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
 * @defgroup EFR32FG1V_SEQ
 * @{
 * @brief EFR32FG1V_SEQ Register Declaration
 ******************************************************************************/
/* =========================================================================================================================== */
/* ================                                            SEQ                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Sequencer (SEQ)
  */

typedef struct {                                /*!< (@ 0x21000F00) SEQ Structure                                              */
  __IOM uint32_t  REG000;                       /*!< (@ 0x00000000) REG000                                                     */
  __IOM uint32_t  REG004;                       /*!< (@ 0x00000004) REG004                                                     */
  __IOM uint32_t  REG008;                       /*!< (@ 0x00000008) REG008                                                     */
  __IOM uint32_t  REG00C;                       /*!< (@ 0x0000000C) REG00C                                                     */
  __IOM uint32_t  REG010;                       /*!< (@ 0x00000010) REG010                                                     */
  __IOM uint32_t  REG014;                       /*!< (@ 0x00000014) REG014                                                     */
  __IOM uint32_t  REG018;                       /*!< (@ 0x00000018) REG018                                                     */
  __IOM uint32_t  REG01C;                       /*!< (@ 0x0000001C) REG01C                                                     */
  __IOM uint32_t  REG020;                       /*!< (@ 0x00000020) REG020                                                     */
  __IOM uint32_t  REG024;                       /*!< (@ 0x00000024) REG024                                                     */
  __IOM uint32_t  REG028;                       /*!< (@ 0x00000028) REG028                                                     */
  __IOM uint32_t  REG02C;                       /*!< (@ 0x0000002C) REG02C                                                     */
  __IOM uint32_t  REG030;                       /*!< (@ 0x00000030) REG030                                                     */
  __IOM uint32_t  REG034;                       /*!< (@ 0x00000034) REG034                                                     */
  __IOM uint32_t  REG038;                       /*!< (@ 0x00000038) REG038                                                     */
  __IOM uint32_t  REG03C;                       /*!< (@ 0x0000003C) REG03C                                                     */
  __IOM uint32_t  REG040;                       /*!< (@ 0x00000040) REG040                                                     */
  __IOM uint32_t  REG044;                       /*!< (@ 0x00000044) REG044                                                     */
  __IOM uint32_t  REG048;                       /*!< (@ 0x00000048) REG048                                                     */
  __IOM uint32_t  REG04C;                       /*!< (@ 0x0000004C) REG04C                                                     */
  __IOM uint32_t  REG050;                       /*!< (@ 0x00000050) REG050                                                     */
  __IOM uint32_t  REG054;                       /*!< (@ 0x00000054) REG054                                                     */
  __IOM uint32_t  REG058;                       /*!< (@ 0x00000058) REG058                                                     */
  __IOM uint32_t  REG05C;                       /*!< (@ 0x0000005C) REG05C                                                     */
  __IOM uint32_t  REG060;                       /*!< (@ 0x00000060) REG060                                                     */
  __IOM uint32_t  REG064;                       /*!< (@ 0x00000064) REG064                                                     */
  __IOM uint32_t  REG068;                       /*!< (@ 0x00000068) REG068                                                     */
  __IOM uint32_t  REG06C;                       /*!< (@ 0x0000006C) REG06C                                                     */
  __IOM uint32_t  REG070;                       /*!< (@ 0x00000070) REG070                                                     */
  __IOM uint32_t  REG074;                       /*!< (@ 0x00000074) REG074                                                     */
  __IOM uint32_t  REG078;                       /*!< (@ 0x00000078) REG078                                                     */
  __IOM uint32_t  REG07C;                       /*!< (@ 0x0000007C) REG07C                                                     */
  __IOM uint32_t  REG080;                       /*!< (@ 0x00000080) REG080                                                     */
  __IOM uint32_t  REG084;                       /*!< (@ 0x00000084) REG084                                                     */
  __IOM uint32_t  REG088;                       /*!< (@ 0x00000088) REG088                                                     */
  __IOM uint32_t  REG08C;                       /*!< (@ 0x0000008C) REG08C                                                     */
  __IOM uint32_t  REG090;                       /*!< (@ 0x00000090) REG090                                                     */
  __IOM uint32_t  REG094;                       /*!< (@ 0x00000094) REG094                                                     */
  __IOM uint32_t  REG098;                       /*!< (@ 0x00000098) REG098                                                     */
  __IOM uint32_t  REG09C;                       /*!< (@ 0x0000009C) REG09C                                                     */
  __IOM uint32_t  REG0A0;                       /*!< (@ 0x000000A0) REG0A0                                                     */
  __IOM uint32_t  REG0A4;                       /*!< (@ 0x000000A4) REG0A4                                                     */
  __IOM uint32_t  REG0A8;                       /*!< (@ 0x000000A8) REG0A8                                                     */
  __IOM uint32_t  REG0AC;                       /*!< (@ 0x000000AC) REG0AC                                                     */
  __IOM uint32_t  REG0B0;                       /*!< (@ 0x000000B0) REG0B0                                                     */
  __IOM uint32_t  REG0B4;                       /*!< (@ 0x000000B4) REG0B4                                                     */
  __IOM uint32_t  REG0B8;                       /*!< (@ 0x000000B8) REG0B8                                                     */
  __IOM uint32_t  REG0BC;                       /*!< (@ 0x000000BC) REG0BC                                                     */
  __IOM uint32_t  REG0C0;                       /*!< (@ 0x000000C0) REG0C0                                                     */
  __IOM uint32_t  REG0C4;                       /*!< (@ 0x000000C4) REG0C4                                                     */
  __IOM uint32_t  REG0C8;                       /*!< (@ 0x000000C8) REG0C8                                                     */
  __IOM uint32_t  REG0CC;                       /*!< (@ 0x000000CC) REG0CC                                                     */
  __IOM uint32_t  REG0D0;                       /*!< (@ 0x000000D0) REG0D0                                                     */
  __IOM uint32_t  REG0D4;                       /*!< (@ 0x000000D4) REG0D4                                                     */
  __IOM uint32_t  REG0D8;                       /*!< (@ 0x000000D8) REG0D8                                                     */
  __IOM uint32_t  REG0DC;                       /*!< (@ 0x000000DC) REG0DC                                                     */
  __IOM uint32_t  REG0E0;                       /*!< (@ 0x000000E0) REG0E0                                                     */
  __IOM uint32_t  REG0E4;                       /*!< (@ 0x000000E4) REG0E4                                                     */
  __IOM uint32_t  REG0E8;                       /*!< (@ 0x000000E8) REG0E8                                                     */
  __IOM uint32_t  DYNAMIC_CHPWR_TABLE;          /*!< (@ 0x000000EC) DYNAMIC_CHPWR_TABLE                                        */
  __IOM uint32_t  PHYINFO;                      /*!< (@ 0x000000F0) PHYINFO                                                    */
  __IOM uint32_t  MISC;                         /*!< (@ 0x000000F4) MISC                                                       */
  __IOM uint32_t  SYNTHLPFCTRLRX;               /*!< (@ 0x000000F8) SYNTHLPFCTRLRX                                             */
  __IOM uint32_t  SYNTHLPFCTRLTX;               /*!< (@ 0x000000FC) SYNTHLPFCTRLTX                                             */
} SEQ_Typedef;                                    /*!< Size = 20 (0x14)                                                          */

/***************************************************************************//**
 * @addtogroup EFR32FG1V_SEQ
 * @{
 * @defgroup EFR32FG1V_SEQ BitFields  SEQ Bit Fields
 * @{
 ******************************************************************************/
/* =========================================================================================================================== */
/* ================                                            SEQ                                            ================ */
/* =========================================================================================================================== */

/* ==================================================  DYNAMIC_CHPWR_TABLE  ================================================== */
#define SEQ_DYNAMIC_CHPWR_TABLE_ADDRESS_Pos (0UL)                   /*!< ADDRESS (Bit 0)                                       */
#define SEQ_DYNAMIC_CHPWR_TABLE_ADDRESS_Msk (0xffffffffUL)          /*!< ADDRESS (Bitfield-Mask: 0xffffffff)                   */
/* ========================================================  PHYINFO  ======================================================== */
#define SEQ_PHYINFO_ADDRESS_Pos           (0UL)                     /*!< ADDRESS (Bit 0)                                       */
#define SEQ_PHYINFO_ADDRESS_Msk           (0xffffffffUL)            /*!< ADDRESS (Bitfield-Mask: 0xffffffff)                   */
/* =========================================================  MISC  ========================================================== */
#define SEQ_MISC_DYNAMIC_SLICER_SW_EN_Pos (1UL)                     /*!< DYNAMIC_SLICER_SW_EN (Bit 1)                          */
#define SEQ_MISC_DYNAMIC_SLICER_SW_EN_Msk (0x2UL)                   /*!< DYNAMIC_SLICER_SW_EN (Bitfield-Mask: 0x01)            */
#define SEQ_MISC_SQBMODETX_Pos            (10UL)                    /*!< SQBMODETX (Bit 10)                                    */
#define SEQ_MISC_SQBMODETX_Msk            (0xc00UL)                 /*!< SQBMODETX (Bitfield-Mask: 0x03)                       */
/* ====================================================  SYNTHLPFCTRLRX  ===================================================== */
#define SEQ_SYNTHLPFCTRLRX_SYNTHLPFCTRLRX_Pos (0UL)                 /*!< SYNTHLPFCTRLRX (Bit 0)                                */
#define SEQ_SYNTHLPFCTRLRX_SYNTHLPFCTRLRX_Msk (0xffffffffUL)        /*!< SYNTHLPFCTRLRX (Bitfield-Mask: 0xffffffff)            */
/* ====================================================  SYNTHLPFCTRLTX  ===================================================== */
#define SEQ_SYNTHLPFCTRLTX_SYNTHLPFCTRLTX_Pos (0UL)                 /*!< SYNTHLPFCTRLTX (Bit 0)                                */
#define SEQ_SYNTHLPFCTRLTX_SYNTHLPFCTRLTX_Msk (0xffffffffUL)        /*!< SYNTHLPFCTRLTX (Bitfield-Mask: 0xffffffff)            */


/** @} */
/** @} End of group EFR32FG1V_SEQ */
/** @} End of group Parts */
