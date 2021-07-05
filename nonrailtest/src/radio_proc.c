#include "radio_proc.h"
#include <stdint.h>
#include <string.h>

uint8_t RADIO_rxBuffer[RADIO_BUFFER_SIZE];
uint8_t RADIO_txBuffer[RADIO_BUFFER_SIZE];
uint8_t RADIO_rxLengthBuffer[RADIO_BUFFER_SIZE];

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
	
	 //RAIL_RfHalInit(&railInit);
	//GENERIC_PHY_Init(void)
	
	
	//clocks RADIO_CLKEnable();
	CMU_ClockEnable(0x63400,true); //3
  CMU_ClockEnable(0x60400,true); //0 - PROTIMER
  CMU_ClockEnable(0x64400,true); //4
  CMU_ClockEnable(0x67400,true); //7
  CMU_ClockEnable(0x66400,true); //6
  CMU_ClockEnable(0x65400,true); //5
  CMU_ClockEnable(0x62400,true); //2
  CMU_ClockEnable(0x68400,true); //8
	
	BUFC->BUF1_CTRL = 2; //
  BUFC->BUF1_ADDR = (uint32_t)&RADIO_rxBuffer;
  BUFC->BUF1_THRESHOLDCTRL = 0xaf;
  BUFC->BUF0_CTRL = 2;
  BUFC->BUF0_ADDR = (uint32_t)&RADIO_txBuffer;
  BUFC->BUF0_THRESHOLDCTRL = 0x2020;
  BUFC->BUF2_CTRL = 0;
  BUFC->BUF2_ADDR = (uint32_t)&RADIO_rxLengthBuffer;
  BUFC->BUF2_THRESHOLDCTR = 0x3e;
  RADIO_FrameControlDescrBufferIdSet(0,0);
  RADIO_FrameControlDescrBufferIdSet(1,0);
  RADIO_FrameControlDescrBufferIdSet(2,1);
  RADIO_FrameControlDescrBufferIdSet(3,1);
  FRC->CTRL &= 0xffffff0f; //reset TXFCDMODE, RXFCDMODE
  FRC->CTRL |= 0xa0; //5, 7 - TXFCDMODE, RXFCDMODE

 // DAT_000109d8 = RADIO_BUFCIrqHandler;

  //_DAT_e000e280 = 0x80;
  NVIC_ClearPendingIRQ(FRC_IRQn);
  //_DAT_e000e100 = 0x80;
  NVIC_EnableIRQ(FRC_IRQn);

  RADIO_BUFCClear(0);
  RADIO_BUFCClear(1);
  RADIO_BUFCClear(2);
  BUFC->IEN |= 0xb0a0b; //
  RADIO_RXBufferDisableThrInt();
  RADIO_SetAndForgetWrite();
  MODEM->DCCOMP |= 3; //DCESTIEN, DCCOMPEN
  RAC->SR3 = 0;
  RADIO_DccalEnable();
  //_DAT_4308019c = 1; //bit 7
  RAC->CTRL |= 0x80; //ACTIVEPOL
  //_DAT_430801a0 = 1;  //400D bit 0 - 400C bit 8
  RAC->CTRL |= 0x00010000; //PAENPOL
  //_DAT_430801a4 = 1; //400D //bit 2 - 400C bit 10
  RAC->CTRL |= 0x00040000; //PRSRXDIS	
/////	RADIO_init
  //_DAT_e000e280 = 0x40000000;
  NVIC_ClearPendingIRQ(SYNTH_IRQn);
  //_DAT_e000e180 = 0x40000000;
  NVIC_DisableIRQ(SYNTH_IRQn);
	//
//GENERIC_PHY_RACConfig();
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
  //FRC->RXCTRL = 0x60;
	FRC->RXCTRL = FRC_RXCTRL_BUFRESTORERXABORTED_Msk | FRC_RXCTRL_BUFRESTOREFRAMEERROR_Msk;
//  RADIO_PTI_Enable();
  //if ((int)(RAC->CTRL << 0x1f) < 0)
  //if (RAC->CTRL & 0x01)
	if (RAC->CTRL & RAC_CTRL_FORCEDISABLE_Msk)
  {
    //_DAT_43080180 = 0;
		RAC->CTRL &= ~RAC_CTRL_FORCEDISABLE_Msk; //FORCEDISABLE
  }
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
  //_DAT_21000f70 = 0;
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
  RAC->VCOCTRL = 0x0F00277A;
  RAC->RFENCTRL = 0x00001020;
  RAC->LNAMIXCTRL1 = 0x00000880;
  RAC->IFPGACTRL = 0x000087F6;
  RAC->IFFILTCTRL = 0x008800E0;
  RAC->IFADCCTRL = 0x1153E6C1;

	//SYNTH
	//RF freq.
	//channel spacing
	//IF frequency
	//injection side
  SYNTH->CTRL = 0x0000AC3F;
  SYNTH->IFFREQ = 0x00104000;
  SYNTH->DIVCTRL = 0x00000003;
  SYNTH->CALOFFSET = 0x00000000;	

	//MODEM
	//modulation type
	MODEM->MIXCTRL = 0x00000010;
  MODEM->CTRL0 = 0x04000000;
  MODEM->CTRL1 = 0x0001400F;
  MODEM->CTRL2 = 0x00002000;
  MODEM->CTRL3 = 0x00000000;
  MODEM->CTRL4 = 0x03000000;
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
  FRC->WCNTCMP0 = 0x0000001F;
  FRC->WCNTCMP1 = 0x00000000;
	//FEC algo
  FRC->FECCTRL = 0x00000001;
  FRC->BLOCKRAMADDR = 0x00000000;
  FRC->CONVRAMADDR = 0x00000000;
  FRC->CTRL = 0x00000700;
  FRC->TRAILTXDATACTRL = 0x00000000;
  FRC->CONVGENERATOR = 0x00000000;
  FRC->PUNCTCTRL = 0x00000000;
  FRC->FCD0 = 0x00000CFF;
  FRC->FCD1 = 0x00000000;
  FRC->FCD2 = 0x00000DFF;
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
PA_OutputPowerSet(150);
//PA_PowerModeConfigSet();
PA_CTuneSet(9, 8);
PA_PowerLevelSet(100);
}


