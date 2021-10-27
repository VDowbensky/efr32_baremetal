#include "radio_proc.h"
#include <stdint.h>
#include <string.h>

volatile uint8_t RADIO_rxBuffer[RADIO_BUFFER_SIZE];
volatile uint8_t RADIO_txBuffer[RADIO_BUFFER_SIZE];
volatile uint8_t RADIO_rxLengthBuffer[RADIO_BUFFER_SIZE];

uint8_t txpactune;
uint8_t rxpactune;

const uint32_t generated_phyInfo[] = {
  0UL,
  0x00100000UL, // 16.0
};

void init_radio(void)
{
	//RAIL_RfHalCalibrationInit(uint32_t cal)
	//INT_Disable();
  //RAIL_CalPend = 0;
  //RAIL_CalEnable = cal;
  //INT_Enable();

	CMU_ClockEnable(0x63400,true); //3
  CMU_ClockEnable(0x60400,true); //0 - PROTIMER
  CMU_ClockEnable(0x64400,true); //4
  CMU_ClockEnable(0x67400,true); //7
  CMU_ClockEnable(0x66400,true); //6
  CMU_ClockEnable(0x65400,true); //5
  CMU_ClockEnable(0x62400,true); //2
  CMU_ClockEnable(0x68400,true); //8
	
	BUFC->BUF1_CTRL = 2; //size
	BUFC->BUF1_ADDR = (uint32_t)RADIO_rxBuffer;
  BUFC->BUF1_THRESHOLDCTRL = 0xaf;
  BUFC->BUF0_CTRL = 2; //size
  BUFC->BUF0_ADDR = (uint32_t)RADIO_txBuffer;
  BUFC->BUF0_THRESHOLDCTRL = 0x2020; //BUFC_BUF0_THRESHOLDCTRL_THRESHOLDMODE_Msk | THRESHOLD
  BUFC->BUF2_CTRL = 0; //size
  BUFC->BUF2_ADDR = (uint32_t)RADIO_rxLengthBuffer;
  BUFC->BUF2_THRESHOLDCTR = 0x3e; 
  RADIO_FrameControlDescrBufferIdSet(0,0);
  RADIO_FrameControlDescrBufferIdSet(1,0);
  RADIO_FrameControlDescrBufferIdSet(2,1);
  RADIO_FrameControlDescrBufferIdSet(3,1);
  FRC->CTRL &= 0xffffff0f; //reset TXFCDMODE, RXFCDMODE
  FRC->CTRL |= 0xa0; //5, 7 - TXFCDMODE, RXFCDMODE

 // DAT_000109d8 = RADIO_BUFCIrqHandler;

  NVIC_ClearPendingIRQ(FRC_IRQn);
  NVIC_EnableIRQ(FRC_IRQn);

  RADIO_BUFCClear(0);
  RADIO_BUFCClear(1);
  RADIO_BUFCClear(2);
  BUFC->IEN |= 0xb0a0b; //23,21,20,11,9,3,1,0 
  RADIO_RXBufferDisableThrInt();
  RADIO_SetAndForgetWrite();
  MODEM->DCCOMP |= MODEM_DCCOMP_DCCOMPEN_Msk | MODEM_DCCOMP_DCESTIEN_Msk; //3; 
  RAC->SR3 = 0;
  RADIO_DccalEnable();
  //RAC->CTRL |= 0x80; //RAC_CTRL_ACTIVEPOL_Msk 
  //RAC->CTRL |= 0x00010000; //bit 8 0x100 RAC_CTRL_PAENPOL_Msk
  //RAC->CTRL |= 0x00040000; //bit 9 0x200 RAC_CTRL_LNAENPOL_Msk
  BUS_RegMaskedSet(&RAC->CTRL, RAC_CTRL_ACTIVEPOL_Msk | RAC_CTRL_PAENPOL_Msk | 	RAC_CTRL_LNAENPOL_Msk);
	
  NVIC_ClearPendingIRQ(SYNTH_IRQn);
  NVIC_DisableIRQ(SYNTH_IRQn);

	RADIO_SeqInit(&genericSeqProg, GENERIC_SEQPROG_SIZE);
  memset((void*)0x21000efc,0,0x70); //clear sequencer variables
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
	

	FRC->TRAILRXDATA = 0x1b;
	FRC->RXCTRL = FRC_RXCTRL_BUFRESTORERXABORTED_Msk | FRC_RXCTRL_BUFRESTOREFRAMEERROR_Msk;
//  RADIO_PTI_Enable();
	if (RAC->CTRL & RAC_CTRL_FORCEDISABLE_Msk) RAC->CTRL &= ~RAC_CTRL_FORCEDISABLE_Msk; //FORCEDISABLE
//  RADIO_RegisterIrqCallback(1,GENERIC_PHY_FRC_IRQCallback);
//  RADIO_RegisterIrqCallback(2,GENERIC_PHY_MODEM_IRQCallback);
//  RADIO_RegisterIrqCallback(5,GENERIC_PHY_RAC_IRQCallback);
//  RADIO_RegisterIrqCallback(7,GENERIC_PHY_PROTIMER_IRQCallback);
//  GENERIC_PHY_ResetAddressFiltering();
  //_DAT_21000efc = _DAT_21000efc | 8;
  *(uint32_t*)0x21000efc = *(uint32_t*)0x21000efc | 8;
  PROTIMER_Init();
  PROTIMER_Start();
  PROTIMER_CCTimerCapture(0,0xc00000);
  PROTIMER_CCTimerCapture(1,0x200000);
//  RFRAND_SeedProtimerRandom();
  SYNTH_DCDCRetimeEnable();
  SEQ->REG070 = 0; //GENERIC_PHY_Init
	////
//  _enabledCallbacks = _enabledCallbacks & 0xff000000 | (uint)(uint3)((uint3)_enabledCallbacks | 7) | 0x80000;
//  iVar1 = RAIL_RfHalCalibrationEnableGet();
//  if (iVar1 << 0x1f < 0)
//  {
//    _enabledCallbacks = _enabledCallbacks | 0x10000;
//  }
//  GENERIC_PHY_SetCallbacks(&_enabledCallbacks);
//  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
//  RAILCb_RfReady(); //RAIL_RfHalInit

//changeRadioConfig


	SEQ->PHYINFO = 	(uint32_t) &generated_phyInfo;
	//misc.
	//channel BW
	SEQ->MISC = 0x00000000;
	SEQ->SYNTHLPFCTRLRX = 0x0003C002;
	SEQ->SYNTHLPFCTRLTX = 0x0003C002;	
  //RAC
  RAC->VCOCTRL = 0x0F00277A; //27,26,25,24,13,10,9,8,6,5,4,3,1
  //RAC->RFENCTRL = 0x00001020; //12,5 RAC_RFENCTRL_DEMEN_Msk | RAC_RFENCTRL_IFADCCAPRESET_Msk
	RAC->RFENCTRL = RAC_RFENCTRL_DEMEN_Msk | RAC_RFENCTRL_IFADCCAPRESET_Msk;
  RAC->LNAMIXCTRL1 = 0x00000880; //11,7 trim values
  RAC->IFPGACTRL = 0x000087F6; //15,10,9,8,7,6,5,4,2,1 bandsel & trim values
  RAC->IFFILTCTRL = 0x008800E0; //
  RAC->IFADCCTRL = 0x1153E6C1;

	//SYNTH
	//RF freq.
	//channel spacing
	//IF frequency
	//injection side
  SYNTH->CTRL = 0x0000AC3F; //15,13,11,10,5,4,3,2,1,0 //trim values
  SYNTH->IFFREQ = 0x00104000; //
  SYNTH->DIVCTRL = 0x00000003; //3 for 868 MHz
  SYNTH->CALOFFSET = 0x00000000;	

	//MODEM
	//modulation type
	//MODEM->MIXCTRL = 0x00000010; //bit 4 - MODEM_MIXCTRL_DIGIQSWAPEN_Msk
	MODEM->MIXCTRL = MODEM_MIXCTRL_DIGIQSWAPEN_Msk;
  MODEM->CTRL0 = 0x04000000; //26 shaping
  MODEM->CTRL1 = 0x0001400F; //16,14,3,2,1,0 resync, compmode, syncbits (0f -> 16)
  MODEM->CTRL2 = 0x00002000; //13 DATAFILTER
  MODEM->CTRL3 = 0x00000000;
  MODEM->CTRL4 = 0x03000000; //24,25 ADCSATLEVEL
  MODEM->CTRL5 = 0x00000000;
	//bitrate
	MODEM->TXBR = 0x00FF5FA0;
  MODEM->RXBR = 0x00000820;
	//deviation
	MODEM->MODINDEX = 0x00230390;
	//baudrate tolerance
	//shaping filter
	//bt/r
  MODEM->SHAPING0 = 0x22140A04;
  MODEM->SHAPING1 = 0x504B4133;
  MODEM->SHAPING2	= 0x00000000;
	//FSK symbol mapping
	//direct mode
	//AFC
	MODEM->AFC = 0x00000000;
	MODEM->AFCADJLIM = 0x00000000;
	//symbol coding
	//encoding
	//dsss chipping code length
	//dsss SF
	//dsss chipping code base
	//diff.encoding
	//manchester mapping
	MODEM->DSSS0 = 0x00000000;
	//timings
  MODEM->TIMING	= 0x0220081F;
	//preamble base pattern
	//length
	//pattern length
	//syncword length
	//sync word tx skip
	MODEM->CF = 0x020200F8; 
  MODEM->PRE = 0x00140012;
	//syncword 0
	MODEM->SYNC0 = 0x00002BB4;
	//syncword 1
	MODEM->SYNC1 = 0x00000000;
	
	//FRC
	//header enable
	//frame coding method
	//frame length algo
	//bit endian
	//fixed length
	//variable length
	//frame type
	//insert/check CRC
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
	//AGC
  AGC->CTRL0 = 0x000270F8;
  AGC->CTRL1 = 0x00000300;
  AGC->CTRL2 = 0x82710060;
  AGC->MANGAIN = 0x00000000;
  AGC->GAINRANGE = 0x0000383E;
  AGC->GAININDEX = 0x000025BC;
  AGC->GAINSTEPLIM = 0x00020105;
  AGC->LOOPDEL = 0x00000113;
  AGC->MININDEX	= 0x006D8480;
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
	
//config callbacks here if needed
SYNTH_Config(868000000, 100000);

RADIO_PAInit_t painit;
painit.paSel = PA_SEL_SUBGIG;
painit.voltMode = PA_VOLTMODE_DCDC;
painit.power = 100; //100
painit.offset = 0;
painit.rampTime = 10;
RADIO_PA_Init(&painit);
//PA_OutputPowerSet(150);
PA_SetPowerLevel(200);
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
		//PA_PowerLevelSet(75);
		PA_SetPowerLevel(50);
}


void BM_TxOn(void)
{
	//RAC->CTRL = RAC_CTRL_LNAENPOL_Msk | RAC_CTRL_PAENPOL_Msk | RAC_CTRL_ACTIVEPOL_Msk;
	RAC->SYNTHENCTRL = RAC_SYNTHENCTRL_VCODIVEN_Msk | RAC_SYNTHENCTRL_VCOLDOEN_Msk | RAC_SYNTHENCTRL_MMDLDOEN_Msk | RAC_SYNTHENCTRL_LODIVSYNCCLKEN_Msk | RAC_SYNTHENCTRL_CHPLDOEN_Msk 
	| RAC_SYNTHENCTRL_SYNTHSTARTREQ_Msk	| RAC_SYNTHENCTRL_SYNTHCLKEN_Msk | RAC_SYNTHENCTRL_LPFEN_Msk | RAC_SYNTHENCTRL_CHPEN_Msk | RAC_SYNTHENCTRL_LODIVEN_Msk | RAC_SYNTHENCTRL_VCOEN_Msk;
	//At this point - normal current consumption !!!!!!
	//while (1) {};
	RAC->LPFCTRL = 0x0003C000;
	SYNTH->CMD = SYNTH_CMD_SYNTHSTART_Msk;
	//RAC->MMDCTRL = 0x0001147B;
	//RAC->RFENCTRL = RAC_RFENCTRL_DEMEN_Msk; //???
	//RAC->LNAMIXCTRL1 = 0x00000880;
	//RAC->IFPGACTRL = 0x000087F6; //it's significant!
	RAC->SGRFENCTRL0 = 0x000F0000;
	RAC->PACTRL0 = 0;
	RAC->PABIASCTRL0 = 0x0;
	//RAC->SGPABIASCTRL0 = (0x07 << RAC_SGPABIASCTRL0_SGDACFILTBANDWIDTH_Pos) | RAC_SGPABIASCTRL0_TXPOWER_Msk | (1 << RAC_SGPABIASCTRL0_BUF0BIAS_Pos)
	//| (1 << RAC_SGPABIASCTRL0_PABIAS_Pos) | (RAC_SGPABIASCTRL0_LDOBIAS_Msk) | (1 << RAC_SGPABIASCTRL0_BUF12BIAS_Pos); //no effect!!!
	//RAC->SGPACTRL0 = RAC_SGPACTRL0_DACGLITCHCTRL_Msk | (Stripe << RAC_SGPACTRL0_STRIPE_Pos) | (Slice << RAC_SGPACTRL0_SLICE_Pos) | Cascode << RAC_SGPACTRL0_CASCODE_Pos); 
	//RAC->SGPACTRL0 = 0x4801C1E0;	//no effect. Writed by sequencer???
	RAC->PAENCTRL = RAC_PAENCTRL_PARAMP_Msk;
	RAC->SGRFENCTRL0 = RAC_SGRFENCTRL0_TRSW_Msk | RAC_SGRFENCTRL0_PAOUTEN_Msk | RAC_SGRFENCTRL0_PAEN_Msk | RAC_SGRFENCTRL0_PASTANDBY_Msk;
	RAC->SYNTHCTRL = RAC_SYNTHCTRL_LODIVTXEN_Msk;
}

void BM_TxOff(void)
{
	RAC->SGPACTRL0 = 0;
	RAC->SGRFENCTRL0 = 0;
	RAC->PAENCTRL = 0;
	RAC->SGPABIASCTRL0 = 0;
	//RAC->RFENCTRL = RAC_RFENCTRL_DEMEN_Msk;
	//RAC->MMDCTRL = 0x0001147B;
	SYNTH->CMD = SYNTH_CMD_SYNTHSTOP_Msk;
	RAC->SYNTHCTRL = 0;
	RAC->LPFCTRL = 0x0003C002;
	RAC->SYNTHENCTRL = 0;
	RAC->CTRL = 0;
}



