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
 * @defgroup EFR32FG1V_RFSENSE
 * @{
 * @brief EFR32FG1V_RFSENSE Register Declaration
 ******************************************************************************/
/* =========================================================================================================================== */
/* ================                                          RFSENSE                                          ================ */
/* =========================================================================================================================== */


/**
  * @brief RFSENSE (RFSENSE)
  */

typedef struct {                                /*!< (@ 0x40088000) RFSENSE Structure                                          */
  __IOM uint32_t  CTRL;                         /*!< (@ 0x00000000) CTRL                                                       */
  __IOM uint32_t  PERIODSEL;                    /*!< (@ 0x00000004) PERIODSEL                                                  */
  __IOM uint32_t  CNT;                          /*!< (@ 0x00000008) CNT                                                        */
  __IM  uint32_t  RESERVED;
  __IOM uint32_t  EM4WUEN;                      /*!< (@ 0x00000010) EM4WUEN                                                    */
  __IOM uint32_t  CALIB;                        /*!< (@ 0x00000014) CALIB                                                      */
  __IOM uint32_t  IF;                           /*!< (@ 0x00000018) IF                                                         */
  __IOM uint32_t  IFS;                          /*!< (@ 0x0000001C) IFS                                                        */
  __IOM uint32_t  IFC;                          /*!< (@ 0x00000020) IFC                                                        */
  __IOM uint32_t  IEN;                          /*!< (@ 0x00000024) IEN                                                        */
} RFSENSE_Typedef;                                 /*!< Size = 40 (0x28)                                                          */
 
/***************************************************************************//**
 * @addtogroup EFR32FG1V_RFSENSE
 * @{
 * @defgroup EFR32FG1V_RFSENSE BitFields  RFSENSE Bit Fields
 * @{
 ******************************************************************************/
/* =========================================================================================================================== */
/* ================                                          RFSENSE                                          ================ */
/* =========================================================================================================================== */

/* =========================================================  CTRL  ========================================================== */
#define RFSENSE_CTRL_F00_Pos              (0UL)                     /*!< F00 (Bit 0)                                           */
#define RFSENSE_CTRL_F00_Msk              (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* =======================================================  PERIODSEL  ======================================================= */
#define RFSENSE_PERIODSEL_F00_Pos         (0UL)                     /*!< F00 (Bit 0)                                           */
#define RFSENSE_PERIODSEL_F00_Msk         (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ==========================================================  CNT  ========================================================== */
#define RFSENSE_CNT_F00_Pos               (0UL)                     /*!< F00 (Bit 0)                                           */
#define RFSENSE_CNT_F00_Msk               (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ========================================================  EM4WUEN  ======================================================== */
#define RFSENSE_EM4WUEN_F00_Pos           (0UL)                     /*!< F00 (Bit 0)                                           */
#define RFSENSE_EM4WUEN_F00_Msk           (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* =========================================================  CALIB  ========================================================= */
#define RFSENSE_CALIB_F00_Pos             (0UL)                     /*!< F00 (Bit 0)                                           */
#define RFSENSE_CALIB_F00_Msk             (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ==========================================================  IF  =========================================================== */
#define RFSENSE_IF_F00_Pos                (0UL)                     /*!< F00 (Bit 0)                                           */
#define RFSENSE_IF_F00_Msk                (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ==========================================================  IFS  ========================================================== */
#define RFSENSE_IFS_F00_Pos               (0UL)                     /*!< F00 (Bit 0)                                           */
#define RFSENSE_IFS_F00_Msk               (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ==========================================================  IFC  ========================================================== */
#define RFSENSE_IFC_F00_Pos               (0UL)                     /*!< F00 (Bit 0)                                           */
#define RFSENSE_IFC_F00_Msk               (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */
/* ==========================================================  IEN  ========================================================== */
#define RFSENSE_IEN_F00_Pos               (0UL)                     /*!< F00 (Bit 0)                                           */
#define RFSENSE_IEN_F00_Msk               (0xffffffffUL)            /*!< F00 (Bitfield-Mask: 0xffffffff)                       */



/** @} */
/** @} End of group EFR32FG1V_RFSENSE */
/** @} End of group Parts */
