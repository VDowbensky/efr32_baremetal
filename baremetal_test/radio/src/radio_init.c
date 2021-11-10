#include <string.h>
#include "radio_init.h"

void RADIO_SeqInit(void *src,uint32_t len);
void RADIO_SetAndForgetWrite(void);

const uint32_t generated_phyInfo[] = {
  0UL,
  0x00100000UL, // 16.0
};

void init_radio(void)
{
	CMU_ClockEnable(0x63400,true); //3
  CMU_ClockEnable(0x60400,true); //0 - PROTIMER
  CMU_ClockEnable(0x64400,true); //4
  CMU_ClockEnable(0x67400,true); //7
  CMU_ClockEnable(0x66400,true); //6
  CMU_ClockEnable(0x65400,true); //5
  CMU_ClockEnable(0x62400,true); //2
  CMU_ClockEnable(0x68400,true); //8

  RADIO_SetAndForgetWrite();
  RAC->SR3 = 0;
  BUS_RegMaskedSet(&RAC->CTRL, RAC_CTRL_ACTIVEPOL_Msk | RAC_CTRL_PAENPOL_Msk | 	RAC_CTRL_LNAENPOL_Msk);
	
  RAC->SEQCMD = RAC_SEQCMD_HALT_Msk;
	memset((void*)0x21000000,0,0x1000);
	RADIO_SeqInit(&genericSeqProg, GENERIC_SEQPROG_SIZE);
  memset((void*)0x21000efc,0,0x70); //clear sequencer variables
	RAC->SEQCMD = RAC_SEQCMD_RESUME_Msk;
  RAC->SR0 = 0;
  RAC->SR1 = 0;
  RAC->SR2 = 0;
  //TEMPCAL_Init();
  RADIO_RxSearchTimeSet(0);
  RADIO_TxToRxSearchTimeSet(0);
  RADIO_RxWarmTimeSet(100);
  RADIO_TxToRxTimeSet(100);
  RADIO_TxToTxTimeSet(100);
  RADIO_RxToTxTimeSet(100);
	RADIO_RxFrameToTxTimeSet(100);
  RADIO_TxWarmTimeSet(100); 
	
//  RADIO_PTI_Enable();
	if (RAC->CTRL & RAC_CTRL_FORCEDISABLE_Msk) RAC->CTRL &= ~RAC_CTRL_FORCEDISABLE_Msk; //FORCEDISABLE
//  GENERIC_PHY_ResetAddressFiltering();
  SEQ_CONTROL_REG = SEQ_CONTROL_REG | 8;
  PROTIMER_Init();
  PROTIMER_Start();
  PROTIMER_CCTimerCapture(0,0xc00000);
  PROTIMER_CCTimerCapture(1,0x200000);
//  RFRAND_SeedProtimerRandom();
  
  SEQ->REG070 = 0; //GENERIC_PHY_Init
	SEQ->PHYINFO = 	(uint32_t) &generated_phyInfo;
	SEQ->MISC = 0x00000000;
	SEQ->SYNTHLPFCTRLRX = 0x0003C002;
	SEQ->SYNTHLPFCTRLTX = 0x0003C002;	
  //RAC
  RAC->VCOCTRL = 0x0F00277A; //27,26,25,24,13,10,9,8,6,5,4,3,1
	RAC->RFENCTRL = RAC_RFENCTRL_DEMEN_Msk | RAC_RFENCTRL_IFADCCAPRESET_Msk;
  RAC->LNAMIXCTRL1 = 0x00000880; //11,7 trim values
  //RAC->IFPGACTRL = 0x000087F6; //15,10,9,8,7,6,5,4,2,1 bandsel & trim values
  RAC->IFFILTCTRL = 0x008800E0; //
  RAC->IFADCCTRL = 0x1153E6C1;

  SYNTH_init();
	MODEM_init();
	FRC_init();
	BUFC_init();
	AGC_init();
	CRC_init();


//config callbacks here if needed

PA_rampTime = 10;
PA_Powerlevel = 150;
PA_Init(PA_Powerlevel,PA_rampTime);
PA_SetPowerDbm(DEFAULT_TX_POWER);

uint32_t tmp;
tmp = *(uint32_t *) (DEVID_ADDR + 0x104);

  if (tmp == 0xFFFFFFFF)
    {
      txpactune = TX_PACTUNE;
      rxpactune = RX_PACTUNE;
		}
      
	 else
    {
      txpactune = tmp & 0x000000FF;
      rxpactune = (tmp >> 8) & 0x000000FF;
    }
		PA_CTuneSet(txpactune, rxpactune); //default
		//radio_SetTxTransitions(RAIL_RF_STATE_RX,RAIL_RF_STATE_RX);
		//radio_SetTxTransitions(RAIL_RF_STATE_IDLE,RAIL_RF_STATE_IDLE);
		//radio_SetRxTransitions(RAIL_RF_STATE_RX,RAIL_RF_STATE_RX);
		//radio_SetRxTransitions(RAIL_RF_STATE_IDLE,RAIL_RF_STATE_IDLE);
		RxEvents = 0;
		TxEvents = 0;
		HardEvents = 0;
		radio_startrx();
}

void RADIO_SetAndForgetWrite(void)

{
  SYSTEM_ChipRevision_TypeDef revision;

  SYSTEM_ChipRevisionGet(&revision);
  RAC->IFADCCTRL = 0x1153e6c0;
  RAC->IFPGACTRL = 0x87f6;
  RAC->LNAMIXCTRL1 = 0x880;
  RAC->VCOCTRL = 0xf00277a;
	if((revision.major == 0x01) && (revision.minor < 2)) SYNTH->VCOGAIN = 0x28;
  SYNTH->CTRL = 0xac3f;
  AGC->MANGAIN = 0x1800000;
  RAC->LNAMIXCTRL = 0;
  RAC->SYNTHREGCTRL = 0x3636d80;
}

void RADIO_SeqInit(void *src,uint32_t len)

{
  uint32_t t1, t2, t3;
  t1 = RAC->STATUS & RAC_RXENSRCEN_SWRXEN_Msk; //dummy read
  RAC->VECTADDR = 0x21000000;
  RAC->SEQCTRL = RAC_SEQCTRL_COMPACT_Msk; 
  INT_Disable();
  memcpy((void *)0x21000000,src,len);
  INT_Enable();
  t3 = TX_PA_CTUNE;
  t2 = RX_PA_CTUNE;
  t1 = PA_SLICES;
  RAC->R6 = 0x21000fcc;
  memset((void *)0x21000f6c,0,0x94);
  PA_SLICES = t1;
  RX_PA_CTUNE = t2;
  TX_PA_CTUNE = t3;
  STIMER_VALUE = -(RADIO_UsToStimerTickCalc(0x3c));
}

