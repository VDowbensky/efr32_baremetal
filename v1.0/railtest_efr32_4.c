#include "railtest_efr32_4.h"



// WARNING: Control flow encountered bad instruction data

void FUN_00000000(void)

{
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



undefined1 * __do_global_dtors_aux(undefined1 *param_1)

{
  if (completed_9929 == '\0') {
    if (false) {
      param_1 = &__FRAME_END__;
    }
    completed_9929 = '\x01';
  }
  return param_1;
}



undefined8 frame_dummy(undefined1 *param_1,undefined *param_2)

{
  if (false) {
    param_2 = &object_9934;
    param_1 = &__FRAME_END__;
  }
  return CONCAT44(param_2,param_1);
}



void _start(void)

{
  int __status;
  
  memset(&completed_9929,0,0x262c);
  if (false) {
    FUN_00000000();
  }
  if (false) {
    FUN_00000000();
  }
  __libc_init_array(0,0);
  __status = main();
                    // WARNING: Subroutine does not return
  exit(__status);
}



// WARNING: Could not reconcile some variable overlaps

void ieee802154Enable(int argc,char **argv)

{
  _Bool _Var1;
  RAIL_Status_t code;
  int iVar2;
  uint32_t uVar3;
  char *pcVar4;
  RAIL_IEEE802154_Config_t config;
  
  _Var1 = inRadioState(RAIL_RF_STATE_IDLE,*argv);
  if (_Var1 == false) {
    return;
  }
  pcVar4 = argv[1];
  config._0_4_ = 0x10b0000;
  config._4_4_ = 0xc00064;
  config._8_4_ = 1000;
  config.addresses = (RAIL_IEEE802154_AddrConfig_t *)0x0;
  iVar2 = memcmp(pcVar4,&DAT_00010987,4);
  if (iVar2 == 0) {
    config._0_4_ = config._0_4_ & 0xffffff;
  }
  else {
    iVar2 = memcmp(pcVar4,&DAT_0001098c,2);
    if (iVar2 != 0) {
      pcVar4 = "Unknown auto ack default state.";
      code = 0x20;
      goto LAB_000001d0;
    }
  }
  uVar3 = ciGetUnsigned(argv[2]);
  if ((uVar3 & 0xffff) < 0x32c9) {
    config._4_4_ = config._4_4_ & 0xffff0000 | uVar3 & 0xffff;
    uVar3 = ciGetUnsigned(argv[3]);
    if ((uVar3 & 0xffff) < 0x32c9) {
      config._4_4_ = config._4_4_ & 0xffff | (uVar3 & 0xffff) << 0x10;
      uVar3 = ciGetUnsigned(argv[4]);
      config._8_4_ = config._8_4_ & 0xffff0000 | uVar3 & 0xffff;
      code = RAIL_IEEE802154_Init(&config);
      if (code == RAIL_STATUS_NO_ERROR) {
        responsePrint(*argv,
                      "802.15.4:%s,defaultState:%s,idleTiming:%d,turnaroundTime:%d,ackTimeout:%d",
                      "Enabled",rfStates[config._0_4_ >> 0x18],config._4_4_ & 0xffff,
                      config._4_4_ >> 0x10,config._8_4_ & 0xffff);
        return;
      }
      pcVar4 = "Call to RAIL_IEEE802154_Init returned an error";
    }
    else {
      pcVar4 = "Invalid turnaround timing";
      code = 0x22;
    }
  }
  else {
    pcVar4 = "Invalid idle timing.";
    code = 0x21;
  }
LAB_000001d0:
  responsePrintError(*argv,code,pcVar4);
  return;
}



void config2p4Ghz802154(int argc,char **argv)

{
  _Bool _Var1;
  RAIL_Status_t RVar2;
  char *pcVar3;
  undefined4 in_r3;
  
  _Var1 = inRadioState(RAIL_RF_STATE_IDLE,*argv);
  if (_Var1 != false) {
    RVar2 = RAIL_IEEE802154_2p4GHzRadioConfig();
    changeChannel(0xb);
    pcVar3 = "Disabled";
    if (RVar2 == RAIL_STATUS_NO_ERROR) {
      pcVar3 = "Enabled";
    }
    responsePrint(*argv,"802.15.4:%s",pcVar3,in_r3);
    return;
  }
  return;
}



void ieee802154AcceptFrames(int argc,char **argv)

{
  byte framesMask;
  RAIL_Status_t RVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  char *pcVar7;
  
  uVar2 = ciGetUnsigned(argv[1]);
  uVar3 = ciGetUnsigned(argv[2]);
  uVar4 = ciGetUnsigned(argv[3]);
  uVar5 = ciGetUnsigned(argv[4]);
  uVar6 = uVar5;
  if (uVar2 == 0) {
    uVar6 = 0;
  }
  framesMask = (byte)uVar6;
  if (uVar2 != 0) {
    framesMask = 8;
  }
  if (uVar3 != 0) {
    framesMask = framesMask | 4;
  }
  if (uVar4 != 0) {
    framesMask = framesMask | 2;
  }
  if (uVar5 != 0) {
    framesMask = framesMask | 1;
  }
  RVar1 = RAIL_IEEE802154_AcceptFrames(framesMask);
  if (RVar1 == RAIL_STATUS_NO_ERROR) {
    pcVar7 = "Disabled";
    if (uVar2 != 0) {
      pcVar7 = "Enabled";
    }
    responsePrint(*argv,"CommandFrame:%s,AckFrame:%s,DataFrame:%s,BeaconFrame:%s",pcVar7);
    return;
  }
  responsePrintError(*argv,'#',"Failed to set which frames to accept.");
  return;
}



void ieee802154SetPromiscuousMode(int argc,char **argv)

{
  RAIL_Status_t RVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  char *pcVar4;
  undefined4 in_r3;
  
  uVar2 = ciGetUnsigned(argv[1]);
  uVar3 = uVar2;
  if (uVar2 != 0) {
    uVar3 = 1;
  }
  RVar1 = RAIL_IEEE802154_SetPromiscuousMode(SUB41(uVar3,0));
  if (RVar1 != RAIL_STATUS_NO_ERROR) {
    responsePrintError(*argv,'$',"Failed to (un)set promiscuous mode.",in_r3);
    return;
  }
  pcVar4 = "Enabled";
  if (uVar2 == 0) {
    pcVar4 = "Disabled";
  }
  responsePrint(*argv,"PromiscuousMode:%s",pcVar4,in_r3);
  return;
}



void ieee802154SetPanCoordinator(int argc,char **argv)

{
  RAIL_Status_t RVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  char *pcVar4;
  undefined4 in_r3;
  
  uVar2 = ciGetUnsigned(argv[1]);
  uVar3 = uVar2;
  if (uVar2 != 0) {
    uVar3 = 1;
  }
  RVar1 = RAIL_IEEE802154_SetPanCoordinator(SUB41(uVar3,0));
  if (RVar1 != RAIL_STATUS_NO_ERROR) {
    responsePrintError(*argv,'$',"Failed to (un)set PAN Coordinator.",in_r3);
    return;
  }
  pcVar4 = "Enabled";
  if (uVar2 == 0) {
    pcVar4 = "Disabled";
  }
  responsePrint(*argv,"PanCoordinator:%s",pcVar4,in_r3);
  return;
}



void ieee802154SetPanId(int argc,char **argv)

{
  bool bVar1;
  uint32_t uVar2;
  char *pcVar3;
  
  uVar2 = ciGetUnsigned(argv[1]);
  bVar1 = RAIL_IEEE802154_SetPanId((uint16_t)uVar2);
  pcVar3 = "Enabled";
  if (bVar1 == false) {
    pcVar3 = "Disabled";
  }
  responsePrint(*argv,"802.15.4PanId:%s",pcVar3);
  return;
}



void ieee802154SetShortAddress(int argc,char **argv)

{
  bool bVar1;
  uint32_t uVar2;
  char *pcVar3;
  
  uVar2 = ciGetUnsigned(argv[1]);
  bVar1 = RAIL_IEEE802154_SetShortAddress((uint16_t)uVar2);
  pcVar3 = "Enabled";
  if (bVar1 == false) {
    pcVar3 = "Disabled";
  }
  responsePrint(*argv,"802.15.4ShortAddress:%s",pcVar3);
  return;
}



// WARNING: Could not reconcile some variable overlaps

void ieee802154SetLongAddress(int argc,char **argv)

{
  uint32_t uVar1;
  char *pcVar2;
  int iVar3;
  char **ppcVar4;
  uint8_t longAddr [8];
  
  iVar3 = 0;
  ppcVar4 = argv;
  longAddr._0_4_ = argc;
  longAddr._4_4_ = argv;
  do {
    ppcVar4 = ppcVar4 + 1;
    uVar1 = ciGetUnsigned(*ppcVar4);
    longAddr[iVar3] = (uint8_t)uVar1;
    iVar3 = iVar3 + 1;
  } while (iVar3 != 8);
  iVar3 = RAIL_IEEE802154_SetLongAddress(longAddr);
  pcVar2 = "Enabled";
  if (iVar3 == 0) {
    pcVar2 = "Disabled";
  }
  responsePrint(*argv,"802.15.4LongAddress:%s",pcVar2);
  return;
}



void addressFilterByFrame(int argc,char **argv)

{
  bool bVar1;
  uint32_t uVar2;
  
  uVar2 = ciGetUnsigned(argv[1]);
  bVar1 = RAIL_AddressFilterByFrameType((uint8_t)uVar2);
  if (bVar1 != false) {
    responsePrint(*argv,"AddressFilterByFrame:Set");
    return;
  }
  responsePrintError(*argv,'5',"Invalid filtering by frame config.");
  return;
}



void getAddressFilter(int argc,char **argv)

{
  bool bVar1;
  char *pcVar2;
  
  bVar1 = RAIL_AddressFilterIsEnabled();
  pcVar2 = "Enabled";
  if (bVar1 == false) {
    pcVar2 = "Disabled";
  }
  responsePrint(*argv,"AddressFiltering:%s",pcVar2);
  return;
}



void setAddressFilter(int argc,char **argv)

{
  uint32_t uVar1;
  
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



void printAddresses(int argc,char **argv)

{
  byte bVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint8_t *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint8_t *puVar10;
  
  puVar10 = offsets;
  puVar6 = sizes;
  responsePrintHeader(*argv,"Field:%u,Index:%u,Offset:%u,Size:%u,Address:%s,Status:%s");
  iVar8 = 0;
  iVar7 = 0;
  while( true ) {
    iVar9 = iVar7 << 5;
    iVar5 = 0;
    do {
      bVar1 = *puVar6;
      if (*puVar6 != 0) {
        iVar4 = 0;
        for (iVar3 = 0; iVar3 < (int)(uint)*puVar6; iVar3 = iVar3 + 1) {
          siprintf(addressPrintBuffer + iVar4,"0x%.2x ",(uint)addresses[iVar9 + iVar3]);
          iVar4 = iVar4 + 5;
        }
        bVar1 = addressPrintBuffer[0];
        if (iVar4 != 0) {
          addressEnabled[1][iVar4 + 3] = false;
          bVar1 = addressPrintBuffer[0];
        }
      }
      addressPrintBuffer[0] = bVar1;
      iVar9 = iVar9 + 8;
      pcVar2 = "Enabled";
      if (addressEnabled[iVar8 + iVar5] == false) {
        pcVar2 = "Disabled";
      }
      iVar3 = iVar5 + 1;
      responsePrintMulti("Field:%u,Index:%u,Offset:%u,Size:%u,Address:%s,Status:%s",iVar7,iVar5,
                         (uint)*puVar10,(uint)*puVar6,addressPrintBuffer,pcVar2);
      iVar5 = iVar3;
    } while (iVar3 != 4);
    puVar10 = puVar10 + 1;
    puVar6 = puVar6 + 1;
    iVar8 = iVar8 + 4;
    if (iVar7 != 0) break;
    iVar7 = 1;
  }
  return;
}



void setAddressFilterConfig(int argc,char **argv)

{
  bool bVar1;
  uint8_t uVar2;
  undefined4 in_r3;
  uint8_t *puVar4;
  int iVar5;
  int iVar6;
  char **ppcVar7;
  uint32_t uVar3;
  
  offsets = 0;
  sizes = 0;
  memset(addresses,0,0x40);
  addressEnabled[0] = 0;
  addressEnabled[1] = 0;
  config.matchTable = ciGetUnsigned(argv[1]);
  if (argc < 6) {
    iVar5 = argc + -2;
  }
  else {
    iVar5 = 4;
  }
  ppcVar7 = argv + 1;
  for (iVar6 = 0; iVar6 < iVar5; iVar6 = iVar6 + 1) {
    ppcVar7 = ppcVar7 + 1;
    if (iVar6 << 0x1f < 0) {
      uVar3 = ciGetUnsigned(*ppcVar7);
      uVar2 = (uint8_t)uVar3;
      puVar4 = config.sizes;
    }
    else {
      uVar3 = ciGetUnsigned(*ppcVar7);
      uVar2 = (uint8_t)uVar3;
      puVar4 = config.offsets;
    }
    puVar4[iVar6 >> 1] = uVar2;
  }
  bVar1 = RAIL_AddressFilterConfig(&config);
  if (bVar1 == false) {
    responsePrintError(*argv,'0',"Invalid address filtering configuration.",in_r3);
    return;
  }
  printAddresses(1,argv);
  return;
}



// WARNING: Could not reconcile some variable overlaps

void setAddress(int argc,char **argv)

{
  bool bVar1;
  uint32_t uVar2;
  uint8_t code;
  char *formatString;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint8_t auStack35 [3];
  uint8_t address [8];
  
  address._0_4_ = argc;
  address._4_4_ = argv;
  uVar2 = ciGetUnsigned(argv[1]);
  uVar5 = uVar2 & 0xff;
  uVar2 = ciGetUnsigned(argv[2]);
  if ((uVar5 < 3) && (uVar3 = uVar2 & 0xff, uVar3 < 5)) {
    if (argc < 0xc) {
      address._0_4_ = 0;
      address._4_4_ = (char **)0x0;
      for (iVar4 = 3; iVar4 < argc; iVar4 = iVar4 + 1) {
        uVar2 = ciGetUnsigned(argv[iVar4]);
        auStack35[iVar4] = (uint8_t)uVar2;
      }
      bVar1 = RAIL_AddressFilterSetAddress
                        ((uint8_t)uVar5,(uint8_t)uVar3,address,(bool)addressEnabled[uVar5][uVar3]);
      if (bVar1 != false) {
        iVar4 = uVar3 + uVar5 * 4;
        *(int *)addresses[iVar4] = address._0_4_;
        *(char ***)(addresses[iVar4] + 4) = address._4_4_;
        printAddresses(1,argv);
        return;
      }
      formatString = "Could not configure address!";
      code = '3';
    }
    else {
      formatString = "Too many address bytes given!";
      code = '2';
    }
  }
  else {
    formatString = "Address field or index out of range!";
    code = '1';
  }
  responsePrintError(*argv,code,formatString);
  return;
}



void enableAddress(int argc,char **argv)

{
  char cVar1;
  uint32_t uVar2;
  char *command;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar2 = ciGetUnsigned(argv[1]);
  uVar4 = uVar2 & 0xff;
  uVar2 = ciGetUnsigned(argv[2]);
  uVar5 = uVar2 & 0xff;
  uVar2 = ciGetUnsigned(argv[3]);
  uVar6 = uVar2 & 0xff;
  if (uVar6 == 0) {
    cVar1 = RAIL_AddressFilterDisableAddress((uint8_t)uVar4,(uint8_t)uVar5);
  }
  else {
    cVar1 = RAIL_AddressFilterEnableAddress((uint8_t)uVar4,(uint8_t)uVar5);
  }
  command = *argv;
  if (cVar1 != '\0') {
    addressEnabled[uVar4][uVar5] = (_Bool)(uVar6 != 0);
    pcVar3 = "Disabled";
    if (uVar6 != 0) {
      pcVar3 = "Enabled";
    }
    responsePrint(command,"Field:%u,Index:%u,Offset:%u,Size:%u,Address:%s,Status:%s",uVar4,uVar5,
                  (uint)offsets[uVar4],(uint)sizes[uVar4],addressPrintBuffer,pcVar3);
    return;
  }
  responsePrintError(command,'4',"Could not enable/disable address!");
  return;
}



void autoAckConfig(int argc,char **argv)

{
  _Bool _Var1;
  RAIL_Status_t code;
  int iVar2;
  uint32_t uVar3;
  char *pcVar4;
  
  _Var1 = inRadioState(RAIL_RF_STATE_IDLE,*argv);
  if (_Var1 == false) {
    return;
  }
  pcVar4 = argv[1];
  iVar2 = memcmp(pcVar4,&DAT_00010987,4);
  if (iVar2 == 0) {
    config.defaultState = RAIL_RF_STATE_IDLE;
  }
  else {
    iVar2 = memcmp(pcVar4,&DAT_0001098c,2);
    if (iVar2 != 0) {
      pcVar4 = "Unknown auto ack default state.";
      code = 0x20;
      goto LAB_00000804;
    }
    config.defaultState = RAIL_RF_STATE_RX;
  }
  uVar3 = ciGetUnsigned(argv[2]);
  if ((uVar3 & 0xffff) < 0x32c9) {
    config.idleTiming = (uint16_t)(uVar3 & 0xffff);
    uVar3 = ciGetUnsigned(argv[3]);
    if ((uVar3 & 0xffff) < 0x32c9) {
      config.turnaroundTime = (uint16_t)(uVar3 & 0xffff);
      uVar3 = ciGetUnsigned(argv[4]);
      config.ackTimeout = (uint16_t)uVar3;
      code = RAIL_AutoAckConfig(&config);
      if (code == RAIL_STATUS_NO_ERROR) {
        responsePrint(*argv,"defaultState:%s,idleTiming:%d,turnaroundTime:%d,ackTimeout:%d",
                      rfStates[config.defaultState],(uint)config.idleTiming,
                      (uint)config.turnaroundTime,(uint)config.ackTimeout);
        return;
      }
      pcVar4 = "Call to RAIL_AutoAckConfig returned an error";
    }
    else {
      pcVar4 = "Invalid turnaround timing";
      code = 0x22;
    }
  }
  else {
    pcVar4 = "Invalid idle timing.";
    code = 0x21;
  }
LAB_00000804:
  responsePrintError(*argv,code,pcVar4);
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
  char **ppcVar7;
  
  ppcVar7 = argv;
  bVar1 = RAIL_AutoAckIsEnabled();
  bVar2 = RAIL_AutoAckRxIsPaused();
  bVar3 = RAIL_AutoAckTxIsPaused();
  pcVar6 = "Paused";
  pcVar5 = "Enabled";
  if (bVar3 == false) {
    pcVar4 = "Unpaused";
  }
  else {
    pcVar4 = "Paused";
  }
  if (bVar2 == false) {
    pcVar6 = "Unpaused";
  }
  if (bVar1 == false) {
    pcVar5 = "Disabled";
  }
  responsePrint(*argv,"AutoAck:%s,RxAutoAckStatus:%s,TxAutoAckStatus:%s",pcVar5,pcVar6,pcVar4,
                ppcVar7);
  return;
}



void autoAckDisable(int argc,char **argv)

{
  RAIL_Status_t code;
  
  code = RAIL_AutoAckDisable();
  if (code != RAIL_STATUS_NO_ERROR) {
    responsePrintError(*argv,code,"Error disabling AutoAck");
  }
  getAutoAck(1,argv);
  return;
}



void autoAckPause(int argc,char **argv)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar1 = ciGetUnsigned(argv[1]);
  uVar2 = ciGetUnsigned(argv[2]);
  if ((uVar1 & 0xff) == 0) {
    RAIL_AutoAckRxResume();
  }
  else {
    RAIL_AutoAckRxPause();
  }
  if ((uVar2 & 0xff) == 0) {
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
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  
  uVar1 = ciGetUnsigned(argv[1]);
  uVar5 = uVar1 & 0xff;
  uVar1 = ciGetUnsigned(argv[2]);
  uVar3 = uVar1 & 0xff;
  afterRxUseTxBufferForAck = (_Bool)(char)uVar3;
  afterRxCancelAck = (_Bool)(char)uVar5;
  if (uVar5 != 0) {
    afterRxCancelAck = true;
  }
  if (uVar3 != 0) {
    afterRxUseTxBufferForAck = true;
  }
  pcVar2 = "True";
  if (uVar3 == 0) {
    pcVar4 = "False";
  }
  else {
    pcVar4 = "True";
  }
  if (uVar5 == 0) {
    pcVar2 = "False";
  }
  responsePrint(*argv,"CancelAck:%s,UseTxBuffer:%s",pcVar2,pcVar4);
  return;
}



void bleStatus(int argc,char **argv)

{
  bool bVar1;
  char *pcVar2;
  
  bVar1 = RAIL_BLE_IsEnabled();
  pcVar2 = "Enabled";
  if (bVar1 == false) {
    pcVar2 = "Disabled";
  }
  responsePrint(*argv,"BLE:%s",pcVar2);
  return;
}



void bleEnable(int argc,char **argv)

{
  _Bool _Var1;
  uint32_t uVar2;
  
  uVar2 = ciGetUnsigned(argv[1]);
  _Var1 = inRadioState(RAIL_RF_STATE_IDLE,*argv);
  if (_Var1 != false) {
    if (uVar2 == 0) {
      RAIL_BLE_Deinit();
    }
    else {
      RAIL_BLE_Init();
    }
    bleStatus(1,argv);
    return;
  }
  return;
}



void bleSet1MbpsPhy(int argc,char **argv)

{
  _Bool _Var1;
  char cVar2;
  uint32_t uVar3;
  char *pcVar4;
  undefined4 in_r3;
  
  if (argc == 2) {
    uVar3 = ciGetUnsigned(argv[1]);
    if (uVar3 != 0) {
      uVar3 = 1;
    }
  }
  else {
    uVar3 = 0;
  }
  _Var1 = inRadioState(RAIL_RF_STATE_IDLE,*argv);
  if (_Var1 != false) {
    if (uVar3 == 0) {
      cVar2 = RAIL_BLE_SetPhy1Mbps();
    }
    else {
      cVar2 = RAIL_BLE_SetPhy1MbpsViterbi();
    }
    pcVar4 = "Success";
    if (cVar2 == '\0') {
      pcVar4 = "Fail";
    }
    responsePrint(*argv,"Status:%s",pcVar4,in_r3);
    return;
  }
  return;
}



void bleSet2MbpsPhy(int argc,char **argv)

{
  _Bool _Var1;
  char cVar2;
  uint32_t uVar3;
  char *pcVar4;
  undefined4 in_r3;
  
  if (argc == 2) {
    uVar3 = ciGetUnsigned(argv[1]);
    if (uVar3 != 0) {
      uVar3 = 1;
    }
  }
  else {
    uVar3 = 0;
  }
  _Var1 = inRadioState(RAIL_RF_STATE_IDLE,*argv);
  if (_Var1 != false) {
    if (uVar3 == 0) {
      cVar2 = RAIL_BLE_SetPhy2Mbps();
    }
    else {
      cVar2 = RAIL_BLE_SetPhy2MbpsViterbi();
    }
    pcVar4 = "Success";
    if (cVar2 == '\0') {
      pcVar4 = "Fail";
    }
    responsePrint(*argv,"Status:%s",pcVar4,in_r3);
    return;
  }
  return;
}



void bleSetChannelParams(int argc,char **argv)

{
  uint32_t uVar1;
  uint32_t crcInit;
  uint32_t uVar2;
  char *pcVar3;
  uint uVar4;
  
  if (argc < 2) {
    uVar4 = 0x25;
LAB_00000b04:
    crcInit = 0x555555;
    uVar1 = 0x8e89bed6;
  }
  else {
    uVar1 = ciGetUnsigned(argv[1]);
    uVar4 = uVar1 & 0xff;
    if (argc == 2) goto LAB_00000b04;
    uVar1 = ciGetUnsigned(argv[2]);
    if (argc == 3) {
      crcInit = 0x555555;
    }
    else {
      crcInit = ciGetUnsigned(argv[3]);
      if (argc != 4) {
        uVar2 = ciGetUnsigned(argv[4]);
        if (uVar2 != 0) {
          uVar2 = 1;
        }
        goto LAB_00000ad2;
      }
    }
  }
  uVar2 = 0;
LAB_00000ad2:
  RAIL_BLE_SetupChannelRadioParams(crcInit,uVar1,(uint8_t)uVar4,SUB41(uVar2,0));
  if (uVar2 == 0) {
    pcVar3 = "Enabled";
  }
  else {
    pcVar3 = "Disabled";
  }
  responsePrint(*argv,"LogicalChannel:%d,AccessAddress:0x%0.8X,CrcInit:0x%0.8X,Whitening:%s",uVar4,
                uVar1,crcInit,pcVar3);
  return;
}



void bleAdvertisingConfig(int argc,char **argv)

{
  uint32_t uVar1;
  undefined4 *puVar2;
  undefined4 in_r3;
  undefined4 *puVar3;
  uint uVar5;
  undefined4 *puVar4;
  
  uVar1 = ciGetUnsigned(argv[1]);
  uVar5 = uVar1 & 0xff;
  if (2 < uVar5 - 0x25) {
    responsePrintError(*argv,'0',"Invalid advertising channel",in_r3);
    return;
  }
  RAIL_BLE_SetupChannelRadioParams(0x555555,0x8e89bed6,(uint8_t)uVar5,false);
  if (uVar5 == 0x25) {
    uVar1 = 0;
  }
  else {
    if (uVar5 == 0x26) {
      uVar1 = 0xc;
    }
    else {
      uVar1 = 0x27;
    }
  }
  changeChannel(uVar1);
  responsePrint(*argv,"AdvertisingChannel:%d",uVar5);
  puVar2 = (undefined4 *)txData;
  puVar3 = (undefined4 *)blePacket;
  do {
    puVar4 = puVar3 + 1;
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar4;
  } while (puVar4 != (undefined4 *)"Success");
  transmitPayload.dataLength = 0x1c;
  printTxPacket(1,argv);
  return;
}



void setFrequency(int argc,char **argv)

{
  _Bool _Var1;
  RAIL_Status_t RVar2;
  uint32_t freq;
  uint32_t uVar3;
  
  freq = ciGetUnsigned(argv[1]);
  _Var1 = inRadioState(RAIL_RF_STATE_IDLE,*argv);
  if (_Var1 == false) {
    return;
  }
  uVar3 = RAIL_DebugModeGet();
  if ((int)(uVar3 << 0x1f) < 0) {
    RVar2 = RAIL_DebugFrequencyOverride(freq);
    if (RVar2 == RAIL_STATUS_NO_ERROR) {
      responsePrint(*argv,"New Frequency:%u",freq);
      return;
    }
    responsePrintError(*argv,'\x14',"%u Hz is out of range and cannot be set as the frequency",freq)
    ;
    return;
  }
  responsePrintError(*argv,'\x13',"Not currently in frequency override debug mode.");
  return;
}



char * lookupDebugModeString(uint32_t debugMode)

{
  char *pcVar1;
  
  if (debugMode != 0) {
    pcVar1 = "Frequency Override";
    if ((debugMode & 1) == 0) {
      pcVar1 = "NULL";
    }
    return pcVar1;
  }
  return "Disabled";
}



void setDebugMode(int argc,char **argv)

{
  RAIL_Status_t RVar1;
  uint32_t DebugMode;
  char *pcVar2;
  
  DebugMode = ciGetUnsigned(argv[1]);
  RVar1 = RAIL_DebugModeSet(DebugMode);
  if (RVar1 == RAIL_STATUS_NO_ERROR) {
    pcVar2 = lookupDebugModeString(DebugMode);
    responsePrint(*argv,"DebugMode:%s",pcVar2);
    return;
  }
  responsePrintError(*argv,'\x15',"%d is an invalid debug mode!",DebugMode);
  return;
}



void getMemWord(int argc,char **argv)

{
  undefined4 *puVar1;
  uint32_t uVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)ciGetUnsigned(argv[1]);
  if (argc < 3) {
    uVar2 = 1;
  }
  else {
    uVar2 = ciGetUnsigned(argv[2]);
  }
  if (((uint)puVar1 & 3) != 0) {
    responsePrintError(*argv,0xff,"Address 0x%.8X is not 32bit aligned",puVar1);
    return;
  }
  responsePrintHeader(*argv,"address:0x%.8x,value:0x%.8x");
  puVar3 = puVar1 + uVar2;
  for (; puVar1 != puVar3; puVar1 = puVar1 + 1) {
    responsePrintMulti("address:0x%.8x,value:0x%.8x",puVar1,*puVar1);
  }
  return;
}



// WARNING: Could not reconcile some variable overlaps

void setMemWord(int argc,char **argv)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint uVar3;
  char **ppcVar4;
  int iVar5;
  char lengthStr [10];
  
  iVar5 = argc;
  lengthStr._0_4_ = argv;
  uVar1 = ciGetUnsigned(argv[1]);
  uVar3 = uVar1 & 3;
  if (uVar3 == 0) {
    ppcVar4 = argv + 1;
    for (; (int)(uVar3 + 2) < argc; uVar3 = uVar3 + 1) {
      ppcVar4 = ppcVar4 + 1;
      uVar2 = ciGetUnsigned(*ppcVar4);
      *(uint32_t *)(uVar1 + uVar3 * 4) = uVar2;
    }
    siprintf(lengthStr,"%d",uVar3);
    argv[2] = lengthStr;
    getMemWord(3,argv);
  }
  else {
    responsePrintError(*argv,0xff,"Address 0x%.8X is not 32bit aligned",uVar1,iVar5);
  }
  return;
}



void setTxUnderflow(int argc,char **argv)

{
  uint32_t uVar1;
  
  uVar1 = ciGetUnsigned(argv[1]);
  if (uVar1 != 0) {
    uVar1 = 1;
  }
  enableAppMode(TX_UNDERFLOW,SUB41(uVar1,0),*argv);
  return;
}



void setRxOverflow(int argc,char **argv)

{
  uint32_t uVar1;
  
  uVar1 = ciGetUnsigned(argv[1]);
  if (uVar1 != 0) {
    uVar1 = 1;
  }
  enableAppMode(RX_OVERFLOW,SUB41(uVar1,0),*argv);
  return;
}



void setCalibrations(int argc,char **argv)

{
  uint32_t uVar1;
  char *pcVar2;
  
  uVar1 = ciGetUnsigned(argv[1]);
  skipCalibrations = (_Bool)(uVar1 == 0);
  pcVar2 = "Enabled";
  if ((bool)skipCalibrations) {
    pcVar2 = "Disabled";
  }
  responsePrint(*argv,"Calibrations:%s",pcVar2);
  return;
}



void txCancel(int argc,char **argv)

{
  AppMode_t AVar1;
  int32_t iVar2;
  
  txCancelDelay = ciGetSigned(argv[1]);
  iVar2 = txCancelDelay;
  if (txCancelDelay != 0) {
    iVar2 = 1;
  }
  enableAppMode(TX_CANCEL,SUB41(iVar2,0),*argv);
  if ((0 < txCancelDelay) && (AVar1 = currentAppMode(), AVar1 == TX_CANCEL)) {
    txCount = 1;
    pendPacketTx();
    return;
  }
  return;
}



void getLogLevels(int argc,char **argv)

{
  responsePrint(*argv,"Peripherals:%s,Notifications:%s");
  return;
}



void setPeripheralEnable(int argc,char **argv)

{
  uint32_t uVar1;
  
  uVar1 = ciGetUnsigned(argv[1]);
  if (uVar1 == 0) {
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
  
  uVar1 = ciGetUnsigned(argv[1]);
  if (uVar1 == 0) {
    logLevel = logLevel & 0xfd;
  }
  else {
    logLevel = logLevel | 2;
  }
  getLogLevels(1,argv);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void resetChip(int argc,char **argv)

{
  serialWaitForTxIdle();
  DataSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



void printDataRates(int argc,char **argv)

{
  uint32_t uVar1;
  uint32_t uVar2;
  char *command;
  
  command = *argv;
  uVar1 = RAIL_SymbolRateGet();
  uVar2 = RAIL_BitRateGet();
  responsePrint(command,"Symbolrate:%d,Bitrate:%d",uVar1,uVar2);
  return;
}



void getRandom(int argc,char **argv)

{
  uint16_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  char *formatString;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  
  uVar2 = ciGetUnsigned(argv[1]);
  uVar5 = uVar2 & 0xffff;
  if (argc < 3) {
    uVar3 = 0;
  }
  else {
    uVar3 = ciGetUnsigned(argv[2]);
    if (uVar3 != 0) {
      uVar3 = 1;
    }
  }
  if (0x400 < uVar5) {
    responsePrintError(*argv,'\x10',"Cannot collect more than %d random bytes.",0x400);
    return;
  }
  uVar1 = RAIL_GetRadioEntropy(randomDataBuffer,(uint16_t)uVar5);
  if (uVar5 != uVar1) {
    responsePrintError(*argv,'\x11',"Error collecting random data.");
  }
  uVar5 = uVar3;
  if (uVar3 == 0) {
    for (; (int)uVar3 < (int)(uVar2 & 0xffff); uVar3 = uVar3 + 1) {
      uVar6 = uVar5 + 2 & 0xffff;
      sniprintf(randomPrintBuffer + uVar5,0x192 - uVar5,"%.2x",(uint)randomDataBuffer[uVar3]);
      if (uVar6 == 0x192) break;
      uVar5 = uVar6;
    }
    pcVar4 = randomPrintBuffer;
    formatString = "Length:%u,Data:%s";
  }
  else {
    formatString = "Length:%u,DataPtr:0x%.8x";
    pcVar4 = (char *)randomDataBuffer;
  }
  responsePrint(*argv,formatString,(uint)uVar1,pcVar4);
  return;
}



void setDebugSignal(int argc,char **argv)

{
  _Bool _Var1;
  debugSignal_t *pdVar2;
  debugPin_t *pdVar3;
  uint32_t uVar4;
  int iVar5;
  debugSignal_t *pdVar6;
  uint8_t uVar7;
  char *formatString;
  debugPin_t *pdVar8;
  debugPin_t *pdVar9;
  char *pcVar10;
  uint32_t numSignals;
  uint32_t numPins;
  debugSignal_t customSignal;
  
  pdVar2 = halGetDebugSignals(&numSignals);
  pdVar3 = halGetDebugPins(&numPins);
  pcVar10 = argv[1];
  uVar4 = strcasecmp(pcVar10,"help");
  if (uVar4 == 0) {
    iprintf("%s [pin] [signal] [options]\n",*argv);
    iprintf("Pins: ");
    for (; numPins != uVar4; uVar4 = uVar4 + 1) {
      if (uVar4 != 0) {
        iprintf(", ");
      }
      iprintf("%s",pdVar3[uVar4].name);
    }
    puts("\nSignals: ");
    puts("  OFF\n  CUSTOM_PRS <source> <signal>\n  CUSTOM_LIB <event>");
    for (uVar4 = 0; numSignals != uVar4; uVar4 = uVar4 + 1) {
      iprintf("  %s\n",pdVar2[uVar4].name);
    }
    return;
  }
  uVar4 = 0;
  pdVar9 = (debugPin_t *)0x0;
  while (numPins != uVar4) {
    pdVar8 = pdVar3 + uVar4;
    iVar5 = strcasecmp(pdVar3[uVar4].name,pcVar10);
    uVar4 = uVar4 + 1;
    if (iVar5 == 0) {
      pdVar9 = pdVar8;
    }
  }
  if (pdVar9 == (debugPin_t *)0x0) {
    formatString = "%s is not a valid pin name";
    uVar7 = 'P';
LAB_00000fcc:
    responsePrintError(*argv,uVar7,formatString,pcVar10);
    return;
  }
  pcVar10 = argv[2];
  iVar5 = strcasecmp("CUSTOM_LIB",pcVar10);
  if (iVar5 == 0) {
    if ((argc != 4) || (_Var1 = ciValidateInteger(argv[3],'w'), _Var1 == false)) {
      pcVar10 = "Invalid parameters passed to CUSTOM_LIB";
      uVar7 = 'Q';
      goto LAB_00001066;
    }
    customSignal.name = "CUSTOM_LIB";
    customSignal.isPrs = false;
    uVar4 = ciGetUnsigned(argv[3]);
    customSignal.loc = (undefined2)uVar4;
LAB_0000108a:
    pdVar6 = &customSignal;
LAB_0000108c:
    CMU_ClockEnable(cmuClock_GPIO,true);
    GPIO_PinModeSet(pdVar9->gpioPort,(uint)pdVar9->gpioPin,gpioModeDisabled,0);
    if (iVar5 != 0) {
      halDisablePrs(pdVar9->prsChannel);
      responsePrint(*argv,"Pin:%s,Signal:OFF",pdVar9->name);
      return;
    }
    if (pdVar6->isPrs != false) {
      halEnablePrs(pdVar9->prsChannel,pdVar9->prsLocation,*(uint8_t *)((int)&pdVar6->loc + 1),
                   *(uint8_t *)&pdVar6->loc);
    }
    GPIO_PinModeSet(pdVar9->gpioPort,(uint)pdVar9->gpioPin,gpioModePushPull,0);
    responsePrint(*argv,"Pin:%s,Signal:%s",pdVar9->name,pdVar6->name);
    return;
  }
  iVar5 = strcasecmp("CUSTOM_PRS",pcVar10);
  if (iVar5 != 0) {
    pdVar6 = (debugSignal_t *)strcasecmp("OFF",pcVar10);
    if (pdVar6 == (debugSignal_t *)0x0) {
      iVar5 = 1;
    }
    else {
      pdVar6 = (debugSignal_t *)0x0;
      for (uVar4 = 0; numSignals != uVar4; uVar4 = uVar4 + 1) {
        iVar5 = strcasecmp(pdVar2[uVar4].name,pcVar10);
        if (iVar5 == 0) {
          pdVar6 = pdVar2 + uVar4;
        }
      }
      if (pdVar6 == (debugSignal_t *)0x0) {
        formatString = "%s is not a valid signal name";
        uVar7 = 'T';
        goto LAB_00000fcc;
      }
      iVar5 = 0;
    }
    goto LAB_0000108c;
  }
  if (argc == 5) {
    _Var1 = ciValidateInteger(argv[3],'u');
    if ((_Var1 != false) && (_Var1 = ciValidateInteger(argv[4],'u'), _Var1 != false)) {
      customSignal.isPrs = true;
      customSignal.name = "CUSTOM_PRS";
      uVar4 = ciGetUnsigned(argv[3]);
      customSignal.loc._1_1_ = (undefined)uVar4;
      uVar4 = ciGetUnsigned(argv[4]);
      customSignal.loc = CONCAT11(customSignal.loc._1_1_,(char)uVar4);
      goto LAB_0000108a;
    }
  }
  pcVar10 = "Invalid parameters passed to CUSTOM_PRS";
  uVar7 = 'S';
LAB_00001066:
  responsePrintError(*argv,uVar7,pcVar10);
  return;
}



void startPerMode(int argc,char **argv)

{
  _Bool _Var1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  
  uVar2 = ciGetUnsigned(argv[1]);
  uVar3 = ciGetUnsigned(argv[2]);
  uVar4 = uVar2;
  if (uVar2 != 0) {
    uVar4 = 1;
  }
  _Var1 = enableAppModeSync(PER,SUB41(uVar4,0),*argv);
  if (_Var1 != false) {
    resetCounters(argc,argv);
    perDelay = uVar3 >> 1;
    perCount = uVar2;
    if (uVar2 != 0) {
      RAIL_TimerSet(perDelay,1);
      return;
    }
  }
  return;
}



void updateStats(int32_t newValue,Stats_t *stats)

{
  int iVar1;
  uint uVar2;
  undefined4 in_cr6;
  undefined4 in_cr7;
  
  uVar2 = stats->samples + 1;
  stats->samples = uVar2;
  if (uVar2 == 1) {
    stats->min = newValue;
    stats->max = newValue;
    stats->mean = (float)(longlong)newValue;
    stats->varianceTimesSamples = 0.0;
    return;
  }
  iVar1 = stats->min;
  if (iVar1 <= newValue) {
    stats->min = iVar1;
  }
  if (newValue < iVar1) {
    stats->min = newValue;
  }
  iVar1 = stats->max;
  if (newValue <= iVar1) {
    stats->max = iVar1;
  }
  if (iVar1 < newValue) {
    stats->max = newValue;
  }
  stats->mean = ((float)(longlong)newValue - stats->mean) / (float)(ulonglong)uVar2 + stats->mean;
  coprocessor_function(10,0xe,0,in_cr7,in_cr7,in_cr6);
  stats->varianceTimesSamples = stats->varianceTimesSamples;
  return;
}



void getPerStats(int argc,char **argv)

{
  __aeabi_f2d((counters.rssi.varianceTimesSamples / (float)(ulonglong)(counters.rssi.samples - 1)) *
              0.0625);
  __aeabi_f2d((float)(longlong)counters.rssi.max * 0.25);
  __aeabi_f2d((float)(longlong)counters.rssi.min * 0.25);
  __aeabi_f2d(counters.rssi.mean * 0.25);
  responsePrint(*argv,"PerTriggers:%u,RssiMean:%f,RssiMin:%.2f,RssiMax:%.2f,RssiVariance:%f",
                counters.perTriggers);
  return;
}



void berConfigSet(int argc,char **argv)

{
  RAIL_BerConfig_t berConfig;
  
  berConfig = (uint32_t)argv;
  berConfig = ciGetUnsigned(argv[1]);
  RAIL_BerConfigSet(&berConfig);
  return;
}



void berRx(int argc,char **argv)

{
  _Bool _Var1;
  uint32_t uVar2;
  uint32_t uVar3;
  
  uVar2 = ciGetUnsigned(argv[1]);
  uVar3 = uVar2;
  if (uVar2 != 0) {
    uVar3 = 1;
  }
  _Var1 = enableAppModeSync(BER,SUB41(uVar3,0),*argv);
  if (_Var1 != false) {
    resetCounters(argc,argv);
    if (uVar2 != 0) {
      RAIL_BerRxStart();
      return;
    }
    RAIL_BerRxStop();
    return;
  }
  return;
}



void berStatusGet(int argc,char **argv)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  RAIL_BerStatus_t berStats;
  
  RAIL_BerStatusGet(&berStats);
  if (berStats.bitsTotal == 0) {
    uVar1 = 0;
  }
  else {
    uVar4 = __floatunsidf(berStats.bitsTested);
    uVar5 = __floatunsidf(berStats.bitsTotal);
    uVar4 = __divdf3((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),(int)uVar5,
                     (int)((ulonglong)uVar5 >> 0x20));
    __muldf3((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,0x40590000);
    uVar1 = __truncdfsf2();
  }
  if (berStats.bitsTested == 0) {
    uVar2 = 0;
  }
  else {
    uVar4 = __floatunsidf(berStats.bitErrors);
    uVar5 = __floatunsidf(berStats.bitsTested);
    uVar4 = __divdf3((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),(int)uVar5,
                     (int)((ulonglong)uVar5 >> 0x20));
    __muldf3((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,0x40590000);
    uVar2 = __truncdfsf2();
  }
  uVar4 = __aeabi_f2d(uVar2);
  iVar3 = (int)berStats.rssi;
  uVar5 = __aeabi_f2d(uVar1);
  responsePrint(*argv,
                "BitsToTest:%u,BitsTested:%u,PercentDone:%0.2f,RSSI:%d,BitErrors:%u,PercentBitError:%0.2f"
                ,berStats.bitsTotal,berStats.bitsTested,(int)uVar5,(int)((ulonglong)uVar5 >> 0x20),
                iVar3,berStats.bitErrors,(int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
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



void getVersion(int argc,char **argv)

{
  RAIL_Version_t rail_ver;
  
  RAIL_VersionGet(&rail_ver,false);
  responsePrint(*argv,"App:%d.%d.%d,RAIL:%d.%d.%d",(uint)rail_ver.major,(uint)rail_ver.minor,
                (uint)rail_ver.rev,(uint)rail_ver.major,(uint)rail_ver.minor,(uint)rail_ver.rev);
  return;
}



void setPtiProtocol(int argc,char **argv)

{
  RAIL_Status_t RVar1;
  uint32_t uVar2;
  char *pcVar3;
  
  uVar2 = ciGetUnsigned(argv[1]);
  RVar1 = RAIL_SetPtiProtocol((RAIL_PtiProtocol_t)uVar2);
  pcVar3 = "Error";
  if (RVar1 == RAIL_STATUS_NO_ERROR) {
    pcVar3 = "Set";
  }
  responsePrint(*argv,"Pti:%s",pcVar3);
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
  uint32_t averageTimeUs;
  undefined4 uVar2;
  undefined8 uVar3;
  
  if (argc == 2) {
    averageTimeUs = ciGetUnsigned(argv[1]);
  }
  else {
    averageTimeUs = 0;
  }
  iVar1 = RAIL_PollAverageRSSI(averageTimeUs);
  if (iVar1 == -0x200) {
    responsePrintError(*argv,'\b',"Could not read RSSI. Ensure Rx is enabled");
    return;
  }
  uVar2 = FixedToFP((int)iVar1,0x20,0x20,2,0,0);
  uVar3 = __aeabi_f2d(uVar2);
  responsePrint(*argv,"rssi:%.2f",(int)uVar3,(int)((ulonglong)uVar3 >> 0x20));
  return;
}



void startAvgRssi(int argc,char **argv)

{
  _Bool _Var1;
  RAIL_Status_t RVar2;
  uint32_t averagingTimeUs;
  char *formatString;
  undefined4 in_r3;
  
  averagingTimeUs = ciGetUnsigned(argv[1]);
  _Var1 = inRadioState(RAIL_RF_STATE_IDLE,(char *)0x0);
  if (_Var1 == false) {
    formatString = "Could not read RSSI. Ensure RX is disabled.";
  }
  else {
    RVar2 = RAIL_StartAverageRSSI(channel,averagingTimeUs);
    if (RVar2 == RAIL_STATUS_NO_ERROR) {
      return;
    }
    formatString = "Could not read RSSI.";
  }
  responsePrintError(*argv,'\b',formatString,in_r3);
  return;
}



void getAvgRssi(int argc,char **argv)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  iVar1 = RAIL_GetAverageRSSI();
  if (iVar1 == -0x200) {
    responsePrintError(*argv,'\b',"Invalid RSSI. Make sure startAvgRssi ran successfully.");
    return;
  }
  uVar2 = FixedToFP(iVar1,0x20,0x20,2,0,0);
  uVar3 = __aeabi_f2d(uVar2);
  responsePrint(*argv,"rssi:%.2f",(int)uVar3,(int)((ulonglong)uVar3 >> 0x20));
  return;
}



void sweepPower(int argc,char **argv)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  
  uVar1 = ciGetUnsigned(argv[1]);
  uVar2 = ciGetUnsigned(argv[2]);
  uVar3 = ciGetUnsigned(argv[3]);
  uVar4 = RAIL_GetTime();
  while (uVar5 = RAIL_GetTime(), uVar5 < uVar4 + 5000000) {
    RAIL_TxToneStop();
    RAIL_RfIdle();
    RAIL_TxPowerSet(uVar1);
    RAIL_TxToneStart(channel);
    usDelay(uVar3 / 2);
    RAIL_TxToneStop();
    RAIL_RfIdle();
    RAIL_TxPowerSet(uVar2);
    RAIL_TxToneStart(channel);
    usDelay(uVar3 / 2);
  }
  RAIL_TxToneStop();
  return;
}



void resetCounters(int argc,char **argv)

{
  memset(&counters,0,0x5c);
  getStatus(1,argv);
  return;
}



void getTime(int argc,char **argv)

{
  uint32_t uVar1;
  char *command;
  
  command = *argv;
  uVar1 = RAIL_GetTime();
  responsePrint(command,"Time:%u",uVar1);
  return;
}



void setTime(int argc,char **argv)

{
  RAIL_Status_t RVar1;
  uint32_t time;
  uint32_t uVar2;
  char *formatString;
  char *command;
  
  time = ciGetUnsigned(argv[1]);
  RVar1 = RAIL_SetTime(time);
  command = *argv;
  if (RVar1 == RAIL_STATUS_NO_ERROR) {
    uVar2 = RAIL_GetTime();
    formatString = "Status:Success,CurrentTime:%u";
  }
  else {
    uVar2 = RAIL_GetTime();
    formatString = "Status:Error,CurrentTime:%u";
  }
  responsePrint(command,formatString,uVar2);
  return;
}



void setLbtMode(int argc,char **argv)

{
  code *pcVar1;
  RAIL_PreTxOp_t *pRVar2;
  RAIL_PreTxOp_t *pRVar3;
  int iVar4;
  undefined4 in_r3;
  char *pcVar5;
  
  pRVar3 = txPreTxOp;
  pRVar2 = (RAIL_PreTxOp_t *)txPreTxOpArgs;
  if (1 < argc) {
    pcVar5 = argv[1];
    pRVar3 = (RAIL_PreTxOp_t *)memcmp(pcVar5,"off",3);
    pRVar2 = pRVar3;
    if (pRVar3 != FUN_00000000) {
      iVar4 = memcmp(pcVar5,&DAT_0001138c,4);
      if (iVar4 == 0) {
        pcVar1 = RAIL_CcaCsma;
      }
      else {
        iVar4 = memcmp(pcVar5,"lbt",3);
        if (iVar4 != 0) {
          responsePrintError(*argv,'p',"Unknown LBT mode specified.",in_r3);
          return;
        }
        pcVar1 = RAIL_CcaLbt;
      }
      txPreTxOpArgs = &lbtParams;
      pRVar3 = pcVar1 + 1;
      pRVar2 = (RAIL_PreTxOp_t *)txPreTxOpArgs;
    }
  }
  txPreTxOpArgs = pRVar2;
  txPreTxOp = pRVar3;
  if (txPreTxOp == FUN_00000000) {
    pcVar5 = "LbtMode:off";
  }
  else {
    if (txPreTxOp == RAIL_CcaCsma + 1) {
      pcVar5 = "LbtMode:CSMA";
    }
    else {
      if (txPreTxOp != RAIL_CcaLbt + 1) {
        return;
      }
      pcVar5 = "LbtMode:LBT";
    }
  }
  responsePrint(*argv,pcVar5);
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
  undefined4 in_r3;
  int iVar3;
  int iVar4;
  
  uVar1 = ciGetUnsigned(argv[1]);
  iVar4 = 2;
  while( true ) {
    if (argc <= iVar4) {
      transmitPayload.dataPtr = txData;
      RAIL_TxDataLoad();
      printTxPacket(1,argv);
      return;
    }
    uVar2 = ciGetUnsigned(argv[iVar4]);
    if (0xef < ((uVar1 & 0xffff) - 2) + iVar4) break;
    iVar3 = (uVar1 & 0xffff) + iVar4;
    iVar4 = iVar4 + 1;
    *(char *)((int)&txCancelDelay + iVar3 + 2) = (char)uVar2;
  }
  responsePrintError(*argv,'\x05',"Data overflows txData buffer",in_r3);
  return;
}



void setTxLength(int argc,char **argv)

{
  uint32_t uVar1;
  
  uVar1 = ciGetUnsigned(argv[1]);
  if (0xf0 < uVar1) {
    responsePrintError(*argv,'\x06',"Invalid length %d");
    return;
  }
  transmitPayload.dataLength = (uint16_t)uVar1;
  transmitPayload.dataPtr = txData;
  RAIL_TxDataLoad(&transmitPayload);
  responsePrint(*argv,"TxLength:%d",(uint)transmitPayload.dataLength);
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
  undefined4 in_r3;
  int iVar3;
  int iVar4;
  
  uVar1 = ciGetUnsigned(argv[1]);
  iVar4 = 2;
  while( true ) {
    if (argc <= iVar4) {
      ackPayload.dataPtr = ackData;
      RAIL_AutoAckLoadBuffer(&ackPayload);
      printAckPacket(1,argv);
      return;
    }
    uVar2 = ciGetUnsigned(argv[iVar4]);
    if (0x3f < ((uVar1 & 0xffff) - 2) + iVar4) break;
    iVar3 = (uVar1 & 0xffff) + iVar4;
    iVar4 = iVar4 + 1;
    *(char *)((int)&lbtParams.lbtTimeout + iVar3 + 3) = (char)uVar2;
  }
  responsePrintError(*argv,'\x05',"Data overflows ackData buffer",in_r3);
  return;
}



void setAckLength(int argc,char **argv)

{
  uint32_t uVar1;
  
  uVar1 = ciGetUnsigned(argv[1]);
  if (0x40 < uVar1) {
    responsePrintError(*argv,'\x06',"Invalid length %d",uVar1);
    return;
  }
  ackPayload.dataLength = (uint8_t)uVar1;
  ackPayload.dataPtr = ackData;
  RAIL_AutoAckLoadBuffer(&ackPayload);
  responsePrint(*argv,"TxLength:%d",(uint)ackPayload.dataLength);
  return;
}



int8_t stringsToStates(char **strings,RAIL_RadioState_t *states)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    bVar1 = *strings[iVar2];
    if (bVar1 == 0x54) {
LAB_00001a54:
      states[iVar2] = RAIL_RF_STATE_TX;
    }
    else {
      if (bVar1 < 0x55) {
        if (bVar1 == 0x49) {
LAB_00001a46:
          states[iVar2] = RAIL_RF_STATE_IDLE;
          goto LAB_00001a48;
        }
        if (bVar1 != 0x52) {
          return '\x01';
        }
      }
      else {
        if (bVar1 != 0x72) {
          if (bVar1 == 0x74) goto LAB_00001a54;
          if (bVar1 != 0x69) {
            return '\x01';
          }
          goto LAB_00001a46;
        }
      }
      states[iVar2] = RAIL_RF_STATE_RX;
    }
LAB_00001a48:
    if (iVar2 != 0) {
      return '\0';
    }
    iVar2 = 1;
  } while( true );
}



void getChannel(int argc,char **argv)

{
  uint32_t uVar1;
  
  uVar1 = RAIL_DebugModeGet();
  if ((int)(uVar1 << 0x1f) < 0) {
    responsePrintError(*argv,'\x12',"Channels are not valid in Debug Mode");
    return;
  }
  responsePrint(*argv,"channel:%d",(uint)channel);
  return;
}



void setChannel(int argc,char **argv)

{
  _Bool _Var1;
  bool bVar2;
  uint32_t i;
  
  _Var1 = inRadioState(RAIL_RF_STATE_IDLE,*argv);
  if (_Var1 == false) {
    return;
  }
  i = ciGetUnsigned(argv[1]);
  bVar2 = RAIL_ChannelExists((ushort)i & 0xff);
  if (bVar2 != false) {
    responsePrintError(*argv,'\x11',"Invalid channel \'%d\'",i);
    return;
  }
  changeChannel(i);
  getChannel(1,argv);
  return;
}



void getPower(int argc,char **argv)

{
  undefined4 uVar1;
  char *command;
  
  command = *argv;
  uVar1 = RAIL_TxPowerGet();
  responsePrint(command,"power:%d",uVar1);
  return;
}



void setPower(int argc,char **argv)

{
  _Bool _Var1;
  undefined4 uVar2;
  
  _Var1 = inRadioState(RAIL_RF_STATE_IDLE,*argv);
  if (_Var1 != false) {
    ciGetSigned(argv[1]);
    uVar2 = RAIL_TxPowerSet();
    responsePrint(*argv,"power:%d",uVar2);
    return;
  }
  return;
}



void getTxDelay(int argc,char **argv)

{
  responsePrint(*argv,"txDelay:%d",continuousTransferPeriod);
  return;
}



void setTxDelay(int argc,char **argv)

{
  continuousTransferPeriod = ciGetUnsigned(argv[1]);
  getTxDelay(1,argv);
  return;
}



void getCtune(int argc,char **argv)

{
  uint32_t uVar1;
  
  uVar1 = RAIL_GetTune();
  responsePrint(*argv,"CTUNE:0x%.3x",uVar1);
  return;
}



void setCtune(int argc,char **argv)

{
  _Bool _Var1;
  uint32_t tune;
  
  _Var1 = inRadioState(RAIL_RF_STATE_IDLE,*argv);
  if (_Var1 != false) {
    tune = ciGetUnsigned(argv[1]);
    RAIL_SetTune(tune);
    getCtune(1,argv);
    return;
  }
  return;
}



void setPaCtune(int argc,char **argv)

{
  RAIL_Status_t code;
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar1 = ciGetUnsigned(argv[1]);
  uVar2 = ciGetUnsigned(argv[2]);
  code = RAIL_PaCtuneSet((uint8_t)(uVar1 & 0xff),(uint8_t)(uVar2 & 0xff));
  if (code == RAIL_STATUS_NO_ERROR) {
    responsePrint(*argv,"PACTUNETX:%d,PACTUNERX:%d",uVar1 & 0xff,uVar2 & 0xff);
    return;
  }
  responsePrintError(*argv,code,"Error");
  return;
}



void getConfig(int argc,char **argv)

{
  responsePrint(*argv,"Index:%u,Config:%s",currentConfig,configNames[currentConfig]);
  return;
}



void listConfigs(int argc,char **argv)

{
  responsePrintHeader(*argv,"Index:%u,Config:%s");
  responsePrintMulti("Index:%u,Config:%s",0,configNames);
  return;
}



void setConfig(int argc,char **argv)

{
  _Bool _Var1;
  uint32_t newConfig;
  
  _Var1 = inRadioState(RAIL_RF_STATE_IDLE,*argv);
  if (_Var1 == false) {
    return;
  }
  newConfig = ciGetUnsigned(argv[1]);
  if ((int)newConfig < 1) {
    changeRadioConfig(newConfig);
    getConfig(1,argv);
    getChannel(1,argv);
    return;
  }
  responsePrintError(*argv,'\b',"Invalid index %u");
  return;
}



// WARNING: Could not reconcile some variable overlaps

void setTxTransitions(int argc,char **argv)

{
  int8_t iVar1;
  RAIL_Status_t RVar2;
  char *pcVar3;
  RAIL_RadioState_t states [2];
  
  _states = argv;
  iVar1 = stringsToStates(argv + 1,states);
  if (iVar1 == '\0') {
    RVar2 = RAIL_SetTxTransitions(states[0],states[1]);
    pcVar3 = "Error";
    if (RVar2 == RAIL_STATUS_NO_ERROR) {
      pcVar3 = "Set";
    }
    responsePrint(*argv,"TxTransitions:%s",pcVar3,"Set",argc);
  }
  else {
    responsePrintError(*argv,'\x16',"Invalid states");
  }
  return;
}



// WARNING: Could not reconcile some variable overlaps

void setRxTransitions(int argc,char **argv)

{
  int8_t iVar1;
  RAIL_Status_t RVar2;
  uint32_t uVar3;
  char *pcVar4;
  RAIL_RadioState_t states [2];
  
  _states = argv;
  iVar1 = stringsToStates(argv + 1,states);
  if (iVar1 == '\0') {
    uVar3 = ciGetUnsigned(argv[3]);
    RVar2 = RAIL_SetRxTransitions(states[0],states[1],(uint8_t)uVar3);
    pcVar4 = "Error";
    if (RVar2 == RAIL_STATUS_NO_ERROR) {
      pcVar4 = "Set";
    }
    responsePrint(*argv,"RxTransitions:%s",pcVar4,"Set",argc);
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
  int iVar3;
  char **ppcVar4;
  uint16_t timing [4];
  RAIL_StateTiming_t timings;
  
  iVar3 = 0;
  ppcVar4 = argv;
  do {
    ppcVar4 = ppcVar4 + 1;
    uVar2 = ciGetUnsigned(*ppcVar4);
    timing[iVar3] = (uint16_t)uVar2;
    iVar3 = iVar3 + 1;
  } while (iVar3 != 4);
  timings.idleToRx = timing[0];
  timings.txToRx = timing[1];
  timings.idleToTx = timing[2];
  timings.rxToTx = timing[3];
  RVar1 = RAIL_SetStateTiming(&timings);
  if (RVar1 == RAIL_STATUS_NO_ERROR) {
    responsePrint(*argv,"IdleToRx:%u,RxToTx:%u,IdleToTx:%u,TxToRx:%u",(uint)timings.idleToRx,
                  (uint)timings.rxToTx,(uint)timings.idleToTx,(uint)timings.txToRx);
  }
  else {
    responsePrintError(*argv,'\x18',"Setting timings failed");
  }
  return;
}



void printTimerStats(int argc,char **argv)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint32_t uVar4;
  char *pcVar5;
  char *pcVar6;
  
  iVar1 = RAIL_TimerIsRunning();
  iVar2 = RAIL_TimerExpired();
  uVar3 = RAIL_TimerGet();
  uVar4 = RAIL_GetTime();
  pcVar5 = "True";
  if (iVar1 == 0) {
    pcVar6 = "False";
  }
  else {
    pcVar6 = "True";
  }
  if (iVar2 == 0) {
    pcVar5 = "False";
  }
  responsePrint(*argv,"timeUs:%u,ExpirationTime:%u,IsRunning:%s,IsExpired:%s",uVar4,uVar3,pcVar6,
                pcVar5);
  return;
}



void setTimer(int argc,char **argv)

{
  _Bool _Var1;
  uint32_t uVar2;
  int iVar3;
  
  _Var1 = inAppMode(NONE,*argv);
  if (_Var1 == false) {
    return;
  }
  uVar2 = ciGetUnsigned(argv[1]);
  iVar3 = strcmp(argv[2],"abs");
  RAIL_TimerCancel();
  if (iVar3 != 0) {
    iVar3 = 1;
  }
  iVar3 = RAIL_TimerSet(uVar2,iVar3);
  if (iVar3 != 0) {
    responsePrintError(*argv,'@',"TimerSet failed");
    return;
  }
  printTimerStats(1,argv);
  return;
}



void timerCancel(int argc,char **argv)

{
  _Bool _Var1;
  
  _Var1 = inAppMode(NONE,*argv);
  if (_Var1 != false) {
    RAIL_TimerCancel();
    printTimerStats(1,argv);
    return;
  }
  return;
}



void tx(int argc,char **argv)

{
  uint32_t iterations;
  
  iterations = ciGetUnsigned(argv[1]);
  radioTransmit(iterations,*argv);
  txOptionsPtr = (RAIL_TxOptions_t *)0x0;
  return;
}



void txWithOptions(int argc,char **argv)

{
  uint32_t iterations;
  
  iterations = ciGetUnsigned(argv[1]);
  radioTransmit(iterations,*argv);
  txOptionsPtr = &txOptions;
  return;
}



void configTxOptions(int argc,char **argv)

{
  uint32_t uVar1;
  char *pcVar2;
  
  uVar1 = ciGetUnsigned(argv[1]);
  txOptions = (_Bool)((uVar1 & 0xff) != 0);
  txOptionsPtr = &txOptions;
  pcVar2 = "True";
  if (!(bool)txOptions) {
    pcVar2 = "False";
  }
  responsePrint(*argv,"waitForAck:%s",pcVar2);
  return;
}



void txAtTime(int argc,char **argv)

{
  uint32_t absTime;
  
  absTime = ciGetUnsigned(argv[1]);
  setNextPacketTime(absTime);
  setNextAppMode(TX_SCHEDULED,*argv);
  return;
}



void txAfterRx(int argc,char **argv)

{
  uint32_t uVar1;
  
  txAfterRxDelay = ciGetUnsigned(argv[1]);
  uVar1 = txAfterRxDelay;
  if (txAfterRxDelay != 0) {
    uVar1 = 1;
  }
  enableAppMode(SCHTX_AFTER_RX,SUB41(uVar1,0),*argv);
  return;
}



void rx(int argc,char **argv)

{
  AppMode_t AVar1;
  RAIL_RadioState_t RVar2;
  _Bool _Var3;
  uint32_t uVar4;
  uint32_t uVar5;
  char *pcVar6;
  char *pcVar7;
  char *command;
  
  uVar4 = ciGetUnsigned(argv[1]);
  AVar1 = currentAppMode();
  if ((AVar1 == RX_SCHEDULED) && (uVar4 != 0)) {
    responsePrintError(*argv,'\x1d',"Can\'t turn on receive when in ScheduledRx");
    return;
  }
  AVar1 = currentAppMode();
  if (((AVar1 != DIRECT) && (AVar1 = currentAppMode(), AVar1 != RX_SCHEDULED)) &&
     (_Var3 = inAppMode(NONE,*argv), _Var3 == false)) {
    return;
  }
  if (uVar4 == 0) {
    RVar2 = RAIL_RfStateGet();
    if (RVar2 != RAIL_RF_STATE_IDLE) {
      RAIL_RfIdle();
      receiveModeEnabled = false;
      AVar1 = currentAppMode();
      if (AVar1 == RX_SCHEDULED) {
        enableAppModeSync(RX_SCHEDULED,false,(char *)0x0);
        goto LAB_00001fa6;
      }
    }
    command = *argv;
    pcVar7 = "Disabled";
    pcVar6 = "Enabled";
  }
  else {
    RVar2 = RAIL_RfStateGet();
    if ((RVar2 == RAIL_RF_STATE_RX) ||
       (_Var3 = inRadioState(RAIL_RF_STATE_IDLE,*argv), _Var3 == false)) {
      command = *argv;
      pcVar7 = "Enabled";
      pcVar6 = "Disabled";
      goto LAB_00001fb6;
    }
    RAIL_RxStart(channel);
    receiveModeEnabled = true;
LAB_00001fa6:
    command = *argv;
    pcVar6 = "Disabled";
    if (uVar4 == 0) {
      pcVar7 = "Disabled";
      pcVar6 = "Enabled";
    }
    else {
      pcVar7 = "Enabled";
    }
  }
LAB_00001fb6:
  uVar5 = RAIL_GetTime();
  responsePrint(command,"Rx:%s,Idle:%s,Time:%u",pcVar7,pcVar6,uVar5);
  return;
}



void setTxTone(int argc,char **argv)

{
  uint32_t uVar1;
  undefined enable;
  
  uVar1 = ciGetUnsigned(argv[1]);
  enable = (undefined)(uVar1 & 0xff);
  if ((uVar1 & 0xff) != 0) {
    enable = true;
  }
  enableAppMode(TX_TONE,(_Bool)enable,*argv);
  return;
}



void setTxStream(int argc,char **argv)

{
  uint32_t uVar1;
  undefined enable;
  
  uVar1 = ciGetUnsigned(argv[1]);
  enable = (undefined)(uVar1 & 0xff);
  if ((uVar1 & 0xff) != 0) {
    enable = true;
  }
  enableAppMode(TX_STREAM,(_Bool)enable,*argv);
  return;
}



void setDirectMode(int argc,char **argv)

{
  uint32_t uVar1;
  undefined enable;
  
  uVar1 = ciGetUnsigned(argv[1]);
  enable = (undefined)(uVar1 & 0xff);
  if ((uVar1 & 0xff) != 0) {
    enable = true;
  }
  enableAppMode(DIRECT,(_Bool)enable,*argv);
  return;
}



void setDirectTx(int argc,char **argv)

{
  AppMode_t AVar1;
  uint8_t uVar2;
  uint32_t uVar3;
  char *pcVar4;
  undefined4 in_r3;
  
  uVar3 = ciGetUnsigned(argv[1]);
  AVar1 = currentAppMode();
  if (AVar1 == DIRECT) {
    RAIL_RfIdle();
    if ((uVar3 & 0xff) == 0) {
      while ((receiveModeEnabled != false && (uVar2 = RAIL_RxStart(channel), uVar2 != '\0'))) {
        RAIL_RfIdle();
      }
    }
    else {
      RAIL_TxStart(channel,0);
    }
    pcVar4 = "Enabled";
    if ((uVar3 & 0xff) == 0) {
      pcVar4 = "Disabled";
    }
    responsePrint(*argv,"DirectTx:%s",pcVar4,in_r3);
    return;
  }
  responsePrintError(*argv,'\a',"DirectMode not enabled",in_r3);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void sleep(int argc,char **argv)

{
  byte bVar1;
  uint uVar2;
  _Bool _Var3;
  bool bVar4;
  uint8_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  char *command;
  CORE_irqState_t CVar8;
  int iVar9;
  undefined *puVar10;
  undefined1 *puVar11;
  undefined *puVar12;
  uint uVar13;
  char *pcVar14;
  
  _Var3 = enableAppModeSync(RF_SENSE,true,*argv);
  if (_Var3 == false) {
    return;
  }
  uVar6 = ciGetUnsigned(argv[1]);
  uVar13 = uVar6 & 0x7f;
  if (4 < uVar13) {
    responsePrintError(*argv,'\x01',"Invalid EM mode %u (valid 0-4)",uVar13);
    return;
  }
  if (uVar13 == 4) {
    bVar1 = argv[1][1];
    if (bVar1 == 0x53) {
LAB_00002122:
      CVar8 = CORE_EnterCritical();
      uVar2 = read_volatile_4(EMU->.EM4CTRL);
      write_volatile_4(EMU->.EM4CTRL,uVar2 & 0xfffffffe);
      CORE_ExitCritical(CVar8);
      pcVar14 = "s";
    }
    else {
      if (bVar1 < 0x54) {
        if (bVar1 == 0x48) {
LAB_0000213c:
          CVar8 = CORE_EnterCritical();
          uVar2 = read_volatile_4(EMU->.EM4CTRL);
          write_volatile_4(EMU->.EM4CTRL,uVar2 | 1);
          CORE_ExitCritical(CVar8);
          pcVar14 = "h";
          goto LAB_00002134;
        }
      }
      else {
        if (bVar1 == 0x68) goto LAB_0000213c;
        if (bVar1 == 0x73) goto LAB_00002122;
      }
      uVar2 = read_volatile_4(EMU->.EM4CTRL);
      pcVar14 = "s";
      if ((uVar2 & 1) != 0) {
        pcVar14 = "h";
      }
    }
LAB_00002134:
    if (argc < 3) goto LAB_00002178;
LAB_0000215a:
    rfUs = ciGetUnsigned(argv[2]);
    if (argc != 3) {
      uVar7 = ciGetUnsigned(argv[3]);
      rfBand = (RAIL_RfSenseBand_t)uVar7;
    }
    if (1 < uVar13) goto LAB_00002178;
  }
  else {
    if (2 < argc) {
      pcVar14 = "";
      goto LAB_0000215a;
    }
    if (uVar13 < 2) {
      command = *argv;
      pcVar14 = "";
      puVar11 = &DAT_000116be;
      goto LAB_0000219a;
    }
    pcVar14 = "";
LAB_00002178:
    RAIL_RfIdle();
    PeripheralDisable();
    uVar2 = read_volatile_4(EMU->.EM4CTRL);
    write_volatile_4(EMU->.EM4CTRL,uVar2 & 0xffffffcf | 0x10);
  }
  puVar11 = &DAT_000116c1;
  command = *argv;
  if (uVar13 != 4) {
    puVar11 = &DAT_000116be;
  }
LAB_0000219a:
  responsePrint(command,"EM:%u%s,SerialWakeup:%s,RfSense:%s",uVar13,pcVar14,puVar11,
                rfBands[rfBand & 3]);
  serialWaitForTxIdle();
  CVar8 = CORE_EnterCritical();
  rfUs = RAIL_RfSense(rfBand,rfUs,(bool)((byte)~(byte)uVar6 >> 7));
  GPIO_ExtIntConfig(gpioPortA,1,1,false,true,true);
  serEvent = false;
  do {
    switch(uVar13) {
    case 1:
      _DAT_e000ed10 = _DAT_e000ed10 & 0xfffffffb;
      WaitForInterrupt();
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
    CORE_ExitCritical(CVar8);
    CVar8 = CORE_EnterCritical();
    bVar4 = RAIL_RfSensed();
  } while ((bVar4 == false) && (serEvent == false));
  CORE_ExitCritical(CVar8);
  enableAppMode(RF_SENSE,false,(char *)0x0);
  GPIO_ExtIntConfig(gpioPortA,1,1,false,true,false);
  puVar12 = &DAT_000116c9;
  if (serEvent == false) {
    puVar10 = &DAT_000116c9;
  }
  else {
    puVar10 = &DAT_000116c5;
  }
  if (bVar4 != false) {
    puVar12 = &DAT_000116c5;
  }
  responsePrint("sleepWoke","EM:%u%s,SerialWakeup:%s,RfSensed:%s,RfUs:%u",uVar13,pcVar14,puVar10,
                puVar12,rfUs);
  if (serEvent != false) {
    if (uVar13 < 2) {
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
  if ((1 < uVar13) && ((int)((uint)logLevel << 0x1f) < 0)) {
    PeripheralEnable();
    redrawDisplay = true;
  }
  return;
}



void rfSense(int argc,char **argv)

{
  _Bool _Var1;
  uint32_t uVar2;
  RAIL_RfSenseBand_t enable;
  
  if (1 < argc) {
    rfUs = ciGetUnsigned(argv[1]);
    if (argc != 2) {
      uVar2 = ciGetUnsigned(argv[2]);
      rfBand = (RAIL_RfSenseBand_t)uVar2;
    }
  }
  enable = rfBand;
  if (rfBand != RAIL_RFSENSE_OFF) {
    enable = true;
  }
  _Var1 = enableAppModeSync(RF_SENSE,(_Bool)enable,*argv);
  if (_Var1 != false) {
    rfUs = RAIL_RfSense(rfBand,rfUs,true);
    if (rfUs == 0) {
      rfBand = RAIL_RFSENSE_OFF;
    }
    responsePrint(*argv,"RfSense:%s,RfUs:%u",rfBands[rfBand & 3],rfUs);
    return;
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
    return;
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
      return true;
    }
    iVar1 = strcasecmp("abs",str);
    if (iVar1 != 0) {
      *mode = RAIL_TIME_DISABLED;
      return false;
    }
    *mode = RAIL_TIME_ABSOLUTE;
  }
  return true;
}



void rxAt(int argc,char **argv)

{
  _Bool _Var1;
  _Bool _Var2;
  byte bVar3;
  uint32_t uVar4;
  uint8_t code;
  char *formatString;
  RAIL_TimeMode_t startMode;
  RAIL_TimeMode_t endMode;
  RAIL_ScheduleRxConfig_t rxCfg;
  
  _Var1 = inAppMode(NONE,(char *)0x0);
  if (((_Var1 == false) && (_Var1 = inAppMode(RX_SCHEDULED,(char *)0x0), _Var1 == false)) ||
     ((_Var1 = inAppMode(NONE,(char *)0x0), _Var1 != false &&
      (_Var1 = inRadioState(RAIL_RF_STATE_IDLE,(char *)0x0), _Var1 == false)))) {
    formatString = "Cannot enter ScheduledRx when not in Idle.";
    code = '\x1e';
LAB_000024c4:
    responsePrintError(*argv,code,formatString);
    return;
  }
  rxCfg.start = ciGetUnsigned(argv[1]);
  rxCfg.end = ciGetUnsigned(argv[3]);
  _Var1 = parseTimeModeFromString(argv[2],&startMode);
  if (_Var1 == false) {
    formatString = "Invalid startMode specified";
    code = '\x19';
    goto LAB_000024c4;
  }
  _Var1 = parseTimeModeFromString(argv[4],&endMode);
  if (_Var1 == false) {
    formatString = "Invalid endMode specified";
    code = '\x1a';
    goto LAB_000024c4;
  }
  if (argc < 6) {
    rxCfg.rxTransitionEndSchedule = '\0';
  }
  else {
    uVar4 = ciGetUnsigned(argv[5]);
    if (uVar4 != 0) {
      uVar4 = 1;
    }
    rxCfg.rxTransitionEndSchedule = (uint8_t)uVar4;
    if (argc != 6) {
      uVar4 = ciGetUnsigned(argv[6]);
      if (uVar4 != 0) {
        uVar4 = 1;
      }
      goto LAB_00002510;
    }
  }
  uVar4 = 0;
LAB_00002510:
  rxCfg.startMode = startMode;
  rxCfg.endMode = endMode;
  rxCfg.hardWindowEnd = (uint8_t)uVar4;
  schRxStopOnRxEvent = (_Bool)rxCfg.rxTransitionEndSchedule;
  _Var1 = inAppMode(RX_SCHEDULED,(char *)0x0);
  if ((_Var1 == false) && (_Var2 = enableAppModeSync(RX_SCHEDULED,true,*argv), _Var2 == false)) {
    return;
  }
  bVar3 = RAIL_ScheduleRx(channel,&rxCfg);
  if (bVar3 == 0) {
    return;
  }
  responsePrintError(*argv,'\x1b',"Could not start scheduled receive %d",(uint)bVar3);
  if (_Var1 != false) {
    return;
  }
  enableAppModeSync(RX_SCHEDULED,false,*argv);
  return;
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



void gpio1ShortPress(void)

{
  _Bool _Var1;
  bool bVar2;
  uint8_t uVar3;
  
  _Var1 = inAppMode(NONE,(char *)0x0);
  if ((_Var1 != false) && (_Var1 = inRadioState(RAIL_RF_STATE_TX,(char *)0x0), _Var1 == false)) {
    _Var1 = inRadioState(RAIL_RF_STATE_RX,(char *)0x0);
    if (_Var1 != false) {
      RAIL_RfIdle();
    }
    bVar2 = RAIL_ChannelExists((ushort)(byte)(channel + 1));
    if (bVar2 == false) {
      channel = channel + '\x01';
    }
    else {
      channel = 0;
      while (bVar2 = RAIL_ChannelExists((ushort)channel), bVar2 != false) {
        channel = channel + 1;
      }
    }
    while ((receiveModeEnabled != false && (uVar3 = RAIL_RxStart(channel), uVar3 != '\0'))) {
      RAIL_RfIdle();
    }
    redrawDisplay = true;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void gpioCallback(uint8_t pin)

{
  uint32_t uVar1;
  uint32_t *puVar2;
  
  if (pin == '\x01') {
    serEvent = (_Bool)pin;
    return;
  }
  if (pin == '\x06') {
    puVar2 = &gpioCallback::gpio0TimeCapture;
    if (_DAT_42142198 != 0) {
      uVar1 = halCommonGetInt32uMillisecondTick();
      if (1000 < uVar1 - gpioCallback::gpio0TimeCapture) {
        gpio0LongPress();
        return;
      }
      gpio0ShortPress();
      return;
    }
  }
  else {
    if (pin != '\a') {
      return;
    }
    puVar2 = &gpioCallback::gpio1TimeCapture;
    if (_DAT_4214219c != 0) {
      uVar1 = halCommonGetInt32uMillisecondTick();
      if (1000 < uVar1 - gpioCallback::gpio1TimeCapture) {
        return;
      }
      gpio1ShortPress();
      return;
    }
  }
  uVar1 = halCommonGetInt32uMillisecondTick();
  *puVar2 = uVar1;
  return;
}



void appHalInit(void)

{
  halInit();
  CMU_ClockEnable(cmuClock_GPIO,true);
  BSP_Init(4);
  BSP_LedsInit();
  GRAPHICS_Init();
  RETARGET_SerialInit();
  RETARGET_SerialCrLf(1);
  GPIO_PinModeSet(gpioPortF,6,gpioModeInputPull,1);
  GPIO_PinModeSet(gpioPortF,7,gpioModeInputPull,1);
  GPIO_PinModeSet(gpioPortC,7,gpioModePushPull,1);
  GPIOINT_Init();
  GPIOINT_CallbackRegister('\x06',gpioCallback + 1);
  GPIOINT_CallbackRegister('\a',gpioCallback + 1);
  GPIOINT_CallbackRegister('\x01',gpioCallback + 1);
  GPIO_ExtIntConfig(gpioPortF,6,6,true,true,true);
  GPIO_ExtIntConfig(gpioPortF,7,7,true,true,true);
  return;
}



void updateDisplay(void)

{
  char textBuf [64];
  
  if ((redrawDisplay != false) && ((int)((uint)logLevel << 0x1f) < 0)) {
    redrawDisplay = false;
    GRAPHICS_Clear();
    GRAPHICS_AppendString("\nRAIL Test App\n");
    GRAPHICS_AppendString("");
    sniprintf(textBuf,0x40,"Rx Count: %05lu",counters.receive % 100000);
    GRAPHICS_AppendString(textBuf);
    sniprintf(textBuf,0x40,"Tx Count: %05lu",counters.transmit % 100000);
    GRAPHICS_AppendString(textBuf);
    sniprintf(textBuf,0x40,"Channel: %d",(uint)channel);
    GRAPHICS_AppendString(textBuf);
    GRAPHICS_AppendString("");
    GRAPHICS_AppendString("   Tx     Rx");
    GRAPHICS_InsertTriangle
              (0x14,0x50,0x20,true,
               ((char)counters.transmit + (char)(counters.transmit / 10) * -10) * -10);
    GRAPHICS_InsertTriangle(0x4c,0x50,0x20,false,(char)(counters.receive % 10) * '\n');
    GRAPHICS_Update();
  }
  return;
}



void LedSet(int led)

{
  if ((int)((uint)logLevel << 0x1f) < 0) {
    BSP_LedSet(led);
    return;
  }
  return;
}



void LedToggle(int led)

{
  if ((int)((uint)logLevel << 0x1f) < 0) {
    BSP_LedToggle(led);
    return;
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



EMSTATUS PeripheralEnable(void)

{
  EMSTATUS EVar1;
  
                    // WARNING: Could not recover jumptable at 0x0000640e. Too many branches
                    // WARNING: Treating indirect jump as call
  EVar1 = (*displayDevice.pDisplayPowerOn)(&displayDevice,true);
  return EVar1;
}



void usDelay(uint32_t microseconds)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar1 = RAIL_GetTime();
  do {
    uVar2 = RAIL_GetTime();
  } while (uVar2 - uVar1 < microseconds);
  return;
}



void serialWaitForTxIdle(void)

{
  uint uVar1;
  
  do {
    uVar1 = read_volatile_4(Peripherals::USART0.STATUS);
  } while (-1 < (int)(uVar1 << 0x12));
  return;
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
  _Bool _Var1;
  AppMode_t AVar2;
  int *piVar3;
  
  RAIL_TxDataLoad(&transmitPayload);
  receivingPacket = false;
  counters.receive = counters.receive + 1;
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
      nextPacketTxTime.when = *piVar3 + txAfterRxDelay;
      txCount = 1;
      packetTx = true;
    }
  }
  LedToggle(0);
  if (((int)((uint)logLevel << 0x1e) < 0) && (redrawDisplay = true, piVar3 != (int *)0x0)) {
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



void RAILCb_RxRadioStatusExt(uint32_t status)

{
  _Bool _Var1;
  Counters_t *pCVar2;
  uint32_t uVar3;
  bool bVar4;
  
  pCVar2 = (Counters_t *)(status << 0x1b);
  if ((int)pCVar2 < 0) {
    receivingPacket = false;
    pCVar2 = &counters;
    counters.frameError = counters.frameError + 1;
    LedToggle(1);
  }
  if ((status & 0xc) != 0) {
    receivingPacket = true;
    pCVar2 = &counters;
    counters.syncDetect = counters.syncDetect + 1;
  }
  uVar3 = status << 0x1e;
  bVar4 = (int)uVar3 < 0;
  if (bVar4) {
    pCVar2 = &counters;
    uVar3 = counters.preambleDetect + 1;
  }
  if (bVar4) {
    pCVar2->preambleDetect = uVar3;
  }
  if ((int)(status << 0x1a) < 0) {
    receivingPacket = false;
    counters.rxOfEvent = counters.rxOfEvent + 1;
  }
  if ((int)(status << 0x19) < 0) {
    receivingPacket = false;
    counters.addrFilterEvent = counters.addrFilterEvent + 1;
  }
  pCVar2 = (Counters_t *)(status << 0x18);
  if ((int)pCVar2 < 0) {
    pCVar2 = &counters;
    counters.rfSensedEvent = counters.rfSensedEvent + 1;
    if (counters.rfSensedEvent == 0) {
      counters.rfSensedEvent = 1;
    }
  }
  uVar3 = status << 0x15;
  bVar4 = (int)uVar3 < 0;
  if (bVar4) {
    pCVar2 = &counters;
    uVar3 = counters.rxFail + 1;
  }
  if (bVar4) {
    pCVar2->rxFail = uVar3;
  }
  if (((status & 0x200) == 0) &&
     (((schRxStopOnRxEvent == false || (_Var1 = inAppMode(RX_SCHEDULED,(char *)0x0), _Var1 == false)
       ) || ((status & 0x70) == 0)))) {
    return;
  }
  enableAppMode(RX_SCHEDULED,false,(char *)0x0);
  return;
}



void RAILCb_TxRadioStatus(uint8_t status)

{
  uint uVar1;
  uint32_t *in_r2;
  Counters_t *pCVar2;
  uint32_t in_r3;
  uint32_t uVar3;
  bool bVar4;
  
  uVar1 = (uint)status;
  if ((status & 0x1e) != 0) {
    newTxError = true;
    in_r2 = &failPackets;
    in_r3 = failPackets + 1;
    failPackets = in_r3;
    lastTxStatus = status;
    scheduleNextTx();
  }
  bVar4 = (int)(uVar1 << 0x1a) < 0;
  if (bVar4) {
    in_r3 = counters.lbtSuccess + 1;
    in_r2 = &counters.transmit;
  }
  if (bVar4) {
    *(uint32_t *)((int)in_r2 + 0x3c) = in_r3;
  }
  pCVar2 = (Counters_t *)(uVar1 << 0x19);
  bVar4 = (int)pCVar2 < 0;
  if (bVar4) {
    pCVar2 = &counters;
    in_r3 = counters.lbtRetry + 1;
  }
  if (bVar4) {
    pCVar2->lbtRetry = in_r3;
  }
  uVar3 = uVar1 << 0x18;
  bVar4 = (int)uVar3 < 0;
  if (bVar4) {
    pCVar2 = &counters;
    uVar3 = counters.lbtStartCca + 1;
  }
  if (bVar4) {
    pCVar2->lbtStartCca = uVar3;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RAILCb_TimerExpired(void)

{
  _Bool _Var1;
  AppMode_t AVar2;
  _Bool *p_Var3;
  
  _Var1 = inAppMode(NONE,(char *)0x0);
  if (_Var1 == false) {
    AVar2 = currentAppMode();
    if (AVar2 == PER) {
      write_volatile_4(Peripherals::GPIO.PC_DOUTTGL,0x80);
      counters.perTriggers = counters.perTriggers + _DAT_42140d9c;
      perCount = perCount - _DAT_42140d9c;
      if (perCount == 0) {
        _DAT_42140d9c = perCount;
        enableAppMode(PER,false,(char *)0x0);
        return;
      }
      RAIL_TimerSet(perDelay,1);
      return;
    }
    p_Var3 = &packetTx;
  }
  else {
    railTimerExpireTime = RAIL_GetTime();
    railTimerConfigExpireTime = RAIL_TimerGet();
    p_Var3 = &railTimerExpired;
  }
  *p_Var3 = true;
  return;
}



void RAILCb_RxAckTimeout(void)

{
  counters.ackTimeout = counters.ackTimeout + 1;
  rxAckTimeout = true;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

RAIL_Status_t RAILCb_IEEE802154_DataRequestCommand(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = GENERIC_PHY_CanModifyAck();
  if (iVar1 == 0) {
    return RAIL_STATUS_INVALID_STATE;
  }
  uVar2 = read_volatile_4(RAC->.SR0);
  uVar2 = uVar2 & 0x20000;
  if (uVar2 == 0) {
    uRam43081210 = 1;
  }
  else {
    uVar2 = 2;
  }
  _DAT_43081104 = 0;
  return (RAIL_Status_t)uVar2;
}



void RAILCb_RssiAverageDone(int16_t avgRssi)

{
  undefined8 uVar1;
  
  rssiDoneCount = rssiDoneCount + 1;
  averageRssi = (float)FixedToFP((int)avgRssi,0x20,0x20,2,0,0);
  if (avgRssi == -0x200) {
    responsePrint("getAvgRssi","Could not read RSSI.");
    return;
  }
  uVar1 = __aeabi_f2d(averageRssi);
  responsePrint("getAvgRssi","rssi:%.2f",(int)uVar1,(int)((ulonglong)uVar1 >> 0x20));
  return;
}



void processPendingCalibrations(void)

{
  _Bool _Var1;
  uint8_t uVar2;
  RAIL_CalMask_t calForce;
  
  _Var1 = inAppMode(NONE,(char *)0x0);
  if ((((calibrateRadio != false) && (_Var1 != false)) && (skipCalibrations == false)) &&
     (receivingPacket == false)) {
    calForce = RAIL_CalPendingGet();
    if ((calForce & 0x10000) != 0) {
      RAIL_RfIdle();
    }
    counters.calibrations = counters.calibrations + 1;
    calibrateRadio = false;
    RAIL_CalStart((undefined4 *)0x0,calForce,false);
    if ((calForce & 0x10000) != 0) {
      while ((receiveModeEnabled != false && (uVar2 = RAIL_RxStart(channel), uVar2 != '\0'))) {
        RAIL_RfIdle();
      }
    }
  }
  return;
}



void processPendingCalibrations::lexical_block_0(void)

{
  uint8_t uVar1;
  RAIL_CalMask_t calForce;
  undefined *unaff_r5;
  
  calForce = RAIL_CalPendingGet();
  if ((calForce & 0x10000) != 0) {
    RAIL_RfIdle();
  }
  counters.calibrations = counters.calibrations + 1;
  *unaff_r5 = 0;
  RAIL_CalStart((undefined4 *)0x0,calForce,false);
  if ((calForce & 0x10000) != 0) {
    while ((receiveModeEnabled != false && (uVar1 = RAIL_RxStart(channel), uVar1 != '\0'))) {
      RAIL_RfIdle();
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
    return;
  }
  return;
}



void printNewTxError(void)

{
  if (newTxError != false) {
    newTxError = false;
    if ((int)((uint)lastTxStatus << 0x1e) < 0) {
      if ((int)((uint)logLevel << 0x1e) < 0) {
        responsePrint("txPacket","txStatus:Error,errorReason:Tx underflow or abort,errorCode:%u");
      }
      counters.txAbort = counters.txAbort + 1;
    }
    if ((int)((uint)lastTxStatus << 0x1d) < 0) {
      if ((int)((uint)logLevel << 0x1e) < 0) {
        responsePrint("txPacket","txStatus:Error,errorReason:Tx channel busy,errorCode:%u");
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
    responsePrintError("rxAckTimeout",'/',"Searching for RX Ack has timed out.");
    return;
  }
  return;
}



void changeChannel(uint32_t i)

{
  redrawDisplay = true;
  channel = (uint8_t)i;
  return;
}



void changeChannelConfig(int newConfig)

{
  channel = RAIL_ChannelConfig(channelConfigs[newConfig]);
  redrawDisplay = true;
  return;
}



void changeRadioConfig(int newConfig)

{
  uint8_t uVar1;
  
  RAIL_RfIdle();
  RAIL_PacketLengthConfigFrameType(frameTypeConfigList[newConfig]);
  uVar1 = RAIL_RadioConfig(configList[newConfig]);
  if (uVar1 != '\0') {
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  changeChannelConfig(newConfig);
  currentConfig = newConfig;
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
  int iVar3;
  RAIL_PreTxOp_t *pRVar4;
  RAIL_ScheduleTxConfig_t *pRVar5;
  
  uVar1 = internalTransmitCounter;
  if (packetTx == false) {
    return;
  }
  packetTx = false;
  AVar2 = currentAppMode();
  if (AVar2 != TX_CONTINUOUS) {
    txCount = txCount + -1;
  }
  AVar2 = currentAppMode();
  if (AVar2 != TX_UNDERFLOW) {
    RAIL_TxDataLoad(&transmitPayload);
  }
  AVar2 = currentAppMode();
  if ((AVar2 == TX_SCHEDULED) || (AVar2 = currentAppMode(), AVar2 == SCHTX_AFTER_RX)) {
    if (txOptionsPtr == (RAIL_TxOptions_t *)0x0) {
      pRVar5 = &nextPacketTxTime;
      pRVar4 = RAIL_ScheduleTx + 1;
      goto LAB_00002e10;
    }
    pRVar5 = &nextPacketTxTime;
    pRVar4 = RAIL_ScheduleTx + 1;
  }
  else {
    pRVar4 = txPreTxOp;
    if ((uVar1 == startTransmitCounter) && (failPackets == 0)) {
      pRVar5 = (RAIL_ScheduleTxConfig_t *)txPreTxOpArgs;
      if (txOptionsPtr == (RAIL_TxOptions_t *)0x0) {
LAB_00002e10:
        iVar3 = RAIL_TxStart(channel,pRVar4,pRVar5);
        goto LAB_00002e14;
      }
    }
    else {
      pRVar5 = (RAIL_ScheduleTxConfig_t *)txOptionsPtr;
      if (txOptionsPtr == (RAIL_TxOptions_t *)0x0) goto LAB_00002e10;
      pRVar5 = (RAIL_ScheduleTxConfig_t *)0x0;
    }
  }
  iVar3 = RAIL_TxStartWithOptions(channel,txOptionsPtr,pRVar4,pRVar5);
LAB_00002e14:
  if (iVar3 != 0) {
    lastTxStatus = (uint8_t)iVar3;
    failPackets = failPackets + 1;
    scheduleNextTx();
    return;
  }
  AVar2 = currentAppMode();
  if (AVar2 != TX_CANCEL) {
    return;
  }
  usDelay(txCancelDelay);
  RAIL_RfIdle();
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
  
  if (finishTxSequence != false) {
    finishTxSequence = false;
    if ((logLevel & 2) != 0) {
      if (failPackets == 0) {
        pcVar1 = "Complete";
      }
      else {
        pcVar1 = "Partial";
        if (internalTransmitCounter - startTransmitCounter == 0) {
          pcVar1 = "Error";
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



void setNextPacketTime(uint32_t absTime)

{
  nextPacketTxTime.when = absTime;
  return;
}



void printPacket(char *cmdName,uint8_t *data,uint16_t dataLength,RAIL_RxPacketInfo_t *packetInfo)

{
  byte bVar1;
  char *pcVar2;
  size_t __maxlen;
  undefined *puVar3;
  int iVar4;
  undefined *puVar5;
  byte *pbVar6;
  
  if (data == (uint8_t *)0x0) {
    responsePrint(cmdName,"len:0");
    return;
  }
  iVar4 = 0;
  pbVar6 = data;
  do {
    if ((int)(uint)dataLength <= (int)pbVar6 - (int)data) goto LAB_00002fa4;
    __maxlen = 0x4b5 - iVar4;
    pcVar2 = packetPrintBuffer + iVar4;
    iVar4 = iVar4 + 5;
    sniprintf(pcVar2,__maxlen," 0x%.2x",(uint)*pbVar6);
    pbVar6 = pbVar6 + 1;
  } while (iVar4 != 0x4b5);
  strcpy(packetPrintBuffer,"Packet too large!");
LAB_00002fa4:
  if (packetInfo == (RAIL_RxPacketInfo_t *)0x0) {
    responsePrint(cmdName,"len:%d,payload:%s",(uint)dataLength,packetPrintBuffer);
    return;
  }
  bVar1 = *(byte *)&(packetInfo->appendedInfo).field_0x4;
  puVar3 = &DAT_00011963;
  if ((bVar1 & 1) == 0) {
    puVar5 = &DAT_00010d42;
  }
  else {
    puVar5 = &DAT_00011963;
  }
  if ((bVar1 & 2) == 0) {
    puVar3 = &DAT_00010d42;
  }
  pcVar2 = "True";
  if ((bVar1 & 4) == 0) {
    pcVar2 = "False";
  }
  responsePrint(cmdName,"len:%d,timeUs:%u,crc:%s,coding:%s,rssi:%d,isAck:%s,payload:%s",
                (uint)packetInfo->dataLength,(packetInfo->appendedInfo).timeUs,puVar5,puVar3,
                (int)(packetInfo->appendedInfo).rssiLatch,pcVar2,packetPrintBuffer);
  return;
}



void printReceivedPacket(void)

{
  _Bool _Var1;
  void *handle;
  RAIL_RxPacketInfo_t *packetInfo;
  
  _Var1 = queueIsEmpty(&rxPacketQueue);
  if (_Var1 == false) {
    handle = queueRemove(&rxPacketQueue);
    packetInfo = (RAIL_RxPacketInfo_t *)memoryPtrFromHandle(handle);
    printPacket("rxPacket",(uint8_t *)&packetInfo->field_0xa,packetInfo->dataLength,packetInfo);
    memoryFree(handle);
    return;
  }
  return;
}



// WARNING: Could not reconcile some variable overlaps

void processInputCharacters(void)

{
  uint __c;
  int8_t iVar1;
  int iVar2;
  uint in_r1;
  char input;
  uint uStack20;
  
  uStack20 = in_r1;
  iVar2 = getchar();
  for (uStack20 = uStack20 & 0xffffff | iVar2 << 0x18; __c = uStack20 >> 0x18,
      (__c - 1 & 0xff) < 0xfe; uStack20 = uStack20 & 0xffffff | iVar2 << 0x18) {
    if (__c != 10) {
      putchar(__c);
    }
    iVar1 = ciProcessInput(&state,&input,1);
    if ('\0' < iVar1) {
      iprintf("> ");
    }
    iVar2 = getchar();
  }
  return;
}



int main(void)

{
  _Bool _Var1;
  bool bVar2;
  uint uVar3;
  undefined4 in_r1;
  CMU *in_r2;
  EMU *pEVar4;
  undefined *puVar5;
  undefined4 uVar6;
  SYSTEM_ChipRevision_TypeDef chipRev;
  
  chipRev.major = (uint8_t)((uint)in_r1 >> 8);
  uVar3 = read_volatile_4(DAT_0fe081fc);
  SYSTEM_ChipRevisionGet(&chipRev);
  if (uVar3 >> 0x18 < 0x8f) {
    uVar3 = read_volatile_4(CMU->HFBUSCLKEN0);
    write_volatile_4(CMU->HFBUSCLKEN0,uVar3 | 4);
    write_volatile_4(Peripherals::GPIO.PA_CTRL,0x500050);
    write_volatile_4(Peripherals::GPIO.PB_CTRL,0x500050);
    write_volatile_4(Peripherals::GPIO.PC_CTRL,0x500050);
    write_volatile_4(Peripherals::GPIO.PD_CTRL,0x500050);
    write_volatile_4(Peripherals::GPIO.PE_CTRL,0x500050);
    write_volatile_4(Peripherals::GPIO.PF_CTRL,0x500050);
    write_volatile_4(CMU->HFBUSCLKEN0,uVar3);
  }
  else {
    if (0x8f < uVar3 >> 0x18) goto LAB_0000310c;
  }
  in_r2 = &CMU->;
  uVar3 = read_volatile_4(CMU->HFXOSTARTUPCTRL);
  write_volatile_4(CMU->HFXOSTARTUPCTRL,uVar3 & 0xffffff80 | 0x20);
LAB_0000310c:
  pEVar4 = (EMU *)(uint)chipRev.major;
  if (pEVar4 == (EMU *)(FUN_00000000 + 1)) {
    in_r2 = (CMU *)&EMU->.BIASCONF;
    uVar3 = read_volatile_4(EMU->.BIASCONF);
    pEVar4 = (EMU *)(uVar3 | 4);
    write_volatile_4(EMU->.BIASCONF,(uint)pEVar4);
  }
  uVar3 = RMU_ResetCauseGet();
  RMU_ResetCauseClear();
  uVar3 = uVar3 & 0x10000;
  if (uVar3 != 0) {
    pEVar4 = &EMU->;
    in_r2 = (CMU *)(FUN_00000000 + 1);
  }
  if (uVar3 != 0) {
    pEVar4->CMD = (uint)in_r2;
  }
  appHalInit();
  RAIL_RfInit(&railInitParams);
  RAIL_CalInit(&railCalInitParams);
  changeRadioConfig(currentConfig);
  RAIL_RxConfig(0x67c,false);
  RAIL_TxConfig(0xfe);
  RAIL_SetRxTransitions(RAIL_RF_STATE_RX,RAIL_RF_STATE_RX,'\0');
  RAIL_SetTxTransitions(RAIL_RF_STATE_RX,RAIL_RF_STATE_RX);
  _Var1 = queueInit(&rxPacketQueue,10);
  if (_Var1 != false) {
    updateDisplay();
    puts("\nRAIL Test App");
    if (uVar3 != 0) {
      uVar3 = read_volatile_4(EMU->.EM4CTRL);
      if ((uVar3 & 1) == 0) {
        uVar6 = 0x73;
      }
      else {
        uVar6 = 0x68;
      }
      bVar2 = RAIL_RfSensed();
      puVar5 = &DAT_000116c9;
      if (bVar2 != false) {
        puVar5 = &DAT_000116c5;
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
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



void ciErrorCallback(char *command,CommandError_t error)

{
  char *formatString;
  
  if (error == CI_UNKNOWN_COMMAND) {
    formatString = "Unknown command \'%s\'";
  }
  else {
    if (error == CI_MAX_ARGUMENTS) {
      formatString = "CI_MAX_ARGUMENTS \'%s\'";
    }
    else {
      if (error != CI_INVALID_ARGUMENTS) {
        return;
      }
      formatString = "Invalid arguments for \'%s\'";
    }
  }
  responsePrintError("ci",error,formatString,command);
  return;
}



AppMode_t currentAppMode(void)

{
  return currAppMode;
}



void enableAppMode(AppMode_t next,_Bool enable,char *command)

{
  undefined4 *puVar1;
  undefined4 *puVar3;
  undefined4 *puVar2;
  
  if ((transitionPend == false) && (next != NONE)) {
    transitionPend = true;
    enableMode = enable;
    nextAppMode = next;
    if (command == (char *)0x0) {
      nextCommand = command;
      if ((logLevel & 2) != 0) {
        nextCommand = "appMode";
      }
    }
    else {
      puVar1 = (undefined4 *)command;
      puVar3 = (undefined4 *)nextCommandBuf;
      do {
        puVar2 = puVar1 + 1;
        *puVar3 = *puVar1;
        puVar1 = puVar2;
        puVar3 = puVar3 + 1;
      } while (puVar2 != (undefined4 *)(command + 0x10));
      nextCommand = nextCommandBuf;
    }
  }
  return;
}



char * appModeNames(AppMode_t appMode)

{
  char *appModes [15];
  
  appModes[0] = "None";
  appModes[1] = (char *)((int)"setTxStream" + 5);
  appModes[2] = (char *)((int)"setTxTone" + 5);
  appModes[3] = "ContinuousTx";
  appModes[4] = "DirectMode";
  appModes[5] = "PacketTx";
  appModes[6] = "ScheduledTx";
  appModes[7] = "SchTxAfterRx";
  appModes[8] = (char *)((int)"setRxOverflow" + 3);
  appModes[9] = (char *)((int)"setTxUnderflow" + 3);
  appModes[10] = "TxCancel";
  appModes[11] = "RfSense";
  appModes[12] = "PER";
  appModes[13] = "BER";
  appModes[14] = (char *)((int)"Can\'t turn on receive when in ScheduledRx" + 0x1e);
  return appModes[appMode];
}



void changeAppModeIfPending(void)

{
  bool wait;
  AppMode_t AVar1;
  char *command;
  _Bool _Var2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  uint32_t uVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  command = nextCommand;
  AVar1 = currAppMode;
  if (transitionPend == false) {
    return;
  }
  transitionPend = false;
  uVar3 = (uint)nextAppMode;
  uVar9 = uVar3;
  if (enableMode == false) {
    uVar9 = 0;
  }
  wait = SUB41(uVar9,0);
  if (currAppMode == uVar3) {
    if (enableMode != false) {
      if (nextCommand != (char *)0x0) {
        pcVar4 = appModeNames(wait);
        responsePrint(command,"%s:Enabled",pcVar4);
        return;
      }
      transitionPend = false;
      return;
    }
    if (nextCommand != (char *)0x0) {
LAB_00003376:
      pcVar4 = appModeNames(wait);
      pcVar5 = appModeNames(AVar1);
      uVar6 = RAIL_GetTime();
      _Var2 = responsePrint(command,"%s:Enabled,%s:Disabled,Time:%u",pcVar4,pcVar5,uVar6);
      uVar3 = (uint)_Var2;
    }
    uVar8 = (uint)currAppMode;
    if (uVar8 != 0) {
      if (uVar8 == 1) {
        RAIL_TxStreamStop();
        goto LAB_000033a0;
      }
      if (uVar8 == 2) {
        RAIL_TxToneStop();
        goto LAB_000033a0;
      }
      if (uVar8 == 4) {
        RAIL_DirectModeConfig(false);
        goto LAB_000033a0;
      }
      if (uVar8 < 0xb) {
        uVar10 = ~(0x668U >> uVar8) & 1;
        if (uVar10 == 0) {
          RAIL_TimerCancel(uVar3);
          txCount = uVar10;
          pendFinishTxSequence();
          goto LAB_000033a0;
        }
      }
      else {
        if (uVar8 == 0xb) {
          RAIL_RfSense(RAIL_RFSENSE_OFF,0,false);
          goto LAB_000033a0;
        }
      }
      if (uVar8 != 0xc) {
        if (uVar8 == 0xd) {
          RAIL_RfIdle();
        }
        goto LAB_000033a0;
      }
    }
  }
  else {
    if (currAppMode != 0) {
      if (nextCommand == (char *)0x0) {
        transitionPend = false;
        return;
      }
      pcVar4 = "disable";
      if (enableMode != false) {
        pcVar4 = "enable";
      }
LAB_00003480:
      pcVar5 = appModeNames(nextAppMode);
      pcVar7 = appModeNames(AVar1);
      responsePrintError(command,'\x01',"Can\'t %s %s during %s",pcVar4,pcVar5,pcVar7);
      return;
    }
    if (enableMode == false) {
      if (nextCommand == (char *)0x0) {
        transitionPend = false;
        return;
      }
      pcVar4 = "disable";
      goto LAB_00003480;
    }
    if (nextCommand != (char *)0x0) goto LAB_00003376;
  }
  RAIL_TimerCancel(uVar3);
LAB_000033a0:
  AVar1 = currAppMode;
  if (uVar9 == 1) {
    RAIL_RfIdleExt(1,wait);
    RAIL_TxStreamStart(channel,1);
  }
  else {
    if (uVar9 == 2) {
      RAIL_RfIdleExt(1,true);
      RAIL_TxToneStart(channel);
    }
    else {
      if (uVar9 == 4) {
        RAIL_DirectModeConfig(true);
      }
      else {
        if ((uVar9 != 3) && (uVar9 != 5)) {
          if ((uVar9 != 6) && (uVar9 != 10)) {
            if (1 < uVar9 - 7) {
              currAppMode = wait;
              prevAppMode = AVar1;
              return;
            }
            RAIL_RxStart(channel);
            prevAppMode = currAppMode;
            currAppMode = wait;
            return;
          }
          txCount = 1;
        }
        pendPacketTx();
      }
    }
  }
  prevAppMode = currAppMode;
  currAppMode = wait;
  return;
}



void setNextAppMode(char *command,AppMode_t next)

{
  AppMode_t next_00;
  
  next_00 = currentAppMode();
  enableAppMode(next_00,false,command);
  return;
}



_Bool inAppMode(AppMode_t appMode,char *command)

{
  AppMode_t AVar1;
  char *pcVar2;
  _Bool _Var3;
  
  AVar1 = currentAppMode();
  if (AVar1 == appMode) {
    _Var3 = true;
  }
  else {
    _Var3 = false;
    if (command != (char *)0x0) {
      pcVar2 = appModeNames(appMode);
      responsePrintError(command,'\x16',"Need to be in %s mode for this command",pcVar2);
    }
  }
  return _Var3;
}



_Bool inRadioState(RAIL_RadioState_t state,char *command)

{
  RAIL_RadioState_t RVar1;
  _Bool _Var2;
  
  RVar1 = RAIL_RfStateGet();
  if ((uint)RVar1 == (uint)state) {
    _Var2 = true;
  }
  else {
    _Var2 = false;
    if (command != (char *)0x0) {
      responsePrintError(command,'\x17',"Need to be in %s radio state for this command",
                         rfStateNames[state]);
    }
  }
  return _Var2;
}



void setNextAppMode(AppMode_t next,char *command)

{
  if (next == NONE) {
    setNextAppMode(command,(AppMode_t)command);
    return;
  }
  enableAppMode(next,true,command);
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
  AppMode_t AVar2;
  AppMode_t extraout_r1;
  AppMode_t extraout_r1_00;
  AppMode_t extraout_r1_01;
  AppMode_t extraout_r1_02;
  undefined4 in_r2;
  undefined4 in_r3;
  
  if ((0 < txCount) || (AVar1 = currentAppMode(), AVar1 == TX_CONTINUOUS)) {
    RAIL_TimerSet(continuousTransferPeriod * 1000,1,in_r2,in_r3);
    return;
  }
  AVar2 = currentAppMode();
  AVar1 = extraout_r1;
  if ((AVar2 != TX_N_PACKETS) &&
     (((AVar2 = currentAppMode(), AVar1 = extraout_r1_00, AVar2 != TX_SCHEDULED &&
       (AVar2 = currentAppMode(), AVar1 = extraout_r1_01, AVar2 != TX_UNDERFLOW)) &&
      (AVar2 = currentAppMode(), AVar1 = extraout_r1_02, AVar2 != TX_CANCEL)))) {
    pendFinishTxSequence();
    return;
  }
  setNextAppMode((char *)0x0,AVar1);
  return;
}



void radioTransmit(uint32_t iterations,char *command)

{
  AppMode_t AVar1;
  AppMode_t AVar2;
  AppMode_t extraout_r1;
  AppMode_t extraout_r1_00;
  AppMode_t extraout_r1_01;
  
  txCount = iterations;
  if (iterations == 0) {
    AVar2 = currentAppMode();
    AVar1 = extraout_r1;
    if (((AVar2 == TX_N_PACKETS) ||
        (AVar2 = currentAppMode(), AVar1 = extraout_r1_00, AVar2 == TX_CONTINUOUS)) ||
       (AVar2 = currentAppMode(), AVar1 = extraout_r1_01, AVar2 == TX_UNDERFLOW)) {
      setNextAppMode(command,AVar1);
      return;
    }
    AVar1 = TX_CONTINUOUS;
  }
  else {
    AVar1 = currentAppMode();
    if (AVar1 == TX_UNDERFLOW) {
      setNextAppMode(TX_UNDERFLOW,command);
      pendPacketTx();
      return;
    }
    AVar1 = TX_N_PACKETS;
  }
  setNextAppMode(AVar1,command);
  return;
}



void * memoryAllocate(uint32_t size)

{
  CORE_irqState_t irqState;
  undefined *puVar1;
  
  if (size < 0x101) {
    irqState = CORE_EnterCritical();
    puVar1 = (undefined *)0x0;
    do {
      if (memoryObjs[(int)puVar1].refCount == '\0') {
        memoryObjs[(int)puVar1].refCount = '\x01';
        goto LAB_0000366a;
      }
      puVar1 = puVar1 + 1;
    } while (puVar1 != &UNK_0000000a);
    puVar1 = (undefined *)0xffffffff;
LAB_0000366a:
    CORE_ExitCritical(irqState);
  }
  else {
    puVar1 = (undefined *)0xffffffff;
  }
  return puVar1;
}



void * memoryPtrFromHandle(void *handle)

{
  CORE_irqState_t irqState;
  uint8_t *puVar1;
  
  if ((handle == (void *)0xffffffff) || (&UNK_0000000a < handle)) {
    puVar1 = (uint8_t *)0x0;
  }
  else {
    irqState = CORE_EnterCritical();
    puVar1 = (uint8_t *)(uint)memoryObjs[(int)handle].refCount;
    if (puVar1 != (uint8_t *)0x0) {
      puVar1 = memoryObjs[(int)handle].data;
    }
    CORE_ExitCritical(irqState);
  }
  return puVar1;
}



void memoryFree(void *handle)

{
  CORE_irqState_t irqState;
  void *pvVar1;
  
  irqState = CORE_EnterCritical();
  pvVar1 = memoryPtrFromHandle(handle);
  if (pvVar1 != (void *)0x0) {
    memoryObjs[(int)handle].refCount = memoryObjs[(int)handle].refCount + 0xff;
  }
  CORE_ExitCritical(irqState);
  return;
}



void memoryTakeReference(void *handle)

{
  CORE_irqState_t irqState;
  void *pvVar1;
  
  irqState = CORE_EnterCritical();
  pvVar1 = memoryPtrFromHandle(handle);
  if (pvVar1 != (void *)0x0) {
    memoryObjs[(int)handle].refCount = memoryObjs[(int)handle].refCount + '\x01';
  }
  CORE_ExitCritical(irqState);
  return;
}



void * RAILCb_AllocateMemory(uint32_t size)

{
  CORE_irqState_t irqState;
  undefined *puVar1;
  
  if (size < 0x101) {
    irqState = CORE_EnterCritical();
    puVar1 = (undefined *)0x0;
    do {
      if (memoryObjs[(int)puVar1].refCount == '\0') {
        memoryObjs[(int)puVar1].refCount = '\x01';
        goto LAB_0000366a;
      }
      puVar1 = puVar1 + 1;
    } while (puVar1 != &UNK_0000000a);
    puVar1 = (undefined *)0xffffffff;
LAB_0000366a:
    CORE_ExitCritical(irqState);
  }
  else {
    puVar1 = (undefined *)0xffffffff;
  }
  return puVar1;
}



void RAILCb_FreeMemory(void *handle)

{
  CORE_irqState_t irqState;
  void *pvVar1;
  
  irqState = CORE_EnterCritical();
  pvVar1 = memoryPtrFromHandle(handle);
  if (pvVar1 != (void *)0x0) {
    memoryObjs[(int)handle].refCount = memoryObjs[(int)handle].refCount + 0xff;
  }
  CORE_ExitCritical(irqState);
  return;
}



void * RAILCb_BeginWriteMemory(void *handle,uint32_t offset,uint32_t *available)

{
  void *pvVar1;
  
  pvVar1 = memoryPtrFromHandle(handle);
  return (void *)((int)pvVar1 + offset);
}



void RAILCb_EndWriteMemory(void *handle,uint32_t offset,uint32_t size)

{
  return;
}



_Bool queueInit(Queue_t *queue,uint16_t size)

{
  CORE_irqState_t irqState;
  
  if (size < 0xb) {
    if (queue != (Queue_t *)0x0) {
      irqState = CORE_EnterCritical();
      queue->size = size;
      *(undefined4 *)queue = 0;
      CORE_ExitCritical(irqState);
      queue = (Queue_t *)(FUN_00000000 + 1);
    }
  }
  else {
    queue = (Queue_t *)0x0;
  }
  return SUB41(queue,0);
}



_Bool queueAdd(Queue_t *queue,void *data)

{
  ushort uVar1;
  ushort uVar2;
  CORE_irqState_t irqState;
  uint uVar3;
  uint uVar4;
  
  if (queue != (Queue_t *)0x0) {
    irqState = CORE_EnterCritical();
    uVar1 = queue->count;
    uVar2 = queue->size;
    uVar4 = (uint)uVar2;
    uVar3 = (uint)queue->head;
    if (uVar1 < uVar4) {
      uVar3 = uVar3 + uVar1;
      queue->data[uVar3 - uVar4 * (uVar3 / uVar4) & 0xffff] = data;
      queue->count = uVar1 + 1;
    }
    else {
      queue->data[uVar3] = data;
      queue->head = (short)(uVar3 + 1) - uVar2 * (short)((uVar3 + 1) / uVar4);
    }
    CORE_ExitCritical(irqState);
    queue = (Queue_t *)(FUN_00000000 + 1);
  }
  return SUB41(queue,0);
}



void * queueRemove(Queue_t *queue)

{
  CORE_irqState_t irqState;
  uint uVar1;
  Queue_t *pQVar2;
  
  if (queue != (Queue_t *)0x0) {
    irqState = CORE_EnterCritical();
    pQVar2 = (Queue_t *)(uint)queue->count;
    if (pQVar2 != (Queue_t *)0x0) {
      uVar1 = queue->head + 1;
      pQVar2 = (Queue_t *)queue->data[queue->head];
      queue->head = (short)uVar1 - queue->size * (short)(uVar1 / queue->size);
      queue->count = queue->count - 1;
    }
    CORE_ExitCritical(irqState);
    queue = pQVar2;
  }
  return queue;
}



_Bool queueIsEmpty(Queue_t *queue)

{
  CORE_irqState_t irqState;
  undefined uVar1;
  uint uVar2;
  
  if (queue == (Queue_t *)0x0) {
    uVar1 = 1;
  }
  else {
    irqState = CORE_EnterCritical();
    uVar2 = count_leading_zeroes((uint)queue->count);
    uVar1 = (undefined)(uVar2 >> 5);
    CORE_ExitCritical(irqState);
  }
  return (_Bool)uVar1;
}



_Bool validateInteger(char *str,int lengthInBytes,_Bool isSigned)

{
  undefined4 *puVar1;
  int *piVar2;
  size_t sVar3;
  ulong uVar4;
  char *endptr;
  
  endptr = (char *)lengthInBytes;
  if (isSigned == false) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0;
    uVar4 = strtoul(str,&endptr,0);
    if ((uVar4 & ~((1 << ((lengthInBytes & 0x1fU) << 3)) - 1U)) != 0) {
      return false;
    }
  }
  else {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0;
    strtol(str,&endptr,0);
  }
  piVar2 = (int *)__errno();
  if (*piVar2 != 0) {
    return false;
  }
  sVar3 = strlen(str);
  return (_Bool)((int)endptr - (int)str == sVar3);
}



_Bool ciPrintHelp(CommandEntry_t *commands)

{
  size_t sVar1;
  size_t sVar2;
  char *__format;
  char *pcVar3;
  CommandEntry_t *pCVar4;
  size_t sVar5;
  size_t sVar6;
  
  sVar5 = 0;
  sVar6 = 0;
  for (pCVar4 = commands; (pCVar4 != (CommandEntry_t *)0x0 && (pCVar4->command != (char *)0x0));
      pCVar4 = pCVar4 + 1) {
    sVar1 = strlen(pCVar4->command);
    sVar2 = strlen(pCVar4->arguments);
    if ((int)sVar6 < (int)sVar1) {
      sVar6 = sVar1;
    }
    if ((int)sVar5 < (int)sVar2) {
      sVar5 = sVar2;
    }
  }
  puts("<command> <args> <help text>");
  puts("  u=uint8, v=uint16, w=uint32, s=int32, b=string, ?=Anything, *=0 or more of previous");
  do {
    if ((commands == (CommandEntry_t *)0x0) || (pcVar3 = commands->command, pcVar3 == (char *)0x0))
    {
      return true;
    }
    __format = " --- %s ---";
    if (commands->callback == FUN_00000000) {
LAB_000038c2:
      iprintf(__format,pcVar3);
    }
    else {
      iprintf("%*s",-sVar6);
      pcVar3 = commands->arguments;
      if (pcVar3 == (char *)0x0) {
        pcVar3 = "";
      }
      else {
        if (*pcVar3 == '\0') {
          pcVar3 = "";
        }
      }
      iprintf(" %*s",-sVar5,pcVar3);
      pcVar3 = commands->helpStr;
      if ((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) {
        __format = " %s";
        goto LAB_000038c2;
      }
    }
    putchar(10);
    commands = commands + 1;
  } while( true );
}



uint8_t ciInitState(CommandState_t *state,char *buffer,uint32_t length,CommandEntry_t *commands)

{
  if ((state != (CommandState_t *)0x0) && (buffer != (char *)0x0)) {
    state->buffer = buffer;
    state->offset = 0;
    state->length = length;
    state->commands = commands;
    state->prevEol = '\0';
    return '\0';
  }
  return '\x01';
}



int8_t ciProcessInput(CommandState_t *state,char *data,uint32_t length)

{
  char cVar1;
  char cVar2;
  _Bool _Var3;
  int iVar4;
  int iVar5;
  size_t sVar6;
  char *pcVar7;
  CommandError_t error;
  char *pcVar8;
  int lengthInBytes;
  size_t sVar9;
  CommandEntry_t *commands;
  uint uVar10;
  char *__s;
  CommandEntry_t *pCVar11;
  CommandEntry_t *__s2;
  int8_t iVar12;
  byte bVar13;
  uint local_a0;
  char *local_98;
  char *saveptr;
  char *argv [20];
  
  if ((state == (CommandState_t *)0x0) || (data == (char *)0x0)) {
    iVar12 = -1;
  }
  else {
    uVar10 = state->offset;
    if (uVar10 + length < state->length) {
      memcpy(state->buffer + uVar10,data,length);
      iVar12 = '\0';
      state->offset = state->offset + length;
      local_a0 = 0;
LAB_00003948:
      if (uVar10 < state->offset) {
        cVar1 = state->buffer[uVar10];
        if ((cVar1 == '\n') || (cVar1 == '\r')) {
          state->buffer[uVar10] = '\0';
          if (uVar10 != local_a0) {
            commands = state->commands;
            __s = state->buffer + local_a0;
            pcVar8 = __s + -1;
            pcVar7 = __s;
            while( true ) {
              pcVar8 = pcVar8 + 1;
              cVar2 = *pcVar8;
              if (cVar2 == '\0') break;
              if (cVar2 == '\b') {
                if (__s < pcVar7) {
                  pcVar7 = pcVar7 + -1;
                }
              }
              else {
                *pcVar7 = cVar2;
                pcVar7 = pcVar7 + 1;
              }
            }
            *pcVar7 = '\0';
            local_98 = strtok_r(__s,"\n\r ",&saveptr);
            pCVar11 = commands;
            if (local_98 == (char *)0x0) goto LAB_000039a8;
            for (; pCVar11 != (CommandEntry_t *)0x0; pCVar11 = pCVar11 + 1) {
              __s2 = (CommandEntry_t *)pCVar11->command;
              if (__s2 == (CommandEntry_t *)0x0) goto LAB_00003a3e;
              if ((pCVar11->callback != FUN_00000000) &&
                 (iVar4 = strcasecmp(local_98,(char *)__s2), iVar4 == 0)) {
                argv[0] = (char *)__s2;
                local_98 = strtok_r((char *)0x0,"\n\r ",&saveptr);
                iVar4 = 1;
                goto LAB_00003afc;
              }
            }
            __s2 = pCVar11;
            if (commands != (CommandEntry_t *)0x0) goto LAB_00003b5a;
            goto LAB_00003a50;
          }
          goto LAB_000039a8;
        }
        goto LAB_000039cc;
      }
      if (local_a0 != 0) {
        sVar9 = state->offset - local_a0;
        state->offset = sVar9;
        memmove(state->buffer,state->buffer + local_a0,sVar9);
      }
    }
    else {
      iVar12 = -2;
    }
  }
  return iVar12;
LAB_00003afc:
  if (local_98 == (char *)0x0) goto code_r0x00003b04;
  argv[iVar4] = local_98;
  iVar4 = iVar4 + 1;
  if (iVar4 == 0x14) {
    error = CI_MAX_ARGUMENTS;
    goto LAB_000039f6;
  }
  local_98 = strtok_r((char *)0x0,"\n\r ",&saveptr);
  goto LAB_00003afc;
code_r0x00003b04:
  pcVar8 = pCVar11->arguments;
  if ((pcVar8 == (char *)0x0) || (iVar5 = strcmp(pcVar8,"?"), iVar5 == 0)) {
LAB_00003a32:
    (*pCVar11->callback)(iVar4,argv);
    __s2 = (CommandEntry_t *)(FUN_00000000 + 1);
LAB_00003a3e:
    if ((pCVar11->command == (char *)0x0) && (commands != (CommandEntry_t *)0x0)) {
LAB_00003b5a:
      iVar4 = strcasecmp(__s,"help");
      if (iVar4 == 0) {
        _Var3 = ciPrintHelp(commands);
        __s2 = (CommandEntry_t *)(uint)_Var3;
      }
    }
    if (__s2 != (CommandEntry_t *)0x0) goto LAB_000039a8;
LAB_00003a50:
    error = CI_UNKNOWN_COMMAND;
    __s = local_98;
  }
  else {
    sVar6 = strlen(pcVar8);
    pcVar7 = strchr(pcVar8,0x2a);
    sVar9 = sVar6;
    if (pcVar7 == (char *)0x0) {
LAB_00003a14:
      bVar13 = 0x2e;
      for (iVar5 = 1; iVar4 != iVar5; iVar5 = iVar5 + 1) {
        if (iVar5 + -1 < (int)sVar6) {
          if (pcVar8[iVar5 + -1] != 0x2a) {
            bVar13 = pcVar8[iVar5 + -1];
          }
        }
        else {
          if (pcVar8[sVar6 - 1] != '*') goto LAB_00003b3c;
        }
        if (bVar13 == 0x75) {
          _Var3 = false;
          lengthInBytes = 1;
LAB_00003aaa:
          _Var3 = validateInteger(argv[iVar5],lengthInBytes,_Var3);
          if (_Var3 == false) goto LAB_00003b3c;
        }
        else {
          if (0x75 < bVar13) {
            if (bVar13 == 0x76) {
              _Var3 = false;
              lengthInBytes = 2;
              goto LAB_00003aaa;
            }
            if (bVar13 == 0x77) {
              _Var3 = false;
              goto LAB_00003aa2;
            }
            goto LAB_00003b3c;
          }
          if (bVar13 != 0x62) {
            if (bVar13 == 0x73) {
              _Var3 = true;
LAB_00003aa2:
              lengthInBytes = 4;
              goto LAB_00003aaa;
            }
            goto LAB_00003b3c;
          }
        }
      }
      if ((int)sVar9 < iVar4) goto LAB_00003a32;
    }
    else {
      if ((pcVar7 == pcVar8 + (sVar6 - 1)) && (sVar6 != 1)) {
        sVar9 = sVar6 - 2;
        goto LAB_00003a14;
      }
    }
LAB_00003b3c:
    error = CI_INVALID_ARGUMENTS;
  }
LAB_000039f6:
  ciErrorCallback(__s,error);
LAB_000039a8:
  if (((cVar1 != '\n') || (state->prevEol != '\r')) || (uVar10 != local_a0)) {
    iVar12 = iVar12 + '\x01';
  }
  local_a0 = uVar10 + 1;
  state->prevEol = cVar1;
LAB_000039cc:
  uVar10 = uVar10 + 1;
  goto LAB_00003948;
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
  int lengthInBytes;
  
  if (false) {
switchD_00003b96_caseD_74:
    return false;
  }
  switch(type) {
  case 's':
    lengthInBytes = 4;
    _Var1 = true;
    goto LAB_00003bae;
  default:
    goto switchD_00003b96_caseD_74;
  case 'u':
    lengthInBytes = 1;
    break;
  case 'v':
    lengthInBytes = 2;
    break;
  case 'w':
    lengthInBytes = 4;
  }
  _Var1 = false;
LAB_00003bae:
  _Var1 = validateInteger(arg,lengthInBytes,_Var1);
  return _Var1;
}



void Reset_Handler(void)

{
  undefined4 *puVar1;
  RAIL_AddrConfig_t *pRVar2;
  
  SystemInit();
  puVar1 = (undefined4 *)&__exidx_end;
  for (pRVar2 = &config; (int)pRVar2 < (int)&__data_end__;
      pRVar2 = (RAIL_AddrConfig_t *)&pRVar2->offsets) {
    *(undefined4 *)pRVar2 = *puVar1;
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



uint32_t SystemMaxCoreClockGet(void)

{
  return 38400000;
}



uint32_t SystemHFClockGet(void)

{
  uint uVar1;
  uint uVar2;
  uint32_t *puVar3;
  
  uVar2 = read_volatile_4(CMU->HFCLKSTATUS);
  uVar2 = uVar2 & 7;
  if (uVar2 == 3) {
    uVar2 = 0x8000;
  }
  else {
    if (uVar2 == 4) {
      puVar3 = &SystemLFXOClock;
    }
    else {
      if (uVar2 == 2) {
        puVar3 = &SystemHFXOClock;
      }
      else {
        puVar3 = &SystemHfrcoFreq;
      }
    }
    uVar2 = *puVar3;
  }
  uVar1 = read_volatile_4(CMU->HFPRESC);
  return uVar2 / (((uVar1 << 0x13) >> 0x1b) + 1);
}



void SystemCoreClockGet(void)

{
  uint uVar1;
  uint32_t uVar2;
  
  uVar2 = SystemHFClockGet();
  uVar1 = read_volatile_4(CMU->HFCOREPRESC);
  SystemCoreClock = uVar2 / (((uVar1 << 0xf) >> 0x17) + 1);
  return;
}



uint32_t SystemHFXOClockGet(void)

{
  return SystemHFXOClock;
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



void BSP_BccPinsEnable(_Bool enable)

{
  uint uVar1;
  
  GPIO_PinModeSet(gpioPortA,0,gpioModePushPull,1);
  GPIO_PinModeSet(gpioPortA,1,gpioModeInput,1);
  GPIO_PinModeSet(gpioPortA,5,gpioModePushPull,1);
  write_volatile_4(Peripherals::USART0.ROUTEPEN,3);
  uVar1 = read_volatile_4(Peripherals::USART0.ROUTELOC0);
  write_volatile_4(Peripherals::USART0.ROUTELOC0,uVar1 & 0xffffe0e0);
  return;
}



// WARNING: Could not reconcile some variable overlaps

int BSP_BccInit(void)

{
  _Bool enable;
  USART_InitAsync_TypeDef usartInit;
  
  usartInit._0_4_ = 5;
  usartInit.refFreq = 0;
  usartInit.baudrate = 0x1c200;
  usartInit._12_4_ = 0x500;
  usartInit._16_4_ = 0x1000;
  usartInit._20_4_ = 0;
  rxByteCount = 0;
  txByteCount = 0;
  CMU_ClockEnable(cmuClock_HFPER,true);
  CMU_ClockEnable(cmuClock_GPIO,true);
  CMU_ClockEnable(cmuClock_USART0,true);
  enable = false;
  USART_InitAsync((USART_TypeDef *)&Peripherals::USART0,&usartInit);
  BSP_BccPinsEnable(enable);
  return 0;
}



int BSP_Init(uint32_t flags)

{
  if ((int)(flags << 0x1d) < 0) {
    BSP_BccInit();
  }
  return 0;
}



int BSP_LedsInit(void)

{
  CMU_ClockEnable(cmuClock_HFPER,true);
  CMU_ClockEnable(cmuClock_GPIO,true);
  GPIO_PinModeSet(gpioPortF,4,gpioModePushPull,0);
  GPIO_PinModeSet(gpioPortF,5,gpioModePushPull,0);
  return 0;
}



int BSP_LedClear(int ledNo)

{
  if ((uint)ledNo < 2) {
    *(undefined4 *)
     ((ledArray[ledNo].pin + ((uint)ledArray[ledNo].port * 0x30 + 0x4210a00c) * 8) * 4) = 0;
    return 0;
  }
  return -1;
}



int BSP_LedSet(int ledNo)

{
  if ((uint)ledNo < 2) {
    *(undefined4 *)
     ((ledArray[ledNo].pin + ((uint)ledArray[ledNo].port * 0x30 + 0x4210a00c) * 8) * 4) = 1;
    return 0;
  }
  return -1;
}



int BSP_LedToggle(int ledNo)

{
  if ((uint)ledNo < 2) {
    (&Peripherals::GPIO.PA_DOUTTGL)[(uint)ledArray[ledNo].port * 0xc] =
         1 << (ledArray[ledNo].pin & 0xff);
    return 0;
  }
  return -1;
}



void flashWaitStateControl(uint32_t coreFreq)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = read_volatile_4(Peripherals::MSC.LOCK);
  write_volatile_4(Peripherals::MSC.LOCK,0x1b71);
  read_volatile(Peripherals::MSC.READCTRL._0_1_);
  if (coreFreq + 0xfe73457f < 14000000) {
    uVar3 = 0x1000000;
  }
  else {
    uVar3 = 0;
  }
  uVar1 = read_volatile_4(Peripherals::MSC.READCTRL);
  write_volatile_4(Peripherals::MSC.READCTRL,uVar1 & 0xfcffffff | uVar3);
  if (uVar2 != 0) {
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



void syncReg(uint32_t mask)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(CMU->FREEZE);
  if (-1 < (int)(uVar1 << 0x1f)) {
    do {
      uVar1 = read_volatile_4(CMU->SYNCBUSY);
    } while ((mask & uVar1) != 0);
  }
  return;
}



void CMU_OscillatorTuningSet(uint32_t val,CMU_Osc_TypeDef osc)

{
  uint uVar1;
  
  read_volatile(CMU->STATUS._0_1_);
  uVar1 = read_volatile_4(CMU->HFXOCTRL);
  write_volatile_4(CMU->HFXOCTRL,uVar1 & 0xffffffcf | 0x10);
  uVar1 = ((val << 0x15) >> 0x1c) + 3;
  if (0xe < uVar1) {
    uVar1 = 0xf;
  }
  write_volatile_4(Peripherals::CMU_CLR.HFXOSTEADYSTATECTRL,0xf00007ff);
  write_volatile_4(Peripherals::CMU_SET.HFXOSTEADYSTATECTRL,val | uVar1 << 0x1c);
  return;
}



void CMU_ClockEnable(CMU_Clock_TypeDef clock,_Bool enable)

{
  uint32_t mask;
  uint uVar1;
  uint extraout_r1;
  CMU *pCVar2;
  
  uVar1 = (uint)enable;
  if (true) {
    switch((clock << 0x14) >> 0x1c) {
    case 1:
      mask = 0;
      pCVar2 = &CMU->;
      break;
    case 2:
      mask = 0;
      pCVar2 = (CMU *)&CMU->HFPERCLKEN0;
      break;
    default:
      goto switchD_00003eca_caseD_3;
    case 5:
      pCVar2 = (CMU *)&CMU->HFBUSCLKEN0;
      mask = 0;
      break;
    case 6:
      mask = 1;
      pCVar2 = (CMU *)&CMU->LFACLKEN0;
      break;
    case 7:
      mask = 0x10;
      pCVar2 = (CMU *)&CMU->LFBCLKEN0;
      break;
    case 9:
      mask = 0x10000;
      pCVar2 = (CMU *)&CMU->LFECLKEN0;
      break;
    case 10:
      mask = 0;
      pCVar2 = (CMU *)&CMU->PCNTCTRL;
    }
    if (mask != 0) {
      syncReg(mask);
      uVar1 = extraout_r1;
    }
    *(uint *)((((clock << 0xf) >> 0x1b) + (int)&pCVar2[0x114fb].RFLOCK0 * 8) * 4) = uVar1;
  }
switchD_00003eca_caseD_3:
  return;
}



uint32_t CMU_ClockPrescGet(CMU_Clock_TypeDef clock)

{
  uint uVar1;
  
  switch((clock << 0x18) >> 0x1c) {
  case 1:
    uVar1 = read_volatile_4(CMU->HFPRESC);
    break;
  case 2:
    uVar1 = read_volatile_4(CMU->HFEXPPRESC);
    break;
  case 3:
    uVar1 = read_volatile_4(CMU->HFPRESC);
    return (uVar1 << 7) >> 0x1f;
  case 4:
    uVar1 = read_volatile_4(CMU->HFPERPRESC);
    goto LAB_00003f74;
  case 5:
    uVar1 = read_volatile_4(CMU->HFCOREPRESC);
LAB_00003f74:
    return (uVar1 << 0xf) >> 0x17;
  case 6:
    if (clock != cmuClock_LETIMER0) {
      return 0;
    }
    uVar1 = read_volatile_4(CMU->LFAPRESC0);
    uVar1 = uVar1 & 0xf;
    goto LAB_00003f92;
  case 7:
    if (clock != cmuClock_LEUART0) {
      return 0;
    }
    uVar1 = read_volatile_4(CMU->LFBPRESC0);
    uVar1 = uVar1 & 3;
LAB_00003f92:
    return (1 << uVar1) - 1;
  default:
    return 0;
  }
  return (uVar1 << 0x13) >> 0x1b;
}



CMU_ClkDiv_TypeDef CMU_ClockDivGet(CMU_Clock_TypeDef clock)

{
  uint32_t uVar1;
  
  uVar1 = CMU_ClockPrescGet(clock);
  return uVar1 + 1;
}



CMU_Select_TypeDef CMU_ClockSelectGet(CMU_Clock_TypeDef clock)

{
  CMU_Select_TypeDef CVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  if (false) {
switchD_00003fd2_caseD_4:
    return cmuSelect_Error;
  }
  switch(clock & 0xf) {
  case 1:
    uVar3 = read_volatile_4(CMU->HFCLKSTATUS);
    uVar3 = (uVar3 & 7) - 2;
    if (2 < uVar3) {
      return cmuSelect_HFRCO;
    }
    puVar2 = &CSWTCH_44;
    break;
  case 2:
    uVar3 = read_volatile_4(CMU->LFACLKSEL);
    uVar3 = (uVar3 & 7) - 1;
    if (3 < uVar3) {
      return cmuSelect_Disabled;
    }
    puVar2 = &DAT_00013bdf;
    break;
  case 3:
    uVar3 = read_volatile_4(CMU->LFBCLKSEL);
    uVar3 = (uVar3 & 7) - 1;
    if (3 < uVar3) {
      return cmuSelect_Disabled;
    }
    puVar2 = &DAT_00013be3;
    break;
  default:
    goto switchD_00003fd2_caseD_4;
  case 5:
    uVar3 = read_volatile_4(CMU->LFECLKSEL);
    uVar3 = (uVar3 & 7) - 1;
    if (3 < uVar3) {
      return cmuSelect_Disabled;
    }
    puVar2 = &DAT_00013bdf;
    break;
  case 6:
    uVar3 = read_volatile_4(CMU->DBGCLKSEL);
    if ((uVar3 & 1) == 0) {
      CVar1 = cmuSelect_AUXHFRCO;
    }
    else {
      CVar1 = cmuSelect_HFCLK;
    }
    return CVar1;
  }
  return (CMU_Select_TypeDef)puVar2[uVar3];
}



uint32_t lfClkGet(CMU_Clock_TypeDef lfClkBranch)

{
  CMU_Select_TypeDef CVar1;
  uint uVar2;
  uint32_t uVar3;
  int extraout_r1;
  
  CVar1 = CMU_ClockSelectGet(lfClkBranch);
  uVar2 = (uint)CVar1;
  if (extraout_r1 == 0x1c0003) {
    uVar2 = read_volatile_4(CMU->LFBCLKSEL);
  }
  else {
    if (extraout_r1 == 0x200005) {
      uVar2 = read_volatile_4(CMU->LFECLKSEL);
    }
    else {
      if (extraout_r1 != 0x1a0002) goto LAB_00004084;
      uVar2 = read_volatile_4(CMU->LFACLKSEL);
    }
  }
  uVar2 = uVar2 & 7;
LAB_00004084:
  switch(uVar2) {
  case 1:
    uVar3 = SystemLFRCOClockGet();
    return uVar3;
  case 2:
    uVar3 = SystemLFXOClockGet();
    return uVar3;
  case 3:
    uVar2 = read_volatile_4(CMU->HFPRESC);
    if ((int)(uVar2 << 7) < 0) {
      uVar2 = SystemCoreClockGet();
      uVar3 = uVar2 >> 2;
    }
    else {
      uVar2 = SystemCoreClockGet();
      uVar3 = uVar2 >> 1;
    }
    break;
  case 4:
    uVar3 = SystemULFRCOClockGet();
    return uVar3;
  default:
    uVar3 = 0;
  }
  return uVar3;
}



uint32_t CMU_ClockFreqGet(CMU_Clock_TypeDef clock)

{
  CMU_Select_TypeDef CVar1;
  uint uVar2;
  CMU_AUXHFRCOFreq_TypeDef CVar3;
  uint uVar4;
  CMU_Clock_TypeDef lfClkBranch;
  bool bVar5;
  
  uVar2 = clock & 0x3e0000;
  if (uVar2 == 0xe0000) {
    return auxHfrcoFreq;
  }
  if (0xe0000 < uVar2) {
    if (uVar2 != 0x160000) {
      if (uVar2 < 0x160001) {
        if (uVar2 != 0x120000) {
          if (uVar2 != 0x140000) {
            return cmuAUXHFRCOFreq_UserDefined;
          }
          uVar4 = lfClkGet(cmuClock_LFA);
          uVar2 = read_volatile_4(CMU->LFAPRESC0);
          uVar2 = uVar2 & 0xf;
          goto LAB_00004148;
        }
      }
      else {
        if (uVar2 == 0x1c0000) {
          lfClkBranch = cmuClock_LFB;
          goto LAB_00004162;
        }
        if (uVar2 != 0x200000) {
          if (uVar2 != 0x1a0000) {
            return cmuAUXHFRCOFreq_UserDefined;
          }
          lfClkBranch = cmuClock_LFA;
          goto LAB_00004162;
        }
      }
      lfClkBranch = cmuClock_LFE;
LAB_00004162:
      CVar3 = lfClkGet(lfClkBranch);
      return CVar3;
    }
    uVar4 = lfClkGet(cmuClock_LFB);
    uVar2 = read_volatile_4(CMU->LFBPRESC0);
    uVar2 = uVar2 & 3;
LAB_00004148:
    uVar2 = 1 << uVar2;
    goto LAB_0000417a;
  }
  if (uVar2 == 0x40000) {
    uVar4 = SystemHFClockGet();
    uVar2 = read_volatile_4(CMU->HFPERPRESC);
LAB_00004174:
    uVar2 = (uVar2 << 0xf) >> 0x17;
  }
  else {
    if (uVar2 < 0x40001) {
      if (uVar2 == 0) goto LAB_0000411c;
      if (uVar2 != 0x20000) {
        return cmuAUXHFRCOFreq_UserDefined;
      }
      uVar4 = SystemHFClockGet();
      uVar2 = read_volatile_4(CMU->HFCOREPRESC);
      goto LAB_00004174;
    }
    if (uVar2 != 0xa0000) {
      if (uVar2 == 0xc0000) {
        CVar1 = CMU_ClockSelectGet(cmuClock_DBG);
        if (CVar1 == cmuSelect_AUXHFRCO) {
          return auxHfrcoFreq;
        }
        bVar5 = CVar1 == cmuSelect_HFCLK;
      }
      else {
        bVar5 = uVar2 == 0x80000;
      }
      if (!bVar5) {
        return cmuAUXHFRCOFreq_UserDefined;
      }
LAB_0000411c:
      CVar3 = SystemHFClockGet();
      return CVar3;
    }
    uVar4 = SystemHFClockGet();
    uVar2 = read_volatile_4(CMU->HFEXPPRESC);
    uVar2 = (uVar2 << 0x13) >> 0x1b;
  }
  uVar2 = uVar2 + 1;
LAB_0000417a:
  return uVar4 / uVar2;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void CMU_ClockPrescSet(CMU_Clock_TypeDef clock,CMU_ClkPresc_TypeDef presc)

{
  uint uVar1;
  uint32_t uVar2;
  int extraout_r1;
  int extraout_r1_00;
  
  switch((clock << 0x18) >> 0x1c) {
  case 1:
    flashWaitStateMax();
    uVar1 = read_volatile_4(CMU->HFPRESC);
    write_volatile_4(CMU->HFPRESC,uVar1 & 0xffffe0ff | presc << 8);
    goto LAB_0000421e;
  case 2:
    uVar1 = read_volatile_4(CMU->HFEXPPRESC);
    write_volatile_4(CMU->HFEXPPRESC,uVar1 & 0xffffe0ff | presc << 8);
    break;
  case 3:
    uVar1 = read_volatile_4(CMU->HFPRESC);
    write_volatile_4(CMU->HFPRESC,uVar1 & 0xfeffffff | presc << 0x18);
    break;
  case 4:
    uVar1 = read_volatile_4(CMU->HFPERPRESC);
    write_volatile_4(CMU->HFPERPRESC,uVar1 & 0xfffe00ff | presc << 8);
    break;
  case 5:
    flashWaitStateMax();
    uVar1 = read_volatile_4(CMU->HFCOREPRESC);
    write_volatile_4(CMU->HFCOREPRESC,uVar1 & 0xfffe00ff | presc << 8);
LAB_0000421e:
    _DAT_43c82060 = 1;
    _DAT_43c80040 = 1;
    uVar2 = SystemCoreClockGet();
    flashWaitStateControl(uVar2);
    uVar2 = CMU_ClockFreqGet(cmuClock_HFLE);
    _DAT_43c80040 = (uint)(32000000 < uVar2);
    _DAT_43c82060 = _DAT_43c80040;
    break;
  case 6:
    if (clock != cmuClock_RTCC) {
      if (clock != cmuClock_LETIMER0) {
        return;
      }
      count_leading_zeroes(presc + 1);
      syncReg(4);
      uVar1 = read_volatile_4(CMU->LFAPRESC0);
      write_volatile_4(CMU->LFAPRESC0,uVar1 & 0xfffffff0 | 0x1fU - extraout_r1);
      return;
    }
    goto LAB_000042fe;
  case 7:
    if (clock == cmuClock_LEUART0) {
      count_leading_zeroes(presc + 1);
      syncReg(0x40);
      uVar1 = read_volatile_4(CMU->LFBPRESC0);
      write_volatile_4(CMU->LFBPRESC0,uVar1 & 0xfffffffc | 0x1fU - extraout_r1_00);
    }
    break;
  case 8:
    if (clock != cmuClock_RTCC) {
      return;
    }
LAB_000042fe:
    syncReg(0x40000);
    uVar1 = read_volatile_4(CMU->LFEPRESC0);
    write_volatile_4(CMU->LFEPRESC0,presc | uVar1 & 0xfffffff0);
  }
  return;
}



void CMU_ClockDivSet(CMU_Clock_TypeDef clock,CMU_ClkDiv_TypeDef div)

{
  CMU_ClockPrescSet(clock,div - 1);
  return;
}



_Bool CMU_OscillatorTuningWait(CMU_Osc_TypeDef osc,CMU_HFXOTuningMode_TypeDef mode)

{
  uint uVar1;
  _Bool _Var2;
  uint uVar3;
  
  uVar3 = read_volatile_4(CMU->HFXOCTRL);
  if ((uVar3 & 0x30) != 0) {
    if (mode == cmuHFXOTuningMode_ShuntCommand) {
      uVar3 = 0x800000;
      goto LAB_0000435e;
    }
    if ((mode != cmuHFXOTuningMode_PeakShuntCommand) && (mode != cmuHFXOTuningMode_Auto)) {
      uVar3 = 0x7c103ff;
      goto LAB_0000435e;
    }
  }
  uVar3 = 0xc00000;
LAB_0000435e:
  do {
    uVar1 = read_volatile_4(CMU->STATUS);
  } while ((uVar3 & ~uVar1) != 0);
  if ((int)(uVar3 << 9) < 0) {
    uVar3 = read_volatile_4(CMU->IF);
    _Var2 = SUB41((uVar3 << 0x15) >> 0x1f,0);
  }
  else {
    _Var2 = true;
  }
  return _Var2;
}



_Bool CMU_OscillatorTuningOptimize(CMU_Osc_TypeDef osc,CMU_HFXOTuningMode_TypeDef mode,_Bool wait)

{
  _Bool _Var1;
  
  if (osc == cmuOsc_HFXO) {
    if (mode != 0) {
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



void CMU_OscillatorEnable(CMU_Osc_TypeDef osc,_Bool enable,_Bool wait)

{
  CMU_Osc_TypeDef osc_00;
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  switch(osc) {
  case cmuOsc_LFXO:
    uVar5 = 0x200;
    uVar4 = 0x100;
    iVar1 = 8;
    uVar3 = 9;
    break;
  case cmuOsc_LFRCO:
    uVar5 = 0x80;
    uVar4 = 0x40;
    iVar1 = 6;
    uVar3 = 7;
    break;
  case cmuOsc_HFXO:
    if (enable == false) {
      uVar5 = 8;
      iVar1 = 2;
      goto LAB_00004470;
    }
    uVar5 = read_volatile_4(CMU->HFXOCTRL);
    if ((uVar5 & 0x30) != 0) {
      uVar4 = 4;
      iVar1 = 2;
      uVar3 = 3;
      goto LAB_00004462;
    }
    uVar5 = read_volatile_4(CMU->HFXOCTRL);
    if ((int)(uVar5 << 0x1f) < 0) {
      uVar5 = read_volatile_4(CMU->HFXOCTRL);
      write_volatile_4(CMU->HFXOCTRL,uVar5 & 0xffffffcf | 0x10);
    }
    uVar4 = 4;
    iVar1 = 2;
    uVar3 = 3;
    goto LAB_00004402;
  case cmuOsc_HFRCO:
    uVar3 = 1;
    uVar5 = 2;
    iVar1 = 0;
    uVar4 = uVar3;
    break;
  case cmuOsc_AUXHFRCO:
    uVar5 = 0x20;
    iVar1 = 4;
    uVar3 = 5;
    uVar4 = 0x10;
    break;
  default:
    return;
  }
  if (enable == false) {
LAB_00004470:
    write_volatile_4(CMU->OSCENCMD,uVar5);
    do {
    } while (*(int *)((iVar1 + 0x10f20480) * 4) != 0);
  }
  else {
LAB_00004462:
    enable = false;
LAB_00004402:
    write_volatile_4(CMU->OSCENCMD,uVar4);
    do {
    } while (*(int *)((iVar1 + 0x10f20480) * 4) == 0);
    if (wait != false) {
      piVar2 = (int *)((uVar3 + 0x10f20480) * 4);
      do {
      } while (*piVar2 == 0);
      if ((osc == cmuOsc_HFXO) && (enable != false)) {
        uVar5 = read_volatile_4(CMU->HFXOCTRL);
        if ((uVar5 & 1) == 0) {
          CMU_OscillatorTuningWait(cmuOsc_HFXO,cmuHFXOTuningMode_Auto);
        }
        else {
          CMU_OscillatorTuningOptimize(cmuOsc_HFXO,cmuHFXOTuningMode_ShuntCommand,true);
        }
        uVar5 = read_volatile_4(CMU->HFXOTRIMSTATUS);
        CMU_OscillatorEnable(cmuOsc_HFXO,false,true);
        CMU_OscillatorTuningSet(uVar5 & 0x7ff,osc_00);
        write_volatile_4(CMU->OSCENCMD,uVar4);
        do {
        } while (*piVar2 == 0);
      }
    }
  }
  EMU_UpdateOscConfig();
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void CMU_ClockSelectSet(CMU_Clock_TypeDef clock,CMU_Select_TypeDef ref)

{
  uint32_t uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  
  if (false) {
    return;
  }
  switch(clock & 0xf) {
  case 1:
    switch(ref) {
    case cmuSelect_LFXO:
      uVar2 = 0;
      uVar4 = 4;
      break;
    case cmuSelect_LFRCO:
      uVar2 = 1;
      uVar4 = 3;
      break;
    case cmuSelect_HFXO:
      _DAT_43c80040 = 1;
      uVar2 = 2;
      _DAT_43c82060 = 1;
      uVar4 = uVar2;
      break;
    case cmuSelect_HFRCO:
      _DAT_43c80040 = 1;
      uVar2 = 3;
      _DAT_43c82060 = 1;
      uVar4 = 1;
      break;
    default:
      return;
    }
    CMU_OscillatorEnable((CMU_Osc_TypeDef)uVar2,true,true);
    flashWaitStateMax();
    write_volatile_4(CMU->HFCLKSEL,uVar4);
    uVar1 = CMU_ClockFreqGet(cmuClock_HFLE);
    _DAT_43c80040 = (uint)(32000000 < uVar1);
    _DAT_43c82060 = _DAT_43c80040;
    EMU_UpdateOscConfig();
    uVar1 = SystemCoreClockGet();
    flashWaitStateControl(uVar1);
    return;
  case 2:
    puVar3 = &CMU->LFACLKSEL;
    break;
  case 3:
    puVar3 = &CMU->LFBCLKSEL;
    break;
  default:
    goto switchD_000044d2_caseD_4;
  case 5:
    puVar3 = &CMU->LFECLKSEL;
  }
  if (true) {
    switch(ref) {
    case cmuSelect_Disabled:
      uVar4 = 0;
      break;
    case cmuSelect_LFXO:
      CMU_OscillatorEnable(cmuOsc_LFXO,true,true);
      uVar4 = 2;
      break;
    case cmuSelect_LFRCO:
      CMU_OscillatorEnable(cmuOsc_LFRCO,true,true);
      uVar4 = 1;
      break;
    default:
      goto switchD_000044d2_caseD_4;
    case cmuSelect_HFCLKLE:
      uVar4 = SystemCoreClockGet();
      _DAT_43c80040 = (uint)(32000000 < uVar4);
      _DAT_43c81600 = 1;
      uVar4 = 3;
      _DAT_43c82060 = _DAT_43c80040;
      break;
    case cmuSelect_ULFRCO:
      uVar4 = 4;
    }
    *puVar3 = uVar4;
  }
switchD_000044d2_caseD_4:
  return;
}



void CMU_HFXOInit(CMU_HFXOInit_TypeDef *hfxoInit)

{
  uint uVar1;
  
  CMU_ClockSelectGet(cmuClock_HF);
  CMU_OscillatorEnable(cmuOsc_HFXO,false,true);
  if (hfxoInit->lowPowerMode == false) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x100;
  }
  if (hfxoInit->mode == cmuOscMode_External) {
    uVar1 = uVar1 | 1;
  }
  write_volatile_4(Peripherals::CMU_CLR.HFXOCTRL,0x101);
  write_volatile_4(Peripherals::CMU_SET.HFXOCTRL,uVar1);
  write_volatile_4(Peripherals::CMU_CLR.HFXOCTRL1,7);
  write_volatile_4(Peripherals::CMU_SET.HFXOCTRL1,(uint)hfxoInit->thresholdPeakDetect);
  write_volatile_4(Peripherals::CMU_CLR.HFXOSTARTUPCTRL,0xff87f);
  write_volatile_4(Peripherals::CMU_SET.HFXOSTARTUPCTRL,
                   (uint)hfxoInit->xoCoreBiasTrimStartup | (uint)hfxoInit->ctuneStartup << 0xb);
  uVar1 = hfxoInit->regIshSteadyState + 3;
  if (0xe < uVar1) {
    uVar1 = 0xf;
  }
  write_volatile_4(Peripherals::CMU_CLR.HFXOSTEADYSTATECTRL,0xf00fffff);
  write_volatile_4(Peripherals::CMU_SET.HFXOSTEADYSTATECTRL,
                   (uint)hfxoInit->regIshSteadyState << 7 | (uint)hfxoInit->ctuneSteadyState << 0xb
                   | (uint)hfxoInit->xoCoreBiasTrimSteadyState | uVar1 << 0x1c);
  write_volatile_4(Peripherals::CMU_CLR.HFXOTIMEOUTCTRL,0xff0ff);
  write_volatile_4(Peripherals::CMU_SET.HFXOTIMEOUTCTRL,
                   (uint)hfxoInit->timeoutPeakDetect << 0xc |
                   (uint)hfxoInit->timeoutShuntOptimization << 0x10 | (uint)hfxoInit->timeoutStartup
                   | (uint)hfxoInit->timeoutSteady << 4);
  return;
}



CORE_irqState_t CORE_EnterCritical(void)

{
  bool bVar1;
  CORE_irqState_t CVar2;
  
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



undefined4 CORE_EnterAtomic(void)

{
  bool bVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  return uVar2;
}



void CORE_ExitAtomic(CORE_irqState_t irqState)

{
  if (irqState == 0) {
    enableIRQinterrupts();
  }
  return;
}



void emuRestore(void)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  
  uVar1 = read_volatile_4(CMU->LOCK);
  write_volatile_4(CMU->LOCK,0x580e);
  write_volatile_4(CMU->OSCENCMD,cmuStatus & 0x155);
  uVar2 = cmuHfclkStatus & 7;
  if (uVar2 == 3) {
    uVar3 = read_volatile_4(CMU->HFXOCTRL);
    if ((int)(uVar3 << 2) < 0) goto LAB_00004710;
    do {
      uVar3 = read_volatile_4(CMU->STATUS);
    } while (-1 < (int)(uVar3 << 0x18));
    uVar3 = 3;
  }
  else {
    if (uVar2 != 4) {
      if (uVar2 == 2) {
        do {
          uVar3 = read_volatile_4(CMU->STATUS);
        } while (-1 < (int)(uVar3 << 0x1c));
        uVar3 = read_volatile_4(CMU->HFXOCTRL);
        if ((uVar3 & 0x30) == 0) {
          do {
            uVar3 = read_volatile_4(CMU->STATUS);
          } while ((uVar3 & 0xc00000) != 0xc00000);
        }
        write_volatile_4(CMU->HFCLKSEL,2);
      }
      goto LAB_00004710;
    }
    do {
      uVar3 = read_volatile_4(CMU->STATUS);
    } while (-1 < (int)(uVar3 << 0x16));
    uVar3 = 4;
  }
  write_volatile_4(CMU->HFCLKSEL,uVar3);
LAB_00004710:
  if ((uVar1 & 1) != 0) {
    write_volatile_4(CMU->LOCK,0);
  }
  return;
}



void currentLimitersUpdate(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = read_volatile_4(EMU->.DCDCMISCCTRL);
  uVar2 = ((uVar1 << 0x14) >> 0x1c) + 1;
  uVar1 = read_volatile_4(EMU->.DCDCMISCCTRL);
  uVar3 = (dcdcMaxCurrent_mA + 0x28 + (dcdcMaxCurrent_mA + 0x28 >> 1)) / (uVar2 * 5) - 1;
  if (6 < uVar3) {
    uVar3 = 7;
  }
  write_volatile_4(EMU->.DCDCMISCCTRL,uVar1 & 0xf88fffff | 0x100000 | uVar3 << 0x18);
  if (-1 < dcdcReverseCurrentControl) {
    iVar4 = dcdcReverseCurrentControl + 0x28;
    uVar2 = (uint)(iVar4 + (iVar4 >> 1)) / ((uVar2 >> 1) + uVar2 * 2);
    uVar1 = read_volatile_4(EMU->.DCDCZDETCTRL);
    if (6 < uVar2) {
      uVar2 = 7;
    }
    write_volatile_4(EMU->.DCDCZDETCTRL,uVar1 & 0xffffff8f | uVar2 << 4);
  }
  return;
}



void dcdcHsFixLnBlock(void)

{
  uint uVar1;
  int iVar2;
  
  if (errataFixDcdcHsState - 1 < 2) {
    uVar1 = read_volatile_4(EMU->.DCDCCTRL);
    if ((uVar1 & 3) == 1) {
      do {
        iVar2 = read_volatile_4(EMU->._124_4_);
      } while (-1 < iVar2 << 0xf);
    }
    errataFixDcdcHsState = errataFixDcdcHsLnWaitDone;
  }
  return;
}



void dcdcFetCntSet(_Bool lpModeSet)

{
  uint uVar1;
  
  dcdcFetCntSet::emuDcdcMiscCtrlReg = read_volatile_4(EMU->.DCDCMISCCTRL);
  uVar1 = read_volatile_4(EMU->.DCDCMISCCTRL);
  write_volatile_4(EMU->.DCDCMISCCTRL,uVar1 & 0xffff00ff | 0x7700);
  currentLimitersUpdate(lpModeSet);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void EMU_EnterEM2(_Bool restore)

{
  uint uVar1;
  
  cmuStatus = read_volatile_4(CMU->STATUS);
  uVar1 = read_volatile_4(CMU->HFCLKSTATUS);
  cmuHfclkStatus = (uint16_t)uVar1;
  _DAT_e000ed10 = _DAT_e000ed10 | 4;
  dcdcFetCntSet(restore);
  dcdcHsFixLnBlock();
  WaitForInterrupt();
  write_volatile_4(EMU->.DCDCMISCCTRL,dcdcFetCntSet::emuDcdcMiscCtrlReg);
  currentLimitersUpdate();
  if (restore != false) {
    emuRestore();
    return;
  }
  if ((cmuHfclkStatus & 7) != 1) {
    SystemCoreClockGet();
    return;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void EMU_EnterEM3(_Bool restore)

{
  uint uVar1;
  bool bVar2;
  
  cmuStatus = read_volatile_4(CMU->STATUS);
  uVar1 = read_volatile_4(CMU->HFCLKSTATUS);
  cmuHfclkStatus = (uint16_t)uVar1;
  uVar1 = read_volatile_4(CMU->LOCK);
  uVar1 = uVar1 << 0x1f;
  bVar2 = (int)uVar1 < 0;
  write_volatile_4(CMU->LOCK,0x580e);
  if (bVar2) {
    uVar1 = 0;
  }
  write_volatile_4(CMU->OSCENCMD,0x280);
  if (bVar2) {
    write_volatile_4(CMU->LOCK,uVar1);
  }
  _DAT_e000ed10 = _DAT_e000ed10 | 4;
  dcdcFetCntSet(true);
  dcdcHsFixLnBlock();
  WaitForInterrupt();
  write_volatile_4(EMU->.DCDCMISCCTRL,dcdcFetCntSet::emuDcdcMiscCtrlReg);
  currentLimitersUpdate();
  if (restore != false) {
    emuRestore();
    return;
  }
  if ((cmuHfclkStatus & 7) != 1) {
    SystemCoreClockGet();
    return;
  }
  return;
}



void EMU_UpdateOscConfig(void)

{
  uint uVar1;
  
  cmuStatus = read_volatile_4(CMU->STATUS);
  uVar1 = read_volatile_4(CMU->HFCLKSTATUS);
  cmuHfclkStatus = (uint16_t)uVar1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void EMU_DCDCModeSet(EMU_DcdcMode_TypeDef dcdcMode)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (uint)dcdcMode;
  uVar1 = read_volatile_4(EMU->.DCDCCTRL);
  if ((uVar1 & 3) != uVar3) {
    do {
      uVar2 = read_volatile_4(EMU->.DCDCSYNC);
    } while ((int)(uVar2 << 0x1f) < 0);
    _DAT_43c60ab4 = uVar3;
    if (uVar3 != 0) {
      _DAT_43c60ab4 = 1;
    }
    if (((uVar1 & 3) == 0) && (uVar3 == 1)) {
      errataFixDcdcHsState = errataFixDcdcHsBypassLn;
    }
    uVar1 = read_volatile_4(EMU->.DCDCCTRL);
    write_volatile_4(EMU->.DCDCCTRL,uVar3 | uVar1 & 0xfffffffc);
  }
  return;
}



void EMU_EnterEM4(void)

{
  uint uVar1;
  undefined lpModeSet;
  uint uVar2;
  uint uVar3;
  
  uVar2 = read_volatile_4(EMU->.EM4CTRL);
  uVar3 = read_volatile_4(EMU->.EM4CTRL);
  write_volatile_4(EMU->.LOCK,0xade8);
  uVar1 = read_volatile_4(EMU->.EM4CTRL);
  lpModeSet = (undefined)(uVar1 & 1);
  uVar2 = uVar2 & 0xfffcffff | 0x20000;
  uVar3 = uVar3 | 0x30000;
  if (((uVar1 & 1) == 0) &&
     (uVar1 = read_volatile_4(EMU->.DCDCCTRL), (uVar1 & 3) - 1 < 2)) {
    EMU_DCDCModeSet(emuDcdcMode_Bypass);
  }
  uVar1 = read_volatile_4(EMU->.EM4CTRL);
  if ((int)(uVar1 << 0x1f) < 0) {
    disableIRQinterrupts();
    write_volatile_4(EMU->.TESTLOCK,0xade8);
    uVar1 = read_volatile_4(EMU->._408_4_);
    write_volatile_4(EMU->._408_4_,uVar1 | 0x80);
    uVar1 = read_volatile_4(EMU->._136_4_);
    write_volatile_4(EMU->._136_4_,uVar1 | 0x100);
  }
  dcdcFetCntSet((_Bool)lpModeSet);
  dcdcHsFixLnBlock();
  write_volatile_4(EMU->.EM4CTRL,uVar2);
  write_volatile_4(EMU->.EM4CTRL,uVar3);
  write_volatile_4(EMU->.EM4CTRL,uVar2);
  write_volatile_4(EMU->.EM4CTRL,uVar3);
  write_volatile_4(EMU->.EM4CTRL,uVar2);
  write_volatile_4(EMU->.EM4CTRL,uVar3);
  write_volatile_4(EMU->.EM4CTRL,uVar2);
  write_volatile_4(EMU->.EM4CTRL,uVar3);
  write_volatile_4(EMU->.EM4CTRL,uVar2);
  return;
}



_Bool EMU_DCDCOutputVoltageSet(uint32_t mV,_Bool setLpVoltage,_Bool setLnVoltage)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  
  uVar6 = read_volatile_4(EMU->.PWRCFG);
  if ((uVar6 & 0xf) != 2) {
    return false;
  }
  if (0x4b0 < mV - 0x708) {
    return false;
  }
  bVar1 = false;
  uVar6 = 0;
  uVar4 = 0;
  if (setLpVoltage == false) goto LAB_00004a06;
  uVar5 = read_volatile_4(EMU->.DCDCMISCCTRL);
  uVar7 = (uint)(mV != 0x708);
  uVar5 = uVar5 & 0x30000000;
  uVar3 = uVar5 | uVar7;
  uVar2 = 3000;
  if (mV != 0x708) {
    uVar10 = 0x708;
  }
  else {
    uVar2 = 0x708;
    uVar10 = 0x4b0;
  }
  if (uVar3 == 0x10000001) {
    uVar4 = read_volatile_4(DAT_0fe08324);
LAB_00004b7c:
    uVar6 = uVar4 >> 0x18;
    uVar4 = (uVar4 << 8) >> 0x18;
  }
  else {
    if (uVar3 < 0x10000002) {
      if (uVar3 == 1) {
        uVar4 = read_volatile_4(DAT_0fe08324);
      }
      else {
        if (uVar3 != 0) {
          if (uVar3 != 0x10000000) goto LAB_00004a44;
          uVar4 = read_volatile_4(DAT_0fe0831c);
          goto LAB_00004b7c;
        }
        uVar4 = read_volatile_4(DAT_0fe0831c);
      }
    }
    else {
      if (uVar3 == 0x20000001) {
        uVar4 = read_volatile_4(DAT_0fe08328);
      }
      else {
        if (0x20000001 < uVar3) {
          if (uVar3 == 0x30000000) {
            uVar4 = read_volatile_4(DAT_0fe08320);
          }
          else {
            if (uVar3 != 0x30000001) goto LAB_00004a44;
            uVar4 = read_volatile_4(DAT_0fe08328);
          }
          goto LAB_00004b7c;
        }
        if (uVar3 != 0x20000000) goto LAB_00004a44;
        uVar4 = read_volatile_4(DAT_0fe08320);
      }
    }
    uVar6 = (uVar4 << 0x10) >> 0x18;
    uVar4 = uVar4 & 0xff;
  }
LAB_00004a44:
  uVar3 = read_volatile_4(DAT_0fe08200);
  if ((uVar3 & 0xff) < 4) {
    uVar3 = read_volatile_4(DAT_0fe0832c);
    if (mV == 0x708) {
LAB_00004ad0:
      uVar3 = uVar3 & 0xff;
      goto LAB_00004ad2;
    }
  }
  else {
    uVar3 = read_volatile_4(DAT_0fe08330);
    if (uVar5 != 0x10000000) {
      if (0x10000000 < uVar5) {
        if (uVar5 == 0x20000000) {
          uVar3 = (uVar3 << 8) >> 0x18;
        }
        else {
          if (uVar5 != 0x30000000) {
            return false;
          }
          uVar3 = uVar3 >> 0x18;
        }
        goto LAB_00004ad2;
      }
      if (uVar5 != 0) {
        return false;
      }
      goto LAB_00004ad0;
    }
  }
  uVar3 = (uVar3 << 0x10) >> 0x18;
LAB_00004ad2:
  if ((uVar3 << 0xc & 0xf0000) == 0) {
    uVar5 = read_volatile_4(EMU->.DCDCLPCTRL);
    write_volatile_4(EMU->.DCDCLPCTRL,uVar5 & 0xffff0fff | uVar3 << 0xc);
    if (uVar10 < uVar2) {
      puVar8 = &EMU->.DCDCLPVCTRL;
      iVar9 = 1;
      while( true ) {
        uVar2 = ((uVar6 - uVar4) * (mV - uVar10)) / (uVar2 - uVar10);
        uVar5 = uVar4 + uVar2;
        if ((uVar6 < uVar5) || (CARRY4(uVar4,uVar2) != false)) break;
        *puVar8 = uVar5 << iVar9 | uVar7;
        do {
          if (bVar1) {
            return (_Bool)bVar1;
          }
LAB_00004a06:
          bVar1 = true;
        } while (setLnVoltage == false);
        if (mV == 0x708) {
          uVar4 = read_volatile_4(DAT_0fe08318);
          uVar6 = uVar4 << 0x10;
          uVar10 = 0x4b0;
          uVar4 = uVar4 & 0xff;
          uVar7 = 0;
          uVar2 = mV;
        }
        else {
          uVar6 = read_volatile_4(DAT_0fe08318);
          uVar7 = 2;
          uVar2 = 3000;
          uVar4 = (uVar6 << 8) >> 0x18;
          uVar10 = 0x708;
        }
        uVar6 = uVar6 >> 0x18;
        puVar8 = &EMU->.DCDCLNVCTRL;
        iVar9 = 8;
      }
    }
  }
  return false;
}



void EMU_DCDCOptimizeSlice(uint32_t em0LoadCurrent_mA)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  
  uVar1 = read_volatile_4(EMU->.DCDCLNFREQCTRL);
  uVar2 = read_volatile_4(EMU->.DCDCMISCCTRL);
  uVar1 = uVar1 & 7;
  if (((int)(uVar2 << 0x1f) < 0) && (1 < uVar1)) {
    if (em0LoadCurrent_mA < 0x14) {
LAB_00004bfe:
      uVar2 = 4;
      goto LAB_00004bc0;
    }
    bVar4 = 0x12 < em0LoadCurrent_mA - 0x14;
    bVar3 = em0LoadCurrent_mA - 0x14 == 0x13;
  }
  else {
    uVar2 = read_volatile_4(EMU->.DCDCMISCCTRL);
    if (((int)(uVar2 << 0x1f) < 0) || (1 < uVar1)) {
      uVar2 = read_volatile_4(EMU->.DCDCMISCCTRL);
      uVar2 = uVar2 & 1;
      if (uVar2 == 0) goto LAB_00004bc0;
      if (1 < uVar1) {
        uVar2 = 0;
        goto LAB_00004bc0;
      }
      bVar4 = 0x26 < em0LoadCurrent_mA;
      bVar3 = em0LoadCurrent_mA == 0x27;
    }
    else {
      if (em0LoadCurrent_mA < 10) goto LAB_00004bfe;
      bVar4 = 8 < em0LoadCurrent_mA - 10;
      bVar3 = em0LoadCurrent_mA - 10 == 9;
    }
  }
  if (bVar4 && !bVar3) {
    uVar2 = 0x10;
  }
  else {
    uVar2 = 8;
  }
LAB_00004bc0:
  uVar1 = read_volatile_4(EMU->.DCDCMISCCTRL);
  write_volatile_4(EMU->.DCDCMISCCTRL,
                   (uVar2 - 1) * 0x1000 | (uVar2 - 1) * 0x100 | uVar1 & 0xffff00ff);
  currentLimitersUpdate();
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void EMU_DCDCLnRcoBandSet(EMU_DcdcLnRcoBand_TypeDef band)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(EMU->.DCDCLNFREQCTRL);
  write_volatile_4(EMU->.DCDCLNFREQCTRL,(uint)band | uVar1 & 0xfffffff8);
  EMU_DCDCOptimizeSlice((uint)dcdcEm01LoadCurrent_mA);
  return;
}



// WARNING: Could not reconcile some variable overlaps
// WARNING: Globals starting with '_' overlap smaller symbols at the same address

_Bool EMU_DCDCInit(EMU_DCDCInit_TypeDef *dcdcInit)

{
  ushort uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint *puVar4;
  _Bool _Var5;
  uint uVar6;
  int iVar7;
  undefined4 in_r1;
  uint uVar8;
  SYSTEM_ChipRevision_TypeDef rev;
  
  rev._1_2_ = (undefined2)((uint)in_r1 >> 8);
  write_volatile_4(EMU->.PWRCFG,(uint)dcdcInit->powerConfig);
  uVar6 = read_volatile_4(EMU->.PWRCFG);
  if ((uint)dcdcInit->powerConfig != (uVar6 & 0xf)) {
    return false;
  }
  iVar7 = read_volatile_4(DAT_0fe0831c);
  if (iVar7 != -1) {
    uVar3 = read_volatile_4(Peripherals::DEVINFO._60_4_);
    puVar2 = (undefined4 *)read_volatile_4(Peripherals::DEVINFO._56_4_);
    *puVar2 = uVar3;
    uVar6 = read_volatile_4(Peripherals::DEVINFO.UNIQUEH);
    puVar4 = (uint *)read_volatile_4(Peripherals::DEVINFO.UNIQUEL);
    *puVar4 = uVar6;
    uVar6 = read_volatile_4(Peripherals::DEVINFO.PART);
    puVar4 = (uint *)read_volatile_4(Peripherals::DEVINFO.MSIZE);
    *puVar4 = uVar6;
    uVar6 = read_volatile_4(Peripherals::DEVINFO.EMUTEMP);
    puVar4 = (uint *)read_volatile_4(Peripherals::DEVINFO.DEVINFOREV);
    *puVar4 = uVar6;
    uVar3 = read_volatile_4(Peripherals::DEVINFO._92_4_);
    puVar2 = (undefined4 *)read_volatile_4(Peripherals::DEVINFO._88_4_);
    *puVar2 = uVar3;
    uVar6 = read_volatile_4(Peripherals::DEVINFO.ADC0CAL1);
    puVar4 = (uint *)read_volatile_4(Peripherals::DEVINFO.ADC0CAL0);
    *puVar4 = uVar6;
  }
  uVar1 = dcdcInit->em234LoadCurrent_uA;
  if (uVar1 < 0x4b) {
    uVar6 = 0;
  }
  else {
    if (uVar1 < 500) {
      uVar6 = 0x10000000;
    }
    else {
      if (uVar1 < 0x9c4) {
        uVar6 = 0x20000000;
      }
      else {
        uVar6 = 0x30000000;
      }
    }
  }
  uVar8 = read_volatile_4(EMU->.DCDCMISCCTRL);
  uVar8 = uVar8 & 0xcffffffe;
  if (-1 < dcdcInit->reverseCurrentControl) {
    uVar8 = uVar8 | 1;
  }
  write_volatile_4(EMU->.DCDCMISCCTRL,uVar8 | uVar6);
  uVar6 = read_volatile_4(EMU->.DCDCLPCTRL);
  write_volatile_4(EMU->.DCDCLPCTRL,uVar6 | 0x1000000);
  iVar7 = _DAT_43c60980;
  if (_DAT_43c60980 != 0) {
    iVar7 = 4;
  }
  EMU_DCDCLnRcoBandSet((EMU_DcdcLnRcoBand_TypeDef)iVar7);
  uVar6 = read_volatile_4(EMU->.DCDCTIMING);
  write_volatile_4(EMU->.DCDCTIMING,uVar6 & 0x9fffffff);
  uVar6 = read_volatile_4(EMU->.DCDCMISCCTRL);
  write_volatile_4(EMU->.DCDCMISCCTRL,uVar6 | 6);
  iVar7 = read_volatile_4(DAT_0fe081fc);
  uVar6 = (uint)(iVar7 << 8) >> 0x18;
  rev._0_2_ = rev._1_2_;
  SYSTEM_ChipRevisionGet(&rev);
  if ((((uVar6 - 0x10 < 0xc) || ((uVar6 & 0xfd) == 0x51)) && (rev.major == '\x01')) &&
     ((rev.minor < 3 && (errataFixDcdcHsState == errataFixDcdcHsInit)))) {
    uVar6 = read_volatile_4(EMU->._68_4_);
    write_volatile_4(EMU->._68_4_,uVar6 | 1);
    uVar6 = read_volatile_4(EMU->.DCDCTIMING);
    write_volatile_4(EMU->.DCDCTIMING,uVar6 & 0xf00e0f00 | 0xb40c0b4);
    errataFixDcdcHsState = rev.major;
  }
  dcdcMaxCurrent_mA = dcdcInit->maxCurrent_mA;
  dcdcReverseCurrentControl = dcdcInit->reverseCurrentControl;
  dcdcEm01LoadCurrent_mA = dcdcInit->em01LoadCurrent_mA;
  EMU_DCDCOptimizeSlice((uint)dcdcEm01LoadCurrent_mA);
  if (dcdcInit->dcdcLnCompCtrl == emuDcdcLnCompCtrl_1u0F) {
    uVar6 = 0x57204077;
  }
  else {
    if (dcdcInit->dcdcLnCompCtrl != emuDcdcLnCompCtrl_4u7F) goto LAB_00004d5c;
    uVar6 = 0xb7102137;
  }
  write_volatile_4(EMU->.DCDCLNCOMPCTRL,uVar6);
LAB_00004d5c:
  _Var5 = EMU_DCDCOutputVoltageSet((uint)dcdcInit->mVout,true,true);
  if (_Var5 == false) {
    return false;
  }
  _DAT_43c60794 = (uint)dcdcInit->anaPeripheralPower;
  if (_DAT_43c60794 != 0) {
    _DAT_43c60794 = 1;
  }
  EMU_DCDCModeSet(dcdcInit->dcdcMode);
  return _Var5;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void GPIO_ExtIntConfig(GPIO_Port_TypeDef port,uint pin,uint intNo,_Bool risingEdge,_Bool fallingEdge
                      ,_Bool enable)

{
  uint *puVar1;
  uint uVar2;
  
  if (intNo < 8) {
    uVar2 = intNo << 2;
    _DAT_4400a400 = 0xf << (uVar2 & 0xff);
    _DAT_4600a400 = (uint)port << (uVar2 & 0xff);
    _DAT_4400a408 = 3 << (uVar2 & 0xff);
    _DAT_4600a408 = (pin & 3) << (uVar2 & 0xff);
  }
  else {
    uVar2 = (intNo - 8) * 4;
    _DAT_4400a404 = 0xf << (uVar2 & 0xff);
    _DAT_4600a404 = (uint)port << (uVar2 & 0xff);
    _DAT_4400a40c = 3 << (uVar2 & 0xff);
    _DAT_4600a40c = (pin & 3) << (uVar2 & 0xff);
  }
  puVar1 = (uint *)((intNo + 0x10852080) * 4);
  *puVar1 = (uint)risingEdge;
  puVar1[0x20] = (uint)fallingEdge;
  write_volatile_4(Peripherals::GPIO.IFC,1 << (intNo & 0xff));
  puVar1[0xc0] = (uint)enable;
  return;
}



void GPIO_PinModeSet(GPIO_Port_TypeDef port,uint pin,GPIO_Mode_TypeDef mode,uint out)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  uVar2 = (uint)mode;
  uVar1 = (uint)port;
  if (uVar2 != 0) {
    puVar3 = (undefined4 *)((pin + (uVar1 * 0x30 + 0x4210a00c) * 8) * 4);
    if (out == 0) {
      *puVar3 = 0;
    }
    else {
      *puVar3 = 1;
    }
  }
  if (pin < 8) {
    (&Peripherals::GPIO.PA_MODEL)[uVar1 * 0xc] =
         (&Peripherals::GPIO.PA_MODEL)[uVar1 * 0xc] & ~(0xf << (pin << 2 & 0xff)) |
         uVar2 << (pin << 2 & 0xff);
  }
  else {
    uVar4 = (pin + 0x3ffffff8) * 4;
    (&Peripherals::GPIO.PA_MODEH)[uVar1 * 0xc] =
         uVar2 << (uVar4 & 0xff) |
         (&Peripherals::GPIO.PA_MODEH)[uVar1 * 0xc] & ~(0xf << (uVar4 & 0xff));
  }
  if (uVar2 == 0) {
    if (out != 0) {
      out = 1;
    }
    *(uint *)((pin + (uVar1 * 0x30 + 0x4210a00c) * 8) * 4) = out;
  }
  return;
}



void RMU_ResetCauseClear(void)

{
  write_volatile_4(Peripherals::RMU.CMD,1);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint RMU_ResetCauseGet(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  
  uVar2 = read_volatile_4(Peripherals::RMU.RSTCAUSE);
  iVar6 = 0;
  uVar3 = 0;
  do {
    uVar4 = *(uint *)((int)&resetCauseMasks[0].resetCauseZeroXMask + iVar6);
    uVar5 = *(uint *)((int)&resetCauseMasks[0].resetCauseMask + iVar6);
    if ((_DAT_0fe041e8 & 4) == 0) {
      if (uVar5 != 0x400) {
        if (uVar5 < 0x401) {
          bVar7 = uVar5 == 0x200;
        }
        else {
          if (uVar5 == 0x800) goto LAB_00004f36;
          bVar7 = uVar5 == 0x10000;
        }
        if (!bVar7) goto LAB_00004f3a;
      }
LAB_00004f36:
      uVar4 = uVar4 | 0x100;
    }
LAB_00004f3a:
    uVar1 = read_volatile_4(EMU->._136_4_);
    if ((uVar1 & 0x100) != 0) {
      uVar4 = uVar4 & 0xffffffe3;
    }
    if (((uVar2 & uVar5) != 0) && ((uVar4 & uVar2) == 0)) {
      uVar3 = uVar3 | uVar5;
    }
    iVar6 = iVar6 + 8;
    if (iVar6 == 0x48) {
      if ((int)(uVar3 << 0xf) < 0) {
        uVar3 = uVar3 & 0xffffffe3;
      }
      return uVar3;
    }
  } while( true );
}



void RTCC_ChannelInit(int ch,RTCC_CCChConf_TypeDef *confPtr)

{
  (&Peripherals::RTCC.CC0_CTRL)[ch * 4] =
       (uint)confPtr->prsSel << 6 | (uint)confPtr->compMatchOutAction << 2 | (uint)confPtr->chMode |
       (uint)confPtr->inputEdgeSel << 4 | (uint)confPtr->compBase << 0xb |
       (uint)confPtr->compMask << 0xc | (uint)confPtr->dayCompMode << 0x11;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RTCC_Enable(_Bool enable)

{
  _DAT_42840000 = (uint)enable;
  return;
}



void RTCC_Init(RTCC_Init_TypeDef *init)

{
  write_volatile_4(Peripherals::RTCC.CTRL,
                   (uint)init->precntWrapOnCCV0 << 4 | (uint)init->debugRun << 2 |
                   (uint)init->enable | (uint)init->cntWrapOnCCV1 << 5 | (uint)init->presc << 8 |
                   (uint)init->prescMode << 0xc | (uint)init->enaOSCFailDetect << 0xf |
                   (uint)init->cntMode << 0x10 | (uint)init->disLeapYearCorr << 0x11);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void SYSTEM_ChipRevisionGet(SYSTEM_ChipRevision_TypeDef *rev)

{
  rev->family = (byte)(_DAT_e00fffe4 << 2) & 0x3c | (byte)_DAT_e00fffe0 >> 6;
  rev->major = (byte)_DAT_e00fffe0 & 0x3f;
  rev->minor = (byte)_DAT_e00fffe8 & 0xf0 | (byte)_DAT_e00fffec >> 4;
  return;
}



void TIMER_Init(TIMER_TypeDef *timer,TIMER_Init_TypeDef *init)

{
  _Bool _Var1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  _Var1 = init->enable;
  if (_Var1 == false) {
    timer->CMD = 2;
  }
  timer->CNT = 0;
  if (init->debugRun == false) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0x40;
  }
  if (init->dmaClrAct == false) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0x80;
  }
  if (init->quadModeX4 == false) {
    uVar5 = 0;
  }
  else {
    uVar5 = 0x20;
  }
  if (init->oneShot == false) {
    uVar6 = 0;
  }
  else {
    uVar6 = 0x10;
  }
  if (init->count2x == false) {
    uVar7 = 0;
  }
  else {
    uVar7 = 0x2000;
  }
  if (init->ati == false) {
    uVar8 = 0;
  }
  else {
    uVar8 = 0x10000000;
  }
  if (init->sync == false) {
    uVar2 = 0;
  }
  else {
    uVar2 = 8;
  }
  timer->CTRL = (uint)init->clkSel << 0x10 | (uint)init->prescale << 0x18 | (uint)init->mode |
                (uint)init->fallAction << 10 | (uint)init->riseAction << 8 | uVar3 | uVar4 | uVar5 |
                uVar6 | uVar7 | uVar8 | uVar2;
  if (_Var1 != false) {
    timer->CMD = 1;
  }
  return;
}



void TIMER_InitCC(TIMER_TypeDef *timer,uint ch,TIMER_InitCC_TypeDef *init)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (init->filter == false) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x40000000;
  }
  if (init->prsInput == false) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0x20000000;
  }
  if (init->coist == false) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0x10;
  }
  if (init->outInvert == false) {
    uVar1 = 0;
  }
  else {
    uVar1 = 4;
  }
  timer->CC[ch].CTRL =
       (uint)init->edge << 0x18 | (uint)init->eventCtrl << 0x1a | (uint)init->mode |
       (uint)init->prsSel << 0x10 | (uint)init->cufoa << 0xc | (uint)init->cofoa << 10 |
       (uint)init->cmoa << 8 | uVar2 | uVar3 | uVar4 | uVar1;
  return;
}



void USART_BaudrateAsyncSet
               (USART_TypeDef *usart,uint32_t refFreq,uint32_t baudrate,USART_OVS_TypeDef ovs)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)ovs;
  if (refFreq == 0) {
    refFreq = CMU_ClockFreqGet(cmuClock_HFPER);
  }
  if (uVar2 == 0x20) {
    iVar1 = 8;
  }
  else {
    if (uVar2 < 0x21) {
      if (uVar2 != 0) {
        return;
      }
      iVar1 = 0x10;
    }
    else {
      if (uVar2 == 0x40) {
        iVar1 = 6;
      }
      else {
        if (uVar2 != 0x60) {
          return;
        }
        iVar1 = 4;
      }
    }
  }
  usart->CTRL = usart->CTRL & 0xffffff9f;
  usart->CTRL = uVar2 | usart->CTRL;
  usart->CLKDIV =
       (((baudrate * iVar1 >> 1) + refFreq * 0x20) / (baudrate * iVar1) - 0x20) * 8 & 0x7ffff8;
  return;
}



void USART_BaudrateSyncSet(USART_TypeDef *usart,uint32_t refFreq,uint32_t baudrate)

{
  int iVar1;
  
  if (refFreq == 0) {
    refFreq = CMU_ClockFreqGet(cmuClock_HFPER);
  }
  iVar1 = __aeabi_uldivmod(refFreq << 7,refFreq >> 0x19,baudrate,0);
  usart[0x80000].CLKDIV = 0x7ffff8;
  usart[0xc0000].CLKDIV = iVar1 - 0x80U & 0x7fff00;
  return;
}



void USART_Enable(USART_TypeDef *usart,USART_Enable_TypeDef enable)

{
  usart->CMD = (~(uint)enable & 5) << 1;
  usart->CMD = (uint)enable;
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
    usart->IRCTRL = 0;
  }
  usart->INPUT = 0;
  if (usart == (USART_TypeDef *)&Peripherals::USART1) {
    usart->I2SCTRL = 0;
  }
  return;
}



void USART_InitAsync(USART_TypeDef *usart,USART_InitAsync_TypeDef *init)

{
  USART_TypeDef *pUVar1;
  int extraout_r1;
  
  pUVar1 = usart;
  USART_Reset(usart);
  if (*(char *)(extraout_r1 + 0x12) != '\0') {
    pUVar1->CTRL = pUVar1->CTRL | 0x40000000;
  }
  if (init->prsRxEnable != false) {
    usart->INPUT = init->prsRxCh | 0x80;
  }
  usart->FRAME = (uint)init->databits | (uint)init->stopbits | (uint)init->parity;
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
  _Bool _Var1;
  USART_TypeDef *pUVar2;
  int extraout_r1;
  uint uVar3;
  
  pUVar2 = usart;
  USART_Reset(usart);
  if (*(char *)(extraout_r1 + 0xe) == '\0') {
    uVar3 = 0;
  }
  else {
    uVar3 = 0x400;
  }
  _Var1 = init->autoTx;
  pUVar2->CTRL = pUVar2->CTRL | *(ushort *)(extraout_r1 + 0x10) | 1 | uVar3;
  if (_Var1 == false) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0x20000000;
  }
  pUVar2->CTRL = pUVar2->CTRL | uVar3;
  if (init->prsRxEnable != false) {
    pUVar2->INPUT = init->prsRxCh | 0x80;
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



uint8_t USART_Rx(USART_TypeDef *usart)

{
  do {
  } while (-1 < (int)(usart->STATUS << 0x18));
  return (uint8_t)usart->RXDATA;
}



void USART_Tx(USART_TypeDef *usart,uint8_t data)

{
  do {
  } while (-1 < (int)(usart->STATUS << 0x19));
  usart->TXDATA = (uint)data;
  return;
}



void USART_TxDouble(USART_TypeDef *usart,uint16_t data)

{
  do {
  } while (-1 < (int)(usart->STATUS << 0x19));
  usart->TXDOUBLE = (uint)data;
  return;
}



void GPIOINT_IRQDispatcher(uint32_t iflags)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  
  while (iflags != 0) {
    bVar2 = (byte)iflags;
    bVar3 = (byte)(iflags >> 8);
    bVar4 = (byte)(iflags >> 0x10);
    bVar1 = (byte)(iflags >> 0x18);
    uVar5 = count_leading_zeroes
                      ((uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1)
                                        << 1 | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 |
                                     bVar2 >> 5 & 1) << 1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) <<
                       0x18 | (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 |
                                               bVar3 >> 2 & 1) << 1 | bVar3 >> 3 & 1) << 1 |
                                             bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1 |
                                           bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
                       (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1)
                                        << 1 | bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 |
                                     bVar4 >> 5 & 1) << 1 | bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8
                       | (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1
                                          ) << 1 | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 |
                                       bVar1 >> 5 & 1) << 1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7));
    iflags = iflags & ~(1 << (uVar5 & 0xff));
    if (gpioCallbacks[uVar5] != FUN_00000000) {
      (*gpioCallbacks[uVar5])((uint8_t)uVar5);
    }
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void GPIOINT_Init(void)

{
  _DAT_e000e100 = 0x200;
  _DAT_e000e280 = 0x200;
  return;
}



void GPIOINT_CallbackRegister(uint8_t pin,GPIOINT_IrqCallbackPtr_t *callbackPtr)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterAtomic();
  gpioCallbacks[pin] = callbackPtr;
  CORE_ExitAtomic(irqState);
  return;
}



void GPIO_EVEN_IRQHandler(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = read_volatile_4(Peripherals::GPIO.IEN);
  uVar2 = read_volatile_4(Peripherals::GPIO.IF);
  uVar2 = uVar1 & uVar2 & 0x5555;
  write_volatile_4(Peripherals::GPIO.IFC,uVar2);
  GPIOINT_IRQDispatcher(uVar2);
  return;
}



void GPIO_ODD_IRQHandler(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = read_volatile_4(Peripherals::GPIO.IEN);
  uVar2 = read_volatile_4(Peripherals::GPIO.IF);
  uVar2 = uVar1 & uVar2 & 0xaaaa;
  write_volatile_4(Peripherals::GPIO.IFC,uVar2);
  GPIOINT_IRQDispatcher(uVar2);
  return;
}



void halInit(void)

{
  halInitChipSpecific();
  USTIMER_Init();
  RTCDRV_Init();
  return;
}



uint32_t halCommonGetInt32uMillisecondTick(void)

{
  uint32_t uVar1;
  uint64_t in_stack_00000000;
  
  RTCDRV_GetWallClockTicks64();
  uVar1 = RTCDRV_TicksToMsec(in_stack_00000000);
  return uVar1;
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
    uVar1 = iterations._4_4_ | (uint)iterations;
    iterations._0_4_ = (uint)iterations - 1;
    iterations._4_4_ = (iterations._4_4_ - 1) + (uint)bVar2;
  } while (uVar1 != 0);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint8_t halInitChipSpecific(void)

{
  uint8_t uVar1;
  undefined4 uVar2;
  EMU_DCDCInit_TypeDef *pEVar3;
  CMU_HFXOInit_TypeDef *pCVar4;
  undefined4 *puVar5;
  undefined4 local_58;
  undefined4 uStack84;
  undefined local_50 [16];
  undefined local_40 [8];
  undefined2 local_38 [6];
  undefined4 local_2c;
  undefined4 uStack40;
  undefined4 uStack36;
  undefined4 uStack32;
  undefined4 local_1c;
  
  puVar5 = &DAT_00013c30;
  pEVar3 = (EMU_DCDCInit_TypeDef *)local_50;
  do {
    uVar2 = puVar5[1];
    *(undefined4 *)pEVar3 = *puVar5;
    *(undefined4 *)&pEVar3->em01LoadCurrent_mA = uVar2;
    pEVar3 = (EMU_DCDCInit_TypeDef *)&pEVar3->maxCurrent_mA;
    puVar5 = puVar5 + 2;
  } while (puVar5 != &DAT_00013c40);
  puVar5 = &DAT_00013c40;
  pCVar4 = (CMU_HFXOInit_TypeDef *)local_40;
  do {
    uVar2 = puVar5[1];
    *(undefined4 *)pCVar4 = *puVar5;
    *(undefined4 *)&pCVar4->ctuneStartup = uVar2;
    pCVar4 = (CMU_HFXOInit_TypeDef *)&pCVar4->regIshSteadyState;
    puVar5 = puVar5 + 2;
  } while (puVar5 != (undefined4 *)&UNK_00013c50);
  *(undefined2 *)pCVar4 = 0;
  local_2c = 1;
  uStack40 = 1600000;
  uStack36 = 0x60c0106;
  uStack32 = 0x1060b01;
  local_1c = 0xd;
  EMU_DCDCInit((EMU_DCDCInit_TypeDef *)local_50);
  CMU_HFXOInit((CMU_HFXOInit_TypeDef *)local_40);
  RADIO_PTI_Init(&local_2c);
  CMU_ClockSelectSet(cmuClock_HF,cmuSelect_HFXO);
  CMU_OscillatorEnable(cmuOsc_HFRCO,false,false);
  local_58 = 0x640102;
  uStack84 = 0xa0000;
  RADIO_PA_Init((RADIO_PAInit_t *)&local_58);
  CMU_OscillatorEnable(cmuOsc_LFRCO,true,true);
  CMU_ClockSelectSet(cmuClock_LFA,cmuSelect_LFRCO);
  CMU_ClockSelectSet(cmuClock_LFB,cmuSelect_LFRCO);
  CMU_ClockEnable(cmuClock_HFLE,true);
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
  _DAT_42140190 = 0;
  USART_Tx((USART_TypeDef *)&Peripherals::USART1,0xab);
  USART_Rx((USART_TypeDef *)&Peripherals::USART1);
  _DAT_42140190 = 1;
  usecDelay(0x1e);
  _DAT_42140190 = 0;
  USART_Tx((USART_TypeDef *)&Peripherals::USART1,0xb9);
  uVar1 = USART_Rx((USART_TypeDef *)&Peripherals::USART1);
  _DAT_42140190 = 1;
  return uVar1;
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
  *(undefined4 *)((channel + 0x10f30040) * 4) = 0;
  return;
}



void halEnablePrs(uint8_t channel,uint8_t loc,uint8_t source,uint8_t signal)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = (uint)channel;
  CMU_ClockEnable(cmuClock_PRS,true);
  puVar2 = (undefined4 *)((uVar1 + 0x10f30040) * 4);
  *puVar2 = 0;
  (&Peripherals::PRS.CH0_CTRL)[uVar1] = (uint)CONCAT11(source,signal);
  uVar3 = (uint)(channel >> 2);
  iVar4 = (uVar1 & 3) << 3;
  (&Peripherals::PRS.ROUTELOC0)[uVar3] = (&Peripherals::PRS.ROUTELOC0)[uVar3] & ~(0xff << iVar4);
  (&Peripherals::PRS.ROUTELOC0)[uVar3] = (uint)loc << iVar4 | (&Peripherals::PRS.ROUTELOC0)[uVar3];
  *puVar2 = 1;
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
  int iVar2;
  char *pcVar3;
  
  pcVar3 = ptr;
  while ((iVar2 = (int)pcVar3 - (int)ptr, pcVar3 != ptr + len &&
         (iVar1 = RETARGET_ReadChar(), iVar1 != -1))) {
    *pcVar3 = (char)iVar1;
    pcVar3 = pcVar3 + 1;
  }
  if (iVar2 == 0) {
    iVar2 = -1;
  }
  return iVar2;
}



int _write(int file,char *ptr,int len)

{
  char *pcVar1;
  
  for (pcVar1 = ptr; (int)pcVar1 - (int)ptr < len; pcVar1 = pcVar1 + 1) {
    RETARGET_WriteChar(*pcVar1);
  }
  return len;
}



caddr_t _sbrk(int incr)

{
  caddr_t pcVar1;
  int file;
  char *pcVar2;
  
  if (_sbrk::heap_end == (char *)0x0) {
    _sbrk::heap_end = (char *)0x20003140;
  }
  pcVar1 = _sbrk::heap_end;
  pcVar2 = (char *)getMainStackPointer();
  if (pcVar2 < _sbrk::heap_end + incr) {
    file = fileno(*(FILE **)(_impure_ptr + 8));
    _write(file,"Heap and stack collision\n",0x19);
                    // WARNING: Subroutine does not return
    exit(1);
  }
  _sbrk::heap_end = _sbrk::heap_end + incr;
  return pcVar1;
}



void USART0_RX_IRQHandler(void)

{
  uint uVar1;
  int iVar2;
  uint8_t uVar3;
  
  iVar2 = rxWriteIndex;
  uVar1 = read_volatile_4(Peripherals::USART0.STATUS);
  if ((int)(uVar1 << 0x18) < 0) {
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
  if (on != 0) {
    LFtoCRLF = '\x01';
    return;
  }
  LFtoCRLF = '\0';
  return;
}



// WARNING: Could not reconcile some variable overlaps
// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RETARGET_SerialInit(void)

{
  uint uVar1;
  USART_InitAsync_TypeDef init;
  
  CMU_ClockEnable(cmuClock_HFPER,true);
  CMU_ClockEnable(cmuClock_GPIO,true);
  GPIO_PinModeSet(gpioPortA,0,gpioModePushPull,1);
  GPIO_PinModeSet(gpioPortA,1,gpioModeInput,0);
  init._0_4_ = 5;
  init.refFreq = 0;
  init.baudrate = 0x1c200;
  init._12_4_ = 0x500;
  init._16_4_ = 0x1000;
  init._20_4_ = 0;
  CMU_ClockEnable(cmuClock_USART0,true);
  init._0_4_ = init._0_4_ & 0xffffff00;
  USART_InitAsync((USART_TypeDef *)&Peripherals::USART0,&init);
  write_volatile_4(Peripherals::USART0.ROUTEPEN,3);
  uVar1 = read_volatile_4(Peripherals::USART0.ROUTELOC0);
  write_volatile_4(Peripherals::USART0.ROUTELOC0,uVar1 & 0xffffe0e0);
  write_volatile_4(Peripherals::USART0.IFC,4);
  _DAT_e000e280 = 0x800;
  uVar1 = read_volatile_4(Peripherals::USART0.IEN);
  write_volatile_4(Peripherals::USART0.IEN,uVar1 | 4);
  _DAT_e000e100 = 0x800;
  USART_Enable((USART_TypeDef *)&Peripherals::USART0,usartEnable);
  setvbuf(*(FILE **)(_impure_ptr + 8),(char *)0x0,2,0);
  initialized = true;
  return;
}



int RETARGET_ReadChar(void)

{
  byte *pbVar1;
  CORE_irqState_t irqState;
  uint uVar2;
  
  if (initialized == false) {
    RETARGET_SerialInit();
  }
  irqState = CORE_EnterAtomic();
  if (rxCount < 1) {
    uVar2 = 0xffffffff;
  }
  else {
    pbVar1 = rxBuffer + rxReadIndex;
    rxReadIndex = rxReadIndex + 1;
    if (rxReadIndex == 8) {
      rxReadIndex = 0;
    }
    rxCount = rxCount + -1;
    uVar2 = (uint)*pbVar1;
  }
  CORE_ExitAtomic(irqState);
  return uVar2;
}



int RETARGET_WriteChar(char c)

{
  int iVar1;
  
  iVar1 = (int)c;
  if (initialized == false) {
    RETARGET_SerialInit();
  }
  if ((LFtoCRLF != '\0') && (iVar1 == 10)) {
    USART_Tx((USART_TypeDef *)&Peripherals::USART0,'\r');
  }
  USART_Tx((USART_TypeDef *)&Peripherals::USART0,c);
  if ((LFtoCRLF != '\0') && (iVar1 == 0xd)) {
    USART_Tx((USART_TypeDef *)&Peripherals::USART0,'\n');
  }
  return iVar1;
}



void checkAllTimers(uint32_t timeElapsed)

{
  int iVar1;
  Timer_t *pTVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  bool bVar8;
  
  pTVar2 = timer;
  do {
    pTVar2->doCallback = false;
    if (pTVar2->running != false) {
      uVar6 = *(uint *)&pTVar2->remaining;
      iVar7 = *(int *)((int)&pTVar2->remaining + 4);
      bVar8 = iVar7 == 0;
      if (iVar7 == 0) {
        bVar8 = uVar6 <= timeElapsed;
      }
      if (bVar8) {
        if (pTVar2->timerType == rtcdrvTimerTypeOneshot) {
          pTVar2->running = false;
        }
        else {
          uVar3 = uVar6 + *(uint *)&pTVar2->ticks;
          iVar1 = pTVar2->periodicCompensationUsec;
          uVar5 = pTVar2->periodicDriftUsec;
          uVar4 = uVar3 - timeElapsed;
          iVar7 = (iVar7 + *(int *)((int)&pTVar2->ticks + 4) +
                           (uint)CARRY4(uVar6,*(uint *)&pTVar2->ticks)) -
                  (uint)(uVar3 < timeElapsed);
          *(uint *)&pTVar2->remaining = uVar4;
          *(int *)((int)&pTVar2->remaining + 4) = iVar7;
          if (iVar1 < 1) {
            uVar5 = uVar5 - iVar1;
            pTVar2->periodicDriftUsec = uVar5;
            if (0xf3 < uVar5) {
              iVar1 = uVar4 - 1;
              iVar7 = iVar7 + -1 + (uint)(uVar4 != 0);
              goto LAB_00005900;
            }
          }
          else {
            uVar5 = iVar1 + uVar5;
            pTVar2->periodicDriftUsec = uVar5;
            if (0xf3 < uVar5) {
              iVar1 = uVar4 + 1;
              iVar7 = iVar7 + (uint)(0xfffffffe < uVar4);
LAB_00005900:
              *(int *)&pTVar2->remaining = iVar1;
              *(int *)((int)&pTVar2->remaining + 4) = iVar7;
              pTVar2->periodicDriftUsec = uVar5 - 0xf4;
            }
          }
        }
        if (pTVar2->callback != FUN_00000000) {
          pTVar2->doCallback = true;
        }
      }
      else {
        *(uint *)&pTVar2->remaining = uVar6 - timeElapsed;
        *(uint *)((int)&pTVar2->remaining + 4) = iVar7 - (uint)(uVar6 < timeElapsed);
      }
    }
    pTVar2 = pTVar2 + 1;
    if (pTVar2 == (Timer_t *)&wallClockOverflowCnt) {
      return;
    }
  } while( true );
}



void executeTimerCallbacks(void)

{
  Timer_t *pTVar1;
  RTCDRV_TimerID_t RVar2;
  
  pTVar1 = timer;
  RVar2 = 0;
  do {
    if (pTVar1->doCallback != false) {
      (*pTVar1->callback)(RVar2,pTVar1->user);
    }
    RVar2 = RVar2 + 1;
    pTVar1 = pTVar1 + 1;
  } while (RVar2 != 4);
  return;
}



void rescheduleRtc(uint32_t rtcCnt)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  iVar1 = 0;
  uVar2 = 0xffffffff;
  uVar3 = 0xffffffff;
  do {
    if ((&timer[0].running)[iVar1] != false) {
      uVar4 = *(uint *)((int)&timer[0].remaining + iVar1);
      uVar5 = *(uint *)((int)&timer[0].remaining + iVar1 + 4);
      bVar6 = uVar3 <= uVar5;
      if (uVar5 == uVar3) {
        bVar6 = uVar2 <= uVar4;
      }
      if (!bVar6) {
        uVar2 = uVar4;
        uVar3 = uVar5;
      }
    }
    iVar1 = iVar1 + 0x28;
  } while (iVar1 != 0xa0);
  rtcRunning = false;
  if (uVar3 != 0xffffffff || uVar2 != 0xffffffff) {
    bVar6 = uVar3 == 0;
    if (uVar3 == 0) {
      bVar6 = uVar2 < 0xffffff9c;
    }
    if (!bVar6) {
      uVar2 = 0xffffff9b;
    }
    write_volatile_4(Peripherals::RTCC.IFC,4);
    write_volatile_4(Peripherals::RTCC.CC1_CCV,uVar2 + rtcCnt);
    rtcRunning = true;
    uVar2 = read_volatile_4(Peripherals::RTCC.IEN);
    write_volatile_4(Peripherals::RTCC.IEN,uVar2 | 4);
    lastStart = rtcCnt;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

Ecode_t RTCDRV_Init(void)

{
  uint uVar1;
  _Bool _Var2;
  uint uVar3;
  
  _Var2 = rtcdrvIsInitialized;
  uVar3 = (uint)rtcdrvIsInitialized;
  if (uVar3 == 0) {
    rtcdrvIsInitialized = true;
    CMU_ClockEnable(cmuClock_HFLE,true);
    CMU_ClockSelectSet(cmuClock_LFE,cmuSelect_LFXO);
    initRTCC.presc = rtccCntPresc_8;
    CMU_ClockEnable(cmuClock_RTCC,true);
    RTCC_Init(&initRTCC);
    RTCC_ChannelInit(1,&initRTCCCompareChannel);
    uVar1 = read_volatile_4(Peripherals::RTCC.IEN);
    write_volatile_4(Peripherals::RTCC.IEN,uVar1 & 0xfffff800);
    write_volatile_4(Peripherals::RTCC.IFC,0x7ff);
    write_volatile_4(Peripherals::RTCC.CNT,0);
    _DAT_e000e280 = 0x20000000;
    _DAT_e000e100 = 0x20000000;
    uVar1 = read_volatile_4(Peripherals::RTCC.IEN);
    write_volatile_4(Peripherals::RTCC.IEN,uVar1 | 1);
    memset(timer,0,0xa0);
    inTimerIRQ = _Var2;
    rtcRunning = _Var2;
    startTimerNestingLevel = uVar3;
    wallClockOverflowCnt = uVar3;
    wallClockTimeBase = uVar3;
  }
  return 0;
}



undefined8 RTCDRV_GetWallClockTicks64(void)

{
  uint uVar1;
  
  do {
    uVar1 = read_volatile_4(Peripherals::RTCC.CNT);
  } while (false);
  return CONCAT44(wallClockOverflowCnt,uVar1);
}



uint32_t RTCDRV_TicksToMsec(uint64_t ticks)

{
  uint in_r0;
  int in_r1;
  uint uVar1;
  
  uVar1 = (uint)((ulonglong)in_r0 * 8000);
  return uVar1 + 0x4000 >> 0xf |
         (in_r1 * 8000 + (int)((ulonglong)in_r0 * 8000 >> 0x20) + (uint)(0xffffbfff < uVar1)) *
         0x20000;
}



void RTCC_IRQHandler(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  uint uVar2;
  uint uVar3;
  
  irqState = CORE_EnterAtomic();
  uVar2 = read_volatile_4(Peripherals::RTCC.IEN);
  uVar3 = read_volatile_4(Peripherals::RTCC.IF);
  uVar2 = uVar2 & uVar3;
  write_volatile_4(Peripherals::RTCC.IFC,uVar2 & 0xfffffffa);
  if ((int)(uVar2 << 0x1d) < 0) {
    uVar3 = read_volatile_4(Peripherals::RTCC.CNT);
    inTimerIRQ = true;
    do {
      uVar1 = read_volatile_4(Peripherals::RTCC.IEN);
      write_volatile_4(Peripherals::RTCC.IEN,uVar1 & 0xfffffffb);
      checkAllTimers(uVar3 - lastStart);
      executeTimerCallbacks();
      rescheduleRtc(uVar3);
      uVar3 = read_volatile_4(Peripherals::RTCC.CNT);
      uVar1 = read_volatile_4(Peripherals::RTCC.CC1_CCV);
      if (rtcRunning == false) break;
    } while (uVar1 - lastStart < uVar3 - lastStart);
    inTimerIRQ = false;
  }
  if ((int)(uVar2 << 0x1f) < 0) {
    write_volatile_4(Peripherals::RTCC.IFC,1);
    wallClockOverflowCnt = wallClockOverflowCnt + 1;
  }
  CORE_ExitAtomic(irqState);
  return;
}



// WARNING: Could not reconcile some variable overlaps
// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void UDELAY_Calibrate(void)

{
  uint uVar1;
  uint uVar2;
  CMU_Select_TypeDef ref;
  CMU_ClkDiv_TypeDef div;
  CORE_irqState_t irqState;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  uint local_34;
  undefined4 local_30;
  _Bool local_2c;
  
  local_34 = 1;
  local_30 = 5;
  local_2c = false;
  uVar2 = read_volatile_4(CMU->HFBUSCLKEN0);
  bVar11 = -1 < (int)(uVar2 << 0x1f);
  if (bVar11) {
    CMU_ClockEnable(cmuClock_HFLE,true);
  }
  ref = CMU_ClockSelectGet(cmuClock_LFE);
  uVar2 = read_volatile_4(CMU->STATUS);
  CMU_ClockSelectSet(cmuClock_LFE,cmuSelect_LFRCO);
  div = CMU_ClockDivGet(cmuClock_RTCC);
  uVar7 = read_volatile_4(CMU->LFECLKEN0);
  bVar12 = -1 < (int)(uVar7 << 0x1f);
  if (bVar12) {
    CMU_ClockEnable(cmuClock_RTCC,true);
  }
  irqState = CORE_EnterAtomic();
  uVar7 = read_volatile_4(Peripherals::RTCC.CTRL);
  uVar7 = uVar7 & 1;
  uVar8 = uVar7;
  uVar9 = uVar7;
  if (uVar7 != 0) {
    uVar8 = read_volatile_4(Peripherals::RTCC.CTRL);
    uVar7 = read_volatile_4(Peripherals::RTCC.IEN);
    write_volatile_4(Peripherals::RTCC.CTRL,0);
    write_volatile_4(Peripherals::RTCC.IEN,0);
    write_volatile_4(Peripherals::RTCC.IFC,0x7ff);
    _DAT_e000e280 = 0x20000000;
    uVar9 = 1;
  }
  local_34 = (uint)((uint3)local_34 & 0xffff);
  local_30 = CONCAT31(local_30._1_3_,8);
  RTCC_Init((RTCC_Init_TypeDef *)&local_34);
  loops_per_jiffy = 0x1000;
  uVar4 = loops_per_jiffy;
  do {
    loops_per_jiffy = uVar4;
    uVar4 = loops_per_jiffy << 1;
    if (uVar4 == 0) break;
    uVar6 = read_volatile_4(Peripherals::RTCC.CNT);
    do {
      uVar1 = read_volatile_4(Peripherals::RTCC.CNT);
    } while (uVar6 == uVar1);
    uVar6 = read_volatile_4(Peripherals::RTCC.CNT);
    uVar5 = uVar4;
    do {
      bVar13 = uVar5 != 0;
      uVar5 = uVar5 - 1;
    } while (bVar13 && uVar5 != 0);
    uVar1 = read_volatile_4(Peripherals::RTCC.CNT);
  } while (uVar6 == uVar1);
  uVar6 = loops_per_jiffy & 0x7fffffff;
  iVar3 = 9;
  loops_per_jiffy = uVar6;
  while ((iVar3 = iVar3 + -1, iVar3 != 0 && (uVar6 = uVar6 >> 1, uVar6 != 0))) {
    loops_per_jiffy = loops_per_jiffy | uVar6;
    uVar1 = read_volatile_4(Peripherals::RTCC.CNT);
    do {
      uVar10 = read_volatile_4(Peripherals::RTCC.CNT);
    } while (uVar1 == uVar10);
    uVar1 = read_volatile_4(Peripherals::RTCC.CNT);
    uVar10 = loops_per_jiffy;
    do {
      bVar13 = uVar10 != 0;
      uVar10 = uVar10 - 1;
    } while (bVar13 && uVar10 != 0);
    uVar10 = read_volatile_4(Peripherals::RTCC.CNT);
    if (uVar1 != uVar10) {
      loops_per_jiffy = loops_per_jiffy & ~uVar6;
    }
  }
  CORE_ExitAtomic(irqState);
  if (uVar9 == 0) {
    RTCC_Enable(false);
  }
  else {
    CMU_ClockDivSet(cmuClock_RTCC,div);
    write_volatile_4(Peripherals::RTCC.CTRL,uVar8);
    write_volatile_4(Peripherals::RTCC.IEN,uVar7);
  }
  if (bVar12) {
    CMU_ClockEnable(cmuClock_RTCC,false);
  }
  if (ref != cmuSelect_LFRCO) {
    CMU_ClockSelectSet(cmuClock_LFE,ref);
  }
  if ((uVar2 & 0x40) == 0) {
    CMU_OscillatorEnable(cmuOsc_LFRCO,false,false);
  }
  if (bVar11) {
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



// WARNING: Could not reconcile some variable overlaps
// WARNING: Globals starting with '_' overlap smaller symbols at the same address

Ecode_t USTIMER_Init(void)

{
  longlong lVar1;
  uint uVar2;
  uint32_t uVar3;
  TIMER_InitCC_TypeDef timerCCInit;
  TIMER_Init_TypeDef timerInit;
  
  memset(&timerInit,0,0xd);
  timerInit.enable = true;
  timerCCInit._0_4_ = 0;
  timerCCInit._4_2_ = 0;
  timerCCInit._7_4_ = 0;
  timerCCInit.mode = timerCCModeCompare;
  CMU_ClockEnable(cmuClock_TIMER0,true);
  write_volatile_4(Peripherals::TIMER0.TOP,0xffff);
  TIMER_InitCC((TIMER_TypeDef *)&Peripherals::TIMER0,0,&timerCCInit);
  timerInit.prescale = timerPrescale1;
  do {
    TIMER_Init((TIMER_TypeDef *)&Peripherals::TIMER0,&timerInit);
    uVar3 = CMU_ClockFreqGet(cmuClock_HFPER);
    freq = uVar3 >> (uint)timerInit.prescale;
    timerInit.prescale = timerInit.prescale + timerPrescale2;
    if (timerPrescale1024 < timerInit.prescale) break;
  } while (2000000 < freq);
  uVar3 = CMU_ClockFreqGet(cmuClock_CORE);
  lVar1 = (192000000 / (ulonglong)uVar3) * (ulonglong)freq + 500000;
  minTicks = __aeabi_uldivmod((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),1000000,0);
  uVar2 = read_volatile_4(Peripherals::TIMER0.IEN);
  write_volatile_4(Peripherals::TIMER0.IEN,uVar2 & 0xffffffef);
  timeElapsed = false;
  _DAT_e000e100 = 0x400;
  _DAT_e000e280 = 0x400;
  return 0;
}



void TIMER0_IRQHandler(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::TIMER0.IF);
  if ((int)(uVar1 << 0x1b) < 0) {
    write_volatile_4(Peripherals::TIMER0.IFC,0x10);
    timeElapsed = true;
  }
  return;
}



EMSTATUS DISPLAY_Init(void)

{
  EMSTATUS EVar1;
  ulong *puVar2;
  
  if (moduleInitialized == false) {
    puVar2 = &loops_per_jiffy;
    moduleInitialized = true;
    do {
      puVar2 = (ulong *)((code **)puVar2 + 1);
      if ((code *)*puVar2 == FUN_00000000) goto LAB_00005e34;
      EVar1 = (*(code *)*puVar2)();
    } while (EVar1 == 0);
  }
  else {
LAB_00005e34:
    EVar1 = 0;
  }
  return EVar1;
}



EMSTATUS DISPLAY_DeviceGet(int displayDeviceNo,DISPLAY_Device_t *device)

{
  char **ppcVar1;
  EMSTATUS EVar2;
  uint uVar3;
  DISPLAY_Device_t *pDVar4;
  
  if (moduleInitialized == false) {
    EVar2 = 0x80110005;
  }
  else {
    if (displayDeviceNo < 1) {
      pDVar4 = deviceTable + displayDeviceNo;
      do {
        ppcVar1 = &pDVar4->name;
        uVar3 = (pDVar4->geometry).width;
        pDVar4 = (DISPLAY_Device_t *)&(pDVar4->geometry).stride;
        device->name = *ppcVar1;
        (device->geometry).width = uVar3;
        device = (DISPLAY_Device_t *)&(device->geometry).stride;
      } while (pDVar4 != (DISPLAY_Device_t *)&deviceTable[displayDeviceNo].pDriverRefresh);
      device->name = pDVar4->name;
      EVar2 = 0;
    }
    else {
      EVar2 = 0x80110002;
    }
  }
  return EVar2;
}



EMSTATUS DISPLAY_DeviceRegister(DISPLAY_Device_t *device)

{
  EMSTATUS EVar1;
  uint uVar2;
  DISPLAY_Device_t *pDVar3;
  DISPLAY_Device_t *pDVar4;
  
  if (moduleInitialized == false) {
    EVar1 = 0x80110005;
  }
  else {
    if (devicesRegistered < 1) {
      pDVar3 = deviceTable + devicesRegistered;
      pDVar4 = (DISPLAY_Device_t *)&device->pDriverRefresh;
      devicesRegistered = devicesRegistered + 1;
      do {
        uVar2 = (device->geometry).width;
        pDVar3->name = device->name;
        (pDVar3->geometry).width = uVar2;
        pDVar3 = (DISPLAY_Device_t *)&(pDVar3->geometry).stride;
        device = (DISPLAY_Device_t *)&(device->geometry).stride;
      } while (device != pDVar4);
      pDVar3->name = device->name;
      EVar1 = 0;
    }
    else {
      EVar1 = 0x80110001;
    }
  }
  return EVar1;
}



EMSTATUS PixelMatrixAllocate(DISPLAY_Device_t *device,uint width,uint height,
                            DISPLAY_PixelMatrix_t *pixelMatrix)

{
  EMSTATUS EVar1;
  
  if (width == 0x80) {
    EVar1 = 0;
    if (&DAT_20002b8d < pixelMatrixPool + height * 0x10) {
      *pixelMatrix = (DISPLAY_PixelMatrix_t)0x0;
      EVar1 = 0x80110001;
    }
    else {
      *pixelMatrix = pixelMatrixPool;
      pixelMatrixPool = pixelMatrixPool + height * 0x10;
    }
  }
  else {
    EVar1 = 0x80110002;
  }
  return EVar1;
}



EMSTATUS PixelMatrixFree(DISPLAY_Device_t *device,DISPLAY_PixelMatrix_t pixelMatrix)

{
  return 0x80110004;
}



EMSTATUS DriverRefresh(DISPLAY_Device_t *device)

{
  PAL_TimerInit();
  PAL_SpiInit();
  return 0;
}



EMSTATUS PixelMatrixClear(DISPLAY_Device_t *device,DISPLAY_PixelMatrix_t pixelMatrix,uint width,
                         uint height)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 != height; uVar1 = uVar1 + 1) {
    memset((void *)((int)pixelMatrix + uVar1 * 0x10),0,0x10);
  }
  return 0;
}



// WARNING: Could not reconcile some variable overlaps

EMSTATUS PixelMatrixDraw(DISPLAY_Device_t *device,DISPLAY_PixelMatrix_t pixelMatrix,uint startColumn
                        ,uint width,uint startRow,uint height)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint16_t cmd;
  DISPLAY_PixelMatrix_t pvStack36;
  uint uStack32;
  
  pvStack36 = pixelMatrix;
  uStack32 = startColumn;
  PAL_GpioPinOutSet(3,0xe);
  PAL_TimerMicroSecondsDelay(6);
  uVar3 = startRow + 1 & 0xffff;
  pvStack36 = (DISPLAY_PixelMatrix_t)
              ((uint)pvStack36 & 0xffff | (uint)(ushort)((ushort)(uVar3 << 8) | 1) << 0x10);
  PAL_SpiTransmit((uint8_t *)&cmd,2);
  for (uVar2 = 0; uVar2 != height; uVar2 = uVar2 + 1) {
    PAL_SpiTransmit((uint8_t *)((int)pixelMatrix + uVar2 * 0x10),0x10);
    if (height - 1 == uVar2) {
      uVar1 = 0xffff;
    }
    else {
      uVar1 = ((short)uVar3 + 1 + (short)uVar2) * 0x100 | 0xff;
    }
    pvStack36 = (DISPLAY_PixelMatrix_t)((uint)pvStack36 & 0xffff | (uint)uVar1 << 0x10);
    PAL_SpiTransmit((uint8_t *)&cmd,2);
  }
  PAL_TimerMicroSecondsDelay(2);
  PAL_GpioPinOutClear(3,0xe);
  return 0;
}



EMSTATUS DisplayPolarityInverse(void)

{
  PAL_GpioPinOutToggle(3,0xd);
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



EMSTATUS DISPLAY_Ls013b7dh03Init(void)

{
  EMSTATUS EVar1;
  uint16_t cmd;
  DISPLAY_Device_t display;
  
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
    display.geometry.width = 0x80;
    display.geometry.stride = 0x80;
    display.geometry.height = 0x80;
    display.pDisplayPowerOn = DisplayEnable + 1;
    display.pPixelMatrixAllocate = PixelMatrixAllocate + 1;
    display.pPixelMatrixFree = PixelMatrixFree + 1;
    display.pPixelMatrixDraw = PixelMatrixDraw + 1;
    display.addressMode = DISPLAY_ADDRESSING_BY_ROWS_ONLY;
    display.pPixelMatrixClear = PixelMatrixClear + 1;
    display.pDriverRefresh = DriverRefresh + 1;
    EVar1 = DISPLAY_DeviceRegister(&display);
    if (EVar1 == 0) {
      PAL_GpioPinOutSet(3,0xf);
      PAL_GpioPinOutSet(3,0xe);
      PAL_TimerMicroSecondsDelay(6);
      cmd = 4;
      PAL_SpiTransmit((uint8_t *)&cmd,2);
      PAL_TimerMicroSecondsDelay(2);
      PAL_GpioPinOutClear(3,0xe);
    }
  }
  return EVar1;
}



// WARNING: Could not reconcile some variable overlaps

EMSTATUS PAL_SpiInit(void)

{
  uint uVar1;
  USART_InitSync_TypeDef usartInit;
  
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
  uVar1 = read_volatile_4(Peripherals::USART1.ROUTELOC0);
  write_volatile_4(Peripherals::USART1.ROUTELOC0,uVar1 & 0xe0ffe0ff | 0xb000b00);
  return 0;
}



EMSTATUS PAL_SpiTransmit(uint8_t *data,uint len)

{
  uint uVar1;
  
  while (len != 0) {
    if ((len == 1) || ((int)data << 0x1f < 0)) {
      USART_Tx((USART_TypeDef *)&Peripherals::USART1,*data);
      len = len - 1;
      data = (uint8_t *)((int)data + 1);
    }
    else {
      USART_TxDouble((USART_TypeDef *)&Peripherals::USART1,*(uint16_t *)data);
      len = len - 2;
      data = (uint8_t *)((int)data + 2);
    }
  }
  do {
    uVar1 = read_volatile_4(Peripherals::USART1.STATUS);
  } while (-1 < (int)(uVar1 << 0x1a));
  return 0;
}



EMSTATUS PAL_TimerInit(void)

{
  UDELAY_Calibrate();
  return 0;
}



EMSTATUS PAL_TimerMicroSecondsDelay(uint usecs)

{
  UDELAY_Delay(usecs);
  return 0;
}



EMSTATUS PAL_TimerRepeat(anon_subr_void_void_ptr *pFunction,void *argument,uint frequency)

{
  int iVar1;
  EMSTATUS EVar2;
  
  iVar1 = rtcIntCallbackRegister(pFunction,argument,frequency);
  EVar2 = 0x80130002;
  if (iVar1 == 0) {
    EVar2 = 0;
  }
  return EVar2;
}



EMSTATUS PAL_GpioInit(void)

{
  CMU_ClockEnable(cmuClock_GPIO,true);
  return 0;
}



EMSTATUS PAL_GpioPinModeSet(uint port,uint pin,PAL_GpioMode_t mode,uint platformSpecific)

{
  EMSTATUS EVar1;
  
  EVar1 = (EMSTATUS)mode;
  if (EVar1 == 0) {
    GPIO_PinModeSet((GPIO_Port_TypeDef)port,pin,gpioModePushPull,platformSpecific);
  }
  else {
    EVar1 = 0x80130001;
  }
  return EVar1;
}



EMSTATUS PAL_GpioPinOutSet(uint port,uint pin)

{
  *(undefined4 *)((pin + ((port & 0xff) * 0x30 + 0x4210a00c) * 8) * 4) = 1;
  return 0;
}



EMSTATUS PAL_GpioPinOutClear(uint port,uint pin)

{
  *(undefined4 *)((pin + ((port & 0xff) * 0x30 + 0x4210a00c) * 8) * 4) = 0;
  return 0;
}



EMSTATUS PAL_GpioPinOutToggle(uint port,uint pin)

{
  (&Peripherals::GPIO.PA_DOUTTGL)[(port & 0xff) * 0xc] = 1 << (pin & 0xff);
  return 0;
}



EMSTATUS DMD_getDisplayGeometry(DMD_DisplayGeometry **geometry)

{
  if (moduleInitialized != false) {
    *geometry = &dimensions;
    return 0;
  }
  return 1;
}



EMSTATUS DMD_setClippingArea(uint16_t xStart,uint16_t yStart,uint16_t width,uint16_t height)

{
  EMSTATUS EVar1;
  
  if (moduleInitialized == false) {
    EVar1 = 1;
  }
  else {
    if (((uint)dimensions.xSize < (uint)xStart + (uint)width) ||
       ((uint)dimensions.ySize < (uint)yStart + (uint)height)) {
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
  return EVar1;
}



EMSTATUS DMD_writeColor(uint16_t x,uint16_t y,uint8_t red,uint8_t green,uint8_t blue,
                       uint32_t numPixels)

{
  char cVar1;
  uint uVar2;
  void *pvVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  byte *__s;
  uint uVar7;
  uint uVar8;
  DISPLAY_PixelMatrix_t pvVar9;
  uint uVar10;
  int iVar11;
  int __c;
  
  uVar10 = (uint)green;
  uVar6 = (uint)x;
  if ((moduleInitialized == false) || (pixelMatrixBuffer == (DISPLAY_PixelMatrix_t)0x0)) {
    numPixels = 1;
  }
  else {
    if (displayDevice.addressMode == DISPLAY_ADDRESSING_BY_ROWS_ONLY) {
      if (displayDevice.colourMode != DISPLAY_COLOUR_MODE_MONOCHROME_INVERSE) {
        uVar10 = count_leading_zeroes(uVar10);
      }
      uVar7 = displayDevice.geometry.stride >> 3;
      uVar4 = y + dimensions.yClipStart;
      if (displayDevice.colourMode != DISPLAY_COLOUR_MODE_MONOCHROME_INVERSE) {
        uVar10 = uVar10 >> 5;
      }
      if (uVar10 == 0) {
        __c = 0;
      }
      else {
        __c = 0xff;
      }
      pvVar9 = (DISPLAY_PixelMatrix_t)(uVar7 * uVar4 + (int)pixelMatrixBuffer);
      iVar11 = 0;
      while (numPixels != 0) {
        uVar8 = dimensions.clipWidth - uVar6;
        if (numPixels <= dimensions.clipWidth - uVar6) {
          uVar8 = numPixels;
        }
        numPixels = numPixels - uVar8;
        uVar2 = uVar6 + dimensions.xClipStart & 0xffff;
        if (uVar8 < 8) {
          uVar8 = uVar8 + uVar2;
          if (uVar10 == 0) {
            for (; uVar2 < uVar8; uVar2 = uVar2 + 1 & 0xffff) {
              *(byte *)((int)pvVar9 + (uVar2 >> 3)) =
                   *(byte *)((int)pvVar9 + (uVar2 >> 3)) & ~(byte)(1 << (uVar2 & 7));
            }
          }
          else {
            for (; uVar2 < uVar8; uVar2 = uVar2 + 1 & 0xffff) {
              *(byte *)((int)pvVar9 + (uVar2 >> 3)) =
                   (byte)(1 << (uVar2 & 7)) | *(byte *)((int)pvVar9 + (uVar2 >> 3));
            }
          }
        }
        else {
          uVar2 = uVar2 >> 3;
          uVar6 = uVar6 + dimensions.xClipStart & 7;
          __s = (byte *)((int)pvVar9 + uVar2);
          if (uVar6 != 0) {
            cVar1 = (char)(1 << uVar6);
            *(byte *)((int)pvVar9 + uVar2) =
                 -cVar1 & (byte)__c | *(byte *)((int)pvVar9 + uVar2) & cVar1 - 1U;
            __s = __s + 1;
            uVar8 = uVar8 + (uVar6 - 8);
          }
          uVar6 = uVar8 >> 3;
          if (uVar6 != 0) {
            pvVar3 = memset(__s,__c,uVar6);
            uVar8 = uVar8 - (uVar8 & 0xfffffff8);
            __s = (byte *)((int)pvVar3 + uVar6);
            if (uVar8 == 0) goto LAB_0000635a;
          }
          cVar1 = (char)(1 << (uVar8 & 0xff));
          *__s = (byte)__c & cVar1 - 1U | -cVar1 & *__s;
        }
LAB_0000635a:
        uVar6 = (uint)uVar4 + iVar11;
        iVar5 = (int)uVar6 >> 5;
        dirtyRows[iVar5] = 1 << (uVar6 & 0x1f) | dirtyRows[iVar5];
        iVar11 = iVar11 + 1;
        pvVar9 = (DISPLAY_PixelMatrix_t)((int)pvVar9 + uVar7);
        uVar6 = 0;
      }
    }
    else {
      numPixels = 10;
    }
  }
  return numPixels;
}



EMSTATUS DMD_sleep(void)

{
  EMSTATUS EVar1;
  
                    // WARNING: Could not recover jumptable at 0x00006402. Too many branches
                    // WARNING: Treating indirect jump as call
  EVar1 = (*displayDevice.pDisplayPowerOn)(&displayDevice,false);
  return EVar1;
}



EMSTATUS DMD_wakeUp(void)

{
  EMSTATUS EVar1;
  
                    // WARNING: Could not recover jumptable at 0x0000640e. Too many branches
                    // WARNING: Treating indirect jump as call
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



EMSTATUS DMD_init(DMD_InitConfig *initConfig)

{
  EMSTATUS EVar1;
  
  if (moduleInitialized == false) {
    EVar1 = DISPLAY_Init();
    if (((EVar1 == 0) && (EVar1 = DISPLAY_DeviceGet(0,&displayDevice), EVar1 == 0)) &&
       (EVar1 = DMD_allocateFramebuffer(&pixelMatrixBuffer), EVar1 == 0)) {
      if (pixelMatrixBuffer == (DISPLAY_PixelMatrix_t)0x0) {
        EVar1 = 0xb;
      }
      else {
        dimensions.xSize = (uint16_t)(displayDevice.geometry.width & 0xffff);
        dimensions.ySize = (uint16_t)(displayDevice.geometry.height & 0xffff);
        dimensions.xClipStart = 0;
        dimensions.yClipStart = 0;
        moduleInitialized = true;
        dimensions.clipWidth = dimensions.xSize;
        dimensions.clipHeight = dimensions.ySize;
        DMD_writeColor(0,0,'\0','\0','\0',
                       (displayDevice.geometry.width & 0xffff) *
                       (displayDevice.geometry.height & 0xffff));
      }
    }
  }
  else {
    EVar1 = 0;
  }
  return EVar1;
}



EMSTATUS DMD_updateDisplay(void)

{
  uint uVar1;
  EMSTATUS EVar2;
  uint uVar3;
  uint32_t uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar1 = 0;
  uVar5 = displayDevice.geometry.stride >> 3;
  iVar6 = 1;
  uVar3 = 0;
  uVar4 = dirtyRows[0];
  do {
    uVar7 = uVar3 + uVar1;
    if (displayDevice.geometry.height <= uVar7) {
      if ((uVar1 == 0) ||
         (EVar2 = (*displayDevice.pPixelMatrixDraw)
                            (&displayDevice,
                             (DISPLAY_PixelMatrix_t)(uVar3 * uVar5 + (int)pixelMatrixBuffer),0,
                             displayDevice.geometry.width,uVar3,uVar1), EVar2 == 0)) {
        memset(dirtyRows,0,0x10);
        EVar2 = 0;
      }
      return EVar2;
    }
    if ((uVar4 & 1) == 0) {
      if (uVar1 == 0) {
        uVar3 = uVar3 + 1;
      }
      else {
        uVar1 = (*displayDevice.pPixelMatrixDraw)
                          (&displayDevice,
                           (DISPLAY_PixelMatrix_t)(uVar3 * uVar5 + (int)pixelMatrixBuffer),0,
                           displayDevice.geometry.width,uVar3,uVar1);
        if (uVar1 != 0) {
          return uVar1;
        }
        uVar3 = uVar7 + 1;
      }
    }
    else {
      uVar1 = uVar1 + 1;
    }
    if ((uVar3 + uVar1 & 0x1f) == 0) {
      uVar4 = dirtyRows[iVar6];
      iVar6 = iVar6 + 1;
    }
    else {
      uVar4 = uVar4 >> 1;
    }
  } while( true );
}



EMSTATUS GLIB_displayWakeUp(void)

{
  EMSTATUS EVar1;
  
                    // WARNING: Could not recover jumptable at 0x0000640e. Too many branches
                    // WARNING: Treating indirect jump as call
  EVar1 = (*displayDevice.pDisplayPowerOn)(&displayDevice,true);
  return EVar1;
}



EMSTATUS GLIB_displaySleep(void)

{
  EMSTATUS EVar1;
  
                    // WARNING: Could not recover jumptable at 0x00006402. Too many branches
                    // WARNING: Treating indirect jump as call
  EVar1 = (*displayDevice.pDisplayPowerOn)(&displayDevice,false);
  return EVar1;
}



EMSTATUS GLIB_setClippingRegion(GLIB_Context_t *pContext,GLIB_Rectangle_t *pRect)

{
  int iVar1;
  EMSTATUS EVar2;
  int iVar3;
  int32_t iVar4;
  int iVar5;
  int32_t iVar6;
  int iVar7;
  int32_t iVar8;
  DMD_DisplayGeometry *pDVar9;
  
  if ((pContext == (GLIB_Context_t *)0x0) || (pRect == (GLIB_Rectangle_t *)0x0)) {
    EVar2 = 5;
  }
  else {
    iVar1 = pRect->xMin;
    iVar5 = pRect->xMax;
    if (iVar1 < iVar5) {
      iVar3 = pRect->yMin;
      iVar7 = pRect->yMax;
      if (iVar3 < iVar7) {
        pDVar9 = pContext->pDisplayGeometry;
        if (((((int)(uint)pDVar9->xClipStart <= iVar1) && ((int)(uint)pDVar9->yClipStart <= iVar3))
            && (iVar5 < (int)(uint)pDVar9->clipWidth)) && (iVar7 < (int)(uint)pDVar9->clipHeight)) {
          EVar2 = DMD_setClippingArea((uint16_t)iVar1,(uint16_t)iVar3,
                                      (short)iVar5 + (uint16_t)iVar1 + 1,
                                      (short)iVar7 + (uint16_t)iVar3 + 1);
          iVar4 = pRect->yMin;
          iVar6 = pRect->xMax;
          iVar8 = pRect->yMax;
          (pContext->clippingRegion).xMin = pRect->xMin;
          (pContext->clippingRegion).yMin = iVar4;
          (pContext->clippingRegion).xMax = iVar6;
          (pContext->clippingRegion).yMax = iVar8;
          return EVar2;
        }
        return 3;
      }
    }
    EVar2 = 4;
  }
  return EVar2;
}



EMSTATUS GLIB_contextInit(GLIB_Context_t *pContext)

{
  EMSTATUS EVar1;
  DMD_DisplayGeometry *pTmpDisplayGeometry;
  GLIB_Rectangle_t tmpRect;
  
  if (pContext == (GLIB_Context_t *)0x0) {
    EVar1 = 5;
  }
  else {
    pContext->backgroundColor = 0;
    pContext->foregroundColor = 0xffffff;
    EVar1 = DMD_getDisplayGeometry(&pTmpDisplayGeometry);
    if (EVar1 == 0) {
      pContext->pDisplayGeometry = pTmpDisplayGeometry;
      tmpRect.xMax = pTmpDisplayGeometry->xSize - 1;
      tmpRect.yMax = pTmpDisplayGeometry->ySize - 1;
      tmpRect.xMin = EVar1;
      tmpRect.yMin = EVar1;
      EVar1 = GLIB_setClippingRegion(pContext,&tmpRect);
      if (EVar1 == 0) {
        GLIB_setFont(pContext,&GLIB_FontNormal8x8);
      }
    }
  }
  return EVar1;
}



EMSTATUS GLIB_resetDisplayClippingArea(GLIB_Context_t *pContext)

{
  EMSTATUS EVar1;
  
  if (pContext != (GLIB_Context_t *)0x0) {
    EVar1 = DMD_setClippingArea(0,0,pContext->pDisplayGeometry->xSize,
                                pContext->pDisplayGeometry->ySize);
    return EVar1;
  }
  return 5;
}



EMSTATUS GLIB_clear(GLIB_Context_t *pContext)

{
  EMSTATUS EVar1;
  uint32_t uVar2;
  
  if (pContext == (GLIB_Context_t *)0x0) {
    EVar1 = 5;
  }
  else {
    uVar2 = pContext->backgroundColor;
    EVar1 = GLIB_resetDisplayClippingArea(pContext);
    if (EVar1 == 0) {
      EVar1 = DMD_writeColor(0,0,(uint8_t)((uVar2 << 8) >> 0x18),(uint8_t)((uVar2 << 0x10) >> 0x18),
                             (uint8_t)uVar2,
                             (uint)pContext->pDisplayGeometry->clipWidth *
                             (uint)pContext->pDisplayGeometry->clipHeight);
    }
  }
  return EVar1;
}



void GLIB_colorTranslate24bpp(uint32_t color,uint8_t *red,uint8_t *green,uint8_t *blue)

{
  *red = (uint8_t)(color >> 0x10);
  *green = (uint8_t)(color >> 8);
  *blue = (uint8_t)color;
  return;
}



EMSTATUS GLIB_drawPixel(GLIB_Context_t *pContext,int32_t x,int32_t y)

{
  _Bool _Var1;
  EMSTATUS EVar2;
  uint32_t uVar3;
  
  if (pContext == (GLIB_Context_t *)0x0) {
    EVar2 = 5;
  }
  else {
    _Var1 = GLIB_rectContainsPoint(&pContext->clippingRegion,x,y);
    if (_Var1 == false) {
      EVar2 = 1;
    }
    else {
      uVar3 = pContext->foregroundColor;
      EVar2 = DMD_writeColor((uint16_t)x,(uint16_t)y,(uint8_t)((uVar3 << 8) >> 0x18),
                             (uint8_t)((uVar3 << 0x10) >> 0x18),(uint8_t)uVar3,1);
    }
  }
  return EVar2;
}



EMSTATUS GLIB_drawPixelColor(GLIB_Context_t *pContext,int32_t x,int32_t y,uint32_t color)

{
  _Bool _Var1;
  EMSTATUS EVar2;
  
  if (pContext == (GLIB_Context_t *)0x0) {
    EVar2 = 5;
  }
  else {
    _Var1 = GLIB_rectContainsPoint(&pContext->clippingRegion,x,y);
    if (_Var1 == false) {
      EVar2 = 1;
    }
    else {
      EVar2 = DMD_writeColor((uint16_t)x,(uint16_t)y,(uint8_t)((color << 8) >> 0x18),
                             (uint8_t)((color << 0x10) >> 0x18),(uint8_t)color,1);
    }
  }
  return EVar2;
}



uint8_t GLIB_getClipCode(GLIB_Context_t *pContext,int32_t x,int32_t y)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (pContext->clippingRegion).xMin;
  iVar3 = iVar2;
  if (x < iVar2) {
    iVar3 = 1;
  }
  bVar1 = (byte)iVar3;
  if (iVar2 <= x) {
    bVar1 = 0;
  }
  if ((pContext->clippingRegion).xMax < x) {
    bVar1 = bVar1 | 2;
  }
  if ((pContext->clippingRegion).yMax < y) {
    bVar1 = bVar1 | 4;
  }
  if (y < (pContext->clippingRegion).yMin) {
    bVar1 = bVar1 | 8;
  }
  return (uint8_t)bVar1;
}



EMSTATUS GLIB_drawLineH(GLIB_Context_t *pContext,int32_t x1,int32_t y1,int32_t x2)

{
  EMSTATUS EVar1;
  int iVar2;
  int iVar3;
  int32_t iVar4;
  uint8_t red;
  uint8_t green;
  uint8_t blue;
  
  if (pContext == (GLIB_Context_t *)0x0) {
    EVar1 = 5;
  }
  else {
    if (((pContext->clippingRegion).yMin <= y1) && (y1 <= (pContext->clippingRegion).yMax)) {
      iVar3 = (pContext->clippingRegion).xMax;
      iVar4 = x2;
      if (x2 < x1) {
        iVar4 = x1;
        x1 = x2;
      }
      if ((x1 <= iVar3) && (iVar2 = (pContext->clippingRegion).xMin, iVar2 <= iVar4)) {
        if (iVar2 < x1) {
          iVar2 = x1;
        }
        GLIB_colorTranslate24bpp(pContext->foregroundColor,&red,&green,&blue);
        if (iVar4 < iVar3) {
          iVar3 = iVar4 - iVar2;
        }
        else {
          iVar3 = iVar3 - iVar2;
        }
        EVar1 = DMD_writeColor((uint16_t)iVar2,(uint16_t)y1,red,green,blue,iVar3 + 1);
        return EVar1;
      }
    }
    EVar1 = 1;
  }
  return EVar1;
}



// WARNING: Could not reconcile some variable overlaps

EMSTATUS GLIB_drawLineV(GLIB_Context_t *pContext,int32_t x1,int32_t y1,int32_t y2)

{
  uint16_t xStart;
  uint16_t yStart;
  EMSTATUS EVar1;
  int iVar2;
  int32_t iVar3;
  int iVar4;
  uint8_t red;
  uint8_t green;
  uint8_t blue;
  int32_t iStack20;
  
  if (pContext == (GLIB_Context_t *)0x0) {
    EVar1 = 5;
  }
  else {
    if (((pContext->clippingRegion).xMin <= x1) && (x1 <= (pContext->clippingRegion).xMax)) {
      iVar4 = (pContext->clippingRegion).yMax;
      iVar3 = y2;
      if (y2 < y1) {
        iVar3 = y1;
        y1 = y2;
      }
      if ((y1 <= iVar4) && (iVar2 = (pContext->clippingRegion).yMin, iVar2 <= iVar3)) {
        if (iVar2 < y1) {
          iVar2 = y1;
        }
        if (iVar3 < iVar4) {
          iVar4 = iVar3 - iVar2;
        }
        else {
          iVar4 = iVar4 - iVar2;
        }
        iStack20 = y2;
        EVar1 = DMD_setClippingArea((uint16_t)x1,(uint16_t)iVar2,1,(uint16_t)(iVar4 + 1U));
        if (EVar1 != 0) {
          return EVar1;
        }
        GLIB_colorTranslate24bpp(pContext->foregroundColor,&red,&green,&blue);
        EVar1 = DMD_writeColor(0,0,red,green,blue,iVar4 + 1U);
        if (EVar1 != 0) {
          return EVar1;
        }
        xStart = *(uint16_t *)&(pContext->clippingRegion).xMin;
        yStart = *(uint16_t *)&(pContext->clippingRegion).yMin;
        EVar1 = DMD_setClippingArea(xStart,yStart,
                                    (short)(pContext->clippingRegion).xMax + xStart + 1,
                                    (short)(pContext->clippingRegion).yMax + yStart + 1);
        return EVar1;
      }
    }
    EVar1 = 1;
  }
  return EVar1;
}



EMSTATUS GLIB_drawLine(GLIB_Context_t *pContext,int32_t x1,int32_t y1,int32_t x2,int32_t y2)

{
  byte bVar1;
  byte bVar2;
  EMSTATUS EVar3;
  int x;
  uint uVar4;
  int y;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int32_t y_00;
  uint uVar9;
  int32_t x_00;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  
  if (pContext == (GLIB_Context_t *)0x0) {
    EVar3 = 5;
  }
  else {
    if (x1 == x2) {
      EVar3 = GLIB_drawLineV(pContext,x1,y1,y2);
      return EVar3;
    }
    if (y1 == y2) {
      EVar3 = GLIB_drawLineH(pContext,x1,y1,x2);
      return EVar3;
    }
    bVar1 = GLIB_getClipCode(pContext,x1,y1);
    bVar2 = GLIB_getClipCode(pContext,x2,y2);
    y_00 = 0;
    x_00 = 0;
    uVar9 = (uint)bVar2;
    uVar4 = (uint)bVar1;
    while (uVar12 = uVar4, iVar13 = y1, iVar7 = x1, (uVar12 | uVar9) != 0) {
      if ((uVar12 & uVar9) != 0) {
        return 1;
      }
      uVar4 = uVar12;
      if (uVar12 == 0) {
        uVar4 = uVar9;
      }
      if ((int)(uVar4 << 0x1f) < 0) {
        x_00 = (pContext->clippingRegion).xMin;
LAB_000068b2:
        y_00 = (uint)((x_00 - iVar7) * (y2 - iVar13)) / (uint)(x2 - iVar7) + iVar13;
      }
      else {
        if ((int)(uVar4 << 0x1e) < 0) {
          x_00 = (pContext->clippingRegion).xMax;
          goto LAB_000068b2;
        }
        if ((int)(uVar4 << 0x1d) < 0) {
          y_00 = (pContext->clippingRegion).yMax;
LAB_000068fc:
          x_00 = (uint)((y_00 - iVar13) * (x2 - iVar7)) / (uint)(y2 - iVar13) + iVar7;
        }
        else {
          if ((int)(uVar4 << 0x1c) < 0) {
            y_00 = (pContext->clippingRegion).yMin;
            goto LAB_000068fc;
          }
        }
      }
      bVar1 = GLIB_getClipCode(pContext,x_00,y_00);
      x1 = x_00;
      y1 = y_00;
      uVar4 = (uint)bVar1;
      if (uVar12 == 0) {
        uVar9 = (uint)bVar1;
        x1 = iVar7;
        x2 = x_00;
        y2 = y_00;
        y1 = iVar13;
        uVar4 = uVar12;
      }
    }
    if (iVar13 < y2) {
      iVar5 = y2 - iVar13;
    }
    else {
      iVar5 = iVar13 - y2;
    }
    if (iVar7 < x2) {
      iVar6 = x2 - iVar7;
    }
    else {
      iVar6 = iVar7 - x2;
    }
    iVar10 = x2;
    iVar11 = iVar7;
    if (iVar6 < iVar5) {
      iVar10 = y2;
      y2 = x2;
      iVar11 = iVar13;
      iVar13 = iVar7;
    }
    iVar7 = iVar13;
    iVar8 = iVar10;
    if (iVar11 <= iVar10) {
      iVar7 = y2;
      y2 = iVar13;
      iVar8 = iVar11;
      iVar11 = iVar10;
    }
    iVar13 = iVar11 - iVar8;
    if (y2 < iVar7) {
      iVar10 = iVar7 - y2;
    }
    else {
      iVar10 = y2 - iVar7;
    }
    if (iVar7 < y2) {
      iVar7 = -1;
    }
    else {
      iVar7 = 1;
    }
    uVar9 = (uint)-iVar13 / 2;
    for (; iVar8 <= iVar11; iVar8 = iVar8 + 1) {
      x = iVar8;
      y = y2;
      if (iVar6 < iVar5) {
        x = y2;
        y = iVar8;
      }
      EVar3 = GLIB_drawPixel(pContext,x,y);
      if (EVar3 != 0) {
        return EVar3;
      }
      uVar9 = uVar9 + iVar10;
      if (0 < (int)uVar9) {
        y2 = y2 + iVar7;
        uVar9 = uVar9 - iVar13;
      }
    }
    EVar3 = 0;
  }
  return EVar3;
}



EMSTATUS GLIB_drawPolygon(GLIB_Context_t *pContext,uint32_t numPoints,int32_t *polyPoints)

{
  EMSTATUS EVar1;
  uint uVar2;
  int x1;
  int y1;
  int32_t *piVar3;
  int iVar4;
  int x2;
  int y2;
  int x1_00;
  int y1_00;
  uint32_t uVar5;
  
  if (((pContext == (GLIB_Context_t *)0x0) || (polyPoints == (int32_t *)0x0)) || (numPoints < 2)) {
    EVar1 = 5;
  }
  else {
    x1_00 = *polyPoints;
    y1_00 = polyPoints[1];
    piVar3 = polyPoints + 4;
    uVar5 = 1;
    iVar4 = 0;
    x1 = x1_00;
    y1 = y1_00;
    do {
      x2 = piVar3[-2];
      y2 = piVar3[-1];
      EVar1 = GLIB_drawLine(pContext,x1,y1,x2,y2);
      if (1 < EVar1) {
        return EVar1;
      }
      if (EVar1 == 0) {
        iVar4 = iVar4 + 1;
      }
      uVar5 = uVar5 + 1;
      piVar3 = piVar3 + 2;
      x1 = x2;
      y1 = y2;
    } while (numPoints != uVar5);
    if ((x1_00 != x2) || (y1_00 != y2)) {
      EVar1 = GLIB_drawLine(pContext,x1_00,y1_00,x2,y2);
      if (1 < EVar1) {
        return EVar1;
      }
      if (EVar1 == 0) {
        iVar4 = iVar4 + 1;
      }
    }
    uVar2 = count_leading_zeroes(iVar4);
    EVar1 = uVar2 >> 5;
  }
  return EVar1;
}



_Bool GLIB_rectContainsPoint(GLIB_Rectangle_t *pRect,int32_t x,int32_t y)

{
  undefined uVar1;
  int iVar2;
  int iVar3;
  
  if (pRect != (GLIB_Rectangle_t *)0x0) {
    if (((pRect->xMin <= x) && (x <= pRect->xMax)) && (pRect->yMin <= y)) {
      iVar2 = pRect->yMax;
      iVar3 = iVar2;
      if (iVar2 < y) {
        iVar3 = 0;
      }
      uVar1 = (undefined)iVar3;
      if (y <= iVar2) {
        uVar1 = 1;
      }
      return (_Bool)uVar1;
    }
    pRect = (GLIB_Rectangle_t *)0x0;
  }
  return SUB41(pRect,0);
}



EMSTATUS GLIB_drawChar(GLIB_Context_t *pContext,char myChar,int32_t x,int32_t y,_Bool opaque)

{
  uint8_t uVar1;
  short sVar2;
  EMSTATUS EVar3;
  void *pvVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int32_t y_00;
  int iVar8;
  uint uVar9;
  
  iVar7 = (int)myChar;
  if (pContext == (GLIB_Context_t *)0x0) {
    return 5;
  }
  if (0x5e < iVar7 - 0x20U) {
    return 2;
  }
  if ((pContext->font).class == NumbersOnlyFont) {
    if (iVar7 == 0x3a) {
      uVar5 = 10;
      goto LAB_00006a8e;
    }
    if (iVar7 == 0x20) {
      uVar5 = 0xb;
      goto LAB_00006a8e;
    }
    sVar2 = -0x30;
  }
  else {
    sVar2 = -0x20;
  }
  uVar5 = (uint)(ushort)(myChar + sVar2);
LAB_00006a8e:
  if ((pContext->font).cntOfMapElements <= uVar5) {
    return 2;
  }
  pvVar4 = (pContext->font).pFontPixMap;
  iVar7 = 0;
  y_00 = y;
  do {
    if ((uint)(pContext->font).fontHeight <= (y_00 - y & 0xffffU)) {
      uVar5 = count_leading_zeroes(iVar7);
      return uVar5 >> 5;
    }
    uVar1 = (pContext->font).sizeOfMapElement;
    iVar8 = x;
    if (uVar1 == '\x01') {
      uVar9 = (uint)*(byte *)((int)pvVar4 + uVar5);
    }
    else {
      if (uVar1 == '\x02') {
        uVar9 = (uint)*(ushort *)((int)pvVar4 + uVar5 * 2);
      }
      else {
        uVar9 = (uint)*(ushort *)((int)pvVar4 + uVar5 * 4);
      }
    }
    for (; uVar6 = iVar8 - x & 0xffff, uVar6 < (pContext->font).fontWidth; iVar8 = iVar8 + 1) {
      if ((uVar9 & 1) == 0) {
        if (opaque != false) {
          uVar6 = GLIB_drawPixelColor(pContext,iVar8,y_00,pContext->backgroundColor);
          goto LAB_00006b24;
        }
      }
      else {
        uVar6 = GLIB_drawPixel(pContext,iVar8,y_00);
LAB_00006b24:
        if (1 < uVar6) {
          return uVar6;
        }
        if (uVar6 == 0) {
          iVar7 = iVar7 + 1;
        }
      }
      uVar9 = uVar9 >> 1;
    }
    for (; uVar6 < (uint)(pContext->font).fontWidth + (uint)(pContext->font).charSpacing;
        uVar6 = uVar6 + 1 & 0xffff) {
      if (opaque != false) {
        EVar3 = GLIB_drawPixelColor(pContext,x + uVar6,y_00,pContext->backgroundColor);
        if (1 < EVar3) {
          return EVar3;
        }
        if (EVar3 == 0) {
          iVar7 = iVar7 + 1;
        }
      }
    }
    uVar5 = uVar5 + (pContext->font).fontRowOffset & 0xffff;
    y_00 = y_00 + 1;
  } while( true );
}



EMSTATUS GLIB_drawString(GLIB_Context_t *pContext,char *pString,uint32_t sLength,int32_t x0,
                        int32_t y0,_Bool opaque)

{
  uint uVar1;
  EMSTATUS EVar2;
  char *pcVar3;
  int32_t x;
  int iVar4;
  
  if ((pContext == (GLIB_Context_t *)0x0) || (pString == (char *)0x0)) {
    EVar2 = 5;
  }
  else {
    if ((pContext->font).class == InvalidFont) {
      EVar2 = 2;
    }
    else {
      iVar4 = 0;
      pcVar3 = pString;
      x = x0;
      while (pString + sLength != pcVar3) {
        if (*pcVar3 == '\n') {
          y0 = y0 + (uint)(pContext->font).fontHeight + (uint)(pContext->font).lineSpacing;
          pcVar3 = pcVar3 + 1;
          x = x0;
        }
        else {
          EVar2 = GLIB_drawChar(pContext,*pcVar3,x,y0,opaque);
          if (1 < EVar2) {
            return EVar2;
          }
          if (EVar2 == 0) {
            iVar4 = iVar4 + 1;
          }
          x = x + (uint)(pContext->font).fontWidth + (uint)(pContext->font).charSpacing;
          pcVar3 = pcVar3 + 1;
        }
      }
      uVar1 = count_leading_zeroes(iVar4);
      EVar2 = uVar1 >> 5;
    }
  }
  return EVar2;
}



EMSTATUS GLIB_setFont(GLIB_Context_t *pContext,GLIB_Font_t *pFont)

{
  GLIB_Font_t *pGVar1;
  GLIB_Font_t *pGVar2;
  GLIB_Font_t *pGVar3;
  
  if (pContext != (GLIB_Context_t *)0x0) {
    if (pFont != (GLIB_Font_t *)0x0) {
      pGVar1 = &pContext->font;
      pGVar2 = pFont;
      do {
        pGVar3 = (GLIB_Font_t *)&pGVar2->cntOfMapElements;
        pGVar1->pFontPixMap = pGVar2->pFontPixMap;
        pGVar1 = (GLIB_Font_t *)&pGVar1->cntOfMapElements;
        pGVar2 = pGVar3;
      } while (pGVar3 != pFont + 1);
      return 0;
    }
    memset(&pContext->font,0,0x10);
  }
  return 5;
}



int crossProduct(int32_t *points)

{
  return (points[2] - *points) * (points[5] - points[1]) -
         (points[4] - *points) * (points[3] - points[1]);
}



void GRAPHICS_Init(void)

{
  EMSTATUS EVar1;
  
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
  glibContext.foregroundColor = GLIB_contextInit(&glibContext);
  if (glibContext.foregroundColor != 0) {
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  glibContext.backgroundColor = 0xffffff;
  GLIB_setFont(&glibContext,&GLIB_FontNormal8x8);
  return;
}



EMSTATUS GRAPHICS_Sleep(void)

{
  EMSTATUS EVar1;
  
                    // WARNING: Could not recover jumptable at 0x00006402. Too many branches
                    // WARNING: Treating indirect jump as call
  EVar1 = (*displayDevice.pDisplayPowerOn)(&displayDevice,false);
  return EVar1;
}



EMSTATUS GRAPHICS_Wakeup(void)

{
  EMSTATUS EVar1;
  
                    // WARNING: Could not recover jumptable at 0x0000640e. Too many branches
                    // WARNING: Treating indirect jump as call
  EVar1 = (*displayDevice.pDisplayPowerOn)(&displayDevice,true);
  return EVar1;
}



EMSTATUS GRAPHICS_Update(void)

{
  uint uVar1;
  EMSTATUS EVar2;
  uint uVar3;
  uint32_t uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar1 = 0;
  uVar5 = displayDevice.geometry.stride >> 3;
  iVar6 = 1;
  uVar3 = 0;
  uVar4 = dirtyRows[0];
  do {
    uVar7 = uVar3 + uVar1;
    if (displayDevice.geometry.height <= uVar7) {
      if ((uVar1 == 0) ||
         (EVar2 = (*displayDevice.pPixelMatrixDraw)
                            (&displayDevice,
                             (DISPLAY_PixelMatrix_t)(uVar3 * uVar5 + (int)pixelMatrixBuffer),0,
                             displayDevice.geometry.width,uVar3,uVar1), EVar2 == 0)) {
        memset(dirtyRows,0,0x10);
        EVar2 = 0;
      }
      return EVar2;
    }
    if ((uVar4 & 1) == 0) {
      if (uVar1 == 0) {
        uVar3 = uVar3 + 1;
      }
      else {
        uVar1 = (*displayDevice.pPixelMatrixDraw)
                          (&displayDevice,
                           (DISPLAY_PixelMatrix_t)(uVar3 * uVar5 + (int)pixelMatrixBuffer),0,
                           displayDevice.geometry.width,uVar3,uVar1);
        if (uVar1 != 0) {
          return uVar1;
        }
        uVar3 = uVar7 + 1;
      }
    }
    else {
      uVar1 = uVar1 + 1;
    }
    if ((uVar3 + uVar1 & 0x1f) == 0) {
      uVar4 = dirtyRows[iVar6];
      iVar6 = iVar6 + 1;
    }
    else {
      uVar4 = uVar4 >> 1;
    }
  } while( true );
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
  yOffset = (uint)glibContext.font.fontHeight + (uint)glibContext.font.lineSpacing + yOffset;
  return;
}



void GRAPHICS_InsertTriangle(uint32_t x,uint32_t y,uint32_t size,_Bool up,int8_t fillPercent)

{
  int32_t iVar1;
  int32_t iVar2;
  int32_t iVar3;
  int32_t iVar4;
  int32_t iVar5;
  int32_t iVar6;
  uint32_t y_00;
  int iVar7;
  int iVar8;
  int iVar9;
  int32_t polyPoints [6];
  int32_t points [6];
  
  iVar7 = y + size;
  iVar9 = x + size;
  iVar8 = (int)fillPercent;
  polyPoints[4] = x + (size >> 1);
  polyPoints[0] = x;
  polyPoints[3] = y;
  if (up != false) {
    polyPoints[0] = polyPoints[4];
    polyPoints[3] = iVar7;
    polyPoints[4] = x;
  }
  polyPoints[1] = y;
  polyPoints[2] = iVar9;
  polyPoints[5] = iVar7;
  GLIB_drawPolygon(&glibContext,3,polyPoints);
  if ((iVar8 != 0) && ((byte)(fillPercent + 100U) < 0xc9)) {
    if (iVar8 < 0) {
      y = iVar7 - (size * (byte)-fillPercent) / 100;
    }
    else {
      iVar7 = (size * iVar8) / 100 + y;
    }
    for (; y_00 = y, (int)x < iVar9; x = x + 1) {
      for (; iVar4 = polyPoints[3], iVar3 = polyPoints[2], iVar2 = polyPoints[1],
          iVar1 = polyPoints[0], (int)y_00 < iVar7; y_00 = y_00 + 1) {
        points[0] = polyPoints[0];
        points[1] = polyPoints[1];
        points[2] = polyPoints[2];
        points[3] = polyPoints[3];
        points[4] = x;
        points[5] = y_00;
        iVar8 = crossProduct(points);
        iVar6 = polyPoints[5];
        iVar5 = polyPoints[4];
        if (-1 < iVar8) {
          points[0] = iVar3;
          points[1] = iVar4;
          points[2] = polyPoints[4];
          points[3] = polyPoints[5];
          iVar8 = crossProduct(points);
          if (-1 < iVar8) {
            points[0] = iVar5;
            points[1] = iVar6;
            points[2] = iVar1;
            points[3] = iVar2;
            iVar8 = crossProduct(points);
            if (-1 < iVar8) {
              GLIB_drawPixel(&glibContext,x,y_00);
            }
          }
        }
      }
    }
  }
  return;
}



int rtcIntCallbackRegister(anon_subr_void_void_ptr *pFunction,void *argument,uint frequency)

{
  return 0;
}



int responsePrintInternal(StripMode_t stripMode,char *command,char *formatString,va_list args)

{
  char *pcVar1;
  char *pcVar2;
  size_t __n;
  size_t __n_00;
  char *__s;
  int iVar3;
  int iVar4;
  
  putchar(0x7b);
  if (command != (char *)0x0) {
    iprintf("{(%s)}",command);
  }
  __n = 0;
  iVar3 = 0;
  pcVar1 = formatString;
  do {
    if (formatString == (char *)0x0) {
LAB_00006e0c:
      viprintf(buffer,args);
      if ((int)__n < 0) {
        iprintf(" {internal_error:%d}",-__n);
      }
      else {
        __n = 0;
      }
      puts("}");
      return __n;
    }
    formatString = strchr(pcVar1,0x2c);
    if (formatString == (char *)0x0) {
      __n_00 = strlen(pcVar1);
    }
    else {
      __n_00 = (int)formatString - (int)pcVar1;
    }
    __s = buffer + iVar3;
    if (0x100U - iVar3 < __n_00 + 3) {
      __n = 0xfffffff5;
      goto LAB_00006e0c;
    }
    iVar4 = 0;
    pcVar2 = __s;
    while ((iVar4 = iVar4 + 1, __n_00 != 0 && (*pcVar1 == '\n'))) {
      *pcVar2 = '\n';
      __n_00 = __n_00 - 1;
      pcVar1 = pcVar1 + 1;
      pcVar2 = pcVar2 + 1;
    }
    *pcVar2 = '{';
    memcpy(__s + iVar4,pcVar1,__n_00);
    __n = iVar4 + __n_00 + 1;
    __s[iVar4 + __n_00] = '}';
    __s[__n] = '\0';
    pcVar1 = strchr(__s,0x3a);
    if (pcVar1 == (char *)0x0) {
      if (stripMode == STRIP_NONE) {
        __n = 0xfffffff4;
        goto LAB_00006e0c;
      }
    }
    else {
      pcVar2 = strchr(pcVar1 + 1,0x3a);
      if (pcVar2 != (char *)0x0) {
        __n = 0xfffffff3;
        goto LAB_00006e0c;
      }
      if (stripMode == STRIP_TAG) {
        __n = __n - ((int)pcVar1 - (int)__s);
        memmove(buffer + iVar3 + 1,pcVar1 + 1,__n);
      }
      else {
        if (stripMode == STRIP_VALUE) {
          __n = (int)pcVar1 - (int)__s;
          *pcVar1 = '}';
        }
        if (stripMode == STRIP_VALUE) {
          pcVar1[1] = '\0';
          __n = __n + 1;
        }
      }
    }
    if ((int)__n < 0) goto LAB_00006e0c;
    iVar3 = iVar3 + __n;
    pcVar1 = formatString + 1;
  } while( true );
}



_Bool responsePrintHeader(char *command,char *formatString,...)

{
  int iVar1;
  uint uVar2;
  undefined4 in_r2;
  undefined4 in_r3;
  va_list ap;
  undefined4 uStack8;
  undefined4 uStack4;
  
  uStack8 = in_r2;
  uStack4 = in_r3;
  putchar(0x23);
  iVar1 = responsePrintInternal(STRIP_VALUE,command,formatString,(va_list)&uStack8);
  uVar2 = count_leading_zeroes(iVar1);
  return SUB41(uVar2 >> 5,0);
}



_Bool responsePrintMulti(char *formatString,...)

{
  int iVar1;
  uint uVar2;
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
  uVar2 = count_leading_zeroes(iVar1);
  return SUB41(uVar2 >> 5,0);
}



_Bool responsePrint(char *command,char *formatString,...)

{
  int iVar1;
  uint uVar2;
  undefined4 in_r2;
  undefined4 in_r3;
  va_list ap;
  undefined4 uStack8;
  undefined4 uStack4;
  
  uStack8 = in_r2;
  uStack4 = in_r3;
  iVar1 = responsePrintInternal(STRIP_NONE,command,formatString,(va_list)&uStack8);
  uVar2 = count_leading_zeroes(iVar1);
  return SUB41(uVar2 >> 5,0);
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



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void apcConfigure(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  if ((apcEnabled == '\0') || (param_1 < 0x79)) {
    _DAT_4308128c = 0;
  }
  else {
    uVar1 = read_volatile_4(RAC->.PAPKDCTRL);
    write_volatile_4(RAC->.PAPKDCTRL,uVar1 & 0xffff2082);
    uVar1 = read_volatile_4(RAC->.SGPAPKDCTRL);
    write_volatile_4(RAC->.SGPAPKDCTRL,uVar1 & 0xffff2082);
    uVar1 = read_volatile_4(RAC->.PAPKDCTRL);
    uVar2 = ((param_1 - 0x93U) / 5 + 9) * 4;
    write_volatile_4(RAC->.PAPKDCTRL,uVar1 | 0xd700 | uVar2);
    uVar1 = read_volatile_4(RAC->.SGPAPKDCTRL);
    write_volatile_4(RAC->.SGPAPKDCTRL,uVar2 | uVar1 | 0xd700);
    _DAT_4308128c = 1;
  }
  peakDetectorOldSlices = read_volatile_4(Peripherals::SEQ.REG0E8);
  return;
}



int PA_OutputPowerGet(void)

{
  return (int)gPaConfig.power;
}



void PA_20dbmConfigSet(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG0E8);
  uVar2 = read_volatile_4(RAC->.PACTRL0);
  write_volatile_4(RAC->.PACTRL0,uVar2 & 0xfffffff8);
  write_volatile_4(Peripherals::SEQ.REG0E8,uVar1 & 0xbfffffe8 | 0x40000014);
  uVar1 = read_volatile_4(RAC->.PACTRL0);
  write_volatile_4(RAC->.PACTRL0,uVar1 | 4);
  uVar1 = read_volatile_4(RAC->.PABIASCTRL1);
  write_volatile_4(RAC->.PABIASCTRL1,uVar1 & 0xfffffff8);
  uVar1 = read_volatile_4(RAC->.PABIASCTRL1);
  write_volatile_4(RAC->.PABIASCTRL1,uVar1 | 5);
  uVar1 = read_volatile_4(RAC->.PABIASCTRL0);
  write_volatile_4(RAC->.PABIASCTRL0,uVar1 & 0xffffff3f);
  uVar1 = read_volatile_4(RAC->.PABIASCTRL0);
  write_volatile_4(RAC->.PABIASCTRL0,uVar1 | 0x81);
  return;
}



void PA_0dbmConfigSet(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG0E8);
  uVar2 = read_volatile_4(RAC->.PACTRL0);
  write_volatile_4(RAC->.PACTRL0,uVar2 & 0xfffffff8);
  write_volatile_4(Peripherals::SEQ.REG0E8,uVar1 & 0xbfffffe8 | 3);
  uVar1 = read_volatile_4(RAC->.PACTRL0);
  write_volatile_4(RAC->.PACTRL0,uVar1 | 3);
  uVar1 = read_volatile_4(RAC->.PABIASCTRL1);
  write_volatile_4(RAC->.PABIASCTRL1,uVar1 & 0xfffffff8);
  uVar1 = read_volatile_4(RAC->.PABIASCTRL1);
  write_volatile_4(RAC->.PABIASCTRL1,uVar1 | 6);
  uVar1 = read_volatile_4(RAC->.PABIASCTRL0);
  write_volatile_4(RAC->.PABIASCTRL0,uVar1 & 0xffbfff3e);
  uVar1 = read_volatile_4(RAC->.PAPKDCTRL);
  write_volatile_4(RAC->.PAPKDCTRL,uVar1 & 0xffff3fff);
  return;
}



void PA_SubGhz20dbmConfigSet(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG0E8);
  write_volatile_4(Peripherals::SEQ.REG0E8,uVar1 & 0xbfffffe8 | 0x40000020);
  uVar1 = read_volatile_4(RAC->.SGPABIASCTRL1);
  write_volatile_4(RAC->.SGPABIASCTRL1,uVar1 & 0xffff88ff);
  uVar1 = read_volatile_4(RAC->.SGPABIASCTRL1);
  write_volatile_4(RAC->.SGPABIASCTRL1,uVar1 | 0x4500);
  uVar1 = read_volatile_4(RAC->.SGPABIASCTRL0);
  write_volatile_4(RAC->.SGPABIASCTRL0,uVar1 | 1);
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



uint PA_StripesAndSlicesSet(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = read_volatile_4(CMU->RFLOCK0);
  uVar1 = read_volatile_4(Peripherals::SEQ.REG0E8);
  uVar3 = (param_1 << 0x17) >> 0x1c;
  iVar4 = count_leading_zeroes(~uVar5 & 0x1fc000);
  uVar5 = 0x13 - iVar4;
  if (uVar5 < uVar3) {
    if (uVar5 != 0) {
      uVar2 = 0x1f;
      uVar3 = uVar5;
      goto LAB_000071fc;
    }
  }
  else {
    if (uVar3 != 0) {
      uVar2 = param_1 & 0x1f;
      if (uVar2 == 0) {
        uVar2 = 1;
      }
      goto LAB_000071fc;
    }
  }
  uVar2 = 1;
  uVar3 = uVar2;
LAB_000071fc:
  write_volatile_4(Peripherals::SEQ.REG0E8,
                   uVar1 & 0xe0c03fff | 0x3fc8 | uVar2 << 0x18 |
                   ((1 << (uVar3 & 0xff)) - 1U & 0xff) << 0xe);
  uVar2 = uVar2 | uVar3 << 5;
  uVar1 = read_volatile_4(RAC->.PABIASCTRL0);
  if ((param_1 & 0x8000) == 0) {
    write_volatile_4(RAC->.PABIASCTRL0,uVar1 & 0xffbfffff);
    return uVar2;
  }
  write_volatile_4(RAC->.PABIASCTRL0,uVar1 | 0x400000);
  return uVar2 | 0x8000;
}



uint PA_StripesAndSlicesCommonCalc(int param_1,short *param_2)

{
  int iVar1;
  uint uVar2;
  
  if (*param_2 <= param_1) {
    param_1 = (int)*param_2;
  }
  iVar1 = -((param_1 - 200U) / 0x28);
  if (6 < iVar1) {
    iVar1 = 7;
  }
  uVar2 = param_1 * (param_2 + iVar1 * 4)[3] + *(int *)(param_2 + iVar1 * 4 + 4);
  if (0 < param_1) {
    uVar2 = uVar2 + 500;
  }
  uVar2 = uVar2 / 1000;
  if ((iVar1 != 7) && (gPaConfig.paSel != PA_SEL_SUBGIG)) {
    uVar2 = uVar2 | 0x8000;
  }
  return uVar2;
}



uint PA_PowerFromStripesAndSlicesCommonCalc(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 1;
  do {
    if (*(ushort *)(param_2 + iVar2 * 8) < param_1) break;
    iVar2 = iVar2 + 1;
  } while (iVar2 != 8);
  param_2 = param_2 + (iVar2 + -1) * 8;
  uVar1 = (param_1 & 0xffff7fff) * 1000 - *(int *)(param_2 + 4);
  if (0 < (int)uVar1) {
    uVar1 = uVar1 + 500;
  }
  return uVar1 / (uint)(int)*(short *)(param_2 + 2);
}



void PA_PowerLevelOptimize(int param_1)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG0E8);
  if (param_1 < 0x83) {
    write_volatile_4(Peripherals::SEQ.REG0E8,uVar1 & 0xffffc037 | ((uVar1 << 10) >> 0x18) << 6);
    if (param_1 < 0x1f) {
      uVar1 = read_volatile_4(RAC->.PABIASCTRL0);
      write_volatile_4(RAC->.PABIASCTRL0,uVar1 & 0xfffffffe);
      uVar1 = read_volatile_4(RAC->.SGPABIASCTRL0);
      uVar1 = uVar1 & 0xfffffffe;
      goto LAB_00007322;
    }
  }
  else {
    write_volatile_4(Peripherals::SEQ.REG0E8,uVar1 & 0xffffc037 | 0x3fc8);
  }
  uVar1 = read_volatile_4(RAC->.PABIASCTRL0);
  write_volatile_4(RAC->.PABIASCTRL0,uVar1 | 1);
  uVar1 = read_volatile_4(RAC->.SGPABIASCTRL0);
  uVar1 = uVar1 | 1;
LAB_00007322:
  write_volatile_4(RAC->.SGPABIASCTRL0,uVar1);
  apcConfigure();
  return;
}



void PA_StripesAndSlicesCalc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (gPaConfig.paSel == PA_SEL_2P4_LP) {
    uVar3 = read_volatile_4(Peripherals::SEQ.REG0E8);
    iVar1 = 6;
    do {
      if ((int)*(short *)(&power0dBmParams + iVar1 * 2) <= param_1 + gPaConfig.offset) break;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    iVar2 = (int)*(short *)(&power0dBmParams + iVar1 * 2);
    peakDetectorOldSlices = uVar3 & 0xe0c0003f | (iVar1 + 1) * 0x1000000;
    write_volatile_4(Peripherals::SEQ.REG0E8,peakDetectorOldSlices);
  }
  else {
    uVar3 = (uint)gPaConfig.voltMode;
    if (gPaConfig.paSel != PA_SEL_2P4_HP) {
      uVar3 = uVar3 + 2;
    }
    iVar2 = uVar3 * 0x44;
    PA_StripesAndSlicesCommonCalc
              (param_1 + gPaConfig.offset,&paParams + iVar2,&paParams,uVar3,param_4);
    iVar1 = PA_StripesAndSlicesSet();
    if (iVar1 == 0x21) {
      iVar2 = (int)*(short *)(&DAT_0001409a + iVar2);
    }
    else {
      iVar2 = PA_PowerFromStripesAndSlicesCommonCalc(iVar1,&UNK_0001409c + iVar2);
    }
  }
  PA_PowerLevelOptimize(iVar2);
  gPaConfig.power = (short)iVar2 - gPaConfig.offset;
  return;
}



int PA_OutputPowerSet(void)

{
  PA_StripesAndSlicesCalc();
  return (int)gPaConfig.power;
}



void PA_PeakDetectorHighRun(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG0E8);
  uVar3 = uVar1 >> 1 & 0x1fc000;
  write_volatile_4(Peripherals::SEQ.REG0E8,uVar1 & 0xffc03fff | uVar3);
  iVar2 = SYNTH_Is2p4GHz();
  if (iVar2 == 0) {
    uVar1 = read_volatile_4(RAC->.SGPACTRL0);
    write_volatile_4(RAC->.SGPACTRL0,uVar1 & 0xffc03fff | uVar3);
  }
  else {
    uVar1 = read_volatile_4(RAC->.PACTRL0);
    write_volatile_4(RAC->.PACTRL0,uVar1 & 0xffc03fff | uVar3);
  }
  write_volatile_4(RAC->.IFC,0x2000000);
  return;
}



void PA_PeakDetectorLowRun(void)

{
  uint uVar1;
  
  write_volatile_4(Peripherals::SEQ.REG0E8,peakDetectorOldSlices);
  uVar1 = read_volatile_4(RAC->.IEN);
  write_volatile_4(RAC->.IEN,uVar1 & 0xfbffffff);
  return;
}



void PA_BatHighRun(void)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = SYNTH_Is2p4GHz();
  if (iVar2 == 0) {
    uVar1 = read_volatile_4(RAC->.SGPACTRL0);
    write_volatile_4(RAC->.SGPACTRL0,uVar1 & 0x7fdfffff);
  }
  else {
    uVar1 = read_volatile_4(RAC->.PACTRL0);
    write_volatile_4(RAC->.PACTRL0,uVar1 & 0x7fdfffff);
  }
  uVar1 = read_volatile_4(RAC->.IEN);
  write_volatile_4(RAC->.IEN,uVar1 & 0xf7ffffff);
  return;
}



uint16_t PA_RampTimeGet(void)

{
  return gPaConfig.rampTime;
}



void PA_RampConfigSet(uint *param_1)

{
  uint uVar1;
  
  write_volatile_4(MODEM->.RAMPLEV,param_1[1]);
  uVar1 = read_volatile_4(MODEM->.RAMPCTRL);
  write_volatile_4(MODEM->.RAMPCTRL,uVar1 & 0xfffff000);
  uVar1 = read_volatile_4(MODEM->.RAMPCTRL);
  write_volatile_4(MODEM->.RAMPCTRL,*param_1 | uVar1);
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
  
  uVar4 = read_volatile_4(MODEM->.RAMPLEV);
  uVar6 = read_volatile_4(MODEM->.RAMPLEV);
  uVar5 = read_volatile_4(MODEM->.RAMPLEV);
  uVar1 = read_volatile_4(MODEM->.RAMPCTRL);
  uVar2 = read_volatile_4(MODEM->.RAMPCTRL);
  uVar3 = read_volatile_4(MODEM->.RAMPCTRL);
  uVar6 = (uVar6 << 0x10) >> 0x18;
  return ((int)(((uVar5 << 8) >> 0x18) - uVar6 << ((uVar3 << 0x14) >> 0x1c)) >> 5) +
         ((int)(uVar6 - (uVar4 & 0xff) << ((uVar2 << 0x18) >> 0x1c)) >> 5) +
         ((int)((uVar4 & 0xff) << (uVar1 & 0xf)) >> 5);
}



uint16_t PA_RampTimeSet(uint16_t ramptime)

{
  uint32_t uVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  uint local_18;
  int local_14;
  
  uVar2 = (uint)ramptime;
  if (gPaConfig.paSel == PA_SEL_SUBGIG) {
    uVar5 = 0x96;
  }
  else {
    if (gPaConfig.paSel == PA_SEL_2P4_LP) {
      uVar5 = 0x32;
    }
    else {
      uVar5 = 0xb4;
    }
  }
  if (uVar2 != 0) {
    local_18 = uVar2;
    uVar1 = SystemHFXOClockGet();
    cVar3 = -1;
    for (uVar2 = (((uVar1 / 1000) * uVar2) / uVar5 << 5) / 1000; uVar2 != 0; uVar2 = uVar2 >> 1) {
      cVar3 = cVar3 + '\x01';
    }
    iVar4 = (int)cVar3;
    if (0xf < iVar4) {
      iVar4 = 0xf;
      goto LAB_00007540;
    }
    if (-1 < iVar4) goto LAB_00007540;
  }
  iVar4 = 1;
LAB_00007540:
  local_18 = iVar4 << 8;
  local_14 = uVar5 << 0x10;
  PA_RampConfigSet(&local_18);
  iVar4 = PA_RampTimeCalc();
  uVar1 = SystemHFXOClockGet();
  gPaConfig.rampTime = (uint16_t)((ulonglong)(uint)(iVar4 * 10000) / ((ulonglong)uVar1 / 100));
  return (uint16_t)gPaConfig.rampTime;
}



void PA_CTuneSet(uint param_1,uint param_2)

{
  write_volatile_4(Peripherals::SEQ.PHYINFO,param_1 & 7 | (param_1 & 0x1f) << 4);
  write_volatile_4(Peripherals::SEQ.DYNAMIC_CHPWR_TABLE,param_2 & 7 | (param_2 & 0x1f) << 4);
  return;
}



void PA_BandSelect(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = SYNTH_LoDivGet();
  if (false) {
switchD_000075a6_caseD_2:
    write_volatile_4(Peripherals::SEQ.PHYINFO,0xf7);
    uVar2 = 0xa2;
  }
  else {
    switch(uVar1) {
    case 1:
      uVar2 = 0x44;
      if (gPaConfig.paSel != PA_SEL_2P4_LP) {
        write_volatile_4(Peripherals::SEQ.PHYINFO,0);
        goto LAB_000075d2;
      }
      break;
    default:
      goto switchD_000075a6_caseD_2;
    default:
      uVar2 = 0;
      break;
    case 5:
    case 6:
      uVar2 = 0x33;
    }
    write_volatile_4(Peripherals::SEQ.PHYINFO,uVar2);
  }
LAB_000075d2:
  write_volatile_4(Peripherals::SEQ.DYNAMIC_CHPWR_TABLE,uVar2);
  return;
}



bool RADIO_PA_Init(RADIO_PAInit_t *paInit)

{
  uint uVar1;
  uint uVar2;
  uint16_t uVar3;
  bool bVar4;
  
  if (paInit != (RADIO_PAInit_t *)0x0) {
    RADIO_CLKEnable();
    memset(&Peripherals::SEQ.REG0E8,0,0xc);
    if (paInit->paSel == PA_SEL_SUBGIG) {
      uVar1 = read_volatile_4(CMU->RFLOCK0);
      bVar4 = (uVar1 & 0x200000) == 0;
    }
    else {
      if (paInit->paSel == PA_SEL_2P4_LP) {
        uVar1 = read_volatile_4(CMU->RFLOCK0);
        bVar4 = (uVar1 & 0xc00000) == 0;
      }
      else {
        uVar1 = read_volatile_4(DAT_0fe081d4);
        uVar2 = read_volatile_4(CMU->RFLOCK0);
        bVar4 = (uVar1 & 1 ^ 1 | uVar2 & 0x400000) == 0;
      }
    }
    if (bVar4) {
      gPaConfig._0_4_ = *(undefined4 *)paInit;
      gPaConfig._4_4_ = *(undefined4 *)&paInit->offset;
      uVar3 = PA_RampTimeSet(paInit->rampTime);
      PA_PowerModeConfigSet(uVar3);
      PA_OutputPowerSet((int)paInit->power);
      uVar1 = read_volatile_4(RAC->.APC);
      write_volatile_4(RAC->.APC,uVar1 & 0xfffffff8);
      PA_BandSelect();
      return true;
    }
  }
  return false;
}



void RADIO_PTI_Init(byte *param_1)

{
  byte bVar1;
  GPIO_Port_TypeDef port;
  uint out;
  uint uVar2;
  
  if (param_1 == (byte *)0x0) {
    return;
  }
  RADIOCMU_ClockEnable(0x63400,1);
  CMU_ClockEnable(cmuClock_GPIO,true);
  sniffBaudHz = *(undefined4 *)(param_1 + 4);
  uVar2 = (uint)*param_1;
  write_volatile_4(FRC->.SNIFFCTRL,0xf8);
  write_volatile_4(FRC->.ROUTELOC0,
                   (uint)param_1[0xe] << 0x10 | (uint)param_1[0xb] << 8 | (uint)param_1[8]);
  if (uVar2 == 0) {
    sniffMode = 2;
    write_volatile_4(FRC->.ROUTEPEN,7);
    GPIO_PinModeSet(param_1[0xc],(uint)param_1[0xd],gpioModePushPull,0);
    port = param_1[0xf];
    bVar1 = param_1[0x10];
    out = uVar2;
  }
  else {
    if (uVar2 != 1) {
      if (uVar2 == 2) {
        sniffMode = 5;
        write_volatile_4(FRC->.ROUTEPEN,1);
      }
      else {
        if (uVar2 == 3) {
          write_volatile_4(FRC->.ROUTEPEN,0);
          sniffMode = 0;
          return;
        }
      }
      goto LAB_00007708;
    }
    port = param_1[0xf];
    write_volatile_4(FRC->.ROUTEPEN,5);
    bVar1 = param_1[0x10];
    out = 0;
    sniffMode = uVar2;
  }
  GPIO_PinModeSet(port,(uint)bVar1,gpioModePushPull,out);
LAB_00007708:
  GPIO_PinModeSet(param_1[9],(uint)param_1[10],gpioModePushPull,1);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RADIO_PTI_Enable(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = read_volatile_4(FRC->.SNIFFCTRL);
  uVar3 = sniffBaudHz;
  if (sniffBaudHz != 0) {
    iVar2 = RADIOCMU_ClockFreqGet(0x63400);
    uVar3 = ((iVar2 + (sniffBaudHz >> 1)) / sniffBaudHz - 1) * 0x100;
  }
  write_volatile_4(FRC->.SNIFFCTRL,uVar3 | uVar1 & 0xffff00fc | sniffMode);
  _DAT_430812f8 = 1;
  return;
}



void RADIO_PTI_AuxdataOutput(uint param_1)

{
  FRC *pFVar1;
  bool bVar2;
  
  pFVar1 = (FRC *)read_volatile_4(RAC->.SR3);
  bVar2 = (int)pFVar1 < 0;
  if (bVar2) {
    pFVar1 = &FRC->;
  }
  if (bVar2) {
    pFVar1->AUXDATA = param_1;
  }
  return;
}



void RADIO_BUFCClear(int param_1)

{
  *(undefined4 *)((param_1 * 0x30 + 0x42181028) * 0x20) = 1;
  return;
}



void RADIO_WriteSync(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return;
}



void RADIO_OrSync(uint *param_1,uint param_2)

{
  *param_1 = param_2 | *param_1;
  return;
}



void RADIO_XorSync(uint *param_1,uint param_2)

{
  *param_1 = param_2 ^ *param_1;
  return;
}



void RADIO_AndSync(uint *param_1,uint param_2)

{
  *param_1 = param_2 & *param_1;
  return;
}



void RADIO_BUFCWriteContSync(int param_1,byte *param_2,int param_3)

{
  CORE_irqState_t irqState;
  byte *pbVar1;
  
  pbVar1 = param_2 + param_3;
  irqState = CORE_EnterCritical();
  for (; param_2 != pbVar1; param_2 = param_2 + 1) {
    (&Peripherals::BUFC.BUF0_WRITEDATA)[param_1 * 0xc] = (uint)*param_2;
  }
  CORE_ExitCritical(irqState);
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



void RADIO_ClrBitSync(int param_1,int param_2)

{
  *(undefined4 *)((param_2 + (param_1 + 0x2100000) * 8) * 4) = 0;
  return;
}



void RADIO_SetBitSync(int param_1,int param_2)

{
  *(undefined4 *)((param_2 + (param_1 + 0x2100000) * 8) * 4) = 1;
  return;
}



void RADIO_SetAndForgetWrite(undefined4 param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 local_c;
  undefined4 uStack8;
  
  local_c = param_2;
  uStack8 = param_3;
  SYSTEM_ChipRevisionGet((SYSTEM_ChipRevision_TypeDef *)&local_c);
  write_volatile_4(RAC->.IFADCCTRL,0x5153e6c0);
  write_volatile_4(RAC->.IFPGACTRL,0x87e6);
  write_volatile_4(RAC->.LNAMIXCTRL1,0x880);
  write_volatile_4(RAC->.VCOCTRL,0xf00277a);
  if ((local_c._1_1_ == '\x01') && ((local_c & 0xff) < 2)) {
    write_volatile_4(Peripherals::SYNTH.VCOGAIN,0x28);
  }
  write_volatile_4(Peripherals::SYNTH.CTRL,0xac3f);
  write_volatile_4(AGC->.MANGAIN,0x1800000);
  write_volatile_4(RAC->.LNAMIXCTRL,0);
  write_volatile_4(RAC->.SYNTHREGCTRL,0x3636d80);
  uVar1 = read_volatile_4(Peripherals::SYNTH.VCDACCTRL);
  write_volatile_4(Peripherals::SYNTH.VCDACCTRL,uVar1 & 0xffffff80);
  uVar1 = read_volatile_4(Peripherals::SYNTH.VCDACCTRL);
  write_volatile_4(Peripherals::SYNTH.VCDACCTRL,uVar1 | 0x23);
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



void RADIO_Config(int param_1)

{
  CORE_irqState_t irqState;
  uint uVar1;
  void *__dest;
  uint uVar2;
  void *__src;
  
  param_1 = param_1 + 8;
  while( true ) {
    uVar1 = *(uint *)(param_1 + -8);
    if (uVar1 == 0xffffffff) break;
    uVar2 = (uVar1 << 8) >> 0x18;
    __dest = (void *)(uVar1 & 0xffff | (uint)(&regBases)[(uVar1 << 4) >> 0x1c]);
    if (uVar2 < 2) {
      (**(code **)(&EFRDRV_actionFunc + (uVar1 >> 0x1c) * 4))(__dest,*(undefined4 *)(param_1 + -4));
    }
    else {
      __src = *(void **)(param_1 + -4);
      irqState = CORE_EnterCritical();
      memcpy(__dest,__src,uVar2 << 2);
      CORE_ExitCritical(irqState);
    }
    param_1 = param_1 + 8;
  }
  PA_BandSelect();
  return;
}



void RADIO_RegisterIrqCallback(int param_1,undefined4 param_2)

{
  (&EFRDRV_irqClbk)[param_1] = param_2;
  return;
}



void FRC_PRI_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x000079ac. Too many branches
                    // WARNING: Treating indirect jump as call
  (*EFRDRV_irqClbk)();
  return;
}



void FRC_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x000079b8. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_20002d18)();
  return;
}



void RAC_RSM_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x000079c4. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_20002d28)();
  return;
}



void RAC_SEQ_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x000079d0. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_20002d28)();
  return;
}



void AGC_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x000079dc. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_20002d38)();
  return;
}



void PROTIMER_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x000079e8. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_20002d30)();
  return;
}



void BUFC_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x000079f4. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_20002d20)();
  return;
}



void MODEM_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x00007a00. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_20002d1c)();
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RADIO_TxBufferSet(undefined4 param_1,int param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  
  RADIO_BUFCClear(0);
  RADIO_BUFCWriteContSync(0,param_1,param_2);
  if (param_4 == 0) {
    return;
  }
  uVar1 = 0x100U - param_2 & 0xffff;
  bufcTxStreaming = (undefined2)param_2;
  DAT_20002ee2 = (undefined2)param_4;
  DAT_20002eec = (undefined2)uVar1;
  DAT_20002ee4 = param_1;
  DAT_20002ee8 = param_3;
  if (uVar1 < param_4) {
    RADIO_BUFCWriteContSync(0,param_3);
    _DAT_43021d90 = 1;
    return;
  }
  RADIO_BUFCWriteContSync(0,param_3,param_4,param_4);
  return;
}



void RADIO_TxBufferReset(void)

{
  RADIO_TxBufferSet(0,0,0,0);
  return;
}



void RADIO_TxAckBufferSet(undefined4 param_1,undefined4 param_2)

{
  RADIO_BUFCClear(3);
  RADIO_BUFCWriteContSync(3,param_1,param_2);
  write_volatile_4(Peripherals::BUFC.BUF3_CMD,4);
  return;
}



void RADIO_TxAckBufferReset(void)

{
  RADIO_TxAckBufferSet(0,0);
  return;
}



void RADIO_RXBufferEnableThrInt(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::BUFC.IEN);
  write_volatile_4(Peripherals::BUFC.IEN,uVar1 | 0x400);
  return;
}



void RADIO_RXBufferDisableThrInt(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::BUFC.IEN);
  write_volatile_4(Peripherals::BUFC.IEN,uVar1 & 0xfffffbff);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RADIO_RxBufferSet(int param_1)

{
  if (param_1 != 0) {
    _DAT_43022d80 = 1;
  }
  bufcRxStreaming = 0;
  DAT_20002edc = param_1;
  return;
}



undefined4 RADIO_RxBufferGet(void)

{
  return DAT_20002edc;
}



void RADIO_RxBufferReset(void)

{
  bufcRxStreaming = 0;
  RADIO_BUFCClear(1);
  RADIO_BUFCClear(2);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RADIO_BUFCIrqHandler(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = read_volatile_4(Peripherals::BUFC.IF);
  uVar2 = read_volatile_4(Peripherals::BUFC.IEN);
  write_volatile_4(Peripherals::BUFC.IFC,uVar1 & uVar2);
  uVar4 = read_volatile_4(Peripherals::BUFC.IEN);
  uVar4 = uVar4 & uVar1 & uVar2;
  if ((int)(uVar4 << 0x1d) < 0) {
    iVar3 = DAT_20002ee8 + (uint)DAT_20002eec;
    if (((uint)DAT_20002ee2 - (uint)DAT_20002eec & 0xffff) < 0xe1) {
      RADIO_BUFCWriteContSync(0,iVar3);
      _DAT_43021d90 = 0;
    }
    else {
      RADIO_BUFCWriteContSync(0,iVar3,0xe0);
      DAT_20002eec = DAT_20002eec + 0xe0;
    }
  }
  if ((int)(uVar4 << 0x15) < 0) {
    RFTEST_BerEmptyBufcAndUpdateStats();
  }
  if ((uVar4 & 0xa0a00) != 0) {
    RADIO_RxBufferReset();
  }
  if ((uVar4 & 9) != 0) {
    _DAT_43080114 = 1;
    RADIO_TxBufferReset();
  }
  if ((int)(uVar4 << 0x1e) < 0) {
    RADIO_TxBufferReset();
  }
  if ((uVar4 & 0x9000000) != 0) {
    _DAT_43080114 = 1;
    RADIO_TxAckBufferReset();
  }
  if ((int)(uVar4 << 6) < 0) {
    RADIO_TxAckBufferReset();
    return;
  }
  return;
}



int RADIO_RxTrailDataLength(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = read_volatile_4(FRC->.TRAILRXDATA);
  if ((uVar1 & 0x20) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = 4;
  }
  if ((int)(uVar1 << 0x1b) < 0) {
    iVar2 = iVar2 + 2;
  }
  if ((int)(uVar1 << 0x1c) < 0) {
    iVar2 = iVar2 + 2;
  }
  if ((int)(uVar1 << 0x1d) < 0) {
    iVar2 = iVar2 + 2;
  }
  if ((int)(uVar1 << 0x1e) < 0) {
    iVar2 = iVar2 + 1;
  }
  if ((int)(uVar1 << 0x1f) < 0) {
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}



bool RADIO_RxBufferPacketAvailable(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::BUFC.BUF2_STATUS);
  return 3 < (uVar1 & 0x1fff);
}



uint RADIO_RxBufferBytesAvailable(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::BUFC.BUF1_STATUS);
  return uVar1 & 0x1fff;
}



uint RADIO_TxBufferBytesAvailable(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::BUFC.BUF0_STATUS);
  return uVar1 & 0x1fff;
}



uint RADIO_RxBufferReadByte(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::BUFC.BUF1_READDATA);
  return uVar1 & 0xff;
}



void RADIO_FrameControlDescrBufferIdSet(int param_1,int param_2)

{
  (&FRC->.FCD0)[param_1] = (&FRC->.FCD0)[param_1] & 0xfffffcff;
  (&FRC->.FCD0)[param_1] = (&FRC->.FCD0)[param_1] | param_2 << 8;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RADIO_Init(void)

{
  uint uVar1;
  
  RADIO_CLKEnable();
  write_volatile_4(Peripherals::BUFC.BUF1_CTRL,2);
  write_volatile_4(Peripherals::BUFC.BUF1_ADDR,(uint)RADIO_rxBuffer);
  write_volatile_4(Peripherals::BUFC.BUF1_THRESHOLDCTRL,0xaf);
  write_volatile_4(Peripherals::BUFC.BUF0_CTRL,2);
  write_volatile_4(Peripherals::BUFC.BUF0_ADDR,(uint)&RADIO_txBuffer);
  write_volatile_4(Peripherals::BUFC.BUF0_THRESHOLDCTRL,0x2020);
  write_volatile_4(Peripherals::BUFC.BUF2_CTRL,0);
  write_volatile_4(Peripherals::BUFC.BUF2_ADDR,(uint)&RADIO_rxLengthBuffer);
  write_volatile_4(Peripherals::BUFC.BUF2_THRESHOLDCTR,0x3c);
  write_volatile_4(Peripherals::BUFC.BUF3_CTRL,0);
  write_volatile_4(Peripherals::BUFC.BUF3_ADDR,(uint)&RADIO_txAckBuffer);
  write_volatile_4(Peripherals::BUFC.BUF3_THRESHOLDCTRL,0x2020);
  RADIO_FrameControlDescrBufferIdSet(0,0);
  RADIO_FrameControlDescrBufferIdSet(1,0);
  RADIO_FrameControlDescrBufferIdSet(2,1);
  RADIO_FrameControlDescrBufferIdSet(3,1);
  uVar1 = read_volatile_4(FRC->.CTRL);
  write_volatile_4(FRC->.CTRL,uVar1 & 0xffffff0f);
  uVar1 = read_volatile_4(FRC->.CTRL);
  write_volatile_4(FRC->.CTRL,uVar1 | 0xa0);
  DAT_20002d20 = 0x7b05;
  _DAT_e000e280 = 0x80;
  _DAT_e000e100 = 0x80;
  RADIO_BUFCClear(0);
  RADIO_BUFCClear(1);
  RADIO_BUFCClear(2);
  RADIO_BUFCClear(3);
  uVar1 = read_volatile_4(Peripherals::BUFC.IEN);
  write_volatile_4(Peripherals::BUFC.IEN,uVar1 | 0xb0b0a0b);
  RADIO_RXBufferDisableThrInt();
  RADIO_SetAndForgetWrite();
  uVar1 = read_volatile_4(MODEM->.DCCOMP);
  write_volatile_4(MODEM->.DCCOMP,uVar1 | 3);
  write_volatile_4(RAC->.SR3,0);
  _DAT_43081280 = 1;
  SYNTH_KvnFreqCompensationEnable();
  SYNTH_DCDCRetimeEnable();
  _DAT_4308019c = 1;
  _DAT_430801a0 = 1;
  _DAT_430801a4 = 1;
  return;
}



void RADIO_FrameControlDescrConfigSet
               (int param_1,uint param_2,int param_3,int param_4,byte param_5,byte param_6)

{
  (&FRC->.FCD0)[param_1] = (&FRC->.FCD0)[param_1] & 0xffff8300;
  (&FRC->.FCD0)[param_1] =
       param_2 | (uint)param_6 << 10 | (uint)param_5 << 0xb | param_4 << 0xc | param_3 << 0xe |
       (&FRC->.FCD0)[param_1];
  return;
}



void RADIO_FrameDescsConfig
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  RADIO_FrameControlDescrConfigSet(0,0xff,param_1,param_2,param_3,param_4,param_3);
  RADIO_FrameControlDescrConfigSet(2,0xff,param_1,param_2,param_3,param_4);
  return;
}



void RADIO_BUFCReadContASync(int param_1,undefined *param_2,int param_3)

{
  undefined *puVar1;
  
  puVar1 = param_2 + param_3;
  for (; param_2 != puVar1; param_2 = param_2 + 1) {
    *param_2 = (char)(&Peripherals::BUFC.BUF0_READDATA)[param_1 * 0xc];
  }
  return;
}



void RADIO_RxBufferReadBytes(undefined4 param_1,undefined4 param_2)

{
  RADIO_BUFCReadContASync(1,param_1,param_2);
  return;
}



void RADIO_RxBufferDropBytes(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = param_1;
  for (; param_1 != 0; param_1 = param_1 - 1 & 0xffff) {
    RADIO_RxBufferReadBytes(&stack0xfffffff7,1,param_3,param_4,uVar1,param_2);
  }
  return;
}



void RADIO_RxLengthReadNext(ushort *param_1)

{
  int iVar1;
  
  iVar1 = RADIO_RxBufferPacketAvailable();
  if (iVar1 == 0) {
    *(undefined *)(param_1 + 1) = 0;
    *(undefined *)param_1 = 0xff;
    *(undefined *)((int)param_1 + 1) = 0xff;
    return;
  }
  RADIO_BUFCReadContASync(2,param_1,4);
  *param_1 = *param_1 & 0xff;
  return;
}



void RADIO_FRCErrorHandle(void)

{
  bufcRxStreaming = 0;
  RADIO_BUFCClear(1);
  RADIO_BUFCClear(2);
  return;
}



uint RADIO_UsToStimerTickCalc(uint param_1)

{
  uint uVar1;
  
  uVar1 = RADIOCMU_ClockFreqGet(0x75160);
  return ((uVar1 / 1000) * (param_1 & ~((int)param_1 >> 0x1f)) + 4000) / 8000 & 0xffff;
}



void RADIO_SeqInit(void *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  CORE_irqState_t irqState;
  int iVar4;
  
  read_volatile(RAC->.STATUS._0_1_);
  write_volatile_4(RAC->.VECTADDR,0x21000000);
  write_volatile_4(RAC->.SEQCTRL,1);
  irqState = CORE_EnterCritical();
  memcpy((void *)0x21000000,param_1,param_2 << 2);
  CORE_ExitCritical(irqState);
  write_volatile_4(RAC->.R6,0x21000fc0);
  uVar1 = read_volatile_4(Peripherals::SEQ.REG0E8);
  uVar2 = read_volatile_4(Peripherals::SEQ.DYNAMIC_CHPWR_TABLE);
  uVar3 = read_volatile_4(Peripherals::SEQ.PHYINFO);
  memset(&Peripherals::SEQ.REG068,0,0x98);
  write_volatile_4(Peripherals::SEQ.REG0E8,uVar1);
  write_volatile_4(Peripherals::SEQ.DYNAMIC_CHPWR_TABLE,uVar2);
  write_volatile_4(Peripherals::SEQ.PHYINFO,uVar3);
  iVar4 = RADIO_UsToStimerTickCalc(0x3c);
  write_volatile_4(Peripherals::SEQ.REG0BC,-iVar4);
  return;
}



uint RADIO_TxWarmTimeSet(uint param_1)

{
  short sVar1;
  undefined2 uVar2;
  
  if (param_1 < 100) {
    param_1 = 100;
  }
  else {
    if (12999 < param_1) {
      param_1 = 13000;
    }
  }
  txWarmTimeUs = (short)param_1;
  sVar1 = PA_RampTimeGet();
  sVar1 = (short)param_1 - sVar1;
  uVar2 = RADIO_UsToStimerTickCalc((int)sVar1);
  write_volatile_2(Peripherals::SEQ.REG0AC._0_2_,uVar2);
  uVar2 = RADIO_UsToStimerTickCalc((int)(short)(sVar1 + -0x14));
  write_volatile_2(Peripherals::SEQ.REG0AC._2_2_,uVar2);
  return param_1;
}



undefined2 RADIO_TxWarmTimeGet(void)

{
  return txWarmTimeUs;
}



uint RADIO_RxToTxTimeSet(uint param_1)

{
  short sVar1;
  undefined2 uVar2;
  
  if (param_1 < 100) {
    param_1 = 100;
  }
  else {
    if (12999 < param_1) {
      param_1 = 13000;
    }
  }
  sVar1 = PA_RampTimeGet();
  sVar1 = (short)param_1 - sVar1;
  uVar2 = RADIO_UsToStimerTickCalc((int)sVar1);
  write_volatile_2(Peripherals::SEQ.REG0A4._0_2_,uVar2);
  uVar2 = RADIO_UsToStimerTickCalc((int)(short)(sVar1 + -0x14));
  write_volatile_2(Peripherals::SEQ.REG0A4._2_2_,uVar2);
  return param_1;
}



uint RADIO_RxFrameToTxTimeSet(uint param_1)

{
  short sVar1;
  undefined2 uVar2;
  
  if (param_1 < 100) {
    param_1 = 100;
  }
  else {
    if (12999 < param_1) {
      param_1 = 13000;
    }
  }
  sVar1 = PA_RampTimeGet();
  sVar1 = (short)param_1 - sVar1;
  uVar2 = RADIO_UsToStimerTickCalc((int)sVar1);
  write_volatile_2(Peripherals::SEQ.REG0A8._0_2_,uVar2);
  uVar2 = RADIO_UsToStimerTickCalc((int)(short)(sVar1 + -0x14));
  write_volatile_2(Peripherals::SEQ.REG0A8._2_2_,uVar2);
  return param_1;
}



uint RADIO_TxToTxTimeSet(uint param_1)

{
  short sVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = PA_RampTimeGet();
  uVar4 = param_1;
  if (12999 < param_1) {
    uVar4 = 13000;
  }
  if (uVar4 < uVar3) {
    param_1 = PA_RampTimeGet();
    param_1 = param_1 & 0xffff;
  }
  else {
    if (12999 < param_1) {
      param_1 = 13000;
    }
  }
  sVar1 = PA_RampTimeGet();
  sVar1 = (short)param_1 - sVar1;
  uVar2 = RADIO_UsToStimerTickCalc((int)sVar1);
  write_volatile_2(Peripherals::SEQ.REG0B8._0_2_,uVar2);
  uVar2 = RADIO_UsToStimerTickCalc((int)(short)(sVar1 + -0x14));
  write_volatile_2(Peripherals::SEQ.REG0B8._2_2_,uVar2);
  return param_1;
}



uint RADIO_TxToRxTimeSet(uint param_1)

{
  uint uVar1;
  
  if (param_1 < 100) {
    param_1 = 100;
  }
  else {
    if (12999 < param_1) {
      param_1 = 13000;
    }
  }
  uVar1 = RADIO_UsToStimerTickCalc((int)(short)((short)param_1 + -4));
  write_volatile_4(Peripherals::SEQ.REG0B0,uVar1);
  return param_1;
}



short RADIO_RxWarmTimeSet(uint param_1)

{
  uint uVar1;
  
  if (param_1 < 100) {
    rxWarmTimeUs = 100;
  }
  else {
    if (12999 < param_1) {
      param_1 = 13000;
    }
    rxWarmTimeUs = (short)param_1;
  }
  uVar1 = RADIO_UsToStimerTickCalc((int)(short)(rxWarmTimeUs + -4));
  write_volatile_4(Peripherals::SEQ.REG09C,uVar1);
  return rxWarmTimeUs;
}



undefined2 RADIO_RxWarmTimeGet(void)

{
  return rxWarmTimeUs;
}



uint RADIO_RxSearchTimeSet(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 13000;
  if (param_1 < 0x32c9) {
    uVar2 = param_1;
  }
  uVar1 = RADIO_UsToStimerTickCalc((int)(short)uVar2);
  write_volatile_4(Peripherals::SEQ.REG0A0,uVar1);
  return uVar2;
}



uint RADIO_TxToRxSearchTimeSet(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 13000;
  if (param_1 < 0x32c9) {
    uVar2 = param_1;
  }
  uVar1 = RADIO_UsToStimerTickCalc((int)(short)uVar2);
  write_volatile_4(Peripherals::SEQ.REG0B4,uVar1);
  return uVar2;
}



uint RADIO_ComputeTxBaudrate(void)

{
  uint uVar1;
  uint32_t uVar2;
  
  uVar2 = CMU_ClockFreqGet(cmuClock_HF);
  uVar1 = read_volatile_4(MODEM->.TXBR);
  return (((uVar1 << 8) >> 0x18) * (uVar2 >> 3)) / (uVar1 & 0xffff);
}



uint RADIO_ComputeRxBaudrate(void)

{
  uint uVar1;
  uint uVar2;
  uint32_t uVar3;
  int iVar4;
  uint uVar5;
  
  uVar2 = read_volatile_4(MODEM->.CF);
  uVar1 = read_volatile_4(MODEM->.RXBR);
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
  uVar1 = read_volatile_4(MODEM->.CTRL0);
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
  
  uVar1 = read_volatile_4(MODEM->.CTRL0);
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
    uVar1 = read_volatile_4(MODEM->.CTRL0);
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



int RADIO_GetRSSI(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  uint uVar2;
  uint uVar3;
  short sVar4;
  
  do {
    irqState = CORE_EnterCritical();
    uVar2 = read_volatile_4(RAC->.STATUS);
    uVar2 = uVar2 & 0xf000000;
    uVar1 = read_volatile_4(AGC->.RSSI);
    uVar3 = read_volatile_4(RAC->.STATUS);
    uVar3 = uVar3 & 0xf000000;
    sVar4 = (short)uVar1 >> 6;
    CORE_ExitCritical(irqState);
    if (sVar4 != -0x200) {
      if (uVar3 != 0x2000000 && uVar3 != 0x3000000 || uVar2 != 0x2000000 && uVar2 != 0x3000000) {
        sVar4 = -0x200;
      }
      break;
    }
  } while ((uVar3 == 0x2000000 || uVar3 == 0x3000000) && (uVar2 == 0x2000000 || uVar2 == 0x3000000))
  ;
  return (int)sVar4;
}



undefined4 RADIO_AGCCCAThresholdSet(byte param_1)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(AGC->.CTRL1);
  write_volatile_4(AGC->.CTRL1,uVar1 & 0xffffff00);
  uVar1 = read_volatile_4(AGC->.CTRL1);
  write_volatile_4(AGC->.CTRL1,uVar1 | param_1);
  return 0;
}



undefined4
RADIO_SetAgcCcaParams(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  
  uVar4 = RADIO_ComputeRxBaudrate();
  for (uVar2 = 0; (uint)(1 << (uVar2 & 0xff)) < (uint)(param_1 * (int)uVar4) / 1000000;
      uVar2 = uVar2 + 1) {
    if (uVar2 == 0x10) {
      return 1;
    }
  }
  uVar3 = read_volatile_4(AGC->.CTRL1);
  write_volatile_4(AGC->.CTRL1,uVar3 & 0xfffff0ff);
  uVar3 = read_volatile_4(AGC->.CTRL1);
  uVar3 = uVar3 | uVar2 << 8;
  write_volatile_4(AGC->.CTRL1,uVar3);
  uVar2 = read_volatile_4(AGC->.CTRL1);
  if ((uVar2 & 0xff) == 0x80) {
    return 2;
  }
  uVar1 = RADIO_AGCCCAThresholdSet(param_2,(int)((ulonglong)uVar4 >> 0x20),uVar3,param_4);
  return uVar1;
}



undefined4
RADIO_CalcRssiPeriod(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  
  uVar4 = read_volatile_4(AGC->.CTRL1);
  write_volatile_4(AGC->.CTRL1,uVar4 | 0x8000);
  uVar4 = read_volatile_4(MODEM->.CF);
  uVar5 = read_volatile_4(MODEM->.CF);
  uVar6 = read_volatile_4(MODEM->.CF);
  uVar1 = (&modemCfDec0Factors)[uVar4 & 7];
  uVar3 = CMU_ClockFreqGet(cmuClock_HF);
  uVar10 = __aeabi_uldivmod((int)((ulonglong)uVar3 * 1000),(int)((ulonglong)uVar3 * 1000 >> 0x20),
                            uVar1,0,param_4);
  uVar10 = __aeabi_uldivmod((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),
                            ((uVar5 << 0xf) >> 0x12) + 1,0);
  uVar11 = __aeabi_uldivmod((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),((uVar6 << 9) >> 0x1a) + 1,
                            0);
  iVar8 = (int)(uVar11 >> 0x20);
  uVar4 = __aeabi_uldivmod(0xdb000000,0x7558b,(int)uVar11,iVar8);
  if (uVar4 < param_1) {
    return 1;
  }
  lVar2 = (uVar11 & 0xffffffff) * (ulonglong)param_1;
  uVar7 = (undefined4)lVar2;
  iVar8 = param_1 * iVar8 + (int)((ulonglong)lVar2 >> 0x20);
  uVar5 = __aeabi_uldivmod(uVar7,iVar8,1000000000,0);
  iVar9 = 1;
  uVar4 = 0;
  do {
    uVar6 = uVar4 + 1;
    if (uVar5 <= (uint)(1 << (uVar6 & 0xff))) {
LAB_00008302:
      uVar5 = read_volatile_4(AGC->.CTRL1);
      write_volatile_4(AGC->.CTRL1,uVar5 & 0xfffff0ff);
      uVar5 = read_volatile_4(AGC->.CTRL1);
      write_volatile_4(AGC->.CTRL1,uVar5 | uVar4 << 8);
      uVar10 = __aeabi_uldivmod(uVar7,iVar8,10000000,0);
      uVar10 = __aeabi_uldivmod((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),iVar9,0);
      iVar8 = __aeabi_uldivmod((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),100,0);
      uVar4 = ((int)uVar10 + iVar8 * -100 & 0xffU) / 3;
      if (uVar4 < 0x20) {
        if (uVar4 == 0) {
          uVar4 = read_volatile_4(AGC->.CTRL1);
          write_volatile_4(AGC->.CTRL1,uVar4 & 0xffe0ffff | 0x10000);
          uVar4 = read_volatile_4(AGC->.CTRL1);
          write_volatile_4(AGC->.CTRL1,uVar4 & 0xfc1fffff | 0x200000);
          return 0;
        }
      }
      else {
        uVar4 = 0x1f;
      }
      uVar5 = read_volatile_4(AGC->.CTRL1);
      write_volatile_4(AGC->.CTRL1,uVar5 & 0x3ffffff | iVar8 << 0x1a);
      uVar5 = read_volatile_4(AGC->.CTRL1);
      write_volatile_4(AGC->.CTRL1,uVar5 & 0xffe0ffff | uVar4 << 0x10);
      uVar4 = read_volatile_4(AGC->.CTRL1);
      write_volatile_4(AGC->.CTRL1,uVar4 | 0x3e00000);
      return 0;
    }
    if (uVar6 == 0x10) {
      uVar4 = 0xf;
      goto LAB_00008302;
    }
    iVar9 = iVar9 << 1;
    uVar4 = uVar6;
  } while( true );
}



void RADIO_SetCRCInitVal(uint param_1)

{
  write_volatile_4(CRC->.INIT,param_1);
  write_volatile_4(CRC->.CMD,1);
  return;
}



void setupPnForTest(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(FRC->.FCD0);
  write_volatile_4(FRC->.FCD0,uVar1 & 0xffffbfff);
  uVar1 = read_volatile_4(FRC->.FCD1);
  write_volatile_4(FRC->.FCD1,uVar1 & 0xffffbfff);
  uVar1 = read_volatile_4(FRC->.FCD2);
  write_volatile_4(FRC->.FCD2,uVar1 & 0xffffbfff);
  uVar1 = read_volatile_4(FRC->.FCD3);
  write_volatile_4(FRC->.FCD3,uVar1 & 0xffffbfff);
  write_volatile_4(FRC->.FECCTRL,1);
  write_volatile_4(FRC->.WHITECTRL,0x24);
  write_volatile_4(FRC->.WHITEPOLY,0x100);
  write_volatile_4(FRC->.WHITEINIT,0x138);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RFTEST_StartRx(void)

{
  uint uVar1;
  
  do {
    uVar1 = read_volatile_4(RAC->.STATUS);
  } while ((uVar1 & 0xf000000) != 0);
  RADIO_RxBufferReset();
  _DAT_43080004 = 1;
  return;
}



void RFTEST_StopRx(undefined4 param_1,undefined4 param_2,int param_3)

{
  CORE_irqState_t irqState;
  uint uVar1;
  bool bVar2;
  
  uVar1 = read_volatile_4(RAC->.RXENSRCEN);
  write_volatile_4(RAC->.RXENSRCEN,uVar1 & 0xffffff00);
  irqState = CORE_EnterCritical();
  uVar1 = read_volatile_4(RAC->.STATUS);
  uVar1 = (uVar1 << 4) >> 0x1c;
  bVar2 = uVar1 == 3;
  if (bVar2) {
    param_3 = 0x21000f68;
    uVar1 = read_volatile_4(Peripherals::SEQ.REG070);
    uVar1 = uVar1 & 0xffffff01 | 0xe;
  }
  if (bVar2) {
    *(uint *)(param_3 + 8) = uVar1;
  }
  write_volatile_4(FRC->.CMD,1);
  CORE_ExitCritical(irqState);
  uVar1 = read_volatile_4(RAC->.STATUS);
  if ((uVar1 << 4) >> 0x1c == 6) {
    uVar1 = read_volatile_4(RAC->.CMD);
    write_volatile_4(RAC->.CMD,uVar1 | 0x40);
    RADIO_RxBufferReset();
  }
  do {
    uVar1 = read_volatile_4(RAC->.STATUS);
  } while ((uVar1 & 0xf000000) != 0);
  return;
}



void RFTEST_SaveRadioConfiguration(void)

{
  if (testModeRegisterState == '\0') {
    DAT_20002f08 = read_volatile_4(MODEM->.AFC);
    DAT_20002f0c = read_volatile_4(MODEM->.CTRL0);
    DAT_20002f10 = read_volatile_4(MODEM->.CTRL1);
    DAT_20002f14 = read_volatile_4(MODEM->.MODINDEX);
    DAT_20002f18 = read_volatile_4(MODEM->.PRE);
    DAT_20002f1c = read_volatile_4(MODEM->.TIMING);
    DAT_20002f20 = read_volatile_4(FRC->.DFLCTRL);
    DAT_20002f24 = read_volatile_4(FRC->.CTRL);
    DAT_20002f28 = read_volatile_4(FRC->.FECCTRL);
    DAT_20002f2c = read_volatile_4(FRC->.FCD0);
    DAT_20002f30 = read_volatile_4(FRC->.FCD1);
    DAT_20002f34 = read_volatile_4(FRC->.FCD2);
    DAT_20002f38 = read_volatile_4(FRC->.FCD3);
    DAT_20002f3c = read_volatile_4(FRC->.WHITECTRL);
    DAT_20002f40 = read_volatile_4(FRC->.WHITEPOLY);
    DAT_20002f44 = read_volatile_4(FRC->.WHITEINIT);
    DAT_20002f48 = read_volatile_4(Peripherals::SEQ.SYNTHLPFCTRLTX);
    DAT_20002f4c = read_volatile_4(FRC->.SNIFFCTRL);
    DAT_20002f50 = read_volatile_4(FRC->.IEN);
    write_volatile_4(FRC->.IEN,0);
    testModeRegisterState = '\x01';
  }
  return;
}



void RFTEST_RestoreRadioConfiguration(void)

{
  if (testModeRegisterState != '\0') {
    write_volatile_4(MODEM->.AFC,DAT_20002f08);
    write_volatile_4(MODEM->.CTRL0,DAT_20002f0c);
    write_volatile_4(MODEM->.CTRL1,DAT_20002f10);
    write_volatile_4(MODEM->.MODINDEX,DAT_20002f14);
    write_volatile_4(MODEM->.PRE,DAT_20002f18);
    write_volatile_4(FRC->.DFLCTRL,DAT_20002f20);
    write_volatile_4(FRC->.CTRL,DAT_20002f24);
    write_volatile_4(FRC->.FECCTRL,DAT_20002f28);
    write_volatile_4(FRC->.FCD0,DAT_20002f2c);
    write_volatile_4(FRC->.FCD1,DAT_20002f30);
    write_volatile_4(FRC->.FCD2,DAT_20002f34);
    write_volatile_4(FRC->.FCD3,DAT_20002f38);
    write_volatile_4(FRC->.WHITECTRL,DAT_20002f3c);
    write_volatile_4(FRC->.WHITEPOLY,DAT_20002f40);
    write_volatile_4(FRC->.WHITEINIT,DAT_20002f44);
    write_volatile_4(Peripherals::SEQ.SYNTHLPFCTRLTX,DAT_20002f48);
    write_volatile_4(FRC->.SNIFFCTRL,DAT_20002f4c);
    write_volatile_4(FRC->.IFC,0x7ffff);
    write_volatile_4(FRC->.IEN,DAT_20002f50);
    testModeRegisterState = '\0';
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RFTEST_StartCwTx(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.SYNTHLPFCTRLTX);
  write_volatile_4(Peripherals::SEQ.SYNTHLPFCTRLTX,uVar1 & 0xfffffff0);
  write_volatile_4(MODEM->.MODINDEX,0);
  uVar1 = read_volatile_4(MODEM->.CTRL0);
  write_volatile_4(MODEM->.CTRL0,uVar1 & 0xfffffe3f | 0x100);
  uVar1 = read_volatile_4(MODEM->.PRE);
  write_volatile_4(MODEM->.PRE,~(~(uVar1 << 0x10) >> 0x10));
  write_volatile_4(FRC->.DFLCTRL,5);
  _DAT_43000800 = 1;
  _DAT_43080100 = 1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RFTEST_StartStreamTx(void)

{
  setupPnForTest();
  write_volatile_4(FRC->.SNIFFCTRL,0);
  write_volatile_4(FRC->.DFLCTRL,5);
  _DAT_43000800 = 1;
  _DAT_43080100 = 1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RFTEST_StopTx(void)

{
  uint uVar1;
  
  do {
    uVar1 = read_volatile_4(FRC->.DFLCTRL);
    if ((uVar1 & 7) != 5) {
      _DAT_43080114 = 1;
      return;
    }
    uVar1 = read_volatile_4(FRC->.IF);
  } while (-1 < (int)(uVar1 << 0x1d));
  _DAT_43080114 = 1;
  return;
}



void RFTEST_BerStop(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(FRC->.RXCTRL);
  write_volatile_4(FRC->.RXCTRL,uVar1 & 0xffffffbf);
  RFTEST_StopRx();
  RADIO_RXBufferDisableThrInt();
  return;
}



void RFTEST_BerEmptyBufcAndUpdateStats(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  for (iVar1 = RADIO_RxBufferBytesAvailable(); iVar1 != 0; iVar1 = iVar1 + -1) {
    uVar2 = RADIO_RxBufferReadByte();
    if (berSkipBytesLeft == 0) {
      if ((berTotalBytesLeft != 0) || (berInfiniteMode != '\0')) {
        berTotalBytesLeft = berTotalBytesLeft + -1;
        berTotalErrors =
             berTotalErrors +
             ((uint)(byte)(&DAT_000141e5)[uVar2 & 0xf] +
              (uint)(byte)(&DAT_000141e5)[(uVar2 << 0x14) >> 0x18] & 0xff);
        berTotalBits = berTotalBits + 8;
        iVar3 = RADIO_GetRSSI();
        DAT_20002efc._0_1_ = (undefined)(iVar3 >> 2);
      }
    }
    else {
      berSkipBytesLeft = berSkipBytesLeft + -1;
    }
  }
  uVar2 = berTotalBits;
  if (berTotalBits < DAT_20002ef4) {
    uVar2 = 0xffffffff;
  }
  if (berTotalErrors < DAT_20002ef8) {
    DAT_20002ef8 = 0xffffffff;
  }
  else {
    DAT_20002ef8 = berTotalErrors;
  }
  DAT_20002ef4 = uVar2;
  return;
}



void RFTEST_ResetBerStats(int param_1)

{
  if (0x1ffffffe < param_1 - 1U) {
    param_1 = 0x1fffffff;
  }
  berStats = param_1 << 3;
  DAT_20002ef4 = 0;
  DAT_20002ef8 = 0;
  DAT_20002efc._0_1_ = 0;
  berInfiniteMode = 0;
  berTotalBits = 0;
  berTotalBytesLeft = param_1;
  berTotalErrors = 0;
  berSkipBytesLeft = berSkipBytes;
  return;
}



void RFTEST_ReportBerStats(RAIL_BerStatus_t *berstats)

{
  uint32_t uVar1;
  uint32_t uVar2;
  undefined4 uVar3;
  
  uVar3 = DAT_20002efc;
  uVar2 = DAT_20002ef8;
  uVar1 = DAT_20002ef4;
  berstats->bitsTotal = berStats;
  berstats->bitsTested = uVar1;
  berstats->bitErrors = uVar2;
  *(undefined4 *)&berstats->rssi = uVar3;
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



uint SYNTH_IfFreqCompute(void)

{
  uint uVar1;
  uint32_t uVar2;
  uint uVar3;
  
  uVar2 = SystemHFXOClockGet();
  uVar3 = read_volatile_4(MODEM->.CF);
  uVar1 = read_volatile_4(MODEM->.CF);
  uVar3 = (uVar3 << 6) >> 0x1d;
  if (uVar3 - 1 < 4) {
    uVar3 = (uint)(byte)(&DAT_000141fd)[uVar3];
  }
  else {
    uVar3 = 7;
  }
  if ((uVar1 & 7) == 0) {
    uVar3 = uVar3 * 3;
  }
  else {
    if ((uVar1 & 7) - 3 < 2) {
      uVar3 = uVar3 << 3;
    }
    else {
      uVar3 = uVar3 << 2;
    }
  }
  return uVar2 / uVar3;
}



uint SYNTH_LoDivGet(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = read_volatile_4(Peripherals::SYNTH.DIVCTRL);
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
  
  uVar1 = read_volatile_4(RAC->.IFPGACTRL);
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
  uint uVar1;
  uint32_t uVar2;
  uint uVar3;
  
  uVar2 = SystemHFXOClockGet();
  uVar3 = param_1 / uVar2;
  if (((param_1 - uVar2 * uVar3) * 100) / uVar2 == 0) {
    uVar3 = uVar3 - 1;
  }
  uVar1 = read_volatile_4(RAC->.HFXORETIMECTRL);
  write_volatile_4(RAC->.HFXORETIMECTRL,uVar1 & 0xfffff88f);
  uVar1 = read_volatile_4(RAC->.HFXORETIMECTRL);
  write_volatile_4(RAC->.HFXORETIMECTRL,
                   uVar1 | ((uVar3 >> 1) - 1) * 0x10 | ((uVar3 + 1 >> 1) - 1) * 0x100);
  return;
}



// WARNING: Could not reconcile some variable overlaps

void SYNTH_RetimeClkConfig(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 in_r3;
  int iVar3;
  uint uVar4;
  undefined4 local_1c;
  undefined4 uStack24;
  undefined4 local_14;
  
  local_1c = 0x2010000;
  uStack24 = 0x3030302;
  local_14 = CONCAT31((int3)((uint)in_r3 >> 8),3);
  uVar2 = read_volatile_4(Peripherals::SYNTH.CHCTRL);
  uVar1 = read_volatile_4(Peripherals::SYNTH.IFFREQ);
  iVar3 = currIfFrequency;
  if ((uVar1 & 0x100000) == 0) {
    iVar3 = -currIfFrequency;
  }
  uVar2 = currChSpacing * uVar2 + currRfFrequency + iVar3;
  uVar4 = (uint)*(byte *)((int)&local_1c + uVar2 / 625000000 + 1);
  uVar2 = uVar2 >> uVar4;
  uVar1 = read_volatile_4(RAC->.MMDCTRL);
  write_volatile_4(RAC->.MMDCTRL,uVar1 & 0xffffc200);
  uVar1 = read_volatile_4(RAC->.MMDCTRL);
  write_volatile_4(RAC->.MMDCTRL,
                   uVar1 | uVar4 << 0xc |
                   (uVar2 + (dcdcRetimeClkTarget >> 1)) / dcdcRetimeClkTarget - 1 |
                   (uint)*(byte *)((int)&local_1c + uVar2 / 325000000 + 1) << 10);
  SYNTH_RetimeLimitsConfig();
  return;
}



void SYNTH_Config(int param_1,uint param_2)

{
  longlong lVar1;
  uint uVar2;
  uint32_t uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar2 = SYNTH_LoDivGet();
  SYNTH_VcoRangeIsValid(param_1);
  uVar5 = read_volatile_4(RAC->.IFPGACTRL);
  if (uVar2 == 1) {
    uVar5 = uVar5 & 0xffffffef;
  }
  else {
    uVar5 = uVar5 | 0x10;
  }
  write_volatile_4(RAC->.IFPGACTRL,uVar5);
  uVar3 = SystemHFXOClockGet();
  uVar6 = uVar2 * param_1;
  currRfFrequency = param_1;
  uVar5 = __aeabi_uldivmod(uVar6 * 0x80000,uVar6 >> 0xd,uVar3,0);
  write_volatile_4(Peripherals::SYNTH.FREQ,uVar5);
  currIfFrequency = SYNTH_IfFreqCompute();
  lVar1 = (ulonglong)(uVar2 << 0x13) * (ulonglong)currIfFrequency;
  uVar4 = __aeabi_uldivmod((int)lVar1,
                           currIfFrequency * (uVar2 >> 0xd) + (int)((ulonglong)lVar1 >> 0x20),uVar3,
                           0);
  uVar5 = read_volatile_4(Peripherals::SYNTH.IFFREQ);
  write_volatile_4(Peripherals::SYNTH.IFFREQ,uVar4 & 0xfffff | uVar5 & 0x100000);
  lVar1 = (ulonglong)(param_2 << 0x13) * (ulonglong)uVar2;
  currChSpacing = param_2;
  uVar5 = __aeabi_uldivmod((int)lVar1,uVar2 * (param_2 >> 0xd) + (int)((ulonglong)lVar1 >> 0x20),
                           uVar3,0);
  write_volatile_4(Peripherals::SYNTH.CHSP,uVar5);
  if (vcoGainPte == 0) {
    uVar5 = read_volatile_4(Peripherals::SYNTH.VCOGAIN);
    vcoGainPte = (byte)uVar5 & 0x3f;
  }
  uVar5 = read_volatile_4(RAC->.SR3);
  if ((int)(uVar5 << 0x1b) < 0) {
    uVar6 = uVar6 / 24000000;
    write_volatile_4(Peripherals::SYNTH.VCOGAIN,
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
      uVar1 = read_volatile_4(RAC->.STATUS);
      uVar1 = (uVar1 << 4) >> 0x1c;
    } while (uVar1 == 4);
  } while (uVar1 == 10);
  write_volatile_4(Peripherals::SYNTH.CHCTRL,param_1);
  if (param_2 != 0) {
    write_volatile_4(RAC->.CMD,0x80);
  }
  SYNTH_RetimeClkConfig();
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void SYNTH_DCDCRetimeEnable(void)

{
  _DAT_43081288 = 1;
  return;
}



void SYNTH_DCDCRetimeClkSet(int param_1)

{
  dcdcRetimeClkTarget = param_1;
  EMU_DCDCLnRcoBandSet((char)((param_1 + 500000U) / 1000000) + ~emuDcdcLnRcoBand_5MHz);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void SYNTH_KvnFreqCompensationEnable(void)

{
  _DAT_43081290 = 1;
  return;
}



void RADIOCMU_ClockEnable(CMU_Clock_TypeDef param_1,undefined4 param_2)

{
  uint uVar1;
  CMU *pCVar2;
  
  uVar1 = (param_1 << 0x14) >> 0x1c;
  if (uVar1 == 1) {
    pCVar2 = &CMU->;
  }
  else {
    if (uVar1 != 4) {
      CMU_ClockEnable(param_1,SUB41(param_2,0));
      return;
    }
    pCVar2 = (CMU *)&CMU->HFRADIOCLKEN0;
  }
  *(undefined4 *)((((param_1 << 0xf) >> 0x1b) + (int)&pCVar2[0x114fb].RFLOCK0 * 8) * 4) = param_2;
  return;
}



uint RADIOCMU_ClockFreqGet(CMU_Clock_TypeDef param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 & 0x3e0000;
  if (uVar2 == 0x40000) {
    uVar1 = SystemHFClockGet();
    uVar2 = read_volatile_4(CMU->HFPERPRESC);
  }
  else {
    if (uVar2 < 0x40001) {
      if (uVar2 == 0) {
        uVar1 = SystemHFClockGet();
        uVar2 = read_volatile_4(CMU->HFPRESC);
LAB_00008b50:
        uVar2 = (uVar2 << 0x13) >> 0x1b;
        goto LAB_00008b54;
      }
      if (uVar2 != 0x20000) {
LAB_00008b5c:
        uVar2 = CMU_ClockFreqGet(param_1);
        return uVar2;
      }
      uVar1 = SystemHFClockGet();
      uVar2 = read_volatile_4(CMU->HFCOREPRESC);
    }
    else {
      if (uVar2 == 0x80000) {
        uVar2 = SystemHFClockGet();
        return uVar2;
      }
      if (uVar2 == 0xa0000) {
        uVar1 = SystemHFClockGet();
        uVar2 = read_volatile_4(CMU->HFEXPPRESC);
        goto LAB_00008b50;
      }
      if (uVar2 != 0x60000) goto LAB_00008b5c;
      uVar1 = SystemHFClockGet();
      uVar2 = read_volatile_4(CMU->HFRADIOPRESC);
    }
  }
  uVar2 = (uVar2 << 0xf) >> 0x17;
LAB_00008b54:
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
  uVar1 = read_volatile_4(CMU->HFRADIOPRESC);
  return (uVar1 << 0xf) >> 0x17;
}



uint8_t RAIL_RadioConfig(void *radioConfig)

{
  RADIO_Config();
  forceIrCal = 1;
  return '\0';
}



uint8_t RAIL_ChannelConfig(RAIL_ChannelConfig_t *config)

{
  int iVar1;
  undefined4 uVar2;
  
  RAILInt_TrackChannelConfig();
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
    RFHAL_CalibrationPend(0x10000);
  }
  return *(uint8_t *)&config->configs->channelNumberStart;
}



void RAIL_DirectModeConfig(bool enable)

{
  undefined1 *puVar1;
  
  if (enable == false) {
    puVar1 = &directModeDisableConfig;
  }
  else {
    puVar1 = &directModeEnableConfig;
  }
  GENERIC_PHY_DirectModeConfig(puVar1);
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
  uint uVar2;
  
  GENERIC_PHY_ResetPacketConfig();
  if (frameType == (RAIL_FrameType_t *)0x0) {
    memset(&Peripherals::SEQ.REG05C,0,0xc);
    return;
  }
  write_volatile_1(Peripherals::SEQ.REG05C._0_1_,frameType->offset);
  write_volatile_1(Peripherals::SEQ.REG05C._1_1_,frameType->mask);
  write_volatile_1(Peripherals::SEQ.REG05C._2_1_,0);
  write_volatile_4(Peripherals::SEQ.REG060,(uint)frameType->frameLen);
  write_volatile_4(Peripherals::SEQ.REG064,(uint)frameType->isValid);
  uVar2 = (uint)frameType->mask;
  if (uVar2 != 0) {
    while (-1 < (int)(uVar2 << 0x1f)) {
      cVar1 = read_volatile_1(Peripherals::SEQ.REG05C._2_1_);
      uVar2 = uVar2 >> 1;
      write_volatile_1(Peripherals::SEQ.REG05C._2_1_,cVar1 + '\x01');
    }
  }
  write_volatile_4(FRC->.WCNTCMP0,frameType->offset + 1);
  uVar2 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar2 | 7);
  return;
}



int16_t RAIL_PollAverageRSSI(uint32_t averageTimeUs)

{
  short sVar1;
  int16_t iVar2;
  undefined4 uVar3;
  uint32_t uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  bool bVar10;
  
  if (averageTimeUs != 0) {
    uVar3 = PROTIMER_GetTime();
    uVar4 = PROTIMER_UsToPrecntOverflow(averageTimeUs);
    iVar7 = 0;
    uVar8 = 0;
    iVar9 = 0;
    while( true ) {
      uVar5 = PROTIMER_GetTime();
      uVar6 = PROTIMER_ElapsedTime(uVar3,uVar5);
      if (uVar4 <= uVar6) break;
      sVar1 = RADIO_GetRSSI();
      uVar6 = SEXT24(sVar1);
      bVar10 = CARRY4(uVar8,uVar6);
      uVar8 = uVar8 + uVar6;
      iVar9 = iVar9 + ((int)uVar6 >> 0x1f) + (uint)bVar10;
      iVar7 = iVar7 + 1;
    }
    if (iVar7 != 0) {
      iVar2 = __aeabi_ldivmod(uVar8,iVar9,iVar7,iVar7 >> 0x1f);
      return iVar2;
    }
  }
  iVar2 = RADIO_GetRSSI();
  return iVar2;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

RAIL_Status_t RAIL_StartAverageRSSI(uint8_t channel,uint32_t averagingTimeUs)

{
  uint uVar1;
  uint8_t uVar2;
  int iVar3;
  
  saveRssiPeriod = read_volatile_4(AGC->.CTRL1);
  iVar3 = RADIO_CalcRssiPeriod(averagingTimeUs);
  if (iVar3 == 0) {
    frc_modem_ctrl0 = read_volatile_4(MODEM->.CTRL0);
    uVar1 = read_volatile_4(MODEM->.CTRL0);
    write_volatile_4(MODEM->.CTRL0,uVar1 | 0x200000);
    uVar2 = RAIL_RxStart(channel);
    if (uVar2 == '\0') {
      _enabledCallbacks = _enabledCallbacks | 0x2000000;
      GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
    }
    else {
      iVar3 = 2;
    }
  }
  else {
    iVar3 = 1;
  }
  return (RAIL_Status_t)iVar3;
}



int RAIL_GetAverageRSSI(void)

{
  return (int)currentRssiAverage;
}



void RAIL_SetTune(uint32_t tune)

{
  uint uVar1;
  
  CMU_ClockSelectSet(cmuClock_HF,cmuSelect_HFRCO);
  CMU_OscillatorEnable(cmuOsc_HFXO,false,false);
  uVar1 = read_volatile_4(CMU->HFXOSTEADYSTATECTRL);
  write_volatile_4(CMU->HFXOSTEADYSTATECTRL,uVar1 & 0xfff007ff);
  uVar1 = read_volatile_4(CMU->HFXOSTEADYSTATECTRL);
  write_volatile_4(CMU->HFXOSTEADYSTATECTRL,(tune & 0x1ff) << 0xb | uVar1);
  CMU_OscillatorEnable(cmuOsc_HFXO,true,true);
  CMU_ClockSelectSet(cmuClock_HF,cmuSelect_HFXO);
  return;
}



uint32_t RAIL_GetTune(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(CMU->HFXOSTEADYSTATECTRL);
  return (uVar1 << 0xc) >> 0x17;
}



uint32_t RAIL_GetTime(void)

{
  uint32_t uVar1;
  
  uVar1 = PROTIMER_GetTime();
  uVar1 = PROTIMER_PrecntOverflowToUs(uVar1);
  return uVar1;
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



RAIL_Status_t RAIL_SetStateTiming(RAIL_StateTiming_t *timings)

{
  uint16_t uVar1;
  
  uVar1 = RADIO_RxWarmTimeSet(timings->idleToRx);
  timings->idleToRx = uVar1;
  uVar1 = RADIO_TxToRxTimeSet(timings->txToRx);
  timings->txToRx = uVar1;
  uVar1 = RADIO_TxWarmTimeSet(timings->idleToTx);
  timings->idleToTx = uVar1;
  uVar1 = RADIO_RxFrameToTxTimeSet(timings->rxToTx);
  timings->rxToTx = uVar1;
  return RAIL_STATUS_NO_ERROR;
}



// WARNING: Could not reconcile some variable overlaps

bool RAIL_AddressFilterConfig(RAIL_AddrConfig_t *addrConfig)

{
  byte bVar1;
  undefined uVar2;
  undefined4 in_r3;
  int iVar3;
  uint8_t local_1c [4];
  uint32_t local_18;
  undefined4 local_14;
  
  bVar1 = addrConfig->numFields;
  if (bVar1 < 3) {
    local_14 = in_r3;
    memset(local_1c,0,0xc);
    for (iVar3 = 0; iVar3 < (int)(uint)bVar1; iVar3 = iVar3 + 1) {
      local_1c[iVar3] = addrConfig->offsets[iVar3];
      local_1c[iVar3 + 2] = addrConfig->sizes[iVar3];
    }
    local_18 = addrConfig->matchTable;
    local_14 = CONCAT31(local_14._1_3_,0xff);
    uVar2 = GENERIC_PHY_ConfigureAddressFiltering(local_1c);
  }
  else {
    uVar2 = 0;
  }
  return (bool)uVar2;
}



bool RAIL_AddressFilterByFrameType(uint8_t validFrames)

{
  write_volatile_1(Peripherals::SEQ.REG058._2_1_,validFrames);
  return true;
}



bool RAIL_AddressFilterEnable(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 | 0x10);
  return SUB41((uVar1 << 0x1b) >> 0x1f,0);
}



bool RAIL_AddressFilterDisable(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 & 0xffffffef);
  return SUB41((uVar1 << 0x1b) >> 0x1f,0);
}



bool RAIL_AddressFilterIsEnabled(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  return SUB41((uVar1 << 0x1b) >> 0x1f,0);
}



void RAIL_AddressFilterReset(void)

{
  memset(&Peripherals::SEQ.REG010,0,0x4c);
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
                    (uVar2,uVar2,index,0,*(undefined *)((int)&Peripherals::SEQ.REG054 + uVar2 + 2),
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
    *(byte *)((int)&Peripherals::SEQ.REG058 + uVar1) =
         (byte)(1 << (uint)index) | *(byte *)((int)&Peripherals::SEQ.REG058 + uVar1);
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
    *(byte *)((int)&Peripherals::SEQ.REG058 + uVar1) =
         *(byte *)((int)&Peripherals::SEQ.REG058 + uVar1) & ~(byte)(1 << (uint)index);
    GENERIC_PHY_SetAddressFilteringMatchTable();
    return true;
  }
  return false;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

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
  uVar4 = read_volatile_4(CMU->HFRADIOCLKEN0);
  uStack36 = __n;
  memset(buffer,0,__n);
  if ((((uVar4 | 0xcc) == uVar4) &&
      (uVar4 = read_volatile_4(RAC->.CTRL), -1 < (int)(uVar4 << 0x1f))) &&
     (uVar4 = RADIOCMU_ClockPrescGet(0x75160), uVar4 == 0)) {
    irqState = CORE_EnterCritical();
    uVar3 = read_volatile_4(MODEM->.CTRL0);
    uVar2 = read_volatile_4(FRC->.RAWCTRL);
    uVar1 = read_volatile_4(MODEM->.CTRL0);
    write_volatile_4(MODEM->.CTRL0,uVar1 & 0xc7ffffff);
    uVar1 = read_volatile_4(MODEM->.CTRL0);
    write_volatile_4(MODEM->.CTRL0,uVar1 | 0x8000000);
    write_volatile_4(FRC->.RAWCTRL,0x24);
    _DAT_43080008 = 1;
    write_volatile_4(FRC->.IFC,0x4000);
    write_volatile_4(FRC->.CMD,0x1000);
    for (; uVar4 < __n; uVar4 = uVar4 + __n_00 & 0xffff) {
      do {
        do {
          uVar1 = read_volatile_4(FRC->.IF);
        } while (-1 < (int)(uVar1 << 0x11));
        uVar1 = read_volatile_4(FRC->.STATUS);
      } while (-1 < (int)(uVar1 << 0x17));
      __n_00 = __n - uVar4;
      write_volatile_4(FRC->.IFC,0x4000);
      if (3 < (int)__n_00) {
        __n_00 = 4;
      }
      uStack36 = read_volatile_4(FRC->.RXRAWDATA);
      memcpy(buffer + uVar4,&uStack36,__n_00);
    }
    _DAT_43080008 = 0;
    write_volatile_4(FRC->.RAWCTRL,uVar2);
    write_volatile_4(MODEM->.CTRL0,uVar3);
    write_volatile_4(FRC->.IFC,0x4000);
    CORE_ExitCritical(irqState);
  }
  else {
    bytes = 0;
  }
  return bytes;
}



void pktTxDoneEvt(undefined4 param_1,RAIL_TxPacketInfo_t param_2,undefined4 param_3)

{
  uint32_t cnt;
  RAIL_TxPacketInfo_t local_c;
  undefined4 uStack8;
  
  local_c = (uint32_t)param_2;
  uStack8 = param_3;
  cnt = GENERIC_PHY_PreviousTxTime();
  local_c = PROTIMER_PrecntOverflowToUs(cnt);
  RAILCb_TxPacketSent(&local_c);
  return;
}



void pktRxOverflow(void)

{
  RAILCb_RxRadioStatusExt(0x20);
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



void racStateChange(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(RAC->.STATUS);
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



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void rssiAverageDone(void)

{
  _enabledCallbacks = _enabledCallbacks & 0xfdffffff;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  currentRssiAverage = RADIO_GetRSSI();
  RAIL_RfIdle();
  write_volatile_4(MODEM->.CTRL0,frc_modem_ctrl0);
  RAILCb_RssiAverageDone(currentRssiAverage);
  write_volatile_4(AGC->.CTRL1,saveRssiPeriod);
  return;
}



void racCalRequest(void)

{
  RFHAL_CalibrationPend(1);
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
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined2 local_1a;
  
  if (param_1 << 0xb < 0) {
    RAILCb_RxAckTimeout();
  }
  if ((param_1 << 0xc < 0) && (iVar3 = GENERIC_PHY_CanModifyAck(), iVar3 != 0)) {
    uVar2 = read_volatile_4(Peripherals::BUFC.BUF1_ADDR);
    uVar1 = read_volatile_4(Peripherals::BUFC.BUF1_CTRL);
    uVar6 = read_volatile_4(RAC->.SR1);
    uVar6 = (uVar6 << 0x18) >> 0x1e;
    uVar7 = (0x40 << (uVar1 & 0xff)) - 1U & 0xffff;
    uVar1 = read_volatile_4(Peripherals::SEQ.REG004);
    iVar3 = uVar2 + 0x20000000;
    if (uVar6 == 3) {
      iVar4 = 0;
      do {
        iVar5 = iVar4 + 1;
        *(undefined *)((int)&local_1a + iVar4) =
             *(undefined *)(iVar3 + (((uVar1 & 0xffff) - 8) + iVar4 & uVar7));
        iVar4 = iVar5;
      } while (iVar5 != 8);
    }
    else {
      if (uVar6 != 2) {
        return;
      }
      local_1a = CONCAT11(*(undefined *)(iVar3 + ((uVar1 & 0xffff) - 1 & uVar7)),
                          *(undefined *)(iVar3 + ((uVar1 & 0xffff) - 2 & uVar7)));
    }
    RAILCb_IEEE802154_DataRequestCommand();
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void pktRxDoneEvt(void)

{
  byte bVar1;
  int iVar2;
  void *handle;
  void *pvVar3;
  uint32_t uVar4;
  uint32_t *puVar5;
  uint32_t uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  void *local_3c;
  ushort local_38;
  byte local_36;
  undefined local_35;
  undefined auStack52 [5];
  undefined local_2f;
  byte local_2e;
  uint32_t local_28;
  
  iVar2 = RADIO_RxTrailDataLength();
  RADIO_RxLengthReadNext(&local_38);
  if (local_38 != 0xffff) {
    uVar9 = (uint)local_38 - iVar2 & 0xffff;
    handle = RAILCb_AllocateMemory(uVar9 + 0xc);
    uVar7 = 0;
    while (uVar7 < uVar9) {
      local_3c = (void *)(uVar9 - uVar7);
      pvVar3 = RAILCb_BeginWriteMemory(handle,uVar7 + 10,(uint32_t *)&local_3c);
      if (local_3c == (void *)0x0) {
        pvVar3 = local_3c;
        local_3c = (void *)(uVar9 - uVar7);
      }
      uVar4 = GENERIC_PHY_PacketRxDataHelper(pvVar3,(uint)local_3c & 0xffff);
      uVar8 = uVar7 + uVar4;
      if (pvVar3 == (void *)0x0) {
        uVar4 = 0;
      }
      RAILCb_EndWriteMemory(handle,uVar7 + 10,uVar4);
      uVar7 = uVar8 & 0xffff;
    }
    GENERIC_PHY_PacketRxAppendedInfoHelper(iVar2,auStack52);
    local_3c = (void *)0xc;
    puVar5 = (uint32_t *)RAILCb_BeginWriteMemory(handle,0,(uint32_t *)&local_3c);
    if ((puVar5 == (uint32_t *)0x0) || (local_3c < (void *)0xc)) {
      uVar4 = 0;
    }
    else {
      *(short *)(puVar5 + 2) = (short)uVar9;
      read_volatile(FRC->.IEN._0_1_);
      uVar7 = read_volatile_4(FRC->.IF);
      *(byte *)(puVar5 + 1) =
           *(byte *)(puVar5 + 1) & 0xfd | (byte)((((uVar7 ^ 0x80) << 0x18) >> 0x1f) << 1);
      _DAT_43000d1c = 1;
      bVar1 = *(byte *)(puVar5 + 1);
      if (local_2e != 0) {
        local_2e = 1;
      }
      *(byte *)(puVar5 + 1) = bVar1 & 0xfe | local_2e & 1;
      *(undefined *)((int)puVar5 + 5) = local_2f;
      *(undefined *)((int)puVar5 + 6) = local_35;
      *(byte *)(puVar5 + 1) =
           bVar1 & 0xfa | local_2e & 1 | (byte)((((uint)local_36 << 0x1c) >> 0x1f) << 2);
      uVar6 = PROTIMER_PrecntOverflowToUs(local_28);
      *puVar5 = uVar6;
      *(undefined *)((int)puVar5 + 7) = 0;
      uVar4 = 0xc;
    }
    RAILCb_EndWriteMemory(handle,0,uVar4);
    RAILCb_RxPacketReceived(handle);
    RAILCb_FreeMemory(handle);
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void pktRxFrmErr(void)

{
  _DAT_43000d1c = 1;
  RAILCb_RxRadioStatusExt(0x10);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void pktRxAborted(void)

{
  uint uVar1;
  uint32_t status;
  
  uVar1 = read_volatile_4(RAC->.SR0);
  _DAT_43081160 = 0;
  if ((int)(uVar1 << 7) < 0) {
    status = 0x40;
  }
  else {
    status = 0x400;
  }
  RAILCb_RxRadioStatusExt(status);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void pktTxErrorEvt(uint param_1)

{
  if ((param_1 & 0x1c) != 0) {
    _DAT_4308111c = 0;
  }
  if ((param_1 & txConfigEvents) == 0) {
    return;
  }
  RAILCb_TxRadioStatus((uint8_t)(param_1 & txConfigEvents));
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void protmrLbtEvt(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  PROTIMER_CCTimerStop(4);
  if (param_1 << 9 < 0) {
    RADIO_PTI_AuxdataOutput(0x27);
    GENERIC_PHY_FlushTxPacketBuffer();
    uVar1 = read_volatile_4(Peripherals::SEQ.REG00C);
    if ((uVar1 & 0xff000000) == 0x2000000) {
      _DAT_43080004 = 1;
    }
LAB_0000907c:
    uVar2 = 4;
  }
  else {
    if (-1 < param_1 << 0xb) {
      if (-1 < param_1 << 0x13) goto LAB_00009082;
      PROTIMER_LBTStop();
      uVar1 = read_volatile_4(PROTIMER->.IF);
      if ((uVar1 & 0x500000) != 0) goto LAB_00009082;
      RADIO_PTI_AuxdataOutput(0x2a);
      GENERIC_PHY_FlushTxPacketBuffer();
      goto LAB_0000907c;
    }
    RADIO_PTI_AuxdataOutput(0x28);
    uVar2 = 0x20;
  }
  pktTxErrorEvt(uVar2);
LAB_00009082:
  write_volatile_4(AGC->.CTRL1,saveRssiPeriodPreCca);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint8_t RFHAL_Init(RAIL_Init_t *railInit)

{
  uint32_t uVar1;
  int iVar2;
  
  uVar1 = SystemHFXOClockGet();
  if (uVar1 == railInit->rfXtalFreq) {
    GENERIC_PHY_Init();
    _enabledCallbacks =
         _enabledCallbacks & 0xff000000 | (uint)(uint3)((uint3)_enabledCallbacks | 7) | 0x200000;
    iVar2 = RFHAL_CalibrationEnableGet();
    if (iVar2 << 0x1f < 0) {
      _enabledCallbacks = _enabledCallbacks | 0x40000;
    }
    _enabledCallbacks = _enabledCallbacks | 0x80000;
    GENERIC_PHY_SetCallbacks(&callbacks);
    GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
    RAILCb_RfReady();
    return '\0';
  }
  return '\x01';
}



uint RFHAL_SetPtiProtocol(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int unaff_r4;
  
  uVar2 = param_1 & 0xfffffff0;
  if (uVar2 == 0) {
    unaff_r4 = 0x21000f68;
    uVar1 = read_volatile_4(Peripherals::SEQ.REG070);
    param_4 = uVar1 & 0xfffffff0 | param_1 & 0xf;
    param_1 = uVar2;
  }
  if (uVar2 == 0) {
    *(uint *)(unaff_r4 + 8) = param_4;
  }
  else {
    param_1 = 1;
  }
  return param_1;
}



void RFHAL_IdleExt(int param_1)

{
  int iVar1;
  
  if (param_1 == 1) {
    iVar1 = 0;
  }
  else {
    if (param_1 == 0) {
      param_1 = 0;
      iVar1 = param_1;
    }
    else {
      if (param_1 != 2) {
        return;
      }
      param_1 = 1;
      iVar1 = param_1;
    }
  }
  GENERIC_PHY_RadioIdle(param_1,iVar1);
  return;
}



RAIL_RadioState_t RFHAL_StateGet(void)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = read_volatile_4(RAC->.STATUS);
  uVar1 = uVar1 & 0xf000000;
  if (uVar1 != 0x6000000) {
    if (0x6000000 < uVar1) {
      if (uVar1 != 0x9000000) {
        if (uVar1 < 0x9000001) {
          if (uVar1 == 0x7000000) {
            return RAIL_RF_STATE_RX;
          }
          bVar2 = uVar1 == 0x8000000;
        }
        else {
          if (uVar1 == 0xb000000) {
            return RAIL_RF_STATE_TX;
          }
          if (uVar1 == 0xc000000) {
            return RAIL_RF_STATE_TX;
          }
          bVar2 = uVar1 == 0xa000000;
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



uint RFHAL_OkToTransmit(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(RAC->.SR0);
  return ((uVar1 ^ 0x80) << 0x18) >> 0x1f;
}



bool RFHAL_HeadedToIdle(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  irqState = CORE_EnterCritical();
  iVar2 = PROTIMER_CCTimerIsEnabled(3);
  if ((iVar2 == 0) && (iVar2 = PROTIMER_LBTIsActive(), iVar2 == 0)) {
    uVar3 = read_volatile_4(RAC->.STATUS);
    uVar1 = read_volatile_4(RAC->.SR0);
    CORE_ExitCritical(irqState);
    if (((uVar3 & 0xc0000000) == 0) &&
       ((-1 < (int)(uVar1 << 0x18) && (uVar3 = uVar3 & 0xf000000, uVar3 != 0x6000000)))) {
      if (uVar3 < 0x6000001) {
        bVar4 = uVar3 == 0x3000000;
      }
      else {
        if (uVar3 == 0x9000000) goto LAB_00009218;
        bVar4 = uVar3 == 0xc000000;
      }
      if (!bVar4) {
        iVar2 = 1;
      }
    }
  }
  else {
    CORE_ExitCritical(irqState);
    iVar2 = 0;
  }
LAB_00009218:
  return SUB41(iVar2,0);
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint RFHAL_TxDataLoad(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  CORE_irqState_t irqState;
  uint uVar1;
  
  irqState = CORE_EnterCritical();
  _DAT_43081100 = 1;
  uVar1 = read_volatile_4(RAC->.SR0);
  uVar1 = uVar1 & 0x10000;
  if (uVar1 == 0) {
    RADIO_TxBufferSet(*param_1,*(undefined2 *)(param_1 + 1),0,0,param_4);
  }
  else {
    uVar1 = 3;
  }
  _DAT_43081100 = 0;
  CORE_ExitCritical(irqState);
  return uVar1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint8_t RAIL_CcaCsma(void *params)

{
  byte bVar1;
  RAIL_RadioState_t RVar2;
  uint8_t uVar3;
  uint32_t uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  byte bVar10;
  byte bVar11;
  uint uVar12;
  byte bVar13;
  byte bVar14;
  
  if (params == (void *)0x0) {
    PROTIMER_LBTUseLastConfig();
LAB_0000937e:
    GENERIC_PHY_PacketTxCommon();
    uVar4 = lbtTimeout_8797;
    if (lbtTimeout_8797 != 0) {
      iVar5 = PROTIMER_CCTimerIsEnabled(4);
      if (iVar5 != 0) {
        PROTIMER_CCTimerStop(4);
      }
      uVar4 = PROTIMER_UsToPrecntOverflow(uVar4);
      iVar5 = PROTIMER_CCTimerStart(4,uVar4,1);
      if (iVar5 == 0) goto LAB_000092dc;
    }
    PROTIMER_LBTStart();
    uVar3 = '\0';
  }
  else {
    saveRssiPeriodPreCca = read_volatile_4(AGC->.CTRL1);
    RADIO_SetAgcCcaParams
              (*(undefined2 *)((int)params + 6),(int)*(char *)((int)params + 3),saveRssiPeriodPreCca
               ,&saveRssiPeriodPreCca,params);
    bVar13 = *(byte *)((int)params + 2);
                    // WARNING: Load size is inaccurate
    bVar1 = *params;
    bVar10 = *(byte *)((int)params + 1);
    bVar14 = bVar13;
    bVar11 = bVar13;
    if (bVar13 != 0) {
      bVar11 = bVar13 - 1;
      bVar14 = bVar1;
      if (bVar10 < bVar1) {
        bVar13 = 1;
        bVar10 = bVar1;
      }
      else {
        bVar13 = 1;
      }
    }
                    // WARNING: Load size is inaccurate
    uVar12 = count_leading_zeroes((uint)*params);
    uVar4 = PROTIMER_UsToPrecntOverflow((uint)*(ushort *)((int)params + 4));
    uVar8 = uVar4 & 0xffff;
    uVar4 = RADIO_RxWarmTimeGet();
    uVar4 = PROTIMER_UsToPrecntOverflow(uVar4);
    if ((uVar4 < uVar8) || (RVar2 = RAIL_RfStateGet(), RVar2 == RAIL_RF_STATE_RX)) {
      if (uVar12 >> 5 == 0) {
        if (reseedRandom_8798 != 0xf804) {
          write_volatile_4(PROTIMER->.RANDOM,(uint)reseedRandom_8798);
          reseedRandom_8798 = 0xf804;
        }
        if (uVar8 < 0x100) goto LAB_00009344;
        write_volatile_4(PROTIMER->.BASECNTTOP,0xff);
        PROTIMER_LBTCfgSet(bVar14,bVar10,bVar13,bVar11,0);
      }
      else {
        uVar7 = 0;
        uVar9 = uVar8;
        while( true ) {
          uVar6 = uVar7 & 0xff;
          uVar7 = uVar7 + 1;
          if (uVar9 < 0x100) break;
          uVar9 = uVar9 >> 1;
        }
        if ((uVar6 != 0) && (uVar9 != 0xff)) {
          uVar9 = uVar9 + ((int)uVar8 >> (uVar6 - 1 & 0xff) & 1U) & 0xffff;
        }
        uVar8 = read_volatile_4(PROTIMER->.RANDOM);
        reseedRandom_8798 = (ushort)(uVar8 & 0xffff);
        if ((uVar8 & 0xffff) == 0xf804) {
          reseedRandom_8798 = 0xf805;
        }
        write_volatile_4(PROTIMER->.RANDOM,(1 << uVar6) - 1);
        bVar10 = 8;
        write_volatile_4(PROTIMER->.LBTSTATE,0x800000);
        bVar14 = 8;
        uVar8 = uVar9;
LAB_00009344:
        write_volatile_4(PROTIMER->.BASECNTTOP,uVar8 - 1);
        PROTIMER_LBTCfgSet(bVar14,bVar10,bVar13,bVar11,0);
        if (uVar12 >> 5 != 0) {
          _DAT_430a09d0 = 1;
          uVar8 = read_volatile_4(PROTIMER->.CTRL);
          write_volatile_4(PROTIMER->.CTRL,uVar8 & 0xff3fffff | 0x400000);
        }
      }
      lbtTimeout_8797 = *(uint32_t *)((int)params + 8);
      goto LAB_0000937e;
    }
LAB_000092dc:
    uVar3 = '\x01';
  }
  return uVar3;
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
  short sVar1;
  int16_t iVar2;
  undefined4 uVar3;
  uint32_t uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  bool bVar10;
  
  if (averageTimeUs != 0) {
    uVar3 = PROTIMER_GetTime();
    uVar4 = PROTIMER_UsToPrecntOverflow(averageTimeUs);
    iVar7 = 0;
    uVar8 = 0;
    iVar9 = 0;
    while( true ) {
      uVar5 = PROTIMER_GetTime();
      uVar6 = PROTIMER_ElapsedTime(uVar3,uVar5);
      if (uVar4 <= uVar6) break;
      sVar1 = RADIO_GetRSSI();
      uVar6 = SEXT24(sVar1);
      bVar10 = CARRY4(uVar8,uVar6);
      uVar8 = uVar8 + uVar6;
      iVar9 = iVar9 + ((int)uVar6 >> 0x1f) + (uint)bVar10;
      iVar7 = iVar7 + 1;
    }
    if (iVar7 != 0) {
      iVar2 = __aeabi_ldivmod(uVar8,iVar9,iVar7,iVar7 >> 0x1f);
      return iVar2;
    }
  }
  iVar2 = RADIO_GetRSSI();
  return iVar2;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

RAIL_Status_t RFHAL_StartAverageRSSI(uint8_t channel,uint32_t averagingTimeUs)

{
  uint uVar1;
  uint8_t uVar2;
  int iVar3;
  
  saveRssiPeriod = read_volatile_4(AGC->.CTRL1);
  iVar3 = RADIO_CalcRssiPeriod(averagingTimeUs);
  if (iVar3 == 0) {
    frc_modem_ctrl0 = read_volatile_4(MODEM->.CTRL0);
    uVar1 = read_volatile_4(MODEM->.CTRL0);
    write_volatile_4(MODEM->.CTRL0,uVar1 | 0x200000);
    uVar2 = RAIL_RxStart(channel);
    if (uVar2 == '\0') {
      _enabledCallbacks = _enabledCallbacks | 0x2000000;
      GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
    }
    else {
      iVar3 = 2;
    }
  }
  else {
    iVar3 = 1;
  }
  return (RAIL_Status_t)iVar3;
}



int RFHAL_GetAverageRSSI(void)

{
  return (int)currentRssiAverage;
}



uint8_t RFHAL_ScheduleRx(uint8_t channel,RAIL_ScheduleRxConfig_t *cfg)

{
  uint8_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint8_t uVar4;
  uint uVar5;
  RAIL_TimeMode_t RVar6;
  RAIL_TimeMode_t RVar7;
  
  RVar7 = cfg->startMode;
  if (RVar7 == RAIL_TIME_DISABLED) {
    uVar2 = 0;
  }
  else {
    uVar2 = PROTIMER_UsToPrecntOverflow(cfg->start);
    RVar7 = cfg->startMode;
    if (RVar7 != RAIL_TIME_ABSOLUTE) {
      RVar7 = RAIL_TIME_DELAY;
    }
  }
  RVar6 = cfg->endMode;
  if (RVar6 == RAIL_TIME_DISABLED) {
    uVar3 = 0;
  }
  else {
    uVar3 = PROTIMER_UsToPrecntOverflow(cfg->end);
    RVar6 = cfg->endMode;
    if (RVar6 != RAIL_TIME_ABSOLUTE) {
      RVar6 = RAIL_TIME_DELAY;
    }
  }
  uVar5 = count_leading_zeroes((uint)cfg->rxTransitionEndSchedule);
  uVar4 = cfg->hardWindowEnd;
  if (uVar4 != '\0') {
    uVar4 = '\x01';
  }
  uVar1 = GENERIC_PHY_SchedulePacketRx(uVar2,RVar7,uVar3,RVar6,uVar5 >> 5,uVar4);
  return uVar1;
}



RAIL_Status_t RAIL_ScheduleTx(RAIL_ScheduleTxConfig_t *params)

{
  RAIL_Status_t RVar1;
  uint32_t when;
  RAIL_TimeMode_t mode;
  RAIL_TimeMode_t mode_00;
  
  mode_00 = params->mode;
  if (mode_00 != RAIL_TIME_ABSOLUTE) {
    mode_00 = RAIL_TIME_DELAY;
  }
  when = PROTIMER_UsToPrecntOverflow(params->when);
  RVar1 = GENERIC_PHY_SchedulePacketTx(when,mode_00);
  return RVar1;
}



uint8_t RFHAL_RxStart(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(RAC->.RXENSRCEN);
  if ((uVar1 & 0xff) == 0) {
    RADIO_RxBufferReset();
  }
  GENERIC_PHY_StartRx(0);
  return '\0';
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint8_t RFHAL_RxIntEnable(uint32_t cbToEnable,bool appendedInfoEnable)

{
  _enabledCallbacks =
       CONCAT11(DAT_20002f75 & 0xe3 | (byte)(((cbToEnable << 0x1e) >> 0x1f) << 2) |
                (byte)(((cbToEnable << 0x1d) >> 0x1f) << 3) |
                (byte)(((cbToEnable << 0x1c) >> 0x1f) << 4),enabledCallbacks);
  _enabledCallbacks =
       _enabledCallbacks & 0xffff0000 | _enabledCallbacks & 0xffffff00 |
       (uint)(byte)(enabledCallbacks & 0x87 | (byte)(((cbToEnable << 0x1b) >> 0x1f) << 3) |
                    (byte)(((cbToEnable << 0x1a) >> 0x1f) << 4) |
                    (byte)(((cbToEnable << 0x15) >> 0x1f) << 5) | ((cbToEnable & 0x300) != 0) << 6);
  rxConfigEvents = cbToEnable;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  return '\0';
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 RFHAL_TxIntEnable(uint param_1)

{
  _enabledCallbacks =
       CONCAT12(DAT_20002f76 & 0x3f | 0x20 | (byte)(((param_1 << 0x19) >> 0x1f) << 6) |
                (byte)(((param_1 << 0x18) >> 0x1f) << 7),_enabledCallbacks);
  _enabledCallbacks =
       _enabledCallbacks & 0xff000000 | _enabledCallbacks & 0xffffff00 |
       (uint)(byte)(enabledCallbacks & 0xfd | ((param_1 & 0x1a) != 0) << 1);
  txConfigEvents = param_1;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  return 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 RFHAL_ErrorConfig(uint param_1)

{
  _DAT_43000884 = param_1 & 1;
  return 0;
}



RAIL_Status_t RAIL_PaCtuneSet(uint8_t txPaCtuneValue,uint8_t rxPaCtuneValue)

{
  PA_CTuneSet(txPaCtuneValue,rxPaCtuneValue);
  return RAIL_STATUS_NO_ERROR;
}



void RAIL_TimerGet(void)

{
  uint32_t cnt;
  
  cnt = GENERIC_PHY_TimerGetTimeout();
  PROTIMER_PrecntOverflowToUs(cnt);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RAIL_TimerCancel(void)

{
  undefined4 extraout_r1;
  undefined4 in_r3;
  
  GENERIC_PHY_TimerStop();
  _enabledCallbacks = _enabledCallbacks & 0xfeffffff;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks,extraout_r1,DAT_20002f77 & 0xfe,in_r3);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

byte RAIL_TimerSet(uint32_t param_1,int param_2)

{
  byte bVar1;
  CORE_irqState_t irqState;
  uint32_t uVar2;
  int iVar3;
  
  iVar3 = param_2;
  if (param_2 != 0) {
    iVar3 = 1;
  }
  if (param_2 == 2) {
    RAIL_TimerCancel();
    return 0;
  }
  irqState = CORE_EnterCritical();
  _enabledCallbacks = _enabledCallbacks | 0x1000000;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  timerExpired = 0;
  uVar2 = PROTIMER_UsToPrecntOverflow(param_1);
  bVar1 = GENERIC_PHY_TimerStart(uVar2,iVar3);
  CORE_ExitCritical(irqState);
  return bVar1 ^ 1;
}



byte RAIL_TimerExpired(void)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = GENERIC_PHY_TimerExpired();
  bVar1 = timerExpired;
  if (iVar2 != 0) {
    bVar1 = 1;
  }
  return bVar1 & 1;
}



void RAIL_TimerIsRunning(void)

{
  PROTIMER_CCTimerIsEnabled(2);
  return;
}



uint32_t RAIL_SymbolRateGet(void)

{
  uint uVar1;
  uint32_t uVar2;
  
  uVar2 = RADIO_ComputeTxBaudrate();
  uVar1 = read_volatile_4(MODEM->.CTRL0);
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
  
  uVar1 = read_volatile_4(MODEM->.CTRL0);
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
    uVar1 = read_volatile_4(MODEM->.CTRL0);
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
  
  local_14 = 0x8d61;
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

bool RAIL_RfSensed(void)

{
  code *pcVar1;
  int iVar2;
  CORE_irqState_t irqState;
  uint uVar3;
  
  iVar2 = _DAT_43c81904;
  _DAT_43c81904 = 1;
  uVar3 = read_volatile_4(Peripherals::RFSENSE.IF);
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
    _DAT_43c81904 = iVar2;
  }
  return SUB41(uVar3,0);
}



void RFHAL_CalibrationRun(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_2 << 0x1f < 0) {
    TEMPCAL_Perform();
  }
  if (param_2 << 0xf < 0) {
    if (*param_1 == -1) {
      iVar1 = IRCAL_Perform();
      *param_1 = iVar1;
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
  
  uVar1 = read_volatile_2(Peripherals::SEQ.REG00C._0_2_);
  write_volatile_4(Peripherals::SEQ.REG00C,
                   1 << (success + 0x10 & 0xff) | (uint)uVar1 | 1 << (error + 0x18 & 0xff));
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RFHAL_SetRxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error)

{
  ushort uVar1;
  
  uVar1 = read_volatile_2(Peripherals::SEQ.REG00C._2_2_);
  write_volatile_4(Peripherals::SEQ.REG00C,
                   1 << (error + 8 & 0xff) | 1 << success | (uint)uVar1 << 0x10);
  return RAIL_STATUS_NO_ERROR;
}



void RFHAL_SetBerConfig(RAIL_BerConfig_t *berconfig)

{
  RFTEST_ResetBerStats(berconfig->bytesToTest);
  return;
}



void RFHAL_StartBerRx(void)

{
  uint uVar1;
  
  RFTEST_SaveRadioConfiguration();
  write_volatile_4(FRC->.SNIFFCTRL,0);
  write_volatile_4(FRC->.DFLCTRL,5);
  uVar1 = read_volatile_4(MODEM->.TIMING);
  write_volatile_4(MODEM->.TIMING,uVar1 & 0xfffff0ff);
  RADIO_RXBufferEnableThrInt();
  RFTEST_StartRx();
  return;
}



void RFHAL_StopBerRx(void)

{
  RFTEST_BerStop();
  RADIO_RXBufferDisableThrInt();
  RFTEST_RestoreRadioConfiguration();
  return;
}



void RFHAL_GetBerStatus(RAIL_BerStatus_t *berstatus)

{
  uint32_t in_r1;
  uint32_t in_r2;
  int8_t in_r3;
  RAIL_BerStatus_t local_18;
  
  local_18.bitsTotal = (uint32_t)berstatus;
  local_18.bitsTested = in_r1;
  local_18.bitErrors = in_r2;
  local_18.rssi = in_r3;
  RFTEST_ReportBerStats(&local_18);
  berstatus->bitsTotal = local_18.bitsTotal;
  berstatus->bitsTested = local_18.bitsTested;
  berstatus->bitErrors = local_18.bitErrors;
  berstatus->rssi = local_18.rssi;
  return;
}



void RFHAL_SetCRCInitVal(uint param_1)

{
  write_volatile_4(CRC->.INIT,param_1);
  write_volatile_4(CRC->.CMD,1);
  return;
}



int RFHAL_GetCurrPowerLevel(void)

{
  return (int)gPaConfig.power;
}



undefined4 RFHAL_SetCurrPowerLevel(void)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = PA_OutputPowerSet();
  pcVar1 = protChChngCB;
  if (protChChngCB != FUN_00000000) {
    uVar3 = RAILInt_GetChannel();
    (*pcVar1)(uVar3,1);
  }
  return uVar2;
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



undefined4 RFHAL_SetChannel(int param_1,byte *param_2,int param_3)

{
  uint uVar1;
  bool bVar2;
  uint32_t uVar3;
  
  uVar3 = RAIL_DebugModeGet();
  if (uVar3 != 1) {
    do {
      bVar2 = RFHAL_HeadedToIdle();
      if (bVar2 == false) break;
      uVar1 = read_volatile_4(RAC->.STATUS);
    } while ((uVar1 & 0xf000000) != 0);
    uVar1 = read_volatile_4(RAC->.STATUS);
    if ((uVar1 & 0xf000000) != 0) {
      return 2;
    }
    if (protChChngCB != FUN_00000000) {
      (*protChChngCB)(param_1);
    }
    if (param_3 != 0) {
      SYNTH_Config(*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 4));
    }
    GENERIC_PHY_ChannelSet(param_1 - (uint)*param_2 & 0xff);
  }
  return 0;
}



uint RFHAL_AutoAckEnable(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 | 0x20);
  return (uVar1 << 0x1a) >> 0x1f;
}



uint RFHAL_AutoAckDisable(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 & 0xffffffdf);
  return (uVar1 << 0x1a) >> 0x1f;
}



bool RFHAL_AutoAckIsEnabled(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  return SUB41((uVar1 << 0x1a) >> 0x1f,0);
}



undefined4 RFHAL_AutoAckConfig(int param_1)

{
  uint32_t uVar1;
  
  uVar1 = PROTIMER_UsToPrecntOverflow((uint)*(ushort *)(param_1 + 6));
  write_volatile_4(Peripherals::SEQ.REG008,uVar1);
  return 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint RFHAL_AutoAckLoadBuffer
               (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  CORE_irqState_t irqState;
  uint uVar1;
  
  irqState = CORE_EnterCritical();
  _DAT_43081104 = 1;
  uVar1 = read_volatile_4(RAC->.SR0);
  uVar1 = uVar1 & 0x20000;
  if (uVar1 == 0) {
    RADIO_TxAckBufferSet
              (*param_1,*(undefined *)(param_1 + 1),&RAC->,&DAT_43081104,param_4);
  }
  else {
    uVar1 = 3;
  }
  _DAT_43081104 = 0;
  CORE_ExitCritical(irqState);
  return uVar1;
}



void RFHAL_AutoAckRxPause(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 | 8);
  return;
}



void RFHAL_AutoAckRxResume(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 & 0xfffffff7);
  return;
}



void RFHAL_AutoAckTxPause(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 | 0x100);
  return;
}



void RFHAL_AutoAckTxResume(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 & 0xfffffeff);
  return;
}



bool RFHAL_AutoAckRxIsPaused(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  return SUB41((uVar1 << 0x1c) >> 0x1f,0);
}



bool RFHAL_AutoAckTxIsPaused(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  return SUB41((uVar1 << 0x17) >> 0x1f,0);
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

bool RFHAL_AutoAckUseTxBuffer(void)

{
  CORE_irqState_t irqState;
  uint uVar1;
  bool bVar2;
  
  irqState = CORE_EnterCritical();
  uVar1 = GENERIC_PHY_CanModifyAck();
  if (uVar1 != 0) {
    uVar1 = read_volatile_4(RAC->.SR0);
    bVar2 = -1 < (int)(uVar1 << 0xe);
    if (bVar2) {
      uRam43081218 = 1;
    }
    uVar1 = (uint)bVar2;
    _DAT_43081104 = 0;
  }
  CORE_ExitCritical(irqState);
  return SUB41(uVar1,0);
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

bool RFHAL_AutoAckCancelAck(void)

{
  CORE_irqState_t irqState;
  uint uVar1;
  bool bVar2;
  
  irqState = CORE_EnterCritical();
  uVar1 = GENERIC_PHY_CanModifyAck();
  if (uVar1 != 0) {
    uVar1 = read_volatile_4(RAC->.SR0);
    bVar2 = -1 < (int)(uVar1 << 0xe);
    if (bVar2) {
      uRam43081214 = 1;
    }
    uVar1 = (uint)bVar2;
    _DAT_43081104 = 0;
  }
  CORE_ExitCritical(irqState);
  return SUB41(uVar1,0);
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RFHAL_AutoAckWaitForAck(uint param_1)

{
  _DAT_43081120 = param_1 ^ 1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

code * RFHAL_TxStart(undefined4 param_1,undefined *param_2,code *param_3,undefined4 param_4)

{
  bool bVar1;
  
  if (param_2 != (undefined *)0x0) {
    bVar1 = RFHAL_AutoAckIsEnabled();
    if (bVar1 != false) {
      RFHAL_AutoAckWaitForAck(*param_2);
    }
  }
  if (param_3 == FUN_00000000) {
    GENERIC_PHY_PacketTx();
  }
  else {
    param_3 = (code *)(*param_3)(param_4);
    if (param_3 != FUN_00000000) {
      _DAT_43081120 = 0;
      return param_3;
    }
  }
  return param_3;
}



uint8_t RAIL_RfInit(RAIL_Init_t *railInit)

{
  uint8_t uVar1;
  
  RFHAL_CalibrationInit(railInit->calEnable & 0x10001);
  uVar1 = RFHAL_Init(railInit);
  return uVar1;
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
  
  RFHAL_IdleExt();
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
  
  uVar1 = read_volatile_4(RAC->.STATUS);
  uVar1 = uVar1 & 0xf000000;
  if (uVar1 != 0x6000000) {
    if (0x6000000 < uVar1) {
      if (uVar1 != 0x9000000) {
        if (uVar1 < 0x9000001) {
          if (uVar1 == 0x7000000) {
            return RAIL_RF_STATE_RX;
          }
          bVar2 = uVar1 == 0x8000000;
        }
        else {
          if (uVar1 == 0xb000000) {
            return RAIL_RF_STATE_TX;
          }
          if (uVar1 == 0xc000000) {
            return RAIL_RF_STATE_TX;
          }
          bVar2 = uVar1 == 0xa000000;
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



bool RAIL_ChannelExists(uint16_t channel)

{
  uint uVar1;
  byte bVar2;
  
  bVar2 = 0;
  while( true ) {
    uVar1 = (uint)bVar2;
    if (channelConfig->length <= uVar1) {
      return true;
    }
    if ((channelConfig->configs[uVar1].channelNumberStart <= channel) &&
       (channel <= channelConfig->configs[uVar1].channelNumberEnd)) break;
    bVar2 = bVar2 + 1;
  }
  return false;
}



void RAILInt_TrackChannelConfig(RAIL_ChannelConfig_t *param_1)

{
  channelConfig = param_1;
  return;
}



uint8_t RAILInt_SetChannel(uint8_t channel)

{
  int iVar1;
  uint32_t uVar2;
  RAIL_ChannelConfigEntry_t *pRVar3;
  
  if (((channelConfig != (RAIL_ChannelConfig_t *)0x0) &&
      (pRVar3 = channelConfig->configs, pRVar3 != (RAIL_ChannelConfigEntry_t *)0x0)) &&
     (channelConfig->length != 0)) {
    uVar2 = 0;
    do {
      if ((pRVar3->channelNumberStart <= (ushort)channel) &&
         ((ushort)channel <= pRVar3->channelNumberEnd)) {
        if ((currentEntry == pRVar3) && (currentChannel == channel)) {
          return '\0';
        }
        iVar1 = (int)currentEntry - (int)pRVar3;
        if (iVar1 != 0) {
          iVar1 = 1;
        }
        iVar1 = RFHAL_SetChannel(channel,pRVar3,iVar1);
        if (iVar1 == 0) {
          currentChannel = channel;
          currentEntry = pRVar3;
          return (uint8_t)iVar1;
        }
        return (uint8_t)iVar1;
      }
      uVar2 = uVar2 + 1;
      pRVar3 = pRVar3 + 1;
    } while (uVar2 != channelConfig->length);
  }
  return '\x01';
}



undefined RAILInt_GetChannel(void)

{
  return currentChannel;
}



void RAIL_VersionGet(RAIL_Version_t *version,bool verbose)

{
  version->major = '\x01';
  version->minor = '\x04';
  version->rev = '\x01';
  if (verbose != false) {
    version->build = '\x01';
    version->hash = 0x8cb9ff28;
    version->flags = '\0';
    return;
  }
  version->build = '\0';
  version->hash = 0;
  version->flags = '\0';
  return;
}



RAIL_Status_t RAIL_DebugModeSet(uint32_t DebugMode)

{
  if (RAIL_DebugMode == 1) {
    currentEntry = 0;
  }
  RAIL_DebugMode = DebugMode;
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
RAIL_SetRxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error,uint8_t ignoreerrors)

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
      RVar2 = RFHAL_ErrorConfig(ignoreerrors);
      return RVar2;
    }
  }
  return RVar2;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint8_t RAIL_RxConfig(uint32_t cbToEnable,bool appendedInfoEnable)

{
  _enabledCallbacks =
       CONCAT11(DAT_20002f75 & 0xe3 | (byte)(((cbToEnable << 0x1e) >> 0x1f) << 2) |
                (byte)(((cbToEnable << 0x1d) >> 0x1f) << 3) |
                (byte)(((cbToEnable << 0x1c) >> 0x1f) << 4),enabledCallbacks);
  _enabledCallbacks =
       _enabledCallbacks & 0xffff0000 | _enabledCallbacks & 0xffffff00 |
       (uint)(byte)(enabledCallbacks & 0x87 | (byte)(((cbToEnable << 0x1b) >> 0x1f) << 3) |
                    (byte)(((cbToEnable << 0x1a) >> 0x1f) << 4) |
                    (byte)(((cbToEnable << 0x15) >> 0x1f) << 5) | ((cbToEnable & 0x300) != 0) << 6);
  rxConfigEvents = cbToEnable;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  return '\0';
}



uint8_t RAIL_RxStart(uint8_t channel)

{
  bool bVar1;
  uint8_t uVar2;
  
  bVar1 = RFHAL_HeadedToIdle();
  if (bVar1 == false) {
    uVar2 = '\x02';
  }
  else {
    uVar2 = RAILInt_SetChannel(channel);
    if (uVar2 == '\0') {
      uVar2 = RFHAL_RxStart();
      return uVar2;
    }
  }
  return uVar2;
}



uint8_t RAIL_ScheduleRx(uint8_t channel,RAIL_ScheduleRxConfig_t *cfg)

{
  RAIL_RadioState_t RVar1;
  uint8_t uVar2;
  
  RVar1 = RAIL_RfStateGet();
  if (RVar1 == RAIL_RF_STATE_IDLE) {
    uVar2 = RAILInt_SetChannel(channel);
    if (uVar2 == '\0') {
      uVar2 = RFHAL_ScheduleRx(channel,cfg);
      return uVar2;
    }
  }
  else {
    uVar2 = '\x02';
  }
  return uVar2;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 RAIL_TxConfig(uint param_1)

{
  _enabledCallbacks =
       CONCAT12(DAT_20002f76 & 0x3f | 0x20 | (byte)(((param_1 << 0x19) >> 0x1f) << 6) |
                (byte)(((param_1 << 0x18) >> 0x1f) << 7),_enabledCallbacks);
  _enabledCallbacks =
       _enabledCallbacks & 0xff000000 | _enabledCallbacks & 0xffffff00 |
       (uint)(byte)(enabledCallbacks & 0xfd | ((param_1 & 0x1a) != 0) << 1);
  txConfigEvents = param_1;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  return 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint RAIL_TxDataLoad(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  CORE_irqState_t irqState;
  uint uVar1;
  
  irqState = CORE_EnterCritical();
  _DAT_43081100 = 1;
  uVar1 = read_volatile_4(RAC->.SR0);
  uVar1 = uVar1 & 0x10000;
  if (uVar1 == 0) {
    RADIO_TxBufferSet(*param_1,*(undefined2 *)(param_1 + 1),0,0,param_4);
  }
  else {
    uVar1 = 3;
  }
  _DAT_43081100 = 0;
  CORE_ExitCritical(irqState);
  return uVar1;
}



uint RAIL_TxStartWithOptions
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = RFHAL_OkToTransmit();
  if (iVar2 == 0) {
    uVar3 = 2;
  }
  else {
    bVar1 = RAILInt_SetChannel((uint8_t)param_1);
    uVar3 = (uint)bVar1;
    if (uVar3 == 0) {
      uVar3 = RFHAL_TxStart(param_1,param_2,param_3,param_4);
      return uVar3;
    }
  }
  return uVar3;
}



void RAIL_TxStart(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  RAIL_TxStartWithOptions(param_1,0,param_2,param_3);
  return;
}



uint8_t RAIL_TxToneStart(uint8_t param_1)

{
  uint8_t uVar1;
  
  uVar1 = RAILInt_SetChannel(param_1);
  if (uVar1 == '\0') {
    RFHAL_StartCWTestMode();
  }
  return uVar1;
}



undefined4 RAIL_TxToneStop(void)

{
  RFHAL_StopTestMode();
  return 0;
}



uint8_t RAIL_TxStreamStart(uint8_t param_1,int param_2)

{
  uint8_t uVar1;
  
  if (param_2 == 1) {
    uVar1 = RAILInt_SetChannel(param_1);
    if (uVar1 == '\0') {
      RFHAL_StartStreamTestMode();
    }
    return uVar1;
  }
  return '\x01';
}



undefined4 RAIL_TxStreamStop(void)

{
  RFHAL_StopTestMode();
  return 0;
}



undefined4 RAIL_TxPowerSet(void)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = PA_OutputPowerSet();
  pcVar1 = protChChngCB;
  if (protChChngCB != FUN_00000000) {
    uVar3 = RAILInt_GetChannel();
    (*pcVar1)(uVar3,1);
  }
  return uVar2;
}



int RAIL_TxPowerGet(void)

{
  return (int)gPaConfig.power;
}



void RFHAL_CalibrationInit(RAIL_CalMask_t calEnable)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  RAIL_CalPend = 0;
  RAIL_CalEnable = calEnable;
  CORE_ExitCritical(irqState);
  return;
}



void RFHAL_CalibrationPend(RAIL_CalMask_t calpend)

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



uint RFHAL_CalibrationClear(uint param_1)

{
  CORE_irqState_t irqState;
  uint uVar1;
  
  irqState = CORE_EnterCritical();
  uVar1 = RAIL_CalPend & ~(param_1 & RAIL_CalEnable);
  RAIL_CalPend = uVar1;
  CORE_ExitCritical(irqState);
  return uVar1;
}



undefined4 RFHAL_CalibrationEnableGet(void)

{
  return RAIL_CalEnable;
}



RAIL_CalMask_t RFHAL_CalibrationPendingGet(void)

{
  RAIL_CalMask_t RVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  RVar1 = RAIL_CalPend;
  CORE_ExitCritical(irqState);
  return RVar1;
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



void RAIL_CalStart(undefined4 *calValues,RAIL_CalMask_t calForce,bool calSave)

{
  undefined4 local_14;
  
  if (calValues == (undefined4 *)0x0) {
    local_14 = 0xffffffff;
  }
  else {
    local_14 = *calValues;
  }
  if (calForce == 0) {
    calForce = RFHAL_CalibrationPendingGet();
  }
  RFHAL_CalibrationClear(calForce);
  RFHAL_CalibrationRun(&local_14,calForce);
  if ((calSave != false) && (calValues != (undefined4 *)0x0)) {
    *calValues = local_14;
  }
  return;
}



uint8_t RAIL_CalInit(RAIL_CalInit_t *railCalInit)

{
  uint8_t uVar1;
  
  uVar1 = IRCAL_Init(railCalInit->irCalSettings);
  RFHAL_CalibrationInit(railCalInit->calEnable & 0x10001);
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
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
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
    RVar1 = RFHAL_AutoAckLoadBuffer();
    return RVar1;
  }
  return RAIL_STATUS_INVALID_PARAMETER;
}



void RAIL_AutoAckRxPause(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 | 8);
  return;
}



void RAIL_AutoAckRxResume(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 & 0xfffffff7);
  return;
}



bool RAIL_AutoAckRxIsPaused(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  return SUB41((uVar1 << 0x1c) >> 0x1f,0);
}



void RAIL_AutoAckTxPause(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 | 0x100);
  return;
}



void RAIL_AutoAckTxResume(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 & 0xfffffeff);
  return;
}



bool RAIL_AutoAckTxIsPaused(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  return SUB41((uVar1 << 0x17) >> 0x1f,0);
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

bool RAIL_AutoAckUseTxBuffer(void)

{
  CORE_irqState_t irqState;
  uint uVar1;
  bool bVar2;
  
  irqState = CORE_EnterCritical();
  uVar1 = GENERIC_PHY_CanModifyAck();
  if (uVar1 != 0) {
    uVar1 = read_volatile_4(RAC->.SR0);
    bVar2 = -1 < (int)(uVar1 << 0xe);
    if (bVar2) {
      uRam43081218 = 1;
    }
    uVar1 = (uint)bVar2;
    _DAT_43081104 = 0;
  }
  CORE_ExitCritical(irqState);
  return SUB41(uVar1,0);
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

bool RAIL_AutoAckCancelAck(void)

{
  CORE_irqState_t irqState;
  uint uVar1;
  bool bVar2;
  
  irqState = CORE_EnterCritical();
  uVar1 = GENERIC_PHY_CanModifyAck();
  if (uVar1 != 0) {
    uVar1 = read_volatile_4(RAC->.SR0);
    bVar2 = -1 < (int)(uVar1 << 0xe);
    if (bVar2) {
      uRam43081214 = 1;
    }
    uVar1 = (uint)bVar2;
    _DAT_43081104 = 0;
  }
  CORE_ExitCritical(irqState);
  return SUB41(uVar1,0);
}



void RAIL_BerRxStop(void)

{
  RFHAL_StopBerRx();
  RAIL_RfIdle();
  return;
}



void RAIL_BerConfigSet(RAIL_BerConfig_t *berConfig)

{
  RAIL_BerRxStop();
  RFHAL_SetBerConfig(berConfig);
  berConfigGlobal = berConfig->bytesToTest;
  return;
}



void RAIL_BerRxStart(void)

{
  RAIL_BerRxStop();
  RFHAL_SetBerConfig((RAIL_BerConfig_t *)&berConfigGlobal);
  RFHAL_StartBerRx();
  return;
}



void RAIL_BerStatusGet(RAIL_BerStatus_t *berstatus)

{
  uint32_t in_r1;
  uint32_t in_r2;
  int8_t in_r3;
  RAIL_BerStatus_t RStack24;
  
  RStack24.bitsTotal = (uint32_t)berstatus;
  RStack24.bitsTested = in_r1;
  RStack24.bitErrors = in_r2;
  RStack24.rssi = in_r3;
  RFTEST_ReportBerStats(&RStack24);
  berstatus->bitsTotal = RStack24.bitsTotal;
  berstatus->bitsTested = RStack24.bitsTested;
  berstatus->bitErrors = RStack24.bitErrors;
  berstatus->rssi = RStack24.rssi;
  return;
}



RAIL_Status_t RAIL_IEEE802154_2p4GHzRadioConfig(void)

{
  uint8_t uVar1;
  RAIL_Status_t RVar2;
  undefined4 extraout_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  
  uVar1 = RAIL_ChannelConfig((RAIL_ChannelConfig_t *)&channels);
  RVar2 = RFHAL_IEEE802154RadioConfig2p4GHz(uVar1,extraout_r1,in_r2,in_r3);
  return RVar2;
}



bool RAIL_IEEE802154_SetAddresses(RAIL_IEEE802154_AddrConfig_t *addresses)

{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  
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
  undefined uVar1;
  uint in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  uint auStack12 [3];
  
  auStack12[0] = in_r1 & 0xffff0000 | (uint)shortAddr;
  uVar1 = GENERIC_PHY_SetIeeeShortAddress(1,auStack12,in_r2,in_r3,shortAddr);
  return (bool)uVar1;
}



void RAIL_IEEE802154_SetLongAddress(undefined4 param_1)

{
  GENERIC_PHY_SetIeeeLongAddress(1,param_1);
  return;
}



RAIL_Status_t RAIL_IEEE802154_SetPanCoordinator(bool isPanCoordinator)

{
  RAIL_Status_t RVar1;
  int iVar2;
  
  iVar2 = RFHAL_IEEE802154IsEnabled();
  if (iVar2 != 0) {
    RVar1 = RFHAL_IEEE802154SetPanCoordinator(isPanCoordinator);
    return RVar1;
  }
  return RAIL_STATUS_INVALID_STATE;
}



RAIL_Status_t RAIL_IEEE802154_SetPromiscuousMode(bool enable)

{
  RAIL_Status_t RVar1;
  int iVar2;
  
  iVar2 = RFHAL_IEEE802154IsEnabled();
  if (iVar2 != 0) {
    RVar1 = RFHAL_IEEE802154SetPromiscuousMode(enable);
    return RVar1;
  }
  return RAIL_STATUS_INVALID_STATE;
}



RAIL_Status_t RAIL_IEEE802154_AcceptFrames(uint8_t framesMask)

{
  RAIL_Status_t RVar1;
  int iVar2;
  
  iVar2 = RFHAL_IEEE802154IsEnabled();
  if (iVar2 != 0) {
    RVar1 = RFHAL_IEEE802154AcceptFrames(framesMask);
    return RVar1;
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



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

RAIL_Status_t RAIL_IEEE802154_SetFramePending(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = GENERIC_PHY_CanModifyAck();
  if (iVar1 == 0) {
    return RAIL_STATUS_INVALID_STATE;
  }
  uVar2 = read_volatile_4(RAC->.SR0);
  uVar2 = uVar2 & 0x20000;
  if (uVar2 == 0) {
    uRam43081210 = 1;
  }
  else {
    uVar2 = 2;
  }
  _DAT_43081104 = 0;
  return (RAIL_Status_t)uVar2;
}



RAIL_Status_t RAIL_BLE_Init(void)

{
  RAIL_Status_t RVar1;
  
  RFHAL_BleInit();
  isBleEnabled = 1;
  RVar1 = RAIL_SetPtiProtocol(RAIL_PTI_PROTOCOL_BLE);
  return RVar1;
}



uint RAIL_BLE_Deinit(uint param_1)

{
  RAIL_Status_t RVar1;
  
  if (isBleEnabled != '\0') {
    RFHAL_BleDeinit();
    isBleEnabled = 0;
    RVar1 = RAIL_SetPtiProtocol(RAIL_PTI_PROTOCOL_CUSTOM);
    return (uint)RVar1;
  }
  return param_1;
}



bool RAIL_BLE_IsEnabled(void)

{
  return (bool)isBleEnabled;
}



bool RAIL_BLE_SetPhy1MbpsViterbi(void)

{
  RAIL_RadioState_t RVar1;
  undefined uVar2;
  
  if (isBleEnabled != '\0') {
    RVar1 = RFHAL_StateGet();
    if (RVar1 == RAIL_RF_STATE_IDLE) {
      uVar2 = RFHAL_Ble1MbpsSet();
      return (bool)uVar2;
    }
  }
  return false;
}



bool RAIL_BLE_SetPhy1Mbps(void)

{
  RAIL_RadioState_t RVar1;
  undefined uVar2;
  undefined4 extraout_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  
  if ((isBleEnabled != '\0') && (RVar1 = RFHAL_StateGet(), RVar1 == RAIL_RF_STATE_IDLE)) {
    uVar2 = RFHAL_Ble1MbpsSet(1,extraout_r1,in_r2,in_r3);
    return (bool)uVar2;
  }
  return false;
}



bool RAIL_BLE_SetPhy2MbpsViterbi(void)

{
  RAIL_RadioState_t RVar1;
  undefined uVar2;
  
  if (isBleEnabled != '\0') {
    RVar1 = RFHAL_StateGet();
    if (RVar1 == RAIL_RF_STATE_IDLE) {
      uVar2 = RFHAL_Ble2MbpsSet();
      return (bool)uVar2;
    }
  }
  return false;
}



bool RAIL_BLE_SetPhy2Mbps(void)

{
  RAIL_RadioState_t RVar1;
  undefined uVar2;
  undefined4 extraout_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  
  if ((isBleEnabled != '\0') && (RVar1 = RFHAL_StateGet(), RVar1 == RAIL_RF_STATE_IDLE)) {
    uVar2 = RFHAL_Ble2MbpsSet(1,extraout_r1,in_r2,in_r3);
    return (bool)uVar2;
  }
  return false;
}



bool RAIL_BLE_SetupChannelRadioParams
               (uint32_t crcInit,uint32_t accessAddress,uint8_t channel,bool disableWhitening)

{
  byte bVar1;
  byte bVar2;
  undefined uVar3;
  undefined4 uVar4;
  byte bVar5;
  
  bVar5 = (byte)crcInit;
  bVar1 = (byte)(crcInit >> 8);
  bVar2 = (byte)(crcInit >> 0x10);
  RFHAL_SetCRCInitVal(((uint)(byte)((((((((bVar5 & 1) << 1 | bVar5 >> 1 & 1) << 1 | bVar5 >> 2 & 1)
                                        << 1 | bVar5 >> 3 & 1) << 1 | bVar5 >> 4 & 1) << 1 |
                                     bVar5 >> 5 & 1) << 1 | bVar5 >> 6 & 1) << 1 | bVar5 >> 7) <<
                       0x18 | (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 |
                                               bVar1 >> 2 & 1) << 1 | bVar1 >> 3 & 1) << 1 |
                                             bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) << 1 |
                                           bVar1 >> 6 & 1) << 1 | bVar1 >> 7) << 0x10 |
                      (uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1)
                                       << 1 | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 |
                                    bVar2 >> 5 & 1) << 1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 8)
                      >> 8);
  if ((accessAddress & 1) == 0) {
    uVar4 = 0xaa;
  }
  else {
    uVar4 = 0x55;
  }
  RFHAL_BLEPreambleSyncWordSet(uVar4,accessAddress);
  if (disableWhitening != false) {
    uVar4 = 0;
    bVar5 = 0;
  }
  else {
    uVar4 = 0x44;
    bVar5 = channel | 0x40;
  }
  uVar3 = RFHAL_BLEWhiteningSet(uVar4,bVar5,disableWhitening == false);
  return (bool)uVar3;
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
    uVar1 = read_volatile_4(RAC->.IFPGACAL);
    write_volatile_4(RAC->.IFPGACAL,uVar1 & 0xffff0000 | param_1 & 0xffff);
  }
  return;
}



undefined4 IRCAL_Init(byte *param_1)

{
  byte bVar1;
  byte bVar2;
  
  if ((param_1 != (byte *)0x0) && (0x11 < *param_1)) {
    rcIrCalData[5] = param_1[6];
    if (rcIrCalData[5] != 0) {
      rcIrCalData[5] = 1;
    }
    rcIrCalData[6] = param_1[7];
    if (rcIrCalData[6] != 0) {
      rcIrCalData[6] = 1;
    }
    rcIrCalData[7] = param_1[8];
    if (rcIrCalData[7] != 0) {
      rcIrCalData[7] = 1;
    }
    if (*param_1 < 0x18) {
      rcIrCalData[9] = param_1[10];
      if (rcIrCalData[9] != 0) {
        rcIrCalData[9] = 1;
      }
      rcIrCalData[10] = param_1[0xb];
      rcIrCalData[11] = param_1[0xc];
      rcIrCalData._12_2_ = CONCAT11(param_1[0xe],param_1[0xd]);
      bVar1 = param_1[0x10];
      bVar2 = param_1[0xf];
    }
    else {
      rcIrCalData[9] = param_1[0x12];
      if (rcIrCalData[9] != 0) {
        rcIrCalData[9] = 1;
      }
      rcIrCalData[10] = param_1[0x13];
      rcIrCalData[11] = param_1[0x14];
      rcIrCalData._12_2_ = CONCAT11(param_1[0x16],param_1[0x15]);
      bVar1 = param_1[0x18];
      bVar2 = param_1[0x17];
    }
    rcIrCalData[0] = param_1[1];
    rcIrCalData[1] = param_1[2];
    rcIrCalData[2] = param_1[3];
    rcIrCalData[3] = param_1[4];
    rcIrCalData[4] = param_1[5];
    rcIrCalData[8] = param_1[9];
    rcIrCalData._14_2_ = CONCAT11(bVar1,bVar2);
    rcIrCalData[16] = param_1[0x11];
    return 0;
  }
  IRCAL_Set(0);
  return 1;
}



void IRCAL_SaveRegStates(void)

{
  uint uVar1;
  
  RADIO_rxBuffer._0_4_ = read_volatile_4(RAC->.SGRFENCTRL0);
  RADIO_rxBuffer._4_4_ = read_volatile_4(RAC->.RFENCTRL0);
  RADIO_rxBuffer._8_4_ = read_volatile_4(AGC->.CTRL0);
  RADIO_rxBuffer._12_4_ = read_volatile_4(AGC->.MANGAIN);
  RADIO_rxBuffer._16_4_ = read_volatile_4(AGC->.GAINRANGE);
  RADIO_rxBuffer._20_4_ = read_volatile_4(AGC->.GAININDEX);
  RADIO_rxBuffer._24_4_ = read_volatile_4(AGC->.MININDEX);
  RADIO_rxBuffer._28_4_ = read_volatile_4(MODEM->.MODINDEX);
  RADIO_rxBuffer._32_4_ = read_volatile_4(MODEM->.CTRL0);
  RADIO_rxBuffer._36_4_ = read_volatile_4(FRC->.DFLCTRL);
  RADIO_rxBuffer._40_4_ = read_volatile_4(RAC->.SGPACTRL0);
  RADIO_rxBuffer._44_4_ = read_volatile_4(RAC->.SGPAPKDCTRL);
  RADIO_rxBuffer._48_4_ = read_volatile_4(RAC->.SGPABIASCTRL0);
  RADIO_rxBuffer._52_4_ = read_volatile_4(RAC->.SGPABIASCTRL1);
  RADIO_rxBuffer._56_4_ = read_volatile_4(RAC->.PACTUNECTRL);
  RADIO_rxBuffer._60_4_ = read_volatile_4(MODEM->.RAMPCTRL);
  RADIO_rxBuffer._64_4_ = read_volatile_4(RAC->.TESTCTRL);
  RADIO_rxBuffer._68_4_ = read_volatile_4(AGC->.CTRL1);
  RADIO_rxBuffer._72_4_ = read_volatile_4(MODEM->.AFC);
  RADIO_rxBuffer._76_4_ = SYNTH_RfFreqGet();
  RADIO_rxBuffer._80_4_ = SYNTH_ChSpacingGet();
  write_volatile_4(MODEM->.AFC,0);
  uVar1 = read_volatile_4(FRC->.CTRL);
  write_volatile_4(FRC->.CTRL,uVar1 | 1);
  uVar1 = read_volatile_4(RAC->.CTRL);
  write_volatile_4(RAC->.CTRL,uVar1 | 0x40);
  uVar1 = read_volatile_4(AGC->.CTRL1);
  write_volatile_4(AGC->.CTRL1,uVar1 & 0xfffff0ff | (rcIrCalData[16] & 0xf) << 8);
  return;
}



undefined4 IRCAL_SetRxFrequency(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = SYNTH_IfFreqGet();
  uVar1 = read_volatile_4(Peripherals::SYNTH.IFFREQ);
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



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void IRCAL_StartRx(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(MODEM->.CTRL0);
  write_volatile_4(MODEM->.CTRL0,uVar1 | 0x200000);
  do {
    uVar1 = read_volatile_4(RAC->.STATUS);
  } while ((uVar1 & 0xf000000) != 0);
  RADIO_RxBufferReset();
  do {
    uVar1 = read_volatile_4(RAC->.STATUS);
  } while ((uVar1 << 4) >> 0x1c != 2);
  _DAT_4308000c = 1;
  return;
}



void IRCAL_StopRx(undefined4 param_1,undefined4 param_2,int param_3)

{
  CORE_irqState_t irqState;
  uint uVar1;
  bool bVar2;
  
  uVar1 = read_volatile_4(RAC->.RXENSRCEN);
  write_volatile_4(RAC->.RXENSRCEN,uVar1 & 0xffffff00);
  irqState = CORE_EnterCritical();
  uVar1 = read_volatile_4(RAC->.STATUS);
  uVar1 = (uVar1 << 4) >> 0x1c;
  bVar2 = uVar1 == 3;
  if (bVar2) {
    param_3 = 0x21000f68;
    uVar1 = read_volatile_4(Peripherals::SEQ.REG070);
    uVar1 = uVar1 & 0xffffff01 | 0xe;
  }
  if (bVar2) {
    *(uint *)(param_3 + 8) = uVar1;
  }
  write_volatile_4(FRC->.CMD,1);
  CORE_ExitCritical(irqState);
  do {
    uVar1 = read_volatile_4(RAC->.STATUS);
  } while ((uVar1 & 0xf000000) != 0);
  return;
}



void IRCAL_SetSubGhzPllLoopback(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(AGC->.MANGAIN);
  write_volatile_4(AGC->.MANGAIN,uVar1 & 0x801001ff | 0x40009800);
  uVar1 = read_volatile_4(AGC->.CTRL0);
  write_volatile_4(AGC->.CTRL0,uVar1 | 0x400000);
  uVar1 = read_volatile_4(RAC->.SGRFENCTRL0);
  write_volatile_4(RAC->.SGRFENCTRL0,uVar1 | 0x80000);
  uVar1 = read_volatile_4(RAC->.RFENCTRL0);
  write_volatile_4(RAC->.RFENCTRL0,uVar1 | 0x80000);
  return;
}



void IRCAL_SetSubGhzPaLoopback(void)

{
  uint uVar1;
  undefined4 extraout_r1;
  undefined4 in_r3;
  
  uVar1 = read_volatile_4(AGC->.GAINRANGE);
  write_volatile_4(AGC->.GAINRANGE,uVar1 & 0xffffc000 | 0x383e);
  uVar1 = read_volatile_4(AGC->.GAININDEX);
  write_volatile_4(AGC->.GAININDEX,uVar1 & 0xfff00000 | 0x25bc);
  uVar1 = read_volatile_4(AGC->.MININDEX);
  write_volatile_4(AGC->.MININDEX,uVar1 & 0xff000000 | 0x6d8480);
  uVar1 = read_volatile_4(AGC->.MANGAIN);
  write_volatile_4(AGC->.MANGAIN,uVar1 & 0xffffff40 | 0xa7);
  uVar1 = read_volatile_4(AGC->.CTRL0);
  write_volatile_4(AGC->.CTRL0,uVar1 | 0x400000);
  write_volatile_4(MODEM->.MODINDEX,0);
  uVar1 = read_volatile_4(MODEM->.CTRL0);
  write_volatile_4(MODEM->.CTRL0,uVar1 & 0xfffffe3f | 0x100);
  uVar1 = read_volatile_4(FRC->.DFLCTRL);
  write_volatile_4(FRC->.DFLCTRL,uVar1 & 0xfffffff8 | 5);
  uVar1 = read_volatile_4(RAC->.SGRFENCTRL0);
  write_volatile_4(RAC->.SGRFENCTRL0,uVar1 & 0xfff7ffff);
  uVar1 = read_volatile_4(RAC->.SGPACTRL0);
  write_volatile_4(RAC->.SGPACTRL0,uVar1 & 0x3fffffff | 0x40000000);
  uVar1 = read_volatile_4(RAC->.SGPAPKDCTRL);
  write_volatile_4(RAC->.SGPAPKDCTRL,uVar1 | 0xc000);
  uVar1 = read_volatile_4(RAC->.SGPABIASCTRL0);
  write_volatile_4(RAC->.SGPABIASCTRL0,uVar1 & 0xff3ff332 | 0x445);
  uVar1 = read_volatile_4(RAC->.SGPABIASCTRL1);
  write_volatile_4(RAC->.SGPABIASCTRL1,uVar1 & 0xffffffc8 | 0x20);
  uVar1 = read_volatile_4(RAC->.SGPABIASCTRL1);
  write_volatile_4(RAC->.SGPABIASCTRL1,uVar1 & 0xfff388ff | 0x84500);
  uVar1 = read_volatile_4(RAC->.PACTUNECTRL);
  write_volatile_4(RAC->.PACTUNECTRL,uVar1 & 0xfffffe0f);
  uVar1 = read_volatile_4(RAC->.SGPACTRL0);
  write_volatile_4(RAC->.SGPACTRL0,uVar1 | 8);
  uVar1 = read_volatile_4(RAC->.SGRFENCTRL0);
  write_volatile_4(RAC->.SGRFENCTRL0,uVar1 | 0x10000);
  PHY_UTILS_DelayUs(0x14);
  uVar1 = read_volatile_4(RAC->.SGPACTRL0);
  write_volatile_4(RAC->.SGPACTRL0,uVar1 & 0xffffc03f | 0x40);
  uVar1 = read_volatile_4(RAC->.SGRFENCTRL0);
  write_volatile_4(RAC->.SGRFENCTRL0,uVar1 | 0x20000);
  PHY_UTILS_DelayUs(0x14);
  uVar1 = read_volatile_4(RAC->.SGPACTRL0);
  write_volatile_4(RAC->.SGPACTRL0,uVar1 & 0xe0c03fff | 0x1004000);
  PHY_UTILS_DelayUs(0x14);
  uVar1 = read_volatile_4(RAC->.SGRFENCTRL0);
  write_volatile_4(RAC->.SGRFENCTRL0,uVar1 | 0x40000);
  PHY_UTILS_DelayUs(0x14);
  uVar1 = read_volatile_4(RAC->.TESTCTRL);
  write_volatile_4(RAC->.TESTCTRL,uVar1 | 9);
  PHY_UTILS_DelayUs(0x14);
  uVar1 = read_volatile_4(RAC->.SGPACTRL0);
  write_volatile_4(RAC->.SGPACTRL0,uVar1 & 0xe0c03fff | 0x1004000);
  PHY_UTILS_DelayUs(0x14);
  uVar1 = read_volatile_4(MODEM->.RAMPCTRL);
  write_volatile_4(MODEM->.RAMPCTRL,
                   uVar1 & 0x7fffff | 0x800000 | (uint)rcIrCalData[2] << 0x18);
  PHY_UTILS_DelayUs(0x14,extraout_r1,rcIrCalData[2],in_r3);
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



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

int IRCAL_ReadRssi(uint param_1,uint param_2,uint param_3,undefined4 param_4,undefined2 param_5)

{
  uint uVar1;
  short sVar2;
  int iVar3;
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
    uVar5 = read_volatile_4(RAC->.IFPGACAL);
    write_volatile_4(RAC->.IFPGACAL,uVar5 & 0xffff8080 | param_1 << 8 | param_2);
    PHY_UTILS_DelayUs(param_4);
    if (rcIrCalData[9] == '\0') {
      _DAT_430e0714 = 1;
    }
    uVar5 = 0;
    uVar4 = 0;
    for (uVar6 = 0; uVar6 >> (param_3 & 0xff) == 0; uVar6 = uVar6 + 1) {
      PHY_UTILS_DelayUs(param_5);
      if (rcIrCalData[9] == '\0') {
        write_volatile_4(AGC->.CMD,1);
        do {
          uVar1 = read_volatile_4(AGC->.IF);
        } while (-1 < (int)(uVar1 << 0x1a));
      }
      if (rcIrCalData[11] <= uVar6) {
        iVar3 = RADIO_GetRSSI();
        uVar5 = uVar5 + 1;
        uVar4 = uVar4 + iVar3;
      }
      if (rcIrCalData[9] == '\0') {
        _DAT_430e0714 = 1;
      }
    }
    if (uVar5 == 0) {
      uVar5 = 1;
    }
    sVar2 = (short)(uVar4 / uVar5);
  }
  else {
    sVar2 = -1;
  }
  return (int)sVar2;
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
  uint uVar1;
  undefined4 in_r3;
  
  IRCAL_StopRx();
  AUXPLL_Stop();
  write_volatile_4(RAC->.SGRFENCTRL0,RADIO_rxBuffer._0_4_);
  write_volatile_4(RAC->.RFENCTRL0,RADIO_rxBuffer._4_4_);
  write_volatile_4(AGC->.CTRL0,RADIO_rxBuffer._8_4_);
  write_volatile_4(AGC->.MANGAIN,RADIO_rxBuffer._12_4_);
  write_volatile_4(AGC->.GAINRANGE,RADIO_rxBuffer._16_4_);
  write_volatile_4(AGC->.GAININDEX,RADIO_rxBuffer._20_4_);
  write_volatile_4(AGC->.MININDEX,RADIO_rxBuffer._24_4_);
  write_volatile_4(MODEM->.MODINDEX,RADIO_rxBuffer._28_4_);
  write_volatile_4(MODEM->.CTRL0,RADIO_rxBuffer._32_4_);
  write_volatile_4(FRC->.DFLCTRL,RADIO_rxBuffer._36_4_);
  write_volatile_4(RAC->.SGPACTRL0,RADIO_rxBuffer._40_4_);
  write_volatile_4(RAC->.SGPAPKDCTRL,RADIO_rxBuffer._44_4_);
  write_volatile_4(RAC->.SGPABIASCTRL0,RADIO_rxBuffer._48_4_);
  write_volatile_4(RAC->.SGPABIASCTRL1,RADIO_rxBuffer._52_4_);
  write_volatile_4(RAC->.PACTUNECTRL,RADIO_rxBuffer._56_4_);
  write_volatile_4(MODEM->.RAMPCTRL,RADIO_rxBuffer._60_4_);
  write_volatile_4(RAC->.TESTCTRL,RADIO_rxBuffer._64_4_);
  write_volatile_4(AGC->.CTRL1,RADIO_rxBuffer._68_4_);
  write_volatile_4(MODEM->.AFC,RADIO_rxBuffer._72_4_);
  SYNTH_Config(RADIO_rxBuffer._76_4_,RADIO_rxBuffer._80_4_,RADIO_rxBuffer._72_4_,RADIO_rxBuffer,
               in_r3);
  RADIO_RxBufferReset();
  uVar1 = read_volatile_4(FRC->.CTRL);
  write_volatile_4(FRC->.CTRL,uVar1 & 0xfffffffe);
  uVar1 = read_volatile_4(RAC->.CTRL);
  write_volatile_4(RAC->.CTRL,uVar1 & 0xffffffbf);
  return;
}



uint IRCAL_GetDiValue(void)

{
  uint uVar1;
  
  uVar1 = SYNTH_RfFreqGet();
  if (uVar1 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    if (uVar1 < 1000000000) {
      uVar1 = read_volatile_4(DAT_0fe081c8);
    }
    else {
      uVar1 = read_volatile_4(MODEM->.CTRL0);
      if ((uVar1 << 0x17) >> 0x1d == 4) {
        uVar1 = read_volatile_4(DAT_0fe081c4);
      }
      else {
        uVar1 = read_volatile_4(DAT_0fe081c0);
      }
    }
    if (uVar1 != 0xffffffff) {
      return uVar1 & 0xffff;
    }
  }
  return uVar1;
}



uint IRCAL_PerformSubfunction
               (uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined2 param_5)

{
  uint32_t uVar1;
  uint32_t uVar2;
  int extraout_r1;
  int extraout_r1_00;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  undefined8 uVar7;
  
  uVar4 = read_volatile_4(PROTIMER->.WRAPCNT);
  uVar1 = PROTIMER_PrecntOverflowToUs(uVar4);
  if (param_1 == 1) {
    uVar4 = IRCAL_GetDiValue();
    RADIO_RxBufferReset();
  }
  else {
    if ((param_1 == 0) || (3 < param_1)) {
      uVar4 = 0xffffffff;
    }
    else {
      uVar4 = IRCAL_Setup(param_1);
      if (uVar4 != 0xffffffff) {
        uVar4 = IRCAL_Search(param_2,param_3,param_4,param_5);
      }
      IRCAL_Teardown();
    }
  }
  uVar5 = read_volatile_4(PROTIMER->.WRAPCNT);
  uVar2 = PROTIMER_PrecntOverflowToUs(uVar5);
  uVar7 = __aeabi_uldivmod(uVar2 - uVar1,(extraout_r1_00 - extraout_r1) - (uint)(uVar2 < uVar1),1000
                           ,0);
  iVar3 = (int)((ulonglong)uVar7 >> 0x20);
  bVar6 = iVar3 == 0;
  if (iVar3 == 0) {
    bVar6 = (uint)uVar7 < 0xffff;
  }
  if (bVar6) {
    uVar5 = (uint)uVar7 & 0xfffe;
  }
  else {
    uVar5 = 0;
  }
  if (uVar4 != 0xffffffff) {
    IRCAL_Set(uVar4);
    uVar4 = uVar4 | uVar5 << 0x10;
  }
  return uVar4;
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



void PROTIMER_Init(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  
  RADIOCMU_ClockEnable(0x60400,1,param_3,param_4,param_4);
  write_volatile_4(PROTIMER->.CTRL,(uint)"Variance:%f");
  uVar1 = RADIOCMU_ClockFreqGet(0x60400);
  uVar2 = ((uVar1 / 1000) * 0x200 + 500) / 1000;
  write_volatile_4(PROTIMER->.PRECNTTOP,uVar2 & 0xff | (uVar2 & 0xffffff00) - 0x100);
  write_volatile_4(PROTIMER->.WRAPCNTTOP,0x7fffffff);
  proTimerClockkHz = uVar1 / 1000;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_Start(void)

{
  _DAT_430a0080 = 1;
  _DAT_e000e100 = 0x10000000;
  _DAT_e000e280 = 0x10000000;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_Stop(void)

{
  _DAT_430a0088 = 1;
  _DAT_e000e180 = 0x10000000;
  _DAT_e000e280 = 0x10000000;
  return;
}



uint PROTIMER_IsRunning(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(PROTIMER->.STATUS);
  return uVar1 & 1;
}



void PROTIMER_Reset(void)

{
  write_volatile_4(PROTIMER->.PRECNT,0);
  write_volatile_4(PROTIMER->.BASECNT,0);
  write_volatile_4(PROTIMER->.WRAPCNT,0);
  return;
}



int PROTIMER_ElapsedTime(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = read_volatile_4(PROTIMER->.WRAPCNTTOP);
  iVar2 = param_2 - param_1;
  if (param_2 < param_1) {
    iVar2 = iVar2 + uVar1 + 1;
  }
  return iVar2;
}



void PROTIMER_CCTimerStop(uint param_1)

{
  *(undefined4 *)(param_1 * 0x200 + 0x430a0e80) = 0;
  write_volatile_4(PROTIMER->.IFC,0x100 << (param_1 & 0xff));
  return;
}



undefined4 PROTIMER_CCTimerStart(uint param_1,uint param_2,int param_3)

{
  uint uVar1;
  CORE_irqState_t irqState;
  uint uVar2;
  int iVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  uVar5 = param_1;
  iVar7 = param_3;
  irqState = CORE_EnterCritical();
  PROTIMER_CCTimerStop(param_1);
  if (param_3 == 1) {
    uVar1 = read_volatile_4(PROTIMER->.WRAPCNT);
    param_2 = param_2 + uVar1 + 1;
  }
  else {
    if (param_3 == 2) {
      return 1;
    }
  }
  uVar1 = read_volatile_4(PROTIMER->.WRAPCNTTOP);
  if (uVar1 < param_2) {
    param_2 = (param_2 - uVar1) - 1;
  }
  iVar3 = 0;
  while( true ) {
    (&PROTIMER->.CC0_WRAP)[param_1 * 4] = param_2;
    (&PROTIMER->.CC0_CTRL)[param_1 * 4] = 0x11;
    uVar6 = read_volatile_4(PROTIMER->.WRAPCNT);
    uVar2 = PROTIMER_ElapsedTime(param_2,uVar6,uVar6,param_1 * 0x10 + 0x40085070,uVar5,uVar6,iVar7);
    if (uVar1 >> 2 < uVar2) {
      bVar4 = false;
    }
    else {
      uVar2 = read_volatile_4(PROTIMER->.IFS);
      bVar4 = (0x100 << (param_1 & 0xff) & uVar2) == 0;
    }
    iVar3 = iVar3 + 1;
    param_2 = iVar3 + uVar6;
    if ((param_3 != 1) || (iVar3 == 6)) break;
    if (!bVar4) {
LAB_0000ab38:
      CORE_ExitCritical(irqState);
      return 1;
    }
  }
  if (bVar4) {
    PROTIMER_CCTimerStop(param_1);
    CORE_ExitCritical(irqState);
    return 0;
  }
  goto LAB_0000ab38;
}



uint PROTIMER_CCTimerIsEnabled(int param_1)

{
  return (&PROTIMER->.CC0_CTRL)[param_1 * 4] & 1;
}



void PROTIMER_CCTimerCapture(int param_1,uint param_2)

{
  (&PROTIMER->.CC0_CTRL)[param_1 * 4] = param_2 & 0xe00000 | 3;
  return;
}



// WARNING: Unknown calling convention yet parameter storage is locked

bool PROTIMER_ScheduleTxEnable(void)

{
  undefined uVar1;
  int in_r0;
  
  RADIO_TxWarmTimeGet();
  PROTIMER_CCTimerStop();
  write_volatile_4(PROTIMER->.TXCTRL,(in_r0 + 9) * 0x100 | 1);
  uVar1 = PROTIMER_CCTimerStart();
  return (bool)uVar1;
}



void PROTIMER_ClearTxEnable(void)

{
  write_volatile_4(PROTIMER->.TXCTRL,0);
  return;
}



void PROTIMER_ScheduleRxEnable(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  PROTIMER_CCTimerStop();
  uVar1 = RADIO_RxWarmTimeGet();
  uVar1 = (uVar1 & 1) + (uVar1 >> 1);
  if ((param_3 == 1) && (param_2 < uVar1)) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_2 - uVar1;
  }
  write_volatile_4(PROTIMER->.RXCTRL,(param_1 + 9) * 0x100 | 0x10001);
  PROTIMER_CCTimerStart(param_1,iVar2,param_3);
  return;
}



void PROTIMER_ScheduleRxDisable(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  PROTIMER_CCTimerStop();
  uVar1 = read_volatile_4(PROTIMER->.RXCTRL);
  write_volatile_4(PROTIMER->.RXCTRL,
                   uVar1 & 0xe0e0ffff | 0x10000 | (param_1 + 9) * 0x1000000);
  PROTIMER_CCTimerStart(param_1,param_2,param_3);
  return;
}



void PROTIMER_ClearRxEnable(void)

{
  write_volatile_4(PROTIMER->.RXCTRL,0x1010000);
  return;
}



uint PROTIMER_GetTime(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(PROTIMER->.WRAPCNT);
  return uVar1;
}



bool PROTIMER_SetTime(uint32_t time)

{
  int iVar1;
  
  iVar1 = PROTIMER_IsRunning();
  if (iVar1 != 0) {
    PROTIMER_Stop();
    iVar1 = 1;
  }
  PROTIMER_Reset();
  write_volatile_4(PROTIMER->.WRAPCNT,(time & 1) + (time >> 1));
  if (iVar1 != 0) {
    PROTIMER_Start();
  }
  return true;
}



uint PROTIMER_GetCCTime(int param_1)

{
  return (&PROTIMER->.CC0_WRAP)[param_1 * 4];
}



void PROTIMER_LBTCfgSet(uint param_1,int param_2,uint param_3,int param_4,byte param_5)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = read_volatile_4(PROTIMER->.CTRL);
  write_volatile_4(PROTIMER->.CTRL,uVar1 & 0xff0fffff | 0x900000);
  if (param_3 == 0) {
    write_volatile_4(PROTIMER->.RXCTRL,0);
    param_1 = param_3;
  }
  write_volatile_4(PROTIMER->.LBTCTRL,
                   (uint)param_5 << 8 | param_4 << 0x18 | param_2 << 4 | param_3 << 0x10 | param_1);
  uVar1 = read_volatile_4(PROTIMER->.BASECNTTOP);
  write_volatile_4(PROTIMER->.TOUT0CNTTOP,uVar1);
  if (param_3 != 0) {
    uVar2 = RADIO_RxWarmTimeGet();
    uVar2 = (uVar2 & 1) + (uVar2 >> 1);
    if (uVar1 < uVar2) {
      uVar2 = 0;
    }
    write_volatile_4(PROTIMER->.TOUT0COMP,uVar2);
    write_volatile_4(PROTIMER->.RXCTRL,0x18011b01);
  }
  write_volatile_4(PROTIMER->.TXCTRL,0x1401);
  return;
}



void PROTIMER_LBTUseLastConfig(void)

{
  write_volatile_4(PROTIMER->.RXCTRL,0x18011b01);
  write_volatile_4(PROTIMER->.TXCTRL,0x1401);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_LBTStart(void)

{
  RADIO_PTI_AuxdataOutput(0x21);
  _DAT_430a00c0 = 1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_LBTStop(void)

{
  RADIO_PTI_AuxdataOutput(0x22);
  _DAT_430a00c8 = 1;
  return;
}



bool PROTIMER_LBTIsActive(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(PROTIMER->.STATUS);
  return (uVar1 & 6) != 0;
}



uint32_t PROTIMER_PrecntOverflowToUs(uint32_t cnt)

{
  return cnt * 2;
}



uint32_t PROTIMER_UsToPrecntOverflow(uint32_t us)

{
  return (us & 1) + (us >> 1);
}



void PROTIMER_DelayUs(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar6 = read_volatile_4(PROTIMER->.WRAPCNT);
  uVar2 = read_volatile_4(PROTIMER->.WRAPCNTTOP);
  iVar3 = PROTIMER_IsRunning();
  if (iVar3 != 0) {
    uVar5 = (param_1 & 1) + (param_1 >> 1);
    while( true ) {
      uVar7 = uVar5;
      if (uVar2 >> 1 <= uVar5) {
        uVar7 = uVar2 >> 1;
      }
      do {
        uVar1 = read_volatile_4(PROTIMER->.WRAPCNT);
        uVar4 = PROTIMER_ElapsedTime(uVar6,uVar1);
      } while (uVar4 < uVar7);
      if (uVar5 <= uVar4) break;
      uVar5 = uVar5 - uVar4;
      uVar6 = uVar1;
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



void RFSENSE_Disable(void)

{
  uint uVar1;
  uint uVar2;
  CORE_irqState_t irqState;
  
  uVar2 = em4Flag;
  RFSENSE_Cb = 0;
  write_volatile_4(Peripherals::RFSENSE.IEN,0);
  write_volatile_4(Peripherals::RFSENSE.EM4WUEN,0);
  write_volatile_4(Peripherals::RFSENSE.CTRL,0);
  write_volatile_4(Peripherals::RFSENSE.PERIODSEL,0xf);
  if (em4Flag != 0) {
    em4Flag = 0;
    irqState = CORE_EnterCritical();
    uVar1 = read_volatile_4(EMU->.EM4CTRL);
    write_volatile_4(EMU->.EM4CTRL,uVar1 & ~uVar2);
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
  write_volatile_4(Peripherals::RFSENSE.IFC,1);
  _DAT_e000e184 = 1;
  _DAT_e000e284 = 1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

bool RFSENSE_Sensed(void)

{
  code *pcVar1;
  int iVar2;
  CORE_irqState_t irqState;
  uint uVar3;
  
  iVar2 = _DAT_43c81904;
  _DAT_43c81904 = 1;
  uVar3 = read_volatile_4(Peripherals::RFSENSE.IF);
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
    _DAT_43c81904 = iVar2;
  }
  return SUB41(uVar3,0);
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

bool RFSENSE_IRQHandler(void)

{
  code *pcVar1;
  int iVar2;
  CORE_irqState_t irqState;
  uint uVar3;
  
  iVar2 = _DAT_43c81904;
  _DAT_43c81904 = 1;
  uVar3 = read_volatile_4(Peripherals::RFSENSE.IF);
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
    _DAT_43c81904 = iVar2;
  }
  return SUB41(uVar3,0);
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RFSENSE_DeInit(void)

{
  RFSENSE_ReInit();
  _DAT_43c81904 = 0;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint RFSENSE_Init(undefined4 *param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  CORE_irqState_t irqState;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  _DAT_43c81904 = 1;
  puVar7 = param_1;
  RFSENSE_ReInit();
  if (param_1 == (undefined4 *)0x0) {
LAB_0000af46:
    RFSENSE_DeInit();
    return 0;
  }
  bVar1 = *(byte *)(param_1 + 2);
  uVar5 = (uint)bVar1;
  if ((((bVar1 & 3) == 0) || (param_1[1] == 0)) ||
     (uVar2 = RFSENSE_CalcPeriod(uVar5,param_1[1],&stack0xffffffe6), uVar2 == 0)) goto LAB_0000af46;
  if (((bVar1 & 0xc) == 0) && (uVar3 = param_1[1], 100000 < uVar3)) {
    if (uVar3 < uVar2) {
      uVar6 = uVar2 - uVar3;
    }
    else {
      uVar6 = uVar3 - uVar2;
    }
    if ((uVar6 != 0) &&
       (uVar3 = RFSENSE_CalcPeriod(0xc,uVar3,&stack0xffffffe7,100000,puVar7,param_2), uVar3 != 0)) {
      uVar4 = param_1[1];
      if (uVar4 < uVar3) {
        uVar4 = uVar3 - uVar4;
      }
      else {
        uVar4 = uVar4 - uVar3;
      }
      if (uVar4 < uVar6) {
        param_2 = (param_2 >> 0x18) << 0x10;
        uVar5 = uVar5 | 0xc;
        uVar2 = uVar3;
      }
    }
  }
  write_volatile_4(Peripherals::RFSENSE.PERIODSEL,param_2 >> 0x10 & 0xff);
  if (*(char *)((int)param_1 + 9) == '\0') goto LAB_0000afe0;
  write_volatile_4(Peripherals::RFSENSE.EM4WUEN,1);
  uVar3 = uVar5 & 0xc;
  if (uVar3 == 8) {
    uVar3 = read_volatile_4(EMU->.EM4CTRL);
    if (-1 < (int)(uVar3 << 0x1d)) {
      uVar3 = 4;
      goto LAB_0000b004;
    }
  }
  else {
    if (uVar3 == 0xc) {
      uVar3 = read_volatile_4(EMU->.EM4CTRL);
      if (-1 < (int)(uVar3 << 0x1c)) {
        uVar3 = 8;
        goto LAB_0000b004;
      }
    }
    else {
      if ((uVar3 == 4) &&
         (uVar3 = read_volatile_4(EMU->.EM4CTRL), -1 < (int)(uVar3 << 0x1e))) {
        uVar3 = 2;
LAB_0000b004:
        irqState = CORE_EnterCritical();
        uVar6 = read_volatile_4(EMU->.EM4CTRL);
        write_volatile_4(EMU->.EM4CTRL,uVar6 | uVar3);
        CORE_ExitCritical(irqState);
        em4Flag = uVar3;
        goto LAB_0000afe0;
      }
    }
  }
  em4Flag = 0;
LAB_0000afe0:
  write_volatile_4(Peripherals::RFSENSE.IEN,1);
  write_volatile_4(Peripherals::RFSENSE.CTRL,uVar5 & 0x2f);
  RFSENSE_Cb = *param_1;
  _DAT_e000e104 = 1;
  return uVar2;
}



void TEMPCAL_Init(void)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  char cVar4;
  
  uVar2 = read_volatile_4(DAT_0fe08204);
  iVar1 = read_volatile_4(DAT_0fe081b0);
  cVar3 = (char)(uVar2 & 0xff);
  if ((uVar2 & 0xff) == 0xff) {
    cVar3 = -0x70;
    cVar4 = '\x19';
  }
  else {
    cVar4 = (char)((uint)(iVar1 << 8) >> 0x18);
    if (cVar4 == -1) {
      cVar3 = -0x70;
      cVar4 = '\x19';
    }
  }
  write_volatile_1(Peripherals::SEQ.REG07C._3_1_,(char)((uint)(int)cVar4 / 2) + cVar3);
  write_volatile_1(Peripherals::SEQ.REG07C._2_1_,2);
  write_volatile_1(Peripherals::SEQ.REG07C._1_1_,0x23);
  return;
}



void TEMPCAL_Perform(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(RAC->.STATUS);
  if ((uVar1 << 4) >> 0x1c == 2) {
    write_volatile_4(RAC->.CMD,0x80);
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

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
  uVar4 = read_volatile_4(CMU->HFRADIOCLKEN0);
  local_24 = __n;
  memset(buffer,0,__n);
  if ((((uVar4 | 0xcc) == uVar4) &&
      (uVar4 = read_volatile_4(RAC->.CTRL), -1 < (int)(uVar4 << 0x1f))) &&
     (uVar4 = RADIOCMU_ClockPrescGet(0x75160), uVar4 == 0)) {
    irqState = CORE_EnterCritical();
    uVar3 = read_volatile_4(MODEM->.CTRL0);
    uVar2 = read_volatile_4(FRC->.RAWCTRL);
    uVar1 = read_volatile_4(MODEM->.CTRL0);
    write_volatile_4(MODEM->.CTRL0,uVar1 & 0xc7ffffff);
    uVar1 = read_volatile_4(MODEM->.CTRL0);
    write_volatile_4(MODEM->.CTRL0,uVar1 | 0x8000000);
    write_volatile_4(FRC->.RAWCTRL,0x24);
    _DAT_43080008 = 1;
    write_volatile_4(FRC->.IFC,0x4000);
    write_volatile_4(FRC->.CMD,0x1000);
    for (; uVar4 < __n; uVar4 = uVar4 + __n_00 & 0xffff) {
      do {
        do {
          uVar1 = read_volatile_4(FRC->.IF);
        } while (-1 < (int)(uVar1 << 0x11));
        uVar1 = read_volatile_4(FRC->.STATUS);
      } while (-1 < (int)(uVar1 << 0x17));
      __n_00 = __n - uVar4;
      write_volatile_4(FRC->.IFC,0x4000);
      if (3 < (int)__n_00) {
        __n_00 = 4;
      }
      local_24 = read_volatile_4(FRC->.RXRAWDATA);
      memcpy(buffer + uVar4,&local_24,__n_00);
    }
    _DAT_43080008 = 0;
    write_volatile_4(FRC->.RAWCTRL,uVar2);
    write_volatile_4(MODEM->.CTRL0,uVar3);
    write_volatile_4(FRC->.IFC,0x4000);
    CORE_ExitCritical(irqState);
  }
  else {
    bytes = 0;
  }
  return bytes;
}



// WARNING: Could not reconcile some variable overlaps

undefined4 RFRAND_SeedProtimerRandom(undefined4 param_1,uint param_2,undefined4 param_3)

{
  uint16_t uVar1;
  undefined4 uVar2;
  undefined4 uStack12;
  undefined4 uStack8;
  
  uStack12 = param_2;
  uStack8 = param_3;
  uVar1 = RFRAND_GetRadioEntropy((uint8_t *)((int)&uStack12 + 2),2);
  if (uVar1 == 2) {
    if (uStack12._2_2_ == -0x7fc) {
      uStack12 = 0xf8050000;
    }
    write_volatile_4(PROTIMER->.RANDOM,uStack12 >> 0x10);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



void GENERIC_PHY_RAC_IRQCallback(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = read_volatile_4(RAC->.IF);
  uVar1 = read_volatile_4(RAC->.IEN);
  uVar1 = uVar1 & uVar2;
  write_volatile_4(RAC->.IFC,uVar1);
  if ((int)(uVar1 << 0x1f) < 0) {
    (**(code **)(currentCallbacks + 0x38))();
  }
  if ((int)(uVar1 << 0x1d) < 0) {
    (**(code **)(currentCallbacks + 0x34))();
  }
  if ((int)(uVar1 << 6) < 0) {
    if (DAT_20002fb1 < '\0') {
      (**(code **)(currentCallbacks + 0x3c))();
    }
    PA_PeakDetectorHighRun();
  }
  if ((int)(uVar1 << 5) < 0) {
    if ((int)((uint)DAT_20002fb2 << 0x1f) < 0) {
      (**(code **)(currentCallbacks + 0x40))();
    }
    PA_PeakDetectorLowRun();
  }
  if ((int)(uVar1 << 4) < 0) {
    if ((int)((uint)DAT_20002fb2 << 0x1e) < 0) {
      (**(code **)(currentCallbacks + 0x44))();
    }
    PA_BatHighRun();
  }
  uVar2 = uVar1 & 0xff0000;
  if (uVar2 != 0) {
    if ((uVar1 & 0x40000) != 0) {
      if ((int)((uint)DAT_20002fb2 << 0x1d) < 0) {
        (**(code **)(currentCallbacks + 0x48))();
      }
      uVar2 = uVar1 & 0xfb0000;
    }
    if ((int)(uVar2 << 0xf) < 0) {
      if ((int)((uint)enabledCallbacks << 0x19) < 0) {
        (**(code **)(currentCallbacks + 0x18))(2);
      }
      uVar2 = uVar2 & 0xfffeffff;
    }
    if (((int)(uVar2 << 0xe) < 0) && ((int)((uint)enabledCallbacks << 0x1e) < 0)) {
      (**(code **)(currentCallbacks + 4))(0x10);
    }
    if ((*(code **)(currentCallbacks + 0x4c) != FUN_00000000) && (uVar2 != 0)) {
                    // WARNING: Could not recover jumptable at 0x0000b276. Too many branches
                    // WARNING: Treating indirect jump as call
      (**(code **)(currentCallbacks + 0x4c))(uVar2);
      return;
    }
  }
  return;
}



void GENERIC_PHY_MODEM_IRQCallback(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = read_volatile_4(MODEM->.IF);
  uVar2 = read_volatile_4(MODEM->.IEN);
  uVar2 = uVar2 & uVar1;
  write_volatile_4(MODEM->.IFC,uVar2);
  if ((int)(uVar2 << 0x12) < 0) {
    (**(code **)(currentCallbacks + 0x24))();
  }
  if ((int)(uVar2 << 0x16) < 0) {
    (**(code **)(currentCallbacks + 0x28))();
  }
  if ((int)(uVar2 << 0x15) < 0) {
    (**(code **)(currentCallbacks + 0x2c))();
  }
  if ((int)(uVar2 << 0x14) < 0) {
                    // WARNING: Could not recover jumptable at 0x0000b2cc. Too many branches
                    // WARNING: Treating indirect jump as call
    (**(code **)(currentCallbacks + 0x30))();
    return;
  }
  return;
}



void GENERIC_PHY_AGC_IRQCallback(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = read_volatile_4(AGC->.IF);
  uVar2 = read_volatile_4(AGC->.IEN);
  write_volatile_4(AGC->.IFC,uVar1 & uVar2);
  if ((int)((uVar1 & uVar2) << 0x1f) < 0) {
                    // WARNING: Could not recover jumptable at 0x0000b2ec. Too many branches
                    // WARNING: Treating indirect jump as call
    (**(code **)(currentCallbacks + 100))();
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
  uVar1 = read_volatile_4(RAC->.STATUS);
  uVar1 = (uVar1 << 4) >> 0x1c;
  bVar2 = uVar1 == 3;
  if (bVar2) {
    param_3 = 0x21000f68;
    uVar1 = read_volatile_4(Peripherals::SEQ.REG070);
    uVar1 = uVar1 & 0xffffff01 | 0xe;
  }
  if (bVar2) {
    *(uint *)(param_3 + 8) = uVar1;
  }
  write_volatile_4(FRC->.CMD,1);
  CORE_ExitCritical(irqState);
  return;
}



void GENERIC_PHY_PROTIMER_IRQCallback(void)

{
  int iVar1;
  CORE_irqState_t irqState;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = PROTIMER_LBTIsActive();
  uVar4 = read_volatile_4(PROTIMER->.IF);
  uVar3 = read_volatile_4(PROTIMER->.IEN);
  uVar3 = uVar3 & uVar4;
  write_volatile_4(PROTIMER->.IFC,uVar3);
  if ((int)(uVar3 << 0x14) < 0) {
    PROTIMER_CCTimerStop(3);
  }
  if ((uVar3 & 0x500000) == 0) {
    if (-1 < (int)(uVar3 << 0x13)) goto LAB_0000b3bc;
    if (iVar1 != 0) goto LAB_0000b35c;
    PROTIMER_CCTimerStop(3);
    PROTIMER_CCTimerStop(4);
    PROTIMER_ClearRxEnable();
    irqState = CORE_EnterCritical();
    if (scheduledRxHardEnd != '\0') {
      RADIO_RACRxAbort();
    }
    uVar4 = read_volatile_4(RAC->.STATUS);
    if (((uVar4 << 4) >> 0x1c == 3) ||
       (uVar4 = read_volatile_4(FRC->.IF), uVar4 = uVar4 & 0x10, uVar4 != 0)) {
      uVar4 = 1;
      pendedRxWindowEnd = 1;
    }
    CORE_ExitCritical(irqState);
    if ((uVar4 != 0) || (-1 < (int)((uint)enabledCallbacks << 0x19))) goto LAB_0000b3bc;
    pcVar2 = *(code **)(currentCallbacks + 0x18);
    uVar4 = 1;
  }
  else {
LAB_0000b35c:
    pcVar2 = *(code **)(currentCallbacks + 0x54);
    uVar4 = uVar3;
  }
  (*pcVar2)(uVar4);
LAB_0000b3bc:
  if ((int)(uVar3 << 10) < 0) {
    (**(code **)(currentCallbacks + 0x58))();
  }
  if ((int)(uVar3 << 6) < 0) {
    (**(code **)(currentCallbacks + 0x5c))();
  }
  if ((int)(uVar3 << 0x15) < 0) {
                    // WARNING: Could not recover jumptable at 0x0000b3e2. Too many branches
                    // WARNING: Treating indirect jump as call
    (**(code **)(currentCallbacks + 0x60))();
    return;
  }
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
      puVar11 = &Peripherals::SEQ.REG010;
      bVar2 = read_volatile_1(Peripherals::SEQ.REG058._0_1_);
      uVar4 = 1 << (uVar8 & 0xff) | 1 << (uVar3 & 0xff);
      if ((uVar4 & bVar2) == uVar4) {
        bVar2 = read_volatile_1(Peripherals::SEQ.REG054._2_1_);
        for (iVar10 = 0; iVar10 < (int)(uint)bVar2; iVar10 = iVar10 + 1) {
          puVar11 = puVar11 + 1;
          if (((*puVar11 >> (uVar9 & 0xff) ^ *puVar11 >> (uVar5 & 0xff)) & 0xff) != 0)
          goto LAB_0000b492;
        }
        uVar12 = uVar12 | addressFilterMatchTable >> (local_38 & 0xff) & 0x1f;
      }
LAB_0000b492:
      bVar2 = read_volatile_1(Peripherals::SEQ.REG058._1_1_);
      if ((uVar4 & bVar2) == uVar4) {
        bVar2 = read_volatile_1(Peripherals::SEQ.REG054._3_1_);
        puVar11 = &Peripherals::SEQ.REG030;
        for (iVar10 = 0; iVar10 < (int)(uint)bVar2; iVar10 = iVar10 + 1) {
          puVar11 = puVar11 + 1;
          if (((*puVar11 >> (uVar9 & 0xff) ^ *puVar11 >> (uVar5 & 0xff)) & 0xff) != 0)
          goto LAB_0000b4da;
        }
        uVar7 = uVar7 | addressFilterMatchTable >> (uVar8 + 1 & 0xff) & 0x108421;
      }
LAB_0000b4da:
      uVar9 = uVar9 + 8;
    }
    local_34 = local_34 | uVar7 << (uVar6 & 0xff) | uVar12 << (uVar1 & 0xff);
    uVar5 = uVar5 + 8;
    uVar3 = uVar6;
    if (uVar6 == 4) {
      write_volatile_4(Peripherals::SEQ.REG010,local_34);
      return;
    }
  } while( true );
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void GENERIC_PHY_ConfigureCallbacks(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  _enabledCallbacks = param_1 & availableCallbacks;
  uVar4 = 0x161;
  if ((_enabledCallbacks & 1) != 0) {
    uVar4 = 0x163;
  }
  if ((int)(_enabledCallbacks << 0x1e) < 0) {
    uVar4 = uVar4 | 0xc;
  }
  if ((int)(_enabledCallbacks << 0x1d) < 0) {
    uVar4 = uVar4 | 0x10;
  }
  if ((int)(_enabledCallbacks << 0x18) < 0) {
    uVar4 = uVar4 | 0x4000;
  }
  uVar1 = read_volatile_4(FRC->.IEN);
  if ((int)(_enabledCallbacks << 0x17) < 0) {
    uVar4 = uVar4 | 0x2000;
  }
  uVar3 = uVar1 & (uVar4 ^ uVar1);
  write_volatile_4(FRC->.IFC,uVar3);
  uVar2 = read_volatile_4(FRC->.IEN);
  uVar4 = uVar4 & (uVar4 ^ uVar1);
  write_volatile_4(FRC->.IEN,uVar2 & ~uVar3);
  write_volatile_4(FRC->.IFC,uVar4);
  uVar1 = read_volatile_4(FRC->.IEN);
  write_volatile_4(FRC->.IEN,uVar4 | uVar1);
  if ((_enabledCallbacks & 0x200) == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0x2000;
  }
  if ((int)(_enabledCallbacks << 0x15) < 0) {
    uVar4 = uVar4 | 0x200;
  }
  uVar1 = read_volatile_4(MODEM->.IEN);
  if ((int)(_enabledCallbacks << 0x14) < 0) {
    uVar4 = uVar4 | 0x400;
  }
  if ((int)(_enabledCallbacks << 0x13) < 0) {
    uVar4 = uVar4 | 0x800;
  }
  uVar3 = uVar1 & (uVar4 ^ uVar1);
  write_volatile_4(MODEM->.IFC,uVar3);
  uVar2 = read_volatile_4(MODEM->.IEN);
  uVar4 = uVar4 & (uVar4 ^ uVar1);
  write_volatile_4(MODEM->.IEN,uVar2 & ~uVar3);
  write_volatile_4(MODEM->.IFC,uVar4);
  uVar1 = read_volatile_4(MODEM->.IEN);
  write_volatile_4(MODEM->.IEN,uVar4 | uVar1);
  if ((_enabledCallbacks & 0x2000) == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = 4;
  }
  if ((int)(_enabledCallbacks << 0x11) < 0) {
    uVar4 = uVar4 | 1;
  }
  if ((int)(_enabledCallbacks << 0xd) < 0) {
    uVar4 = uVar4 | 0x40000;
  }
  if ((int)(_enabledCallbacks << 0x1e) < 0) {
    uVar4 = uVar4 | 0x20000;
  }
  uVar1 = read_volatile_4(RAC->.IEN);
  if ((int)(_enabledCallbacks << 0xc) < 0) {
    uVar4 = uVar4 | 0xff0000;
  }
  if ((int)(_enabledCallbacks << 0x19) < 0) {
    uVar4 = uVar4 | 0x10000;
  }
  uVar3 = uVar1 & (uVar4 ^ uVar1);
  write_volatile_4(RAC->.IFC,uVar3);
  uVar2 = read_volatile_4(RAC->.IEN);
  uVar4 = uVar4 & (uVar4 ^ uVar1);
  write_volatile_4(RAC->.IEN,uVar2 & ~uVar3);
  write_volatile_4(RAC->.IFC,uVar4);
  uVar1 = read_volatile_4(RAC->.IEN);
  write_volatile_4(RAC->.IEN,uVar4 | uVar1);
  uVar4 = 0x501800;
  if ((_enabledCallbacks & 0x200000) == 0) {
    uVar4 = 0x1800;
  }
  if ((int)(_enabledCallbacks << 9) < 0) {
    uVar4 = uVar4 | 0x200000;
  }
  if ((int)(_enabledCallbacks << 8) < 0) {
    uVar4 = uVar4 | 0x2000000;
  }
  uVar1 = read_volatile_4(PROTIMER->.IEN);
  if ((int)(_enabledCallbacks << 7) < 0) {
    uVar4 = uVar4 | 0x400;
  }
  uVar3 = uVar1 & (uVar4 ^ uVar1);
  write_volatile_4(PROTIMER->.IFC,uVar3);
  uVar2 = read_volatile_4(PROTIMER->.IEN);
  uVar4 = uVar4 & (uVar4 ^ uVar1);
  write_volatile_4(PROTIMER->.IEN,uVar2 & ~uVar3);
  write_volatile_4(PROTIMER->.IFC,uVar4);
  uVar1 = read_volatile_4(PROTIMER->.IEN);
  write_volatile_4(PROTIMER->.IEN,uVar4 | uVar1);
  uVar4 = read_volatile_4(AGC->.IEN);
  uVar2 = (_enabledCallbacks << 6) >> 0x1f;
  uVar3 = uVar2 ^ uVar4;
  uVar4 = uVar4 & uVar3;
  write_volatile_4(AGC->.IFC,uVar4);
  uVar1 = read_volatile_4(AGC->.IEN);
  uVar2 = uVar2 & uVar3;
  write_volatile_4(AGC->.IEN,uVar1 & ~uVar4);
  write_volatile_4(AGC->.IFC,uVar2);
  uVar4 = read_volatile_4(AGC->.IEN);
  write_volatile_4(AGC->.IEN,uVar2 | uVar4);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void GENERIC_PHY_SetCallbacks(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  _DAT_e000e280 = 0x8000000;
  _DAT_e000e180 = 0x8000000;
  uVar2 = 0;
  availableCallbacks = 0;
  if (param_1 != 0) {
    uVar1 = 0;
    do {
      if (*(int *)(param_1 + uVar1 * 4) != 0) {
        uVar2 = uVar2 | 1 << (uVar1 & 0xff);
      }
      uVar1 = uVar1 + 1;
      availableCallbacks = uVar2;
    } while (uVar1 != 0x1a);
  }
  currentCallbacks = param_1;
  GENERIC_PHY_ConfigureCallbacks(0xffffffff);
  _DAT_e000e100 = 0x8000000;
  _DAT_e000e280 = 0x8000000;
  return;
}



void GENERIC_PHY_FlushTxPacketBuffer(void)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  RADIO_TxBufferReset();
  CORE_ExitCritical(irqState);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void GENERIC_PHY_PacketTxCommon(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = read_volatile_4(FRC->.DFLCTRL);
  if (((uVar1 & 7) == 0) && (uVar1 = read_volatile_4(Peripherals::SEQ.REG060), uVar1 != 0)) {
    iVar2 = RADIO_TxBufferBytesAvailable();
    write_volatile_4(FRC->.WCNTCMP0,iVar2 - 1);
  }
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 & 0xffffffbf);
  _DAT_4308111c = 1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 GENERIC_PHY_PacketTx(void)

{
  CORE_irqState_t irqState;
  int iVar1;
  
  irqState = CORE_EnterCritical();
  iVar1 = PROTIMER_CCTimerIsEnabled(3);
  if ((iVar1 == 0) && (iVar1 = PROTIMER_LBTIsActive(), iVar1 == 0)) {
    GENERIC_PHY_PacketTxCommon();
    _DAT_43080100 = 1;
    CORE_ExitCritical(irqState);
    return 0;
  }
  CORE_ExitCritical(irqState);
  return 1;
}



undefined4
GENERIC_PHY_SchedulePacketRx
          (undefined4 param_1,int param_2,int param_3,int param_4,char param_5,undefined param_6)

{
  CORE_irqState_t irqState;
  int iVar1;
  uint32_t uVar2;
  uint uVar3;
  
  irqState = CORE_EnterCritical();
  if (param_2 != 2) {
    iVar1 = PROTIMER_CCTimerIsEnabled(3);
    if (iVar1 != 0) {
      CORE_ExitCritical(irqState);
      return 1;
    }
    PROTIMER_ClearRxEnable();
    PROTIMER_ClearTxEnable();
    if (param_5 == '\0') {
      uVar3 = read_volatile_4(Peripherals::SEQ.REG000);
      uVar3 = uVar3 & 0xffffffbf;
    }
    else {
      uVar3 = read_volatile_4(Peripherals::SEQ.REG000);
      uVar3 = uVar3 | 0x40;
    }
    write_volatile_4(Peripherals::SEQ.REG000,uVar3);
    iVar1 = PROTIMER_ScheduleRxEnable(3,param_1,param_2);
    if (iVar1 == 0) {
      CORE_ExitCritical(irqState);
      return 2;
    }
  }
  if (param_4 != 2) {
    iVar1 = PROTIMER_CCTimerIsEnabled(3);
    if ((iVar1 == 0) &&
       (uVar3 = read_volatile_4(RAC->.STATUS), -1 < (int)(uVar3 << 0x11))) {
      CORE_ExitCritical(irqState);
      return 4;
    }
    scheduledRxHardEnd = param_6;
    if ((param_4 == 1) && (param_2 != 2)) {
      iVar1 = PROTIMER_GetCCTime(3);
      uVar2 = RADIO_RxWarmTimeGet();
      uVar2 = PROTIMER_UsToPrecntOverflow(uVar2);
      param_3 = param_3 + uVar2 + iVar1;
      param_4 = 0;
    }
    pendedRxWindowEnd = 0;
    iVar1 = PROTIMER_ScheduleRxDisable(4,param_3,param_4);
    if (iVar1 == 0) {
      PROTIMER_CCTimerStop(3);
      PROTIMER_ClearRxEnable();
      CORE_ExitCritical(irqState);
      return 3;
    }
  }
  CORE_ExitCritical(irqState);
  return 0;
}



RAIL_Status_t GENERIC_PHY_SchedulePacketTx(uint32_t when,RAIL_TimeMode_t mode)

{
  bool bVar1;
  CORE_irqState_t irqState;
  int iVar2;
  
  irqState = CORE_EnterCritical();
  iVar2 = PROTIMER_CCTimerIsEnabled(3);
  if ((iVar2 == 0) && (iVar2 = PROTIMER_LBTIsActive(), iVar2 == 0)) {
    GENERIC_PHY_PacketTxCommon();
    PROTIMER_ClearRxEnable();
    PROTIMER_ClearTxEnable();
    bVar1 = PROTIMER_ScheduleTxEnable();
    if (bVar1 == false) {
      CORE_ExitCritical(irqState);
      return RAIL_STATUS_INVALID_STATE;
    }
    CORE_ExitCritical(irqState);
    return RAIL_STATUS_NO_ERROR;
  }
  CORE_ExitCritical(irqState);
  return RAIL_STATUS_INVALID_PARAMETER;
}



uint GENERIC_PHY_PacketRxDataHelper(int param_1,uint param_2)

{
  RADIO_RxBufferBytesAvailable();
  if (param_1 == 0) {
    RADIO_RxBufferDropBytes(param_2);
  }
  else {
    RADIO_RxBufferReadBytes(param_1,param_2 & 0xff);
  }
  return param_2;
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
  
  uVar1 = read_volatile_4(FRC->.TRAILRXDATA);
  apvStack28[0] = param_2;
  apvStack28[1] = (void *)param_3;
  apvStack28[2] = (void *)param_4;
  if (param_2 == (void *)0x0) {
    RADIO_RxBufferDropBytes();
  }
  else {
    RADIO_RxBufferReadBytes(apvStack28,param_1 & 0xff,param_3,&FRC->,param_1);
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



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void GENERIC_PHY_StartRx(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 != 0) {
    write_volatile_4(FRC->.WCNTCMP0,param_1 - 1);
  }
  iVar2 = RADIO_RxBufferGet();
  if ((iVar2 == 0) && (*(code **)(currentCallbacks + 0x50) != FUN_00000000)) {
    (**(code **)(currentCallbacks + 0x50))();
    RADIO_RxBufferSet();
  }
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 & 0xffffffbf);
  _DAT_43080004 = 1;
  return;
}



void GENERIC_PHY_ChannelSet(undefined4 param_1)

{
  SYNTH_ChannelSet(param_1,1);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void GENERIC_PHY_SeqAtomicLock(void)

{
  uint uVar1;
  
  read_volatile(RAC->.SR0._0_1_);
  while (uVar1 = read_volatile_4(RAC->.SR0), (int)(uVar1 << 0xd) < 0) {
    _DAT_43081108 = 0;
    PROTIMER_DelayUs(2);
  }
  _DAT_43081108 = 1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void GENERIC_PHY_RadioIdle(int param_1,int param_2)

{
  uint uVar1;
  CORE_irqState_t CVar2;
  int iVar3;
  
  if ((param_1 != 0) || (param_2 != 0)) {
    CVar2 = CORE_EnterCritical();
    do {
      uVar1 = read_volatile_4(RAC->.STATUS);
      if ((uVar1 << 4) >> 0x1c != 3) break;
      uVar1 = read_volatile_4(Peripherals::SEQ.REG068);
    } while ((uVar1 & 0xf) != 3);
    if (param_2 != 0) {
      GENERIC_PHY_SeqAtomicLock();
      uVar1 = read_volatile_4(RAC->.CTRL);
      if (-1 < (int)(uVar1 << 0x1f)) {
        uRam43080180 = 1;
      }
      _DAT_43081108 = 0;
      do {
        uVar1 = read_volatile_4(RAC->.STATUS);
      } while ((uVar1 & 0xf000000) != 0);
    }
    CORE_ExitCritical(CVar2);
  }
  _DAT_4308111c = 0;
  iVar3 = PROTIMER_CCTimerIsEnabled(3);
  if (iVar3 != 0) {
    PROTIMER_CCTimerStop(3);
    PROTIMER_CCTimerStop(4);
  }
  PROTIMER_ClearRxEnable();
  PROTIMER_ClearTxEnable();
  CVar2 = CORE_EnterCritical();
  GENERIC_PHY_SeqAtomicLock();
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 | 0x40);
  uVar1 = read_volatile_4(RAC->.RXENSRCEN);
  write_volatile_4(RAC->.RXENSRCEN,uVar1 & 0xffffff00);
  write_volatile_4(RAC->.CMD,0x100);
  _DAT_43081108 = 0;
  CORE_ExitCritical(CVar2);
  if (param_1 != 0) {
    RADIO_RACRxAbort();
    _DAT_43080114 = 1;
    PROTIMER_LBTStop();
    PROTIMER_CCTimerStop(4);
  }
  if (param_2 != 0) {
    RADIO_RxBufferReset();
    uVar1 = read_volatile_4(RAC->.CTRL);
    if ((int)(uVar1 << 0x1f) < 0) {
      uRam43080180 = 0;
    }
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void GENERIC_PHY_FRC_IRQCallback(void)

{
  CORE_irqState_t irqState;
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  irqState = CORE_EnterCritical();
  GENERIC_PHY_SeqAtomicLock();
  uVar3 = read_volatile_4(FRC->.IF);
  uVar2 = read_volatile_4(Peripherals::SEQ.REG06C);
  write_volatile_4(Peripherals::SEQ.REG06C,uVar2 | uVar3);
  _DAT_43081108 = 0;
  CORE_ExitCritical(irqState);
  uVar2 = read_volatile_4(FRC->.IEN);
  uVar3 = uVar3 & uVar2;
  write_volatile_4(FRC->.IFC,uVar3);
  if ((int)(uVar3 << 0x1b) < 0) {
    (*currentCallbacks[2])();
    iVar1 = RADIO_RxBufferPacketAvailable();
    if (iVar1 == 0) goto LAB_0000bbc2;
    uVar2 = 0x10;
  }
  else {
    if (-1 < (int)(uVar3 << 0x19)) goto LAB_0000bbc2;
    uVar2 = read_volatile_4(FRC->.IF);
    if ((-1 < (int)(uVar2 << 0x1b)) ||
       (uVar2 = read_volatile_4(FRC->.RXCTRL), -1 < (int)(uVar2 << 0x1e))) {
      if ((int)((uint)enabledCallbacks << 0x1c) < 0) {
        (*currentCallbacks[3])();
      }
      goto LAB_0000bbc2;
    }
    uVar2 = 0x40;
  }
  write_volatile_4(FRC->.IFS,uVar2);
LAB_0000bbc2:
  if (((uVar3 & 3) != 0) && ((int)((uint)enabledCallbacks << 0x1f) < 0)) {
    (**currentCallbacks)();
  }
  if (((int)(uVar3 << 0x17) < 0) &&
     (uVar2 = read_volatile_4(RAC->.STATUS), (uVar2 & 0xf000000) == 0x6000000)) {
    if ((int)((uint)enabledCallbacks << 0x1b) < 0) {
      (*currentCallbacks[4])();
    }
    uVar2 = read_volatile_4(FRC->.IF);
    if ((int)(uVar2 << 0x1b) < 0) {
      uVar2 = read_volatile_4(FRC->.IFS);
      write_volatile_4(FRC->.IFS,uVar2 | 0x100);
    }
    else {
      RADIO_FRCErrorHandle();
      uVar2 = read_volatile_4(RAC->.SR0);
      if (-1 < (int)(uVar2 << 0x18)) {
        _DAT_4308010c = 1;
        _DAT_43080004 = read_volatile_4(Peripherals::SEQ.REG00C);
        _DAT_43080004 = _DAT_43080004 & 0x200;
        if (_DAT_43080004 != 0) {
          _DAT_43080004 = 1;
        }
      }
      _DAT_43080118 = 1;
    }
  }
  if (((int)(uVar3 << 0x1d) < 0) &&
     (uVar2 = read_volatile_4(FRC->.CTRL), -1 < (int)(uVar2 << 0x1f))) {
    (*currentCallbacks[1])(8);
  }
  if ((int)(uVar3 << 0x1c) < 0) {
    (*currentCallbacks[1])(2);
  }
  if ((int)(uVar3 << 0x11) < 0) {
    (*currentCallbacks[7])();
  }
  if ((int)(uVar3 << 0x12) < 0) {
    (*currentCallbacks[8])();
  }
  if (((pendedRxWindowEnd != '\0') &&
      (uVar2 = read_volatile_4(FRC->.IF), (uVar2 & 0x10) == 0)) &&
     (pendedRxWindowEnd = '\0', (int)((uint)enabledCallbacks << 0x19) < 0)) {
    (*currentCallbacks[6])(1);
  }
  if ((int)(uVar3 << 0x1a) < 0) {
                    // WARNING: Could not recover jumptable at 0x0000bca2. Too many branches
                    // WARNING: Treating indirect jump as call
    (*currentCallbacks[5])();
    return;
  }
  return;
}



void GENERIC_PHY_PreviousTxTime(void)

{
  PROTIMER_GetCCTime(1);
  return;
}



void GENERIC_PHY_RACConfig(void)

{
  RADIO_SeqInit(&genericSeqProg,0x3af);
  memset(&Peripherals::SEQ,0,0x68);
  write_volatile_4(RAC->.SR0,0);
  write_volatile_4(RAC->.SR1,0);
  write_volatile_4(RAC->.SR2,0);
  TEMPCAL_Init();
  RADIO_RxSearchTimeSet(0);
  RADIO_TxToRxSearchTimeSet(0);
  RADIO_RxWarmTimeSet(100);
  RADIO_TxToRxTimeSet(100);
  RADIO_TxToTxTimeSet(100);
  RADIO_RxToTxTimeSet(100);
  RADIO_RxFrameToTxTimeSet(100);
  RADIO_TxWarmTimeSet(100);
  return;
}



void GENERIC_PHY_DirectModeConfig(byte *param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (param_1 != (byte *)0x0) {
    RADIOCMU_ClockEnable(0x67400,1);
    CMU_ClockEnable(cmuClock_GPIO,true);
    uVar2 = (uint)*param_1;
    uVar1 = read_volatile_4(MODEM->.CTRL2);
    write_volatile_4(MODEM->.CTRL2,uVar1 & 0xfffff3ff);
    if (uVar2 == 0) {
      uVar1 = read_volatile_4(MODEM->.CTRL2);
      write_volatile_4(MODEM->.CTRL2,uVar1);
    }
    else {
      uVar2 = (uint)param_1[4];
      uVar1 = read_volatile_4(MODEM->.CTRL2);
      if (uVar2 == 0) {
        write_volatile_4(MODEM->.CTRL2,uVar1 | 0x800);
      }
      else {
        write_volatile_4(MODEM->.CTRL2,uVar1 | 0xc00);
        uVar2 = 4;
      }
      uVar2 = uVar2 | 1;
    }
    if (param_1[1] != 0) {
      uVar1 = read_volatile_4(MODEM->.CTRL2);
      write_volatile_4(MODEM->.CTRL2,uVar1 & 0xfffffdff);
      if (param_1[3] == 0) {
        uVar1 = read_volatile_4(MODEM->.CTRL2);
        write_volatile_4(MODEM->.CTRL2,uVar1 | 0x200);
      }
      else {
        uVar1 = read_volatile_4(MODEM->.CTRL2);
        write_volatile_4(MODEM->.CTRL2,uVar1);
        uVar2 = uVar2 | 4;
      }
      uVar2 = uVar2 | 2;
    }
    uVar1 = read_volatile_4(MODEM->.CTRL2);
    write_volatile_4(MODEM->.CTRL2,uVar1 & 0xfffffeff);
    if (param_1[2] != 0) {
      uVar1 = read_volatile_4(MODEM->.CTRL2);
      write_volatile_4(MODEM->.CTRL2,uVar1 | 0x100);
    }
    write_volatile_4(MODEM->.ROUTELOC0,
                     (uint)param_1[0xb] | (uint)param_1[8] << 0x10 | (uint)param_1[5] << 8);
    uVar1 = read_volatile_4(MODEM->.ROUTEPEN);
    write_volatile_4(MODEM->.ROUTEPEN,uVar1 & 0xfffffff8);
    uVar1 = read_volatile_4(MODEM->.ROUTEPEN);
    write_volatile_4(MODEM->.ROUTEPEN,uVar1 | uVar2);
    if ((int)(uVar2 << 0x1f) < 0) {
      GPIO_PinModeSet(param_1[0xc],(uint)param_1[0xd],gpioModeInput,0);
    }
    if ((int)(uVar2 << 0x1e) < 0) {
      GPIO_PinModeSet(param_1[6],(uint)param_1[7],gpioModePushPull,0);
    }
    if ((int)(uVar2 << 0x1d) < 0) {
      GPIO_PinModeSet(param_1[9],(uint)param_1[10],gpioModePushPull,0);
      return;
    }
  }
  return;
}



void GENERIC_PHY_ResetPacketConfig(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 & 0xfffffff8);
  uVar1 = read_volatile_4(FRC->.DFLCTRL);
  write_volatile_4(FRC->.DFLCTRL,uVar1 & 0xfffffff8);
  uVar1 = read_volatile_4(FRC->.DFLCTRL);
  write_volatile_4(FRC->.DFLCTRL,uVar1);
  return;
}



void GENERIC_PHY_ConfigureFrameType(RAIL_FrameType_t *frameType)

{
  char cVar1;
  uint uVar2;
  
  GENERIC_PHY_ResetPacketConfig();
  if (frameType == (RAIL_FrameType_t *)0x0) {
    memset(&Peripherals::SEQ.REG05C,0,0xc);
    return;
  }
  write_volatile_1(Peripherals::SEQ.REG05C._0_1_,frameType->offset);
  write_volatile_1(Peripherals::SEQ.REG05C._1_1_,frameType->mask);
  write_volatile_1(Peripherals::SEQ.REG05C._2_1_,0);
  write_volatile_4(Peripherals::SEQ.REG060,(uint)frameType->frameLen);
  write_volatile_4(Peripherals::SEQ.REG064,(uint)frameType->isValid);
  uVar2 = (uint)frameType->mask;
  if (uVar2 != 0) {
    while (-1 < (int)(uVar2 << 0x1f)) {
      cVar1 = read_volatile_1(Peripherals::SEQ.REG05C._2_1_);
      uVar2 = uVar2 >> 1;
      write_volatile_1(Peripherals::SEQ.REG05C._2_1_,cVar1 + '\x01');
    }
  }
  write_volatile_4(FRC->.WCNTCMP0,frameType->offset + 1);
  uVar2 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar2 | 7);
  return;
}



bool GENERIC_PHY_EnableAddressFiltering(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 | 0x10);
  return SUB41((uVar1 << 0x1b) >> 0x1f,0);
}



bool GENERIC_PHY_DisableAddressFiltering(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 & 0xffffffef);
  return SUB41((uVar1 << 0x1b) >> 0x1f,0);
}



bool GENERIC_PHY_IsEnabledAddressFiltering(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  return SUB41((uVar1 << 0x1b) >> 0x1f,0);
}



void GENERIC_PHY_ResetAddressFiltering(void)

{
  memset(&Peripherals::SEQ.REG010,0,0x4c);
  addressFilterMatchTable = 0;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void GENERIC_PHY_Init(void)

{
  uint uVar1;
  
  RADIO_Init();
  _DAT_e000e280 = 0x40000000;
  _DAT_e000e180 = 0x40000000;
  GENERIC_PHY_RACConfig();
  write_volatile_4(FRC->.TRAILRXDATA,0x1b);
  write_volatile_4(FRC->.RXCTRL,0x60);
  RADIO_PTI_Enable();
  uVar1 = read_volatile_4(RAC->.CTRL);
  if ((int)(uVar1 << 0x1f) < 0) {
    uRam43080180 = 0;
  }
  RADIO_RegisterIrqCallback(1,0xbb5d);
  RADIO_RegisterIrqCallback(2,0xb289);
  RADIO_RegisterIrqCallback(5,0xb1b1);
  RADIO_RegisterIrqCallback(7,0xb335);
  RADIO_RegisterIrqCallback(9,0xb2d9);
  GENERIC_PHY_ResetAddressFiltering();
  PROTIMER_Init();
  PROTIMER_Start();
  PROTIMER_CCTimerCapture(0,0xc00000);
  PROTIMER_CCTimerCapture(1,0x200000);
  RFRAND_SeedProtimerRandom();
  return;
}



undefined4 GENERIC_PHY_ConfigureAddressFiltering(undefined *param_1)

{
  GENERIC_PHY_ResetAddressFiltering();
  if (param_1 == (undefined *)0x0) {
    return 1;
  }
  write_volatile_1(Peripherals::SEQ.REG054._0_1_,*param_1);
  if ((byte)param_1[2] < 9) {
    write_volatile_1(Peripherals::SEQ.REG054._2_1_,param_1[2]);
    write_volatile_1(Peripherals::SEQ.REG054._1_1_,param_1[1]);
    if ((byte)param_1[3] < 9) {
      write_volatile_1(Peripherals::SEQ.REG054._3_1_,param_1[3]);
      write_volatile_1(Peripherals::SEQ.REG058._2_1_,param_1[8]);
      addressFilterMatchTable = *(undefined4 *)(param_1 + 4);
      GENERIC_PHY_SetAddressFilteringMatchTable();
      return 1;
    }
  }
  return 0;
}



bool GENERIC_PHY_EnableAddress(uint8_t field,uint8_t index)

{
  uint uVar1;
  
  uVar1 = (uint)field;
  if ((uVar1 < 2) && (index < 4)) {
    *(byte *)((int)&Peripherals::SEQ.REG058 + uVar1) =
         (byte)(1 << (uint)index) | *(byte *)((int)&Peripherals::SEQ.REG058 + uVar1);
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
    *(byte *)((int)&Peripherals::SEQ.REG058 + uVar1) =
         *(byte *)((int)&Peripherals::SEQ.REG058 + uVar1) & ~(byte)(1 << (uint)index);
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
      bVar1 = read_volatile_1(Peripherals::SEQ.REG058._0_1_);
      write_volatile_1(Peripherals::SEQ.REG058._0_1_,(byte)(1 << (param_1 & 0xff)) | bVar1);
    }
    else {
      iVar2 = 0;
    }
  }
  return iVar2;
}



int GENERIC_PHY_SetIeeeShortAddress(uint param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = GENERIC_PHY_SetAddressData(1,0,param_1,2,4,param_2);
  if (iVar2 != 0) {
    if (param_1 < 4) {
      bVar1 = read_volatile_1(Peripherals::SEQ.REG058._1_1_);
      write_volatile_1(Peripherals::SEQ.REG058._1_1_,(byte)(1 << (param_1 & 0xff)) | bVar1);
    }
    else {
      iVar2 = 0;
    }
  }
  return iVar2;
}



int GENERIC_PHY_SetIeeeLongAddress(uint param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = GENERIC_PHY_SetAddressData(1,1,param_1,0,8,param_2);
  if (iVar2 != 0) {
    if (param_1 < 4) {
      bVar1 = read_volatile_1(Peripherals::SEQ.REG058._1_1_);
      write_volatile_1(Peripherals::SEQ.REG058._1_1_,(byte)(1 << (param_1 & 0xff)) | bVar1);
    }
    else {
      iVar2 = 0;
    }
  }
  return iVar2;
}



bool GENERIC_PHY_SetAddress(uint8_t field,uint8_t index,uint8_t *value,bool enable)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (uint)field;
  iVar3 = GENERIC_PHY_SetAddressData
                    (uVar2,uVar2,index,0,*(undefined *)((int)&Peripherals::SEQ.REG054 + uVar2 + 2),
                     value);
  if ((enable != false) && (iVar3 != 0)) {
    bVar1 = GENERIC_PHY_EnableAddress(field,index);
    return bVar1;
  }
  return SUB41(iVar3,0);
}



uint GENERIC_PHY_EnableIEEE802154(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 | 0x80);
  return (uVar1 << 0x18) >> 0x1f;
}



uint GENERIC_PHY_IsEnabledIEEE802154(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  return (uVar1 << 0x18) >> 0x1f;
}



void GENERIC_PHY_TimerStart(undefined4 param_1,undefined4 param_2)

{
  PROTIMER_CCTimerStart(2,param_1,param_2);
  return;
}



void GENERIC_PHY_TimerStop(void)

{
  PROTIMER_CCTimerStop(2);
  return;
}



void GENERIC_PHY_TimerGetTimeout(void)

{
  PROTIMER_GetCCTime(2);
  return;
}



uint GENERIC_PHY_TimerExpired(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(PROTIMER->.IF);
  return (uVar1 << 0x15) >> 0x1f;
}



void GENERIC_PHY_TimerIsRunning(void)

{
  PROTIMER_CCTimerIsEnabled(2);
  return;
}



bool GENERIC_PHY_CanModifyAck(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(RAC->.STATUS);
  uVar1 = (uVar1 << 4) >> 0x1c;
  if (1 < uVar1 - 2) {
    return uVar1 == 7;
  }
  return true;
}



uint RFHAL_802154SetPhyforChan(uint param_1)

{
  byte bVar1;
  undefined1 *radioConfig;
  
  if (param_1 == 0xd) {
    radioConfig = &ieee802154_config_2415MHz_min;
  }
  else {
    radioConfig = &ieee802154_config_base_min;
    if (param_1 == 0xe) {
      radioConfig = &ieee802154_config_2420MHz_min;
    }
  }
  if (radioConfig != prevRadioCfg) {
    bVar1 = RAIL_RadioConfig(&ieee802154_config_base_min);
    param_1 = (uint)bVar1;
    if (radioConfig != &ieee802154_config_base_min) {
      bVar1 = RAIL_RadioConfig(radioConfig);
      param_1 = (uint)bVar1;
    }
  }
  prevRadioCfg = radioConfig;
  return param_1;
}



uint RFHAL_IEEE802154Enable(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 | 0x80);
  return (uVar1 << 0x18) >> 0x1f;
}



uint RFHAL_IEEE802154IsEnabled(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  return (uVar1 << 0x18) >> 0x1f;
}



undefined4 RFHAL_IEEE802154RadioConfig2p4GHz(void)

{
  RAIL_RadioConfig(&ieee802154_config_base);
  RFHAL_SetProtocolSpecificChCheckCB(0xc249);
  prevRadioCfg = &ieee802154_config_base_min;
  return 0;
}



byte RFHAL_IEEE802154SetBroadcastAddresses(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  byte bVar2;
  undefined4 local_c;
  
  local_c = CONCAT22((short)((uint)param_2 >> 0x10),0xffff);
  bVar1 = GENERIC_PHY_SetIeeePanId(0,&local_c,param_3,0xffff,param_1);
  bVar2 = GENERIC_PHY_SetIeeeShortAddress(0,&local_c);
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
  undefined uVar1;
  uint in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  uint local_c [3];
  
  local_c[0] = in_r1 & 0xffff0000 | (uint)shortAddr;
  uVar1 = GENERIC_PHY_SetIeeeShortAddress(1,local_c,in_r2,in_r3,shortAddr);
  return (bool)uVar1;
}



void RFHAL_IEEE802154SetLongAddress(undefined4 param_1)

{
  GENERIC_PHY_SetIeeeLongAddress(1,param_1);
  return;
}



undefined4 RFHAL_IEEE802154SetPromiscuousMode(int param_1)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  if (param_1 == 0) {
    uVar1 = uVar1 & 0xfffeffff;
  }
  else {
    uVar1 = uVar1 | 0x10000;
  }
  write_volatile_4(Peripherals::SEQ.REG000,uVar1);
  return 0;
}



undefined4 RFHAL_IEEE802154SetPanCoordinator(int param_1)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  if (param_1 == 0) {
    uVar1 = uVar1 & 0xff7fffff;
  }
  else {
    uVar1 = uVar1 | 0x800000;
  }
  write_volatile_4(Peripherals::SEQ.REG000,uVar1);
  return 0;
}



undefined4 RFHAL_IEEE802154AcceptFrames(int param_1)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 & 0xffe1ffff | param_1 << 0x11);
  return 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

RAIL_Status_t RFHAL_IEEE802154SetFramePending(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = GENERIC_PHY_CanModifyAck();
  if (iVar1 == 0) {
    return RAIL_STATUS_INVALID_STATE;
  }
  uVar2 = read_volatile_4(RAC->.SR0);
  uVar2 = uVar2 & 0x20000;
  if (uVar2 == 0) {
    uRam43081210 = 1;
  }
  else {
    uVar2 = 2;
  }
  _DAT_43081104 = 0;
  return (RAIL_Status_t)uVar2;
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
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined **radioConfig;
  
  if (param_2 != 0) {
    lastSetTxPower = RFHAL_GetCurrPowerLevel();
  }
  uVar2 = RFHAL_GetCurrPowerLevel();
  if ((int)uVar2 < 0x65) {
    radioConfig = (undefined **)&ble_config_base_min;
    if (param_1 == 0x1c) {
      radioConfig = &ble_config_2458MHz_min;
    }
  }
  else {
    uVar4 = param_1 - 7U & 0xff;
    if (uVar4 < 0x17) {
      uVar4 = 1 << uVar4;
      if ((uVar4 & 0x58000b) == 0) {
        radioConfig = (undefined **)&ble_config_2458MHz_20dBm_min;
        if ((uVar4 & 0x200000) == 0) {
          radioConfig = (undefined **)&ble_config_base_20dBm_min;
        }
      }
      else {
        radioConfig = (undefined **)&ble_config_2416_2418_2422_2454_2456_2460_20dBm_min;
      }
    }
    else {
      radioConfig = (undefined **)&ble_config_base_20dBm_min;
    }
  }
  if (radioConfig != prevRadioCfg) {
    bVar1 = RAIL_RadioConfig(&ble_config_base_min);
    if (radioConfig != (undefined **)&ble_config_base_min) {
      bVar1 = RAIL_RadioConfig(radioConfig);
    }
    uVar2 = (uint)bVar1;
    prevRadioCfg = radioConfig;
  }
  iVar3 = RFHAL_GetCurrPowerLevel(uVar2);
  if (param_1 == 0x1b) {
    iVar5 = 0x96;
  }
  else {
    iVar5 = 300;
  }
  if ((iVar3 <= iVar5) && (lastSetTxPower <= iVar5)) {
    if (iVar3 != lastSetTxPower) {
      lastSetTxPower = RAIL_TxPowerSet(lastSetTxPower);
    }
    return;
  }
  RAIL_TxPowerSet(iVar5);
  return;
}



undefined4 RFHAL_Ble2MbpsSet(void)

{
  return 0;
}



undefined4 RFHAL_Ble1MbpsSet(void)

{
  return 1;
}



void RFHAL_BleInit(void)

{
  uint8_t uVar1;
  
  RADIO_TxToRxSearchTimeSet(0x46);
  RFHAL_SetProtocolSpecificChCheckCB(0xc3cd);
  RAIL_RadioConfig(&ble_config_base);
  prevRadioCfg = &ble_config_base_min;
  uVar1 = RAIL_ChannelConfig((RAIL_ChannelConfig_t *)&bleChannelConfig);
  lastSetTxPower = RFHAL_GetCurrPowerLevel(uVar1);
  return;
}



void RFHAL_BleDeinit(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 extraout_r1;
  
  RFHAL_SetProtocolSpecificChCheckCB(0);
  RADIO_TxToRxSearchTimeSet(0,extraout_r1,param_3,param_4);
  return;
}



void RFHAL_BLEPreambleSyncWordSet(int param_1,uint param_2)

{
  uint uVar1;
  
  write_volatile_4(MODEM->.SYNC0,param_2);
  uVar1 = read_volatile_4(MODEM->.PRE);
  if (param_1 == 0x55) {
    uVar1 = uVar1 & 0xfffffff0 | 1;
  }
  else {
    uVar1 = uVar1 & 0xfffffff0 | 2;
  }
  write_volatile_4(MODEM->.PRE,uVar1);
  return;
}



void RFHAL_BLEWhiteningSet(uint param_1,uint param_2,int param_3)

{
  bool bVar1;
  
  write_volatile_4(FRC->.WHITEPOLY,param_1);
  write_volatile_4(FRC->.WHITEINIT,param_2);
  bVar1 = param_3 == 0;
  if (bVar1) {
    write_volatile_4(FRC->.FECCTRL,0);
  }
  else {
    write_volatile_4(FRC->.FECCTRL,1);
    param_3 = 0;
  }
  RADIO_FrameDescsConfig(bVar1,param_3,1,1);
  return;
}



void AUXPLL_AuxSettingsPllLoopback(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(RAC->.AUXCTRL);
  write_volatile_4(RAC->.AUXCTRL,uVar1 | 0x3000000);
  uVar1 = read_volatile_4(RAC->.SGLNAMIXCTRL);
  write_volatile_4(RAC->.SGLNAMIXCTRL,uVar1 | 0x4000000);
  return;
}



void AUXPLL_AuxSettingsPaLoopback(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(RAC->.SYNTHCTRL);
  write_volatile_4(RAC->.SYNTHCTRL,uVar1 & 0xfffffffb);
  uVar1 = read_volatile_4(RAC->.AUXENCTRL);
  write_volatile_4(RAC->.AUXENCTRL,uVar1 | 4);
  return;
}



void AUXPLL_Stop(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(RAC->.AUXCTRL);
  write_volatile_4(RAC->.AUXCTRL,uVar1 & 0xff7ff835);
  uVar1 = read_volatile_4(RAC->.AUXENCTRL);
  write_volatile_4(RAC->.AUXENCTRL,uVar1 & 0xfffffffe);
  uVar1 = read_volatile_4(RAC->.SGLNAMIXCTRL);
  write_volatile_4(RAC->.SGLNAMIXCTRL,uVar1 & 0xfbffffff);
  uVar1 = read_volatile_4(RAC->.AUXENCTRL);
  write_volatile_4(RAC->.AUXENCTRL,uVar1 & 0xfffffffb);
  return;
}



undefined AUXPLL_ConvertAuxLoDivToRegVal(int param_1)

{
  undefined uVar1;
  
  if (param_1 - 2U < 0x17) {
    uVar1 = (&UNK_00015692)[param_1];
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
  
  uVar1 = read_volatile_4(RAC->.AUXENCTRL);
  write_volatile_4(RAC->.AUXENCTRL,uVar1 & 0xfffffffe);
  uVar1 = read_volatile_4(RAC->.AUXCTRL);
  write_volatile_4(RAC->.AUXCTRL,uVar1 & 0xff01ffcf | 0xe80030);
  uVar1 = read_volatile_4(Peripherals::SYNTH.DIVCTRL);
  iVar2 = AUXPLL_ConvertAuxLoDivToRegVal(param_2);
  write_volatile_4(Peripherals::SYNTH.DIVCTRL,uVar1 & 0xffc0ffff | iVar2 << 0x10);
  uVar1 = read_volatile_4(RAC->.AUXCTRL);
  write_volatile_4(RAC->.AUXCTRL,uVar1 & 0xfffe00ff | param_4 << 0xb | param_3 << 8);
  uVar1 = read_volatile_4(Peripherals::SYNTH.AUXFREQ);
  write_volatile_4(Peripherals::SYNTH.AUXFREQ,param_1 | uVar1 & 0xffffff80);
  uVar1 = read_volatile_4(RAC->.AUXCTRL);
  write_volatile_4(RAC->.AUXCTRL,uVar1 | 0x4a);
  uVar1 = read_volatile_4(RAC->.AUXENCTRL);
  write_volatile_4(RAC->.AUXENCTRL,uVar1 | 1);
  uVar1 = read_volatile_4(RAC->.AUXCTRL);
  write_volatile_4(RAC->.AUXCTRL,uVar1 | 0x80);
  uVar1 = read_volatile_4(RAC->.AUXCTRL);
  write_volatile_4(RAC->.AUXCTRL,uVar1 | 0x800000);
  uVar1 = read_volatile_4(Peripherals::SYNTH.AUXVCDACCTRL);
  write_volatile_4(Peripherals::SYNTH.AUXVCDACCTRL,uVar1 | 0x10);
  uVar1 = read_volatile_4(RAC->.AUXCTRL);
  write_volatile_4(RAC->.AUXCTRL,uVar1 & 0xfffffff7);
  uVar1 = read_volatile_4(RAC->.AUXCTRL);
  write_volatile_4(RAC->.AUXCTRL,uVar1 | 0x800004);
  PHY_UTILS_DelayUs(1000);
  do {
    write_volatile_4(Peripherals::SYNTH.CMD,0x80);
    write_volatile_4(Peripherals::SYNTH.CMD,0x100);
    do {
      uVar1 = read_volatile_4(Peripherals::SYNTH.STATUS);
    } while ((int)(uVar1 << 0x14) < 0);
    uVar1 = read_volatile_4(Peripherals::SYNTH.STATUS);
  } while ((int)(uVar1 << 0x11) < 0);
  uVar1 = read_volatile_4(RAC->.AUXCTRL);
  write_volatile_4(RAC->.AUXCTRL,uVar1 | 8);
  uVar1 = read_volatile_4(Peripherals::SYNTH.AUXVCDACCTRL);
  write_volatile_4(Peripherals::SYNTH.AUXVCDACCTRL,uVar1 & 0xffffffef);
  write_volatile_4(Peripherals::SYNTH.CMD,0x40);
  uVar1 = read_volatile_4(RAC->.AUXCTRL);
  write_volatile_4(RAC->.AUXCTRL,uVar1 & 0xff7ffffb | 0x800000);
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
LAB_0000c970:
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
      if (0xffbfffff < uVar9 * 0x200000) goto LAB_0000c970;
    }
LAB_0000c83c:
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
  if ((uVar11 & 0x100000) != 0) goto LAB_0000c83c;
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
      goto LAB_0000c8b4;
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
LAB_0000c8b4:
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
LAB_0000c970:
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
      if (0xffbfffff < uVar7 * 0x200000) goto LAB_0000c970;
    }
LAB_0000c83c:
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
  if ((uVar10 & 0x100000) != 0) goto LAB_0000c83c;
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
      goto LAB_0000c8b4;
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
LAB_0000c8b4:
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
  if (true) {
    uVar1 = param_1;
  }
  if (true) {
    param_1 = 0;
  }
  iVar3 = count_leading_zeroes(uVar1);
  if (true) {
    iVar3 = iVar3 + 0x20;
  }
  uVar4 = iVar3 - 0xb;
  bVar7 = SBORROW4(uVar4,0x20);
  uVar2 = iVar3 - 0x2b;
  bVar5 = (int)uVar2 < 0;
  bVar6 = uVar2 == 0;
  if ((int)uVar4 < 0x20) {
    bVar7 = SCARRY4(uVar2,0xc);
    iVar3 = iVar3 + -0x1f;
    bVar5 = iVar3 < 0;
    bVar6 = iVar3 == 0;
    uVar2 = uVar4;
    if (!bVar6 && bVar5 == bVar7) {
      param_1 = uVar1 << (uVar4 & 0xff);
      uVar1 = uVar1 >> (0xcU - iVar3 & 0xff);
      goto LAB_0000c8b4;
    }
  }
  if (bVar6 || bVar5 != bVar7) {
    in_r12 = 0x20 - uVar2;
  }
  uVar1 = uVar1 << (uVar2 & 0xff);
  if (bVar6 || bVar5 != bVar7) {
    uVar1 = uVar1 | param_1 >> (in_r12 & 0xff);
  }
  if (bVar6 || bVar5 != bVar7) {
    param_1 = param_1 << (uVar2 & 0xff);
  }
LAB_0000c8b4:
  if ((int)uVar4 < 0x433) {
    return CONCAT44(uVar1 + (0x432 - uVar4) * 0x100000,param_1);
  }
  uVar2 = ~(0x432 - uVar4);
  if (0x1e < (int)uVar2) {
    return (ulonglong)(uVar1 >> (uVar2 - 0x1f & 0xff));
  }
  iVar3 = uVar2 - 0x13;
  if (iVar3 == 0 || iVar3 < 0 != SCARRY4(uVar2 - 0x1f,0xc)) {
    uVar2 = uVar2 + 1;
    return CONCAT44(uVar1 >> (uVar2 & 0xff),
                    param_1 >> (uVar2 & 0xff) | uVar1 << (0x20 - uVar2 & 0xff));
  }
  return (ulonglong)(param_1 >> (0x20 - (0xcU - iVar3) & 0xff) | uVar1 << (0xcU - iVar3 & 0xff));
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
  uVar1 = param_1;
  if ((int)uVar6 < 0) {
    uVar1 = -param_1;
  }
  uVar2 = 0;
  if (true) {
    uVar2 = uVar1;
  }
  if (true) {
    uVar1 = 0;
  }
  iVar4 = count_leading_zeroes(uVar2);
  if (true) {
    iVar4 = iVar4 + 0x20;
  }
  uVar5 = iVar4 - 0xb;
  bVar9 = SBORROW4(uVar5,0x20);
  uVar3 = iVar4 - 0x2b;
  bVar7 = (int)uVar3 < 0;
  bVar8 = uVar3 == 0;
  if ((int)uVar5 < 0x20) {
    bVar9 = SCARRY4(uVar3,0xc);
    iVar4 = iVar4 + -0x1f;
    bVar7 = iVar4 < 0;
    bVar8 = iVar4 == 0;
    uVar3 = uVar5;
    if (!bVar8 && bVar7 == bVar9) {
      uVar1 = uVar2 << (uVar5 & 0xff);
      uVar2 = uVar2 >> (0xcU - iVar4 & 0xff);
      goto LAB_0000c8b4;
    }
  }
  if (bVar8 || bVar7 != bVar9) {
    in_r12 = 0x20 - uVar3;
  }
  uVar2 = uVar2 << (uVar3 & 0xff);
  if (bVar8 || bVar7 != bVar9) {
    uVar2 = uVar2 | uVar1 >> (in_r12 & 0xff);
  }
  if (bVar8 || bVar7 != bVar9) {
    uVar1 = uVar1 << (uVar3 & 0xff);
  }
LAB_0000c8b4:
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
      goto LAB_0000c8b4;
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
LAB_0000c8b4:
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
LAB_0000c83c:
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
  if ((param_2 & 0x100000) != 0) goto LAB_0000c83c;
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
      goto LAB_0000c8b4;
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
LAB_0000c8b4:
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
LAB_0000c83c:
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
  if ((uVar3 & 0x100000) != 0) goto LAB_0000c83c;
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
      goto LAB_0000c8b4;
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
LAB_0000c8b4:
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
    uVar12 = FUN_0000cc78();
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



ulonglong FUN_0000cc78(uint param_1,uint param_2,uint param_3,uint param_4)

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
    uVar16 = FUN_0000ce5e();
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
        if ((uVar6 & 0x100000) != 0) goto LAB_0000ce0e;
        uVar6 = uVar6 | uVar10;
        uVar10 = 0;
        uVar2 = 0x80000000;
      }
    }
    if ((uVar6 & 0x100000) == 0) {
      uVar6 = uVar6 | uVar10;
      uVar10 = 0;
    }
LAB_0000ce0e:
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



ulonglong FUN_0000ce5e(uint param_1,uint param_2,uint param_3,uint param_4)

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
LAB_0000ccd0:
        return (ulonglong)((param_2 ^ param_4) & 0x80000000 | 0x7ff00000) << 0x20;
      }
    }
    else {
      if (uVar2 == in_r12) {
        param_1 = param_3;
        uVar3 = param_4;
        if ((param_3 | param_4 << 0xc) == 0) {
LAB_0000cc94:
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
        if ((param_1 | param_2 << 1) != 0) goto LAB_0000ccd0;
        if ((param_3 | param_4 << 1) != 0) goto LAB_0000cc94;
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
                    // WARNING: Could not recover jumptable at 0x0000d116. Too many branches
                    // WARNING: Treating indirect jump as call
        UNRECOVERED_JUMPTABLE = (code *)software_udf(0xff,0xd116);
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



void exit(int __status)

{
  if (DAT_20000960 != FUN_00000000) {
    (*DAT_20000960)();
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
  param_1[9] = 0xe2f5;
  param_1[10] = 0xe317;
  param_1[0xb] = 0xe34f;
  param_1[8] = param_1;
  param_1[0xc] = 0xe373;
  return;
}



void _cleanup_r(undefined4 param_1)

{
  _fwalk_reent(param_1,0xf631);
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
    param_1[10] = 0xd3d5;
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
  
  if (DAT_20000950 == 0) {
    __sinit(&impure_data);
  }
  ppiVar3 = (int **)&DAT_20000980;
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
        goto LAB_0000d6a0;
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
LAB_0000d6a0:
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
    puVar5 = (uint *)&DAT_00015714;
    puVar7 = (uint *)&DAT_00015710;
LAB_0000d8a2:
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
      puVar5 = (uint *)&DAT_0001571c;
      puVar7 = (uint *)&DAT_00015718;
      goto LAB_0000d8a2;
    }
    uVar8 = param_2[1];
    uVar11 = uVar11 | 0x400;
    if (uVar8 == 0xffffffff) {
      uVar8 = 6;
LAB_0000d8fc:
      param_2[1] = uVar8;
LAB_0000d8fe:
      *param_2 = uVar11;
      puVar5 = (uint *)__cvt(param_1,&local_30,uVar6,uVar9,param_2[1],uVar11,&local_35,&local_34,
                             bVar10,&local_30,0);
      if ((bVar10 & 0xdf) == 0x47) goto LAB_0000d92c;
LAB_0000d940:
      if (0x65 < bVar10) {
        if (bVar10 != 0x66) goto LAB_0000d9cc;
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
          if ((uVar11 == 0) && (-1 < (int)(*param_2 << 0x1f))) goto LAB_0000d9ae;
          uVar11 = uVar11 + 1 + local_34;
        }
        goto LAB_0000d9ac;
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
        if ((bVar10 == 0x47) && (uVar8 == 0)) goto LAB_0000d98e;
        goto LAB_0000d8fe;
      }
      if (uVar8 == 0) {
LAB_0000d98e:
        uVar8 = 1;
        goto LAB_0000d8fc;
      }
      *param_2 = uVar11;
      puVar5 = (uint *)__cvt(param_1,&local_35,uVar6,uVar9,uVar8,uVar11,&local_35,&local_34,0x67,
                             &local_30,0);
LAB_0000d92c:
      if (((int)(local_34 + 3) < 0 != SCARRY4(local_34,3)) || ((int)param_2[1] < (int)local_34)) {
        bVar10 = bVar10 - 2;
        goto LAB_0000d940;
      }
      bVar10 = 0x67;
LAB_0000d9cc:
      if ((int)local_34 < (int)local_30) {
        if ((int)local_34 < 1) {
          iVar3 = 2 - local_34;
        }
        else {
          iVar3 = 1;
        }
        uVar11 = iVar3 + local_30;
LAB_0000d9ac:
        param_2[4] = uVar11;
      }
      else {
        param_2[4] = local_34;
        if ((int)(*param_2 << 0x1f) < 0) {
          uVar11 = local_34 + 1;
          goto LAB_0000d9ac;
        }
      }
LAB_0000d9ae:
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
LAB_0000dc0a:
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
        if (iVar3 == 0) goto LAB_0000dc0a;
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
        iVar3 = (*param_4)(param_1,param_3,&DAT_00013c73,1);
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
        goto LAB_0000da5a;
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
        goto LAB_0000da5a;
      }
      iVar3 = (*param_4)(param_1,param_3,&DAT_00013c73,1);
      if (iVar3 == -1) {
        return 0xffffffff;
      }
      if (((local_34 == 0) && (local_30 == 0)) && (-1 < (int)(*param_2 << 0x1f))) goto LAB_0000da5a;
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
LAB_0000da5a:
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
      if (iVar1 == -1) goto LAB_0000dd52;
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
LAB_0000dd52:
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
      if (iVar1 == -1) goto LAB_0000dd52;
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
LAB_0000df28:
    param_2[4] = 0;
    goto LAB_0000dea4;
  }
  if (bVar1 < 0x6f) {
    if (bVar1 != 99) {
      if (bVar1 < 100) {
        if (bVar1 == 0) goto LAB_0000df28;
        if (bVar1 != 0x58) goto LAB_0000ddbc;
        pcVar3 = "0123456789ABCDEF";
        *(undefined *)((int)param_2 + 0x45) = 0x58;
LAB_0000dec8:
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
LAB_0000de5e:
        *(undefined *)((int)param_2 + 0x43) = 0;
      }
      else {
        if ((bVar1 != 100) && (bVar1 != 0x69)) goto LAB_0000ddbc;
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
        if (uVar8 != 0) goto LAB_0000def8;
LAB_0000df9c:
        *(char *)((int)param_2 + 0x42) = *pcVar3;
        pcVar12 = (char *)((int)param_2 + 0x42);
      }
      else {
        *param_2 = *param_2 & 0xfffffffb;
        if (uVar8 == 0) {
          if (uVar11 != 0) goto LAB_0000df9c;
        }
        else {
LAB_0000def8:
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
      goto LAB_0000dea4;
    }
    uVar8 = **param_5;
    *param_5 = *param_5 + 1;
    *(char *)((int)param_2 + 0x42) = (char)uVar8;
LAB_0000de2c:
    __s = (char *)((int)param_2 + 0x42);
    uVar8 = 1;
  }
  else {
    if (bVar1 != 0x73) {
      if (bVar1 < 0x74) {
        if (bVar1 == 0x6f) {
LAB_0000de3e:
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
          goto LAB_0000de5e;
        }
        if (bVar1 == 0x70) {
          *param_2 = *param_2 | 0x20;
LAB_0000de12:
          *(undefined *)((int)param_2 + 0x45) = 0x78;
          pcVar3 = "0123456789abcdef";
          goto LAB_0000dec8;
        }
      }
      else {
        if (bVar1 == 0x75) goto LAB_0000de3e;
        if (bVar1 == 0x78) goto LAB_0000de12;
      }
LAB_0000ddbc:
      *(byte *)((int)param_2 + 0x42) = bVar1;
      goto LAB_0000de2c;
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
LAB_0000dea4:
  iVar2 = _printf_common(param_1,param_2,local_24,param_3,param_4);
  if ((iVar2 == -1) || (iVar2 = (*param_4)(param_1,param_3,__s,param_2[4]), iVar2 == -1)) {
LAB_0000deb8:
    uVar8 = 0xffffffff;
  }
  else {
    if ((int)(*param_2 << 0x1e) < 0) {
      for (iVar2 = 0; iVar2 < (int)(param_2[3] - local_24[0]); iVar2 = iVar2 + 1) {
        iVar5 = (*param_4)(param_1,param_3,(int)param_2 + 0x19,1);
        if (iVar5 == -1) goto LAB_0000deb8;
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
LAB_0000e19a:
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
        goto LAB_0000e19a;
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



char * strcpy(char *__dest,char *__src)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = __dest;
  do {
    cVar1 = *__src;
    *pcVar2 = cVar1;
    __src = __src + 1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  return __dest;
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
      goto LAB_0000e4a8;
    }
  }
  else {
    if ((param_4 != 0x10) || (uVar7 != 0x30)) goto LAB_0000e4a8;
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
LAB_0000e4a8:
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
    if (iVar2 == 0) goto LAB_0000e53c;
  }
  param_2 = pbVar8 + -1;
LAB_0000e53c:
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
      goto LAB_0000e5ca;
    }
  }
  else {
    if ((param_4 != 0x10) || (uVar6 != 0x30)) goto LAB_0000e5ca;
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
LAB_0000e5ca:
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
    if (iVar2 == 0) goto LAB_0000e65c;
  }
  param_2 = pbVar7 + -1;
LAB_0000e65c:
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
      goto LAB_0000e7c4;
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
LAB_0000e7c4:
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
                              *(undefined4 *)(&DAT_00015784 + uVar17 * 8),param_3,uStack116);
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
switchD_0000eb84_caseD_4:
    local_50 = 1;
    param_6 = 0;
    uVar16 = 0x12;
    uVar23 = 0xffffffff;
    uVar24 = 0xffffffff;
    goto LAB_0000ebf8;
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
    goto LAB_0000ec6c;
  case 4:
    local_50 = 1;
    break;
  case 5:
    local_50 = 1;
LAB_0000ec6c:
    uVar24 = param_6 + uVar17;
    uVar23 = uVar24 + 1;
    uVar16 = uVar23;
    if ((int)uVar23 < 1) {
      uVar16 = 1;
    }
    goto LAB_0000ebf8;
  default:
    goto switchD_0000eb84_caseD_4;
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
LAB_0000ebf8:
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
                          *(undefined4 *)(&DAT_00015784 + iVar18));
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
        if (bVar1) goto LAB_0000ed1e;
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
LAB_0000ed1e:
      uStack116 = (uint)((ulonglong)uVar26 >> 0x20);
      local_78 = (uint)uVar26;
    }
    uVar26 = CONCAT44(uStack116,local_78);
    if (((local_38 != 0) &&
        (iVar6 = __aeabi_dcmplt(local_78,uStack116,0,0x3ff00000),
        uVar26 = CONCAT44(uStack116,local_78), iVar6 != 0)) &&
       (uVar26 = CONCAT44(uStack116,local_78), uVar23 != 0)) {
      if ((int)uVar24 < 1) goto LAB_0000edf6;
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
        uVar27 = __divdf3(0,0x3fe00000,(&DAT_00015778)[uVar21 * 2],(&DAT_0001577c)[uVar21 * 2]);
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
          if (iVar18 != 0) goto LAB_0000f05a;
          if ((int)uVar21 <= (int)pcVar19 - (int)pcVar13) goto LAB_0000edf6;
          uVar27 = __muldf3(local_48,uStack68,0,0x40240000);
          uVar26 = __muldf3(uVar5,uVar25,0,0x40240000);
        }
        goto LAB_0000f036;
      }
      uVar27 = __muldf3((&DAT_00015778)[uVar21 * 2],(&DAT_0001577c)[uVar21 * 2],uVar5,iVar6);
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
LAB_0000f05a:
        do {
          pcVar19 = pcVar15;
          pcVar15 = pcVar19 + -1;
          if (pcVar19[-1] != '9') goto LAB_0000f078;
        } while (pcVar13 != pcVar15);
        uVar16 = uVar16 + 1;
        *pcVar13 = '0';
        pcVar15 = pcVar13;
LAB_0000f078:
        *pcVar15 = *pcVar15 + '\x01';
        goto LAB_0000f036;
      }
      uVar26 = __subdf3(0,0x3fe00000,(int)uVar27,uVar5);
      iVar18 = __aeabi_dcmplt(uVar25,uVar9,(int)uVar26,(int)((ulonglong)uVar26 >> 0x20));
      if (iVar18 != 0) {
        do {
          pcVar19 = pcVar15;
          pcVar15 = pcVar19 + -1;
        } while (pcVar19[-1] == '0');
        goto LAB_0000f036;
      }
      goto LAB_0000edf6;
    }
    uVar26 = __subdf3(local_78,uStack116,0,0x40140000);
    uVar25 = (undefined4)((ulonglong)uVar26 >> 0x20);
    iVar6 = __aeabi_dcmpgt((int)uVar26,uVar25,uVar5,iVar6);
    uVar20 = uVar21;
    if (iVar6 == 0) {
      iVar18 = __aeabi_dcmplt((int)uVar26,uVar25,uVar5,iVar18 + 0x7cc00000);
      if (iVar18 == 0) goto LAB_0000edf6;
      goto LAB_0000f2ae;
    }
LAB_0000ee46:
    *pcVar13 = '1';
    uVar17 = uVar16 + 1;
    pcVar19 = pcVar13 + 1;
LAB_0000f2b6:
    uVar24 = 0;
  }
  else {
LAB_0000edf6:
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
                ((bVar2 & 1) != 0)))) goto LAB_0000f05a;
            break;
          }
          uVar26 = __muldf3(uVar9,uVar10,0,0x40240000);
          uVar11 = (uint)((ulonglong)uVar26 >> 0x20);
          param_3 = (uint)uVar26;
          iVar8 = __aeabi_dcmpeq(param_3,uVar11,0,0);
          pcVar15 = pcVar19;
          uVar16 = uVar17;
        } while (iVar8 == 0);
        goto LAB_0000f036;
      }
      if (uVar23 == 0) {
        uVar26 = __muldf3(uVar25,uVar5,0,0x40140000);
        iVar8 = __aeabi_dcmpge((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),param_3,uVar11);
        uVar21 = uVar23;
        uVar20 = uVar23;
        uVar16 = uVar17;
        if (iVar8 == 0) goto LAB_0000ee46;
      }
      else {
        uVar21 = 0;
        uVar20 = uVar21;
      }
LAB_0000f2ae:
      uVar17 = ~param_6;
      pcVar19 = pcVar13;
      goto LAB_0000f2b6;
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
        if (local_5c == 0) goto LAB_0000f12a;
      }
      uVar4 = __pow5mult(param_1,uVar4,local_5c);
    }
LAB_0000f12a:
    uVar20 = __i2b(param_1,1);
    if (local_4c == 0) {
      if ((int)param_5 < 2) goto LAB_0000f14e;
      local_5c = local_4c;
LAB_0000f17e:
      iVar6 = 1;
    }
    else {
      uVar20 = __pow5mult(param_1,uVar20,local_4c);
      if ((int)param_5 < 2) {
LAB_0000f14e:
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
        if (local_4c == 0) goto LAB_0000f17e;
      }
      else {
        local_5c = 0;
      }
      iVar6 = __hi0bits(*(undefined4 *)(uVar20 + *(int *)(uVar20 + 0x10) * 4 + 0x10));
      iVar6 = 0x20 - iVar6;
    }
    uVar11 = iVar6 + iVar8 & 0x1f;
    if (uVar11 == 0) {
LAB_0000f26e:
      iVar6 = uVar11 + 0x1c;
      local_60 = (char *)((int)local_60 + iVar6);
      iVar18 = iVar18 + iVar6;
      iVar8 = iVar8 + iVar6;
    }
    else {
      uVar16 = 0x20 - uVar11;
      if ((int)uVar16 < 5) {
        uVar11 = uVar16;
        if (uVar16 != 4) goto LAB_0000f26e;
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
        if ((0 < (int)uVar24) || ((int)param_5 < 3)) goto LAB_0000f4f0;
      }
      else {
        uVar21 = __multadd(param_1,uVar21,10,0);
        if ((0 < (int)uVar24) || ((int)param_5 < 3)) goto LAB_0000f304;
      }
LAB_0000f290:
      if (uVar23 == 0) {
        uVar20 = __multadd(param_1,uVar20,5);
        iVar8 = __mcmp(uVar4,uVar20);
        uVar16 = uVar17;
        if (0 < iVar8) goto LAB_0000ee46;
      }
      goto LAB_0000f2ae;
    }
    if (((int)uVar23 < 1) && (2 < (int)param_5)) goto LAB_0000f290;
    if (local_50 == 0) {
LAB_0000f4f0:
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
LAB_0000f304:
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
LAB_0000f34e:
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
LAB_0000f3f4:
          *local_60 = '9';
          pcVar12 = local_60 + 1;
          goto LAB_0000f3fe;
        }
        if (0 < iVar18) {
LAB_0000f3a6:
          uVar11 = iVar8 + 0x31;
        }
LAB_0000f3aa:
        cVar22 = (char)uVar11;
LAB_0000f3ae:
        pcVar19 = local_60 + 1;
        *local_60 = cVar22;
        goto LAB_0000f2ba;
      }
      if ((iVar18 < 0) || (((iVar18 == 0 && (param_5 == 0)) && ((param_3 & 1) == 0)))) {
        if (0 < iVar7) {
          uVar4 = __lshift(param_1,uVar4,1);
          iVar18 = __mcmp(uVar4,uVar20);
          if ((0 < iVar18) || ((iVar18 == 0 && ((uVar11 & 1) != 0)))) {
            if (uVar11 != 0x39) goto LAB_0000f3a6;
            goto LAB_0000f3f4;
          }
        }
        goto LAB_0000f3aa;
      }
      pcVar12 = local_60 + 1;
      if (0 < iVar7) {
        if (uVar11 == 0x39) goto LAB_0000f3f4;
        cVar22 = (char)uVar11 + '\x01';
        goto LAB_0000f3ae;
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
        goto LAB_0000f34e;
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
LAB_0000f3fe:
      do {
        pcVar19 = pcVar12;
        pcVar12 = pcVar19 + -1;
        if (pcVar19[-1] != '9') {
          cVar22 = pcVar19[-1] + '\x01';
          goto LAB_0000f4b6;
        }
      } while (pcVar13 != pcVar12);
      uVar17 = uVar17 + 1;
      cVar22 = '1';
      pcVar12 = pcVar13;
LAB_0000f4b6:
      *pcVar12 = cVar22;
    }
  }
LAB_0000f2ba:
  _Bfree(param_1,uVar20);
  uVar16 = uVar17;
  if (uVar21 != 0) {
    if ((uVar24 != 0) && (uVar24 != uVar21)) {
      _Bfree(param_1,uVar24);
    }
    _Bfree(param_1,uVar21);
  }
LAB_0000f036:
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
          goto LAB_0000f616;
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
LAB_0000f616:
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
    iVar1 = _fwalk_reent(&impure_data,0xf631);
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
      goto LAB_0000f7a4;
    }
  }
  else {
    *param_4 = (uint)((local_64 & 0xf000) == 0x2000);
  }
  uVar2 = 0x400;
LAB_0000f7a4:
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
      *(undefined4 *)(param_1 + 0x28) = 0xd3d5;
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
joined_r0x0000f8c0:
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
        goto joined_r0x0000f8c0;
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
    if (*(int *)(iVar3 + 0xc) != 0) goto LAB_0000f924;
LAB_0000f95a:
    puVar1 = (undefined4 *)0x0;
  }
  else {
LAB_0000f924:
    iVar4 = *(int *)(*(int *)(param_1 + 0x24) + 0xc);
    puVar1 = *(undefined4 **)(iVar4 + param_2 * 4);
    if (puVar1 == (undefined4 *)0x0) {
      iVar4 = 1 << (param_2 & 0xff);
      puVar1 = (undefined4 *)_calloc_r(param_1,1,(iVar4 + 5) * 4);
      if (puVar1 == (undefined4 *)0x0) goto LAB_0000f95a;
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
LAB_0000ffba:
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
          goto LAB_0000ffba;
        }
      }
      param_2[4] = pvVar1;
      param_2[5] = pvVar2;
      *param_2 = (void *)((int)pvVar1 + __n);
      param_2[2] = (void *)((int)pvVar2 - __n);
      pvVar2 = param_4;
    }
    if (pvVar2 <= param_4) goto LAB_0000fff8;
  }
  pvVar2 = param_4;
LAB_0000fff8:
  memmove(*param_2,param_3,(size_t)pvVar2);
  param_2[2] = (void *)((int)param_2[2] - (int)pvVar2);
  *param_2 = (void *)((int)pvVar2 + (int)*param_2);
  return 0;
}



int _svfiprintf_r(undefined4 *param_1,int *param_2,byte *param_3,int *param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  int *piVar5;
  byte *pbVar6;
  byte *pbVar7;
  int unaff_r9;
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
LAB_00010072:
  pbVar7 = pbVar6;
  if (*pbVar7 != 0) goto code_r0x0001007a;
  goto LAB_0001007e;
code_r0x0001007a:
  pbVar6 = pbVar7 + 1;
  if (*pbVar7 != 0x25) goto LAB_00010072;
LAB_0001007e:
  iVar2 = (int)pbVar7 - (int)param_3;
  if (iVar2 != 0) {
    iVar3 = __ssputs_r(param_1,param_2,param_3,iVar2);
    if (iVar3 == -1) {
LAB_000101de:
      if ((int)((uint)*(ushort *)(param_2 + 3) << 0x19) < 0) {
        return -1;
      }
      return local_74;
    }
    local_74 = local_74 + iVar2;
  }
  if (*pbVar7 == 0) goto LAB_000101de;
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
    local_88 = 1 << ((int)pvVar4 - 0x15854U & 0xff) | local_88;
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
    if (-1 < iVar2) goto LAB_0001011c;
    local_7c = -iVar2;
    local_88 = local_88 | 2;
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
    if (bVar1) {
LAB_0001011c:
      local_7c = iVar2;
    }
  }
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
  pvVar4 = memchr(&DAT_0001585a,(uint)*param_3,3);
  if (pvVar4 != (void *)0x0) {
    local_88 = local_88 | 0x40 << ((int)pvVar4 - 0x1585aU & 0xff);
    param_3 = param_3 + 1;
  }
  local_70 = *param_3;
  param_3 = param_3 + 1;
  pvVar4 = memchr(&DAT_0001585e,(uint)local_70,6);
  if (pvVar4 == (void *)0x0) {
    unaff_r9 = _printf_i(param_1,&local_88,param_2,0xff75,&local_8c);
  }
  else {
    if (false) {
      local_8c = (int *)(((int)local_8c + 7U & 0xfffffff8) + 8);
      goto LAB_0001018c;
    }
    unaff_r9 = _printf_float(param_1,&local_88,param_2,0xff75,&local_8c);
  }
  if (unaff_r9 == -1) goto LAB_000101de;
LAB_0001018c:
  local_74 = local_74 + unaff_r9;
  pbVar6 = param_3;
  goto LAB_00010072;
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



int _vfprintf_r(int param_1,undefined4 *param_2,byte *param_3,int *param_4)

{
  bool bVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  byte *pbVar5;
  byte *pbVar6;
  int unaff_r9;
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
LAB_000102aa:
  pbVar6 = pbVar5;
  if (*pbVar6 != 0) goto code_r0x000102b2;
  goto LAB_000102b6;
code_r0x000102b2:
  pbVar5 = pbVar6 + 1;
  if (*pbVar6 != 0x25) goto LAB_000102aa;
LAB_000102b6:
  iVar7 = (int)pbVar6 - (int)param_3;
  if (iVar7 != 0) {
    iVar2 = __sfputs_r(param_1,param_2,param_3,iVar7);
    if (iVar2 == -1) {
LAB_00010452:
      if ((int)((uint)*(ushort *)(param_2 + 3) << 0x19) < 0) {
        return -1;
      }
      return local_74;
    }
    local_74 = local_74 + iVar7;
  }
  if (*pbVar6 == 0) goto LAB_00010452;
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
    local_88 = 1 << ((int)pvVar3 - 0x15854U & 0xff) | local_88;
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
    if (-1 < iVar7) goto LAB_00010380;
    local_7c = -iVar7;
    local_88 = local_88 | 2;
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
    if (bVar1) {
LAB_00010380:
      local_7c = iVar7;
    }
  }
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
  pvVar3 = memchr(&DAT_0001585a,(uint)*param_3,3);
  if (pvVar3 != (void *)0x0) {
    local_88 = local_88 | 0x40 << ((int)pvVar3 - 0x1585aU & 0xff);
    param_3 = param_3 + 1;
  }
  local_70 = *param_3;
  param_3 = param_3 + 1;
  pvVar3 = memchr(&DAT_0001585e,(uint)local_70,6);
  if (pvVar3 == (void *)0x0) {
    unaff_r9 = _printf_i(param_1,&local_88,param_2,0x10243,&local_8c);
  }
  else {
    if (false) {
      local_8c = (int *)(((int)local_8c + 7U & 0xfffffff8) + 8);
      goto LAB_000103fe;
    }
    unaff_r9 = _printf_float(param_1,&local_88,param_2,0x10243,&local_8c);
  }
  if (unaff_r9 == -1) goto LAB_00010452;
LAB_000103fe:
  local_74 = local_74 + unaff_r9;
  pbVar5 = param_3;
  goto LAB_000102aa;
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
      _fwalk(&impure_data,0x10625);
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


