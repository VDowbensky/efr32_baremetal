#include "BUFC.h"

volatile uint8_t RADIO_rxBuffer[RADIO_BUFFER_SIZE];
volatile uint8_t RADIO_txBuffer[RADIO_BUFFER_SIZE];
volatile uint8_t RADIO_rxLengthBuffer[RADIO_BUFFER_SIZE];

void BUFC_Init(void)
{
	BUFC->BUF0_CTRL = RadioConfig.txbuffersize << BUFC_BUF0_CTRL_SIZE_Pos;
	BUFC->BUF0_ADDR = (uint32_t)&RADIO_txBuffer;
	BUFC->BUF0_THRESHOLDCTRL = RadioConfig.txbufferthreshold | (RadioConfig.txbufferthresholdmode << BUFC_BUF0_THRESHOLDCTRL_THRESHOLDMODE_Pos);
	
	BUFC->BUF1_CTRL = RadioConfig.rxbuffersize << BUFC_BUF1_CTRL_SIZE_Pos;
	BUFC->BUF1_ADDR = (uint32_t)&RADIO_rxBuffer;
	BUFC->BUF1_THRESHOLDCTRL = RadioConfig.rxbufferthreshold | (RadioConfig.rxbufferthresholdmode << BUFC_BUF1_THRESHOLDCTRL_THRESHOLDMODE_Pos);
	
	BUFC->BUF2_CTRL = RadioConfig.rxlenbuffersize << BUFC_BUF2_CTRL_SIZE_Pos;
	BUFC->BUF2_ADDR = (uint32_t)&RADIO_rxLengthBuffer;
	BUFC->BUF2_THRESHOLDCTRL = RadioConfig.rxlenbufferthreshold | (RadioConfig.rxlenbufferthresholdmode << BUFC_BUF2_THRESHOLDCTRL_THRESHOLDMODE_Pos);
	
	//BUFC->BUF3_CTRL = RadioConfig.ackbuffersize << BUFC_BUF3_CTRL_SIZE_Pos;
	//BUFC->BUF3_ADDR = (uint32_t)&RADIO_ackBuffer;
	//BUFC->BUF3_THRESHOLDCTRL = RadioConfig.ackbufferthreshold | (RadioConfig.ackbufferthresholdmode << BUFC_BUF3_THRESHOLDCTRL_THRESHOLDMODE_Pos);
	
	BUFC_Clear(0);
	BUFC_Clear(1);
	BUFC_Clear(2);
	BUFC->IEN = 0xb0a0b; //23,21,20,11,9,3,1,0 
	//BUFC->IEN = 0;
	BUFC_RXBufferDisableThrInt();
	NVIC_ClearPendingIRQ(BUFC_IRQn);
	NVIC_EnableIRQ(BUFC_IRQn);
}

void BUFC_IRQHandler(void)
{
	uint32_t flags;
	
	flags = BUFC->IF & BUFC->IEN;
	BUFC->IFC = flags;
	if(flags & BUFC_IF_BUF0OF_Msk)
	{
		
	}
	if(flags & BUFC_IF_BUF0UF_Msk)
	{
		
	}
	if(flags & BUFC_IF_BUF0THR_Msk)
	{
		
	}
	if(flags & BUFC_IF_BUF0CORR_Msk)
	{
		
	}
	if(flags & BUFC_IF_BUF1THR_Msk)
	{
		//RxEvents |= RXEVENT_RXBUFTHR;
		if(berRx) radio_emptybufandupdatestats();
	}
	if(flags & BUFC_IF_BUF1OF_Msk)
	{
		BUFC_RxBufferReset();
	}
	if(flags & BUFC_IF_BUF1UF_Msk)
	{
		BUFC_RxBufferReset();
	}
	if(flags & BUFC_IF_BUF1CORR_Msk)
	{
		BUFC_RxBufferReset();
	}
	if(flags & BUFC_IF_BUF2OF_Msk)
	{
		
	}
	if(flags & BUFC_IF_BUF2UF_Msk)
	{
		//BUFC_RxBufferReset();
	}
	if(flags & BUFC_IF_BUF2THR_Msk)
	{
		
	}
	if(flags & BUFC_IF_BUF2CORR_Msk)
	{
		//BUFC_RxBufferReset();
	}
	if(flags & BUFC_IF_BUF3OF_Msk)
	{
		
	}
	if(flags & BUFC_IF_BUF3UF_Msk)
	{
		
	}
	if(flags & BUFC_IF_BUF3THR_Msk)
	{
		
	}
	if(flags & BUFC_IF_BUF3CORR_Msk)
	{
		
	}
	if(flags & BUFC_IF_BUSERROR_Msk)
	{
		
	}
}

void BUFC_WriteContSync(uint8_t *addr,int len)

{
  uint8_t *ptr;
  
  INT_Disable();
  ptr = addr;
  while (ptr != (addr + len))
  {
    BUFC->BUF0_WRITEDATA = (uint8_t)*ptr;
    ptr++;
  }
  INT_Enable();
}



uint32_t BUFC_BytesAvailable(uint8_t buf)

{
  return (&BUFC->BUF0_STATUS)[buf * 0xc] & 0x1fff;
}


void BUFC_TxBufferSet(uint8_t * param_1,int param_2,uint8_t * param_3,uint32_t param_4)

{
  uint32_t uVar1;
  
  BUFC_Clear(0);
  BUFC_WriteContSync(param_1,param_2);
  if (param_4 == 0)
  {
    return;
  }
  uVar1 = 0x100U - param_2 & 0xffff;
//  bufcTxStreaming = (undefined2)param_2;
//  DAT_00010b82 = (undefined2)param_4;
//  DAT_00010b8c = (undefined2)uVar1;
//  DAT_00010b84 = param_1;
//  DAT_00010b88 = param_3;
  if (uVar1 < param_4) 
	{
//    RADIO_BUFCWriteContSync_constprop_3(param_3);
//    _DAT_43021d90 = 1;
		//BUS_RegMaskedSet(&BUFC->IEN, 0x10);
    return;
  }
  BUFC_WriteContSync(param_3,param_4);
}




void BUFC_TxBufferReset(void)

{
  BUFC_TxBufferSet(0,0,0,0);
}



void BUFC_RXBufferEnableThrInt(void)

{
  BUFC->IEN |= BUFC_IEN_BUF1THR_Msk;
}



void BUFC_RXBufferDisableThrInt(void)

{
  BUFC->IEN &= ~BUFC_IEN_BUF1THR_Msk;
}

void BUFC_RxBufferSet(uint32_t address)

{
  if (address != 0) BUS_RegMaskedSet(&BUFC->IEN,BUFC_IEN_BUF1THR_Msk); //0x400);
  //bufcRxStreaming._0_2_ = 0;
  //bufcRxStreaming._4_4_ = param_1;
}

uint32_t BUFC_RxBufferGet(void)

{
	return (uint32_t)RADIO_rxBuffer;
}



void BUFC_RxBufferReset(void)

{
//  bufcRxStreaming = 0;
  BUFC_Clear(1);
  BUFC_Clear(2);
}



bool BUFC_RxBufferPacketAvailable(void)

{
  return 1 < (BUFC->BUF2_STATUS & 0x1fff);
}



uint16_t BUFC_RxBufferBytesAvailable(void)

{
  return BUFC->BUF1_STATUS & 0x1fff;
}



uint16_t BUFC_TxBufferBytesAvailable(void)

{
  return BUFC->BUF0_STATUS & 0x1fff;
}



uint16_t BUFC_RxLengthBufferBytesAvailable(void)

{
  return BUFC->BUF2_STATUS & 0x1fff;
}



uint8_t BUFC_RxBufferReadByte(void)

{
  return BUFC->BUF1_READDATA & 0xff;
}

uint8_t BUFC_Readbyte(uint32_t buf)

{
  return (&BUFC->BUF0_READDATA)[buf * 12] & 0xff;
}



void BUFC_ReadContASync(uint32_t buf,uint8_t *dest,uint16_t len)

{
  uint8_t *end;
  
  end = dest + len;
  for (; dest != end; dest ++) *dest = (uint8_t)(&BUFC->BUF0_READDATA)[buf * 0xc];
}



void BUFC_RxBufferReadBytes(uint8_t *dest,uint16_t len)

{
  BUFC_ReadContASync(1,dest,len);
}



void BUFC_RxBufferDropBytes(uint16_t bytes)

{
  uint8_t dummy;
  
  for (; bytes != 0; bytes --) BUFC_RxBufferReadBytes(&dummy,1);
}


uint32_t BUFC_RxLengthReadNext(uint32_t param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4)

{
  uint32_t local_c;
  uint32_t uStack8;
  
  local_c = param_2;
  uStack8 = param_3;
  if (BUFC_RxBufferPacketAvailable() == 0) local_c = 0xffff;
  else
  {
//    RADIO_BUFCReadContASync(2,&local_c,2,param_4,param_1); //!!!!!!!!!!!!!!!!!!!!!
    local_c &= 0xff;
  }
  return local_c;
}


void BUFC_Clear(uint32_t buf)

{
  *(uint32_t*)((buf * 0x30 + 0x42181028) * 0x20) = 1; //using bit-banding C081
}


