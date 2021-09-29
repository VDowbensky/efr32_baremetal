#include "radio_proc.h"
#include <stdint.h>
#include <string.h>

uint8_t RADIO_rxBuffer[RADIO_BUFFER_SIZE];
uint8_t RADIO_txBuffer[RADIO_BUFFER_SIZE];
//int8_t RADIO_rxLengthBuffer[RADIO_BUFFER_SIZE];

uint8_t txpactune;
uint8_t rxpactune;

//const uint32_t generated_phyInfo[] = {
//  0UL,
//  0x00100000UL, // 16.0
//};

void init_radio(void)
{
	RADIO_CLKEnable();
	set_defaults(); //set&forgetwrite
	init_buffers();
	init_modem();
	init_frc();
	init_crc();
	init_agc();
	init_sequencer();
	init_synth();
	init_pa();
	init_protimer();
	RAIL_RfIdle();
	//RAIL_SetTxTransitions(RAIL_RF_STATE_RX, RAIL_RF_STATE_RX);
	//RAIL_SetRxTransitions(RAIL_RF_STATE_RX, RAIL_RF_STATE_RX, true);
	
	//start receiving
	//RAIL_RxConfig(0x74,0);
	RAIL_RxStart(0);
	//RFTEST_StartRx();
	//RAIL_RfHalRxStart(0);
	//GENERIC_PHY_RadioEnable(1);
	//GENERIC_PHY_ChannelSet(0);
	//GENERIC_PHY_StartRx(0);
}

void RADIO_CLKEnable(void)
{
	CMU_ClockEnable(0x63400,true); //3
  CMU_ClockEnable(0x60400,true); //0 - PROTIMER
  CMU_ClockEnable(0x64400,true); //4
  CMU_ClockEnable(0x67400,true); //7
  CMU_ClockEnable(0x66400,true); //6
  CMU_ClockEnable(0x65400,true); //5
  CMU_ClockEnable(0x62400,true); //2
  CMU_ClockEnable(0x68400,true); //8	
}

void set_defaults(void)

{
  //SYSTEM_ChipRevisionGet(&local_c);
  RAC->IFADCCTRL = 0x5153e6c0;
  RAC->IFPGACTRL = 0x87e6;
  RAC->LNAMIXCTRL1 = 0x880;
  RAC->VCOCTRL = 0xf00277a;
  //if ((local_c._1_1_ == '\x01') && ((local_c & 0xff) < 2)) SYNTH->VCOGAIN = 0x28;
  SYNTH->CTRL = 0xac3f;
  AGC->MANGAIN = 0x1800000;
  RAC->LNAMIXCTRL = 0;
  RAC->SYNTHREGCTRL = 0x3636d80;
  BUS_RegMaskedClear(&SYNTH->VCDACCTRL,0x7f);
  BUS_RegMaskedSet(&SYNTH->VCDACCTRL,0x23);
	
	BUS_RegMaskedSet(&RAC->CTRL, RAC_CTRL_ACTIVEPOL_Msk | RAC_CTRL_PAENPOL_Msk | 	RAC_CTRL_LNAENPOL_Msk);
	if (RAC->CTRL & RAC_CTRL_FORCEDISABLE_Msk) RAC->CTRL &= ~RAC_CTRL_FORCEDISABLE_Msk; //FORCEDISABLE
  *(uint32_t*)0x21000efc = *(uint32_t*)0x21000efc | 8;
  SEQ->REG070 = 0; 
}

void init_buffers(void)
{
	BUFC->BUF1_CTRL = 2; //size
  BUFC->BUF1_ADDR = (uint32_t)&RADIO_rxBuffer;
  BUFC->BUF1_THRESHOLDCTRL = 0xaf;
  BUFC->BUF0_CTRL = 2; //size
	BUFC->BUF0_ADDR = (uint32_t)&RADIO_txBuffer;
  BUFC->BUF0_THRESHOLDCTRL = 0x2020; //BUFC_BUF0_THRESHOLDCTRL_THRESHOLDMODE_Msk | THRESHOLD
  RADIO_FrameControlDescrBufferIdSet(0,0);
  RADIO_FrameControlDescrBufferIdSet(1,0);
  RADIO_FrameControlDescrBufferIdSet(2,1);
  RADIO_FrameControlDescrBufferIdSet(3,1);
  RADIO_BUFCClear(0);
  RADIO_BUFCClear(1);
  BUFC->IEN |= 0xb0a0b; //23,21,20,11,9,3,1,0 
  RADIO_RXBufferDisableThrInt();	
}




void init_frc(void)
{
  FRC->CTRL &= 0xffffff0f; //reset TXFCDMODE, RXFCDMODE
  FRC->CTRL |= 0xa0; //5, 7 - TXFCDMODE, RXFCDMODE
  NVIC_ClearPendingIRQ(FRC_IRQn);
  NVIC_EnableIRQ(FRC_IRQn);	
	FRC->TRAILRXDATA = 0x1b;
	FRC->RXCTRL = FRC_RXCTRL_BUFRESTORERXABORTED_Msk | FRC_RXCTRL_BUFRESTOREFRAMEERROR_Msk;
	FRC->DFLCTRL = 0x00000000;
  FRC->MAXLENGTH = 0x00000000;
  FRC->WCNTCMP0 = 0x0000001F; //
  FRC->WCNTCMP1 = 0x00000000;
	//FEC algo
  FRC->FECCTRL = 0x00000001; //BLOCKWHITEMODE
  FRC->BLOCKRAMADDR = 0x00000000;
  FRC->CONVRAMADDR = 0x00000000;
  FRC->CTRL = 0x00000700; //BITSPERWORD
  FRC->TRAILTXDATACTRL = 0x00000000;
  FRC->CONVGENERATOR = 0x00000000;
  FRC->PUNCTCTRL = 0x00000000;
  FRC->FCD0 = 0x00000CFF; //FRC_FCD0_CALCCRC_Msk | FRC_FCD0_INCLUDECRC_Msk | FRC_FCD0_WORDS_Msk
  FRC->FCD1 = 0x00000000;
  FRC->FCD2 = 0x00000DFF; //FRC_FCD0_CALCCRC_Msk | FRC_FCD0_INCLUDECRC_Msk | 0x100 | FRC_FCD0_WORDS_Msk
  FRC->FCD3 = 0x00000000;
  //whitening
	//whitening output bit
	FRC->WHITECTRL = 0x00000000;
	//whitening poly (algo)
  FRC->WHITEPOLY = 0x00000108;
	//seed
  FRC->WHITEINIT = 0x0000FFFF;
}

void init_crc(void)
{
	//CRC
	//poly
	CRC->POLY = 0x0000A001;
	//seed
	CRC->INIT = 0x00000000;
	//input bit endian
	//CRC input padding
	//output byte endian
	//output bit endian
	//invert
	CRC->CTRL = 0x00000744;	
}

void init_agc(void)
{
  AGC->CTRL0 = 0x000270F8;
  AGC->CTRL1 = 0x00000300;
  AGC->CTRL2 = 0x82710060;
  AGC->MANGAIN = 0x00000000;
  AGC->GAINRANGE = 0x0000383E;
  AGC->GAININDEX = 0x000025BC;
  AGC->GAINSTEPLIM = 0x00020105;
  AGC->LOOPDEL = 0x00000113;
  AGC->MININDEX	= 0x006D8480;	
}

void init_sequencer(void)
{
	RADIO_SeqInit(&genericSeqProg, GENERIC_SEQPROG_SIZE);
  memset((void*)0x21000efc,0,0x70); //clear sequencer variables
	SEQ->MISC = 0x00000000;
	SEQ->SYNTHLPFCTRLRX = 0x0003C002;
	SEQ->SYNTHLPFCTRLTX = 0x0003C002;	
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
  RADIO_TxWarmTimeSet(100); //GENERIC_PHY_RACConfig	
}

void init_synth(void)
{
  NVIC_ClearPendingIRQ(SYNTH_IRQn);
  NVIC_DisableIRQ(SYNTH_IRQn);	
	SYNTH->CTRL = 0x0000AC3F; //15,13,11,10,5,4,3,2,1,0 //trim values
  SYNTH->IFFREQ = 0x00104000; //
  SYNTH->DIVCTRL = 0x00000003; //3 for 868 MHz
  SYNTH->CALOFFSET = 0x00000000;
	SYNTH_DCDCRetimeEnable();	
	SYNTH_Config(868000000, 100000);
}

void init_pa(void)
{
RADIO_PAInit_t painit;
painit.paSel = PA_SEL_SUBGIG;
painit.voltMode = PA_VOLTMODE_DCDC;
painit.power = 100; //100
painit.offset = 0;
painit.rampTime = 10;
RADIO_PA_Init(&painit);
PA_OutputPowerSet(150);
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
		PA_PowerLevelSet(75);	
}

void init_protimer(void)
{
  PROTIMER_Init();
  PROTIMER_Start();
  PROTIMER_CCTimerCapture(0,0xc00000);
  PROTIMER_CCTimerCapture(1,0x200000);	
}







