#ifndef _SEQVAR_H_
#define _SEQVAR_H_



//_DAT_21000efc
//==7 id framelen config
//0x10 - address filtering
//0x20 - radio enable (???) ==0 before RX or TX, ==1 on idle, 

#define Transitions SEQ->REG000 // - TxTransitions, RxTransitions


//address filtering
//SEQ->REG008 len = 0x4c
//SEQ->REG00C
//SEQ->REG028

//SEQ->REG04C
//SEQ->REG050

//SEQ->REG054 - frame length config
//SEQ->REG058 - frame length config
//SEQ->REG05C - frame length config
//SEQ->REG060 - frame length config
//SEQ->REG064 - frame length config
//SEQ->REG068 - frame length config

//SEQ->REG06C
//SEQ->REG070 - 

//SEQ->REG080 - Tempcal

//SEQ->REG09C - RxWarmTime
//SEQ->REG0A0 - RxSearchTime
//SEQ->REG0A4 - RxToTxTime
//SEQ->REG0A8 - RxFrameToTx
//SEQ->REG0AC - TxWarmTime
//SEQ->REG0B0 - TxToRxTime
//SEQ->REG0B4 - TxToRxSearchTime
//SEQ->REG0B8 - TxToTxTime
//SEQ->REG0BC = -(RADIO_UsToStimerTickCalc(0x3c))
//SEQ->REG0C0 - PA related (TX power, slices)
//SEQ->REG0C4 - rxpactune
//SEQ->REG0C8 - txpactune


#endif
