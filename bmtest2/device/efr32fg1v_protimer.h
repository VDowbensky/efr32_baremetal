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
#define PROTIMER_CTRL_DEBUGRUN_Pos        (1UL)                     /*!< DEBUGRUN (Bit 1)                                      */
#define PROTIMER_CTRL_DEBUGRUN_Msk        (0x2UL)                   /*!< DEBUGRUN (Bitfield-Mask: 0x01)                        */
#define PROTIMER_CTRL_DMACLRACT_Pos       (2UL)                     /*!< DMACLRACT (Bit 2)                                     */
#define PROTIMER_CTRL_DMACLRACT_Msk       (0x4UL)                   /*!< DMACLRACT (Bitfield-Mask: 0x01)                       */
#define PROTIMER_CTRL_OSMEN_Pos           (4UL)                     /*!< OSMEN (Bit 4)                                         */
#define PROTIMER_CTRL_OSMEN_Msk           (0x10UL)                  /*!< OSMEN (Bitfield-Mask: 0x01)                           */
#define PROTIMER_CTRL_ZEROSTARTEN_Pos     (5UL)                     /*!< ZEROSTARTEN (Bit 5)                                   */
#define PROTIMER_CTRL_ZEROSTARTEN_Msk     (0x20UL)                  /*!< ZEROSTARTEN (Bitfield-Mask: 0x01)                     */
#define PROTIMER_CTRL_PRECNTSRC_Pos       (8UL)                     /*!< PRECNTSRC (Bit 8)                                     */
#define PROTIMER_CTRL_PRECNTSRC_Msk       (0x300UL)                 /*!< PRECNTSRC (Bitfield-Mask: 0x03)                       */
#define PROTIMER_CTRL_BASECNTSRC_Pos      (12UL)                    /*!< BASECNTSRC (Bit 12)                                   */
#define PROTIMER_CTRL_BASECNTSRC_Msk      (0x3000UL)                /*!< BASECNTSRC (Bitfield-Mask: 0x03)                      */
#define PROTIMER_CTRL_WRAPCNTSRC_Pos      (16UL)                    /*!< WRAPCNTSRC (Bit 16)                                   */
#define PROTIMER_CTRL_WRAPCNTSRC_Msk      (0x30000UL)               /*!< WRAPCNTSRC (Bitfield-Mask: 0x03)                      */
#define PROTIMER_CTRL_TOUT0SRC_Pos        (20UL)                    /*!< TOUT0SRC (Bit 20)                                     */
#define PROTIMER_CTRL_TOUT0SRC_Msk        (0x300000UL)              /*!< TOUT0SRC (Bitfield-Mask: 0x03)                        */
#define PROTIMER_CTRL_TOUT0SYNCSRC_Pos    (22UL)                    /*!< TOUT0SYNCSRC (Bit 22)                                 */
#define PROTIMER_CTRL_TOUT0SYNCSRC_Msk    (0xc00000UL)              /*!< TOUT0SYNCSRC (Bitfield-Mask: 0x03)                    */
#define PROTIMER_CTRL_TOUT1SRC_Pos        (24UL)                    /*!< TOUT1SRC (Bit 24)                                     */
#define PROTIMER_CTRL_TOUT1SRC_Msk        (0x3000000UL)             /*!< TOUT1SRC (Bitfield-Mask: 0x03)                        */
#define PROTIMER_CTRL_TOUT1SYNCSRC_Pos    (26UL)                    /*!< TOUT1SYNCSRC (Bit 26)                                 */
#define PROTIMER_CTRL_TOUT1SYNCSRC_Msk    (0xc000000UL)             /*!< TOUT1SYNCSRC (Bitfield-Mask: 0x03)                    */
#define PROTIMER_CTRL_TOUT0MODE_Pos       (28UL)                    /*!< TOUT0MODE (Bit 28)                                    */
#define PROTIMER_CTRL_TOUT0MODE_Msk       (0x10000000UL)            /*!< TOUT0MODE (Bitfield-Mask: 0x01)                       */
#define PROTIMER_CTRL_TOUT1MODE_Pos       (29UL)                    /*!< TOUT1MODE (Bit 29)                                    */
#define PROTIMER_CTRL_TOUT1MODE_Msk       (0x20000000UL)            /*!< TOUT1MODE (Bitfield-Mask: 0x01)                       */
/* ==========================================================  CMD  ========================================================== */
#define PROTIMER_CMD_START_Pos            (0UL)                     /*!< START (Bit 0)                                         */
#define PROTIMER_CMD_START_Msk            (0x1UL)                   /*!< START (Bitfield-Mask: 0x01)                           */
#define PROTIMER_CMD_RTCSYNCSTART_Pos     (1UL)                     /*!< RTCSYNCSTART (Bit 1)                                  */
#define PROTIMER_CMD_RTCSYNCSTART_Msk     (0x2UL)                   /*!< RTCSYNCSTART (Bitfield-Mask: 0x01)                    */
#define PROTIMER_CMD_STOP_Pos             (2UL)                     /*!< STOP (Bit 2)                                          */
#define PROTIMER_CMD_STOP_Msk             (0x4UL)                   /*!< STOP (Bitfield-Mask: 0x01)                            */
#define PROTIMER_CMD_TOUT0START_Pos       (4UL)                     /*!< TOUT0START (Bit 4)                                    */
#define PROTIMER_CMD_TOUT0START_Msk       (0x10UL)                  /*!< TOUT0START (Bitfield-Mask: 0x01)                      */
#define PROTIMER_CMD_TOUT0STOP_Pos        (5UL)                     /*!< TOUT0STOP (Bit 5)                                     */
#define PROTIMER_CMD_TOUT0STOP_Msk        (0x20UL)                  /*!< TOUT0STOP (Bitfield-Mask: 0x01)                       */
#define PROTIMER_CMD_TOUT1START_Pos       (6UL)                     /*!< TOUT1START (Bit 6)                                    */
#define PROTIMER_CMD_TOUT1START_Msk       (0x40UL)                  /*!< TOUT1START (Bitfield-Mask: 0x01)                      */
#define PROTIMER_CMD_TOUT1STOP_Pos        (7UL)                     /*!< TOUT1STOP (Bit 7)                                     */
#define PROTIMER_CMD_TOUT1STOP_Msk        (0x80UL)                  /*!< TOUT1STOP (Bitfield-Mask: 0x01)                       */
#define PROTIMER_CMD_LBTSTART_Pos         (16UL)                    /*!< LBTSTART (Bit 16)                                     */
#define PROTIMER_CMD_LBTSTART_Msk         (0x10000UL)               /*!< LBTSTART (Bitfield-Mask: 0x01)                        */
#define PROTIMER_CMD_LBTSTOP_Pos          (18UL)                    /*!< LBTSTOP (Bit 18)                                      */
#define PROTIMER_CMD_LBTSTOP_Msk          (0x40000UL)               /*!< LBTSTOP (Bitfield-Mask: 0x01)                         */
/* ========================================================  PRSCTRL  ======================================================== */
#define PROTIMER_PRSCTRL_STARTPRSEN_Pos   (1UL)                     /*!< STARTPRSEN (Bit 1)                                    */
#define PROTIMER_PRSCTRL_STARTPRSEN_Msk   (0x2UL)                   /*!< STARTPRSEN (Bitfield-Mask: 0x01)                      */
#define PROTIMER_PRSCTRL_STARTEDGE_Pos    (2UL)                     /*!< STARTEDGE (Bit 2)                                     */
#define PROTIMER_PRSCTRL_STARTEDGE_Msk    (0xcUL)                   /*!< STARTEDGE (Bitfield-Mask: 0x03)                       */
#define PROTIMER_PRSCTRL_STOPPRSEN_Pos    (9UL)                     /*!< STOPPRSEN (Bit 9)                                     */
#define PROTIMER_PRSCTRL_STOPPRSEN_Msk    (0x200UL)                 /*!< STOPPRSEN (Bitfield-Mask: 0x01)                       */
#define PROTIMER_PRSCTRL_STOPEDGE_Pos     (10UL)                    /*!< STOPEDGE (Bit 10)                                     */
#define PROTIMER_PRSCTRL_STOPEDGE_Msk     (0xc00UL)                 /*!< STOPEDGE (Bitfield-Mask: 0x03)                        */
#define PROTIMER_PRSCTRL_RTCCTRIGGERPRSEN_Pos (17UL)                /*!< RTCCTRIGGERPRSEN (Bit 17)                             */
#define PROTIMER_PRSCTRL_RTCCTRIGGERPRSEN_Msk (0x20000UL)           /*!< RTCCTRIGGERPRSEN (Bitfield-Mask: 0x01)                */
#define PROTIMER_PRSCTRL_RTCCTRIGGEREDGE_Pos (18UL)                 /*!< RTCCTRIGGEREDGE (Bit 18)                              */
#define PROTIMER_PRSCTRL_RTCCTRIGGEREDGE_Msk (0xc0000UL)            /*!< RTCCTRIGGEREDGE (Bitfield-Mask: 0x03)                 */
/* ========================================================  STATUS  ========================================================= */
#define PROTIMER_STATUS_RUNNING_Pos       (0UL)                     /*!< RUNNING (Bit 0)                                       */
#define PROTIMER_STATUS_RUNNING_Msk       (0x1UL)                   /*!< RUNNING (Bitfield-Mask: 0x01)                         */
#define PROTIMER_STATUS_LBTSYNC_Pos       (1UL)                     /*!< LBTSYNC (Bit 1)                                       */
#define PROTIMER_STATUS_LBTSYNC_Msk       (0x2UL)                   /*!< LBTSYNC (Bitfield-Mask: 0x01)                         */
#define PROTIMER_STATUS_LBTRUNNING_Pos    (2UL)                     /*!< LBTRUNNING (Bit 2)                                    */
#define PROTIMER_STATUS_LBTRUNNING_Msk    (0x4UL)                   /*!< LBTRUNNING (Bitfield-Mask: 0x01)                      */
#define PROTIMER_STATUS_LBTPAUSED_Pos     (3UL)                     /*!< LBTPAUSED (Bit 3)                                     */
#define PROTIMER_STATUS_LBTPAUSED_Msk     (0x8UL)                   /*!< LBTPAUSED (Bitfield-Mask: 0x01)                       */
#define PROTIMER_STATUS_TOUT0RUNNING_Pos  (4UL)                     /*!< TOUT0RUNNING (Bit 4)                                  */
#define PROTIMER_STATUS_TOUT0RUNNING_Msk  (0x10UL)                  /*!< TOUT0RUNNING (Bitfield-Mask: 0x01)                    */
#define PROTIMER_STATUS_TOUT0SYNC_Pos     (5UL)                     /*!< TOUT0SYNC (Bit 5)                                     */
#define PROTIMER_STATUS_TOUT0SYNC_Msk     (0x20UL)                  /*!< TOUT0SYNC (Bitfield-Mask: 0x01)                       */
#define PROTIMER_STATUS_TOUT1RUNNING_Pos  (6UL)                     /*!< TOUT1RUNNING (Bit 6)                                  */
#define PROTIMER_STATUS_TOUT1RUNNING_Msk  (0x40UL)                  /*!< TOUT1RUNNING (Bitfield-Mask: 0x01)                    */
#define PROTIMER_STATUS_TOUT1SYNC_Pos     (7UL)                     /*!< TOUT1SYNC (Bit 7)                                     */
#define PROTIMER_STATUS_TOUT1SYNC_Msk     (0x80UL)                  /*!< TOUT1SYNC (Bitfield-Mask: 0x01)                       */
#define PROTIMER_STATUS_ICV0_Pos          (8UL)                     /*!< ICV0 (Bit 8)                                          */
#define PROTIMER_STATUS_ICV0_Msk          (0x100UL)                 /*!< ICV0 (Bitfield-Mask: 0x01)                            */
#define PROTIMER_STATUS_ICV1_Pos          (9UL)                     /*!< ICV1 (Bit 9)                                          */
#define PROTIMER_STATUS_ICV1_Msk          (0x200UL)                 /*!< ICV1 (Bitfield-Mask: 0x01)                            */
#define PROTIMER_STATUS_ICV2_Pos          (10UL)                    /*!< ICV2 (Bit 10)                                         */
#define PROTIMER_STATUS_ICV2_Msk          (0x400UL)                 /*!< ICV2 (Bitfield-Mask: 0x01)                            */
#define PROTIMER_STATUS_ICV3_Pos          (11UL)                    /*!< ICV3 (Bit 11)                                         */
#define PROTIMER_STATUS_ICV3_Msk          (0x800UL)                 /*!< ICV3 (Bitfield-Mask: 0x01)                            */
#define PROTIMER_STATUS_ICV4_Pos          (12UL)                    /*!< ICV4 (Bit 12)                                         */
#define PROTIMER_STATUS_ICV4_Msk          (0x1000UL)                /*!< ICV4 (Bitfield-Mask: 0x01)                            */
/* ========================================================  PRECNT  ========================================================= */
#define PROTIMER_PRECNT_PRECNT_Pos        (0UL)                     /*!< PRECNT (Bit 0)                                        */
#define PROTIMER_PRECNT_PRECNT_Msk        (0xffffUL)                /*!< PRECNT (Bitfield-Mask: 0xffff)                        */
/* ========================================================  BASECNT  ======================================================== */
#define PROTIMER_BASECNT_BASECNT_Pos      (0UL)                     /*!< BASECNT (Bit 0)                                       */
#define PROTIMER_BASECNT_BASECNT_Msk      (0xffffUL)                /*!< BASECNT (Bitfield-Mask: 0xffff)                       */
/* ========================================================  WRAPCNT  ======================================================== */
#define PROTIMER_WRAPCNT_WRAPCNT_Pos      (0UL)                     /*!< WRAPCNT (Bit 0)                                       */
#define PROTIMER_WRAPCNT_WRAPCNT_Msk      (0xffffffffUL)            /*!< WRAPCNT (Bitfield-Mask: 0xffffffff)                   */
/* ========================================================  BASEPRE  ======================================================== */
#define PROTIMER_BASEPRE_PRECNTV_Pos      (0UL)                     /*!< PRECNTV (Bit 0)                                       */
#define PROTIMER_BASEPRE_PRECNTV_Msk      (0xffffUL)                /*!< PRECNTV (Bitfield-Mask: 0xffff)                       */
#define PROTIMER_BASEPRE_BASECNTV_Pos     (16UL)                    /*!< BASECNTV (Bit 16)                                     */
#define PROTIMER_BASEPRE_BASECNTV_Msk     (0xffff0000UL)            /*!< BASECNTV (Bitfield-Mask: 0xffff)                      */
/* =======================================================  LWRAPCNT  ======================================================== */
#define PROTIMER_LWRAPCNT_LWRAPCNT_Pos    (0UL)                     /*!< LWRAPCNT (Bit 0)                                      */
#define PROTIMER_LWRAPCNT_LWRAPCNT_Msk    (0xffffffffUL)            /*!< LWRAPCNT (Bitfield-Mask: 0xffffffff)                  */
/* =====================================================  PRECNTTOPADJ  ====================================================== */
#define PROTIMER_PRECNTTOPADJ_PRECNTTOPADJ_Pos (0UL)                /*!< PRECNTTOPADJ (Bit 0)                                  */
#define PROTIMER_PRECNTTOPADJ_PRECNTTOPADJ_Msk (0xffffUL)           /*!< PRECNTTOPADJ (Bitfield-Mask: 0xffff)                  */
/* =======================================================  PRECNTTOP  ======================================================= */
#define PROTIMER_PRECNTTOP_PRECNTTOPFRAC_Pos (0UL)                  /*!< PRECNTTOPFRAC (Bit 0)                                 */
#define PROTIMER_PRECNTTOP_PRECNTTOPFRAC_Msk (0xffUL)               /*!< PRECNTTOPFRAC (Bitfield-Mask: 0xff)                   */
#define PROTIMER_PRECNTTOP_PRECNTTOP_Pos  (8UL)                     /*!< PRECNTTOP (Bit 8)                                     */
#define PROTIMER_PRECNTTOP_PRECNTTOP_Msk  (0xffff00UL)              /*!< PRECNTTOP (Bitfield-Mask: 0xffff)                     */
/* ======================================================  BASECNTTOP  ======================================================= */
#define PROTIMER_BASECNTTOP_BASECNTTOP_Pos (0UL)                    /*!< BASECNTTOP (Bit 0)                                    */
#define PROTIMER_BASECNTTOP_BASECNTTOP_Msk (0xffffUL)               /*!< BASECNTTOP (Bitfield-Mask: 0xffff)                    */
/* ======================================================  WRAPCNTTOP  ======================================================= */
#define PROTIMER_WRAPCNTTOP_WRAPCNTTOP_Pos (0UL)                    /*!< WRAPCNTTOP (Bit 0)                                    */
#define PROTIMER_WRAPCNTTOP_WRAPCNTTOP_Msk (0xffffffffUL)           /*!< WRAPCNTTOP (Bitfield-Mask: 0xffffffff)                */
/* =======================================================  TOUT0CNT  ======================================================== */
#define PROTIMER_TOUT0CNT_TOUT0PCNT_Pos   (0UL)                     /*!< TOUT0PCNT (Bit 0)                                     */
#define PROTIMER_TOUT0CNT_TOUT0PCNT_Msk   (0xffffUL)                /*!< TOUT0PCNT (Bitfield-Mask: 0xffff)                     */
#define PROTIMER_TOUT0CNT_TOUT0CNT_Pos    (16UL)                    /*!< TOUT0CNT (Bit 16)                                     */
#define PROTIMER_TOUT0CNT_TOUT0CNT_Msk    (0xffff0000UL)            /*!< TOUT0CNT (Bitfield-Mask: 0xffff)                      */
/* ======================================================  TOUT0CNTTOP  ====================================================== */
#define PROTIMER_TOUT0CNTTOP_TOUT0PCNTTOP_Pos (0UL)                 /*!< TOUT0PCNTTOP (Bit 0)                                  */
#define PROTIMER_TOUT0CNTTOP_TOUT0PCNTTOP_Msk (0xffffUL)            /*!< TOUT0PCNTTOP (Bitfield-Mask: 0xffff)                  */
#define PROTIMER_TOUT0CNTTOP_TOUT0CNTTOP_Pos (16UL)                 /*!< TOUT0CNTTOP (Bit 16)                                  */
#define PROTIMER_TOUT0CNTTOP_TOUT0CNTTOP_Msk (0xffff0000UL)         /*!< TOUT0CNTTOP (Bitfield-Mask: 0xffff)                   */
/* =======================================================  TOUT0COMP  ======================================================= */
#define PROTIMER_TOUT0COMP_TOUT0PCNTCOMP_Pos (0UL)                  /*!< TOUT0PCNTCOMP (Bit 0)                                 */
#define PROTIMER_TOUT0COMP_TOUT0PCNTCOMP_Msk (0xffffUL)             /*!< TOUT0PCNTCOMP (Bitfield-Mask: 0xffff)                 */
#define PROTIMER_TOUT0COMP_TOUT0CNTCOMP_Pos (16UL)                  /*!< TOUT0CNTCOMP (Bit 16)                                 */
#define PROTIMER_TOUT0COMP_TOUT0CNTCOMP_Msk (0xffff0000UL)          /*!< TOUT0CNTCOMP (Bitfield-Mask: 0xffff)                  */
/* =======================================================  TOUT1CNT  ======================================================== */
#define PROTIMER_TOUT1CNT_TOUT1PCNT_Pos   (0UL)                     /*!< TOUT1PCNT (Bit 0)                                     */
#define PROTIMER_TOUT1CNT_TOUT1PCNT_Msk   (0xffffUL)                /*!< TOUT1PCNT (Bitfield-Mask: 0xffff)                     */
#define PROTIMER_TOUT1CNT_TOUT1CNT_Pos    (16UL)                    /*!< TOUT1CNT (Bit 16)                                     */
#define PROTIMER_TOUT1CNT_TOUT1CNT_Msk    (0xffff0000UL)            /*!< TOUT1CNT (Bitfield-Mask: 0xffff)                      */
/* ======================================================  TOUT1CNTTOP  ====================================================== */
#define PROTIMER_TOUT1CNTTOP_TOUT1PCNTTOP_Pos (0UL)                 /*!< TOUT1PCNTTOP (Bit 0)                                  */
#define PROTIMER_TOUT1CNTTOP_TOUT1PCNTTOP_Msk (0xffffUL)            /*!< TOUT1PCNTTOP (Bitfield-Mask: 0xffff)                  */
#define PROTIMER_TOUT1CNTTOP_TOUT1CNTTOP_Pos (16UL)                 /*!< TOUT1CNTTOP (Bit 16)                                  */
#define PROTIMER_TOUT1CNTTOP_TOUT1CNTTOP_Msk (0xffff0000UL)         /*!< TOUT1CNTTOP (Bitfield-Mask: 0xffff)                   */
/* =======================================================  TOUT1COMP  ======================================================= */
#define PROTIMER_TOUT1COMP_TOUT1PCNTCOMP_Pos (0UL)                  /*!< TOUT1PCNTCOMP (Bit 0)                                 */
#define PROTIMER_TOUT1COMP_TOUT1PCNTCOMP_Msk (0xffffUL)             /*!< TOUT1PCNTCOMP (Bitfield-Mask: 0xffff)                 */
#define PROTIMER_TOUT1COMP_TOUT1CNTCOMP_Pos (16UL)                  /*!< TOUT1CNTCOMP (Bit 16)                                 */
#define PROTIMER_TOUT1COMP_TOUT1CNTCOMP_Msk (0xffff0000UL)          /*!< TOUT1CNTCOMP (Bitfield-Mask: 0xffff)                  */
/* ========================================================  LBTCTRL  ======================================================== */
#define PROTIMER_LBTCTRL_STARTEXP_Pos     (0UL)                     /*!< STARTEXP (Bit 0)                                      */
#define PROTIMER_LBTCTRL_STARTEXP_Msk     (0xfUL)                   /*!< STARTEXP (Bitfield-Mask: 0x0f)                        */
#define PROTIMER_LBTCTRL_MAXEXP_Pos       (4UL)                     /*!< MAXEXP (Bit 4)                                        */
#define PROTIMER_LBTCTRL_MAXEXP_Msk       (0xf0UL)                  /*!< MAXEXP (Bitfield-Mask: 0x0f)                          */
#define PROTIMER_LBTCTRL_CCADELAY_Pos     (8UL)                     /*!< CCADELAY (Bit 8)                                      */
#define PROTIMER_LBTCTRL_CCADELAY_Msk     (0x1f00UL)                /*!< CCADELAY (Bitfield-Mask: 0x1f)                        */
#define PROTIMER_LBTCTRL_CCAREPEAT_Pos    (16UL)                    /*!< CCAREPEAT (Bit 16)                                    */
#define PROTIMER_LBTCTRL_CCAREPEAT_Msk    (0xf0000UL)               /*!< CCAREPEAT (Bitfield-Mask: 0x0f)                       */
#define PROTIMER_LBTCTRL_FIXEDBACKOFF_Pos (20UL)                    /*!< FIXEDBACKOFF (Bit 20)                                 */
#define PROTIMER_LBTCTRL_FIXEDBACKOFF_Msk (0x100000UL)              /*!< FIXEDBACKOFF (Bitfield-Mask: 0x01)                    */
#define PROTIMER_LBTCTRL_RETRYLIMIT_Pos   (24UL)                    /*!< RETRYLIMIT (Bit 24)                                   */
#define PROTIMER_LBTCTRL_RETRYLIMIT_Msk   (0xf000000UL)             /*!< RETRYLIMIT (Bitfield-Mask: 0x0f)                      */
/* ======================================================  LBTPRSCTRL  ======================================================= */
#define PROTIMER_LBTPRSCTRL_LBTSTARTPRSEN_Pos (8UL)                 /*!< LBTSTARTPRSEN (Bit 8)                                 */
#define PROTIMER_LBTPRSCTRL_LBTSTARTPRSEN_Msk (0x100UL)             /*!< LBTSTARTPRSEN (Bitfield-Mask: 0x01)                   */
#define PROTIMER_LBTPRSCTRL_LBTPAUSEPRSEN_Pos (16UL)                /*!< LBTPAUSEPRSEN (Bit 16)                                */
#define PROTIMER_LBTPRSCTRL_LBTPAUSEPRSEN_Msk (0x10000UL)           /*!< LBTPAUSEPRSEN (Bitfield-Mask: 0x01)                   */
#define PROTIMER_LBTPRSCTRL_LBTSTOPPRSEN_Pos (24UL)                 /*!< LBTSTOPPRSEN (Bit 24)                                 */
#define PROTIMER_LBTPRSCTRL_LBTSTOPPRSEN_Msk (0x1000000UL)          /*!< LBTSTOPPRSEN (Bitfield-Mask: 0x01)                    */
/* =======================================================  LBTSTATE  ======================================================== */
#define PROTIMER_LBTSTATE_TOUT0PCNT_Pos   (0UL)                     /*!< TOUT0PCNT (Bit 0)                                     */
#define PROTIMER_LBTSTATE_TOUT0PCNT_Msk   (0xffffUL)                /*!< TOUT0PCNT (Bitfield-Mask: 0xffff)                     */
#define PROTIMER_LBTSTATE_TOUT0CNT_Pos    (16UL)                    /*!< TOUT0CNT (Bit 16)                                     */
#define PROTIMER_LBTSTATE_TOUT0CNT_Msk    (0xffff0000UL)            /*!< TOUT0CNT (Bitfield-Mask: 0xffff)                      */
/* ========================================================  RANDOM  ========================================================= */
#define PROTIMER_RANDOM_RANDOM_Pos        (0UL)                     /*!< RANDOM (Bit 0)                                        */
#define PROTIMER_RANDOM_RANDOM_Msk        (0xffffUL)                /*!< RANDOM (Bitfield-Mask: 0xffff)                        */
/* ==========================================================  IF  =========================================================== */
#define PROTIMER_IF_PRECNTOF_Pos          (0UL)                     /*!< PRECNTOF (Bit 0)                                      */
#define PROTIMER_IF_PRECNTOF_Msk          (0x1UL)                   /*!< PRECNTOF (Bitfield-Mask: 0x01)                        */
#define PROTIMER_IF_BASECNTOF_Pos         (1UL)                     /*!< BASECNTOF (Bit 1)                                     */
#define PROTIMER_IF_BASECNTOF_Msk         (0x2UL)                   /*!< BASECNTOF (Bitfield-Mask: 0x01)                       */
#define PROTIMER_IF_WRAPCNTOF_Pos         (2UL)                     /*!< WRAPCNTOF (Bit 2)                                     */
#define PROTIMER_IF_WRAPCNTOF_Msk         (0x4UL)                   /*!< WRAPCNTOF (Bitfield-Mask: 0x01)                       */
#define PROTIMER_IF_TOUT0_Pos             (4UL)                     /*!< TOUT0 (Bit 4)                                         */
#define PROTIMER_IF_TOUT0_Msk             (0x10UL)                  /*!< TOUT0 (Bitfield-Mask: 0x01)                           */
#define PROTIMER_IF_TOUT1_Pos             (5UL)                     /*!< TOUT1 (Bit 5)                                         */
#define PROTIMER_IF_TOUT1_Msk             (0x20UL)                  /*!< TOUT1 (Bitfield-Mask: 0x01)                           */
#define PROTIMER_IF_TOUT0MATCH_Pos        (6UL)                     /*!< TOUT0MATCH (Bit 6)                                    */
#define PROTIMER_IF_TOUT0MATCH_Msk        (0x40UL)                  /*!< TOUT0MATCH (Bitfield-Mask: 0x01)                      */
#define PROTIMER_IF_TOUT1MATCH_Pos        (7UL)                     /*!< TOUT1MATCH (Bit 7)                                    */
#define PROTIMER_IF_TOUT1MATCH_Msk        (0x80UL)                  /*!< TOUT1MATCH (Bitfield-Mask: 0x01)                      */
#define PROTIMER_IF_CC0_Pos               (8UL)                     /*!< CC0 (Bit 8)                                           */
#define PROTIMER_IF_CC0_Msk               (0x100UL)                 /*!< CC0 (Bitfield-Mask: 0x01)                             */
#define PROTIMER_IF_CC1_Pos               (9UL)                     /*!< CC1 (Bit 9)                                           */
#define PROTIMER_IF_CC1_Msk               (0x200UL)                 /*!< CC1 (Bitfield-Mask: 0x01)                             */
#define PROTIMER_IF_CC2_Pos               (10UL)                    /*!< CC2 (Bit 10)                                          */
#define PROTIMER_IF_CC2_Msk               (0x400UL)                 /*!< CC2 (Bitfield-Mask: 0x01)                             */
#define PROTIMER_IF_CC3_Pos               (11UL)                    /*!< CC3 (Bit 11)                                          */
#define PROTIMER_IF_CC3_Msk               (0x800UL)                 /*!< CC3 (Bitfield-Mask: 0x01)                             */
#define PROTIMER_IF_CC4_Pos               (12UL)                    /*!< CC4 (Bit 12)                                          */
#define PROTIMER_IF_CC4_Msk               (0x1000UL)                /*!< CC4 (Bitfield-Mask: 0x01)                             */
#define PROTIMER_IF_COF0_Pos              (16UL)                    /*!< COF0 (Bit 16)                                         */
#define PROTIMER_IF_COF0_Msk              (0x10000UL)               /*!< COF0 (Bitfield-Mask: 0x01)                            */
#define PROTIMER_IF_COF1_Pos              (17UL)                    /*!< COF1 (Bit 17)                                         */
#define PROTIMER_IF_COF1_Msk              (0x20000UL)               /*!< COF1 (Bitfield-Mask: 0x01)                            */
#define PROTIMER_IF_COF2_Pos              (18UL)                    /*!< COF2 (Bit 18)                                         */
#define PROTIMER_IF_COF2_Msk              (0x40000UL)               /*!< COF2 (Bitfield-Mask: 0x01)                            */
#define PROTIMER_IF_COF3_Pos              (19UL)                    /*!< COF3 (Bit 19)                                         */
#define PROTIMER_IF_COF3_Msk              (0x80000UL)               /*!< COF3 (Bitfield-Mask: 0x01)                            */
#define PROTIMER_IF_COF4_Pos              (20UL)                    /*!< COF4 (Bit 20)                                         */
#define PROTIMER_IF_COF4_Msk              (0x100000UL)              /*!< COF4 (Bitfield-Mask: 0x01)                            */
#define PROTIMER_IF_LBTSUCCESS_Pos        (24UL)                    /*!< LBTSUCCESS (Bit 24)                                   */
#define PROTIMER_IF_LBTSUCCESS_Msk        (0x1000000UL)             /*!< LBTSUCCESS (Bitfield-Mask: 0x01)                      */
#define PROTIMER_IF_LBTFAILURE_Pos        (25UL)                    /*!< LBTFAILURE (Bit 25)                                   */
#define PROTIMER_IF_LBTFAILURE_Msk        (0x2000000UL)             /*!< LBTFAILURE (Bitfield-Mask: 0x01)                      */
#define PROTIMER_IF_LBTPAUSED_Pos         (26UL)                    /*!< LBTPAUSED (Bit 26)                                    */
#define PROTIMER_IF_LBTPAUSED_Msk         (0x4000000UL)             /*!< LBTPAUSED (Bitfield-Mask: 0x01)                       */
#define PROTIMER_IF_LBTRETRY_Pos          (27UL)                    /*!< LBTRETRY (Bit 27)                                     */
#define PROTIMER_IF_LBTRETRY_Msk          (0x8000000UL)             /*!< LBTRETRY (Bitfield-Mask: 0x01)                        */
#define PROTIMER_IF_RTCCSYNCHED_Pos       (28UL)                    /*!< RTCCSYNCHED (Bit 28)                                  */
#define PROTIMER_IF_RTCCSYNCHED_Msk       (0x10000000UL)            /*!< RTCCSYNCHED (Bitfield-Mask: 0x01)                     */
#define PROTIMER_IF_TOUT0MATCHLBT_Pos     (29UL)                    /*!< TOUT0MATCHLBT (Bit 29)                                */
#define PROTIMER_IF_TOUT0MATCHLBT_Msk     (0x20000000UL)            /*!< TOUT0MATCHLBT (Bitfield-Mask: 0x01)                   */
/* ==========================================================  IFS  ========================================================== */
#define PROTIMER_IFS_PRECNTOF_Pos         (0UL)                     /*!< PRECNTOF (Bit 0)                                      */
#define PROTIMER_IFS_PRECNTOF_Msk         (0x1UL)                   /*!< PRECNTOF (Bitfield-Mask: 0x01)                        */
#define PROTIMER_IFS_BASECNTOF_Pos        (1UL)                     /*!< BASECNTOF (Bit 1)                                     */
#define PROTIMER_IFS_BASECNTOF_Msk        (0x2UL)                   /*!< BASECNTOF (Bitfield-Mask: 0x01)                       */
#define PROTIMER_IFS_WRAPCNTOF_Pos        (2UL)                     /*!< WRAPCNTOF (Bit 2)                                     */
#define PROTIMER_IFS_WRAPCNTOF_Msk        (0x4UL)                   /*!< WRAPCNTOF (Bitfield-Mask: 0x01)                       */
#define PROTIMER_IFS_TOUT0_Pos            (4UL)                     /*!< TOUT0 (Bit 4)                                         */
#define PROTIMER_IFS_TOUT0_Msk            (0x10UL)                  /*!< TOUT0 (Bitfield-Mask: 0x01)                           */
#define PROTIMER_IFS_TOUT1_Pos            (5UL)                     /*!< TOUT1 (Bit 5)                                         */
#define PROTIMER_IFS_TOUT1_Msk            (0x20UL)                  /*!< TOUT1 (Bitfield-Mask: 0x01)                           */
#define PROTIMER_IFS_TOUT0MATCH_Pos       (6UL)                     /*!< TOUT0MATCH (Bit 6)                                    */
#define PROTIMER_IFS_TOUT0MATCH_Msk       (0x40UL)                  /*!< TOUT0MATCH (Bitfield-Mask: 0x01)                      */
#define PROTIMER_IFS_TOUT1MATCH_Pos       (7UL)                     /*!< TOUT1MATCH (Bit 7)                                    */
#define PROTIMER_IFS_TOUT1MATCH_Msk       (0x80UL)                  /*!< TOUT1MATCH (Bitfield-Mask: 0x01)                      */
#define PROTIMER_IFS_CC0_Pos              (8UL)                     /*!< CC0 (Bit 8)                                           */
#define PROTIMER_IFS_CC0_Msk              (0x100UL)                 /*!< CC0 (Bitfield-Mask: 0x01)                             */
#define PROTIMER_IFS_CC1_Pos              (9UL)                     /*!< CC1 (Bit 9)                                           */
#define PROTIMER_IFS_CC1_Msk              (0x200UL)                 /*!< CC1 (Bitfield-Mask: 0x01)                             */
#define PROTIMER_IFS_CC2_Pos              (10UL)                    /*!< CC2 (Bit 10)                                          */
#define PROTIMER_IFS_CC2_Msk              (0x400UL)                 /*!< CC2 (Bitfield-Mask: 0x01)                             */
#define PROTIMER_IFS_CC3_Pos              (11UL)                    /*!< CC3 (Bit 11)                                          */
#define PROTIMER_IFS_CC3_Msk              (0x800UL)                 /*!< CC3 (Bitfield-Mask: 0x01)                             */
#define PROTIMER_IFS_CC4_Pos              (12UL)                    /*!< CC4 (Bit 12)                                          */
#define PROTIMER_IFS_CC4_Msk              (0x1000UL)                /*!< CC4 (Bitfield-Mask: 0x01)                             */
#define PROTIMER_IFS_COF0_Pos             (16UL)                    /*!< COF0 (Bit 16)                                         */
#define PROTIMER_IFS_COF0_Msk             (0x10000UL)               /*!< COF0 (Bitfield-Mask: 0x01)                            */
#define PROTIMER_IFS_COF1_Pos             (17UL)                    /*!< COF1 (Bit 17)                                         */
#define PROTIMER_IFS_COF1_Msk             (0x20000UL)               /*!< COF1 (Bitfield-Mask: 0x01)                            */
#define PROTIMER_IFS_COF2_Pos             (18UL)                    /*!< COF2 (Bit 18)                                         */
#define PROTIMER_IFS_COF2_Msk             (0x40000UL)               /*!< COF2 (Bitfield-Mask: 0x01)                            */
#define PROTIMER_IFS_COF3_Pos             (19UL)                    /*!< COF3 (Bit 19)                                         */
#define PROTIMER_IFS_COF3_Msk             (0x80000UL)               /*!< COF3 (Bitfield-Mask: 0x01)                            */
#define PROTIMER_IFS_COF4_Pos             (20UL)                    /*!< COF4 (Bit 20)                                         */
#define PROTIMER_IFS_COF4_Msk             (0x100000UL)              /*!< COF4 (Bitfield-Mask: 0x01)                            */
#define PROTIMER_IFS_LBTSUCCESS_Pos       (24UL)                    /*!< LBTSUCCESS (Bit 24)                                   */
#define PROTIMER_IFS_LBTSUCCESS_Msk       (0x1000000UL)             /*!< LBTSUCCESS (Bitfield-Mask: 0x01)                      */
#define PROTIMER_IFS_LBTFAILURE_Pos       (25UL)                    /*!< LBTFAILURE (Bit 25)                                   */
#define PROTIMER_IFS_LBTFAILURE_Msk       (0x2000000UL)             /*!< LBTFAILURE (Bitfield-Mask: 0x01)                      */
#define PROTIMER_IFS_LBTPAUSED_Pos        (26UL)                    /*!< LBTPAUSED (Bit 26)                                    */
#define PROTIMER_IFS_LBTPAUSED_Msk        (0x4000000UL)             /*!< LBTPAUSED (Bitfield-Mask: 0x01)                       */
#define PROTIMER_IFS_LBTRETRY_Pos         (27UL)                    /*!< LBTRETRY (Bit 27)                                     */
#define PROTIMER_IFS_LBTRETRY_Msk         (0x8000000UL)             /*!< LBTRETRY (Bitfield-Mask: 0x01)                        */
#define PROTIMER_IFS_RTCCSYNCHED_Pos      (28UL)                    /*!< RTCCSYNCHED (Bit 28)                                  */
#define PROTIMER_IFS_RTCCSYNCHED_Msk      (0x10000000UL)            /*!< RTCCSYNCHED (Bitfield-Mask: 0x01)                     */
#define PROTIMER_IFS_TOUT0MATCHLBT_Pos    (29UL)                    /*!< TOUT0MATCHLBT (Bit 29)                                */
#define PROTIMER_IFS_TOUT0MATCHLBT_Msk    (0x20000000UL)            /*!< TOUT0MATCHLBT (Bitfield-Mask: 0x01)                   */
/* ==========================================================  IFC  ========================================================== */
#define PROTIMER_IFC_PRECNTOF_Pos         (0UL)                     /*!< PRECNTOF (Bit 0)                                      */
#define PROTIMER_IFC_PRECNTOF_Msk         (0x1UL)                   /*!< PRECNTOF (Bitfield-Mask: 0x01)                        */
#define PROTIMER_IFC_BASECNTOF_Pos        (1UL)                     /*!< BASECNTOF (Bit 1)                                     */
#define PROTIMER_IFC_BASECNTOF_Msk        (0x2UL)                   /*!< BASECNTOF (Bitfield-Mask: 0x01)                       */
#define PROTIMER_IFC_WRAPCNTOF_Pos        (2UL)                     /*!< WRAPCNTOF (Bit 2)                                     */
#define PROTIMER_IFC_WRAPCNTOF_Msk        (0x4UL)                   /*!< WRAPCNTOF (Bitfield-Mask: 0x01)                       */
#define PROTIMER_IFC_TOUT0_Pos            (4UL)                     /*!< TOUT0 (Bit 4)                                         */
#define PROTIMER_IFC_TOUT0_Msk            (0x10UL)                  /*!< TOUT0 (Bitfield-Mask: 0x01)                           */
#define PROTIMER_IFC_TOUT1_Pos            (5UL)                     /*!< TOUT1 (Bit 5)                                         */
#define PROTIMER_IFC_TOUT1_Msk            (0x20UL)                  /*!< TOUT1 (Bitfield-Mask: 0x01)                           */
#define PROTIMER_IFC_TOUT0MATCH_Pos       (6UL)                     /*!< TOUT0MATCH (Bit 6)                                    */
#define PROTIMER_IFC_TOUT0MATCH_Msk       (0x40UL)                  /*!< TOUT0MATCH (Bitfield-Mask: 0x01)                      */
#define PROTIMER_IFC_TOUT1MATCH_Pos       (7UL)                     /*!< TOUT1MATCH (Bit 7)                                    */
#define PROTIMER_IFC_TOUT1MATCH_Msk       (0x80UL)                  /*!< TOUT1MATCH (Bitfield-Mask: 0x01)                      */
#define PROTIMER_IFC_CC0_Pos              (8UL)                     /*!< CC0 (Bit 8)                                           */
#define PROTIMER_IFC_CC0_Msk              (0x100UL)                 /*!< CC0 (Bitfield-Mask: 0x01)                             */
#define PROTIMER_IFC_CC1_Pos              (9UL)                     /*!< CC1 (Bit 9)                                           */
#define PROTIMER_IFC_CC1_Msk              (0x200UL)                 /*!< CC1 (Bitfield-Mask: 0x01)                             */
#define PROTIMER_IFC_CC2_Pos              (10UL)                    /*!< CC2 (Bit 10)                                          */
#define PROTIMER_IFC_CC2_Msk              (0x400UL)                 /*!< CC2 (Bitfield-Mask: 0x01)                             */
#define PROTIMER_IFC_CC3_Pos              (11UL)                    /*!< CC3 (Bit 11)                                          */
#define PROTIMER_IFC_CC3_Msk              (0x800UL)                 /*!< CC3 (Bitfield-Mask: 0x01)                             */
#define PROTIMER_IFC_CC4_Pos              (12UL)                    /*!< CC4 (Bit 12)                                          */
#define PROTIMER_IFC_CC4_Msk              (0x1000UL)                /*!< CC4 (Bitfield-Mask: 0x01)                             */
#define PROTIMER_IFC_COF0_Pos             (16UL)                    /*!< COF0 (Bit 16)                                         */
#define PROTIMER_IFC_COF0_Msk             (0x10000UL)               /*!< COF0 (Bitfield-Mask: 0x01)                            */
#define PROTIMER_IFC_COF1_Pos             (17UL)                    /*!< COF1 (Bit 17)                                         */
#define PROTIMER_IFC_COF1_Msk             (0x20000UL)               /*!< COF1 (Bitfield-Mask: 0x01)                            */
#define PROTIMER_IFC_COF2_Pos             (18UL)                    /*!< COF2 (Bit 18)                                         */
#define PROTIMER_IFC_COF2_Msk             (0x40000UL)               /*!< COF2 (Bitfield-Mask: 0x01)                            */
#define PROTIMER_IFC_COF3_Pos             (19UL)                    /*!< COF3 (Bit 19)                                         */
#define PROTIMER_IFC_COF3_Msk             (0x80000UL)               /*!< COF3 (Bitfield-Mask: 0x01)                            */
#define PROTIMER_IFC_COF4_Pos             (20UL)                    /*!< COF4 (Bit 20)                                         */
#define PROTIMER_IFC_COF4_Msk             (0x100000UL)              /*!< COF4 (Bitfield-Mask: 0x01)                            */
#define PROTIMER_IFC_LBTSUCCESS_Pos       (24UL)                    /*!< LBTSUCCESS (Bit 24)                                   */
#define PROTIMER_IFC_LBTSUCCESS_Msk       (0x1000000UL)             /*!< LBTSUCCESS (Bitfield-Mask: 0x01)                      */
#define PROTIMER_IFC_LBTFAILURE_Pos       (25UL)                    /*!< LBTFAILURE (Bit 25)                                   */
#define PROTIMER_IFC_LBTFAILURE_Msk       (0x2000000UL)             /*!< LBTFAILURE (Bitfield-Mask: 0x01)                      */
#define PROTIMER_IFC_LBTPAUSED_Pos        (26UL)                    /*!< LBTPAUSED (Bit 26)                                    */
#define PROTIMER_IFC_LBTPAUSED_Msk        (0x4000000UL)             /*!< LBTPAUSED (Bitfield-Mask: 0x01)                       */
#define PROTIMER_IFC_LBTRETRY_Pos         (27UL)                    /*!< LBTRETRY (Bit 27)                                     */
#define PROTIMER_IFC_LBTRETRY_Msk         (0x8000000UL)             /*!< LBTRETRY (Bitfield-Mask: 0x01)                        */
#define PROTIMER_IFC_RTCCSYNCHED_Pos      (28UL)                    /*!< RTCCSYNCHED (Bit 28)                                  */
#define PROTIMER_IFC_RTCCSYNCHED_Msk      (0x10000000UL)            /*!< RTCCSYNCHED (Bitfield-Mask: 0x01)                     */
#define PROTIMER_IFC_TOUT0MATCHLBT_Pos    (29UL)                    /*!< TOUT0MATCHLBT (Bit 29)                                */
#define PROTIMER_IFC_TOUT0MATCHLBT_Msk    (0x20000000UL)            /*!< TOUT0MATCHLBT (Bitfield-Mask: 0x01)                   */
/* ==========================================================  IEN  ========================================================== */
#define PROTIMER_IEN_PRECNTOF_Pos         (0UL)                     /*!< PRECNTOF (Bit 0)                                      */
#define PROTIMER_IEN_PRECNTOF_Msk         (0x1UL)                   /*!< PRECNTOF (Bitfield-Mask: 0x01)                        */
#define PROTIMER_IEN_BASECNTOF_Pos        (1UL)                     /*!< BASECNTOF (Bit 1)                                     */
#define PROTIMER_IEN_BASECNTOF_Msk        (0x2UL)                   /*!< BASECNTOF (Bitfield-Mask: 0x01)                       */
#define PROTIMER_IEN_WRAPCNTOF_Pos        (2UL)                     /*!< WRAPCNTOF (Bit 2)                                     */
#define PROTIMER_IEN_WRAPCNTOF_Msk        (0x4UL)                   /*!< WRAPCNTOF (Bitfield-Mask: 0x01)                       */
#define PROTIMER_IEN_TOUT0_Pos            (4UL)                     /*!< TOUT0 (Bit 4)                                         */
#define PROTIMER_IEN_TOUT0_Msk            (0x10UL)                  /*!< TOUT0 (Bitfield-Mask: 0x01)                           */
#define PROTIMER_IEN_TOUT1_Pos            (5UL)                     /*!< TOUT1 (Bit 5)                                         */
#define PROTIMER_IEN_TOUT1_Msk            (0x20UL)                  /*!< TOUT1 (Bitfield-Mask: 0x01)                           */
#define PROTIMER_IEN_TOUT0MATCH_Pos       (6UL)                     /*!< TOUT0MATCH (Bit 6)                                    */
#define PROTIMER_IEN_TOUT0MATCH_Msk       (0x40UL)                  /*!< TOUT0MATCH (Bitfield-Mask: 0x01)                      */
#define PROTIMER_IEN_TOUT1MATCH_Pos       (7UL)                     /*!< TOUT1MATCH (Bit 7)                                    */
#define PROTIMER_IEN_TOUT1MATCH_Msk       (0x80UL)                  /*!< TOUT1MATCH (Bitfield-Mask: 0x01)                      */
#define PROTIMER_IEN_CC0_Pos              (8UL)                     /*!< CC0 (Bit 8)                                           */
#define PROTIMER_IEN_CC0_Msk              (0x100UL)                 /*!< CC0 (Bitfield-Mask: 0x01)                             */
#define PROTIMER_IEN_CC1_Pos              (9UL)                     /*!< CC1 (Bit 9)                                           */
#define PROTIMER_IEN_CC1_Msk              (0x200UL)                 /*!< CC1 (Bitfield-Mask: 0x01)                             */
#define PROTIMER_IEN_CC2_Pos              (10UL)                    /*!< CC2 (Bit 10)                                          */
#define PROTIMER_IEN_CC2_Msk              (0x400UL)                 /*!< CC2 (Bitfield-Mask: 0x01)                             */
#define PROTIMER_IEN_CC3_Pos              (11UL)                    /*!< CC3 (Bit 11)                                          */
#define PROTIMER_IEN_CC3_Msk              (0x800UL)                 /*!< CC3 (Bitfield-Mask: 0x01)                             */
#define PROTIMER_IEN_CC4_Pos              (12UL)                    /*!< CC4 (Bit 12)                                          */
#define PROTIMER_IEN_CC4_Msk              (0x1000UL)                /*!< CC4 (Bitfield-Mask: 0x01)                             */
#define PROTIMER_IEN_COF0_Pos             (16UL)                    /*!< COF0 (Bit 16)                                         */
#define PROTIMER_IEN_COF0_Msk             (0x10000UL)               /*!< COF0 (Bitfield-Mask: 0x01)                            */
#define PROTIMER_IEN_COF1_Pos             (17UL)                    /*!< COF1 (Bit 17)                                         */
#define PROTIMER_IEN_COF1_Msk             (0x20000UL)               /*!< COF1 (Bitfield-Mask: 0x01)                            */
#define PROTIMER_IEN_COF2_Pos             (18UL)                    /*!< COF2 (Bit 18)                                         */
#define PROTIMER_IEN_COF2_Msk             (0x40000UL)               /*!< COF2 (Bitfield-Mask: 0x01)                            */
#define PROTIMER_IEN_COF3_Pos             (19UL)                    /*!< COF3 (Bit 19)                                         */
#define PROTIMER_IEN_COF3_Msk             (0x80000UL)               /*!< COF3 (Bitfield-Mask: 0x01)                            */
#define PROTIMER_IEN_COF4_Pos             (20UL)                    /*!< COF4 (Bit 20)                                         */
#define PROTIMER_IEN_COF4_Msk             (0x100000UL)              /*!< COF4 (Bitfield-Mask: 0x01)                            */
#define PROTIMER_IEN_LBTSUCCESS_Pos       (24UL)                    /*!< LBTSUCCESS (Bit 24)                                   */
#define PROTIMER_IEN_LBTSUCCESS_Msk       (0x1000000UL)             /*!< LBTSUCCESS (Bitfield-Mask: 0x01)                      */
#define PROTIMER_IEN_LBTFAILURE_Pos       (25UL)                    /*!< LBTFAILURE (Bit 25)                                   */
#define PROTIMER_IEN_LBTFAILURE_Msk       (0x2000000UL)             /*!< LBTFAILURE (Bitfield-Mask: 0x01)                      */
#define PROTIMER_IEN_LBTPAUSED_Pos        (26UL)                    /*!< LBTPAUSED (Bit 26)                                    */
#define PROTIMER_IEN_LBTPAUSED_Msk        (0x4000000UL)             /*!< LBTPAUSED (Bitfield-Mask: 0x01)                       */
#define PROTIMER_IEN_LBTRETRY_Pos         (27UL)                    /*!< LBTRETRY (Bit 27)                                     */
#define PROTIMER_IEN_LBTRETRY_Msk         (0x8000000UL)             /*!< LBTRETRY (Bitfield-Mask: 0x01)                        */
#define PROTIMER_IEN_RTCCSYNCHED_Pos      (28UL)                    /*!< RTCCSYNCHED (Bit 28)                                  */
#define PROTIMER_IEN_RTCCSYNCHED_Msk      (0x10000000UL)            /*!< RTCCSYNCHED (Bitfield-Mask: 0x01)                     */
#define PROTIMER_IEN_TOUT0MATCHLBT_Pos    (29UL)                    /*!< TOUT0MATCHLBT (Bit 29)                                */
#define PROTIMER_IEN_TOUT0MATCHLBT_Msk    (0x20000000UL)            /*!< TOUT0MATCHLBT (Bitfield-Mask: 0x01)                   */
/* ========================================================  RXCTRL  ========================================================= */
#define PROTIMER_RXCTRL_RXSETEVENT1_Pos   (0UL)                     /*!< RXSETEVENT1 (Bit 0)                                   */
#define PROTIMER_RXCTRL_RXSETEVENT1_Msk   (0x1fUL)                  /*!< RXSETEVENT1 (Bitfield-Mask: 0x1f)                     */
#define PROTIMER_RXCTRL_RXSETEVENT2_Pos   (8UL)                     /*!< RXSETEVENT2 (Bit 8)                                   */
#define PROTIMER_RXCTRL_RXSETEVENT2_Msk   (0x1f00UL)                /*!< RXSETEVENT2 (Bitfield-Mask: 0x1f)                     */
#define PROTIMER_RXCTRL_RXCLREVENT1_Pos   (16UL)                    /*!< RXCLREVENT1 (Bit 16)                                  */
#define PROTIMER_RXCTRL_RXCLREVENT1_Msk   (0x1f0000UL)              /*!< RXCLREVENT1 (Bitfield-Mask: 0x1f)                     */
#define PROTIMER_RXCTRL_RXCLREVENT2_Pos   (24UL)                    /*!< RXCLREVENT2 (Bit 24)                                  */
#define PROTIMER_RXCTRL_RXCLREVENT2_Msk   (0x1f000000UL)            /*!< RXCLREVENT2 (Bitfield-Mask: 0x1f)                     */
/* ========================================================  TXCTRL  ========================================================= */
#define PROTIMER_TXCTRL_TXSETEVENT1_Pos   (0UL)                     /*!< TXSETEVENT1 (Bit 0)                                   */
#define PROTIMER_TXCTRL_TXSETEVENT1_Msk   (0x1fUL)                  /*!< TXSETEVENT1 (Bitfield-Mask: 0x1f)                     */
#define PROTIMER_TXCTRL_TXSETEVENT2_Pos   (8UL)                     /*!< TXSETEVENT2 (Bit 8)                                   */
#define PROTIMER_TXCTRL_TXSETEVENT2_Msk   (0x1f00UL)                /*!< TXSETEVENT2 (Bitfield-Mask: 0x1f)                     */
/* =======================================================  CC0_CTRL  ======================================================== */
#define PROTIMER_CC0_CTRL_ENABLE_Pos      (0UL)                     /*!< ENABLE (Bit 0)                                        */
#define PROTIMER_CC0_CTRL_ENABLE_Msk      (0x1UL)                   /*!< ENABLE (Bitfield-Mask: 0x01)                          */
#define PROTIMER_CC0_CTRL_CCMODE_Pos      (1UL)                     /*!< CCMODE (Bit 1)                                        */
#define PROTIMER_CC0_CTRL_CCMODE_Msk      (0x2UL)                   /*!< CCMODE (Bitfield-Mask: 0x01)                          */
#define PROTIMER_CC0_CTRL_PREMATCHEN_Pos  (2UL)                     /*!< PREMATCHEN (Bit 2)                                    */
#define PROTIMER_CC0_CTRL_PREMATCHEN_Msk  (0x4UL)                   /*!< PREMATCHEN (Bitfield-Mask: 0x01)                      */
#define PROTIMER_CC0_CTRL_BASEMATCHEN_Pos (3UL)                     /*!< BASEMATCHEN (Bit 3)                                   */
#define PROTIMER_CC0_CTRL_BASEMATCHEN_Msk (0x8UL)                   /*!< BASEMATCHEN (Bitfield-Mask: 0x01)                     */
#define PROTIMER_CC0_CTRL_WRAPMATCHEN_Pos (4UL)                     /*!< WRAPMATCHEN (Bit 4)                                   */
#define PROTIMER_CC0_CTRL_WRAPMATCHEN_Msk (0x10UL)                  /*!< WRAPMATCHEN (Bitfield-Mask: 0x01)                     */
#define PROTIMER_CC0_CTRL_OIST_Pos        (5UL)                     /*!< OIST (Bit 5)                                          */
#define PROTIMER_CC0_CTRL_OIST_Msk        (0x20UL)                  /*!< OIST (Bitfield-Mask: 0x01)                            */
#define PROTIMER_CC0_CTRL_OUTINV_Pos      (6UL)                     /*!< OUTINV (Bit 6)                                        */
#define PROTIMER_CC0_CTRL_OUTINV_Msk      (0x40UL)                  /*!< OUTINV (Bitfield-Mask: 0x01)                          */
#define PROTIMER_CC0_CTRL_MOA_Pos         (8UL)                     /*!< MOA (Bit 8)                                           */
#define PROTIMER_CC0_CTRL_MOA_Msk         (0x300UL)                 /*!< MOA (Bitfield-Mask: 0x03)                             */
#define PROTIMER_CC0_CTRL_OFOA_Pos        (10UL)                    /*!< OFOA (Bit 10)                                         */
#define PROTIMER_CC0_CTRL_OFOA_Msk        (0xc00UL)                 /*!< OFOA (Bitfield-Mask: 0x03)                            */
#define PROTIMER_CC0_CTRL_OFSEL_Pos       (12UL)                    /*!< OFSEL (Bit 12)                                        */
#define PROTIMER_CC0_CTRL_OFSEL_Msk       (0x3000UL)                /*!< OFSEL (Bitfield-Mask: 0x03)                           */
#define PROTIMER_CC0_CTRL_PRSCONF_Pos     (14UL)                    /*!< PRSCONF (Bit 14)                                      */
#define PROTIMER_CC0_CTRL_PRSCONF_Msk     (0x4000UL)                /*!< PRSCONF (Bitfield-Mask: 0x01)                         */
#define PROTIMER_CC0_CTRL_INSEL_Pos       (21UL)                    /*!< INSEL (Bit 21)                                        */
#define PROTIMER_CC0_CTRL_INSEL_Msk       (0x1e00000UL)             /*!< INSEL (Bitfield-Mask: 0x0f)                           */
#define PROTIMER_CC0_CTRL_ICEDGE_Pos      (25UL)                    /*!< ICEDGE (Bit 25)                                       */
#define PROTIMER_CC0_CTRL_ICEDGE_Msk      (0x6000000UL)             /*!< ICEDGE (Bitfield-Mask: 0x03)                          */
/* ========================================================  CC0_PRE  ======================================================== */
#define PROTIMER_CC0_PRE_PRE_Pos          (0UL)                     /*!< PRE (Bit 0)                                           */
#define PROTIMER_CC0_PRE_PRE_Msk          (0xffffUL)                /*!< PRE (Bitfield-Mask: 0xffff)                           */
/* =======================================================  CC0_BASE  ======================================================== */
#define PROTIMER_CC0_BASE_BASE_Pos        (0UL)                     /*!< BASE (Bit 0)                                          */
#define PROTIMER_CC0_BASE_BASE_Msk        (0xffffUL)                /*!< BASE (Bitfield-Mask: 0xffff)                          */
/* =======================================================  CC0_WRAP  ======================================================== */
#define PROTIMER_CC0_WRAP_WRAP_Pos        (0UL)                     /*!< WRAP (Bit 0)                                          */
#define PROTIMER_CC0_WRAP_WRAP_Msk        (0xffffffffUL)            /*!< WRAP (Bitfield-Mask: 0xffffffff)                      */
/* =======================================================  CC1_CTRL  ======================================================== */
#define PROTIMER_CC1_CTRL_ENABLE_Pos      (0UL)                     /*!< ENABLE (Bit 0)                                        */
#define PROTIMER_CC1_CTRL_ENABLE_Msk      (0x1UL)                   /*!< ENABLE (Bitfield-Mask: 0x01)                          */
#define PROTIMER_CC1_CTRL_CCMODE_Pos      (1UL)                     /*!< CCMODE (Bit 1)                                        */
#define PROTIMER_CC1_CTRL_CCMODE_Msk      (0x2UL)                   /*!< CCMODE (Bitfield-Mask: 0x01)                          */
#define PROTIMER_CC1_CTRL_PREMATCHEN_Pos  (2UL)                     /*!< PREMATCHEN (Bit 2)                                    */
#define PROTIMER_CC1_CTRL_PREMATCHEN_Msk  (0x4UL)                   /*!< PREMATCHEN (Bitfield-Mask: 0x01)                      */
#define PROTIMER_CC1_CTRL_BASEMATCHEN_Pos (3UL)                     /*!< BASEMATCHEN (Bit 3)                                   */
#define PROTIMER_CC1_CTRL_BASEMATCHEN_Msk (0x8UL)                   /*!< BASEMATCHEN (Bitfield-Mask: 0x01)                     */
#define PROTIMER_CC1_CTRL_WRAPMATCHEN_Pos (4UL)                     /*!< WRAPMATCHEN (Bit 4)                                   */
#define PROTIMER_CC1_CTRL_WRAPMATCHEN_Msk (0x10UL)                  /*!< WRAPMATCHEN (Bitfield-Mask: 0x01)                     */
#define PROTIMER_CC1_CTRL_OIST_Pos        (5UL)                     /*!< OIST (Bit 5)                                          */
#define PROTIMER_CC1_CTRL_OIST_Msk        (0x20UL)                  /*!< OIST (Bitfield-Mask: 0x01)                            */
#define PROTIMER_CC1_CTRL_OUTINV_Pos      (6UL)                     /*!< OUTINV (Bit 6)                                        */
#define PROTIMER_CC1_CTRL_OUTINV_Msk      (0x40UL)                  /*!< OUTINV (Bitfield-Mask: 0x01)                          */
#define PROTIMER_CC1_CTRL_MOA_Pos         (8UL)                     /*!< MOA (Bit 8)                                           */
#define PROTIMER_CC1_CTRL_MOA_Msk         (0x300UL)                 /*!< MOA (Bitfield-Mask: 0x03)                             */
#define PROTIMER_CC1_CTRL_OFOA_Pos        (10UL)                    /*!< OFOA (Bit 10)                                         */
#define PROTIMER_CC1_CTRL_OFOA_Msk        (0xc00UL)                 /*!< OFOA (Bitfield-Mask: 0x03)                            */
#define PROTIMER_CC1_CTRL_OFSEL_Pos       (12UL)                    /*!< OFSEL (Bit 12)                                        */
#define PROTIMER_CC1_CTRL_OFSEL_Msk       (0x3000UL)                /*!< OFSEL (Bitfield-Mask: 0x03)                           */
#define PROTIMER_CC1_CTRL_PRSCONF_Pos     (14UL)                    /*!< PRSCONF (Bit 14)                                      */
#define PROTIMER_CC1_CTRL_PRSCONF_Msk     (0x4000UL)                /*!< PRSCONF (Bitfield-Mask: 0x01)                         */
#define PROTIMER_CC1_CTRL_INSEL_Pos       (21UL)                    /*!< INSEL (Bit 21)                                        */
#define PROTIMER_CC1_CTRL_INSEL_Msk       (0x1e00000UL)             /*!< INSEL (Bitfield-Mask: 0x0f)                           */
#define PROTIMER_CC1_CTRL_ICEDGE_Pos      (25UL)                    /*!< ICEDGE (Bit 25)                                       */
#define PROTIMER_CC1_CTRL_ICEDGE_Msk      (0x6000000UL)             /*!< ICEDGE (Bitfield-Mask: 0x03)                          */
/* ========================================================  CC1_PRE  ======================================================== */
#define PROTIMER_CC1_PRE_PRE_Pos          (0UL)                     /*!< PRE (Bit 0)                                           */
#define PROTIMER_CC1_PRE_PRE_Msk          (0xffffUL)                /*!< PRE (Bitfield-Mask: 0xffff)                           */
/* =======================================================  CC1_BASE  ======================================================== */
#define PROTIMER_CC1_BASE_BASE_Pos        (0UL)                     /*!< BASE (Bit 0)                                          */
#define PROTIMER_CC1_BASE_BASE_Msk        (0xffffUL)                /*!< BASE (Bitfield-Mask: 0xffff)                          */
/* =======================================================  CC1_WRAP  ======================================================== */
#define PROTIMER_CC1_WRAP_WRAP_Pos        (0UL)                     /*!< WRAP (Bit 0)                                          */
#define PROTIMER_CC1_WRAP_WRAP_Msk        (0xffffffffUL)            /*!< WRAP (Bitfield-Mask: 0xffffffff)                      */
/* =======================================================  CC2_CTRL  ======================================================== */
#define PROTIMER_CC2_CTRL_ENABLE_Pos      (0UL)                     /*!< ENABLE (Bit 0)                                        */
#define PROTIMER_CC2_CTRL_ENABLE_Msk      (0x1UL)                   /*!< ENABLE (Bitfield-Mask: 0x01)                          */
#define PROTIMER_CC2_CTRL_CCMODE_Pos      (1UL)                     /*!< CCMODE (Bit 1)                                        */
#define PROTIMER_CC2_CTRL_CCMODE_Msk      (0x2UL)                   /*!< CCMODE (Bitfield-Mask: 0x01)                          */
#define PROTIMER_CC2_CTRL_PREMATCHEN_Pos  (2UL)                     /*!< PREMATCHEN (Bit 2)                                    */
#define PROTIMER_CC2_CTRL_PREMATCHEN_Msk  (0x4UL)                   /*!< PREMATCHEN (Bitfield-Mask: 0x01)                      */
#define PROTIMER_CC2_CTRL_BASEMATCHEN_Pos (3UL)                     /*!< BASEMATCHEN (Bit 3)                                   */
#define PROTIMER_CC2_CTRL_BASEMATCHEN_Msk (0x8UL)                   /*!< BASEMATCHEN (Bitfield-Mask: 0x01)                     */
#define PROTIMER_CC2_CTRL_WRAPMATCHEN_Pos (4UL)                     /*!< WRAPMATCHEN (Bit 4)                                   */
#define PROTIMER_CC2_CTRL_WRAPMATCHEN_Msk (0x10UL)                  /*!< WRAPMATCHEN (Bitfield-Mask: 0x01)                     */
#define PROTIMER_CC2_CTRL_OIST_Pos        (5UL)                     /*!< OIST (Bit 5)                                          */
#define PROTIMER_CC2_CTRL_OIST_Msk        (0x20UL)                  /*!< OIST (Bitfield-Mask: 0x01)                            */
#define PROTIMER_CC2_CTRL_OUTINV_Pos      (6UL)                     /*!< OUTINV (Bit 6)                                        */
#define PROTIMER_CC2_CTRL_OUTINV_Msk      (0x40UL)                  /*!< OUTINV (Bitfield-Mask: 0x01)                          */
#define PROTIMER_CC2_CTRL_MOA_Pos         (8UL)                     /*!< MOA (Bit 8)                                           */
#define PROTIMER_CC2_CTRL_MOA_Msk         (0x300UL)                 /*!< MOA (Bitfield-Mask: 0x03)                             */
#define PROTIMER_CC2_CTRL_OFOA_Pos        (10UL)                    /*!< OFOA (Bit 10)                                         */
#define PROTIMER_CC2_CTRL_OFOA_Msk        (0xc00UL)                 /*!< OFOA (Bitfield-Mask: 0x03)                            */
#define PROTIMER_CC2_CTRL_OFSEL_Pos       (12UL)                    /*!< OFSEL (Bit 12)                                        */
#define PROTIMER_CC2_CTRL_OFSEL_Msk       (0x3000UL)                /*!< OFSEL (Bitfield-Mask: 0x03)                           */
#define PROTIMER_CC2_CTRL_PRSCONF_Pos     (14UL)                    /*!< PRSCONF (Bit 14)                                      */
#define PROTIMER_CC2_CTRL_PRSCONF_Msk     (0x4000UL)                /*!< PRSCONF (Bitfield-Mask: 0x01)                         */
#define PROTIMER_CC2_CTRL_INSEL_Pos       (21UL)                    /*!< INSEL (Bit 21)                                        */
#define PROTIMER_CC2_CTRL_INSEL_Msk       (0x1e00000UL)             /*!< INSEL (Bitfield-Mask: 0x0f)                           */
#define PROTIMER_CC2_CTRL_ICEDGE_Pos      (25UL)                    /*!< ICEDGE (Bit 25)                                       */
#define PROTIMER_CC2_CTRL_ICEDGE_Msk      (0x6000000UL)             /*!< ICEDGE (Bitfield-Mask: 0x03)                          */
/* ========================================================  CC2_PRE  ======================================================== */
#define PROTIMER_CC2_PRE_PRE_Pos          (0UL)                     /*!< PRE (Bit 0)                                           */
#define PROTIMER_CC2_PRE_PRE_Msk          (0xffffUL)                /*!< PRE (Bitfield-Mask: 0xffff)                           */
/* =======================================================  CC2_BASE  ======================================================== */
#define PROTIMER_CC2_BASE_BASE_Pos        (0UL)                     /*!< BASE (Bit 0)                                          */
#define PROTIMER_CC2_BASE_BASE_Msk        (0xffffUL)                /*!< BASE (Bitfield-Mask: 0xffff)                          */
/* =======================================================  CC2_WRAP  ======================================================== */
#define PROTIMER_CC2_WRAP_WRAP_Pos        (0UL)                     /*!< WRAP (Bit 0)                                          */
#define PROTIMER_CC2_WRAP_WRAP_Msk        (0xffffffffUL)            /*!< WRAP (Bitfield-Mask: 0xffffffff)                      */
/* =======================================================  CC3_CTRL  ======================================================== */
#define PROTIMER_CC3_CTRL_ENABLE_Pos      (0UL)                     /*!< ENABLE (Bit 0)                                        */
#define PROTIMER_CC3_CTRL_ENABLE_Msk      (0x1UL)                   /*!< ENABLE (Bitfield-Mask: 0x01)                          */
#define PROTIMER_CC3_CTRL_CCMODE_Pos      (1UL)                     /*!< CCMODE (Bit 1)                                        */
#define PROTIMER_CC3_CTRL_CCMODE_Msk      (0x2UL)                   /*!< CCMODE (Bitfield-Mask: 0x01)                          */
#define PROTIMER_CC3_CTRL_PREMATCHEN_Pos  (2UL)                     /*!< PREMATCHEN (Bit 2)                                    */
#define PROTIMER_CC3_CTRL_PREMATCHEN_Msk  (0x4UL)                   /*!< PREMATCHEN (Bitfield-Mask: 0x01)                      */
#define PROTIMER_CC3_CTRL_BASEMATCHEN_Pos (3UL)                     /*!< BASEMATCHEN (Bit 3)                                   */
#define PROTIMER_CC3_CTRL_BASEMATCHEN_Msk (0x8UL)                   /*!< BASEMATCHEN (Bitfield-Mask: 0x01)                     */
#define PROTIMER_CC3_CTRL_WRAPMATCHEN_Pos (4UL)                     /*!< WRAPMATCHEN (Bit 4)                                   */
#define PROTIMER_CC3_CTRL_WRAPMATCHEN_Msk (0x10UL)                  /*!< WRAPMATCHEN (Bitfield-Mask: 0x01)                     */
#define PROTIMER_CC3_CTRL_OIST_Pos        (5UL)                     /*!< OIST (Bit 5)                                          */
#define PROTIMER_CC3_CTRL_OIST_Msk        (0x20UL)                  /*!< OIST (Bitfield-Mask: 0x01)                            */
#define PROTIMER_CC3_CTRL_OUTINV_Pos      (6UL)                     /*!< OUTINV (Bit 6)                                        */
#define PROTIMER_CC3_CTRL_OUTINV_Msk      (0x40UL)                  /*!< OUTINV (Bitfield-Mask: 0x01)                          */
#define PROTIMER_CC3_CTRL_MOA_Pos         (8UL)                     /*!< MOA (Bit 8)                                           */
#define PROTIMER_CC3_CTRL_MOA_Msk         (0x300UL)                 /*!< MOA (Bitfield-Mask: 0x03)                             */
#define PROTIMER_CC3_CTRL_OFOA_Pos        (10UL)                    /*!< OFOA (Bit 10)                                         */
#define PROTIMER_CC3_CTRL_OFOA_Msk        (0xc00UL)                 /*!< OFOA (Bitfield-Mask: 0x03)                            */
#define PROTIMER_CC3_CTRL_OFSEL_Pos       (12UL)                    /*!< OFSEL (Bit 12)                                        */
#define PROTIMER_CC3_CTRL_OFSEL_Msk       (0x3000UL)                /*!< OFSEL (Bitfield-Mask: 0x03)                           */
#define PROTIMER_CC3_CTRL_PRSCONF_Pos     (14UL)                    /*!< PRSCONF (Bit 14)                                      */
#define PROTIMER_CC3_CTRL_PRSCONF_Msk     (0x4000UL)                /*!< PRSCONF (Bitfield-Mask: 0x01)                         */
#define PROTIMER_CC3_CTRL_INSEL_Pos       (21UL)                    /*!< INSEL (Bit 21)                                        */
#define PROTIMER_CC3_CTRL_INSEL_Msk       (0x1e00000UL)             /*!< INSEL (Bitfield-Mask: 0x0f)                           */
#define PROTIMER_CC3_CTRL_ICEDGE_Pos      (25UL)                    /*!< ICEDGE (Bit 25)                                       */
#define PROTIMER_CC3_CTRL_ICEDGE_Msk      (0x6000000UL)             /*!< ICEDGE (Bitfield-Mask: 0x03)                          */
/* ========================================================  CC3_PRE  ======================================================== */
#define PROTIMER_CC3_PRE_PRE_Pos          (0UL)                     /*!< PRE (Bit 0)                                           */
#define PROTIMER_CC3_PRE_PRE_Msk          (0xffffUL)                /*!< PRE (Bitfield-Mask: 0xffff)                           */
/* =======================================================  CC3_BASE  ======================================================== */
#define PROTIMER_CC3_BASE_BASE_Pos        (0UL)                     /*!< BASE (Bit 0)                                          */
#define PROTIMER_CC3_BASE_BASE_Msk        (0xffffUL)                /*!< BASE (Bitfield-Mask: 0xffff)                          */
/* =======================================================  CC3_WRAP  ======================================================== */
#define PROTIMER_CC3_WRAP_WRAP_Pos        (0UL)                     /*!< WRAP (Bit 0)                                          */
#define PROTIMER_CC3_WRAP_WRAP_Msk        (0xffffffffUL)            /*!< WRAP (Bitfield-Mask: 0xffffffff)                      */
/* =======================================================  CC4_CTRL  ======================================================== */
#define PROTIMER_CC4_CTRL_ENABLE_Pos      (0UL)                     /*!< ENABLE (Bit 0)                                        */
#define PROTIMER_CC4_CTRL_ENABLE_Msk      (0x1UL)                   /*!< ENABLE (Bitfield-Mask: 0x01)                          */
#define PROTIMER_CC4_CTRL_CCMODE_Pos      (1UL)                     /*!< CCMODE (Bit 1)                                        */
#define PROTIMER_CC4_CTRL_CCMODE_Msk      (0x2UL)                   /*!< CCMODE (Bitfield-Mask: 0x01)                          */
#define PROTIMER_CC4_CTRL_PREMATCHEN_Pos  (2UL)                     /*!< PREMATCHEN (Bit 2)                                    */
#define PROTIMER_CC4_CTRL_PREMATCHEN_Msk  (0x4UL)                   /*!< PREMATCHEN (Bitfield-Mask: 0x01)                      */
#define PROTIMER_CC4_CTRL_BASEMATCHEN_Pos (3UL)                     /*!< BASEMATCHEN (Bit 3)                                   */
#define PROTIMER_CC4_CTRL_BASEMATCHEN_Msk (0x8UL)                   /*!< BASEMATCHEN (Bitfield-Mask: 0x01)                     */
#define PROTIMER_CC4_CTRL_WRAPMATCHEN_Pos (4UL)                     /*!< WRAPMATCHEN (Bit 4)                                   */
#define PROTIMER_CC4_CTRL_WRAPMATCHEN_Msk (0x10UL)                  /*!< WRAPMATCHEN (Bitfield-Mask: 0x01)                     */
#define PROTIMER_CC4_CTRL_OIST_Pos        (5UL)                     /*!< OIST (Bit 5)                                          */
#define PROTIMER_CC4_CTRL_OIST_Msk        (0x20UL)                  /*!< OIST (Bitfield-Mask: 0x01)                            */
#define PROTIMER_CC4_CTRL_OUTINV_Pos      (6UL)                     /*!< OUTINV (Bit 6)                                        */
#define PROTIMER_CC4_CTRL_OUTINV_Msk      (0x40UL)                  /*!< OUTINV (Bitfield-Mask: 0x01)                          */
#define PROTIMER_CC4_CTRL_MOA_Pos         (8UL)                     /*!< MOA (Bit 8)                                           */
#define PROTIMER_CC4_CTRL_MOA_Msk         (0x300UL)                 /*!< MOA (Bitfield-Mask: 0x03)                             */
#define PROTIMER_CC4_CTRL_OFOA_Pos        (10UL)                    /*!< OFOA (Bit 10)                                         */
#define PROTIMER_CC4_CTRL_OFOA_Msk        (0xc00UL)                 /*!< OFOA (Bitfield-Mask: 0x03)                            */
#define PROTIMER_CC4_CTRL_OFSEL_Pos       (12UL)                    /*!< OFSEL (Bit 12)                                        */
#define PROTIMER_CC4_CTRL_OFSEL_Msk       (0x3000UL)                /*!< OFSEL (Bitfield-Mask: 0x03)                           */
#define PROTIMER_CC4_CTRL_PRSCONF_Pos     (14UL)                    /*!< PRSCONF (Bit 14)                                      */
#define PROTIMER_CC4_CTRL_PRSCONF_Msk     (0x4000UL)                /*!< PRSCONF (Bitfield-Mask: 0x01)                         */
#define PROTIMER_CC4_CTRL_INSEL_Pos       (21UL)                    /*!< INSEL (Bit 21)                                        */
#define PROTIMER_CC4_CTRL_INSEL_Msk       (0x1e00000UL)             /*!< INSEL (Bitfield-Mask: 0x0f)                           */
#define PROTIMER_CC4_CTRL_ICEDGE_Pos      (25UL)                    /*!< ICEDGE (Bit 25)                                       */
#define PROTIMER_CC4_CTRL_ICEDGE_Msk      (0x6000000UL)             /*!< ICEDGE (Bitfield-Mask: 0x03)                          */
/* ========================================================  CC4_PRE  ======================================================== */
#define PROTIMER_CC4_PRE_PRE_Pos          (0UL)                     /*!< PRE (Bit 0)                                           */
#define PROTIMER_CC4_PRE_PRE_Msk          (0xffffUL)                /*!< PRE (Bitfield-Mask: 0xffff)                           */
/* =======================================================  CC4_BASE  ======================================================== */
#define PROTIMER_CC4_BASE_BASE_Pos        (0UL)                     /*!< BASE (Bit 0)                                          */
#define PROTIMER_CC4_BASE_BASE_Msk        (0xffffUL)                /*!< BASE (Bitfield-Mask: 0xffff)                          */
/* =======================================================  CC4_WRAP  ======================================================== */
#define PROTIMER_CC4_WRAP_WRAP_Pos        (0UL)                     /*!< WRAP (Bit 0)                                          */
#define PROTIMER_CC4_WRAP_WRAP_Msk        (0xffffffffUL)            /*!< WRAP (Bitfield-Mask: 0xffffffff)                      */

/** @} */
/** @} End of group EFR32FG1V_PROTIMER*/
/** @} End of group Parts */
