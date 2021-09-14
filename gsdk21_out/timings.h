typedef unsigned char   undefined;

typedef unsigned char    uint8_t;
typedef unsigned int    dword;
typedef unsigned int    uint32_t;
typedef unsigned char    undefined1;
typedef unsigned int    undefined4;
typedef unsigned int16_t    word;
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
    uint32_t CTRL; // Control Register
    uint32_t CMD; // Command Register
    uint32_t SYNCBUSY; // Synchronization Busy Register
    uint32_t PCH0_PRSCTRL; // PRS Control Register
    uint32_t PCH1_PRSCTRL; // PRS Control Register
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    undefined field_0x18;
    undefined field_0x19;
    undefined field_0x1a;
    undefined field_0x1b;
    uint32_t IF; // Watchdog Interrupt Flags
    uint32_t IFS; // Interrupt Flag Set Register
    uint32_t IFC; // Interrupt Flag Clear Register
    uint32_t IEN; // Interrupt Enable Register
};

typedef struct LETIMER0 LETIMER0, *PLETIMER0;

struct LETIMER0 {
    uint32_t CTRL; // Control Register
    uint32_t CMD; // Command Register
    uint32_t STATUS; // Status Register
    uint32_t CNT; // Counter Value Register
    uint32_t COMP0; // Compare Value Register 0
    uint32_t COMP1; // Compare Value Register 1
    uint32_t REP0; // Repeat Counter Register 0
    uint32_t REP1; // Repeat Counter Register 1
    uint32_t IF; // Interrupt Flag Register
    uint32_t IFS; // Interrupt Flag Set Register
    uint32_t IFC; // Interrupt Flag Clear Register
    uint32_t IEN; // Interrupt Enable Register
    undefined field_0x30;
    undefined field_0x31;
    undefined field_0x32;
    undefined field_0x33;
    uint32_t SYNCBUSY; // Synchronization Busy Register
    undefined field_0x38;
    undefined field_0x39;
    undefined field_0x3a;
    undefined field_0x3b;
    undefined field_0x3c;
    undefined field_0x3d;
    undefined field_0x3e;
    undefined field_0x3f;
    uint32_t ROUTEPEN; // I/O Routing Pin Enable Register
    uint32_t ROUTELOC0; // I/O Routing Location Register
    undefined field_0x48;
    undefined field_0x49;
    undefined field_0x4a;
    undefined field_0x4b;
    undefined field_0x4c;
    undefined field_0x4d;
    undefined field_0x4e;
    undefined field_0x4f;
    uint32_t PRSSEL; // PRS Input Select Register
};

typedef struct RTCC RTCC, *PRTCC;

struct RTCC {
    uint32_t CTRL; // Control Register
    uint32_t PRECNT; // Pre-Counter Value Register
    uint32_t CNT; // Counter Value Register
    uint32_t COMBCNT; // Combined Pre-Counter and Counter Value Register
    uint32_t TIME; // Time of Day Register
    uint32_t DATE; // Date Register
    uint32_t IF; // RTCC Interrupt Flags
    uint32_t IFS; // Interrupt Flag Set Register
    uint32_t IFC; // Interrupt Flag Clear Register
    uint32_t IEN; // Interrupt Enable Register
    uint32_t STATUS; // Status Register
    uint32_t CMD; // Command Register
    uint32_t SYNCBUSY; // Synchronization Busy Register
    uint32_t POWERDOWN; // Retention RAM Power-down Register
    uint32_t LOCK; // Configuration Lock Register
    uint32_t EM4WUEN; // Wake Up Enable
    uint32_t CC0_CTRL; // CC Channel Control Register
    uint32_t CC0_CCV; // Capture/Compare Value Register
    uint32_t CC0_TIME; // Capture/Compare Time Register
    uint32_t CC0_DATE; // Capture/Compare Date Register
    uint32_t CC1_CTRL; // CC Channel Control Register
    uint32_t CC1_CCV; // Capture/Compare Value Register
    uint32_t CC1_TIME; // Capture/Compare Time Register
    uint32_t CC1_DATE; // Capture/Compare Date Register
    uint32_t CC2_CTRL; // CC Channel Control Register
    uint32_t CC2_CCV; // Capture/Compare Value Register
    uint32_t CC2_TIME; // Capture/Compare Time Register
    uint32_t CC2_DATE; // Capture/Compare Date Register
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
    uint32_t RET0_REG; // Retention Register
    uint32_t RET1_REG; // Retention Register
    uint32_t RET2_REG; // Retention Register
    uint32_t RET3_REG; // Retention Register
    uint32_t RET4_REG; // Retention Register
    uint32_t RET5_REG; // Retention Register
    uint32_t RET6_REG; // Retention Register
    uint32_t RET7_REG; // Retention Register
    uint32_t RET8_REG; // Retention Register
    uint32_t RET9_REG; // Retention Register
    uint32_t RET10_REG; // Retention Register
    uint32_t RET11_REG; // Retention Register
    uint32_t RET12_REG; // Retention Register
    uint32_t RET13_REG; // Retention Register
    uint32_t RET14_REG; // Retention Register
    uint32_t RET15_REG; // Retention Register
    uint32_t RET16_REG; // Retention Register
    uint32_t RET17_REG; // Retention Register
    uint32_t RET18_REG; // Retention Register
    uint32_t RET19_REG; // Retention Register
    uint32_t RET20_REG; // Retention Register
    uint32_t RET21_REG; // Retention Register
    uint32_t RET22_REG; // Retention Register
    uint32_t RET23_REG; // Retention Register
    uint32_t RET24_REG; // Retention Register
    uint32_t RET25_REG; // Retention Register
    uint32_t RET26_REG; // Retention Register
    uint32_t RET27_REG; // Retention Register
    uint32_t RET28_REG; // Retention Register
    uint32_t RET29_REG; // Retention Register
    uint32_t RET30_REG; // Retention Register
    uint32_t RET31_REG; // Retention Register
};

typedef struct SYNTH_SET SYNTH_SET, *PSYNTH_SET;

struct SYNTH_SET {
    uint32_t STATUS;
    uint32_t CMD;
    uint32_t CTRL;
    uint32_t CALCTRL;
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
    uint32_t VCDACCTRL;
    undefined field_0x28;
    undefined field_0x29;
    undefined field_0x2a;
    undefined field_0x2b;
    uint32_t FREQ;
    uint32_t IFFREQ;
    uint32_t DIVCTRL;
    uint32_t CHCTRL;
    uint32_t CHSP;
    uint32_t CALOFFSET;
    uint32_t VCOTUNING;
    undefined field_0x48;
    undefined field_0x49;
    undefined field_0x4a;
    undefined field_0x4b;
    uint32_t VCORANGE;
    uint32_t VCOGAIN;
    uint32_t AUXVCOTUNING;
    uint32_t AUXFREQ;
    uint32_t AUXVCDACCTRL;
    uint32_t CHPDACCTRL;
    uint32_t CAPCALCYCLECNT;
    undefined field_0x68;
    undefined field_0x69;
    undefined field_0x6a;
    undefined field_0x6b;
    undefined field_0x6c;
    undefined field_0x6d;
    undefined field_0x6e;
    undefined field_0x6f;
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
};

typedef struct PRS PRS, *PPRS;

struct PRS {
    uint32_t SWPULSE; // Software Pulse Register
    uint32_t SWLEVEL; // Software Level Register
    uint32_t ROUTEPEN; // I/O Routing Pin Enable Register
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    uint32_t ROUTELOC0; // I/O Routing Location Register
    uint32_t ROUTELOC1; // I/O Routing Location Register
    uint32_t ROUTELOC2; // I/O Routing Location Register
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    uint32_t CTRL; // Control Register
    uint32_t DMAREQ0; // DMA Request 0 Register
    uint32_t DMAREQ1; // DMA Request 1 Register
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    uint32_t PEEK; // PRS Channel Values
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
    uint32_t CH0_CTRL; // Channel Control Register
    uint32_t CH1_CTRL; // Channel Control Register
    uint32_t CH2_CTRL; // Channel Control Register
    uint32_t CH3_CTRL; // Channel Control Register
    uint32_t CH4_CTRL; // Channel Control Register
    uint32_t CH5_CTRL; // Channel Control Register
    uint32_t CH6_CTRL; // Channel Control Register
    uint32_t CH7_CTRL; // Channel Control Register
    uint32_t CH8_CTRL; // Channel Control Register
    uint32_t CH9_CTRL; // Channel Control Register
    uint32_t CH10_CTRL; // Channel Control Register
    uint32_t CH11_CTRL; // Channel Control Register
};

typedef struct PROTIMER PROTIMER, *PPROTIMER;

struct PROTIMER {
    uint32_t CTRL;
    uint32_t CMD;
    uint32_t PRSCTRL;
    uint32_t STATUS;
    uint32_t PRECNT;
    uint32_t BASECNT;
    uint32_t WRAPCNT;
    uint32_t BASEPRE;
    uint32_t LWRAPCNT;
    uint32_t PRECNTTOPADJ;
    uint32_t PRECNTTOP;
    uint32_t BASECNTTOP;
    uint32_t WRAPCNTTOP;
    uint32_t TOUT0CNT;
    uint32_t TOUT0CNTTOP;
    uint32_t TOUT0COMP;
    uint32_t TOUT1CNT;
    uint32_t TOUT1CNTTOP;
    uint32_t TOUT1COMP;
    uint32_t LBTCTRL;
    uint32_t LBTPRSCTRL;
    uint32_t LBTSTATE;
    uint32_t RANDOM;
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
    uint32_t RXCTRL;
    uint32_t TXCTRL;
    uint32_t CC0_CTRL;
    uint32_t CC0_PRE;
    uint32_t CC0_BASE;
    uint32_t CC0_WRAP;
    uint32_t CC1_CTRL;
    uint32_t CC1_PRE;
    uint32_t CC1_BASE;
    uint32_t CC1_WRAP;
    uint32_t CC2_CTRL;
    uint32_t CC2_PRE;
    uint32_t CC2_BASE;
    uint32_t CC2_WRAP;
    uint32_t CC3_CTRL;
    uint32_t CC3_PRE;
    uint32_t CC3_BASE;
    uint32_t CC3_WRAP;
    uint32_t CC4_CTRL;
    uint32_t CC4_PRE;
    uint32_t CC4_BASE;
    uint32_t CC4_WRAP;
};

typedef struct AGC_SET AGC_SET, *PAGC_SET;

struct AGC_SET {
    uint32_t STATUS0;
    uint32_t STATUS1;
    uint32_t RSSI;
    uint32_t FRAMERSSI;
    undefined field_0x10;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    uint32_t CTRL0;
    uint32_t CTRL1;
    uint32_t CTRL2;
    uint32_t RSSISTEPTHR;
    uint32_t IFPEAKDET;
    uint32_t MANGAIN;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
    uint32_t CMD;
    undefined field_0x44;
    undefined field_0x45;
    undefined field_0x46;
    undefined field_0x47;
    uint32_t GAINRANGE;
    uint32_t GAININDEX;
    uint32_t SLICECODE;
    uint32_t ATTENCODE1;
    uint32_t ATTENCODE2;
    uint32_t ATTENCODE3;
    uint32_t GAINERROR1;
    uint32_t GAINERROR2;
    uint32_t GAINERROR3;
    uint32_t MANUALCTRL;
    uint32_t GAINSTEPLIM;
    uint32_t LOOPDEL;
    uint32_t MININDEX;
};

typedef struct BUFC_SET BUFC_SET, *PBUFC_SET;

struct BUFC_SET {
    uint32_t BUF0_CTRL;
    uint32_t BUF0_ADDR;
    uint32_t BUF0_WRITEOFFSET;
    uint32_t BUF0_READOFFSET;
    uint32_t BUF0_WRITESTART;
    uint32_t BUF0_READDATA;
    uint32_t BUF0_WRITEDATA;
    uint32_t BUF0_XWRITE;
    uint32_t BUF0_STATUS;
    uint32_t BUF0_THRESHOLDCTRL;
    uint32_t BUF0_CMD;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    uint32_t BUF1_CTRL;
    uint32_t BUF1_ADDR;
    uint32_t BUF1_WRITEOFFSET;
    uint32_t BUF1_READOFFSET;
    uint32_t BUF1_WRITESTART;
    uint32_t BUF1_READDATA;
    uint32_t BUF1_WRITEDATA;
    uint32_t BUF1_XWRITE;
    uint32_t BUF1_STATUS;
    uint32_t BUF1_THRESHOLDCTRL;
    uint32_t BUF1_CMD;
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    uint32_t BUF2_CTRL;
    uint32_t BUF2_ADDR;
    uint32_t BUF2_WRITEOFFSET;
    uint32_t BUF2_READOFFSET;
    uint32_t BUF2_WRITESTART;
    uint32_t BUF2_READDATA;
    uint32_t BUF2_WRITEDATA;
    uint32_t BUF2_XWRITE;
    uint32_t BUF2_STATUS;
    uint32_t BUF2_THRESHOLDCTR;
    uint32_t BUF2_CMD;
    undefined field_0x8c;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
    uint32_t BUF3_CTRL;
    uint32_t BUF3_ADDR;
    uint32_t BUF3_WRITEOFFSET;
    uint32_t BUF3_READOFFSET;
    uint32_t BUF3_WRITESTART;
    uint32_t BUF3_READDATA;
    uint32_t BUF3_WRITEDATA;
    uint32_t BUF3_XWRITE;
    uint32_t BUF3_STATUS;
    uint32_t BUF3_THRESHOLDCTRL;
    uint32_t BUF3_CMD;
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
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
};

typedef struct CRYOTIMER CRYOTIMER, *PCRYOTIMER;

struct CRYOTIMER {
    uint32_t CTRL; // Control Register
    uint32_t PERIODSEL; // Interrupt Duration
    uint32_t CNT; // Counter Value
    uint32_t EM4WUEN; // Wake Up Enable
    uint32_t IF; // Interrupt Flag Register
    uint32_t IFS; // Interrupt Flag Set Register
    uint32_t IFC; // Interrupt Flag Clear Register
    uint32_t IEN; // Interrupt Enable Register
};

typedef struct RFSENSE_SET RFSENSE_SET, *PRFSENSE_SET;

struct RFSENSE_SET {
    uint32_t CTRL;
    uint32_t PERIODSEL;
    uint32_t CNT;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    uint32_t EM4WUEN;
    uint32_t CALIB;
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
};

typedef struct GPCRC GPCRC, *PGPCRC;

struct GPCRC {
    uint32_t CTRL; // Control Register
    uint32_t CMD; // Command Register
    uint32_t INIT; // CRC Init Value
    uint32_t POLY; // CRC Polynomial Value
    uint32_t INPUTDATA; // Input 32-bit Data Register
    uint32_t INPUTDATAHWORD; // Input 16-bit Data Register
    uint32_t INPUTDATABYTE; // Input 8-bit Data Register
    uint32_t DATA; // CRC Data Register
    uint32_t DATAREV; // CRC Data Reverse Register
    uint32_t DATABYTEREV; // CRC Data Byte Reverse Register
};

typedef struct SYNTH SYNTH, *PSYNTH;

struct SYNTH {
    uint32_t STATUS;
    uint32_t CMD;
    uint32_t CTRL;
    uint32_t CALCTRL;
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
    uint32_t VCDACCTRL;
    undefined field_0x28;
    undefined field_0x29;
    undefined field_0x2a;
    undefined field_0x2b;
    uint32_t FREQ;
    uint32_t IFFREQ;
    uint32_t DIVCTRL;
    uint32_t CHCTRL;
    uint32_t CHSP;
    uint32_t CALOFFSET;
    uint32_t VCOTUNING;
    undefined field_0x48;
    undefined field_0x49;
    undefined field_0x4a;
    undefined field_0x4b;
    uint32_t VCORANGE;
    uint32_t VCOGAIN;
    uint32_t AUXVCOTUNING;
    uint32_t AUXFREQ;
    uint32_t AUXVCDACCTRL;
    uint32_t CHPDACCTRL;
    uint32_t CAPCALCYCLECNT;
    undefined field_0x68;
    undefined field_0x69;
    undefined field_0x6a;
    undefined field_0x6b;
    undefined field_0x6c;
    undefined field_0x6d;
    undefined field_0x6e;
    undefined field_0x6f;
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
};

typedef struct CMU CMU, *PCMU;

struct CMU {
    uint32_t CTRL; // CMU Control Register
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
    uint32_t HFRCOCTRL; // HFRCO Control Register
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    uint32_t AUXHFRCOCTRL; // AUXHFRCO Control Register
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    uint32_t LFRCOCTRL; // LFRCO Control Register
    uint32_t HFXOCTRL; // HFXO Control Register
    uint32_t HFXOCTRL1; // HFXO Control 1
    uint32_t HFXOSTARTUPCTRL; // HFXO Startup Control
    uint32_t HFXOSTEADYSTATECTRL; // HFXO Steady State Control
    uint32_t HFXOTIMEOUTCTRL; // HFXO Timeout Control
    uint32_t LFXOCTRL; // LFXO Control Register
    uint32_t ULFRCOCTRL; // ULFRCO Control Register
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
    uint32_t CALCTRL; // Calibration Control Register
    uint32_t CALCNT; // Calibration Counter Register
    undefined field_0x58;
    undefined field_0x59;
    undefined field_0x5a;
    undefined field_0x5b;
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    uint32_t OSCENCMD; // Oscillator Enable/Disable Command Register
    uint32_t CMD; // Command Register
    undefined field_0x68;
    undefined field_0x69;
    undefined field_0x6a;
    undefined field_0x6b;
    undefined field_0x6c;
    undefined field_0x6d;
    undefined field_0x6e;
    undefined field_0x6f;
    uint32_t DBGCLKSEL; // Debug Trace Clock Select
    uint32_t HFCLKSEL; // High Frequency Clock Select Command Register
    undefined field_0x78;
    undefined field_0x79;
    undefined field_0x7a;
    undefined field_0x7b;
    undefined field_0x7c;
    undefined field_0x7d;
    undefined field_0x7e;
    undefined field_0x7f;
    uint32_t LFACLKSEL; // Low Frequency A Clock Select Register
    uint32_t LFBCLKSEL; // Low Frequency B Clock Select Register
    uint32_t LFECLKSEL; // Low Frequency E Clock Select Register
    undefined field_0x8c;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
    uint32_t STATUS; // Status Register
    uint32_t HFCLKSTATUS; // HFCLK Status Register
    undefined field_0x98;
    undefined field_0x99;
    undefined field_0x9a;
    undefined field_0x9b;
    uint32_t HFXOTRIMSTATUS; // HFXO Trim Status
    uint32_t IF; // Interrupt Flag Register
    uint32_t IFS; // Interrupt Flag Set Register
    uint32_t IFC; // Interrupt Flag Clear Register
    uint32_t IEN; // Interrupt Enable Register
    uint32_t HFBUSCLKEN0; // High Frequency Bus Clock Enable Register 0
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
    uint32_t HFPERCLKEN0; // High Frequency Peripheral Clock Enable Register 0
    undefined field_0xc4;
    undefined field_0xc5;
    undefined field_0xc6;
    undefined field_0xc7;
    uint32_t HFRADIOCLKEN0; // High Frequency Peripheral Clock Enable Register 0
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
    uint32_t LFACLKEN0; // Low Frequency a Clock Enable Register 0 (Async Reg)
    undefined field_0xe4;
    undefined field_0xe5;
    undefined field_0xe6;
    undefined field_0xe7;
    uint32_t LFBCLKEN0; // Low Frequency B Clock Enable Register 0 (Async Reg)
    undefined field_0xec;
    undefined field_0xed;
    undefined field_0xee;
    undefined field_0xef;
    uint32_t LFECLKEN0; // Low Frequency E Clock Enable Register 0 (Async Reg)
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
    uint32_t HFPRESC; // High Frequency Clock Prescaler Register
    undefined field_0x104;
    undefined field_0x105;
    undefined field_0x106;
    undefined field_0x107;
    uint32_t HFCOREPRESC; // High Frequency Core Clock Prescaler Register
    uint32_t HFPERPRESC; // High Frequency Peripheral Clock Prescaler Register
    uint32_t HFRADIOPRESC; // Radio Clock Prescaler Register
    uint32_t HFEXPPRESC; // High Frequency Export Clock Prescaler Register
    undefined field_0x118;
    undefined field_0x119;
    undefined field_0x11a;
    undefined field_0x11b;
    undefined field_0x11c;
    undefined field_0x11d;
    undefined field_0x11e;
    undefined field_0x11f;
    uint32_t LFAPRESC0; // Low Frequency a Prescaler Register 0 (Async Reg)
    undefined field_0x124;
    undefined field_0x125;
    undefined field_0x126;
    undefined field_0x127;
    uint32_t LFBPRESC0; // Low Frequency B Prescaler Register 0 (Async Reg)
    undefined field_0x12c;
    undefined field_0x12d;
    undefined field_0x12e;
    undefined field_0x12f;
    uint32_t LFEPRESC0; // Low Frequency E Prescaler Register 0 (Async Reg)
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
    uint32_t SYNCBUSY; // Synchronization Busy Register
    uint32_t FREEZE; // Freeze Register
    undefined field_0x148;
    undefined field_0x149;
    undefined field_0x14a;
    undefined field_0x14b;
    undefined field_0x14c;
    undefined field_0x14d;
    undefined field_0x14e;
    undefined field_0x14f;
    uint32_t PCNTCTRL; // PCNT Control Register
    uint32_t LCDCTRL; // LCD Control Register
    uint32_t LVDSCTRL; // LVDSCTRL Control Register
    uint32_t ADCCTRL; // ADC Control Register
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
    uint32_t ROUTEPEN; // I/O Routing Pin Enable Register
    uint32_t ROUTELOC0; // I/O Routing Location Register
    undefined field_0x178;
    undefined field_0x179;
    undefined field_0x17a;
    undefined field_0x17b;
    undefined field_0x17c;
    undefined field_0x17d;
    undefined field_0x17e;
    undefined field_0x17f;
    uint32_t LOCK; // Configuration Lock Register
    undefined field_0x184;
    undefined field_0x185;
    undefined field_0x186;
    undefined field_0x187;
    uint32_t RFLOCK0; // RF LOCK Register
    undefined field_0x18c;
    undefined field_0x18d;
    undefined field_0x18e;
    undefined field_0x18f;
    uint32_t HFBUSCLKENMASK0;
    undefined field_0x194;
    undefined field_0x195;
    undefined field_0x196;
    undefined field_0x197;
    uint32_t HFPERCLKENMASK0;
    undefined field_0x19c;
    undefined field_0x19d;
    undefined field_0x19e;
    undefined field_0x19f;
    undefined field_0x1a0;
    undefined field_0x1a1;
    undefined field_0x1a2;
    undefined field_0x1a3;
    uint32_t HFRADIOCLKENMASK0;
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
    uint32_t LFACLKENMASK0;
    undefined field_0x1b8;
    undefined field_0x1b9;
    undefined field_0x1ba;
    undefined field_0x1bb;
    uint32_t LFBCLKENMASK0;
    undefined field_0x1c0;
    undefined field_0x1c1;
    undefined field_0x1c2;
    undefined field_0x1c3;
    uint32_t LFECLKENMASK0;
    undefined field_0x1c8;
    undefined field_0x1c9;
    undefined field_0x1ca;
    undefined field_0x1cb;
    uint32_t PCNTCLKENMASK;
    uint32_t TEST;
    uint32_t TESTHFRCOCTRL;
    uint32_t TESTAUXHFRCOCTRL;
    uint32_t TESTLFRCOCTRL;
    uint32_t TESTHFXOCTRL;
    uint32_t TESTLFXOCTRL;
};

typedef struct EMU EMU, *PEMU;

struct EMU {
    uint32_t CTRL; // Control Register
    uint32_t STATUS; // Status Register
    uint32_t LOCK; // Configuration Lock Register
    uint32_t RAM0CTRL; // Memory Control Register
    uint32_t CMD; // Command Register
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    uint32_t EM4CTRL; // EM4 Control Register
    uint32_t TEMPLIMITS; // Temperature Limits for Interrupt Generation
    uint32_t TEMP; // Value of Last Temperature Measurement
    uint32_t IF; // Interrupt Flag Register
    uint32_t IFS; // Interrupt Flag Set Register
    uint32_t IFC; // Interrupt Flag Clear Register
    uint32_t IEN; // Interrupt Enable Register
    uint32_t PWRLOCK; // Regulator and Supply Lock Register
    uint32_t PWRCFG; // Power Configuration Register
    uint32_t PWRCTRL; // Power Control Register
    uint32_t DCDCCTRL; // DCDC Control
    undefined field_0x44;
    undefined field_0x45;
    undefined field_0x46;
    undefined field_0x47;
    undefined field_0x48;
    undefined field_0x49;
    undefined field_0x4a;
    undefined field_0x4b;
    uint32_t DCDCMISCCTRL; // DCDC Miscellaneous Control Register
    uint32_t DCDCZDETCTRL; // DCDC Power Train NFET Zero Current Detector Control Register
    uint32_t DCDCCLIMCTRL; // DCDC Power Train PFET Current Limiter Control Register
    uint32_t DCDCLNCOMPCTRL; // DCDC Low Noise Compensator Control Register
    uint32_t DCDCLNVCTRL; // DCDC Low Noise Voltage Register
    uint32_t DCDCTIMING; // DCDC Controller Timing Value Register
    uint32_t DCDCLPVCTRL; // DCDC Low Power Voltage Register
    undefined field_0x68;
    undefined field_0x69;
    undefined field_0x6a;
    undefined field_0x6b;
    uint32_t DCDCLPCTRL; // DCDC Low Power Control Register
    uint32_t DCDCLNFREQCTRL; // DCDC Low Noise Controller Frequency Control
    undefined field_0x74;
    undefined field_0x75;
    undefined field_0x76;
    undefined field_0x77;
    uint32_t DCDCSYNC; // DCDC Read Status Register
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
    uint32_t VMONAVDDCTRL; // VMON AVDD Channel Control
    uint32_t VMONALTAVDDCTRL; // Alternate VMON AVDD Channel Control
    uint32_t VMONDVDDCTRL; // VMON DVDD Channel Control
    uint32_t VMONIO0CTRL; // VMON IOVDD0 Channel Control
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
    uint32_t BIASCONF; // Configurations Related to the Bias
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
    uint32_t TESTLOCK; // Test Lock Register
    undefined field_0x194;
    undefined field_0x195;
    undefined field_0x196;
    undefined field_0x197;
    undefined field_0x198;
    undefined field_0x199;
    undefined field_0x19a;
    undefined field_0x19b;
    uint32_t BIASTESTCTRL; // Test Control Register for Regulator and BIAS
};

typedef struct LEUART0 LEUART0, *PLEUART0;

struct LEUART0 {
    uint32_t CTRL; // Control Register
    uint32_t CMD; // Command Register
    uint32_t STATUS; // Status Register
    uint32_t CLKDIV; // Clock Control Register
    uint32_t STARTFRAME; // Start Frame Register
    uint32_t SIGFRAME; // Signal Frame Register
    uint32_t RXDATAX; // Receive Buffer Data Extended Register
    uint32_t RXDATA; // Receive Buffer Data Register
    uint32_t RXDATAXP; // Receive Buffer Data Extended Peek Register
    uint32_t TXDATAX; // Transmit Buffer Data Extended Register
    uint32_t TXDATA; // Transmit Buffer Data Register
    uint32_t IF; // Interrupt Flag Register
    uint32_t IFS; // Interrupt Flag Set Register
    uint32_t IFC; // Interrupt Flag Clear Register
    uint32_t IEN; // Interrupt Enable Register
    uint32_t PULSECTRL; // Pulse Control Register
    uint32_t FREEZE; // Freeze Register
    uint32_t SYNCBUSY; // Synchronization Busy Register
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
    uint32_t ROUTEPEN; // I/O Routing Pin Enable Register
    uint32_t ROUTELOC0; // I/O Routing Location Register
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    undefined field_0x60;
    undefined field_0x61;
    undefined field_0x62;
    undefined field_0x63;
    uint32_t INPUT; // LEUART Input Register
};

typedef struct FPUEH FPUEH, *PFPUEH;

struct FPUEH {
    uint32_t IF; // Interrupt Flag Register
    uint32_t IFS; // Interrupt Flag Set Register
    uint32_t IFC; // Interrupt Flag Clear Register
    uint32_t IEN; // Interrupt Enable Register
};

typedef struct ADC0 ADC0, *PADC0;

struct ADC0 {
    uint32_t CTRL; // Control Register
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    uint32_t CMD; // Command Register
    uint32_t STATUS; // Status Register
    uint32_t SINGLECTRL; // Single Channel Control Register
    uint32_t SINGLECTRLX; // Single Channel Control Register Continued
    uint32_t SCANCTRL; // Scan Control Register
    uint32_t SCANCTRLX; // Scan Control Register Continued
    uint32_t SCANMASK; // Scan Sequence Input Mask Register
    uint32_t SCANINPUTSEL; // Input Selection Register for Scan Mode
    uint32_t SCANNEGSEL; // Negative Input Select Register for Scan
    uint32_t CMPTHR; // Compare Threshold Register
    uint32_t BIASPROG; // Bias Programming Register for Various Analog Blocks Used in ADC Operation
    uint32_t CAL; // Calibration Register
    uint32_t IF; // Interrupt Flag Register
    uint32_t IFS; // Interrupt Flag Set Register
    uint32_t IFC; // Interrupt Flag Clear Register
    uint32_t IEN; // Interrupt Enable Register
    uint32_t SINGLEDATA; // Single Conversion Result Data
    uint32_t SCANDATA; // Scan Conversion Result Data
    uint32_t SINGLEDATAP; // Single Conversion Result Data Peek Register
    uint32_t SCANDATAP; // Scan Sequence Result Data Peek Register
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
    uint32_t SCANDATAX; // Scan Sequence Result Data + Data Source Register
    uint32_t SCANDATAXP; // Scan Sequence Result Data + Data Source Peek Register
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
    uint32_t APORTREQ; // APORT Request Status Register
    uint32_t APORTCONFLICT; // APORT Conflict Status Register
    uint32_t SINGLEFIFOCOUNT; // Single FIFO Count Register
    uint32_t SCANFIFOCOUNT; // Scan FIFO Count Register
    uint32_t SINGLEFIFOCLEAR; // Single FIFO Clear Register
    uint32_t SCANFIFOCLEAR; // Scan FIFO Clear Register
    uint32_t APORTMASTERDIS; // APORT Bus Master Disable Register
};

typedef struct CMU_SET CMU_SET, *PCMU_SET;

struct CMU_SET {
    uint32_t CTRL; // CMU Control Register
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
    uint32_t HFRCOCTRL; // HFRCO Control Register
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    uint32_t AUXHFRCOCTRL; // AUXHFRCO Control Register
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    uint32_t LFRCOCTRL; // LFRCO Control Register
    uint32_t HFXOCTRL; // HFXO Control Register
    uint32_t HFXOCTRL1; // HFXO Control 1
    uint32_t HFXOSTARTUPCTRL; // HFXO Startup Control
    uint32_t HFXOSTEADYSTATECTRL; // HFXO Steady State Control
    uint32_t HFXOTIMEOUTCTRL; // HFXO Timeout Control
    uint32_t LFXOCTRL; // LFXO Control Register
    uint32_t ULFRCOCTRL; // ULFRCO Control Register
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
    uint32_t CALCTRL; // Calibration Control Register
    uint32_t CALCNT; // Calibration Counter Register
    undefined field_0x58;
    undefined field_0x59;
    undefined field_0x5a;
    undefined field_0x5b;
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    uint32_t OSCENCMD; // Oscillator Enable/Disable Command Register
    uint32_t CMD; // Command Register
    undefined field_0x68;
    undefined field_0x69;
    undefined field_0x6a;
    undefined field_0x6b;
    undefined field_0x6c;
    undefined field_0x6d;
    undefined field_0x6e;
    undefined field_0x6f;
    uint32_t DBGCLKSEL; // Debug Trace Clock Select
    uint32_t HFCLKSEL; // High Frequency Clock Select Command Register
    undefined field_0x78;
    undefined field_0x79;
    undefined field_0x7a;
    undefined field_0x7b;
    undefined field_0x7c;
    undefined field_0x7d;
    undefined field_0x7e;
    undefined field_0x7f;
    uint32_t LFACLKSEL; // Low Frequency A Clock Select Register
    uint32_t LFBCLKSEL; // Low Frequency B Clock Select Register
    uint32_t LFECLKSEL; // Low Frequency E Clock Select Register
    undefined field_0x8c;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
    uint32_t STATUS; // Status Register
    uint32_t HFCLKSTATUS; // HFCLK Status Register
    undefined field_0x98;
    undefined field_0x99;
    undefined field_0x9a;
    undefined field_0x9b;
    uint32_t HFXOTRIMSTATUS; // HFXO Trim Status
    uint32_t IF; // Interrupt Flag Register
    uint32_t IFS; // Interrupt Flag Set Register
    uint32_t IFC; // Interrupt Flag Clear Register
    uint32_t IEN; // Interrupt Enable Register
    uint32_t HFBUSCLKEN0; // High Frequency Bus Clock Enable Register 0
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
    uint32_t HFPERCLKEN0; // High Frequency Peripheral Clock Enable Register 0
    undefined field_0xc4;
    undefined field_0xc5;
    undefined field_0xc6;
    undefined field_0xc7;
    uint32_t HFRADIOCLKEN0; // High Frequency Peripheral Clock Enable Register 0
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
    uint32_t LFACLKEN0; // Low Frequency a Clock Enable Register 0 (Async Reg)
    undefined field_0xe4;
    undefined field_0xe5;
    undefined field_0xe6;
    undefined field_0xe7;
    uint32_t LFBCLKEN0; // Low Frequency B Clock Enable Register 0 (Async Reg)
    undefined field_0xec;
    undefined field_0xed;
    undefined field_0xee;
    undefined field_0xef;
    uint32_t LFECLKEN0; // Low Frequency E Clock Enable Register 0 (Async Reg)
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
    uint32_t HFPRESC; // High Frequency Clock Prescaler Register
    undefined field_0x104;
    undefined field_0x105;
    undefined field_0x106;
    undefined field_0x107;
    uint32_t HFCOREPRESC; // High Frequency Core Clock Prescaler Register
    uint32_t HFPERPRESC; // High Frequency Peripheral Clock Prescaler Register
    uint32_t HFRADIOPRESC; // Radio Clock Prescaler Register
    uint32_t HFEXPPRESC; // High Frequency Export Clock Prescaler Register
    undefined field_0x118;
    undefined field_0x119;
    undefined field_0x11a;
    undefined field_0x11b;
    undefined field_0x11c;
    undefined field_0x11d;
    undefined field_0x11e;
    undefined field_0x11f;
    uint32_t LFAPRESC0; // Low Frequency a Prescaler Register 0 (Async Reg)
    undefined field_0x124;
    undefined field_0x125;
    undefined field_0x126;
    undefined field_0x127;
    uint32_t LFBPRESC0; // Low Frequency B Prescaler Register 0 (Async Reg)
    undefined field_0x12c;
    undefined field_0x12d;
    undefined field_0x12e;
    undefined field_0x12f;
    uint32_t LFEPRESC0; // Low Frequency E Prescaler Register 0 (Async Reg)
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
    uint32_t SYNCBUSY; // Synchronization Busy Register
    uint32_t FREEZE; // Freeze Register
    undefined field_0x148;
    undefined field_0x149;
    undefined field_0x14a;
    undefined field_0x14b;
    undefined field_0x14c;
    undefined field_0x14d;
    undefined field_0x14e;
    undefined field_0x14f;
    uint32_t PCNTCTRL; // PCNT Control Register
    uint32_t LCDCTRL; // LCD Control Register
    uint32_t LVDSCTRL; // LVDSCTRL Control Register
    uint32_t ADCCTRL; // ADC Control Register
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
    uint32_t ROUTEPEN; // I/O Routing Pin Enable Register
    uint32_t ROUTELOC0; // I/O Routing Location Register
    undefined field_0x178;
    undefined field_0x179;
    undefined field_0x17a;
    undefined field_0x17b;
    undefined field_0x17c;
    undefined field_0x17d;
    undefined field_0x17e;
    undefined field_0x17f;
    uint32_t LOCK; // Configuration Lock Register
    undefined field_0x184;
    undefined field_0x185;
    undefined field_0x186;
    undefined field_0x187;
    uint32_t RFLOCK0; // RF LOCK Register
    undefined field_0x18c;
    undefined field_0x18d;
    undefined field_0x18e;
    undefined field_0x18f;
    uint32_t HFBUSCLKENMASK0;
    undefined field_0x194;
    undefined field_0x195;
    undefined field_0x196;
    undefined field_0x197;
    uint32_t HFPERCLKENMASK0;
    undefined field_0x19c;
    undefined field_0x19d;
    undefined field_0x19e;
    undefined field_0x19f;
    undefined field_0x1a0;
    undefined field_0x1a1;
    undefined field_0x1a2;
    undefined field_0x1a3;
    uint32_t HFRADIOCLKENMASK0;
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
    uint32_t LFACLKENMASK0;
    undefined field_0x1b8;
    undefined field_0x1b9;
    undefined field_0x1ba;
    undefined field_0x1bb;
    uint32_t LFBCLKENMASK0;
    undefined field_0x1c0;
    undefined field_0x1c1;
    undefined field_0x1c2;
    undefined field_0x1c3;
    uint32_t LFECLKENMASK0;
    undefined field_0x1c8;
    undefined field_0x1c9;
    undefined field_0x1ca;
    undefined field_0x1cb;
    uint32_t PCNTCLKENMASK;
    uint32_t TEST;
    uint32_t TESTHFRCOCTRL;
    uint32_t TESTAUXHFRCOCTRL;
    uint32_t TESTLFRCOCTRL;
    uint32_t TESTHFXOCTRL;
    uint32_t TESTLFXOCTRL;
};

typedef struct LDMA LDMA, *PLDMA;

struct LDMA {
    uint32_t CTRL; // DMA Control Register
    uint32_t STATUS; // DMA Status Register
    uint32_t SYNC; // DMA Synchronization Trigger Register (Single-Cycle RMW)
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
    uint32_t CHEN; // DMA Channel Enable Register (Single-Cycle RMW)
    uint32_t CHBUSY; // DMA Channel Busy Register
    uint32_t CHDONE; // DMA Channel Linking Done Register (Single-Cycle RMW)
    uint32_t DBGHALT; // DMA Channel Debug Halt Register
    uint32_t SWREQ; // DMA Channel Software Transfer Request Register
    uint32_t REQDIS; // DMA Channel Request Disable Register
    uint32_t REQPEND; // DMA Channel Requests Pending Register
    uint32_t LINKLOAD; // DMA Channel Link Load Register
    uint32_t REQCLEAR; // DMA Channel Request Clear Register
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
    uint32_t IF; // Interrupt Flag Register
    uint32_t IFS; // Interrupt Flag Set Register
    uint32_t IFC; // Interrupt Flag Clear Register
    uint32_t IEN; // Interrupt Enable Register
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
    uint32_t CH0_REQSEL; // Channel Peripheral Request Select Register
    uint32_t CH0_CFG; // Channel Configuration Register
    uint32_t CH0_LOOP; // Channel Loop Counter Register
    uint32_t CH0_CTRL; // Channel Descriptor Control Word Register
    uint32_t CH0_SRC; // Channel Descriptor Source Data Address Register
    uint32_t CH0_DST; // Channel Descriptor Destination Data Address Register
    uint32_t CH0_LINK; // Channel Descriptor Link Structure Address Register
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
    uint32_t CH1_REQSEL; // Channel Peripheral Request Select Register
    uint32_t CH1_CFG; // Channel Configuration Register
    uint32_t CH1_LOOP; // Channel Loop Counter Register
    uint32_t CH1_CTRL; // Channel Descriptor Control Word Register
    uint32_t CH1_SRC; // Channel Descriptor Source Data Address Register
    uint32_t CH1_DST; // Channel Descriptor Destination Data Address Register
    uint32_t CH1_LINK; // Channel Descriptor Link Structure Address Register
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
    uint32_t CH2_REQSEL; // Channel Peripheral Request Select Register
    uint32_t CH2_CFG; // Channel Configuration Register
    uint32_t CH2_LOOP; // Channel Loop Counter Register
    uint32_t CH2_CTRL; // Channel Descriptor Control Word Register
    uint32_t CH2_SRC; // Channel Descriptor Source Data Address Register
    uint32_t CH2_DST; // Channel Descriptor Destination Data Address Register
    uint32_t CH2_LINK; // Channel Descriptor Link Structure Address Register
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
    uint32_t CH3_REQSEL; // Channel Peripheral Request Select Register
    uint32_t CH3_CFG; // Channel Configuration Register
    uint32_t CH3_LOOP; // Channel Loop Counter Register
    uint32_t CH3_CTRL; // Channel Descriptor Control Word Register
    uint32_t CH3_SRC; // Channel Descriptor Source Data Address Register
    uint32_t CH3_DST; // Channel Descriptor Destination Data Address Register
    uint32_t CH3_LINK; // Channel Descriptor Link Structure Address Register
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
    uint32_t CH4_REQSEL; // Channel Peripheral Request Select Register
    uint32_t CH4_CFG; // Channel Configuration Register
    uint32_t CH4_LOOP; // Channel Loop Counter Register
    uint32_t CH4_CTRL; // Channel Descriptor Control Word Register
    uint32_t CH4_SRC; // Channel Descriptor Source Data Address Register
    uint32_t CH4_DST; // Channel Descriptor Destination Data Address Register
    uint32_t CH4_LINK; // Channel Descriptor Link Structure Address Register
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
    uint32_t CH5_REQSEL; // Channel Peripheral Request Select Register
    uint32_t CH5_CFG; // Channel Configuration Register
    uint32_t CH5_LOOP; // Channel Loop Counter Register
    uint32_t CH5_CTRL; // Channel Descriptor Control Word Register
    uint32_t CH5_SRC; // Channel Descriptor Source Data Address Register
    uint32_t CH5_DST; // Channel Descriptor Destination Data Address Register
    uint32_t CH5_LINK; // Channel Descriptor Link Structure Address Register
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
    uint32_t CH6_REQSEL; // Channel Peripheral Request Select Register
    uint32_t CH6_CFG; // Channel Configuration Register
    uint32_t CH6_LOOP; // Channel Loop Counter Register
    uint32_t CH6_CTRL; // Channel Descriptor Control Word Register
    uint32_t CH6_SRC; // Channel Descriptor Source Data Address Register
    uint32_t CH6_DST; // Channel Descriptor Destination Data Address Register
    uint32_t CH6_LINK; // Channel Descriptor Link Structure Address Register
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
    uint32_t CH7_REQSEL; // Channel Peripheral Request Select Register
    uint32_t CH7_CFG; // Channel Configuration Register
    uint32_t CH7_LOOP; // Channel Loop Counter Register
    uint32_t CH7_CTRL; // Channel Descriptor Control Word Register
    uint32_t CH7_SRC; // Channel Descriptor Source Data Address Register
    uint32_t CH7_DST; // Channel Descriptor Destination Data Address Register
    uint32_t CH7_LINK; // Channel Descriptor Link Structure Address Register
};

typedef struct CRC CRC, *PCRC;

struct CRC {
    uint32_t CTRL;
    uint32_t STATUS;
    uint32_t CMD;
    uint32_t INPUTDATA;
    uint32_t INIT;
    uint32_t DATA;
    uint32_t POLY;
};

typedef struct MODEM_CLR MODEM_CLR, *PMODEM_CLR;

struct MODEM_CLR {
    uint32_t STATUS;
    uint32_t TIMDETSTATUS;
    uint32_t FREQOFFEST;
    uint32_t AFCADJRX;
    uint32_t AFCADJTX;
    uint32_t MIXCTRL;
    uint32_t CTRL0;
    uint32_t CTRL1;
    uint32_t CTRL2;
    uint32_t CTRL3;
    uint32_t CTRL4;
    uint32_t CTRL5;
    uint32_t TXBR;
    uint32_t RXBR;
    uint32_t CF;
    uint32_t PRE;
    uint32_t SYNC0;
    uint32_t SYNC1;
    uint32_t TIMING;
    uint32_t DSSS0;
    uint32_t MODINDEX;
    uint32_t AFC;
    uint32_t AFCADJLIM;
    uint32_t SHAPING0;
    uint32_t SHAPING1;
    uint32_t SHAPING2;
    uint32_t RAMPCTRL;
    uint32_t RAMPLEV;
    uint32_t ROUTEPEN;
    uint32_t ROUTELOC0;
    uint32_t ROUTELOC1;
    undefined field_0x7c;
    undefined field_0x7d;
    undefined field_0x7e;
    undefined field_0x7f;
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
    uint32_t CMD;
    undefined field_0x94;
    undefined field_0x95;
    undefined field_0x96;
    undefined field_0x97;
    uint32_t DCCOMP;
    uint32_t DCCOMPFILTINIT;
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
    uint32_t DCESTI;
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
    uint32_t RAM0_RAMDATA;
    uint32_t RAM1_RAMDATA;
    uint32_t RAM2_RAMDATA;
    uint32_t RAM3_RAMDATA;
    uint32_t RAM4_RAMDATA;
    uint32_t RAM5_RAMDATA;
    uint32_t RAM6_RAMDATA;
    uint32_t RAM7_RAMDATA;
    uint32_t RAM8_RAMDATA;
    uint32_t RAM9_RAMDATA;
    uint32_t RAM10_RAMDATA;
    uint32_t RAM11_RAMDATA;
    uint32_t RAM12_RAMDATA;
    uint32_t RAM13_RAMDATA;
    uint32_t RAM14_RAMDATA;
    uint32_t RAM15_RAMDATA;
    uint32_t RAM16_RAMDATA;
    uint32_t RAM17_RAMDATA;
    uint32_t RAM18_RAMDATA;
    uint32_t RAM19_RAMDATA;
    uint32_t RAM20_RAMDATA;
    uint32_t RAM21_RAMDATA;
    uint32_t RAM22_RAMDATA;
    uint32_t RAM23_RAMDATA;
    uint32_t RAM24_RAMDATA;
    uint32_t RAM25_RAMDATA;
    uint32_t RAM26_RAMDATA;
    uint32_t RAM27_RAMDATA;
    uint32_t RAM28_RAMDATA;
    uint32_t RAM29_RAMDATA;
    uint32_t RAM30_RAMDATA;
    uint32_t RAM31_RAMDATA;
    uint32_t RAM32_RAMDATA;
    uint32_t RAM33_RAMDATA;
    uint32_t RAM34_RAMDATA;
    uint32_t RAM35_RAMDATA;
    uint32_t RAM36_RAMDATA;
    uint32_t RAM37_RAMDATA;
    uint32_t RAM38_RAMDATA;
    uint32_t RAM39_RAMDATA;
    uint32_t RAM40_RAMDATA;
    uint32_t RAM41_RAMDATA;
    uint32_t RAM42_RAMDATA;
    uint32_t RAM43_RAMDATA;
    uint32_t RAM44_RAMDATA;
    uint32_t RAM45_RAMDATA;
    uint32_t RAM46_RAMDATA;
    uint32_t RAM47_RAMDATA;
    uint32_t RAM48_RAMDATA;
    uint32_t RAM49_RAMDATA;
    uint32_t RAM50_RAMDATA;
    uint32_t RAM51_RAMDATA;
    uint32_t RAM52_RAMDATA;
    uint32_t RAM53_RAMDATA;
    uint32_t RAM54_RAMDATA;
    uint32_t RAM55_RAMDATA;
    uint32_t RAM56_RAMDATA;
    uint32_t RAM57_RAMDATA;
    uint32_t RAM58_RAMDATA;
    uint32_t RAM59_RAMDATA;
    uint32_t RAM60_RAMDATA;
    uint32_t RAM61_RAMDATA;
    uint32_t RAM62_RAMDATA;
    uint32_t RAM63_RAMDATA;
    uint32_t RAM64_RAMDATA;
    uint32_t RAM65_RAMDATA;
    uint32_t RAM66_RAMDATA;
    uint32_t RAM67_RAMDATA;
    uint32_t RAM68_RAMDATA;
    uint32_t RAM69_RAMDATA;
    uint32_t RAM70_RAMDATA;
    uint32_t RAM71_RAMDATA;
    uint32_t RAM72_RAMDATA;
    uint32_t RAM73_RAMDATA;
    uint32_t RAM74_RAMDATA;
    uint32_t RAM75_RAMDATA;
    uint32_t RAM76_RAMDATA;
    uint32_t RAM77_RAMDATA;
    uint32_t RAM78_RAMDATA;
    uint32_t RAM79_RAMDATA;
    uint32_t RAM80_RAMDATA;
    uint32_t RAM81_RAMDATA;
    uint32_t RAM82_RAMDATA;
    uint32_t RAM83_RAMDATA;
    uint32_t RAM84_RAMDATA;
    uint32_t RAM85_RAMDATA;
    uint32_t RAM86_RAMDATA;
    uint32_t RAM87_RAMDATA;
    uint32_t RAM88_RAMDATA;
    uint32_t RAM89_RAMDATA;
    uint32_t RAM90_RAMDATA;
    uint32_t RAM91_RAMDATA;
    uint32_t RAM92_RAMDATA;
    uint32_t RAM93_RAMDATA;
    uint32_t RAM94_RAMDATA;
    uint32_t RAM95_RAMDATA;
    uint32_t RAM96_RAMDATA;
    uint32_t RAM97_RAMDATA;
    uint32_t RAM98_RAMDATA;
    uint32_t RAM99_RAMDATA;
    uint32_t RAM100_RAMDATA;
    uint32_t RAM101_RAMDATA;
    uint32_t RAM102_RAMDATA;
    uint32_t RAM103_RAMDATA;
    uint32_t RAM104_RAMDATA;
    uint32_t RAM105_RAMDATA;
    uint32_t RAM106_RAMDATA;
    uint32_t RAM107_RAMDATA;
    uint32_t RAM108_RAMDATA;
    uint32_t RAM109_RAMDATA;
    uint32_t RAM110_RAMDATA;
    uint32_t RAM111_RAMDATA;
    uint32_t RAM112_RAMDATA;
    uint32_t RAM113_RAMDATA;
    uint32_t RAM114_RAMDATA;
    uint32_t RAM115_RAMDATA;
    uint32_t RAM116_RAMDATA;
    uint32_t RAM117_RAMDATA;
    uint32_t RAM118_RAMDATA;
    uint32_t RAM119_RAMDATA;
    uint32_t RAM120_RAMDATA;
    uint32_t RAM121_RAMDATA;
    uint32_t RAM122_RAMDATA;
    uint32_t RAM123_RAMDATA;
    uint32_t RAM124_RAMDATA;
    uint32_t RAM125_RAMDATA;
    uint32_t RAM126_RAMDATA;
    uint32_t RAM127_RAMDATA;
    uint32_t RAM128_RAMDATA;
    uint32_t RAM129_RAMDATA;
    uint32_t RAM130_RAMDATA;
    uint32_t RAM131_RAMDATA;
    uint32_t RAM132_RAMDATA;
    uint32_t RAM133_RAMDATA;
    uint32_t RAM134_RAMDATA;
    uint32_t RAM135_RAMDATA;
    uint32_t RAM136_RAMDATA;
    uint32_t RAM137_RAMDATA;
    uint32_t RAM138_RAMDATA;
    uint32_t RAM139_RAMDATA;
    uint32_t RAM140_RAMDATA;
    uint32_t RAM141_RAMDATA;
    uint32_t RAM142_RAMDATA;
    uint32_t RAM143_RAMDATA;
    uint32_t RAM144_RAMDATA;
    uint32_t RAM145_RAMDATA;
    uint32_t RAM146_RAMDATA;
    uint32_t RAM147_RAMDATA;
    uint32_t RAM148_RAMDATA;
    uint32_t RAM149_RAMDATA;
    uint32_t RAM150_RAMDATA;
    uint32_t RAM151_RAMDATA;
    uint32_t RAM152_RAMDATA;
    uint32_t RAM153_RAMDATA;
    uint32_t RAM154_RAMDATA;
    uint32_t RAM155_RAMDATA;
    uint32_t RAM156_RAMDATA;
    uint32_t RAM157_RAMDATA;
    uint32_t RAM158_RAMDATA;
    uint32_t RAM159_RAMDATA;
    uint32_t RAM160_RAMDATA;
    uint32_t RAM161_RAMDATA;
    uint32_t RAM162_RAMDATA;
    uint32_t RAM163_RAMDATA;
    uint32_t RAM164_RAMDATA;
    uint32_t RAM165_RAMDATA;
    uint32_t RAM166_RAMDATA;
    uint32_t RAM167_RAMDATA;
    uint32_t RAM168_RAMDATA;
    uint32_t RAM169_RAMDATA;
    uint32_t RAM170_RAMDATA;
    uint32_t RAM171_RAMDATA;
    uint32_t RAM172_RAMDATA;
    uint32_t RAM173_RAMDATA;
    uint32_t RAM174_RAMDATA;
    uint32_t RAM175_RAMDATA;
    uint32_t RAM176_RAMDATA;
    uint32_t RAM177_RAMDATA;
    uint32_t RAM178_RAMDATA;
    uint32_t RAM179_RAMDATA;
    uint32_t RAM180_RAMDATA;
    uint32_t RAM181_RAMDATA;
    uint32_t RAM182_RAMDATA;
    uint32_t RAM183_RAMDATA;
    uint32_t RAM184_RAMDATA;
    uint32_t RAM185_RAMDATA;
    uint32_t RAM186_RAMDATA;
    uint32_t RAM187_RAMDATA;
    uint32_t RAM188_RAMDATA;
    uint32_t RAM189_RAMDATA;
    uint32_t RAM190_RAMDATA;
    uint32_t RAM191_RAMDATA;
    uint32_t RAM192_RAMDATA;
    uint32_t RAM193_RAMDATA;
    uint32_t RAM194_RAMDATA;
    uint32_t RAM195_RAMDATA;
    uint32_t RAM196_RAMDATA;
    uint32_t RAM197_RAMDATA;
    uint32_t RAM198_RAMDATA;
    uint32_t RAM199_RAMDATA;
    uint32_t RAM200_RAMDATA;
    uint32_t RAM201_RAMDATA;
    uint32_t RAM202_RAMDATA;
    uint32_t RAM203_RAMDATA;
    uint32_t RAM204_RAMDATA;
    uint32_t RAM205_RAMDATA;
    uint32_t RAM206_RAMDATA;
    uint32_t RAM207_RAMDATA;
    uint32_t RAM208_RAMDATA;
    uint32_t RAM209_RAMDATA;
    uint32_t RAM210_RAMDATA;
    uint32_t RAM211_RAMDATA;
    uint32_t RAM212_RAMDATA;
    uint32_t RAM213_RAMDATA;
    uint32_t RAM214_RAMDATA;
    uint32_t RAM215_RAMDATA;
    uint32_t RAM216_RAMDATA;
    uint32_t RAM217_RAMDATA;
    uint32_t RAM218_RAMDATA;
    uint32_t RAM219_RAMDATA;
    uint32_t RAM220_RAMDATA;
    uint32_t RAM221_RAMDATA;
    uint32_t RAM222_RAMDATA;
    uint32_t RAM223_RAMDATA;
    uint32_t RAM224_RAMDATA;
    uint32_t RAM225_RAMDATA;
    uint32_t RAM226_RAMDATA;
    uint32_t RAM227_RAMDATA;
    uint32_t RAM228_RAMDATA;
    uint32_t RAM229_RAMDATA;
    uint32_t RAM230_RAMDATA;
    uint32_t RAM231_RAMDATA;
    uint32_t RAM232_RAMDATA;
    uint32_t RAM233_RAMDATA;
    uint32_t RAM234_RAMDATA;
    uint32_t RAM235_RAMDATA;
    uint32_t RAM236_RAMDATA;
    uint32_t RAM237_RAMDATA;
    uint32_t RAM238_RAMDATA;
    uint32_t RAM239_RAMDATA;
    uint32_t RAM240_RAMDATA;
    uint32_t RAM241_RAMDATA;
    uint32_t RAM242_RAMDATA;
    uint32_t RAM243_RAMDATA;
    uint32_t RAM244_RAMDATA;
    uint32_t RAM245_RAMDATA;
    uint32_t RAM246_RAMDATA;
    uint32_t RAM247_RAMDATA;
    uint32_t RAM248_RAMDATA;
    uint32_t RAM249_RAMDATA;
    uint32_t RAM250_RAMDATA;
    uint32_t RAM251_RAMDATA;
    uint32_t RAM252_RAMDATA;
    uint32_t RAM253_RAMDATA;
    uint32_t RAM254_RAMDATA;
    uint32_t RAM255_RAMDATA;
};

typedef struct I2C0 I2C0, *PI2C0;

struct I2C0 {
    uint32_t CTRL; // Control Register
    uint32_t CMD; // Command Register
    uint32_t STATE; // State Register
    uint32_t STATUS; // Status Register
    uint32_t CLKDIV; // Clock Division Register
    uint32_t SADDR; // Slave Address Register
    uint32_t SADDRMASK; // Slave Address Mask Register
    uint32_t RXDATA; // Receive Buffer Data Register
    uint32_t RXDOUBLE; // Receive Buffer Double Data Register
    uint32_t RXDATAP; // Receive Buffer Data Peek Register
    uint32_t RXDOUBLEP; // Receive Buffer Double Data Peek Register
    uint32_t TXDATA; // Transmit Buffer Data Register
    uint32_t TXDOUBLE; // Transmit Buffer Double Data Register
    uint32_t IF; // Interrupt Flag Register
    uint32_t IFS; // Interrupt Flag Set Register
    uint32_t IFC; // Interrupt Flag Clear Register
    uint32_t IEN; // Interrupt Enable Register
    uint32_t ROUTEPEN; // I/O Routing Pin Enable Register
    uint32_t ROUTELOC0; // I/O Routing Location Register
};

typedef struct ACMP0 ACMP0, *PACMP0;

struct ACMP0 {
    uint32_t CTRL; // Control Register
    uint32_t INPUTSEL; // Input Selection Register
    uint32_t STATUS; // Status Register
    uint32_t IF; // Interrupt Flag Register
    uint32_t IFS; // Interrupt Flag Set Register
    uint32_t IFC; // Interrupt Flag Clear Register
    uint32_t IEN; // Interrupt Enable Register
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    uint32_t APORTREQ; // APORT Request Status Register
    uint32_t APORTCONFLICT; // APORT Conflict Status Register
    uint32_t HYSTERESIS0; // Hysteresis 0 Register
    uint32_t HYSTERESIS1; // Hysteresis 1 Register
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
    uint32_t ROUTEPEN; // I/O Routing Pine Enable Register
    uint32_t ROUTELOC0; // I/O Routing Location Register
};

typedef struct RAC_CLR RAC_CLR, *PRAC_CLR;

struct RAC_CLR {
    uint32_t RXENSRCEN;
    uint32_t STATUS;
    uint32_t CMD;
    uint32_t CTRL;
    uint32_t FORCESTATE;
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
    uint32_t LVDSCTRL;
    uint32_t LVDSIDLESEQ;
    uint32_t LVDSROUTE;
    uint32_t HFXORETIMECTRL;
    uint32_t HFXORETIMESTATUS;
    uint32_t TESTCTRL;
    uint32_t SEQSTATUS;
    uint32_t SEQCMD;
    uint32_t BREAKPOINT;
    uint32_t R0;
    uint32_t R1;
    uint32_t R2;
    uint32_t R3;
    uint32_t R4;
    uint32_t R5;
    uint32_t R6;
    uint32_t R7;
    undefined field_0x68;
    undefined field_0x69;
    undefined field_0x6a;
    undefined field_0x6b;
    uint32_t WAITMASK;
    uint32_t WAITSNSH;
    uint32_t STIMER;
    uint32_t STIMERCOMP;
    uint32_t VECTADDR;
    uint32_t SEQCTRL;
    uint32_t PRESC;
    uint32_t SR0;
    uint32_t SR1;
    uint32_t SR2;
    uint32_t SR3;
    uint32_t SYNTHENCTRL;
    uint32_t SYNTHREGCTRL;
    uint32_t VCOCTRL;
    uint32_t MMDCTRL;
    undefined field_0xa8;
    undefined field_0xa9;
    undefined field_0xaa;
    undefined field_0xab;
    undefined field_0xac;
    undefined field_0xad;
    undefined field_0xae;
    undefined field_0xaf;
    uint32_t CHPCTRL;
    uint32_t CHPCAL;
    uint32_t LPFCTRL;
    uint32_t SYNTHCTRL;
    uint32_t AUXCTRL;
    uint32_t AUXENCTRL;
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
    uint32_t RFENCTRL;
    uint32_t RFENCTRL0;
    uint32_t LNAMIXCTRL;
    uint32_t PACTRL0;
    uint32_t PAPKDCTRL;
    uint32_t PABIASCTRL0;
    uint32_t PABIASCTRL1;
    uint32_t SGRFENCTRL0;
    uint32_t SGLNAMIXCTRL;
    uint32_t SGPACTRL0;
    uint32_t SGPAPKDCTRL;
    uint32_t SGPABIASCTRL0;
    uint32_t SGPABIASCTRL1;
    uint32_t RFSTATUS;
    uint32_t RFBIASCTRL;
    uint32_t RFBIASCAL;
    uint32_t LNAMIXCTRL1;
    uint32_t IFPGACTRL;
    uint32_t IFPGACAL;
    uint32_t IFFILTCTRL;
    uint32_t IFADCCTRL;
    uint32_t IFADCCAL;
    uint32_t PAENCTRL;
    uint32_t PACTUNECTRL;
    uint32_t RCTUNE;
    uint32_t APC;
    uint32_t SPARE;
};

typedef struct CRC_SET CRC_SET, *PCRC_SET;

struct CRC_SET {
    uint32_t CTRL;
    uint32_t STATUS;
    uint32_t CMD;
    uint32_t INPUTDATA;
    uint32_t INIT;
    uint32_t DATA;
    uint32_t POLY;
};

typedef struct RFSENSE RFSENSE, *PRFSENSE;

struct RFSENSE {
    uint32_t CTRL;
    uint32_t PERIODSEL;
    uint32_t CNT;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    uint32_t EM4WUEN;
    uint32_t CALIB;
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
};

typedef struct SEQ SEQ, *PSEQ;

struct SEQ {
    uint32_t REG000;
    uint32_t REG004;
    uint32_t REG008;
    uint32_t REG00C;
    uint32_t REG010;
    uint32_t REG014;
    uint32_t REG018;
    uint32_t REG01C;
    uint32_t REG020;
    uint32_t REG024;
    uint32_t REG028;
    uint32_t REG02C;
    uint32_t REG030;
    uint32_t REG034;
    uint32_t REG038;
    uint32_t REG03C;
    uint32_t REG040;
    uint32_t REG044;
    uint32_t REG048;
    uint32_t REG04C;
    uint32_t REG050;
    uint32_t REG054;
    uint32_t REG058;
    uint32_t REG05C;
    uint32_t REG060;
    uint32_t REG064;
    uint32_t REG068;
    uint32_t REG06C;
    uint32_t REG070;
    uint32_t REG074;
    uint32_t REG078;
    uint32_t REG07C;
    uint32_t REG080;
    uint32_t REG084;
    uint32_t REG088;
    uint32_t REG08C;
    uint32_t REG090;
    uint32_t REG094;
    uint32_t REG098;
    uint32_t REG09C;
    uint32_t REG0A0;
    uint32_t REG0A4;
    uint32_t REG0A8;
    uint32_t REG0AC;
    uint32_t REG0B0;
    uint32_t REG0B4;
    uint32_t REG0B8;
    uint32_t REG0BC;
    uint32_t REG0C0;
    uint32_t REG0C4;
    uint32_t REG0C8;
    uint32_t REG0CC;
    uint32_t REG0D0;
    uint32_t REG0D4;
    uint32_t REG0D8;
    uint32_t REG0DC;
    uint32_t REG0E0;
    uint32_t REG0E4;
    uint32_t REG0E8;
    uint32_t DYNAMIC_CHPWR_TABLE;
    uint32_t PHYINFO;
    uint32_t MISC;
    uint32_t SYNTHLPFCTRLRX;
    uint32_t SYNTHLPFCTRLTX;
};

typedef struct ACMP1 ACMP1, *PACMP1;

struct ACMP1 {
    uint32_t CTRL; // Control Register
    uint32_t INPUTSEL; // Input Selection Register
    uint32_t STATUS; // Status Register
    uint32_t IF; // Interrupt Flag Register
    uint32_t IFS; // Interrupt Flag Set Register
    uint32_t IFC; // Interrupt Flag Clear Register
    uint32_t IEN; // Interrupt Enable Register
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    uint32_t APORTREQ; // APORT Request Status Register
    uint32_t APORTCONFLICT; // APORT Conflict Status Register
    uint32_t HYSTERESIS0; // Hysteresis 0 Register
    uint32_t HYSTERESIS1; // Hysteresis 1 Register
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
    uint32_t ROUTEPEN; // I/O Routing Pine Enable Register
    uint32_t ROUTELOC0; // I/O Routing Location Register
};

typedef struct CRYPTO CRYPTO, *PCRYPTO;

struct CRYPTO {
    uint32_t CTRL; // Control Register
    uint32_t WAC; // Wide Arithmetic Configuration
    uint32_t CMD; // Command Register
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    uint32_t STATUS; // Status Register
    uint32_t DSTATUS; // Data Status Register
    uint32_t CSTATUS; // Control Status Register
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    uint32_t KEY; // KEY Register Access
    uint32_t KEYBUF; // KEY Buffer Register Access
    undefined field_0x28;
    undefined field_0x29;
    undefined field_0x2a;
    undefined field_0x2b;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    uint32_t SEQCTRL; // Sequence Control
    uint32_t SEQCTRLB; // Sequence Control B
    undefined field_0x38;
    undefined field_0x39;
    undefined field_0x3a;
    undefined field_0x3b;
    undefined field_0x3c;
    undefined field_0x3d;
    undefined field_0x3e;
    undefined field_0x3f;
    uint32_t IF; // AES Interrupt Flags
    uint32_t IFS; // Interrupt Flag Set Register
    uint32_t IFC; // Interrupt Flag Clear Register
    uint32_t IEN; // Interrupt Enable Register
    uint32_t SEQ0; // Sequence Register 0
    uint32_t SEQ1; // Sequence Register 1
    uint32_t SEQ2; // Sequence Register 2
    uint32_t SEQ3; // Sequence Register 3
    uint32_t SEQ4; // Sequence Register 4
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
    uint32_t DATA0; // DATA0 Register Access
    uint32_t DATA1; // DATA1 Register Access
    uint32_t DATA2; // DATA2 Register Access
    uint32_t DATA3; // DATA3 Register Access
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
    uint32_t DATA0XOR; // DATA0XOR Register Access
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
    uint32_t DATA0BYTE; // DATA0 Register Byte Access
    uint32_t DATA1BYTE; // DATA1 Register Byte Access
    undefined field_0xb8;
    undefined field_0xb9;
    undefined field_0xba;
    undefined field_0xbb;
    uint32_t DATA0XORBYTE; // DATA0 Register Byte XOR Access
    uint32_t DATA0BYTE12; // DATA0 Register Byte 12 Access
    uint32_t DATA0BYTE13; // DATA0 Register Byte 13 Access
    uint32_t DATA0BYTE14; // DATA0 Register Byte 14 Access
    uint32_t DATA0BYTE15; // DATA0 Register Byte 15 Access
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
    uint32_t DDATA0; // DDATA0 Register Access
    uint32_t DDATA1; // DDATA1 Register Access
    uint32_t DDATA2; // DDATA2 Register Access
    uint32_t DDATA3; // DDATA3 Register Access
    uint32_t DDATA4; // DDATA4 Register Access
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
    uint32_t DDATA0BIG; // DDATA0 Register Big Endian Access
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
    uint32_t DDATA0BYTE; // DDATA0 Register Byte Access
    uint32_t DDATA1BYTE; // DDATA1 Register Byte Access
    uint32_t DDATA0BYTE32; // DDATA0 Register Byte 32 Access
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
    uint32_t QDATA0; // QDATA0 Register Access
    uint32_t QDATA1; // QDATA1 Register Access
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
    uint32_t QDATA1BIG; // QDATA1 Register Big Endian Access
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
    uint32_t QDATA0BYTE; // QDATA0 Register Byte Access
    uint32_t QDATA1BYTE; // QDATA1 Register Byte Access
};

typedef struct FRC_SET FRC_SET, *PFRC_SET;

struct FRC_SET {
    uint32_t STATUS;
    uint32_t DFLCTRL;
    uint32_t MAXLENGTH;
    uint32_t ADDRFILTCTRL;
    uint32_t DATABUFFER;
    uint32_t WCNT;
    uint32_t WCNTCMP0;
    uint32_t WCNTCMP1;
    uint32_t WCNTCMP2;
    uint32_t CMD;
    uint32_t WHITECTRL;
    uint32_t WHITEPOLY;
    uint32_t WHITEINIT;
    uint32_t FECCTRL;
    uint32_t BLOCKRAMADDR;
    uint32_t CONVRAMADDR;
    uint32_t CTRL;
    uint32_t RXCTRL;
    uint32_t TRAILTXDATACTRL;
    uint32_t TRAILRXDATA;
    uint32_t SCNT;
    uint32_t CONVGENERATOR;
    uint32_t PUNCTCTRL;
    uint32_t PAUSECTRL;
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
    uint32_t BUFFERMODE;
    uint32_t ROUTEPEN;
    uint32_t ROUTELOC0;
    uint32_t SNIFFCTRL;
    uint32_t AUXDATA;
    uint32_t RAWCTRL;
    uint32_t RXRAWDATA;
    uint32_t PAUSEDATA;
    uint32_t LIKELYCONVSTATE;
    uint32_t INTELEMENTNEXT;
    uint32_t INTWRITEPOINT;
    uint32_t INTREADPOINT;
    uint32_t FCD0;
    uint32_t FCD1;
    uint32_t FCD2;
    uint32_t FCD3;
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
    uint32_t INTELEMENT0;
    uint32_t INTELEMENT1;
    uint32_t INTELEMENT2;
    uint32_t INTELEMENT3;
    uint32_t INTELEMENT4;
    uint32_t INTELEMENT5;
    uint32_t INTELEMENT6;
    uint32_t INTELEMENT7;
    uint32_t INTELEMENT8;
    uint32_t INTELEMENT9;
    uint32_t INTELEMENT10;
    uint32_t INTELEMENT11;
    uint32_t INTELEMENT12;
    uint32_t INTELEMENT13;
    uint32_t INTELEMENT14;
    uint32_t INTELEMENT15;
};

typedef struct PROTIMER_CLR PROTIMER_CLR, *PPROTIMER_CLR;

struct PROTIMER_CLR {
    uint32_t CTRL;
    uint32_t CMD;
    uint32_t PRSCTRL;
    uint32_t STATUS;
    uint32_t PRECNT;
    uint32_t BASECNT;
    uint32_t WRAPCNT;
    uint32_t BASEPRE;
    uint32_t LWRAPCNT;
    uint32_t PRECNTTOPADJ;
    uint32_t PRECNTTOP;
    uint32_t BASECNTTOP;
    uint32_t WRAPCNTTOP;
    uint32_t TOUT0CNT;
    uint32_t TOUT0CNTTOP;
    uint32_t TOUT0COMP;
    uint32_t TOUT1CNT;
    uint32_t TOUT1CNTTOP;
    uint32_t TOUT1COMP;
    uint32_t LBTCTRL;
    uint32_t LBTPRSCTRL;
    uint32_t LBTSTATE;
    uint32_t RANDOM;
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
    uint32_t RXCTRL;
    uint32_t TXCTRL;
    uint32_t CC0_CTRL;
    uint32_t CC0_PRE;
    uint32_t CC0_BASE;
    uint32_t CC0_WRAP;
    uint32_t CC1_CTRL;
    uint32_t CC1_PRE;
    uint32_t CC1_BASE;
    uint32_t CC1_WRAP;
    uint32_t CC2_CTRL;
    uint32_t CC2_PRE;
    uint32_t CC2_BASE;
    uint32_t CC2_WRAP;
    uint32_t CC3_CTRL;
    uint32_t CC3_PRE;
    uint32_t CC3_BASE;
    uint32_t CC3_WRAP;
    uint32_t CC4_CTRL;
    uint32_t CC4_PRE;
    uint32_t CC4_BASE;
    uint32_t CC4_WRAP;
};

typedef struct BUFC BUFC, *PBUFC;

struct BUFC {
    uint32_t BUF0_CTRL;
    uint32_t BUF0_ADDR;
    uint32_t BUF0_WRITEOFFSET;
    uint32_t BUF0_READOFFSET;
    uint32_t BUF0_WRITESTART;
    uint32_t BUF0_READDATA;
    uint32_t BUF0_WRITEDATA;
    uint32_t BUF0_XWRITE;
    uint32_t BUF0_STATUS;
    uint32_t BUF0_THRESHOLDCTRL;
    uint32_t BUF0_CMD;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    uint32_t BUF1_CTRL;
    uint32_t BUF1_ADDR;
    uint32_t BUF1_WRITEOFFSET;
    uint32_t BUF1_READOFFSET;
    uint32_t BUF1_WRITESTART;
    uint32_t BUF1_READDATA;
    uint32_t BUF1_WRITEDATA;
    uint32_t BUF1_XWRITE;
    uint32_t BUF1_STATUS;
    uint32_t BUF1_THRESHOLDCTRL;
    uint32_t BUF1_CMD;
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    uint32_t BUF2_CTRL;
    uint32_t BUF2_ADDR;
    uint32_t BUF2_WRITEOFFSET;
    uint32_t BUF2_READOFFSET;
    uint32_t BUF2_WRITESTART;
    uint32_t BUF2_READDATA;
    uint32_t BUF2_WRITEDATA;
    uint32_t BUF2_XWRITE;
    uint32_t BUF2_STATUS;
    uint32_t BUF2_THRESHOLDCTR;
    uint32_t BUF2_CMD;
    undefined field_0x8c;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
    uint32_t BUF3_CTRL;
    uint32_t BUF3_ADDR;
    uint32_t BUF3_WRITEOFFSET;
    uint32_t BUF3_READOFFSET;
    uint32_t BUF3_WRITESTART;
    uint32_t BUF3_READDATA;
    uint32_t BUF3_WRITEDATA;
    uint32_t BUF3_XWRITE;
    uint32_t BUF3_STATUS;
    uint32_t BUF3_THRESHOLDCTRL;
    uint32_t BUF3_CMD;
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
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
};

typedef struct USART1 USART1, *PUSART1;

struct USART1 {
    uint32_t CTRL; // Control Register
    uint32_t FRAME; // USART Frame Format Register
    uint32_t TRIGCTRL; // USART Trigger Control Register
    uint32_t CMD; // Command Register
    uint32_t STATUS; // USART Status Register
    uint32_t CLKDIV; // Clock Control Register
    uint32_t RXDATAX; // RX Buffer Data Extended Register
    uint32_t RXDATA; // RX Buffer Data Register
    uint32_t RXDOUBLEX; // RX Buffer Double Data Extended Register
    uint32_t RXDOUBLE; // RX FIFO Double Data Register
    uint32_t RXDATAXP; // RX Buffer Data Extended Peek Register
    uint32_t RXDOUBLEXP; // RX Buffer Double Data Extended Peek Register
    uint32_t TXDATAX; // TX Buffer Data Extended Register
    uint32_t TXDATA; // TX Buffer Data Register
    uint32_t TXDOUBLEX; // TX Buffer Double Data Extended Register
    uint32_t TXDOUBLE; // TX Buffer Double Data Register
    uint32_t IF; // Interrupt Flag Register
    uint32_t IFS; // Interrupt Flag Set Register
    uint32_t IFC; // Interrupt Flag Clear Register
    uint32_t IEN; // Interrupt Enable Register
    uint32_t IRCTRL; // IrDA Control Register
    undefined field_0x54;
    undefined field_0x55;
    undefined field_0x56;
    undefined field_0x57;
    uint32_t INPUT; // USART Input Register
    uint32_t I2SCTRL; // I2S Control Register
    uint32_t TIMING; // Timing Register
    uint32_t CTRLX; // Control Register Extended
    uint32_t TIMECMP0; // Used to Generate Interrupts and Various Delays
    uint32_t TIMECMP1; // Used to Generate Interrupts and Various Delays
    uint32_t TIMECMP2; // Used to Generate Interrupts and Various Delays
    uint32_t ROUTEPEN; // I/O Routing Pin Enable Register
    uint32_t ROUTELOC0; // I/O Routing Location Register
    uint32_t ROUTELOC1; // I/O Routing Location Register
};

typedef struct PCNT0 PCNT0, *PPCNT0;

struct PCNT0 {
    uint32_t CTRL; // Control Register
    uint32_t CMD; // Command Register
    uint32_t STATUS; // Status Register
    uint32_t CNT; // Counter Value Register
    uint32_t TOP; // Top Value Register
    uint32_t TOPB; // Top Value Buffer Register
    uint32_t IF; // Interrupt Flag Register
    uint32_t IFS; // Interrupt Flag Set Register
    uint32_t IFC; // Interrupt Flag Clear Register
    uint32_t IEN; // Interrupt Enable Register
    undefined field_0x28;
    undefined field_0x29;
    undefined field_0x2a;
    undefined field_0x2b;
    uint32_t ROUTELOC0; // I/O Routing Location Register
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
    uint32_t FREEZE; // Freeze Register
    uint32_t SYNCBUSY; // Synchronization Busy Register
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
    uint32_t AUXCNT; // Auxiliary Counter Value Register
    uint32_t INPUT; // PCNT Input Register
    uint32_t OVSCFG; // Oversampling Config Register
};

typedef struct TIMER1 TIMER1, *PTIMER1;

struct TIMER1 {
    uint32_t CTRL; // Control Register
    uint32_t CMD; // Command Register
    uint32_t STATUS; // Status Register
    uint32_t IF; // Interrupt Flag Register
    uint32_t IFS; // Interrupt Flag Set Register
    uint32_t IFC; // Interrupt Flag Clear Register
    uint32_t IEN; // Interrupt Enable Register
    uint32_t TOP; // Counter Top Value Register
    uint32_t TOPB; // Counter Top Value Buffer Register
    uint32_t CNT; // Counter Value Register
    undefined field_0x28;
    undefined field_0x29;
    undefined field_0x2a;
    undefined field_0x2b;
    uint32_t LOCK; // TIMER Configuration Lock Register
    uint32_t ROUTEPEN; // I/O Routing Pin Enable Register
    uint32_t ROUTELOC0; // I/O Routing Location Register
    undefined field_0x38;
    undefined field_0x39;
    undefined field_0x3a;
    undefined field_0x3b;
    uint32_t ROUTELOC2; // I/O Routing Location Register
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
    uint32_t CC0_CTRL; // CC Channel Control Register
    uint32_t CC0_CCV; // CC Channel Value Register
    uint32_t CC0_CCVP; // CC Channel Value Peek Register
    uint32_t CC0_CCVB; // CC Channel Buffer Register
    uint32_t CC1_CTRL; // CC Channel Control Register
    uint32_t CC1_CCV; // CC Channel Value Register
    uint32_t CC1_CCVP; // CC Channel Value Peek Register
    uint32_t CC1_CCVB; // CC Channel Buffer Register
    uint32_t CC2_CTRL; // CC Channel Control Register
    uint32_t CC2_CCV; // CC Channel Value Register
    uint32_t CC2_CCVP; // CC Channel Value Peek Register
    uint32_t CC2_CCVB; // CC Channel Buffer Register
    uint32_t CC3_CTRL; // CC Channel Control Register
    uint32_t CC3_CCV; // CC Channel Value Register
    uint32_t CC3_CCVP; // CC Channel Value Peek Register
    uint32_t CC3_CCVB; // CC Channel Buffer Register
    uint32_t DTCTRL; // DTI Control Register
    uint32_t DTTIME; // DTI Time Control Register
    uint32_t DTFC; // DTI Fault Configuration Register
    uint32_t DTOGEN; // DTI Output Generation Enable Register
    uint32_t DTFAULT; // DTI Fault Register
    uint32_t DTFAULTC; // DTI Fault Clear Register
    uint32_t DTLOCK; // DTI Configuration Lock Register
};

typedef struct TIMER0 TIMER0, *PTIMER0;

struct TIMER0 {
    uint32_t CTRL; // Control Register
    uint32_t CMD; // Command Register
    uint32_t STATUS; // Status Register
    uint32_t IF; // Interrupt Flag Register
    uint32_t IFS; // Interrupt Flag Set Register
    uint32_t IFC; // Interrupt Flag Clear Register
    uint32_t IEN; // Interrupt Enable Register
    uint32_t TOP; // Counter Top Value Register
    uint32_t TOPB; // Counter Top Value Buffer Register
    uint32_t CNT; // Counter Value Register
    undefined field_0x28;
    undefined field_0x29;
    undefined field_0x2a;
    undefined field_0x2b;
    uint32_t LOCK; // TIMER Configuration Lock Register
    uint32_t ROUTEPEN; // I/O Routing Pin Enable Register
    uint32_t ROUTELOC0; // I/O Routing Location Register
    undefined field_0x38;
    undefined field_0x39;
    undefined field_0x3a;
    undefined field_0x3b;
    uint32_t ROUTELOC2; // I/O Routing Location Register
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
    uint32_t CC0_CTRL; // CC Channel Control Register
    uint32_t CC0_CCV; // CC Channel Value Register
    uint32_t CC0_CCVP; // CC Channel Value Peek Register
    uint32_t CC0_CCVB; // CC Channel Buffer Register
    uint32_t CC1_CTRL; // CC Channel Control Register
    uint32_t CC1_CCV; // CC Channel Value Register
    uint32_t CC1_CCVP; // CC Channel Value Peek Register
    uint32_t CC1_CCVB; // CC Channel Buffer Register
    uint32_t CC2_CTRL; // CC Channel Control Register
    uint32_t CC2_CCV; // CC Channel Value Register
    uint32_t CC2_CCVP; // CC Channel Value Peek Register
    uint32_t CC2_CCVB; // CC Channel Buffer Register
    uint32_t CC3_CTRL; // CC Channel Control Register
    uint32_t CC3_CCV; // CC Channel Value Register
    uint32_t CC3_CCVP; // CC Channel Value Peek Register
    uint32_t CC3_CCVB; // CC Channel Buffer Register
    uint32_t DTCTRL; // DTI Control Register
    uint32_t DTTIME; // DTI Time Control Register
    uint32_t DTFC; // DTI Fault Configuration Register
    uint32_t DTOGEN; // DTI Output Generation Enable Register
    uint32_t DTFAULT; // DTI Fault Register
    uint32_t DTFAULTC; // DTI Fault Clear Register
    uint32_t DTLOCK; // DTI Configuration Lock Register
};

typedef struct BUFC_CLR BUFC_CLR, *PBUFC_CLR;

struct BUFC_CLR {
    uint32_t BUF0_CTRL;
    uint32_t BUF0_ADDR;
    uint32_t BUF0_WRITEOFFSET;
    uint32_t BUF0_READOFFSET;
    uint32_t BUF0_WRITESTART;
    uint32_t BUF0_READDATA;
    uint32_t BUF0_WRITEDATA;
    uint32_t BUF0_XWRITE;
    uint32_t BUF0_STATUS;
    uint32_t BUF0_THRESHOLDCTRL;
    uint32_t BUF0_CMD;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    uint32_t BUF1_CTRL;
    uint32_t BUF1_ADDR;
    uint32_t BUF1_WRITEOFFSET;
    uint32_t BUF1_READOFFSET;
    uint32_t BUF1_WRITESTART;
    uint32_t BUF1_READDATA;
    uint32_t BUF1_WRITEDATA;
    uint32_t BUF1_XWRITE;
    uint32_t BUF1_STATUS;
    uint32_t BUF1_THRESHOLDCTRL;
    uint32_t BUF1_CMD;
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    uint32_t BUF2_CTRL;
    uint32_t BUF2_ADDR;
    uint32_t BUF2_WRITEOFFSET;
    uint32_t BUF2_READOFFSET;
    uint32_t BUF2_WRITESTART;
    uint32_t BUF2_READDATA;
    uint32_t BUF2_WRITEDATA;
    uint32_t BUF2_XWRITE;
    uint32_t BUF2_STATUS;
    uint32_t BUF2_THRESHOLDCTR;
    uint32_t BUF2_CMD;
    undefined field_0x8c;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
    uint32_t BUF3_CTRL;
    uint32_t BUF3_ADDR;
    uint32_t BUF3_WRITEOFFSET;
    uint32_t BUF3_READOFFSET;
    uint32_t BUF3_WRITESTART;
    uint32_t BUF3_READDATA;
    uint32_t BUF3_WRITEDATA;
    uint32_t BUF3_XWRITE;
    uint32_t BUF3_STATUS;
    uint32_t BUF3_THRESHOLDCTRL;
    uint32_t BUF3_CMD;
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
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
};

typedef struct USART0 USART0, *PUSART0;

struct USART0 {
    uint32_t CTRL; // Control Register
    uint32_t FRAME; // USART Frame Format Register
    uint32_t TRIGCTRL; // USART Trigger Control Register
    uint32_t CMD; // Command Register
    uint32_t STATUS; // USART Status Register
    uint32_t CLKDIV; // Clock Control Register
    uint32_t RXDATAX; // RX Buffer Data Extended Register
    uint32_t RXDATA; // RX Buffer Data Register
    uint32_t RXDOUBLEX; // RX Buffer Double Data Extended Register
    uint32_t RXDOUBLE; // RX FIFO Double Data Register
    uint32_t RXDATAXP; // RX Buffer Data Extended Peek Register
    uint32_t RXDOUBLEXP; // RX Buffer Double Data Extended Peek Register
    uint32_t TXDATAX; // TX Buffer Data Extended Register
    uint32_t TXDATA; // TX Buffer Data Register
    uint32_t TXDOUBLEX; // TX Buffer Double Data Extended Register
    uint32_t TXDOUBLE; // TX Buffer Double Data Register
    uint32_t IF; // Interrupt Flag Register
    uint32_t IFS; // Interrupt Flag Set Register
    uint32_t IFC; // Interrupt Flag Clear Register
    uint32_t IEN; // Interrupt Enable Register
    uint32_t IRCTRL; // IrDA Control Register
    undefined field_0x54;
    undefined field_0x55;
    undefined field_0x56;
    undefined field_0x57;
    uint32_t INPUT; // USART Input Register
    uint32_t I2SCTRL; // I2S Control Register
    uint32_t TIMING; // Timing Register
    uint32_t CTRLX; // Control Register Extended
    uint32_t TIMECMP0; // Used to Generate Interrupts and Various Delays
    uint32_t TIMECMP1; // Used to Generate Interrupts and Various Delays
    uint32_t TIMECMP2; // Used to Generate Interrupts and Various Delays
    uint32_t ROUTEPEN; // I/O Routing Pin Enable Register
    uint32_t ROUTELOC0; // I/O Routing Location Register
    uint32_t ROUTELOC1; // I/O Routing Location Register
};

typedef struct MSC MSC, *PMSC;

struct MSC {
    uint32_t CTRL; // Memory System Control Register
    uint32_t READCTRL; // Read Control Register
    uint32_t WRITECTRL; // Write Control Register
    uint32_t WRITECMD; // Write Command Register
    uint32_t ADDRB; // Page Erase/Write Address Buffer
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    uint32_t WDATA; // Write Data Register
    uint32_t STATUS; // Status Register
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
    uint32_t IF; // Interrupt Flag Register
    uint32_t IFS; // Interrupt Flag Set Register
    uint32_t IFC; // Interrupt Flag Clear Register
    uint32_t IEN; // Interrupt Enable Register
    uint32_t LOCK; // Configuration Lock Register
    uint32_t CACHECMD; // Flash Cache Command Register
    uint32_t CACHEHITS; // Cache Hits Performance Counter
    uint32_t CACHEMISSES; // Cache Misses Performance Counter
    undefined field_0x50;
    undefined field_0x51;
    undefined field_0x52;
    undefined field_0x53;
    uint32_t MASSLOCK; // Mass Erase Lock Register
    undefined field_0x58;
    undefined field_0x59;
    undefined field_0x5a;
    undefined field_0x5b;
    uint32_t STARTUP; // Startup Control
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
    uint32_t CMD; // Command Register
};

typedef struct RFSENSE_CLR RFSENSE_CLR, *PRFSENSE_CLR;

struct RFSENSE_CLR {
    uint32_t CTRL;
    uint32_t PERIODSEL;
    uint32_t CNT;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    uint32_t EM4WUEN;
    uint32_t CALIB;
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
};

typedef struct AGC AGC, *PAGC;

struct AGC {
    uint32_t STATUS0;
    uint32_t STATUS1;
    uint32_t RSSI;
    uint32_t FRAMERSSI;
    undefined field_0x10;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    uint32_t CTRL0;
    uint32_t CTRL1;
    uint32_t CTRL2;
    uint32_t RSSISTEPTHR;
    uint32_t IFPEAKDET;
    uint32_t MANGAIN;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
    uint32_t CMD;
    undefined field_0x44;
    undefined field_0x45;
    undefined field_0x46;
    undefined field_0x47;
    uint32_t GAINRANGE;
    uint32_t GAININDEX;
    uint32_t SLICECODE;
    uint32_t ATTENCODE1;
    uint32_t ATTENCODE2;
    uint32_t ATTENCODE3;
    uint32_t GAINERROR1;
    uint32_t GAINERROR2;
    uint32_t GAINERROR3;
    uint32_t MANUALCTRL;
    uint32_t GAINSTEPLIM;
    uint32_t LOOPDEL;
    uint32_t MININDEX;
};

typedef struct AGC_CLR AGC_CLR, *PAGC_CLR;

struct AGC_CLR {
    uint32_t STATUS0;
    uint32_t STATUS1;
    uint32_t RSSI;
    uint32_t FRAMERSSI;
    undefined field_0x10;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    uint32_t CTRL0;
    uint32_t CTRL1;
    uint32_t CTRL2;
    uint32_t RSSISTEPTHR;
    uint32_t IFPEAKDET;
    uint32_t MANGAIN;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
    uint32_t CMD;
    undefined field_0x44;
    undefined field_0x45;
    undefined field_0x46;
    undefined field_0x47;
    uint32_t GAINRANGE;
    uint32_t GAININDEX;
    uint32_t SLICECODE;
    uint32_t ATTENCODE1;
    uint32_t ATTENCODE2;
    uint32_t ATTENCODE3;
    uint32_t GAINERROR1;
    uint32_t GAINERROR2;
    uint32_t GAINERROR3;
    uint32_t MANUALCTRL;
    uint32_t GAINSTEPLIM;
    uint32_t LOOPDEL;
    uint32_t MININDEX;
};

typedef struct DEVINFO DEVINFO, *PDEVINFO;

struct DEVINFO {
    uint32_t CAL;
    uint32_t MODULEINFO;
    uint32_t MODXOCAL;
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
    uint32_t EXTINFO;
    undefined field_0x24;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
    uint32_t EUI48L;
    uint32_t EUI48H;
    uint32_t CUSTOMINFO;
    uint32_t MEMINFO;
    undefined field_0x38;
    undefined field_0x39;
    undefined field_0x3a;
    undefined field_0x3b;
    undefined field_0x3c;
    undefined field_0x3d;
    undefined field_0x3e;
    undefined field_0x3f;
    uint32_t UNIQUEL;
    uint32_t UNIQUEH;
    uint32_t MSIZE;
    uint32_t PART;
    uint32_t DEVINFOREV;
    uint32_t EMUTEMP;
    undefined field_0x58;
    undefined field_0x59;
    undefined field_0x5a;
    undefined field_0x5b;
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    uint32_t ADC0CAL0;
    uint32_t ADC0CAL1;
    uint32_t ADC0CAL2;
    uint32_t ADC0CAL3;
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
    uint32_t HFRCOCAL0;
    undefined field_0x84;
    undefined field_0x85;
    undefined field_0x86;
    undefined field_0x87;
    undefined field_0x88;
    undefined field_0x89;
    undefined field_0x8a;
    undefined field_0x8b;
    uint32_t HFRCOCAL3;
    undefined field_0x90;
    undefined field_0x91;
    undefined field_0x92;
    undefined field_0x93;
    undefined field_0x94;
    undefined field_0x95;
    undefined field_0x96;
    undefined field_0x97;
    uint32_t HFRCOCAL6;
    uint32_t HFRCOCAL7;
    uint32_t HFRCOCAL8;
    undefined field_0xa4;
    undefined field_0xa5;
    undefined field_0xa6;
    undefined field_0xa7;
    uint32_t HFRCOCAL10;
    uint32_t HFRCOCAL11;
    uint32_t HFRCOCAL12;
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
    uint32_t AUXHFRCOCAL0;
    undefined field_0xe4;
    undefined field_0xe5;
    undefined field_0xe6;
    undefined field_0xe7;
    undefined field_0xe8;
    undefined field_0xe9;
    undefined field_0xea;
    undefined field_0xeb;
    uint32_t AUXHFRCOCAL3;
    undefined field_0xf0;
    undefined field_0xf1;
    undefined field_0xf2;
    undefined field_0xf3;
    undefined field_0xf4;
    undefined field_0xf5;
    undefined field_0xf6;
    undefined field_0xf7;
    uint32_t AUXHFRCOCAL6;
    uint32_t AUXHFRCOCAL7;
    uint32_t AUXHFRCOCAL8;
    undefined field_0x104;
    undefined field_0x105;
    undefined field_0x106;
    undefined field_0x107;
    uint32_t AUXHFRCOCAL10;
    uint32_t AUXHFRCOCAL11;
    uint32_t AUXHFRCOCAL12;
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
    uint32_t VMONCAL0;
    uint32_t VMONCAL1;
    uint32_t VMONCAL2;
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
    uint32_t IDAC0CAL0;
    uint32_t IDAC0CAL1;
    undefined field_0x160;
    undefined field_0x161;
    undefined field_0x162;
    undefined field_0x163;
    undefined field_0x164;
    undefined field_0x165;
    undefined field_0x166;
    undefined field_0x167;
    uint32_t DCDCLNVCTRL0;
    uint32_t DCDCLPVCTRL0;
    uint32_t DCDCLPVCTRL1;
    uint32_t DCDCLPVCTRL2;
    uint32_t DCDCLPVCTRL3;
    uint32_t DCDCLPCMPHYSSEL0;
    uint32_t DCDCLPCMPHYSSEL1;
};

typedef struct MODEM MODEM, *PMODEM;

struct MODEM {
    uint32_t STATUS;
    uint32_t TIMDETSTATUS;
    uint32_t FREQOFFEST;
    uint32_t AFCADJRX;
    uint32_t AFCADJTX;
    uint32_t MIXCTRL;
    uint32_t CTRL0;
    uint32_t CTRL1;
    uint32_t CTRL2;
    uint32_t CTRL3;
    uint32_t CTRL4;
    uint32_t CTRL5;
    uint32_t TXBR;
    uint32_t RXBR;
    uint32_t CF;
    uint32_t PRE;
    uint32_t SYNC0;
    uint32_t SYNC1;
    uint32_t TIMING;
    uint32_t DSSS0;
    uint32_t MODINDEX;
    uint32_t AFC;
    uint32_t AFCADJLIM;
    uint32_t SHAPING0;
    uint32_t SHAPING1;
    uint32_t SHAPING2;
    uint32_t RAMPCTRL;
    uint32_t RAMPLEV;
    uint32_t ROUTEPEN;
    uint32_t ROUTELOC0;
    uint32_t ROUTELOC1;
    undefined field_0x7c;
    undefined field_0x7d;
    undefined field_0x7e;
    undefined field_0x7f;
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
    uint32_t CMD;
    undefined field_0x94;
    undefined field_0x95;
    undefined field_0x96;
    undefined field_0x97;
    uint32_t DCCOMP;
    uint32_t DCCOMPFILTINIT;
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
    uint32_t DCESTI;
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
    uint32_t RAM0_RAMDATA;
    uint32_t RAM1_RAMDATA;
    uint32_t RAM2_RAMDATA;
    uint32_t RAM3_RAMDATA;
    uint32_t RAM4_RAMDATA;
    uint32_t RAM5_RAMDATA;
    uint32_t RAM6_RAMDATA;
    uint32_t RAM7_RAMDATA;
    uint32_t RAM8_RAMDATA;
    uint32_t RAM9_RAMDATA;
    uint32_t RAM10_RAMDATA;
    uint32_t RAM11_RAMDATA;
    uint32_t RAM12_RAMDATA;
    uint32_t RAM13_RAMDATA;
    uint32_t RAM14_RAMDATA;
    uint32_t RAM15_RAMDATA;
    uint32_t RAM16_RAMDATA;
    uint32_t RAM17_RAMDATA;
    uint32_t RAM18_RAMDATA;
    uint32_t RAM19_RAMDATA;
    uint32_t RAM20_RAMDATA;
    uint32_t RAM21_RAMDATA;
    uint32_t RAM22_RAMDATA;
    uint32_t RAM23_RAMDATA;
    uint32_t RAM24_RAMDATA;
    uint32_t RAM25_RAMDATA;
    uint32_t RAM26_RAMDATA;
    uint32_t RAM27_RAMDATA;
    uint32_t RAM28_RAMDATA;
    uint32_t RAM29_RAMDATA;
    uint32_t RAM30_RAMDATA;
    uint32_t RAM31_RAMDATA;
    uint32_t RAM32_RAMDATA;
    uint32_t RAM33_RAMDATA;
    uint32_t RAM34_RAMDATA;
    uint32_t RAM35_RAMDATA;
    uint32_t RAM36_RAMDATA;
    uint32_t RAM37_RAMDATA;
    uint32_t RAM38_RAMDATA;
    uint32_t RAM39_RAMDATA;
    uint32_t RAM40_RAMDATA;
    uint32_t RAM41_RAMDATA;
    uint32_t RAM42_RAMDATA;
    uint32_t RAM43_RAMDATA;
    uint32_t RAM44_RAMDATA;
    uint32_t RAM45_RAMDATA;
    uint32_t RAM46_RAMDATA;
    uint32_t RAM47_RAMDATA;
    uint32_t RAM48_RAMDATA;
    uint32_t RAM49_RAMDATA;
    uint32_t RAM50_RAMDATA;
    uint32_t RAM51_RAMDATA;
    uint32_t RAM52_RAMDATA;
    uint32_t RAM53_RAMDATA;
    uint32_t RAM54_RAMDATA;
    uint32_t RAM55_RAMDATA;
    uint32_t RAM56_RAMDATA;
    uint32_t RAM57_RAMDATA;
    uint32_t RAM58_RAMDATA;
    uint32_t RAM59_RAMDATA;
    uint32_t RAM60_RAMDATA;
    uint32_t RAM61_RAMDATA;
    uint32_t RAM62_RAMDATA;
    uint32_t RAM63_RAMDATA;
    uint32_t RAM64_RAMDATA;
    uint32_t RAM65_RAMDATA;
    uint32_t RAM66_RAMDATA;
    uint32_t RAM67_RAMDATA;
    uint32_t RAM68_RAMDATA;
    uint32_t RAM69_RAMDATA;
    uint32_t RAM70_RAMDATA;
    uint32_t RAM71_RAMDATA;
    uint32_t RAM72_RAMDATA;
    uint32_t RAM73_RAMDATA;
    uint32_t RAM74_RAMDATA;
    uint32_t RAM75_RAMDATA;
    uint32_t RAM76_RAMDATA;
    uint32_t RAM77_RAMDATA;
    uint32_t RAM78_RAMDATA;
    uint32_t RAM79_RAMDATA;
    uint32_t RAM80_RAMDATA;
    uint32_t RAM81_RAMDATA;
    uint32_t RAM82_RAMDATA;
    uint32_t RAM83_RAMDATA;
    uint32_t RAM84_RAMDATA;
    uint32_t RAM85_RAMDATA;
    uint32_t RAM86_RAMDATA;
    uint32_t RAM87_RAMDATA;
    uint32_t RAM88_RAMDATA;
    uint32_t RAM89_RAMDATA;
    uint32_t RAM90_RAMDATA;
    uint32_t RAM91_RAMDATA;
    uint32_t RAM92_RAMDATA;
    uint32_t RAM93_RAMDATA;
    uint32_t RAM94_RAMDATA;
    uint32_t RAM95_RAMDATA;
    uint32_t RAM96_RAMDATA;
    uint32_t RAM97_RAMDATA;
    uint32_t RAM98_RAMDATA;
    uint32_t RAM99_RAMDATA;
    uint32_t RAM100_RAMDATA;
    uint32_t RAM101_RAMDATA;
    uint32_t RAM102_RAMDATA;
    uint32_t RAM103_RAMDATA;
    uint32_t RAM104_RAMDATA;
    uint32_t RAM105_RAMDATA;
    uint32_t RAM106_RAMDATA;
    uint32_t RAM107_RAMDATA;
    uint32_t RAM108_RAMDATA;
    uint32_t RAM109_RAMDATA;
    uint32_t RAM110_RAMDATA;
    uint32_t RAM111_RAMDATA;
    uint32_t RAM112_RAMDATA;
    uint32_t RAM113_RAMDATA;
    uint32_t RAM114_RAMDATA;
    uint32_t RAM115_RAMDATA;
    uint32_t RAM116_RAMDATA;
    uint32_t RAM117_RAMDATA;
    uint32_t RAM118_RAMDATA;
    uint32_t RAM119_RAMDATA;
    uint32_t RAM120_RAMDATA;
    uint32_t RAM121_RAMDATA;
    uint32_t RAM122_RAMDATA;
    uint32_t RAM123_RAMDATA;
    uint32_t RAM124_RAMDATA;
    uint32_t RAM125_RAMDATA;
    uint32_t RAM126_RAMDATA;
    uint32_t RAM127_RAMDATA;
    uint32_t RAM128_RAMDATA;
    uint32_t RAM129_RAMDATA;
    uint32_t RAM130_RAMDATA;
    uint32_t RAM131_RAMDATA;
    uint32_t RAM132_RAMDATA;
    uint32_t RAM133_RAMDATA;
    uint32_t RAM134_RAMDATA;
    uint32_t RAM135_RAMDATA;
    uint32_t RAM136_RAMDATA;
    uint32_t RAM137_RAMDATA;
    uint32_t RAM138_RAMDATA;
    uint32_t RAM139_RAMDATA;
    uint32_t RAM140_RAMDATA;
    uint32_t RAM141_RAMDATA;
    uint32_t RAM142_RAMDATA;
    uint32_t RAM143_RAMDATA;
    uint32_t RAM144_RAMDATA;
    uint32_t RAM145_RAMDATA;
    uint32_t RAM146_RAMDATA;
    uint32_t RAM147_RAMDATA;
    uint32_t RAM148_RAMDATA;
    uint32_t RAM149_RAMDATA;
    uint32_t RAM150_RAMDATA;
    uint32_t RAM151_RAMDATA;
    uint32_t RAM152_RAMDATA;
    uint32_t RAM153_RAMDATA;
    uint32_t RAM154_RAMDATA;
    uint32_t RAM155_RAMDATA;
    uint32_t RAM156_RAMDATA;
    uint32_t RAM157_RAMDATA;
    uint32_t RAM158_RAMDATA;
    uint32_t RAM159_RAMDATA;
    uint32_t RAM160_RAMDATA;
    uint32_t RAM161_RAMDATA;
    uint32_t RAM162_RAMDATA;
    uint32_t RAM163_RAMDATA;
    uint32_t RAM164_RAMDATA;
    uint32_t RAM165_RAMDATA;
    uint32_t RAM166_RAMDATA;
    uint32_t RAM167_RAMDATA;
    uint32_t RAM168_RAMDATA;
    uint32_t RAM169_RAMDATA;
    uint32_t RAM170_RAMDATA;
    uint32_t RAM171_RAMDATA;
    uint32_t RAM172_RAMDATA;
    uint32_t RAM173_RAMDATA;
    uint32_t RAM174_RAMDATA;
    uint32_t RAM175_RAMDATA;
    uint32_t RAM176_RAMDATA;
    uint32_t RAM177_RAMDATA;
    uint32_t RAM178_RAMDATA;
    uint32_t RAM179_RAMDATA;
    uint32_t RAM180_RAMDATA;
    uint32_t RAM181_RAMDATA;
    uint32_t RAM182_RAMDATA;
    uint32_t RAM183_RAMDATA;
    uint32_t RAM184_RAMDATA;
    uint32_t RAM185_RAMDATA;
    uint32_t RAM186_RAMDATA;
    uint32_t RAM187_RAMDATA;
    uint32_t RAM188_RAMDATA;
    uint32_t RAM189_RAMDATA;
    uint32_t RAM190_RAMDATA;
    uint32_t RAM191_RAMDATA;
    uint32_t RAM192_RAMDATA;
    uint32_t RAM193_RAMDATA;
    uint32_t RAM194_RAMDATA;
    uint32_t RAM195_RAMDATA;
    uint32_t RAM196_RAMDATA;
    uint32_t RAM197_RAMDATA;
    uint32_t RAM198_RAMDATA;
    uint32_t RAM199_RAMDATA;
    uint32_t RAM200_RAMDATA;
    uint32_t RAM201_RAMDATA;
    uint32_t RAM202_RAMDATA;
    uint32_t RAM203_RAMDATA;
    uint32_t RAM204_RAMDATA;
    uint32_t RAM205_RAMDATA;
    uint32_t RAM206_RAMDATA;
    uint32_t RAM207_RAMDATA;
    uint32_t RAM208_RAMDATA;
    uint32_t RAM209_RAMDATA;
    uint32_t RAM210_RAMDATA;
    uint32_t RAM211_RAMDATA;
    uint32_t RAM212_RAMDATA;
    uint32_t RAM213_RAMDATA;
    uint32_t RAM214_RAMDATA;
    uint32_t RAM215_RAMDATA;
    uint32_t RAM216_RAMDATA;
    uint32_t RAM217_RAMDATA;
    uint32_t RAM218_RAMDATA;
    uint32_t RAM219_RAMDATA;
    uint32_t RAM220_RAMDATA;
    uint32_t RAM221_RAMDATA;
    uint32_t RAM222_RAMDATA;
    uint32_t RAM223_RAMDATA;
    uint32_t RAM224_RAMDATA;
    uint32_t RAM225_RAMDATA;
    uint32_t RAM226_RAMDATA;
    uint32_t RAM227_RAMDATA;
    uint32_t RAM228_RAMDATA;
    uint32_t RAM229_RAMDATA;
    uint32_t RAM230_RAMDATA;
    uint32_t RAM231_RAMDATA;
    uint32_t RAM232_RAMDATA;
    uint32_t RAM233_RAMDATA;
    uint32_t RAM234_RAMDATA;
    uint32_t RAM235_RAMDATA;
    uint32_t RAM236_RAMDATA;
    uint32_t RAM237_RAMDATA;
    uint32_t RAM238_RAMDATA;
    uint32_t RAM239_RAMDATA;
    uint32_t RAM240_RAMDATA;
    uint32_t RAM241_RAMDATA;
    uint32_t RAM242_RAMDATA;
    uint32_t RAM243_RAMDATA;
    uint32_t RAM244_RAMDATA;
    uint32_t RAM245_RAMDATA;
    uint32_t RAM246_RAMDATA;
    uint32_t RAM247_RAMDATA;
    uint32_t RAM248_RAMDATA;
    uint32_t RAM249_RAMDATA;
    uint32_t RAM250_RAMDATA;
    uint32_t RAM251_RAMDATA;
    uint32_t RAM252_RAMDATA;
    uint32_t RAM253_RAMDATA;
    uint32_t RAM254_RAMDATA;
    uint32_t RAM255_RAMDATA;
};

typedef struct MODEM_SET MODEM_SET, *PMODEM_SET;

struct MODEM_SET {
    uint32_t STATUS;
    uint32_t TIMDETSTATUS;
    uint32_t FREQOFFEST;
    uint32_t AFCADJRX;
    uint32_t AFCADJTX;
    uint32_t MIXCTRL;
    uint32_t CTRL0;
    uint32_t CTRL1;
    uint32_t CTRL2;
    uint32_t CTRL3;
    uint32_t CTRL4;
    uint32_t CTRL5;
    uint32_t TXBR;
    uint32_t RXBR;
    uint32_t CF;
    uint32_t PRE;
    uint32_t SYNC0;
    uint32_t SYNC1;
    uint32_t TIMING;
    uint32_t DSSS0;
    uint32_t MODINDEX;
    uint32_t AFC;
    uint32_t AFCADJLIM;
    uint32_t SHAPING0;
    uint32_t SHAPING1;
    uint32_t SHAPING2;
    uint32_t RAMPCTRL;
    uint32_t RAMPLEV;
    uint32_t ROUTEPEN;
    uint32_t ROUTELOC0;
    uint32_t ROUTELOC1;
    undefined field_0x7c;
    undefined field_0x7d;
    undefined field_0x7e;
    undefined field_0x7f;
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
    uint32_t CMD;
    undefined field_0x94;
    undefined field_0x95;
    undefined field_0x96;
    undefined field_0x97;
    uint32_t DCCOMP;
    uint32_t DCCOMPFILTINIT;
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
    uint32_t DCESTI;
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
    uint32_t RAM0_RAMDATA;
    uint32_t RAM1_RAMDATA;
    uint32_t RAM2_RAMDATA;
    uint32_t RAM3_RAMDATA;
    uint32_t RAM4_RAMDATA;
    uint32_t RAM5_RAMDATA;
    uint32_t RAM6_RAMDATA;
    uint32_t RAM7_RAMDATA;
    uint32_t RAM8_RAMDATA;
    uint32_t RAM9_RAMDATA;
    uint32_t RAM10_RAMDATA;
    uint32_t RAM11_RAMDATA;
    uint32_t RAM12_RAMDATA;
    uint32_t RAM13_RAMDATA;
    uint32_t RAM14_RAMDATA;
    uint32_t RAM15_RAMDATA;
    uint32_t RAM16_RAMDATA;
    uint32_t RAM17_RAMDATA;
    uint32_t RAM18_RAMDATA;
    uint32_t RAM19_RAMDATA;
    uint32_t RAM20_RAMDATA;
    uint32_t RAM21_RAMDATA;
    uint32_t RAM22_RAMDATA;
    uint32_t RAM23_RAMDATA;
    uint32_t RAM24_RAMDATA;
    uint32_t RAM25_RAMDATA;
    uint32_t RAM26_RAMDATA;
    uint32_t RAM27_RAMDATA;
    uint32_t RAM28_RAMDATA;
    uint32_t RAM29_RAMDATA;
    uint32_t RAM30_RAMDATA;
    uint32_t RAM31_RAMDATA;
    uint32_t RAM32_RAMDATA;
    uint32_t RAM33_RAMDATA;
    uint32_t RAM34_RAMDATA;
    uint32_t RAM35_RAMDATA;
    uint32_t RAM36_RAMDATA;
    uint32_t RAM37_RAMDATA;
    uint32_t RAM38_RAMDATA;
    uint32_t RAM39_RAMDATA;
    uint32_t RAM40_RAMDATA;
    uint32_t RAM41_RAMDATA;
    uint32_t RAM42_RAMDATA;
    uint32_t RAM43_RAMDATA;
    uint32_t RAM44_RAMDATA;
    uint32_t RAM45_RAMDATA;
    uint32_t RAM46_RAMDATA;
    uint32_t RAM47_RAMDATA;
    uint32_t RAM48_RAMDATA;
    uint32_t RAM49_RAMDATA;
    uint32_t RAM50_RAMDATA;
    uint32_t RAM51_RAMDATA;
    uint32_t RAM52_RAMDATA;
    uint32_t RAM53_RAMDATA;
    uint32_t RAM54_RAMDATA;
    uint32_t RAM55_RAMDATA;
    uint32_t RAM56_RAMDATA;
    uint32_t RAM57_RAMDATA;
    uint32_t RAM58_RAMDATA;
    uint32_t RAM59_RAMDATA;
    uint32_t RAM60_RAMDATA;
    uint32_t RAM61_RAMDATA;
    uint32_t RAM62_RAMDATA;
    uint32_t RAM63_RAMDATA;
    uint32_t RAM64_RAMDATA;
    uint32_t RAM65_RAMDATA;
    uint32_t RAM66_RAMDATA;
    uint32_t RAM67_RAMDATA;
    uint32_t RAM68_RAMDATA;
    uint32_t RAM69_RAMDATA;
    uint32_t RAM70_RAMDATA;
    uint32_t RAM71_RAMDATA;
    uint32_t RAM72_RAMDATA;
    uint32_t RAM73_RAMDATA;
    uint32_t RAM74_RAMDATA;
    uint32_t RAM75_RAMDATA;
    uint32_t RAM76_RAMDATA;
    uint32_t RAM77_RAMDATA;
    uint32_t RAM78_RAMDATA;
    uint32_t RAM79_RAMDATA;
    uint32_t RAM80_RAMDATA;
    uint32_t RAM81_RAMDATA;
    uint32_t RAM82_RAMDATA;
    uint32_t RAM83_RAMDATA;
    uint32_t RAM84_RAMDATA;
    uint32_t RAM85_RAMDATA;
    uint32_t RAM86_RAMDATA;
    uint32_t RAM87_RAMDATA;
    uint32_t RAM88_RAMDATA;
    uint32_t RAM89_RAMDATA;
    uint32_t RAM90_RAMDATA;
    uint32_t RAM91_RAMDATA;
    uint32_t RAM92_RAMDATA;
    uint32_t RAM93_RAMDATA;
    uint32_t RAM94_RAMDATA;
    uint32_t RAM95_RAMDATA;
    uint32_t RAM96_RAMDATA;
    uint32_t RAM97_RAMDATA;
    uint32_t RAM98_RAMDATA;
    uint32_t RAM99_RAMDATA;
    uint32_t RAM100_RAMDATA;
    uint32_t RAM101_RAMDATA;
    uint32_t RAM102_RAMDATA;
    uint32_t RAM103_RAMDATA;
    uint32_t RAM104_RAMDATA;
    uint32_t RAM105_RAMDATA;
    uint32_t RAM106_RAMDATA;
    uint32_t RAM107_RAMDATA;
    uint32_t RAM108_RAMDATA;
    uint32_t RAM109_RAMDATA;
    uint32_t RAM110_RAMDATA;
    uint32_t RAM111_RAMDATA;
    uint32_t RAM112_RAMDATA;
    uint32_t RAM113_RAMDATA;
    uint32_t RAM114_RAMDATA;
    uint32_t RAM115_RAMDATA;
    uint32_t RAM116_RAMDATA;
    uint32_t RAM117_RAMDATA;
    uint32_t RAM118_RAMDATA;
    uint32_t RAM119_RAMDATA;
    uint32_t RAM120_RAMDATA;
    uint32_t RAM121_RAMDATA;
    uint32_t RAM122_RAMDATA;
    uint32_t RAM123_RAMDATA;
    uint32_t RAM124_RAMDATA;
    uint32_t RAM125_RAMDATA;
    uint32_t RAM126_RAMDATA;
    uint32_t RAM127_RAMDATA;
    uint32_t RAM128_RAMDATA;
    uint32_t RAM129_RAMDATA;
    uint32_t RAM130_RAMDATA;
    uint32_t RAM131_RAMDATA;
    uint32_t RAM132_RAMDATA;
    uint32_t RAM133_RAMDATA;
    uint32_t RAM134_RAMDATA;
    uint32_t RAM135_RAMDATA;
    uint32_t RAM136_RAMDATA;
    uint32_t RAM137_RAMDATA;
    uint32_t RAM138_RAMDATA;
    uint32_t RAM139_RAMDATA;
    uint32_t RAM140_RAMDATA;
    uint32_t RAM141_RAMDATA;
    uint32_t RAM142_RAMDATA;
    uint32_t RAM143_RAMDATA;
    uint32_t RAM144_RAMDATA;
    uint32_t RAM145_RAMDATA;
    uint32_t RAM146_RAMDATA;
    uint32_t RAM147_RAMDATA;
    uint32_t RAM148_RAMDATA;
    uint32_t RAM149_RAMDATA;
    uint32_t RAM150_RAMDATA;
    uint32_t RAM151_RAMDATA;
    uint32_t RAM152_RAMDATA;
    uint32_t RAM153_RAMDATA;
    uint32_t RAM154_RAMDATA;
    uint32_t RAM155_RAMDATA;
    uint32_t RAM156_RAMDATA;
    uint32_t RAM157_RAMDATA;
    uint32_t RAM158_RAMDATA;
    uint32_t RAM159_RAMDATA;
    uint32_t RAM160_RAMDATA;
    uint32_t RAM161_RAMDATA;
    uint32_t RAM162_RAMDATA;
    uint32_t RAM163_RAMDATA;
    uint32_t RAM164_RAMDATA;
    uint32_t RAM165_RAMDATA;
    uint32_t RAM166_RAMDATA;
    uint32_t RAM167_RAMDATA;
    uint32_t RAM168_RAMDATA;
    uint32_t RAM169_RAMDATA;
    uint32_t RAM170_RAMDATA;
    uint32_t RAM171_RAMDATA;
    uint32_t RAM172_RAMDATA;
    uint32_t RAM173_RAMDATA;
    uint32_t RAM174_RAMDATA;
    uint32_t RAM175_RAMDATA;
    uint32_t RAM176_RAMDATA;
    uint32_t RAM177_RAMDATA;
    uint32_t RAM178_RAMDATA;
    uint32_t RAM179_RAMDATA;
    uint32_t RAM180_RAMDATA;
    uint32_t RAM181_RAMDATA;
    uint32_t RAM182_RAMDATA;
    uint32_t RAM183_RAMDATA;
    uint32_t RAM184_RAMDATA;
    uint32_t RAM185_RAMDATA;
    uint32_t RAM186_RAMDATA;
    uint32_t RAM187_RAMDATA;
    uint32_t RAM188_RAMDATA;
    uint32_t RAM189_RAMDATA;
    uint32_t RAM190_RAMDATA;
    uint32_t RAM191_RAMDATA;
    uint32_t RAM192_RAMDATA;
    uint32_t RAM193_RAMDATA;
    uint32_t RAM194_RAMDATA;
    uint32_t RAM195_RAMDATA;
    uint32_t RAM196_RAMDATA;
    uint32_t RAM197_RAMDATA;
    uint32_t RAM198_RAMDATA;
    uint32_t RAM199_RAMDATA;
    uint32_t RAM200_RAMDATA;
    uint32_t RAM201_RAMDATA;
    uint32_t RAM202_RAMDATA;
    uint32_t RAM203_RAMDATA;
    uint32_t RAM204_RAMDATA;
    uint32_t RAM205_RAMDATA;
    uint32_t RAM206_RAMDATA;
    uint32_t RAM207_RAMDATA;
    uint32_t RAM208_RAMDATA;
    uint32_t RAM209_RAMDATA;
    uint32_t RAM210_RAMDATA;
    uint32_t RAM211_RAMDATA;
    uint32_t RAM212_RAMDATA;
    uint32_t RAM213_RAMDATA;
    uint32_t RAM214_RAMDATA;
    uint32_t RAM215_RAMDATA;
    uint32_t RAM216_RAMDATA;
    uint32_t RAM217_RAMDATA;
    uint32_t RAM218_RAMDATA;
    uint32_t RAM219_RAMDATA;
    uint32_t RAM220_RAMDATA;
    uint32_t RAM221_RAMDATA;
    uint32_t RAM222_RAMDATA;
    uint32_t RAM223_RAMDATA;
    uint32_t RAM224_RAMDATA;
    uint32_t RAM225_RAMDATA;
    uint32_t RAM226_RAMDATA;
    uint32_t RAM227_RAMDATA;
    uint32_t RAM228_RAMDATA;
    uint32_t RAM229_RAMDATA;
    uint32_t RAM230_RAMDATA;
    uint32_t RAM231_RAMDATA;
    uint32_t RAM232_RAMDATA;
    uint32_t RAM233_RAMDATA;
    uint32_t RAM234_RAMDATA;
    uint32_t RAM235_RAMDATA;
    uint32_t RAM236_RAMDATA;
    uint32_t RAM237_RAMDATA;
    uint32_t RAM238_RAMDATA;
    uint32_t RAM239_RAMDATA;
    uint32_t RAM240_RAMDATA;
    uint32_t RAM241_RAMDATA;
    uint32_t RAM242_RAMDATA;
    uint32_t RAM243_RAMDATA;
    uint32_t RAM244_RAMDATA;
    uint32_t RAM245_RAMDATA;
    uint32_t RAM246_RAMDATA;
    uint32_t RAM247_RAMDATA;
    uint32_t RAM248_RAMDATA;
    uint32_t RAM249_RAMDATA;
    uint32_t RAM250_RAMDATA;
    uint32_t RAM251_RAMDATA;
    uint32_t RAM252_RAMDATA;
    uint32_t RAM253_RAMDATA;
    uint32_t RAM254_RAMDATA;
    uint32_t RAM255_RAMDATA;
};

typedef struct GPIO GPIO, *PGPIO;

struct GPIO {
    uint32_t PA_CTRL; // Port Control Register
    uint32_t PA_MODEL; // Port Pin Mode Low Register
    uint32_t PA_MODEH; // Port Pin Mode High Register
    uint32_t PA_DOUT; // Port Data Out Register
    undefined field_0x10;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    uint32_t PA_DOUTTGL; // Port Data Out Toggle Register
    uint32_t PA_DIN; // Port Data in Register
    uint32_t PA_PINLOCKN; // Port Unlocked Pins Register
    undefined field_0x24;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
    uint32_t PA_OVTDIS; // Over Voltage Disable for All Modes
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    uint32_t PB_CTRL; // Port Control Register
    uint32_t PB_MODEL; // Port Pin Mode Low Register
    uint32_t PB_MODEH; // Port Pin Mode High Register
    uint32_t PB_DOUT; // Port Data Out Register
    undefined field_0x40;
    undefined field_0x41;
    undefined field_0x42;
    undefined field_0x43;
    undefined field_0x44;
    undefined field_0x45;
    undefined field_0x46;
    undefined field_0x47;
    uint32_t PB_DOUTTGL; // Port Data Out Toggle Register
    uint32_t PB_DIN; // Port Data in Register
    uint32_t PB_PINLOCKN; // Port Unlocked Pins Register
    undefined field_0x54;
    undefined field_0x55;
    undefined field_0x56;
    undefined field_0x57;
    uint32_t PB_OVTDIS; // Over Voltage Disable for All Modes
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    uint32_t PC_CTRL; // Port Control Register
    uint32_t PC_MODEL; // Port Pin Mode Low Register
    uint32_t PC_MODEH; // Port Pin Mode High Register
    uint32_t PC_DOUT; // Port Data Out Register
    undefined field_0x70;
    undefined field_0x71;
    undefined field_0x72;
    undefined field_0x73;
    undefined field_0x74;
    undefined field_0x75;
    undefined field_0x76;
    undefined field_0x77;
    uint32_t PC_DOUTTGL; // Port Data Out Toggle Register
    uint32_t PC_DIN; // Port Data in Register
    uint32_t PC_PINLOCKN; // Port Unlocked Pins Register
    undefined field_0x84;
    undefined field_0x85;
    undefined field_0x86;
    undefined field_0x87;
    uint32_t PC_OVTDIS; // Over Voltage Disable for All Modes
    undefined field_0x8c;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
    uint32_t PD_CTRL; // Port Control Register
    uint32_t PD_MODEL; // Port Pin Mode Low Register
    uint32_t PD_MODEH; // Port Pin Mode High Register
    uint32_t PD_DOUT; // Port Data Out Register
    undefined field_0xa0;
    undefined field_0xa1;
    undefined field_0xa2;
    undefined field_0xa3;
    undefined field_0xa4;
    undefined field_0xa5;
    undefined field_0xa6;
    undefined field_0xa7;
    uint32_t PD_DOUTTGL; // Port Data Out Toggle Register
    uint32_t PD_DIN; // Port Data in Register
    uint32_t PD_PINLOCKN; // Port Unlocked Pins Register
    undefined field_0xb4;
    undefined field_0xb5;
    undefined field_0xb6;
    undefined field_0xb7;
    uint32_t PD_OVTDIS; // Over Voltage Disable for All Modes
    undefined field_0xbc;
    undefined field_0xbd;
    undefined field_0xbe;
    undefined field_0xbf;
    uint32_t PE_CTRL; // Port Control Register
    uint32_t PE_MODEL; // Port Pin Mode Low Register
    uint32_t PE_MODEH; // Port Pin Mode High Register
    uint32_t PE_DOUT; // Port Data Out Register
    undefined field_0xd0;
    undefined field_0xd1;
    undefined field_0xd2;
    undefined field_0xd3;
    undefined field_0xd4;
    undefined field_0xd5;
    undefined field_0xd6;
    undefined field_0xd7;
    uint32_t PE_DOUTTGL; // Port Data Out Toggle Register
    uint32_t PE_DIN; // Port Data in Register
    uint32_t PE_PINLOCKN; // Port Unlocked Pins Register
    undefined field_0xe4;
    undefined field_0xe5;
    undefined field_0xe6;
    undefined field_0xe7;
    uint32_t PE_OVTDIS; // Over Voltage Disable for All Modes
    undefined field_0xec;
    undefined field_0xed;
    undefined field_0xee;
    undefined field_0xef;
    uint32_t PF_CTRL; // Port Control Register
    uint32_t PF_MODEL; // Port Pin Mode Low Register
    uint32_t PF_MODEH; // Port Pin Mode High Register
    uint32_t PF_DOUT; // Port Data Out Register
    undefined field_0x100;
    undefined field_0x101;
    undefined field_0x102;
    undefined field_0x103;
    undefined field_0x104;
    undefined field_0x105;
    undefined field_0x106;
    undefined field_0x107;
    uint32_t PF_DOUTTGL; // Port Data Out Toggle Register
    uint32_t PF_DIN; // Port Data in Register
    uint32_t PF_PINLOCKN; // Port Unlocked Pins Register
    undefined field_0x114;
    undefined field_0x115;
    undefined field_0x116;
    undefined field_0x117;
    uint32_t PF_OVTDIS; // Over Voltage Disable for All Modes
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
    uint32_t EXTIPSELL; // External Interrupt Port Select Low Register
    uint32_t EXTIPSELH; // External Interrupt Port Select High Register
    uint32_t EXTIPINSELL; // External Interrupt Pin Select Low Register
    uint32_t EXTIPINSELH; // External Interrupt Pin Select High Register
    uint32_t EXTIRISE; // External Interrupt Rising Edge Trigger Register
    uint32_t EXTIFALL; // External Interrupt Falling Edge Trigger Register
    uint32_t EXTILEVEL; // External Interrupt Level Register
    uint32_t IF; // Interrupt Flag Register
    uint32_t IFS; // Interrupt Flag Set Register
    uint32_t IFC; // Interrupt Flag Clear Register
    uint32_t IEN; // Interrupt Enable Register
    uint32_t EM4WUEN; // EM4 Wake Up Enable Register
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
    uint32_t ROUTEPEN; // I/O Routing Pin Enable Register
    uint32_t ROUTELOC0; // I/O Routing Location Register
    undefined field_0x448;
    undefined field_0x449;
    undefined field_0x44a;
    undefined field_0x44b;
    undefined field_0x44c;
    undefined field_0x44d;
    undefined field_0x44e;
    undefined field_0x44f;
    uint32_t INSENSE; // Input Sense Register
    uint32_t LOCK; // Configuration Lock Register
};

typedef struct RAC_SET RAC_SET, *PRAC_SET;

struct RAC_SET {
    uint32_t RXENSRCEN;
    uint32_t STATUS;
    uint32_t CMD;
    uint32_t CTRL;
    uint32_t FORCESTATE;
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
    uint32_t LVDSCTRL;
    uint32_t LVDSIDLESEQ;
    uint32_t LVDSROUTE;
    uint32_t HFXORETIMECTRL;
    uint32_t HFXORETIMESTATUS;
    uint32_t TESTCTRL;
    uint32_t SEQSTATUS;
    uint32_t SEQCMD;
    uint32_t BREAKPOINT;
    uint32_t R0;
    uint32_t R1;
    uint32_t R2;
    uint32_t R3;
    uint32_t R4;
    uint32_t R5;
    uint32_t R6;
    uint32_t R7;
    undefined field_0x68;
    undefined field_0x69;
    undefined field_0x6a;
    undefined field_0x6b;
    uint32_t WAITMASK;
    uint32_t WAITSNSH;
    uint32_t STIMER;
    uint32_t STIMERCOMP;
    uint32_t VECTADDR;
    uint32_t SEQCTRL;
    uint32_t PRESC;
    uint32_t SR0;
    uint32_t SR1;
    uint32_t SR2;
    uint32_t SR3;
    uint32_t SYNTHENCTRL;
    uint32_t SYNTHREGCTRL;
    uint32_t VCOCTRL;
    uint32_t MMDCTRL;
    undefined field_0xa8;
    undefined field_0xa9;
    undefined field_0xaa;
    undefined field_0xab;
    undefined field_0xac;
    undefined field_0xad;
    undefined field_0xae;
    undefined field_0xaf;
    uint32_t CHPCTRL;
    uint32_t CHPCAL;
    uint32_t LPFCTRL;
    uint32_t SYNTHCTRL;
    uint32_t AUXCTRL;
    uint32_t AUXENCTRL;
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
    uint32_t RFENCTRL;
    uint32_t RFENCTRL0;
    uint32_t LNAMIXCTRL;
    uint32_t PACTRL0;
    uint32_t PAPKDCTRL;
    uint32_t PABIASCTRL0;
    uint32_t PABIASCTRL1;
    uint32_t SGRFENCTRL0;
    uint32_t SGLNAMIXCTRL;
    uint32_t SGPACTRL0;
    uint32_t SGPAPKDCTRL;
    uint32_t SGPABIASCTRL0;
    uint32_t SGPABIASCTRL1;
    uint32_t RFSTATUS;
    uint32_t RFBIASCTRL;
    uint32_t RFBIASCAL;
    uint32_t LNAMIXCTRL1;
    uint32_t IFPGACTRL;
    uint32_t IFPGACAL;
    uint32_t IFFILTCTRL;
    uint32_t IFADCCTRL;
    uint32_t IFADCCAL;
    uint32_t PAENCTRL;
    uint32_t PACTUNECTRL;
    uint32_t RCTUNE;
    uint32_t APC;
    uint32_t SPARE;
};

typedef struct CRC_CLR CRC_CLR, *PCRC_CLR;

struct CRC_CLR {
    uint32_t CTRL;
    uint32_t STATUS;
    uint32_t CMD;
    uint32_t INPUTDATA;
    uint32_t INIT;
    uint32_t DATA;
    uint32_t POLY;
};

typedef struct RAC RAC, *PRAC;

struct RAC {
    uint32_t RXENSRCEN;
    uint32_t STATUS;
    uint32_t CMD;
    uint32_t CTRL;
    uint32_t FORCESTATE;
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
    uint32_t LVDSCTRL;
    uint32_t LVDSIDLESEQ;
    uint32_t LVDSROUTE;
    uint32_t HFXORETIMECTRL;
    uint32_t HFXORETIMESTATUS;
    uint32_t TESTCTRL;
    uint32_t SEQSTATUS;
    uint32_t SEQCMD;
    uint32_t BREAKPOINT;
    uint32_t R0;
    uint32_t R1;
    uint32_t R2;
    uint32_t R3;
    uint32_t R4;
    uint32_t R5;
    uint32_t R6;
    uint32_t R7;
    undefined field_0x68;
    undefined field_0x69;
    undefined field_0x6a;
    undefined field_0x6b;
    uint32_t WAITMASK;
    uint32_t WAITSNSH;
    uint32_t STIMER;
    uint32_t STIMERCOMP;
    uint32_t VECTADDR;
    uint32_t SEQCTRL;
    uint32_t PRESC;
    uint32_t SR0;
    uint32_t SR1;
    uint32_t SR2;
    uint32_t SR3;
    uint32_t SYNTHENCTRL;
    uint32_t SYNTHREGCTRL;
    uint32_t VCOCTRL;
    uint32_t MMDCTRL;
    undefined field_0xa8;
    undefined field_0xa9;
    undefined field_0xaa;
    undefined field_0xab;
    undefined field_0xac;
    undefined field_0xad;
    undefined field_0xae;
    undefined field_0xaf;
    uint32_t CHPCTRL;
    uint32_t CHPCAL;
    uint32_t LPFCTRL;
    uint32_t SYNTHCTRL;
    uint32_t AUXCTRL;
    uint32_t AUXENCTRL;
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
    uint32_t RFENCTRL;
    uint32_t RFENCTRL0;
    uint32_t LNAMIXCTRL;
    uint32_t PACTRL0;
    uint32_t PAPKDCTRL;
    uint32_t PABIASCTRL0;
    uint32_t PABIASCTRL1;
    uint32_t SGRFENCTRL0;
    uint32_t SGLNAMIXCTRL;
    uint32_t SGPACTRL0;
    uint32_t SGPAPKDCTRL;
    uint32_t SGPABIASCTRL0;
    uint32_t SGPABIASCTRL1;
    uint32_t RFSTATUS;
    uint32_t RFBIASCTRL;
    uint32_t RFBIASCAL;
    uint32_t LNAMIXCTRL1;
    uint32_t IFPGACTRL;
    uint32_t IFPGACAL;
    uint32_t IFFILTCTRL;
    uint32_t IFADCCTRL;
    uint32_t IFADCCAL;
    uint32_t PAENCTRL;
    uint32_t PACTUNECTRL;
    uint32_t RCTUNE;
    uint32_t APC;
    uint32_t SPARE;
};

typedef struct CMU_CLR CMU_CLR, *PCMU_CLR;

struct CMU_CLR {
    uint32_t CTRL; // CMU Control Register
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
    uint32_t HFRCOCTRL; // HFRCO Control Register
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    uint32_t AUXHFRCOCTRL; // AUXHFRCO Control Register
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    uint32_t LFRCOCTRL; // LFRCO Control Register
    uint32_t HFXOCTRL; // HFXO Control Register
    uint32_t HFXOCTRL1; // HFXO Control 1
    uint32_t HFXOSTARTUPCTRL; // HFXO Startup Control
    uint32_t HFXOSTEADYSTATECTRL; // HFXO Steady State Control
    uint32_t HFXOTIMEOUTCTRL; // HFXO Timeout Control
    uint32_t LFXOCTRL; // LFXO Control Register
    uint32_t ULFRCOCTRL; // ULFRCO Control Register
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
    uint32_t CALCTRL; // Calibration Control Register
    uint32_t CALCNT; // Calibration Counter Register
    undefined field_0x58;
    undefined field_0x59;
    undefined field_0x5a;
    undefined field_0x5b;
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    uint32_t OSCENCMD; // Oscillator Enable/Disable Command Register
    uint32_t CMD; // Command Register
    undefined field_0x68;
    undefined field_0x69;
    undefined field_0x6a;
    undefined field_0x6b;
    undefined field_0x6c;
    undefined field_0x6d;
    undefined field_0x6e;
    undefined field_0x6f;
    uint32_t DBGCLKSEL; // Debug Trace Clock Select
    uint32_t HFCLKSEL; // High Frequency Clock Select Command Register
    undefined field_0x78;
    undefined field_0x79;
    undefined field_0x7a;
    undefined field_0x7b;
    undefined field_0x7c;
    undefined field_0x7d;
    undefined field_0x7e;
    undefined field_0x7f;
    uint32_t LFACLKSEL; // Low Frequency A Clock Select Register
    uint32_t LFBCLKSEL; // Low Frequency B Clock Select Register
    uint32_t LFECLKSEL; // Low Frequency E Clock Select Register
    undefined field_0x8c;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
    uint32_t STATUS; // Status Register
    uint32_t HFCLKSTATUS; // HFCLK Status Register
    undefined field_0x98;
    undefined field_0x99;
    undefined field_0x9a;
    undefined field_0x9b;
    uint32_t HFXOTRIMSTATUS; // HFXO Trim Status
    uint32_t IF; // Interrupt Flag Register
    uint32_t IFS; // Interrupt Flag Set Register
    uint32_t IFC; // Interrupt Flag Clear Register
    uint32_t IEN; // Interrupt Enable Register
    uint32_t HFBUSCLKEN0; // High Frequency Bus Clock Enable Register 0
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
    uint32_t HFPERCLKEN0; // High Frequency Peripheral Clock Enable Register 0
    undefined field_0xc4;
    undefined field_0xc5;
    undefined field_0xc6;
    undefined field_0xc7;
    uint32_t HFRADIOCLKEN0; // High Frequency Peripheral Clock Enable Register 0
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
    uint32_t LFACLKEN0; // Low Frequency a Clock Enable Register 0 (Async Reg)
    undefined field_0xe4;
    undefined field_0xe5;
    undefined field_0xe6;
    undefined field_0xe7;
    uint32_t LFBCLKEN0; // Low Frequency B Clock Enable Register 0 (Async Reg)
    undefined field_0xec;
    undefined field_0xed;
    undefined field_0xee;
    undefined field_0xef;
    uint32_t LFECLKEN0; // Low Frequency E Clock Enable Register 0 (Async Reg)
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
    uint32_t HFPRESC; // High Frequency Clock Prescaler Register
    undefined field_0x104;
    undefined field_0x105;
    undefined field_0x106;
    undefined field_0x107;
    uint32_t HFCOREPRESC; // High Frequency Core Clock Prescaler Register
    uint32_t HFPERPRESC; // High Frequency Peripheral Clock Prescaler Register
    uint32_t HFRADIOPRESC; // Radio Clock Prescaler Register
    uint32_t HFEXPPRESC; // High Frequency Export Clock Prescaler Register
    undefined field_0x118;
    undefined field_0x119;
    undefined field_0x11a;
    undefined field_0x11b;
    undefined field_0x11c;
    undefined field_0x11d;
    undefined field_0x11e;
    undefined field_0x11f;
    uint32_t LFAPRESC0; // Low Frequency a Prescaler Register 0 (Async Reg)
    undefined field_0x124;
    undefined field_0x125;
    undefined field_0x126;
    undefined field_0x127;
    uint32_t LFBPRESC0; // Low Frequency B Prescaler Register 0 (Async Reg)
    undefined field_0x12c;
    undefined field_0x12d;
    undefined field_0x12e;
    undefined field_0x12f;
    uint32_t LFEPRESC0; // Low Frequency E Prescaler Register 0 (Async Reg)
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
    uint32_t SYNCBUSY; // Synchronization Busy Register
    uint32_t FREEZE; // Freeze Register
    undefined field_0x148;
    undefined field_0x149;
    undefined field_0x14a;
    undefined field_0x14b;
    undefined field_0x14c;
    undefined field_0x14d;
    undefined field_0x14e;
    undefined field_0x14f;
    uint32_t PCNTCTRL; // PCNT Control Register
    uint32_t LCDCTRL; // LCD Control Register
    uint32_t LVDSCTRL; // LVDSCTRL Control Register
    uint32_t ADCCTRL; // ADC Control Register
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
    uint32_t ROUTEPEN; // I/O Routing Pin Enable Register
    uint32_t ROUTELOC0; // I/O Routing Location Register
    undefined field_0x178;
    undefined field_0x179;
    undefined field_0x17a;
    undefined field_0x17b;
    undefined field_0x17c;
    undefined field_0x17d;
    undefined field_0x17e;
    undefined field_0x17f;
    uint32_t LOCK; // Configuration Lock Register
    undefined field_0x184;
    undefined field_0x185;
    undefined field_0x186;
    undefined field_0x187;
    uint32_t RFLOCK0; // RF LOCK Register
    undefined field_0x18c;
    undefined field_0x18d;
    undefined field_0x18e;
    undefined field_0x18f;
    uint32_t HFBUSCLKENMASK0;
    undefined field_0x194;
    undefined field_0x195;
    undefined field_0x196;
    undefined field_0x197;
    uint32_t HFPERCLKENMASK0;
    undefined field_0x19c;
    undefined field_0x19d;
    undefined field_0x19e;
    undefined field_0x19f;
    undefined field_0x1a0;
    undefined field_0x1a1;
    undefined field_0x1a2;
    undefined field_0x1a3;
    uint32_t HFRADIOCLKENMASK0;
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
    uint32_t LFACLKENMASK0;
    undefined field_0x1b8;
    undefined field_0x1b9;
    undefined field_0x1ba;
    undefined field_0x1bb;
    uint32_t LFBCLKENMASK0;
    undefined field_0x1c0;
    undefined field_0x1c1;
    undefined field_0x1c2;
    undefined field_0x1c3;
    uint32_t LFECLKENMASK0;
    undefined field_0x1c8;
    undefined field_0x1c9;
    undefined field_0x1ca;
    undefined field_0x1cb;
    uint32_t PCNTCLKENMASK;
    uint32_t TEST;
    uint32_t TESTHFRCOCTRL;
    uint32_t TESTAUXHFRCOCTRL;
    uint32_t TESTLFRCOCTRL;
    uint32_t TESTHFXOCTRL;
    uint32_t TESTLFXOCTRL;
};

typedef struct FRC FRC, *PFRC;

struct FRC {
    uint32_t STATUS;
    uint32_t DFLCTRL;
    uint32_t MAXLENGTH;
    uint32_t ADDRFILTCTRL;
    uint32_t DATABUFFER;
    uint32_t WCNT;
    uint32_t WCNTCMP0;
    uint32_t WCNTCMP1;
    uint32_t WCNTCMP2;
    uint32_t CMD;
    uint32_t WHITECTRL;
    uint32_t WHITEPOLY;
    uint32_t WHITEINIT;
    uint32_t FECCTRL;
    uint32_t BLOCKRAMADDR;
    uint32_t CONVRAMADDR;
    uint32_t CTRL;
    uint32_t RXCTRL;
    uint32_t TRAILTXDATACTRL;
    uint32_t TRAILRXDATA;
    uint32_t SCNT;
    uint32_t CONVGENERATOR;
    uint32_t PUNCTCTRL;
    uint32_t PAUSECTRL;
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
    uint32_t BUFFERMODE;
    uint32_t ROUTEPEN;
    uint32_t ROUTELOC0;
    uint32_t SNIFFCTRL;
    uint32_t AUXDATA;
    uint32_t RAWCTRL;
    uint32_t RXRAWDATA;
    uint32_t PAUSEDATA;
    uint32_t LIKELYCONVSTATE;
    uint32_t INTELEMENTNEXT;
    uint32_t INTWRITEPOINT;
    uint32_t INTREADPOINT;
    uint32_t FCD0;
    uint32_t FCD1;
    uint32_t FCD2;
    uint32_t FCD3;
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
    uint32_t INTELEMENT0;
    uint32_t INTELEMENT1;
    uint32_t INTELEMENT2;
    uint32_t INTELEMENT3;
    uint32_t INTELEMENT4;
    uint32_t INTELEMENT5;
    uint32_t INTELEMENT6;
    uint32_t INTELEMENT7;
    uint32_t INTELEMENT8;
    uint32_t INTELEMENT9;
    uint32_t INTELEMENT10;
    uint32_t INTELEMENT11;
    uint32_t INTELEMENT12;
    uint32_t INTELEMENT13;
    uint32_t INTELEMENT14;
    uint32_t INTELEMENT15;
};

typedef struct IDAC0 IDAC0, *PIDAC0;

struct IDAC0 {
    uint32_t CTRL; // Control Register
    uint32_t CURPROG; // Current Programming Register
    undefined field_0x8;
    undefined field_0x9;
    undefined field_0xa;
    undefined field_0xb;
    uint32_t DUTYCONFIG; // Duty Cycle Configuration Register
    undefined field_0x10;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    uint32_t STATUS; // Status Register
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    uint32_t IF; // Interrupt Flag Register
    uint32_t IFS; // Interrupt Flag Set Register
    uint32_t IFC; // Interrupt Flag Clear Register
    uint32_t IEN; // Interrupt Enable Register
    undefined field_0x30;
    undefined field_0x31;
    undefined field_0x32;
    undefined field_0x33;
    uint32_t APORTREQ; // APORT Request Status Register
    uint32_t APORTCONFLICT; // APORT Request Status Register
};

typedef struct RMU RMU, *PRMU;

struct RMU {
    uint32_t CTRL; // Control Register
    uint32_t RSTCAUSE; // Reset Cause Register
    uint32_t CMD; // Command Register
    uint32_t RST; // Reset Control Register
    uint32_t LOCK; // Configuration Lock Register
};

typedef struct FRC_CLR FRC_CLR, *PFRC_CLR;

struct FRC_CLR {
    uint32_t STATUS;
    uint32_t DFLCTRL;
    uint32_t MAXLENGTH;
    uint32_t ADDRFILTCTRL;
    uint32_t DATABUFFER;
    uint32_t WCNT;
    uint32_t WCNTCMP0;
    uint32_t WCNTCMP1;
    uint32_t WCNTCMP2;
    uint32_t CMD;
    uint32_t WHITECTRL;
    uint32_t WHITEPOLY;
    uint32_t WHITEINIT;
    uint32_t FECCTRL;
    uint32_t BLOCKRAMADDR;
    uint32_t CONVRAMADDR;
    uint32_t CTRL;
    uint32_t RXCTRL;
    uint32_t TRAILTXDATACTRL;
    uint32_t TRAILRXDATA;
    uint32_t SCNT;
    uint32_t CONVGENERATOR;
    uint32_t PUNCTCTRL;
    uint32_t PAUSECTRL;
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
    uint32_t BUFFERMODE;
    uint32_t ROUTEPEN;
    uint32_t ROUTELOC0;
    uint32_t SNIFFCTRL;
    uint32_t AUXDATA;
    uint32_t RAWCTRL;
    uint32_t RXRAWDATA;
    uint32_t PAUSEDATA;
    uint32_t LIKELYCONVSTATE;
    uint32_t INTELEMENTNEXT;
    uint32_t INTWRITEPOINT;
    uint32_t INTREADPOINT;
    uint32_t FCD0;
    uint32_t FCD1;
    uint32_t FCD2;
    uint32_t FCD3;
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
    uint32_t INTELEMENT0;
    uint32_t INTELEMENT1;
    uint32_t INTELEMENT2;
    uint32_t INTELEMENT3;
    uint32_t INTELEMENT4;
    uint32_t INTELEMENT5;
    uint32_t INTELEMENT6;
    uint32_t INTELEMENT7;
    uint32_t INTELEMENT8;
    uint32_t INTELEMENT9;
    uint32_t INTELEMENT10;
    uint32_t INTELEMENT11;
    uint32_t INTELEMENT12;
    uint32_t INTELEMENT13;
    uint32_t INTELEMENT14;
    uint32_t INTELEMENT15;
};

typedef struct PROTIMER_SET PROTIMER_SET, *PPROTIMER_SET;

struct PROTIMER_SET {
    uint32_t CTRL;
    uint32_t CMD;
    uint32_t PRSCTRL;
    uint32_t STATUS;
    uint32_t PRECNT;
    uint32_t BASECNT;
    uint32_t WRAPCNT;
    uint32_t BASEPRE;
    uint32_t LWRAPCNT;
    uint32_t PRECNTTOPADJ;
    uint32_t PRECNTTOP;
    uint32_t BASECNTTOP;
    uint32_t WRAPCNTTOP;
    uint32_t TOUT0CNT;
    uint32_t TOUT0CNTTOP;
    uint32_t TOUT0COMP;
    uint32_t TOUT1CNT;
    uint32_t TOUT1CNTTOP;
    uint32_t TOUT1COMP;
    uint32_t LBTCTRL;
    uint32_t LBTPRSCTRL;
    uint32_t LBTSTATE;
    uint32_t RANDOM;
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
    uint32_t RXCTRL;
    uint32_t TXCTRL;
    uint32_t CC0_CTRL;
    uint32_t CC0_PRE;
    uint32_t CC0_BASE;
    uint32_t CC0_WRAP;
    uint32_t CC1_CTRL;
    uint32_t CC1_PRE;
    uint32_t CC1_BASE;
    uint32_t CC1_WRAP;
    uint32_t CC2_CTRL;
    uint32_t CC2_PRE;
    uint32_t CC2_BASE;
    uint32_t CC2_WRAP;
    uint32_t CC3_CTRL;
    uint32_t CC3_PRE;
    uint32_t CC3_BASE;
    uint32_t CC3_WRAP;
    uint32_t CC4_CTRL;
    uint32_t CC4_PRE;
    uint32_t CC4_BASE;
    uint32_t CC4_WRAP;
};

typedef struct SYNTH_CLR SYNTH_CLR, *PSYNTH_CLR;

struct SYNTH_CLR {
    uint32_t STATUS;
    uint32_t CMD;
    uint32_t CTRL;
    uint32_t CALCTRL;
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
    uint32_t VCDACCTRL;
    undefined field_0x28;
    undefined field_0x29;
    undefined field_0x2a;
    undefined field_0x2b;
    uint32_t FREQ;
    uint32_t IFFREQ;
    uint32_t DIVCTRL;
    uint32_t CHCTRL;
    uint32_t CHSP;
    uint32_t CALOFFSET;
    uint32_t VCOTUNING;
    undefined field_0x48;
    undefined field_0x49;
    undefined field_0x4a;
    undefined field_0x4b;
    uint32_t VCORANGE;
    uint32_t VCOGAIN;
    uint32_t AUXVCOTUNING;
    uint32_t AUXFREQ;
    uint32_t AUXVCDACCTRL;
    uint32_t CHPDACCTRL;
    uint32_t CAPCALCYCLECNT;
    undefined field_0x68;
    undefined field_0x69;
    undefined field_0x6a;
    undefined field_0x6b;
    undefined field_0x6c;
    undefined field_0x6d;
    undefined field_0x6e;
    undefined field_0x6f;
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
};

typedef struct Elf32_Shdr Elf32_Shdr, *PElf32_Shdr;

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

typedef struct Elf32_Sym Elf32_Sym, *PElf32_Sym;

struct Elf32_Sym {
    dword st_name;
    dword st_value;
    dword st_size;
    uint8_t st_info;
    uint8_t st_other;
    word st_shndx;
};

typedef struct Elf32_Rel Elf32_Rel, *PElf32_Rel;

struct Elf32_Rel {
    dword r_offset; // location to apply the relocation action
    dword r_info; // the symbol table index and the type of relocation
};

typedef struct Elf32_Ehdr Elf32_Ehdr, *PElf32_Ehdr;

struct Elf32_Ehdr {
    uint8_t e_ident_magic_num;
    char e_ident_magic_str[3];
    uint8_t e_ident_class;
    uint8_t e_ident_data;
    uint8_t e_ident_version;
    uint8_t e_ident_osabi;
    uint8_t e_ident_abiversion;
    uint8_t e_ident_pad[7];
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




int TIMING_PreambleSyncBits(void);
undefined4 TIMING_CalcAdjustUs(int param_1,int param_2);
void TIMING_SeqTimingInit(void);
int TIMING_NsToStimerTickCalcSigned(uint32_t param_1);
uint32_t TIMING_NsToStimerTickCalc(void);
void TIMING_InitStimer(void);
void TIMING_TxWarmTimeRecalculate(int param_1);
uint32_t TIMING_TxWarmTimeSet(int param_1,uint32_t param_2);
undefined2 TIMING_TxWarmTimeGet(int param_1);
void TIMING_RxToTxTimeRecalculate(int param_1);
uint32_t TIMING_RxToTxTimeSet(int param_1,uint32_t param_2);
void TIMING_RxFrameToTxTimeRecalculate(int param_1);
uint32_t TIMING_RxFrameToTxTimeSet(int param_1,uint32_t param_2);
void TIMING_TxToTxTimeRecalculate(int param_1);
void TIMING_TxToTxTimeSet(int param_1,uint32_t param_2);
void TIMING_TxToRxTimeRecalculate(int param_1);
uint32_t TIMING_TxToRxTimeSet(int param_1,uint32_t param_2);
void TIMING_RxWarmTimeRecalculate(int param_1);
uint32_t TIMING_RxWarmTimeSet(int param_1,uint32_t param_2);
undefined2 TIMING_RxWarmTimeGet(int param_1);
void TIMING_RxSearchTimeRecalculate(int *param_1);
uint32_t TIMING_RxSearchTimeSet(int param_1,uint32_t param_2);
void TIMING_TxToRxSearchTimeRecalculate(int *param_1);
uint32_t TIMING_TxToRxSearchTimeSet(int param_1,uint32_t param_2);
void TIMING_RecalculateAll(int param_1);
void TIMING_RecalculatePaRampChanged(int param_1);
void TIMING_RecalculateViterbiChanged(int param_1);
undefined4 TIMING_SetChainDelays(undefined4 *param_1,undefined4 param_2,undefined4 param_3);
undefined4 TIMING_SetRxDoneDelay(int param_1,undefined4 param_2);
void TIMING_CalcRxTimeStampUs(int *param_1,undefined4 param_2,int *param_3,undefined4 param_4);
void TIMING_CalcTxTimeStampUs(int param_1,undefined4 param_2,int *param_3);
undefined RADIO_ComputeTxBitRate();
undefined __aeabi_uldivmod();
undefined RADIOCMU_ClockFreqGet();
undefined PA_GetRampTime();
undefined PROTIMER_PrecntOverflowToUs();

