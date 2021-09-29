#include "railtest_efr32_6.h"



// WARNING: Control flow encountered bad instruction data

void FUN_00000000(uint param_1)

{
  uint unaff_r6;
  uint unaff_r9;
  bool in_ZR;
  
  if (!in_ZR) {
                    // WARNING: Bad instruction - Truncating control flow here
    halt_baddata();
  }
                    // WARNING: Could not recover jumptable at 0x00000044. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)(param_1 &
            (param_1 & (unaff_r9 >> (unaff_r6 & 0x1f) | unaff_r9 << 0x20 - (unaff_r6 & 0x1f))) >> 5)
  )();
  return;
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
  
  memset(&completed_9929,0,0x3a08);
  if (false) {
    FUN_00000000();
  }
  if (false) {
    FUN_00000000();
  }
  __libc_init_array(0);
  __status = main(0,0);
                    // WARNING: Subroutine does not return
  exit(__status);
}



void ieee802154Enable(int argc,char **argv)

{
  _Bool _Var1;
  RAIL_Status_t_enum code;
  int iVar2;
  uint32_t uVar3;
  uint uVar4;
  char *pcVar5;
  char *command;
  char *pcVar6;
  RAIL_StateTiming_t timings;
  RAIL_IEEE802154_Config_t config;
  
  _Var1 = inRadioState('\x01',*argv);
  if (_Var1 == false) {
    return;
  }
  config.ackConfig.ackTimeout = 1000;
  config.ackConfig.rxTransitions = 0x202;
  config.ackConfig.txTransitions = 0x202;
  config.timings._0_4_ = 0xb60064;
  config.timings._4_4_ = 0xc00064;
  config.timings._8_4_ = 0;
  pcVar6 = argv[1];
  config.framesMask = '\v';
  config.addresses = (RAIL_IEEE802154_AddrConfig_t *)0x0;
  config.ackConfig.enable = true;
  config.promiscuousMode = false;
  config.isPanCoordinator = false;
  iVar2 = memcmp(pcVar6,&DAT_00011c47,4);
  if (iVar2 == 0) {
    config.ackConfig.rxTransitions = CONCAT11(config.ackConfig.rxTransitions.error,1);
    config.ackConfig.txTransitions = CONCAT11(config.ackConfig.txTransitions.error,1);
  }
  else {
    iVar2 = memcmp(pcVar6,"rx",2);
    if (iVar2 != 0) {
      pcVar6 = "Unknown auto ack default state.";
      code = 0x20;
      goto LAB_00000210;
    }
  }
  uVar3 = ciGetUnsigned(argv[2]);
  uVar4 = uVar3 & 0xffff;
  if (uVar4 < 0x32c9) {
    config.timings._4_4_ = config.timings._4_4_ & 0xffff0000 | uVar4;
    config.timings._0_4_ = config.timings._0_4_ & 0xffff0000 | uVar4;
    uVar3 = ciGetUnsigned(argv[3]);
    uVar4 = uVar3 & 0xffff;
    if (uVar4 < 0x32c9) {
      config.timings._4_4_ = config.timings._4_4_ & 0xffff | uVar4 << 0x10;
      config.timings._0_4_ =
           config.timings._0_4_ & 0xffff | (uint)(ushort)((short)uVar4 - 10) << 0x10;
      uVar3 = ciGetUnsigned(argv[4]);
      config.ackConfig.ackTimeout = (uint16_t)uVar3;
      code = RAIL_IEEE802154_Init(railHandle,&config);
      if (code == RAIL_STATUS_NO_ERROR) {
        command = *argv;
        pcVar6 = getRfStateName(config.ackConfig.txTransitions.success);
        pcVar5 = getRfStateName(config.ackConfig.rxTransitions.success);
        responsePrint(command,
                      "802.15.4:%s,rxDefaultState:%s,txDefaultState:%s,idleTiming:%d,turnaroundTime:%d,ackTimeout:%d"
                      ,"Enabled",pcVar6,pcVar5,config.timings._4_4_ & 0xffff,
                      config.timings._4_4_ >> 0x10,(uint)config.ackConfig.ackTimeout);
        return;
      }
      pcVar6 = "Call to RAIL_IEEE802154_Init returned an error";
    }
    else {
      pcVar6 = "Invalid turnaround timing";
      code = 0x22;
    }
  }
  else {
    pcVar6 = "Invalid idle timing.";
    code = 0x21;
  }
LAB_00000210:
  responsePrintError(*argv,code,pcVar6);
  return;
}



void config2p4Ghz802154(int argc,char **argv)

{
  _Bool _Var1;
  RAIL_Status_t_enum RVar2;
  char *pcVar3;
  undefined4 in_r3;
  
  _Var1 = inRadioState('\x01',*argv);
  if (_Var1 != false) {
    RVar2 = RAIL_IEEE802154_Config2p4GHzRadio(railHandle);
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
  RAIL_Status_t_enum RVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  byte framesMask;
  char *pcVar6;
  
  uVar2 = ciGetUnsigned(argv[1]);
  uVar3 = ciGetUnsigned(argv[2]);
  uVar4 = ciGetUnsigned(argv[3]);
  uVar5 = ciGetUnsigned(argv[4]);
  if (uVar2 == 0) {
    framesMask = 0;
  }
  else {
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
  RVar1 = RAIL_IEEE802154_AcceptFrames(railHandle,framesMask);
  if (RVar1 == RAIL_STATUS_NO_ERROR) {
    pcVar6 = "Disabled";
    if (uVar2 != 0) {
      pcVar6 = "Enabled";
    }
    responsePrint(*argv,"CommandFrame:%s,AckFrame:%s,DataFrame:%s,BeaconFrame:%s",pcVar6);
    return;
  }
  responsePrintError(*argv,'#',"Failed to set which frames to accept.");
  return;
}



void ieee802154SetPromiscuousMode(int argc,char **argv)

{
  RAIL_Status_t_enum RVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  char *pcVar4;
  undefined4 in_r3;
  
  uVar2 = ciGetUnsigned(argv[1]);
  uVar3 = uVar2;
  if (uVar2 != 0) {
    uVar3 = 1;
  }
  RVar1 = RAIL_IEEE802154_SetPromiscuousMode(railHandle,SUB41(uVar3,0));
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
  RAIL_Status_t_enum RVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  char *pcVar4;
  undefined4 in_r3;
  
  uVar2 = ciGetUnsigned(argv[1]);
  uVar3 = uVar2;
  if (uVar2 != 0) {
    uVar3 = 1;
  }
  RVar1 = RAIL_IEEE802154_SetPanCoordinator(railHandle,SUB41(uVar3,0));
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
  RAIL_Status_t_enum status;
  uint32_t uVar1;
  uint32_t uVar2;
  char *pcVar3;
  uint8_t index;
  char *command;
  
  uVar1 = ciGetUnsigned(argv[1]);
  if (argc < 3) {
    index = '\0';
  }
  else {
    uVar2 = ciGetUnsigned(argv[2]);
    index = (uint8_t)uVar2;
  }
  status = RAIL_IEEE802154_SetPanId(railHandle,(uint16_t)uVar1,index);
  command = *argv;
  pcVar3 = getStatusMessage(status);
  responsePrint(command,"802.15.4PanId:%s",pcVar3);
  return;
}



void ieee802154SetShortAddress(int argc,char **argv)

{
  RAIL_Status_t status;
  uint32_t uVar1;
  uint32_t uVar2;
  char *pcVar3;
  uint8_t index;
  char *command;
  
  uVar1 = ciGetUnsigned(argv[1]);
  if (argc < 3) {
    index = '\0';
  }
  else {
    uVar2 = ciGetUnsigned(argv[2]);
    index = (uint8_t)uVar2;
  }
  status = RAIL_IEEE802154_SetShortAddress(railHandle,(uint16_t)uVar1,index);
  command = *argv;
  pcVar3 = getStatusMessage(status);
  responsePrint(command,"802.15.4ShortAddress:%s",pcVar3);
  return;
}



// WARNING: Could not reconcile some variable overlaps

void ieee802154SetLongAddress(int argc,char **argv)

{
  RAIL_Status_t status;
  uint32_t uVar1;
  char *pcVar2;
  uint8_t index;
  int iVar3;
  char *command;
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
  if (argc < 10) {
    index = '\0';
  }
  else {
    uVar1 = ciGetUnsigned(argv[9]);
    index = (uint8_t)uVar1;
  }
  status = RAIL_IEEE802154_SetLongAddress(railHandle,longAddr,index);
  command = *argv;
  pcVar2 = getStatusMessage(status);
  responsePrint(command,"802.15.4LongAddress:%s",pcVar2);
  return;
}



void getAddressFilter(int argc,char **argv)

{
  bool bVar1;
  char *pcVar2;
  
  bVar1 = RAIL_IsAddressFilterEnabled(railHandle);
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
  if (uVar1 != 0) {
    uVar1 = 1;
  }
  RAIL_EnableAddressFilter(railHandle,SUB41(uVar1,0));
  getAddressFilter(1,argv);
  return;
}



void printAddresses(int argc,char **argv)

{
  byte bVar1;
  char *pcVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  pbVar4 = config.sizes;
  responsePrintHeader(*argv,"Field:%u,Index:%u,Offset:%u,Size:%u,Address:%s,Status:%s");
  iVar7 = 0;
  iVar6 = 0;
  while( true ) {
    iVar9 = iVar6 << 5;
    iVar5 = 0;
    do {
      bVar1 = *pbVar4;
      if (*pbVar4 != 0) {
        iVar3 = 0;
        for (iVar8 = 0; iVar8 < (int)(uint)*pbVar4; iVar8 = iVar8 + 1) {
          siprintf(addressPrintBuffer + iVar3,"0x%.2x ",(uint)addresses[iVar9 + iVar8]);
          iVar3 = iVar3 + 5;
        }
        bVar1 = addressPrintBuffer[0];
        if (iVar3 != 0) {
          addressEnabled[1][iVar3 + 3] = false;
          bVar1 = addressPrintBuffer[0];
        }
      }
      addressPrintBuffer[0] = bVar1;
      iVar9 = iVar9 + 8;
      pcVar2 = "Enabled";
      if (addressEnabled[iVar7 + iVar5] == false) {
        pcVar2 = "Disabled";
      }
      iVar3 = iVar5 + 1;
      responsePrintMulti("Field:%u,Index:%u,Offset:%u,Size:%u,Address:%s,Status:%s",iVar6,iVar5,
                         (uint)pbVar4[-2],(uint)*pbVar4,addressPrintBuffer,pcVar2);
      iVar5 = iVar3;
    } while (iVar3 != 4);
    iVar7 = iVar7 + 4;
    pbVar4 = pbVar4 + 1;
    if (iVar6 != 0) break;
    iVar6 = 1;
  }
  return;
}



void setAddressFilterConfig(int argc,char **argv)

{
  RAIL_Status_t_enum RVar1;
  uint32_t uVar2;
  undefined4 in_r3;
  int iVar3;
  int iVar4;
  char **ppcVar5;
  
  memset(addresses,0,0x40);
  addressEnabled[0] = 0;
  addressEnabled[1] = 0;
  config.matchTable = ciGetUnsigned(argv[1]);
  if (argc < 6) {
    iVar3 = argc + -2;
  }
  else {
    iVar3 = 4;
  }
  ppcVar5 = argv + 1;
  for (iVar4 = 0; iVar4 < iVar3; iVar4 = iVar4 + 1) {
    ppcVar5 = ppcVar5 + 1;
    if (iVar4 << 0x1f < 0) {
      uVar2 = ciGetUnsigned(*ppcVar5);
      config.sizes[iVar4 >> 1] = (uint8_t)uVar2;
    }
    else {
      uVar2 = ciGetUnsigned(*ppcVar5);
      config.offsets[iVar4 >> 1] = (uint8_t)uVar2;
    }
  }
  RVar1 = RAIL_ConfigAddressFilter(railHandle,&config);
  if (RVar1 != RAIL_STATUS_NO_ERROR) {
    responsePrintError(*argv,'0',"Invalid address filtering configuration.",in_r3);
    return;
  }
  printAddresses(1,argv);
  return;
}



// WARNING: Could not reconcile some variable overlaps

void setAddress(int argc,char **argv)

{
  RAIL_Status_t_enum RVar1;
  uint32_t uVar2;
  uint8_t code;
  undefined4 in_r2;
  char *formatString;
  undefined4 in_r3;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uStack36;
  uint8_t address [8];
  
  uStack36 = argv;
  address._0_4_ = in_r2;
  address._4_4_ = in_r3;
  uVar2 = ciGetUnsigned(argv[1]);
  uVar5 = uVar2 & 0xff;
  uVar2 = ciGetUnsigned(argv[2]);
  if ((uVar5 < 2) && (uVar3 = uVar2 & 0xff, uVar3 < 4)) {
    if (argc < 0xc) {
      address._0_4_ = 0;
      address._4_4_ = 0;
      for (iVar4 = 3; iVar4 < argc; iVar4 = iVar4 + 1) {
        uVar2 = ciGetUnsigned(argv[iVar4]);
        address[iVar4 + -3] = (uint8_t)uVar2;
      }
      RVar1 = RAIL_SetAddressFilterAddress
                        (railHandle,(uint8_t)uVar5,(uint8_t)uVar3,address,
                         (bool)addressEnabled[uVar5][uVar3]);
      if (RVar1 == RAIL_STATUS_NO_ERROR) {
        iVar4 = uVar3 + uVar5 * 4;
        *(undefined4 *)addresses[iVar4] = address._0_4_;
        *(undefined4 *)(addresses[iVar4] + 4) = address._4_4_;
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
  RAIL_Status_t RVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  char *command;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  undefined enable;
  uint uVar8;
  
  uVar2 = ciGetUnsigned(argv[1]);
  uVar3 = ciGetUnsigned(argv[2]);
  uVar4 = ciGetUnsigned(argv[3]);
  uVar8 = uVar4 & 0xff;
  enable = (undefined)uVar8;
  if (uVar8 != 0) {
    enable = true;
  }
  uVar7 = uVar3 & 0xff;
  uVar6 = uVar2 & 0xff;
  RVar1 = RAIL_EnableAddressFilterAddress(railHandle,(bool)enable,(uint8_t)uVar6,(uint8_t)uVar7);
  if (RVar1 != '\0') {
    responsePrintError(*argv,'4',"Could not enable/disable address!");
    return;
  }
  command = *argv;
  addressEnabled[uVar6][uVar7] = (_Bool)enable;
  pcVar5 = "Enabled";
  if (uVar8 == 0) {
    pcVar5 = "Disabled";
  }
  responsePrint(command,"Field:%u,Index:%u,Offset:%u,Size:%u,Address:%s,Status:%s",uVar6,uVar7,
                (uint)config.offsets[uVar6],(uint)config.sizes[uVar6],addressPrintBuffer,pcVar5);
  return;
}



// WARNING: Could not reconcile some variable overlaps

void autoAckConfig(int argc,char **argv)

{
  _Bool _Var1;
  RAIL_Status_t_enum code;
  int iVar2;
  uint32_t uVar3;
  uint uVar4;
  char *pcVar5;
  char *command;
  char *pcVar6;
  RAIL_StateTiming_t timings;
  
  config.enable = true;
  _Var1 = inRadioState('\x01',*argv);
  if (_Var1 == false) {
    return;
  }
  pcVar6 = argv[1];
  iVar2 = memcmp(pcVar6,&DAT_00011c47,4);
  if (iVar2 == 0) {
    config.rxTransitions.success = '\x01';
    config.txTransitions.success = '\x01';
  }
  else {
    iVar2 = memcmp(pcVar6,"rx",2);
    if (iVar2 != 0) {
      pcVar6 = "Unknown auto ack default state.";
      code = 0x20;
      goto LAB_00000896;
    }
    config.rxTransitions.success = '\x02';
    config.txTransitions.success = '\x02';
  }
  timings._8_4_ = 0;
  timings._0_4_ = 0;
  timings._4_4_ = 0;
  uVar3 = ciGetUnsigned(argv[2]);
  uVar4 = uVar3 & 0xffff;
  if (uVar4 < 0x32c9) {
    timings._4_4_ = timings._4_4_ & 0xffff0000 | uVar4;
    timings._0_4_ = timings._0_4_ & 0xffff0000 | uVar4;
    uVar3 = ciGetUnsigned(argv[3]);
    uVar4 = uVar3 & 0xffff;
    if (uVar4 < 0x32c9) {
      timings._4_4_ = timings._4_4_ & 0xffff | uVar4 << 0x10;
      timings._0_4_ = timings._0_4_ & 0xffff | (uint)(ushort)((short)uVar4 - 10) << 0x10;
      uVar3 = ciGetUnsigned(argv[4]);
      config.ackTimeout = (uint16_t)uVar3;
      RAIL_SetStateTiming(railHandle,&timings);
      code = RAIL_ConfigAutoAck(railHandle,&config);
      if (code == RAIL_STATUS_NO_ERROR) {
        command = *argv;
        pcVar6 = getRfStateName(config.rxTransitions.success);
        pcVar5 = getRfStateName(config.txTransitions.success);
        responsePrint(command,
                      "rxDefaultState:%s,txDefaultState:%s,idleTiming:%d,turnaroundTime:%d,ackTimeout:%d"
                      ,pcVar6,pcVar5,timings._4_4_ & 0xffff,timings._4_4_ >> 0x10,
                      (uint)config.ackTimeout);
        return;
      }
      pcVar6 = "Call to RAIL_ConfigAutoAck returned an error";
    }
    else {
      pcVar6 = "Invalid turnaround timing";
      code = 0x22;
    }
  }
  else {
    pcVar6 = "Invalid idle timing.";
    code = 0x21;
  }
LAB_00000896:
  responsePrintError(*argv,code,pcVar6);
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
  bVar1 = RAIL_IsAutoAckEnabled(railHandle);
  bVar2 = RAIL_IsRxAutoAckPaused(railHandle);
  bVar3 = RAIL_IsTxAutoAckPaused(railHandle);
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



// WARNING: Could not reconcile some variable overlaps

void autoAckDisable(int argc,char **argv)

{
  RAIL_Status_t_enum code;
  RAIL_AutoAckConfig_t autoAckConfig;
  
  autoAckConfig._0_4_ = ((uint)argc >> 8 & 0xff) << 8;
  autoAckConfig._4_4_ = 0x1010101;
  code = RAIL_ConfigAutoAck(railHandle,&autoAckConfig);
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
  undefined uVar3;
  
  uVar1 = ciGetUnsigned(argv[1]);
  uVar2 = ciGetUnsigned(argv[2]);
  uVar3 = (undefined)(uVar1 & 0xff);
  if ((uVar1 & 0xff) != 0) {
    uVar3 = true;
  }
  RAIL_PauseRxAutoAck(railHandle,(bool)uVar3);
  uVar3 = (undefined)(uVar2 & 0xff);
  if ((uVar2 & 0xff) != 0) {
    uVar3 = true;
  }
  RAIL_PauseTxAutoAck(railHandle,(bool)uVar3);
  getAutoAck(1,argv);
  return;
}



void setTxAckOptions(int argc,char **argv)

{
  char *pcVar1;
  char *pcVar2;
  uint32_t uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = ciGetUnsigned(argv[1]);
  uVar5 = uVar3 & 0xff;
  uVar3 = ciGetUnsigned(argv[2]);
  uVar4 = uVar3 & 0xff;
  afterRxUseTxBufferForAck = (_Bool)(char)uVar4;
  afterRxCancelAck = (_Bool)(char)uVar5;
  if (uVar5 != 0) {
    afterRxCancelAck = true;
  }
  if (uVar4 != 0) {
    afterRxUseTxBufferForAck = true;
  }
  pcVar2 = "txStatus:%s,transmitted:%u,lastTxTime:%u,failed:%u,lastTxStatus:0x%x,isAck:True";
  if (uVar4 == 0) {
    pcVar1 = "txStatus:%s,transmitted:%u,lastTxTime:%u,failed:%u,lastTxStatus:0x%x,isAck:False";
  }
  else {
    pcVar1 = "txStatus:%s,transmitted:%u,lastTxTime:%u,failed:%u,lastTxStatus:0x%x,isAck:True";
  }
  if (uVar5 == 0) {
    pcVar2 = "txStatus:%s,transmitted:%u,lastTxTime:%u,failed:%u,lastTxStatus:0x%x,isAck:False";
  }
  responsePrint(*argv,"CancelAck:%s,UseTxBuffer:%s",pcVar2 + 0x4b,pcVar1 + 0x4b);
  return;
}



void bleStatus(int argc,char **argv)

{
  bool bVar1;
  char *pcVar2;
  
  bVar1 = RAIL_BLE_IsEnabled(railHandle);
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
  _Var1 = inRadioState('\x01',*argv);
  if (_Var1 != false) {
    if (uVar2 == 0) {
      RAIL_BLE_Deinit(railHandle);
    }
    else {
      RAIL_BLE_Init(railHandle);
    }
    bleStatus(1,argv);
    return;
  }
  return;
}



void bleSet1MbpsPhy(int argc,char **argv)

{
  _Bool _Var1;
  RAIL_Status_t_enum status;
  uint32_t uVar2;
  char *pcVar3;
  undefined4 in_r3;
  char *command;
  
  if (argc == 2) {
    uVar2 = ciGetUnsigned(argv[1]);
    if (uVar2 != 0) {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  _Var1 = inRadioState('\x01',*argv);
  if (_Var1 != false) {
    if (uVar2 == 0) {
      status = RAIL_BLE_ConfigPhy1Mbps(railHandle);
    }
    else {
      status = RAIL_BLE_ConfigPhy1MbpsViterbi(railHandle);
    }
    command = *argv;
    pcVar3 = getStatusMessage(status);
    responsePrint(command,"Status:%s",pcVar3,in_r3);
    return;
  }
  return;
}



void bleSet2MbpsPhy(int argc,char **argv)

{
  _Bool _Var1;
  RAIL_Status_t_enum status;
  uint32_t uVar2;
  char *pcVar3;
  undefined4 in_r3;
  char *command;
  
  if (argc == 2) {
    uVar2 = ciGetUnsigned(argv[1]);
    if (uVar2 != 0) {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  _Var1 = inRadioState('\x01',*argv);
  if (_Var1 != false) {
    if (uVar2 == 0) {
      status = RAIL_BLE_ConfigPhy2Mbps(railHandle);
    }
    else {
      status = RAIL_BLE_ConfigPhy2MbpsViterbi(railHandle);
    }
    command = *argv;
    pcVar3 = getStatusMessage(status);
    responsePrint(command,"Status:%s",pcVar3,in_r3);
    return;
  }
  return;
}



void bleSetCoding(int argc,char **argv)

{
  _Bool _Var1;
  bool bVar2;
  RAIL_Status_t_enum status;
  uint32_t uVar3;
  char *pcVar4;
  undefined4 in_r3;
  char *command;
  
  _Var1 = inRadioState('\x01',*argv);
  if (_Var1 == false) {
    return;
  }
  bVar2 = RAIL_BLE_IsEnabled(railHandle);
  if (bVar2 == false) {
    responsePrintError(*argv,'1',"BLE mode not enabled",in_r3);
    return;
  }
  uVar3 = ciGetUnsigned(argv[1]);
  status = RAIL_BLE_ConfigPhyCoded(railHandle,(RAIL_BLE_Coding_t)uVar3);
  command = *argv;
  pcVar4 = getStatusMessage(status);
  responsePrint(command,"Status:%s",pcVar4,in_r3);
  return;
}



void bleSetChannelParams(int argc,char **argv)

{
  bool bVar1;
  RAIL_Status_t_enum RVar2;
  uint32_t uVar3;
  uint32_t crcInit;
  uint32_t uVar4;
  uint8_t code;
  char *pcVar5;
  uint uVar6;
  
  bVar1 = RAIL_BLE_IsEnabled(railHandle);
  if (bVar1 == false) {
    pcVar5 = "BLE mode not enabled";
    code = '1';
    goto LAB_00000bf8;
  }
  if (argc < 2) {
    uVar6 = 0x25;
LAB_00000c7a:
    crcInit = 0x555555;
    uVar3 = 0x8e89bed6;
LAB_00000c7e:
    uVar4 = 0;
  }
  else {
    uVar3 = ciGetUnsigned(argv[1]);
    uVar6 = uVar3 & 0xff;
    if (argc == 2) goto LAB_00000c7a;
    uVar3 = ciGetUnsigned(argv[2]);
    if (argc == 3) {
      crcInit = 0x555555;
      goto LAB_00000c7e;
    }
    crcInit = ciGetUnsigned(argv[3]);
    if (argc == 4) goto LAB_00000c7e;
    uVar4 = ciGetUnsigned(argv[4]);
    if (uVar4 != 0) {
      uVar4 = 1;
    }
  }
  RVar2 = RAIL_BLE_ConfigChannelRadioParams(railHandle,crcInit,uVar3,(uint16_t)uVar6,SUB41(uVar4,0))
  ;
  if (RVar2 == RAIL_STATUS_NO_ERROR) {
    if (uVar4 == 0) {
      pcVar5 = "Enabled";
    }
    else {
      pcVar5 = "Disabled";
    }
    responsePrint(*argv,"LogicalChannel:%d,AccessAddress:0x%0.8X,CrcInit:0x%0.8X,Whitening:%s",uVar6
                  ,uVar3,crcInit,pcVar5);
    return;
  }
  pcVar5 = "Setting channel parameters failed";
  code = '2';
LAB_00000bf8:
  responsePrintError(*argv,code,pcVar5);
  return;
}



void bleAdvertisingConfig(int argc,char **argv)

{
  bool bVar1;
  RAIL_Status_t_enum RVar2;
  uint32_t uVar3;
  uint8_t code;
  char *formatString;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar7;
  undefined4 *puVar6;
  
  uVar3 = ciGetUnsigned(argv[1]);
  bVar1 = RAIL_BLE_IsEnabled(railHandle);
  if (bVar1 == false) {
    formatString = "BLE mode not enabled";
    code = '1';
  }
  else {
    uVar7 = uVar3 & 0xff;
    if (uVar7 - 0x25 < 3) {
      RVar2 = RAIL_BLE_ConfigChannelRadioParams
                        (railHandle,0x555555,0x8e89bed6,(uint16_t)uVar7,false);
      uVar3 = (uint32_t)RVar2;
      if (uVar3 == 0) {
        if (uVar7 != 0x25) {
          if (uVar7 == 0x26) {
            uVar3 = 0xc;
          }
          else {
            uVar3 = 0x27;
          }
        }
        changeChannel(uVar3);
        responsePrint(*argv,"AdvertisingChannel:%d",uVar7);
        puVar4 = (undefined4 *)txData;
        puVar5 = (undefined4 *)blePacket;
        do {
          puVar6 = puVar5 + 1;
          *puVar4 = *puVar5;
          puVar4 = puVar4 + 1;
          puVar5 = puVar6;
        } while (puVar6 != (undefined4 *)
                           "LogicalChannel:%d,AccessAddress:0x%0.8X,CrcInit:0x%0.8X,Whitening:%s");
        txDataLen = 0x1c;
        printTxPacket(1,argv);
        return;
      }
      formatString = "Setting channel parameters failed";
      code = '2';
    }
    else {
      formatString = "Invalid advertising channel";
      code = '0';
    }
  }
  responsePrintError(*argv,code,formatString);
  return;
}



void setFrequency(int argc,char **argv)

{
  _Bool _Var1;
  RAIL_Status_t_enum RVar2;
  uint32_t freq;
  uint32_t uVar3;
  
  freq = ciGetUnsigned(argv[1]);
  _Var1 = inRadioState('\x01',*argv);
  if (_Var1 == false) {
    return;
  }
  uVar3 = RAIL_GetDebugMode(railHandle);
  if ((int)(uVar3 << 0x1f) < 0) {
    RVar2 = RAIL_OverrideDebugFrequency(railHandle,freq);
    if (RVar2 == RAIL_STATUS_NO_ERROR) {
      responsePrint(*argv,"NewFrequency:%u",freq);
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
  RAIL_Status_t_enum RVar1;
  uint32_t debugMode;
  char *pcVar2;
  
  debugMode = ciGetUnsigned(argv[1]);
  RVar1 = RAIL_SetDebugMode(railHandle,debugMode);
  if (RVar1 == RAIL_STATUS_NO_ERROR) {
    pcVar2 = lookupDebugModeString(debugMode);
    responsePrint(*argv,"DebugMode:%s",pcVar2);
    return;
  }
  responsePrintError(*argv,'\x15',"%d is an invalid debug mode!",debugMode);
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
  if (uVar1 != 0) {
    PeripheralEnable();
    return;
  }
  PeripheralDisable();
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
  uVar1 = RAIL_GetSymbolRate(railHandle);
  uVar2 = RAIL_GetBitRate(railHandle);
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
  uVar1 = RAIL_GetRadioEntropy(railHandle,randomDataBuffer,(uint16_t)uVar5);
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
  int iVar4;
  debugSignal_t *pdVar5;
  uint8_t uVar6;
  char *formatString;
  debugPin_t *pdVar7;
  uint32_t uVar8;
  debugPin_t *pdVar9;
  char *pcVar10;
  uint32_t numSignals;
  uint32_t numPins;
  debugSignal_t customSignal;
  
  pdVar2 = halGetDebugSignals(&numSignals);
  pdVar3 = halGetDebugPins(&numPins);
  if (argc < 2) {
LAB_000011c0:
    iprintf("%s [pin] [signal] [options]\n",*argv);
    iprintf("Pins: ");
    for (uVar8 = 0; numPins != uVar8; uVar8 = uVar8 + 1) {
      if (uVar8 != 0) {
        iprintf(", ");
      }
      iprintf("%s",pdVar3[uVar8].name);
    }
    puts("\nSignals: ");
    puts("  OFF\n  CUSTOM_PRS <source> <signal>\n  CUSTOM_LIB <event>");
    for (uVar8 = 0; numSignals != uVar8; uVar8 = uVar8 + 1) {
      iprintf("  %s\n",pdVar2[uVar8].name);
    }
    return;
  }
  pcVar10 = argv[1];
  iVar4 = strcasecmp(pcVar10,"help");
  if (iVar4 == 0) goto LAB_000011c0;
  uVar8 = 0;
  pdVar9 = (debugPin_t *)0x0;
  while (uVar8 != numPins) {
    pdVar7 = pdVar3 + uVar8;
    iVar4 = strcasecmp(pdVar3[uVar8].name,pcVar10);
    uVar8 = uVar8 + 1;
    if (iVar4 == 0) {
      pdVar9 = pdVar7;
    }
  }
  if (pdVar9 == (debugPin_t *)0x0) {
    formatString = "%s is not a valid pin name";
    uVar6 = 'P';
LAB_000011b8:
    responsePrintError(*argv,uVar6,formatString,pcVar10);
    return;
  }
  pcVar10 = argv[2];
  iVar4 = strcasecmp("CUSTOM_LIB",pcVar10);
  if (iVar4 == 0) {
    if ((argc != 4) || (_Var1 = ciValidateInteger(argv[3],'w'), _Var1 == false)) {
      pcVar10 = "Invalid parameters passed to CUSTOM_LIB";
      uVar6 = 'Q';
      goto LAB_00001252;
    }
    customSignal.name = "CUSTOM_LIB";
    customSignal.isPrs = false;
    uVar8 = ciGetUnsigned(argv[3]);
    customSignal.loc = (undefined2)uVar8;
LAB_00001276:
    pdVar5 = &customSignal;
LAB_00001278:
    CMU_ClockEnable(cmuClock_GPIO,true);
    GPIO_PinModeSet(pdVar9->gpioPort,(uint)pdVar9->gpioPin,gpioModeDisabled,0);
    if (iVar4 != 0) {
      halDisablePrs(pdVar9->prsChannel);
      responsePrint(*argv,"Pin:%s,Signal:OFF",pdVar9->name);
      return;
    }
    if (pdVar5 == (debugSignal_t *)0x0) {
      return;
    }
    if (pdVar5->isPrs != false) {
      halEnablePrs(pdVar9->prsChannel,pdVar9->prsLocation,*(uint8_t *)((int)&pdVar5->loc + 1),
                   *(uint8_t *)&pdVar5->loc);
    }
    GPIO_PinModeSet(pdVar9->gpioPort,(uint)pdVar9->gpioPin,gpioModePushPull,0);
    responsePrint(*argv,"Pin:%s,Signal:%s",pdVar9->name,pdVar5->name);
    return;
  }
  iVar4 = strcasecmp("CUSTOM_PRS",pcVar10);
  if (iVar4 != 0) {
    pdVar5 = (debugSignal_t *)strcasecmp("OFF",pcVar10);
    if (pdVar5 == (debugSignal_t *)0x0) {
      iVar4 = 1;
    }
    else {
      pdVar5 = (debugSignal_t *)0x0;
      for (uVar8 = 0; numSignals != uVar8; uVar8 = uVar8 + 1) {
        iVar4 = strcasecmp(pdVar2[uVar8].name,pcVar10);
        if (iVar4 == 0) {
          pdVar5 = pdVar2 + uVar8;
        }
      }
      if (pdVar5 == (debugSignal_t *)0x0) {
        formatString = "%s is not a valid signal name";
        uVar6 = 'T';
        goto LAB_000011b8;
      }
      iVar4 = 0;
    }
    goto LAB_00001278;
  }
  if (argc == 5) {
    _Var1 = ciValidateInteger(argv[3],'u');
    if ((_Var1 != false) && (_Var1 = ciValidateInteger(argv[4],'u'), _Var1 != false)) {
      customSignal.isPrs = true;
      customSignal.name = "CUSTOM_PRS";
      uVar8 = ciGetUnsigned(argv[3]);
      customSignal.loc._1_1_ = (undefined)uVar8;
      uVar8 = ciGetUnsigned(argv[4]);
      customSignal.loc = CONCAT11(customSignal.loc._1_1_,(char)uVar8);
      goto LAB_00001276;
    }
  }
  pcVar10 = "Invalid parameters passed to CUSTOM_PRS";
  uVar6 = 'S';
LAB_00001252:
  responsePrintError(*argv,uVar6,pcVar10);
  return;
}



void forceAssert(int argc,char **argv)

{
  uint32_t errorCode;
  
  errorCode = ciGetUnsigned(argv[1]);
  responsePrint(*argv,"code:%d",errorCode);
  RAILCb_AssertFailed(railHandle,errorCode);
  return;
}



void configPrintEvents(int argc,char **argv)

{
  enablePrintEvents = ciGetUnsigned(argv[1]);
  responsePrint(*argv,"enablePrintEvents:0x%x",enablePrintEvents);
  return;
}



void getAppMode(int argc,char **argv)

{
  AppMode_t AVar1;
  char *command;
  
  command = *argv;
  AVar1 = currentAppMode();
  responsePrint(command,"appMode:%s",(uint)AVar1);
  return;
}



void getRadioState(int argc,char **argv)

{
  RAIL_RadioState_t_enum state;
  char *pcVar1;
  char *command;
  
  command = *argv;
  state = RAIL_GetRadioState();
  pcVar1 = getRfStateName(state);
  responsePrint(command,"radioState:%s",pcVar1);
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
      RAIL_SetTimer(railHandle,perDelay,'\x01',0x35dd);
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
  float in_s0;
  float f;
  float f_00;
  float f_01;
  char bufRssiMean [10];
  char bufRssiMin [10];
  char bufRssiMax [10];
  char bufRssiVariance [10];
  
  sprintfFloat(bufRssiMean,'\n',in_s0,SUB41(counters.rssi.mean * 0.25,0));
  sprintfFloat(bufRssiMin,'\n',f,SUB41((float)(longlong)counters.rssi.min * 0.25,0));
  sprintfFloat(bufRssiMax,'\n',f_00,SUB41((float)(longlong)counters.rssi.max * 0.25,0));
  sprintfFloat(bufRssiVariance,'\n',f_01,
               SUB41((counters.rssi.varianceTimesSamples /
                     (float)(ulonglong)(counters.rssi.samples - 1)) * 0.0625,0));
  responsePrint(*argv,"PerTriggers:%u,RssiMean:%s,RssiMin:%s,RssiMax:%s,RssiVariance:%s",
                counters.perTriggers,bufRssiMean,bufRssiMin,bufRssiMax,bufRssiVariance);
  return;
}



void berResetStats(uint32_t numBytes)

{
  if (0x1ffffffe < numBytes - 1) {
    numBytes = 0x1fffffff;
  }
  berStats.bytesTotal = numBytes;
  berStats.bytesTested = 0;
  berStats.bitErrors = 0;
  berStats._12_4_ = 0;
  return;
}



void berConfigSet(int argc,char **argv)

{
  RAIL_Status_t_enum code;
  uint32_t numBytes;
  undefined4 in_r3;
  
  RAIL_Idle(railHandle,RAIL_IDLE_ABORT,true);
  RAIL_ResetFifo(railHandle,true,true);
  railDataConfig.txSource = '\0';
  railDataConfig.rxSource = '\0';
  railDataConfig.txMethod = '\x01';
  railDataConfig.rxMethod = '\x01';
  code = RAIL_ConfigData(railHandle,&railDataConfig);
  if (code != RAIL_STATUS_NO_ERROR) {
    responsePrintError(*argv,code,"Error calling RAIL_ConfigData().");
  }
  RAIL_SetRxFifoThreshold(railHandle,100);
  RAIL_SetFixedLength(railHandle,0);
  RAIL_EnablePti(railHandle,false);
  numBytes = ciGetUnsigned(argv[1]);
  berBytesToTest = numBytes;
  berResetStats(numBytes);
  responsePrint(*argv,"NumBytes:%d",numBytes,in_r3);
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
    RAIL_Idle(railHandle,RAIL_IDLE_ABORT,true);
    RAIL_ResetFifo(railHandle,true,true);
    if (uVar2 != 0) {
      RAIL_EnablePti(railHandle,false);
      berResetStats(berBytesToTest);
      berTestModeEnabled = true;
      RAIL_StartRx(railHandle,channel,(undefined *)0x0);
      return;
    }
  }
  return;
}



void berStatusGet(int argc,char **argv)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint8_t precision;
  uint8_t precision_00;
  CORE_irqState_t irqState;
  int iVar4;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float f;
  float f_00;
  undefined8 uVar5;
  undefined8 uVar6;
  char bufPercentDone [10];
  char bufPercentBitError [10];
  
  irqState = CORE_EnterCritical();
  uVar3 = berStats.bitErrors;
  uVar2 = berStats.bytesTested;
  uVar1 = berStats.bytesTotal;
  iVar4 = (int)berStats.rssi;
  CORE_ExitCritical(irqState);
  if (uVar1 == 0) {
    precision = '\0';
    f = extraout_s0;
  }
  else {
    uVar5 = __floatunsidf(uVar2);
    uVar6 = __floatunsidf(uVar1);
    uVar5 = __divdf3((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),(int)uVar6,
                     (int)((ulonglong)uVar6 >> 0x20));
    __muldf3((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40590000);
    precision = __truncdfsf2();
    f = extraout_s0_00;
  }
  if (uVar2 == 0) {
    precision_00 = '\0';
  }
  else {
    uVar5 = __floatunsidf(uVar3);
    uVar6 = __floatunsidf(uVar2 << 3);
    uVar5 = __divdf3((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),(int)uVar6,
                     (int)((ulonglong)uVar6 >> 0x20));
    __muldf3((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40590000);
    precision_00 = __truncdfsf2();
    f = extraout_s0_01;
  }
  if (counters.rxOfEvent == 0) {
    sprintfFloat(bufPercentDone,'\n',f,precision);
    sprintfFloat(bufPercentBitError,'\n',f_00,precision_00);
    responsePrint(*argv,
                  "BitsToTest:%u,BitsTested:%u,PercentDone:%s,RSSI:%d,BitErrors:%u,PercentBitError:%s"
                  ,uVar1 << 3,uVar2 << 3,bufPercentDone,iVar4,uVar3,bufPercentBitError);
  }
  else {
    responsePrint(*argv,
                  "BitsToTest:%u,BitsTested:0,PercentDone:0.00,RSSI:%d,BitErrors:0,PercentBitError:0.00,Status:TestAbortedRxOverflow"
                  ,uVar1 << 3,iVar4);
  }
  return;
}



char * getRfStateName(RAIL_RadioState_t state)

{
  char *pcVar1;
  
  if (state < 6) {
    pcVar1 = (&CSWTCH_29)[state];
  }
  else {
    pcVar1 = "Unknown";
  }
  return pcVar1;
}



char * getStatusMessage(RAIL_Status_t status)

{
  char *pcVar1;
  
  if (status < 4) {
    pcVar1 = (&CSWTCH_32)[status];
  }
  else {
    pcVar1 = "Unknown";
  }
  return pcVar1;
}



void getStatus(int argc,char **argv)

{
  char **ppcVar1;
  RAIL_RadioState_t_enum RVar2;
  AppMode_t appMode;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  
  responsePrintStart(*argv);
  responsePrintContinue
            ("UserTxCount:%u,AckTxCount:%u,UserTxAborted:%u,AckTxAborted:%u,UserTxBlocked:%u,AckTxBlocked:%u,UserTxUnderflow:%u,AckTxUnderflow:%u,RxCount:%u,SyncDetect:%u,NoRxBuffer:%u,RfSensed:%u,ackTimeout:%u"
             ,counters.userTx,counters.ackTx,counters.userTxAborted,counters.ackTxAborted,
             counters.userTxBlocked,counters.ackTxBlocked,counters.userTxUnderflow,
             counters.ackTxUnderflow,counters.receive,counters.syncDetect,counters.noRxBuffer,
             counters.rfSensedEvent,counters.ackTimeout);
  RVar2 = RAIL_GetRadioState();
  uVar4 = (uint)RVar2;
  if (uVar4 < 6) {
    pcVar3 = (&CSWTCH_29)[uVar4];
  }
  else {
    pcVar3 = "Unknown";
  }
  responsePrintContinue("RfState:%s",pcVar3);
  iVar5 = 0;
  do {
    ppcVar1 = printRailState::railStates + iVar5;
    iVar5 = iVar5 + 1;
    responsePrintContinue("%s:%u",*ppcVar1,uVar4 & 1);
    uVar4 = uVar4 >> 1;
  } while (iVar5 != 3);
  uVar4 = (uint)channel;
  appMode = currentAppMode();
  pcVar3 = appModeNames(appMode);
  responsePrintEnd("Channel:%u,AppMode:%s,TimingLost:%u,TimingDetect:%u,FrameErrors:%u,RxOverflow:%u,AddrFilt:%u,Aborted:%u,Calibrations:%u,TxChannelBusy:%u,TxClear:%u,TxCca:%u,TxRetry:%u"
                   ,uVar4,pcVar3,counters.timingLost,counters.timingDetect,counters.frameError,
                   counters.rxOfEvent,counters.addrFilterEvent,counters.rxFail,counters.calibrations
                   ,counters.txChannelBusy,counters.lbtSuccess,counters.lbtStartCca,
                   counters.lbtRetry);
  return;
}



void fifoStatus(int argc,char **argv)

{
  uint16_t uVar1;
  uint16_t uVar2;
  uint16_t uVar3;
  uint16_t uVar4;
  char *command;
  
  uVar1 = RAIL_GetTxFifoSpaceAvailable(railHandle);
  uVar2 = RAIL_GetRxFifoBytesAvailable(railHandle);
  command = *argv;
  uVar3 = RAIL_GetTxFifoThreshold(railHandle);
  uVar4 = RAIL_GetRxFifoThreshold(railHandle);
  responsePrint(command,
                "TxSpaceCount:%u,RxByteCount:%u,TxFifoThreshold:%d,RxFifoThreshold:%d,TxFifoAlmostEmpty:%u,RxFifoAlmostFull:%u,RxOverflow:%u,UserTxUnderflow:%u,AckTxUnderflow:%u"
                ,(uint)uVar1,(uint)uVar2,(uint)uVar3,(uint)uVar4,counters.txFifoAlmostEmpty,
                counters.rxFifoAlmostFull,counters.rxOfEvent,counters.userTxUnderflow,
                counters.ackTxUnderflow);
  return;
}



void getVersion(int argc,char **argv)

{
  char *pcVar1;
  RAIL_Version_t rail_ver;
  
  RAIL_GetVersion(&rail_ver,false);
  pcVar1 = "txStatus:%s,transmitted:%u,lastTxTime:%u,failed:%u,lastTxStatus:0x%x,isAck:True";
  if (rail_ver.multiprotocol == false) {
    pcVar1 = "txStatus:%s,transmitted:%u,lastTxTime:%u,failed:%u,lastTxStatus:0x%x,isAck:False";
  }
  responsePrint(*argv,"App:%d.%d.%d,RAIL:%d.%d.%d,Multiprotocol:%s",(uint)rail_ver.major,
                (uint)rail_ver.minor,(uint)rail_ver.rev,(uint)rail_ver.major,(uint)rail_ver.minor,
                (uint)rail_ver.rev,pcVar1 + 0x4b);
  return;
}



void setPtiProtocol(int argc,char **argv)

{
  RAIL_Handle_t railHandle;
  RAIL_Status_t_enum RVar1;
  uint32_t uVar2;
  char *pcVar3;
  undefined4 in_r3;
  
  railHandle = ::railHandle;
  uVar2 = ciGetUnsigned(argv[1]);
  RVar1 = RAIL_SetPtiProtocol(railHandle,(RAIL_PtiProtocol_t)uVar2);
  pcVar3 = "Error";
  if (RVar1 == RAIL_STATUS_NO_ERROR) {
    pcVar3 = "Set";
  }
  responsePrint(*argv,"Pti:%s",pcVar3,in_r3);
  return;
}



void getVersionVerbose(int argc,char **argv)

{
  RAIL_Version_t rail_ver;
  
  RAIL_GetVersion(&rail_ver,true);
  responsePrint(*argv,"App:%d.%d.%d,RAIL:%d.%d.%d.%d",(uint)rail_ver.major,(uint)rail_ver.minor,
                (uint)rail_ver.rev,(uint)rail_ver.major,(uint)rail_ver.minor,(uint)rail_ver.rev,
                (uint)rail_ver.build);
  responsePrint(*argv,"hash:0x%.8X,flags:0x%.2X",rail_ver.hash,(uint)rail_ver.flags);
  return;
}



// WARNING: Could not reconcile some variable overlaps

void getRssi(int argc,char **argv)

{
  int16_t iVar1;
  uint32_t uVar2;
  float f;
  undefined4 uVar3;
  char bufRssi [10];
  
  bufRssi._0_4_ = argv;
  if (argc == 2) {
    uVar2 = ciGetUnsigned(argv[1]);
    if (uVar2 != 0) {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  iVar1 = RAIL_GetRssi(railHandle,SUB41(uVar2,0));
  if (iVar1 == -0x200) {
    responsePrintError(*argv,'\b',"Could not read RSSI. Ensure Rx is enabled");
  }
  else {
    uVar3 = FixedToFP((int)iVar1,0x20,0x20,2,0,0);
    sprintfFloat(bufRssi,'\n',f,(uint8_t)uVar3);
    responsePrint(*argv,"rssi:%s",bufRssi);
  }
  return;
}



void startAvgRssi(int argc,char **argv)

{
  _Bool _Var1;
  RAIL_Status_t_enum RVar2;
  uint32_t averagingTimeUs;
  uint32_t uVar3;
  char *formatString;
  undefined4 in_r3;
  uint16_t channel;
  
  averagingTimeUs = ciGetUnsigned(argv[1]);
  channel = (uint16_t)(byte)::channel;
  if (argc == 3) {
    uVar3 = ciGetUnsigned(argv[2]);
    channel = (ushort)uVar3 & 0xff;
  }
  _Var1 = inRadioState('\x01',(char *)0x0);
  if (_Var1 == false) {
    formatString = "Could not read RSSI. Ensure RX is disabled.";
  }
  else {
    RVar2 = RAIL_StartAverageRssi(railHandle,channel,averagingTimeUs,(undefined *)0x0);
    if (RVar2 == RAIL_STATUS_NO_ERROR) {
      return;
    }
    formatString = "Could not read RSSI.";
  }
  responsePrintError(*argv,'\b',formatString,in_r3);
  return;
}



// WARNING: Could not reconcile some variable overlaps

void getAvgRssi(int argc,char **argv)

{
  int16_t iVar1;
  float f;
  undefined4 uVar2;
  char bufRssi [10];
  
  bufRssi._0_4_ = argv;
  iVar1 = RAIL_GetAverageRssi(railHandle);
  if (iVar1 == -0x200) {
    responsePrintError(*argv,'\b',"Invalid RSSI. Make sure startAvgRssi ran successfully.");
  }
  else {
    uVar2 = FixedToFP((int)iVar1,0x20,0x20,2,0,0);
    sprintfFloat(bufRssi,'\n',f,(uint8_t)uVar2);
    responsePrint(*argv,"rssi:%s",bufRssi);
  }
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
  while( true ) {
    uVar5 = RAIL_GetTime();
    if (uVar4 + 5000000 <= uVar5) break;
    RAIL_StopTxStream(railHandle);
    RAIL_Idle(railHandle,RAIL_IDLE_ABORT,false);
    RAIL_SetTxPower(railHandle,(ushort)uVar1 & 0xff);
    RAIL_StartTxStream(railHandle,channel,RAIL_STREAM_CARRIER_WAVE);
    usDelay(uVar3 / 2);
    RAIL_StopTxStream(railHandle);
    RAIL_Idle(railHandle,RAIL_IDLE_ABORT,false);
    RAIL_SetTxPower(railHandle,(ushort)uVar2 & 0xff);
    RAIL_StartTxStream(railHandle,channel,RAIL_STREAM_CARRIER_WAVE);
    usDelay(uVar3 / 2);
  }
  RAIL_StopTxStream(railHandle);
  return;
}



void resetCounters(int argc,char **argv)

{
  memset(&counters,0,0x88);
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
  RAIL_Status_t_enum RVar1;
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
  int iVar1;
  undefined4 in_r3;
  RAIL_CsmaConfig_t **ppRVar2;
  char *pcVar3;
  
  if (1 < argc) {
    pcVar3 = argv[1];
    iVar1 = memcmp(pcVar3,"off",3);
    if (iVar1 == 0) {
      txType = TX_TYPE_NORMAL;
    }
    else {
      iVar1 = memcmp(pcVar3,&DAT_000128fd,4);
      if (iVar1 == 0) {
        txType = TX_TYPE_CSMA;
        ppRVar2 = &csmaConfig;
      }
      else {
        iVar1 = memcmp(pcVar3,"lbt",3);
        if (iVar1 != 0) {
          responsePrintError(*argv,'p',"Unknown LBT mode specified.",in_r3);
          return;
        }
        txType = TX_TYPE_LBT;
        ppRVar2 = (RAIL_CsmaConfig_t **)&lbtConfig;
      }
      *ppRVar2 = (RAIL_CsmaConfig_t *)&lbtParams;
    }
  }
  if (txType == TX_TYPE_NORMAL) {
    pcVar3 = "LbtMode:off";
  }
  else {
    if (txType == TX_TYPE_CSMA) {
      pcVar3 = "LbtMode:CSMA";
    }
    else {
      if (txType != TX_TYPE_LBT) {
        return;
      }
      pcVar3 = "LbtMode:LBT";
    }
  }
  responsePrint(*argv,pcVar3);
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
  printPacket(*argv,txData,txDataLen,(RxPacketData_t *)0x0);
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
      if (railDataConfig.txMethod == '\0') {
        RAIL_WriteTxFifo(railHandle,txData,txDataLen,true);
      }
      printTxPacket(1,argv);
      return;
    }
    uVar2 = ciGetUnsigned(argv[iVar4]);
    if (0x1f7 < ((uVar1 & 0xffff) - 2) + iVar4) break;
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
  if (0x1f8 < uVar1) {
    responsePrintError(*argv,'\x06',"Invalid length %d",uVar1);
    return;
  }
  txDataLen = (uint16_t)uVar1;
  if (railDataConfig.txMethod == '\0') {
    RAIL_WriteTxFifo(railHandle,txData,txDataLen,true);
  }
  responsePrint(*argv,"TxLength:%d",(uint)txDataLen);
  return;
}



void printAckPacket(int argc,char **argv)

{
  printPacket(*argv,ackData,(ushort)ackDataLen,(RxPacketData_t *)0x0);
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
      RAIL_WriteAutoAckFifo(railHandle,ackData,ackDataLen);
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
  ackDataLen = (uint8_t)uVar1;
  RAIL_WriteAutoAckFifo(railHandle,ackData,ackDataLen);
  responsePrint(*argv,"TxLength:%d",(uint)ackDataLen);
  return;
}



void setFixedLength(int argc,char **argv)

{
  _Bool _Var1;
  uint16_t rxLength;
  uint32_t uVar2;
  undefined4 in_r3;
  
  _Var1 = inAppMode(NONE,*argv);
  if ((_Var1 != false) && (_Var1 = inRadioState('\x01',*argv), _Var1 != false)) {
    uVar2 = ciGetUnsigned(argv[1]);
    rxLength = RAIL_SetFixedLength(railHandle,(uint16_t)uVar2);
    configRxLengthSetting(rxLength);
    responsePrint(*argv,"FixedLength:%d",(uint)rxLength,in_r3);
    return;
  }
  return;
}



void dataConfig(int argc,char **argv)

{
  _Bool _Var1;
  RAIL_Status_t_enum RVar2;
  int iVar3;
  char *pcVar4;
  
  _Var1 = inAppMode(NONE,*argv);
  if ((_Var1 == false) || (_Var1 = inRadioState('\x01',*argv), _Var1 == false)) {
    return;
  }
  pcVar4 = argv[1];
  railDataConfig.txSource = '\0';
  railDataConfig.rxSource = '\0';
  iVar3 = memcmp(pcVar4,&DAT_0001295b,3);
  if (iVar3 == 0) {
    railDataConfig.txMethod = '\0';
  }
  else {
    iVar3 = memcmp(pcVar4,"fifo",4);
    if (iVar3 == 0) {
      railDataConfig.txMethod = '\x01';
    }
    else {
      responsePrintError(*argv,'P',"Invalid Data Method selection.");
    }
  }
  pcVar4 = argv[2];
  iVar3 = memcmp(pcVar4,&DAT_0001295b,3);
  if (iVar3 == 0) {
    railDataConfig.rxMethod = '\0';
  }
  else {
    iVar3 = memcmp(pcVar4,"fifo",4);
    if (iVar3 == 0) {
      railDataConfig.rxMethod = '\x01';
    }
    else {
      responsePrintError(*argv,'P',"Invalid Data Method selection.");
    }
  }
  RVar2 = RAIL_ConfigData(railHandle,&railDataConfig);
  if (RVar2 != 0) {
    responsePrintError(*argv,'P',"Failed to successfully call RAIL_DataConfig: %d",(uint)RVar2);
    return;
  }
  responsePrint(*argv,"TxMethod:%s,RxMethod:%s",argv[1],argv[2]);
  return;
}



void fifoModeTestOptions(int argc,char **argv)

{
  uint32_t uVar1;
  char *outputStr [2];
  
  outputStr[0] = "Disabled";
  outputStr[1] = "Enabled";
  uVar1 = ciGetUnsigned(argv[1]);
  if (uVar1 != 0) {
    uVar1 = 1;
  }
  txFifoManual = (_Bool)(char)uVar1;
  uVar1 = ciGetUnsigned(argv[2]);
  if (uVar1 != 0) {
    uVar1 = 1;
  }
  rxFifoManual = (_Bool)(char)uVar1;
  responsePrint(*argv,"TxFifoManual:%s,RxFifoManual:%s",outputStr[txFifoManual],outputStr[uVar1]);
  return;
}



void rxFifoManualRead(int argc,char **argv)

{
  RAIL_Status_t_enum RVar1;
  uint16_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  void *handle;
  RAIL_RxPacketDetails_t *pPacketDetails;
  
  if (rxFifoManual == false) {
    responsePrintError(*argv,'Q',"Must be in rx fifo manual mode (fifoModeTestOptions).");
    return;
  }
  uVar3 = ciGetUnsigned(argv[1]);
  uVar4 = ciGetUnsigned(argv[2]);
  handle = memoryAllocate(uVar4 & 0xffff);
  pPacketDetails = (RAIL_RxPacketDetails_t *)memoryPtrFromHandle(handle);
  if (pPacketDetails == (RAIL_RxPacketDetails_t *)0x0) {
    RAIL_ReleaseRxPacket(railHandle,FUN_00000000 + 1);
LAB_00002100:
    memoryFree(handle);
    return;
  }
  uVar2 = RAIL_ReadRxFifo(railHandle,
                          (uint8_t *)((int)&pPacketDetails[1].timeReceived.packetTime + 2),
                          (uint16_t)uVar4);
  *(uint16_t *)&pPacketDetails[1].timeReceived.packetTime = uVar2;
  if (uVar3 != 0) {
    (pPacketDetails->timeReceived).timePosition = '\x01';
    (pPacketDetails->timeReceived).totalPacketBytes = 0;
    RVar1 = RAIL_GetRxPacketDetails(railHandle,FUN_00000000 + 1,pPacketDetails);
    RAIL_ReleaseRxPacket(railHandle,FUN_00000000 + 1);
    if (RVar1 != RAIL_STATUS_NO_ERROR) {
      memset(pPacketDetails,0,0x14);
      pPacketDetails->rssi = -0x80;
      if (*(short *)&pPacketDetails[1].timeReceived.packetTime == 0) {
        responsePrintError(*argv,'R',"No packet found in rx fifo!");
        goto LAB_00002100;
      }
    }
  }
  queueAdd(&rxPacketQueue,handle);
  return;
}



void fifoReset(int argc,char **argv)

{
  uint32_t uVar1;
  uint32_t uVar2;
  char *outputStr [2];
  
  outputStr[0] = "DoNothing";
  outputStr[1] = "Reset";
  uVar1 = ciGetUnsigned(argv[1]);
  if (uVar1 != 0) {
    uVar1 = 1;
  }
  uVar2 = ciGetUnsigned(argv[2]);
  if (uVar2 != 0) {
    uVar2 = 1;
  }
  RAIL_ResetFifo(railHandle,SUB41(uVar1,0),SUB41(uVar2,0));
  responsePrint(*argv,"TxFifo:%s,RxFifo:%s",outputStr[uVar1],outputStr[uVar2]);
  return;
}



void txFifoManualLoad(int argc,char **argv)

{
  if (txFifoManual == false) {
    responsePrintError(*argv,'Q',"Must be in tx fifo manual mode (fifoModeTestOptions).");
    return;
  }
  loadTxData(txData,txDataLen);
  responsePrint(*argv,"Status:Fifo Written");
  return;
}



void abortRxPacket(int argc,char **argv)

{
  abortRxDelay = ciGetUnsigned(argv[1]);
  responsePrint(*argv,"TimeAfterSyncToAbort:%d",abortRxDelay);
  return;
}



void peekRx(int argc,char **argv)

{
  uint16_t uVar1;
  uint32_t uVar2;
  uint8_t code;
  char *formatString;
  uint uVar3;
  uint8_t pDst [10];
  
  uVar2 = ciGetUnsigned(argv[1]);
  uVar3 = uVar2 & 0xffff;
  if (uVar3 < 0xb) {
    if (argc < 3) {
      uVar1 = 0;
    }
    else {
      uVar2 = ciGetUnsigned(argv[2]);
      uVar1 = (uint16_t)uVar2;
    }
    uVar1 = RAIL_PeekRxPacket(railHandle,FUN_00000000 + 1,pDst,(uint16_t)uVar3,uVar1);
    if (uVar1 == uVar3) {
      printPacket(*argv,pDst,(uint16_t)uVar3,(RxPacketData_t *)0x0);
      return;
    }
    formatString = "Requested bytes not in receive buffer";
    code = 'S';
  }
  else {
    formatString = "Can\'t peek more than 10 bytes";
    code = 'R';
  }
  responsePrintError(*argv,code,formatString);
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
LAB_000022f8:
      states[iVar2] = '\x04';
    }
    else {
      if (bVar1 < 0x55) {
        if (bVar1 == 0x49) {
LAB_000022ea:
          states[iVar2] = '\x01';
          goto LAB_000022ec;
        }
        if (bVar1 != 0x52) {
          return '\x01';
        }
      }
      else {
        if (bVar1 != 0x72) {
          if (bVar1 == 0x74) goto LAB_000022f8;
          if (bVar1 != 0x69) {
            return '\x01';
          }
          goto LAB_000022ea;
        }
      }
      states[iVar2] = '\x02';
    }
LAB_000022ec:
    if (iVar2 != 0) {
      return '\0';
    }
    iVar2 = 1;
  } while( true );
}



void getChannel(int argc,char **argv)

{
  uint32_t uVar1;
  
  uVar1 = RAIL_GetDebugMode(railHandle);
  if ((int)(uVar1 << 0x1f) < 0) {
    responsePrintError(*argv,'\x12',"Channels are not valid in Debug Mode");
    return;
  }
  responsePrint(*argv,"channel:%d",(uint)channel);
  return;
}



void setChannel(int argc,char **argv)

{
  RAIL_Status_t_enum RVar1;
  uint32_t i;
  
  i = ciGetUnsigned(argv[1]);
  RVar1 = RAIL_IsValidChannel(railHandle,(uint16_t)i);
  if (RVar1 != RAIL_STATUS_NO_ERROR) {
    responsePrintError(*argv,'\x11',"Invalid channel \'%d\'",i);
    return;
  }
  changeChannel(i);
  getChannel(1,argv);
  return;
}



void getPower(int argc,char **argv)

{
  byte bVar1;
  RAIL_TxPower_t RVar2;
  char *command;
  
  command = *argv;
  bVar1 = RAIL_GetTxPower(railHandle);
  RVar2 = RAIL_GetTxPowerDbm(railHandle);
  responsePrint(command,"powerLevel:%d,power:%d",(uint)bVar1,(int)RVar2);
  return;
}



void setPower(int argc,char **argv)

{
  RAIL_Handle_t railHandle;
  _Bool _Var1;
  RAIL_TxPower_t RVar2;
  int iVar3;
  uint32_t uVar4;
  uint uVar5;
  int32_t iVar6;
  char *arg;
  
  _Var1 = inRadioState('\x01',*argv);
  railHandle = ::railHandle;
  if (_Var1 != false) {
    arg = argv[1];
    if ((argc < 3) || (iVar3 = strcmp(argv[2],"raw"), iVar3 != 0)) {
      iVar6 = ciGetSigned(arg);
      RAIL_SetTxPowerDbm(railHandle,(RAIL_TxPower_t)iVar6);
    }
    else {
      uVar4 = ciGetUnsigned(arg);
      RAIL_SetTxPower(railHandle,(ushort)uVar4 & 0xff);
    }
    lastSetTxPowerLevel = RAIL_GetTxPower(::railHandle);
    uVar5 = (uint)lastSetTxPowerLevel;
    RVar2 = RAIL_GetTxPowerDbm(::railHandle);
    responsePrint(*argv,"powerLevel:%d,power:%d",uVar5,(int)RVar2);
    return;
  }
  return;
}



// WARNING: Could not reconcile some variable overlaps

void sweepTxPower(int argc,char **argv)

{
  uint uVar1;
  uint8_t code;
  char *formatString;
  uint uVar2;
  uint uVar3;
  RAIL_TxPowerConfig_t txPowerConfig;
  
  txPowerConfig._0_4_ = argc;
  unique0x10000089 = argv;
  responsePrint(*argv,"Sweeping:Started,Instructions:\'q\' to quit or \'enter\' to continue.");
  RAIL_GetTxPowerConfig(railHandle,&txPowerConfig);
  uVar2 = txPowerConfig._0_4_ & 0xff;
  if (uVar2 == 1) {
    uVar2 = 7;
  }
  else {
    if (uVar2 == 0) {
      uVar2 = 0xfc;
    }
    else {
      if (uVar2 != 2) {
        formatString = "PA not configured.";
        code = '!';
LAB_00002452:
        responsePrintError(*argv,code,formatString);
        return;
      }
      uVar2 = 0xf8;
    }
  }
  uVar3 = 1;
  do {
    responsePrint(*argv,"PowerLevel:%u",uVar3);
    RAIL_Idle(railHandle,RAIL_IDLE_FORCE_SHUTDOWN_CLEAR_FLAGS,true);
    RAIL_SetTxPower(railHandle,(ushort)uVar3 & 0xff);
    RAIL_StartTxStream(railHandle,channel,RAIL_STREAM_CARRIER_WAVE);
    while( true ) {
      uVar1 = getchar();
      if ((uVar1 & 0xff) == 10) break;
      if ((uVar1 & 0xff) == 0x71) {
        formatString = "Sweep Aborted.";
        code = ' ';
        goto LAB_00002452;
      }
    }
    uVar3 = uVar3 + 1;
    RAIL_Idle(railHandle,RAIL_IDLE_FORCE_SHUTDOWN_CLEAR_FLAGS,true);
    if (uVar2 < (uVar3 & 0xff)) {
      responsePrint(*argv,"Sweeping:Complete");
      return;
    }
  } while( true );
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
  
  uVar1 = RAIL_GetTune(railHandle);
  responsePrint(*argv,"CTUNE:0x%.3x",uVar1);
  return;
}



void setCtune(int argc,char **argv)

{
  RAIL_Handle_t railHandle;
  _Bool _Var1;
  uint32_t tune;
  
  _Var1 = inRadioState('\x01',*argv);
  railHandle = ::railHandle;
  if (_Var1 != false) {
    tune = ciGetUnsigned(argv[1]);
    RAIL_SetTune(railHandle,tune);
    getCtune(1,argv);
    return;
  }
  return;
}



void setPaCtune(int argc,char **argv)

{
  RAIL_Status_t_enum code;
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar1 = ciGetUnsigned(argv[1]);
  uVar2 = ciGetUnsigned(argv[2]);
  code = RAIL_SetPaCTune(railHandle,(uint8_t)(uVar1 & 0xff),(uint8_t)(uVar2 & 0xff));
  if (code == RAIL_STATUS_NO_ERROR) {
    responsePrint(*argv,"PACTUNETX:%d,PACTUNERX:%d",uVar1 & 0xff,uVar2 & 0xff);
    return;
  }
  responsePrintError(*argv,code,"Error");
  return;
}



void enablePaCal(int argc,char **argv)

{
  uint32_t uVar1;
  char *pcVar2;
  undefined4 in_r3;
  undefined enable;
  uint uVar3;
  
  uVar1 = ciGetUnsigned(argv[1]);
  uVar3 = uVar1 & 0xff;
  enable = (undefined)uVar3;
  if (uVar3 != 0) {
    enable = true;
  }
  RAIL_EnablePaCal((bool)enable);
  pcVar2 = "Enabled";
  if (uVar3 == 0) {
    pcVar2 = "Disabled";
  }
  responsePrint(*argv,"paCal:%s",pcVar2,in_r3);
  return;
}



// WARNING: Could not reconcile some variable overlaps

void setTxTransitions(int argc,char **argv)

{
  int8_t iVar1;
  RAIL_Status_t_enum RVar2;
  char *pcVar3;
  RAIL_RadioState_t states [2];
  RAIL_StateTransitions_t transitions;
  
  _states = argc;
  _transitions = argv;
  iVar1 = stringsToStates(argv + 1,states);
  if (iVar1 == '\0') {
    _transitions = (char **)((uint)_transitions & 0xffff0000 | _states & 0xffff);
    RVar2 = RAIL_SetTxTransitions(railHandle,&transitions);
    pcVar3 = "Error";
    if (RVar2 == RAIL_STATUS_NO_ERROR) {
      pcVar3 = "Set";
    }
    responsePrint(*argv,"TxTransitions:%s",pcVar3);
  }
  else {
    responsePrintError(*argv,'\x16',"Invalid states");
  }
  return;
}



// WARNING: Could not reconcile some variable overlaps

void setRxTransitions(int argc,char **argv)

{
  _Bool _Var1;
  int8_t iVar2;
  RAIL_Status_t_enum RVar3;
  char *pcVar4;
  RAIL_RadioState_t states [2];
  RAIL_StateTransitions_t transitions;
  
  _states = argc;
  _transitions = argv;
  _Var1 = inRadioState('\x01',*argv);
  if (_Var1 != false) {
    iVar2 = stringsToStates(argv + 1,states);
    if (iVar2 == '\0') {
      _transitions = (char **)((uint)_transitions & 0xffff0000 | _states & 0xffff);
      RVar3 = RAIL_SetRxTransitions(railHandle,&transitions);
      if (RVar3 == RAIL_STATUS_NO_ERROR) {
        rxSuccessTransition = states[0];
      }
      pcVar4 = "Error";
      if (RVar3 == RAIL_STATUS_NO_ERROR) {
        pcVar4 = "Set";
      }
      responsePrint(*argv,"RxTransitions:%s",pcVar4);
    }
    else {
      responsePrintError(*argv,'\x16',"Invalid states");
    }
  }
  return;
}



// WARNING: Could not reconcile some variable overlaps

void setTimings(int argc,char **argv)

{
  RAIL_Status_t_enum RVar1;
  uint32_t uVar2;
  int iVar3;
  uint16_t timing [6];
  RAIL_StateTiming_t timings;
  
  timing._0_4_ = 0;
  timing._4_4_ = 0;
  timing._8_4_ = 0;
  for (iVar3 = 1; iVar3 < argc; iVar3 = iVar3 + 1) {
    uVar2 = ciGetUnsigned(argv[iVar3]);
    *(short *)(&stack0xffffffd6 + iVar3 * 2) = (short)uVar2;
  }
  timings.idleToRx = timing[0];
  timings.txToRx = timing[1];
  timings.idleToTx = timing[2];
  timings.rxToTx = timing[3];
  timings.rxSearchTimeout = timing[4];
  timings.txToRxSearchTimeout = timing[5];
  RVar1 = RAIL_SetStateTiming(railHandle,&timings);
  if (RVar1 == RAIL_STATUS_NO_ERROR) {
    responsePrint(*argv,"IdleToRx:%u,RxToTx:%u,IdleToTx:%u,TxToRx:%u,RxSearch:%u,Tx2RxSearch:%u",
                  (uint)timings.idleToRx,(uint)timings.rxToTx,(uint)timings.idleToTx,
                  (uint)timings.txToRx,(uint)timings.rxSearchTimeout,
                  (uint)timings.txToRxSearchTimeout);
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
  
  if (railDataConfig.txMethod != '\x01') {
    responsePrintError(*argv,'\x19',"Tx is not in FIFO mode");
    return;
  }
  uVar2 = ciGetUnsigned(argv[1]);
  uVar1 = RAIL_SetTxFifoThreshold(railHandle,(uint16_t)uVar2);
  responsePrint(*argv,"TxFifoThreshold:%d",(uint)uVar1);
  return;
}



void setRxFifoThreshold(int argc,char **argv)

{
  uint16_t uVar1;
  uint32_t uVar2;
  
  uVar2 = ciGetUnsigned(argv[1]);
  uVar1 = RAIL_SetRxFifoThreshold(railHandle,(uint16_t)uVar2);
  responsePrint(*argv,"RxFifoThreshold:%d",(uint)uVar1);
  return;
}



void setEventConfig(int argc,char **argv)

{
  uint32_t uVar1;
  uint32_t uVar2;
  undefined4 in_r2;
  undefined4 unaff_r4;
  
  uVar1 = ciGetUnsigned(argv[1]);
  uVar2 = ciGetUnsigned(argv[2]);
  RAIL_ConfigEvents(railHandle,(ulonglong)uVar2,CONCAT44(unaff_r4,in_r2));
  responsePrint(*argv,"Mask:0x%llx,Values:0x%llx",uVar1,0,uVar2,0);
  return;
}



void printTimerStats(int argc,char **argv)

{
  char *pcVar1;
  char *pcVar2;
  bool bVar3;
  bool bVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  
  bVar3 = RAIL_IsTimerRunning(railHandle);
  bVar4 = RAIL_IsTimerExpired(railHandle);
  uVar5 = RAIL_GetTimer(railHandle);
  uVar6 = RAIL_GetTime();
  pcVar2 = "txStatus:%s,transmitted:%u,lastTxTime:%u,failed:%u,lastTxStatus:0x%x,isAck:True";
  if (bVar3 == false) {
    pcVar1 = "txStatus:%s,transmitted:%u,lastTxTime:%u,failed:%u,lastTxStatus:0x%x,isAck:False";
  }
  else {
    pcVar1 = "txStatus:%s,transmitted:%u,lastTxTime:%u,failed:%u,lastTxStatus:0x%x,isAck:True";
  }
  if (bVar4 == false) {
    pcVar2 = "txStatus:%s,transmitted:%u,lastTxTime:%u,failed:%u,lastTxStatus:0x%x,isAck:False";
  }
  responsePrint(*argv,"timeUs:%u,ExpirationTime:%u,IsRunning:%s,IsExpired:%s",uVar6,uVar5,
                pcVar1 + 0x4b,pcVar2 + 0x4b);
  return;
}



void setTimer(int argc,char **argv)

{
  _Bool _Var1;
  RAIL_Status_t_enum RVar2;
  uint32_t time;
  int iVar3;
  undefined4 in_r3;
  
  _Var1 = inAppMode(NONE,*argv);
  if (_Var1 == false) {
    return;
  }
  time = ciGetUnsigned(argv[1]);
  iVar3 = strcmp(argv[2],"abs");
  RAIL_CancelTimer(railHandle);
  if (iVar3 != 0) {
    iVar3 = 1;
  }
  RVar2 = RAIL_SetTimer(railHandle,time,(RAIL_TimeMode_t)iVar3,0x35dd);
  if (RVar2 != RAIL_STATUS_NO_ERROR) {
    responsePrintError(*argv,'@',"SetTimer failed",in_r3);
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
    RAIL_CancelTimer(railHandle);
    printTimerStats(1,argv);
    return;
  }
  return;
}



void RAILCb_SensedRf(void)

{
  counters.rfSensedEvent = counters.rfSensedEvent + 1;
  if (counters.rfSensedEvent == 0) {
    counters.rfSensedEvent = 1;
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
  char *pcVar1;
  char *pcVar2;
  char **ppcVar3;
  
  ppcVar3 = argv;
  txOptions = ciGetUnsigned(argv[1]);
  txOptionsPtr = &txOptions;
  pcVar1 = "txStatus:%s,transmitted:%u,lastTxTime:%u,failed:%u,lastTxStatus:0x%x,isAck:False";
  if ((txOptions & 1) == 0) {
    pcVar2 = "txStatus:%s,transmitted:%u,lastTxTime:%u,failed:%u,lastTxStatus:0x%x,isAck:False";
  }
  else {
    pcVar2 = "txStatus:%s,transmitted:%u,lastTxTime:%u,failed:%u,lastTxStatus:0x%x,isAck:True";
  }
  if ((txOptions & 2) != 0) {
    pcVar1 = "txStatus:%s,transmitted:%u,lastTxTime:%u,failed:%u,lastTxStatus:0x%x,isAck:True";
  }
  responsePrint(*argv,"waitForAck:%s,removeCrc:%s,syncWordId:%d",pcVar2 + 0x4b,pcVar1 + 0x4b,
                (txOptions << 0x1d) >> 0x1f,ppcVar3);
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
  RAIL_RadioState_t_enum RVar2;
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
  RVar2 = RAIL_GetRadioState();
  if (uVar4 == 0) {
    if (1 < RVar2) {
      RAIL_Idle(railHandle,RAIL_IDLE_ABORT,false);
      receiveModeEnabled = false;
      AVar1 = currentAppMode();
      if (AVar1 == RX_SCHEDULED) {
        enableAppModeSync(RX_SCHEDULED,false,(char *)0x0);
        goto LAB_00002a62;
      }
    }
    command = *argv;
    pcVar6 = "Enabled";
    pcVar7 = "Disabled";
  }
  else {
    if ((RVar2 & 2) != 0) {
      command = *argv;
      pcVar6 = "Disabled";
      pcVar7 = "Enabled";
      goto LAB_00002a74;
    }
    RAIL_StartRx(railHandle,channel,(undefined *)(RVar2 & 2));
    receiveModeEnabled = true;
LAB_00002a62:
    command = *argv;
    if (uVar4 == 0) {
      pcVar7 = "Disabled";
      pcVar6 = "Enabled";
    }
    else {
      pcVar7 = "Enabled";
      pcVar6 = "Disabled";
    }
  }
LAB_00002a74:
  uVar5 = RAIL_GetTime();
  responsePrint(command,"Rx:%s,Idle:%s,Time:%u",pcVar7,pcVar6,uVar5);
  return;
}



void setRxOptions(int argc,char **argv)

{
  RAIL_Status_t_enum RVar1;
  uint32_t options;
  
  options = ciGetUnsigned(argv[1]);
  RVar1 = RAIL_ConfigRxOptions(railHandle,0xffffffff,options);
  if (RVar1 != RAIL_STATUS_NO_ERROR) {
    responsePrintError(*argv,'\x1f',"RxOptions:Failed");
    return;
  }
  responsePrint(*argv,
                "storeCrc:%s,ignoreCrcErrors:%s,enableDualSync:%s,trackAborted:%s,removeAppendedInfo:%s"
               );
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
  RAIL_Status_t RVar2;
  uint32_t uVar3;
  char *pcVar4;
  
  uVar3 = ciGetUnsigned(argv[1]);
  AVar1 = currentAppMode();
  if (AVar1 == DIRECT) {
    RAIL_Idle(railHandle,RAIL_IDLE_ABORT,false);
    if ((uVar3 & 0xff) == 0) {
      while ((receiveModeEnabled != false &&
             (RVar2 = RAIL_StartRx(railHandle,channel,(undefined *)0x0), RVar2 != '\0'))) {
        RAIL_Idle(railHandle,RAIL_IDLE_ABORT,false);
      }
    }
    else {
      RAIL_StartTx(railHandle,channel,0,(undefined *)0x0);
    }
    pcVar4 = "Enabled";
    if ((uVar3 & 0xff) == 0) {
      pcVar4 = "Disabled";
    }
    responsePrint(*argv,"DirectTx:%s",pcVar4);
    return;
  }
  responsePrintError(*argv,'\a',"DirectMode not enabled");
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void sleep(int argc,char **argv)

{
  byte bVar1;
  uint uVar2;
  _Bool _Var3;
  bool bVar4;
  RAIL_Status_t RVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  char *command;
  CORE_irqState_t CVar8;
  int iVar9;
  undefined *puVar10;
  undefined1 *puVar11;
  undefined4 *cb;
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
LAB_00002cac:
      CVar8 = CORE_EnterCritical();
      uVar2 = read_volatile_4(Peripherals::EMU.EM4CTRL);
      write_volatile_4(Peripherals::EMU.EM4CTRL,uVar2 & 0xfffffffe);
      CORE_ExitCritical(CVar8);
      pcVar14 = "s";
    }
    else {
      if (bVar1 < 0x54) {
        if (bVar1 == 0x48) {
LAB_00002cc6:
          CVar8 = CORE_EnterCritical();
          uVar2 = read_volatile_4(Peripherals::EMU.EM4CTRL);
          write_volatile_4(Peripherals::EMU.EM4CTRL,uVar2 | 1);
          CORE_ExitCritical(CVar8);
          pcVar14 = "h";
          goto LAB_00002cbe;
        }
      }
      else {
        if (bVar1 == 0x68) goto LAB_00002cc6;
        if (bVar1 == 0x73) goto LAB_00002cac;
      }
      uVar2 = read_volatile_4(Peripherals::EMU.EM4CTRL);
      pcVar14 = "s";
      if ((uVar2 & 1) != 0) {
        pcVar14 = "h";
      }
    }
LAB_00002cbe:
    if (argc < 3) goto LAB_00002d02;
LAB_00002ce4:
    rfUs = ciGetUnsigned(argv[2]);
    if (argc != 3) {
      uVar7 = ciGetUnsigned(argv[3]);
      rfBand = (RAIL_RfSenseBand_t)uVar7;
    }
    if (1 < uVar13) goto LAB_00002d02;
  }
  else {
    if (2 < argc) {
      pcVar14 = "";
      goto LAB_00002ce4;
    }
    if (uVar13 < 2) {
      command = *argv;
      pcVar14 = "";
      puVar11 = &DAT_00012f5e;
      goto LAB_00002d2a;
    }
    pcVar14 = "";
LAB_00002d02:
    RAIL_Idle(railHandle,RAIL_IDLE_ABORT,false);
    PeripheralDisable();
    uVar2 = read_volatile_4(Peripherals::EMU.EM4CTRL);
    write_volatile_4(Peripherals::EMU.EM4CTRL,uVar2 & 0xffffffcf | 0x10);
  }
  puVar11 = &DAT_00012f61;
  command = *argv;
  if (uVar13 != 4) {
    puVar11 = &DAT_00012f5e;
  }
LAB_00002d2a:
  responsePrint(command,"EM:%u%s,SerialWakeup:%s,RfSense:%s",uVar13,pcVar14,puVar11,
                rfBands[rfBand & 3]);
  serialWaitForTxIdle();
  CVar8 = CORE_EnterCritical();
  cb = (undefined4 *)(RAILCb_SensedRf + 1);
  if ((uVar6 & 0x80) != 0) {
    cb = (undefined4 *)0x0;
  }
  rfUs = RAIL_StartRfSense(railHandle,rfBand,rfUs,cb);
  GPIO_ExtIntConfig(gpioPortA,1,1,false,true,true);
  serEvent = false;
  do {
    switch(uVar13) {
    case 0:
                    // WARNING: This code block may not be properly labeled as switch case
      _DAT_e000ed10 = _DAT_e000ed10 & 0xfffffffb;
      WaitForInterrupt();
      break;
    case 1:
      EMU_EnterEM2(true);
      break;
    case 2:
      EMU_EnterEM3(true);
      break;
    case 3:
      EMU_EnterEM4();
    }
    CORE_ExitCritical(CVar8);
    CVar8 = CORE_EnterCritical();
    bVar4 = RAIL_IsRfSensed(railHandle);
  } while ((bVar4 == false) && (serEvent == false));
  CORE_ExitCritical(CVar8);
  enableAppMode(RF_SENSE,false,(char *)0x0);
  GPIO_ExtIntConfig(gpioPortA,1,1,false,true,false);
  puVar12 = &DAT_00012f69;
  if (serEvent == false) {
    puVar10 = &DAT_00012f69;
  }
  else {
    puVar10 = &DAT_00012f65;
  }
  if (bVar4 != false) {
    puVar12 = &DAT_00012f65;
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
  while ((receiveModeEnabled != false &&
         (RVar5 = RAIL_StartRx(railHandle,channel,(undefined *)0x0), RVar5 != '\0'))) {
    RAIL_Idle(railHandle,RAIL_IDLE_ABORT,false);
  }
  if ((1 < uVar13) && ((int)((uint)logLevel << 0x1f) < 0)) {
    PeripheralEnable();
    return;
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
  if (rfBand != '\0') {
    enable = true;
  }
  _Var1 = enableAppModeSync(RF_SENSE,(_Bool)enable,*argv);
  if (_Var1 != false) {
    rfUs = RAIL_StartRfSense(railHandle,rfBand,rfUs,(undefined4 *)(RAILCb_SensedRf + 1));
    if (rfUs == 0) {
      rfBand = '\0';
    }
    responsePrint(*argv,"RfSense:%s,RfUs:%u",rfBands[rfBand & 3],rfUs);
    return;
  }
  return;
}



void printTxAcks(int argc,char **argv)

{
  char *pcVar1;
  uint32_t uVar2;
  
  uVar2 = ciGetUnsigned(argv[1]);
  printTxAck = (_Bool)(uVar2 != 0);
  pcVar1 = "txStatus:%s,transmitted:%u,lastTxTime:%u,failed:%u,lastTxStatus:0x%x,isAck:True";
  if (!(bool)printTxAck) {
    pcVar1 = "txStatus:%s,transmitted:%u,lastTxTime:%u,failed:%u,lastTxStatus:0x%x,isAck:False";
  }
  responsePrint(*argv,"printTxAcks:%s",pcVar1 + 0x4b);
  return;
}



void rfSensedCheck(void)

{
  AppMode_t AVar1;
  bool bVar2;
  
  AVar1 = currentAppMode();
  if ((AVar1 == RF_SENSE) && (bVar2 = RAIL_IsRfSensed(railHandle), bVar2 != false)) {
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
    *mode = '\x02';
  }
  else {
    iVar1 = strcasecmp("rel",str);
    if (iVar1 == 0) {
      *mode = '\x01';
      return true;
    }
    iVar1 = strcasecmp("abs",str);
    if (iVar1 != 0) {
      *mode = '\x02';
      return false;
    }
    *mode = '\0';
  }
  return true;
}



void txAtTime(int argc,char **argv)

{
  _Bool _Var1;
  int iVar2;
  undefined uVar3;
  RAIL_ScheduleTxConfig_t scheduledTxOptions;
  
  scheduledTxOptions.when = 0;
  scheduledTxOptions._4_4_ = 0;
  scheduledTxOptions.when = ciGetUnsigned(argv[1]);
  if (2 < argc) {
    _Var1 = parseTimeModeFromString(argv[2],&scheduledTxOptions.mode);
    if (_Var1 == false) {
      responsePrintError(*argv,'\x1c',"Invalid time mode");
      return;
    }
    if ((argc != 3) && (iVar2 = strcasecmp("abort",argv[3]), iVar2 == 0)) {
      uVar3 = 1;
      goto LAB_000030a8;
    }
  }
  uVar3 = 0;
LAB_000030a8:
  scheduledTxOptions._4_2_ = CONCAT11(uVar3,scheduledTxOptions.mode);
  scheduledTxOptions._4_4_ = scheduledTxOptions._4_4_ & 0xffff0000 | (uint)scheduledTxOptions._4_2_;
  setNextPacketTime(&scheduledTxOptions);
  setNextAppMode(TX_SCHEDULED,*argv);
  return;
}



void rxAt(int argc,char **argv)

{
  _Bool _Var1;
  _Bool _Var2;
  RAIL_Status_t_enum RVar3;
  uint32_t uVar4;
  uint8_t code;
  char *formatString;
  RAIL_TimeMode_t startMode;
  RAIL_TimeMode_t endMode;
  RAIL_ScheduleRxConfig_t rxCfg;
  
  _Var1 = inAppMode(NONE,(char *)0x0);
  if (((_Var1 == false) && (_Var1 = inAppMode(RX_SCHEDULED,(char *)0x0), _Var1 == false)) ||
     ((_Var1 = inAppMode(NONE,(char *)0x0), _Var1 != false &&
      (_Var1 = inRadioState('\x01',(char *)0x0), _Var1 == false)))) {
    formatString = "Cannot enter ScheduledRx when not in Idle.";
    code = '\x1e';
LAB_00003118:
    responsePrintError(*argv,code,formatString);
    return;
  }
  rxCfg.start = ciGetUnsigned(argv[1]);
  rxCfg.end = ciGetUnsigned(argv[3]);
  _Var1 = parseTimeModeFromString(argv[2],&startMode);
  if (_Var1 == false) {
    formatString = "Invalid startMode specified";
    code = '\x19';
    goto LAB_00003118;
  }
  _Var1 = parseTimeModeFromString(argv[4],&endMode);
  if (_Var1 == false) {
    formatString = "Invalid endMode specified";
    code = '\x1a';
    goto LAB_00003118;
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
      goto LAB_00003164;
    }
  }
  uVar4 = 0;
LAB_00003164:
  rxCfg.startMode = startMode;
  rxCfg.endMode = endMode;
  rxCfg.hardWindowEnd = (uint8_t)uVar4;
  schRxStopOnRxEvent = (_Bool)rxCfg.rxTransitionEndSchedule;
  _Var1 = inAppMode(RX_SCHEDULED,(char *)0x0);
  if ((_Var1 == false) && (_Var2 = enableAppModeSync(RX_SCHEDULED,true,*argv), _Var2 == false)) {
    return;
  }
  RVar3 = RAIL_ScheduleRx(railHandle,channel,&rxCfg,(undefined *)0x0);
  if (RVar3 == 0) {
    return;
  }
  responsePrintError(*argv,'\x1b',"Could not start scheduled receive %d",(uint)RVar3);
  if (_Var1 != false) {
    return;
  }
  enableAppModeSync(RX_SCHEDULED,false,*argv);
  return;
}



void PeripheralEnable(void)

{
  GRAPHICS_Wakeup();
  redrawDisplay = true;
  return;
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



void disableGraphics(void)

{
  GRAPHICS_Clear();
  GRAPHICS_Update();
  GRAPHICS_Sleep();
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
    sniprintf(textBuf,0x40,"Tx Count: %05lu",(counters.userTx + counters.ackTx) % 100000);
    GRAPHICS_AppendString(textBuf);
    sniprintf(textBuf,0x40,"Channel: %d",(uint)channel);
    GRAPHICS_AppendString(textBuf);
    GRAPHICS_AppendString("");
    GRAPHICS_AppendString("   Tx     Rx");
    GRAPHICS_InsertTriangle
              (0x14,0x50,0x20,true,
               ((char)(counters.ackTx + counters.userTx) +
               (char)((counters.ackTx + counters.userTx) / 10) * -10) * -10);
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



void LedsDisable(void)

{
  BSP_LedClear(0);
  BSP_LedClear(1);
  return;
}



void PeripheralDisable(void)

{
  LedsDisable();
  disableGraphics();
  return;
}



void initButtons(void)

{
  GPIO_PinModeSet(gpioPortF,6,gpioModeInputPull,1);
  GPIO_PinModeSet(gpioPortF,7,gpioModeInputPull,1);
  GPIOINT_CallbackRegister('\x06',gpioCallback + 1);
  GPIOINT_CallbackRegister('\a',gpioCallback + 1);
  GPIO_ExtIntConfig(gpioPortF,6,6,true,true,true);
  GPIO_ExtIntConfig(gpioPortF,7,7,true,true,true);
  return;
}



void appHalInit(void)

{
  halInit();
  GRAPHICS_Init();
  RETARGET_SerialCrLf(1);
  GPIO_PinModeSet(gpioPortC,7,gpioModePushPull,1);
  GPIOINT_Init();
  GPIOINT_CallbackRegister('\x01',gpioCallback + 1);
  initButtons();
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
  RAIL_Status_t_enum RVar2;
  RAIL_Status_t RVar3;
  
  _Var1 = inAppMode(NONE,(char *)0x0);
  if ((_Var1 != false) && (_Var1 = inRadioState('\x04',(char *)0x0), _Var1 == false)) {
    _Var1 = inRadioState('\x02',(char *)0x0);
    if (_Var1 != false) {
      RAIL_Idle(railHandle,RAIL_IDLE_ABORT,false);
    }
    RVar2 = RAIL_IsValidChannel(railHandle,channel + 1);
    if (RVar2 == RAIL_STATUS_NO_ERROR) {
      channel = channel + 1;
    }
    else {
      channel = 0;
      while (RVar2 = RAIL_IsValidChannel(railHandle,channel), RVar2 != RAIL_STATUS_NO_ERROR) {
        channel = channel + 1;
      }
    }
    while ((receiveModeEnabled != false &&
           (RVar3 = RAIL_StartRx(railHandle,channel,(undefined *)0x0), RVar3 != '\0'))) {
      RAIL_Idle(railHandle,RAIL_IDLE_ABORT,false);
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
      uVar1 = RAIL_GetTime();
      if (1000 < uVar1 / 1000 - gpioCallback::gpio0TimeCapture) {
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
      uVar1 = RAIL_GetTime();
      if (1000 < uVar1 / 1000 - gpioCallback::gpio1TimeCapture) {
        return;
      }
      gpio1ShortPress();
      return;
    }
  }
  uVar1 = RAIL_GetTime();
  *puVar2 = uVar1 / 1000;
  return;
}



// WARNING: Could not reconcile some variable overlaps

void RAILCb_RadioConfigChanged(RAIL_Handle_t railHandle,RAIL_ChannelConfigEntry_t *entry)

{
  RAIL_Status_t_enum RVar1;
  RAIL_TxPower_t RVar2;
  short power;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  RAIL_TxPowerConfig_t txConfig;
  
  txConfig._0_4_ = railHandle;
  unique0x10000071 = entry;
  RAIL_GetTxPowerConfig(railHandle,&txConfig);
  if (entry->baseFrequency < 0x3b9aca01) {
    if ((entry->baseFrequency == 1000000000) || (1 < txConfig.mode)) goto LAB_0000359c;
  }
  else {
    if (txConfig.mode != '\x02') goto LAB_0000359c;
  }
  RVar2 = RAIL_ConvertRawToDbm(railHandle,txConfig.mode,lastSetTxPowerLevel);
  uVar4 = entry->baseFrequency;
  uVar5 = uVar4;
  if (uVar4 < 0x3b9aca01) {
    uVar5 = 2;
  }
  bVar3 = (byte)uVar5;
  if (1000000000 < uVar4) {
    bVar3 = 0;
  }
  txConfig._0_4_ = (RAIL_Handle_t)((uint)txConfig._0_4_ & 0xffffff00 | (uint)bVar3);
  RVar1 = RAIL_ConfigTxPower(railHandle,&txConfig);
  if (RVar1 != RAIL_STATUS_NO_ERROR) {
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  power = entry->maxPower;
  if (RVar2 <= entry->maxPower) {
    power = RVar2;
  }
  RAIL_SetTxPowerDbm(railHandle,power);
LAB_0000359c:
  counters.radioConfigChanged = counters.radioConfigChanged + 1;
  return;
}



void RAILCb_RfReady(RAIL_Handle_t railHandle)

{
  LedSet(0);
  LedSet(1);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RAILCb_TimerExpired(RAIL_Handle_t railHandle)

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
        _DAT_4400a06c = 0x80;
        enableAppMode(PER,false,(char *)0x0);
        return;
      }
      RAIL_SetTimer(railHandle,perDelay,'\x01',0x35dd);
      return;
    }
    p_Var3 = &packetTx;
  }
  else {
    if (abortRxDelay != 0) {
      RAIL_Idle(railHandle,RAIL_IDLE_ABORT,true);
      return;
    }
    railTimerExpireTime = RAIL_GetTime();
    railTimerConfigExpireTime = RAIL_GetTimer(railHandle);
    p_Var3 = &railTimerExpired;
  }
  *p_Var3 = true;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RAILCb_AssertFailed(RAIL_Handle_t railHandle,uint32_t errorCode)

{
  responsePrint("assert","code:%d,message:%s",errorCode);
  DataSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



void processPendingCalibrations(void)

{
  _Bool _Var1;
  RAIL_Status_t RVar2;
  RAIL_CalMask_t calForce;
  
  _Var1 = inAppMode(NONE,(char *)0x0);
  if ((((calibrateRadio != false) && (_Var1 != false)) && (skipCalibrations == false)) &&
     (receivingPacket == false)) {
    calForce = RAIL_GetPendingCal(railHandle);
    if ((calForce & 0x10000) != 0) {
      RAIL_Idle(railHandle,RAIL_IDLE_ABORT,false);
    }
    counters.calibrations = counters.calibrations + 1;
    calibrateRadio = false;
    RAIL_Calibrate(railHandle,(undefined *)0x0,calForce);
    if ((calForce & 0x10000) != 0) {
      while ((receiveModeEnabled != false &&
             (RVar2 = RAIL_StartRx(railHandle,channel,(undefined *)0x0), RVar2 != '\0'))) {
        RAIL_Idle(railHandle,RAIL_IDLE_ABORT,false);
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
    return;
  }
  return;
}



void printNewTxError(void)

{
  if (newTxError != false) {
    newTxError = false;
    if ((((uint)lastTxStatus & 0x1000000) != 0) && ((int)((uint)logLevel << 0x1e) < 0)) {
      responsePrint("txPacket","txStatus:Error,errorReason:Tx underflow or abort,errorCode:0x%x",
                    (uint)lastTxStatus,lastTxStatus._4_4_);
    }
    if (((uint)lastTxStatus & 0x8000000) != 0) {
      if ((int)((uint)logLevel << 0x1e) < 0) {
        responsePrint("txPacket","txStatus:Error,errorReason:Tx channel busy,errorCode:0x%x",
                      (uint)lastTxStatus,lastTxStatus._4_4_);
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
    return;
  }
  return;
}



void changeChannel(uint32_t i)

{
  channel = (uint16_t)i;
  redrawDisplay = true;
  if (receiveModeEnabled != false) {
    RAIL_StartRx(railHandle,channel,(undefined *)0x0);
    return;
  }
  redrawDisplay = true;
  return;
}



void pendPacketTx(void)

{
  packetTx = true;
  return;
}



uint8_t chooseTxType(_Bool reuseCcaConfig)

{
  AppMode_t AVar1;
  RAIL_Status_t_enum RVar2;
  RAIL_LbtConfig_t *lbtConfig;
  RAIL_CsmaConfig_t *schedulerInfo;
  RAIL_CsmaConfig_t *csmaConfig;
  
  csmaConfig = (RAIL_CsmaConfig_t *)txOptionsPtr;
  if (txOptionsPtr != (RAIL_TxOptions_t *)0x0) {
    csmaConfig = (RAIL_CsmaConfig_t *)*txOptionsPtr;
  }
  AVar1 = currentAppMode();
  if ((AVar1 == TX_SCHEDULED) || (AVar1 = currentAppMode(), AVar1 == SCHTX_AFTER_RX)) {
    RVar2 = RAIL_StartScheduledTx
                      (railHandle,channel,(RAIL_TxOptions_t)csmaConfig,&nextPacketTxTime,
                       (undefined *)0x0);
  }
  else {
    if (txType == TX_TYPE_LBT) {
      lbtConfig = (RAIL_LbtConfig_t *)0x0;
      if (reuseCcaConfig == false) {
        lbtConfig = ::lbtConfig;
      }
      RVar2 = RAIL_StartCcaLbtTx(railHandle,channel,(RAIL_TxOptions_t)csmaConfig,lbtConfig,
                                 (undefined *)0x0);
    }
    else {
      if (txType != TX_TYPE_CSMA) {
        RVar2 = RAIL_StartTx(railHandle,channel,(RAIL_TxOptions_t)csmaConfig,(undefined *)0x0);
        return (uint8_t)RVar2;
      }
      schedulerInfo = (RAIL_CsmaConfig_t *)0x0;
      if (reuseCcaConfig == false) {
        schedulerInfo = ::csmaConfig;
      }
      RVar2 = RAIL_StartCcaCsmaTx(railHandle,channel,csmaConfig,&schedulerInfo->csmaMinBoExp);
    }
  }
  return (uint8_t)RVar2;
}



void sendPacketIfPending(void)

{
  AppMode_t AVar1;
  byte bVar2;
  uint32_t uVar3;
  
  uVar3 = internalTransmitCounter;
  if (packetTx != false) {
    packetTx = false;
    AVar1 = currentAppMode();
    if (AVar1 != TX_CONTINUOUS) {
      txCount = txCount + -1;
    }
    AVar1 = currentAppMode();
    if ((AVar1 != TX_UNDERFLOW) && (txFifoManual == false)) {
      loadTxData(txData,txDataLen);
    }
    if (uVar3 == startTransmitCounter) {
      uVar3 = failPackets;
      if (failPackets != 0) {
        uVar3 = 1;
      }
    }
    else {
      uVar3 = 1;
    }
    bVar2 = chooseTxType(SUB41(uVar3,0));
    if (bVar2 != 0) {
      lastTxStatus._0_4_ = (uint)bVar2;
      failPackets = failPackets + 1;
      lastTxStatus._4_4_ = 0;
      scheduleNextTx();
      return;
    }
    AVar1 = currentAppMode();
    if (AVar1 == TX_CANCEL) {
      usDelay(txCancelDelay);
      RAIL_Idle(railHandle,RAIL_IDLE_ABORT,false);
      return;
    }
  }
  return;
}



void pendFinishTxSequence(void)

{
  finishTxSequence = true;
  return;
}



void pendFinishTxAckSequence(void)

{
  finishTxAckSequence = true;
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
      responsePrint("txEnd",
                    "txStatus:%s,transmitted:%u,lastTxTime:%u,failed:%u,lastTxStatus:0x%x,isAck:False"
                    ,pcVar1,internalTransmitCounter - startTransmitCounter,
                    previousTxAppendedInfo.timeSent.packetTime,failPackets,(undefined4)lastTxStatus,
                    lastTxStatus._4_4_);
    }
    startTransmitCounter = internalTransmitCounter;
    failPackets = 0;
    lastTxStatus._0_4_ = 0;
    lastTxStatus._4_4_ = 0;
  }
  if (finishTxAckSequence != false) {
    finishTxAckSequence = false;
    if (((logLevel & 2) != 0) && (printTxAck != false)) {
      if (failAckPackets == 0) {
        pcVar1 = "Complete";
      }
      else {
        pcVar1 = "Error";
        if (sentAckPackets != 0) {
          pcVar1 = "Partial";
        }
      }
      responsePrint("txEnd",
                    "txStatus:%s,transmitted:%u,lastTxTime:%u,failed:%u,lastTxStatus:0x%x,isAck:True"
                    ,pcVar1,sentAckPackets,previousTxAckAppendedInfo.timeSent.packetTime,
                    failAckPackets,(undefined4)lastTxAckStatus,lastTxAckStatus._4_4_);
    }
    sentAckPackets = 0;
    failAckPackets = 0;
    lastTxAckStatus._0_4_ = 0;
    lastTxAckStatus._4_4_ = 0;
  }
  return;
}



void printPacket(char *cmdName,uint8_t *data,uint16_t dataLength,RxPacketData_t *packetData)

{
  char *pcVar1;
  size_t __maxlen;
  undefined1 *puVar2;
  int iVar3;
  byte *pbVar4;
  
  if (data == (uint8_t *)0x0) {
    responsePrint(cmdName,"len:0");
    return;
  }
  iVar3 = 0;
  pbVar4 = data;
  do {
    if ((int)(uint)dataLength <= (int)pbVar4 - (int)data) goto LAB_00003b54;
    __maxlen = 0x9dd - iVar3;
    pcVar1 = packetPrintBuffer + iVar3;
    iVar3 = iVar3 + 5;
    sniprintf(pcVar1,__maxlen," 0x%.2x",(uint)*pbVar4);
    pbVar4 = pbVar4 + 1;
  } while (iVar3 != 0x9dd);
  strcpy(packetPrintBuffer,"Packet too large!");
LAB_00003b54:
  if (packetData != (RxPacketData_t *)0x0) {
    puVar2 = &DAT_000132fd;
    if ((packetData->appendedInfo).crcPassed == false) {
      puVar2 = &DAT_00013302;
    }
    pcVar1 = "txStatus:%s,transmitted:%u,lastTxTime:%u,failed:%u,lastTxStatus:0x%x,isAck:True";
    if ((packetData->appendedInfo).isAck == false) {
      pcVar1 = "txStatus:%s,transmitted:%u,lastTxTime:%u,failed:%u,lastTxStatus:0x%x,isAck:False";
    }
    responsePrint(cmdName,
                  "len:%d,timeUs:%u,crc:%s,rssi:%d,lqi:%d,phy:%d,isAck:%s,syncWordId:%d,payload:%s",
                  (uint)packetData->dataLength,(packetData->appendedInfo).timeReceived.packetTime,
                  puVar2,(int)(packetData->appendedInfo).rssi,(uint)(packetData->appendedInfo).lqi,
                  (uint)(packetData->appendedInfo).subPhyId,pcVar1 + 0x4b,
                  (uint)(packetData->appendedInfo).syncWordId,packetPrintBuffer);
    return;
  }
  responsePrint(cmdName,"len:%d,payload:%s",(uint)dataLength,packetPrintBuffer);
  return;
}



void printReceivedPacket(void)

{
  _Bool _Var1;
  void *handle;
  RxPacketData_t *packetData;
  
  _Var1 = queueIsEmpty(&rxPacketQueue);
  if (_Var1 == false) {
    handle = queueRemove(&rxPacketQueue);
    packetData = (RxPacketData_t *)memoryPtrFromHandle(handle);
    if (packetData != (RxPacketData_t *)0x0) {
      printPacket("rxPacket",(uint8_t *)&packetData->field_0x16,packetData->dataLength,packetData);
    }
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
    iVar1 = ciProcessInput(&ciState,&input,1);
    if ('\0' < iVar1) {
      iprintf("> ");
    }
    iVar2 = getchar();
  }
  return;
}



void enqueueEvents(RAIL_Events_t events)

{
  uint in_r0;
  CORE_irqState_t irqState;
  uint32_t uVar1;
  undefined4 in_r1;
  uint uVar2;
  
  if ((in_r0 & enablePrintEvents) != 0) {
    irqState = CORE_EnterCritical();
    uVar2 = (uint)eventQueueMarker;
    if (uVar2 < 10) {
      uVar1 = RAIL_GetTime();
      *(uint *)&eventQueue[eventQueueMarker].events = in_r0;
      *(undefined4 *)((int)&eventQueue[eventQueueMarker].events + 4) = in_r1;
      eventQueueMarker = eventQueueMarker + '\x01';
      eventQueue[uVar2].timestamp = uVar1;
    }
    else {
      eventsMissed = eventsMissed + 1;
    }
    CORE_ExitCritical(irqState);
    return;
  }
  return;
}



void RAILCb_Event(RAIL_Handle_t railHandle,RAIL_Events_t events)

{
  RAIL_Status_t RVar1;
  _Bool _Var2;
  int16_t iVar3;
  uint32_t uVar4;
  uint in_r2;
  Counters_t *pCVar5;
  Counters_t *pCVar6;
  uint in_r3;
  bool bVar7;
  float f;
  undefined4 in_stack_ffffffd0;
  char cVar8;
  undefined4 in_stack_ffffffd4;
  
  enqueueEvents(CONCAT44(in_stack_ffffffd4,in_stack_ffffffd0));
  cVar8 = (char)in_stack_ffffffd4;
  bVar7 = (in_r3 & 2) != 0;
  if (bVar7) {
    calibrateRadio = (_Bool)bVar7;
  }
  if ((in_r2 & 1) != 0) {
    iVar3 = RAIL_GetAverageRssi(railHandle);
    rssiDoneCount = rssiDoneCount + 1;
    averageRssi = (float)FixedToFP((int)iVar3,0x20,0x20,2,0,0);
    if (iVar3 == -0x200) {
      responsePrint("getAvgRssi","Could not read RSSI.");
    }
    else {
      sprintfFloat(&stack0xffffffd4,'\n',f,SUB41(averageRssi,0));
      responsePrint("getAvgRssi","rssi:%s",&stack0xffffffd4);
    }
  }
  pCVar5 = (Counters_t *)(in_r2 & 0x8000);
  bVar7 = pCVar5 != (Counters_t *)0x0;
  pCVar6 = pCVar5;
  if (bVar7) {
    pCVar6 = &counters;
    pCVar5 = (Counters_t *)(counters.timingDetect + 1);
  }
  if (bVar7) {
    pCVar6->timingDetect = (uint32_t)pCVar5;
  }
  pCVar5 = (Counters_t *)(in_r2 & 0x4000);
  bVar7 = pCVar5 != (Counters_t *)0x0;
  pCVar6 = pCVar5;
  if (bVar7) {
    pCVar6 = &counters;
    pCVar5 = (Counters_t *)(counters.timingLost + 1);
  }
  if (bVar7) {
    pCVar6->timingLost = (uint32_t)pCVar5;
  }
  pCVar5 = (Counters_t *)(in_r2 & 0x10);
  bVar7 = pCVar5 != (Counters_t *)0x0;
  pCVar6 = pCVar5;
  if (bVar7) {
    pCVar6 = &counters;
    pCVar5 = (Counters_t *)(counters.preambleDetect + 1);
  }
  if (bVar7) {
    pCVar6->preambleDetect = (uint32_t)pCVar5;
  }
  if ((in_r2 & 0x20) != 0) {
    receivingPacket = true;
    counters.syncDetect = counters.syncDetect + 1;
    rxFifoPrep();
    if (abortRxDelay != 0) {
      RAIL_SetTimer(railHandle,abortRxDelay,'\x01',0x35dd);
    }
  }
  if ((((in_r2 & 0x10000) != 0) &&
      (RVar1 = RAIL_IEEE802154_GetAddress(railHandle,(RAIL_IEEE802154_Address_t *)&stack0xffffffd4),
      RVar1 == '\0')) && (cVar8 == -0x56)) {
    RAIL_IEEE802154_SetFramePending(railHandle);
  }
  if ((in_r2 & 4) != 0) {
    RAILCb_RxFifoAlmostFull(railHandle);
  }
  if ((in_r2 & 5000) != 0) {
    receivingPacket = false;
    if ((rxFifoManual != false) && (railDataConfig.rxMethod != '\0')) {
      RAIL_HoldRxPacket(railHandle);
    }
    pCVar5 = (Counters_t *)(in_r2 & 0x100);
    bVar7 = pCVar5 != (Counters_t *)0x0;
    pCVar6 = pCVar5;
    if (bVar7) {
      pCVar6 = &counters;
      pCVar5 = (Counters_t *)(counters.rxOfEvent + 1);
    }
    if (bVar7) {
      pCVar6->rxOfEvent = (uint32_t)pCVar5;
    }
    pCVar5 = (Counters_t *)(in_r2 & 0x200);
    bVar7 = pCVar5 != (Counters_t *)0x0;
    pCVar6 = pCVar5;
    if (bVar7) {
      pCVar6 = &counters;
      pCVar5 = (Counters_t *)(counters.addrFilterEvent + 1);
    }
    if (bVar7) {
      pCVar6->addrFilterEvent = (uint32_t)pCVar5;
    }
    pCVar5 = (Counters_t *)(in_r2 & 0x1000);
    bVar7 = pCVar5 != (Counters_t *)0x0;
    pCVar6 = pCVar5;
    if (bVar7) {
      pCVar6 = &counters;
      pCVar5 = (Counters_t *)(counters.rxFail + 1);
    }
    if (bVar7) {
      pCVar6->rxFail = (uint32_t)pCVar5;
    }
    pCVar5 = (Counters_t *)(in_r2 & 0x80);
    bVar7 = pCVar5 != (Counters_t *)0x0;
    pCVar6 = pCVar5;
    if (bVar7) {
      pCVar6 = &counters;
      pCVar5 = (Counters_t *)(counters.frameError + 1);
    }
    if (bVar7) {
      pCVar6->frameError = (uint32_t)pCVar5;
    }
    if ((in_r2 & 8) != 0) {
      RAILCb_RxPacketReceived(railHandle);
    }
  }
  if ((in_r2 & 2) != 0) {
    counters.ackTimeout = counters.ackTimeout + 1;
    rxAckTimeout = true;
    uVar4 = RAIL_GetTime();
    ackTimeoutDuration = uVar4 - previousTxAppendedInfo.timeSent.packetTime;
  }
  if (((in_r2 & 0x800) != 0) ||
     (((schRxStopOnRxEvent != false && (_Var2 = inAppMode(RX_SCHEDULED,(char *)0x0), _Var2 != false)
       ) && ((in_r2 & 0x380) != 0)))) {
    enableAppMode(RX_SCHEDULED,false,(char *)0x0);
  }
  pCVar5 = (Counters_t *)(in_r2 & 0x20000000);
  bVar7 = pCVar5 != (Counters_t *)0x0;
  pCVar6 = pCVar5;
  if (bVar7) {
    pCVar6 = &counters;
    pCVar5 = (Counters_t *)(counters.lbtStartCca + 1);
  }
  if (bVar7) {
    pCVar6->lbtStartCca = (uint32_t)pCVar5;
  }
  pCVar5 = (Counters_t *)(in_r2 & 0x10000000);
  bVar7 = pCVar5 != (Counters_t *)0x0;
  pCVar6 = pCVar5;
  if (bVar7) {
    pCVar6 = &counters;
    pCVar5 = (Counters_t *)(counters.lbtRetry + 1);
  }
  if (bVar7) {
    pCVar6->lbtRetry = (uint32_t)pCVar5;
  }
  pCVar5 = (Counters_t *)(in_r2 & 0x4000000);
  bVar7 = pCVar5 != (Counters_t *)0x0;
  pCVar6 = pCVar5;
  if (bVar7) {
    pCVar6 = &counters;
    pCVar5 = (Counters_t *)(counters.lbtSuccess + 1);
  }
  if (bVar7) {
    pCVar6->lbtSuccess = (uint32_t)pCVar5;
  }
  if ((in_r2 & 0x9500000) != 0) {
    newTxError = true;
    failPackets = failPackets + 1;
    lastTxStatus._0_4_ = in_r2;
    lastTxStatus._4_4_ = in_r3;
    scheduleNextTx();
    pCVar5 = (Counters_t *)(in_r2 & 0x100000);
    bVar7 = pCVar5 != (Counters_t *)0x0;
    pCVar6 = pCVar5;
    if (bVar7) {
      pCVar6 = &counters;
      pCVar5 = (Counters_t *)(counters.userTxAborted + 1);
    }
    if (bVar7) {
      pCVar6->userTxAborted = (uint32_t)pCVar5;
    }
    pCVar5 = (Counters_t *)(in_r2 & 0x400000);
    bVar7 = pCVar5 != (Counters_t *)0x0;
    pCVar6 = pCVar5;
    if (bVar7) {
      pCVar6 = &counters;
      pCVar5 = (Counters_t *)(counters.userTxBlocked + 1);
    }
    if (bVar7) {
      pCVar6->userTxBlocked = (uint32_t)pCVar5;
    }
    pCVar5 = (Counters_t *)(in_r2 & 0x1000000);
    bVar7 = pCVar5 != (Counters_t *)0x0;
    pCVar6 = pCVar5;
    if (bVar7) {
      pCVar6 = &counters;
      pCVar5 = (Counters_t *)(counters.userTxUnderflow + 1);
    }
    if (bVar7) {
      pCVar6->userTxUnderflow = (uint32_t)pCVar5;
    }
  }
  if ((in_r2 & 0x2a00000) != 0) {
    failAckPackets = failAckPackets + 1;
    finishTxAckSequence = true;
    pCVar5 = (Counters_t *)(in_r2 & 0x200000);
    bVar7 = pCVar5 != (Counters_t *)0x0;
    pCVar6 = pCVar5;
    if (bVar7) {
      pCVar6 = &counters;
      pCVar5 = (Counters_t *)(counters.ackTxAborted + 1);
    }
    lastTxAckStatus._0_4_ = in_r2;
    lastTxAckStatus._4_4_ = in_r3;
    if (bVar7) {
      pCVar6->ackTxAborted = (uint32_t)pCVar5;
    }
    pCVar5 = (Counters_t *)(in_r2 & 0x800000);
    bVar7 = pCVar5 != (Counters_t *)0x0;
    pCVar6 = pCVar5;
    if (bVar7) {
      pCVar6 = &counters;
      pCVar5 = (Counters_t *)(counters.ackTxBlocked + 1);
    }
    if (bVar7) {
      pCVar6->ackTxBlocked = (uint32_t)pCVar5;
    }
    pCVar5 = (Counters_t *)(in_r2 & 0x2000000);
    bVar7 = pCVar5 != (Counters_t *)0x0;
    pCVar6 = pCVar5;
    if (bVar7) {
      pCVar6 = &counters;
      pCVar5 = (Counters_t *)(counters.ackTxUnderflow + 1);
    }
    if (bVar7) {
      pCVar6->ackTxUnderflow = (uint32_t)pCVar5;
    }
  }
  if ((in_r2 & 0x20000) != 0) {
    RAILCb_TxFifoAlmostEmpty(railHandle);
  }
  if ((in_r2 & 0x40000) != 0) {
    counters.userTx = counters.userTx + 1;
    RAILCb_TxPacketSent(railHandle,false);
  }
  if ((in_r2 & 0x80000) != 0) {
    counters.ackTx = counters.ackTx + 1;
    RAILCb_TxPacketSent(railHandle,true);
  }
  return;
}



void printEvents(void)

{
  uint *puVar1;
  CORE_irqState_t irqState;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint32_t local_d8 [3];
  uint local_cc;
  uint local_c8 [41];
  
  if (eventQueueMarker != '\0') {
    irqState = CORE_EnterCritical();
    memcpy(local_c8,eventQueue,0xa0);
    local_d8[0] = eventsMissed;
    local_cc = (uint)eventQueueMarker;
    eventQueueMarker = '\0';
    eventsMissed = 0;
    CORE_ExitCritical(irqState);
    puVar1 = local_d8;
    for (iVar4 = 0; iVar4 < (int)local_cc; iVar4 = iVar4 + 1) {
      uVar5 = puVar1[4];
      uVar6 = puVar1[5];
      for (uVar3 = 0;
          (uVar5 >> (uVar3 & 0xff) | uVar6 << (0x20 - uVar3 & 0xff) | uVar6 >> (uVar3 - 0x20 & 0xff)
          | uVar6 >> (uVar3 & 0xff)) != 0; uVar3 = uVar3 + 1) {
        uVar2 = 1 << (uVar3 & 0xff);
        if ((uVar5 & uVar2 | uVar6 & (int)uVar2 >> 0x1f) != 0) {
          responsePrint("event","timestamp:%d,eventName:RAIL_EVENT_%s",puVar1[6],eventNames[uVar3]);
        }
      }
      puVar1 = puVar1 + 4;
    }
    if (local_d8[0] != 0) {
      responsePrintError("printEventsMissed",'6',
                         "Event queue limited to %d callbacks. %d callbacks not enqueued.",10);
    }
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void main(void)

{
  RAIL_Status_t_enum RVar1;
  _Bool _Var2;
  bool bVar3;
  uint16_t uVar4;
  uint uVar5;
  uint uVar6;
  EMU *pEVar7;
  undefined *puVar8;
  undefined4 uVar9;
  undefined4 in_stack_ffffffd8;
  RAIL_StateTransitions_t in_stack_ffffffdc;
  undefined2 in_stack_ffffffde;
  undefined local_20 [2];
  uint16_t local_1e;
  uint16_t local_1c;
  
  uVar5 = read_volatile_4(DAT_0fe081fc);
  SYSTEM_ChipRevisionGet((SYSTEM_ChipRevision_TypeDef *)local_20);
  if (uVar5 >> 0x18 < 0x8f) {
    uVar5 = read_volatile_4(Peripherals::CMU.HFBUSCLKEN0);
    write_volatile_4(Peripherals::CMU.HFBUSCLKEN0,uVar5 | 4);
    write_volatile_4(Peripherals::GPIO.PA_CTRL,0x500050);
    write_volatile_4(Peripherals::GPIO.PB_CTRL,0x500050);
    write_volatile_4(Peripherals::GPIO.PC_CTRL,0x500050);
    write_volatile_4(Peripherals::GPIO.PD_CTRL,0x500050);
    write_volatile_4(Peripherals::GPIO.PE_CTRL,0x500050);
    write_volatile_4(Peripherals::GPIO.PF_CTRL,0x500050);
    write_volatile_4(Peripherals::CMU.HFBUSCLKEN0,uVar5);
  }
  else {
    if (0x8f < uVar5 >> 0x18) goto LAB_00004182;
  }
  uVar5 = read_volatile_4(Peripherals::CMU.HFXOSTARTUPCTRL);
  write_volatile_4(Peripherals::CMU.HFXOSTARTUPCTRL,uVar5 & 0xffffff80 | 0x20);
LAB_00004182:
  if (local_20[1] == '\x01') {
    uVar5 = read_volatile_4(Peripherals::EMU.BIASCONF);
    write_volatile_4(Peripherals::EMU.BIASCONF,uVar5 | 4);
  }
  pEVar7 = (EMU *)&DAT_43c60ab4;
  uVar6 = 0;
  _DAT_43c60ab4 = 0;
  uVar5 = RMU_ResetCauseGet();
  RMU_ResetCauseClear();
  uVar5 = uVar5 & 0x10000;
  if (uVar5 != 0) {
    pEVar7 = &Peripherals::EMU;
    uVar6 = 1;
  }
  if (uVar5 != 0) {
    pEVar7->CMD = uVar6;
  }
  appHalInit();
  railHandle = RAIL_Init(&railCfg,0x35c9);
  local_20[0] = '\0';
  local_1e = 0x708;
  local_1c = 10;
  if (channelConfigs->configs->baseFrequency < 1000000) {
    local_20[0] = '\x02';
  }
  RVar1 = RAIL_ConfigTxPower(railHandle,(RAIL_TxPowerConfig_t *)local_20);
  if (RVar1 != RAIL_STATUS_NO_ERROR) {
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  RAIL_SetTxPower(railHandle,0xfc);
  uVar4 = RAIL_SetTxFifo(railHandle,txFifo,0,0x200);
  if (uVar4 != 0x200) {
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  RAIL_ConfigCal(railHandle,0x10001);
  RAIL_ConfigChannels(railHandle,channelConfigs,0x354d);
  RAIL_ConfigEvents(railHandle,0x23fff3fff,
                    CONCAT26(in_stack_ffffffde,CONCAT24(in_stack_ffffffdc,in_stack_ffffffd8)));
  RAIL_ConfigRxOptions(railHandle,0xffffffff,0);
  RAIL_SetRxTransitions(railHandle,(RAIL_StateTransitions_t *)&stack0xffffffdc);
  rxSuccessTransition = '\x02';
  RAIL_SetTxTransitions(railHandle,(RAIL_StateTransitions_t *)&stack0xffffffdc);
  _Var2 = queueInit(&rxPacketQueue,10);
  if (_Var2 != false) {
    updateDisplay();
    puts("\nRAIL Test App");
    if (uVar5 != 0) {
      uVar5 = read_volatile_4(Peripherals::EMU.EM4CTRL);
      if ((uVar5 & 1) == 0) {
        uVar9 = 0x73;
      }
      else {
        uVar9 = 0x68;
      }
      bVar3 = RAIL_IsRfSensed(railHandle);
      puVar8 = &DAT_00012f69;
      if (bVar3 != false) {
        puVar8 = &DAT_00012f65;
      }
      responsePrint("sleepWoke","EM:4%c,SerialWakeup:No,RfSensed:%s",uVar9,puVar8);
    }
    iprintf("> ");
    ciInitState(&ciState,ciBuffer,0x100,commands);
    for (uVar5 = (uint)txDataLen; uVar5 < 0x1f8; uVar5 = uVar5 + 1) {
      txData[uVar5] = (uint8_t)uVar5;
    }
    RAIL_WriteAutoAckFifo(railHandle,ackData,ackDataLen);
    RAIL_StartRx(railHandle,channel,(undefined *)0x0);
    receiveModeEnabled = true;
    do {
      processInputCharacters();
      rfSensedCheck();
      sendPacketIfPending();
      finishTxSequenceIfPending();
      changeAppModeIfPending();
      printReceivedPacket();
      printNewTxError();
      printEvents();
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
  appModes[8] = (char *)((int)
                         "BitsToTest:%u,BitsTested:0,PercentDone:0.00,RSSI:%d,BitErrors:0,PercentBitError:0.00,Status:TestAbortedRxOverflow"
                        + 0x67);
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
  AppMode_t appMode;
  AppMode_t AVar1;
  char *command;
  char *pcVar2;
  char *pcVar3;
  uint32_t uVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  command = nextCommand;
  AVar1 = currAppMode;
  if (transitionPend == false) {
    return;
  }
  transitionPend = false;
  uVar6 = (uint)nextAppMode;
  if (enableMode == false) {
    uVar6 = 0;
  }
  appMode = (AppMode_t)uVar6;
  if ((uint)currAppMode == (uint)nextAppMode) {
    if (enableMode != false) {
      if (nextCommand != (char *)0x0) {
        pcVar2 = appModeNames(appMode);
        responsePrint(command,"%s:Enabled",pcVar2);
        return;
      }
      transitionPend = false;
      return;
    }
    if (nextCommand != (char *)0x0) {
LAB_000044c6:
      pcVar2 = appModeNames(appMode);
      pcVar3 = appModeNames(AVar1);
      uVar4 = RAIL_GetTime();
      responsePrint(command,"%s:Enabled,%s:Disabled,Time:%u",pcVar2,pcVar3,uVar4);
    }
    uVar7 = (uint)currAppMode;
    if (uVar7 != 0) {
      if (uVar7 - 1 < 2) {
        RAIL_StopTxStream(railHandle);
        goto LAB_000044f4;
      }
      if (uVar7 == 4) {
        RAIL_EnableDirectMode(railHandle,false);
        goto LAB_000044f4;
      }
      if (uVar7 < 0xb) {
        uVar8 = ~(0x668U >> uVar7) & 1;
        if (uVar8 == 0) {
          RAIL_CancelTimer(railHandle);
          txCount = uVar8;
          pendFinishTxSequence();
          goto LAB_000044f4;
        }
      }
      else {
        if (uVar7 == 0xb) {
          RAIL_StartRfSense(railHandle,'\0',0,(undefined4 *)0x0);
          goto LAB_000044f4;
        }
      }
      if (uVar7 != 0xc) {
        if (uVar7 == 0xd) {
          RAIL_Idle(railHandle,RAIL_IDLE_ABORT,false);
        }
        goto LAB_000044f4;
      }
    }
  }
  else {
    if (currAppMode != 0) {
      if (nextCommand == (char *)0x0) {
        transitionPend = false;
        return;
      }
      pcVar2 = "disable";
      if (enableMode != false) {
        pcVar2 = "enable";
      }
LAB_000045dc:
      pcVar3 = appModeNames(nextAppMode);
      pcVar5 = appModeNames(AVar1);
      responsePrintError(command,'\x01',"Can\'t %s %s during %s",pcVar2,pcVar3,pcVar5);
      return;
    }
    if (enableMode == false) {
      if (nextCommand == (char *)0x0) {
        transitionPend = false;
        return;
      }
      pcVar2 = "disable";
      goto LAB_000045dc;
    }
    if (nextCommand != (char *)0x0) goto LAB_000044c6;
  }
  RAIL_CancelTimer(railHandle);
LAB_000044f4:
  AVar1 = currAppMode;
  if (uVar6 != 1) {
    if (uVar6 != 2) {
      if (uVar6 == 4) {
        RAIL_EnableDirectMode(railHandle,true);
        prevAppMode = currAppMode;
        currAppMode = appMode;
        return;
      }
      if ((uVar6 != 3) && (uVar6 != 5)) {
        if ((uVar6 != 6) && (uVar6 != 10)) {
          if (1 < uVar6 - 7) {
            currAppMode = appMode;
            prevAppMode = AVar1;
            return;
          }
          RAIL_StartRx(railHandle,channel,(undefined *)0x0);
          prevAppMode = currAppMode;
          currAppMode = appMode;
          return;
        }
        txCount = 1;
      }
      pendPacketTx();
      prevAppMode = currAppMode;
      currAppMode = appMode;
      return;
    }
    uVar6 = 0;
  }
  RAIL_StartTxStream(railHandle,channel,(RAIL_StreamMode_t_enum)uVar6);
  prevAppMode = currAppMode;
  currAppMode = appMode;
  return;
}



void rxFifoPrep(void)

{
  AppMode_t AVar1;
  
  if (((railDataConfig.rxMethod == '\x01') && (AVar1 = currentAppMode(), AVar1 != BER)) &&
     (rxFifoManual == false)) {
    rxLengthCount = rxLengthTarget;
    rxFifoPacketHandle = memoryAllocate((uint)rxLengthTarget);
    rxFifoPacketData = (RxPacketData_t *)memoryPtrFromHandle(rxFifoPacketHandle);
    currentRxFifoPacketPtr = (uint8_t *)&rxFifoPacketData->field_0x16;
  }
  return;
}



void loadTxData(uint8_t *data,uint16_t dataLen)

{
  uint16_t uVar1;
  
  if (railDataConfig.txMethod == '\0') {
    RAIL_WriteTxFifo(railHandle,data,dataLen,true);
    return;
  }
  uVar1 = RAIL_WriteTxFifo(railHandle,data,dataLen,false);
  dataLeft = dataLen - uVar1;
  dataLeftPtr = data + uVar1;
  return;
}



void configRxLengthSetting(uint16_t rxLength)

{
  if (railDataConfig.rxMethod == '\x01') {
    rxLengthTarget = rxLength;
  }
  return;
}



void RAILCb_TxPacketSent(RAIL_Handle_t railHandle,_Bool isAck)

{
  LedToggle(1);
  redrawDisplay = true;
  if (isAck != 0) {
    sentAckPackets = sentAckPackets + 1;
    previousTxAckAppendedInfo.timeSent.totalPacketBytes = 0;
    previousTxAckAppendedInfo.timeSent.timePosition = '\x01';
    RAIL_GetTxPacketDetails(railHandle,&previousTxAckAppendedInfo);
    pendFinishTxAckSequence();
    return;
  }
  internalTransmitCounter = internalTransmitCounter + 1;
  previousTxAppendedInfo.timeSent.timePosition = '\x01';
  previousTxAppendedInfo.timeSent.totalPacketBytes = (uint)isAck;
  RAIL_GetTxPacketDetails(railHandle,&previousTxAppendedInfo);
  scheduleNextTx();
  return;
}



void RAILCb_TxFifoAlmostEmpty(RAIL_Handle_t railHandle)

{
  uint16_t uVar1;
  
  counters.txFifoAlmostEmpty = counters.txFifoAlmostEmpty + 1;
  if (dataLeft != 0) {
    uVar1 = RAIL_WriteTxFifo(railHandle,dataLeftPtr,dataLeft,false);
    dataLeft = dataLeft - uVar1;
    dataLeftPtr = dataLeftPtr + uVar1;
  }
  return;
}



void RAILCb_RxFifoAlmostFull(RAIL_Handle_t railHandle)

{
  uint16_t uVar1;
  uint16_t uVar2;
  int16_t iVar3;
  uint32_t uVar4;
  uint16_t readLength;
  uint32_t uVar5;
  uint32_t uVar6;
  uint uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  undefined4 in_stack_ffffffd0;
  undefined4 in_stack_ffffffd4;
  
  uVar1 = RAIL_GetRxFifoBytesAvailable(railHandle);
  counters.rxFifoAlmostFull = counters.rxFifoAlmostFull + 1;
  uVar10 = (uint)berTestModeEnabled;
  if (uVar10 == 0) {
    bVar12 = RAIL_BLE_IsEnabled(railHandle);
    if (bVar12 == false) {
      if (rxLengthCount != 0) {
        readLength = rxLengthCount;
        if (uVar1 <= rxLengthCount) {
          readLength = uVar1;
        }
        uVar1 = RAIL_ReadRxFifo(::railHandle,currentRxFifoPacketPtr,readLength);
        rxLengthCount = rxLengthCount - uVar1;
        currentRxFifoPacketPtr = currentRxFifoPacketPtr + uVar1;
      }
    }
    else {
      RAIL_ConfigEvents(railHandle,0,CONCAT44(in_stack_ffffffd4,in_stack_ffffffd0));
    }
  }
  else {
    uVar7 = counters.rxOfEvent;
    if (counters.rxOfEvent != 0) {
      uVar7 = 1;
    }
    while( true ) {
      uVar1 = RAIL_GetRxFifoBytesAvailable(::railHandle);
      uVar2 = RAIL_GetRxFifoThreshold(::railHandle);
      if ((uVar1 <= uVar2) || (uVar7 != 0)) break;
      uVar1 = RAIL_ReadRxFifo(::railHandle,txData,0x1f8);
      uVar4 = uVar7;
      uVar6 = berStats.bytesTested;
      uVar8 = uVar7;
      uVar11 = uVar7;
      uVar5 = berStats.bitErrors;
      while (((uVar4 & 0xffff) < (uint)uVar1 && (uVar8 == 0))) {
        uVar9 = uVar10;
        if (uVar6 < berStats.bytesTotal) {
          uVar5 = uVar5 + ((uint)(byte)(&nibblebits_10255)[txData[uVar4] & 0xf] +
                           (uint)(byte)(&nibblebits_10255)[txData[uVar4] >> 4] & 0xff);
          uVar6 = uVar6 + 1;
          uVar7 = uVar10;
          uVar9 = uVar8;
          uVar11 = uVar10;
        }
        uVar4 = uVar4 + 1;
        uVar8 = uVar9;
      }
      if (uVar11 != 0) {
        berStats.bytesTested = uVar6;
      }
      bVar12 = uVar7 != 0;
      uVar7 = uVar8;
      if (bVar12) {
        berStats.bitErrors = uVar5;
      }
    }
    iVar3 = RAIL_GetRssi(::railHandle,true);
    berStats.rssi = (int8_t)((uint)(int)iVar3 / 4);
    if (uVar7 != 0) {
      RAIL_Idle(::railHandle,RAIL_IDLE_FORCE_SHUTDOWN,true);
      RAIL_ResetFifo(::railHandle,true,true);
      berTestModeEnabled = false;
    }
  }
  return;
}



void setNextPacketTime(RAIL_ScheduleTxConfig_t *scheduledTxOptions)

{
  nextPacketTxTime.when = scheduledTxOptions->when;
  nextPacketTxTime._4_4_ = *(undefined4 *)&scheduledTxOptions->mode;
  return;
}



void RAILCb_RxPacketReceived(RAIL_Handle_t railHandle)

{
  RxPacketData_t *pPacketDetails;
  RAIL_Handle_t railHandle_00;
  _Bool _Var1;
  AppMode_t AVar2;
  bool bVar3;
  uint16_t uVar4;
  RAIL_RxPacketHandle_t packetHandle;
  void *handle;
  RAIL_RxPacketDetails_t *pPacketDetails_00;
  void *pvVar5;
  uint uVar6;
  uint __n;
  RAIL_ScheduleTxConfig_t scheduledTxOptions;
  RAIL_RxPacketInfo_t packetInfo;
  
  counters.receive = counters.receive + 1;
  LedToggle(0);
  if (railDataConfig.rxMethod == '\0') {
    packetHandle = RAIL_GetRxPacketInfo(railHandle,(RAIL_RxPacketHandle_t)0x2,&packetInfo);
    uVar6 = (uint)packetInfo.packetBytes;
    handle = memoryAllocate(uVar6 + 0x18);
    pPacketDetails_00 = (RAIL_RxPacketDetails_t *)memoryPtrFromHandle(handle);
    if (pPacketDetails_00 != (RAIL_RxPacketDetails_t *)0x0) {
      __n = (uint)packetInfo.firstPortionBytes;
      pvVar5 = memcpy((void *)((int)&pPacketDetails_00[1].timeReceived.packetTime + 2),
                      packetInfo.firstPortionData,__n);
      if (uVar6 != __n) {
        memcpy((void *)((int)pvVar5 + __n),packetInfo.lastPortionData,uVar6 - __n);
      }
      (pPacketDetails_00->timeReceived).timePosition = '\x01';
      *(uint16_t *)&pPacketDetails_00[1].timeReceived.packetTime = packetInfo.packetBytes;
      (pPacketDetails_00->timeReceived).totalPacketBytes = 0;
      RAIL_GetRxPacketDetails(railHandle,packetHandle,pPacketDetails_00);
    }
    if ((rxSuccessTransition == '\x04') ||
       ((bVar3 = RAIL_IsAutoAckEnabled(railHandle), bVar3 != false &&
        (afterRxUseTxBufferForAck != false)))) {
      RAIL_WriteTxFifo(railHandle,txData,txDataLen,true);
    }
    if (pPacketDetails_00 == (RAIL_RxPacketDetails_t *)0x0) {
      counters.noRxBuffer = counters.noRxBuffer + 1;
    }
    else {
      if (*(char *)&pPacketDetails_00[1].timeReceived.totalPacketBytes == -0xf) {
        RAIL_CancelAutoAck(railHandle);
      }
      if (afterRxCancelAck != false) {
        afterRxCancelAck = false;
        RAIL_CancelAutoAck(railHandle);
      }
      if (afterRxUseTxBufferForAck != false) {
        afterRxUseTxBufferForAck = false;
        RAIL_UseTxFifoForAutoAck(railHandle);
      }
      AVar2 = currentAppMode();
      if (AVar2 == SCHTX_AFTER_RX) {
        scheduledTxOptions.when = (pPacketDetails_00->timeReceived).packetTime + txAfterRxDelay;
        scheduledTxOptions._4_2_ = 0;
        setNextPacketTime(&scheduledTxOptions);
        txCount = 1;
        pendPacketTx();
      }
      if ((int)((uint)logLevel << 0x1e) < 0) {
        redrawDisplay = true;
        memoryTakeReference(handle);
        queueAdd(&rxPacketQueue,handle);
      }
      updateStats((int)pPacketDetails_00->rssi,&counters.rssi);
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
    memoryFree(handle);
  }
  else {
    if (rxFifoManual == false) {
      AVar2 = currentAppMode();
      if (AVar2 == BER) {
        RAIL_ResetFifo(::railHandle,true,true);
      }
      else {
        if (rxLengthCount != 0) {
          uVar4 = RAIL_ReadRxFifo(::railHandle,currentRxFifoPacketPtr,rxLengthCount);
          rxLengthCount = rxLengthCount - uVar4;
          currentRxFifoPacketPtr = currentRxFifoPacketPtr + uVar4;
        }
        railHandle_00 = ::railHandle;
        pPacketDetails = rxFifoPacketData;
        rxFifoPacketData->dataLength = rxLengthTarget;
        (pPacketDetails->appendedInfo).timeReceived.timePosition = '\x01';
        (pPacketDetails->appendedInfo).timeReceived.totalPacketBytes = 0;
        RAIL_GetRxPacketDetails(railHandle_00,FUN_00000000 + 1,&pPacketDetails->appendedInfo);
        queueAdd(&rxPacketQueue,rxFifoPacketHandle);
      }
    }
  }
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
  RAIL_RadioState_t_enum RVar1;
  uint uVar2;
  char *pcVar4;
  uint uVar5;
  uint uVar3;
  
  uVar2 = (uint)state;
  RVar1 = RAIL_GetRadioState();
  uVar3 = (uint)RVar1;
  if (uVar2 < 6) {
    uVar5 = 1 << uVar2;
    if ((uVar5 & 0x29) == 0) {
      if ((uVar5 & 0x14) == 0) {
        if (-1 < (int)(uVar5 << 0x1e)) goto LAB_00004b72;
        pcVar4 = (char *)(uint)(uVar3 < 2);
      }
      else {
        pcVar4 = (char *)(uint)((uVar2 & ~uVar3) == 0);
      }
    }
    else {
      pcVar4 = (char *)(uint)(uVar3 == uVar2);
    }
    if (pcVar4 != (char *)0x0) goto LAB_00004b94;
  }
LAB_00004b72:
  pcVar4 = command;
  if (command != (char *)0x0) {
    pcVar4 = getRfStateName(state);
    responsePrintError(command,'\x17',"Need to be in %s radio state for this command",pcVar4);
    pcVar4 = (char *)0x0;
  }
LAB_00004b94:
  return SUB41(pcVar4,0);
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
  
  if ((0 < txCount) || (AVar1 = currentAppMode(), AVar1 == TX_CONTINUOUS)) {
    RAIL_SetTimer(railHandle,continuousTransferPeriod * 1000,'\x01',0x35dd);
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
  void *pvVar1;
  
  if (size < 0x201) {
    irqState = CORE_EnterCritical();
    pvVar1 = (void *)0x0;
    do {
      if (memoryObjs[(int)pvVar1].refCount == 0) {
        memoryObjs[(int)pvVar1].refCount = 1;
        goto LAB_00004ce4;
      }
      pvVar1 = (void *)((int)pvVar1 + 1);
    } while (pvVar1 != (void *)0xa);
    pvVar1 = (void *)0xffffffff;
LAB_00004ce4:
    CORE_ExitCritical(irqState);
  }
  else {
    pvVar1 = (void *)0xffffffff;
  }
  return pvVar1;
}



void * memoryPtrFromHandle(void *handle)

{
  CORE_irqState_t irqState;
  uint8_t *puVar1;
  
  if ((handle == (void *)0xffffffff) || ((void *)0x9 < handle)) {
    puVar1 = (uint8_t *)0x0;
  }
  else {
    irqState = CORE_EnterCritical();
    puVar1 = (uint8_t *)memoryObjs[(int)handle].refCount;
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
    memoryObjs[(int)handle].refCount = memoryObjs[(int)handle].refCount - 1;
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
    memoryObjs[(int)handle].refCount = memoryObjs[(int)handle].refCount + 1;
  }
  CORE_ExitCritical(irqState);
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
  char *__format;
  char *pcVar2;
  CommandEntry_t *pCVar3;
  char *pcVar4;
  size_t sVar5;
  
  pcVar4 = (char *)0x0;
  sVar5 = 0;
  for (pCVar3 = commands; (pCVar3 != (CommandEntry_t *)0x0 && (pCVar3->command != (char *)0x0));
      pCVar3 = pCVar3 + 1) {
    sVar1 = strlen(pCVar3->command);
    pcVar2 = pCVar3->arguments;
    if (pcVar2 != (char *)0x0) {
      pcVar2 = (char *)strlen(pcVar2);
    }
    if ((int)sVar5 < (int)sVar1) {
      sVar5 = sVar1;
    }
    if ((int)pcVar4 < (int)pcVar2) {
      pcVar4 = pcVar2;
    }
  }
  puts("<command> <args> <help text>");
  puts("  u=uint8, v=uint16, w=uint32, s=int32, b=string, ?=Anything, *=0 or more of previous");
  do {
    if ((commands == (CommandEntry_t *)0x0) || (pcVar2 = commands->command, pcVar2 == (char *)0x0))
    {
      return true;
    }
    __format = " --- %s ---";
    if (commands->callback == FUN_00000000) {
LAB_00004f2c:
      iprintf(__format,pcVar2);
    }
    else {
      iprintf("%*s",-sVar5);
      pcVar2 = commands->arguments;
      if (pcVar2 == (char *)0x0) {
        pcVar2 = "";
      }
      else {
        if (*pcVar2 == '\0') {
          pcVar2 = "";
        }
      }
      iprintf(" %*s",-(int)pcVar4,pcVar2);
      pcVar2 = commands->helpStr;
      if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {
        __format = " %s";
        goto LAB_00004f2c;
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
  char cVar10;
  CommandEntry_t *commands;
  char *pcVar11;
  uint uVar12;
  char *__s;
  CommandEntry_t *pCVar13;
  CommandEntry_t *__s2;
  byte bVar14;
  uint local_a0;
  char *saveptr;
  char *argv [20];
  
  if ((state == (CommandState_t *)0x0) || (data == (char *)0x0)) {
    cVar10 = -1;
  }
  else {
    uVar12 = state->offset;
    if (uVar12 + length < state->length) {
      memcpy(state->buffer + uVar12,data,length);
      state->offset = state->offset + length;
      cVar10 = '\0';
      local_a0 = 0;
LAB_00004fae:
      if (uVar12 < state->offset) {
        cVar1 = state->buffer[uVar12];
        if ((cVar1 == '\n') || (cVar1 == '\r')) {
          state->buffer[uVar12] = '\0';
          if (uVar12 != local_a0) {
            commands = state->commands;
            __s = state->buffer + local_a0;
            pcVar8 = __s + -1;
            pcVar11 = __s;
            while( true ) {
              pcVar8 = pcVar8 + 1;
              cVar2 = *pcVar8;
              if (cVar2 == '\0') break;
              if (cVar2 == '\b') {
                if (__s < pcVar11) {
                  pcVar11 = pcVar11 + -1;
                }
              }
              else {
                *pcVar11 = cVar2;
                pcVar11 = pcVar11 + 1;
              }
            }
            *pcVar11 = '\0';
            pcVar8 = strtok_r(__s,"\n\r ",&saveptr);
            pCVar13 = commands;
            if (pcVar8 == (char *)0x0) goto LAB_0000500e;
            for (; pCVar13 != (CommandEntry_t *)0x0; pCVar13 = pCVar13 + 1) {
              __s2 = (CommandEntry_t *)pCVar13->command;
              if (__s2 == (CommandEntry_t *)0x0) goto LAB_000050a2;
              if ((pCVar13->callback != FUN_00000000) &&
                 (iVar4 = strcasecmp(pcVar8,(char *)__s2), iVar4 == 0)) {
                argv[0] = (char *)__s2;
                pcVar8 = strtok_r((char *)0x0,"\n\r ",&saveptr);
                iVar4 = 1;
                goto LAB_00005166;
              }
            }
            __s2 = pCVar13;
            if (commands != (CommandEntry_t *)0x0) goto LAB_000051c6;
            goto LAB_000050ba;
          }
          goto LAB_0000500e;
        }
        goto LAB_00005032;
      }
      if (local_a0 != 0) {
        sVar9 = state->offset - local_a0;
        state->offset = sVar9;
        memmove(state->buffer,state->buffer + local_a0,sVar9);
      }
    }
    else {
      cVar10 = -2;
    }
  }
  return (int8_t)cVar10;
LAB_00005166:
  if (pcVar8 == (char *)0x0) goto code_r0x0000516e;
  argv[iVar4] = pcVar8;
  iVar4 = iVar4 + 1;
  if (iVar4 == 0x14) {
    error = CI_MAX_ARGUMENTS;
    goto LAB_0000505a;
  }
  pcVar8 = strtok_r((char *)0x0,"\n\r ",&saveptr);
  goto LAB_00005166;
code_r0x0000516e:
  pcVar11 = pCVar13->arguments;
  if ((pcVar11 == (char *)0x0) || (iVar5 = strcmp(pcVar11,"?"), iVar5 == 0)) {
LAB_00005096:
    (*pCVar13->callback)(iVar4,argv);
    __s2 = (CommandEntry_t *)(FUN_00000000 + 1);
LAB_000050a2:
    if ((pCVar13->command == (char *)0x0) && (commands != (CommandEntry_t *)0x0)) {
LAB_000051c6:
      iVar4 = strcasecmp(__s,"help");
      if (iVar4 == 0) {
        _Var3 = ciPrintHelp(commands);
        __s2 = (CommandEntry_t *)(uint)_Var3;
      }
    }
    if ((__s2 != (CommandEntry_t *)0x0) || (pcVar8 == (char *)0x0)) goto LAB_0000500e;
LAB_000050ba:
    __s = pcVar8;
    error = CI_UNKNOWN_COMMAND;
  }
  else {
    sVar6 = strlen(pcVar11);
    pcVar7 = strchr(pcVar11,0x2a);
    sVar9 = sVar6;
    if (pcVar7 == (char *)0x0) {
LAB_00005078:
      bVar14 = 0x2e;
      for (iVar5 = 1; iVar4 != iVar5; iVar5 = iVar5 + 1) {
        if (iVar5 + -1 < (int)sVar6) {
          if (pcVar11[iVar5 + -1] != 0x2a) {
            bVar14 = pcVar11[iVar5 + -1];
          }
        }
        else {
          if (pcVar11[sVar6 - 1] != '*') goto LAB_000051a6;
        }
        if (bVar14 == 0x75) {
          _Var3 = false;
          lengthInBytes = 1;
LAB_00005114:
          _Var3 = validateInteger(argv[iVar5],lengthInBytes,_Var3);
          if (_Var3 == false) goto LAB_000051a6;
        }
        else {
          if (0x75 < bVar14) {
            if (bVar14 == 0x76) {
              _Var3 = false;
              lengthInBytes = 2;
              goto LAB_00005114;
            }
            if (bVar14 == 0x77) {
              _Var3 = false;
              goto LAB_0000510c;
            }
            goto LAB_000051a6;
          }
          if (bVar14 != 0x62) {
            if (bVar14 == 0x73) {
              _Var3 = true;
LAB_0000510c:
              lengthInBytes = 4;
              goto LAB_00005114;
            }
            goto LAB_000051a6;
          }
        }
      }
      if ((int)sVar9 < iVar4) goto LAB_00005096;
    }
    else {
      if ((pcVar7 == pcVar11 + (sVar6 - 1)) && (sVar6 != 1)) {
        sVar9 = sVar6 - 2;
        goto LAB_00005078;
      }
    }
LAB_000051a6:
    error = CI_INVALID_ARGUMENTS;
  }
LAB_0000505a:
  ciErrorCallback(__s,error);
LAB_0000500e:
  if (((cVar1 != '\n') || (state->prevEol != '\r')) || (uVar12 != local_a0)) {
    cVar10 = cVar10 + '\x01';
  }
  local_a0 = uVar12 + 1;
  state->prevEol = cVar1;
LAB_00005032:
  uVar12 = uVar12 + 1;
  goto LAB_00004fae;
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
switchD_00005202_caseD_74:
    return false;
  }
  switch(type) {
  case 's':
    lengthInBytes = 4;
    _Var1 = true;
    goto LAB_0000521a;
  default:
    goto switchD_00005202_caseD_74;
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
LAB_0000521a:
  _Var1 = validateInteger(arg,lengthInBytes,_Var1);
  return _Var1;
}



void LDMA_IRQHandler(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  _Bool _Var4;
  uint uVar5;
  ChTable_t *pCVar6;
  uint uVar7;
  uint uVar8;
  
  uVar2 = read_volatile_4(Peripherals::LDMA.IF);
  uVar3 = read_volatile_4(Peripherals::LDMA.IEN);
  if ((int)(uVar2 & uVar3) < 0) {
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  pCVar6 = chTable;
  uVar8 = 1;
  uVar7 = 0;
  do {
    if ((uVar2 & uVar3 & uVar8) != 0) {
      write_volatile_4(Peripherals::LDMA.IFC,uVar8);
      if (pCVar6->callback != FUN_00000000) {
        uVar5 = pCVar6->callbackCount + 1;
        pCVar6->callbackCount = uVar5;
        _Var4 = (*pCVar6->callback)(uVar7,uVar5,pCVar6->userParam);
        if ((pCVar6->mode == dmaModePingPong) && (_Var4 == false)) {
          bVar1 = *(byte *)&dmaXfer[uVar7].desc[1].field_0xc;
          *(byte *)&dmaXfer[uVar7].desc[0].field_0xc =
               *(byte *)&dmaXfer[uVar7].desc[0].field_0xc & 0xfd;
          *(byte *)&dmaXfer[uVar7].desc[1].field_0xc = bVar1 & 0xfd;
        }
      }
    }
    uVar7 = uVar7 + 1;
    uVar8 = uVar8 << 1;
    pCVar6 = pCVar6 + 1;
  } while (uVar7 != 8);
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



void checkAllTimers(uint32_t timeElapsed)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  Timer_t *pTVar5;
  uint uVar6;
  int iVar7;
  bool bVar8;
  
  pTVar5 = timer;
  do {
    pTVar5->doCallback = false;
    if (pTVar5->running != false) {
      uVar1 = *(uint *)&pTVar5->remaining;
      iVar3 = *(int *)((int)&pTVar5->remaining + 4);
      bVar8 = iVar3 == 0;
      if (iVar3 == 0) {
        bVar8 = uVar1 <= timeElapsed;
      }
      if (bVar8) {
        if (pTVar5->timerType == rtcdrvTimerTypeOneshot) {
          pTVar5->running = false;
        }
        else {
          uVar6 = *(uint *)&pTVar5->ticks;
          iVar7 = *(int *)((int)&pTVar5->ticks + 4);
          uVar2 = uVar6;
          iVar4 = iVar7;
          __aeabi_uldivmod(timeElapsed - uVar1,-(uint)(timeElapsed < uVar1) - iVar3);
          uVar1 = uVar6 - uVar2;
          iVar3 = (iVar7 - iVar4) - (uint)(uVar6 < uVar2);
          iVar4 = pTVar5->periodicCompensationUsec;
          uVar2 = pTVar5->periodicDriftUsec;
          *(uint *)&pTVar5->remaining = uVar1;
          *(int *)((int)&pTVar5->remaining + 4) = iVar3;
          if (iVar4 < 1) {
            uVar2 = uVar2 - iVar4;
            pTVar5->periodicDriftUsec = uVar2;
            if (0xf3 < uVar2) {
              iVar4 = uVar1 - 1;
              iVar3 = iVar3 + -1 + (uint)(uVar1 != 0);
              goto LAB_000053d0;
            }
          }
          else {
            uVar2 = iVar4 + uVar2;
            pTVar5->periodicDriftUsec = uVar2;
            if (0xf3 < uVar2) {
              iVar4 = uVar1 + 1;
              iVar3 = iVar3 + (uint)(0xfffffffe < uVar1);
LAB_000053d0:
              *(int *)&pTVar5->remaining = iVar4;
              *(int *)((int)&pTVar5->remaining + 4) = iVar3;
              pTVar5->periodicDriftUsec = uVar2 - 0xf4;
            }
          }
        }
        if (pTVar5->callback != FUN_00000000) {
          pTVar5->doCallback = true;
        }
      }
      else {
        *(uint *)&pTVar5->remaining = uVar1 - timeElapsed;
        *(uint *)((int)&pTVar5->remaining + 4) = iVar3 - (uint)(uVar1 < timeElapsed);
      }
    }
    pTVar5 = pTVar5 + 1;
    if (pTVar5 == (Timer_t *)&wallClockOverflowCnt) {
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



void updateInterrupts(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  TEMPDRV_CallbackSet_t *pTVar4;
  TEMPDRV_CallbackSet_t *pTVar5;
  
  iVar2 = 0;
  bVar1 = false;
  pTVar4 = highCallback;
  do {
    if (*(int *)((int)&tempdrvHighCallbacks[0].callback + iVar2) != 0) {
      pTVar5 = (TEMPDRV_CallbackSet_t *)((int)&tempdrvHighCallbacks[0].callback + iVar2);
      if (pTVar4->callback == FUN_00000000) {
        bVar1 = true;
        pTVar4 = pTVar5;
      }
      else {
        if (pTVar4->temp < (&tempdrvHighCallbacks[0].temp)[iVar2]) {
          bVar1 = true;
          pTVar4 = pTVar5;
        }
      }
    }
    iVar2 = iVar2 + 8;
  } while (iVar2 != 0x30);
  if (bVar1) {
    highCallback = pTVar4;
  }
  if (highCallback->callback == FUN_00000000) {
    uVar3 = read_volatile_4(Peripherals::EMU.IEN);
    uVar3 = uVar3 & 0xbfffffff;
  }
  else {
    uVar3 = read_volatile_4(Peripherals::EMU.TEMPLIMITS);
    write_volatile_4(Peripherals::EMU.TEMPLIMITS,uVar3 & 0xffffff00);
    uVar3 = read_volatile_4(Peripherals::EMU.TEMPLIMITS);
    write_volatile_4(Peripherals::EMU.TEMPLIMITS,highCallback->temp | uVar3);
    uVar3 = read_volatile_4(Peripherals::EMU.IEN);
    uVar3 = uVar3 | 0x40000000;
  }
  write_volatile_4(Peripherals::EMU.IEN,uVar3);
  iVar2 = 0;
  bVar1 = false;
  pTVar4 = lowCallback;
  do {
    if (*(int *)((int)&tempdrvLowCallbacks[0].callback + iVar2) != 0) {
      pTVar5 = (TEMPDRV_CallbackSet_t *)((int)&tempdrvLowCallbacks[0].callback + iVar2);
      if (pTVar4->callback == FUN_00000000) {
        bVar1 = true;
        pTVar4 = pTVar5;
      }
      else {
        if ((&tempdrvLowCallbacks[0].temp)[iVar2] < pTVar4->temp) {
          bVar1 = true;
          pTVar4 = pTVar5;
        }
      }
    }
    iVar2 = iVar2 + 8;
  } while (iVar2 != 0x30);
  if (bVar1) {
    lowCallback = pTVar4;
  }
  if (lowCallback->callback == FUN_00000000) {
    uVar3 = read_volatile_4(Peripherals::EMU.IEN);
    uVar3 = uVar3 & 0x7fffffff;
  }
  else {
    uVar3 = read_volatile_4(Peripherals::EMU.TEMPLIMITS);
    write_volatile_4(Peripherals::EMU.TEMPLIMITS,uVar3 & 0xffff00ff);
    uVar3 = read_volatile_4(Peripherals::EMU.TEMPLIMITS);
    write_volatile_4(Peripherals::EMU.TEMPLIMITS,uVar3 | (uint)lowCallback->temp << 8);
    uVar3 = read_volatile_4(Peripherals::EMU.IEN);
    uVar3 = uVar3 | 0x80000000;
  }
  write_volatile_4(Peripherals::EMU.IEN,uVar3);
  return;
}



int8_t TEMPDRV_GetTemp(void)

{
  undefined4 uVar1;
  
  read_volatile(Peripherals::EMU.TEMP._0_1_);
  uVar1 = SignedSaturate(calibrationTEMP,7);
  SignedDoesSaturate(calibrationTEMP,7);
  return (int8_t)uVar1;
}



void TEMPDRV_IRQHandler(void)

{
  uint uVar1;
  uint uVar2;
  TEMPDRV_CallbackSet_t *pTVar3;
  TEMPDRV_CallbackSet_t *pTVar4;
  int8_t iVar5;
  TEMPDRV_LimitType_t extraout_r1;
  TEMPDRV_Callback_t *pTVar6;
  
  pTVar4 = lowCallback;
  pTVar3 = highCallback;
  uVar2 = read_volatile_4(Peripherals::EMU.IEN);
  uVar1 = read_volatile_4(Peripherals::EMU.IF);
  if ((int)(uVar2 & uVar1) < 0) {
    pTVar6 = lowCallback->callback;
    if (pTVar6 != FUN_00000000) {
      lowCallback->callback = FUN_00000000;
      *(undefined4 *)&pTVar4->temp = 0;
      iVar5 = TEMPDRV_GetTemp();
      (*pTVar6)(iVar5,extraout_r1);
    }
    write_volatile_4(Peripherals::EMU.IFC,0x80000000);
  }
  else {
    if ((int)((uVar2 & uVar1) << 1) < 0) {
      pTVar6 = highCallback->callback;
      if (pTVar6 != FUN_00000000) {
        highCallback->callback = FUN_00000000;
        *(undefined4 *)&pTVar3->temp = 0;
        iVar5 = TEMPDRV_GetTemp();
        (*pTVar6)(iVar5,TEMPDRV_LIMIT_HIGH);
      }
      write_volatile_4(Peripherals::EMU.IFC,0x40000000);
    }
  }
  updateInterrupts();
  return;
}



void EMU_IRQHandler(void)

{
  uint uVar1;
  uint uVar2;
  TEMPDRV_CallbackSet_t *pTVar3;
  TEMPDRV_CallbackSet_t *pTVar4;
  int8_t iVar5;
  TEMPDRV_LimitType_t extraout_r1;
  TEMPDRV_Callback_t *pTVar6;
  
  pTVar4 = lowCallback;
  pTVar3 = highCallback;
  uVar2 = read_volatile_4(Peripherals::EMU.IEN);
  uVar1 = read_volatile_4(Peripherals::EMU.IF);
  if ((int)(uVar2 & uVar1) < 0) {
    pTVar6 = lowCallback->callback;
    if (pTVar6 != FUN_00000000) {
      lowCallback->callback = FUN_00000000;
      *(undefined4 *)&pTVar4->temp = 0;
      iVar5 = TEMPDRV_GetTemp();
      (*pTVar6)(iVar5,extraout_r1);
    }
    write_volatile_4(Peripherals::EMU.IFC,0x80000000);
  }
  else {
    if ((int)((uVar2 & uVar1) << 1) < 0) {
      pTVar6 = highCallback->callback;
      if (pTVar6 != FUN_00000000) {
        highCallback->callback = FUN_00000000;
        *(undefined4 *)&pTVar3->temp = 0;
        iVar5 = TEMPDRV_GetTemp();
        (*pTVar6)(iVar5,TEMPDRV_LIMIT_HIGH);
      }
      write_volatile_4(Peripherals::EMU.IFC,0x40000000);
    }
  }
  updateInterrupts();
  return;
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



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void setHfLeConfig(uint32_t hfFreq)

{
  uint uVar1;
  int iVar2;
  
  if (hfFreq < 0x1e84801) {
    iVar2 = 0;
    _DAT_43c80040 = iVar2;
  }
  else {
    if (hfFreq < 0x3d09001) {
      iVar2 = 1;
      _DAT_43c80040 = iVar2;
    }
    else {
      iVar2 = 2;
      _DAT_43c80040 = 1;
    }
  }
  uVar1 = read_volatile_4(Peripherals::CMU.HFPRESC);
  write_volatile_4(Peripherals::CMU.HFPRESC,uVar1 & 0xfeffffff | iVar2 << 0x18);
  return;
}



void flashWaitStateControl(uint32_t coreFreq,int vscale)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = read_volatile_4(Peripherals::MSC.LOCK);
  write_volatile_4(Peripherals::MSC.LOCK,0x1b71);
  if (coreFreq < 0x17d7841) {
    iVar3 = 0;
  }
  else {
    if (coreFreq < 0x2625a01) {
      iVar3 = 1;
    }
    else {
      iVar3 = 0;
    }
  }
  uVar1 = read_volatile_4(Peripherals::MSC.READCTRL);
  write_volatile_4(Peripherals::MSC.READCTRL,uVar1 & 0xfcffffff | iVar3 << 0x18);
  if (uVar2 != 0) {
    write_volatile_4(Peripherals::MSC.LOCK,0);
  }
  return;
}



void flashWaitStateMax(void)

{
  uint32_t coreFreq;
  int vscale;
  
  coreFreq = SystemMaxCoreClockGet();
  flashWaitStateControl(coreFreq,vscale);
  return;
}



void syncReg(uint32_t mask)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::CMU.FREEZE);
  if (-1 < (int)(uVar1 << 0x1f)) {
    do {
      uVar1 = read_volatile_4(Peripherals::CMU.SYNCBUSY);
    } while ((mask & uVar1) != 0);
  }
  return;
}



void CMU_OscillatorTuningSet(uint32_t val,CMU_Osc_TypeDef osc)

{
  uint uVar1;
  uint uVar2;
  
  read_volatile(Peripherals::CMU.STATUS._0_1_);
  uVar1 = read_volatile_4(Peripherals::CMU.HFXOCTRL);
  write_volatile_4(Peripherals::CMU.HFXOCTRL,uVar1 & 0xffffffcf | 0x10);
  uVar1 = read_volatile_4(Peripherals::CMU.HFXOSTEADYSTATECTRL);
  uVar2 = ((val << 0x15) >> 0x1c) + 3;
  if (0xe < uVar2) {
    uVar2 = 0xf;
  }
  write_volatile_4(Peripherals::CMU.HFXOSTEADYSTATECTRL,uVar1 & 0xffff800 | val | uVar2 << 0x1c);
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
      pCVar2 = &Peripherals::CMU;
      break;
    case 2:
      mask = 0;
      pCVar2 = (CMU *)&Peripherals::CMU.HFPERCLKEN0;
      break;
    default:
      goto switchD_00005796_caseD_3;
    case 5:
      pCVar2 = (CMU *)&Peripherals::CMU.HFBUSCLKEN0;
      mask = 0;
      break;
    case 6:
      mask = 1;
      pCVar2 = (CMU *)&Peripherals::CMU.LFACLKEN0;
      break;
    case 7:
      mask = 0x10;
      pCVar2 = (CMU *)&Peripherals::CMU.LFBCLKEN0;
      break;
    case 9:
      mask = 0x10000;
      pCVar2 = (CMU *)&Peripherals::CMU.LFECLKEN0;
      break;
    case 10:
      mask = 0;
      pCVar2 = (CMU *)&Peripherals::CMU.PCNTCTRL;
    }
    if (mask != 0) {
      syncReg(mask);
      uVar1 = extraout_r1;
    }
    *(uint *)((((clock << 0xf) >> 0x1b) + (int)&pCVar2[0x114fb].RFLOCK0 * 8) * 4) = uVar1;
  }
switchD_00005796_caseD_3:
  return;
}



uint32_t CMU_ClockPrescGet(CMU_Clock_TypeDef clock)

{
  uint uVar1;
  
  switch((clock << 0x18) >> 0x1c) {
  case 1:
    uVar1 = read_volatile_4(Peripherals::CMU.HFPRESC);
    break;
  case 2:
    uVar1 = read_volatile_4(Peripherals::CMU.HFEXPPRESC);
    break;
  case 3:
    uVar1 = read_volatile_4(Peripherals::CMU.HFPRESC);
    return (uVar1 << 7) >> 0x1f;
  case 4:
    uVar1 = read_volatile_4(Peripherals::CMU.HFPERPRESC);
    goto LAB_00005840;
  case 5:
    uVar1 = read_volatile_4(Peripherals::CMU.HFCOREPRESC);
LAB_00005840:
    return (uVar1 << 0xf) >> 0x17;
  case 6:
    if (clock != cmuClock_LETIMER0) {
      return 0;
    }
    uVar1 = read_volatile_4(Peripherals::CMU.LFAPRESC0);
    uVar1 = uVar1 & 0xf;
    goto LAB_0000585e;
  case 7:
    if (clock != cmuClock_LEUART0) {
      return 0;
    }
    uVar1 = read_volatile_4(Peripherals::CMU.LFBPRESC0);
    uVar1 = uVar1 & 3;
LAB_0000585e:
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
switchD_0000589e_caseD_4:
    return cmuSelect_Error;
  }
  switch(clock & 0xf) {
  case 1:
    uVar3 = read_volatile_4(Peripherals::CMU.HFCLKSTATUS);
    uVar3 = (uVar3 & 7) - 2;
    if (2 < uVar3) {
      return cmuSelect_HFRCO;
    }
    puVar2 = &CSWTCH_44;
    break;
  case 2:
    uVar3 = read_volatile_4(Peripherals::CMU.LFACLKSEL);
    uVar3 = (uVar3 & 7) - 1;
    if (3 < uVar3) {
      return cmuSelect_Disabled;
    }
    puVar2 = &DAT_000164d3;
    break;
  case 3:
    uVar3 = read_volatile_4(Peripherals::CMU.LFBCLKSEL);
    uVar3 = (uVar3 & 7) - 1;
    if (3 < uVar3) {
      return cmuSelect_Disabled;
    }
    puVar2 = &DAT_000164d7;
    break;
  default:
    goto switchD_0000589e_caseD_4;
  case 5:
    uVar3 = read_volatile_4(Peripherals::CMU.LFECLKSEL);
    uVar3 = (uVar3 & 7) - 1;
    if (3 < uVar3) {
      return cmuSelect_Disabled;
    }
    puVar2 = &DAT_000164d3;
    break;
  case 6:
    uVar3 = read_volatile_4(Peripherals::CMU.DBGCLKSEL);
    if ((uVar3 & 1) == 0) {
      CVar1 = cmuSelect_AUXHFRCO;
    }
    else {
      CVar1 = cmuSelect_HFCLK;
    }
    return CVar1;
  case 8:
    uVar3 = read_volatile_4(Peripherals::CMU.ADCCTRL);
    uVar3 = uVar3 & 0x30;
    if (uVar3 == 0x20) {
      return cmuSelect_HFXO;
    }
    if (uVar3 == 0x30) {
      return cmuSelect_HFSRCCLK;
    }
    if (uVar3 == 0x10) {
      CVar1 = cmuSelect_AUXHFRCO;
    }
    else {
      CVar1 = cmuSelect_Disabled;
    }
    return CVar1;
  }
  return (CMU_Select_TypeDef)puVar2[uVar3];
}



uint32_t lfClkGet(CMU_Clock_TypeDef lfClkBranch)

{
  CMU_Select_TypeDef CVar1;
  uint uVar2;
  uint uVar3;
  uint32_t uVar4;
  int extraout_r1;
  
  CVar1 = CMU_ClockSelectGet(lfClkBranch);
  uVar2 = (uint)CVar1;
  if (extraout_r1 == 0x1c0003) {
    uVar2 = read_volatile_4(Peripherals::CMU.LFBCLKSEL);
  }
  else {
    if (extraout_r1 == 0x200005) {
      uVar2 = read_volatile_4(Peripherals::CMU.LFECLKSEL);
    }
    else {
      if (extraout_r1 != 0x1a0002) goto LAB_00005974;
      uVar2 = read_volatile_4(Peripherals::CMU.LFACLKSEL);
    }
  }
  uVar2 = uVar2 & 7;
LAB_00005974:
  switch(uVar2) {
  case 1:
    uVar4 = SystemLFRCOClockGet();
    return uVar4;
  case 2:
    uVar4 = SystemLFXOClockGet();
    return uVar4;
  case 3:
    uVar3 = SystemCoreClockGet();
    uVar2 = read_volatile_4(Peripherals::CMU.HFPRESC);
    uVar4 = uVar3 / (uint)(1 << (1U - ((int)(uVar2 << 7) >> 0x1f) & 0xff));
    break;
  case 4:
    uVar4 = SystemULFRCOClockGet();
    return uVar4;
  default:
    uVar4 = 0;
  }
  return uVar4;
}



uint32_t CMU_ClockFreqGet(CMU_Clock_TypeDef clock)

{
  CMU_Select_TypeDef CVar1;
  uint uVar2;
  CMU_AUXHFRCOFreq_TypeDef CVar3;
  CMU_Clock_TypeDef lfClkBranch;
  uint uVar4;
  uint32_t uVar5;
  bool bVar6;
  
  uVar2 = clock & 0x3e0000;
  if (uVar2 == 0xe0000) {
    return auxHfrcoFreq;
  }
  if (0xe0000 < uVar2) {
    if (uVar2 == 0x1a0000) {
      lfClkBranch = cmuClock_LFA;
      goto LAB_00005a7c;
    }
    if (0x1a0000 < uVar2) {
      if (uVar2 != 0x200000) {
        if (uVar2 == 0x2e0000) {
          CVar1 = CMU_ClockSelectGet(cmuClock_ADC0ASYNC);
          if (CVar1 == cmuSelect_AUXHFRCO) {
            return auxHfrcoFreq;
          }
          if (CVar1 != cmuSelect_HFSRCCLK) {
            if (CVar1 != cmuSelect_HFXO) {
              return cmuAUXHFRCOFreq_UserDefined;
            }
            CVar3 = SystemHFXOClockGet();
            return CVar3;
          }
          uVar5 = SystemHFClockGet();
          uVar2 = read_volatile_4(Peripherals::CMU.HFPRESC);
          return ((uVar2 << 0x13) >> 0x1b) * uVar5 + uVar5;
        }
        if (uVar2 != 0x1c0000) {
          return cmuAUXHFRCOFreq_UserDefined;
        }
        lfClkBranch = cmuClock_LFB;
        goto LAB_00005a7c;
      }
LAB_00005a2e:
      lfClkBranch = cmuClock_LFE;
LAB_00005a7c:
      CVar3 = lfClkGet(lfClkBranch);
      return CVar3;
    }
    if (uVar2 == 0x140000) {
      uVar4 = lfClkGet(cmuClock_LFA);
      uVar2 = read_volatile_4(Peripherals::CMU.LFAPRESC0);
      uVar2 = uVar2 & 0xf;
    }
    else {
      if (uVar2 != 0x160000) {
        if (uVar2 != 0x120000) {
          return cmuAUXHFRCOFreq_UserDefined;
        }
        goto LAB_00005a2e;
      }
      uVar4 = lfClkGet(cmuClock_LFB);
      uVar2 = read_volatile_4(Peripherals::CMU.LFBPRESC0);
      uVar2 = uVar2 & 3;
    }
    uVar2 = 1 << uVar2;
    goto LAB_00005a58;
  }
  if (uVar2 == 0x40000) {
    uVar4 = SystemHFClockGet();
    uVar2 = read_volatile_4(Peripherals::CMU.HFPERPRESC);
LAB_00005a52:
    uVar2 = (uVar2 << 0xf) >> 0x17;
  }
  else {
    if (uVar2 < 0x40001) {
      if (uVar2 == 0) goto LAB_00005a0c;
      if (uVar2 != 0x20000) {
        return cmuAUXHFRCOFreq_UserDefined;
      }
      uVar4 = SystemHFClockGet();
      uVar2 = read_volatile_4(Peripherals::CMU.HFCOREPRESC);
      goto LAB_00005a52;
    }
    if (uVar2 != 0xa0000) {
      if (uVar2 == 0xc0000) {
        CVar1 = CMU_ClockSelectGet(cmuClock_DBG);
        if (CVar1 == cmuSelect_AUXHFRCO) {
          return auxHfrcoFreq;
        }
        bVar6 = CVar1 == cmuSelect_HFCLK;
      }
      else {
        bVar6 = uVar2 == 0x80000;
      }
      if (!bVar6) {
        return cmuAUXHFRCOFreq_UserDefined;
      }
LAB_00005a0c:
      CVar3 = SystemHFClockGet();
      return CVar3;
    }
    uVar4 = SystemHFClockGet();
    uVar2 = read_volatile_4(Peripherals::CMU.HFEXPPRESC);
    uVar2 = (uVar2 << 0x13) >> 0x1b;
  }
  uVar2 = uVar2 + 1;
LAB_00005a58:
  return uVar4 / uVar2;
}



void CMU_ClockPrescSet(CMU_Clock_TypeDef clock,CMU_ClkPresc_TypeDef presc)

{
  uint uVar1;
  uint32_t hfFreq;
  int extraout_r1;
  int extraout_r1_00;
  undefined8 uVar2;
  
  switch((clock << 0x18) >> 0x1c) {
  case 1:
    flashWaitStateMax();
    setHfLeConfig(0x1e84801);
    uVar1 = read_volatile_4(Peripherals::CMU.HFPRESC);
    write_volatile_4(Peripherals::CMU.HFPRESC,uVar1 & 0xffffe0ff | presc << 8);
    goto LAB_00005b42;
  case 2:
    uVar1 = read_volatile_4(Peripherals::CMU.HFEXPPRESC);
    write_volatile_4(Peripherals::CMU.HFEXPPRESC,uVar1 & 0xffffe0ff | presc << 8);
    break;
  case 3:
    uVar1 = read_volatile_4(Peripherals::CMU.HFPRESC);
    write_volatile_4(Peripherals::CMU.HFPRESC,uVar1 & 0xfeffffff | presc << 0x18);
    break;
  case 4:
    uVar1 = read_volatile_4(Peripherals::CMU.HFPERPRESC);
    write_volatile_4(Peripherals::CMU.HFPERPRESC,uVar1 & 0xfffe00ff | presc << 8);
    break;
  case 5:
    flashWaitStateMax();
    setHfLeConfig(0x1e84801);
    uVar1 = read_volatile_4(Peripherals::CMU.HFCOREPRESC);
    write_volatile_4(Peripherals::CMU.HFCOREPRESC,uVar1 & 0xfffe00ff | presc << 8);
LAB_00005b42:
    uVar2 = SystemCoreClockGet();
    flashWaitStateControl((uint32_t)uVar2,(int)((ulonglong)uVar2 >> 0x20));
    hfFreq = CMU_ClockFreqGet(cmuClock_HFLE);
    setHfLeConfig(hfFreq);
    return;
  case 6:
    if (clock != cmuClock_RTCC) {
      if (clock == cmuClock_LETIMER0) {
        count_leading_zeroes(presc + 1);
        syncReg(4);
        uVar1 = read_volatile_4(Peripherals::CMU.LFAPRESC0);
        write_volatile_4(Peripherals::CMU.LFAPRESC0,uVar1 & 0xfffffff0 | 0x1fU - extraout_r1);
        return;
      }
      return;
    }
    goto LAB_00005c16;
  case 7:
    if (clock == cmuClock_LEUART0) {
      count_leading_zeroes(presc + 1);
      syncReg(0x40);
      uVar1 = read_volatile_4(Peripherals::CMU.LFBPRESC0);
      write_volatile_4(Peripherals::CMU.LFBPRESC0,uVar1 & 0xfffffffc | 0x1fU - extraout_r1_00);
    }
    break;
  case 8:
    if (clock != cmuClock_RTCC) {
      return;
    }
LAB_00005c16:
    syncReg(0x40000);
    uVar1 = read_volatile_4(Peripherals::CMU.LFEPRESC0);
    write_volatile_4(Peripherals::CMU.LFEPRESC0,presc | uVar1 & 0xfffffff0);
    break;
  default:
    return;
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
  
  uVar3 = read_volatile_4(Peripherals::CMU.HFXOCTRL);
  if ((uVar3 & 0x30) != 0) {
    if (mode == cmuHFXOTuningMode_ShuntCommand) {
      uVar3 = 0x800000;
      goto LAB_00005c6c;
    }
    if ((mode != cmuHFXOTuningMode_PeakShuntCommand) && (mode != cmuHFXOTuningMode_Auto)) {
      uVar3 = 0x7e103ff;
      goto LAB_00005c6c;
    }
  }
  uVar3 = 0xc00000;
LAB_00005c6c:
  do {
    uVar1 = read_volatile_4(Peripherals::CMU.STATUS);
  } while ((uVar3 & ~uVar1) != 0);
  if ((int)(uVar3 << 9) < 0) {
    uVar3 = read_volatile_4(Peripherals::CMU.IF);
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
      write_volatile_4(Peripherals::CMU.IFC,0x400);
      write_volatile_4(Peripherals::CMU.CMD,(uint)mode);
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
      goto LAB_00005d72;
    }
    uVar5 = read_volatile_4(Peripherals::CMU.HFXOCTRL);
    if ((uVar5 & 0x30) != 0) {
      uVar4 = 4;
      iVar1 = 2;
      uVar3 = 3;
      goto LAB_00005d64;
    }
    uVar5 = read_volatile_4(Peripherals::CMU.HFXOCTRL);
    if ((int)(uVar5 << 0x1f) < 0) {
      uVar5 = read_volatile_4(Peripherals::CMU.HFXOCTRL);
      write_volatile_4(Peripherals::CMU.HFXOCTRL,uVar5 & 0xffffffcf | 1);
    }
    uVar4 = 4;
    iVar1 = 2;
    uVar3 = 3;
    goto LAB_00005d0a;
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
    goto switchD_00005cbe_caseD_5;
  }
  if (enable == false) {
LAB_00005d72:
    write_volatile_4(Peripherals::CMU.OSCENCMD,uVar5);
    do {
    } while (*(int *)((iVar1 + 0x10f20480) * 4) != 0);
  }
  else {
LAB_00005d64:
    enable = false;
LAB_00005d0a:
    write_volatile_4(Peripherals::CMU.OSCENCMD,uVar4);
    do {
    } while (*(int *)((iVar1 + 0x10f20480) * 4) == 0);
    if (wait != false) {
      piVar2 = (int *)((uVar3 + 0x10f20480) * 4);
      do {
      } while (*piVar2 == 0);
      if ((osc == cmuOsc_HFXO) && (enable != false)) {
        uVar5 = read_volatile_4(Peripherals::CMU.HFXOCTRL);
        if ((uVar5 & 1) == 0) {
          CMU_OscillatorTuningWait(cmuOsc_HFXO,cmuHFXOTuningMode_Auto);
        }
        else {
          CMU_OscillatorTuningOptimize(cmuOsc_HFXO,cmuHFXOTuningMode_ShuntCommand,true);
        }
        uVar5 = read_volatile_4(Peripherals::CMU.HFXOTRIMSTATUS);
        CMU_OscillatorEnable(cmuOsc_HFXO,false,true);
        CMU_OscillatorTuningSet(uVar5 & 0x7ff,osc_00);
        write_volatile_4(Peripherals::CMU.OSCENCMD,uVar4);
        do {
        } while (*piVar2 == 0);
      }
    }
  }
switchD_00005cbe_caseD_5:
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void CMU_ClockSelectSet(CMU_Clock_TypeDef clock,CMU_Select_TypeDef ref)

{
  uint32_t uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  undefined8 uVar6;
  
  if (false) {
    return;
  }
  switch(clock & 0xf) {
  case 1:
    switch(ref) {
    case cmuSelect_LFXO:
      uVar2 = 0;
      uVar3 = 4;
      break;
    case cmuSelect_LFRCO:
      uVar2 = 1;
      uVar3 = 3;
      break;
    case cmuSelect_HFXO:
      setHfLeConfig(0x1e84801);
      uVar2 = 2;
      uVar3 = uVar2;
      break;
    case cmuSelect_HFRCO:
      setHfLeConfig(0x1e84801);
      uVar2 = 3;
      uVar3 = 1;
      break;
    default:
      goto switchD_00005dd4_caseD_4;
    }
    CMU_OscillatorEnable((CMU_Osc_TypeDef)uVar2,true,true);
    flashWaitStateMax();
    write_volatile_4(Peripherals::CMU.HFCLKSEL,uVar3);
    uVar1 = CMU_ClockFreqGet(cmuClock_HFLE);
    setHfLeConfig(uVar1);
    uVar6 = SystemCoreClockGet();
    flashWaitStateControl((uint32_t)uVar6,(int)((ulonglong)uVar6 >> 0x20));
    return;
  case 2:
    puVar5 = &Peripherals::CMU.LFACLKSEL;
    break;
  case 3:
    puVar5 = &Peripherals::CMU.LFBCLKSEL;
    break;
  default:
    goto switchD_00005dd4_caseD_4;
  case 5:
    puVar5 = &Peripherals::CMU.LFECLKSEL;
    break;
  case 6:
    if (ref == cmuSelect_AUXHFRCO) {
      uVar3 = 0;
    }
    else {
      if (ref != cmuSelect_HFCLK) {
        return;
      }
      uVar3 = 1;
    }
    write_volatile_4(Peripherals::CMU.DBGCLKSEL,uVar3);
    return;
  case 8:
    if (true) {
      switch(ref) {
      case cmuSelect_Disabled:
        iVar4 = 0;
        break;
      default:
        goto switchD_00005dd4_caseD_4;
      case cmuSelect_HFXO:
        CMU_OscillatorEnable(cmuOsc_HFXO,true,true);
        iVar4 = 2;
        break;
      case cmuSelect_AUXHFRCO:
        CMU_OscillatorEnable(cmuOsc_AUXHFRCO,true,true);
        iVar4 = 1;
        break;
      case cmuSelect_HFSRCCLK:
        iVar4 = 3;
      }
      uVar3 = read_volatile_4(Peripherals::CMU.ADCCTRL);
      write_volatile_4(Peripherals::CMU.ADCCTRL,uVar3 & 0xffffffcf | iVar4 << 4);
    }
    goto switchD_00005dd4_caseD_4;
  }
  if (true) {
    switch(ref) {
    case cmuSelect_Disabled:
      uVar3 = 0;
      break;
    case cmuSelect_LFXO:
      CMU_OscillatorEnable(cmuOsc_LFXO,true,true);
      uVar3 = 2;
      break;
    case cmuSelect_LFRCO:
      CMU_OscillatorEnable(cmuOsc_LFRCO,true,true);
      uVar3 = 1;
      break;
    default:
      goto switchD_00005dd4_caseD_4;
    case cmuSelect_HFCLKLE:
      uVar1 = SystemCoreClockGet();
      setHfLeConfig(uVar1);
      _DAT_43c81600 = 1;
      uVar3 = 3;
      break;
    case cmuSelect_ULFRCO:
      uVar3 = 4;
    }
    *puVar5 = uVar3;
  }
switchD_00005dd4_caseD_4:
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void CMU_HFXOInit(CMU_HFXOInit_TypeDef *hfxoInit)

{
  uint uVar1;
  uint uVar2;
  
  CMU_ClockSelectGet(cmuClock_HF);
  CMU_OscillatorEnable(cmuOsc_HFXO,false,true);
  uVar2 = read_volatile_4(Peripherals::CMU.HFXOCTRL);
  uVar2 = uVar2 & 0xfffffffe;
  if (hfxoInit->mode == cmuOscMode_External) {
    uVar2 = uVar2 | 1;
  }
  write_volatile_4(Peripherals::CMU.HFXOCTRL,uVar2);
  uVar2 = read_volatile_4(Peripherals::CMU.HFXOCTRL1);
  write_volatile_4(Peripherals::CMU.HFXOCTRL1,
                   uVar2 & 0xfffffff8 | (uint)hfxoInit->thresholdPeakDetect);
  write_volatile_4(Peripherals::CMU.HFXOSTARTUPCTRL,
                   (uint)hfxoInit->xoCoreBiasTrimStartup | (uint)hfxoInit->ctuneStartup << 0xb);
  uVar2 = read_volatile_4(Peripherals::CMU.HFXOSTEADYSTATECTRL);
  uVar1 = hfxoInit->regIshSteadyState + 3;
  if (0xe < uVar1) {
    uVar1 = 0xf;
  }
  write_volatile_4(Peripherals::CMU.HFXOSTEADYSTATECTRL,
                   uVar2 & 0xff00000 | (uint)hfxoInit->xoCoreBiasTrimSteadyState |
                   (uint)hfxoInit->ctuneSteadyState << 0xb | (uint)hfxoInit->regIshSteadyState << 7
                   | uVar1 << 0x1c);
  write_volatile_4(Peripherals::CMU.HFXOTIMEOUTCTRL,
                   (uint)hfxoInit->timeoutSteady << 4 | (uint)hfxoInit->timeoutPeakDetect << 0xc |
                   (uint)hfxoInit->timeoutStartup | (uint)hfxoInit->timeoutShuntOptimization << 0x10
                  );
  _DAT_43c804a0 = (uint)hfxoInit->lowPowerMode;
  return;
}



void CMU_LFXOInit(CMU_LFXOInit_TypeDef *lfxoInit)

{
  CMU_ClockSelectGet(cmuClock_HF);
  CMU_OscillatorEnable(cmuOsc_LFXO,false,false);
  write_volatile_4(Peripherals::CMU_CLR.LFXOCTRL,0x7001b7f);
  write_volatile_4(Peripherals::CMU_SET.LFXOCTRL,
                   (uint)lfxoInit->timeout << 0x18 | (uint)lfxoInit->gain << 0xb |
                   (uint)lfxoInit->ctune | (uint)lfxoInit->mode << 8);
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



void currentLimitersUpdate(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = read_volatile_4(Peripherals::EMU.DCDCMISCCTRL);
  uVar1 = ((uVar3 << 0x14) >> 0x1c) + 1;
  uVar3 = read_volatile_4(Peripherals::EMU.DCDCMISCCTRL);
  uVar2 = (dcdcMaxCurrent_mA + 0x28 + (dcdcMaxCurrent_mA + 0x28 >> 1)) / (uVar1 * 5) - 1;
  if (6 < uVar2) {
    uVar2 = 7;
  }
  write_volatile_4(Peripherals::EMU.DCDCMISCCTRL,uVar3 & 0xf88fffff | 0x100000 | uVar2 << 0x18);
  if (-1 < dcdcReverseCurrentControl) {
    uVar3 = (int)dcdcReverseCurrentControl + 0x28;
    uVar1 = (uVar3 + (uVar3 >> 1)) / ((uVar1 >> 1) + uVar1 * 2);
    uVar3 = read_volatile_4(Peripherals::EMU.DCDCZDETCTRL);
    if (6 < uVar1) {
      uVar1 = 7;
    }
    write_volatile_4(Peripherals::EMU.DCDCZDETCTRL,uVar3 & 0xffffff8f | uVar1 << 4);
  }
  return;
}



void dcdcHsFixLnBlock(void)

{
  uint uVar1;
  int iVar2;
  
  if (errataFixDcdcHsState - 1 < 2) {
    uVar1 = read_volatile_4(Peripherals::EMU.DCDCCTRL);
    if ((uVar1 & 3) == 1) {
      do {
        iVar2 = read_volatile_4(Peripherals::EMU._124_4_);
      } while (-1 < iVar2 << 0xf);
    }
    errataFixDcdcHsState = errataFixDcdcHsLnWaitDone;
  }
  return;
}



void dcdcFetCntSet(_Bool lpModeSet)

{
  uint uVar1;
  
  dcdcFetCntSet::emuDcdcMiscCtrlReg = read_volatile_4(Peripherals::EMU.DCDCMISCCTRL);
  uVar1 = read_volatile_4(Peripherals::EMU.DCDCMISCCTRL);
  write_volatile_4(Peripherals::EMU.DCDCMISCCTRL,uVar1 & 0xffff00ff | 0x7700);
  currentLimitersUpdate(lpModeSet);
  return;
}



void emState(emState_TypeDef action)

{
  emState::cmuStatus = read_volatile_4(Peripherals::CMU.STATUS);
  emState::hfClock = CMU_ClockSelectGet(cmuClock_HF);
  return;
}



void emState(emState_TypeDef action)

{
  uint uVar1;
  uint uVar2;
  CMU *pCVar3;
  bool bVar4;
  
  uVar1 = read_volatile_4(Peripherals::CMU.LOCK);
  write_volatile_4(Peripherals::CMU.LOCK,0x580e);
  write_volatile_4(Peripherals::CMU.OSCENCMD,emState::cmuStatus & 0x155);
  if (emState::hfClock != cmuSelect_HFRCO) {
    CMU_ClockSelectSet(cmuClock_HF,emState::hfClock);
  }
  uVar2 = emState::cmuStatus << 0x1f;
  bVar4 = -1 < (int)uVar2;
  pCVar3 = (CMU *)emState::cmuStatus;
  if (bVar4) {
    uVar2 = 2;
    pCVar3 = &Peripherals::CMU;
  }
  if (bVar4) {
    pCVar3->OSCENCMD = uVar2;
  }
  pCVar3 = (CMU *)(uVar1 << 0x1f);
  bVar4 = (int)pCVar3 < 0;
  if (bVar4) {
    pCVar3 = &Peripherals::CMU;
    uVar2 = 0;
  }
  if (bVar4) {
    pCVar3->LOCK = uVar2;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void EMU_EnterEM2(_Bool restore)

{
  undefined lpModeSet;
  emState_TypeDef action;
  
  lpModeSet = restore;
  if (restore != false) {
    emState(restore);
  }
  _DAT_e000ed10 = _DAT_e000ed10 | 4;
  dcdcFetCntSet((_Bool)lpModeSet);
  dcdcHsFixLnBlock();
  WaitForInterrupt();
  write_volatile_4(Peripherals::EMU.DCDCMISCCTRL,dcdcFetCntSet::emuDcdcMiscCtrlReg);
  action = currentLimitersUpdate();
  if (restore != false) {
    emState(action);
    return;
  }
  SystemCoreClockGet();
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void EMU_EnterEM3(_Bool restore)

{
  undefined lpModeSet;
  emState_TypeDef action;
  uint uVar1;
  bool bVar2;
  
  lpModeSet = restore;
  if (restore != false) {
    emState(restore);
  }
  uVar1 = read_volatile_4(Peripherals::CMU.LOCK);
  uVar1 = uVar1 << 0x1f;
  bVar2 = (int)uVar1 < 0;
  write_volatile_4(Peripherals::CMU.LOCK,0x580e);
  if (bVar2) {
    uVar1 = 0;
  }
  write_volatile_4(Peripherals::CMU.OSCENCMD,0x280);
  if (bVar2) {
    write_volatile_4(Peripherals::CMU.LOCK,uVar1);
  }
  _DAT_e000ed10 = _DAT_e000ed10 | 4;
  dcdcFetCntSet((_Bool)lpModeSet);
  dcdcHsFixLnBlock();
  WaitForInterrupt();
  write_volatile_4(Peripherals::EMU.DCDCMISCCTRL,dcdcFetCntSet::emuDcdcMiscCtrlReg);
  action = currentLimitersUpdate();
  if (restore != false) {
    emState(action);
    return;
  }
  SystemCoreClockGet();
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void EMU_DCDCModeSet(EMU_DcdcMode_TypeDef dcdcMode)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)dcdcMode;
  do {
    uVar2 = read_volatile_4(Peripherals::EMU.DCDCSYNC);
  } while ((int)(uVar2 << 0x1f) < 0);
  uVar2 = read_volatile_4(Peripherals::EMU.DCDCCTRL);
  uVar2 = uVar2 & 3;
  if (uVar2 != 0) {
    _DAT_43c60ab4 = 1;
  }
  if (uVar2 == uVar1) {
    if (uVar1 != 0) {
      return;
    }
  }
  else {
    if ((uVar2 == 0) && (uVar1 == 1)) {
      errataFixDcdcHsState = errataFixDcdcHsBypassLn;
    }
    do {
      uVar2 = read_volatile_4(Peripherals::EMU.DCDCSYNC);
    } while ((int)(uVar2 << 0x1f) < 0);
    uVar2 = read_volatile_4(Peripherals::EMU.DCDCCTRL);
    write_volatile_4(Peripherals::EMU.DCDCCTRL,uVar2 & 0xfffffffc | uVar1);
    do {
      uVar2 = read_volatile_4(Peripherals::EMU.DCDCSYNC);
    } while ((int)(uVar2 << 0x1f) < 0);
    if (uVar1 != 0) {
      uVar1 = 1;
    }
  }
  _DAT_43c60ab4 = uVar1;
  return;
}



void EMU_EnterEM4(void)

{
  uint uVar1;
  undefined lpModeSet;
  uint uVar2;
  uint uVar3;
  
  uVar2 = read_volatile_4(Peripherals::EMU.EM4CTRL);
  uVar3 = read_volatile_4(Peripherals::EMU.EM4CTRL);
  write_volatile_4(Peripherals::EMU.LOCK,0xade8);
  uVar1 = read_volatile_4(Peripherals::EMU.EM4CTRL);
  lpModeSet = (undefined)(uVar1 & 1);
  uVar2 = uVar2 & 0xfffcffff | 0x20000;
  uVar3 = uVar3 | 0x30000;
  if (((uVar1 & 1) == 0) &&
     (uVar1 = read_volatile_4(Peripherals::EMU.DCDCCTRL), (uVar1 & 3) - 1 < 2)) {
    EMU_DCDCModeSet(emuDcdcMode_Bypass);
  }
  uVar1 = read_volatile_4(Peripherals::EMU.EM4CTRL);
  if ((int)(uVar1 << 0x1f) < 0) {
    disableIRQinterrupts();
    write_volatile_4(Peripherals::EMU.TESTLOCK,0xade8);
    uVar1 = read_volatile_4(Peripherals::EMU._408_4_);
    write_volatile_4(Peripherals::EMU._408_4_,uVar1 | 0x80);
    uVar1 = read_volatile_4(Peripherals::EMU._136_4_);
    write_volatile_4(Peripherals::EMU._136_4_,uVar1 | 0x100);
  }
  dcdcFetCntSet((_Bool)lpModeSet);
  dcdcHsFixLnBlock();
  write_volatile_4(Peripherals::EMU.EM4CTRL,uVar2);
  write_volatile_4(Peripherals::EMU.EM4CTRL,uVar3);
  write_volatile_4(Peripherals::EMU.EM4CTRL,uVar2);
  write_volatile_4(Peripherals::EMU.EM4CTRL,uVar3);
  write_volatile_4(Peripherals::EMU.EM4CTRL,uVar2);
  write_volatile_4(Peripherals::EMU.EM4CTRL,uVar3);
  write_volatile_4(Peripherals::EMU.EM4CTRL,uVar2);
  write_volatile_4(Peripherals::EMU.EM4CTRL,uVar3);
  write_volatile_4(Peripherals::EMU.EM4CTRL,uVar2);
  return;
}



_Bool EMU_DCDCOutputVoltageSet(uint32_t mV,_Bool setLpVoltage,_Bool setLnVoltage)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  if (0x4b0 < mV - 0x708) {
    return false;
  }
  uVar2 = read_volatile_4(DAT_0fe08318);
  uVar7 = read_volatile_4(Peripherals::EMU.DCDCMISCCTRL);
  if (mV == 0x708) {
    uVar6 = uVar2 << 0x10;
    uVar4 = uVar2 & 0xff;
    uVar5 = 600;
    iVar3 = 0x4b0;
  }
  else {
    uVar4 = (uVar2 << 8) >> 0x18;
    uVar5 = 0x4b0;
    iVar3 = 0x708;
    uVar6 = uVar2;
  }
  uVar2 = mV - 0x708;
  uVar7 = (uVar7 << 2) >> 0x1e;
  if (uVar2 != 0) {
    uVar2 = 1;
  }
  uVar8 = uVar2 | uVar7 << 8;
  if (uVar8 == 0x101) {
    uVar8 = read_volatile_4(DAT_0fe08324);
LAB_000063c8:
    uVar1 = uVar8 >> 0x18;
    uVar8 = (uVar8 << 8) >> 0x18;
  }
  else {
    if (uVar8 < 0x102) {
      if (uVar8 == 1) {
        uVar8 = read_volatile_4(DAT_0fe08324);
      }
      else {
        if (uVar8 != 0) {
          if (uVar8 != 0x100) goto LAB_00006320;
          uVar8 = read_volatile_4(DAT_0fe0831c);
          goto LAB_000063c8;
        }
        uVar8 = read_volatile_4(DAT_0fe0831c);
      }
    }
    else {
      if (uVar8 == 0x201) {
        uVar8 = read_volatile_4(DAT_0fe08328);
      }
      else {
        if (0x201 < uVar8) {
          if (uVar8 == 0x300) {
            uVar8 = read_volatile_4(DAT_0fe08320);
          }
          else {
            if (uVar8 != 0x301) goto LAB_00006320;
            uVar8 = read_volatile_4(DAT_0fe08328);
          }
          goto LAB_000063c8;
        }
        if (uVar8 != 0x200) {
LAB_00006320:
          uVar1 = 0;
          uVar8 = 0;
          goto LAB_0000635a;
        }
        uVar8 = read_volatile_4(DAT_0fe08320);
      }
    }
    uVar1 = (uVar8 << 0x10) >> 0x18;
    uVar8 = uVar8 & 0xff;
  }
LAB_0000635a:
  uVar4 = ((mV - iVar3) * ((uVar6 >> 0x18) - uVar4)) / uVar5 + uVar4;
  if (uVar6 >> 0x18 < uVar4) {
    return false;
  }
  uVar8 = uVar8 + ((mV - iVar3) * (uVar1 - uVar8)) / uVar5;
  uVar5 = 0;
  if (uVar1 < uVar8) {
    return false;
  }
  if (setLnVoltage != false) {
    uVar6 = read_volatile_4(Peripherals::EMU.DCDCLNVCTRL);
    if (mV != 0x708) {
      uVar5 = 2;
    }
    write_volatile_4(Peripherals::EMU.DCDCLNVCTRL,uVar6 & 0xffff80fd | uVar4 * 0x100 | uVar5);
  }
  if (setLpVoltage == false) {
    return true;
  }
  uVar4 = read_volatile_4(DAT_0fe08200);
  if ((uVar4 & 0xff) < 4) {
    uVar4 = read_volatile_4(DAT_0fe0832c);
    if (mV == 0x708) {
LAB_000063fe:
      uVar4 = uVar4 & 0xff;
      goto LAB_00006400;
    }
  }
  else {
    uVar4 = read_volatile_4(DAT_0fe08330);
    if (uVar7 == 2) {
      uVar4 = (uVar4 << 8) >> 0x18;
      goto LAB_00006400;
    }
    if (uVar7 == 3) {
      uVar4 = uVar4 >> 0x18;
      goto LAB_00006400;
    }
    if (uVar7 != 1) goto LAB_000063fe;
  }
  uVar4 = (uVar4 << 0x10) >> 0x18;
LAB_00006400:
  if ((uVar4 << 0xc & 0xf0000) != 0) {
    return false;
  }
  uVar7 = read_volatile_4(Peripherals::EMU.DCDCLPCTRL);
  write_volatile_4(Peripherals::EMU.DCDCLPCTRL,uVar4 << 0xc | uVar7 & 0xffff0fff);
  uVar7 = read_volatile_4(Peripherals::EMU.DCDCLPVCTRL);
  if (0xe6 < uVar8) {
    uVar8 = 0xe7;
  }
  write_volatile_4(Peripherals::EMU.DCDCLPVCTRL,uVar7 & 0xfffffe00 | uVar2 | uVar8 << 1);
  return setLpVoltage;
}



void EMU_DCDCOptimizeSlice(uint32_t em0LoadCurrentmA)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  
  uVar1 = read_volatile_4(Peripherals::EMU.DCDCLNFREQCTRL);
  uVar2 = read_volatile_4(Peripherals::EMU.DCDCMISCCTRL);
  uVar1 = uVar1 & 7;
  if (((int)(uVar2 << 0x1f) < 0) && (1 < uVar1)) {
    if (em0LoadCurrentmA < 0x14) {
LAB_000064a6:
      uVar2 = 4;
      goto LAB_00006468;
    }
    bVar4 = 0x12 < em0LoadCurrentmA - 0x14;
    bVar3 = em0LoadCurrentmA - 0x14 == 0x13;
  }
  else {
    uVar2 = read_volatile_4(Peripherals::EMU.DCDCMISCCTRL);
    if (((int)(uVar2 << 0x1f) < 0) || (1 < uVar1)) {
      uVar2 = read_volatile_4(Peripherals::EMU.DCDCMISCCTRL);
      uVar2 = uVar2 & 1;
      if (uVar2 == 0) goto LAB_00006468;
      if (1 < uVar1) {
        uVar2 = 0;
        goto LAB_00006468;
      }
      bVar4 = 0x26 < em0LoadCurrentmA;
      bVar3 = em0LoadCurrentmA == 0x27;
    }
    else {
      if (em0LoadCurrentmA < 10) goto LAB_000064a6;
      bVar4 = 8 < em0LoadCurrentmA - 10;
      bVar3 = em0LoadCurrentmA - 10 == 9;
    }
  }
  if (bVar4 && !bVar3) {
    uVar2 = 0x10;
  }
  else {
    uVar2 = 8;
  }
LAB_00006468:
  uVar1 = read_volatile_4(Peripherals::EMU.DCDCMISCCTRL);
  write_volatile_4(Peripherals::EMU.DCDCMISCCTRL,
                   (uVar2 - 1) * 0x1000 | (uVar2 - 1) * 0x100 | uVar1 & 0xffff00ff);
  currentLimitersUpdate();
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void EMU_DCDCLnRcoBandSet(EMU_DcdcLnRcoBand_TypeDef band)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::EMU.DCDCLNFREQCTRL);
  write_volatile_4(Peripherals::EMU.DCDCLNFREQCTRL,(uint)band | uVar1 & 0xfffffff8);
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
  int iVar6;
  undefined4 in_r1;
  uint uVar7;
  uint uVar8;
  SYSTEM_ChipRevision_TypeDef rev;
  
  rev._1_2_ = (undefined2)((uint)in_r1 >> 8);
  write_volatile_4(Peripherals::EMU.PWRCFG,2);
  uVar7 = read_volatile_4(Peripherals::EMU.PWRCFG);
  if ((uVar7 & 0xf) != 2) {
    return false;
  }
  iVar6 = read_volatile_4(DAT_0fe0831c);
  if (iVar6 != -1) {
    uVar3 = read_volatile_4(Peripherals::DEVINFO._60_4_);
    puVar2 = (undefined4 *)read_volatile_4(Peripherals::DEVINFO._56_4_);
    *puVar2 = uVar3;
    uVar7 = read_volatile_4(Peripherals::DEVINFO.UNIQUEH);
    puVar4 = (uint *)read_volatile_4(Peripherals::DEVINFO.UNIQUEL);
    *puVar4 = uVar7;
    uVar7 = read_volatile_4(Peripherals::DEVINFO.PART);
    puVar4 = (uint *)read_volatile_4(Peripherals::DEVINFO.MSIZE);
    *puVar4 = uVar7;
    uVar7 = read_volatile_4(Peripherals::DEVINFO.EMUTEMP);
    puVar4 = (uint *)read_volatile_4(Peripherals::DEVINFO.DEVINFOREV);
    *puVar4 = uVar7;
    uVar3 = read_volatile_4(Peripherals::DEVINFO._92_4_);
    puVar2 = (undefined4 *)read_volatile_4(Peripherals::DEVINFO._88_4_);
    *puVar2 = uVar3;
    uVar7 = read_volatile_4(Peripherals::DEVINFO.ADC0CAL1);
    puVar4 = (uint *)read_volatile_4(Peripherals::DEVINFO.ADC0CAL0);
    *puVar4 = uVar7;
  }
  uVar1 = dcdcInit->em234LoadCurrent_uA;
  if (uVar1 < 0x4b) {
    uVar7 = 0;
  }
  else {
    if (uVar1 < 500) {
      uVar7 = 0x10000000;
    }
    else {
      if (uVar1 < 0x9c4) {
        uVar7 = 0x20000000;
      }
      else {
        uVar7 = 0x30000000;
      }
    }
  }
  uVar8 = read_volatile_4(Peripherals::EMU.DCDCMISCCTRL);
  uVar8 = uVar8 & 0xcffffffe;
  if (-1 < dcdcInit->reverseCurrentControl) {
    uVar8 = uVar8 | 1;
  }
  write_volatile_4(Peripherals::EMU.DCDCMISCCTRL,uVar8 | uVar7);
  uVar7 = read_volatile_4(Peripherals::EMU.DCDCLPCTRL);
  write_volatile_4(Peripherals::EMU.DCDCLPCTRL,uVar7 | 0x1000000);
  iVar6 = _DAT_43c60980;
  if (_DAT_43c60980 != 0) {
    iVar6 = 4;
  }
  EMU_DCDCLnRcoBandSet((EMU_DcdcLnRcoBand_TypeDef)iVar6);
  uVar7 = read_volatile_4(Peripherals::EMU.DCDCTIMING);
  write_volatile_4(Peripherals::EMU.DCDCTIMING,uVar7 & 0x9fffffff);
  uVar7 = read_volatile_4(Peripherals::EMU.DCDCMISCCTRL);
  write_volatile_4(Peripherals::EMU.DCDCMISCCTRL,uVar7 | 6);
  rev._0_2_ = rev._1_2_;
  SYSTEM_ChipRevisionGet(&rev);
  if (((rev.major == '\x01') && (rev.minor < 3)) && (errataFixDcdcHsState == errataFixDcdcHsInit)) {
    uVar7 = read_volatile_4(Peripherals::EMU._68_4_);
    write_volatile_4(Peripherals::EMU._68_4_,uVar7 | 1);
    uVar7 = read_volatile_4(Peripherals::EMU.DCDCTIMING);
    write_volatile_4(Peripherals::EMU.DCDCTIMING,uVar7 & 0xf00e0f00 | 0xb40c0b4);
    errataFixDcdcHsState = rev.major;
  }
  dcdcMaxCurrent_mA = dcdcInit->maxCurrent_mA;
  dcdcReverseCurrentControl = dcdcInit->reverseCurrentControl;
  dcdcEm01LoadCurrent_mA = dcdcInit->em01LoadCurrent_mA;
  EMU_DCDCOptimizeSlice((uint)dcdcEm01LoadCurrent_mA);
  if (dcdcInit->dcdcLnCompCtrl == emuDcdcLnCompCtrl_1u0F) {
    uVar7 = 0x57204077;
  }
  else {
    if (dcdcInit->dcdcLnCompCtrl != emuDcdcLnCompCtrl_4u7F) goto LAB_000065ea;
    uVar7 = 0xb7102137;
  }
  write_volatile_4(Peripherals::EMU.DCDCLNCOMPCTRL,uVar7);
LAB_000065ea:
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
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = (uint)mode;
  uVar2 = (uint)port;
  if (uVar3 != 0) {
    if (out == 0) {
      puVar1 = &DAT_4400a00c;
    }
    else {
      puVar1 = &DAT_4600a00c;
    }
    *(int *)(puVar1 + uVar2 * 0x30) = 1 << (pin & 0xff);
  }
  if (pin < 8) {
    (&Peripherals::GPIO.PA_MODEL)[uVar2 * 0xc] =
         (&Peripherals::GPIO.PA_MODEL)[uVar2 * 0xc] & ~(0xf << (pin << 2 & 0xff)) |
         uVar3 << (pin << 2 & 0xff);
  }
  else {
    uVar4 = (pin + 0x3ffffff8) * 4;
    (&Peripherals::GPIO.PA_MODEH)[uVar2 * 0xc] =
         uVar3 << (uVar4 & 0xff) |
         (&Peripherals::GPIO.PA_MODEH)[uVar2 * 0xc] & ~(0xf << (uVar4 & 0xff));
  }
  if (uVar3 == 0) {
    if (out == 0) {
      puVar1 = &DAT_4400a00c;
    }
    else {
      puVar1 = &DAT_4600a00c;
    }
    *(int *)(puVar1 + uVar2 * 0x30) = 1 << (pin & 0xff);
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
          if (uVar5 == 0x800) goto LAB_000067ca;
          bVar7 = uVar5 == 0x10000;
        }
        if (!bVar7) goto LAB_000067ce;
      }
LAB_000067ca:
      uVar4 = uVar4 | 0x100;
    }
LAB_000067ce:
    uVar1 = read_volatile_4(Peripherals::EMU._136_4_);
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



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RTCC_Enable(_Bool enable)

{
  _DAT_42840000 = (uint)enable;
  return;
}



void RTCC_Init(RTCC_Init_TypeDef *init)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (init->debugRun == false) {
    uVar5 = 0;
  }
  else {
    uVar5 = 4;
  }
  if (init->precntWrapOnCCV0 == false) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0x10;
  }
  if (init->cntWrapOnCCV1 == false) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0x20;
  }
  if (init->enaOSCFailDetect == false) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x8000;
  }
  if (init->disLeapYearCorr == false) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x20000;
  }
  write_volatile_4(Peripherals::RTCC.CTRL,
                   (uint)init->prescMode << 0xc | (uint)init->presc << 8 | (uint)init->enable |
                   (uint)init->cntMode << 0x10 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2);
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
  if (refFreq == 0) {
    refFreq = CMU_ClockFreqGet(cmuClock_HFPER);
  }
  usart->CLKDIV = (refFreq - 1) / (baudrate << 1) << 8;
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
  if ((usart == (USART_TypeDef *)&Peripherals::USART0) ||
     (usart == (USART_TypeDef *)&Peripherals::USART1)) {
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
  usart->ROUTEPEN = usart->ROUTEPEN & 0xffffffcf;
  usart->ROUTEPEN = (uint)init->hwFlowControl | usart->ROUTEPEN;
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



uint32_t SystemMaxCoreClockGet(void)

{
  return 38400000;
}



uint32_t SystemHFClockGet(void)

{
  uint uVar1;
  uint uVar2;
  uint32_t *puVar3;
  
  uVar2 = read_volatile_4(Peripherals::CMU.HFCLKSTATUS);
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
  uVar1 = read_volatile_4(Peripherals::CMU.HFPRESC);
  return uVar2 / (((uVar1 << 0x13) >> 0x1b) + 1);
}



void SystemCoreClockGet(void)

{
  uint uVar1;
  uint32_t uVar2;
  
  uVar2 = SystemHFClockGet();
  uVar1 = read_volatile_4(Peripherals::CMU.HFCOREPRESC);
  SystemCoreClock = uVar2 / (((uVar1 << 0xf) >> 0x17) + 1);
  return;
}



uint32_t SystemHFXOClockGet(void)

{
  return SystemHFXOClock;
}



void SystemHFXOClockSet(uint32_t freq)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::CMU.HFCLKSTATUS);
  if ((uVar1 & 7) == 2) {
    SystemHFXOClock = freq;
    SystemCoreClockGet();
    return;
  }
  SystemHFXOClock = freq;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void SystemInit(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::EMU.DCDCCLIMCTRL);
  write_volatile_4(Peripherals::EMU.DCDCCLIMCTRL,uVar1 | 0x2000);
  uVar1 = read_volatile_4(Peripherals::EMU.DCDCCTRL);
  write_volatile_4(Peripherals::EMU.DCDCCTRL,uVar1 & 0xfffffffc);
  uVar1 = read_volatile_4(Peripherals::EMU._116_4_);
  write_volatile_4(Peripherals::EMU._116_4_,uVar1 & 0xfffffffe);
  uVar1 = read_volatile_4(Peripherals::EMU.DCDCTIMING);
  write_volatile_4(Peripherals::EMU.DCDCTIMING,uVar1 & 0xefffffff);
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



void SystemLFXOClockSet(uint32_t freq)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::CMU.HFCLKSTATUS);
  if ((uVar1 & 7) == 4) {
    SystemLFXOClock = freq;
    SystemCoreClockGet();
    return;
  }
  SystemLFXOClock = freq;
  return;
}



void BSP_initDcdc(void)

{
  undefined4 uVar1;
  EMU_DCDCInit_TypeDef *pEVar2;
  undefined4 *puVar3;
  EMU_DCDCInit_TypeDef dcdcInit;
  
  puVar3 = &DAT_00016524;
  pEVar2 = &dcdcInit;
  do {
    uVar1 = puVar3[1];
    *(undefined4 *)pEVar2 = *puVar3;
    *(undefined4 *)&pEVar2->em01LoadCurrent_mA = uVar1;
    pEVar2 = (EMU_DCDCInit_TypeDef *)&pEVar2->maxCurrent_mA;
    puVar3 = puVar3 + 2;
  } while (puVar3 != &DAT_00016534);
  EMU_DCDCInit(&dcdcInit);
  return;
}



void BSP_initClocks(void)

{
  undefined4 uVar1;
  CMU_HFXOInit_TypeDef *pCVar2;
  undefined4 *puVar3;
  CMU_LFXOInit_TypeDef lfxoInit;
  CMU_HFXOInit_TypeDef hfxoInit;
  
  puVar3 = &DAT_00016534;
  pCVar2 = &hfxoInit;
  do {
    uVar1 = puVar3[1];
    *(undefined4 *)pCVar2 = *puVar3;
    *(undefined4 *)&pCVar2->ctuneStartup = uVar1;
    pCVar2 = (CMU_HFXOInit_TypeDef *)&pCVar2->regIshSteadyState;
    puVar3 = puVar3 + 2;
  } while (puVar3 != (undefined4 *)&UNK_00016544);
  *(undefined2 *)pCVar2 = 0;
  hfxoInit._4_4_ = 0x15a015a;
  CMU_HFXOInit(&hfxoInit);
  SystemHFXOClockSet(38400000);
  CMU_OscillatorEnable(cmuOsc_HFXO,true,true);
  CMU_ClockSelectSet(cmuClock_HF,cmuSelect_HFXO);
  CMU_OscillatorEnable(cmuOsc_HFRCO,false,false);
  lfxoInit = (CMU_LFXOInit_TypeDef)0x70200;
  CMU_LFXOInit(&lfxoInit);
  SystemLFXOClockSet(0x8000);
  CMU_ClockSelectSet(cmuClock_LFA,cmuSelect_LFRCO);
  CMU_ClockSelectSet(cmuClock_LFB,cmuSelect_LFRCO);
  CMU_ClockSelectSet(cmuClock_LFE,cmuSelect_LFRCO);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void BSP_initDevice(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uStack12;
  
  uVar1 = read_volatile_4(DAT_0fe081fc);
  uStack12 = param_2;
  SYSTEM_ChipRevisionGet((SYSTEM_ChipRevision_TypeDef *)&uStack12);
  if (uVar1 >> 0x18 < 0x8f) {
    uVar1 = read_volatile_4(Peripherals::CMU.HFBUSCLKEN0);
    write_volatile_4(Peripherals::CMU.HFBUSCLKEN0,uVar1 | 4);
    write_volatile_4(Peripherals::GPIO.PA_CTRL,0x500050);
    write_volatile_4(Peripherals::GPIO.PB_CTRL,0x500050);
    write_volatile_4(Peripherals::GPIO.PC_CTRL,0x500050);
    write_volatile_4(Peripherals::GPIO.PD_CTRL,0x500050);
    write_volatile_4(Peripherals::GPIO.PE_CTRL,0x500050);
    write_volatile_4(Peripherals::GPIO.PF_CTRL,0x500050);
    write_volatile_4(Peripherals::CMU.HFBUSCLKEN0,uVar1);
  }
  else {
    if (0x8f < uVar1 >> 0x18) goto LAB_00006ce0;
  }
  uVar1 = read_volatile_4(Peripherals::CMU.HFXOSTARTUPCTRL);
  write_volatile_4(Peripherals::CMU.HFXOSTARTUPCTRL,uVar1 & 0xffffff80 | 0x20);
LAB_00006ce0:
  if (uStack12._1_1_ == '\x01') {
    uVar1 = read_volatile_4(Peripherals::EMU.BIASCONF);
    write_volatile_4(Peripherals::EMU.BIASCONF,uVar1 | 4);
  }
  _DAT_43c60ab4 = 0;
  BSP_initDcdc();
  BSP_initClocks();
  return;
}



void BSP_initBoard(void)

{
  CMU_ClockEnable(cmuClock_GPIO,true);
  BSP_LedsInit();
  GPIO_PinModeSet(gpioPortA,5,gpioModePushPull,1);
  RETARGET_SerialInit();
  return;
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
    *(int *)(&DAT_4400a00c + (uint)ledArray[ledNo].port * 0x30) = 1 << (ledArray[ledNo].pin & 0xff);
    return 0;
  }
  return -1;
}



int BSP_LedSet(int ledNo)

{
  if ((uint)ledNo < 2) {
    *(int *)(&DAT_4600a00c + (uint)ledArray[ledNo].port * 0x30) = 1 << (ledArray[ledNo].pin & 0xff);
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



void halInit(void)

{
  halInitChipSpecific();
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
    uVar1 = iterations._4_4_ | (uint)iterations;
    iterations._0_4_ = (uint)iterations - 1;
    iterations._4_4_ = (iterations._4_4_ - 1) + (uint)bVar2;
  } while (uVar1 != 0);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint8_t halInitChipSpecific(void)

{
  uint uVar1;
  uint8_t uVar2;
  CMU_Select_TypeDef ref;
  RAIL_TxPowerCurvesConfig_t *config;
  bool osc;
  undefined local_3c [16];
  RAIL_PtiConfig_t local_2c;
  
  BSP_initDevice();
  BSP_initBoard();
  memset(&local_2c,0,0x14);
  local_2c.baud = 1600000;
  local_2c.doutPin = '\f';
  local_2c.mode = '\x02';
  local_2c.doutLoc = '\x06';
  local_2c.doutPort = gpioPortB;
  local_2c.dframeLoc = '\x06';
  local_2c.dframePort = gpioPortB;
  local_2c.dframePin = '\r';
  RAIL_ConfigPti((RAIL_Handle_t)0xffffffff,&local_2c);
  config = (RAIL_TxPowerCurvesConfig_t *)local_3c;
  local_3c._0_4_ = curves24Hp;
  local_3c._4_4_ = curvesSg;
  local_3c._8_4_ = curves24Lp;
  local_3c._12_4_ = 8;
  RAIL_InitTxPowerCurves(config);
  uVar1 = read_volatile_4(Peripherals::CMU.STATUS);
  osc = (uVar1 & 0x100) == 0;
  if (!osc) {
    config = (RAIL_TxPowerCurvesConfig_t *)(FUN_00000000 + 2);
  }
  ref = (CMU_Select_TypeDef)config;
  if (osc) {
    ref = cmuSelect_LFRCO;
  }
  CMU_ClockEnable(cmuClock_HFLE,true);
  CMU_OscillatorEnable(osc,true,true);
  CMU_ClockSelectSet(cmuClock_LFA,ref);
  CMU_ClockSelectSet(cmuClock_LFB,ref);
  CMU_ClockSelectSet(cmuClock_LFE,ref);
  CMU_ClockEnable(cmuClock_HFPER,true);
  CMU_ClockEnable(cmuClock_USART1,true);
  USART_InitSync((USART_TypeDef *)&Peripherals::USART1,&usartInit);
  write_volatile_4(Peripherals::USART1.ROUTEPEN,0xb);
  write_volatile_4(Peripherals::USART1.ROUTELOC0,0xb000b0b);
  GPIO_PinModeSet(gpioPortC,6,gpioModePushPull,0);
  GPIO_PinModeSet(gpioPortC,7,gpioModeInputPull,0);
  GPIO_PinModeSet(gpioPortC,8,gpioModePushPull,0);
  GPIO_PinModeSet(gpioPortA,4,gpioModePushPull,1);
  usecDelay(10000);
  _DAT_4400a00c = 0x10;
  USART_Tx((USART_TypeDef *)&Peripherals::USART1,0xab);
  USART_Rx((USART_TypeDef *)&Peripherals::USART1);
  _DAT_4600a00c = 0x10;
  usecDelay(0x1e);
  _DAT_4400a00c = 0x10;
  USART_Tx((USART_TypeDef *)&Peripherals::USART1,0xb9);
  uVar2 = USART_Rx((USART_TypeDef *)&Peripherals::USART1);
  _DAT_4600a00c = 0x10;
  return uVar2;
}



debugSignal_t * halGetDebugSignals(uint32_t *size)

{
  if (size != (uint32_t *)0x0) {
    *size = 10;
  }
  return debugSignals;
}



debugPin_t * halGetDebugPins(uint32_t *size)

{
  if (size != (uint32_t *)0x0) {
    *size = 0xb;
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



caddr_t _sbrk(int incr)

{
  caddr_t pcVar1;
  
  if (_sbrk::heap_end == (char *)0x0) {
    _sbrk::heap_end = &__bss_end__;
  }
  pcVar1 = _sbrk::heap_end;
  _sbrk::heap_end = _sbrk::heap_end + incr;
  return pcVar1;
}



int _write(int file,char *ptr,int len)

{
  char *pcVar1;
  
  for (pcVar1 = ptr; (int)pcVar1 - (int)ptr < len; pcVar1 = pcVar1 + 1) {
    RETARGET_WriteChar(*pcVar1);
  }
  return len;
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
  init._24_4_ = 0;
  GPIO_PinModeSet(gpioPortA,5,gpioModePushPull,1);
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
  uVar2 = read_volatile_4(Peripherals::CMU.HFBUSCLKEN0);
  bVar11 = -1 < (int)(uVar2 << 0x1f);
  if (bVar11) {
    CMU_ClockEnable(cmuClock_HFLE,true);
  }
  ref = CMU_ClockSelectGet(cmuClock_LFE);
  uVar2 = read_volatile_4(Peripherals::CMU.STATUS);
  CMU_ClockSelectSet(cmuClock_LFE,cmuSelect_LFRCO);
  div = CMU_ClockDivGet(cmuClock_RTCC);
  uVar7 = read_volatile_4(Peripherals::CMU.LFECLKEN0);
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



EMSTATUS DISPLAY_Init(void)

{
  EMSTATUS EVar1;
  ulong *puVar2;
  
  if (moduleInitialized == false) {
    puVar2 = &loops_per_jiffy;
    moduleInitialized = true;
    do {
      puVar2 = (ulong *)((code **)puVar2 + 1);
      if ((code *)*puVar2 == FUN_00000000) goto LAB_0000745c;
      EVar1 = (*(code *)*puVar2)();
    } while (EVar1 == 0);
  }
  else {
LAB_0000745c:
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
    if (&DAT_2000421d < pixelMatrixPool + height * 0x10) {
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
  EVar1 = PAL_TimerRepeat(DisplayPolarityInverse + 1,(void *)0x0,0x40);
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
  usartInit.baudrate = 1000000;
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
  *(int *)(&DAT_4600a00c + (port & 0xff) * 0x30) = 1 << (pin & 0xff);
  return 0;
}



EMSTATUS PAL_GpioPinOutClear(uint port,uint pin)

{
  *(int *)(&DAT_4400a00c + (port & 0xff) * 0x30) = 1 << (pin & 0xff);
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
  void *pvVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte *__s;
  uint uVar6;
  char cVar7;
  byte bVar8;
  uint uVar9;
  DISPLAY_PixelMatrix_t pvVar10;
  uint uVar11;
  
  uVar5 = (uint)x;
  if ((moduleInitialized == false) || (pixelMatrixBuffer == (DISPLAY_PixelMatrix_t)0x0)) {
    numPixels = 1;
  }
  else {
    uVar11 = (uint)displayDevice.addressMode;
    if (uVar11 == 0) {
      uVar4 = displayDevice.geometry.stride >> 3;
      uVar2 = y + dimensions.yClipStart;
      pvVar10 = (DISPLAY_PixelMatrix_t)(uVar2 * uVar4 + (int)pixelMatrixBuffer);
      while (numPixels != 0) {
        uVar6 = dimensions.clipWidth - uVar5;
        if (numPixels <= dimensions.clipWidth - uVar5) {
          uVar6 = numPixels;
        }
        numPixels = numPixels - uVar6;
        if (displayDevice.colourMode < DISPLAY_COLOUR_MODE_RGB_3BIT) {
          uVar9 = count_leading_zeroes((uint)green);
          cVar7 = (char)(uVar9 >> 5);
          if (displayDevice.colourMode == DISPLAY_COLOUR_MODE_MONOCHROME_INVERSE) {
            bVar8 = cVar7 - 1;
          }
          else {
            bVar8 = -cVar7;
          }
          uVar9 = uVar5 + dimensions.xClipStart & 0xffff;
          if (uVar6 < 8) {
            uVar6 = uVar6 + uVar9;
            if (bVar8 == 0) {
              for (; uVar9 < uVar6; uVar9 = uVar9 + 1 & 0xffff) {
                *(byte *)((int)pvVar10 + (uVar9 >> 3)) =
                     *(byte *)((int)pvVar10 + (uVar9 >> 3)) & ~(byte)(1 << (uVar9 & 7));
              }
            }
            else {
              for (; uVar9 < uVar6; uVar9 = uVar9 + 1 & 0xffff) {
                *(byte *)((int)pvVar10 + (uVar9 >> 3)) =
                     (byte)(1 << (uVar9 & 7)) | *(byte *)((int)pvVar10 + (uVar9 >> 3));
              }
            }
          }
          else {
            uVar9 = uVar9 >> 3;
            uVar5 = uVar5 + dimensions.xClipStart & 7;
            __s = (byte *)((int)pvVar10 + uVar9);
            if (uVar5 != 0) {
              cVar7 = (char)(1 << uVar5);
              *(byte *)((int)pvVar10 + uVar9) =
                   -cVar7 & bVar8 | *(byte *)((int)pvVar10 + uVar9) & cVar7 - 1U;
              __s = __s + 1;
              uVar6 = uVar6 + (uVar5 - 8);
            }
            uVar5 = uVar6 >> 3;
            if (uVar5 != 0) {
              pvVar1 = memset(__s,(uint)bVar8,uVar5);
              uVar6 = uVar6 - (uVar6 & 0xfffffff8);
              __s = (byte *)((int)pvVar1 + uVar5);
              if (uVar6 == 0) goto LAB_0000794c;
            }
            cVar7 = (char)(1 << (uVar6 & 0xff));
            *__s = cVar7 - 1U & bVar8 | -cVar7 & *__s;
          }
        }
LAB_0000794c:
        uVar5 = uVar11 + uVar2;
        iVar3 = (int)uVar5 >> 5;
        dirtyRows[iVar3] = 1 << (uVar5 & 0x1f) | dirtyRows[iVar3];
        uVar11 = uVar11 + 1;
        pvVar10 = (DISPLAY_PixelMatrix_t)((int)pvVar10 + uVar4);
        uVar5 = 0;
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
  
                    // WARNING: Could not recover jumptable at 0x00007a26. Too many branches
                    // WARNING: Treating indirect jump as call
  EVar1 = (*displayDevice.pDisplayPowerOn)(&displayDevice,false);
  return EVar1;
}



EMSTATUS DMD_wakeUp(void)

{
  EMSTATUS EVar1;
  
                    // WARNING: Could not recover jumptable at 0x00007a32. Too many branches
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
  
                    // WARNING: Could not recover jumptable at 0x00007a32. Too many branches
                    // WARNING: Treating indirect jump as call
  EVar1 = (*displayDevice.pDisplayPowerOn)(&displayDevice,true);
  return EVar1;
}



EMSTATUS GLIB_displaySleep(void)

{
  EMSTATUS EVar1;
  
                    // WARNING: Could not recover jumptable at 0x00007a26. Too many branches
                    // WARNING: Treating indirect jump as call
  EVar1 = (*displayDevice.pDisplayPowerOn)(&displayDevice,false);
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



EMSTATUS GLIB_applyClippingRegion(GLIB_Context_t *pContext)

{
  uint16_t yStart;
  uint16_t xStart;
  EMSTATUS EVar1;
  
  if (pContext != (GLIB_Context_t *)0x0) {
    yStart = *(uint16_t *)&(pContext->clippingRegion).yMin;
    xStart = *(uint16_t *)&(pContext->clippingRegion).xMin;
    EVar1 = DMD_setClippingArea(xStart,yStart,((short)(pContext->clippingRegion).xMax + 1) - xStart,
                                ((short)(pContext->clippingRegion).yMax + 1) - yStart);
    return EVar1;
  }
  return 5;
}



EMSTATUS GLIB_setClippingRegion(GLIB_Context_t *pContext,GLIB_Rectangle_t *pRect)

{
  EMSTATUS EVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((pContext == (GLIB_Context_t *)0x0) || (pRect == (GLIB_Rectangle_t *)0x0)) {
    EVar1 = 5;
  }
  else {
    iVar5 = pRect->xMin;
    iVar3 = pRect->xMax;
    if (iVar5 < iVar3) {
      iVar4 = pRect->yMin;
      iVar2 = pRect->yMax;
      if (iVar4 < iVar2) {
        if ((((-1 < iVar5) && (-1 < iVar4)) &&
            (iVar3 < (int)(uint)pContext->pDisplayGeometry->xSize)) &&
           (iVar2 < (int)(uint)pContext->pDisplayGeometry->ySize)) {
          (pContext->clippingRegion).xMin = iVar5;
          (pContext->clippingRegion).yMin = iVar4;
          (pContext->clippingRegion).xMax = iVar3;
          (pContext->clippingRegion).yMax = iVar2;
          EVar1 = GLIB_applyClippingRegion(pContext);
          return EVar1;
        }
        return 3;
      }
    }
    EVar1 = 4;
  }
  return EVar1;
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



// WARNING: Could not reconcile some variable overlaps

EMSTATUS GLIB_drawLineH(GLIB_Context_t *pContext,int32_t x1,int32_t y1,int32_t x2)

{
  int iVar1;
  EMSTATUS EVar2;
  int32_t iVar3;
  int iVar4;
  uint8_t red;
  uint8_t green;
  uint8_t blue;
  int32_t iStack20;
  
  if (pContext == (GLIB_Context_t *)0x0) {
    EVar2 = 5;
  }
  else {
    if (((pContext->clippingRegion).yMin <= y1) && (y1 <= (pContext->clippingRegion).yMax)) {
      iVar4 = (pContext->clippingRegion).xMax;
      iVar3 = x2;
      if (x2 < x1) {
        iVar3 = x1;
        x1 = x2;
      }
      if ((x1 <= iVar4) && (iVar1 = (pContext->clippingRegion).xMin, iVar1 <= iVar3)) {
        if (iVar1 < x1) {
          iVar1 = x1;
        }
        if (iVar3 < iVar4) {
          iVar4 = iVar3 - iVar1;
        }
        else {
          iVar4 = iVar4 - iVar1;
        }
        iStack20 = x2;
        EVar2 = DMD_setClippingArea((uint16_t)iVar1,(uint16_t)y1,(uint16_t)(iVar4 + 1U),1);
        if (EVar2 != 0) {
          return EVar2;
        }
        GLIB_colorTranslate24bpp(pContext->foregroundColor,&red,&green,&blue);
        EVar2 = DMD_writeColor(0,0,red,green,blue,iVar4 + 1U);
        if (EVar2 != 0) {
          return EVar2;
        }
        EVar2 = GLIB_applyClippingRegion(pContext);
        return EVar2;
      }
    }
    EVar2 = 1;
  }
  return EVar2;
}



// WARNING: Could not reconcile some variable overlaps

EMSTATUS GLIB_drawLineV(GLIB_Context_t *pContext,int32_t x1,int32_t y1,int32_t y2)

{
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
        EVar1 = GLIB_applyClippingRegion(pContext);
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
LAB_00007ee4:
        y_00 = (uint)((x_00 - iVar7) * (y2 - iVar13)) / (uint)(x2 - iVar7) + iVar13;
      }
      else {
        if ((int)(uVar4 << 0x1e) < 0) {
          x_00 = (pContext->clippingRegion).xMax;
          goto LAB_00007ee4;
        }
        if ((int)(uVar4 << 0x1d) < 0) {
          y_00 = (pContext->clippingRegion).yMax;
LAB_00007f2e:
          x_00 = (uint)((y_00 - iVar13) * (x2 - iVar7)) / (uint)(y2 - iVar13) + iVar7;
        }
        else {
          if ((int)(uVar4 << 0x1c) < 0) {
            y_00 = (pContext->clippingRegion).yMin;
            goto LAB_00007f2e;
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
      goto LAB_000080c0;
    }
    if (iVar7 == 0x20) {
      uVar5 = 0xb;
      goto LAB_000080c0;
    }
    sVar2 = -0x30;
  }
  else {
    sVar2 = -0x20;
  }
  uVar5 = (uint)(ushort)(myChar + sVar2);
LAB_000080c0:
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
          goto LAB_00008156;
        }
      }
      else {
        uVar6 = GLIB_drawPixel(pContext,iVar8,y_00);
LAB_00008156:
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
  
                    // WARNING: Could not recover jumptable at 0x00007a26. Too many branches
                    // WARNING: Treating indirect jump as call
  EVar1 = (*displayDevice.pDisplayPowerOn)(&displayDevice,false);
  return EVar1;
}



EMSTATUS GRAPHICS_Wakeup(void)

{
  EMSTATUS EVar1;
  
                    // WARNING: Could not recover jumptable at 0x00007a32. Too many branches
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



RAIL_TxPowerCurves_t * RAIL_GetTxPowerCurve(RAIL_TxPowerMode_t mode)

{
  RAIL_TxPowerCurves_t **ppRVar1;
  
  if (mode == '\0') {
    ppRVar1 = &txPower24HpCurves;
  }
  else {
    ppRVar1 = &txPowerSgCurves;
  }
  return *ppRVar1;
}



RAIL_Status_t RAIL_InitTxPowerCurves(RAIL_TxPowerCurvesConfig_t *config)

{
  piecewiseSegments = config->piecewiseSegments;
  txPower24HpCurves = config->txPower24HpCurves;
  txPower24LpCurves = config->txPower24LpCurves;
  txPowerSgCurves = config->txPowerSgCurves;
  return '\0';
}



RAIL_TxPowerLevel_t
RAIL_ConvertDbmToRaw(RAIL_Handle_t railHandle,RAIL_TxPowerMode_t mode,RAIL_TxPower_t power)

{
  RAIL_TxPowerLevel_t RVar1;
  RAIL_TxPowerCurves_t *pRVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  RAIL_TxPowerCurveSegment_t *pRVar7;
  int iVar8;
  RAIL_TxPowerCurveSegment_t *pRVar9;
  
  iVar8 = (int)power;
  if (iVar8 == 0x7fff) {
    RVar1 = 0xff;
  }
  else {
    if (((txPower24HpCurves == (RAIL_TxPowerCurves_t *)0x0) ||
        (txPowerSgCurves == (RAIL_TxPowerCurves_t *)0x0)) || (txPower24LpCurves == (int16_t *)0x0))
    {
      RAILCb_AssertFailed(railHandle,0x2a);
    }
    pRVar2 = RAIL_GetTxPowerCurve(mode);
    if (mode == '\x01') {
      iVar6 = 6;
      do {
        iVar3 = (int)(short)iVar6;
        if (txPower24LpCurves[iVar6] <= iVar8) break;
        iVar3 = iVar6 + -1;
        iVar6 = iVar3;
      } while (iVar3 != 0);
      RVar1 = (char)iVar3 + '\x01';
    }
    else {
      iVar6 = (int)pRVar2->maxPower;
      if ((iVar8 <= pRVar2->maxPower) && (iVar6 = -0x7f38, -0x7f38 < iVar8)) {
        iVar6 = iVar8;
      }
      pRVar9 = pRVar2->powerParams;
      iVar8 = (int)(short)-(short)((iVar6 - 200U) / 0x28);
      if ((int)(uint)piecewiseSegments <= iVar8) {
        iVar8 = (int)(short)(piecewiseSegments - 1);
      }
      do {
        pRVar7 = pRVar9 + iVar8;
        iVar8 = (int)(short)((short)iVar8 + 1);
        uVar4 = (int)(short)iVar6 * (int)pRVar7->slope + pRVar7->intercept;
        uVar4 = ((uVar4 & ~((int)uVar4 >> 0x1f)) + 500) / 1000;
        if ((int)(uint)piecewiseSegments <= iVar8) break;
      } while (uVar4 <= pRVar9[iVar8].maxPowerLevel);
      uVar5 = (uint)pRVar9[iVar8 + 0x1fffffff].maxPowerLevel;
      if (uVar4 <= pRVar9[iVar8 + 0x1fffffff].maxPowerLevel) {
        uVar5 = uVar4;
      }
      if (uVar5 == 0) {
        uVar5 = 1;
      }
      RVar1 = (RAIL_TxPowerLevel_t)uVar5;
    }
  }
  return RVar1;
}



RAIL_TxPower_t
RAIL_ConvertRawToDbm
          (RAIL_Handle_t railHandle,RAIL_TxPowerMode_t mode,RAIL_TxPowerLevel_t powerLevel)

{
  RAIL_TxPowerCurves_t *pRVar1;
  uint uVar2;
  uint uVar3;
  RAIL_TxPowerCurveSegment_t *pRVar4;
  uint uVar5;
  
  uVar5 = (uint)powerLevel;
  if (((txPower24HpCurves == (RAIL_TxPowerCurves_t *)0x0) ||
      (txPowerSgCurves == (RAIL_TxPowerCurves_t *)0x0)) || (txPower24LpCurves == (int16_t *)0x0)) {
    RAILCb_AssertFailed(railHandle,0x2a);
  }
  if (mode != '\x01') {
    if (uVar5 == 0) {
      return -500;
    }
    pRVar1 = RAIL_GetTxPowerCurve(mode);
    if (uVar5 < 2) {
      return pRVar1->minPower;
    }
    if (mode == '\0') {
      uVar2 = 0xfc;
    }
    else {
      uVar2 = 0xf8;
    }
    if (uVar2 <= uVar5) {
      return pRVar1->maxPower;
    }
    uVar2 = 0;
    do {
      uVar3 = uVar2;
      if ((piecewiseSegments - 1 & 0xff) <= (uVar3 & 0xff)) break;
      uVar2 = uVar3 + 1;
    } while ((ushort)powerLevel <= pRVar1->powerParams[uVar3 + 1].maxPowerLevel);
    pRVar4 = pRVar1->powerParams + uVar3;
    uVar2 = SEXT24(pRVar4->slope);
    return (RAIL_TxPower_t)(((uVar5 * 1000 - pRVar4->intercept) + uVar2 / 2) / uVar2);
  }
  if (uVar5 < 8) {
    if (uVar5 == 0) goto LAB_00008558;
  }
  else {
    uVar5 = 7;
  }
  uVar5 = uVar5 - 1 & 0xff;
LAB_00008558:
  return (RAIL_TxPower_t)txPower24LpCurves[uVar5];
}



void Reset_Handler(void)

{
  char **ppcVar1;
  char **ppcVar2;
  
  SystemInit();
  ppcVar1 = (char **)&__exidx_end;
  for (ppcVar2 = printRailState::railStates; (int)ppcVar2 < (int)&__data_end__;
      ppcVar2 = ppcVar2 + 1) {
    *ppcVar2 = *ppcVar1;
    ppcVar1 = ppcVar1 + 1;
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



// WARNING: Type propagation algorithm not settling

int responsePrintInternal(StripMode_t stripMode,char *formatString,va_list args,_Bool finalize)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  char *__s;
  int iVar5;
  size_t __n;
  
  pcVar3 = (char *)0x0;
  iVar5 = 0;
  pcVar1 = formatString;
  do {
    if (formatString == (char *)0x0) {
LAB_00008632:
      viprintf(buffer,args);
      if ((int)pcVar3 < 0) {
        iprintf(" {internal_error:%d}",-(int)pcVar3);
      }
      else {
        pcVar3 = (char *)0x0;
      }
      if (finalize != false) {
        puts("}");
      }
      return (int)pcVar3;
    }
    formatString = strchr(pcVar1,0x2c);
    if (formatString == (char *)0x0) {
      __n = strlen(pcVar1);
    }
    else {
      __n = (int)formatString - (int)pcVar1;
    }
    __s = buffer + iVar5;
    if (0x100U - iVar5 < __n + 3) {
      pcVar3 = (char *)0xfffffff5;
      goto LAB_00008632;
    }
    iVar4 = 0;
    pcVar3 = __s;
    while ((iVar4 = iVar4 + 1, __n != 0 && (*pcVar1 == '\n'))) {
      *pcVar3 = '\n';
      __n = __n - 1;
      pcVar3 = pcVar3 + 1;
      pcVar1 = pcVar1 + 1;
    }
    *pcVar3 = '{';
    memcpy(__s + iVar4,pcVar1,__n);
    pcVar3 = (char *)(iVar4 + __n + 1);
    __s[iVar4 + __n] = '}';
    __s[(int)pcVar3] = '\0';
    pcVar1 = strchr(__s,0x3a);
    if (pcVar1 == (char *)0x0) {
      if (stripMode == STRIP_NONE) {
        pcVar3 = (char *)0xfffffff4;
        goto LAB_00008632;
      }
    }
    else {
      pcVar2 = strchr(pcVar1 + 1,0x3a);
      if (pcVar2 != (char *)0x0) {
        pcVar3 = (char *)0xfffffff3;
        goto LAB_00008632;
      }
      if (stripMode == STRIP_TAG) {
        pcVar3 = pcVar3 + -((int)pcVar1 - (int)__s);
        memmove(buffer + iVar5 + 1,pcVar1 + 1,(size_t)pcVar3);
      }
      else {
        if (stripMode == STRIP_VALUE) {
          *pcVar1 = '}';
          pcVar1[1] = '\0';
          pcVar3 = pcVar1 + (1 - (int)__s);
        }
      }
    }
    if ((int)pcVar3 < 0) goto LAB_00008632;
    iVar5 = iVar5 + (int)pcVar3;
    pcVar1 = formatString + 1;
  } while( true );
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
  putchar(0x7b);
  iVar1 = responsePrintInternal(STRIP_TAG,formatString,(va_list)&uStack12,true);
  uVar2 = count_leading_zeroes(iVar1);
  return SUB41(uVar2 >> 5,0);
}



_Bool responsePrintStart(char *command)

{
  putchar(0x7b);
  if (command != (char *)0x0) {
    iprintf("{(%s)}",command);
  }
  return true;
}



_Bool responsePrintHeader(char *command,char *formatString,...)

{
  undefined uVar1;
  int iVar2;
  undefined4 in_r2;
  undefined4 in_r3;
  va_list ap;
  undefined4 uStack8;
  undefined4 uStack4;
  
  uStack8 = in_r2;
  uStack4 = in_r3;
  putchar(0x23);
  uVar1 = responsePrintStart(command);
  if (((_Bool)uVar1 == false) ||
     (iVar2 = responsePrintInternal(STRIP_VALUE,formatString,(va_list)&uStack8,true), iVar2 != 0)) {
    uVar1 = 0;
  }
  return (_Bool)uVar1;
}



_Bool responsePrint(char *command,char *formatString,...)

{
  undefined uVar1;
  int iVar2;
  undefined4 in_r2;
  undefined4 in_r3;
  va_list ap;
  undefined4 uStack8;
  undefined4 uStack4;
  
  uStack8 = in_r2;
  uStack4 = in_r3;
  uVar1 = responsePrintStart(command);
  if (((_Bool)uVar1 == false) ||
     (iVar2 = responsePrintInternal(STRIP_NONE,formatString,(va_list)&uStack8,true), iVar2 != 0)) {
    uVar1 = 0;
  }
  return (_Bool)uVar1;
}



_Bool responsePrintContinue(char *formatString,...)

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
  iVar1 = responsePrintInternal(STRIP_NONE,formatString,(va_list)&uStack12,false);
  uVar2 = count_leading_zeroes(iVar1);
  return SUB41(uVar2 >> 5,0);
}



_Bool responsePrintEnd(char *formatString,...)

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
  iVar1 = responsePrintInternal(STRIP_NONE,formatString,(va_list)&uStack12,true);
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



int sprintfFloat(char *buffer,int8_t len,float f,uint8_t precision)

{
  float fVar1;
  int iVar2;
  char cVar3;
  float fVar4;
  int iVar5;
  byte bVar6;
  uint in_r3;
  size_t sVar7;
  float fVar8;
  
  fVar4 = (float)(uint)precision;
  sVar7 = SEXT14(len);
  if ((buffer == (char *)0x0) || ((int)sVar7 < 2)) {
    sVar7 = 0;
  }
  else {
    memset(buffer,0,sVar7);
    fVar8 = fVar4;
    for (bVar6 = 0; bVar6 < in_r3; bVar6 = bVar6 + 1) {
      fVar8 = fVar8 * 10.0;
    }
    fVar8 = ROUND(fVar8);
    cVar3 = len + -2;
    if ((int)((uint)(fVar4 < 0.0) << 0x1f) < 0) {
      fVar8 = (float)-(int)fVar8;
    }
    buffer[(byte)(len - 1)] = '\0';
    iVar5 = (int)cVar3;
    if (fVar8 == 0.0) {
      while( true ) {
        iVar5 = (int)(char)(cVar3 - (char)((uint)fVar8 & 0xff));
        if (in_r3 <= ((uint)fVar8 & 0xff)) break;
        buffer[iVar5] = '0';
        fVar8 = (float)((int)fVar8 + 1);
      }
      cVar3 = cVar3 - (char)in_r3;
      if (in_r3 != 0) {
        buffer[iVar5] = '.';
        cVar3 = cVar3 + -1;
      }
      buffer[cVar3] = '0';
      iVar2 = (int)(char)(cVar3 + -1);
    }
    else {
      do {
        fVar1 = (float)((uint)fVar8 / 10);
        cVar3 = (char)iVar5;
        iVar2 = (int)(char)(cVar3 + -1);
        buffer[iVar5] = SUB41(fVar8,0) + SUB41(fVar1,0) * -10 + '0';
        if ((in_r3 != 0) && (iVar2 + 2 + in_r3 == sVar7)) {
          cVar3 = cVar3 + -2;
          buffer[iVar2] = '.';
          iVar2 = (int)cVar3;
        }
      } while ((fVar1 != 0.0) && (fVar8 = fVar1, iVar5 = iVar2, -1 < iVar2));
      iVar5 = (uint)(fVar4 < 0.0) << 0x1f;
      if (iVar5 < 0) {
        fVar1 = (float)(iVar2 - 1);
        cVar3 = '-';
      }
      if (iVar5 < 0) {
        buffer[iVar2] = cVar3;
        iVar2 = (int)SUB41(fVar1,0);
      }
    }
    sVar7 = (sVar7 - iVar2) - 1;
    if (iVar2 != -1) {
      memmove(buffer,buffer + iVar2 + 1,sVar7);
    }
  }
  return sVar7;
}



int RAILInt_GetActiveConfig(void)

{
  int iVar1;
  
  iVar1 = activeRailConfig;
  if (activeRailConfig != 0) {
    iVar1 = 1;
  }
  RAILInt_Assert(iVar1,0x26);
  return activeRailConfig;
}



RAIL_Handle_t RAIL_Init(RAIL_Config_t *railCfg,undefined4 cb)

{
  RAIL_Handle_t pvVar1;
  undefined4 in_r2;
  undefined4 in_r3;
  
  activeRailConfig = railCfg;
  RFHAL_SetCallbackConfig();
  pvVar1 = (RAIL_Handle_t)RAILCore_Init(railCfg,cb,in_r2,in_r3);
  return pvVar1;
}



RAIL_RadioState_t_enum RAIL_GetRadioState(void)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  iVar1 = PROTIMER_LBTIsActive();
  if (iVar1 != 0) {
    return RAIL_RF_STATE_TX;
  }
  uVar2 = read_volatile_4(Peripherals::RAC.STATUS);
  uVar2 = uVar2 & 0xf000000;
  if (uVar2 == 0x7000000) {
    return RAIL_RF_STATE_RX;
  }
  if (uVar2 < 0x7000001) {
    if (uVar2 == 0x3000000) {
      return RAIL_RF_STATE_RX_ACTIVE;
    }
    if (uVar2 < 0x3000001) {
      if (uVar2 == 0x1000000) {
        return RAIL_RF_STATE_RX;
      }
      bVar3 = uVar2 == 0x2000000;
    }
    else {
      if (uVar2 == 0x4000000) {
        return RAIL_RF_STATE_RX;
      }
      bVar3 = uVar2 == 0x5000000;
    }
    if (bVar3) {
      return RAIL_RF_STATE_RX;
    }
  }
  else {
    if (uVar2 == 0xa000000) {
      return RAIL_RF_STATE_TX;
    }
    if (uVar2 < 0xa000001) {
      if (uVar2 == 0x8000000) {
        return RAIL_RF_STATE_TX;
      }
      if (uVar2 == 0x9000000) {
        return RAIL_RF_STATE_TX_ACTIVE;
      }
    }
    else {
      if (uVar2 == 0xb000000) {
        return RAIL_RF_STATE_TX;
      }
      if (uVar2 == 0xc000000) {
        return RAIL_RF_STATE_TX;
      }
    }
  }
  return RAIL_RF_STATE_ACTIVE;
}



void RAIL_Idle(RAIL_Handle_t railHandle,RAIL_IdleMode_t_enum mode,bool wait)

{
  RAILCore_Idle(mode,wait);
  return;
}



uint32_t RAIL_StartRfSense(RAIL_Handle_t railHandle,RAIL_RfSenseBand_t band,uint32_t senseTime,
                          undefined4 *cb)

{
  uint32_t uVar1;
  
  uVar1 = RAILCore_StartRfSense(band,senseTime,cb,(uint)cb);
  return uVar1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

bool RAIL_IsRfSensed(RAIL_Handle_t railHandle)

{
  code *pcVar1;
  int iVar2;
  CORE_irqState_t irqState;
  uint uVar3;
  
  iVar2 = _DAT_43c81904;
  write_volatile_4(Peripherals::CMU_SET.HFRADIOCLKEN0,2);
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
    write_volatile_4(Peripherals::CMU_CLR.HFRADIOCLKEN0,2);
  }
  return SUB41(uVar3,0);
}



uint16_t RAIL_GetRadioEntropy(RAIL_Handle_t railHandle,uint8_t *buffer,uint16_t bytes)

{
  uint16_t uVar1;
  
  uVar1 = RAILCore_GetRadioEntropy(buffer,bytes);
  return (uint16_t)uVar1;
}



RAIL_Status_t_enum
RAIL_SetTimer(RAIL_Handle_t railHandle,uint32_t time,RAIL_TimeMode_t mode,undefined4 cb)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RFHAL_SetTimer(time,mode,(undefined)cb);
  return RVar1;
}



uint32_t RAIL_GetTimer(RAIL_Handle_t railHandle)

{
  uint32_t cnt;
  uint64_t uVar1;
  
  cnt = GENERIC_PHY_GetTimerTimeout();
  uVar1 = PROTIMER_PrecntOverflowToUs(cnt);
  return (uint32_t)uVar1;
}



void RAIL_CancelTimer(RAIL_Handle_t railHandle)

{
  GENERIC_PHY_ConfigureEvents(0,0,0,0,4,0);
  GENERIC_PHY_TimerStop();
  timerExpiredCb = 0;
  return;
}



bool RAIL_IsTimerExpired(RAIL_Handle_t railHandle)

{
  bool bVar1;
  byte bVar2;
  
  bVar1 = GENERIC_PHY_IsTimerExpired();
  bVar2 = timerExpired;
  if (bVar1 != false) {
    bVar2 = 1;
  }
  return (bool)(bVar2 & 1);
}



bool RAIL_IsTimerRunning(RAIL_Handle_t railHandle)

{
  bool bVar1;
  
  bVar1 = PROTIMER_CCTimerIsEnabled('\x02');
  return bVar1;
}



RAIL_Status_t_enum
RAIL_StartTx(RAIL_Handle_t railHandle,uint16_t channel,RAIL_TxOptions_t options,
            undefined *schedulerInfo)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RAILCore_StartTx((int)railHandle + 0xc,(uint)channel,options);
  return RVar1;
}



RAIL_Status_t_enum
RAIL_StartScheduledTx
          (RAIL_Handle_t railHandle,uint16_t channel,RAIL_TxOptions_t options,
          RAIL_ScheduleTxConfig_t *config,undefined *schedulerInfo)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RAILCore_StartScheduledTx
                    ((RAIL_Handle_t)((int)railHandle + 0xc),channel,options,config,
                     (undefined *)config);
  return RVar1;
}



RAIL_Status_t_enum
RAIL_StartCcaCsmaTx(RAIL_Handle_t railHandle,uint16_t channel,RAIL_CsmaConfig_t *csmaConfig,
                   undefined *schedulerInfo)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RAILCore_StartCcaCsmaTx
                    ((RAIL_Handle_t)((int)railHandle + 0xc),channel,(RAIL_TxOptions_t)csmaConfig,
                     (RAIL_CsmaConfig_t *)schedulerInfo,schedulerInfo);
  return RVar1;
}



RAIL_Status_t
RAIL_StartCcaLbtTx(RAIL_Handle_t railHandle,uint16_t channel,RAIL_TxOptions_t options,
                  RAIL_LbtConfig_t *lbtConfig,undefined *schedulerInfo)

{
  RAIL_Status_t RVar1;
  
  RVar1 = RAILCore_StartCcaLbtTx((int)railHandle + 0xc,channel,options,lbtConfig,lbtConfig);
  return RVar1;
}



RAIL_Status_t
RAIL_StartTxStream(RAIL_Handle_t railHandle,uint16_t channel,RAIL_StreamMode_t_enum mode)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RAILCore_StartTxStream((RAIL_Handle_t)((int)railHandle + 0xc),channel,mode);
  return (RAIL_Status_t)RVar1;
}



RAIL_Status_t_enum RAIL_StopTxStream(RAIL_Handle_t railHandle)

{
  RFHAL_StopTestMode();
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RAIL_StartRx(RAIL_Handle_t railHandle,uint16_t channel,undefined *schedulerInfo)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RAILCore_StartRx((RAIL_Handle_t)((int)railHandle + 0xc),channel,
                           (undefined4 *)schedulerInfo);
  return (RAIL_Status_t)RVar1;
}



RAIL_Status_t_enum
RAIL_ScheduleRx(RAIL_Handle_t railHandle,uint16_t channel,RAIL_ScheduleRxConfig_t *cfg,
               undefined *schedulerInfo)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RAILCore_ScheduleRx((RAIL_Handle_t)((int)railHandle + 0xc),channel,cfg,schedulerInfo);
  return RVar1;
}



int16_t RAIL_GetRssi(RAIL_Handle_t railHandle,bool wait)

{
  int16_t iVar1;
  
  iVar1 = RAILCore_GetRssi((RAIL_Handle_t)((int)railHandle + 0xc),wait);
  return iVar1;
}



RAIL_Status_t_enum
RAIL_StartAverageRssi
          (RAIL_Handle_t railHandle,uint16_t channel,uint32_t averagingTimeUs,
          undefined *schedulerInfo)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RAILCore_StartAverageRssi
                    ((RAIL_Handle_t)((int)railHandle + 0xc),channel,averagingTimeUs,schedulerInfo);
  return RVar1;
}



RAIL_Status_t_enum RAIL_EnableDirectMode(RAIL_Handle_t railHandle,bool enable)

{
  RAILCore_EnableDirectMode(enable);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t_enum RAIL_OverrideDebugFrequency(RAIL_Handle_t railHandle,uint32_t freq)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RAILCore_OverrideDebugFrequency(freq);
  return RVar1;
}



bool isTransitionState(int state)

{
  if (1 < state - 1U) {
    return state == 4;
  }
  return true;
}



undefined4 RAILCore_Init(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = RFHAL_Init();
  if (iVar1 != 0) {
    param_1 = 0;
  }
  return param_1;
}



RAIL_Status_t_enum RAIL_SetPtiProtocol(RAIL_Handle_t railHandle,RAIL_PtiProtocol_t protocol)

{
  RAIL_RadioState_t_enum RVar1;
  RAIL_Status_t_enum RVar2;
  
  RVar1 = RFHAL_GetRadioState();
  if (RVar1 == RAIL_RF_STATE_ACTIVE) {
    RVar2 = RFHAL_SetPtiProtocol((RAIL_Handle_t)((int)railHandle + 0xc),protocol);
    return RVar2;
  }
  return RAIL_STATUS_INVALID_STATE;
}



void RAILCore_Idle(RAIL_IdleMode_t_enum mode,bool wait)

{
  RAIL_RadioState_t_enum RVar1;
  
  RFHAL_Idle(mode);
  if (wait != false) {
    do {
      RVar1 = RFHAL_GetRadioState();
    } while (RVar1 != RAIL_RF_STATE_ACTIVE);
  }
  return;
}



RAIL_RadioState_t_enum RAILCore_GetRadioState(void)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  iVar1 = PROTIMER_LBTIsActive();
  if (iVar1 != 0) {
    return RAIL_RF_STATE_TX;
  }
  uVar2 = read_volatile_4(Peripherals::RAC.STATUS);
  uVar2 = uVar2 & 0xf000000;
  if (uVar2 == 0x7000000) {
    return RAIL_RF_STATE_RX;
  }
  if (uVar2 < 0x7000001) {
    if (uVar2 == 0x3000000) {
      return RAIL_RF_STATE_RX_ACTIVE;
    }
    if (uVar2 < 0x3000001) {
      if (uVar2 == 0x1000000) {
        return RAIL_RF_STATE_RX;
      }
      bVar3 = uVar2 == 0x2000000;
    }
    else {
      if (uVar2 == 0x4000000) {
        return RAIL_RF_STATE_RX;
      }
      bVar3 = uVar2 == 0x5000000;
    }
    if (bVar3) {
      return RAIL_RF_STATE_RX;
    }
  }
  else {
    if (uVar2 == 0xa000000) {
      return RAIL_RF_STATE_TX;
    }
    if (uVar2 < 0xa000001) {
      if (uVar2 == 0x8000000) {
        return RAIL_RF_STATE_TX;
      }
      if (uVar2 == 0x9000000) {
        return RAIL_RF_STATE_TX_ACTIVE;
      }
    }
    else {
      if (uVar2 == 0xb000000) {
        return RAIL_RF_STATE_TX;
      }
      if (uVar2 == 0xc000000) {
        return RAIL_RF_STATE_TX;
      }
    }
  }
  return RAIL_RF_STATE_ACTIVE;
}



void RAILCore_EnableDirectMode(bool enable)

{
  uint in_r3;
  uint uStack24;
  undefined4 uStack20;
  undefined4 uStack16;
  uint uStack12;
  
  uStack24 = (uint)CONCAT11(enable,enable);
  uStack20 = 0xb020e00;
  uStack16 = 0xe09020e;
  uStack12 = in_r3 & 0xffff0000 | 0xa02;
  GENERIC_PHY_ConfigDirectMode(&uStack24);
  return;
}



uint32_t RAIL_GetSymbolRate(RAIL_Handle_t railHandle)

{
  uint32_t uVar1;
  
  uVar1 = RFHAL_GetSymbolRate((RAIL_Handle_t)((int)railHandle + 0xc));
  return uVar1;
}



uint32_t RAIL_GetBitRate(RAIL_Handle_t railHandle)

{
  uint32_t uVar1;
  
  uVar1 = RFHAL_GetBitRate((RAIL_Handle_t)((int)railHandle + 0xc));
  return uVar1;
}



RAIL_Status_t_enum RAIL_SetStateTiming(RAIL_Handle_t railHandle,RAIL_StateTiming_t *timings)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RFHAL_SetStateTiming((RAIL_Handle_t)((int)railHandle + 0xc),timings);
  return RVar1;
}



RAIL_Status_t_enum RAIL_IsValidChannel(RAIL_Handle_t railHandle,uint16_t channel)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    if (iVar2 == *(int *)(*(int *)((int)railHandle + 0x2c) + 0xc)) {
      return RAIL_STATUS_INVALID_PARAMETER;
    }
    iVar1 = iVar2 * 0x18 + *(int *)(*(int *)((int)railHandle + 0x2c) + 8);
    if ((*(ushort *)(iVar1 + 0xe) <= channel) && (channel <= *(ushort *)(iVar1 + 0x10))) break;
    iVar2 = iVar2 + 1;
  }
  return RAIL_STATUS_NO_ERROR;
}



uint16_t RAILInt_SetChannel(RAIL_Handle_t railHandle,uint16_t channel)

{
  uint16_t uVar1;
  bool bVar2;
  bool bVar3;
  int *piVar4;
  undefined4 *puVar5;
  RAIL_Status_t_enum RVar6;
  byte bVar7;
  byte bVar8;
  RAIL_Handle_t railHandle_00;
  RAIL_Handle_t pvVar9;
  int iVar10;
  undefined4 *puVar11;
  int *piVar12;
  uint uVar13;
  undefined4 *puVar14;
  RAIL_TxPowerConfig_t local_30 [2];
  
  puVar5 = currentChannelConfigEntry;
  piVar4 = currentChannelConfig;
  piVar12 = *(int **)((int)railHandle + 0x20);
  puVar11 = *(undefined4 **)((int)railHandle + 0x24);
  uVar13 = 0;
  bVar2 = false;
  bVar3 = false;
  if (((piVar12 == (int *)0x0) || (piVar12[2] == 0)) || (pvVar9 = railHandle, piVar12[3] == 0)) {
    iVar10 = 3;
    goto LAB_00008d28;
  }
  for (; puVar14 = puVar11, uVar13 < (uint)piVar12[3]; uVar13 = uVar13 + 1) {
    puVar14 = (undefined4 *)(uVar13 * 0x18 + piVar12[2]);
    if ((*(ushort *)((int)puVar14 + 0xe) <= channel) && (channel <= *(ushort *)(puVar14 + 4))) {
      bVar3 = true;
      railHandle_00 = (RAIL_Handle_t)RAILInt_GetActiveConfig();
      RVar6 = RFHAL_GetTxPowerConfig(railHandle,local_30);
      pvVar9 = (RAIL_Handle_t)(uint)RVar6;
      bVar8 = *(byte *)((int)railHandle + 4);
      if (*(short *)((int)puVar14 + 0x12) != 0x7fff) {
        bVar7 = RAIL_ConvertDbmToRaw(railHandle_00,local_30[0].mode,*(short *)((int)puVar14 + 0x12))
        ;
        pvVar9 = (RAIL_Handle_t)(uint)bVar7;
        puVar11 = puVar14;
        if (pvVar9 < (RAIL_Handle_t)(uint)bVar8) goto LAB_00008bf8;
      }
      bVar2 = true;
      break;
    }
LAB_00008bf8:
  }
  pvVar9 = (RAIL_Handle_t)RAILInt_GetActiveConfig(pvVar9);
  RFHAL_GetTxPowerConfig(railHandle,local_30);
  bVar8 = RFHAL_GetTxPower(railHandle);
  if (bVar2) {
    bVar7 = *(byte *)((int)railHandle + 4);
  }
  else {
    if (!bVar3) {
      iVar10 = 1;
      goto LAB_00008d28;
    }
    bVar7 = RAIL_ConvertDbmToRaw(pvVar9,local_30[0].mode,*(RAIL_TxPower_t *)((int)puVar14 + 0x12));
  }
  RFHAL_SetTxPower(railHandle,(ushort)bVar7);
  uVar1 = *(uint16_t *)((int)railHandle + 2);
  if (currentChannelConfig == (int *)0x0) {
LAB_00008ca2:
    iVar10 = *piVar12;
  }
  else {
    if (((currentChannelConfig == piVar12) && (currentChannelConfigEntry != (undefined4 *)0x0)) &&
       (currentChannelConfigEntry == puVar14)) {
      if (uVar1 == channel) {
        iVar10 = 0;
      }
      else {
        iVar10 = RFHAL_SetChannel(railHandle,channel,puVar14,0);
        if (iVar10 == 0) {
          *(uint16_t *)((int)railHandle + 2) = channel;
        }
        else {
          RFHAL_SetTxPower(railHandle,(ushort)bVar8);
          RFHAL_SetChannel(railHandle,uVar1,currentChannelConfigEntry,0);
        }
      }
      goto LAB_00008d28;
    }
    if ((*currentChannelConfig == 0) || (*currentChannelConfig != *piVar12)) goto LAB_00008ca2;
    iVar10 = currentChannelConfig[1];
  }
  iVar10 = RFHAL_ConfigRadio(railHandle,iVar10);
  if ((iVar10 == 0) && (iVar10 = RFHAL_ConfigRadio(railHandle,*puVar14), iVar10 == 0)) {
    *(undefined4 **)((int)railHandle + 0x24) = puVar14;
    *(uint16_t *)((int)railHandle + 2) = channel;
    currentChannelConfig = piVar12;
    currentChannelConfigEntry = puVar14;
    iVar10 = RFHAL_SetChannel(railHandle,channel,puVar14,1);
    if (iVar10 == 0) {
      RFHAL_IssueRadioConfigChangedCallback(puVar14);
      goto LAB_00008d28;
    }
  }
  currentChannelConfig = piVar4;
  currentChannelConfigEntry = puVar5;
  if (piVar4 != (int *)0x0) {
    RFHAL_ConfigRadio(railHandle,*piVar4);
  }
  RFHAL_SetTxPower(railHandle,(ushort)bVar8);
  if (currentChannelConfigEntry != (undefined4 *)0x0) {
    RFHAL_ConfigRadio(railHandle,*currentChannelConfigEntry);
    RFHAL_SetChannel(railHandle,uVar1,currentChannelConfigEntry,0);
  }
LAB_00008d28:
  return (uint16_t)iVar10;
}



uint16_t RAILCore_ConfigChannels(RAIL_Handle_t railHandle,RAIL_ChannelConfig_t *config)

{
  byte bVar1;
  ushort uVar2;
  ushort channel;
  RAIL_ChannelConfig_t *pRVar3;
  
  pRVar3 = config;
  if (config != (RAIL_ChannelConfig_t *)0x0) {
    pRVar3 = (RAIL_ChannelConfig_t *)(FUN_00000000 + 1);
  }
  RAILInt_Assert(pRVar3,0x1f);
  *(RAIL_ChannelConfig_t **)((int)railHandle + 0x20) = config;
  RAILInt_Assert(pRVar3,0x1f);
  bVar1 = 0;
  uVar2 = 0xffff;
  while ((channel = uVar2, (uint)bVar1 < config->length &&
         ((channel = config->configs[bVar1].channelNumberStart, uVar2 <= channel ||
          (uVar2 = channel, channel != 0))))) {
    bVar1 = bVar1 + 1;
  }
  RAILInt_SetChannel(railHandle,channel);
  return channel;
}



uint16_t RAIL_ConfigChannels(RAIL_Handle_t railHandle,RAIL_ChannelConfig_t *config,int cb)

{
  uint16_t uVar1;
  
  uVar1 = RAILCore_ConfigChannels((RAIL_Handle_t)((int)railHandle + 0xc),config);
  RFHAL_SetRadioConfigChangedCallback((RAIL_Handle_t)((int)railHandle + 0xc),cb);
  return uVar1;
}



uint16_t RAILInt_GetChannel(RAIL_Handle_t railHandle)

{
  return *(uint16_t *)((int)railHandle + 2);
}



void RAIL_GetVersion(RAIL_Version_t *version,bool verbose)

{
  version->major = '\x02';
  version->minor = '\x01';
  version->rev = '\x03';
  version->multiprotocol = false;
  if (verbose != false) {
    version->build = '\0';
    version->hash = 0x6be0298c;
    version->flags = '\0';
    return;
  }
  version->build = '\0';
  version->hash = 0;
  version->flags = '\0';
  return;
}



RAIL_Status_t_enum RAIL_SetDebugMode(RAIL_Handle_t railHandle,uint32_t debugMode)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = *(int *)((int)railHandle + 0x1c);
  *(uint32_t *)((int)railHandle + 0x1c) = debugMode;
  bVar2 = iVar1 == 1;
  if (bVar2) {
    iVar1 = 0;
  }
  if (bVar2) {
    *(int *)((int)railHandle + 0x30) = iVar1;
  }
  return RAIL_STATUS_NO_ERROR;
}



uint32_t RAIL_GetDebugMode(RAIL_Handle_t railHandle)

{
  return *(uint32_t *)((int)railHandle + 0x1c);
}



RAIL_Status_t_enum
RAILCore_SetTxTransitions(RAIL_Handle_t railHandle,RAIL_StateTransitions_t *transitions)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  RAIL_RadioState_t_enum RVar4;
  RAIL_Status_t_enum RVar5;
  
  bVar1 = transitions->success;
  bVar3 = isTransitionState((uint)bVar1);
  if (bVar3 != false) {
    bVar2 = transitions->error;
    bVar3 = isTransitionState((uint)bVar2);
    if ((bVar3 != false) && (-1 < (int)((uint)(bVar1 | bVar2) << 0x1d))) {
      RVar4 = RFHAL_GetRadioState();
      if (-1 < (int)((uint)RVar4 << 0x1d)) {
        RVar5 = RFHAL_SetTxTransitions(railHandle,transitions);
        return RVar5;
      }
      return RAIL_STATUS_INVALID_STATE;
    }
  }
  return RAIL_STATUS_INVALID_PARAMETER;
}



RAIL_Status_t_enum
RAIL_SetTxTransitions(RAIL_Handle_t railHandle,RAIL_StateTransitions_t *transitions)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RAILCore_SetTxTransitions((RAIL_Handle_t)((int)railHandle + 0xc),transitions);
  return RVar1;
}



RAIL_Status_t_enum
RAILCore_SetRxTransitions(RAIL_Handle_t railHandle,RAIL_StateTransitions_t *transitions)

{
  byte bVar1;
  bool bVar2;
  RAIL_RadioState_t_enum RVar3;
  RAIL_Status_t_enum RVar4;
  
  bVar2 = isTransitionState((uint)transitions->success);
  if (bVar2 != false) {
    bVar1 = transitions->error;
    bVar2 = isTransitionState((uint)bVar1);
    if ((bVar2 != false) && (bVar1 != 4)) {
      RVar3 = RFHAL_GetRadioState();
      if (-1 < (int)((uint)RVar3 << 0x1e)) {
        RVar4 = RFHAL_SetRxTransitions(railHandle,transitions);
        return RVar4;
      }
      return RAIL_STATUS_INVALID_STATE;
    }
  }
  return RAIL_STATUS_INVALID_PARAMETER;
}



RAIL_Status_t_enum
RAIL_SetRxTransitions(RAIL_Handle_t railHandle,RAIL_StateTransitions_t *transitions)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RAILCore_SetRxTransitions((RAIL_Handle_t)((int)railHandle + 0xc),transitions);
  return RVar1;
}



uint16_t RAIL_SetFixedLength(RAIL_Handle_t railHandle,uint16_t length)

{
  uint16_t uVar1;
  
  uVar1 = RFHAL_SetFixedLength((RAIL_Handle_t)((int)railHandle + 0xc),length);
  return uVar1;
}



RAIL_Status_t RAIL_ConfigEvents(RAIL_Handle_t railHandle,RAIL_Events_t mask,RAIL_Events_t events)

{
  RAIL_Status_t RVar1;
  
  RVar1 = RFHAL_IntEnable((int)railHandle + 0xc);
  return RVar1;
}



RAIL_Status_t_enum
RAIL_ConfigRxOptions(RAIL_Handle_t railHandle,RAIL_RxOptions_t mask,RAIL_RxOptions_t options)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RFHAL_ConfigRxOptions((RAIL_Handle_t)((int)railHandle + 0xc),mask,options);
  return RVar1;
}



RAIL_Status_t_enum
RAILCore_StartRx(RAIL_Handle_t railHandle,uint16_t channel,undefined4 *schedulerInfo)

{
  RAIL_Status_t_enum RVar1;
  uint16_t uVar2;
  
  uVar2 = RAILInt_SetChannel(railHandle,channel);
  if (uVar2 == 0) {
    RVar1 = RFHAL_StartRx();
    return RVar1;
  }
  return (RAIL_Status_t_enum)uVar2;
}



RAIL_Status_t_enum
RAILCore_ScheduleRx(RAIL_Handle_t railHandle,uint16_t channel,RAIL_ScheduleRxConfig_t *cfg,
                   undefined *schedulerInfo)

{
  RAIL_RadioState_t_enum RVar1;
  RAIL_Status_t_enum RVar2;
  uint16_t uVar3;
  
  RVar1 = RAILCore_GetRadioState();
  if (RVar1 == RAIL_RF_STATE_ACTIVE) {
    uVar3 = RAILInt_SetChannel(railHandle,channel);
    if (uVar3 == 0) {
      RVar2 = RFHAL_ScheduleRx(railHandle,(uint)channel,&cfg->start);
      return RVar2;
    }
  }
  else {
    uVar3 = 2;
  }
  return (RAIL_Status_t_enum)uVar3;
}



uint16_t RAILInt_PreTxOps(RAIL_Handle_t param_1,uint16_t param_2)

{
  uint16_t uVar1;
  int iVar2;
  
  iVar2 = RFHAL_OkToTransmit();
  if (iVar2 != 0) {
    uVar1 = RAILInt_SetChannel(param_1,param_2);
    return uVar1;
  }
  return 2;
}



RAIL_Status_t_enum RAILCore_StartTx(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  RAIL_Status_t_enum RVar1;
  int iVar2;
  
  iVar2 = RAILInt_PreTxOps();
  if (iVar2 == 0) {
    RVar1 = RFHAL_StartTx(param_1,param_3);
    return RVar1;
  }
  return (RAIL_Status_t_enum)iVar2;
}



RAIL_Status_t_enum
RAILCore_StartScheduledTx
          (RAIL_Handle_t railHandle,uint16_t channel,RAIL_TxOptions_t options,
          RAIL_ScheduleTxConfig_t *config,undefined *schedulerInfo)

{
  RAIL_Status_t_enum RVar1;
  int iVar2;
  
  iVar2 = RAILInt_PreTxOps(railHandle,channel);
  if (iVar2 == 0) {
    RVar1 = RFHAL_StartScheduledTx(railHandle,options,config);
    return RVar1;
  }
  return (RAIL_Status_t_enum)iVar2;
}



RAIL_Status_t_enum
RAILCore_StartCcaCsmaTx
          (RAIL_Handle_t railHandle,uint16_t channel,RAIL_TxOptions_t options,
          RAIL_CsmaConfig_t *csmaConfig,undefined *schedulerInfo)

{
  RAIL_Status_t_enum RVar1;
  int iVar2;
  RAIL_CsmaConfig_t *csmaConfig_00;
  
  csmaConfig_00 = csmaConfig;
  iVar2 = RAILInt_PreTxOps(railHandle,channel);
  if (iVar2 == 0) {
    RVar1 = RFHAL_StartCcaCsmaTx
                      (railHandle,(uint16_t)options,(RAIL_TxOptions_t)csmaConfig,csmaConfig_00,
                       schedulerInfo);
    return RVar1;
  }
  return (RAIL_Status_t_enum)iVar2;
}



void RAILCore_StartCcaLbtTx
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = RAILInt_PreTxOps();
  if (iVar1 == 0) {
    RFHAL_StartCcaLbtTx(param_1,param_3,param_4);
    return;
  }
  return;
}



RAIL_Status_t_enum
RAILCore_StartTxStream(RAIL_Handle_t railHandle,uint16_t channel,RAIL_StreamMode_t_enum mode)

{
  uint16_t uVar1;
  
  if (RAIL_STREAM_PN9_STREAM < mode) {
    return RAIL_STATUS_INVALID_PARAMETER;
  }
  uVar1 = RAILInt_SetChannel(railHandle,channel);
  if (uVar1 == 0) {
    RAILCore_Idle(RAIL_IDLE_ABORT,true);
    if (mode == RAIL_STREAM_CARRIER_WAVE) {
      RFHAL_StartCWTestMode();
      return RAIL_STATUS_NO_ERROR;
    }
    RFHAL_StartStreamTestMode();
  }
  return (RAIL_Status_t_enum)uVar1;
}



RAIL_Status_t_enum RAIL_SetTxPower(RAIL_Handle_t railHandle,RAIL_TxPower_t power)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RFHAL_SetTxPower((RAIL_Handle_t)((int)railHandle + 0xc),power);
  return RVar1;
}



RAIL_TxPowerLevel_t RAIL_GetTxPower(RAIL_Handle_t railHandle)

{
  RAIL_TxPowerLevel_t RVar1;
  
  RVar1 = RFHAL_GetTxPower((RAIL_Handle_t)((int)railHandle + 0xc));
  return RVar1;
}



RAIL_Status_t_enum RAIL_ConfigTxPower(RAIL_Handle_t railHandle,RAIL_TxPowerConfig_t *config)

{
  RAIL_Status_t_enum RVar1;
  
  RFHAL_SetTxPower((RAIL_Handle_t)((int)railHandle + 0xc),0);
  RVar1 = RFHAL_ConfigTxPower((RAIL_Handle_t)((int)railHandle + 0xc),config);
  return RVar1;
}



RAIL_Status_t RAIL_GetTxPowerConfig(RAIL_Handle_t railHandle,RAIL_TxPowerConfig_t *config)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RFHAL_GetTxPowerConfig((RAIL_Handle_t)((int)railHandle + 0xc),config);
  return (RAIL_Status_t)RVar1;
}



// WARNING: Could not reconcile some variable overlaps

RAIL_Status_t_enum RAIL_SetTxPowerDbm(RAIL_Handle_t railHandle,RAIL_TxPower_t power)

{
  byte bVar1;
  RAIL_Status_t_enum RVar2;
  RAIL_Handle_t local_18;
  int iStack20;
  
  iStack20 = (int)power;
  local_18 = railHandle;
  RAIL_GetTxPowerConfig(railHandle,(RAIL_TxPowerConfig_t *)&local_18);
  bVar1 = RAIL_ConvertDbmToRaw(railHandle,(RAIL_TxPowerMode_t)local_18,power);
  RVar2 = RFHAL_SetTxPower((RAIL_Handle_t)((int)railHandle + 0xc),(ushort)bVar1);
  return RVar2;
}



// WARNING: Could not reconcile some variable overlaps

RAIL_TxPower_t RAIL_GetTxPowerDbm(RAIL_Handle_t railHandle)

{
  RAIL_TxPowerLevel_t powerLevel;
  RAIL_TxPower_t RVar1;
  RAIL_Handle_t local_18;
  
  local_18 = railHandle;
  RAIL_GetTxPowerConfig(railHandle,(RAIL_TxPowerConfig_t *)&local_18);
  powerLevel = RFHAL_GetTxPower((RAIL_Handle_t)((int)railHandle + 0xc));
  RVar1 = RAIL_ConvertRawToDbm(railHandle,(RAIL_TxPowerMode_t)local_18,powerLevel);
  return RVar1;
}



RAIL_Status_t_enum RAILCore_OverrideDebugFrequency(uint32_t freq)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = SYNTH_Config(freq,0);
  if (RVar1 == RAIL_STATUS_NO_ERROR) {
    RVar1 = RAIL_STATUS_NO_ERROR;
  }
  else {
    RVar1 = RAIL_STATUS_INVALID_STATE;
  }
  return RVar1;
}



RAIL_Status_t_enum
RAIL_GetTxPacketDetails(RAIL_Handle_t railHandle,RAIL_TxPacketDetails_t *pPacketDetails)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RFHAL_GetTxPacketDetails((RAIL_Handle_t)((int)railHandle + 0xc),pPacketDetails);
  return RVar1;
}



void RAIL_EnablePaCal(bool enable)

{
  paCalEnabled = enable;
  return;
}



void RAILInt_EnableCal(RAIL_Handle_t railHandle,RAIL_CalMask_t calEnable)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  *(RAIL_CalMask_t *)((int)railHandle + 0xc) = calEnable;
  *(undefined4 *)((int)railHandle + 8) = 0;
  CORE_ExitCritical(irqState);
  return;
}



undefined8 RAILInt_PendCal(int param_1,uint param_2)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  param_2 = param_2 & *(uint *)(param_1 + 0xc);
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | param_2;
  CORE_ExitCritical(irqState);
  if (param_2 == 0) {
    return 0;
  }
  return 0x200000000;
}



uint RAILInt_ClearCal(int param_1,uint param_2)

{
  CORE_irqState_t irqState;
  uint uVar1;
  
  irqState = CORE_EnterCritical();
  uVar1 = *(uint *)(param_1 + 8) & ~(param_2 & *(uint *)(param_1 + 0xc));
  *(uint *)(param_1 + 8) = uVar1;
  CORE_ExitCritical(irqState);
  return uVar1;
}



RAIL_CalMask_t RAIL_GetPendingCal(RAIL_Handle_t railHandle)

{
  return *(RAIL_CalMask_t *)((int)railHandle + 0x14);
}



void RAILCore_Calibrate(RAIL_Handle_t railHandle,undefined4 *calValues,RAIL_CalMask_t calForce)

{
  undefined4 uVar1;
  undefined4 local_14;
  
  if (calValues == (undefined4 *)0x0) {
    local_14 = 0xffffffff;
    if (calForce != 0) {
      RAILInt_ClearCal(railHandle,calForce,calForce,0xffffffff,railHandle);
      RFHAL_RunCal(railHandle,&local_14,calForce);
      return;
    }
  }
  else {
    local_14 = *calValues;
    if (calForce != 0) {
      RAILInt_ClearCal(railHandle,calForce,calForce,local_14,railHandle);
      RFHAL_RunCal(railHandle,&local_14,calForce);
      goto LAB_000090d6;
    }
  }
  uVar1 = *(undefined4 *)((int)railHandle + 8);
  RAILInt_ClearCal(railHandle,uVar1,calForce,local_14,railHandle);
  RFHAL_RunCal(railHandle,&local_14,uVar1);
  if (calValues == (undefined4 *)0x0) {
    return;
  }
LAB_000090d6:
  *calValues = local_14;
  return;
}



RAIL_Status_t_enum
RAIL_Calibrate(RAIL_Handle_t railHandle,undefined *calValues,RAIL_CalMask_t calForce)

{
  RAILCore_Calibrate((RAIL_Handle_t)((int)railHandle + 0xc),(undefined4 *)calValues,calForce);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t_enum RAIL_ConfigCal(RAIL_Handle_t railHandle,RAIL_CalMask_t calEnable)

{
  RAILInt_EnableCal((RAIL_Handle_t)((int)railHandle + 0xc),calEnable & 0x10001);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t_enum RAIL_SetTune(RAIL_Handle_t railHandle,uint32_t tune)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RFHAL_SetTune((RAIL_Handle_t)((int)railHandle + 0xc),tune);
  return RVar1;
}



uint32_t RAIL_GetTune(RAIL_Handle_t railHandle)

{
  uint32_t uVar1;
  
  uVar1 = RFHAL_GetTune((RAIL_Handle_t)((int)railHandle + 0xc));
  return uVar1;
}



RAIL_Status_t_enum
RAIL_SetPaCTune(RAIL_Handle_t railHandle,uint8_t txPaCtuneValue,uint8_t rxPaCtuneValue)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RFHAL_SetPaCTune((RAIL_Handle_t)((int)railHandle + 0xc),txPaCtuneValue,rxPaCtuneValue);
  return RVar1;
}



// WARNING: Could not reconcile some variable overlaps

RAIL_Status_t_enum RAILCore_ConfigAutoAck(RAIL_Handle_t railHandle,RAIL_AutoAckConfig_t *config)

{
  RAIL_Status_t_enum RVar1;
  RAIL_Status_t_enum RVar2;
  RAIL_RadioState_t RVar3;
  RAIL_RadioState_t RVar4;
  RAIL_AutoAckConfig_t *local_14;
  
  local_14 = config;
  if (config->enable == false) {
    RFHAL_EnableAutoAck(railHandle,false);
    RFHAL_PauseRxAutoAck(railHandle,0);
    RFHAL_PauseTxAutoAck(railHandle,0);
  }
  if (config->enable == false) {
    RVar3 = (config->rxTransitions).success;
    RVar4 = (config->rxTransitions).error;
  }
  else {
    RVar3 = '\x04';
    RVar4 = (config->rxTransitions).success;
  }
  local_14._0_2_ = CONCAT11(RVar4,RVar3);
  local_14 = (RAIL_AutoAckConfig_t *)((uint)local_14 & 0xffff0000 | (uint)(ushort)local_14);
  RVar1 = RAILCore_SetRxTransitions(railHandle,(RAIL_StateTransitions_t *)&local_14);
  if (RVar1 == RAIL_STATUS_NO_ERROR) {
    if (config->enable == false) {
      RVar3 = (config->txTransitions).success;
      RVar4 = (config->txTransitions).error;
    }
    else {
      RVar3 = '\x02';
      RVar4 = (config->txTransitions).success;
    }
    local_14._0_2_ = CONCAT11(RVar4,RVar3);
    local_14 = (RAIL_AutoAckConfig_t *)((uint)local_14 & 0xffff0000 | (uint)(ushort)local_14);
    RVar2 = RAILCore_SetTxTransitions(railHandle,(RAIL_StateTransitions_t *)&local_14);
    RVar1 = RVar2;
    if ((RVar2 == RAIL_STATUS_NO_ERROR) && (RVar1 = config->enable, config->enable != false)) {
      RFHAL_SetAutoAckTimeout(railHandle,(uint)config->ackTimeout);
      RFHAL_EnableAutoAck(railHandle,true);
      RVar1 = RVar2;
    }
  }
  return RVar1;
}



RAIL_Status_t_enum RAIL_ConfigAutoAck(RAIL_Handle_t railHandle,RAIL_AutoAckConfig_t *config)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RAILCore_ConfigAutoAck((RAIL_Handle_t)((int)railHandle + 0xc),config);
  return RVar1;
}



bool RAIL_IsAutoAckEnabled(RAIL_Handle_t railHandle)

{
  bool bVar1;
  
  bVar1 = RFHAL_IsAutoAckEnabled((RAIL_Handle_t)((int)railHandle + 0xc));
  return bVar1;
}



RAIL_Status_t_enum
RAIL_WriteAutoAckFifo(RAIL_Handle_t railHandle,uint8_t *ackData,uint8_t ackDataLen)

{
  RAIL_Status_t_enum RVar1;
  
  if (ackDataLen < 0x41) {
    RVar1 = RFHAL_WriteAutoAckFifo((RAIL_Handle_t)((int)railHandle + 0xc),ackData,ackDataLen);
    return RVar1;
  }
  return RAIL_STATUS_INVALID_PARAMETER;
}



RAIL_Status_t_enum RAIL_UseTxFifoForAutoAck(RAIL_Handle_t railHandle)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RFHAL_UseTxFifoForAutoAck((RAIL_Handle_t)((int)railHandle + 0xc));
  return RVar1;
}



RAIL_Status_t_enum RAIL_CancelAutoAck(RAIL_Handle_t railHandle)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RFHAL_CancelAutoAck((RAIL_Handle_t)((int)railHandle + 0xc));
  return RVar1;
}



void RAIL_PauseRxAutoAck(RAIL_Handle_t railHandle,bool pause)

{
  RFHAL_PauseRxAutoAck((int)railHandle + 0xc,pause);
  return;
}



bool RAIL_IsRxAutoAckPaused(RAIL_Handle_t railHandle)

{
  bool bVar1;
  
  bVar1 = RFHAL_IsRxAutoAckPaused((RAIL_Handle_t)((int)railHandle + 0xc));
  return bVar1;
}



void RAIL_PauseTxAutoAck(RAIL_Handle_t railHandle,bool pause)

{
  RFHAL_PauseTxAutoAck((int)railHandle + 0xc,pause);
  return;
}



bool RAIL_IsTxAutoAckPaused(RAIL_Handle_t railHandle)

{
  bool bVar1;
  
  bVar1 = RFHAL_IsTxAutoAckPaused();
  return bVar1;
}



RAIL_Status_t_enum RAIL_ConfigData(RAIL_Handle_t railHandle,RAIL_DataConfig_t *dataConfig)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RFHAL_ConfigData((RAIL_Handle_t)((int)railHandle + 0xc),dataConfig);
  return RVar1;
}



uint16_t RAIL_WriteTxFifo(RAIL_Handle_t railHandle,uint8_t *dataPtr,uint16_t writeLength,bool reset)

{
  uint16_t uVar1;
  
  uVar1 = RFHAL_WriteTxFifo((RAIL_Handle_t)((int)railHandle + 0xc),dataPtr,writeLength,reset);
  return uVar1;
}



uint16_t RAIL_SetTxFifo(RAIL_Handle_t railHandle,uint8_t *addr,uint16_t initLength,uint16_t size)

{
  uint16_t uVar1;
  
  uVar1 = RFHAL_SetTxBuffer((RAIL_Handle_t)((int)railHandle + 0xc),addr,initLength,size);
  return uVar1;
}



uint16_t RAIL_ReadRxFifo(RAIL_Handle_t railHandle,uint8_t *dataPtr,uint16_t readLength)

{
  uint16_t uVar1;
  
  uVar1 = RFHAL_ReadRxFifo((RAIL_Handle_t)((int)railHandle + 0xc),dataPtr,readLength);
  return uVar1;
}



RAIL_RxPacketHandle_t
RAIL_GetRxPacketInfo
          (RAIL_Handle_t railHandle,RAIL_RxPacketHandle_t packetHandle,
          RAIL_RxPacketInfo_t *pPacketInfo)

{
  RAIL_RxPacketHandle_t pvVar1;
  
  pvVar1 = RFHAL_GetRxPacketInfo(packetHandle,pPacketInfo);
  return pvVar1;
}



RAIL_Status_t_enum
RAIL_GetRxPacketDetails
          (RAIL_Handle_t railHandle,RAIL_RxPacketHandle_t packetHandle,
          RAIL_RxPacketDetails_t *pPacketDetails)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RFHAL_GetRxPacketDetails(packetHandle,pPacketDetails);
  return RVar1;
}



uint RAIL_HoldRxPacket(void)

{
  uint uVar1;
  
  uVar1 = callbackRxLenEntry;
  if (callbackRxLenEntry != 0) {
    uVar1 = callbackRxLenEntry & 0xfffffffe;
    callbackRxLenEntry = callbackRxLenEntry | 1;
  }
  return uVar1;
}



RAIL_Status_t_enum RAIL_ReleaseRxPacket(RAIL_Handle_t railHandle,RAIL_RxPacketHandle_t packetHandle)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RFHAL_ReleaseRxPacket(packetHandle);
  return RVar1;
}



uint16_t RAIL_SetTxFifoThreshold(RAIL_Handle_t railHandle,uint16_t txThreshold)

{
  uint16_t uVar1;
  
  uVar1 = RFHAL_SetTxFifoThreshold((RAIL_Handle_t)((int)railHandle + 0xc),txThreshold);
  return uVar1;
}



uint16_t RAIL_SetRxFifoThreshold(RAIL_Handle_t railHandle,uint16_t rxThreshold)

{
  uint16_t uVar1;
  
  uVar1 = RFHAL_SetRxFifoThreshold((RAIL_Handle_t)((int)railHandle + 0xc),rxThreshold);
  return uVar1;
}



uint16_t RAIL_GetTxFifoThreshold(RAIL_Handle_t railHandle)

{
  uint16_t uVar1;
  
  uVar1 = RFHAL_GetTxFifoThreshold((RAIL_Handle_t)((int)railHandle + 0xc));
  return uVar1;
}



uint16_t RAIL_GetRxFifoThreshold(RAIL_Handle_t railHandle)

{
  uint16_t uVar1;
  
  uVar1 = RFHAL_GetRxFifoThreshold((RAIL_Handle_t)((int)railHandle + 0xc));
  return uVar1;
}



uint16_t RAIL_GetTxFifoSpaceAvailable(RAIL_Handle_t railHandle)

{
  uint16_t uVar1;
  
  uVar1 = RFHAL_GetTxFifoSpaceAvailable((RAIL_Handle_t)((int)railHandle + 0xc));
  return uVar1;
}



uint16_t RAIL_GetRxFifoBytesAvailable(RAIL_Handle_t railHandle)

{
  uint16_t uVar1;
  
  uVar1 = RFHAL_GetRxFifoBytesAvailable((RAIL_Handle_t)((int)railHandle + 0xc));
  return uVar1;
}



void RAIL_ResetFifo(RAIL_Handle_t railHandle,bool txFifo,bool rxFifo)

{
  if (txFifo != false) {
    RFHAL_ResetTxFifo((RAIL_Handle_t)((int)railHandle + 0xc));
  }
  if (rxFifo != false) {
    RFHAL_ResetRxFifo((RAIL_Handle_t)((int)railHandle + 0xc));
  }
  return;
}



uint16_t RAIL_PeekRxPacket(RAIL_Handle_t railHandle,RAIL_RxPacketHandle_t packetHandle,uint8_t *pDst
                          ,uint16_t len,uint16_t offset)

{
  uint16_t uVar1;
  
  uVar1 = RFHAL_PeekRxPacket(packetHandle,pDst,len,offset);
  return uVar1;
}



void RAILInt_Assert(int param_1,uint32_t param_2)

{
  RAIL_Handle_t railHandle;
  
  if (param_1 == 0) {
    errorCodeEncountered = param_2;
    railHandle = (RAIL_Handle_t)RAILInt_GetActiveConfig();
    RAILCb_AssertFailed(railHandle,param_2);
  }
  return;
}



RAIL_Status_t_enum
RAIL_SetAddressFilterAddress
          (RAIL_Handle_t railHandle,uint8_t field,uint8_t index,uint8_t *value,bool enable)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RFHAL_SetAddressFilterAddress((int)railHandle + 0xc,field,index,value,enable,field);
  return RVar1;
}



RAIL_Status_t
RAIL_EnableAddressFilterAddress(RAIL_Handle_t railHandle,bool enable,uint8_t field,uint8_t index)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RFHAL_EnableAddressFilterAddress
                    ((RAIL_Handle_t)((int)railHandle + 0xc),enable,field,index);
  return (RAIL_Status_t)RVar1;
}



bool RAIL_EnableAddressFilter(RAIL_Handle_t railHandle,bool enable)

{
  bool bVar1;
  
  bVar1 = RFHAL_EnableAddressFilter((RAIL_Handle_t)((int)railHandle + 0xc),enable);
  return bVar1;
}



RAIL_Status_t_enum RAIL_ConfigAddressFilter(RAIL_Handle_t railHandle,RAIL_AddrConfig_t *addrConfig)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RFHAL_ConfigAddressFilter((RAIL_Handle_t)((int)railHandle + 0xc),addrConfig);
  return RVar1;
}



bool RAIL_IsAddressFilterEnabled(RAIL_Handle_t railHandle)

{
  bool bVar1;
  
  bVar1 = RFHAL_AddressFilterIsEnabled((RAIL_Handle_t)((int)railHandle + 0xc));
  return bVar1;
}



RAIL_Status_t RAIL_ConfigPti(RAIL_Handle_t railHandle,RAIL_PtiConfig_t *ptiConfig)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RFHAL_ConfigPti(ptiConfig);
  return (RAIL_Status_t)RVar1;
}



RAIL_Status_t_enum RAIL_EnablePti(RAIL_Handle_t railHandle,bool enable)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RFHAL_EnablePti(enable);
  return RVar1;
}



int16_t RAILCore_GetRssi(RAIL_Handle_t railHandle,bool wait)

{
  int16_t iVar1;
  
  iVar1 = RADIO_GetRssi(wait);
  return iVar1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

RAIL_Status_t_enum
RAILCore_StartAverageRssi
          (RAIL_Handle_t railHandle,uint16_t channel,uint32_t averagingTimeUs,
          undefined *schedulerInfo)

{
  RAIL_Status_t_enum RVar1;
  int iVar2;
  
                    // WARNING: Load size is inaccurate
  *(byte *)railHandle = *railHandle & 0xf7;
  saveRssiPeriod = read_volatile_4(Peripherals::AGC.CTRL1);
  iVar2 = RADIO_SetRssiPeriod(averagingTimeUs);
  if (iVar2 == 0) {
    iVar2 = _DAT_430c0354;
    if (_DAT_430c0354 != 0) {
      iVar2 = 1;
    }
    saveFrameDetDisable = (char)iVar2;
    write_volatile_4(Peripherals::MODEM_SET.CTRL0,0x200000);
    RVar1 = RAILCore_StartRx(railHandle,channel,(undefined4 *)averagingTimeUs);
    if (RVar1 == RAIL_STATUS_NO_ERROR) {
      GENERIC_PHY_ConfigureEvents(1,0,1,0,0,0);
    }
    else {
      if (saveFrameDetDisable == '\0') {
        write_volatile_4(Peripherals::MODEM_CLR.CTRL0,0x200000);
      }
      else {
        write_volatile_4(Peripherals::MODEM_SET.CTRL0,0x200000);
      }
      setRssiPeriod(saveRssiPeriod);
      RVar1 = RAIL_STATUS_INVALID_STATE;
    }
  }
  else {
    RVar1 = RAIL_STATUS_INVALID_PARAMETER;
  }
  return RVar1;
}



int16_t RAIL_GetAverageRssi(RAIL_Handle_t railHandle)

{
  int16_t iVar1;
  
  iVar1 = RFHAL_GetAverageRssi((RAIL_Handle_t)((int)railHandle + 0xc));
  return iVar1;
}



uint16_t RAILCore_GetRadioEntropy(uint8_t *buffer,uint16_t bytes)

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
  uVar4 = read_volatile_4(Peripherals::CMU.HFRADIOCLKEN0);
  uStack36 = __n;
  memset(buffer,0,__n);
  if ((((uVar4 | 0xcc) == uVar4) &&
      (uVar4 = read_volatile_4(Peripherals::RAC.CTRL), -1 < (int)(uVar4 << 0x1f))) &&
     (uVar4 = RADIOCMU_ClockPrescGet(0x75160), uVar4 == 0)) {
    irqState = CORE_EnterCritical();
    uVar3 = read_volatile_4(Peripherals::MODEM.CTRL0);
    uVar2 = read_volatile_4(Peripherals::FRC.RAWCTRL);
    write_volatile_4(Peripherals::MODEM_CLR.CTRL0,0x38000000);
    write_volatile_4(Peripherals::MODEM_SET.CTRL0,0x8000000);
    write_volatile_4(Peripherals::FRC.RAWCTRL,0x24);
    write_volatile_4(Peripherals::RAC_SET.RXENSRCEN,4);
    write_volatile_4(Peripherals::FRC.IFC,0x4000);
    write_volatile_4(Peripherals::FRC.CMD,0x1000);
    for (; uVar4 < __n; uVar4 = uVar4 + __n_00 & 0xffff) {
      do {
        do {
          uVar1 = read_volatile_4(Peripherals::FRC.IF);
        } while (-1 < (int)(uVar1 << 0x11));
        uVar1 = read_volatile_4(Peripherals::FRC.STATUS);
      } while (-1 < (int)(uVar1 << 0x17));
      __n_00 = __n - uVar4;
      write_volatile_4(Peripherals::FRC.IFC,0x4000);
      if (3 < (int)__n_00) {
        __n_00 = 4;
      }
      uStack36 = read_volatile_4(Peripherals::FRC.RXRAWDATA);
      memcpy(buffer + uVar4,&uStack36,__n_00);
    }
    write_volatile_4(Peripherals::RAC_CLR.RXENSRCEN,4);
    write_volatile_4(Peripherals::FRC.RAWCTRL,uVar2);
    write_volatile_4(Peripherals::MODEM.CTRL0,uVar3);
    write_volatile_4(Peripherals::FRC.IFC,0x4000);
    CORE_ExitCritical(irqState);
  }
  else {
    bytes = 0;
  }
  return bytes;
}



// WARNING: Could not reconcile some variable overlaps

uint32_t RAILCore_StartRfSense(undefined param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint32_t uVar1;
  undefined4 uStack20;
  undefined4 uStack16;
  uint uStack12;
  
  uStack12._0_2_ = CONCAT11(1,param_1);
  uStack12 = param_4 & 0xffff0000 | (uint)(ushort)uStack12;
  uStack20 = param_3;
  uStack16 = param_2;
  uVar1 = RFSENSE_Init(&uStack20);
  return uVar1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

bool RAILCore_IsRfSensed(RAIL_Handle_t railHandle)

{
  code *pcVar1;
  int iVar2;
  CORE_irqState_t irqState;
  uint uVar3;
  
  iVar2 = _DAT_43c81904;
  write_volatile_4(Peripherals::CMU_SET.HFRADIOCLKEN0,2);
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
    write_volatile_4(Peripherals::CMU_CLR.HFRADIOCLKEN0,2);
  }
  return SUB41(uVar3,0);
}



uint32_t RAIL_GetTime(void)

{
  uint32_t cnt;
  uint64_t uVar1;
  
  cnt = PROTIMER_GetTime();
  uVar1 = PROTIMER_PrecntOverflowToUs(cnt);
  return (uint32_t)uVar1;
}



RAIL_Status_t_enum RAIL_SetTime(uint32_t time)

{
  bool bVar1;
  RAIL_Status_t_enum RVar2;
  
  bVar1 = PROTIMER_SetTime(time);
  if (bVar1 == false) {
    RVar2 = RAIL_STATUS_INVALID_STATE;
  }
  else {
    RVar2 = RAIL_STATUS_NO_ERROR;
  }
  return RVar2;
}



RAIL_Status_t_enum RAIL_IEEE802154_Config2p4GHzRadio(RAIL_Handle_t railHandle)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RFHAL_IEEE802154RadioConfig2p4GHz((RAIL_Handle_t)((int)railHandle + 0xc));
  return RVar1;
}



RAIL_Status_t_enum RAILCore_IEEE802154_SetAddresses(RAIL_Handle_t param_1,undefined2 *param_2)

{
  RAIL_Status_t_enum RVar1;
  int iVar2;
  undefined2 *longAddr;
  undefined2 local_44;
  undefined2 local_42;
  undefined2 local_40;
  undefined2 local_3e;
  undefined2 local_3c;
  undefined2 local_3a;
  
  memset(&local_44,0,0x24);
  if (param_2 == (undefined2 *)0x0) {
    param_2 = &local_44;
  }
  iVar2 = 0;
  local_44 = 0xffff;
  local_42 = 0xffff;
  local_40 = 0xffff;
  local_3e = 0xffff;
  local_3c = 0xffff;
  local_3a = 0xffff;
  longAddr = param_2 + 6;
  RVar1 = RAIL_STATUS_NO_ERROR;
  do {
    if (RVar1 == RAIL_STATUS_NO_ERROR) {
      RVar1 = RFHAL_IEEE802154SetPanId(param_1,param_2[iVar2],(uint8_t)iVar2);
      if (RVar1 == RAIL_STATUS_NO_ERROR) {
        RVar1 = RFHAL_IEEE802154SetShortAddress(param_1,param_2[iVar2 + 3],(uint8_t)iVar2);
        if (RVar1 == RAIL_STATUS_NO_ERROR) {
          RVar1 = RFHAL_IEEE802154SetLongAddress(param_1,(uint8_t *)longAddr,'\0');
        }
      }
    }
    iVar2 = iVar2 + 1;
    longAddr = longAddr + 4;
  } while (iVar2 != 3);
  return RVar1;
}



RAIL_Status_t_enum
RAILCore_IEEE802154_Init(RAIL_Handle_t railHandle,RAIL_IEEE802154_Config_t *fifteenFourConfig)

{
  RAIL_Status_t_enum RVar1;
  uint uVar2;
  RAIL_IEEE802154_Config_t *local_1c;
  undefined4 uStack24;
  undefined4 uStack20;
  
  local_1c = fifteenFourConfig;
  RFHAL_IEEE802154SetFeatures
            (railHandle,fifteenFourConfig->isPanCoordinator,fifteenFourConfig->promiscuousMode,
             fifteenFourConfig->framesMask,railHandle);
  local_1c = *(RAIL_IEEE802154_Config_t **)&fifteenFourConfig->timings;
  uStack24 = *(undefined4 *)&(fifteenFourConfig->timings).idleToTx;
  uStack20 = *(undefined4 *)&(fifteenFourConfig->timings).rxSearchTimeout;
  RFHAL_SetStateTiming(railHandle,(RAIL_StateTiming_t *)&local_1c);
  RVar1 = RAILCore_ConfigAutoAck(railHandle,&fifteenFourConfig->ackConfig);
  uVar2 = (uint)RVar1;
  if ((uVar2 == 0) && (uVar2 = RFHAL_IEEE802154LoadAck(railHandle), uVar2 == 0)) {
    RVar1 = RFHAL_ConfigAddressFilter(railHandle,(RAIL_AddrConfig_t *)&initialAddrConfig);
    uVar2 = (uint)RVar1;
    if (uVar2 == 0) {
      uVar2 = RFHAL_IEEE802154SetBroadcastAddresses(railHandle);
    }
  }
  RAILCore_IEEE802154_SetAddresses(railHandle,fifteenFourConfig->addresses);
  return (RAIL_Status_t_enum)uVar2;
}



RAIL_Status_t_enum
RAIL_IEEE802154_Init(RAIL_Handle_t railHandle,RAIL_IEEE802154_Config_t *fifteenFourConfig)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RAILCore_IEEE802154_Init((RAIL_Handle_t)((int)railHandle + 0xc),fifteenFourConfig);
  return RVar1;
}



RAIL_Status_t_enum RAIL_IEEE802154_SetPanId(RAIL_Handle_t railHandle,uint16_t panId,uint8_t index)

{
  RAIL_Status_t_enum RVar1;
  
  if (index < 3) {
    RVar1 = RFHAL_IEEE802154SetPanId((RAIL_Handle_t)((int)railHandle + 0xc),panId,index);
    return RVar1;
  }
  return RAIL_STATUS_INVALID_PARAMETER;
}



RAIL_Status_t
RAIL_IEEE802154_SetShortAddress(RAIL_Handle_t railHandle,uint16_t shortAddr,uint8_t index)

{
  RAIL_Status_t_enum RVar1;
  
  if (index < 3) {
    RVar1 = RFHAL_IEEE802154SetShortAddress((RAIL_Handle_t)((int)railHandle + 0xc),shortAddr,index);
    return (RAIL_Status_t)RVar1;
  }
  return '\x01';
}



RAIL_Status_t
RAIL_IEEE802154_SetLongAddress(RAIL_Handle_t railHandle,uint8_t *longAddr,uint8_t index)

{
  RAIL_Status_t RVar1;
  
  if (index < 3) {
    RVar1 = RFHAL_IEEE802154SetLongAddress((RAIL_Handle_t)((int)railHandle + 0xc),longAddr,index);
    return RVar1;
  }
  return '\x01';
}



RAIL_Status_t_enum RAIL_IEEE802154_SetPanCoordinator(RAIL_Handle_t railHandle,bool isPanCoordinator)

{
  bool bVar1;
  RAIL_Status_t_enum RVar2;
  
  bVar1 = RFHAL_IEEE802154IsEnabled();
  if (bVar1 != false) {
    RVar2 = RFHAL_IEEE802154SetPanCoordinator((int)railHandle + 0xc,isPanCoordinator);
    return RVar2;
  }
  return RAIL_STATUS_INVALID_STATE;
}



RAIL_Status_t_enum RAIL_IEEE802154_SetPromiscuousMode(RAIL_Handle_t railHandle,bool enable)

{
  bool bVar1;
  RAIL_Status_t_enum RVar2;
  
  bVar1 = RFHAL_IEEE802154IsEnabled();
  if (bVar1 != false) {
    RVar2 = RFHAL_IEEE802154SetPromiscuousMode((int)railHandle + 0xc,enable);
    return RVar2;
  }
  return RAIL_STATUS_INVALID_STATE;
}



RAIL_Status_t_enum RAIL_IEEE802154_AcceptFrames(RAIL_Handle_t railHandle,uint8_t framesMask)

{
  bool bVar1;
  RAIL_Status_t_enum RVar2;
  
  bVar1 = RFHAL_IEEE802154IsEnabled();
  if (bVar1 != false) {
    RVar2 = RFHAL_IEEE802154AcceptFrames((RAIL_Handle_t)((int)railHandle + 0xc),framesMask);
    return RVar2;
  }
  return RAIL_STATUS_INVALID_STATE;
}



RAIL_Status_t_enum RAIL_IEEE802154_SetFramePending(RAIL_Handle_t railHandle)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RFHAL_IEEE802154SetFramePending();
  return RVar1;
}



RAIL_Status_t
RAIL_IEEE802154_GetAddress(RAIL_Handle_t railHandle,RAIL_IEEE802154_Address_t *pAddress)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RFHAL_IEEE802154GetAddress(pAddress);
  return (RAIL_Status_t)RVar1;
}



RAIL_Status_t_enum RAILCore_BLE_Init(byte *param_1)

{
  RAIL_Status_t_enum RVar1;
  
  RFHAL_BleInit();
  *param_1 = *param_1 | 1;
  RVar1 = RFHAL_SetPtiProtocol(param_1,'\x03');
  return RVar1;
}



void RAIL_BLE_Init(RAIL_Handle_t railHandle)

{
  RAILCore_BLE_Init((int)railHandle + 0xc);
  return;
}



void RAILCore_BLE_Deinit(RAIL_Handle_t railHandle)

{
                    // WARNING: Load size is inaccurate
  if ((int)((uint)*railHandle << 0x1f) < 0) {
    RFHAL_BleDeinit();
                    // WARNING: Load size is inaccurate
    *(byte *)railHandle = *railHandle & 0xfe;
    RFHAL_SetPtiProtocol(railHandle,'\0');
    return;
  }
  return;
}



void RAIL_BLE_Deinit(RAIL_Handle_t railHandle)

{
  RAILCore_BLE_Deinit((RAIL_Handle_t)((int)railHandle + 0xc));
  return;
}



bool RAIL_BLE_IsEnabled(RAIL_Handle_t railHandle)

{
  return (bool)(*(byte *)((int)railHandle + 0xc) & 1);
}



RAIL_Status_t_enum RAILCore_BLE_ConfigPhy1MbpsViterbi(RAIL_Handle_t railHandle)

{
  RAIL_RadioState_t_enum RVar1;
  RAIL_Status_t_enum RVar2;
  
                    // WARNING: Load size is inaccurate
  if (((int)((uint)*railHandle << 0x1f) < 0) &&
     (RVar1 = RFHAL_GetRadioState(), RVar1 == RAIL_RF_STATE_ACTIVE)) {
    RVar2 = RFHAL_ConfigBle1MbpsViterbi(railHandle);
    return RVar2;
  }
  return RAIL_STATUS_INVALID_STATE;
}



RAIL_Status_t RAIL_BLE_ConfigPhy1MbpsViterbi(RAIL_Handle_t railHandle)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RAILCore_BLE_ConfigPhy1MbpsViterbi((RAIL_Handle_t)((int)railHandle + 0xc));
  return (RAIL_Status_t)RVar1;
}



RAIL_Status_t_enum RAILCore_BLE_ConfigPhy1Mbps(RAIL_Handle_t railHandle)

{
  RAIL_RadioState_t_enum RVar1;
  RAIL_Status_t_enum RVar2;
  
                    // WARNING: Load size is inaccurate
  if (((int)((uint)*railHandle << 0x1f) < 0) &&
     (RVar1 = RFHAL_GetRadioState(), RVar1 == RAIL_RF_STATE_ACTIVE)) {
    RVar2 = RFHAL_ConfigBle1Mbps(railHandle);
    return RVar2;
  }
  return RAIL_STATUS_INVALID_STATE;
}



RAIL_Status_t_enum RAIL_BLE_ConfigPhy1Mbps(RAIL_Handle_t railHandle)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RAILCore_BLE_ConfigPhy1Mbps((RAIL_Handle_t)((int)railHandle + 0xc));
  return RVar1;
}



RAIL_Status_t_enum RAILCore_BLE_ConfigPhy2MbpsViterbi(RAIL_Handle_t railHandle)

{
  RAIL_RadioState_t_enum RVar1;
  RAIL_Status_t_enum RVar2;
  
                    // WARNING: Load size is inaccurate
  if (((int)((uint)*railHandle << 0x1f) < 0) &&
     (RVar1 = RFHAL_GetRadioState(), RVar1 == RAIL_RF_STATE_ACTIVE)) {
    RVar2 = RFHAL_ConfigBle2MbpsViterbi(railHandle);
    return RVar2;
  }
  return RAIL_STATUS_INVALID_STATE;
}



RAIL_Status_t_enum RAIL_BLE_ConfigPhy2MbpsViterbi(RAIL_Handle_t railHandle)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RAILCore_BLE_ConfigPhy2MbpsViterbi((RAIL_Handle_t)((int)railHandle + 0xc));
  return RVar1;
}



RAIL_Status_t_enum RAILCore_BLE_ConfigPhy2Mbps(RAIL_Handle_t railHandle)

{
  RAIL_RadioState_t_enum RVar1;
  RAIL_Status_t_enum RVar2;
  
                    // WARNING: Load size is inaccurate
  if (((int)((uint)*railHandle << 0x1f) < 0) &&
     (RVar1 = RFHAL_GetRadioState(), RVar1 == RAIL_RF_STATE_ACTIVE)) {
    RVar2 = RFHAL_ConfigBle2Mbps(railHandle);
    return RVar2;
  }
  return RAIL_STATUS_INVALID_STATE;
}



RAIL_Status_t_enum RAIL_BLE_ConfigPhy2Mbps(RAIL_Handle_t railHandle)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RAILCore_BLE_ConfigPhy2Mbps((RAIL_Handle_t)((int)railHandle + 0xc));
  return RVar1;
}



RAIL_Status_t_enum RAILCore_BLE_ConfigPhyCoded(RAIL_Handle_t railHandle,RAIL_BLE_Coding_t bleCoding)

{
  RAIL_RadioState_t_enum RVar1;
  RAIL_Status_t_enum RVar2;
  
                    // WARNING: Load size is inaccurate
  if (((int)((uint)*railHandle << 0x1f) < 0) &&
     (RVar1 = RFHAL_GetRadioState(), (int)((uint)RVar1 << 0x1f) < 0)) {
    RVar2 = RFHAL_ConfigBleCoded(railHandle,bleCoding);
    return RVar2;
  }
  return RAIL_STATUS_INVALID_STATE;
}



RAIL_Status_t_enum RAIL_BLE_ConfigPhyCoded(RAIL_Handle_t railHandle,RAIL_BLE_Coding_t bleCoding)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RAILCore_BLE_ConfigPhyCoded((RAIL_Handle_t)((int)railHandle + 0xc),bleCoding);
  return RVar1;
}



RAIL_Status_t_enum
RAILCore_BLE_ConfigChannelRadioParams
          (byte *param_1,undefined4 param_2,int param_3,uint param_4,char param_5)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  undefined4 uVar5;
  uint uVar6;
  
  if ((int)((uint)*param_1 << 0x1f) < 0) {
    bVar1 = (byte)param_2;
    bVar2 = (byte)((uint)param_2 >> 8);
    bVar3 = (byte)((uint)param_2 >> 0x10);
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
    if (param_3 << 0x1f < 0) {
      bVar4 = RFHAL_IsBleLongRangeEnabled();
      if (bVar4 == false) {
        uVar5 = 0x55;
      }
      else {
        uVar5 = 0xaa;
      }
    }
    else {
      uVar5 = 0xaa;
    }
    RFHAL_BLEPreambleSyncWordSet(uVar5,param_3);
    if (param_5 != '\0') {
      uVar5 = 0;
      uVar6 = 0;
    }
    else {
      uVar5 = 0x44;
      uVar6 = param_4 | 0x40;
    }
    RFHAL_BLEWhiteningSet(uVar5,uVar6,param_5 == '\0');
    return RAIL_STATUS_NO_ERROR;
  }
  return RAIL_STATUS_INVALID_STATE;
}



RAIL_Status_t_enum
RAIL_BLE_ConfigChannelRadioParams
          (RAIL_Handle_t railHandle,uint32_t crcInit,uint32_t accessAddress,uint16_t channel,
          bool disableWhitening)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = RAILCore_BLE_ConfigChannelRadioParams
                    ((byte *)((int)railHandle + 0xc),crcInit,accessAddress,(uint)channel,
                     disableWhitening);
  return RVar1;
}



void eventDefault(void)

{
  return;
}



void radioConfigChangedDefault(void)

{
  return;
}



void setRssiPeriod(uint param_1)

{
  if (param_1 != 0) {
    write_volatile_4(Peripherals::AGC_CLR.CTRL1,0xffffff00);
    write_volatile_4(Peripherals::AGC_SET.CTRL1,param_1 & 0xffffff00);
  }
  return;
}



void callRailGenericCb_isra_1(uint *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  RAILInt_GetActiveConfig();
  if ((*param_1 & param_3 | param_1[1] & param_4) != 0) {
                    // WARNING: Could not recover jumptable at 0x000096b2. Too many branches
                    // WARNING: Treating indirect jump as call
    (*eventCb)();
    return;
  }
  return;
}



void RFHAL_NotifyUserOfIrCal(byte *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  if ((-1 < (int)((uint)*param_1 << 0x1e)) || (*(int *)(param_1 + 0x24) == 0)) {
    return;
  }
  *param_1 = *param_1 & 0xfd;
  piVar1 = (int *)read_volatile_4(Peripherals::SEQ.PHYINFO);
  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
    IRCAL_Init(piVar1[3]);
  }
  if (**(int **)(*(int *)(param_1 + 0x24) + 0x14) != -1) {
    IRCAL_Set();
    return;
  }
  if ((*(uint *)(param_1 + 0x4c) & 2) == 0) {
    *param_1 = *param_1 | 2;
    return;
  }
  uVar3 = RAILInt_PendCal(param_1,0x10000);
  uVar2 = (undefined4)((ulonglong)uVar3 >> 0x20);
  callRailGenericCb_isra_1(param_1 + 0x48,uVar2,(int)uVar3,uVar2);
  return;
}



void RFHAL_SetRadioConfigChangedCallback(RAIL_Handle_t railHandle,int cb)

{
  if (cb == 0) {
    cb = 0x9677;
  }
  radioConfigChangedCb = cb;
  return;
}



void RFHAL_IssueRadioConfigChangedCallback(undefined4 param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar1;
  
  UNRECOVERED_JUMPTABLE = radioConfigChangedCb;
  uVar1 = RAILInt_GetActiveConfig();
                    // WARNING: Could not recover jumptable at 0x00009758. Too many branches
                    // WARNING: Treating indirect jump as call
  (*UNRECOVERED_JUMPTABLE)(uVar1,param_1);
  return;
}



void GENERIC_PHY_EventCallback(uint param_1,uint param_2,int param_3)

{
  MODEM_SET *pMVar1;
  code *UNRECOVERED_JUMPTABLE;
  int16_t iVar2;
  int iVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  uint uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  uVar8 = param_1;
  uVar9 = param_2;
  iVar10 = param_3;
  uVar5 = RAILInt_GetActiveConfig();
  uVar4 = (uint)(uVar5 >> 0x20);
  uVar6 = uVar5 & 0xffffffff00000000 | (ulonglong)lastTxPacketTimeTicks;
  iVar3 = (int)uVar5;
  if ((param_2 & 2 | param_1 & 0xc0c0001) == 0) {
LAB_00009858:
    uVar6 = CONCAT44(uVar4,lastTxPacketTimeTicks);
    if ((param_1 | param_2) == 0) goto LAB_00009888;
  }
  else {
    if ((param_1 & 0x40000) != 0) {
      uVar6 = GENERIC_PHY_PreviousTxTime();
    }
    lastTxPacketTimeTicks = (uint)uVar6;
    if ((param_1 & 0x80000) != 0) {
      uVar5 = GENERIC_PHY_PreviousTxTime();
      uVar6 = uVar5 & 0xffffffff00000000 | (ulonglong)lastTxPacketTimeTicks;
      lastTxAckPacketTimeTicks = (undefined4)uVar5;
    }
    lastTxPacketTimeTicks = (uint)uVar6;
    if (((param_1 & 0x8000000) != 0) &&
       (uVar4 = read_volatile_4(Peripherals::SEQ.REG024), (uVar4 & 0xff000000) == 0x2000000)) {
      write_volatile_4(Peripherals::RAC_SET.RXENSRCEN,2);
    }
    if ((param_1 & 0xc000000) != 0) {
      setRssiPeriod(saveRssiPeriodPreCca);
      uVar6 = CONCAT44(extraout_r1,lastTxPacketTimeTicks);
      saveRssiPeriodPreCca = 0;
    }
    lastTxPacketTimeTicks = (uint)uVar6;
    if ((param_1 & 1) != 0) {
      uVar8 = 0;
      uVar9 = 0;
      GENERIC_PHY_ConfigureEvents(1,0,0,0,0,0,iVar10);
      iVar2 = RADIO_GetRssi(true);
      *(int16_t *)(iVar3 + 0x12) = iVar2;
      RAILCore_Idle(RAIL_IDLE_ABORT,false);
      if (saveFrameDetDisable == '\0') {
        pMVar1 = (MODEM_SET *)&Peripherals::MODEM_CLR;
      }
      else {
        pMVar1 = &Peripherals::MODEM_SET;
      }
      ((MODEM_CLR *)pMVar1)->CTRL0 = 0x200000;
      setRssiPeriod(saveRssiPeriod);
      saveRssiPeriod = 0;
      *(byte *)(iVar3 + 0xc) = *(byte *)(iVar3 + 0xc) | 8;
      uVar6 = CONCAT44(extraout_r1_00,lastTxPacketTimeTicks);
    }
    lastTxPacketTimeTicks = (uint)uVar6;
    if ((param_2 & 2) != 0) {
      uVar7 = RAILInt_PendCal(iVar3 + 0xc,1);
      uVar4 = (uint)((ulonglong)uVar7 >> 0x20);
      param_1 = param_1 | (uint)uVar7;
      param_2 = param_2 & 0xfffffffd | uVar4;
      goto LAB_00009858;
    }
  }
  lastTxPacketTimeTicks = (uint)uVar6;
  callRailGenericCb_isra_1(iVar3 + 0x54,(int)(uVar6 >> 0x20),param_1,param_2,uVar8,uVar9);
  lastTxPacketTimeTicks = 0xffffffff;
  lastTxAckPacketTimeTicks = 0xffffffff;
  if ((param_1 & 8) != 0) {
    cachedPacketHandle = 0;
  }
LAB_00009888:
  UNRECOVERED_JUMPTABLE = timerExpiredCb;
  if (param_3 << 0x1d < 0) {
    timerExpiredCb = FUN_00000000;
    timerExpired = 1;
    if (UNRECOVERED_JUMPTABLE != FUN_00000000) {
                    // WARNING: Could not recover jumptable at 0x000098a6. Too many branches
                    // WARNING: Treating indirect jump as call
      (*UNRECOVERED_JUMPTABLE)(timerExpiredCbArg);
      return;
    }
  }
  return;
}



RAIL_Status_t_enum RFHAL_IEEE802154GetAddress(RAIL_IEEE802154_Address_t *pAddress)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  if (pAddress == (RAIL_IEEE802154_Address_t *)0x0) {
    return RAIL_STATUS_INVALID_PARAMETER;
  }
  uVar3 = read_volatile_4(Peripherals::BUFC.BUF1_ADDR);
  uVar2 = read_volatile_4(Peripherals::BUFC.BUF1_CTRL);
  uVar4 = read_volatile_4(Peripherals::RAC.SR1);
  uVar5 = (uVar4 << 0x18) >> 0x1e;
  uVar6 = (0x40 << (uVar2 & 0xff)) - 1U & 0xffff;
  iVar7 = uVar3 + 0x20000000;
  uVar2 = read_volatile_4(Peripherals::SEQ.REG018);
  if (uVar5 == 3) {
    iVar8 = 0;
    do {
      *(undefined *)((int)&pAddress->field_0 + iVar8) =
           *(undefined *)(iVar7 + (((uVar2 & 0xffff) - 8) + iVar8 & uVar6));
      iVar8 = iVar8 + 1;
    } while (iVar8 != 8);
  }
  else {
    if (uVar5 != 2) {
      return RAIL_STATUS_INVALID_STATE;
    }
    bVar1 = *(byte *)(iVar7 + ((uVar2 & 0xffff) - 2 & uVar6));
    *(ushort *)&pAddress->field_0 = (ushort)bVar1;
    *(ushort *)&pAddress->field_0 =
         CONCAT11(*(undefined *)(iVar7 + ((uVar2 & 0xffff) - 1 & uVar6)),bVar1);
  }
  pAddress->length = (byte)uVar4 >> 6;
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t_enum
RFHAL_GetTxPacketDetails(RAIL_Handle_t railHandle,RAIL_TxPacketDetails_t *pPacketDetails)

{
  int *piVar1;
  
  if (pPacketDetails == (RAIL_TxPacketDetails_t *)0x0) {
    return RAIL_STATUS_INVALID_PARAMETER;
  }
  if (pPacketDetails->isAck == false) {
    piVar1 = &lastTxPacketTimeTicks;
  }
  else {
    piVar1 = &lastTxAckPacketTimeTicks;
  }
  if (*piVar1 != -1) {
    TIMING_CalcTxTimeStampUs((int)railHandle + 0x28,*piVar1,pPacketDetails);
    return RAIL_STATUS_NO_ERROR;
  }
  return RAIL_STATUS_INVALID_STATE;
}



undefined4
RFHAL_IntEnable(int param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5,uint param_6)

{
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) & ~param_3 | param_3 & param_5;
  *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) & ~param_4 | param_4 & param_6;
  GENERIC_PHY_ConfigureEvents
            (param_3 & 0xfffffffe,param_4,param_3 & 0xfffffffe & param_5 | 0xc000000,
             param_4 & param_6 | 2,0,0);
  RFHAL_NotifyUserOfIrCal(param_1);
  return 0;
}



void RFHAL_SetCallbackConfig(int *param_1)

{
  eventCb = *param_1;
  if (eventCb == 0) {
    eventCb = 0x9675;
  }
  radioConfigChangedCb = param_1[9];
  if (radioConfigChangedCb == 0) {
    radioConfigChangedCb = 0x9677;
  }
  return;
}



uint16_t RFHAL_PeekRxPacket(RAIL_RxPacketHandle_t packetHandle,uint8_t *pDst,uint16_t len,
                           uint16_t offset)

{
  ushort uVar1;
  uint16_t uVar2;
  CORE_irqState_t CVar3;
  uint uVar4;
  ushort local_2a;
  undefined auStack40 [2];
  ushort local_26;
  
  uVar4 = (uint)len;
  if (pDst == (uint8_t *)0x0) {
    return 0;
  }
  if (uVar4 == 0) {
    return len;
  }
  if (packetHandle == (RAIL_RxPacketHandle_t)0x0) {
LAB_00009aae:
    uVar2 = (uint16_t)packetHandle;
  }
  else {
    CVar3 = CORE_EnterCritical();
    uVar1 = cachedPacketBytes;
    if (packetHandle == cachedPacketHandle) {
      local_2a = cachedPacketStartOffset;
      CORE_ExitCritical(CVar3);
      local_26 = uVar1;
    }
    else {
      CORE_ExitCritical(CVar3);
      packetHandle = (RAIL_RxPacketHandle_t)BUFC_GetRxPacketInfo(packetHandle,auStack40,&local_2a);
      if (packetHandle == (RAIL_RxPacketHandle_t)0x0) goto LAB_00009aae;
      CVar3 = CORE_EnterCritical();
      cachedPacketStartOffset = local_2a;
      cachedPacketBytes = local_26;
      cachedPacketHandle = packetHandle;
      CORE_ExitCritical(CVar3);
    }
    if ((uint)local_26 < offset + uVar4) {
      uVar4 = (uint)(ushort)(local_26 - offset);
    }
    uVar2 = BUFC_Peek(1,pDst,uVar4,(uint)local_2a + (uint)offset & 0xffff);
  }
  return uVar2;
}



RAIL_Status_t_enum RFHAL_SetPtiProtocol(RAIL_Handle_t railHandle,RAIL_PtiProtocol_t protocol)

{
  uint uVar1;
  RAIL_Status_t_enum RVar2;
  int in_r2;
  uint in_r3;
  bool bVar3;
  
  RVar2 = protocol & 0xf0;
  bVar3 = (protocol & 0xf0) == 0;
  if (bVar3) {
    in_r2 = 0x21000f7c;
    uVar1 = read_volatile_4(Peripherals::SEQ.REG080);
    in_r3 = uVar1 & 0xfffffff0 | protocol & 0xf;
  }
  if (bVar3) {
    *(uint *)(in_r2 + 4) = in_r3;
  }
  else {
    RVar2 = RAIL_STATUS_INVALID_PARAMETER;
  }
  return RVar2;
}



void RFHAL_Idle(RAIL_IdleMode_t_enum mode)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  switch(mode) {
  case RAIL_IDLE:
    iVar1 = 0;
    iVar2 = iVar1;
    iVar3 = iVar1;
    break;
  case RAIL_IDLE_ABORT:
    iVar1 = 0;
    goto LAB_00009af6;
  case RAIL_IDLE_FORCE_SHUTDOWN:
    iVar1 = 1;
LAB_00009af6:
    iVar2 = 0;
    iVar3 = 1;
    break;
  case RAIL_IDLE_FORCE_SHUTDOWN_CLEAR_FLAGS:
    iVar1 = 1;
    iVar2 = iVar1;
    iVar3 = iVar1;
    break;
  default:
    goto switchD_00009aea_caseD_4;
  }
  GENERIC_PHY_RadioIdle(iVar3,iVar1,iVar2);
  if (iVar3 != 0) {
    setRssiPeriod(saveRssiPeriodPreCca);
    saveRssiPeriodPreCca = 0;
  }
switchD_00009aea_caseD_4:
  return;
}



RAIL_RadioState_t_enum RFHAL_GetRadioState(void)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  iVar1 = PROTIMER_LBTIsActive();
  if (iVar1 != 0) {
    return RAIL_RF_STATE_TX;
  }
  uVar2 = read_volatile_4(Peripherals::RAC.STATUS);
  uVar2 = uVar2 & 0xf000000;
  if (uVar2 == 0x7000000) {
    return RAIL_RF_STATE_RX;
  }
  if (uVar2 < 0x7000001) {
    if (uVar2 == 0x3000000) {
      return RAIL_RF_STATE_RX_ACTIVE;
    }
    if (uVar2 < 0x3000001) {
      if (uVar2 == 0x1000000) {
        return RAIL_RF_STATE_RX;
      }
      bVar3 = uVar2 == 0x2000000;
    }
    else {
      if (uVar2 == 0x4000000) {
        return RAIL_RF_STATE_RX;
      }
      bVar3 = uVar2 == 0x5000000;
    }
    if (bVar3) {
      return RAIL_RF_STATE_RX;
    }
  }
  else {
    if (uVar2 == 0xa000000) {
      return RAIL_RF_STATE_TX;
    }
    if (uVar2 < 0xa000001) {
      if (uVar2 == 0x8000000) {
        return RAIL_RF_STATE_TX;
      }
      if (uVar2 == 0x9000000) {
        return RAIL_RF_STATE_TX_ACTIVE;
      }
    }
    else {
      if (uVar2 == 0xb000000) {
        return RAIL_RF_STATE_TX;
      }
      if (uVar2 == 0xc000000) {
        return RAIL_RF_STATE_TX;
      }
    }
  }
  return RAIL_RF_STATE_ACTIVE;
}



uint RFHAL_OkToTransmit(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::RAC.SR0);
  return ((uVar1 ^ 0x80) << 0x18) >> 0x1f;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

RAIL_Status_t_enum
RFHAL_StartAverageRssi
          (RAIL_Handle_t railHandle,uint16_t channel,uint32_t averagingTimeUs,
          undefined *schedulerInfo)

{
  RAIL_Status_t_enum RVar1;
  int iVar2;
  
                    // WARNING: Load size is inaccurate
  *(byte *)railHandle = *railHandle & 0xf7;
  saveRssiPeriod = read_volatile_4(Peripherals::AGC.CTRL1);
  iVar2 = RADIO_SetRssiPeriod(averagingTimeUs);
  if (iVar2 == 0) {
    iVar2 = _DAT_430c0354;
    if (_DAT_430c0354 != 0) {
      iVar2 = 1;
    }
    saveFrameDetDisable = (char)iVar2;
    write_volatile_4(Peripherals::MODEM_SET.CTRL0,0x200000);
    RVar1 = RAILCore_StartRx(railHandle,channel,(undefined4 *)averagingTimeUs);
    if (RVar1 == RAIL_STATUS_NO_ERROR) {
      GENERIC_PHY_ConfigureEvents(1,0,1,0,0,0);
    }
    else {
      if (saveFrameDetDisable == '\0') {
        write_volatile_4(Peripherals::MODEM_CLR.CTRL0,0x200000);
      }
      else {
        write_volatile_4(Peripherals::MODEM_SET.CTRL0,0x200000);
      }
      setRssiPeriod(saveRssiPeriod);
      RVar1 = RAIL_STATUS_INVALID_STATE;
    }
  }
  else {
    RVar1 = RAIL_STATUS_INVALID_PARAMETER;
  }
  return RVar1;
}



int16_t RFHAL_GetAverageRssi(RAIL_Handle_t railHandle)

{
  return *(int16_t *)((int)railHandle + 6);
}



RAIL_Status_t_enum RFHAL_ScheduleRx(RAIL_Handle_t railHandle,undefined4 param_2,uint *param_3)

{
  RAIL_Status_t_enum RVar1;
  uint32_t us;
  char cVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  char cVar6;
  undefined4 uVar7;
  uint64_t uVar8;
  
  cVar6 = *(char *)(param_3 + 1);
  if (cVar6 == '\x01') {
    if ((uint)*(ushort *)((int)railHandle + 0x38) <= *param_3) goto LAB_00009c5e;
    us = 0;
  }
  else {
    if (cVar6 == '\x02') {
      uVar7 = 0;
      goto LAB_00009c78;
    }
LAB_00009c5e:
    us = *param_3 - (uint)*(ushort *)((int)railHandle + 0x38);
  }
  uVar8 = PROTIMER_UsToPrecntOverflow(us);
  uVar7 = (undefined4)uVar8;
  cVar6 = *(char *)(param_3 + 1);
  if (cVar6 != '\0') {
    cVar6 = '\x01';
  }
LAB_00009c78:
  cVar2 = *(char *)(param_3 + 3);
  if (cVar2 == '\x02') {
    uVar5 = 0;
  }
  else {
    uVar8 = PROTIMER_UsToPrecntOverflow(param_3[2]);
    uVar5 = (undefined4)uVar8;
    cVar2 = *(char *)(param_3 + 3);
    if (cVar2 != '\0') {
      cVar2 = '\x01';
    }
  }
  uVar4 = count_leading_zeroes((uint)*(byte *)((int)param_3 + 0xd));
  cVar3 = *(char *)((int)param_3 + 0xe);
  if (cVar3 != '\0') {
    cVar3 = '\x01';
  }
  RVar1 = GENERIC_PHY_SchedulePacketRx(railHandle,uVar7,cVar6,uVar5,cVar2,uVar4 >> 5,cVar3);
  return RVar1;
}



RAIL_Status_t_enum RFHAL_StartRx(void)

{
  GENERIC_PHY_StartRx(0);
  return RAIL_STATUS_NO_ERROR;
}



undefined4 RFHAL_EnableRxRawCapture(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 - 1U & 0xff;
  if (uVar2 < 3) {
    param_2 = *(uint *)(&CSWTCH_140 + uVar2 * 4);
  }
  uVar1 = read_volatile_4(Peripherals::MODEM.CTRL0);
  if (2 < uVar2) {
    param_2 = 0;
  }
  write_volatile_4(Peripherals::MODEM.CTRL0,uVar1 & 0xc7ffffff | param_2);
  write_volatile_4(Peripherals::MODEM_SET.CTRL0,0x200000);
  uVar2 = read_volatile_4(Peripherals::FRC.BUFFERMODE);
  write_volatile_4(Peripherals::FRC.BUFFERMODE,uVar2 & 0xfffffff9 | 4);
  write_volatile_4(Peripherals::RAC_SET.SR3,0x10000000);
  write_volatile_4(Peripherals::FRC.RAWCTRL,4);
  return 0;
}



void RFHAL_DisableRxRawCapture(void)

{
  write_volatile_4(Peripherals::FRC_CLR.BUFFERMODE,6);
  write_volatile_4(Peripherals::FRC.RAWCTRL,0);
  write_volatile_4(Peripherals::RAC_CLR.SR3,0x10000000);
  write_volatile_4(Peripherals::MODEM_CLR.CTRL0,0x200000);
  write_volatile_4(Peripherals::MODEM_CLR.CTRL0,0x38000000);
  return;
}



void RFHAL_AcceptCrcErrors(bool accepterrors)

{
  FRC_SET *pFVar1;
  
  if (accepterrors == false) {
    pFVar1 = (FRC_SET *)&Peripherals::FRC_CLR;
  }
  else {
    pFVar1 = &Peripherals::FRC_SET;
  }
  ((FRC_CLR *)pFVar1)->RXCTRL = 2;
  return;
}



RAIL_Status_t_enum
RFHAL_ConfigRxOptions(RAIL_Handle_t railHandle,RAIL_RxOptions_t mask,RAIL_RxOptions_t options)

{
  FRC_SET *pFVar1;
  MODEM_SET *pMVar2;
  uint uVar3;
  
  if ((int)(mask << 0x1c) < 0) {
    if ((options & 8) == 0) {
      pFVar1 = (FRC_SET *)&Peripherals::FRC_CLR;
    }
    else {
      pFVar1 = &Peripherals::FRC_SET;
    }
    ((FRC_CLR *)pFVar1)->RXCTRL = 8;
  }
  if ((int)(mask << 0x1f) < 0) {
    if ((options & 1) == 0) {
      pFVar1 = (FRC_SET *)&Peripherals::FRC_CLR;
    }
    else {
      pFVar1 = &Peripherals::FRC_SET;
    }
    ((FRC_CLR *)pFVar1)->RXCTRL = 1;
  }
  if ((int)(mask << 0x1d) < 0) {
    if ((options & 4) == 0) {
      pMVar2 = (MODEM_SET *)&Peripherals::MODEM_CLR;
    }
    else {
      pMVar2 = &Peripherals::MODEM_SET;
    }
    ((MODEM_CLR *)pMVar2)->CTRL1 = 0x200;
  }
  if ((int)(mask << 0x1e) < 0) {
    RFHAL_AcceptCrcErrors(SUB41((options << 0x1e) >> 0x1f,0));
  }
  if ((int)(mask << 0x1b) < 0) {
    if ((options & 0x10) == 0) {
      uVar3 = 0x1b;
    }
    else {
      uVar3 = 0;
    }
    write_volatile_4(Peripherals::FRC.TRAILRXDATA,uVar3);
  }
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t_enum
RFHAL_SetPaCTune(RAIL_Handle_t railHandle,uint8_t txPaCtuneValue,uint8_t rxPaCtuneValue)

{
  PA_SetCTune(txPaCtuneValue,rxPaCtuneValue);
  return RAIL_STATUS_NO_ERROR;
}



uint32_t RFHAL_GetTimer(RAIL_Handle_t railHandle)

{
  uint32_t cnt;
  uint64_t uVar1;
  
  cnt = GENERIC_PHY_GetTimerTimeout();
  uVar1 = PROTIMER_PrecntOverflowToUs(cnt);
  return (uint32_t)uVar1;
}



void RFHAL_CancelTimer(RAIL_Handle_t railHandle)

{
  GENERIC_PHY_ConfigureEvents(0,0,0,0,4,0);
  GENERIC_PHY_TimerStop();
  timerExpiredCb = 0;
  return;
}



RAIL_Status_t_enum RFHAL_SetTimer(uint32_t time,RAIL_TimeMode_t mode,byte cb)

{
  CORE_irqState_t irqState;
  int iVar1;
  uint uVar2;
  undefined4 in_r3;
  uint64_t uVar3;
  uint uVar4;
  
  uVar2 = (uint)cb;
  if (mode == '\x02') {
    RFHAL_CancelTimer((RAIL_Handle_t)time);
  }
  else {
    uVar4 = uVar2;
    irqState = CORE_EnterCritical();
    if ((timerExpiredCb == 0) || (timerExpiredCb == uVar2)) {
      timerExpiredCb = uVar2;
      timerExpiredCbArg = in_r3;
      GENERIC_PHY_ConfigureEvents(0,0,0,0,4,4,uVar4);
      timerExpired = 0;
      uVar3 = PROTIMER_UsToPrecntOverflow(time);
      if (mode != '\0') {
        mode = '\x01';
      }
      iVar1 = GENERIC_PHY_TimerStart((int)uVar3,mode);
    }
    else {
      iVar1 = 0;
    }
    CORE_ExitCritical(irqState);
    if (iVar1 == 0) {
      timerExpiredCb = iVar1;
      return RAIL_STATUS_INVALID_PARAMETER;
    }
  }
  return RAIL_STATUS_NO_ERROR;
}



bool RFHAL_IsTimerExpired(RAIL_Handle_t railHandle)

{
  bool bVar1;
  byte bVar2;
  
  bVar1 = GENERIC_PHY_IsTimerExpired();
  bVar2 = timerExpired;
  if (bVar1 != false) {
    bVar2 = 1;
  }
  return (bool)(bVar2 & 1);
}



bool RFHAL_IsTimerRunning(RAIL_Handle_t railHandle)

{
  bool bVar1;
  
  bVar1 = PROTIMER_CCTimerIsEnabled('\x02');
  return bVar1;
}



uint32_t RFHAL_GetSymbolRate(RAIL_Handle_t railHandle)

{
  uint uVar1;
  uint32_t uVar2;
  
  uVar2 = RADIO_ComputeTxBaudrate();
  uVar1 = read_volatile_4(Peripherals::MODEM.CTRL0);
  if ((uVar1 & 0x30) == 0x10) {
    return uVar2 >> 1;
  }
  if ((uVar1 & 0x30) != 0x20) {
    return uVar2;
  }
  return uVar2 / (((uVar1 << 0x10) >> 0x1b) + 1);
}



uint32_t RFHAL_GetBitRate(RAIL_Handle_t railHandle)

{
  uint uVar1;
  uint32_t uVar2;
  uint uVar3;
  
  uVar1 = read_volatile_4(Peripherals::MODEM.CTRL0);
  if ((uVar1 & 0x30) == 0x20) {
    uVar3 = (uVar1 << 0xd) >> 0x1d;
    if (uVar3 != 0) {
      uVar3 = ((uVar1 << 0x10) >> 0x1b) / uVar3;
    }
    if ((uVar1 & 0x180000) != 0) {
      uVar3 = uVar3 << 1;
    }
    uVar3 = uVar3 >> 1;
    if (2 < uVar3) {
      uVar3 = 4;
    }
  }
  else {
    uVar1 = read_volatile_4(Peripherals::MODEM.CTRL0);
    if (((uVar1 & 0x1c0) == 0x40) || ((uVar1 & 0x1c0) == 0x100)) {
      uVar3 = 2;
    }
    else {
      uVar3 = 1;
    }
  }
  uVar2 = RADIO_ComputeTxSymbolRate(railHandle);
  return uVar3 * uVar2;
}



// WARNING: Could not reconcile some variable overlaps

uint32_t RFHAL_StartRfSense(undefined param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint32_t uVar1;
  undefined4 local_14;
  undefined4 local_10;
  uint local_c;
  
  local_c._0_2_ = CONCAT11(1,param_1);
  local_c = param_4 & 0xffff0000 | (uint)(ushort)local_c;
  local_14 = param_3;
  local_10 = param_2;
  uVar1 = RFSENSE_Init(&local_14);
  return uVar1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

bool RFHAL_IsRfSensed(RAIL_Handle_t railHandle)

{
  code *pcVar1;
  int iVar2;
  CORE_irqState_t irqState;
  uint uVar3;
  
  iVar2 = _DAT_43c81904;
  write_volatile_4(Peripherals::CMU_SET.HFRADIOCLKEN0,2);
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
    write_volatile_4(Peripherals::CMU_CLR.HFRADIOCLKEN0,2);
  }
  return SUB41(uVar3,0);
}



void RFHAL_RunCal(int param_1,int *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x24);
  if (piVar1 != (int *)0x0) {
    piVar1 = (int *)piVar1[5];
  }
  if (param_3 << 0x1f < 0) {
    TEMPCAL_Perform();
  }
  if (param_3 << 0xf < 0) {
    iVar2 = *param_2;
    if (iVar2 == -1) {
      iVar2 = IRCAL_Perform();
      *param_2 = iVar2;
    }
    else {
      IRCAL_Set(iVar2);
    }
    if (piVar1 != (int *)0x0) {
      *piVar1 = iVar2;
    }
  }
  return;
}



void RFHAL_EnablePaCal(bool enable)

{
  paCalEnabled = enable;
  return;
}



RAIL_Status_t_enum
RFHAL_SetTxTransitions(RAIL_Handle_t railHandle,RAIL_StateTransitions_t *transitions)

{
  ushort uVar1;
  
  uVar1 = read_volatile_2(Peripherals::SEQ.REG024._0_2_);
  write_volatile_4(Peripherals::SEQ.REG024,
                   (uint)transitions->error << 0x18 | (uint)transitions->success << 0x10 |
                   (uint)uVar1);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t_enum
RFHAL_SetRxTransitions(RAIL_Handle_t railHandle,RAIL_StateTransitions_t *transitions)

{
  ushort uVar1;
  
  uVar1 = read_volatile_2(Peripherals::SEQ.REG024._2_2_);
  write_volatile_4(Peripherals::SEQ.REG024,
                   (uint)transitions->success | (uint)uVar1 << 0x10 | (uint)transitions->error << 8)
  ;
  return RAIL_STATUS_NO_ERROR;
}



void RFHAL_SetCRCInitVal(uint param_1)

{
  write_volatile_4(Peripherals::CRC.INIT,param_1);
  write_volatile_4(Peripherals::CRC.CMD,1);
  return;
}



RAIL_Status_t RFHAL_ConfigTxPower(RAIL_Handle_t railHandle,RAIL_TxPowerConfig_t *config)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = PA_Config(config);
  TIMING_RecalculatePaRampChanged((int)railHandle + 0x28);
  return (RAIL_Status_t)RVar1;
}



RAIL_Status_t_enum RFHAL_SetTxPower(RAIL_Handle_t railHandle,RAIL_TxPower_t power)

{
  uint16_t channel;
  int in_r2;
  
  if (*(char *)((int)railHandle + 0x60) != '\x03') {
    if (in_r2 == 0) {
      PA_SetPowerLevel((uint8_t)power);
    }
    else {
      *(uint8_t *)((int)railHandle + 4) = (uint8_t)power;
      channel = RAILInt_GetChannel(railHandle);
      RAILInt_SetChannel(railHandle,channel);
    }
    return RAIL_STATUS_NO_ERROR;
  }
  return RAIL_STATUS_INVALID_STATE;
}



RAIL_Status_t_enum RFHAL_GetTxPowerConfig(RAIL_Handle_t railHandle,RAIL_TxPowerConfig_t *config)

{
  PA_GetTxPowerConfig(config);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_TxPowerLevel_t RFHAL_GetTxPower(RAIL_Handle_t railHandle)

{
  return currentPowerLevel;
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



undefined4 RFHAL_SetChannel(int param_1,int param_2,int param_3,int param_4)

{
  RAIL_RadioState_t_enum RVar1;
  RAIL_Status_t_enum RVar2;
  uint32_t uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint32_t freq;
  
  if (*(int *)(param_1 + 0x10) != 1) {
    RVar1 = RAILCore_GetRadioState();
    if (RVar1 != RAIL_RF_STATE_ACTIVE) {
      RAILCore_Idle(RAIL_IDLE_ABORT,true);
    }
    if (*(code **)(param_1 + 0x1c) != FUN_00000000) {
      (**(code **)(param_1 + 0x1c))(param_1,param_2);
    }
    freq = *(uint32_t *)(param_3 + 4);
    uVar6 = param_2 - (uint)*(ushort *)(param_3 + 0xc);
    uVar7 = uVar6 & 0xffff;
    if (0x3f < uVar7) {
      freq = (uVar7 >> 6) * *(int *)(param_3 + 8) * 0x40 + freq;
      uVar7 = uVar6 & 0x3f;
    }
    uVar3 = SYNTH_RfFreqGet();
    if (((uVar3 != freq) || (iVar4 = SYNTH_ChSpacingGet(), iVar4 != *(int *)(param_3 + 8))) ||
       (param_4 != 0)) {
      RVar2 = SYNTH_Config(freq,*(uint32_t *)(param_3 + 8));
      if (RVar2 != RAIL_STATUS_NO_ERROR) {
        return 2;
      }
      iVar4 = SYNTH_Is2p4GHz();
      if (iVar4 == 0) {
        uVar5 = 3500000;
      }
      else {
        uVar5 = 7000000;
      }
      SYNTH_DCDCRetimeClkSet(uVar5);
    }
    RFHAL_NotifyUserOfIrCal(param_1);
    GENERIC_PHY_ChannelSet(uVar7 & 0xff);
  }
  return 0;
}



bool RFHAL_EnableAutoAck(RAIL_Handle_t railHandle,bool enable)

{
  CORE_irqState_t irqState;
  uint uVar1;
  
  irqState = CORE_EnterCritical();
  uVar1 = read_volatile_4(Peripherals::SEQ.REG014);
  if (enable == false) {
    uVar1 = uVar1 & 0xffffffdf;
  }
  else {
    uVar1 = uVar1 | 0x20;
  }
  write_volatile_4(Peripherals::SEQ.REG014,uVar1);
  CORE_ExitCritical(irqState);
  return SUB41((uVar1 << 0x1a) >> 0x1f,0);
}



bool RFHAL_IsAutoAckEnabled(RAIL_Handle_t railHandle)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG014);
  return SUB41((uVar1 << 0x1a) >> 0x1f,0);
}



RAIL_Status_t_enum RFHAL_SetAutoAckTimeout(RAIL_Handle_t railHandle,uint32_t timeout)

{
  uint64_t uVar1;
  
  uVar1 = PROTIMER_UsToPrecntOverflow(timeout);
  write_volatile_4(Peripherals::SEQ.REG020,-(int)uVar1);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RFHAL_WriteAutoAckFifo(RAIL_Handle_t railHandle,uint8_t *ackData,uint8_t ackDataLen)

{
  RAIL_Status_t RVar1;
  CORE_irqState_t irqState;
  uint uVar2;
  
  irqState = CORE_EnterCritical();
  write_volatile_4(Peripherals::RAC_SET.SR0,2);
  uVar2 = read_volatile_4(Peripherals::RAC.STATUS);
  uVar2 = (uVar2 << 4) >> 0x1c;
  if (((uVar2 - 7 < 3) || (uVar2 == 0xc)) &&
     (uVar2 = read_volatile_4(Peripherals::RAC.SR0), (int)(uVar2 << 0xe) < 0)) {
    RVar1 = '\x03';
  }
  else {
    RVar1 = BUFC_TxAckBufferSet(ackData,ackDataLen);
  }
  write_volatile_4(Peripherals::RAC_CLR.SR0,2);
  CORE_ExitCritical(irqState);
  return RVar1;
}



void RFHAL_PauseRxAutoAck(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 8;
  }
  GENERIC_PHY_SetFeatures(param_1,8,uVar1);
  return;
}



void RFHAL_PauseTxAutoAck(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x100;
  }
  GENERIC_PHY_SetFeatures(param_1,0x100,uVar1);
  return;
}



bool RFHAL_IsRxAutoAckPaused(RAIL_Handle_t railHandle)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG014);
  return SUB41((uVar1 << 0x1c) >> 0x1f,0);
}



bool RFHAL_IsTxAutoAckPaused(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG014);
  return SUB41((uVar1 << 0x17) >> 0x1f,0);
}



RAIL_Status_t_enum RFHAL_UseTxFifoForAutoAck(RAIL_Handle_t railHandle)

{
  uint uVar1;
  uint uVar2;
  CORE_irqState_t irqState;
  int iVar3;
  RAIL_Status_t_enum RVar4;
  
  irqState = CORE_EnterCritical();
  iVar3 = GENERIC_PHY_CanModifyAck();
  RVar4 = RAIL_STATUS_INVALID_STATE;
  if (iVar3 != 0) {
    write_volatile_4(Peripherals::RAC_SET.SR0,2);
    uVar2 = read_volatile_4(Peripherals::RAC.SR0);
    uVar1 = 2;
    if ((uVar2 & 0x20000) == 0) {
      write_volatile_4(Peripherals::RAC_SET.SR2,0x40);
      uVar1 = uVar2 & 0x20000;
    }
    RVar4 = (RAIL_Status_t_enum)uVar1;
    write_volatile_4(Peripherals::RAC_CLR.SR0,2);
  }
  CORE_ExitCritical(irqState);
  return RVar4;
}



RAIL_Status_t RFHAL_CancelAutoAck(RAIL_Handle_t railHandle)

{
  uint uVar1;
  uint uVar2;
  CORE_irqState_t irqState;
  int iVar3;
  RAIL_Status_t RVar4;
  
  irqState = CORE_EnterCritical();
  iVar3 = GENERIC_PHY_CanModifyAck();
  RVar4 = '\x02';
  if (iVar3 != 0) {
    write_volatile_4(Peripherals::RAC_SET.SR0,2);
    uVar2 = read_volatile_4(Peripherals::RAC.SR0);
    uVar1 = 2;
    if ((uVar2 & 0x20000) == 0) {
      write_volatile_4(Peripherals::RAC_SET.SR2,0x20);
      uVar1 = uVar2 & 0x20000;
    }
    RVar4 = (RAIL_Status_t)uVar1;
    write_volatile_4(Peripherals::RAC_CLR.SR0,2);
  }
  CORE_ExitCritical(irqState);
  return RVar4;
}



void RFHAL_AutoAckWaitForAck(int param_1)

{
  RAC_SET *pRVar1;
  
  if (param_1 == 0) {
    pRVar1 = &Peripherals::RAC_SET;
  }
  else {
    pRVar1 = (RAC_SET *)&Peripherals::RAC_CLR;
  }
  ((RAC_CLR *)pRVar1)->SR0 = 0x100;
  return;
}



uint preTxOps(undefined4 param_1,uint param_2)

{
  FRC_SET *pFVar1;
  MODEM_SET *pMVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = param_2 << 0x1e;
  if ((int)((uint)fcds << 0x1f) < 0) {
    if (iVar5 < 0) {
      pFVar1 = (FRC_SET *)&Peripherals::FRC_CLR;
    }
    else {
      pFVar1 = &Peripherals::FRC_SET;
    }
    ((FRC_CLR *)pFVar1)->FCD0 = 0x400;
  }
  if ((int)((uint)fcds << 0x1e) < 0) {
    if (iVar5 < 0) {
      pFVar1 = (FRC_SET *)&Peripherals::FRC_CLR;
    }
    else {
      pFVar1 = &Peripherals::FRC_SET;
    }
    ((FRC_CLR *)pFVar1)->FCD0 = 0x800;
  }
  if ((int)((uint)fcds << 0x1d) < 0) {
    if (iVar5 < 0) {
      pFVar1 = (FRC_SET *)&Peripherals::FRC_CLR;
    }
    else {
      pFVar1 = &Peripherals::FRC_SET;
    }
    ((FRC_CLR *)pFVar1)->FCD1 = 0x400;
  }
  if ((int)((uint)fcds << 0x1c) < 0) {
    if (iVar5 < 0) {
      pFVar1 = (FRC_SET *)&Peripherals::FRC_CLR;
    }
    else {
      pFVar1 = &Peripherals::FRC_SET;
    }
    ((FRC_CLR *)pFVar1)->FCD1 = 0x800;
  }
  if ((param_2 & 4) == 0) {
    pMVar2 = (MODEM_SET *)&Peripherals::MODEM_CLR;
  }
  else {
    pMVar2 = &Peripherals::MODEM_SET;
  }
  ((MODEM_CLR *)pMVar2)->CTRL1 = 0x400;
  uVar4 = read_volatile_4(Peripherals::SEQ.REG014);
  if ((int)(uVar4 << 0x1a) < 0) {
    RFHAL_AutoAckWaitForAck(param_2 & 1);
  }
  bVar3 = GENERIC_PHY_IsEnabledIEEE802154();
  uVar4 = (uint)bVar3;
  if (uVar4 != 0) {
    uVar4 = read_volatile_4(Peripherals::SEQ.REG014);
    uVar4 = uVar4 & 0x20;
    if (uVar4 != 0) {
      uVar4 = BUFC_PeekByte(0,3);
      if (uVar4 != 0xffffffff) {
        write_volatile_4(Peripherals::SEQ.REG01C,uVar4);
        return 0;
      }
      uVar4 = 3;
    }
  }
  return uVar4;
}



int RFHAL_StartTx(void)

{
  int iVar1;
  
  iVar1 = preTxOps();
  if (iVar1 == 0) {
    GENERIC_PHY_PacketTx();
  }
  return iVar1;
}



// WARNING: Could not reconcile some variable overlaps

void RFHAL_StartScheduledTx(int param_1,undefined4 param_2,uint *param_3)

{
  int local_18;
  uint local_14;
  
  local_18 = param_1;
  local_14 = param_2;
  local_18 = preTxOps();
  if (local_18 == 0) {
    local_14 = param_3[1];
    if (((char)local_14 != '\x01') || ((uint)*(ushort *)(param_1 + 0x3e) <= *param_3)) {
      local_18 = *param_3 - (uint)*(ushort *)(param_1 + 0x3e);
    }
    GENERIC_PHY_SchedulePacketTx(&local_18);
  }
  return;
}



RAIL_Status_t_enum
RFHAL_StartCcaCsmaTx
          (RAIL_Handle_t railHandle,uint16_t channel,RAIL_TxOptions_t options,
          RAIL_CsmaConfig_t *csmaConfig,undefined *schedulerInfo)

{
  byte bVar1;
  uint32_t us;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte bVar6;
  uint uVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  uint uVar11;
  PROTIMER *pPVar12;
  uint uVar13;
  uint64_t uVar14;
  
  uVar4 = (uint)channel;
  iVar3 = preTxOps();
  if (iVar3 == 0) {
    saveRssiPeriodPreCca = read_volatile_4(Peripherals::AGC.CTRL1);
    if (options == 0) {
      setRssiPeriod(saveRssiPeriodInCca);
      PROTIMER_LBTUseLastConfig();
    }
    else {
      RADIO_SetAgcCcaParams
                (*(undefined2 *)(options + 6),(int)*(char *)(options + 3),saveRssiPeriodPreCca,
                 &saveRssiPeriodPreCca,railHandle,uVar4);
      saveRssiPeriodInCca = read_volatile_4(Peripherals::AGC.CTRL1);
      bVar10 = *(byte *)(options + 2);
      bVar1 = *(byte *)options;
      bVar9 = *(byte *)(options + 1);
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
      uVar7 = count_leading_zeroes((uint)*(ushort *)options);
      pPVar12 = (PROTIMER *)0xa38b;
      uVar14 = PROTIMER_UsToPrecntOverflow((uint)*(ushort *)(options + 4));
      uVar4 = (uint)(ushort)uVar14;
      if (uVar7 >> 5 == 0) {
        uVar13 = (uint)reseedRandom_9523;
        if (uVar13 != 0xf804) {
          pPVar12 = &Peripherals::PROTIMER;
        }
        if (uVar13 != 0xf804) {
          pPVar12->RANDOM = uVar13;
          reseedRandom_9523 = 0xf804;
        }
      }
      else {
        uVar5 = 0;
        uVar13 = uVar4;
        while( true ) {
          uVar11 = uVar5 & 0xff;
          uVar5 = uVar5 + 1;
          if (uVar13 < 0x100) break;
          uVar13 = uVar13 >> 1;
        }
        if ((uVar11 != 0) && (uVar13 != 0xff)) {
          uVar13 = (uint)(ushort)(((ushort)((int)uVar4 >> (uVar11 - 1 & 0xff)) & 1) + (short)uVar13)
          ;
        }
        uVar4 = uVar13;
        uVar13 = read_volatile_4(Peripherals::PROTIMER.RANDOM);
        reseedRandom_9523 = (ushort)(uVar13 & 0xffff);
        if ((uVar13 & 0xffff) == 0xf804) {
          reseedRandom_9523 = 0xf805;
        }
        bVar9 = 8;
        write_volatile_4(Peripherals::PROTIMER.RANDOM,(1 << uVar11) - 1);
        write_volatile_4(Peripherals::PROTIMER.LBTSTATE,0x800000);
        bVar10 = 8;
      }
      uVar4 = uVar4 - 1;
      if (0xfe < uVar4) {
        uVar4 = 0xff;
      }
      write_volatile_4(Peripherals::PROTIMER.BASECNTTOP,uVar4);
      iVar3 = RAILInt_GetActiveConfig();
      PROTIMER_LBTCfgSet(iVar3 + 0x34,bVar10,bVar9,bVar8,bVar6,0);
      if (uVar7 >> 5 != 0) {
        write_volatile_4(Peripherals::PROTIMER_SET.LBTCTRL,0x100000);
        uVar4 = read_volatile_4(Peripherals::PROTIMER.CTRL);
        write_volatile_4(Peripherals::PROTIMER.CTRL,uVar4 & 0xff3fffff | 0x400000);
      }
      lbtTimeout_9522 = *(uint32_t *)(options + 8);
    }
    GENERIC_PHY_PacketTxCommon();
    us = lbtTimeout_9522;
    if (lbtTimeout_9522 != 0) {
      bVar2 = PROTIMER_CCTimerIsEnabled('\x04');
      if (bVar2 != false) {
        PROTIMER_CCTimerStop(4);
      }
      uVar14 = PROTIMER_UsToPrecntOverflow(us);
      iVar3 = PROTIMER_CCTimerStart(4,(int)uVar14,1);
      if (iVar3 == 0) {
        iVar3 = 1;
        goto LAB_0000a494;
      }
    }
    PROTIMER_LBTStart();
    iVar3 = 0;
  }
LAB_0000a494:
  return (RAIL_Status_t_enum)iVar3;
}



// WARNING: Could not reconcile some variable overlaps

RAIL_Status_t_enum
RFHAL_StartCcaLbtTx(RAIL_Handle_t param_1,uint param_2,RAIL_CsmaConfig_t *param_3,uint32_t param_4)

{
  ushort *puVar1;
  RAIL_Status_t_enum RVar2;
  uint uVar3;
  byte bVar4;
  RAIL_CsmaConfig_t *csmaConfig;
  undefined4 local_1c;
  undefined4 local_18;
  uint32_t uStack20;
  
  csmaConfig = param_3;
  local_1c = param_2;
  local_18 = param_3;
  uStack20 = param_4;
  if ((param_3 != (RAIL_CsmaConfig_t *)0x0) && (*(short *)param_3 != 0)) {
    local_1c = *(uint *)param_3;
    local_18._2_2_ = (ushort)((uint)*(undefined4 *)&param_3->ccaBackoff >> 0x10);
    uStack20 = param_3->csmaTimeout;
    bVar4 = param_3->csmaMinBoExp;
    if (bVar4 != 0) {
      local_18._2_2_ = param_3->ccaBackoff * (ushort)bVar4 + local_18._2_2_;
      local_1c._1_1_ = (uint8_t)(local_1c >> 8);
      local_1c._2_2_ = (undefined2)(local_1c >> 0x10);
      local_1c = (uint)CONCAT21(local_1c._2_2_,local_1c._1_1_ - bVar4) << 8;
    }
    uVar3 = local_1c >> 8 & 0xff;
    for (bVar4 = 1; (uint)(1 << (uint)bVar4) < uVar3; bVar4 = bVar4 + 1) {
    }
    puVar1 = &param_3->ccaBackoff;
    local_18 = (RAIL_CsmaConfig_t *)
               (uVar3 * (int)(RAIL_CsmaConfig_t *)(uint)*puVar1 + ((uint)(1 << (uint)bVar4) >> 1) >>
                (uint)bVar4 & 0xffff | (uint)local_18._2_2_ << 0x10);
    local_1c._0_2_ = CONCAT11(bVar4,bVar4);
    local_1c = local_1c & 0xffff0000 | (uint)(ushort)local_1c;
    param_3 = (RAIL_CsmaConfig_t *)&local_1c;
    csmaConfig = (RAIL_CsmaConfig_t *)(uint)*puVar1;
  }
  RVar2 = RFHAL_StartCcaCsmaTx
                    (param_1,(uint16_t)param_2,(RAIL_TxOptions_t)param_3,csmaConfig,
                     (undefined *)param_1);
  return RVar2;
}



uint16_t RFHAL_ReadRxFifo(RAIL_Handle_t railHandle,uint8_t *dataPtr,uint16_t readLength)

{
  uint uVar1;
  uint uVar2;
  undefined auStack32 [2];
  ushort local_1e;
  
  uVar1 = BUFC_GetRxPacketInfo(1,auStack32,0);
  uVar2 = uVar1;
  if (uVar1 != 0) {
    uVar2 = (uint)readLength;
    if ((uint)local_1e <= (uint)readLength) {
      uVar2 = (uint)local_1e;
    }
    if (uVar1 == cachedPacketHandle) {
      cachedPacketHandle = 0;
    }
    BUFC_ReadBuffer(1,dataPtr,uVar2);
  }
  return (uint16_t)uVar2;
}



// WARNING: Could not reconcile some variable overlaps

RAIL_RxPacketHandle_t
RFHAL_GetRxPacketInfo(RAIL_RxPacketHandle_t packetHandle,RAIL_RxPacketInfo_t *pPacketInfo)

{
  RAIL_RxPacketHandle_t pvVar1;
  CORE_irqState_t irqState;
  undefined4 in_r3;
  undefined4 uStack20;
  
  uStack20 = pPacketInfo;
  pvVar1 = (RAIL_RxPacketHandle_t)
           BUFC_GetRxPacketInfo(packetHandle,pPacketInfo,(int)&uStack20 + 2,in_r3,packetHandle);
  if (pvVar1 != (RAIL_RxPacketHandle_t)0x0) {
    irqState = CORE_EnterCritical();
    cachedPacketStartOffset = uStack20._2_2_;
    cachedPacketBytes = pPacketInfo->packetBytes;
    cachedPacketHandle = pvVar1;
    CORE_ExitCritical(irqState);
  }
  return pvVar1;
}



// WARNING: Could not reconcile some variable overlaps

RAIL_Status_t_enum
RFHAL_GetRxPacketDetails(RAIL_RxPacketHandle_t packetHandle,RAIL_RxPacketDetails_t *pPacketDetails)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  RAIL_Status_t_enum RVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 local_18;
  RAIL_RxPacketDetails_t *local_14;
  
  if (((packetHandle == (RAIL_RxPacketHandle_t)0x0) ||
      (pPacketDetails == (RAIL_RxPacketDetails_t *)0x0)) ||
     ((local_18 = packetHandle, local_14 = pPacketDetails, packetHandle < FUN_00000000 + 3 &&
      (packetHandle = (RAIL_RxPacketHandle_t)BUFC_GetRxPacketInfo(packetHandle,0,0),
      (short *)packetHandle == (short *)0x0)))) {
    RVar4 = RAIL_STATUS_INVALID_PARAMETER;
  }
  else {
                    // WARNING: Load size is inaccurate
    sVar1 = *packetHandle;
    uVar7 = (uint)*(byte *)((int)packetHandle + 2);
    if ((sVar1 < 0) || ((uVar7 & 7) < 6)) {
      RVar4 = RAIL_STATUS_INVALID_STATE;
    }
    else {
      pPacketDetails->isAck = SUB41((uVar7 << 0x1b) >> 0x1f,0);
      pPacketDetails->subPhyId = (byte)((uVar7 << 0x1a) >> 0x1f);
      pPacketDetails->crcPassed = (_Bool)((uVar7 & 7) == 7);
      pPacketDetails->syncWordId = (byte)((uVar7 << 0x19) >> 0x1f);
      cVar5 = RADIO_RxTrailDataLength();
      if (cVar5 == '\0') {
        pPacketDetails->lqi = '\0';
        pPacketDetails->rssi = -0x80;
        (pPacketDetails->timeReceived).packetTime = 0;
        (pPacketDetails->timeReceived).timePosition = '\0';
      }
      else {
        if ((pPacketDetails->timeReceived).timePosition == '\0') {
          cVar5 = '\x02';
        }
        BUFC_Peek(1,&local_18,cVar5,sVar1 + -6);
        pPacketDetails->lqi = local_18._1_1_ << 1;
        pPacketDetails->rssi = (int8_t)local_18;
        if ((pPacketDetails->timeReceived).timePosition != '\0') {
          uVar8 = (uint)local_14 & 0xff;
          uVar7 = (uint)local_18 >> 0x18;
          uVar2 = (uint)local_18 >> 0x10;
          uVar3 = (uint)local_14 >> 8;
          iVar6 = RAILInt_GetActiveConfig();
          TIMING_CalcRxTimeStampUs
                    (iVar6 + 0x34,uVar2 & 0xff | uVar8 << 0x10 | uVar7 << 8 | uVar3 << 0x18,
                     pPacketDetails);
        }
      }
      RVar4 = RAIL_STATUS_NO_ERROR;
    }
  }
  return RVar4;
}



uint RFHAL_HoldRxPacket(void)

{
  uint uVar1;
  
  uVar1 = callbackRxLenEntry;
  if (callbackRxLenEntry != 0) {
    uVar1 = callbackRxLenEntry & 0xfffffffe;
    callbackRxLenEntry = callbackRxLenEntry | 1;
  }
  return uVar1;
}



RAIL_Status_t_enum RFHAL_ReleaseRxPacket(RAIL_RxPacketHandle_t packetHandle)

{
  RAIL_Status_t_enum RVar1;
  
  if ((packetHandle == cachedPacketHandle) || (packetHandle < FUN_00000000 + 3)) {
    cachedPacketHandle = (RAIL_RxPacketHandle_t)0x0;
  }
  RVar1 = GENERIC_PHY_ReleaseRxPacket();
  return RVar1;
}



uint16_t RFHAL_SetTxFifoThreshold(RAIL_Handle_t railHandle,uint16_t txThreshold)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = read_volatile_4(Peripherals::BUFC.BUF0_CTRL);
  uVar2 = 1 << (uVar1 & 7) + 6 & 0xffff;
  uVar1 = (uint)txThreshold;
  if (uVar2 <= txThreshold) {
    uVar1 = uVar2;
  }
  uVar2 = read_volatile_4(Peripherals::BUFC.BUF0_THRESHOLDCTRL);
  write_volatile_4(Peripherals::BUFC.BUF0_THRESHOLDCTRL,uVar2 & 0xfffff000 | uVar1 - 1 & 0xffff);
  *(uint16_t *)((int)railHandle + 0x6c) = (uint16_t)uVar1;
  return (uint16_t)uVar1;
}



uint16_t RFHAL_SetRxFifoThreshold(RAIL_Handle_t railHandle,uint16_t rxThreshold)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)rxThreshold;
  uVar1 = read_volatile_4(Peripherals::BUFC.BUF1_THRESHOLDCTRL);
  if (0x1ff < uVar2) {
    uVar2 = 0x200;
  }
  write_volatile_4(Peripherals::BUFC.BUF1_THRESHOLDCTRL,uVar1 & 0xfffff000 | uVar2);
  *(uint16_t *)((int)railHandle + 0x6e) = (uint16_t)uVar2;
  return (uint16_t)uVar2;
}



uint16_t RFHAL_GetTxFifoThreshold(RAIL_Handle_t railHandle)

{
  return *(uint16_t *)((int)railHandle + 0x6c);
}



uint16_t RFHAL_GetRxFifoThreshold(RAIL_Handle_t railHandle)

{
  return *(uint16_t *)((int)railHandle + 0x6e);
}



uint16_t RFHAL_GetTxFifoSpaceAvailable(RAIL_Handle_t railHandle)

{
  uint16_t uVar1;
  
  uVar1 = BUFC_GetSpaceAvailable(0);
  return uVar1;
}



uint16_t RFHAL_GetRxFifoBytesAvailable(RAIL_Handle_t railHandle)

{
  uint16_t uVar1;
  
  uVar1 = BUFC_GetBytesAvailable('\x01');
  return uVar1;
}



uint16_t RFHAL_SetTxBuffer(RAIL_Handle_t railHandle,uint8_t *addr,uint16_t initLength,uint16_t size)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = count_leading_zeroes((uint)size);
  uVar3 = 0x19 - iVar2;
  if ((iVar2 == 0x19) || (0 < (int)uVar3)) {
    if (5 < (int)uVar3) {
      uVar3 = 6;
    }
    uVar3 = uVar3 & 0xff;
  }
  else {
    uVar3 = 0;
  }
  uVar4 = 1 << (uVar3 + 6 & 0xff) & 0xffff;
  uVar1 = (uint)initLength;
  if (uVar4 <= initLength) {
    uVar1 = uVar4;
  }
  BUFC_SetTxBuffer(addr,uVar1,uVar3);
  return (uint16_t)uVar4;
}



void RFHAL_ResetTxFifo(RAIL_Handle_t railHandle)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::BUFC.IEN);
  write_volatile_4(Peripherals::BUFC.BUF0_CMD,1);
  write_volatile_4(Peripherals::BUFC_CLR.BUF0_THRESHOLDCTRL,0x2000);
  if ((int)(uVar1 << 0x1d) < 0) {
    write_volatile_4(Peripherals::BUFC_SET.IEN,4);
  }
  return;
}



uint16_t RFHAL_WriteTxFifo(RAIL_Handle_t railHandle,uint8_t *dataPtr,uint16_t writeLength,bool reset
                          )

{
  uint16_t len;
  
  if (reset != false) {
    RFHAL_ResetTxFifo(railHandle);
  }
  len = BUFC_GetSpaceAvailable(0);
  if (writeLength <= len) {
    len = writeLength;
  }
  BUFC_WriteBuffer('\0',dataPtr,len);
  return len;
}



void RFHAL_ResetRxFifo(RAIL_Handle_t railHandle)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::BUFC.IEN);
  write_volatile_4(Peripherals::BUFC_CLR.IEN,0x400);
  cachedPacketHandle = 0;
  GENERIC_PHY_ResetRxFifo();
  write_volatile_4(Peripherals::BUFC_CLR.BUF1_THRESHOLDCTRL,0x2000);
  if ((int)(uVar1 << 0x15) < 0) {
    write_volatile_4(Peripherals::BUFC_SET.IEN,0x400);
  }
  return;
}



RAIL_Status_t_enum RFHAL_ConfigData(RAIL_Handle_t railHandle,RAIL_DataConfig_t *dataConfig)

{
  if (dataConfig->txMethod != dataConfig->rxMethod) {
    return RAIL_STATUS_INVALID_PARAMETER;
  }
  if (dataConfig->rxSource == '\0') {
    RFHAL_DisableRxRawCapture();
  }
  else {
    RFHAL_EnableRxRawCapture();
  }
  if (dataConfig->txMethod == '\0') {
    write_volatile_4(Peripherals::BUFC.BUF0_THRESHOLDCTRL,0xfff);
  }
  else {
    RFHAL_ResetTxFifo(railHandle);
  }
  if (dataConfig->rxMethod == '\0') {
    write_volatile_4(Peripherals::BUFC.BUF1_THRESHOLDCTRL,0xfff);
    write_volatile_4(Peripherals::FRC_SET.RXCTRL,0x60);
    write_volatile_4(Peripherals::RAC_CLR.SR0,0x40);
    return RAIL_STATUS_NO_ERROR;
  }
  write_volatile_4(Peripherals::FRC_CLR.RXCTRL,0x60);
  RFHAL_ResetRxFifo(railHandle);
  write_volatile_4(Peripherals::RAC_SET.SR0,0x40);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t_enum RFHAL_Init(int param_1,code *param_2,undefined4 param_3)

{
  CMU_Select_TypeDef CVar1;
  RAIL_Status_t_enum RVar2;
  RAIL_Handle_t railHandle;
  RAIL_DataConfig_t local_1c;
  
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined2 *)(param_1 + 0x44) = 100;
  *(undefined2 *)(param_1 + 0x46) = 100;
  *(undefined2 *)(param_1 + 0x48) = 100;
  *(undefined2 *)(param_1 + 0x4a) = 100;
  *(undefined2 *)(param_1 + 0x4c) = 100;
  *(undefined2 *)(param_1 + 0x4e) = 100;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined2 *)(param_1 + 0x40) = 0;
  *(undefined2 *)(param_1 + 0x42) = 0;
  *(undefined2 *)(param_1 + 0x7c) = 0xffff;
  railHandle = (RAIL_Handle_t)(param_1 + 0xc);
  local_1c = (RAIL_DataConfig_t)0x0;
  CVar1 = CMU_ClockSelectGet(cmuClock_HF);
  if (CVar1 == cmuSelect_HFXO) {
    GENERIC_PHY_Init(railHandle);
    write_volatile_4(Peripherals::FRC.RXCTRL,0x60);
    RVar2 = RFHAL_ConfigData(railHandle,&local_1c);
    RFHAL_ConfigRxOptions(railHandle,0xffffffff,*(RAIL_RxOptions_t *)(param_1 + 0x90));
    GENERIC_PHY_ConfigureEvents(0xc000000,2,0xc000000,2,0,0,param_3);
  }
  else {
    RVar2 = RAIL_STATUS_INVALID_STATE;
  }
  if (param_2 != FUN_00000000) {
    (*param_2)(param_1);
  }
  return RVar2;
}



uint16_t RFHAL_SetFixedLength(RAIL_Handle_t railHandle,uint16_t length)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  bool bVar4;
  
  uVar2 = (uint)length;
  uVar1 = read_volatile_4(Peripherals::FRC.DFLCTRL);
  if (((uVar1 & 7) == 0) || ((uVar1 & 7) == 5)) {
    uVar3 = *(ushort *)((int)railHandle + 0x70);
    if (uVar2 == 0) {
      bVar4 = uVar3 == 0xffff;
      if (bVar4) {
        uVar1 = read_volatile_4(Peripherals::FRC.WCNTCMP0);
        uVar3 = (ushort)uVar1 & 0xfff;
      }
      if (bVar4) {
        *(ushort *)((int)railHandle + 0x72) = uVar3;
      }
      *(undefined2 *)((int)railHandle + 0x70) = 0;
      uVar1 = read_volatile_4(Peripherals::FRC.DFLCTRL);
      write_volatile_4(Peripherals::FRC.DFLCTRL,uVar1 & 0xfffffff8 | 5);
    }
    else {
      if (uVar2 == 0xffff) {
        if (uVar3 != 0xffff) {
          write_volatile_4(Peripherals::FRC_CLR.DFLCTRL,7);
          uVar1 = read_volatile_4(Peripherals::FRC.WCNTCMP0);
          uVar2 = (uint)*(ushort *)((int)railHandle + 0x72);
          write_volatile_4(Peripherals::FRC.WCNTCMP0,uVar1 & 0xfffff000 | uVar2);
          *(undefined2 *)((int)railHandle + 0x70) = 0xffff;
        }
      }
      else {
        bVar4 = uVar3 == 0xffff;
        if (bVar4) {
          uVar1 = read_volatile_4(Peripherals::FRC.WCNTCMP0);
          uVar3 = (ushort)uVar1;
        }
        *(uint16_t *)((int)railHandle + 0x70) = length;
        if (bVar4) {
          uVar3 = uVar3 & 0xfff;
        }
        if (bVar4) {
          *(ushort *)((int)railHandle + 0x72) = uVar3;
        }
        write_volatile_4(Peripherals::FRC_CLR.DFLCTRL,7);
        if (0xfff < uVar2) {
          uVar2 = 0x1000;
        }
        write_volatile_4(Peripherals::FRC.WCNTCMP0,uVar2 - 1);
      }
    }
  }
  else {
    uVar2 = 0xffff;
  }
  return (uint16_t)uVar2;
}



void RFHAL_SetAbortScheduledTxDuringRx(int param_1)

{
  RAC_SET *pRVar1;
  
  if (param_1 == 0) {
    pRVar1 = (RAC_SET *)&Peripherals::RAC_CLR;
  }
  else {
    pRVar1 = &Peripherals::RAC_SET;
  }
  ((RAC_CLR *)pRVar1)->SR0 = 8;
  return;
}



int RFHAL_ConfigRadio(byte *param_1)

{
  ushort *puVar1;
  uint uVar2;
  uint **ppuVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint **ppuVar9;
  uint **ppuVar10;
  byte *railHandle;
  uint **ppuVar11;
  uint **ppuVar12;
  
  uVar4 = read_volatile_4(Peripherals::FRC.FCD0);
  uVar2 = read_volatile_4(Peripherals::SEQ.PHYINFO);
  uVar6 = read_volatile_4(Peripherals::FRC.FCD1);
  railHandle = param_1 + 0x28;
  RADIO_Config(railHandle);
  uVar5 = read_volatile_4(Peripherals::FRC.FCD0);
  ppuVar3 = (uint **)read_volatile_4(Peripherals::SEQ.PHYINFO);
  uVar7 = read_volatile_4(Peripherals::FRC.FCD1);
  if (uVar5 != uVar4) {
    fcds = fcds & 0xfc | (byte)((uVar5 << 0x15) >> 0x1f) | (byte)(((uVar5 << 0x14) >> 0x1f) << 1);
  }
  if (uVar7 != uVar6) {
    fcds = fcds & 0xf3 | (byte)(((uVar7 << 0x15) >> 0x1f) << 2) |
           (byte)(((uVar7 << 0x14) >> 0x1f) << 3);
  }
  if (*(uint16_t *)(param_1 + 0x70) != 0xffff) {
    RFHAL_SetFixedLength(param_1,*(uint16_t *)(param_1 + 0x70));
  }
  if (ppuVar3 != (uint **)uVar2) {
    ppuVar9 = ppuVar3;
    if ((ppuVar3 != (uint **)0x0) && (ppuVar9 = (uint **)*ppuVar3, *ppuVar3 != (uint *)0x0)) {
      ppuVar9 = (uint **)ppuVar3[2];
    }
    GENERIC_PHY_ConfigureFrameType(param_1,ppuVar9);
    ppuVar9 = ppuVar3;
    ppuVar10 = ppuVar3;
    ppuVar11 = ppuVar3;
    ppuVar12 = ppuVar3;
    if (((ppuVar3 != (uint **)0x0) &&
        (ppuVar9 = (uint **)*ppuVar3, ppuVar10 = ppuVar9, ppuVar11 = ppuVar9, ppuVar12 = ppuVar9,
        ppuVar9 != (uint **)0x0)) &&
       (ppuVar9 = (uint **)ppuVar3[4], ppuVar10 = ppuVar9, ppuVar11 = ppuVar9, ppuVar12 = ppuVar9,
       ppuVar9 != (uint **)0x0)) {
      ppuVar3 = ppuVar9 + 2;
      ppuVar12 = (uint **)*ppuVar9;
      puVar1 = (ushort *)((int)ppuVar9 + 0xe);
      ppuVar9 = (uint **)ppuVar9[1];
      ppuVar10 = (uint **)(uint)*puVar1;
      ppuVar11 = (uint **)*ppuVar3;
    }
    iVar8 = TIMING_SetRxDoneDelay(railHandle,ppuVar9);
    if (iVar8 != 0) {
      return iVar8;
    }
    iVar8 = TIMING_SetChainDelays(railHandle,ppuVar12,ppuVar11);
    if (iVar8 != 0) {
      return iVar8;
    }
    TIMING_TxToRxSearchTimeSet(railHandle,(uint16_t)ppuVar10);
    TIMING_RecalculateAll(railHandle);
  }
  *param_1 = *param_1 | 2;
  return 0;
}



void RFHAL_EnableDirectMode(bool enable)

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
  GENERIC_PHY_ConfigDirectMode(&local_18);
  return;
}



RAIL_Status_t_enum RFHAL_OverrideDebugFrequency(uint32_t freq)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = SYNTH_Config(freq,0);
  if (RVar1 == RAIL_STATUS_NO_ERROR) {
    RVar1 = RAIL_STATUS_NO_ERROR;
  }
  else {
    RVar1 = RAIL_STATUS_INVALID_STATE;
  }
  return RVar1;
}



int16_t RFHAL_GetRssi(RAIL_Handle_t railHandle,bool wait)

{
  int16_t iVar1;
  
  iVar1 = RADIO_GetRssi(wait);
  return iVar1;
}



RAIL_Status_t_enum RFHAL_SetTune(RAIL_Handle_t railHandle,uint32_t tune)

{
  RAIL_RadioState_t_enum RVar1;
  
  RVar1 = RFHAL_GetRadioState();
  if (RVar1 == RAIL_RF_STATE_ACTIVE) {
    CMU_ClockSelectSet(cmuClock_HF,cmuSelect_HFRCO);
    CMU_OscillatorEnable(cmuOsc_HFXO,false,false);
    write_volatile_4(Peripherals::CMU_CLR.HFXOSTEADYSTATECTRL,0xff800);
    write_volatile_4(Peripherals::CMU_SET.HFXOSTEADYSTATECTRL,(tune & 0x1ff) << 0xb);
    CMU_OscillatorEnable(cmuOsc_HFXO,true,true);
    CMU_ClockSelectSet(cmuClock_HF,cmuSelect_HFXO);
    return RAIL_STATUS_NO_ERROR;
  }
  return RAIL_STATUS_INVALID_STATE;
}



uint32_t RFHAL_GetTune(RAIL_Handle_t railHandle)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::CMU.HFXOSTEADYSTATECTRL);
  return (uVar1 << 0xc) >> 0x17;
}



uint32_t RFHAL_GetTime(void)

{
  uint32_t cnt;
  uint64_t uVar1;
  
  cnt = PROTIMER_GetTime();
  uVar1 = PROTIMER_PrecntOverflowToUs(cnt);
  return (uint32_t)uVar1;
}



RAIL_Status_t_enum RFHAL_SetTime(uint32_t time)

{
  bool bVar1;
  RAIL_Status_t_enum RVar2;
  
  bVar1 = PROTIMER_SetTime(time);
  if (bVar1 == false) {
    RVar2 = RAIL_STATUS_INVALID_STATE;
  }
  else {
    RVar2 = RAIL_STATUS_NO_ERROR;
  }
  return RVar2;
}



RAIL_Status_t_enum RFHAL_ConfigAddressFilter(RAIL_Handle_t railHandle,RAIL_AddrConfig_t *addrConfig)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = GENERIC_PHY_ConfigureAddressFiltering(railHandle,addrConfig,true);
  return RVar1;
}



bool RFHAL_EnableAddressFilter(RAIL_Handle_t railHandle,bool enable)

{
  int iVar1;
  
  iVar1 = GENERIC_PHY_SetFeatures();
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return SUB41(iVar1,0);
}



bool RFHAL_AddressFilterIsEnabled(RAIL_Handle_t railHandle)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG014);
  return SUB41((uVar1 << 0x1b) >> 0x1f,0);
}



void RFHAL_SetAddressFilterAddress(void)

{
  GENERIC_PHY_SetAddress();
  return;
}



RAIL_Status_t_enum
RFHAL_EnableAddressFilterAddress(RAIL_Handle_t railHandle,bool enable,uint8_t field,uint8_t index)

{
  RAIL_Status_t_enum RVar1;
  
  RVar1 = GENERIC_PHY_EnableAddress(railHandle,(bool)field,index,enable);
  return RVar1;
}



uint16_t RFHAL_GetRadioEntropy(uint8_t *buffer,uint16_t bytes)

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
  uVar4 = read_volatile_4(Peripherals::CMU.HFRADIOCLKEN0);
  uStack36 = __n;
  memset(buffer,0,__n);
  if ((((uVar4 | 0xcc) == uVar4) &&
      (uVar4 = read_volatile_4(Peripherals::RAC.CTRL), -1 < (int)(uVar4 << 0x1f))) &&
     (uVar4 = RADIOCMU_ClockPrescGet(0x75160), uVar4 == 0)) {
    irqState = CORE_EnterCritical();
    uVar3 = read_volatile_4(Peripherals::MODEM.CTRL0);
    uVar2 = read_volatile_4(Peripherals::FRC.RAWCTRL);
    write_volatile_4(Peripherals::MODEM_CLR.CTRL0,0x38000000);
    write_volatile_4(Peripherals::MODEM_SET.CTRL0,0x8000000);
    write_volatile_4(Peripherals::FRC.RAWCTRL,0x24);
    write_volatile_4(Peripherals::RAC_SET.RXENSRCEN,4);
    write_volatile_4(Peripherals::FRC.IFC,0x4000);
    write_volatile_4(Peripherals::FRC.CMD,0x1000);
    for (; uVar4 < __n; uVar4 = uVar4 + __n_00 & 0xffff) {
      do {
        do {
          uVar1 = read_volatile_4(Peripherals::FRC.IF);
        } while (-1 < (int)(uVar1 << 0x11));
        uVar1 = read_volatile_4(Peripherals::FRC.STATUS);
      } while (-1 < (int)(uVar1 << 0x17));
      __n_00 = __n - uVar4;
      write_volatile_4(Peripherals::FRC.IFC,0x4000);
      if (3 < (int)__n_00) {
        __n_00 = 4;
      }
      uStack36 = read_volatile_4(Peripherals::FRC.RXRAWDATA);
      memcpy(buffer + uVar4,&uStack36,__n_00);
    }
    write_volatile_4(Peripherals::RAC_CLR.RXENSRCEN,4);
    write_volatile_4(Peripherals::FRC.RAWCTRL,uVar2);
    write_volatile_4(Peripherals::MODEM.CTRL0,uVar3);
    write_volatile_4(Peripherals::FRC.IFC,0x4000);
    CORE_ExitCritical(irqState);
  }
  else {
    bytes = 0;
  }
  return bytes;
}



RAIL_Status_t_enum RFHAL_SetStateTiming(RAIL_Handle_t railHandle,RAIL_StateTiming_t *timings)

{
  uint16_t uVar1;
  RAIL_Handle_t railHandle_00;
  
  railHandle_00 = (RAIL_Handle_t)((int)railHandle + 0x28);
  uVar1 = TIMING_RxWarmTimeSet(railHandle_00,timings->idleToRx);
  timings->idleToRx = uVar1;
  uVar1 = TIMING_TxToRxTimeSet(railHandle_00,timings->txToRx);
  timings->txToRx = uVar1;
  uVar1 = TIMING_TxWarmTimeSet(railHandle_00,timings->idleToTx);
  timings->idleToTx = uVar1;
  uVar1 = TIMING_RxFrameToTxTimeSet(railHandle_00,timings->rxToTx);
  timings->rxToTx = uVar1;
  uVar1 = TIMING_RxSearchTimeSet(railHandle_00,timings->rxSearchTimeout);
  timings->rxSearchTimeout = uVar1;
  uVar1 = TIMING_TxToRxSearchTimeSet(railHandle_00,timings->txToRxSearchTimeout);
  timings->txToRxSearchTimeout = uVar1;
  TIMING_RecalculateAll(railHandle_00);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t_enum RFHAL_ConfigPti(RAIL_PtiConfig_t *ptiConfig)

{
  uint uVar1;
  uint32_t uVar2;
  undefined4 *puVar3;
  RAIL_PtiConfig_t *pRVar4;
  
  if (ptiConfig == (RAIL_PtiConfig_t *)0x0) {
    return RAIL_STATUS_INVALID_PARAMETER;
  }
  puVar3 = &ptiState;
  pRVar4 = ptiConfig;
  do {
    uVar2 = pRVar4->baud;
    *puVar3 = *(undefined4 *)pRVar4;
    puVar3[1] = uVar2;
    puVar3 = puVar3 + 2;
    pRVar4 = (RAIL_PtiConfig_t *)&pRVar4->doutLoc;
  } while (pRVar4 != (RAIL_PtiConfig_t *)&ptiConfig->dframePin);
  *puVar3 = *(undefined4 *)pRVar4;
  RADIOCMU_ClockEnable(0x63400,true);
  CMU_ClockEnable(cmuClock_GPIO,true);
  write_volatile_4(Peripherals::FRC.SNIFFCTRL,0xf8);
  write_volatile_4(Peripherals::FRC.ROUTELOC0,
                   (uint)ptiConfig->dframeLoc << 0x10 | (uint)ptiConfig->dclkLoc << 8 |
                   (uint)ptiConfig->doutLoc);
  uVar1 = (uint)ptiConfig->mode;
  if (uVar1 == 1) {
    sniffMode = 2;
    write_volatile_4(Peripherals::FRC.ROUTEPEN,7);
    GPIO_PinModeSet(ptiConfig->dclkPort,(uint)ptiConfig->dclkPin,gpioModePushPull,0);
  }
  else {
    if (uVar1 != 2) {
      if (uVar1 != 3) {
        if (uVar1 != 0) {
          return RAIL_STATUS_INVALID_PARAMETER;
        }
        write_volatile_4(Peripherals::FRC.ROUTEPEN,0);
        sniffMode = uVar1;
        return (RAIL_Status_t_enum)ptiConfig->mode;
      }
      sniffMode = 5;
      write_volatile_4(Peripherals::FRC.ROUTEPEN,1);
      goto LAB_0000cade;
    }
    sniffMode = 1;
    write_volatile_4(Peripherals::FRC.ROUTEPEN,5);
  }
  GPIO_PinModeSet(ptiConfig->dframePort,(uint)ptiConfig->dframePin,gpioModePushPull,0);
LAB_0000cade:
  GPIO_PinModeSet(ptiConfig->doutPort,(uint)ptiConfig->doutPin,gpioModePushPull,1);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t_enum RFHAL_EnablePti(bool enable)

{
  int iVar1;
  uint uVar2;
  
  if (enable == false) {
    write_volatile_4(Peripherals::FRC_CLR.SNIFFCTRL,3);
  }
  else {
    uVar2 = DAT_2000448c;
    if (DAT_2000448c != 0) {
      iVar1 = RADIOCMU_ClockFreqGet(0x63400);
      uVar2 = ((iVar1 + (DAT_2000448c >> 1)) / DAT_2000448c - 1) * 0x100;
    }
    write_volatile_4(Peripherals::FRC_CLR.SNIFFCTRL,0xff03);
    write_volatile_4(Peripherals::FRC_SET.SNIFFCTRL,uVar2 | sniffMode);
  }
  PTI_EnableAppendedInfo(enable);
  return RAIL_STATUS_NO_ERROR;
}



bool RFHAL_IEEE802154IsEnabled(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG014);
  return (bool)((byte)uVar1 >> 7);
}



RAIL_Status_t_enum RFHAL_IEEE802154RadioConfig2p4GHz(RAIL_Handle_t railHandle)

{
  RAILCore_ConfigChannels(railHandle,(RAIL_ChannelConfig_t *)&ieee802154_noncoherent_channelConfig);
  return RAIL_STATUS_NO_ERROR;
}



int RFHAL_IEEE802154SetBroadcastAddresses
              (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_14;
  int local_10;
  int local_c;
  
  local_14 = CONCAT22((short)((uint)param_2 >> 0x10),0xffff);
  local_10 = param_3;
  local_c = param_4;
  iVar1 = GENERIC_PHY_SetIeeePanId(param_1,0,&local_14,0xffff,param_1);
  if ((iVar1 == 0) && (iVar1 = GENERIC_PHY_SetIeeeShortAddress(param_1,0,&local_14), iVar1 == 0)) {
    local_10 = iVar1;
    local_c = iVar1;
    iVar1 = GENERIC_PHY_SetIeeeLongAddress(param_1,0,&local_10);
  }
  return iVar1;
}



RAIL_Status_t_enum RFHAL_IEEE802154SetPanId(RAIL_Handle_t railHandle,uint16_t panId,uint8_t index)

{
  RAIL_Status_t_enum RVar1;
  undefined4 in_r3;
  uint local_c;
  uint uStack8;
  
  uStack8 = (uint)index;
  local_c = (uint)panId;
  RVar1 = GENERIC_PHY_SetIeeePanId(railHandle,uStack8 + 1 & 0xff,&local_c,in_r3,railHandle);
  return RVar1;
}



RAIL_Status_t_enum
RFHAL_IEEE802154SetShortAddress(RAIL_Handle_t railHandle,uint16_t shortAddr,uint8_t index)

{
  RAIL_Status_t_enum RVar1;
  undefined4 in_r3;
  uint local_c;
  uint uStack8;
  
  uStack8 = (uint)index;
  local_c = (uint)shortAddr;
  RVar1 = GENERIC_PHY_SetIeeeShortAddress(railHandle,uStack8 + 1 & 0xff,&local_c,in_r3,railHandle);
  return RVar1;
}



RAIL_Status_t
RFHAL_IEEE802154SetLongAddress(RAIL_Handle_t railHandle,uint8_t *longAddr,uint8_t index)

{
  RAIL_Status_t RVar1;
  
  RVar1 = GENERIC_PHY_SetIeeeLongAddress(railHandle,index + '\x01',longAddr);
  return RVar1;
}



undefined4
RFHAL_IEEE802154SetPromiscuousMode
          (undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x10000;
  }
  GENERIC_PHY_SetFeatures(param_1,0x10000,uVar1,param_4,param_4);
  return 0;
}



undefined4
RFHAL_IEEE802154SetPanCoordinator
          (undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x800000;
  }
  GENERIC_PHY_SetFeatures(param_1,0x800000,uVar1,param_4,param_4);
  return 0;
}



RAIL_Status_t_enum RFHAL_IEEE802154AcceptFrames(RAIL_Handle_t railHandle,uint8_t framesMask)

{
  GENERIC_PHY_SetFeatures(railHandle,0x1e0000,(uint)framesMask << 0x11);
  return RAIL_STATUS_NO_ERROR;
}



undefined4 RFHAL_IEEE802154SetFeatures(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0x8000b0;
  if (param_2 == 0) {
    uVar1 = 0xb0;
  }
  uVar1 = (param_4 & 0xf) << 0x11 | uVar1;
  if (param_3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x10000;
  }
  GENERIC_PHY_SetFeatures(param_1,0x9f01b8,uVar2 | uVar1,uVar1,param_4);
  return 0;
}



RAIL_Status_t_enum RFHAL_IEEE802154SetFramePending(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = GENERIC_PHY_CanModifyAck();
  uVar3 = 2;
  if (iVar2 != 0) {
    write_volatile_4(Peripherals::RAC_SET.SR0,2);
    uVar1 = read_volatile_4(Peripherals::RAC.SR0);
    if ((uVar1 & 0x20000) == 0) {
      write_volatile_4(Peripherals::RAC_SET.SR2,0x10);
      uVar3 = uVar1 & 0x20000;
    }
    write_volatile_4(Peripherals::RAC_CLR.SR0,2);
    return (RAIL_Status_t_enum)uVar3;
  }
  return RAIL_STATUS_INVALID_STATE;
}



RAIL_Status_t RFHAL_IEEE802154LoadAck(RAIL_Handle_t param_1,undefined4 param_2,undefined4 param_3)

{
  RAIL_Status_t RVar1;
  undefined4 local_c;
  undefined4 uStack8;
  
  local_c = CONCAT31((int3)((uint)param_2 >> 8),5);
  uStack8 = param_3;
  RVar1 = RFHAL_WriteAutoAckFifo(param_1,(uint8_t *)&local_c,'\x01');
  return RVar1;
}



RAIL_Status_t_enum RFHAL_ConfigBle2Mbps(RAIL_Handle_t railHandle)

{
  return RAIL_STATUS_INVALID_CALL;
}



RAIL_Status_t_enum RFHAL_ConfigBle2MbpsViterbi(RAIL_Handle_t railHandle)

{
  return RAIL_STATUS_INVALID_CALL;
}



RAIL_Status_t_enum RFHAL_ConfigBle1Mbps(RAIL_Handle_t railHandle)

{
  RAILCore_ConfigChannels(railHandle,(RAIL_ChannelConfig_t *)&ble_1M_channelConfig);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t_enum RFHAL_ConfigBle1MbpsViterbi(RAIL_Handle_t railHandle)

{
  RAILCore_ConfigChannels(railHandle,(RAIL_ChannelConfig_t *)&ble_1M_channelConfig);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t_enum RFHAL_ConfigBleCoded(RAIL_Handle_t railHandle,RAIL_BLE_Coding_t bleCoding)

{
  return RAIL_STATUS_INVALID_CALL;
}



void RFHAL_BleInit(RAIL_Handle_t param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 extraout_r1;
  
  RFHAL_ConfigBle1MbpsViterbi(param_1);
  PTI_EnableSyncword(1,extraout_r1,param_3,param_4);
  return;
}



void RFHAL_BleDeinit(int param_1)

{
  *(undefined4 *)(param_1 + 0x1c) = 0;
  PTI_EnableSyncword(0);
  return;
}



bool RFHAL_IsBleLongRangeEnabled(void)

{
  return false;
}



void RFHAL_BLEPreambleSyncWordSet(int param_1,uint param_2)

{
  uint uVar1;
  
  write_volatile_4(Peripherals::MODEM.SYNC0,param_2);
  uVar1 = read_volatile_4(Peripherals::MODEM.PRE);
  if (param_1 == 0x55) {
    uVar1 = uVar1 & 0xfffffff0 | 1;
  }
  else {
    uVar1 = uVar1 & 0xfffffff0 | 2;
  }
  write_volatile_4(Peripherals::MODEM.PRE,uVar1);
  return;
}



void RFHAL_BLEWhiteningSet(uint param_1,uint param_2,int param_3)

{
  bool bVar1;
  
  write_volatile_4(Peripherals::FRC.WHITEPOLY,param_1);
  write_volatile_4(Peripherals::FRC.WHITEINIT,param_2);
  write_volatile_4(Peripherals::FRC_CLR.FECCTRL,7);
  bVar1 = param_3 == 0;
  if (bVar1) {
    write_volatile_4(Peripherals::FRC_SET.FECCTRL,0);
  }
  else {
    write_volatile_4(Peripherals::FRC_SET.FECCTRL,1);
    param_3 = 0;
  }
  RADIO_FrameDescsConfig(bVar1,param_3,1,1);
  return;
}



void BUFC_ReadHelper(int param_1,void *param_2,size_t param_3,uint param_4,char param_5)

{
  uint uVar1;
  void *pvVar2;
  uint uVar3;
  uint __n;
  void *__src;
  bool bVar4;
  
  uVar3 = 1 << ((&Peripherals::BUFC.BUF0_CTRL)[param_1 * 0xc] & 7) + 6;
  uVar1 = param_4 & uVar3 - 1;
  __n = uVar3 - uVar1;
  __src = (void *)((&Peripherals::BUFC.BUF0_ADDR)[param_1 * 0xc] | 0x20000000);
  pvVar2 = (void *)(uVar1 + (int)__src);
  if (__n < param_3) {
    pvVar2 = memcpy(param_2,pvVar2,__n);
    memcpy((void *)((int)pvVar2 + __n),__src,param_3 - __n);
  }
  else {
    memcpy(param_2,pvVar2,param_3);
  }
  if (param_5 != '\0') {
    uVar3 = (uVar3 | uVar3 - 1) & param_3 + param_4;
    (&Peripherals::BUFC.BUF0_READOFFSET)[param_1 * 0xc] = uVar3;
    uVar1 = (&Peripherals::BUFC.BUF0_WRITEOFFSET)[param_1 * 0xc];
    bVar4 = uVar3 != uVar1;
    if (bVar4) {
      uVar1 = 2;
    }
    if (bVar4) {
      (&Peripherals::BUFC.BUF0_CMD)[param_1 * 0xc] = uVar1;
    }
  }
  return;
}



void checkAndAddRxLenOverflowEntry(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::BUFC.IF);
  if ((int)(uVar1 << 0xf) < 0) {
    write_volatile_4(Peripherals::BUFC.IFC,0x10000);
    write_volatile_4(Peripherals::BUFC_SET.IEN,0x10000);
    uVar1 = read_volatile_4(Peripherals::BUFC.BUF1_WRITEOFFSET);
    write_volatile_4(Peripherals::BUFC.BUF2_WRITEDATA,uVar1 & 0xff);
    uVar1 = read_volatile_4(Peripherals::BUFC.BUF1_WRITEOFFSET);
    write_volatile_4(Peripherals::BUFC.BUF2_WRITEDATA,(uVar1 << 0x10) >> 0x18);
    write_volatile_4(Peripherals::BUFC.BUF2_WRITEDATA,4);
    write_volatile_4(Peripherals::BUFC.BUF2_WRITEDATA,0);
  }
  return;
}



void BUFC_SetTxBuffer(uint param_1,uint param_2,uint param_3)

{
  CORE_irqState_t irqState;
  uint uVar1;
  bool bVar2;
  
  write_volatile_4(Peripherals::BUFC.BUF0_CTRL,param_3);
  write_volatile_4(Peripherals::BUFC.BUF0_ADDR,param_1);
  irqState = CORE_EnterCritical();
  uVar1 = read_volatile_4(Peripherals::BUFC.IF);
  uVar1 = uVar1 << 0x1d;
  bVar2 = -1 < (int)uVar1;
  if (bVar2) {
    uVar1 = 4;
  }
  write_volatile_4(Peripherals::BUFC.BUF0_READOFFSET,0);
  write_volatile_4(Peripherals::BUFC.BUF0_WRITEOFFSET,param_2);
  if (bVar2) {
    write_volatile_4(Peripherals::BUFC.IFC,uVar1);
  }
  CORE_ExitCritical(irqState);
  if (param_2 != 0) {
    write_volatile_4(Peripherals::BUFC.BUF0_CMD,2);
  }
  return;
}



void BUFC_WriteBuffer(uint8_t buf,uint8_t *src,uint16_t len)

{
  uint uVar1;
  uint uVar2;
  void *__dest;
  uint8_t *__src;
  uint __n;
  uint uVar3;
  void *__dest_00;
  uint uVar4;
  uint __n_00;
  
  uVar1 = (uint)buf;
  switch((uint)len) {
  case 4:
    (&Peripherals::BUFC.BUF0_WRITEDATA)[uVar1 * 0xc] = (uint)*src;
    src = src + 1;
  case 3:
    (&Peripherals::BUFC.BUF0_WRITEDATA)[uVar1 * 0xc] = (uint)*src;
    src = src + 1;
  case 2:
    (&Peripherals::BUFC.BUF0_WRITEDATA)[uVar1 * 0xc] = (uint)*src;
    src = src + 1;
  case 1:
    (&Peripherals::BUFC.BUF0_WRITEDATA)[uVar1 * 0xc] = (uint)*src;
    return;
  case 0xbad1abe1:
    return;
  default:
    (&Peripherals::BUFC.BUF0_WRITEDATA)[uVar1 * 0xc] = (uint)*src;
    (&Peripherals::BUFC.BUF0_WRITEDATA)[uVar1 * 0xc] = (uint)src[1];
    (&Peripherals::BUFC.BUF0_WRITEDATA)[uVar1 * 0xc] = (uint)src[2];
    (&Peripherals::BUFC.BUF0_WRITEDATA)[uVar1 * 0xc] = (uint)src[3];
    uVar3 = (&Peripherals::BUFC.BUF0_WRITEOFFSET)[uVar1 * 0xc];
    uVar4 = 1 << ((&Peripherals::BUFC.BUF0_CTRL)[uVar1 * 0xc] & 7) + 6;
    uVar2 = uVar4 - 1 & uVar3;
    __n_00 = uVar4 - uVar2;
    __n = len - 4;
    __src = src + 4;
    __dest_00 = (void *)((&Peripherals::BUFC.BUF0_ADDR)[uVar1 * 0xc] | 0x20000000);
    __dest = (void *)(uVar2 + (int)__dest_00);
    if (__n_00 < __n) {
      memcpy(__dest,__src,__n_00);
      memcpy(__dest_00,__src + __n_00,__n - __n_00);
    }
    else {
      memcpy(__dest,__src,__n);
    }
    (&Peripherals::BUFC.BUF0_WRITEOFFSET)[uVar1 * 0xc] = __n + uVar3 & (uVar4 - 1 | uVar4);
    return;
  }
}



void BUFC_ReadBuffer(uint param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = param_2;
  uVar3 = param_3;
  do {
    uVar1 = (&Peripherals::BUFC.BUF0_STATUS)[param_1 * 0xc] & 0x1fff;
    if (uVar1 == 0) {
      if (param_3 == 0) {
        return;
      }
      write_volatile_4(Peripherals::BUFC.IFS,2 << ((param_1 & 0x1f) << 3));
      return;
    }
    if (param_3 <= uVar1) {
      uVar1 = param_3;
    }
    BUFC_ReadHelper(param_1 & 0xff,param_2,uVar1 & 0xffff,
                    (&Peripherals::BUFC.BUF0_READOFFSET)[param_1 * 0xc] & 0xffff,1,uVar2,uVar3);
    param_3 = param_3 - uVar1;
  } while (param_3 != 0);
  return;
}



undefined4 BUFC_Peek(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  BUFC_ReadHelper();
  return param_3;
}



uint BUFC_PeekByte(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 < ((&Peripherals::BUFC.BUF0_STATUS)[param_1 * 0xc] & 0x1ff)) {
    uVar1 = (uint)*(byte *)((&Peripherals::BUFC.BUF0_ADDR)[param_1 * 0xc] +
                            (param_2 + (&Peripherals::BUFC.BUF0_READOFFSET)[param_1 * 0xc] & 0x1ff)
                           + 0x20000000);
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



uint16_t BUFC_GetSpaceAvailable(uint32_t buf)

{
  return (uint16_t)
         ((short)(1 << ((&Peripherals::BUFC.BUF0_CTRL)[buf * 0xc] & 7) + 6) -
         (ushort)(((&Peripherals::BUFC.BUF0_STATUS)[buf * 0xc] << 0x13) >> 0x13));
}



uint16_t BUFC_GetBytesAvailable(uint8_t buf)

{
  return (uint16_t)(((&Peripherals::BUFC.BUF0_STATUS)[(uint)buf * 0xc] << 0x13) >> 0x13);
}



bool BUFC_TxAckBufferSet(uint8_t *src,uint8_t len)

{
  CORE_irqState_t irqState;
  
  if (0x40 >= len) {
    write_volatile_4(Peripherals::BUFC.BUF3_CMD,1);
    irqState = CORE_EnterCritical();
    BUFC_WriteBuffer('\x03',src,(ushort)len);
    CORE_ExitCritical(irqState);
    write_volatile_4(Peripherals::BUFC.BUF3_CMD,4);
  }
  return 0x40 < len;
}



undefined BUFC_TxAckBufferReset(void)

{
  bool bVar1;
  
  bVar1 = BUFC_TxAckBufferSet((uint8_t *)0x0,'\0');
  return bVar1;
}



void BUFC_RxBufferReset(void)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  write_volatile_4(Peripherals::BUFC.BUF1_CMD,1);
  write_volatile_4(Peripherals::BUFC.BUF2_CMD,1);
  write_volatile_4(Peripherals::BUFC.BUF2_CTRL,0);
  write_volatile_4(Peripherals::BUFC.BUF2_ADDR,(uint)&BUFC_RxLenBuffer);
  write_volatile_4(Peripherals::BUFC.BUF2_THRESHOLDCTR,3);
  BUFC_RxLenBufferThreshold = 3;
  BUFC_RxLenBufferReadOffset = 0;
  write_volatile_4(Peripherals::BUFC.IFC,0x50000);
  write_volatile_4(Peripherals::BUFC_SET.IEN,0x50000);
  callbackRxLenEntry = 0;
  CORE_ExitCritical(irqState);
  return;
}



void BUFC_Init(undefined4 param_1)

{
  write_volatile_4(Peripherals::BUFC.BUF1_CTRL,3);
  write_volatile_4(Peripherals::BUFC.BUF1_ADDR,(uint)BUFC_RxBuffer);
  write_volatile_4(Peripherals::BUFC.BUF1_THRESHOLDCTRL,0xfff);
  write_volatile_4(Peripherals::BUFC.BUF2_CTRL,0);
  write_volatile_4(Peripherals::BUFC.BUF2_ADDR,(uint)&BUFC_RxLenBuffer);
  write_volatile_4(Peripherals::BUFC.BUF2_THRESHOLDCTR,3);
  BUFC_RxLenBufferThreshold = 3;
  BUFC_RxLenBufferReadOffset = 0;
  write_volatile_4(Peripherals::BUFC.BUF3_CTRL,0);
  write_volatile_4(Peripherals::BUFC.BUF3_ADDR,(uint)&BUFC_TxAckBuffer);
  write_volatile_4(Peripherals::BUFC.BUF3_THRESHOLDCTRL,0x2000);
  protocolRxOverflowHook = param_1;
  RADIO_FrameControlDescrBufferIdSet(0,0);
  RADIO_FrameControlDescrBufferIdSet(1,0);
  RADIO_FrameControlDescrBufferIdSet(2,1);
  RADIO_FrameControlDescrBufferIdSet(3,1);
  write_volatile_4(Peripherals::FRC_CLR.CTRL,0xf0);
  write_volatile_4(Peripherals::FRC_SET.CTRL,0xa0);
  write_volatile_4(Peripherals::BUFC.BUF3_CMD,1);
  BUFC_RxBufferReset();
  return;
}



uint BUFC_RxBufferBytesAvailable(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::BUFC.BUF1_STATUS);
  return uVar1 & 0x1fff;
}



uint BUFC_HoldRxPacket(void)

{
  uint uVar1;
  
  uVar1 = callbackRxLenEntry;
  if (callbackRxLenEntry != 0) {
    uVar1 = callbackRxLenEntry & 0xfffffffe;
    callbackRxLenEntry = callbackRxLenEntry | 1;
  }
  return uVar1;
}



undefined4 BUFC_ReleaseRxPacket(ushort *param_1)

{
  CORE_irqState_t irqState;
  uint uVar1;
  int iVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  
  if (param_1 == (ushort *)0x0) {
    return 3;
  }
  irqState = CORE_EnterCritical();
  uVar1 = (uint)BUFC_RxLenBufferReadOffset;
  if (param_1 == (ushort *)0x2) {
    if (callbackRxLenEntry == 0) goto LAB_0000b22e;
    param_1 = (ushort *)(callbackRxLenEntry & 0xfffffffe);
  }
  else {
    if (param_1 == (ushort *)(FUN_00000000 + 1)) {
      param_1 = (ushort *)(&BUFC_RxLenBuffer + (uVar1 & 0x3c));
    }
  }
  if (param_1 == (ushort *)(callbackRxLenEntry & 0xfffffffe)) {
    callbackRxLenEntry = 0;
  }
  else {
    iVar2 = (int)param_1 - (uVar1 & 0x3f);
    iVar3 = iVar2 + -0x200043dc;
    if (iVar3 < 0) {
      iVar3 = iVar2 + -0x2000439c;
    }
    if ((int)(BUFC_RxLenBufferThreshold - 4) <= iVar3) {
LAB_0000b22e:
      CORE_ExitCritical(irqState);
      return 3;
    }
  }
  *param_1 = ~((ushort)~(ushort)(((uint)*param_1 << 0x11) >> 0x10) >> 1);
  if (param_1 == (ushort *)(&BUFC_RxLenBuffer + (uVar1 & 0x3c))) {
    uVar5 = (uint)BUFC_RxLenBufferThreshold;
    uVar1 = uVar5;
    do {
      puVar4 = param_1;
      uVar1 = uVar1 - 4 & 0xffff;
      param_1 = puVar4 + 2;
      if ((undefined *)0x2000441b < puVar4 + 2) {
        param_1 = (ushort *)&BUFC_RxLenBuffer;
      }
    } while ((4 < uVar1) && ((short)*param_1 < 0));
    BUFC_RxLenBufferThreshold = (ushort)uVar1;
    write_volatile_4(Peripherals::BUFC.BUF1_READOFFSET,*puVar4 & 0x1fff);
    uVar5 = (BUFC_RxLenBufferReadOffset + uVar5) - uVar1 & 0x7f;
    BUFC_RxLenBufferReadOffset = (ushort)uVar5;
    write_volatile_4(Peripherals::BUFC.BUF2_READOFFSET,uVar5);
    write_volatile_4(Peripherals::BUFC.BUF2_THRESHOLDCTR,uVar1);
    if ((*(byte *)(puVar4 + 1) & 7) == 4) {
      if (protocolRxOverflowHook != FUN_00000000) {
        (*protocolRxOverflowHook)();
      }
      RADIO_RACClearRxOverflow();
    }
  }
  checkAndAddRxLenOverflowEntry();
  CORE_ExitCritical(irqState);
  return 0;
}



void BUFC_StartRxLenThrEvent(void)

{
  byte bVar1;
  byte bVar2;
  undefined *puVar3;
  uint uVar4;
  undefined **ppuVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 local_38 [8];
  
  uVar4 = BUFC_RxLenBufferThreshold + 4 & 0xffff;
  uVar6 = ((uint)BUFC_RxLenBufferReadOffset + (uint)BUFC_RxLenBufferThreshold) - 3 & 0x3c;
  BUFC_RxLenBufferThreshold = (ushort)uVar4;
  write_volatile_4(Peripherals::BUFC.BUF2_THRESHOLDCTR,uVar4);
  bVar1 = (&DAT_200043de)[uVar6];
  bVar2 = bVar1 & 7;
  puVar7 = local_38;
  if ((bVar1 & 7) == 0) {
    bVar2 = (&DAT_200043df)[uVar6];
    if ((bVar2 & 0x81) == 0) {
      ppuVar5 = (undefined **)&DAT_00017300;
      do {
        puVar3 = ppuVar5[1];
        *puVar7 = *ppuVar5;
        puVar7[1] = puVar3;
        puVar7 = puVar7 + 2;
        ppuVar5 = ppuVar5 + 2;
      } while (ppuVar5 != &regBases);
      bVar2 = *(byte *)((int)local_38 + (uint)(bVar2 >> 2));
    }
    else {
      bVar2 = 4;
    }
    (&DAT_200043de)[uVar6] = bVar1 | bVar2;
  }
  if (bVar2 == 4) {
    do {
      uVar4 = read_volatile_4(Peripherals::RAC.STATUS);
    } while ((int)(uVar4 << 0xc) < 0);
  }
  callbackRxLenEntry = &BUFC_RxLenBuffer + uVar6;
  return;
}



void BUFC_EndRxLenThrEvent(void)

{
  if (callbackRxLenEntry != 0) {
    if (-1 < callbackRxLenEntry << 0x1f) {
      BUFC_ReleaseRxPacket();
    }
    callbackRxLenEntry = 0;
  }
  return;
}



void BUFC_HandleRxLenOvfEvent(void)

{
  uint uVar1;
  
  write_volatile_4(Peripherals::BUFC_CLR.IEN,0x10000);
  write_volatile_4(Peripherals::BUFC.IFS,0x10000);
  uVar1 = read_volatile_4(Peripherals::BUFC.BUF2_STATUS);
  if ((uVar1 & 0x1fff) < 0x3d) {
    checkAndAddRxLenOverflowEntry();
    return;
  }
  return;
}



ushort * BUFC_GetRxPacketInfo(ushort *param_1,byte *param_2,undefined2 *param_3)

{
  short sVar1;
  CORE_irqState_t irqState;
  ushort *puVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  ushort uVar8;
  uint uVar9;
  uint uVar10;
  
  irqState = CORE_EnterCritical();
  uVar10 = (uint)BUFC_RxLenBufferReadOffset;
  if (param_1 == (ushort *)0x2) {
    if (callbackRxLenEntry == 0) {
      param_1 = (ushort *)(&BUFC_RxLenBuffer + ((uVar10 + BUFC_RxLenBufferThreshold) - 3 & 0x3c));
    }
    else {
      param_1 = (ushort *)(callbackRxLenEntry & 0xfffffffe);
    }
  }
  else {
    if (param_1 == (ushort *)(FUN_00000000 + 1)) {
      param_1 = (ushort *)(&BUFC_RxLenBuffer + (uVar10 & 0x3c));
    }
  }
  iVar5 = (int)param_1 - (uVar10 & 0x3f);
  iVar6 = iVar5 + -0x200043dc;
  if (iVar6 < 0) {
    iVar6 = iVar5 + -0x2000439c;
  }
  if (iVar6 < (int)(uint)BUFC_RxLenBufferThreshold) {
    if ((param_2 != (byte *)0x0) || (param_3 != (undefined2 *)0x0)) {
      if (param_1 == (ushort *)(&BUFC_RxLenBuffer + (uVar10 & 0x3c))) {
        uVar10 = read_volatile_4(Peripherals::BUFC.BUF1_READOFFSET);
        uVar10 = uVar10 & 0xffff;
      }
      else {
        puVar2 = param_1 + -2;
        if (puVar2 < &BUFC_RxLenBuffer) {
          puVar2 = param_1 + 0x1e;
        }
        uVar10 = *puVar2 & 0x1fff;
      }
      if (param_3 != (undefined2 *)0x0) {
        *param_3 = (short)uVar10;
      }
      if (param_2 != (byte *)0x0) {
        uVar9 = read_volatile_4(Peripherals::BUFC.BUF2_STATUS);
        if (iVar6 < (int)(uVar9 & 0x1fff)) {
          uVar8 = *param_1;
          if ((short)uVar8 < 0) goto LAB_0000b45c;
          bVar4 = *(byte *)(param_1 + 1);
          *param_2 = bVar4 & 7;
          uVar9 = uVar8 - uVar10 & 0x3ff;
          if (5 < (bVar4 & 7)) {
            iVar5 = RADIO_RxTrailDataLength();
            uVar9 = uVar9 - iVar5 & 0xffff;
          }
          RAILInt_Assert((~uVar9 << 0x10) >> 0x1f,4);
          *(short *)(param_2 + 2) = (short)uVar9;
        }
        else {
          uVar9 = read_volatile_4(Peripherals::BUFC.BUF1_WRITEOFFSET);
          uVar3 = read_volatile_4(Peripherals::RAC.STATUS);
          if ((uVar9 - uVar10 & 0x3ff) == 0) {
            if ((uVar3 << 4) >> 0x1c == 3) {
              bVar4 = 8;
            }
            else {
              bVar4 = 0;
            }
          }
          else {
            bVar4 = 8;
          }
          *param_2 = bVar4;
          sVar1 = RADIO_RxTrailDataLength();
          uVar8 = (ushort)((uVar9 - uVar10) * 0x400000 >> 0x16) - sVar1;
          uVar8 = uVar8 & ~((short)uVar8 >> 0x1f);
          uVar9 = (uint)uVar8;
          *(ushort *)(param_2 + 2) = uVar8;
        }
        puVar7 = BUFC_RxBuffer;
        uVar10 = uVar10 & 0x1ff;
        *(undefined1 **)(param_2 + 8) = BUFC_RxBuffer + uVar10;
        uVar3 = uVar10 + uVar9;
        if (uVar3 < 0x201) {
          puVar7 = (undefined1 *)0x0;
        }
        else {
          uVar10 = 0x200 - uVar10;
        }
        if (0x200 < uVar3) {
          *(short *)(param_2 + 4) = (short)uVar10;
        }
        if (uVar3 < 0x201) {
          *(short *)(param_2 + 4) = (short)uVar9;
        }
        *(undefined1 **)(param_2 + 0xc) = puVar7;
      }
    }
    CORE_ExitCritical(irqState);
    return param_1;
  }
LAB_0000b45c:
  CORE_ExitCritical(irqState);
  return (ushort *)0x0;
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
    uVar1 = read_volatile_4(Peripherals::RAC.IFPGACAL);
    write_volatile_4(Peripherals::RAC.IFPGACAL,uVar1 & 0xffff0000 | param_1 & 0xffff);
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
  
  BUFC_RxBuffer._0_4_ = read_volatile_4(Peripherals::RAC.SGRFENCTRL0);
  BUFC_RxBuffer._4_4_ = read_volatile_4(Peripherals::RAC.RFENCTRL0);
  BUFC_RxBuffer._8_4_ = read_volatile_4(Peripherals::AGC.CTRL0);
  BUFC_RxBuffer._12_4_ = read_volatile_4(Peripherals::AGC.MANGAIN);
  BUFC_RxBuffer._16_4_ = read_volatile_4(Peripherals::AGC.GAINRANGE);
  BUFC_RxBuffer._20_4_ = read_volatile_4(Peripherals::AGC.GAININDEX);
  BUFC_RxBuffer._24_4_ = read_volatile_4(Peripherals::AGC.MININDEX);
  BUFC_RxBuffer._28_4_ = read_volatile_4(Peripherals::MODEM.MODINDEX);
  BUFC_RxBuffer._32_4_ = read_volatile_4(Peripherals::MODEM.CTRL0);
  BUFC_RxBuffer._36_4_ = read_volatile_4(Peripherals::FRC.DFLCTRL);
  BUFC_RxBuffer._40_4_ = read_volatile_4(Peripherals::RAC.SGPACTRL0);
  BUFC_RxBuffer._44_4_ = read_volatile_4(Peripherals::RAC.SGPAPKDCTRL);
  BUFC_RxBuffer._48_4_ = read_volatile_4(Peripherals::RAC.SGPABIASCTRL0);
  BUFC_RxBuffer._52_4_ = read_volatile_4(Peripherals::RAC.SGPABIASCTRL1);
  BUFC_RxBuffer._56_4_ = read_volatile_4(Peripherals::RAC.PACTUNECTRL);
  BUFC_RxBuffer._60_4_ = read_volatile_4(Peripherals::MODEM.RAMPCTRL);
  BUFC_RxBuffer._64_4_ = read_volatile_4(Peripherals::RAC.TESTCTRL);
  BUFC_RxBuffer._68_4_ = read_volatile_4(Peripherals::AGC.CTRL1);
  BUFC_RxBuffer._72_4_ = read_volatile_4(Peripherals::MODEM.AFC);
  BUFC_RxBuffer._76_4_ = SYNTH_RfFreqGet();
  BUFC_RxBuffer._80_4_ = SYNTH_ChSpacingGet();
  write_volatile_4(Peripherals::MODEM.AFC,0);
  write_volatile_4(Peripherals::FRC_SET.CTRL,1);
  write_volatile_4(Peripherals::RAC_SET.CTRL,0x40);
  uVar1 = read_volatile_4(Peripherals::AGC.CTRL1);
  write_volatile_4(Peripherals::AGC.CTRL1,uVar1 & 0xfffff0ff | (rcIrCalData[16] & 0xf) << 8);
  return;
}



int IRCAL_SetRxFrequency(int param_1)

{
  bool bVar1;
  RAIL_Status_t_enum RVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar3 = SYNTH_IfFreqGet();
  uVar5 = read_volatile_4(Peripherals::SYNTH.IFFREQ);
  iVar4 = iVar3 * 2;
  if ((uVar5 & 0x100000) != 0) {
    iVar4 = iVar3 * -2;
  }
  bVar1 = SYNTH_VcoRangeIsValid(param_1 + iVar4);
  if (bVar1 == false) {
    IRCAL_Set();
    return -1;
  }
  RVar2 = SYNTH_Config(param_1 + iVar4,0);
  uVar5 = (uint)RVar2;
  if (uVar5 != 0) {
    uVar5 = 1;
  }
  return -uVar5;
}



void IRCAL_StartRx(void)

{
  uint uVar1;
  
  write_volatile_4(Peripherals::MODEM_SET.CTRL0,0x200000);
  do {
    uVar1 = read_volatile_4(Peripherals::RAC.STATUS);
  } while ((uVar1 & 0xf000000) != 0);
  BUFC_RxBufferReset();
  write_volatile_4(Peripherals::RAC_SET.RXENSRCEN,8);
  do {
    uVar1 = read_volatile_4(Peripherals::RAC.STATUS);
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
  write_volatile_4(Peripherals::RAC_CLR.RXENSRCEN,0xff);
  irqState = CORE_EnterCritical();
  uVar2 = read_volatile_4(Peripherals::RAC.STATUS);
  uVar2 = (uVar2 << 4) >> 0x1c;
  bVar3 = uVar2 == 3;
  if (bVar3) {
    iVar1 = 0x21000f7c;
    uVar2 = read_volatile_4(Peripherals::SEQ.REG080);
    uVar2 = uVar2 & 0xffffff0f | 0xe0;
  }
  if (bVar3) {
    *(uint *)(iVar1 + 4) = uVar2;
  }
  write_volatile_4(Peripherals::FRC.CMD,1);
  CORE_ExitCritical(irqState);
  do {
    uVar2 = read_volatile_4(Peripherals::RAC.STATUS);
  } while ((uVar2 & 0xf000000) != 0);
  return;
}



void IRCAL_SetSubGhzPllLoopback(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::AGC.MANGAIN);
  write_volatile_4(Peripherals::AGC.MANGAIN,uVar1 & 0x801001ff | 0x40009800);
  write_volatile_4(Peripherals::AGC_SET.CTRL0,0x400000);
  write_volatile_4(Peripherals::RAC_SET.SGRFENCTRL0,0x80000);
  write_volatile_4(Peripherals::RAC_SET.RFENCTRL0,0x80000);
  return;
}



void IRCAL_SetSubGhzPaLoopback(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::AGC.GAINRANGE);
  write_volatile_4(Peripherals::AGC.GAINRANGE,uVar1 & 0xffffc000 | 0x383e);
  uVar1 = read_volatile_4(Peripherals::AGC.GAININDEX);
  write_volatile_4(Peripherals::AGC.GAININDEX,uVar1 & 0xfff00000 | 0x25bc);
  uVar1 = read_volatile_4(Peripherals::AGC.MININDEX);
  write_volatile_4(Peripherals::AGC.MININDEX,uVar1 & 0xff000000 | 0x6d8480);
  uVar1 = read_volatile_4(Peripherals::AGC.MANGAIN);
  write_volatile_4(Peripherals::AGC.MANGAIN,uVar1 & 0xffffff40 | 0xa7);
  write_volatile_4(Peripherals::AGC_SET.CTRL0,0x400000);
  write_volatile_4(Peripherals::MODEM.MODINDEX,0);
  uVar1 = read_volatile_4(Peripherals::MODEM.CTRL0);
  write_volatile_4(Peripherals::MODEM.CTRL0,uVar1 & 0xfffffe3f | 0x100);
  uVar1 = read_volatile_4(Peripherals::FRC.DFLCTRL);
  write_volatile_4(Peripherals::FRC.DFLCTRL,uVar1 & 0xfffffff8 | 5);
  write_volatile_4(Peripherals::RAC_CLR.SGRFENCTRL0,0x80000);
  uVar1 = read_volatile_4(Peripherals::RAC.SGPACTRL0);
  write_volatile_4(Peripherals::RAC.SGPACTRL0,uVar1 & 0x3fffffff | 0x40000000);
  write_volatile_4(Peripherals::RAC_CLR.SGPAPKDCTRL,0xc000);
  write_volatile_4(Peripherals::RAC_SET.SGPAPKDCTRL,0xc000);
  uVar1 = read_volatile_4(Peripherals::RAC.SGPABIASCTRL0);
  write_volatile_4(Peripherals::RAC.SGPABIASCTRL0,uVar1 & 0xff3ff332 | 0x445);
  uVar1 = read_volatile_4(Peripherals::RAC.SGPABIASCTRL1);
  write_volatile_4(Peripherals::RAC.SGPABIASCTRL1,uVar1 & 0xffffffc8 | 0x20);
  uVar1 = read_volatile_4(Peripherals::RAC.SGPABIASCTRL1);
  write_volatile_4(Peripherals::RAC.SGPABIASCTRL1,uVar1 & 0xfff388ff | 0x84500);
  write_volatile_4(Peripherals::RAC_CLR.PACTUNECTRL,0x1f0);
  write_volatile_4(Peripherals::RAC_SET.SGPACTRL0,8);
  write_volatile_4(Peripherals::RAC_SET.SGRFENCTRL0,0x10000);
  PROTIMER_DelayUs(0x14);
  uVar1 = read_volatile_4(Peripherals::RAC.SGPACTRL0);
  write_volatile_4(Peripherals::RAC.SGPACTRL0,uVar1 & 0xffffc03f | 0x40);
  write_volatile_4(Peripherals::RAC_SET.SGRFENCTRL0,0x20000);
  PROTIMER_DelayUs(0x14);
  uVar1 = read_volatile_4(Peripherals::RAC.SGPACTRL0);
  write_volatile_4(Peripherals::RAC.SGPACTRL0,uVar1 & 0xe0c03fff | 0x1004000);
  PROTIMER_DelayUs(0x14);
  write_volatile_4(Peripherals::RAC_SET.SGRFENCTRL0,0x40000);
  PROTIMER_DelayUs(0x14);
  write_volatile_4(Peripherals::RAC_SET.TESTCTRL,9);
  PROTIMER_DelayUs(0x14);
  uVar1 = read_volatile_4(Peripherals::RAC.SGPACTRL0);
  write_volatile_4(Peripherals::RAC.SGPACTRL0,uVar1 & 0xe0c03fff | 0x1004000);
  PROTIMER_DelayUs(0x14);
  uVar1 = read_volatile_4(Peripherals::MODEM.RAMPCTRL);
  write_volatile_4(Peripherals::MODEM.RAMPCTRL,
                   uVar1 & 0x7fffff | 0x800000 | (uint)rcIrCalData[2] << 0x18);
  PROTIMER_DelayUs(0x14);
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



int IRCAL_ReadRssi(uint param_1,uint param_2,uint param_3,uint32_t param_4,ushort param_5)

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
    uVar5 = read_volatile_4(Peripherals::RAC.IFPGACAL);
    write_volatile_4(Peripherals::RAC.IFPGACAL,uVar5 & 0xffff8080 | param_1 << 8 | param_2);
    PROTIMER_DelayUs(param_4);
    if (rcIrCalData[9] == '\0') {
      write_volatile_4(Peripherals::AGC.IFC,0x20);
    }
    uVar5 = 0;
    uVar4 = 0;
    for (uVar6 = 0; uVar6 >> (param_3 & 0xff) == 0; uVar6 = uVar6 + 1) {
      PROTIMER_DelayUs((uint)param_5);
      if (rcIrCalData[9] == '\0') {
        write_volatile_4(Peripherals::AGC.CMD,1);
        do {
          uVar1 = read_volatile_4(Peripherals::AGC.IF);
        } while (-1 < (int)(uVar1 << 0x1a));
      }
      if (rcIrCalData[11] <= uVar6) {
        iVar2 = RADIO_GetRssi(true);
        uVar5 = uVar5 + 1;
        uVar4 = uVar4 + (int)iVar2;
      }
      if (rcIrCalData[9] == '\0') {
        write_volatile_4(Peripherals::AGC.IFC,0x20);
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
  RAIL_Status_t_enum RVar1;
  
  IRCAL_StopRx();
  AUXPLL_Stop();
  write_volatile_4(Peripherals::RAC.SGRFENCTRL0,BUFC_RxBuffer._0_4_);
  write_volatile_4(Peripherals::RAC.RFENCTRL0,BUFC_RxBuffer._4_4_);
  write_volatile_4(Peripherals::AGC.CTRL0,BUFC_RxBuffer._8_4_);
  write_volatile_4(Peripherals::AGC.MANGAIN,BUFC_RxBuffer._12_4_);
  write_volatile_4(Peripherals::AGC.GAINRANGE,BUFC_RxBuffer._16_4_);
  write_volatile_4(Peripherals::AGC.GAININDEX,BUFC_RxBuffer._20_4_);
  write_volatile_4(Peripherals::AGC.MININDEX,BUFC_RxBuffer._24_4_);
  write_volatile_4(Peripherals::MODEM.MODINDEX,BUFC_RxBuffer._28_4_);
  write_volatile_4(Peripherals::MODEM.CTRL0,BUFC_RxBuffer._32_4_);
  write_volatile_4(Peripherals::FRC.DFLCTRL,BUFC_RxBuffer._36_4_);
  write_volatile_4(Peripherals::RAC.SGPACTRL0,BUFC_RxBuffer._40_4_);
  write_volatile_4(Peripherals::RAC.SGPAPKDCTRL,BUFC_RxBuffer._44_4_);
  write_volatile_4(Peripherals::RAC.SGPABIASCTRL0,BUFC_RxBuffer._48_4_);
  write_volatile_4(Peripherals::RAC.SGPABIASCTRL1,BUFC_RxBuffer._52_4_);
  write_volatile_4(Peripherals::RAC.PACTUNECTRL,BUFC_RxBuffer._56_4_);
  write_volatile_4(Peripherals::MODEM.RAMPCTRL,BUFC_RxBuffer._60_4_);
  write_volatile_4(Peripherals::RAC.TESTCTRL,BUFC_RxBuffer._64_4_);
  write_volatile_4(Peripherals::AGC.CTRL1,BUFC_RxBuffer._68_4_);
  write_volatile_4(Peripherals::MODEM.AFC,BUFC_RxBuffer._72_4_);
  RVar1 = SYNTH_Config(BUFC_RxBuffer._76_4_,BUFC_RxBuffer._80_4_);
  BUFC_RxBufferReset(RVar1);
  write_volatile_4(Peripherals::FRC_CLR.CTRL,1);
  write_volatile_4(Peripherals::RAC_CLR.CTRL,0x40);
  write_volatile_4(Peripherals::FRC.IFC,0xffffffff);
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
      uVar1 = read_volatile_4(Peripherals::MODEM.CTRL0);
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
  int iVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  uint64_t uVar5;
  uint64_t uVar6;
  undefined8 uVar7;
  
  uVar2 = read_volatile_4(Peripherals::PROTIMER.WRAPCNT);
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
  uVar3 = read_volatile_4(Peripherals::PROTIMER.WRAPCNT);
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



void PA_ProtectPa(uint param_1)

{
  bool bVar1;
  RAC_CLR *pRVar2;
  RAC_SET *pRVar3;
  uint uVar4;
  uint uVar5;
  
  if ((char)gPaConfig != '\x03') {
    uVar5 = read_volatile_4(Peripherals::SEQ.REG0E0);
    uVar4 = ((uVar5 << 10) >> 0x18) << 6;
    if (param_1 < 0x5b) {
      bVar1 = false;
    }
    else {
      if (gPaConfig._2_2_ < 0x709) {
        bVar1 = 200 < param_1;
        if (bVar1) {
          uVar4 = 0x3fc8;
        }
      }
      else {
        bVar1 = true;
        uVar4 = 0x3fc8;
      }
    }
    if (param_1 < 0x1f) {
      pRVar2 = &Peripherals::RAC_CLR;
    }
    else {
      pRVar2 = (RAC_CLR *)&Peripherals::RAC_SET;
    }
    write_volatile_4(Peripherals::SEQ.REG0E0,uVar4 | uVar5 & 0xffffc037);
    pRVar2->PABIASCTRL0 = 1;
    (&pRVar2->PABIASCTRL0)[6] = 1;
    if (((apcEnabled == '\0') || (param_1 < 0x51)) ||
       ((gPaConfig._2_2_ < 0x709 && (param_1 < 0x79)))) {
      pRVar3 = (RAC_SET *)&Peripherals::RAC_CLR;
    }
    else {
      write_volatile_4(Peripherals::RAC_CLR.PAPKDCTRL,0xdf01);
      write_volatile_4(Peripherals::RAC_CLR.SGPAPKDCTRL,0xdf01);
      if (bVar1) {
        uVar5 = 0xd700;
      }
      else {
        uVar5 = 0xd000;
      }
      write_volatile_4(Peripherals::RAC_SET.PAPKDCTRL,uVar5);
      write_volatile_4(Peripherals::RAC_SET.SGPAPKDCTRL,uVar5);
      pRVar3 = &Peripherals::RAC_SET;
    }
    ((RAC_CLR *)pRVar3)->SR3 = 8;
  }
  return;
}



uint32_t getRampTimeFromLevelAndRate(uint32_t level,uint32_t rate)

{
  uint32_t uVar1;
  
  uVar1 = SystemHFXOClockGet();
  return (uint32_t)
         ((ulonglong)(uint)(((int)(level << (rate & 0xff)) >> 5) * 10000) / ((ulonglong)uVar1 / 100)
         );
}



RAIL_Status_t_enum PA_GetTxPowerConfig(RAIL_TxPowerConfig_t *config)

{
  *(undefined4 *)config = gPaConfig;
  config->rampTime = gDesiredRampTime;
  return RAIL_STATUS_NO_ERROR;
}



RAIL_TxPowerLevel_t PA_GetPowerLevel(RAIL_Handle_t railHandle)

{
  return currentPowerLevel;
}



uint16_t PA_SetPowerLevel(uint8_t level)

{
  RAC_SET *pRVar1;
  undefined *puVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar8 = (uint)level;
  PA_ProtectPa(200);
  if ((char)gPaConfig == '\x03') {
    currentPowerLevel = 0xff;
    return 0xff;
  }
  if ((char)gPaConfig == '\x01') {
    if (uVar8 < 8) {
      if (uVar8 == 1) {
        uVar8 = 2;
      }
    }
    else {
      uVar8 = 7;
    }
    uVar4 = read_volatile_4(Peripherals::SEQ.REG0E0);
    write_volatile_4(Peripherals::SEQ.REG0E0,uVar4 & 0xe0c0003f | uVar8 << 0x18);
    write_volatile_4(Peripherals::RAC_CLR.APC,4);
    goto LAB_0000bfda;
  }
  uVar4 = read_volatile_4(Peripherals::SEQ.REG0E0);
  uVar4 = uVar4 & 0xe0c03fff | 0x3fc8;
  write_volatile_4(Peripherals::SEQ.REG0E0,uVar4);
  if ((char)gPaConfig == '\0') {
    cVar3 = (char)gPaConfig;
    if (4 < uVar8) {
      uVar8 = uVar8 - 4 & 0xff;
      cVar3 = '\x01';
    }
  }
  else {
    cVar3 = '\0';
  }
  uVar7 = read_volatile_4(Peripherals::CMU.RFLOCK0);
  iVar5 = count_leading_zeroes(~uVar7 & 0x1fc000 | 0x2000);
  uVar6 = (0x13 - iVar5) * 0x1f & 0xff;
  uVar7 = uVar8;
  if (uVar6 <= uVar8) {
    uVar7 = uVar6;
  }
  if ((char)gPaConfig == '\0') {
    if (cVar3 == '\0') {
      iVar5 = 0;
    }
    else {
      iVar5 = 4;
    }
  }
  else {
    iVar5 = 0;
  }
  uVar8 = iVar5 + uVar7;
  if (uVar7 == 0) {
    write_volatile_4(Peripherals::RAC.APC,0x700002c);
  }
  else {
    write_volatile_4(Peripherals::RAC.APC,0x7000000);
    uVar7 = uVar7 - 1 & 0xff;
  }
  uVar7 = uVar4 | (uVar7 % 0x1f) * 0x1000000 + 0x1000000 | ((1 << uVar7 / 0x1f + 1) + -1) * 0x4000;
  write_volatile_4(Peripherals::SEQ.REG0E0,uVar7);
  uVar4 = read_volatile_4(Peripherals::RAC.APC);
  if (paCalEnabled == '\0') {
LAB_0000bfba:
    if (uVar8 == 0) {
LAB_0000bfbe:
      uVar4 = 0x7000004;
    }
    else {
LAB_0000bf9e:
      uVar4 = uVar4 & 0xfffffb | 0xff000000;
    }
  }
  else {
    iVar5 = count_leading_zeroes((uVar7 << 10) >> 0x18);
    if ((char)gPaConfig == '\x02') {
      puVar2 = &DAT_0fe083b0;
    }
    else {
      puVar2 = &DAT_0fe083b8;
    }
    if (0x1f - iVar5 == -1) goto LAB_0000bfba;
    if (uVar8 == 0) goto LAB_0000bfbe;
    if (0xfd < (byte)(puVar2[0x1f - iVar5] - 1)) goto LAB_0000bf9e;
    uVar4 = uVar4 & 0xffffff | 4 | (uint)(byte)puVar2[0x1f - iVar5] << 0x18;
  }
  write_volatile_4(Peripherals::RAC.APC,uVar4);
  if (cVar3 == '\0') {
    pRVar1 = (RAC_SET *)&Peripherals::RAC_CLR;
  }
  else {
    pRVar1 = &Peripherals::RAC_SET;
  }
  ((RAC_CLR *)pRVar1)->PABIASCTRL0 = 0x400000;
LAB_0000bfda:
  uVar8 = uVar8 & 0xff;
  currentPowerLevel = (undefined)uVar8;
  PA_ProtectPa(uVar8);
  return (uint16_t)uVar8;
}



void PA_RunPeakDetectorHigh(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = SYNTH_Is2p4GHz();
  if (iVar3 == 0) {
    uVar1 = read_volatile_4(Peripherals::RAC.SGPACTRL0);
    uVar2 = read_volatile_4(Peripherals::RAC.SGPACTRL0);
    write_volatile_4(Peripherals::RAC.SGPACTRL0,uVar1 & 0xffc03fff | (uVar2 & 0x3f8000) >> 1);
  }
  else {
    uVar1 = read_volatile_4(Peripherals::RAC.PACTRL0);
    uVar2 = read_volatile_4(Peripherals::RAC.PACTRL0);
    write_volatile_4(Peripherals::RAC.PACTRL0,uVar1 & 0xffc03fff | (uVar2 & 0x3f8000) >> 1);
  }
  write_volatile_4(Peripherals::RAC.IFC,0x2000000);
  return;
}



void PA_RunPeakDetectorLow(void)

{
  return;
}



void PA_RunBatHigh(void)

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
  write_volatile_4(Peripherals::RAC_CLR.IEN,0x8000000);
  return;
}



undefined2 PA_GetRampTime(void)

{
  return gDesiredRampTime;
}



void PA_ConfigRamp(uint *param_1)

{
  write_volatile_4(Peripherals::MODEM.RAMPLEV,param_1[1]);
  write_volatile_4(Peripherals::MODEM_CLR.RAMPCTRL,0xfff);
  write_volatile_4(Peripherals::MODEM_SET.RAMPCTRL,*param_1);
  return;
}



uint32_t PA_CalcRampTime(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  
  uVar4 = read_volatile_4(Peripherals::MODEM.RAMPLEV);
  uVar5 = read_volatile_4(Peripherals::MODEM.RAMPLEV);
  uVar6 = read_volatile_4(Peripherals::MODEM.RAMPLEV);
  uVar1 = read_volatile_4(Peripherals::MODEM.RAMPCTRL);
  uVar2 = read_volatile_4(Peripherals::MODEM.RAMPCTRL);
  uVar3 = read_volatile_4(Peripherals::MODEM.RAMPCTRL);
  uVar7 = getRampTimeFromLevelAndRate(uVar4 & 0xff,uVar1 & 0xf);
  uVar8 = getRampTimeFromLevelAndRate((uVar5 << 0x10) >> 0x18,(uVar2 << 0x18) >> 0x1c);
  uVar9 = getRampTimeFromLevelAndRate((uVar6 << 8) >> 0x18,(uVar3 << 0x14) >> 0x1c);
  return uVar9 + uVar7 + uVar8;
}



undefined2 PA_SetRampTime(uint param_1,undefined4 param_2,undefined4 param_3)

{
  uint32_t uVar1;
  uint uVar2;
  uint32_t uVar3;
  uint local_20;
  int local_1c;
  undefined4 uStack24;
  
  gDesiredRampTime = param_1;
  if (param_1 == 0) {
    gDesiredRampTime = 1;
  }
  uVar2 = read_volatile_4(Peripherals::MODEM.CTRL0);
  gCurrentModulation = (byte)((uVar2 << 0x17) >> 0x1d);
  uVar2 = ((uVar2 << 0x17) >> 0x1d) - 2 & 0xff;
  if ((uVar2 < 5) && ((1 << uVar2 & 0x13U) != 0)) {
    uVar3 = 0;
  }
  else {
    if ((char)gPaConfig == '\x02') {
      if (paCalEnabled == '\0') {
        uVar3 = 0x96;
      }
      else {
        uVar3 = 200;
      }
    }
    else {
      if ((char)gPaConfig == '\x01') {
        uVar3 = 0x32;
      }
      else {
        if (paCalEnabled == '\0') {
          uVar3 = 0xb4;
        }
        else {
          uVar3 = 0xf0;
        }
      }
    }
  }
  uVar2 = 0;
  local_20 = param_1;
  local_1c = param_2;
  uStack24 = param_3;
  do {
    uVar1 = getRampTimeFromLevelAndRate(uVar3,uVar2 & 0xff);
    if (gDesiredRampTime < uVar1) break;
    uVar2 = uVar2 + 1;
  } while (uVar2 != 0x10);
  local_20 = (uVar2 - 1) * 0x100;
  local_1c = uVar3 << 0x10;
  PA_ConfigRamp(&local_20);
  uVar3 = PA_CalcRampTime();
  gDesiredRampTime = (undefined2)uVar3;
  TIMING_RecalculatePaRampChanged(param_2);
  return gDesiredRampTime;
}



void PA_SetCTune(uint8_t txPaCtuneValue,uint8_t rxPaCtuneValue)

{
  write_volatile_4(Peripherals::SEQ.REG0E8,txPaCtuneValue & 7 | (txPaCtuneValue & 0x1f) << 4);
  write_volatile_4(Peripherals::SEQ.REG0E4,rxPaCtuneValue & 7 | (rxPaCtuneValue & 0x1f) << 4);
  return;
}



void PA_SelectBand(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = SYNTH_LoDivGet();
  if (false) {
switchD_0000c1e6_caseD_2:
    uVar2 = 0xf7;
LAB_0000c216:
    write_volatile_4(Peripherals::SEQ.REG0E8,uVar2);
    uVar2 = 0xa2;
  }
  else {
    switch(uVar1) {
    case 1:
      uVar2 = 0x44;
      if ((char)gPaConfig != '\x01') {
        write_volatile_4(Peripherals::SEQ.REG0E8,0);
        goto LAB_0000c21a;
      }
      break;
    default:
      goto switchD_0000c1e6_caseD_2;
    case 3:
    case 4:
      uVar2 = 0;
      break;
    case 5:
    case 6:
      uVar2 = 0x33;
      break;
    default:
      uVar2 = 0;
      goto LAB_0000c216;
    }
    write_volatile_4(Peripherals::SEQ.REG0E8,uVar2);
  }
LAB_0000c21a:
  write_volatile_4(Peripherals::SEQ.REG0E4,uVar2);
  return;
}



RAIL_Status_t_enum PA_Config(RAIL_TxPowerConfig_t *config)

{
  RAIL_TxPowerMode_t RVar1;
  uint uVar2;
  uint16_t uVar3;
  uint uVar4;
  uint *puVar5;
  bool bVar6;
  
  if (config == (RAIL_TxPowerConfig_t *)0x0) {
    return RAIL_STATUS_INVALID_PARAMETER;
  }
  RADIO_CLKEnable();
  memset(&Peripherals::SEQ.REG0E0,0,0xc);
  RVar1 = config->mode;
  if (RVar1 == '\x02') {
    uVar4 = read_volatile_4(Peripherals::CMU.RFLOCK0);
    bVar6 = (uVar4 & 0x200000) == 0;
  }
  else {
    if (RVar1 == '\x01') {
      uVar4 = read_volatile_4(Peripherals::CMU.RFLOCK0);
      bVar6 = (uVar4 & 0xc00000) == 0;
    }
    else {
      if (RVar1 != '\0') goto LAB_0000c27c;
      uVar4 = read_volatile_4(DAT_0fe081d4);
      uVar2 = read_volatile_4(Peripherals::CMU.RFLOCK0);
      bVar6 = (uVar4 & 1 ^ 1 | uVar2 & 0x400000) == 0;
    }
  }
  if (bVar6) {
    gPaConfig = *(uint *)config;
    gDesiredRampTime = config->rampTime;
    PA_SetPowerLevel('\0');
    PA_SetRampTime(config->rampTime,0);
    if ((gPaConfig & 0xff) == 2) {
      uVar4 = read_volatile_4(Peripherals::SEQ.REG0E0);
      write_volatile_4(Peripherals::SEQ.REG0E0,uVar4 & 0xbfffffe8 | 0x40000020);
      write_volatile_4(Peripherals::RAC_CLR.SGPABIASCTRL1,0x7700);
      write_volatile_4(Peripherals::RAC_SET.SGPABIASCTRL1,0x4500);
      write_volatile_4(Peripherals::RAC_SET.SGPABIASCTRL0,1);
    }
    else {
      uVar4 = read_volatile_4(Peripherals::SEQ.REG0E0);
      if ((gPaConfig & 0xff) == 1) {
        write_volatile_4(Peripherals::SEQ.REG0E0,uVar4 & 0xbfffffe8 | 3);
        write_volatile_4(Peripherals::RAC_CLR.PACTRL0,7);
        write_volatile_4(Peripherals::RAC_SET.PACTRL0,3);
        write_volatile_4(Peripherals::RAC_CLR.PABIASCTRL1,7);
        write_volatile_4(Peripherals::RAC_SET.PABIASCTRL1,6);
        write_volatile_4(Peripherals::RAC_CLR.PABIASCTRL0,0x4000c1);
        uVar4 = 0xc000;
        puVar5 = &Peripherals::RAC_CLR.PAPKDCTRL;
      }
      else {
        write_volatile_4(Peripherals::SEQ.REG0E0,uVar4 & 0xbfffffe8 | 0x40000014);
        write_volatile_4(Peripherals::RAC_CLR.PACTRL0,7);
        write_volatile_4(Peripherals::RAC_SET.PACTRL0,4);
        write_volatile_4(Peripherals::RAC_CLR.PABIASCTRL1,7);
        write_volatile_4(Peripherals::RAC_SET.PABIASCTRL1,5);
        write_volatile_4(Peripherals::RAC_CLR.PABIASCTRL0,0xc0);
        puVar5 = &Peripherals::RAC_SET.PABIASCTRL0;
        uVar4 = 0x81;
      }
      *puVar5 = uVar4;
    }
    uVar3 = PA_SetPowerLevel('\0');
    write_volatile_4(Peripherals::RAC_CLR.APC,3);
    PA_SelectBand(uVar3);
    return RAIL_STATUS_NO_ERROR;
  }
LAB_0000c27c:
  gPaConfig = CONCAT31(gPaConfig._1_3_,3);
  currentPowerLevel = 0xff;
  return RAIL_STATUS_INVALID_PARAMETER;
}



bool PA_UpdateConfig(undefined4 param_1)

{
  uint uVar1;
  
  PA_SelectBand();
  uVar1 = read_volatile_4(Peripherals::MODEM.CTRL0);
  if ((uint)gCurrentModulation != (uVar1 << 0x17) >> 0x1d) {
    PA_SetRampTime(gDesiredRampTime,param_1);
    return true;
  }
  return false;
}



void PA_EnableCal(bool enable)

{
  paCalEnabled = enable;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_Init(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 in_r3;
  longlong lVar5;
  undefined8 uVar6;
  
  RADIOCMU_ClockEnable(0x60400,true);
  write_volatile_4(Peripherals::PROTIMER.CTRL,0x11100);
  uVar1 = RADIOCMU_ClockFreqGet(0x60400);
  uVar1 = uVar1 / 1000;
  uVar2 = (uint)((ulonglong)uVar1 * 2000);
  uVar4 = uVar2 * 0x100;
  lVar5 = __aeabi_uldivmod(uVar4 + 500000,
                           ((int)((ulonglong)uVar1 * 2000 >> 0x20) << 8 | uVar2 >> 0x18) +
                           (uint)(0xfff85edf < uVar4),1000000,0,in_r3);
  uVar2 = (uint)lVar5;
  write_volatile_4(Peripherals::PROTIMER.PRECNTTOP,uVar2 - 0x100);
  uVar6 = __aeabi_uldivmod(500,uVar1,1000,0);
  if (lVar5 == 0) {
    RAILInt_Assert(0,0x2b);
    uVar2 = 1;
  }
  uVar4 = (uint)uVar6 * 0x100;
  _usRatioFrac = __aeabi_uldivmod(uVar4 + (uVar2 >> 1),
                                  ((int)((ulonglong)uVar6 >> 0x20) << 8 | (uint)uVar6 >> 0x18) +
                                  (uint)CARRY4(uVar4,uVar2 >> 1),uVar2,0);
  iVar3 = (int)_usRatioFrac;
  if (uVar1 == 0) {
    RAILInt_Assert(0,0x2b);
    uVar1 = 1;
  }
  lVar5 = (ulonglong)(uVar2 << 0x18) * 1000;
  uVar4 = (uint)lVar5;
  uVar6 = __aeabi_uldivmod(uVar4 + (uVar1 >> 1),
                           (uVar2 >> 8) * 1000 + (int)((ulonglong)lVar5 >> 0x20) +
                           (uint)CARRY4(uVar4,uVar1 >> 1),uVar1,0);
  write_volatile_4(Peripherals::PROTIMER.WRAPCNTTOP,iVar3 - 1);
  precntRatioFrac = (int)uVar6;
  precntRatioInt = (int)((ulonglong)uVar6 >> 0x20);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_Start(void)

{
  write_volatile_4(Peripherals::PROTIMER.CMD,1);
  _DAT_e000e100 = 0x10000000;
  _DAT_e000e280 = 0x10000000;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_Stop(void)

{
  write_volatile_4(Peripherals::PROTIMER.CMD,4);
  _DAT_e000e180 = 0x10000000;
  _DAT_e000e280 = 0x10000000;
  return;
}



bool PROTIMER_IsRunning(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::PROTIMER.STATUS);
  return (bool)((byte)uVar1 & 1);
}



void PROTIMER_Reset(void)

{
  write_volatile_4(Peripherals::PROTIMER.PRECNT,0);
  write_volatile_4(Peripherals::PROTIMER.BASECNT,0);
  write_volatile_4(Peripherals::PROTIMER.WRAPCNT,0);
  return;
}



int PROTIMER_ElapsedTime(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = read_volatile_4(Peripherals::PROTIMER.WRAPCNTTOP);
  iVar2 = param_2 - param_1;
  if (param_2 < param_1) {
    iVar2 = iVar2 + uVar1 + 1;
  }
  return iVar2;
}



void PROTIMER_CCTimerStop(uint32_t timer)

{
  (&Peripherals::PROTIMER_CLR.CC0_CTRL)[timer * 4] = 1;
  write_volatile_4(Peripherals::PROTIMER.IFC,0x100 << (timer & 0xff));
  return;
}



undefined4 PROTIMER_CCTimerStart(uint32_t param_1,uint param_2,int param_3)

{
  uint uVar1;
  CORE_irqState_t irqState;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  RAC *pRVar7;
  uint uVar8;
  bool bVar9;
  uint32_t uVar10;
  int iVar11;
  
  uVar10 = param_1;
  iVar11 = param_3;
  irqState = CORE_EnterCritical();
  PROTIMER_CCTimerStop(param_1);
  if (param_3 != 2) {
    uVar4 = read_volatile_4(Peripherals::PROTIMER.WRAPCNT);
    uVar3 = read_volatile_4(Peripherals::PROTIMER.WRAPCNTTOP);
    if (param_3 == 1) {
      param_2 = param_2 + uVar4 + 1;
    }
    uVar8 = uVar3 + 1;
    uVar3 = (uint)(0xfffffffe < uVar3);
    while( true ) {
      bVar9 = uVar3 == 0;
      if (uVar3 == 0) {
        bVar9 = uVar8 <= param_2;
      }
      if (!bVar9) break;
      param_2 = param_2 - uVar8;
    }
    uVar2 = PROTIMER_ElapsedTime(param_2,uVar4);
    if (uVar2 <= (uVar8 >> 2 | uVar3 << 0x1e)) {
LAB_0000c5c0:
      CORE_ExitCritical(irqState);
      return 0;
    }
    uVar8 = read_volatile_4(Peripherals::PROTIMER.TXCTRL);
    uVar3 = read_volatile_4(Peripherals::PROTIMER.RXCTRL);
    uVar2 = (param_1 + 9) * 0x100 | 1;
    if ((uVar8 & 0x1f1f) == uVar2) {
      uVar8 = 4;
    }
    else {
      uVar8 = 0;
    }
    uVar1 = read_volatile_4(Peripherals::PROTIMER.RXCTRL);
    if ((uVar3 & 0x1f1f0000) == ((param_1 + 9) * 0x1000000 | 0x10000)) {
      uVar8 = uVar8 | 2;
    }
    if ((uVar1 & 0x1f1f) == uVar2) {
      uVar8 = uVar8 | 1;
    }
    puVar5 = (uint *)(uVar8 & 1);
    puVar6 = puVar5;
    if (puVar5 != (uint *)0x0) {
      puVar6 = &PROTIMER_scheduledRxEnable;
    }
    if (puVar5 != (uint *)0x0) {
      *puVar6 = param_2;
    }
    (&Peripherals::PROTIMER.CC0_WRAP)[param_1 * 4] = param_2;
    (&Peripherals::PROTIMER.CC0_CTRL)[param_1 * 4] = 0x11;
    uVar3 = read_volatile_4(Peripherals::PROTIMER.WRAPCNT);
    uVar3 = PROTIMER_ElapsedTime(uVar4,uVar3,0x11,param_1 * 0x10 + 0x40085070,uVar10,puVar5,iVar11);
    uVar2 = PROTIMER_ElapsedTime(uVar4,param_2);
    uVar4 = read_volatile_4(Peripherals::PROTIMER.IF);
    if ((uVar2 <= uVar3) && (uVar3 = 0x100 << (param_1 & 0xff), (uVar3 & uVar4) == 0)) {
      if (param_3 == 0) {
        PROTIMER_CCTimerStop(param_1);
        goto LAB_0000c5c0;
      }
      write_volatile_4(Peripherals::PROTIMER.IFS,uVar3);
      if (puVar5 != (uint *)0x0) {
        write_volatile_4(Peripherals::PROTIMER_CLR.RXCTRL,0x1f1f);
        write_volatile_4(Peripherals::PROTIMER_SET.RXCTRL,0x101);
        write_volatile_4(Peripherals::PROTIMER_CLR.RXCTRL,0x1f1f);
      }
      uVar4 = uVar8 << 0x1e;
      if ((int)uVar4 < 0) {
        uVar4 = 0x1f1f0000;
        write_volatile_4(Peripherals::PROTIMER_CLR.RXCTRL,0x1f1f0000);
        write_volatile_4(Peripherals::PROTIMER_SET.RXCTRL,0x1010000);
        write_volatile_4(Peripherals::PROTIMER_CLR.RXCTRL,0x1f1f0000);
      }
      pRVar7 = (RAC *)(uVar8 << 0x1d);
      bVar9 = (int)pRVar7 < 0;
      if (bVar9) {
        pRVar7 = &Peripherals::RAC;
        uVar4 = 1;
      }
      if (bVar9) {
        pRVar7->CMD = uVar4;
      }
    }
  }
  CORE_ExitCritical(irqState);
  return 1;
}



void PROTIMER_WrapMultiple(uint param_1,undefined4 param_2,uint param_3,int param_4)

{
  bool bVar1;
  
  while( true ) {
    bVar1 = param_4 == 0;
    if (param_4 == 0) {
      bVar1 = param_3 <= param_1;
    }
    if (!bVar1) break;
    param_1 = param_1 - param_3;
  }
  return;
}



bool PROTIMER_CCTimerIsEnabled(uint8_t timer)

{
  return (bool)((byte)(&Peripherals::PROTIMER.CC0_CTRL)[(uint)timer * 4] & 1);
}



void PROTIMER_CCTimerCapture(int param_1,uint param_2)

{
  (&Peripherals::PROTIMER.CC0_CTRL)[param_1 * 4] = param_2 & 0xe00000 | 3;
  return;
}



void PROTIMER_ScheduleTxEnable(uint32_t param_1,undefined4 param_2,undefined4 param_3)

{
  PROTIMER_CCTimerStop(param_1);
  write_volatile_4(Peripherals::PROTIMER.TXCTRL,(param_1 + 9) * 0x100 | 1);
  PROTIMER_CCTimerStart(param_1,param_2,param_3);
  return;
}



void PROTIMER_ClearTxEnable(void)

{
  write_volatile_4(Peripherals::PROTIMER.TXCTRL,0);
  return;
}



void PROTIMER_ScheduleRxEnable(uint32_t param_1,undefined4 param_2,undefined4 param_3)

{
  PROTIMER_CCTimerStop(param_1);
  write_volatile_4(Peripherals::PROTIMER.RXCTRL,(param_1 + 9) * 0x100 | 0x10001);
  PROTIMER_CCTimerStart(param_1,param_2,param_3);
  return;
}



void PROTIMER_ScheduleRxDisable(uint32_t param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  PROTIMER_CCTimerStop(param_1);
  uVar1 = read_volatile_4(Peripherals::PROTIMER.RXCTRL);
  write_volatile_4(Peripherals::PROTIMER.RXCTRL,
                   uVar1 & 0xe0e0ffff | 0x10000 | (param_1 + 9) * 0x1000000);
  PROTIMER_CCTimerStart(param_1,param_2,param_3);
  return;
}



void PROTIMER_ClearRxEnable(void)

{
  write_volatile_4(Peripherals::PROTIMER.RXCTRL,0x1010000);
  return;
}



uint PROTIMER_GetTime(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::PROTIMER.WRAPCNT);
  return uVar1;
}



uint32_t PROTIMER_GetCCTime(uint32_t timer)

{
  return (&Peripherals::PROTIMER.CC0_WRAP)[timer * 4];
}



void PROTIMER_LBTUseLastConfig(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::PROTIMER.TOUT0COMP);
  if (uVar1 == 0) {
    write_volatile_4(Peripherals::RAC_SET.RXENSRCEN,0x10);
  }
  write_volatile_4(Peripherals::PROTIMER.RXCTRL,0x18011b01);
  write_volatile_4(Peripherals::PROTIMER.TXCTRL,0x1401);
  return;
}



void PROTIMER_LBTStart(void)

{
  PTI_AuxdataOutput(0x21);
  write_volatile_4(Peripherals::PROTIMER.CMD,0x10000);
  return;
}



void PROTIMER_LBTStop(void)

{
  PTI_AuxdataOutput(0x22);
  write_volatile_4(Peripherals::PROTIMER.CMD,0x40000);
  return;
}



bool PROTIMER_LBTIsActive(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::PROTIMER.STATUS);
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
  char cVar1;
  uint64_t uVar2;
  
  cVar1 = PROTIMER_IsRunning();
  if ((bool)cVar1 != false) {
    PROTIMER_Stop();
    cVar1 = '\x01';
  }
  PROTIMER_Reset();
  uVar2 = PROTIMER_UsToPrecntOverflow(time);
  write_volatile_4(Peripherals::PROTIMER.WRAPCNT,(uint)uVar2);
  if (cVar1 != '\0') {
    PROTIMER_Start((uint)uVar2,(int)(uVar2 >> 0x20));
  }
  return true;
}



void PROTIMER_LBTCfgSet(int param_1,uint param_2,int param_3,uint param_4,byte param_5,byte param_6)

{
  uint uVar1;
  uint64_t uVar2;
  
  uVar1 = read_volatile_4(Peripherals::PROTIMER.CTRL);
  write_volatile_4(Peripherals::PROTIMER.CTRL,uVar1 & 0xff0fffff | 0x900000);
  if (param_4 == 0) {
    write_volatile_4(Peripherals::PROTIMER.RXCTRL,0);
    param_2 = param_4;
  }
  param_2 = (uint)param_6 << 8 | (uint)param_5 << 0x18 | param_3 << 4 | param_4 << 0x10 | param_2;
  write_volatile_4(Peripherals::PROTIMER.LBTCTRL,param_2);
  uVar1 = read_volatile_4(Peripherals::PROTIMER.BASECNTTOP);
  RAILInt_Assert(uVar1 < 0x100,0x18,param_2,param_5,param_4);
  write_volatile_4(Peripherals::PROTIMER.TOUT0CNTTOP,uVar1);
  if (param_4 != 0) {
    uVar2 = PROTIMER_UsToPrecntOverflow((uint)*(ushort *)(param_1 + 0x10));
    if (uVar1 < (uint)uVar2) {
      write_volatile_4(Peripherals::RAC_SET.RXENSRCEN,0x10);
      write_volatile_4(Peripherals::PROTIMER.TOUT0COMP,0);
    }
    else {
      write_volatile_4(Peripherals::PROTIMER.TOUT0COMP,(uint)uVar2);
    }
    write_volatile_4(Peripherals::PROTIMER.RXCTRL,0x18011b01);
  }
  write_volatile_4(Peripherals::PROTIMER.TXCTRL,0x1401);
  return;
}



void PROTIMER_DelayUs(uint32_t us)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint64_t uVar8;
  
  uVar8 = PROTIMER_UsToPrecntOverflow(us);
  uVar5 = (uint)uVar8;
  uVar6 = read_volatile_4(Peripherals::PROTIMER.WRAPCNT);
  uVar2 = read_volatile_4(Peripherals::PROTIMER.WRAPCNTTOP);
  bVar3 = PROTIMER_IsRunning();
  if (bVar3 != false) {
    while( true ) {
      uVar7 = uVar5;
      if (uVar2 >> 1 <= uVar5) {
        uVar7 = uVar2 >> 1;
      }
      do {
        uVar1 = read_volatile_4(Peripherals::PROTIMER.WRAPCNT);
        uVar4 = PROTIMER_ElapsedTime(uVar6,uVar1);
      } while (uVar4 < uVar7);
      if (uVar5 <= uVar4) break;
      uVar5 = uVar5 - uVar4;
      uVar6 = uVar1;
    }
  }
  return;
}



uint PROTIMER_CheckCcaReallyFailed(uint param_1)

{
  uint uVar1;
  uint uVar2;
  CORE_irqState_t irqState;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  irqState = CORE_EnterAtomic();
  if ((param_1 & 0x600000) != 0) {
    uVar4 = read_volatile_4(Peripherals::AGC.RSSI);
    uVar4 = uVar4 << 0x10;
    uVar5 = uVar4 >> 0x16;
    uVar1 = read_volatile_4(Peripherals::RAC.STATUS);
    uVar2 = read_volatile_4(Peripherals::AGC.CTRL1);
    if ((int)uVar4 < 0) {
      uVar5 = ~(uVar4 & 0xffc00000);
    }
    uVar3 = uVar2 & 0xff;
    if ((int)uVar4 < 0) {
      uVar5 = ~(uVar5 >> 0x16);
    }
    if ((int)(uVar2 << 0x18) < 0) {
      uVar3 = uVar3 | 0xffffff00;
    }
    uVar4 = read_volatile_4(Peripherals::PROTIMER.IF);
    if ((((((int)(uVar3 + 0x46) < 0 == SCARRY4(uVar3,0x46)) && (uVar5 != 0xfffffe00)) &&
         (uVar5 == uVar3 * 4 || (int)(uVar5 + uVar3 * -4) < 0 != SBORROW4(uVar5,uVar3 * 4))) &&
        (((uVar1 & 0xf000000) == 0x4000000 || ((uVar1 & 0xd000000) == 0)))) &&
       (-1 < (int)(uVar4 << 0xb))) {
      PROTIMER_LBTStop();
      uVar1 = read_volatile_4(Peripherals::PROTIMER.IF);
      if (-1 < (int)(uVar1 << 0xb)) {
        write_volatile_4(Peripherals::RAC.CMD,1);
        uVar1 = read_volatile_4(Peripherals::PROTIMER.RXCTRL);
        write_volatile_4(Peripherals::PROTIMER.RXCTRL,0x1010000);
        write_volatile_4(Peripherals::PROTIMER.RXCTRL,uVar1);
        write_volatile_4(Peripherals::PROTIMER.IFC,0x700000);
        if (((int)(param_1 << 10) < 0) &&
           (uVar1 = read_volatile_4(Peripherals::PROTIMER.LBTSTATE), (uVar1 & 0xf000000) != 0)) {
          uVar1 = read_volatile_4(Peripherals::PROTIMER.LBTSTATE);
          write_volatile_4(Peripherals::PROTIMER.LBTSTATE,uVar1 - 0x1000000);
        }
        param_1 = param_1 & 0xff9fffff | 0x100000;
        PTI_AuxdataOutput(0x2c);
      }
    }
  }
  CORE_ExitAtomic(irqState);
  return param_1;
}



RAIL_Status_t_enum PTI_Config(RAIL_PtiConfig_t *ptiConfig)

{
  uint uVar1;
  uint32_t uVar2;
  undefined4 *puVar3;
  RAIL_PtiConfig_t *pRVar4;
  
  if (ptiConfig == (RAIL_PtiConfig_t *)0x0) {
    return RAIL_STATUS_INVALID_PARAMETER;
  }
  puVar3 = &ptiState;
  pRVar4 = ptiConfig;
  do {
    uVar2 = pRVar4->baud;
    *puVar3 = *(undefined4 *)pRVar4;
    puVar3[1] = uVar2;
    puVar3 = puVar3 + 2;
    pRVar4 = (RAIL_PtiConfig_t *)&pRVar4->doutLoc;
  } while (pRVar4 != (RAIL_PtiConfig_t *)&ptiConfig->dframePin);
  *puVar3 = *(undefined4 *)pRVar4;
  RADIOCMU_ClockEnable(0x63400,true);
  CMU_ClockEnable(cmuClock_GPIO,true);
  write_volatile_4(Peripherals::FRC.SNIFFCTRL,0xf8);
  write_volatile_4(Peripherals::FRC.ROUTELOC0,
                   (uint)ptiConfig->dframeLoc << 0x10 | (uint)ptiConfig->dclkLoc << 8 |
                   (uint)ptiConfig->doutLoc);
  uVar1 = (uint)ptiConfig->mode;
  if (uVar1 == 1) {
    sniffMode = 2;
    write_volatile_4(Peripherals::FRC.ROUTEPEN,7);
    GPIO_PinModeSet(ptiConfig->dclkPort,(uint)ptiConfig->dclkPin,gpioModePushPull,0);
  }
  else {
    if (uVar1 != 2) {
      if (uVar1 != 3) {
        if (uVar1 != 0) {
          return RAIL_STATUS_INVALID_PARAMETER;
        }
        write_volatile_4(Peripherals::FRC.ROUTEPEN,0);
        sniffMode = uVar1;
        return (RAIL_Status_t_enum)ptiConfig->mode;
      }
      sniffMode = 5;
      write_volatile_4(Peripherals::FRC.ROUTEPEN,1);
      goto LAB_0000cade;
    }
    sniffMode = 1;
    write_volatile_4(Peripherals::FRC.ROUTEPEN,5);
  }
  GPIO_PinModeSet(ptiConfig->dframePort,(uint)ptiConfig->dframePin,gpioModePushPull,0);
LAB_0000cade:
  GPIO_PinModeSet(ptiConfig->doutPort,(uint)ptiConfig->doutPin,gpioModePushPull,1);
  return RAIL_STATUS_NO_ERROR;
}



void PTI_EnableAppendedInfo(int param_1)

{
  RAC_SET *pRVar1;
  
  if (param_1 == 0) {
    pRVar1 = (RAC_SET *)&Peripherals::RAC_CLR;
  }
  else {
    pRVar1 = &Peripherals::RAC_SET;
  }
  ((RAC_CLR *)pRVar1)->SR3 = 0x40000000;
  return;
}



RAIL_Status_t_enum PTI_Enable(bool enable)

{
  int iVar1;
  uint uVar2;
  
  if (enable == false) {
    write_volatile_4(Peripherals::FRC_CLR.SNIFFCTRL,3);
  }
  else {
    uVar2 = DAT_2000448c;
    if (DAT_2000448c != 0) {
      iVar1 = RADIOCMU_ClockFreqGet(0x63400);
      uVar2 = ((iVar1 + (DAT_2000448c >> 1)) / DAT_2000448c - 1) * 0x100;
    }
    write_volatile_4(Peripherals::FRC_CLR.SNIFFCTRL,0xff03);
    write_volatile_4(Peripherals::FRC_SET.SNIFFCTRL,uVar2 | sniffMode);
  }
  PTI_EnableAppendedInfo(enable);
  return RAIL_STATUS_NO_ERROR;
}



void PTI_AuxdataOutput(uint param_1)

{
  FRC *pFVar1;
  bool bVar2;
  
  pFVar1 = (FRC *)read_volatile_4(Peripherals::RAC.SR3);
  bVar2 = (int)pFVar1 < 0;
  if (bVar2) {
    pFVar1 = &Peripherals::FRC;
  }
  if (bVar2) {
    pFVar1->AUXDATA = param_1;
  }
  return;
}



void PTI_EnableSyncword(int param_1)

{
  RAC_SET *pRVar1;
  
  if (param_1 == 0) {
    pRVar1 = (RAC_SET *)&Peripherals::RAC_CLR;
  }
  else {
    pRVar1 = &Peripherals::RAC_SET;
  }
  ((RAC_CLR *)pRVar1)->SR3 = 0x8000000;
  return;
}



void RADIO_SetAndForgetWrite(undefined4 param_1,uint param_2,undefined4 param_3)

{
  undefined4 local_c;
  undefined4 uStack8;
  
  local_c = param_2;
  uStack8 = param_3;
  SYSTEM_ChipRevisionGet((SYSTEM_ChipRevision_TypeDef *)&local_c);
  write_volatile_4(Peripherals::RAC.IFADCCTRL,0x5153e6c0);
  write_volatile_4(Peripherals::RAC.IFPGACTRL,0x87e6);
  write_volatile_4(Peripherals::RAC.LNAMIXCTRL1,0x880);
  write_volatile_4(Peripherals::RAC.VCOCTRL,0xf00277a);
  if ((local_c._1_1_ == '\x01') && ((local_c & 0xff) < 2)) {
    write_volatile_4(Peripherals::SYNTH.VCOGAIN,0x28);
  }
  write_volatile_4(Peripherals::SYNTH.CTRL,0xac3f);
  write_volatile_4(Peripherals::AGC.MANGAIN,0x1800000);
  write_volatile_4(Peripherals::RAC.LNAMIXCTRL,0);
  write_volatile_4(Peripherals::RAC.SYNTHREGCTRL,0x3636d80);
  write_volatile_4(Peripherals::SYNTH_CLR.VCDACCTRL,0x7f);
  write_volatile_4(Peripherals::SYNTH_SET.VCDACCTRL,0x23);
  return;
}



void RADIO_SeqInit(void *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  write_volatile_4(Peripherals::RAC_SET.CTRL,1);
  do {
    uVar1 = read_volatile_4(Peripherals::RAC.STATUS);
  } while ((uVar1 << 4) >> 0x1c != 0);
  write_volatile_4(Peripherals::RAC.VECTADDR,0x21000000);
  write_volatile_4(Peripherals::RAC.SEQCTRL,1);
  memcpy((void *)0x21000000,param_1,param_2 << 2);
  write_volatile_4(Peripherals::RAC.R6,0x21000fb8);
  uVar1 = read_volatile_4(Peripherals::SEQ.REG0E0);
  uVar2 = read_volatile_4(Peripherals::SEQ.REG0E4);
  uVar3 = read_volatile_4(Peripherals::SEQ.REG0E8);
  memset(&Peripherals::SEQ.REG07C,0,0x84);
  write_volatile_4(Peripherals::SEQ.REG0E0,uVar1);
  write_volatile_4(Peripherals::SEQ.REG0E4,uVar2);
  write_volatile_4(Peripherals::SEQ.REG0E8,uVar3);
  return;
}



void RADIO_CLKEnable(void)

{
  RADIOCMU_ClockEnable(0x63400,true);
  RADIOCMU_ClockEnable(0x60400,true);
  RADIOCMU_ClockEnable(0x64400,true);
  RADIOCMU_ClockEnable(0x67400,true);
  RADIOCMU_ClockEnable(0x66400,true);
  RADIOCMU_ClockEnable(0x65400,true);
  RADIOCMU_ClockEnable(0x62400,true);
  RADIOCMU_ClockEnable(0x68400,true);
  return;
}



void RADIO_Init(void)

{
  RADIO_CLKEnable();
  RADIO_SetAndForgetWrite();
  write_volatile_4(Peripherals::MODEM_SET.DCCOMP,3);
  write_volatile_4(Peripherals::RAC.SR3,0x80000);
  write_volatile_4(Peripherals::RAC_SET.SR3,1);
  SYNTH_KvnFreqCompensationEnable();
  write_volatile_4(Peripherals::RAC_SET.CTRL,0x380);
  return;
}



void RADIO_Config(undefined4 param_1,uint *param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  
switchD_0000cd90_caseD_8:
  while( true ) {
    if ((param_2 == (uint *)0x0) || (uVar3 = *param_2, uVar3 == 0xffffffff)) {
      bVar1 = PA_UpdateConfig(param_1);
      TIMING_SeqTimingInit(bVar1);
      return;
    }
    uVar2 = (uVar3 << 8) >> 0x18;
    puVar5 = (uint *)(uVar3 & 0xffff | (uint)(&regBases)[(uVar3 << 4) >> 0x1c]);
    uVar4 = uVar2;
    puVar6 = param_2;
    if (uVar2 < 2) break;
    do {
      uVar4 = uVar4 - 1;
      *(uint *)(((int)puVar5 - (int)param_2) + (int)puVar6) = puVar6[1];
      puVar6 = puVar6 + 1;
    } while (uVar4 != 0);
    param_2 = param_2 + uVar2 + 1;
  }
  puVar6 = param_2 + 2;
  uVar4 = param_2[1];
  param_2 = puVar6;
  switch(uVar3 >> 0x1c) {
  case 0:
    break;
  case 1:
    uVar4 = ~uVar4;
    puVar5 = puVar5 + 0x1000000;
    break;
  case 2:
    uVar4 = uVar4 ^ *puVar5;
    break;
  case 3:
    puVar5 = puVar5 + 0x1800000;
    break;
  case 4:
    PROTIMER_DelayUs(uVar4);
    goto switchD_0000cd90_caseD_8;
  case 5:
    puVar5 = puVar5 + 0x1800000;
    goto LAB_0000cdca;
  case 6:
    puVar5 = puVar5 + 0x1000000;
LAB_0000cdca:
    *puVar5 = 1 << (uVar4 & 0xff);
    goto switchD_0000cd90_caseD_8;
  case 7:
    do {
    } while ((*puVar5 & uVar4) != uVar4);
  default:
    goto switchD_0000cd90_caseD_8;
  }
  *puVar5 = uVar4;
  goto switchD_0000cd90_caseD_8;
}



bool RADIO_IsRxOnForRssi(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::RAC.STATUS);
  return ((uVar1 << 4) >> 0x1c) - 2 < 2;
}



int RADIO_RxTrailDataLength(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = read_volatile_4(Peripherals::FRC.TRAILRXDATA);
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



void RADIO_FrameControlDescrBufferIdSet(uint32_t fcd,uint32_t id)

{
  (&Peripherals::FRC_CLR.FCD0)[fcd] = 0x300;
  (&Peripherals::FRC_SET.FCD0)[fcd] = id << 8;
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



uint32_t RADIO_ComputeTxBaudrate(void)

{
  uint uVar1;
  uint32_t uVar2;
  
  uVar2 = CMU_ClockFreqGet(cmuClock_HF);
  uVar1 = read_volatile_4(Peripherals::MODEM.TXBR);
  if ((uVar1 & 0xffff) != 0) {
    return (((uVar1 << 8) >> 0x18) * (uVar2 >> 3)) / (uVar1 & 0xffff);
  }
  return 0;
}



uint32_t RADIO_ComputeRxBaudrate(void)

{
  uint uVar1;
  uint32_t uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = read_volatile_4(Peripherals::MODEM.CF);
  uVar4 = read_volatile_4(Peripherals::MODEM.RXBR);
  iVar3 = ((uVar1 << 9) >> 0x1a) + 1;
  uVar5 = (uVar4 << 0x16) >> 0x1b;
  uVar4 = (((uVar1 << 0xf) >> 0x12) * iVar3 + iVar3) * 2 *
          (uVar5 * ((uVar4 << 0x13) >> 0x1d) + (uVar4 & 0x1f)) *
          (uint)(byte)(&modemCfDec0Factors)[uVar1 & 7];
  if (uVar4 != 0) {
    uVar2 = CMU_ClockFreqGet(cmuClock_HF);
    return (uVar5 * uVar2) / uVar4;
  }
  return 0;
}



uint32_t RADIO_ComputeTxSymbolRate(RAIL_Handle_t railHandle)

{
  uint uVar1;
  uint32_t uVar2;
  
  uVar2 = RADIO_ComputeTxBaudrate();
  uVar1 = read_volatile_4(Peripherals::MODEM.CTRL0);
  if ((uVar1 & 0x30) == 0x10) {
    return uVar2 >> 1;
  }
  if ((uVar1 & 0x30) != 0x20) {
    return uVar2;
  }
  return uVar2 / (((uVar1 << 0x10) >> 0x1b) + 1);
}



uint32_t RADIO_ComputeTxBitRate(RAIL_Handle_t railHandle)

{
  uint uVar1;
  uint32_t uVar2;
  uint uVar3;
  
  uVar1 = read_volatile_4(Peripherals::MODEM.CTRL0);
  if ((uVar1 & 0x30) == 0x20) {
    uVar3 = (uVar1 << 0xd) >> 0x1d;
    if (uVar3 != 0) {
      uVar3 = ((uVar1 << 0x10) >> 0x1b) / uVar3;
    }
    if ((uVar1 & 0x180000) != 0) {
      uVar3 = uVar3 << 1;
    }
    uVar3 = uVar3 >> 1;
    if (2 < uVar3) {
      uVar3 = 4;
    }
  }
  else {
    uVar1 = read_volatile_4(Peripherals::MODEM.CTRL0);
    if (((uVar1 & 0x1c0) == 0x40) || ((uVar1 & 0x1c0) == 0x100)) {
      uVar3 = 2;
    }
    else {
      uVar3 = 1;
    }
  }
  uVar2 = RADIO_ComputeTxSymbolRate(railHandle);
  return uVar3 * uVar2;
}



int16_t RADIO_GetRssi(bool wait)

{
  CORE_irqState_t irqState;
  int iVar1;
  uint uVar2;
  int iVar4;
  int16_t iVar5;
  uint uVar3;
  
  do {
    irqState = CORE_EnterCritical();
    iVar1 = RADIO_IsRxOnForRssi();
    uVar2 = read_volatile_4(Peripherals::AGC.RSSI);
    uVar2 = uVar2 << 0x10;
    uVar3 = uVar2 >> 0x16;
    if ((int)uVar2 < 0) {
      uVar3 = ~(uVar2 & 0xffc00000);
    }
    if ((int)uVar2 < 0) {
      uVar3 = ~(uVar3 >> 0x16);
    }
    iVar5 = (int16_t)(uVar3 & 0xffff);
    iVar4 = RADIO_IsRxOnForRssi();
    if (iVar4 == 0) {
      iVar1 = 0;
    }
    CORE_ExitCritical(irqState);
    if ((uVar3 & 0xffff) != 0xfe00) {
      if (iVar1 == 0) {
        iVar5 = -0x200;
      }
      return iVar5;
    }
    if (iVar1 == 0) {
      return iVar5;
    }
  } while (wait != false);
  return iVar5;
}



undefined4 RADIO_SetAgcCcaParams(int param_1,byte param_2)

{
  uint32_t uVar1;
  uint uVar2;
  
  uVar1 = RADIO_ComputeRxBaudrate();
  for (uVar2 = 0; (uint)(1 << (uVar2 & 0xff)) < (param_1 * uVar1) / 1000000; uVar2 = uVar2 + 1) {
    if (uVar2 == 0x10) {
      return 1;
    }
  }
  write_volatile_4(Peripherals::AGC_CLR.CTRL1,0xf00);
  write_volatile_4(Peripherals::AGC_SET.CTRL1,uVar2 << 8);
  uVar2 = read_volatile_4(Peripherals::AGC.CTRL1);
  if ((uVar2 & 0xff) == 0x80) {
    return 2;
  }
  write_volatile_4(Peripherals::AGC_CLR.CTRL1,0xff);
  write_volatile_4(Peripherals::AGC_SET.CTRL1,(uint)param_2);
  return 0;
}



void RADIO_ComputeAgcSampleRate(void)

{
  undefined uVar1;
  uint uVar2;
  uint uVar3;
  uint32_t uVar4;
  undefined8 uVar5;
  
  uVar2 = read_volatile_4(Peripherals::MODEM.CF);
  uVar3 = read_volatile_4(Peripherals::MODEM.CF);
  uVar1 = (&modemCfDec0Factors)[uVar2 & 7];
  uVar2 = read_volatile_4(Peripherals::MODEM.CF);
  uVar4 = CMU_ClockFreqGet(cmuClock_HF);
  uVar5 = __aeabi_uldivmod((int)((ulonglong)uVar4 * 1000),(int)((ulonglong)uVar4 * 1000 >> 0x20),
                           uVar1,0);
  uVar5 = __aeabi_uldivmod((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),((uVar3 << 0xf) >> 0x12) + 1,0
                          );
  __aeabi_uldivmod((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),((uVar2 << 9) >> 0x1a) + 1,0);
  return;
}



undefined4 RADIO_SetRssiPeriod(uint param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  
  uVar7 = RADIO_ComputeAgcSampleRate();
  if (uVar7 == 0) {
    RAILInt_Assert(0,0x2b);
    uVar7 = 1;
  }
  iVar6 = (int)(uVar7 >> 0x20);
  uVar2 = __aeabi_uldivmod(0xdb000000,0x7558b,(int)uVar7,iVar6);
  if (uVar2 < param_1) {
    return 1;
  }
  lVar1 = (uVar7 & 0xffffffff) * (ulonglong)param_1;
  uVar5 = (undefined4)lVar1;
  iVar6 = param_1 * iVar6 + (int)((ulonglong)lVar1 >> 0x20);
  uVar3 = __aeabi_uldivmod(uVar5,iVar6,1000000000,0);
  uVar2 = 1;
  do {
    uVar4 = uVar2 + 1;
    if (uVar3 <= (uint)(1 << (uVar4 & 0xff))) goto LAB_0000d122;
    uVar2 = uVar4;
  } while (uVar4 != 0x10);
  uVar2 = 0xf;
LAB_0000d122:
  write_volatile_4(Peripherals::AGC_SET.CTRL1,0x8000);
  write_volatile_4(Peripherals::AGC_CLR.CTRL1,0xf00);
  write_volatile_4(Peripherals::AGC_SET.CTRL1,uVar2 << 8);
  __aeabi_uldivmod(uVar5,iVar6,10000000,0);
  uVar8 = __aeabi_uldivmod();
  iVar6 = __aeabi_uldivmod((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),100,0);
  uVar2 = ((int)uVar8 + iVar6 * -100 & 0xffU) / 3;
  if (uVar2 < 0x20) {
    if (uVar2 == 0) {
      uVar2 = read_volatile_4(Peripherals::AGC.CTRL1);
      write_volatile_4(Peripherals::AGC.CTRL1,uVar2 & 0xffe0ffff | 0x10000);
      uVar2 = read_volatile_4(Peripherals::AGC.CTRL1);
      write_volatile_4(Peripherals::AGC.CTRL1,uVar2 & 0xfc1fffff | 0x200000);
      return 0;
    }
  }
  else {
    uVar2 = 0x1f;
  }
  uVar3 = read_volatile_4(Peripherals::AGC.CTRL1);
  write_volatile_4(Peripherals::AGC.CTRL1,uVar3 & 0x3ffffff | iVar6 << 0x1a);
  uVar3 = read_volatile_4(Peripherals::AGC.CTRL1);
  write_volatile_4(Peripherals::AGC.CTRL1,uVar3 & 0xffe0ffff | uVar2 << 0x10);
  uVar2 = read_volatile_4(Peripherals::AGC.CTRL1);
  write_volatile_4(Peripherals::AGC.CTRL1,uVar2 | 0x3e00000);
  return 0;
}



void RADIO_SetCRCInitVal(uint param_1)

{
  write_volatile_4(Peripherals::CRC.INIT,param_1);
  write_volatile_4(Peripherals::CRC.CMD,1);
  return;
}



void RADIO_RACClearRxOverflow(void)

{
  uint uVar1;
  
  do {
    uVar1 = read_volatile_4(Peripherals::RAC.STATUS);
    if ((uVar1 & 0xf000000) != 0x6000000) break;
    uVar1 = read_volatile_4(Peripherals::RAC.SEQSTATUS);
  } while (-1 < (int)(uVar1 << 0x1b));
  write_volatile_4(Peripherals::RAC.CMD,0x40);
  return;
}



void RFTEST_SaveRadioConfiguration(void)

{
  if (testModeRegisterState == false) {
    DAT_200044a0 = read_volatile_4(Peripherals::MODEM.CTRL0);
    DAT_200044a4 = read_volatile_4(Peripherals::MODEM.MODINDEX);
    DAT_200044a8 = read_volatile_4(Peripherals::MODEM.PRE);
    DAT_200044ac = read_volatile_4(Peripherals::FRC.DFLCTRL);
    DAT_200044b0 = read_volatile_4(Peripherals::FRC.FECCTRL);
    DAT_200044b4 = read_volatile_4(Peripherals::FRC.FCD0);
    DAT_200044b8 = read_volatile_4(Peripherals::FRC.FCD1);
    DAT_200044bc = read_volatile_4(Peripherals::FRC.WHITECTRL);
    DAT_200044c0 = read_volatile_4(Peripherals::FRC.WHITEPOLY);
    DAT_200044c4 = read_volatile_4(Peripherals::FRC.WHITEINIT);
    DAT_200044c8 = read_volatile_4(Peripherals::SEQ.SYNTHLPFCTRLTX);
    testModeRegisterState = true;
  }
  return;
}



void RFTEST_StartCwTx(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.SYNTHLPFCTRLTX);
  write_volatile_4(Peripherals::SEQ.SYNTHLPFCTRLTX,uVar1 & 0xfffffff0);
  uVar1 = read_volatile_4(Peripherals::MODEM.CTRL0);
  uVar2 = uVar1 & 0x1c0;
  if (uVar2 == 0xc0) {
    write_volatile_4(Peripherals::MODEM.CTRL0,uVar1 & 0xfffffe3f | 0x80);
  }
  else {
    if ((uVar2 != 0x180) && (uVar2 != 0x80)) {
      write_volatile_4(Peripherals::MODEM.MODINDEX,0);
    }
  }
  write_volatile_4(Peripherals::MODEM_SET.PRE,0xffff000f);
  write_volatile_4(Peripherals::MODEM_CLR.PRE,0x30);
  write_volatile_4(Peripherals::FRC.DFLCTRL,5);
  write_volatile_4(Peripherals::FRC_SET.CTRL,1);
  write_volatile_4(Peripherals::RAC.CMD,1);
  return;
}



void RFTEST_StartStreamTx(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::FRC.FCD0);
  write_volatile_4(Peripherals::FRC.FCD0,uVar1 & 0xffffbfff);
  uVar1 = read_volatile_4(Peripherals::FRC.FCD1);
  write_volatile_4(Peripherals::FRC.FCD1,uVar1 & 0xffffbfff);
  write_volatile_4(Peripherals::FRC.FECCTRL,1);
  write_volatile_4(Peripherals::FRC.WHITECTRL,0x24);
  write_volatile_4(Peripherals::FRC.WHITEPOLY,0x100);
  write_volatile_4(Peripherals::FRC.WHITEINIT,0x138);
  write_volatile_4(Peripherals::FRC_CLR.SNIFFCTRL,0x10);
  write_volatile_4(Peripherals::FRC.DFLCTRL,5);
  write_volatile_4(Peripherals::FRC_SET.CTRL,1);
  write_volatile_4(Peripherals::RAC.CMD,1);
  return;
}



void RFTEST_StopTx(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  int iVar2;
  
  irqState = CORE_EnterCritical();
  uVar1 = read_volatile_4(Peripherals::RAC.STATUS);
  if ((uVar1 & 0x9000000) != 0) {
    write_volatile_4(Peripherals::RAC.CMD,0x20);
    uVar1 = read_volatile_4(Peripherals::FRC.DFLCTRL);
    if ((uVar1 & 7) == 5) {
      iVar2 = 0;
      do {
        uVar1 = read_volatile_4(Peripherals::FRC.IF);
        if ((int)(uVar1 << 0x1d) < 0) break;
        iVar2 = iVar2 + 1;
      } while (iVar2 != 0x10000);
    }
    write_volatile_4(Peripherals::FRC_SET.IFC,4);
  }
  CORE_ExitCritical(irqState);
  return;
}



void RFTEST_RestoreRadioConfiguration(void)

{
  if (testModeRegisterState != false) {
    RFTEST_StopTx();
    write_volatile_4(Peripherals::MODEM.CTRL0,DAT_200044a0);
    write_volatile_4(Peripherals::MODEM.MODINDEX,DAT_200044a4);
    write_volatile_4(Peripherals::MODEM.PRE,DAT_200044a8);
    write_volatile_4(Peripherals::FRC.DFLCTRL,DAT_200044ac);
    write_volatile_4(Peripherals::FRC.FECCTRL,DAT_200044b0);
    write_volatile_4(Peripherals::FRC.FCD0,DAT_200044b4);
    write_volatile_4(Peripherals::FRC.FCD1,DAT_200044b8);
    write_volatile_4(Peripherals::FRC.WHITECTRL,DAT_200044bc);
    write_volatile_4(Peripherals::FRC.WHITEPOLY,DAT_200044c0);
    write_volatile_4(Peripherals::FRC.WHITEINIT,DAT_200044c4);
    write_volatile_4(Peripherals::SEQ.SYNTHLPFCTRLTX,DAT_200044c8);
    write_volatile_4(Peripherals::FRC_CLR.CTRL,1);
    write_volatile_4(Peripherals::FRC_SET.SNIFFCTRL,0x10);
    testModeRegisterState = false;
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
    uVar1 = read_volatile_4(Peripherals::EMU.EM4CTRL);
    write_volatile_4(Peripherals::EMU.EM4CTRL,uVar1 & ~uVar2);
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

bool RFSENSE_Sensed(RAIL_Handle_t railHandle)

{
  code *pcVar1;
  int iVar2;
  CORE_irqState_t irqState;
  uint uVar3;
  
  iVar2 = _DAT_43c81904;
  write_volatile_4(Peripherals::CMU_SET.HFRADIOCLKEN0,2);
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
    write_volatile_4(Peripherals::CMU_CLR.HFRADIOCLKEN0,2);
  }
  return SUB41(uVar3,0);
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

bool RFSENSE_IRQHandler(RAIL_Handle_t railHandle)

{
  code *pcVar1;
  int iVar2;
  CORE_irqState_t irqState;
  uint uVar3;
  
  iVar2 = _DAT_43c81904;
  write_volatile_4(Peripherals::CMU_SET.HFRADIOCLKEN0,2);
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
    write_volatile_4(Peripherals::CMU_CLR.HFRADIOCLKEN0,2);
  }
  return SUB41(uVar3,0);
}



void RFSENSE_DeInit(void)

{
  RFSENSE_ReInit();
  write_volatile_4(Peripherals::CMU_CLR.HFRADIOCLKEN0,2);
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
  
  write_volatile_4(Peripherals::CMU_SET.HFRADIOCLKEN0,2);
  puVar7 = param_1;
  RFSENSE_ReInit();
  if (param_1 == (undefined4 *)0x0) {
LAB_0000d552:
    RFSENSE_DeInit();
    return 0;
  }
  bVar1 = *(byte *)(param_1 + 2);
  uVar5 = (uint)bVar1;
  if ((((bVar1 & 3) == 0) || (param_1[1] == 0)) ||
     (uVar2 = RFSENSE_CalcPeriod(uVar5,param_1[1],&stack0xffffffe6), uVar2 == 0)) goto LAB_0000d552;
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
  if (*(char *)((int)param_1 + 9) == '\0') goto LAB_0000d5ec;
  write_volatile_4(Peripherals::RFSENSE.EM4WUEN,1);
  uVar3 = uVar5 & 0xc;
  if (uVar3 == 8) {
    uVar3 = read_volatile_4(Peripherals::EMU.EM4CTRL);
    if (-1 < (int)(uVar3 << 0x1d)) {
      uVar3 = 4;
      goto LAB_0000d610;
    }
  }
  else {
    if (uVar3 == 0xc) {
      uVar3 = read_volatile_4(Peripherals::EMU.EM4CTRL);
      if (-1 < (int)(uVar3 << 0x1c)) {
        uVar3 = 8;
        goto LAB_0000d610;
      }
    }
    else {
      if ((uVar3 == 4) &&
         (uVar3 = read_volatile_4(Peripherals::EMU.EM4CTRL), -1 < (int)(uVar3 << 0x1e))) {
        uVar3 = 2;
LAB_0000d610:
        irqState = CORE_EnterCritical();
        uVar6 = read_volatile_4(Peripherals::EMU.EM4CTRL);
        write_volatile_4(Peripherals::EMU.EM4CTRL,uVar6 | uVar3);
        CORE_ExitCritical(irqState);
        em4Flag = uVar3;
        goto LAB_0000d5ec;
      }
    }
  }
  em4Flag = 0;
LAB_0000d5ec:
  write_volatile_4(Peripherals::RFSENSE.IEN,1);
  write_volatile_4(Peripherals::RFSENSE.CTRL,uVar5 & 0x2f);
  RFSENSE_Cb = *param_1;
  _DAT_e000e104 = 1;
  return uVar2;
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
  
  uVar1 = read_volatile_4(Peripherals::RAC.IFPGACTRL);
  return ((uVar1 ^ 0x10) << 0x1b) >> 0x1f;
}



bool SYNTH_VcoRangeIsValid(uint32_t freq)

{
  undefined uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = SYNTH_LoDivGet();
  if (uVar2 != 0) {
    if (2300000000 / uVar2 <= freq) {
      uVar2 = 2900000000 / uVar2;
      uVar3 = uVar2;
      if (uVar2 < freq) {
        uVar3 = 0;
      }
      uVar1 = (undefined)uVar3;
      if (freq <= uVar2) {
        uVar1 = 1;
      }
      return (bool)uVar1;
    }
    uVar2 = 0;
  }
  return SUB41(uVar2,0);
}



void SYNTH_RetimeLimitsConfig(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint32_t uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = SystemHFXOClockGet();
  if (uVar1 == 0) {
    RAILInt_Assert(0,0x2b);
    uVar1 = 1;
  }
  uVar2 = param_1 / uVar1;
  if (((param_1 - uVar1 * uVar2) * 100) / uVar1 == 0) {
    uVar2 = uVar2 - 1;
  }
  uVar4 = (uVar2 >> 1) - 1;
  uVar3 = (uVar2 + 1 >> 1) - 1;
  if (((7 < uVar4) || (7 < uVar3)) || ((uVar4 == 0 && (uVar3 == 0)))) {
    RAILInt_Assert(0,0x10,100,uVar2,param_4);
  }
  write_volatile_4(Peripherals::RAC_CLR.HFXORETIMECTRL,0x770);
  write_volatile_4(Peripherals::RAC_SET.HFXORETIMECTRL,uVar4 * 0x10 | uVar3 * 0x100);
  return;
}



void SYNTH_RetimeClkConfig(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_24;
  undefined4 uStack32;
  undefined local_1c;
  
  local_24 = 0x2010000;
  uStack32 = 0x3030302;
  local_1c = 3;
  uVar3 = read_volatile_4(Peripherals::SYNTH.CHCTRL);
  iVar2 = currChSpacing * uVar3 + currRfFrequency;
  uVar3 = read_volatile_4(Peripherals::SYNTH.IFFREQ);
  if ((uVar3 & 0x100000) == 0) {
    uVar3 = iVar2 - currIfFrequency;
  }
  else {
    uVar3 = iVar2 + currIfFrequency;
  }
  uVar4 = (uint)*(byte *)((int)&local_24 + uVar3 / 625000000 + 1);
  uVar3 = uVar3 >> uVar4;
  bVar1 = *(byte *)((int)&local_24 + uVar3 / 325000000 + 1);
  if (dcdcRetimeClkTarget == 0) {
    RAILInt_Assert(0,0x2b);
    dcdcRetimeClkTarget = 1;
  }
  write_volatile_4(Peripherals::RAC_CLR.MMDCTRL,0x3dff);
  write_volatile_4(Peripherals::RAC_SET.MMDCTRL,
                   (uVar3 + (dcdcRetimeClkTarget >> 1)) / dcdcRetimeClkTarget - 1 | uVar4 << 0xc |
                   (uint)bVar1 << 10);
  SYNTH_RetimeLimitsConfig(uVar3);
  return;
}



RAIL_Status_t_enum SYNTH_Config(uint32_t freq,uint32_t spacing)

{
  longlong lVar1;
  RAC_SET *pRVar2;
  bool bVar3;
  uint uVar4;
  uint32_t uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar4 = SYNTH_LoDivGet();
  bVar3 = SYNTH_VcoRangeIsValid(freq);
  if (bVar3 == false) {
    RAILInt_Assert(0,0xe);
  }
  else {
    if (uVar4 == 1) {
      pRVar2 = (RAC_SET *)&Peripherals::RAC_CLR;
    }
    else {
      pRVar2 = &Peripherals::RAC_SET;
    }
    ((RAC_CLR *)pRVar2)->IFPGACTRL = 0x10;
    uVar5 = SystemHFXOClockGet();
    if ((uVar4 != 0) && (uVar5 != 0)) {
      uVar7 = uVar4 * freq;
      currRfFrequency = freq;
      uVar6 = __aeabi_uldivmod(uVar7 * 0x80000,uVar7 >> 0xd,uVar5,0);
      write_volatile_4(Peripherals::SYNTH.FREQ,uVar6);
      uVar6 = read_volatile_4(Peripherals::SYNTH.IFFREQ);
      lVar1 = (ulonglong)uVar5 * (ulonglong)(uVar6 & 0xfffff);
      currIfFrequency = __aeabi_uldivmod((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),uVar4 << 0x13,0)
      ;
      lVar1 = (ulonglong)(spacing << 0x13) * (ulonglong)uVar4;
      currChSpacing = spacing;
      uVar4 = __aeabi_uldivmod((int)lVar1,uVar4 * (spacing >> 0xd) + (int)((ulonglong)lVar1 >> 0x20)
                               ,uVar5,0);
      write_volatile_4(Peripherals::SYNTH.CHSP,uVar4);
      if (vcoGainPte == 0) {
        uVar4 = read_volatile_4(Peripherals::SYNTH.VCOGAIN);
        vcoGainPte = (byte)uVar4 & 0x3f;
      }
      uVar4 = read_volatile_4(Peripherals::RAC.SR3);
      if ((int)(uVar4 << 0x19) < 0) {
        uVar7 = uVar7 / 24000000;
        uVar4 = uVar7 * uVar7 * 0x54d + uVar7 * -0xc60c + 0x192d50;
        if (uVar4 == 0) {
          RAILInt_Assert(0,0x2b);
          uVar4 = 1;
        }
        write_volatile_4(Peripherals::SYNTH.VCOGAIN,((uint)vcoGainPte * 10000000) / uVar4);
      }
      SYNTH_RetimeClkConfig();
      return RAIL_STATUS_NO_ERROR;
    }
  }
  return RAIL_STATUS_INVALID_STATE;
}



void SYNTH_ChannelSet(uint16_t channel,bool rxcal)

{
  uint uVar1;
  
  do {
    do {
      uVar1 = read_volatile_4(Peripherals::RAC.STATUS);
      uVar1 = (uVar1 << 4) >> 0x1c;
    } while (uVar1 == 4);
  } while (uVar1 == 10);
  uVar1 = count_leading_zeroes(uVar1);
  RAILInt_Assert(uVar1 >> 5,0xf);
  write_volatile_4(Peripherals::SYNTH.CHCTRL,(uint)channel);
  if (rxcal != false) {
    write_volatile_4(Peripherals::RAC.CMD,0x80);
  }
  SYNTH_RetimeClkConfig();
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void SYNTH_DCDCRetimeClkSet(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  write_volatile_4(Peripherals::RAC_SET.SR3,0x80000);
  dcdcRetimeClkTarget = param_1;
  if (_DAT_43c60980 != 0) {
    uVar1 = read_volatile_4(Peripherals::EMU.DCDCLNFREQCTRL);
    uVar2 = (param_1 + 500000U) / 1000000 - 3 & 0xff;
    if ((uVar1 & 7) != uVar2) {
      EMU_DCDCLnRcoBandSet((EMU_DcdcLnRcoBand_TypeDef)uVar2);
    }
    if (dcdcRetimeDesired != '\0') {
      write_volatile_4(Peripherals::RAC_CLR.SR3,0xf0000);
      write_volatile_4(Peripherals::RAC_SET.SR3,uVar2 << 0x10);
    }
  }
  return;
}



void SYNTH_DCDCRetimeEnable(void)

{
  dcdcRetimeDesired = 1;
  SYNTH_DCDCRetimeClkSet(dcdcRetimeClkTarget);
  return;
}



void SYNTH_DCDCRetimeDisable(void)

{
  write_volatile_4(Peripherals::RAC_SET.SR3,0x80000);
  dcdcRetimeDesired = 0;
  return;
}



void SYNTH_KvnFreqCompensationEnable(void)

{
  write_volatile_4(Peripherals::RAC_SET.SR3,0x40);
  return;
}



void RADIOCMU_ClockEnable(CMU_Clock_TypeDef clock,bool enable)

{
  uint uVar1;
  CMU *pCVar2;
  uint *puVar3;
  
  uVar1 = (clock << 0x14) >> 0x1c;
  if (uVar1 == 1) {
    pCVar2 = &Peripherals::CMU;
  }
  else {
    if (uVar1 != 4) {
      CMU_ClockEnable(clock,(_Bool)enable);
      return;
    }
    pCVar2 = (CMU *)&Peripherals::CMU.HFRADIOCLKEN0;
  }
  if (enable == false) {
    puVar3 = &pCVar2[0x2192e].CALCTRL;
  }
  else {
    puVar3 = (uint *)&pCVar2[0x325c5].field_0x78;
  }
  *puVar3 = 1 << ((clock << 0xf) >> 0x1b);
  return;
}



uint RADIOCMU_ClockFreqGet(CMU_Clock_TypeDef param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 & 0x3e0000;
  if (uVar2 == 0x40000) {
    uVar1 = SystemHFClockGet();
    uVar2 = read_volatile_4(Peripherals::CMU.HFPERPRESC);
  }
  else {
    if (uVar2 < 0x40001) {
      if (uVar2 == 0) {
        uVar1 = SystemHFClockGet();
        uVar2 = read_volatile_4(Peripherals::CMU.HFPRESC);
LAB_0000da84:
        uVar2 = (uVar2 << 0x13) >> 0x1b;
        goto LAB_0000da88;
      }
      if (uVar2 != 0x20000) {
LAB_0000da90:
        uVar2 = CMU_ClockFreqGet(param_1);
        return uVar2;
      }
      uVar1 = SystemHFClockGet();
      uVar2 = read_volatile_4(Peripherals::CMU.HFCOREPRESC);
    }
    else {
      if (uVar2 == 0x80000) {
        uVar2 = SystemHFClockGet();
        return uVar2;
      }
      if (uVar2 == 0xa0000) {
        uVar1 = SystemHFClockGet();
        uVar2 = read_volatile_4(Peripherals::CMU.HFEXPPRESC);
        goto LAB_0000da84;
      }
      if (uVar2 != 0x60000) goto LAB_0000da90;
      uVar1 = SystemHFClockGet();
      uVar2 = read_volatile_4(Peripherals::CMU.HFRADIOPRESC);
    }
  }
  uVar2 = (uVar2 << 0xf) >> 0x17;
LAB_0000da88:
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
  uVar1 = read_volatile_4(Peripherals::CMU.HFRADIOPRESC);
  return (uVar1 << 0xf) >> 0x17;
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
  write_volatile_1(Peripherals::SEQ.REG08C._3_1_,(char)((uint)(int)cVar4 / 2) + cVar3);
  write_volatile_1(Peripherals::SEQ.REG08C._2_1_,2);
  write_volatile_1(Peripherals::SEQ.REG08C._1_1_,0x23);
  return;
}



void TEMPCAL_Perform(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::RAC.STATUS);
  if ((uVar1 << 4) >> 0x1c == 2) {
    write_volatile_4(Peripherals::RAC.CMD,0x80);
  }
  return;
}



int TIMING_PreambleSyncBits(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = read_volatile_4(Peripherals::MODEM.PRE);
  uVar3 = ((uVar3 << 0x1a) >> 0x1e) * (uVar3 >> 0x10) + (uVar3 >> 0x10);
  if (uVar3 < 0x2711) {
    uVar1 = read_volatile_4(Peripherals::MODEM.CTRL1);
    iVar2 = (uVar1 & 0x1f) + 1 + uVar3;
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}



undefined4 TIMING_CalcAdjustUs(RAIL_Handle_t param_1,int param_2)

{
  uint32_t uVar1;
  
  uVar1 = RADIO_ComputeTxBitRate(param_1);
  return (int)((ulonglong)(((int)param_1 + param_2) * 100000 + uVar1 / 0x14) /
              ((ulonglong)uVar1 / 10));
}



void TIMING_SeqTimingInit(void)

{
  return;
}



int TIMING_NsToStimerTickCalcSigned(uint param_1)

{
  uint uVar1;
  
  uVar1 = (uint)((ulonglong)param_1 * (ulonglong)nsToStimerRatio);
  return (uVar1 + 0x1000000 >> 0x19 |
         (nsToStimerRatio * ((int)param_1 >> 0x1f) +
          (int)((ulonglong)param_1 * (ulonglong)nsToStimerRatio >> 0x20) +
         (uint)(0xfeffffff < uVar1)) * 0x80) - 0x80;
}



uint TIMING_NsToStimerTickCalc(void)

{
  uint uVar1;
  
  uVar1 = TIMING_NsToStimerTickCalcSigned();
  return uVar1 & ~((int)uVar1 >> 0x1f);
}



void TIMING_InitStimer(void)

{
  uint uVar1;
  int iVar2;
  undefined4 in_r3;
  
  write_volatile_4(Peripherals::RAC.PRESC,7);
  uVar1 = RADIOCMU_ClockFreqGet(0x75160);
  nsToStimerRatio = __aeabi_uldivmod(4000000,uVar1 / 1000,8000000,0,in_r3);
  iVar2 = TIMING_NsToStimerTickCalc(&PTR_RAC_0000ea60);
  write_volatile_4(Peripherals::SEQ.REG0B0,-iVar2);
  return;
}



void TIMING_TxWarmTimeRecalculate(RAIL_Handle_t railHandle)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = *(ushort *)((int)railHandle + 0x16);
  iVar2 = PA_GetRampTime();
  uVar3 = TIMING_NsToStimerTickCalc
                    (((uint)uVar1 - iVar2) * 1000 + (-0x9c4 - *(int *)((int)railHandle + 8)));
  write_volatile_4(Peripherals::SEQ.REG0A0,uVar3);
  return;
}



uint16_t TIMING_TxWarmTimeSet(RAIL_Handle_t railHandle,uint16_t time)

{
  if (time < 100) {
    time = 100;
  }
  else {
    if (12999 < time) {
      time = 13000;
    }
  }
  *(uint16_t *)((int)railHandle + 0x16) = time;
  return time;
}



void TIMING_RxToTxTimeRecalculate(RAIL_Handle_t railHandle)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = *(ushort *)((int)railHandle + 0x12);
  iVar2 = PA_GetRampTime();
  uVar3 = TIMING_NsToStimerTickCalc
                    (((uint)uVar1 - iVar2) * 1000 + (-0x9c4 - *(int *)((int)railHandle + 8)));
  write_volatile_4(Peripherals::SEQ.REG098,uVar3);
  return;
}



void TIMING_RxFrameToTxTimeRecalculate(RAIL_Handle_t railHandle)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = *(ushort *)((int)railHandle + 0x14);
  iVar2 = PA_GetRampTime();
  uVar3 = TIMING_NsToStimerTickCalcSigned
                    ((((uint)uVar1 - iVar2) * 1000 + (-0x9c4 - *(int *)((int)railHandle + 8))) -
                     *(int *)((int)railHandle + 4));
  write_volatile_4(Peripherals::SEQ.REG09C,uVar3);
  return;
}



uint16_t TIMING_RxFrameToTxTimeSet(RAIL_Handle_t railHandle,uint16_t time)

{
  if (time < 100) {
    time = 100;
  }
  else {
    if (12999 < time) {
      time = 13000;
    }
  }
  *(uint16_t *)((int)railHandle + 0x14) = time;
  return time;
}



void TIMING_TxToTxTimeRecalculate(RAIL_Handle_t railHandle)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = *(ushort *)((int)railHandle + 0x1a);
  iVar2 = PA_GetRampTime();
  uVar3 = TIMING_NsToStimerTickCalc(((uint)uVar1 - iVar2) * 1000 + -0x9c4);
  write_volatile_4(Peripherals::SEQ.REG0AC,uVar3);
  return;
}



void TIMING_TxToRxTimeRecalculate(RAIL_Handle_t railHandle)

{
  uint uVar1;
  
  uVar1 = TIMING_NsToStimerTickCalc
                    ((uint)*(ushort *)((int)railHandle + 0x18) * 1000 +
                     *(int *)((int)railHandle + 8) + -0x20d0);
  write_volatile_4(Peripherals::SEQ.REG0A4,uVar1);
  return;
}



uint16_t TIMING_TxToRxTimeSet(RAIL_Handle_t railHandle,uint16_t time)

{
  if (time < 100) {
    time = 100;
  }
  else {
    if (12999 < time) {
      time = 13000;
    }
  }
  *(uint16_t *)((int)railHandle + 0x18) = time;
  return time;
}



void TIMING_RxWarmTimeRecalculate(RAIL_Handle_t railHandle)

{
  uint uVar1;
  
  uVar1 = TIMING_NsToStimerTickCalc((uint)*(ushort *)((int)railHandle + 0x10) * 1000 + -0x20d0);
  write_volatile_4(Peripherals::SEQ.REG090,uVar1);
  return;
}



uint16_t TIMING_RxWarmTimeSet(RAIL_Handle_t railHandle,uint16_t time)

{
  if (time < 100) {
    time = 100;
  }
  else {
    if (12999 < time) {
      time = 13000;
    }
  }
  *(uint16_t *)((int)railHandle + 0x10) = time;
  return time;
}



void TIMING_RxSearchTimeRecalculate(RAIL_Handle_t railHandle)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = (uint)*(ushort *)((int)railHandle + 0xc) * 1000;
  if (*(ushort *)((int)railHandle + 0xc) != 0) {
                    // WARNING: Load size is inaccurate
    iVar2 = iVar2 + *railHandle + 10000;
  }
  uVar1 = TIMING_NsToStimerTickCalc(iVar2);
  write_volatile_4(Peripherals::SEQ.REG094,uVar1);
  return;
}



uint16_t TIMING_RxSearchTimeSet(RAIL_Handle_t railHandle,uint16_t time)

{
  if (12999 < time) {
    time = 13000;
  }
  *(uint16_t *)((int)railHandle + 0xc) = time;
  return time;
}



void TIMING_TxToRxSearchTimeRecalculate(RAIL_Handle_t railHandle)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = (uint)*(ushort *)((int)railHandle + 0xe) * 1000;
  if (*(ushort *)((int)railHandle + 0xe) != 0) {
                    // WARNING: Load size is inaccurate
    iVar2 = iVar2 + *railHandle + 10000;
  }
  uVar1 = TIMING_NsToStimerTickCalc(iVar2);
  write_volatile_4(Peripherals::SEQ.REG0A8,uVar1);
  return;
}



uint16_t TIMING_TxToRxSearchTimeSet(RAIL_Handle_t railHandle,uint16_t time)

{
  if (12999 < time) {
    time = 13000;
  }
  *(uint16_t *)((int)railHandle + 0xe) = time;
  return time;
}



void TIMING_RecalculateAll(RAIL_Handle_t railHandle)

{
  if (railHandle != (RAIL_Handle_t)0x0) {
    TIMING_RxSearchTimeRecalculate(railHandle);
    TIMING_TxToRxSearchTimeRecalculate(railHandle);
    TIMING_RxWarmTimeRecalculate(railHandle);
    TIMING_TxWarmTimeRecalculate(railHandle);
    TIMING_RxFrameToTxTimeRecalculate(railHandle);
    TIMING_RxToTxTimeRecalculate(railHandle);
    TIMING_TxToTxTimeRecalculate(railHandle);
    TIMING_TxToRxTimeRecalculate(railHandle);
    return;
  }
  return;
}



void TIMING_RecalculatePaRampChanged(RAIL_Handle_t param_1)

{
  if (param_1 != (RAIL_Handle_t)0x0) {
    TIMING_TxWarmTimeRecalculate(param_1);
    TIMING_RxToTxTimeRecalculate(param_1);
    TIMING_RxFrameToTxTimeRecalculate(param_1);
    TIMING_TxToTxTimeRecalculate(param_1);
    return;
  }
  return;
}



undefined4 TIMING_SetChainDelays(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  param_1[2] = param_3;
  *param_1 = param_2;
  return 0;
}



undefined4 TIMING_SetRxDoneDelay(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 4) = param_2;
  return 0;
}



void TIMING_CalcRxTimeStampUs(int *param_1,uint32_t param_2,int *param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  uint64_t uVar3;
  
  if (param_3 == (int *)0x0) {
    return;
  }
  bVar1 = *(byte *)(param_3 + 2);
  if (bVar1 == 0) {
    return;
  }
  iVar2 = bVar1 - 1;
  switch(bVar1) {
  case 1:
  case 5:
    *(undefined *)(param_3 + 2) = 4;
  case 4:
    iVar2 = 0;
    break;
  case 3:
    *(undefined *)(param_3 + 2) = 2;
  case 2:
    iVar2 = TIMING_PreambleSyncBits();
    if (iVar2 == -1) {
switchD_0000de4c_caseD_7:
      iVar2 = 0;
      *(undefined *)(param_3 + 2) = 0;
    }
    else {
      iVar2 = TIMING_CalcAdjustUs(iVar2,0);
      iVar2 = -iVar2;
    }
    break;
  case 6:
    iVar2 = 7;
    *(undefined *)(param_3 + 2) = 7;
  case 7:
    iVar2 = TIMING_CalcAdjustUs(0,param_3[1] << 3,param_3,iVar2,param_4);
    break;
  default:
    goto switchD_0000de4c_caseD_7;
  }
  if (*(char *)(param_3 + 2) != '\0') {
    uVar3 = PROTIMER_PrecntOverflowToUs(param_2);
    *param_3 = (int)uVar3 + (iVar2 - (*param_1 + 500U) / 1000);
  }
  return;
}



void TIMING_CalcTxTimeStampUs(int param_1,uint32_t param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint64_t uVar3;
  
  if (param_3 == (int *)0x0) {
    return;
  }
  switch(*(undefined *)(param_3 + 2)) {
  case 1:
  case 7:
    *(undefined *)(param_3 + 2) = 6;
  case 6:
    iVar2 = 0;
    goto LAB_0000defe;
  case 2:
    *(undefined *)(param_3 + 2) = 3;
switchD_0000dec4_caseD_3:
    iVar2 = TIMING_PreambleSyncBits();
    if (iVar2 == -1) {
switchD_0000dec4_caseD_7:
      iVar2 = 0;
      *(undefined *)(param_3 + 2) = 0;
    }
    else {
      iVar1 = param_3[1];
LAB_0000deee:
      iVar2 = TIMING_CalcAdjustUs(iVar2,iVar1 << 3);
      iVar2 = -iVar2;
    }
LAB_0000defe:
    if (*(char *)(param_3 + 2) != '\0') {
      uVar3 = PROTIMER_PrecntOverflowToUs(param_2);
      *param_3 = (int)uVar3 + iVar2 + (*(int *)(param_1 + 8) + 500U) / 1000;
    }
    return;
  case 3:
    goto switchD_0000dec4_caseD_3;
  case 4:
    *(undefined *)(param_3 + 2) = 5;
  case 5:
    iVar1 = param_3[1];
    iVar2 = 0;
    goto LAB_0000deee;
  default:
    return;
  case 0xbad1abe1:
    goto switchD_0000dec4_caseD_7;
  }
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
  uVar4 = read_volatile_4(Peripherals::CMU.HFRADIOCLKEN0);
  local_24 = __n;
  memset(buffer,0,__n);
  if ((((uVar4 | 0xcc) == uVar4) &&
      (uVar4 = read_volatile_4(Peripherals::RAC.CTRL), -1 < (int)(uVar4 << 0x1f))) &&
     (uVar4 = RADIOCMU_ClockPrescGet(0x75160), uVar4 == 0)) {
    irqState = CORE_EnterCritical();
    uVar3 = read_volatile_4(Peripherals::MODEM.CTRL0);
    uVar2 = read_volatile_4(Peripherals::FRC.RAWCTRL);
    write_volatile_4(Peripherals::MODEM_CLR.CTRL0,0x38000000);
    write_volatile_4(Peripherals::MODEM_SET.CTRL0,0x8000000);
    write_volatile_4(Peripherals::FRC.RAWCTRL,0x24);
    write_volatile_4(Peripherals::RAC_SET.RXENSRCEN,4);
    write_volatile_4(Peripherals::FRC.IFC,0x4000);
    write_volatile_4(Peripherals::FRC.CMD,0x1000);
    for (; uVar4 < __n; uVar4 = uVar4 + __n_00 & 0xffff) {
      do {
        do {
          uVar1 = read_volatile_4(Peripherals::FRC.IF);
        } while (-1 < (int)(uVar1 << 0x11));
        uVar1 = read_volatile_4(Peripherals::FRC.STATUS);
      } while (-1 < (int)(uVar1 << 0x17));
      __n_00 = __n - uVar4;
      write_volatile_4(Peripherals::FRC.IFC,0x4000);
      if (3 < (int)__n_00) {
        __n_00 = 4;
      }
      local_24 = read_volatile_4(Peripherals::FRC.RXRAWDATA);
      memcpy(buffer + uVar4,&local_24,__n_00);
    }
    write_volatile_4(Peripherals::RAC_CLR.RXENSRCEN,4);
    write_volatile_4(Peripherals::FRC.RAWCTRL,uVar2);
    write_volatile_4(Peripherals::MODEM.CTRL0,uVar3);
    write_volatile_4(Peripherals::FRC.IFC,0x4000);
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
    write_volatile_4(Peripherals::PROTIMER.RANDOM,uStack12 >> 0x10);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



void GENERIC_PHY_ConfigureRollbackReporting(void)

{
  RAC_SET *pRVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  if ((overrideRxRollback == '\0') && ((enabledRailEvents & 0x1200) == 0)) {
    write_volatile_4(Peripherals::RAC_CLR.SR3,0x10);
LAB_0000e06e:
    if ((enabledRailEvents & 0x80) == 0) {
      pRVar1 = (RAC_SET *)&Peripherals::RAC_CLR;
      goto LAB_0000e082;
    }
  }
  else {
    write_volatile_4(Peripherals::RAC_SET.SR3,0x10);
    if (overrideRxRollback == '\0') goto LAB_0000e06e;
  }
  pRVar1 = &Peripherals::RAC_SET;
LAB_0000e082:
  ((RAC_CLR *)pRVar1)->SR3 = 0x20;
  CORE_ExitCritical(irqState);
  return;
}



void GENERIC_PHY_ClearPendedRxWindowEnd(void)

{
  pendedRxWindowEnd = 0;
  if (overrideRxRollback != '\0') {
    overrideRxRollback = 0;
    GENERIC_PHY_ConfigureRollbackReporting();
    return;
  }
  pendedRxWindowEnd = 0;
  return;
}



void RADIO_RACRxAbort(undefined4 param_1,undefined4 param_2,int param_3)

{
  CORE_irqState_t irqState;
  uint uVar1;
  bool bVar2;
  
  irqState = CORE_EnterCritical();
  uVar1 = read_volatile_4(Peripherals::RAC.STATUS);
  uVar1 = (uVar1 << 4) >> 0x1c;
  bVar2 = uVar1 == 3;
  if (bVar2) {
    param_3 = 0x21000f7c;
    uVar1 = read_volatile_4(Peripherals::SEQ.REG080);
    uVar1 = uVar1 & 0xffffff0f | 0xe0;
  }
  if (bVar2) {
    *(uint *)(param_3 + 4) = uVar1;
  }
  write_volatile_4(Peripherals::FRC.CMD,1);
  CORE_ExitCritical(irqState);
  return;
}



void GENERIC_PHY_IssueCallback(uint param_1,uint param_2,int param_3)

{
  if (((param_1 | param_2) != 0) || (param_3 != 0)) {
    inCallback = 1;
    GENERIC_PHY_EventCallback();
    inCallback = 0;
  }
  return;
}



void GENERIC_PHY_RxOverflowHook(void)

{
  uint uVar1;
  RAC_SET *pRVar2;
  
  uVar1 = read_volatile_4(Peripherals::RAC.SR0);
  if (-1 < (int)(uVar1 << 0x18)) {
    write_volatile_4(Peripherals::RAC.CMD,8);
    uVar1 = read_volatile_4(Peripherals::SEQ.REG024);
    if ((uVar1 & 0x200) == 0) {
      pRVar2 = (RAC_SET *)&Peripherals::RAC_CLR;
    }
    else {
      pRVar2 = &Peripherals::RAC_SET;
    }
    pRVar2->RXENSRCEN = 2;
  }
  return;
}



void GENERIC_PHY_CheckPendedRxWindowEnd(void)

{
  int iVar1;
  
  if ((pendedRxWindowEnd != '\0') && (iVar1 = BUFC_RxBufferBytesAvailable(), iVar1 == 0)) {
    GENERIC_PHY_ClearPendedRxWindowEnd();
    GENERIC_PHY_IssueCallback(enabledRailEvents & 0x800,0,0);
    return;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void GENERIC_PHY_DisableRadioIrqs(void)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  _DAT_e000e180 = 0x40000000;
  CORE_ExitCritical(irqState);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void GENERIC_PHY_ConfigureEvents
               (uint param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6)

{
  BUFC_SET *pBVar1;
  CORE_irqState_t irqState;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  param_3 = param_3 & param_1;
  param_4 = param_4 & param_2;
  param_6 = param_6 & param_5;
  if (param_5 == 0) {
    if (param_2 == 0 && param_1 == 1) {
      irqState = CORE_EnterCritical();
      DAT_200044f4 = DAT_200044f4 | param_4;
      enabledRailEvents = enabledRailEvents & 0xfffffffe | param_3;
      uVar4 = 1;
      if ((param_3 | param_4) == 0) {
        write_volatile_4(Peripherals::AGC_CLR.IEN,1);
        write_volatile_4(Peripherals::AGC.IFC,1);
        goto LAB_0000e4c2;
      }
      write_volatile_4(Peripherals::AGC.IFC,1);
      puVar2 = &Peripherals::AGC_SET.IEN;
    }
    else {
      if (param_2 == 0 && param_1 == 0) {
        return;
      }
      if (param_2 != 0 || param_1 != 4) goto LAB_0000e2a6;
      irqState = CORE_EnterCritical();
      enabledRailEvents = enabledRailEvents & 0xfffffffb | param_3;
      DAT_200044f4 = DAT_200044f4 | param_4;
      if ((param_3 | param_4) == 0) {
        pBVar1 = (BUFC_SET *)&Peripherals::BUFC_CLR;
      }
      else {
        pBVar1 = &Peripherals::BUFC_SET;
      }
      puVar2 = &((BUFC_CLR *)pBVar1)->IEN;
      uVar4 = 0x400;
    }
  }
  else {
    if (((param_1 | param_2) != 0) || (param_5 != 4)) {
LAB_0000e2a6:
      GENERIC_PHY_DisableRadioIrqs();
      param_3 = enabledRailEvents & ~param_1 | param_3;
      param_4 = DAT_200044f4 & ~param_2 | param_4;
      param_6 = enabledPhyEvents & ~param_5 | param_6;
      enabledPhyEvents = param_6;
      enabledRailEvents = param_3;
      DAT_200044f4 = param_4;
      GENERIC_PHY_ConfigureRollbackReporting();
      uVar4 = read_volatile_4(Peripherals::FRC.IEN);
      uVar5 = 0x8002;
      if ((param_3 & 0x2a80000) == 0) {
        uVar5 = 0x8000;
      }
      if ((int)(param_6 << 0x1c) < 0) {
        uVar5 = uVar5 | 0x2000;
      }
      uVar3 = uVar4 & (uVar5 ^ uVar4);
      write_volatile_4(Peripherals::FRC_CLR.IEN,uVar3);
      write_volatile_4(Peripherals::FRC.IFC,uVar3);
      uVar5 = uVar5 & (uVar5 ^ uVar4);
      write_volatile_4(Peripherals::FRC.IFC,uVar5);
      write_volatile_4(Peripherals::FRC_SET.IEN,uVar5);
      if ((param_3 & 0x4000) == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = 0x1000;
      }
      if ((param_3 & 0x8000) != 0) {
        uVar4 = uVar4 | 0x100;
      }
      if ((int)(param_6 << 0x1f) < 0) {
        uVar4 = uVar4 | 0x2000;
      }
      if ((param_3 & 0x10) != 0) {
        uVar4 = uVar4 | 0x200;
      }
      if ((param_3 & 0x20) != 0) {
        uVar4 = uVar4 | 0x400;
      }
      uVar5 = read_volatile_4(Peripherals::MODEM.IEN);
      if ((param_3 & 0x40) != 0) {
        uVar4 = uVar4 | 0x800;
      }
      uVar3 = uVar5 & (uVar4 ^ uVar5);
      write_volatile_4(Peripherals::MODEM_CLR.IEN,uVar3);
      write_volatile_4(Peripherals::MODEM.IFC,uVar3);
      uVar4 = uVar4 & (uVar4 ^ uVar5);
      write_volatile_4(Peripherals::MODEM.IFC,uVar4);
      write_volatile_4(Peripherals::MODEM_SET.IEN,uVar4);
      if ((param_4 & 2) == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = 0x40000;
      }
      if ((param_3 & 0x400) != 0) {
        uVar4 = uVar4 | 0x10000;
      }
      if ((param_3 & 0x2000) != 0) {
        uVar4 = uVar4 | 0x100000;
      }
      if ((param_3 & 2) != 0) {
        uVar4 = uVar4 | 0x200000;
      }
      if ((param_3 & 0x10000) != 0) {
        uVar4 = uVar4 | 0x80000;
      }
      uVar5 = read_volatile_4(Peripherals::RAC.IEN);
      if ((int)(param_6 << 0x1b) < 0) {
        uVar4 = uVar4 | 4;
      }
      uVar3 = (uVar4 ^ uVar5) & 0xfffffffe;
      uVar5 = uVar5 & uVar3;
      write_volatile_4(Peripherals::RAC_CLR.IEN,uVar5);
      write_volatile_4(Peripherals::RAC.IFC,uVar5);
      uVar4 = uVar4 & uVar3;
      write_volatile_4(Peripherals::RAC.IFC,uVar4);
      write_volatile_4(Peripherals::RAC_SET.IEN,uVar4);
      uVar4 = 0x701800;
      if ((param_6 & 4) != 0) {
        uVar4 = 0x701c00;
      }
      uVar5 = read_volatile_4(Peripherals::PROTIMER.IEN);
      if ((param_3 & 0x20000000) != 0) {
        uVar4 = uVar4 | 0x2000000;
      }
      uVar3 = uVar5 & (uVar4 ^ uVar5);
      write_volatile_4(Peripherals::PROTIMER_CLR.IEN,uVar3);
      uVar4 = uVar4 & (uVar4 ^ uVar5);
      write_volatile_4(Peripherals::PROTIMER.IFC,uVar3);
      write_volatile_4(Peripherals::PROTIMER.IFC,uVar4);
      write_volatile_4(Peripherals::PROTIMER_SET.IEN,uVar4);
      uVar4 = read_volatile_4(Peripherals::AGC.IEN);
      uVar5 = uVar4 ^ param_3 & 1;
      uVar4 = uVar4 & uVar5;
      write_volatile_4(Peripherals::AGC_CLR.IEN,uVar4);
      write_volatile_4(Peripherals::AGC.IFC,uVar4);
      uVar5 = param_3 & 1 & uVar5;
      write_volatile_4(Peripherals::AGC.IFC,uVar5);
      write_volatile_4(Peripherals::AGC_SET.IEN,uVar5);
      uVar4 = 0x90a0a09;
      if ((param_3 & 0x20000) != 0) {
        uVar4 = 0x90a0a0d;
      }
      uVar5 = read_volatile_4(Peripherals::BUFC.IEN);
      if ((param_3 & 4) != 0) {
        uVar4 = uVar4 | 0x400;
      }
      uVar3 = (uVar4 ^ uVar5) & 0xfffaffff;
      uVar5 = uVar5 & uVar3;
      write_volatile_4(Peripherals::BUFC_CLR.IEN,uVar5);
      write_volatile_4(Peripherals::BUFC.IFC,uVar5);
      uVar4 = uVar4 & uVar3;
      write_volatile_4(Peripherals::BUFC.IFC,uVar4);
      write_volatile_4(Peripherals::BUFC_SET.IEN,uVar4);
      irqState = CORE_EnterCritical();
      _DAT_e000e100 = 0x20;
      goto LAB_0000e4c2;
    }
    irqState = CORE_EnterCritical();
    enabledPhyEvents = enabledPhyEvents & 0xfffffffb | param_6;
    uVar4 = 0x400;
    if (param_6 == 0) {
      write_volatile_4(Peripherals::PROTIMER_CLR.IEN,0x400);
      write_volatile_4(Peripherals::PROTIMER.IFC,0x400);
      goto LAB_0000e4c2;
    }
    write_volatile_4(Peripherals::PROTIMER.IFC,0x400);
    puVar2 = &Peripherals::PROTIMER_SET.IEN;
  }
  *puVar2 = uVar4;
LAB_0000e4c2:
  CORE_ExitCritical(irqState);
  return;
}



void GENERIC_PHY_PacketTxCommon(void)

{
  uint uVar1;
  uint16_t uVar2;
  
  uVar1 = read_volatile_4(Peripherals::FRC.DFLCTRL);
  if (((uVar1 & 7) == 0) && (uVar1 = read_volatile_4(Peripherals::SEQ.REG078), uVar1 != 0)) {
    uVar2 = BUFC_GetBytesAvailable('\0');
    write_volatile_4(Peripherals::FRC.WCNTCMP0,uVar2 - 1);
  }
  write_volatile_4(Peripherals::RAC_SET.SR0,0x80);
  uVar1 = read_volatile_4(Peripherals::SEQ.REG014);
  write_volatile_4(Peripherals::SEQ.REG014,uVar1 & 0xffffffbf);
  return;
}



undefined4 GENERIC_PHY_PacketTx(void)

{
  bool bVar1;
  CORE_irqState_t irqState;
  int iVar2;
  
  irqState = CORE_EnterCritical();
  bVar1 = PROTIMER_CCTimerIsEnabled('\x03');
  if ((bVar1 == false) && (iVar2 = PROTIMER_LBTIsActive(), iVar2 == 0)) {
    GENERIC_PHY_PacketTxCommon();
    write_volatile_4(Peripherals::RAC.CMD,1);
    CORE_ExitCritical(irqState);
    return 0;
  }
  CORE_ExitCritical(irqState);
  return 1;
}



undefined4
GENERIC_PHY_SchedulePacketRx
          (int param_1,undefined4 param_2,int param_3,int param_4,char param_5,char param_6,
          undefined param_7)

{
  bool bVar1;
  CORE_irqState_t irqState;
  int iVar2;
  uint uVar3;
  uint64_t uVar4;
  
  irqState = CORE_EnterCritical();
  if (param_3 != 2) {
    bVar1 = PROTIMER_CCTimerIsEnabled('\x03');
    if (bVar1 != false) goto LAB_0000e670;
    PROTIMER_ClearRxEnable();
    PROTIMER_ClearTxEnable();
    scheduledRxLoop = param_6;
    uVar3 = read_volatile_4(Peripherals::SEQ.REG014);
    if (param_6 == '\0') {
      uVar3 = uVar3 & 0xffffffbf;
    }
    else {
      uVar3 = uVar3 | 0x40;
    }
    write_volatile_4(Peripherals::SEQ.REG014,uVar3);
    iVar2 = PROTIMER_ScheduleRxEnable(3,param_2,param_3);
    if (iVar2 == 0) {
      CORE_ExitCritical(irqState);
      return 1;
    }
  }
  if (param_5 != '\x02') {
    bVar1 = PROTIMER_CCTimerIsEnabled('\x03');
    if ((bVar1 != false) ||
       (uVar3 = read_volatile_4(Peripherals::RAC.STATUS), (int)(uVar3 << 0x11) < 0)) {
      scheduledRxHardEnd = param_7;
      if ((param_5 == '\x01') && (param_3 != 2)) {
        param_4 = param_4 + PROTIMER_scheduledRxEnable;
        uVar4 = PROTIMER_UsToPrecntOverflow((uint)*(ushort *)(param_1 + 0x38));
        uVar3 = read_volatile_4(Peripherals::PROTIMER.WRAPCNTTOP);
        param_4 = PROTIMER_WrapMultiple
                            ((int)uVar4 + param_4,(int)(uVar4 >> 0x20),uVar3 + 1,0xfffffffe < uVar3)
        ;
        param_5 = '\0';
      }
      GENERIC_PHY_ClearPendedRxWindowEnd();
      iVar2 = PROTIMER_ScheduleRxDisable(4,param_4,param_5);
      if (iVar2 != 0) {
        if (param_6 != '\0') {
          overrideRxRollback = 1;
          write_volatile_4(Peripherals::RAC_SET.SR3,5);
        }
        goto LAB_0000e68a;
      }
      PROTIMER_CCTimerStop(3);
      PROTIMER_ClearRxEnable();
    }
LAB_0000e670:
    CORE_ExitCritical(irqState);
    return 3;
  }
LAB_0000e68a:
  CORE_ExitCritical(irqState);
  return 0;
}



undefined4 GENERIC_PHY_SchedulePacketTx(uint32_t *param_1)

{
  bool bVar1;
  CORE_irqState_t irqState;
  int iVar2;
  char cVar3;
  uint64_t uVar4;
  
  uVar4 = PROTIMER_UsToPrecntOverflow(*param_1);
  irqState = CORE_EnterCritical();
  bVar1 = PROTIMER_CCTimerIsEnabled('\x03');
  if ((bVar1 != false) || (iVar2 = PROTIMER_LBTIsActive(), iVar2 != 0)) {
    CORE_ExitCritical(irqState);
    return 3;
  }
  GENERIC_PHY_PacketTxCommon();
  PROTIMER_ClearRxEnable();
  PROTIMER_ClearTxEnable();
  RFHAL_SetAbortScheduledTxDuringRx(*(char *)((int)param_1 + 5) == '\x01');
  cVar3 = *(char *)(param_1 + 1);
  if (cVar3 != '\0') {
    cVar3 = '\x01';
  }
  iVar2 = PROTIMER_ScheduleTxEnable(3,(int)uVar4,cVar3);
  if (iVar2 == 0) {
    write_volatile_4(Peripherals::RAC_CLR.SR0,0x80);
    CORE_ExitCritical(irqState);
    return 1;
  }
  CORE_ExitCritical(irqState);
  return 0;
}



void GENERIC_PHY_StartRx(int param_1)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  if (param_1 != 0) {
    write_volatile_4(Peripherals::FRC.WCNTCMP0,param_1 - 1);
  }
  irqState = CORE_EnterCritical();
  uVar1 = read_volatile_4(Peripherals::SEQ.REG014);
  write_volatile_4(Peripherals::SEQ.REG014,uVar1 & 0xffffffbf);
  CORE_ExitCritical(irqState);
  write_volatile_4(Peripherals::RAC_SET.RXENSRCEN,2);
  return;
}



void GENERIC_PHY_ChannelSet(uint16_t param_1)

{
  SYNTH_ChannelSet(param_1,true);
  return;
}



void GENERIC_PHY_SeqAtomicLock(void)

{
  uint uVar1;
  
  write_volatile_4(Peripherals::RAC_SET.SR0,4);
  while (uVar1 = read_volatile_4(Peripherals::RAC.SR0), (int)(uVar1 << 0xd) < 0) {
    write_volatile_4(Peripherals::RAC_CLR.SR0,4);
    PROTIMER_DelayUs(2);
    write_volatile_4(Peripherals::RAC_SET.SR0,4);
  }
  return;
}



uint GENERIC_PHY_PreviousTxTime(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::PROTIMER.CC1_WRAP);
  return uVar1;
}



void GENERIC_PHY_RACConfig(void)

{
  RADIO_SeqInit(&genericSeqProg,0x3c1);
  memset(&Peripherals::SEQ.REG014,0,0x68);
  write_volatile_4(Peripherals::RAC.SR0,0);
  write_volatile_4(Peripherals::RAC.SR1,0);
  write_volatile_4(Peripherals::RAC.SR2,0);
  TEMPCAL_Init();
  return;
}



void GENERIC_PHY_ConfigDirectMode(byte *param_1)

{
  uint uVar1;
  
  if (param_1 != (byte *)0x0) {
    RADIOCMU_ClockEnable(0x67400,true);
    CMU_ClockEnable(cmuClock_GPIO,true);
    uVar1 = (uint)*param_1;
    write_volatile_4(Peripherals::MODEM_CLR.CTRL2,0xc00);
    if (uVar1 == 0) {
      write_volatile_4(Peripherals::MODEM_SET.CTRL2,0);
    }
    else {
      uVar1 = (uint)param_1[4];
      if (uVar1 == 0) {
        write_volatile_4(Peripherals::MODEM_SET.CTRL2,0x800);
      }
      else {
        write_volatile_4(Peripherals::MODEM_SET.CTRL2,0xc00);
        uVar1 = 4;
      }
      uVar1 = uVar1 | 1;
    }
    if (param_1[1] != 0) {
      write_volatile_4(Peripherals::MODEM_CLR.CTRL2,0x200);
      if (param_1[3] == 0) {
        write_volatile_4(Peripherals::MODEM_SET.CTRL2,0x200);
      }
      else {
        write_volatile_4(Peripherals::MODEM_SET.CTRL2,0);
        uVar1 = uVar1 | 4;
      }
      uVar1 = uVar1 | 2;
    }
    if (param_1[2] == 0) {
      write_volatile_4(Peripherals::MODEM_CLR.CTRL2,0x100);
    }
    else {
      write_volatile_4(Peripherals::MODEM_SET.CTRL2,0x100);
    }
    write_volatile_4(Peripherals::MODEM.ROUTELOC0,
                     (uint)param_1[8] << 0x10 | (uint)param_1[5] << 8 | (uint)param_1[0xb]);
    write_volatile_4(Peripherals::MODEM_CLR.ROUTEPEN,7);
    write_volatile_4(Peripherals::MODEM_SET.ROUTEPEN,uVar1);
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



int GENERIC_PHY_ReleaseRxPacket(void)

{
  int iVar1;
  CORE_irqState_t irqState;
  
  iVar1 = BUFC_ReleaseRxPacket();
  if ((inCallback == '\0') && (iVar1 == 0)) {
    irqState = CORE_EnterCritical();
    GENERIC_PHY_CheckPendedRxWindowEnd();
    CORE_ExitCritical(irqState);
  }
  return iVar1;
}



void GENERIC_PHY_ResetRxFifo(int param_1)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  BUFC_RxBufferReset();
  if (param_1 == 0) {
    if (inCallback == '\0') {
      GENERIC_PHY_CheckPendedRxWindowEnd();
    }
  }
  else {
    GENERIC_PHY_ClearPendedRxWindowEnd();
  }
  CORE_ExitCritical(irqState);
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
      uVar1 = read_volatile_4(Peripherals::RAC.STATUS);
      if ((uVar1 << 4) >> 0x1c != 3) break;
      uVar1 = read_volatile_4(Peripherals::SEQ.REG07C);
    } while ((uVar1 & 0xf) != 3);
    if (param_2 != 0) {
      GENERIC_PHY_SeqAtomicLock();
      write_volatile_4(Peripherals::RAC_SET.CTRL,1);
      write_volatile_4(Peripherals::RAC_CLR.SR0,4);
      while (uVar1 = read_volatile_4(Peripherals::RAC.STATUS), (uVar1 & 0xf000000) != 0) {
        RADIO_RACClearRxOverflow();
      }
    }
  }
  write_volatile_4(Peripherals::RAC_CLR.SR0,0x80);
  bVar2 = PROTIMER_CCTimerIsEnabled('\x03');
  if (bVar2 != false) {
    PROTIMER_CCTimerStop(3);
    PROTIMER_CCTimerStop(4);
  }
  PROTIMER_ClearRxEnable();
  PROTIMER_ClearTxEnable();
  GENERIC_PHY_SeqAtomicLock();
  uVar1 = read_volatile_4(Peripherals::SEQ.REG014);
  write_volatile_4(Peripherals::SEQ.REG014,uVar1 | 0x40);
  write_volatile_4(Peripherals::RAC_CLR.RXENSRCEN,0xff);
  write_volatile_4(Peripherals::RAC.CMD,0x100);
  write_volatile_4(Peripherals::RAC_CLR.SR0,4);
  if (param_1 != 0) {
    RADIO_RACRxAbort();
    PROTIMER_LBTStop();
    write_volatile_4(Peripherals::RAC.CMD,0x20);
    PROTIMER_CCTimerStop(4);
  }
  if (param_2 != 0) {
    GENERIC_PHY_ResetRxFifo(param_3);
    write_volatile_4(Peripherals::RAC_CLR.CTRL,1);
    if (param_3 != 0) {
      uVar1 = read_volatile_4(Peripherals::FRC.IEN);
      write_volatile_4(Peripherals::FRC.IFC,uVar1);
      uVar1 = read_volatile_4(Peripherals::RAC.IEN);
      write_volatile_4(Peripherals::RAC.IFC,uVar1);
      uVar1 = read_volatile_4(Peripherals::MODEM.IEN);
      write_volatile_4(Peripherals::MODEM.IFC,uVar1);
      uVar1 = read_volatile_4(Peripherals::SYNTH.IEN);
      write_volatile_4(Peripherals::SYNTH.IFC,uVar1);
      uVar1 = read_volatile_4(Peripherals::BUFC.IEN);
      write_volatile_4(Peripherals::BUFC.IFC,uVar1);
      uVar1 = read_volatile_4(Peripherals::AGC.IEN);
      write_volatile_4(Peripherals::AGC.IFC,uVar1);
      write_volatile_4(Peripherals::PROTIMER.IFC,0x2f00050);
      GENERIC_PHY_ClearPendedRxWindowEnd();
    }
  }
  CORE_ExitCritical(irqState);
  return;
}



void RAILCb_RadioStateChanged(void)

{
  write_volatile_4(Peripherals::RAC_CLR.IEN,1);
  write_volatile_4(Peripherals::RAC.IFC,1);
  return;
}



void RAC_RSM_IRQHandler(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = read_volatile_4(Peripherals::RAC.IF);
  uVar2 = read_volatile_4(Peripherals::RAC.IEN);
  uVar2 = uVar2 & uVar1;
  write_volatile_4(Peripherals::RAC.IFC,uVar2 & 0xffff);
  if ((int)(uVar2 << 0x1f) < 0) {
    uVar1 = read_volatile_4(Peripherals::RAC.STATUS);
    RAILCb_RadioStateChanged((uVar1 << 4) >> 0x1c);
  }
  if ((int)(uVar2 << 0x1d) < 0) {
    GENERIC_PHY_IssueCallback(0,0,enabledPhyEvents & 0x10);
    return;
  }
  return;
}



void AGC_IRQHandler(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 in_r3;
  
  uVar1 = read_volatile_4(Peripherals::AGC.IF);
  uVar2 = read_volatile_4(Peripherals::AGC.IEN);
  write_volatile_4(Peripherals::AGC.IFC,uVar1 & uVar2);
  if ((int)((uVar1 & uVar2) << 0x1f) < 0) {
    RAILInt_Assert((byte)enabledRailEvents & 1,0x12);
    GENERIC_PHY_IssueCallback(1,0,0,in_r3);
    return;
  }
  return;
}



void SYNTH_IRQHandler(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = read_volatile_4(Peripherals::SYNTH.IF);
  uVar2 = read_volatile_4(Peripherals::SYNTH.IEN);
  write_volatile_4(Peripherals::SYNTH.IFC,uVar1 & uVar2);
  return;
}



uint GENERIC_PHY_SetFeatures(undefined4 param_1,uint param_2,uint param_3)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = read_volatile_4(Peripherals::SEQ.REG014);
  write_volatile_4(Peripherals::SEQ.REG014,param_3 & param_2 | uVar1 & ~param_2);
  CORE_ExitCritical(irqState);
  return param_2 & uVar1;
}



void GENERIC_PHY_ConfigureFrameType(undefined4 param_1,uint *param_2,undefined4 param_3)

{
  byte bVar1;
  uint *local_1c;
  undefined4 uStack24;
  
  uStack24 = param_3;
  if (param_2 == (uint *)0x0) {
    local_1c = param_2;
    GENERIC_PHY_SetFeatures(param_1,7,0);
    write_volatile_4(Peripherals::SEQ.REG074,0);
    write_volatile_4(Peripherals::SEQ.REG078,0);
  }
  else {
    write_volatile_4(Peripherals::FRC_CLR.DFLCTRL,7);
    write_volatile_4(Peripherals::FRC_SET.DFLCTRL,0);
    write_volatile_1(Peripherals::SEQ.REG074._0_1_,*(undefined *)(param_2 + 1));
    local_1c = (uint *)(uint)*(byte *)((int)param_2 + 5);
    bVar1 = CORTEX_UTILS_BitsetLowestSetBit(&local_1c,1,0,local_1c,param_1);
    write_volatile_1(Peripherals::SEQ.REG074._1_1_,
                     bVar1 & 0xf | (byte)(((uint)local_1c >> (uint)bVar1) << 4));
    write_volatile_1(Peripherals::SEQ.REG074._2_1_,*(undefined *)((int)param_2 + 6));
    write_volatile_1(Peripherals::SEQ.REG074._3_1_,*(undefined *)((int)param_2 + 7));
    write_volatile_4(Peripherals::SEQ.REG078,*param_2);
    write_volatile_4(Peripherals::FRC.WCNTCMP0,*(byte *)(param_2 + 1) + 1);
    GENERIC_PHY_SetFeatures(param_1,7,7);
  }
  return;
}



bool GENERIC_PHY_EnableAddressFiltering(RAIL_Handle_t railHandle,bool enable)

{
  int iVar1;
  
  iVar1 = GENERIC_PHY_SetFeatures();
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return SUB41(iVar1,0);
}



bool GENERIC_PHY_IsEnabledAddressFiltering(RAIL_Handle_t railHandle)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG014);
  return SUB41((uVar1 << 0x1b) >> 0x1f,0);
}



void GENERIC_PHY_ResetAddressFiltering(void)

{
  memset(&Peripherals::SEQ.REG028,0,0x4c);
  return;
}



void GENERIC_PHY_Init(int param_1)

{
  int iVar1;
  
  RADIO_Init();
  GENERIC_PHY_DisableRadioIrqs();
  GENERIC_PHY_RACConfig();
  PTI_Enable(true);
  BUFC_Init(0xe129);
  write_volatile_4(Peripherals::RAC_CLR.CTRL,1);
  GENERIC_PHY_ResetAddressFiltering(param_1);
  PROTIMER_Init();
  PROTIMER_Start();
  TIMING_InitStimer();
  TIMING_RecalculateAll((RAIL_Handle_t)(param_1 + 0x28));
  PROTIMER_CCTimerCapture(0,0xc00000);
  PROTIMER_CCTimerCapture(1,0x200000);
  SYNTH_DCDCRetimeDisable();
  iVar1 = RFRAND_SeedProtimerRandom();
  if (iVar1 == 0) {
    RAILInt_Assert(0,0x14);
  }
  SYNTH_DCDCRetimeEnable();
  return;
}



RAIL_Status_t_enum
GENERIC_PHY_ConfigureAddressFiltering
          (RAIL_Handle_t railHandle,RAIL_AddrConfig_t *addrConfig,bool reset)

{
  if (reset != false) {
    GENERIC_PHY_ResetAddressFiltering();
  }
  if (addrConfig == (RAIL_AddrConfig_t *)0x0) {
    return RAIL_STATUS_NO_ERROR;
  }
  write_volatile_1(Peripherals::SEQ.REG06C._0_1_,addrConfig->offsets[0]);
  if (addrConfig->sizes[0] < 9) {
    write_volatile_1(Peripherals::SEQ.REG06C._2_1_,addrConfig->sizes[0]);
    write_volatile_1(Peripherals::SEQ.REG06C._1_1_,addrConfig->offsets[1]);
    if (addrConfig->sizes[1] < 9) {
      write_volatile_1(Peripherals::SEQ.REG06C._3_1_,addrConfig->sizes[1]);
      write_volatile_4(Peripherals::SEQ.REG028,addrConfig->matchTable);
      return RAIL_STATUS_NO_ERROR;
    }
  }
  return RAIL_STATUS_INVALID_PARAMETER;
}



RAIL_Status_t_enum
GENERIC_PHY_EnableAddress(RAIL_Handle_t railHandle,bool enable,uint8_t field,uint8_t index)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  
  uVar3 = (uint)enable;
  if ((uVar3 < 2) && (field < 4)) {
    bVar1 = *(byte *)((int)&Peripherals::SEQ.REG070 + uVar3);
    bVar2 = (byte)(1 << (uint)field);
    if (index == '\0') {
      bVar2 = bVar1 & ~bVar2;
    }
    else {
      bVar2 = bVar2 | bVar1;
    }
    *(byte *)((int)&Peripherals::SEQ.REG070 + uVar3) = bVar2;
    return RAIL_STATUS_NO_ERROR;
  }
  return RAIL_STATUS_INVALID_PARAMETER;
}



undefined4
GENERIC_PHY_SetAddressData
          (RAIL_Handle_t param_1,uint param_2,uint param_3,uint param_4,byte param_5,byte param_6,
          byte *param_7)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  
  uVar3 = (uint)param_5;
  uVar2 = (uint)param_6;
  if ((((param_2 < 2) && (param_3 < 2)) && (uVar3 < uVar2)) &&
     (((uVar2 < 9 && (param_4 < 4)) && (param_7 != (byte *)0x0)))) {
    GENERIC_PHY_EnableAddress(param_1,SUB41(param_2,0),(uint8_t)param_4,'\0');
    puVar1 = (uint *)((uVar3 + 0x84003ca + param_3 * 8) * 4);
    for (pbVar4 = param_7; (int)(pbVar4 + (uVar3 - (int)param_7)) < (int)uVar2; pbVar4 = pbVar4 + 1)
    {
      puVar1 = puVar1 + 1;
      *puVar1 = (uint)*pbVar4 << (param_4 << 3 & 0xff) | ~(0xff << (param_4 << 3 & 0xff)) & *puVar1;
    }
    return 0;
  }
  return 1;
}



int GENERIC_PHY_SetIeeePanId(undefined4 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  uVar4 = GENERIC_PHY_SetAddressData();
  iVar2 = (int)((ulonglong)uVar4 >> 0x20);
  iVar1 = (int)uVar4;
  iVar3 = iVar1;
  if (iVar1 == 0) {
    if (param_2 < 4) {
      iVar2 = 0x21000f28;
    }
    iVar3 = 1;
    if (param_2 < 4) {
      *(byte *)(iVar2 + 0x48) = (byte)(1 << (param_2 & 0xff)) | *(byte *)(iVar2 + 0x48);
      iVar3 = iVar1;
    }
  }
  return iVar3;
}



int GENERIC_PHY_SetIeeeShortAddress
              (undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  uVar4 = GENERIC_PHY_SetAddressData(param_1,1,0,param_2,2,4,param_3,param_4);
  iVar2 = (int)((ulonglong)uVar4 >> 0x20);
  iVar1 = (int)uVar4;
  iVar3 = iVar1;
  if (iVar1 == 0) {
    if (param_2 < 4) {
      iVar2 = 0x21000f28;
    }
    iVar3 = 1;
    if (param_2 < 4) {
      *(byte *)(iVar2 + 0x49) = (byte)(1 << (param_2 & 0xff)) | *(byte *)(iVar2 + 0x49);
      iVar3 = iVar1;
    }
  }
  return iVar3;
}



int GENERIC_PHY_SetIeeeLongAddress(undefined4 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  uVar4 = GENERIC_PHY_SetAddressData();
  iVar2 = (int)((ulonglong)uVar4 >> 0x20);
  iVar1 = (int)uVar4;
  iVar3 = iVar1;
  if (iVar1 == 0) {
    if (param_2 < 4) {
      iVar2 = 0x21000f28;
    }
    iVar3 = 1;
    if (param_2 < 4) {
      *(byte *)(iVar2 + 0x49) = (byte)(1 << (param_2 & 0xff)) | *(byte *)(iVar2 + 0x49);
      iVar3 = iVar1;
    }
  }
  return iVar3;
}



uint GENERIC_PHY_SetAddress
               (RAIL_Handle_t param_1,int param_2,undefined4 param_3,undefined4 param_4,char param_5
               )

{
  RAIL_Status_t_enum RVar1;
  uint uVar2;
  
  uVar2 = GENERIC_PHY_SetAddressData
                    (param_1,param_2,param_2,param_3,0,
                     *(undefined *)((int)&Peripherals::SEQ.REG06C + param_2 + 2),param_4);
  if ((param_5 != '\0') && (uVar2 == 0)) {
    RVar1 = GENERIC_PHY_EnableAddress(param_1,SUB41(param_2,0),(uint8_t)param_3,'\x01');
    return (uint)RVar1;
  }
  return uVar2;
}



bool GENERIC_PHY_IsEnabledIEEE802154(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG014);
  return (bool)((byte)uVar1 >> 7);
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



uint32_t GENERIC_PHY_GetTimerTimeout(void)

{
  uint32_t uVar1;
  
  uVar1 = PROTIMER_GetCCTime(2);
  return uVar1;
}



bool GENERIC_PHY_IsTimerExpired(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::PROTIMER.IF);
  return SUB41((uVar1 << 0x15) >> 0x1f,0);
}



bool GENERIC_PHY_IsTimerRunning(RAIL_Handle_t railHandle)

{
  bool bVar1;
  
  bVar1 = PROTIMER_CCTimerIsEnabled('\x02');
  return bVar1;
}



bool GENERIC_PHY_CanModifyAck(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::RAC.STATUS);
  uVar1 = (uVar1 << 4) >> 0x1c;
  if (1 < uVar1 - 2) {
    return uVar1 == 7;
  }
  return true;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FRC_IRQHandler(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  CORE_irqState_t irqState;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar4 = read_volatile_4(Peripherals::FRC.IF);
  uVar6 = read_volatile_4(Peripherals::FRC.IEN);
  uVar6 = uVar6 & uVar4;
  write_volatile_4(Peripherals::FRC.IFC,uVar6);
  uVar4 = read_volatile_4(Peripherals::BUFC.IF);
  uVar7 = read_volatile_4(Peripherals::BUFC.IEN);
  uVar7 = uVar7 & uVar4;
  write_volatile_4(Peripherals::BUFC.IFC,uVar7);
  uVar4 = read_volatile_4(Peripherals::MODEM.IF);
  uVar10 = read_volatile_4(Peripherals::MODEM.IEN);
  uVar10 = uVar10 & uVar4;
  write_volatile_4(Peripherals::MODEM.IFC,uVar10);
  uVar4 = read_volatile_4(Peripherals::RAC.IF);
  uVar8 = read_volatile_4(Peripherals::RAC.IEN);
  uVar8 = uVar8 & uVar4;
  write_volatile_4(Peripherals::RAC.IFC,uVar8 & 0xffff0000);
  iVar1 = PROTIMER_LBTIsActive();
  uVar4 = read_volatile_4(Peripherals::PROTIMER.IF);
  uVar9 = read_volatile_4(Peripherals::PROTIMER.IEN);
  uVar9 = uVar9 & uVar4;
  write_volatile_4(Peripherals::PROTIMER.IFC,uVar9 & 0xfffff7ff);
  if (uVar6 == 0) {
    uVar4 = 0;
  }
  else {
    if ((int)(uVar6 << 0x10) < 0) {
      uVar4 = read_volatile_4(Peripherals::RAC.SR0);
      write_volatile_4(Peripherals::RAC_CLR.SR0,uVar4 & 0x1c00);
      write_volatile_4(Peripherals::RAC_CLR.SR0,0x80);
      write_volatile_4(Peripherals::RAC_CLR.RXENSRCEN,0x10);
      if ((uVar4 & 0x1c00) == 0) {
        uVar4 = 0x40000;
      }
      else {
        if ((int)(uVar4 << 0x13) < 0) {
          uVar4 = 0x1000000;
        }
        else {
          if ((int)(uVar4 << 0x15) < 0) {
            uVar4 = 0x100000;
          }
          else {
            uVar4 = 0x400000;
          }
        }
      }
    }
    else {
      uVar4 = 0;
    }
    if ((int)(uVar6 << 0x1e) < 0) {
      uVar5 = read_volatile_4(Peripherals::RAC.SR0);
      write_volatile_4(Peripherals::RAC_CLR.SR0,uVar5 & 0xe000);
      if ((uVar5 & 0xe000) == 0) {
        uVar4 = uVar4 | 0x80000;
      }
      else {
        if ((int)(uVar5 << 0x10) < 0) {
          uVar4 = uVar4 | 0x2000000;
        }
        else {
          if ((int)(uVar5 << 0x12) < 0) {
            uVar4 = uVar4 | 0x200000;
          }
          else {
            uVar4 = uVar4 | 0x800000;
          }
        }
      }
    }
    if ((uVar6 & 0x2000) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = 8;
    }
  }
  uVar5 = 0;
  if ((uVar7 & 0x90b0a09) != 0) {
    if ((uVar7 & 0xa00) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,6);
    }
    if ((uVar7 & 9) != 0) {
      write_volatile_4(Peripherals::RAC.CMD,0x20);
      write_volatile_4(Peripherals::BUFC.BUF0_CMD,1);
      RAILInt_Assert(0,8);
    }
    if ((uVar7 & 0x9000000) != 0) {
      write_volatile_4(Peripherals::RAC.CMD,0x20);
      BUFC_TxAckBufferReset();
      RAILInt_Assert(0,9);
    }
    if ((uVar7 & 0xa0000) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,7);
    }
    if ((int)(uVar7 << 0xf) < 0) {
      BUFC_HandleRxLenOvfEvent();
    }
  }
  if ((int)(uVar7 << 0x1d) < 0) {
    if (_DAT_430204b4 == 0) {
      write_volatile_4(Peripherals::BUFC_SET.BUF0_THRESHOLDCTRL,0x2000);
    }
    else {
      uVar4 = uVar4 | 0x20000;
      write_volatile_4(Peripherals::BUFC_CLR.BUF0_THRESHOLDCTRL,0x2000);
    }
  }
  if ((int)(uVar7 << 0x15) < 0) {
    uVar4 = uVar4 | 4;
  }
  if ((uVar7 & 0x40000) != 0) {
    uVar2 = BUFC_StartRxLenThrEvent();
    switch(uVar2) {
    case 1:
    case 3:
      uVar4 = uVar4 | 0x1000;
      break;
    case 2:
      uVar4 = uVar4 | 0x200;
      break;
    case 4:
      uVar4 = uVar4 | 0x100;
      break;
    case 5:
      uVar4 = uVar4 | 0x80;
      break;
    case 6:
    case 7:
      uVar4 = uVar4 | 8;
      break;
    default:
      RAILInt_Assert(0,3);
    }
  }
  if (uVar10 != 0) {
    if ((uVar10 & 0x1000) != 0) {
      uVar4 = uVar4 | 0x4000;
    }
    if ((uVar10 & 0x100) != 0) {
      uVar4 = uVar4 | 0x8000;
    }
    if ((uVar10 & 0x2000) != 0) {
      uVar6 = uVar6 | 1;
    }
    if ((uVar10 & 0x200) != 0) {
      uVar4 = uVar4 | 0x10;
    }
    if ((uVar10 & 0x400) != 0) {
      uVar4 = uVar4 | 0x20;
    }
    if ((uVar10 & 0x800) != 0) {
      uVar4 = uVar4 | 0x40;
    }
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      uVar6 = uVar6 | 0x20;
    }
    if ((uVar8 & 0x4000000) != 0) {
      uVar6 = uVar6 | 0x40;
    }
    if ((uVar8 & 0x8000000) != 0) {
      uVar6 = uVar6 | 0x80;
    }
    if ((uVar8 & 0x40000) != 0) {
      uVar5 = 2;
    }
    if ((uVar8 & 0x10000) != 0) {
      uVar4 = uVar4 | 0x400;
    }
    if ((uVar8 & 0x100000) != 0) {
      uVar4 = uVar4 | 0x2000;
    }
    if ((uVar8 & 0x200000) != 0) {
      uVar4 = uVar4 | 2;
    }
    if (((uVar8 & 0x80000) != 0) && (iVar3 = GENERIC_PHY_CanModifyAck(), iVar3 != 0)) {
      uVar4 = uVar4 | 0x10000;
    }
  }
  if (uVar9 == 0) goto LAB_0000f236;
  if ((uVar9 & 0x800) != 0) {
    PROTIMER_CCTimerStop(3);
    write_volatile_4(Peripherals::PROTIMER_CLR.RXCTRL,0x1f1f);
    write_volatile_4(Peripherals::PROTIMER.IFC,0x800);
    PROTIMER_ClearTxEnable();
  }
  if ((uVar9 & 0x2000000) != 0) {
    PTI_AuxdataOutput(0x2b);
    uVar4 = uVar4 | 0x20000000;
  }
  if ((uVar9 & 0x700000) == 0) {
    if ((uVar9 & 0x1000) != 0) {
      if (iVar1 != 0) goto LAB_0000f120;
      PROTIMER_CCTimerStop(4);
      PROTIMER_CCTimerStop(3);
      PROTIMER_ClearRxEnable();
      irqState = CORE_EnterCritical();
      if (scheduledRxHardEnd != '\0') {
        RADIO_RACRxAbort();
      }
      iVar1 = BUFC_RxBufferBytesAvailable();
      uVar10 = read_volatile_4(Peripherals::RAC.STATUS);
      if (((uVar10 << 4) >> 0x1c == 3) || (iVar1 != 0)) {
        iVar1 = 1;
        pendedRxWindowEnd = scheduledRxLoop;
      }
      CORE_ExitCritical(irqState);
      if (iVar1 == 0) {
        overrideRxRollback = 0;
        GENERIC_PHY_ConfigureRollbackReporting();
        uVar10 = 0x800;
      }
      else {
        uVar10 = 0;
      }
      uVar4 = uVar4 | uVar10;
    }
  }
  else {
LAB_0000f120:
    uVar9 = PROTIMER_CheckCcaReallyFailed(uVar9);
    if ((uVar9 & 0x200000) != 0) {
      PTI_AuxdataOutput(0x29);
      uVar4 = uVar4 | 0x10000000;
    }
    if ((uVar9 & 0x400000) == 0) {
      if ((uVar9 & 0x100000) == 0) {
        if ((uVar9 & 0x1000) != 0) {
          PROTIMER_CCTimerStop(4);
          PROTIMER_LBTStop();
          uVar10 = read_volatile_4(Peripherals::PROTIMER.IF);
          if ((uVar10 & 0x500000) == 0) {
            PTI_AuxdataOutput(0x2a);
            write_volatile_4(Peripherals::BUFC.BUF0_CMD,1);
            goto LAB_0000f1ba;
          }
        }
      }
      else {
        PROTIMER_CCTimerStop(4);
        PTI_AuxdataOutput(0x28);
        uVar4 = uVar4 | 0x4000000;
      }
    }
    else {
      PROTIMER_CCTimerStop(4);
      PTI_AuxdataOutput(0x27);
      write_volatile_4(Peripherals::RAC_CLR.SR0,0x80);
      write_volatile_4(Peripherals::RAC_CLR.RXENSRCEN,0x10);
LAB_0000f1ba:
      uVar4 = uVar4 | 0x8000000;
    }
  }
  if ((uVar9 & 0x400) != 0) {
    PROTIMER_CCTimerStop(2);
    uVar6 = uVar6 | 4;
  }
LAB_0000f236:
  GENERIC_PHY_IssueCallback(enabledRailEvents & uVar4,DAT_200044f4 & uVar5,enabledPhyEvents & uVar6)
  ;
  if ((uVar7 & 0x40000) != 0) {
    BUFC_EndRxLenThrEvent();
    GENERIC_PHY_CheckPendedRxWindowEnd();
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      PA_RunPeakDetectorHigh();
    }
    if ((uVar8 & 0x4000000) != 0) {
      PA_RunPeakDetectorLow();
    }
    if ((uVar8 & 0x8000000) != 0) {
      PA_RunBatHigh();
      return;
    }
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FRC_PRI_IRQHandler(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  CORE_irqState_t irqState;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar4 = read_volatile_4(Peripherals::FRC.IF);
  uVar6 = read_volatile_4(Peripherals::FRC.IEN);
  uVar6 = uVar6 & uVar4;
  write_volatile_4(Peripherals::FRC.IFC,uVar6);
  uVar4 = read_volatile_4(Peripherals::BUFC.IF);
  uVar7 = read_volatile_4(Peripherals::BUFC.IEN);
  uVar7 = uVar7 & uVar4;
  write_volatile_4(Peripherals::BUFC.IFC,uVar7);
  uVar4 = read_volatile_4(Peripherals::MODEM.IF);
  uVar10 = read_volatile_4(Peripherals::MODEM.IEN);
  uVar10 = uVar10 & uVar4;
  write_volatile_4(Peripherals::MODEM.IFC,uVar10);
  uVar4 = read_volatile_4(Peripherals::RAC.IF);
  uVar8 = read_volatile_4(Peripherals::RAC.IEN);
  uVar8 = uVar8 & uVar4;
  write_volatile_4(Peripherals::RAC.IFC,uVar8 & 0xffff0000);
  iVar1 = PROTIMER_LBTIsActive();
  uVar4 = read_volatile_4(Peripherals::PROTIMER.IF);
  uVar9 = read_volatile_4(Peripherals::PROTIMER.IEN);
  uVar9 = uVar9 & uVar4;
  write_volatile_4(Peripherals::PROTIMER.IFC,uVar9 & 0xfffff7ff);
  if (uVar6 == 0) {
    uVar4 = 0;
  }
  else {
    if ((int)(uVar6 << 0x10) < 0) {
      uVar4 = read_volatile_4(Peripherals::RAC.SR0);
      write_volatile_4(Peripherals::RAC_CLR.SR0,uVar4 & 0x1c00);
      write_volatile_4(Peripherals::RAC_CLR.SR0,0x80);
      write_volatile_4(Peripherals::RAC_CLR.RXENSRCEN,0x10);
      if ((uVar4 & 0x1c00) == 0) {
        uVar4 = 0x40000;
      }
      else {
        if ((int)(uVar4 << 0x13) < 0) {
          uVar4 = 0x1000000;
        }
        else {
          if ((int)(uVar4 << 0x15) < 0) {
            uVar4 = 0x100000;
          }
          else {
            uVar4 = 0x400000;
          }
        }
      }
    }
    else {
      uVar4 = 0;
    }
    if ((int)(uVar6 << 0x1e) < 0) {
      uVar5 = read_volatile_4(Peripherals::RAC.SR0);
      write_volatile_4(Peripherals::RAC_CLR.SR0,uVar5 & 0xe000);
      if ((uVar5 & 0xe000) == 0) {
        uVar4 = uVar4 | 0x80000;
      }
      else {
        if ((int)(uVar5 << 0x10) < 0) {
          uVar4 = uVar4 | 0x2000000;
        }
        else {
          if ((int)(uVar5 << 0x12) < 0) {
            uVar4 = uVar4 | 0x200000;
          }
          else {
            uVar4 = uVar4 | 0x800000;
          }
        }
      }
    }
    if ((uVar6 & 0x2000) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = 8;
    }
  }
  uVar5 = 0;
  if ((uVar7 & 0x90b0a09) != 0) {
    if ((uVar7 & 0xa00) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,6);
    }
    if ((uVar7 & 9) != 0) {
      write_volatile_4(Peripherals::RAC.CMD,0x20);
      write_volatile_4(Peripherals::BUFC.BUF0_CMD,1);
      RAILInt_Assert(0,8);
    }
    if ((uVar7 & 0x9000000) != 0) {
      write_volatile_4(Peripherals::RAC.CMD,0x20);
      BUFC_TxAckBufferReset();
      RAILInt_Assert(0,9);
    }
    if ((uVar7 & 0xa0000) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,7);
    }
    if ((int)(uVar7 << 0xf) < 0) {
      BUFC_HandleRxLenOvfEvent();
    }
  }
  if ((int)(uVar7 << 0x1d) < 0) {
    if (_DAT_430204b4 == 0) {
      write_volatile_4(Peripherals::BUFC_SET.BUF0_THRESHOLDCTRL,0x2000);
    }
    else {
      uVar4 = uVar4 | 0x20000;
      write_volatile_4(Peripherals::BUFC_CLR.BUF0_THRESHOLDCTRL,0x2000);
    }
  }
  if ((int)(uVar7 << 0x15) < 0) {
    uVar4 = uVar4 | 4;
  }
  if ((uVar7 & 0x40000) != 0) {
    uVar2 = BUFC_StartRxLenThrEvent();
    switch(uVar2) {
    case 1:
    case 3:
      uVar4 = uVar4 | 0x1000;
      break;
    case 2:
      uVar4 = uVar4 | 0x200;
      break;
    case 4:
      uVar4 = uVar4 | 0x100;
      break;
    case 5:
      uVar4 = uVar4 | 0x80;
      break;
    case 6:
    case 7:
      uVar4 = uVar4 | 8;
      break;
    default:
      RAILInt_Assert(0,3);
    }
  }
  if (uVar10 != 0) {
    if ((uVar10 & 0x1000) != 0) {
      uVar4 = uVar4 | 0x4000;
    }
    if ((uVar10 & 0x100) != 0) {
      uVar4 = uVar4 | 0x8000;
    }
    if ((uVar10 & 0x2000) != 0) {
      uVar6 = uVar6 | 1;
    }
    if ((uVar10 & 0x200) != 0) {
      uVar4 = uVar4 | 0x10;
    }
    if ((uVar10 & 0x400) != 0) {
      uVar4 = uVar4 | 0x20;
    }
    if ((uVar10 & 0x800) != 0) {
      uVar4 = uVar4 | 0x40;
    }
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      uVar6 = uVar6 | 0x20;
    }
    if ((uVar8 & 0x4000000) != 0) {
      uVar6 = uVar6 | 0x40;
    }
    if ((uVar8 & 0x8000000) != 0) {
      uVar6 = uVar6 | 0x80;
    }
    if ((uVar8 & 0x40000) != 0) {
      uVar5 = 2;
    }
    if ((uVar8 & 0x10000) != 0) {
      uVar4 = uVar4 | 0x400;
    }
    if ((uVar8 & 0x100000) != 0) {
      uVar4 = uVar4 | 0x2000;
    }
    if ((uVar8 & 0x200000) != 0) {
      uVar4 = uVar4 | 2;
    }
    if (((uVar8 & 0x80000) != 0) && (iVar3 = GENERIC_PHY_CanModifyAck(), iVar3 != 0)) {
      uVar4 = uVar4 | 0x10000;
    }
  }
  if (uVar9 == 0) goto LAB_0000f236;
  if ((uVar9 & 0x800) != 0) {
    PROTIMER_CCTimerStop(3);
    write_volatile_4(Peripherals::PROTIMER_CLR.RXCTRL,0x1f1f);
    write_volatile_4(Peripherals::PROTIMER.IFC,0x800);
    PROTIMER_ClearTxEnable();
  }
  if ((uVar9 & 0x2000000) != 0) {
    PTI_AuxdataOutput(0x2b);
    uVar4 = uVar4 | 0x20000000;
  }
  if ((uVar9 & 0x700000) == 0) {
    if ((uVar9 & 0x1000) != 0) {
      if (iVar1 != 0) goto LAB_0000f120;
      PROTIMER_CCTimerStop(4);
      PROTIMER_CCTimerStop(3);
      PROTIMER_ClearRxEnable();
      irqState = CORE_EnterCritical();
      if (scheduledRxHardEnd != '\0') {
        RADIO_RACRxAbort();
      }
      iVar1 = BUFC_RxBufferBytesAvailable();
      uVar10 = read_volatile_4(Peripherals::RAC.STATUS);
      if (((uVar10 << 4) >> 0x1c == 3) || (iVar1 != 0)) {
        iVar1 = 1;
        pendedRxWindowEnd = scheduledRxLoop;
      }
      CORE_ExitCritical(irqState);
      if (iVar1 == 0) {
        overrideRxRollback = 0;
        GENERIC_PHY_ConfigureRollbackReporting();
        uVar10 = 0x800;
      }
      else {
        uVar10 = 0;
      }
      uVar4 = uVar4 | uVar10;
    }
  }
  else {
LAB_0000f120:
    uVar9 = PROTIMER_CheckCcaReallyFailed(uVar9);
    if ((uVar9 & 0x200000) != 0) {
      PTI_AuxdataOutput(0x29);
      uVar4 = uVar4 | 0x10000000;
    }
    if ((uVar9 & 0x400000) == 0) {
      if ((uVar9 & 0x100000) == 0) {
        if ((uVar9 & 0x1000) != 0) {
          PROTIMER_CCTimerStop(4);
          PROTIMER_LBTStop();
          uVar10 = read_volatile_4(Peripherals::PROTIMER.IF);
          if ((uVar10 & 0x500000) == 0) {
            PTI_AuxdataOutput(0x2a);
            write_volatile_4(Peripherals::BUFC.BUF0_CMD,1);
            goto LAB_0000f1ba;
          }
        }
      }
      else {
        PROTIMER_CCTimerStop(4);
        PTI_AuxdataOutput(0x28);
        uVar4 = uVar4 | 0x4000000;
      }
    }
    else {
      PROTIMER_CCTimerStop(4);
      PTI_AuxdataOutput(0x27);
      write_volatile_4(Peripherals::RAC_CLR.SR0,0x80);
      write_volatile_4(Peripherals::RAC_CLR.RXENSRCEN,0x10);
LAB_0000f1ba:
      uVar4 = uVar4 | 0x8000000;
    }
  }
  if ((uVar9 & 0x400) != 0) {
    PROTIMER_CCTimerStop(2);
    uVar6 = uVar6 | 4;
  }
LAB_0000f236:
  GENERIC_PHY_IssueCallback(enabledRailEvents & uVar4,DAT_200044f4 & uVar5,enabledPhyEvents & uVar6)
  ;
  if ((uVar7 & 0x40000) != 0) {
    BUFC_EndRxLenThrEvent();
    GENERIC_PHY_CheckPendedRxWindowEnd();
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      PA_RunPeakDetectorHigh();
    }
    if ((uVar8 & 0x4000000) != 0) {
      PA_RunPeakDetectorLow();
    }
    if ((uVar8 & 0x8000000) != 0) {
      PA_RunBatHigh();
      return;
    }
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void BUFC_IRQHandler(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  CORE_irqState_t irqState;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar4 = read_volatile_4(Peripherals::FRC.IF);
  uVar6 = read_volatile_4(Peripherals::FRC.IEN);
  uVar6 = uVar6 & uVar4;
  write_volatile_4(Peripherals::FRC.IFC,uVar6);
  uVar4 = read_volatile_4(Peripherals::BUFC.IF);
  uVar7 = read_volatile_4(Peripherals::BUFC.IEN);
  uVar7 = uVar7 & uVar4;
  write_volatile_4(Peripherals::BUFC.IFC,uVar7);
  uVar4 = read_volatile_4(Peripherals::MODEM.IF);
  uVar10 = read_volatile_4(Peripherals::MODEM.IEN);
  uVar10 = uVar10 & uVar4;
  write_volatile_4(Peripherals::MODEM.IFC,uVar10);
  uVar4 = read_volatile_4(Peripherals::RAC.IF);
  uVar8 = read_volatile_4(Peripherals::RAC.IEN);
  uVar8 = uVar8 & uVar4;
  write_volatile_4(Peripherals::RAC.IFC,uVar8 & 0xffff0000);
  iVar1 = PROTIMER_LBTIsActive();
  uVar4 = read_volatile_4(Peripherals::PROTIMER.IF);
  uVar9 = read_volatile_4(Peripherals::PROTIMER.IEN);
  uVar9 = uVar9 & uVar4;
  write_volatile_4(Peripherals::PROTIMER.IFC,uVar9 & 0xfffff7ff);
  if (uVar6 == 0) {
    uVar4 = 0;
  }
  else {
    if ((int)(uVar6 << 0x10) < 0) {
      uVar4 = read_volatile_4(Peripherals::RAC.SR0);
      write_volatile_4(Peripherals::RAC_CLR.SR0,uVar4 & 0x1c00);
      write_volatile_4(Peripherals::RAC_CLR.SR0,0x80);
      write_volatile_4(Peripherals::RAC_CLR.RXENSRCEN,0x10);
      if ((uVar4 & 0x1c00) == 0) {
        uVar4 = 0x40000;
      }
      else {
        if ((int)(uVar4 << 0x13) < 0) {
          uVar4 = 0x1000000;
        }
        else {
          if ((int)(uVar4 << 0x15) < 0) {
            uVar4 = 0x100000;
          }
          else {
            uVar4 = 0x400000;
          }
        }
      }
    }
    else {
      uVar4 = 0;
    }
    if ((int)(uVar6 << 0x1e) < 0) {
      uVar5 = read_volatile_4(Peripherals::RAC.SR0);
      write_volatile_4(Peripherals::RAC_CLR.SR0,uVar5 & 0xe000);
      if ((uVar5 & 0xe000) == 0) {
        uVar4 = uVar4 | 0x80000;
      }
      else {
        if ((int)(uVar5 << 0x10) < 0) {
          uVar4 = uVar4 | 0x2000000;
        }
        else {
          if ((int)(uVar5 << 0x12) < 0) {
            uVar4 = uVar4 | 0x200000;
          }
          else {
            uVar4 = uVar4 | 0x800000;
          }
        }
      }
    }
    if ((uVar6 & 0x2000) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = 8;
    }
  }
  uVar5 = 0;
  if ((uVar7 & 0x90b0a09) != 0) {
    if ((uVar7 & 0xa00) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,6);
    }
    if ((uVar7 & 9) != 0) {
      write_volatile_4(Peripherals::RAC.CMD,0x20);
      write_volatile_4(Peripherals::BUFC.BUF0_CMD,1);
      RAILInt_Assert(0,8);
    }
    if ((uVar7 & 0x9000000) != 0) {
      write_volatile_4(Peripherals::RAC.CMD,0x20);
      BUFC_TxAckBufferReset();
      RAILInt_Assert(0,9);
    }
    if ((uVar7 & 0xa0000) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,7);
    }
    if ((int)(uVar7 << 0xf) < 0) {
      BUFC_HandleRxLenOvfEvent();
    }
  }
  if ((int)(uVar7 << 0x1d) < 0) {
    if (_DAT_430204b4 == 0) {
      write_volatile_4(Peripherals::BUFC_SET.BUF0_THRESHOLDCTRL,0x2000);
    }
    else {
      uVar4 = uVar4 | 0x20000;
      write_volatile_4(Peripherals::BUFC_CLR.BUF0_THRESHOLDCTRL,0x2000);
    }
  }
  if ((int)(uVar7 << 0x15) < 0) {
    uVar4 = uVar4 | 4;
  }
  if ((uVar7 & 0x40000) != 0) {
    uVar2 = BUFC_StartRxLenThrEvent();
    switch(uVar2) {
    case 1:
    case 3:
      uVar4 = uVar4 | 0x1000;
      break;
    case 2:
      uVar4 = uVar4 | 0x200;
      break;
    case 4:
      uVar4 = uVar4 | 0x100;
      break;
    case 5:
      uVar4 = uVar4 | 0x80;
      break;
    case 6:
    case 7:
      uVar4 = uVar4 | 8;
      break;
    default:
      RAILInt_Assert(0,3);
    }
  }
  if (uVar10 != 0) {
    if ((uVar10 & 0x1000) != 0) {
      uVar4 = uVar4 | 0x4000;
    }
    if ((uVar10 & 0x100) != 0) {
      uVar4 = uVar4 | 0x8000;
    }
    if ((uVar10 & 0x2000) != 0) {
      uVar6 = uVar6 | 1;
    }
    if ((uVar10 & 0x200) != 0) {
      uVar4 = uVar4 | 0x10;
    }
    if ((uVar10 & 0x400) != 0) {
      uVar4 = uVar4 | 0x20;
    }
    if ((uVar10 & 0x800) != 0) {
      uVar4 = uVar4 | 0x40;
    }
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      uVar6 = uVar6 | 0x20;
    }
    if ((uVar8 & 0x4000000) != 0) {
      uVar6 = uVar6 | 0x40;
    }
    if ((uVar8 & 0x8000000) != 0) {
      uVar6 = uVar6 | 0x80;
    }
    if ((uVar8 & 0x40000) != 0) {
      uVar5 = 2;
    }
    if ((uVar8 & 0x10000) != 0) {
      uVar4 = uVar4 | 0x400;
    }
    if ((uVar8 & 0x100000) != 0) {
      uVar4 = uVar4 | 0x2000;
    }
    if ((uVar8 & 0x200000) != 0) {
      uVar4 = uVar4 | 2;
    }
    if (((uVar8 & 0x80000) != 0) && (iVar3 = GENERIC_PHY_CanModifyAck(), iVar3 != 0)) {
      uVar4 = uVar4 | 0x10000;
    }
  }
  if (uVar9 == 0) goto LAB_0000f236;
  if ((uVar9 & 0x800) != 0) {
    PROTIMER_CCTimerStop(3);
    write_volatile_4(Peripherals::PROTIMER_CLR.RXCTRL,0x1f1f);
    write_volatile_4(Peripherals::PROTIMER.IFC,0x800);
    PROTIMER_ClearTxEnable();
  }
  if ((uVar9 & 0x2000000) != 0) {
    PTI_AuxdataOutput(0x2b);
    uVar4 = uVar4 | 0x20000000;
  }
  if ((uVar9 & 0x700000) == 0) {
    if ((uVar9 & 0x1000) != 0) {
      if (iVar1 != 0) goto LAB_0000f120;
      PROTIMER_CCTimerStop(4);
      PROTIMER_CCTimerStop(3);
      PROTIMER_ClearRxEnable();
      irqState = CORE_EnterCritical();
      if (scheduledRxHardEnd != '\0') {
        RADIO_RACRxAbort();
      }
      iVar1 = BUFC_RxBufferBytesAvailable();
      uVar10 = read_volatile_4(Peripherals::RAC.STATUS);
      if (((uVar10 << 4) >> 0x1c == 3) || (iVar1 != 0)) {
        iVar1 = 1;
        pendedRxWindowEnd = scheduledRxLoop;
      }
      CORE_ExitCritical(irqState);
      if (iVar1 == 0) {
        overrideRxRollback = 0;
        GENERIC_PHY_ConfigureRollbackReporting();
        uVar10 = 0x800;
      }
      else {
        uVar10 = 0;
      }
      uVar4 = uVar4 | uVar10;
    }
  }
  else {
LAB_0000f120:
    uVar9 = PROTIMER_CheckCcaReallyFailed(uVar9);
    if ((uVar9 & 0x200000) != 0) {
      PTI_AuxdataOutput(0x29);
      uVar4 = uVar4 | 0x10000000;
    }
    if ((uVar9 & 0x400000) == 0) {
      if ((uVar9 & 0x100000) == 0) {
        if ((uVar9 & 0x1000) != 0) {
          PROTIMER_CCTimerStop(4);
          PROTIMER_LBTStop();
          uVar10 = read_volatile_4(Peripherals::PROTIMER.IF);
          if ((uVar10 & 0x500000) == 0) {
            PTI_AuxdataOutput(0x2a);
            write_volatile_4(Peripherals::BUFC.BUF0_CMD,1);
            goto LAB_0000f1ba;
          }
        }
      }
      else {
        PROTIMER_CCTimerStop(4);
        PTI_AuxdataOutput(0x28);
        uVar4 = uVar4 | 0x4000000;
      }
    }
    else {
      PROTIMER_CCTimerStop(4);
      PTI_AuxdataOutput(0x27);
      write_volatile_4(Peripherals::RAC_CLR.SR0,0x80);
      write_volatile_4(Peripherals::RAC_CLR.RXENSRCEN,0x10);
LAB_0000f1ba:
      uVar4 = uVar4 | 0x8000000;
    }
  }
  if ((uVar9 & 0x400) != 0) {
    PROTIMER_CCTimerStop(2);
    uVar6 = uVar6 | 4;
  }
LAB_0000f236:
  GENERIC_PHY_IssueCallback(enabledRailEvents & uVar4,DAT_200044f4 & uVar5,enabledPhyEvents & uVar6)
  ;
  if ((uVar7 & 0x40000) != 0) {
    BUFC_EndRxLenThrEvent();
    GENERIC_PHY_CheckPendedRxWindowEnd();
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      PA_RunPeakDetectorHigh();
    }
    if ((uVar8 & 0x4000000) != 0) {
      PA_RunPeakDetectorLow();
    }
    if ((uVar8 & 0x8000000) != 0) {
      PA_RunBatHigh();
      return;
    }
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_IRQHandler(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  CORE_irqState_t irqState;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar4 = read_volatile_4(Peripherals::FRC.IF);
  uVar6 = read_volatile_4(Peripherals::FRC.IEN);
  uVar6 = uVar6 & uVar4;
  write_volatile_4(Peripherals::FRC.IFC,uVar6);
  uVar4 = read_volatile_4(Peripherals::BUFC.IF);
  uVar7 = read_volatile_4(Peripherals::BUFC.IEN);
  uVar7 = uVar7 & uVar4;
  write_volatile_4(Peripherals::BUFC.IFC,uVar7);
  uVar4 = read_volatile_4(Peripherals::MODEM.IF);
  uVar10 = read_volatile_4(Peripherals::MODEM.IEN);
  uVar10 = uVar10 & uVar4;
  write_volatile_4(Peripherals::MODEM.IFC,uVar10);
  uVar4 = read_volatile_4(Peripherals::RAC.IF);
  uVar8 = read_volatile_4(Peripherals::RAC.IEN);
  uVar8 = uVar8 & uVar4;
  write_volatile_4(Peripherals::RAC.IFC,uVar8 & 0xffff0000);
  iVar1 = PROTIMER_LBTIsActive();
  uVar4 = read_volatile_4(Peripherals::PROTIMER.IF);
  uVar9 = read_volatile_4(Peripherals::PROTIMER.IEN);
  uVar9 = uVar9 & uVar4;
  write_volatile_4(Peripherals::PROTIMER.IFC,uVar9 & 0xfffff7ff);
  if (uVar6 == 0) {
    uVar4 = 0;
  }
  else {
    if ((int)(uVar6 << 0x10) < 0) {
      uVar4 = read_volatile_4(Peripherals::RAC.SR0);
      write_volatile_4(Peripherals::RAC_CLR.SR0,uVar4 & 0x1c00);
      write_volatile_4(Peripherals::RAC_CLR.SR0,0x80);
      write_volatile_4(Peripherals::RAC_CLR.RXENSRCEN,0x10);
      if ((uVar4 & 0x1c00) == 0) {
        uVar4 = 0x40000;
      }
      else {
        if ((int)(uVar4 << 0x13) < 0) {
          uVar4 = 0x1000000;
        }
        else {
          if ((int)(uVar4 << 0x15) < 0) {
            uVar4 = 0x100000;
          }
          else {
            uVar4 = 0x400000;
          }
        }
      }
    }
    else {
      uVar4 = 0;
    }
    if ((int)(uVar6 << 0x1e) < 0) {
      uVar5 = read_volatile_4(Peripherals::RAC.SR0);
      write_volatile_4(Peripherals::RAC_CLR.SR0,uVar5 & 0xe000);
      if ((uVar5 & 0xe000) == 0) {
        uVar4 = uVar4 | 0x80000;
      }
      else {
        if ((int)(uVar5 << 0x10) < 0) {
          uVar4 = uVar4 | 0x2000000;
        }
        else {
          if ((int)(uVar5 << 0x12) < 0) {
            uVar4 = uVar4 | 0x200000;
          }
          else {
            uVar4 = uVar4 | 0x800000;
          }
        }
      }
    }
    if ((uVar6 & 0x2000) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = 8;
    }
  }
  uVar5 = 0;
  if ((uVar7 & 0x90b0a09) != 0) {
    if ((uVar7 & 0xa00) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,6);
    }
    if ((uVar7 & 9) != 0) {
      write_volatile_4(Peripherals::RAC.CMD,0x20);
      write_volatile_4(Peripherals::BUFC.BUF0_CMD,1);
      RAILInt_Assert(0,8);
    }
    if ((uVar7 & 0x9000000) != 0) {
      write_volatile_4(Peripherals::RAC.CMD,0x20);
      BUFC_TxAckBufferReset();
      RAILInt_Assert(0,9);
    }
    if ((uVar7 & 0xa0000) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,7);
    }
    if ((int)(uVar7 << 0xf) < 0) {
      BUFC_HandleRxLenOvfEvent();
    }
  }
  if ((int)(uVar7 << 0x1d) < 0) {
    if (_DAT_430204b4 == 0) {
      write_volatile_4(Peripherals::BUFC_SET.BUF0_THRESHOLDCTRL,0x2000);
    }
    else {
      uVar4 = uVar4 | 0x20000;
      write_volatile_4(Peripherals::BUFC_CLR.BUF0_THRESHOLDCTRL,0x2000);
    }
  }
  if ((int)(uVar7 << 0x15) < 0) {
    uVar4 = uVar4 | 4;
  }
  if ((uVar7 & 0x40000) != 0) {
    uVar2 = BUFC_StartRxLenThrEvent();
    switch(uVar2) {
    case 1:
    case 3:
      uVar4 = uVar4 | 0x1000;
      break;
    case 2:
      uVar4 = uVar4 | 0x200;
      break;
    case 4:
      uVar4 = uVar4 | 0x100;
      break;
    case 5:
      uVar4 = uVar4 | 0x80;
      break;
    case 6:
    case 7:
      uVar4 = uVar4 | 8;
      break;
    default:
      RAILInt_Assert(0,3);
    }
  }
  if (uVar10 != 0) {
    if ((uVar10 & 0x1000) != 0) {
      uVar4 = uVar4 | 0x4000;
    }
    if ((uVar10 & 0x100) != 0) {
      uVar4 = uVar4 | 0x8000;
    }
    if ((uVar10 & 0x2000) != 0) {
      uVar6 = uVar6 | 1;
    }
    if ((uVar10 & 0x200) != 0) {
      uVar4 = uVar4 | 0x10;
    }
    if ((uVar10 & 0x400) != 0) {
      uVar4 = uVar4 | 0x20;
    }
    if ((uVar10 & 0x800) != 0) {
      uVar4 = uVar4 | 0x40;
    }
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      uVar6 = uVar6 | 0x20;
    }
    if ((uVar8 & 0x4000000) != 0) {
      uVar6 = uVar6 | 0x40;
    }
    if ((uVar8 & 0x8000000) != 0) {
      uVar6 = uVar6 | 0x80;
    }
    if ((uVar8 & 0x40000) != 0) {
      uVar5 = 2;
    }
    if ((uVar8 & 0x10000) != 0) {
      uVar4 = uVar4 | 0x400;
    }
    if ((uVar8 & 0x100000) != 0) {
      uVar4 = uVar4 | 0x2000;
    }
    if ((uVar8 & 0x200000) != 0) {
      uVar4 = uVar4 | 2;
    }
    if (((uVar8 & 0x80000) != 0) && (iVar3 = GENERIC_PHY_CanModifyAck(), iVar3 != 0)) {
      uVar4 = uVar4 | 0x10000;
    }
  }
  if (uVar9 == 0) goto LAB_0000f236;
  if ((uVar9 & 0x800) != 0) {
    PROTIMER_CCTimerStop(3);
    write_volatile_4(Peripherals::PROTIMER_CLR.RXCTRL,0x1f1f);
    write_volatile_4(Peripherals::PROTIMER.IFC,0x800);
    PROTIMER_ClearTxEnable();
  }
  if ((uVar9 & 0x2000000) != 0) {
    PTI_AuxdataOutput(0x2b);
    uVar4 = uVar4 | 0x20000000;
  }
  if ((uVar9 & 0x700000) == 0) {
    if ((uVar9 & 0x1000) != 0) {
      if (iVar1 != 0) goto LAB_0000f120;
      PROTIMER_CCTimerStop(4);
      PROTIMER_CCTimerStop(3);
      PROTIMER_ClearRxEnable();
      irqState = CORE_EnterCritical();
      if (scheduledRxHardEnd != '\0') {
        RADIO_RACRxAbort();
      }
      iVar1 = BUFC_RxBufferBytesAvailable();
      uVar10 = read_volatile_4(Peripherals::RAC.STATUS);
      if (((uVar10 << 4) >> 0x1c == 3) || (iVar1 != 0)) {
        iVar1 = 1;
        pendedRxWindowEnd = scheduledRxLoop;
      }
      CORE_ExitCritical(irqState);
      if (iVar1 == 0) {
        overrideRxRollback = 0;
        GENERIC_PHY_ConfigureRollbackReporting();
        uVar10 = 0x800;
      }
      else {
        uVar10 = 0;
      }
      uVar4 = uVar4 | uVar10;
    }
  }
  else {
LAB_0000f120:
    uVar9 = PROTIMER_CheckCcaReallyFailed(uVar9);
    if ((uVar9 & 0x200000) != 0) {
      PTI_AuxdataOutput(0x29);
      uVar4 = uVar4 | 0x10000000;
    }
    if ((uVar9 & 0x400000) == 0) {
      if ((uVar9 & 0x100000) == 0) {
        if ((uVar9 & 0x1000) != 0) {
          PROTIMER_CCTimerStop(4);
          PROTIMER_LBTStop();
          uVar10 = read_volatile_4(Peripherals::PROTIMER.IF);
          if ((uVar10 & 0x500000) == 0) {
            PTI_AuxdataOutput(0x2a);
            write_volatile_4(Peripherals::BUFC.BUF0_CMD,1);
            goto LAB_0000f1ba;
          }
        }
      }
      else {
        PROTIMER_CCTimerStop(4);
        PTI_AuxdataOutput(0x28);
        uVar4 = uVar4 | 0x4000000;
      }
    }
    else {
      PROTIMER_CCTimerStop(4);
      PTI_AuxdataOutput(0x27);
      write_volatile_4(Peripherals::RAC_CLR.SR0,0x80);
      write_volatile_4(Peripherals::RAC_CLR.RXENSRCEN,0x10);
LAB_0000f1ba:
      uVar4 = uVar4 | 0x8000000;
    }
  }
  if ((uVar9 & 0x400) != 0) {
    PROTIMER_CCTimerStop(2);
    uVar6 = uVar6 | 4;
  }
LAB_0000f236:
  GENERIC_PHY_IssueCallback(enabledRailEvents & uVar4,DAT_200044f4 & uVar5,enabledPhyEvents & uVar6)
  ;
  if ((uVar7 & 0x40000) != 0) {
    BUFC_EndRxLenThrEvent();
    GENERIC_PHY_CheckPendedRxWindowEnd();
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      PA_RunPeakDetectorHigh();
    }
    if ((uVar8 & 0x4000000) != 0) {
      PA_RunPeakDetectorLow();
    }
    if ((uVar8 & 0x8000000) != 0) {
      PA_RunBatHigh();
      return;
    }
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RAC_SEQ_IRQHandler(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  CORE_irqState_t irqState;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar4 = read_volatile_4(Peripherals::FRC.IF);
  uVar6 = read_volatile_4(Peripherals::FRC.IEN);
  uVar6 = uVar6 & uVar4;
  write_volatile_4(Peripherals::FRC.IFC,uVar6);
  uVar4 = read_volatile_4(Peripherals::BUFC.IF);
  uVar7 = read_volatile_4(Peripherals::BUFC.IEN);
  uVar7 = uVar7 & uVar4;
  write_volatile_4(Peripherals::BUFC.IFC,uVar7);
  uVar4 = read_volatile_4(Peripherals::MODEM.IF);
  uVar10 = read_volatile_4(Peripherals::MODEM.IEN);
  uVar10 = uVar10 & uVar4;
  write_volatile_4(Peripherals::MODEM.IFC,uVar10);
  uVar4 = read_volatile_4(Peripherals::RAC.IF);
  uVar8 = read_volatile_4(Peripherals::RAC.IEN);
  uVar8 = uVar8 & uVar4;
  write_volatile_4(Peripherals::RAC.IFC,uVar8 & 0xffff0000);
  iVar1 = PROTIMER_LBTIsActive();
  uVar4 = read_volatile_4(Peripherals::PROTIMER.IF);
  uVar9 = read_volatile_4(Peripherals::PROTIMER.IEN);
  uVar9 = uVar9 & uVar4;
  write_volatile_4(Peripherals::PROTIMER.IFC,uVar9 & 0xfffff7ff);
  if (uVar6 == 0) {
    uVar4 = 0;
  }
  else {
    if ((int)(uVar6 << 0x10) < 0) {
      uVar4 = read_volatile_4(Peripherals::RAC.SR0);
      write_volatile_4(Peripherals::RAC_CLR.SR0,uVar4 & 0x1c00);
      write_volatile_4(Peripherals::RAC_CLR.SR0,0x80);
      write_volatile_4(Peripherals::RAC_CLR.RXENSRCEN,0x10);
      if ((uVar4 & 0x1c00) == 0) {
        uVar4 = 0x40000;
      }
      else {
        if ((int)(uVar4 << 0x13) < 0) {
          uVar4 = 0x1000000;
        }
        else {
          if ((int)(uVar4 << 0x15) < 0) {
            uVar4 = 0x100000;
          }
          else {
            uVar4 = 0x400000;
          }
        }
      }
    }
    else {
      uVar4 = 0;
    }
    if ((int)(uVar6 << 0x1e) < 0) {
      uVar5 = read_volatile_4(Peripherals::RAC.SR0);
      write_volatile_4(Peripherals::RAC_CLR.SR0,uVar5 & 0xe000);
      if ((uVar5 & 0xe000) == 0) {
        uVar4 = uVar4 | 0x80000;
      }
      else {
        if ((int)(uVar5 << 0x10) < 0) {
          uVar4 = uVar4 | 0x2000000;
        }
        else {
          if ((int)(uVar5 << 0x12) < 0) {
            uVar4 = uVar4 | 0x200000;
          }
          else {
            uVar4 = uVar4 | 0x800000;
          }
        }
      }
    }
    if ((uVar6 & 0x2000) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = 8;
    }
  }
  uVar5 = 0;
  if ((uVar7 & 0x90b0a09) != 0) {
    if ((uVar7 & 0xa00) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,6);
    }
    if ((uVar7 & 9) != 0) {
      write_volatile_4(Peripherals::RAC.CMD,0x20);
      write_volatile_4(Peripherals::BUFC.BUF0_CMD,1);
      RAILInt_Assert(0,8);
    }
    if ((uVar7 & 0x9000000) != 0) {
      write_volatile_4(Peripherals::RAC.CMD,0x20);
      BUFC_TxAckBufferReset();
      RAILInt_Assert(0,9);
    }
    if ((uVar7 & 0xa0000) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,7);
    }
    if ((int)(uVar7 << 0xf) < 0) {
      BUFC_HandleRxLenOvfEvent();
    }
  }
  if ((int)(uVar7 << 0x1d) < 0) {
    if (_DAT_430204b4 == 0) {
      write_volatile_4(Peripherals::BUFC_SET.BUF0_THRESHOLDCTRL,0x2000);
    }
    else {
      uVar4 = uVar4 | 0x20000;
      write_volatile_4(Peripherals::BUFC_CLR.BUF0_THRESHOLDCTRL,0x2000);
    }
  }
  if ((int)(uVar7 << 0x15) < 0) {
    uVar4 = uVar4 | 4;
  }
  if ((uVar7 & 0x40000) != 0) {
    uVar2 = BUFC_StartRxLenThrEvent();
    switch(uVar2) {
    case 1:
    case 3:
      uVar4 = uVar4 | 0x1000;
      break;
    case 2:
      uVar4 = uVar4 | 0x200;
      break;
    case 4:
      uVar4 = uVar4 | 0x100;
      break;
    case 5:
      uVar4 = uVar4 | 0x80;
      break;
    case 6:
    case 7:
      uVar4 = uVar4 | 8;
      break;
    default:
      RAILInt_Assert(0,3);
    }
  }
  if (uVar10 != 0) {
    if ((uVar10 & 0x1000) != 0) {
      uVar4 = uVar4 | 0x4000;
    }
    if ((uVar10 & 0x100) != 0) {
      uVar4 = uVar4 | 0x8000;
    }
    if ((uVar10 & 0x2000) != 0) {
      uVar6 = uVar6 | 1;
    }
    if ((uVar10 & 0x200) != 0) {
      uVar4 = uVar4 | 0x10;
    }
    if ((uVar10 & 0x400) != 0) {
      uVar4 = uVar4 | 0x20;
    }
    if ((uVar10 & 0x800) != 0) {
      uVar4 = uVar4 | 0x40;
    }
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      uVar6 = uVar6 | 0x20;
    }
    if ((uVar8 & 0x4000000) != 0) {
      uVar6 = uVar6 | 0x40;
    }
    if ((uVar8 & 0x8000000) != 0) {
      uVar6 = uVar6 | 0x80;
    }
    if ((uVar8 & 0x40000) != 0) {
      uVar5 = 2;
    }
    if ((uVar8 & 0x10000) != 0) {
      uVar4 = uVar4 | 0x400;
    }
    if ((uVar8 & 0x100000) != 0) {
      uVar4 = uVar4 | 0x2000;
    }
    if ((uVar8 & 0x200000) != 0) {
      uVar4 = uVar4 | 2;
    }
    if (((uVar8 & 0x80000) != 0) && (iVar3 = GENERIC_PHY_CanModifyAck(), iVar3 != 0)) {
      uVar4 = uVar4 | 0x10000;
    }
  }
  if (uVar9 == 0) goto LAB_0000f236;
  if ((uVar9 & 0x800) != 0) {
    PROTIMER_CCTimerStop(3);
    write_volatile_4(Peripherals::PROTIMER_CLR.RXCTRL,0x1f1f);
    write_volatile_4(Peripherals::PROTIMER.IFC,0x800);
    PROTIMER_ClearTxEnable();
  }
  if ((uVar9 & 0x2000000) != 0) {
    PTI_AuxdataOutput(0x2b);
    uVar4 = uVar4 | 0x20000000;
  }
  if ((uVar9 & 0x700000) == 0) {
    if ((uVar9 & 0x1000) != 0) {
      if (iVar1 != 0) goto LAB_0000f120;
      PROTIMER_CCTimerStop(4);
      PROTIMER_CCTimerStop(3);
      PROTIMER_ClearRxEnable();
      irqState = CORE_EnterCritical();
      if (scheduledRxHardEnd != '\0') {
        RADIO_RACRxAbort();
      }
      iVar1 = BUFC_RxBufferBytesAvailable();
      uVar10 = read_volatile_4(Peripherals::RAC.STATUS);
      if (((uVar10 << 4) >> 0x1c == 3) || (iVar1 != 0)) {
        iVar1 = 1;
        pendedRxWindowEnd = scheduledRxLoop;
      }
      CORE_ExitCritical(irqState);
      if (iVar1 == 0) {
        overrideRxRollback = 0;
        GENERIC_PHY_ConfigureRollbackReporting();
        uVar10 = 0x800;
      }
      else {
        uVar10 = 0;
      }
      uVar4 = uVar4 | uVar10;
    }
  }
  else {
LAB_0000f120:
    uVar9 = PROTIMER_CheckCcaReallyFailed(uVar9);
    if ((uVar9 & 0x200000) != 0) {
      PTI_AuxdataOutput(0x29);
      uVar4 = uVar4 | 0x10000000;
    }
    if ((uVar9 & 0x400000) == 0) {
      if ((uVar9 & 0x100000) == 0) {
        if ((uVar9 & 0x1000) != 0) {
          PROTIMER_CCTimerStop(4);
          PROTIMER_LBTStop();
          uVar10 = read_volatile_4(Peripherals::PROTIMER.IF);
          if ((uVar10 & 0x500000) == 0) {
            PTI_AuxdataOutput(0x2a);
            write_volatile_4(Peripherals::BUFC.BUF0_CMD,1);
            goto LAB_0000f1ba;
          }
        }
      }
      else {
        PROTIMER_CCTimerStop(4);
        PTI_AuxdataOutput(0x28);
        uVar4 = uVar4 | 0x4000000;
      }
    }
    else {
      PROTIMER_CCTimerStop(4);
      PTI_AuxdataOutput(0x27);
      write_volatile_4(Peripherals::RAC_CLR.SR0,0x80);
      write_volatile_4(Peripherals::RAC_CLR.RXENSRCEN,0x10);
LAB_0000f1ba:
      uVar4 = uVar4 | 0x8000000;
    }
  }
  if ((uVar9 & 0x400) != 0) {
    PROTIMER_CCTimerStop(2);
    uVar6 = uVar6 | 4;
  }
LAB_0000f236:
  GENERIC_PHY_IssueCallback(enabledRailEvents & uVar4,DAT_200044f4 & uVar5,enabledPhyEvents & uVar6)
  ;
  if ((uVar7 & 0x40000) != 0) {
    BUFC_EndRxLenThrEvent();
    GENERIC_PHY_CheckPendedRxWindowEnd();
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      PA_RunPeakDetectorHigh();
    }
    if ((uVar8 & 0x4000000) != 0) {
      PA_RunPeakDetectorLow();
    }
    if ((uVar8 & 0x8000000) != 0) {
      PA_RunBatHigh();
      return;
    }
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void MODEM_IRQHandler(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  CORE_irqState_t irqState;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar4 = read_volatile_4(Peripherals::FRC.IF);
  uVar6 = read_volatile_4(Peripherals::FRC.IEN);
  uVar6 = uVar6 & uVar4;
  write_volatile_4(Peripherals::FRC.IFC,uVar6);
  uVar4 = read_volatile_4(Peripherals::BUFC.IF);
  uVar7 = read_volatile_4(Peripherals::BUFC.IEN);
  uVar7 = uVar7 & uVar4;
  write_volatile_4(Peripherals::BUFC.IFC,uVar7);
  uVar4 = read_volatile_4(Peripherals::MODEM.IF);
  uVar10 = read_volatile_4(Peripherals::MODEM.IEN);
  uVar10 = uVar10 & uVar4;
  write_volatile_4(Peripherals::MODEM.IFC,uVar10);
  uVar4 = read_volatile_4(Peripherals::RAC.IF);
  uVar8 = read_volatile_4(Peripherals::RAC.IEN);
  uVar8 = uVar8 & uVar4;
  write_volatile_4(Peripherals::RAC.IFC,uVar8 & 0xffff0000);
  iVar1 = PROTIMER_LBTIsActive();
  uVar4 = read_volatile_4(Peripherals::PROTIMER.IF);
  uVar9 = read_volatile_4(Peripherals::PROTIMER.IEN);
  uVar9 = uVar9 & uVar4;
  write_volatile_4(Peripherals::PROTIMER.IFC,uVar9 & 0xfffff7ff);
  if (uVar6 == 0) {
    uVar4 = 0;
  }
  else {
    if ((int)(uVar6 << 0x10) < 0) {
      uVar4 = read_volatile_4(Peripherals::RAC.SR0);
      write_volatile_4(Peripherals::RAC_CLR.SR0,uVar4 & 0x1c00);
      write_volatile_4(Peripherals::RAC_CLR.SR0,0x80);
      write_volatile_4(Peripherals::RAC_CLR.RXENSRCEN,0x10);
      if ((uVar4 & 0x1c00) == 0) {
        uVar4 = 0x40000;
      }
      else {
        if ((int)(uVar4 << 0x13) < 0) {
          uVar4 = 0x1000000;
        }
        else {
          if ((int)(uVar4 << 0x15) < 0) {
            uVar4 = 0x100000;
          }
          else {
            uVar4 = 0x400000;
          }
        }
      }
    }
    else {
      uVar4 = 0;
    }
    if ((int)(uVar6 << 0x1e) < 0) {
      uVar5 = read_volatile_4(Peripherals::RAC.SR0);
      write_volatile_4(Peripherals::RAC_CLR.SR0,uVar5 & 0xe000);
      if ((uVar5 & 0xe000) == 0) {
        uVar4 = uVar4 | 0x80000;
      }
      else {
        if ((int)(uVar5 << 0x10) < 0) {
          uVar4 = uVar4 | 0x2000000;
        }
        else {
          if ((int)(uVar5 << 0x12) < 0) {
            uVar4 = uVar4 | 0x200000;
          }
          else {
            uVar4 = uVar4 | 0x800000;
          }
        }
      }
    }
    if ((uVar6 & 0x2000) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = 8;
    }
  }
  uVar5 = 0;
  if ((uVar7 & 0x90b0a09) != 0) {
    if ((uVar7 & 0xa00) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,6);
    }
    if ((uVar7 & 9) != 0) {
      write_volatile_4(Peripherals::RAC.CMD,0x20);
      write_volatile_4(Peripherals::BUFC.BUF0_CMD,1);
      RAILInt_Assert(0,8);
    }
    if ((uVar7 & 0x9000000) != 0) {
      write_volatile_4(Peripherals::RAC.CMD,0x20);
      BUFC_TxAckBufferReset();
      RAILInt_Assert(0,9);
    }
    if ((uVar7 & 0xa0000) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,7);
    }
    if ((int)(uVar7 << 0xf) < 0) {
      BUFC_HandleRxLenOvfEvent();
    }
  }
  if ((int)(uVar7 << 0x1d) < 0) {
    if (_DAT_430204b4 == 0) {
      write_volatile_4(Peripherals::BUFC_SET.BUF0_THRESHOLDCTRL,0x2000);
    }
    else {
      uVar4 = uVar4 | 0x20000;
      write_volatile_4(Peripherals::BUFC_CLR.BUF0_THRESHOLDCTRL,0x2000);
    }
  }
  if ((int)(uVar7 << 0x15) < 0) {
    uVar4 = uVar4 | 4;
  }
  if ((uVar7 & 0x40000) != 0) {
    uVar2 = BUFC_StartRxLenThrEvent();
    switch(uVar2) {
    case 1:
    case 3:
      uVar4 = uVar4 | 0x1000;
      break;
    case 2:
      uVar4 = uVar4 | 0x200;
      break;
    case 4:
      uVar4 = uVar4 | 0x100;
      break;
    case 5:
      uVar4 = uVar4 | 0x80;
      break;
    case 6:
    case 7:
      uVar4 = uVar4 | 8;
      break;
    default:
      RAILInt_Assert(0,3);
    }
  }
  if (uVar10 != 0) {
    if ((uVar10 & 0x1000) != 0) {
      uVar4 = uVar4 | 0x4000;
    }
    if ((uVar10 & 0x100) != 0) {
      uVar4 = uVar4 | 0x8000;
    }
    if ((uVar10 & 0x2000) != 0) {
      uVar6 = uVar6 | 1;
    }
    if ((uVar10 & 0x200) != 0) {
      uVar4 = uVar4 | 0x10;
    }
    if ((uVar10 & 0x400) != 0) {
      uVar4 = uVar4 | 0x20;
    }
    if ((uVar10 & 0x800) != 0) {
      uVar4 = uVar4 | 0x40;
    }
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      uVar6 = uVar6 | 0x20;
    }
    if ((uVar8 & 0x4000000) != 0) {
      uVar6 = uVar6 | 0x40;
    }
    if ((uVar8 & 0x8000000) != 0) {
      uVar6 = uVar6 | 0x80;
    }
    if ((uVar8 & 0x40000) != 0) {
      uVar5 = 2;
    }
    if ((uVar8 & 0x10000) != 0) {
      uVar4 = uVar4 | 0x400;
    }
    if ((uVar8 & 0x100000) != 0) {
      uVar4 = uVar4 | 0x2000;
    }
    if ((uVar8 & 0x200000) != 0) {
      uVar4 = uVar4 | 2;
    }
    if (((uVar8 & 0x80000) != 0) && (iVar3 = GENERIC_PHY_CanModifyAck(), iVar3 != 0)) {
      uVar4 = uVar4 | 0x10000;
    }
  }
  if (uVar9 == 0) goto LAB_0000f236;
  if ((uVar9 & 0x800) != 0) {
    PROTIMER_CCTimerStop(3);
    write_volatile_4(Peripherals::PROTIMER_CLR.RXCTRL,0x1f1f);
    write_volatile_4(Peripherals::PROTIMER.IFC,0x800);
    PROTIMER_ClearTxEnable();
  }
  if ((uVar9 & 0x2000000) != 0) {
    PTI_AuxdataOutput(0x2b);
    uVar4 = uVar4 | 0x20000000;
  }
  if ((uVar9 & 0x700000) == 0) {
    if ((uVar9 & 0x1000) != 0) {
      if (iVar1 != 0) goto LAB_0000f120;
      PROTIMER_CCTimerStop(4);
      PROTIMER_CCTimerStop(3);
      PROTIMER_ClearRxEnable();
      irqState = CORE_EnterCritical();
      if (scheduledRxHardEnd != '\0') {
        RADIO_RACRxAbort();
      }
      iVar1 = BUFC_RxBufferBytesAvailable();
      uVar10 = read_volatile_4(Peripherals::RAC.STATUS);
      if (((uVar10 << 4) >> 0x1c == 3) || (iVar1 != 0)) {
        iVar1 = 1;
        pendedRxWindowEnd = scheduledRxLoop;
      }
      CORE_ExitCritical(irqState);
      if (iVar1 == 0) {
        overrideRxRollback = 0;
        GENERIC_PHY_ConfigureRollbackReporting();
        uVar10 = 0x800;
      }
      else {
        uVar10 = 0;
      }
      uVar4 = uVar4 | uVar10;
    }
  }
  else {
LAB_0000f120:
    uVar9 = PROTIMER_CheckCcaReallyFailed(uVar9);
    if ((uVar9 & 0x200000) != 0) {
      PTI_AuxdataOutput(0x29);
      uVar4 = uVar4 | 0x10000000;
    }
    if ((uVar9 & 0x400000) == 0) {
      if ((uVar9 & 0x100000) == 0) {
        if ((uVar9 & 0x1000) != 0) {
          PROTIMER_CCTimerStop(4);
          PROTIMER_LBTStop();
          uVar10 = read_volatile_4(Peripherals::PROTIMER.IF);
          if ((uVar10 & 0x500000) == 0) {
            PTI_AuxdataOutput(0x2a);
            write_volatile_4(Peripherals::BUFC.BUF0_CMD,1);
            goto LAB_0000f1ba;
          }
        }
      }
      else {
        PROTIMER_CCTimerStop(4);
        PTI_AuxdataOutput(0x28);
        uVar4 = uVar4 | 0x4000000;
      }
    }
    else {
      PROTIMER_CCTimerStop(4);
      PTI_AuxdataOutput(0x27);
      write_volatile_4(Peripherals::RAC_CLR.SR0,0x80);
      write_volatile_4(Peripherals::RAC_CLR.RXENSRCEN,0x10);
LAB_0000f1ba:
      uVar4 = uVar4 | 0x8000000;
    }
  }
  if ((uVar9 & 0x400) != 0) {
    PROTIMER_CCTimerStop(2);
    uVar6 = uVar6 | 4;
  }
LAB_0000f236:
  GENERIC_PHY_IssueCallback(enabledRailEvents & uVar4,DAT_200044f4 & uVar5,enabledPhyEvents & uVar6)
  ;
  if ((uVar7 & 0x40000) != 0) {
    BUFC_EndRxLenThrEvent();
    GENERIC_PHY_CheckPendedRxWindowEnd();
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      PA_RunPeakDetectorHigh();
    }
    if ((uVar8 & 0x4000000) != 0) {
      PA_RunPeakDetectorLow();
    }
    if ((uVar8 & 0x8000000) != 0) {
      PA_RunBatHigh();
      return;
    }
  }
  return;
}



int CORTEX_UTILS_BitsetLowestSetBit(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar5 = 0;
  while( true ) {
    if (iVar5 == param_2) {
      return -1;
    }
    uVar6 = *(undefined4 *)(param_1 + iVar5 * 4);
    bVar2 = (byte)uVar6;
    bVar3 = (byte)((uint)uVar6 >> 8);
    bVar4 = (byte)((uint)uVar6 >> 0x10);
    bVar1 = (byte)((uint)uVar6 >> 0x18);
    iVar7 = count_leading_zeroes
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
    if (iVar7 != 0x20) break;
    iVar5 = iVar5 + 1;
  }
  return iVar7 + iVar5 * 0x20;
}



void AUXPLL_AuxSettingsPllLoopback(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::RAC.AUXCTRL);
  write_volatile_4(Peripherals::RAC.AUXCTRL,uVar1 | 0x3000000);
  write_volatile_4(Peripherals::RAC_SET.SGLNAMIXCTRL,0x4000000);
  return;
}



void AUXPLL_AuxSettingsPaLoopback(void)

{
  write_volatile_4(Peripherals::RAC_CLR.SYNTHCTRL,4);
  write_volatile_4(Peripherals::RAC_SET.AUXENCTRL,4);
  return;
}



void AUXPLL_Stop(void)

{
  write_volatile_4(Peripherals::RAC_CLR.AUXCTRL,0x8007ca);
  write_volatile_4(Peripherals::RAC_CLR.AUXENCTRL,1);
  write_volatile_4(Peripherals::RAC_CLR.SGLNAMIXCTRL,0x4000000);
  write_volatile_4(Peripherals::RAC_CLR.AUXENCTRL,4);
  return;
}



undefined AUXPLL_ConvertAuxLoDivToRegVal(int param_1)

{
  undefined uVar1;
  
  if (param_1 - 2U < 0x17) {
    uVar1 = (&UNK_00018302)[param_1];
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
  
  write_volatile_4(Peripherals::RAC_CLR.AUXENCTRL,1);
  uVar1 = read_volatile_4(Peripherals::RAC.AUXCTRL);
  write_volatile_4(Peripherals::RAC.AUXCTRL,uVar1 & 0xff01ffcf | 0xe80030);
  uVar1 = read_volatile_4(Peripherals::SYNTH.DIVCTRL);
  iVar2 = AUXPLL_ConvertAuxLoDivToRegVal(param_2);
  write_volatile_4(Peripherals::SYNTH.DIVCTRL,uVar1 & 0xffc0ffff | iVar2 << 0x10);
  uVar1 = read_volatile_4(Peripherals::RAC.AUXCTRL);
  write_volatile_4(Peripherals::RAC.AUXCTRL,uVar1 & 0xfffe00ff | param_4 << 0xb | param_3 << 8);
  uVar1 = read_volatile_4(Peripherals::SYNTH.AUXFREQ);
  write_volatile_4(Peripherals::SYNTH.AUXFREQ,uVar1 & 0xffffff80 | param_1);
  write_volatile_4(Peripherals::RAC_SET.AUXCTRL,0x4a);
  write_volatile_4(Peripherals::RAC_SET.AUXENCTRL,1);
  write_volatile_4(Peripherals::RAC_SET.AUXCTRL,0x80);
  write_volatile_4(Peripherals::RAC_SET.AUXCTRL,0x800000);
  write_volatile_4(Peripherals::SYNTH_SET.AUXVCDACCTRL,0x10);
  write_volatile_4(Peripherals::RAC_CLR.AUXCTRL,8);
  write_volatile_4(Peripherals::RAC_SET.AUXCTRL,0x800004);
  PROTIMER_DelayUs(1000);
  do {
    write_volatile_4(Peripherals::SYNTH.CMD,0x80);
    write_volatile_4(Peripherals::SYNTH.CMD,0x100);
    do {
      uVar1 = read_volatile_4(Peripherals::SYNTH.STATUS);
    } while ((int)(uVar1 << 0x14) < 0);
    uVar1 = read_volatile_4(Peripherals::SYNTH.STATUS);
  } while ((int)(uVar1 << 0x11) < 0);
  write_volatile_4(Peripherals::RAC_SET.AUXCTRL,8);
  write_volatile_4(Peripherals::SYNTH_CLR.AUXVCDACCTRL,0x10);
  write_volatile_4(Peripherals::SYNTH.CMD,0x40);
  uVar1 = read_volatile_4(Peripherals::RAC.AUXCTRL);
  write_volatile_4(Peripherals::RAC.AUXCTRL,uVar1 & 0xff7ffffb | 0x800000);
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
LAB_0000f6e8:
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
      if (0xffbfffff < uVar9 * 0x200000) goto LAB_0000f6e8;
    }
LAB_0000f5b4:
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
  if ((uVar11 & 0x100000) != 0) goto LAB_0000f5b4;
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
      goto LAB_0000f62c;
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
LAB_0000f62c:
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
LAB_0000f6e8:
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
      if (0xffbfffff < uVar7 * 0x200000) goto LAB_0000f6e8;
    }
LAB_0000f5b4:
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
  if ((uVar10 & 0x100000) != 0) goto LAB_0000f5b4;
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
      goto LAB_0000f62c;
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
LAB_0000f62c:
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
      goto LAB_0000f62c;
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
LAB_0000f62c:
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
      goto LAB_0000f62c;
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
LAB_0000f62c:
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
      goto LAB_0000f62c;
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
LAB_0000f62c:
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
LAB_0000f5b4:
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
  if ((param_2 & 0x100000) != 0) goto LAB_0000f5b4;
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
      goto LAB_0000f62c;
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
LAB_0000f62c:
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
LAB_0000f5b4:
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
  if ((uVar3 & 0x100000) != 0) goto LAB_0000f5b4;
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
      goto LAB_0000f62c;
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
LAB_0000f62c:
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
    uVar12 = FUN_0000f9f0();
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



ulonglong FUN_0000f9f0(uint param_1,uint param_2,uint param_3,uint param_4)

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
    uVar16 = FUN_0000fbd6();
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
        if ((uVar6 & 0x100000) != 0) goto LAB_0000fb86;
        uVar6 = uVar6 | uVar10;
        uVar10 = 0;
        uVar2 = 0x80000000;
      }
    }
    if ((uVar6 & 0x100000) == 0) {
      uVar6 = uVar6 | uVar10;
      uVar10 = 0;
    }
LAB_0000fb86:
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



ulonglong FUN_0000fbd6(uint param_1,uint param_2,uint param_3,uint param_4)

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
LAB_0000fa48:
        return (ulonglong)((param_2 ^ param_4) & 0x80000000 | 0x7ff00000) << 0x20;
      }
    }
    else {
      if (uVar2 == in_r12) {
        param_1 = param_3;
        uVar3 = param_4;
        if ((param_3 | param_4 << 0xc) == 0) {
LAB_0000fa0c:
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
        if ((param_1 | param_2 << 1) != 0) goto LAB_0000fa48;
        if ((param_3 | param_4 << 1) != 0) goto LAB_0000fa0c;
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
                    // WARNING: Could not recover jumptable at 0x0000fdee. Too many branches
                    // WARNING: Treating indirect jump as call
        UNRECOVERED_JUMPTABLE = (code *)software_udf(0xff,0xfdee);
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
  if (DAT_20000c70 != FUN_00000000) {
    (*DAT_20000c70)();
  }
                    // WARNING: Subroutine does not return
  _exit(__status);
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
LAB_000102ba:
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
        goto LAB_000102ba;
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
      goto LAB_00010542;
    }
  }
  else {
    if ((param_4 != 0x10) || (uVar7 != 0x30)) goto LAB_00010542;
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
LAB_00010542:
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
    if (iVar2 == 0) goto LAB_000105d6;
  }
  param_2 = pbVar8 + -1;
LAB_000105d6:
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
      goto LAB_00010666;
    }
  }
  else {
    if ((param_4 != 0x10) || (uVar6 != 0x30)) goto LAB_00010666;
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
LAB_00010666:
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
    if (iVar2 == 0) goto LAB_000106f8;
  }
  param_2 = pbVar7 + -1;
LAB_000106f8:
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
      goto LAB_0001083c;
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
LAB_0001083c:
  *(ushort *)(param_2 + 3) = uVar3 | 0x40;
  return 0xffffffff;
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
          goto LAB_000109da;
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
LAB_000109da:
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
    iVar1 = _fwalk_reent(&impure_data,0x109f5);
    return iVar1;
  }
  iVar1 = _fflush_r(_impure_ptr,__stream);
  return iVar1;
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
  param_1[9] = 0x11811;
  param_1[10] = 0x11833;
  param_1[0xb] = 0x1186b;
  param_1[8] = param_1;
  param_1[0xc] = 0x1188f;
  return;
}



void _cleanup_r(undefined4 param_1)

{
  _fwalk_reent(param_1,0x109f5);
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
    param_1[10] = 0x10ab5;
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
  
  if (DAT_20000c60 == 0) {
    __sinit(&impure_data);
  }
  ppiVar3 = (int **)&DAT_20000c90;
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
      goto LAB_00010cf4;
    }
  }
  else {
    *param_4 = (uint)((local_64 & 0xf000) == 0x2000);
  }
  uVar2 = 0x400;
LAB_00010cf4:
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
      *(undefined4 *)(param_1 + 0x28) = 0x10ab5;
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
        goto LAB_00010eb0;
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
LAB_00010eb0:
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
LAB_00010f46:
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
          goto LAB_00010f46;
        }
      }
      param_2[4] = pvVar1;
      param_2[5] = pvVar2;
      *param_2 = (void *)((int)pvVar1 + __n);
      param_2[2] = (void *)((int)pvVar2 - __n);
      pvVar2 = param_4;
    }
    if (pvVar2 <= param_4) goto LAB_00010f84;
  }
  pvVar2 = param_4;
LAB_00010f84:
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
  undefined4 *puVar5;
  int *piVar6;
  byte *pbVar7;
  byte *pbVar8;
  undefined4 *unaff_r9;
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
  pbVar7 = param_3;
LAB_00010ffe:
  pbVar8 = pbVar7;
  if (*pbVar8 != 0) goto code_r0x00011006;
  goto LAB_0001100a;
code_r0x00011006:
  pbVar7 = pbVar8 + 1;
  if (*pbVar8 != 0x25) goto LAB_00010ffe;
LAB_0001100a:
  iVar2 = (int)pbVar8 - (int)param_3;
  if (iVar2 != 0) {
    iVar3 = __ssputs_r(param_1,param_2,param_3,iVar2);
    if (iVar3 == -1) {
LAB_0001116a:
      if ((int)((uint)*(ushort *)(param_2 + 3) << 0x19) < 0) {
        return -1;
      }
      return local_74;
    }
    local_74 = local_74 + iVar2;
  }
  if (*pbVar8 == 0) goto LAB_0001116a;
  local_84 = -1;
  uStack128 = 0;
  local_88 = 0;
  local_7c = 0;
  local_45 = 0;
  local_30 = 0;
  pbVar7 = pbVar8 + 1;
  while( true ) {
    param_3 = pbVar7 + 1;
    pvVar4 = memchr(&DAT_00018386,(uint)*pbVar7,5);
    if (pvVar4 == (void *)0x0) break;
    local_88 = 1 << ((int)pvVar4 - 0x18386U & 0xff) | local_88;
    pbVar7 = param_3;
  }
  if ((int)(local_88 << 0x1b) < 0) {
    local_45 = 0x20;
  }
  if ((int)(local_88 << 0x1c) < 0) {
    local_45 = 0x2b;
  }
  if (*pbVar7 == 0x2a) {
    piVar6 = local_8c + 1;
    iVar2 = *local_8c;
    local_8c = piVar6;
    if (-1 < iVar2) goto LAB_000110a8;
    local_7c = -iVar2;
    local_88 = local_88 | 2;
  }
  else {
    bVar1 = false;
    iVar2 = local_7c;
    param_3 = pbVar7;
    while( true ) {
      if (9 < *param_3 - 0x30) break;
      iVar2 = iVar2 * 10 + (*param_3 - 0x30);
      bVar1 = true;
      param_3 = param_3 + 1;
    }
    if (bVar1) {
LAB_000110a8:
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
  pvVar4 = memchr(&DAT_0001838c,(uint)*param_3,3);
  if (pvVar4 != (void *)0x0) {
    local_88 = local_88 | 0x40 << ((int)pvVar4 - 0x1838cU & 0xff);
    param_3 = param_3 + 1;
  }
  local_70 = *param_3;
  param_3 = param_3 + 1;
  pvVar4 = memchr("efgEFG",(uint)local_70,6);
  if (pvVar4 == (void *)0x0) {
    puVar5 = (undefined4 *)_printf_i(param_1,&local_88,param_2,0x10f01,&local_8c);
  }
  else {
    puVar5 = param_1;
    if (true) {
      local_8c = (int *)(((int)local_8c + 7U & 0xfffffff8) + 8);
      puVar5 = unaff_r9;
      goto LAB_00011118;
    }
  }
  if (puVar5 == (undefined4 *)0xffffffff) goto LAB_0001116a;
LAB_00011118:
  local_74 = local_74 + (int)puVar5;
  pbVar7 = param_3;
  unaff_r9 = puVar5;
  goto LAB_00010ffe;
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
LAB_00011236:
  pbVar6 = pbVar5;
  if (*pbVar6 != 0) goto code_r0x0001123e;
  goto LAB_00011242;
code_r0x0001123e:
  pbVar5 = pbVar6 + 1;
  if (*pbVar6 != 0x25) goto LAB_00011236;
LAB_00011242:
  iVar7 = (int)pbVar6 - (int)param_3;
  if (iVar7 != 0) {
    iVar2 = __sfputs_r(param_1,param_2,param_3,iVar7);
    if (iVar2 == -1) {
LAB_000113de:
      if ((int)((uint)*(ushort *)(param_2 + 3) << 0x19) < 0) {
        return -1;
      }
      return local_74;
    }
    local_74 = local_74 + iVar7;
  }
  if (*pbVar6 == 0) goto LAB_000113de;
  local_84 = -1;
  uStack128 = 0;
  local_88 = 0;
  local_7c = 0;
  local_45 = 0;
  local_30 = 0;
  pbVar5 = pbVar6 + 1;
  while( true ) {
    param_3 = pbVar5 + 1;
    pvVar3 = memchr(&DAT_00018386,(uint)*pbVar5,5);
    if (pvVar3 == (void *)0x0) break;
    local_88 = 1 << ((int)pvVar3 - 0x18386U & 0xff) | local_88;
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
    if (-1 < iVar7) goto LAB_0001130c;
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
LAB_0001130c:
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
  pvVar3 = memchr(&DAT_0001838c,(uint)*param_3,3);
  if (pvVar3 != (void *)0x0) {
    local_88 = local_88 | 0x40 << ((int)pvVar3 - 0x1838cU & 0xff);
    param_3 = param_3 + 1;
  }
  local_70 = *param_3;
  param_3 = param_3 + 1;
  pvVar3 = memchr("efgEFG",(uint)local_70,6);
  if (pvVar3 == (void *)0x0) {
    iVar7 = _printf_i(param_1,&local_88,param_2,0x111cf,&local_8c);
  }
  else {
    iVar7 = param_1;
    if (true) {
      local_8c = (int *)(((int)local_8c + 7U & 0xfffffff8) + 8);
      iVar7 = unaff_r9;
      goto LAB_0001138a;
    }
  }
  if (iVar7 == -1) goto LAB_000113de;
LAB_0001138a:
  local_74 = local_74 + iVar7;
  pbVar5 = param_3;
  unaff_r9 = iVar7;
  goto LAB_00011236;
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
      if (iVar1 == -1) goto LAB_000114ce;
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
LAB_000114ce:
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
      if (iVar1 == -1) goto LAB_000114ce;
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
LAB_000116a4:
    param_2[4] = 0;
    goto LAB_00011620;
  }
  if (bVar1 < 0x6f) {
    if (bVar1 != 99) {
      if (bVar1 < 100) {
        if (bVar1 == 0) goto LAB_000116a4;
        if (bVar1 != 0x58) goto LAB_00011538;
        pcVar3 = "0123456789ABCDEF";
        *(undefined *)((int)param_2 + 0x45) = 0x58;
LAB_00011644:
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
LAB_000115da:
        *(undefined *)((int)param_2 + 0x43) = 0;
      }
      else {
        if ((bVar1 != 100) && (bVar1 != 0x69)) goto LAB_00011538;
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
        if (uVar8 != 0) goto LAB_00011674;
LAB_00011718:
        *(char *)((int)param_2 + 0x42) = *pcVar3;
        pcVar12 = (char *)((int)param_2 + 0x42);
      }
      else {
        *param_2 = *param_2 & 0xfffffffb;
        if (uVar8 == 0) {
          if (uVar11 != 0) goto LAB_00011718;
        }
        else {
LAB_00011674:
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
      goto LAB_00011620;
    }
    uVar8 = **param_5;
    *param_5 = *param_5 + 1;
    *(char *)((int)param_2 + 0x42) = (char)uVar8;
LAB_000115a8:
    __s = (char *)((int)param_2 + 0x42);
    uVar8 = 1;
  }
  else {
    if (bVar1 != 0x73) {
      if (bVar1 < 0x74) {
        if (bVar1 == 0x6f) {
LAB_000115ba:
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
          goto LAB_000115da;
        }
        if (bVar1 == 0x70) {
          *param_2 = *param_2 | 0x20;
LAB_0001158e:
          *(undefined *)((int)param_2 + 0x45) = 0x78;
          pcVar3 = "0123456789abcdef";
          goto LAB_00011644;
        }
      }
      else {
        if (bVar1 == 0x75) goto LAB_000115ba;
        if (bVar1 == 0x78) goto LAB_0001158e;
      }
LAB_00011538:
      *(byte *)((int)param_2 + 0x42) = bVar1;
      goto LAB_000115a8;
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
LAB_00011620:
  iVar2 = _printf_common(param_1,param_2,local_24,param_3,param_4);
  if ((iVar2 == -1) || (iVar2 = (*param_4)(param_1,param_3,__s,param_2[4]), iVar2 == -1)) {
LAB_00011634:
    uVar8 = 0xffffffff;
  }
  else {
    if ((int)(*param_2 << 0x1e) < 0) {
      for (iVar2 = 0; iVar2 < (int)(param_2[3] - local_24[0]); iVar2 = iVar2 + 1) {
        iVar5 = (*param_4)(param_1,param_3,(int)param_2 + 0x19,1);
        if (iVar5 == -1) goto LAB_00011634;
      }
    }
    uVar8 = param_2[3];
    if ((int)param_2[3] < (int)local_24[0]) {
      uVar8 = local_24[0];
    }
  }
  return uVar8;
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
joined_r0x000119c0:
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
        goto joined_r0x000119c0;
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
      _fwalk(&impure_data,0x11a75);
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



int _init(EVP_PKEY_CTX *ctx)

{
  return (int)ctx;
}



void _fini(void)

{
  return;
}


