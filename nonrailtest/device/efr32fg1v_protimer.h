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
 * @defgroup EFR32FG1V_PROTIMER
 * @{
 * @brief EFR32FG1V_PROTIMER Register Declaration
 ******************************************************************************/
/* =========================================================================================================================== */
/* ================                                         PROTIMER                                          ================ */
/* =========================================================================================================================== */


/**
  * @brief PROTIMER (PROTIMER)
  */

typedef struct {                                /*!< (@ 0x40085000) PROTIMER Structure                                         */
  __IOM uint32_t  CTRL;                         /*!< (@ 0x00000000) CTRL                                                       */
  __IOM uint32_t  CMD;                          /*!< (@ 0x00000004) CMD                                                        */
  __IOM uint32_t  PRSCTRL;                      /*!< (@ 0x00000008) PRSCTRL                                                    */
  __IOM uint32_t  STATUS;                       /*!< (@ 0x0000000C) STATUS                                                     */
  __IOM uint32_t  PRECNT;                       /*!< (@ 0x00000010) PRECNT                                                     */
  __IOM uint32_t  BASECNT;                      /*!< (@ 0x00000014) BASECNT                                                    */
  __IOM uint32_t  WRAPCNT;                      /*!< (@ 0x00000018) WRAPCNT                                                    */
  __IOM uint32_t  BASEPRE;                      /*!< (@ 0x0000001C) BASEPRE                                                    */
  __IOM uint32_t  LWRAPCNT;                     /*!< (@ 0x00000020) LWRAPCNT                                                   */
  __IOM uint32_t  PRECNTTOPADJ;                 /*!< (@ 0x00000024) PRECNTTOPADJ                                               */
  __IOM uint32_t  PRECNTTOP;                    /*!< (@ 0x00000028) PRECNTTOP                                                  */
  __IOM uint32_t  BASECNTTOP;                   /*!< (@ 0x0000002C) BASECNTTOP                                                 */
  __IOM uint32_t  WRAPCNTTOP;                   /*!< (@ 0x00000030) WRAPCNTTOP                                                 */
  __IOM uint32_t  TOUT0CNT;                     /*!< (@ 0x00000034) TOUT0CNT                                                   */
  __IOM uint32_t  TOUT0CNTTOP;                  /*!< (@ 0x00000038) TOUT0CNTTOP                                                */
  __IOM uint32_t  TOUT0COMP;                    /*!< (@ 0x0000003C) TOUT0COMP                                                  */
  __IOM uint32_t  TOUT1CNT;                     /*!< (@ 0x00000040) TOUT1CNT                                                   */
  __IOM uint32_t  TOUT1CNTTOP;                  /*!< (@ 0x00000044) TOUT1CNTTOP                                                */
  __IOM uint32_t  TOUT1COMP;                    /*!< (@ 0x00000048) TOUT1COMP                                                  */
  __IOM uint32_t  LBTCTRL;                      /*!< (@ 0x0000004C) LBTCTRL                                                    */
  __IOM uint32_t  LBTPRSCTRL;                   /*!< (@ 0x00000050) LBTPRSCTRL                                                 */
  __IOM uint32_t  LBTSTATE;                     /*!< (@ 0x00000054) LBTSTATE                                                   */
  __IOM uint32_t  RANDOM;                       /*!< (@ 0x00000058) RANDOM                                                     */
  __IOM uint32_t  IF;                           /*!< (@ 0x0000005C) IF                                                         */
  __IOM uint32_t  IFS;                          /*!< (@ 0x00000060) IFS                                                        */
  __IOM uint32_t  IFC;                          /*!< (@ 0x00000064) IFC                                                        */
  __IOM uint32_t  IEN;                          /*!< (@ 0x00000068) IEN                                                        */
  __IOM uint32_t  RXCTRL;                       /*!< (@ 0x0000006C) RXCTRL                                                     */
  __IOM uint32_t  TXCTRL;                       /*!< (@ 0x00000070) TXCTRL                                                     */
  __IOM uint32_t  CC0_CTRL;                     /*!< (@ 0x00000074) CC0_CTRL                                                   */
  __IOM uint32_t  CC0_PRE;                      /*!< (@ 0x00000078) CC0_PRE                                                    */
  __IOM uint32_t  CC0_BASE;                     /*!< (@ 0x0000007C) CC0_BASE                                                   */
  __IOM uint32_t  CC0_WRAP;                     /*!< (@ 0x00000080) CC0_WRAP                                                   */
  __IOM uint32_t  CC1_CTRL;                     /*!< (@ 0x00000084) CC1_CTRL                                                   */
  __IOM uint32_t  CC1_PRE;                      /*!< (@ 0x00000088) CC1_PRE                                                    */
  __IOM uint32_t  CC1_BASE;                     /*!< (@ 0x0000008C) CC1_BASE                                                   */
  __IOM uint32_t  CC1_WRAP;                     /*!< (@ 0x00000090) CC1_WRAP                                                   */
  __IOM uint32_t  CC2_CTRL;                     /*!< (@ 0x00000094) CC2_CTRL                                                   */
  __IOM uint32_t  CC2_PRE;                      /*!< (@ 0x00000098) CC2_PRE                                                    */
  __IOM uint32_t  CC2_BASE;                     /*!< (@ 0x0000009C) CC2_BASE                                                   */
  __IOM uint32_t  CC2_WRAP;                     /*!< (@ 0x000000A0) CC2_WRAP                                                   */
  __IOM uint32_t  CC3_CTRL;                     /*!< (@ 0x000000A4) CC3_CTRL                                                   */
  __IOM uint32_t  CC3_PRE;                      /*!< (@ 0x000000A8) CC3_PRE                                                    */
  __IOM uint32_t  CC3_BASE;                     /*!< (@ 0x000000AC) CC3_BASE                                                   */
  __IOM uint32_t  CC3_WRAP;                     /*!< (@ 0x000000B0) CC3_WRAP                                                   */
  __IOM uint32_t  CC4_CTRL;                     /*!< (@ 0x000000B4) CC4_CTRL                                                   */
  __IOM uint32_t  CC4_PRE;                      /*!< (@ 0x000000B8) CC4_PRE                                                    */
  __IOM uint32_t  CC4_BASE;                     /*!< (@ 0x000000BC) CC4_BASE                                                   */
  __IOM uint32_t  CC4_WRAP;                     /*!< (@ 0x000000C0) CC4_WRAP                                                   */
} PROTIMER_Typedef;                                /*!< Size = 196 (0xc4)                                                         */
 
/***************************************************************************//**
 * @addtogroup EFR32FG1V_PROTIMER
 * @{
 * @defgroup EFR32FG1V_PROTIMER BitFields  PROTIMER Bit Fields
 * @{
 ******************************************************************************/
/* =========================================================================================================================== */
/* ================                                         PROTIMER                                          ================ */
/* =========================================================================================================================== */

/* =========================================================  CTRL  ========================================================== */
#define PROTIMER_CTRL_F00_Pos             (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_CTRL_F00_Msk             (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* ==========================================================  CMD  ========================================================== */
#define PROTIMER_CMD_F00_Pos              (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_CMD_F00_Msk              (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* ========================================================  PRSCTRL  ======================================================== */
#define PROTIMER_PRSCTRL_F00_Pos          (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_PRSCTRL_F00_Msk          (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* ========================================================  STATUS  ========================================================= */
#define PROTIMER_STATUS_F00_Pos           (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_STATUS_F00_Msk           (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* ========================================================  PRECNT  ========================================================= */
#define PROTIMER_PRECNT_F00_Pos           (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_PRECNT_F00_Msk           (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* ========================================================  BASECNT  ======================================================== */
#define PROTIMER_BASECNT_F00_Pos          (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_BASECNT_F00_Msk          (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* ========================================================  WRAPCNT  ======================================================== */
#define PROTIMER_WRAPCNT_F00_Pos          (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_WRAPCNT_F00_Msk          (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* ========================================================  BASEPRE  ======================================================== */
#define PROTIMER_BASEPRE_F00_Pos          (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_BASEPRE_F00_Msk          (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* =======================================================  LWRAPCNT  ======================================================== */
#define PROTIMER_LWRAPCNT_F00_Pos         (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_LWRAPCNT_F00_Msk         (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* =====================================================  PRECNTTOPADJ  ====================================================== */
#define PROTIMER_PRECNTTOPADJ_F00_Pos     (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_PRECNTTOPADJ_F00_Msk     (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* =======================================================  PRECNTTOP  ======================================================= */
#define PROTIMER_PRECNTTOP_F00_Pos        (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_PRECNTTOP_F00_Msk        (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* ======================================================  BASECNTTOP  ======================================================= */
#define PROTIMER_BASECNTTOP_F00_Pos       (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_BASECNTTOP_F00_Msk       (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* ======================================================  WRAPCNTTOP  ======================================================= */
#define PROTIMER_WRAPCNTTOP_F00_Pos       (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_WRAPCNTTOP_F00_Msk       (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* =======================================================  TOUT0CNT  ======================================================== */
#define PROTIMER_TOUT0CNT_F00_Pos         (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_TOUT0CNT_F00_Msk         (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* ======================================================  TOUT0CNTTOP  ====================================================== */
#define PROTIMER_TOUT0CNTTOP_F00_Pos      (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_TOUT0CNTTOP_F00_Msk      (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* =======================================================  TOUT0COMP  ======================================================= */
#define PROTIMER_TOUT0COMP_F00_Pos        (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_TOUT0COMP_F00_Msk        (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* =======================================================  TOUT1CNT  ======================================================== */
#define PROTIMER_TOUT1CNT_F00_Pos         (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_TOUT1CNT_F00_Msk         (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* ======================================================  TOUT1CNTTOP  ====================================================== */
#define PROTIMER_TOUT1CNTTOP_F00_Pos      (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_TOUT1CNTTOP_F00_Msk      (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* =======================================================  TOUT1COMP  ======================================================= */
#define PROTIMER_TOUT1COMP_F00_Pos        (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_TOUT1COMP_F00_Msk        (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* ========================================================  LBTCTRL  ======================================================== */
#define PROTIMER_LBTCTRL_F00_Pos          (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_LBTCTRL_F00_Msk          (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* ======================================================  LBTPRSCTRL  ======================================================= */
#define PROTIMER_LBTPRSCTRL_F00_Pos       (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_LBTPRSCTRL_F00_Msk       (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* =======================================================  LBTSTATE  ======================================================== */
#define PROTIMER_LBTSTATE_F00_Pos         (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_LBTSTATE_F00_Msk         (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* ========================================================  RANDOM  ========================================================= */
#define PROTIMER_RANDOM_F00_Pos           (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_RANDOM_F00_Msk           (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* ==========================================================  IF  =========================================================== */
#define PROTIMER_IF_F00_Pos               (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_IF_F00_Msk               (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* ==========================================================  IFS  ========================================================== */
#define PROTIMER_IFS_F00_Pos              (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_IFS_F00_Msk              (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* ==========================================================  IFC  ========================================================== */
#define PROTIMER_IFC_F00_Pos              (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_IFC_F00_Msk              (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* ==========================================================  IEN  ========================================================== */
#define PROTIMER_IEN_F00_Pos              (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_IEN_F00_Msk              (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* ========================================================  RXCTRL  ========================================================= */
#define PROTIMER_RXCTRL_F00_Pos           (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_RXCTRL_F00_Msk           (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* ========================================================  TXCTRL  ========================================================= */
#define PROTIMER_TXCTRL_F00_Pos           (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_TXCTRL_F00_Msk           (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* =======================================================  CC0_CTRL  ======================================================== */
#define PROTIMER_CC0_CTRL_F00_Pos         (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_CC0_CTRL_F00_Msk         (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* ========================================================  CC0_PRE  ======================================================== */
#define PROTIMER_CC0_PRE_F00_Pos          (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_CC0_PRE_F00_Msk          (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* =======================================================  CC0_BASE  ======================================================== */
#define PROTIMER_CC0_BASE_F00_Pos         (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_CC0_BASE_F00_Msk         (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* =======================================================  CC0_WRAP  ======================================================== */
#define PROTIMER_CC0_WRAP_F00_Pos         (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_CC0_WRAP_F00_Msk         (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* =======================================================  CC1_CTRL  ======================================================== */
#define PROTIMER_CC1_CTRL_F00_Pos         (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_CC1_CTRL_F00_Msk         (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* ========================================================  CC1_PRE  ======================================================== */
#define PROTIMER_CC1_PRE_F00_Pos          (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_CC1_PRE_F00_Msk          (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* =======================================================  CC1_BASE  ======================================================== */
#define PROTIMER_CC1_BASE_F00_Pos         (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_CC1_BASE_F00_Msk         (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* =======================================================  CC1_WRAP  ======================================================== */
#define PROTIMER_CC1_WRAP_F00_Pos         (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_CC1_WRAP_F00_Msk         (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* =======================================================  CC2_CTRL  ======================================================== */
#define PROTIMER_CC2_CTRL_F00_Pos         (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_CC2_CTRL_F00_Msk         (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* ========================================================  CC2_PRE  ======================================================== */
#define PROTIMER_CC2_PRE_F00_Pos          (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_CC2_PRE_F00_Msk          (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* =======================================================  CC2_BASE  ======================================================== */
#define PROTIMER_CC2_BASE_F00_Pos         (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_CC2_BASE_F00_Msk         (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* =======================================================  CC2_WRAP  ======================================================== */
#define PROTIMER_CC2_WRAP_F00_Pos         (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_CC2_WRAP_F00_Msk         (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* =======================================================  CC3_CTRL  ======================================================== */
#define PROTIMER_CC3_CTRL_F00_Pos         (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_CC3_CTRL_F00_Msk         (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* ========================================================  CC3_PRE  ======================================================== */
#define PROTIMER_CC3_PRE_F00_Pos          (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_CC3_PRE_F00_Msk          (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* =======================================================  CC3_BASE  ======================================================== */
#define PROTIMER_CC3_BASE_F00_Pos         (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_CC3_BASE_F00_Msk         (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* =======================================================  CC3_WRAP  ======================================================== */
#define PROTIMER_CC3_WRAP_F00_Pos         (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_CC3_WRAP_F00_Msk         (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* =======================================================  CC4_CTRL  ======================================================== */
#define PROTIMER_CC4_CTRL_F00_Pos         (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_CC4_CTRL_F00_Msk         (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* ========================================================  CC4_PRE  ======================================================== */
#define PROTIMER_CC4_PRE_F00_Pos          (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_CC4_PRE_F00_Msk          (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* =======================================================  CC4_BASE  ======================================================== */
#define PROTIMER_CC4_BASE_F00_Pos         (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_CC4_BASE_F00_Msk         (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */
/* =======================================================  CC4_WRAP  ======================================================== */
#define PROTIMER_CC4_WRAP_F00_Pos         (0UL)                     /*!< F00 (Bit 0)                                           */
#define PROTIMER_CC4_WRAP_F00_Msk         (0x1UL)                   /*!< F00 (Bitfield-Mask: 0x01)                             */

/** @} */
/** @} End of group EFR32FG1V_PROTIMER*/
/** @} End of group Parts */
