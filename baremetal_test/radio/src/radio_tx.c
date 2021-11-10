#include "radio_tx.h"

void radio_stopPN9(void);
void radio_saveconfig(void);
void radio_restoreconfig(void);

uint32_t rfparamsfbuffer[20] = {};
uint8_t testModeRegisterState;

bool radio_sendpacket(void)
{
	BUFC_TxBufferReset();
	BUFC_WriteContSync(tx_fifo ,32);
  INT_Disable();
  if ((PROTIMER_CCTimerIsEnabled(3) == 0) && (PROTIMER_LBTIsActive() == 0)) 
	{
  if ((FRC->DFLCTRL & FRC_DFLCTRL_DFLMODE_Msk) == 0) FRC->WCNTCMP0 = BUFC_TxBufferBytesAvailable() - 1; 
		SEQ_CONTROL_REG &= ~0x20; 
		BUS_RegMaskedSet(&RAC->IFPGACTRL, RAC_IFPGACTRL_BANDSEL_Msk); //fix sequencer error
		RAC->CMD = RAC_CMD_TXEN_Msk;
    INT_Enable();
    return true;
  }
  INT_Enable();
  return false;
}

void radio_startCW(void)

{
  radio_saveconfig();
	SEQ->SYNTHLPFCTRLTX &= 0xfffffff0;
	MODEM->MODINDEX = 0;
	BUS_RegMaskedClear(&MODEM->CTRL0, MODEM_CTRL0_MODFORMAT_Msk);
	BUS_RegMaskedSet(&MODEM->CTRL0, 0x100);
	BUS_RegMaskedSet(&MODEM->PRE, MODEM_PRE_TXBASES_Msk);
  FRC->DFLCTRL = 5;
	BUS_RegMaskedSet(&FRC->CTRL, FRC_CTRL_RANDOMTX_Msk);
	BUS_RegMaskedSet(&RAC->IFPGACTRL, RAC_IFPGACTRL_BANDSEL_Msk);
	RAC->CMD = RAC_CMD_TXEN_Msk; 
}

void radio_startPN9(void)

{
  radio_saveconfig();
	radio_setupPN9();
  FRC->SNIFFCTRL = 0;
  FRC->DFLCTRL = 5;
	BUS_RegMaskedSet(&FRC->CTRL, FRC_CTRL_RANDOMTX_Msk);
	BUS_RegMaskedSet(&RAC->IFPGACTRL, RAC_IFPGACTRL_BANDSEL_Msk);
  RAC->CMD = RAC_CMD_TXEN_Msk; 
}

void radio_stoptx(void)
{
	RAC->CMD = RAC_CMD_TXDIS_Msk;
	while (!(FRC->IF & FRC_IF_TXABORTED_Msk)) {};
	do 
		{
      if (radio_HeadedToIdle() == 0) break;
    } while ((RAC->STATUS & 0xf000000) != 0);
// 	radio_restoreconfig();
  	init_radio();
}


void radio_setupPN9(void)

{
  FRC->FCD0 &= 0xffffbfff;
  FRC->FCD1 &= 0xffffbfff;
  FRC->FCD2 &= 0xffffbfff;
  FRC->FCD3 &= 0xffffbfff;
  FRC->FECCTRL = 1;
  FRC->WHITECTRL = 0x24;
  FRC->WHITEPOLY = 0x100;
  FRC->WHITEINIT = 0x138;
}



void radio_saveconfig(void)

{
  if (testModeRegisterState == 0) 
  {
    rfparamsfbuffer[0] = MODEM->AFC;
    rfparamsfbuffer[1] = MODEM->CTRL0;
    rfparamsfbuffer[2] = MODEM->CTRL1;
    rfparamsfbuffer[3] = MODEM->MODINDEX;
    rfparamsfbuffer[4] = MODEM->PRE;
    rfparamsfbuffer[5] = MODEM->TIMING;
    rfparamsfbuffer[6] = FRC->DFLCTRL;
    rfparamsfbuffer[7] = FRC->CTRL;
    rfparamsfbuffer[8] = FRC->FECCTRL;
    rfparamsfbuffer[9] = FRC->FCD0;
    rfparamsfbuffer[10] = FRC->FCD1;
    rfparamsfbuffer[11] = FRC->FCD2;
    rfparamsfbuffer[12] = FRC->FCD3;
    rfparamsfbuffer[13] = FRC->WHITECTRL;
    rfparamsfbuffer[14] = FRC->WHITEPOLY;
    rfparamsfbuffer[15] = FRC->WHITEINIT;
    rfparamsfbuffer[16] = SEQ->SYNTHLPFCTRLTX;
    rfparamsfbuffer[17] = FRC->SNIFFCTRL;
    rfparamsfbuffer[18] = FRC->IEN;
    FRC->IEN = 0;
    testModeRegisterState = 1;
  }
}



void radio_restoreconfig(void)

{
  if (testModeRegisterState != 0) 
  {
    MODEM->AFC = rfparamsfbuffer[0];
    MODEM->CTRL0 = rfparamsfbuffer[1];
    MODEM->CTRL1 = rfparamsfbuffer[2];
    MODEM->MODINDEX = rfparamsfbuffer[3];
    MODEM->PRE = rfparamsfbuffer[4];
    MODEM->TIMING = rfparamsfbuffer[5];
    FRC->DFLCTRL = rfparamsfbuffer[6];
    FRC->CTRL = rfparamsfbuffer[7];
    FRC->FECCTRL = rfparamsfbuffer[8];
    FRC->FCD0 = rfparamsfbuffer[9];
    FRC->FCD1 = rfparamsfbuffer[10];
    FRC->FCD2 = rfparamsfbuffer[11];
    FRC->FCD3 = rfparamsfbuffer[12];
    FRC->WHITECTRL = rfparamsfbuffer[13];
    FRC->WHITEPOLY = rfparamsfbuffer[14];
    FRC->WHITEINIT = rfparamsfbuffer[15];
    SEQ->SYNTHLPFCTRLTX = rfparamsfbuffer[16];
    FRC->SNIFFCTRL = rfparamsfbuffer[17];
    FRC->IFC = 0x7ffff;
    FRC->IEN = rfparamsfbuffer[18];
    testModeRegisterState = 0;
  }
}