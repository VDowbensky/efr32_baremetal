/***************************************************************************//**
 * @file
 * @brief EFR32FG1V_CRC register and bit field definitions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/

#if defined(__ICCARM__)
#pragma system_include       /* Treat file as system include file. */
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang system_header  /* Treat file as system include file. */
#endif

/***************************************************************************//**
 * @addtogroup Parts
 * @{
 ******************************************************************************/
/***************************************************************************//**
 * @defgroup EFR32FG1V_BUFC
 * @{
 * @brief EFR32FG1V_BUFC Register Declaration
 ******************************************************************************/
/* =========================================================================================================================== */
/* ================                                           BUFC                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Buffer controller (BUFC)
  */

typedef struct {                                /*!< (@ 0x40081000) BUFC Structure                                             */
  __IOM uint32_t  BUF0_CTRL;                    /*!< (@ 0x00000000) BUF0_CTRL                                                  */
  __IOM uint32_t  BUF0_ADDR;                    /*!< (@ 0x00000004) BUF0_ADDR                                                  */
  __IOM uint32_t  BUF0_WRITEOFFSET;             /*!< (@ 0x00000008) BUF0_WRITEOFFSET                                           */
  __IOM uint32_t  BUF0_READOFFSET;              /*!< (@ 0x0000000C) BUF0_READOFFSET                                            */
  __IOM uint32_t  BUF0_WRITESTART;              /*!< (@ 0x00000010) BUF0_WRITESTART                                            */
  __IOM uint32_t  BUF0_READDATA;                /*!< (@ 0x00000014) BUF0_READDATA                                              */
  __IOM uint32_t  BUF0_WRITEDATA;               /*!< (@ 0x00000018) BUF0_WRITEDATA                                             */
  __IOM uint32_t  BUF0_XWRITE;                  /*!< (@ 0x0000001C) BUF0_XWRITE                                                */
  __IOM uint32_t  BUF0_STATUS;                  /*!< (@ 0x00000020) BUF0_STATUS                                                */
  __IOM uint32_t  BUF0_THRESHOLDCTRL;           /*!< (@ 0x00000024) BUF0_THRESHOLDCTRL                                         */
  __IOM uint32_t  BUF0_CMD;                     /*!< (@ 0x00000028) BUF0_CMD                                                   */
  __IM  uint32_t  RESERVED;
  __IOM uint32_t  BUF1_CTRL;                    /*!< (@ 0x00000030) BUF1_CTRL                                                  */
  __IOM uint32_t  BUF1_ADDR;                    /*!< (@ 0x00000034) BUF1_ADDR                                                  */
  __IOM uint32_t  BUF1_WRITEOFFSET;             /*!< (@ 0x00000038) BUF1_WRITEOFFSET                                           */
  __IOM uint32_t  BUF1_READOFFSET;              /*!< (@ 0x0000003C) BUF1_READOFFSET                                            */
  __IOM uint32_t  BUF1_WRITESTART;              /*!< (@ 0x00000040) BUF1_WRITESTART                                            */
  __IOM uint32_t  BUF1_READDATA;                /*!< (@ 0x00000044) BUF1_READDATA                                              */
  __IOM uint32_t  BUF1_WRITEDATA;               /*!< (@ 0x00000048) BUF1_WRITEDATA                                             */
  __IOM uint32_t  BUF1_XWRITE;                  /*!< (@ 0x0000004C) BUF1_XWRITE                                                */
  __IOM uint32_t  BUF1_STATUS;                  /*!< (@ 0x00000050) BUF1_STATUS                                                */
  __IOM uint32_t  BUF1_THRESHOLDCTRL;           /*!< (@ 0x00000054) BUF1_THRESHOLDCTRL                                         */
  __IOM uint32_t  BUF1_CMD;                     /*!< (@ 0x00000058) BUF1_CMD                                                   */
  __IM  uint32_t  RESERVED1;
  __IOM uint32_t  BUF2_CTRL;                    /*!< (@ 0x00000060) BUF2_CTRL                                                  */
  __IOM uint32_t  BUF2_ADDR;                    /*!< (@ 0x00000064) BUF2_ADDR                                                  */
  __IOM uint32_t  BUF2_WRITEOFFSET;             /*!< (@ 0x00000068) BUF2_WRITEOFFSET                                           */
  __IOM uint32_t  BUF2_READOFFSET;              /*!< (@ 0x0000006C) BUF2_READOFFSET                                            */
  __IOM uint32_t  BUF2_WRITESTART;              /*!< (@ 0x00000070) BUF2_WRITESTART                                            */
  __IOM uint32_t  BUF2_READDATA;                /*!< (@ 0x00000074) BUF2_READDATA                                              */
  __IOM uint32_t  BUF2_WRITEDATA;               /*!< (@ 0x00000078) BUF2_WRITEDATA                                             */
  __IOM uint32_t  BUF2_XWRITE;                  /*!< (@ 0x0000007C) BUF2_XWRITE                                                */
  __IOM uint32_t  BUF2_STATUS;                  /*!< (@ 0x00000080) BUF2_STATUS                                                */
  __IOM uint32_t  BUF2_THRESHOLDCTR;            /*!< (@ 0x00000084) BUF2_THRESHOLDCTR                                          */
  __IOM uint32_t  BUF2_CMD;                     /*!< (@ 0x00000088) BUF2_CMD                                                   */
  __IM  uint32_t  RESERVED2;
  __IOM uint32_t  BUF3_CTRL;                    /*!< (@ 0x00000090) BUF3_CTRL                                                  */
  __IOM uint32_t  BUF3_ADDR;                    /*!< (@ 0x00000094) BUF3_ADDR                                                  */
  __IOM uint32_t  BUF3_WRITEOFFSET;             /*!< (@ 0x00000098) BUF3_WRITEOFFSET                                           */
  __IOM uint32_t  BUF3_READOFFSET;              /*!< (@ 0x0000009C) BUF3_READOFFSET                                            */
  __IOM uint32_t  BUF3_WRITESTART;              /*!< (@ 0x000000A0) BUF3_WRITESTART                                            */
  __IOM uint32_t  BUF3_READDATA;                /*!< (@ 0x000000A4) BUF3_READDATA                                              */
  __IOM uint32_t  BUF3_WRITEDATA;               /*!< (@ 0x000000A8) BUF3_WRITEDATA                                             */
  __IOM uint32_t  BUF3_XWRITE;                  /*!< (@ 0x000000AC) BUF3_XWRITE                                                */
  __IOM uint32_t  BUF3_STATUS;                  /*!< (@ 0x000000B0) BUF3_STATUS                                                */
  __IOM uint32_t  BUF3_THRESHOLDCTRL;           /*!< (@ 0x000000B4) BUF3_THRESHOLDCTRL                                         */
  __IOM uint32_t  BUF3_CMD;                     /*!< (@ 0x000000B8) BUF3_CMD                                                   */
  __IM  uint32_t  RESERVED3[9];
  __IOM uint32_t  IF;                           /*!< (@ 0x000000E0) IF                                                         */
  __IOM uint32_t  IFS;                          /*!< (@ 0x000000E4) IFS                                                        */
  __IOM uint32_t  IFC;                          /*!< (@ 0x000000E8) IFC                                                        */
  __IOM uint32_t  IEN;                          /*!< (@ 0x000000EC) IEN                                                        */
} BUFC_Typedef;                                    /*!< Size = 240 (0xf0)                                                         */


/***************************************************************************//**
 * @addtogroup EFR32FG1V_BUFC
 * @{
 * @defgroup EFR32FG1V_BUFC BitFields  BUFC Bit Fields
 * @{
 ******************************************************************************/
/* =========================================================================================================================== */
/* ================                                           BUFC                                            ================ */
/* =========================================================================================================================== */

/* =======================================================  BUF0_CTRL  ======================================================= */
#define BUFC_BUF0_CTRL_F00_Pos            (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF0_CTRL_F00_Msk            (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* =======================================================  BUF0_ADDR  ======================================================= */
#define BUFC_BUF0_ADDR_F00_Pos            (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF0_ADDR_F00_Msk            (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ===================================================  BUF0_WRITEOFFSET  ==================================================== */
#define BUFC_BUF0_WRITEOFFSET_F00_Pos     (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF0_WRITEOFFSET_F00_Msk     (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ====================================================  BUF0_READOFFSET  ==================================================== */
#define BUFC_BUF0_READOFFSET_F00_Pos      (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF0_READOFFSET_F00_Msk      (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ====================================================  BUF0_WRITESTART  ==================================================== */
#define BUFC_BUF0_WRITESTART_F00_Pos      (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF0_WRITESTART_F00_Msk      (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* =====================================================  BUF0_READDATA  ===================================================== */
#define BUFC_BUF0_READDATA_F00_Pos        (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF0_READDATA_F00_Msk        (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ====================================================  BUF0_WRITEDATA  ===================================================== */
#define BUFC_BUF0_WRITEDATA_F00_Pos       (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF0_WRITEDATA_F00_Msk       (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ======================================================  BUF0_XWRITE  ====================================================== */
#define BUFC_BUF0_XWRITE_F00_Pos          (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF0_XWRITE_F00_Msk          (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ======================================================  BUF0_STATUS  ====================================================== */
#define BUFC_BUF0_STATUS_F00_Pos          (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF0_STATUS_F00_Msk          (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ==================================================  BUF0_THRESHOLDCTRL  =================================================== */
#define BUFC_BUF0_THRESHOLDCTRL_F00_Pos   (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF0_THRESHOLDCTRL_F00_Msk   (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* =======================================================  BUF0_CMD  ======================================================== */
#define BUFC_BUF0_CMD_F00_Pos             (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF0_CMD_F00_Msk             (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* =======================================================  BUF1_CTRL  ======================================================= */
#define BUFC_BUF1_CTRL_F00_Pos            (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF1_CTRL_F00_Msk            (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* =======================================================  BUF1_ADDR  ======================================================= */
#define BUFC_BUF1_ADDR_F00_Pos            (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF1_ADDR_F00_Msk            (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ===================================================  BUF1_WRITEOFFSET  ==================================================== */
#define BUFC_BUF1_WRITEOFFSET_F00_Pos     (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF1_WRITEOFFSET_F00_Msk     (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ====================================================  BUF1_READOFFSET  ==================================================== */
#define BUFC_BUF1_READOFFSET_F00_Pos      (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF1_READOFFSET_F00_Msk      (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ====================================================  BUF1_WRITESTART  ==================================================== */
#define BUFC_BUF1_WRITESTART_F00_Pos      (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF1_WRITESTART_F00_Msk      (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* =====================================================  BUF1_READDATA  ===================================================== */
#define BUFC_BUF1_READDATA_F00_Pos        (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF1_READDATA_F00_Msk        (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ====================================================  BUF1_WRITEDATA  ===================================================== */
#define BUFC_BUF1_WRITEDATA_F00_Pos       (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF1_WRITEDATA_F00_Msk       (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ======================================================  BUF1_XWRITE  ====================================================== */
#define BUFC_BUF1_XWRITE_F00_Pos          (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF1_XWRITE_F00_Msk          (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ======================================================  BUF1_STATUS  ====================================================== */
#define BUFC_BUF1_STATUS_F00_Pos          (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF1_STATUS_F00_Msk          (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ==================================================  BUF1_THRESHOLDCTRL  =================================================== */
#define BUFC_BUF1_THRESHOLDCTRL_F00_Pos   (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF1_THRESHOLDCTRL_F00_Msk   (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* =======================================================  BUF1_CMD  ======================================================== */
#define BUFC_BUF1_CMD_F00_Pos             (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF1_CMD_F00_Msk             (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* =======================================================  BUF2_CTRL  ======================================================= */
#define BUFC_BUF2_CTRL_F00_Pos            (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF2_CTRL_F00_Msk            (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* =======================================================  BUF2_ADDR  ======================================================= */
#define BUFC_BUF2_ADDR_F00_Pos            (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF2_ADDR_F00_Msk            (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ===================================================  BUF2_WRITEOFFSET  ==================================================== */
#define BUFC_BUF2_WRITEOFFSET_F00_Pos     (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF2_WRITEOFFSET_F00_Msk     (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ====================================================  BUF2_READOFFSET  ==================================================== */
#define BUFC_BUF2_READOFFSET_F00_Pos      (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF2_READOFFSET_F00_Msk      (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ====================================================  BUF2_WRITESTART  ==================================================== */
#define BUFC_BUF2_WRITESTART_F00_Pos      (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF2_WRITESTART_F00_Msk      (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* =====================================================  BUF2_READDATA  ===================================================== */
#define BUFC_BUF2_READDATA_F00_Pos        (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF2_READDATA_F00_Msk        (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ====================================================  BUF2_WRITEDATA  ===================================================== */
#define BUFC_BUF2_WRITEDATA_F00_Pos       (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF2_WRITEDATA_F00_Msk       (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ======================================================  BUF2_XWRITE  ====================================================== */
#define BUFC_BUF2_XWRITE_F00_Pos          (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF2_XWRITE_F00_Msk          (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ======================================================  BUF2_STATUS  ====================================================== */
#define BUFC_BUF2_STATUS_F00_Pos          (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF2_STATUS_F00_Msk          (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ===================================================  BUF2_THRESHOLDCTR  =================================================== */
#define BUFC_BUF2_THRESHOLDCTR_F00_Pos    (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF2_THRESHOLDCTR_F00_Msk    (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* =======================================================  BUF2_CMD  ======================================================== */
#define BUFC_BUF2_CMD_F00_Pos             (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF2_CMD_F00_Msk             (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* =======================================================  BUF3_CTRL  ======================================================= */
#define BUFC_BUF3_CTRL_F00_Pos            (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF3_CTRL_F00_Msk            (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* =======================================================  BUF3_ADDR  ======================================================= */
#define BUFC_BUF3_ADDR_F00_Pos            (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF3_ADDR_F00_Msk            (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ===================================================  BUF3_WRITEOFFSET  ==================================================== */
#define BUFC_BUF3_WRITEOFFSET_F00_Pos     (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF3_WRITEOFFSET_F00_Msk     (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ====================================================  BUF3_READOFFSET  ==================================================== */
#define BUFC_BUF3_READOFFSET_F00_Pos      (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF3_READOFFSET_F00_Msk      (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ====================================================  BUF3_WRITESTART  ==================================================== */
#define BUFC_BUF3_WRITESTART_F00_Pos      (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF3_WRITESTART_F00_Msk      (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* =====================================================  BUF3_READDATA  ===================================================== */
#define BUFC_BUF3_READDATA_F00_Pos        (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF3_READDATA_F00_Msk        (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ====================================================  BUF3_WRITEDATA  ===================================================== */
#define BUFC_BUF3_WRITEDATA_F00_Pos       (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF3_WRITEDATA_F00_Msk       (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ======================================================  BUF3_XWRITE  ====================================================== */
#define BUFC_BUF3_XWRITE_F00_Pos          (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF3_XWRITE_F00_Msk          (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ======================================================  BUF3_STATUS  ====================================================== */
#define BUFC_BUF3_STATUS_F00_Pos          (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF3_STATUS_F00_Msk          (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ==================================================  BUF3_THRESHOLDCTRL  =================================================== */
#define BUFC_BUF3_THRESHOLDCTRL_F00_Pos   (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF3_THRESHOLDCTRL_F00_Msk   (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* =======================================================  BUF3_CMD  ======================================================== */
#define BUFC_BUF3_CMD_F00_Pos             (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_BUF3_CMD_F00_Msk             (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ==========================================================  IF  =========================================================== */
#define BUFC_IF_F00_Pos                   (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_IF_F00_Msk                   (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ==========================================================  IFS  ========================================================== */
#define BUFC_IFS_F00_Pos                  (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_IFS_F00_Msk                  (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ==========================================================  IFC  ========================================================== */
#define BUFC_IFC_F00_Pos                  (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_IFC_F00_Msk                  (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ==========================================================  IEN  ========================================================== */
#define BUFC_IEN_F00_Pos                  (0UL)                     /*!< F00 (Bit 0)                                           */
#define BUFC_IEN_F00_Msk                  (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */



/** @} */
/** @} End of group EFR32FG1V_BUFC */
/** @} End of group Parts */
