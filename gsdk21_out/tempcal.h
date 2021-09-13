typedef unsigned char   undefined;

typedef unsigned char    byte;
typedef unsigned int    dword;
typedef unsigned int    uint;
typedef unsigned char    undefined1;
typedef unsigned int    undefined4;
typedef unsigned short    word;
#define unkbyte9   unsigned long long
#define unkbyte10   unsigned long long
#define unkbyte11   unsigned long long
#define unkbyte12   unsigned long long
#define unkbyte13   unsigned long long
#define unkbyte14   unsigned long long
#define unkbyte15   unsigned long long
#define unkbyte16   unsigned long long

#define unkuint9   unsigned long long
#define unkuint10   unsigned long long
#define unkuint11   unsigned long long
#define unkuint12   unsigned long long
#define unkuint13   unsigned long long
#define unkuint14   unsigned long long
#define unkuint15   unsigned long long
#define unkuint16   unsigned long long

#define unkint9   long long
#define unkint10   long long
#define unkint11   long long
#define unkint12   long long
#define unkint13   long long
#define unkint14   long long
#define unkint15   long long
#define unkint16   long long

#define unkfloat1   float
#define unkfloat2   float
#define unkfloat3   float
#define unkfloat5   double
#define unkfloat6   double
#define unkfloat7   double
#define unkfloat9   long double
#define unkfloat11   long double
#define unkfloat12   long double
#define unkfloat13   long double
#define unkfloat14   long double
#define unkfloat15   long double
#define unkfloat16   long double

#define BADSPACEBASE   void
#define code   void

typedef struct WDOG0 WDOG0, *PWDOG0;

struct WDOG0 {
    uint CTRL; // Control Register
    uint CMD; // Command Register
    uint SYNCBUSY; // Synchronization Busy Register
    uint PCH0_PRSCTRL; // PRS Control Register
    uint PCH1_PRSCTRL; // PRS Control Register
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    undefined field_0x18;
    undefined field_0x19;
    undefined field_0x1a;
    undefined field_0x1b;
    uint IF; // Watchdog Interrupt Flags
    uint IFS; // Interrupt Flag Set Register
    uint IFC; // Interrupt Flag Clear Register
    uint IEN; // Interrupt Enable Register
};

typedef struct LETIMER0 LETIMER0, *PLETIMER0;

struct LETIMER0 {
    uint CTRL; // Control Register
    uint CMD; // Command Register
    uint STATUS; // Status Register
    uint CNT; // Counter Value Register
    uint COMP0; // Compare Value Register 0
    uint COMP1; // Compare Value Register 1
    uint REP0; // Repeat Counter Register 0
    uint REP1; // Repeat Counter Register 1
    uint IF; // Interrupt Flag Register
    uint IFS; // Interrupt Flag Set Register
    uint IFC; // Interrupt Flag Clear Register
    uint IEN; // Interrupt Enable Register
    undefined field_0x30;
    undefined field_0x31;
    undefined field_0x32;
    undefined field_0x33;
    uint SYNCBUSY; // Synchronization Busy Register
    undefined field_0x38;
    undefined field_0x39;
    undefined field_0x3a;
    undefined field_0x3b;
    undefined field_0x3c;
    undefined field_0x3d;
    undefined field_0x3e;
    undefined field_0x3f;
    uint ROUTEPEN; // I/O Routing Pin Enable Register
    uint ROUTELOC0; // I/O Routing Location Register
    undefined field_0x48;
    undefined field_0x49;
    undefined field_0x4a;
    undefined field_0x4b;
    undefined field_0x4c;
    undefined field_0x4d;
    undefined field_0x4e;
    undefined field_0x4f;
    uint PRSSEL; // PRS Input Select Register
};

typedef struct RTCC RTCC, *PRTCC;

struct RTCC {
    uint CTRL; // Control Register
    uint PRECNT; // Pre-Counter Value Register
    uint CNT; // Counter Value Register
    uint COMBCNT; // Combined Pre-Counter and Counter Value Register
    uint TIME; // Time of Day Register
    uint DATE; // Date Register
    uint IF; // RTCC Interrupt Flags
    uint IFS; // Interrupt Flag Set Register
    uint IFC; // Interrupt Flag Clear Register
    uint IEN; // Interrupt Enable Register
    uint STATUS; // Status Register
    uint CMD; // Command Register
    uint SYNCBUSY; // Synchronization Busy Register
    uint POWERDOWN; // Retention RAM Power-down Register
    uint LOCK; // Configuration Lock Register
    uint EM4WUEN; // Wake Up Enable
    uint CC0_CTRL; // CC Channel Control Register
    uint CC0_CCV; // Capture/Compare Value Register
    uint CC0_TIME; // Capture/Compare Time Register
    uint CC0_DATE; // Capture/Compare Date Register
    uint CC1_CTRL; // CC Channel Control Register
    uint CC1_CCV; // Capture/Compare Value Register
    uint CC1_TIME; // Capture/Compare Time Register
    uint CC1_DATE; // Capture/Compare Date Register
    uint CC2_CTRL; // CC Channel Control Register
    uint CC2_CCV; // Capture/Compare Value Register
    uint CC2_TIME; // Capture/Compare Time Register
    uint CC2_DATE; // Capture/Compare Date Register
    undefined field_0x70;
    undefined field_0x71;
    undefined field_0x72;
    undefined field_0x73;
    undefined field_0x74;
    undefined field_0x75;
    undefined field_0x76;
    undefined field_0x77;
    undefined field_0x78;
    undefined field_0x79;
    undefined field_0x7a;
    undefined field_0x7b;
    undefined field_0x7c;
    undefined field_0x7d;
    undefined field_0x7e;
    undefined field_0x7f;
    undefined field_0x80;
    undefined field_0x81;
    undefined field_0x82;
    undefined field_0x83;
    undefined field_0x84;
    undefined field_0x85;
    undefined field_0x86;
    undefined field_0x87;
    undefined field_0x88;
    undefined field_0x89;
    undefined field_0x8a;
    undefined field_0x8b;
    undefined field_0x8c;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
    undefined field_0x90;
    undefined field_0x91;
    undefined field_0x92;
    undefined field_0x93;
    undefined field_0x94;
    undefined field_0x95;
    undefined field_0x96;
    undefined field_0x97;
    undefined field_0x98;
    undefined field_0x99;
    undefined field_0x9a;
    undefined field_0x9b;
    undefined field_0x9c;
    undefined field_0x9d;
    undefined field_0x9e;
    undefined field_0x9f;
    undefined field_0xa0;
    undefined field_0xa1;
    undefined field_0xa2;
    undefined field_0xa3;
    undefined field_0xa4;
    undefined field_0xa5;
    undefined field_0xa6;
    undefined field_0xa7;
    undefined field_0xa8;
    undefined field_0xa9;
    undefined field_0xaa;
    undefined field_0xab;
    undefined field_0xac;
    undefined field_0xad;
    undefined field_0xae;
    undefined field_0xaf;
    undefined field_0xb0;
    undefined field_0xb1;
    undefined field_0xb2;
    undefined field_0xb3;
    undefined field_0xb4;
    undefined field_0xb5;
    undefined field_0xb6;
    undefined field_0xb7;
    undefined field_0xb8;
    undefined field_0xb9;
    undefined field_0xba;
    undefined field_0xbb;
    undefined field_0xbc;
    undefined field_0xbd;
    undefined field_0xbe;
    undefined field_0xbf;
    undefined field_0xc0;
    undefined field_0xc1;
    undefined field_0xc2;
    undefined field_0xc3;
    undefined field_0xc4;
    undefined field_0xc5;
    undefined field_0xc6;
    undefined field_0xc7;
    undefined field_0xc8;
    undefined field_0xc9;
    undefined field_0xca;
    undefined field_0xcb;
    undefined field_0xcc;
    undefined field_0xcd;
    undefined field_0xce;
    undefined field_0xcf;
    undefined field_0xd0;
    undefined field_0xd1;
    undefined field_0xd2;
    undefined field_0xd3;
    undefined field_0xd4;
    undefined field_0xd5;
    undefined field_0xd6;
    undefined field_0xd7;
    undefined field_0xd8;
    undefined field_0xd9;
    undefined field_0xda;
    undefined field_0xdb;
    undefined field_0xdc;
    undefined field_0xdd;
    undefined field_0xde;
    undefined field_0xdf;
    undefined field_0xe0;
    undefined field_0xe1;
    undefined field_0xe2;
    undefined field_0xe3;
    undefined field_0xe4;
    undefined field_0xe5;
    undefined field_0xe6;
    undefined field_0xe7;
    undefined field_0xe8;
    undefined field_0xe9;
    undefined field_0xea;
    undefined field_0xeb;
    undefined field_0xec;
    undefined field_0xed;
    undefined field_0xee;
    undefined field_0xef;
    undefined field_0xf0;
    undefined field_0xf1;
    undefined field_0xf2;
    undefined field_0xf3;
    undefined field_0xf4;
    undefined field_0xf5;
    undefined field_0xf6;
    undefined field_0xf7;
    undefined field_0xf8;
    undefined field_0xf9;
    undefined field_0xfa;
    undefined field_0xfb;
    undefined field_0xfc;
    undefined field_0xfd;
    undefined field_0xfe;
    undefined field_0xff;
    undefined field_0x100;
    undefined field_0x101;
    undefined field_0x102;
    undefined field_0x103;
    uint RET0_REG; // Retention Register
    uint RET1_REG; // Retention Register
    uint RET2_REG; // Retention Register
    uint RET3_REG; // Retention Register
    uint RET4_REG; // Retention Register
    uint RET5_REG; // Retention Register
    uint RET6_REG; // Retention Register
    uint RET7_REG; // Retention Register
    uint RET8_REG; // Retention Register
    uint RET9_REG; // Retention Register
    uint RET10_REG; // Retention Register
    uint RET11_REG; // Retention Register
    uint RET12_REG; // Retention Register
    uint RET13_REG; // Retention Register
    uint RET14_REG; // Retention Register
    uint RET15_REG; // Retention Register
    uint RET16_REG; // Retention Register
    uint RET17_REG; // Retention Register
    uint RET18_REG; // Retention Register
    uint RET19_REG; // Retention Register
    uint RET20_REG; // Retention Register
    uint RET21_REG; // Retention Register
    uint RET22_REG; // Retention Register
    uint RET23_REG; // Retention Register
    uint RET24_REG; // Retention Register
    uint RET25_REG; // Retention Register
    uint RET26_REG; // Retention Register
    uint RET27_REG; // Retention Register
    uint RET28_REG; // Retention Register
    uint RET29_REG; // Retention Register
    uint RET30_REG; // Retention Register
    uint RET31_REG; // Retention Register
};

typedef struct SYNTH_SET SYNTH_SET, *PSYNTH_SET;

struct SYNTH_SET {
    uint STATUS;
    uint CMD;
    uint CTRL;
    uint CALCTRL;
    undefined field_0x10;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    undefined field_0x18;
    undefined field_0x19;
    undefined field_0x1a;
    undefined field_0x1b;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    undefined field_0x20;
    undefined field_0x21;
    undefined field_0x22;
    undefined field_0x23;
    uint VCDACCTRL;
    undefined field_0x28;
    undefined field_0x29;
    undefined field_0x2a;
    undefined field_0x2b;
    uint FREQ;
    uint IFFREQ;
    uint DIVCTRL;
    uint CHCTRL;
    uint CHSP;
    uint CALOFFSET;
    uint VCOTUNING;
    undefined field_0x48;
    undefined field_0x49;
    undefined field_0x4a;
    undefined field_0x4b;
    uint VCORANGE;
    uint VCOGAIN;
    uint AUXVCOTUNING;
    uint AUXFREQ;
    uint AUXVCDACCTRL;
    uint CHPDACCTRL;
    uint CAPCALCYCLECNT;
    undefined field_0x68;
    undefined field_0x69;
    undefined field_0x6a;
    undefined field_0x6b;
    undefined field_0x6c;
    undefined field_0x6d;
    undefined field_0x6e;
    undefined field_0x6f;
    uint IF;
    uint IFS;
    uint IFC;
    uint IEN;
};

typedef struct PRS PRS, *PPRS;

struct PRS {
    uint SWPULSE; // Software Pulse Register
    uint SWLEVEL; // Software Level Register
    uint ROUTEPEN; // I/O Routing Pin Enable Register
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    uint ROUTELOC0; // I/O Routing Location Register
    uint ROUTELOC1; // I/O Routing Location Register
    uint ROUTELOC2; // I/O Routing Location Register
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    uint CTRL; // Control Register
    uint DMAREQ0; // DMA Request 0 Register
    uint DMAREQ1; // DMA Request 1 Register
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    uint PEEK; // PRS Channel Values
    undefined field_0x34;
    undefined field_0x35;
    undefined field_0x36;
    undefined field_0x37;
    undefined field_0x38;
    undefined field_0x39;
    undefined field_0x3a;
    undefined field_0x3b;
    undefined field_0x3c;
    undefined field_0x3d;
    undefined field_0x3e;
    undefined field_0x3f;
    uint CH0_CTRL; // Channel Control Register
    uint CH1_CTRL; // Channel Control Register
    uint CH2_CTRL; // Channel Control Register
    uint CH3_CTRL; // Channel Control Register
    uint CH4_CTRL; // Channel Control Register
    uint CH5_CTRL; // Channel Control Register
    uint CH6_CTRL; // Channel Control Register
    uint CH7_CTRL; // Channel Control Register
    uint CH8_CTRL; // Channel Control Register
    uint CH9_CTRL; // Channel Control Register
    uint CH10_CTRL; // Channel Control Register
    uint CH11_CTRL; // Channel Control Register
};

typedef struct PROTIMER PROTIMER, *PPROTIMER;

struct PROTIMER {
    uint CTRL;
    uint CMD;
    uint PRSCTRL;
    uint STATUS;
    uint PRECNT;
    uint BASECNT;
    uint WRAPCNT;
    uint BASEPRE;
    uint LWRAPCNT;
    uint PRECNTTOPADJ;
    uint PRECNTTOP;
    uint BASECNTTOP;
    uint WRAPCNTTOP;
    uint TOUT0CNT;
    uint TOUT0CNTTOP;
    uint TOUT0COMP;
    uint TOUT1CNT;
    uint TOUT1CNTTOP;
    uint TOUT1COMP;
    uint LBTCTRL;
    uint LBTPRSCTRL;
    uint LBTSTATE;
    uint RANDOM;
    uint IF;
    uint IFS;
    uint IFC;
    uint IEN;
    uint RXCTRL;
    uint TXCTRL;
    uint CC0_CTRL;
    uint CC0_PRE;
    uint CC0_BASE;
    uint CC0_WRAP;
    uint CC1_CTRL;
    uint CC1_PRE;
    uint CC1_BASE;
    uint CC1_WRAP;
    uint CC2_CTRL;
    uint CC2_PRE;
    uint CC2_BASE;
    uint CC2_WRAP;
    uint CC3_CTRL;
    uint CC3_PRE;
    uint CC3_BASE;
    uint CC3_WRAP;
    uint CC4_CTRL;
    uint CC4_PRE;
    uint CC4_BASE;
    uint CC4_WRAP;
};

typedef struct AGC_SET AGC_SET, *PAGC_SET;

struct AGC_SET {
    uint STATUS0;
    uint STATUS1;
    uint RSSI;
    uint FRAMERSSI;
    undefined field_0x10;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    uint CTRL0;
    uint CTRL1;
    uint CTRL2;
    uint RSSISTEPTHR;
    uint IFPEAKDET;
    uint MANGAIN;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    uint IF;
    uint IFS;
    uint IFC;
    uint IEN;
    uint CMD;
    undefined field_0x44;
    undefined field_0x45;
    undefined field_0x46;
    undefined field_0x47;
    uint GAINRANGE;
    uint GAININDEX;
    uint SLICECODE;
    uint ATTENCODE1;
    uint ATTENCODE2;
    uint ATTENCODE3;
    uint GAINERROR1;
    uint GAINERROR2;
    uint GAINERROR3;
    uint MANUALCTRL;
    uint GAINSTEPLIM;
    uint LOOPDEL;
    uint MININDEX;
};

typedef struct BUFC_SET BUFC_SET, *PBUFC_SET;

struct BUFC_SET {
    uint BUF0_CTRL;
    uint BUF0_ADDR;
    uint BUF0_WRITEOFFSET;
    uint BUF0_READOFFSET;
    uint BUF0_WRITESTART;
    uint BUF0_READDATA;
    uint BUF0_WRITEDATA;
    uint BUF0_XWRITE;
    uint BUF0_STATUS;
    uint BUF0_THRESHOLDCTRL;
    uint BUF0_CMD;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    uint BUF1_CTRL;
    uint BUF1_ADDR;
    uint BUF1_WRITEOFFSET;
    uint BUF1_READOFFSET;
    uint BUF1_WRITESTART;
    uint BUF1_READDATA;
    uint BUF1_WRITEDATA;
    uint BUF1_XWRITE;
    uint BUF1_STATUS;
    uint BUF1_THRESHOLDCTRL;
    uint BUF1_CMD;
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    uint BUF2_CTRL;
    uint BUF2_ADDR;
    uint BUF2_WRITEOFFSET;
    uint BUF2_READOFFSET;
    uint BUF2_WRITESTART;
    uint BUF2_READDATA;
    uint BUF2_WRITEDATA;
    uint BUF2_XWRITE;
    uint BUF2_STATUS;
    uint BUF2_THRESHOLDCTR;
    uint BUF2_CMD;
    undefined field_0x8c;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
    uint BUF3_CTRL;
    uint BUF3_ADDR;
    uint BUF3_WRITEOFFSET;
    uint BUF3_READOFFSET;
    uint BUF3_WRITESTART;
    uint BUF3_READDATA;
    uint BUF3_WRITEDATA;
    uint BUF3_XWRITE;
    uint BUF3_STATUS;
    uint BUF3_THRESHOLDCTRL;
    uint BUF3_CMD;
    undefined field_0xbc;
    undefined field_0xbd;
    undefined field_0xbe;
    undefined field_0xbf;
    undefined field_0xc0;
    undefined field_0xc1;
    undefined field_0xc2;
    undefined field_0xc3;
    undefined field_0xc4;
    undefined field_0xc5;
    undefined field_0xc6;
    undefined field_0xc7;
    undefined field_0xc8;
    undefined field_0xc9;
    undefined field_0xca;
    undefined field_0xcb;
    undefined field_0xcc;
    undefined field_0xcd;
    undefined field_0xce;
    undefined field_0xcf;
    undefined field_0xd0;
    undefined field_0xd1;
    undefined field_0xd2;
    undefined field_0xd3;
    undefined field_0xd4;
    undefined field_0xd5;
    undefined field_0xd6;
    undefined field_0xd7;
    undefined field_0xd8;
    undefined field_0xd9;
    undefined field_0xda;
    undefined field_0xdb;
    undefined field_0xdc;
    undefined field_0xdd;
    undefined field_0xde;
    undefined field_0xdf;
    uint IF;
    uint IFS;
    uint IFC;
    uint IEN;
};

typedef struct CRYOTIMER CRYOTIMER, *PCRYOTIMER;

struct CRYOTIMER {
    uint CTRL; // Control Register
    uint PERIODSEL; // Interrupt Duration
    uint CNT; // Counter Value
    uint EM4WUEN; // Wake Up Enable
    uint IF; // Interrupt Flag Register
    uint IFS; // Interrupt Flag Set Register
    uint IFC; // Interrupt Flag Clear Register
    uint IEN; // Interrupt Enable Register
};

typedef struct RFSENSE_SET RFSENSE_SET, *PRFSENSE_SET;

struct RFSENSE_SET {
    uint CTRL;
    uint PERIODSEL;
    uint CNT;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    uint EM4WUEN;
    uint CALIB;
    uint IF;
    uint IFS;
    uint IFC;
    uint IEN;
};

typedef struct GPCRC GPCRC, *PGPCRC;

struct GPCRC {
    uint CTRL; // Control Register
    uint CMD; // Command Register
    uint INIT; // CRC Init Value
    uint POLY; // CRC Polynomial Value
    uint INPUTDATA; // Input 32-bit Data Register
    uint INPUTDATAHWORD; // Input 16-bit Data Register
    uint INPUTDATABYTE; // Input 8-bit Data Register
    uint DATA; // CRC Data Register
    uint DATAREV; // CRC Data Reverse Register
    uint DATABYTEREV; // CRC Data Byte Reverse Register
};

typedef struct SYNTH SYNTH, *PSYNTH;

struct SYNTH {
    uint STATUS;
    uint CMD;
    uint CTRL;
    uint CALCTRL;
    undefined field_0x10;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    undefined field_0x18;
    undefined field_0x19;
    undefined field_0x1a;
    undefined field_0x1b;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    undefined field_0x20;
    undefined field_0x21;
    undefined field_0x22;
    undefined field_0x23;
    uint VCDACCTRL;
    undefined field_0x28;
    undefined field_0x29;
    undefined field_0x2a;
    undefined field_0x2b;
    uint FREQ;
    uint IFFREQ;
    uint DIVCTRL;
    uint CHCTRL;
    uint CHSP;
    uint CALOFFSET;
    uint VCOTUNING;
    undefined field_0x48;
    undefined field_0x49;
    undefined field_0x4a;
    undefined field_0x4b;
    uint VCORANGE;
    uint VCOGAIN;
    uint AUXVCOTUNING;
    uint AUXFREQ;
    uint AUXVCDACCTRL;
    uint CHPDACCTRL;
    uint CAPCALCYCLECNT;
    undefined field_0x68;
    undefined field_0x69;
    undefined field_0x6a;
    undefined field_0x6b;
    undefined field_0x6c;
    undefined field_0x6d;
    undefined field_0x6e;
    undefined field_0x6f;
    uint IF;
    uint IFS;
    uint IFC;
    uint IEN;
};

typedef struct CMU CMU, *PCMU;

struct CMU {
    uint CTRL; // CMU Control Register
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    undefined field_0x8;
    undefined field_0x9;
    undefined field_0xa;
    undefined field_0xb;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    uint HFRCOCTRL; // HFRCO Control Register
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    uint AUXHFRCOCTRL; // AUXHFRCO Control Register
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    uint LFRCOCTRL; // LFRCO Control Register
    uint HFXOCTRL; // HFXO Control Register
    uint HFXOCTRL1; // HFXO Control 1
    uint HFXOSTARTUPCTRL; // HFXO Startup Control
    uint HFXOSTEADYSTATECTRL; // HFXO Steady State Control
    uint HFXOTIMEOUTCTRL; // HFXO Timeout Control
    uint LFXOCTRL; // LFXO Control Register
    uint ULFRCOCTRL; // ULFRCO Control Register
    undefined field_0x40;
    undefined field_0x41;
    undefined field_0x42;
    undefined field_0x43;
    undefined field_0x44;
    undefined field_0x45;
    undefined field_0x46;
    undefined field_0x47;
    undefined field_0x48;
    undefined field_0x49;
    undefined field_0x4a;
    undefined field_0x4b;
    undefined field_0x4c;
    undefined field_0x4d;
    undefined field_0x4e;
    undefined field_0x4f;
    uint CALCTRL; // Calibration Control Register
    uint CALCNT; // Calibration Counter Register
    undefined field_0x58;
    undefined field_0x59;
    undefined field_0x5a;
    undefined field_0x5b;
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    uint OSCENCMD; // Oscillator Enable/Disable Command Register
    uint CMD; // Command Register
    undefined field_0x68;
    undefined field_0x69;
    undefined field_0x6a;
    undefined field_0x6b;
    undefined field_0x6c;
    undefined field_0x6d;
    undefined field_0x6e;
    undefined field_0x6f;
    uint DBGCLKSEL; // Debug Trace Clock Select
    uint HFCLKSEL; // High Frequency Clock Select Command Register
    undefined field_0x78;
    undefined field_0x79;
    undefined field_0x7a;
    undefined field_0x7b;
    undefined field_0x7c;
    undefined field_0x7d;
    undefined field_0x7e;
    undefined field_0x7f;
    uint LFACLKSEL; // Low Frequency A Clock Select Register
    uint LFBCLKSEL; // Low Frequency B Clock Select Register
    uint LFECLKSEL; // Low Frequency E Clock Select Register
    undefined field_0x8c;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
    uint STATUS; // Status Register
    uint HFCLKSTATUS; // HFCLK Status Register
    undefined field_0x98;
    undefined field_0x99;
    undefined field_0x9a;
    undefined field_0x9b;
    uint HFXOTRIMSTATUS; // HFXO Trim Status
    uint IF; // Interrupt Flag Register
    uint IFS; // Interrupt Flag Set Register
    uint IFC; // Interrupt Flag Clear Register
    uint IEN; // Interrupt Enable Register
    uint HFBUSCLKEN0; // High Frequency Bus Clock Enable Register 0
    undefined field_0xb4;
    undefined field_0xb5;
    undefined field_0xb6;
    undefined field_0xb7;
    undefined field_0xb8;
    undefined field_0xb9;
    undefined field_0xba;
    undefined field_0xbb;
    undefined field_0xbc;
    undefined field_0xbd;
    undefined field_0xbe;
    undefined field_0xbf;
    uint HFPERCLKEN0; // High Frequency Peripheral Clock Enable Register 0
    undefined field_0xc4;
    undefined field_0xc5;
    undefined field_0xc6;
    undefined field_0xc7;
    uint HFRADIOCLKEN0; // High Frequency Peripheral Clock Enable Register 0
    undefined field_0xcc;
    undefined field_0xcd;
    undefined field_0xce;
    undefined field_0xcf;
    undefined field_0xd0;
    undefined field_0xd1;
    undefined field_0xd2;
    undefined field_0xd3;
    undefined field_0xd4;
    undefined field_0xd5;
    undefined field_0xd6;
    undefined field_0xd7;
    undefined field_0xd8;
    undefined field_0xd9;
    undefined field_0xda;
    undefined field_0xdb;
    undefined field_0xdc;
    undefined field_0xdd;
    undefined field_0xde;
    undefined field_0xdf;
    uint LFACLKEN0; // Low Frequency a Clock Enable Register 0 (Async Reg)
    undefined field_0xe4;
    undefined field_0xe5;
    undefined field_0xe6;
    undefined field_0xe7;
    uint LFBCLKEN0; // Low Frequency B Clock Enable Register 0 (Async Reg)
    undefined field_0xec;
    undefined field_0xed;
    undefined field_0xee;
    undefined field_0xef;
    uint LFECLKEN0; // Low Frequency E Clock Enable Register 0 (Async Reg)
    undefined field_0xf4;
    undefined field_0xf5;
    undefined field_0xf6;
    undefined field_0xf7;
    undefined field_0xf8;
    undefined field_0xf9;
    undefined field_0xfa;
    undefined field_0xfb;
    undefined field_0xfc;
    undefined field_0xfd;
    undefined field_0xfe;
    undefined field_0xff;
    uint HFPRESC; // High Frequency Clock Prescaler Register
    undefined field_0x104;
    undefined field_0x105;
    undefined field_0x106;
    undefined field_0x107;
    uint HFCOREPRESC; // High Frequency Core Clock Prescaler Register
    uint HFPERPRESC; // High Frequency Peripheral Clock Prescaler Register
    uint HFRADIOPRESC; // Radio Clock Prescaler Register
    uint HFEXPPRESC; // High Frequency Export Clock Prescaler Register
    undefined field_0x118;
    undefined field_0x119;
    undefined field_0x11a;
    undefined field_0x11b;
    undefined field_0x11c;
    undefined field_0x11d;
    undefined field_0x11e;
    undefined field_0x11f;
    uint LFAPRESC0; // Low Frequency a Prescaler Register 0 (Async Reg)
    undefined field_0x124;
    undefined field_0x125;
    undefined field_0x126;
    undefined field_0x127;
    uint LFBPRESC0; // Low Frequency B Prescaler Register 0 (Async Reg)
    undefined field_0x12c;
    undefined field_0x12d;
    undefined field_0x12e;
    undefined field_0x12f;
    uint LFEPRESC0; // Low Frequency E Prescaler Register 0 (Async Reg)
    undefined field_0x134;
    undefined field_0x135;
    undefined field_0x136;
    undefined field_0x137;
    undefined field_0x138;
    undefined field_0x139;
    undefined field_0x13a;
    undefined field_0x13b;
    undefined field_0x13c;
    undefined field_0x13d;
    undefined field_0x13e;
    undefined field_0x13f;
    uint SYNCBUSY; // Synchronization Busy Register
    uint FREEZE; // Freeze Register
    undefined field_0x148;
    undefined field_0x149;
    undefined field_0x14a;
    undefined field_0x14b;
    undefined field_0x14c;
    undefined field_0x14d;
    undefined field_0x14e;
    undefined field_0x14f;
    uint PCNTCTRL; // PCNT Control Register
    uint LCDCTRL; // LCD Control Register
    uint LVDSCTRL; // LVDSCTRL Control Register
    uint ADCCTRL; // ADC Control Register
    undefined field_0x160;
    undefined field_0x161;
    undefined field_0x162;
    undefined field_0x163;
    undefined field_0x164;
    undefined field_0x165;
    undefined field_0x166;
    undefined field_0x167;
    undefined field_0x168;
    undefined field_0x169;
    undefined field_0x16a;
    undefined field_0x16b;
    undefined field_0x16c;
    undefined field_0x16d;
    undefined field_0x16e;
    undefined field_0x16f;
    uint ROUTEPEN; // I/O Routing Pin Enable Register
    uint ROUTELOC0; // I/O Routing Location Register
    undefined field_0x178;
    undefined field_0x179;
    undefined field_0x17a;
    undefined field_0x17b;
    undefined field_0x17c;
    undefined field_0x17d;
    undefined field_0x17e;
    undefined field_0x17f;
    uint LOCK; // Configuration Lock Register
    undefined field_0x184;
    undefined field_0x185;
    undefined field_0x186;
    undefined field_0x187;
    uint RFLOCK0; // RF LOCK Register
    undefined field_0x18c;
    undefined field_0x18d;
    undefined field_0x18e;
    undefined field_0x18f;
    uint HFBUSCLKENMASK0;
    undefined field_0x194;
    undefined field_0x195;
    undefined field_0x196;
    undefined field_0x197;
    uint HFPERCLKENMASK0;
    undefined field_0x19c;
    undefined field_0x19d;
    undefined field_0x19e;
    undefined field_0x19f;
    undefined field_0x1a0;
    undefined field_0x1a1;
    undefined field_0x1a2;
    undefined field_0x1a3;
    uint HFRADIOCLKENMASK0;
    undefined field_0x1a8;
    undefined field_0x1a9;
    undefined field_0x1aa;
    undefined field_0x1ab;
    undefined field_0x1ac;
    undefined field_0x1ad;
    undefined field_0x1ae;
    undefined field_0x1af;
    undefined field_0x1b0;
    undefined field_0x1b1;
    undefined field_0x1b2;
    undefined field_0x1b3;
    uint LFACLKENMASK0;
    undefined field_0x1b8;
    undefined field_0x1b9;
    undefined field_0x1ba;
    undefined field_0x1bb;
    uint LFBCLKENMASK0;
    undefined field_0x1c0;
    undefined field_0x1c1;
    undefined field_0x1c2;
    undefined field_0x1c3;
    uint LFECLKENMASK0;
    undefined field_0x1c8;
    undefined field_0x1c9;
    undefined field_0x1ca;
    undefined field_0x1cb;
    uint PCNTCLKENMASK;
    uint TEST;
    uint TESTHFRCOCTRL;
    uint TESTAUXHFRCOCTRL;
    uint TESTLFRCOCTRL;
    uint TESTHFXOCTRL;
    uint TESTLFXOCTRL;
};

typedef struct EMU EMU, *PEMU;

struct EMU {
    uint CTRL; // Control Register
    uint STATUS; // Status Register
    uint LOCK; // Configuration Lock Register
    uint RAM0CTRL; // Memory Control Register
    uint CMD; // Command Register
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    uint EM4CTRL; // EM4 Control Register
    uint TEMPLIMITS; // Temperature Limits for Interrupt Generation
    uint TEMP; // Value of Last Temperature Measurement
    uint IF; // Interrupt Flag Register
    uint IFS; // Interrupt Flag Set Register
    uint IFC; // Interrupt Flag Clear Register
    uint IEN; // Interrupt Enable Register
    uint PWRLOCK; // Regulator and Supply Lock Register
    uint PWRCFG; // Power Configuration Register
    uint PWRCTRL; // Power Control Register
    uint DCDCCTRL; // DCDC Control
    undefined field_0x44;
    undefined field_0x45;
    undefined field_0x46;
    undefined field_0x47;
    undefined field_0x48;
    undefined field_0x49;
    undefined field_0x4a;
    undefined field_0x4b;
    uint DCDCMISCCTRL; // DCDC Miscellaneous Control Register
    uint DCDCZDETCTRL; // DCDC Power Train NFET Zero Current Detector Control Register
    uint DCDCCLIMCTRL; // DCDC Power Train PFET Current Limiter Control Register
    uint DCDCLNCOMPCTRL; // DCDC Low Noise Compensator Control Register
    uint DCDCLNVCTRL; // DCDC Low Noise Voltage Register
    uint DCDCTIMING; // DCDC Controller Timing Value Register
    uint DCDCLPVCTRL; // DCDC Low Power Voltage Register
    undefined field_0x68;
    undefined field_0x69;
    undefined field_0x6a;
    undefined field_0x6b;
    uint DCDCLPCTRL; // DCDC Low Power Control Register
    uint DCDCLNFREQCTRL; // DCDC Low Noise Controller Frequency Control
    undefined field_0x74;
    undefined field_0x75;
    undefined field_0x76;
    undefined field_0x77;
    uint DCDCSYNC; // DCDC Read Status Register
    undefined field_0x7c;
    undefined field_0x7d;
    undefined field_0x7e;
    undefined field_0x7f;
    undefined field_0x80;
    undefined field_0x81;
    undefined field_0x82;
    undefined field_0x83;
    undefined field_0x84;
    undefined field_0x85;
    undefined field_0x86;
    undefined field_0x87;
    undefined field_0x88;
    undefined field_0x89;
    undefined field_0x8a;
    undefined field_0x8b;
    undefined field_0x8c;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
    uint VMONAVDDCTRL; // VMON AVDD Channel Control
    uint VMONALTAVDDCTRL; // Alternate VMON AVDD Channel Control
    uint VMONDVDDCTRL; // VMON DVDD Channel Control
    uint VMONIO0CTRL; // VMON IOVDD0 Channel Control
    undefined field_0xa0;
    undefined field_0xa1;
    undefined field_0xa2;
    undefined field_0xa3;
    undefined field_0xa4;
    undefined field_0xa5;
    undefined field_0xa6;
    undefined field_0xa7;
    undefined field_0xa8;
    undefined field_0xa9;
    undefined field_0xaa;
    undefined field_0xab;
    undefined field_0xac;
    undefined field_0xad;
    undefined field_0xae;
    undefined field_0xaf;
    undefined field_0xb0;
    undefined field_0xb1;
    undefined field_0xb2;
    undefined field_0xb3;
    undefined field_0xb4;
    undefined field_0xb5;
    undefined field_0xb6;
    undefined field_0xb7;
    undefined field_0xb8;
    undefined field_0xb9;
    undefined field_0xba;
    undefined field_0xbb;
    undefined field_0xbc;
    undefined field_0xbd;
    undefined field_0xbe;
    undefined field_0xbf;
    undefined field_0xc0;
    undefined field_0xc1;
    undefined field_0xc2;
    undefined field_0xc3;
    undefined field_0xc4;
    undefined field_0xc5;
    undefined field_0xc6;
    undefined field_0xc7;
    undefined field_0xc8;
    undefined field_0xc9;
    undefined field_0xca;
    undefined field_0xcb;
    undefined field_0xcc;
    undefined field_0xcd;
    undefined field_0xce;
    undefined field_0xcf;
    undefined field_0xd0;
    undefined field_0xd1;
    undefined field_0xd2;
    undefined field_0xd3;
    undefined field_0xd4;
    undefined field_0xd5;
    undefined field_0xd6;
    undefined field_0xd7;
    undefined field_0xd8;
    undefined field_0xd9;
    undefined field_0xda;
    undefined field_0xdb;
    undefined field_0xdc;
    undefined field_0xdd;
    undefined field_0xde;
    undefined field_0xdf;
    undefined field_0xe0;
    undefined field_0xe1;
    undefined field_0xe2;
    undefined field_0xe3;
    undefined field_0xe4;
    undefined field_0xe5;
    undefined field_0xe6;
    undefined field_0xe7;
    undefined field_0xe8;
    undefined field_0xe9;
    undefined field_0xea;
    undefined field_0xeb;
    undefined field_0xec;
    undefined field_0xed;
    undefined field_0xee;
    undefined field_0xef;
    undefined field_0xf0;
    undefined field_0xf1;
    undefined field_0xf2;
    undefined field_0xf3;
    undefined field_0xf4;
    undefined field_0xf5;
    undefined field_0xf6;
    undefined field_0xf7;
    undefined field_0xf8;
    undefined field_0xf9;
    undefined field_0xfa;
    undefined field_0xfb;
    undefined field_0xfc;
    undefined field_0xfd;
    undefined field_0xfe;
    undefined field_0xff;
    undefined field_0x100;
    undefined field_0x101;
    undefined field_0x102;
    undefined field_0x103;
    undefined field_0x104;
    undefined field_0x105;
    undefined field_0x106;
    undefined field_0x107;
    undefined field_0x108;
    undefined field_0x109;
    undefined field_0x10a;
    undefined field_0x10b;
    undefined field_0x10c;
    undefined field_0x10d;
    undefined field_0x10e;
    undefined field_0x10f;
    undefined field_0x110;
    undefined field_0x111;
    undefined field_0x112;
    undefined field_0x113;
    undefined field_0x114;
    undefined field_0x115;
    undefined field_0x116;
    undefined field_0x117;
    undefined field_0x118;
    undefined field_0x119;
    undefined field_0x11a;
    undefined field_0x11b;
    undefined field_0x11c;
    undefined field_0x11d;
    undefined field_0x11e;
    undefined field_0x11f;
    undefined field_0x120;
    undefined field_0x121;
    undefined field_0x122;
    undefined field_0x123;
    undefined field_0x124;
    undefined field_0x125;
    undefined field_0x126;
    undefined field_0x127;
    undefined field_0x128;
    undefined field_0x129;
    undefined field_0x12a;
    undefined field_0x12b;
    undefined field_0x12c;
    undefined field_0x12d;
    undefined field_0x12e;
    undefined field_0x12f;
    undefined field_0x130;
    undefined field_0x131;
    undefined field_0x132;
    undefined field_0x133;
    undefined field_0x134;
    undefined field_0x135;
    undefined field_0x136;
    undefined field_0x137;
    undefined field_0x138;
    undefined field_0x139;
    undefined field_0x13a;
    undefined field_0x13b;
    undefined field_0x13c;
    undefined field_0x13d;
    undefined field_0x13e;
    undefined field_0x13f;
    undefined field_0x140;
    undefined field_0x141;
    undefined field_0x142;
    undefined field_0x143;
    undefined field_0x144;
    undefined field_0x145;
    undefined field_0x146;
    undefined field_0x147;
    undefined field_0x148;
    undefined field_0x149;
    undefined field_0x14a;
    undefined field_0x14b;
    undefined field_0x14c;
    undefined field_0x14d;
    undefined field_0x14e;
    undefined field_0x14f;
    undefined field_0x150;
    undefined field_0x151;
    undefined field_0x152;
    undefined field_0x153;
    undefined field_0x154;
    undefined field_0x155;
    undefined field_0x156;
    undefined field_0x157;
    undefined field_0x158;
    undefined field_0x159;
    undefined field_0x15a;
    undefined field_0x15b;
    undefined field_0x15c;
    undefined field_0x15d;
    undefined field_0x15e;
    undefined field_0x15f;
    undefined field_0x160;
    undefined field_0x161;
    undefined field_0x162;
    undefined field_0x163;
    uint BIASCONF; // Configurations Related to the Bias
    undefined field_0x168;
    undefined field_0x169;
    undefined field_0x16a;
    undefined field_0x16b;
    undefined field_0x16c;
    undefined field_0x16d;
    undefined field_0x16e;
    undefined field_0x16f;
    undefined field_0x170;
    undefined field_0x171;
    undefined field_0x172;
    undefined field_0x173;
    undefined field_0x174;
    undefined field_0x175;
    undefined field_0x176;
    undefined field_0x177;
    undefined field_0x178;
    undefined field_0x179;
    undefined field_0x17a;
    undefined field_0x17b;
    undefined field_0x17c;
    undefined field_0x17d;
    undefined field_0x17e;
    undefined field_0x17f;
    undefined field_0x180;
    undefined field_0x181;
    undefined field_0x182;
    undefined field_0x183;
    undefined field_0x184;
    undefined field_0x185;
    undefined field_0x186;
    undefined field_0x187;
    undefined field_0x188;
    undefined field_0x189;
    undefined field_0x18a;
    undefined field_0x18b;
    undefined field_0x18c;
    undefined field_0x18d;
    undefined field_0x18e;
    undefined field_0x18f;
    uint TESTLOCK; // Test Lock Register
    undefined field_0x194;
    undefined field_0x195;
    undefined field_0x196;
    undefined field_0x197;
    undefined field_0x198;
    undefined field_0x199;
    undefined field_0x19a;
    undefined field_0x19b;
    uint BIASTESTCTRL; // Test Control Register for Regulator and BIAS
};

typedef struct LEUART0 LEUART0, *PLEUART0;

struct LEUART0 {
    uint CTRL; // Control Register
    uint CMD; // Command Register
    uint STATUS; // Status Register
    uint CLKDIV; // Clock Control Register
    uint STARTFRAME; // Start Frame Register
    uint SIGFRAME; // Signal Frame Register
    uint RXDATAX; // Receive Buffer Data Extended Register
    uint RXDATA; // Receive Buffer Data Register
    uint RXDATAXP; // Receive Buffer Data Extended Peek Register
    uint TXDATAX; // Transmit Buffer Data Extended Register
    uint TXDATA; // Transmit Buffer Data Register
    uint IF; // Interrupt Flag Register
    uint IFS; // Interrupt Flag Set Register
    uint IFC; // Interrupt Flag Clear Register
    uint IEN; // Interrupt Enable Register
    uint PULSECTRL; // Pulse Control Register
    uint FREEZE; // Freeze Register
    uint SYNCBUSY; // Synchronization Busy Register
    undefined field_0x48;
    undefined field_0x49;
    undefined field_0x4a;
    undefined field_0x4b;
    undefined field_0x4c;
    undefined field_0x4d;
    undefined field_0x4e;
    undefined field_0x4f;
    undefined field_0x50;
    undefined field_0x51;
    undefined field_0x52;
    undefined field_0x53;
    uint ROUTEPEN; // I/O Routing Pin Enable Register
    uint ROUTELOC0; // I/O Routing Location Register
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    undefined field_0x60;
    undefined field_0x61;
    undefined field_0x62;
    undefined field_0x63;
    uint INPUT; // LEUART Input Register
};

typedef struct FPUEH FPUEH, *PFPUEH;

struct FPUEH {
    uint IF; // Interrupt Flag Register
    uint IFS; // Interrupt Flag Set Register
    uint IFC; // Interrupt Flag Clear Register
    uint IEN; // Interrupt Enable Register
};

typedef struct ADC0 ADC0, *PADC0;

struct ADC0 {
    uint CTRL; // Control Register
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    uint CMD; // Command Register
    uint STATUS; // Status Register
    uint SINGLECTRL; // Single Channel Control Register
    uint SINGLECTRLX; // Single Channel Control Register Continued
    uint SCANCTRL; // Scan Control Register
    uint SCANCTRLX; // Scan Control Register Continued
    uint SCANMASK; // Scan Sequence Input Mask Register
    uint SCANINPUTSEL; // Input Selection Register for Scan Mode
    uint SCANNEGSEL; // Negative Input Select Register for Scan
    uint CMPTHR; // Compare Threshold Register
    uint BIASPROG; // Bias Programming Register for Various Analog Blocks Used in ADC Operation
    uint CAL; // Calibration Register
    uint IF; // Interrupt Flag Register
    uint IFS; // Interrupt Flag Set Register
    uint IFC; // Interrupt Flag Clear Register
    uint IEN; // Interrupt Enable Register
    uint SINGLEDATA; // Single Conversion Result Data
    uint SCANDATA; // Scan Conversion Result Data
    uint SINGLEDATAP; // Single Conversion Result Data Peek Register
    uint SCANDATAP; // Scan Sequence Result Data Peek Register
    undefined field_0x58;
    undefined field_0x59;
    undefined field_0x5a;
    undefined field_0x5b;
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    undefined field_0x60;
    undefined field_0x61;
    undefined field_0x62;
    undefined field_0x63;
    undefined field_0x64;
    undefined field_0x65;
    undefined field_0x66;
    undefined field_0x67;
    uint SCANDATAX; // Scan Sequence Result Data + Data Source Register
    uint SCANDATAXP; // Scan Sequence Result Data + Data Source Peek Register
    undefined field_0x70;
    undefined field_0x71;
    undefined field_0x72;
    undefined field_0x73;
    undefined field_0x74;
    undefined field_0x75;
    undefined field_0x76;
    undefined field_0x77;
    undefined field_0x78;
    undefined field_0x79;
    undefined field_0x7a;
    undefined field_0x7b;
    uint APORTREQ; // APORT Request Status Register
    uint APORTCONFLICT; // APORT Conflict Status Register
    uint SINGLEFIFOCOUNT; // Single FIFO Count Register
    uint SCANFIFOCOUNT; // Scan FIFO Count Register
    uint SINGLEFIFOCLEAR; // Single FIFO Clear Register
    uint SCANFIFOCLEAR; // Scan FIFO Clear Register
    uint APORTMASTERDIS; // APORT Bus Master Disable Register
};

typedef struct CMU_SET CMU_SET, *PCMU_SET;

struct CMU_SET {
    uint CTRL; // CMU Control Register
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    undefined field_0x8;
    undefined field_0x9;
    undefined field_0xa;
    undefined field_0xb;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    uint HFRCOCTRL; // HFRCO Control Register
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    uint AUXHFRCOCTRL; // AUXHFRCO Control Register
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    uint LFRCOCTRL; // LFRCO Control Register
    uint HFXOCTRL; // HFXO Control Register
    uint HFXOCTRL1; // HFXO Control 1
    uint HFXOSTARTUPCTRL; // HFXO Startup Control
    uint HFXOSTEADYSTATECTRL; // HFXO Steady State Control
    uint HFXOTIMEOUTCTRL; // HFXO Timeout Control
    uint LFXOCTRL; // LFXO Control Register
    uint ULFRCOCTRL; // ULFRCO Control Register
    undefined field_0x40;
    undefined field_0x41;
    undefined field_0x42;
    undefined field_0x43;
    undefined field_0x44;
    undefined field_0x45;
    undefined field_0x46;
    undefined field_0x47;
    undefined field_0x48;
    undefined field_0x49;
    undefined field_0x4a;
    undefined field_0x4b;
    undefined field_0x4c;
    undefined field_0x4d;
    undefined field_0x4e;
    undefined field_0x4f;
    uint CALCTRL; // Calibration Control Register
    uint CALCNT; // Calibration Counter Register
    undefined field_0x58;
    undefined field_0x59;
    undefined field_0x5a;
    undefined field_0x5b;
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    uint OSCENCMD; // Oscillator Enable/Disable Command Register
    uint CMD; // Command Register
    undefined field_0x68;
    undefined field_0x69;
    undefined field_0x6a;
    undefined field_0x6b;
    undefined field_0x6c;
    undefined field_0x6d;
    undefined field_0x6e;
    undefined field_0x6f;
    uint DBGCLKSEL; // Debug Trace Clock Select
    uint HFCLKSEL; // High Frequency Clock Select Command Register
    undefined field_0x78;
    undefined field_0x79;
    undefined field_0x7a;
    undefined field_0x7b;
    undefined field_0x7c;
    undefined field_0x7d;
    undefined field_0x7e;
    undefined field_0x7f;
    uint LFACLKSEL; // Low Frequency A Clock Select Register
    uint LFBCLKSEL; // Low Frequency B Clock Select Register
    uint LFECLKSEL; // Low Frequency E Clock Select Register
    undefined field_0x8c;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
    uint STATUS; // Status Register
    uint HFCLKSTATUS; // HFCLK Status Register
    undefined field_0x98;
    undefined field_0x99;
    undefined field_0x9a;
    undefined field_0x9b;
    uint HFXOTRIMSTATUS; // HFXO Trim Status
    uint IF; // Interrupt Flag Register
    uint IFS; // Interrupt Flag Set Register
    uint IFC; // Interrupt Flag Clear Register
    uint IEN; // Interrupt Enable Register
    uint HFBUSCLKEN0; // High Frequency Bus Clock Enable Register 0
    undefined field_0xb4;
    undefined field_0xb5;
    undefined field_0xb6;
    undefined field_0xb7;
    undefined field_0xb8;
    undefined field_0xb9;
    undefined field_0xba;
    undefined field_0xbb;
    undefined field_0xbc;
    undefined field_0xbd;
    undefined field_0xbe;
    undefined field_0xbf;
    uint HFPERCLKEN0; // High Frequency Peripheral Clock Enable Register 0
    undefined field_0xc4;
    undefined field_0xc5;
    undefined field_0xc6;
    undefined field_0xc7;
    uint HFRADIOCLKEN0; // High Frequency Peripheral Clock Enable Register 0
    undefined field_0xcc;
    undefined field_0xcd;
    undefined field_0xce;
    undefined field_0xcf;
    undefined field_0xd0;
    undefined field_0xd1;
    undefined field_0xd2;
    undefined field_0xd3;
    undefined field_0xd4;
    undefined field_0xd5;
    undefined field_0xd6;
    undefined field_0xd7;
    undefined field_0xd8;
    undefined field_0xd9;
    undefined field_0xda;
    undefined field_0xdb;
    undefined field_0xdc;
    undefined field_0xdd;
    undefined field_0xde;
    undefined field_0xdf;
    uint LFACLKEN0; // Low Frequency a Clock Enable Register 0 (Async Reg)
    undefined field_0xe4;
    undefined field_0xe5;
    undefined field_0xe6;
    undefined field_0xe7;
    uint LFBCLKEN0; // Low Frequency B Clock Enable Register 0 (Async Reg)
    undefined field_0xec;
    undefined field_0xed;
    undefined field_0xee;
    undefined field_0xef;
    uint LFECLKEN0; // Low Frequency E Clock Enable Register 0 (Async Reg)
    undefined field_0xf4;
    undefined field_0xf5;
    undefined field_0xf6;
    undefined field_0xf7;
    undefined field_0xf8;
    undefined field_0xf9;
    undefined field_0xfa;
    undefined field_0xfb;
    undefined field_0xfc;
    undefined field_0xfd;
    undefined field_0xfe;
    undefined field_0xff;
    uint HFPRESC; // High Frequency Clock Prescaler Register
    undefined field_0x104;
    undefined field_0x105;
    undefined field_0x106;
    undefined field_0x107;
    uint HFCOREPRESC; // High Frequency Core Clock Prescaler Register
    uint HFPERPRESC; // High Frequency Peripheral Clock Prescaler Register
    uint HFRADIOPRESC; // Radio Clock Prescaler Register
    uint HFEXPPRESC; // High Frequency Export Clock Prescaler Register
    undefined field_0x118;
    undefined field_0x119;
    undefined field_0x11a;
    undefined field_0x11b;
    undefined field_0x11c;
    undefined field_0x11d;
    undefined field_0x11e;
    undefined field_0x11f;
    uint LFAPRESC0; // Low Frequency a Prescaler Register 0 (Async Reg)
    undefined field_0x124;
    undefined field_0x125;
    undefined field_0x126;
    undefined field_0x127;
    uint LFBPRESC0; // Low Frequency B Prescaler Register 0 (Async Reg)
    undefined field_0x12c;
    undefined field_0x12d;
    undefined field_0x12e;
    undefined field_0x12f;
    uint LFEPRESC0; // Low Frequency E Prescaler Register 0 (Async Reg)
    undefined field_0x134;
    undefined field_0x135;
    undefined field_0x136;
    undefined field_0x137;
    undefined field_0x138;
    undefined field_0x139;
    undefined field_0x13a;
    undefined field_0x13b;
    undefined field_0x13c;
    undefined field_0x13d;
    undefined field_0x13e;
    undefined field_0x13f;
    uint SYNCBUSY; // Synchronization Busy Register
    uint FREEZE; // Freeze Register
    undefined field_0x148;
    undefined field_0x149;
    undefined field_0x14a;
    undefined field_0x14b;
    undefined field_0x14c;
    undefined field_0x14d;
    undefined field_0x14e;
    undefined field_0x14f;
    uint PCNTCTRL; // PCNT Control Register
    uint LCDCTRL; // LCD Control Register
    uint LVDSCTRL; // LVDSCTRL Control Register
    uint ADCCTRL; // ADC Control Register
    undefined field_0x160;
    undefined field_0x161;
    undefined field_0x162;
    undefined field_0x163;
    undefined field_0x164;
    undefined field_0x165;
    undefined field_0x166;
    undefined field_0x167;
    undefined field_0x168;
    undefined field_0x169;
    undefined field_0x16a;
    undefined field_0x16b;
    undefined field_0x16c;
    undefined field_0x16d;
    undefined field_0x16e;
    undefined field_0x16f;
    uint ROUTEPEN; // I/O Routing Pin Enable Register
    uint ROUTELOC0; // I/O Routing Location Register
    undefined field_0x178;
    undefined field_0x179;
    undefined field_0x17a;
    undefined field_0x17b;
    undefined field_0x17c;
    undefined field_0x17d;
    undefined field_0x17e;
    undefined field_0x17f;
    uint LOCK; // Configuration Lock Register
    undefined field_0x184;
    undefined field_0x185;
    undefined field_0x186;
    undefined field_0x187;
    uint RFLOCK0; // RF LOCK Register
    undefined field_0x18c;
    undefined field_0x18d;
    undefined field_0x18e;
    undefined field_0x18f;
    uint HFBUSCLKENMASK0;
    undefined field_0x194;
    undefined field_0x195;
    undefined field_0x196;
    undefined field_0x197;
    uint HFPERCLKENMASK0;
    undefined field_0x19c;
    undefined field_0x19d;
    undefined field_0x19e;
    undefined field_0x19f;
    undefined field_0x1a0;
    undefined field_0x1a1;
    undefined field_0x1a2;
    undefined field_0x1a3;
    uint HFRADIOCLKENMASK0;
    undefined field_0x1a8;
    undefined field_0x1a9;
    undefined field_0x1aa;
    undefined field_0x1ab;
    undefined field_0x1ac;
    undefined field_0x1ad;
    undefined field_0x1ae;
    undefined field_0x1af;
    undefined field_0x1b0;
    undefined field_0x1b1;
    undefined field_0x1b2;
    undefined field_0x1b3;
    uint LFACLKENMASK0;
    undefined field_0x1b8;
    undefined field_0x1b9;
    undefined field_0x1ba;
    undefined field_0x1bb;
    uint LFBCLKENMASK0;
    undefined field_0x1c0;
    undefined field_0x1c1;
    undefined field_0x1c2;
    undefined field_0x1c3;
    uint LFECLKENMASK0;
    undefined field_0x1c8;
    undefined field_0x1c9;
    undefined field_0x1ca;
    undefined field_0x1cb;
    uint PCNTCLKENMASK;
    uint TEST;
    uint TESTHFRCOCTRL;
    uint TESTAUXHFRCOCTRL;
    uint TESTLFRCOCTRL;
    uint TESTHFXOCTRL;
    uint TESTLFXOCTRL;
};

typedef struct LDMA LDMA, *PLDMA;

struct LDMA {
    uint CTRL; // DMA Control Register
    uint STATUS; // DMA Status Register
    uint SYNC; // DMA Synchronization Trigger Register (Single-Cycle RMW)
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    undefined field_0x10;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    undefined field_0x18;
    undefined field_0x19;
    undefined field_0x1a;
    undefined field_0x1b;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    uint CHEN; // DMA Channel Enable Register (Single-Cycle RMW)
    uint CHBUSY; // DMA Channel Busy Register
    uint CHDONE; // DMA Channel Linking Done Register (Single-Cycle RMW)
    uint DBGHALT; // DMA Channel Debug Halt Register
    uint SWREQ; // DMA Channel Software Transfer Request Register
    uint REQDIS; // DMA Channel Request Disable Register
    uint REQPEND; // DMA Channel Requests Pending Register
    uint LINKLOAD; // DMA Channel Link Load Register
    uint REQCLEAR; // DMA Channel Request Clear Register
    undefined field_0x44;
    undefined field_0x45;
    undefined field_0x46;
    undefined field_0x47;
    undefined field_0x48;
    undefined field_0x49;
    undefined field_0x4a;
    undefined field_0x4b;
    undefined field_0x4c;
    undefined field_0x4d;
    undefined field_0x4e;
    undefined field_0x4f;
    undefined field_0x50;
    undefined field_0x51;
    undefined field_0x52;
    undefined field_0x53;
    undefined field_0x54;
    undefined field_0x55;
    undefined field_0x56;
    undefined field_0x57;
    undefined field_0x58;
    undefined field_0x59;
    undefined field_0x5a;
    undefined field_0x5b;
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    uint IF; // Interrupt Flag Register
    uint IFS; // Interrupt Flag Set Register
    uint IFC; // Interrupt Flag Clear Register
    uint IEN; // Interrupt Enable Register
    undefined field_0x70;
    undefined field_0x71;
    undefined field_0x72;
    undefined field_0x73;
    undefined field_0x74;
    undefined field_0x75;
    undefined field_0x76;
    undefined field_0x77;
    undefined field_0x78;
    undefined field_0x79;
    undefined field_0x7a;
    undefined field_0x7b;
    undefined field_0x7c;
    undefined field_0x7d;
    undefined field_0x7e;
    undefined field_0x7f;
    uint CH0_REQSEL; // Channel Peripheral Request Select Register
    uint CH0_CFG; // Channel Configuration Register
    uint CH0_LOOP; // Channel Loop Counter Register
    uint CH0_CTRL; // Channel Descriptor Control Word Register
    uint CH0_SRC; // Channel Descriptor Source Data Address Register
    uint CH0_DST; // Channel Descriptor Destination Data Address Register
    uint CH0_LINK; // Channel Descriptor Link Structure Address Register
    undefined field_0x9c;
    undefined field_0x9d;
    undefined field_0x9e;
    undefined field_0x9f;
    undefined field_0xa0;
    undefined field_0xa1;
    undefined field_0xa2;
    undefined field_0xa3;
    undefined field_0xa4;
    undefined field_0xa5;
    undefined field_0xa6;
    undefined field_0xa7;
    undefined field_0xa8;
    undefined field_0xa9;
    undefined field_0xaa;
    undefined field_0xab;
    undefined field_0xac;
    undefined field_0xad;
    undefined field_0xae;
    undefined field_0xaf;
    uint CH1_REQSEL; // Channel Peripheral Request Select Register
    uint CH1_CFG; // Channel Configuration Register
    uint CH1_LOOP; // Channel Loop Counter Register
    uint CH1_CTRL; // Channel Descriptor Control Word Register
    uint CH1_SRC; // Channel Descriptor Source Data Address Register
    uint CH1_DST; // Channel Descriptor Destination Data Address Register
    uint CH1_LINK; // Channel Descriptor Link Structure Address Register
    undefined field_0xcc;
    undefined field_0xcd;
    undefined field_0xce;
    undefined field_0xcf;
    undefined field_0xd0;
    undefined field_0xd1;
    undefined field_0xd2;
    undefined field_0xd3;
    undefined field_0xd4;
    undefined field_0xd5;
    undefined field_0xd6;
    undefined field_0xd7;
    undefined field_0xd8;
    undefined field_0xd9;
    undefined field_0xda;
    undefined field_0xdb;
    undefined field_0xdc;
    undefined field_0xdd;
    undefined field_0xde;
    undefined field_0xdf;
    uint CH2_REQSEL; // Channel Peripheral Request Select Register
    uint CH2_CFG; // Channel Configuration Register
    uint CH2_LOOP; // Channel Loop Counter Register
    uint CH2_CTRL; // Channel Descriptor Control Word Register
    uint CH2_SRC; // Channel Descriptor Source Data Address Register
    uint CH2_DST; // Channel Descriptor Destination Data Address Register
    uint CH2_LINK; // Channel Descriptor Link Structure Address Register
    undefined field_0xfc;
    undefined field_0xfd;
    undefined field_0xfe;
    undefined field_0xff;
    undefined field_0x100;
    undefined field_0x101;
    undefined field_0x102;
    undefined field_0x103;
    undefined field_0x104;
    undefined field_0x105;
    undefined field_0x106;
    undefined field_0x107;
    undefined field_0x108;
    undefined field_0x109;
    undefined field_0x10a;
    undefined field_0x10b;
    undefined field_0x10c;
    undefined field_0x10d;
    undefined field_0x10e;
    undefined field_0x10f;
    uint CH3_REQSEL; // Channel Peripheral Request Select Register
    uint CH3_CFG; // Channel Configuration Register
    uint CH3_LOOP; // Channel Loop Counter Register
    uint CH3_CTRL; // Channel Descriptor Control Word Register
    uint CH3_SRC; // Channel Descriptor Source Data Address Register
    uint CH3_DST; // Channel Descriptor Destination Data Address Register
    uint CH3_LINK; // Channel Descriptor Link Structure Address Register
    undefined field_0x12c;
    undefined field_0x12d;
    undefined field_0x12e;
    undefined field_0x12f;
    undefined field_0x130;
    undefined field_0x131;
    undefined field_0x132;
    undefined field_0x133;
    undefined field_0x134;
    undefined field_0x135;
    undefined field_0x136;
    undefined field_0x137;
    undefined field_0x138;
    undefined field_0x139;
    undefined field_0x13a;
    undefined field_0x13b;
    undefined field_0x13c;
    undefined field_0x13d;
    undefined field_0x13e;
    undefined field_0x13f;
    uint CH4_REQSEL; // Channel Peripheral Request Select Register
    uint CH4_CFG; // Channel Configuration Register
    uint CH4_LOOP; // Channel Loop Counter Register
    uint CH4_CTRL; // Channel Descriptor Control Word Register
    uint CH4_SRC; // Channel Descriptor Source Data Address Register
    uint CH4_DST; // Channel Descriptor Destination Data Address Register
    uint CH4_LINK; // Channel Descriptor Link Structure Address Register
    undefined field_0x15c;
    undefined field_0x15d;
    undefined field_0x15e;
    undefined field_0x15f;
    undefined field_0x160;
    undefined field_0x161;
    undefined field_0x162;
    undefined field_0x163;
    undefined field_0x164;
    undefined field_0x165;
    undefined field_0x166;
    undefined field_0x167;
    undefined field_0x168;
    undefined field_0x169;
    undefined field_0x16a;
    undefined field_0x16b;
    undefined field_0x16c;
    undefined field_0x16d;
    undefined field_0x16e;
    undefined field_0x16f;
    uint CH5_REQSEL; // Channel Peripheral Request Select Register
    uint CH5_CFG; // Channel Configuration Register
    uint CH5_LOOP; // Channel Loop Counter Register
    uint CH5_CTRL; // Channel Descriptor Control Word Register
    uint CH5_SRC; // Channel Descriptor Source Data Address Register
    uint CH5_DST; // Channel Descriptor Destination Data Address Register
    uint CH5_LINK; // Channel Descriptor Link Structure Address Register
    undefined field_0x18c;
    undefined field_0x18d;
    undefined field_0x18e;
    undefined field_0x18f;
    undefined field_0x190;
    undefined field_0x191;
    undefined field_0x192;
    undefined field_0x193;
    undefined field_0x194;
    undefined field_0x195;
    undefined field_0x196;
    undefined field_0x197;
    undefined field_0x198;
    undefined field_0x199;
    undefined field_0x19a;
    undefined field_0x19b;
    undefined field_0x19c;
    undefined field_0x19d;
    undefined field_0x19e;
    undefined field_0x19f;
    uint CH6_REQSEL; // Channel Peripheral Request Select Register
    uint CH6_CFG; // Channel Configuration Register
    uint CH6_LOOP; // Channel Loop Counter Register
    uint CH6_CTRL; // Channel Descriptor Control Word Register
    uint CH6_SRC; // Channel Descriptor Source Data Address Register
    uint CH6_DST; // Channel Descriptor Destination Data Address Register
    uint CH6_LINK; // Channel Descriptor Link Structure Address Register
    undefined field_0x1bc;
    undefined field_0x1bd;
    undefined field_0x1be;
    undefined field_0x1bf;
    undefined field_0x1c0;
    undefined field_0x1c1;
    undefined field_0x1c2;
    undefined field_0x1c3;
    undefined field_0x1c4;
    undefined field_0x1c5;
    undefined field_0x1c6;
    undefined field_0x1c7;
    undefined field_0x1c8;
    undefined field_0x1c9;
    undefined field_0x1ca;
    undefined field_0x1cb;
    undefined field_0x1cc;
    undefined field_0x1cd;
    undefined field_0x1ce;
    undefined field_0x1cf;
    uint CH7_REQSEL; // Channel Peripheral Request Select Register
    uint CH7_CFG; // Channel Configuration Register
    uint CH7_LOOP; // Channel Loop Counter Register
    uint CH7_CTRL; // Channel Descriptor Control Word Register
    uint CH7_SRC; // Channel Descriptor Source Data Address Register
    uint CH7_DST; // Channel Descriptor Destination Data Address Register
    uint CH7_LINK; // Channel Descriptor Link Structure Address Register
};

typedef struct CRC CRC, *PCRC;

struct CRC {
    uint CTRL;
    uint STATUS;
    uint CMD;
    uint INPUTDATA;
    uint INIT;
    uint DATA;
    uint POLY;
};

typedef struct MODEM_CLR MODEM_CLR, *PMODEM_CLR;

struct MODEM_CLR {
    uint STATUS;
    uint TIMDETSTATUS;
    uint FREQOFFEST;
    uint AFCADJRX;
    uint AFCADJTX;
    uint MIXCTRL;
    uint CTRL0;
    uint CTRL1;
    uint CTRL2;
    uint CTRL3;
    uint CTRL4;
    uint CTRL5;
    uint TXBR;
    uint RXBR;
    uint CF;
    uint PRE;
    uint SYNC0;
    uint SYNC1;
    uint TIMING;
    uint DSSS0;
    uint MODINDEX;
    uint AFC;
    uint AFCADJLIM;
    uint SHAPING0;
    uint SHAPING1;
    uint SHAPING2;
    uint RAMPCTRL;
    uint RAMPLEV;
    uint ROUTEPEN;
    uint ROUTELOC0;
    uint ROUTELOC1;
    undefined field_0x7c;
    undefined field_0x7d;
    undefined field_0x7e;
    undefined field_0x7f;
    uint IF;
    uint IFS;
    uint IFC;
    uint IEN;
    uint CMD;
    undefined field_0x94;
    undefined field_0x95;
    undefined field_0x96;
    undefined field_0x97;
    uint DCCOMP;
    uint DCCOMPFILTINIT;
    undefined field_0xa0;
    undefined field_0xa1;
    undefined field_0xa2;
    undefined field_0xa3;
    undefined field_0xa4;
    undefined field_0xa5;
    undefined field_0xa6;
    undefined field_0xa7;
    undefined field_0xa8;
    undefined field_0xa9;
    undefined field_0xaa;
    undefined field_0xab;
    undefined field_0xac;
    undefined field_0xad;
    undefined field_0xae;
    undefined field_0xaf;
    undefined field_0xb0;
    undefined field_0xb1;
    undefined field_0xb2;
    undefined field_0xb3;
    undefined field_0xb4;
    undefined field_0xb5;
    undefined field_0xb6;
    undefined field_0xb7;
    undefined field_0xb8;
    undefined field_0xb9;
    undefined field_0xba;
    undefined field_0xbb;
    undefined field_0xbc;
    undefined field_0xbd;
    undefined field_0xbe;
    undefined field_0xbf;
    undefined field_0xc0;
    undefined field_0xc1;
    undefined field_0xc2;
    undefined field_0xc3;
    undefined field_0xc4;
    undefined field_0xc5;
    undefined field_0xc6;
    undefined field_0xc7;
    undefined field_0xc8;
    undefined field_0xc9;
    undefined field_0xca;
    undefined field_0xcb;
    undefined field_0xcc;
    undefined field_0xcd;
    undefined field_0xce;
    undefined field_0xcf;
    undefined field_0xd0;
    undefined field_0xd1;
    undefined field_0xd2;
    undefined field_0xd3;
    undefined field_0xd4;
    undefined field_0xd5;
    undefined field_0xd6;
    undefined field_0xd7;
    undefined field_0xd8;
    undefined field_0xd9;
    undefined field_0xda;
    undefined field_0xdb;
    undefined field_0xdc;
    undefined field_0xdd;
    undefined field_0xde;
    undefined field_0xdf;
    undefined field_0xe0;
    undefined field_0xe1;
    undefined field_0xe2;
    undefined field_0xe3;
    undefined field_0xe4;
    undefined field_0xe5;
    undefined field_0xe6;
    undefined field_0xe7;
    undefined field_0xe8;
    undefined field_0xe9;
    undefined field_0xea;
    undefined field_0xeb;
    undefined field_0xec;
    undefined field_0xed;
    undefined field_0xee;
    undefined field_0xef;
    undefined field_0xf0;
    undefined field_0xf1;
    undefined field_0xf2;
    undefined field_0xf3;
    undefined field_0xf4;
    undefined field_0xf5;
    undefined field_0xf6;
    undefined field_0xf7;
    undefined field_0xf8;
    undefined field_0xf9;
    undefined field_0xfa;
    undefined field_0xfb;
    undefined field_0xfc;
    undefined field_0xfd;
    undefined field_0xfe;
    undefined field_0xff;
    uint DCESTI;
    undefined field_0x104;
    undefined field_0x105;
    undefined field_0x106;
    undefined field_0x107;
    undefined field_0x108;
    undefined field_0x109;
    undefined field_0x10a;
    undefined field_0x10b;
    undefined field_0x10c;
    undefined field_0x10d;
    undefined field_0x10e;
    undefined field_0x10f;
    undefined field_0x110;
    undefined field_0x111;
    undefined field_0x112;
    undefined field_0x113;
    undefined field_0x114;
    undefined field_0x115;
    undefined field_0x116;
    undefined field_0x117;
    undefined field_0x118;
    undefined field_0x119;
    undefined field_0x11a;
    undefined field_0x11b;
    undefined field_0x11c;
    undefined field_0x11d;
    undefined field_0x11e;
    undefined field_0x11f;
    undefined field_0x120;
    undefined field_0x121;
    undefined field_0x122;
    undefined field_0x123;
    undefined field_0x124;
    undefined field_0x125;
    undefined field_0x126;
    undefined field_0x127;
    undefined field_0x128;
    undefined field_0x129;
    undefined field_0x12a;
    undefined field_0x12b;
    undefined field_0x12c;
    undefined field_0x12d;
    undefined field_0x12e;
    undefined field_0x12f;
    undefined field_0x130;
    undefined field_0x131;
    undefined field_0x132;
    undefined field_0x133;
    undefined field_0x134;
    undefined field_0x135;
    undefined field_0x136;
    undefined field_0x137;
    undefined field_0x138;
    undefined field_0x139;
    undefined field_0x13a;
    undefined field_0x13b;
    undefined field_0x13c;
    undefined field_0x13d;
    undefined field_0x13e;
    undefined field_0x13f;
    undefined field_0x140;
    undefined field_0x141;
    undefined field_0x142;
    undefined field_0x143;
    undefined field_0x144;
    undefined field_0x145;
    undefined field_0x146;
    undefined field_0x147;
    undefined field_0x148;
    undefined field_0x149;
    undefined field_0x14a;
    undefined field_0x14b;
    undefined field_0x14c;
    undefined field_0x14d;
    undefined field_0x14e;
    undefined field_0x14f;
    undefined field_0x150;
    undefined field_0x151;
    undefined field_0x152;
    undefined field_0x153;
    undefined field_0x154;
    undefined field_0x155;
    undefined field_0x156;
    undefined field_0x157;
    undefined field_0x158;
    undefined field_0x159;
    undefined field_0x15a;
    undefined field_0x15b;
    undefined field_0x15c;
    undefined field_0x15d;
    undefined field_0x15e;
    undefined field_0x15f;
    undefined field_0x160;
    undefined field_0x161;
    undefined field_0x162;
    undefined field_0x163;
    undefined field_0x164;
    undefined field_0x165;
    undefined field_0x166;
    undefined field_0x167;
    undefined field_0x168;
    undefined field_0x169;
    undefined field_0x16a;
    undefined field_0x16b;
    undefined field_0x16c;
    undefined field_0x16d;
    undefined field_0x16e;
    undefined field_0x16f;
    undefined field_0x170;
    undefined field_0x171;
    undefined field_0x172;
    undefined field_0x173;
    undefined field_0x174;
    undefined field_0x175;
    undefined field_0x176;
    undefined field_0x177;
    undefined field_0x178;
    undefined field_0x179;
    undefined field_0x17a;
    undefined field_0x17b;
    undefined field_0x17c;
    undefined field_0x17d;
    undefined field_0x17e;
    undefined field_0x17f;
    undefined field_0x180;
    undefined field_0x181;
    undefined field_0x182;
    undefined field_0x183;
    undefined field_0x184;
    undefined field_0x185;
    undefined field_0x186;
    undefined field_0x187;
    undefined field_0x188;
    undefined field_0x189;
    undefined field_0x18a;
    undefined field_0x18b;
    undefined field_0x18c;
    undefined field_0x18d;
    undefined field_0x18e;
    undefined field_0x18f;
    undefined field_0x190;
    undefined field_0x191;
    undefined field_0x192;
    undefined field_0x193;
    undefined field_0x194;
    undefined field_0x195;
    undefined field_0x196;
    undefined field_0x197;
    undefined field_0x198;
    undefined field_0x199;
    undefined field_0x19a;
    undefined field_0x19b;
    undefined field_0x19c;
    undefined field_0x19d;
    undefined field_0x19e;
    undefined field_0x19f;
    undefined field_0x1a0;
    undefined field_0x1a1;
    undefined field_0x1a2;
    undefined field_0x1a3;
    undefined field_0x1a4;
    undefined field_0x1a5;
    undefined field_0x1a6;
    undefined field_0x1a7;
    undefined field_0x1a8;
    undefined field_0x1a9;
    undefined field_0x1aa;
    undefined field_0x1ab;
    undefined field_0x1ac;
    undefined field_0x1ad;
    undefined field_0x1ae;
    undefined field_0x1af;
    undefined field_0x1b0;
    undefined field_0x1b1;
    undefined field_0x1b2;
    undefined field_0x1b3;
    undefined field_0x1b4;
    undefined field_0x1b5;
    undefined field_0x1b6;
    undefined field_0x1b7;
    undefined field_0x1b8;
    undefined field_0x1b9;
    undefined field_0x1ba;
    undefined field_0x1bb;
    undefined field_0x1bc;
    undefined field_0x1bd;
    undefined field_0x1be;
    undefined field_0x1bf;
    undefined field_0x1c0;
    undefined field_0x1c1;
    undefined field_0x1c2;
    undefined field_0x1c3;
    undefined field_0x1c4;
    undefined field_0x1c5;
    undefined field_0x1c6;
    undefined field_0x1c7;
    undefined field_0x1c8;
    undefined field_0x1c9;
    undefined field_0x1ca;
    undefined field_0x1cb;
    undefined field_0x1cc;
    undefined field_0x1cd;
    undefined field_0x1ce;
    undefined field_0x1cf;
    undefined field_0x1d0;
    undefined field_0x1d1;
    undefined field_0x1d2;
    undefined field_0x1d3;
    undefined field_0x1d4;
    undefined field_0x1d5;
    undefined field_0x1d6;
    undefined field_0x1d7;
    undefined field_0x1d8;
    undefined field_0x1d9;
    undefined field_0x1da;
    undefined field_0x1db;
    undefined field_0x1dc;
    undefined field_0x1dd;
    undefined field_0x1de;
    undefined field_0x1df;
    undefined field_0x1e0;
    undefined field_0x1e1;
    undefined field_0x1e2;
    undefined field_0x1e3;
    undefined field_0x1e4;
    undefined field_0x1e5;
    undefined field_0x1e6;
    undefined field_0x1e7;
    undefined field_0x1e8;
    undefined field_0x1e9;
    undefined field_0x1ea;
    undefined field_0x1eb;
    undefined field_0x1ec;
    undefined field_0x1ed;
    undefined field_0x1ee;
    undefined field_0x1ef;
    undefined field_0x1f0;
    undefined field_0x1f1;
    undefined field_0x1f2;
    undefined field_0x1f3;
    undefined field_0x1f4;
    undefined field_0x1f5;
    undefined field_0x1f6;
    undefined field_0x1f7;
    undefined field_0x1f8;
    undefined field_0x1f9;
    undefined field_0x1fa;
    undefined field_0x1fb;
    undefined field_0x1fc;
    undefined field_0x1fd;
    undefined field_0x1fe;
    undefined field_0x1ff;
    undefined field_0x200;
    undefined field_0x201;
    undefined field_0x202;
    undefined field_0x203;
    undefined field_0x204;
    undefined field_0x205;
    undefined field_0x206;
    undefined field_0x207;
    undefined field_0x208;
    undefined field_0x209;
    undefined field_0x20a;
    undefined field_0x20b;
    undefined field_0x20c;
    undefined field_0x20d;
    undefined field_0x20e;
    undefined field_0x20f;
    undefined field_0x210;
    undefined field_0x211;
    undefined field_0x212;
    undefined field_0x213;
    undefined field_0x214;
    undefined field_0x215;
    undefined field_0x216;
    undefined field_0x217;
    undefined field_0x218;
    undefined field_0x219;
    undefined field_0x21a;
    undefined field_0x21b;
    undefined field_0x21c;
    undefined field_0x21d;
    undefined field_0x21e;
    undefined field_0x21f;
    undefined field_0x220;
    undefined field_0x221;
    undefined field_0x222;
    undefined field_0x223;
    undefined field_0x224;
    undefined field_0x225;
    undefined field_0x226;
    undefined field_0x227;
    undefined field_0x228;
    undefined field_0x229;
    undefined field_0x22a;
    undefined field_0x22b;
    undefined field_0x22c;
    undefined field_0x22d;
    undefined field_0x22e;
    undefined field_0x22f;
    undefined field_0x230;
    undefined field_0x231;
    undefined field_0x232;
    undefined field_0x233;
    undefined field_0x234;
    undefined field_0x235;
    undefined field_0x236;
    undefined field_0x237;
    undefined field_0x238;
    undefined field_0x239;
    undefined field_0x23a;
    undefined field_0x23b;
    undefined field_0x23c;
    undefined field_0x23d;
    undefined field_0x23e;
    undefined field_0x23f;
    undefined field_0x240;
    undefined field_0x241;
    undefined field_0x242;
    undefined field_0x243;
    undefined field_0x244;
    undefined field_0x245;
    undefined field_0x246;
    undefined field_0x247;
    undefined field_0x248;
    undefined field_0x249;
    undefined field_0x24a;
    undefined field_0x24b;
    undefined field_0x24c;
    undefined field_0x24d;
    undefined field_0x24e;
    undefined field_0x24f;
    undefined field_0x250;
    undefined field_0x251;
    undefined field_0x252;
    undefined field_0x253;
    undefined field_0x254;
    undefined field_0x255;
    undefined field_0x256;
    undefined field_0x257;
    undefined field_0x258;
    undefined field_0x259;
    undefined field_0x25a;
    undefined field_0x25b;
    undefined field_0x25c;
    undefined field_0x25d;
    undefined field_0x25e;
    undefined field_0x25f;
    undefined field_0x260;
    undefined field_0x261;
    undefined field_0x262;
    undefined field_0x263;
    undefined field_0x264;
    undefined field_0x265;
    undefined field_0x266;
    undefined field_0x267;
    undefined field_0x268;
    undefined field_0x269;
    undefined field_0x26a;
    undefined field_0x26b;
    undefined field_0x26c;
    undefined field_0x26d;
    undefined field_0x26e;
    undefined field_0x26f;
    undefined field_0x270;
    undefined field_0x271;
    undefined field_0x272;
    undefined field_0x273;
    undefined field_0x274;
    undefined field_0x275;
    undefined field_0x276;
    undefined field_0x277;
    undefined field_0x278;
    undefined field_0x279;
    undefined field_0x27a;
    undefined field_0x27b;
    undefined field_0x27c;
    undefined field_0x27d;
    undefined field_0x27e;
    undefined field_0x27f;
    undefined field_0x280;
    undefined field_0x281;
    undefined field_0x282;
    undefined field_0x283;
    undefined field_0x284;
    undefined field_0x285;
    undefined field_0x286;
    undefined field_0x287;
    undefined field_0x288;
    undefined field_0x289;
    undefined field_0x28a;
    undefined field_0x28b;
    undefined field_0x28c;
    undefined field_0x28d;
    undefined field_0x28e;
    undefined field_0x28f;
    undefined field_0x290;
    undefined field_0x291;
    undefined field_0x292;
    undefined field_0x293;
    undefined field_0x294;
    undefined field_0x295;
    undefined field_0x296;
    undefined field_0x297;
    undefined field_0x298;
    undefined field_0x299;
    undefined field_0x29a;
    undefined field_0x29b;
    undefined field_0x29c;
    undefined field_0x29d;
    undefined field_0x29e;
    undefined field_0x29f;
    undefined field_0x2a0;
    undefined field_0x2a1;
    undefined field_0x2a2;
    undefined field_0x2a3;
    undefined field_0x2a4;
    undefined field_0x2a5;
    undefined field_0x2a6;
    undefined field_0x2a7;
    undefined field_0x2a8;
    undefined field_0x2a9;
    undefined field_0x2aa;
    undefined field_0x2ab;
    undefined field_0x2ac;
    undefined field_0x2ad;
    undefined field_0x2ae;
    undefined field_0x2af;
    undefined field_0x2b0;
    undefined field_0x2b1;
    undefined field_0x2b2;
    undefined field_0x2b3;
    undefined field_0x2b4;
    undefined field_0x2b5;
    undefined field_0x2b6;
    undefined field_0x2b7;
    undefined field_0x2b8;
    undefined field_0x2b9;
    undefined field_0x2ba;
    undefined field_0x2bb;
    undefined field_0x2bc;
    undefined field_0x2bd;
    undefined field_0x2be;
    undefined field_0x2bf;
    undefined field_0x2c0;
    undefined field_0x2c1;
    undefined field_0x2c2;
    undefined field_0x2c3;
    undefined field_0x2c4;
    undefined field_0x2c5;
    undefined field_0x2c6;
    undefined field_0x2c7;
    undefined field_0x2c8;
    undefined field_0x2c9;
    undefined field_0x2ca;
    undefined field_0x2cb;
    undefined field_0x2cc;
    undefined field_0x2cd;
    undefined field_0x2ce;
    undefined field_0x2cf;
    undefined field_0x2d0;
    undefined field_0x2d1;
    undefined field_0x2d2;
    undefined field_0x2d3;
    undefined field_0x2d4;
    undefined field_0x2d5;
    undefined field_0x2d6;
    undefined field_0x2d7;
    undefined field_0x2d8;
    undefined field_0x2d9;
    undefined field_0x2da;
    undefined field_0x2db;
    undefined field_0x2dc;
    undefined field_0x2dd;
    undefined field_0x2de;
    undefined field_0x2df;
    undefined field_0x2e0;
    undefined field_0x2e1;
    undefined field_0x2e2;
    undefined field_0x2e3;
    undefined field_0x2e4;
    undefined field_0x2e5;
    undefined field_0x2e6;
    undefined field_0x2e7;
    undefined field_0x2e8;
    undefined field_0x2e9;
    undefined field_0x2ea;
    undefined field_0x2eb;
    undefined field_0x2ec;
    undefined field_0x2ed;
    undefined field_0x2ee;
    undefined field_0x2ef;
    undefined field_0x2f0;
    undefined field_0x2f1;
    undefined field_0x2f2;
    undefined field_0x2f3;
    undefined field_0x2f4;
    undefined field_0x2f5;
    undefined field_0x2f6;
    undefined field_0x2f7;
    undefined field_0x2f8;
    undefined field_0x2f9;
    undefined field_0x2fa;
    undefined field_0x2fb;
    undefined field_0x2fc;
    undefined field_0x2fd;
    undefined field_0x2fe;
    undefined field_0x2ff;
    undefined field_0x300;
    undefined field_0x301;
    undefined field_0x302;
    undefined field_0x303;
    undefined field_0x304;
    undefined field_0x305;
    undefined field_0x306;
    undefined field_0x307;
    undefined field_0x308;
    undefined field_0x309;
    undefined field_0x30a;
    undefined field_0x30b;
    undefined field_0x30c;
    undefined field_0x30d;
    undefined field_0x30e;
    undefined field_0x30f;
    undefined field_0x310;
    undefined field_0x311;
    undefined field_0x312;
    undefined field_0x313;
    undefined field_0x314;
    undefined field_0x315;
    undefined field_0x316;
    undefined field_0x317;
    undefined field_0x318;
    undefined field_0x319;
    undefined field_0x31a;
    undefined field_0x31b;
    undefined field_0x31c;
    undefined field_0x31d;
    undefined field_0x31e;
    undefined field_0x31f;
    undefined field_0x320;
    undefined field_0x321;
    undefined field_0x322;
    undefined field_0x323;
    undefined field_0x324;
    undefined field_0x325;
    undefined field_0x326;
    undefined field_0x327;
    undefined field_0x328;
    undefined field_0x329;
    undefined field_0x32a;
    undefined field_0x32b;
    undefined field_0x32c;
    undefined field_0x32d;
    undefined field_0x32e;
    undefined field_0x32f;
    undefined field_0x330;
    undefined field_0x331;
    undefined field_0x332;
    undefined field_0x333;
    undefined field_0x334;
    undefined field_0x335;
    undefined field_0x336;
    undefined field_0x337;
    undefined field_0x338;
    undefined field_0x339;
    undefined field_0x33a;
    undefined field_0x33b;
    undefined field_0x33c;
    undefined field_0x33d;
    undefined field_0x33e;
    undefined field_0x33f;
    undefined field_0x340;
    undefined field_0x341;
    undefined field_0x342;
    undefined field_0x343;
    undefined field_0x344;
    undefined field_0x345;
    undefined field_0x346;
    undefined field_0x347;
    undefined field_0x348;
    undefined field_0x349;
    undefined field_0x34a;
    undefined field_0x34b;
    undefined field_0x34c;
    undefined field_0x34d;
    undefined field_0x34e;
    undefined field_0x34f;
    undefined field_0x350;
    undefined field_0x351;
    undefined field_0x352;
    undefined field_0x353;
    undefined field_0x354;
    undefined field_0x355;
    undefined field_0x356;
    undefined field_0x357;
    undefined field_0x358;
    undefined field_0x359;
    undefined field_0x35a;
    undefined field_0x35b;
    undefined field_0x35c;
    undefined field_0x35d;
    undefined field_0x35e;
    undefined field_0x35f;
    undefined field_0x360;
    undefined field_0x361;
    undefined field_0x362;
    undefined field_0x363;
    undefined field_0x364;
    undefined field_0x365;
    undefined field_0x366;
    undefined field_0x367;
    undefined field_0x368;
    undefined field_0x369;
    undefined field_0x36a;
    undefined field_0x36b;
    undefined field_0x36c;
    undefined field_0x36d;
    undefined field_0x36e;
    undefined field_0x36f;
    undefined field_0x370;
    undefined field_0x371;
    undefined field_0x372;
    undefined field_0x373;
    undefined field_0x374;
    undefined field_0x375;
    undefined field_0x376;
    undefined field_0x377;
    undefined field_0x378;
    undefined field_0x379;
    undefined field_0x37a;
    undefined field_0x37b;
    undefined field_0x37c;
    undefined field_0x37d;
    undefined field_0x37e;
    undefined field_0x37f;
    undefined field_0x380;
    undefined field_0x381;
    undefined field_0x382;
    undefined field_0x383;
    undefined field_0x384;
    undefined field_0x385;
    undefined field_0x386;
    undefined field_0x387;
    undefined field_0x388;
    undefined field_0x389;
    undefined field_0x38a;
    undefined field_0x38b;
    undefined field_0x38c;
    undefined field_0x38d;
    undefined field_0x38e;
    undefined field_0x38f;
    undefined field_0x390;
    undefined field_0x391;
    undefined field_0x392;
    undefined field_0x393;
    undefined field_0x394;
    undefined field_0x395;
    undefined field_0x396;
    undefined field_0x397;
    undefined field_0x398;
    undefined field_0x399;
    undefined field_0x39a;
    undefined field_0x39b;
    undefined field_0x39c;
    undefined field_0x39d;
    undefined field_0x39e;
    undefined field_0x39f;
    undefined field_0x3a0;
    undefined field_0x3a1;
    undefined field_0x3a2;
    undefined field_0x3a3;
    undefined field_0x3a4;
    undefined field_0x3a5;
    undefined field_0x3a6;
    undefined field_0x3a7;
    undefined field_0x3a8;
    undefined field_0x3a9;
    undefined field_0x3aa;
    undefined field_0x3ab;
    undefined field_0x3ac;
    undefined field_0x3ad;
    undefined field_0x3ae;
    undefined field_0x3af;
    undefined field_0x3b0;
    undefined field_0x3b1;
    undefined field_0x3b2;
    undefined field_0x3b3;
    undefined field_0x3b4;
    undefined field_0x3b5;
    undefined field_0x3b6;
    undefined field_0x3b7;
    undefined field_0x3b8;
    undefined field_0x3b9;
    undefined field_0x3ba;
    undefined field_0x3bb;
    undefined field_0x3bc;
    undefined field_0x3bd;
    undefined field_0x3be;
    undefined field_0x3bf;
    undefined field_0x3c0;
    undefined field_0x3c1;
    undefined field_0x3c2;
    undefined field_0x3c3;
    undefined field_0x3c4;
    undefined field_0x3c5;
    undefined field_0x3c6;
    undefined field_0x3c7;
    undefined field_0x3c8;
    undefined field_0x3c9;
    undefined field_0x3ca;
    undefined field_0x3cb;
    undefined field_0x3cc;
    undefined field_0x3cd;
    undefined field_0x3ce;
    undefined field_0x3cf;
    undefined field_0x3d0;
    undefined field_0x3d1;
    undefined field_0x3d2;
    undefined field_0x3d3;
    undefined field_0x3d4;
    undefined field_0x3d5;
    undefined field_0x3d6;
    undefined field_0x3d7;
    undefined field_0x3d8;
    undefined field_0x3d9;
    undefined field_0x3da;
    undefined field_0x3db;
    undefined field_0x3dc;
    undefined field_0x3dd;
    undefined field_0x3de;
    undefined field_0x3df;
    undefined field_0x3e0;
    undefined field_0x3e1;
    undefined field_0x3e2;
    undefined field_0x3e3;
    undefined field_0x3e4;
    undefined field_0x3e5;
    undefined field_0x3e6;
    undefined field_0x3e7;
    undefined field_0x3e8;
    undefined field_0x3e9;
    undefined field_0x3ea;
    undefined field_0x3eb;
    undefined field_0x3ec;
    undefined field_0x3ed;
    undefined field_0x3ee;
    undefined field_0x3ef;
    undefined field_0x3f0;
    undefined field_0x3f1;
    undefined field_0x3f2;
    undefined field_0x3f3;
    undefined field_0x3f4;
    undefined field_0x3f5;
    undefined field_0x3f6;
    undefined field_0x3f7;
    undefined field_0x3f8;
    undefined field_0x3f9;
    undefined field_0x3fa;
    undefined field_0x3fb;
    undefined field_0x3fc;
    undefined field_0x3fd;
    undefined field_0x3fe;
    undefined field_0x3ff;
    uint RAM0_RAMDATA;
    uint RAM1_RAMDATA;
    uint RAM2_RAMDATA;
    uint RAM3_RAMDATA;
    uint RAM4_RAMDATA;
    uint RAM5_RAMDATA;
    uint RAM6_RAMDATA;
    uint RAM7_RAMDATA;
    uint RAM8_RAMDATA;
    uint RAM9_RAMDATA;
    uint RAM10_RAMDATA;
    uint RAM11_RAMDATA;
    uint RAM12_RAMDATA;
    uint RAM13_RAMDATA;
    uint RAM14_RAMDATA;
    uint RAM15_RAMDATA;
    uint RAM16_RAMDATA;
    uint RAM17_RAMDATA;
    uint RAM18_RAMDATA;
    uint RAM19_RAMDATA;
    uint RAM20_RAMDATA;
    uint RAM21_RAMDATA;
    uint RAM22_RAMDATA;
    uint RAM23_RAMDATA;
    uint RAM24_RAMDATA;
    uint RAM25_RAMDATA;
    uint RAM26_RAMDATA;
    uint RAM27_RAMDATA;
    uint RAM28_RAMDATA;
    uint RAM29_RAMDATA;
    uint RAM30_RAMDATA;
    uint RAM31_RAMDATA;
    uint RAM32_RAMDATA;
    uint RAM33_RAMDATA;
    uint RAM34_RAMDATA;
    uint RAM35_RAMDATA;
    uint RAM36_RAMDATA;
    uint RAM37_RAMDATA;
    uint RAM38_RAMDATA;
    uint RAM39_RAMDATA;
    uint RAM40_RAMDATA;
    uint RAM41_RAMDATA;
    uint RAM42_RAMDATA;
    uint RAM43_RAMDATA;
    uint RAM44_RAMDATA;
    uint RAM45_RAMDATA;
    uint RAM46_RAMDATA;
    uint RAM47_RAMDATA;
    uint RAM48_RAMDATA;
    uint RAM49_RAMDATA;
    uint RAM50_RAMDATA;
    uint RAM51_RAMDATA;
    uint RAM52_RAMDATA;
    uint RAM53_RAMDATA;
    uint RAM54_RAMDATA;
    uint RAM55_RAMDATA;
    uint RAM56_RAMDATA;
    uint RAM57_RAMDATA;
    uint RAM58_RAMDATA;
    uint RAM59_RAMDATA;
    uint RAM60_RAMDATA;
    uint RAM61_RAMDATA;
    uint RAM62_RAMDATA;
    uint RAM63_RAMDATA;
    uint RAM64_RAMDATA;
    uint RAM65_RAMDATA;
    uint RAM66_RAMDATA;
    uint RAM67_RAMDATA;
    uint RAM68_RAMDATA;
    uint RAM69_RAMDATA;
    uint RAM70_RAMDATA;
    uint RAM71_RAMDATA;
    uint RAM72_RAMDATA;
    uint RAM73_RAMDATA;
    uint RAM74_RAMDATA;
    uint RAM75_RAMDATA;
    uint RAM76_RAMDATA;
    uint RAM77_RAMDATA;
    uint RAM78_RAMDATA;
    uint RAM79_RAMDATA;
    uint RAM80_RAMDATA;
    uint RAM81_RAMDATA;
    uint RAM82_RAMDATA;
    uint RAM83_RAMDATA;
    uint RAM84_RAMDATA;
    uint RAM85_RAMDATA;
    uint RAM86_RAMDATA;
    uint RAM87_RAMDATA;
    uint RAM88_RAMDATA;
    uint RAM89_RAMDATA;
    uint RAM90_RAMDATA;
    uint RAM91_RAMDATA;
    uint RAM92_RAMDATA;
    uint RAM93_RAMDATA;
    uint RAM94_RAMDATA;
    uint RAM95_RAMDATA;
    uint RAM96_RAMDATA;
    uint RAM97_RAMDATA;
    uint RAM98_RAMDATA;
    uint RAM99_RAMDATA;
    uint RAM100_RAMDATA;
    uint RAM101_RAMDATA;
    uint RAM102_RAMDATA;
    uint RAM103_RAMDATA;
    uint RAM104_RAMDATA;
    uint RAM105_RAMDATA;
    uint RAM106_RAMDATA;
    uint RAM107_RAMDATA;
    uint RAM108_RAMDATA;
    uint RAM109_RAMDATA;
    uint RAM110_RAMDATA;
    uint RAM111_RAMDATA;
    uint RAM112_RAMDATA;
    uint RAM113_RAMDATA;
    uint RAM114_RAMDATA;
    uint RAM115_RAMDATA;
    uint RAM116_RAMDATA;
    uint RAM117_RAMDATA;
    uint RAM118_RAMDATA;
    uint RAM119_RAMDATA;
    uint RAM120_RAMDATA;
    uint RAM121_RAMDATA;
    uint RAM122_RAMDATA;
    uint RAM123_RAMDATA;
    uint RAM124_RAMDATA;
    uint RAM125_RAMDATA;
    uint RAM126_RAMDATA;
    uint RAM127_RAMDATA;
    uint RAM128_RAMDATA;
    uint RAM129_RAMDATA;
    uint RAM130_RAMDATA;
    uint RAM131_RAMDATA;
    uint RAM132_RAMDATA;
    uint RAM133_RAMDATA;
    uint RAM134_RAMDATA;
    uint RAM135_RAMDATA;
    uint RAM136_RAMDATA;
    uint RAM137_RAMDATA;
    uint RAM138_RAMDATA;
    uint RAM139_RAMDATA;
    uint RAM140_RAMDATA;
    uint RAM141_RAMDATA;
    uint RAM142_RAMDATA;
    uint RAM143_RAMDATA;
    uint RAM144_RAMDATA;
    uint RAM145_RAMDATA;
    uint RAM146_RAMDATA;
    uint RAM147_RAMDATA;
    uint RAM148_RAMDATA;
    uint RAM149_RAMDATA;
    uint RAM150_RAMDATA;
    uint RAM151_RAMDATA;
    uint RAM152_RAMDATA;
    uint RAM153_RAMDATA;
    uint RAM154_RAMDATA;
    uint RAM155_RAMDATA;
    uint RAM156_RAMDATA;
    uint RAM157_RAMDATA;
    uint RAM158_RAMDATA;
    uint RAM159_RAMDATA;
    uint RAM160_RAMDATA;
    uint RAM161_RAMDATA;
    uint RAM162_RAMDATA;
    uint RAM163_RAMDATA;
    uint RAM164_RAMDATA;
    uint RAM165_RAMDATA;
    uint RAM166_RAMDATA;
    uint RAM167_RAMDATA;
    uint RAM168_RAMDATA;
    uint RAM169_RAMDATA;
    uint RAM170_RAMDATA;
    uint RAM171_RAMDATA;
    uint RAM172_RAMDATA;
    uint RAM173_RAMDATA;
    uint RAM174_RAMDATA;
    uint RAM175_RAMDATA;
    uint RAM176_RAMDATA;
    uint RAM177_RAMDATA;
    uint RAM178_RAMDATA;
    uint RAM179_RAMDATA;
    uint RAM180_RAMDATA;
    uint RAM181_RAMDATA;
    uint RAM182_RAMDATA;
    uint RAM183_RAMDATA;
    uint RAM184_RAMDATA;
    uint RAM185_RAMDATA;
    uint RAM186_RAMDATA;
    uint RAM187_RAMDATA;
    uint RAM188_RAMDATA;
    uint RAM189_RAMDATA;
    uint RAM190_RAMDATA;
    uint RAM191_RAMDATA;
    uint RAM192_RAMDATA;
    uint RAM193_RAMDATA;
    uint RAM194_RAMDATA;
    uint RAM195_RAMDATA;
    uint RAM196_RAMDATA;
    uint RAM197_RAMDATA;
    uint RAM198_RAMDATA;
    uint RAM199_RAMDATA;
    uint RAM200_RAMDATA;
    uint RAM201_RAMDATA;
    uint RAM202_RAMDATA;
    uint RAM203_RAMDATA;
    uint RAM204_RAMDATA;
    uint RAM205_RAMDATA;
    uint RAM206_RAMDATA;
    uint RAM207_RAMDATA;
    uint RAM208_RAMDATA;
    uint RAM209_RAMDATA;
    uint RAM210_RAMDATA;
    uint RAM211_RAMDATA;
    uint RAM212_RAMDATA;
    uint RAM213_RAMDATA;
    uint RAM214_RAMDATA;
    uint RAM215_RAMDATA;
    uint RAM216_RAMDATA;
    uint RAM217_RAMDATA;
    uint RAM218_RAMDATA;
    uint RAM219_RAMDATA;
    uint RAM220_RAMDATA;
    uint RAM221_RAMDATA;
    uint RAM222_RAMDATA;
    uint RAM223_RAMDATA;
    uint RAM224_RAMDATA;
    uint RAM225_RAMDATA;
    uint RAM226_RAMDATA;
    uint RAM227_RAMDATA;
    uint RAM228_RAMDATA;
    uint RAM229_RAMDATA;
    uint RAM230_RAMDATA;
    uint RAM231_RAMDATA;
    uint RAM232_RAMDATA;
    uint RAM233_RAMDATA;
    uint RAM234_RAMDATA;
    uint RAM235_RAMDATA;
    uint RAM236_RAMDATA;
    uint RAM237_RAMDATA;
    uint RAM238_RAMDATA;
    uint RAM239_RAMDATA;
    uint RAM240_RAMDATA;
    uint RAM241_RAMDATA;
    uint RAM242_RAMDATA;
    uint RAM243_RAMDATA;
    uint RAM244_RAMDATA;
    uint RAM245_RAMDATA;
    uint RAM246_RAMDATA;
    uint RAM247_RAMDATA;
    uint RAM248_RAMDATA;
    uint RAM249_RAMDATA;
    uint RAM250_RAMDATA;
    uint RAM251_RAMDATA;
    uint RAM252_RAMDATA;
    uint RAM253_RAMDATA;
    uint RAM254_RAMDATA;
    uint RAM255_RAMDATA;
};

typedef struct I2C0 I2C0, *PI2C0;

struct I2C0 {
    uint CTRL; // Control Register
    uint CMD; // Command Register
    uint STATE; // State Register
    uint STATUS; // Status Register
    uint CLKDIV; // Clock Division Register
    uint SADDR; // Slave Address Register
    uint SADDRMASK; // Slave Address Mask Register
    uint RXDATA; // Receive Buffer Data Register
    uint RXDOUBLE; // Receive Buffer Double Data Register
    uint RXDATAP; // Receive Buffer Data Peek Register
    uint RXDOUBLEP; // Receive Buffer Double Data Peek Register
    uint TXDATA; // Transmit Buffer Data Register
    uint TXDOUBLE; // Transmit Buffer Double Data Register
    uint IF; // Interrupt Flag Register
    uint IFS; // Interrupt Flag Set Register
    uint IFC; // Interrupt Flag Clear Register
    uint IEN; // Interrupt Enable Register
    uint ROUTEPEN; // I/O Routing Pin Enable Register
    uint ROUTELOC0; // I/O Routing Location Register
};

typedef struct ACMP0 ACMP0, *PACMP0;

struct ACMP0 {
    uint CTRL; // Control Register
    uint INPUTSEL; // Input Selection Register
    uint STATUS; // Status Register
    uint IF; // Interrupt Flag Register
    uint IFS; // Interrupt Flag Set Register
    uint IFC; // Interrupt Flag Clear Register
    uint IEN; // Interrupt Enable Register
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    uint APORTREQ; // APORT Request Status Register
    uint APORTCONFLICT; // APORT Conflict Status Register
    uint HYSTERESIS0; // Hysteresis 0 Register
    uint HYSTERESIS1; // Hysteresis 1 Register
    undefined field_0x30;
    undefined field_0x31;
    undefined field_0x32;
    undefined field_0x33;
    undefined field_0x34;
    undefined field_0x35;
    undefined field_0x36;
    undefined field_0x37;
    undefined field_0x38;
    undefined field_0x39;
    undefined field_0x3a;
    undefined field_0x3b;
    undefined field_0x3c;
    undefined field_0x3d;
    undefined field_0x3e;
    undefined field_0x3f;
    uint ROUTEPEN; // I/O Routing Pine Enable Register
    uint ROUTELOC0; // I/O Routing Location Register
};

typedef struct RAC_CLR RAC_CLR, *PRAC_CLR;

struct RAC_CLR {
    uint RXENSRCEN;
    uint STATUS;
    uint CMD;
    uint CTRL;
    uint FORCESTATE;
    uint IF;
    uint IFS;
    uint IFC;
    uint IEN;
    uint LVDSCTRL;
    uint LVDSIDLESEQ;
    uint LVDSROUTE;
    uint HFXORETIMECTRL;
    uint HFXORETIMESTATUS;
    uint TESTCTRL;
    uint SEQSTATUS;
    uint SEQCMD;
    uint BREAKPOINT;
    uint R0;
    uint R1;
    uint R2;
    uint R3;
    uint R4;
    uint R5;
    uint R6;
    uint R7;
    undefined field_0x68;
    undefined field_0x69;
    undefined field_0x6a;
    undefined field_0x6b;
    uint WAITMASK;
    uint WAITSNSH;
    uint STIMER;
    uint STIMERCOMP;
    uint VECTADDR;
    uint SEQCTRL;
    uint PRESC;
    uint SR0;
    uint SR1;
    uint SR2;
    uint SR3;
    uint SYNTHENCTRL;
    uint SYNTHREGCTRL;
    uint VCOCTRL;
    uint MMDCTRL;
    undefined field_0xa8;
    undefined field_0xa9;
    undefined field_0xaa;
    undefined field_0xab;
    undefined field_0xac;
    undefined field_0xad;
    undefined field_0xae;
    undefined field_0xaf;
    uint CHPCTRL;
    uint CHPCAL;
    uint LPFCTRL;
    uint SYNTHCTRL;
    uint AUXCTRL;
    uint AUXENCTRL;
    undefined field_0xc8;
    undefined field_0xc9;
    undefined field_0xca;
    undefined field_0xcb;
    undefined field_0xcc;
    undefined field_0xcd;
    undefined field_0xce;
    undefined field_0xcf;
    undefined field_0xd0;
    undefined field_0xd1;
    undefined field_0xd2;
    undefined field_0xd3;
    undefined field_0xd4;
    undefined field_0xd5;
    undefined field_0xd6;
    undefined field_0xd7;
    undefined field_0xd8;
    undefined field_0xd9;
    undefined field_0xda;
    undefined field_0xdb;
    undefined field_0xdc;
    undefined field_0xdd;
    undefined field_0xde;
    undefined field_0xdf;
    undefined field_0xe0;
    undefined field_0xe1;
    undefined field_0xe2;
    undefined field_0xe3;
    undefined field_0xe4;
    undefined field_0xe5;
    undefined field_0xe6;
    undefined field_0xe7;
    undefined field_0xe8;
    undefined field_0xe9;
    undefined field_0xea;
    undefined field_0xeb;
    undefined field_0xec;
    undefined field_0xed;
    undefined field_0xee;
    undefined field_0xef;
    undefined field_0xf0;
    undefined field_0xf1;
    undefined field_0xf2;
    undefined field_0xf3;
    uint RFENCTRL;
    uint RFENCTRL0;
    uint LNAMIXCTRL;
    uint PACTRL0;
    uint PAPKDCTRL;
    uint PABIASCTRL0;
    uint PABIASCTRL1;
    uint SGRFENCTRL0;
    uint SGLNAMIXCTRL;
    uint SGPACTRL0;
    uint SGPAPKDCTRL;
    uint SGPABIASCTRL0;
    uint SGPABIASCTRL1;
    uint RFSTATUS;
    uint RFBIASCTRL;
    uint RFBIASCAL;
    uint LNAMIXCTRL1;
    uint IFPGACTRL;
    uint IFPGACAL;
    uint IFFILTCTRL;
    uint IFADCCTRL;
    uint IFADCCAL;
    uint PAENCTRL;
    uint PACTUNECTRL;
    uint RCTUNE;
    uint APC;
    uint SPARE;
};

typedef struct CRC_SET CRC_SET, *PCRC_SET;

struct CRC_SET {
    uint CTRL;
    uint STATUS;
    uint CMD;
    uint INPUTDATA;
    uint INIT;
    uint DATA;
    uint POLY;
};

typedef struct RFSENSE RFSENSE, *PRFSENSE;

struct RFSENSE {
    uint CTRL;
    uint PERIODSEL;
    uint CNT;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    uint EM4WUEN;
    uint CALIB;
    uint IF;
    uint IFS;
    uint IFC;
    uint IEN;
};

typedef struct SEQ SEQ, *PSEQ;

struct SEQ {
    uint REG000;
    uint REG004;
    uint REG008;
    uint REG00C;
    uint REG010;
    uint REG014;
    uint REG018;
    uint REG01C;
    uint REG020;
    uint REG024;
    uint REG028;
    uint REG02C;
    uint REG030;
    uint REG034;
    uint REG038;
    uint REG03C;
    uint REG040;
    uint REG044;
    uint REG048;
    uint REG04C;
    uint REG050;
    uint REG054;
    uint REG058;
    uint REG05C;
    uint REG060;
    uint REG064;
    uint REG068;
    uint REG06C;
    uint REG070;
    uint REG074;
    uint REG078;
    uint REG07C;
    uint REG080;
    uint REG084;
    uint REG088;
    uint REG08C;
    uint REG090;
    uint REG094;
    uint REG098;
    uint REG09C;
    uint REG0A0;
    uint REG0A4;
    uint REG0A8;
    uint REG0AC;
    uint REG0B0;
    uint REG0B4;
    uint REG0B8;
    uint REG0BC;
    uint REG0C0;
    uint REG0C4;
    uint REG0C8;
    uint REG0CC;
    uint REG0D0;
    uint REG0D4;
    uint REG0D8;
    uint REG0DC;
    uint REG0E0;
    uint REG0E4;
    uint REG0E8;
    uint DYNAMIC_CHPWR_TABLE;
    uint PHYINFO;
    uint MISC;
    uint SYNTHLPFCTRLRX;
    uint SYNTHLPFCTRLTX;
};

typedef struct ACMP1 ACMP1, *PACMP1;

struct ACMP1 {
    uint CTRL; // Control Register
    uint INPUTSEL; // Input Selection Register
    uint STATUS; // Status Register
    uint IF; // Interrupt Flag Register
    uint IFS; // Interrupt Flag Set Register
    uint IFC; // Interrupt Flag Clear Register
    uint IEN; // Interrupt Enable Register
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    uint APORTREQ; // APORT Request Status Register
    uint APORTCONFLICT; // APORT Conflict Status Register
    uint HYSTERESIS0; // Hysteresis 0 Register
    uint HYSTERESIS1; // Hysteresis 1 Register
    undefined field_0x30;
    undefined field_0x31;
    undefined field_0x32;
    undefined field_0x33;
    undefined field_0x34;
    undefined field_0x35;
    undefined field_0x36;
    undefined field_0x37;
    undefined field_0x38;
    undefined field_0x39;
    undefined field_0x3a;
    undefined field_0x3b;
    undefined field_0x3c;
    undefined field_0x3d;
    undefined field_0x3e;
    undefined field_0x3f;
    uint ROUTEPEN; // I/O Routing Pine Enable Register
    uint ROUTELOC0; // I/O Routing Location Register
};

typedef struct CRYPTO CRYPTO, *PCRYPTO;

struct CRYPTO {
    uint CTRL; // Control Register
    uint WAC; // Wide Arithmetic Configuration
    uint CMD; // Command Register
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    uint STATUS; // Status Register
    uint DSTATUS; // Data Status Register
    uint CSTATUS; // Control Status Register
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    uint KEY; // KEY Register Access
    uint KEYBUF; // KEY Buffer Register Access
    undefined field_0x28;
    undefined field_0x29;
    undefined field_0x2a;
    undefined field_0x2b;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    uint SEQCTRL; // Sequence Control
    uint SEQCTRLB; // Sequence Control B
    undefined field_0x38;
    undefined field_0x39;
    undefined field_0x3a;
    undefined field_0x3b;
    undefined field_0x3c;
    undefined field_0x3d;
    undefined field_0x3e;
    undefined field_0x3f;
    uint IF; // AES Interrupt Flags
    uint IFS; // Interrupt Flag Set Register
    uint IFC; // Interrupt Flag Clear Register
    uint IEN; // Interrupt Enable Register
    uint SEQ0; // Sequence Register 0
    uint SEQ1; // Sequence Register 1
    uint SEQ2; // Sequence Register 2
    uint SEQ3; // Sequence Register 3
    uint SEQ4; // Sequence Register 4
    undefined field_0x64;
    undefined field_0x65;
    undefined field_0x66;
    undefined field_0x67;
    undefined field_0x68;
    undefined field_0x69;
    undefined field_0x6a;
    undefined field_0x6b;
    undefined field_0x6c;
    undefined field_0x6d;
    undefined field_0x6e;
    undefined field_0x6f;
    undefined field_0x70;
    undefined field_0x71;
    undefined field_0x72;
    undefined field_0x73;
    undefined field_0x74;
    undefined field_0x75;
    undefined field_0x76;
    undefined field_0x77;
    undefined field_0x78;
    undefined field_0x79;
    undefined field_0x7a;
    undefined field_0x7b;
    undefined field_0x7c;
    undefined field_0x7d;
    undefined field_0x7e;
    undefined field_0x7f;
    uint DATA0; // DATA0 Register Access
    uint DATA1; // DATA1 Register Access
    uint DATA2; // DATA2 Register Access
    uint DATA3; // DATA3 Register Access
    undefined field_0x90;
    undefined field_0x91;
    undefined field_0x92;
    undefined field_0x93;
    undefined field_0x94;
    undefined field_0x95;
    undefined field_0x96;
    undefined field_0x97;
    undefined field_0x98;
    undefined field_0x99;
    undefined field_0x9a;
    undefined field_0x9b;
    undefined field_0x9c;
    undefined field_0x9d;
    undefined field_0x9e;
    undefined field_0x9f;
    uint DATA0XOR; // DATA0XOR Register Access
    undefined field_0xa4;
    undefined field_0xa5;
    undefined field_0xa6;
    undefined field_0xa7;
    undefined field_0xa8;
    undefined field_0xa9;
    undefined field_0xaa;
    undefined field_0xab;
    undefined field_0xac;
    undefined field_0xad;
    undefined field_0xae;
    undefined field_0xaf;
    uint DATA0BYTE; // DATA0 Register Byte Access
    uint DATA1BYTE; // DATA1 Register Byte Access
    undefined field_0xb8;
    undefined field_0xb9;
    undefined field_0xba;
    undefined field_0xbb;
    uint DATA0XORBYTE; // DATA0 Register Byte XOR Access
    uint DATA0BYTE12; // DATA0 Register Byte 12 Access
    uint DATA0BYTE13; // DATA0 Register Byte 13 Access
    uint DATA0BYTE14; // DATA0 Register Byte 14 Access
    uint DATA0BYTE15; // DATA0 Register Byte 15 Access
    undefined field_0xd0;
    undefined field_0xd1;
    undefined field_0xd2;
    undefined field_0xd3;
    undefined field_0xd4;
    undefined field_0xd5;
    undefined field_0xd6;
    undefined field_0xd7;
    undefined field_0xd8;
    undefined field_0xd9;
    undefined field_0xda;
    undefined field_0xdb;
    undefined field_0xdc;
    undefined field_0xdd;
    undefined field_0xde;
    undefined field_0xdf;
    undefined field_0xe0;
    undefined field_0xe1;
    undefined field_0xe2;
    undefined field_0xe3;
    undefined field_0xe4;
    undefined field_0xe5;
    undefined field_0xe6;
    undefined field_0xe7;
    undefined field_0xe8;
    undefined field_0xe9;
    undefined field_0xea;
    undefined field_0xeb;
    undefined field_0xec;
    undefined field_0xed;
    undefined field_0xee;
    undefined field_0xef;
    undefined field_0xf0;
    undefined field_0xf1;
    undefined field_0xf2;
    undefined field_0xf3;
    undefined field_0xf4;
    undefined field_0xf5;
    undefined field_0xf6;
    undefined field_0xf7;
    undefined field_0xf8;
    undefined field_0xf9;
    undefined field_0xfa;
    undefined field_0xfb;
    undefined field_0xfc;
    undefined field_0xfd;
    undefined field_0xfe;
    undefined field_0xff;
    uint DDATA0; // DDATA0 Register Access
    uint DDATA1; // DDATA1 Register Access
    uint DDATA2; // DDATA2 Register Access
    uint DDATA3; // DDATA3 Register Access
    uint DDATA4; // DDATA4 Register Access
    undefined field_0x114;
    undefined field_0x115;
    undefined field_0x116;
    undefined field_0x117;
    undefined field_0x118;
    undefined field_0x119;
    undefined field_0x11a;
    undefined field_0x11b;
    undefined field_0x11c;
    undefined field_0x11d;
    undefined field_0x11e;
    undefined field_0x11f;
    undefined field_0x120;
    undefined field_0x121;
    undefined field_0x122;
    undefined field_0x123;
    undefined field_0x124;
    undefined field_0x125;
    undefined field_0x126;
    undefined field_0x127;
    undefined field_0x128;
    undefined field_0x129;
    undefined field_0x12a;
    undefined field_0x12b;
    undefined field_0x12c;
    undefined field_0x12d;
    undefined field_0x12e;
    undefined field_0x12f;
    uint DDATA0BIG; // DDATA0 Register Big Endian Access
    undefined field_0x134;
    undefined field_0x135;
    undefined field_0x136;
    undefined field_0x137;
    undefined field_0x138;
    undefined field_0x139;
    undefined field_0x13a;
    undefined field_0x13b;
    undefined field_0x13c;
    undefined field_0x13d;
    undefined field_0x13e;
    undefined field_0x13f;
    uint DDATA0BYTE; // DDATA0 Register Byte Access
    uint DDATA1BYTE; // DDATA1 Register Byte Access
    uint DDATA0BYTE32; // DDATA0 Register Byte 32 Access
    undefined field_0x14c;
    undefined field_0x14d;
    undefined field_0x14e;
    undefined field_0x14f;
    undefined field_0x150;
    undefined field_0x151;
    undefined field_0x152;
    undefined field_0x153;
    undefined field_0x154;
    undefined field_0x155;
    undefined field_0x156;
    undefined field_0x157;
    undefined field_0x158;
    undefined field_0x159;
    undefined field_0x15a;
    undefined field_0x15b;
    undefined field_0x15c;
    undefined field_0x15d;
    undefined field_0x15e;
    undefined field_0x15f;
    undefined field_0x160;
    undefined field_0x161;
    undefined field_0x162;
    undefined field_0x163;
    undefined field_0x164;
    undefined field_0x165;
    undefined field_0x166;
    undefined field_0x167;
    undefined field_0x168;
    undefined field_0x169;
    undefined field_0x16a;
    undefined field_0x16b;
    undefined field_0x16c;
    undefined field_0x16d;
    undefined field_0x16e;
    undefined field_0x16f;
    undefined field_0x170;
    undefined field_0x171;
    undefined field_0x172;
    undefined field_0x173;
    undefined field_0x174;
    undefined field_0x175;
    undefined field_0x176;
    undefined field_0x177;
    undefined field_0x178;
    undefined field_0x179;
    undefined field_0x17a;
    undefined field_0x17b;
    undefined field_0x17c;
    undefined field_0x17d;
    undefined field_0x17e;
    undefined field_0x17f;
    uint QDATA0; // QDATA0 Register Access
    uint QDATA1; // QDATA1 Register Access
    undefined field_0x188;
    undefined field_0x189;
    undefined field_0x18a;
    undefined field_0x18b;
    undefined field_0x18c;
    undefined field_0x18d;
    undefined field_0x18e;
    undefined field_0x18f;
    undefined field_0x190;
    undefined field_0x191;
    undefined field_0x192;
    undefined field_0x193;
    undefined field_0x194;
    undefined field_0x195;
    undefined field_0x196;
    undefined field_0x197;
    undefined field_0x198;
    undefined field_0x199;
    undefined field_0x19a;
    undefined field_0x19b;
    undefined field_0x19c;
    undefined field_0x19d;
    undefined field_0x19e;
    undefined field_0x19f;
    undefined field_0x1a0;
    undefined field_0x1a1;
    undefined field_0x1a2;
    undefined field_0x1a3;
    uint QDATA1BIG; // QDATA1 Register Big Endian Access
    undefined field_0x1a8;
    undefined field_0x1a9;
    undefined field_0x1aa;
    undefined field_0x1ab;
    undefined field_0x1ac;
    undefined field_0x1ad;
    undefined field_0x1ae;
    undefined field_0x1af;
    undefined field_0x1b0;
    undefined field_0x1b1;
    undefined field_0x1b2;
    undefined field_0x1b3;
    undefined field_0x1b4;
    undefined field_0x1b5;
    undefined field_0x1b6;
    undefined field_0x1b7;
    undefined field_0x1b8;
    undefined field_0x1b9;
    undefined field_0x1ba;
    undefined field_0x1bb;
    undefined field_0x1bc;
    undefined field_0x1bd;
    undefined field_0x1be;
    undefined field_0x1bf;
    uint QDATA0BYTE; // QDATA0 Register Byte Access
    uint QDATA1BYTE; // QDATA1 Register Byte Access
};

typedef struct FRC_SET FRC_SET, *PFRC_SET;

struct FRC_SET {
    uint STATUS;
    uint DFLCTRL;
    uint MAXLENGTH;
    uint ADDRFILTCTRL;
    uint DATABUFFER;
    uint WCNT;
    uint WCNTCMP0;
    uint WCNTCMP1;
    uint WCNTCMP2;
    uint CMD;
    uint WHITECTRL;
    uint WHITEPOLY;
    uint WHITEINIT;
    uint FECCTRL;
    uint BLOCKRAMADDR;
    uint CONVRAMADDR;
    uint CTRL;
    uint RXCTRL;
    uint TRAILTXDATACTRL;
    uint TRAILRXDATA;
    uint SCNT;
    uint CONVGENERATOR;
    uint PUNCTCTRL;
    uint PAUSECTRL;
    uint IF;
    uint IFS;
    uint IFC;
    uint IEN;
    uint BUFFERMODE;
    uint ROUTEPEN;
    uint ROUTELOC0;
    uint SNIFFCTRL;
    uint AUXDATA;
    uint RAWCTRL;
    uint RXRAWDATA;
    uint PAUSEDATA;
    uint LIKELYCONVSTATE;
    uint INTELEMENTNEXT;
    uint INTWRITEPOINT;
    uint INTREADPOINT;
    uint FCD0;
    uint FCD1;
    uint FCD2;
    uint FCD3;
    undefined field_0xb0;
    undefined field_0xb1;
    undefined field_0xb2;
    undefined field_0xb3;
    undefined field_0xb4;
    undefined field_0xb5;
    undefined field_0xb6;
    undefined field_0xb7;
    undefined field_0xb8;
    undefined field_0xb9;
    undefined field_0xba;
    undefined field_0xbb;
    undefined field_0xbc;
    undefined field_0xbd;
    undefined field_0xbe;
    undefined field_0xbf;
    uint INTELEMENT0;
    uint INTELEMENT1;
    uint INTELEMENT2;
    uint INTELEMENT3;
    uint INTELEMENT4;
    uint INTELEMENT5;
    uint INTELEMENT6;
    uint INTELEMENT7;
    uint INTELEMENT8;
    uint INTELEMENT9;
    uint INTELEMENT10;
    uint INTELEMENT11;
    uint INTELEMENT12;
    uint INTELEMENT13;
    uint INTELEMENT14;
    uint INTELEMENT15;
};

typedef struct PROTIMER_CLR PROTIMER_CLR, *PPROTIMER_CLR;

struct PROTIMER_CLR {
    uint CTRL;
    uint CMD;
    uint PRSCTRL;
    uint STATUS;
    uint PRECNT;
    uint BASECNT;
    uint WRAPCNT;
    uint BASEPRE;
    uint LWRAPCNT;
    uint PRECNTTOPADJ;
    uint PRECNTTOP;
    uint BASECNTTOP;
    uint WRAPCNTTOP;
    uint TOUT0CNT;
    uint TOUT0CNTTOP;
    uint TOUT0COMP;
    uint TOUT1CNT;
    uint TOUT1CNTTOP;
    uint TOUT1COMP;
    uint LBTCTRL;
    uint LBTPRSCTRL;
    uint LBTSTATE;
    uint RANDOM;
    uint IF;
    uint IFS;
    uint IFC;
    uint IEN;
    uint RXCTRL;
    uint TXCTRL;
    uint CC0_CTRL;
    uint CC0_PRE;
    uint CC0_BASE;
    uint CC0_WRAP;
    uint CC1_CTRL;
    uint CC1_PRE;
    uint CC1_BASE;
    uint CC1_WRAP;
    uint CC2_CTRL;
    uint CC2_PRE;
    uint CC2_BASE;
    uint CC2_WRAP;
    uint CC3_CTRL;
    uint CC3_PRE;
    uint CC3_BASE;
    uint CC3_WRAP;
    uint CC4_CTRL;
    uint CC4_PRE;
    uint CC4_BASE;
    uint CC4_WRAP;
};

typedef struct BUFC BUFC, *PBUFC;

struct BUFC {
    uint BUF0_CTRL;
    uint BUF0_ADDR;
    uint BUF0_WRITEOFFSET;
    uint BUF0_READOFFSET;
    uint BUF0_WRITESTART;
    uint BUF0_READDATA;
    uint BUF0_WRITEDATA;
    uint BUF0_XWRITE;
    uint BUF0_STATUS;
    uint BUF0_THRESHOLDCTRL;
    uint BUF0_CMD;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    uint BUF1_CTRL;
    uint BUF1_ADDR;
    uint BUF1_WRITEOFFSET;
    uint BUF1_READOFFSET;
    uint BUF1_WRITESTART;
    uint BUF1_READDATA;
    uint BUF1_WRITEDATA;
    uint BUF1_XWRITE;
    uint BUF1_STATUS;
    uint BUF1_THRESHOLDCTRL;
    uint BUF1_CMD;
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    uint BUF2_CTRL;
    uint BUF2_ADDR;
    uint BUF2_WRITEOFFSET;
    uint BUF2_READOFFSET;
    uint BUF2_WRITESTART;
    uint BUF2_READDATA;
    uint BUF2_WRITEDATA;
    uint BUF2_XWRITE;
    uint BUF2_STATUS;
    uint BUF2_THRESHOLDCTR;
    uint BUF2_CMD;
    undefined field_0x8c;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
    uint BUF3_CTRL;
    uint BUF3_ADDR;
    uint BUF3_WRITEOFFSET;
    uint BUF3_READOFFSET;
    uint BUF3_WRITESTART;
    uint BUF3_READDATA;
    uint BUF3_WRITEDATA;
    uint BUF3_XWRITE;
    uint BUF3_STATUS;
    uint BUF3_THRESHOLDCTRL;
    uint BUF3_CMD;
    undefined field_0xbc;
    undefined field_0xbd;
    undefined field_0xbe;
    undefined field_0xbf;
    undefined field_0xc0;
    undefined field_0xc1;
    undefined field_0xc2;
    undefined field_0xc3;
    undefined field_0xc4;
    undefined field_0xc5;
    undefined field_0xc6;
    undefined field_0xc7;
    undefined field_0xc8;
    undefined field_0xc9;
    undefined field_0xca;
    undefined field_0xcb;
    undefined field_0xcc;
    undefined field_0xcd;
    undefined field_0xce;
    undefined field_0xcf;
    undefined field_0xd0;
    undefined field_0xd1;
    undefined field_0xd2;
    undefined field_0xd3;
    undefined field_0xd4;
    undefined field_0xd5;
    undefined field_0xd6;
    undefined field_0xd7;
    undefined field_0xd8;
    undefined field_0xd9;
    undefined field_0xda;
    undefined field_0xdb;
    undefined field_0xdc;
    undefined field_0xdd;
    undefined field_0xde;
    undefined field_0xdf;
    uint IF;
    uint IFS;
    uint IFC;
    uint IEN;
};

typedef struct USART1 USART1, *PUSART1;

struct USART1 {
    uint CTRL; // Control Register
    uint FRAME; // USART Frame Format Register
    uint TRIGCTRL; // USART Trigger Control Register
    uint CMD; // Command Register
    uint STATUS; // USART Status Register
    uint CLKDIV; // Clock Control Register
    uint RXDATAX; // RX Buffer Data Extended Register
    uint RXDATA; // RX Buffer Data Register
    uint RXDOUBLEX; // RX Buffer Double Data Extended Register
    uint RXDOUBLE; // RX FIFO Double Data Register
    uint RXDATAXP; // RX Buffer Data Extended Peek Register
    uint RXDOUBLEXP; // RX Buffer Double Data Extended Peek Register
    uint TXDATAX; // TX Buffer Data Extended Register
    uint TXDATA; // TX Buffer Data Register
    uint TXDOUBLEX; // TX Buffer Double Data Extended Register
    uint TXDOUBLE; // TX Buffer Double Data Register
    uint IF; // Interrupt Flag Register
    uint IFS; // Interrupt Flag Set Register
    uint IFC; // Interrupt Flag Clear Register
    uint IEN; // Interrupt Enable Register
    uint IRCTRL; // IrDA Control Register
    undefined field_0x54;
    undefined field_0x55;
    undefined field_0x56;
    undefined field_0x57;
    uint INPUT; // USART Input Register
    uint I2SCTRL; // I2S Control Register
    uint TIMING; // Timing Register
    uint CTRLX; // Control Register Extended
    uint TIMECMP0; // Used to Generate Interrupts and Various Delays
    uint TIMECMP1; // Used to Generate Interrupts and Various Delays
    uint TIMECMP2; // Used to Generate Interrupts and Various Delays
    uint ROUTEPEN; // I/O Routing Pin Enable Register
    uint ROUTELOC0; // I/O Routing Location Register
    uint ROUTELOC1; // I/O Routing Location Register
};

typedef struct PCNT0 PCNT0, *PPCNT0;

struct PCNT0 {
    uint CTRL; // Control Register
    uint CMD; // Command Register
    uint STATUS; // Status Register
    uint CNT; // Counter Value Register
    uint TOP; // Top Value Register
    uint TOPB; // Top Value Buffer Register
    uint IF; // Interrupt Flag Register
    uint IFS; // Interrupt Flag Set Register
    uint IFC; // Interrupt Flag Clear Register
    uint IEN; // Interrupt Enable Register
    undefined field_0x28;
    undefined field_0x29;
    undefined field_0x2a;
    undefined field_0x2b;
    uint ROUTELOC0; // I/O Routing Location Register
    undefined field_0x30;
    undefined field_0x31;
    undefined field_0x32;
    undefined field_0x33;
    undefined field_0x34;
    undefined field_0x35;
    undefined field_0x36;
    undefined field_0x37;
    undefined field_0x38;
    undefined field_0x39;
    undefined field_0x3a;
    undefined field_0x3b;
    undefined field_0x3c;
    undefined field_0x3d;
    undefined field_0x3e;
    undefined field_0x3f;
    uint FREEZE; // Freeze Register
    uint SYNCBUSY; // Synchronization Busy Register
    undefined field_0x48;
    undefined field_0x49;
    undefined field_0x4a;
    undefined field_0x4b;
    undefined field_0x4c;
    undefined field_0x4d;
    undefined field_0x4e;
    undefined field_0x4f;
    undefined field_0x50;
    undefined field_0x51;
    undefined field_0x52;
    undefined field_0x53;
    undefined field_0x54;
    undefined field_0x55;
    undefined field_0x56;
    undefined field_0x57;
    undefined field_0x58;
    undefined field_0x59;
    undefined field_0x5a;
    undefined field_0x5b;
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    undefined field_0x60;
    undefined field_0x61;
    undefined field_0x62;
    undefined field_0x63;
    uint AUXCNT; // Auxiliary Counter Value Register
    uint INPUT; // PCNT Input Register
    uint OVSCFG; // Oversampling Config Register
};

typedef struct TIMER1 TIMER1, *PTIMER1;

struct TIMER1 {
    uint CTRL; // Control Register
    uint CMD; // Command Register
    uint STATUS; // Status Register
    uint IF; // Interrupt Flag Register
    uint IFS; // Interrupt Flag Set Register
    uint IFC; // Interrupt Flag Clear Register
    uint IEN; // Interrupt Enable Register
    uint TOP; // Counter Top Value Register
    uint TOPB; // Counter Top Value Buffer Register
    uint CNT; // Counter Value Register
    undefined field_0x28;
    undefined field_0x29;
    undefined field_0x2a;
    undefined field_0x2b;
    uint LOCK; // TIMER Configuration Lock Register
    uint ROUTEPEN; // I/O Routing Pin Enable Register
    uint ROUTELOC0; // I/O Routing Location Register
    undefined field_0x38;
    undefined field_0x39;
    undefined field_0x3a;
    undefined field_0x3b;
    uint ROUTELOC2; // I/O Routing Location Register
    undefined field_0x40;
    undefined field_0x41;
    undefined field_0x42;
    undefined field_0x43;
    undefined field_0x44;
    undefined field_0x45;
    undefined field_0x46;
    undefined field_0x47;
    undefined field_0x48;
    undefined field_0x49;
    undefined field_0x4a;
    undefined field_0x4b;
    undefined field_0x4c;
    undefined field_0x4d;
    undefined field_0x4e;
    undefined field_0x4f;
    undefined field_0x50;
    undefined field_0x51;
    undefined field_0x52;
    undefined field_0x53;
    undefined field_0x54;
    undefined field_0x55;
    undefined field_0x56;
    undefined field_0x57;
    undefined field_0x58;
    undefined field_0x59;
    undefined field_0x5a;
    undefined field_0x5b;
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    uint CC0_CTRL; // CC Channel Control Register
    uint CC0_CCV; // CC Channel Value Register
    uint CC0_CCVP; // CC Channel Value Peek Register
    uint CC0_CCVB; // CC Channel Buffer Register
    uint CC1_CTRL; // CC Channel Control Register
    uint CC1_CCV; // CC Channel Value Register
    uint CC1_CCVP; // CC Channel Value Peek Register
    uint CC1_CCVB; // CC Channel Buffer Register
    uint CC2_CTRL; // CC Channel Control Register
    uint CC2_CCV; // CC Channel Value Register
    uint CC2_CCVP; // CC Channel Value Peek Register
    uint CC2_CCVB; // CC Channel Buffer Register
    uint CC3_CTRL; // CC Channel Control Register
    uint CC3_CCV; // CC Channel Value Register
    uint CC3_CCVP; // CC Channel Value Peek Register
    uint CC3_CCVB; // CC Channel Buffer Register
    uint DTCTRL; // DTI Control Register
    uint DTTIME; // DTI Time Control Register
    uint DTFC; // DTI Fault Configuration Register
    uint DTOGEN; // DTI Output Generation Enable Register
    uint DTFAULT; // DTI Fault Register
    uint DTFAULTC; // DTI Fault Clear Register
    uint DTLOCK; // DTI Configuration Lock Register
};

typedef struct TIMER0 TIMER0, *PTIMER0;

struct TIMER0 {
    uint CTRL; // Control Register
    uint CMD; // Command Register
    uint STATUS; // Status Register
    uint IF; // Interrupt Flag Register
    uint IFS; // Interrupt Flag Set Register
    uint IFC; // Interrupt Flag Clear Register
    uint IEN; // Interrupt Enable Register
    uint TOP; // Counter Top Value Register
    uint TOPB; // Counter Top Value Buffer Register
    uint CNT; // Counter Value Register
    undefined field_0x28;
    undefined field_0x29;
    undefined field_0x2a;
    undefined field_0x2b;
    uint LOCK; // TIMER Configuration Lock Register
    uint ROUTEPEN; // I/O Routing Pin Enable Register
    uint ROUTELOC0; // I/O Routing Location Register
    undefined field_0x38;
    undefined field_0x39;
    undefined field_0x3a;
    undefined field_0x3b;
    uint ROUTELOC2; // I/O Routing Location Register
    undefined field_0x40;
    undefined field_0x41;
    undefined field_0x42;
    undefined field_0x43;
    undefined field_0x44;
    undefined field_0x45;
    undefined field_0x46;
    undefined field_0x47;
    undefined field_0x48;
    undefined field_0x49;
    undefined field_0x4a;
    undefined field_0x4b;
    undefined field_0x4c;
    undefined field_0x4d;
    undefined field_0x4e;
    undefined field_0x4f;
    undefined field_0x50;
    undefined field_0x51;
    undefined field_0x52;
    undefined field_0x53;
    undefined field_0x54;
    undefined field_0x55;
    undefined field_0x56;
    undefined field_0x57;
    undefined field_0x58;
    undefined field_0x59;
    undefined field_0x5a;
    undefined field_0x5b;
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    uint CC0_CTRL; // CC Channel Control Register
    uint CC0_CCV; // CC Channel Value Register
    uint CC0_CCVP; // CC Channel Value Peek Register
    uint CC0_CCVB; // CC Channel Buffer Register
    uint CC1_CTRL; // CC Channel Control Register
    uint CC1_CCV; // CC Channel Value Register
    uint CC1_CCVP; // CC Channel Value Peek Register
    uint CC1_CCVB; // CC Channel Buffer Register
    uint CC2_CTRL; // CC Channel Control Register
    uint CC2_CCV; // CC Channel Value Register
    uint CC2_CCVP; // CC Channel Value Peek Register
    uint CC2_CCVB; // CC Channel Buffer Register
    uint CC3_CTRL; // CC Channel Control Register
    uint CC3_CCV; // CC Channel Value Register
    uint CC3_CCVP; // CC Channel Value Peek Register
    uint CC3_CCVB; // CC Channel Buffer Register
    uint DTCTRL; // DTI Control Register
    uint DTTIME; // DTI Time Control Register
    uint DTFC; // DTI Fault Configuration Register
    uint DTOGEN; // DTI Output Generation Enable Register
    uint DTFAULT; // DTI Fault Register
    uint DTFAULTC; // DTI Fault Clear Register
    uint DTLOCK; // DTI Configuration Lock Register
};

typedef struct BUFC_CLR BUFC_CLR, *PBUFC_CLR;

struct BUFC_CLR {
    uint BUF0_CTRL;
    uint BUF0_ADDR;
    uint BUF0_WRITEOFFSET;
    uint BUF0_READOFFSET;
    uint BUF0_WRITESTART;
    uint BUF0_READDATA;
    uint BUF0_WRITEDATA;
    uint BUF0_XWRITE;
    uint BUF0_STATUS;
    uint BUF0_THRESHOLDCTRL;
    uint BUF0_CMD;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    uint BUF1_CTRL;
    uint BUF1_ADDR;
    uint BUF1_WRITEOFFSET;
    uint BUF1_READOFFSET;
    uint BUF1_WRITESTART;
    uint BUF1_READDATA;
    uint BUF1_WRITEDATA;
    uint BUF1_XWRITE;
    uint BUF1_STATUS;
    uint BUF1_THRESHOLDCTRL;
    uint BUF1_CMD;
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    uint BUF2_CTRL;
    uint BUF2_ADDR;
    uint BUF2_WRITEOFFSET;
    uint BUF2_READOFFSET;
    uint BUF2_WRITESTART;
    uint BUF2_READDATA;
    uint BUF2_WRITEDATA;
    uint BUF2_XWRITE;
    uint BUF2_STATUS;
    uint BUF2_THRESHOLDCTR;
    uint BUF2_CMD;
    undefined field_0x8c;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
    uint BUF3_CTRL;
    uint BUF3_ADDR;
    uint BUF3_WRITEOFFSET;
    uint BUF3_READOFFSET;
    uint BUF3_WRITESTART;
    uint BUF3_READDATA;
    uint BUF3_WRITEDATA;
    uint BUF3_XWRITE;
    uint BUF3_STATUS;
    uint BUF3_THRESHOLDCTRL;
    uint BUF3_CMD;
    undefined field_0xbc;
    undefined field_0xbd;
    undefined field_0xbe;
    undefined field_0xbf;
    undefined field_0xc0;
    undefined field_0xc1;
    undefined field_0xc2;
    undefined field_0xc3;
    undefined field_0xc4;
    undefined field_0xc5;
    undefined field_0xc6;
    undefined field_0xc7;
    undefined field_0xc8;
    undefined field_0xc9;
    undefined field_0xca;
    undefined field_0xcb;
    undefined field_0xcc;
    undefined field_0xcd;
    undefined field_0xce;
    undefined field_0xcf;
    undefined field_0xd0;
    undefined field_0xd1;
    undefined field_0xd2;
    undefined field_0xd3;
    undefined field_0xd4;
    undefined field_0xd5;
    undefined field_0xd6;
    undefined field_0xd7;
    undefined field_0xd8;
    undefined field_0xd9;
    undefined field_0xda;
    undefined field_0xdb;
    undefined field_0xdc;
    undefined field_0xdd;
    undefined field_0xde;
    undefined field_0xdf;
    uint IF;
    uint IFS;
    uint IFC;
    uint IEN;
};

typedef struct USART0 USART0, *PUSART0;

struct USART0 {
    uint CTRL; // Control Register
    uint FRAME; // USART Frame Format Register
    uint TRIGCTRL; // USART Trigger Control Register
    uint CMD; // Command Register
    uint STATUS; // USART Status Register
    uint CLKDIV; // Clock Control Register
    uint RXDATAX; // RX Buffer Data Extended Register
    uint RXDATA; // RX Buffer Data Register
    uint RXDOUBLEX; // RX Buffer Double Data Extended Register
    uint RXDOUBLE; // RX FIFO Double Data Register
    uint RXDATAXP; // RX Buffer Data Extended Peek Register
    uint RXDOUBLEXP; // RX Buffer Double Data Extended Peek Register
    uint TXDATAX; // TX Buffer Data Extended Register
    uint TXDATA; // TX Buffer Data Register
    uint TXDOUBLEX; // TX Buffer Double Data Extended Register
    uint TXDOUBLE; // TX Buffer Double Data Register
    uint IF; // Interrupt Flag Register
    uint IFS; // Interrupt Flag Set Register
    uint IFC; // Interrupt Flag Clear Register
    uint IEN; // Interrupt Enable Register
    uint IRCTRL; // IrDA Control Register
    undefined field_0x54;
    undefined field_0x55;
    undefined field_0x56;
    undefined field_0x57;
    uint INPUT; // USART Input Register
    uint I2SCTRL; // I2S Control Register
    uint TIMING; // Timing Register
    uint CTRLX; // Control Register Extended
    uint TIMECMP0; // Used to Generate Interrupts and Various Delays
    uint TIMECMP1; // Used to Generate Interrupts and Various Delays
    uint TIMECMP2; // Used to Generate Interrupts and Various Delays
    uint ROUTEPEN; // I/O Routing Pin Enable Register
    uint ROUTELOC0; // I/O Routing Location Register
    uint ROUTELOC1; // I/O Routing Location Register
};

typedef struct MSC MSC, *PMSC;

struct MSC {
    uint CTRL; // Memory System Control Register
    uint READCTRL; // Read Control Register
    uint WRITECTRL; // Write Control Register
    uint WRITECMD; // Write Command Register
    uint ADDRB; // Page Erase/Write Address Buffer
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    uint WDATA; // Write Data Register
    uint STATUS; // Status Register
    undefined field_0x20;
    undefined field_0x21;
    undefined field_0x22;
    undefined field_0x23;
    undefined field_0x24;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
    undefined field_0x28;
    undefined field_0x29;
    undefined field_0x2a;
    undefined field_0x2b;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    uint IF; // Interrupt Flag Register
    uint IFS; // Interrupt Flag Set Register
    uint IFC; // Interrupt Flag Clear Register
    uint IEN; // Interrupt Enable Register
    uint LOCK; // Configuration Lock Register
    uint CACHECMD; // Flash Cache Command Register
    uint CACHEHITS; // Cache Hits Performance Counter
    uint CACHEMISSES; // Cache Misses Performance Counter
    undefined field_0x50;
    undefined field_0x51;
    undefined field_0x52;
    undefined field_0x53;
    uint MASSLOCK; // Mass Erase Lock Register
    undefined field_0x58;
    undefined field_0x59;
    undefined field_0x5a;
    undefined field_0x5b;
    uint STARTUP; // Startup Control
    undefined field_0x60;
    undefined field_0x61;
    undefined field_0x62;
    undefined field_0x63;
    undefined field_0x64;
    undefined field_0x65;
    undefined field_0x66;
    undefined field_0x67;
    undefined field_0x68;
    undefined field_0x69;
    undefined field_0x6a;
    undefined field_0x6b;
    undefined field_0x6c;
    undefined field_0x6d;
    undefined field_0x6e;
    undefined field_0x6f;
    undefined field_0x70;
    undefined field_0x71;
    undefined field_0x72;
    undefined field_0x73;
    uint CMD; // Command Register
};

typedef struct RFSENSE_CLR RFSENSE_CLR, *PRFSENSE_CLR;

struct RFSENSE_CLR {
    uint CTRL;
    uint PERIODSEL;
    uint CNT;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    uint EM4WUEN;
    uint CALIB;
    uint IF;
    uint IFS;
    uint IFC;
    uint IEN;
};

typedef struct AGC AGC, *PAGC;

struct AGC {
    uint STATUS0;
    uint STATUS1;
    uint RSSI;
    uint FRAMERSSI;
    undefined field_0x10;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    uint CTRL0;
    uint CTRL1;
    uint CTRL2;
    uint RSSISTEPTHR;
    uint IFPEAKDET;
    uint MANGAIN;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    uint IF;
    uint IFS;
    uint IFC;
    uint IEN;
    uint CMD;
    undefined field_0x44;
    undefined field_0x45;
    undefined field_0x46;
    undefined field_0x47;
    uint GAINRANGE;
    uint GAININDEX;
    uint SLICECODE;
    uint ATTENCODE1;
    uint ATTENCODE2;
    uint ATTENCODE3;
    uint GAINERROR1;
    uint GAINERROR2;
    uint GAINERROR3;
    uint MANUALCTRL;
    uint GAINSTEPLIM;
    uint LOOPDEL;
    uint MININDEX;
};

typedef struct AGC_CLR AGC_CLR, *PAGC_CLR;

struct AGC_CLR {
    uint STATUS0;
    uint STATUS1;
    uint RSSI;
    uint FRAMERSSI;
    undefined field_0x10;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    uint CTRL0;
    uint CTRL1;
    uint CTRL2;
    uint RSSISTEPTHR;
    uint IFPEAKDET;
    uint MANGAIN;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    uint IF;
    uint IFS;
    uint IFC;
    uint IEN;
    uint CMD;
    undefined field_0x44;
    undefined field_0x45;
    undefined field_0x46;
    undefined field_0x47;
    uint GAINRANGE;
    uint GAININDEX;
    uint SLICECODE;
    uint ATTENCODE1;
    uint ATTENCODE2;
    uint ATTENCODE3;
    uint GAINERROR1;
    uint GAINERROR2;
    uint GAINERROR3;
    uint MANUALCTRL;
    uint GAINSTEPLIM;
    uint LOOPDEL;
    uint MININDEX;
};

typedef struct DEVINFO DEVINFO, *PDEVINFO;

struct DEVINFO {
    uint CAL;
    uint MODULEINFO;
    uint MODXOCAL;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    undefined field_0x10;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    undefined field_0x18;
    undefined field_0x19;
    undefined field_0x1a;
    undefined field_0x1b;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    uint EXTINFO;
    undefined field_0x24;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
    uint EUI48L;
    uint EUI48H;
    uint CUSTOMINFO;
    uint MEMINFO;
    undefined field_0x38;
    undefined field_0x39;
    undefined field_0x3a;
    undefined field_0x3b;
    undefined field_0x3c;
    undefined field_0x3d;
    undefined field_0x3e;
    undefined field_0x3f;
    uint UNIQUEL;
    uint UNIQUEH;
    uint MSIZE;
    uint PART;
    uint DEVINFOREV;
    uint EMUTEMP;
    undefined field_0x58;
    undefined field_0x59;
    undefined field_0x5a;
    undefined field_0x5b;
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    uint ADC0CAL0;
    uint ADC0CAL1;
    uint ADC0CAL2;
    uint ADC0CAL3;
    undefined field_0x70;
    undefined field_0x71;
    undefined field_0x72;
    undefined field_0x73;
    undefined field_0x74;
    undefined field_0x75;
    undefined field_0x76;
    undefined field_0x77;
    undefined field_0x78;
    undefined field_0x79;
    undefined field_0x7a;
    undefined field_0x7b;
    undefined field_0x7c;
    undefined field_0x7d;
    undefined field_0x7e;
    undefined field_0x7f;
    uint HFRCOCAL0;
    undefined field_0x84;
    undefined field_0x85;
    undefined field_0x86;
    undefined field_0x87;
    undefined field_0x88;
    undefined field_0x89;
    undefined field_0x8a;
    undefined field_0x8b;
    uint HFRCOCAL3;
    undefined field_0x90;
    undefined field_0x91;
    undefined field_0x92;
    undefined field_0x93;
    undefined field_0x94;
    undefined field_0x95;
    undefined field_0x96;
    undefined field_0x97;
    uint HFRCOCAL6;
    uint HFRCOCAL7;
    uint HFRCOCAL8;
    undefined field_0xa4;
    undefined field_0xa5;
    undefined field_0xa6;
    undefined field_0xa7;
    uint HFRCOCAL10;
    uint HFRCOCAL11;
    uint HFRCOCAL12;
    undefined field_0xb4;
    undefined field_0xb5;
    undefined field_0xb6;
    undefined field_0xb7;
    undefined field_0xb8;
    undefined field_0xb9;
    undefined field_0xba;
    undefined field_0xbb;
    undefined field_0xbc;
    undefined field_0xbd;
    undefined field_0xbe;
    undefined field_0xbf;
    undefined field_0xc0;
    undefined field_0xc1;
    undefined field_0xc2;
    undefined field_0xc3;
    undefined field_0xc4;
    undefined field_0xc5;
    undefined field_0xc6;
    undefined field_0xc7;
    undefined field_0xc8;
    undefined field_0xc9;
    undefined field_0xca;
    undefined field_0xcb;
    undefined field_0xcc;
    undefined field_0xcd;
    undefined field_0xce;
    undefined field_0xcf;
    undefined field_0xd0;
    undefined field_0xd1;
    undefined field_0xd2;
    undefined field_0xd3;
    undefined field_0xd4;
    undefined field_0xd5;
    undefined field_0xd6;
    undefined field_0xd7;
    undefined field_0xd8;
    undefined field_0xd9;
    undefined field_0xda;
    undefined field_0xdb;
    undefined field_0xdc;
    undefined field_0xdd;
    undefined field_0xde;
    undefined field_0xdf;
    uint AUXHFRCOCAL0;
    undefined field_0xe4;
    undefined field_0xe5;
    undefined field_0xe6;
    undefined field_0xe7;
    undefined field_0xe8;
    undefined field_0xe9;
    undefined field_0xea;
    undefined field_0xeb;
    uint AUXHFRCOCAL3;
    undefined field_0xf0;
    undefined field_0xf1;
    undefined field_0xf2;
    undefined field_0xf3;
    undefined field_0xf4;
    undefined field_0xf5;
    undefined field_0xf6;
    undefined field_0xf7;
    uint AUXHFRCOCAL6;
    uint AUXHFRCOCAL7;
    uint AUXHFRCOCAL8;
    undefined field_0x104;
    undefined field_0x105;
    undefined field_0x106;
    undefined field_0x107;
    uint AUXHFRCOCAL10;
    uint AUXHFRCOCAL11;
    uint AUXHFRCOCAL12;
    undefined field_0x114;
    undefined field_0x115;
    undefined field_0x116;
    undefined field_0x117;
    undefined field_0x118;
    undefined field_0x119;
    undefined field_0x11a;
    undefined field_0x11b;
    undefined field_0x11c;
    undefined field_0x11d;
    undefined field_0x11e;
    undefined field_0x11f;
    undefined field_0x120;
    undefined field_0x121;
    undefined field_0x122;
    undefined field_0x123;
    undefined field_0x124;
    undefined field_0x125;
    undefined field_0x126;
    undefined field_0x127;
    undefined field_0x128;
    undefined field_0x129;
    undefined field_0x12a;
    undefined field_0x12b;
    undefined field_0x12c;
    undefined field_0x12d;
    undefined field_0x12e;
    undefined field_0x12f;
    undefined field_0x130;
    undefined field_0x131;
    undefined field_0x132;
    undefined field_0x133;
    undefined field_0x134;
    undefined field_0x135;
    undefined field_0x136;
    undefined field_0x137;
    undefined field_0x138;
    undefined field_0x139;
    undefined field_0x13a;
    undefined field_0x13b;
    undefined field_0x13c;
    undefined field_0x13d;
    undefined field_0x13e;
    undefined field_0x13f;
    uint VMONCAL0;
    uint VMONCAL1;
    uint VMONCAL2;
    undefined field_0x14c;
    undefined field_0x14d;
    undefined field_0x14e;
    undefined field_0x14f;
    undefined field_0x150;
    undefined field_0x151;
    undefined field_0x152;
    undefined field_0x153;
    undefined field_0x154;
    undefined field_0x155;
    undefined field_0x156;
    undefined field_0x157;
    uint IDAC0CAL0;
    uint IDAC0CAL1;
    undefined field_0x160;
    undefined field_0x161;
    undefined field_0x162;
    undefined field_0x163;
    undefined field_0x164;
    undefined field_0x165;
    undefined field_0x166;
    undefined field_0x167;
    uint DCDCLNVCTRL0;
    uint DCDCLPVCTRL0;
    uint DCDCLPVCTRL1;
    uint DCDCLPVCTRL2;
    uint DCDCLPVCTRL3;
    uint DCDCLPCMPHYSSEL0;
    uint DCDCLPCMPHYSSEL1;
};

typedef struct MODEM MODEM, *PMODEM;

struct MODEM {
    uint STATUS;
    uint TIMDETSTATUS;
    uint FREQOFFEST;
    uint AFCADJRX;
    uint AFCADJTX;
    uint MIXCTRL;
    uint CTRL0;
    uint CTRL1;
    uint CTRL2;
    uint CTRL3;
    uint CTRL4;
    uint CTRL5;
    uint TXBR;
    uint RXBR;
    uint CF;
    uint PRE;
    uint SYNC0;
    uint SYNC1;
    uint TIMING;
    uint DSSS0;
    uint MODINDEX;
    uint AFC;
    uint AFCADJLIM;
    uint SHAPING0;
    uint SHAPING1;
    uint SHAPING2;
    uint RAMPCTRL;
    uint RAMPLEV;
    uint ROUTEPEN;
    uint ROUTELOC0;
    uint ROUTELOC1;
    undefined field_0x7c;
    undefined field_0x7d;
    undefined field_0x7e;
    undefined field_0x7f;
    uint IF;
    uint IFS;
    uint IFC;
    uint IEN;
    uint CMD;
    undefined field_0x94;
    undefined field_0x95;
    undefined field_0x96;
    undefined field_0x97;
    uint DCCOMP;
    uint DCCOMPFILTINIT;
    undefined field_0xa0;
    undefined field_0xa1;
    undefined field_0xa2;
    undefined field_0xa3;
    undefined field_0xa4;
    undefined field_0xa5;
    undefined field_0xa6;
    undefined field_0xa7;
    undefined field_0xa8;
    undefined field_0xa9;
    undefined field_0xaa;
    undefined field_0xab;
    undefined field_0xac;
    undefined field_0xad;
    undefined field_0xae;
    undefined field_0xaf;
    undefined field_0xb0;
    undefined field_0xb1;
    undefined field_0xb2;
    undefined field_0xb3;
    undefined field_0xb4;
    undefined field_0xb5;
    undefined field_0xb6;
    undefined field_0xb7;
    undefined field_0xb8;
    undefined field_0xb9;
    undefined field_0xba;
    undefined field_0xbb;
    undefined field_0xbc;
    undefined field_0xbd;
    undefined field_0xbe;
    undefined field_0xbf;
    undefined field_0xc0;
    undefined field_0xc1;
    undefined field_0xc2;
    undefined field_0xc3;
    undefined field_0xc4;
    undefined field_0xc5;
    undefined field_0xc6;
    undefined field_0xc7;
    undefined field_0xc8;
    undefined field_0xc9;
    undefined field_0xca;
    undefined field_0xcb;
    undefined field_0xcc;
    undefined field_0xcd;
    undefined field_0xce;
    undefined field_0xcf;
    undefined field_0xd0;
    undefined field_0xd1;
    undefined field_0xd2;
    undefined field_0xd3;
    undefined field_0xd4;
    undefined field_0xd5;
    undefined field_0xd6;
    undefined field_0xd7;
    undefined field_0xd8;
    undefined field_0xd9;
    undefined field_0xda;
    undefined field_0xdb;
    undefined field_0xdc;
    undefined field_0xdd;
    undefined field_0xde;
    undefined field_0xdf;
    undefined field_0xe0;
    undefined field_0xe1;
    undefined field_0xe2;
    undefined field_0xe3;
    undefined field_0xe4;
    undefined field_0xe5;
    undefined field_0xe6;
    undefined field_0xe7;
    undefined field_0xe8;
    undefined field_0xe9;
    undefined field_0xea;
    undefined field_0xeb;
    undefined field_0xec;
    undefined field_0xed;
    undefined field_0xee;
    undefined field_0xef;
    undefined field_0xf0;
    undefined field_0xf1;
    undefined field_0xf2;
    undefined field_0xf3;
    undefined field_0xf4;
    undefined field_0xf5;
    undefined field_0xf6;
    undefined field_0xf7;
    undefined field_0xf8;
    undefined field_0xf9;
    undefined field_0xfa;
    undefined field_0xfb;
    undefined field_0xfc;
    undefined field_0xfd;
    undefined field_0xfe;
    undefined field_0xff;
    uint DCESTI;
    undefined field_0x104;
    undefined field_0x105;
    undefined field_0x106;
    undefined field_0x107;
    undefined field_0x108;
    undefined field_0x109;
    undefined field_0x10a;
    undefined field_0x10b;
    undefined field_0x10c;
    undefined field_0x10d;
    undefined field_0x10e;
    undefined field_0x10f;
    undefined field_0x110;
    undefined field_0x111;
    undefined field_0x112;
    undefined field_0x113;
    undefined field_0x114;
    undefined field_0x115;
    undefined field_0x116;
    undefined field_0x117;
    undefined field_0x118;
    undefined field_0x119;
    undefined field_0x11a;
    undefined field_0x11b;
    undefined field_0x11c;
    undefined field_0x11d;
    undefined field_0x11e;
    undefined field_0x11f;
    undefined field_0x120;
    undefined field_0x121;
    undefined field_0x122;
    undefined field_0x123;
    undefined field_0x124;
    undefined field_0x125;
    undefined field_0x126;
    undefined field_0x127;
    undefined field_0x128;
    undefined field_0x129;
    undefined field_0x12a;
    undefined field_0x12b;
    undefined field_0x12c;
    undefined field_0x12d;
    undefined field_0x12e;
    undefined field_0x12f;
    undefined field_0x130;
    undefined field_0x131;
    undefined field_0x132;
    undefined field_0x133;
    undefined field_0x134;
    undefined field_0x135;
    undefined field_0x136;
    undefined field_0x137;
    undefined field_0x138;
    undefined field_0x139;
    undefined field_0x13a;
    undefined field_0x13b;
    undefined field_0x13c;
    undefined field_0x13d;
    undefined field_0x13e;
    undefined field_0x13f;
    undefined field_0x140;
    undefined field_0x141;
    undefined field_0x142;
    undefined field_0x143;
    undefined field_0x144;
    undefined field_0x145;
    undefined field_0x146;
    undefined field_0x147;
    undefined field_0x148;
    undefined field_0x149;
    undefined field_0x14a;
    undefined field_0x14b;
    undefined field_0x14c;
    undefined field_0x14d;
    undefined field_0x14e;
    undefined field_0x14f;
    undefined field_0x150;
    undefined field_0x151;
    undefined field_0x152;
    undefined field_0x153;
    undefined field_0x154;
    undefined field_0x155;
    undefined field_0x156;
    undefined field_0x157;
    undefined field_0x158;
    undefined field_0x159;
    undefined field_0x15a;
    undefined field_0x15b;
    undefined field_0x15c;
    undefined field_0x15d;
    undefined field_0x15e;
    undefined field_0x15f;
    undefined field_0x160;
    undefined field_0x161;
    undefined field_0x162;
    undefined field_0x163;
    undefined field_0x164;
    undefined field_0x165;
    undefined field_0x166;
    undefined field_0x167;
    undefined field_0x168;
    undefined field_0x169;
    undefined field_0x16a;
    undefined field_0x16b;
    undefined field_0x16c;
    undefined field_0x16d;
    undefined field_0x16e;
    undefined field_0x16f;
    undefined field_0x170;
    undefined field_0x171;
    undefined field_0x172;
    undefined field_0x173;
    undefined field_0x174;
    undefined field_0x175;
    undefined field_0x176;
    undefined field_0x177;
    undefined field_0x178;
    undefined field_0x179;
    undefined field_0x17a;
    undefined field_0x17b;
    undefined field_0x17c;
    undefined field_0x17d;
    undefined field_0x17e;
    undefined field_0x17f;
    undefined field_0x180;
    undefined field_0x181;
    undefined field_0x182;
    undefined field_0x183;
    undefined field_0x184;
    undefined field_0x185;
    undefined field_0x186;
    undefined field_0x187;
    undefined field_0x188;
    undefined field_0x189;
    undefined field_0x18a;
    undefined field_0x18b;
    undefined field_0x18c;
    undefined field_0x18d;
    undefined field_0x18e;
    undefined field_0x18f;
    undefined field_0x190;
    undefined field_0x191;
    undefined field_0x192;
    undefined field_0x193;
    undefined field_0x194;
    undefined field_0x195;
    undefined field_0x196;
    undefined field_0x197;
    undefined field_0x198;
    undefined field_0x199;
    undefined field_0x19a;
    undefined field_0x19b;
    undefined field_0x19c;
    undefined field_0x19d;
    undefined field_0x19e;
    undefined field_0x19f;
    undefined field_0x1a0;
    undefined field_0x1a1;
    undefined field_0x1a2;
    undefined field_0x1a3;
    undefined field_0x1a4;
    undefined field_0x1a5;
    undefined field_0x1a6;
    undefined field_0x1a7;
    undefined field_0x1a8;
    undefined field_0x1a9;
    undefined field_0x1aa;
    undefined field_0x1ab;
    undefined field_0x1ac;
    undefined field_0x1ad;
    undefined field_0x1ae;
    undefined field_0x1af;
    undefined field_0x1b0;
    undefined field_0x1b1;
    undefined field_0x1b2;
    undefined field_0x1b3;
    undefined field_0x1b4;
    undefined field_0x1b5;
    undefined field_0x1b6;
    undefined field_0x1b7;
    undefined field_0x1b8;
    undefined field_0x1b9;
    undefined field_0x1ba;
    undefined field_0x1bb;
    undefined field_0x1bc;
    undefined field_0x1bd;
    undefined field_0x1be;
    undefined field_0x1bf;
    undefined field_0x1c0;
    undefined field_0x1c1;
    undefined field_0x1c2;
    undefined field_0x1c3;
    undefined field_0x1c4;
    undefined field_0x1c5;
    undefined field_0x1c6;
    undefined field_0x1c7;
    undefined field_0x1c8;
    undefined field_0x1c9;
    undefined field_0x1ca;
    undefined field_0x1cb;
    undefined field_0x1cc;
    undefined field_0x1cd;
    undefined field_0x1ce;
    undefined field_0x1cf;
    undefined field_0x1d0;
    undefined field_0x1d1;
    undefined field_0x1d2;
    undefined field_0x1d3;
    undefined field_0x1d4;
    undefined field_0x1d5;
    undefined field_0x1d6;
    undefined field_0x1d7;
    undefined field_0x1d8;
    undefined field_0x1d9;
    undefined field_0x1da;
    undefined field_0x1db;
    undefined field_0x1dc;
    undefined field_0x1dd;
    undefined field_0x1de;
    undefined field_0x1df;
    undefined field_0x1e0;
    undefined field_0x1e1;
    undefined field_0x1e2;
    undefined field_0x1e3;
    undefined field_0x1e4;
    undefined field_0x1e5;
    undefined field_0x1e6;
    undefined field_0x1e7;
    undefined field_0x1e8;
    undefined field_0x1e9;
    undefined field_0x1ea;
    undefined field_0x1eb;
    undefined field_0x1ec;
    undefined field_0x1ed;
    undefined field_0x1ee;
    undefined field_0x1ef;
    undefined field_0x1f0;
    undefined field_0x1f1;
    undefined field_0x1f2;
    undefined field_0x1f3;
    undefined field_0x1f4;
    undefined field_0x1f5;
    undefined field_0x1f6;
    undefined field_0x1f7;
    undefined field_0x1f8;
    undefined field_0x1f9;
    undefined field_0x1fa;
    undefined field_0x1fb;
    undefined field_0x1fc;
    undefined field_0x1fd;
    undefined field_0x1fe;
    undefined field_0x1ff;
    undefined field_0x200;
    undefined field_0x201;
    undefined field_0x202;
    undefined field_0x203;
    undefined field_0x204;
    undefined field_0x205;
    undefined field_0x206;
    undefined field_0x207;
    undefined field_0x208;
    undefined field_0x209;
    undefined field_0x20a;
    undefined field_0x20b;
    undefined field_0x20c;
    undefined field_0x20d;
    undefined field_0x20e;
    undefined field_0x20f;
    undefined field_0x210;
    undefined field_0x211;
    undefined field_0x212;
    undefined field_0x213;
    undefined field_0x214;
    undefined field_0x215;
    undefined field_0x216;
    undefined field_0x217;
    undefined field_0x218;
    undefined field_0x219;
    undefined field_0x21a;
    undefined field_0x21b;
    undefined field_0x21c;
    undefined field_0x21d;
    undefined field_0x21e;
    undefined field_0x21f;
    undefined field_0x220;
    undefined field_0x221;
    undefined field_0x222;
    undefined field_0x223;
    undefined field_0x224;
    undefined field_0x225;
    undefined field_0x226;
    undefined field_0x227;
    undefined field_0x228;
    undefined field_0x229;
    undefined field_0x22a;
    undefined field_0x22b;
    undefined field_0x22c;
    undefined field_0x22d;
    undefined field_0x22e;
    undefined field_0x22f;
    undefined field_0x230;
    undefined field_0x231;
    undefined field_0x232;
    undefined field_0x233;
    undefined field_0x234;
    undefined field_0x235;
    undefined field_0x236;
    undefined field_0x237;
    undefined field_0x238;
    undefined field_0x239;
    undefined field_0x23a;
    undefined field_0x23b;
    undefined field_0x23c;
    undefined field_0x23d;
    undefined field_0x23e;
    undefined field_0x23f;
    undefined field_0x240;
    undefined field_0x241;
    undefined field_0x242;
    undefined field_0x243;
    undefined field_0x244;
    undefined field_0x245;
    undefined field_0x246;
    undefined field_0x247;
    undefined field_0x248;
    undefined field_0x249;
    undefined field_0x24a;
    undefined field_0x24b;
    undefined field_0x24c;
    undefined field_0x24d;
    undefined field_0x24e;
    undefined field_0x24f;
    undefined field_0x250;
    undefined field_0x251;
    undefined field_0x252;
    undefined field_0x253;
    undefined field_0x254;
    undefined field_0x255;
    undefined field_0x256;
    undefined field_0x257;
    undefined field_0x258;
    undefined field_0x259;
    undefined field_0x25a;
    undefined field_0x25b;
    undefined field_0x25c;
    undefined field_0x25d;
    undefined field_0x25e;
    undefined field_0x25f;
    undefined field_0x260;
    undefined field_0x261;
    undefined field_0x262;
    undefined field_0x263;
    undefined field_0x264;
    undefined field_0x265;
    undefined field_0x266;
    undefined field_0x267;
    undefined field_0x268;
    undefined field_0x269;
    undefined field_0x26a;
    undefined field_0x26b;
    undefined field_0x26c;
    undefined field_0x26d;
    undefined field_0x26e;
    undefined field_0x26f;
    undefined field_0x270;
    undefined field_0x271;
    undefined field_0x272;
    undefined field_0x273;
    undefined field_0x274;
    undefined field_0x275;
    undefined field_0x276;
    undefined field_0x277;
    undefined field_0x278;
    undefined field_0x279;
    undefined field_0x27a;
    undefined field_0x27b;
    undefined field_0x27c;
    undefined field_0x27d;
    undefined field_0x27e;
    undefined field_0x27f;
    undefined field_0x280;
    undefined field_0x281;
    undefined field_0x282;
    undefined field_0x283;
    undefined field_0x284;
    undefined field_0x285;
    undefined field_0x286;
    undefined field_0x287;
    undefined field_0x288;
    undefined field_0x289;
    undefined field_0x28a;
    undefined field_0x28b;
    undefined field_0x28c;
    undefined field_0x28d;
    undefined field_0x28e;
    undefined field_0x28f;
    undefined field_0x290;
    undefined field_0x291;
    undefined field_0x292;
    undefined field_0x293;
    undefined field_0x294;
    undefined field_0x295;
    undefined field_0x296;
    undefined field_0x297;
    undefined field_0x298;
    undefined field_0x299;
    undefined field_0x29a;
    undefined field_0x29b;
    undefined field_0x29c;
    undefined field_0x29d;
    undefined field_0x29e;
    undefined field_0x29f;
    undefined field_0x2a0;
    undefined field_0x2a1;
    undefined field_0x2a2;
    undefined field_0x2a3;
    undefined field_0x2a4;
    undefined field_0x2a5;
    undefined field_0x2a6;
    undefined field_0x2a7;
    undefined field_0x2a8;
    undefined field_0x2a9;
    undefined field_0x2aa;
    undefined field_0x2ab;
    undefined field_0x2ac;
    undefined field_0x2ad;
    undefined field_0x2ae;
    undefined field_0x2af;
    undefined field_0x2b0;
    undefined field_0x2b1;
    undefined field_0x2b2;
    undefined field_0x2b3;
    undefined field_0x2b4;
    undefined field_0x2b5;
    undefined field_0x2b6;
    undefined field_0x2b7;
    undefined field_0x2b8;
    undefined field_0x2b9;
    undefined field_0x2ba;
    undefined field_0x2bb;
    undefined field_0x2bc;
    undefined field_0x2bd;
    undefined field_0x2be;
    undefined field_0x2bf;
    undefined field_0x2c0;
    undefined field_0x2c1;
    undefined field_0x2c2;
    undefined field_0x2c3;
    undefined field_0x2c4;
    undefined field_0x2c5;
    undefined field_0x2c6;
    undefined field_0x2c7;
    undefined field_0x2c8;
    undefined field_0x2c9;
    undefined field_0x2ca;
    undefined field_0x2cb;
    undefined field_0x2cc;
    undefined field_0x2cd;
    undefined field_0x2ce;
    undefined field_0x2cf;
    undefined field_0x2d0;
    undefined field_0x2d1;
    undefined field_0x2d2;
    undefined field_0x2d3;
    undefined field_0x2d4;
    undefined field_0x2d5;
    undefined field_0x2d6;
    undefined field_0x2d7;
    undefined field_0x2d8;
    undefined field_0x2d9;
    undefined field_0x2da;
    undefined field_0x2db;
    undefined field_0x2dc;
    undefined field_0x2dd;
    undefined field_0x2de;
    undefined field_0x2df;
    undefined field_0x2e0;
    undefined field_0x2e1;
    undefined field_0x2e2;
    undefined field_0x2e3;
    undefined field_0x2e4;
    undefined field_0x2e5;
    undefined field_0x2e6;
    undefined field_0x2e7;
    undefined field_0x2e8;
    undefined field_0x2e9;
    undefined field_0x2ea;
    undefined field_0x2eb;
    undefined field_0x2ec;
    undefined field_0x2ed;
    undefined field_0x2ee;
    undefined field_0x2ef;
    undefined field_0x2f0;
    undefined field_0x2f1;
    undefined field_0x2f2;
    undefined field_0x2f3;
    undefined field_0x2f4;
    undefined field_0x2f5;
    undefined field_0x2f6;
    undefined field_0x2f7;
    undefined field_0x2f8;
    undefined field_0x2f9;
    undefined field_0x2fa;
    undefined field_0x2fb;
    undefined field_0x2fc;
    undefined field_0x2fd;
    undefined field_0x2fe;
    undefined field_0x2ff;
    undefined field_0x300;
    undefined field_0x301;
    undefined field_0x302;
    undefined field_0x303;
    undefined field_0x304;
    undefined field_0x305;
    undefined field_0x306;
    undefined field_0x307;
    undefined field_0x308;
    undefined field_0x309;
    undefined field_0x30a;
    undefined field_0x30b;
    undefined field_0x30c;
    undefined field_0x30d;
    undefined field_0x30e;
    undefined field_0x30f;
    undefined field_0x310;
    undefined field_0x311;
    undefined field_0x312;
    undefined field_0x313;
    undefined field_0x314;
    undefined field_0x315;
    undefined field_0x316;
    undefined field_0x317;
    undefined field_0x318;
    undefined field_0x319;
    undefined field_0x31a;
    undefined field_0x31b;
    undefined field_0x31c;
    undefined field_0x31d;
    undefined field_0x31e;
    undefined field_0x31f;
    undefined field_0x320;
    undefined field_0x321;
    undefined field_0x322;
    undefined field_0x323;
    undefined field_0x324;
    undefined field_0x325;
    undefined field_0x326;
    undefined field_0x327;
    undefined field_0x328;
    undefined field_0x329;
    undefined field_0x32a;
    undefined field_0x32b;
    undefined field_0x32c;
    undefined field_0x32d;
    undefined field_0x32e;
    undefined field_0x32f;
    undefined field_0x330;
    undefined field_0x331;
    undefined field_0x332;
    undefined field_0x333;
    undefined field_0x334;
    undefined field_0x335;
    undefined field_0x336;
    undefined field_0x337;
    undefined field_0x338;
    undefined field_0x339;
    undefined field_0x33a;
    undefined field_0x33b;
    undefined field_0x33c;
    undefined field_0x33d;
    undefined field_0x33e;
    undefined field_0x33f;
    undefined field_0x340;
    undefined field_0x341;
    undefined field_0x342;
    undefined field_0x343;
    undefined field_0x344;
    undefined field_0x345;
    undefined field_0x346;
    undefined field_0x347;
    undefined field_0x348;
    undefined field_0x349;
    undefined field_0x34a;
    undefined field_0x34b;
    undefined field_0x34c;
    undefined field_0x34d;
    undefined field_0x34e;
    undefined field_0x34f;
    undefined field_0x350;
    undefined field_0x351;
    undefined field_0x352;
    undefined field_0x353;
    undefined field_0x354;
    undefined field_0x355;
    undefined field_0x356;
    undefined field_0x357;
    undefined field_0x358;
    undefined field_0x359;
    undefined field_0x35a;
    undefined field_0x35b;
    undefined field_0x35c;
    undefined field_0x35d;
    undefined field_0x35e;
    undefined field_0x35f;
    undefined field_0x360;
    undefined field_0x361;
    undefined field_0x362;
    undefined field_0x363;
    undefined field_0x364;
    undefined field_0x365;
    undefined field_0x366;
    undefined field_0x367;
    undefined field_0x368;
    undefined field_0x369;
    undefined field_0x36a;
    undefined field_0x36b;
    undefined field_0x36c;
    undefined field_0x36d;
    undefined field_0x36e;
    undefined field_0x36f;
    undefined field_0x370;
    undefined field_0x371;
    undefined field_0x372;
    undefined field_0x373;
    undefined field_0x374;
    undefined field_0x375;
    undefined field_0x376;
    undefined field_0x377;
    undefined field_0x378;
    undefined field_0x379;
    undefined field_0x37a;
    undefined field_0x37b;
    undefined field_0x37c;
    undefined field_0x37d;
    undefined field_0x37e;
    undefined field_0x37f;
    undefined field_0x380;
    undefined field_0x381;
    undefined field_0x382;
    undefined field_0x383;
    undefined field_0x384;
    undefined field_0x385;
    undefined field_0x386;
    undefined field_0x387;
    undefined field_0x388;
    undefined field_0x389;
    undefined field_0x38a;
    undefined field_0x38b;
    undefined field_0x38c;
    undefined field_0x38d;
    undefined field_0x38e;
    undefined field_0x38f;
    undefined field_0x390;
    undefined field_0x391;
    undefined field_0x392;
    undefined field_0x393;
    undefined field_0x394;
    undefined field_0x395;
    undefined field_0x396;
    undefined field_0x397;
    undefined field_0x398;
    undefined field_0x399;
    undefined field_0x39a;
    undefined field_0x39b;
    undefined field_0x39c;
    undefined field_0x39d;
    undefined field_0x39e;
    undefined field_0x39f;
    undefined field_0x3a0;
    undefined field_0x3a1;
    undefined field_0x3a2;
    undefined field_0x3a3;
    undefined field_0x3a4;
    undefined field_0x3a5;
    undefined field_0x3a6;
    undefined field_0x3a7;
    undefined field_0x3a8;
    undefined field_0x3a9;
    undefined field_0x3aa;
    undefined field_0x3ab;
    undefined field_0x3ac;
    undefined field_0x3ad;
    undefined field_0x3ae;
    undefined field_0x3af;
    undefined field_0x3b0;
    undefined field_0x3b1;
    undefined field_0x3b2;
    undefined field_0x3b3;
    undefined field_0x3b4;
    undefined field_0x3b5;
    undefined field_0x3b6;
    undefined field_0x3b7;
    undefined field_0x3b8;
    undefined field_0x3b9;
    undefined field_0x3ba;
    undefined field_0x3bb;
    undefined field_0x3bc;
    undefined field_0x3bd;
    undefined field_0x3be;
    undefined field_0x3bf;
    undefined field_0x3c0;
    undefined field_0x3c1;
    undefined field_0x3c2;
    undefined field_0x3c3;
    undefined field_0x3c4;
    undefined field_0x3c5;
    undefined field_0x3c6;
    undefined field_0x3c7;
    undefined field_0x3c8;
    undefined field_0x3c9;
    undefined field_0x3ca;
    undefined field_0x3cb;
    undefined field_0x3cc;
    undefined field_0x3cd;
    undefined field_0x3ce;
    undefined field_0x3cf;
    undefined field_0x3d0;
    undefined field_0x3d1;
    undefined field_0x3d2;
    undefined field_0x3d3;
    undefined field_0x3d4;
    undefined field_0x3d5;
    undefined field_0x3d6;
    undefined field_0x3d7;
    undefined field_0x3d8;
    undefined field_0x3d9;
    undefined field_0x3da;
    undefined field_0x3db;
    undefined field_0x3dc;
    undefined field_0x3dd;
    undefined field_0x3de;
    undefined field_0x3df;
    undefined field_0x3e0;
    undefined field_0x3e1;
    undefined field_0x3e2;
    undefined field_0x3e3;
    undefined field_0x3e4;
    undefined field_0x3e5;
    undefined field_0x3e6;
    undefined field_0x3e7;
    undefined field_0x3e8;
    undefined field_0x3e9;
    undefined field_0x3ea;
    undefined field_0x3eb;
    undefined field_0x3ec;
    undefined field_0x3ed;
    undefined field_0x3ee;
    undefined field_0x3ef;
    undefined field_0x3f0;
    undefined field_0x3f1;
    undefined field_0x3f2;
    undefined field_0x3f3;
    undefined field_0x3f4;
    undefined field_0x3f5;
    undefined field_0x3f6;
    undefined field_0x3f7;
    undefined field_0x3f8;
    undefined field_0x3f9;
    undefined field_0x3fa;
    undefined field_0x3fb;
    undefined field_0x3fc;
    undefined field_0x3fd;
    undefined field_0x3fe;
    undefined field_0x3ff;
    uint RAM0_RAMDATA;
    uint RAM1_RAMDATA;
    uint RAM2_RAMDATA;
    uint RAM3_RAMDATA;
    uint RAM4_RAMDATA;
    uint RAM5_RAMDATA;
    uint RAM6_RAMDATA;
    uint RAM7_RAMDATA;
    uint RAM8_RAMDATA;
    uint RAM9_RAMDATA;
    uint RAM10_RAMDATA;
    uint RAM11_RAMDATA;
    uint RAM12_RAMDATA;
    uint RAM13_RAMDATA;
    uint RAM14_RAMDATA;
    uint RAM15_RAMDATA;
    uint RAM16_RAMDATA;
    uint RAM17_RAMDATA;
    uint RAM18_RAMDATA;
    uint RAM19_RAMDATA;
    uint RAM20_RAMDATA;
    uint RAM21_RAMDATA;
    uint RAM22_RAMDATA;
    uint RAM23_RAMDATA;
    uint RAM24_RAMDATA;
    uint RAM25_RAMDATA;
    uint RAM26_RAMDATA;
    uint RAM27_RAMDATA;
    uint RAM28_RAMDATA;
    uint RAM29_RAMDATA;
    uint RAM30_RAMDATA;
    uint RAM31_RAMDATA;
    uint RAM32_RAMDATA;
    uint RAM33_RAMDATA;
    uint RAM34_RAMDATA;
    uint RAM35_RAMDATA;
    uint RAM36_RAMDATA;
    uint RAM37_RAMDATA;
    uint RAM38_RAMDATA;
    uint RAM39_RAMDATA;
    uint RAM40_RAMDATA;
    uint RAM41_RAMDATA;
    uint RAM42_RAMDATA;
    uint RAM43_RAMDATA;
    uint RAM44_RAMDATA;
    uint RAM45_RAMDATA;
    uint RAM46_RAMDATA;
    uint RAM47_RAMDATA;
    uint RAM48_RAMDATA;
    uint RAM49_RAMDATA;
    uint RAM50_RAMDATA;
    uint RAM51_RAMDATA;
    uint RAM52_RAMDATA;
    uint RAM53_RAMDATA;
    uint RAM54_RAMDATA;
    uint RAM55_RAMDATA;
    uint RAM56_RAMDATA;
    uint RAM57_RAMDATA;
    uint RAM58_RAMDATA;
    uint RAM59_RAMDATA;
    uint RAM60_RAMDATA;
    uint RAM61_RAMDATA;
    uint RAM62_RAMDATA;
    uint RAM63_RAMDATA;
    uint RAM64_RAMDATA;
    uint RAM65_RAMDATA;
    uint RAM66_RAMDATA;
    uint RAM67_RAMDATA;
    uint RAM68_RAMDATA;
    uint RAM69_RAMDATA;
    uint RAM70_RAMDATA;
    uint RAM71_RAMDATA;
    uint RAM72_RAMDATA;
    uint RAM73_RAMDATA;
    uint RAM74_RAMDATA;
    uint RAM75_RAMDATA;
    uint RAM76_RAMDATA;
    uint RAM77_RAMDATA;
    uint RAM78_RAMDATA;
    uint RAM79_RAMDATA;
    uint RAM80_RAMDATA;
    uint RAM81_RAMDATA;
    uint RAM82_RAMDATA;
    uint RAM83_RAMDATA;
    uint RAM84_RAMDATA;
    uint RAM85_RAMDATA;
    uint RAM86_RAMDATA;
    uint RAM87_RAMDATA;
    uint RAM88_RAMDATA;
    uint RAM89_RAMDATA;
    uint RAM90_RAMDATA;
    uint RAM91_RAMDATA;
    uint RAM92_RAMDATA;
    uint RAM93_RAMDATA;
    uint RAM94_RAMDATA;
    uint RAM95_RAMDATA;
    uint RAM96_RAMDATA;
    uint RAM97_RAMDATA;
    uint RAM98_RAMDATA;
    uint RAM99_RAMDATA;
    uint RAM100_RAMDATA;
    uint RAM101_RAMDATA;
    uint RAM102_RAMDATA;
    uint RAM103_RAMDATA;
    uint RAM104_RAMDATA;
    uint RAM105_RAMDATA;
    uint RAM106_RAMDATA;
    uint RAM107_RAMDATA;
    uint RAM108_RAMDATA;
    uint RAM109_RAMDATA;
    uint RAM110_RAMDATA;
    uint RAM111_RAMDATA;
    uint RAM112_RAMDATA;
    uint RAM113_RAMDATA;
    uint RAM114_RAMDATA;
    uint RAM115_RAMDATA;
    uint RAM116_RAMDATA;
    uint RAM117_RAMDATA;
    uint RAM118_RAMDATA;
    uint RAM119_RAMDATA;
    uint RAM120_RAMDATA;
    uint RAM121_RAMDATA;
    uint RAM122_RAMDATA;
    uint RAM123_RAMDATA;
    uint RAM124_RAMDATA;
    uint RAM125_RAMDATA;
    uint RAM126_RAMDATA;
    uint RAM127_RAMDATA;
    uint RAM128_RAMDATA;
    uint RAM129_RAMDATA;
    uint RAM130_RAMDATA;
    uint RAM131_RAMDATA;
    uint RAM132_RAMDATA;
    uint RAM133_RAMDATA;
    uint RAM134_RAMDATA;
    uint RAM135_RAMDATA;
    uint RAM136_RAMDATA;
    uint RAM137_RAMDATA;
    uint RAM138_RAMDATA;
    uint RAM139_RAMDATA;
    uint RAM140_RAMDATA;
    uint RAM141_RAMDATA;
    uint RAM142_RAMDATA;
    uint RAM143_RAMDATA;
    uint RAM144_RAMDATA;
    uint RAM145_RAMDATA;
    uint RAM146_RAMDATA;
    uint RAM147_RAMDATA;
    uint RAM148_RAMDATA;
    uint RAM149_RAMDATA;
    uint RAM150_RAMDATA;
    uint RAM151_RAMDATA;
    uint RAM152_RAMDATA;
    uint RAM153_RAMDATA;
    uint RAM154_RAMDATA;
    uint RAM155_RAMDATA;
    uint RAM156_RAMDATA;
    uint RAM157_RAMDATA;
    uint RAM158_RAMDATA;
    uint RAM159_RAMDATA;
    uint RAM160_RAMDATA;
    uint RAM161_RAMDATA;
    uint RAM162_RAMDATA;
    uint RAM163_RAMDATA;
    uint RAM164_RAMDATA;
    uint RAM165_RAMDATA;
    uint RAM166_RAMDATA;
    uint RAM167_RAMDATA;
    uint RAM168_RAMDATA;
    uint RAM169_RAMDATA;
    uint RAM170_RAMDATA;
    uint RAM171_RAMDATA;
    uint RAM172_RAMDATA;
    uint RAM173_RAMDATA;
    uint RAM174_RAMDATA;
    uint RAM175_RAMDATA;
    uint RAM176_RAMDATA;
    uint RAM177_RAMDATA;
    uint RAM178_RAMDATA;
    uint RAM179_RAMDATA;
    uint RAM180_RAMDATA;
    uint RAM181_RAMDATA;
    uint RAM182_RAMDATA;
    uint RAM183_RAMDATA;
    uint RAM184_RAMDATA;
    uint RAM185_RAMDATA;
    uint RAM186_RAMDATA;
    uint RAM187_RAMDATA;
    uint RAM188_RAMDATA;
    uint RAM189_RAMDATA;
    uint RAM190_RAMDATA;
    uint RAM191_RAMDATA;
    uint RAM192_RAMDATA;
    uint RAM193_RAMDATA;
    uint RAM194_RAMDATA;
    uint RAM195_RAMDATA;
    uint RAM196_RAMDATA;
    uint RAM197_RAMDATA;
    uint RAM198_RAMDATA;
    uint RAM199_RAMDATA;
    uint RAM200_RAMDATA;
    uint RAM201_RAMDATA;
    uint RAM202_RAMDATA;
    uint RAM203_RAMDATA;
    uint RAM204_RAMDATA;
    uint RAM205_RAMDATA;
    uint RAM206_RAMDATA;
    uint RAM207_RAMDATA;
    uint RAM208_RAMDATA;
    uint RAM209_RAMDATA;
    uint RAM210_RAMDATA;
    uint RAM211_RAMDATA;
    uint RAM212_RAMDATA;
    uint RAM213_RAMDATA;
    uint RAM214_RAMDATA;
    uint RAM215_RAMDATA;
    uint RAM216_RAMDATA;
    uint RAM217_RAMDATA;
    uint RAM218_RAMDATA;
    uint RAM219_RAMDATA;
    uint RAM220_RAMDATA;
    uint RAM221_RAMDATA;
    uint RAM222_RAMDATA;
    uint RAM223_RAMDATA;
    uint RAM224_RAMDATA;
    uint RAM225_RAMDATA;
    uint RAM226_RAMDATA;
    uint RAM227_RAMDATA;
    uint RAM228_RAMDATA;
    uint RAM229_RAMDATA;
    uint RAM230_RAMDATA;
    uint RAM231_RAMDATA;
    uint RAM232_RAMDATA;
    uint RAM233_RAMDATA;
    uint RAM234_RAMDATA;
    uint RAM235_RAMDATA;
    uint RAM236_RAMDATA;
    uint RAM237_RAMDATA;
    uint RAM238_RAMDATA;
    uint RAM239_RAMDATA;
    uint RAM240_RAMDATA;
    uint RAM241_RAMDATA;
    uint RAM242_RAMDATA;
    uint RAM243_RAMDATA;
    uint RAM244_RAMDATA;
    uint RAM245_RAMDATA;
    uint RAM246_RAMDATA;
    uint RAM247_RAMDATA;
    uint RAM248_RAMDATA;
    uint RAM249_RAMDATA;
    uint RAM250_RAMDATA;
    uint RAM251_RAMDATA;
    uint RAM252_RAMDATA;
    uint RAM253_RAMDATA;
    uint RAM254_RAMDATA;
    uint RAM255_RAMDATA;
};

typedef struct MODEM_SET MODEM_SET, *PMODEM_SET;

struct MODEM_SET {
    uint STATUS;
    uint TIMDETSTATUS;
    uint FREQOFFEST;
    uint AFCADJRX;
    uint AFCADJTX;
    uint MIXCTRL;
    uint CTRL0;
    uint CTRL1;
    uint CTRL2;
    uint CTRL3;
    uint CTRL4;
    uint CTRL5;
    uint TXBR;
    uint RXBR;
    uint CF;
    uint PRE;
    uint SYNC0;
    uint SYNC1;
    uint TIMING;
    uint DSSS0;
    uint MODINDEX;
    uint AFC;
    uint AFCADJLIM;
    uint SHAPING0;
    uint SHAPING1;
    uint SHAPING2;
    uint RAMPCTRL;
    uint RAMPLEV;
    uint ROUTEPEN;
    uint ROUTELOC0;
    uint ROUTELOC1;
    undefined field_0x7c;
    undefined field_0x7d;
    undefined field_0x7e;
    undefined field_0x7f;
    uint IF;
    uint IFS;
    uint IFC;
    uint IEN;
    uint CMD;
    undefined field_0x94;
    undefined field_0x95;
    undefined field_0x96;
    undefined field_0x97;
    uint DCCOMP;
    uint DCCOMPFILTINIT;
    undefined field_0xa0;
    undefined field_0xa1;
    undefined field_0xa2;
    undefined field_0xa3;
    undefined field_0xa4;
    undefined field_0xa5;
    undefined field_0xa6;
    undefined field_0xa7;
    undefined field_0xa8;
    undefined field_0xa9;
    undefined field_0xaa;
    undefined field_0xab;
    undefined field_0xac;
    undefined field_0xad;
    undefined field_0xae;
    undefined field_0xaf;
    undefined field_0xb0;
    undefined field_0xb1;
    undefined field_0xb2;
    undefined field_0xb3;
    undefined field_0xb4;
    undefined field_0xb5;
    undefined field_0xb6;
    undefined field_0xb7;
    undefined field_0xb8;
    undefined field_0xb9;
    undefined field_0xba;
    undefined field_0xbb;
    undefined field_0xbc;
    undefined field_0xbd;
    undefined field_0xbe;
    undefined field_0xbf;
    undefined field_0xc0;
    undefined field_0xc1;
    undefined field_0xc2;
    undefined field_0xc3;
    undefined field_0xc4;
    undefined field_0xc5;
    undefined field_0xc6;
    undefined field_0xc7;
    undefined field_0xc8;
    undefined field_0xc9;
    undefined field_0xca;
    undefined field_0xcb;
    undefined field_0xcc;
    undefined field_0xcd;
    undefined field_0xce;
    undefined field_0xcf;
    undefined field_0xd0;
    undefined field_0xd1;
    undefined field_0xd2;
    undefined field_0xd3;
    undefined field_0xd4;
    undefined field_0xd5;
    undefined field_0xd6;
    undefined field_0xd7;
    undefined field_0xd8;
    undefined field_0xd9;
    undefined field_0xda;
    undefined field_0xdb;
    undefined field_0xdc;
    undefined field_0xdd;
    undefined field_0xde;
    undefined field_0xdf;
    undefined field_0xe0;
    undefined field_0xe1;
    undefined field_0xe2;
    undefined field_0xe3;
    undefined field_0xe4;
    undefined field_0xe5;
    undefined field_0xe6;
    undefined field_0xe7;
    undefined field_0xe8;
    undefined field_0xe9;
    undefined field_0xea;
    undefined field_0xeb;
    undefined field_0xec;
    undefined field_0xed;
    undefined field_0xee;
    undefined field_0xef;
    undefined field_0xf0;
    undefined field_0xf1;
    undefined field_0xf2;
    undefined field_0xf3;
    undefined field_0xf4;
    undefined field_0xf5;
    undefined field_0xf6;
    undefined field_0xf7;
    undefined field_0xf8;
    undefined field_0xf9;
    undefined field_0xfa;
    undefined field_0xfb;
    undefined field_0xfc;
    undefined field_0xfd;
    undefined field_0xfe;
    undefined field_0xff;
    uint DCESTI;
    undefined field_0x104;
    undefined field_0x105;
    undefined field_0x106;
    undefined field_0x107;
    undefined field_0x108;
    undefined field_0x109;
    undefined field_0x10a;
    undefined field_0x10b;
    undefined field_0x10c;
    undefined field_0x10d;
    undefined field_0x10e;
    undefined field_0x10f;
    undefined field_0x110;
    undefined field_0x111;
    undefined field_0x112;
    undefined field_0x113;
    undefined field_0x114;
    undefined field_0x115;
    undefined field_0x116;
    undefined field_0x117;
    undefined field_0x118;
    undefined field_0x119;
    undefined field_0x11a;
    undefined field_0x11b;
    undefined field_0x11c;
    undefined field_0x11d;
    undefined field_0x11e;
    undefined field_0x11f;
    undefined field_0x120;
    undefined field_0x121;
    undefined field_0x122;
    undefined field_0x123;
    undefined field_0x124;
    undefined field_0x125;
    undefined field_0x126;
    undefined field_0x127;
    undefined field_0x128;
    undefined field_0x129;
    undefined field_0x12a;
    undefined field_0x12b;
    undefined field_0x12c;
    undefined field_0x12d;
    undefined field_0x12e;
    undefined field_0x12f;
    undefined field_0x130;
    undefined field_0x131;
    undefined field_0x132;
    undefined field_0x133;
    undefined field_0x134;
    undefined field_0x135;
    undefined field_0x136;
    undefined field_0x137;
    undefined field_0x138;
    undefined field_0x139;
    undefined field_0x13a;
    undefined field_0x13b;
    undefined field_0x13c;
    undefined field_0x13d;
    undefined field_0x13e;
    undefined field_0x13f;
    undefined field_0x140;
    undefined field_0x141;
    undefined field_0x142;
    undefined field_0x143;
    undefined field_0x144;
    undefined field_0x145;
    undefined field_0x146;
    undefined field_0x147;
    undefined field_0x148;
    undefined field_0x149;
    undefined field_0x14a;
    undefined field_0x14b;
    undefined field_0x14c;
    undefined field_0x14d;
    undefined field_0x14e;
    undefined field_0x14f;
    undefined field_0x150;
    undefined field_0x151;
    undefined field_0x152;
    undefined field_0x153;
    undefined field_0x154;
    undefined field_0x155;
    undefined field_0x156;
    undefined field_0x157;
    undefined field_0x158;
    undefined field_0x159;
    undefined field_0x15a;
    undefined field_0x15b;
    undefined field_0x15c;
    undefined field_0x15d;
    undefined field_0x15e;
    undefined field_0x15f;
    undefined field_0x160;
    undefined field_0x161;
    undefined field_0x162;
    undefined field_0x163;
    undefined field_0x164;
    undefined field_0x165;
    undefined field_0x166;
    undefined field_0x167;
    undefined field_0x168;
    undefined field_0x169;
    undefined field_0x16a;
    undefined field_0x16b;
    undefined field_0x16c;
    undefined field_0x16d;
    undefined field_0x16e;
    undefined field_0x16f;
    undefined field_0x170;
    undefined field_0x171;
    undefined field_0x172;
    undefined field_0x173;
    undefined field_0x174;
    undefined field_0x175;
    undefined field_0x176;
    undefined field_0x177;
    undefined field_0x178;
    undefined field_0x179;
    undefined field_0x17a;
    undefined field_0x17b;
    undefined field_0x17c;
    undefined field_0x17d;
    undefined field_0x17e;
    undefined field_0x17f;
    undefined field_0x180;
    undefined field_0x181;
    undefined field_0x182;
    undefined field_0x183;
    undefined field_0x184;
    undefined field_0x185;
    undefined field_0x186;
    undefined field_0x187;
    undefined field_0x188;
    undefined field_0x189;
    undefined field_0x18a;
    undefined field_0x18b;
    undefined field_0x18c;
    undefined field_0x18d;
    undefined field_0x18e;
    undefined field_0x18f;
    undefined field_0x190;
    undefined field_0x191;
    undefined field_0x192;
    undefined field_0x193;
    undefined field_0x194;
    undefined field_0x195;
    undefined field_0x196;
    undefined field_0x197;
    undefined field_0x198;
    undefined field_0x199;
    undefined field_0x19a;
    undefined field_0x19b;
    undefined field_0x19c;
    undefined field_0x19d;
    undefined field_0x19e;
    undefined field_0x19f;
    undefined field_0x1a0;
    undefined field_0x1a1;
    undefined field_0x1a2;
    undefined field_0x1a3;
    undefined field_0x1a4;
    undefined field_0x1a5;
    undefined field_0x1a6;
    undefined field_0x1a7;
    undefined field_0x1a8;
    undefined field_0x1a9;
    undefined field_0x1aa;
    undefined field_0x1ab;
    undefined field_0x1ac;
    undefined field_0x1ad;
    undefined field_0x1ae;
    undefined field_0x1af;
    undefined field_0x1b0;
    undefined field_0x1b1;
    undefined field_0x1b2;
    undefined field_0x1b3;
    undefined field_0x1b4;
    undefined field_0x1b5;
    undefined field_0x1b6;
    undefined field_0x1b7;
    undefined field_0x1b8;
    undefined field_0x1b9;
    undefined field_0x1ba;
    undefined field_0x1bb;
    undefined field_0x1bc;
    undefined field_0x1bd;
    undefined field_0x1be;
    undefined field_0x1bf;
    undefined field_0x1c0;
    undefined field_0x1c1;
    undefined field_0x1c2;
    undefined field_0x1c3;
    undefined field_0x1c4;
    undefined field_0x1c5;
    undefined field_0x1c6;
    undefined field_0x1c7;
    undefined field_0x1c8;
    undefined field_0x1c9;
    undefined field_0x1ca;
    undefined field_0x1cb;
    undefined field_0x1cc;
    undefined field_0x1cd;
    undefined field_0x1ce;
    undefined field_0x1cf;
    undefined field_0x1d0;
    undefined field_0x1d1;
    undefined field_0x1d2;
    undefined field_0x1d3;
    undefined field_0x1d4;
    undefined field_0x1d5;
    undefined field_0x1d6;
    undefined field_0x1d7;
    undefined field_0x1d8;
    undefined field_0x1d9;
    undefined field_0x1da;
    undefined field_0x1db;
    undefined field_0x1dc;
    undefined field_0x1dd;
    undefined field_0x1de;
    undefined field_0x1df;
    undefined field_0x1e0;
    undefined field_0x1e1;
    undefined field_0x1e2;
    undefined field_0x1e3;
    undefined field_0x1e4;
    undefined field_0x1e5;
    undefined field_0x1e6;
    undefined field_0x1e7;
    undefined field_0x1e8;
    undefined field_0x1e9;
    undefined field_0x1ea;
    undefined field_0x1eb;
    undefined field_0x1ec;
    undefined field_0x1ed;
    undefined field_0x1ee;
    undefined field_0x1ef;
    undefined field_0x1f0;
    undefined field_0x1f1;
    undefined field_0x1f2;
    undefined field_0x1f3;
    undefined field_0x1f4;
    undefined field_0x1f5;
    undefined field_0x1f6;
    undefined field_0x1f7;
    undefined field_0x1f8;
    undefined field_0x1f9;
    undefined field_0x1fa;
    undefined field_0x1fb;
    undefined field_0x1fc;
    undefined field_0x1fd;
    undefined field_0x1fe;
    undefined field_0x1ff;
    undefined field_0x200;
    undefined field_0x201;
    undefined field_0x202;
    undefined field_0x203;
    undefined field_0x204;
    undefined field_0x205;
    undefined field_0x206;
    undefined field_0x207;
    undefined field_0x208;
    undefined field_0x209;
    undefined field_0x20a;
    undefined field_0x20b;
    undefined field_0x20c;
    undefined field_0x20d;
    undefined field_0x20e;
    undefined field_0x20f;
    undefined field_0x210;
    undefined field_0x211;
    undefined field_0x212;
    undefined field_0x213;
    undefined field_0x214;
    undefined field_0x215;
    undefined field_0x216;
    undefined field_0x217;
    undefined field_0x218;
    undefined field_0x219;
    undefined field_0x21a;
    undefined field_0x21b;
    undefined field_0x21c;
    undefined field_0x21d;
    undefined field_0x21e;
    undefined field_0x21f;
    undefined field_0x220;
    undefined field_0x221;
    undefined field_0x222;
    undefined field_0x223;
    undefined field_0x224;
    undefined field_0x225;
    undefined field_0x226;
    undefined field_0x227;
    undefined field_0x228;
    undefined field_0x229;
    undefined field_0x22a;
    undefined field_0x22b;
    undefined field_0x22c;
    undefined field_0x22d;
    undefined field_0x22e;
    undefined field_0x22f;
    undefined field_0x230;
    undefined field_0x231;
    undefined field_0x232;
    undefined field_0x233;
    undefined field_0x234;
    undefined field_0x235;
    undefined field_0x236;
    undefined field_0x237;
    undefined field_0x238;
    undefined field_0x239;
    undefined field_0x23a;
    undefined field_0x23b;
    undefined field_0x23c;
    undefined field_0x23d;
    undefined field_0x23e;
    undefined field_0x23f;
    undefined field_0x240;
    undefined field_0x241;
    undefined field_0x242;
    undefined field_0x243;
    undefined field_0x244;
    undefined field_0x245;
    undefined field_0x246;
    undefined field_0x247;
    undefined field_0x248;
    undefined field_0x249;
    undefined field_0x24a;
    undefined field_0x24b;
    undefined field_0x24c;
    undefined field_0x24d;
    undefined field_0x24e;
    undefined field_0x24f;
    undefined field_0x250;
    undefined field_0x251;
    undefined field_0x252;
    undefined field_0x253;
    undefined field_0x254;
    undefined field_0x255;
    undefined field_0x256;
    undefined field_0x257;
    undefined field_0x258;
    undefined field_0x259;
    undefined field_0x25a;
    undefined field_0x25b;
    undefined field_0x25c;
    undefined field_0x25d;
    undefined field_0x25e;
    undefined field_0x25f;
    undefined field_0x260;
    undefined field_0x261;
    undefined field_0x262;
    undefined field_0x263;
    undefined field_0x264;
    undefined field_0x265;
    undefined field_0x266;
    undefined field_0x267;
    undefined field_0x268;
    undefined field_0x269;
    undefined field_0x26a;
    undefined field_0x26b;
    undefined field_0x26c;
    undefined field_0x26d;
    undefined field_0x26e;
    undefined field_0x26f;
    undefined field_0x270;
    undefined field_0x271;
    undefined field_0x272;
    undefined field_0x273;
    undefined field_0x274;
    undefined field_0x275;
    undefined field_0x276;
    undefined field_0x277;
    undefined field_0x278;
    undefined field_0x279;
    undefined field_0x27a;
    undefined field_0x27b;
    undefined field_0x27c;
    undefined field_0x27d;
    undefined field_0x27e;
    undefined field_0x27f;
    undefined field_0x280;
    undefined field_0x281;
    undefined field_0x282;
    undefined field_0x283;
    undefined field_0x284;
    undefined field_0x285;
    undefined field_0x286;
    undefined field_0x287;
    undefined field_0x288;
    undefined field_0x289;
    undefined field_0x28a;
    undefined field_0x28b;
    undefined field_0x28c;
    undefined field_0x28d;
    undefined field_0x28e;
    undefined field_0x28f;
    undefined field_0x290;
    undefined field_0x291;
    undefined field_0x292;
    undefined field_0x293;
    undefined field_0x294;
    undefined field_0x295;
    undefined field_0x296;
    undefined field_0x297;
    undefined field_0x298;
    undefined field_0x299;
    undefined field_0x29a;
    undefined field_0x29b;
    undefined field_0x29c;
    undefined field_0x29d;
    undefined field_0x29e;
    undefined field_0x29f;
    undefined field_0x2a0;
    undefined field_0x2a1;
    undefined field_0x2a2;
    undefined field_0x2a3;
    undefined field_0x2a4;
    undefined field_0x2a5;
    undefined field_0x2a6;
    undefined field_0x2a7;
    undefined field_0x2a8;
    undefined field_0x2a9;
    undefined field_0x2aa;
    undefined field_0x2ab;
    undefined field_0x2ac;
    undefined field_0x2ad;
    undefined field_0x2ae;
    undefined field_0x2af;
    undefined field_0x2b0;
    undefined field_0x2b1;
    undefined field_0x2b2;
    undefined field_0x2b3;
    undefined field_0x2b4;
    undefined field_0x2b5;
    undefined field_0x2b6;
    undefined field_0x2b7;
    undefined field_0x2b8;
    undefined field_0x2b9;
    undefined field_0x2ba;
    undefined field_0x2bb;
    undefined field_0x2bc;
    undefined field_0x2bd;
    undefined field_0x2be;
    undefined field_0x2bf;
    undefined field_0x2c0;
    undefined field_0x2c1;
    undefined field_0x2c2;
    undefined field_0x2c3;
    undefined field_0x2c4;
    undefined field_0x2c5;
    undefined field_0x2c6;
    undefined field_0x2c7;
    undefined field_0x2c8;
    undefined field_0x2c9;
    undefined field_0x2ca;
    undefined field_0x2cb;
    undefined field_0x2cc;
    undefined field_0x2cd;
    undefined field_0x2ce;
    undefined field_0x2cf;
    undefined field_0x2d0;
    undefined field_0x2d1;
    undefined field_0x2d2;
    undefined field_0x2d3;
    undefined field_0x2d4;
    undefined field_0x2d5;
    undefined field_0x2d6;
    undefined field_0x2d7;
    undefined field_0x2d8;
    undefined field_0x2d9;
    undefined field_0x2da;
    undefined field_0x2db;
    undefined field_0x2dc;
    undefined field_0x2dd;
    undefined field_0x2de;
    undefined field_0x2df;
    undefined field_0x2e0;
    undefined field_0x2e1;
    undefined field_0x2e2;
    undefined field_0x2e3;
    undefined field_0x2e4;
    undefined field_0x2e5;
    undefined field_0x2e6;
    undefined field_0x2e7;
    undefined field_0x2e8;
    undefined field_0x2e9;
    undefined field_0x2ea;
    undefined field_0x2eb;
    undefined field_0x2ec;
    undefined field_0x2ed;
    undefined field_0x2ee;
    undefined field_0x2ef;
    undefined field_0x2f0;
    undefined field_0x2f1;
    undefined field_0x2f2;
    undefined field_0x2f3;
    undefined field_0x2f4;
    undefined field_0x2f5;
    undefined field_0x2f6;
    undefined field_0x2f7;
    undefined field_0x2f8;
    undefined field_0x2f9;
    undefined field_0x2fa;
    undefined field_0x2fb;
    undefined field_0x2fc;
    undefined field_0x2fd;
    undefined field_0x2fe;
    undefined field_0x2ff;
    undefined field_0x300;
    undefined field_0x301;
    undefined field_0x302;
    undefined field_0x303;
    undefined field_0x304;
    undefined field_0x305;
    undefined field_0x306;
    undefined field_0x307;
    undefined field_0x308;
    undefined field_0x309;
    undefined field_0x30a;
    undefined field_0x30b;
    undefined field_0x30c;
    undefined field_0x30d;
    undefined field_0x30e;
    undefined field_0x30f;
    undefined field_0x310;
    undefined field_0x311;
    undefined field_0x312;
    undefined field_0x313;
    undefined field_0x314;
    undefined field_0x315;
    undefined field_0x316;
    undefined field_0x317;
    undefined field_0x318;
    undefined field_0x319;
    undefined field_0x31a;
    undefined field_0x31b;
    undefined field_0x31c;
    undefined field_0x31d;
    undefined field_0x31e;
    undefined field_0x31f;
    undefined field_0x320;
    undefined field_0x321;
    undefined field_0x322;
    undefined field_0x323;
    undefined field_0x324;
    undefined field_0x325;
    undefined field_0x326;
    undefined field_0x327;
    undefined field_0x328;
    undefined field_0x329;
    undefined field_0x32a;
    undefined field_0x32b;
    undefined field_0x32c;
    undefined field_0x32d;
    undefined field_0x32e;
    undefined field_0x32f;
    undefined field_0x330;
    undefined field_0x331;
    undefined field_0x332;
    undefined field_0x333;
    undefined field_0x334;
    undefined field_0x335;
    undefined field_0x336;
    undefined field_0x337;
    undefined field_0x338;
    undefined field_0x339;
    undefined field_0x33a;
    undefined field_0x33b;
    undefined field_0x33c;
    undefined field_0x33d;
    undefined field_0x33e;
    undefined field_0x33f;
    undefined field_0x340;
    undefined field_0x341;
    undefined field_0x342;
    undefined field_0x343;
    undefined field_0x344;
    undefined field_0x345;
    undefined field_0x346;
    undefined field_0x347;
    undefined field_0x348;
    undefined field_0x349;
    undefined field_0x34a;
    undefined field_0x34b;
    undefined field_0x34c;
    undefined field_0x34d;
    undefined field_0x34e;
    undefined field_0x34f;
    undefined field_0x350;
    undefined field_0x351;
    undefined field_0x352;
    undefined field_0x353;
    undefined field_0x354;
    undefined field_0x355;
    undefined field_0x356;
    undefined field_0x357;
    undefined field_0x358;
    undefined field_0x359;
    undefined field_0x35a;
    undefined field_0x35b;
    undefined field_0x35c;
    undefined field_0x35d;
    undefined field_0x35e;
    undefined field_0x35f;
    undefined field_0x360;
    undefined field_0x361;
    undefined field_0x362;
    undefined field_0x363;
    undefined field_0x364;
    undefined field_0x365;
    undefined field_0x366;
    undefined field_0x367;
    undefined field_0x368;
    undefined field_0x369;
    undefined field_0x36a;
    undefined field_0x36b;
    undefined field_0x36c;
    undefined field_0x36d;
    undefined field_0x36e;
    undefined field_0x36f;
    undefined field_0x370;
    undefined field_0x371;
    undefined field_0x372;
    undefined field_0x373;
    undefined field_0x374;
    undefined field_0x375;
    undefined field_0x376;
    undefined field_0x377;
    undefined field_0x378;
    undefined field_0x379;
    undefined field_0x37a;
    undefined field_0x37b;
    undefined field_0x37c;
    undefined field_0x37d;
    undefined field_0x37e;
    undefined field_0x37f;
    undefined field_0x380;
    undefined field_0x381;
    undefined field_0x382;
    undefined field_0x383;
    undefined field_0x384;
    undefined field_0x385;
    undefined field_0x386;
    undefined field_0x387;
    undefined field_0x388;
    undefined field_0x389;
    undefined field_0x38a;
    undefined field_0x38b;
    undefined field_0x38c;
    undefined field_0x38d;
    undefined field_0x38e;
    undefined field_0x38f;
    undefined field_0x390;
    undefined field_0x391;
    undefined field_0x392;
    undefined field_0x393;
    undefined field_0x394;
    undefined field_0x395;
    undefined field_0x396;
    undefined field_0x397;
    undefined field_0x398;
    undefined field_0x399;
    undefined field_0x39a;
    undefined field_0x39b;
    undefined field_0x39c;
    undefined field_0x39d;
    undefined field_0x39e;
    undefined field_0x39f;
    undefined field_0x3a0;
    undefined field_0x3a1;
    undefined field_0x3a2;
    undefined field_0x3a3;
    undefined field_0x3a4;
    undefined field_0x3a5;
    undefined field_0x3a6;
    undefined field_0x3a7;
    undefined field_0x3a8;
    undefined field_0x3a9;
    undefined field_0x3aa;
    undefined field_0x3ab;
    undefined field_0x3ac;
    undefined field_0x3ad;
    undefined field_0x3ae;
    undefined field_0x3af;
    undefined field_0x3b0;
    undefined field_0x3b1;
    undefined field_0x3b2;
    undefined field_0x3b3;
    undefined field_0x3b4;
    undefined field_0x3b5;
    undefined field_0x3b6;
    undefined field_0x3b7;
    undefined field_0x3b8;
    undefined field_0x3b9;
    undefined field_0x3ba;
    undefined field_0x3bb;
    undefined field_0x3bc;
    undefined field_0x3bd;
    undefined field_0x3be;
    undefined field_0x3bf;
    undefined field_0x3c0;
    undefined field_0x3c1;
    undefined field_0x3c2;
    undefined field_0x3c3;
    undefined field_0x3c4;
    undefined field_0x3c5;
    undefined field_0x3c6;
    undefined field_0x3c7;
    undefined field_0x3c8;
    undefined field_0x3c9;
    undefined field_0x3ca;
    undefined field_0x3cb;
    undefined field_0x3cc;
    undefined field_0x3cd;
    undefined field_0x3ce;
    undefined field_0x3cf;
    undefined field_0x3d0;
    undefined field_0x3d1;
    undefined field_0x3d2;
    undefined field_0x3d3;
    undefined field_0x3d4;
    undefined field_0x3d5;
    undefined field_0x3d6;
    undefined field_0x3d7;
    undefined field_0x3d8;
    undefined field_0x3d9;
    undefined field_0x3da;
    undefined field_0x3db;
    undefined field_0x3dc;
    undefined field_0x3dd;
    undefined field_0x3de;
    undefined field_0x3df;
    undefined field_0x3e0;
    undefined field_0x3e1;
    undefined field_0x3e2;
    undefined field_0x3e3;
    undefined field_0x3e4;
    undefined field_0x3e5;
    undefined field_0x3e6;
    undefined field_0x3e7;
    undefined field_0x3e8;
    undefined field_0x3e9;
    undefined field_0x3ea;
    undefined field_0x3eb;
    undefined field_0x3ec;
    undefined field_0x3ed;
    undefined field_0x3ee;
    undefined field_0x3ef;
    undefined field_0x3f0;
    undefined field_0x3f1;
    undefined field_0x3f2;
    undefined field_0x3f3;
    undefined field_0x3f4;
    undefined field_0x3f5;
    undefined field_0x3f6;
    undefined field_0x3f7;
    undefined field_0x3f8;
    undefined field_0x3f9;
    undefined field_0x3fa;
    undefined field_0x3fb;
    undefined field_0x3fc;
    undefined field_0x3fd;
    undefined field_0x3fe;
    undefined field_0x3ff;
    uint RAM0_RAMDATA;
    uint RAM1_RAMDATA;
    uint RAM2_RAMDATA;
    uint RAM3_RAMDATA;
    uint RAM4_RAMDATA;
    uint RAM5_RAMDATA;
    uint RAM6_RAMDATA;
    uint RAM7_RAMDATA;
    uint RAM8_RAMDATA;
    uint RAM9_RAMDATA;
    uint RAM10_RAMDATA;
    uint RAM11_RAMDATA;
    uint RAM12_RAMDATA;
    uint RAM13_RAMDATA;
    uint RAM14_RAMDATA;
    uint RAM15_RAMDATA;
    uint RAM16_RAMDATA;
    uint RAM17_RAMDATA;
    uint RAM18_RAMDATA;
    uint RAM19_RAMDATA;
    uint RAM20_RAMDATA;
    uint RAM21_RAMDATA;
    uint RAM22_RAMDATA;
    uint RAM23_RAMDATA;
    uint RAM24_RAMDATA;
    uint RAM25_RAMDATA;
    uint RAM26_RAMDATA;
    uint RAM27_RAMDATA;
    uint RAM28_RAMDATA;
    uint RAM29_RAMDATA;
    uint RAM30_RAMDATA;
    uint RAM31_RAMDATA;
    uint RAM32_RAMDATA;
    uint RAM33_RAMDATA;
    uint RAM34_RAMDATA;
    uint RAM35_RAMDATA;
    uint RAM36_RAMDATA;
    uint RAM37_RAMDATA;
    uint RAM38_RAMDATA;
    uint RAM39_RAMDATA;
    uint RAM40_RAMDATA;
    uint RAM41_RAMDATA;
    uint RAM42_RAMDATA;
    uint RAM43_RAMDATA;
    uint RAM44_RAMDATA;
    uint RAM45_RAMDATA;
    uint RAM46_RAMDATA;
    uint RAM47_RAMDATA;
    uint RAM48_RAMDATA;
    uint RAM49_RAMDATA;
    uint RAM50_RAMDATA;
    uint RAM51_RAMDATA;
    uint RAM52_RAMDATA;
    uint RAM53_RAMDATA;
    uint RAM54_RAMDATA;
    uint RAM55_RAMDATA;
    uint RAM56_RAMDATA;
    uint RAM57_RAMDATA;
    uint RAM58_RAMDATA;
    uint RAM59_RAMDATA;
    uint RAM60_RAMDATA;
    uint RAM61_RAMDATA;
    uint RAM62_RAMDATA;
    uint RAM63_RAMDATA;
    uint RAM64_RAMDATA;
    uint RAM65_RAMDATA;
    uint RAM66_RAMDATA;
    uint RAM67_RAMDATA;
    uint RAM68_RAMDATA;
    uint RAM69_RAMDATA;
    uint RAM70_RAMDATA;
    uint RAM71_RAMDATA;
    uint RAM72_RAMDATA;
    uint RAM73_RAMDATA;
    uint RAM74_RAMDATA;
    uint RAM75_RAMDATA;
    uint RAM76_RAMDATA;
    uint RAM77_RAMDATA;
    uint RAM78_RAMDATA;
    uint RAM79_RAMDATA;
    uint RAM80_RAMDATA;
    uint RAM81_RAMDATA;
    uint RAM82_RAMDATA;
    uint RAM83_RAMDATA;
    uint RAM84_RAMDATA;
    uint RAM85_RAMDATA;
    uint RAM86_RAMDATA;
    uint RAM87_RAMDATA;
    uint RAM88_RAMDATA;
    uint RAM89_RAMDATA;
    uint RAM90_RAMDATA;
    uint RAM91_RAMDATA;
    uint RAM92_RAMDATA;
    uint RAM93_RAMDATA;
    uint RAM94_RAMDATA;
    uint RAM95_RAMDATA;
    uint RAM96_RAMDATA;
    uint RAM97_RAMDATA;
    uint RAM98_RAMDATA;
    uint RAM99_RAMDATA;
    uint RAM100_RAMDATA;
    uint RAM101_RAMDATA;
    uint RAM102_RAMDATA;
    uint RAM103_RAMDATA;
    uint RAM104_RAMDATA;
    uint RAM105_RAMDATA;
    uint RAM106_RAMDATA;
    uint RAM107_RAMDATA;
    uint RAM108_RAMDATA;
    uint RAM109_RAMDATA;
    uint RAM110_RAMDATA;
    uint RAM111_RAMDATA;
    uint RAM112_RAMDATA;
    uint RAM113_RAMDATA;
    uint RAM114_RAMDATA;
    uint RAM115_RAMDATA;
    uint RAM116_RAMDATA;
    uint RAM117_RAMDATA;
    uint RAM118_RAMDATA;
    uint RAM119_RAMDATA;
    uint RAM120_RAMDATA;
    uint RAM121_RAMDATA;
    uint RAM122_RAMDATA;
    uint RAM123_RAMDATA;
    uint RAM124_RAMDATA;
    uint RAM125_RAMDATA;
    uint RAM126_RAMDATA;
    uint RAM127_RAMDATA;
    uint RAM128_RAMDATA;
    uint RAM129_RAMDATA;
    uint RAM130_RAMDATA;
    uint RAM131_RAMDATA;
    uint RAM132_RAMDATA;
    uint RAM133_RAMDATA;
    uint RAM134_RAMDATA;
    uint RAM135_RAMDATA;
    uint RAM136_RAMDATA;
    uint RAM137_RAMDATA;
    uint RAM138_RAMDATA;
    uint RAM139_RAMDATA;
    uint RAM140_RAMDATA;
    uint RAM141_RAMDATA;
    uint RAM142_RAMDATA;
    uint RAM143_RAMDATA;
    uint RAM144_RAMDATA;
    uint RAM145_RAMDATA;
    uint RAM146_RAMDATA;
    uint RAM147_RAMDATA;
    uint RAM148_RAMDATA;
    uint RAM149_RAMDATA;
    uint RAM150_RAMDATA;
    uint RAM151_RAMDATA;
    uint RAM152_RAMDATA;
    uint RAM153_RAMDATA;
    uint RAM154_RAMDATA;
    uint RAM155_RAMDATA;
    uint RAM156_RAMDATA;
    uint RAM157_RAMDATA;
    uint RAM158_RAMDATA;
    uint RAM159_RAMDATA;
    uint RAM160_RAMDATA;
    uint RAM161_RAMDATA;
    uint RAM162_RAMDATA;
    uint RAM163_RAMDATA;
    uint RAM164_RAMDATA;
    uint RAM165_RAMDATA;
    uint RAM166_RAMDATA;
    uint RAM167_RAMDATA;
    uint RAM168_RAMDATA;
    uint RAM169_RAMDATA;
    uint RAM170_RAMDATA;
    uint RAM171_RAMDATA;
    uint RAM172_RAMDATA;
    uint RAM173_RAMDATA;
    uint RAM174_RAMDATA;
    uint RAM175_RAMDATA;
    uint RAM176_RAMDATA;
    uint RAM177_RAMDATA;
    uint RAM178_RAMDATA;
    uint RAM179_RAMDATA;
    uint RAM180_RAMDATA;
    uint RAM181_RAMDATA;
    uint RAM182_RAMDATA;
    uint RAM183_RAMDATA;
    uint RAM184_RAMDATA;
    uint RAM185_RAMDATA;
    uint RAM186_RAMDATA;
    uint RAM187_RAMDATA;
    uint RAM188_RAMDATA;
    uint RAM189_RAMDATA;
    uint RAM190_RAMDATA;
    uint RAM191_RAMDATA;
    uint RAM192_RAMDATA;
    uint RAM193_RAMDATA;
    uint RAM194_RAMDATA;
    uint RAM195_RAMDATA;
    uint RAM196_RAMDATA;
    uint RAM197_RAMDATA;
    uint RAM198_RAMDATA;
    uint RAM199_RAMDATA;
    uint RAM200_RAMDATA;
    uint RAM201_RAMDATA;
    uint RAM202_RAMDATA;
    uint RAM203_RAMDATA;
    uint RAM204_RAMDATA;
    uint RAM205_RAMDATA;
    uint RAM206_RAMDATA;
    uint RAM207_RAMDATA;
    uint RAM208_RAMDATA;
    uint RAM209_RAMDATA;
    uint RAM210_RAMDATA;
    uint RAM211_RAMDATA;
    uint RAM212_RAMDATA;
    uint RAM213_RAMDATA;
    uint RAM214_RAMDATA;
    uint RAM215_RAMDATA;
    uint RAM216_RAMDATA;
    uint RAM217_RAMDATA;
    uint RAM218_RAMDATA;
    uint RAM219_RAMDATA;
    uint RAM220_RAMDATA;
    uint RAM221_RAMDATA;
    uint RAM222_RAMDATA;
    uint RAM223_RAMDATA;
    uint RAM224_RAMDATA;
    uint RAM225_RAMDATA;
    uint RAM226_RAMDATA;
    uint RAM227_RAMDATA;
    uint RAM228_RAMDATA;
    uint RAM229_RAMDATA;
    uint RAM230_RAMDATA;
    uint RAM231_RAMDATA;
    uint RAM232_RAMDATA;
    uint RAM233_RAMDATA;
    uint RAM234_RAMDATA;
    uint RAM235_RAMDATA;
    uint RAM236_RAMDATA;
    uint RAM237_RAMDATA;
    uint RAM238_RAMDATA;
    uint RAM239_RAMDATA;
    uint RAM240_RAMDATA;
    uint RAM241_RAMDATA;
    uint RAM242_RAMDATA;
    uint RAM243_RAMDATA;
    uint RAM244_RAMDATA;
    uint RAM245_RAMDATA;
    uint RAM246_RAMDATA;
    uint RAM247_RAMDATA;
    uint RAM248_RAMDATA;
    uint RAM249_RAMDATA;
    uint RAM250_RAMDATA;
    uint RAM251_RAMDATA;
    uint RAM252_RAMDATA;
    uint RAM253_RAMDATA;
    uint RAM254_RAMDATA;
    uint RAM255_RAMDATA;
};

typedef struct GPIO GPIO, *PGPIO;

struct GPIO {
    uint PA_CTRL; // Port Control Register
    uint PA_MODEL; // Port Pin Mode Low Register
    uint PA_MODEH; // Port Pin Mode High Register
    uint PA_DOUT; // Port Data Out Register
    undefined field_0x10;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    uint PA_DOUTTGL; // Port Data Out Toggle Register
    uint PA_DIN; // Port Data in Register
    uint PA_PINLOCKN; // Port Unlocked Pins Register
    undefined field_0x24;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
    uint PA_OVTDIS; // Over Voltage Disable for All Modes
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    uint PB_CTRL; // Port Control Register
    uint PB_MODEL; // Port Pin Mode Low Register
    uint PB_MODEH; // Port Pin Mode High Register
    uint PB_DOUT; // Port Data Out Register
    undefined field_0x40;
    undefined field_0x41;
    undefined field_0x42;
    undefined field_0x43;
    undefined field_0x44;
    undefined field_0x45;
    undefined field_0x46;
    undefined field_0x47;
    uint PB_DOUTTGL; // Port Data Out Toggle Register
    uint PB_DIN; // Port Data in Register
    uint PB_PINLOCKN; // Port Unlocked Pins Register
    undefined field_0x54;
    undefined field_0x55;
    undefined field_0x56;
    undefined field_0x57;
    uint PB_OVTDIS; // Over Voltage Disable for All Modes
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    uint PC_CTRL; // Port Control Register
    uint PC_MODEL; // Port Pin Mode Low Register
    uint PC_MODEH; // Port Pin Mode High Register
    uint PC_DOUT; // Port Data Out Register
    undefined field_0x70;
    undefined field_0x71;
    undefined field_0x72;
    undefined field_0x73;
    undefined field_0x74;
    undefined field_0x75;
    undefined field_0x76;
    undefined field_0x77;
    uint PC_DOUTTGL; // Port Data Out Toggle Register
    uint PC_DIN; // Port Data in Register
    uint PC_PINLOCKN; // Port Unlocked Pins Register
    undefined field_0x84;
    undefined field_0x85;
    undefined field_0x86;
    undefined field_0x87;
    uint PC_OVTDIS; // Over Voltage Disable for All Modes
    undefined field_0x8c;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
    uint PD_CTRL; // Port Control Register
    uint PD_MODEL; // Port Pin Mode Low Register
    uint PD_MODEH; // Port Pin Mode High Register
    uint PD_DOUT; // Port Data Out Register
    undefined field_0xa0;
    undefined field_0xa1;
    undefined field_0xa2;
    undefined field_0xa3;
    undefined field_0xa4;
    undefined field_0xa5;
    undefined field_0xa6;
    undefined field_0xa7;
    uint PD_DOUTTGL; // Port Data Out Toggle Register
    uint PD_DIN; // Port Data in Register
    uint PD_PINLOCKN; // Port Unlocked Pins Register
    undefined field_0xb4;
    undefined field_0xb5;
    undefined field_0xb6;
    undefined field_0xb7;
    uint PD_OVTDIS; // Over Voltage Disable for All Modes
    undefined field_0xbc;
    undefined field_0xbd;
    undefined field_0xbe;
    undefined field_0xbf;
    uint PE_CTRL; // Port Control Register
    uint PE_MODEL; // Port Pin Mode Low Register
    uint PE_MODEH; // Port Pin Mode High Register
    uint PE_DOUT; // Port Data Out Register
    undefined field_0xd0;
    undefined field_0xd1;
    undefined field_0xd2;
    undefined field_0xd3;
    undefined field_0xd4;
    undefined field_0xd5;
    undefined field_0xd6;
    undefined field_0xd7;
    uint PE_DOUTTGL; // Port Data Out Toggle Register
    uint PE_DIN; // Port Data in Register
    uint PE_PINLOCKN; // Port Unlocked Pins Register
    undefined field_0xe4;
    undefined field_0xe5;
    undefined field_0xe6;
    undefined field_0xe7;
    uint PE_OVTDIS; // Over Voltage Disable for All Modes
    undefined field_0xec;
    undefined field_0xed;
    undefined field_0xee;
    undefined field_0xef;
    uint PF_CTRL; // Port Control Register
    uint PF_MODEL; // Port Pin Mode Low Register
    uint PF_MODEH; // Port Pin Mode High Register
    uint PF_DOUT; // Port Data Out Register
    undefined field_0x100;
    undefined field_0x101;
    undefined field_0x102;
    undefined field_0x103;
    undefined field_0x104;
    undefined field_0x105;
    undefined field_0x106;
    undefined field_0x107;
    uint PF_DOUTTGL; // Port Data Out Toggle Register
    uint PF_DIN; // Port Data in Register
    uint PF_PINLOCKN; // Port Unlocked Pins Register
    undefined field_0x114;
    undefined field_0x115;
    undefined field_0x116;
    undefined field_0x117;
    uint PF_OVTDIS; // Over Voltage Disable for All Modes
    undefined field_0x11c;
    undefined field_0x11d;
    undefined field_0x11e;
    undefined field_0x11f;
    undefined field_0x120;
    undefined field_0x121;
    undefined field_0x122;
    undefined field_0x123;
    undefined field_0x124;
    undefined field_0x125;
    undefined field_0x126;
    undefined field_0x127;
    undefined field_0x128;
    undefined field_0x129;
    undefined field_0x12a;
    undefined field_0x12b;
    undefined field_0x12c;
    undefined field_0x12d;
    undefined field_0x12e;
    undefined field_0x12f;
    undefined field_0x130;
    undefined field_0x131;
    undefined field_0x132;
    undefined field_0x133;
    undefined field_0x134;
    undefined field_0x135;
    undefined field_0x136;
    undefined field_0x137;
    undefined field_0x138;
    undefined field_0x139;
    undefined field_0x13a;
    undefined field_0x13b;
    undefined field_0x13c;
    undefined field_0x13d;
    undefined field_0x13e;
    undefined field_0x13f;
    undefined field_0x140;
    undefined field_0x141;
    undefined field_0x142;
    undefined field_0x143;
    undefined field_0x144;
    undefined field_0x145;
    undefined field_0x146;
    undefined field_0x147;
    undefined field_0x148;
    undefined field_0x149;
    undefined field_0x14a;
    undefined field_0x14b;
    undefined field_0x14c;
    undefined field_0x14d;
    undefined field_0x14e;
    undefined field_0x14f;
    undefined field_0x150;
    undefined field_0x151;
    undefined field_0x152;
    undefined field_0x153;
    undefined field_0x154;
    undefined field_0x155;
    undefined field_0x156;
    undefined field_0x157;
    undefined field_0x158;
    undefined field_0x159;
    undefined field_0x15a;
    undefined field_0x15b;
    undefined field_0x15c;
    undefined field_0x15d;
    undefined field_0x15e;
    undefined field_0x15f;
    undefined field_0x160;
    undefined field_0x161;
    undefined field_0x162;
    undefined field_0x163;
    undefined field_0x164;
    undefined field_0x165;
    undefined field_0x166;
    undefined field_0x167;
    undefined field_0x168;
    undefined field_0x169;
    undefined field_0x16a;
    undefined field_0x16b;
    undefined field_0x16c;
    undefined field_0x16d;
    undefined field_0x16e;
    undefined field_0x16f;
    undefined field_0x170;
    undefined field_0x171;
    undefined field_0x172;
    undefined field_0x173;
    undefined field_0x174;
    undefined field_0x175;
    undefined field_0x176;
    undefined field_0x177;
    undefined field_0x178;
    undefined field_0x179;
    undefined field_0x17a;
    undefined field_0x17b;
    undefined field_0x17c;
    undefined field_0x17d;
    undefined field_0x17e;
    undefined field_0x17f;
    undefined field_0x180;
    undefined field_0x181;
    undefined field_0x182;
    undefined field_0x183;
    undefined field_0x184;
    undefined field_0x185;
    undefined field_0x186;
    undefined field_0x187;
    undefined field_0x188;
    undefined field_0x189;
    undefined field_0x18a;
    undefined field_0x18b;
    undefined field_0x18c;
    undefined field_0x18d;
    undefined field_0x18e;
    undefined field_0x18f;
    undefined field_0x190;
    undefined field_0x191;
    undefined field_0x192;
    undefined field_0x193;
    undefined field_0x194;
    undefined field_0x195;
    undefined field_0x196;
    undefined field_0x197;
    undefined field_0x198;
    undefined field_0x199;
    undefined field_0x19a;
    undefined field_0x19b;
    undefined field_0x19c;
    undefined field_0x19d;
    undefined field_0x19e;
    undefined field_0x19f;
    undefined field_0x1a0;
    undefined field_0x1a1;
    undefined field_0x1a2;
    undefined field_0x1a3;
    undefined field_0x1a4;
    undefined field_0x1a5;
    undefined field_0x1a6;
    undefined field_0x1a7;
    undefined field_0x1a8;
    undefined field_0x1a9;
    undefined field_0x1aa;
    undefined field_0x1ab;
    undefined field_0x1ac;
    undefined field_0x1ad;
    undefined field_0x1ae;
    undefined field_0x1af;
    undefined field_0x1b0;
    undefined field_0x1b1;
    undefined field_0x1b2;
    undefined field_0x1b3;
    undefined field_0x1b4;
    undefined field_0x1b5;
    undefined field_0x1b6;
    undefined field_0x1b7;
    undefined field_0x1b8;
    undefined field_0x1b9;
    undefined field_0x1ba;
    undefined field_0x1bb;
    undefined field_0x1bc;
    undefined field_0x1bd;
    undefined field_0x1be;
    undefined field_0x1bf;
    undefined field_0x1c0;
    undefined field_0x1c1;
    undefined field_0x1c2;
    undefined field_0x1c3;
    undefined field_0x1c4;
    undefined field_0x1c5;
    undefined field_0x1c6;
    undefined field_0x1c7;
    undefined field_0x1c8;
    undefined field_0x1c9;
    undefined field_0x1ca;
    undefined field_0x1cb;
    undefined field_0x1cc;
    undefined field_0x1cd;
    undefined field_0x1ce;
    undefined field_0x1cf;
    undefined field_0x1d0;
    undefined field_0x1d1;
    undefined field_0x1d2;
    undefined field_0x1d3;
    undefined field_0x1d4;
    undefined field_0x1d5;
    undefined field_0x1d6;
    undefined field_0x1d7;
    undefined field_0x1d8;
    undefined field_0x1d9;
    undefined field_0x1da;
    undefined field_0x1db;
    undefined field_0x1dc;
    undefined field_0x1dd;
    undefined field_0x1de;
    undefined field_0x1df;
    undefined field_0x1e0;
    undefined field_0x1e1;
    undefined field_0x1e2;
    undefined field_0x1e3;
    undefined field_0x1e4;
    undefined field_0x1e5;
    undefined field_0x1e6;
    undefined field_0x1e7;
    undefined field_0x1e8;
    undefined field_0x1e9;
    undefined field_0x1ea;
    undefined field_0x1eb;
    undefined field_0x1ec;
    undefined field_0x1ed;
    undefined field_0x1ee;
    undefined field_0x1ef;
    undefined field_0x1f0;
    undefined field_0x1f1;
    undefined field_0x1f2;
    undefined field_0x1f3;
    undefined field_0x1f4;
    undefined field_0x1f5;
    undefined field_0x1f6;
    undefined field_0x1f7;
    undefined field_0x1f8;
    undefined field_0x1f9;
    undefined field_0x1fa;
    undefined field_0x1fb;
    undefined field_0x1fc;
    undefined field_0x1fd;
    undefined field_0x1fe;
    undefined field_0x1ff;
    undefined field_0x200;
    undefined field_0x201;
    undefined field_0x202;
    undefined field_0x203;
    undefined field_0x204;
    undefined field_0x205;
    undefined field_0x206;
    undefined field_0x207;
    undefined field_0x208;
    undefined field_0x209;
    undefined field_0x20a;
    undefined field_0x20b;
    undefined field_0x20c;
    undefined field_0x20d;
    undefined field_0x20e;
    undefined field_0x20f;
    undefined field_0x210;
    undefined field_0x211;
    undefined field_0x212;
    undefined field_0x213;
    undefined field_0x214;
    undefined field_0x215;
    undefined field_0x216;
    undefined field_0x217;
    undefined field_0x218;
    undefined field_0x219;
    undefined field_0x21a;
    undefined field_0x21b;
    undefined field_0x21c;
    undefined field_0x21d;
    undefined field_0x21e;
    undefined field_0x21f;
    undefined field_0x220;
    undefined field_0x221;
    undefined field_0x222;
    undefined field_0x223;
    undefined field_0x224;
    undefined field_0x225;
    undefined field_0x226;
    undefined field_0x227;
    undefined field_0x228;
    undefined field_0x229;
    undefined field_0x22a;
    undefined field_0x22b;
    undefined field_0x22c;
    undefined field_0x22d;
    undefined field_0x22e;
    undefined field_0x22f;
    undefined field_0x230;
    undefined field_0x231;
    undefined field_0x232;
    undefined field_0x233;
    undefined field_0x234;
    undefined field_0x235;
    undefined field_0x236;
    undefined field_0x237;
    undefined field_0x238;
    undefined field_0x239;
    undefined field_0x23a;
    undefined field_0x23b;
    undefined field_0x23c;
    undefined field_0x23d;
    undefined field_0x23e;
    undefined field_0x23f;
    undefined field_0x240;
    undefined field_0x241;
    undefined field_0x242;
    undefined field_0x243;
    undefined field_0x244;
    undefined field_0x245;
    undefined field_0x246;
    undefined field_0x247;
    undefined field_0x248;
    undefined field_0x249;
    undefined field_0x24a;
    undefined field_0x24b;
    undefined field_0x24c;
    undefined field_0x24d;
    undefined field_0x24e;
    undefined field_0x24f;
    undefined field_0x250;
    undefined field_0x251;
    undefined field_0x252;
    undefined field_0x253;
    undefined field_0x254;
    undefined field_0x255;
    undefined field_0x256;
    undefined field_0x257;
    undefined field_0x258;
    undefined field_0x259;
    undefined field_0x25a;
    undefined field_0x25b;
    undefined field_0x25c;
    undefined field_0x25d;
    undefined field_0x25e;
    undefined field_0x25f;
    undefined field_0x260;
    undefined field_0x261;
    undefined field_0x262;
    undefined field_0x263;
    undefined field_0x264;
    undefined field_0x265;
    undefined field_0x266;
    undefined field_0x267;
    undefined field_0x268;
    undefined field_0x269;
    undefined field_0x26a;
    undefined field_0x26b;
    undefined field_0x26c;
    undefined field_0x26d;
    undefined field_0x26e;
    undefined field_0x26f;
    undefined field_0x270;
    undefined field_0x271;
    undefined field_0x272;
    undefined field_0x273;
    undefined field_0x274;
    undefined field_0x275;
    undefined field_0x276;
    undefined field_0x277;
    undefined field_0x278;
    undefined field_0x279;
    undefined field_0x27a;
    undefined field_0x27b;
    undefined field_0x27c;
    undefined field_0x27d;
    undefined field_0x27e;
    undefined field_0x27f;
    undefined field_0x280;
    undefined field_0x281;
    undefined field_0x282;
    undefined field_0x283;
    undefined field_0x284;
    undefined field_0x285;
    undefined field_0x286;
    undefined field_0x287;
    undefined field_0x288;
    undefined field_0x289;
    undefined field_0x28a;
    undefined field_0x28b;
    undefined field_0x28c;
    undefined field_0x28d;
    undefined field_0x28e;
    undefined field_0x28f;
    undefined field_0x290;
    undefined field_0x291;
    undefined field_0x292;
    undefined field_0x293;
    undefined field_0x294;
    undefined field_0x295;
    undefined field_0x296;
    undefined field_0x297;
    undefined field_0x298;
    undefined field_0x299;
    undefined field_0x29a;
    undefined field_0x29b;
    undefined field_0x29c;
    undefined field_0x29d;
    undefined field_0x29e;
    undefined field_0x29f;
    undefined field_0x2a0;
    undefined field_0x2a1;
    undefined field_0x2a2;
    undefined field_0x2a3;
    undefined field_0x2a4;
    undefined field_0x2a5;
    undefined field_0x2a6;
    undefined field_0x2a7;
    undefined field_0x2a8;
    undefined field_0x2a9;
    undefined field_0x2aa;
    undefined field_0x2ab;
    undefined field_0x2ac;
    undefined field_0x2ad;
    undefined field_0x2ae;
    undefined field_0x2af;
    undefined field_0x2b0;
    undefined field_0x2b1;
    undefined field_0x2b2;
    undefined field_0x2b3;
    undefined field_0x2b4;
    undefined field_0x2b5;
    undefined field_0x2b6;
    undefined field_0x2b7;
    undefined field_0x2b8;
    undefined field_0x2b9;
    undefined field_0x2ba;
    undefined field_0x2bb;
    undefined field_0x2bc;
    undefined field_0x2bd;
    undefined field_0x2be;
    undefined field_0x2bf;
    undefined field_0x2c0;
    undefined field_0x2c1;
    undefined field_0x2c2;
    undefined field_0x2c3;
    undefined field_0x2c4;
    undefined field_0x2c5;
    undefined field_0x2c6;
    undefined field_0x2c7;
    undefined field_0x2c8;
    undefined field_0x2c9;
    undefined field_0x2ca;
    undefined field_0x2cb;
    undefined field_0x2cc;
    undefined field_0x2cd;
    undefined field_0x2ce;
    undefined field_0x2cf;
    undefined field_0x2d0;
    undefined field_0x2d1;
    undefined field_0x2d2;
    undefined field_0x2d3;
    undefined field_0x2d4;
    undefined field_0x2d5;
    undefined field_0x2d6;
    undefined field_0x2d7;
    undefined field_0x2d8;
    undefined field_0x2d9;
    undefined field_0x2da;
    undefined field_0x2db;
    undefined field_0x2dc;
    undefined field_0x2dd;
    undefined field_0x2de;
    undefined field_0x2df;
    undefined field_0x2e0;
    undefined field_0x2e1;
    undefined field_0x2e2;
    undefined field_0x2e3;
    undefined field_0x2e4;
    undefined field_0x2e5;
    undefined field_0x2e6;
    undefined field_0x2e7;
    undefined field_0x2e8;
    undefined field_0x2e9;
    undefined field_0x2ea;
    undefined field_0x2eb;
    undefined field_0x2ec;
    undefined field_0x2ed;
    undefined field_0x2ee;
    undefined field_0x2ef;
    undefined field_0x2f0;
    undefined field_0x2f1;
    undefined field_0x2f2;
    undefined field_0x2f3;
    undefined field_0x2f4;
    undefined field_0x2f5;
    undefined field_0x2f6;
    undefined field_0x2f7;
    undefined field_0x2f8;
    undefined field_0x2f9;
    undefined field_0x2fa;
    undefined field_0x2fb;
    undefined field_0x2fc;
    undefined field_0x2fd;
    undefined field_0x2fe;
    undefined field_0x2ff;
    undefined field_0x300;
    undefined field_0x301;
    undefined field_0x302;
    undefined field_0x303;
    undefined field_0x304;
    undefined field_0x305;
    undefined field_0x306;
    undefined field_0x307;
    undefined field_0x308;
    undefined field_0x309;
    undefined field_0x30a;
    undefined field_0x30b;
    undefined field_0x30c;
    undefined field_0x30d;
    undefined field_0x30e;
    undefined field_0x30f;
    undefined field_0x310;
    undefined field_0x311;
    undefined field_0x312;
    undefined field_0x313;
    undefined field_0x314;
    undefined field_0x315;
    undefined field_0x316;
    undefined field_0x317;
    undefined field_0x318;
    undefined field_0x319;
    undefined field_0x31a;
    undefined field_0x31b;
    undefined field_0x31c;
    undefined field_0x31d;
    undefined field_0x31e;
    undefined field_0x31f;
    undefined field_0x320;
    undefined field_0x321;
    undefined field_0x322;
    undefined field_0x323;
    undefined field_0x324;
    undefined field_0x325;
    undefined field_0x326;
    undefined field_0x327;
    undefined field_0x328;
    undefined field_0x329;
    undefined field_0x32a;
    undefined field_0x32b;
    undefined field_0x32c;
    undefined field_0x32d;
    undefined field_0x32e;
    undefined field_0x32f;
    undefined field_0x330;
    undefined field_0x331;
    undefined field_0x332;
    undefined field_0x333;
    undefined field_0x334;
    undefined field_0x335;
    undefined field_0x336;
    undefined field_0x337;
    undefined field_0x338;
    undefined field_0x339;
    undefined field_0x33a;
    undefined field_0x33b;
    undefined field_0x33c;
    undefined field_0x33d;
    undefined field_0x33e;
    undefined field_0x33f;
    undefined field_0x340;
    undefined field_0x341;
    undefined field_0x342;
    undefined field_0x343;
    undefined field_0x344;
    undefined field_0x345;
    undefined field_0x346;
    undefined field_0x347;
    undefined field_0x348;
    undefined field_0x349;
    undefined field_0x34a;
    undefined field_0x34b;
    undefined field_0x34c;
    undefined field_0x34d;
    undefined field_0x34e;
    undefined field_0x34f;
    undefined field_0x350;
    undefined field_0x351;
    undefined field_0x352;
    undefined field_0x353;
    undefined field_0x354;
    undefined field_0x355;
    undefined field_0x356;
    undefined field_0x357;
    undefined field_0x358;
    undefined field_0x359;
    undefined field_0x35a;
    undefined field_0x35b;
    undefined field_0x35c;
    undefined field_0x35d;
    undefined field_0x35e;
    undefined field_0x35f;
    undefined field_0x360;
    undefined field_0x361;
    undefined field_0x362;
    undefined field_0x363;
    undefined field_0x364;
    undefined field_0x365;
    undefined field_0x366;
    undefined field_0x367;
    undefined field_0x368;
    undefined field_0x369;
    undefined field_0x36a;
    undefined field_0x36b;
    undefined field_0x36c;
    undefined field_0x36d;
    undefined field_0x36e;
    undefined field_0x36f;
    undefined field_0x370;
    undefined field_0x371;
    undefined field_0x372;
    undefined field_0x373;
    undefined field_0x374;
    undefined field_0x375;
    undefined field_0x376;
    undefined field_0x377;
    undefined field_0x378;
    undefined field_0x379;
    undefined field_0x37a;
    undefined field_0x37b;
    undefined field_0x37c;
    undefined field_0x37d;
    undefined field_0x37e;
    undefined field_0x37f;
    undefined field_0x380;
    undefined field_0x381;
    undefined field_0x382;
    undefined field_0x383;
    undefined field_0x384;
    undefined field_0x385;
    undefined field_0x386;
    undefined field_0x387;
    undefined field_0x388;
    undefined field_0x389;
    undefined field_0x38a;
    undefined field_0x38b;
    undefined field_0x38c;
    undefined field_0x38d;
    undefined field_0x38e;
    undefined field_0x38f;
    undefined field_0x390;
    undefined field_0x391;
    undefined field_0x392;
    undefined field_0x393;
    undefined field_0x394;
    undefined field_0x395;
    undefined field_0x396;
    undefined field_0x397;
    undefined field_0x398;
    undefined field_0x399;
    undefined field_0x39a;
    undefined field_0x39b;
    undefined field_0x39c;
    undefined field_0x39d;
    undefined field_0x39e;
    undefined field_0x39f;
    undefined field_0x3a0;
    undefined field_0x3a1;
    undefined field_0x3a2;
    undefined field_0x3a3;
    undefined field_0x3a4;
    undefined field_0x3a5;
    undefined field_0x3a6;
    undefined field_0x3a7;
    undefined field_0x3a8;
    undefined field_0x3a9;
    undefined field_0x3aa;
    undefined field_0x3ab;
    undefined field_0x3ac;
    undefined field_0x3ad;
    undefined field_0x3ae;
    undefined field_0x3af;
    undefined field_0x3b0;
    undefined field_0x3b1;
    undefined field_0x3b2;
    undefined field_0x3b3;
    undefined field_0x3b4;
    undefined field_0x3b5;
    undefined field_0x3b6;
    undefined field_0x3b7;
    undefined field_0x3b8;
    undefined field_0x3b9;
    undefined field_0x3ba;
    undefined field_0x3bb;
    undefined field_0x3bc;
    undefined field_0x3bd;
    undefined field_0x3be;
    undefined field_0x3bf;
    undefined field_0x3c0;
    undefined field_0x3c1;
    undefined field_0x3c2;
    undefined field_0x3c3;
    undefined field_0x3c4;
    undefined field_0x3c5;
    undefined field_0x3c6;
    undefined field_0x3c7;
    undefined field_0x3c8;
    undefined field_0x3c9;
    undefined field_0x3ca;
    undefined field_0x3cb;
    undefined field_0x3cc;
    undefined field_0x3cd;
    undefined field_0x3ce;
    undefined field_0x3cf;
    undefined field_0x3d0;
    undefined field_0x3d1;
    undefined field_0x3d2;
    undefined field_0x3d3;
    undefined field_0x3d4;
    undefined field_0x3d5;
    undefined field_0x3d6;
    undefined field_0x3d7;
    undefined field_0x3d8;
    undefined field_0x3d9;
    undefined field_0x3da;
    undefined field_0x3db;
    undefined field_0x3dc;
    undefined field_0x3dd;
    undefined field_0x3de;
    undefined field_0x3df;
    undefined field_0x3e0;
    undefined field_0x3e1;
    undefined field_0x3e2;
    undefined field_0x3e3;
    undefined field_0x3e4;
    undefined field_0x3e5;
    undefined field_0x3e6;
    undefined field_0x3e7;
    undefined field_0x3e8;
    undefined field_0x3e9;
    undefined field_0x3ea;
    undefined field_0x3eb;
    undefined field_0x3ec;
    undefined field_0x3ed;
    undefined field_0x3ee;
    undefined field_0x3ef;
    undefined field_0x3f0;
    undefined field_0x3f1;
    undefined field_0x3f2;
    undefined field_0x3f3;
    undefined field_0x3f4;
    undefined field_0x3f5;
    undefined field_0x3f6;
    undefined field_0x3f7;
    undefined field_0x3f8;
    undefined field_0x3f9;
    undefined field_0x3fa;
    undefined field_0x3fb;
    undefined field_0x3fc;
    undefined field_0x3fd;
    undefined field_0x3fe;
    undefined field_0x3ff;
    uint EXTIPSELL; // External Interrupt Port Select Low Register
    uint EXTIPSELH; // External Interrupt Port Select High Register
    uint EXTIPINSELL; // External Interrupt Pin Select Low Register
    uint EXTIPINSELH; // External Interrupt Pin Select High Register
    uint EXTIRISE; // External Interrupt Rising Edge Trigger Register
    uint EXTIFALL; // External Interrupt Falling Edge Trigger Register
    uint EXTILEVEL; // External Interrupt Level Register
    uint IF; // Interrupt Flag Register
    uint IFS; // Interrupt Flag Set Register
    uint IFC; // Interrupt Flag Clear Register
    uint IEN; // Interrupt Enable Register
    uint EM4WUEN; // EM4 Wake Up Enable Register
    undefined field_0x430;
    undefined field_0x431;
    undefined field_0x432;
    undefined field_0x433;
    undefined field_0x434;
    undefined field_0x435;
    undefined field_0x436;
    undefined field_0x437;
    undefined field_0x438;
    undefined field_0x439;
    undefined field_0x43a;
    undefined field_0x43b;
    undefined field_0x43c;
    undefined field_0x43d;
    undefined field_0x43e;
    undefined field_0x43f;
    uint ROUTEPEN; // I/O Routing Pin Enable Register
    uint ROUTELOC0; // I/O Routing Location Register
    undefined field_0x448;
    undefined field_0x449;
    undefined field_0x44a;
    undefined field_0x44b;
    undefined field_0x44c;
    undefined field_0x44d;
    undefined field_0x44e;
    undefined field_0x44f;
    uint INSENSE; // Input Sense Register
    uint LOCK; // Configuration Lock Register
};

typedef struct RAC_SET RAC_SET, *PRAC_SET;

struct RAC_SET {
    uint RXENSRCEN;
    uint STATUS;
    uint CMD;
    uint CTRL;
    uint FORCESTATE;
    uint IF;
    uint IFS;
    uint IFC;
    uint IEN;
    uint LVDSCTRL;
    uint LVDSIDLESEQ;
    uint LVDSROUTE;
    uint HFXORETIMECTRL;
    uint HFXORETIMESTATUS;
    uint TESTCTRL;
    uint SEQSTATUS;
    uint SEQCMD;
    uint BREAKPOINT;
    uint R0;
    uint R1;
    uint R2;
    uint R3;
    uint R4;
    uint R5;
    uint R6;
    uint R7;
    undefined field_0x68;
    undefined field_0x69;
    undefined field_0x6a;
    undefined field_0x6b;
    uint WAITMASK;
    uint WAITSNSH;
    uint STIMER;
    uint STIMERCOMP;
    uint VECTADDR;
    uint SEQCTRL;
    uint PRESC;
    uint SR0;
    uint SR1;
    uint SR2;
    uint SR3;
    uint SYNTHENCTRL;
    uint SYNTHREGCTRL;
    uint VCOCTRL;
    uint MMDCTRL;
    undefined field_0xa8;
    undefined field_0xa9;
    undefined field_0xaa;
    undefined field_0xab;
    undefined field_0xac;
    undefined field_0xad;
    undefined field_0xae;
    undefined field_0xaf;
    uint CHPCTRL;
    uint CHPCAL;
    uint LPFCTRL;
    uint SYNTHCTRL;
    uint AUXCTRL;
    uint AUXENCTRL;
    undefined field_0xc8;
    undefined field_0xc9;
    undefined field_0xca;
    undefined field_0xcb;
    undefined field_0xcc;
    undefined field_0xcd;
    undefined field_0xce;
    undefined field_0xcf;
    undefined field_0xd0;
    undefined field_0xd1;
    undefined field_0xd2;
    undefined field_0xd3;
    undefined field_0xd4;
    undefined field_0xd5;
    undefined field_0xd6;
    undefined field_0xd7;
    undefined field_0xd8;
    undefined field_0xd9;
    undefined field_0xda;
    undefined field_0xdb;
    undefined field_0xdc;
    undefined field_0xdd;
    undefined field_0xde;
    undefined field_0xdf;
    undefined field_0xe0;
    undefined field_0xe1;
    undefined field_0xe2;
    undefined field_0xe3;
    undefined field_0xe4;
    undefined field_0xe5;
    undefined field_0xe6;
    undefined field_0xe7;
    undefined field_0xe8;
    undefined field_0xe9;
    undefined field_0xea;
    undefined field_0xeb;
    undefined field_0xec;
    undefined field_0xed;
    undefined field_0xee;
    undefined field_0xef;
    undefined field_0xf0;
    undefined field_0xf1;
    undefined field_0xf2;
    undefined field_0xf3;
    uint RFENCTRL;
    uint RFENCTRL0;
    uint LNAMIXCTRL;
    uint PACTRL0;
    uint PAPKDCTRL;
    uint PABIASCTRL0;
    uint PABIASCTRL1;
    uint SGRFENCTRL0;
    uint SGLNAMIXCTRL;
    uint SGPACTRL0;
    uint SGPAPKDCTRL;
    uint SGPABIASCTRL0;
    uint SGPABIASCTRL1;
    uint RFSTATUS;
    uint RFBIASCTRL;
    uint RFBIASCAL;
    uint LNAMIXCTRL1;
    uint IFPGACTRL;
    uint IFPGACAL;
    uint IFFILTCTRL;
    uint IFADCCTRL;
    uint IFADCCAL;
    uint PAENCTRL;
    uint PACTUNECTRL;
    uint RCTUNE;
    uint APC;
    uint SPARE;
};

typedef struct CRC_CLR CRC_CLR, *PCRC_CLR;

struct CRC_CLR {
    uint CTRL;
    uint STATUS;
    uint CMD;
    uint INPUTDATA;
    uint INIT;
    uint DATA;
    uint POLY;
};

typedef struct RAC RAC, *PRAC;

struct RAC {
    uint RXENSRCEN;
    uint STATUS;
    uint CMD;
    uint CTRL;
    uint FORCESTATE;
    uint IF;
    uint IFS;
    uint IFC;
    uint IEN;
    uint LVDSCTRL;
    uint LVDSIDLESEQ;
    uint LVDSROUTE;
    uint HFXORETIMECTRL;
    uint HFXORETIMESTATUS;
    uint TESTCTRL;
    uint SEQSTATUS;
    uint SEQCMD;
    uint BREAKPOINT;
    uint R0;
    uint R1;
    uint R2;
    uint R3;
    uint R4;
    uint R5;
    uint R6;
    uint R7;
    undefined field_0x68;
    undefined field_0x69;
    undefined field_0x6a;
    undefined field_0x6b;
    uint WAITMASK;
    uint WAITSNSH;
    uint STIMER;
    uint STIMERCOMP;
    uint VECTADDR;
    uint SEQCTRL;
    uint PRESC;
    uint SR0;
    uint SR1;
    uint SR2;
    uint SR3;
    uint SYNTHENCTRL;
    uint SYNTHREGCTRL;
    uint VCOCTRL;
    uint MMDCTRL;
    undefined field_0xa8;
    undefined field_0xa9;
    undefined field_0xaa;
    undefined field_0xab;
    undefined field_0xac;
    undefined field_0xad;
    undefined field_0xae;
    undefined field_0xaf;
    uint CHPCTRL;
    uint CHPCAL;
    uint LPFCTRL;
    uint SYNTHCTRL;
    uint AUXCTRL;
    uint AUXENCTRL;
    undefined field_0xc8;
    undefined field_0xc9;
    undefined field_0xca;
    undefined field_0xcb;
    undefined field_0xcc;
    undefined field_0xcd;
    undefined field_0xce;
    undefined field_0xcf;
    undefined field_0xd0;
    undefined field_0xd1;
    undefined field_0xd2;
    undefined field_0xd3;
    undefined field_0xd4;
    undefined field_0xd5;
    undefined field_0xd6;
    undefined field_0xd7;
    undefined field_0xd8;
    undefined field_0xd9;
    undefined field_0xda;
    undefined field_0xdb;
    undefined field_0xdc;
    undefined field_0xdd;
    undefined field_0xde;
    undefined field_0xdf;
    undefined field_0xe0;
    undefined field_0xe1;
    undefined field_0xe2;
    undefined field_0xe3;
    undefined field_0xe4;
    undefined field_0xe5;
    undefined field_0xe6;
    undefined field_0xe7;
    undefined field_0xe8;
    undefined field_0xe9;
    undefined field_0xea;
    undefined field_0xeb;
    undefined field_0xec;
    undefined field_0xed;
    undefined field_0xee;
    undefined field_0xef;
    undefined field_0xf0;
    undefined field_0xf1;
    undefined field_0xf2;
    undefined field_0xf3;
    uint RFENCTRL;
    uint RFENCTRL0;
    uint LNAMIXCTRL;
    uint PACTRL0;
    uint PAPKDCTRL;
    uint PABIASCTRL0;
    uint PABIASCTRL1;
    uint SGRFENCTRL0;
    uint SGLNAMIXCTRL;
    uint SGPACTRL0;
    uint SGPAPKDCTRL;
    uint SGPABIASCTRL0;
    uint SGPABIASCTRL1;
    uint RFSTATUS;
    uint RFBIASCTRL;
    uint RFBIASCAL;
    uint LNAMIXCTRL1;
    uint IFPGACTRL;
    uint IFPGACAL;
    uint IFFILTCTRL;
    uint IFADCCTRL;
    uint IFADCCAL;
    uint PAENCTRL;
    uint PACTUNECTRL;
    uint RCTUNE;
    uint APC;
    uint SPARE;
};

typedef struct CMU_CLR CMU_CLR, *PCMU_CLR;

struct CMU_CLR {
    uint CTRL; // CMU Control Register
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    undefined field_0x8;
    undefined field_0x9;
    undefined field_0xa;
    undefined field_0xb;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    uint HFRCOCTRL; // HFRCO Control Register
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    uint AUXHFRCOCTRL; // AUXHFRCO Control Register
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    uint LFRCOCTRL; // LFRCO Control Register
    uint HFXOCTRL; // HFXO Control Register
    uint HFXOCTRL1; // HFXO Control 1
    uint HFXOSTARTUPCTRL; // HFXO Startup Control
    uint HFXOSTEADYSTATECTRL; // HFXO Steady State Control
    uint HFXOTIMEOUTCTRL; // HFXO Timeout Control
    uint LFXOCTRL; // LFXO Control Register
    uint ULFRCOCTRL; // ULFRCO Control Register
    undefined field_0x40;
    undefined field_0x41;
    undefined field_0x42;
    undefined field_0x43;
    undefined field_0x44;
    undefined field_0x45;
    undefined field_0x46;
    undefined field_0x47;
    undefined field_0x48;
    undefined field_0x49;
    undefined field_0x4a;
    undefined field_0x4b;
    undefined field_0x4c;
    undefined field_0x4d;
    undefined field_0x4e;
    undefined field_0x4f;
    uint CALCTRL; // Calibration Control Register
    uint CALCNT; // Calibration Counter Register
    undefined field_0x58;
    undefined field_0x59;
    undefined field_0x5a;
    undefined field_0x5b;
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    uint OSCENCMD; // Oscillator Enable/Disable Command Register
    uint CMD; // Command Register
    undefined field_0x68;
    undefined field_0x69;
    undefined field_0x6a;
    undefined field_0x6b;
    undefined field_0x6c;
    undefined field_0x6d;
    undefined field_0x6e;
    undefined field_0x6f;
    uint DBGCLKSEL; // Debug Trace Clock Select
    uint HFCLKSEL; // High Frequency Clock Select Command Register
    undefined field_0x78;
    undefined field_0x79;
    undefined field_0x7a;
    undefined field_0x7b;
    undefined field_0x7c;
    undefined field_0x7d;
    undefined field_0x7e;
    undefined field_0x7f;
    uint LFACLKSEL; // Low Frequency A Clock Select Register
    uint LFBCLKSEL; // Low Frequency B Clock Select Register
    uint LFECLKSEL; // Low Frequency E Clock Select Register
    undefined field_0x8c;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
    uint STATUS; // Status Register
    uint HFCLKSTATUS; // HFCLK Status Register
    undefined field_0x98;
    undefined field_0x99;
    undefined field_0x9a;
    undefined field_0x9b;
    uint HFXOTRIMSTATUS; // HFXO Trim Status
    uint IF; // Interrupt Flag Register
    uint IFS; // Interrupt Flag Set Register
    uint IFC; // Interrupt Flag Clear Register
    uint IEN; // Interrupt Enable Register
    uint HFBUSCLKEN0; // High Frequency Bus Clock Enable Register 0
    undefined field_0xb4;
    undefined field_0xb5;
    undefined field_0xb6;
    undefined field_0xb7;
    undefined field_0xb8;
    undefined field_0xb9;
    undefined field_0xba;
    undefined field_0xbb;
    undefined field_0xbc;
    undefined field_0xbd;
    undefined field_0xbe;
    undefined field_0xbf;
    uint HFPERCLKEN0; // High Frequency Peripheral Clock Enable Register 0
    undefined field_0xc4;
    undefined field_0xc5;
    undefined field_0xc6;
    undefined field_0xc7;
    uint HFRADIOCLKEN0; // High Frequency Peripheral Clock Enable Register 0
    undefined field_0xcc;
    undefined field_0xcd;
    undefined field_0xce;
    undefined field_0xcf;
    undefined field_0xd0;
    undefined field_0xd1;
    undefined field_0xd2;
    undefined field_0xd3;
    undefined field_0xd4;
    undefined field_0xd5;
    undefined field_0xd6;
    undefined field_0xd7;
    undefined field_0xd8;
    undefined field_0xd9;
    undefined field_0xda;
    undefined field_0xdb;
    undefined field_0xdc;
    undefined field_0xdd;
    undefined field_0xde;
    undefined field_0xdf;
    uint LFACLKEN0; // Low Frequency a Clock Enable Register 0 (Async Reg)
    undefined field_0xe4;
    undefined field_0xe5;
    undefined field_0xe6;
    undefined field_0xe7;
    uint LFBCLKEN0; // Low Frequency B Clock Enable Register 0 (Async Reg)
    undefined field_0xec;
    undefined field_0xed;
    undefined field_0xee;
    undefined field_0xef;
    uint LFECLKEN0; // Low Frequency E Clock Enable Register 0 (Async Reg)
    undefined field_0xf4;
    undefined field_0xf5;
    undefined field_0xf6;
    undefined field_0xf7;
    undefined field_0xf8;
    undefined field_0xf9;
    undefined field_0xfa;
    undefined field_0xfb;
    undefined field_0xfc;
    undefined field_0xfd;
    undefined field_0xfe;
    undefined field_0xff;
    uint HFPRESC; // High Frequency Clock Prescaler Register
    undefined field_0x104;
    undefined field_0x105;
    undefined field_0x106;
    undefined field_0x107;
    uint HFCOREPRESC; // High Frequency Core Clock Prescaler Register
    uint HFPERPRESC; // High Frequency Peripheral Clock Prescaler Register
    uint HFRADIOPRESC; // Radio Clock Prescaler Register
    uint HFEXPPRESC; // High Frequency Export Clock Prescaler Register
    undefined field_0x118;
    undefined field_0x119;
    undefined field_0x11a;
    undefined field_0x11b;
    undefined field_0x11c;
    undefined field_0x11d;
    undefined field_0x11e;
    undefined field_0x11f;
    uint LFAPRESC0; // Low Frequency a Prescaler Register 0 (Async Reg)
    undefined field_0x124;
    undefined field_0x125;
    undefined field_0x126;
    undefined field_0x127;
    uint LFBPRESC0; // Low Frequency B Prescaler Register 0 (Async Reg)
    undefined field_0x12c;
    undefined field_0x12d;
    undefined field_0x12e;
    undefined field_0x12f;
    uint LFEPRESC0; // Low Frequency E Prescaler Register 0 (Async Reg)
    undefined field_0x134;
    undefined field_0x135;
    undefined field_0x136;
    undefined field_0x137;
    undefined field_0x138;
    undefined field_0x139;
    undefined field_0x13a;
    undefined field_0x13b;
    undefined field_0x13c;
    undefined field_0x13d;
    undefined field_0x13e;
    undefined field_0x13f;
    uint SYNCBUSY; // Synchronization Busy Register
    uint FREEZE; // Freeze Register
    undefined field_0x148;
    undefined field_0x149;
    undefined field_0x14a;
    undefined field_0x14b;
    undefined field_0x14c;
    undefined field_0x14d;
    undefined field_0x14e;
    undefined field_0x14f;
    uint PCNTCTRL; // PCNT Control Register
    uint LCDCTRL; // LCD Control Register
    uint LVDSCTRL; // LVDSCTRL Control Register
    uint ADCCTRL; // ADC Control Register
    undefined field_0x160;
    undefined field_0x161;
    undefined field_0x162;
    undefined field_0x163;
    undefined field_0x164;
    undefined field_0x165;
    undefined field_0x166;
    undefined field_0x167;
    undefined field_0x168;
    undefined field_0x169;
    undefined field_0x16a;
    undefined field_0x16b;
    undefined field_0x16c;
    undefined field_0x16d;
    undefined field_0x16e;
    undefined field_0x16f;
    uint ROUTEPEN; // I/O Routing Pin Enable Register
    uint ROUTELOC0; // I/O Routing Location Register
    undefined field_0x178;
    undefined field_0x179;
    undefined field_0x17a;
    undefined field_0x17b;
    undefined field_0x17c;
    undefined field_0x17d;
    undefined field_0x17e;
    undefined field_0x17f;
    uint LOCK; // Configuration Lock Register
    undefined field_0x184;
    undefined field_0x185;
    undefined field_0x186;
    undefined field_0x187;
    uint RFLOCK0; // RF LOCK Register
    undefined field_0x18c;
    undefined field_0x18d;
    undefined field_0x18e;
    undefined field_0x18f;
    uint HFBUSCLKENMASK0;
    undefined field_0x194;
    undefined field_0x195;
    undefined field_0x196;
    undefined field_0x197;
    uint HFPERCLKENMASK0;
    undefined field_0x19c;
    undefined field_0x19d;
    undefined field_0x19e;
    undefined field_0x19f;
    undefined field_0x1a0;
    undefined field_0x1a1;
    undefined field_0x1a2;
    undefined field_0x1a3;
    uint HFRADIOCLKENMASK0;
    undefined field_0x1a8;
    undefined field_0x1a9;
    undefined field_0x1aa;
    undefined field_0x1ab;
    undefined field_0x1ac;
    undefined field_0x1ad;
    undefined field_0x1ae;
    undefined field_0x1af;
    undefined field_0x1b0;
    undefined field_0x1b1;
    undefined field_0x1b2;
    undefined field_0x1b3;
    uint LFACLKENMASK0;
    undefined field_0x1b8;
    undefined field_0x1b9;
    undefined field_0x1ba;
    undefined field_0x1bb;
    uint LFBCLKENMASK0;
    undefined field_0x1c0;
    undefined field_0x1c1;
    undefined field_0x1c2;
    undefined field_0x1c3;
    uint LFECLKENMASK0;
    undefined field_0x1c8;
    undefined field_0x1c9;
    undefined field_0x1ca;
    undefined field_0x1cb;
    uint PCNTCLKENMASK;
    uint TEST;
    uint TESTHFRCOCTRL;
    uint TESTAUXHFRCOCTRL;
    uint TESTLFRCOCTRL;
    uint TESTHFXOCTRL;
    uint TESTLFXOCTRL;
};

typedef struct FRC FRC, *PFRC;

struct FRC {
    uint STATUS;
    uint DFLCTRL;
    uint MAXLENGTH;
    uint ADDRFILTCTRL;
    uint DATABUFFER;
    uint WCNT;
    uint WCNTCMP0;
    uint WCNTCMP1;
    uint WCNTCMP2;
    uint CMD;
    uint WHITECTRL;
    uint WHITEPOLY;
    uint WHITEINIT;
    uint FECCTRL;
    uint BLOCKRAMADDR;
    uint CONVRAMADDR;
    uint CTRL;
    uint RXCTRL;
    uint TRAILTXDATACTRL;
    uint TRAILRXDATA;
    uint SCNT;
    uint CONVGENERATOR;
    uint PUNCTCTRL;
    uint PAUSECTRL;
    uint IF;
    uint IFS;
    uint IFC;
    uint IEN;
    uint BUFFERMODE;
    uint ROUTEPEN;
    uint ROUTELOC0;
    uint SNIFFCTRL;
    uint AUXDATA;
    uint RAWCTRL;
    uint RXRAWDATA;
    uint PAUSEDATA;
    uint LIKELYCONVSTATE;
    uint INTELEMENTNEXT;
    uint INTWRITEPOINT;
    uint INTREADPOINT;
    uint FCD0;
    uint FCD1;
    uint FCD2;
    uint FCD3;
    undefined field_0xb0;
    undefined field_0xb1;
    undefined field_0xb2;
    undefined field_0xb3;
    undefined field_0xb4;
    undefined field_0xb5;
    undefined field_0xb6;
    undefined field_0xb7;
    undefined field_0xb8;
    undefined field_0xb9;
    undefined field_0xba;
    undefined field_0xbb;
    undefined field_0xbc;
    undefined field_0xbd;
    undefined field_0xbe;
    undefined field_0xbf;
    uint INTELEMENT0;
    uint INTELEMENT1;
    uint INTELEMENT2;
    uint INTELEMENT3;
    uint INTELEMENT4;
    uint INTELEMENT5;
    uint INTELEMENT6;
    uint INTELEMENT7;
    uint INTELEMENT8;
    uint INTELEMENT9;
    uint INTELEMENT10;
    uint INTELEMENT11;
    uint INTELEMENT12;
    uint INTELEMENT13;
    uint INTELEMENT14;
    uint INTELEMENT15;
};

typedef struct IDAC0 IDAC0, *PIDAC0;

struct IDAC0 {
    uint CTRL; // Control Register
    uint CURPROG; // Current Programming Register
    undefined field_0x8;
    undefined field_0x9;
    undefined field_0xa;
    undefined field_0xb;
    uint DUTYCONFIG; // Duty Cycle Configuration Register
    undefined field_0x10;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    uint STATUS; // Status Register
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    uint IF; // Interrupt Flag Register
    uint IFS; // Interrupt Flag Set Register
    uint IFC; // Interrupt Flag Clear Register
    uint IEN; // Interrupt Enable Register
    undefined field_0x30;
    undefined field_0x31;
    undefined field_0x32;
    undefined field_0x33;
    uint APORTREQ; // APORT Request Status Register
    uint APORTCONFLICT; // APORT Request Status Register
};

typedef struct RMU RMU, *PRMU;

struct RMU {
    uint CTRL; // Control Register
    uint RSTCAUSE; // Reset Cause Register
    uint CMD; // Command Register
    uint RST; // Reset Control Register
    uint LOCK; // Configuration Lock Register
};

typedef struct FRC_CLR FRC_CLR, *PFRC_CLR;

struct FRC_CLR {
    uint STATUS;
    uint DFLCTRL;
    uint MAXLENGTH;
    uint ADDRFILTCTRL;
    uint DATABUFFER;
    uint WCNT;
    uint WCNTCMP0;
    uint WCNTCMP1;
    uint WCNTCMP2;
    uint CMD;
    uint WHITECTRL;
    uint WHITEPOLY;
    uint WHITEINIT;
    uint FECCTRL;
    uint BLOCKRAMADDR;
    uint CONVRAMADDR;
    uint CTRL;
    uint RXCTRL;
    uint TRAILTXDATACTRL;
    uint TRAILRXDATA;
    uint SCNT;
    uint CONVGENERATOR;
    uint PUNCTCTRL;
    uint PAUSECTRL;
    uint IF;
    uint IFS;
    uint IFC;
    uint IEN;
    uint BUFFERMODE;
    uint ROUTEPEN;
    uint ROUTELOC0;
    uint SNIFFCTRL;
    uint AUXDATA;
    uint RAWCTRL;
    uint RXRAWDATA;
    uint PAUSEDATA;
    uint LIKELYCONVSTATE;
    uint INTELEMENTNEXT;
    uint INTWRITEPOINT;
    uint INTREADPOINT;
    uint FCD0;
    uint FCD1;
    uint FCD2;
    uint FCD3;
    undefined field_0xb0;
    undefined field_0xb1;
    undefined field_0xb2;
    undefined field_0xb3;
    undefined field_0xb4;
    undefined field_0xb5;
    undefined field_0xb6;
    undefined field_0xb7;
    undefined field_0xb8;
    undefined field_0xb9;
    undefined field_0xba;
    undefined field_0xbb;
    undefined field_0xbc;
    undefined field_0xbd;
    undefined field_0xbe;
    undefined field_0xbf;
    uint INTELEMENT0;
    uint INTELEMENT1;
    uint INTELEMENT2;
    uint INTELEMENT3;
    uint INTELEMENT4;
    uint INTELEMENT5;
    uint INTELEMENT6;
    uint INTELEMENT7;
    uint INTELEMENT8;
    uint INTELEMENT9;
    uint INTELEMENT10;
    uint INTELEMENT11;
    uint INTELEMENT12;
    uint INTELEMENT13;
    uint INTELEMENT14;
    uint INTELEMENT15;
};

typedef struct PROTIMER_SET PROTIMER_SET, *PPROTIMER_SET;

struct PROTIMER_SET {
    uint CTRL;
    uint CMD;
    uint PRSCTRL;
    uint STATUS;
    uint PRECNT;
    uint BASECNT;
    uint WRAPCNT;
    uint BASEPRE;
    uint LWRAPCNT;
    uint PRECNTTOPADJ;
    uint PRECNTTOP;
    uint BASECNTTOP;
    uint WRAPCNTTOP;
    uint TOUT0CNT;
    uint TOUT0CNTTOP;
    uint TOUT0COMP;
    uint TOUT1CNT;
    uint TOUT1CNTTOP;
    uint TOUT1COMP;
    uint LBTCTRL;
    uint LBTPRSCTRL;
    uint LBTSTATE;
    uint RANDOM;
    uint IF;
    uint IFS;
    uint IFC;
    uint IEN;
    uint RXCTRL;
    uint TXCTRL;
    uint CC0_CTRL;
    uint CC0_PRE;
    uint CC0_BASE;
    uint CC0_WRAP;
    uint CC1_CTRL;
    uint CC1_PRE;
    uint CC1_BASE;
    uint CC1_WRAP;
    uint CC2_CTRL;
    uint CC2_PRE;
    uint CC2_BASE;
    uint CC2_WRAP;
    uint CC3_CTRL;
    uint CC3_PRE;
    uint CC3_BASE;
    uint CC3_WRAP;
    uint CC4_CTRL;
    uint CC4_PRE;
    uint CC4_BASE;
    uint CC4_WRAP;
};

typedef struct SYNTH_CLR SYNTH_CLR, *PSYNTH_CLR;

struct SYNTH_CLR {
    uint STATUS;
    uint CMD;
    uint CTRL;
    uint CALCTRL;
    undefined field_0x10;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    undefined field_0x18;
    undefined field_0x19;
    undefined field_0x1a;
    undefined field_0x1b;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    undefined field_0x20;
    undefined field_0x21;
    undefined field_0x22;
    undefined field_0x23;
    uint VCDACCTRL;
    undefined field_0x28;
    undefined field_0x29;
    undefined field_0x2a;
    undefined field_0x2b;
    uint FREQ;
    uint IFFREQ;
    uint DIVCTRL;
    uint CHCTRL;
    uint CHSP;
    uint CALOFFSET;
    uint VCOTUNING;
    undefined field_0x48;
    undefined field_0x49;
    undefined field_0x4a;
    undefined field_0x4b;
    uint VCORANGE;
    uint VCOGAIN;
    uint AUXVCOTUNING;
    uint AUXFREQ;
    uint AUXVCDACCTRL;
    uint CHPDACCTRL;
    uint CAPCALCYCLECNT;
    undefined field_0x68;
    undefined field_0x69;
    undefined field_0x6a;
    undefined field_0x6b;
    undefined field_0x6c;
    undefined field_0x6d;
    undefined field_0x6e;
    undefined field_0x6f;
    uint IF;
    uint IFS;
    uint IFC;
    uint IEN;
};

typedef enum Elf_SectionHeaderType_ARM {
    SHT_ANDROID_REL=1610612737,
    SHT_ANDROID_RELA=1610612738,
    SHT_ARM_ATTRIBUTES=1879048195,
    SHT_ARM_DEBUGOVERLAY=1879048196,
    SHT_ARM_EXIDX=1879048193,
    SHT_ARM_OVERLAYSECTION=1879048197,
    SHT_ARM_PREEMPTMAP=1879048194,
    SHT_CHECKSUM=1879048184,
    SHT_DYNAMIC=6,
    SHT_DYNSYM=11,
    SHT_FINI_ARRAY=15,
    SHT_GNU_ATTRIBUTES=1879048181,
    SHT_GNU_HASH=1879048182,
    SHT_GNU_LIBLIST=1879048183,
    SHT_GNU_verdef=1879048189,
    SHT_GNU_verneed=1879048190,
    SHT_GNU_versym=1879048191,
    SHT_GROUP=17,
    SHT_HASH=5,
    SHT_INIT_ARRAY=14,
    SHT_NOBITS=8,
    SHT_NOTE=7,
    SHT_NULL=0,
    SHT_PREINIT_ARRAY=16,
    SHT_PROGBITS=1,
    SHT_REL=9,
    SHT_RELA=4,
    SHT_SHLIB=10,
    SHT_STRTAB=3,
    SHT_SUNW_COMDAT=1879048187,
    SHT_SUNW_move=1879048186,
    SHT_SUNW_syminfo=1879048188,
    SHT_SYMTAB=2,
    SHT_SYMTAB_SHNDX=18
} Elf_SectionHeaderType_ARM;

typedef struct Elf32_Sym Elf32_Sym, *PElf32_Sym;

struct Elf32_Sym {
    dword st_name;
    dword st_value;
    dword st_size;
    byte st_info;
    byte st_other;
    word st_shndx;
};

typedef struct Elf32_Shdr Elf32_Shdr, *PElf32_Shdr;

struct Elf32_Shdr {
    dword sh_name;
    enum Elf_SectionHeaderType_ARM sh_type;
    dword sh_flags;
    dword sh_addr;
    dword sh_offset;
    dword sh_size;
    dword sh_link;
    dword sh_info;
    dword sh_addralign;
    dword sh_entsize;
};

typedef struct Elf32_Ehdr Elf32_Ehdr, *PElf32_Ehdr;

struct Elf32_Ehdr {
    byte e_ident_magic_num;
    char e_ident_magic_str[3];
    byte e_ident_class;
    byte e_ident_data;
    byte e_ident_version;
    byte e_ident_osabi;
    byte e_ident_abiversion;
    byte e_ident_pad[7];
    word e_type;
    word e_machine;
    dword e_version;
    dword e_entry;
    dword e_phoff;
    dword e_shoff;
    dword e_flags;
    word e_ehsize;
    word e_phentsize;
    word e_phnum;
    word e_shentsize;
    word e_shnum;
    word e_shstrndx;
};




void TEMPCAL_Init(void);
void TEMPCAL_Perform(void);

