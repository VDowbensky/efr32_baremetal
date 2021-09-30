typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned int    dword;
typedef long long    longlong;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
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

typedef void _IO_lock_t;

typedef struct _IO_marker _IO_marker, *P_IO_marker;

typedef struct _IO_FILE _IO_FILE, *P_IO_FILE;

typedef long __off_t;

typedef longlong __quad_t;

typedef __quad_t __off64_t;

typedef ulong size_t;

struct _IO_FILE {
    int _flags;
    char * _IO_read_ptr;
    char * _IO_read_end;
    char * _IO_read_base;
    char * _IO_write_base;
    char * _IO_write_ptr;
    char * _IO_write_end;
    char * _IO_buf_base;
    char * _IO_buf_end;
    char * _IO_save_base;
    char * _IO_backup_base;
    char * _IO_save_end;
    struct _IO_marker * _markers;
    struct _IO_FILE * _chain;
    int _fileno;
    int _flags2;
    __off_t _old_offset;
    ushort _cur_column;
    char _vtable_offset;
    char _shortbuf[1];
    _IO_lock_t * _lock;
    __off64_t _offset;
    void * __pad1;
    void * __pad2;
    void * __pad3;
    void * __pad4;
    size_t __pad5;
    int _mode;
    char _unused2[15];
};

struct _IO_marker {
    struct _IO_marker * _next;
    struct _IO_FILE * _sbuf;
    int _pos;
};

#define __WORDSIZE 32

typedef struct _IO_FILE FILE;

typedef uint __mode_t;

typedef __mode_t mode_t;

typedef short int16_t;

typedef struct evp_pkey_ctx_st evp_pkey_ctx_st, *Pevp_pkey_ctx_st;

typedef struct evp_pkey_ctx_st EVP_PKEY_CTX;

struct evp_pkey_ctx_st {
};

typedef struct astruct astruct, *Pastruct;

struct astruct {
    undefined * field_0x0;
};

typedef struct astruct_4 astruct_4, *Pastruct_4;

struct astruct_4 {
    undefined4 field_0x0;
};

typedef struct astruct_3 astruct_3, *Pastruct_3;

struct astruct_3 {
    undefined4 field_0x0;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    undefined field_0x8;
};

typedef struct astruct_6 astruct_6, *Pastruct_6;

struct astruct_6 {
    undefined4 field_0x0;
    undefined4 field_0x4;
    undefined4 field_0x8;
    undefined4 field_0xc;
};

typedef struct astruct_5 astruct_5, *Pastruct_5;

struct astruct_5 {
    int field_0x0;
    int field_0x4;
    int field_0x8;
    undefined field_0xc;
};

typedef struct astruct_2 astruct_2, *Pastruct_2;

struct astruct_2 {
    int field_0x0;
    uint field_0x4;
};

typedef struct astruct_1 astruct_1, *Pastruct_1;

struct astruct_1 {
    byte field_0x0;
    undefined field_0x1;
    undefined field_0x2;
    undefined field_0x3;
    int field_0x4;
    int field_0x8;
    undefined4 field_0xc;
};

typedef struct astruct_7 astruct_7, *Pastruct_7;

typedef ushort uint16_t;

struct astruct_7 {
    char field_0x0;
    undefined field_0x1;
    short field_0x2;
    undefined field_0x4;
    undefined field_0x5;
    uint16_t field_0x6;
};

typedef bool _Bool;

typedef struct debugSignal debugSignal, *PdebugSignal;

typedef struct debugSignal debugSignal_t;

typedef union anon_union.conflict6565_for_loc anon_union.conflict6565_for_loc, *Panon_union.conflict6565_for_loc;

typedef struct prs_t prs_t, *Pprs_t;


// WARNING! conflicting data type names: /DWARF/_stdint.h/uint16_t - /stdint.h/uint16_t

typedef uchar __uint8_t;

typedef __uint8_t uint8_t;

struct prs_t {
    uint8_t signal;
    uint8_t source;
};

union anon_union.conflict6565_for_loc {
    struct prs_t prs;
    uint16_t debugEventNum;
};

struct debugSignal {
    char * name;
    _Bool isPrs;
    undefined field_0x5;
    union anon_union.conflict6565_for_loc loc;
};

typedef struct debugPin debugPin, *PdebugPin;

typedef struct debugPin debugPin_t;

typedef enum GPIO_Port_TypeDef {
    gpioPortA=0,
    gpioPortB=1,
    gpioPortC=2,
    gpioPortD=3,
    gpioPortF=5
} GPIO_Port_TypeDef;

struct debugPin {
    char * name;
    uint8_t prsChannel;
    uint8_t prsLocation;
    enum GPIO_Port_TypeDef gpioPort;
    uint8_t gpioPin;
};

typedef union anon_union.conflict6565 anon_union.conflict6565, *Panon_union.conflict6565;

union anon_union.conflict6565 {
    struct prs_t prs;
    uint16_t debugEventNum;
};

typedef longlong __int_least64_t;

typedef __int_least64_t time_t;

typedef struct __va_list __va_list, *P__va_list;

typedef struct __va_list __gnuc_va_list;

struct __va_list {
    void * __ap;
};

typedef struct BCP_Packet BCP_Packet, *PBCP_Packet;

struct BCP_Packet {
    uint8_t magic;
    uint8_t type;
    uint8_t payloadLength;
    uint8_t reserved;
    uint8_t data[132];
};

typedef ulong __uint32_t;

typedef __uint32_t uint32_t;

typedef uint32_t EMSTATUS;

typedef struct RTCC_RET_TypeDef RTCC_RET_TypeDef, *PRTCC_RET_TypeDef;

struct RTCC_RET_TypeDef {
    uint32_t REG;
};

typedef uint32_t RTCDRV_TimerID_t;

typedef enum RTCDRV_TimerType_t {
    rtcdrvTimerTypeOneshot=0,
    rtcdrvTimerTypePeriodic=1
} RTCDRV_TimerType_t;

typedef struct USART_InitI2s_TypeDef USART_InitI2s_TypeDef, *PUSART_InitI2s_TypeDef;

typedef struct USART_InitSync_TypeDef USART_InitSync_TypeDef, *PUSART_InitSync_TypeDef;

typedef enum USART_I2sFormat_TypeDef {
    usartI2sFormatW16D16=1280,
    usartI2sFormatW16D8=1536,
    usartI2sFormatW32D16=768,
    usartI2sFormatW32D24=512,
    usartI2sFormatW32D24M=256,
    usartI2sFormatW32D32=0,
    usartI2sFormatW32D8=1024,
    usartI2sFormatW8D8=1792
} USART_I2sFormat_TypeDef;

typedef enum USART_I2sJustify_TypeDef {
    usartI2sJustifyLeft=0,
    usartI2sJustifyRight=4
} USART_I2sJustify_TypeDef;

typedef enum USART_Enable_TypeDef {
    usartDisable=0,
    usartEnable=5,
    usartEnableRx=1,
    usartEnableTx=4
} USART_Enable_TypeDef;

typedef enum USART_Databits_TypeDef {
    usartDatabits10=7,
    usartDatabits11=8,
    usartDatabits12=9,
    usartDatabits13=10,
    usartDatabits14=11,
    usartDatabits15=12,
    usartDatabits16=13,
    usartDatabits4=1,
    usartDatabits5=2,
    usartDatabits6=3,
    usartDatabits7=4,
    usartDatabits8=5,
    usartDatabits9=6
} USART_Databits_TypeDef;

typedef enum USART_ClockMode_TypeDef {
    usartClockMode0=0,
    usartClockMode1=512,
    usartClockMode2=256,
    usartClockMode3=768
} USART_ClockMode_TypeDef;

typedef enum USART_PrsRxCh_TypeDef {
    usartPrsRxCh0=0,
    usartPrsRxCh1=1,
    usartPrsRxCh10=10,
    usartPrsRxCh11=11,
    usartPrsRxCh2=2,
    usartPrsRxCh3=3,
    usartPrsRxCh4=4,
    usartPrsRxCh5=5,
    usartPrsRxCh6=6,
    usartPrsRxCh7=7,
    usartPrsRxCh8=8,
    usartPrsRxCh9=9
} USART_PrsRxCh_TypeDef;

struct USART_InitSync_TypeDef {
    enum USART_Enable_TypeDef enable;
    undefined field_0x1;
    undefined field_0x2;
    undefined field_0x3;
    uint32_t refFreq;
    uint32_t baudrate;
    enum USART_Databits_TypeDef databits;
    _Bool master;
    _Bool msbf;
    undefined field_0xf;
    enum USART_ClockMode_TypeDef clockMode;
    _Bool prsRxEnable;
    enum USART_PrsRxCh_TypeDef prsRxCh;
    _Bool autoTx;
    _Bool autoCsEnable;
    uint8_t autoCsHold;
    uint8_t autoCsSetup;
};

struct USART_InitI2s_TypeDef {
    struct USART_InitSync_TypeDef sync;
    enum USART_I2sFormat_TypeDef format;
    _Bool delay;
    _Bool dmaSplit;
    enum USART_I2sJustify_TypeDef justify;
    _Bool mono;
    undefined field_0x1e;
    undefined field_0x1f;
};

typedef struct USART_PrsTriggerInit_TypeDef USART_PrsTriggerInit_TypeDef, *PUSART_PrsTriggerInit_TypeDef;

typedef enum USART_PrsTriggerCh_TypeDef {
    usartPrsTriggerCh0=0,
    usartPrsTriggerCh1=65536,
    usartPrsTriggerCh2=131072,
    usartPrsTriggerCh3=196608,
    usartPrsTriggerCh4=262144,
    usartPrsTriggerCh5=327680,
    usartPrsTriggerCh6=393216,
    usartPrsTriggerCh7=458752
} USART_PrsTriggerCh_TypeDef;

struct USART_PrsTriggerInit_TypeDef {
    _Bool autoTxTriggerEnable;
    _Bool rxTriggerEnable;
    _Bool txTriggerEnable;
    undefined field_0x3;
    enum USART_PrsTriggerCh_TypeDef prsTriggerChannel;
};

typedef enum USART_Parity_TypeDef {
    usartEvenParity=512,
    usartNoParity=0,
    usartOddParity=768
} USART_Parity_TypeDef;

typedef struct USART_InitAsync_TypeDef USART_InitAsync_TypeDef, *PUSART_InitAsync_TypeDef;

typedef enum USART_OVS_TypeDef {
    usartOVS16=0,
    usartOVS4=96,
    usartOVS6=64,
    usartOVS8=32
} USART_OVS_TypeDef;

typedef enum USART_Stopbits_TypeDef {
    usartStopbits0p5=0,
    usartStopbits1=4096,
    usartStopbits1p5=8192,
    usartStopbits2=12288
} USART_Stopbits_TypeDef;

struct USART_InitAsync_TypeDef {
    enum USART_Enable_TypeDef enable;
    undefined field_0x1;
    undefined field_0x2;
    undefined field_0x3;
    uint32_t refFreq;
    uint32_t baudrate;
    enum USART_OVS_TypeDef oversampling;
    enum USART_Databits_TypeDef databits;
    enum USART_Parity_TypeDef parity;
    enum USART_Stopbits_TypeDef stopbits;
    _Bool mvdis;
    _Bool prsRxEnable;
    enum USART_PrsRxCh_TypeDef prsRxCh;
    _Bool autoCsEnable;
    uint8_t autoCsHold;
    uint8_t autoCsSetup;
};

typedef enum USART_IrDAPrsSel_Typedef {
    usartIrDAPrsCh0=0,
    usartIrDAPrsCh1=256,
    usartIrDAPrsCh2=512,
    usartIrDAPrsCh3=768,
    usartIrDAPrsCh4=1024,
    usartIrDAPrsCh5=1280,
    usartIrDAPrsCh6=1536,
    usartIrDAPrsCh7=1792
} USART_IrDAPrsSel_Typedef;

typedef enum USART_IrDAPw_Typedef {
    usartIrDAPwFOUR=6,
    usartIrDAPwONE=0,
    usartIrDAPwTHREE=4,
    usartIrDAPwTWO=2
} USART_IrDAPw_Typedef;

typedef struct USART_InitIrDA_TypeDef USART_InitIrDA_TypeDef, *PUSART_InitIrDA_TypeDef;

struct USART_InitIrDA_TypeDef {
    struct USART_InitAsync_TypeDef async;
    _Bool irRxInv;
    _Bool irFilt;
    enum USART_IrDAPw_Typedef irPw;
    _Bool irPrsEn;
    enum USART_IrDAPrsSel_Typedef irPrsSel;
    undefined field_0x1e;
    undefined field_0x1f;
};

typedef struct DEVINFO_TypeDef DEVINFO_TypeDef, *PDEVINFO_TypeDef;

struct DEVINFO_TypeDef {
    uint32_t CAL;
    uint32_t RESERVED0[7];
    uint32_t EXTINFO;
    uint32_t RESERVED1[1];
    uint32_t EUI48L;
    uint32_t EUI48H;
    uint32_t CUSTOMINFO;
    uint32_t MEMINFO;
    uint32_t RESERVED2[2];
    uint32_t UNIQUEL;
    uint32_t UNIQUEH;
    uint32_t MSIZE;
    uint32_t PART;
    uint32_t DEVINFOREV;
    uint32_t EMUTEMP;
    uint32_t RESERVED3[2];
    uint32_t ADC0CAL0;
    uint32_t ADC0CAL1;
    uint32_t ADC0CAL2;
    uint32_t ADC0CAL3;
    uint32_t RESERVED4[4];
    uint32_t HFRCOCAL0;
    uint32_t RESERVED5[2];
    uint32_t HFRCOCAL3;
    uint32_t RESERVED6[2];
    uint32_t HFRCOCAL6;
    uint32_t HFRCOCAL7;
    uint32_t HFRCOCAL8;
    uint32_t RESERVED7[1];
    uint32_t HFRCOCAL10;
    uint32_t HFRCOCAL11;
    uint32_t HFRCOCAL12;
    uint32_t RESERVED8[11];
    uint32_t AUXHFRCOCAL0;
    uint32_t RESERVED9[2];
    uint32_t AUXHFRCOCAL3;
    uint32_t RESERVED10[2];
    uint32_t AUXHFRCOCAL6;
    uint32_t AUXHFRCOCAL7;
    uint32_t AUXHFRCOCAL8;
    uint32_t RESERVED11[1];
    uint32_t AUXHFRCOCAL10;
    uint32_t AUXHFRCOCAL11;
    uint32_t AUXHFRCOCAL12;
    uint32_t RESERVED12[11];
    uint32_t VMONCAL0;
    uint32_t VMONCAL1;
    uint32_t VMONCAL2;
    uint32_t RESERVED13[3];
    uint32_t IDAC0CAL0;
    uint32_t IDAC0CAL1;
    uint32_t RESERVED14[2];
    uint32_t DCDCLNVCTRL0;
    uint32_t DCDCLPVCTRL0;
    uint32_t DCDCLPVCTRL1;
    uint32_t DCDCLPVCTRL2;
    uint32_t DCDCLPVCTRL3;
    uint32_t DCDCLPCMPHYSSEL0;
    uint32_t DCDCLPCMPHYSSEL1;
};

typedef struct RMU_TypeDef RMU_TypeDef, *PRMU_TypeDef;

struct RMU_TypeDef {
    uint32_t CTRL;
    uint32_t RSTCAUSE;
    uint32_t CMD;
    uint32_t RST;
    uint32_t LOCK;
};

typedef struct EMU_VmonInit_TypeDef EMU_VmonInit_TypeDef, *PEMU_VmonInit_TypeDef;

typedef enum EMU_VmonChannel_TypeDef {
    emuVmonChannel_ALTAVDD=1,
    emuVmonChannel_AVDD=0,
    emuVmonChannel_DVDD=2,
    emuVmonChannel_IOVDD0=3
} EMU_VmonChannel_TypeDef;

struct EMU_VmonInit_TypeDef {
    enum EMU_VmonChannel_TypeDef channel;
    undefined field_0x1;
    undefined field_0x2;
    undefined field_0x3;
    int threshold;
    _Bool riseWakeup;
    _Bool fallWakeup;
    _Bool enable;
    _Bool retDisable;
};

typedef struct EMU_VmonHystInit_TypeDef EMU_VmonHystInit_TypeDef, *PEMU_VmonHystInit_TypeDef;

struct EMU_VmonHystInit_TypeDef {
    enum EMU_VmonChannel_TypeDef channel;
    undefined field_0x1;
    undefined field_0x2;
    undefined field_0x3;
    int riseThreshold;
    int fallThreshold;
    _Bool riseWakeup;
    _Bool fallWakeup;
    _Bool enable;
    undefined field_0xf;
};

typedef enum EMU_DcdcMode_TypeDef {
    emuDcdcMode_Bypass=0,
    emuDcdcMode_LowNoise=1
} EMU_DcdcMode_TypeDef;

typedef enum EMU_PowerConfig_TypeDef {
    emuPowerConfig_DcdcToDvdd=2
} EMU_PowerConfig_TypeDef;

typedef struct EMU_EM23Init_TypeDef EMU_EM23Init_TypeDef, *PEMU_EM23Init_TypeDef;

struct EMU_EM23Init_TypeDef {
    _Bool em23VregFullEn;
};


// WARNING! conflicting data type names: /DWARF/_stdint.h/int16_t - /types.h/int16_t

typedef int16_t EMU_DcdcLnReverseCurrentControl_TypeDef;

typedef struct EMU_DCDCInit_TypeDef EMU_DCDCInit_TypeDef, *PEMU_DCDCInit_TypeDef;

typedef enum EMU_DcdcAnaPeripheralPower_TypeDef {
    emuDcdcAnaPeripheralPower_AVDD=0,
    emuDcdcAnaPeripheralPower_DCDC=32
} EMU_DcdcAnaPeripheralPower_TypeDef;

typedef enum EMU_DcdcLnCompCtrl_TypeDef {
    emuDcdcLnCompCtrl_1u0F=0,
    emuDcdcLnCompCtrl_4u7F=1
} EMU_DcdcLnCompCtrl_TypeDef;

struct EMU_DCDCInit_TypeDef {
    enum EMU_PowerConfig_TypeDef powerConfig;
    enum EMU_DcdcMode_TypeDef dcdcMode;
    uint16_t mVout;
    uint16_t em01LoadCurrent_mA;
    uint16_t em234LoadCurrent_uA;
    uint16_t maxCurrent_mA;
    enum EMU_DcdcAnaPeripheralPower_TypeDef anaPeripheralPower;
    undefined field_0xb;
    EMU_DcdcLnReverseCurrentControl_TypeDef reverseCurrentControl;
    enum EMU_DcdcLnCompCtrl_TypeDef dcdcLnCompCtrl;
    undefined field_0xf;
};

typedef struct EMU_EM4Init_TypeDef EMU_EM4Init_TypeDef, *PEMU_EM4Init_TypeDef;

typedef enum EMU_EM4State_TypeDef {
    emuEM4Hibernate=1,
    emuEM4Shutoff=0
} EMU_EM4State_TypeDef;

typedef enum EMU_EM4PinRetention_TypeDef {
    emuPinRetentionDisable=0,
    emuPinRetentionEm4Exit=16,
    emuPinRetentionLatch=32
} EMU_EM4PinRetention_TypeDef;

struct EMU_EM4Init_TypeDef {
    _Bool retainLfxo;
    _Bool retainLfrco;
    _Bool retainUlfrco;
    enum EMU_EM4State_TypeDef em4State;
    enum EMU_EM4PinRetention_TypeDef pinRetentionMode;
};

typedef enum EMU_DcdcLnRcoBand_TypeDef {
    emuDcdcLnRcoBand_10MHz=7,
    emuDcdcLnRcoBand_3MHz=0,
    emuDcdcLnRcoBand_4MHz=1,
    emuDcdcLnRcoBand_5MHz=2,
    emuDcdcLnRcoBand_6MHz=3,
    emuDcdcLnRcoBand_7MHz=4,
    emuDcdcLnRcoBand_8MHz=5,
    emuDcdcLnRcoBand_9MHz=6
} EMU_DcdcLnRcoBand_TypeDef;

typedef enum EMU_BiasMode_TypeDef {
    emuBiasMode_1KHz=0,
    emuBiasMode_4KHz=1,
    emuBiasMode_Continuous=2
} EMU_BiasMode_TypeDef;

typedef struct USART_TypeDef USART_TypeDef, *PUSART_TypeDef;

struct USART_TypeDef {
    uint32_t CTRL;
    uint32_t FRAME;
    uint32_t TRIGCTRL;
    uint32_t CMD;
    uint32_t STATUS;
    uint32_t CLKDIV;
    uint32_t RXDATAX;
    uint32_t RXDATA;
    uint32_t RXDOUBLEX;
    uint32_t RXDOUBLE;
    uint32_t RXDATAXP;
    uint32_t RXDOUBLEXP;
    uint32_t TXDATAX;
    uint32_t TXDATA;
    uint32_t TXDOUBLEX;
    uint32_t TXDOUBLE;
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
    uint32_t IRCTRL;
    uint32_t RESERVED0[1];
    uint32_t INPUT;
    uint32_t I2SCTRL;
    uint32_t TIMING;
    uint32_t CTRLX;
    uint32_t TIMECMP0;
    uint32_t TIMECMP1;
    uint32_t TIMECMP2;
    uint32_t ROUTEPEN;
    uint32_t ROUTELOC0;
    uint32_t ROUTELOC1;
};

typedef struct SYSTEM_ChipRevision_TypeDef SYSTEM_ChipRevision_TypeDef, *PSYSTEM_ChipRevision_TypeDef;

struct SYSTEM_ChipRevision_TypeDef {
    uint8_t minor;
    uint8_t major;
    uint8_t family;
};

typedef struct SYSTEM_CalAddrVal_TypeDef SYSTEM_CalAddrVal_TypeDef, *PSYSTEM_CalAddrVal_TypeDef;

struct SYSTEM_CalAddrVal_TypeDef {
    uint32_t address;
    uint32_t calValue;
};

typedef enum SYSTEM_PartFamily_TypeDef {
    systemPartFamilyBlue1B=20,
    systemPartFamilyBlue1P=19,
    systemPartFamilyBlue1V=21,
    systemPartFamilyEfm32Gecko=71,
    systemPartFamilyEfm32Giant=72,
    systemPartFamilyEfm32Happy=77,
    systemPartFamilyEfm32Jade1B=83,
    systemPartFamilyEfm32Leopard=74,
    systemPartFamilyEfm32Pearl1B=81,
    systemPartFamilyEfm32Tiny=73,
    systemPartFamilyEfm32Wonder=75,
    systemPartFamilyEfm32Zero=76,
    systemPartFamilyEzr32Happy=122,
    systemPartFamilyEzr32Leopard=120,
    systemPartFamilyEzr32Wonder=121,
    systemPartFamilyFlex1B=26,
    systemPartFamilyFlex1P=25,
    systemPartFamilyFlex1V=27,
    systemPartFamilyGecko=71,
    systemPartFamilyGiant=72,
    systemPartFamilyHappy=77,
    systemPartFamilyLeopard=74,
    systemPartFamilyMighty1B=17,
    systemPartFamilyMighty1P=16,
    systemPartFamilyMighty1V=18,
    systemPartFamilyMighty2P=28,
    systemPartFamilyTiny=73,
    systemPartFamilyUnknown=-1,
    systemPartFamilyWonder=75,
    systemPartFamilyZero=76
} SYSTEM_PartFamily_TypeDef;

typedef struct Timer Timer, *PTimer;

typedef struct Timer Timer_t;

typedef ulonglong __uint64_t;

typedef __uint64_t uint64_t;

struct Timer {
    uint64_t remaining;
    uint64_t ticks;
    int periodicCompensationUsec;
    uint periodicDriftUsec;
    void (* callback)(RTCDRV_TimerID_t, void *);
    _Bool running;
    _Bool doCallback;
    _Bool allocated;
    enum RTCDRV_TimerType_t timerType;
    void * user;
    undefined field_0x24;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
};

typedef enum errataFixDcdcHs_TypeDef {
    errataFixDcdcHsBypassLn=2,
    errataFixDcdcHsInit=0,
    errataFixDcdcHsLnWaitDone=3,
    errataFixDcdcHsTrimSet=1
} errataFixDcdcHs_TypeDef;

typedef uint wint_t;

typedef struct PRS_CH_TypeDef PRS_CH_TypeDef, *PPRS_CH_TypeDef;

struct PRS_CH_TypeDef {
    uint32_t CTRL;
};

typedef uint8_t PixelMatrixAlign_t;

typedef enum RMU_Reset_TypeDef {
    rmuResetCoreLockup=112,
    rmuResetLockUp=112,
    rmuResetPin=28672,
    rmuResetSys=1792,
    rmuResetWdog=7
} RMU_Reset_TypeDef;

typedef enum RMU_ResetMode_TypeDef {
    rmuResetModeDisabled=0,
    rmuResetModeExtended=2,
    rmuResetModeFull=4,
    rmuResetModeLimited=1
} RMU_ResetMode_TypeDef;

typedef struct RMU_ResetCauseMasks_Typedef RMU_ResetCauseMasks_Typedef, *PRMU_ResetCauseMasks_Typedef;

struct RMU_ResetCauseMasks_Typedef {
    uint32_t resetCauseMask;
    uint32_t resetCauseZeroXMask;
};

typedef struct CMU_TypeDef CMU_TypeDef, *PCMU_TypeDef;

struct CMU_TypeDef {
    uint32_t CTRL;
    uint32_t RESERVED0[3];
    uint32_t HFRCOCTRL;
    uint32_t RESERVED1[1];
    uint32_t AUXHFRCOCTRL;
    uint32_t RESERVED2[1];
    uint32_t LFRCOCTRL;
    uint32_t HFXOCTRL;
    uint32_t HFXOCTRL1;
    uint32_t HFXOSTARTUPCTRL;
    uint32_t HFXOSTEADYSTATECTRL;
    uint32_t HFXOTIMEOUTCTRL;
    uint32_t LFXOCTRL;
    uint32_t RESERVED3[5];
    uint32_t CALCTRL;
    uint32_t CALCNT;
    uint32_t RESERVED4[2];
    uint32_t OSCENCMD;
    uint32_t CMD;
    uint32_t RESERVED5[2];
    uint32_t DBGCLKSEL;
    uint32_t HFCLKSEL;
    uint32_t RESERVED6[2];
    uint32_t LFACLKSEL;
    uint32_t LFBCLKSEL;
    uint32_t LFECLKSEL;
    uint32_t RESERVED7[1];
    uint32_t STATUS;
    uint32_t HFCLKSTATUS;
    uint32_t RESERVED8[1];
    uint32_t HFXOTRIMSTATUS;
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
    uint32_t HFBUSCLKEN0;
    uint32_t RESERVED9[3];
    uint32_t HFPERCLKEN0;
    uint32_t RESERVED10[7];
    uint32_t LFACLKEN0;
    uint32_t RESERVED11[1];
    uint32_t LFBCLKEN0;
    uint32_t RESERVED12[1];
    uint32_t LFECLKEN0;
    uint32_t RESERVED13[3];
    uint32_t HFPRESC;
    uint32_t RESERVED14[1];
    uint32_t HFCOREPRESC;
    uint32_t HFPERPRESC;
    uint32_t RESERVED15[1];
    uint32_t HFEXPPRESC;
    uint32_t RESERVED16[2];
    uint32_t LFAPRESC0;
    uint32_t RESERVED17[1];
    uint32_t LFBPRESC0;
    uint32_t RESERVED18[1];
    uint32_t LFEPRESC0;
    uint32_t RESERVED19[3];
    uint32_t SYNCBUSY;
    uint32_t FREEZE;
    uint32_t RESERVED20[2];
    uint32_t PCNTCTRL;
    uint32_t RESERVED21[2];
    uint32_t ADCCTRL;
    uint32_t RESERVED22[4];
    uint32_t ROUTEPEN;
    uint32_t ROUTELOC0;
    uint32_t RESERVED23[2];
    uint32_t LOCK;
};

typedef struct __GLIB_Rectangle_t __GLIB_Rectangle_t, *P__GLIB_Rectangle_t;

typedef struct __GLIB_Rectangle_t GLIB_Rectangle_t;

typedef long __int32_t;

typedef __int32_t int32_t;

struct __GLIB_Rectangle_t {
    int32_t xMin;
    int32_t yMin;
    int32_t xMax;
    int32_t yMax;
};

typedef struct __GLIB_Context_t __GLIB_Context_t, *P__GLIB_Context_t;

typedef struct __GLIB_Context_t GLIB_Context_t;

typedef struct __DMD_DisplayGeometry __DMD_DisplayGeometry, *P__DMD_DisplayGeometry;

typedef struct __DMD_DisplayGeometry DMD_DisplayGeometry;

typedef struct __GLIB_Font_t __GLIB_Font_t, *P__GLIB_Font_t;

typedef struct __GLIB_Font_t GLIB_Font_t;

typedef enum __GLIB_Font_Class {
    FullFont=1,
    InvalidFont=0,
    NumbersOnlyFont=2
} __GLIB_Font_Class;

typedef enum __GLIB_Font_Class GLIB_Font_Class;

struct __DMD_DisplayGeometry {
    uint16_t xSize;
    uint16_t ySize;
    uint16_t xClipStart;
    uint16_t yClipStart;
    uint16_t clipWidth;
    uint16_t clipHeight;
};

struct __GLIB_Font_t {
    void * pFontPixMap;
    uint16_t cntOfMapElements;
    uint8_t sizeOfMapElement;
    uint8_t fontRowOffset;
    uint8_t fontWidth;
    uint8_t fontHeight;
    uint8_t lineSpacing;
    uint8_t charSpacing;
    GLIB_Font_Class class;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
};

struct __GLIB_Context_t {
    DMD_DisplayGeometry * pDisplayGeometry;
    uint32_t backgroundColor;
    uint32_t foregroundColor;
    GLIB_Rectangle_t clippingRegion;
    GLIB_Font_t font;
};

typedef struct BufferPoolObj_t BufferPoolObj_t, *PBufferPoolObj_t;

struct BufferPoolObj_t {
    uint8_t refCount;
    uint8_t data[256];
};

typedef enum anon_enum_8.conflict60d2 {
    RAIL_IDLE=0,
    RAIL_IDLE_ABORT=1,
    RAIL_IDLE_FORCE_SHUTDOWN=2,
    RAIL_RFSENSE_2_4GHZ=1,
    RAIL_RFSENSE_ANY=3,
    RAIL_RFSENSE_MAX=4,
    RAIL_RFSENSE_OFF=0,
    RAIL_RFSENSE_SUBGHZ=2,
    cmuOsc_AUXHFRCO=4,
    cmuOsc_HFRCO=3,
    cmuOsc_HFXO=2,
    cmuOsc_LFRCO=1,
    cmuOsc_LFXO=0,
    cmuOsc_ULFRCO=5,
    cmuSelect_AUXHFRCO=7,
    cmuSelect_Disabled=1,
    cmuSelect_Error=0,
    cmuSelect_HFCLK=8,
    cmuSelect_HFCLKLE=6,
    cmuSelect_HFRCO=5,
    cmuSelect_HFXO=4,
    cmuSelect_LFRCO=3,
    cmuSelect_LFXO=2,
    cmuSelect_ULFRCO=9,
    gpioModeDisabled=0,
    gpioModeInput=1,
    gpioModeInputPull=2,
    gpioModeInputPullFilter=3,
    gpioModePushPull=4,
    gpioModePushPullAlternate=5,
    gpioModeWiredAnd=8,
    gpioModeWiredAndAlternate=12,
    gpioModeWiredAndAlternateFilter=13,
    gpioModeWiredAndAlternatePullUp=14,
    gpioModeWiredAndAlternatePullUpFilter=15,
    gpioModeWiredAndFilter=9,
    gpioModeWiredAndPullUp=10,
    gpioModeWiredAndPullUpFilter=11,
    gpioModeWiredOr=6,
    gpioModeWiredOrPullDown=7,
    gpioPortA=0,
    gpioPortB=1,
    gpioPortC=2,
    gpioPortD=3,
    gpioPortF=5,
    palGpioModePushPull=0
} anon_enum_8.conflict60d2;

typedef enum GPIO_Mode_TypeDef {
    gpioModeDisabled=0,
    gpioModeInput=1,
    gpioModeInputPull=2,
    gpioModeInputPullFilter=3,
    gpioModePushPull=4,
    gpioModePushPullAlternate=5,
    gpioModeWiredAnd=8,
    gpioModeWiredAndAlternate=12,
    gpioModeWiredAndAlternateFilter=13,
    gpioModeWiredAndAlternatePullUp=14,
    gpioModeWiredAndAlternatePullUpFilter=15,
    gpioModeWiredAndFilter=9,
    gpioModeWiredAndPullUp=10,
    gpioModeWiredAndPullUpFilter=11,
    gpioModeWiredOr=6,
    gpioModeWiredOrPullDown=7
} GPIO_Mode_TypeDef;

typedef enum GPIO_DriveStrength_TypeDef {
    gpioDriveStrengthStrongAlternateStrong=0,
    gpioDriveStrengthStrongAlternateWeak=65536,
    gpioDriveStrengthWeakAlternateStrong=1,
    gpioDriveStrengthWeakAlternateWeak=65537
} GPIO_DriveStrength_TypeDef;

typedef struct __lock __lock, *P__lock;

typedef struct __lock * _LOCK_T;

struct __lock {
};

typedef struct DISPLAY_Device_t DISPLAY_Device_t, *PDISPLAY_Device_t;

typedef void * DISPLAY_PixelMatrix_t;

typedef struct DISPLAY_Geometry_t DISPLAY_Geometry_t, *PDISPLAY_Geometry_t;

typedef enum DISPLAY_ColourMode_t {
    DISPLAY_COLOUR_MODE_MONOCHROME=0,
    DISPLAY_COLOUR_MODE_MONOCHROME_INVERSE=1
} DISPLAY_ColourMode_t;

typedef enum DISPLAY_AddressMode_t {
    DISPLAY_ADDRESSING_BY_ROWS_AND_COLUMNS=1,
    DISPLAY_ADDRESSING_BY_ROWS_ONLY=0
} DISPLAY_AddressMode_t;

struct DISPLAY_Geometry_t {
    uint width;
    uint stride;
    uint height;
};

struct DISPLAY_Device_t {
    char * name;
    struct DISPLAY_Geometry_t geometry;
    enum DISPLAY_ColourMode_t colourMode;
    enum DISPLAY_AddressMode_t addressMode;
    undefined field_0x12;
    undefined field_0x13;
    EMSTATUS (* pDisplayPowerOn)(struct DISPLAY_Device_t *, _Bool);
    EMSTATUS (* pPixelMatrixAllocate)(struct DISPLAY_Device_t *, uint, uint, DISPLAY_PixelMatrix_t *);
    EMSTATUS (* pPixelMatrixFree)(struct DISPLAY_Device_t *, DISPLAY_PixelMatrix_t);
    EMSTATUS (* pPixelMatrixDraw)(struct DISPLAY_Device_t *, DISPLAY_PixelMatrix_t, uint, uint, uint, uint);
    EMSTATUS (* pPixelMatrixClear)(struct DISPLAY_Device_t *, DISPLAY_PixelMatrix_t, uint, uint);
    EMSTATUS (* pDriverRefresh)(struct DISPLAY_Device_t *);
};

typedef enum RAIL_RfSenseBand_t {
    RAIL_RFSENSE_2_4GHZ=1,
    RAIL_RFSENSE_ANY=3,
    RAIL_RFSENSE_MAX=4,
    RAIL_RFSENSE_OFF=0,
    RAIL_RFSENSE_SUBGHZ=2
} RAIL_RfSenseBand_t;

typedef struct RAIL_AutoAckConfig RAIL_AutoAckConfig, *PRAIL_AutoAckConfig;

typedef enum RAIL_RadioState {
    RAIL_RF_STATE_IDLE=0,
    RAIL_RF_STATE_RX=1,
    RAIL_RF_STATE_TX=2
} RAIL_RadioState;

typedef enum RAIL_RadioState RAIL_RadioState_t;

struct RAIL_AutoAckConfig {
    RAIL_RadioState_t defaultState;
    undefined field_0x1;
    uint16_t idleTiming;
    uint16_t turnaroundTime;
    uint16_t ackTimeout;
};

typedef struct RAIL_ScheduleTxConfig RAIL_ScheduleTxConfig, *PRAIL_ScheduleTxConfig;

typedef struct RAIL_ScheduleTxConfig RAIL_ScheduleTxConfig_t;

typedef enum RAIL_TimeMode {
    RAIL_TIME_ABSOLUTE=0,
    RAIL_TIME_DELAY=1,
    RAIL_TIME_DISABLED=2
} RAIL_TimeMode;

typedef enum RAIL_TimeMode RAIL_TimeMode_t;

struct RAIL_ScheduleTxConfig {
    uint32_t when;
    RAIL_TimeMode_t mode;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
};

typedef struct RAIL_TxData RAIL_TxData, *PRAIL_TxData;

typedef struct RAIL_TxData RAIL_TxData_t;

struct RAIL_TxData {
    uint8_t * dataPtr;
    uint16_t dataLength;
    undefined field_0x6;
    undefined field_0x7;
};

typedef struct RAIL_AppendedInfo RAIL_AppendedInfo, *PRAIL_AppendedInfo;

typedef struct RAIL_AppendedInfo RAIL_AppendedInfo_t;

typedef char __int8_t;

typedef __int8_t int8_t;

struct RAIL_AppendedInfo {
    uint32_t timeUs;
    _Bool crcStatus:1;
    _Bool frameCodingStatus:1;
    _Bool isAck:1;
    int8_t rssiLatch;
    uint8_t lqi;
    uint8_t syncWordId;
};

typedef struct RAIL_AutoAckData RAIL_AutoAckData, *PRAIL_AutoAckData;

typedef struct RAIL_AutoAckData RAIL_AutoAckData_t;

struct RAIL_AutoAckData {
    uint8_t * dataPtr;
    uint8_t dataLength;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
};

typedef enum RAIL_StreamMode {
    PN9_STREAM=1,
    PSEUDO_RANDOM_STREAM=0
} RAIL_StreamMode;

typedef struct RAIL_ScheduleRxConfig RAIL_ScheduleRxConfig, *PRAIL_ScheduleRxConfig;

typedef struct RAIL_ScheduleRxConfig RAIL_ScheduleRxConfig_t;

struct RAIL_ScheduleRxConfig {
    uint32_t start;
    RAIL_TimeMode_t startMode;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    uint32_t end;
    RAIL_TimeMode_t endMode;
    uint8_t rxTransitionEndSchedule;
    uint8_t hardWindowEnd;
    undefined field_0xf;
};

typedef struct RAIL_ChannelConfig RAIL_ChannelConfig, *PRAIL_ChannelConfig;

typedef struct RAIL_ChannelConfig RAIL_ChannelConfig_t;

typedef struct RAIL_ChannelConfigEntry RAIL_ChannelConfigEntry, *PRAIL_ChannelConfigEntry;

typedef struct RAIL_ChannelConfigEntry RAIL_ChannelConfigEntry_t;

struct RAIL_ChannelConfigEntry {
    uint16_t channelNumberStart;
    uint16_t channelNumberEnd;
    uint32_t channelSpacing;
    uint32_t baseFrequency;
};

struct RAIL_ChannelConfig {
    RAIL_ChannelConfigEntry_t * configs;
    uint32_t length;
};

typedef struct RAIL_FrameType RAIL_FrameType, *PRAIL_FrameType;

typedef struct RAIL_FrameType RAIL_FrameType_t;

struct RAIL_FrameType {
    uint8_t offset;
    uint8_t mask;
    undefined field_0x2;
    undefined field_0x3;
    uint16_t * frameLen;
    uint8_t * isValid;
    _Bool variableAddrLoc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
};

typedef struct RAIL_AddrConfig RAIL_AddrConfig, *PRAIL_AddrConfig;

typedef struct RAIL_AddrConfig RAIL_AddrConfig_t;

struct RAIL_AddrConfig {
    uint8_t numFields;
    undefined field_0x1;
    undefined field_0x2;
    undefined field_0x3;
    uint8_t * offsets;
    uint8_t * sizes;
    uint32_t matchTable;
};

typedef struct RAIL_TxOptions RAIL_TxOptions, *PRAIL_TxOptions;

struct RAIL_TxOptions {
    _Bool waitForAck;
};

typedef struct RAIL_BerConfig RAIL_BerConfig, *PRAIL_BerConfig;

typedef struct RAIL_BerConfig RAIL_BerConfig_t;

struct RAIL_BerConfig {
    uint32_t bytesToTest;
};

typedef struct RAIL_Version RAIL_Version, *PRAIL_Version;

typedef struct RAIL_Version RAIL_Version_t;

struct RAIL_Version {
    uint32_t hash;
    uint8_t major;
    uint8_t minor;
    uint8_t rev;
    uint8_t build;
    uint8_t flags;
    undefined field_0x9;
    undefined field_0xa;
    undefined field_0xb;
};

typedef struct RAIL_RxPacketInfo RAIL_RxPacketInfo, *PRAIL_RxPacketInfo;

struct RAIL_RxPacketInfo { // Missing member dataPtr : uint8_t[1] at offset 0xa [Unsupported interior flex array: uint8_t[1]]
    RAIL_AppendedInfo_t appendedInfo;
    uint16_t dataLength;
    undefined field_0xa;
    undefined field_0xb;
};

typedef enum RAIL_Status {
    RAIL_STATUS_INVALID_CALL=3,
    RAIL_STATUS_INVALID_PARAMETER=1,
    RAIL_STATUS_INVALID_STATE=2,
    RAIL_STATUS_NO_ERROR=0
} RAIL_Status;

typedef enum RAIL_Status RAIL_Status_t;

typedef struct RAIL_RxPacketInfo RAIL_RxPacketInfo_t;

typedef enum RAIL_PtiProtocol {
    RAIL_PTI_PROTOCOL_BLE=3,
    RAIL_PTI_PROTOCOL_CONNECT=4,
    RAIL_PTI_PROTOCOL_CUSTOM=0,
    RAIL_PTI_PROTOCOL_THREAD=2,
    RAIL_PTI_PROTOCOL_ZIGBEE=5
} RAIL_PtiProtocol;

typedef struct RAIL_TxOptions RAIL_TxOptions_t;

typedef struct RAIL_Init RAIL_Init, *PRAIL_Init;

typedef uint32_t RAIL_CalMask_t;

struct RAIL_Init {
    uint16_t maxPacketLength;
    undefined field_0x2;
    undefined field_0x3;
    uint32_t rfXtalFreq;
    RAIL_CalMask_t calEnable;
};

typedef struct RAIL_AutoAckConfig RAIL_AutoAckConfig_t;

typedef struct RAIL_StateTiming RAIL_StateTiming, *PRAIL_StateTiming;

typedef struct RAIL_StateTiming RAIL_StateTiming_t;

struct RAIL_StateTiming {
    uint16_t idleToRx;
    uint16_t txToRx;
    uint16_t idleToTx;
    uint16_t rxToTx;
};

typedef struct RAIL_LbtConfig RAIL_LbtConfig, *PRAIL_LbtConfig;

typedef struct RAIL_LbtConfig RAIL_LbtConfig_t;

struct RAIL_LbtConfig {
    uint8_t lbtMinBoRand;
    uint8_t lbtMaxBoRand;
    uint8_t lbtTries;
    int8_t lbtThreshold;
    uint16_t lbtBackoff;
    uint16_t lbtDuration;
    uint32_t lbtTimeout;
};

typedef struct RAIL_BerStatus RAIL_BerStatus, *PRAIL_BerStatus;

struct RAIL_BerStatus {
    uint32_t bitsTotal;
    uint32_t bitsTested;
    uint32_t bitErrors;
    int8_t rssi;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
};

typedef struct RAIL_TxPacketInfo RAIL_TxPacketInfo, *PRAIL_TxPacketInfo;

typedef struct RAIL_TxPacketInfo RAIL_TxPacketInfo_t;

struct RAIL_TxPacketInfo {
    uint32_t timeUs;
};

typedef struct RAIL_BerStatus RAIL_BerStatus_t;

typedef struct RAIL_CalInit RAIL_CalInit, *PRAIL_CalInit;

struct RAIL_CalInit {
    RAIL_CalMask_t calEnable;
    uint8_t * irCalSettings;
};

typedef struct RAIL_CalInit RAIL_CalInit_t;

typedef struct RAIL_Init RAIL_Init_t;

typedef enum RAIL_PtiProtocol RAIL_PtiProtocol_t;

typedef ushort __ino_t;

typedef __ino_t ino_t;

typedef ushort __uid_t;

typedef __uid_t uid_t;


// WARNING! conflicting data type names: /DWARF/_types.h/__off_t - /types.h/__off_t

typedef __off_t off_t;

typedef ushort __nlink_t;

typedef __nlink_t nlink_t;

typedef ushort __gid_t;

typedef __gid_t gid_t;

typedef long __blkcnt_t;

typedef __blkcnt_t blkcnt_t;


// WARNING! conflicting data type names: /DWARF/types.h/mode_t - /types.h/mode_t

typedef char * caddr_t;

typedef short __dev_t;

typedef __dev_t dev_t;

typedef long __blksize_t;

typedef __blksize_t blksize_t;

typedef struct SCB_Type SCB_Type, *PSCB_Type;

struct SCB_Type {
    uint32_t CPUID;
    uint32_t ICSR;
    uint32_t VTOR;
    uint32_t AIRCR;
    uint32_t SCR;
    uint32_t CCR;
    uint8_t SHP[12];
    uint32_t SHCSR;
    uint32_t CFSR;
    uint32_t HFSR;
    uint32_t DFSR;
    uint32_t MMFAR;
    uint32_t BFAR;
    uint32_t AFSR;
    uint32_t PFR[2];
    uint32_t DFR;
    uint32_t ADR;
    uint32_t MMFR[4];
    uint32_t ISAR[5];
    uint32_t RESERVED0[5];
    uint32_t CPACR;
};

typedef struct NVIC_Type NVIC_Type, *PNVIC_Type;

struct NVIC_Type {
    uint32_t ISER[8];
    uint32_t RESERVED0[24];
    uint32_t ICER[8];
    uint32_t RSERVED1[24];
    uint32_t ISPR[8];
    uint32_t RESERVED2[24];
    uint32_t ICPR[8];
    uint32_t RESERVED3[24];
    uint32_t IABR[8];
    uint32_t RESERVED4[56];
    uint8_t IP[240];
    uint32_t RESERVED5[644];
    uint32_t STIR;
};

typedef struct TIMER_TypeDef TIMER_TypeDef, *PTIMER_TypeDef;

typedef struct TIMER_CC_TypeDef TIMER_CC_TypeDef, *PTIMER_CC_TypeDef;

struct TIMER_CC_TypeDef {
    uint32_t CTRL;
    uint32_t CCV;
    uint32_t CCVP;
    uint32_t CCVB;
};

struct TIMER_TypeDef {
    uint32_t CTRL;
    uint32_t CMD;
    uint32_t STATUS;
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
    uint32_t TOP;
    uint32_t TOPB;
    uint32_t CNT;
    uint32_t RESERVED0[1];
    uint32_t LOCK;
    uint32_t ROUTEPEN;
    uint32_t ROUTELOC0;
    uint32_t RESERVED1[1];
    uint32_t ROUTELOC2;
    uint32_t RESERVED2[8];
    struct TIMER_CC_TypeDef CC[4];
    uint32_t DTCTRL;
    uint32_t DTTIME;
    uint32_t DTFC;
    uint32_t DTOGEN;
    uint32_t DTFAULT;
    uint32_t DTFAULTC;
    uint32_t DTLOCK;
};

typedef struct CommandState CommandState, *PCommandState;

typedef struct CommandState CommandState_t;

typedef struct CommandEntry CommandEntry, *PCommandEntry;

typedef struct CommandEntry CommandEntry_t;

struct CommandEntry {
    char * command;
    char * arguments;
    void (* callback)(int, char * *);
    char * helpStr;
};

struct CommandState {
    char * buffer;
    char prevEol;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    uint32_t offset;
    uint32_t length;
    CommandEntry_t * commands;
};

typedef enum CommandError_t {
    CI_INVALID_ARGUMENTS=2,
    CI_MAX_ARGUMENTS=1,
    CI_UNKNOWN_COMMAND=0
} CommandError_t;

typedef struct ROMTABLE_TypeDef ROMTABLE_TypeDef, *PROMTABLE_TypeDef;

struct ROMTABLE_TypeDef {
    uint32_t PID4;
    uint32_t PID5;
    uint32_t PID6;
    uint32_t PID7;
    uint32_t PID0;
    uint32_t PID1;
    uint32_t PID2;
    uint32_t PID3;
    uint32_t CID0;
};

typedef struct PRS_TypeDef PRS_TypeDef, *PPRS_TypeDef;

struct PRS_TypeDef {
    uint32_t SWPULSE;
    uint32_t SWLEVEL;
    uint32_t ROUTEPEN;
    uint32_t RESERVED0[1];
    uint32_t ROUTELOC0;
    uint32_t ROUTELOC1;
    uint32_t ROUTELOC2;
    uint32_t RESERVED1[1];
    uint32_t CTRL;
    uint32_t DMAREQ0;
    uint32_t DMAREQ1;
    uint32_t RESERVED2[1];
    uint32_t PEEK;
    uint32_t RESERVED3[3];
    struct PRS_CH_TypeDef CH[12];
};

typedef enum TIMER_Event_TypeDef {
    timerEventEvery2ndEdge=1,
    timerEventEveryEdge=0,
    timerEventFalling=3,
    timerEventRising=2
} TIMER_Event_TypeDef;

typedef enum TIMER_InputAction_TypeDef {
    timerInputActionNone=0,
    timerInputActionReloadStart=3,
    timerInputActionStart=1,
    timerInputActionStop=2
} TIMER_InputAction_TypeDef;

typedef enum TIMER_CCMode_TypeDef {
    timerCCModeCapture=1,
    timerCCModeCompare=2,
    timerCCModeOff=0,
    timerCCModePWM=3
} TIMER_CCMode_TypeDef;

typedef struct TIMER_InitDTI_TypeDef TIMER_InitDTI_TypeDef, *PTIMER_InitDTI_TypeDef;

typedef enum TIMER_PRSSEL_TypeDef {
    timerPRSSELCh0=0,
    timerPRSSELCh1=1,
    timerPRSSELCh10=10,
    timerPRSSELCh11=11,
    timerPRSSELCh2=2,
    timerPRSSELCh3=3,
    timerPRSSELCh4=4,
    timerPRSSELCh5=5,
    timerPRSSELCh6=6,
    timerPRSSELCh7=7,
    timerPRSSELCh8=8,
    timerPRSSELCh9=9
} TIMER_PRSSEL_TypeDef;

typedef enum TIMER_Prescale_TypeDef {
    timerPrescale1=0,
    timerPrescale1024=10,
    timerPrescale128=7,
    timerPrescale16=4,
    timerPrescale2=1,
    timerPrescale256=8,
    timerPrescale32=5,
    timerPrescale4=2,
    timerPrescale512=9,
    timerPrescale64=6,
    timerPrescale8=3
} TIMER_Prescale_TypeDef;

typedef enum TIMER_DtiFaultAction_TypeDef {
    timerDtiFaultActionClear=2,
    timerDtiFaultActionInactive=1,
    timerDtiFaultActionNone=0,
    timerDtiFaultActionTristate=3
} TIMER_DtiFaultAction_TypeDef;

struct TIMER_InitDTI_TypeDef {
    _Bool enable;
    _Bool activeLowOut;
    _Bool invertComplementaryOut;
    _Bool autoRestart;
    _Bool enablePrsSource;
    enum TIMER_PRSSEL_TypeDef prsSel;
    enum TIMER_Prescale_TypeDef prescale;
    undefined field_0x7;
    uint riseTime;
    uint fallTime;
    uint32_t outputsEnableMask;
    _Bool enableFaultSourceCoreLockup;
    _Bool enableFaultSourceDebugger;
    _Bool enableFaultSourcePrsSel0;
    enum TIMER_PRSSEL_TypeDef faultSourcePrsSel0;
    _Bool enableFaultSourcePrsSel1;
    enum TIMER_PRSSEL_TypeDef faultSourcePrsSel1;
    enum TIMER_DtiFaultAction_TypeDef faultAction;
    undefined field_0x1b;
};

typedef struct TIMER_Init_TypeDef TIMER_Init_TypeDef, *PTIMER_Init_TypeDef;

typedef enum TIMER_ClkSel_TypeDef {
    timerClkSelCC1=1,
    timerClkSelCascade=2,
    timerClkSelHFPerClk=0
} TIMER_ClkSel_TypeDef;

typedef enum TIMER_Mode_TypeDef {
    timerModeDown=1,
    timerModeQDec=3,
    timerModeUp=0,
    timerModeUpDown=2
} TIMER_Mode_TypeDef;

struct TIMER_Init_TypeDef {
    _Bool enable;
    _Bool debugRun;
    enum TIMER_Prescale_TypeDef prescale;
    enum TIMER_ClkSel_TypeDef clkSel;
    _Bool count2x;
    _Bool ati;
    enum TIMER_InputAction_TypeDef fallAction;
    enum TIMER_InputAction_TypeDef riseAction;
    enum TIMER_Mode_TypeDef mode;
    _Bool dmaClrAct;
    _Bool quadModeX4;
    _Bool oneShot;
    _Bool sync;
};

typedef struct TIMER_InitCC_TypeDef TIMER_InitCC_TypeDef, *PTIMER_InitCC_TypeDef;

typedef enum TIMER_Edge_TypeDef {
    timerEdgeBoth=2,
    timerEdgeFalling=1,
    timerEdgeNone=3,
    timerEdgeRising=0
} TIMER_Edge_TypeDef;

typedef enum TIMER_OutputAction_TypeDef {
    timerOutputActionClear=2,
    timerOutputActionNone=0,
    timerOutputActionSet=3,
    timerOutputActionToggle=1
} TIMER_OutputAction_TypeDef;

struct TIMER_InitCC_TypeDef {
    enum TIMER_Event_TypeDef eventCtrl;
    enum TIMER_Edge_TypeDef edge;
    enum TIMER_PRSSEL_TypeDef prsSel;
    enum TIMER_OutputAction_TypeDef cufoa;
    enum TIMER_OutputAction_TypeDef cofoa;
    enum TIMER_OutputAction_TypeDef cmoa;
    enum TIMER_CCMode_TypeDef mode;
    _Bool filter;
    _Bool prsInput;
    _Bool coist;
    _Bool outInvert;
};

typedef long _off_t;

typedef struct _mbstate_t _mbstate_t, *P_mbstate_t;

typedef union anon_union.conflictda_for___value anon_union.conflictda_for___value, *Panon_union.conflictda_for___value;

union anon_union.conflictda_for___value {
    wint_t __wch;
    uchar __wchb[4];
};

struct _mbstate_t {
    int __count;
    union anon_union.conflictda_for___value __value;
};

typedef long _fpos_t;

typedef _LOCK_T _flock_t;

typedef union anon_union.conflictda anon_union.conflictda, *Panon_union.conflictda;

union anon_union.conflictda {
    wint_t __wch;
    uchar __wchb[4];
};


// WARNING! conflicting data type names: /DWARF/_types.h/__mode_t - /types.h/__mode_t

typedef struct Queue_t Queue_t, *PQueue_t;

struct Queue_t {
    uint16_t head;
    uint16_t count;
    uint16_t size;
    undefined field_0x6;
    undefined field_0x7;
    void * data[10];
};

typedef __gnuc_va_list va_list;

typedef struct GPIO_TypeDef GPIO_TypeDef, *PGPIO_TypeDef;

typedef struct GPIO_P_TypeDef GPIO_P_TypeDef, *PGPIO_P_TypeDef;

struct GPIO_P_TypeDef {
    uint32_t CTRL;
    uint32_t MODEL;
    uint32_t MODEH;
    uint32_t DOUT;
    uint32_t RESERVED0[2];
    uint32_t DOUTTGL;
    uint32_t DIN;
    uint32_t PINLOCKN;
    uint32_t RESERVED1[1];
    uint32_t OVTDIS;
    uint32_t RESERVED2[1];
};

struct GPIO_TypeDef {
    struct GPIO_P_TypeDef P[6];
    uint32_t RESERVED0[184];
    uint32_t EXTIPSELL;
    uint32_t EXTIPSELH;
    uint32_t EXTIPINSELL;
    uint32_t EXTIPINSELH;
    uint32_t EXTIRISE;
    uint32_t EXTIFALL;
    uint32_t EXTILEVEL;
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
    uint32_t EM4WUEN;
    uint32_t RESERVED1[4];
    uint32_t ROUTEPEN;
    uint32_t ROUTELOC0;
    uint32_t RESERVED2[2];
    uint32_t INSENSE;
    uint32_t LOCK;
};

typedef uint32_t Ecode_t;

typedef struct MSC_TypeDef MSC_TypeDef, *PMSC_TypeDef;

struct MSC_TypeDef {
    uint32_t CTRL;
    uint32_t READCTRL;
    uint32_t WRITECTRL;
    uint32_t WRITECMD;
    uint32_t ADDRB;
    uint32_t RESERVED0[1];
    uint32_t WDATA;
    uint32_t STATUS;
    uint32_t RESERVED1[4];
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
    uint32_t LOCK;
    uint32_t CACHECMD;
    uint32_t CACHEHITS;
    uint32_t CACHEMISSES;
    uint32_t RESERVED2[1];
    uint32_t MASSLOCK;
    uint32_t RESERVED3[1];
    uint32_t STARTUP;
    uint32_t RESERVED4[5];
    uint32_t CMD;
};

typedef enum RAIL_IEEE802154_AddressLength {
    RAIL_IEEE802154_LongAddress=3,
    RAIL_IEEE802154_ShortAddress=2
} RAIL_IEEE802154_AddressLength;

typedef struct RAIL_IEEE802154_Address RAIL_IEEE802154_Address, *PRAIL_IEEE802154_Address;

typedef struct RAIL_IEEE802154_Address RAIL_IEEE802154_Address_t;

typedef enum RAIL_IEEE802154_AddressLength RAIL_IEEE802154_AddressLength_t;

typedef union anon_union.conflict12fa8_for_field_1 anon_union.conflict12fa8_for_field_1, *Panon_union.conflict12fa8_for_field_1;

union anon_union.conflict12fa8_for_field_1 {
    uint16_t shortAddress;
    uint8_t longAddress[8];
};

struct RAIL_IEEE802154_Address {
    RAIL_IEEE802154_AddressLength_t length;
    undefined field_0x1;
    union anon_union.conflict12fa8_for_field_1 field_1;
};

typedef struct RAIL_IEEE802154_AddrConfig RAIL_IEEE802154_AddrConfig, *PRAIL_IEEE802154_AddrConfig;

struct RAIL_IEEE802154_AddrConfig {
    uint16_t panId;
    uint16_t shortAddr;
    uint8_t * longAddr;
};

typedef struct RAIL_IEEE802154_AddrConfig RAIL_IEEE802154_AddrConfig_t;

typedef struct RAIL_IEEE802154_Config RAIL_IEEE802154_Config, *PRAIL_IEEE802154_Config;

struct RAIL_IEEE802154_Config {
    _Bool promiscuousMode;
    _Bool isPanCoordinator;
    uint8_t framesMask;
    RAIL_RadioState_t defaultState;
    uint16_t idleTime;
    uint16_t turnaroundTime;
    uint16_t ackTimeout;
    undefined field_0xa;
    undefined field_0xb;
    RAIL_IEEE802154_AddrConfig_t * addresses;
};

typedef struct RAIL_IEEE802154_Config RAIL_IEEE802154_Config_t;

typedef union anon_union.conflict12fa8 anon_union.conflict12fa8, *Panon_union.conflict12fa8;

union anon_union.conflict12fa8 {
    uint16_t shortAddress;
    uint8_t longAddress[8];
};

typedef struct __sFILE __sFILE, *P__sFILE;

typedef struct _reent _reent, *P_reent;

typedef struct __sFILE __FILE;

typedef struct __sbuf __sbuf, *P__sbuf;

typedef struct __locale_t __locale_t, *P__locale_t;

typedef struct _Bigint _Bigint, *P_Bigint;

typedef union anon_union.conflict907_for__new anon_union.conflict907_for__new, *Panon_union.conflict907_for__new;

typedef struct _atexit _atexit, *P_atexit;

typedef struct _glue _glue, *P_glue;

typedef ulong __ULong;

typedef struct anon_struct.conflict75f anon_struct.conflict75f, *Panon_struct.conflict75f;

typedef struct anon_struct.conflict8bf anon_struct.conflict8bf, *Panon_struct.conflict8bf;

typedef struct _on_exit_args _on_exit_args, *P_on_exit_args;

typedef struct __tm __tm, *P__tm;

typedef struct _rand48 _rand48, *P_rand48;

struct anon_struct.conflict8bf {
    uchar * _nextf[30];
    uint _nmalloc[30];
};

struct _rand48 {
    ushort _seed[3];
    ushort _mult[3];
    ushort _add;
};

struct __tm {
    int __tm_sec;
    int __tm_min;
    int __tm_hour;
    int __tm_mday;
    int __tm_mon;
    int __tm_year;
    int __tm_wday;
    int __tm_yday;
    int __tm_isdst;
};

struct anon_struct.conflict75f {
    uint _unused_rand;
    char * _strtok_last;
    char _asctime_buf[26];
    undefined field_0x22;
    undefined field_0x23;
    struct __tm _localtime_buf;
    int _gamma_signgam;
    undefined field_0x4c;
    undefined field_0x4d;
    undefined field_0x4e;
    undefined field_0x4f;
    ulonglong _rand_next;
    struct _rand48 _r48;
    undefined field_0x66;
    undefined field_0x67;
    struct _mbstate_t _mblen_state;
    struct _mbstate_t _mbtowc_state;
    struct _mbstate_t _wctomb_state;
    char _l64a_buf[8];
    char _signal_buf[24];
    int _getdate_err;
    struct _mbstate_t _mbrlen_state;
    struct _mbstate_t _mbrtowc_state;
    struct _mbstate_t _mbsrtowcs_state;
    struct _mbstate_t _wcrtomb_state;
    struct _mbstate_t _wcsrtombs_state;
    int _h_errno;
};

union anon_union.conflict907_for__new {
    struct anon_struct.conflict75f _reent;
    struct anon_struct.conflict8bf _unused;
};

struct _Bigint {
    struct _Bigint * _next;
    int _k;
    int _maxwds;
    int _sign;
    int _wds;
    __ULong _x[1];
};

struct _glue {
    struct _glue * _next;
    int _niobs;
    __FILE * _iobs;
};

struct __sbuf {
    uchar * _base;
    int _size;
};

struct __sFILE {
    uchar * _p;
    int _r;
    int _w;
    short _flags;
    short _file;
    struct __sbuf _bf;
    int _lbfsize;
    void * _cookie;
    int (* _read)(struct _reent *, void *, char *, int);
    int (* _write)(struct _reent *, void *, char *, int);
    _fpos_t (* _seek)(struct _reent *, void *, _fpos_t, int);
    int (* _close)(struct _reent *, void *);
    struct __sbuf _ub;
    uchar * _up;
    int _ur;
    uchar _ubuf[3];
    uchar _nbuf[1];
    struct __sbuf _lb;
    int _blksize;
    _off_t _offset;
    struct _reent * _data;
    _flock_t _lock;
    struct _mbstate_t _mbstate;
    int _flags2;
};

struct _on_exit_args {
    void * _fnargs[32];
    void * _dso_handle[32];
    __ULong _fntypes;
    __ULong _is_cxa;
};

struct _atexit {
    struct _atexit * _next;
    int _ind;
    void (* _fns[32])(void);
    struct _on_exit_args _on_exit_args;
};

struct _reent {
    int _errno;
    __FILE * _stdin;
    __FILE * _stdout;
    __FILE * _stderr;
    int _inc;
    char _emergency[25];
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    int _unspecified_locale_info;
    struct __locale_t * _locale;
    int __sdidinit;
    void (* __cleanup)(struct _reent *);
    struct _Bigint * _result;
    int _result_k;
    struct _Bigint * _p5s;
    struct _Bigint * * _freelist;
    int _cvtlen;
    char * _cvtbuf;
    union anon_union.conflict907_for__new _new;
    struct _atexit * _atexit;
    struct _atexit _atexit0;
    void (** _sig_func)(int);
    struct _glue __sglue;
    __FILE __sf[3];
    undefined field_0x424;
    undefined field_0x425;
    undefined field_0x426;
    undefined field_0x427;
};

struct __locale_t {
};

typedef union anon_union.conflict907 anon_union.conflict907, *Panon_union.conflict907;

union anon_union.conflict907 {
    struct anon_struct.conflict75f _reent;
    struct anon_struct.conflict8bf _unused;
};

typedef struct RTCC_CCChConf_TypeDef RTCC_CCChConf_TypeDef, *PRTCC_CCChConf_TypeDef;

typedef enum RTCC_CapComChMode_TypeDef {
    rtccCapComChModeCapture=1,
    rtccCapComChModeCompare=2,
    rtccCapComChModeOff=0
} RTCC_CapComChMode_TypeDef;

typedef enum RTCC_CompMatchOutAction_TypeDef {
    rtccCompMatchOutActionClear=2,
    rtccCompMatchOutActionPulse=0,
    rtccCompMatchOutActionSet=3,
    rtccCompMatchOutActionToggle=1
} RTCC_CompMatchOutAction_TypeDef;

typedef enum RTCC_PRSSel_TypeDef {
    rtccPRSCh0=0,
    rtccPRSCh1=1,
    rtccPRSCh10=10,
    rtccPRSCh11=11,
    rtccPRSCh2=2,
    rtccPRSCh3=3,
    rtccPRSCh4=4,
    rtccPRSCh5=5,
    rtccPRSCh6=6,
    rtccPRSCh7=7,
    rtccPRSCh8=8,
    rtccPRSCh9=9
} RTCC_PRSSel_TypeDef;

typedef enum RTCC_InEdgeSel_TypeDef {
    rtccInEdgeBoth=2,
    rtccInEdgeFalling=1,
    rtccInEdgeNone=3,
    rtccInEdgeRising=0
} RTCC_InEdgeSel_TypeDef;

typedef enum RTCC_CompBase_TypeDef {
    rtccCompBaseCnt=0,
    rtccCompBasePreCnt=1
} RTCC_CompBase_TypeDef;

typedef enum RTCC_DayCompareMode_TypeDef {
    rtccDayCompareModeMonth=0,
    rtccDayCompareModeWeek=1
} RTCC_DayCompareMode_TypeDef;

struct RTCC_CCChConf_TypeDef {
    enum RTCC_CapComChMode_TypeDef chMode;
    enum RTCC_CompMatchOutAction_TypeDef compMatchOutAction;
    enum RTCC_PRSSel_TypeDef prsSel;
    enum RTCC_InEdgeSel_TypeDef inputEdgeSel;
    enum RTCC_CompBase_TypeDef compBase;
    uint8_t compMask;
    enum RTCC_DayCompareMode_TypeDef dayCompMode;
};

typedef enum RTCC_CntMode_TypeDef {
    rtccCntModeCalendar=1,
    rtccCntModeNormal=0
} RTCC_CntMode_TypeDef;

typedef struct RTCC_Init_TypeDef RTCC_Init_TypeDef, *PRTCC_Init_TypeDef;

typedef enum RTCC_CntPresc_TypeDef {
    rtccCntPresc_1=0,
    rtccCntPresc_1024=10,
    rtccCntPresc_128=7,
    rtccCntPresc_16=4,
    rtccCntPresc_16384=14,
    rtccCntPresc_2=1,
    rtccCntPresc_2048=11,
    rtccCntPresc_256=8,
    rtccCntPresc_32=5,
    rtccCntPresc_32768=15,
    rtccCntPresc_4=2,
    rtccCntPresc_4096=12,
    rtccCntPresc_512=9,
    rtccCntPresc_64=6,
    rtccCntPresc_8=3,
    rtccCntPresc_8192=13
} RTCC_CntPresc_TypeDef;

typedef enum RTCC_PrescMode_TypeDef {
    rtccCntTickCCV0Match=1,
    rtccCntTickPresc=0
} RTCC_PrescMode_TypeDef;

struct RTCC_Init_TypeDef {
    _Bool enable;
    _Bool debugRun;
    _Bool precntWrapOnCCV0;
    _Bool cntWrapOnCCV1;
    enum RTCC_CntPresc_TypeDef presc;
    enum RTCC_PrescMode_TypeDef prescMode;
    _Bool enaOSCFailDetect;
    enum RTCC_CntMode_TypeDef cntMode;
    _Bool disLeapYearCorr;
};

typedef enum PAL_GpioMode_t {
    palGpioModePushPull=0
} PAL_GpioMode_t;

typedef void DMD_InitConfig;

typedef struct Stats Stats, *PStats;

typedef struct Stats Stats_t;

struct Stats {
    uint32_t samples;
    int32_t min;
    int32_t max;
    float mean;
    float varianceTimesSamples;
};

typedef enum AppMode {
    BER=13,
    DIRECT=4,
    NONE=0,
    PER=12,
    RF_SENSE=11,
    RX_OVERFLOW=8,
    RX_SCHEDULED=14,
    SCHTX_AFTER_RX=7,
    TX_CANCEL=10,
    TX_CONTINUOUS=3,
    TX_N_PACKETS=5,
    TX_SCHEDULED=6,
    TX_STREAM=1,
    TX_TONE=2,
    TX_UNDERFLOW=9
} AppMode;

typedef struct ButtonArray ButtonArray, *PButtonArray;

typedef struct ButtonArray ButtonArray_t;

struct ButtonArray {
    enum GPIO_Port_TypeDef port;
    undefined field_0x1;
    undefined field_0x2;
    undefined field_0x3;
    uint pin;
};

typedef struct Counters Counters, *PCounters;

struct Counters {
    uint32_t transmit;
    uint32_t receive;
    uint32_t syncDetect;
    uint32_t preambleDetect;
    uint32_t frameError;
    uint32_t rxOfEvent;
    uint32_t txAbort;
    uint32_t txChannelBusy;
    uint32_t addrFilterEvent;
    uint32_t rxFail;
    uint32_t calibrations;
    uint32_t noRxBuffer;
    uint32_t rfSensedEvent;
    uint32_t perTriggers;
    uint32_t ackTimeout;
    uint32_t lbtSuccess;
    uint32_t lbtRetry;
    uint32_t lbtStartCca;
    Stats_t rssi;
};

typedef struct Counters Counters_t;

typedef enum AppMode AppMode_t;

typedef struct tLedArray tLedArray, *PtLedArray;

struct tLedArray {
    enum GPIO_Port_TypeDef port;
    undefined field_0x1;
    undefined field_0x2;
    undefined field_0x3;
    uint pin;
};

typedef struct stat stat, *Pstat;

struct stat {
    dev_t st_dev;
    ino_t st_ino;
    mode_t st_mode;
    nlink_t st_nlink;
    uid_t st_uid;
    gid_t st_gid;
    dev_t st_rdev;
    off_t st_size;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    time_t st_atime;
    long st_spare1;
    undefined field_0x24;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
    time_t st_mtime;
    long st_spare2;
    undefined field_0x34;
    undefined field_0x35;
    undefined field_0x36;
    undefined field_0x37;
    time_t st_ctime;
    long st_spare3;
    blksize_t st_blksize;
    blkcnt_t st_blocks;
    long st_spare4[2];
    undefined field_0x54;
    undefined field_0x55;
    undefined field_0x56;
    undefined field_0x57;
};

typedef enum CMU_Select_TypeDef {
    cmuSelect_AUXHFRCO=7,
    cmuSelect_Disabled=1,
    cmuSelect_Error=0,
    cmuSelect_HFCLK=8,
    cmuSelect_HFCLKLE=6,
    cmuSelect_HFRCO=5,
    cmuSelect_HFXO=4,
    cmuSelect_LFRCO=3,
    cmuSelect_LFXO=2,
    cmuSelect_ULFRCO=9
} CMU_Select_TypeDef;

typedef struct CMU_HFXOInit_TypeDef CMU_HFXOInit_TypeDef, *PCMU_HFXOInit_TypeDef;

typedef enum CMU_OscMode_TypeDef {
    cmuOscMode_AcCoupled=1,
    cmuOscMode_Crystal=0,
    cmuOscMode_External=2
} CMU_OscMode_TypeDef;

struct CMU_HFXOInit_TypeDef {
    _Bool lowPowerMode;
    _Bool autoStartEm01;
    _Bool autoSelEm01;
    _Bool autoStartSelOnRacWakeup;
    uint16_t ctuneStartup;
    uint16_t ctuneSteadyState;
    uint8_t regIshSteadyState;
    uint8_t xoCoreBiasTrimStartup;
    uint8_t xoCoreBiasTrimSteadyState;
    uint8_t thresholdPeakDetect;
    uint8_t timeoutShuntOptimization;
    uint8_t timeoutPeakDetect;
    uint8_t timeoutSteady;
    uint8_t timeoutStartup;
    enum CMU_OscMode_TypeDef mode;
    undefined field_0x11;
};

typedef enum CMU_HFXOTuningMode_TypeDef {
    cmuHFXOTuningMode_Auto=0,
    cmuHFXOTuningMode_PeakShuntCommand=48,
    cmuHFXOTuningMode_ShuntCommand=32
} CMU_HFXOTuningMode_TypeDef;

typedef enum CMU_Clock_TypeDef {
    cmuClock_ACMP0=279040,
    cmuClock_ACMP1=283136,
    cmuClock_ADC0=295424,
    cmuClock_AUX=917504,
    cmuClock_BUS=524288,
    cmuClock_CORE=131152,
    cmuClock_CRYOTIMER=287232,
    cmuClock_CRYPTO=529664,
    cmuClock_DBG=786438,
    cmuClock_EXPORT=655392,
    cmuClock_GPCRC=546048,
    cmuClock_GPIO=533760,
    cmuClock_HF=17,
    cmuClock_HFLE=525568,
    cmuClock_HFPER=344384,
    cmuClock_I2C0=291328,
    cmuClock_IDAC0=299520,
    cmuClock_LDMA=541952,
    cmuClock_LETIMER0=1312352,
    cmuClock_LEUART0=1443696,
    cmuClock_LFA=1703938,
    cmuClock_LFB=1835011,
    cmuClock_LFE=2097157,
    cmuClock_PCNT0=1706496,
    cmuClock_PRS=537856,
    cmuClock_RTCC=1182080,
    cmuClock_TIMER0=262656,
    cmuClock_TIMER1=266752,
    cmuClock_USART0=270848,
    cmuClock_USART1=274944
} CMU_Clock_TypeDef;

typedef uint32_t CMU_ClkPresc_TypeDef;

typedef uint32_t CMU_ClkDiv_TypeDef;

typedef struct CMU_LFXOInit_TypeDef CMU_LFXOInit_TypeDef, *PCMU_LFXOInit_TypeDef;

struct CMU_LFXOInit_TypeDef {
    uint8_t ctune;
    uint8_t gain;
    uint8_t timeout;
    enum CMU_OscMode_TypeDef mode;
};

typedef enum CMU_HFRCOFreq_TypeDef {
    cmuHFRCOFreq_13M0Hz=13000000,
    cmuHFRCOFreq_16M0Hz=16000000,
    cmuHFRCOFreq_19M0Hz=19000000,
    cmuHFRCOFreq_1M0Hz=1000000,
    cmuHFRCOFreq_26M0Hz=26000000,
    cmuHFRCOFreq_2M0Hz=2000000,
    cmuHFRCOFreq_32M0Hz=32000000,
    cmuHFRCOFreq_38M0Hz=38000000,
    cmuHFRCOFreq_4M0Hz=4000000,
    cmuHFRCOFreq_7M0Hz=7000000,
    cmuHFRCOFreq_UserDefined=0
} CMU_HFRCOFreq_TypeDef;

typedef enum CMU_Osc_TypeDef {
    cmuOsc_AUXHFRCO=4,
    cmuOsc_HFRCO=3,
    cmuOsc_HFXO=2,
    cmuOsc_LFRCO=1,
    cmuOsc_LFXO=0,
    cmuOsc_ULFRCO=5
} CMU_Osc_TypeDef;

typedef enum CMU_AUXHFRCOFreq_TypeDef {
    cmuAUXHFRCOFreq_13M0Hz=13000000,
    cmuAUXHFRCOFreq_16M0Hz=16000000,
    cmuAUXHFRCOFreq_19M0Hz=19000000,
    cmuAUXHFRCOFreq_1M0Hz=1000000,
    cmuAUXHFRCOFreq_26M0Hz=26000000,
    cmuAUXHFRCOFreq_2M0Hz=2000000,
    cmuAUXHFRCOFreq_32M0Hz=32000000,
    cmuAUXHFRCOFreq_38M0Hz=38000000,
    cmuAUXHFRCOFreq_4M0Hz=4000000,
    cmuAUXHFRCOFreq_7M0Hz=7000000,
    cmuAUXHFRCOFreq_UserDefined=0
} CMU_AUXHFRCOFreq_TypeDef;

typedef enum anon_enum_32.conflict65c6 {
    cmuClock_ACMP0=279040,
    cmuClock_ACMP1=283136,
    cmuClock_ADC0=295424,
    cmuClock_AUX=917504,
    cmuClock_BUS=524288,
    cmuClock_CORE=131152,
    cmuClock_CRYOTIMER=287232,
    cmuClock_CRYPTO=529664,
    cmuClock_DBG=786438,
    cmuClock_EXPORT=655392,
    cmuClock_GPCRC=546048,
    cmuClock_GPIO=533760,
    cmuClock_HF=17,
    cmuClock_HFLE=525568,
    cmuClock_HFPER=344384,
    cmuClock_I2C0=291328,
    cmuClock_IDAC0=299520,
    cmuClock_LDMA=541952,
    cmuClock_LETIMER0=1312352,
    cmuClock_LEUART0=1443696,
    cmuClock_LFA=1703938,
    cmuClock_LFB=1835011,
    cmuClock_LFE=2097157,
    cmuClock_PCNT0=1706496,
    cmuClock_PRS=537856,
    cmuClock_RTCC=1182080,
    cmuClock_TIMER0=262656,
    cmuClock_TIMER1=266752,
    cmuClock_USART0=270848,
    cmuClock_USART1=274944
} anon_enum_32.conflict65c6;

typedef struct RTCC_TypeDef RTCC_TypeDef, *PRTCC_TypeDef;

typedef struct RTCC_CC_TypeDef RTCC_CC_TypeDef, *PRTCC_CC_TypeDef;

struct RTCC_CC_TypeDef {
    uint32_t CTRL;
    uint32_t CCV;
    uint32_t TIME;
    uint32_t DATE;
};

struct RTCC_TypeDef {
    uint32_t CTRL;
    uint32_t PRECNT;
    uint32_t CNT;
    uint32_t COMBCNT;
    uint32_t TIME;
    uint32_t DATE;
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
    uint32_t STATUS;
    uint32_t CMD;
    uint32_t SYNCBUSY;
    uint32_t POWERDOWN;
    uint32_t LOCK;
    uint32_t EM4WUEN;
    struct RTCC_CC_TypeDef CC[3];
    uint32_t RESERVED0[37];
    struct RTCC_RET_TypeDef RET[32];
};

typedef struct RADIO_PAInit RADIO_PAInit, *PRADIO_PAInit;

typedef enum RADIO_PASel {
    PA_SEL_2P4_HP=0,
    PA_SEL_2P4_LP=1,
    PA_SEL_SUBGIG=2
} RADIO_PASel;

typedef enum RADIO_PASel RADIO_PASel_t;

typedef enum RADIO_PAVoltMode {
    PA_VOLTMODE_DCDC=1,
    PA_VOLTMODE_VBAT=0
} RADIO_PAVoltMode;

typedef enum RADIO_PAVoltMode RADIO_PAVoltMode_t;

struct RADIO_PAInit {
    RADIO_PASel_t paSel;
    RADIO_PAVoltMode_t voltMode;
    int16_t power;
    int16_t offset;
    uint16_t rampTime;
};

typedef struct RADIO_PAInit RADIO_PAInit_t;

typedef struct EMU_TypeDef EMU_TypeDef, *PEMU_TypeDef;

struct EMU_TypeDef {
    uint32_t CTRL;
    uint32_t STATUS;
    uint32_t LOCK;
    uint32_t RAM0CTRL;
    uint32_t CMD;
    uint32_t RESERVED0[1];
    uint32_t EM4CTRL;
    uint32_t TEMPLIMITS;
    uint32_t TEMP;
    uint32_t IF;
    uint32_t IFS;
    uint32_t IFC;
    uint32_t IEN;
    uint32_t PWRLOCK;
    uint32_t PWRCFG;
    uint32_t PWRCTRL;
    uint32_t DCDCCTRL;
    uint32_t RESERVED1[2];
    uint32_t DCDCMISCCTRL;
    uint32_t DCDCZDETCTRL;
    uint32_t DCDCCLIMCTRL;
    uint32_t RESERVED2[1];
    uint32_t DCDCLNVCTRL;
    uint32_t DCDCTIMING;
    uint32_t DCDCLPVCTRL;
    uint32_t RESERVED3[1];
    uint32_t DCDCLPCTRL;
    uint32_t DCDCLNFREQCTRL;
    uint32_t RESERVED4[1];
    uint32_t DCDCSYNC;
    uint32_t RESERVED5[5];
    uint32_t VMONAVDDCTRL;
    uint32_t VMONALTAVDDCTRL;
    uint32_t VMONDVDDCTRL;
    uint32_t VMONIO0CTRL;
};

typedef enum IRQn {
    ACMP0_IRQn=13,
    ADC0_IRQn=14,
    BusFault_IRQn=-11,
    CMU_IRQn=23,
    CRYOTIMER_IRQn=31,
    CRYPTO_IRQn=25,
    DebugMonitor_IRQn=-4,
    EMU_IRQn=0,
    FPUEH_IRQn=33,
    GPIO_EVEN_IRQn=9,
    GPIO_ODD_IRQn=17,
    HardFault_IRQn=-13,
    I2C0_IRQn=16,
    IDAC0_IRQn=15,
    LDMA_IRQn=8,
    LETIMER0_IRQn=26,
    LEUART0_IRQn=21,
    MSC_IRQn=24,
    MemoryManagement_IRQn=-12,
    NonMaskableInt_IRQn=-14,
    PCNT0_IRQn=22,
    PendSV_IRQn=-2,
    RTCC_IRQn=29,
    SVCall_IRQn=-5,
    SysTick_IRQn=-1,
    TIMER0_IRQn=10,
    TIMER1_IRQn=18,
    USART0_RX_IRQn=11,
    USART0_TX_IRQn=12,
    USART1_RX_IRQn=19,
    USART1_TX_IRQn=20,
    UsageFault_IRQn=-10,
    WDOG0_IRQn=2
} IRQn;

typedef enum IRQn IRQn_Type;

typedef struct CORE_nvicMask_t CORE_nvicMask_t, *PCORE_nvicMask_t;

struct CORE_nvicMask_t {
    uint32_t a[2];
};

typedef uint32_t CORE_irqState_t;

typedef ushort __uint16_t;

typedef short __int16_t;

typedef enum StripMode {
    STRIP_NONE=0,
    STRIP_TAG=1,
    STRIP_VALUE=2
} StripMode;

typedef enum StripMode StripMode_t;

typedef enum RADIO_PTIMode {
    RADIO_PTI_MODE_DISABLED=3,
    RADIO_PTI_MODE_SPI=0,
    RADIO_PTI_MODE_UART=1,
    RADIO_PTI_MODE_UART_ONEWIRE=2
} RADIO_PTIMode;

typedef struct RADIO_PTIInit RADIO_PTIInit, *PRADIO_PTIInit;

typedef enum RADIO_PTIMode RADIO_PTIMode_t;

struct RADIO_PTIInit {
    RADIO_PTIMode_t mode;
    undefined field_0x1;
    undefined field_0x2;
    undefined field_0x3;
    uint32_t baud;
    uint8_t doutLoc;
    enum GPIO_Port_TypeDef doutPort;
    uint8_t doutPin;
    uint8_t dclkLoc;
    enum GPIO_Port_TypeDef dclkPort;
    uint8_t dclkPin;
    uint8_t dframeLoc;
    enum GPIO_Port_TypeDef dframePort;
    uint8_t dframePin;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
};

typedef struct RADIO_PTIInit RADIO_PTIInit_t;


// WARNING! conflicting data type names: /stdarg.h/__gnuc_va_list - /DWARF/stdarg.h/__gnuc_va_list

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

typedef struct Elf32_Phdr Elf32_Phdr, *PElf32_Phdr;

typedef enum Elf_ProgramHeaderType_ARM {
    PT_ARM_EXIDX=1879048192,
    PT_DYNAMIC=2,
    PT_GNU_EH_FRAME=1685382480,
    PT_GNU_RELRO=1685382482,
    PT_GNU_STACK=1685382481,
    PT_INTERP=3,
    PT_LOAD=1,
    PT_NOTE=4,
    PT_NULL=0,
    PT_PHDR=6,
    PT_SHLIB=5,
    PT_TLS=7
} Elf_ProgramHeaderType_ARM;

struct Elf32_Phdr {
    enum Elf_ProgramHeaderType_ARM p_type;
    dword p_offset;
    dword p_vaddr;
    dword p_paddr;
    dword p_filesz;
    dword p_memsz;
    dword p_flags;
    dword p_align;
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

#define RAIL_TX_CONFIG_CHANNEL_BUSY 4

#define RAIL_TX_CONFIG_CCA_RETRY 64

#define RAIL_RX_OPTION_STORE_CRC 1

#define RAIL_MAX_LBT_TRIES 15

#define RAIL_TX_CONFIG_CHANNEL_CLEAR 32

#define RAIL_TX_CONFIG_START_CCA 128

#define RAIL_RX_CONFIG_PACKET_ABORTED 1024

#define RAIL_RX_CONFIG_FILTER_PASSED 2048

#define RAIL_RX_CONFIG_INVALID_CRC 16

#define RAIL_RX_CONFIG_SYNC1_DETECT 4

#define RAIL_TX_CONFIG_TX_BLOCKED 16

#define RAIL_RX_CONFIG_SYNC2_DETECT 8

#define RAIL_TX_CONFIG_TX_ABORTED 8

#define RAIL_DEBUG_MODE_FREQ_OVERRIDE 1

#define RAIL_RX_CONFIG_FRAME_ERROR 16

#define RAIL_DEBUG_CONFIG_STATE_CHANGE 2

#define ADDRCONFIG_MATCH_TABLE_SINGLE_FIELD 33554430

#define RAIL_AUTOACK_MAX_LENGTH 64

#define RAIL_IGNORE_CRC_ERRORS 1

#define RAIL_TX_CONFIG_BUFFER_OVERFLOW 1

#define RAIL_IGNORE_NO_ERRORS 0

#define ADDRCONFIG_MATCH_TABLE_DOUBLE_FIELD 17043520

#define RAIL_RX_CONFIG_RF_SENSED 128

#define RAIL_TX_CONFIG_BUFFER_UNDERFLOW 2

#define RAIL_RX_CONFIG_SCHEDULED_RX_END 512

#define RAIL_RSSI_INVALID -512

#define RAIL_RX_CONFIG_BUFFER_UNDERFLOW 1

#define RAIL_RX_CONFIG_ADDRESS_FILTERED 64

#define RAIL_IGNORE_ALL_ERRORS 255

#define RAIL_RX_CONFIG_TIMEOUT 256

#define RAIL_SETFIXEDLENGTH_INVALID 65535

#define RAIL_RX_CONFIG_BUFFER_OVERFLOW 32

#define RAIL_RX_CONFIG_PREAMBLE_DETECT 2


// WARNING! conflicting data type names: /stdint.h/uint32_t - /DWARF/_stdint.h/uint32_t


// WARNING! conflicting data type names: /stdint.h/uint8_t - /DWARF/_stdint.h/uint8_t




void FUN_00000000(void);
undefined1 * __do_global_dtors_aux(undefined1 *param_1);
undefined8 frame_dummy(undefined1 *param_1,undefined *param_2);
void _start(void);
void ieee802154Enable(int argc,char **argv);
void config2p4Ghz802154(int argc,char **argv);
void ieee802154AcceptFrames(int argc,char **argv);
void ieee802154SetPromiscuousMode(int argc,char **argv);
void ieee802154SetPanCoordinator(int argc,char **argv);
void ieee802154SetPanId(int argc,char **argv);
void ieee802154SetShortAddress(int argc,char **argv);
void ieee802154SetLongAddress(int argc,char **argv);
void addressFilterByFrame(int argc,char **argv);
void getAddressFilter(int argc,char **argv);
void setAddressFilter(int argc,char **argv);
void printAddresses(int argc,char **argv);
void setAddressFilterConfig(int argc,char **argv);
void setAddress(int argc,char **argv);
void enableAddress(int argc,char **argv);
void autoAckConfig(int argc,char **argv);
void getAutoAck(int argc,char **argv);
void autoAckDisable(int argc,char **argv);
void autoAckPause(int argc,char **argv);
void setTxAckOptions(int argc,char **argv);
void bleStatus(int argc,char **argv);
void bleEnable(int argc,char **argv);
void bleSet1MbpsPhy(int argc,char **argv);
void bleSet2MbpsPhy(int argc,char **argv);
void bleSetChannelParams(int argc,char **argv);
void bleAdvertisingConfig(int argc,char **argv);
void setFrequency(int argc,char **argv);
char * lookupDebugModeString(uint32_t debugMode);
void setDebugMode(int argc,char **argv);
void getMemWord(int argc,char **argv);
void setMemWord(int argc,char **argv);
void setTxUnderflow(int argc,char **argv);
void setRxOverflow(int argc,char **argv);
void setCalibrations(int argc,char **argv);
void txCancel(int argc,char **argv);
void getLogLevels(int argc,char **argv);
void setPeripheralEnable(int argc,char **argv);
void setNotifications(int argc,char **argv);
void resetChip(int argc,char **argv);
void printDataRates(int argc,char **argv);
void getRandom(int argc,char **argv);
void setDebugSignal(int argc,char **argv);
void startPerMode(int argc,char **argv);
void updateStats(int32_t newValue,Stats_t *stats);
void getPerStats(int argc,char **argv);
void berConfigSet(int argc,char **argv);
void berRx(int argc,char **argv);
void berStatusGet(int argc,char **argv);
void getStatus(int argc,char **argv);
void getVersion(int argc,char **argv);
void setPtiProtocol(int argc,char **argv);
void getVersionVerbose(int argc,char **argv);
void getRssi(int argc,char **argv);
void startAvgRssi(int argc,char **argv);
void getAvgRssi(int argc,char **argv);
void sweepPower(int argc,char **argv);
void resetCounters(int argc,char **argv);
void getTime(int argc,char **argv);
void setTime(int argc,char **argv);
void setLbtMode(int argc,char **argv);
void getLbtParams(int argc,char **argv);
void setLbtParams(int argc,char **argv);
void printTxPacket(int argc,char **argv);
void setTxPayload(int argc,char **argv);
void setTxLength(int argc,char **argv);
void printAckPacket(int argc,char **argv);
void setAckPayload(int argc,char **argv);
void setAckLength(int argc,char **argv);
int8_t stringsToStates(char **strings,RAIL_RadioState_t *states);
void getChannel(int argc,char **argv);
void setChannel(int argc,char **argv);
void getPower(int argc,char **argv);
void setPower(int argc,char **argv);
void getTxDelay(int argc,char **argv);
void setTxDelay(int argc,char **argv);
void getCtune(int argc,char **argv);
void setCtune(int argc,char **argv);
void setPaCtune(int argc,char **argv);
void getConfig(int argc,char **argv);
void listConfigs(int argc,char **argv);
void setConfig(int argc,char **argv);
void setTxTransitions(int argc,char **argv);
void setRxTransitions(int argc,char **argv);
void setTimings(int argc,char **argv);
void printTimerStats(int argc,char **argv);
void setTimer(int argc,char **argv);
void timerCancel(int argc,char **argv);
void tx(int argc,char **argv);
void txWithOptions(int argc,char **argv);
void configTxOptions(int argc,char **argv);
void txAtTime(int argc,char **argv);
void txAfterRx(int argc,char **argv);
void rx(int argc,char **argv);
void setTxTone(int argc,char **argv);
void setTxStream(int argc,char **argv);
void setDirectMode(int argc,char **argv);
void setDirectTx(int argc,char **argv);
void sleep(int argc,char **argv);
void rfSense(int argc,char **argv);
void rfSensedCheck(void);
_Bool parseTimeModeFromString(char *str,RAIL_TimeMode_t *mode);
void rxAt(int argc,char **argv);
void gpio0LongPress(void);
void gpio0ShortPress(void);
void gpio1ShortPress(void);
void gpioCallback(uint8_t pin);
void appHalInit(void);
void updateDisplay(void);
void LedSet(int led);
void LedToggle(int led);
void PeripheralDisable(void);
EMSTATUS PeripheralEnable(void);
void usDelay(uint32_t microseconds);
void serialWaitForTxIdle(void);
void RAILCb_RfReady(void);
void RAILCb_CalNeeded(void);
void RAILCb_RadioStateChanged(uint8_t state);
void RAILCb_TxPacketSent(RAIL_TxPacketInfo_t *txPacketInfo);
void RAILCb_RxPacketReceived(void *rxPacketHandle);
void RAILCb_RxRadioStatusExt(uint32_t status);
void RAILCb_TxRadioStatus(uint8_t status);
void RAILCb_TimerExpired(void);
void RAILCb_RxAckTimeout(void);
RAIL_Status_t RAILCb_IEEE802154_DataRequestCommand(void);
void RAILCb_RssiAverageDone(int16_t avgRssi);
void processPendingCalibrations(void);
void processPendingCalibrations::lexical_block_0(void);
void checkTimerExpiration(void);
void printNewTxError(void);
void printAckTimeout(void);
void changeChannel(uint32_t i);
void changeChannelConfig(int newConfig);
void changeRadioConfig(int newConfig);
void pendPacketTx(void);
void sendPacketIfPending(void);
void pendFinishTxSequence(void);
void finishTxSequenceIfPending(void);
void setNextPacketTime(uint32_t absTime);
void printPacket(char *cmdName,uint8_t *data,uint16_t dataLength,RAIL_RxPacketInfo_t *packetInfo);
void printReceivedPacket(void);
void processInputCharacters(void);
int main(void);
void ciErrorCallback(char *command,CommandError_t error);
AppMode_t currentAppMode(void);
void enableAppMode(AppMode_t next,_Bool enable,char *command);
char * appModeNames(AppMode_t appMode);
void changeAppModeIfPending(void);
void setNextAppMode(char *command,AppMode_t next);
_Bool inAppMode(AppMode_t appMode,char *command);
_Bool inRadioState(RAIL_RadioState_t state,char *command);
void setNextAppMode(AppMode_t next,char *command);
_Bool enableAppModeSync(AppMode_t mode,_Bool enable,char *command);
void scheduleNextTx(void);
void radioTransmit(uint32_t iterations,char *command);
void * memoryAllocate(uint32_t size);
void * memoryPtrFromHandle(void *handle);
void memoryFree(void *handle);
void memoryTakeReference(void *handle);
void * RAILCb_AllocateMemory(uint32_t size);
void RAILCb_FreeMemory(void *handle);
void * RAILCb_BeginWriteMemory(void *handle,uint32_t offset,uint32_t *available);
void RAILCb_EndWriteMemory(void *handle,uint32_t offset,uint32_t size);
_Bool queueInit(Queue_t *queue,uint16_t size);
_Bool queueAdd(Queue_t *queue,void *data);
void * queueRemove(Queue_t *queue);
_Bool queueIsEmpty(Queue_t *queue);
_Bool validateInteger(char *str,int lengthInBytes,_Bool isSigned);
_Bool ciPrintHelp(CommandEntry_t *commands);
uint8_t ciInitState(CommandState_t *state,char *buffer,uint32_t length,CommandEntry_t *commands);
int8_t ciProcessInput(CommandState_t *state,char *data,uint32_t length);
uint32_t ciGetUnsigned(char *arg);
int32_t ciGetSigned(char *arg);
_Bool ciValidateInteger(char *arg,char type);
void Reset_Handler(void);
void IDAC0_IRQHandler(void);
uint32_t SystemMaxCoreClockGet(void);
uint32_t SystemHFClockGet(void);
void SystemCoreClockGet(void);
uint32_t SystemHFXOClockGet(void);
void SystemInit(void);
uint32_t SystemLFRCOClockGet(void);
uint32_t SystemULFRCOClockGet(void);
uint32_t SystemLFXOClockGet(void);
void BSP_BccPinsEnable(_Bool enable);
int BSP_BccInit(void);
int BSP_Init(uint32_t flags);
int BSP_LedsInit(void);
int BSP_LedClear(int ledNo);
int BSP_LedSet(int ledNo);
int BSP_LedToggle(int ledNo);
void flashWaitStateControl(uint32_t coreFreq);
void flashWaitStateMax(void);
void syncReg(uint32_t mask);
void CMU_OscillatorTuningSet(uint32_t val,CMU_Osc_TypeDef osc);
void CMU_ClockEnable(CMU_Clock_TypeDef clock,_Bool enable);
uint32_t CMU_ClockPrescGet(CMU_Clock_TypeDef clock);
CMU_ClkDiv_TypeDef CMU_ClockDivGet(CMU_Clock_TypeDef clock);
CMU_Select_TypeDef CMU_ClockSelectGet(CMU_Clock_TypeDef clock);
uint32_t lfClkGet(CMU_Clock_TypeDef lfClkBranch);
uint32_t CMU_ClockFreqGet(CMU_Clock_TypeDef clock);
void CMU_ClockPrescSet(CMU_Clock_TypeDef clock,CMU_ClkPresc_TypeDef presc);
void CMU_ClockDivSet(CMU_Clock_TypeDef clock,CMU_ClkDiv_TypeDef div);
_Bool CMU_OscillatorTuningWait(CMU_Osc_TypeDef osc,CMU_HFXOTuningMode_TypeDef mode);
_Bool CMU_OscillatorTuningOptimize(CMU_Osc_TypeDef osc,CMU_HFXOTuningMode_TypeDef mode,_Bool wait);
void CMU_OscillatorEnable(CMU_Osc_TypeDef osc,_Bool enable,_Bool wait);
void CMU_ClockSelectSet(CMU_Clock_TypeDef clock,CMU_Select_TypeDef ref);
void CMU_HFXOInit(CMU_HFXOInit_TypeDef *hfxoInit);
CORE_irqState_t CORE_EnterCritical(void);
void CORE_ExitCritical(CORE_irqState_t irqState);
undefined4 CORE_EnterAtomic(void);
void CORE_ExitAtomic(CORE_irqState_t irqState);
void emuRestore(void);
void currentLimitersUpdate(void);
void dcdcHsFixLnBlock(void);
void dcdcFetCntSet(_Bool lpModeSet);
void EMU_EnterEM2(_Bool restore);
void EMU_EnterEM3(_Bool restore);
void EMU_UpdateOscConfig(void);
void EMU_DCDCModeSet(EMU_DcdcMode_TypeDef dcdcMode);
void EMU_EnterEM4(void);
_Bool EMU_DCDCOutputVoltageSet(uint32_t mV,_Bool setLpVoltage,_Bool setLnVoltage);
void EMU_DCDCOptimizeSlice(uint32_t em0LoadCurrent_mA);
void EMU_DCDCLnRcoBandSet(EMU_DcdcLnRcoBand_TypeDef band);
_Bool EMU_DCDCInit(EMU_DCDCInit_TypeDef *dcdcInit);
void GPIO_ExtIntConfig(GPIO_Port_TypeDef port,uint pin,uint intNo,_Bool risingEdge,_Bool fallingEdge,_Bool enable);
void GPIO_PinModeSet(GPIO_Port_TypeDef port,uint pin,GPIO_Mode_TypeDef mode,uint out);
void RMU_ResetCauseClear(void);
uint RMU_ResetCauseGet(void);
void RTCC_ChannelInit(int ch,RTCC_CCChConf_TypeDef *confPtr);
void RTCC_Enable(_Bool enable);
void RTCC_Init(RTCC_Init_TypeDef *init);
void SYSTEM_ChipRevisionGet(SYSTEM_ChipRevision_TypeDef *rev);
void TIMER_Init(TIMER_TypeDef *timer,TIMER_Init_TypeDef *init);
void TIMER_InitCC(TIMER_TypeDef *timer,uint ch,TIMER_InitCC_TypeDef *init);
void USART_BaudrateAsyncSet(USART_TypeDef *usart,uint32_t refFreq,uint32_t baudrate,USART_OVS_TypeDef ovs);
void USART_BaudrateSyncSet(USART_TypeDef *usart,uint32_t refFreq,uint32_t baudrate);
void USART_Enable(USART_TypeDef *usart,USART_Enable_TypeDef enable);
void USART_Reset(USART_TypeDef *usart);
void USART_InitAsync(USART_TypeDef *usart,USART_InitAsync_TypeDef *init);
void USART_InitSync(USART_TypeDef *usart,USART_InitSync_TypeDef *init);
uint8_t USART_Rx(USART_TypeDef *usart);
void USART_Tx(USART_TypeDef *usart,uint8_t data);
void USART_TxDouble(USART_TypeDef *usart,uint16_t data);
void GPIOINT_IRQDispatcher(uint32_t iflags);
void GPIOINT_Init(void);
void GPIOINT_CallbackRegister(uint8_t pin,GPIOINT_IrqCallbackPtr_t *callbackPtr);
void GPIO_EVEN_IRQHandler(void);
void GPIO_ODD_IRQHandler(void);
void halInit(void);
uint32_t halCommonGetInt32uMillisecondTick(void);
void usecDelay(uint32_t usecs);
uint8_t halInitChipSpecific(void);
debugSignal_t * halGetDebugSignals(uint32_t *size);
debugPin_t * halGetDebugPins(uint32_t *size);
void halDisablePrs(uint8_t channel);
void halEnablePrs(uint8_t channel,uint8_t loc,uint8_t source,uint8_t signal);
int _close(int file);
void _exit(int status);
int _fstat(int file,stat *st);
int _isatty(int file);
int _lseek(int file,int ptr,int dir);
int _read(int file,char *ptr,int len);
int _write(int file,char *ptr,int len);
caddr_t _sbrk(int incr);
void USART0_RX_IRQHandler(void);
void RETARGET_SerialCrLf(int on);
void RETARGET_SerialInit(void);
int RETARGET_ReadChar(void);
int RETARGET_WriteChar(char c);
void checkAllTimers(uint32_t timeElapsed);
void executeTimerCallbacks(void);
void rescheduleRtc(uint32_t rtcCnt);
Ecode_t RTCDRV_Init(void);
undefined8 RTCDRV_GetWallClockTicks64(void);
uint32_t RTCDRV_TicksToMsec(uint64_t ticks);
void RTCC_IRQHandler(void);
void UDELAY_Calibrate(void);
void UDELAY_Delay(uint32_t usecs);
Ecode_t USTIMER_Init(void);
void TIMER0_IRQHandler(void);
EMSTATUS DISPLAY_Init(void);
EMSTATUS DISPLAY_DeviceGet(int displayDeviceNo,DISPLAY_Device_t *device);
EMSTATUS DISPLAY_DeviceRegister(DISPLAY_Device_t *device);
EMSTATUS PixelMatrixAllocate(DISPLAY_Device_t *device,uint width,uint height,DISPLAY_PixelMatrix_t *pixelMatrix);
EMSTATUS PixelMatrixFree(DISPLAY_Device_t *device,DISPLAY_PixelMatrix_t pixelMatrix);
EMSTATUS DriverRefresh(DISPLAY_Device_t *device);
EMSTATUS PixelMatrixClear(DISPLAY_Device_t *device,DISPLAY_PixelMatrix_t pixelMatrix,uint width,uint height);
EMSTATUS PixelMatrixDraw(DISPLAY_Device_t *device,DISPLAY_PixelMatrix_t pixelMatrix,uint startColumn,uint width,uint startRow,uint height);
EMSTATUS DisplayPolarityInverse(void);
EMSTATUS DisplayEnable(DISPLAY_Device_t *device,_Bool enable);
EMSTATUS DISPLAY_Ls013b7dh03Init(void);
EMSTATUS PAL_SpiInit(void);
EMSTATUS PAL_SpiTransmit(uint8_t *data,uint len);
EMSTATUS PAL_TimerInit(void);
EMSTATUS PAL_TimerMicroSecondsDelay(uint usecs);
EMSTATUS PAL_TimerRepeat(anon_subr_void_void_ptr *pFunction,void *argument,uint frequency);
EMSTATUS PAL_GpioInit(void);
EMSTATUS PAL_GpioPinModeSet(uint port,uint pin,PAL_GpioMode_t mode,uint platformSpecific);
EMSTATUS PAL_GpioPinOutSet(uint port,uint pin);
EMSTATUS PAL_GpioPinOutClear(uint port,uint pin);
EMSTATUS PAL_GpioPinOutToggle(uint port,uint pin);
EMSTATUS DMD_getDisplayGeometry(DMD_DisplayGeometry **geometry);
EMSTATUS DMD_setClippingArea(uint16_t xStart,uint16_t yStart,uint16_t width,uint16_t height);
EMSTATUS DMD_writeColor(uint16_t x,uint16_t y,uint8_t red,uint8_t green,uint8_t blue,uint32_t numPixels);
EMSTATUS DMD_sleep(void);
EMSTATUS DMD_wakeUp(void);
EMSTATUS DMD_allocateFramebuffer(void **framebuffer);
EMSTATUS DMD_init(DMD_InitConfig *initConfig);
EMSTATUS DMD_updateDisplay(void);
EMSTATUS GLIB_displayWakeUp(void);
EMSTATUS GLIB_displaySleep(void);
EMSTATUS GLIB_setClippingRegion(GLIB_Context_t *pContext,GLIB_Rectangle_t *pRect);
EMSTATUS GLIB_contextInit(GLIB_Context_t *pContext);
EMSTATUS GLIB_resetDisplayClippingArea(GLIB_Context_t *pContext);
EMSTATUS GLIB_clear(GLIB_Context_t *pContext);
void GLIB_colorTranslate24bpp(uint32_t color,uint8_t *red,uint8_t *green,uint8_t *blue);
EMSTATUS GLIB_drawPixel(GLIB_Context_t *pContext,int32_t x,int32_t y);
EMSTATUS GLIB_drawPixelColor(GLIB_Context_t *pContext,int32_t x,int32_t y,uint32_t color);
uint8_t GLIB_getClipCode(GLIB_Context_t *pContext,int32_t x,int32_t y);
EMSTATUS GLIB_drawLineH(GLIB_Context_t *pContext,int32_t x1,int32_t y1,int32_t x2);
EMSTATUS GLIB_drawLineV(GLIB_Context_t *pContext,int32_t x1,int32_t y1,int32_t y2);
EMSTATUS GLIB_drawLine(GLIB_Context_t *pContext,int32_t x1,int32_t y1,int32_t x2,int32_t y2);
EMSTATUS GLIB_drawPolygon(GLIB_Context_t *pContext,uint32_t numPoints,int32_t *polyPoints);
_Bool GLIB_rectContainsPoint(GLIB_Rectangle_t *pRect,int32_t x,int32_t y);
EMSTATUS GLIB_drawChar(GLIB_Context_t *pContext,char myChar,int32_t x,int32_t y,_Bool opaque);
EMSTATUS GLIB_drawString(GLIB_Context_t *pContext,char *pString,uint32_t sLength,int32_t x0,int32_t y0,_Bool opaque);
EMSTATUS GLIB_setFont(GLIB_Context_t *pContext,GLIB_Font_t *pFont);
int crossProduct(int32_t *points);
void GRAPHICS_Init(void);
EMSTATUS GRAPHICS_Sleep(void);
EMSTATUS GRAPHICS_Wakeup(void);
EMSTATUS GRAPHICS_Update(void);
void GRAPHICS_Clear(void);
void GRAPHICS_AppendString(char *str);
void GRAPHICS_InsertTriangle(uint32_t x,uint32_t y,uint32_t size,_Bool up,int8_t fillPercent);
int rtcIntCallbackRegister(anon_subr_void_void_ptr *pFunction,void *argument,uint frequency);
int responsePrintInternal(StripMode_t stripMode,char *command,char *formatString,va_list args);
_Bool responsePrintHeader(char *command,char *formatString,...);
_Bool responsePrintMulti(char *formatString,...);
_Bool responsePrint(char *command,char *formatString,...);
_Bool responsePrintError(char *command,uint8_t code,char *formatString,...);
void apcConfigure(int param_1);
int PA_OutputPowerGet(void);
void PA_20dbmConfigSet(void);
void PA_0dbmConfigSet(void);
void PA_SubGhz20dbmConfigSet(void);
void PA_PowerModeConfigSet(void);
uint PA_StripesAndSlicesSet(uint param_1);
uint PA_StripesAndSlicesCommonCalc(int param_1,short *param_2);
uint PA_PowerFromStripesAndSlicesCommonCalc(uint param_1,int param_2);
void PA_PowerLevelOptimize(int param_1);
void PA_StripesAndSlicesCalc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
int PA_OutputPowerSet(void);
void PA_PeakDetectorHighRun(void);
void PA_PeakDetectorLowRun(void);
void PA_BatHighRun(void);
uint16_t PA_RampTimeGet(void);
void PA_RampConfigSet(uint *param_1);
int PA_RampTimeCalc(void);
uint16_t PA_RampTimeSet(uint16_t ramptime);
void PA_CTuneSet(uint param_1,uint param_2);
void PA_BandSelect(void);
bool RADIO_PA_Init(RADIO_PAInit_t *paInit);
void RADIO_PTI_Init(byte *param_1);
void RADIO_PTI_Enable(void);
void RADIO_PTI_AuxdataOutput(uint param_1);
void RADIO_BUFCClear(int param_1);
void RADIO_WriteSync(undefined4 *param_1,undefined4 param_2);
void RADIO_OrSync(uint *param_1,uint param_2);
void RADIO_XorSync(uint *param_1,uint param_2);
void RADIO_AndSync(uint *param_1,uint param_2);
void RADIO_BUFCWriteContSync(int param_1,byte *param_2,int param_3);
void RADIO_WaitForSetSync(uint *param_1,uint param_2);
void RADIO_Delay(undefined4 param_1,undefined4 param_2);
void RADIO_ClrBitSync(int param_1,int param_2);
void RADIO_SetBitSync(int param_1,int param_2);
void RADIO_SetAndForgetWrite(undefined4 param_1,uint param_2,undefined4 param_3);
void RADIO_CLKEnable(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
void RADIO_Config(int param_1);
void RADIO_RegisterIrqCallback(int param_1,undefined4 param_2);
void FRC_PRI_IRQHandler(void);
void FRC_IRQHandler(void);
void RAC_RSM_IRQHandler(void);
void RAC_SEQ_IRQHandler(void);
void AGC_IRQHandler(void);
void PROTIMER_IRQHandler(void);
void BUFC_IRQHandler(void);
void MODEM_IRQHandler(void);
void RADIO_TxBufferSet(undefined4 param_1,int param_2,undefined4 param_3,uint param_4);
void RADIO_TxBufferReset(void);
void RADIO_TxAckBufferSet(undefined4 param_1,undefined4 param_2);
void RADIO_TxAckBufferReset(void);
void RADIO_RXBufferEnableThrInt(void);
void RADIO_RXBufferDisableThrInt(void);
void RADIO_RxBufferSet(int param_1);
undefined4 RADIO_RxBufferGet(void);
void RADIO_RxBufferReset(void);
void RADIO_BUFCIrqHandler(void);
int RADIO_RxTrailDataLength(void);
bool RADIO_RxBufferPacketAvailable(void);
uint RADIO_RxBufferBytesAvailable(void);
uint RADIO_TxBufferBytesAvailable(void);
uint RADIO_RxBufferReadByte(void);
void RADIO_FrameControlDescrBufferIdSet(int param_1,int param_2);
void RADIO_Init(void);
void RADIO_FrameControlDescrConfigSet(int param_1,uint param_2,int param_3,int param_4,byte param_5,byte param_6);
void RADIO_FrameDescsConfig(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
void RADIO_BUFCReadContASync(int param_1,undefined *param_2,int param_3);
void RADIO_RxBufferReadBytes(undefined4 param_1,undefined4 param_2);
void RADIO_RxBufferDropBytes(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
void RADIO_RxLengthReadNext(ushort *param_1);
void RADIO_FRCErrorHandle(void);
uint RADIO_UsToStimerTickCalc(uint param_1);
void RADIO_SeqInit(void *param_1,int param_2);
uint RADIO_TxWarmTimeSet(uint param_1);
undefined2 RADIO_TxWarmTimeGet(void);
uint RADIO_RxToTxTimeSet(uint param_1);
uint RADIO_RxFrameToTxTimeSet(uint param_1);
uint RADIO_TxToTxTimeSet(uint param_1);
uint RADIO_TxToRxTimeSet(uint param_1);
short RADIO_RxWarmTimeSet(uint param_1);
undefined2 RADIO_RxWarmTimeGet(void);
uint RADIO_RxSearchTimeSet(uint param_1);
uint RADIO_TxToRxSearchTimeSet(uint param_1);
uint RADIO_ComputeTxBaudrate(void);
uint RADIO_ComputeRxBaudrate(void);
uint32_t RADIO_ComputeTxSymbolRate(void);
uint32_t RADIO_ComputeTxBitRate(void);
int RADIO_GetRSSI(void);
undefined4 RADIO_AGCCCAThresholdSet(byte param_1);
undefined4 RADIO_SetAgcCcaParams(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
undefined4 RADIO_CalcRssiPeriod(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
void RADIO_SetCRCInitVal(uint param_1);
void setupPnForTest(void);
void RFTEST_StartRx(void);
void RFTEST_StopRx(undefined4 param_1,undefined4 param_2,int param_3);
void RFTEST_SaveRadioConfiguration(void);
void RFTEST_RestoreRadioConfiguration(void);
void RFTEST_StartCwTx(void);
void RFTEST_StartStreamTx(void);
void RFTEST_StopTx(void);
void RFTEST_BerStop(void);
void RFTEST_BerEmptyBufcAndUpdateStats(void);
void RFTEST_ResetBerStats(int param_1);
void RFTEST_ReportBerStats(RAIL_BerStatus_t *berstats);
undefined4 SYNTH_RfFreqGet(void);
undefined4 SYNTH_ChSpacingGet(void);
undefined4 SYNTH_IfFreqGet(void);
uint SYNTH_IfFreqCompute(void);
uint SYNTH_LoDivGet(void);
uint SYNTH_Is2p4GHz(void);
bool SYNTH_VcoRangeIsValid(uint param_1);
void SYNTH_RetimeLimitsConfig(uint param_1);
void SYNTH_RetimeClkConfig(void);
void SYNTH_Config(int param_1,uint param_2);
void SYNTH_ChannelSet(uint param_1,int param_2);
void SYNTH_DCDCRetimeEnable(void);
void SYNTH_DCDCRetimeClkSet(int param_1);
void SYNTH_KvnFreqCompensationEnable(void);
void RADIOCMU_ClockEnable(CMU_Clock_TypeDef param_1,undefined4 param_2);
uint RADIOCMU_ClockFreqGet(CMU_Clock_TypeDef param_1);
uint32_t RADIOCMU_ClockPrescGet(CMU_Clock_TypeDef param_1);
uint8_t RAIL_RadioConfig(void *radioConfig);
uint8_t RAIL_ChannelConfig(RAIL_ChannelConfig_t *config);
void RAIL_DirectModeConfig(bool enable);
RAIL_Status_t RAIL_DebugFrequencyOverride(uint32_t freq);
void RAIL_PacketLengthConfigFrameType(RAIL_FrameType_t *frameType);
int16_t RAIL_PollAverageRSSI(uint32_t averageTimeUs);
RAIL_Status_t RAIL_StartAverageRSSI(uint8_t channel,uint32_t averagingTimeUs);
int RAIL_GetAverageRSSI(void);
void RAIL_SetTune(uint32_t tune);
uint32_t RAIL_GetTune(void);
uint32_t RAIL_GetTime(void);
RAIL_Status_t RAIL_SetTime(uint32_t time);
RAIL_Status_t RAIL_SetStateTiming(RAIL_StateTiming_t *timings);
bool RAIL_AddressFilterConfig(RAIL_AddrConfig_t *addrConfig);
bool RAIL_AddressFilterByFrameType(uint8_t validFrames);
bool RAIL_AddressFilterEnable(void);
bool RAIL_AddressFilterDisable(void);
bool RAIL_AddressFilterIsEnabled(void);
void RAIL_AddressFilterReset(void);
bool RAIL_AddressFilterSetAddress(uint8_t field,uint8_t index,uint8_t *value,bool enable);
bool RAIL_AddressFilterEnableAddress(uint8_t field,uint8_t index);
bool RAIL_AddressFilterDisableAddress(uint8_t field,uint8_t index);
uint16_t RAIL_GetRadioEntropy(uint8_t *buffer,uint16_t bytes);
void pktTxDoneEvt(undefined4 param_1,RAIL_TxPacketInfo_t param_2,undefined4 param_3);
void pktRxOverflow(void);
void preambleDetected(void);
void frameDet0(void);
void frameDet1(void);
void RAIL_RFSENSE_Callback(void);
void protmrRetry(void);
void protmrStartCca(void);
void racStateChange(void);
void softwareTimerExpired(void);
void rssiAverageDone(void);
void racCalRequest(void);
void rxTimeout(int param_1);
void sequencerInterrupt(int param_1);
void pktRxDoneEvt(void);
void pktRxFrmErr(void);
void pktRxAborted(void);
void pktTxErrorEvt(uint param_1);
void protmrLbtEvt(int param_1);
uint8_t RFHAL_Init(RAIL_Init_t *railInit);
uint RFHAL_SetPtiProtocol(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4);
void RFHAL_IdleExt(int param_1);
RAIL_RadioState_t RFHAL_StateGet(void);
uint RFHAL_OkToTransmit(void);
bool RFHAL_HeadedToIdle(void);
uint RFHAL_TxDataLoad(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
uint8_t RAIL_CcaCsma(void *params);
uint8_t RAIL_CcaLbt(void *params);
int16_t RFHAL_PollAverageRSSI(uint32_t averageTimeUs);
RAIL_Status_t RFHAL_StartAverageRSSI(uint8_t channel,uint32_t averagingTimeUs);
int RFHAL_GetAverageRSSI(void);
uint8_t RFHAL_ScheduleRx(uint8_t channel,RAIL_ScheduleRxConfig_t *cfg);
RAIL_Status_t RAIL_ScheduleTx(RAIL_ScheduleTxConfig_t *params);
uint8_t RFHAL_RxStart(void);
uint8_t RFHAL_RxIntEnable(uint32_t cbToEnable,bool appendedInfoEnable);
undefined4 RFHAL_TxIntEnable(uint param_1);
undefined4 RFHAL_ErrorConfig(uint param_1);
RAIL_Status_t RAIL_PaCtuneSet(uint8_t txPaCtuneValue,uint8_t rxPaCtuneValue);
void RAIL_TimerGet(void);
void RAIL_TimerCancel(void);
byte RAIL_TimerSet(uint32_t param_1,int param_2);
byte RAIL_TimerExpired(void);
void RAIL_TimerIsRunning(void);
uint32_t RAIL_SymbolRateGet(void);
uint32_t RAIL_BitRateGet(void);
uint32_t RAIL_RfSense(RAIL_RfSenseBand_t band,uint32_t senseTime,bool enableCb);
bool RAIL_RfSensed(void);
void RFHAL_CalibrationRun(int *param_1,int param_2);
RAIL_Status_t RFHAL_SetTxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error);
RAIL_Status_t RFHAL_SetRxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error);
void RFHAL_SetBerConfig(RAIL_BerConfig_t *berconfig);
void RFHAL_StartBerRx(void);
void RFHAL_StopBerRx(void);
void RFHAL_GetBerStatus(RAIL_BerStatus_t *berstatus);
void RFHAL_SetCRCInitVal(uint param_1);
int RFHAL_GetCurrPowerLevel(void);
undefined4 RFHAL_SetCurrPowerLevel(void);
void RFHAL_SetProtocolSpecificChCheckCB(undefined4 param_1);
void RFHAL_StopTestMode(void);
void RFHAL_StartCWTestMode(void);
void RFHAL_StartStreamTestMode(void);
undefined4 RFHAL_SetChannel(int param_1,byte *param_2,int param_3);
uint RFHAL_AutoAckEnable(void);
uint RFHAL_AutoAckDisable(void);
bool RFHAL_AutoAckIsEnabled(void);
undefined4 RFHAL_AutoAckConfig(int param_1);
uint RFHAL_AutoAckLoadBuffer(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
void RFHAL_AutoAckRxPause(void);
void RFHAL_AutoAckRxResume(void);
void RFHAL_AutoAckTxPause(void);
void RFHAL_AutoAckTxResume(void);
bool RFHAL_AutoAckRxIsPaused(void);
bool RFHAL_AutoAckTxIsPaused(void);
bool RFHAL_AutoAckUseTxBuffer(void);
bool RFHAL_AutoAckCancelAck(void);
void RFHAL_AutoAckWaitForAck(uint param_1);
code * RFHAL_TxStart(undefined4 param_1,undefined *param_2,code *param_3,undefined4 param_4);
uint8_t RAIL_RfInit(RAIL_Init_t *railInit);
RAIL_Status_t RAIL_SetPtiProtocol(RAIL_PtiProtocol_t protocol);
void RAIL_RfIdle(void);
void RAIL_RfIdleExt(undefined4 mode,bool wait);
RAIL_RadioState_t RAIL_RfStateGet(void);
bool RAIL_ChannelExists(uint16_t channel);
void RAILInt_TrackChannelConfig(RAIL_ChannelConfig_t *param_1);
uint8_t RAILInt_SetChannel(uint8_t channel);
undefined RAILInt_GetChannel(void);
void RAIL_VersionGet(RAIL_Version_t *version,bool verbose);
RAIL_Status_t RAIL_DebugModeSet(uint32_t DebugMode);
uint32_t RAIL_DebugModeGet(void);
RAIL_Status_t RAIL_SetTxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error);
RAIL_Status_t RAIL_SetRxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error,uint8_t ignoreerrors);
uint8_t RAIL_RxConfig(uint32_t cbToEnable,bool appendedInfoEnable);
uint8_t RAIL_RxStart(uint8_t channel);
uint8_t RAIL_ScheduleRx(uint8_t channel,RAIL_ScheduleRxConfig_t *cfg);
undefined4 RAIL_TxConfig(uint param_1);
uint RAIL_TxDataLoad(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
uint RAIL_TxStartWithOptions(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
void RAIL_TxStart(undefined4 param_1,undefined4 param_2,undefined4 param_3);
uint8_t RAIL_TxToneStart(uint8_t param_1);
undefined4 RAIL_TxToneStop(void);
uint8_t RAIL_TxStreamStart(uint8_t param_1,int param_2);
undefined4 RAIL_TxStreamStop(void);
undefined4 RAIL_TxPowerSet(void);
int RAIL_TxPowerGet(void);
void RFHAL_CalibrationInit(RAIL_CalMask_t calEnable);
void RFHAL_CalibrationPend(RAIL_CalMask_t calpend);
uint RFHAL_CalibrationClear(uint param_1);
undefined4 RFHAL_CalibrationEnableGet(void);
RAIL_CalMask_t RFHAL_CalibrationPendingGet(void);
RAIL_CalMask_t RAIL_CalPendingGet(void);
void RAIL_CalStart(undefined4 *calValues,RAIL_CalMask_t calForce,bool calSave);
uint8_t RAIL_CalInit(RAIL_CalInit_t *railCalInit);
RAIL_Status_t RAIL_AutoAckDisable(void);
bool RAIL_AutoAckIsEnabled(void);
RAIL_Status_t RAIL_AutoAckConfig(RAIL_AutoAckConfig_t *config);
RAIL_Status_t RAIL_AutoAckLoadBuffer(RAIL_AutoAckData_t *ackData);
void RAIL_AutoAckRxPause(void);
void RAIL_AutoAckRxResume(void);
bool RAIL_AutoAckRxIsPaused(void);
void RAIL_AutoAckTxPause(void);
void RAIL_AutoAckTxResume(void);
bool RAIL_AutoAckTxIsPaused(void);
bool RAIL_AutoAckUseTxBuffer(void);
bool RAIL_AutoAckCancelAck(void);
void RAIL_BerRxStop(void);
void RAIL_BerConfigSet(RAIL_BerConfig_t *berConfig);
void RAIL_BerRxStart(void);
void RAIL_BerStatusGet(RAIL_BerStatus_t *berstatus);
RAIL_Status_t RAIL_IEEE802154_2p4GHzRadioConfig(void);
bool RAIL_IEEE802154_SetAddresses(RAIL_IEEE802154_AddrConfig_t *addresses);
bool RAIL_IEEE802154_SetPanId(uint16_t panId);
bool RAIL_IEEE802154_SetShortAddress(uint16_t shortAddr);
void RAIL_IEEE802154_SetLongAddress(undefined4 param_1);
RAIL_Status_t RAIL_IEEE802154_SetPanCoordinator(bool isPanCoordinator);
RAIL_Status_t RAIL_IEEE802154_SetPromiscuousMode(bool enable);
RAIL_Status_t RAIL_IEEE802154_AcceptFrames(uint8_t framesMask);
RAIL_Status_t RAIL_IEEE802154_Init(RAIL_IEEE802154_Config_t *config);
RAIL_Status_t RAIL_IEEE802154_SetFramePending(void);
RAIL_Status_t RAIL_BLE_Init(void);
uint RAIL_BLE_Deinit(uint param_1);
bool RAIL_BLE_IsEnabled(void);
bool RAIL_BLE_SetPhy1MbpsViterbi(void);
bool RAIL_BLE_SetPhy1Mbps(void);
bool RAIL_BLE_SetPhy2MbpsViterbi(void);
bool RAIL_BLE_SetPhy2Mbps(void);
bool RAIL_BLE_SetupChannelRadioParams(uint32_t crcInit,uint32_t accessAddress,uint8_t channel,bool disableWhitening);
undefined4 IRCAL_Configure(undefined4 param_1);
undefined IRCAL_GetGlobalCalType(void);
void IRCAL_Set(uint param_1);
undefined4 IRCAL_Init(byte *param_1);
void IRCAL_SaveRegStates(void);
undefined4 IRCAL_SetRxFrequency(int param_1);
void IRCAL_StartRx(void);
void IRCAL_StopRx(undefined4 param_1,undefined4 param_2,int param_3);
void IRCAL_SetSubGhzPllLoopback(void);
void IRCAL_SetSubGhzPaLoopback(void);
undefined4 IRCAL_Setup(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
int IRCAL_ReadRssi(uint param_1,uint param_2,uint param_3,undefined4 param_4,undefined2 param_5);
uint IRCAL_SearchLinear2Stage(uint param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined2 param_5);
uint IRCAL_Search(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
void IRCAL_Teardown(void);
uint IRCAL_GetDiValue(void);
uint IRCAL_PerformSubfunction(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined2 param_5);
undefined4 IRCAL_Perform(undefined4 param_1,undefined4 param_2,undefined4 param_3);
void PROTIMER_Init(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
void PROTIMER_Start(void);
void PROTIMER_Stop(void);
uint PROTIMER_IsRunning(void);
void PROTIMER_Reset(void);
int PROTIMER_ElapsedTime(uint param_1,uint param_2);
void PROTIMER_CCTimerStop(uint param_1);
undefined4 PROTIMER_CCTimerStart(uint param_1,uint param_2,int param_3);
uint PROTIMER_CCTimerIsEnabled(int param_1);
void PROTIMER_CCTimerCapture(int param_1,uint param_2);
bool PROTIMER_ScheduleTxEnable(void);
void PROTIMER_ClearTxEnable(void);
void PROTIMER_ScheduleRxEnable(int param_1,uint param_2,int param_3);
void PROTIMER_ScheduleRxDisable(int param_1,undefined4 param_2,undefined4 param_3);
void PROTIMER_ClearRxEnable(void);
uint PROTIMER_GetTime(void);
bool PROTIMER_SetTime(uint32_t time);
uint PROTIMER_GetCCTime(int param_1);
void PROTIMER_LBTCfgSet(uint param_1,int param_2,uint param_3,int param_4,byte param_5);
void PROTIMER_LBTUseLastConfig(void);
void PROTIMER_LBTStart(void);
void PROTIMER_LBTStop(void);
bool PROTIMER_LBTIsActive(void);
uint32_t PROTIMER_PrecntOverflowToUs(uint32_t cnt);
uint32_t PROTIMER_UsToPrecntOverflow(uint32_t us);
void PROTIMER_DelayUs(uint param_1);
void PHY_UTILS_DelayUs(undefined4 param_1);
void RFSENSE_Disable(void);
int RFSENSE_CalcPeriod(uint param_1,uint param_2,char *param_3,undefined4 param_4);
void RFSENSE_ReInit(void);
bool RFSENSE_Sensed(void);
bool RFSENSE_IRQHandler(void);
void RFSENSE_DeInit(void);
uint RFSENSE_Init(undefined4 *param_1,uint param_2);
void TEMPCAL_Init(void);
void TEMPCAL_Perform(void);
uint16_t RFRAND_GetRadioEntropy(uint8_t *buffer,uint16_t bytes);
undefined4 RFRAND_SeedProtimerRandom(undefined4 param_1,uint param_2,undefined4 param_3);
void GENERIC_PHY_RAC_IRQCallback(void);
void GENERIC_PHY_MODEM_IRQCallback(void);
void GENERIC_PHY_AGC_IRQCallback(void);
void RADIO_RACRxAbort(undefined4 param_1,undefined4 param_2,int param_3);
void GENERIC_PHY_PROTIMER_IRQCallback(void);
void GENERIC_PHY_SetAddressFilteringMatchTable(void);
void GENERIC_PHY_ConfigureCallbacks(uint param_1);
void GENERIC_PHY_SetCallbacks(int param_1);
void GENERIC_PHY_FlushTxPacketBuffer(void);
void GENERIC_PHY_PacketTxCommon(void);
undefined4 GENERIC_PHY_PacketTx(void);
undefined4 GENERIC_PHY_SchedulePacketRx(undefined4 param_1,int param_2,int param_3,int param_4,char param_5,undefined param_6);
RAIL_Status_t GENERIC_PHY_SchedulePacketTx(uint32_t when,RAIL_TimeMode_t mode);
uint GENERIC_PHY_PacketRxDataHelper(int param_1,uint param_2);
uint GENERIC_PHY_PacketRxAppendedInfoHelper(uint param_1,void *param_2,undefined4 param_3,undefined4 param_4);
void GENERIC_PHY_StartRx(int param_1);
void GENERIC_PHY_ChannelSet(undefined4 param_1);
void GENERIC_PHY_SeqAtomicLock(void);
void GENERIC_PHY_RadioIdle(int param_1,int param_2);
void GENERIC_PHY_FRC_IRQCallback(void);
void GENERIC_PHY_PreviousTxTime(void);
void GENERIC_PHY_RACConfig(void);
void GENERIC_PHY_DirectModeConfig(byte *param_1);
void GENERIC_PHY_ResetPacketConfig(void);
void GENERIC_PHY_ConfigureFrameType(RAIL_FrameType_t *frameType);
bool GENERIC_PHY_EnableAddressFiltering(void);
bool GENERIC_PHY_DisableAddressFiltering(void);
bool GENERIC_PHY_IsEnabledAddressFiltering(void);
void GENERIC_PHY_ResetAddressFiltering(void);
void GENERIC_PHY_Init(void);
undefined4 GENERIC_PHY_ConfigureAddressFiltering(undefined *param_1);
bool GENERIC_PHY_EnableAddress(uint8_t field,uint8_t index);
bool GENERIC_PHY_DisableAddress(uint8_t field,uint8_t index);
undefined4 GENERIC_PHY_SetAddressData(uint param_1,uint param_2,uint param_3,uint param_4,byte param_5,byte *param_6);
int GENERIC_PHY_SetIeeePanId(uint param_1,undefined4 param_2);
int GENERIC_PHY_SetIeeeShortAddress(uint param_1,undefined4 param_2);
int GENERIC_PHY_SetIeeeLongAddress(uint param_1,undefined4 param_2);
bool GENERIC_PHY_SetAddress(uint8_t field,uint8_t index,uint8_t *value,bool enable);
uint GENERIC_PHY_EnableIEEE802154(void);
uint GENERIC_PHY_IsEnabledIEEE802154(void);
void GENERIC_PHY_TimerStart(undefined4 param_1,undefined4 param_2);
void GENERIC_PHY_TimerStop(void);
void GENERIC_PHY_TimerGetTimeout(void);
uint GENERIC_PHY_TimerExpired(void);
void GENERIC_PHY_TimerIsRunning(void);
bool GENERIC_PHY_CanModifyAck(void);
uint RFHAL_802154SetPhyforChan(uint param_1);
uint RFHAL_IEEE802154Enable(void);
uint RFHAL_IEEE802154IsEnabled(void);
undefined4 RFHAL_IEEE802154RadioConfig2p4GHz(void);
byte RFHAL_IEEE802154SetBroadcastAddresses(undefined4 param_1,undefined4 param_2,undefined4 param_3);
bool RFHAL_IEEE802154SetPanId(uint16_t panId);
bool RFHAL_IEEE802154SetShortAddress(uint16_t shortAddr);
void RFHAL_IEEE802154SetLongAddress(undefined4 param_1);
undefined4 RFHAL_IEEE802154SetPromiscuousMode(int param_1);
undefined4 RFHAL_IEEE802154SetPanCoordinator(int param_1);
undefined4 RFHAL_IEEE802154AcceptFrames(int param_1);
RAIL_Status_t RFHAL_IEEE802154SetFramePending(void);
RAIL_Status_t RFHAL_IEEE802154LoadAck(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
void RFHAL_BLESetPhyforChan(int param_1,int param_2);
undefined4 RFHAL_Ble2MbpsSet(void);
undefined4 RFHAL_Ble1MbpsSet(void);
void RFHAL_BleInit(void);
void RFHAL_BleDeinit(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
void RFHAL_BLEPreambleSyncWordSet(int param_1,uint param_2);
void RFHAL_BLEWhiteningSet(uint param_1,uint param_2,int param_3);
void AUXPLL_AuxSettingsPllLoopback(void);
void AUXPLL_AuxSettingsPaLoopback(void);
void AUXPLL_Stop(void);
undefined AUXPLL_ConvertAuxLoDivToRegVal(int param_1);
void AUXPLL_Configure(uint param_1,undefined4 param_2,int param_3,int param_4);
int AUXPLL_Start(int param_1,undefined4 param_2,int param_3,uint param_4);
void __aeabi_drsub(undefined4 param_1,uint param_2);
ulonglong __subdf3(uint param_1,uint param_2,uint param_3,uint param_4);
ulonglong __aeabi_dadd(uint param_1,uint param_2,uint param_3,uint param_4);
ulonglong __floatunsidf(uint param_1);
ulonglong __aeabi_i2d(uint param_1);
ulonglong __aeabi_f2d(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4);
ulonglong __floatundidf(uint param_1,uint param_2);
ulonglong __aeabi_l2d(uint param_1,uint param_2);
ulonglong __muldf3(undefined4 param_1,uint param_2,uint param_3,uint param_4);
ulonglong FUN_0000cc78(uint param_1,uint param_2,uint param_3,uint param_4);
ulonglong __divdf3(undefined4 param_1,uint param_2,uint param_3,uint param_4);
ulonglong FUN_0000ce5e(uint param_1,uint param_2,uint param_3,uint param_4);
uint __truncdfsf2(uint param_1,uint param_2);
int __aeabi_ldivmod(int param_1,int param_2,int param_3,int param_4);
void __aeabi_uldivmod(int param_1,int param_2,int param_3,int param_4);
undefined8 __udivmoddi4(uint param_1,uint param_2,uint param_3,uint param_4,uint *param_5);
void __aeabi_idiv0(void);
undefined * __errno(void);
void exit(int __status);
int fileno(FILE *__stream);
void std(undefined4 *param_1,undefined2 param_2,undefined2 param_3);
void _cleanup_r(undefined4 param_1);
undefined4 * __sfmoreglue(undefined4 param_1,int param_2);
void __sinit(undefined4 *param_1);
int * __sfp(undefined4 *param_1);
uint _fwalk(int param_1,code *param_2);
uint _fwalk_reent(int param_1,code *param_2,undefined4 param_3,undefined4 param_4);
int getchar(void);
void __libc_init_array(EVP_PKEY_CTX *param_1);
int memcmp(void *__s1,void *__s2,size_t __n);
void * memcpy(void *__dest,void *__src,size_t __n);
void * memmove(void *__dest,void *__src,size_t __n);
void * memset(void *__s,int __c,size_t __n);
uint _malloc_r(undefined4 *param_1,uint param_2);
char * __cvt(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,int param_6,undefined *param_7,int *param_8,uint param_9,int *param_10);
int __exponent(undefined *param_1,uint param_2,undefined4 param_3);
uint _printf_float(undefined4 param_1,uint *param_2,undefined4 param_3,code *param_4,uint **param_5);
undefined4 _printf_common(undefined4 param_1,uint *param_2,uint *param_3,undefined4 param_4,code *param_5);
uint _printf_i(undefined4 param_1,uint *param_2,undefined4 param_3,code *param_4,uint **param_5);
int iprintf(char *__format,...);
int putchar(int __c);
undefined4 _puts_r(int param_1,int param_2);
int puts(char *__s);
void _sbrk_r(int *param_1,int param_2);
int setvbuf(FILE *__stream,char *__buf,int __modes,size_t __n);
int sniprintf(char *__s,size_t __maxlen,char *__format,...);
int siprintf(char *__s,char *__format,...);
void __sread(undefined4 param_1,int param_2);
void __swrite(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4);
void __sseek(undefined4 param_1,int param_2);
void __sclose(undefined4 param_1,int param_2);
int strcasecmp(char *__s1,char *__s2);
char * strchr(char *__s,int __c);
int strcmp(char *__s1,char *__s2);
char * strcpy(char *__dest,char *__src);
size_t strlen(char *__s);
char * __strtok_r(char *__s,char *__delim,char **__save_ptr);
char * strtok_r(char *__s,char *__delim,char **__save_ptr);
uint _strtol_l.isra.0(undefined4 *param_1,byte *param_2,byte **param_3,uint param_4,undefined4 param_5);
long strtol(char *__nptr,char **__endptr,int __base);
uint _strtoul_l.isra.0(undefined4 *param_1,byte *param_2,byte **param_3,uint param_4,undefined4 param_5);
ulong strtoul(char *__nptr,char **__endptr,int __base);
int viprintf(char *__format,__gnuc_va_list __arg);
uint __swbuf_r(int param_1,uint param_2,int *param_3,undefined4 param_4);
void _write_r(int *param_1,int param_2,char *param_3,int param_4);
undefined4 __swsetup_r(undefined4 *param_1,undefined4 *param_2);
void _close_r(int *param_1,int param_2);
uint quorem(int param_1,int param_2);
char * _dtoa_r(int param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5,uint param_6,int *param_7,undefined4 *param_8,char **param_9);
undefined4 __sflush_r(uint *param_1,int *param_2);
undefined4 _fflush_r(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4);
int fflush(FILE *__stream);
uint _getc_r(int param_1,byte **param_2);
undefined4 __locale_ctype_ptr_l(int param_1);
undefined4 __locale_ctype_ptr(void);
undefined1 * _localeconv_r(void);
void _lseek_r(int *param_1,int param_2,int param_3,int param_4);
undefined4 __swhatbuf_r(undefined4 param_1,int param_2,undefined4 *param_3,uint *param_4);
void __smakebuf_r(int param_1,int *param_2);
void * malloc(size_t __size);
code * __ascii_mbtowc(undefined4 param_1,uint *param_2,code *param_3,int param_4);
void * memchr(void *__s,int __c,size_t __n);
void __malloc_lock(void);
void __malloc_unlock(void);
undefined4 * _Balloc(int param_1,uint param_2);
void _Bfree(int param_1,undefined4 *param_2);
int __multadd(undefined4 param_1,int param_2,int param_3,uint param_4);
int __hi0bits(uint param_1);
uint __lo0bits(uint *param_1);
void __i2b(undefined4 param_1,undefined4 param_2);
void __multiply(undefined4 param_1,int param_2,int param_3);
undefined4 __pow5mult(int param_1,undefined4 param_2,uint param_3,undefined4 param_4);
int __lshift(undefined4 param_1,int param_2,uint param_3);
int __mcmp(int param_1,int param_2);
void __mdiff(undefined4 param_1,int param_2,int param_3,int param_4);
int __d2b(uint param_1,uint param_2,uint param_3,uint param_4,int *param_5,int *param_6);
void * _calloc_r(undefined4 param_1,int param_2,int param_3,undefined4 param_4);
void _free_r(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4);
undefined4 __ssputs_r(undefined4 *param_1,void **param_2,void *param_3,void *param_4);
int _svfiprintf_r(undefined4 *param_1,int *param_2,byte *param_3,int *param_4);
int __sfputc_r(undefined4 param_1,int param_2,undefined4 *param_3);
int __sfputs_r(undefined4 param_1,undefined4 param_2,undefined *param_3,int param_4);
int _vfprintf_r(int param_1,undefined4 *param_2,byte *param_3,int *param_4);
uint _putc_r(int param_1,uint param_2,undefined4 *param_3);
void _read_r(int *param_1,int param_2,char *param_3,int param_4);
uint __srget_r(int param_1,byte **param_2);
undefined4 __ascii_wctomb(undefined4 *param_1,undefined *param_2,uint param_3);
void _fstat_r(int *param_1,int param_2,stat *param_3);
void _isatty_r(int *param_1,int param_2);
void * _realloc_r(undefined4 param_1,void *param_2,void *param_3,undefined4 param_4);
int lflush(FILE *param_1);
undefined4 __srefill_r(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4);
int _malloc_usable_size_r(undefined4 param_1,int param_2);
uint __gedf2(uint param_1,uint param_2,uint param_3,uint param_4);
uint __ledf2(uint param_1,uint param_2,uint param_3,uint param_4);
uint __nedf2(uint param_1,uint param_2,uint param_3,uint param_4);
void __aeabi_cdrcmple(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
undefined4 __aeabi_cdcmpeq(undefined4 param_1);
bool __aeabi_dcmpeq(void);
bool __aeabi_dcmplt(void);
bool __aeabi_dcmple(void);
bool __aeabi_dcmpge(void);
bool __aeabi_dcmpgt(void);
undefined4 __unorddf2(uint param_1,int param_2,uint param_3,int param_4);
uint __aeabi_d2iz(uint param_1,uint param_2);
int _init(EVP_PKEY_CTX *ctx);
void _fini(void);

