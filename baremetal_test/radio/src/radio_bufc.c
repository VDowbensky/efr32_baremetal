#include "radio_bufc.h"

void BUFC_IRQHandler(void)
{
	uint32_t flags;
	flags = BUFC->IF & BUFC->IEN;
	BUFC->IFC = flags;
}

void BUFC_init(void)
{
	BUFC->BUF1_CTRL = 2; //size
	BUFC->BUF1_ADDR = (uint32_t)RADIO_rxBuffer;
  BUFC->BUF1_THRESHOLDCTRL = 0xaf;
  BUFC->BUF0_CTRL = 2; //size
  BUFC->BUF0_ADDR = (uint32_t)RADIO_txBuffer;
  BUFC->BUF0_THRESHOLDCTRL = 0x2020; //BUFC_BUF0_THRESHOLDCTRL_THRESHOLDMODE_Msk | THRESHOLD
  BUFC->BUF2_CTRL = 0; //size
  BUFC->BUF2_ADDR = (uint32_t)RADIO_rxLengthBuffer;
  BUFC->BUF2_THRESHOLDCTR = 0x3e; 
	 // DAT_000109d8 = RADIO_BUFCIrqHandler;
  BUFC_Clear(0);
  BUFC_Clear(1);
  BUFC_Clear(2);
  BUFC->IEN |= 0xb0a0b; //23,21,20,11,9,3,1,0 
  BUFC_RXBufferDisableThrInt();
	
}

/*
void RADIO_BUFCIrqHandler(void)

{
  uint16_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint8_t * iVar4;
  uint32_t flags;
  
  //uVar2 = read_volatile_4(BUFC->IF);
  //uVar3 = BUFC->IEN;
  //write_volatile_4(BUFC->IFC,uVar2 & uVar3);
	flags = BUFC->IEN & BUFC->IF;
  BUFC->IFC = flags;
  
  //if ((int)(uVar5 << 0x1d) < 0)
	  if(flags & 0x04)
    {
 //   iVar4 = DAT_00010b88 + (uint32_t)DAT_00010b8c;
 //   if (((uint)DAT_00010b82 - (uint32_t)DAT_00010b8c & 0xffff) < 0xe1) {
 //     RADIO_BUFCWriteContSync_constprop_3(iVar4);
      //_DAT_43021d90 = 0;  //BUFC->REG0EC bit 4 -
      BUFC->IEN &= ~0x10;
    }
    else
    {
 //     uVar1 = DAT_00010b8c + 0xe0;
      RADIO_BUFCWriteContSync_constprop_3(iVar4,0xe0);
 //     DAT_00010b8c = uVar1;
    }
  //if ((int)(uVar5 << 0x15) < 0)
  if(flags & 0x400) RFTEST_BerEmptyBufcAndUpdateStats();
  if (flags & 0xa0a00) RADIO_RxBufferReset();
  if(flags & 0x9)
  {
    //_DAT_43080114 = 1;
    //RAC->CMD |= 0x20; //TXDIS
		BUS_RegMaskedSet(&RAC->CMD, RAC_CMD_TXDIS_Msk);
    RADIO_TxBufferReset();
  }
   if(flags & 0x02) RADIO_TxBufferReset();
}
*/
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


void BUFC_Config(uint32_t buf,uint32_t len,uint32_t address,uint32_t threshold,uint32_t tresholdmode)
{
  (&BUFC->BUF0_CTRL)[buf * 0xc] = 0x19 - __CLZ(len);
  (&BUFC->BUF0_ADDR)[buf * 0xc] = address;
  (&BUFC->BUF0_THRESHOLDCTRL)[buf * 0xc] = threshold | tresholdmode;
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


int BUFC_RxBufferFinalizeAndGet(int *param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4)

{
  int iVar1;
  int iVar2;
  
//  iVar2 = RADIO_RxLengthReadNext();
//  iVar1 = DAT_00010b7c;
//  if (iVar2 != 0xffff) {
//    RADIO_BUFCReadContASync
//              (1,DAT_00010b7c + (uint)bufcRxStreaming,iVar2 - (uint)bufcRxStreaming,0xffff,param_4);
//    bufcRxStreaming = (ushort)iVar2;
//    _DAT_43022d80 = 0; //BUFC->REG16C bit 0

 //   *param_1 = iVar1;
 // }
  return iVar2;
}

