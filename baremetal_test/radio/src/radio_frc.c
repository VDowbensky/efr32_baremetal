#include "radio_frc.h"

void FRC_PRI_IRQHandler(void)
{
	uint32_t flags;
	flags = FRC->IF & FRC->IEN;
	FRC->IFC = flags;	
}

void FRC_IRQHandler(void)
{
	uint32_t flags;
	flags = FRC->IF & FRC->IEN;
	FRC->IFC = flags;	
}

void FRC_init(void)
{
	//FRC
	//header enable
	//frame coding method
	//frame length algo
	//bit endian
	//fixed length
	//variable length
	//frame type
	//insert/check CRC
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
  FRC_FrameControlDescrBufferIdSet(0,0);
  FRC_FrameControlDescrBufferIdSet(1,0);
  FRC_FrameControlDescrBufferIdSet(2,1);
  //FRC_FrameControlDescrBufferIdSet(3,1);
  FRC->CTRL &= 0xffffff0f; //reset TXFCDMODE, RXFCDMODE
  FRC->CTRL |= 0xa0; //5, 7 - TXFCDMODE, RXFCDMODE	
	//NVIC_ClearPendingIRQ(FRC_IRQn);
  //NVIC_EnableIRQ(FRC_IRQn);
}

void FRC_FrameControlDescrBufferIdSet(int buf,int fcd)

{
  (&FRC->FCD0)[buf] = (&FRC->FCD0)[buf] & 0xfffffcff; //bits 8,9
  (&FRC->FCD0)[buf] = (&FRC->FCD0)[buf] | fcd << 8;
}



void FRC_FrameControlDescrConfigSet(int param_1,uint32_t param_2,int param_3,int param_4,uint8_t param_5,uint8_t param_6)

{
  (&FRC->FCD0)[param_1] = (&FRC->FCD0)[param_1] & 0xffff8300;
  (&FRC->FCD0)[param_1] =
       param_2 | (uint32_t)param_6 << 10 | (uint32_t)param_5 << 0xb | param_4 << 0xc | param_3 << 0xe |
       (&FRC->FCD0)[param_1];
}



void FRC_FrameDescsConfig (uint32_t param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4)

{
 // RADIO_FrameControlDescrConfigSet(0,0xff,param_1,param_2,param_3,param_4,param_3); //!!!!!!!!!!!!!!!!!!!
  FRC_FrameControlDescrConfigSet(2,0xff,param_1,param_2,param_3,param_4);
}


void FRC_ErrorHandle(void)

{
 // bufcRxStreaming = 0; //!!!!!!!!!!!!!!!
  BUFC_Clear(1);
  BUFC_Clear(2);
}

int FRC_RxTrailDataLength(void)

{
  uint32_t t1;
  uint16_t t2;
  
  t1 = FRC->TRAILRXDATA;
  if ((t1 & 0x20) == 0) t2 = 0;
  else t2 = 4;
  if(t1 & 0x08000000) t2 += 2;
  if(t1 & 0x10000000) t2 += 2;
  if(t1 & 0x20000000) t2 += 2;
  if(t1 & 0x40000000) t2 += 1;
  if(t1 & 0x80000000) t2 += 1;
  return t2;
}

