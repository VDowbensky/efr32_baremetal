#include "railtest_1_5_2_2.h"



// WARNING: Control flow encountered bad instruction data

void FUN_00000000(void)

{
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Removing unreachable block (ram,0x000000d4)

undefined4 __do_global_dtors_aux(undefined4 param_1)

{
  if (completed_9929 == '\0') {
    completed_9929 = '\x01';
  }
  return param_1;
}



// WARNING: Removing unreachable block (ram,0x000000f2)

undefined8 frame_dummy(undefined4 param_1,undefined4 param_2)

{
  return CONCAT44(param_2,param_1);
}



// WARNING: Removing unreachable block (ram,0x00000134)
// WARNING: Removing unreachable block (ram,0x0000010e)
// WARNING: Removing unreachable block (ram,0x0000012c)
// WARNING: Removing unreachable block (ram,0x00000144)

void _start(void)

{
  int __status;
  
  memset(&completed_9929,0,(size_t)&PTR_lbtParams_0000288c);
  __libc_init_array(0,0);
  __status = main();
                    // WARNING: Subroutine does not return
  exit(__status);
}



uint32_t SystemCoreClockGet(void)

{
  uint uVar1;
  uint32_t uVar2;
  uint32_t presc;
  uint32_t ret;
  
  uVar2 = SystemHFClockGet();
  uVar1 = (CMU->HFCOREPRESC);
  SystemCoreClock = uVar2 / ((uVar1 >> 8 & 0x1ff) + 1);
  return SystemCoreClock;
}



uint32_t SystemMaxCoreClockGet(void)

{
  return 38400000;
}



uint32_t SystemHFClockGet(void)

{
  uint uVar1;
  uint32_t ret;
  
  uVar1 = (CMU->HFCLKSTATUS);
  uVar1 = uVar1 & 7;
  if (uVar1 == 3) {
    ret = 0x8000;
  }
  else {
    if (uVar1 == 4) {
      ret = SystemLFXOClock;
    }
    else {
      if (uVar1 == 2) {
        ret = SystemHFXOClock;
      }
      else {
        ret = SystemHfrcoFreq;
      }
    }
  }
  uVar1 = (CMU->HFPRESC);
  return ret / ((uVar1 >> 8 & 0x1f) + 1);
}



uint32_t SystemHFXOClockGet(void)

{
  return SystemHFXOClock;
}



void SystemHFXOClockSet(uint32_t freq)

{
  uint uVar1;
  
  uVar1 = (CMU->HFCLKSTATUS);
  SystemHFXOClock = freq;
  if ((uVar1 & 7) == 2) {
    SystemCoreClockGet();
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void SystemInit(void)

{
  _DAT_e000ed88 = _DAT_e000ed88 | 0xf00000;
  return;
}



uint32_t SystemLFRCOClockGet(void)

{
  return 0x8000;
}



uint32_t SystemULFRCOClockGet(void)

{
  return 1000;
}



uint32_t SystemLFXOClockGet(void)

{
  return SystemLFXOClock;
}



// WARNING: Removing unreachable block (ram,0x000003fe)
// WARNING: Could not reconcile some variable overlaps

void ieee802154Enable(int argc,char **argv)

{
  _Bool _Var1;
  RAIL_Status_t code;
  int iVar2;
  uint32_t uVar3;
  RAIL_IEEE802154_Config_t config;
  RAIL_Status_t status;
  uint16_t timing;
  
  _Var1 = inRadioState(RAIL_RF_STATE_IDLE,*argv);
  if (_Var1 == true) {
    config._0_3_ = 0xb0000;
    config.defaultState = RAIL_RF_STATE_RX;
    config._4_4_ = 0xc00064;
    config._8_4_ = 1000;
    config.addresses = (RAIL_IEEE802154_AddrConfig_t *)0x0;
    iVar2 = memcmp(argv[1],&DAT_00017064,4);
    if (iVar2 == 0) {
      config.defaultState = RAIL_RF_STATE_IDLE;
    }
    else {
      iVar2 = memcmp(argv[1],&DAT_0001706c,2);
      if (iVar2 != 0) {
        responsePrintError(*argv,' ',"Unknown auto ack default state.");
        return;
      }
      config.defaultState = RAIL_RF_STATE_RX;
    }
    uVar3 = ciGetUnsigned(argv[2]);
    if ((ushort)uVar3 < 0x32c9) {
      config._4_4_ = config._4_4_ & 0xffff0000 | uVar3 & 0xffff;
      uVar3 = ciGetUnsigned(argv[3]);
      if ((ushort)uVar3 < 0x32c9) {
        config._4_4_ = config._4_4_ & 0xffff | uVar3 << 0x10;
        uVar3 = ciGetUnsigned(argv[4]);
        config._8_4_ = config._8_4_ & 0xffff0000 | uVar3 & 0xffff;
        code = RAIL_IEEE802154_Init(&config);
        if (code == RAIL_STATUS_NO_ERROR) {
          responsePrint(*argv,
                        "802.15.4:%s,defaultState:%s,idleTiming:%d,turnaroundTime:%d,ackTimeout:%d",
                        "Enabled",rfStates[config.defaultState],config._4_4_ & 0xffff,
                        config._4_4_ >> 0x10,config._8_4_ & 0xffff);
        }
        else {
          responsePrintError(*argv,code,"Call to RAIL_IEEE802154_Init returned an error");
        }
      }
      else {
        responsePrintError(*argv,'\"',"Invalid turnaround timing");
      }
    }
    else {
      responsePrintError(*argv,'!',"Invalid idle timing.");
    }
  }
  return;
}



void config2p4Ghz802154(int argc,char **argv)

{
  _Bool _Var1;
  RAIL_Status_t RVar2;
  char *pcVar3;
  RAIL_Status_t status;
  
  _Var1 = inRadioState(RAIL_RF_STATE_IDLE,*argv);
  if (_Var1 == true) {
    RVar2 = RAIL_IEEE802154_2p4GHzRadioConfig();
    changeChannel(0xb);
    if (RVar2 == RAIL_STATUS_NO_ERROR) {
      pcVar3 = "Enabled";
    }
    else {
      pcVar3 = "Disabled";
    }
    responsePrint(*argv,"802.15.4:%s",pcVar3,pcVar3,argv,argc);
  }
  return;
}



void ieee802154AcceptFrames(int argc,char **argv)

{
  RAIL_Status_t RVar1;
  uint32_t uVar2;
  char *pcVar3;
  char *pcVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char *pcVar9;
  char *pcVar10;
  bool bVar11;
  RAIL_Status_t status;
  _Bool beaconFrame;
  _Bool dataFrame;
  _Bool ackFrame;
  _Bool commandFrame;
  uint8_t framesEnable;
  
  framesEnable = '\0';
  uVar2 = ciGetUnsigned(argv[1]);
  bVar11 = uVar2 != 0;
  if (bVar11) {
    uVar2 = 1;
  }
  cVar5 = (char)uVar2;
  if (!bVar11) {
    cVar5 = '\0';
  }
  uVar2 = ciGetUnsigned(argv[2]);
  bVar11 = uVar2 != 0;
  if (bVar11) {
    uVar2 = 1;
  }
  cVar6 = (char)uVar2;
  if (!bVar11) {
    cVar6 = '\0';
  }
  uVar2 = ciGetUnsigned(argv[3]);
  bVar11 = uVar2 != 0;
  if (bVar11) {
    uVar2 = 1;
  }
  cVar7 = (char)uVar2;
  if (!bVar11) {
    cVar7 = '\0';
  }
  uVar2 = ciGetUnsigned(argv[4]);
  bVar11 = uVar2 != 0;
  if (bVar11) {
    uVar2 = 1;
  }
  cVar8 = (char)uVar2;
  if (!bVar11) {
    cVar8 = '\0';
  }
  if (cVar5 != '\0') {
    framesEnable = '\b';
  }
  if (cVar6 != '\0') {
    framesEnable = framesEnable | 4;
  }
  if (cVar7 != '\0') {
    framesEnable = framesEnable | 2;
  }
  if (cVar8 != '\0') {
    framesEnable = framesEnable | 1;
  }
  RVar1 = RAIL_IEEE802154_AcceptFrames(framesEnable);
  if (RVar1 == RAIL_STATUS_NO_ERROR) {
    if (cVar5 == '\0') {
      pcVar3 = "Disabled";
    }
    else {
      pcVar3 = "Enabled";
    }
    if (cVar6 == '\0') {
      pcVar10 = "Disabled";
    }
    else {
      pcVar10 = "Enabled";
    }
    if (cVar7 == '\0') {
      pcVar9 = "Disabled";
    }
    else {
      pcVar9 = "Enabled";
    }
    if (cVar8 == '\0') {
      pcVar4 = "Disabled";
    }
    else {
      pcVar4 = "Enabled";
    }
    responsePrint(*argv,"CommandFrame:%s,AckFrame:%s,DataFrame:%s,BeaconFrame:%s",pcVar3,pcVar10,
                  pcVar9,pcVar4);
  }
  else {
    responsePrintError(*argv,'#',"Failed to set which frames to accept.");
  }
  return;
}



void ieee802154SetPromiscuousMode(int argc,char **argv)

{
  RAIL_Status_t RVar1;
  uint32_t uVar2;
  undefined enable;
  char *pcVar3;
  bool bVar4;
  RAIL_Status_t status;
  _Bool promiscuous;
  
  uVar2 = ciGetUnsigned(argv[1]);
  bVar4 = uVar2 != 0;
  if (bVar4) {
    uVar2 = 1;
  }
  enable = (undefined)uVar2;
  if (!bVar4) {
    enable = false;
  }
  RVar1 = RAIL_IEEE802154_SetPromiscuousMode((bool)enable);
  if (RVar1 == RAIL_STATUS_NO_ERROR) {
    if ((bool)enable == false) {
      pcVar3 = "Disabled";
    }
    else {
      pcVar3 = "Enabled";
    }
    responsePrint(*argv,"PromiscuousMode:%s",pcVar3,pcVar3,argv,argc);
  }
  else {
    responsePrintError(*argv,'$',"Failed to (un)set promiscuous mode.");
  }
  return;
}



void ieee802154SetPanCoordinator(int argc,char **argv)

{
  RAIL_Status_t RVar1;
  uint32_t uVar2;
  undefined isPanCoordinator;
  char *pcVar3;
  bool bVar4;
  RAIL_Status_t status;
  _Bool panCoord;
  
  uVar2 = ciGetUnsigned(argv[1]);
  bVar4 = uVar2 != 0;
  if (bVar4) {
    uVar2 = 1;
  }
  isPanCoordinator = (undefined)uVar2;
  if (!bVar4) {
    isPanCoordinator = false;
  }
  RVar1 = RAIL_IEEE802154_SetPanCoordinator((bool)isPanCoordinator);
  if (RVar1 == RAIL_STATUS_NO_ERROR) {
    if ((bool)isPanCoordinator == false) {
      pcVar3 = "Disabled";
    }
    else {
      pcVar3 = "Enabled";
    }
    responsePrint(*argv,"PanCoordinator:%s",pcVar3,pcVar3,argv,argc);
  }
  else {
    responsePrintError(*argv,'$',"Failed to (un)set PAN Coordinator.");
  }
  return;
}



void ieee802154SetPanId(int argc,char **argv)

{
  bool bVar1;
  uint32_t uVar2;
  char *pcVar3;
  _Bool status;
  uint16_t panId;
  
  uVar2 = ciGetUnsigned(argv[1]);
  bVar1 = RAIL_IEEE802154_SetPanId((uint16_t)uVar2);
  if (bVar1 == false) {
    pcVar3 = "Disabled";
  }
  else {
    pcVar3 = "Enabled";
  }
  responsePrint(*argv,"802.15.4PanId:%s",pcVar3,pcVar3,argv,argc);
  return;
}



void ieee802154SetShortAddress(int argc,char **argv)

{
  bool bVar1;
  uint32_t uVar2;
  char *pcVar3;
  _Bool status;
  uint16_t shortAddr;
  
  uVar2 = ciGetUnsigned(argv[1]);
  bVar1 = RAIL_IEEE802154_SetShortAddress((uint16_t)uVar2);
  if (bVar1 == false) {
    pcVar3 = "Disabled";
  }
  else {
    pcVar3 = "Enabled";
  }
  responsePrint(*argv,"802.15.4ShortAddress:%s",pcVar3,pcVar3,argv,argc);
  return;
}



void ieee802154SetLongAddress(int argc,char **argv)

{
  bool bVar1;
  uint32_t uVar2;
  char *pcVar3;
  uint8_t longAddr [8];
  _Bool status;
  int i;
  
  for (i = 0; i < 8; i = i + 1) {
    uVar2 = ciGetUnsigned(argv[i + 1]);
    longAddr[i] = (uint8_t)uVar2;
  }
  bVar1 = RAIL_IEEE802154_SetLongAddress(longAddr);
  if (bVar1 == false) {
    pcVar3 = "Disabled";
  }
  else {
    pcVar3 = "Enabled";
  }
  responsePrint(*argv,"802.15.4LongAddress:%s",pcVar3,pcVar3,argv,argc);
  return;
}



void setAddressFilterConfig(int argc,char **argv)

{
  bool bVar1;
  uint32_t uVar2;
  int count;
  int i;
  
  count = 4;
  memset(offsets,0,2);
  memset(sizes,0,2);
  memset(addresses,0,0x40);
  memset(addressEnabled,0,8);
  config.matchTable = ciGetUnsigned(argv[1]);
  if (argc + -2 < 4) {
    count = argc + -2;
  }
  for (i = 0; i < count; i = i + 1) {
    if ((i & 1U) == 0) {
      uVar2 = ciGetUnsigned(argv[i + 2]);
      config.offsets[i / 2] = (uint8_t)uVar2;
    }
    else {
      uVar2 = ciGetUnsigned(argv[i + 2]);
      config.sizes[i / 2] = (uint8_t)uVar2;
    }
  }
  bVar1 = RAIL_AddressFilterConfig(&config);
  if (bVar1 == false) {
    responsePrintError(*argv,'0',"Invalid address filtering configuration.");
  }
  else {
    printAddresses(1,argv);
  }
  return;
}



void addressFilterByFrame(int argc,char **argv)

{
  bool bVar1;
  uint32_t uVar2;
  uint8_t validFrames;
  
  uVar2 = ciGetUnsigned(argv[1]);
  bVar1 = RAIL_AddressFilterByFrameType((uint8_t)uVar2);
  if (bVar1 == false) {
    responsePrintError(*argv,'5',"Invalid filtering by frame config.",*argv,argv,argc);
  }
  else {
    responsePrint(*argv,"AddressFilterByFrame:Set");
  }
  return;
}



void setAddressFilter(int argc,char **argv)

{
  uint32_t uVar1;
  uint32_t enable;
  
  uVar1 = ciGetUnsigned(argv[1]);
  if (uVar1 == 0) {
    RAIL_AddressFilterDisable();
  }
  else {
    RAIL_AddressFilterEnable();
  }
  getAddressFilter(1,argv);
  return;
}



void getAddressFilter(int argc,char **argv)

{
  bool bVar1;
  char *pcVar2;
  _Bool filteringEnabled;
  
  bVar1 = RAIL_AddressFilterIsEnabled();
  if (bVar1 == false) {
    pcVar2 = "Disabled";
  }
  else {
    pcVar2 = "Enabled";
  }
  responsePrint(*argv,"AddressFiltering:%s",pcVar2,pcVar2,argv,argc);
  return;
}



void printAddresses(int argc,char **argv)

{
  int iVar1;
  char *pcVar2;
  int offset;
  int k;
  int j;
  int i;
  
  responsePrintHeader(*argv,"Field:%u,Index:%u,Offset:%u,Size:%u,Address:%s,Status:%s");
  for (i = 0; i < 2; i = i + 1) {
    for (j = 0; j < 4; j = j + 1) {
      offset = 0;
      if (sizes[i] == '\0') {
        addressPrintBuffer[0] = '\0';
      }
      else {
        for (k = 0; k < (int)(uint)sizes[i]; k = k + 1) {
          iVar1 = siprintf(addressPrintBuffer + offset,"0x%.2x ",(uint)addresses[j + i * 4][k]);
          offset = offset + iVar1;
        }
        if (0 < offset) {
          *(undefined *)(offset + 0x20000bdb) = 0;
        }
      }
      if (addressEnabled[i][j] == false) {
        pcVar2 = "Disabled";
      }
      else {
        pcVar2 = "Enabled";
      }
      responsePrintMulti("Field:%u,Index:%u,Offset:%u,Size:%u,Address:%s,Status:%s",i,j,
                         (uint)offsets[i],(uint)sizes[i],addressPrintBuffer,pcVar2);
    }
  }
  return;
}



// WARNING: Could not reconcile some variable overlaps

void setAddress(int argc,char **argv)

{
  bool bVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  undefined4 local_24;
  uint8_t address [8];
  _Bool result;
  int location;
  uint8_t index;
  uint8_t field;
  int i;
  
  local_24 = argc;
  uVar2 = ciGetUnsigned(argv[1]);
  field = (uint8_t)uVar2;
  uVar3 = ciGetUnsigned(argv[2]);
  index = (uint8_t)uVar3;
  location = (uVar3 & 0xff) + (uVar2 & 0xff) * 4;
  if ((field < 3) && (index < 5)) {
    if (local_24 < 0xc) {
      memset(address,0,8);
      for (i = 3; i < local_24; i = i + 1) {
        uVar2 = ciGetUnsigned(argv[i]);
        address[i + -3] = (uint8_t)uVar2;
      }
      bVar1 = RAIL_AddressFilterSetAddress(field,index,address,(bool)addressEnabled[field][index]);
      if (bVar1 == true) {
        *(undefined4 *)addresses[location] = address._0_4_;
        *(undefined4 *)(addresses[location] + 4) = address._4_4_;
        printAddresses(1,argv);
      }
      else {
        responsePrintError(*argv,'3',"Could not configure address!");
      }
    }
    else {
      responsePrintError(*argv,'2',"Too many address bytes given!");
    }
  }
  else {
    responsePrintError(*argv,'1',"Address field or index out of range!");
  }
  return;
}



void enableAddress(int argc,char **argv)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  char *pcVar4;
  uint8_t enable;
  uint8_t index;
  uint8_t field;
  _Bool result;
  
  uVar1 = ciGetUnsigned(argv[1]);
  uVar2 = ciGetUnsigned(argv[2]);
  uVar3 = ciGetUnsigned(argv[3]);
  if ((char)uVar3 == '\0') {
    result = (_Bool)RAIL_AddressFilterDisableAddress((uint8_t)uVar1,(uint8_t)uVar2);
  }
  else {
    result = (_Bool)RAIL_AddressFilterEnableAddress((uint8_t)uVar1,(uint8_t)uVar2);
  }
  if (result == true) {
    addressEnabled[uVar1 & 0xff][uVar2 & 0xff] = (_Bool)((char)uVar3 != '\0');
    if (addressEnabled[uVar1 & 0xff][uVar2 & 0xff] == false) {
      pcVar4 = "Disabled";
    }
    else {
      pcVar4 = "Enabled";
    }
    responsePrint(*argv,"Field:%u,Index:%u,Offset:%u,Size:%u,Address:%s,Status:%s",uVar1 & 0xff,
                  uVar2 & 0xff,(uint)offsets[uVar1 & 0xff],(uint)sizes[uVar1 & 0xff],
                  addressPrintBuffer,pcVar4);
  }
  else {
    responsePrintError(*argv,'4',"Could not enable/disable address!");
  }
  return;
}



void autoAckConfig(int argc,char **argv)

{
  _Bool _Var1;
  RAIL_Status_t code;
  int iVar2;
  uint32_t uVar3;
  RAIL_Status_t status;
  uint16_t timing;
  
  _Var1 = inRadioState(RAIL_RF_STATE_IDLE,*argv);
  if (_Var1 == true) {
    iVar2 = memcmp(argv[1],&DAT_000173e8,4);
    if (iVar2 == 0) {
      config.defaultState = RAIL_RF_STATE_IDLE;
    }
    else {
      iVar2 = memcmp(argv[1],&DAT_000173f0,2);
      if (iVar2 != 0) {
        responsePrintError(*argv,' ',"Unknown auto ack default state.");
        return;
      }
      config.defaultState = RAIL_RF_STATE_RX;
    }
    uVar3 = ciGetUnsigned(argv[2]);
    if ((ushort)uVar3 < 0x32c9) {
      config.idleTiming = (ushort)uVar3;
      uVar3 = ciGetUnsigned(argv[3]);
      if ((ushort)uVar3 < 0x32c9) {
        config.turnaroundTime = (ushort)uVar3;
        uVar3 = ciGetUnsigned(argv[4]);
        config.ackTimeout = (uint16_t)uVar3;
        code = RAIL_AutoAckConfig(&config);
        if (code == RAIL_STATUS_NO_ERROR) {
          responsePrint(*argv,"defaultState:%s,idleTiming:%d,turnaroundTime:%d,ackTimeout:%d",
                        rfStates[config.defaultState],(uint)config.idleTiming,
                        (uint)config.turnaroundTime,(uint)config.ackTimeout);
        }
        else {
          responsePrintError(*argv,code,"Call to RAIL_AutoAckConfig returned an error");
        }
      }
      else {
        responsePrintError(*argv,'\"',"Invalid turnaround timing");
      }
    }
    else {
      responsePrintError(*argv,'!',"Invalid idle timing.");
    }
  }
  return;
}



void getAutoAck(int argc,char **argv)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  _Bool txPaused;
  _Bool rxPaused;
  _Bool filteringEnabled;
  
  bVar1 = RAIL_AutoAckIsEnabled();
  bVar2 = RAIL_AutoAckRxIsPaused();
  bVar3 = RAIL_AutoAckTxIsPaused();
  if (bVar1 == false) {
    pcVar5 = "Disabled";
  }
  else {
    pcVar5 = "Enabled";
  }
  if (bVar2 == false) {
    pcVar4 = "Unpaused";
  }
  else {
    pcVar4 = "Paused";
  }
  if (bVar3 == false) {
    pcVar6 = "Unpaused";
  }
  else {
    pcVar6 = "Paused";
  }
  responsePrint(*argv,"AutoAck:%s,RxAutoAckStatus:%s,TxAutoAckStatus:%s",pcVar5,pcVar4,pcVar6);
  return;
}



void autoAckDisable(int argc,char **argv)

{
  RAIL_Status_t code;
  RAIL_Status_t status;
  
  code = RAIL_AutoAckDisable();
  if (code != RAIL_STATUS_NO_ERROR) {
    responsePrintError(*argv,code,"Error disabling AutoAck",*argv,argv,argc);
  }
  getAutoAck(1,argv);
  return;
}



void autoAckPause(int argc,char **argv)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint8_t txEnable;
  uint8_t rxEnable;
  
  uVar1 = ciGetUnsigned(argv[1]);
  uVar2 = ciGetUnsigned(argv[2]);
  if ((uVar1 & 0xff) == 0) {
    RAIL_AutoAckRxResume();
  }
  else {
    RAIL_AutoAckRxPause();
  }
  if ((char)uVar2 == '\0') {
    RAIL_AutoAckTxResume();
  }
  else {
    RAIL_AutoAckTxPause();
  }
  getAutoAck(1,argv);
  return;
}



void setTxAckOptions(int argc,char **argv)

{
  uint32_t uVar1;
  uint32_t uVar2;
  char *pcVar3;
  char *pcVar4;
  uint8_t useTxBuffer;
  uint8_t cancelAck;
  
  uVar1 = ciGetUnsigned(argv[1]);
  uVar2 = ciGetUnsigned(argv[2]);
  afterRxCancelAck = (_Bool)((char)uVar1 != '\0');
  afterRxUseTxBufferForAck = (_Bool)((char)uVar2 != '\0');
  if ((bool)afterRxCancelAck) {
    pcVar3 = "True";
  }
  else {
    pcVar3 = "False";
  }
  if ((bool)afterRxUseTxBufferForAck) {
    pcVar4 = "True";
  }
  else {
    pcVar4 = "False";
  }
  responsePrint(*argv,"CancelAck:%s,UseTxBuffer:%s",pcVar3,pcVar4,argv,argc);
  return;
}



void bleEnable(int argc,char **argv)

{
  _Bool _Var1;
  uint32_t uVar2;
  char cVar3;
  bool bVar4;
  _Bool enable;
  
  uVar2 = ciGetUnsigned(argv[1]);
  bVar4 = uVar2 != 0;
  if (bVar4) {
    uVar2 = 1;
  }
  cVar3 = (char)uVar2;
  if (!bVar4) {
    cVar3 = '\0';
  }
  _Var1 = inRadioState(RAIL_RF_STATE_IDLE,*argv);
  if (_Var1 == true) {
    if (cVar3 == '\0') {
      RAIL_BLE_Deinit();
    }
    else {
      RAIL_BLE_Init();
    }
    bleStatus(1,argv);
  }
  return;
}



void bleStatus(int argc,char **argv)

{
  bool bVar1;
  char *pcVar2;
  _Bool enabled;
  
  bVar1 = RAIL_BLE_IsEnabled();
  if (bVar1 == false) {
    pcVar2 = "Disabled";
  }
  else {
    pcVar2 = "Enabled";
  }
  responsePrint(*argv,"BLE:%s",pcVar2,pcVar2,argv,argc);
  return;
}



void bleSet1MbpsPhy(int argc,char **argv)

{
  _Bool _Var1;
  uint32_t uVar2;
  char *pcVar3;
  bool bVar4;
  _Bool isViterbi;
  _Bool success;
  
  if (argc == 2) {
    uVar2 = ciGetUnsigned(argv[1]);
    bVar4 = uVar2 != 0;
    if (bVar4) {
      uVar2 = 1;
    }
    isViterbi = (_Bool)(char)uVar2;
    if (!bVar4) {
      isViterbi = false;
    }
  }
  else {
    isViterbi = false;
  }
  _Var1 = inRadioState(RAIL_RF_STATE_IDLE,*argv);
  if (_Var1 == true) {
    if (isViterbi == false) {
      success = (_Bool)RAIL_BLE_SetPhy1Mbps();
    }
    else {
      success = (_Bool)RAIL_BLE_SetPhy1MbpsViterbi();
    }
    if (success == false) {
      pcVar3 = "Fail";
    }
    else {
      pcVar3 = "Success";
    }
    responsePrint(*argv,"Status:%s",pcVar3);
  }
  return;
}



void bleSet2MbpsPhy(int argc,char **argv)

{
  _Bool _Var1;
  uint32_t uVar2;
  char *pcVar3;
  bool bVar4;
  _Bool isViterbi;
  _Bool success;
  
  if (argc == 2) {
    uVar2 = ciGetUnsigned(argv[1]);
    bVar4 = uVar2 != 0;
    if (bVar4) {
      uVar2 = 1;
    }
    isViterbi = (_Bool)(char)uVar2;
    if (!bVar4) {
      isViterbi = false;
    }
  }
  else {
    isViterbi = false;
  }
  _Var1 = inRadioState(RAIL_RF_STATE_IDLE,*argv);
  if (_Var1 == true) {
    if (isViterbi == false) {
      success = (_Bool)RAIL_BLE_SetPhy2Mbps();
    }
    else {
      success = (_Bool)RAIL_BLE_SetPhy2MbpsViterbi();
    }
    if (success == false) {
      pcVar3 = "Fail";
    }
    else {
      pcVar3 = "Success";
    }
    responsePrint(*argv,"Status:%s",pcVar3);
  }
  return;
}



void bleSetChannelParams(int argc,char **argv)

{
  bool bVar1;
  uint32_t uVar2;
  char *pcVar3;
  _Bool res;
  _Bool disableWhitening;
  uint8_t logicalChannel;
  uint32_t crcInit;
  uint32_t accessAddress;
  
  accessAddress = 0x8e89bed6;
  crcInit = 0x555555;
  logicalChannel = '%';
  disableWhitening = false;
  bVar1 = RAIL_BLE_IsEnabled();
  if (bVar1 == true) {
    if (1 < argc) {
      uVar2 = ciGetUnsigned(argv[1]);
      logicalChannel = (uint8_t)uVar2;
    }
    if (2 < argc) {
      accessAddress = ciGetUnsigned(argv[2]);
    }
    if (3 < argc) {
      crcInit = ciGetUnsigned(argv[3]);
    }
    if (4 < argc) {
      uVar2 = ciGetUnsigned(argv[4]);
      bVar1 = uVar2 != 0;
      if (bVar1) {
        uVar2 = 1;
      }
      disableWhitening = (_Bool)(char)uVar2;
      if (!bVar1) {
        disableWhitening = false;
      }
    }
    bVar1 = RAIL_BLE_SetupChannelRadioParams
                      (crcInit,accessAddress,logicalChannel,(bool)disableWhitening);
    if (bVar1 == false) {
      responsePrintError(*argv,'2',"Setting channel parameters failed");
    }
    else {
      if (disableWhitening == false) {
        pcVar3 = "Enabled";
      }
      else {
        pcVar3 = "Disabled";
      }
      responsePrint(*argv,"LogicalChannel:%d,AccessAddress:0x%0.8X,CrcInit:0x%0.8X,Whitening:%s",
                    (uint)logicalChannel,accessAddress,crcInit,pcVar3);
    }
  }
  else {
    responsePrintError(*argv,'1',"BLE mode not enabled");
  }
  return;
}



void bleAdvertisingConfig(int argc,char **argv)

{
  byte channel;
  bool bVar1;
  uint32_t uVar2;
  _Bool res;
  uint8_t advChannel;
  
  uVar2 = ciGetUnsigned(argv[1]);
  channel = (byte)uVar2;
  bVar1 = RAIL_BLE_IsEnabled();
  if (bVar1 == true) {
    if ((channel < 0x25) || (0x27 < channel)) {
      responsePrintError(*argv,'0',"Invalid advertising channel");
    }
    else {
      bVar1 = RAIL_BLE_SetupChannelRadioParams(0x555555,0x8e89bed6,channel,false);
      if (bVar1 == true) {
        if (channel == 0x25) {
          changeChannel(0);
        }
        else {
          if (channel == 0x26) {
            changeChannel(0xc);
          }
          else {
            if (channel == 0x27) {
              changeChannel(0x27);
            }
          }
        }
        responsePrint(*argv,"AdvertisingChannel:%d",uVar2 & 0xff,*argv,argv,argc);
        txData._0_4_ = 0xeeff1a02;
        txData._4_4_ = 0xaabbccdd;
        txData._8_4_ = 0x10060102;
        txData._12_4_ = 0x6c695308;
        txData._16_4_ = 0x20736261;
        txData._20_4_ = 0x4c494152;
        txData._24_4_ = 0x54534554;
        transmitPayload.dataLength = 0x1c;
        printTxPacket(1,argv);
      }
      else {
        responsePrintError(*argv,'2',"Setting channel parameters failed");
      }
    }
  }
  else {
    responsePrintError(*argv,'1',"BLE mode not enabled");
  }
  return;
}



void NVIC_SystemReset(void)

{
  DataSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



void setFrequency(int argc,char **argv)

{
  _Bool _Var1;
  RAIL_Status_t RVar2;
  uint32_t freq;
  uint32_t uVar3;
  uint32_t newFrequency;
  
  freq = ciGetUnsigned(argv[1]);
  _Var1 = inRadioState(RAIL_RF_STATE_IDLE,*argv);
  if (_Var1 == true) {
    uVar3 = RAIL_DebugModeGet();
    if ((uVar3 & 1) == 1) {
      RVar2 = RAIL_DebugFrequencyOverride(freq);
      if (RVar2 == RAIL_STATUS_NO_ERROR) {
        responsePrint(*argv,"NewFrequency:%u",freq);
      }
      else {
        responsePrintError(*argv,'\x14',"%u Hz is out of range and cannot be set as the frequency",
                           freq,argv,argc);
      }
    }
    else {
      responsePrintError(*argv,'\x13',"Not currently in frequency override debug mode.",*argv,argv,
                         argc);
    }
  }
  return;
}



char * lookupDebugModeString(uint32_t debugMode)

{
  char *pcVar1;
  
  if (debugMode == 0) {
    pcVar1 = "Disabled";
  }
  else {
    if ((debugMode & 1) == 0) {
      pcVar1 = "NULL";
    }
    else {
      pcVar1 = "Frequency Override";
    }
  }
  return pcVar1;
}



void setDebugMode(int argc,char **argv)

{
  RAIL_Status_t RVar1;
  uint32_t debugMode_00;
  char *pcVar2;
  char *command;
  uint32_t debugMode;
  
  debugMode_00 = ciGetUnsigned(argv[1]);
  RVar1 = RAIL_DebugModeSet(debugMode_00);
  if (RVar1 == RAIL_STATUS_NO_ERROR) {
    command = *argv;
    pcVar2 = lookupDebugModeString(debugMode_00);
    responsePrint(command,"DebugMode:%s",pcVar2);
  }
  else {
    responsePrintError(*argv,'\x15',"%d is an invalid debug mode!",debugMode_00,argv,argc);
  }
  return;
}



void getMemWord(int argc,char **argv)

{
  uint32_t uVar1;
  uint32_t value;
  uint32_t *address;
  uint32_t i;
  uint32_t count;
  
  uVar1 = ciGetUnsigned(argv[1]);
  count = 1;
  if (2 < argc) {
    count = ciGetUnsigned(argv[2]);
  }
  if ((uVar1 & 3) == 0) {
    responsePrintHeader(*argv,"address:0x%.8x,value:0x%.8x");
    for (i = 0; i < count; i = i + 1) {
      responsePrintMulti("address:0x%.8x,value:0x%.8x",i * 4 + uVar1,*(undefined4 *)(i * 4 + uVar1))
      ;
    }
  }
  else {
    responsePrintError(*argv,0xff,"Address 0x%.8X is not 32bit aligned",uVar1);
  }
  return;
}



void setMemWord(int argc,char **argv)

{
  uint32_t uVar1;
  uint32_t uVar2;
  char lengthStr [10];
  uint32_t *address;
  int i;
  int count;
  
  uVar1 = ciGetUnsigned(argv[1]);
  count = 0;
  if ((uVar1 & 3) == 0) {
    for (i = 2; i < argc; i = i + 1) {
      uVar2 = ciGetUnsigned(argv[i]);
      *(uint32_t *)(uVar1 + count * 4) = uVar2;
      count = count + 1;
    }
    siprintf(lengthStr,"%d",count);
    argv[2] = lengthStr;
    getMemWord(3,argv);
  }
  else {
    responsePrintError(*argv,0xff,"Address 0x%.8X is not 32bit aligned",uVar1);
  }
  return;
}



void setTxUnderflow(int argc,char **argv)

{
  uint32_t uVar1;
  undefined enable_00;
  bool bVar2;
  _Bool enable;
  
  uVar1 = ciGetUnsigned(argv[1]);
  bVar2 = uVar1 != 0;
  if (bVar2) {
    uVar1 = 1;
  }
  enable_00 = (undefined)uVar1;
  if (!bVar2) {
    enable_00 = false;
  }
  enableAppMode(TX_UNDERFLOW,(_Bool)enable_00,*argv);
  return;
}



void setRxOverflow(int argc,char **argv)

{
  uint32_t uVar1;
  undefined enable_00;
  bool bVar2;
  _Bool enable;
  
  uVar1 = ciGetUnsigned(argv[1]);
  bVar2 = uVar1 != 0;
  if (bVar2) {
    uVar1 = 1;
  }
  enable_00 = (undefined)uVar1;
  if (!bVar2) {
    enable_00 = false;
  }
  enableAppMode(RX_OVERFLOW,(_Bool)enable_00,*argv);
  return;
}



void setCalibrations(int argc,char **argv)

{
  uint32_t uVar1;
  char cVar2;
  char *pcVar3;
  bool bVar4;
  _Bool enable;
  
  uVar1 = ciGetUnsigned(argv[1]);
  bVar4 = uVar1 != 0;
  if (bVar4) {
    uVar1 = 1;
  }
  cVar2 = (char)uVar1;
  if (!bVar4) {
    cVar2 = '\0';
  }
  skipCalibrations = (_Bool)(cVar2 == '\0');
  if (cVar2 == '\0') {
    pcVar3 = "Disabled";
  }
  else {
    pcVar3 = "Enabled";
  }
  responsePrint(*argv,"Calibrations:%s",pcVar3,pcVar3,argv,argc);
  return;
}



void txCancel(int argc,char **argv)

{
  AppMode_t AVar1;
  undefined enable;
  int32_t iVar2;
  int32_t delay;
  
  txCancelDelay = ciGetSigned(argv[1]);
  iVar2 = txCancelDelay;
  if (txCancelDelay != 0) {
    iVar2 = 1;
  }
  enable = (undefined)iVar2;
  if (txCancelDelay == 0) {
    enable = false;
  }
  enableAppMode(TX_CANCEL,(_Bool)enable,*argv);
  if ((0 < txCancelDelay) && (AVar1 = currentAppMode(), AVar1 == TX_CANCEL)) {
    txCount = 1;
    pendPacketTx();
  }
  return;
}



void getLogLevels(int argc,char **argv)

{
  char *pcVar1;
  char *pcVar2;
  
  if ((logLevel & 1) == 0) {
    pcVar1 = "Disabled";
  }
  else {
    pcVar1 = "Enabled";
  }
  if ((logLevel & 2) == 0) {
    pcVar2 = "Disabled";
  }
  else {
    pcVar2 = "Enabled";
  }
  responsePrint(*argv,"Peripherals:%s,Notifications:%s",pcVar1,pcVar2,argv,argc);
  return;
}



void setPeripheralEnable(int argc,char **argv)

{
  uint32_t uVar1;
  char cVar2;
  bool bVar3;
  _Bool enable;
  
  uVar1 = ciGetUnsigned(argv[1]);
  bVar3 = uVar1 != 0;
  if (bVar3) {
    uVar1 = 1;
  }
  cVar2 = (char)uVar1;
  if (!bVar3) {
    cVar2 = '\0';
  }
  if (cVar2 == '\0') {
    logLevel = logLevel & 0xfe;
  }
  else {
    logLevel = logLevel | 1;
  }
  getLogLevels(1,argv);
  return;
}



void setNotifications(int argc,char **argv)

{
  uint32_t uVar1;
  char cVar2;
  bool bVar3;
  _Bool enable;
  
  uVar1 = ciGetUnsigned(argv[1]);
  bVar3 = uVar1 != 0;
  if (bVar3) {
    uVar1 = 1;
  }
  cVar2 = (char)uVar1;
  if (!bVar3) {
    cVar2 = '\0';
  }
  if (cVar2 == '\0') {
    logLevel = logLevel & 0xfd;
  }
  else {
    logLevel = logLevel | 2;
  }
  getLogLevels(1,argv);
  return;
}



void resetChip(int argc,char **argv)

{
  serialWaitForTxIdle();
  NVIC_SystemReset();
  return;
}



void printDataRates(int argc,char **argv)

{
  uint32_t uVar1;
  uint32_t uVar2;
  char *command;
  
  command = *argv;
  uVar1 = RAIL_SymbolRateGet();
  uVar2 = RAIL_BitRateGet();
  responsePrint(command,"Symbolrate:%d,Bitrate:%d",uVar1,uVar2,argv,argc);
  return;
}



void getRandom(int argc,char **argv)

{
  uint16_t bytes;
  uint16_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  int iVar4;
  bool bVar5;
  int n;
  uint16_t result;
  uint16_t length;
  int i;
  uint16_t offset;
  _Bool hidden;
  
  uVar2 = ciGetUnsigned(argv[1]);
  bytes = (uint16_t)uVar2;
  hidden = false;
  offset = 0;
  if (2 < argc) {
    uVar3 = ciGetUnsigned(argv[2]);
    bVar5 = uVar3 != 0;
    if (bVar5) {
      uVar3 = 1;
    }
    hidden = (_Bool)(char)uVar3;
    if (!bVar5) {
      hidden = false;
    }
  }
  if (bytes < 0x401) {
    uVar1 = RAIL_GetRadioEntropy(randomDataBuffer,bytes);
    if (uVar1 != bytes) {
      responsePrintError(*argv,'\x11',"Error collecting random data.");
    }
    if (hidden == true) {
      responsePrint(*argv,"Length:%u,DataPtr:0x%.8x",(uint)uVar1,randomDataBuffer);
    }
    else {
      for (i = 0; i < (int)(uVar2 & 0xffff); i = i + 1) {
        iVar4 = sniprintf(randomPrintBuffer + offset,0x192 - offset,"%.2x",(uint)randomDataBuffer[i]
                         );
        if (iVar4 < 0) {
          responsePrintError(*argv,'\x12',"Error printing random data.");
          return;
        }
        offset = offset + (short)iVar4;
        if (0x191 < offset) break;
      }
      responsePrint(*argv,"Length:%u,Data:%s",(uint)uVar1,randomPrintBuffer);
    }
  }
  else {
    responsePrintError(*argv,'\x10',"Cannot collect more than %d random bytes.",0x400);
  }
  return;
}



void printDebugSignalHelp
               (char *cmdName,debugPin_t *pins,debugSignal_t *signals,uint32_t numPins,
               uint32_t numSignals)

{
  uint32_t i;
  
  iprintf("%s [pin] [signal] [options]\n",cmdName);
  iprintf("Pins: ");
  for (i = 0; i < numPins; i = i + 1) {
    if (i != 0) {
      iprintf(", ");
    }
    iprintf("%s",pins[i].name);
  }
  puts("\nSignals: ");
  puts("  OFF\n  CUSTOM_PRS <source> <signal>\n  CUSTOM_LIB <event>");
  for (i = 0; i < numSignals; i = i + 1) {
    iprintf("  %s\n",signals[i].name);
  }
  return;
}



void setDebugSignal(int argc,char **argv)

{
  bool bVar1;
  _Bool _Var2;
  debugSignal_t *signals;
  debugPin_t *pins;
  int iVar3;
  uint32_t uVar4;
  uint32_t numPins;
  uint32_t numSignals;
  debugSignal_t customSignal;
  debugPin_t *pinList;
  debugSignal_t *signalList;
  _Bool disablePin;
  uint32_t i;
  debugSignal_t *signal;
  debugPin_t *pin;
  
  pin = (debugPin_t *)0x0;
  signal = (debugSignal_t *)0x0;
  bVar1 = false;
  signals = halGetDebugSignals(&numSignals);
  pins = halGetDebugPins(&numPins);
  if ((argc < 2) || (iVar3 = strcasecmp(argv[1],"help"), iVar3 == 0)) {
    printDebugSignalHelp(*argv,pins,signals,numPins,numSignals);
  }
  else {
    for (i = 0; i < numPins; i = i + 1) {
      iVar3 = strcasecmp(pins[i].name,argv[1]);
      if (iVar3 == 0) {
        pin = pins + i;
      }
    }
    if (pin == (debugPin_t *)0x0) {
      responsePrintError(*argv,'P',"%s is not a valid pin name",argv[1]);
    }
    else {
      iVar3 = strcasecmp("CUSTOM_LIB",argv[2]);
      if (iVar3 == 0) {
        if ((argc != 4) || (_Var2 = ciValidateInteger(argv[3],'w'), _Var2 != true)) {
          responsePrintError(*argv,'Q',"Invalid parameters passed to CUSTOM_LIB");
          return;
        }
        customSignal.name = "CUSTOM_LIB";
        customSignal.isPrs = false;
        uVar4 = ciGetUnsigned(argv[3]);
        customSignal.loc = (undefined2)uVar4;
        signal = &customSignal;
      }
      else {
        iVar3 = strcasecmp("CUSTOM_PRS",argv[2]);
        if (iVar3 == 0) {
          if (argc != 5) {
LAB_00001bf2:
            responsePrintError(*argv,'S',"Invalid parameters passed to CUSTOM_PRS");
            return;
          }
          _Var2 = ciValidateInteger(argv[3],'u');
          if ((_Var2 != true) || (_Var2 = ciValidateInteger(argv[4],'u'), _Var2 != true))
          goto LAB_00001bf2;
          customSignal.name = "CUSTOM_PRS";
          customSignal.isPrs = true;
          uVar4 = ciGetUnsigned(argv[3]);
          customSignal.loc._1_1_ = (undefined)uVar4;
          uVar4 = ciGetUnsigned(argv[4]);
          customSignal.loc = CONCAT11(customSignal.loc._1_1_,(char)uVar4);
          signal = &customSignal;
        }
        else {
          iVar3 = strcasecmp("OFF",argv[2]);
          if (iVar3 == 0) {
            bVar1 = true;
          }
          else {
            for (i = 0; i < numSignals; i = i + 1) {
              iVar3 = strcasecmp(signals[i].name,argv[2]);
              if (iVar3 == 0) {
                signal = signals + i;
              }
            }
            if (signal == (debugSignal_t *)0x0) {
              responsePrintError(*argv,'T',"%s is not a valid signal name",argv[2]);
              return;
            }
          }
        }
      }
      CMU_ClockEnable(cmuClock_GPIO,true);
      GPIO_PinModeSet(pin->gpioPort,(uint)pin->gpioPin,gpioModeDisabled,0);
      if (bVar1) {
        halDisablePrs(pin->prsChannel);
        responsePrint(*argv,"Pin:%s,Signal:OFF",pin->name);
      }
      else {
        if (signal->isPrs != false) {
          halEnablePrs(pin->prsChannel,pin->prsLocation,*(uint8_t *)((int)&signal->loc + 1),
                       *(uint8_t *)&signal->loc);
        }
        GPIO_PinModeSet(pin->gpioPort,(uint)pin->gpioPin,gpioModePushPull,0);
        responsePrint(*argv,"Pin:%s,Signal:%s",pin->name,signal->name);
      }
    }
  }
  return;
}



void startPerMode(int argc,char **argv)

{
  _Bool _Var1;
  uint32_t uVar2;
  uint32_t uVar3;
  undefined enable;
  uint32_t uVar4;
  uint32_t delayUs;
  uint32_t packets;
  
  uVar2 = ciGetUnsigned(argv[1]);
  uVar3 = ciGetUnsigned(argv[2]);
  uVar4 = uVar2;
  if (uVar2 != 0) {
    uVar4 = 1;
  }
  enable = (undefined)uVar4;
  if (uVar2 == 0) {
    enable = false;
  }
  _Var1 = enableAppModeSync(PER,(_Bool)enable,*argv);
  if (_Var1 == true) {
    resetCounters(argc,argv);
    perDelay = uVar3 >> 1;
    perCount = uVar2;
    if (uVar2 != 0) {
      RAIL_TimerSet(perDelay,RAIL_TIME_DELAY);
    }
  }
  return;
}



void updateStats(int32_t newValue,Stats_t *stats)

{
  int iVar1;
  float fVar2;
  float delta;
  
  stats->samples = stats->samples + 1;
  if (stats->samples == 1) {
    stats->min = newValue;
    stats->max = newValue;
    stats->mean = (float)(longlong)newValue;
    stats->varianceTimesSamples = 0.0;
  }
  else {
    iVar1 = stats->min;
    if (newValue <= stats->min) {
      iVar1 = newValue;
    }
    stats->min = iVar1;
    iVar1 = stats->max;
    if (stats->max < newValue) {
      iVar1 = newValue;
    }
    stats->max = iVar1;
    fVar2 = (float)(longlong)newValue - stats->mean;
    stats->mean = stats->mean + fVar2 / (float)(ulonglong)stats->samples;
    stats->varianceTimesSamples =
         stats->varianceTimesSamples + ((float)(longlong)newValue - stats->mean) * fVar2;
  }
  return;
}



float variance(int param_1)

{
  float in_stack_00000000;
  
  return in_stack_00000000 / (float)(ulonglong)(param_1 - 1);
}



void getPerStats(int argc,char **argv)

{
  uint32_t uVar1;
  float fVar2;
  undefined4 uVar3;
  char *command;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  uVar1 = counters.perTriggers;
  command = *argv;
  uVar4 = __aeabi_f2d(counters.rssi.mean / 4.0);
  uVar5 = __aeabi_f2d((float)(longlong)counters.rssi.min / 4.0);
  uVar6 = __aeabi_f2d((float)(longlong)counters.rssi.max / 4.0);
  fVar2 = (float)variance(counters.rssi.samples,counters.rssi.min,counters.rssi.max,
                          counters.rssi.mean,counters.rssi.varianceTimesSamples);
  uVar7 = __aeabi_f2d(fVar2 / 16.0);
  uVar3 = (undefined4)((ulonglong)uVar7 >> 0x20);
  responsePrint(command,"PerTriggers:%u,RssiMean:%f,RssiMin:%.2f,RssiMax:%.2f,RssiVariance:%f",uVar1
                ,uVar3,(int)uVar4,(int)((ulonglong)uVar4 >> 0x20),(int)uVar5,
                (int)((ulonglong)uVar5 >> 0x20),(int)uVar6,(int)((ulonglong)uVar6 >> 0x20),
                (int)uVar7,uVar3);
  return;
}



void berConfigSet(int argc,char **argv)

{
  RAIL_Status_t code;
  uint16_t packetLength;
  uint16_t rxThreshold;
  RAIL_Status_t status;
  
  RAIL_RfIdleExt(1,true);
  RAIL_ResetFifo(true,true);
  railDataConfig.txSource = TX_PACKET_DATA;
  railDataConfig.rxSource = RX_PACKET_DATA;
  railDataConfig.txMethod = FIFO_MODE;
  railDataConfig.rxMethod = FIFO_MODE;
  code = RAIL_DataConfig(&railDataConfig);
  if (code != RAIL_STATUS_NO_ERROR) {
    responsePrintError(*argv,code,"Error calling RAIL_DataConfig().",*argv,argv,argc);
  }
  RAIL_SetRxFifoThreshold(100);
  RAIL_SetFixedLength(0);
  RADIO_PTI_Disable();
  berBytesToTest = ciGetUnsigned(argv[1]);
  berResetStats(berBytesToTest);
  responsePrint(*argv,"NumBytes:%d",berBytesToTest);
  return;
}



void berRx(int argc,char **argv)

{
  _Bool _Var1;
  uint32_t uVar2;
  undefined enable_00;
  bool bVar3;
  _Bool enable;
  
  uVar2 = ciGetUnsigned(argv[1]);
  bVar3 = uVar2 != 0;
  if (bVar3) {
    uVar2 = 1;
  }
  enable_00 = (undefined)uVar2;
  if (!bVar3) {
    enable_00 = false;
  }
  _Var1 = enableAppModeSync(BER,(_Bool)enable_00,*argv);
  if (_Var1 == true) {
    resetCounters(argc,argv);
    RAIL_RfIdleExt(1,true);
    RAIL_ResetFifo(true,true);
    if ((_Bool)enable_00 != false) {
      RADIO_PTI_Disable();
      berResetStats(berBytesToTest);
      berTestModeEnabled = true;
      RAIL_RxStart('\0');
    }
  }
  return;
}



void berStatusGet(int argc,char **argv)

{
  CORE_irqState_t irqState_00;
  char *command;
  undefined8 uVar1;
  undefined8 uVar2;
  RAIL_BerStatus_t berStats;
  int8_t rssi;
  uint32_t bitErrors;
  uint32_t bitsTested;
  uint32_t bitsTotal;
  CORE_irqState_t irqState;
  float percentBitError;
  float percentDone;
  
  irqState_00 = CORE_EnterCritical();
  berGetStats(&berStats);
  CORE_ExitCritical(irqState_00);
  if (berStats.bitsTotal == 0) {
    percentDone = 0.0;
  }
  else {
    uVar1 = __floatunsidf(berStats.bitsTested);
    uVar2 = __floatunsidf(berStats.bitsTotal);
    uVar1 = __divdf3((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),(int)uVar2,
                     (int)((ulonglong)uVar2 >> 0x20));
    uVar1 = __muldf3((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),0,0x40590000);
    percentDone = (float)__truncdfsf2((int)uVar1,(int)((ulonglong)uVar1 >> 0x20));
  }
  if (berStats.bitsTested == 0) {
    percentBitError = 0.0;
  }
  else {
    uVar1 = __floatunsidf(berStats.bitErrors);
    uVar2 = __floatunsidf(berStats.bitsTested);
    uVar1 = __divdf3((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),(int)uVar2,
                     (int)((ulonglong)uVar2 >> 0x20));
    uVar1 = __muldf3((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),0,0x40590000);
    percentBitError = (float)__truncdfsf2((int)uVar1,(int)((ulonglong)uVar1 >> 0x20));
  }
  command = *argv;
  uVar1 = __aeabi_f2d(percentDone);
  uVar2 = __aeabi_f2d(percentBitError);
  responsePrint(command,
                "BitsToTest:%u,BitsTested:%u,PercentDone:%0.2f,RSSI:%d,BitErrors:%u,PercentBitError:%0.2f"
                ,berStats.bitsTotal,berStats.bitsTested,(int)uVar1,(int)((ulonglong)uVar1 >> 0x20),
                (int)berStats.rssi,berStats.bitErrors,(int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
  return;
}



void getStatus(int argc,char **argv)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  uint32_t uVar10;
  uint32_t uVar11;
  uint32_t uVar12;
  uint32_t uVar13;
  uint32_t uVar14;
  uint32_t uVar15;
  uint32_t uVar16;
  AppMode_t appMode;
  RAIL_RadioState_t RVar17;
  char *pcVar18;
  char *command;
  uint uVar19;
  
  uVar16 = counters.lbtStartCca;
  uVar15 = counters.lbtRetry;
  uVar14 = counters.lbtSuccess;
  uVar13 = counters.ackTimeout;
  uVar12 = counters.rfSensedEvent;
  uVar11 = counters.noRxBuffer;
  uVar10 = counters.calibrations;
  uVar9 = counters.rxFail;
  uVar8 = counters.addrFilterEvent;
  uVar7 = counters.txChannelBusy;
  uVar6 = counters.txAbort;
  uVar5 = counters.rxOfEvent;
  uVar4 = counters.frameError;
  uVar3 = counters.syncDetect;
  uVar2 = counters.receive;
  uVar1 = counters.transmit;
  command = *argv;
  uVar19 = (uint)channel;
  appMode = currentAppMode();
  pcVar18 = appModeNames(appMode);
  RVar17 = RAIL_RfStateGet();
  responsePrint(command,
                "TxCount:%u,RxCount:%u,SyncDetect:%u,FrameErrors:%u,RxOverflow:%u,AddrFilt:%u,Aborted:%u,Calibrations:%u,TxAbort:%u,TxChannelBusy:%u,TxClear:%u,TxCca:%u,TxRetry:%u,NoRxBuffer:%u,RfSensed:%u,ackTimeout:%u,Channel:%u,AppMode:%s,RfState:%s"
                ,uVar1,uVar2,uVar3,uVar4,uVar5,uVar8,uVar9,uVar10,uVar6,uVar7,uVar14,uVar16,uVar15,
                uVar11,uVar12,uVar13,uVar19,pcVar18,rfStates[RVar17]);
  return;
}



void fifoStatus(int argc,char **argv)

{
  uint16_t uVar1;
  uint16_t uVar2;
  uint16_t uVar3;
  uint16_t uVar4;
  char *command;
  uint16_t byteCount;
  uint16_t spaceCount;
  
  uVar1 = RAIL_GetTxFifoSpaceAvailable();
  uVar2 = RAIL_GetRxFifoBytesAvailable();
  command = *argv;
  uVar3 = RAIL_GetTxFifoThreshold();
  uVar4 = RAIL_GetRxFifoThreshold();
  responsePrint(command,
                "TxSpaceCount:%u,RxByteCount:%u,TxFifoThreshold:%d,RxFifoThreshold:%d,TxFifoAlmostEmpty:%u,RxFifoAlmostFull:%u,RxOverflow:%u,TxOverflow:%u,RxUnderflow:%u,TxUnderflow:%u"
                ,(uint)uVar1,(uint)uVar2,(uint)uVar3,(uint)uVar4,counters.txFifoAlmostEmpty,
                counters.rxFifoAlmostFull,counters.rxOfEvent,counters.txOfEvent,counters.rxUfEvent,
                counters.txUfEvent);
  return;
}



void getVersion(int argc,char **argv)

{
  RAIL_Version_t rail_ver;
  
  RAIL_VersionGet(&rail_ver,false);
  responsePrint(*argv,"App:%d.%d.%d,RAIL:%d.%d.%d",(uint)rail_ver.major,(uint)rail_ver.minor,
                (uint)rail_ver.rev,(uint)rail_ver.major,(uint)rail_ver.minor,(uint)rail_ver.rev,argv
                ,argc);
  return;
}



void setPtiProtocol(int argc,char **argv)

{
  RAIL_Status_t RVar1;
  uint32_t uVar2;
  char *pcVar3;
  RAIL_Status_t status;
  
  uVar2 = ciGetUnsigned(argv[1]);
  RVar1 = RAIL_SetPtiProtocol((RAIL_PtiProtocol_t)uVar2);
  if (RVar1 == RAIL_STATUS_NO_ERROR) {
    pcVar3 = "Set";
  }
  else {
    pcVar3 = "Error";
  }
  responsePrint(*argv,"Pti:%s",pcVar3,pcVar3,argv,argc);
  return;
}



void getVersionVerbose(int argc,char **argv)

{
  RAIL_Version_t rail_ver;
  
  RAIL_VersionGet(&rail_ver,true);
  responsePrint(*argv,"App:%d.%d.%d,RAIL:%d.%d.%d.%d",(uint)rail_ver.major,(uint)rail_ver.minor,
                (uint)rail_ver.rev,(uint)rail_ver.major,(uint)rail_ver.minor,(uint)rail_ver.rev,
                (uint)rail_ver.build);
  responsePrint(*argv,"hash:0x%.8X,flags:0x%.2X",rail_ver.hash,(uint)rail_ver.flags);
  return;
}



void getRssi(int argc,char **argv)

{
  int16_t iVar1;
  char *command;
  undefined8 uVar2;
  int16_t rssi;
  uint32_t averageTimeUs;
  
  if (argc == 2) {
    averageTimeUs = ciGetUnsigned(argv[1]);
  }
  else {
    averageTimeUs = 0;
  }
  iVar1 = RAIL_PollAverageRSSI(averageTimeUs);
  if (iVar1 == -0x200) {
    responsePrintError(*argv,'\b',"Could not read RSSI. Ensure Rx is enabled");
  }
  else {
    command = *argv;
    uVar2 = __aeabi_f2d((float)(longlong)(int)iVar1 / 4.0);
    responsePrint(command,"rssi:%.2f",(int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
  }
  return;
}



void startAvgRssi(int argc,char **argv)

{
  _Bool _Var1;
  RAIL_Status_t RVar2;
  uint32_t averagingTimeUs;
  uint32_t averageTimeUs;
  
  averagingTimeUs = ciGetUnsigned(argv[1]);
  _Var1 = inRadioState(RAIL_RF_STATE_IDLE,(char *)0x0);
  if (_Var1 == true) {
    RVar2 = RAIL_StartAverageRSSI(channel,averagingTimeUs);
    if (RVar2 != RAIL_STATUS_NO_ERROR) {
      responsePrintError(*argv,'\b',"Could not read RSSI.",*argv,argv,argc);
    }
  }
  else {
    responsePrintError(*argv,'\b',"Could not read RSSI. Ensure RX is disabled.",*argv,argv,argc);
  }
  return;
}



void getAvgRssi(int argc,char **argv)

{
  int16_t iVar1;
  char *command;
  undefined8 uVar2;
  int16_t rssi;
  
  iVar1 = RAIL_GetAverageRSSI();
  if (iVar1 == -0x200) {
    responsePrintError(*argv,'\b',"Invalid RSSI. Make sure startAvgRssi ran successfully.");
  }
  else {
    command = *argv;
    uVar2 = __aeabi_f2d((float)(longlong)(int)iVar1 / 4.0);
    responsePrint(command,"rssi:%.2f",(int)uVar2,(int)((ulonglong)uVar2 >> 0x20),argv,argc);
  }
  return;
}



void sweepPower(int argc,char **argv)

{
  uint8_t uVar1;
  uint32_t powerLevel;
  uint32_t powerLevel_00;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t expired;
  int32_t halfPeriodStepUs;
  int32_t period;
  int32_t hiPower;
  int32_t lowPower;
  
  powerLevel = ciGetUnsigned(argv[1]);
  powerLevel_00 = ciGetUnsigned(argv[2]);
  uVar2 = ciGetUnsigned(argv[3]);
  uVar3 = RAIL_GetTime();
  while (uVar4 = RAIL_GetTime(), uVar4 < uVar3 + 5000000) {
    uVar1 = RAIL_TxToneStop();
    RAIL_RfIdle(uVar1);
    RAIL_TxPowerSet(powerLevel);
    RAIL_TxToneStart(channel);
    usDelay((int)uVar2 / 2);
    uVar1 = RAIL_TxToneStop();
    RAIL_RfIdle(uVar1);
    RAIL_TxPowerSet(powerLevel_00);
    RAIL_TxToneStart(channel);
    usDelay((int)uVar2 / 2);
  }
  RAIL_TxToneStop();
  return;
}



void resetCounters(int argc,char **argv)

{
  memset(&counters,0,0x70);
  getStatus(1,argv);
  return;
}



void getTime(int argc,char **argv)

{
  uint32_t uVar1;
  char *command;
  
  command = *argv;
  uVar1 = RAIL_GetTime();
  responsePrint(command,"Time:%u",uVar1,uVar1,argv,argc);
  return;
}



void setTime(int argc,char **argv)

{
  RAIL_Status_t RVar1;
  uint32_t time;
  uint32_t uVar2;
  char *pcVar3;
  uint32_t timeUs;
  
  time = ciGetUnsigned(argv[1]);
  RVar1 = RAIL_SetTime(time);
  if (RVar1 == RAIL_STATUS_NO_ERROR) {
    pcVar3 = *argv;
    uVar2 = RAIL_GetTime();
    responsePrint(pcVar3,"Status:Success,CurrentTime:%u",uVar2,uVar2,argv,argc);
  }
  else {
    pcVar3 = *argv;
    uVar2 = RAIL_GetTime();
    responsePrint(pcVar3,"Status:Error,CurrentTime:%u",uVar2,uVar2,argv,argc);
  }
  return;
}



void setLbtMode(int argc,char **argv)

{
  int iVar1;
  
  if (1 < argc) {
    iVar1 = memcmp(argv[1],&DAT_00017de8,3);
    if (iVar1 == 0) {
      txPreTxOp = FUN_00000000;
      txPreTxOpArgs = (void *)0x0;
    }
    else {
      iVar1 = memcmp(argv[1],&DAT_00017dec,4);
      if (iVar1 == 0) {
        txPreTxOp = RAIL_CcaCsma + 1;
        txPreTxOpArgs = &lbtParams;
      }
      else {
        iVar1 = memcmp(argv[1],&DAT_00017df4,3);
        if (iVar1 != 0) {
          responsePrintError(*argv,'p',"Unknown LBT mode specified.");
          return;
        }
        txPreTxOp = RAIL_CcaLbt + 1;
        txPreTxOpArgs = &lbtParams;
      }
    }
  }
  if (txPreTxOp == FUN_00000000) {
    responsePrint(*argv,"LbtMode:off");
  }
  else {
    if (txPreTxOp == RAIL_CcaCsma + 1) {
      responsePrint(*argv,"LbtMode:CSMA");
    }
    else {
      if (txPreTxOp == RAIL_CcaLbt + 1) {
        responsePrint(*argv,"LbtMode:LBT");
      }
    }
  }
  return;
}



void getLbtParams(int argc,char **argv)

{
  responsePrint(*argv,"MinBo:%u,MaxBo:%u,Tries:%u,Threshold:%d,Backoff:%u,Duration:%u,Timeout:%u",
                (uint)lbtParams.lbtMinBoRand,(uint)lbtParams.lbtMaxBoRand,(uint)lbtParams.lbtTries,
                (int)lbtParams.lbtThreshold,(uint)lbtParams.lbtBackoff,(uint)lbtParams.lbtDuration,
                lbtParams.lbtTimeout);
  return;
}



void setLbtParams(int argc,char **argv)

{
  uint32_t uVar1;
  int32_t iVar2;
  
  uVar1 = ciGetUnsigned(argv[1]);
  lbtParams.lbtMinBoRand = (uint8_t)uVar1;
  uVar1 = ciGetUnsigned(argv[2]);
  lbtParams.lbtMaxBoRand = (uint8_t)uVar1;
  uVar1 = ciGetUnsigned(argv[3]);
  lbtParams.lbtTries = (uint8_t)uVar1;
  iVar2 = ciGetSigned(argv[4]);
  lbtParams.lbtThreshold = (int8_t)iVar2;
  uVar1 = ciGetUnsigned(argv[5]);
  lbtParams.lbtBackoff = (uint16_t)uVar1;
  uVar1 = ciGetUnsigned(argv[6]);
  lbtParams.lbtDuration = (uint16_t)uVar1;
  lbtParams.lbtTimeout = ciGetUnsigned(argv[7]);
  getLbtParams(1,argv);
  return;
}



void printTxPacket(int argc,char **argv)

{
  printPacket(*argv,transmitPayload.dataPtr,transmitPayload.dataLength,(RAIL_RxPacketInfo_t *)0x0);
  return;
}



void setTxPayload(int argc,char **argv)

{
  uint32_t uVar1;
  uint32_t uVar2;
  int iVar3;
  uint8_t value;
  uint32_t index;
  uint16_t offset;
  int i;
  
  uVar1 = ciGetUnsigned(argv[1]);
  i = 2;
  while( true ) {
    if (argc <= i) {
      transmitPayload.dataPtr = txData;
      if (railDataConfig.txMethod == PACKET_MODE) {
        RAIL_TxDataLoad(&transmitPayload);
      }
      printTxPacket(1,argv);
      return;
    }
    iVar3 = i + (uVar1 & 0xffff);
    uVar2 = ciGetUnsigned(argv[i]);
    if (0xef < iVar3 - 2U) break;
    *(char *)((int)&commands[0x79].helpStr + iVar3 + 2) = (char)uVar2;
    i = i + 1;
  }
  responsePrintError(*argv,'\x05',"Data overflows txData buffer");
  return;
}



void setTxLength(int argc,char **argv)

{
  uint32_t uVar1;
  uint32_t length;
  
  uVar1 = ciGetUnsigned(argv[1]);
  if (uVar1 < 0xf1) {
    transmitPayload.dataPtr = txData;
    transmitPayload.dataLength = (uint16_t)uVar1;
    if (railDataConfig.txMethod == PACKET_MODE) {
      RAIL_TxDataLoad(&transmitPayload);
    }
    responsePrint(*argv,"TxLength:%d",(uint)transmitPayload.dataLength,
                  (uint)transmitPayload.dataLength,argv,argc);
  }
  else {
    responsePrintError(*argv,'\x06',"Invalid length %d",uVar1);
  }
  return;
}



void printAckPacket(int argc,char **argv)

{
  printPacket(*argv,ackPayload.dataPtr,(ushort)ackPayload.dataLength,(RAIL_RxPacketInfo_t *)0x0);
  return;
}



void setAckPayload(int argc,char **argv)

{
  uint32_t uVar1;
  uint32_t uVar2;
  int iVar3;
  uint8_t value;
  uint32_t index;
  uint16_t offset;
  int i;
  
  uVar1 = ciGetUnsigned(argv[1]);
  i = 2;
  while( true ) {
    if (argc <= i) {
      ackPayload.dataPtr = ackData;
      RAIL_AutoAckLoadBuffer(&ackPayload);
      printAckPacket(1,argv);
      return;
    }
    iVar3 = i + (uVar1 & 0xffff);
    uVar2 = ciGetUnsigned(argv[i]);
    if (0x3f < iVar3 - 2U) break;
    *(char *)(&transmitPayload.field_0x6 + iVar3) = (char)uVar2;
    i = i + 1;
  }
  responsePrintError(*argv,'\x05',"Data overflows ackData buffer");
  return;
}



void setAckLength(int argc,char **argv)

{
  uint32_t uVar1;
  uint32_t length;
  
  uVar1 = ciGetUnsigned(argv[1]);
  if (uVar1 < 0x41) {
    ackPayload.dataPtr = ackData;
    ackPayload.dataLength = (uint8_t)uVar1;
    RAIL_AutoAckLoadBuffer(&ackPayload);
    responsePrint(*argv,"TxLength:%d",(uint)ackPayload.dataLength,(uint)ackPayload.dataLength,argv,
                  argc);
  }
  else {
    responsePrintError(*argv,'\x06',"Invalid length %d",uVar1);
  }
  return;
}



void setFixedLength(int argc,char **argv)

{
  _Bool _Var1;
  uint16_t rxLength;
  uint32_t uVar2;
  uint16_t fixedLength;
  
  _Var1 = inAppMode(NONE,*argv);
  if ((_Var1 == true) && (_Var1 = inRadioState(RAIL_RF_STATE_IDLE,*argv), _Var1 == true)) {
    uVar2 = ciGetUnsigned(argv[1]);
    rxLength = RAIL_SetFixedLength((uint16_t)uVar2);
    configRxLengthSetting(rxLength);
    responsePrint(*argv,"FixedLength:%d",(uint)rxLength);
  }
  return;
}



void dataConfig(int argc,char **argv)

{
  _Bool _Var1;
  RAIL_Status_t RVar2;
  int iVar3;
  RAIL_Status_t status;
  
  _Var1 = inAppMode(NONE,*argv);
  if ((_Var1 == true) && (_Var1 = inRadioState(RAIL_RF_STATE_IDLE,*argv), _Var1 == true)) {
    railDataConfig.txSource = TX_PACKET_DATA;
    railDataConfig.rxSource = RX_PACKET_DATA;
    iVar3 = memcmp(argv[1],&DAT_00017ef8,3);
    if (iVar3 == 0) {
      railDataConfig.txMethod = PACKET_MODE;
    }
    else {
      iVar3 = memcmp(argv[1],&DAT_00017efc,4);
      if (iVar3 == 0) {
        railDataConfig.txMethod = FIFO_MODE;
      }
      else {
        responsePrintError(*argv,'P',"Invalid Data Method selection.",*argv,argv,argc);
      }
    }
    iVar3 = memcmp(argv[2],&DAT_00017ef8,3);
    if (iVar3 == 0) {
      railDataConfig.rxMethod = PACKET_MODE;
    }
    else {
      iVar3 = memcmp(argv[2],&DAT_00017efc,4);
      if (iVar3 == 0) {
        railDataConfig.rxMethod = FIFO_MODE;
      }
      else {
        responsePrintError(*argv,'P',"Invalid Data Method selection.");
      }
    }
    RVar2 = RAIL_DataConfig(&railDataConfig);
    if (RVar2 == RAIL_STATUS_NO_ERROR) {
      responsePrint(*argv,"TxMethod:%s,RxMethod:%s",argv[1],argv[2]);
    }
    else {
      responsePrintError(*argv,'P',"Failed to successfully call RAIL_DataConfig: %d",(uint)RVar2);
    }
  }
  return;
}



void fifoModeTestOptions(int argc,char **argv)

{
  uint32_t uVar1;
  bool bVar2;
  char *outputStr [2];
  
  outputStr[0] = "Disabled";
  outputStr[1] = "Enabled";
  uVar1 = ciGetUnsigned(argv[1]);
  bVar2 = uVar1 != 0;
  if (bVar2) {
    uVar1 = 1;
  }
  txFifoManual = (_Bool)(char)uVar1;
  if (!bVar2) {
    txFifoManual = false;
  }
  uVar1 = ciGetUnsigned(argv[2]);
  bVar2 = uVar1 != 0;
  if (bVar2) {
    uVar1 = 1;
  }
  rxFifoManual = (_Bool)(byte)uVar1;
  if (!bVar2) {
    rxFifoManual = false;
  }
  responsePrint(*argv,"TxFifoManual:%s,RxFifoManual:%s",outputStr[txFifoManual],
                outputStr[rxFifoManual],argv,argc);
  return;
}



void rxFifoManualRead(int argc,char **argv)

{
  uint16_t uVar1;
  uint32_t uVar2;
  void *handle;
  RAIL_AppendedInfo_t *appendedInfo;
  char cVar3;
  bool bVar4;
  RAIL_RxPacketInfo_t *packetInfo;
  void *packetHandle;
  uint16_t bytesToRead;
  _Bool readAppendedInfo;
  
  if (rxFifoManual == true) {
    uVar2 = ciGetUnsigned(argv[1]);
    bVar4 = uVar2 != 0;
    if (bVar4) {
      uVar2 = 1;
    }
    cVar3 = (char)uVar2;
    if (!bVar4) {
      cVar3 = '\0';
    }
    uVar2 = ciGetUnsigned(argv[2]);
    handle = memoryAllocate(uVar2 & 0xffff);
    appendedInfo = (RAIL_AppendedInfo_t *)memoryPtrFromHandle(handle);
    uVar1 = RAIL_ReadRxFifo((uint8_t *)((int)&appendedInfo[1].timeUs + 2),(uint16_t)uVar2);
    *(uint16_t *)&appendedInfo[1].timeUs = uVar1;
    if (cVar3 != '\0') {
      RAIL_ReadRxFifoAppendedInfo(appendedInfo);
    }
    queueAdd(&rxPacketQueue,handle);
  }
  else {
    responsePrintError(*argv,'Q',"Must be in rx fifo manual mode (fifoModeTestOptions).",*argv,argv,
                       argc);
  }
  return;
}



void fifoReset(int argc,char **argv)

{
  uint32_t uVar1;
  undefined txFifo;
  undefined rxFifo;
  bool bVar2;
  char *outputStr [2];
  _Bool rxReset;
  _Bool txReset;
  
  outputStr[0] = "DoNothing";
  outputStr[1] = "Reset";
  uVar1 = ciGetUnsigned(argv[1]);
  bVar2 = uVar1 != 0;
  if (bVar2) {
    uVar1 = 1;
  }
  txFifo = (undefined)uVar1;
  if (!bVar2) {
    txFifo = false;
  }
  uVar1 = ciGetUnsigned(argv[2]);
  bVar2 = uVar1 != 0;
  if (bVar2) {
    uVar1 = 1;
  }
  rxFifo = (undefined)uVar1;
  if (!bVar2) {
    rxFifo = false;
  }
  RAIL_ResetFifo((bool)txFifo,(bool)rxFifo);
  responsePrint(*argv,"TxFifo:%s,RxFifo:%s",outputStr[(byte)txFifo],outputStr[(byte)rxFifo],argv,
                argc);
  return;
}



void txFifoManualLoad(int argc,char **argv)

{
  if (txFifoManual == true) {
    loadTxData(&transmitPayload);
    responsePrint(*argv,"Status:Fifo Written");
  }
  else {
    responsePrintError(*argv,'Q',"Must be in tx fifo manual mode (fifoModeTestOptions).",*argv,argv,
                       argc);
  }
  return;
}



void abortRxPacket(int argc,char **argv)

{
  abortRxDelay = ciGetUnsigned(argv[1]);
  responsePrint(*argv,"TimeAfterSyncToAbort:%d",abortRxDelay,abortRxDelay,argv,argc);
  return;
}



void getChannel(int argc,char **argv)

{
  uint32_t uVar1;
  
  uVar1 = RAIL_DebugModeGet();
  if ((uVar1 & 1) == 0) {
    responsePrint(*argv,"channel:%d",(uint)channel,(uint)channel,argv,argc);
  }
  else {
    responsePrintError(*argv,'\x12',"Channels are not valid in Debug Mode");
  }
  return;
}



void setChannel(int argc,char **argv)

{
  _Bool _Var1;
  RAIL_Status_t RVar2;
  uint32_t i;
  int proposedChannel;
  _Bool success;
  
  _Var1 = inRadioState(RAIL_RF_STATE_IDLE,*argv);
  if (_Var1 == true) {
    i = ciGetUnsigned(argv[1]);
    RVar2 = RAIL_ChannelExists((uint8_t)i);
    if (RVar2 == RAIL_STATUS_NO_ERROR) {
      changeChannel(i);
      getChannel(1,argv);
    }
    else {
      responsePrintError(*argv,'\x11',"Invalid channel \'%d\'",i,argv,argc);
    }
  }
  return;
}



void getPower(int argc,char **argv)

{
  int32_t iVar1;
  char *command;
  
  command = *argv;
  iVar1 = RAIL_TxPowerGet();
  responsePrint(command,"power:%d",iVar1,iVar1,argv,argc);
  return;
}



void setPower(int argc,char **argv)

{
  _Bool _Var1;
  int32_t powerLevel;
  int32_t iVar2;
  int32_t power;
  
  _Var1 = inRadioState(RAIL_RF_STATE_IDLE,*argv);
  if (_Var1 == true) {
    powerLevel = ciGetSigned(argv[1]);
    iVar2 = RAIL_TxPowerSet(powerLevel);
    responsePrint(*argv,"power:%d",iVar2,*argv,argv,argc);
  }
  return;
}



void getTxDelay(int argc,char **argv)

{
  responsePrint(*argv,"txDelay:%d",continuousTransferPeriod,continuousTransferPeriod,argv,argc);
  return;
}



void setTxDelay(int argc,char **argv)

{
  uint32_t delay;
  
  continuousTransferPeriod = ciGetUnsigned(argv[1]);
  getTxDelay(1,argv);
  return;
}



void getCtune(int argc,char **argv)

{
  uint32_t uVar1;
  uint32_t ctune;
  
  uVar1 = RAIL_GetTune();
  responsePrint(*argv,"CTUNE:0x%.3x",uVar1,*argv,argv,argc);
  return;
}



void setCtune(int argc,char **argv)

{
  _Bool _Var1;
  uint32_t tune;
  
  _Var1 = inRadioState(RAIL_RF_STATE_IDLE,*argv);
  if (_Var1 == true) {
    tune = ciGetUnsigned(argv[1]);
    RAIL_SetTune(tune);
    getCtune(1,argv);
  }
  return;
}



void setPaCtune(int argc,char **argv)

{
  RAIL_Status_t code;
  uint32_t uVar1;
  uint32_t uVar2;
  RAIL_Status_t status;
  uint8_t rxVal;
  uint8_t txVal;
  
  uVar1 = ciGetUnsigned(argv[1]);
  uVar2 = ciGetUnsigned(argv[2]);
  code = RAIL_PaCtuneSet((uint8_t)uVar1,(uint8_t)uVar2);
  if (code == RAIL_STATUS_NO_ERROR) {
    responsePrint(*argv,"PACTUNETX:%d,PACTUNERX:%d",uVar1 & 0xff,uVar2 & 0xff);
  }
  else {
    responsePrintError(*argv,code,"Error",*argv,argv,argc);
  }
  return;
}



void getConfig(int argc,char **argv)

{
  responsePrint(*argv,"Index:%u,Config:%s",currentConfig,configNames[currentConfig],argv,argc);
  return;
}



void listConfigs(int argc,char **argv)

{
  int i;
  
  responsePrintHeader(*argv,"Index:%u,Config:%s");
  for (i = 0; i < 1; i = i + 1) {
    responsePrintMulti("Index:%u,Config:%s",i,configNames[i],configNames[i],argv,argc);
  }
  return;
}



void setConfig(int argc,char **argv)

{
  _Bool _Var1;
  uint32_t newConfig;
  int newIndex;
  
  _Var1 = inRadioState(RAIL_RF_STATE_IDLE,*argv);
  if (_Var1 == true) {
    newConfig = ciGetUnsigned(argv[1]);
    if ((int)newConfig < 1) {
      changeRadioConfig(newConfig);
      getConfig(1,argv);
      getChannel(1,argv);
    }
    else {
      responsePrintError(*argv,'\b',"Invalid index %u",newConfig,argv,argc);
    }
  }
  return;
}



int8_t stringsToStates(char **strings,RAIL_RadioState_t *states)

{
  int i;
  
  for (i = 0; i < 2; i = i + 1) {
    switch(*strings[i]) {
    case 'I':
    case 'i':
      states[i] = RAIL_RF_STATE_IDLE;
      break;
    default:
      return '\x01';
    case 'R':
    case 'r':
      states[i] = RAIL_RF_STATE_RX;
      break;
    case 'T':
    case 't':
      states[i] = RAIL_RF_STATE_TX;
    }
  }
  return '\0';
}



void setTxTransitions(int argc,char **argv)

{
  int8_t iVar1;
  RAIL_Status_t RVar2;
  char *pcVar3;
  RAIL_RadioState_t states [2];
  RAIL_Status_t ret;
  
  iVar1 = stringsToStates(argv + 1,states);
  if (iVar1 == '\0') {
    RVar2 = RAIL_SetTxTransitions(states[0],states[1]);
    if (RVar2 == RAIL_STATUS_NO_ERROR) {
      pcVar3 = "Set";
    }
    else {
      pcVar3 = "Error";
    }
    responsePrint(*argv,"TxTransitions:%s",pcVar3,pcVar3,argv,argc);
  }
  else {
    responsePrintError(*argv,'\x16',"Invalid states");
  }
  return;
}



void setRxTransitions(int argc,char **argv)

{
  int8_t iVar1;
  RAIL_Status_t RVar2;
  uint32_t uVar3;
  char *pcVar4;
  RAIL_RadioState_t states [2];
  RAIL_Status_t ret;
  uint8_t ignoreErrors;
  
  iVar1 = stringsToStates(argv + 1,states);
  if (iVar1 == '\0') {
    uVar3 = ciGetUnsigned(argv[3]);
    RVar2 = RAIL_SetRxTransitions(states[0],states[1],(uint8_t)uVar3);
    if (RVar2 == RAIL_STATUS_NO_ERROR) {
      pcVar4 = "Set";
    }
    else {
      pcVar4 = "Error";
    }
    responsePrint(*argv,"RxTransitions:%s",pcVar4,pcVar4,argv,argc);
  }
  else {
    responsePrintError(*argv,'\x16',"Invalid states");
  }
  return;
}



void setTimings(int argc,char **argv)

{
  RAIL_Status_t RVar1;
  uint32_t uVar2;
  RAIL_StateTiming_t timings;
  uint16_t timing [4];
  int i;
  
  for (i = 1; i < 5; i = i + 1) {
    uVar2 = ciGetUnsigned(argv[i]);
    timing[i + -1] = (uint16_t)uVar2;
  }
  timings.idleToRx = timing[0];
  timings.txToRx = timing[1];
  timings.idleToTx = timing[2];
  timings.rxToTx = timing[3];
  RVar1 = RAIL_SetStateTiming(&timings);
  if (RVar1 == RAIL_STATUS_NO_ERROR) {
    responsePrint(*argv,"IdleToRx:%u,RxToTx:%u,IdleToTx:%u,TxToRx:%u",(uint)timings.idleToRx,
                  (uint)timings.rxToTx,(uint)timings.idleToTx,(uint)timings.txToRx,argv,argc);
  }
  else {
    responsePrintError(*argv,'\x18',"Setting timings failed");
  }
  return;
}



void setTxFifoThreshold(int argc,char **argv)

{
  uint16_t uVar1;
  uint32_t uVar2;
  uint16_t txFifoThreshold;
  
  if (railDataConfig.txMethod == FIFO_MODE) {
    uVar2 = ciGetUnsigned(argv[1]);
    uVar1 = RAIL_SetTxFifoThreshold((uint16_t)uVar2);
    responsePrint(*argv,"TxFifoThreshold:%d",(uint)uVar1);
  }
  else {
    responsePrintError(*argv,'\x19',"Tx is not in FIFO mode",*argv,argv,argc);
  }
  return;
}



void setRxFifoThreshold(int argc,char **argv)

{
  uint16_t uVar1;
  uint32_t uVar2;
  uint16_t rxFifoThreshold;
  
  if (railDataConfig.rxMethod == FIFO_MODE) {
    uVar2 = ciGetUnsigned(argv[1]);
    uVar1 = RAIL_SetRxFifoThreshold((uint16_t)uVar2);
    responsePrint(*argv,"RxFifoThreshold:%d",(uint)uVar1);
  }
  else {
    responsePrintError(*argv,'\x19',"Rx is not in FIFO mode",*argv,argv,argc);
  }
  return;
}



void setTimer(int argc,char **argv)

{
  _Bool _Var1;
  RAIL_Status_t RVar2;
  uint32_t time;
  int iVar3;
  uint32_t timeOut;
  RAIL_TimeMode_t mode;
  
  _Var1 = inAppMode(NONE,*argv);
  if (_Var1 == true) {
    time = ciGetUnsigned(argv[1]);
    iVar3 = strcmp(argv[2],"abs");
    RAIL_TimerCancel();
    RVar2 = RAIL_TimerSet(time,iVar3 != 0);
    if (RVar2 == RAIL_STATUS_NO_ERROR) {
      printTimerStats(1,argv);
    }
    else {
      responsePrintError(*argv,'@',"TimerSet failed");
    }
  }
  return;
}



void printTimerStats(int argc,char **argv)

{
  bool bVar1;
  bool bVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  char *pcVar5;
  char *pcVar6;
  uint32_t currentTime;
  uint32_t expirationTime;
  _Bool expired;
  _Bool enabled;
  
  bVar1 = RAIL_TimerIsRunning();
  bVar2 = RAIL_TimerExpired();
  uVar3 = RAIL_TimerGet();
  uVar4 = RAIL_GetTime();
  if (bVar1 == false) {
    pcVar6 = "False";
  }
  else {
    pcVar6 = "True";
  }
  if (bVar2 == false) {
    pcVar5 = "False";
  }
  else {
    pcVar5 = "True";
  }
  responsePrint(*argv,"timeUs:%u,ExpirationTime:%u,IsRunning:%s,IsExpired:%s",uVar4,uVar3,pcVar6,
                pcVar5,argv,argc);
  return;
}



void timerCancel(int argc,char **argv)

{
  _Bool _Var1;
  
  _Var1 = inAppMode(NONE,*argv);
  if (_Var1 != false) {
    RAIL_TimerCancel();
    printTimerStats(1,argv);
  }
  return;
}



void GPIO_EM4SetPinRetention(_Bool enable)

{
  uint uVar1;
  
  if (enable == false) {
    uVar1 = (EMU->EM4CTRL);
    write_volatile_4(EMU->EM4CTRL,uVar1 & 0xffffffcf);
  }
  else {
    uVar1 = (EMU->EM4CTRL);
    write_volatile_4(EMU->EM4CTRL,uVar1 & 0xffffffcf | 0x10);
  }
  return;
}



void GPIO_IntConfig(GPIO_Port_TypeDef port,uint pin,_Bool risingEdge,_Bool fallingEdge,_Bool enable)

{
  GPIO_ExtIntConfig(port,pin,pin,risingEdge,fallingEdge,enable);
  return;
}



void tx(int argc,char **argv)

{
  uint32_t iterations;
  uint32_t newTxCount;
  
  iterations = ciGetUnsigned(argv[1]);
  radioTransmit(iterations,*argv);
  txOptionsPtr = (RAIL_TxOptions_t *)0x0;
  return;
}



void txWithOptions(int argc,char **argv)

{
  uint32_t iterations;
  uint32_t newTxCount;
  
  iterations = ciGetUnsigned(argv[1]);
  radioTransmit(iterations,*argv);
  txOptionsPtr = &txOptions;
  return;
}



void configTxOptions(int argc,char **argv)

{
  uint32_t uVar1;
  char *pcVar2;
  uint8_t waitForAck;
  
  uVar1 = ciGetUnsigned(argv[1]);
  txOptions = (_Bool)((char)uVar1 != '\0');
  txOptionsPtr = &txOptions;
  if ((bool)txOptions) {
    pcVar2 = "True";
  }
  else {
    pcVar2 = "False";
  }
  responsePrint(*argv,"waitForAck:%s",pcVar2,pcVar2,argv,argc);
  return;
}



void txAtTime(int argc,char **argv)

{
  _Bool _Var1;
  RAIL_TimeMode_t mode;
  uint32_t txTime;
  _Bool isAbs;
  
  isAbs = true;
  txTime = ciGetUnsigned(argv[1]);
  if (2 < argc) {
    _Var1 = parseTimeModeFromString(argv[2],&mode);
    if (_Var1 != true) {
      responsePrintError(*argv,'\x1c',"Invalid time mode");
      return;
    }
    if (mode == RAIL_TIME_DELAY) {
      isAbs = false;
    }
    else {
      if (mode != RAIL_TIME_ABSOLUTE) {
        responsePrintError(*argv,'\x1c',"Invalid time mode");
        return;
      }
      isAbs = true;
    }
  }
  setNextPacketTime(txTime,isAbs);
  setNextAppMode(TX_SCHEDULED,*argv);
  return;
}



void txAfterRx(int argc,char **argv)

{
  undefined enable;
  uint32_t uVar1;
  uint32_t delay;
  
  txAfterRxDelay = ciGetUnsigned(argv[1]);
  uVar1 = txAfterRxDelay;
  if (txAfterRxDelay != 0) {
    uVar1 = 1;
  }
  enable = (undefined)uVar1;
  if (txAfterRxDelay == 0) {
    enable = false;
  }
  enableAppMode(SCHTX_AFTER_RX,(_Bool)enable,*argv);
  return;
}



void rxConfig(int argc,char **argv)

{
  _Bool _Var1;
  uint32_t uVar2;
  undefined appendedInfoEnable;
  bool bVar3;
  _Bool appendedInfo;
  
  _Var1 = inAppMode(NONE,*argv);
  if ((_Var1 == true) && (_Var1 = inRadioState(RAIL_RF_STATE_IDLE,*argv), _Var1 == true)) {
    uVar2 = ciGetUnsigned(argv[1]);
    bVar3 = uVar2 != 0;
    if (bVar3) {
      uVar2 = 1;
    }
    appendedInfoEnable = (undefined)uVar2;
    if (!bVar3) {
      appendedInfoEnable = false;
    }
    RAIL_RxConfig(0x674,(bool)appendedInfoEnable);
  }
  return;
}



void rx(int argc,char **argv)

{
  AppMode_t AVar1;
  _Bool _Var2;
  RAIL_RadioState_t RVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  char cVar6;
  char *command;
  char *pcVar7;
  char *pcVar8;
  bool bVar9;
  _Bool enable;
  
  uVar4 = ciGetUnsigned(argv[1]);
  bVar9 = uVar4 != 0;
  if (bVar9) {
    uVar4 = 1;
  }
  cVar6 = (char)uVar4;
  if (!bVar9) {
    cVar6 = '\0';
  }
  AVar1 = currentAppMode();
  if ((AVar1 == RX_SCHEDULED) && (cVar6 != '\0')) {
    responsePrintError(*argv,'\x1d',"Can\'t turn on receive when in ScheduledRx");
    return;
  }
  AVar1 = currentAppMode();
  if (((AVar1 != DIRECT) && (AVar1 = currentAppMode(), AVar1 != RX_SCHEDULED)) &&
     (_Var2 = inAppMode(NONE,*argv), _Var2 != true)) {
    return;
  }
  if (((cVar6 == '\0') || (RVar3 = RAIL_RfStateGet(), RVar3 != RAIL_RF_STATE_RX)) &&
     ((cVar6 == '\x01' || (RVar3 = RAIL_RfStateGet(), RVar3 != RAIL_RF_STATE_IDLE)))) {
    if ((cVar6 == '\0') || (_Var2 = inRadioState(RAIL_RF_STATE_IDLE,*argv), _Var2 == false)) {
      if (cVar6 != '\x01') {
        RAIL_RfIdle();
        receiveModeEnabled = (_Bool)cVar6;
        AVar1 = currentAppMode();
        if (AVar1 == RX_SCHEDULED) {
          enableAppModeSync(RX_SCHEDULED,false,(char *)0x0);
        }
      }
    }
    else {
      RAIL_RxStart(channel);
      receiveModeEnabled = (_Bool)cVar6;
    }
  }
  command = *argv;
  if (cVar6 == '\0') {
    pcVar7 = "Disabled";
  }
  else {
    pcVar7 = "Enabled";
  }
  if (cVar6 == '\x01') {
    pcVar8 = "Disabled";
  }
  else {
    pcVar8 = "Enabled";
  }
  uVar5 = RAIL_GetTime();
  responsePrint(command,"Rx:%s,Idle:%s,Time:%u",pcVar7,pcVar8,uVar5);
  return;
}



void rxAt(int argc,char **argv)

{
  _Bool _Var1;
  uint32_t uVar2;
  bool bVar3;
  RAIL_ScheduleRxConfig_t rxCfg;
  RAIL_TimeMode_t endMode;
  RAIL_TimeMode_t startMode;
  uint8_t res;
  uint32_t endTime;
  uint32_t startTime;
  _Bool scheduledRxUpdate;
  _Bool hardEnd;
  _Bool rxTransitionEndSchedule;
  
  rxTransitionEndSchedule = false;
  hardEnd = false;
  scheduledRxUpdate = false;
  _Var1 = inAppMode(NONE,(char *)0x0);
  if (((_Var1 == true) || (_Var1 = inAppMode(RX_SCHEDULED,(char *)0x0), _Var1 == true)) &&
     ((_Var1 = inAppMode(NONE,(char *)0x0), _Var1 == false ||
      (_Var1 = inRadioState(RAIL_RF_STATE_IDLE,(char *)0x0), _Var1 == true)))) {
    startTime = ciGetUnsigned(argv[1]);
    endTime = ciGetUnsigned(argv[3]);
    _Var1 = parseTimeModeFromString(argv[2],&startMode);
    if (_Var1 == true) {
      _Var1 = parseTimeModeFromString(argv[4],&endMode);
      if (_Var1 == true) {
        if (5 < argc) {
          uVar2 = ciGetUnsigned(argv[5]);
          bVar3 = uVar2 != 0;
          if (bVar3) {
            uVar2 = 1;
          }
          rxTransitionEndSchedule = (_Bool)(char)uVar2;
          if (!bVar3) {
            rxTransitionEndSchedule = false;
          }
        }
        if (6 < argc) {
          uVar2 = ciGetUnsigned(argv[6]);
          bVar3 = uVar2 != 0;
          if (bVar3) {
            uVar2 = 1;
          }
          hardEnd = (_Bool)(char)uVar2;
          if (!bVar3) {
            hardEnd = false;
          }
        }
        rxCfg.start = startTime;
        rxCfg.startMode = startMode;
        rxCfg.end = endTime;
        rxCfg.endMode = endMode;
        rxCfg.rxTransitionEndSchedule = rxTransitionEndSchedule;
        rxCfg.hardWindowEnd = hardEnd;
        schRxStopOnRxEvent = rxTransitionEndSchedule;
        _Var1 = inAppMode(RX_SCHEDULED,(char *)0x0);
        if (_Var1 != false) {
          scheduledRxUpdate = true;
        }
        if ((((scheduledRxUpdate == true) ||
             (_Var1 = enableAppModeSync(RX_SCHEDULED,true,*argv), _Var1 == true)) &&
            (res = RAIL_ScheduleRx(channel,&rxCfg), res != 0)) &&
           (responsePrintError(*argv,'\x1b',"Could not start scheduled receive %d",(uint)res),
           scheduledRxUpdate != true)) {
          enableAppModeSync(RX_SCHEDULED,false,*argv);
        }
      }
      else {
        responsePrintError(*argv,'\x1a',"Invalid endMode specified");
      }
    }
    else {
      responsePrintError(*argv,'\x19',"Invalid startMode specified");
    }
  }
  else {
    responsePrintError(*argv,'\x1e',"Cannot enter ScheduledRx when not in Idle.");
  }
  return;
}



void setRxOptions(int argc,char **argv)

{
  RAIL_Status_t RVar1;
  uint32_t options_00;
  RAIL_Status_t status;
  uint32_t options;
  
  options_00 = ciGetUnsigned(argv[1]);
  RVar1 = RAIL_SetRxOptions(options_00);
  if (RVar1 == RAIL_STATUS_NO_ERROR) {
    responsePrint(*argv,"RxOptions:%u",options_00,*argv,argv,argc);
  }
  else {
    responsePrint(*argv,"RxOptions:Failed");
  }
  return;
}



void setTxTone(int argc,char **argv)

{
  uint32_t uVar1;
  uint8_t enable;
  
  uVar1 = ciGetUnsigned(argv[1]);
  enableAppMode(TX_TONE,(_Bool)((char)uVar1 != '\0'),*argv);
  return;
}



void setTxStream(int argc,char **argv)

{
  uint32_t uVar1;
  uint8_t enable;
  
  uVar1 = ciGetUnsigned(argv[1]);
  enableAppMode(TX_STREAM,(_Bool)((char)uVar1 != '\0'),*argv);
  return;
}



void setDirectMode(int argc,char **argv)

{
  uint32_t uVar1;
  uint8_t enable;
  
  uVar1 = ciGetUnsigned(argv[1]);
  enableAppMode(DIRECT,(_Bool)((char)uVar1 != '\0'),*argv);
  return;
}



void setDirectTx(int argc,char **argv)

{
  AppMode_t AVar1;
  uint8_t uVar2;
  uint32_t uVar3;
  char *pcVar4;
  uint8_t enable;
  
  uVar3 = ciGetUnsigned(argv[1]);
  AVar1 = currentAppMode();
  if (AVar1 == DIRECT) {
    RAIL_RfIdle();
    if ((char)uVar3 == '\0') {
      while (receiveModeEnabled != false) {
        uVar2 = RAIL_RxStart(channel);
        if (uVar2 == '\0') break;
        RAIL_RfIdle();
      }
    }
    else {
      RAIL_TxStart(channel,FUN_00000000,(void *)0x0);
    }
    if ((char)uVar3 == '\0') {
      pcVar4 = "Disabled";
    }
    else {
      pcVar4 = "Enabled";
    }
    responsePrint(*argv,"DirectTx:%s",pcVar4);
  }
  else {
    responsePrintError(*argv,'\a',"DirectMode not enabled",*argv,argv,argc);
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void EMU_EnterEM1(void)

{
  WaitForInterrupt();
  _DAT_e000ed10 = _DAT_e000ed10 & 0xfffffffb;
  return;
}



void sleep(int argc,char **argv)

{
  byte bVar1;
  uint uVar2;
  _Bool _Var3;
  bool bVar4;
  uint8_t uVar5;
  uint32_t uVar6;
  CORE_irqState_t CVar7;
  uint32_t uVar8;
  int iVar9;
  undefined *puVar10;
  byte bVar11;
  undefined *puVar12;
  _Bool rfSensed;
  CORE_irqState_t irqState_2;
  CORE_irqState_t irqState_1;
  _Bool enableCb;
  uint8_t emMode;
  CORE_irqState_t irqState;
  char *em4State;
  
  _Var3 = enableAppModeSync(RF_SENSE,true,*argv);
  if (_Var3 != true) {
    return;
  }
  uVar6 = ciGetUnsigned(argv[1]);
  bVar11 = (byte)uVar6 & 0x7f;
  if (4 < bVar11) {
    responsePrintError(*argv,'\x01',"Invalid EM mode %u (valid 0-4)",(uint)bVar11);
    return;
  }
  em4State = "";
  if (bVar11 != 4) goto LAB_00004018;
  bVar1 = argv[1][1];
  if (bVar1 == 0x53) {
LAB_00003fc4:
    CVar7 = CORE_EnterCritical();
    uVar2 = (EMU->EM4CTRL);
    write_volatile_4(EMU->EM4CTRL,uVar2 & 0xfffffffe);
    em4State = "s";
    CORE_ExitCritical(CVar7);
    goto LAB_00004018;
  }
  if (bVar1 < 0x54) {
    if (bVar1 == 0x48) {
LAB_00003fe2:
      CVar7 = CORE_EnterCritical();
      uVar2 = (EMU->EM4CTRL);
      write_volatile_4(EMU->EM4CTRL,uVar2 | 1);
      em4State = "h";
      CORE_ExitCritical(CVar7);
      goto LAB_00004018;
    }
  }
  else {
    if (bVar1 == 0x68) goto LAB_00003fe2;
    if (bVar1 == 0x73) goto LAB_00003fc4;
  }
  uVar2 = (EMU->EM4CTRL);
  if ((uVar2 & 1) == 0) {
    em4State = "s";
  }
  else {
    em4State = "h";
  }
LAB_00004018:
  if ((2 < argc) && (rfUs = ciGetUnsigned(argv[2]), 3 < argc)) {
    uVar8 = ciGetUnsigned(argv[3]);
    rfBand = (RAIL_RfSenseBand_t)uVar8;
  }
  if (1 < bVar11) {
    RAIL_RfIdle();
    PeripheralDisable();
    GPIO_EM4SetPinRetention(true);
  }
  if (bVar11 < 4) {
    puVar12 = &DAT_000183e4;
  }
  else {
    puVar12 = &DAT_000183c8;
  }
  responsePrint(*argv,"EM:%u%s,SerialWakeup:%s,RfSense:%s",(uint)bVar11,em4State,puVar12,
                rfBands[rfBand & 3]);
  serialWaitForTxIdle();
  irqState = CORE_EnterCritical();
  rfUs = RAIL_RfSense(rfBand,rfUs,(bool)((byte)~(byte)uVar6 >> 7));
  GPIO_IntConfig(gpioPortA,1,false,true,true);
  serEvent = false;
  do {
    switch(bVar11) {
    case 1:
      EMU_EnterEM1();
      break;
    case 2:
      EMU_EnterEM2(true);
      break;
    case 3:
      EMU_EnterEM3(true);
      break;
    case 4:
      EMU_EnterEM4();
    }
    CORE_ExitCritical(irqState);
    irqState = CORE_EnterCritical();
    bVar4 = RAIL_RfSensed();
  } while ((bVar4 != true) && (serEvent != true));
  CORE_ExitCritical(irqState);
  enableAppMode(RF_SENSE,false,(char *)0x0);
  GPIO_IntConfig(gpioPortA,1,false,true,false);
  if (serEvent == false) {
    puVar12 = &DAT_00018410;
  }
  else {
    puVar12 = &DAT_0001840c;
  }
  if (bVar4 == false) {
    puVar10 = &DAT_00018410;
  }
  else {
    puVar10 = &DAT_0001840c;
  }
  responsePrint("sleepWoke","EM:%u%s,SerialWakeup:%s,RfSensed:%s,RfUs:%u",(uint)bVar11,em4State,
                puVar12,puVar10,rfUs);
  if (serEvent != false) {
    if (bVar11 < 2) {
      do {
        iVar9 = getchar();
      } while (iVar9 < 0);
    }
    else {
      usDelay(250000);
      getchar();
      getchar();
      getchar();
      getchar();
    }
  }
  while ((receiveModeEnabled != false && (uVar5 = RAIL_RxStart(channel), uVar5 != '\0'))) {
    RAIL_RfIdle();
  }
  if ((1 < bVar11) && ((logLevel & 1) != 0)) {
    PeripheralEnable();
    redrawDisplay = true;
  }
  return;
}



void rfSense(int argc,char **argv)

{
  _Bool _Var1;
  uint32_t uVar2;
  
  if ((1 < argc) && (rfUs = ciGetUnsigned(argv[1]), 2 < argc)) {
    uVar2 = ciGetUnsigned(argv[2]);
    rfBand = (RAIL_RfSenseBand_t)uVar2;
  }
  _Var1 = enableAppModeSync(RF_SENSE,(_Bool)(rfBand != RAIL_RFSENSE_OFF),*argv);
  if (_Var1 == true) {
    rfUs = RAIL_RfSense(rfBand,rfUs,true);
    if (rfUs == 0) {
      rfBand = RAIL_RFSENSE_OFF;
    }
    responsePrint(*argv,"RfSense:%s,RfUs:%u",rfBands[rfBand & 3],rfUs);
  }
  return;
}



void rfSensedCheck(void)

{
  AppMode_t AVar1;
  bool bVar2;
  
  AVar1 = currentAppMode();
  if ((AVar1 == RF_SENSE) && (bVar2 = RAIL_RfSensed(), bVar2 != false)) {
    enableAppMode(RF_SENSE,false,(char *)0x0);
    responsePrint("rfSensedCheck","RfSensed:%s,RfUs:%u",rfBands[rfBand & 3],rfUs);
  }
  return;
}



_Bool parseTimeModeFromString(char *str,RAIL_TimeMode_t *mode)

{
  int iVar1;
  
  iVar1 = strcasecmp("dis",str);
  if (iVar1 == 0) {
    *mode = RAIL_TIME_DISABLED;
  }
  else {
    iVar1 = strcasecmp("rel",str);
    if (iVar1 == 0) {
      *mode = RAIL_TIME_DELAY;
    }
    else {
      iVar1 = strcasecmp("abs",str);
      if (iVar1 != 0) {
        *mode = RAIL_TIME_DISABLED;
        return false;
      }
      *mode = RAIL_TIME_ABSOLUTE;
    }
  }
  return true;
}



uint BUS_RegBitRead(uint32_t *addr,uint bit)

{
  uint32_t aliasAddr;
  
  return *(uint *)((bit + (int)(addr + 0x840000) * 8) * 4);
}



uint GPIO_PinInGet(GPIO_Port_TypeDef port,uint pin)

{
  uint uVar1;
  
  uVar1 = BUS_RegBitRead(&Peripherals::GPIO.PA_DIN + (uint)port * 0xc,pin);
  return uVar1;
}



void GPIO_IntConfig(GPIO_Port_TypeDef port,uint pin,_Bool risingEdge,_Bool fallingEdge,_Bool enable)

{
  GPIO_ExtIntConfig(port,pin,pin,risingEdge,fallingEdge,enable);
  return;
}



uint32_t USART_StatusGet(USART_TypeDef *usart)

{
  return usart->STATUS;
}



void gpio0LongPress(void)

{
  radioTransmit(0,(char *)0x0);
  return;
}



void gpio0ShortPress(void)

{
  radioTransmit(1,(char *)0x0);
  return;
}



void gpio1LongPress(void)

{
  return;
}



void gpio1ShortPress(void)

{
  _Bool _Var1;
  RAIL_Status_t RVar2;
  uint8_t uVar3;
  
  _Var1 = inAppMode(NONE,(char *)0x0);
  if ((_Var1 == true) && (_Var1 = inRadioState(RAIL_RF_STATE_TX,(char *)0x0), _Var1 == false)) {
    _Var1 = inRadioState(RAIL_RF_STATE_RX,(char *)0x0);
    if (_Var1 != false) {
      RAIL_RfIdle();
    }
    RVar2 = RAIL_ChannelExists(channel + '\x01');
    if (RVar2 == RAIL_STATUS_NO_ERROR) {
      channel = channel + '\x01';
    }
    else {
      channel = '\0';
      while (RVar2 = RAIL_ChannelExists(channel), RVar2 != RAIL_STATUS_NO_ERROR) {
        channel = channel + '\x01';
      }
    }
    while ((receiveModeEnabled != false && (uVar3 = RAIL_RxStart(channel), uVar3 != '\0'))) {
      RAIL_RfIdle();
    }
    redrawDisplay = true;
  }
  return;
}



void gpioCallback(uint8_t pin)

{
  uint uVar1;
  uint32_t uVar2;
  
  if (pin == '\x01') {
    serEvent = true;
  }
  if (pin == '\x06') {
    uVar1 = GPIO_PinInGet(gpioPortF,6);
    if (uVar1 == 0) {
      uVar2 = RAIL_GetTime();
      gpioCallback::gpio0TimeCapture = uVar2 / 1000;
    }
    else {
      uVar2 = RAIL_GetTime();
      if (uVar2 / 1000 - gpioCallback::gpio0TimeCapture < 0x3e9) {
        gpio0ShortPress();
      }
      else {
        gpio0LongPress();
      }
    }
  }
  else {
    if (pin == '\a') {
      uVar1 = GPIO_PinInGet(gpioPortF,7);
      if (uVar1 == 0) {
        uVar2 = RAIL_GetTime();
        gpioCallback::gpio1TimeCapture = uVar2 / 1000;
      }
      else {
        uVar2 = RAIL_GetTime();
        if (uVar2 / 1000 - gpioCallback::gpio1TimeCapture < 0x3e9) {
          gpio1ShortPress();
        }
        else {
          gpio1LongPress();
        }
      }
    }
  }
  return;
}



void appHalInit(void)

{
  int i;
  
  halInit();
  CMU_ClockEnable(cmuClock_GPIO,true);
  BSP_Init(4);
  BSP_LedsInit();
  GRAPHICS_Init();
  RETARGET_SerialInit();
  RETARGET_SerialCrLf(1);
  for (i = 0; i < 2; i = i + 1) {
    GPIO_PinModeSet(buttonArray[i].port,buttonArray[i].pin,gpioModeInputPull,1);
  }
  GPIO_PinModeSet(gpioPortC,7,gpioModePushPull,1);
  GPIOINT_Init();
  GPIOINT_CallbackRegister('\x06',gpioCallback + 1);
  GPIOINT_CallbackRegister('\a',gpioCallback + 1);
  GPIOINT_CallbackRegister('\x01',gpioCallback + 1);
  GPIO_IntConfig(gpioPortF,6,true,true,true);
  GPIO_IntConfig(gpioPortF,7,true,true,true);
  return;
}



void updateDisplay(void)

{
  char textBuf [64];
  
  if ((redrawDisplay != false) && ((logLevel & 1) != 0)) {
    redrawDisplay = false;
    GRAPHICS_Clear();
    GRAPHICS_AppendString("\nRAIL Test App\n");
    GRAPHICS_AppendString("");
    sniprintf(textBuf,0x40,"Rx Count: %05lu",
              counters.receive + ((counters.receive >> 5) / 0xc35) * -100000);
    GRAPHICS_AppendString(textBuf);
    sniprintf(textBuf,0x40,"Tx Count: %05lu",
              counters.transmit + ((counters.transmit >> 5) / 0xc35) * -100000);
    GRAPHICS_AppendString(textBuf);
    sniprintf(textBuf,0x40,"Channel: %d",(uint)channel);
    GRAPHICS_AppendString(textBuf);
    GRAPHICS_AppendString("");
    GRAPHICS_AppendString("   Tx     Rx");
    GRAPHICS_InsertTriangle(0x14,0x50,0x20,true,(char)(counters.transmit % 10) * -10);
    GRAPHICS_InsertTriangle(0x4c,0x50,0x20,false,(char)(counters.receive % 10) * '\n');
    GRAPHICS_Update();
  }
  return;
}



void LedSet(int led)

{
  if ((logLevel & 1) != 0) {
    BSP_LedSet(led);
  }
  return;
}



void LedToggle(int led)

{
  if ((logLevel & 1) != 0) {
    BSP_LedToggle(led);
  }
  return;
}



void PeripheralDisable(void)

{
  BSP_LedClear(0);
  BSP_LedClear(1);
  GRAPHICS_Clear();
  GRAPHICS_Update();
  GRAPHICS_Sleep();
  return;
}



void PeripheralEnable(void)

{
  GRAPHICS_Wakeup();
  return;
}



void usDelay(uint32_t microseconds)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t start;
  
  uVar1 = RAIL_GetTime();
  do {
    uVar2 = RAIL_GetTime();
  } while (uVar2 - uVar1 < microseconds);
  return;
}



void serialWaitForTxIdle(void)

{
  uint32_t uVar1;
  
  do {
    uVar1 = USART_StatusGet((USART_TypeDef *)&Peripherals::USART0);
  } while ((uVar1 & 0x2000) == 0);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint8_t SYSTEM_GetProdRev(void)

{
  return (uint8_t)((uint)_DAT_0fe081fc >> 0x18);
}



void BUS_RegBitWrite(uint32_t *addr,uint bit,uint val)

{
  uint32_t aliasAddr;
  
  *(uint *)((bit + (int)(addr + 0x840000) * 8) * 4) = val;
  return;
}



uint BUS_RegBitRead(uint32_t *addr,uint bit)

{
  uint32_t aliasAddr;
  
  return *(uint *)((bit + (int)(addr + 0x840000) * 8) * 4);
}



void GPIO_PinOutClear(GPIO_Port_TypeDef port,uint pin)

{
  BUS_RegBitWrite(&Peripherals::GPIO.PA_DOUT + (uint)port * 0xc,pin,0);
  return;
}



uint GPIO_PinOutGet(GPIO_Port_TypeDef port,uint pin)

{
  uint uVar1;
  
  uVar1 = BUS_RegBitRead(&Peripherals::GPIO.PA_DOUT + (uint)port * 0xc,pin);
  return uVar1;
}



void GPIO_PinOutToggle(GPIO_Port_TypeDef port,uint pin)

{
  (&Peripherals::GPIO.PA_DOUTTGL)[(uint)port * 0xc] = 1 << (pin & 0xff);
  return;
}



void CHIP_Init(void)

{
  uint uVar1;
  byte bVar2;
  SYSTEM_ChipRevision_TypeDef chipRev;
  uint32_t clkEn;
  uint8_t prodRev;
  uint32_t resetVal;
  uint32_t setVal;
  uint32_t port;
  
  bVar2 = SYSTEM_GetProdRev();
  SYSTEM_ChipRevisionGet(&chipRev);
  if (bVar2 < 0x8f) {
    uVar1 = (CMU->HFBUSCLKEN0);
    write_volatile_4(CMU->HFBUSCLKEN0,uVar1 | 4);
    for (port = 0; port < 6; port = port + 1) {
      (&Peripherals::GPIO.PA_CTRL)[port * 0xc] = 0x500050;
    }
    write_volatile_4(CMU->HFBUSCLKEN0,uVar1);
  }
  if (bVar2 < 0x90) {
    uVar1 = (CMU->HFXOSTARTUPCTRL);
    write_volatile_4(CMU->HFXOSTARTUPCTRL,uVar1 & 0xffffff80 | 0x20);
  }
  if (chipRev.major == '\x01') {
    uVar1 = (EMU->BIASCONF);
    write_volatile_4(EMU->BIASCONF,uVar1 | 4);
  }
  return;
}



int main(void)

{
  uint uVar1;
  _Bool _Var2;
  bool bVar3;
  uint32_t uVar4;
  undefined *puVar5;
  undefined4 uVar6;
  uint32_t resetCause;
  
  CHIP_Init();
  uVar4 = RMU_ResetCauseGet();
  RMU_ResetCauseClear();
  if ((uVar4 & 0x10000) != 0) {
    write_volatile_4(EMU->CMD,1);
  }
  appHalInit();
  RAIL_RfInit(&railInitParams);
  RAIL_CalInit(&railCalInitParams);
  changeRadioConfig(currentConfig);
  RAIL_RxConfig(0x67d,true);
  RAIL_TxConfig(0xff);
  RAIL_SetRxTransitions(RAIL_RF_STATE_RX,RAIL_RF_STATE_RX,'\0');
  RAIL_SetTxTransitions(RAIL_RF_STATE_RX,RAIL_RF_STATE_RX);
  _Var2 = queueInit(&rxPacketQueue,10);
  if (_Var2 != true) {
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  updateDisplay();
  puts("\nRAIL Test App");
  if ((uVar4 & 0x10000) != 0) {
    uVar1 = (EMU->EM4CTRL);
    if ((uVar1 & 1) == 0) {
      uVar6 = 0x73;
    }
    else {
      uVar6 = 0x68;
    }
    bVar3 = RAIL_RfSensed();
    if (bVar3 == false) {
      puVar5 = &DAT_0001a7e0;
    }
    else {
      puVar5 = &DAT_0001a7dc;
    }
    responsePrint("sleepWoke","EM:4%c,SerialWakeup:No,RfSensed:%s",uVar6,puVar5);
  }
  iprintf("> ");
  ciInitState(&state,ciBuffer,0x100,commands);
  RAIL_AutoAckLoadBuffer(&ackPayload);
  RAIL_RxStart(channel);
  do {
    processInputCharacters();
    rfSensedCheck();
    sendPacketIfPending();
    finishTxSequenceIfPending();
    changeAppModeIfPending();
    printReceivedPacket();
    printNewTxError();
    checkTimerExpiration();
    updateDisplay();
    processPendingCalibrations();
    printAckTimeout();
  } while( true );
}



void RAILCb_RfReady(void)

{
  LedSet(0);
  LedSet(1);
  return;
}



void RAILCb_CalNeeded(void)

{
  calibrateRadio = true;
  return;
}



void RAILCb_RadioStateChanged(uint8_t state)

{
  return;
}



void RAILCb_TimerExpired(void)

{
  _Bool _Var1;
  AppMode_t AVar2;
  uint uVar3;
  
  _Var1 = inAppMode(NONE,(char *)0x0);
  if (_Var1 == false) {
    AVar2 = currentAppMode();
    if (AVar2 == PER) {
      GPIO_PinOutToggle(gpioPortC,7);
      uVar3 = GPIO_PinOutGet(gpioPortC,7);
      counters.perTriggers = counters.perTriggers + uVar3;
      uVar3 = GPIO_PinOutGet(gpioPortC,7);
      perCount = perCount - uVar3;
      if (perCount == 0) {
        GPIO_PinOutClear(gpioPortC,7);
        enableAppMode(PER,false,(char *)0x0);
      }
      else {
        RAIL_TimerSet(perDelay,RAIL_TIME_DELAY);
      }
    }
    else {
      pendPacketTx();
    }
  }
  else {
    if (abortRxDelay == 0) {
      railTimerExpireTime = RAIL_GetTime();
      railTimerConfigExpireTime = RAIL_TimerGet();
      railTimerExpired = true;
    }
    else {
      RAIL_RfIdleExt(1,true);
    }
  }
  return;
}



void RAILCb_RxAckTimeout(void)

{
  uint32_t uVar1;
  
  counters.ackTimeout = counters.ackTimeout + 1;
  rxAckTimeout = true;
  uVar1 = RAIL_GetTime();
  ackTimeoutDuration = uVar1 - previousTxTime;
  return;
}



void RAILCb_IEEE802154_DataRequestCommand(RAIL_IEEE802154_Address_t *data)

{
  if (data->length == RAIL_IEEE802154_LongAddress) {
    if (*(char *)&data->field_1 == -0x56) {
      RAIL_IEEE802154_SetFramePending();
    }
  }
  else {
    if ((char)*(undefined2 *)&data->field_1 == -0x56) {
      RAIL_IEEE802154_SetFramePending();
    }
  }
  return;
}



void RAILCb_RssiAverageDone(int16_t avgRssi)

{
  undefined8 uVar1;
  
  rssiDoneCount = rssiDoneCount + 1;
  averageRssi = (float)(longlong)(int)avgRssi / 4.0;
  if (avgRssi == -0x200) {
    responsePrint("getAvgRssi","Could not read RSSI.");
  }
  else {
    uVar1 = __aeabi_f2d(averageRssi);
    responsePrint("getAvgRssi","rssi:%.2f",(int)uVar1,(int)((ulonglong)uVar1 >> 0x20));
  }
  return;
}



void processPendingCalibrations(void)

{
  _Bool _Var1;
  uint8_t uVar2;
  RAIL_CalMask_t calForce;
  RAIL_CalMask_t pendingCals;
  _Bool calsInMode;
  
  _Var1 = inAppMode(NONE,(char *)0x0);
  if ((((calibrateRadio != false) && (_Var1 != false)) && (skipCalibrations != true)) &&
     (receivingPacket != true)) {
    calForce = RAIL_CalPendingGet();
    if ((calForce & 0x10000) != 0) {
      RAIL_RfIdle();
    }
    counters.calibrations = counters.calibrations + 1;
    calibrateRadio = false;
    RAIL_CalStart((undefined4 *)0x0,calForce,0);
    if ((calForce & 0x10000) != 0) {
      while ((receiveModeEnabled != false && (uVar2 = RAIL_RxStart(channel), uVar2 != '\0'))) {
        RAIL_RfIdle();
      }
    }
  }
  return;
}



void checkTimerExpiration(void)

{
  if (railTimerExpired != false) {
    railTimerExpired = false;
    responsePrint("timerCb","TimerExpiredCallback:%u,ConfiguredExpireTime:%u",railTimerExpireTime,
                  railTimerConfigExpireTime);
  }
  return;
}



void printNewTxError(void)

{
  if (newTxError != false) {
    newTxError = false;
    if ((lastTxStatus & 2) != 0) {
      if ((logLevel & 2) != 0) {
        responsePrint("txPacket","txStatus:Error,errorReason:Tx underflow or abort,errorCode:%u",
                      (uint)lastTxStatus);
      }
      counters.txAbort = counters.txAbort + 1;
    }
    if ((lastTxStatus & 1) != 0) {
      if ((logLevel & 2) != 0) {
        responsePrint("txPacket","txStatus:Error,errorReason:Tx overflow or abort,errorCode:%u",
                      (uint)lastTxStatus);
      }
      counters.txAbort = counters.txAbort + 1;
    }
    if ((lastTxStatus & 4) != 0) {
      if ((logLevel & 2) != 0) {
        responsePrint("txPacket","txStatus:Error,errorReason:Tx channel busy,errorCode:%u",
                      (uint)lastTxStatus);
      }
      counters.txChannelBusy = counters.txChannelBusy + 1;
    }
  }
  return;
}



void printAckTimeout(void)

{
  if (rxAckTimeout != false) {
    rxAckTimeout = false;
    responsePrint("rxAckTimeout","ackTimeoutDuration:%d",ackTimeoutDuration);
  }
  return;
}



void changeChannel(uint32_t i)

{
  redrawDisplay = true;
  channel = (uint8_t)i;
  return;
}



void changeRadioConfig(int newConfig)

{
  uint8_t uVar1;
  
  RAIL_RfIdle();
  uVar1 = RAIL_RadioConfig(configList[newConfig]);
  if (uVar1 != '\0') {
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  RAIL_PacketLengthConfigFrameType(frameTypeConfigList[newConfig]);
  changeChannelConfig(newConfig);
  currentConfig = newConfig;
  return;
}



void changeChannelConfig(int newConfig)

{
  channel = RAIL_ChannelConfig(channelConfigs[newConfig]);
  changeChannel((uint)channel);
  return;
}



void pendPacketTx(void)

{
  packetTx = true;
  return;
}



void sendPacketIfPending(void)

{
  uint32_t uVar1;
  AppMode_t AVar2;
  uint32_t storedTransmitCounter;
  uint8_t txStatus;
  
  uVar1 = internalTransmitCounter;
  if (packetTx != false) {
    packetTx = false;
    AVar2 = currentAppMode();
    if (AVar2 != TX_CONTINUOUS) {
      txCount = txCount + -1;
    }
    AVar2 = currentAppMode();
    if ((AVar2 != TX_UNDERFLOW) && (txFifoManual != true)) {
      loadTxData(&transmitPayload);
    }
    AVar2 = currentAppMode();
    if ((AVar2 == TX_SCHEDULED) || (AVar2 = currentAppMode(), AVar2 == SCHTX_AFTER_RX)) {
      if (txOptionsPtr == (RAIL_TxOptions_t *)0x0) {
        txStatus = RAIL_TxStart(channel,RAIL_ScheduleTx + 1,&nextPacketTxTime);
      }
      else {
        txStatus = RAIL_TxStartWithOptions
                             (channel,txOptionsPtr,RAIL_ScheduleTx + 1,&nextPacketTxTime);
      }
    }
    else {
      if ((uVar1 == startTransmitCounter) && (failPackets == 0)) {
        if (txOptionsPtr == (RAIL_TxOptions_t *)0x0) {
          txStatus = RAIL_TxStart(channel,txPreTxOp,txPreTxOpArgs);
        }
        else {
          txStatus = RAIL_TxStartWithOptions(channel,txOptionsPtr,txPreTxOp,txPreTxOpArgs);
        }
      }
      else {
        if (txOptionsPtr == (RAIL_TxOptions_t *)0x0) {
          txStatus = RAIL_TxStart(channel,txPreTxOp,(void *)0x0);
        }
        else {
          txStatus = RAIL_TxStartWithOptions(channel,txOptionsPtr,txPreTxOp,(void *)0x0);
        }
      }
    }
    if (txStatus == '\0') {
      AVar2 = currentAppMode();
      if (AVar2 == TX_CANCEL) {
        usDelay(txCancelDelay);
        RAIL_RfIdle();
      }
    }
    else {
      lastTxStatus = txStatus;
      failPackets = failPackets + 1;
      scheduleNextTx();
    }
  }
  return;
}



void pendFinishTxSequence(void)

{
  finishTxSequence = true;
  return;
}



void finishTxSequenceIfPending(void)

{
  char *pcVar1;
  uint32_t sentPackets;
  
  if (finishTxSequence != false) {
    finishTxSequence = false;
    if ((logLevel & 2) != 0) {
      if (failPackets == 0) {
        pcVar1 = "Complete";
      }
      else {
        if (internalTransmitCounter - startTransmitCounter == 0) {
          pcVar1 = "Error";
        }
        else {
          pcVar1 = "Partial";
        }
      }
      responsePrint("txEnd","txStatus:%s,transmitted:%u,lastTxTime:%u,failed:%u,lastTxStatus:0x%x",
                    pcVar1,internalTransmitCounter - startTransmitCounter,previousTxTime,failPackets
                    ,(uint)lastTxStatus);
    }
    startTransmitCounter = internalTransmitCounter;
    failPackets = 0;
    lastTxStatus = '\0';
  }
  return;
}



void setNextPacketTime(uint32_t time,_Bool isAbs)

{
  nextPacketTxTime.when = time;
  nextPacketTxTime.mode = isAbs == false;
  return;
}



void printReceivedPacket(void)

{
  _Bool _Var1;
  void *handle;
  RAIL_RxPacketInfo_t *packetInfo;
  RAIL_RxPacketInfo_t *rxPacketInfo;
  void *rxPacketHandle;
  
  _Var1 = queueIsEmpty(&rxPacketQueue);
  if (_Var1 != true) {
    handle = queueRemove(&rxPacketQueue);
    packetInfo = (RAIL_RxPacketInfo_t *)memoryPtrFromHandle(handle);
    printPacket("rxPacket",(uint8_t *)&packetInfo->field_0xa,packetInfo->dataLength,packetInfo);
    memoryFree(handle);
  }
  return;
}



void printPacket(char *cmdName,uint8_t *data,uint16_t dataLength,RAIL_RxPacketInfo_t *packetInfo)

{
  int iVar1;
  char *pcVar2;
  undefined *puVar3;
  undefined *puVar4;
  int n;
  int i;
  uint32_t offset;
  
  offset = 0;
  if (data == (uint8_t *)0x0) {
    responsePrint(cmdName,"len:0");
  }
  else {
    for (i = 0; i < (int)(uint)dataLength; i = i + 1) {
      iVar1 = sniprintf(packetPrintBuffer + offset,0x4b5 - offset," 0x%.2x",(uint)data[i]);
      if (iVar1 < 0) {
        packetPrintBuffer._0_4_ = 0x61766e49;
        packetPrintBuffer._4_4_ = 0x2064696c;
        packetPrintBuffer._8_4_ = 0x6b636150;
        packetPrintBuffer._12_4_ = packetPrintBuffer._12_4_ & 0xff000000 | 0x7465;
        break;
      }
      offset = iVar1 + offset;
      if (0x4b4 < offset) {
        packetPrintBuffer._0_4_ = 0x6b636150;
        packetPrintBuffer._4_4_ = 0x74207465;
        packetPrintBuffer._8_4_ = 0x6c206f6f;
        packetPrintBuffer._12_4_ = 0x65677261;
        packetPrintBuffer._16_2_ = 0x21;
        break;
      }
    }
    if (packetInfo == (RAIL_RxPacketInfo_t *)0x0) {
      responsePrint(cmdName,"len:%d,payload:%s",(uint)dataLength,packetPrintBuffer);
    }
    else {
      if ((*(byte *)&(packetInfo->appendedInfo).field_0x4 & 1) == 0) {
        puVar4 = &DAT_0001aa14;
      }
      else {
        puVar4 = &DAT_0001aa0c;
      }
      if ((*(byte *)&(packetInfo->appendedInfo).field_0x4 & 2) == 0) {
        puVar3 = &DAT_0001aa14;
      }
      else {
        puVar3 = &DAT_0001aa0c;
      }
      if ((*(byte *)&(packetInfo->appendedInfo).field_0x4 & 4) == 0) {
        pcVar2 = "False";
      }
      else {
        pcVar2 = "True";
      }
      responsePrint(cmdName,"len:%d,timeUs:%u,crc:%s,coding:%s,rssi:%d,lqi:%d,isAck:%s,payload:%s",
                    (uint)packetInfo->dataLength,(packetInfo->appendedInfo).timeUs,puVar4,puVar3,
                    (int)(packetInfo->appendedInfo).rssiLatch,(uint)(packetInfo->appendedInfo).lqi,
                    pcVar2,packetPrintBuffer);
    }
  }
  return;
}



void processInputCharacters(void)

{
  int8_t iVar1;
  int iVar2;
  char input;
  
  iVar2 = getchar();
  input = (char)iVar2;
  while ((input != '\0' && (input != -1))) {
    if (input != '\n') {
      putchar((uint)(byte)input);
    }
    iVar1 = ciProcessInput(&state,&input,1);
    if ('\0' < iVar1) {
      iprintf("> ");
    }
    iVar2 = getchar();
    input = (char)iVar2;
  }
  return;
}



void ciErrorCallback(char *command,CommandError_t error)

{
  if (error == CI_UNKNOWN_COMMAND) {
    responsePrintError("ci",'\0',"Unknown command \'%s\'",command);
  }
  else {
    if (error == CI_MAX_ARGUMENTS) {
      responsePrintError("ci",'\x01',"CI_MAX_ARGUMENTS \'%s\'",command);
    }
    else {
      if (error == CI_INVALID_ARGUMENTS) {
        responsePrintError("ci",'\x02',"Invalid arguments for \'%s\'",command);
      }
    }
  }
  return;
}



AppMode_t currentAppMode(void)

{
  return currAppMode;
}



void enableAppMode(AppMode_t next,_Bool enable,char *command)

{
  if ((transitionPend != true) && (next != NONE)) {
    transitionPend = true;
    enableMode = enable;
    nextAppMode = next;
    if (command == (char *)0x0) {
      if ((logLevel & 2) == 0) {
        nextCommand = (char *)0x0;
      }
      else {
        nextCommand = "appMode";
      }
    }
    else {
      memcpy(nextCommandBuf,command,0x10);
      nextCommand = nextCommandBuf;
    }
  }
  return;
}



char * appModeNames(AppMode_t appMode)

{
  char *appModes [15];
  
  appModes[0] = "None";
  appModes[1] = "Stream";
  appModes[2] = "Tone";
  appModes[3] = "ContinuousTx";
  appModes[4] = "DirectMode";
  appModes[5] = "PacketTx";
  appModes[6] = "ScheduledTx";
  appModes[7] = "SchTxAfterRx";
  appModes[8] = "RxOverflow";
  appModes[9] = "TxUnderflow";
  appModes[10] = "TxCancel";
  appModes[11] = "RfSense";
  appModes[12] = "PER";
  appModes[13] = "BER";
  appModes[14] = "ScheduledRx";
  return appModes[appMode];
}



void transitionAppMode(AppMode_t nextAppMode)

{
  if (currAppMode == NONE) {
    RAIL_TimerCancel();
  }
  else {
    if (currAppMode == TX_STREAM) {
      RAIL_TxStreamStop();
    }
    else {
      if (currAppMode == TX_TONE) {
        RAIL_TxToneStop();
      }
      else {
        if (currAppMode == DIRECT) {
          RAIL_DirectModeConfig(false);
        }
        else {
          if ((((currAppMode == TX_CONTINUOUS) || (currAppMode == TX_N_PACKETS)) ||
              (currAppMode == TX_SCHEDULED)) ||
             ((currAppMode == TX_UNDERFLOW || (currAppMode == TX_CANCEL)))) {
            RAIL_TimerCancel();
            txCount = 0;
            pendFinishTxSequence();
          }
          else {
            if (currAppMode == RF_SENSE) {
              RAIL_RfSense(RAIL_RFSENSE_OFF,0,false);
            }
            else {
              if (currAppMode == PER) {
                RAIL_TimerCancel();
              }
              else {
                if (currAppMode == BER) {
                  RAIL_RfIdle();
                }
              }
            }
          }
        }
      }
    }
  }
  if (nextAppMode == TX_STREAM) {
    RAIL_RfIdleExt(1,true);
    RAIL_TxStreamStart(channel,1);
  }
  else {
    if (nextAppMode == TX_TONE) {
      RAIL_RfIdleExt(1,true);
      RAIL_TxToneStart(channel);
    }
    else {
      if (nextAppMode == DIRECT) {
        RAIL_DirectModeConfig(true);
      }
      else {
        if ((nextAppMode == TX_CONTINUOUS) || (nextAppMode == TX_N_PACKETS)) {
          pendPacketTx();
        }
        else {
          if ((nextAppMode == TX_SCHEDULED) || (nextAppMode == TX_CANCEL)) {
            txCount = 1;
            pendPacketTx();
          }
          else {
            if ((nextAppMode == SCHTX_AFTER_RX) || (nextAppMode == RX_OVERFLOW)) {
              RAIL_RxStart(channel);
            }
          }
        }
      }
    }
  }
  prevAppMode = currAppMode;
  currAppMode = nextAppMode;
  return;
}



void setAppModeInternal(void)

{
  char *command;
  char *pcVar1;
  char *pcVar2;
  uint32_t uVar3;
  char *pcVar4;
  AppMode_t appMode;
  AppMode_t next;
  
  command = nextCommand;
  appMode = nextAppMode;
  if (enableMode == false) {
    appMode = NONE;
  }
  if ((currAppMode == nextAppMode) && (enableMode != false)) {
    if (nextCommand != (char *)0x0) {
      pcVar1 = appModeNames(appMode);
      responsePrint(command,"%s:Enabled",pcVar1);
    }
  }
  else {
    if (((currAppMode == nextAppMode) && (enableMode != true)) ||
       ((currAppMode == NONE && (enableMode != false)))) {
      if (nextCommand != (char *)0x0) {
        pcVar1 = appModeNames(appMode);
        pcVar2 = appModeNames(currAppMode);
        uVar3 = RAIL_GetTime();
        responsePrint(command,"%s:Enabled,%s:Disabled,Time:%u",pcVar1,pcVar2,uVar3);
      }
      transitionAppMode(appMode);
    }
    else {
      if (nextCommand != (char *)0x0) {
        if (enableMode == false) {
          pcVar1 = "disable";
        }
        else {
          pcVar1 = "enable";
        }
        pcVar2 = appModeNames(nextAppMode);
        pcVar4 = appModeNames(currAppMode);
        responsePrintError(command,'\x01',"Can\'t %s %s during %s",pcVar1,pcVar2,pcVar4);
      }
    }
  }
  return;
}



void changeAppModeIfPending(void)

{
  if (transitionPend != false) {
    transitionPend = false;
    setAppModeInternal();
  }
  return;
}



void packetMode_RxPacketReceived(void *rxPacketHandle)

{
  _Bool _Var1;
  AppMode_t AVar2;
  int *piVar3;
  RAIL_RxPacketInfo_t *rxPacketInfo;
  
  RAIL_TxDataLoad(&transmitPayload);
  receivingPacket = false;
  piVar3 = (int *)memoryPtrFromHandle(rxPacketHandle);
  if (piVar3 == (int *)0x0) {
    counters.noRxBuffer = counters.noRxBuffer + 1;
  }
  else {
    if (*(char *)(piVar3 + 3) == -0xf) {
      RAIL_AutoAckCancelAck();
    }
    if (afterRxCancelAck != false) {
      afterRxCancelAck = false;
      RAIL_AutoAckCancelAck();
    }
    if (afterRxUseTxBufferForAck != false) {
      afterRxUseTxBufferForAck = false;
      RAIL_AutoAckUseTxBuffer();
    }
    AVar2 = currentAppMode();
    if (AVar2 == SCHTX_AFTER_RX) {
      setNextPacketTime(txAfterRxDelay + *piVar3,true);
      txCount = 1;
      pendPacketTx();
    }
  }
  if (((logLevel & 2) != 0) && (redrawDisplay = true, piVar3 != (int *)0x0)) {
    memoryTakeReference(rxPacketHandle);
    queueAdd(&rxPacketQueue,rxPacketHandle);
  }
  _Var1 = inAppMode(RX_SCHEDULED,(char *)0x0);
  if ((_Var1 != false) && (schRxStopOnRxEvent != false)) {
    enableAppMode(RX_SCHEDULED,false,(char *)0x0);
  }
  AVar2 = currentAppMode();
  if (AVar2 == RX_OVERFLOW) {
    enableAppMode(RX_OVERFLOW,false,(char *)0x0);
    changeAppModeIfPending();
    usDelay(10000000);
  }
  updateStats((int)*(char *)((int)piVar3 + 5),&counters.rssi);
  return;
}



void fifoMode_RxPacketReceived(void)

{
  AppMode_t AVar1;
  uint16_t uVar2;
  uint16_t bytesRead;
  
  AVar1 = currentAppMode();
  if (AVar1 == BER) {
    RAIL_ResetFifo(true,true);
  }
  else {
    if (rxLengthCount != 0) {
      uVar2 = RAIL_ReadRxFifo(currentRxFifoPacketPtr,rxLengthCount);
      rxLengthCount = rxLengthCount - uVar2;
      currentRxFifoPacketPtr = currentRxFifoPacketPtr + uVar2;
    }
    rxFifoPacketInfo->dataLength = rxLengthTarget;
    RAIL_ReadRxFifoAppendedInfo(&rxFifoPacketInfo->appendedInfo);
    queueAdd(&rxPacketQueue,rxFifoPacketHandle);
  }
  return;
}



void rxFifoPrep(void)

{
  AppMode_t AVar1;
  
  if (((railDataConfig.rxMethod == FIFO_MODE) && (AVar1 = currentAppMode(), AVar1 != BER)) &&
     (rxFifoManual != true)) {
    rxLengthCount = rxLengthTarget;
    rxFifoPacketHandle = memoryAllocate((uint)rxLengthTarget);
    rxFifoPacketInfo = (RAIL_RxPacketInfo_t *)memoryPtrFromHandle(rxFifoPacketHandle);
    currentRxFifoPacketPtr = (uint8_t *)&rxFifoPacketInfo->field_0xa;
  }
  return;
}



void loadTxData(RAIL_TxData_t *transmitData)

{
  uint16_t uVar1;
  uint16_t dataWritten;
  
  if (railDataConfig.txMethod == PACKET_MODE) {
    RAIL_TxDataLoad(transmitData);
  }
  else {
    uVar1 = RAIL_WriteTxFifo(transmitData->dataPtr,transmitData->dataLength);
    dataLeft = transmitData->dataLength - uVar1;
    dataLeftPtr = transmitData->dataPtr + uVar1;
  }
  return;
}



void configRxLengthSetting(uint16_t rxLength)

{
  if (railDataConfig.rxMethod == FIFO_MODE) {
    rxLengthTarget = rxLength;
  }
  return;
}



void RAILCb_RxRadioStatusExt(uint32_t status)

{
  _Bool _Var1;
  
  if ((status & 0x10) != 0) {
    receivingPacket = false;
    counters.frameError = counters.frameError + 1;
    LedToggle(1);
  }
  if ((status & 4) != 0) {
    receivingPacket = true;
    counters.syncDetect = counters.syncDetect + 1;
    rxFifoPrep();
    if (abortRxDelay != 0) {
      RAIL_TimerSet(abortRxDelay,RAIL_TIME_DELAY);
    }
  }
  if ((status & 2) != 0) {
    counters.preambleDetect = counters.preambleDetect + 1;
  }
  if ((status & 0x20) != 0) {
    receivingPacket = false;
    counters.rxOfEvent = counters.rxOfEvent + 1;
  }
  if ((status & 1) != 0) {
    receivingPacket = false;
    counters.rxUfEvent = counters.rxUfEvent + 1;
  }
  if ((status & 0x40) != 0) {
    receivingPacket = false;
    counters.addrFilterEvent = counters.addrFilterEvent + 1;
  }
  if (((status & 0x80) != 0) &&
     (counters.rfSensedEvent = counters.rfSensedEvent + 1, counters.rfSensedEvent == 0)) {
    counters.rfSensedEvent = 1;
  }
  if ((status & 0x400) != 0) {
    counters.rxFail = counters.rxFail + 1;
  }
  if (((status & 0x200) != 0) ||
     (((schRxStopOnRxEvent != false && (_Var1 = inAppMode(RX_SCHEDULED,(char *)0x0), _Var1 != false)
       ) && (((status & 0x40) != 0 || (((status & 0x20) != 0 || ((status & 0x10) != 0)))))))) {
    enableAppMode(RX_SCHEDULED,false,(char *)0x0);
  }
  return;
}



void RAILCb_TxRadioStatus(uint8_t status)

{
  if ((status & 0x1f) != 0) {
    newTxError = true;
    failPackets = failPackets + 1;
    lastTxStatus = status;
    scheduleNextTx();
  }
  if ((status & 2) != 0) {
    counters.txUfEvent = counters.txUfEvent + 1;
  }
  if ((status & 1) != 0) {
    counters.txOfEvent = counters.txOfEvent + 1;
  }
  if ((status & 0x20) != 0) {
    counters.lbtSuccess = counters.lbtSuccess + 1;
  }
  if ((status & 0x40) != 0) {
    counters.lbtRetry = counters.lbtRetry + 1;
  }
  if ((char)status < '\0') {
    counters.lbtStartCca = counters.lbtStartCca + 1;
  }
  return;
}



void RAILCb_TxPacketSent(RAIL_TxPacketInfo_t *txPacketInfo)

{
  counters.transmit = counters.transmit + 1;
  internalTransmitCounter = internalTransmitCounter + 1;
  LedToggle(1);
  redrawDisplay = true;
  previousTxTime = txPacketInfo->timeUs;
  scheduleNextTx();
  return;
}



void RAILCb_RxPacketReceived(void *rxPacketHandle)

{
  counters.receive = counters.receive + 1;
  LedToggle(0);
  if (railDataConfig.rxMethod == PACKET_MODE) {
    packetMode_RxPacketReceived(rxPacketHandle);
  }
  else {
    if (rxFifoManual != true) {
      fifoMode_RxPacketReceived();
    }
  }
  return;
}



void RAILCb_TxFifoAlmostEmpty(uint16_t spaceAvailable)

{
  uint16_t uVar1;
  uint16_t dataWritten;
  
  counters.txFifoAlmostEmpty = counters.txFifoAlmostEmpty + 1;
  if (dataLeft != 0) {
    uVar1 = RAIL_WriteTxFifo(dataLeftPtr,dataLeft);
    dataLeft = dataLeft - uVar1;
    dataLeftPtr = dataLeftPtr + uVar1;
  }
  return;
}



void berGetStats(RAIL_BerStatus_t *status)

{
  uint32_t uVar1;
  uint32_t uVar2;
  int8_t iVar3;
  
  iVar3 = berStats.rssi;
  uVar2 = berStats.bitErrors;
  uVar1 = berStats.bitsTested;
  status->bitsTotal = berStats.bitsTotal;
  status->bitsTested = uVar1;
  status->bitErrors = uVar2;
  status->rssi = iVar3;
  return;
}



void berResetStats(uint32_t numBytes)

{
  uint32_t local_c;
  
  if ((numBytes == 0) || (local_c = numBytes, 0x1fffffff < numBytes)) {
    local_c = 0x1fffffff;
  }
  berStats.bitsTotal = local_c << 3;
  berStats.bitsTested = 0;
  berStats.bitErrors = 0;
  berStats.rssi = '\0';
  berTotalErrors = 0;
  berTotalBits = 0;
  berTotalBytesLeft = local_c;
  return;
}



uint8_t countBits(uint8_t num)

{
  uint8_t count;
  
  return ""[num & 0xf] + ""[num >> 4];
}



void berSource_RxFifoAlmostFull(uint16_t bytesAvailable)

{
  byte bVar1;
  int16_t iVar2;
  uint16_t uVar3;
  uint16_t uVar4;
  uint8_t byteValue;
  uint16_t numBytes;
  _Bool stopBerRx;
  
  stopBerRx = false;
  do {
    numBytes = RAIL_ReadRxFifo(&byteValue,1);
    if (numBytes != 0) {
      if (berTotalBytesLeft == 0) {
        stopBerRx = true;
      }
      else {
        bVar1 = countBits(byteValue);
        berTotalErrors = berTotalErrors + bVar1;
        berTotalBits = berTotalBits + 8;
        iVar2 = RAIL_RxGetRSSI();
        berStats.rssi = (int8_t)(iVar2 >> 2);
        berTotalBytesLeft = berTotalBytesLeft - 1;
      }
    }
    uVar3 = RAIL_GetRxFifoBytesAvailable();
    uVar4 = RAIL_GetRxFifoThreshold();
  } while ((uVar4 < uVar3) && (stopBerRx != true));
  if (berTotalBits < berStats.bitsTested) {
    berStats.bitsTested = 0xffffffff;
  }
  else {
    berStats.bitsTested = berTotalBits;
  }
  if (berTotalErrors < berStats.bitErrors) {
    berStats.bitErrors = 0xffffffff;
  }
  else {
    berStats.bitErrors = berTotalErrors;
  }
  if (stopBerRx != false) {
    RAIL_RfIdleExt(1,true);
    RAIL_ResetFifo(true,true);
  }
  return;
}



void packetSource_RxFifoAlmostFull(uint16_t bytesAvailable)

{
  uint16_t uVar1;
  uint16_t readLength;
  uint16_t bytesRead;
  
  if (rxLengthCount != 0) {
    readLength = rxLengthCount;
    if (bytesAvailable <= rxLengthCount) {
      readLength = bytesAvailable;
    }
    uVar1 = RAIL_ReadRxFifo(currentRxFifoPacketPtr,readLength);
    rxLengthCount = rxLengthCount - uVar1;
    currentRxFifoPacketPtr = currentRxFifoPacketPtr + uVar1;
  }
  return;
}



void RAILCb_RxFifoAlmostFull(uint16_t bytesAvailable)

{
  counters.rxFifoAlmostFull = counters.rxFifoAlmostFull + 1;
  if (berTestModeEnabled == false) {
    packetSource_RxFifoAlmostFull(bytesAvailable);
  }
  else {
    berSource_RxFifoAlmostFull(bytesAvailable);
  }
  return;
}



_Bool inAppMode(AppMode_t appMode,char *command)

{
  AppMode_t AVar1;
  char *pcVar2;
  _Bool ret;
  
  AVar1 = currentAppMode();
  if ((appMode != AVar1) && (command != (char *)0x0)) {
    pcVar2 = appModeNames(appMode);
    responsePrintError(command,'\x16',"Need to be in %s mode for this command",pcVar2);
  }
  return (_Bool)(appMode == AVar1);
}



_Bool inRadioState(RAIL_RadioState_t state,char *command)

{
  RAIL_RadioState_t RVar1;
  _Bool ret;
  
  RVar1 = RAIL_RfStateGet();
  if ((state != RVar1) && (command != (char *)0x0)) {
    responsePrintError(command,'\x17',"Need to be in %s radio state for this command",
                       rfStateNames[state]);
  }
  return (_Bool)(state == RVar1);
}



void setNextAppMode(AppMode_t next,char *command)

{
  AppMode_t next_00;
  
  if (next == NONE) {
    next_00 = currentAppMode();
    enableAppMode(next_00,false,command);
  }
  else {
    enableAppMode(next,true,command);
  }
  return;
}



_Bool enableAppModeSync(AppMode_t mode,_Bool enable,char *command)

{
  _Bool _Var1;
  
  changeAppModeIfPending();
  enableAppMode(mode,enable,command);
  changeAppModeIfPending();
  if (enable == false) {
    mode = NONE;
  }
  _Var1 = inAppMode(mode,(char *)0x0);
  return _Var1;
}



void scheduleNextTx(void)

{
  AppMode_t AVar1;
  
  if ((txCount < 1) && (AVar1 = currentAppMode(), AVar1 != TX_CONTINUOUS)) {
    AVar1 = currentAppMode();
    if ((AVar1 == TX_N_PACKETS) ||
       (((AVar1 = currentAppMode(), AVar1 == TX_SCHEDULED ||
         (AVar1 = currentAppMode(), AVar1 == TX_UNDERFLOW)) ||
        (AVar1 = currentAppMode(), AVar1 == TX_CANCEL)))) {
      setNextAppMode(NONE,(char *)0x0);
    }
    else {
      pendFinishTxSequence();
    }
  }
  else {
    RAIL_TimerSet(continuousTransferPeriod * 1000,RAIL_TIME_DELAY);
  }
  return;
}



void radioTransmit(uint32_t iterations,char *command)

{
  AppMode_t AVar1;
  
  txCount = iterations;
  if (iterations == 0) {
    AVar1 = currentAppMode();
    if (((AVar1 == TX_N_PACKETS) || (AVar1 = currentAppMode(), AVar1 == TX_CONTINUOUS)) ||
       (AVar1 = currentAppMode(), AVar1 == TX_UNDERFLOW)) {
      setNextAppMode(NONE,command);
    }
    else {
      setNextAppMode(TX_CONTINUOUS,command);
    }
  }
  else {
    AVar1 = currentAppMode();
    if (AVar1 == TX_UNDERFLOW) {
      setNextAppMode(TX_UNDERFLOW,command);
      pendPacketTx();
    }
    else {
      setNextAppMode(TX_N_PACKETS,command);
    }
  }
  return;
}



void * memoryAllocate(uint32_t size)

{
  CORE_irqState_t irqState_00;
  CORE_irqState_t irqState;
  void *handle;
  uint32_t i;
  
  handle = (void *)0xffffffff;
  if (size < 0x101) {
    irqState_00 = CORE_EnterCritical();
    for (i = 0; i < 10; i = i + 1) {
      if (memoryObjs[i].refCount == '\0') {
        memoryObjs[i].refCount = '\x01';
        handle = (void *)i;
        break;
      }
    }
    CORE_ExitCritical(irqState_00);
  }
  else {
    handle = (void *)0xffffffff;
  }
  return handle;
}



void * memoryPtrFromHandle(void *handle)

{
  CORE_irqState_t irqState_00;
  CORE_irqState_t irqState;
  void *ptr;
  
  ptr = (void *)0x0;
  if ((handle == (void *)0xffffffff) || ((void *)0xa < handle)) {
    ptr = (void *)0x0;
  }
  else {
    irqState_00 = CORE_EnterCritical();
    if (memoryObjs[(int)handle].refCount != '\0') {
      ptr = memoryObjs[(int)handle].data;
    }
    CORE_ExitCritical(irqState_00);
  }
  return ptr;
}



void memoryFree(void *handle)

{
  CORE_irqState_t irqState_00;
  void *pvVar1;
  CORE_irqState_t irqState;
  
  irqState_00 = CORE_EnterCritical();
  pvVar1 = memoryPtrFromHandle(handle);
  if (pvVar1 != (void *)0x0) {
    memoryObjs[(int)handle].refCount = memoryObjs[(int)handle].refCount + 0xff;
  }
  CORE_ExitCritical(irqState_00);
  return;
}



void memoryTakeReference(void *handle)

{
  CORE_irqState_t irqState_00;
  void *pvVar1;
  CORE_irqState_t irqState;
  
  irqState_00 = CORE_EnterCritical();
  pvVar1 = memoryPtrFromHandle(handle);
  if (pvVar1 != (void *)0x0) {
    memoryObjs[(int)handle].refCount = memoryObjs[(int)handle].refCount + '\x01';
  }
  CORE_ExitCritical(irqState_00);
  return;
}



void * RAILCb_AllocateMemory(uint32_t size)

{
  void *pvVar1;
  
  pvVar1 = memoryAllocate(size);
  return pvVar1;
}



void RAILCb_FreeMemory(void *ptr)

{
  memoryFree(ptr);
  return;
}



void * RAILCb_BeginWriteMemory(void *handle,uint32_t offset,uint32_t *available)

{
  void *pvVar1;
  
  pvVar1 = memoryPtrFromHandle(handle);
  return (void *)(offset + (int)pvVar1);
}



void RAILCb_EndWriteMemory(void *handle,uint32_t offset,uint32_t size)

{
  return;
}



_Bool queueInit(Queue_t *queue,uint16_t size)

{
  CORE_irqState_t irqState_00;
  _Bool _Var1;
  CORE_irqState_t irqState;
  
  if ((size < 0xb) && (queue != (Queue_t *)0x0)) {
    irqState_00 = CORE_EnterCritical();
    queue->size = size;
    queue->head = 0;
    queue->count = 0;
    CORE_ExitCritical(irqState_00);
    _Var1 = true;
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}



_Bool queueAdd(Queue_t *queue,void *data)

{
  CORE_irqState_t irqState_00;
  _Bool _Var1;
  uint uVar2;
  uint16_t index;
  CORE_irqState_t irqState;
  
  if (queue == (Queue_t *)0x0) {
    _Var1 = false;
  }
  else {
    irqState_00 = CORE_EnterCritical();
    if (queue->count < queue->size) {
      uVar2 = (uint)queue->count + (uint)queue->head;
      queue->data[(ushort)((short)uVar2 - queue->size * (short)(uVar2 / queue->size))] = data;
      queue->count = queue->count + 1;
    }
    else {
      queue->data[queue->head] = data;
      uVar2 = queue->head + 1;
      queue->head = (short)uVar2 - queue->size * (short)(uVar2 / queue->size);
    }
    CORE_ExitCritical(irqState_00);
    _Var1 = true;
  }
  return _Var1;
}



void * queueRemove(Queue_t *queue)

{
  CORE_irqState_t irqState_00;
  uint uVar1;
  CORE_irqState_t irqState;
  void *ptr;
  
  ptr = (void *)0x0;
  if (queue == (Queue_t *)0x0) {
    ptr = (void *)0x0;
  }
  else {
    irqState_00 = CORE_EnterCritical();
    if (queue->count != 0) {
      ptr = queue->data[queue->head];
      uVar1 = queue->head + 1;
      queue->head = (short)uVar1 - queue->size * (short)(uVar1 / queue->size);
      queue->count = queue->count - 1;
    }
    CORE_ExitCritical(irqState_00);
  }
  return ptr;
}



_Bool queueIsEmpty(Queue_t *queue)

{
  CORE_irqState_t irqState_00;
  undefined uVar1;
  bool bVar3;
  _Bool result;
  CORE_irqState_t irqState;
  uint16_t uVar2;
  
  if (queue == (Queue_t *)0x0) {
    uVar1 = 1;
  }
  else {
    irqState_00 = CORE_EnterCritical();
    uVar2 = queue->count;
    bVar3 = uVar2 == 0;
    if (bVar3) {
      uVar2 = 1;
    }
    uVar1 = (undefined)uVar2;
    if (!bVar3) {
      uVar1 = 0;
    }
    CORE_ExitCritical(irqState_00);
  }
  return (_Bool)uVar1;
}



_Bool ciPrintHelp(CommandEntry_t *commands)

{
  size_t sVar1;
  CommandEntry_t *local_24;
  int commandLen;
  CommandEntry_t *head;
  char *arguments;
  int argstrLen;
  int column1Width;
  int column0Width;
  
  column0Width = 0;
  column1Width = 0;
  for (local_24 = commands;
      (local_24 != (CommandEntry_t *)0x0 && (local_24->command != (char *)0x0));
      local_24 = local_24 + 1) {
    sVar1 = strlen(local_24->command);
    if (local_24->arguments == (char *)0x0) {
      argstrLen = 0;
    }
    else {
      argstrLen = strlen(local_24->arguments);
    }
    if ((int)sVar1 < column0Width) {
      sVar1 = column0Width;
    }
    if (argstrLen < column1Width) {
      argstrLen = column1Width;
    }
    column1Width = argstrLen;
    column0Width = sVar1;
  }
  puts("<command> <args> <help text>");
  puts("  u=uint8, v=uint16, w=uint32, s=int32, b=string, ?=Anything, *=0 or more of previous");
  for (local_24 = commands;
      (local_24 != (CommandEntry_t *)0x0 && (local_24->command != (char *)0x0));
      local_24 = local_24 + 1) {
    arguments = "";
    if (local_24->callback == FUN_00000000) {
      iprintf(" --- %s ---",local_24->command);
    }
    else {
      iprintf("%*s",-column0Width,local_24->command);
      if ((local_24->arguments != (char *)0x0) && (*local_24->arguments != '\0')) {
        arguments = local_24->arguments;
      }
      iprintf(" %*s",-column1Width,arguments);
      if ((local_24->helpStr != (char *)0x0) && (*local_24->helpStr != '\0')) {
        iprintf(" %s",local_24->helpStr);
      }
    }
    putchar(10);
  }
  return true;
}



uint8_t ciInitState(CommandState_t *state,char *buffer,uint32_t length,CommandEntry_t *commands)

{
  uint8_t uVar1;
  
  if ((state == (CommandState_t *)0x0) || (buffer == (char *)0x0)) {
    uVar1 = '\x01';
  }
  else {
    state->buffer = buffer;
    state->offset = 0;
    state->length = length;
    state->commands = commands;
    state->prevEol = '\0';
    uVar1 = '\0';
  }
  return uVar1;
}



int8_t ciProcessInput(CommandState_t *state,char *data,uint32_t length)

{
  char cVar1;
  char eolChar;
  int8_t rval;
  uint32_t start;
  uint32_t i;
  
  rval = '\0';
  if ((state == (CommandState_t *)0x0) || (data == (char *)0x0)) {
    rval = -1;
  }
  else {
    if (state->offset + length < state->length) {
      i = state->offset;
      memcpy(state->buffer + state->offset,data,length);
      state->offset = state->offset + length;
      start = 0;
      for (; i < state->offset; i = i + 1) {
        if ((state->buffer[i] == '\n') || (state->buffer[i] == '\r')) {
          cVar1 = state->buffer[i];
          state->buffer[i] = '\0';
          if (i != start) {
            processCommand(state->commands,state->buffer + start);
          }
          if (((cVar1 != '\n') || (state->prevEol != '\r')) || (i != start)) {
            rval = rval + '\x01';
          }
          start = i + 1;
          state->prevEol = cVar1;
        }
      }
      if (start != 0) {
        state->offset = state->offset - start;
        memmove(state->buffer,state->buffer + start,state->offset);
      }
    }
    else {
      rval = -2;
    }
  }
  return rval;
}



uint32_t ciGetUnsigned(char *arg)

{
  ulong uVar1;
  
  uVar1 = strtoul(arg,(char **)0x0,0);
  return uVar1;
}



int32_t ciGetSigned(char *arg)

{
  long lVar1;
  
  lVar1 = strtol(arg,(char **)0x0,0);
  return lVar1;
}



_Bool ciValidateInteger(char *arg,char type)

{
  _Bool _Var1;
  int length;
  _Bool isSigned;
  
  isSigned = false;
  switch(type) {
  case 's':
    length = 4;
    isSigned = true;
    break;
  default:
    return false;
  case 'u':
    length = 1;
    break;
  case 'v':
    length = 2;
    break;
  case 'w':
    length = 4;
  }
  _Var1 = validateInteger(arg,length,isSigned);
  return _Var1;
}



void parseBackspaces(char *buffer)

{
  char *rd;
  char *wr;
  
  wr = buffer;
  for (rd = buffer; *rd != '\0'; rd = rd + 1) {
    if (*rd == '\b') {
      if (buffer < wr) {
        wr = wr + -1;
      }
    }
    else {
      *wr = *rd;
      wr = wr + 1;
    }
  }
  *wr = '\0';
  return;
}



_Bool processCommand(CommandEntry_t *commands,char *buffer)

{
  _Bool _Var1;
  int iVar2;
  CommandEntry_t *local_74;
  char *argv [20];
  char *saveptr;
  CommandEntry_t *commandListStart;
  int argc;
  char *token;
  _Bool success;
  
  success = false;
  commandListStart = commands;
  parseBackspaces(buffer);
  token = strtok_r(buffer,"\n\r ",&saveptr);
  local_74 = commands;
  if (token == (char *)0x0) {
    return true;
  }
  while( true ) {
    if ((local_74 == (CommandEntry_t *)0x0) || (local_74->command == (char *)0x0))
    goto LAB_00006bcc;
    argc = 0;
    if ((local_74->callback != FUN_00000000) &&
       (iVar2 = strcasecmp(token,local_74->command), iVar2 == 0)) break;
    local_74 = local_74 + 1;
  }
  argv[argc] = local_74->command;
  argc = argc + 1;
  token = strtok_r((char *)0x0,"\n\r ",&saveptr);
  while (token != (char *)0x0) {
    argv[argc] = token;
    argc = argc + 1;
    if (0x13 < argc) {
      ciErrorCallback(buffer,CI_MAX_ARGUMENTS);
      return false;
    }
    token = strtok_r((char *)0x0,"\n\r ",&saveptr);
  }
  _Var1 = validateArguments(local_74->arguments,argc + -1,argv + 1);
  if (_Var1 != true) {
    ciErrorCallback(buffer,CI_INVALID_ARGUMENTS);
    return false;
  }
  (*local_74->callback)(argc,argv);
  success = true;
LAB_00006bcc:
  if ((((local_74 == (CommandEntry_t *)0x0) || (local_74->command == (char *)0x0)) &&
      (commandListStart != (CommandEntry_t *)0x0)) &&
     (iVar2 = strcasecmp(buffer,"help"), iVar2 == 0)) {
    success = ciPrintHelp(commandListStart);
  }
  if (success != true) {
    ciErrorCallback(token,CI_UNKNOWN_COMMAND);
  }
  return success;
}



_Bool validateArguments(char *argstring,int argc,char **argv)

{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  undefined uVar4;
  char *loc;
  int argstringLen;
  _Bool isValid;
  int i;
  char argType;
  int minArgs;
  
  argType = '.';
  if ((argstring == (char *)0x0) || (iVar1 = strcmp(argstring,"?"), iVar1 == 0)) {
    uVar4 = 1;
  }
  else {
    sVar2 = strlen(argstring);
    pcVar3 = strchr(argstring,0x2a);
    minArgs = sVar2;
    if (pcVar3 != (char *)0x0) {
      if ((pcVar3 != argstring + (sVar2 - 1)) || (sVar2 == 1)) {
        return false;
      }
      minArgs = sVar2 - 2;
    }
    for (i = 0; i < argc; i = i + 1) {
      if (i < (int)sVar2) {
        if (argstring[i] != '*') {
          argType = argstring[i];
        }
      }
      else {
        if (argstring[sVar2 - 1] != '*') {
          return false;
        }
      }
      switch(argType) {
      case 'b':
        isValid = true;
        break;
      default:
        isValid = false;
        break;
      case 's':
        isValid = validateInteger(argv[i],4,true);
        break;
      case 'u':
        isValid = validateInteger(argv[i],1,false);
        break;
      case 'v':
        isValid = validateInteger(argv[i],2,false);
        break;
      case 'w':
        isValid = validateInteger(argv[i],4,false);
      }
      if (isValid != true) {
        return false;
      }
    }
    iVar1 = minArgs;
    if (minArgs <= argc) {
      iVar1 = 1;
    }
    uVar4 = (undefined)iVar1;
    if (argc < minArgs) {
      uVar4 = 0;
    }
  }
  return (_Bool)uVar4;
}



_Bool validateInteger(char *str,int lengthInBytes,_Bool isSigned)

{
  undefined4 *puVar1;
  int *piVar2;
  size_t sVar3;
  _Bool _Var4;
  char *endptr;
  uint32_t val;
  uint32_t mask;
  
  if (isSigned == false) {
    mask = (1 << ((lengthInBytes & 0x1fU) << 3)) - 1;
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0;
    val = strtoul(str,&endptr,0);
    if (val != (mask & val)) {
      return false;
    }
  }
  else {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0;
    strtol(str,&endptr,0);
  }
  piVar2 = (int *)__errno();
  if ((*piVar2 == 0) && (sVar3 = strlen(str), (int)endptr - (int)str == sVar3)) {
    _Var4 = true;
  }
  else {
    _Var4 = false;
  }
  return _Var4;
}



// WARNING: Could not reconcile some variable overlaps

int BSP_BccInit(void)

{
  USART_InitAsync_TypeDef usartInit;
  
  usartInit._0_4_ = 5;
  usartInit.refFreq = 0;
  usartInit.baudrate = (uint32_t)&DAT_0001c200;
  usartInit._12_4_ = 0x500;
  usartInit._16_4_ = 0x1000;
  usartInit._20_4_ = 0;
  rxByteCount = 0;
  txByteCount = 0;
  CMU_ClockEnable(cmuClock_HFPER,true);
  CMU_ClockEnable(cmuClock_GPIO,true);
  CMU_ClockEnable(cmuClock_USART0,true);
  USART_InitAsync((USART_TypeDef *)&Peripherals::USART0,&usartInit);
  BSP_BccPinsEnable(true);
  return 0;
}



void BSP_BccPinsEnable(_Bool enable)

{
  uint uVar1;
  
  if (enable == false) {
    GPIO_PinModeSet(gpioPortA,5,gpioModeDisabled,0);
    uVar1 = (Peripherals::USART0.ROUTEPEN);
    write_volatile_4(Peripherals::USART0.ROUTEPEN,uVar1 & 0xfffffffc);
    GPIO_PinModeSet(gpioPortA,0,gpioModeDisabled,0);
    GPIO_PinModeSet(gpioPortA,1,gpioModeDisabled,0);
  }
  else {
    GPIO_PinModeSet(gpioPortA,0,gpioModePushPull,1);
    GPIO_PinModeSet(gpioPortA,1,gpioModeInput,1);
    GPIO_PinModeSet(gpioPortA,5,gpioModePushPull,1);
    write_volatile_4(Peripherals::USART0.ROUTEPEN,3);
    uVar1 = (Peripherals::USART0.ROUTELOC0);
    write_volatile_4(Peripherals::USART0.ROUTELOC0,uVar1 & 0xffffe0e0);
  }
  return;
}



int BSP_Init(uint32_t flags)

{
  if ((flags & 4) != 0) {
    BSP_BccInit();
  }
  return 0;
}



void BUS_RegBitWrite(uint32_t *addr,uint bit,uint val)

{
  uint32_t aliasAddr;
  
  *(uint *)((bit + (int)(addr + 0x840000) * 8) * 4) = val;
  return;
}



void GPIO_PinOutClear(GPIO_Port_TypeDef port,uint pin)

{
  BUS_RegBitWrite(&Peripherals::GPIO.PA_DOUT + (uint)port * 0xc,pin,0);
  return;
}



void GPIO_PinOutSet(GPIO_Port_TypeDef port,uint pin)

{
  BUS_RegBitWrite(&Peripherals::GPIO.PA_DOUT + (uint)port * 0xc,pin,1);
  return;
}



void GPIO_PinOutToggle(GPIO_Port_TypeDef port,uint pin)

{
  (&Peripherals::GPIO.PA_DOUTTGL)[(uint)port * 0xc] = 1 << (pin & 0xff);
  return;
}



int BSP_LedsInit(void)

{
  int i;
  
  CMU_ClockEnable(cmuClock_HFPER,true);
  CMU_ClockEnable(cmuClock_GPIO,true);
  for (i = 0; i < 2; i = i + 1) {
    GPIO_PinModeSet(ledArray[i].port,ledArray[i].pin,gpioModePushPull,0);
  }
  return 0;
}



int BSP_LedClear(int ledNo)

{
  int iVar1;
  
  if ((ledNo < 0) || (1 < ledNo)) {
    iVar1 = -1;
  }
  else {
    GPIO_PinOutClear(ledArray[ledNo].port,ledArray[ledNo].pin);
    iVar1 = 0;
  }
  return iVar1;
}



int BSP_LedSet(int ledNo)

{
  int iVar1;
  
  if ((ledNo < 0) || (1 < ledNo)) {
    iVar1 = -1;
  }
  else {
    GPIO_PinOutSet(ledArray[ledNo].port,ledArray[ledNo].pin);
    iVar1 = 0;
  }
  return iVar1;
}



int BSP_LedToggle(int ledNo)

{
  int iVar1;
  
  if ((ledNo < 0) || (1 < ledNo)) {
    iVar1 = -1;
  }
  else {
    GPIO_PinOutToggle(ledArray[ledNo].port,ledArray[ledNo].pin);
    iVar1 = 0;
  }
  return iVar1;
}



void BUS_RegBitWrite(uint32_t *addr,uint bit,uint val)

{
  uint32_t aliasAddr;
  
  *(uint *)((bit + (int)(addr + 0x840000) * 8) * 4) = val;
  return;
}



uint BUS_RegBitRead(uint32_t *addr,uint bit)

{
  uint32_t aliasAddr;
  
  return *(uint *)((bit + (int)(addr + 0x840000) * 8) * 4);
}



void BUS_RegMaskedSet(uint32_t *addr,uint32_t mask)

{
  uint32_t aliasAddr;
  
  addr[0x1800000] = mask;
  return;
}



void BUS_RegMaskedClear(uint32_t *addr,uint32_t mask)

{
  uint32_t aliasAddr;
  
  addr[0x1000000] = mask;
  return;
}



void BUS_RegMaskedWrite(uint32_t *addr,uint32_t mask,uint32_t val)

{
  BUS_RegMaskedClear(addr,mask);
  BUS_RegMaskedSet(addr,val);
  return;
}



uint32_t BUS_RegMaskedRead(uint32_t *addr,uint32_t mask)

{
  return mask & *addr;
}



uint32_t CMU_Log2ToDiv(uint32_t log2)

{
  return 1 << (log2 & 0xff);
}



uint32_t CMU_PrescToLog2(CMU_ClkPresc_TypeDef presc)

{
  int iVar1;
  uint32_t log2;
  
  iVar1 = count_leading_zeroes(presc + 1);
  CMU_Log2ToDiv(0x1fU - iVar1);
  return 0x1fU - iVar1;
}



void setHfLeConfig(uint32_t hfFreq,uint32_t maxLeFreq)

{
  byte bVar1;
  uint32_t uVar2;
  uint val;
  
  uVar2 = maxLeFreq;
  if (maxLeFreq < hfFreq) {
    uVar2 = 1;
  }
  bVar1 = (byte)uVar2;
  if (hfFreq <= maxLeFreq) {
    bVar1 = 0;
  }
  BUS_RegBitWrite(&CMU->CTRL,0x10,(uint)bVar1);
  BUS_RegBitWrite(&CMU->HFPRESC,0x18,(uint)bVar1);
  return;
}



uint32_t getHfLeConfig(void)

{
  uint uVar1;
  uint32_t presc;
  uint32_t ws;
  
  uVar1 = BUS_RegBitRead(&CMU->CTRL,0x10);
  BUS_RegBitRead(&CMU->HFPRESC,0x18);
  return uVar1;
}



uint32_t auxClkGet(void)

{
  uint32_t ret;
  
  return auxHfrcoFreq;
}



uint32_t dbgClkGet(void)

{
  CMU_Select_TypeDef CVar1;
  CMU_Select_TypeDef clk;
  uint32_t ret;
  
  CVar1 = CMU_ClockSelectGet(cmuClock_DBG);
  if (CVar1 == cmuSelect_AUXHFRCO) {
    ret = auxClkGet();
  }
  else {
    if (CVar1 == cmuSelect_HFCLK) {
      ret = SystemHFClockGet();
    }
    else {
      ret = 0;
    }
  }
  return ret;
}



void flashWaitStateControl(uint32_t coreFreq)

{
  char cVar1;
  uint uVar2;
  bool bVar3;
  _Bool mscLocked;
  uint32_t mode;
  
  uVar2 = (Peripherals::MSC.LOCK);
  bVar3 = uVar2 != 0;
  if (bVar3) {
    uVar2 = 1;
  }
  cVar1 = (char)uVar2;
  if (!bVar3) {
    cVar1 = '\0';
  }
  write_volatile_4(Peripherals::MSC.LOCK,0x1b71);
  read_volatile(Peripherals::MSC.READCTRL._0_1_);
  if ((coreFreq < 0x2625a01) && (26000000 < coreFreq)) {
    mode = 0x1000000;
  }
  else {
    mode = 0;
  }
  uVar2 = (Peripherals::MSC.READCTRL);
  write_volatile_4(Peripherals::MSC.READCTRL,mode | uVar2 & 0xfcffffff);
  if (cVar1 != '\0') {
    write_volatile_4(Peripherals::MSC.LOCK,0);
  }
  return;
}



void flashWaitStateMax(void)

{
  uint32_t coreFreq;
  
  coreFreq = SystemMaxCoreClockGet();
  flashWaitStateControl(coreFreq);
  return;
}



uint32_t getRegIshUpperVal(uint32_t steadyStateRegIsh)

{
  uint uVar1;
  uint32_t regIshUpper;
  uint32_t _b;
  ulong _a;
  uint32_t upperMax;
  
  uVar1 = steadyStateRegIsh + 3;
  if (0xe < steadyStateRegIsh + 3) {
    uVar1 = 0xf;
  }
  return uVar1 << 0x1c;
}



uint32_t lfClkGet(CMU_Clock_TypeDef lfClkBranch)

{
  uint uVar1;
  CMU_Select_TypeDef CVar2;
  uint32_t uVar3;
  uint32_t ret;
  uint32_t sel;
  
  ret = 0;
  CVar2 = CMU_ClockSelectGet(lfClkBranch);
  sel = (uint32_t)CVar2;
  if (lfClkBranch == cmuClock_LFB) {
    uVar1 = (CMU->LFBCLKSEL);
    sel = uVar1 & 7;
  }
  else {
    if (lfClkBranch == cmuClock_LFE) {
      uVar1 = (CMU->LFECLKSEL);
      sel = uVar1 & 7;
    }
    else {
      if (lfClkBranch == cmuClock_LFA) {
        uVar1 = (CMU->LFACLKSEL);
        sel = uVar1 & 7;
      }
    }
  }
  switch(sel) {
  case 0:
    ret = 0;
    break;
  case 1:
    ret = SystemLFRCOClockGet();
    break;
  case 2:
    ret = SystemLFXOClockGet();
    break;
  case 3:
    uVar1 = (CMU->HFPRESC);
    if ((uVar1 & 0x1000000) == 0x1000000) {
      uVar3 = SystemCoreClockGet();
      ret = uVar3 >> 2;
    }
    else {
      uVar3 = SystemCoreClockGet();
      ret = uVar3 >> 1;
    }
    break;
  case 4:
    ret = SystemULFRCOClockGet();
  }
  return ret;
}



void syncReg(uint32_t mask)

{
  uint uVar1;
  
  uVar1 = (CMU->FREEZE);
  if ((uVar1 & 1) == 0) {
    do {
      uVar1 = (CMU->SYNCBUSY);
    } while ((mask & uVar1) != 0);
  }
  return;
}



CMU_ClkDiv_TypeDef CMU_ClockDivGet(CMU_Clock_TypeDef clock)

{
  uint32_t uVar1;
  
  uVar1 = CMU_ClockPrescGet(clock);
  return uVar1 + 1;
}



void CMU_ClockDivSet(CMU_Clock_TypeDef clock,CMU_ClkDiv_TypeDef div)

{
  CMU_ClockPrescSet(clock,div - 1);
  return;
}



void CMU_ClockEnable(CMU_Clock_TypeDef clock,_Bool enable)

{
  uint32_t bit;
  uint32_t sync;
  uint32_t *reg;
  
  sync = 0;
  switch(clock >> 8 & 0xf) {
  case 1:
    reg = (uint32_t *)&Peripherals::CMU;
    break;
  case 2:
    reg = &CMU->HFPERCLKEN0;
    break;
  default:
    goto LAB_0000769a;
  case 5:
    reg = &CMU->HFBUSCLKEN0;
    break;
  case 6:
    reg = &CMU->LFACLKEN0;
    sync = 1;
    break;
  case 7:
    reg = &CMU->LFBCLKEN0;
    sync = 0x10;
    break;
  case 9:
    reg = &CMU->LFECLKEN0;
    sync = 0x10000;
    break;
  case 10:
    reg = &CMU->PCNTCTRL;
  }
  if (sync != 0) {
    syncReg(sync);
  }
  BUS_RegBitWrite(reg,clock >> 0xc & 0x1f,(uint)enable);
LAB_0000769a:
  return;
}



uint32_t CMU_ClockFreqGet(CMU_Clock_TypeDef clock)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint uVar3;
  uint32_t ret;
  
  uVar3 = clock & 0x3e0000;
  if (uVar3 == 0xe0000) {
    uVar1 = auxClkGet();
    return uVar1;
  }
  if (uVar3 < 0xe0001) {
    if (uVar3 == 0x40000) {
      uVar1 = SystemHFClockGet();
      uVar3 = (CMU->HFPERPRESC);
      return uVar1 / ((uVar3 >> 8 & 0x1ff) + 1);
    }
    if (uVar3 < 0x40001) {
      if (uVar3 == 0) {
        uVar1 = SystemHFClockGet();
        return uVar1;
      }
      if (uVar3 == 0x20000) {
        uVar1 = SystemHFClockGet();
        uVar3 = (CMU->HFCOREPRESC);
        return uVar1 / ((uVar3 >> 8 & 0x1ff) + 1);
      }
    }
    else {
      if (uVar3 == 0xa0000) {
        uVar1 = SystemHFClockGet();
        uVar3 = (CMU->HFEXPPRESC);
        return uVar1 / ((uVar3 >> 8 & 0x1f) + 1);
      }
      if (uVar3 == 0xc0000) {
        uVar1 = dbgClkGet();
        return uVar1;
      }
      if (uVar3 == 0x80000) {
        uVar1 = SystemHFClockGet();
        return uVar1;
      }
    }
  }
  else {
    if (uVar3 == 0x160000) {
      uVar1 = lfClkGet(cmuClock_LFB);
      uVar3 = (CMU->LFBPRESC0);
      uVar2 = CMU_Log2ToDiv(uVar3 & 3);
      return uVar1 / uVar2;
    }
    if (uVar3 < 0x160001) {
      if (uVar3 == 0x120000) {
        uVar1 = lfClkGet(cmuClock_LFE);
        return uVar1;
      }
      if (uVar3 == 0x140000) {
        uVar1 = lfClkGet(cmuClock_LFA);
        uVar3 = (CMU->LFAPRESC0);
        uVar2 = CMU_Log2ToDiv(uVar3 & 0xf);
        return uVar1 / uVar2;
      }
    }
    else {
      if (uVar3 == 0x1c0000) {
        uVar1 = lfClkGet(cmuClock_LFB);
        return uVar1;
      }
      if (uVar3 == 0x200000) {
        uVar1 = lfClkGet(cmuClock_LFE);
        return uVar1;
      }
      if (uVar3 == 0x1a0000) {
        uVar1 = lfClkGet(cmuClock_LFA);
        return uVar1;
      }
    }
  }
  return 0;
}



uint32_t CMU_ClockPrescGet(CMU_Clock_TypeDef clock)

{
  uint uVar1;
  uint32_t uVar2;
  uint32_t prescReg;
  uint32_t ret;
  
  switch(clock >> 4 & 0xf) {
  case 1:
    uVar1 = (CMU->HFPRESC);
    ret = uVar1 >> 8 & 0x1f;
    break;
  case 2:
    uVar1 = (CMU->HFEXPPRESC);
    ret = uVar1 >> 8 & 0x1f;
    break;
  case 3:
    uVar1 = (CMU->HFPRESC);
    ret = uVar1 >> 0x18 & 1;
    break;
  case 4:
    uVar1 = (CMU->HFPERPRESC);
    ret = uVar1 >> 8 & 0x1ff;
    break;
  case 5:
    uVar1 = (CMU->HFCOREPRESC);
    ret = uVar1 >> 8 & 0x1ff;
    break;
  case 6:
    if (clock == cmuClock_LETIMER0) {
      uVar1 = (CMU->LFAPRESC0);
      uVar2 = CMU_Log2ToDiv(uVar1 & 0xf);
      ret = uVar2 - 1;
    }
    else {
      ret = 0;
    }
    break;
  case 7:
    if (clock == cmuClock_LEUART0) {
      uVar1 = (CMU->LFBPRESC0);
      uVar2 = CMU_Log2ToDiv(uVar1 & 3);
      ret = uVar2 - 1;
    }
    else {
      ret = 0;
    }
    break;
  case 8:
    ret = 0;
    break;
  default:
    ret = 0;
  }
  return ret;
}



void CMU_ClockPrescSet(CMU_Clock_TypeDef clock,CMU_ClkPresc_TypeDef presc)

{
  uint uVar1;
  uint32_t uVar2;
  uint32_t freq;
  uint32_t prescReg;
  
  switch(clock >> 4 & 0xf) {
  case 1:
    flashWaitStateMax();
    setHfLeConfig(0x1e84801,32000000);
    uVar1 = (CMU->HFPRESC);
    write_volatile_4(CMU->HFPRESC,presc << 8 | uVar1 & 0xffffe0ff);
    uVar2 = SystemCoreClockGet();
    flashWaitStateControl(uVar2);
    uVar2 = CMU_ClockFreqGet(cmuClock_HFLE);
    setHfLeConfig(uVar2,32000000);
    break;
  case 2:
    uVar1 = (CMU->HFEXPPRESC);
    write_volatile_4(CMU->HFEXPPRESC,presc << 8 | uVar1 & 0xffffe0ff);
    break;
  case 3:
    uVar1 = (CMU->HFPRESC);
    write_volatile_4(CMU->HFPRESC,presc << 0x18 | uVar1 & 0xfeffffff);
    break;
  case 4:
    uVar1 = (CMU->HFPERPRESC);
    write_volatile_4(CMU->HFPERPRESC,uVar1 & 0xfffe00ff | presc << 8);
    break;
  case 5:
    flashWaitStateMax();
    setHfLeConfig(0x1e84801,32000000);
    uVar1 = (CMU->HFCOREPRESC);
    write_volatile_4(CMU->HFCOREPRESC,uVar1 & 0xfffe00ff | presc << 8);
    uVar2 = SystemCoreClockGet();
    flashWaitStateControl(uVar2);
    uVar2 = CMU_ClockFreqGet(cmuClock_HFLE);
    setHfLeConfig(uVar2,32000000);
    break;
  case 6:
    if (clock == cmuClock_RTCC) {
      syncReg(0x40000);
      uVar1 = (CMU->LFEPRESC0);
      write_volatile_4(CMU->LFEPRESC0,presc | uVar1 & 0xfffffff0);
    }
    else {
      if (clock == cmuClock_LETIMER0) {
        uVar2 = CMU_PrescToLog2(presc);
        syncReg(4);
        uVar1 = (CMU->LFAPRESC0);
        write_volatile_4(CMU->LFAPRESC0,uVar2 | uVar1 & 0xfffffff0);
      }
    }
    break;
  case 7:
    if (clock == cmuClock_LEUART0) {
      uVar2 = CMU_PrescToLog2(presc);
      syncReg(0x40);
      uVar1 = (CMU->LFBPRESC0);
      write_volatile_4(CMU->LFBPRESC0,uVar2 | uVar1 & 0xfffffffc);
    }
    break;
  case 8:
    if (clock == cmuClock_RTCC) {
      syncReg(0x40000);
      uVar1 = (CMU->LFEPRESC0);
      write_volatile_4(CMU->LFEPRESC0,presc | uVar1 & 0xfffffff0);
    }
  }
  return;
}



CMU_Select_TypeDef CMU_ClockSelectGet(CMU_Clock_TypeDef clock)

{
  uint uVar1;
  uint32_t selReg;
  CMU_Select_TypeDef ret;
  
  ret = cmuSelect_Disabled;
  switch(clock & 0xf) {
  case 1:
    uVar1 = (CMU->HFCLKSTATUS);
    uVar1 = uVar1 & 7;
    if (uVar1 == 3) {
      ret = cmuSelect_LFRCO;
    }
    else {
      if (uVar1 == 4) {
        ret = cmuSelect_LFXO;
      }
      else {
        if (uVar1 == 2) {
          ret = cmuSelect_HFXO;
        }
        else {
          ret = cmuSelect_HFRCO;
        }
      }
    }
    break;
  case 2:
    uVar1 = (CMU->LFACLKSEL);
    uVar1 = uVar1 & 7;
    if (uVar1 == 2) {
      ret = cmuSelect_LFXO;
    }
    else {
      if (uVar1 == 4) {
        ret = cmuSelect_ULFRCO;
      }
      else {
        if (uVar1 == 1) {
          ret = cmuSelect_LFRCO;
        }
        else {
          ret = cmuSelect_Disabled;
        }
      }
    }
    break;
  case 3:
    uVar1 = (CMU->LFBCLKSEL);
    switch(uVar1 & 7) {
    case 1:
      ret = cmuSelect_LFRCO;
      break;
    case 2:
      ret = cmuSelect_LFXO;
      break;
    case 3:
      ret = cmuSelect_HFCLKLE;
      break;
    case 4:
      ret = cmuSelect_ULFRCO;
      break;
    default:
      ret = cmuSelect_Disabled;
    }
    break;
  default:
    ret = cmuSelect_Error;
    break;
  case 5:
    uVar1 = (CMU->LFECLKSEL);
    uVar1 = uVar1 & 7;
    if (uVar1 == 2) {
      ret = cmuSelect_LFXO;
    }
    else {
      if (uVar1 == 4) {
        ret = cmuSelect_ULFRCO;
      }
      else {
        if (uVar1 == 1) {
          ret = cmuSelect_LFRCO;
        }
        else {
          ret = cmuSelect_Disabled;
        }
      }
    }
    break;
  case 6:
    uVar1 = (CMU->DBGCLKSEL);
    if ((uVar1 & 1) == 0) {
      ret = cmuSelect_AUXHFRCO;
    }
    else {
      if ((uVar1 & 1) == 1) {
        ret = cmuSelect_HFCLK;
      }
    }
  }
  return ret;
}



// WARNING: Removing unreachable block (ram,0x00007d76)

void CMU_ClockSelectSet(CMU_Clock_TypeDef clock,CMU_Select_TypeDef ref)

{
  uint32_t uVar1;
  uint32_t freq;
  uint32_t selRegId;
  uint32_t *selReg;
  uint32_t tmp;
  CMU_Osc_TypeDef osc;
  uint32_t select;
  
  selReg = (uint32_t *)0x0;
  switch(clock & 0xf) {
  case 1:
    switch(ref) {
    case cmuSelect_LFXO:
      select = 4;
      osc = cmuOsc_LFXO;
      break;
    case cmuSelect_LFRCO:
      select = 3;
      osc = cmuOsc_LFRCO;
      break;
    case cmuSelect_HFXO:
      select = 2;
      osc = cmuOsc_HFXO;
      setHfLeConfig(0x1e84801,32000000);
      break;
    case cmuSelect_HFRCO:
      select = 1;
      osc = cmuOsc_HFRCO;
      setHfLeConfig(0x1e84801,32000000);
      break;
    default:
      goto LAB_00007e2c;
    }
    CMU_OscillatorEnable(osc,true,true);
    flashWaitStateMax();
    write_volatile_4(CMU->HFCLKSEL,select);
    uVar1 = CMU_ClockFreqGet(cmuClock_HFLE);
    setHfLeConfig(uVar1,32000000);
    uVar1 = SystemCoreClockGet();
    flashWaitStateControl(uVar1);
    break;
  case 2:
    selReg = &CMU->LFACLKSEL;
  case 5:
    if (selReg == (uint32_t *)0x0) {
      selReg = &CMU->LFECLKSEL;
    }
  case 3:
    goto switchD_00007cbc_caseD_3;
  }
LAB_00007e20:
  getHfLeConfig();
LAB_00007e2c:
  return;
switchD_00007cbc_caseD_3:
  if (selReg == (uint32_t *)0x0) {
    selReg = &CMU->LFBCLKSEL;
  }
  switch(ref) {
  case cmuSelect_Disabled:
    tmp = 0;
    break;
  case cmuSelect_LFXO:
    CMU_OscillatorEnable(cmuOsc_LFXO,true,true);
    tmp = 2;
    break;
  case cmuSelect_LFRCO:
    CMU_OscillatorEnable(cmuOsc_LFRCO,true,true);
    tmp = 1;
    break;
  default:
    goto LAB_00007e2c;
  case cmuSelect_HFCLKLE:
    uVar1 = SystemCoreClockGet();
    setHfLeConfig(uVar1,32000000);
    BUS_RegBitWrite(&CMU->HFBUSCLKEN0,0,1);
    tmp = 3;
    break;
  case cmuSelect_ULFRCO:
    tmp = 4;
  }
  *selReg = tmp;
  goto LAB_00007e20;
}



void CMU_HFXOInit(CMU_HFXOInit_TypeDef *hfxoInit)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  uint32_t uVar4;
  uint uVar5;
  uint32_t mode;
  
  CMU_ClockSelectGet(cmuClock_HF);
  CMU_OscillatorEnable(cmuOsc_HFXO,false,true);
  mode = (uint32_t)(hfxoInit->mode == cmuOscMode_External);
  if (hfxoInit->lowPowerMode == false) {
    uVar5 = 0;
  }
  else {
    uVar5 = 0x100;
  }
  BUS_RegMaskedWrite(&CMU->HFXOCTRL,0x101,mode | uVar5);
  BUS_RegMaskedWrite(&CMU->HFXOCTRL1,7,(uint)hfxoInit->thresholdPeakDetect);
  BUS_RegMaskedWrite(&CMU->HFXOSTARTUPCTRL,0xff87f,
                     (uint)hfxoInit->ctuneStartup << 0xb | (uint)hfxoInit->xoCoreBiasTrimStartup);
  uVar3 = hfxoInit->ctuneSteadyState;
  bVar1 = hfxoInit->regIshSteadyState;
  bVar2 = hfxoInit->xoCoreBiasTrimSteadyState;
  uVar4 = getRegIshUpperVal((uint)hfxoInit->regIshSteadyState);
  BUS_RegMaskedWrite(&CMU->HFXOSTEADYSTATECTRL,0xf00fffff,
                     uVar4 | (uint)bVar1 << 7 | (uint)uVar3 << 0xb | (uint)bVar2);
  BUS_RegMaskedWrite(&CMU->HFXOTIMEOUTCTRL,0xff0ff,
                     (uint)hfxoInit->timeoutSteady << 4 |
                     (uint)hfxoInit->timeoutShuntOptimization << 0x10 |
                     (uint)hfxoInit->timeoutPeakDetect << 0xc | (uint)hfxoInit->timeoutStartup);
  return;
}



void CMU_OscillatorEnable(CMU_Osc_TypeDef osc,_Bool enable,_Bool wait)

{
  bool bVar1;
  uint uVar2;
  uint32_t val;
  uint32_t hfxoTrimStatus;
  _Bool firstHfxoEnable;
  uint32_t disBit;
  uint32_t enBit;
  uint32_t ensBitPos;
  uint32_t rdyBitPos;
  
  switch(osc) {
  case cmuOsc_LFXO:
    enBit = 0x100;
    disBit = 0x200;
    rdyBitPos = 9;
    ensBitPos = 8;
    break;
  case cmuOsc_LFRCO:
    enBit = 0x40;
    disBit = 0x80;
    rdyBitPos = 7;
    ensBitPos = 6;
    break;
  case cmuOsc_HFXO:
    enBit = 4;
    disBit = 8;
    rdyBitPos = 3;
    ensBitPos = 2;
    break;
  case cmuOsc_HFRCO:
    enBit = 1;
    disBit = 2;
    rdyBitPos = 1;
    ensBitPos = 0;
    break;
  case cmuOsc_AUXHFRCO:
    enBit = 0x10;
    disBit = 0x20;
    rdyBitPos = 5;
    ensBitPos = 4;
    break;
  default:
    goto switchD_00007f80_caseD_5;
  }
  if (enable == false) {
    write_volatile_4(CMU->OSCENCMD,disBit);
    do {
      uVar2 = BUS_RegBitRead(&CMU->STATUS,ensBitPos);
    } while (uVar2 != 0);
  }
  else {
    bVar1 = false;
    if ((osc == cmuOsc_HFXO) &&
       (uVar2 = (CMU->HFXOCTRL), (uVar2 & 0x30) == 0)) {
      bVar1 = true;
      uVar2 = (CMU->HFXOCTRL);
      if ((uVar2 & 1) == 1) {
        uVar2 = (CMU->HFXOCTRL);
        write_volatile_4(CMU->HFXOCTRL,uVar2 & 0xffffffcf | 0x10);
      }
    }
    write_volatile_4(CMU->OSCENCMD,enBit);
    do {
      uVar2 = BUS_RegBitRead(&CMU->STATUS,ensBitPos);
    } while (uVar2 == 0);
    if (wait != false) {
      do {
        uVar2 = BUS_RegBitRead(&CMU->STATUS,rdyBitPos);
      } while (uVar2 == 0);
      if ((osc == cmuOsc_HFXO) && (bVar1)) {
        uVar2 = (CMU->HFXOCTRL);
        if ((uVar2 & 1) == 1) {
          CMU_OscillatorTuningOptimize(cmuOsc_HFXO,cmuHFXOTuningMode_ShuntCommand,true);
        }
        else {
          CMU_OscillatorTuningWait(cmuOsc_HFXO,cmuHFXOTuningMode_Auto);
        }
        val = CMU_OscillatorTuningGet(cmuOsc_HFXO);
        CMU_OscillatorEnable(cmuOsc_HFXO,false,true);
        CMU_OscillatorTuningSet(cmuOsc_HFXO,val);
        write_volatile_4(CMU->OSCENCMD,enBit);
        do {
          uVar2 = BUS_RegBitRead(&CMU->STATUS,rdyBitPos);
        } while (uVar2 == 0);
      }
    }
  }
switchD_00007f80_caseD_5:
  return;
}



uint32_t CMU_OscillatorTuningGet(CMU_Osc_TypeDef osc)

{
  uint uVar1;
  uint32_t ret;
  
  switch(osc) {
  case cmuOsc_LFRCO:
    uVar1 = (CMU->LFRCOCTRL);
    ret = uVar1 & 0x1ff;
    break;
  case cmuOsc_HFXO:
    uVar1 = (CMU->HFXOTRIMSTATUS);
    ret = uVar1 & 0x7ff;
    break;
  case cmuOsc_HFRCO:
    uVar1 = (CMU->HFRCOCTRL);
    ret = uVar1 & 0x7f;
    break;
  case cmuOsc_AUXHFRCO:
    uVar1 = (CMU->AUXHFRCOCTRL);
    ret = uVar1 & 0x7f;
    break;
  default:
    ret = 0;
  }
  return ret;
}



void CMU_OscillatorTuningSet(CMU_Osc_TypeDef osc,uint32_t val)

{
  uint uVar1;
  uint32_t uVar2;
  uint32_t regIshUpper;
  
  switch(osc) {
  case cmuOsc_LFRCO:
    do {
      uVar1 = BUS_RegBitRead(&CMU->SYNCBUSY,0x1a);
    } while (uVar1 != 0);
    uVar1 = (CMU->LFRCOCTRL);
    write_volatile_4(CMU->LFRCOCTRL,uVar1 & 0xfffffe00 | val & 0x1ff);
    break;
  case cmuOsc_HFXO:
    read_volatile(CMU->STATUS._0_1_);
    uVar1 = (CMU->HFXOCTRL);
    write_volatile_4(CMU->HFXOCTRL,uVar1 & 0xffffffcf | 0x10);
    uVar2 = getRegIshUpperVal(val >> 7 & 0xf);
    BUS_RegMaskedWrite(&CMU->HFXOSTEADYSTATECTRL,0xf00007ff,uVar2 | val);
    break;
  case cmuOsc_HFRCO:
    do {
      uVar1 = BUS_RegBitRead(&CMU->SYNCBUSY,0x18);
    } while (uVar1 != 0);
    uVar1 = (CMU->HFRCOCTRL);
    write_volatile_4(CMU->HFRCOCTRL,val & 0x7f | uVar1 & 0xffffff80);
    break;
  case cmuOsc_AUXHFRCO:
    do {
      uVar1 = BUS_RegBitRead(&CMU->SYNCBUSY,0x19);
    } while (uVar1 != 0);
    uVar1 = (CMU->AUXHFRCOCTRL);
    write_volatile_4(CMU->AUXHFRCOCTRL,val & 0x7f | uVar1 & 0xffffff80);
  }
  return;
}



_Bool CMU_OscillatorTuningWait(CMU_Osc_TypeDef osc,CMU_HFXOTuningMode_TypeDef mode)

{
  uint32_t uVar1;
  _Bool _Var2;
  uint uVar3;
  bool bVar4;
  uint32_t waitFlags;
  
  uVar1 = BUS_RegMaskedRead(&CMU->HFXOCTRL,0x30);
  if (uVar1 == 0) {
    waitFlags = 0xc00000;
  }
  else {
    if (mode == cmuHFXOTuningMode_ShuntCommand) {
      waitFlags = 0x800000;
    }
    else {
      if ((mode == cmuHFXOTuningMode_PeakShuntCommand) || (mode == cmuHFXOTuningMode_Auto)) {
        waitFlags = 0xc00000;
      }
      else {
        waitFlags = 0x7e103ff;
      }
    }
  }
  do {
    uVar3 = (CMU->STATUS);
  } while (waitFlags != (waitFlags & uVar3));
  if ((waitFlags & 0x400000) == 0) {
    _Var2 = true;
  }
  else {
    uVar3 = (CMU->IF);
    uVar3 = uVar3 & 0x400;
    bVar4 = uVar3 != 0;
    if (bVar4) {
      uVar3 = 1;
    }
    _Var2 = SUB41(uVar3,0);
    if (!bVar4) {
      _Var2 = false;
    }
  }
  return _Var2;
}



_Bool CMU_OscillatorTuningOptimize(CMU_Osc_TypeDef osc,CMU_HFXOTuningMode_TypeDef mode,_Bool wait)

{
  _Bool _Var1;
  
  if (osc == cmuOsc_HFXO) {
    if (mode != cmuHFXOTuningMode_Auto) {
      write_volatile_4(CMU->IFC,0x400);
      write_volatile_4(CMU->CMD,(uint)mode);
    }
    if (wait != false) {
      _Var1 = CMU_OscillatorTuningWait(cmuOsc_HFXO,mode);
      return _Var1;
    }
  }
  return true;
}



CORE_irqState_t CORE_EnterCritical(void)

{
  bool bVar1;
  CORE_irqState_t CVar2;
  uint32_t result;
  CORE_irqState_t irqState;
  
  CVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    CVar2 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  return CVar2;
}



void CORE_ExitCritical(CORE_irqState_t irqState)

{
  if (irqState == 0) {
    enableIRQinterrupts();
  }
  return;
}



CORE_irqState_t CORE_EnterAtomic(void)

{
  bool bVar1;
  CORE_irqState_t CVar2;
  uint32_t result;
  CORE_irqState_t irqState;
  
  CVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    CVar2 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  return CVar2;
}



void CORE_ExitAtomic(CORE_irqState_t irqState)

{
  if (irqState == 0) {
    enableIRQinterrupts();
  }
  return;
}



void SystemCoreClockUpdate(void)

{
  SystemCoreClockGet();
  return;
}



void BUS_RegBitWrite(uint32_t *addr,uint bit,uint val)

{
  uint32_t aliasAddr;
  
  *(uint *)((bit + (int)(addr + 0x840000) * 8) * 4) = val;
  return;
}



uint BUS_RegBitRead(uint32_t *addr,uint bit)

{
  uint32_t aliasAddr;
  
  return *(uint *)((bit + (int)(addr + 0x840000) * 8) * 4);
}



void EMU_Unlock(void)

{
  write_volatile_4(EMU->LOCK,0xade8);
  return;
}



void CMU_Lock(void)

{
  write_volatile_4(CMU->LOCK,0);
  return;
}



void CMU_Unlock(void)

{
  write_volatile_4(CMU->LOCK,0x580e);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint8_t SYSTEM_GetDevinfoRev(void)

{
  return (uint8_t)_DAT_0fe08200;
}



void emState(emState_TypeDef action)

{
  uint uVar1;
  uint32_t oscEnCmd;
  uint32_t cmuLocked;
  
  if (action == emState_Save) {
    emState::cmuStatus = (CMU->STATUS);
    emState::hfClock = CMU_ClockSelectGet(cmuClock_HF);
  }
  else {
    if (action == emState_Restore) {
      uVar1 = (CMU->LOCK);
      CMU_Unlock();
      write_volatile_4(CMU->OSCENCMD,emState::cmuStatus & 0x155);
      if (emState::hfClock != cmuSelect_HFRCO) {
        CMU_ClockSelectSet(cmuClock_HF,emState::hfClock);
      }
      if ((emState::cmuStatus & 1) == 0) {
        write_volatile_4(CMU->OSCENCMD,2);
      }
      if ((uVar1 & 1) != 0) {
        CMU_Lock();
      }
    }
  }
  return;
}



void dcdcFetCntSet(_Bool lpModeSet)

{
  uint uVar1;
  uint32_t tmp;
  
  if (lpModeSet == false) {
    write_volatile_4(EMU->DCDCMISCCTRL,dcdcFetCntSet::emuDcdcMiscCtrlReg);
    currentLimitersUpdate();
  }
  else {
    dcdcFetCntSet::emuDcdcMiscCtrlReg = (EMU->DCDCMISCCTRL);
    uVar1 = (EMU->DCDCMISCCTRL);
    write_volatile_4(EMU->DCDCMISCCTRL,uVar1 & 0xffff00ff | 0x7700);
    currentLimitersUpdate();
  }
  return;
}



void dcdcHsFixLnBlock(void)

{
  uint uVar1;
  
  if ((errataFixDcdcHsState == errataFixDcdcHsTrimSet) ||
     (errataFixDcdcHsState == errataFixDcdcHsBypassLn)) {
    uVar1 = (EMU->DCDCCTRL);
    if ((uVar1 & 3) == 1) {
      do {
        uVar1 = (EMU->_124_4_);
      } while ((uVar1 & 0x10000) == 0);
    }
    errataFixDcdcHsState = errataFixDcdcHsLnWaitDone;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void EMU_EnterEM2(_Bool restore)

{
  emState(emState_Save);
  _DAT_e000ed10 = _DAT_e000ed10 | 4;
  dcdcFetCntSet(true);
  dcdcHsFixLnBlock();
  WaitForInterrupt();
  dcdcFetCntSet(false);
  if (restore == false) {
    SystemCoreClockUpdate();
  }
  else {
    emState(emState_Restore);
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void EMU_EnterEM3(_Bool restore)

{
  uint uVar1;
  uint32_t cmuLocked;
  
  emState(emState_Save);
  uVar1 = (CMU->LOCK);
  CMU_Unlock();
  write_volatile_4(CMU->OSCENCMD,0x280);
  if ((uVar1 & 1) != 0) {
    CMU_Lock();
  }
  _DAT_e000ed10 = _DAT_e000ed10 | 4;
  dcdcFetCntSet(true);
  dcdcHsFixLnBlock();
  WaitForInterrupt();
  dcdcFetCntSet(false);
  if (restore == false) {
    SystemCoreClockUpdate();
  }
  else {
    emState(emState_Restore);
  }
  return;
}



void EMU_EnterEM4(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint32_t dcdcMode;
  uint32_t em4seq3;
  uint32_t em4seq2;
  int i;
  
  uVar1 = (EMU->EM4CTRL);
  uVar3 = uVar1 & 0xfffcffff | 0x20000;
  uVar1 = (EMU->EM4CTRL);
  EMU_Unlock();
  uVar2 = (EMU->EM4CTRL);
  if (((uVar2 & 1) == 0) &&
     ((uVar2 = (EMU->DCDCCTRL), (uVar2 & 3) == 1 || ((uVar2 & 3) == 2))))
  {
    EMU_DCDCModeSet(emuDcdcMode_Bypass);
  }
  uVar2 = (EMU->EM4CTRL);
  if ((uVar2 & 1) != 0) {
    disableIRQinterrupts();
    write_volatile_4(EMU->TESTLOCK,0xade8);
    uVar2 = (EMU->_408_4_);
    write_volatile_4(EMU->_408_4_,uVar2 | 0x80);
    uVar2 = (EMU->_136_4_);
    write_volatile_4(EMU->_136_4_,uVar2 | 0x100);
  }
  dcdcFetCntSet(true);
  dcdcHsFixLnBlock();
  for (i = 0; i < 4; i = i + 1) {
    write_volatile_4(EMU->EM4CTRL,uVar3);
    write_volatile_4(EMU->EM4CTRL,uVar1 | 0x30000);
  }
  write_volatile_4(EMU->EM4CTRL,uVar3);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

_Bool dcdcConstCalibrationLoad(void)

{
  bool bVar1;
  uint32_t *reg;
  uint32_t val;
  uint32_t *diCal_EMU_DCDCTRIM1;
  uint32_t *diCal_EMU_DCDCTRIM0;
  uint32_t *diCal_EMU_DCDCLPVCTRL;
  uint32_t *diCal_EMU_DCDCLPCTRL;
  uint32_t *diCal_EMU_DCDCLNVCTRL;
  uint32_t *diCal_EMU_DCDCLNFREQCTRL;
  
  bVar1 = _DAT_0fe0831c != -1;
  if (bVar1) {
    *_DAT_0fe08038 = _DAT_0fe0803c;
    *_DAT_0fe08040 = _DAT_0fe08044;
    *_DAT_0fe08048 = _DAT_0fe0804c;
    *_DAT_0fe08050 = _DAT_0fe08054;
    *_DAT_0fe08058 = _DAT_0fe0805c;
    *_DAT_0fe08060 = _DAT_0fe08064;
  }
  return (_Bool)bVar1;
}



void dcdcValidatedConfigSet(void)

{
  uint uVar1;
  SYSTEM_ChipRevision_TypeDef rev;
  uint32_t dcdcTiming;
  uint32_t lnForceCcm;
  
  uVar1 = (EMU->DCDCLPCTRL);
  write_volatile_4(EMU->DCDCLPCTRL,uVar1 | 0x1000000);
  uVar1 = BUS_RegBitRead(&EMU->DCDCMISCCTRL,0);
  if (uVar1 == 0) {
    EMU_DCDCLnRcoBandSet(emuDcdcLnRcoBand_3MHz);
  }
  else {
    EMU_DCDCLnRcoBandSet(emuDcdcLnRcoBand_7MHz);
  }
  uVar1 = (EMU->DCDCTIMING);
  write_volatile_4(EMU->DCDCTIMING,uVar1 & 0x9fffffff);
  uVar1 = (EMU->DCDCMISCCTRL);
  write_volatile_4(EMU->DCDCMISCCTRL,uVar1 | 6);
  SYSTEM_ChipRevisionGet(&rev);
  if (((rev.major == '\x01') && (rev.minor < 3)) && (errataFixDcdcHsState == errataFixDcdcHsInit)) {
    uVar1 = (EMU->_68_4_);
    write_volatile_4(EMU->_68_4_,uVar1 | 1);
    uVar1 = (EMU->DCDCTIMING);
    write_volatile_4(EMU->DCDCTIMING,uVar1 & 0xf00e0f00 | 0xb40c0b4);
    errataFixDcdcHsState = errataFixDcdcHsTrimSet;
  }
  return;
}



void currentLimitersUpdate(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ulong _b_1;
  uint32_t _a_1;
  uint32_t zdetLimSel;
  uint16_t maxReverseCurrent_mA;
  ulong _b;
  uint32_t _a;
  uint32_t lncLimSel;
  uint32_t pFetCnt;
  uint32_t lpcLimSel;
  uint32_t lpcLim;
  
  uVar3 = (EMU->DCDCMISCCTRL);
  uVar2 = uVar3 >> 8 & 0xf;
  uVar3 = ((dcdcMaxCurrent_mA + 0x28) / 2 + dcdcMaxCurrent_mA + 0x28) / ((uVar2 + 1) * 5) - 1;
  if (6 < uVar3) {
    uVar3 = 7;
  }
  uVar1 = (EMU->DCDCMISCCTRL);
  write_volatile_4(EMU->DCDCMISCCTRL,uVar3 << 0x18 | 0x100000 | uVar1 & 0xf88fffff);
  if (-1 < dcdcReverseCurrentControl) {
    uVar3 = (((ushort)dcdcReverseCurrentControl + 0x28) / 2 +
            (ushort)dcdcReverseCurrentControl + 0x28) / ((uVar2 + 1 >> 1) + (uVar2 + 1) * 2);
    if (6 < uVar3) {
      uVar3 = 7;
    }
    uVar2 = (EMU->DCDCZDETCTRL);
    write_volatile_4(EMU->DCDCZDETCTRL,uVar3 << 4 | uVar2 & 0xffffff8f);
  }
  return;
}



void userCurrentLimitsSet
               (uint32_t maxCurrent_mA,EMU_DcdcLnReverseCurrentControl_TypeDef reverseCurrentControl
               )

{
  dcdcMaxCurrent_mA = (uint16_t)maxCurrent_mA;
  dcdcReverseCurrentControl = reverseCurrentControl;
  return;
}



void compCtrlSet(EMU_DcdcLnCompCtrl_TypeDef comp)

{
  if (comp == emuDcdcLnCompCtrl_1u0F) {
    write_volatile_4(EMU->DCDCLNCOMPCTRL,0x57204077);
  }
  else {
    if (comp == emuDcdcLnCompCtrl_4u7F) {
      write_volatile_4(EMU->DCDCLNCOMPCTRL,0xb7102137);
    }
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

_Bool lpCmpHystCalibrationLoad(_Bool lpAttenuation,uint8_t lpCmpBias,dcdcTrimMode_TypeDef trimMode)

{
  uint uVar1;
  byte bVar2;
  uint8_t devinfoRev;
  uint32_t lpcmpHystSel;
  
  bVar2 = SYSTEM_GetDevinfoRev();
  if (bVar2 < 4) {
    if (lpAttenuation == false) {
      lpcmpHystSel = _DAT_0fe0832c & 0xff;
    }
    else {
      lpcmpHystSel = _DAT_0fe0832c >> 8 & 0xff;
    }
  }
  else {
    switch(lpCmpBias) {
    case '\0':
      lpcmpHystSel = _DAT_0fe08330 & 0xff;
      break;
    case '\x01':
      lpcmpHystSel = _DAT_0fe08330 >> 8 & 0xff;
      break;
    case '\x02':
      lpcmpHystSel = _DAT_0fe08330 >> 0x10 & 0xff;
      break;
    case '\x03':
      lpcmpHystSel = _DAT_0fe08330 >> 0x18;
      break;
    default:
      return false;
    }
  }
  if (trimMode == dcdcTrimMode_EM234H_LP) {
    if ((lpcmpHystSel << 0xc & 0xffff0fff) != 0) {
      return false;
    }
    uVar1 = (EMU->DCDCLPCTRL);
    write_volatile_4(EMU->DCDCLPCTRL,lpcmpHystSel << 0xc | uVar1 & 0xffff0fff);
  }
  return true;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void lpGetDevinfoVrefLowHigh(uint32_t *vrefL,uint32_t *vrefH,_Bool lpAttenuation,uint8_t lpcmpBias)

{
  ushort uVar1;
  uint32_t switchVal;
  uint32_t vrefHigh;
  uint32_t vrefLow;
  
  vrefLow = 0;
  vrefHigh = 0;
  uVar1 = CONCAT11(lpcmpBias,lpAttenuation);
  if (uVar1 == 0x101) {
    vrefHigh = _DAT_0fe08324 >> 0x18;
    vrefLow = _DAT_0fe08324 >> 0x10 & 0xff;
  }
  else {
    if (uVar1 < 0x102) {
      if (uVar1 == 1) {
        vrefHigh = _DAT_0fe08324 >> 8 & 0xff;
        vrefLow = _DAT_0fe08324 & 0xff;
      }
      else {
        if (uVar1 == 0) {
          vrefHigh = _DAT_0fe0831c >> 8 & 0xff;
          vrefLow = _DAT_0fe0831c & 0xff;
        }
        else {
          if (uVar1 == 0x100) {
            vrefHigh = _DAT_0fe0831c >> 0x18;
            vrefLow = _DAT_0fe0831c >> 0x10 & 0xff;
          }
        }
      }
    }
    else {
      if (uVar1 == 0x201) {
        vrefHigh = _DAT_0fe08328 >> 8 & 0xff;
        vrefLow = _DAT_0fe08328 & 0xff;
      }
      else {
        if (uVar1 < 0x202) {
          if (uVar1 == 0x200) {
            vrefHigh = _DAT_0fe08320 >> 8 & 0xff;
            vrefLow = _DAT_0fe08320 & 0xff;
          }
        }
        else {
          if (uVar1 == 0x300) {
            vrefHigh = _DAT_0fe08320 >> 0x18;
            vrefLow = _DAT_0fe08320 >> 0x10 & 0xff;
          }
          else {
            if (uVar1 == 0x301) {
              vrefHigh = _DAT_0fe08328 >> 0x18;
              vrefLow = _DAT_0fe08328 >> 0x10 & 0xff;
            }
          }
        }
      }
    }
  }
  *vrefL = vrefLow;
  *vrefH = vrefHigh;
  return;
}



void EMU_DCDCModeSet(EMU_DcdcMode_TypeDef dcdcMode)

{
  uint uVar1;
  uint uVar2;
  uint32_t currentDcdcMode;
  
  uVar1 = (EMU->DCDCCTRL);
  if ((uint)dcdcMode != (uVar1 & 3)) {
    do {
      uVar2 = (EMU->DCDCSYNC);
    } while ((uVar2 & 1) != 0);
    BUS_RegBitWrite(&EMU->DCDCCLIMCTRL,0xd,(uint)(dcdcMode != emuDcdcMode_Bypass));
    if (((uVar1 & 3) == 0) && (dcdcMode == emuDcdcMode_LowNoise)) {
      errataFixDcdcHsState = errataFixDcdcHsBypassLn;
    }
    do {
      uVar1 = (EMU->DCDCSYNC);
    } while ((uVar1 & 1) != 0);
    uVar1 = (EMU->DCDCCTRL);
    write_volatile_4(EMU->DCDCCTRL,(uint)dcdcMode | uVar1 & 0xfffffffc);
  }
  return;
}



_Bool EMU_DCDCInit(EMU_DCDCInit_TypeDef *dcdcInit)

{
  uint uVar1;
  _Bool _Var2;
  uint32_t lpCmpBiasSelEM234H;
  
  write_volatile_4(EMU->PWRCFG,2);
  uVar1 = (EMU->PWRCFG);
  if ((uVar1 & 0xf) == 2) {
    dcdcConstCalibrationLoad();
    if (dcdcInit->em234LoadCurrent_uA < 0x4b) {
      lpCmpBiasSelEM234H = 0;
    }
    else {
      if (dcdcInit->em234LoadCurrent_uA < 500) {
        lpCmpBiasSelEM234H = 0x10000000;
      }
      else {
        if (dcdcInit->em234LoadCurrent_uA < 0x9c4) {
          lpCmpBiasSelEM234H = 0x20000000;
        }
        else {
          lpCmpBiasSelEM234H = 0x30000000;
        }
      }
    }
    uVar1 = (EMU->DCDCMISCCTRL);
    write_volatile_4(EMU->DCDCMISCCTRL,
                     uVar1 & 0xcffffffe | lpCmpBiasSelEM234H | -1 < dcdcInit->reverseCurrentControl)
    ;
    dcdcValidatedConfigSet();
    userCurrentLimitsSet((uint)dcdcInit->maxCurrent_mA,dcdcInit->reverseCurrentControl);
    dcdcEm01LoadCurrent_mA = dcdcInit->em01LoadCurrent_mA;
    EMU_DCDCOptimizeSlice((uint)dcdcInit->em01LoadCurrent_mA);
    compCtrlSet(dcdcInit->dcdcLnCompCtrl);
    _Var2 = EMU_DCDCOutputVoltageSet((uint)dcdcInit->mVout,true,true);
    if (_Var2 == true) {
      BUS_RegBitWrite(&EMU->PWRCTRL,5,
                      (uint)(dcdcInit->anaPeripheralPower != emuDcdcAnaPeripheralPower_AVDD));
      EMU_DCDCModeSet(dcdcInit->dcdcMode);
      _Var2 = true;
    }
    else {
      _Var2 = false;
    }
  }
  else {
    _Var2 = false;
  }
  return _Var2;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

_Bool EMU_DCDCOutputVoltageSet(uint32_t mV,_Bool setLpVoltage,_Bool setLnVoltage)

{
  uint uVar1;
  _Bool _Var2;
  uint uVar3;
  bool bVar4;
  undefined lpAttenuation;
  uint32_t uVar5;
  uint uVar6;
  uint uVar7;
  uint8_t lpcmpBias [2];
  uint32_t vrefHigh [2];
  uint32_t vrefLow [2];
  uint32_t vrefVal [2];
  uint _b;
  uint32_t _a;
  _Bool attenuationSet;
  _Bool validOutVoltage;
  uint32_t mVhigh;
  uint32_t mVdiff;
  uint32_t mVlow;
  
  vrefLow[0] = 0;
  vrefHigh[0] = 0;
  if ((mV < 0x708) || (3000 < mV)) {
    bVar4 = false;
  }
  else {
    bVar4 = true;
  }
  if (bVar4) {
    uVar5 = mV;
    if (0x708 < mV) {
      uVar5 = 1;
    }
    lpAttenuation = (undefined)uVar5;
    if (mV < 0x709) {
      lpAttenuation = false;
    }
    if ((_Bool)lpAttenuation == false) {
      mVlow = 0x4b0;
      uVar6 = 600;
      vrefHigh[1] = _DAT_0fe08318 >> 8 & 0xff;
      vrefLow[1] = _DAT_0fe08318 & 0xff;
    }
    else {
      mVlow = 0x708;
      uVar6 = 0x4b0;
      vrefHigh[1] = _DAT_0fe08318 >> 0x18;
      vrefLow[1] = _DAT_0fe08318 >> 0x10 & 0xff;
    }
    uVar7 = (EMU->DCDCMISCCTRL);
    lpcmpBias[0] = (byte)(uVar7 >> 0x1c) & 3;
    lpGetDevinfoVrefLowHigh(vrefLow,vrefHigh,(_Bool)lpAttenuation,lpcmpBias[0]);
    uVar7 = vrefLow[1] + ((vrefHigh[1] - vrefLow[1]) * (mV - mVlow)) / uVar6;
    uVar6 = vrefLow[0] + ((vrefHigh[0] - vrefLow[0]) * (mV - mVlow)) / uVar6;
    if ((((vrefHigh[1] < uVar7) || (uVar7 < vrefLow[1])) || (vrefHigh[0] < uVar6)) ||
       (uVar6 < vrefLow[0])) {
      _Var2 = false;
    }
    else {
      if (setLnVoltage != false) {
        uVar1 = (EMU->DCDCLNVCTRL);
        if ((_Bool)lpAttenuation == false) {
          uVar3 = 0;
        }
        else {
          uVar3 = 2;
        }
        write_volatile_4(EMU->DCDCLNVCTRL,uVar1 & 0xffff80fd | uVar7 * 0x100 | uVar3);
      }
      if (setLpVoltage != false) {
        _Var2 = lpCmpHystCalibrationLoad((_Bool)lpAttenuation,lpcmpBias[0],dcdcTrimMode_EM234H_LP);
        if (_Var2 != true) {
          return false;
        }
        if (0xe6 < uVar6) {
          uVar6 = 0xe7;
        }
        uVar7 = (EMU->DCDCLPVCTRL);
        write_volatile_4(EMU->DCDCLPVCTRL,
                         uVar7 & 0xfffffe00 | uVar6 << 1 | (uint)((_Bool)lpAttenuation != false));
      }
      _Var2 = true;
    }
  }
  else {
    _Var2 = false;
  }
  return _Var2;
}



void EMU_DCDCOptimizeSlice(uint32_t em0LoadCurrent_mA)

{
  uint uVar1;
  uint uVar2;
  uint32_t rcoBand;
  uint32_t sliceCount;
  
  sliceCount = 0;
  uVar2 = (EMU->DCDCLNFREQCTRL);
  uVar2 = uVar2 & 7;
  uVar1 = (EMU->DCDCMISCCTRL);
  if (((uVar1 & 1) == 0) || (uVar2 < 2)) {
    uVar1 = (EMU->DCDCMISCCTRL);
    if (((uVar1 & 1) == 0) && (uVar2 < 2)) {
      if (em0LoadCurrent_mA < 10) {
        sliceCount = 4;
      }
      else {
        if ((em0LoadCurrent_mA < 10) || (0x13 < em0LoadCurrent_mA)) {
          sliceCount = 0x10;
        }
        else {
          sliceCount = 8;
        }
      }
    }
    else {
      uVar1 = (EMU->DCDCMISCCTRL);
      if (((uVar1 & 1) != 0) && (uVar2 < 2)) {
        if (em0LoadCurrent_mA < 0x28) {
          sliceCount = 8;
        }
        else {
          sliceCount = 0x10;
        }
      }
    }
  }
  else {
    if (em0LoadCurrent_mA < 0x14) {
      sliceCount = 4;
    }
    else {
      if ((em0LoadCurrent_mA < 0x14) || (0x27 < em0LoadCurrent_mA)) {
        sliceCount = 0x10;
      }
      else {
        sliceCount = 8;
      }
    }
  }
  uVar1 = (EMU->DCDCMISCCTRL);
  write_volatile_4(EMU->DCDCMISCCTRL,
                   (sliceCount - 1) * 0x1000 | (sliceCount - 1) * 0x100 | uVar1 & 0xffff00ff);
  currentLimitersUpdate();
  return;
}



void EMU_DCDCLnRcoBandSet(EMU_DcdcLnRcoBand_TypeDef band)

{
  uint uVar1;
  uint32_t forcedCcm;
  
  BUS_RegBitRead(&EMU->DCDCMISCCTRL,0);
  uVar1 = (EMU->DCDCLNFREQCTRL);
  write_volatile_4(EMU->DCDCLNFREQCTRL,(uint)band | uVar1 & 0xfffffff8);
  EMU_DCDCOptimizeSlice((uint)dcdcEm01LoadCurrent_mA);
  return;
}



void BUS_RegBitWrite(uint32_t *addr,uint bit,uint val)

{
  uint32_t aliasAddr;
  
  *(uint *)((bit + (int)(addr + 0x840000) * 8) * 4) = val;
  return;
}



void BUS_RegMaskedSet(uint32_t *addr,uint32_t mask)

{
  uint32_t aliasAddr;
  
  addr[0x1800000] = mask;
  return;
}



void BUS_RegMaskedClear(uint32_t *addr,uint32_t mask)

{
  uint32_t aliasAddr;
  
  addr[0x1000000] = mask;
  return;
}



void BUS_RegMaskedWrite(uint32_t *addr,uint32_t mask,uint32_t val)

{
  BUS_RegMaskedClear(addr,mask);
  BUS_RegMaskedSet(addr,val);
  return;
}



void GPIO_PinOutClear(GPIO_Port_TypeDef port,uint pin)

{
  BUS_RegBitWrite(&Peripherals::GPIO.PA_DOUT + (uint)port * 0xc,pin,0);
  return;
}



void GPIO_PinOutSet(GPIO_Port_TypeDef port,uint pin)

{
  BUS_RegBitWrite(&Peripherals::GPIO.PA_DOUT + (uint)port * 0xc,pin,1);
  return;
}



void GPIO_ExtIntConfig(GPIO_Port_TypeDef port,uint pin,uint intNo,_Bool risingEdge,_Bool fallingEdge
                      ,_Bool enable)

{
  uint uVar1;
  uint32_t tmp;
  
  if (intNo < 8) {
    BUS_RegMaskedWrite(&Peripherals::GPIO.EXTIPSELL,0xf << ((intNo & 0x3f) << 2),
                       (uint)port << ((intNo & 0x3f) << 2));
    BUS_RegMaskedWrite(&Peripherals::GPIO.EXTIPINSELL,3 << ((intNo & 0x3f) << 2),
                       (pin & 3) << ((intNo & 0x3f) << 2));
  }
  else {
    uVar1 = intNo - 8;
    BUS_RegMaskedWrite(&Peripherals::GPIO.EXTIPSELH,0xf << ((uVar1 & 0x3f) << 2),
                       (uint)port << ((uVar1 & 0x3f) << 2));
    BUS_RegMaskedWrite(&Peripherals::GPIO.EXTIPINSELH,3 << ((uVar1 & 0x3f) << 2),
                       (pin & 3) << ((uVar1 & 0x3f) << 2));
  }
  BUS_RegBitWrite(&Peripherals::GPIO.EXTIRISE,intNo,(uint)risingEdge);
  BUS_RegBitWrite(&Peripherals::GPIO.EXTIFALL,intNo,(uint)fallingEdge);
  write_volatile_4(Peripherals::GPIO.IFC,1 << (intNo & 0xff));
  BUS_RegBitWrite(&Peripherals::GPIO.IEN,intNo,(uint)enable);
  return;
}



void GPIO_PinModeSet(GPIO_Port_TypeDef port,uint pin,GPIO_Mode_TypeDef mode,uint out)

{
  if (mode != gpioModeDisabled) {
    if (out == 0) {
      GPIO_PinOutClear(port,pin);
    }
    else {
      GPIO_PinOutSet(port,pin);
    }
  }
  if (pin < 8) {
    (&Peripherals::GPIO.PA_MODEL)[(uint)port * 0xc] =
         (uint)mode << ((pin & 0x3f) << 2) |
         ~(0xf << ((pin & 0x3f) << 2)) & (&Peripherals::GPIO.PA_MODEL)[(uint)port * 0xc];
  }
  else {
    (&Peripherals::GPIO.PA_MODEH)[(uint)port * 0xc] =
         (&Peripherals::GPIO.PA_MODEH)[(uint)port * 0xc] & ~(0xf << ((pin + 0x3ffffff8) * 4 & 0xff))
         | (uint)mode << ((pin + 0x3ffffff8) * 4 & 0xff);
  }
  if (mode == gpioModeDisabled) {
    if (out == 0) {
      GPIO_PinOutClear(port,pin);
    }
    else {
      GPIO_PinOutSet(port,pin);
    }
  }
  return;
}



void RMU_ResetCauseClear(void)

{
  write_volatile_4(Peripherals::RMU.CMD,1);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint32_t RMU_ResetCauseGet(void)

{
  uint uVar1;
  uint uVar2;
  uint32_t rstCause;
  uint32_t i;
  uint32_t zeroXMask;
  uint32_t validRstCause;
  
  uVar1 = (Peripherals::RMU.RSTCAUSE);
  validRstCause = 0;
  i = 0;
  do {
    if (8 < i) {
      if ((validRstCause & 0x10000) != 0) {
        validRstCause = validRstCause & 0xffffffe3;
      }
      return validRstCause;
    }
    zeroXMask = resetCauseMasks[i].resetCauseZeroXMask;
    if ((_DAT_0fe041e8 & 4) != 0) goto LAB_0000953c;
    uVar2 = resetCauseMasks[i].resetCauseMask;
    if (uVar2 == 0x400) {
LAB_00009532:
      zeroXMask = zeroXMask | 0x100;
    }
    else {
      if (uVar2 < 0x401) {
        if (uVar2 == 0x200) goto LAB_00009532;
      }
      else {
        if ((uVar2 == 0x800) || (uVar2 == 0x10000)) goto LAB_00009532;
      }
    }
LAB_0000953c:
    uVar2 = (EMU->_136_4_);
    if ((uVar2 & 0x100) != 0) {
      zeroXMask = zeroXMask & 0xffffffe3;
    }
    if (((uVar1 & resetCauseMasks[i].resetCauseMask) != 0) && ((zeroXMask & uVar1) == 0)) {
      validRstCause = resetCauseMasks[i].resetCauseMask | validRstCause;
    }
    i = i + 1;
  } while( true );
}



void BUS_RegBitWrite(uint32_t *addr,uint bit,uint val)

{
  uint32_t aliasAddr;
  
  *(uint *)((bit + (int)(addr + 0x840000) * 8) * 4) = val;
  return;
}



void RTCC_Enable(_Bool enable)

{
  BUS_RegBitWrite(&Peripherals::RTCC.CTRL,0,(uint)enable);
  return;
}



void RTCC_Init(RTCC_Init_TypeDef *init)

{
  write_volatile_4(Peripherals::RTCC.CTRL,
                   (uint)init->disLeapYearCorr << 0x11 |
                   (uint)init->enable | (uint)init->debugRun << 2 |
                   (uint)init->precntWrapOnCCV0 << 4 | (uint)init->cntWrapOnCCV1 << 5 |
                   (uint)init->presc << 8 | (uint)init->prescMode << 0xc |
                   (uint)init->enaOSCFailDetect << 0xf | (uint)init->cntMode << 0x10);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void SYSTEM_ChipRevisionGet(SYSTEM_ChipRevision_TypeDef *rev)

{
  uint8_t tmp;
  
  rev->family = (byte)((_DAT_e00fffe4 & 0xff) << 2) & 0x3c | (byte)(_DAT_e00fffe0 >> 6) & 3;
  rev->major = (byte)_DAT_e00fffe0 & 0x3f;
  rev->minor = (byte)((_DAT_e00fffe8 >> 4 & 0xff) << 4) | (byte)(_DAT_e00fffec >> 4) & 0xf;
  return;
}



void BUS_RegMaskedSet(uint32_t *addr,uint32_t mask)

{
  uint32_t aliasAddr;
  
  addr[0x1800000] = mask;
  return;
}



void BUS_RegMaskedClear(uint32_t *addr,uint32_t mask)

{
  uint32_t aliasAddr;
  
  addr[0x1000000] = mask;
  return;
}



void BUS_RegMaskedWrite(uint32_t *addr,uint32_t mask,uint32_t val)

{
  BUS_RegMaskedClear(addr,mask);
  BUS_RegMaskedSet(addr,val);
  return;
}



void USART_BaudrateAsyncSet
               (USART_TypeDef *usart,uint32_t refFreq,uint32_t baudrate,USART_OVS_TypeDef ovs)

{
  uint32_t local_18;
  uint32_t clkdiv;
  uint32_t oversample;
  
  local_18 = refFreq;
  if (refFreq == 0) {
    local_18 = CMU_ClockFreqGet(cmuClock_HFPER);
  }
  if (ovs == usartOVS8) {
    oversample = 8;
  }
  else {
    if (ovs < 0x21) {
      if (ovs != usartOVS16) {
        return;
      }
      oversample = 0x10;
    }
    else {
      if (ovs == usartOVS6) {
        oversample = 6;
      }
      else {
        if (ovs != usartOVS4) {
          return;
        }
        oversample = 4;
      }
    }
  }
  usart->CTRL = usart->CTRL & 0xffffff9f;
  usart->CTRL = usart->CTRL | (uint)ovs;
  usart->CLKDIV =
       (((baudrate * oversample >> 1) + local_18 * 0x20) / (baudrate * oversample) - 0x20) * 8 &
       0x7ffff8;
  return;
}



void USART_BaudrateSyncSet(USART_TypeDef *usart,uint32_t refFreq,uint32_t baudrate)

{
  uint32_t local_18;
  uint32_t clkdiv;
  
  local_18 = refFreq;
  if (refFreq == 0) {
    local_18 = CMU_ClockFreqGet(cmuClock_HFPER);
  }
  BUS_RegMaskedWrite(&usart->CLKDIV,0x7ffff8,((local_18 - 1) / (baudrate << 1) & 0x7fff) << 8);
  return;
}



void USART_Enable(USART_TypeDef *usart,USART_Enable_TypeDef enable)

{
  uint32_t tmp;
  
  usart->CMD = (~(uint)enable & 5) << 1;
  usart->CMD = (uint)enable;
  return;
}



void USART_InitAsync(USART_TypeDef *usart,USART_InitAsync_TypeDef *init)

{
  USART_Reset(usart);
  if (init->mvdis != false) {
    usart->CTRL = usart->CTRL | 0x40000000;
  }
  if (init->prsRxEnable != false) {
    usart->INPUT = (uint)(init->prsRxCh | 0x80);
  }
  usart->FRAME = (uint)init->parity | (uint)init->stopbits | (uint)init->databits;
  USART_BaudrateAsyncSet(usart,init->refFreq,init->baudrate,init->oversampling);
  usart->TIMING = (init->autoCsHold & 7) << 0x1c | (init->autoCsSetup & 7) << 0x14;
  if (init->autoCsEnable != false) {
    usart->CTRL = usart->CTRL | 0x10000;
  }
  usart->CMD = (uint)init->enable;
  return;
}



void USART_InitSync(USART_TypeDef *usart,USART_InitSync_TypeDef *init)

{
  uint uVar1;
  
  USART_Reset(usart);
  if (init->msbf == false) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x400;
  }
  usart->CTRL = usart->CTRL | uVar1 | (init->clockMode | 1);
  if (init->autoTx == false) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x20000000;
  }
  usart->CTRL = uVar1 | usart->CTRL;
  if (init->prsRxEnable != false) {
    usart->INPUT = (uint)(init->prsRxCh | 0x80);
  }
  usart->FRAME = init->databits | 0x1000;
  USART_BaudrateSyncSet(usart,init->refFreq,init->baudrate);
  if (init->master != false) {
    usart->CMD = 0x10;
  }
  usart->TIMING = (init->autoCsHold & 7) << 0x1c | (init->autoCsSetup & 7) << 0x14;
  if (init->autoCsEnable != false) {
    usart->CTRL = usart->CTRL | 0x10000;
  }
  usart->CMD = (uint)init->enable;
  return;
}



void USART_Reset(USART_TypeDef *usart)

{
  usart->CMD = 0xeaa;
  usart->CTRL = 0;
  usart->FRAME = 0x1005;
  usart->TRIGCTRL = 0;
  usart->CLKDIV = 0;
  usart->IEN = 0;
  usart->IFC = 0x1fff9;
  usart->ROUTEPEN = 0;
  usart->ROUTELOC0 = 0;
  usart->ROUTELOC1 = 0;
  if (usart == (USART_TypeDef *)&Peripherals::USART0) {
    write_volatile_4(Peripherals::USART0.IRCTRL,0);
  }
  usart->INPUT = 0;
  if (usart == (USART_TypeDef *)&Peripherals::USART1) {
    write_volatile_4(Peripherals::USART1.I2SCTRL,0);
  }
  return;
}



uint8_t USART_Rx(USART_TypeDef *usart)

{
  do {
  } while ((usart->STATUS & 0x80) == 0);
  return (uint8_t)usart->RXDATA;
}



void USART_Tx(USART_TypeDef *usart,uint8_t data)

{
  do {
  } while ((usart->STATUS & 0x40) == 0);
  usart->TXDATA = (uint)data;
  return;
}



void USART_TxDouble(USART_TypeDef *usart,uint16_t data)

{
  do {
  } while ((usart->STATUS & 0x40) == 0);
  usart->TXDOUBLE = (uint)data;
  return;
}



void NVIC_EnableIRQ(IRQn_Type IRQn)

{
  *(int *)(&DAT_e000e100 + ((uint)(int)IRQn >> 5) * 4) = 1 << (IRQn & 0x1fU);
  return;
}



void NVIC_ClearPendingIRQ(IRQn_Type IRQn)

{
  *(int *)(&DAT_e000e100 + (((uint)(int)IRQn >> 5) + 0x60) * 4) = 1 << (IRQn & 0x1fU);
  return;
}



void GPIO_IntClear(uint32_t flags)

{
  write_volatile_4(Peripherals::GPIO.IFC,flags);
  return;
}



uint32_t GPIO_IntGetEnabled(void)

{
  uint uVar1;
  uint uVar2;
  uint32_t tmp;
  
  uVar2 = (Peripherals::GPIO.IEN);
  uVar1 = (Peripherals::GPIO.IF);
  return uVar2 & uVar1;
}



uint32_t SL_CTZ(uint32_t value)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint32_t uVar5;
  uint32_t result;
  
  bVar2 = (byte)value;
  bVar3 = (byte)(value >> 8);
  bVar4 = (byte)(value >> 0x10);
  bVar1 = (byte)(value >> 0x18);
  uVar5 = count_leading_zeroes
                    ((uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) <<
                                      1 | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 |
                                   bVar2 >> 5 & 1) << 1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x18
                     | (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1)
                                        << 1 | bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 |
                                     bVar3 >> 5 & 1) << 1 | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) <<
                       0x10 | (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 |
                                               bVar4 >> 2 & 1) << 1 | bVar4 >> 3 & 1) << 1 |
                                             bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) << 1 |
                                           bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8 |
                     (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) <<
                                      1 | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 |
                                   bVar1 >> 5 & 1) << 1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7));
  return uVar5;
}



void GPIOINT_Init(void)

{
  NVIC_ClearPendingIRQ(GPIO_ODD_IRQn);
  NVIC_EnableIRQ(GPIO_ODD_IRQn);
  NVIC_ClearPendingIRQ(GPIO_EVEN_IRQn);
  NVIC_EnableIRQ(GPIO_EVEN_IRQn);
  return;
}



void GPIOINT_CallbackRegister(uint8_t pin,GPIOINT_IrqCallbackPtr_t *callbackPtr)

{
  CORE_irqState_t irqState_00;
  CORE_irqState_t irqState;
  
  irqState_00 = CORE_EnterAtomic();
  gpioCallbacks[pin] = callbackPtr;
  CORE_ExitAtomic(irqState_00);
  return;
}



void GPIOINT_IRQDispatcher(uint32_t iflags)

{
  uint32_t uVar1;
  uint32_t local_14;
  GPIOINT_IrqCallbackPtr_t *callback;
  uint32_t irqIdx;
  
  local_14 = iflags;
  while (local_14 != 0) {
    uVar1 = SL_CTZ(local_14);
    local_14 = local_14 & ~(1 << (uVar1 & 0xff));
    if (gpioCallbacks[uVar1] != FUN_00000000) {
      (*gpioCallbacks[uVar1])((uint8_t)uVar1);
    }
  }
  return;
}



void GPIO_EVEN_IRQHandler(void)

{
  uint32_t uVar1;
  uint32_t iflags;
  
  uVar1 = GPIO_IntGetEnabled();
  GPIO_IntClear(uVar1 & 0x5555);
  GPIOINT_IRQDispatcher(uVar1 & 0x5555);
  return;
}



void GPIO_ODD_IRQHandler(void)

{
  uint32_t uVar1;
  uint32_t iflags;
  
  uVar1 = GPIO_IntGetEnabled();
  GPIO_IntClear(uVar1 & 0xaaaa);
  GPIOINT_IRQDispatcher(uVar1 & 0xaaaa);
  return;
}



void halInit(void)

{
  halInitChipSpecific();
  return;
}



void BUS_RegBitWrite(uint32_t *addr,uint bit,uint val)

{
  uint32_t aliasAddr;
  
  *(uint *)((bit + (int)(addr + 0x840000) * 8) * 4) = val;
  return;
}



void GPIO_PinOutClear(GPIO_Port_TypeDef port,uint pin)

{
  BUS_RegBitWrite(&Peripherals::GPIO.PA_DOUT + (uint)port * 0xc,pin,0);
  return;
}



void GPIO_PinOutSet(GPIO_Port_TypeDef port,uint pin)

{
  BUS_RegBitWrite(&Peripherals::GPIO.PA_DOUT + (uint)port * 0xc,pin,1);
  return;
}



// WARNING: Could not reconcile some variable overlaps

void halInitChipSpecific(void)

{
  bool bVar1;
  EMU_DCDCInit_TypeDef dcdcInit;
  RADIO_PAInit_t paInit;
  RADIO_PTIInit_t ptiInit;
  CMU_HFXOInit_TypeDef hfxoInit;
  
  hfxoInit._0_4_ = 0;
  hfxoInit._4_4_ = 0x14200a0;
  hfxoInit._8_4_ = 0x607200a;
  hfxoInit._12_4_ = 0x7040a02;
  hfxoInit._16_2_ = 0;
  ptiInit._0_4_ = 1;
  ptiInit.baud = 1600000;
  ptiInit._8_4_ = 0x60c0106;
  ptiInit._12_4_ = 0x1060b01;
  ptiInit._16_4_ = 0xd;
  dcdcInit._0_4_ = 0x7080100;
  dcdcInit._4_4_ = 0xa000f;
  dcdcInit._8_4_ = 0x2000c8;
  dcdcInit._12_4_ = 0xa0;
  EMU_DCDCInit(&dcdcInit);
  CMU_HFXOInit(&hfxoInit);
  SystemHFXOClockSet(38400000);
  RADIO_PTI_Init(&ptiInit);
  CMU_ClockSelectSet(cmuClock_HF,cmuSelect_HFXO);
  CMU_OscillatorEnable(cmuOsc_HFRCO,false,false);
  paInit._0_4_ = 0x640102;
  paInit._4_4_ = 0xa0000;
  bVar1 = RADIO_PA_Init(&paInit);
  if (bVar1 != true) {
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  CMU_OscillatorEnable(cmuOsc_LFRCO,true,true);
  CMU_ClockSelectSet(cmuClock_LFA,cmuSelect_LFRCO);
  CMU_ClockSelectSet(cmuClock_LFB,cmuSelect_LFRCO);
  CMU_ClockEnable(cmuClock_HFLE,true);
  boardLowPowerInit();
  return;
}



void boardLowPowerInit(void)

{
  boardDisableSpiFlash();
  return;
}



void boardDisableSpiFlash(void)

{
  CMU_ClockEnable(cmuClock_HFPER,true);
  CMU_ClockEnable(cmuClock_GPIO,true);
  CMU_ClockEnable(cmuClock_USART1,true);
  USART_InitSync((USART_TypeDef *)&Peripherals::USART1,&usartInit);
  write_volatile_4(Peripherals::USART1.ROUTEPEN,0xb);
  write_volatile_4(Peripherals::USART1.ROUTELOC0,0xb000b0b);
  GPIO_PinModeSet(gpioPortC,6,gpioModePushPull,0);
  GPIO_PinModeSet(gpioPortC,7,gpioModeInputPull,0);
  GPIO_PinModeSet(gpioPortC,8,gpioModePushPull,0);
  GPIO_PinModeSet(gpioPortA,4,gpioModePushPull,1);
  usecDelay(10000);
  GPIO_PinOutClear(gpioPortA,4);
  USART_Tx((USART_TypeDef *)&Peripherals::USART1,0xab);
  USART_Rx((USART_TypeDef *)&Peripherals::USART1);
  GPIO_PinOutSet(gpioPortA,4);
  usecDelay(0x1e);
  GPIO_PinOutClear(gpioPortA,4);
  USART_Tx((USART_TypeDef *)&Peripherals::USART1,0xb9);
  USART_Rx((USART_TypeDef *)&Peripherals::USART1);
  GPIO_PinOutSet(gpioPortA,4);
  return;
}



// WARNING: Could not reconcile some variable overlaps

void usecDelay(uint32_t usecs)

{
  uint uVar1;
  bool bVar2;
  uint64_t iterations;
  
  iterations._4_4_ = 0;
  iterations._0_4_ = usecs * 3;
  do {
    bVar2 = (uint)iterations != 0;
    uVar1 = (uint)iterations | iterations._4_4_;
    iterations._0_4_ = (uint)iterations - 1;
    iterations._4_4_ = (iterations._4_4_ - 1) + (uint)bVar2;
  } while (uVar1 != 0);
  return;
}



debugSignal_t * halGetDebugSignals(uint32_t *size)

{
  if (size != (uint32_t *)0x0) {
    *size = 5;
  }
  return debugSignals;
}



debugPin_t * halGetDebugPins(uint32_t *size)

{
  if (size != (uint32_t *)0x0) {
    *size = 6;
  }
  return debugPins;
}



void halDisablePrs(uint8_t channel)

{
  BUS_RegBitWrite(&Peripherals::PRS.ROUTEPEN,(uint)channel,0);
  return;
}



void halEnablePrs(uint8_t channel,uint8_t loc,uint8_t source,uint8_t signal)

{
  uint *puVar1;
  ushort local_1c;
  uint32_t *routeLocPtr;
  
  local_1c = CONCAT11(source,signal);
  CMU_ClockEnable(cmuClock_PRS,true);
  BUS_RegBitWrite(&Peripherals::PRS.ROUTEPEN,(uint)channel,0);
  (&Peripherals::PRS.CH0_CTRL)[channel] = (uint)local_1c;
  puVar1 = &Peripherals::PRS.ROUTELOC0 + (channel >> 2);
  *puVar1 = ~(0xff << ((channel & 3) << 3)) & *puVar1;
  *puVar1 = (uint)loc << ((channel & 3) << 3) | *puVar1;
  BUS_RegBitWrite(&Peripherals::PRS.ROUTEPEN,(uint)channel,1);
  return;
}



int _close(int file)

{
  return 0;
}



void _exit(int status)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



int _fstat(int file,stat *st)

{
  st->st_mode = 0x2000;
  return 0;
}



int _isatty(int file)

{
  return 1;
}



int _lseek(int file,int ptr,int dir)

{
  return 0;
}



int _read(int file,char *ptr,int len)

{
  int iVar1;
  int local_1c;
  char *local_18;
  int c;
  int rxCount;
  
  rxCount = 0;
  local_1c = len;
  local_18 = ptr;
  while ((local_1c != 0 && (iVar1 = RETARGET_ReadChar(), iVar1 != -1))) {
    *local_18 = (char)iVar1;
    rxCount = rxCount + 1;
    local_1c = local_1c + -1;
    local_18 = local_18 + 1;
  }
  if (rxCount < 1) {
    rxCount = -1;
  }
  return rxCount;
}



caddr_t _sbrk(int incr)

{
  int file;
  size_t len;
  caddr_t pcVar1;
  char *pcVar2;
  char *prev_heap_end;
  
  if (_sbrk::heap_end == (char *)0x0) {
    _sbrk::heap_end = (char *)0x20003400;
  }
  pcVar2 = (char *)getMainStackPointer();
  if (pcVar2 < _sbrk::heap_end + incr) {
    file = fileno(*(FILE **)(_impure_ptr + 8));
    len = strlen("Heap and stack collision\n");
    _write(file,"Heap and stack collision\n",len);
                    // WARNING: Subroutine does not return
    exit(1);
  }
  pcVar1 = _sbrk::heap_end;
  _sbrk::heap_end = _sbrk::heap_end + incr;
  return pcVar1;
}



int _write(int file,char *ptr,int len)

{
  char *local_18;
  int txCount;
  
  local_18 = ptr;
  for (txCount = 0; txCount < len; txCount = txCount + 1) {
    RETARGET_WriteChar(*local_18);
    local_18 = local_18 + 1;
  }
  return len;
}



void NVIC_EnableIRQ(IRQn_Type IRQn)

{
  *(int *)(&DAT_e000e100 + ((uint)(int)IRQn >> 5) * 4) = 1 << (IRQn & 0x1fU);
  return;
}



void NVIC_ClearPendingIRQ(IRQn_Type IRQn)

{
  *(int *)(&DAT_e000e100 + (((uint)(int)IRQn >> 5) + 0x60) * 4) = 1 << (IRQn & 0x1fU);
  return;
}



void USART_IntClear(USART_TypeDef *usart,uint32_t flags)

{
  usart->IFC = flags;
  return;
}



void USART_IntEnable(USART_TypeDef *usart,uint32_t flags)

{
  usart->IEN = usart->IEN | flags;
  return;
}



void USART0_RX_IRQHandler(void)

{
  uint uVar1;
  int iVar2;
  uint8_t uVar3;
  
  iVar2 = rxWriteIndex;
  uVar1 = (Peripherals::USART0.STATUS);
  if ((uVar1 & 0x80) != 0) {
    uVar3 = USART_Rx((USART_TypeDef *)&Peripherals::USART0);
    rxBuffer[iVar2] = uVar3;
    rxWriteIndex = rxWriteIndex + 1;
    rxCount = rxCount + 1;
    if (rxWriteIndex == 8) {
      rxWriteIndex = 0;
    }
    if (8 < rxCount) {
      rxWriteIndex = 0;
      rxCount = 0;
      rxReadIndex = 0;
    }
  }
  return;
}



void RETARGET_SerialCrLf(int on)

{
  LFtoCRLF = on != 0;
  return;
}



// WARNING: Could not reconcile some variable overlaps

void RETARGET_SerialInit(void)

{
  uint uVar1;
  USART_InitAsync_TypeDef init;
  USART_TypeDef *usart;
  
  CMU_ClockEnable(cmuClock_HFPER,true);
  CMU_ClockEnable(cmuClock_GPIO,true);
  GPIO_PinModeSet(gpioPortA,0,gpioModePushPull,1);
  GPIO_PinModeSet(gpioPortA,1,gpioModeInput,0);
  init._0_4_ = 5;
  init.refFreq = 0;
  init.baudrate = (uint32_t)&DAT_0001c200;
  init._12_4_ = 0x500;
  init._16_4_ = 0x1000;
  init._20_4_ = 0;
  CMU_ClockEnable(cmuClock_USART0,true);
  init._0_4_ = init._0_4_ & 0xffffff00;
  USART_InitAsync((USART_TypeDef *)&Peripherals::USART0,&init);
  write_volatile_4(Peripherals::USART0.ROUTEPEN,3);
  uVar1 = (Peripherals::USART0.ROUTELOC0);
  write_volatile_4(Peripherals::USART0.ROUTELOC0,uVar1 & 0xffffe0e0);
  USART_IntClear((USART_TypeDef *)&Peripherals::USART0,4);
  NVIC_ClearPendingIRQ(USART0_RX_IRQn);
  USART_IntEnable((USART_TypeDef *)&Peripherals::USART0,4);
  NVIC_EnableIRQ(USART0_RX_IRQn);
  USART_Enable((USART_TypeDef *)&Peripherals::USART0,usartEnable);
  setvbuf(*(FILE **)(_impure_ptr + 8),(char *)0x0,2,0);
  initialized = true;
  return;
}



int RETARGET_ReadChar(void)

{
  CORE_irqState_t irqState_00;
  CORE_irqState_t irqState;
  int c;
  
  c = -1;
  if (initialized != true) {
    RETARGET_SerialInit();
  }
  irqState_00 = CORE_EnterAtomic();
  if (0 < rxCount) {
    c = ZEXT14(rxBuffer[rxReadIndex]);
    rxReadIndex = rxReadIndex + 1;
    if (rxReadIndex == 8) {
      rxReadIndex = 0;
    }
    rxCount = rxCount + -1;
  }
  CORE_ExitAtomic(irqState_00);
  return c;
}



int RETARGET_WriteChar(char c)

{
  if (initialized != true) {
    RETARGET_SerialInit();
  }
  if ((LFtoCRLF != '\0') && (c == '\n')) {
    USART_Tx((USART_TypeDef *)&Peripherals::USART0,'\r');
  }
  USART_Tx((USART_TypeDef *)&Peripherals::USART0,c);
  if ((LFtoCRLF != '\0') && (c == '\r')) {
    USART_Tx((USART_TypeDef *)&Peripherals::USART0,'\n');
  }
  return (uint)(byte)c;
}



uint32_t RTCC_ChannelCCVGet(int ch)

{
  return (&Peripherals::RTCC.CC0_CCV)[ch * 4];
}



void RTCC_ChannelCCVSet(int ch,uint32_t value)

{
  (&Peripherals::RTCC.CC0_CCV)[ch * 4] = value;
  return;
}



uint32_t RTCC_CounterGet(void)

{
  uint uVar1;
  
  uVar1 = (Peripherals::RTCC.CNT);
  return uVar1;
}



void RTCC_IntClear(uint32_t flags)

{
  write_volatile_4(Peripherals::RTCC.IFC,flags);
  return;
}



void RTCC_IntDisable(uint32_t flags)

{
  uint uVar1;
  
  uVar1 = (Peripherals::RTCC.IEN);
  write_volatile_4(Peripherals::RTCC.IEN,~flags & uVar1);
  return;
}



void RTCC_IntEnable(uint32_t flags)

{
  uint uVar1;
  
  uVar1 = (Peripherals::RTCC.IEN);
  write_volatile_4(Peripherals::RTCC.IEN,flags | uVar1);
  return;
}



uint32_t RTCC_IntGetEnabled(void)

{
  uint uVar1;
  uint uVar2;
  uint32_t tmp;
  
  uVar2 = (Peripherals::RTCC.IEN);
  uVar1 = (Peripherals::RTCC.IF);
  return uVar2 & uVar1;
}



void RTCC_IRQHandler(void)

{
  CORE_irqState_t irqState_00;
  uint32_t uVar1;
  uint32_t uVar2;
  uint uVar3;
  uint32_t timeToNextTimerCompletion;
  uint32_t timeElapsed;
  uint32_t flags;
  CORE_irqState_t irqState;
  uint32_t cnt;
  
  irqState_00 = CORE_EnterAtomic();
  uVar1 = RTCC_IntGetEnabled();
  RTCC_IntClear(uVar1 & 0xfffffffa);
  if ((uVar1 & 4) != 0) {
    inTimerIRQ = true;
    cnt = RTCC_CounterGet();
    do {
      RTCC_IntDisable(4);
      checkAllTimers(cnt - lastStart);
      executeTimerCallbacks();
      rescheduleRtc(cnt);
      cnt = RTCC_CounterGet();
      uVar3 = cnt - lastStart;
      uVar2 = RTCC_ChannelCCVGet(1);
      if (rtcRunning == false) break;
    } while (uVar2 - lastStart < uVar3);
    inTimerIRQ = false;
  }
  if ((uVar1 & 1) != 0) {
    RTCC_IntClear(1);
    wallClockOverflowCnt = wallClockOverflowCnt + 1;
  }
  CORE_ExitAtomic(irqState_00);
  return;
}



void checkAllTimers(uint32_t timeElapsed)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  int i;
  
  for (i = 0; i < 4; i = i + 1) {
    timer[i].doCallback = false;
    if (timer[i].running != false) {
      iVar3 = *(int *)((int)&timer[i].remaining + 4);
      bVar6 = iVar3 == 0;
      if (iVar3 == 0) {
        bVar6 = *(uint *)&timer[i].remaining <= timeElapsed;
      }
      if (bVar6) {
        if (timer[i].timerType == rtcdrvTimerTypeOneshot) {
          timer[i].running = false;
        }
        else {
          uVar5 = *(uint *)&timer[i].ticks;
          iVar3 = *(int *)((int)&timer[i].ticks + 4);
          uVar1 = uVar5 - timeElapsed;
          uVar2 = *(uint *)&timer[i].remaining;
          iVar4 = *(int *)((int)&timer[i].remaining + 4);
          *(uint *)&timer[i].remaining = uVar1 + uVar2;
          *(uint *)((int)&timer[i].remaining + 4) =
               (iVar3 - (uint)(uVar5 < timeElapsed)) + iVar4 + (uint)CARRY4(uVar1,uVar2);
          if (timer[i].periodicCompensationUsec < 1) {
            timer[i].periodicDriftUsec =
                 timer[i].periodicDriftUsec - timer[i].periodicCompensationUsec;
            if (0xf3 < timer[i].periodicDriftUsec) {
              iVar3 = *(int *)&timer[i].remaining;
              iVar4 = *(int *)((int)&timer[i].remaining + 4);
              *(int *)&timer[i].remaining = iVar3 + -1;
              *(uint *)((int)&timer[i].remaining + 4) = iVar4 + -1 + (uint)(iVar3 != 0);
              timer[i].periodicDriftUsec = timer[i].periodicDriftUsec - 0xf4;
            }
          }
          else {
            timer[i].periodicDriftUsec =
                 timer[i].periodicDriftUsec + timer[i].periodicCompensationUsec;
            if (0xf3 < timer[i].periodicDriftUsec) {
              uVar5 = *(uint *)&timer[i].remaining;
              iVar3 = *(int *)((int)&timer[i].remaining + 4);
              *(uint *)&timer[i].remaining = uVar5 + 1;
              *(uint *)((int)&timer[i].remaining + 4) = iVar3 + (uint)(0xfffffffe < uVar5);
              timer[i].periodicDriftUsec = timer[i].periodicDriftUsec - 0xf4;
            }
          }
        }
        if (timer[i].callback != FUN_00000000) {
          timer[i].doCallback = true;
        }
      }
      else {
        uVar5 = *(uint *)&timer[i].remaining;
        iVar3 = *(int *)((int)&timer[i].remaining + 4);
        *(uint *)&timer[i].remaining = uVar5 - timeElapsed;
        *(uint *)((int)&timer[i].remaining + 4) = iVar3 - (uint)(uVar5 < timeElapsed);
      }
    }
  }
  return;
}



void executeTimerCallbacks(void)

{
  int i;
  
  for (i = 0; i < 4; i = i + 1) {
    if (timer[i].doCallback != false) {
      (*timer[i].callback)(i,timer[i].user);
    }
  }
  return;
}



// WARNING: Could not reconcile some variable overlaps

void rescheduleRtc(uint32_t rtcCnt)

{
  uint uVar1;
  bool bVar2;
  ulong _b;
  uint64_t _a;
  uint64_t min;
  int i;
  
  min._0_4_ = 0xffffffff;
  min._4_4_ = 0xffffffff;
  for (i = 0; i < 4; i = i + 1) {
    if (timer[i].running != false) {
      uVar1 = *(uint *)((int)&timer[i].remaining + 4);
      bVar2 = min._4_4_ <= uVar1;
      if (uVar1 == min._4_4_) {
        bVar2 = (uint)min <= *(uint *)&timer[i].remaining;
      }
      if (!bVar2) {
        min._0_4_ = *(uint *)&timer[i].remaining;
        min._4_4_ = *(uint *)((int)&timer[i].remaining + 4);
      }
    }
  }
  rtcRunning = false;
  if (min._4_4_ != 0xffffffff || (uint)min != 0xffffffff) {
    bVar2 = min._4_4_ == 0;
    if (min._4_4_ == 0) {
      bVar2 = (uint)min < 0xffffff9c;
    }
    if (!bVar2) {
      min._0_4_ = 0xffffff9b;
    }
    lastStart = rtcCnt;
    RTCC_IntClear(4);
    RTCC_ChannelCCVSet(1,rtcCnt + (uint)min);
    rtcRunning = true;
    RTCC_IntEnable(4);
  }
  return;
}



void NVIC_ClearPendingIRQ(IRQn_Type IRQn)

{
  *(int *)(&DAT_e000e100 + (((uint)(int)IRQn >> 5) + 0x60) * 4) = 1 << (IRQn & 0x1fU);
  return;
}



uint32_t RTCC_CounterGet(void)

{
  uint uVar1;
  
  uVar1 = (Peripherals::RTCC.CNT);
  return uVar1;
}



// WARNING: Could not reconcile some variable overlaps

void UDELAY_Calibrate(void)

{
  uint uVar1;
  uint uVar2;
  CMU_Select_TypeDef ref;
  CMU_ClkDiv_TypeDef div;
  CORE_irqState_t irqState_00;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  RTCC_Init_TypeDef init;
  CORE_irqState_t irqState;
  CMU_ClkDiv_TypeDef rtcClkDiv;
  CMU_Select_TypeDef lfaClkSel;
  uint32_t rtcIen;
  uint32_t rtcCtrl;
  _Bool lfaClkTurnoff;
  _Bool lfaClkSrcRestore;
  _Bool rtcClkTurnoff;
  _Bool leClkTurnoff;
  _Bool rtcRestore;
  
  init._0_4_ = 1;
  init._4_4_ = 5;
  init.disLeapYearCorr = false;
  rtcCtrl = 0;
  rtcIen = 0;
  uVar2 = (CMU->HFBUSCLKEN0);
  bVar3 = (uVar2 & 1) == 0;
  if (bVar3) {
    CMU_ClockEnable(cmuClock_HFLE,true);
  }
  ref = CMU_ClockSelectGet(cmuClock_LFE);
  uVar2 = (CMU->STATUS);
  CMU_ClockSelectSet(cmuClock_LFE,cmuSelect_LFRCO);
  div = CMU_ClockDivGet(cmuClock_RTCC);
  uVar1 = (CMU->LFECLKEN0);
  bVar4 = (uVar1 & 1) == 0;
  if (bVar4) {
    CMU_ClockEnable(cmuClock_RTCC,true);
  }
  irqState_00 = CORE_EnterAtomic();
  uVar1 = (Peripherals::RTCC.CTRL);
  bVar5 = (uVar1 & 1) != 0;
  if (bVar5) {
    rtcCtrl = (Peripherals::RTCC.CTRL);
    rtcIen = (Peripherals::RTCC.IEN);
    write_volatile_4(Peripherals::RTCC.CTRL,0);
    write_volatile_4(Peripherals::RTCC.IEN,0);
    write_volatile_4(Peripherals::RTCC.IFC,0x7ff);
    NVIC_ClearPendingIRQ(RTCC_IRQn);
  }
  init._0_4_ = (uint)((uint3)init._0_4_ & 0xffff);
  init._4_4_ = CONCAT31(init._5_3_,8);
  RTCC_Init(&init);
  calibrate_delay();
  CORE_ExitAtomic(irqState_00);
  if (bVar5) {
    CMU_ClockDivSet(cmuClock_RTCC,div);
    write_volatile_4(Peripherals::RTCC.CTRL,rtcCtrl);
    write_volatile_4(Peripherals::RTCC.IEN,rtcIen);
  }
  else {
    RTCC_Enable(false);
  }
  if (bVar4) {
    CMU_ClockEnable(cmuClock_RTCC,false);
  }
  if (ref != cmuSelect_LFRCO) {
    CMU_ClockSelectSet(cmuClock_LFE,ref);
  }
  if ((uVar2 & 0x40) == 0) {
    CMU_OscillatorEnable(cmuOsc_LFRCO,false,false);
  }
  if (bVar3) {
    CMU_ClockEnable(cmuClock_HFLE,false);
  }
  return;
}



void UDELAY_Delay(uint32_t usecs)

{
  uint uVar1;
  bool bVar2;
  
  if ((usecs != 0) &&
     (uVar1 = (loops_per_jiffy >> 0xb) * ((usecs - 1) * 0x8800 >> 0xb) >> 6, uVar1 != 0)) {
    do {
      bVar2 = uVar1 != 0;
      uVar1 = uVar1 - 1;
    } while (bVar2 && uVar1 != 0);
  }
  return;
}



void calibrate_delay(void)

{
  clock_t cVar1;
  clock_t cVar2;
  int iVar3;
  ulong ticks;
  int lps_precision;
  ulong loopbit;
  
  lps_precision = 8;
  loops_per_jiffy = 0x1000;
  do {
    loops_per_jiffy = loops_per_jiffy * 2;
    if (loops_per_jiffy == 0) break;
    cVar1 = clock();
    do {
      cVar2 = clock();
    } while (cVar1 == cVar2);
    cVar1 = clock();
    _delay(loops_per_jiffy);
    cVar2 = clock();
  } while (cVar2 == cVar1);
  loops_per_jiffy = loops_per_jiffy >> 1;
  loopbit = loops_per_jiffy;
  while ((iVar3 = lps_precision + -1, lps_precision != 0 && (loopbit = loopbit >> 1, loopbit != 0)))
  {
    loops_per_jiffy = loopbit | loops_per_jiffy;
    cVar1 = clock();
    do {
      cVar2 = clock();
    } while (cVar1 == cVar2);
    cVar1 = clock();
    _delay(loops_per_jiffy);
    cVar2 = clock();
    lps_precision = iVar3;
    if (cVar1 != cVar2) {
      loops_per_jiffy = loops_per_jiffy & ~loopbit;
    }
  }
  return;
}



clock_t clock(void)

{
  uint32_t uVar1;
  
  uVar1 = RTCC_CounterGet();
  return uVar1;
}



void _delay(uint32_t delay)

{
  bool bVar1;
  
  do {
    bVar1 = delay != 0;
    delay = delay - 1;
  } while (bVar1 && delay != 0);
  return;
}



void TIMER_IntClear(TIMER_TypeDef *timer,uint32_t flags)

{
  timer->IFC = flags;
  return;
}



uint32_t TIMER_IntGet(TIMER_TypeDef *timer)

{
  return timer->IF;
}



void TIMER0_IRQHandler(void)

{
  uint32_t uVar1;
  uint32_t flags;
  
  uVar1 = TIMER_IntGet((TIMER_TypeDef *)&Peripherals::TIMER0);
  if ((uVar1 & 0x10) != 0) {
    TIMER_IntClear((TIMER_TypeDef *)&Peripherals::TIMER0,0x10);
    timeElapsed = true;
  }
  return;
}



EMSTATUS DISPLAY_Init(void)

{
  EMSTATUS EVar1;
  EMSTATUS status;
  pDisplayDeviceDriverInitFunction_t **pDisplayDeviceDriverInitFunction;
  
  pDisplayDeviceDriverInitFunction = pDisplayDeviceDriverInitFunctions;
  if (moduleInitialized != true) {
    moduleInitialized = true;
    for (; *pDisplayDeviceDriverInitFunction != FUN_00000000;
        pDisplayDeviceDriverInitFunction = pDisplayDeviceDriverInitFunction + 1) {
      EVar1 = (**pDisplayDeviceDriverInitFunction)();
      if (EVar1 != 0) {
        return EVar1;
      }
    }
  }
  return 0;
}



EMSTATUS DISPLAY_DeviceGet(int displayDeviceNo,DISPLAY_Device_t *device)

{
  EMSTATUS status;
  
  if (moduleInitialized == true) {
    if (displayDeviceNo < 1) {
      memcpy(device,deviceTable + displayDeviceNo,0x2c);
      status = 0;
    }
    else {
      status = 0x80110002;
    }
  }
  else {
    status = 0x80110005;
  }
  return status;
}



EMSTATUS DISPLAY_DeviceRegister(DISPLAY_Device_t *device)

{
  DISPLAY_Device_t *__dest;
  EMSTATUS status;
  
  if (moduleInitialized == true) {
    if (devicesRegistered < 1) {
      __dest = deviceTable + devicesRegistered;
      devicesRegistered = devicesRegistered + 1;
      memcpy(__dest,device,0x2c);
      status = 0;
    }
    else {
      status = 0x80110001;
    }
  }
  else {
    status = 0x80110005;
  }
  return status;
}



EMSTATUS DISPLAY_Ls013b7dh03Init(void)

{
  EMSTATUS EVar1;
  DISPLAY_Device_t display;
  EMSTATUS status;
  
  PAL_TimerInit();
  PAL_SpiInit();
  PAL_GpioInit();
  PAL_GpioPinModeSet(2,8,palGpioModePushPull,0);
  PAL_GpioPinModeSet(2,6,palGpioModePushPull,0);
  PAL_GpioPinModeSet(3,0xe,palGpioModePushPull,0);
  PAL_GpioPinModeSet(3,0xf,palGpioModePushPull,0);
  PAL_GpioPinModeSet(3,0xd,palGpioModePushPull,0);
  EVar1 = PAL_TimerRepeat(DisplayPolarityInverse + 1,(void *)0x0,0x80);
  if (EVar1 == 0) {
    display.name = "Sharp LS013B7DH03 #1";
    display.colourMode = DISPLAY_COLOUR_MODE_MONOCHROME_INVERSE;
    display.addressMode = DISPLAY_ADDRESSING_BY_ROWS_ONLY;
    display.geometry.width = 0x80;
    display.geometry.height = 0x80;
    display.geometry.stride = 0x80;
    display.pDisplayPowerOn = DisplayEnable;
    display.pPixelMatrixAllocate = PixelMatrixAllocate + 1;
    display.pPixelMatrixFree = PixelMatrixFree + 1;
    display.pPixelMatrixDraw = PixelMatrixDraw + 1;
    display.pPixelMatrixClear = PixelMatrixClear + 1;
    display.pDriverRefresh = DriverRefresh + 1;
    EVar1 = DISPLAY_DeviceRegister(&display);
    if (EVar1 == 0) {
      DisplayEnable(&display,true);
      DisplayClear();
    }
  }
  return EVar1;
}



EMSTATUS DriverRefresh(DISPLAY_Device_t *device)

{
  EMSTATUS status;
  
  PAL_TimerInit();
  PAL_SpiInit();
  return 0;
}



EMSTATUS DisplayEnable(DISPLAY_Device_t *device,_Bool enable)

{
  if (enable == false) {
    PAL_GpioPinOutClear(3,0xf);
  }
  else {
    PAL_GpioPinOutSet(3,0xf);
  }
  return 0;
}



EMSTATUS DisplayClear(void)

{
  uint16_t cmd;
  
  PAL_GpioPinOutSet(3,0xe);
  PAL_TimerMicroSecondsDelay(6);
  cmd = (uint16_t)(lcdPolarity | 4);
  PAL_SpiTransmit((uint8_t *)&cmd,2);
  PAL_TimerMicroSecondsDelay(2);
  PAL_GpioPinOutClear(3,0xe);
  return 0;
}



EMSTATUS DisplayPolarityInverse(void)

{
  PAL_GpioPinOutToggle(3,0xd);
  return 0;
}



EMSTATUS PixelMatrixAllocate(DISPLAY_Device_t *device,uint width,uint height,
                            DISPLAY_PixelMatrix_t *pixelMatrix)

{
  int iVar1;
  EMSTATUS EVar2;
  uint allocSize;
  
  iVar1 = (width >> 3) * height;
  if (width == 0x80) {
    if (pixelMatrixPool + iVar1 < (PixelMatrixAlign_t *)0x20002c09) {
      *pixelMatrix = pixelMatrixPool;
      pixelMatrixPool = pixelMatrixPool + iVar1;
      EVar2 = 0;
    }
    else {
      *pixelMatrix = (DISPLAY_PixelMatrix_t)0x0;
      EVar2 = 0x80110001;
    }
  }
  else {
    EVar2 = 0x80110002;
  }
  return EVar2;
}



EMSTATUS PixelMatrixFree(DISPLAY_Device_t *device,DISPLAY_PixelMatrix_t pixelMatrix)

{
  return 0x80110004;
}



EMSTATUS PixelMatrixClear(DISPLAY_Device_t *device,DISPLAY_PixelMatrix_t pixelMatrix,uint width,
                         uint height)

{
  uint i;
  uint8_t *pByte;
  
  pByte = (uint8_t *)pixelMatrix;
  for (i = 0; i < height; i = i + 1) {
    memset(pByte,0,0x10);
    pByte = pByte + 0x10;
  }
  return 0;
}



EMSTATUS PixelMatrixDraw(DISPLAY_Device_t *device,DISPLAY_PixelMatrix_t pixelMatrix,uint startColumn
                        ,uint width,uint startRow,uint height)

{
  uint16_t cmd;
  uint16_t *p;
  uint i;
  
  p = (uint16_t *)pixelMatrix;
  PAL_GpioPinOutSet(3,0xe);
  PAL_TimerMicroSecondsDelay(6);
  cmd = (ushort)((startRow + 1 & 0xff) << 8) | 1;
  PAL_SpiTransmit((uint8_t *)&cmd,2);
  for (i = 0; i < height; i = i + 1) {
    PAL_SpiTransmit((uint8_t *)p,0x10);
    p = p + 8;
    if (i == height - 1) {
      cmd = 0xffff;
    }
    else {
      cmd = (ushort)((((i & 0xffff) + (startRow + 1 & 0xffff) & 0xffff) + 1 & 0xff) << 8) | 0xff;
    }
    PAL_SpiTransmit((uint8_t *)&cmd,2);
  }
  PAL_TimerMicroSecondsDelay(2);
  PAL_GpioPinOutClear(3,0xe);
  return 0;
}



void BUS_RegBitWrite(uint32_t *addr,uint bit,uint val)

{
  uint32_t aliasAddr;
  
  *(uint *)((bit + (int)(addr + 0x840000) * 8) * 4) = val;
  return;
}



void GPIO_PinOutClear(GPIO_Port_TypeDef port,uint pin)

{
  BUS_RegBitWrite(&Peripherals::GPIO.PA_DOUT + (uint)port * 0xc,pin,0);
  return;
}



void GPIO_PinOutSet(GPIO_Port_TypeDef port,uint pin)

{
  BUS_RegBitWrite(&Peripherals::GPIO.PA_DOUT + (uint)port * 0xc,pin,1);
  return;
}



void GPIO_PinOutToggle(GPIO_Port_TypeDef port,uint pin)

{
  (&Peripherals::GPIO.PA_DOUTTGL)[(uint)port * 0xc] = 1 << (pin & 0xff);
  return;
}



// WARNING: Could not reconcile some variable overlaps

EMSTATUS PAL_SpiInit(void)

{
  uint uVar1;
  USART_InitSync_TypeDef usartInit;
  EMSTATUS status;
  
  usartInit._0_4_ = 5;
  usartInit.refFreq = 0;
  usartInit.baudrate = 1000000;
  usartInit._12_4_ = 0x105;
  usartInit._16_4_ = 0;
  usartInit._20_4_ = 0;
  CMU_ClockEnable(cmuClock_USART1,true);
  usartInit.baudrate = 3500000;
  USART_InitSync((USART_TypeDef *)&Peripherals::USART1,&usartInit);
  write_volatile_4(Peripherals::USART1.ROUTEPEN,10);
  uVar1 = (Peripherals::USART1.ROUTELOC0);
  write_volatile_4(Peripherals::USART1.ROUTELOC0,uVar1 & 0xe0ffe0ff | 0xb000b00);
  return 0;
}



EMSTATUS PAL_SpiTransmit(uint8_t *data,uint len)

{
  uint uVar1;
  uint local_18;
  uint16_t *local_14;
  EMSTATUS status;
  
  local_18 = len;
  local_14 = (uint16_t *)data;
  while (local_18 != 0) {
    if ((local_18 == 1) || (((uint)local_14 & 1) != 0)) {
      USART_Tx((USART_TypeDef *)&Peripherals::USART1,*(uint8_t *)local_14);
      local_18 = local_18 - 1;
      local_14 = (uint16_t *)((int)local_14 + 1);
    }
    else {
      USART_TxDouble((USART_TypeDef *)&Peripherals::USART1,*local_14);
      local_18 = local_18 - 2;
      local_14 = local_14 + 1;
    }
  }
  do {
    uVar1 = (Peripherals::USART1.STATUS);
  } while ((uVar1 & 0x20) == 0);
  return 0;
}



EMSTATUS PAL_TimerInit(void)

{
  EMSTATUS status;
  
  UDELAY_Calibrate();
  return 0;
}



EMSTATUS PAL_TimerMicroSecondsDelay(uint usecs)

{
  EMSTATUS status;
  
  UDELAY_Delay(usecs);
  return 0;
}



EMSTATUS PAL_TimerRepeat(anon_subr_void_void_ptr *pFunction,void *argument,uint frequency)

{
  int iVar1;
  EMSTATUS EVar2;
  
  iVar1 = rtcIntCallbackRegister(pFunction,argument,frequency);
  if (iVar1 == 0) {
    EVar2 = 0;
  }
  else {
    EVar2 = 0x80130002;
  }
  return EVar2;
}



EMSTATUS PAL_GpioInit(void)

{
  EMSTATUS status;
  
  CMU_ClockEnable(cmuClock_GPIO,true);
  return 0;
}



EMSTATUS PAL_GpioPinModeSet(uint port,uint pin,PAL_GpioMode_t mode,uint platformSpecific)

{
  EMSTATUS EVar1;
  GPIO_Mode_TypeDef emGpioMode;
  EMSTATUS status;
  
  if (mode == palGpioModePushPull) {
    GPIO_PinModeSet((GPIO_Port_TypeDef)port,pin,gpioModePushPull,platformSpecific);
    EVar1 = 0;
  }
  else {
    EVar1 = 0x80130001;
  }
  return EVar1;
}



EMSTATUS PAL_GpioPinOutSet(uint port,uint pin)

{
  EMSTATUS status;
  
  GPIO_PinOutSet((GPIO_Port_TypeDef)port,pin);
  return 0;
}



EMSTATUS PAL_GpioPinOutClear(uint port,uint pin)

{
  EMSTATUS status;
  
  GPIO_PinOutClear((GPIO_Port_TypeDef)port,pin);
  return 0;
}



EMSTATUS PAL_GpioPinOutToggle(uint port,uint pin)

{
  EMSTATUS status;
  
  GPIO_PinOutToggle((GPIO_Port_TypeDef)port,pin);
  return 0;
}



EMSTATUS DMD_init(DMD_InitConfig *initConfig)

{
  EMSTATUS EVar1;
  EMSTATUS status;
  
  if (moduleInitialized == false) {
    EVar1 = DISPLAY_Init();
    if (((EVar1 == 0) && (EVar1 = DISPLAY_DeviceGet(0,&displayDevice), EVar1 == 0)) &&
       (EVar1 = DMD_allocateFramebuffer(&pixelMatrixBuffer), EVar1 == 0)) {
      if (pixelMatrixBuffer == (DISPLAY_PixelMatrix_t)0x0) {
        EVar1 = 0xb;
      }
      else {
        dimensions.xSize = (uint16_t)displayDevice.geometry.width;
        dimensions.ySize = (uint16_t)displayDevice.geometry.height;
        dimensions.xClipStart = 0;
        dimensions.yClipStart = 0;
        moduleInitialized = true;
        dimensions.clipWidth = dimensions.xSize;
        dimensions.clipHeight = dimensions.ySize;
        DMD_writeColor(0,0,'\0','\0','\0',
                       (displayDevice.geometry.height & 0xffff) *
                       (displayDevice.geometry.width & 0xffff));
        EVar1 = 0;
      }
    }
  }
  else {
    EVar1 = 0;
  }
  return EVar1;
}



EMSTATUS DMD_getDisplayGeometry(DMD_DisplayGeometry **geometry)

{
  bool bVar1;
  
  bVar1 = moduleInitialized == true;
  if (bVar1) {
    *geometry = &dimensions;
  }
  return (uint)!bVar1;
}



EMSTATUS DMD_setClippingArea(uint16_t xStart,uint16_t yStart,uint16_t width,uint16_t height)

{
  EMSTATUS EVar1;
  
  if (moduleInitialized == true) {
    if (((uint)dimensions.xSize < (uint)width + (uint)xStart) ||
       ((uint)dimensions.ySize < (uint)height + (uint)yStart)) {
      EVar1 = 4;
    }
    else {
      if ((width == 0) || (height == 0)) {
        EVar1 = 5;
      }
      else {
        EVar1 = 0;
        dimensions.xClipStart = xStart;
        dimensions.yClipStart = yStart;
        dimensions.clipWidth = width;
        dimensions.clipHeight = height;
      }
    }
  }
  else {
    EVar1 = 1;
  }
  return EVar1;
}



EMSTATUS DMD_writeColor(uint16_t x,uint16_t y,uint8_t red,uint8_t green,uint8_t blue,
                       uint32_t numPixels)

{
  byte bVar1;
  DISPLAY_PixelMatrix_t pvVar2;
  byte bVar3;
  ushort uVar4;
  EMSTATUS EVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint16_t local_3a;
  int numBytesToCopy;
  uint8_t pixelMask;
  uint8_t matrixByte;
  int byteOffset;
  uint8_t *pStartRow;
  uint8_t pixelData;
  int pixelColour;
  int bytesPerRow;
  int rows;
  uint8_t *pDst;
  uint rowPixels;
  
  pvVar2 = pixelMatrixBuffer;
  if (moduleInitialized == true) {
    if (pixelMatrixBuffer == (DISPLAY_PixelMatrix_t)0x0) {
      EVar5 = 1;
    }
    else {
      if (displayDevice.addressMode == DISPLAY_ADDRESSING_BY_ROWS_ONLY) {
        rows = 0;
        uVar6 = displayDevice.geometry.stride >> 3;
        if (displayDevice.colourMode != DISPLAY_COLOUR_MODE_MONOCHROME_INVERSE) {
          green = green == '\0';
        }
        if (green == '\0') {
          bVar3 = 0;
        }
        else {
          bVar3 = 0xff;
        }
        uVar4 = y + dimensions.yClipStart;
        local_3a = x;
        while (numPixels != 0) {
          rowPixels = numPixels;
          if ((uint)dimensions.clipWidth - (uint)local_3a <= numPixels) {
            rowPixels = (uint)dimensions.clipWidth - (uint)local_3a;
          }
          numPixels = numPixels - rowPixels;
          local_3a = local_3a + dimensions.xClipStart;
          iVar7 = (int)pvVar2 + uVar6 * rows + uVar6 * uVar4;
          if (rowPixels < 8) {
            uVar8 = (uint)local_3a;
            if (green == '\0') {
              for (; (uint)local_3a < uVar8 + rowPixels; local_3a = local_3a + 1) {
                *(byte *)(iVar7 + (uint)(local_3a >> 3)) =
                     ~(byte)(1 << (local_3a & 7)) & *(byte *)(iVar7 + (uint)(local_3a >> 3));
              }
            }
            else {
              for (; (uint)local_3a < uVar8 + rowPixels; local_3a = local_3a + 1) {
                *(byte *)(iVar7 + (uint)(local_3a >> 3)) =
                     (byte)(1 << (local_3a & 7)) | *(byte *)(iVar7 + (uint)(local_3a >> 3));
              }
            }
          }
          else {
            pDst = (uint8_t *)(iVar7 + (uint)(local_3a >> 3));
            if ((local_3a & 7) != 0) {
              bVar1 = (char)(1 << (local_3a & 7)) - 1;
              *pDst = bVar1 & *pDst | bVar3 & ~bVar1;
              pDst = pDst + 1;
              rowPixels = (rowPixels + (local_3a & 7)) - 8;
            }
            uVar8 = rowPixels >> 3;
            if (uVar8 != 0) {
              memset(pDst,(uint)bVar3,uVar8);
              rowPixels = rowPixels + uVar8 * -8;
              pDst = pDst + uVar8;
            }
            if (rowPixels != 0) {
              bVar1 = (char)(1 << (rowPixels & 0xff)) - 1;
              *pDst = *pDst & ~bVar1 | bVar1 & bVar3;
            }
          }
          dirtyRows[(int)(rows + (uint)uVar4) >> 5] =
               dirtyRows[(int)(rows + (uint)uVar4) >> 5] | 1 << (rows + (uint)uVar4 & 0x1f);
          local_3a = 0;
          rows = rows + 1;
        }
        EVar5 = 0;
      }
      else {
        EVar5 = 10;
      }
    }
  }
  else {
    EVar5 = 1;
  }
  return EVar5;
}



EMSTATUS DMD_sleep(void)

{
  EMSTATUS EVar1;
  
  EVar1 = (*displayDevice.pDisplayPowerOn)(&displayDevice,false);
  return EVar1;
}



EMSTATUS DMD_wakeUp(void)

{
  EMSTATUS EVar1;
  
  EVar1 = (*displayDevice.pDisplayPowerOn)(&displayDevice,true);
  return EVar1;
}



EMSTATUS DMD_allocateFramebuffer(void **framebuffer)

{
  EMSTATUS EVar1;
  
  (*displayDevice.pPixelMatrixAllocate)
            (&displayDevice,displayDevice.geometry.width,displayDevice.geometry.height,
             &pixelMatrixBuffer);
  if (pixelMatrixBuffer == (DISPLAY_PixelMatrix_t)0x0) {
    EVar1 = 0xb;
  }
  else {
    *framebuffer = pixelMatrixBuffer;
    memset(dirtyRows,0xff,0x10);
    EVar1 = 0;
  }
  return EVar1;
}



EMSTATUS DMD_updateDisplay(void)

{
  EMSTATUS EVar1;
  uint uVar2;
  EMSTATUS status;
  uint8_t *pStartRow;
  int bytesPerRow;
  int dirtyWordCnt;
  uint32_t dirtyFlags;
  uint consecutiveDirtyRows;
  uint startRow;
  
  uVar2 = displayDevice.geometry.stride >> 3;
  dirtyFlags = dirtyRows[0];
  dirtyWordCnt = 1;
  startRow = 0;
  consecutiveDirtyRows = 0;
  do {
    if (displayDevice.geometry.height <= startRow + consecutiveDirtyRows) {
      if ((consecutiveDirtyRows == 0) ||
         (EVar1 = (*displayDevice.pPixelMatrixDraw)
                            (&displayDevice,
                             (DISPLAY_PixelMatrix_t)(startRow * uVar2 + (int)pixelMatrixBuffer),0,
                             displayDevice.geometry.width,startRow,consecutiveDirtyRows), EVar1 == 0
         )) {
        memset(dirtyRows,0,0x10);
        EVar1 = 0;
      }
      return EVar1;
    }
    if ((dirtyFlags & 1) == 0) {
      if (consecutiveDirtyRows == 0) {
        startRow = startRow + 1;
      }
      else {
        EVar1 = (*displayDevice.pPixelMatrixDraw)
                          (&displayDevice,
                           (DISPLAY_PixelMatrix_t)(startRow * uVar2 + (int)pixelMatrixBuffer),0,
                           displayDevice.geometry.width,startRow,consecutiveDirtyRows);
        if (EVar1 != 0) {
          return EVar1;
        }
        startRow = startRow + consecutiveDirtyRows + 1;
        consecutiveDirtyRows = 0;
      }
    }
    else {
      consecutiveDirtyRows = consecutiveDirtyRows + 1;
    }
    if ((consecutiveDirtyRows + startRow & 0x1f) == 0) {
      dirtyFlags = dirtyRows[dirtyWordCnt];
      dirtyWordCnt = dirtyWordCnt + 1;
    }
    else {
      dirtyFlags = dirtyFlags >> 1;
    }
  } while( true );
}



void GLIB_colorTranslate24bppInl(uint32_t color,uint8_t *red,uint8_t *green,uint8_t *blue)

{
  *red = (uint8_t)(color >> 0x10);
  *green = (uint8_t)(color >> 8);
  *blue = (uint8_t)color;
  return;
}



EMSTATUS GLIB_contextInit(GLIB_Context_t *pContext)

{
  GLIB_Rectangle_t tmpRect;
  DMD_DisplayGeometry *pTmpDisplayGeometry;
  EMSTATUS status;
  
  if (pContext == (GLIB_Context_t *)0x0) {
    status = 5;
  }
  else {
    pContext->backgroundColor = 0;
    pContext->foregroundColor = 0xffffff;
    status = DMD_getDisplayGeometry(&pTmpDisplayGeometry);
    if (status == 0) {
      pContext->pDisplayGeometry = pTmpDisplayGeometry;
      tmpRect.xMin = 0;
      tmpRect.yMin = 0;
      tmpRect.xMax = pTmpDisplayGeometry->xSize - 1;
      tmpRect.yMax = pTmpDisplayGeometry->ySize - 1;
      status = GLIB_setClippingRegion(pContext,&tmpRect);
      if (status == 0) {
        GLIB_setFont(pContext,&GLIB_FontNormal8x8);
      }
    }
  }
  return status;
}



EMSTATUS GLIB_displayWakeUp(void)

{
  EMSTATUS EVar1;
  
  EVar1 = DMD_wakeUp();
  return EVar1;
}



EMSTATUS GLIB_displaySleep(void)

{
  EMSTATUS EVar1;
  
  EVar1 = DMD_sleep();
  return EVar1;
}



EMSTATUS GLIB_setClippingRegion(GLIB_Context_t *pContext,GLIB_Rectangle_t *pRect)

{
  EMSTATUS EVar1;
  int32_t iVar2;
  int32_t iVar3;
  int32_t iVar4;
  GLIB_Rectangle_t tmpRect;
  
  if ((pContext == (GLIB_Context_t *)0x0) || (pRect == (GLIB_Rectangle_t *)0x0)) {
    EVar1 = 5;
  }
  else {
    if ((pRect->xMin < pRect->xMax) && (pRect->yMin < pRect->yMax)) {
      if ((((pRect->xMin < 0) || (pRect->yMin < 0)) ||
          ((int)(pContext->pDisplayGeometry->xSize - 1) < pRect->xMax)) ||
         ((int)(pContext->pDisplayGeometry->ySize - 1) < pRect->yMax)) {
        EVar1 = 3;
      }
      else {
        iVar2 = pRect->yMin;
        iVar3 = pRect->xMax;
        iVar4 = pRect->yMax;
        (pContext->clippingRegion).xMin = pRect->xMin;
        (pContext->clippingRegion).yMin = iVar2;
        (pContext->clippingRegion).xMax = iVar3;
        (pContext->clippingRegion).yMax = iVar4;
        EVar1 = GLIB_applyClippingRegion(pContext);
      }
    }
    else {
      EVar1 = 4;
    }
  }
  return EVar1;
}



EMSTATUS GLIB_clear(GLIB_Context_t *pContext)

{
  uint8_t blue;
  uint8_t green;
  uint8_t red;
  uint32_t height;
  uint32_t width;
  EMSTATUS status;
  
  if (pContext == (GLIB_Context_t *)0x0) {
    status = 5;
  }
  else {
    GLIB_colorTranslate24bpp(pContext->backgroundColor,&red,&green,&blue);
    status = GLIB_resetDisplayClippingArea(pContext);
    if (status == 0) {
      width = (uint32_t)pContext->pDisplayGeometry->clipWidth;
      height = (uint32_t)pContext->pDisplayGeometry->clipHeight;
      status = DMD_writeColor(0,0,red,green,blue,height * width);
    }
  }
  return status;
}



EMSTATUS GLIB_resetDisplayClippingArea(GLIB_Context_t *pContext)

{
  EMSTATUS EVar1;
  
  if (pContext == (GLIB_Context_t *)0x0) {
    EVar1 = 5;
  }
  else {
    EVar1 = DMD_setClippingArea(0,0,pContext->pDisplayGeometry->xSize,
                                pContext->pDisplayGeometry->ySize);
  }
  return EVar1;
}



EMSTATUS GLIB_applyClippingRegion(GLIB_Context_t *pContext)

{
  EMSTATUS EVar1;
  
  if (pContext == (GLIB_Context_t *)0x0) {
    EVar1 = 5;
  }
  else {
    EVar1 = DMD_setClippingArea((uint16_t)(pContext->clippingRegion).xMin,
                                (uint16_t)(pContext->clippingRegion).yMin,
                                ((short)(pContext->clippingRegion).xMax -
                                (short)(pContext->clippingRegion).xMin) + 1,
                                ((short)(pContext->clippingRegion).yMax -
                                (short)(pContext->clippingRegion).yMin) + 1);
  }
  return EVar1;
}



void GLIB_colorTranslate24bpp(uint32_t color,uint8_t *red,uint8_t *green,uint8_t *blue)

{
  GLIB_colorTranslate24bppInl(color,red,green,blue);
  return;
}



EMSTATUS GLIB_drawPixel(GLIB_Context_t *pContext,int32_t x,int32_t y)

{
  _Bool _Var1;
  EMSTATUS EVar2;
  uint8_t blue;
  uint8_t green;
  uint8_t red;
  
  if (pContext == (GLIB_Context_t *)0x0) {
    EVar2 = 5;
  }
  else {
    _Var1 = GLIB_rectContainsPoint(&pContext->clippingRegion,x,y);
    if (_Var1 == true) {
      GLIB_colorTranslate24bppInl(pContext->foregroundColor,&red,&green,&blue);
      EVar2 = DMD_writeColor((uint16_t)x,(uint16_t)y,red,green,blue,1);
    }
    else {
      EVar2 = 1;
    }
  }
  return EVar2;
}



EMSTATUS GLIB_drawPixelColor(GLIB_Context_t *pContext,int32_t x,int32_t y,uint32_t color)

{
  _Bool _Var1;
  EMSTATUS EVar2;
  uint8_t blue;
  uint8_t green;
  uint8_t red;
  
  if (pContext == (GLIB_Context_t *)0x0) {
    EVar2 = 5;
  }
  else {
    _Var1 = GLIB_rectContainsPoint(&pContext->clippingRegion,x,y);
    if (_Var1 == true) {
      GLIB_colorTranslate24bppInl(color,&red,&green,&blue);
      EVar2 = DMD_writeColor((uint16_t)x,(uint16_t)y,red,green,blue,1);
    }
    else {
      EVar2 = 1;
    }
  }
  return EVar2;
}



EMSTATUS GLIB_drawLineH(GLIB_Context_t *pContext,int32_t x1,int32_t y1,int32_t x2)

{
  int32_t local_28;
  int32_t local_20;
  uint8_t blue;
  uint8_t green;
  uint8_t red;
  EMSTATUS status;
  uint32_t length;
  int32_t swap;
  
  if (pContext == (GLIB_Context_t *)0x0) {
    status = 5;
  }
  else {
    if ((y1 < (pContext->clippingRegion).yMin) || ((pContext->clippingRegion).yMax < y1)) {
      status = 1;
    }
    else {
      local_28 = x2;
      local_20 = x1;
      if (x2 < x1) {
        local_28 = x1;
        local_20 = x2;
        swap = x1;
      }
      if (((pContext->clippingRegion).xMax < local_20) ||
         (local_28 < (pContext->clippingRegion).xMin)) {
        status = 1;
      }
      else {
        if (local_20 < (pContext->clippingRegion).xMin) {
          local_20 = (pContext->clippingRegion).xMin;
        }
        if ((pContext->clippingRegion).xMax < local_28) {
          local_28 = (pContext->clippingRegion).xMax;
        }
        length = (local_28 - local_20) + 1;
        status = DMD_setClippingArea((uint16_t)local_20,(uint16_t)y1,(uint16_t)length,1);
        if (status == 0) {
          GLIB_colorTranslate24bpp(pContext->foregroundColor,&red,&green,&blue);
          status = DMD_writeColor(0,0,red,green,blue,length);
          if (status == 0) {
            status = GLIB_applyClippingRegion(pContext);
          }
        }
      }
    }
  }
  return status;
}



EMSTATUS GLIB_drawLineV(GLIB_Context_t *pContext,int32_t x1,int32_t y1,int32_t y2)

{
  int32_t local_28;
  int32_t local_24;
  uint8_t blue;
  uint8_t green;
  uint8_t red;
  EMSTATUS status;
  int32_t length;
  int32_t swap;
  
  if (pContext == (GLIB_Context_t *)0x0) {
    status = 5;
  }
  else {
    if ((x1 < (pContext->clippingRegion).xMin) || ((pContext->clippingRegion).xMax < x1)) {
      status = 1;
    }
    else {
      local_28 = y2;
      local_24 = y1;
      if (y2 < y1) {
        local_28 = y1;
        local_24 = y2;
        swap = y1;
      }
      if (((pContext->clippingRegion).yMax < local_24) ||
         (local_28 < (pContext->clippingRegion).yMin)) {
        status = 1;
      }
      else {
        if (local_24 < (pContext->clippingRegion).yMin) {
          local_24 = (pContext->clippingRegion).yMin;
        }
        if ((pContext->clippingRegion).yMax < local_28) {
          local_28 = (pContext->clippingRegion).yMax;
        }
        length = (local_28 - local_24) + 1;
        status = DMD_setClippingArea((uint16_t)x1,(uint16_t)local_24,1,(uint16_t)length);
        if (status == 0) {
          GLIB_colorTranslate24bpp(pContext->foregroundColor,&red,&green,&blue);
          status = DMD_writeColor(0,0,red,green,blue,length);
          if (status == 0) {
            status = GLIB_applyClippingRegion(pContext);
          }
        }
      }
    }
  }
  return status;
}



uint8_t GLIB_getClipCode(GLIB_Context_t *pContext,int32_t x,int32_t y)

{
  uint8_t code;
  
  code = x < (pContext->clippingRegion).xMin;
  if ((pContext->clippingRegion).xMax < x) {
    code = code | 2;
  }
  if ((pContext->clippingRegion).yMax < y) {
    code = code | 4;
  }
  if (y < (pContext->clippingRegion).yMin) {
    code = code | 8;
  }
  return code;
}



_Bool GLIB_clipLine(GLIB_Context_t *pContext,int32_t *pX1,int32_t *pY1,int32_t *pX2,int32_t *pY2)

{
  int32_t y;
  int32_t x;
  uint8_t code2;
  uint8_t code1;
  uint8_t currentCode;
  
  x = 0;
  y = 0;
  code1 = GLIB_getClipCode(pContext,*pX1,*pY1);
  code2 = GLIB_getClipCode(pContext,*pX2,*pY2);
  while( true ) {
    if ((code2 | code1) == 0) {
      return true;
    }
    if ((code2 & code1) != 0) break;
    if (code1 == '\0') {
      currentCode = code2;
    }
    else {
      currentCode = code1;
    }
    if ((currentCode & 1) == 0) {
      if ((currentCode & 2) == 0) {
        if ((currentCode & 4) == 0) {
          if ((currentCode & 8) != 0) {
            y = (pContext->clippingRegion).yMin;
            x = (uint)(((pContext->clippingRegion).yMin - *pY1) * (*pX2 - *pX1)) /
                (uint)(*pY2 - *pY1) + *pX1;
          }
        }
        else {
          y = (pContext->clippingRegion).yMax;
          x = (uint)(((pContext->clippingRegion).yMax - *pY1) * (*pX2 - *pX1)) / (uint)(*pY2 - *pY1)
              + *pX1;
        }
      }
      else {
        x = (pContext->clippingRegion).xMax;
        y = (uint)(((pContext->clippingRegion).xMax - *pX1) * (*pY2 - *pY1)) / (uint)(*pX2 - *pX1) +
            *pY1;
      }
    }
    else {
      y = (uint)(((pContext->clippingRegion).xMin - *pX1) * (*pY2 - *pY1)) / (uint)(*pX2 - *pX1) +
          *pY1;
      x = (pContext->clippingRegion).xMin;
    }
    if (code1 == '\0') {
      *pX2 = x;
      *pY2 = y;
      code2 = GLIB_getClipCode(pContext,x,y);
    }
    else {
      *pX1 = x;
      *pY1 = y;
      code1 = GLIB_getClipCode(pContext,x,y);
    }
  }
  return false;
}



EMSTATUS GLIB_drawLine(GLIB_Context_t *pContext,int32_t x1,int32_t y1,int32_t x2,int32_t y2)

{
  int iVar1;
  int32_t iVar2;
  int iVar3;
  _Bool _Var4;
  EMSTATUS EVar5;
  int32_t local_38;
  int32_t local_34;
  int32_t local_30;
  GLIB_Context_t *local_2c;
  int32_t deltaY;
  int32_t deltaX;
  int32_t xMotion;
  int32_t yMotion;
  int32_t yStep;
  _Bool steepLine;
  int32_t error;
  EMSTATUS status;
  
  steepLine = false;
  yStep = 1;
  if (pContext == (GLIB_Context_t *)0x0) {
    EVar5 = 5;
  }
  else {
    local_38 = x2;
    local_34 = y1;
    local_30 = x1;
    local_2c = pContext;
    if (x1 == x2) {
      EVar5 = GLIB_drawLineV(pContext,x1,y1,y2);
    }
    else {
      if (y1 == y2) {
        EVar5 = GLIB_drawLineH(pContext,x1,y1,x2);
      }
      else {
        _Var4 = GLIB_clipLine(pContext,&local_30,&local_34,&local_38,(int32_t *)register0x00000054);
        iVar3 = local_30;
        iVar1 = local_38;
        if (_Var4 == true) {
          if (local_34 < y2) {
            yMotion = y2 - local_34;
          }
          else {
            yMotion = local_34 - y2;
          }
          if (local_30 < local_38) {
            xMotion = local_38 - local_30;
          }
          else {
            xMotion = local_30 - local_38;
          }
          if (xMotion < yMotion) {
            steepLine = true;
            local_30 = local_34;
            local_34 = iVar3;
            local_38 = y2;
            y2 = iVar1;
          }
          iVar1 = local_30;
          iVar2 = local_34;
          if (local_38 < local_30) {
            local_30 = local_38;
            local_38 = iVar1;
            local_34 = y2;
            y2 = iVar2;
          }
          deltaX = local_38 - local_30;
          if (local_34 < y2) {
            deltaY = y2 - local_34;
          }
          else {
            deltaY = local_34 - y2;
          }
          error = -deltaX / 2;
          if (y2 < local_34) {
            yStep = -1;
          }
          for (; local_30 <= local_38; local_30 = local_30 + 1) {
            if (steepLine == false) {
              status = GLIB_drawPixel(local_2c,local_30,local_34);
            }
            else {
              status = GLIB_drawPixel(local_2c,local_34,local_30);
            }
            if (status != 0) {
              return status;
            }
            error = deltaY + error;
            if (0 < error) {
              local_34 = yStep + local_34;
              error = error - deltaX;
            }
          }
          EVar5 = 0;
        }
        else {
          EVar5 = 1;
        }
      }
    }
  }
  return EVar5;
}



EMSTATUS GLIB_drawPolygon(GLIB_Context_t *pContext,uint32_t numPoints,int32_t *polyPoints)

{
  int32_t *piVar1;
  byte bVar2;
  EMSTATUS EVar3;
  int x1;
  int y1;
  bool bVar4;
  int32_t *local_3c;
  EMSTATUS status;
  int32_t firstY;
  int32_t firstX;
  int32_t endY;
  int32_t endX;
  int32_t startY;
  int32_t startX;
  uint32_t point;
  uint32_t drawnElements;
  
  drawnElements = 0;
  if (((pContext == (GLIB_Context_t *)0x0) || (polyPoints == (int32_t *)0x0)) || (numPoints < 2)) {
    EVar3 = 5;
  }
  else {
    x1 = *polyPoints;
    local_3c = polyPoints + 2;
    y1 = polyPoints[1];
    startY = y1;
    startX = x1;
    for (point = 1; point < numPoints; point = point + 1) {
      piVar1 = local_3c + 1;
      endX = *local_3c;
      local_3c = local_3c + 2;
      endY = *piVar1;
      EVar3 = GLIB_drawLine(pContext,startX,startY,endX,endY);
      if (1 < EVar3) {
        return EVar3;
      }
      if (EVar3 == 0) {
        drawnElements = drawnElements + 1;
      }
      startY = endY;
      startX = endX;
    }
    if ((endX != x1) || (endY != y1)) {
      EVar3 = GLIB_drawLine(pContext,x1,y1,endX,endY);
      if (1 < EVar3) {
        return EVar3;
      }
      if (EVar3 == 0) {
        drawnElements = drawnElements + 1;
      }
    }
    bVar4 = drawnElements == 0;
    if (bVar4) {
      drawnElements = 1;
    }
    bVar2 = (byte)drawnElements;
    if (!bVar4) {
      bVar2 = 0;
    }
    EVar3 = (EMSTATUS)bVar2;
  }
  return EVar3;
}



_Bool GLIB_rectContainsPoint(GLIB_Rectangle_t *pRect,int32_t x,int32_t y)

{
  _Bool _Var1;
  
  if ((((pRect == (GLIB_Rectangle_t *)0x0) || (x < pRect->xMin)) || (pRect->xMax < x)) ||
     ((y < pRect->yMin || (pRect->yMax < y)))) {
    _Var1 = false;
  }
  else {
    _Var1 = true;
  }
  return _Var1;
}



EMSTATUS GLIB_drawChar(GLIB_Context_t *pContext,char myChar,int32_t x,int32_t y,_Bool opaque)

{
  uint8_t uVar1;
  byte bVar2;
  EMSTATUS EVar3;
  void *pvVar4;
  void *pvVar5;
  void *pvVar6;
  bool bVar7;
  EMSTATUS status;
  uint32_t *pPixMap32;
  uint16_t *pPixMap16;
  uint8_t *pPixMap8;
  uint32_t drawnElements;
  uint16_t xOffset;
  uint16_t currentRow;
  uint16_t row;
  uint16_t fontIdx;
  
  drawnElements = 0;
  if (pContext == (GLIB_Context_t *)0x0) {
    EVar3 = 5;
  }
  else {
    if (((byte)myChar < 0x20) || (0x7e < (byte)myChar)) {
      EVar3 = 2;
    }
    else {
      if ((pContext->font).class == NumbersOnlyFont) {
        fontIdx = (byte)myChar - 0x30;
        if (myChar == ':') {
          fontIdx = 10;
        }
        if (myChar == ' ') {
          fontIdx = 0xb;
        }
      }
      else {
        fontIdx = (byte)myChar - 0x20;
      }
      if ((int)((pContext->font).cntOfMapElements - 1) < (int)(uint)fontIdx) {
        EVar3 = 2;
      }
      else {
        pvVar4 = (pContext->font).pFontPixMap;
        pvVar5 = (pContext->font).pFontPixMap;
        pvVar6 = (pContext->font).pFontPixMap;
        for (row = 0; row < (pContext->font).fontHeight; row = row + 1) {
          uVar1 = (pContext->font).sizeOfMapElement;
          if (uVar1 == '\x01') {
            currentRow = (uint16_t)*(byte *)((uint)fontIdx + (int)pvVar4);
          }
          else {
            if (uVar1 == '\x02') {
              currentRow = *(uint16_t *)((uint)fontIdx * 2 + (int)pvVar5);
            }
            else {
              currentRow = (uint16_t)*(undefined4 *)((uint)fontIdx * 4 + (int)pvVar6);
            }
          }
          for (xOffset = 0; xOffset < (pContext->font).fontWidth; xOffset = xOffset + 1) {
            if ((currentRow & 1) == 0) {
              if (opaque != false) {
                EVar3 = GLIB_drawPixelColor(pContext,(uint)xOffset + x,(uint)row + y,
                                            pContext->backgroundColor);
                if (1 < EVar3) {
                  return EVar3;
                }
                if (EVar3 == 0) {
                  drawnElements = drawnElements + 1;
                }
              }
            }
            else {
              EVar3 = GLIB_drawPixel(pContext,(uint)xOffset + x,y + (uint)row);
              if (1 < EVar3) {
                return EVar3;
              }
              if (EVar3 == 0) {
                drawnElements = drawnElements + 1;
              }
            }
            currentRow = currentRow >> 1;
          }
          for (; xOffset < (ushort)((ushort)(pContext->font).charSpacing +
                                   (ushort)(pContext->font).fontWidth); xOffset = xOffset + 1) {
            if (opaque != false) {
              EVar3 = GLIB_drawPixelColor(pContext,(uint)xOffset + x,(uint)row + y,
                                          pContext->backgroundColor);
              if (1 < EVar3) {
                return EVar3;
              }
              if (EVar3 == 0) {
                drawnElements = drawnElements + 1;
              }
            }
          }
          fontIdx = fontIdx + (pContext->font).fontRowOffset;
        }
        bVar7 = drawnElements == 0;
        if (bVar7) {
          drawnElements = 1;
        }
        bVar2 = (byte)drawnElements;
        if (!bVar7) {
          bVar2 = 0;
        }
        EVar3 = (EMSTATUS)bVar2;
      }
    }
  }
  return EVar3;
}



EMSTATUS GLIB_drawString(GLIB_Context_t *pContext,char *pString,uint32_t sLength,int32_t x0,
                        int32_t y0,_Bool opaque)

{
  byte bVar1;
  EMSTATUS EVar2;
  bool bVar3;
  EMSTATUS status;
  int32_t y;
  int32_t x;
  uint32_t stringIndex;
  uint32_t drawnElements;
  
  drawnElements = 0;
  if ((pContext == (GLIB_Context_t *)0x0) || (pString == (char *)0x0)) {
    EVar2 = 5;
  }
  else {
    if ((pContext->font).class == InvalidFont) {
      EVar2 = 2;
    }
    else {
      y = y0;
      x = x0;
      for (stringIndex = 0; stringIndex < sLength; stringIndex = stringIndex + 1) {
        if (pString[stringIndex] == '\n') {
          y = y + (uint)(pContext->font).fontHeight + (uint)(pContext->font).lineSpacing;
          x = x0;
        }
        else {
          EVar2 = GLIB_drawChar(pContext,pString[stringIndex],x,y,opaque);
          if (1 < EVar2) {
            return EVar2;
          }
          if (EVar2 == 0) {
            drawnElements = drawnElements + 1;
          }
          x = (uint)(pContext->font).charSpacing + (uint)(pContext->font).fontWidth + x;
        }
      }
      bVar3 = drawnElements == 0;
      if (bVar3) {
        drawnElements = 1;
      }
      bVar1 = (byte)drawnElements;
      if (!bVar3) {
        bVar1 = 0;
      }
      EVar2 = (EMSTATUS)bVar1;
    }
  }
  return EVar2;
}



EMSTATUS GLIB_setFont(GLIB_Context_t *pContext,GLIB_Font_t *pFont)

{
  EMSTATUS EVar1;
  
  if (pContext == (GLIB_Context_t *)0x0) {
    EVar1 = 5;
  }
  else {
    if (pFont == (GLIB_Font_t *)0x0) {
      memset(&pContext->font,0,0x10);
      EVar1 = 5;
    }
    else {
      memcpy(&pContext->font,pFont,0x10);
      EVar1 = 0;
    }
  }
  return EVar1;
}



void GRAPHICS_Init(void)

{
  EMSTATUS EVar1;
  EMSTATUS status;
  
  EVar1 = DISPLAY_Init();
  if (EVar1 != 0) {
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  EVar1 = DMD_init((DMD_InitConfig *)0x0);
  if (EVar1 != 0) {
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  EVar1 = GLIB_contextInit(&glibContext);
  if (EVar1 != 0) {
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  glibContext.backgroundColor = 0xffffff;
  glibContext.foregroundColor = 0;
  GLIB_setFont(&glibContext,&GLIB_FontNormal8x8);
  return;
}



void GRAPHICS_Sleep(void)

{
  GLIB_displaySleep();
  return;
}



void GRAPHICS_Wakeup(void)

{
  GLIB_displayWakeUp();
  return;
}



void GRAPHICS_Update(void)

{
  DMD_updateDisplay();
  return;
}



void GRAPHICS_Clear(void)

{
  GLIB_clear(&glibContext);
  xOffset = 5;
  yOffset = 2;
  return;
}



void GRAPHICS_AppendString(char *str)

{
  size_t sLength;
  
  sLength = strlen(str);
  GLIB_drawString(&glibContext,str,sLength,xOffset,yOffset,false);
  yOffset = yOffset + (uint)glibContext.font.lineSpacing + (uint)glibContext.font.fontHeight;
  return;
}



void GRAPHICS_InsertTriangle(uint32_t x,uint32_t y,uint32_t size,_Bool up,int8_t fillPercent)

{
  _Bool _Var1;
  int32_t polyPoints [6];
  int fillStopX;
  int fillStartX;
  int j;
  int i;
  int fillStopY;
  int fillStartY;
  
  if (up == false) {
    polyPoints[4] = x + (size >> 1);
    polyPoints[0] = x;
    polyPoints[3] = y;
  }
  else {
    polyPoints[0] = x + (size >> 1);
    polyPoints[3] = size + y;
    polyPoints[4] = x;
  }
  polyPoints[5] = size + y;
  polyPoints[2] = size + x;
  polyPoints[1] = y;
  GLIB_drawPolygon(&glibContext,3,polyPoints);
  if (((fillPercent != '\0') && (fillPercent + 100 < 0 == SCARRY4((int)fillPercent,100))) &&
     (fillPercent < 'e')) {
    i = x;
    if (fillPercent < '\0') {
      fillStopY = size + y;
      fillStartY = fillStopY - (size * (int)-fillPercent) / 100;
    }
    else {
      fillStopY = y + (size * (int)fillPercent) / 100;
      fillStartY = y;
    }
    for (; i < (int)(size + x); i = i + 1) {
      for (j = fillStartY; j < fillStopY; j = j + 1) {
        _Var1 = pointInTriangle(i,j,polyPoints);
        if (_Var1 != false) {
          GLIB_drawPixel(&glibContext,i,j);
        }
      }
    }
  }
  return;
}



int crossProduct(int32_t *points)

{
  return (points[5] - points[1]) * (points[2] - *points) -
         (points[4] - *points) * (points[3] - points[1]);
}



_Bool pointInTriangle(int x,int y,int32_t *polyPoints)

{
  int iVar1;
  _Bool _Var2;
  int32_t points [6];
  
  points[0] = *polyPoints;
  points[1] = polyPoints[1];
  points[2] = polyPoints[2];
  points[3] = polyPoints[3];
  points[4] = x;
  points[5] = y;
  iVar1 = crossProduct(points);
  if (iVar1 < 0) {
    _Var2 = false;
  }
  else {
    points[0] = polyPoints[2];
    points[1] = polyPoints[3];
    points[2] = polyPoints[4];
    points[3] = polyPoints[5];
    iVar1 = crossProduct(points);
    if (iVar1 < 0) {
      _Var2 = false;
    }
    else {
      points[0] = polyPoints[4];
      points[1] = polyPoints[5];
      points[2] = *polyPoints;
      points[3] = polyPoints[1];
      iVar1 = crossProduct(points);
      if (iVar1 < 0) {
        _Var2 = false;
      }
      else {
        _Var2 = true;
      }
    }
  }
  return _Var2;
}



int rtcIntCallbackRegister(anon_subr_void_void_ptr *pFunction,void *argument,uint frequency)

{
  return 0;
}



void Reset_Handler(void)

{
  uint32_t *puVar1;
  uint32_t *puVar2;
  
  SystemInit();
  puVar1 = (uint32_t *)&__exidx_end;
  for (puVar2 = &SystemHFXOClock; (int)puVar2 < (int)&__data_end__; puVar2 = puVar2 + 1) {
    *puVar2 = *puVar1;
    puVar1 = puVar1 + 1;
  }
                    // WARNING: Subroutine does not return
  _start();
}



void IDAC0_IRQHandler(void)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



int32_t appendToFormatString
                  (char *dest,char *src,uint32_t size,uint32_t capacity,StripMode_t stripMode)

{
  char *pcVar1;
  char *pcVar2;
  char *__n;
  int iVar3;
  uint32_t local_1c;
  char *local_18;
  char *delim;
  int32_t offset;
  
  offset = 0;
  local_1c = size;
  local_18 = src;
  if (capacity < size + 3) {
    __n = (char *)0xfffffff5;
  }
  else {
    while ((local_1c != 0 && (*local_18 == '\n'))) {
      dest[offset] = *local_18;
      local_1c = local_1c - 1;
      local_18 = local_18 + 1;
      offset = offset + 1;
    }
    dest[offset] = '{';
    memcpy(dest + offset + 1,local_18,local_1c);
    iVar3 = local_1c + offset + 1;
    __n = (char *)(iVar3 + 1);
    dest[iVar3] = '}';
    dest[(int)__n] = '\0';
    pcVar1 = strchr(dest,0x3a);
    if ((pcVar1 == (char *)0x0) && (stripMode == STRIP_NONE)) {
      __n = (char *)0xfffffff4;
    }
    else {
      if (pcVar1 != (char *)0x0) {
        pcVar2 = strchr(pcVar1 + 1,0x3a);
        if (pcVar2 == (char *)0x0) {
          if (stripMode == STRIP_TAG) {
            __n = __n + -((int)pcVar1 - (int)dest);
            memmove(dest + 1,pcVar1 + 1,(size_t)__n);
          }
          else {
            if (stripMode == STRIP_VALUE) {
              *pcVar1 = '}';
              pcVar1[1] = '\0';
              __n = pcVar1 + (1 - (int)dest);
            }
          }
        }
        else {
          __n = (char *)0xfffffff3;
        }
      }
    }
  }
  return (int32_t)__n;
}



int responsePrintInternal(StripMode_t stripMode,char *command,char *formatString,va_list args)

{
  uint32_t size;
  int rval;
  uint32_t offset;
  char *start;
  char *end;
  
  offset = 0;
  rval = 0;
  putchar(0x7b);
  start = formatString;
  end = formatString;
  if (command != (char *)0x0) {
    iprintf("{(%s)}",command);
  }
  while (end != (char *)0x0) {
    end = strchr(start,0x2c);
    if (end == (char *)0x0) {
      size = strlen(start);
    }
    else {
      size = (int)end - (int)start;
    }
    rval = appendToFormatString(buffer + offset,start,size,0x100 - offset,stripMode);
    if (rval < 0) break;
    offset = rval + offset;
    start = end + 1;
  }
  viprintf(buffer,args);
  if (rval < 0) {
    iprintf(" {internal_error:%d}",-rval);
  }
  else {
    rval = 0;
  }
  puts("}");
  return rval;
}



_Bool responsePrintHeader(char *command,char *formatString,...)

{
  int iVar1;
  undefined4 in_r2;
  undefined4 in_r3;
  va_list ap;
  undefined4 uStack8;
  undefined4 uStack4;
  
  uStack8 = in_r2;
  uStack4 = in_r3;
  putchar(0x23);
  iVar1 = responsePrintInternal(STRIP_VALUE,command,formatString,(va_list)&uStack8);
  return (_Bool)(iVar1 == 0);
}



_Bool responsePrintMulti(char *formatString,...)

{
  int iVar1;
  undefined4 in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  va_list ap;
  undefined4 uStack12;
  undefined4 uStack8;
  undefined4 uStack4;
  
  uStack12 = in_r1;
  uStack8 = in_r2;
  uStack4 = in_r3;
  iVar1 = responsePrintInternal(STRIP_TAG,(char *)0x0,formatString,(va_list)&uStack12);
  return (_Bool)(iVar1 == 0);
}



_Bool responsePrint(char *command,char *formatString,...)

{
  int iVar1;
  undefined4 in_r2;
  undefined4 in_r3;
  va_list ap;
  undefined4 uStack8;
  undefined4 uStack4;
  
  uStack8 = in_r2;
  uStack4 = in_r3;
  iVar1 = responsePrintInternal(STRIP_NONE,command,formatString,(va_list)&uStack8);
  return (_Bool)(iVar1 == 0);
}



_Bool responsePrintError(char *command,uint8_t code,char *formatString,...)

{
  undefined4 in_r3;
  va_list ap;
  undefined4 uStack4;
  
  uStack4 = in_r3;
  putchar(0x7b);
  if (command != (char *)0x0) {
    iprintf("{(%s)}",command);
  }
  iprintf("{error:");
  viprintf(formatString,&uStack4);
  putchar(0x7d);
  iprintf("{errorCode:%d}",(uint)code);
  puts("}");
  return true;
}



void apcConfigure(int param_1)

{
  RAC_SET *pRVar1;
  
  if ((apcEnabled == '\0') || (param_1 < 0x79)) {
    pRVar1 = (RAC_SET *)&Peripherals::RAC_CLR;
  }
  else {
    BUS_RegMaskedClear(&RAC->PAPKDCTRL,0xdf01);
    BUS_RegMaskedClear(&RAC->SGPAPKDCTRL,0xdf01);
    BUS_RegMaskedSet(&RAC->PAPKDCTRL,0xd700);
    BUS_RegMaskedSet(&RAC->SGPAPKDCTRL,0xd700);
    pRVar1 = &Peripherals::RAC_SET;
  }
  ((RAC_CLR *)pRVar1)->SR3 = 8;
  return;
}



int32_t PA_OutputPowerGet(void)

{
  return (int)gPaConfig.power;
}



void PA_20dbmConfigSet(void)

{
  uint uVar1;
  
  uVar1 = (SEQ->REG0E4);
  write_volatile_4(SEQ->REG0E4,uVar1 & 0xbfffffe8 | 0x40000014);
  BUS_RegMaskedClear(&RAC->PACTRL0,7);
  BUS_RegMaskedSet(&RAC->PACTRL0,4);
  BUS_RegMaskedClear(&RAC->PABIASCTRL1,7);
  BUS_RegMaskedSet(&RAC->PABIASCTRL1,5);
  BUS_RegMaskedClear(&RAC->PABIASCTRL0,0xc0);
  BUS_RegMaskedSet(&RAC->PABIASCTRL0,0x81);
  return;
}



void PA_0dbmConfigSet(void)

{
  uint uVar1;
  
  uVar1 = (SEQ->REG0E4);
  write_volatile_4(SEQ->REG0E4,uVar1 & 0xbfffffe8 | 3);
  BUS_RegMaskedClear(&RAC->PACTRL0,7);
  BUS_RegMaskedSet(&RAC->PACTRL0,3);
  BUS_RegMaskedClear(&RAC->PABIASCTRL1,7);
  BUS_RegMaskedSet(&RAC->PABIASCTRL1,6);
  BUS_RegMaskedClear(&RAC->PABIASCTRL0,0x4000c1);
  BUS_RegMaskedClear(&RAC->PAPKDCTRL,0xc000);
  return;
}



void PA_SubGhz20dbmConfigSet(void)

{
  uint uVar1;
  
  uVar1 = (SEQ->REG0E4);
  write_volatile_4(SEQ->REG0E4,uVar1 & 0xbfffffe8 | 0x40000020);
  BUS_RegMaskedClear(&RAC->SGPABIASCTRL1,0x7700);
  BUS_RegMaskedSet(&RAC->SGPABIASCTRL1,0x4500);
  BUS_RegMaskedSet(&RAC->SGPABIASCTRL0,1);
  return;
}



void PA_PowerModeConfigSet(void)

{
  if (gPaConfig.paSel == PA_SEL_SUBGIG) {
    PA_SubGhz20dbmConfigSet();
    return;
  }
  if (gPaConfig.paSel == PA_SEL_2P4_LP) {
    PA_0dbmConfigSet();
    return;
  }
  PA_20dbmConfigSet();
  return;
}



uint16_t PA_PowerLevelSet(uint8_t pwrLevel,uint8_t boostMode)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar2 = (uint)boostMode;
  uVar1 = (uint)pwrLevel;
  if (gPaConfig.paSel == PA_SEL_INVALID) {
    return 0;
  }
  if (gPaConfig.paSel != PA_SEL_2P4_LP) {
    uVar5 = (SEQ->REG0E4);
    uVar3 = uVar5 & 0xe0c03fff | 0x3fc8;
    write_volatile_4(SEQ->REG0E4,uVar3);
    uVar5 = (CMU->RFLOCK0);
    iVar4 = count_leading_zeroes(~uVar5 & 0x1fc000);
    uVar5 = (0x13 - iVar4) * 0x1f & 0xff;
    if (uVar5 <= uVar1) {
      uVar1 = uVar5;
    }
    if (uVar1 == 0) {
      write_volatile_4(RAC->APC,0x700002c);
      uVar5 = uVar1;
      uVar2 = uVar1;
    }
    else {
      write_volatile_4(RAC->APC,0x7000000);
      uVar5 = uVar1 - 1 & 0xff;
    }
    write_volatile_4(SEQ->REG0E4,
                     uVar3 | (uVar5 % 0x1f) * 0x1000000 + 0x1000000 |
                     ((1 << uVar5 / 0x1f + 1) - 1U & 0xff) << 0xe);
    if ((uVar2 == 0) || (gPaConfig.paSel != PA_SEL_2P4_HP)) {
      BUS_RegMaskedClear(&RAC->PABIASCTRL0,0x400000);
    }
    else {
      uVar1 = uVar1 | 0x100;
      BUS_RegMaskedSet(&RAC->PABIASCTRL0,0x400000);
    }
    apcConfigure(200);
    return (uint16_t)uVar1;
  }
  if (uVar1 < 8) {
    if (uVar1 == 0) {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 7;
  }
  uVar2 = (SEQ->REG0E4);
  write_volatile_4(SEQ->REG0E4,uVar2 & 0xe0c0003f | uVar1 << 0x18);
  return (uint16_t)uVar1;
}



uint32_t PA_StripesAndSlicesSet(uint32_t level)

{
  uint8_t pwrLevel;
  uint16_t uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = (level & 0x1f) + (((int)(level & 0xffff7fff) >> 5) + -1) * 0x1f;
  if (iVar2 < 1) {
    pwrLevel = '\x01';
  }
  else {
    if (0xfe < iVar2) {
      iVar2 = 0xff;
    }
    pwrLevel = (uint8_t)iVar2;
  }
  uVar1 = PA_PowerLevelSet(pwrLevel,(byte)((level << 0x10) >> 0x1f));
  if ((uVar1 & 0xff00) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0x8000;
  }
  return (uVar1 & 0xffff00ff) % 0x1f | ((uVar1 & 0xffff00ff) / 0x1f + 1) * 0x20 | uVar3;
}



uint32_t PA_StripesAndSlicesCommonCalc(int32_t power,uint16_t *table)

{
  uint32_t uVar1;
  int iVar2;
  uint uVar3;
  
  if ((short)*table <= power) {
    power = (int)(short)*table;
  }
  iVar2 = -((power - 200U) / 0x28);
  if (6 < iVar2) {
    iVar2 = 7;
  }
  uVar3 = power * (short)(table + iVar2 * 4)[3] + *(int *)(table + iVar2 * 4 + 4);
  if (0 < power) {
    uVar3 = uVar3 + 500;
  }
  uVar1 = uVar3 / 1000;
  if ((iVar2 != 7) && (gPaConfig.paSel != PA_SEL_SUBGIG)) {
    uVar1 = uVar1 | 0x8000;
  }
  return uVar1;
}



uint32_t PA_PowerFromStripesAndSlicesCommonCalc(uint32_t stripe,uint32_t slice)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 1;
  do {
    if (*(ushort *)(slice + iVar2 * 8) < stripe) break;
    iVar2 = iVar2 + 1;
  } while (iVar2 != 8);
  iVar2 = slice + (iVar2 + -1) * 8;
  uVar1 = (stripe & 0xffff7fff) * 1000 - *(int *)(iVar2 + 4);
  if (0 < (int)uVar1) {
    uVar1 = uVar1 + 500;
  }
  return uVar1 / (uint)(int)*(short *)(iVar2 + 2);
}



void PA_PowerLevelOptimize(int param_1)

{
  uint uVar1;
  RAC_CLR *pRVar2;
  
  if (gPaConfig.paSel == PA_SEL_INVALID) {
    return;
  }
  uVar1 = (SEQ->REG0E4);
  if (param_1 < 0x83) {
    write_volatile_4(SEQ->REG0E4,uVar1 & 0xffffc037 | ((uVar1 << 10) >> 0x18) << 6);
    if (param_1 < 0x1f) {
      pRVar2 = &Peripherals::RAC_CLR;
      goto LAB_0000d2da;
    }
  }
  else {
    write_volatile_4(SEQ->REG0E4,uVar1 & 0xffffc037 | 0x3fc8);
  }
  pRVar2 = (RAC_CLR *)&Peripherals::RAC_SET;
LAB_0000d2da:
  pRVar2->PABIASCTRL0 = 1;
  (&pRVar2->PABIASCTRL0)[6] = 1;
  apcConfigure();
  return;
}



void PA_StripesAndSlicesCalc(int32_t power)

{
  int iVar1;
  uint32_t uVar2;
  uint uVar3;
  
  if (gPaConfig.paSel != PA_SEL_INVALID) {
    if (gPaConfig.paSel == PA_SEL_2P4_LP) {
      uVar3 = (SEQ->REG0E4);
      iVar1 = 6;
      do {
        if ((int)*(short *)(&power0dBmParams + iVar1 * 2) <= power + gPaConfig.offset) break;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
      uVar2 = SEXT24(*(short *)(&power0dBmParams + iVar1 * 2));
      write_volatile_4(SEQ->REG0E4,uVar3 & 0xe0c0003f | (iVar1 + 1) * 0x1000000);
    }
    else {
      uVar3 = (uint)gPaConfig.voltMode;
      if (gPaConfig.paSel != PA_SEL_2P4_HP) {
        uVar3 = uVar3 + 2;
      }
      iVar1 = uVar3 * 0x44;
      uVar2 = PA_StripesAndSlicesCommonCalc
                        (power + gPaConfig.offset,(uint16_t *)(&paParams + iVar1));
      uVar2 = PA_StripesAndSlicesSet(uVar2);
      if (uVar2 == 0x21) {
        uVar2 = SEXT24(*(short *)(&DAT_0001b55a + iVar1));
      }
      else {
        uVar2 = PA_PowerFromStripesAndSlicesCommonCalc(uVar2,(uint32_t)(&UNK_0001b55c + iVar1));
      }
    }
    PA_PowerLevelOptimize(uVar2);
    gPaConfig.power = (short)uVar2 - gPaConfig.offset;
  }
  return;
}



int32_t PA_OutputPowerSet(int32_t power)

{
  PA_StripesAndSlicesCalc(power);
  return (int)gPaConfig.power;
}



void PA_PeakDetectorHighRun(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = SYNTH_Is2p4GHz();
  if (iVar3 == 0) {
    uVar1 = (RAC->SGPACTRL0);
    uVar2 = (RAC->SGPACTRL0);
    write_volatile_4(RAC->SGPACTRL0,uVar1 & 0xffc03fff | (uVar2 & 0x3f8000) >> 1);
  }
  else {
    uVar1 = (RAC->PACTRL0);
    uVar2 = (RAC->PACTRL0);
    write_volatile_4(RAC->PACTRL0,uVar1 & 0xffc03fff | (uVar2 & 0x3f8000) >> 1);
  }
  write_volatile_4(RAC->IFC,0x2000000);
  return;
}



void PA_PeakDetectorLowRun(void)

{
  return;
}



void PA_BatHighRun(void)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = SYNTH_Is2p4GHz();
  if (iVar1 == 0) {
    puVar2 = &Peripherals::RAC_CLR.SGPACTRL0;
  }
  else {
    puVar2 = &Peripherals::RAC_CLR.PACTRL0;
  }
  *puVar2 = 0x200000;
  BUS_RegMaskedClear(&RAC->IEN,0x8000000);
  return;
}



uint32_t PA_RampTimeGet(void)

{
  return (uint)gPaConfig.rampTime;
}



void PA_RampConfigSet(uint *param_1)

{
  write_volatile_4(MODEM->RAMPLEV,param_1[1]);
  BUS_RegMaskedClear(&MODEM->RAMPCTRL,0xfff);
  BUS_RegMaskedSet(&MODEM->RAMPCTRL,*param_1);
  return;
}



int PA_RampTimeCalc(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = (MODEM->RAMPLEV);
  uVar6 = (MODEM->RAMPLEV);
  uVar5 = (MODEM->RAMPLEV);
  uVar1 = (MODEM->RAMPCTRL);
  uVar2 = (MODEM->RAMPCTRL);
  uVar3 = (MODEM->RAMPCTRL);
  uVar6 = (uVar6 << 0x10) >> 0x18;
  return ((int)(((uVar5 << 8) >> 0x18) - uVar6 << ((uVar3 << 0x14) >> 0x1c)) >> 5) +
         ((int)(uVar6 - (uVar4 & 0xff) << ((uVar2 << 0x18) >> 0x1c)) >> 5) +
         ((int)((uVar4 & 0xff) << (uVar1 & 0xf)) >> 5);
}



uint32_t PA_RampTimeSet(uint32_t ramptime)

{
  uint32_t uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint32_t local_18;
  int local_14;
  
  uVar3 = (MODEM->CTRL0);
  gCurrentModulation = (byte)((uVar3 << 0x17) >> 0x1d);
  uVar3 = ((uVar3 << 0x17) >> 0x1d) - 2 & 0xff;
  if ((uVar3 < 5) && ((1 << uVar3 & 0x13U) != 0)) {
    uVar3 = 0;
  }
  else {
    if (gPaConfig.paSel == PA_SEL_SUBGIG) {
      uVar3 = 0x96;
    }
    else {
      if (gPaConfig.paSel == PA_SEL_2P4_LP) {
        uVar3 = 0x32;
      }
      else {
        uVar3 = 0xb4;
      }
    }
  }
  gDesiredRampTime = ramptime;
  local_18 = ramptime;
  uVar1 = SystemHFXOClockGet();
  cVar2 = -1;
  for (uVar4 = (((uVar1 / 1000) * ramptime) / uVar3 << 5) / 1000; uVar4 != 0; uVar4 = uVar4 >> 1) {
    cVar2 = cVar2 + '\x01';
  }
  iVar5 = (int)cVar2;
  if (iVar5 < 0x10) {
    if (iVar5 < 0) {
      iVar5 = 0;
    }
  }
  else {
    iVar5 = 0xf;
  }
  local_18 = iVar5 << 8;
  local_14 = uVar3 << 0x10;
  PA_RampConfigSet(&local_18);
  iVar5 = PA_RampTimeCalc();
  uVar1 = SystemHFXOClockGet();
  gPaConfig.rampTime = (uint16_t)((uint)(iVar5 * 10000) / (uVar1 / 100));
  TIMING_RecalculateAll();
  return (uint)gPaConfig.rampTime;
}



void PA_CTuneSet(uint8_t txPaCtuneValue,uint8_t rxPaCtuneValue)

{
  write_volatile_4(SEQ->DYNAMIC_CHPWR_TABLE,
                   txPaCtuneValue & 7 | (txPaCtuneValue & 0x1f) << 4);
  write_volatile_4(SEQ->REG0E8,rxPaCtuneValue & 7 | (rxPaCtuneValue & 0x1f) << 4);
  return;
}



void PA_BandSelect(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = SYNTH_LoDivGet();
  switch(uVar1) {
  case 1:
    uVar2 = 0x44;
    if (gPaConfig.paSel != PA_SEL_2P4_LP) {
      write_volatile_4(SEQ->DYNAMIC_CHPWR_TABLE,0);
      goto LAB_0000d59e;
    }
    break;
  default:
    uVar2 = 0xf7;
    goto LAB_0000d59a;
  case 3:
  case 4:
    uVar2 = 0;
    break;
  case 5:
  case 6:
    uVar2 = 0x33;
    break;
  case 7:
  case 8:
  case 9:
    uVar2 = 0;
LAB_0000d59a:
    write_volatile_4(SEQ->DYNAMIC_CHPWR_TABLE,uVar2);
    uVar2 = 0xa2;
    goto LAB_0000d59e;
  }
  write_volatile_4(SEQ->DYNAMIC_CHPWR_TABLE,uVar2);
LAB_0000d59e:
  write_volatile_4(SEQ->REG0E8,uVar2);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

bool RADIO_PA_Init(RADIO_PAInit_t *paInit)

{
  RADIO_PASel_t RVar1;
  uint uVar2;
  bool bVar3;
  
  if (paInit == (RADIO_PAInit_t *)0x0) {
    return false;
  }
  RADIO_CLKEnable();
  memset(&SEQ->REG0E4,0,0xc);
  RVar1 = paInit->paSel;
  if (RVar1 == PA_SEL_SUBGIG) {
    uVar2 = (CMU->RFLOCK0);
    bVar3 = (uVar2 & 0x200000) == 0;
  }
  else {
    if (RVar1 == PA_SEL_2P4_LP) {
      uVar2 = (CMU->RFLOCK0);
      bVar3 = (uVar2 & 0xc00000) == 0;
    }
    else {
      if (RVar1 != PA_SEL_2P4_HP) goto LAB_0000d600;
      uVar2 = (CMU->RFLOCK0);
      bVar3 = (_DAT_0fe081d4 & 1 ^ 1 | uVar2 & 0x400000) == 0;
    }
  }
  if (bVar3) {
    gPaConfig._0_4_ = *(undefined4 *)paInit;
    gPaConfig._4_4_ = *(undefined4 *)&paInit->offset;
    PA_RampTimeSet((uint)paInit->rampTime);
    PA_PowerModeConfigSet();
    PA_OutputPowerSet((int)paInit->power);
    BUS_RegMaskedClear(&RAC->APC,3);
    PA_BandSelect();
    return true;
  }
LAB_0000d600:
  gPaConfig._0_4_ = CONCAT31(gPaConfig._1_3_,3);
  gPaConfig._0_4_ = CONCAT22(0x8000,gPaConfig._0_2_);
  return false;
}



bool PA_UpdateConfig(void)

{
  uint uVar1;
  
  PA_BandSelect();
  uVar1 = (MODEM->CTRL0);
  if ((uint)gCurrentModulation != (uVar1 << 0x17) >> 0x1d) {
    PA_RampTimeSet(gDesiredRampTime);
    return true;
  }
  return false;
}



void RADIO_PTI_Init(RADIO_PTIInit_t *ptiInit)

{
  byte bVar1;
  GPIO_Port_TypeDef port;
  uint out;
  uint uVar2;
  
  if (ptiInit == (RADIO_PTIInit_t *)0x0) {
    return;
  }
  RADIOCMU_ClockEnable(0x63400,1);
  CMU_ClockEnable(cmuClock_GPIO,true);
  sniffBaudHz = ptiInit->baud;
  uVar2 = (uint)ptiInit->mode;
  write_volatile_4(FRC->SNIFFCTRL,0xf8);
  write_volatile_4(FRC->ROUTELOC0,
                   (uint)ptiInit->dframeLoc << 0x10 | (uint)ptiInit->dclkLoc << 8 |
                   (uint)ptiInit->doutLoc);
  if (uVar2 == 0) {
    sniffMode = 2;
    write_volatile_4(FRC->ROUTEPEN,7);
    GPIO_PinModeSet(ptiInit->dclkPort,(uint)ptiInit->dclkPin,gpioModePushPull,0);
    port = ptiInit->dframePort;
    bVar1 = ptiInit->dframePin;
    out = uVar2;
  }
  else {
    if (uVar2 != 1) {
      if (uVar2 == 2) {
        sniffMode = 5;
        write_volatile_4(FRC->ROUTEPEN,1);
      }
      else {
        if (uVar2 == 3) {
          write_volatile_4(FRC->ROUTEPEN,0);
          sniffMode = 0;
          return;
        }
      }
      goto LAB_0000d710;
    }
    port = ptiInit->dframePort;
    write_volatile_4(FRC->ROUTEPEN,5);
    bVar1 = ptiInit->dframePin;
    out = 0;
    sniffMode = uVar2;
  }
  GPIO_PinModeSet(port,(uint)bVar1,gpioModePushPull,out);
LAB_0000d710:
  GPIO_PinModeSet(ptiInit->doutPort,(uint)ptiInit->doutPin,gpioModePushPull,1);
  return;
}



void RADIO_PTI_Enable(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = (FRC->SNIFFCTRL);
  uVar3 = sniffBaudHz;
  if (sniffBaudHz != 0) {
    iVar2 = RADIOCMU_ClockFreqGet(0x63400);
    uVar3 = ((iVar2 + (sniffBaudHz >> 1)) / sniffBaudHz - 1) * 0x100;
  }
  BUS_RegMaskedSet(&RAC->SR3,0x40000000);
  write_volatile_4(FRC->SNIFFCTRL,uVar3 | uVar1 & 0xffff00fc | sniffMode);
  return;
}



void RADIO_PTI_Disable(void)

{
  uint uVar1;
  
  uVar1 = (FRC->SNIFFCTRL);
  write_volatile_4(FRC->SNIFFCTRL,uVar1 & 0xfffffffc);
  BUS_RegMaskedClear(&RAC->SR3,0x40000000);
  return;
}



void RADIO_PTI_AuxdataOutput(uint param_1)

{
  FRC *pFVar1;
  bool bVar2;
  
  pFVar1 = (FRC *)(RAC->SR3);
  bVar2 = (int)pFVar1 < 0;
  if (bVar2) {
    pFVar1 = &Peripherals::FRC;
  }
  if (bVar2) {
    pFVar1->AUXDATA = param_1;
  }
  return;
}



void RADIO_WriteSync(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return;
}



void RADIO_SetBitSync(int param_1,uint param_2)

{
  *(int *)(param_1 + 0x6000000) = 1 << (param_2 & 0xff);
  return;
}



void RADIO_ClrBitSync(int param_1,uint param_2)

{
  *(int *)(param_1 + 0x4000000) = 1 << (param_2 & 0xff);
  return;
}



void RADIO_OrSync(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x6000000) = param_2;
  return;
}



void RADIO_XorSync(uint *param_1,uint param_2)

{
  *param_1 = param_2 ^ *param_1;
  return;
}



void RADIO_AndSync(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x4000000) = ~param_2;
  return;
}



void RADIO_WaitForSetSync(uint *param_1,uint param_2)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  do {
  } while ((*param_1 & param_2) != param_2);
  CORE_ExitCritical(irqState);
  return;
}



void RADIO_Delay(undefined4 param_1,undefined4 param_2)

{
  PHY_UTILS_DelayUs(param_2);
  return;
}



void RADIO_SetAndForgetWrite(undefined4 param_1,uint param_2,undefined4 param_3)

{
  undefined4 local_c;
  undefined4 uStack8;
  
  local_c = param_2;
  uStack8 = param_3;
  SYSTEM_ChipRevisionGet((SYSTEM_ChipRevision_TypeDef *)&local_c);
  write_volatile_4(RAC->IFADCCTRL,0x5153e6c0);
  write_volatile_4(RAC->IFPGACTRL,0x87e6);
  write_volatile_4(RAC->LNAMIXCTRL1,0x880);
  write_volatile_4(RAC->VCOCTRL,0xf00277a);
  if ((local_c._1_1_ == '\x01') && ((local_c & 0xff) < 2)) {
    write_volatile_4(SYNTH->VCOGAIN,0x28);
  }
  write_volatile_4(SYNTH->CTRL,0xac3f);
  write_volatile_4(AGC->MANGAIN,0x1800000);
  write_volatile_4(RAC->LNAMIXCTRL,0);
  write_volatile_4(RAC->SYNTHREGCTRL,0x3636d80);
  write_volatile_4(Peripherals::SYNTH_CLR.VCDACCTRL,0x7f);
  BUS_RegMaskedSet(&SYNTH->VCDACCTRL,0x23);
  return;
}



void RADIO_SeqInit(void *src,uint32_t len)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  CORE_irqState_t irqState;
  
  read_volatile(RAC->STATUS._0_1_);
  write_volatile_4(RAC->VECTADDR,0x21000000);
  write_volatile_4(RAC->SEQCTRL,1);
  irqState = CORE_EnterCritical();
  memcpy((void *)0x21000000,src,len << 2);
  CORE_ExitCritical(irqState);
  write_volatile_4(RAC->R6,0x21000fbc);
  uVar1 = (SEQ->REG0E4);
  uVar2 = (SEQ->REG0E8);
  uVar3 = (SEQ->DYNAMIC_CHPWR_TABLE);
  memset(&SEQ->REG064,0,0x9c);
  write_volatile_4(SEQ->REG0E4,uVar1);
  write_volatile_4(SEQ->REG0E8,uVar2);
  write_volatile_4(SEQ->DYNAMIC_CHPWR_TABLE,uVar3);
  return;
}



void RADIO_CLKEnable(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  RADIOCMU_ClockEnable(0x63400,1);
  RADIOCMU_ClockEnable(0x60400,1);
  RADIOCMU_ClockEnable(0x64400,1);
  RADIOCMU_ClockEnable(0x67400,1);
  RADIOCMU_ClockEnable(0x66400,1);
  RADIOCMU_ClockEnable(0x65400,1);
  RADIOCMU_ClockEnable(0x62400,1);
  RADIOCMU_ClockEnable(0x68400,1,param_3,param_4);
  return;
}



void RADIO_Init(void)

{
  RADIO_CLKEnable();
  BUFC_Init();
  RADIO_SetAndForgetWrite();
  BUS_RegMaskedSet(&MODEM->DCCOMP,3);
  write_volatile_4(RAC->SR3,0);
  BUS_RegMaskedSet(&RAC->SR3,1);
  SYNTH_KvnFreqCompensationEnable();
  SYNTH_DCDCRetimeEnable();
  BUS_RegMaskedSet(&RAC->CTRL,0x380);
  return;
}



void RADIO_Config(void *config)

{
  bool init;
  CORE_irqState_t irqState;
  uint uVar1;
  int iVar2;
  void *__dest;
  uint uVar3;
  void *__src;
  
  if (config != (void *)0x0) {
    for (iVar2 = (int)config + 8; uVar1 = *(uint *)(iVar2 + -8), uVar1 != 0xffffffff;
        iVar2 = iVar2 + 8) {
      uVar3 = (uVar1 << 8) >> 0x18;
      __dest = (void *)(uVar1 & 0xffff | (uint)(&regBases)[(uVar1 << 4) >> 0x1c]);
      if (uVar3 < 2) {
        (**(code **)(&EFRDRV_actionFunc + (uVar1 >> 0x1c) * 4))(__dest,*(undefined4 *)(iVar2 + -4));
      }
      else {
        __src = *(void **)(iVar2 + -4);
        irqState = CORE_EnterCritical();
        memcpy(__dest,__src,uVar3 << 2);
        CORE_ExitCritical(irqState);
      }
    }
  }
  init = PA_UpdateConfig();
  TIMING_SeqTimingInit(init);
  return;
}



void RADIO_RegisterIrqCallback(int param_1,undefined4 param_2)

{
  (&EFRDRV_irqClbk)[param_1] = param_2;
  return;
}



void FRC_PRI_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x0000da3c. Too many branches
                    // WARNING: Treating indirect jump as call
  (*EFRDRV_irqClbk)();
  return;
}



void RAC_RSM_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x0000da48. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_20002d98)();
  return;
}



void RAC_SEQ_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x0000da54. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_20002d98)();
  return;
}



void AGC_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x0000da60. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_20002da8)();
  return;
}



void PROTIMER_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x0000da6c. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_20002da0)();
  return;
}



void BUFC_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x0000da78. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_20002d90)();
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FRC_IRQHandler(void)

{
  if (_DAT_e000e200 << 0x18 < 0) {
    BUFC_IRQHandler();
  }
                    // WARNING: Could not recover jumptable at 0x0000da98. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_20002d88)();
  return;
}



void MODEM_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x0000daa8. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_20002d8c)();
  return;
}



uint32_t RADIO_RxTrailDataLength(void)

{
  uint uVar1;
  uint32_t uVar2;
  
  uVar1 = (FRC->TRAILRXDATA);
  if ((uVar1 & 0x20) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 4;
  }
  if ((int)(uVar1 << 0x1b) < 0) {
    uVar2 = uVar2 + 2;
  }
  if ((int)(uVar1 << 0x1c) < 0) {
    uVar2 = uVar2 + 2;
  }
  if ((int)(uVar1 << 0x1d) < 0) {
    uVar2 = uVar2 + 2;
  }
  if ((int)(uVar1 << 0x1e) < 0) {
    uVar2 = uVar2 + 1;
  }
  if ((int)(uVar1 << 0x1f) < 0) {
    uVar2 = uVar2 + 1;
  }
  return uVar2;
}



void RADIO_FrameControlDescrBufferIdSet(int param_1,int param_2)

{
  (&Peripherals::FRC_CLR.FCD0)[param_1] = 0x300;
  (&Peripherals::FRC_SET.FCD0)[param_1] = param_2 << 8;
  return;
}



void RADIO_FrameControlDescrConfigSet
               (int param_1,uint param_2,int param_3,int param_4,byte param_5,byte param_6)

{
  (&Peripherals::FRC_CLR.FCD0)[param_1] = 31999;
  (&Peripherals::FRC_SET.FCD0)[param_1] =
       param_2 | (uint)param_6 << 10 | (uint)param_5 << 0xb | param_4 << 0xc | param_3 << 0xe;
  return;
}



void RADIO_FrameDescsConfig
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  RADIO_FrameControlDescrConfigSet(0,0xff,param_1,param_2,param_3,param_4,param_3);
  RADIO_FrameControlDescrConfigSet(2,0xff,param_1,param_2,param_3,param_4);
  return;
}



void RADIO_FRCErrorHandle(void)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  bufcRxStreaming._0_2_ = 0;
  write_volatile_4(BUFC->BUF1_CMD,1);
  write_volatile_4(BUFC->BUF2_CMD,1);
  write_volatile_4(FRC->IFC,0x10);
  CORE_ExitCritical(irqState);
  return;
}



uint32_t RADIO_ComputeTxBaudrate(void)

{
  uint uVar1;
  uint32_t uVar2;
  
  uVar2 = CMU_ClockFreqGet(cmuClock_HF);
  uVar1 = (MODEM->TXBR);
  return (((uVar1 << 8) >> 0x18) * (uVar2 >> 3)) / (uVar1 & 0xffff);
}



uint RADIO_ComputeRxBaudrate(void)

{
  uint uVar1;
  uint uVar2;
  uint32_t uVar3;
  int iVar4;
  uint uVar5;
  
  uVar2 = (MODEM->CF);
  uVar1 = (MODEM->RXBR);
  uVar5 = (uVar1 << 0x16) >> 0x1b;
  iVar4 = (((uVar2 << 0xf) >> 0x12) * (uint)(byte)(&modemCfDec0Factors)[uVar2 & 7] +
          (uint)(byte)(&modemCfDec0Factors)[uVar2 & 7]) * 2;
  uVar3 = CMU_ClockFreqGet(cmuClock_HF);
  return (uVar5 * uVar3) /
         ((((uVar2 << 9) >> 0x1a) * iVar4 + iVar4) *
         (uVar5 * ((uVar1 << 0x13) >> 0x1d) + (uVar1 & 0x1f)));
}



uint32_t RADIO_ComputeTxSymbolRate(void)

{
  uint uVar1;
  uint32_t uVar2;
  
  uVar2 = RADIO_ComputeTxBaudrate();
  uVar1 = (MODEM->CTRL0);
  if ((uVar1 & 0x30) == 0x20) {
    uVar2 = uVar2 / (((uVar1 << 0x10) >> 0x1b) + 1);
  }
  return uVar2;
}



uint32_t RADIO_ComputeTxBitRate(void)

{
  uint uVar1;
  uint32_t uVar2;
  uint uVar3;
  
  uVar1 = (MODEM->CTRL0);
  if ((uVar1 & 0x30) == 0x20) {
    uVar3 = ((uVar1 << 0x10) >> 0x1b) / ((uVar1 << 0xd) >> 0x1d);
    if ((uVar1 & 0x180000) != 0) {
      uVar3 = uVar3 << 1;
    }
    uVar3 = uVar3 >> 1;
    if (2 < uVar3) {
      uVar3 = 4;
    }
  }
  else {
    uVar1 = (MODEM->CTRL0);
    if (((uVar1 & 0x1c0) == 0x40) || ((uVar1 & 0x1c0) == 0x100)) {
      uVar3 = 2;
    }
    else {
      uVar3 = 1;
    }
  }
  uVar2 = RADIO_ComputeTxSymbolRate();
  return uVar3 * uVar2;
}



int16_t RADIO_GetRSSI(void)

{
  short sVar1;
  uint uVar2;
  CORE_irqState_t irqState;
  uint uVar3;
  uint uVar4;
  
  do {
    irqState = CORE_EnterCritical();
    uVar3 = (RAC->STATUS);
    uVar3 = uVar3 & 0xf000000;
    uVar2 = (AGC->RSSI);
    uVar4 = (RAC->STATUS);
    uVar4 = uVar4 & 0xf000000;
    sVar1 = (short)uVar2 >> 6;
    CORE_ExitCritical(irqState);
    if (sVar1 != -0x200) {
      if ((uVar4 == 0x2000000 || uVar4 == 0x3000000) && (uVar3 == 0x2000000 || uVar3 == 0x3000000))
      {
        return sVar1;
      }
      return -0x200;
    }
  } while ((uVar4 == 0x2000000 || uVar4 == 0x3000000) && (uVar3 == 0x2000000 || uVar3 == 0x3000000))
  ;
  return -0x200;
}



undefined4 RADIO_SetAgcCcaParams(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = RADIO_ComputeRxBaudrate();
  for (uVar2 = 0; (uint)(1 << (uVar2 & 0xff)) < (uint)(param_1 * iVar1) / 1000000; uVar2 = uVar2 + 1
      ) {
    if (uVar2 == 0x10) {
      return 1;
    }
  }
  BUS_RegMaskedClear(&AGC->CTRL1,0xf00);
  BUS_RegMaskedSet(&AGC->CTRL1,uVar2 << 8);
  uVar2 = (AGC->CTRL1);
  if ((uVar2 & 0xff) == 0x80) {
    return 2;
  }
  BUS_RegMaskedClear(&AGC->CTRL1,0xff);
  BUS_RegMaskedSet(&AGC->CTRL1,param_2 & 0xff);
  return 0;
}



RAIL_Status_t RADIO_CalcRssiPeriod(uint32_t us)

{
  undefined uVar1;
  longlong lVar2;
  uint32_t uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  
  BUS_RegMaskedSet(&AGC->CTRL1,0x8000);
  uVar4 = (MODEM->CF);
  uVar5 = (MODEM->CF);
  uVar6 = (MODEM->CF);
  uVar1 = (&modemCfDec0Factors)[uVar4 & 7];
  uVar3 = CMU_ClockFreqGet(cmuClock_HF);
  uVar10 = __aeabi_uldivmod((int)((ulonglong)uVar3 * 1000),(int)((ulonglong)uVar3 * 1000 >> 0x20),
                            uVar1,0);
  uVar10 = __aeabi_uldivmod((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),
                            ((uVar5 << 0xf) >> 0x12) + 1,0);
  uVar11 = __aeabi_uldivmod((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),((uVar6 << 9) >> 0x1a) + 1,
                            0);
  iVar8 = (int)(uVar11 >> 0x20);
  uVar4 = __aeabi_uldivmod(0xdb000000,0x7558b,(int)uVar11,iVar8);
  if (uVar4 < us) {
    return RAIL_STATUS_INVALID_PARAMETER;
  }
  lVar2 = (uVar11 & 0xffffffff) * (ulonglong)us;
  uVar7 = (undefined4)lVar2;
  iVar8 = us * iVar8 + (int)((ulonglong)lVar2 >> 0x20);
  uVar5 = __aeabi_uldivmod(uVar7,iVar8,1000000000,0);
  iVar9 = 1;
  uVar4 = 0;
  do {
    uVar6 = uVar4 + 1;
    if (uVar5 <= (uint)(1 << (uVar6 & 0xff))) {
LAB_0000ddbc:
      BUS_RegMaskedClear(&AGC->CTRL1,0xf00);
      BUS_RegMaskedSet(&AGC->CTRL1,uVar4 << 8);
      uVar10 = __aeabi_uldivmod(uVar7,iVar8,10000000,0);
      uVar10 = __aeabi_uldivmod((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),iVar9,0);
      iVar8 = __aeabi_uldivmod((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),100,0);
      uVar4 = ((int)uVar10 + iVar8 * -100 & 0xffU) / 3;
      if (uVar4 < 0x20) {
        if (uVar4 == 0) {
          uVar4 = (AGC->CTRL1);
          write_volatile_4(AGC->CTRL1,uVar4 & 0xffe0ffff | 0x10000);
          uVar4 = (AGC->CTRL1);
          write_volatile_4(AGC->CTRL1,uVar4 & 0xfc1fffff | 0x200000);
          return RAIL_STATUS_NO_ERROR;
        }
      }
      else {
        uVar4 = 0x1f;
      }
      uVar5 = (AGC->CTRL1);
      write_volatile_4(AGC->CTRL1,uVar5 & 0x3ffffff | iVar8 << 0x1a);
      uVar5 = (AGC->CTRL1);
      write_volatile_4(AGC->CTRL1,uVar5 & 0xffe0ffff | uVar4 << 0x10);
      uVar4 = (AGC->CTRL1);
      write_volatile_4(AGC->CTRL1,uVar4 | 0x3e00000);
      return RAIL_STATUS_NO_ERROR;
    }
    if (uVar6 == 0x10) {
      uVar4 = 0xf;
      goto LAB_0000ddbc;
    }
    iVar9 = iVar9 << 1;
    uVar4 = uVar6;
  } while( true );
}



void RADIO_SetCRCInitVal(uint32_t value)

{
  write_volatile_4(Peripherals::CRC.INIT,value);
  write_volatile_4(Peripherals::CRC.CMD,1);
  return;
}



undefined4 SYNTH_RfFreqGet(void)

{
  return currRfFrequency;
}



undefined4 SYNTH_ChSpacingGet(void)

{
  return currChSpacing;
}



undefined4 SYNTH_IfFreqGet(void)

{
  return currIfFrequency;
}



uint SYNTH_LoDivGet(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (SYNTH->DIVCTRL);
  uVar1 = uVar3 & 7;
  uVar2 = (uVar3 << 0x17) >> 0x1a & 7;
  if (uVar2 != 0) {
    uVar1 = uVar2 * uVar1;
  }
  uVar3 = (uVar3 << 0x17) >> 0x1d;
  if (uVar3 != 0) {
    uVar1 = uVar3 * uVar1;
  }
  return uVar1;
}



uint SYNTH_Is2p4GHz(void)

{
  uint uVar1;
  
  uVar1 = (RAC->IFPGACTRL);
  return ((uVar1 ^ 0x10) << 0x1b) >> 0x1f;
}



bool SYNTH_VcoRangeIsValid(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  longlong lVar5;
  
  uVar1 = SYNTH_LoDivGet();
  lVar5 = __aeabi_ldivmod(2300000000,0,uVar1,0);
  uVar2 = (uint)((ulonglong)lVar5 >> 0x20);
  bVar4 = (uint)lVar5 <= param_1;
  if ((int)(-(uint)!bVar4 - uVar2) < 0 != (lVar5 < 0 && (int)(~uVar2 + (uint)bVar4) < 0)) {
    return false;
  }
  lVar5 = __aeabi_ldivmod(2900000000,0,uVar1,0);
  iVar3 = (int)((ulonglong)lVar5 >> 0x20);
  bVar4 = param_1 <= (uint)lVar5;
  return (int)(iVar3 - (uint)!bVar4) < 0 ==
         (lVar5 < 0 && (int)(iVar3 + -1 + (uint)bVar4) < 0 != lVar5 < 0);
}



void SYNTH_RetimeLimitsConfig(uint param_1)

{
  uint32_t uVar1;
  uint uVar2;
  
  uVar1 = SystemHFXOClockGet();
  uVar2 = param_1 / uVar1;
  if (((param_1 - uVar1 * uVar2) * 100) / uVar1 == 0) {
    uVar2 = uVar2 - 1;
  }
  BUS_RegMaskedClear(&RAC->HFXORETIMECTRL,0x770);
  BUS_RegMaskedSet(&RAC->HFXORETIMECTRL,
                   ((uVar2 >> 1) - 1) * 0x10 | ((uVar2 + 1 >> 1) - 1) * 0x100);
  return;
}



void SYNTH_RetimeClkConfig(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_1c;
  undefined4 uStack24;
  undefined local_14;
  
  local_1c = 0x2010000;
  uStack24 = 0x3030302;
  local_14 = 3;
  uVar3 = (SYNTH->CHCTRL);
  uVar1 = (SYNTH->IFFREQ);
  iVar2 = currIfFrequency;
  if ((uVar1 & 0x100000) == 0) {
    iVar2 = -currIfFrequency;
  }
  uVar1 = currChSpacing * uVar3 + currRfFrequency + iVar2;
  uVar3 = (uint)*(byte *)((int)&local_1c + uVar1 / 625000000 + 1);
  uVar1 = uVar1 >> uVar3;
  BUS_RegMaskedClear(&RAC->MMDCTRL,0x3dff);
  BUS_RegMaskedSet(&RAC->MMDCTRL,
                   (uVar1 + (dcdcRetimeClkTarget >> 1)) / dcdcRetimeClkTarget - 1 | uVar3 << 0xc |
                   (uint)*(byte *)((int)&local_1c + uVar1 / 325000000 + 1) << 10);
  SYNTH_RetimeLimitsConfig();
  return;
}



void SYNTH_Config(int param_1,uint param_2)

{
  longlong lVar1;
  RAC_SET *pRVar2;
  uint uVar3;
  uint32_t uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = SYNTH_LoDivGet();
  SYNTH_VcoRangeIsValid(param_1);
  if (uVar3 == 1) {
    pRVar2 = (RAC_SET *)&Peripherals::RAC_CLR;
  }
  else {
    pRVar2 = &Peripherals::RAC_SET;
  }
  ((RAC_CLR *)pRVar2)->IFPGACTRL = 0x10;
  uVar4 = SystemHFXOClockGet();
  uVar6 = uVar3 * param_1;
  currRfFrequency = param_1;
  uVar5 = __aeabi_uldivmod(uVar6 * 0x80000,uVar6 >> 0xd,uVar4,0);
  write_volatile_4(SYNTH->FREQ,uVar5);
  uVar5 = (SYNTH->IFFREQ);
  lVar1 = (ulonglong)uVar4 * (ulonglong)(uVar5 & 0xfffff);
  currIfFrequency = __aeabi_uldivmod((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),uVar3 << 0x13,0);
  lVar1 = (ulonglong)(param_2 << 0x13) * (ulonglong)uVar3;
  currChSpacing = param_2;
  uVar3 = __aeabi_uldivmod((int)lVar1,uVar3 * (param_2 >> 0xd) + (int)((ulonglong)lVar1 >> 0x20),
                           uVar4,0);
  write_volatile_4(SYNTH->CHSP,uVar3);
  if (vcoGainPte == 0) {
    uVar3 = (SYNTH->VCOGAIN);
    vcoGainPte = (byte)uVar3 & 0x3f;
  }
  uVar3 = (RAC->SR3);
  if ((int)(uVar3 << 0x1b) < 0) {
    uVar6 = uVar6 / 24000000;
    write_volatile_4(SYNTH->VCOGAIN,
                     ((uint)vcoGainPte * 10000000) /
                     (uVar6 * uVar6 * 0x553 + uVar6 * -0xc60c + 0x192d50));
  }
  SYNTH_RetimeClkConfig();
  return;
}



void SYNTH_ChannelSet(uint param_1,int param_2)

{
  uint uVar1;
  
  do {
    do {
      uVar1 = (RAC->STATUS);
      uVar1 = (uVar1 << 4) >> 0x1c;
    } while (uVar1 == 4);
  } while (uVar1 == 10);
  write_volatile_4(SYNTH->CHCTRL,param_1);
  if (param_2 != 0) {
    write_volatile_4(RAC->CMD,0x80);
  }
  SYNTH_RetimeClkConfig();
  return;
}



void SYNTH_DCDCRetimeEnable(void)

{
  BUS_RegMaskedSet(&RAC->SR3,4);
  return;
}



void SYNTH_DCDCRetimeClkSet(int param_1)

{
  dcdcRetimeClkTarget = param_1;
  EMU_DCDCLnRcoBandSet((char)((param_1 + 500000U) / 1000000) + ~emuDcdcLnRcoBand_5MHz);
  return;
}



void SYNTH_KvnFreqCompensationEnable(void)

{
  BUS_RegMaskedSet(&RAC->SR3,0x10);
  return;
}



void RADIOCMU_ClockEnable(CMU_Clock_TypeDef param_1,int param_2)

{
  uint uVar1;
  CMU *pCVar2;
  uint *puVar3;
  
  uVar1 = (param_1 << 0x14) >> 0x1c;
  if (uVar1 == 1) {
    pCVar2 = &Peripherals::CMU;
  }
  else {
    if (uVar1 != 4) {
      CMU_ClockEnable(param_1,SUB41(param_2,0));
      return;
    }
    pCVar2 = (CMU *)&CMU->HFRADIOCLKEN0;
  }
  if (param_2 == 0) {
    puVar3 = &pCVar2[0x2192e].CALCTRL;
  }
  else {
    puVar3 = (uint *)&pCVar2[0x325c5].field_0x78;
  }
  *puVar3 = 1 << ((param_1 << 0xf) >> 0x1b);
  return;
}



uint RADIOCMU_ClockFreqGet(CMU_Clock_TypeDef param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 & 0x3e0000;
  if (uVar2 == 0x40000) {
    uVar1 = SystemHFClockGet();
    uVar2 = (CMU->HFPERPRESC);
  }
  else {
    if (uVar2 < 0x40001) {
      if (uVar2 == 0) {
        uVar1 = SystemHFClockGet();
        uVar2 = (CMU->HFPRESC);
LAB_0000e21c:
        uVar2 = (uVar2 << 0x13) >> 0x1b;
        goto LAB_0000e220;
      }
      if (uVar2 != 0x20000) {
LAB_0000e228:
        uVar2 = CMU_ClockFreqGet(param_1);
        return uVar2;
      }
      uVar1 = SystemHFClockGet();
      uVar2 = (CMU->HFCOREPRESC);
    }
    else {
      if (uVar2 == 0x80000) {
        uVar2 = SystemHFClockGet();
        return uVar2;
      }
      if (uVar2 == 0xa0000) {
        uVar1 = SystemHFClockGet();
        uVar2 = (CMU->HFEXPPRESC);
        goto LAB_0000e21c;
      }
      if (uVar2 != 0x60000) goto LAB_0000e228;
      uVar1 = SystemHFClockGet();
      uVar2 = (CMU->HFRADIOPRESC);
    }
  }
  uVar2 = (uVar2 << 0xf) >> 0x17;
LAB_0000e220:
  return uVar1 / (uVar2 + 1);
}



uint32_t RADIOCMU_ClockPrescGet(CMU_Clock_TypeDef param_1)

{
  uint uVar1;
  uint32_t uVar2;
  
  if ((param_1 << 0x18) >> 0x1c != 6) {
    uVar2 = CMU_ClockPrescGet(param_1);
    return uVar2;
  }
  uVar1 = (CMU->HFRADIOPRESC);
  return (uVar1 << 0xf) >> 0x17;
}



bool TIMING_SeqTimingInit(bool init)

{
  return init;
}



int TIMING_NsToStimerTickCalc(uint param_1)

{
  uint uVar1;
  
  if ((0 < (int)param_1) &&
     (uVar1 = (uint)((ulonglong)param_1 * (ulonglong)nsToStimerRatio),
     uVar1 = uVar1 + 0x1000000 >> 0x19 |
             (nsToStimerRatio * ((int)param_1 >> 0x1f) +
              (int)((ulonglong)param_1 * (ulonglong)nsToStimerRatio >> 0x20) +
             (uint)(0xfeffffff < uVar1)) * 0x80, 0x80 < uVar1)) {
    return uVar1 - 0x80;
  }
  return 0;
}



void TIMING_InitStimer(void)

{
  uint uVar1;
  int iVar2;
  undefined4 in_r3;
  
  write_volatile_4(RAC->PRESC,7);
  uVar1 = RADIOCMU_ClockFreqGet(0x75160);
  nsToStimerRatio = __aeabi_uldivmod(4000000,uVar1 / 1000,8000000,0,in_r3);
  iVar2 = TIMING_NsToStimerTickCalc(60000);
  write_volatile_4(SEQ->REG0B8,-iVar2);
  return;
}



void TIMING_TxWarmTimeRecalculate(void)

{
  uint32_t uVar1;
  uint uVar2;
  
  uVar2 = (uint)DAT_20002de6;
  uVar1 = PA_RampTimeGet();
  uVar2 = TIMING_NsToStimerTickCalc((uVar2 - uVar1) * 1000);
  write_volatile_4(SEQ->REG0A8,uVar2);
  return;
}



uint16_t TIMING_TxWarmTimeSet(uint16_t tme)

{
  if (tme < 100) {
    DAT_20002de6 = 100;
  }
  else {
    DAT_20002de6 = tme;
    if (12999 < tme) {
      DAT_20002de6 = 13000;
    }
  }
  TIMING_TxWarmTimeRecalculate();
  return DAT_20002de6;
}



undefined2 TIMING_TxWarmTimeGet(void)

{
  return DAT_20002de6;
}



void TIMING_RxToTxTimeRecalculate(void)

{
  uint32_t uVar1;
  uint uVar2;
  
  uVar2 = (uint)DAT_20002de2;
  uVar1 = PA_RampTimeGet();
  uVar2 = TIMING_NsToStimerTickCalc((uVar2 - uVar1) * 1000);
  write_volatile_4(SEQ->REG0A0,uVar2);
  return;
}



undefined2 TIMING_RxToTxTimeSet(uint param_1)

{
  if (param_1 < 100) {
    DAT_20002de2 = 100;
  }
  else {
    if (12999 < param_1) {
      param_1 = 13000;
    }
    DAT_20002de2 = (undefined2)param_1;
  }
  TIMING_RxToTxTimeRecalculate();
  return DAT_20002de2;
}



void TIMING_RxFrameToTxTimeRecalculate(void)

{
  uint32_t uVar1;
  uint uVar2;
  
  uVar2 = (uint)DAT_20002de4;
  uVar1 = PA_RampTimeGet();
  uVar2 = TIMING_NsToStimerTickCalc((uVar2 - uVar1) * 1000 - timings);
  write_volatile_4(SEQ->REG0A4,uVar2);
  return;
}



uint16_t TIMING_RxFrameToTxTimeSet(uint16_t time)

{
  if (time < 100) {
    DAT_20002de4 = 100;
  }
  else {
    DAT_20002de4 = time;
    if (12999 < time) {
      DAT_20002de4 = 13000;
    }
  }
  TIMING_RxFrameToTxTimeRecalculate();
  return (uint16_t)DAT_20002de4;
}



void TIMING_TxToTxTimeRecalculate(void)

{
  uint32_t uVar1;
  uint uVar2;
  
  uVar2 = (uint)DAT_20002dea;
  uVar1 = PA_RampTimeGet();
  uVar2 = TIMING_NsToStimerTickCalc((uVar2 - uVar1) * 1000 - DAT_20002ddc);
  write_volatile_4(SEQ->REG0B4,uVar2);
  return;
}



undefined2 TIMING_TxToTxTimeSet(uint param_1)

{
  uint32_t uVar1;
  uint uVar2;
  
  uVar1 = PA_RampTimeGet();
  uVar2 = param_1;
  if (12999 < param_1) {
    uVar2 = 13000;
  }
  if (uVar2 < uVar1) {
    uVar1 = PA_RampTimeGet();
    param_1 = uVar1 & 0xffff;
  }
  else {
    if (12999 < param_1) {
      param_1 = 13000;
    }
  }
  DAT_20002dea = (undefined2)param_1;
  TIMING_TxToTxTimeRecalculate();
  return DAT_20002dea;
}



void TIMING_TxToRxTimeRecalculate(void)

{
  uint uVar1;
  
  uVar1 = TIMING_NsToStimerTickCalc((uint)DAT_20002de8 * 1000 + (-4000 - DAT_20002ddc));
  write_volatile_4(SEQ->REG0AC,uVar1);
  return;
}



uint16_t TIMING_TxToRxTimeSet(uint16_t time)

{
  uint16_t uVar1;
  
  if (time < 100) {
    DAT_20002de8 = 100;
  }
  else {
    DAT_20002de8 = time;
    if (12999 < time) {
      DAT_20002de8 = 13000;
    }
  }
  uVar1 = DAT_20002de8;
  TIMING_TxToRxTimeRecalculate();
  return uVar1;
}



void TIMING_RxWarmTimeRecalculate(void)

{
  uint uVar1;
  
  uVar1 = TIMING_NsToStimerTickCalc((uint)DAT_20002de0 * 1000 + -4000);
  write_volatile_4(SEQ->REG098,uVar1);
  return;
}



uint16_t TIMING_RxWarmTimeSet(uint16_t time)

{
  uint16_t uVar1;
  
  if (time < 100) {
    DAT_20002de0 = 100;
  }
  else {
    DAT_20002de0 = time;
    if (12999 < time) {
      DAT_20002de0 = 13000;
    }
  }
  uVar1 = DAT_20002de0;
  TIMING_RxWarmTimeRecalculate();
  return uVar1;
}



undefined2 TIMING_RxWarmTimeGet(void)

{
  return DAT_20002de0;
}



uint TIMING_RxSearchTimeSet(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 13000;
  if (param_1 < 0x32c9) {
    uVar2 = param_1;
  }
  uVar1 = TIMING_NsToStimerTickCalc(uVar2 * 1000);
  write_volatile_4(SEQ->REG09C,uVar1);
  return uVar2;
}



uint TIMING_TxToRxSearchTimeSet(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 13000;
  if (param_1 < 0x32c9) {
    uVar2 = param_1;
  }
  uVar1 = TIMING_NsToStimerTickCalc(uVar2 * 1000);
  write_volatile_4(SEQ->REG0B0,uVar1);
  return uVar2;
}



void TIMING_RecalculateAll(void)

{
  TIMING_RxWarmTimeRecalculate();
  TIMING_TxWarmTimeRecalculate();
  TIMING_RxFrameToTxTimeRecalculate();
  TIMING_RxToTxTimeRecalculate();
  TIMING_TxToTxTimeRecalculate();
  TIMING_TxToRxTimeRecalculate();
  return;
}



uint32_t TIMING_SetChainDelays(uint32_t param_1,uint32_t param_2)

{
  timings = param_1;
  DAT_20002ddc = param_2;
  TIMING_RecalculateAll();
  return 0;
}



uint64_t TIMING_GetRxTimestampUs(uint32_t cnt)

{
  uint64_t uVar1;
  
  uVar1 = PROTIMER_PrecntOverflowToUs(cnt);
  return uVar1 & 0xffffffff00000000 | (ulonglong)((int)uVar1 - (timings + 500U) / 1000);
}



ulonglong TIMING_GetTxTimestampUs(uint32_t param_1)

{
  uint64_t uVar1;
  
  uVar1 = PROTIMER_PrecntOverflowToUs(param_1);
  return uVar1 & 0xffffffff00000000 | (ulonglong)((int)uVar1 - (DAT_20002ddc + 500U) / 1000);
}



uint8_t RAIL_RadioConfig(void *radioConfig)

{
  RADIO_Config(radioConfig);
  forceIrCal = 1;
  return '\0';
}



uint8_t RAIL_ChannelConfig(RAIL_ChannelConfig_t *config)

{
  int iVar1;
  undefined4 uVar2;
  
  RAILInt_TrackChannelConfig(config);
  SYNTH_Config(config->configs->baseFrequency,config->configs->channelSpacing);
  iVar1 = SYNTH_Is2p4GHz();
  if (iVar1 == 0) {
    uVar2 = 3500000;
  }
  else {
    uVar2 = 7000000;
  }
  SYNTH_DCDCRetimeClkSet(uVar2);
  if (forceIrCal != '\0') {
    forceIrCal = '\0';
    RAILINT_CalibrationPend(0x10000);
  }
  return *(uint8_t *)&config->configs->channelNumberStart;
}



void RAIL_DirectModeConfig(bool enable)

{
  uint in_r3;
  uint local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint local_c;
  
  local_18 = (uint)CONCAT11(enable,enable);
  local_14 = 0xb020e00;
  local_10 = 0xe09020e;
  local_c = in_r3 & 0xffff0000 | 0xa02;
  GENERIC_PHY_DirectModeConfig(&local_18);
  return;
}



RAIL_Status_t RAIL_DebugFrequencyOverride(uint32_t freq)

{
  SYNTH_Config(freq,0);
  return RAIL_STATUS_NO_ERROR;
}



void RAIL_PacketLengthConfigFrameType(RAIL_FrameType_t *frameType)

{
  char cVar1;
  CORE_irqState_t CVar2;
  uint uVar3;
  uint uVar4;
  
  if (frameType == (RAIL_FrameType_t *)0x0) {
    CVar2 = CORE_EnterCritical();
    uVar3 = (SEQ->REG000);
    write_volatile_4(SEQ->REG000,uVar3 & 0xfffffff8);
    CORE_ExitCritical(CVar2);
    write_volatile_4(SEQ->REG05C,0);
    write_volatile_4(SEQ->REG060,0);
    return;
  }
  GENERIC_PHY_ResetPacketConfig();
  write_volatile_1(SEQ->REG05C._0_1_,frameType->offset);
  write_volatile_1(SEQ->REG05C._1_1_,frameType->mask);
  uVar4 = 0;
  write_volatile_1(SEQ->REG05C._2_1_,0);
  write_volatile_4(SEQ->REG060,(uint)frameType->frameLen);
  uVar3 = 0;
  do {
    if (frameType->isValid[uVar4] != '\0') {
      uVar3 = uVar3 | 1 << (uVar4 & 0xff) & 0xffU;
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 != 8);
  write_volatile_1(SEQ->REG05C._3_1_,(char)uVar3);
  uVar3 = (uint)frameType->mask;
  if (uVar3 != 0) {
    while (-1 < (int)(uVar3 << 0x1f)) {
      cVar1 = read_volatile_1(SEQ->REG05C._2_1_);
      uVar3 = uVar3 >> 1;
      write_volatile_1(SEQ->REG05C._2_1_,cVar1 + '\x01');
    }
  }
  write_volatile_4(FRC->WCNTCMP0,frameType->offset + 1);
  CVar2 = CORE_EnterCritical();
  uVar3 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar3 | 7);
  CORE_ExitCritical(CVar2);
  return;
}



int16_t RAIL_RxGetRSSI(void)

{
  short sVar1;
  uint uVar2;
  CORE_irqState_t irqState;
  uint uVar3;
  uint uVar4;
  
  do {
    irqState = CORE_EnterCritical();
    uVar3 = (RAC->STATUS);
    uVar3 = uVar3 & 0xf000000;
    uVar2 = (AGC->RSSI);
    uVar4 = (RAC->STATUS);
    uVar4 = uVar4 & 0xf000000;
    sVar1 = (short)uVar2 >> 6;
    CORE_ExitCritical(irqState);
    if (sVar1 != -0x200) {
      if ((uVar4 == 0x2000000 || uVar4 == 0x3000000) && (uVar3 == 0x2000000 || uVar3 == 0x3000000))
      {
        return sVar1;
      }
      return -0x200;
    }
  } while ((uVar4 == 0x2000000 || uVar4 == 0x3000000) && (uVar3 == 0x2000000 || uVar3 == 0x3000000))
  ;
  return -0x200;
}



int16_t RAIL_PollAverageRSSI(uint32_t averageTimeUs)

{
  int16_t iVar1;
  uint32_t begin;
  uint32_t uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  uint64_t uVar8;
  
  if (averageTimeUs == 0) {
    iVar1 = RADIO_GetRSSI();
    return iVar1;
  }
  begin = PROTIMER_GetTime();
  uVar8 = PROTIMER_UsToPrecntOverflow(averageTimeUs);
  iVar4 = 0;
  uVar5 = 0;
  iVar6 = 0;
  while( true ) {
    uVar2 = PROTIMER_GetTime();
    uVar2 = PROTIMER_ElapsedTime(begin,uVar2);
    if ((uint)uVar8 <= uVar2) break;
    iVar1 = RADIO_GetRSSI();
    if (iVar1 != -0x200) {
      uVar3 = SEXT24(iVar1);
      bVar7 = CARRY4(uVar5,uVar3);
      uVar5 = uVar5 + uVar3;
      iVar6 = iVar6 + ((int)uVar3 >> 0x1f) + (uint)bVar7;
      iVar4 = iVar4 + 1;
    }
  }
  if (iVar4 == 0) {
    iVar1 = -0x200;
  }
  else {
    iVar1 = __aeabi_ldivmod(uVar5,iVar6,iVar4,iVar4 >> 0x1f);
  }
  return iVar1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

RAIL_Status_t RAIL_StartAverageRSSI(uint8_t channel,uint32_t averagingTimeUs)

{
  RAIL_Status_t RVar1;
  uint8_t uVar2;
  int iVar3;
  
  isRssiReady = 0;
  saveRssiPeriod = (AGC->CTRL1);
  RVar1 = RADIO_CalcRssiPeriod(averagingTimeUs);
  if (RVar1 == RAIL_STATUS_NO_ERROR) {
    iVar3 = _DAT_430c0354;
    if (_DAT_430c0354 != 0) {
      iVar3 = 1;
    }
    saveFrameDetDisable = (undefined)iVar3;
    BUS_RegMaskedSet(&MODEM->CTRL0,0x200000);
    uVar2 = RAIL_RxStart(channel);
    if (uVar2 == '\0') {
      _enabledCallbacks = _enabledCallbacks | 0x4000000;
      GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
    }
    else {
      RVar1 = RAIL_STATUS_INVALID_STATE;
    }
  }
  else {
    RVar1 = RAIL_STATUS_INVALID_PARAMETER;
  }
  return RVar1;
}



int16_t RAIL_GetAverageRSSI(void)

{
  return currentRssiAverage;
}



void RAIL_SetTune(uint32_t tune)

{
  CMU_ClockSelectSet(cmuClock_HF,cmuSelect_HFRCO);
  CMU_OscillatorEnable(cmuOsc_HFXO,false,false);
  BUS_RegMaskedClear(&CMU->HFXOSTEADYSTATECTRL,0xff800);
  BUS_RegMaskedSet(&CMU->HFXOSTEADYSTATECTRL,(tune & 0x1ff) << 0xb);
  CMU_OscillatorEnable(cmuOsc_HFXO,true,true);
  CMU_ClockSelectSet(cmuClock_HF,cmuSelect_HFXO);
  return;
}



uint32_t RAIL_GetTune(void)

{
  uint uVar1;
  
  uVar1 = (CMU->HFXOSTEADYSTATECTRL);
  return (uVar1 << 0xc) >> 0x17;
}



uint32_t RAIL_GetTime(void)

{
  uint32_t cnt;
  uint64_t uVar1;
  
  cnt = PROTIMER_GetTime();
  uVar1 = PROTIMER_PrecntOverflowToUs(cnt);
  return (uint32_t)uVar1;
}



RAIL_Status_t RAIL_SetTime(uint32_t time)

{
  bool bVar1;
  RAIL_Status_t RVar2;
  
  bVar1 = PROTIMER_SetTime(time);
  if (bVar1 == false) {
    RVar2 = RAIL_STATUS_INVALID_STATE;
  }
  else {
    RVar2 = RAIL_STATUS_NO_ERROR;
  }
  return RVar2;
}



uint32_t RAILInt_CompensateForDelay(uint32_t param_1,uint32_t param_2)

{
  timings = param_1;
  DAT_20002ddc = param_2;
  TIMING_RecalculateAll();
  return 0;
}



RAIL_Status_t RAIL_SetStateTiming(RAIL_StateTiming_t *timings)

{
  uint16_t uVar1;
  
  uVar1 = TIMING_RxWarmTimeSet(timings->idleToRx);
  timings->idleToRx = uVar1;
  uVar1 = TIMING_TxToRxTimeSet(timings->txToRx);
  timings->txToRx = uVar1;
  uVar1 = TIMING_TxWarmTimeSet(timings->idleToTx);
  timings->idleToTx = uVar1;
  uVar1 = TIMING_RxFrameToTxTimeSet(timings->rxToTx);
  timings->rxToTx = uVar1;
  return RAIL_STATUS_NO_ERROR;
}



// WARNING: Could not reconcile some variable overlaps

bool RAIL_AddressFilterConfig(RAIL_AddrConfig_t *addrConfig)

{
  byte bVar1;
  undefined uVar2;
  uint8_t *in_r3;
  int iVar3;
  uint8_t local_1c [4];
  uint8_t *local_18;
  undefined4 local_14;
  
  bVar1 = addrConfig->numFields;
  if (bVar1 < 3) {
    local_14 = in_r3;
    memset((RAIL_AddrConfig_t *)local_1c,0,0xc);
    for (iVar3 = 0; iVar3 < (int)(uint)bVar1; iVar3 = iVar3 + 1) {
      (&((RAIL_AddrConfig_t *)local_1c)->numFields)[iVar3] = addrConfig->offsets[iVar3];
      local_1c[iVar3 + 2] = addrConfig->sizes[iVar3];
    }
    local_18 = (uint8_t *)addrConfig->matchTable;
    local_14 = (uint8_t *)CONCAT31(local_14._1_3_,0xff);
    uVar2 = GENERIC_PHY_ConfigureAddressFiltering((RAIL_AddrConfig_t *)local_1c);
  }
  else {
    uVar2 = 0;
  }
  return (bool)uVar2;
}



bool RAIL_AddressFilterByFrameType(uint8_t validFrames)

{
  write_volatile_1(SEQ->REG058._2_1_,validFrames);
  return true;
}



bool RAIL_AddressFilterEnable(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 | 0x10);
  CORE_ExitCritical(irqState);
  return SUB41((uVar1 << 0x1b) >> 0x1f,0);
}



bool RAIL_AddressFilterDisable(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 & 0xffffffef);
  CORE_ExitCritical(irqState);
  return SUB41((uVar1 << 0x1b) >> 0x1f,0);
}



bool RAIL_AddressFilterIsEnabled(void)

{
  uint uVar1;
  
  uVar1 = (SEQ->REG000);
  return SUB41((uVar1 << 0x1b) >> 0x1f,0);
}



void RAIL_AddressFilterReset(void)

{
  memset(&SEQ->REG010,0,0x4c);
  addressFilterMatchTable = 0;
  return;
}



bool RAIL_AddressFilterSetAddress(uint8_t field,uint8_t index,uint8_t *value,bool enable)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (uint)field;
  iVar3 = GENERIC_PHY_SetAddressData
                    (uVar2,uVar2,index,0,*(undefined *)((int)&SEQ->REG054 + uVar2 + 2),
                     value);
  if ((enable != false) && (iVar3 != 0)) {
    bVar1 = GENERIC_PHY_EnableAddress(field,index);
    return bVar1;
  }
  return SUB41(iVar3,0);
}



bool RAIL_AddressFilterEnableAddress(uint8_t field,uint8_t index)

{
  uint uVar1;
  
  uVar1 = (uint)field;
  if ((uVar1 < 2) && (index < 4)) {
    *(byte *)((int)&SEQ->REG058 + uVar1) =
         (byte)(1 << (uint)index) | *(byte *)((int)&SEQ->REG058 + uVar1);
    GENERIC_PHY_SetAddressFilteringMatchTable();
    return true;
  }
  return false;
}



bool RAIL_AddressFilterDisableAddress(uint8_t field,uint8_t index)

{
  uint uVar1;
  
  uVar1 = (uint)field;
  if ((uVar1 < 2) && (index < 4)) {
    *(byte *)((int)&SEQ->REG058 + uVar1) =
         *(byte *)((int)&SEQ->REG058 + uVar1) & ~(byte)(1 << (uint)index);
    GENERIC_PHY_SetAddressFilteringMatchTable();
    return true;
  }
  return false;
}



uint16_t RAIL_GetRadioEntropy(uint8_t *buffer,uint16_t bytes)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  CORE_irqState_t irqState;
  uint __n;
  size_t __n_00;
  uint uStack36;
  
  __n = (uint)bytes;
  uVar4 = (CMU->HFRADIOCLKEN0);
  uStack36 = __n;
  memset(buffer,0,__n);
  if ((((uVar4 | 0xcc) == uVar4) &&
      (uVar4 = (RAC->CTRL), -1 < (int)(uVar4 << 0x1f))) &&
     (uVar4 = RADIOCMU_ClockPrescGet(0x75160), uVar4 == 0)) {
    irqState = CORE_EnterCritical();
    uVar3 = (MODEM->CTRL0);
    uVar2 = (FRC->RAWCTRL);
    BUS_RegMaskedClear(&MODEM->CTRL0,0x38000000);
    BUS_RegMaskedSet(&MODEM->CTRL0,0x8000000);
    write_volatile_4(FRC->RAWCTRL,0x24);
    BUS_RegMaskedSet(&RAC->RXENSRCEN,4);
    write_volatile_4(FRC->IFC,0x4000);
    write_volatile_4(FRC->CMD,0x1000);
    for (; uVar4 < __n; uVar4 = uVar4 + __n_00 & 0xffff) {
      do {
        do {
          uVar1 = (FRC->IF);
        } while (-1 < (int)(uVar1 << 0x11));
        uVar1 = (FRC->STATUS);
      } while (-1 < (int)(uVar1 << 0x17));
      __n_00 = __n - uVar4;
      write_volatile_4(FRC->IFC,0x4000);
      if (3 < (int)__n_00) {
        __n_00 = 4;
      }
      uStack36 = (FRC->RXRAWDATA);
      memcpy(buffer + uVar4,&uStack36,__n_00);
    }
    BUS_RegMaskedClear(&RAC->RXENSRCEN,4);
    write_volatile_4(FRC->RAWCTRL,uVar2);
    write_volatile_4(MODEM->CTRL0,uVar3);
    write_volatile_4(FRC->IFC,0x4000);
    CORE_ExitCritical(irqState);
  }
  else {
    bytes = 0;
  }
  return bytes;
}



void pktTxDoneEvt(undefined4 param_1,RAIL_TxPacketInfo_t param_2,undefined4 param_3)

{
  RAIL_TxPacketInfo_t local_c;
  undefined4 uStack8;
  
  local_c = (uint32_t)param_2;
  uStack8 = param_3;
  GENERIC_PHY_PreviousTxTime();
  local_c = TIMING_GetTxTimestampUs();
  RAILCb_TxPacketSent(&local_c);
  return;
}



void pktRxFrmErr(void)

{
  write_volatile_4(FRC->IFC,0x80);
  RAILCb_RxRadioStatusExt(0x10);
  return;
}



void pktRxOverflow(void)

{
  RAILCb_RxRadioStatusExt(0x20);
  return;
}



void filterPass(void)

{
  RAILCb_RxRadioStatusExt(0x800);
  return;
}



void pktRxAborted(void)

{
  uint uVar1;
  uint32_t status;
  
  uVar1 = (RAC->SR0);
  BUS_RegMaskedClear(&RAC->SR0,0x1000000);
  if ((int)(uVar1 << 7) < 0) {
    status = 0x40;
  }
  else {
    status = 0x400;
  }
  RAILCb_RxRadioStatusExt(status);
  return;
}



void preambleDetected(void)

{
  RAILCb_RxRadioStatusExt(2);
  return;
}



void frameDet0(void)

{
  RAILCb_RxRadioStatusExt(4);
  return;
}



void frameDet1(void)

{
  RAILCb_RxRadioStatusExt(8);
  return;
}



void rxFifoUnderflow(void)

{
  RAILCb_RxRadioStatusExt(1);
  return;
}



void RAIL_RFSENSE_Callback(void)

{
  RAILCb_RxRadioStatusExt(0x80);
  return;
}



void protmrRetry(void)

{
  RAILCb_TxRadioStatus('@');
  return;
}



void protmrStartCca(void)

{
  RAILCb_TxRadioStatus(0x80);
  return;
}



void txFifoOverflow(void)

{
  RAILCb_TxRadioStatus('\x01');
  return;
}



void racStateChange(void)

{
  uint uVar1;
  
  uVar1 = (RAC->STATUS);
  RAILCb_RadioStateChanged((byte)((uVar1 << 4) >> 0x1c));
  return;
}



void softwareTimerExpired(void)

{
  timerExpired = 1;
  GENERIC_PHY_TimerStop();
  RAILCb_TimerExpired();
  return;
}



void rxFifoAlmostFull(void)

{
  uint16_t bytesAvailable;
  
  bytesAvailable = BUFC_GetBytesAvailable(1);
  RAILCb_RxFifoAlmostFull(bytesAvailable);
  return;
}



void txFifoAlmostEmpty(void)

{
  uint16_t spaceAvailable;
  
  spaceAvailable = BUFC_GetSpaceAvailable(0);
  RAILCb_TxFifoAlmostEmpty(spaceAvailable);
  return;
}



void racCalRequest(void)

{
  RAILINT_CalibrationPend(1);
  return;
}



void pktRxDoneEvt(void)

{
  byte bVar1;
  uint16_t uVar2;
  uint32_t uVar3;
  void *handle;
  void *pvVar4;
  undefined4 *puVar5;
  uint size;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint64_t uVar9;
  ushort local_3c;
  byte local_3a;
  undefined local_39;
  void *local_38;
  undefined auStack52 [5];
  undefined local_2f;
  byte local_2e;
  uint32_t local_28;
  
  BUFC_RxLengthReadNext(&local_3c);
  uVar6 = -((int)((uint)(byte)bufcEnabledCallbacks << 0x1d) >> 0x1f);
  if (uVar6 == 0) {
    uVar3 = RADIO_RxTrailDataLength();
    if (local_3c != 0xffff) {
      uVar8 = local_3c - uVar3 & 0xffff;
      handle = RAILCb_AllocateMemory(uVar8 + 0xc);
      while (uVar6 < uVar8) {
        local_38 = (void *)(uVar8 - uVar6);
        pvVar4 = RAILCb_BeginWriteMemory(handle,uVar6 + 10,(uint32_t *)&local_38);
        if (local_38 == (void *)0x0) {
          pvVar4 = local_38;
          local_38 = (void *)(uVar8 - uVar6);
        }
        uVar2 = GENERIC_PHY_PacketRxDataHelper((int)pvVar4,(uint)local_38 & 0xffff);
        size = (uint)uVar2;
        uVar7 = uVar6 + size;
        if (pvVar4 == (void *)0x0) {
          size = 0;
        }
        RAILCb_EndWriteMemory(handle,uVar6 + 10,size);
        uVar6 = uVar7 & 0xffff;
      }
      GENERIC_PHY_PacketRxAppendedInfoHelper(uVar3,auStack52);
      local_38 = (void *)0xc;
      puVar5 = (undefined4 *)RAILCb_BeginWriteMemory(handle,0,(uint32_t *)&local_38);
      if ((puVar5 == (undefined4 *)0x0) || (local_38 < (void *)0xc)) {
        uVar3 = 0;
      }
      else {
        read_volatile(FRC->IEN._0_1_);
        uVar6 = (FRC->IF);
        *(short *)(puVar5 + 2) = (short)uVar8;
        *(byte *)(puVar5 + 1) =
             *(byte *)(puVar5 + 1) & 0xfd | (byte)((((uVar6 ^ 0x80) << 0x18) >> 0x1f) << 1);
        write_volatile_4(FRC->IFC,0x80);
        bVar1 = *(byte *)(puVar5 + 1);
        if (local_2e != 0) {
          local_2e = 1;
        }
        *(byte *)(puVar5 + 1) = bVar1 & 0xfe | local_2e & 1;
        *(undefined *)((int)puVar5 + 5) = local_2f;
        *(undefined *)((int)puVar5 + 6) = local_39;
        *(byte *)(puVar5 + 1) =
             bVar1 & 0xfa | local_2e & 1 | (byte)((((uint)local_3a << 0x1c) >> 0x1f) << 2);
        uVar9 = TIMING_GetRxTimestampUs(local_28);
        *puVar5 = (int)uVar9;
        *(undefined *)((int)puVar5 + 7) = 0;
        uVar3 = 0xc;
      }
      RAILCb_EndWriteMemory(handle,0,uVar3);
      RAILCb_RxPacketReceived(handle);
      RAILCb_FreeMemory(handle);
    }
  }
  else {
    RAILCb_RxPacketReceived((void *)0x0);
  }
  return;
}



void rxTimeout(int param_1)

{
  uint32_t status;
  
  if (param_1 == 1) {
    if (-1 < rxConfigEvents << 0x16) {
      return;
    }
    status = 0x200;
  }
  else {
    if ((param_1 != 2) || (-1 < rxConfigEvents << 0x17)) {
      return;
    }
    status = 0x100;
  }
  RAILCb_RxRadioStatusExt(status);
  return;
}



void sequencerInterrupt(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined local_1c [2];
  undefined2 local_1a;
  
  if (param_1 << 10 < 0) {
    RAILCb_RxAckTimeout();
  }
  if ((param_1 << 0xc < 0) && (iVar4 = GENERIC_PHY_CanModifyAck(), iVar4 != 0)) {
    uVar2 = (BUFC->BUF1_ADDR);
    uVar1 = (BUFC->BUF1_CTRL);
    uVar3 = (RAC->SR1);
    uVar7 = (uVar3 << 0x18) >> 0x1e;
    uVar8 = (0x40 << (uVar1 & 0xff)) - 1U & 0xffff;
    uVar1 = (SEQ->REG004);
    local_1c[0] = (byte)uVar3 >> 6;
    iVar4 = uVar2 + 0x20000000;
    if (uVar7 == 3) {
      iVar5 = 0;
      do {
        iVar6 = iVar5 + 1;
        *(undefined *)((int)&local_1a + iVar5) =
             *(undefined *)(iVar4 + (((uVar1 & 0xffff) - 8) + iVar5 & uVar8));
        iVar5 = iVar6;
      } while (iVar6 != 8);
    }
    else {
      if (uVar7 != 2) {
        return;
      }
      local_1a = CONCAT11(*(undefined *)(iVar4 + ((uVar1 & 0xffff) - 1 & uVar8)),
                          *(undefined *)(iVar4 + ((uVar1 & 0xffff) - 2 & uVar8)));
    }
    RAILCb_IEEE802154_DataRequestCommand((RAIL_IEEE802154_Address_t *)local_1c);
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void rssiAverageDone(void)

{
  MODEM_SET *pMVar1;
  
  _enabledCallbacks = _enabledCallbacks & 0xfbffffff;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  currentRssiAverage = RADIO_GetRSSI();
  RAIL_RfIdle();
  if (saveFrameDetDisable == '\0') {
    pMVar1 = (MODEM_SET *)&Peripherals::MODEM_CLR;
  }
  else {
    pMVar1 = &Peripherals::MODEM_SET;
  }
  ((MODEM_CLR *)pMVar1)->CTRL0 = 0x200000;
  RAILCb_RssiAverageDone(currentRssiAverage);
  BUS_RegMaskedClear(&AGC->CTRL1,0xffffff00);
  BUS_RegMaskedSet(&AGC->CTRL1,saveRssiPeriod & 0xffffff00);
  isRssiReady = 1;
  return;
}



uint userTransmitStarted(void)

{
  uint uVar1;
  
  uVar1 = (RAC->SR0);
  uVar1 = uVar1 & 0x80;
  if (uVar1 != 0) {
    uVar1 = (PROTIMER->STATUS);
    if (-1 < (int)(uVar1 << 0x1d)) {
      uVar1 = (PROTIMER->CC3_CTRL);
      return uVar1 & 1 ^ 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}



void pktTxErrorEvt(uint param_1)

{
  int iVar1;
  
  if (((param_1 & 0x1c) != 0) && (iVar1 = userTransmitStarted(), iVar1 != 0)) {
    BUS_RegMaskedClear(&RAC->SR0,0x80);
    BUS_RegMaskedClear(&RAC->RXENSRCEN,0x10);
  }
  if ((txConfigEvents & param_1) != 0) {
    RAILCb_TxRadioStatus((uint8_t)(txConfigEvents & param_1));
    return;
  }
  return;
}



void protmrLbtEvt(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  PROTIMER_CCTimerStop(4);
  if (param_1 << 9 < 0) {
    RADIO_PTI_AuxdataOutput(0x27);
    write_volatile_4(BUFC->BUF0_CMD,1);
    uVar1 = (SEQ->REG00C);
    if ((uVar1 & 0xff000000) == 0x2000000) {
      BUS_RegMaskedSet(&RAC->RXENSRCEN,2);
    }
LAB_0000eb78:
    uVar2 = 4;
  }
  else {
    if (-1 < param_1 << 0xb) {
      if (-1 < param_1 << 0x13) goto LAB_0000eb7e;
      PROTIMER_LBTStop();
      uVar1 = (PROTIMER->IF);
      if ((uVar1 & 0x500000) != 0) goto LAB_0000eb7e;
      RADIO_PTI_AuxdataOutput(0x2a);
      write_volatile_4(BUFC->BUF0_CMD,1);
      goto LAB_0000eb78;
    }
    RADIO_PTI_AuxdataOutput(0x28);
    uVar2 = 0x20;
  }
  pktTxErrorEvt(uVar2);
LAB_0000eb7e:
  BUS_RegMaskedClear(&AGC->CTRL1,0xffffff00);
  BUS_RegMaskedSet(&AGC->CTRL1,saveRssiPeriodPreCca & 0xffffff00);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint8_t RFHAL_Init(RAIL_Init_t *railinit)

{
  uint32_t uVar1;
  RAIL_CalMask_t RVar2;
  
  uVar1 = SystemHFXOClockGet();
  if (uVar1 == railinit->rfXtalFreq) {
    GENERIC_PHY_Init();
    write_volatile_4(FRC->TRAILRXDATA,0x1b);
    write_volatile_4(FRC->RXCTRL,0x60);
    _enabledCallbacks =
         _enabledCallbacks & 0xff000000 | (uint)(uint3)((uint3)_enabledCallbacks | 7) | 0x400000;
    RVar2 = RAILINT_CalibrationEnableGet();
    if ((int)(RVar2 << 0x1f) < 0) {
      _enabledCallbacks = _enabledCallbacks | 0x80000;
    }
    _enabledCallbacks = _enabledCallbacks | 0x100000;
    GENERIC_PHY_SetCallbacks((uint32_t *)&callbacks);
    GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
    BUFC_SetCallbacks((uint32_t *)&bufcCallbacks);
    bufcEnabledCallbacks = 0;
    BUFC_ConfigureCallbacks(0);
    RAILCb_RfReady();
    return '\0';
  }
  return '\x01';
}



RAIL_Status_t RFHAL_SetPtiProtocol(RAIL_PtiProtocol_t protocol1)

{
  uint uVar1;
  uint in_r3;
  int unaff_r4;
  bool bVar2;
  
  bVar2 = (protocol1 & 0xf0) == 0;
  if (bVar2) {
    unaff_r4 = 0x21000f64;
    uVar1 = (SEQ->REG06C);
    in_r3 = uVar1 & 0xfffffff0 | protocol1 & 0xf;
    protocol1 = protocol1 & 0xf0;
  }
  if (bVar2) {
    *(uint *)(unaff_r4 + 8) = in_r3;
  }
  else {
    protocol1 = RAIL_STATUS_INVALID_PARAMETER;
  }
  return (RAIL_Status_t)protocol1;
}



void RFHAL_IdleExt(undefined4 mode)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  switch(mode) {
  case 0:
    uVar2 = 0;
    uVar1 = uVar2;
    uVar3 = uVar2;
    goto LAB_0000ec7c;
  case 1:
    uVar1 = 0;
    break;
  case 2:
    uVar1 = 1;
    break;
  case 3:
    uVar2 = 1;
    uVar1 = uVar2;
    uVar3 = uVar2;
    goto LAB_0000ec7c;
  default:
    return;
  }
  uVar2 = 1;
  uVar3 = 0;
LAB_0000ec7c:
  GENERIC_PHY_RadioIdle(uVar2,uVar1,uVar3);
  return;
}



RAIL_RadioState_t RFHAL_StateGet(void)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = (RAC->STATUS);
  uVar1 = uVar1 & 0xf000000;
  if (uVar1 != 0x7000000) {
    if (0x7000000 < uVar1) {
      if (uVar1 != 0xa000000) {
        if (uVar1 < 0xa000001) {
          if (uVar1 == 0x8000000) {
            return RAIL_RF_STATE_TX;
          }
          bVar2 = uVar1 == 0x9000000;
        }
        else {
          if (uVar1 == 0xb000000) {
            return RAIL_RF_STATE_TX;
          }
          bVar2 = uVar1 == 0xc000000;
        }
        if (!bVar2) {
          return RAIL_RF_STATE_IDLE;
        }
      }
      return RAIL_RF_STATE_TX;
    }
    if (uVar1 != 0x3000000) {
      if (uVar1 < 0x3000001) {
        if (uVar1 == 0x1000000) {
          return RAIL_RF_STATE_RX;
        }
        bVar2 = uVar1 == 0x2000000;
      }
      else {
        if (uVar1 == 0x4000000) {
          return RAIL_RF_STATE_RX;
        }
        bVar2 = uVar1 == 0x5000000;
      }
      if (!bVar2) {
        return RAIL_RF_STATE_IDLE;
      }
    }
  }
  return RAIL_RF_STATE_RX;
}



bool RFHAL_OkToTransmit(void)

{
  uint uVar1;
  
  uVar1 = (RAC->SR0);
  return (bool)((byte)((byte)uVar1 ^ 0x80) >> 7);
}



int RFHAL_HeadedToIdle(void)

{
  uint uVar1;
  bool bVar2;
  CORE_irqState_t irqState;
  uint uVar3;
  int iVar4;
  
  irqState = CORE_EnterCritical();
  bVar2 = PROTIMER_CCTimerIsEnabled(3);
  if ((bVar2 == false) && (iVar4 = PROTIMER_LBTIsActive(), iVar4 == 0)) {
    uVar3 = (RAC->STATUS);
    uVar1 = (RAC->SR0);
    CORE_ExitCritical(irqState);
    if ((((uVar3 & 0xc0000000) == 0) && (-1 < (int)(uVar1 << 0x18))) &&
       (uVar3 = uVar3 & 0xf000000, uVar3 != 0x6000000)) {
      if (uVar3 < 0x6000001) {
        bVar2 = uVar3 == 0x3000000;
      }
      else {
        if (uVar3 == 0x9000000) {
          return 0;
        }
        bVar2 = uVar3 == 0xc000000;
      }
      if (!bVar2) {
        iVar4 = 1;
      }
    }
  }
  else {
    CORE_ExitCritical(irqState);
    iVar4 = 0;
  }
  return iVar4;
}



uint8_t RFHAL_TxDataLoad(RAIL_TxData_t *txData)

{
  CORE_irqState_t irqState;
  uint uVar1;
  uint8_t uVar2;
  
  irqState = CORE_EnterCritical();
  uVar1 = (RAC->STATUS);
  uVar1 = (uVar1 << 4) >> 0x1c;
  if (((uVar1 - 7 < 3) || (uVar1 == 0xc)) &&
     (uVar1 = (RAC->SR0), (int)(uVar1 << 0xf) < 0)) {
    uVar2 = '\x03';
  }
  else {
    write_volatile_4(BUFC->BUF0_CMD,1);
    BUFC_WriteBuffer(0,txData->dataPtr,txData->dataLength);
    uVar2 = '\0';
  }
  CORE_ExitCritical(irqState);
  return uVar2;
}



uint8_t RAIL_CcaCsma(void *params)

{
  byte bVar1;
  uint32_t us;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte bVar6;
  uint uVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  PROTIMER *pPVar11;
  uint uVar12;
  uint64_t uVar13;
  
  saveRssiPeriodPreCca = (AGC->CTRL1);
  if (params == (void *)0x0) {
    BUS_RegMaskedClear(&AGC->CTRL1,0xffffff00);
    BUS_RegMaskedSet(&AGC->CTRL1,saveRssiPeriodInCca & 0xffffff00);
    PROTIMER_LBTUseLastConfig();
  }
  else {
    RADIO_SetAgcCcaParams
              (*(undefined2 *)((int)params + 6),(int)*(char *)((int)params + 3),saveRssiPeriodPreCca
               ,&saveRssiPeriodPreCca,params);
    saveRssiPeriodInCca = (AGC->CTRL1);
    bVar10 = *(byte *)((int)params + 2);
                    // WARNING: Load size is inaccurate
    bVar1 = *params;
    bVar9 = *(byte *)((int)params + 1);
    bVar8 = bVar10;
    bVar6 = bVar10;
    if (bVar10 != 0) {
      bVar6 = bVar10 - 1;
      bVar10 = bVar1;
      if (bVar9 < bVar1) {
        bVar9 = bVar1;
        bVar8 = 1;
      }
      else {
        bVar8 = 1;
      }
    }
                    // WARNING: Load size is inaccurate
    uVar7 = count_leading_zeroes((uint)*params);
    pPVar11 = (PROTIMER *)0xedff;
    uVar13 = PROTIMER_UsToPrecntOverflow((uint)*(ushort *)((int)params + 4));
    uVar3 = (uint)(ushort)uVar13;
    if (uVar7 >> 5 == 0) {
      uVar4 = (uint)reseedRandom_8945;
      if (uVar4 != 0xf804) {
        pPVar11 = &Peripherals::PROTIMER;
      }
      if (uVar4 != 0xf804) {
        pPVar11->RANDOM = uVar4;
        reseedRandom_8945 = 0xf804;
      }
    }
    else {
      uVar5 = 0;
      uVar4 = uVar3;
      while( true ) {
        uVar12 = uVar5 & 0xff;
        uVar5 = uVar5 + 1;
        if (uVar4 < 0x100) break;
        uVar4 = uVar4 >> 1;
      }
      if ((uVar12 != 0) && (uVar4 != 0xff)) {
        uVar4 = (uint)(ushort)(((ushort)((int)uVar3 >> (uVar12 - 1 & 0xff)) & 1) + (short)uVar4);
      }
      uVar3 = uVar4;
      uVar4 = (PROTIMER->RANDOM);
      reseedRandom_8945 = (ushort)(uVar4 & 0xffff);
      if ((uVar4 & 0xffff) == 0xf804) {
        reseedRandom_8945 = 0xf805;
      }
      write_volatile_4(PROTIMER->RANDOM,(1 << uVar12) - 1);
      bVar9 = 8;
      write_volatile_4(PROTIMER->LBTSTATE,0x800000);
      bVar10 = 8;
    }
    if (uVar3 < 0x100) {
      uVar3 = uVar3 - 1;
    }
    else {
      uVar3 = 0xff;
    }
    write_volatile_4(PROTIMER->BASECNTTOP,uVar3);
    PROTIMER_LBTCfgSet(bVar10,bVar9,bVar8,bVar6,0);
    if (uVar7 >> 5 != 0) {
      BUS_RegMaskedSet(&PROTIMER->LBTCTRL,0x100000);
      uVar3 = (PROTIMER->CTRL);
      write_volatile_4(PROTIMER->CTRL,uVar3 & 0xff3fffff | 0x400000);
    }
    lbtTimeout_8944 = *(uint32_t *)((int)params + 8);
  }
  GENERIC_PHY_PacketTxCommon();
  us = lbtTimeout_8944;
  if (lbtTimeout_8944 != 0) {
    bVar2 = PROTIMER_CCTimerIsEnabled(4);
    if (bVar2 != false) {
      PROTIMER_CCTimerStop(4);
    }
    uVar13 = PROTIMER_UsToPrecntOverflow(us);
    bVar2 = PROTIMER_CCTimerStart(4,(uint32_t)uVar13,RAIL_TIME_DELAY);
    if (bVar2 == false) {
      return '\x01';
    }
  }
  PROTIMER_LBTStart();
  return '\0';
}



// WARNING: Could not reconcile some variable overlaps

uint8_t RAIL_CcaLbt(void *params)

{
  uint8_t uVar1;
  uint uVar2;
  uint in_r1;
  byte bVar3;
  uint in_r2;
  undefined4 in_r3;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 uStack12;
  
  local_14 = in_r1;
  local_10 = in_r2;
  uStack12 = in_r3;
                    // WARNING: Load size is inaccurate
  if ((params != (void *)0x0) && (*params != 0)) {
                    // WARNING: Load size is inaccurate
    local_14 = *params;
    local_10._2_2_ = (ushort)((uint)*(undefined4 *)((int)params + 4) >> 0x10);
    uStack12 = *(undefined4 *)((int)params + 8);
                    // WARNING: Load size is inaccurate
    bVar3 = *params;
    if (bVar3 != 0) {
      local_10._2_2_ = *(short *)((int)params + 4) * (ushort)bVar3 + local_10._2_2_;
      local_14._1_1_ = (char)(local_14 >> 8);
      local_14._2_2_ = (undefined2)(local_14 >> 0x10);
      local_14 = (uint)CONCAT21(local_14._2_2_,local_14._1_1_ - bVar3) << 8;
    }
    uVar2 = local_14 >> 8 & 0xff;
    for (bVar3 = 1; (uint)(1 << (uint)bVar3) < uVar2; bVar3 = bVar3 + 1) {
    }
    local_10 = uVar2 * *(ushort *)((int)params + 4) + ((uint)(1 << (uint)bVar3) >> 1) >> (uint)bVar3
               & 0xffff | (uint)local_10._2_2_ << 0x10;
    local_14._0_2_ = CONCAT11(bVar3,bVar3);
    local_14 = local_14 & 0xffff0000 | (uint)(ushort)local_14;
    params = &local_14;
  }
  uVar1 = RAIL_CcaCsma(params);
  return uVar1;
}



int16_t RFHAL_PollAverageRSSI(uint32_t averageTimeUs)

{
  int16_t iVar1;
  uint32_t begin;
  uint32_t uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  uint64_t uVar8;
  
  if (averageTimeUs == 0) {
    iVar1 = RADIO_GetRSSI();
    return iVar1;
  }
  begin = PROTIMER_GetTime();
  uVar8 = PROTIMER_UsToPrecntOverflow(averageTimeUs);
  iVar4 = 0;
  uVar5 = 0;
  iVar6 = 0;
  while( true ) {
    uVar2 = PROTIMER_GetTime();
    uVar2 = PROTIMER_ElapsedTime(begin,uVar2);
    if ((uint)uVar8 <= uVar2) break;
    iVar1 = RADIO_GetRSSI();
    if (iVar1 != -0x200) {
      uVar3 = SEXT24(iVar1);
      bVar7 = CARRY4(uVar5,uVar3);
      uVar5 = uVar5 + uVar3;
      iVar6 = iVar6 + ((int)uVar3 >> 0x1f) + (uint)bVar7;
      iVar4 = iVar4 + 1;
    }
  }
  if (iVar4 == 0) {
    iVar1 = -0x200;
  }
  else {
    iVar1 = __aeabi_ldivmod(uVar5,iVar6,iVar4,iVar4 >> 0x1f);
  }
  return iVar1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

RAIL_Status_t RFHAL_StartAverageRSSI(uint8_t channel,uint32_t averagingTimeUs)

{
  RAIL_Status_t RVar1;
  uint8_t uVar2;
  int iVar3;
  
  isRssiReady = 0;
  saveRssiPeriod = (AGC->CTRL1);
  RVar1 = RADIO_CalcRssiPeriod(averagingTimeUs);
  if (RVar1 == RAIL_STATUS_NO_ERROR) {
    iVar3 = _DAT_430c0354;
    if (_DAT_430c0354 != 0) {
      iVar3 = 1;
    }
    saveFrameDetDisable = (undefined)iVar3;
    BUS_RegMaskedSet(&MODEM->CTRL0,0x200000);
    uVar2 = RAIL_RxStart(channel);
    if (uVar2 == '\0') {
      _enabledCallbacks = _enabledCallbacks | 0x4000000;
      GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
    }
    else {
      RVar1 = RAIL_STATUS_INVALID_STATE;
    }
  }
  else {
    RVar1 = RAIL_STATUS_INVALID_PARAMETER;
  }
  return RVar1;
}



int16_t RFHAL_GetAverageRSSI(void)

{
  return currentRssiAverage;
}



void RFHAL_ScheduleRx(uint8_t channel,RAIL_ScheduleRxConfig_t *config)

{
  uint uVar1;
  uint32_t us;
  uint8_t uVar2;
  undefined4 uVar3;
  RAIL_TimeMode_t RVar4;
  RAIL_TimeMode_t RVar5;
  undefined4 uVar6;
  uint64_t uVar7;
  
  uVar1 = TIMING_RxWarmTimeGet();
  RVar5 = config->startMode;
  if (RVar5 == RAIL_TIME_DELAY) {
    if (uVar1 <= config->start) goto LAB_0000f09a;
    us = 0;
  }
  else {
    if (RVar5 == RAIL_TIME_DISABLED) {
      uVar6 = 0;
      goto LAB_0000f0b4;
    }
LAB_0000f09a:
    us = config->start - uVar1;
  }
  uVar7 = PROTIMER_UsToPrecntOverflow(us);
  uVar6 = (undefined4)uVar7;
  RVar5 = config->startMode;
  if (RVar5 != RAIL_TIME_ABSOLUTE) {
    RVar5 = RAIL_TIME_DELAY;
  }
LAB_0000f0b4:
  RVar4 = config->endMode;
  if (RVar4 == RAIL_TIME_DISABLED) {
    uVar3 = 0;
  }
  else {
    uVar7 = PROTIMER_UsToPrecntOverflow(config->end);
    uVar3 = (undefined4)uVar7;
    RVar4 = config->endMode;
    if (RVar4 != RAIL_TIME_ABSOLUTE) {
      RVar4 = RAIL_TIME_DELAY;
    }
  }
  uVar1 = count_leading_zeroes((uint)config->rxTransitionEndSchedule);
  uVar2 = config->hardWindowEnd;
  if (uVar2 != '\0') {
    uVar2 = '\x01';
  }
  GENERIC_PHY_SchedulePacketRx(uVar6,RVar5,uVar3,RVar4,uVar1 >> 5,uVar2);
  return;
}



uint8_t RAIL_ScheduleTx(void *params)

{
  uint8_t uVar1;
  uint uVar2;
  uint32_t us;
  char cVar3;
  uint64_t uVar4;
  
  cVar3 = *(char *)((int)params + 4);
  if (cVar3 != '\0') {
    cVar3 = '\x01';
  }
  uVar2 = TIMING_TxWarmTimeGet();
                    // WARNING: Load size is inaccurate
  if ((*(char *)((int)params + 4) == '\x01') && (*params < uVar2)) {
    us = 0;
  }
  else {
    us = *params - uVar2;
  }
  uVar4 = PROTIMER_UsToPrecntOverflow(us);
  uVar1 = GENERIC_PHY_SchedulePacketTx((int)uVar4,cVar3);
  return uVar1;
}



uint8_t RFHAL_RxStart(uint8_t reset)

{
  uint uVar1;
  
  uVar1 = (RAC->RXENSRCEN);
  if ((uVar1 & 0xff) == 0) {
    BUFC_RxBufferReset(reset);
  }
  GENERIC_PHY_StartRx(0);
  return '\0';
}



void RFHAL_EnableRxRawCapture(void)

{
  uint uVar1;
  int in_r0;
  uint uVar2;
  uint in_r1;
  
  uVar2 = in_r0 - 1U & 0xff;
  if (uVar2 < 3) {
    in_r1 = *(uint *)(&CSWTCH_104 + uVar2 * 4);
  }
  uVar1 = (MODEM->CTRL0);
  if (2 < uVar2) {
    in_r1 = 0;
  }
  write_volatile_4(MODEM->CTRL0,uVar1 & 0xc7ffffff | in_r1);
  BUS_RegMaskedSet(&MODEM->CTRL0,0x200000);
  uVar2 = (FRC->BUFFERMODE);
  write_volatile_4(FRC->BUFFERMODE,uVar2 & 0xfffffff9 | 4);
  BUS_RegMaskedSet(&RAC->SR3,0x10000000);
  write_volatile_4(FRC->RAWCTRL,4);
  return;
}



void RFHAL_DisableRxRawCapture(void)

{
  BUS_RegMaskedClear(&FRC->BUFFERMODE,6);
  write_volatile_4(FRC->RAWCTRL,0);
  BUS_RegMaskedClear(&RAC->SR3,0x10000000);
  BUS_RegMaskedClear(&MODEM->CTRL0,0x200000);
  BUS_RegMaskedClear(&MODEM->CTRL0,0x38000000);
  return;
}



void RFHAL_EnableRxAppendedInfo(void)

{
  write_volatile_4(FRC->TRAILRXDATA,0x1b);
  return;
}



void RFHAL_DisableRxAppendedInfo(void)

{
  write_volatile_4(FRC->TRAILRXDATA,0);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint8_t RFHAL_RxIntEnable(uint32_t cbtoenable)

{
  _enabledCallbacks =
       CONCAT11(DAT_20002df9 & 0xc5 | (byte)(((cbtoenable << 0x1e) >> 0x1f) << 3) |
                (byte)(((cbtoenable << 0x1d) >> 0x1f) << 4) |
                (byte)(((cbtoenable << 0x1c) >> 0x1f) << 5) |
                (byte)(((cbtoenable << 0x14) >> 0x1f) << 1),
                enabledCallbacks & 0x87 | (byte)(((cbtoenable << 0x1b) >> 0x1f) << 3) |
                (byte)(((cbtoenable << 0x1a) >> 0x1f) << 4) |
                (byte)(((cbtoenable << 0x15) >> 0x1f) << 5) | ((cbtoenable & 0x300) != 0) << 6);
  _enabledCallbacks = _enabledCallbacks & 0xffff0000 | (uint)_enabledCallbacks;
  bufcEnabledCallbacks =
       bufcEnabledCallbacks & 0xffffff00 |
       (uint)((byte)bufcEnabledCallbacks & 0xf7 | (byte)(cbtoenable << 3) & 8);
  rxConfigEvents = cbtoenable;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  BUFC_ConfigureCallbacks(bufcEnabledCallbacks);
  return '\0';
}



RAIL_Status_t RFHAL_SetRxOptions(uint32_t options)

{
  uint uVar1;
  RAIL_Status_t RVar2;
  
  uVar1 = (RAC->STATUS);
  if ((uVar1 << 4) >> 0x1c == 3) {
    return RAIL_STATUS_INVALID_STATE;
  }
  RVar2 = (RAIL_Status_t)(options & 1);
  if ((options & 1) == 0) {
    BUS_RegMaskedClear(&FRC->RXCTRL,1);
  }
  else {
    RVar2 = RAIL_STATUS_NO_ERROR;
    BUS_RegMaskedSet(&FRC->RXCTRL,1);
  }
  return RVar2;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

RAIL_Status_t RFHAL_TxIntEnable(uint32_t cbToEnable)

{
  _enabledCallbacks =
       CONCAT12(DAT_20002dfa & 0x7f | 0x40 | (byte)(((cbToEnable << 0x19) >> 0x1f) << 7),
                _enabledCallbacks);
  _enabledCallbacks =
       _enabledCallbacks & 0xffffff00 |
       (uint)(byte)((byte)(_enabledCallbacks >> 0x18) & 0xfe | (byte)cbToEnable >> 7) << 0x18 |
       (uint)(byte)(enabledCallbacks & 0xfd | ((cbToEnable & 0x1b) != 0) << 1);
  bufcEnabledCallbacks =
       bufcEnabledCallbacks & 0xffffff00 |
       (uint)((byte)bufcEnabledCallbacks & 0xfd | (byte)(cbToEnable << 1) & 2);
  txConfigEvents = cbToEnable;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  BUFC_ConfigureCallbacks(bufcEnabledCallbacks);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RFHAL_ErrorConfig(uint8_t ignore)

{
  FRC_SET *pFVar1;
  
  if ((ignore & 1) == 0) {
    pFVar1 = (FRC_SET *)&Peripherals::FRC_CLR;
  }
  else {
    pFVar1 = &Peripherals::FRC_SET;
  }
  ((FRC_CLR *)pFVar1)->RXCTRL = 2;
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RAIL_PaCtuneSet(uint8_t txPaCtuneValue,uint8_t rxPaCtuneValue)

{
  PA_CTuneSet(txPaCtuneValue,rxPaCtuneValue);
  return RAIL_STATUS_NO_ERROR;
}



uint32_t RAIL_TimerGet(void)

{
  uint32_t cnt;
  uint64_t uVar1;
  
  cnt = GENERIC_PHY_TimerGetTimeout();
  uVar1 = PROTIMER_PrecntOverflowToUs(cnt);
  return (uint32_t)uVar1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RAIL_TimerCancel(void)

{
  GENERIC_PHY_TimerStop();
  _enabledCallbacks = _enabledCallbacks & 0xfdffffff;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

RAIL_Status_t RAIL_TimerSet(uint32_t time,RAIL_TimeMode_t mode)

{
  bool bVar1;
  CORE_irqState_t irqState;
  RAIL_TimeMode_t mode_00;
  uint64_t uVar2;
  
  mode_00 = mode;
  if (mode != RAIL_TIME_ABSOLUTE) {
    mode_00 = RAIL_TIME_DELAY;
  }
  if (mode == RAIL_TIME_DISABLED) {
    RAIL_TimerCancel();
    return RAIL_STATUS_NO_ERROR;
  }
  irqState = CORE_EnterCritical();
  _enabledCallbacks = _enabledCallbacks | 0x2000000;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  timerExpired = 0;
  uVar2 = PROTIMER_UsToPrecntOverflow(time);
  bVar1 = GENERIC_PHY_TimerStart((uint32_t)uVar2,mode_00);
  CORE_ExitCritical(irqState);
  return (RAIL_Status_t)(bVar1 ^ 1);
}



bool RAIL_TimerExpired(void)

{
  bool bVar1;
  byte bVar2;
  
  bVar1 = GENERIC_PHY_TimerExpired();
  bVar2 = timerExpired;
  if (bVar1 != false) {
    bVar2 = 1;
  }
  return (bool)(bVar2 & 1);
}



bool RAIL_TimerIsRunning(void)

{
  bool bVar1;
  
  bVar1 = PROTIMER_CCTimerIsEnabled(2);
  return bVar1;
}



uint32_t RAIL_SymbolRateGet(void)

{
  uint uVar1;
  uint32_t uVar2;
  
  uVar2 = RADIO_ComputeTxBaudrate();
  uVar1 = (MODEM->CTRL0);
  if ((uVar1 & 0x30) == 0x20) {
    uVar2 = uVar2 / (((uVar1 << 0x10) >> 0x1b) + 1);
  }
  return uVar2;
}



uint32_t RAIL_BitRateGet(void)

{
  uint uVar1;
  uint32_t uVar2;
  uint uVar3;
  
  uVar1 = (MODEM->CTRL0);
  if ((uVar1 & 0x30) == 0x20) {
    uVar3 = ((uVar1 << 0x10) >> 0x1b) / ((uVar1 << 0xd) >> 0x1d);
    if ((uVar1 & 0x180000) != 0) {
      uVar3 = uVar3 << 1;
    }
    uVar3 = uVar3 >> 1;
    if (2 < uVar3) {
      uVar3 = 4;
    }
  }
  else {
    uVar1 = (MODEM->CTRL0);
    if (((uVar1 & 0x1c0) == 0x40) || ((uVar1 & 0x1c0) == 0x100)) {
      uVar3 = 2;
    }
    else {
      uVar3 = 1;
    }
  }
  uVar2 = RADIO_ComputeTxSymbolRate();
  return uVar3 * uVar2;
}



// WARNING: Could not reconcile some variable overlaps

uint32_t RAIL_RfSense(RAIL_RfSenseBand_t band,uint32_t senseTime,bool enableCb)

{
  uint32_t uVar1;
  uint in_r3;
  undefined4 local_14;
  uint32_t local_10;
  uint local_c;
  
  local_14 = 0xe7f5;
  if (enableCb == false) {
    local_14 = 0;
  }
  local_c._0_2_ = CONCAT11(1,band);
  local_c = in_r3 & 0xffff0000 | (uint)(ushort)local_c;
  local_10 = senseTime;
  uVar1 = RFSENSE_Init(&local_14);
  return uVar1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// WARNING: Unknown calling convention yet parameter storage is locked

bool RAIL_RfSensed(void)

{
  code *pcVar1;
  int iVar2;
  CORE_irqState_t irqState;
  uint uVar3;
  
  iVar2 = _DAT_43c81904;
  BUS_RegMaskedSet(&CMU->HFRADIOCLKEN0,2);
  uVar3 = (RFSENSE->IF);
  if (uVar3 != 0) {
    uVar3 = 1;
  }
  if (uVar3 != 0) {
    irqState = CORE_EnterCritical();
    pcVar1 = RFSENSE_Cb;
    RFSENSE_Cb = FUN_00000000;
    CORE_ExitCritical(irqState);
    RFSENSE_Disable();
    if (pcVar1 != FUN_00000000) {
      (*pcVar1)();
    }
  }
  if (iVar2 == 0) {
    BUS_RegMaskedClear(&CMU->HFRADIOCLKEN0,2);
  }
  return SUB41(uVar3,0);
}



uint8_t RFHAL_CalibrationInit(RAIL_CalInit_t *railCalInit)

{
  uint8_t uVar1;
  
  uVar1 = IRCAL_Init(railCalInit->irCalSettings);
  return uVar1;
}



void RFHAL_CalibrationRun(int *calValues,RAIL_CalMask_t calForce)

{
  int iVar1;
  
  if ((int)(calForce << 0x1f) < 0) {
    TEMPCAL_Perform();
  }
  if ((int)(calForce << 0xf) < 0) {
    if (*calValues == -1) {
      iVar1 = IRCAL_Perform();
      *calValues = iVar1;
      return;
    }
    IRCAL_Set();
    return;
  }
  return;
}



RAIL_Status_t RFHAL_SetTxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error)

{
  ushort uVar1;
  
  uVar1 = read_volatile_2(SEQ->REG00C._0_2_);
  write_volatile_4(SEQ->REG00C,
                   1 << (success + 0x10 & 0xff) | (uint)uVar1 | 1 << (error + 0x18 & 0xff));
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RFHAL_SetRxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error)

{
  ushort uVar1;
  
  uVar1 = read_volatile_2(SEQ->REG00C._2_2_);
  write_volatile_4(SEQ->REG00C,
                   1 << (error + 8 & 0xff) | 1 << success | (uint)uVar1 << 0x10);
  return RAIL_STATUS_NO_ERROR;
}



void RFHAL_SetCRCInitVal(uint32_t value)

{
  write_volatile_4(Peripherals::CRC.INIT,value);
  write_volatile_4(Peripherals::CRC.CMD,1);
  return;
}



int32_t RFHAL_GetCurrPowerLevel(void)

{
  return (int)gPaConfig.power;
}



int32_t RFHAL_SetCurrPowerLevel(int32_t powerLevel)

{
  code *pcVar1;
  uint8_t uVar2;
  int32_t iVar3;
  
  iVar3 = PA_OutputPowerSet(powerLevel);
  pcVar1 = protChChngCB;
  if (protChChngCB != FUN_00000000) {
    uVar2 = RAILInt_GetChannel();
    (*pcVar1)(uVar2,1);
  }
  return iVar3;
}



void RFHAL_SetProtocolSpecificChCheckCB(undefined4 param_1)

{
  protChChngCB = param_1;
  return;
}



void RFHAL_StopTestMode(void)

{
  RFTEST_StopTx();
  RFTEST_RestoreRadioConfiguration();
  return;
}



void RFHAL_StartCWTestMode(void)

{
  RFTEST_SaveRadioConfiguration();
  RFTEST_StartCwTx();
  return;
}



void RFHAL_StartStreamTestMode(void)

{
  RFTEST_SaveRadioConfiguration();
  RFTEST_StartStreamTx();
  return;
}



undefined4 RFHAL_SetChannel(undefined4 param_1,char *param_2,int param_3)

{
  uint uVar1;
  uint32_t uVar2;
  int iVar3;
  
  uVar2 = RAIL_DebugModeGet();
  if (uVar2 != 1) {
    do {
      iVar3 = RFHAL_HeadedToIdle();
      if (iVar3 == 0) break;
      uVar1 = (RAC->STATUS);
    } while ((uVar1 & 0xf000000) != 0);
    uVar1 = (RAC->STATUS);
    if ((uVar1 & 0xf000000) != 0) {
      return 2;
    }
    if (protChChngCB != FUN_00000000) {
      (*protChChngCB)(param_1);
    }
    if (param_3 != 0) {
      SYNTH_Config(*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 4));
    }
    GENERIC_PHY_ChannelSet((char)param_1 - *param_2);
  }
  return 0;
}



bool RFHAL_AutoAckEnable(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 | 0x20);
  CORE_ExitCritical(irqState);
  return SUB41((uVar1 << 0x1a) >> 0x1f,0);
}



bool RFHAL_AutoAckDisable(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 & 0xffffffdf);
  CORE_ExitCritical(irqState);
  return SUB41((uVar1 << 0x1a) >> 0x1f,0);
}



bool RFHAL_AutoAckIsEnabled(void)

{
  uint uVar1;
  
  uVar1 = (SEQ->REG000);
  return SUB41((uVar1 << 0x1a) >> 0x1f,0);
}



RAIL_Status_t RFHAL_AutoAckConfig(RAIL_AutoAckConfig_t *config)

{
  uint64_t uVar1;
  
  uVar1 = PROTIMER_UsToPrecntOverflow((uint)config->ackTimeout);
  write_volatile_4(SEQ->REG008,-(int)uVar1);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RFHAL_AutoAckLoadBuffer(RAIL_AutoAckData_t *ackData)

{
  CORE_irqState_t irqState;
  uint uVar1;
  RAIL_Status_t RVar2;
  
  irqState = CORE_EnterCritical();
  BUS_RegMaskedSet(&RAC->SR0,2);
  uVar1 = (RAC->STATUS);
  uVar1 = (uVar1 << 4) >> 0x1c;
  if (((uVar1 - 7 < 3) || (uVar1 == 0xc)) &&
     (uVar1 = (RAC->SR0), (int)(uVar1 << 0xe) < 0)) {
    RVar2 = RAIL_STATUS_INVALID_CALL;
  }
  else {
    BUFC_TxAckBufferSet(ackData->dataPtr,(ushort)ackData->dataLength);
    RVar2 = RAIL_STATUS_NO_ERROR;
  }
  BUS_RegMaskedClear(&RAC->SR0,2);
  CORE_ExitCritical(irqState);
  return RVar2;
}



void RFHAL_AutoAckRxPause(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 | 8);
  CORE_ExitCritical(irqState);
  return;
}



void RFHAL_AutoAckRxResume(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 & 0xfffffff7);
  CORE_ExitCritical(irqState);
  return;
}



void RFHAL_AutoAckTxPause(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 | 0x100);
  CORE_ExitCritical(irqState);
  return;
}



void RFHAL_AutoAckTxResume(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 & 0xfffffeff);
  CORE_ExitCritical(irqState);
  return;
}



bool RFHAL_AutoAckRxIsPaused(void)

{
  uint uVar1;
  
  uVar1 = (SEQ->REG000);
  return SUB41((uVar1 << 0x1c) >> 0x1f,0);
}



bool RFHAL_AutoAckTxIsPaused(void)

{
  uint uVar1;
  
  uVar1 = (SEQ->REG000);
  return SUB41((uVar1 << 0x17) >> 0x1f,0);
}



bool RFHAL_AutoAckUseTxBuffer(void)

{
  CORE_irqState_t irqState;
  uint uVar1;
  bool bVar2;
  
  irqState = CORE_EnterCritical();
  uVar1 = GENERIC_PHY_CanModifyAck();
  if (uVar1 != 0) {
    BUS_RegMaskedSet(&RAC->SR0,2);
    uVar1 = (RAC->SR0);
    bVar2 = -1 < (int)(uVar1 << 0xe);
    if (bVar2) {
      BUS_RegMaskedSet(&RAC->SR2,0x40);
    }
    uVar1 = (uint)bVar2;
    BUS_RegMaskedClear(&RAC->SR0,2);
  }
  CORE_ExitCritical(irqState);
  return SUB41(uVar1,0);
}



bool RFHAL_AutoAckCancelAck(void)

{
  CORE_irqState_t irqState;
  uint uVar1;
  bool bVar2;
  
  irqState = CORE_EnterCritical();
  uVar1 = GENERIC_PHY_CanModifyAck();
  if (uVar1 != 0) {
    BUS_RegMaskedSet(&RAC->SR0,2);
    uVar1 = (RAC->SR0);
    bVar2 = -1 < (int)(uVar1 << 0xe);
    if (bVar2) {
      BUS_RegMaskedSet(&RAC->SR2,0x20);
    }
    uVar1 = (uint)bVar2;
    BUS_RegMaskedClear(&RAC->SR0,2);
  }
  CORE_ExitCritical(irqState);
  return SUB41(uVar1,0);
}



void RFHAL_AutoAckWaitForAck(bool wait)

{
  RAC_SET *pRVar1;
  
  if (wait == false) {
    pRVar1 = &Peripherals::RAC_SET;
  }
  else {
    pRVar1 = (RAC_SET *)&Peripherals::RAC_CLR;
  }
  ((RAC_CLR *)pRVar1)->SR0 = 0x100;
  return;
}



uint8_t RFHAL_TxStart(uint8_t channel,RAIL_TxOptions_t *options,RAIL_PreTxOp_t *preTxOp,
                     void *preTxOpParams)

{
  bool bVar1;
  byte bVar2;
  
  if ((options != (RAIL_TxOptions_t *)0x0) && (bVar1 = RFHAL_AutoAckIsEnabled(), bVar1 != false)) {
    RFHAL_AutoAckWaitForAck((bool)options->waitForAck);
  }
  if (preTxOp == FUN_00000000) {
    GENERIC_PHY_PacketTx();
  }
  else {
    bVar2 = (*preTxOp)(preTxOpParams);
    preTxOp = (RAIL_PreTxOp_t *)(uint)bVar2;
    if (preTxOp != FUN_00000000) {
      BUS_RegMaskedClear(&RAC->SR0,0x100);
      return (uint8_t)bVar2;
    }
  }
  return (uint8_t)preTxOp;
}



uint16_t RFHAL_WriteTxFifo(uint8_t *dataPtr,uint16_t writeLength)

{
  uint16_t uVar1;
  
  uVar1 = BUFC_GetSpaceAvailable(0);
  if (uVar1 <= writeLength) {
    writeLength = BUFC_GetSpaceAvailable(0);
  }
  BUFC_WriteBuffer(0,dataPtr,writeLength);
  return writeLength;
}



uint16_t RFHAL_ReadRxFifo(uint8_t *dataPtr,uint16_t readLength)

{
  uint16_t uVar1;
  
  uVar1 = BUFC_GetBytesAvailable(1);
  if (uVar1 <= readLength) {
    readLength = BUFC_GetBytesAvailable(1);
  }
  BUFC_ReadBuffer(1,dataPtr,readLength);
  return readLength;
}



void RFHAL_ReadRxFifoAppendedInfo(RAIL_AppendedInfo_t *appendedInfo)

{
  uint uVar1;
  uint32_t uVar2;
  uint64_t uVar3;
  undefined auStack28 [5];
  int8_t local_17;
  byte local_16;
  uint32_t local_10;
  
  uVar2 = RADIO_RxTrailDataLength();
  GENERIC_PHY_PacketRxAppendedInfoHelper(uVar2,auStack28);
  read_volatile(FRC->IEN._0_1_);
  uVar1 = (FRC->IF);
  *(byte *)&appendedInfo->field_0x4 =
       *(byte *)&appendedInfo->field_0x4 & 0xfd | (byte)((((uVar1 ^ 0x80) << 0x18) >> 0x1f) << 1);
  write_volatile_4(FRC->IFC,0x80);
  if (local_16 != 0) {
    local_16 = 1;
  }
  appendedInfo->rssiLatch = local_17;
  *(byte *)&appendedInfo->field_0x4 = *(byte *)&appendedInfo->field_0x4 & 0xfe | local_16 & 1;
  uVar3 = TIMING_GetRxTimestampUs(local_10);
  appendedInfo->timeUs = (uint32_t)uVar3;
  appendedInfo->syncWordId = '\0';
  return;
}



uint16_t RFHAL_SetRxFifoThreshold(uint16_t threshold)

{
  uint uVar1;
  
  uVar1 = (BUFC->BUF1_THRESHOLDCTRL);
  if (threshold < 0x201) {
    uVar1 = (uint)threshold | uVar1 & 0xfffff000;
  }
  else {
    uVar1 = uVar1 & 0xfffff000 | 0x200;
  }
  write_volatile_4(BUFC->BUF1_THRESHOLDCTRL,uVar1);
  uVar1 = (BUFC->BUF1_THRESHOLDCTRL);
  return (uint16_t)((uVar1 << 0x14) >> 0x14);
}



uint16_t RFHAL_GetTxFifoThreshold(void)

{
  uint uVar1;
  
  uVar1 = (BUFC->BUF0_THRESHOLDCTRL);
  return (uint16_t)((ushort)((uVar1 << 0x14) >> 0x14) + 1);
}



uint16_t RFHAL_SetTxFifoThreshold(uint16_t threshold)

{
  uint uVar1;
  uint16_t uVar2;
  
  uVar1 = (BUFC->BUF0_THRESHOLDCTRL);
  if (0x1ff < threshold) {
    threshold = 0x200;
  }
  write_volatile_4(BUFC->BUF0_THRESHOLDCTRL,
                   uVar1 & 0xfffff000 | (uint)(ushort)(threshold - 1));
  uVar2 = RFHAL_GetTxFifoThreshold();
  return uVar2;
}



uint16_t RFHAL_GetRxFifoThreshold(void)

{
  uint uVar1;
  
  uVar1 = (BUFC->BUF1_THRESHOLDCTRL);
  return (uint16_t)((uVar1 << 0x14) >> 0x14);
}



uint16_t RFHAL_GetTxFifoSpaceAvailable(void)

{
  uint16_t uVar1;
  
  uVar1 = BUFC_GetSpaceAvailable(0);
  return uVar1;
}



uint16_t RFHAL_GetRxFifoBytesAvailable(void)

{
  uint16_t uVar1;
  
  uVar1 = BUFC_GetBytesAvailable(1);
  return (uint16_t)uVar1;
}



void RFHAL_ResetTxFifo(void)

{
  BUS_RegMaskedClear(&BUFC->IEN,4);
  write_volatile_4(BUFC->BUF0_CMD,1);
  BUS_RegMaskedClear(&BUFC->BUF0_THRESHOLDCTRL,0x2000);
  BUS_RegMaskedSet(&BUFC->IEN,4);
  return;
}



void RFHAL_ResetRxFifo(void)

{
  BUS_RegMaskedClear(&BUFC->IEN,0x400);
  write_volatile_4(BUFC->BUF1_CMD,1);
  BUS_RegMaskedClear(&BUFC->BUF1_THRESHOLDCTRL,0x2000);
  BUS_RegMaskedSet(&BUFC->IEN,0x400);
  return;
}



RAIL_Status_t RFHAL_DataConfig(RAIL_DataConfig_t *dataConfig)

{
  if (dataConfig->txMethod == dataConfig->rxMethod) {
    if (dataConfig->rxSource == RX_PACKET_DATA) {
      RFHAL_DisableRxRawCapture();
    }
    else {
      RFHAL_EnableRxRawCapture();
    }
    if (dataConfig->txMethod == PACKET_MODE) {
      bufcEnabledCallbacks =
           bufcEnabledCallbacks & 0xffffff00 | (uint)((byte)bufcEnabledCallbacks & 0xfe);
    }
    else {
      bufcEnabledCallbacks =
           bufcEnabledCallbacks & 0xffffff00 | (uint)((byte)bufcEnabledCallbacks | 1);
      RFHAL_ResetTxFifo();
    }
    if (dataConfig->rxMethod == PACKET_MODE) {
      bufcEnabledCallbacks =
           bufcEnabledCallbacks & 0xffffff00 | (uint)((byte)bufcEnabledCallbacks & 0xfb);
      BUS_RegMaskedSet(&FRC->RXCTRL,0x60);
      BUS_RegMaskedClear(&RAC->SR0,0x40);
      BUS_RegMaskedClear(&FRC->RXCTRL,2);
    }
    else {
      bufcEnabledCallbacks = bufcEnabledCallbacks | 4;
      BUS_RegMaskedClear(&FRC->RXCTRL,0x60);
      RFHAL_ResetRxFifo();
      BUS_RegMaskedSet(&RAC->SR0,0x40);
      BUS_RegMaskedSet(&FRC->RXCTRL,2);
    }
    BUFC_ConfigureCallbacks(bufcEnabledCallbacks);
    return RAIL_STATUS_NO_ERROR;
  }
  return RAIL_STATUS_INVALID_PARAMETER;
}



uint16_t RFHAL_SetFixedLength(uint16_t length)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)length;
  uVar1 = (FRC->DFLCTRL);
  if (((uVar1 & 7) != 0) && ((uVar1 & 7) != 5)) {
    return 0xffff;
  }
  if (uVar2 == 0) {
    uVar1 = (FRC->DFLCTRL);
    write_volatile_4(FRC->DFLCTRL,uVar1 & 0xfffffff8 | 5);
    return length;
  }
  BUS_RegMaskedClear(&FRC->DFLCTRL,7);
  if (0xfff < uVar2) {
    uVar2 = 0x1000;
  }
  write_volatile_4(FRC->WCNTCMP0,uVar2 - 1);
  return (uint16_t)uVar2;
}



uint8_t RAIL_RfInit(RAIL_Init_t *railInit)

{
  RAIL_Status_t RVar1;
  RAIL_DataConfig_t local_c;
  
  RAILINT_CalibrationEnable(railInit->calEnable & 0x10001);
  RVar1 = RFHAL_Init(railInit);
  if (RVar1 == RAIL_STATUS_NO_ERROR) {
    local_c = (RAIL_DataConfig_t)0x0;
    RVar1 = RAIL_DataConfig(&local_c);
  }
  return (uint8_t)RVar1;
}



RAIL_Status_t RAIL_SetPtiProtocol(RAIL_PtiProtocol_t protocol)

{
  RAIL_RadioState_t RVar1;
  RAIL_Status_t RVar2;
  
  RVar1 = RFHAL_StateGet();
  if (RVar1 == RAIL_RF_STATE_IDLE) {
    RVar2 = RFHAL_SetPtiProtocol(protocol);
    return RVar2;
  }
  return RAIL_STATUS_INVALID_STATE;
}



void RAIL_RfIdle(void)

{
  RFHAL_IdleExt(1);
  return;
}



void RAIL_RfIdleExt(undefined4 mode,bool wait)

{
  RAIL_RadioState_t RVar1;
  
  RFHAL_IdleExt(mode);
  if (wait != false) {
    do {
      RVar1 = RFHAL_StateGet();
    } while (RVar1 != RAIL_RF_STATE_IDLE);
  }
  return;
}



RAIL_RadioState_t RAIL_RfStateGet(void)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = (RAC->STATUS);
  uVar1 = uVar1 & 0xf000000;
  if (uVar1 != 0x7000000) {
    if (0x7000000 < uVar1) {
      if (uVar1 != 0xa000000) {
        if (uVar1 < 0xa000001) {
          if (uVar1 == 0x8000000) {
            return RAIL_RF_STATE_TX;
          }
          bVar2 = uVar1 == 0x9000000;
        }
        else {
          if (uVar1 == 0xb000000) {
            return RAIL_RF_STATE_TX;
          }
          bVar2 = uVar1 == 0xc000000;
        }
        if (!bVar2) {
          return RAIL_RF_STATE_IDLE;
        }
      }
      return RAIL_RF_STATE_TX;
    }
    if (uVar1 != 0x3000000) {
      if (uVar1 < 0x3000001) {
        if (uVar1 == 0x1000000) {
          return RAIL_RF_STATE_RX;
        }
        bVar2 = uVar1 == 0x2000000;
      }
      else {
        if (uVar1 == 0x4000000) {
          return RAIL_RF_STATE_RX;
        }
        bVar2 = uVar1 == 0x5000000;
      }
      if (!bVar2) {
        return RAIL_RF_STATE_IDLE;
      }
    }
  }
  return RAIL_RF_STATE_RX;
}



RAIL_Status_t RAIL_ChannelExists(uint8_t channel)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = 0;
  while( true ) {
    if ((uint)channelConfig[1] <= (uint)bVar1) {
      return RAIL_STATUS_INVALID_PARAMETER;
    }
    iVar2 = (uint)bVar1 * 0xc;
    if ((*(ushort *)(*channelConfig + iVar2) <= (ushort)channel) &&
       ((ushort)channel <= *(ushort *)(*channelConfig + iVar2 + 2))) break;
    bVar1 = bVar1 + 1;
  }
  return RAIL_STATUS_NO_ERROR;
}



void RAILInt_TrackChannelConfig(RAIL_ChannelConfig_t *config)

{
  channelConfig = config;
  return;
}



uint8_t RAILInt_SetChannel(uint8_t channel)

{
  int iVar1;
  ushort *puVar2;
  ushort *puVar3;
  
  if (((channelConfig != (ushort **)0x0) && (puVar3 = *channelConfig, puVar3 != (ushort *)0x0)) &&
     (channelConfig[1] != (ushort *)0x0)) {
    puVar2 = (ushort *)0x0;
    do {
      if ((*puVar3 <= (ushort)channel) && ((ushort)channel <= puVar3[1])) {
        if ((currentEntry == puVar3) && (currentChannel == channel)) {
          return '\0';
        }
        iVar1 = (int)currentEntry - (int)puVar3;
        if (iVar1 != 0) {
          iVar1 = 1;
        }
        iVar1 = RFHAL_SetChannel(channel,puVar3,iVar1);
        if (iVar1 == 0) {
          currentChannel = channel;
          currentEntry = puVar3;
          return (uint8_t)iVar1;
        }
        return (uint8_t)iVar1;
      }
      puVar2 = (ushort *)((int)puVar2 + 1);
      puVar3 = puVar3 + 6;
    } while (puVar2 != channelConfig[1]);
  }
  return '\x01';
}



uint8_t RAILInt_GetChannel(void)

{
  return currentChannel;
}



void RAIL_VersionGet(RAIL_Version_t *version,bool verbose)

{
  version->major = '\x01';
  version->minor = '\x05';
  version->rev = '\x02';
  if (verbose != false) {
    version->build = '\x02';
    version->hash = 0xa397d602;
    version->flags = '\0';
    return;
  }
  version->build = '\0';
  version->hash = 0;
  version->flags = '\0';
  return;
}



RAIL_Status_t RAIL_DebugModeSet(uint32_t debugMode)

{
  if (RAIL_DebugMode == 1) {
    currentEntry = 0;
  }
  RAIL_DebugMode = debugMode;
  return RAIL_STATUS_NO_ERROR;
}



uint32_t RAIL_DebugModeGet(void)

{
  return RAIL_DebugMode;
}



RAIL_Status_t RAIL_SetTxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error)

{
  RAIL_RadioState_t RVar1;
  RAIL_Status_t RVar2;
  
  if ((success == RAIL_RF_STATE_TX) || (error == RAIL_RF_STATE_TX)) {
    RVar1 = RAIL_RF_STATE_RX;
  }
  else {
    RVar1 = RFHAL_StateGet();
    if (RVar1 != RAIL_RF_STATE_TX) {
      RVar2 = RFHAL_SetTxTransitions(success,error);
      return RVar2;
    }
  }
  return (RAIL_Status_t)RVar1;
}



RAIL_Status_t
RAIL_SetRxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error,uint8_t ignoreErrors)

{
  RAIL_RadioState_t RVar1;
  RAIL_Status_t RVar2;
  
  if (error == RAIL_RF_STATE_TX) {
    return RAIL_STATUS_INVALID_PARAMETER;
  }
  RVar1 = RFHAL_StateGet();
  if (RVar1 == RAIL_RF_STATE_RX) {
    RVar2 = RAIL_STATUS_INVALID_STATE;
  }
  else {
    RVar2 = RFHAL_SetRxTransitions(success,error);
    if (RVar2 == RAIL_STATUS_NO_ERROR) {
      RVar2 = RFHAL_ErrorConfig(ignoreErrors);
      return RVar2;
    }
  }
  return RVar2;
}



uint16_t RAIL_SetFixedLength(uint16_t length)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)length;
  uVar1 = (FRC->DFLCTRL);
  if (((uVar1 & 7) != 0) && ((uVar1 & 7) != 5)) {
    return 0xffff;
  }
  if (uVar2 == 0) {
    uVar1 = (FRC->DFLCTRL);
    write_volatile_4(FRC->DFLCTRL,uVar1 & 0xfffffff8 | 5);
    return length;
  }
  BUS_RegMaskedClear(&FRC->DFLCTRL,7);
  if (0xfff < uVar2) {
    uVar2 = 0x1000;
  }
  write_volatile_4(FRC->WCNTCMP0,uVar2 - 1);
  return (uint16_t)uVar2;
}



uint8_t RAIL_RxConfig(uint32_t cbToEnable,bool appendedInfoEnable)

{
  uint8_t uVar1;
  
  if (appendedInfoEnable == false) {
    RFHAL_DisableRxAppendedInfo();
  }
  else {
    RFHAL_EnableRxAppendedInfo();
  }
  uVar1 = RFHAL_RxIntEnable(cbToEnable);
  return uVar1;
}



RAIL_Status_t RAIL_SetRxOptions(uint32_t options)

{
  uint uVar1;
  RAIL_Status_t RVar2;
  
  uVar1 = (RAC->STATUS);
  if ((uVar1 << 4) >> 0x1c == 3) {
    return RAIL_STATUS_INVALID_STATE;
  }
  RVar2 = (RAIL_Status_t)(options & 1);
  if ((options & 1) == 0) {
    BUS_RegMaskedClear(&FRC->RXCTRL,1);
  }
  else {
    RVar2 = RAIL_STATUS_NO_ERROR;
    BUS_RegMaskedSet(&FRC->RXCTRL,1);
  }
  return RVar2;
}



uint8_t RAIL_RxStart(uint8_t channel)

{
  uint8_t uVar1;
  
  uVar1 = RAILInt_SetChannel(channel);
  if (uVar1 == '\0') {
    uVar1 = RFHAL_RxStart(channel);
    return uVar1;
  }
  return uVar1;
}



uint8_t RAIL_ScheduleRx(uint8_t channel,RAIL_ScheduleRxConfig_t *cfg)

{
  RAIL_RadioState_t RVar1;
  uint8_t uVar2;
  
  RVar1 = RAIL_RfStateGet();
  if (RVar1 == RAIL_RF_STATE_IDLE) {
    uVar2 = RAILInt_SetChannel(channel);
    if (uVar2 == '\0') {
      RFHAL_ScheduleRx(channel,cfg);
      return channel;
    }
  }
  else {
    uVar2 = '\x02';
  }
  return uVar2;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

RAIL_Status_t RAIL_TxConfig(uint32_t cbToEnable)

{
  _enabledCallbacks =
       CONCAT12(DAT_20002dfa & 0x7f | 0x40 | (byte)(((cbToEnable << 0x19) >> 0x1f) << 7),
                _enabledCallbacks);
  _enabledCallbacks =
       _enabledCallbacks & 0xffffff00 |
       (uint)(byte)((byte)(_enabledCallbacks >> 0x18) & 0xfe | (byte)cbToEnable >> 7) << 0x18 |
       (uint)(byte)(enabledCallbacks & 0xfd | ((cbToEnable & 0x1b) != 0) << 1);
  bufcEnabledCallbacks =
       bufcEnabledCallbacks & 0xffffff00 |
       (uint)((byte)bufcEnabledCallbacks & 0xfd | (byte)(cbToEnable << 1) & 2);
  txConfigEvents = cbToEnable;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  BUFC_ConfigureCallbacks(bufcEnabledCallbacks);
  return RAIL_STATUS_NO_ERROR;
}



uint8_t RAIL_TxStartWithOptions
                  (uint8_t channel,RAIL_TxOptions_t *options,RAIL_PreTxOp_t *preTxOp,
                  void *preTxOpParams)

{
  bool bVar1;
  uint8_t uVar2;
  
  bVar1 = RFHAL_OkToTransmit();
  if (bVar1 == false) {
    uVar2 = '\x02';
  }
  else {
    uVar2 = RAILInt_SetChannel(channel);
    if (uVar2 == '\0') {
      uVar2 = RFHAL_TxStart(channel,options,preTxOp,preTxOpParams);
      return uVar2;
    }
  }
  return uVar2;
}



uint8_t RAIL_TxStart(uint8_t channel,RAIL_PreTxOp_t *preTxOp,void *preTxOpParams)

{
  uint8_t uVar1;
  
  uVar1 = RAIL_TxStartWithOptions(channel,(RAIL_TxOptions_t *)0x0,preTxOp,preTxOpParams);
  return uVar1;
}



uint8_t RAIL_TxToneStart(uint8_t channel)

{
  uint8_t uVar1;
  
  uVar1 = RAILInt_SetChannel(channel);
  if (uVar1 == '\0') {
    RFHAL_StartCWTestMode();
  }
  return uVar1;
}



uint8_t RAIL_TxToneStop(void)

{
  RFHAL_StopTestMode();
  return '\0';
}



uint8_t RAIL_TxStreamStart(uint8_t channel,int mode)

{
  uint8_t uVar1;
  
  if (mode == 1) {
    uVar1 = RAILInt_SetChannel(channel);
    if (uVar1 == '\0') {
      RFHAL_StartStreamTestMode();
    }
    return uVar1;
  }
  return '\x01';
}



uint8_t RAIL_TxStreamStop(void)

{
  RFHAL_StopTestMode();
  return '\0';
}



int32_t RAIL_TxPowerSet(int32_t powerLevel)

{
  code *pcVar1;
  uint8_t uVar2;
  int32_t iVar3;
  
  iVar3 = PA_OutputPowerSet(powerLevel);
  pcVar1 = protChChngCB;
  if (protChChngCB != FUN_00000000) {
    uVar2 = RAILInt_GetChannel();
    (*pcVar1)(uVar2,1);
  }
  return iVar3;
}



int32_t RAIL_TxPowerGet(void)

{
  return (int)gPaConfig.power;
}



void RAILINT_CalibrationEnable(RAIL_CalMask_t cbtoenable)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  RAIL_CalPend = 0;
  RAIL_CalEnable = cbtoenable;
  CORE_ExitCritical(irqState);
  return;
}



void RAILINT_CalibrationPend(RAIL_CalMask_t calpend)

{
  CORE_irqState_t irqState;
  uint uVar1;
  
  irqState = CORE_EnterCritical();
  uVar1 = calpend & RAIL_CalEnable;
  RAIL_CalPend = RAIL_CalPend | uVar1;
  CORE_ExitCritical(irqState);
  if (uVar1 != 0) {
    RAILCb_CalNeeded();
    return;
  }
  return;
}



RAIL_CalMask_t RAILINT_CalibrationClear(RAIL_CalMask_t caltoclear)

{
  CORE_irqState_t irqState;
  uint uVar1;
  
  irqState = CORE_EnterCritical();
  uVar1 = RAIL_CalPend & ~(caltoclear & RAIL_CalEnable);
  RAIL_CalPend = uVar1;
  CORE_ExitCritical(irqState);
  return uVar1;
}



RAIL_CalMask_t RAILINT_CalibrationEnableGet(void)

{
  return RAIL_CalEnable;
}



RAIL_CalMask_t RAIL_CalPendingGet(void)

{
  RAIL_CalMask_t RVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  RVar1 = RAIL_CalPend;
  CORE_ExitCritical(irqState);
  return RVar1;
}



void RAIL_CalStart(undefined4 *calValues,RAIL_CalMask_t calForce,RAIL_CalMask_t calSave)

{
  int local_14;
  
  if (calValues == (undefined4 *)0x0) {
    local_14 = -1;
  }
  else {
    local_14 = *calValues;
  }
  if (calForce == 0) {
    calForce = RAIL_CalPendingGet();
  }
  RAILINT_CalibrationClear(calForce);
  RFHAL_CalibrationRun(&local_14,calForce);
  if ((calSave != 0) && (calValues != (undefined4 *)0x0)) {
    *calValues = local_14;
  }
  return;
}



uint8_t RAIL_CalInit(RAIL_CalInit_t *railCalInit)

{
  uint8_t uVar1;
  
  uVar1 = RFHAL_CalibrationInit(railCalInit);
  RAILINT_CalibrationEnable(railCalInit->calEnable & 0x10001);
  return uVar1;
}



RAIL_Status_t RAIL_AutoAckDisable(void)

{
  RAIL_Status_t RVar1;
  RAIL_Status_t RVar2;
  
  RVar1 = RAIL_SetRxTransitions(RAIL_RF_STATE_IDLE,RAIL_RF_STATE_IDLE,'\0');
  RVar2 = RAIL_SetTxTransitions(RAIL_RF_STATE_IDLE,RAIL_RF_STATE_IDLE);
  if ((RVar2 == RAIL_STATUS_NO_ERROR) && (RVar1 == RAIL_STATUS_NO_ERROR)) {
    RFHAL_AutoAckRxResume();
    RFHAL_AutoAckTxResume();
    RFHAL_AutoAckDisable();
    return RAIL_STATUS_NO_ERROR;
  }
  return RAIL_STATUS_INVALID_PARAMETER;
}



bool RAIL_AutoAckIsEnabled(void)

{
  uint uVar1;
  
  uVar1 = (SEQ->REG000);
  return SUB41((uVar1 << 0x1a) >> 0x1f,0);
}



RAIL_Status_t RAIL_AutoAckConfig(RAIL_AutoAckConfig_t *config)

{
  RAIL_Status_t RVar1;
  RAIL_AutoAckConfig_t *local_18;
  undefined4 local_14;
  
  local_18 = config;
  RVar1 = RAIL_SetRxTransitions(RAIL_RF_STATE_TX,config->defaultState,'\0');
  if ((RVar1 == RAIL_STATUS_NO_ERROR) &&
     (RVar1 = RAIL_SetTxTransitions(RAIL_RF_STATE_RX,config->defaultState),
     RVar1 == RAIL_STATUS_NO_ERROR)) {
    local_14 = *(undefined4 *)&config->idleTiming;
    local_18 = (RAIL_AutoAckConfig_t *)CONCAT22(config->turnaroundTime - 10,config->idleTiming);
    RAIL_SetStateTiming((RAIL_StateTiming_t *)&local_18);
    RFHAL_AutoAckConfig(config);
    RFHAL_AutoAckEnable();
  }
  else {
    RVar1 = RAIL_STATUS_INVALID_PARAMETER;
  }
  return RVar1;
}



RAIL_Status_t RAIL_AutoAckLoadBuffer(RAIL_AutoAckData_t *ackData)

{
  RAIL_Status_t RVar1;
  
  if (ackData->dataLength < 0x41) {
    RVar1 = RFHAL_AutoAckLoadBuffer(ackData);
    return RVar1;
  }
  return RAIL_STATUS_INVALID_PARAMETER;
}



void RAIL_AutoAckRxPause(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 | 8);
  CORE_ExitCritical(irqState);
  return;
}



void RAIL_AutoAckRxResume(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 & 0xfffffff7);
  CORE_ExitCritical(irqState);
  return;
}



bool RAIL_AutoAckRxIsPaused(void)

{
  uint uVar1;
  
  uVar1 = (SEQ->REG000);
  return SUB41((uVar1 << 0x1c) >> 0x1f,0);
}



void RAIL_AutoAckTxPause(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 | 0x100);
  CORE_ExitCritical(irqState);
  return;
}



void RAIL_AutoAckTxResume(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 & 0xfffffeff);
  CORE_ExitCritical(irqState);
  return;
}



bool RAIL_AutoAckTxIsPaused(void)

{
  uint uVar1;
  
  uVar1 = (SEQ->REG000);
  return SUB41((uVar1 << 0x17) >> 0x1f,0);
}



bool RAIL_AutoAckUseTxBuffer(void)

{
  CORE_irqState_t irqState;
  uint uVar1;
  bool bVar2;
  
  irqState = CORE_EnterCritical();
  uVar1 = GENERIC_PHY_CanModifyAck();
  if (uVar1 != 0) {
    BUS_RegMaskedSet(&RAC->SR0,2);
    uVar1 = (RAC->SR0);
    bVar2 = -1 < (int)(uVar1 << 0xe);
    if (bVar2) {
      BUS_RegMaskedSet(&RAC->SR2,0x40);
    }
    uVar1 = (uint)bVar2;
    BUS_RegMaskedClear(&RAC->SR0,2);
  }
  CORE_ExitCritical(irqState);
  return SUB41(uVar1,0);
}



bool RAIL_AutoAckCancelAck(void)

{
  CORE_irqState_t irqState;
  uint uVar1;
  bool bVar2;
  
  irqState = CORE_EnterCritical();
  uVar1 = GENERIC_PHY_CanModifyAck();
  if (uVar1 != 0) {
    BUS_RegMaskedSet(&RAC->SR0,2);
    uVar1 = (RAC->SR0);
    bVar2 = -1 < (int)(uVar1 << 0xe);
    if (bVar2) {
      BUS_RegMaskedSet(&RAC->SR2,0x20);
    }
    uVar1 = (uint)bVar2;
    BUS_RegMaskedClear(&RAC->SR0,2);
  }
  CORE_ExitCritical(irqState);
  return SUB41(uVar1,0);
}



uint8_t RAIL_TxDataLoad(RAIL_TxData_t *txData)

{
  CORE_irqState_t irqState;
  uint uVar1;
  uint8_t uVar2;
  
  irqState = CORE_EnterCritical();
  uVar1 = (RAC->STATUS);
  uVar1 = (uVar1 << 4) >> 0x1c;
  if (((uVar1 - 7 < 3) || (uVar1 == 0xc)) &&
     (uVar1 = (RAC->SR0), (int)(uVar1 << 0xf) < 0)) {
    uVar2 = '\x03';
  }
  else {
    write_volatile_4(BUFC->BUF0_CMD,1);
    BUFC_WriteBuffer(0,txData->dataPtr,txData->dataLength);
    uVar2 = '\0';
  }
  CORE_ExitCritical(irqState);
  return uVar2;
}



RAIL_Status_t RAIL_DataConfig(RAIL_DataConfig_t *dataConfig)

{
  if (dataConfig->txMethod == dataConfig->rxMethod) {
    if (dataConfig->rxSource == RX_PACKET_DATA) {
      RFHAL_DisableRxRawCapture();
    }
    else {
      RFHAL_EnableRxRawCapture();
    }
    if (dataConfig->txMethod == PACKET_MODE) {
      bufcEnabledCallbacks =
           bufcEnabledCallbacks & 0xffffff00 | (uint)((byte)bufcEnabledCallbacks & 0xfe);
    }
    else {
      bufcEnabledCallbacks =
           bufcEnabledCallbacks & 0xffffff00 | (uint)((byte)bufcEnabledCallbacks | 1);
      RFHAL_ResetTxFifo();
    }
    if (dataConfig->rxMethod == PACKET_MODE) {
      bufcEnabledCallbacks =
           bufcEnabledCallbacks & 0xffffff00 | (uint)((byte)bufcEnabledCallbacks & 0xfb);
      BUS_RegMaskedSet(&FRC->RXCTRL,0x60);
      BUS_RegMaskedClear(&RAC->SR0,0x40);
      BUS_RegMaskedClear(&FRC->RXCTRL,2);
    }
    else {
      bufcEnabledCallbacks = bufcEnabledCallbacks | 4;
      BUS_RegMaskedClear(&FRC->RXCTRL,0x60);
      RFHAL_ResetRxFifo();
      BUS_RegMaskedSet(&RAC->SR0,0x40);
      BUS_RegMaskedSet(&FRC->RXCTRL,2);
    }
    BUFC_ConfigureCallbacks(bufcEnabledCallbacks);
    return RAIL_STATUS_NO_ERROR;
  }
  return RAIL_STATUS_INVALID_PARAMETER;
}



uint16_t RAIL_WriteTxFifo(uint8_t *dataPtr,uint16_t writeLength)

{
  uint16_t uVar1;
  
  uVar1 = BUFC_GetSpaceAvailable(0);
  if (uVar1 <= writeLength) {
    writeLength = BUFC_GetSpaceAvailable(0);
  }
  BUFC_WriteBuffer(0,dataPtr,writeLength);
  return writeLength;
}



uint16_t RAIL_ReadRxFifo(uint8_t *dataPtr,uint16_t readLength)

{
  uint16_t uVar1;
  
  uVar1 = BUFC_GetBytesAvailable(1);
  if (uVar1 <= readLength) {
    readLength = BUFC_GetBytesAvailable(1);
  }
  BUFC_ReadBuffer(1,dataPtr,readLength);
  return readLength;
}



void RAIL_ReadRxFifoAppendedInfo(RAIL_AppendedInfo_t *appendedInfo)

{
  uint uVar1;
  uint32_t uVar2;
  uint64_t uVar3;
  undefined auStack28 [5];
  int8_t iStack23;
  byte bStack22;
  uint32_t uStack16;
  
  uVar2 = RADIO_RxTrailDataLength();
  GENERIC_PHY_PacketRxAppendedInfoHelper(uVar2,auStack28);
  read_volatile(FRC->IEN._0_1_);
  uVar1 = (FRC->IF);
  *(byte *)&appendedInfo->field_0x4 =
       *(byte *)&appendedInfo->field_0x4 & 0xfd | (byte)((((uVar1 ^ 0x80) << 0x18) >> 0x1f) << 1);
  write_volatile_4(FRC->IFC,0x80);
  if (bStack22 != 0) {
    bStack22 = 1;
  }
  appendedInfo->rssiLatch = iStack23;
  *(byte *)&appendedInfo->field_0x4 = *(byte *)&appendedInfo->field_0x4 & 0xfe | bStack22 & 1;
  uVar3 = TIMING_GetRxTimestampUs(uStack16);
  appendedInfo->timeUs = (uint32_t)uVar3;
  appendedInfo->syncWordId = '\0';
  return;
}



uint16_t RAIL_SetTxFifoThreshold(uint16_t txThreshold)

{
  uint16_t uVar1;
  
  if (txThreshold != 0) {
    uVar1 = RFHAL_SetTxFifoThreshold(txThreshold);
    return uVar1;
  }
  uVar1 = RFHAL_GetTxFifoThreshold();
  return uVar1;
}



uint16_t RAIL_SetRxFifoThreshold(uint16_t rxThreshold)

{
  uint16_t uVar1;
  
  if (rxThreshold != 0xffff) {
    uVar1 = RFHAL_SetRxFifoThreshold(rxThreshold);
    return uVar1;
  }
  uVar1 = RFHAL_GetRxFifoThreshold();
  return uVar1;
}



uint16_t RAIL_GetTxFifoThreshold(void)

{
  uint uVar1;
  
  uVar1 = (BUFC->BUF0_THRESHOLDCTRL);
  return (uint16_t)((ushort)((uVar1 << 0x14) >> 0x14) + 1);
}



uint16_t RAIL_GetRxFifoThreshold(void)

{
  uint uVar1;
  
  uVar1 = (BUFC->BUF1_THRESHOLDCTRL);
  return (uint16_t)((uVar1 << 0x14) >> 0x14);
}



uint16_t RAIL_GetTxFifoSpaceAvailable(void)

{
  uint16_t uVar1;
  
  uVar1 = BUFC_GetSpaceAvailable(0);
  return uVar1;
}



uint16_t RAIL_GetRxFifoBytesAvailable(void)

{
  uint16_t uVar1;
  
  uVar1 = BUFC_GetBytesAvailable(1);
  return (uint16_t)uVar1;
}



void RAIL_ResetFifo(bool txFifo,bool rxFifo)

{
  if (txFifo != false) {
    RFHAL_ResetTxFifo();
  }
  if (rxFifo != false) {
    RFHAL_ResetRxFifo();
    return;
  }
  return;
}



RAIL_Status_t RAIL_IEEE802154_2p4GHzRadioConfig(void)

{
  RAIL_Status_t RVar1;
  
  RAIL_ChannelConfig((RAIL_ChannelConfig_t *)&channels);
  RVar1 = RFHAL_IEEE802154RadioConfig2p4GHz();
  return RVar1;
}



bool RAIL_IEEE802154_SetAddresses(RAIL_IEEE802154_AddrConfig_t *addresses)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  
  if (addresses != (RAIL_IEEE802154_AddrConfig_t *)0x0) {
    bVar1 = RFHAL_IEEE802154SetPanId(addresses->panId);
    bVar2 = RFHAL_IEEE802154SetShortAddress(addresses->shortAddr);
    bVar3 = RFHAL_IEEE802154SetLongAddress(addresses->longAddr);
    return (bool)(bVar3 | bVar2 | bVar1);
  }
  return false;
}



bool RAIL_IEEE802154_SetPanId(uint16_t panId)

{
  undefined uVar1;
  uint in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  uint auStack12 [3];
  
  auStack12[0] = in_r1 & 0xffff0000 | (uint)panId;
  uVar1 = GENERIC_PHY_SetIeeePanId(1,auStack12,in_r2,in_r3,panId);
  return (bool)uVar1;
}



bool RAIL_IEEE802154_SetShortAddress(uint16_t shortAddr)

{
  bool bVar1;
  
  bVar1 = GENERIC_PHY_SetIeeeShortAddress(1);
  return bVar1;
}



bool RAIL_IEEE802154_SetLongAddress(uint8_t *longAddr)

{
  bool bVar1;
  
  bVar1 = GENERIC_PHY_SetIeeeLongAddress(1,longAddr);
  return bVar1;
}



RAIL_Status_t RAIL_IEEE802154_SetPanCoordinator(bool isPanCoordinator)

{
  bool bVar1;
  RAIL_Status_t RVar2;
  
  bVar1 = RFHAL_IEEE802154IsEnabled();
  if (bVar1 != false) {
    RVar2 = RFHAL_IEEE802154SetPanCoordinator(isPanCoordinator);
    return RVar2;
  }
  return RAIL_STATUS_INVALID_STATE;
}



RAIL_Status_t RAIL_IEEE802154_SetPromiscuousMode(bool enable)

{
  bool bVar1;
  RAIL_Status_t RVar2;
  
  bVar1 = RFHAL_IEEE802154IsEnabled();
  if (bVar1 != false) {
    RVar2 = RFHAL_IEEE802154SetPromiscuousMode(enable);
    return RVar2;
  }
  return RAIL_STATUS_INVALID_STATE;
}



RAIL_Status_t RAIL_IEEE802154_AcceptFrames(uint8_t framesMask)

{
  bool bVar1;
  RAIL_Status_t RVar2;
  
  bVar1 = RFHAL_IEEE802154IsEnabled();
  if (bVar1 != false) {
    RVar2 = RFHAL_IEEE802154AcceptFrames(framesMask);
    return RVar2;
  }
  return RAIL_STATUS_INVALID_STATE;
}



RAIL_Status_t RAIL_IEEE802154_Init(RAIL_IEEE802154_Config_t *config)

{
  RAIL_Status_t RVar1;
  bool bVar2;
  int iVar3;
  uint8_t local_30;
  undefined local_2f;
  undefined2 local_2c [2];
  RAIL_AutoAckConfig_t local_28;
  RAIL_AddrConfig_t local_20;
  
  local_20.offsets = &local_30;
  RFHAL_IEEE802154Enable();
  RAIL_IEEE802154_SetPanCoordinator((bool)config->isPanCoordinator);
  RAIL_IEEE802154_SetPromiscuousMode((bool)config->promiscuousMode);
  RAIL_IEEE802154_AcceptFrames(config->framesMask);
  local_28.defaultState = config->defaultState;
  local_28.idleTiming = config->idleTime;
  local_28.turnaroundTime = config->turnaroundTime;
  local_28.ackTimeout = config->ackTimeout;
  RVar1 = RAIL_AutoAckConfig(&local_28);
  if (RVar1 == RAIL_STATUS_NO_ERROR) {
    RVar1 = RFHAL_IEEE802154LoadAck();
  }
  RAIL_AddressFilterReset();
  local_2c[0] = 0x802;
  local_20.numFields = '\x02';
  local_20.sizes = (uint8_t *)local_2c;
  local_30 = '\0';
  local_2f = 0;
  local_20.matchTable = 0;
  bVar2 = RAIL_AddressFilterConfig(&local_20);
  iVar3 = RFHAL_IEEE802154SetBroadcastAddresses();
  if ((iVar3 == 0) || (bVar2 == false)) {
    RVar1 = RAIL_STATUS_INVALID_PARAMETER;
  }
  RAIL_AddressFilterEnable();
  RAIL_IEEE802154_SetAddresses(config->addresses);
  return RVar1;
}



RAIL_Status_t RAIL_IEEE802154_SetFramePending(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = GENERIC_PHY_CanModifyAck();
  uVar3 = 2;
  if (iVar2 != 0) {
    BUS_RegMaskedSet(&RAC->SR0,2);
    uVar1 = (RAC->SR0);
    if ((uVar1 & 0x20000) == 0) {
      BUS_RegMaskedSet(&RAC->SR2,0x10);
      uVar3 = uVar1 & 0x20000;
    }
    BUS_RegMaskedClear(&RAC->SR0,2);
    return (RAIL_Status_t)uVar3;
  }
  return RAIL_STATUS_INVALID_STATE;
}



RAIL_Status_t RAIL_BLE_Init(void)

{
  RAIL_Status_t RVar1;
  
  RFHAL_BleInit();
  isBleEnabled = true;
  RVar1 = RAIL_SetPtiProtocol(RAIL_PTI_PROTOCOL_BLE);
  return RVar1;
}



void RAIL_BLE_Deinit(void)

{
  if (isBleEnabled != false) {
    RFHAL_BleDeinit();
    isBleEnabled = false;
    RAIL_SetPtiProtocol(RAIL_PTI_PROTOCOL_CUSTOM);
    return;
  }
  return;
}



bool RAIL_BLE_IsEnabled(void)

{
  return isBleEnabled;
}



bool RAIL_BLE_SetPhy1MbpsViterbi(void)

{
  RAIL_RadioState_t RVar1;
  bool bVar2;
  
  if ((isBleEnabled != false) && (RVar1 = RFHAL_StateGet(), RVar1 == RAIL_RF_STATE_IDLE)) {
    bVar2 = RFHAL_Ble1MbpsSet();
    return bVar2;
  }
  return false;
}



bool RAIL_BLE_SetPhy1Mbps(void)

{
  RAIL_RadioState_t RVar1;
  bool bVar2;
  
  if ((isBleEnabled != false) && (RVar1 = RFHAL_StateGet(), RVar1 == RAIL_RF_STATE_IDLE)) {
    bVar2 = RFHAL_Ble1MbpsSet();
    return bVar2;
  }
  return false;
}



bool RAIL_BLE_SetPhy2MbpsViterbi(void)

{
  RAIL_RadioState_t RVar1;
  bool bVar2;
  
  if ((isBleEnabled != false) && (RVar1 = RFHAL_StateGet(), RVar1 == RAIL_RF_STATE_IDLE)) {
    bVar2 = RFHAL_Ble2MbpsSet();
    return bVar2;
  }
  return false;
}



bool RAIL_BLE_SetPhy2Mbps(void)

{
  RAIL_RadioState_t RVar1;
  bool bVar2;
  
  if ((isBleEnabled != false) && (RVar1 = RFHAL_StateGet(), RVar1 == RAIL_RF_STATE_IDLE)) {
    bVar2 = RFHAL_Ble2MbpsSet();
    return bVar2;
  }
  return false;
}



bool RAIL_BLE_SetupChannelRadioParams
               (uint32_t crcInit,uint32_t accessAddress,uint8_t channel,bool disableWhitening)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  uint32_t poly;
  uint32_t init;
  
  bVar4 = isBleEnabled;
  if (isBleEnabled != false) {
    bVar1 = (byte)crcInit;
    bVar2 = (byte)(crcInit >> 8);
    bVar3 = (byte)(crcInit >> 0x10);
    RFHAL_SetCRCInitVal(((uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1
                                          ) << 1 | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 |
                                       bVar1 >> 5 & 1) << 1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7) <<
                         0x18 | (uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 |
                                                 bVar2 >> 2 & 1) << 1 | bVar2 >> 3 & 1) << 1 |
                                               bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) << 1 |
                                             bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x10 |
                        (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1)
                                         << 1 | bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 |
                                      bVar3 >> 5 & 1) << 1 | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 8
                        ) >> 8);
    RFHAL_BLEPreambleSyncWordSet();
    if (disableWhitening != false) {
      poly = 0;
      init = 0;
    }
    else {
      poly = 0x44;
      init = channel | 0x40;
    }
    RFHAL_BLEWhiteningSet(poly,init,disableWhitening == false);
  }
  return bVar4;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void BUFC_SetCallbacks(uint32_t *callbacks)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  availableCallbacks = 0;
  if (callbacks != (uint32_t *)0x0) {
    uVar1 = 0;
    do {
      if (callbacks[uVar1] != 0) {
        uVar2 = uVar2 | 1 << (uVar1 & 0xff);
      }
      uVar1 = uVar1 + 1;
      availableCallbacks = uVar2;
    } while (uVar1 != 4);
  }
  currentCallbacks = callbacks;
  _DAT_e000e100 = 0x80;
  _DAT_e000e180 = 0x80;
  _DAT_e000e280 = 0x80;
  return;
}



void BUFC_ConfigureCallbacks(uint32_t callbacks)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  enabledCallbacks = callbacks & availableCallbacks;
  uVar3 = 0x90e0a09;
  if ((enabledCallbacks & 1) != 0) {
    uVar3 = 0x90e0a0d;
  }
  if ((int)(enabledCallbacks << 0x1e) < 0) {
    uVar3 = uVar3 | 1;
  }
  if ((int)(enabledCallbacks << 0x1d) < 0) {
    uVar3 = uVar3 | 0x400;
  }
  uVar1 = (BUFC->IEN);
  if ((int)(enabledCallbacks << 0x1c) < 0) {
    uVar3 = uVar3 | 0x200;
  }
  uVar2 = uVar1 & (uVar3 ^ uVar1);
  BUS_RegMaskedClear(&BUFC->IEN,uVar2);
  write_volatile_4(BUFC->IFC,uVar2);
  uVar3 = uVar3 & (uVar3 ^ uVar1);
  write_volatile_4(BUFC->IFC,uVar3);
  BUS_RegMaskedSet(&BUFC->IEN,uVar3);
  return;
}



void BUFC_WriteBuffer(uint32_t buf,uint8_t *src,uint16_t len)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)len;
  if (uVar1 == 0) {
    return;
  }
  uVar2 = uVar1 + 7 >> 3;
  switch(uVar1 & 7) {
  case 1:
    break;
  case 2:
    goto switchD_0001015e_caseD_2;
  case 3:
    goto switchD_0001015e_caseD_3;
  case 4:
    goto switchD_0001015e_caseD_4;
  case 5:
    goto switchD_0001015e_caseD_5;
  case 6:
    goto switchD_0001015e_caseD_6;
  case 7:
    goto switchD_0001015e_caseD_7;
  default:
    goto switchD_0001015e_caseD_7;
  }
switchD_0001015e_caseD_1:
  (&BUFC->BUF0_WRITEDATA)[buf * 0xc] = (uint)*src;
  uVar2 = uVar2 - 1;
  if (uVar2 == 0) {
    return;
  }
  src = src + 1;
switchD_0001015e_caseD_7:
  (&BUFC->BUF0_WRITEDATA)[buf * 0xc] = (uint)*src;
  src = src + 1;
switchD_0001015e_caseD_7:
  (&BUFC->BUF0_WRITEDATA)[buf * 0xc] = (uint)*src;
  src = src + 1;
switchD_0001015e_caseD_6:
  (&BUFC->BUF0_WRITEDATA)[buf * 0xc] = (uint)*src;
  src = src + 1;
switchD_0001015e_caseD_5:
  (&BUFC->BUF0_WRITEDATA)[buf * 0xc] = (uint)*src;
  src = src + 1;
switchD_0001015e_caseD_4:
  (&BUFC->BUF0_WRITEDATA)[buf * 0xc] = (uint)*src;
  src = src + 1;
switchD_0001015e_caseD_3:
  (&BUFC->BUF0_WRITEDATA)[buf * 0xc] = (uint)*src;
  src = src + 1;
switchD_0001015e_caseD_2:
  (&BUFC->BUF0_WRITEDATA)[buf * 0xc] = (uint)*src;
  src = src + 1;
  goto switchD_0001015e_caseD_1;
}



void BUFC_ReadBuffer(uint32_t buf,uint8_t *dest,uint16_t len)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)len;
  if (uVar1 == 0) {
    return;
  }
  uVar2 = uVar1 + 7 >> 3;
  switch(uVar1 & 7) {
  case 1:
    break;
  case 2:
    goto switchD_000101c4_caseD_2;
  case 3:
    goto switchD_000101c4_caseD_3;
  case 4:
    goto switchD_000101c4_caseD_4;
  case 5:
    goto switchD_000101c4_caseD_5;
  case 6:
    goto switchD_000101c4_caseD_6;
  case 7:
    goto switchD_000101c4_caseD_7;
  default:
    goto switchD_000101c4_caseD_7;
  }
switchD_000101c4_caseD_1:
  *dest = (uint8_t)(&BUFC->BUF0_READDATA)[buf * 0xc];
  uVar2 = uVar2 - 1;
  if (uVar2 == 0) {
    return;
  }
  dest = dest + 1;
switchD_000101c4_caseD_7:
  *dest = (uint8_t)(&BUFC->BUF0_READDATA)[buf * 0xc];
  dest = dest + 1;
switchD_000101c4_caseD_7:
  *dest = (uint8_t)(&BUFC->BUF0_READDATA)[buf * 0xc];
  dest = dest + 1;
switchD_000101c4_caseD_6:
  *dest = (uint8_t)(&BUFC->BUF0_READDATA)[buf * 0xc];
  dest = dest + 1;
switchD_000101c4_caseD_5:
  *dest = (uint8_t)(&BUFC->BUF0_READDATA)[buf * 0xc];
  dest = dest + 1;
switchD_000101c4_caseD_4:
  *dest = (uint8_t)(&BUFC->BUF0_READDATA)[buf * 0xc];
  dest = dest + 1;
switchD_000101c4_caseD_3:
  *dest = (uint8_t)(&BUFC->BUF0_READDATA)[buf * 0xc];
  dest = dest + 1;
switchD_000101c4_caseD_2:
  *dest = (uint8_t)(&BUFC->BUF0_READDATA)[buf * 0xc];
  dest = dest + 1;
  goto switchD_000101c4_caseD_1;
}



uint16_t BUFC_GetSpaceAvailable(uint32_t buf)

{
  return 0x200 - (ushort)(((&BUFC->BUF0_STATUS)[buf * 0xc] << 0x13) >> 0x13);
}



uint16_t BUFC_GetBytesAvailable(uint32_t buf)

{
  return (uint16_t)(((&BUFC->BUF0_STATUS)[buf * 0xc] << 0x13) >> 0x13);
}



void BUFC_TxAckBufferSet(uint8_t *src,uint16_t len)

{
  CORE_irqState_t irqState;
  
  write_volatile_4(BUFC->BUF3_CMD,1);
  irqState = CORE_EnterCritical();
  BUFC_WriteBuffer(3,src,len);
  CORE_ExitCritical(irqState);
  write_volatile_4(BUFC->BUF3_CMD,4);
  return;
}



void BUFC_TxAckBufferReset(void)

{
  BUFC_TxAckBufferSet((uint8_t *)0x0,0);
  return;
}



void BUFC_RxBufferSet(int param_1)

{
  if (param_1 != 0) {
    BUS_RegMaskedSet(&BUFC->IEN,0x400);
  }
  bufcRxStreaming._0_2_ = 0;
  bufcRxStreaming._4_4_ = param_1;
  return;
}



undefined4 BUFC_RxBufferGet(void)

{
  return bufcRxStreaming._4_4_;
}



void BUFC_RxBufferReset(void)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  bufcRxStreaming._0_2_ = 0;
  write_volatile_4(BUFC->BUF1_CMD,1);
  write_volatile_4(BUFC->BUF2_CMD,1);
  write_volatile_4(FRC->IFC,0x10);
  CORE_ExitCritical(irqState);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void BUFC_Init(void)

{
  write_volatile_4(BUFC->BUF1_CTRL,3);
  write_volatile_4(BUFC->BUF1_ADDR,(uint)BUFC_RxBuffer);
  write_volatile_4(BUFC->BUF1_THRESHOLDCTRL,0xfff);
  write_volatile_4(BUFC->BUF0_CTRL,3);
  write_volatile_4(BUFC->BUF0_ADDR,(uint)&BUFC_TxBuffer);
  write_volatile_4(BUFC->BUF0_THRESHOLDCTRL,0xfff);
  write_volatile_4(BUFC->BUF2_CTRL,0);
  write_volatile_4(BUFC->BUF2_ADDR,(uint)&BUFC_RxLengthBuffer);
  write_volatile_4(BUFC->BUF2_THRESHOLDCTR,3);
  write_volatile_4(BUFC->BUF3_CTRL,0);
  write_volatile_4(BUFC->BUF3_ADDR,(uint)&BUFC_TxAckBuffer);
  write_volatile_4(BUFC->BUF3_THRESHOLDCTRL,0x2000);
  RADIO_FrameControlDescrBufferIdSet(0,0);
  RADIO_FrameControlDescrBufferIdSet(1,0);
  RADIO_FrameControlDescrBufferIdSet(2,1);
  RADIO_FrameControlDescrBufferIdSet(3,1);
  BUS_RegMaskedClear(&FRC->CTRL,0xf0);
  BUS_RegMaskedSet(&FRC->CTRL,0xa0);
  RADIO_RegisterIrqCallback(3,0x10375);
  _DAT_e000e280 = 0x80;
  _DAT_e000e100 = 0x80;
  write_volatile_4(BUFC->BUF0_CMD,1);
  write_volatile_4(BUFC->BUF3_CMD,1);
  BUFC_RxBufferReset();
  BUFC_ConfigureCallbacks(0);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void BUFC_IrqHandler(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (BUFC->IF);
  uVar2 = (BUFC->IEN);
  uVar2 = uVar2 & uVar1;
  write_volatile_4(BUFC->IFC,uVar2);
  if (((int)(uVar2 << 0x1d) < 0) && ((int)((uint)(byte)enabledCallbacks << 0x1f) < 0)) {
    if (_DAT_430204b4 == 0) {
      BUS_RegMaskedSet(&BUFC->BUF0_THRESHOLDCTRL,0x2000);
    }
    else {
      BUS_RegMaskedClear(&BUFC->BUF0_THRESHOLDCTRL,0x2000);
      (**currentCallbacks)();
    }
  }
  if (((int)(uVar2 << 0x15) < 0) && ((int)((uint)(byte)enabledCallbacks << 0x1d) < 0)) {
    (*currentCallbacks[2])();
  }
  if ((int)(uVar2 << 0xd) < 0) {
    if (_DAT_430210b4 == 0) {
      write_volatile_4(FRC->IFS,0x10);
      BUS_RegMaskedSet(&FRC->IEN,0x10);
      if (bufcPendRxFrameError != '\0') {
        bufcPendRxFrameError = '\0';
        write_volatile_4(FRC->IFS,0x40);
      }
      BUS_RegMaskedSet(&BUFC->BUF2_THRESHOLDCTR,0x2000);
    }
    else {
      BUS_RegMaskedClear(&FRC->IEN,0x10);
      BUS_RegMaskedClear(&BUFC->BUF2_THRESHOLDCTR,0x2000);
    }
  }
  if ((uVar2 & 0xa0a00) != 0) {
    BUFC_RxBufferReset();
    if (((int)(uVar2 << 0x16) < 0) && ((int)((uint)(byte)enabledCallbacks << 0x1c) < 0)) {
      (*currentCallbacks[3])();
    }
  }
  if ((uVar2 & 9) != 0) {
    write_volatile_4(RAC->CMD,0x20);
    write_volatile_4(BUFC->BUF0_CMD,1);
    if (((int)(uVar2 << 0x1f) < 0) && ((int)((uint)(byte)enabledCallbacks << 0x1e) < 0)) {
      (*currentCallbacks[1])();
    }
  }
  if ((uVar2 & 0x9000000) != 0) {
    write_volatile_4(RAC->CMD,0x20);
    BUFC_TxAckBufferReset();
    return;
  }
  return;
}



uint16_t BUFC_RxBufferReadBytes(uint8_t *dest,uint16_t len)

{
  uint16_t uVar1;
  
  uVar1 = 1;
  BUFC_ReadBuffer(1,dest,len);
  return uVar1;
}



uint BUFC_RxBufferDropBytes(uint param_1,undefined4 param_2)

{
  uint16_t uVar1;
  uint uVar2;
  undefined4 uStack12;
  
  uStack12 = param_2;
  for (uVar2 = param_1; uVar2 != 0; uVar2 = uVar2 - 1 & 0xffff) {
    uVar1 = BUFC_RxBufferReadBytes((uint8_t *)((int)&uStack12 + 3),1);
    param_1 = (uint)uVar1;
  }
  return param_1;
}



bool BUFC_RxBufferPacketAvailable(void)

{
  uint uVar1;
  
  uVar1 = (BUFC->BUF2_STATUS);
  return 3 < (uVar1 & 0x1fff);
}



uint16_t BUFC_RxBufferBytesAvailable(void)

{
  uint uVar1;
  
  uVar1 = (BUFC->BUF1_STATUS);
  return (uint16_t)((uVar1 << 0x13) >> 0x13);
}



void BUFC_RxLengthReadNext(ushort *param_1)

{
  int iVar1;
  
  iVar1 = BUFC_RxBufferPacketAvailable();
  if (iVar1 == 0) {
    *(undefined *)(param_1 + 1) = 0;
    *(undefined *)param_1 = 0xff;
    *(undefined *)((int)param_1 + 1) = 0xff;
    return;
  }
  BUFC_ReadBuffer(2,(uint8_t *)param_1,4);
  *param_1 = (ushort)(((uint)*param_1 << 0x17) >> 0x17);
  return;
}



undefined4 IRCAL_Configure(undefined4 param_1)

{
  char cVar1;
  
  switch(param_1) {
  case 0:
    cVar1 = rcIrCalData[8];
    if (rcIrCalData[8] == '\x01') {
      if (rcIrCalData[5] == '\0') {
        return 0;
      }
    }
    else {
      if (rcIrCalData[8] == '\x02') {
        if (rcIrCalData[6] == '\0') {
          return 0;
        }
      }
      else {
        if (rcIrCalData[8] != '\x03') {
          return 0;
        }
        if (rcIrCalData[7] == '\0') {
          return 0;
        }
      }
    }
    break;
  case 1:
    if (rcIrCalData[5] == '\0') {
      return 0;
    }
    cVar1 = '\x01';
    break;
  case 2:
    if (rcIrCalData[6] == '\0') {
      return 0;
    }
    cVar1 = '\x02';
    break;
  case 3:
    if (rcIrCalData[7] == '\0') {
      return 0;
    }
    cVar1 = '\x03';
    break;
  default:
    return 0;
  }
  globalCalType = cVar1;
  return 1;
}



undefined IRCAL_GetGlobalCalType(void)

{
  IRCAL_Configure(globalCalType);
  return globalCalType;
}



void IRCAL_Set(uint param_1)

{
  uint uVar1;
  
  if (param_1 != 0xffffffff) {
    uVar1 = (RAC->IFPGACAL);
    write_volatile_4(RAC->IFPGACAL,uVar1 & 0xffff0000 | param_1 & 0xffff);
  }
  return;
}



uint8_t IRCAL_Init(uint8_t *settings)

{
  uint8_t uVar1;
  uint8_t uVar2;
  
  if ((settings != (uint8_t *)0x0) && (0x11 < *settings)) {
    rcIrCalData[5] = settings[6];
    if (rcIrCalData[5] != '\0') {
      rcIrCalData[5] = '\x01';
    }
    rcIrCalData[6] = settings[7];
    if (rcIrCalData[6] != '\0') {
      rcIrCalData[6] = '\x01';
    }
    rcIrCalData[7] = settings[8];
    if (rcIrCalData[7] != '\0') {
      rcIrCalData[7] = '\x01';
    }
    if (*settings < 0x18) {
      rcIrCalData[9] = settings[10];
      if (rcIrCalData[9] != '\0') {
        rcIrCalData[9] = '\x01';
      }
      rcIrCalData[10] = settings[0xb];
      rcIrCalData[11] = settings[0xc];
      rcIrCalData._12_2_ = CONCAT11(settings[0xe],settings[0xd]);
      uVar1 = settings[0x10];
      uVar2 = settings[0xf];
    }
    else {
      rcIrCalData[9] = settings[0x12];
      if (rcIrCalData[9] != '\0') {
        rcIrCalData[9] = '\x01';
      }
      rcIrCalData[10] = settings[0x13];
      rcIrCalData[11] = settings[0x14];
      rcIrCalData._12_2_ = CONCAT11(settings[0x16],settings[0x15]);
      uVar1 = settings[0x18];
      uVar2 = settings[0x17];
    }
    rcIrCalData[0] = settings[1];
    rcIrCalData[1] = settings[2];
    rcIrCalData[2] = settings[3];
    rcIrCalData[3] = settings[4];
    rcIrCalData[4] = settings[5];
    rcIrCalData[8] = settings[9];
    rcIrCalData._14_2_ = CONCAT11(uVar1,uVar2);
    rcIrCalData[16] = settings[0x11];
    return '\0';
  }
  IRCAL_Set(0);
  return '\x01';
}



void IRCAL_SaveRegStates(void)

{
  uint uVar1;
  
  BUFC_RxBuffer._0_4_ = (RAC->SGRFENCTRL0);
  BUFC_RxBuffer._4_4_ = (RAC->RFENCTRL0);
  BUFC_RxBuffer._8_4_ = (AGC->CTRL0);
  BUFC_RxBuffer._12_4_ = (AGC->MANGAIN);
  BUFC_RxBuffer._16_4_ = (AGC->GAINRANGE);
  BUFC_RxBuffer._20_4_ = (AGC->GAININDEX);
  BUFC_RxBuffer._24_4_ = (AGC->MININDEX);
  BUFC_RxBuffer._28_4_ = (MODEM->MODINDEX);
  BUFC_RxBuffer._32_4_ = (MODEM->CTRL0);
  BUFC_RxBuffer._36_4_ = (FRC->DFLCTRL);
  BUFC_RxBuffer._40_4_ = (RAC->SGPACTRL0);
  BUFC_RxBuffer._44_4_ = (RAC->SGPAPKDCTRL);
  BUFC_RxBuffer._48_4_ = (RAC->SGPABIASCTRL0);
  BUFC_RxBuffer._52_4_ = (RAC->SGPABIASCTRL1);
  BUFC_RxBuffer._56_4_ = (RAC->PACTUNECTRL);
  BUFC_RxBuffer._60_4_ = (MODEM->RAMPCTRL);
  BUFC_RxBuffer._64_4_ = (RAC->TESTCTRL);
  BUFC_RxBuffer._68_4_ = (AGC->CTRL1);
  BUFC_RxBuffer._72_4_ = (MODEM->AFC);
  BUFC_RxBuffer._76_4_ = SYNTH_RfFreqGet();
  BUFC_RxBuffer._80_4_ = SYNTH_ChSpacingGet();
  write_volatile_4(MODEM->AFC,0);
  BUS_RegMaskedSet(&FRC->CTRL,1);
  BUS_RegMaskedSet(&RAC->CTRL,0x40);
  uVar1 = (AGC->CTRL1);
  write_volatile_4(AGC->CTRL1,uVar1 & 0xfffff0ff | (rcIrCalData[16] & 0xf) << 8);
  return;
}



undefined4 IRCAL_SetRxFrequency(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = SYNTH_IfFreqGet();
  uVar1 = (SYNTH->IFFREQ);
  iVar3 = iVar2 * 2;
  if ((uVar1 & 0x100000) != 0) {
    iVar3 = iVar2 * -2;
  }
  iVar2 = SYNTH_VcoRangeIsValid(param_1 + iVar3);
  if (iVar2 == 0) {
    IRCAL_Set();
    return 0xffffffff;
  }
  SYNTH_Config(param_1 + iVar3,0);
  return 0;
}



void IRCAL_StartRx(void)

{
  uint uVar1;
  
  BUS_RegMaskedSet(&MODEM->CTRL0,0x200000);
  do {
    uVar1 = (RAC->STATUS);
  } while ((uVar1 & 0xf000000) != 0);
  BUFC_RxBufferReset();
  BUS_RegMaskedSet(&RAC->RXENSRCEN,8);
  do {
    uVar1 = (RAC->STATUS);
  } while ((uVar1 << 4) >> 0x1c != 2);
  return;
}



void IRCAL_StopRx(void)

{
  CORE_irqState_t irqState;
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  iVar1 = 0xff;
  BUS_RegMaskedClear(&RAC->RXENSRCEN,0xff);
  irqState = CORE_EnterCritical();
  uVar2 = (RAC->STATUS);
  uVar2 = (uVar2 << 4) >> 0x1c;
  bVar3 = uVar2 == 3;
  if (bVar3) {
    iVar1 = 0x21000f64;
    uVar2 = (SEQ->REG06C);
    uVar2 = uVar2 & 0xffffff0f | 0xe0;
  }
  if (bVar3) {
    *(uint *)(iVar1 + 8) = uVar2;
  }
  write_volatile_4(FRC->CMD,1);
  CORE_ExitCritical(irqState);
  do {
    uVar2 = (RAC->STATUS);
  } while ((uVar2 & 0xf000000) != 0);
  return;
}



void IRCAL_SetSubGhzPllLoopback(void)

{
  uint uVar1;
  
  uVar1 = (AGC->MANGAIN);
  write_volatile_4(AGC->MANGAIN,uVar1 & 0x801001ff | 0x40009800);
  BUS_RegMaskedSet(&AGC->CTRL0,0x400000);
  BUS_RegMaskedSet(&RAC->SGRFENCTRL0,0x80000);
  BUS_RegMaskedSet(&RAC->RFENCTRL0,0x80000);
  return;
}



void IRCAL_SetSubGhzPaLoopback(void)

{
  uint uVar1;
  
  uVar1 = (AGC->GAINRANGE);
  write_volatile_4(AGC->GAINRANGE,uVar1 & 0xffffc000 | 0x383e);
  uVar1 = (AGC->GAININDEX);
  write_volatile_4(AGC->GAININDEX,uVar1 & 0xfff00000 | 0x25bc);
  uVar1 = (AGC->MININDEX);
  write_volatile_4(AGC->MININDEX,uVar1 & 0xff000000 | 0x6d8480);
  uVar1 = (AGC->MANGAIN);
  write_volatile_4(AGC->MANGAIN,uVar1 & 0xffffff40 | 0xa7);
  BUS_RegMaskedSet(&AGC->CTRL0,0x400000);
  write_volatile_4(MODEM->MODINDEX,0);
  uVar1 = (MODEM->CTRL0);
  write_volatile_4(MODEM->CTRL0,uVar1 & 0xfffffe3f | 0x100);
  uVar1 = (FRC->DFLCTRL);
  write_volatile_4(FRC->DFLCTRL,uVar1 & 0xfffffff8 | 5);
  BUS_RegMaskedClear(&RAC->SGRFENCTRL0,0x80000);
  uVar1 = (RAC->SGPACTRL0);
  write_volatile_4(RAC->SGPACTRL0,uVar1 & 0x3fffffff | 0x40000000);
  BUS_RegMaskedClear(&RAC->SGPAPKDCTRL,0xc000);
  BUS_RegMaskedSet(&RAC->SGPAPKDCTRL,0xc000);
  uVar1 = (RAC->SGPABIASCTRL0);
  write_volatile_4(RAC->SGPABIASCTRL0,uVar1 & 0xff3ff332 | 0x445);
  uVar1 = (RAC->SGPABIASCTRL1);
  write_volatile_4(RAC->SGPABIASCTRL1,uVar1 & 0xffffffc8 | 0x20);
  uVar1 = (RAC->SGPABIASCTRL1);
  write_volatile_4(RAC->SGPABIASCTRL1,uVar1 & 0xfff388ff | 0x84500);
  BUS_RegMaskedClear(&RAC->PACTUNECTRL,0x1f0);
  BUS_RegMaskedSet(&RAC->SGPACTRL0,8);
  BUS_RegMaskedSet(&RAC->SGRFENCTRL0,0x10000);
  PHY_UTILS_DelayUs(0x14);
  uVar1 = (RAC->SGPACTRL0);
  write_volatile_4(RAC->SGPACTRL0,uVar1 & 0xffffc03f | 0x40);
  BUS_RegMaskedSet(&RAC->SGRFENCTRL0,0x20000);
  PHY_UTILS_DelayUs(0x14);
  uVar1 = (RAC->SGPACTRL0);
  write_volatile_4(RAC->SGPACTRL0,uVar1 & 0xe0c03fff | 0x1004000);
  PHY_UTILS_DelayUs(0x14);
  BUS_RegMaskedSet(&RAC->SGRFENCTRL0,0x40000);
  PHY_UTILS_DelayUs(0x14);
  BUS_RegMaskedSet(&RAC->TESTCTRL,9);
  PHY_UTILS_DelayUs(0x14);
  uVar1 = (RAC->SGPACTRL0);
  write_volatile_4(RAC->SGPACTRL0,uVar1 & 0xe0c03fff | 0x1004000);
  PHY_UTILS_DelayUs(0x14);
  uVar1 = (MODEM->RAMPCTRL);
  write_volatile_4(MODEM->RAMPCTRL,
                   uVar1 & 0x7fffff | 0x800000 | (uint)rcIrCalData[2] << 0x18);
  PHY_UTILS_DelayUs(0x14);
  return;
}



undefined4 IRCAL_Setup(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined uVar1;
  int iVar2;
  
  IRCAL_SaveRegStates();
  uVar1 = rcIrCalData[3];
  if (((param_1 == 2) || (uVar1 = rcIrCalData[4], param_1 == 3)) &&
     (iVar2 = AUXPLL_Start(param_1,uVar1,rcIrCalData[0],rcIrCalData[1],param_4), iVar2 != -1)) {
    IRCAL_StopRx();
    iVar2 = IRCAL_SetRxFrequency(iVar2);
    if (iVar2 != -1) {
      IRCAL_StartRx();
      if (param_1 == 2) {
        IRCAL_SetSubGhzPllLoopback();
      }
      else {
        if (param_1 != 3) {
          return 0xffffffff;
        }
        IRCAL_SetSubGhzPaLoopback();
      }
      return 0;
    }
  }
  return 0xffffffff;
}



int IRCAL_ReadRssi(uint param_1,uint param_2,uint param_3,undefined4 param_4,undefined2 param_5)

{
  uint uVar1;
  int16_t iVar2;
  short sVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if ((param_1 & 0x80) != 0) {
    param_1 = 0x7f;
  }
  if ((param_2 & 0x80) != 0) {
    param_2 = 0x7f;
  }
  if (param_3 < 0xf) {
    uVar5 = (RAC->IFPGACAL);
    write_volatile_4(RAC->IFPGACAL,uVar5 & 0xffff8080 | param_1 << 8 | param_2);
    PHY_UTILS_DelayUs(param_4);
    if (rcIrCalData[9] == '\0') {
      write_volatile_4(AGC->IFC,0x20);
    }
    uVar5 = 0;
    uVar4 = 0;
    for (uVar6 = 0; uVar6 >> (param_3 & 0xff) == 0; uVar6 = uVar6 + 1) {
      PHY_UTILS_DelayUs(param_5);
      if (rcIrCalData[9] == '\0') {
        write_volatile_4(AGC->CMD,1);
        do {
          uVar1 = (AGC->IF);
        } while (-1 < (int)(uVar1 << 0x1a));
      }
      if (rcIrCalData[11] <= uVar6) {
        iVar2 = RADIO_GetRSSI();
        uVar5 = uVar5 + 1;
        uVar4 = uVar4 + (int)iVar2;
      }
      if (rcIrCalData[9] == '\0') {
        write_volatile_4(AGC->IFC,0x20);
      }
    }
    if (uVar5 == 0) {
      uVar5 = 1;
    }
    sVar3 = (short)(uVar4 / uVar5);
  }
  else {
    sVar3 = -1;
  }
  return (int)sVar3;
}



uint IRCAL_SearchLinear2Stage
               (uint param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined2 param_5)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  short sVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar8 = 0;
  sVar5 = 0x7fff;
  uVar6 = 5;
  do {
    uVar3 = 0x40 - uVar6 & 0xff;
    do {
      uVar7 = param_1;
      if (param_2 != 0) {
        uVar7 = uVar3;
        uVar3 = param_1;
      }
      sVar1 = IRCAL_ReadRssi(uVar7,uVar3,param_3,param_4,param_5);
      uVar3 = uVar6 + 10 & 0xff;
      if (sVar1 < sVar5) {
        uVar8 = uVar6;
        sVar5 = sVar1;
      }
      if (uVar3 == 0x87) {
        uVar3 = uVar8 - 5;
        uVar7 = 0x45 - uVar8;
        uVar6 = 0;
        sVar5 = 0x7fff;
        while( true ) {
          uVar3 = uVar3 & 0xff;
          if ((uVar8 + 5 < uVar3) || ((int)(uVar3 << 0x18) < 0)) break;
          if (uVar3 != 0) {
            uVar4 = uVar3;
            if (uVar3 < 0x40) {
              uVar4 = uVar7 & 0xff;
            }
            uVar2 = param_1;
            if (param_2 != 0) {
              uVar2 = uVar4;
              uVar4 = param_1;
            }
            sVar1 = IRCAL_ReadRssi(uVar2,uVar4,param_3,param_4,param_5);
            if (sVar1 < sVar5) {
              uVar6 = uVar3;
              sVar5 = sVar1;
            }
          }
          uVar3 = uVar3 + 1;
          uVar7 = (uVar7 & 0xff) - 1;
        }
        if (uVar6 < 0x40) {
          uVar6 = 0x40 - uVar6 & 0xff;
        }
        return uVar6;
      }
      uVar6 = uVar3;
    } while (0x3f < uVar3);
  } while( true );
}



uint IRCAL_Search(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  if (param_1 == 2) {
    uVar1 = IRCAL_SearchLinear2Stage(0,1,param_2,param_3,param_4,param_2,param_3);
    uVar2 = IRCAL_SearchLinear2Stage(uVar1,0,param_2,param_3,param_4);
    iVar3 = IRCAL_SearchLinear2Stage(uVar2,1,param_2,param_3,param_4);
    uVar2 = uVar2 | iVar3 << 8;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



void IRCAL_Teardown(void)

{
  undefined4 in_r3;
  
  IRCAL_StopRx();
  AUXPLL_Stop();
  write_volatile_4(RAC->SGRFENCTRL0,BUFC_RxBuffer._0_4_);
  write_volatile_4(RAC->RFENCTRL0,BUFC_RxBuffer._4_4_);
  write_volatile_4(AGC->CTRL0,BUFC_RxBuffer._8_4_);
  write_volatile_4(AGC->MANGAIN,BUFC_RxBuffer._12_4_);
  write_volatile_4(AGC->GAINRANGE,BUFC_RxBuffer._16_4_);
  write_volatile_4(AGC->GAININDEX,BUFC_RxBuffer._20_4_);
  write_volatile_4(AGC->MININDEX,BUFC_RxBuffer._24_4_);
  write_volatile_4(MODEM->MODINDEX,BUFC_RxBuffer._28_4_);
  write_volatile_4(MODEM->CTRL0,BUFC_RxBuffer._32_4_);
  write_volatile_4(FRC->DFLCTRL,BUFC_RxBuffer._36_4_);
  write_volatile_4(RAC->SGPACTRL0,BUFC_RxBuffer._40_4_);
  write_volatile_4(RAC->SGPAPKDCTRL,BUFC_RxBuffer._44_4_);
  write_volatile_4(RAC->SGPABIASCTRL0,BUFC_RxBuffer._48_4_);
  write_volatile_4(RAC->SGPABIASCTRL1,BUFC_RxBuffer._52_4_);
  write_volatile_4(RAC->PACTUNECTRL,BUFC_RxBuffer._56_4_);
  write_volatile_4(MODEM->RAMPCTRL,BUFC_RxBuffer._60_4_);
  write_volatile_4(RAC->TESTCTRL,BUFC_RxBuffer._64_4_);
  write_volatile_4(AGC->CTRL1,BUFC_RxBuffer._68_4_);
  write_volatile_4(MODEM->AFC,BUFC_RxBuffer._72_4_);
  SYNTH_Config(BUFC_RxBuffer._76_4_,BUFC_RxBuffer._80_4_,BUFC_RxBuffer._72_4_,BUFC_RxBuffer,in_r3);
  BUFC_RxBufferReset();
  BUS_RegMaskedClear(&FRC->CTRL,1);
  BUS_RegMaskedClear(&RAC->CTRL,0x40);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint IRCAL_GetDiValue(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = SYNTH_RfFreqGet();
  if (uVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = _DAT_0fe081c8;
    if ((999999999 < uVar1) &&
       (uVar1 = (MODEM->CTRL0), uVar2 = _DAT_0fe081c4,
       (uVar1 << 0x17) >> 0x1d != 4)) {
      uVar2 = _DAT_0fe081c0;
    }
    if (uVar2 != 0xffffffff) {
      return uVar2 & 0xffff;
    }
  }
  return uVar2;
}



uint IRCAL_PerformSubfunction
               (uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined2 param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  uint64_t uVar5;
  uint64_t uVar6;
  undefined8 uVar7;
  
  uVar2 = (PROTIMER->WRAPCNT);
  uVar5 = PROTIMER_PrecntOverflowToUs(uVar2);
  if (param_1 == 1) {
    uVar2 = IRCAL_GetDiValue();
    BUFC_RxBufferReset();
  }
  else {
    if ((param_1 == 0) || (3 < param_1)) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = IRCAL_Setup(param_1);
      if (uVar2 != 0xffffffff) {
        uVar2 = IRCAL_Search(param_2,param_3,param_4,param_5);
      }
      IRCAL_Teardown();
    }
  }
  uVar3 = (PROTIMER->WRAPCNT);
  uVar6 = PROTIMER_PrecntOverflowToUs(uVar3);
  uVar7 = __aeabi_uldivmod((int)(uVar6 - uVar5),(int)(uVar6 - uVar5 >> 0x20),1000,0);
  iVar1 = (int)((ulonglong)uVar7 >> 0x20);
  bVar4 = iVar1 == 0;
  if (iVar1 == 0) {
    bVar4 = (uint)uVar7 < 0xffff;
  }
  if (bVar4) {
    uVar3 = (uint)uVar7 & 0xfffe;
  }
  else {
    uVar3 = 0;
  }
  if (uVar2 != 0xffffffff) {
    IRCAL_Set(uVar2);
    uVar2 = uVar2 | uVar3 << 0x10;
  }
  return uVar2;
}



undefined4 IRCAL_Perform(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = IRCAL_GetGlobalCalType();
  if (iVar1 == 0xff) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = IRCAL_PerformSubfunction
                      (iVar1,2,rcIrCalData[10],rcIrCalData._12_2_,rcIrCalData._14_2_,param_2,param_3
                      );
  }
  return uVar2;
}



void PROTIMER_Init(void)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  RADIOCMU_ClockEnable(0x60400,1);
  write_volatile_4(Peripherals::PROTIMER.CTRL,0x11100);
  uVar2 = RADIOCMU_ClockFreqGet(0x60400);
  uVar2 = uVar2 / 1000;
  uVar3 = (uint)((ulonglong)uVar2 * 2000);
  uVar5 = uVar3 * 0x100;
  uVar6 = __aeabi_uldivmod(uVar5 + 500000,
                           ((int)((ulonglong)uVar2 * 2000 >> 0x20) << 8 | uVar3 >> 0x18) +
                           (uint)(0xfff85edf < uVar5),1000000,0);
  uVar3 = (uint)uVar6;
  write_volatile_4(Peripherals::PROTIMER.PRECNTTOP,uVar3 - 0x100);
  uVar7 = __aeabi_uldivmod(500,uVar2,1000,0);
  uVar5 = (uint)uVar7 * 0x100;
  _usRatioFrac = __aeabi_uldivmod((uVar3 >> 1) + uVar5,
                                  ((int)((ulonglong)uVar7 >> 0x20) << 8 | (uint)uVar7 >> 0x18) +
                                  (uint)CARRY4(uVar3 >> 1,uVar5),uVar3,
                                  (int)((ulonglong)uVar6 >> 0x20));
  iVar4 = (int)_usRatioFrac;
  lVar1 = (ulonglong)(uVar3 << 0x18) * 1000;
  uVar5 = (uint)lVar1;
  uVar6 = __aeabi_uldivmod(uVar5 + (uVar2 >> 1),
                           (uVar3 >> 8) * 1000 + (int)((ulonglong)lVar1 >> 0x20) +
                           (uint)CARRY4(uVar5,uVar2 >> 1),uVar2,0);
  write_volatile_4(Peripherals::PROTIMER.WRAPCNTTOP,iVar4 - 1);
  precntRatioFrac = (int)uVar6;
  precntRatioInt = (int)((ulonglong)uVar6 >> 0x20);
  return;
}


// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_Start(void)

{
  write_volatile_4(PROTIMER->CMD,1);
  _DAT_e000e100 = 0x10000000;
  _DAT_e000e280 = 0x10000000;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_Stop(void)

{
  write_volatile_4(PROTIMER->CMD,4);
  _DAT_e000e180 = 0x10000000;
  _DAT_e000e280 = 0x10000000;
  return;
}



bool PROTIMER_IsRunning(void)

{
  uint uVar1;
  
  uVar1 = (PROTIMER->STATUS);
  return uVar1 & 1;
}



void PROTIMER_Reset(void)

{
  write_volatile_4(PROTIMER->PRECNT,0);
  write_volatile_4(PROTIMER->BASECNT,0);
  write_volatile_4(PROTIMER->WRAPCNT,0);
  return;
}



uint32_t PROTIMER_ElapsedTime(uint32_t begin,uint32_t end)

{
  uint uVar1;
  uint32_t uVar2;
  
  uVar1 = (PROTIMER->WRAPCNTTOP);
  uVar2 = end - begin;
  if (end < begin) {
    uVar2 = uVar2 + uVar1 + 1;
  }
  return uVar2;
}



void PROTIMER_CCTimerStop(uint32_t timer)

{
  (&Peripherals::PROTIMER_CLR.CC0_CTRL)[timer * 4] = 1;
  write_volatile_4(Peripherals::PROTIMER.IFC,0x100 << (timer & 0xff));
  return;
}



bool PROTIMER_CCTimerStart(uint32_t timer,uint32_t time,RAIL_TimeMode_t mode)

{
  uint uVar1;
  uint end;
  uint uVar2;
  CORE_irqState_t irqState;
  uint32_t uVar3;
  int iVar4;
  bool bVar5;
  
  irqState = CORE_EnterCritical();
  PROTIMER_CCTimerStop(timer);
  uVar1 = (PROTIMER->WRAPCNT);
  if (mode == RAIL_TIME_DELAY) {
    if (time == 0) {
      time = 1;
    }
    time = time + uVar1;
  }
  else {
    if (mode == RAIL_TIME_DISABLED) {
      return true;
    }
  }
  uVar1 = (PROTIMER->WRAPCNTTOP);
  if (uVar1 < time) {
    time = (time - uVar1) - 1;
  }
  iVar4 = 1;
  while( true ) {
    (&PROTIMER->CC0_WRAP)[timer * 4] = time;
    (&PROTIMER->CC0_CTRL)[timer * 4] = 0x11;
    end = (PROTIMER->WRAPCNT);
    uVar3 = PROTIMER_ElapsedTime(time,end);
    if (uVar1 >> 2 < uVar3) {
      bVar5 = false;
    }
    else {
      uVar2 = (PROTIMER->IF);
      bVar5 = (0x100 << (timer & 0xff) & uVar2) == 0;
    }
    iVar4 = iVar4 + 1;
    time = iVar4 + end;
    if ((mode != RAIL_TIME_DELAY) || (iVar4 == 7)) break;
    if (!bVar5) {
LAB_00010f96:
      CORE_ExitCritical(irqState);
      return true;
    }
  }
  if (bVar5) {
    PROTIMER_CCTimerStop(timer);
    CORE_ExitCritical(irqState);
    return false;
  }
  goto LAB_00010f96;
}



bool PROTIMER_CCTimerIsEnabled(uint32_t timer)

{
  return (bool)((byte)(&PROTIMER->CC0_CTRL)[timer * 4] & 1);
}



void PROTIMER_CCTimerCapture(int param_1,uint param_2)

{
  (&PROTIMER->CC0_CTRL)[param_1 * 4] = param_2 & 0xe00000 | 3;
  return;
}



undefined PROTIMER_ScheduleTxEnable(uint32_t param_1,uint32_t param_2,RAIL_TimeMode_t param_3)

{
  bool bVar1;
  
  PROTIMER_CCTimerStop();
  write_volatile_4(PROTIMER->TXCTRL,(param_1 + 9) * 0x100 | 1);
  bVar1 = PROTIMER_CCTimerStart(param_1,param_2,param_3);
  return bVar1;
}



void PROTIMER_ClearTxEnable(void)

{
  write_volatile_4(PROTIMER->TXCTRL,0);
  return;
}



undefined PROTIMER_ScheduleRxEnable(uint32_t param_1,uint32_t param_2,RAIL_TimeMode_t param_3)

{
  bool bVar1;
  
  PROTIMER_CCTimerStop();
  write_volatile_4(PROTIMER->RXCTRL,(param_1 + 9) * 0x100 | 0x10001);
  bVar1 = PROTIMER_CCTimerStart(param_1,param_2,param_3);
  return bVar1;
}



undefined PROTIMER_ScheduleRxDisable(uint32_t param_1,uint32_t param_2,RAIL_TimeMode_t param_3)

{
  uint uVar1;
  bool bVar2;
  
  PROTIMER_CCTimerStop();
  uVar1 = (PROTIMER->RXCTRL);
  write_volatile_4(PROTIMER->RXCTRL,
                   uVar1 & 0xe0e0ffff | 0x10000 | (param_1 + 9) * 0x1000000);
  bVar2 = PROTIMER_CCTimerStart(param_1,param_2,param_3);
  return bVar2;
}



void PROTIMER_ClearRxEnable(void)

{
  write_volatile_4(PROTIMER->RXCTRL,0x1010000);
  return;
}



uint32_t PROTIMER_GetTime(void)

{
  uint uVar1;
  
  uVar1 = (PROTIMER->WRAPCNT);
  return uVar1;
}



uint32_t PROTIMER_GetCCTime(uint32_t timer)

{
  return (&PROTIMER->CC0_WRAP)[timer * 4];
}



void PROTIMER_LBTUseLastConfig(void)

{
  uint uVar1;
  
  uVar1 = (PROTIMER->TOUT0COMP);
  if (uVar1 == 0) {
    BUS_RegMaskedSet(&RAC->RXENSRCEN,0x10);
  }
  write_volatile_4(PROTIMER->RXCTRL,0x18011b01);
  write_volatile_4(PROTIMER->TXCTRL,0x1401);
  return;
}



void PROTIMER_LBTStart(void)

{
  RADIO_PTI_AuxdataOutput(0x21);
  write_volatile_4(PROTIMER->CMD,0x10000);
  return;
}



void PROTIMER_LBTStop(void)

{
  RADIO_PTI_AuxdataOutput(0x22);
  write_volatile_4(PROTIMER->CMD,0x40000);
  return;
}



bool PROTIMER_LBTIsActive(void)

{
  uint uVar1;
  
  uVar1 = (PROTIMER->STATUS);
  return (uVar1 & 6) != 0;
}



uint64_t PROTIMER_PrecntOverflowToUs(uint32_t cnt)

{
  uint uVar1;
  int in_r1;
  uint uVar2;
  
  uVar2 = precntRatioFrac * in_r1 + (int)((ulonglong)cnt * (ulonglong)precntRatioFrac >> 0x20) +
          (uint)(0x7fffffff < (uint)((ulonglong)cnt * (ulonglong)precntRatioFrac));
  uVar1 = (uint)((ulonglong)cnt * (ulonglong)precntRatioInt);
  return CONCAT44(precntRatioInt * in_r1 + (int)((ulonglong)cnt * (ulonglong)precntRatioInt >> 0x20)
                  + (uint)CARRY4(uVar1,uVar2),uVar1 + uVar2);
}



uint64_t PROTIMER_UsToPrecntOverflow(uint32_t us)

{
  return (uint64_t)
         ((ulonglong)usRatioInt * (ulonglong)us +
         ((ulonglong)usRatioFrac * (ulonglong)us + 0x80000000 >> 0x20));
}



bool PROTIMER_SetTime(uint32_t time)

{
  int iVar1;
  uint64_t uVar2;
  
  iVar1 = PROTIMER_IsRunning();
  if (iVar1 != 0) {
    PROTIMER_Stop();
    iVar1 = 1;
  }
  PROTIMER_Reset();
  uVar2 = PROTIMER_UsToPrecntOverflow(time);
  write_volatile_4(PROTIMER->WRAPCNT,(uint)uVar2);
  if (iVar1 != 0) {
    PROTIMER_Start((uint)uVar2,(int)(uVar2 >> 0x20));
  }
  return true;
}



void PROTIMER_LBTCfgSet(uint param_1,int param_2,uint param_3,int param_4,byte param_5)

{
  uint uVar1;
  uint32_t us;
  uint64_t uVar2;
  
  uVar1 = (PROTIMER->CTRL);
  write_volatile_4(PROTIMER->CTRL,uVar1 & 0xff0fffff | 0x900000);
  if (param_3 == 0) {
    write_volatile_4(PROTIMER->RXCTRL,0);
    param_1 = param_3;
  }
  write_volatile_4(PROTIMER->LBTCTRL,
                   (uint)param_5 << 8 | param_4 << 0x18 | param_2 << 4 | param_3 << 0x10 | param_1);
  uVar1 = (PROTIMER->BASECNTTOP);
  write_volatile_4(PROTIMER->TOUT0CNTTOP,uVar1);
  if (param_3 != 0) {
    us = TIMING_RxWarmTimeGet();
    uVar2 = PROTIMER_UsToPrecntOverflow(us);
    if (uVar1 < (uint)uVar2) {
      BUS_RegMaskedSet(&RAC->RXENSRCEN,0x10);
      write_volatile_4(PROTIMER->TOUT0COMP,0);
    }
    else {
      write_volatile_4(PROTIMER->TOUT0COMP,(uint)uVar2);
    }
    write_volatile_4(PROTIMER->RXCTRL,0x18011b01);
  }
  write_volatile_4(PROTIMER->TXCTRL,0x1401);
  return;
}



void PROTIMER_DelayUs(uint32_t us)

{
  uint end;
  uint uVar1;
  int iVar2;
  uint32_t uVar3;
  uint uVar4;
  uint begin;
  uint uVar5;
  uint64_t uVar6;
  
  uVar6 = PROTIMER_UsToPrecntOverflow(us);
  uVar4 = (uint)uVar6;
  begin = read_volatile_4(Peripherals::PROTIMER.WRAPCNT);
  uVar1 = read_volatile_4(Peripherals::PROTIMER.WRAPCNTTOP);
  iVar2 = PROTIMER_IsRunning(uVar4,(int)(uVar6 >> 0x20));
  if (iVar2 != 0) {
    while( true ) {
      uVar5 = uVar4;
      if (uVar1 >> 1 <= uVar4) {
        uVar5 = uVar1 >> 1;
      }
      do {
        end = read_volatile_4(Peripherals::PROTIMER.WRAPCNT);
        uVar3 = PROTIMER_ElapsedTime(begin,end);
      } while (uVar3 < uVar5);
      if (uVar4 <= uVar3) break;
      uVar4 = uVar4 - uVar3;
      begin = end;
    }
  }
  return;
}



void PHY_UTILS_DelayUs(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = PROTIMER_IsRunning();
  if (iVar1 == 0) {
    PROTIMER_Init();
    PROTIMER_Start();
  }
  PROTIMER_DelayUs(param_1);
  if (iVar1 == 0) {
    PROTIMER_Stop();
    PROTIMER_Reset();
    return;
  }
  return;
}



void setupPnForTest(void)

{
  uint uVar1;
  
  uVar1 = (FRC->FCD0);
  write_volatile_4(FRC->FCD0,uVar1 & 0xffffbfff);
  uVar1 = (FRC->FCD1);
  write_volatile_4(FRC->FCD1,uVar1 & 0xffffbfff);
  uVar1 = (FRC->FCD2);
  write_volatile_4(FRC->FCD2,uVar1 & 0xffffbfff);
  uVar1 = (FRC->FCD3);
  write_volatile_4(FRC->FCD3,uVar1 & 0xffffbfff);
  write_volatile_4(FRC->FECCTRL,1);
  write_volatile_4(FRC->WHITECTRL,0x24);
  write_volatile_4(FRC->WHITEPOLY,0x100);
  write_volatile_4(FRC->WHITEINIT,0x138);
  return;
}



void RFTEST_SaveRadioConfiguration(void)

{
  if (testModeRegisterState == '\0') {
    DAT_200030d8 = (MODEM->AFC);
    DAT_200030dc = (MODEM->CTRL0);
    DAT_200030e0 = (MODEM->CTRL1);
    DAT_200030e4 = (MODEM->MODINDEX);
    DAT_200030e8 = (MODEM->PRE);
    DAT_200030ec = (MODEM->TIMING);
    DAT_200030f0 = (FRC->DFLCTRL);
    DAT_200030f4 = (FRC->CTRL);
    DAT_200030f8 = (FRC->FECCTRL);
    DAT_200030fc = (FRC->FCD0);
    DAT_20003100 = (FRC->FCD1);
    DAT_20003104 = (FRC->FCD2);
    DAT_20003108 = (FRC->FCD3);
    DAT_2000310c = (FRC->WHITECTRL);
    DAT_20003110 = (FRC->WHITEPOLY);
    DAT_20003114 = (FRC->WHITEINIT);
    DAT_20003118 = (SEQ->SYNTHLPFCTRLTX);
    DAT_2000311c = (FRC->SNIFFCTRL);
    DAT_20003120 = (FRC->IEN);
    write_volatile_4(FRC->IEN,0);
    testModeRegisterState = '\x01';
  }
  return;
}



void RFTEST_RestoreRadioConfiguration(void)

{
  if (testModeRegisterState != '\0') {
    write_volatile_4(MODEM->AFC,DAT_200030d8);
    write_volatile_4(MODEM->CTRL0,DAT_200030dc);
    write_volatile_4(MODEM->CTRL1,DAT_200030e0);
    write_volatile_4(MODEM->MODINDEX,DAT_200030e4);
    write_volatile_4(MODEM->PRE,DAT_200030e8);
    write_volatile_4(FRC->DFLCTRL,DAT_200030f0);
    write_volatile_4(FRC->CTRL,DAT_200030f4);
    write_volatile_4(FRC->FECCTRL,DAT_200030f8);
    write_volatile_4(FRC->FCD0,DAT_200030fc);
    write_volatile_4(FRC->FCD1,DAT_20003100);
    write_volatile_4(FRC->FCD2,DAT_20003104);
    write_volatile_4(FRC->FCD3,DAT_20003108);
    write_volatile_4(FRC->WHITECTRL,DAT_2000310c);
    write_volatile_4(FRC->WHITEPOLY,DAT_20003110);
    write_volatile_4(FRC->WHITEINIT,DAT_20003114);
    write_volatile_4(SEQ->SYNTHLPFCTRLTX,DAT_20003118);
    write_volatile_4(FRC->SNIFFCTRL,DAT_2000311c);
    write_volatile_4(FRC->IFC,0x7ffff);
    write_volatile_4(FRC->IEN,DAT_20003120);
    testModeRegisterState = '\0';
  }
  return;
}



void RFTEST_StartCwTx(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (SEQ->SYNTHLPFCTRLTX);
  write_volatile_4(SEQ->SYNTHLPFCTRLTX,uVar1 & 0xfffffff0);
  uVar1 = (MODEM->CTRL0);
  uVar2 = uVar1 & 0x1c0;
  if (uVar2 == 0xc0) {
    write_volatile_4(MODEM->CTRL0,uVar1 & 0xfffffe3f | 0x80);
  }
  else {
    if ((uVar2 != 0x180) && (uVar2 != 0x80)) {
      write_volatile_4(MODEM->MODINDEX,0);
    }
  }
  BUS_RegMaskedSet(&MODEM->PRE,0xffff000f);
  BUS_RegMaskedClear(&MODEM->PRE,0x30);
  write_volatile_4(FRC->DFLCTRL,5);
  BUS_RegMaskedSet(&FRC->CTRL,1);
  write_volatile_4(RAC->CMD,1);
  return;
}



void RFTEST_StartStreamTx(void)

{
  setupPnForTest();
  write_volatile_4(FRC->SNIFFCTRL,0);
  write_volatile_4(FRC->DFLCTRL,5);
  BUS_RegMaskedSet(&FRC->CTRL,1);
  write_volatile_4(RAC->CMD,1);
  return;
}



void RFTEST_StopTx(void)

{
  uint uVar1;
  
  write_volatile_4(RAC->CMD,0x20);
  do {
    uVar1 = (FRC->DFLCTRL);
    if ((uVar1 & 7) != 5) {
      return;
    }
    uVar1 = (FRC->IF);
  } while (-1 < (int)(uVar1 << 0x1d));
  return;
}



void RFSENSE_Disable(void)

{
  uint uVar1;
  uint uVar2;
  CORE_irqState_t irqState;
  
  uVar2 = em4Flag;
  RFSENSE_Cb = 0;
  write_volatile_4(RFSENSE->IEN,0);
  write_volatile_4(RFSENSE->EM4WUEN,0);
  write_volatile_4(RFSENSE->CTRL,0);
  write_volatile_4(RFSENSE->PERIODSEL,0xf);
  if (em4Flag != 0) {
    em4Flag = 0;
    irqState = CORE_EnterCritical();
    uVar1 = (EMU->EM4CTRL);
    write_volatile_4(EMU->EM4CTRL,uVar1 & ~uVar2);
    CORE_ExitCritical(irqState);
    return;
  }
  RFSENSE_Cb = 0;
  return;
}



int RFSENSE_CalcPeriod(uint param_1,uint param_2,char *param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  
  switch(param_1 & 0xc) {
  case 0:
    uVar1 = RFSENSE_RfOscFreqHz;
    break;
  case 4:
    uVar1 = SystemLFRCOClockGet();
    break;
  case 8:
    uVar1 = SystemLFXOClockGet();
    break;
  case 0xc:
    uVar1 = SystemULFRCOClockGet();
    break;
  default:
    return 0;
  }
  if (uVar1 == 0) {
    return 0;
  }
  uVar4 = uVar1 >> 1;
  uVar2 = __aeabi_uldivmod(uVar4 + 0xa1200000,(0x5edfffff < uVar4) + '\a',uVar1,0,param_4);
  uVar1 = (uVar4 + 3000000) / uVar1;
  if (uVar1 < param_2) {
    param_2 = param_2 - uVar1;
  }
  else {
    param_2 = 0;
  }
  for (cVar3 = '\x0f'; (param_2 < uVar2 - (uVar2 >> 2) && (cVar3 != '\0')); cVar3 = cVar3 + -1) {
    uVar2 = uVar2 >> 1;
  }
  *param_3 = cVar3;
  return uVar2 + uVar1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RFSENSE_ReInit(void)

{
  RFSENSE_Disable();
  write_volatile_4(RFSENSE->IFC,1);
  _DAT_e000e184 = 1;
  _DAT_e000e284 = 1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// WARNING: Unknown calling convention yet parameter storage is locked

bool RFSENSE_Sensed(void)

{
  code *pcVar1;
  int iVar2;
  CORE_irqState_t irqState;
  uint uVar3;
  
  iVar2 = _DAT_43c81904;
  BUS_RegMaskedSet(&CMU->HFRADIOCLKEN0,2);
  uVar3 = (RFSENSE->IF);
  if (uVar3 != 0) {
    uVar3 = 1;
  }
  if (uVar3 != 0) {
    irqState = CORE_EnterCritical();
    pcVar1 = RFSENSE_Cb;
    RFSENSE_Cb = FUN_00000000;
    CORE_ExitCritical(irqState);
    RFSENSE_Disable();
    if (pcVar1 != FUN_00000000) {
      (*pcVar1)();
    }
  }
  if (iVar2 == 0) {
    BUS_RegMaskedClear(&CMU->HFRADIOCLKEN0,2);
  }
  return SUB41(uVar3,0);
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// WARNING: Unknown calling convention yet parameter storage is locked

bool RFSENSE_IRQHandler(void)

{
  code *pcVar1;
  int iVar2;
  CORE_irqState_t irqState;
  uint uVar3;
  
  iVar2 = _DAT_43c81904;
  BUS_RegMaskedSet(&CMU->HFRADIOCLKEN0,2);
  uVar3 = (RFSENSE->IF);
  if (uVar3 != 0) {
    uVar3 = 1;
  }
  if (uVar3 != 0) {
    irqState = CORE_EnterCritical();
    pcVar1 = RFSENSE_Cb;
    RFSENSE_Cb = FUN_00000000;
    CORE_ExitCritical(irqState);
    RFSENSE_Disable();
    if (pcVar1 != FUN_00000000) {
      (*pcVar1)();
    }
  }
  if (iVar2 == 0) {
    BUS_RegMaskedClear(&CMU->HFRADIOCLKEN0,2);
  }
  return SUB41(uVar3,0);
}



void RFSENSE_DeInit(void)

{
  RFSENSE_ReInit();
  BUS_RegMaskedClear(&CMU->HFRADIOCLKEN0,2);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

char * RFSENSE_Init(undefined4 *param_1,uint param_2)

{
  byte bVar1;
  char *pcVar2;
  CORE_irqState_t irqState;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  
  BUS_RegMaskedSet(&CMU->HFRADIOCLKEN0,2);
  puVar8 = param_1;
  RFSENSE_ReInit();
  if (param_1 == (undefined4 *)0x0) {
LAB_000115de:
    RFSENSE_DeInit();
    return (char *)0x0;
  }
  bVar1 = *(byte *)(param_1 + 2);
  uVar6 = (uint)bVar1;
  if ((((bVar1 & 3) == 0) || (param_1[1] == 0)) ||
     (pcVar2 = (char *)RFSENSE_CalcPeriod(uVar6,param_1[1],&stack0xffffffe6), pcVar2 == (char *)0x0)
     ) goto LAB_000115de;
  if (((bVar1 & 0xc) == 0) && (pcVar3 = (char *)param_1[1], "s and LCD peripherals" < pcVar3)) {
    if (pcVar3 < pcVar2) {
      uVar7 = (int)pcVar2 - (int)pcVar3;
    }
    else {
      uVar7 = (int)pcVar3 - (int)pcVar2;
    }
    if ((uVar7 != 0) &&
       (pcVar3 = (char *)RFSENSE_CalcPeriod(0xc,pcVar3,&stack0xffffffe7,"s and LCD peripherals",
                                            puVar8,param_2), pcVar3 != (char *)0x0)) {
      pcVar4 = (char *)param_1[1];
      if (pcVar4 < pcVar3) {
        uVar5 = (int)pcVar3 - (int)pcVar4;
      }
      else {
        uVar5 = (int)pcVar4 - (int)pcVar3;
      }
      if (uVar5 < uVar7) {
        param_2 = (param_2 >> 0x18) << 0x10;
        uVar6 = uVar6 | 0xc;
        pcVar2 = pcVar3;
      }
    }
  }
  write_volatile_4(RFSENSE->PERIODSEL,param_2 >> 0x10 & 0xff);
  if (*(char *)((int)param_1 + 9) == '\0') goto LAB_00011678;
  write_volatile_4(RFSENSE->EM4WUEN,1);
  uVar7 = uVar6 & 0xc;
  if (uVar7 == 8) {
    uVar7 = (EMU->EM4CTRL);
    if (-1 < (int)(uVar7 << 0x1d)) {
      uVar7 = 4;
      goto LAB_0001169c;
    }
  }
  else {
    if (uVar7 == 0xc) {
      uVar7 = (EMU->EM4CTRL);
      if (-1 < (int)(uVar7 << 0x1c)) {
        uVar7 = 8;
        goto LAB_0001169c;
      }
    }
    else {
      if ((uVar7 == 4) &&
         (uVar7 = (EMU->EM4CTRL), -1 < (int)(uVar7 << 0x1e))) {
        uVar7 = 2;
LAB_0001169c:
        irqState = CORE_EnterCritical();
        uVar5 = (EMU->EM4CTRL);
        write_volatile_4(EMU->EM4CTRL,uVar5 | uVar7);
        CORE_ExitCritical(irqState);
        em4Flag = uVar7;
        goto LAB_00011678;
      }
    }
  }
  em4Flag = 0;
LAB_00011678:
  write_volatile_4(RFSENSE->IEN,1);
  write_volatile_4(RFSENSE->CTRL,uVar6 & 0x2f);
  RFSENSE_Cb = *param_1;
  _DAT_e000e104 = 1;
  return pcVar2;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void TEMPCAL_Init(void)

{
  char cVar1;
  char cVar2;
  
  cVar1 = (char)(_DAT_0fe08204 & 0xff);
  if ((_DAT_0fe08204 & 0xff) == 0xff) {
    cVar1 = -0x70;
    cVar2 = '\x19';
  }
  else {
    cVar2 = (char)((uint)(_DAT_0fe081b0 << 8) >> 0x18);
    if (cVar2 == -1) {
      cVar1 = -0x70;
      cVar2 = '\x19';
    }
  }
  write_volatile_1(SEQ->REG078._3_1_,(char)((uint)(int)cVar2 / 2) + cVar1);
  write_volatile_1(SEQ->REG078._2_1_,2);
  write_volatile_1(SEQ->REG078._1_1_,0x23);
  return;
}



void TEMPCAL_Perform(void)

{
  uint uVar1;
  
  uVar1 = (RAC->STATUS);
  if ((uVar1 << 4) >> 0x1c == 2) {
    write_volatile_4(RAC->CMD,0x80);
  }
  return;
}



uint16_t RFRAND_GetRadioEntropy(uint8_t *buffer,uint16_t bytes)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  CORE_irqState_t irqState;
  uint __n;
  size_t __n_00;
  uint local_24;
  
  __n = (uint)bytes;
  uVar4 = (CMU->HFRADIOCLKEN0);
  local_24 = __n;
  memset(buffer,0,__n);
  if ((((uVar4 | 0xcc) == uVar4) &&
      (uVar4 = (RAC->CTRL), -1 < (int)(uVar4 << 0x1f))) &&
     (uVar4 = RADIOCMU_ClockPrescGet(0x75160), uVar4 == 0)) {
    irqState = CORE_EnterCritical();
    uVar3 = (MODEM->CTRL0);
    uVar2 = (FRC->RAWCTRL);
    BUS_RegMaskedClear(&MODEM->CTRL0,0x38000000);
    BUS_RegMaskedSet(&MODEM->CTRL0,0x8000000);
    write_volatile_4(FRC->RAWCTRL,0x24);
    BUS_RegMaskedSet(&RAC->RXENSRCEN,4);
    write_volatile_4(FRC->IFC,0x4000);
    write_volatile_4(FRC->CMD,0x1000);
    for (; uVar4 < __n; uVar4 = uVar4 + __n_00 & 0xffff) {
      do {
        do {
          uVar1 = (FRC->IF);
        } while (-1 < (int)(uVar1 << 0x11));
        uVar1 = (FRC->STATUS);
      } while (-1 < (int)(uVar1 << 0x17));
      __n_00 = __n - uVar4;
      write_volatile_4(FRC->IFC,0x4000);
      if (3 < (int)__n_00) {
        __n_00 = 4;
      }
      local_24 = (FRC->RXRAWDATA);
      memcpy(buffer + uVar4,&local_24,__n_00);
    }
    BUS_RegMaskedClear(&RAC->RXENSRCEN,4);
    write_volatile_4(FRC->RAWCTRL,uVar2);
    write_volatile_4(MODEM->CTRL0,uVar3);
    write_volatile_4(FRC->IFC,0x4000);
    CORE_ExitCritical(irqState);
  }
  else {
    bytes = 0;
  }
  return bytes;
}



bool RFRAND_SeedProtimerRandom(void)

{
  bool bVar1;
  uint16_t uVar2;
  undefined4 in_r1;
  ushort local_a [5];
  
  local_a[0] = (ushort)((uint)in_r1 >> 0x10);
  uVar2 = RFRAND_GetRadioEntropy((uint8_t *)local_a,2);
  if (uVar2 == 2) {
    if (local_a[0] == 0xf804) {
      local_a[0] = 0xf805;
    }
    write_volatile_4(PROTIMER->RANDOM,(uint)local_a[0]);
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}



void GENERIC_PHY_RAC_IRQCallback(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (RAC->IF);
  uVar2 = (RAC->IEN);
  uVar2 = uVar2 & uVar1;
  write_volatile_4(RAC->IFC,uVar2);
  if ((int)(uVar2 << 0x1f) < 0) {
    (**(code **)(currentCallbacks + 0x3c))();
  }
  if ((int)(uVar2 << 0x1d) < 0) {
    (**(code **)(currentCallbacks + 0x38))();
  }
  if ((int)(uVar2 << 6) < 0) {
    if ((int)((uint)DAT_20003136 << 0x1f) < 0) {
      (**(code **)(currentCallbacks + 0x40))();
    }
    PA_PeakDetectorHighRun();
  }
  if ((int)(uVar2 << 5) < 0) {
    if ((int)((uint)DAT_20003136 << 0x1e) < 0) {
      (**(code **)(currentCallbacks + 0x44))();
    }
    PA_PeakDetectorLowRun();
  }
  if ((int)(uVar2 << 4) < 0) {
    if ((int)((uint)DAT_20003136 << 0x1d) < 0) {
      (**(code **)(currentCallbacks + 0x48))();
    }
    PA_BatHighRun();
  }
  uVar1 = uVar2 & 0xff0000;
  if (uVar1 != 0) {
    if ((uVar2 & 0x40000) != 0) {
      if ((int)((uint)DAT_20003136 << 0x1c) < 0) {
        (**(code **)(currentCallbacks + 0x4c))();
      }
      uVar1 = uVar2 & 0xfb0000;
    }
    if ((int)(uVar1 << 0xf) < 0) {
      if ((int)((uint)enabledCallbacks << 0x19) < 0) {
        (**(code **)(currentCallbacks + 0x18))(2);
      }
      uVar1 = uVar1 & 0xfffeffff;
    }
    if ((int)(uVar1 << 0xe) < 0) {
      if ((int)((uint)enabledCallbacks << 0x1e) < 0) {
        (**(code **)(currentCallbacks + 4))(0x10);
      }
      uVar1 = uVar1 & 0xfffdffff;
    }
    if ((int)(uVar1 << 0xb) < 0) {
      if ((int)((uint)DAT_20003135 << 0x1e) < 0) {
        (**(code **)(currentCallbacks + 0x24))();
      }
      uVar1 = uVar1 & 0xffefffff;
    }
    if ((*(code **)(currentCallbacks + 0x50) != FUN_00000000) && (uVar1 != 0)) {
                    // WARNING: Could not recover jumptable at 0x00011934. Too many branches
                    // WARNING: Treating indirect jump as call
      (**(code **)(currentCallbacks + 0x50))(uVar1);
      return;
    }
  }
  return;
}



void GENERIC_PHY_MODEM_IRQCallback(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (MODEM->IF);
  uVar2 = (MODEM->IEN);
  uVar2 = uVar2 & uVar1;
  write_volatile_4(MODEM->IFC,uVar2);
  if ((int)(uVar2 << 0x12) < 0) {
    (**(code **)(currentCallbacks + 0x28))();
  }
  if ((int)(uVar2 << 0x16) < 0) {
    (**(code **)(currentCallbacks + 0x2c))();
  }
  if ((int)(uVar2 << 0x15) < 0) {
    (**(code **)(currentCallbacks + 0x30))();
  }
  if ((int)(uVar2 << 0x14) < 0) {
                    // WARNING: Could not recover jumptable at 0x00011988. Too many branches
                    // WARNING: Treating indirect jump as call
    (**(code **)(currentCallbacks + 0x34))();
    return;
  }
  return;
}



void GENERIC_PHY_AGC_IRQCallback(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (AGC->IF);
  uVar2 = (AGC->IEN);
  write_volatile_4(AGC->IFC,uVar1 & uVar2);
  if ((int)((uVar1 & uVar2) << 0x1f) < 0) {
                    // WARNING: Could not recover jumptable at 0x000119a8. Too many branches
                    // WARNING: Treating indirect jump as call
    (**(code **)(currentCallbacks + 0x68))();
    return;
  }
  return;
}



void RADIO_RACRxAbort(undefined4 param_1,undefined4 param_2,int param_3)

{
  CORE_irqState_t irqState;
  uint uVar1;
  bool bVar2;
  
  irqState = CORE_EnterCritical();
  uVar1 = (RAC->STATUS);
  uVar1 = (uVar1 << 4) >> 0x1c;
  bVar2 = uVar1 == 3;
  if (bVar2) {
    param_3 = 0x21000f64;
    uVar1 = (SEQ->REG06C);
    uVar1 = uVar1 & 0xffffff0f | 0xe0;
  }
  if (bVar2) {
    *(uint *)(param_3 + 8) = uVar1;
  }
  write_volatile_4(FRC->CMD,1);
  CORE_ExitCritical(irqState);
  return;
}



void GENERIC_PHY_PROTIMER_IRQCallback(void)

{
  uint16_t uVar1;
  int iVar2;
  CORE_irqState_t irqState;
  uint uVar3;
  code *pcVar4;
  uint uVar5;
  
  iVar2 = PROTIMER_LBTIsActive();
  uVar3 = (PROTIMER->IF);
  uVar5 = (PROTIMER->IEN);
  uVar5 = uVar5 & uVar3;
  write_volatile_4(PROTIMER->IFC,uVar5);
  if ((int)(uVar5 << 0x14) < 0) {
    PROTIMER_CCTimerStop(3);
  }
  if ((uVar5 & 0x500000) == 0) {
    if (-1 < (int)(uVar5 << 0x13)) goto LAB_00011a7e;
    if (iVar2 != 0) goto LAB_00011a18;
    PROTIMER_CCTimerStop(3);
    PROTIMER_CCTimerStop(4);
    PROTIMER_ClearRxEnable();
    irqState = CORE_EnterCritical();
    if (scheduledRxHardEnd != '\0') {
      RADIO_RACRxAbort();
    }
    uVar3 = (RAC->STATUS);
    if (((uVar3 << 4) >> 0x1c == 3) || (uVar1 = BUFC_RxBufferBytesAvailable(), uVar1 != 0)) {
      uVar1 = 1;
      pendedRxWindowEnd = scheduledRxLoop;
    }
    CORE_ExitCritical(irqState);
    if ((uVar1 != 0) || (-1 < (int)((uint)enabledCallbacks << 0x19))) goto LAB_00011a7e;
    pcVar4 = *(code **)(currentCallbacks + 0x18);
    uVar3 = 1;
  }
  else {
LAB_00011a18:
    pcVar4 = *(code **)(currentCallbacks + 0x58);
    uVar3 = uVar5;
  }
  (*pcVar4)(uVar3);
LAB_00011a7e:
  if ((int)(uVar5 << 10) < 0) {
    (**(code **)(currentCallbacks + 0x5c))();
  }
  if ((int)(uVar5 << 6) < 0) {
    (**(code **)(currentCallbacks + 0x60))();
  }
  if (-1 < (int)(uVar5 << 0x15)) {
    return;
  }
                    // WARNING: Could not recover jumptable at 0x00011aa4. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(currentCallbacks + 100))();
  return;
}



void GENERIC_PHY_SetAddressFilteringMatchTable(void)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  uint uVar12;
  uint local_38;
  uint local_34;
  
  uVar5 = 0;
  local_34 = 0;
  uVar3 = 0;
  do {
    uVar6 = uVar3 + 1;
    uVar1 = uVar6 * 5;
    uVar12 = addressFilterMatchTable >> (uVar1 & 0xff) & 0x1f;
    uVar7 = addressFilterMatchTable >> (uVar6 & 0xff) & 0x108421;
    uVar9 = uVar6 * 8;
    local_38 = uVar1;
    for (uVar8 = uVar6; local_38 = local_38 + 5, uVar8 != 4; uVar8 = uVar8 + 1) {
      puVar11 = &SEQ->REG010;
      bVar2 = read_volatile_1(SEQ->REG058._0_1_);
      uVar4 = 1 << (uVar8 & 0xff) | 1 << (uVar3 & 0xff);
      if ((uVar4 & bVar2) == uVar4) {
        bVar2 = read_volatile_1(SEQ->REG054._2_1_);
        for (iVar10 = 0; iVar10 < (int)(uint)bVar2; iVar10 = iVar10 + 1) {
          puVar11 = puVar11 + 1;
          if (((*puVar11 >> (uVar9 & 0xff) ^ *puVar11 >> (uVar5 & 0xff)) & 0xff) != 0)
          goto LAB_00011b52;
        }
        uVar12 = uVar12 | addressFilterMatchTable >> (local_38 & 0xff) & 0x1f;
      }
LAB_00011b52:
      bVar2 = read_volatile_1(SEQ->REG058._1_1_);
      if ((uVar4 & bVar2) == uVar4) {
        bVar2 = read_volatile_1(SEQ->REG054._3_1_);
        puVar11 = &SEQ->REG030;
        for (iVar10 = 0; iVar10 < (int)(uint)bVar2; iVar10 = iVar10 + 1) {
          puVar11 = puVar11 + 1;
          if (((*puVar11 >> (uVar9 & 0xff) ^ *puVar11 >> (uVar5 & 0xff)) & 0xff) != 0)
          goto LAB_00011b9a;
        }
        uVar7 = uVar7 | addressFilterMatchTable >> (uVar8 + 1 & 0xff) & 0x108421;
      }
LAB_00011b9a:
      uVar9 = uVar9 + 8;
    }
    local_34 = local_34 | uVar7 << (uVar6 & 0xff) | uVar12 << (uVar1 & 0xff);
    uVar5 = uVar5 + 8;
    uVar3 = uVar6;
    if (uVar6 == 4) {
      write_volatile_4(SEQ->REG010,local_34);
      return;
    }
  } while( true );
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void GENERIC_PHY_ConfigureCallbacks(uint32_t callbacks)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  _enabledCallbacks = callbacks & availableCallbacks;
  uVar3 = 0x161;
  if ((_enabledCallbacks & 1) != 0) {
    uVar3 = 0x163;
  }
  if ((int)(_enabledCallbacks << 0x1e) < 0) {
    uVar3 = uVar3 | 0xc;
  }
  if ((int)(_enabledCallbacks << 0x18) < 0) {
    uVar3 = uVar3 | 0x4000;
  }
  uVar2 = (FRC->IEN);
  if ((int)(_enabledCallbacks << 0x17) < 0) {
    uVar3 = uVar3 | 0x2000;
  }
  uVar1 = (uVar3 ^ uVar2) & 0xffffffef;
  uVar2 = uVar2 & uVar1;
  BUS_RegMaskedClear(&FRC->IEN,uVar2);
  write_volatile_4(FRC->IFC,uVar2);
  uVar3 = uVar3 & uVar1;
  write_volatile_4(FRC->IFC,uVar3);
  BUS_RegMaskedSet(&FRC->IEN,uVar3);
  if ((_enabledCallbacks & 0x400) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0x2000;
  }
  if ((int)(_enabledCallbacks << 0x14) < 0) {
    uVar3 = uVar3 | 0x200;
  }
  if ((int)(_enabledCallbacks << 0x13) < 0) {
    uVar3 = uVar3 | 0x400;
  }
  uVar2 = (MODEM->IEN);
  if ((int)(_enabledCallbacks << 0x12) < 0) {
    uVar3 = uVar3 | 0x800;
  }
  uVar1 = uVar2 & (uVar3 ^ uVar2);
  BUS_RegMaskedClear(&MODEM->IEN,uVar1);
  write_volatile_4(MODEM->IFC,uVar1);
  uVar3 = uVar3 & (uVar3 ^ uVar2);
  write_volatile_4(MODEM->IFC,uVar3);
  BUS_RegMaskedSet(&MODEM->IEN,uVar3);
  if ((_enabledCallbacks & 0x4000) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 4;
  }
  if ((int)(_enabledCallbacks << 0x10) < 0) {
    uVar3 = uVar3 | 1;
  }
  if ((int)(_enabledCallbacks << 0xc) < 0) {
    uVar3 = uVar3 | 0x40000;
  }
  if ((int)(_enabledCallbacks << 0x1e) < 0) {
    uVar3 = uVar3 | 0x20000;
  }
  if ((int)(_enabledCallbacks << 0x19) < 0) {
    uVar3 = uVar3 | 0x10000;
  }
  if ((int)(_enabledCallbacks << 0x16) < 0) {
    uVar3 = uVar3 | 0x100000;
  }
  uVar2 = (RAC->IEN);
  if ((int)(_enabledCallbacks << 0xb) < 0) {
    uVar3 = uVar3 | 0xe80000;
  }
  uVar1 = uVar2 & (uVar3 ^ uVar2);
  BUS_RegMaskedClear(&RAC->IEN,uVar1);
  write_volatile_4(RAC->IFC,uVar1);
  uVar3 = uVar3 & (uVar3 ^ uVar2);
  write_volatile_4(RAC->IFC,uVar3);
  BUS_RegMaskedSet(&RAC->IEN,uVar3);
  uVar3 = 0x501800;
  if ((_enabledCallbacks & 0x400000) == 0) {
    uVar3 = 0x1800;
  }
  if ((int)(_enabledCallbacks << 8) < 0) {
    uVar3 = uVar3 | 0x200000;
  }
  if ((int)(_enabledCallbacks << 7) < 0) {
    uVar3 = uVar3 | 0x2000000;
  }
  uVar2 = (PROTIMER->IEN);
  if ((int)(_enabledCallbacks << 6) < 0) {
    uVar3 = uVar3 | 0x400;
  }
  uVar1 = uVar2 & (uVar3 ^ uVar2);
  BUS_RegMaskedClear(&PROTIMER->IEN,uVar1);
  write_volatile_4(PROTIMER->IFC,uVar1);
  uVar3 = uVar3 & (uVar3 ^ uVar2);
  write_volatile_4(PROTIMER->IFC,uVar3);
  BUS_RegMaskedSet(&PROTIMER->IEN,uVar3);
  uVar3 = (AGC->IEN);
  uVar2 = (_enabledCallbacks << 5) >> 0x1f;
  uVar1 = uVar2 ^ uVar3;
  uVar3 = uVar3 & uVar1;
  BUS_RegMaskedClear(&AGC->IEN,uVar3);
  write_volatile_4(AGC->IFC,uVar3);
  uVar2 = uVar2 & uVar1;
  write_volatile_4(AGC->IFC,uVar2);
  BUS_RegMaskedSet(&AGC->IEN,uVar2);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void GENERIC_PHY_SetCallbacks(uint32_t *callbacks)

{
  uint uVar1;
  uint uVar2;
  
  _DAT_e000e280 = 0x8000000;
  _DAT_e000e180 = 0x8000000;
  uVar2 = 0;
  availableCallbacks = 0;
  if (callbacks != (uint32_t *)0x0) {
    uVar1 = 0;
    do {
      if (callbacks[uVar1] != 0) {
        uVar2 = uVar2 | 1 << (uVar1 & 0xff);
      }
      uVar1 = uVar1 + 1;
      availableCallbacks = uVar2;
    } while (uVar1 != 0x1b);
  }
  currentCallbacks = callbacks;
  GENERIC_PHY_ConfigureCallbacks(0xffffffff);
  _DAT_e000e100 = 0x8000000;
  _DAT_e000e280 = 0x8000000;
  return;
}



void GENERIC_PHY_PacketTxCommon(void)

{
  uint uVar1;
  uint16_t uVar2;
  
  uVar1 = (FRC->DFLCTRL);
  if (((uVar1 & 7) == 0) && (uVar1 = (SEQ->REG060), uVar1 != 0)) {
    uVar2 = BUFC_GetBytesAvailable(0);
    write_volatile_4(FRC->WCNTCMP0,uVar2 - 1);
  }
  BUS_RegMaskedSet(&RAC->SR0,0x80);
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 & 0xffffffbf);
  return;
}



RAIL_Status_t GENERIC_PHY_PacketTx(void)

{
  bool bVar1;
  CORE_irqState_t irqState;
  int iVar2;
  
  irqState = CORE_EnterCritical();
  bVar1 = PROTIMER_CCTimerIsEnabled(3);
  if ((bVar1 == false) && (iVar2 = PROTIMER_LBTIsActive(), iVar2 == 0)) {
    GENERIC_PHY_PacketTxCommon();
    write_volatile_4(RAC->CMD,1);
    CORE_ExitCritical(irqState);
    return RAIL_STATUS_NO_ERROR;
  }
  CORE_ExitCritical(irqState);
  return RAIL_STATUS_INVALID_PARAMETER;
}



undefined4
GENERIC_PHY_SchedulePacketRx
          (undefined4 param_1,int param_2,int param_3,int param_4,char param_5,undefined param_6)

{
  bool bVar1;
  CORE_irqState_t irqState;
  int iVar2;
  uint32_t uVar3;
  uint32_t us;
  uint uVar4;
  uint64_t uVar5;
  
  iVar2 = param_4;
  irqState = CORE_EnterCritical();
  if (param_2 != 2) {
    bVar1 = PROTIMER_CCTimerIsEnabled(3);
    if (bVar1 != false) {
      CORE_ExitCritical(irqState);
      return 1;
    }
    PROTIMER_ClearRxEnable();
    PROTIMER_ClearTxEnable();
    scheduledRxLoop = param_5;
    uVar4 = (SEQ->REG000);
    if (param_5 == '\0') {
      uVar4 = uVar4 & 0xffffffbf;
    }
    else {
      uVar4 = uVar4 | 0x40;
    }
    write_volatile_4(SEQ->REG000,uVar4);
    iVar2 = PROTIMER_ScheduleRxEnable(3,param_1,param_2,&Peripherals::SEQ,iVar2);
    if (iVar2 == 0) {
      CORE_ExitCritical(irqState);
      return 2;
    }
  }
  if (param_4 != 2) {
    bVar1 = PROTIMER_CCTimerIsEnabled(3);
    if ((bVar1 == false) &&
       (uVar4 = (RAC->STATUS), -1 < (int)(uVar4 << 0x11))) {
      CORE_ExitCritical(irqState);
      return 4;
    }
    scheduledRxHardEnd = param_6;
    if ((param_4 == 1) && (param_2 != 2)) {
      uVar3 = PROTIMER_GetCCTime(3);
      us = TIMING_RxWarmTimeGet();
      uVar5 = PROTIMER_UsToPrecntOverflow(us);
      param_4 = 0;
      param_3 = param_3 + uVar3 + (int)uVar5;
    }
    pendedRxWindowEnd = 0;
    iVar2 = PROTIMER_ScheduleRxDisable(4,param_3,param_4);
    if (iVar2 == 0) {
      PROTIMER_CCTimerStop(3);
      PROTIMER_ClearRxEnable();
      CORE_ExitCritical(irqState);
      return 3;
    }
  }
  CORE_ExitCritical(irqState);
  return 0;
}



undefined4 GENERIC_PHY_SchedulePacketTx(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  CORE_irqState_t irqState;
  int iVar2;
  
  irqState = CORE_EnterCritical();
  bVar1 = PROTIMER_CCTimerIsEnabled(3);
  if ((bVar1 == false) && (iVar2 = PROTIMER_LBTIsActive(), iVar2 == 0)) {
    GENERIC_PHY_PacketTxCommon();
    PROTIMER_ClearRxEnable();
    PROTIMER_ClearTxEnable();
    iVar2 = PROTIMER_ScheduleTxEnable(3,param_1,param_2);
    if (iVar2 == 0) {
      BUS_RegMaskedClear(&RAC->SR0,0x80);
      CORE_ExitCritical(irqState);
      return 2;
    }
    CORE_ExitCritical(irqState);
    return 0;
  }
  CORE_ExitCritical(irqState);
  return 1;
}



uint16_t GENERIC_PHY_PacketRxDataHelper(int param_1,uint param_2)

{
  BUFC_RxBufferBytesAvailable();
  if (param_1 == 0) {
    BUFC_RxBufferDropBytes(param_2);
  }
  else {
    BUFC_RxBufferReadBytes((uint8_t *)param_1,(ushort)param_2 & 0xff);
  }
  return (ushort)param_2;
}



uint GENERIC_PHY_PacketRxAppendedInfoHelper
               (uint param_1,void *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  void *apvStack28 [3];
  
  uVar1 = (FRC->TRAILRXDATA);
  apvStack28[0] = param_2;
  apvStack28[1] = (void *)param_3;
  apvStack28[2] = (void *)param_4;
  if (param_2 == (void *)0x0) {
    BUFC_RxBufferDropBytes();
  }
  else {
    BUFC_RxBufferReadBytes((uint8_t *)apvStack28,(ushort)param_1 & 0xff);
    uVar3 = 0x14;
    memset(param_2,0,0x14);
    bVar6 = (int)(uVar1 << 0x1a) < 0;
    uVar5 = param_1;
    if (bVar6) {
      uVar5 = param_1 - 4 & 0xffff;
      uVar3 = *(undefined4 *)((int)apvStack28 + uVar5);
    }
    if (bVar6) {
      *(undefined4 *)((int)param_2 + 0x10) = uVar3;
    }
    if ((int)(uVar1 << 0x1b) < 0) {
      uVar5 = uVar5 - 2 & 0xffff;
      *(uint *)((int)param_2 + 0xc) =
           *(uint *)((int)param_2 + 0xc) | (uint)*(ushort *)((int)apvStack28 + uVar5) << 0x10;
    }
    uVar4 = uVar1 << 0x1c;
    if ((int)uVar4 < 0) {
      uVar5 = uVar5 - 2 & 0xffff;
      uVar4 = (uint)*(ushort *)((int)apvStack28 + uVar5) | *(uint *)((int)param_2 + 0xc);
      *(uint *)((int)param_2 + 0xc) = uVar4;
    }
    uVar2 = (undefined2)uVar4;
    bVar6 = (int)(uVar1 << 0x1d) < 0;
    if (bVar6) {
      uVar5 = uVar5 - 2 & 0xffff;
      uVar2 = *(undefined2 *)((int)apvStack28 + uVar5);
    }
    if (bVar6) {
      *(undefined2 *)((int)param_2 + 8) = uVar2;
    }
    if ((int)(uVar1 << 0x1e) < 0) {
      uVar5 = uVar5 - 1 & 0xffff;
      *(byte *)((int)param_2 + 6) = *(byte *)((int)apvStack28 + uVar5) >> 7;
    }
    bVar6 = (int)(uVar1 << 0x1f) < 0;
    if (bVar6) {
      uVar5 = (uint)*(byte *)((int)apvStack28 + (uVar5 - 1 & 0xffff));
    }
    if (bVar6) {
      *(char *)((int)param_2 + 5) = (char)uVar5;
    }
  }
  return param_1;
}



void GENERIC_PHY_StartRx(int param_1)

{
  uint uVar1;
  int iVar2;
  CORE_irqState_t irqState;
  
  if (param_1 != 0) {
    write_volatile_4(FRC->WCNTCMP0,param_1 - 1);
  }
  iVar2 = BUFC_RxBufferGet();
  if ((iVar2 == 0) && (*(code **)(currentCallbacks + 0x54) != FUN_00000000)) {
    (**(code **)(currentCallbacks + 0x54))();
    BUFC_RxBufferSet();
  }
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 & 0xffffffbf);
  CORE_ExitCritical(irqState);
  BUS_RegMaskedSet(&RAC->RXENSRCEN,2);
  return;
}



void GENERIC_PHY_ChannelSet(uint8_t channel)

{
  SYNTH_ChannelSet(channel,1);
  return;
}



void GENERIC_PHY_SeqAtomicLock(void)

{
  uint uVar1;
  
  read_volatile(RAC->SR0._0_1_);
  BUS_RegMaskedSet(&RAC->SR0,4);
  while (uVar1 = (RAC->SR0), (int)(uVar1 << 0xd) < 0) {
    BUS_RegMaskedClear(&RAC->SR0,4);
    PROTIMER_DelayUs(2);
    BUS_RegMaskedSet(&RAC->SR0,4);
  }
  return;
}



void GENERIC_PHY_RadioIdle(int param_1,int param_2,int param_3)

{
  uint uVar1;
  bool bVar2;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  if ((param_1 != 0) || (param_2 != 0)) {
    do {
      uVar1 = (RAC->STATUS);
      if ((uVar1 << 4) >> 0x1c != 3) break;
      uVar1 = (SEQ->REG064);
    } while ((uVar1 & 0xf) != 3);
    if (param_2 != 0) {
      GENERIC_PHY_SeqAtomicLock();
      BUS_RegMaskedSet(&RAC->CTRL,1);
      BUS_RegMaskedClear(&RAC->SR0,4);
      while (uVar1 = (RAC->STATUS), (uVar1 & 0xf000000) != 0) {
        write_volatile_4(RAC->CMD,0x40);
      }
    }
  }
  BUS_RegMaskedClear(&RAC->SR0,0x80);
  bVar2 = PROTIMER_CCTimerIsEnabled(3);
  if (bVar2 != false) {
    PROTIMER_CCTimerStop(3);
    PROTIMER_CCTimerStop(4);
  }
  PROTIMER_ClearRxEnable();
  PROTIMER_ClearTxEnable();
  GENERIC_PHY_SeqAtomicLock();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 | 0x40);
  BUS_RegMaskedClear(&RAC->RXENSRCEN,0xff);
  write_volatile_4(RAC->CMD,0x100);
  BUS_RegMaskedClear(&RAC->SR0,4);
  if (param_1 != 0) {
    RADIO_RACRxAbort();
    write_volatile_4(RAC->CMD,0x20);
    PROTIMER_LBTStop();
    PROTIMER_CCTimerStop(4);
  }
  if (param_2 != 0) {
    BUFC_RxBufferReset();
    BUS_RegMaskedClear(&RAC->CTRL,1);
    if (param_3 != 0) {
      uVar1 = (FRC->IEN);
      write_volatile_4(FRC->IFC,uVar1);
      uVar1 = (RAC->IEN);
      write_volatile_4(RAC->IFC,uVar1);
      uVar1 = (MODEM->IEN);
      write_volatile_4(MODEM->IFC,uVar1);
      uVar1 = (SYNTH->IEN);
      write_volatile_4(SYNTH->IFC,uVar1);
      uVar1 = (BUFC->IEN);
      write_volatile_4(BUFC->IFC,uVar1);
      uVar1 = (AGC->IEN);
      write_volatile_4(AGC->IFC,uVar1);
      write_volatile_4(PROTIMER->IFC,0x2f00050);
      pendedRxWindowEnd = 0;
    }
  }
  CORE_ExitCritical(irqState);
  return;
}



void GENERIC_PHY_FRC_IRQCallback(void)

{
  uint uVar1;
  uint16_t uVar2;
  CORE_irqState_t irqState;
  int iVar3;
  RAC_SET *pRVar4;
  uint uVar5;
  
  irqState = CORE_EnterCritical();
  GENERIC_PHY_SeqAtomicLock();
  uVar5 = (FRC->IF);
  uVar1 = (SEQ->REG068);
  write_volatile_4(SEQ->REG068,uVar1 | uVar5);
  BUS_RegMaskedClear(&RAC->SR0,4);
  CORE_ExitCritical(irqState);
  uVar1 = (FRC->IEN);
  uVar5 = uVar5 & uVar1;
  write_volatile_4(FRC->IFC,uVar5);
  if ((int)(uVar5 << 0x1b) < 0) {
    (*currentCallbacks[2])();
    iVar3 = BUFC_RxBufferPacketAvailable();
    if (iVar3 != 0) {
      write_volatile_4(FRC->IFS,0x10);
    }
  }
  else {
    if ((int)(uVar5 << 0x19) < 0) {
      uVar1 = (FRC->IF);
      if ((((int)(uVar1 << 0x1b) < 0) && (uVar2 = BUFC_RxBufferBytesAvailable(), uVar2 != 0)) &&
         (uVar1 = (FRC->RXCTRL), (int)(uVar1 << 0x1e) < 0)) {
        bufcPendRxFrameError = 1;
      }
      else {
        if ((int)((uint)enabledCallbacks << 0x1c) < 0) {
          (*currentCallbacks[3])();
        }
      }
    }
  }
  if (((uVar5 & 3) != 0) && ((int)((uint)enabledCallbacks << 0x1f) < 0)) {
    (**currentCallbacks)();
  }
  if (((int)(uVar5 << 0x17) < 0) &&
     (uVar1 = (RAC->STATUS), (uVar1 & 0xf000000) == 0x6000000)) {
    if ((int)((uint)enabledCallbacks << 0x1b) < 0) {
      (*currentCallbacks[4])();
    }
    iVar3 = BUFC_RxBufferPacketAvailable();
    if (iVar3 == 0) {
      uVar1 = (RAC->SR0);
      if ((uVar1 & 0x40) == 0) {
        RADIO_FRCErrorHandle();
      }
      uVar1 = (RAC->SR0);
      if (-1 < (int)(uVar1 << 0x18)) {
        write_volatile_4(RAC->CMD,8);
        uVar1 = (SEQ->REG00C);
        if ((uVar1 & 0x200) == 0) {
          pRVar4 = (RAC_SET *)&Peripherals::RAC_CLR;
        }
        else {
          pRVar4 = &Peripherals::RAC_SET;
        }
        pRVar4->RXENSRCEN = 2;
      }
      write_volatile_4(RAC->CMD,0x40);
    }
    else {
      write_volatile_4(FRC->IFS,0x100);
    }
  }
  if (((int)(uVar5 << 0x1d) < 0) &&
     (uVar1 = (FRC->CTRL), -1 < (int)(uVar1 << 0x1f))) {
    (*currentCallbacks[1])(8);
  }
  if ((int)(uVar5 << 0x1c) < 0) {
    (*currentCallbacks[1])(2);
  }
  if ((int)(uVar5 << 0x11) < 0) {
    (*currentCallbacks[7])();
  }
  if ((int)(uVar5 << 0x12) < 0) {
    (*currentCallbacks[8])();
  }
  if (((pendedRxWindowEnd != '\0') && (iVar3 = BUFC_RxBufferPacketAvailable(), iVar3 == 0)) &&
     (pendedRxWindowEnd = '\0', (int)((uint)enabledCallbacks << 0x19) < 0)) {
    (*currentCallbacks[6])(1);
  }
  if (-1 < (int)(uVar5 << 0x1a)) {
    return;
  }
                    // WARNING: Could not recover jumptable at 0x000123d8. Too many branches
                    // WARNING: Treating indirect jump as call
  (*currentCallbacks[5])();
  return;
}



uint32_t GENERIC_PHY_PreviousTxTime(void)

{
  uint uVar1;
  
  uVar1 = (PROTIMER->CC1_WRAP);
  return uVar1;
}



void GENERIC_PHY_RACConfig(void)

{
  RADIO_SeqInit(&genericSeqProg,0x3bb);
  memset(&SEQ,0,100);
  write_volatile_4(RAC->SR0,0);
  write_volatile_4(RAC->SR1,0);
  write_volatile_4(RAC->SR2,0);
  TEMPCAL_Init();
  return;
}



void GENERIC_PHY_DirectModeConfig(byte *param_1)

{
  uint uVar1;
  
  if (param_1 != (byte *)0x0) {
    RADIOCMU_ClockEnable(0x67400,1);
    CMU_ClockEnable(cmuClock_GPIO,true);
    uVar1 = (uint)*param_1;
    BUS_RegMaskedClear(&MODEM->CTRL2,0xc00);
    if (uVar1 == 0) {
      BUS_RegMaskedSet(&MODEM->CTRL2,0);
    }
    else {
      uVar1 = (uint)param_1[4];
      if (uVar1 == 0) {
        BUS_RegMaskedSet(&MODEM->CTRL2,0x800);
      }
      else {
        BUS_RegMaskedSet(&MODEM->CTRL2,0xc00);
        uVar1 = 4;
      }
      uVar1 = uVar1 | 1;
    }
    if (param_1[1] != 0) {
      BUS_RegMaskedClear(&MODEM->CTRL2,0x200);
      if (param_1[3] == 0) {
        BUS_RegMaskedSet(&MODEM->CTRL2,0x200);
      }
      else {
        BUS_RegMaskedSet(&MODEM->CTRL2,0);
        uVar1 = uVar1 | 4;
      }
      uVar1 = uVar1 | 2;
    }
    if (param_1[2] == 0) {
      BUS_RegMaskedClear(&MODEM->CTRL2,0x100);
    }
    else {
      BUS_RegMaskedSet(&MODEM->CTRL2,0x100);
    }
    write_volatile_4(MODEM->ROUTELOC0,
                     (uint)param_1[8] << 0x10 | (uint)param_1[5] << 8 | (uint)param_1[0xb]);
    BUS_RegMaskedClear(&MODEM->ROUTEPEN,7);
    BUS_RegMaskedSet(&MODEM->ROUTEPEN,uVar1);
    if ((int)(uVar1 << 0x1f) < 0) {
      GPIO_PinModeSet(param_1[0xc],(uint)param_1[0xd],gpioModeInput,0);
    }
    if ((int)(uVar1 << 0x1e) < 0) {
      GPIO_PinModeSet(param_1[6],(uint)param_1[7],gpioModePushPull,0);
    }
    if ((int)(uVar1 << 0x1d) < 0) {
      GPIO_PinModeSet(param_1[9],(uint)param_1[10],gpioModePushPull,0);
      return;
    }
  }
  return;
}



void GENERIC_PHY_ResetPacketConfig(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 & 0xfffffff8);
  CORE_ExitCritical(irqState);
  BUS_RegMaskedClear(&FRC->DFLCTRL,7);
  BUS_RegMaskedSet(&FRC->DFLCTRL,0);
  return;
}



void GENERIC_PHY_ConfigureFrameType(RAIL_FrameType_t *frameType)

{
  char cVar1;
  CORE_irqState_t CVar2;
  uint uVar3;
  uint uVar4;
  
  if (frameType == (RAIL_FrameType_t *)0x0) {
    CVar2 = CORE_EnterCritical();
    uVar3 = (SEQ->REG000);
    write_volatile_4(SEQ->REG000,uVar3 & 0xfffffff8);
    CORE_ExitCritical(CVar2);
    write_volatile_4(SEQ->REG05C,0);
    write_volatile_4(SEQ->REG060,0);
    return;
  }
  GENERIC_PHY_ResetPacketConfig();
  write_volatile_1(SEQ->REG05C._0_1_,frameType->offset);
  write_volatile_1(SEQ->REG05C._1_1_,frameType->mask);
  uVar4 = 0;
  write_volatile_1(SEQ->REG05C._2_1_,0);
  write_volatile_4(SEQ->REG060,(uint)frameType->frameLen);
  uVar3 = 0;
  do {
    if (frameType->isValid[uVar4] != '\0') {
      uVar3 = uVar3 | 1 << (uVar4 & 0xff) & 0xffU;
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 != 8);
  write_volatile_1(SEQ->REG05C._3_1_,(char)uVar3);
  uVar3 = (uint)frameType->mask;
  if (uVar3 != 0) {
    while (-1 < (int)(uVar3 << 0x1f)) {
      cVar1 = read_volatile_1(SEQ->REG05C._2_1_);
      uVar3 = uVar3 >> 1;
      write_volatile_1(SEQ->REG05C._2_1_,cVar1 + '\x01');
    }
  }
  write_volatile_4(FRC->WCNTCMP0,frameType->offset + 1);
  CVar2 = CORE_EnterCritical();
  uVar3 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar3 | 7);
  CORE_ExitCritical(CVar2);
  return;
}



bool GENERIC_PHY_EnableAddressFiltering(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 | 0x10);
  CORE_ExitCritical(irqState);
  return SUB41((uVar1 << 0x1b) >> 0x1f,0);
}



bool GENERIC_PHY_DisableAddressFiltering(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 & 0xffffffef);
  CORE_ExitCritical(irqState);
  return SUB41((uVar1 << 0x1b) >> 0x1f,0);
}



bool GENERIC_PHY_IsEnabledAddressFiltering(void)

{
  uint uVar1;
  
  uVar1 = (SEQ->REG000);
  return SUB41((uVar1 << 0x1b) >> 0x1f,0);
}



void GENERIC_PHY_ResetAddressFiltering(void)

{
  memset(&SEQ->REG010,0,0x4c);
  addressFilterMatchTable = 0;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined GENERIC_PHY_Init(void)

{
  bool bVar1;
  
  RADIO_Init();
  _DAT_e000e280 = 0x40000000;
  _DAT_e000e180 = 0x40000000;
  GENERIC_PHY_RACConfig();
  RADIO_PTI_Enable();
  BUS_RegMaskedClear(&RAC->CTRL,1);
  RADIO_RegisterIrqCallback(1,0x12281);
  RADIO_RegisterIrqCallback(2,0x11945);
  RADIO_RegisterIrqCallback(5,0x11855);
  RADIO_RegisterIrqCallback(7,0x119f1);
  RADIO_RegisterIrqCallback(9,0x11995);
  GENERIC_PHY_ResetAddressFiltering();
  PROTIMER_Init();
  PROTIMER_Start();
  TIMING_InitStimer();
  TIMING_RxSearchTimeSet(0);
  TIMING_TxToRxSearchTimeSet(0);
  TIMING_RxWarmTimeSet(100);
  TIMING_TxToRxTimeSet(100);
  TIMING_TxToTxTimeSet(100);
  TIMING_RxToTxTimeSet(100);
  TIMING_RxFrameToTxTimeSet(100);
  TIMING_TxWarmTimeSet(100);
  PROTIMER_CCTimerCapture(0,0xc00000);
  PROTIMER_CCTimerCapture(1,0x200000);
  bVar1 = RFRAND_SeedProtimerRandom();
  return bVar1;
}



bool GENERIC_PHY_ConfigureAddressFiltering(RAIL_AddrConfig_t *addrConfig)

{
  GENERIC_PHY_ResetAddressFiltering();
  if (addrConfig == (RAIL_AddrConfig_t *)0x0) {
    return true;
  }
  write_volatile_1(SEQ->REG054._0_1_,addrConfig->numFields);
  if (*(byte *)&addrConfig->field_0x2 < 9) {
    write_volatile_1(SEQ->REG054._2_1_,*(byte *)&addrConfig->field_0x2);
    write_volatile_1(SEQ->REG054._1_1_,*(undefined *)&addrConfig->field_0x1);
    if (*(byte *)&addrConfig->field_0x3 < 9) {
      write_volatile_1(SEQ->REG054._3_1_,*(byte *)&addrConfig->field_0x3);
      write_volatile_1(SEQ->REG058._2_1_,*(undefined *)&addrConfig->sizes);
      addressFilterMatchTable = addrConfig->offsets;
      GENERIC_PHY_SetAddressFilteringMatchTable();
      return true;
    }
  }
  return false;
}



bool GENERIC_PHY_EnableAddress(uint8_t field,uint8_t index)

{
  uint uVar1;
  
  uVar1 = (uint)field;
  if ((uVar1 < 2) && (index < 4)) {
    *(byte *)((int)&SEQ->REG058 + uVar1) =
         (byte)(1 << (uint)index) | *(byte *)((int)&SEQ->REG058 + uVar1);
    GENERIC_PHY_SetAddressFilteringMatchTable();
    return true;
  }
  return false;
}



bool GENERIC_PHY_DisableAddress(uint8_t field,uint8_t index)

{
  uint uVar1;
  
  uVar1 = (uint)field;
  if ((uVar1 < 2) && (index < 4)) {
    *(byte *)((int)&SEQ->REG058 + uVar1) =
         *(byte *)((int)&SEQ->REG058 + uVar1) & ~(byte)(1 << (uint)index);
    GENERIC_PHY_SetAddressFilteringMatchTable();
    return true;
  }
  return false;
}



undefined4
GENERIC_PHY_SetAddressData
          (uint param_1,uint param_2,uint param_3,uint param_4,byte param_5,byte *param_6)

{
  uint *puVar1;
  uint uVar2;
  byte *pbVar3;
  
  uVar2 = (uint)param_5;
  if ((((param_1 < 2) && (param_2 < 2)) && (param_4 < uVar2)) &&
     (((uVar2 < 9 && (param_3 < 4)) && (param_6 != (byte *)0x0)))) {
    GENERIC_PHY_DisableAddress((uint8_t)param_1,(uint8_t)param_3);
    puVar1 = (uint *)((param_4 + 0x84003c5 + param_2 * 8) * 4);
    for (pbVar3 = param_6; (int)(pbVar3 + (param_4 - (int)param_6)) < (int)uVar2;
        pbVar3 = pbVar3 + 1) {
      *puVar1 = (uint)*pbVar3 << (param_3 << 3 & 0xff) | *puVar1 & ~(0xff << (param_3 << 3 & 0xff));
      puVar1 = puVar1 + 1;
    }
    return 1;
  }
  return 0;
}



int GENERIC_PHY_SetIeeePanId(uint param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = GENERIC_PHY_SetAddressData(0,0,param_1,0,2,param_2);
  if (iVar2 != 0) {
    if (param_1 < 4) {
      bVar1 = read_volatile_1(SEQ->REG058._0_1_);
      write_volatile_1(SEQ->REG058._0_1_,(byte)(1 << (param_1 & 0xff)) | bVar1);
    }
    else {
      iVar2 = 0;
    }
  }
  return iVar2;
}



bool GENERIC_PHY_SetIeeeShortAddress(uint16_t addr)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (uint)addr;
  iVar3 = GENERIC_PHY_SetAddressData(1,0,uVar2,2,4);
  if (iVar3 != 0) {
    if (uVar2 < 4) {
      bVar1 = read_volatile_1(SEQ->REG058._1_1_);
      write_volatile_1(SEQ->REG058._1_1_,(byte)(1 << (uVar2 & 0xff)) | bVar1);
    }
    else {
      iVar3 = 0;
    }
  }
  return SUB41(iVar3,0);
}



bool GENERIC_PHY_SetIeeeLongAddress(uint param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = GENERIC_PHY_SetAddressData(1,1,param_1,0,8,param_2);
  if (iVar2 != 0) {
    if (param_1 < 4) {
      bVar1 = read_volatile_1(SEQ->REG058._1_1_);
      write_volatile_1(SEQ->REG058._1_1_,(byte)(1 << (param_1 & 0xff)) | bVar1);
    }
    else {
      iVar2 = 0;
    }
  }
  return SUB41(iVar2,0);
}



bool GENERIC_PHY_SetAddress(uint8_t field,uint8_t index,uint8_t *value,bool enable)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (uint)field;
  iVar3 = GENERIC_PHY_SetAddressData
                    (uVar2,uVar2,index,0,*(undefined *)((int)&SEQ->REG054 + uVar2 + 2),
                     value);
  if ((enable != false) && (iVar3 != 0)) {
    bVar1 = GENERIC_PHY_EnableAddress(field,index);
    return bVar1;
  }
  return SUB41(iVar3,0);
}



bool GENERIC_PHY_EnableIEEE802154(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 | 0x80);
  CORE_ExitCritical(irqState);
  return (bool)((byte)uVar1 >> 7);
}



bool GENERIC_PHY_IsEnabledIEEE802154(void)

{
  uint uVar1;
  
  uVar1 = (SEQ->REG000);
  return (bool)((byte)uVar1 >> 7);
}



bool GENERIC_PHY_TimerStart(uint32_t time,RAIL_TimeMode_t mode)

{
  bool bVar1;
  
  bVar1 = PROTIMER_CCTimerStart(2,time,mode);
  return bVar1;
}



void GENERIC_PHY_TimerStop(void)

{
  PROTIMER_CCTimerStop(2);
  return;
}



uint32_t GENERIC_PHY_TimerGetTimeout(void)

{
  uint32_t uVar1;
  
  uVar1 = PROTIMER_GetCCTime(2);
  return uVar1;
}



bool GENERIC_PHY_TimerExpired(void)

{
  uint uVar1;
  
  uVar1 = (PROTIMER->IF);
  return SUB41((uVar1 << 0x15) >> 0x1f,0);
}



bool GENERIC_PHY_TimerIsRunning(void)

{
  bool bVar1;
  
  bVar1 = PROTIMER_CCTimerIsEnabled(2);
  return bVar1;
}



bool GENERIC_PHY_CanModifyAck(void)

{
  uint uVar1;
  
  uVar1 = (RAC->STATUS);
  uVar1 = (uVar1 << 4) >> 0x1c;
  if (1 < uVar1 - 2) {
    return uVar1 == 7;
  }
  return true;
}



uint32_t RFHAL_802154SetPhyforChan(uint32_t channel)

{
  byte bVar1;
  undefined1 *radioConfig;
  
  if (channel == 0xd) {
    radioConfig = &ieee802154_config_2415MHz_min;
  }
  else {
    radioConfig = &ieee802154_config_base_min;
    if (channel == 0xe) {
      radioConfig = &ieee802154_config_2420MHz_min;
    }
  }
  if (radioConfig != prevRadioCfg) {
    bVar1 = RAIL_RadioConfig(&ieee802154_config_base_min);
    channel = (uint32_t)bVar1;
    if (radioConfig != &ieee802154_config_base_min) {
      bVar1 = RAIL_RadioConfig(radioConfig);
      channel = (uint32_t)bVar1;
    }
  }
  prevRadioCfg = radioConfig;
  return channel;
}



bool RFHAL_IEEE802154Enable(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 | 0x80);
  CORE_ExitCritical(irqState);
  return (bool)((byte)uVar1 >> 7);
}



bool RFHAL_IEEE802154IsEnabled(void)

{
  uint uVar1;
  
  uVar1 = (SEQ->REG000);
  return (bool)((byte)uVar1 >> 7);
}



RAIL_Status_t RFHAL_IEEE802154RadioConfig2p4GHz(void)

{
  RAIL_RadioConfig(&ieee802154_config_base);
  RFHAL_SetProtocolSpecificChCheckCB(0x129b1);
  prevRadioCfg = &ieee802154_config_base_min;
  return RAIL_STATUS_NO_ERROR;
}



byte RFHAL_IEEE802154SetBroadcastAddresses(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  bool bVar2;
  undefined4 local_c;
  
  local_c = CONCAT22((short)((uint)param_2 >> 0x10),0xffff);
  bVar1 = GENERIC_PHY_SetIeeePanId(0,&local_c,param_3,0xffff,param_1);
  bVar2 = GENERIC_PHY_SetIeeeShortAddress(0);
  return bVar2 & bVar1;
}



bool RFHAL_IEEE802154SetPanId(uint16_t panId)

{
  undefined uVar1;
  uint in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  uint local_c [3];
  
  local_c[0] = in_r1 & 0xffff0000 | (uint)panId;
  uVar1 = GENERIC_PHY_SetIeeePanId(1,local_c,in_r2,in_r3,panId);
  return (bool)uVar1;
}



bool RFHAL_IEEE802154SetShortAddress(uint16_t shortAddr)

{
  bool bVar1;
  
  bVar1 = GENERIC_PHY_SetIeeeShortAddress(1);
  return bVar1;
}



bool RFHAL_IEEE802154SetLongAddress(uint8_t *longAddr)

{
  bool bVar1;
  
  bVar1 = GENERIC_PHY_SetIeeeLongAddress(1,longAddr);
  return bVar1;
}



RAIL_Status_t RFHAL_IEEE802154SetPromiscuousMode(bool enable)

{
  CORE_irqState_t irqState;
  uint uVar1;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  if (enable == false) {
    uVar1 = uVar1 & 0xfffeffff;
  }
  else {
    uVar1 = uVar1 | 0x10000;
  }
  write_volatile_4(SEQ->REG000,uVar1);
  CORE_ExitCritical(irqState);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RFHAL_IEEE802154SetPanCoordinator(bool isPanCoordinator)

{
  CORE_irqState_t irqState;
  uint uVar1;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  if (isPanCoordinator == false) {
    uVar1 = uVar1 & 0xff7fffff;
  }
  else {
    uVar1 = uVar1 | 0x800000;
  }
  write_volatile_4(SEQ->REG000,uVar1);
  CORE_ExitCritical(irqState);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RFHAL_IEEE802154AcceptFrames(uint8_t framesMask)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 & 0xffe1ffff | (uint)framesMask << 0x11);
  CORE_ExitCritical(irqState);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RFHAL_IEEE802154SetFramePending(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = GENERIC_PHY_CanModifyAck();
  uVar3 = 2;
  if (iVar2 != 0) {
    BUS_RegMaskedSet(&RAC->SR0,2);
    uVar1 = (RAC->SR0);
    if ((uVar1 & 0x20000) == 0) {
      BUS_RegMaskedSet(&RAC->SR2,0x10);
      uVar3 = uVar1 & 0x20000;
    }
    BUS_RegMaskedClear(&RAC->SR0,2);
    return (RAIL_Status_t)uVar3;
  }
  return RAIL_STATUS_INVALID_STATE;
}



// WARNING: Could not reconcile some variable overlaps

RAIL_Status_t
RFHAL_IEEE802154LoadAck(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  RAIL_Status_t RVar1;
  undefined4 local_14;
  undefined8 local_10;
  
  local_10._0_4_ = &local_14;
  local_14 = CONCAT31((int3)((uint)param_2 >> 8),5);
  local_10._4_4_ = CONCAT31((int3)((uint)param_4 >> 8),1);
  RVar1 = RAIL_AutoAckLoadBuffer((RAIL_AutoAckData_t *)&local_10);
  return RVar1;
}



void RFHAL_BLESetPhyforChan(int param_1,int param_2)

{
  undefined1 *puVar1;
  int32_t iVar2;
  uint uVar3;
  int32_t power;
  undefined1 *radioConfig;
  
  if (param_2 != 0) {
    lastSetTxPower = RFHAL_GetCurrPowerLevel();
  }
  iVar2 = RFHAL_GetCurrPowerLevel();
  if (iVar2 < 0x65) {
    radioConfig = &ble_config_base_min;
    if (param_1 == 0x1c) {
      radioConfig = &ble_config_2458MHz_min;
    }
  }
  else {
    uVar3 = param_1 - 7U & 0xff;
    if (uVar3 < 0x17) {
      uVar3 = 1 << uVar3;
      if ((uVar3 & 0x58000b) == 0) {
        radioConfig = &ble_config_2458MHz_20dBm_min;
        if ((uVar3 & 0x200000) == 0) {
          radioConfig = &ble_config_base_20dBm_min;
        }
      }
      else {
        radioConfig = &ble_config_2416_2418_2422_2454_2456_2460_20dBm_min;
      }
    }
    else {
      radioConfig = &ble_config_base_20dBm_min;
    }
  }
  puVar1 = prevRadioCfg;
  if ((radioConfig != prevRadioCfg) &&
     (RAIL_RadioConfig(&ble_config_base_min), puVar1 = radioConfig,
     radioConfig != &ble_config_base_min)) {
    RAIL_RadioConfig(radioConfig);
  }
  prevRadioCfg = puVar1;
  iVar2 = RFHAL_GetCurrPowerLevel();
  if (param_1 == 0x1b) {
    power = 0x96;
  }
  else {
    power = 300;
  }
  if ((iVar2 <= power) && (lastSetTxPower <= power)) {
    if (iVar2 != lastSetTxPower) {
      lastSetTxPower = PA_OutputPowerSet(lastSetTxPower);
    }
    return;
  }
  PA_OutputPowerSet(power);
  return;
}



bool RFHAL_Ble2MbpsSet(void)

{
  return false;
}



bool RFHAL_Ble1MbpsSet(void)

{
  uint32_t uVar1;
  uint uVar2;
  
  RAIL_RadioConfig(&ble_config_base);
  prevRadioCfg = &ble_config_base_min;
  uVar1 = RAILInt_CompensateForDelay(10000,0);
  uVar2 = count_leading_zeroes(uVar1);
  return SUB41(uVar2 >> 5,0);
}



void RFHAL_BleInit(void)

{
  TIMING_TxToRxSearchTimeSet(0x46);
  RFHAL_SetProtocolSpecificChCheckCB(0x12b5d);
  RFHAL_Ble1MbpsSet();
  RAIL_ChannelConfig((RAIL_ChannelConfig_t *)&bleChannelConfig);
  lastSetTxPower = RFHAL_GetCurrPowerLevel();
  return;
}



void RFHAL_BleDeinit(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 extraout_r1;
  
  RFHAL_SetProtocolSpecificChCheckCB(0);
  TIMING_TxToRxSearchTimeSet(0,extraout_r1,param_3,param_4);
  return;
}



void RFHAL_BLEPreambleSyncWordSet(int param_1,uint param_2)

{
  uint uVar1;
  
  write_volatile_4(MODEM->SYNC0,param_2);
  uVar1 = (MODEM->PRE);
  if (param_1 == 0x55) {
    uVar1 = uVar1 & 0xfffffff0 | 1;
  }
  else {
    uVar1 = uVar1 & 0xfffffff0 | 2;
  }
  write_volatile_4(MODEM->PRE,uVar1);
  return;
}



void RFHAL_BLEWhiteningSet(uint32_t poly,uint32_t init,bool enable)

{
  bool bVar1;
  
  write_volatile_4(FRC->WHITEPOLY,poly);
  write_volatile_4(FRC->WHITEINIT,init);
  bVar1 = enable == false;
  if (bVar1) {
    write_volatile_4(FRC->FECCTRL,0);
  }
  else {
    write_volatile_4(FRC->FECCTRL,1);
    enable = false;
  }
  RADIO_FrameDescsConfig(bVar1,enable,1,1);
  return;
}



void AUXPLL_AuxSettingsPllLoopback(void)

{
  uint uVar1;
  
  uVar1 = (RAC->AUXCTRL);
  write_volatile_4(RAC->AUXCTRL,uVar1 | 0x3000000);
  BUS_RegMaskedSet(&RAC->SGLNAMIXCTRL,0x4000000);
  return;
}



void AUXPLL_AuxSettingsPaLoopback(void)

{
  BUS_RegMaskedClear(&RAC->SYNTHCTRL,4);
  BUS_RegMaskedSet(&RAC->AUXENCTRL,4);
  return;
}



void AUXPLL_Stop(void)

{
  BUS_RegMaskedClear(&RAC->AUXCTRL,0x8007ca);
  BUS_RegMaskedClear(&RAC->AUXENCTRL,1);
  BUS_RegMaskedClear(&RAC->SGLNAMIXCTRL,0x4000000);
  BUS_RegMaskedClear(&RAC->AUXENCTRL,4);
  return;
}



undefined AUXPLL_ConvertAuxLoDivToRegVal(int param_1)

{
  undefined uVar1;
  
  if (param_1 - 2U < 0x17) {
    uVar1 = (&UNK_0001cbc2)[param_1];
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



void AUXPLL_Configure(uint param_1,undefined4 param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  
  BUS_RegMaskedClear(&RAC->AUXENCTRL,1);
  uVar1 = (RAC->AUXCTRL);
  write_volatile_4(RAC->AUXCTRL,uVar1 & 0xff01ffcf | 0xe80030);
  uVar1 = (SYNTH->DIVCTRL);
  iVar2 = AUXPLL_ConvertAuxLoDivToRegVal(param_2);
  write_volatile_4(SYNTH->DIVCTRL,uVar1 & 0xffc0ffff | iVar2 << 0x10);
  uVar1 = (RAC->AUXCTRL);
  write_volatile_4(RAC->AUXCTRL,uVar1 & 0xfffe00ff | param_4 << 0xb | param_3 << 8);
  uVar1 = (SYNTH->AUXFREQ);
  write_volatile_4(SYNTH->AUXFREQ,uVar1 & 0xffffff80 | param_1);
  BUS_RegMaskedSet(&RAC->AUXCTRL,0x4a);
  BUS_RegMaskedSet(&RAC->AUXENCTRL,1);
  BUS_RegMaskedSet(&RAC->AUXCTRL,0x80);
  BUS_RegMaskedSet(&RAC->AUXCTRL,0x800000);
  BUS_RegMaskedSet(&SYNTH->AUXVCDACCTRL,0x10);
  BUS_RegMaskedClear(&RAC->AUXCTRL,8);
  BUS_RegMaskedSet(&RAC->AUXCTRL,0x800004);
  PHY_UTILS_DelayUs(1000);
  do {
    write_volatile_4(SYNTH->CMD,0x80);
    write_volatile_4(SYNTH->CMD,0x100);
    do {
      uVar1 = (SYNTH->STATUS);
    } while ((int)(uVar1 << 0x14) < 0);
    uVar1 = (SYNTH->STATUS);
  } while ((int)(uVar1 << 0x11) < 0);
  BUS_RegMaskedSet(&RAC->AUXCTRL,8);
  write_volatile_4(Peripherals::SYNTH_CLR.AUXVCDACCTRL,0x10);
  write_volatile_4(SYNTH->CMD,0x40);
  uVar1 = (RAC->AUXCTRL);
  write_volatile_4(RAC->AUXCTRL,uVar1 & 0xff7ffffb | 0x800000);
  return;
}



int AUXPLL_Start(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  uint32_t uVar1;
  int iVar2;
  
  uVar1 = SystemHFXOClockGet();
  iVar2 = param_3 * (uVar1 / param_4);
  if (iVar2 != -1) {
    AUXPLL_Configure(param_3,param_4,param_1,param_2);
    if (param_1 == 2) {
      AUXPLL_AuxSettingsPllLoopback();
    }
    else {
      if (param_1 != 3) {
        AUXPLL_Stop();
        return -1;
      }
      AUXPLL_AuxSettingsPaLoopback();
    }
  }
  return iVar2;
}



void __aeabi_drsub(undefined4 param_1,uint param_2)

{
  __aeabi_dadd(param_1,param_2 ^ 0x80000000);
  return;
}



ulonglong __subdf3(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  
  uVar6 = param_4 ^ 0x80000000;
  uVar9 = param_2 << 1;
  param_4 = param_4 << 1;
  bVar13 = ((param_2 ^ uVar6) & 0x7fffffff) == 0;
  bVar14 = bVar13 && param_1 == param_3;
  if (!bVar13 || param_1 != param_3) {
    bVar14 = (uVar9 | param_1) == 0;
  }
  if (!bVar14) {
    bVar14 = (param_4 | param_3) == 0;
  }
  iVar8 = (int)uVar9 >> 0x15;
  if (!bVar14) {
    bVar14 = iVar8 == -1;
  }
  iVar1 = (int)param_4 >> 0x15;
  if (!bVar14) {
    bVar14 = iVar1 == -1;
  }
  if (bVar14) {
    if (iVar8 == -1 || iVar1 == -1) {
      uVar9 = uVar6;
      uVar11 = param_3;
      if (iVar8 == -1) {
        uVar9 = param_2;
        uVar11 = param_1;
      }
      if (iVar8 != -1 || iVar1 != -1) {
        param_3 = uVar11;
        uVar6 = uVar9;
      }
      bVar14 = (uVar11 | uVar9 << 0xc) == 0;
      if (bVar14) {
        bVar14 = (param_3 | uVar6 << 0xc) == 0;
      }
      if (bVar14) {
        bVar14 = uVar9 == uVar6;
      }
      if (!bVar14) {
        uVar9 = uVar9 | 0x80000;
      }
      return CONCAT44(uVar9,uVar11);
    }
    if (((param_2 ^ uVar6) & 0x7fffffff) != 0 || param_1 != param_3) {
      if ((uVar9 | param_1) == 0) {
        param_1 = param_3;
        param_2 = uVar6;
      }
      return CONCAT44(param_2,param_1);
    }
    if (param_2 != uVar6) {
      return 0;
    }
    if (uVar9 >> 0x15 == 0) {
      bVar14 = (param_1 & 0x80000000) != 0;
      uVar6 = param_2 * 2 + (uint)bVar14;
      if (!bVar14 && CARRY4(param_2,param_2) || bVar14 && param_2 * 2 + 1 <= param_2) {
        uVar6 = uVar6 | 0x80000000;
      }
      return CONCAT44(uVar6,param_1 << 1);
    }
    if (uVar9 < 0xffc00000) {
      return CONCAT44(param_2 + 0x100000,param_1);
    }
    param_2 = param_2 & 0x80000000;
LAB_000130d8:
    return (ulonglong)(param_2 | 0x7ff00000) << 0x20;
  }
  uVar9 = uVar9 >> 0x15;
  param_4 = param_4 >> 0x15;
  uVar11 = param_4 - uVar9;
  bVar14 = uVar11 != 0;
  if (param_4 < uVar9) {
    uVar11 = -uVar11;
  }
  uVar10 = param_1;
  uVar7 = param_2;
  if (bVar14 && uVar9 <= param_4) {
    uVar9 = uVar9 + uVar11;
    uVar10 = param_3;
    uVar7 = uVar6;
    param_3 = param_1;
    uVar6 = param_2;
  }
  if (0x36 < uVar11) {
    return CONCAT44(uVar7,uVar10);
  }
  uVar4 = uVar7 & 0xfffff | 0x100000;
  if ((uVar7 & 0x80000000) != 0) {
    bVar14 = uVar10 != 0;
    uVar10 = -uVar10;
    uVar4 = -uVar4 - (uint)bVar14;
  }
  uVar7 = uVar6 & 0xfffff | 0x100000;
  if ((uVar6 & 0x80000000) != 0) {
    bVar14 = param_3 != 0;
    param_3 = -param_3;
    uVar7 = -uVar7 - (uint)bVar14;
  }
  if (uVar9 == uVar11) {
    uVar7 = uVar7 ^ 0x100000;
    if (uVar9 == 0) {
      uVar4 = uVar4 ^ 0x100000;
      uVar9 = 1;
    }
    else {
      uVar11 = uVar11 - 1;
    }
  }
  uVar6 = -uVar11 + 0x20;
  if ((int)uVar11 < 0x21) {
    uVar12 = param_3 << (uVar6 & 0xff);
    param_3 = param_3 >> (uVar11 & 0xff);
    uVar3 = uVar10 + param_3;
    uVar5 = uVar7 << (uVar6 & 0xff);
    uVar6 = uVar3 + uVar5;
    uVar4 = uVar4 + CARRY4(uVar10,param_3) + ((int)uVar7 >> (uVar11 & 0xff)) +
            (uint)CARRY4(uVar3,uVar5);
  }
  else {
    uVar12 = uVar7 << (-uVar11 + 0x40 & 0xff);
    if (param_3 != 0) {
      uVar12 = uVar12 | 2;
    }
    uVar7 = (int)uVar7 >> (uVar11 - 0x20 & 0xff);
    uVar6 = uVar10 + uVar7;
    uVar4 = uVar4 + ((int)uVar7 >> 0x1f) + (uint)CARRY4(uVar10,uVar7);
  }
  param_2 = uVar4 & 0x80000000;
  uVar11 = uVar4;
  if ((int)uVar4 < 0) {
    bVar13 = uVar12 != 0;
    uVar12 = -uVar12;
    bVar14 = uVar6 != 0;
    uVar6 = -(uint)bVar13 - uVar6;
    uVar11 = -(uint)(bVar13 || bVar14) - uVar4;
  }
  if (0xfffff < uVar11) {
    uVar10 = uVar9 - 1;
    if (0x1fffff < uVar11) {
      uVar10 = uVar11 & 1;
      uVar11 = uVar11 >> 1;
      bVar2 = (byte)uVar6;
      uVar6 = (uint)(uVar10 != 0) << 0x1f | uVar6 >> 1;
      uVar12 = (uint)(bVar2 & 1) << 0x1f | uVar12 >> 1;
      uVar10 = uVar9;
      if (0xffbfffff < uVar9 * 0x200000) goto LAB_000130d8;
    }
LAB_00012fa4:
    bVar14 = 0x7fffffff < uVar12;
    if (uVar12 == 0x80000000) {
      bVar14 = (uVar6 & 1) != 0;
    }
    return CONCAT44(uVar11 + uVar10 * 0x100000 + (uint)(bVar14 == true && uVar6 + 1 <= uVar6) |
                    param_2,uVar6 + bVar14);
  }
  bVar15 = (uVar12 & 0x80000000) != 0;
  uVar12 = uVar12 << 1;
  bVar14 = CARRY4(uVar6,uVar6);
  bVar13 = uVar6 * 2 + 1 <= uVar6;
  uVar6 = uVar6 * 2 + (uint)bVar15;
  uVar11 = uVar11 * 2 + (uint)(!bVar15 && bVar14 || bVar15 && bVar13);
  uVar10 = uVar9 - 2;
  if ((uVar11 & 0x100000) != 0) goto LAB_00012fa4;
  uVar7 = uVar6;
  uVar9 = uVar11;
  if (uVar11 == 0) {
    uVar7 = 0;
    uVar9 = uVar6;
  }
  iVar8 = count_leading_zeroes(uVar9);
  if (uVar11 == 0) {
    iVar8 = iVar8 + 0x20;
  }
  uVar11 = iVar8 - 0xb;
  bVar15 = SBORROW4(uVar11,0x20);
  uVar6 = iVar8 - 0x2b;
  bVar14 = (int)uVar6 < 0;
  bVar13 = uVar6 == 0;
  if ((int)uVar11 < 0x20) {
    bVar15 = SCARRY4(uVar6,0xc);
    iVar8 = iVar8 + -0x1f;
    bVar14 = iVar8 < 0;
    bVar13 = iVar8 == 0;
    uVar6 = uVar11;
    if (!bVar13 && bVar14 == bVar15) {
      uVar7 = uVar9 << (uVar11 & 0xff);
      uVar9 = uVar9 >> (0xcU - iVar8 & 0xff);
      goto LAB_0001301c;
    }
  }
  if (bVar13 || bVar14 != bVar15) {
    uVar12 = 0x20 - uVar6;
  }
  uVar9 = uVar9 << (uVar6 & 0xff);
  if (bVar13 || bVar14 != bVar15) {
    uVar9 = uVar9 | uVar7 >> (uVar12 & 0xff);
  }
  if (bVar13 || bVar14 != bVar15) {
    uVar7 = uVar7 << (uVar6 & 0xff);
  }
LAB_0001301c:
  if ((int)uVar11 <= (int)uVar10) {
    return CONCAT44(uVar9 + (uVar10 - uVar11) * 0x100000 | param_2,uVar7);
  }
  uVar6 = ~(uVar10 - uVar11);
  if ((int)uVar6 < 0x1f) {
    iVar8 = uVar6 - 0x13;
    if (iVar8 != 0 && iVar8 < 0 == SCARRY4(uVar6 - 0x1f,0xc)) {
      return CONCAT44(uVar4,uVar7 >> (0x20 - (0xcU - iVar8) & 0xff) | uVar9 << (0xcU - iVar8 & 0xff)
                     ) & 0x80000000ffffffff;
    }
    uVar6 = uVar6 + 1;
    return CONCAT44(param_2 | uVar9 >> (uVar6 & 0xff),
                    uVar7 >> (uVar6 & 0xff) | uVar9 << (0x20 - uVar6 & 0xff));
  }
  return CONCAT44(uVar4,uVar9 >> (uVar6 - 0x1f & 0xff)) & 0x80000000ffffffff;
}



ulonglong __aeabi_dadd(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  
  uVar7 = param_2 << 1;
  uVar9 = param_4 << 1;
  bVar13 = ((param_2 ^ param_4) & 0x7fffffff) == 0;
  bVar14 = bVar13 && param_1 == param_3;
  if (!bVar13 || param_1 != param_3) {
    bVar14 = (uVar7 | param_1) == 0;
  }
  if (!bVar14) {
    bVar14 = (uVar9 | param_3) == 0;
  }
  iVar6 = (int)uVar7 >> 0x15;
  if (!bVar14) {
    bVar14 = iVar6 == -1;
  }
  iVar1 = (int)uVar9 >> 0x15;
  if (!bVar14) {
    bVar14 = iVar1 == -1;
  }
  if (bVar14) {
    if (iVar6 == -1 || iVar1 == -1) {
      uVar9 = param_4;
      uVar7 = param_3;
      if (iVar6 == -1) {
        uVar9 = param_2;
        uVar7 = param_1;
      }
      if (iVar6 != -1 || iVar1 != -1) {
        param_3 = uVar7;
        param_4 = uVar9;
      }
      bVar14 = (uVar7 | uVar9 << 0xc) == 0;
      if (bVar14) {
        bVar14 = (param_3 | param_4 << 0xc) == 0;
      }
      if (bVar14) {
        bVar14 = uVar9 == param_4;
      }
      if (!bVar14) {
        uVar9 = uVar9 | 0x80000;
      }
      return CONCAT44(uVar9,uVar7);
    }
    if (((param_2 ^ param_4) & 0x7fffffff) != 0 || param_1 != param_3) {
      if ((uVar7 | param_1) == 0) {
        param_1 = param_3;
        param_2 = param_4;
      }
      return CONCAT44(param_2,param_1);
    }
    if (param_2 != param_4) {
      return 0;
    }
    if (uVar7 >> 0x15 == 0) {
      bVar14 = (param_1 & 0x80000000) != 0;
      uVar9 = param_2 * 2 + (uint)bVar14;
      if (!bVar14 && CARRY4(param_2,param_2) || bVar14 && param_2 * 2 + 1 <= param_2) {
        uVar9 = uVar9 | 0x80000000;
      }
      return CONCAT44(uVar9,param_1 << 1);
    }
    if (uVar7 < 0xffc00000) {
      return CONCAT44(param_2 + 0x100000,param_1);
    }
    param_2 = param_2 & 0x80000000;
LAB_000130d8:
    return (ulonglong)(param_2 | 0x7ff00000) << 0x20;
  }
  uVar7 = uVar7 >> 0x15;
  uVar9 = uVar9 >> 0x15;
  uVar10 = uVar9 - uVar7;
  bVar14 = uVar10 != 0;
  if (uVar9 < uVar7) {
    uVar10 = -uVar10;
  }
  uVar8 = param_1;
  uVar5 = param_2;
  if (bVar14 && uVar7 <= uVar9) {
    uVar7 = uVar7 + uVar10;
    uVar8 = param_3;
    uVar5 = param_4;
    param_3 = param_1;
    param_4 = param_2;
  }
  if (0x36 < uVar10) {
    return CONCAT44(uVar5,uVar8);
  }
  uVar9 = uVar5 & 0xfffff | 0x100000;
  if ((uVar5 & 0x80000000) != 0) {
    bVar14 = uVar8 != 0;
    uVar8 = -uVar8;
    uVar9 = -uVar9 - (uint)bVar14;
  }
  uVar5 = param_4 & 0xfffff | 0x100000;
  if ((param_4 & 0x80000000) != 0) {
    bVar14 = param_3 != 0;
    param_3 = -param_3;
    uVar5 = -uVar5 - (uint)bVar14;
  }
  if (uVar7 == uVar10) {
    uVar5 = uVar5 ^ 0x100000;
    if (uVar7 == 0) {
      uVar9 = uVar9 ^ 0x100000;
      uVar7 = 1;
    }
    else {
      uVar10 = uVar10 - 1;
    }
  }
  uVar12 = -uVar10 + 0x20;
  if ((int)uVar10 < 0x21) {
    uVar11 = param_3 << (uVar12 & 0xff);
    param_3 = param_3 >> (uVar10 & 0xff);
    uVar3 = uVar8 + param_3;
    uVar4 = uVar5 << (uVar12 & 0xff);
    uVar12 = uVar3 + uVar4;
    uVar9 = uVar9 + CARRY4(uVar8,param_3) + ((int)uVar5 >> (uVar10 & 0xff)) +
            (uint)CARRY4(uVar3,uVar4);
  }
  else {
    uVar11 = uVar5 << (-uVar10 + 0x40 & 0xff);
    if (param_3 != 0) {
      uVar11 = uVar11 | 2;
    }
    uVar5 = (int)uVar5 >> (uVar10 - 0x20 & 0xff);
    uVar12 = uVar8 + uVar5;
    uVar9 = uVar9 + ((int)uVar5 >> 0x1f) + (uint)CARRY4(uVar8,uVar5);
  }
  param_2 = uVar9 & 0x80000000;
  uVar10 = uVar9;
  if ((int)uVar9 < 0) {
    bVar13 = uVar11 != 0;
    uVar11 = -uVar11;
    bVar14 = uVar12 != 0;
    uVar12 = -(uint)bVar13 - uVar12;
    uVar10 = -(uint)(bVar13 || bVar14) - uVar9;
  }
  if (0xfffff < uVar10) {
    uVar8 = uVar7 - 1;
    if (0x1fffff < uVar10) {
      uVar9 = uVar10 & 1;
      uVar10 = uVar10 >> 1;
      bVar2 = (byte)uVar12;
      uVar12 = (uint)(uVar9 != 0) << 0x1f | uVar12 >> 1;
      uVar11 = (uint)(bVar2 & 1) << 0x1f | uVar11 >> 1;
      uVar8 = uVar7;
      if (0xffbfffff < uVar7 * 0x200000) goto LAB_000130d8;
    }
LAB_00012fa4:
    bVar14 = 0x7fffffff < uVar11;
    if (uVar11 == 0x80000000) {
      bVar14 = (uVar12 & 1) != 0;
    }
    return CONCAT44(uVar10 + uVar8 * 0x100000 + (uint)(bVar14 == true && uVar12 + 1 <= uVar12) |
                    param_2,uVar12 + bVar14);
  }
  bVar15 = (uVar11 & 0x80000000) != 0;
  uVar11 = uVar11 << 1;
  bVar14 = CARRY4(uVar12,uVar12);
  bVar13 = uVar12 * 2 + 1 <= uVar12;
  uVar12 = uVar12 * 2 + (uint)bVar15;
  uVar10 = uVar10 * 2 + (uint)(!bVar15 && bVar14 || bVar15 && bVar13);
  uVar8 = uVar7 - 2;
  if ((uVar10 & 0x100000) != 0) goto LAB_00012fa4;
  uVar5 = uVar12;
  uVar7 = uVar10;
  if (uVar10 == 0) {
    uVar5 = 0;
    uVar7 = uVar12;
  }
  iVar6 = count_leading_zeroes(uVar7);
  if (uVar10 == 0) {
    iVar6 = iVar6 + 0x20;
  }
  uVar12 = iVar6 - 0xb;
  bVar15 = SBORROW4(uVar12,0x20);
  uVar10 = iVar6 - 0x2b;
  bVar14 = (int)uVar10 < 0;
  bVar13 = uVar10 == 0;
  if ((int)uVar12 < 0x20) {
    bVar15 = SCARRY4(uVar10,0xc);
    iVar6 = iVar6 + -0x1f;
    bVar14 = iVar6 < 0;
    bVar13 = iVar6 == 0;
    uVar10 = uVar12;
    if (!bVar13 && bVar14 == bVar15) {
      uVar5 = uVar7 << (uVar12 & 0xff);
      uVar7 = uVar7 >> (0xcU - iVar6 & 0xff);
      goto LAB_0001301c;
    }
  }
  if (bVar13 || bVar14 != bVar15) {
    uVar11 = 0x20 - uVar10;
  }
  uVar7 = uVar7 << (uVar10 & 0xff);
  if (bVar13 || bVar14 != bVar15) {
    uVar7 = uVar7 | uVar5 >> (uVar11 & 0xff);
  }
  if (bVar13 || bVar14 != bVar15) {
    uVar5 = uVar5 << (uVar10 & 0xff);
  }
LAB_0001301c:
  if ((int)uVar12 <= (int)uVar8) {
    return CONCAT44(uVar7 + (uVar8 - uVar12) * 0x100000 | param_2,uVar5);
  }
  uVar10 = ~(uVar8 - uVar12);
  if ((int)uVar10 < 0x1f) {
    iVar6 = uVar10 - 0x13;
    if (iVar6 != 0 && iVar6 < 0 == SCARRY4(uVar10 - 0x1f,0xc)) {
      return CONCAT44(uVar9,uVar5 >> (0x20 - (0xcU - iVar6) & 0xff) | uVar7 << (0xcU - iVar6 & 0xff)
                     ) & 0x80000000ffffffff;
    }
    uVar10 = uVar10 + 1;
    return CONCAT44(param_2 | uVar7 >> (uVar10 & 0xff),
                    uVar5 >> (uVar10 & 0xff) | uVar7 << (0x20 - uVar10 & 0xff));
  }
  return CONCAT44(uVar9,uVar7 >> (uVar10 - 0x1f & 0xff)) & 0x80000000ffffffff;
}



ulonglong __floatunsidf(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint in_r12;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar1 = 0;
  iVar3 = count_leading_zeroes(param_1);
  uVar4 = iVar3 + 0x15;
  bVar7 = SBORROW4(uVar4,0x20);
  uVar2 = iVar3 - 0xb;
  bVar5 = (int)uVar2 < 0;
  bVar6 = uVar2 == 0;
  if ((int)uVar4 < 0x20) {
    bVar7 = SCARRY4(uVar2,0xc);
    iVar3 = iVar3 + 1;
    bVar5 = iVar3 < 0;
    bVar6 = iVar3 == 0;
    uVar2 = uVar4;
    if (!bVar6 && bVar5 == bVar7) {
      uVar1 = param_1 << (uVar4 & 0xff);
      param_1 = param_1 >> (0xcU - iVar3 & 0xff);
      goto LAB_0001301c;
    }
  }
  if (bVar6 || bVar5 != bVar7) {
    in_r12 = 0x20 - uVar2;
  }
  param_1 = param_1 << (uVar2 & 0xff);
  if (bVar6 || bVar5 != bVar7) {
    param_1 = param_1 | 0U >> (in_r12 & 0xff);
  }
  if (bVar6 || bVar5 != bVar7) {
    uVar1 = 0 << (uVar2 & 0xff);
  }
LAB_0001301c:
  if ((int)uVar4 < 0x433) {
    return CONCAT44(param_1 + (0x432 - uVar4) * 0x100000,uVar1);
  }
  uVar2 = ~(0x432 - uVar4);
  if (0x1e < (int)uVar2) {
    return (ulonglong)(param_1 >> (uVar2 - 0x1f & 0xff));
  }
  iVar3 = uVar2 - 0x13;
  if (iVar3 == 0 || iVar3 < 0 != SCARRY4(uVar2 - 0x1f,0xc)) {
    uVar2 = uVar2 + 1;
    return CONCAT44(param_1 >> (uVar2 & 0xff),
                    uVar1 >> (uVar2 & 0xff) | param_1 << (0x20 - uVar2 & 0xff));
  }
  return (ulonglong)(uVar1 >> (0x20 - (0xcU - iVar3) & 0xff) | param_1 << (0xcU - iVar3 & 0xff));
}



ulonglong __aeabi_i2d(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint in_r12;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar6 = param_1 & 0x80000000;
  uVar2 = param_1;
  if ((int)uVar6 < 0) {
    uVar2 = -param_1;
  }
  uVar1 = 0;
  iVar4 = count_leading_zeroes(uVar2);
  uVar5 = iVar4 + 0x15;
  bVar9 = SBORROW4(uVar5,0x20);
  uVar3 = iVar4 - 0xb;
  bVar7 = (int)uVar3 < 0;
  bVar8 = uVar3 == 0;
  if ((int)uVar5 < 0x20) {
    bVar9 = SCARRY4(uVar3,0xc);
    iVar4 = iVar4 + 1;
    bVar7 = iVar4 < 0;
    bVar8 = iVar4 == 0;
    uVar3 = uVar5;
    if (!bVar8 && bVar7 == bVar9) {
      uVar1 = uVar2 << (uVar5 & 0xff);
      uVar2 = uVar2 >> (0xcU - iVar4 & 0xff);
      goto LAB_0001301c;
    }
  }
  if (bVar8 || bVar7 != bVar9) {
    in_r12 = 0x20 - uVar3;
  }
  uVar2 = uVar2 << (uVar3 & 0xff);
  if (bVar8 || bVar7 != bVar9) {
    uVar2 = uVar2 | 0U >> (in_r12 & 0xff);
  }
  if (bVar8 || bVar7 != bVar9) {
    uVar1 = 0 << (uVar3 & 0xff);
  }
LAB_0001301c:
  if ((int)uVar5 < 0x433) {
    return CONCAT44(uVar2 + (0x432 - uVar5) * 0x100000 | uVar6,uVar1);
  }
  uVar3 = ~(0x432 - uVar5);
  if (0x1e < (int)uVar3) {
    return CONCAT44(param_1,uVar2 >> (uVar3 - 0x1f & 0xff)) & 0x80000000ffffffff;
  }
  iVar4 = uVar3 - 0x13;
  if (iVar4 == 0 || iVar4 < 0 != SCARRY4(uVar3 - 0x1f,0xc)) {
    uVar3 = uVar3 + 1;
    return CONCAT44(uVar6 | uVar2 >> (uVar3 & 0xff),
                    uVar1 >> (uVar3 & 0xff) | uVar2 << (0x20 - uVar3 & 0xff));
  }
  return CONCAT44(param_1,uVar1 >> (0x20 - (0xcU - iVar4) & 0xff) | uVar2 << (0xcU - iVar4 & 0xff))
         & 0x80000000ffffffff;
}



ulonglong __aeabi_f2d(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint in_r12;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  
  uVar5 = param_1 << 1;
  bVar9 = uVar5 == 0;
  uVar1 = (uint)((param_1 & 0x80000000) != 0) << 0x1f;
  uVar4 = (uint)((int)uVar5 >> 3) >> 1;
  uVar3 = uVar1 | uVar4;
  param_1 = param_1 << 0x1d;
  if (!bVar9) {
    param_4 = uVar5 & 0xff000000;
    bVar9 = param_4 == 0;
  }
  if (!bVar9) {
    bVar9 = param_4 == 0xff000000;
  }
  if (!bVar9) {
    return CONCAT44(uVar3,param_1) ^ 0x3800000000000000;
  }
  if ((uVar5 & 0xffffff) == 0) {
    return CONCAT44(uVar3,param_1);
  }
  if (param_4 == 0xff000000) {
    return CONCAT44(uVar3,param_1) | 0x8000000000000;
  }
  uVar2 = param_1;
  uVar5 = uVar4;
  if (uVar4 == 0) {
    uVar2 = 0;
    uVar5 = param_1;
  }
  iVar6 = count_leading_zeroes(uVar5);
  if (uVar4 == 0) {
    iVar6 = iVar6 + 0x20;
  }
  uVar7 = iVar6 - 0xb;
  bVar10 = SBORROW4(uVar7,0x20);
  uVar4 = iVar6 - 0x2b;
  bVar9 = (int)uVar4 < 0;
  bVar8 = uVar4 == 0;
  if ((int)uVar7 < 0x20) {
    bVar10 = SCARRY4(uVar4,0xc);
    iVar6 = iVar6 + -0x1f;
    bVar9 = iVar6 < 0;
    bVar8 = iVar6 == 0;
    uVar4 = uVar7;
    if (!bVar8 && bVar9 == bVar10) {
      uVar2 = uVar5 << (uVar7 & 0xff);
      uVar5 = uVar5 >> (0xcU - iVar6 & 0xff);
      goto LAB_0001301c;
    }
  }
  if (bVar8 || bVar9 != bVar10) {
    in_r12 = 0x20 - uVar4;
  }
  uVar5 = uVar5 << (uVar4 & 0xff);
  if (bVar8 || bVar9 != bVar10) {
    uVar5 = uVar5 | uVar2 >> (in_r12 & 0xff);
  }
  if (bVar8 || bVar9 != bVar10) {
    uVar2 = uVar2 << (uVar4 & 0xff);
  }
LAB_0001301c:
  if ((int)uVar7 < 0x381) {
    return CONCAT44(uVar5 + (0x380 - uVar7) * 0x100000 | uVar1,uVar2);
  }
  uVar4 = ~(0x380 - uVar7);
  if (0x1e < (int)uVar4) {
    return CONCAT44(uVar3,uVar5 >> (uVar4 - 0x1f & 0xff)) & 0x80000000ffffffff;
  }
  iVar6 = uVar4 - 0x13;
  if (iVar6 == 0 || iVar6 < 0 != SCARRY4(uVar4 - 0x1f,0xc)) {
    uVar4 = uVar4 + 1;
    return CONCAT44(uVar1 | uVar5 >> (uVar4 & 0xff),
                    uVar2 >> (uVar4 & 0xff) | uVar5 << (0x20 - uVar4 & 0xff));
  }
  return CONCAT44(uVar3,uVar2 >> (0x20 - (0xcU - iVar6) & 0xff) | uVar5 << (0xcU - iVar6 & 0xff)) &
         0x80000000ffffffff;
}



ulonglong __floatundidf(uint param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  
  if ((param_1 | param_2) == 0) {
    return CONCAT44(param_2,param_1);
  }
  iVar7 = 0x432;
  uVar8 = param_2 >> 0x16;
  if (uVar8 != 0) {
    iVar7 = 3;
    if (param_2 >> 0x19 != 0) {
      iVar7 = 6;
    }
    if (param_2 >> 0x1c != 0) {
      iVar7 = iVar7 + 3;
    }
    uVar4 = iVar7 - ((int)param_2 >> 0x1f);
    uVar8 = param_1 << (0x20 - uVar4 & 0xff);
    param_1 = param_1 >> (uVar4 & 0xff) | param_2 << (0x20 - uVar4 & 0xff);
    param_2 = param_2 >> (uVar4 & 0xff);
    iVar7 = uVar4 + 0x432;
  }
  if (0xfffff < param_2) {
    if (0x1fffff < param_2) {
      uVar4 = param_2 & 1;
      param_2 = param_2 >> 1;
      bVar1 = (byte)param_1;
      param_1 = (uint)(uVar4 != 0) << 0x1f | param_1 >> 1;
      uVar8 = (uint)(bVar1 & 1) << 0x1f | uVar8 >> 1;
      iVar7 = iVar7 + 1;
      if (0xffbfffff < (uint)(iVar7 * 0x200000)) {
        return 0x7ff0000000000000;
      }
    }
LAB_00012fa4:
    bVar10 = 0x7fffffff < uVar8;
    if (uVar8 == 0x80000000) {
      bVar10 = (param_1 & 1) != 0;
    }
    return CONCAT44(param_2 + iVar7 * 0x100000 + (uint)(bVar10 == true && param_1 + 1 <= param_1),
                    param_1 + bVar10);
  }
  bVar11 = (uVar8 & 0x80000000) != 0;
  uVar8 = uVar8 << 1;
  bVar10 = CARRY4(param_1,param_1);
  bVar9 = param_1 * 2 + 1 <= param_1;
  param_1 = param_1 * 2 + (uint)bVar11;
  param_2 = param_2 * 2 + (uint)(!bVar11 && bVar10 || bVar11 && bVar9);
  iVar7 = iVar7 + -1;
  if ((param_2 & 0x100000) != 0) goto LAB_00012fa4;
  uVar2 = param_1;
  uVar4 = param_2;
  if (param_2 == 0) {
    uVar2 = 0;
    uVar4 = param_1;
  }
  iVar5 = count_leading_zeroes(uVar4);
  if (param_2 == 0) {
    iVar5 = iVar5 + 0x20;
  }
  uVar6 = iVar5 - 0xb;
  bVar11 = SBORROW4(uVar6,0x20);
  uVar3 = iVar5 - 0x2b;
  bVar10 = (int)uVar3 < 0;
  bVar9 = uVar3 == 0;
  if ((int)uVar6 < 0x20) {
    bVar11 = SCARRY4(uVar3,0xc);
    iVar5 = iVar5 + -0x1f;
    bVar10 = iVar5 < 0;
    bVar9 = iVar5 == 0;
    uVar3 = uVar6;
    if (!bVar9 && bVar10 == bVar11) {
      uVar2 = uVar4 << (uVar6 & 0xff);
      uVar4 = uVar4 >> (0xcU - iVar5 & 0xff);
      goto LAB_0001301c;
    }
  }
  if (bVar9 || bVar10 != bVar11) {
    uVar8 = 0x20 - uVar3;
  }
  uVar4 = uVar4 << (uVar3 & 0xff);
  if (bVar9 || bVar10 != bVar11) {
    uVar4 = uVar4 | uVar2 >> (uVar8 & 0xff);
  }
  if (bVar9 || bVar10 != bVar11) {
    uVar2 = uVar2 << (uVar3 & 0xff);
  }
LAB_0001301c:
  if ((int)uVar6 <= iVar7) {
    return CONCAT44(uVar4 + (iVar7 - uVar6) * 0x100000,uVar2);
  }
  uVar8 = ~(iVar7 - uVar6);
  if (0x1e < (int)uVar8) {
    return (ulonglong)(uVar4 >> (uVar8 - 0x1f & 0xff));
  }
  iVar7 = uVar8 - 0x13;
  if (iVar7 == 0 || iVar7 < 0 != SCARRY4(uVar8 - 0x1f,0xc)) {
    uVar8 = uVar8 + 1;
    return CONCAT44(uVar4 >> (uVar8 & 0xff),uVar2 >> (uVar8 & 0xff) | uVar4 << (0x20 - uVar8 & 0xff)
                   );
  }
  return (ulonglong)(uVar2 >> (0x20 - (0xcU - iVar7) & 0xff) | uVar4 << (0xcU - iVar7 & 0xff));
}



ulonglong __aeabi_l2d(uint param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  
  if ((param_1 | param_2) == 0) {
    return CONCAT44(param_2,param_1);
  }
  uVar8 = param_2 & 0x80000000;
  uVar3 = param_2;
  if ((int)uVar8 < 0) {
    bVar11 = param_1 != 0;
    param_1 = -param_1;
    uVar3 = -param_2 - (uint)bVar11;
  }
  iVar7 = 0x432;
  uVar9 = uVar3 >> 0x16;
  if (uVar9 != 0) {
    iVar7 = 3;
    if (uVar3 >> 0x19 != 0) {
      iVar7 = 6;
    }
    if (uVar3 >> 0x1c != 0) {
      iVar7 = iVar7 + 3;
    }
    uVar4 = iVar7 - ((int)uVar3 >> 0x1f);
    uVar9 = param_1 << (0x20 - uVar4 & 0xff);
    param_1 = param_1 >> (uVar4 & 0xff) | uVar3 << (0x20 - uVar4 & 0xff);
    uVar3 = uVar3 >> (uVar4 & 0xff);
    iVar7 = uVar4 + 0x432;
  }
  if (0xfffff < uVar3) {
    if (0x1fffff < uVar3) {
      uVar4 = uVar3 & 1;
      uVar3 = uVar3 >> 1;
      bVar1 = (byte)param_1;
      param_1 = (uint)(uVar4 != 0) << 0x1f | param_1 >> 1;
      uVar9 = (uint)(bVar1 & 1) << 0x1f | uVar9 >> 1;
      iVar7 = iVar7 + 1;
      if (0xffbfffff < (uint)(iVar7 * 0x200000)) {
        return (ulonglong)(uVar8 | 0x7ff00000) << 0x20;
      }
    }
LAB_00012fa4:
    bVar11 = 0x7fffffff < uVar9;
    if (uVar9 == 0x80000000) {
      bVar11 = (param_1 & 1) != 0;
    }
    return CONCAT44(uVar3 + iVar7 * 0x100000 + (uint)(bVar11 == true && param_1 + 1 <= param_1) |
                    uVar8,param_1 + bVar11);
  }
  bVar12 = (uVar9 & 0x80000000) != 0;
  uVar9 = uVar9 << 1;
  bVar11 = CARRY4(param_1,param_1);
  bVar10 = param_1 * 2 + 1 <= param_1;
  param_1 = param_1 * 2 + (uint)bVar12;
  uVar3 = uVar3 * 2 + (uint)(!bVar12 && bVar11 || bVar12 && bVar10);
  iVar7 = iVar7 + -1;
  if ((uVar3 & 0x100000) != 0) goto LAB_00012fa4;
  uVar2 = param_1;
  uVar4 = uVar3;
  if (uVar3 == 0) {
    uVar2 = 0;
    uVar4 = param_1;
  }
  iVar5 = count_leading_zeroes(uVar4);
  if (uVar3 == 0) {
    iVar5 = iVar5 + 0x20;
  }
  uVar6 = iVar5 - 0xb;
  bVar12 = SBORROW4(uVar6,0x20);
  uVar3 = iVar5 - 0x2b;
  bVar11 = (int)uVar3 < 0;
  bVar10 = uVar3 == 0;
  if ((int)uVar6 < 0x20) {
    bVar12 = SCARRY4(uVar3,0xc);
    iVar5 = iVar5 + -0x1f;
    bVar11 = iVar5 < 0;
    bVar10 = iVar5 == 0;
    uVar3 = uVar6;
    if (!bVar10 && bVar11 == bVar12) {
      uVar2 = uVar4 << (uVar6 & 0xff);
      uVar4 = uVar4 >> (0xcU - iVar5 & 0xff);
      goto LAB_0001301c;
    }
  }
  if (bVar10 || bVar11 != bVar12) {
    uVar9 = 0x20 - uVar3;
  }
  uVar4 = uVar4 << (uVar3 & 0xff);
  if (bVar10 || bVar11 != bVar12) {
    uVar4 = uVar4 | uVar2 >> (uVar9 & 0xff);
  }
  if (bVar10 || bVar11 != bVar12) {
    uVar2 = uVar2 << (uVar3 & 0xff);
  }
LAB_0001301c:
  if ((int)uVar6 <= iVar7) {
    return CONCAT44(uVar4 + (iVar7 - uVar6) * 0x100000 | uVar8,uVar2);
  }
  uVar3 = ~(iVar7 - uVar6);
  if (0x1e < (int)uVar3) {
    return CONCAT44(param_2,uVar4 >> (uVar3 - 0x1f & 0xff)) & 0x80000000ffffffff;
  }
  iVar7 = uVar3 - 0x13;
  if (iVar7 == 0 || iVar7 < 0 != SCARRY4(uVar3 - 0x1f,0xc)) {
    uVar3 = uVar3 + 1;
    return CONCAT44(uVar8 | uVar4 >> (uVar3 & 0xff),
                    uVar2 >> (uVar3 & 0xff) | uVar4 << (0x20 - uVar3 & 0xff));
  }
  return CONCAT44(param_2,uVar2 >> (0x20 - (0xcU - iVar7) & 0xff) | uVar4 << (0xcU - iVar7 & 0xff))
         & 0x80000000ffffffff;
}



ulonglong __muldf3(undefined4 param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint unaff_r5;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  ulonglong uVar12;
  
  uVar12 = CONCAT44(param_2,param_1);
  uVar7 = 0x7ff;
  uVar4 = param_2 >> 0x14 & 0x7ff;
  bVar9 = uVar4 == 0;
  if (!bVar9) {
    unaff_r5 = param_4 >> 0x14 & 0x7ff;
    bVar9 = unaff_r5 == 0;
  }
  if (!bVar9) {
    bVar9 = uVar4 == 0x7ff;
  }
  if (!bVar9) {
    bVar9 = unaff_r5 == 0x7ff;
  }
  if (bVar9) {
    uVar12 = FUN_000133e0();
  }
  uVar3 = (uint)(uVar12 >> 0x20);
  iVar5 = uVar4 + unaff_r5;
  uVar4 = uVar3 ^ param_4;
  uVar3 = uVar3 & ~(uVar7 << 0x15);
  param_4 = param_4 & ~(uVar7 << 0x15);
  bVar9 = ((uint)uVar12 | uVar3 << 0xc) == 0;
  if (!bVar9) {
    bVar9 = (param_3 | param_4 << 0xc) == 0;
  }
  uVar3 = uVar3 | 0x100000;
  param_4 = param_4 | 0x100000;
  if (bVar9) {
    param_3 = (uint)uVar12 | param_3;
    param_4 = (uVar4 & 0x80000000 | uVar3) ^ param_4;
    uVar4 = uVar7 >> 1;
    bVar11 = SBORROW4(iVar5,uVar4);
    uVar6 = iVar5 - uVar4;
    bVar9 = uVar6 == 0;
    uVar3 = uVar6;
    if (!bVar9 && (int)uVar4 <= iVar5) {
      bVar11 = SBORROW4(uVar7,uVar6);
      uVar3 = uVar7 - uVar6;
      bVar9 = uVar7 == uVar6;
    }
    if (!bVar9 && (int)uVar3 < 0 == bVar11) {
      param_4 = param_4 | uVar6 * 0x100000;
    }
    if (!bVar9 && (int)uVar3 < 0 == bVar11) {
      return CONCAT44(param_4,param_3);
    }
    param_4 = param_4 | 0x100000;
    uVar7 = 0;
    bVar11 = SBORROW4(uVar6,1);
    uVar6 = uVar6 - 1;
    bVar9 = uVar6 == 0;
    uVar4 = uVar6;
  }
  else {
    uVar1 = (uVar12 & 0xffffffff) * (ulonglong)param_3;
    uVar12 = (uVar12 & 0xffffffff) * (ulonglong)param_4 +
             (ulonglong)uVar3 * (ulonglong)param_3 + (uVar1 >> 0x20);
    uVar8 = (uint)uVar12;
    lVar2 = (ulonglong)uVar3 * (ulonglong)param_4 + (uVar12 >> 0x20);
    uVar3 = (uint)lVar2;
    uVar7 = (uint)((ulonglong)lVar2 >> 0x20);
    if ((int)uVar1 != 0) {
      uVar8 = uVar8 | 1;
    }
    uVar6 = (iVar5 + -0x3ff) - (uint)(uVar7 < 0x200);
    if (uVar7 < 0x200) {
      bVar10 = (uVar8 & 0x80000000) != 0;
      uVar8 = uVar8 << 1;
      bVar9 = CARRY4(uVar3,uVar3);
      bVar11 = uVar3 * 2 + 1 <= uVar3;
      uVar3 = uVar3 * 2 + (uint)bVar10;
      uVar7 = uVar7 * 2 + (uint)(!bVar10 && bVar9 || bVar10 && bVar11);
    }
    param_4 = uVar4 & 0x80000000 | uVar7 << 0xb | uVar3 >> 0x15;
    param_3 = uVar3 << 0xb | uVar8 >> 0x15;
    uVar7 = uVar8 * 0x800;
    bVar10 = 0xfc < uVar6;
    bVar11 = SBORROW4(uVar6,0xfd);
    uVar3 = uVar6 - 0xfd;
    bVar9 = uVar3 == 0;
    uVar4 = uVar3;
    if (bVar10 && !bVar9) {
      bVar10 = 0x6ff < uVar3;
      bVar11 = SBORROW4(uVar3,0x700);
      uVar4 = uVar6 - 0x7fd;
      bVar9 = uVar3 == 0x700;
    }
    if (!bVar10 || bVar9) {
      bVar9 = 0x7fffffff < uVar7;
      if (uVar7 == 0x80000000) {
        bVar9 = (uVar8 >> 0x15 & 1) != 0;
      }
      return CONCAT44(param_4 + uVar6 * 0x100000 + (uint)(bVar9 == true && param_3 + 1 <= param_3),
                      param_3 + bVar9);
    }
  }
  if (!bVar9 && (int)uVar4 < 0 == bVar11) {
    return (ulonglong)(param_4 & 0x80000000 | 0x7ff00000) << 0x20;
  }
  bVar10 = SCARRY4(uVar6,0x36);
  bVar9 = (int)(uVar6 + 0x36) < 0;
  bVar11 = uVar6 == 0xffffffca;
  if (bVar11 || bVar9 != bVar10) {
    param_3 = 0;
  }
  if (bVar11 || bVar9 != bVar10) {
    param_4 = param_4 & 0x80000000;
  }
  if (bVar11 || bVar9 != bVar10) {
    return CONCAT44(param_4,param_3);
  }
  uVar4 = -uVar6;
  uVar3 = uVar4 - 0x20;
  if (0x1f < (int)uVar4) {
    uVar6 = param_3 >> (uVar3 & 0xff) | param_4 << (0x20 - uVar3 & 0xff);
    uVar4 = (param_4 >> (uVar3 & 0xff) & ~((param_4 & 0x80000000) >> (uVar3 & 0xff))) -
            ((int)uVar6 >> 0x1f);
    if ((uVar7 | param_3 << (0x20 - uVar3 & 0xff) | uVar6 << 1) == 0) {
      uVar4 = uVar4 & ~(uVar6 >> 0x1f);
    }
    return CONCAT44(param_4,uVar4) & 0x80000000ffffffff;
  }
  iVar5 = uVar4 - 0x14;
  if (iVar5 == 0 || iVar5 < 0 != SCARRY4(uVar3,0xc)) {
    uVar8 = param_3 << (uVar6 + 0x20 & 0xff);
    uVar3 = param_3 >> (uVar4 & 0xff) | param_4 << (uVar6 + 0x20 & 0xff);
    uVar6 = uVar3 + -((int)uVar8 >> 0x1f);
    if ((uVar7 | uVar8 << 1) == 0) {
      uVar6 = uVar6 & ~(uVar8 >> 0x1f);
    }
    return CONCAT44((param_4 & 0x80000000) +
                    ((param_4 & 0x7fffffff) >> (uVar4 & 0xff)) +
                    (uint)CARRY4(uVar3,-((int)uVar8 >> 0x1f)),uVar6);
  }
  uVar4 = 0xc - iVar5;
  uVar6 = param_3 << (uVar4 & 0xff);
  uVar4 = param_3 >> (0x20 - uVar4 & 0xff) | param_4 << (uVar4 & 0xff);
  uVar3 = uVar4 + -((int)uVar6 >> 0x1f);
  if ((uVar7 | uVar6 << 1) == 0) {
    uVar3 = uVar3 & ~(uVar6 >> 0x1f);
  }
  return CONCAT44((param_4 & 0x80000000) + (uint)CARRY4(uVar4,-((int)uVar6 >> 0x1f)),uVar3);
}



ulonglong FUN_000133e0(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint unaff_r4;
  uint uVar2;
  uint uVar3;
  uint in_r12;
  bool bVar4;
  
  uVar2 = in_r12 & param_4 >> 0x14;
  if (unaff_r4 != in_r12 && uVar2 != in_r12) {
    bVar4 = (param_1 | param_2 << 1) == 0;
    if (!bVar4) {
      bVar4 = (param_3 | param_4 << 1) == 0;
    }
    if (bVar4) {
      return (ulonglong)((param_2 ^ param_4) & 0x80000000) << 0x20;
    }
    if (unaff_r4 == 0) {
      uVar3 = param_2 & 0x80000000;
      do {
        uVar1 = param_1 & 0x80000000;
        param_1 = param_1 << 1;
        param_2 = param_2 * 2 + (uint)(uVar1 != 0);
      } while ((param_2 & 0x100000) == 0);
      param_2 = param_2 | uVar3;
      if (uVar2 != 0) {
        return CONCAT44(param_2,param_1);
      }
    }
    do {
      uVar2 = param_3 & 0x80000000;
      param_3 = param_3 << 1;
      param_4 = param_4 * 2 + (uint)(uVar2 != 0);
    } while ((param_4 & 0x100000) == 0);
    return CONCAT44(param_2,param_1);
  }
  bVar4 = (param_1 | param_2 << 1) == 0;
  if (bVar4) {
    param_2 = param_4;
    param_1 = param_3;
  }
  if (!bVar4) {
    bVar4 = (param_3 | param_4 << 1) == 0;
  }
  uVar3 = param_2;
  if (((!bVar4) && ((unaff_r4 != in_r12 || ((param_1 | param_2 << 0xc) == 0)))) &&
     ((uVar2 != in_r12 || (param_1 = param_3, uVar3 = param_4, (param_3 | param_4 << 0xc) == 0)))) {
    return (ulonglong)((param_2 ^ param_4) & 0x80000000 | 0x7ff00000) << 0x20;
  }
  return CONCAT44(uVar3,param_1) | 0x7ff8000000000000;
}



ulonglong __divdf3(undefined4 param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint unaff_r5;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  ulonglong uVar16;
  
  uVar16 = CONCAT44(param_2,param_1);
  uVar12 = 0x7ff;
  uVar6 = param_2 >> 0x14 & 0x7ff;
  bVar13 = uVar6 == 0;
  if (!bVar13) {
    unaff_r5 = param_4 >> 0x14 & 0x7ff;
    bVar13 = unaff_r5 == 0;
  }
  if (!bVar13) {
    bVar13 = uVar6 == 0x7ff;
  }
  if (!bVar13) {
    bVar13 = unaff_r5 == 0x7ff;
  }
  if (bVar13) {
    uVar16 = FUN_000135c6();
  }
  uVar8 = (uint)(uVar16 >> 0x20);
  uVar10 = (uint)uVar16;
  iVar7 = uVar6 - unaff_r5;
  if ((param_3 | param_4 << 0xc) == 0) {
    uVar6 = (uVar8 ^ param_4) & 0x80000000 | uVar8 & 0xfffff;
    bVar14 = SCARRY4(iVar7,uVar12 >> 1);
    uVar8 = iVar7 + (uVar12 >> 1);
    bVar13 = (int)uVar8 < 0;
    bVar15 = uVar8 == 0;
    if (!bVar15 && bVar13 == bVar14) {
      bVar14 = SBORROW4(uVar12,uVar8);
      bVar13 = (int)(uVar12 - uVar8) < 0;
      bVar15 = uVar12 == uVar8;
    }
    if (!bVar15 && bVar13 == bVar14) {
      uVar6 = uVar6 | uVar8 * 0x100000;
    }
    if (!bVar15 && bVar13 == bVar14) {
      return uVar16 & 0xffffffff | (ulonglong)uVar6 << 0x20;
    }
    uVar6 = uVar6 | 0x100000;
    uVar12 = 0;
    bVar15 = SBORROW4(uVar8,1);
    uVar8 = uVar8 - 1;
    bVar13 = uVar8 == 0;
    uVar2 = uVar8;
  }
  else {
    uVar2 = (param_4 << 0xc) >> 4 | 0x10000000 | param_3 >> 0x18;
    uVar12 = param_3 << 8;
    uVar9 = (uVar8 << 0xc) >> 4 | 0x10000000 | uVar10 >> 0x18;
    uVar10 = uVar10 * 0x100;
    uVar6 = (uVar8 ^ param_4) & 0x80000000;
    bVar13 = uVar2 <= uVar9;
    if (uVar9 == uVar2) {
      bVar13 = uVar12 <= uVar10;
    }
    iVar7 = iVar7 + (uint)bVar13;
    uVar8 = iVar7 + 0x3fd;
    if (bVar13 == false) {
      uVar2 = uVar2 >> 1;
      uVar12 = (uint)((param_3 >> 0x18 & 1) != 0) << 0x1f | uVar12 >> 1;
    }
    uVar11 = uVar10 - uVar12;
    uVar9 = (uVar9 - uVar2) - (uint)(uVar10 < uVar12);
    uVar3 = uVar2 >> 1;
    uVar1 = (uint)((uVar2 & 1) != 0) << 0x1f | uVar12 >> 1;
    uVar10 = 0x100000;
    uVar2 = 0x80000;
    while( true ) {
      bVar14 = uVar11 < uVar1;
      bVar13 = CARRY4(uVar9,~uVar3);
      bVar15 = uVar9 + ~uVar3 + 1 <= uVar9;
      if (bVar14 && bVar13 || !bVar14 && bVar15) {
        uVar11 = uVar11 - uVar1;
      }
      if (bVar14 && bVar13 || !bVar14 && bVar15) {
        uVar9 = (uVar9 - uVar3) - (uint)bVar14;
      }
      if (bVar14 && bVar13 || !bVar14 && bVar15) {
        uVar10 = uVar10 | uVar2;
      }
      uVar4 = uVar3 >> 1;
      uVar12 = (uint)((uVar3 & 1) != 0) << 0x1f | uVar1 >> 1;
      bVar14 = uVar11 < uVar12;
      bVar13 = CARRY4(uVar9,~uVar4);
      bVar15 = uVar9 + ~uVar4 + 1 <= uVar9;
      if (bVar14 && bVar13 || !bVar14 && bVar15) {
        uVar11 = uVar11 - uVar12;
      }
      if (bVar14 && bVar13 || !bVar14 && bVar15) {
        uVar9 = (uVar9 - uVar4) - (uint)bVar14;
      }
      if (bVar14 && bVar13 || !bVar14 && bVar15) {
        uVar10 = uVar10 | uVar2 >> 1;
      }
      uVar1 = uVar3 >> 2;
      uVar4 = (uint)((uVar4 & 1) != 0) << 0x1f | uVar12 >> 1;
      bVar14 = uVar11 < uVar4;
      bVar13 = CARRY4(uVar9,~uVar1);
      bVar15 = uVar9 + ~uVar1 + 1 <= uVar9;
      if (bVar14 && bVar13 || !bVar14 && bVar15) {
        uVar11 = uVar11 - uVar4;
      }
      if (bVar14 && bVar13 || !bVar14 && bVar15) {
        uVar9 = (uVar9 - uVar1) - (uint)bVar14;
      }
      if (bVar14 && bVar13 || !bVar14 && bVar15) {
        uVar10 = uVar10 | uVar2 >> 2;
      }
      uVar5 = uVar3 >> 3;
      uVar1 = (uint)((uVar1 & 1) != 0) << 0x1f | uVar4 >> 1;
      bVar14 = uVar11 < uVar1;
      bVar13 = CARRY4(uVar9,~uVar5);
      bVar15 = uVar9 + ~uVar5 + 1 <= uVar9;
      if (bVar14 && bVar13 || !bVar14 && bVar15) {
        uVar11 = uVar11 - uVar1;
      }
      if (bVar14 && bVar13 || !bVar14 && bVar15) {
        uVar9 = (uVar9 - uVar5) - (uint)bVar14;
      }
      if (bVar14 && bVar13 || !bVar14 && bVar15) {
        uVar10 = uVar10 | uVar2 >> 3;
      }
      uVar12 = uVar9 | uVar11;
      if (uVar12 == 0) break;
      uVar9 = uVar9 << 4 | uVar11 >> 0x1c;
      uVar11 = uVar11 << 4;
      uVar3 = uVar3 & 0xfffffff8 | uVar1 >> 0x1d;
      uVar1 = (uVar4 >> 1) << 3;
      uVar2 = uVar2 >> 4;
      if (uVar2 == 0) {
        uVar5 = uVar3;
        if ((uVar6 & 0x100000) != 0) goto LAB_00013576;
        uVar6 = uVar6 | uVar10;
        uVar10 = 0;
        uVar2 = 0x80000000;
      }
    }
    if ((uVar6 & 0x100000) == 0) {
      uVar6 = uVar6 | uVar10;
      uVar10 = 0;
    }
LAB_00013576:
    bVar14 = 0xfc < uVar8;
    bVar15 = SBORROW4(uVar8,0xfd);
    uVar3 = iVar7 + 0x300;
    bVar13 = uVar3 == 0;
    uVar2 = uVar3;
    if (bVar14 && !bVar13) {
      bVar14 = 0x6ff < uVar3;
      bVar15 = SBORROW4(uVar3,0x700);
      uVar2 = iVar7 - 0x400;
      bVar13 = uVar3 == 0x700;
    }
    if (!bVar14 || bVar13) {
      bVar13 = uVar5 <= uVar9;
      if (uVar9 == uVar5) {
        bVar13 = uVar1 <= uVar11;
      }
      if (uVar9 == uVar5 && uVar11 == uVar1) {
        bVar13 = (uVar10 & 1) != 0;
      }
      return CONCAT44(uVar6 + uVar8 * 0x100000 + (uint)(bVar13 == true && uVar10 + 1 <= uVar10),
                      uVar10 + bVar13);
    }
  }
  if (!bVar13 && (int)uVar2 < 0 == bVar15) {
    return (ulonglong)(uVar6 & 0x80000000 | 0x7ff00000) << 0x20;
  }
  bVar14 = SCARRY4(uVar8,0x36);
  bVar13 = (int)(uVar8 + 0x36) < 0;
  bVar15 = uVar8 == 0xffffffca;
  if (bVar15 || bVar13 != bVar14) {
    uVar10 = 0;
  }
  if (bVar15 || bVar13 != bVar14) {
    uVar6 = uVar6 & 0x80000000;
  }
  if (bVar15 || bVar13 != bVar14) {
    return CONCAT44(uVar6,uVar10);
  }
  uVar2 = -uVar8;
  uVar9 = uVar2 - 0x20;
  if (0x1f < (int)uVar2) {
    uVar2 = uVar10 >> (uVar9 & 0xff) | uVar6 << (0x20 - uVar9 & 0xff);
    uVar8 = (uVar6 >> (uVar9 & 0xff) & ~((uVar6 & 0x80000000) >> (uVar9 & 0xff))) -
            ((int)uVar2 >> 0x1f);
    if ((uVar12 | uVar10 << (0x20 - uVar9 & 0xff) | uVar2 << 1) == 0) {
      uVar8 = uVar8 & ~(uVar2 >> 0x1f);
    }
    return CONCAT44(uVar6,uVar8) & 0x80000000ffffffff;
  }
  iVar7 = uVar2 - 0x14;
  if (iVar7 != 0 && iVar7 < 0 == SCARRY4(uVar9,0xc)) {
    uVar8 = 0xc - iVar7;
    uVar2 = uVar10 << (uVar8 & 0xff);
    uVar10 = uVar10 >> (0x20 - uVar8 & 0xff) | uVar6 << (uVar8 & 0xff);
    uVar8 = uVar10 + -((int)uVar2 >> 0x1f);
    if ((uVar12 | uVar2 << 1) == 0) {
      uVar8 = uVar8 & ~(uVar2 >> 0x1f);
    }
    return CONCAT44((uVar6 & 0x80000000) + (uint)CARRY4(uVar10,-((int)uVar2 >> 0x1f)),uVar8);
  }
  uVar9 = uVar10 << (uVar8 + 0x20 & 0xff);
  uVar10 = uVar10 >> (uVar2 & 0xff) | uVar6 << (uVar8 + 0x20 & 0xff);
  uVar8 = uVar10 + -((int)uVar9 >> 0x1f);
  if ((uVar12 | uVar9 << 1) == 0) {
    uVar8 = uVar8 & ~(uVar9 >> 0x1f);
  }
  return CONCAT44((uVar6 & 0x80000000) +
                  ((uVar6 & 0x7fffffff) >> (uVar2 & 0xff)) +
                  (uint)CARRY4(uVar10,-((int)uVar9 >> 0x1f)),uVar8);
}



ulonglong FUN_000135c6(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint unaff_r4;
  uint uVar2;
  uint uVar3;
  uint in_r12;
  bool bVar4;
  
  uVar2 = in_r12 & param_4 >> 0x14;
  uVar3 = param_2;
  if (unaff_r4 != in_r12 || uVar2 != in_r12) {
    if (unaff_r4 == in_r12) {
      if (((param_1 | param_2 << 0xc) == 0) && (param_1 = param_3, uVar3 = param_4, uVar2 != in_r12)
         ) {
LAB_00013438:
        return (ulonglong)((param_2 ^ param_4) & 0x80000000 | 0x7ff00000) << 0x20;
      }
    }
    else {
      if (uVar2 == in_r12) {
        param_1 = param_3;
        uVar3 = param_4;
        if ((param_3 | param_4 << 0xc) == 0) {
LAB_000133fc:
          return (ulonglong)((param_2 ^ param_4) & 0x80000000) << 0x20;
        }
      }
      else {
        bVar4 = (param_1 | param_2 << 1) == 0;
        if (!bVar4) {
          bVar4 = (param_3 | param_4 << 1) == 0;
        }
        if (!bVar4) {
          if (unaff_r4 == 0) {
            uVar3 = param_2 & 0x80000000;
            do {
              uVar1 = param_1 & 0x80000000;
              param_1 = param_1 << 1;
              param_2 = param_2 * 2 + (uint)(uVar1 != 0);
            } while ((param_2 & 0x100000) == 0);
            param_2 = param_2 | uVar3;
            if (uVar2 != 0) {
              return CONCAT44(param_2,param_1);
            }
          }
          do {
            uVar3 = param_3 & 0x80000000;
            param_3 = param_3 << 1;
            param_4 = param_4 * 2 + (uint)(uVar3 != 0);
          } while ((param_4 & 0x100000) == 0);
          return CONCAT44(param_2,param_1);
        }
        if ((param_1 | param_2 << 1) != 0) goto LAB_00013438;
        if ((param_3 | param_4 << 1) != 0) goto LAB_000133fc;
      }
    }
  }
  return CONCAT44(uVar3,param_1) | 0x7ff8000000000000;
}



uint __truncdfsf2(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint in_r12;
  bool bVar4;
  bool bVar5;
  
  uVar2 = param_2 * 2;
  bVar5 = uVar2 < 0x70000000;
  uVar3 = uVar2 + 0x90000000;
  uVar1 = uVar3;
  if (!bVar5) {
    in_r12 = uVar2 + 0x8fe00000;
    uVar1 = in_r12;
  }
  bVar4 = uVar1 == 0;
  if (!bVar5 && uVar3 >= 0x200000) {
    bVar4 = in_r12 == 0x1fc00000;
  }
  if (((bVar5 || uVar3 < 0x200000) || 0x1fc00000 < in_r12) || bVar4) {
    if ((param_2 & 0x40000000) != 0) {
      if (((int)uVar2 >> 0x15 == -1) && ((param_1 | param_2 << 0xc) != 0)) {
        return 0x7fc00000;
      }
      return param_2 & 0x80000000 | 0x7f800000;
    }
    if ((int)(uVar2 + 0x92e00000) < 0 != SCARRY4(uVar3,0x2e00000)) {
      return param_2 & 0x80000000;
    }
    uVar2 = 0x18 - (uVar2 + 0x92e00000 >> 0x15);
    uVar1 = param_1 >> (uVar2 & 0xff);
    if (param_1 << (0x20 - uVar2 & 0xff) != 0) {
      uVar1 = uVar1 | 1;
    }
    uVar3 = param_2 & 0x1fffff | 0x100000;
    param_1 = uVar1 | uVar3 << (0x20 - uVar2 & 0xff);
    uVar3 = (uVar3 >> (uVar2 & 0xff)) << 1;
  }
  uVar1 = (param_2 & 0x80000000 | param_1 >> 0x1d) + uVar3 * 4 + (uint)(0x7fffffff < param_1 * 8);
  if (param_1 * 8 == 0x80000000) {
    uVar1 = uVar1 & 0xfffffffe;
  }
  return uVar1;
}



int __aeabi_ldivmod(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined local_8 [8];
  
  if ((param_4 == 0) && (param_3 == 0)) {
    if (param_2 < 0) {
      param_1 = 0;
      param_2 = -0x80000000;
    }
    else {
      if (param_2 != 0 || param_1 != 0) {
        param_2 = 0x7fffffff;
        param_1 = -1;
      }
    }
    iVar1 = __aeabi_idiv0(param_1,param_2);
    return iVar1;
  }
  if (param_2 < 0) {
    iVar1 = -param_2 - (uint)(param_1 != 0);
    if (param_4 < 0) {
      iVar1 = __udivmoddi4(-param_1,iVar1,-param_3,-param_4 - (uint)(param_3 != 0),local_8);
      return iVar1;
    }
    iVar1 = __udivmoddi4(-param_1,iVar1,param_3,param_4,local_8);
    return -iVar1;
  }
  if (param_4 < 0) {
    iVar1 = __udivmoddi4(param_1,param_2,-param_3,-param_4 - (uint)(param_3 != 0),local_8);
    return -iVar1;
  }
  iVar1 = __udivmoddi4();
  return iVar1;
}



void __aeabi_uldivmod(int param_1,int param_2,int param_3,int param_4)

{
  if ((param_4 == 0) && (param_3 == 0)) {
    if (param_2 != 0 || param_1 != 0) {
      param_2 = -1;
      param_1 = -1;
    }
    __aeabi_idiv0(param_1,param_2);
    return;
  }
  __udivmoddi4();
  return;
}



undefined8 __udivmoddi4(uint param_1,uint param_2,uint param_3,uint param_4,uint *param_5)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  undefined8 uVar13;
  
  if (param_4 == 0) {
    if (param_2 < param_3) {
      uVar4 = count_leading_zeroes(param_3);
      if (uVar4 != 0) {
        param_3 = param_3 << (uVar4 & 0xff);
        param_2 = param_1 >> (0x20 - uVar4 & 0xff) | param_2 << (uVar4 & 0xff);
        param_1 = param_1 << (uVar4 & 0xff);
      }
      uVar10 = param_3 >> 0x10;
      uVar6 = param_2 / uVar10;
      uVar5 = param_1 >> 0x10 | (param_2 - uVar10 * uVar6) * 0x10000;
      uVar3 = uVar6 * (param_3 & 0xffff);
      uVar1 = uVar6;
      if (uVar5 <= uVar3 && uVar3 - uVar5 != 0) {
        bVar12 = CARRY4(param_3,uVar5);
        uVar5 = param_3 + uVar5;
        uVar1 = uVar6 - 1;
        if ((bVar12 == false) && (uVar5 <= uVar3 && uVar3 - uVar5 != 0)) {
          uVar1 = uVar6 - 2;
          uVar5 = uVar5 + param_3;
        }
      }
      uVar6 = (uVar5 - uVar3) / uVar10;
      uVar5 = param_1 & 0xffff | ((uVar5 - uVar3) - uVar10 * uVar6) * 0x10000;
      uVar10 = uVar6 * (param_3 & 0xffff);
      uVar3 = uVar6;
      if (uVar5 <= uVar10 && uVar10 - uVar5 != 0) {
        bVar12 = CARRY4(param_3,uVar5);
        uVar5 = param_3 + uVar5;
        uVar3 = uVar6 - 1;
        if ((bVar12 == false) && (uVar5 <= uVar10 && uVar10 - uVar5 != 0)) {
          uVar3 = uVar6 - 2;
          uVar5 = uVar5 + param_3;
        }
      }
      puVar2 = (uint *)(uVar3 | uVar1 << 0x10);
      uVar5 = uVar5 - uVar10;
      puVar7 = (uint *)0x0;
    }
    else {
      if (param_3 == 0) {
                    // WARNING: Could not recover jumptable at 0x0001387e. Too many branches
                    // WARNING: Treating indirect jump as call
        UNRECOVERED_JUMPTABLE = (code *)software_udf(0xff,0x1387e);
        uVar13 = (*UNRECOVERED_JUMPTABLE)();
        return uVar13;
      }
      uVar4 = count_leading_zeroes(param_3);
      if (uVar4 == 0) {
        param_2 = param_2 - param_3;
        uVar11 = param_3 >> 0x10;
        uVar9 = param_3 & 0xffff;
        puVar7 = (uint *)(FUN_00000000 + 1);
      }
      else {
        param_3 = param_3 << (uVar4 & 0xff);
        uVar1 = param_2 >> (0x20 - uVar4 & 0xff);
        uVar11 = param_3 >> 0x10;
        uVar3 = param_2 << (uVar4 & 0xff) | param_1 >> (0x20 - uVar4 & 0xff);
        uVar10 = uVar1 / uVar11;
        uVar9 = param_3 & 0xffff;
        uVar5 = uVar3 >> 0x10 | (uVar1 - uVar11 * uVar10) * 0x10000;
        uVar6 = uVar10 * uVar9;
        param_1 = param_1 << (uVar4 & 0xff);
        uVar1 = uVar10;
        if (uVar5 <= uVar6 && uVar6 - uVar5 != 0) {
          bVar12 = CARRY4(param_3,uVar5);
          uVar5 = param_3 + uVar5;
          uVar1 = uVar10 - 1;
          if ((bVar12 == false) && (uVar5 <= uVar6 && uVar6 - uVar5 != 0)) {
            uVar1 = uVar10 - 2;
            uVar5 = uVar5 + param_3;
          }
        }
        uVar10 = (uVar5 - uVar6) / uVar11;
        param_2 = uVar3 & 0xffff | ((uVar5 - uVar6) - uVar11 * uVar10) * 0x10000;
        uVar5 = uVar10 * uVar9;
        uVar3 = uVar10;
        if (param_2 <= uVar5 && uVar5 - param_2 != 0) {
          bVar12 = CARRY4(param_3,param_2);
          param_2 = param_3 + param_2;
          uVar3 = uVar10 - 1;
          if ((bVar12 == false) && (param_2 <= uVar5 && uVar5 - param_2 != 0)) {
            uVar3 = uVar10 - 2;
            param_2 = param_2 + param_3;
          }
        }
        param_2 = param_2 - uVar5;
        puVar7 = (uint *)(uVar3 | uVar1 << 0x10);
      }
      uVar6 = param_2 / uVar11;
      uVar5 = param_1 >> 0x10 | (param_2 - uVar11 * uVar6) * 0x10000;
      uVar3 = uVar9 * uVar6;
      uVar1 = uVar6;
      if (uVar5 <= uVar3 && uVar3 - uVar5 != 0) {
        bVar12 = CARRY4(param_3,uVar5);
        uVar5 = param_3 + uVar5;
        uVar1 = uVar6 - 1;
        if ((bVar12 == false) && (uVar5 <= uVar3 && uVar3 - uVar5 != 0)) {
          uVar1 = uVar6 - 2;
          uVar5 = uVar5 + param_3;
        }
      }
      uVar6 = (uVar5 - uVar3) / uVar11;
      uVar5 = param_1 & 0xffff | ((uVar5 - uVar3) - uVar11 * uVar6) * 0x10000;
      uVar9 = uVar9 * uVar6;
      uVar3 = uVar6;
      if (uVar5 <= uVar9 && uVar9 - uVar5 != 0) {
        bVar12 = CARRY4(param_3,uVar5);
        uVar5 = param_3 + uVar5;
        uVar3 = uVar6 - 1;
        if ((bVar12 == false) && (uVar5 <= uVar9 && uVar9 - uVar5 != 0)) {
          uVar3 = uVar6 - 2;
          uVar5 = uVar5 + param_3;
        }
      }
      uVar5 = uVar5 - uVar9;
      puVar2 = (uint *)(uVar3 | uVar1 << 0x10);
    }
    if (param_5 != (uint *)0x0) {
      *param_5 = uVar5 >> (uVar4 & 0xff);
      param_5[1] = 0;
    }
  }
  else {
    puVar7 = param_5;
    if (param_2 < param_4) {
      puVar2 = param_5;
      if (param_5 != (uint *)0x0) {
        *param_5 = param_1;
        param_5[1] = param_2;
        return 0;
      }
    }
    else {
      puVar8 = (uint *)count_leading_zeroes(param_4);
      if (puVar8 == (uint *)0x0) {
        if ((param_4 < param_2) || (puVar2 = puVar8, param_3 <= param_1)) {
          bVar12 = param_1 < param_3;
          param_1 = param_1 - param_3;
          param_2 = (param_2 - param_4) - (uint)bVar12;
          puVar2 = (uint *)(FUN_00000000 + 1);
        }
        puVar7 = puVar8;
        if (param_5 != (uint *)0x0) {
          *param_5 = param_1;
          param_5[1] = param_2;
        }
      }
      else {
        uVar9 = 0x20 - (int)puVar8;
        uVar11 = param_3 >> (uVar9 & 0xff) | param_4 << ((uint)puVar8 & 0xff);
        uVar4 = param_2 >> (uVar9 & 0xff);
        uVar6 = uVar11 >> 0x10;
        uVar5 = param_1 >> (uVar9 & 0xff) | param_2 << ((uint)puVar8 & 0xff);
        uVar10 = uVar4 / uVar6;
        uVar1 = uVar5 >> 0x10 | (uVar4 - uVar6 * uVar10) * 0x10000;
        uVar3 = uVar10 * (uVar11 & 0xffff);
        param_3 = param_3 << ((uint)puVar8 & 0xff);
        param_1 = param_1 << ((uint)puVar8 & 0xff);
        uVar4 = uVar10;
        if (uVar1 <= uVar3 && uVar3 - uVar1 != 0) {
          bVar12 = CARRY4(uVar11,uVar1);
          uVar1 = uVar11 + uVar1;
          uVar4 = uVar10 - 1;
          if ((bVar12 == false) && (uVar1 <= uVar3 && uVar3 - uVar1 != 0)) {
            uVar4 = uVar10 - 2;
            uVar1 = uVar1 + uVar11;
          }
        }
        uVar10 = (uVar1 - uVar3) / uVar6;
        uVar3 = uVar5 & 0xffff | ((uVar1 - uVar3) - uVar6 * uVar10) * 0x10000;
        uVar5 = uVar10 * (uVar11 & 0xffff);
        uVar1 = uVar10;
        if (uVar3 <= uVar5 && uVar5 - uVar3 != 0) {
          bVar12 = CARRY4(uVar11,uVar3);
          uVar3 = uVar11 + uVar3;
          uVar1 = uVar10 - 1;
          if ((bVar12 == false) && (uVar3 <= uVar5 && uVar5 - uVar3 != 0)) {
            uVar1 = uVar10 - 2;
            uVar3 = uVar3 + uVar11;
          }
        }
        puVar2 = (uint *)(uVar1 | uVar4 << 0x10);
        uVar1 = (uint)(ZEXT48(puVar2) * (ulonglong)param_3);
        uVar4 = (uint)(ZEXT48(puVar2) * (ulonglong)param_3 >> 0x20);
        uVar3 = uVar3 - uVar5;
        if ((uVar3 < uVar4) || ((uVar3 == uVar4 && (param_1 < uVar1)))) {
          bVar12 = uVar1 < param_3;
          uVar1 = uVar1 - param_3;
          uVar4 = (uVar4 - uVar11) - (uint)bVar12;
          puVar2 = (uint *)((int)puVar2 + -1);
        }
        if (param_5 != (uint *)0x0) {
          uVar4 = (uVar3 - uVar4) - (uint)(param_1 < uVar1);
          *param_5 = uVar4 << (uVar9 & 0xff) | param_1 - uVar1 >> ((uint)puVar8 & 0xff);
          param_5[1] = uVar4 >> ((uint)puVar8 & 0xff);
          puVar7 = (uint *)0x0;
        }
      }
    }
  }
  return CONCAT44(puVar7,puVar2);
}



void __aeabi_idiv0(void)

{
  return;
}



undefined * __errno(void)

{
  return _impure_ptr;
}



// WARNING: Removing unreachable block (ram,0x00013a7c)

void exit(int __status)

{
  if (DAT_200009c0 != FUN_00000000) {
    (*DAT_200009c0)();
  }
                    // WARNING: Subroutine does not return
  _exit(__status);
}



int fileno(FILE *__stream)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = _impure_ptr;
  if ((_impure_ptr != (undefined *)0x0) && (*(int *)(_impure_ptr + 0x18) == 0)) {
    __sinit(_impure_ptr);
  }
  if (__stream == (FILE *)&__sf_fake_stdin) {
    __stream = *(FILE **)(puVar1 + 4);
  }
  else {
    if (__stream == (FILE *)&__sf_fake_stdout) {
      __stream = *(FILE **)(puVar1 + 8);
    }
    else {
      if (__stream == (FILE *)&__sf_fake_stderr) {
        __stream = *(FILE **)(puVar1 + 0xc);
      }
    }
  }
  if (*(short *)&__stream->_IO_read_base == 0) {
    *(undefined4 *)_impure_ptr = 9;
    iVar2 = -1;
  }
  else {
    iVar2 = (int)*(short *)((int)&__stream->_IO_read_base + 2);
  }
  return iVar2;
}



void std(undefined4 *param_1,undefined2 param_2,undefined2 param_3)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  *(undefined2 *)(param_1 + 3) = param_2;
  param_1[0x19] = 0;
  *(undefined2 *)((int)param_1 + 0xe) = param_3;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  memset(param_1 + 0x17,0,8);
  param_1[9] = 0x14a5d;
  param_1[10] = 0x14a7f;
  param_1[0xb] = 0x14ab7;
  param_1[8] = param_1;
  param_1[0xc] = 0x14adb;
  return;
}



void _cleanup_r(undefined4 param_1)

{
  _fwalk_reent(param_1,0x15d89);
  return;
}



undefined4 * __sfmoreglue(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = (param_2 + -1) * 0x68;
  puVar1 = (undefined4 *)_malloc_r(param_1,iVar2 + 0x74);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = param_2;
    puVar1[2] = puVar1 + 3;
    memset(puVar1 + 3,0,iVar2 + 0x68);
  }
  return puVar1;
}



void __sinit(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_1[6] == 0) {
    param_1[0x12] = 0;
    param_1[0x13] = 0;
    param_1[0x14] = 0;
    puVar2 = &impure_data;
    param_1[10] = 0x13b3d;
    if (param_1 == &impure_data) {
      puVar2 = (undefined4 *)(FUN_00000000 + 1);
    }
    if (param_1 == &impure_data) {
      param_1[6] = puVar2;
    }
    uVar1 = __sfp();
    param_1[1] = uVar1;
    uVar1 = __sfp(param_1);
    param_1[2] = uVar1;
    uVar1 = __sfp(param_1);
    param_1[3] = uVar1;
    std(param_1[1],4,0);
    std(param_1[2],9,1);
    std(param_1[3],0x12,2);
    param_1[6] = 1;
  }
  return;
}



int * __sfp(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int **ppiVar3;
  
  if (DAT_200009b0 == 0) {
    __sinit(&impure_data);
  }
  ppiVar3 = (int **)&DAT_200009e0;
  do {
    piVar1 = ppiVar3[1];
    piVar2 = ppiVar3[2];
    while (piVar1 = (int *)((int)piVar1 + -1), -1 < (int)piVar1) {
      if (*(short *)(piVar2 + 3) == 0) {
        piVar2[0x19] = 0;
        *piVar2 = 0;
        piVar2[1] = 0;
        piVar2[2] = 0;
        piVar2[3] = -0xffff;
        piVar2[4] = 0;
        piVar2[5] = 0;
        piVar2[6] = 0;
        memset(piVar2 + 0x17,0,8);
        piVar2[0xd] = 0;
        piVar2[0xe] = 0;
        piVar2[0x12] = 0;
        piVar2[0x13] = 0;
        return piVar2;
      }
      piVar2 = piVar2 + 0x1a;
    }
    if (*ppiVar3 == (int *)0x0) {
      piVar1 = (int *)__sfmoreglue(param_1,4);
      *ppiVar3 = piVar1;
      if (piVar1 == (int *)0x0) {
        *param_1 = 0xc;
        return (int *)0x0;
      }
    }
    ppiVar3 = (int **)*ppiVar3;
  } while( true );
}



uint _fwalk(int param_1,code *param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = 0;
  for (piVar2 = (int *)(param_1 + 0x48); piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
    iVar5 = piVar2[1];
    iVar3 = piVar2[2];
    while (iVar5 = iVar5 + -1, -1 < iVar5) {
      if ((1 < *(ushort *)(iVar3 + 0xc)) && (*(short *)(iVar3 + 0xe) != -1)) {
        uVar1 = (*param_2)(iVar3);
        uVar4 = uVar4 | uVar1;
      }
      iVar3 = iVar3 + 0x68;
    }
  }
  return uVar4;
}



uint _fwalk_reent(int param_1,code *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = 0;
  for (piVar3 = (int *)(param_1 + 0x48); piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
    iVar6 = piVar3[1];
    iVar4 = piVar3[2];
    while (iVar6 = iVar6 + -1, -1 < iVar6) {
      if ((1 < *(ushort *)(iVar4 + 0xc)) && (iVar2 = *(short *)(iVar4 + 0xe) + 1, iVar2 != 0)) {
        uVar1 = (*param_2)(param_1,iVar4,param_3,iVar2,param_4);
        uVar5 = uVar5 | uVar1;
      }
      iVar4 = iVar4 + 0x68;
    }
  }
  return uVar5;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int getchar(void)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = _impure_ptr;
  if ((_impure_ptr != (undefined *)0x0) && (*(int *)(_impure_ptr + 0x18) == 0)) {
    __sinit(_impure_ptr);
  }
  iVar2 = _getc_r(puVar1,*(undefined4 *)(puVar1 + 4));
  return iVar2;
}



void __libc_init_array(EVP_PKEY_CTX *param_1)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + 1) {
    param_1 = (EVP_PKEY_CTX *)(*(code *)(&__frame_dummy_init_array_entry)[iVar1])();
  }
  _init(param_1);
  for (iVar1 = 0; iVar1 != 1; iVar1 = iVar1 + 1) {
    (*(code *)(&__frame_dummy_init_array_entry)[iVar1])();
  }
  return;
}



int memcmp(void *__s1,void *__s2,size_t __n)

{
  byte *pbVar1;
  byte *pbVar2;
  size_t sVar3;
  
  sVar3 = 0;
  do {
    if (__n == sVar3) {
      return 0;
    }
    pbVar2 = (byte *)((int)__s1 + sVar3);
    pbVar1 = (byte *)((int)__s2 + sVar3);
    sVar3 = sVar3 + 1;
  } while ((uint)*pbVar2 == (uint)*pbVar1);
  return (uint)*pbVar2 - (uint)*pbVar1;
}



void * memcpy(void *__dest,void *__src,size_t __n)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = (undefined *)((int)__dest + -1);
  puVar1 = (undefined *)(__n + (int)__src);
  for (; (undefined *)__src != puVar1; __src = (void *)((int)__src + 1)) {
    puVar2 = puVar2 + 1;
    *puVar2 = *__src;
                    // WARNING: Load size is inaccurate
  }
  return __dest;
}



void * memmove(void *__dest,void *__src,size_t __n)

{
  undefined *puVar1;
  int iVar2;
  undefined *puVar3;
  
  puVar3 = (undefined *)((int)__src + __n);
  if ((__src < __dest) && (__dest < puVar3)) {
    puVar1 = (undefined *)((int)__dest + __n);
    iVar2 = __n - (int)puVar3;
    while (puVar3 + iVar2 != (undefined *)0x0) {
      puVar3 = puVar3 + -1;
      puVar1 = puVar1 + -1;
      *puVar1 = *puVar3;
    }
  }
  else {
    puVar1 = (undefined *)((int)__dest + -1);
    for (; (undefined *)__src != puVar3; __src = (void *)((int)__src + 1)) {
      puVar1 = puVar1 + 1;
      *puVar1 = *__src;
                    // WARNING: Load size is inaccurate
    }
  }
  return __dest;
}



void * memset(void *__s,int __c,size_t __n)

{
  undefined *puVar1;
  
  for (puVar1 = (undefined *)__s; puVar1 != (undefined *)(__n + (int)__s); puVar1 = puVar1 + 1) {
    *puVar1 = (char)__c;
  }
  return __s;
}



uint _malloc_r(undefined4 *param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  
  uVar6 = (param_2 + 3 & 0xfffffffc) + 8;
  if (uVar6 < 0xc) {
    uVar6 = 0xc;
  }
  if (((int)uVar6 < 0) || (uVar6 < param_2)) {
    *param_1 = 0xc;
  }
  else {
    __malloc_lock();
    puVar1 = __malloc_free_list;
    puVar5 = __malloc_free_list;
    while (puVar3 = puVar1, puVar3 != (uint *)0x0) {
      uVar4 = *puVar3 - uVar6;
      if (-1 < (int)uVar4) {
        if (uVar4 < 0xc) {
          puVar1 = (uint *)puVar3[1];
          if (puVar5 != puVar3) {
            puVar5[1] = (uint)(uint *)puVar3[1];
            puVar5 = puVar3;
            puVar1 = __malloc_free_list;
          }
        }
        else {
          *puVar3 = uVar4;
          *(uint *)((int)puVar3 + uVar4) = uVar6;
          puVar5 = (uint *)((int)puVar3 + uVar4);
          puVar1 = __malloc_free_list;
        }
        goto LAB_00013e08;
      }
      puVar5 = puVar3;
      puVar1 = (uint *)puVar3[1];
    }
    if (__malloc_sbrk_start == 0) {
      __malloc_sbrk_start = _sbrk_r(param_1);
    }
    puVar1 = (uint *)_sbrk_r(param_1,uVar6);
    if ((puVar1 != (uint *)0xffffffff) &&
       ((puVar5 = (uint *)((int)puVar1 + 3U & 0xfffffffc), puVar1 == puVar5 ||
        (iVar2 = _sbrk_r(param_1,(int)puVar5 - (int)puVar1), iVar2 != -1)))) {
      *puVar5 = uVar6;
      puVar1 = __malloc_free_list;
LAB_00013e08:
      __malloc_free_list = puVar1;
      __malloc_unlock(param_1);
      uVar6 = (int)puVar5 + 0xbU & 0xfffffff8;
      iVar2 = uVar6 - (int)(puVar5 + 1);
      if (iVar2 == 0) {
        return uVar6;
      }
      *(int *)((int)puVar5 + iVar2) = -iVar2;
      return uVar6;
    }
    *param_1 = 0xc;
    __malloc_unlock(param_1);
  }
  return 0;
}



char * __cvt(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
            int param_6,undefined *param_7,int *param_8,uint param_9,int *param_10)

{
  char *pcVar1;
  char *pcVar2;
  undefined uVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  bool bVar7;
  undefined auStack40 [4];
  char *local_24;
  
  bVar7 = param_4 < 0;
  param_9 = param_9 & 0xffffffdf;
  if (bVar7) {
    iVar4 = param_4 + -0x80000000;
    param_4 = iVar4;
  }
  else {
    iVar4 = 0;
  }
  uVar3 = (undefined)iVar4;
  if (bVar7) {
    uVar3 = 0x2d;
  }
  *param_7 = uVar3;
  if (param_9 == 0x46) {
    uVar5 = 3;
  }
  else {
    if (param_9 == 0x45) {
      param_5 = param_5 + 1;
    }
    uVar5 = 2;
  }
  pcVar2 = (char *)_dtoa_r(param_1,param_7,param_3,param_4,uVar5,param_5,param_8,auStack40,&local_24
                          );
  if ((param_9 != 0x47) || (pcVar1 = local_24, param_6 << 0x1f < 0)) {
    pcVar6 = pcVar2 + param_5;
    if (param_9 == 0x46) {
      if ((*pcVar2 == '0') && (iVar4 = __aeabi_dcmpeq(param_3,param_4,0,0), iVar4 == 0)) {
        *param_8 = 1 - param_5;
      }
      pcVar6 = pcVar6 + *param_8;
    }
    iVar4 = __aeabi_dcmpeq(param_3,param_4,0,0);
    pcVar1 = pcVar6;
    if (iVar4 == 0) {
      while (pcVar1 = local_24, local_24 < pcVar6) {
        *local_24 = '0';
        local_24 = local_24 + 1;
      }
    }
  }
  local_24 = pcVar1;
  *param_10 = (int)local_24 - (int)pcVar2;
  return pcVar2;
}



int __exponent(undefined *param_1,uint param_2,undefined4 param_3)

{
  undefined *puVar1;
  undefined uVar2;
  undefined *puVar3;
  uint uVar4;
  undefined4 uStack28;
  undefined4 uStack24;
  
  uStack24 = param_3;
  uStack28 = param_2;
  if ((int)param_2 < 0) {
    param_2 = -param_2;
    uVar2 = 0x2d;
  }
  else {
    uVar2 = 0x2b;
  }
  *param_1 = (char)param_3;
  param_1[1] = uVar2;
  if ((int)param_2 < 10) {
    param_1[2] = 0x30;
    puVar1 = param_1 + 4;
    param_1[3] = (char)param_2 + '0';
  }
  else {
    puVar1 = (undefined *)((int)&uStack28 + 3);
    do {
      puVar3 = puVar1;
      uVar4 = param_2 / 10;
      puVar3[-1] = (char)param_2 + (char)uVar4 * -10 + '0';
      param_2 = uVar4;
      puVar1 = puVar3 + -1;
    } while (9 < uVar4);
    puVar3[-2] = (char)uVar4 + '0';
    puVar1 = param_1 + 2;
    for (puVar3 = puVar3 + -2; puVar3 < (undefined *)((int)&uStack28 + 3); puVar3 = puVar3 + 1) {
      *puVar1 = *puVar3;
      puVar1 = puVar1 + 1;
    }
  }
  return (int)puVar1 - (int)param_1;
}



uint _printf_float(undefined4 param_1,uint *param_2,undefined4 param_3,code *param_4,uint **param_5)

{
  char **ppcVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  char *__s;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  byte bVar10;
  uint uVar11;
  char local_35;
  uint local_34;
  uint local_30;
  uint local_2c [2];
  
  ppcVar1 = (char **)_localeconv_r();
  __s = *ppcVar1;
  sVar2 = strlen(__s);
  local_30 = 0;
  puVar5 = (uint *)((int)*param_5 + 7U & 0xfffffff8);
  bVar10 = *(byte *)(param_2 + 6);
  uVar11 = *param_2;
  *param_5 = puVar5 + 2;
  uVar6 = puVar5[1];
  param_2[0x12] = *puVar5;
  param_2[0x13] = uVar6;
  uVar6 = param_2[0x12];
  uVar9 = param_2[0x13];
  iVar3 = __unorddf2(uVar6,uVar9 & 0x7fffffff,0xffffffff,0x7fefffff);
  if ((iVar3 == 0) &&
     (iVar3 = __aeabi_dcmple(uVar6,uVar9 & 0x7fffffff,0xffffffff,0x7fefffff), iVar3 == 0)) {
    iVar3 = __aeabi_dcmplt(uVar6,uVar9,0,0);
    if (iVar3 != 0) {
      *(undefined *)((int)param_2 + 0x43) = 0x2d;
    }
    puVar5 = (uint *)&DAT_0001cc44;
    puVar7 = (uint *)&DAT_0001cc40;
LAB_0001400a:
    if (bVar10 < 0x48) {
      puVar5 = puVar7;
    }
    param_2[4] = 3;
    *param_2 = uVar11 & 0xfffffffb;
    uVar11 = 0;
  }
  else {
    iVar3 = __unorddf2(uVar6,uVar9,uVar6,uVar9);
    if (iVar3 != 0) {
      puVar5 = (uint *)&DAT_0001cc4c;
      puVar7 = (uint *)&DAT_0001cc48;
      goto LAB_0001400a;
    }
    uVar8 = param_2[1];
    uVar11 = uVar11 | 0x400;
    if (uVar8 == 0xffffffff) {
      uVar8 = 6;
LAB_00014064:
      param_2[1] = uVar8;
LAB_00014066:
      *param_2 = uVar11;
      puVar5 = (uint *)__cvt(param_1,&local_30,uVar6,uVar9,param_2[1],uVar11,&local_35,&local_34,
                             bVar10,&local_30,0);
      if ((bVar10 & 0xdf) == 0x47) goto LAB_00014094;
LAB_000140a8:
      if (0x65 < bVar10) {
        if (bVar10 != 0x66) goto LAB_00014134;
        uVar11 = param_2[1];
        if ((int)local_34 < 1) {
          if ((uVar11 == 0) && (-1 < (int)(*param_2 << 0x1f))) {
            uVar11 = 1;
          }
          else {
            uVar11 = uVar11 + 2;
          }
        }
        else {
          param_2[4] = local_34;
          if ((uVar11 == 0) && (-1 < (int)(*param_2 << 0x1f))) goto LAB_00014116;
          uVar11 = uVar11 + 1 + local_34;
        }
        goto LAB_00014114;
      }
      local_34 = local_34 - 1;
      uVar11 = __exponent(param_2 + 0x14,local_34,bVar10);
      param_2[4] = local_30 + uVar11;
      if ((1 < (int)local_30) || ((int)(*param_2 << 0x1f) < 0)) {
        param_2[4] = local_30 + uVar11 + 1;
      }
    }
    else {
      if (bVar10 != 0x67) {
        if ((bVar10 == 0x47) && (uVar8 == 0)) goto LAB_000140f6;
        goto LAB_00014066;
      }
      if (uVar8 == 0) {
LAB_000140f6:
        uVar8 = 1;
        goto LAB_00014064;
      }
      *param_2 = uVar11;
      puVar5 = (uint *)__cvt(param_1,&local_35,uVar6,uVar9,uVar8,uVar11,&local_35,&local_34,0x67,
                             &local_30,0);
LAB_00014094:
      if (((int)(local_34 + 3) < 0 != SCARRY4(local_34,3)) || ((int)param_2[1] < (int)local_34)) {
        bVar10 = bVar10 - 2;
        goto LAB_000140a8;
      }
      bVar10 = 0x67;
LAB_00014134:
      if ((int)local_34 < (int)local_30) {
        if ((int)local_34 < 1) {
          iVar3 = 2 - local_34;
        }
        else {
          iVar3 = 1;
        }
        uVar11 = iVar3 + local_30;
LAB_00014114:
        param_2[4] = uVar11;
      }
      else {
        param_2[4] = local_34;
        if ((int)(*param_2 << 0x1f) < 0) {
          uVar11 = local_34 + 1;
          goto LAB_00014114;
        }
      }
LAB_00014116:
      param_2[0x16] = local_34;
      uVar11 = 0;
    }
    if (local_35 != '\0') {
      *(undefined *)((int)param_2 + 0x43) = 0x2d;
    }
  }
  iVar3 = _printf_common(param_1,param_2,local_2c,param_3,param_4);
  if (iVar3 == -1) {
    return 0xffffffff;
  }
  if ((int)(*param_2 << 0x15) < 0) {
    if (bVar10 < 0x66) {
      if (((int)local_30 < 2) && (-1 < (int)(*param_2 << 0x1f))) {
        iVar4 = 1;
LAB_00014372:
        iVar3 = (*param_4)(param_1,param_3,puVar5,iVar4);
        if (iVar3 == -1) {
          return 0xffffffff;
        }
      }
      else {
        iVar3 = (*param_4)(param_1,param_3,puVar5,1);
        if (iVar3 == -1) {
          return 0xffffffff;
        }
        iVar3 = (*param_4)(param_1,param_3,__s,sVar2);
        puVar5 = (uint *)((int)puVar5 + 1);
        if (iVar3 == -1) {
          return 0xffffffff;
        }
        iVar4 = local_30 - 1;
        iVar3 = __aeabi_dcmpeq(param_2[0x12],param_2[0x13],0,0);
        if (iVar3 == 0) goto LAB_00014372;
        for (iVar3 = 0; iVar3 < (int)(local_30 - 1); iVar3 = iVar3 + 1) {
          iVar4 = (*param_4)(param_1,param_3,(int)param_2 + 0x1a,1);
          if (iVar4 == -1) {
            return 0xffffffff;
          }
        }
      }
      puVar5 = param_2 + 0x14;
    }
    else {
      iVar3 = __aeabi_dcmpeq(param_2[0x12],param_2[0x13],0,0);
      if (iVar3 != 0) {
        iVar3 = (*param_4)(param_1,param_3,&DAT_0001cc50,1);
        if (iVar3 == -1) {
          return 0xffffffff;
        }
        if (((int)local_34 < (int)local_30) || ((int)(*param_2 << 0x1f) < 0)) {
          iVar3 = (*param_4)(param_1,param_3,__s,sVar2);
          if (iVar3 == -1) {
            return 0xffffffff;
          }
          for (iVar3 = 0; iVar3 < (int)(local_30 - 1); iVar3 = iVar3 + 1) {
            iVar4 = (*param_4)(param_1,param_3,(int)param_2 + 0x1a,1);
            if (iVar4 == -1) {
              return 0xffffffff;
            }
          }
        }
        goto LAB_000141c2;
      }
      if (0 < (int)local_34) {
        uVar11 = local_30;
        if ((int)param_2[0x16] <= (int)local_30) {
          uVar11 = param_2[0x16];
        }
        if ((0 < (int)uVar11) && (iVar3 = (*param_4)(param_1,param_3,puVar5,uVar11), iVar3 == -1)) {
          return 0xffffffff;
        }
        for (iVar3 = 0; uVar6 = param_2[0x16],
            iVar3 < (int)(uVar6 - (uVar11 & ~((int)uVar11 >> 0x1f))); iVar3 = iVar3 + 1) {
          iVar4 = (*param_4)(param_1,param_3,(int)param_2 + 0x1a,1);
          if (iVar4 == -1) {
            return 0xffffffff;
          }
        }
        if ((((int)local_34 < (int)local_30) || ((int)(*param_2 << 0x1f) < 0)) &&
           (iVar3 = (*param_4)(param_1,param_3,__s,sVar2), iVar3 == -1)) {
          return 0xffffffff;
        }
        uVar11 = local_30 - local_34;
        if ((int)(local_30 - uVar6) <= (int)(local_30 - local_34)) {
          uVar11 = local_30 - uVar6;
        }
        if ((0 < (int)uVar11) &&
           (iVar3 = (*param_4)(param_1,param_3,(undefined1 *)((int)puVar5 + uVar6),uVar11),
           iVar3 == -1)) {
          return 0xffffffff;
        }
        for (iVar3 = 0; iVar3 < (int)((local_30 - local_34) - (uVar11 & ~((int)uVar11 >> 0x1f)));
            iVar3 = iVar3 + 1) {
          iVar4 = (*param_4)(param_1,param_3,(int)param_2 + 0x1a,1);
          if (iVar4 == -1) {
            return 0xffffffff;
          }
        }
        goto LAB_000141c2;
      }
      iVar3 = (*param_4)(param_1,param_3,&DAT_0001cc50,1);
      if (iVar3 == -1) {
        return 0xffffffff;
      }
      if (((local_34 == 0) && (local_30 == 0)) && (-1 < (int)(*param_2 << 0x1f))) goto LAB_000141c2;
      iVar3 = (*param_4)(param_1,param_3,__s,sVar2);
      if (iVar3 == -1) {
        return 0xffffffff;
      }
      for (iVar3 = 0; uVar11 = local_30, -iVar3 != local_34 && iVar3 <= (int)-local_34;
          iVar3 = iVar3 + 1) {
        iVar4 = (*param_4)(param_1,param_3,(int)param_2 + 0x1a,1);
        if (iVar4 == -1) {
          return 0xffffffff;
        }
      }
    }
  }
  else {
    uVar11 = param_2[4];
  }
  iVar3 = (*param_4)(param_1,param_3,puVar5,uVar11);
  if (iVar3 == -1) {
    return 0xffffffff;
  }
LAB_000141c2:
  if ((int)(*param_2 << 0x1e) < 0) {
    for (iVar3 = 0; iVar3 < (int)(param_2[3] - local_2c[0]); iVar3 = iVar3 + 1) {
      iVar4 = (*param_4)(param_1,param_3,(int)param_2 + 0x19,1);
      if (iVar4 == -1) {
        return 0xffffffff;
      }
    }
  }
  if ((int)param_2[3] < (int)local_2c[0]) {
    return local_2c[0];
  }
  return param_2[3];
}



undefined4
_printf_common(undefined4 param_1,uint *param_2,uint *param_3,undefined4 param_4,code *param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  uVar3 = param_2[4];
  if ((int)param_2[4] < (int)param_2[2]) {
    uVar3 = param_2[2];
  }
  *param_3 = uVar3;
  if (*(char *)((int)param_2 + 0x43) != '\0') {
    *param_3 = uVar3 + 1;
  }
  if ((int)(*param_2 << 0x1a) < 0) {
    *param_3 = *param_3 + 2;
  }
  uVar3 = *param_2 & 6;
  if (uVar3 == 0) {
    for (; (int)uVar3 < (int)(param_2[3] - *param_3); uVar3 = uVar3 + 1) {
      iVar1 = (*param_5)(param_1,param_4,(int)param_2 + 0x19,1);
      if (iVar1 == -1) goto LAB_000144ba;
    }
  }
  uVar3 = (uint)*(byte *)((int)param_2 + 0x43);
  if (uVar3 != 0) {
    uVar3 = 1;
  }
  if ((int)(*param_2 << 0x1a) < 0) {
    *(undefined *)((int)param_2 + uVar3 + 0x43) = 0x30;
    *(undefined *)((int)param_2 + uVar3 + 0x44) = *(undefined *)((int)param_2 + 0x45);
    uVar3 = uVar3 + 2;
  }
  iVar1 = (*param_5)(param_1,param_4,(int)param_2 + 0x43,uVar3);
  if (iVar1 == -1) {
LAB_000144ba:
    uVar2 = 0xffffffff;
  }
  else {
    uVar3 = param_2[3];
    bVar5 = (*param_2 & 6) == 4;
    if (bVar5) {
      uVar3 = uVar3 - *param_3;
    }
    if (bVar5) {
      uVar3 = uVar3 & ~((int)uVar3 >> 0x1f);
    }
    else {
      uVar3 = 0;
    }
    if ((int)param_2[4] < (int)param_2[2]) {
      uVar3 = uVar3 + (param_2[2] - param_2[4]);
    }
    for (uVar4 = 0; uVar3 != uVar4; uVar4 = uVar4 + 1) {
      iVar1 = (*param_5)(param_1,param_4,(int)param_2 + 0x1a,1);
      if (iVar1 == -1) goto LAB_000144ba;
    }
    uVar2 = 0;
  }
  return uVar2;
}



uint _printf_i(undefined4 param_1,uint *param_2,undefined4 param_3,code *param_4,uint **param_5)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  uint **ppuVar9;
  char **ppcVar10;
  uint uVar11;
  char *pcVar12;
  char *__s;
  uint local_24 [2];
  
  __s = (char *)((int)param_2 + 0x43);
  bVar1 = *(byte *)(param_2 + 6);
  if (bVar1 == 0x6e) {
    ppuVar9 = (uint **)*param_5;
    uVar6 = *param_2;
    uVar8 = param_2[5];
    *param_5 = (uint *)(ppuVar9 + 1);
    puVar7 = *ppuVar9;
    if (((int)(uVar6 << 0x18) < 0) || (-1 < (int)(uVar6 << 0x19))) {
      *puVar7 = uVar8;
    }
    else {
      *(short *)puVar7 = (short)uVar8;
    }
LAB_00014690:
    param_2[4] = 0;
    goto LAB_0001460c;
  }
  if (bVar1 < 0x6f) {
    if (bVar1 != 99) {
      if (bVar1 < 100) {
        if (bVar1 == 0) goto LAB_00014690;
        if (bVar1 != 0x58) goto LAB_00014524;
        pcVar3 = "0123456789ABCDEF";
        *(undefined *)((int)param_2 + 0x45) = 0x58;
LAB_00014630:
        uVar6 = *param_2;
        uVar8 = **param_5;
        *param_5 = *param_5 + 1;
        if ((-1 < (int)(uVar6 << 0x18)) && ((int)(uVar6 << 0x19) < 0)) {
          uVar8 = uVar8 & 0xffff;
        }
        if ((int)(uVar6 << 0x1f) < 0) {
          *param_2 = uVar6 | 0x20;
        }
        if (uVar8 == 0) {
          *param_2 = *param_2 & 0xffffffdf;
        }
        uVar6 = 0x10;
LAB_000145c6:
        *(undefined *)((int)param_2 + 0x43) = 0;
      }
      else {
        if ((bVar1 != 100) && (bVar1 != 0x69)) goto LAB_00014524;
        uVar6 = *param_2;
        puVar7 = *param_5;
        if ((int)(uVar6 << 0x18) < 0) {
          uVar8 = *puVar7;
          *param_5 = puVar7 + 1;
        }
        else {
          uVar8 = *puVar7;
          *param_5 = puVar7 + 1;
          if ((uVar6 & 0x40) != 0) {
            uVar8 = SEXT24((short)uVar8);
          }
        }
        if ((int)uVar8 < 0) {
          uVar8 = -uVar8;
          *(undefined *)((int)param_2 + 0x43) = 0x2d;
        }
        pcVar3 = "0123456789ABCDEF";
        uVar6 = 10;
      }
      uVar11 = param_2[1];
      param_2[2] = uVar11;
      pcVar12 = __s;
      if ((int)uVar11 < 0) {
        if (uVar8 != 0) goto LAB_00014660;
LAB_00014704:
        *(char *)((int)param_2 + 0x42) = *pcVar3;
        pcVar12 = (char *)((int)param_2 + 0x42);
      }
      else {
        *param_2 = *param_2 & 0xfffffffb;
        if (uVar8 == 0) {
          if (uVar11 != 0) goto LAB_00014704;
        }
        else {
LAB_00014660:
          do {
            uVar11 = uVar8 / uVar6;
            pcVar12 = pcVar12 + -1;
            *pcVar12 = pcVar3[uVar8 - uVar6 * uVar11];
            uVar8 = uVar11;
          } while (uVar11 != 0);
        }
      }
      if (((uVar6 == 8) && ((int)(*param_2 << 0x1f) < 0)) && ((int)param_2[1] <= (int)param_2[4])) {
        pcVar12[-1] = '0';
        pcVar12 = pcVar12 + -1;
      }
      param_2[4] = (int)__s - (int)pcVar12;
      __s = pcVar12;
      goto LAB_0001460c;
    }
    uVar8 = **param_5;
    *param_5 = *param_5 + 1;
    *(char *)((int)param_2 + 0x42) = (char)uVar8;
LAB_00014594:
    __s = (char *)((int)param_2 + 0x42);
    uVar8 = 1;
  }
  else {
    if (bVar1 != 0x73) {
      if (bVar1 < 0x74) {
        if (bVar1 == 0x6f) {
LAB_000145a6:
          puVar7 = *param_5;
          uVar8 = *param_2;
          *param_5 = puVar7 + 1;
          if (((int)(uVar8 << 0x18) < 0) || (-1 < (int)(uVar8 << 0x19))) {
            uVar8 = *puVar7;
          }
          else {
            uVar8 = (uint)*(ushort *)puVar7;
          }
          pcVar3 = "0123456789ABCDEF";
          if (bVar1 == 0x6f) {
            uVar6 = 8;
          }
          else {
            uVar6 = 10;
          }
          goto LAB_000145c6;
        }
        if (bVar1 == 0x70) {
          *param_2 = *param_2 | 0x20;
LAB_0001457a:
          *(undefined *)((int)param_2 + 0x45) = 0x78;
          pcVar3 = "0123456789abcdef";
          goto LAB_00014630;
        }
      }
      else {
        if (bVar1 == 0x75) goto LAB_000145a6;
        if (bVar1 == 0x78) goto LAB_0001457a;
      }
LAB_00014524:
      *(byte *)((int)param_2 + 0x42) = bVar1;
      goto LAB_00014594;
    }
    ppcVar10 = (char **)*param_5;
    *param_5 = (uint *)(ppcVar10 + 1);
    __s = *ppcVar10;
    pvVar4 = memchr(__s,0,param_2[1]);
    if (pvVar4 != (void *)0x0) {
      param_2[1] = (int)pvVar4 - (int)__s;
    }
    uVar8 = param_2[1];
  }
  param_2[4] = uVar8;
  *(undefined *)((int)param_2 + 0x43) = 0;
LAB_0001460c:
  iVar2 = _printf_common(param_1,param_2,local_24,param_3,param_4);
  if ((iVar2 == -1) || (iVar2 = (*param_4)(param_1,param_3,__s,param_2[4]), iVar2 == -1)) {
LAB_00014620:
    uVar8 = 0xffffffff;
  }
  else {
    if ((int)(*param_2 << 0x1e) < 0) {
      for (iVar2 = 0; iVar2 < (int)(param_2[3] - local_24[0]); iVar2 = iVar2 + 1) {
        iVar5 = (*param_4)(param_1,param_3,(int)param_2 + 0x19,1);
        if (iVar5 == -1) goto LAB_00014620;
      }
    }
    uVar8 = param_2[3];
    if ((int)param_2[3] < (int)local_24[0]) {
      uVar8 = local_24[0];
    }
  }
  return uVar8;
}



int iprintf(char *__format,...)

{
  undefined *puVar1;
  int iVar2;
  undefined4 in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  char *pcVar3;
  undefined4 uStack12;
  undefined4 uStack8;
  undefined4 uStack4;
  
  puVar1 = _impure_ptr;
  pcVar3 = __format;
  uStack12 = in_r1;
  uStack8 = in_r2;
  uStack4 = in_r3;
  if ((_impure_ptr != (undefined *)0x0) && (*(int *)(_impure_ptr + 0x18) == 0)) {
    __sinit(_impure_ptr);
  }
  iVar2 = _vfprintf_r(puVar1,*(undefined4 *)(puVar1 + 8),__format,&uStack12,pcVar3,&uStack12);
  return iVar2;
}



int putchar(int __c)

{
  undefined *puVar1;
  int iVar2;
  undefined4 in_r3;
  
  puVar1 = _impure_ptr;
  if ((_impure_ptr != (undefined *)0x0) && (*(int *)(_impure_ptr + 0x18) == 0)) {
    __sinit(_impure_ptr);
  }
  iVar2 = _putc_r(puVar1,__c,*(undefined4 *)(puVar1 + 8),in_r3);
  return iVar2;
}



undefined4 _puts_r(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char **ppcVar4;
  char *pcVar5;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x18) == 0)) {
    __sinit();
  }
  ppcVar4 = *(char ***)(param_1 + 8);
  if (*(int *)(param_1 + 0x18) == 0) {
    __sinit(param_1);
  }
  if (ppcVar4 == (char **)&__sf_fake_stdin) {
    ppcVar4 = *(char ***)(param_1 + 4);
  }
  else {
    if (ppcVar4 == (char **)&__sf_fake_stdout) {
      ppcVar4 = *(char ***)(param_1 + 8);
    }
    else {
      if (ppcVar4 == (char **)&__sf_fake_stderr) {
        ppcVar4 = *(char ***)(param_1 + 0xc);
      }
    }
  }
  if ((((int)((uint)*(ushort *)(ppcVar4 + 3) << 0x1c) < 0) && (ppcVar4[4] != (char *)0x0)) ||
     (iVar2 = __swsetup_r(param_1,ppcVar4), iVar2 == 0)) {
    pcVar5 = (char *)(param_2 + -1);
    do {
      while( true ) {
        pcVar5 = pcVar5 + 1;
        cVar1 = *pcVar5;
        pcVar3 = ppcVar4[2] + -1;
        ppcVar4[2] = pcVar3;
        if (cVar1 == '\0') {
          if (-1 < (int)pcVar3) {
            pcVar5 = *ppcVar4;
            *ppcVar4 = pcVar5 + 1;
            *pcVar5 = '\n';
            return 10;
          }
          iVar2 = __swbuf_r(param_1,10,ppcVar4);
          if (iVar2 == -1) {
            return 0xffffffff;
          }
          return 10;
        }
        if (((int)pcVar3 < 0) && (((int)pcVar3 < (int)ppcVar4[6] || (cVar1 == '\n')))) break;
        pcVar3 = *ppcVar4;
        *ppcVar4 = pcVar3 + 1;
        *pcVar3 = cVar1;
      }
      iVar2 = __swbuf_r(param_1,cVar1,ppcVar4);
    } while (iVar2 != -1);
  }
  return 0xffffffff;
}



int puts(char *__s)

{
  int iVar1;
  
  iVar1 = _puts_r(_impure_ptr,__s);
  return iVar1;
}



void _sbrk_r(int *param_1,int param_2)

{
  caddr_t pcVar1;
  
  errno = 0;
  pcVar1 = _sbrk(param_2);
  if ((pcVar1 == (caddr_t)0xffffffff) && (errno != 0)) {
    *param_1 = errno;
  }
  return;
}



int setvbuf(FILE *__stream,char *__buf,int __modes,size_t __n)

{
  undefined *puVar1;
  FILE *pFVar2;
  ushort uVar3;
  char *pcVar4;
  int iVar5;
  FILE *__size;
  bool bVar6;
  FILE *local_28;
  char *pcStack36;
  int iStack32;
  
  puVar1 = _impure_ptr;
  local_28 = __stream;
  pcStack36 = __buf;
  iStack32 = __modes;
  if ((_impure_ptr != (undefined *)0x0) && (*(int *)(_impure_ptr + 0x18) == 0)) {
    __sinit(_impure_ptr);
  }
  if (__stream == (FILE *)&__sf_fake_stdin) {
    __stream = *(FILE **)(puVar1 + 4);
  }
  else {
    if (__stream == (FILE *)&__sf_fake_stdout) {
      __stream = *(FILE **)(puVar1 + 8);
    }
    else {
      if (__stream == (FILE *)&__sf_fake_stderr) {
        __stream = *(FILE **)(puVar1 + 0xc);
      }
    }
  }
  if ((__modes != 2) && ((1 < (uint)__modes || ((int)__n < 0)))) {
    return (int)(char *)0xffffffff;
  }
  _fflush_r(puVar1,__stream);
  if (__stream->_chain != (_IO_FILE *)0x0) {
    if (__stream->_chain != (_IO_FILE *)&__stream->_cur_column) {
      _free_r(puVar1);
    }
    __stream->_chain = (_IO_FILE *)0x0;
  }
  __stream->_IO_write_end = (char *)0x0;
  __stream->_IO_read_ptr = (char *)0x0;
  if ((int)((uint)*(ushort *)&__stream->_IO_read_base << 0x18) < 0) {
    _free_r(puVar1,__stream->_IO_write_base);
  }
  *(ushort *)&__stream->_IO_read_base = *(ushort *)&__stream->_IO_read_base & 0xf35c;
  if (__modes == 2) {
    pcVar4 = (char *)0x0;
LAB_00014902:
    *(ushort *)&__stream->_IO_read_base = *(ushort *)&__stream->_IO_read_base | 2;
    __stream->_IO_read_end = (char *)0x0;
    __stream->_flags = (int)__stream->_shortbuf;
    __stream->_IO_write_base = __stream->_shortbuf;
    __stream->_IO_write_ptr = (char *)(FUN_00000000 + 1);
  }
  else {
    uVar3 = __swhatbuf_r(puVar1,__stream,&local_28,&pcStack36);
    *(ushort *)&__stream->_IO_read_base = uVar3 | *(ushort *)&__stream->_IO_read_base;
    __size = local_28;
    if ((__n == 0) || (__size = (FILE *)__n, __buf == (char *)0x0)) {
      __buf = (char *)malloc((size_t)__size);
      pFVar2 = local_28;
      __n = (size_t)__size;
      if ((__buf == (char *)0x0) &&
         ((local_28 == __size ||
          (__buf = (char *)malloc((size_t)local_28), __n = (size_t)pFVar2, __buf == (char *)0x0))))
      {
        pcVar4 = (char *)0xffffffff;
        goto LAB_00014902;
      }
      *(ushort *)&__stream->_IO_read_base = *(ushort *)&__stream->_IO_read_base | 0x80;
    }
    iVar5 = *(int *)(puVar1 + 0x18);
    if (iVar5 == 0) {
      __sinit(puVar1);
    }
    uVar3 = (ushort)iVar5;
    bVar6 = __modes == 1;
    if (bVar6) {
      uVar3 = *(ushort *)&__stream->_IO_read_base;
    }
    __stream->_flags = (int)__buf;
    if (bVar6) {
      uVar3 = uVar3 | 1;
    }
    if (bVar6) {
      *(ushort *)&__stream->_IO_read_base = uVar3;
    }
    uVar3 = *(ushort *)&__stream->_IO_read_base;
    pcVar4 = (char *)(uVar3 & 8);
    __stream->_IO_write_base = __buf;
    __stream->_IO_write_ptr = (char *)__n;
    if ((uVar3 & 8) == 0) {
      __stream->_IO_read_end = pcVar4;
    }
    else {
      pcVar4 = (char *)(uVar3 & 1);
      bVar6 = (uVar3 & 1) != 0;
      if (bVar6) {
        __n = -__n;
      }
      if (bVar6) {
        __stream->_IO_read_end = (char *)0x0;
      }
      if (bVar6) {
        __stream->_IO_write_end = (char *)__n;
        pcVar4 = (char *)0x0;
      }
      if (!bVar6) {
        __stream->_IO_read_end = (char *)__n;
      }
    }
  }
  return (int)pcVar4;
}



int sniprintf(char *__s,size_t __maxlen,char *__format,...)

{
  undefined *puVar1;
  int iVar2;
  char *local_80 [2];
  size_t local_78;
  undefined2 local_74;
  undefined2 local_72;
  char *local_70;
  size_t local_6c;
  
  puVar1 = _impure_ptr;
  if ((int)__maxlen < 0) {
    *(undefined4 *)_impure_ptr = 0x8b;
    iVar2 = -1;
  }
  else {
    local_74 = 0x208;
    local_78 = __maxlen;
    if (__maxlen != 0) {
      local_78 = __maxlen - 1;
    }
    local_72 = 0xffff;
    local_80[0] = __s;
    local_70 = __s;
    local_6c = local_78;
    iVar2 = _svfiprintf_r(_impure_ptr,local_80,__format);
    if (iVar2 + 1 < 0 != SCARRY4(iVar2,1)) {
      *(undefined4 *)puVar1 = 0x8b;
    }
    if (__maxlen != 0) {
      *local_80[0] = '\0';
    }
  }
  return iVar2;
}



int siprintf(char *__s,char *__format,...)

{
  int iVar1;
  undefined4 in_r2;
  undefined4 in_r3;
  char *local_78 [2];
  undefined4 local_70;
  undefined4 local_6c;
  char *local_68;
  undefined4 local_64;
  char *pcStack12;
  undefined4 uStack8;
  undefined4 uStack4;
  
  local_64 = 0x7fffffff;
  local_70 = 0x7fffffff;
  local_6c = 0xffff0208;
  local_78[0] = __s;
  local_68 = __s;
  pcStack12 = __format;
  uStack8 = in_r2;
  uStack4 = in_r3;
  iVar1 = _svfiprintf_r(_impure_ptr,local_78,__format);
  *local_78[0] = '\0';
  return iVar1;
}



void __sread(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  iVar1 = _read_r(param_1,(int)*(short *)(param_2 + 0xe));
  bVar3 = -1 < iVar1;
  if (bVar3) {
    uVar2 = *(int *)(param_2 + 0x54) + iVar1;
  }
  else {
    uVar2 = *(ushort *)(param_2 + 0xc) & 0xffffefff;
  }
  if (bVar3) {
    *(uint *)(param_2 + 0x54) = uVar2;
  }
  if (!bVar3) {
    *(short *)(param_2 + 0xc) = (short)uVar2;
  }
  return;
}



void __swrite(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  if ((int)((uint)*(ushort *)(param_2 + 0xc) << 0x17) < 0) {
    _lseek_r(param_1,(int)*(short *)(param_2 + 0xe),0,2);
  }
  *(ushort *)(param_2 + 0xc) = *(ushort *)(param_2 + 0xc) & 0xefff;
  _write_r(param_1,(int)*(short *)(param_2 + 0xe),param_3,param_4);
  return;
}



void __sseek(undefined4 param_1,int param_2)

{
  int iVar1;
  ushort uVar2;
  bool bVar3;
  
  iVar1 = _lseek_r(param_1,(int)*(short *)(param_2 + 0xe));
  bVar3 = iVar1 == -1;
  if (bVar3) {
    uVar2 = *(ushort *)(param_2 + 0xc) & 0xefff;
  }
  else {
    *(int *)(param_2 + 0x54) = iVar1;
    uVar2 = *(ushort *)(param_2 + 0xc) | 0x1000;
  }
  if (bVar3) {
    *(ushort *)(param_2 + 0xc) = uVar2;
  }
  if (!bVar3) {
    *(ushort *)(param_2 + 0xc) = uVar2;
  }
  return;
}



void __sclose(undefined4 param_1,int param_2)

{
  _close_r(param_1,(int)*(short *)(param_2 + 0xe));
  return;
}



int strcasecmp(char *__s1,char *__s2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  do {
    uVar2 = (uint)(byte)*__s1;
    iVar1 = __locale_ctype_ptr();
    uVar3 = (uint)(byte)*__s2;
    if ((*(byte *)(iVar1 + uVar2 + 1) & 3) == 1) {
      uVar2 = uVar2 + 0x20;
    }
    iVar1 = __locale_ctype_ptr();
    if ((*(byte *)(iVar1 + uVar3 + 1) & 3) == 1) {
      uVar3 = uVar3 + 0x20;
    }
  } while ((uVar2 - uVar3 == 0) &&
          (__s1 = (char *)((byte *)__s1 + 1), __s2 = (char *)((byte *)__s2 + 1), uVar3 != 0));
  return uVar2 - uVar3;
}



char * strchr(char *__s,int __c)

{
  byte *pbVar1;
  
  do {
    pbVar1 = (byte *)__s;
    if (*pbVar1 == 0) {
      if ((__c & 0xffU) == 0) {
        return (char *)pbVar1;
      }
      return (char *)(byte *)0x0;
    }
    __s = (char *)(pbVar1 + 1);
  } while ((uint)*pbVar1 != (__c & 0xffU));
  return (char *)pbVar1;
}



int strcmp(char *__s1,char *__s2)

{
  byte bVar1;
  uint uVar2;
  bool bVar3;
  
  do {
    uVar2 = (uint)(byte)*__s1;
    bVar1 = *__s2;
    bVar3 = uVar2 == 1;
    if (uVar2 != 0) {
      bVar3 = uVar2 == bVar1;
    }
    __s1 = (char *)((byte *)__s1 + 1);
    __s2 = (char *)((byte *)__s2 + 1);
  } while (bVar3);
  return uVar2 - bVar1;
}



size_t strlen(char *__s)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar3 = __s;
  do {
    pcVar2 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar2;
  } while (cVar1 != '\0');
  return (size_t)(pcVar2 + (-1 - (int)__s));
}



char * __strtok_r(char *__s,char *__delim,char **__save_ptr)

{
  byte bVar1;
  byte *pbVar2;
  int in_r3;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  
  if ((__s != (char *)0x0) ||
     (pbVar2 = (byte *)*__save_ptr, __s = (char *)pbVar2, pbVar2 != (byte *)0x0)) {
    do {
      pbVar2 = (byte *)__s;
      __s = (char *)(pbVar2 + 1);
      pbVar4 = (byte *)__delim;
      do {
        bVar1 = *pbVar4;
        if (bVar1 == 0) {
          if (*pbVar2 == 0) {
            *__save_ptr = (char *)0x0;
            return (char *)(byte *)0x0;
          }
          do {
            pbVar3 = (byte *)__s;
            pbVar4 = (byte *)(uint)*pbVar3;
            pbVar5 = (byte *)__delim;
            do {
              bVar1 = *pbVar5;
              if (pbVar4 == (byte *)(uint)bVar1) {
                if (pbVar4 != (byte *)0x0) {
                  *pbVar3 = 0;
                  pbVar4 = pbVar3 + 1;
                }
                *__save_ptr = (char *)pbVar4;
                return (char *)pbVar2;
              }
              __s = (char *)(pbVar3 + 1);
              pbVar5 = pbVar5 + 1;
            } while ((byte *)(uint)bVar1 != (byte *)0x0);
          } while( true );
        }
        pbVar4 = pbVar4 + 1;
      } while (*pbVar2 != bVar1);
    } while (in_r3 != 0);
    *__save_ptr = __s;
    *pbVar2 = 0;
  }
  return (char *)pbVar2;
}



char * strtok_r(char *__s,char *__delim,char **__save_ptr)

{
  char *pcVar1;
  
  pcVar1 = __strtok_r(__s,__delim,__save_ptr);
  return pcVar1;
}



uint _strtol_l_isra_0(undefined4 *param_1,byte *param_2,byte **param_3,uint param_4,
                     undefined4 param_5)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint uVar10;
  
  pbVar8 = param_2;
  do {
    pbVar9 = pbVar8;
    pbVar8 = pbVar9 + 1;
    uVar7 = (uint)*pbVar9;
    iVar2 = __locale_ctype_ptr_l(param_5);
    bVar1 = *(byte *)(iVar2 + uVar7 + 1);
    bVar5 = bVar1 & 8;
  } while ((bVar1 & 8) != 0);
  if (uVar7 == 0x2d) {
    uVar7 = (uint)pbVar9[1];
    pbVar8 = pbVar9 + 2;
    bVar5 = 1;
  }
  else {
    if (uVar7 == 0x2b) {
      pbVar8 = pbVar9 + 2;
      uVar7 = (uint)pbVar9[1];
    }
  }
  if (param_4 == 0) {
    if (uVar7 != 0x30) {
      param_4 = 10;
      goto LAB_00014c00;
    }
  }
  else {
    if ((param_4 != 0x10) || (uVar7 != 0x30)) goto LAB_00014c00;
  }
  if ((*pbVar8 & 0xdf) == 0x58) {
    uVar7 = (uint)pbVar8[1];
    param_4 = 0x10;
    pbVar8 = pbVar8 + 2;
  }
  else {
    uVar7 = 0x30;
    if (param_4 == 0) {
      param_4 = 8;
    }
  }
LAB_00014c00:
  if (bVar5 == 0) {
    uVar4 = 0x7fffffff;
  }
  else {
    uVar4 = 0x80000000;
  }
  iVar2 = 0;
  uVar10 = uVar4 / param_4;
  uVar3 = 0;
  do {
    uVar6 = uVar7 - 0x30;
    if (9 < uVar6) {
      if (uVar7 - 0x41 < 0x1a) {
        uVar6 = uVar7 - 0x37;
      }
      else {
        if (0x19 < uVar7 - 0x61) break;
        uVar6 = uVar7 - 0x57;
      }
    }
    if ((int)param_4 <= (int)uVar6) break;
    if (iVar2 != -1) {
      if ((uVar10 < uVar3) || ((uVar10 == uVar3 && ((int)(uVar4 - param_4 * uVar10) < (int)uVar6))))
      {
        iVar2 = -1;
      }
      else {
        uVar3 = uVar3 * param_4 + uVar6;
        iVar2 = 1;
      }
    }
    uVar7 = (uint)*pbVar8;
    pbVar8 = pbVar8 + 1;
  } while( true );
  if (iVar2 == -1) {
    *param_1 = 0x22;
    uVar3 = uVar4;
    if (param_3 == (byte **)0x0) {
      return uVar4;
    }
  }
  else {
    if (bVar5 != 0) {
      uVar3 = -uVar3;
    }
    if (param_3 == (byte **)0x0) {
      return uVar3;
    }
    if (iVar2 == 0) goto LAB_00014c94;
  }
  param_2 = pbVar8 + -1;
LAB_00014c94:
  *param_3 = param_2;
  return uVar3;
}



long strtol(char *__nptr,char **__endptr,int __base)

{
  long lVar1;
  undefined1 *puVar2;
  
  puVar2 = *(undefined1 **)(_impure_ptr + 0x20);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &__global_locale;
  }
  lVar1 = _strtol_l_isra_0(_impure_ptr,__nptr,__endptr,__base,puVar2,__endptr,__base);
  return lVar1;
}



uint _strtoul_l_isra_0(undefined4 *param_1,byte *param_2,byte **param_3,uint param_4,
                      undefined4 param_5)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  uint uVar9;
  
  pbVar7 = param_2;
  do {
    pbVar8 = pbVar7;
    pbVar7 = pbVar8 + 1;
    uVar6 = (uint)*pbVar8;
    iVar2 = __locale_ctype_ptr_l(param_5);
    bVar1 = *(byte *)(iVar2 + uVar6 + 1);
    bVar5 = bVar1 & 8;
  } while ((bVar1 & 8) != 0);
  if (uVar6 == 0x2d) {
    uVar6 = (uint)pbVar8[1];
    pbVar7 = pbVar8 + 2;
    bVar5 = 1;
  }
  else {
    if (uVar6 == 0x2b) {
      pbVar7 = pbVar8 + 2;
      uVar6 = (uint)pbVar8[1];
    }
  }
  if (param_4 == 0) {
    if (uVar6 != 0x30) {
      param_4 = 10;
      goto LAB_00014d22;
    }
  }
  else {
    if ((param_4 != 0x10) || (uVar6 != 0x30)) goto LAB_00014d22;
  }
  if ((*pbVar7 & 0xdf) == 0x58) {
    uVar6 = (uint)pbVar7[1];
    param_4 = 0x10;
    pbVar7 = pbVar7 + 2;
  }
  else {
    uVar6 = 0x30;
    if (param_4 == 0) {
      param_4 = 8;
    }
  }
LAB_00014d22:
  iVar2 = 0;
  uVar4 = 0xffffffff / param_4;
  uVar3 = 0;
  do {
    uVar9 = uVar6 - 0x30;
    if (9 < uVar9) {
      if (uVar6 - 0x41 < 0x1a) {
        uVar9 = uVar6 - 0x37;
      }
      else {
        if (0x19 < uVar6 - 0x61) break;
        uVar9 = uVar6 - 0x57;
      }
    }
    if ((int)param_4 <= (int)uVar9) break;
    if (((iVar2 < 0) || (uVar4 < uVar3)) ||
       ((uVar4 == uVar3 && ((int)~(param_4 * uVar4) < (int)uVar9)))) {
      iVar2 = -1;
    }
    else {
      uVar3 = uVar3 * param_4 + uVar9;
      iVar2 = 1;
    }
    uVar6 = (uint)*pbVar7;
    pbVar7 = pbVar7 + 1;
  } while( true );
  if (iVar2 < 0) {
    *param_1 = 0x22;
    uVar3 = 0xffffffff;
    if (param_3 == (byte **)0x0) {
      return 0xffffffff;
    }
  }
  else {
    if (bVar5 != 0) {
      uVar3 = -uVar3;
    }
    if (param_3 == (byte **)0x0) {
      return uVar3;
    }
    if (iVar2 == 0) goto LAB_00014db4;
  }
  param_2 = pbVar7 + -1;
LAB_00014db4:
  *param_3 = param_2;
  return uVar3;
}



ulong strtoul(char *__nptr,char **__endptr,int __base)

{
  ulong uVar1;
  undefined1 *puVar2;
  
  puVar2 = *(undefined1 **)(_impure_ptr + 0x20);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &__global_locale;
  }
  uVar1 = _strtoul_l_isra_0(_impure_ptr,__nptr,__endptr,__base,puVar2,__endptr,__base);
  return uVar1;
}



int viprintf(char *__format,__gnuc_va_list __arg)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = _impure_ptr;
  if ((_impure_ptr != (undefined *)0x0) && (*(int *)(_impure_ptr + 0x18) == 0)) {
    __sinit(_impure_ptr);
  }
  iVar2 = _vfprintf_r(puVar1,*(undefined4 *)(puVar1 + 8),__format,__arg);
  return iVar2;
}



uint __swbuf_r(int param_1,uint param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  undefined *puVar3;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x18) == 0)) {
    __sinit();
  }
  if (param_3 == &__sf_fake_stdin) {
    param_3 = *(int **)(param_1 + 4);
  }
  else {
    if (param_3 == (int *)&__sf_fake_stdout) {
      param_3 = *(int **)(param_1 + 8);
    }
    else {
      if (param_3 == (int *)&__sf_fake_stderr) {
        param_3 = *(int **)(param_1 + 0xc);
      }
    }
  }
  param_3[2] = param_3[6];
  uVar2 = (uint)*(ushort *)(param_3 + 3);
  iVar1 = uVar2 << 0x1c;
  if (((iVar1 < 0) && (uVar2 = param_3[4], uVar2 != 0)) ||
     (iVar1 = __swsetup_r(param_1,param_3,iVar1,uVar2,param_4), iVar1 == 0)) {
    iVar1 = *param_3 - param_3[4];
    param_2 = param_2 & 0xff;
    if ((iVar1 < param_3[5]) || (iVar1 = _fflush_r(param_1,param_3), iVar1 == 0)) {
      param_3[2] = param_3[2] + -1;
      puVar3 = (undefined *)*param_3;
      *param_3 = (int)(puVar3 + 1);
      *puVar3 = (char)param_2;
      if (param_3[5] != iVar1 + 1) {
        if (-1 < (int)((uint)*(ushort *)(param_3 + 3) << 0x1f)) {
          return param_2;
        }
        if (param_2 != 10) {
          return param_2;
        }
      }
      iVar1 = _fflush_r(param_1,param_3);
      if (iVar1 == 0) {
        return param_2;
      }
    }
  }
  return 0xffffffff;
}



void _write_r(int *param_1,int param_2,char *param_3,int param_4)

{
  int iVar1;
  
  errno = 0;
  iVar1 = _write(param_2,param_3,param_4);
  if ((iVar1 == -1) && (errno != 0)) {
    *param_1 = errno;
  }
  return;
}



undefined4 __swsetup_r(undefined4 *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  uint uVar2;
  ushort uVar3;
  
  puVar1 = _impure_ptr;
  if ((_impure_ptr != (undefined *)0x0) && (*(int *)(_impure_ptr + 0x18) == 0)) {
    __sinit(_impure_ptr);
  }
  if (param_2 == &__sf_fake_stdin) {
    param_2 = *(undefined4 **)(puVar1 + 4);
  }
  else {
    if (param_2 == (undefined4 *)&__sf_fake_stdout) {
      param_2 = *(undefined4 **)(puVar1 + 8);
    }
    else {
      if (param_2 == (undefined4 *)&__sf_fake_stderr) {
        param_2 = *(undefined4 **)(puVar1 + 0xc);
      }
    }
  }
  uVar3 = *(ushort *)(param_2 + 3);
  uVar2 = (uint)uVar3;
  if (-1 < (int)(uVar2 << 0x1c)) {
    if (-1 < (int)(uVar2 << 0x1b)) {
      *param_1 = 9;
      goto LAB_00014f1c;
    }
    if ((int)(uVar2 << 0x1d) < 0) {
      if ((undefined4 *)param_2[0xd] != (undefined4 *)0x0) {
        if ((undefined4 *)param_2[0xd] != param_2 + 0x11) {
          _free_r(param_1);
        }
        param_2[0xd] = 0;
      }
      *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) & 0xffdb;
      param_2[1] = 0;
      *param_2 = param_2[4];
    }
    *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 8;
  }
  if ((param_2[4] == 0) && ((*(ushort *)(param_2 + 3) & 0x280) != 0x200)) {
    __smakebuf_r(param_1,param_2);
  }
  uVar3 = *(ushort *)(param_2 + 3);
  uVar2 = uVar3 & 1;
  if ((uVar3 & 1) == 0) {
    if (-1 < (int)((uint)uVar3 << 0x1e)) {
      uVar2 = param_2[5];
    }
    param_2[2] = uVar2;
  }
  else {
    param_2[2] = 0;
    param_2[6] = -param_2[5];
  }
  if (param_2[4] != 0) {
    return 0;
  }
  uVar3 = *(ushort *)(param_2 + 3);
  if ((uVar3 & 0x80) == 0) {
    return 0;
  }
LAB_00014f1c:
  *(ushort *)(param_2 + 3) = uVar3 | 0x40;
  return 0xffffffff;
}



void _close_r(int *param_1,int param_2)

{
  int iVar1;
  
  errno = 0;
  iVar1 = _close(param_2);
  if ((iVar1 == -1) && (errno != 0)) {
    *param_1 = errno;
  }
  return;
}



uint quorem(int param_1,int param_2)

{
  uint *puVar1;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  uint *puVar11;
  uint uVar12;
  int iVar13;
  uint *puVar14;
  uint *puVar2;
  
  if (*(int *)(param_1 + 0x10) < *(int *)(param_2 + 0x10)) {
    uVar8 = 0;
  }
  else {
    iVar7 = *(int *)(param_2 + 0x10) + -1;
    puVar10 = (uint *)(param_2 + 0x14);
    puVar9 = (uint *)(param_1 + 0x14);
    puVar3 = puVar9 + iVar7;
    puVar11 = puVar10 + iVar7;
    uVar8 = puVar9[iVar7] / (puVar10[iVar7] + 1);
    if (uVar8 != 0) {
      uVar12 = 0;
      iVar13 = 0;
      puVar1 = puVar10;
      puVar14 = puVar9;
      do {
        puVar2 = puVar1 + 1;
        uVar12 = uVar8 * (*puVar1 & 0xffff) + uVar12;
        uVar4 = uVar8 * (*puVar1 >> 0x10) + (uVar12 >> 0x10);
        uVar6 = (iVar13 - (uVar12 & 0xffff)) + (*puVar14 & 0xffff);
        uVar12 = uVar4 >> 0x10;
        iVar5 = ((*puVar14 >> 0x10) - (uVar4 & 0xffff)) + ((int)uVar6 >> 0x10);
        iVar13 = iVar5 >> 0x10;
        *puVar14 = uVar6 & 0xffff | iVar5 * 0x10000;
        puVar1 = puVar2;
        puVar14 = puVar14 + 1;
      } while (puVar2 <= puVar11);
      if (puVar9[iVar7] == 0) {
        while ((puVar3 = puVar3 + -1, puVar9 < puVar3 && (*puVar3 == 0))) {
          iVar7 = iVar7 + -1;
        }
        *(int *)(param_1 + 0x10) = iVar7;
      }
    }
    iVar13 = __mcmp(param_1);
    if (-1 < iVar13) {
      uVar8 = uVar8 + 1;
      iVar13 = 0;
      puVar3 = puVar9;
      do {
        puVar1 = puVar10 + 1;
        uVar12 = (iVar13 - (*puVar10 & 0xffff)) + (*puVar3 & 0xffff);
        iVar5 = ((*puVar3 >> 0x10) - (*puVar10 >> 0x10)) + ((int)uVar12 >> 0x10);
        iVar13 = iVar5 >> 0x10;
        *puVar3 = uVar12 & 0xffff | iVar5 * 0x10000;
        puVar3 = puVar3 + 1;
        puVar10 = puVar1;
      } while (puVar1 <= puVar11);
      puVar10 = puVar9 + iVar7;
      if (puVar9[iVar7] == 0) {
        while ((puVar10 = puVar10 + -1, puVar9 < puVar10 && (*puVar10 == 0))) {
          iVar7 = iVar7 + -1;
        }
        *(int *)(param_1 + 0x10) = iVar7;
      }
    }
  }
  return uVar8;
}



// WARNING: Could not reconcile some variable overlaps

char * _dtoa_r(int param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5,uint param_6,
              int *param_7,undefined4 *param_8,char **param_9)

{
  bool bVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  char *pcVar12;
  char *pcVar13;
  char **ppcVar14;
  char *pcVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  char *pcVar19;
  uint uVar20;
  uint uVar21;
  char cVar22;
  uint uVar23;
  uint uVar24;
  undefined4 uVar25;
  undefined8 uVar26;
  undefined8 uVar27;
  uint local_78;
  uint uStack116;
  char *local_6c;
  char *local_60;
  uint local_5c;
  undefined8 local_58;
  uint local_50;
  uint local_4c;
  undefined4 local_48;
  undefined4 uStack68;
  int local_38;
  int local_34;
  int local_30;
  int local_2c [2];
  
  uVar24 = param_5;
  if (*(int *)(param_1 + 0x24) == 0) {
    puVar3 = (undefined4 *)malloc(0x10);
    *(undefined4 **)(param_1 + 0x24) = puVar3;
    puVar3[1] = 0;
    puVar3[2] = 0;
    *puVar3 = 0;
    puVar3[3] = 0;
  }
  iVar8 = **(int **)(param_1 + 0x24);
  if (iVar8 != 0) {
    uVar11 = (*(int **)(param_1 + 0x24))[1];
    *(uint *)(iVar8 + 4) = uVar11;
    *(int *)(iVar8 + 8) = 1 << (uVar11 & 0xff);
    _Bfree(param_1);
    **(undefined4 **)(param_1 + 0x24) = 0;
  }
  if ((int)param_4 < 0) {
    uStack116 = param_4 & 0x7fffffff;
    *param_8 = 1;
  }
  else {
    *param_8 = 0;
    uStack116 = param_4;
  }
  uVar11 = uStack116;
  if ((~uStack116 & 0x7ff00000) == 0) {
    *param_7 = 9999;
    if ((param_3 == 0) && ((uStack116 & 0xfffff) == 0)) {
      if (param_9 == (char **)0x0) {
        return "Infinity";
      }
      local_6c = "Infinity";
      pcVar13 = "";
    }
    else {
      if (param_9 == (char **)0x0) {
        return "NaN";
      }
      local_6c = "NaN";
      pcVar13 = "";
    }
    *param_9 = pcVar13;
    return local_6c;
  }
  uVar26 = __aeabi_dcmpeq(param_3,uStack116,0,0);
  local_34 = (int)uVar26;
  if (local_34 != 0) {
    *param_7 = 1;
    if (param_9 != (char **)0x0) {
      *param_9 = "";
      return "0";
    }
    return "0";
  }
  uVar4 = __d2b(param_1,(int)((ulonglong)uVar26 >> 0x20),param_3,uStack116,local_2c,&local_30);
  uVar17 = (uStack116 << 1) >> 0x15;
  if (uVar17 == 0) {
    iVar18 = local_30 + local_2c[0];
    iVar8 = iVar18 + 0x432;
    if (iVar8 < 0x21) {
      uVar17 = param_3 << (0x20U - iVar8 & 0xff);
    }
    else {
      uVar17 = uStack116 << (0x40U - iVar8 & 0xff) | param_3 >> (iVar18 + 0x412U & 0xff);
    }
    uVar26 = __floatunsidf(uVar17);
    uVar17 = (uint)uVar26;
    uVar23 = (int)((ulonglong)uVar26 >> 0x20) + 0xfe100000;
    iVar18 = iVar18 + -1;
    local_34 = 1;
  }
  else {
    uVar23 = uStack116 & 0xfffff | 0x3ff00000;
    iVar18 = uVar17 - 0x3ff;
    uVar17 = param_3;
  }
  uVar26 = __subdf3(uVar17,uVar23,0,0x3ff80000);
  uVar26 = __muldf3((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),0x636f4361,0x3fd287a7);
  uVar26 = __aeabi_dadd((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),0x8b60c8b3,0x3fc68a28);
  uVar27 = __aeabi_i2d(iVar18);
  uVar27 = __muldf3((int)uVar27,(int)((ulonglong)uVar27 >> 0x20),0x509f79fb,0x3fd34413);
  uVar26 = __aeabi_dadd((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),(int)uVar27,
                        (int)((ulonglong)uVar27 >> 0x20));
  uVar5 = (undefined4)((ulonglong)uVar26 >> 0x20);
  uVar17 = __aeabi_d2iz();
  iVar8 = __aeabi_dcmplt((int)uVar26,uVar5,0,0);
  if (iVar8 != 0) {
    uVar27 = __aeabi_i2d(uVar17);
    iVar8 = __aeabi_dcmpeq((int)uVar27,(int)((ulonglong)uVar27 >> 0x20),(int)uVar26,uVar5);
    if (iVar8 == 0) {
      uVar17 = uVar17 - 1;
    }
  }
  if (uVar17 < 0x17) {
    local_38 = __aeabi_dcmpgt(*(undefined4 *)(&__mprec_tens + uVar17 * 8),
                              *(undefined4 *)(&DAT_0001ccbc + uVar17 * 8),param_3,uStack116);
    if (local_38 != 0) {
      uVar17 = uVar17 - 1;
      local_38 = 0;
    }
  }
  else {
    local_38 = 1;
  }
  iVar8 = (local_30 - iVar18) + -1;
  if (iVar8 < 0) {
    local_60 = (char *)(1 - (local_30 - iVar18));
    iVar8 = 0;
  }
  else {
    local_60 = (char *)0x0;
  }
  if ((int)uVar17 < 0) {
    local_60 = (char *)((int)local_60 - uVar17);
    local_5c = -uVar17;
    local_4c = 0;
  }
  else {
    iVar8 = iVar8 + uVar17;
    local_5c = 0;
    local_4c = uVar17;
  }
  if (9 < param_5) {
    bVar1 = true;
    param_5 = 0;
switchD_000152dc_caseD_4:
    local_50 = 1;
    param_6 = 0;
    uVar16 = 0x12;
    uVar23 = 0xffffffff;
    uVar24 = 0xffffffff;
    goto LAB_00015350;
  }
  if (5 < (int)param_5) {
    param_5 = param_5 - 4;
  }
  bVar1 = (int)uVar24 < 6;
  switch(param_5) {
  case 2:
    local_50 = 0;
    break;
  case 3:
    local_50 = 0;
    goto LAB_000153c4;
  case 4:
    local_50 = 1;
    break;
  case 5:
    local_50 = 1;
LAB_000153c4:
    uVar24 = param_6 + uVar17;
    uVar23 = uVar24 + 1;
    uVar16 = uVar23;
    if ((int)uVar23 < 1) {
      uVar16 = 1;
    }
    goto LAB_00015350;
  default:
    goto switchD_000152dc_caseD_4;
  }
  uVar16 = param_6;
  uVar23 = param_6;
  uVar24 = param_6;
  if ((int)param_6 < 1) {
    param_6 = 1;
    uVar16 = param_6;
    uVar23 = param_6;
    uVar24 = 1;
  }
LAB_00015350:
  puVar3 = *(undefined4 **)(param_1 + 0x24);
  puVar3[1] = 0;
  for (iVar18 = 4; iVar18 + 0x14U <= uVar16; iVar18 = iVar18 << 1) {
    puVar3[1] = puVar3[1] + 1;
  }
  uVar5 = _Balloc(param_1);
  ppcVar14 = *(char ***)(param_1 + 0x24);
  *puVar3 = uVar5;
  pcVar13 = *ppcVar14;
  uVar21 = uVar23;
  uVar16 = uVar17;
  if ((uVar23 < 0xf) && (bVar1)) {
    local_78 = param_3;
    if ((int)uVar17 < 1) {
      if (uVar17 == 0) {
        iVar18 = 2;
      }
      else {
        puVar3 = &__mprec_bigtens;
        iVar18 = (-uVar17 & 0xf) * 8;
        uVar26 = __muldf3(param_3,uStack116,*(undefined4 *)(&__mprec_tens + iVar18),
                          *(undefined4 *)(&DAT_0001ccbc + iVar18));
        uStack116 = (uint)((ulonglong)uVar26 >> 0x20);
        local_78 = (uint)uVar26;
        iVar6 = (int)-uVar17 >> 4;
        bVar1 = false;
        iVar18 = 2;
        while( true ) {
          if (iVar6 == 0) break;
          if (iVar6 << 0x1f < 0) {
            uVar26 = __muldf3((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),*puVar3,puVar3[1]);
            iVar18 = iVar18 + 1;
            bVar1 = true;
          }
          iVar6 = iVar6 >> 1;
          puVar3 = puVar3 + 2;
        }
        if (bVar1) goto LAB_00015476;
      }
    }
    else {
      local_58 = *(undefined8 *)(&__mprec_tens + (uVar17 & 0xf) * 8);
      uVar20 = (int)uVar17 >> 4;
      if ((int)(uVar20 << 0x1b) < 0) {
        uVar26 = __divdf3(param_3,uStack116,0x7f73bf3c,0x75154fdd);
        uStack116 = (uint)((ulonglong)uVar26 >> 0x20);
        local_78 = (uint)uVar26;
        uVar20 = uVar20 & 0xf;
        iVar18 = 3;
      }
      else {
        iVar18 = 2;
      }
      puVar3 = &__mprec_bigtens;
      while( true ) {
        if (uVar20 == 0) break;
        if ((int)(uVar20 << 0x1f) < 0) {
          local_58 = __muldf3((undefined4)local_58,local_58._4_4_,*puVar3,puVar3[1]);
          iVar18 = iVar18 + 1;
        }
        uVar20 = (int)uVar20 >> 1;
        puVar3 = puVar3 + 2;
      }
      uVar26 = __divdf3(local_78,uStack116,(undefined4)local_58,local_58._4_4_);
LAB_00015476:
      uStack116 = (uint)((ulonglong)uVar26 >> 0x20);
      local_78 = (uint)uVar26;
    }
    uVar26 = CONCAT44(uStack116,local_78);
    if (((local_38 != 0) &&
        (iVar6 = __aeabi_dcmplt(local_78,uStack116,0,0x3ff00000),
        uVar26 = CONCAT44(uStack116,local_78), iVar6 != 0)) &&
       (uVar26 = CONCAT44(uStack116,local_78), uVar23 != 0)) {
      if ((int)uVar24 < 1) goto LAB_0001554e;
      uVar26 = __muldf3(local_78,uStack116,0,0x40240000);
      iVar18 = iVar18 + 1;
      uVar21 = uVar24;
      uVar16 = uVar17 - 1;
    }
    uStack116 = (uint)((ulonglong)uVar26 >> 0x20);
    local_78 = (uint)uVar26;
    uVar27 = __aeabi_i2d(iVar18);
    uVar27 = __muldf3((int)uVar27,(int)((ulonglong)uVar27 >> 0x20),local_78,uStack116);
    uVar27 = __aeabi_dadd((int)uVar27,(int)((ulonglong)uVar27 >> 0x20),0,0x401c0000);
    iVar18 = (int)((ulonglong)uVar27 >> 0x20);
    uVar5 = (undefined4)uVar27;
    iVar6 = iVar18 + -0x3400000;
    if (uVar21 != 0) {
      if (local_50 != 0) {
        uVar27 = __divdf3(0,0x3fe00000,(&DAT_0001ccb0)[uVar21 * 2],(&DAT_0001ccb4)[uVar21 * 2]);
        uVar27 = __subdf3((int)uVar27,(int)((ulonglong)uVar27 >> 0x20),uVar5,iVar6);
        pcVar15 = pcVar13;
        while( true ) {
          uStack68 = (undefined4)((ulonglong)uVar27 >> 0x20);
          local_48 = (undefined4)uVar27;
          uStack116 = (uint)((ulonglong)uVar26 >> 0x20);
          local_78 = (uint)uVar26;
          cVar22 = __aeabi_d2iz(local_78,uStack116);
          uVar26 = __aeabi_i2d();
          uVar26 = __subdf3(local_78,uStack116,(int)uVar26,(int)((ulonglong)uVar26 >> 0x20));
          uVar25 = (undefined4)((ulonglong)uVar26 >> 0x20);
          uVar5 = (undefined4)uVar26;
          pcVar19 = pcVar15 + 1;
          *pcVar15 = cVar22 + '0';
          iVar18 = __aeabi_dcmplt(uVar5,uVar25,local_48,uStack68);
          if (iVar18 != 0) break;
          uVar26 = __subdf3(0,0x3ff00000,uVar5,uVar25);
          iVar18 = __aeabi_dcmplt((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),local_48,uStack68);
          pcVar15 = pcVar19;
          if (iVar18 != 0) goto LAB_000157b2;
          if ((int)uVar21 <= (int)pcVar19 - (int)pcVar13) goto LAB_0001554e;
          uVar27 = __muldf3(local_48,uStack68,0,0x40240000);
          uVar26 = __muldf3(uVar5,uVar25,0,0x40240000);
        }
        goto LAB_0001578e;
      }
      uVar27 = __muldf3((&DAT_0001ccb0)[uVar21 * 2],(&DAT_0001ccb4)[uVar21 * 2],uVar5,iVar6);
      uVar5 = (undefined4)((ulonglong)uVar27 >> 0x20);
      pcVar15 = pcVar13 + uVar21;
      pcVar19 = pcVar13;
      while( true ) {
        uStack116 = (uint)((ulonglong)uVar26 >> 0x20);
        local_78 = (uint)uVar26;
        cVar22 = __aeabi_d2iz(local_78,uStack116);
        uVar26 = __aeabi_i2d();
        uVar26 = __subdf3(local_78,uStack116,(int)uVar26,(int)((ulonglong)uVar26 >> 0x20));
        uVar9 = (undefined4)((ulonglong)uVar26 >> 0x20);
        uVar25 = (undefined4)uVar26;
        *pcVar19 = cVar22 + '0';
        if (pcVar19 + 1 == pcVar15) break;
        uVar26 = __muldf3(uVar25,uVar9,0,0x40240000);
        pcVar19 = pcVar19 + 1;
      }
      uVar26 = __aeabi_dadd((int)uVar27,uVar5,0,0x3fe00000);
      iVar18 = __aeabi_dcmpgt(uVar25,uVar9,(int)uVar26,(int)((ulonglong)uVar26 >> 0x20));
      if (iVar18 != 0) {
LAB_000157b2:
        do {
          pcVar19 = pcVar15;
          pcVar15 = pcVar19 + -1;
          if (pcVar19[-1] != '9') goto LAB_000157d0;
        } while (pcVar13 != pcVar15);
        uVar16 = uVar16 + 1;
        *pcVar13 = '0';
        pcVar15 = pcVar13;
LAB_000157d0:
        *pcVar15 = *pcVar15 + '\x01';
        goto LAB_0001578e;
      }
      uVar26 = __subdf3(0,0x3fe00000,(int)uVar27,uVar5);
      iVar18 = __aeabi_dcmplt(uVar25,uVar9,(int)uVar26,(int)((ulonglong)uVar26 >> 0x20));
      if (iVar18 != 0) {
        do {
          pcVar19 = pcVar15;
          pcVar15 = pcVar19 + -1;
        } while (pcVar19[-1] == '0');
        goto LAB_0001578e;
      }
      goto LAB_0001554e;
    }
    uVar26 = __subdf3(local_78,uStack116,0,0x40140000);
    uVar25 = (undefined4)((ulonglong)uVar26 >> 0x20);
    iVar6 = __aeabi_dcmpgt((int)uVar26,uVar25,uVar5,iVar6);
    uVar20 = uVar21;
    if (iVar6 == 0) {
      iVar18 = __aeabi_dcmplt((int)uVar26,uVar25,uVar5,iVar18 + 0x7cc00000);
      if (iVar18 == 0) goto LAB_0001554e;
      goto LAB_00015a06;
    }
LAB_0001559e:
    *pcVar13 = '1';
    uVar17 = uVar16 + 1;
    pcVar19 = pcVar13 + 1;
LAB_00015a0e:
    uVar24 = 0;
  }
  else {
LAB_0001554e:
    if ((-1 < local_2c[0]) && ((int)uVar17 < 0xf)) {
      uVar25 = (undefined4)*(undefined8 *)(&__mprec_tens + uVar17 * 8);
      uVar5 = (undefined4)((ulonglong)*(undefined8 *)(&__mprec_tens + uVar17 * 8) >> 0x20);
      pcVar15 = pcVar13;
      if ((-1 < (int)param_6) || (0 < (int)uVar23)) {
        do {
          __divdf3(param_3,uVar11,uVar25,uVar5);
          bVar2 = __aeabi_d2iz();
          uVar26 = __aeabi_i2d();
          uVar26 = __muldf3((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),uVar25,uVar5);
          uVar26 = __subdf3(param_3,uVar11,(int)uVar26,(int)((ulonglong)uVar26 >> 0x20));
          uVar10 = (undefined4)((ulonglong)uVar26 >> 0x20);
          uVar9 = (undefined4)uVar26;
          pcVar19 = pcVar15 + 1;
          *pcVar15 = bVar2 + 0x30;
          if (uVar23 == (int)pcVar19 - (int)pcVar13) {
            uVar26 = __aeabi_dadd(uVar9,uVar10,uVar9,uVar10);
            uVar9 = (undefined4)((ulonglong)uVar26 >> 0x20);
            iVar8 = __aeabi_dcmpgt((int)uVar26,uVar9,uVar25,uVar5);
            pcVar15 = pcVar19;
            uVar16 = uVar17;
            if ((iVar8 != 0) ||
               ((iVar8 = __aeabi_dcmpeq((int)uVar26,uVar9,uVar25,uVar5), iVar8 != 0 &&
                ((bVar2 & 1) != 0)))) goto LAB_000157b2;
            break;
          }
          uVar26 = __muldf3(uVar9,uVar10,0,0x40240000);
          uVar11 = (uint)((ulonglong)uVar26 >> 0x20);
          param_3 = (uint)uVar26;
          iVar8 = __aeabi_dcmpeq(param_3,uVar11,0,0);
          pcVar15 = pcVar19;
          uVar16 = uVar17;
        } while (iVar8 == 0);
        goto LAB_0001578e;
      }
      if (uVar23 == 0) {
        uVar26 = __muldf3(uVar25,uVar5,0,0x40140000);
        iVar8 = __aeabi_dcmpge((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),param_3,uVar11);
        uVar21 = uVar23;
        uVar20 = uVar23;
        uVar16 = uVar17;
        if (iVar8 == 0) goto LAB_0001559e;
      }
      else {
        uVar21 = 0;
        uVar20 = uVar21;
      }
LAB_00015a06:
      uVar17 = ~param_6;
      pcVar19 = pcVar13;
      goto LAB_00015a0e;
    }
    iVar18 = (int)local_60;
    uVar21 = local_50;
    iVar6 = local_5c;
    if (local_50 != 0) {
      if ((int)param_5 < 2) {
        if (local_34 == 0) {
          uVar16 = 0x36 - local_30;
        }
        else {
          uVar16 = local_2c[0] + 0x433;
        }
      }
      else {
        iVar7 = uVar23 - 1;
        if ((int)local_5c < iVar7) {
          local_4c = local_4c + (iVar7 - local_5c);
          iVar6 = 0;
          local_5c = iVar7;
        }
        else {
          iVar6 = local_5c - iVar7;
        }
        uVar16 = uVar23;
        if ((int)uVar23 < 0) {
          uVar16 = 0;
          iVar18 = (int)local_60 - uVar23;
        }
      }
      local_60 = (char *)((int)local_60 + uVar16);
      iVar8 = iVar8 + uVar16;
      uVar21 = __i2b(param_1,1);
    }
    if ((0 < iVar18) && (0 < iVar8)) {
      iVar7 = iVar18;
      if (iVar8 <= iVar18) {
        iVar7 = iVar8;
      }
      local_60 = (char *)((int)local_60 - iVar7);
      iVar18 = iVar18 - iVar7;
      iVar8 = iVar8 - iVar7;
    }
    if (local_5c != 0) {
      if (local_50 != 0) {
        uVar5 = uVar4;
        if (iVar6 != 0) {
          uVar21 = __pow5mult(param_1,uVar21,iVar6);
          uVar5 = __multiply(param_1,uVar21,uVar4);
          _Bfree(param_1,uVar4);
        }
        local_5c = local_5c - iVar6;
        uVar4 = uVar5;
        if (local_5c == 0) goto LAB_00015882;
      }
      uVar4 = __pow5mult(param_1,uVar4,local_5c);
    }
LAB_00015882:
    uVar20 = __i2b(param_1,1);
    if (local_4c == 0) {
      if ((int)param_5 < 2) goto LAB_000158a6;
      local_5c = local_4c;
LAB_000158d6:
      iVar6 = 1;
    }
    else {
      uVar20 = __pow5mult(param_1,uVar20,local_4c);
      if ((int)param_5 < 2) {
LAB_000158a6:
        if (param_3 == 0) {
          local_5c = param_3;
          if (((uVar11 & 0xfffff) == 0) &&
             (local_5c = uVar11 & 0x7ff00000, (uVar11 & 0x7ff00000) != 0)) {
            local_60 = (char *)((int)local_60 + 1);
            iVar8 = iVar8 + 1;
            local_5c = 1;
          }
        }
        else {
          local_5c = 0;
        }
        if (local_4c == 0) goto LAB_000158d6;
      }
      else {
        local_5c = 0;
      }
      iVar6 = __hi0bits(*(undefined4 *)(uVar20 + *(int *)(uVar20 + 0x10) * 4 + 0x10));
      iVar6 = 0x20 - iVar6;
    }
    uVar11 = iVar6 + iVar8 & 0x1f;
    if (uVar11 == 0) {
LAB_000159c6:
      iVar6 = uVar11 + 0x1c;
      local_60 = (char *)((int)local_60 + iVar6);
      iVar18 = iVar18 + iVar6;
      iVar8 = iVar8 + iVar6;
    }
    else {
      uVar16 = 0x20 - uVar11;
      if ((int)uVar16 < 5) {
        uVar11 = uVar16;
        if (uVar16 != 4) goto LAB_000159c6;
      }
      else {
        iVar6 = 0x1c - uVar11;
        local_60 = (char *)((int)local_60 + iVar6);
        iVar18 = iVar18 + iVar6;
        iVar8 = iVar8 + iVar6;
      }
    }
    if (0 < (int)local_60) {
      uVar4 = __lshift(param_1,uVar4,local_60);
    }
    if (0 < iVar8) {
      uVar20 = __lshift(param_1,uVar20,iVar8);
    }
    pcVar15 = pcVar13;
    if ((local_38 != 0) && (iVar8 = __mcmp(uVar4,uVar20), iVar8 < 0)) {
      uVar4 = __multadd(param_1,uVar4,10,0);
      uVar17 = uVar17 - 1;
      uVar23 = uVar24;
      if (local_50 == 0) {
        if ((0 < (int)uVar24) || ((int)param_5 < 3)) goto LAB_00015c48;
      }
      else {
        uVar21 = __multadd(param_1,uVar21,10,0);
        if ((0 < (int)uVar24) || ((int)param_5 < 3)) goto LAB_00015a5c;
      }
LAB_000159e8:
      if (uVar23 == 0) {
        uVar20 = __multadd(param_1,uVar20,5);
        iVar8 = __mcmp(uVar4,uVar20);
        uVar16 = uVar17;
        if (0 < iVar8) goto LAB_0001559e;
      }
      goto LAB_00015a06;
    }
    if (((int)uVar23 < 1) && (2 < (int)param_5)) goto LAB_000159e8;
    if (local_50 == 0) {
LAB_00015c48:
      while( true ) {
        iVar8 = quorem(uVar4,uVar20);
        uVar11 = iVar8 + 0x30;
        pcVar12 = pcVar15 + 1;
        *pcVar15 = (char)uVar11;
        if ((int)uVar23 <= (int)pcVar12 - (int)pcVar13) break;
        uVar4 = __multadd(param_1,uVar4,10,0);
        pcVar15 = pcVar12;
      }
      uVar24 = 0;
    }
    else {
LAB_00015a5c:
      uVar24 = uVar21;
      if (0 < iVar18) {
        uVar24 = __lshift(param_1,uVar21,iVar18);
      }
      uVar21 = uVar24;
      if (local_5c != 0) {
        iVar8 = _Balloc(param_1,*(undefined4 *)(uVar24 + 4));
        memcpy((void *)(iVar8 + 0xc),(void *)(uVar24 + 0xc),(*(int *)(uVar24 + 0x10) + 2) * 4);
        uVar21 = __lshift(param_1,iVar8,1);
      }
      local_60 = pcVar13;
LAB_00015aa6:
      iVar8 = quorem(uVar4,uVar20);
      uVar11 = iVar8 + 0x30;
      iVar18 = __mcmp(uVar4,uVar24);
      iVar6 = __mdiff(param_1,uVar20,uVar21);
      if (*(int *)(iVar6 + 0xc) == 0) {
        iVar7 = __mcmp(uVar4,iVar6);
      }
      else {
        iVar7 = 1;
      }
      _Bfree(param_1,iVar6);
      if (((iVar7 == 0) && (param_5 == 0)) && ((param_3 & 1) == 0)) {
        if (uVar11 == 0x39) {
LAB_00015b4c:
          *local_60 = '9';
          pcVar12 = local_60 + 1;
          goto LAB_00015b56;
        }
        if (0 < iVar18) {
LAB_00015afe:
          uVar11 = iVar8 + 0x31;
        }
LAB_00015b02:
        cVar22 = (char)uVar11;
LAB_00015b06:
        pcVar19 = local_60 + 1;
        *local_60 = cVar22;
        goto LAB_00015a12;
      }
      if ((iVar18 < 0) || (((iVar18 == 0 && (param_5 == 0)) && ((param_3 & 1) == 0)))) {
        if (0 < iVar7) {
          uVar4 = __lshift(param_1,uVar4,1);
          iVar18 = __mcmp(uVar4,uVar20);
          if ((0 < iVar18) || ((iVar18 == 0 && ((uVar11 & 1) != 0)))) {
            if (uVar11 != 0x39) goto LAB_00015afe;
            goto LAB_00015b4c;
          }
        }
        goto LAB_00015b02;
      }
      pcVar12 = local_60 + 1;
      if (0 < iVar7) {
        if (uVar11 == 0x39) goto LAB_00015b4c;
        cVar22 = (char)uVar11 + '\x01';
        goto LAB_00015b06;
      }
      *local_60 = (char)uVar11;
      if ((int)pcVar12 - (int)pcVar13 != uVar23) {
        uVar4 = __multadd(param_1,uVar4,10,0);
        local_60 = pcVar12;
        if (uVar24 == uVar21) {
          uVar21 = __multadd(param_1,uVar24,10,0);
          uVar24 = uVar21;
        }
        else {
          uVar24 = __multadd(param_1,uVar24,10,0);
          uVar21 = __multadd(param_1,uVar21,10,0);
        }
        goto LAB_00015aa6;
      }
    }
    uVar4 = __lshift(param_1,uVar4,1);
    iVar8 = __mcmp(uVar4,uVar20);
    if ((iVar8 < 1) && ((iVar8 != 0 || ((uVar11 & 1) == 0)))) {
      do {
        pcVar19 = pcVar12;
        pcVar12 = pcVar19 + -1;
      } while (pcVar19[-1] == '0');
    }
    else {
LAB_00015b56:
      do {
        pcVar19 = pcVar12;
        pcVar12 = pcVar19 + -1;
        if (pcVar19[-1] != '9') {
          cVar22 = pcVar19[-1] + '\x01';
          goto LAB_00015c0e;
        }
      } while (pcVar13 != pcVar12);
      uVar17 = uVar17 + 1;
      cVar22 = '1';
      pcVar12 = pcVar13;
LAB_00015c0e:
      *pcVar12 = cVar22;
    }
  }
LAB_00015a12:
  _Bfree(param_1,uVar20);
  uVar16 = uVar17;
  if (uVar21 != 0) {
    if ((uVar24 != 0) && (uVar24 != uVar21)) {
      _Bfree(param_1,uVar24);
    }
    _Bfree(param_1,uVar21);
  }
LAB_0001578e:
  _Bfree(param_1,uVar4);
  *pcVar19 = '\0';
  *param_7 = uVar16 + 1;
  if (param_9 != (char **)0x0) {
    *param_9 = pcVar19;
  }
  return pcVar13;
}



undefined4 __sflush_r(uint *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  ushort uVar4;
  int iVar5;
  code *pcVar6;
  int iVar7;
  uint uVar8;
  bool bVar9;
  
  uVar4 = *(ushort *)(param_2 + 3);
  uVar3 = (uint)uVar4;
  if ((int)(uVar3 << 0x1c) < 0) {
    iVar1 = param_2[4];
    if (iVar1 != 0) {
      iVar5 = uVar3 << 0x1e;
      bVar9 = iVar5 == 0;
      iVar7 = *param_2;
      if (bVar9) {
        iVar5 = param_2[5];
      }
      *param_2 = iVar1;
      if (!bVar9) {
        iVar5 = 0;
      }
      param_2[2] = iVar5;
      for (iVar7 = iVar7 - iVar1; 0 < iVar7; iVar7 = iVar7 - iVar5) {
        iVar5 = (*(code *)param_2[10])(param_1,param_2[8],iVar1,iVar7);
        if (iVar5 < 1) {
          uVar4 = *(ushort *)(param_2 + 3);
          goto LAB_00015d6e;
        }
        iVar1 = iVar1 + iVar5;
      }
    }
  }
  else {
    if (((0 < param_2[1]) || (0 < param_2[0x10])) &&
       (pcVar6 = (code *)param_2[0xb], pcVar6 != FUN_00000000)) {
      uVar8 = *param_1;
      iVar1 = param_2[8];
      *param_1 = 0;
      if ((uVar4 & 0x1000) == 0) {
        iVar1 = (*pcVar6)(param_1,iVar1,uVar3 & 0x1000,1);
        if ((iVar1 == -1) && (uVar3 = *param_1, uVar3 != 0)) {
          if ((uVar3 != 0x1d) && (uVar3 != 0x16)) {
            *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 0x40;
            return 0xffffffff;
          }
          *param_1 = uVar8;
          return 0;
        }
      }
      else {
        iVar1 = param_2[0x15];
      }
      if (((int)((uint)*(ushort *)(param_2 + 3) << 0x1d) < 0) &&
         (iVar1 = iVar1 - param_2[1], param_2[0xd] != 0)) {
        iVar1 = iVar1 - param_2[0x10];
      }
      iVar1 = (*(code *)param_2[0xb])(param_1,param_2[8],iVar1,0);
      uVar4 = *(ushort *)(param_2 + 3);
      if ((iVar1 == -1) &&
         ((0x1d < *param_1 || (-1 < (int)((0x20400001U >> (*param_1 & 0xff)) << 0x1f))))) {
LAB_00015d6e:
        *(ushort *)(param_2 + 3) = uVar4 | 0x40;
        return 0xffffffff;
      }
      param_2[1] = 0;
      *param_2 = param_2[4];
      if (((int)((uint)uVar4 << 0x13) < 0) && ((iVar1 != -1 || (*param_1 == 0)))) {
        param_2[0x15] = iVar1;
      }
      piVar2 = (int *)param_2[0xd];
      *param_1 = uVar8;
      if (piVar2 != (int *)0x0) {
        if (piVar2 != param_2 + 0x11) {
          _free_r(param_1);
        }
        param_2[0xd] = 0;
        return 0;
      }
    }
  }
  return 0;
}



undefined4 _fflush_r(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_2[4] != 0) {
    if ((param_1 != 0) && (*(int *)(param_1 + 0x18) == 0)) {
      __sinit();
    }
    if (param_2 == &__sf_fake_stdin) {
      param_2 = *(undefined4 **)(param_1 + 4);
    }
    else {
      if (param_2 == (undefined4 *)&__sf_fake_stdout) {
        param_2 = *(undefined4 **)(param_1 + 8);
      }
      else {
        if (param_2 == (undefined4 *)&__sf_fake_stderr) {
          param_2 = *(undefined4 **)(param_1 + 0xc);
        }
      }
    }
    if (*(short *)(param_2 + 3) != 0) {
      uVar1 = __sflush_r(param_1,param_2,param_3,param_4);
      return uVar1;
    }
  }
  return 0;
}



int fflush(FILE *__stream)

{
  int iVar1;
  
  if (__stream == (FILE *)0x0) {
    iVar1 = _fwalk_reent(&impure_data,0x15d89);
    return iVar1;
  }
  iVar1 = _fflush_r(_impure_ptr,__stream);
  return iVar1;
}



uint _getc_r(int param_1,byte **param_2)

{
  uint uVar1;
  byte *pbVar2;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x18) == 0)) {
    __sinit();
  }
  if (param_2 == (byte **)&__sf_fake_stdin) {
    param_2 = *(byte ***)(param_1 + 4);
  }
  else {
    if (param_2 == (byte **)&__sf_fake_stdout) {
      param_2 = *(byte ***)(param_1 + 8);
    }
    else {
      if (param_2 == (byte **)&__sf_fake_stderr) {
        param_2 = *(byte ***)(param_1 + 0xc);
      }
    }
  }
  pbVar2 = param_2[1];
  param_2[1] = pbVar2 + -1;
  if (-1 < (int)(pbVar2 + -1)) {
    pbVar2 = *param_2;
    *param_2 = pbVar2 + 1;
    return (uint)*pbVar2;
  }
  uVar1 = __srget_r(param_1,param_2);
  return uVar1;
}



undefined4 __locale_ctype_ptr_l(int param_1)

{
  return *(undefined4 *)(param_1 + 0xec);
}



undefined4 __locale_ctype_ptr(void)

{
  undefined1 *puVar1;
  
  puVar1 = *(undefined1 **)(_impure_ptr + 0x20);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &__global_locale;
  }
  return *(undefined4 *)(puVar1 + 0xec);
}



undefined1 * _localeconv_r(void)

{
  undefined1 *puVar1;
  
  puVar1 = *(undefined1 **)(_impure_ptr + 0x20);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &__global_locale;
  }
  return puVar1 + 0xf0;
}



void _lseek_r(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  errno = 0;
  iVar1 = _lseek(param_2,param_3,param_4);
  if ((iVar1 == -1) && (errno != 0)) {
    *param_1 = errno;
  }
  return;
}



undefined4 __swhatbuf_r(undefined4 param_1,int param_2,undefined4 *param_3,uint *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined auStack104 [4];
  uint local_64;
  
  if ((*(short *)(param_2 + 0xe) < 0) ||
     (iVar1 = _fstat_r(param_1,(int)*(short *)(param_2 + 0xe),auStack104), iVar1 < 0)) {
    *param_4 = 0;
    if ((int)((uint)*(ushort *)(param_2 + 0xc) << 0x18) < 0) {
      uVar2 = 0x40;
      goto LAB_00015efc;
    }
  }
  else {
    *param_4 = (uint)((local_64 & 0xf000) == 0x2000);
  }
  uVar2 = 0x400;
LAB_00015efc:
  *param_3 = uVar2;
  return 0;
}



void __smakebuf_r(int param_1,int *param_2)

{
  ushort uVar1;
  int iVar2;
  int local_18;
  int *local_14;
  
  if (-1 < (int)((uint)*(ushort *)(param_2 + 3) << 0x1e)) {
    local_18 = param_1;
    local_14 = param_2;
    uVar1 = __swhatbuf_r(param_1,param_2,&local_18,&local_14);
    iVar2 = _malloc_r(param_1,local_18);
    if (iVar2 != 0) {
      *(undefined4 *)(param_1 + 0x28) = 0x13b3d;
      *param_2 = iVar2;
      *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 0x80;
      param_2[5] = local_18;
      param_2[4] = iVar2;
      if ((local_14 != (int *)0x0) &&
         (iVar2 = _isatty_r(param_1,(int)*(short *)((int)param_2 + 0xe)), iVar2 != 0)) {
        *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) & 0xfffc | 1;
      }
      *(ushort *)(param_2 + 3) = uVar1 | *(ushort *)(param_2 + 3);
      return;
    }
    if ((int)(short)*(ushort *)(param_2 + 3) << 0x16 < 0) {
      return;
    }
    *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) & 0xfffc | 2;
  }
  *param_2 = (int)param_2 + 0x47;
  param_2[4] = (int)param_2 + 0x47;
  param_2[5] = 1;
  return;
}



void * malloc(size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)_malloc_r(_impure_ptr,__size);
  return pvVar1;
}



code * __ascii_mbtowc(undefined4 param_1,uint *param_2,code *param_3,int param_4)

{
  uint local_4;
  
  if (param_2 == (uint *)0x0) {
    param_2 = &local_4;
  }
  if (param_3 != FUN_00000000) {
    if (param_4 == 0) {
      param_3 = (code *)0xfffffffe;
    }
    else {
      *param_2 = (uint)(byte)*param_3;
      param_3 = (code *)(uint)(byte)*param_3;
      if (param_3 != FUN_00000000) {
        param_3 = FUN_00000000 + 1;
      }
    }
  }
  return param_3;
}



void * memchr(void *__s,int __c,size_t __n)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte *pbVar6;
  uint *puVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  bool bVar15;
  bool bVar16;
  bool bVar17;
  
  uVar9 = __c & 0xff;
  if ((int)__n < 0x10) {
joined_r0x00016020:
    do {
      if (__n == 0) {
        return (byte *)0x0;
      }
                    // WARNING: Load size is inaccurate
      puVar7 = (uint *)((int)__s + 1);
      bVar1 = *__s;
      __n = __n - 1;
      __s = puVar7;
    } while (bVar1 != uVar9);
  }
  else {
    uVar10 = (uint)__s & 7;
    while( true ) {
      if (uVar10 == 0) {
        uVar10 = uVar9 | uVar9 << 8;
        uVar10 = uVar10 | uVar10 << 0x10;
        uVar11 = __n & 0xfffffff8;
        do {
          puVar7 = (uint *)((int)__s + 8);
                    // WARNING: Load size is inaccurate
          uVar11 = uVar11 - 8;
          uVar12 = *__s ^ uVar10;
          uVar13 = *(uint *)((int)__s + 4) ^ uVar10;
          cVar2 = -((char)uVar12 == '\0');
          cVar3 = -((char)(uVar12 >> 8) == '\0');
          cVar4 = -((char)(uVar12 >> 0x10) == '\0');
          cVar5 = -((char)(uVar12 >> 0x18) == '\0');
          uVar12 = CONCAT13(cVar5,CONCAT12(cVar4,CONCAT11(cVar3,cVar2)));
          bVar14 = (char)uVar13 != '\0';
          bVar15 = (char)(uVar13 >> 8) != '\0';
          bVar16 = (char)(uVar13 >> 0x10) != '\0';
          bVar17 = (char)(uVar13 >> 0x18) != '\0';
          uVar13 = CONCAT13(bVar17 * cVar5 - !bVar17,
                            CONCAT12(bVar16 * cVar4 - !bVar16,
                                     CONCAT11(bVar15 * cVar3 - !bVar15,bVar14 * cVar2 - !bVar14)));
          if (uVar13 != 0) {
            if (uVar12 == 0) {
              pbVar8 = (byte *)((int)__s + 5);
              uVar12 = uVar13;
            }
            else {
              pbVar8 = (byte *)((int)__s + 1);
            }
            if ((uVar12 & 1) == 0) {
              bVar14 = (uVar12 & 0x100) == 0;
              pbVar6 = pbVar8 + 1;
              if (bVar14) {
                bVar14 = (uVar12 & 0x18000) == 0;
                pbVar6 = pbVar8 + 2;
              }
              pbVar8 = pbVar6;
              if (bVar14) {
                pbVar8 = pbVar8 + 1;
              }
            }
            return pbVar8 + -1;
          }
          __s = puVar7;
        } while (uVar11 != 0);
        __n = __n & 7;
        goto joined_r0x00016020;
      }
                    // WARNING: Load size is inaccurate
      puVar7 = (uint *)((int)__s + 1);
      __n = __n - 1;
      if (*__s == uVar9) break;
      uVar10 = (uint)puVar7 & 7;
      __s = puVar7;
      if (__n == 0) {
        return (byte *)0x0;
      }
    }
  }
  return (byte *)((int)puVar7 + -1);
}



void __malloc_lock(void)

{
  return;
}



void __malloc_unlock(void)

{
  return;
}



undefined4 * _Balloc(int param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    puVar1 = (undefined4 *)malloc(0x10);
    *(undefined4 **)(param_1 + 0x24) = puVar1;
    puVar1[1] = 0;
    puVar1[2] = 0;
    *puVar1 = 0;
    puVar1[3] = 0;
  }
  iVar4 = *(int *)(param_1 + 0x24);
  if (*(int *)(iVar4 + 0xc) == 0) {
    uVar2 = _calloc_r(param_1,4,0x21);
    iVar3 = *(int *)(param_1 + 0x24);
    *(undefined4 *)(iVar4 + 0xc) = uVar2;
    if (*(int *)(iVar3 + 0xc) != 0) goto LAB_00016084;
LAB_000160ba:
    puVar1 = (undefined4 *)0x0;
  }
  else {
LAB_00016084:
    iVar4 = *(int *)(*(int *)(param_1 + 0x24) + 0xc);
    puVar1 = *(undefined4 **)(iVar4 + param_2 * 4);
    if (puVar1 == (undefined4 *)0x0) {
      iVar4 = 1 << (param_2 & 0xff);
      puVar1 = (undefined4 *)_calloc_r(param_1,1,(iVar4 + 5) * 4);
      if (puVar1 == (undefined4 *)0x0) goto LAB_000160ba;
      puVar1[1] = param_2;
      puVar1[2] = iVar4;
    }
    else {
      *(undefined4 *)(iVar4 + param_2 * 4) = *puVar1;
    }
    puVar1[3] = 0;
    puVar1[4] = 0;
  }
  return puVar1;
}



void _Bfree(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    puVar1 = (undefined4 *)malloc(0x10);
    *(undefined4 **)(param_1 + 0x24) = puVar1;
    puVar1[1] = 0;
    puVar1[2] = 0;
    *puVar1 = 0;
    puVar1[3] = 0;
  }
  if (param_2 != (undefined4 *)0x0) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0xc);
    *param_2 = *(undefined4 *)(iVar2 + param_2[1] * 4);
    *(undefined4 **)(iVar2 + param_2[1] * 4) = param_2;
  }
  return;
}



int __multadd(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  
  iVar4 = *(int *)(param_2 + 0x10);
  iVar3 = 0;
  puVar5 = (uint *)(param_2 + 0x14);
  do {
    uVar2 = param_3 * (*puVar5 & 0xffff) + param_4;
    uVar1 = param_3 * (*puVar5 >> 0x10) + (uVar2 >> 0x10);
    iVar3 = iVar3 + 1;
    param_4 = uVar1 >> 0x10;
    *puVar5 = (uVar2 & 0xffff) + uVar1 * 0x10000;
    puVar5 = puVar5 + 1;
  } while (iVar3 < iVar4);
  iVar3 = param_2;
  if (param_4 != 0) {
    if (*(int *)(param_2 + 8) <= iVar4) {
      iVar3 = _Balloc(param_1,*(int *)(param_2 + 4) + 1);
      memcpy((void *)(iVar3 + 0xc),(void *)(param_2 + 0xc),(*(int *)(param_2 + 0x10) + 2) * 4);
      _Bfree(param_1,param_2);
    }
    *(uint *)(iVar3 + iVar4 * 4 + 0x14) = param_4;
    *(int *)(iVar3 + 0x10) = iVar4 + 1;
  }
  return iVar3;
}



int __hi0bits(uint param_1)

{
  int iVar1;
  
  if ((param_1 & 0xffff0000) == 0) {
    param_1 = param_1 << 0x10;
    iVar1 = 0x10;
  }
  else {
    iVar1 = 0;
  }
  if ((param_1 & 0xff000000) == 0) {
    param_1 = param_1 << 8;
    iVar1 = iVar1 + 8;
  }
  if ((param_1 & 0xf0000000) == 0) {
    param_1 = param_1 << 4;
    iVar1 = iVar1 + 4;
  }
  if ((param_1 & 0xc0000000) == 0) {
    param_1 = param_1 << 2;
    iVar1 = iVar1 + 2;
  }
  if (-1 < (int)param_1) {
    if ((int)(param_1 << 1) < 0) {
      return iVar1 + 1;
    }
    iVar1 = 0x20;
  }
  return iVar1;
}



uint __lo0bits(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  uVar1 = uVar2 & 7;
  if (uVar1 == 0) {
    if ((uVar2 & 0xffff) == 0) {
      uVar2 = uVar2 >> 0x10;
      uVar1 = 0x10;
    }
    if ((uVar2 & 0xff) == 0) {
      uVar2 = uVar2 >> 8;
      uVar1 = uVar1 + 8;
    }
    if ((uVar2 & 0xf) == 0) {
      uVar2 = uVar2 >> 4;
      uVar1 = uVar1 + 4;
    }
    if ((uVar2 & 3) == 0) {
      uVar2 = uVar2 >> 2;
      uVar1 = uVar1 + 2;
    }
    if (-1 < (int)(uVar2 << 0x1f)) {
      uVar2 = uVar2 >> 1;
      if (uVar2 == 0) {
        return 0x20;
      }
      uVar1 = uVar1 + 1;
    }
    *param_1 = uVar2;
    return uVar1;
  }
  if (-1 < (int)(uVar2 << 0x1f)) {
    if ((int)(uVar2 << 0x1e) < 0) {
      uVar1 = 1;
      *param_1 = uVar2 >> 1;
    }
    else {
      *param_1 = uVar2 >> 2;
      uVar1 = 2;
    }
    return uVar1;
  }
  return 0;
}



void __i2b(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _Balloc(param_1,1);
  *(undefined4 *)(iVar1 + 0x14) = param_2;
  *(undefined4 *)(iVar1 + 0x10) = 1;
  return;
}



void __multiply(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint *puVar14;
  uint *puVar16;
  uint *puVar17;
  uint uVar18;
  uint *puVar19;
  uint *puVar15;
  
  iVar7 = param_3;
  iVar1 = param_2;
  if (*(int *)(param_2 + 0x10) < *(int *)(param_3 + 0x10)) {
    iVar7 = param_2;
    iVar1 = param_3;
  }
  iVar11 = *(int *)(iVar1 + 0x10);
  iVar13 = *(int *)(iVar7 + 0x10);
  iVar2 = *(int *)(iVar1 + 4);
  iVar10 = iVar11 + iVar13;
  if (*(int *)(iVar1 + 8) < iVar10) {
    iVar2 = iVar2 + 1;
  }
  iVar2 = _Balloc(param_1,iVar2,*(int *)(param_2 + 0x10),*(int *)(iVar1 + 8),param_1,param_2,param_3
                 );
  puVar9 = (uint *)(iVar2 + 0x14);
  puVar19 = puVar9 + iVar10;
  for (puVar3 = puVar9; puVar3 < puVar19; puVar3 = puVar3 + 1) {
    *puVar3 = 0;
  }
  puVar4 = (ushort *)(iVar7 + 0x14);
  puVar3 = (uint *)(iVar1 + 0x14);
  puVar5 = puVar4 + iVar13 * 2;
  while (puVar4 < puVar5) {
    uVar18 = (uint)*puVar4;
    if (uVar18 != 0) {
      uVar12 = 0;
      puVar14 = puVar3;
      puVar16 = puVar9;
      do {
        puVar17 = puVar16;
        puVar15 = puVar14 + 1;
        uVar6 = uVar18 * (*puVar14 & 0xffff) + (*puVar17 & 0xffff) + uVar12;
        uVar8 = uVar18 * (*puVar14 >> 0x10) + (*puVar17 >> 0x10) + (uVar6 >> 0x10);
        uVar12 = uVar8 >> 0x10;
        *puVar17 = uVar6 & 0xffff | uVar8 * 0x10000;
        puVar14 = puVar15;
        puVar16 = puVar17 + 1;
      } while (puVar15 < puVar3 + iVar11);
      puVar17[1] = uVar12;
    }
    uVar18 = (uint)puVar4[1];
    puVar4 = puVar4 + 2;
    if (uVar18 != 0) {
      uVar12 = *puVar9;
      uVar6 = 0;
      puVar14 = puVar9;
      puVar16 = puVar3;
      do {
        puVar15 = puVar14;
        uVar6 = uVar18 * *(ushort *)puVar16 + (uint)*(ushort *)((int)puVar15 + 2) + uVar6;
        *puVar15 = uVar12 & 0xffff | uVar6 * 0x10000;
        puVar17 = puVar16 + 1;
        uVar12 = uVar18 * (*puVar16 >> 0x10) + (uint)*(ushort *)(puVar15 + 1) + (uVar6 >> 0x10);
        uVar6 = uVar12 >> 0x10;
        puVar14 = puVar15 + 1;
        puVar16 = puVar17;
      } while (puVar17 < puVar3 + iVar11);
      puVar15[1] = uVar12;
    }
    puVar9 = puVar9 + 1;
  }
  while ((0 < iVar10 && (puVar19 = puVar19 + -1, *puVar19 == 0))) {
    iVar10 = iVar10 + -1;
  }
  *(int *)(iVar2 + 0x10) = iVar10;
  return;
}



undefined4 __pow5mult(int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  if ((param_3 & 3) != 0) {
    param_2 = __multadd(param_1,param_2,*(undefined4 *)(&p05_7359 + ((param_3 & 3) - 1) * 4),0,
                        param_4);
  }
  iVar3 = (int)param_3 >> 2;
  if (iVar3 != 0) {
    if (*(int *)(param_1 + 0x24) == 0) {
      puVar1 = (undefined4 *)malloc(0x10);
      *(undefined4 **)(param_1 + 0x24) = puVar1;
      puVar1[1] = 0;
      puVar1[2] = 0;
      *puVar1 = 0;
      puVar1[3] = 0;
    }
    iVar5 = *(int *)(param_1 + 0x24);
    puVar1 = *(undefined4 **)(iVar5 + 8);
    uVar4 = param_2;
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)__i2b(param_1,0x271);
      *(undefined4 **)(iVar5 + 8) = puVar1;
      *puVar1 = 0;
    }
    while( true ) {
      puVar2 = puVar1;
      param_2 = uVar4;
      if (iVar3 << 0x1f < 0) {
        param_2 = __multiply(param_1,uVar4,puVar2);
        _Bfree(param_1,uVar4);
      }
      iVar3 = iVar3 >> 1;
      if (iVar3 == 0) break;
      puVar1 = (undefined4 *)*puVar2;
      uVar4 = param_2;
      if ((undefined4 *)*puVar2 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)__multiply(param_1,puVar2,puVar2);
        *puVar2 = puVar1;
        *puVar1 = 0;
      }
    }
  }
  return param_2;
}



int __lshift(undefined4 param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  int iVar10;
  int iVar11;
  uint *puVar9;
  
  uVar1 = (int)param_3 >> 5;
  iVar2 = *(int *)(param_2 + 4);
  iVar11 = uVar1 + *(int *)(param_2 + 0x10);
  iVar10 = iVar11 + 1;
  for (iVar5 = *(int *)(param_2 + 8); iVar5 < iVar10; iVar5 = iVar5 << 1) {
    iVar2 = iVar2 + 1;
  }
  iVar2 = _Balloc(param_1,iVar2);
  for (iVar5 = 0; iVar5 < (int)uVar1; iVar5 = iVar5 + 1) {
    *(undefined4 *)(iVar2 + 0x14 + iVar5 * 4) = 0;
  }
  iVar5 = *(int *)(param_2 + 0x10);
  puVar6 = (uint *)(param_2 + 0x14);
  uVar4 = param_3 & 0x1f;
  puVar3 = (uint *)(iVar2 + 0x14 + (uVar1 & ~((int)param_3 >> 0x1f)) * 4);
  if (uVar4 == 0) {
    puVar3 = puVar3 + -1;
    puVar8 = puVar6;
    do {
      puVar9 = puVar8 + 1;
      puVar3 = puVar3 + 1;
      *puVar3 = *puVar8;
      puVar8 = puVar9;
    } while (puVar9 < puVar6 + iVar5);
  }
  else {
    uVar1 = 0;
    puVar8 = puVar6;
    do {
      puVar9 = puVar3;
      *puVar9 = uVar1 | *puVar8 << uVar4;
      puVar7 = puVar8 + 1;
      uVar1 = *puVar8 >> (0x20 - uVar4 & 0xff);
      puVar3 = puVar9 + 1;
      puVar8 = puVar7;
    } while (puVar7 < puVar6 + iVar5);
    puVar9[1] = uVar1;
    if (uVar1 != 0) {
      iVar10 = iVar11 + 2;
    }
  }
  *(int *)(iVar2 + 0x10) = iVar10 + -1;
  _Bfree(param_1,param_2);
  return iVar2;
}



int __mcmp(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  
  iVar2 = *(int *)(param_2 + 0x10);
  iVar3 = *(int *)(param_1 + 0x10) - iVar2;
  if (iVar3 == 0) {
    puVar4 = (uint *)(param_1 + 0x14U) + iVar2;
    puVar1 = (uint *)(param_2 + 0x14 + iVar2 * 4);
    do {
      puVar4 = puVar4 + -1;
      puVar1 = puVar1 + -1;
      if (*puVar4 != *puVar1) {
        if (*puVar1 <= *puVar4) {
          return 1;
        }
        return -1;
      }
    } while ((uint *)(param_1 + 0x14U) < puVar4);
  }
  return iVar3;
}



void __mdiff(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  uint *puVar8;
  int iVar9;
  uint *puVar10;
  uint *puVar11;
  uint *puVar12;
  int iVar13;
  bool bVar14;
  
  iVar1 = __mcmp(param_2,param_3);
  bVar14 = -1 < iVar1;
  if (iVar1 == 0) {
    iVar1 = _Balloc(param_1,0);
    *(undefined4 *)(iVar1 + 0x10) = 1;
    *(undefined4 *)(iVar1 + 0x14) = 0;
  }
  else {
    iVar1 = param_3;
    if (bVar14) {
      iVar1 = param_2;
      param_4 = param_3;
    }
    if (!bVar14) {
      param_4 = param_2;
    }
    iVar2 = _Balloc(param_1,*(undefined4 *)(iVar1 + 4));
    iVar5 = *(int *)(param_4 + 0x10);
    *(uint *)(iVar2 + 0xc) = (uint)!bVar14;
    iVar9 = *(int *)(iVar1 + 0x10);
    iVar13 = 0;
    puVar4 = (uint *)(iVar1 + 0x14);
    puVar7 = (uint *)(iVar2 + 0x14);
    puVar10 = (uint *)(param_4 + 0x14);
    do {
      puVar12 = puVar4 + 1;
      puVar11 = puVar10 + 1;
      uVar3 = (iVar13 + (*puVar4 & 0xffff)) - (*puVar10 & 0xffff);
      iVar6 = ((*puVar4 >> 0x10) - (*puVar10 >> 0x10)) + ((int)uVar3 >> 0x10);
      iVar13 = iVar6 >> 0x10;
      *puVar7 = uVar3 & 0xffff | iVar6 * 0x10000;
      puVar4 = puVar12;
      puVar8 = puVar7 + 1;
      puVar7 = puVar7 + 1;
      puVar10 = puVar11;
    } while (puVar11 < (uint *)(param_4 + 0x14) + iVar5);
    for (; puVar12 < (uint *)(iVar1 + 0x14) + iVar9; puVar12 = puVar12 + 1) {
      uVar3 = iVar13 + (*puVar12 & 0xffff);
      iVar5 = ((int)uVar3 >> 0x10) + (*puVar12 >> 0x10);
      iVar13 = iVar5 >> 0x10;
      *puVar8 = uVar3 & 0xffff | iVar5 * 0x10000;
      puVar8 = puVar8 + 1;
    }
    while (puVar8 = puVar8 + -1, *puVar8 == 0) {
      iVar9 = iVar9 + -1;
    }
    *(int *)(iVar2 + 0x10) = iVar9;
  }
  return;
}



int __d2b(uint param_1,uint param_2,uint param_3,uint param_4,int *param_5,int *param_6)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  uint local_28;
  uint local_24;
  uint uStack32;
  
  local_28 = param_1;
  local_24 = param_2;
  uStack32 = param_3;
  iVar1 = _Balloc(param_1,1);
  uVar6 = (param_4 << 1) >> 0x15;
  local_24 = param_4 & 0xfffff;
  if (uVar6 != 0) {
    local_24 = local_24 | 0x100000;
  }
  if (param_3 == 0) {
    iVar3 = __lo0bits(&local_24);
    *(uint *)(iVar1 + 0x14) = local_24;
    iVar4 = 1;
    *(undefined4 *)(iVar1 + 0x10) = 1;
    uVar2 = iVar3 + 0x20;
  }
  else {
    local_28 = param_3;
    uVar2 = __lo0bits(&local_28);
    if (uVar2 == 0) {
      *(uint *)(iVar1 + 0x14) = local_28;
    }
    else {
      uVar5 = local_24 << (0x20 - uVar2 & 0xff);
      local_24 = local_24 >> (uVar2 & 0xff);
      *(uint *)(iVar1 + 0x14) = uVar5 | local_28;
    }
    *(uint *)(iVar1 + 0x18) = local_24;
    if (local_24 == 0) {
      iVar4 = 1;
    }
    else {
      iVar4 = 2;
    }
    *(int *)(iVar1 + 0x10) = iVar4;
  }
  if (uVar6 == 0) {
    *param_5 = uVar2 - 0x432;
    uVar7 = __hi0bits(*(undefined4 *)(iVar1 + iVar4 * 4 + 0x10));
    iVar3 = (int)((ulonglong)uVar7 >> 0x20) * 0x20 - (int)uVar7;
  }
  else {
    *param_5 = (uVar6 - 0x433) + uVar2;
    iVar3 = 0x35 - uVar2;
  }
  *param_6 = iVar3;
  return iVar1;
}



void * _calloc_r(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  void *__s;
  
  __s = (void *)_malloc_r(param_1,param_3 * param_2,param_3,param_4,param_4);
  if (__s != (void *)0x0) {
    memset(__s,0,param_3 * param_2);
  }
  return __s;
}



void _free_r(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int **extraout_r1;
  int **ppiVar2;
  int **ppiVar3;
  int **ppiVar4;
  int **ppiVar5;
  bool bVar6;
  
  if (param_2 == 0) {
    return;
  }
  ppiVar5 = (int **)(param_2 + -4);
  if (*(int *)(param_2 + -4) < 0) {
    ppiVar5 = (int **)((int)ppiVar5 + *(int *)(param_2 + -4));
  }
  __malloc_lock();
  ppiVar3 = (int **)&__malloc_free_list;
  if (__malloc_free_list == (int **)0x0) {
    ppiVar5[1] = (int *)0x0;
    ppiVar2 = extraout_r1;
    __malloc_free_list = ppiVar5;
  }
  else {
    ppiVar3 = __malloc_free_list;
    if (ppiVar5 < __malloc_free_list) {
      ppiVar2 = (int **)*ppiVar5;
      ppiVar3 = (int **)((int)ppiVar5 + (int)ppiVar2);
      bVar6 = __malloc_free_list == ppiVar3;
      if (bVar6) {
        ppiVar3 = (int **)*__malloc_free_list;
        __malloc_free_list = (int **)__malloc_free_list[1];
      }
      ppiVar5[1] = (int *)__malloc_free_list;
      __malloc_free_list = ppiVar5;
      if (bVar6) {
        ppiVar3 = (int **)((int)ppiVar3 + (int)ppiVar2);
        *ppiVar5 = (int *)ppiVar3;
      }
    }
    else {
      do {
        ppiVar4 = ppiVar3;
        ppiVar3 = (int **)ppiVar4[1];
        if (ppiVar3 == (int **)0x0) break;
      } while (ppiVar3 <= ppiVar5);
      ppiVar2 = (int **)*ppiVar4;
      if ((int **)((int)ppiVar4 + (int)ppiVar2) == ppiVar5) {
        ppiVar2 = (int **)((int)ppiVar2 + (int)*ppiVar5);
        *ppiVar4 = (int *)ppiVar2;
        if (ppiVar3 == (int **)((int)ppiVar4 + (int)ppiVar2)) {
          piVar1 = *ppiVar3;
          ppiVar3 = (int **)ppiVar3[1];
          ppiVar4[1] = (int *)ppiVar3;
          ppiVar2 = (int **)((int)ppiVar2 + (int)piVar1);
          *ppiVar4 = (int *)ppiVar2;
        }
      }
      else {
        if (ppiVar5 < (int **)((int)ppiVar4 + (int)ppiVar2)) {
          *param_1 = 0xc;
        }
        else {
          ppiVar2 = (int **)((int)ppiVar5 + (int)*ppiVar5);
          bVar6 = ppiVar3 == ppiVar2;
          if (bVar6) {
            ppiVar2 = (int **)*ppiVar3;
            ppiVar3 = (int **)ppiVar3[1];
          }
          ppiVar5[1] = (int *)ppiVar3;
          if (bVar6) {
            ppiVar2 = (int **)((int)ppiVar2 + (int)*ppiVar5);
            *ppiVar5 = (int *)ppiVar2;
          }
          ppiVar4[1] = (int *)ppiVar5;
        }
      }
    }
  }
  __malloc_unlock(param_1,ppiVar2,ppiVar3,param_4);
  return;
}



undefined4 __ssputs_r(undefined4 *param_1,void **param_2,void *param_3,void *param_4)

{
  void *pvVar1;
  void *pvVar2;
  size_t __n;
  
  if (param_2[2] <= param_4) {
    pvVar2 = param_2[2];
    if ((*(ushort *)(param_2 + 3) & 0x480) != 0) {
      __n = (int)*param_2 - (int)param_2[4];
      pvVar2 = (void *)((uint)((int)param_2[5] * 3) / 2);
      pvVar1 = (void *)((int)param_4 + __n + 1);
      if (pvVar2 < pvVar1) {
        pvVar2 = pvVar1;
      }
      if ((int)((uint)*(ushort *)(param_2 + 3) << 0x15) < 0) {
        pvVar1 = (void *)_malloc_r(param_1,pvVar2);
        if (pvVar1 == (void *)0x0) {
LAB_0001671a:
          *param_1 = 0xc;
          *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 0x40;
          return 0xffffffff;
        }
        memcpy(pvVar1,param_2[4],__n);
        *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) & 0xfb7f | 0x80;
      }
      else {
        pvVar1 = (void *)_realloc_r(param_1,param_2[4],pvVar2);
        if (pvVar1 == (void *)0x0) {
          _free_r(param_1,param_2[4]);
          goto LAB_0001671a;
        }
      }
      param_2[4] = pvVar1;
      param_2[5] = pvVar2;
      *param_2 = (void *)((int)pvVar1 + __n);
      param_2[2] = (void *)((int)pvVar2 - __n);
      pvVar2 = param_4;
    }
    if (pvVar2 <= param_4) goto LAB_00016758;
  }
  pvVar2 = param_4;
LAB_00016758:
  memmove(*param_2,param_3,(size_t)pvVar2);
  param_2[2] = (void *)((int)param_2[2] - (int)pvVar2);
  *param_2 = (void *)((int)pvVar2 + (int)*param_2);
  return 0;
}



// WARNING: Removing unreachable block (ram,0x000168e0)

int _svfiprintf_r(undefined4 *param_1,int *param_2,byte *param_3,int *param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  int *piVar5;
  byte *pbVar6;
  byte *pbVar7;
  int *local_8c;
  uint local_88;
  int local_84;
  undefined4 uStack128;
  int local_7c;
  int local_74;
  byte local_70;
  undefined local_6f;
  undefined local_6e;
  undefined local_45;
  undefined4 local_30;
  
  local_8c = param_4;
  if (((int)((uint)*(ushort *)(param_2 + 3) << 0x18) < 0) && (param_2[4] == 0)) {
    iVar2 = _malloc_r(param_1,0x40);
    *param_2 = iVar2;
    param_2[4] = iVar2;
    if (iVar2 == 0) {
      *param_1 = 0xc;
      return -1;
    }
    param_2[5] = 0x40;
  }
  local_74 = 0;
  local_6f = 0x20;
  local_6e = 0x30;
  pbVar6 = param_3;
LAB_000167d2:
  pbVar7 = pbVar6;
  if (*pbVar7 != 0) goto code_r0x000167da;
  goto LAB_000167de;
code_r0x000167da:
  pbVar6 = pbVar7 + 1;
  if (*pbVar7 != 0x25) goto LAB_000167d2;
LAB_000167de:
  iVar2 = (int)pbVar7 - (int)param_3;
  if (iVar2 != 0) {
    iVar3 = __ssputs_r(param_1,param_2,param_3,iVar2);
    if (iVar3 == -1) {
LAB_0001693e:
      if ((int)((uint)*(ushort *)(param_2 + 3) << 0x19) < 0) {
        return -1;
      }
      return local_74;
    }
    local_74 = local_74 + iVar2;
  }
  if (*pbVar7 == 0) goto LAB_0001693e;
  local_84 = -1;
  uStack128 = 0;
  local_88 = 0;
  local_7c = 0;
  local_45 = 0;
  local_30 = 0;
  pbVar6 = pbVar7 + 1;
  while( true ) {
    param_3 = pbVar6 + 1;
    pvVar4 = memchr("#-0+ ",(uint)*pbVar6,5);
    if (pvVar4 == (void *)0x0) break;
    local_88 = 1 << ((int)pvVar4 - 0x1cd8cU & 0xff) | local_88;
    pbVar6 = param_3;
  }
  if ((int)(local_88 << 0x1b) < 0) {
    local_45 = 0x20;
  }
  if ((int)(local_88 << 0x1c) < 0) {
    local_45 = 0x2b;
  }
  if (*pbVar6 == 0x2a) {
    piVar5 = local_8c + 1;
    iVar2 = *local_8c;
    local_8c = piVar5;
    if (iVar2 < 0) {
      local_7c = -iVar2;
      local_88 = local_88 | 2;
      goto LAB_0001688a;
    }
  }
  else {
    bVar1 = false;
    iVar2 = local_7c;
    param_3 = pbVar6;
    while( true ) {
      if (9 < *param_3 - 0x30) break;
      iVar2 = iVar2 * 10 + (*param_3 - 0x30);
      bVar1 = true;
      param_3 = param_3 + 1;
    }
    if (!bVar1) goto LAB_0001688a;
  }
  local_7c = iVar2;
LAB_0001688a:
  if (*param_3 == 0x2e) {
    if (param_3[1] == 0x2a) {
      local_84 = *local_8c;
      if (local_84 < 0) {
        local_84 = -1;
      }
      param_3 = param_3 + 2;
      local_8c = local_8c + 1;
    }
    else {
      bVar1 = false;
      local_84 = 0;
      iVar2 = 0;
      while( true ) {
        param_3 = param_3 + 1;
        if (9 < *param_3 - 0x30) break;
        iVar2 = iVar2 * 10 + (*param_3 - 0x30);
        bVar1 = true;
      }
      if (bVar1) {
        local_84 = iVar2;
      }
    }
  }
  pvVar4 = memchr(&DAT_0001cd92,(uint)*param_3,3);
  if (pvVar4 != (void *)0x0) {
    local_88 = local_88 | 0x40 << ((int)pvVar4 - 0x1cd92U & 0xff);
    param_3 = param_3 + 1;
  }
  local_70 = *param_3;
  param_3 = param_3 + 1;
  pvVar4 = memchr(&DAT_0001cd96,(uint)local_70,6);
  if (pvVar4 == (void *)0x0) {
    iVar2 = _printf_i(param_1,&local_88,param_2,0x166d5,&local_8c);
  }
  else {
    iVar2 = _printf_float(param_1,&local_88,param_2,0x166d5,&local_8c);
  }
  if (iVar2 == -1) goto LAB_0001693e;
  local_74 = local_74 + iVar2;
  pbVar6 = param_3;
  goto LAB_000167d2;
}



int __sfputc_r(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = param_3[2] + -1;
  param_3[2] = iVar1;
  if ((iVar1 < 0) && ((iVar1 < (int)param_3[6] || (param_2 == 10)))) {
    iVar1 = __swbuf_r();
    return iVar1;
  }
  puVar2 = (undefined *)*param_3;
  *param_3 = puVar2 + 1;
  *puVar2 = (char)param_2;
  return param_2;
}



int __sfputs_r(undefined4 param_1,undefined4 param_2,undefined *param_3,int param_4)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  
  puVar2 = param_3 + param_4;
  iVar3 = param_4;
  do {
    if (param_3 == puVar2) {
      return 0;
    }
    iVar1 = __sfputc_r(param_1,*param_3,param_2,param_4,iVar3);
    param_4 = iVar1 + 1;
    param_3 = param_3 + 1;
  } while (param_4 != 0);
  return iVar1;
}



// WARNING: Removing unreachable block (ram,0x00016b52)

int _vfprintf_r(int param_1,undefined4 *param_2,byte *param_3,int *param_4)

{
  bool bVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  byte *pbVar5;
  byte *pbVar6;
  int iVar7;
  int *local_8c;
  uint local_88;
  int local_84;
  undefined4 uStack128;
  int local_7c;
  int local_74;
  byte local_70;
  undefined local_6f;
  undefined local_6e;
  undefined local_45;
  undefined4 local_30;
  
  local_8c = param_4;
  if ((param_1 != 0) && (*(int *)(param_1 + 0x18) == 0)) {
    __sinit();
  }
  if (param_2 == &__sf_fake_stdin) {
    param_2 = *(undefined4 **)(param_1 + 4);
  }
  else {
    if (param_2 == (undefined4 *)&__sf_fake_stdout) {
      param_2 = *(undefined4 **)(param_1 + 8);
    }
    else {
      if (param_2 == (undefined4 *)&__sf_fake_stderr) {
        param_2 = *(undefined4 **)(param_1 + 0xc);
      }
    }
  }
  if (((-1 < (int)((uint)*(ushort *)(param_2 + 3) << 0x1c)) || (param_2[4] == 0)) &&
     (iVar7 = __swsetup_r(param_1,param_2), iVar7 != 0)) {
    return -1;
  }
  local_74 = 0;
  local_6f = 0x20;
  local_6e = 0x30;
  pbVar5 = param_3;
LAB_00016a0a:
  pbVar6 = pbVar5;
  if (*pbVar6 != 0) goto code_r0x00016a12;
  goto LAB_00016a16;
code_r0x00016a12:
  pbVar5 = pbVar6 + 1;
  if (*pbVar6 != 0x25) goto LAB_00016a0a;
LAB_00016a16:
  iVar7 = (int)pbVar6 - (int)param_3;
  if (iVar7 != 0) {
    iVar2 = __sfputs_r(param_1,param_2,param_3,iVar7);
    if (iVar2 == -1) {
LAB_00016bb2:
      if ((int)((uint)*(ushort *)(param_2 + 3) << 0x19) < 0) {
        return -1;
      }
      return local_74;
    }
    local_74 = local_74 + iVar7;
  }
  if (*pbVar6 == 0) goto LAB_00016bb2;
  local_84 = -1;
  uStack128 = 0;
  local_88 = 0;
  local_7c = 0;
  local_45 = 0;
  local_30 = 0;
  pbVar5 = pbVar6 + 1;
  while( true ) {
    param_3 = pbVar5 + 1;
    pvVar3 = memchr("#-0+ ",(uint)*pbVar5,5);
    if (pvVar3 == (void *)0x0) break;
    local_88 = 1 << ((int)pvVar3 - 0x1cd8cU & 0xff) | local_88;
    pbVar5 = param_3;
  }
  if ((int)(local_88 << 0x1b) < 0) {
    local_45 = 0x20;
  }
  if ((int)(local_88 << 0x1c) < 0) {
    local_45 = 0x2b;
  }
  if (*pbVar5 == 0x2a) {
    piVar4 = local_8c + 1;
    iVar7 = *local_8c;
    local_8c = piVar4;
    if (iVar7 < 0) {
      local_7c = -iVar7;
      local_88 = local_88 | 2;
      goto LAB_00016aee;
    }
  }
  else {
    bVar1 = false;
    iVar7 = local_7c;
    param_3 = pbVar5;
    while( true ) {
      if (9 < *param_3 - 0x30) break;
      iVar7 = iVar7 * 10 + (*param_3 - 0x30);
      bVar1 = true;
      param_3 = param_3 + 1;
    }
    if (!bVar1) goto LAB_00016aee;
  }
  local_7c = iVar7;
LAB_00016aee:
  if (*param_3 == 0x2e) {
    if (param_3[1] == 0x2a) {
      local_84 = *local_8c;
      if (local_84 < 0) {
        local_84 = -1;
      }
      param_3 = param_3 + 2;
      local_8c = local_8c + 1;
    }
    else {
      bVar1 = false;
      local_84 = 0;
      iVar7 = 0;
      while( true ) {
        param_3 = param_3 + 1;
        if (9 < *param_3 - 0x30) break;
        iVar7 = iVar7 * 10 + (*param_3 - 0x30);
        bVar1 = true;
      }
      if (bVar1) {
        local_84 = iVar7;
      }
    }
  }
  pvVar3 = memchr(&DAT_0001cd92,(uint)*param_3,3);
  if (pvVar3 != (void *)0x0) {
    local_88 = local_88 | 0x40 << ((int)pvVar3 - 0x1cd92U & 0xff);
    param_3 = param_3 + 1;
  }
  local_70 = *param_3;
  param_3 = param_3 + 1;
  pvVar3 = memchr(&DAT_0001cd96,(uint)local_70,6);
  if (pvVar3 == (void *)0x0) {
    iVar7 = _printf_i(param_1,&local_88,param_2,0x169a3,&local_8c);
  }
  else {
    iVar7 = _printf_float(param_1,&local_88,param_2,0x169a3,&local_8c);
  }
  if (iVar7 == -1) goto LAB_00016bb2;
  local_74 = local_74 + iVar7;
  pbVar5 = param_3;
  goto LAB_00016a0a;
}



uint _putc_r(int param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x18) == 0)) {
    __sinit();
  }
  if (param_3 == &__sf_fake_stdin) {
    param_3 = *(undefined4 **)(param_1 + 4);
  }
  else {
    if (param_3 == (undefined4 *)&__sf_fake_stdout) {
      param_3 = *(undefined4 **)(param_1 + 8);
    }
    else {
      if (param_3 == (undefined4 *)&__sf_fake_stderr) {
        param_3 = *(undefined4 **)(param_1 + 0xc);
      }
    }
  }
  iVar2 = param_3[2] + -1;
  param_3[2] = iVar2;
  if ((iVar2 < 0) && ((iVar2 < (int)param_3[6] || ((param_2 & 0xff) == 10)))) {
    uVar1 = __swbuf_r(param_1,param_2,param_3);
    return uVar1;
  }
  puVar3 = (undefined *)*param_3;
  *param_3 = puVar3 + 1;
  *puVar3 = (char)param_2;
  return param_2 & 0xff;
}



void _read_r(int *param_1,int param_2,char *param_3,int param_4)

{
  int iVar1;
  
  errno = 0;
  iVar1 = _read(param_2,param_3,param_4);
  if ((iVar1 == -1) && (errno != 0)) {
    *param_1 = errno;
  }
  return;
}



uint __srget_r(int param_1,byte **param_2)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x18) == 0)) {
    __sinit();
  }
  if (param_2 == (byte **)&__sf_fake_stdin) {
    param_2 = *(byte ***)(param_1 + 4);
  }
  else {
    if (param_2 == (byte **)&__sf_fake_stdout) {
      param_2 = *(byte ***)(param_1 + 8);
    }
    else {
      if (param_2 == (byte **)&__sf_fake_stderr) {
        param_2 = *(byte ***)(param_1 + 0xc);
      }
    }
  }
  iVar1 = __srefill_r(param_1,param_2);
  if (iVar1 == 0) {
    param_2[1] = param_2[1] + -1;
    pbVar3 = *param_2;
    *param_2 = pbVar3 + 1;
    uVar2 = (uint)*pbVar3;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



undefined4 __ascii_wctomb(undefined4 *param_1,undefined *param_2,uint param_3)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined *)0x0) {
    return 0;
  }
  if (param_3 < 0x100) {
    *param_2 = (char)param_3;
    uVar1 = 1;
  }
  else {
    *param_1 = 0x8a;
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



void _fstat_r(int *param_1,int param_2,stat *param_3)

{
  int iVar1;
  
  errno = 0;
  iVar1 = _fstat(param_2,param_3);
  if ((iVar1 == -1) && (errno != 0)) {
    *param_1 = errno;
  }
  return;
}



void _isatty_r(int *param_1,int param_2)

{
  int iVar1;
  
  errno = 0;
  iVar1 = _isatty(param_2);
  if ((iVar1 == -1) && (errno != 0)) {
    *param_1 = errno;
  }
  return;
}



void * _realloc_r(undefined4 param_1,void *param_2,void *param_3,undefined4 param_4)

{
  void *pvVar1;
  void *pvVar2;
  
  if (param_2 != (void *)0x0) {
    if (param_3 == (void *)0x0) {
      _free_r();
      pvVar1 = param_3;
    }
    else {
      pvVar2 = (void *)_malloc_usable_size_r();
      pvVar1 = param_2;
      if ((pvVar2 < param_3) && (pvVar1 = (void *)_malloc_r(param_1,param_3), pvVar1 != (void *)0x0)
         ) {
        memcpy(pvVar1,param_2,(size_t)param_3);
        _free_r(param_1,param_2);
      }
    }
    return pvVar1;
  }
  pvVar1 = (void *)_malloc_r(param_1,param_3,param_3,param_4);
  return pvVar1;
}



int lflush(FILE *param_1)

{
  int iVar1;
  
  if ((*(ushort *)&param_1->_IO_read_base & 9) == 9) {
    iVar1 = fflush(param_1);
    return iVar1;
  }
  return 0;
}



undefined4
__srefill_r(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  ushort uVar3;
  uint uVar4;
  
  if ((param_1 != (undefined4 *)0x0) && (param_1[6] == 0)) {
    __sinit();
  }
  if (param_2 == &__sf_fake_stdin) {
    param_2 = (undefined4 *)param_1[1];
  }
  else {
    if (param_2 == (undefined4 *)&__sf_fake_stdout) {
      param_2 = (undefined4 *)param_1[2];
    }
    else {
      if (param_2 == (undefined4 *)&__sf_fake_stderr) {
        param_2 = (undefined4 *)param_1[3];
      }
    }
  }
  uVar3 = *(ushort *)(param_2 + 3);
  param_2[1] = 0;
  uVar4 = (uint)uVar3;
  if (-1 < (int)(uVar4 << 0x1a)) {
    if ((int)(uVar4 << 0x1d) < 0) {
      if ((undefined4 *)param_2[0xd] != (undefined4 *)0x0) {
        if ((undefined4 *)param_2[0xd] != param_2 + 0x11) {
          _free_r(param_1);
        }
        param_2[1] = param_2[0x10];
        param_2[0xd] = 0;
        if (param_2[0x10] != 0) {
          *param_2 = param_2[0xf];
          return 0;
        }
      }
    }
    else {
      if (-1 < (int)(uVar4 << 0x1b)) {
        *param_1 = 9;
        *(ushort *)(param_2 + 3) = uVar3 | 0x40;
        return 0xffffffff;
      }
      if ((int)(uVar4 << 0x1c) < 0) {
        iVar1 = _fflush_r(param_1,param_2,uVar4 << 0x1c,uVar4,param_4);
        if (iVar1 != 0) {
          return 0xffffffff;
        }
        param_2[2] = 0;
        *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) & 0xfff7;
        param_2[6] = 0;
      }
      *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 4;
    }
    if (param_2[4] == 0) {
      __smakebuf_r(param_1,param_2);
    }
    uVar3 = *(ushort *)(param_2 + 3);
    if ((uVar3 & 3) != 0) {
      *(undefined2 *)(param_2 + 3) = 1;
      _fwalk(&impure_data,0x16d85);
      *(ushort *)(param_2 + 3) = uVar3;
      if ((uVar3 & 9) == 9) {
        __sflush_r(param_1,param_2);
      }
    }
    uVar2 = param_2[4];
    *param_2 = uVar2;
    iVar1 = (*(code *)param_2[9])(param_1,param_2[8],uVar2,param_2[5]);
    param_2[1] = iVar1;
    if (0 < iVar1) {
      return 0;
    }
    if (iVar1 != 0) {
      uVar2 = 0;
      uVar3 = *(ushort *)(param_2 + 3) | 0x40;
    }
    else {
      uVar3 = *(ushort *)(param_2 + 3) | 0x20;
    }
    if (iVar1 != 0) {
      param_2[1] = uVar2;
    }
    *(ushort *)(param_2 + 3) = uVar3;
  }
  return 0xffffffff;
}



int _malloc_usable_size_r(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + -4) + -4;
  if (*(int *)(param_2 + -4) < 0) {
    iVar1 = iVar1 + *(int *)(param_2 + iVar1);
  }
  return iVar1;
}



uint __gedf2(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  
  if (((int)(param_2 << 1) >> 0x15 == -1 || (int)(param_4 << 1) >> 0x15 == -1) &&
     ((((int)(param_2 << 1) >> 0x15 == -1 && ((param_1 | param_2 << 0xc) != 0)) ||
      (((int)(param_4 << 1) >> 0x15 == -1 && ((param_3 | param_4 << 0xc) != 0)))))) {
    return 0xffffffff;
  }
  bVar2 = (param_1 | param_2 << 1) == 0;
  if (bVar2) {
    bVar2 = (param_3 | param_4 << 1) == 0;
  }
  if (!bVar2) {
    bVar2 = param_2 == param_4;
  }
  if (bVar2) {
    bVar2 = param_1 == param_3;
  }
  if (!bVar2) {
    uVar1 = param_2 ^ param_4;
    bVar2 = uVar1 == 0;
    if (-1 < (int)uVar1) {
      bVar2 = param_2 == param_4;
    }
    bVar3 = -1 < (int)uVar1 && param_4 <= param_2;
    if (bVar2) {
      bVar3 = param_3 <= param_1;
    }
    param_4 = (int)param_4 >> 0x1f;
    if (!bVar3) {
      param_4 = ~param_4;
    }
    return param_4 | 1;
  }
  return 0;
}



uint __ledf2(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  
  if (((int)(param_2 << 1) >> 0x15 == -1 || (int)(param_4 << 1) >> 0x15 == -1) &&
     ((((int)(param_2 << 1) >> 0x15 == -1 && ((param_1 | param_2 << 0xc) != 0)) ||
      (((int)(param_4 << 1) >> 0x15 == -1 && ((param_3 | param_4 << 0xc) != 0)))))) {
    return 1;
  }
  bVar2 = (param_1 | param_2 << 1) == 0;
  if (bVar2) {
    bVar2 = (param_3 | param_4 << 1) == 0;
  }
  if (!bVar2) {
    bVar2 = param_2 == param_4;
  }
  if (bVar2) {
    bVar2 = param_1 == param_3;
  }
  if (!bVar2) {
    uVar1 = param_2 ^ param_4;
    bVar2 = uVar1 == 0;
    if (-1 < (int)uVar1) {
      bVar2 = param_2 == param_4;
    }
    bVar3 = -1 < (int)uVar1 && param_4 <= param_2;
    if (bVar2) {
      bVar3 = param_3 <= param_1;
    }
    param_4 = (int)param_4 >> 0x1f;
    if (!bVar3) {
      param_4 = ~param_4;
    }
    return param_4 | 1;
  }
  return 0;
}



uint __nedf2(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  
  if (((int)(param_2 << 1) >> 0x15 == -1 || (int)(param_4 << 1) >> 0x15 == -1) &&
     ((((int)(param_2 << 1) >> 0x15 == -1 && ((param_1 | param_2 << 0xc) != 0)) ||
      (((int)(param_4 << 1) >> 0x15 == -1 && ((param_3 | param_4 << 0xc) != 0)))))) {
    return 1;
  }
  bVar2 = (param_1 | param_2 << 1) == 0;
  if (bVar2) {
    bVar2 = (param_3 | param_4 << 1) == 0;
  }
  if (!bVar2) {
    bVar2 = param_2 == param_4;
  }
  if (bVar2) {
    bVar2 = param_1 == param_3;
  }
  if (!bVar2) {
    uVar1 = param_2 ^ param_4;
    bVar2 = uVar1 == 0;
    if (-1 < (int)uVar1) {
      bVar2 = param_2 == param_4;
    }
    bVar3 = -1 < (int)uVar1 && param_4 <= param_2;
    if (bVar2) {
      bVar3 = param_3 <= param_1;
    }
    param_4 = (int)param_4 >> 0x1f;
    if (!bVar3) {
      param_4 = ~param_4;
    }
    return param_4 | 1;
  }
  return 0;
}



void __aeabi_cdrcmple(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  __aeabi_cdcmpeq(param_3,param_4,param_1,param_2);
  return;
}



undefined4 __aeabi_cdcmpeq(undefined4 param_1)

{
  __nedf2();
  return param_1;
}



bool __aeabi_dcmpeq(void)

{
  char in_ZR;
  
  __aeabi_cdcmpeq();
  return in_ZR != '\0';
}



bool __aeabi_dcmplt(void)

{
  char in_CY;
  
  __aeabi_cdcmpeq();
  return in_CY == '\0';
}



bool __aeabi_dcmple(void)

{
  undefined in_ZR;
  undefined in_CY;
  
  __aeabi_cdcmpeq();
  return !(bool)in_CY || (bool)in_ZR;
}



bool __aeabi_dcmpge(void)

{
  undefined in_ZR;
  undefined in_CY;
  
  __aeabi_cdrcmple();
  return !(bool)in_CY || (bool)in_ZR;
}



bool __aeabi_dcmpgt(void)

{
  char in_CY;
  
  __aeabi_cdrcmple();
  return in_CY == '\0';
}



undefined4 __unorddf2(uint param_1,int param_2,uint param_3,int param_4)

{
  if ((((param_2 << 1) >> 0x15 != -1) || ((param_1 | param_2 << 0xc) == 0)) &&
     (((param_4 << 1) >> 0x15 != -1 || ((param_3 | param_4 << 0xc) == 0)))) {
    return 0;
  }
  return 1;
}



uint __aeabi_d2iz(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = param_2 * 2 + 0x200000;
  if (param_2 * 2 < 0xffe00000) {
    if (-1 < iVar2) {
      return 0;
    }
    uVar1 = iVar2 >> 0x15;
    uVar3 = -uVar1 - 0x3e1;
    if (uVar1 < 0xfffffc20 && uVar3 != 0) {
      uVar1 = (param_2 << 0xb | 0x80000000 | param_1 >> 0x15) >> (uVar3 & 0xff);
      if ((param_2 & 0x80000000) != 0) {
        uVar1 = -uVar1;
      }
      return uVar1;
    }
  }
  else {
    if ((param_1 | param_2 << 0xc) != 0) {
      return 0;
    }
  }
  param_2 = param_2 & 0x80000000;
  if (param_2 == 0) {
    param_2 = 0x7fffffff;
  }
  return param_2;
}



int _init(EVP_PKEY_CTX *ctx)

{
  return (int)ctx;
}



void _fini(void)

{
  return;
}


