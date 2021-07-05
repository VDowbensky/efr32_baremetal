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
 * @defgroup EFR32FG1V_RAC
 * @{
 * @brief EFR32FG1V_RAC Register Declaration
 ******************************************************************************/
/* =========================================================================================================================== */
/* ================                                            RAC                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Radio controller (RAC)
  */

typedef struct {                                /*!< (@ 0x40084000) RAC Structure                                              */
  __IOM uint32_t  RXENSRCEN;                    /*!< (@ 0x00000000) RXENSRCEN                                                  */
  __IM  uint32_t  STATUS;                       /*!< (@ 0x00000004) STATUS                                                     */
  __OM  uint32_t  CMD;                          /*!< (@ 0x00000008) CMD                                                        */
  __IOM uint32_t  CTRL;                         /*!< (@ 0x0000000C) CTRL                                                       */
  __IOM uint32_t  FORCESTATE;                   /*!< (@ 0x00000010) FORCESTATE                                                 */
  __IM  uint32_t  IF;                           /*!< (@ 0x00000014) IF                                                         */
  __OM  uint32_t  IFS;                          /*!< (@ 0x00000018) IFS                                                        */
  __OM  uint32_t  IFC;                          /*!< (@ 0x0000001C) IFC                                                        */
  __IOM uint32_t  IEN;                          /*!< (@ 0x00000020) IEN                                                        */
  __IOM uint32_t  LVDSCTRL;                     /*!< (@ 0x00000024) LVDSCTRL                                                   */
  __IOM uint32_t  LVDSIDLESEQ;                  /*!< (@ 0x00000028) LVDSIDLESEQ                                                */
  __IOM uint32_t  LVDSROUTE;                    /*!< (@ 0x0000002C) LVDSROUTE                                                  */
  __IOM uint32_t  HFXORETIMECTRL;               /*!< (@ 0x00000030) HFXORETIMECTRL                                             */
  __IM  uint32_t  HFXORETIMESTATUS;             /*!< (@ 0x00000034) HFXORETIMESTATUS                                           */
  __IOM uint32_t  TESTCTRL;                     /*!< (@ 0x00000038) TESTCTRL                                                   */
  __IM  uint32_t  SEQSTATUS;                    /*!< (@ 0x0000003C) SEQSTATUS                                                  */
  __OM  uint32_t  SEQCMD;                       /*!< (@ 0x00000040) SEQCMD                                                     */
  __IOM uint32_t  BREAKPOINT;                   /*!< (@ 0x00000044) BREAKPOINT                                                 */
  __IOM uint32_t  R0;                           /*!< (@ 0x00000048) R0                                                         */
  __IOM uint32_t  R1;                           /*!< (@ 0x0000004C) R1                                                         */
  __IOM uint32_t  R2;                           /*!< (@ 0x00000050) R2                                                         */
  __IOM uint32_t  R3;                           /*!< (@ 0x00000054) R3                                                         */
  __IOM uint32_t  R4;                           /*!< (@ 0x00000058) R4                                                         */
  __IOM uint32_t  R5;                           /*!< (@ 0x0000005C) R5                                                         */
  __IOM uint32_t  R6;                           /*!< (@ 0x00000060) R6                                                         */
  __IOM uint32_t  R7;                           /*!< (@ 0x00000064) R7                                                         */
  __IM  uint32_t  RESERVED;
  __IM  uint32_t  WAITMASK;                     /*!< (@ 0x0000006C) WAITMASK                                                   */
  __IM  uint32_t  WAITSNSH;                     /*!< (@ 0x00000070) WAITSNSH                                                   */
  __IM  uint32_t  STIMER;                       /*!< (@ 0x00000074) STIMER                                                     */
  __IOM uint32_t  STIMERCOMP;                   /*!< (@ 0x00000078) STIMERCOMP                                                 */
  __IOM uint32_t  VECTADDR;                     /*!< (@ 0x0000007C) VECTADDR                                                   */
  __IOM uint32_t  SEQCTRL;                      /*!< (@ 0x00000080) SEQCTRL                                                    */
  __IOM uint32_t  PRESC;                        /*!< (@ 0x00000084) PRESC                                                      */
  __IOM uint32_t  SR0;                          /*!< (@ 0x00000088) SR0                                                        */
  __IOM uint32_t  SR1;                          /*!< (@ 0x0000008C) SR1                                                        */
  __IOM uint32_t  SR2;                          /*!< (@ 0x00000090) SR2                                                        */
  __IOM uint32_t  SR3;                          /*!< (@ 0x00000094) SR3                                                        */
  __IOM uint32_t  SYNTHENCTRL;                  /*!< (@ 0x00000098) SYNTHENCTRL                                                */
  __IOM uint32_t  SYNTHREGCTRL;                 /*!< (@ 0x0000009C) SYNTHREGCTRL                                               */
  __IOM uint32_t  VCOCTRL;                      /*!< (@ 0x000000A0) VCOCTRL                                                    */
  __IOM uint32_t  MMDCTRL;                      /*!< (@ 0x000000A4) MMDCTRL                                                    */
  __IM  uint32_t  RESERVED1[2];
  __IOM uint32_t  CHPCTRL;                      /*!< (@ 0x000000B0) CHPCTRL                                                    */
  __IOM uint32_t  CHPCAL;                       /*!< (@ 0x000000B4) CHPCAL                                                     */
  __IOM uint32_t  LPFCTRL;                      /*!< (@ 0x000000B8) LPFCTRL                                                    */
  __IOM uint32_t  SYNTHCTRL;                    /*!< (@ 0x000000BC) SYNTHCTRL                                                  */
  __IOM uint32_t  AUXCTRL;                      /*!< (@ 0x000000C0) AUXCTRL                                                    */
  __IOM uint32_t  AUXENCTRL;                    /*!< (@ 0x000000C4) AUXENCTRL                                                  */
  __IM  uint32_t  RESERVED2[11];
  __IOM uint32_t  RFENCTRL;                     /*!< (@ 0x000000F4) RFENCTRL                                                   */
  __IOM uint32_t  RFENCTRL0;                    /*!< (@ 0x000000F8) RFENCTRL0                                                  */
  __IOM uint32_t  LNAMIXCTRL;                   /*!< (@ 0x000000FC) LNAMIXCTRL                                                 */
  __IOM uint32_t  PACTRL0;                      /*!< (@ 0x00000100) PACTRL0                                                    */
  __IOM uint32_t  PAPKDCTRL;                    /*!< (@ 0x00000104) PAPKDCTRL                                                  */
  __IOM uint32_t  PABIASCTRL0;                  /*!< (@ 0x00000108) PABIASCTRL0                                                */
  __IOM uint32_t  PABIASCTRL1;                  /*!< (@ 0x0000010C) PABIASCTRL1                                                */
  __IOM uint32_t  SGRFENCTRL0;                  /*!< (@ 0x00000110) SGRFENCTRL0                                                */
  __IOM uint32_t  SGLNAMIXCTRL;                 /*!< (@ 0x00000114) SGLNAMIXCTRL                                               */
  __IOM uint32_t  SGPACTRL0;                    /*!< (@ 0x00000118) SGPACTRL0                                                  */
  __IOM uint32_t  SGPAPKDCTRL;                  /*!< (@ 0x0000011C) SGPAPKDCTRL                                                */
  __IOM uint32_t  SGPABIASCTRL0;                /*!< (@ 0x00000120) SGPABIASCTRL0                                              */
  __IOM uint32_t  SGPABIASCTRL1;                /*!< (@ 0x00000124) SGPABIASCTRL1                                              */
  __IM  uint32_t  RFSTATUS;                     /*!< (@ 0x00000128) RFSTATUS                                                   */
  __IOM uint32_t  RFBIASCTRL;                   /*!< (@ 0x0000012C) RFBIASCTRL                                                 */
  __IOM uint32_t  RFBIASCAL;                    /*!< (@ 0x00000130) RFBIASCAL                                                  */
  __IOM uint32_t  LNAMIXCTRL1;                  /*!< (@ 0x00000134) LNAMIXCTRL1                                                */
  __IOM uint32_t  IFPGACTRL;                    /*!< (@ 0x00000138) IFPGACTRL                                                  */
  __IOM uint32_t  IFPGACAL;                     /*!< (@ 0x0000013C) IFPGACAL                                                   */
  __IOM uint32_t  IFFILTCTRL;                   /*!< (@ 0x00000140) IFFILTCTRL                                                 */
  __IOM uint32_t  IFADCCTRL;                    /*!< (@ 0x00000144) IFADCCTRL                                                  */
  __IOM uint32_t  IFADCCAL;                     /*!< (@ 0x00000148) IFADCCAL                                                   */
  __IOM uint32_t  PAENCTRL;                     /*!< (@ 0x0000014C) PAENCTRL                                                   */
  __IOM uint32_t  PACTUNECTRL;                  /*!< (@ 0x00000150) PACTUNECTRL                                                */
  __IOM uint32_t  RCTUNE;                       /*!< (@ 0x00000154) RCTUNE                                                     */
  __IOM uint32_t  APC;                          /*!< (@ 0x00000158) APC                                                        */
  __IOM uint32_t  SPARE;                        /*!< (@ 0x0000015C) SPARE                                                      */
} RAC_Typedef;                                     /*!< Size = 352 (0x160)                                                        */
 
/***************************************************************************//**
 * @addtogroup EFR32FG1V_RAC
 * @{
 * @defgroup EFR32FG1V_RAC BitFields  RAC Bit Fields
 * @{
 ******************************************************************************/
/* =========================================================================================================================== */
/* ================                                            RAC                                            ================ */
/* =========================================================================================================================== */

/* =======================================================  RXENSRCEN  ======================================================= */
#define RAC_RXENSRCEN_SWRXEN_Pos          (0UL)                     /*!< SWRXEN (Bit 0)                                        */
#define RAC_RXENSRCEN_SWRXEN_Msk          (0xffUL)                  /*!< SWRXEN (Bitfield-Mask: 0xff)                          */
#define RAC_RXENSRCEN_CHANNELBUSYEN_Pos   (8UL)                     /*!< CHANNELBUSYEN (Bit 8)                                 */
#define RAC_RXENSRCEN_CHANNELBUSYEN_Msk   (0x100UL)                 /*!< CHANNELBUSYEN (Bitfield-Mask: 0x01)                   */
#define RAC_RXENSRCEN_TIMDETEN_Pos        (9UL)                     /*!< TIMDETEN (Bit 9)                                      */
#define RAC_RXENSRCEN_TIMDETEN_Msk        (0x200UL)                 /*!< TIMDETEN (Bitfield-Mask: 0x01)                        */
#define RAC_RXENSRCEN_PREDETEN_Pos        (10UL)                    /*!< PREDETEN (Bit 10)                                     */
#define RAC_RXENSRCEN_PREDETEN_Msk        (0x400UL)                 /*!< PREDETEN (Bitfield-Mask: 0x01)                        */
#define RAC_RXENSRCEN_FRAMEDETEN_Pos      (11UL)                    /*!< FRAMEDETEN (Bit 11)                                   */
#define RAC_RXENSRCEN_FRAMEDETEN_Msk      (0x800UL)                 /*!< FRAMEDETEN (Bitfield-Mask: 0x01)                      */
#define RAC_RXENSRCEN_DEMODRXREQEN_Pos    (12UL)                    /*!< DEMODRXREQEN (Bit 12)                                 */
#define RAC_RXENSRCEN_DEMODRXREQEN_Msk    (0x1000UL)                /*!< DEMODRXREQEN (Bitfield-Mask: 0x01)                    */
#define RAC_RXENSRCEN_PRSRXEN_Pos         (13UL)                    /*!< PRSRXEN (Bit 13)                                      */
#define RAC_RXENSRCEN_PRSRXEN_Msk         (0x2000UL)                /*!< PRSRXEN (Bitfield-Mask: 0x01)                         */
#define RAC_RXENSRCEN_PRSRXENSEL_Pos      (14UL)                    /*!< PRSRXENSEL (Bit 14)                                   */
#define RAC_RXENSRCEN_PRSRXENSEL_Msk      (0x3c000UL)               /*!< PRSRXENSEL (Bitfield-Mask: 0x0f)                      */
#define RAC_RXENSRCEN_PRSRXENEM2WU_Pos    (20UL)                    /*!< PRSRXENEM2WU (Bit 20)                                 */
#define RAC_RXENSRCEN_PRSRXENEM2WU_Msk    (0x100000UL)              /*!< PRSRXENEM2WU (Bitfield-Mask: 0x01)                    */
/* ========================================================  STATUS  ========================================================= */
#define RAC_STATUS_RXMASK_Pos             (0UL)                     /*!< RXMASK (Bit 0)                                        */
#define RAC_STATUS_RXMASK_Msk             (0xffffUL)                /*!< RXMASK (Bitfield-Mask: 0xffff)                        */
#define RAC_STATUS_FORCESTATEACTIVE_Pos   (19UL)                    /*!< FORCESTATEACTIVE (Bit 19)                             */
#define RAC_STATUS_FORCESTATEACTIVE_Msk   (0x80000UL)               /*!< FORCESTATEACTIVE (Bitfield-Mask: 0x01)                */
#define RAC_STATUS_TXAFTERFRAMEPEND_Pos   (20UL)                    /*!< TXAFTERFRAMEPEND (Bit 20)                             */
#define RAC_STATUS_TXAFTERFRAMEPEND_Msk   (0x100000UL)              /*!< TXAFTERFRAMEPEND (Bitfield-Mask: 0x01)                */
#define RAC_STATUS_TXAFTERFRAMEACTIVE_Pos (21UL)                    /*!< TXAFTERFRAMEACTIVE (Bit 21)                           */
#define RAC_STATUS_TXAFTERFRAMEACTIVE_Msk (0x200000UL)              /*!< TXAFTERFRAMEACTIVE (Bitfield-Mask: 0x01)              */
#define RAC_STATUS_STATE_Pos              (24UL)                    /*!< STATE (Bit 24)                                        */
#define RAC_STATUS_STATE_Msk              (0xf000000UL)             /*!< STATE (Bitfield-Mask: 0x0f)                           */
#define RAC_STATUS_DEMODENS_Pos           (29UL)                    /*!< DEMODENS (Bit 29)                                     */
#define RAC_STATUS_DEMODENS_Msk           (0x20000000UL)            /*!< DEMODENS (Bitfield-Mask: 0x01)                        */
#define RAC_STATUS_TXENS_Pos              (30UL)                    /*!< TXENS (Bit 30)                                        */
#define RAC_STATUS_TXENS_Msk              (0x40000000UL)            /*!< TXENS (Bitfield-Mask: 0x01)                           */
#define RAC_STATUS_RXENS_Pos              (31UL)                    /*!< RXENS (Bit 31)                                        */
#define RAC_STATUS_RXENS_Msk              (0x80000000UL)            /*!< RXENS (Bitfield-Mask: 0x01)                           */
/* ==========================================================  CMD  ========================================================== */
#define RAC_CMD_TXEN_Pos                  (0UL)                     /*!< TXEN (Bit 0)                                          */
#define RAC_CMD_TXEN_Msk                  (0x1UL)                   /*!< TXEN (Bitfield-Mask: 0x01)                            */
#define RAC_CMD_FORCETX_Pos               (1UL)                     /*!< FORCETX (Bit 1)                                       */
#define RAC_CMD_FORCETX_Msk               (0x2UL)                   /*!< FORCETX (Bitfield-Mask: 0x01)                         */
#define RAC_CMD_TXONCCA_Pos               (2UL)                     /*!< TXONCCA (Bit 2)                                       */
#define RAC_CMD_TXONCCA_Msk               (0x4UL)                   /*!< TXONCCA (Bitfield-Mask: 0x01)                         */
#define RAC_CMD_CLEARTXEN_Pos             (3UL)                     /*!< CLEARTXEN (Bit 3)                                     */
#define RAC_CMD_CLEARTXEN_Msk             (0x8UL)                   /*!< CLEARTXEN (Bitfield-Mask: 0x01)                       */
#define RAC_CMD_TXAFTERFRAME_Pos          (4UL)                     /*!< TXAFTERFRAME (Bit 4)                                  */
#define RAC_CMD_TXAFTERFRAME_Msk          (0x10UL)                  /*!< TXAFTERFRAME (Bitfield-Mask: 0x01)                    */
#define RAC_CMD_TXDIS_Pos                 (5UL)                     /*!< TXDIS (Bit 5)                                         */
#define RAC_CMD_TXDIS_Msk                 (0x20UL)                  /*!< TXDIS (Bitfield-Mask: 0x01)                           */
#define RAC_CMD_CLEARRXOVERFLOW_Pos       (6UL)                     /*!< CLEARRXOVERFLOW (Bit 6)                               */
#define RAC_CMD_CLEARRXOVERFLOW_Msk       (0x40UL)                  /*!< CLEARRXOVERFLOW (Bitfield-Mask: 0x01)                 */
#define RAC_CMD_RXCAL_Pos                 (7UL)                     /*!< RXCAL (Bit 7)                                         */
#define RAC_CMD_RXCAL_Msk                 (0x80UL)                  /*!< RXCAL (Bitfield-Mask: 0x01)                           */
#define RAC_CMD_RXDIS_Pos                 (8UL)                     /*!< RXDIS (Bit 8)                                         */
#define RAC_CMD_RXDIS_Msk                 (0x100UL)                 /*!< RXDIS (Bitfield-Mask: 0x01)                           */
#define RAC_CMD_PAENSET_Pos               (12UL)                    /*!< PAENSET (Bit 12)                                      */
#define RAC_CMD_PAENSET_Msk               (0x1000UL)                /*!< PAENSET (Bitfield-Mask: 0x01)                         */
#define RAC_CMD_PAENCLEAR_Pos             (13UL)                    /*!< PAENCLEAR (Bit 13)                                    */
#define RAC_CMD_PAENCLEAR_Msk             (0x2000UL)                /*!< PAENCLEAR (Bitfield-Mask: 0x01)                       */
#define RAC_CMD_LNAENSET_Pos              (14UL)                    /*!< LNAENSET (Bit 14)                                     */
#define RAC_CMD_LNAENSET_Msk              (0x4000UL)                /*!< LNAENSET (Bitfield-Mask: 0x01)                        */
#define RAC_CMD_LNAENCLEAR_Pos            (15UL)                    /*!< LNAENCLEAR (Bit 15)                                   */
#define RAC_CMD_LNAENCLEAR_Msk            (0x8000UL)                /*!< LNAENCLEAR (Bitfield-Mask: 0x01)                      */
#define RAC_CMD_DEMODENSET_Pos            (30UL)                    /*!< DEMODENSET (Bit 30)                                   */
#define RAC_CMD_DEMODENSET_Msk            (0x40000000UL)            /*!< DEMODENSET (Bitfield-Mask: 0x01)                      */
#define RAC_CMD_DEMODENCLEAR_Pos          (31UL)                    /*!< DEMODENCLEAR (Bit 31)                                 */
#define RAC_CMD_DEMODENCLEAR_Msk          (0x80000000UL)            /*!< DEMODENCLEAR (Bitfield-Mask: 0x01)                    */
/* =========================================================  CTRL  ========================================================== */
#define RAC_CTRL_FORCEDISABLE_Pos         (0UL)                     /*!< FORCEDISABLE (Bit 0)                                  */
#define RAC_CTRL_FORCEDISABLE_Msk         (0x1UL)                   /*!< FORCEDISABLE (Bitfield-Mask: 0x01)                    */
#define RAC_CTRL_PRSTXEN_Pos              (1UL)                     /*!< PRSTXEN (Bit 1)                                       */
#define RAC_CTRL_PRSTXEN_Msk              (0x2UL)                   /*!< PRSTXEN (Bitfield-Mask: 0x01)                         */
#define RAC_CTRL_TXAFTERRX_Pos            (2UL)                     /*!< TXAFTERRX (Bit 2)                                     */
#define RAC_CTRL_TXAFTERRX_Msk            (0x4UL)                   /*!< TXAFTERRX (Bitfield-Mask: 0x01)                       */
#define RAC_CTRL_PRSMODE_Pos              (3UL)                     /*!< PRSMODE (Bit 3)                                       */
#define RAC_CTRL_PRSMODE_Msk              (0x8UL)                   /*!< PRSMODE (Bitfield-Mask: 0x01)                         */
#define RAC_CTRL_PRSCLR_Pos               (5UL)                     /*!< PRSCLR (Bit 5)                                        */
#define RAC_CTRL_PRSCLR_Msk               (0x20UL)                  /*!< PRSCLR (Bitfield-Mask: 0x01)                          */
#define RAC_CTRL_TXPOSTPONE_Pos           (6UL)                     /*!< TXPOSTPONE (Bit 6)                                    */
#define RAC_CTRL_TXPOSTPONE_Msk           (0x40UL)                  /*!< TXPOSTPONE (Bitfield-Mask: 0x01)                      */
#define RAC_CTRL_ACTIVEPOL_Pos            (7UL)                     /*!< ACTIVEPOL (Bit 7)                                     */
#define RAC_CTRL_ACTIVEPOL_Msk            (0x80UL)                  /*!< ACTIVEPOL (Bitfield-Mask: 0x01)                       */
#define RAC_CTRL_PAENPOL_Pos              (8UL)                     /*!< PAENPOL (Bit 8)                                       */
#define RAC_CTRL_PAENPOL_Msk              (0x100UL)                 /*!< PAENPOL (Bitfield-Mask: 0x01)                         */
#define RAC_CTRL_LNAENPOL_Pos             (9UL)                     /*!< LNAENPOL (Bit 9)                                      */
#define RAC_CTRL_LNAENPOL_Msk             (0x200UL)                 /*!< LNAENPOL (Bitfield-Mask: 0x01)                        */
#define RAC_CTRL_PRSRXDIS_Pos             (10UL)                    /*!< PRSRXDIS (Bit 10)                                     */
#define RAC_CTRL_PRSRXDIS_Msk             (0x400UL)                 /*!< PRSRXDIS (Bitfield-Mask: 0x01)                        */
#define RAC_CTRL_PRSRXDISSEL_Pos          (11UL)                    /*!< PRSRXDISSEL (Bit 11)                                  */
#define RAC_CTRL_PRSRXDISSEL_Msk          (0x7800UL)                /*!< PRSRXDISSEL (Bitfield-Mask: 0x0f)                     */
#define RAC_CTRL_PRSFORCETX_Pos           (16UL)                    /*!< PRSFORCETX (Bit 16)                                   */
#define RAC_CTRL_PRSFORCETX_Msk           (0x10000UL)               /*!< PRSFORCETX (Bitfield-Mask: 0x01)                      */
#define RAC_CTRL_PRSFORCETXSEL_Pos        (17UL)                    /*!< PRSFORCETXSEL (Bit 17)                                */
#define RAC_CTRL_PRSFORCETXSEL_Msk        (0x1e0000UL)              /*!< PRSFORCETXSEL (Bitfield-Mask: 0x0f)                   */
#define RAC_CTRL_PRSTXENSEL_Pos           (22UL)                    /*!< PRSTXENSEL (Bit 22)                                   */
#define RAC_CTRL_PRSTXENSEL_Msk           (0x3c00000UL)             /*!< PRSTXENSEL (Bitfield-Mask: 0x0f)                      */
#define RAC_CTRL_PRSCLRSEL_Pos            (27UL)                    /*!< PRSCLRSEL (Bit 27)                                    */
#define RAC_CTRL_PRSCLRSEL_Msk            (0x78000000UL)            /*!< PRSCLRSEL (Bitfield-Mask: 0x0f)                       */
/* ======================================================  FORCESTATE  ======================================================= */
#define RAC_FORCESTATE_FORCESTATE_Pos     (0UL)                     /*!< FORCESTATE (Bit 0)                                    */
#define RAC_FORCESTATE_FORCESTATE_Msk     (0xfUL)                   /*!< FORCESTATE (Bitfield-Mask: 0x0f)                      */
/* ==========================================================  IF  =========================================================== */
#define RAC_IF_STATECHANGE_Pos            (0UL)                     /*!< STATECHANGE (Bit 0)                                   */
#define RAC_IF_STATECHANGE_Msk            (0x1UL)                   /*!< STATECHANGE (Bitfield-Mask: 0x01)                     */
#define RAC_IF_STIMCMPEV_Pos              (1UL)                     /*!< STIMCMPEV (Bit 1)                                     */
#define RAC_IF_STIMCMPEV_Msk              (0x2UL)                   /*!< STIMCMPEV (Bitfield-Mask: 0x01)                       */
#define RAC_IF_BUSERROR_Pos               (2UL)                     /*!< BUSERROR (Bit 2)                                      */
#define RAC_IF_BUSERROR_Msk               (0x4UL)                   /*!< BUSERROR (Bitfield-Mask: 0x01)                        */
#define RAC_IF_SEQ_Pos                    (16UL)                    /*!< SEQ (Bit 16)                                          */
#define RAC_IF_SEQ_Msk                    (0xff0000UL)              /*!< SEQ (Bitfield-Mask: 0xff)                             */
#define RAC_IF_PAVHIGH_Pos                (25UL)                    /*!< PAVHIGH (Bit 25)                                      */
#define RAC_IF_PAVHIGH_Msk                (0x2000000UL)             /*!< PAVHIGH (Bitfield-Mask: 0x01)                         */
#define RAC_IF_PAVLOW_Pos                 (26UL)                    /*!< PAVLOW (Bit 26)                                       */
#define RAC_IF_PAVLOW_Msk                 (0x4000000UL)             /*!< PAVLOW (Bitfield-Mask: 0x01)                          */
#define RAC_IF_PABATHIGH_Pos              (27UL)                    /*!< PABATHIGH (Bit 27)                                    */
#define RAC_IF_PABATHIGH_Msk              (0x8000000UL)             /*!< PABATHIGH (Bitfield-Mask: 0x01)                       */
/* ==========================================================  IFS  ========================================================== */
#define RAC_IFS_STATECHANGE_Pos           (0UL)                     /*!< STATECHANGE (Bit 0)                                   */
#define RAC_IFS_STATECHANGE_Msk           (0x1UL)                   /*!< STATECHANGE (Bitfield-Mask: 0x01)                     */
#define RAC_IFS_STIMCMPEV_Pos             (1UL)                     /*!< STIMCMPEV (Bit 1)                                     */
#define RAC_IFS_STIMCMPEV_Msk             (0x2UL)                   /*!< STIMCMPEV (Bitfield-Mask: 0x01)                       */
#define RAC_IFS_BUSERROR_Pos              (2UL)                     /*!< BUSERROR (Bit 2)                                      */
#define RAC_IFS_BUSERROR_Msk              (0x4UL)                   /*!< BUSERROR (Bitfield-Mask: 0x01)                        */
#define RAC_IFS_SEQ_Pos                   (16UL)                    /*!< SEQ (Bit 16)                                          */
#define RAC_IFS_SEQ_Msk                   (0xff0000UL)              /*!< SEQ (Bitfield-Mask: 0xff)                             */
#define RAC_IFS_PAVHIGH_Pos               (25UL)                    /*!< PAVHIGH (Bit 25)                                      */
#define RAC_IFS_PAVHIGH_Msk               (0x2000000UL)             /*!< PAVHIGH (Bitfield-Mask: 0x01)                         */
#define RAC_IFS_PAVLOW_Pos                (26UL)                    /*!< PAVLOW (Bit 26)                                       */
#define RAC_IFS_PAVLOW_Msk                (0x4000000UL)             /*!< PAVLOW (Bitfield-Mask: 0x01)                          */
#define RAC_IFS_PABATHIGH_Pos             (27UL)                    /*!< PABATHIGH (Bit 27)                                    */
#define RAC_IFS_PABATHIGH_Msk             (0x8000000UL)             /*!< PABATHIGH (Bitfield-Mask: 0x01)                       */
/* ==========================================================  IFC  ========================================================== */
#define RAC_IFC_STATECHANGE_Pos           (0UL)                     /*!< STATECHANGE (Bit 0)                                   */
#define RAC_IFC_STATECHANGE_Msk           (0x1UL)                   /*!< STATECHANGE (Bitfield-Mask: 0x01)                     */
#define RAC_IFC_STIMCMPEV_Pos             (1UL)                     /*!< STIMCMPEV (Bit 1)                                     */
#define RAC_IFC_STIMCMPEV_Msk             (0x2UL)                   /*!< STIMCMPEV (Bitfield-Mask: 0x01)                       */
#define RAC_IFC_BUSERROR_Pos              (2UL)                     /*!< BUSERROR (Bit 2)                                      */
#define RAC_IFC_BUSERROR_Msk              (0x4UL)                   /*!< BUSERROR (Bitfield-Mask: 0x01)                        */
#define RAC_IFC_SEQ_Pos                   (16UL)                    /*!< SEQ (Bit 16)                                          */
#define RAC_IFC_SEQ_Msk                   (0xff0000UL)              /*!< SEQ (Bitfield-Mask: 0xff)                             */
#define RAC_IFC_PAVHIGH_Pos               (25UL)                    /*!< PAVHIGH (Bit 25)                                      */
#define RAC_IFC_PAVHIGH_Msk               (0x2000000UL)             /*!< PAVHIGH (Bitfield-Mask: 0x01)                         */
#define RAC_IFC_PAVLOW_Pos                (26UL)                    /*!< PAVLOW (Bit 26)                                       */
#define RAC_IFC_PAVLOW_Msk                (0x4000000UL)             /*!< PAVLOW (Bitfield-Mask: 0x01)                          */
#define RAC_IFC_PABATHIGH_Pos             (27UL)                    /*!< PABATHIGH (Bit 27)                                    */
#define RAC_IFC_PABATHIGH_Msk             (0x8000000UL)             /*!< PABATHIGH (Bitfield-Mask: 0x01)                       */
/* ==========================================================  IEN  ========================================================== */
#define RAC_IEN_STATECHANGE_Pos           (0UL)                     /*!< STATECHANGE (Bit 0)                                   */
#define RAC_IEN_STATECHANGE_Msk           (0x1UL)                   /*!< STATECHANGE (Bitfield-Mask: 0x01)                     */
#define RAC_IEN_STIMCMPEV_Pos             (1UL)                     /*!< STIMCMPEV (Bit 1)                                     */
#define RAC_IEN_STIMCMPEV_Msk             (0x2UL)                   /*!< STIMCMPEV (Bitfield-Mask: 0x01)                       */
#define RAC_IEN_BUSERROR_Pos              (2UL)                     /*!< BUSERROR (Bit 2)                                      */
#define RAC_IEN_BUSERROR_Msk              (0x4UL)                   /*!< BUSERROR (Bitfield-Mask: 0x01)                        */
#define RAC_IEN_SEQ_Pos                   (16UL)                    /*!< SEQ (Bit 16)                                          */
#define RAC_IEN_SEQ_Msk                   (0xff0000UL)              /*!< SEQ (Bitfield-Mask: 0xff)                             */
#define RAC_IEN_PAVHIGH_Pos               (25UL)                    /*!< PAVHIGH (Bit 25)                                      */
#define RAC_IEN_PAVHIGH_Msk               (0x2000000UL)             /*!< PAVHIGH (Bitfield-Mask: 0x01)                         */
#define RAC_IEN_PAVLOW_Pos                (26UL)                    /*!< PAVLOW (Bit 26)                                       */
#define RAC_IEN_PAVLOW_Msk                (0x4000000UL)             /*!< PAVLOW (Bitfield-Mask: 0x01)                          */
#define RAC_IEN_PABATHIGH_Pos             (27UL)                    /*!< PABATHIGH (Bit 27)                                    */
#define RAC_IEN_PABATHIGH_Msk             (0x8000000UL)             /*!< PABATHIGH (Bitfield-Mask: 0x01)                       */
/* =======================================================  LVDSCTRL  ======================================================== */
#define RAC_LVDSCTRL_LVDSEN_Pos           (0UL)                     /*!< LVDSEN (Bit 0)                                        */
#define RAC_LVDSCTRL_LVDSEN_Msk           (0x1UL)                   /*!< LVDSEN (Bitfield-Mask: 0x01)                          */
#define RAC_LVDSCTRL_LVDSCURR_Pos         (2UL)                     /*!< LVDSCURR (Bit 2)                                      */
#define RAC_LVDSCTRL_LVDSCURR_Msk         (0xcUL)                   /*!< LVDSCURR (Bitfield-Mask: 0x03)                        */
#define RAC_LVDSCTRL_LVDSTESTMODE_Pos     (4UL)                     /*!< LVDSTESTMODE (Bit 4)                                  */
#define RAC_LVDSCTRL_LVDSTESTMODE_Msk     (0x10UL)                  /*!< LVDSTESTMODE (Bitfield-Mask: 0x01)                    */
#define RAC_LVDSCTRL_LVDSTESTDATA_Pos     (5UL)                     /*!< LVDSTESTDATA (Bit 5)                                  */
#define RAC_LVDSCTRL_LVDSTESTDATA_Msk     (0x20UL)                  /*!< LVDSTESTDATA (Bitfield-Mask: 0x01)                    */
#define RAC_LVDSCTRL_LVDSCMCONFIG_Pos     (6UL)                     /*!< LVDSCMCONFIG (Bit 6)                                  */
#define RAC_LVDSCTRL_LVDSCMCONFIG_Msk     (0xc0UL)                  /*!< LVDSCMCONFIG (Bitfield-Mask: 0x03)                    */
/* ======================================================  LVDSIDLESEQ  ====================================================== */
#define RAC_LVDSIDLESEQ_LVDSIDLESEQ_Pos   (0UL)                     /*!< LVDSIDLESEQ (Bit 0)                                   */
#define RAC_LVDSIDLESEQ_LVDSIDLESEQ_Msk   (0xffUL)                  /*!< LVDSIDLESEQ (Bitfield-Mask: 0xff)                     */
/* =======================================================  LVDSROUTE  ======================================================= */
#define RAC_LVDSROUTE_LVDSPEN_Pos         (0UL)                     /*!< LVDSPEN (Bit 0)                                       */
#define RAC_LVDSROUTE_LVDSPEN_Msk         (0x1UL)                   /*!< LVDSPEN (Bitfield-Mask: 0x01)                         */
#define RAC_LVDSROUTE_LVDSLOCATION_Pos    (8UL)                     /*!< LVDSLOCATION (Bit 8)                                  */
#define RAC_LVDSROUTE_LVDSLOCATION_Msk    (0x100UL)                 /*!< LVDSLOCATION (Bitfield-Mask: 0x01)                    */
/* ====================================================  HFXORETIMECTRL  ===================================================== */
#define RAC_HFXORETIMECTRL_EN_Pos         (0UL)                     /*!< EN (Bit 0)                                            */
#define RAC_HFXORETIMECTRL_EN_Msk         (0x1UL)                   /*!< EN (Bitfield-Mask: 0x01)                              */
#define RAC_HFXORETIMECTRL_DIS_Pos        (1UL)                     /*!< DIS (Bit 1)                                           */
#define RAC_HFXORETIMECTRL_DIS_Msk        (0x2UL)                   /*!< DIS (Bitfield-Mask: 0x01)                             */
#define RAC_HFXORETIMECTRL_RESET_Pos      (2UL)                     /*!< RESET (Bit 2)                                         */
#define RAC_HFXORETIMECTRL_RESET_Msk      (0x4UL)                   /*!< RESET (Bitfield-Mask: 0x01)                           */
#define RAC_HFXORETIMECTRL_LIMITH_Pos     (4UL)                     /*!< LIMITH (Bit 4)                                        */
#define RAC_HFXORETIMECTRL_LIMITH_Msk     (0x70UL)                  /*!< LIMITH (Bitfield-Mask: 0x07)                          */
#define RAC_HFXORETIMECTRL_LIMITL_Pos     (8UL)                     /*!< LIMITL (Bit 8)                                        */
#define RAC_HFXORETIMECTRL_LIMITL_Msk     (0x700UL)                 /*!< LIMITL (Bitfield-Mask: 0x07)                          */
/* ===================================================  HFXORETIMESTATUS  ==================================================== */
#define RAC_HFXORETIMESTATUS_CLKSEL_Pos   (0UL)                     /*!< CLKSEL (Bit 0)                                        */
#define RAC_HFXORETIMESTATUS_CLKSEL_Msk   (0x1UL)                   /*!< CLKSEL (Bitfield-Mask: 0x01)                          */
#define RAC_HFXORETIMESTATUS_RERESETN_Pos (1UL)                     /*!< RERESETN (Bit 1)                                      */
#define RAC_HFXORETIMESTATUS_RERESETN_Msk (0x2UL)                   /*!< RERESETN (Bitfield-Mask: 0x01)                        */
/* =======================================================  TESTCTRL  ======================================================== */
#define RAC_TESTCTRL_MODEN_Pos            (0UL)                     /*!< MODEN (Bit 0)                                         */
#define RAC_TESTCTRL_MODEN_Msk            (0x1UL)                   /*!< MODEN (Bitfield-Mask: 0x01)                           */
#define RAC_TESTCTRL_DEMODEN_Pos          (1UL)                     /*!< DEMODEN (Bit 1)                                       */
#define RAC_TESTCTRL_DEMODEN_Msk          (0x2UL)                   /*!< DEMODEN (Bitfield-Mask: 0x01)                         */
#define RAC_TESTCTRL_AUX2RFSENSE_Pos      (2UL)                     /*!< AUX2RFSENSE (Bit 2)                                   */
#define RAC_TESTCTRL_AUX2RFSENSE_Msk      (0x4UL)                   /*!< AUX2RFSENSE (Bitfield-Mask: 0x01)                     */
#define RAC_TESTCTRL_LOOPBACK2LNAINPUT_Pos (3UL)                    /*!< LOOPBACK2LNAINPUT (Bit 3)                             */
#define RAC_TESTCTRL_LOOPBACK2LNAINPUT_Msk (0x8UL)                  /*!< LOOPBACK2LNAINPUT (Bitfield-Mask: 0x01)               */
#define RAC_TESTCTRL_LOOPBACK2LNAOUTPUT_Pos (4UL)                   /*!< LOOPBACK2LNAOUTPUT (Bit 4)                            */
#define RAC_TESTCTRL_LOOPBACK2LNAOUTPUT_Msk (0x10UL)                /*!< LOOPBACK2LNAOUTPUT (Bitfield-Mask: 0x01)              */
/* =======================================================  SEQSTATUS  ======================================================= */
#define RAC_SEQSTATUS_STOPPED_Pos         (0UL)                     /*!< STOPPED (Bit 0)                                       */
#define RAC_SEQSTATUS_STOPPED_Msk         (0x1UL)                   /*!< STOPPED (Bitfield-Mask: 0x01)                         */
#define RAC_SEQSTATUS_BKPT_Pos            (1UL)                     /*!< BKPT (Bit 1)                                          */
#define RAC_SEQSTATUS_BKPT_Msk            (0x2UL)                   /*!< BKPT (Bitfield-Mask: 0x01)                            */
#define RAC_SEQSTATUS_WAITING_Pos         (2UL)                     /*!< WAITING (Bit 2)                                       */
#define RAC_SEQSTATUS_WAITING_Msk         (0x4UL)                   /*!< WAITING (Bitfield-Mask: 0x01)                         */
#define RAC_SEQSTATUS_WAITMODE_Pos        (3UL)                     /*!< WAITMODE (Bit 3)                                      */
#define RAC_SEQSTATUS_WAITMODE_Msk        (0x8UL)                   /*!< WAITMODE (Bitfield-Mask: 0x01)                        */
#define RAC_SEQSTATUS_DONE_Pos            (4UL)                     /*!< DONE (Bit 4)                                          */
#define RAC_SEQSTATUS_DONE_Msk            (0x10UL)                  /*!< DONE (Bitfield-Mask: 0x01)                            */
#define RAC_SEQSTATUS_NEG_Pos             (5UL)                     /*!< NEG (Bit 5)                                           */
#define RAC_SEQSTATUS_NEG_Msk             (0x20UL)                  /*!< NEG (Bitfield-Mask: 0x01)                             */
#define RAC_SEQSTATUS_POS_Pos             (6UL)                     /*!< POS (Bit 6)                                           */
#define RAC_SEQSTATUS_POS_Msk             (0x40UL)                  /*!< POS (Bitfield-Mask: 0x01)                             */
#define RAC_SEQSTATUS_ZERO_Pos            (7UL)                     /*!< ZERO (Bit 7)                                          */
#define RAC_SEQSTATUS_ZERO_Msk            (0x80UL)                  /*!< ZERO (Bitfield-Mask: 0x01)                            */
#define RAC_SEQSTATUS_CARRY_Pos           (8UL)                     /*!< CARRY (Bit 8)                                         */
#define RAC_SEQSTATUS_CARRY_Msk           (0x100UL)                 /*!< CARRY (Bitfield-Mask: 0x01)                           */
#define RAC_SEQSTATUS_ABORTEN_Pos         (10UL)                    /*!< ABORTEN (Bit 10)                                      */
#define RAC_SEQSTATUS_ABORTEN_Msk         (0x400UL)                 /*!< ABORTEN (Bitfield-Mask: 0x01)                         */
/* ========================================================  SEQCMD  ========================================================= */
#define RAC_SEQCMD_HALT_Pos               (0UL)                     /*!< HALT (Bit 0)                                          */
#define RAC_SEQCMD_HALT_Msk               (0x1UL)                   /*!< HALT (Bitfield-Mask: 0x01)                            */
#define RAC_SEQCMD_STEP_Pos               (1UL)                     /*!< STEP (Bit 1)                                          */
#define RAC_SEQCMD_STEP_Msk               (0x2UL)                   /*!< STEP (Bitfield-Mask: 0x01)                            */
#define RAC_SEQCMD_RESUME_Pos             (2UL)                     /*!< RESUME (Bit 2)                                        */
#define RAC_SEQCMD_RESUME_Msk             (0x4UL)                   /*!< RESUME (Bitfield-Mask: 0x01)                          */
#define RAC_SEQCMD_BKPTEN_Pos             (3UL)                     /*!< BKPTEN (Bit 3)                                        */
#define RAC_SEQCMD_BKPTEN_Msk             (0x8UL)                   /*!< BKPTEN (Bitfield-Mask: 0x01)                          */
#define RAC_SEQCMD_BKPTDIS_Pos            (4UL)                     /*!< BKPTDIS (Bit 4)                                       */
#define RAC_SEQCMD_BKPTDIS_Msk            (0x10UL)                  /*!< BKPTDIS (Bitfield-Mask: 0x01)                         */
#define RAC_SEQCMD_ABORT_Pos              (5UL)                     /*!< ABORT (Bit 5)                                         */
#define RAC_SEQCMD_ABORT_Msk              (0x20UL)                  /*!< ABORT (Bitfield-Mask: 0x01)                           */
#define RAC_SEQCMD_ABORTENSET_Pos         (6UL)                     /*!< ABORTENSET (Bit 6)                                    */
#define RAC_SEQCMD_ABORTENSET_Msk         (0x40UL)                  /*!< ABORTENSET (Bitfield-Mask: 0x01)                      */
#define RAC_SEQCMD_ABORTENCLEAR_Pos       (7UL)                     /*!< ABORTENCLEAR (Bit 7)                                  */
#define RAC_SEQCMD_ABORTENCLEAR_Msk       (0x80UL)                  /*!< ABORTENCLEAR (Bitfield-Mask: 0x01)                    */
/* ======================================================  BREAKPOINT  ======================================================= */
#define RAC_BREAKPOINT_BKPADDR_Pos        (0UL)                     /*!< BKPADDR (Bit 0)                                       */
#define RAC_BREAKPOINT_BKPADDR_Msk        (0xffffffffUL)            /*!< BKPADDR (Bitfield-Mask: 0xffffffff)                   */
/* ==========================================================  R0  =========================================================== */
#define RAC_R0_R0_Pos                     (0UL)                     /*!< R0 (Bit 0)                                            */
#define RAC_R0_R0_Msk                     (0xffffffffUL)            /*!< R0 (Bitfield-Mask: 0xffffffff)                        */
/* ==========================================================  R1  =========================================================== */
#define RAC_R1_R1_Pos                     (0UL)                     /*!< R1 (Bit 0)                                            */
#define RAC_R1_R1_Msk                     (0xffffffffUL)            /*!< R1 (Bitfield-Mask: 0xffffffff)                        */
/* ==========================================================  R2  =========================================================== */
#define RAC_R2_R2_Pos                     (0UL)                     /*!< R2 (Bit 0)                                            */
#define RAC_R2_R2_Msk                     (0xffffffffUL)            /*!< R2 (Bitfield-Mask: 0xffffffff)                        */
/* ==========================================================  R3  =========================================================== */
#define RAC_R3_R3_Pos                     (0UL)                     /*!< R3 (Bit 0)                                            */
#define RAC_R3_R3_Msk                     (0xffffffffUL)            /*!< R3 (Bitfield-Mask: 0xffffffff)                        */
/* ==========================================================  R4  =========================================================== */
#define RAC_R4_R4_Pos                     (0UL)                     /*!< R4 (Bit 0)                                            */
#define RAC_R4_R4_Msk                     (0xffffffffUL)            /*!< R4 (Bitfield-Mask: 0xffffffff)                        */
/* ==========================================================  R5  =========================================================== */
#define RAC_R5_R5_Pos                     (0UL)                     /*!< R5 (Bit 0)                                            */
#define RAC_R5_R5_Msk                     (0xffffffffUL)            /*!< R5 (Bitfield-Mask: 0xffffffff)                        */
/* ==========================================================  R6  =========================================================== */
#define RAC_R6_R6_Pos                     (0UL)                     /*!< R6 (Bit 0)                                            */
#define RAC_R6_R6_Msk                     (0xffffffffUL)            /*!< R6 (Bitfield-Mask: 0xffffffff)                        */
/* ==========================================================  R7  =========================================================== */
#define RAC_R7_R7_Pos                     (0UL)                     /*!< R7 (Bit 0)                                            */
#define RAC_R7_R7_Msk                     (0xffffffffUL)            /*!< R7 (Bitfield-Mask: 0xffffffff)                        */
/* =======================================================  WAITMASK  ======================================================== */
#define RAC_WAITMASK_STCMP_Pos            (0UL)                     /*!< STCMP (Bit 0)                                         */
#define RAC_WAITMASK_STCMP_Msk            (0x1UL)                   /*!< STCMP (Bitfield-Mask: 0x01)                           */
#define RAC_WAITMASK_FRCRX_Pos            (1UL)                     /*!< FRCRX (Bit 1)                                         */
#define RAC_WAITMASK_FRCRX_Msk            (0x2UL)                   /*!< FRCRX (Bitfield-Mask: 0x01)                           */
#define RAC_WAITMASK_FRCTX_Pos            (2UL)                     /*!< FRCTX (Bit 2)                                         */
#define RAC_WAITMASK_FRCTX_Msk            (0x4UL)                   /*!< FRCTX (Bitfield-Mask: 0x01)                           */
#define RAC_WAITMASK_PRSEVENT_Pos         (3UL)                     /*!< PRSEVENT (Bit 3)                                      */
#define RAC_WAITMASK_PRSEVENT_Msk         (0x8UL)                   /*!< PRSEVENT (Bitfield-Mask: 0x01)                        */
#define RAC_WAITMASK_DEMODRXREQCLR_Pos    (4UL)                     /*!< DEMODRXREQCLR (Bit 4)                                 */
#define RAC_WAITMASK_DEMODRXREQCLR_Msk    (0x10UL)                  /*!< DEMODRXREQCLR (Bitfield-Mask: 0x01)                   */
#define RAC_WAITMASK_SYNTHRDY_Pos         (5UL)                     /*!< SYNTHRDY (Bit 5)                                      */
#define RAC_WAITMASK_SYNTHRDY_Msk         (0x20UL)                  /*!< SYNTHRDY (Bitfield-Mask: 0x01)                        */
#define RAC_WAITMASK_RAMPDONE_Pos         (6UL)                     /*!< RAMPDONE (Bit 6)                                      */
#define RAC_WAITMASK_RAMPDONE_Msk         (0x40UL)                  /*!< RAMPDONE (Bitfield-Mask: 0x01)                        */
#define RAC_WAITMASK_HFXORDY_Pos          (7UL)                     /*!< HFXORDY (Bit 7)                                       */
#define RAC_WAITMASK_HFXORDY_Msk          (0x80UL)                  /*!< HFXORDY (Bitfield-Mask: 0x01)                         */
#define RAC_WAITMASK_FRCPAUSED_Pos        (8UL)                     /*!< FRCPAUSED (Bit 8)                                     */
#define RAC_WAITMASK_FRCPAUSED_Msk        (0x100UL)                 /*!< FRCPAUSED (Bitfield-Mask: 0x01)                       */
/* =======================================================  WAITSNSH  ======================================================== */
#define RAC_WAITSNSH_WAITSNSH_Pos         (0UL)                     /*!< WAITSNSH (Bit 0)                                      */
#define RAC_WAITSNSH_WAITSNSH_Msk         (0x3ffUL)                 /*!< WAITSNSH (Bitfield-Mask: 0x3ff)                       */
/* ========================================================  STIMER  ========================================================= */
#define RAC_STIMER_STIMER_Pos             (0UL)                     /*!< STIMER (Bit 0)                                        */
#define RAC_STIMER_STIMER_Msk             (0xffffUL)                /*!< STIMER (Bitfield-Mask: 0xffff)                        */
/* ======================================================  STIMERCOMP  ======================================================= */
#define RAC_STIMERCOMP_STIMERCOMP_Pos     (0UL)                     /*!< STIMERCOMP (Bit 0)                                    */
#define RAC_STIMERCOMP_STIMERCOMP_Msk     (0xffffUL)                /*!< STIMERCOMP (Bitfield-Mask: 0xffff)                    */
/* =======================================================  VECTADDR  ======================================================== */
#define RAC_VECTADDR_VECTADDR_Pos         (0UL)                     /*!< VECTADDR (Bit 0)                                      */
#define RAC_VECTADDR_VECTADDR_Msk         (0xffffffffUL)            /*!< VECTADDR (Bitfield-Mask: 0xffffffff)                  */
/* ========================================================  SEQCTRL  ======================================================== */
#define RAC_SEQCTRL_COMPACT_Pos           (0UL)                     /*!< COMPACT (Bit 0)                                       */
#define RAC_SEQCTRL_COMPACT_Msk           (0x1UL)                   /*!< COMPACT (Bitfield-Mask: 0x01)                         */
#define RAC_SEQCTRL_COMPINVALMODE_Pos     (1UL)                     /*!< COMPINVALMODE (Bit 1)                                 */
#define RAC_SEQCTRL_COMPINVALMODE_Msk     (0x6UL)                   /*!< COMPINVALMODE (Bitfield-Mask: 0x03)                   */
#define RAC_SEQCTRL_PRSSEL_Pos            (4UL)                     /*!< PRSSEL (Bit 4)                                        */
#define RAC_SEQCTRL_PRSSEL_Msk            (0xf0UL)                  /*!< PRSSEL (Bitfield-Mask: 0x0f)                          */
#define RAC_SEQCTRL_STIMERDEBUGRUN_Pos    (10UL)                    /*!< STIMERDEBUGRUN (Bit 10)                               */
#define RAC_SEQCTRL_STIMERDEBUGRUN_Msk    (0x400UL)                 /*!< STIMERDEBUGRUN (Bitfield-Mask: 0x01)                  */
#define RAC_SEQCTRL_CPUHALTREQEN_Pos      (11UL)                    /*!< CPUHALTREQEN (Bit 11)                                 */
#define RAC_SEQCTRL_CPUHALTREQEN_Msk      (0x800UL)                 /*!< CPUHALTREQEN (Bitfield-Mask: 0x01)                    */
#define RAC_SEQCTRL_SEQHALTUPONCPUHALTEN_Pos (12UL)                 /*!< SEQHALTUPONCPUHALTEN (Bit 12)                         */
#define RAC_SEQCTRL_SEQHALTUPONCPUHALTEN_Msk (0x1000UL)             /*!< SEQHALTUPONCPUHALTEN (Bitfield-Mask: 0x01)            */
/* =========================================================  PRESC  ========================================================= */
#define RAC_PRESC_STIMER_Pos              (0UL)                     /*!< STIMER (Bit 0)                                        */
#define RAC_PRESC_STIMER_Msk              (0x7fUL)                  /*!< STIMER (Bitfield-Mask: 0x7f)                          */
/* ==========================================================  SR0  ========================================================== */
#define RAC_SR0_SR0_Pos                   (0UL)                     /*!< SR0 (Bit 0)                                           */
#define RAC_SR0_SR0_Msk                   (0xffffffffUL)            /*!< SR0 (Bitfield-Mask: 0xffffffff)                       */
/* ==========================================================  SR1  ========================================================== */
#define RAC_SR1_SR1_Pos                   (0UL)                     /*!< SR1 (Bit 0)                                           */
#define RAC_SR1_SR1_Msk                   (0xffffffffUL)            /*!< SR1 (Bitfield-Mask: 0xffffffff)                       */
/* ==========================================================  SR2  ========================================================== */
#define RAC_SR2_SR2_Pos                   (0UL)                     /*!< SR2 (Bit 0)                                           */
#define RAC_SR2_SR2_Msk                   (0xffffffffUL)            /*!< SR2 (Bitfield-Mask: 0xffffffff)                       */
/* ==========================================================  SR3  ========================================================== */
#define RAC_SR3_SR3_Pos                   (0UL)                     /*!< SR3 (Bit 0)                                           */
#define RAC_SR3_SR3_Msk                   (0xffffffffUL)            /*!< SR3 (Bitfield-Mask: 0xffffffff)                       */
/* ======================================================  SYNTHENCTRL  ====================================================== */
#define RAC_SYNTHENCTRL_VCOEN_Pos         (0UL)                     /*!< VCOEN (Bit 0)                                         */
#define RAC_SYNTHENCTRL_VCOEN_Msk         (0x1UL)                   /*!< VCOEN (Bitfield-Mask: 0x01)                           */
#define RAC_SYNTHENCTRL_VCOSTARTUP_Pos    (1UL)                     /*!< VCOSTARTUP (Bit 1)                                    */
#define RAC_SYNTHENCTRL_VCOSTARTUP_Msk    (0x2UL)                   /*!< VCOSTARTUP (Bitfield-Mask: 0x01)                      */
#define RAC_SYNTHENCTRL_LODIVEN_Pos       (3UL)                     /*!< LODIVEN (Bit 3)                                       */
#define RAC_SYNTHENCTRL_LODIVEN_Msk       (0x8UL)                   /*!< LODIVEN (Bitfield-Mask: 0x01)                         */
#define RAC_SYNTHENCTRL_CHPEN_Pos         (4UL)                     /*!< CHPEN (Bit 4)                                         */
#define RAC_SYNTHENCTRL_CHPEN_Msk         (0x10UL)                  /*!< CHPEN (Bitfield-Mask: 0x01)                           */
#define RAC_SYNTHENCTRL_LPFEN_Pos         (5UL)                     /*!< LPFEN (Bit 5)                                         */
#define RAC_SYNTHENCTRL_LPFEN_Msk         (0x20UL)                  /*!< LPFEN (Bitfield-Mask: 0x01)                           */
#define RAC_SYNTHENCTRL_LPFQUICKSTART_Pos (6UL)                     /*!< LPFQUICKSTART (Bit 6)                                 */
#define RAC_SYNTHENCTRL_LPFQUICKSTART_Msk (0x40UL)                  /*!< LPFQUICKSTART (Bitfield-Mask: 0x01)                   */
#define RAC_SYNTHENCTRL_VCBUFEN_Pos       (7UL)                     /*!< VCBUFEN (Bit 7)                                       */
#define RAC_SYNTHENCTRL_VCBUFEN_Msk       (0x80UL)                  /*!< VCBUFEN (Bitfield-Mask: 0x01)                         */
#define RAC_SYNTHENCTRL_SYNTHCLKEN_Pos    (8UL)                     /*!< SYNTHCLKEN (Bit 8)                                    */
#define RAC_SYNTHENCTRL_SYNTHCLKEN_Msk    (0x100UL)                 /*!< SYNTHCLKEN (Bitfield-Mask: 0x01)                      */
#define RAC_SYNTHENCTRL_SYNTHSTARTREQ_Pos (9UL)                     /*!< SYNTHSTARTREQ (Bit 9)                                 */
#define RAC_SYNTHENCTRL_SYNTHSTARTREQ_Msk (0x200UL)                 /*!< SYNTHSTARTREQ (Bitfield-Mask: 0x01)                   */
#define RAC_SYNTHENCTRL_CHPLDOEN_Pos      (10UL)                    /*!< CHPLDOEN (Bit 10)                                     */
#define RAC_SYNTHENCTRL_CHPLDOEN_Msk      (0x400UL)                 /*!< CHPLDOEN (Bitfield-Mask: 0x01)                        */
#define RAC_SYNTHENCTRL_LODIVSYNCCLKEN_Pos (11UL)                   /*!< LODIVSYNCCLKEN (Bit 11)                               */
#define RAC_SYNTHENCTRL_LODIVSYNCCLKEN_Msk (0x800UL)                /*!< LODIVSYNCCLKEN (Bitfield-Mask: 0x01)                  */
#define RAC_SYNTHENCTRL_MMDLDOEN_Pos      (13UL)                    /*!< MMDLDOEN (Bit 13)                                     */
#define RAC_SYNTHENCTRL_MMDLDOEN_Msk      (0x2000UL)                /*!< MMDLDOEN (Bitfield-Mask: 0x01)                        */
#define RAC_SYNTHENCTRL_VCOLDOEN_Pos      (14UL)                    /*!< VCOLDOEN (Bit 14)                                     */
#define RAC_SYNTHENCTRL_VCOLDOEN_Msk      (0x4000UL)                /*!< VCOLDOEN (Bitfield-Mask: 0x01)                        */
#define RAC_SYNTHENCTRL_VCODIVEN_Pos      (15UL)                    /*!< VCODIVEN (Bit 15)                                     */
#define RAC_SYNTHENCTRL_VCODIVEN_Msk      (0x8000UL)                /*!< VCODIVEN (Bitfield-Mask: 0x01)                        */
/* =====================================================  SYNTHREGCTRL  ====================================================== */
#define RAC_SYNTHREGCTRL_UNUSED3_Pos      (0UL)                     /*!< UNUSED3 (Bit 0)                                       */
#define RAC_SYNTHREGCTRL_UNUSED3_Msk      (0x1UL)                   /*!< UNUSED3 (Bitfield-Mask: 0x01)                         */
#define RAC_SYNTHREGCTRL_UNUSED1_Pos      (1UL)                     /*!< UNUSED1 (Bit 1)                                       */
#define RAC_SYNTHREGCTRL_UNUSED1_Msk      (0x2UL)                   /*!< UNUSED1 (Bitfield-Mask: 0x01)                         */
#define RAC_SYNTHREGCTRL_UNUSED2_Pos      (2UL)                     /*!< UNUSED2 (Bit 2)                                       */
#define RAC_SYNTHREGCTRL_UNUSED2_Msk      (0x4UL)                   /*!< UNUSED2 (Bitfield-Mask: 0x01)                         */
#define RAC_SYNTHREGCTRL_MMDLDOAMPBWRED_Pos (5UL)                   /*!< MMDLDOAMPBWRED (Bit 5)                                */
#define RAC_SYNTHREGCTRL_MMDLDOAMPBWRED_Msk (0x60UL)                /*!< MMDLDOAMPBWRED (Bitfield-Mask: 0x03)                  */
#define RAC_SYNTHREGCTRL_MMDLDOAMPCURR_Pos (7UL)                    /*!< MMDLDOAMPCURR (Bit 7)                                 */
#define RAC_SYNTHREGCTRL_MMDLDOAMPCURR_Msk (0x380UL)                /*!< MMDLDOAMPCURR (Bitfield-Mask: 0x07)                   */
#define RAC_SYNTHREGCTRL_MMDLDOVREFTRIM_Pos (10UL)                  /*!< MMDLDOVREFTRIM (Bit 10)                               */
#define RAC_SYNTHREGCTRL_MMDLDOVREFTRIM_Msk (0x1c00UL)              /*!< MMDLDOVREFTRIM (Bitfield-Mask: 0x07)                  */
#define RAC_SYNTHREGCTRL_VCOLDOAMPCURR_Pos (13UL)                   /*!< VCOLDOAMPCURR (Bit 13)                                */
#define RAC_SYNTHREGCTRL_VCOLDOAMPCURR_Msk (0xe000UL)               /*!< VCOLDOAMPCURR (Bitfield-Mask: 0x07)                   */
#define RAC_SYNTHREGCTRL_VCOLDOVREFTRIM_Pos (16UL)                  /*!< VCOLDOVREFTRIM (Bit 16)                               */
#define RAC_SYNTHREGCTRL_VCOLDOVREFTRIM_Msk (0x70000UL)             /*!< VCOLDOVREFTRIM (Bitfield-Mask: 0x07)                  */
#define RAC_SYNTHREGCTRL_CHPLDOAMPBWRED_Pos (19UL)                  /*!< CHPLDOAMPBWRED (Bit 19)                               */
#define RAC_SYNTHREGCTRL_CHPLDOAMPBWRED_Msk (0x180000UL)            /*!< CHPLDOAMPBWRED (Bitfield-Mask: 0x03)                  */
#define RAC_SYNTHREGCTRL_CHPLDOAMPCURR_Pos (21UL)                   /*!< CHPLDOAMPCURR (Bit 21)                                */
#define RAC_SYNTHREGCTRL_CHPLDOAMPCURR_Msk (0xe00000UL)             /*!< CHPLDOAMPCURR (Bitfield-Mask: 0x07)                   */
#define RAC_SYNTHREGCTRL_CHPLDOVREFTRIM_Pos (24UL)                  /*!< CHPLDOVREFTRIM (Bit 24)                               */
#define RAC_SYNTHREGCTRL_CHPLDOVREFTRIM_Msk (0x7000000UL)           /*!< CHPLDOVREFTRIM (Bitfield-Mask: 0x07)                  */
/* ========================================================  VCOCTRL  ======================================================== */
#define RAC_VCOCTRL_VCOAMPLITUDE_Pos      (0UL)                     /*!< VCOAMPLITUDE (Bit 0)                                  */
#define RAC_VCOCTRL_VCOAMPLITUDE_Msk      (0xfUL)                   /*!< VCOAMPLITUDE (Bitfield-Mask: 0x0f)                    */
#define RAC_VCOCTRL_VCODETAMPLITUDE_Pos   (4UL)                     /*!< VCODETAMPLITUDE (Bit 4)                               */
#define RAC_VCOCTRL_VCODETAMPLITUDE_Msk   (0xf0UL)                  /*!< VCODETAMPLITUDE (Bitfield-Mask: 0x0f)                 */
#define RAC_VCOCTRL_VCODETEN_Pos          (8UL)                     /*!< VCODETEN (Bit 8)                                      */
#define RAC_VCOCTRL_VCODETEN_Msk          (0x100UL)                 /*!< VCODETEN (Bitfield-Mask: 0x01)                        */
#define RAC_VCOCTRL_VCODETMODE_Pos        (9UL)                     /*!< VCODETMODE (Bit 9)                                    */
#define RAC_VCOCTRL_VCODETMODE_Msk        (0x200UL)                 /*!< VCODETMODE (Bitfield-Mask: 0x01)                      */
#define RAC_VCOCTRL_VCOAREGCURR_Pos       (10UL)                    /*!< VCOAREGCURR (Bit 10)                                  */
#define RAC_VCOCTRL_VCOAREGCURR_Msk       (0xc00UL)                 /*!< VCOAREGCURR (Bitfield-Mask: 0x03)                     */
#define RAC_VCOCTRL_VCOCREGCURR_Pos       (12UL)                    /*!< VCOCREGCURR (Bit 12)                                  */
#define RAC_VCOCTRL_VCOCREGCURR_Msk       (0x7000UL)                /*!< VCOCREGCURR (Bitfield-Mask: 0x07)                     */
#define RAC_VCOCTRL_UNUSED4_Pos           (22UL)                    /*!< UNUSED4 (Bit 22)                                      */
#define RAC_VCOCTRL_UNUSED4_Msk           (0xc00000UL)              /*!< UNUSED4 (Bitfield-Mask: 0x03)                         */
#define RAC_VCOCTRL_VCODIVCURR_Pos        (24UL)                    /*!< VCODIVCURR (Bit 24)                                   */
#define RAC_VCOCTRL_VCODIVCURR_Msk        (0xf000000UL)             /*!< VCODIVCURR (Bitfield-Mask: 0x0f)                      */
/* ========================================================  MMDCTRL  ======================================================== */
#define RAC_MMDCTRL_MMDDIVDCDC_Pos        (0UL)                     /*!< MMDDIVDCDC (Bit 0)                                    */
#define RAC_MMDCTRL_MMDDIVDCDC_Msk        (0x1ffUL)                 /*!< MMDDIVDCDC (Bitfield-Mask: 0x1ff)                     */
#define RAC_MMDCTRL_MMDDIVRSDCDC_Pos      (10UL)                    /*!< MMDDIVRSDCDC (Bit 10)                                 */
#define RAC_MMDCTRL_MMDDIVRSDCDC_Msk      (0xc00UL)                 /*!< MMDDIVRSDCDC (Bitfield-Mask: 0x03)                    */
#define RAC_MMDCTRL_MMDDIVRSDIG_Pos       (12UL)                    /*!< MMDDIVRSDIG (Bit 12)                                  */
#define RAC_MMDCTRL_MMDDIVRSDIG_Msk       (0x3000UL)                /*!< MMDDIVRSDIG (Bitfield-Mask: 0x03)                     */
#define RAC_MMDCTRL_MMDENDCDC_Pos         (14UL)                    /*!< MMDENDCDC (Bit 14)                                    */
#define RAC_MMDCTRL_MMDENDCDC_Msk         (0x4000UL)                /*!< MMDENDCDC (Bitfield-Mask: 0x01)                       */
#define RAC_MMDCTRL_MMDENRSDCDC_Pos       (15UL)                    /*!< MMDENRSDCDC (Bit 15)                                  */
#define RAC_MMDCTRL_MMDENRSDCDC_Msk       (0x8000UL)                /*!< MMDENRSDCDC (Bitfield-Mask: 0x01)                     */
#define RAC_MMDCTRL_MMDENRSDIG_Pos        (16UL)                    /*!< MMDENRSDIG (Bit 16)                                   */
#define RAC_MMDCTRL_MMDENRSDIG_Msk        (0x10000UL)               /*!< MMDENRSDIG (Bitfield-Mask: 0x01)                      */
/* ========================================================  CHPCTRL  ======================================================== */
#define RAC_CHPCTRL_CHPBIAS_Pos           (0UL)                     /*!< CHPBIAS (Bit 0)                                       */
#define RAC_CHPCTRL_CHPBIAS_Msk           (0x7UL)                   /*!< CHPBIAS (Bitfield-Mask: 0x07)                         */
#define RAC_CHPCTRL_CHPCURR_Pos           (3UL)                     /*!< CHPCURR (Bit 3)                                       */
#define RAC_CHPCTRL_CHPCURR_Msk           (0x38UL)                  /*!< CHPCURR (Bitfield-Mask: 0x07)                         */
#define RAC_CHPCTRL_UNUSED8_Pos           (6UL)                     /*!< UNUSED8 (Bit 6)                                       */
#define RAC_CHPCTRL_UNUSED8_Msk           (0x1c0UL)                 /*!< UNUSED8 (Bitfield-Mask: 0x07)                         */
#define RAC_CHPCTRL_UNUSED7_Pos           (9UL)                     /*!< UNUSED7 (Bit 9)                                       */
#define RAC_CHPCTRL_UNUSED7_Msk           (0x200UL)                 /*!< UNUSED7 (Bitfield-Mask: 0x01)                         */
#define RAC_CHPCTRL_UNUSED1_Pos           (10UL)                    /*!< UNUSED1 (Bit 10)                                      */
#define RAC_CHPCTRL_UNUSED1_Msk           (0x400UL)                 /*!< UNUSED1 (Bitfield-Mask: 0x01)                         */
#define RAC_CHPCTRL_UNUSED5_Pos           (11UL)                    /*!< UNUSED5 (Bit 11)                                      */
#define RAC_CHPCTRL_UNUSED5_Msk           (0x1800UL)                /*!< UNUSED5 (Bitfield-Mask: 0x03)                         */
#define RAC_CHPCTRL_UNUSED6_Pos           (13UL)                    /*!< UNUSED6 (Bit 13)                                      */
#define RAC_CHPCTRL_UNUSED6_Msk           (0x2000UL)                /*!< UNUSED6 (Bitfield-Mask: 0x01)                         */
#define RAC_CHPCTRL_CHPOUTPUTTRISTATEMODE_Pos (14UL)                /*!< CHPOUTPUTTRISTATEMODE (Bit 14)                        */
#define RAC_CHPCTRL_CHPOUTPUTTRISTATEMODE_Msk (0x4000UL)            /*!< CHPOUTPUTTRISTATEMODE (Bitfield-Mask: 0x01)           */
#define RAC_CHPCTRL_CHPSWITCHEDBIASEN_Pos (15UL)                    /*!< CHPSWITCHEDBIASEN (Bit 15)                            */
#define RAC_CHPCTRL_CHPSWITCHEDBIASEN_Msk (0x8000UL)                /*!< CHPSWITCHEDBIASEN (Bitfield-Mask: 0x01)               */
/* ========================================================  CHPCAL  ========================================================= */
#define RAC_CHPCAL_PSRC_Pos               (0UL)                     /*!< PSRC (Bit 0)                                          */
#define RAC_CHPCAL_PSRC_Msk               (0x7UL)                   /*!< PSRC (Bitfield-Mask: 0x07)                            */
#define RAC_CHPCAL_NSRC_Pos               (3UL)                     /*!< NSRC (Bit 3)                                          */
#define RAC_CHPCAL_NSRC_Msk               (0x38UL)                  /*!< NSRC (Bitfield-Mask: 0x07)                            */
/* ========================================================  LPFCTRL  ======================================================== */
#define RAC_LPFCTRL_LPFBW_Pos             (0UL)                     /*!< LPFBW (Bit 0)                                         */
#define RAC_LPFCTRL_LPFBW_Msk             (0xfUL)                   /*!< LPFBW (Bitfield-Mask: 0x0f)                           */
#define RAC_LPFCTRL_MIRACLEMODE_Pos       (4UL)                     /*!< MIRACLEMODE (Bit 4)                                   */
#define RAC_LPFCTRL_MIRACLEMODE_Msk       (0x10UL)                  /*!< MIRACLEMODE (Bitfield-Mask: 0x01)                     */
#define RAC_LPFCTRL_UNUSED9_Pos           (8UL)                     /*!< UNUSED9 (Bit 8)                                       */
#define RAC_LPFCTRL_UNUSED9_Msk           (0xf00UL)                 /*!< UNUSED9 (Bitfield-Mask: 0x0f)                         */
#define RAC_LPFCTRL_UNUSED10_Pos          (12UL)                    /*!< UNUSED10 (Bit 12)                                     */
#define RAC_LPFCTRL_UNUSED10_Msk          (0x3000UL)                /*!< UNUSED10 (Bitfield-Mask: 0x03)                        */
#define RAC_LPFCTRL_LPFINPUTCAP_Pos       (14UL)                    /*!< LPFINPUTCAP (Bit 14)                                  */
#define RAC_LPFCTRL_LPFINPUTCAP_Msk       (0xc000UL)                /*!< LPFINPUTCAP (Bitfield-Mask: 0x03)                     */
#define RAC_LPFCTRL_LPFSWITCHINGEN_Pos    (16UL)                    /*!< LPFSWITCHINGEN (Bit 16)                               */
#define RAC_LPFCTRL_LPFSWITCHINGEN_Msk    (0x10000UL)               /*!< LPFSWITCHINGEN (Bitfield-Mask: 0x01)                  */
#define RAC_LPFCTRL_LPFGNDSWITCHINGEN_Pos (17UL)                    /*!< LPFGNDSWITCHINGEN (Bit 17)                            */
#define RAC_LPFCTRL_LPFGNDSWITCHINGEN_Msk (0x20000UL)               /*!< LPFGNDSWITCHINGEN (Bitfield-Mask: 0x01)               */
/* =======================================================  SYNTHCTRL  ======================================================= */
#define RAC_SYNTHCTRL_LODIVTXEN0DBM_Pos   (1UL)                     /*!< LODIVTXEN0DBM (Bit 1)                                 */
#define RAC_SYNTHCTRL_LODIVTXEN0DBM_Msk   (0x2UL)                   /*!< LODIVTXEN0DBM (Bitfield-Mask: 0x01)                   */
#define RAC_SYNTHCTRL_LODIVTXEN_Pos       (2UL)                     /*!< LODIVTXEN (Bit 2)                                     */
#define RAC_SYNTHCTRL_LODIVTXEN_Msk       (0x4UL)                   /*!< LODIVTXEN (Bitfield-Mask: 0x01)                       */
#define RAC_SYNTHCTRL_PFDTRADMODE_Pos     (3UL)                     /*!< PFDTRADMODE (Bit 3)                                   */
#define RAC_SYNTHCTRL_PFDTRADMODE_Msk     (0x8UL)                   /*!< PFDTRADMODE (Bitfield-Mask: 0x01)                     */
#define RAC_SYNTHCTRL_MMDPOWERBALANCEDISABLE_Pos (10UL)             /*!< MMDPOWERBALANCEDISABLE (Bit 10)                       */
#define RAC_SYNTHCTRL_MMDPOWERBALANCEDISABLE_Msk (0x400UL)          /*!< MMDPOWERBALANCEDISABLE (Bitfield-Mask: 0x01)          */
/* ========================================================  AUXCTRL  ======================================================== */
#define RAC_AUXCTRL_AUXREGEN_Pos          (0UL)                     /*!< AUXREGEN (Bit 0)                                      */
#define RAC_AUXCTRL_AUXREGEN_Msk          (0x1UL)                   /*!< AUXREGEN (Bitfield-Mask: 0x01)                        */
#define RAC_AUXCTRL_VCOEN_Pos             (1UL)                     /*!< VCOEN (Bit 1)                                         */
#define RAC_AUXCTRL_VCOEN_Msk             (0x2UL)                   /*!< VCOEN (Bitfield-Mask: 0x01)                           */
#define RAC_AUXCTRL_VCOSTARTUP_Pos        (2UL)                     /*!< VCOSTARTUP (Bit 2)                                    */
#define RAC_AUXCTRL_VCOSTARTUP_Msk        (0x4UL)                   /*!< VCOSTARTUP (Bitfield-Mask: 0x01)                      */
#define RAC_AUXCTRL_CHPEN_Pos             (3UL)                     /*!< CHPEN (Bit 3)                                         */
#define RAC_AUXCTRL_CHPEN_Msk             (0x8UL)                   /*!< CHPEN (Bitfield-Mask: 0x01)                           */
#define RAC_AUXCTRL_CHPCURR_Pos           (4UL)                     /*!< CHPCURR (Bit 4)                                       */
#define RAC_AUXCTRL_CHPCURR_Msk           (0x30UL)                  /*!< CHPCURR (Bitfield-Mask: 0x03)                         */
#define RAC_AUXCTRL_LODIVEN_Pos           (6UL)                     /*!< LODIVEN (Bit 6)                                       */
#define RAC_AUXCTRL_LODIVEN_Msk           (0x40UL)                  /*!< LODIVEN (Bitfield-Mask: 0x01)                         */
#define RAC_AUXCTRL_AUXSYNTHCLKEN_Pos     (7UL)                     /*!< AUXSYNTHCLKEN (Bit 7)                                 */
#define RAC_AUXCTRL_AUXSYNTHCLKEN_Msk     (0x80UL)                  /*!< AUXSYNTHCLKEN (Bitfield-Mask: 0x01)                   */
#define RAC_AUXCTRL_LODIVSEL_Pos          (8UL)                     /*!< LODIVSEL (Bit 8)                                      */
#define RAC_AUXCTRL_LODIVSEL_Msk          (0x700UL)                 /*!< LODIVSEL (Bitfield-Mask: 0x07)                        */
#define RAC_AUXCTRL_RXAMP_Pos             (11UL)                    /*!< RXAMP (Bit 11)                                        */
#define RAC_AUXCTRL_RXAMP_Msk             (0x1f800UL)               /*!< RXAMP (Bitfield-Mask: 0x3f)                           */
#define RAC_AUXCTRL_LDOAMPCURR_Pos        (17UL)                    /*!< LDOAMPCURR (Bit 17)                                   */
#define RAC_AUXCTRL_LDOAMPCURR_Msk        (0xe0000UL)               /*!< LDOAMPCURR (Bitfield-Mask: 0x07)                      */
#define RAC_AUXCTRL_LDOVREFTRIM_Pos       (20UL)                    /*!< LDOVREFTRIM (Bit 20)                                  */
#define RAC_AUXCTRL_LDOVREFTRIM_Msk       (0x700000UL)              /*!< LDOVREFTRIM (Bitfield-Mask: 0x07)                     */
#define RAC_AUXCTRL_FPLLDIGEN_Pos         (23UL)                    /*!< FPLLDIGEN (Bit 23)                                    */
#define RAC_AUXCTRL_FPLLDIGEN_Msk         (0x800000UL)              /*!< FPLLDIGEN (Bitfield-Mask: 0x01)                       */
#define RAC_AUXCTRL_LPFRES_Pos            (24UL)                    /*!< LPFRES (Bit 24)                                       */
#define RAC_AUXCTRL_LPFRES_Msk            (0x3000000UL)             /*!< LPFRES (Bitfield-Mask: 0x03)                          */
/* =======================================================  AUXENCTRL  ======================================================= */
#define RAC_AUXENCTRL_LDOEN_Pos           (0UL)                     /*!< LDOEN (Bit 0)                                         */
#define RAC_AUXENCTRL_LDOEN_Msk           (0x1UL)                   /*!< LDOEN (Bitfield-Mask: 0x01)                           */
#define RAC_AUXENCTRL_VCBUFEN_Pos         (1UL)                     /*!< VCBUFEN (Bit 1)                                       */
#define RAC_AUXENCTRL_VCBUFEN_Msk         (0x2UL)                   /*!< VCBUFEN (Bitfield-Mask: 0x01)                         */
#define RAC_AUXENCTRL_LODIVAUXEN_Pos      (2UL)                     /*!< LODIVAUXEN (Bit 2)                                    */
#define RAC_AUXENCTRL_LODIVAUXEN_Msk      (0x4UL)                   /*!< LODIVAUXEN (Bitfield-Mask: 0x01)                      */
#define RAC_AUXENCTRL_LODIVAUXEN0DBM_Pos  (3UL)                     /*!< LODIVAUXEN0DBM (Bit 3)                                */
#define RAC_AUXENCTRL_LODIVAUXEN0DBM_Msk  (0x8UL)                   /*!< LODIVAUXEN0DBM (Bitfield-Mask: 0x01)                  */
/* =======================================================  RFENCTRL  ======================================================== */
#define RAC_RFENCTRL_IFFILTSTANDBY_Pos    (0UL)                     /*!< IFFILTSTANDBY (Bit 0)                                 */
#define RAC_RFENCTRL_IFFILTSTANDBY_Msk    (0x1UL)                   /*!< IFFILTSTANDBY (Bitfield-Mask: 0x01)                   */
#define RAC_RFENCTRL_IFFILTEREN_Pos       (1UL)                     /*!< IFFILTEREN (Bit 1)                                    */
#define RAC_RFENCTRL_IFFILTEREN_Msk       (0x2UL)                   /*!< IFFILTEREN (Bitfield-Mask: 0x01)                      */
#define RAC_RFENCTRL_PKDEN_Pos            (2UL)                     /*!< PKDEN (Bit 2)                                         */
#define RAC_RFENCTRL_PKDEN_Msk            (0x4UL)                   /*!< PKDEN (Bitfield-Mask: 0x01)                           */
#define RAC_RFENCTRL_IFPGAEN_Pos          (3UL)                     /*!< IFPGAEN (Bit 3)                                       */
#define RAC_RFENCTRL_IFPGAEN_Msk          (0x8UL)                   /*!< IFPGAEN (Bitfield-Mask: 0x01)                         */
#define RAC_RFENCTRL_IFADCEN_Pos          (4UL)                     /*!< IFADCEN (Bit 4)                                       */
#define RAC_RFENCTRL_IFADCEN_Msk          (0x10UL)                  /*!< IFADCEN (Bitfield-Mask: 0x01)                         */
#define RAC_RFENCTRL_IFADCCAPRESET_Pos    (5UL)                     /*!< IFADCCAPRESET (Bit 5)                                 */
#define RAC_RFENCTRL_IFADCCAPRESET_Msk    (0x20UL)                  /*!< IFADCCAPRESET (Bitfield-Mask: 0x01)                   */
#define RAC_RFENCTRL_IFADCCLKEN_Pos       (6UL)                     /*!< IFADCCLKEN (Bit 6)                                    */
#define RAC_RFENCTRL_IFADCCLKEN_Msk       (0x40UL)                  /*!< IFADCCLKEN (Bitfield-Mask: 0x01)                      */
#define RAC_RFENCTRL_RFBIASEN_Pos         (11UL)                    /*!< RFBIASEN (Bit 11)                                     */
#define RAC_RFENCTRL_RFBIASEN_Msk         (0x800UL)                 /*!< RFBIASEN (Bitfield-Mask: 0x01)                        */
#define RAC_RFENCTRL_DEMEN_Pos            (12UL)                    /*!< DEMEN (Bit 12)                                        */
#define RAC_RFENCTRL_DEMEN_Msk            (0x1000UL)                /*!< DEMEN (Bitfield-Mask: 0x01)                           */
#define RAC_RFENCTRL_ENABLEI_Pos          (13UL)                    /*!< ENABLEI (Bit 13)                                      */
#define RAC_RFENCTRL_ENABLEI_Msk          (0x2000UL)                /*!< ENABLEI (Bitfield-Mask: 0x01)                         */
#define RAC_RFENCTRL_ENABLEQ_Pos          (14UL)                    /*!< ENABLEQ (Bit 14)                                      */
#define RAC_RFENCTRL_ENABLEQ_Msk          (0x4000UL)                /*!< ENABLEQ (Bitfield-Mask: 0x01)                         */
#define RAC_RFENCTRL_ENLDOCLK_Pos         (15UL)                    /*!< ENLDOCLK (Bit 15)                                     */
#define RAC_RFENCTRL_ENLDOCLK_Msk         (0x8000UL)                /*!< ENLDOCLK (Bitfield-Mask: 0x01)                        */
#define RAC_RFENCTRL_ENLDOSERIES_Pos      (16UL)                    /*!< ENLDOSERIES (Bit 16)                                  */
#define RAC_RFENCTRL_ENLDOSERIES_Msk      (0x10000UL)               /*!< ENLDOSERIES (Bitfield-Mask: 0x01)                     */
#define RAC_RFENCTRL_ENLDOSHUNTI_Pos      (17UL)                    /*!< ENLDOSHUNTI (Bit 17)                                  */
#define RAC_RFENCTRL_ENLDOSHUNTI_Msk      (0x20000UL)               /*!< ENLDOSHUNTI (Bitfield-Mask: 0x01)                     */
#define RAC_RFENCTRL_ENLDOSHUNTQ_Pos      (18UL)                    /*!< ENLDOSHUNTQ (Bit 18)                                  */
#define RAC_RFENCTRL_ENLDOSHUNTQ_Msk      (0x40000UL)               /*!< ENLDOSHUNTQ (Bitfield-Mask: 0x01)                     */
#define RAC_RFENCTRL_ENLDOPGALNA_Pos      (19UL)                    /*!< ENLDOPGALNA (Bit 19)                                  */
#define RAC_RFENCTRL_ENLDOPGALNA_Msk      (0x80000UL)               /*!< ENLDOPGALNA (Bitfield-Mask: 0x01)                     */
#define RAC_RFENCTRL_ENPGA_Pos            (20UL)                    /*!< ENPGA (Bit 20)                                        */
#define RAC_RFENCTRL_ENPGA_Msk            (0x100000UL)              /*!< ENPGA (Bitfield-Mask: 0x01)                           */
/* =======================================================  RFENCTRL0  ======================================================= */
#define RAC_RFENCTRL0_LNAMIXSTANDBY_Pos   (0UL)                     /*!< LNAMIXSTANDBY (Bit 0)                                 */
#define RAC_RFENCTRL0_LNAMIXSTANDBY_Msk   (0x1UL)                   /*!< LNAMIXSTANDBY (Bitfield-Mask: 0x01)                   */
#define RAC_RFENCTRL0_LNAMIXBIASEN_Pos    (1UL)                     /*!< LNAMIXBIASEN (Bit 1)                                  */
#define RAC_RFENCTRL0_LNAMIXBIASEN_Msk    (0x2UL)                   /*!< LNAMIXBIASEN (Bitfield-Mask: 0x01)                    */
#define RAC_RFENCTRL0_LNAMIXLOBIASEN_Pos  (2UL)                     /*!< LNAMIXLOBIASEN (Bit 2)                                */
#define RAC_RFENCTRL0_LNAMIXLOBIASEN_Msk  (0x4UL)                   /*!< LNAMIXLOBIASEN (Bitfield-Mask: 0x01)                  */
#define RAC_RFENCTRL0_LNAMIXRFBIASEN_Pos  (3UL)                     /*!< LNAMIXRFBIASEN (Bit 3)                                */
#define RAC_RFENCTRL0_LNAMIXRFBIASEN_Msk  (0x8UL)                   /*!< LNAMIXRFBIASEN (Bitfield-Mask: 0x01)                  */
#define RAC_RFENCTRL0_PASTANDBY_Pos       (16UL)                    /*!< PASTANDBY (Bit 16)                                    */
#define RAC_RFENCTRL0_PASTANDBY_Msk       (0x10000UL)               /*!< PASTANDBY (Bitfield-Mask: 0x01)                       */
#define RAC_RFENCTRL0_PAEN_Pos            (17UL)                    /*!< PAEN (Bit 17)                                         */
#define RAC_RFENCTRL0_PAEN_Msk            (0x20000UL)               /*!< PAEN (Bitfield-Mask: 0x01)                            */
#define RAC_RFENCTRL0_PAOUTEN_Pos         (18UL)                    /*!< PAOUTEN (Bit 18)                                      */
#define RAC_RFENCTRL0_PAOUTEN_Msk         (0x40000UL)               /*!< PAOUTEN (Bitfield-Mask: 0x01)                         */
#define RAC_RFENCTRL0_TRSW_Pos            (19UL)                    /*!< TRSW (Bit 19)                                         */
#define RAC_RFENCTRL0_TRSW_Msk            (0x80000UL)               /*!< TRSW (Bitfield-Mask: 0x01)                            */
/* ======================================================  LNAMIXCTRL  ======================================================= */
#define RAC_LNAMIXCTRL_RF2P4BANDWIDTH_Pos (0UL)                     /*!< RF2P4BANDWIDTH (Bit 0)                                */
#define RAC_LNAMIXCTRL_RF2P4BANDWIDTH_Msk (0x1fUL)                  /*!< RF2P4BANDWIDTH (Bitfield-Mask: 0x1f)                  */
#define RAC_LNAMIXCTRL_CASCODEBIAS_Pos    (8UL)                     /*!< CASCODEBIAS (Bit 8)                                   */
#define RAC_LNAMIXCTRL_CASCODEBIAS_Msk    (0x700UL)                 /*!< CASCODEBIAS (Bitfield-Mask: 0x07)                     */
#define RAC_LNAMIXCTRL_LOBIAS_Pos         (11UL)                    /*!< LOBIAS (Bit 11)                                       */
#define RAC_LNAMIXCTRL_LOBIAS_Msk         (0x3800UL)                /*!< LOBIAS (Bitfield-Mask: 0x07)                          */
#define RAC_LNAMIXCTRL_VREG_Pos           (14UL)                    /*!< VREG (Bit 14)                                         */
#define RAC_LNAMIXCTRL_VREG_Msk           (0x1c000UL)               /*!< VREG (Bitfield-Mask: 0x07)                            */
#define RAC_LNAMIXCTRL_RFBIAS_Pos         (17UL)                    /*!< RFBIAS (Bit 17)                                       */
#define RAC_LNAMIXCTRL_RFBIAS_Msk         (0x1e0000UL)              /*!< RFBIAS (Bitfield-Mask: 0x0f)                          */
#define RAC_LNAMIXCTRL_RISEFALLATT_Pos    (21UL)                    /*!< RISEFALLATT (Bit 21)                                  */
#define RAC_LNAMIXCTRL_RISEFALLATT_Msk    (0xe00000UL)              /*!< RISEFALLATT (Bitfield-Mask: 0x07)                     */
#define RAC_LNAMIXCTRL_LNAMIXAUXSYNTHINPUTEN_Pos (26UL)             /*!< LNAMIXAUXSYNTHINPUTEN (Bit 26)                        */
#define RAC_LNAMIXCTRL_LNAMIXAUXSYNTHINPUTEN_Msk (0x4000000UL)      /*!< LNAMIXAUXSYNTHINPUTEN (Bitfield-Mask: 0x01)           */
#define RAC_LNAMIXCTRL_ENLOAD_Pos         (30UL)                    /*!< ENLOAD (Bit 30)                                       */
#define RAC_LNAMIXCTRL_ENLOAD_Msk         (0x40000000UL)            /*!< ENLOAD (Bitfield-Mask: 0x01)                          */
/* ========================================================  PACTRL0  ======================================================== */
#define RAC_PACTRL0_RF2P4PASEL_Pos        (0UL)                     /*!< RF2P4PASEL (Bit 0)                                    */
#define RAC_PACTRL0_RF2P4PASEL_Msk        (0x1UL)                   /*!< RF2P4PASEL (Bitfield-Mask: 0x01)                      */
#define RAC_PACTRL0_RF2P4PAVDDSEL_Pos     (1UL)                     /*!< RF2P4PAVDDSEL (Bit 1)                                 */
#define RAC_PACTRL0_RF2P4PAVDDSEL_Msk     (0x2UL)                   /*!< RF2P4PAVDDSEL (Bitfield-Mask: 0x01)                   */
#define RAC_PACTRL0_RF2P4RFVDDSEL_Pos     (2UL)                     /*!< RF2P4RFVDDSEL (Bit 2)                                 */
#define RAC_PACTRL0_RF2P4RFVDDSEL_Msk     (0x4UL)                   /*!< RF2P4RFVDDSEL (Bitfield-Mask: 0x01)                   */
#define RAC_PACTRL0_BOOTSTRAP_Pos         (3UL)                     /*!< BOOTSTRAP (Bit 3)                                     */
#define RAC_PACTRL0_BOOTSTRAP_Msk         (0x8UL)                   /*!< BOOTSTRAP (Bitfield-Mask: 0x01)                       */
#define RAC_PACTRL0_RF2P4VDDPADET_Pos     (4UL)                     /*!< RF2P4VDDPADET (Bit 4)                                 */
#define RAC_PACTRL0_RF2P4VDDPADET_Msk     (0x10UL)                  /*!< RF2P4VDDPADET (Bitfield-Mask: 0x01)                   */
#define RAC_PACTRL0_CASCODE_Pos           (6UL)                     /*!< CASCODE (Bit 6)                                       */
#define RAC_PACTRL0_CASCODE_Msk           (0x3fc0UL)                /*!< CASCODE (Bitfield-Mask: 0xff)                         */
#define RAC_PACTRL0_SLICE_Pos             (14UL)                    /*!< SLICE (Bit 14)                                        */
#define RAC_PACTRL0_SLICE_Msk             (0x3fc000UL)              /*!< SLICE (Bitfield-Mask: 0xff)                           */
#define RAC_PACTRL0_STRIPE_Pos            (24UL)                    /*!< STRIPE (Bit 24)                                       */
#define RAC_PACTRL0_STRIPE_Msk            (0x1f000000UL)            /*!< STRIPE (Bitfield-Mask: 0x1f)                          */
#define RAC_PACTRL0_DACGLITCHCTRL_Pos     (30UL)                    /*!< DACGLITCHCTRL (Bit 30)                                */
#define RAC_PACTRL0_DACGLITCHCTRL_Msk     (0x40000000UL)            /*!< DACGLITCHCTRL (Bitfield-Mask: 0x01)                   */
#define RAC_PACTRL0_CASCODEBYPASSEN_Pos   (31UL)                    /*!< CASCODEBYPASSEN (Bit 31)                              */
#define RAC_PACTRL0_CASCODEBYPASSEN_Msk   (0x80000000UL)            /*!< CASCODEBYPASSEN (Bitfield-Mask: 0x01)                 */
/* =======================================================  PAPKDCTRL  ======================================================= */
#define RAC_PAPKDCTRL_PKDEN_Pos           (0UL)                     /*!< PKDEN (Bit 0)                                         */
#define RAC_PAPKDCTRL_PKDEN_Msk           (0x1UL)                   /*!< PKDEN (Bitfield-Mask: 0x01)                           */
#define RAC_PAPKDCTRL_VTLSEL_Pos          (2UL)                     /*!< VTLSEL (Bit 2)                                        */
#define RAC_PAPKDCTRL_VTLSEL_Msk          (0x7cUL)                  /*!< VTLSEL (Bitfield-Mask: 0x1f)                          */
#define RAC_PAPKDCTRL_VTHSEL_Pos          (8UL)                     /*!< VTHSEL (Bit 8)                                        */
#define RAC_PAPKDCTRL_VTHSEL_Msk          (0x1f00UL)                /*!< VTHSEL (Bitfield-Mask: 0x1f)                          */
#define RAC_PAPKDCTRL_CAPSEL_Pos          (14UL)                    /*!< CAPSEL (Bit 14)                                       */
#define RAC_PAPKDCTRL_CAPSEL_Msk          (0xc000UL)                /*!< CAPSEL (Bitfield-Mask: 0x03)                          */
#define RAC_PAPKDCTRL_I2VCM_Pos           (18UL)                    /*!< I2VCM (Bit 18)                                        */
#define RAC_PAPKDCTRL_I2VCM_Msk           (0xc0000UL)               /*!< I2VCM (Bitfield-Mask: 0x03)                           */
#define RAC_PAPKDCTRL_PKDBIASTH_Pos       (22UL)                    /*!< PKDBIASTH (Bit 22)                                    */
#define RAC_PAPKDCTRL_PKDBIASTH_Msk       (0x1c00000UL)             /*!< PKDBIASTH (Bitfield-Mask: 0x07)                       */
/* ======================================================  PABIASCTRL0  ====================================================== */
#define RAC_PABIASCTRL0_LDOBIAS_Pos       (0UL)                     /*!< LDOBIAS (Bit 0)                                       */
#define RAC_PABIASCTRL0_LDOBIAS_Msk       (0x1UL)                   /*!< LDOBIAS (Bitfield-Mask: 0x01)                         */
#define RAC_PABIASCTRL0_PABIAS_Pos        (2UL)                     /*!< PABIAS (Bit 2)                                        */
#define RAC_PABIASCTRL0_PABIAS_Msk        (0xcUL)                   /*!< PABIAS (Bitfield-Mask: 0x03)                          */
#define RAC_PABIASCTRL0_BUF0BIAS_Pos      (6UL)                     /*!< BUF0BIAS (Bit 6)                                      */
#define RAC_PABIASCTRL0_BUF0BIAS_Msk      (0xc0UL)                  /*!< BUF0BIAS (Bitfield-Mask: 0x03)                        */
#define RAC_PABIASCTRL0_BUF12BIAS_Pos     (10UL)                    /*!< BUF12BIAS (Bit 10)                                    */
#define RAC_PABIASCTRL0_BUF12BIAS_Msk     (0xc00UL)                 /*!< BUF12BIAS (Bitfield-Mask: 0x03)                       */
#define RAC_PABIASCTRL0_TXPOWER_Pos       (22UL)                    /*!< TXPOWER (Bit 22)                                      */
#define RAC_PABIASCTRL0_TXPOWER_Msk       (0x400000UL)              /*!< TXPOWER (Bitfield-Mask: 0x01)                         */
#define RAC_PABIASCTRL0_CMGAIN_Pos        (23UL)                    /*!< CMGAIN (Bit 23)                                       */
#define RAC_PABIASCTRL0_CMGAIN_Msk        (0x800000UL)              /*!< CMGAIN (Bitfield-Mask: 0x01)                          */
/* ======================================================  PABIASCTRL1  ====================================================== */
#define RAC_PABIASCTRL1_VLDO_Pos          (0UL)                     /*!< VLDO (Bit 0)                                          */
#define RAC_PABIASCTRL1_VLDO_Msk          (0x7UL)                   /*!< VLDO (Bitfield-Mask: 0x07)                            */
#define RAC_PABIASCTRL1_VLDOFB_Pos        (4UL)                     /*!< VLDOFB (Bit 4)                                        */
#define RAC_PABIASCTRL1_VLDOFB_Msk        (0x30UL)                  /*!< VLDOFB (Bitfield-Mask: 0x03)                          */
#define RAC_PABIASCTRL1_VCASCODEHV_Pos    (8UL)                     /*!< VCASCODEHV (Bit 8)                                    */
#define RAC_PABIASCTRL1_VCASCODEHV_Msk    (0x700UL)                 /*!< VCASCODEHV (Bitfield-Mask: 0x07)                      */
#define RAC_PABIASCTRL1_VCASCODELV_Pos    (12UL)                    /*!< VCASCODELV (Bit 12)                                   */
#define RAC_PABIASCTRL1_VCASCODELV_Msk    (0x7000UL)                /*!< VCASCODELV (Bitfield-Mask: 0x07)                      */
#define RAC_PABIASCTRL1_RF2P4VDDPATHRESHOLD_Pos (16UL)              /*!< RF2P4VDDPATHRESHOLD (Bit 16)                          */
#define RAC_PABIASCTRL1_RF2P4VDDPATHRESHOLD_Msk (0x30000UL)         /*!< RF2P4VDDPATHRESHOLD (Bitfield-Mask: 0x03)             */
/* ======================================================  SGRFENCTRL0  ====================================================== */
#define RAC_SGRFENCTRL0_LNAMIXBIASEN_Pos  (1UL)                     /*!< LNAMIXBIASEN (Bit 1)                                  */
#define RAC_SGRFENCTRL0_LNAMIXBIASEN_Msk  (0x2UL)                   /*!< LNAMIXBIASEN (Bitfield-Mask: 0x01)                    */
#define RAC_SGRFENCTRL0_LNAMIXLOBIASEN_Pos (2UL)                    /*!< LNAMIXLOBIASEN (Bit 2)                                */
#define RAC_SGRFENCTRL0_LNAMIXLOBIASEN_Msk (0x4UL)                  /*!< LNAMIXLOBIASEN (Bitfield-Mask: 0x01)                  */
#define RAC_SGRFENCTRL0_LNAMIXRFBIASEN_Pos (3UL)                    /*!< LNAMIXRFBIASEN (Bit 3)                                */
#define RAC_SGRFENCTRL0_LNAMIXRFBIASEN_Msk (0x8UL)                  /*!< LNAMIXRFBIASEN (Bitfield-Mask: 0x01)                  */
#define RAC_SGRFENCTRL0_PASTANDBY_Pos     (16UL)                    /*!< PASTANDBY (Bit 16)                                    */
#define RAC_SGRFENCTRL0_PASTANDBY_Msk     (0x10000UL)               /*!< PASTANDBY (Bitfield-Mask: 0x01)                       */
#define RAC_SGRFENCTRL0_PAEN_Pos          (17UL)                    /*!< PAEN (Bit 17)                                         */
#define RAC_SGRFENCTRL0_PAEN_Msk          (0x20000UL)               /*!< PAEN (Bitfield-Mask: 0x01)                            */
#define RAC_SGRFENCTRL0_PAOUTEN_Pos       (18UL)                    /*!< PAOUTEN (Bit 18)                                      */
#define RAC_SGRFENCTRL0_PAOUTEN_Msk       (0x40000UL)               /*!< PAOUTEN (Bitfield-Mask: 0x01)                         */
#define RAC_SGRFENCTRL0_TRSW_Pos          (19UL)                    /*!< TRSW (Bit 19)                                         */
#define RAC_SGRFENCTRL0_TRSW_Msk          (0x80000UL)               /*!< TRSW (Bitfield-Mask: 0x01)                            */
/* =====================================================  SGLNAMIXCTRL  ====================================================== */
#define RAC_SGLNAMIXCTRL_CASCODEBIAS_Pos  (8UL)                     /*!< CASCODEBIAS (Bit 8)                                   */
#define RAC_SGLNAMIXCTRL_CASCODEBIAS_Msk  (0x700UL)                 /*!< CASCODEBIAS (Bitfield-Mask: 0x07)                     */
#define RAC_SGLNAMIXCTRL_LOBIAS_Pos       (11UL)                    /*!< LOBIAS (Bit 11)                                       */
#define RAC_SGLNAMIXCTRL_LOBIAS_Msk       (0x3800UL)                /*!< LOBIAS (Bitfield-Mask: 0x07)                          */
#define RAC_SGLNAMIXCTRL_VREG_Pos         (14UL)                    /*!< VREG (Bit 14)                                         */
#define RAC_SGLNAMIXCTRL_VREG_Msk         (0x1c000UL)               /*!< VREG (Bitfield-Mask: 0x07)                            */
#define RAC_SGLNAMIXCTRL_RFBIAS_Pos       (17UL)                    /*!< RFBIAS (Bit 17)                                       */
#define RAC_SGLNAMIXCTRL_RFBIAS_Msk       (0xe0000UL)               /*!< RFBIAS (Bitfield-Mask: 0x07)                          */
#define RAC_SGLNAMIXCTRL_RISEFALLATT_Pos  (20UL)                    /*!< RISEFALLATT (Bit 20)                                  */
#define RAC_SGLNAMIXCTRL_RISEFALLATT_Msk  (0x700000UL)              /*!< RISEFALLATT (Bitfield-Mask: 0x07)                     */
#define RAC_SGLNAMIXCTRL_SGREGAMPCURR_Pos (23UL)                    /*!< SGREGAMPCURR (Bit 23)                                 */
#define RAC_SGLNAMIXCTRL_SGREGAMPCURR_Msk (0x3800000UL)             /*!< SGREGAMPCURR (Bitfield-Mask: 0x07)                    */
#define RAC_SGLNAMIXCTRL_LNAMIXAUXSYNTHINPUTEN_Pos (26UL)           /*!< LNAMIXAUXSYNTHINPUTEN (Bit 26)                        */
#define RAC_SGLNAMIXCTRL_LNAMIXAUXSYNTHINPUTEN_Msk (0x4000000UL)    /*!< LNAMIXAUXSYNTHINPUTEN (Bitfield-Mask: 0x01)           */
#define RAC_SGLNAMIXCTRL_SGREGAMPBWRED_Pos (28UL)                   /*!< SGREGAMPBWRED (Bit 28)                                */
#define RAC_SGLNAMIXCTRL_SGREGAMPBWRED_Msk (0x30000000UL)           /*!< SGREGAMPBWRED (Bitfield-Mask: 0x03)                   */
#define RAC_SGLNAMIXCTRL_ENLOAD_Pos       (30UL)                    /*!< ENLOAD (Bit 30)                                       */
#define RAC_SGLNAMIXCTRL_ENLOAD_Msk       (0x40000000UL)            /*!< ENLOAD (Bitfield-Mask: 0x01)                          */
/* =======================================================  SGPACTRL0  ======================================================= */
#define RAC_SGPACTRL0_BOOTSTRAP_Pos       (3UL)                     /*!< BOOTSTRAP (Bit 3)                                     */
#define RAC_SGPACTRL0_BOOTSTRAP_Msk       (0x8UL)                   /*!< BOOTSTRAP (Bitfield-Mask: 0x01)                       */
#define RAC_SGPACTRL0_SGVBATDET_Pos       (5UL)                     /*!< SGVBATDET (Bit 5)                                     */
#define RAC_SGPACTRL0_SGVBATDET_Msk       (0x20UL)                  /*!< SGVBATDET (Bitfield-Mask: 0x01)                       */
#define RAC_SGPACTRL0_CASCODE_Pos         (6UL)                     /*!< CASCODE (Bit 6)                                       */
#define RAC_SGPACTRL0_CASCODE_Msk         (0x3fc0UL)                /*!< CASCODE (Bitfield-Mask: 0xff)                         */
#define RAC_SGPACTRL0_SLICE_Pos           (14UL)                    /*!< SLICE (Bit 14)                                        */
#define RAC_SGPACTRL0_SLICE_Msk           (0x3fc000UL)              /*!< SLICE (Bitfield-Mask: 0xff)                           */
#define RAC_SGPACTRL0_STRIPE_Pos          (24UL)                    /*!< STRIPE (Bit 24)                                       */
#define RAC_SGPACTRL0_STRIPE_Msk          (0x1f000000UL)            /*!< STRIPE (Bitfield-Mask: 0x1f)                          */
#define RAC_SGPACTRL0_DACGLITCHCTRL_Pos   (30UL)                    /*!< DACGLITCHCTRL (Bit 30)                                */
#define RAC_SGPACTRL0_DACGLITCHCTRL_Msk   (0x40000000UL)            /*!< DACGLITCHCTRL (Bitfield-Mask: 0x01)                   */
#define RAC_SGPACTRL0_CASCODEBYPASSEN_Pos (31UL)                    /*!< CASCODEBYPASSEN (Bit 31)                              */
#define RAC_SGPACTRL0_CASCODEBYPASSEN_Msk (0x80000000UL)            /*!< CASCODEBYPASSEN (Bitfield-Mask: 0x01)                 */
/* ======================================================  SGPAPKDCTRL  ====================================================== */
#define RAC_SGPAPKDCTRL_PKDEN_Pos         (0UL)                     /*!< PKDEN (Bit 0)                                         */
#define RAC_SGPAPKDCTRL_PKDEN_Msk         (0x1UL)                   /*!< PKDEN (Bitfield-Mask: 0x01)                           */
#define RAC_SGPAPKDCTRL_VTLSEL_Pos        (2UL)                     /*!< VTLSEL (Bit 2)                                        */
#define RAC_SGPAPKDCTRL_VTLSEL_Msk        (0x7cUL)                  /*!< VTLSEL (Bitfield-Mask: 0x1f)                          */
#define RAC_SGPAPKDCTRL_VTHSEL_Pos        (8UL)                     /*!< VTHSEL (Bit 8)                                        */
#define RAC_SGPAPKDCTRL_VTHSEL_Msk        (0x1f00UL)                /*!< VTHSEL (Bitfield-Mask: 0x1f)                          */
#define RAC_SGPAPKDCTRL_CAPSEL_Pos        (14UL)                    /*!< CAPSEL (Bit 14)                                       */
#define RAC_SGPAPKDCTRL_CAPSEL_Msk        (0xc000UL)                /*!< CAPSEL (Bitfield-Mask: 0x03)                          */
#define RAC_SGPAPKDCTRL_I2VCM_Pos         (18UL)                    /*!< I2VCM (Bit 18)                                        */
#define RAC_SGPAPKDCTRL_I2VCM_Msk         (0xc0000UL)               /*!< I2VCM (Bitfield-Mask: 0x03)                           */
#define RAC_SGPAPKDCTRL_PKDBIASTH_Pos     (22UL)                    /*!< PKDBIASTH (Bit 22)                                    */
#define RAC_SGPAPKDCTRL_PKDBIASTH_Msk     (0x1c00000UL)             /*!< PKDBIASTH (Bitfield-Mask: 0x07)                       */
/* =====================================================  SGPABIASCTRL0  ===================================================== */
#define RAC_SGPABIASCTRL0_LDOBIAS_Pos     (0UL)                     /*!< LDOBIAS (Bit 0)                                       */
#define RAC_SGPABIASCTRL0_LDOBIAS_Msk     (0x1UL)                   /*!< LDOBIAS (Bitfield-Mask: 0x01)                         */
#define RAC_SGPABIASCTRL0_PABIAS_Pos      (2UL)                     /*!< PABIAS (Bit 2)                                        */
#define RAC_SGPABIASCTRL0_PABIAS_Msk      (0xcUL)                   /*!< PABIAS (Bitfield-Mask: 0x03)                          */
#define RAC_SGPABIASCTRL0_BUF0BIAS_Pos    (6UL)                     /*!< BUF0BIAS (Bit 6)                                      */
#define RAC_SGPABIASCTRL0_BUF0BIAS_Msk    (0xc0UL)                  /*!< BUF0BIAS (Bitfield-Mask: 0x03)                        */
#define RAC_SGPABIASCTRL0_BUF12BIAS_Pos   (12UL)                    /*!< BUF12BIAS (Bit 12)                                    */
#define RAC_SGPABIASCTRL0_BUF12BIAS_Msk   (0x3000UL)                /*!< BUF12BIAS (Bitfield-Mask: 0x03)                       */
#define RAC_SGPABIASCTRL0_TXPOWER_Pos     (22UL)                    /*!< TXPOWER (Bit 22)                                      */
#define RAC_SGPABIASCTRL0_TXPOWER_Msk     (0x400000UL)              /*!< TXPOWER (Bitfield-Mask: 0x01)                         */
#define RAC_SGPABIASCTRL0_CMGAIN_Pos      (23UL)                    /*!< CMGAIN (Bit 23)                                       */
#define RAC_SGPABIASCTRL0_CMGAIN_Msk      (0x800000UL)              /*!< CMGAIN (Bitfield-Mask: 0x01)                          */
#define RAC_SGPABIASCTRL0_SGDACFILTBANDWIDTH_Pos (24UL)             /*!< SGDACFILTBANDWIDTH (Bit 24)                           */
#define RAC_SGPABIASCTRL0_SGDACFILTBANDWIDTH_Msk (0x7000000UL)      /*!< SGDACFILTBANDWIDTH (Bitfield-Mask: 0x07)              */
/* =====================================================  SGPABIASCTRL1  ===================================================== */
#define RAC_SGPABIASCTRL1_VLDO_Pos        (0UL)                     /*!< VLDO (Bit 0)                                          */
#define RAC_SGPABIASCTRL1_VLDO_Msk        (0x7UL)                   /*!< VLDO (Bitfield-Mask: 0x07)                            */
#define RAC_SGPABIASCTRL1_VLDOFB_Pos      (4UL)                     /*!< VLDOFB (Bit 4)                                        */
#define RAC_SGPABIASCTRL1_VLDOFB_Msk      (0x30UL)                  /*!< VLDOFB (Bitfield-Mask: 0x03)                          */
#define RAC_SGPABIASCTRL1_VCASCODEHV_Pos  (8UL)                     /*!< VCASCODEHV (Bit 8)                                    */
#define RAC_SGPABIASCTRL1_VCASCODEHV_Msk  (0x700UL)                 /*!< VCASCODEHV (Bitfield-Mask: 0x07)                      */
#define RAC_SGPABIASCTRL1_VCASCODELV_Pos  (12UL)                    /*!< VCASCODELV (Bit 12)                                   */
#define RAC_SGPABIASCTRL1_VCASCODELV_Msk  (0x7000UL)                /*!< VCASCODELV (Bitfield-Mask: 0x07)                      */
#define RAC_SGPABIASCTRL1_SGVBATDETTHRESHOLD_Pos (18UL)             /*!< SGVBATDETTHRESHOLD (Bit 18)                           */
#define RAC_SGPABIASCTRL1_SGVBATDETTHRESHOLD_Msk (0xc0000UL)        /*!< SGVBATDETTHRESHOLD (Bitfield-Mask: 0x03)              */
#define RAC_SGPABIASCTRL1_SGTRIMLOWVBATCURR_Pos (20UL)              /*!< SGTRIMLOWVBATCURR (Bit 20)                            */
#define RAC_SGPABIASCTRL1_SGTRIMLOWVBATCURR_Msk (0x100000UL)        /*!< SGTRIMLOWVBATCURR (Bitfield-Mask: 0x01)               */
/* =======================================================  RFSTATUS  ======================================================== */
#define RAC_RFSTATUS_MODRAMPUPDONE_Pos    (0UL)                     /*!< MODRAMPUPDONE (Bit 0)                                 */
#define RAC_RFSTATUS_MODRAMPUPDONE_Msk    (0x1UL)                   /*!< MODRAMPUPDONE (Bitfield-Mask: 0x01)                   */
#define RAC_RFSTATUS_PAVHIGH_Pos          (1UL)                     /*!< PAVHIGH (Bit 1)                                       */
#define RAC_RFSTATUS_PAVHIGH_Msk          (0x2UL)                   /*!< PAVHIGH (Bitfield-Mask: 0x01)                         */
#define RAC_RFSTATUS_PAVLOW_Pos           (2UL)                     /*!< PAVLOW (Bit 2)                                        */
#define RAC_RFSTATUS_PAVLOW_Msk           (0x4UL)                   /*!< PAVLOW (Bitfield-Mask: 0x01)                          */
#define RAC_RFSTATUS_PABATHIGH_Pos        (3UL)                     /*!< PABATHIGH (Bit 3)                                     */
#define RAC_RFSTATUS_PABATHIGH_Msk        (0x8UL)                   /*!< PABATHIGH (Bitfield-Mask: 0x01)                       */
/* ======================================================  RFBIASCTRL  ======================================================= */
#define RAC_RFBIASCTRL_LDOVREF_Pos        (0UL)                     /*!< LDOVREF (Bit 0)                                       */
#define RAC_RFBIASCTRL_LDOVREF_Msk        (0x7UL)                   /*!< LDOVREF (Bitfield-Mask: 0x07)                         */
#define RAC_RFBIASCTRL_LDOAMPCURR_Pos     (4UL)                     /*!< LDOAMPCURR (Bit 4)                                    */
#define RAC_RFBIASCTRL_LDOAMPCURR_Msk     (0x70UL)                  /*!< LDOAMPCURR (Bitfield-Mask: 0x07)                      */
#define RAC_RFBIASCTRL_STARTUPSUPPLY_Pos  (16UL)                    /*!< STARTUPSUPPLY (Bit 16)                                */
#define RAC_RFBIASCTRL_STARTUPSUPPLY_Msk  (0x10000UL)               /*!< STARTUPSUPPLY (Bitfield-Mask: 0x01)                   */
#define RAC_RFBIASCTRL_STARTUPCORE_Pos    (17UL)                    /*!< STARTUPCORE (Bit 17)                                  */
#define RAC_RFBIASCTRL_STARTUPCORE_Msk    (0x20000UL)               /*!< STARTUPCORE (Bitfield-Mask: 0x01)                     */
#define RAC_RFBIASCTRL_DISBOOTSTRAP_Pos   (18UL)                    /*!< DISBOOTSTRAP (Bit 18)                                 */
#define RAC_RFBIASCTRL_DISBOOTSTRAP_Msk   (0x40000UL)               /*!< DISBOOTSTRAP (Bitfield-Mask: 0x01)                    */
/* =======================================================  RFBIASCAL  ======================================================= */
#define RAC_RFBIASCAL_VREF_Pos            (0UL)                     /*!< VREF (Bit 0)                                          */
#define RAC_RFBIASCAL_VREF_Msk            (0x3fUL)                  /*!< VREF (Bitfield-Mask: 0x3f)                            */
#define RAC_RFBIASCAL_BIAS_Pos            (8UL)                     /*!< BIAS (Bit 8)                                          */
#define RAC_RFBIASCAL_BIAS_Msk            (0x3f00UL)                /*!< BIAS (Bitfield-Mask: 0x3f)                            */
#define RAC_RFBIASCAL_TEMPCO_Pos          (16UL)                    /*!< TEMPCO (Bit 16)                                       */
#define RAC_RFBIASCAL_TEMPCO_Msk          (0x3f0000UL)              /*!< TEMPCO (Bitfield-Mask: 0x3f)                          */
/* ======================================================  LNAMIXCTRL1  ====================================================== */
#define RAC_LNAMIXCTRL1_TRIMAUXPLLCLK_Pos (1UL)                     /*!< TRIMAUXPLLCLK (Bit 1)                                 */
#define RAC_LNAMIXCTRL1_TRIMAUXPLLCLK_Msk (0x1eUL)                  /*!< TRIMAUXPLLCLK (Bitfield-Mask: 0x0f)                   */
#define RAC_LNAMIXCTRL1_TRIMTRSWGATEV_Pos (5UL)                     /*!< TRIMTRSWGATEV (Bit 5)                                 */
#define RAC_LNAMIXCTRL1_TRIMTRSWGATEV_Msk (0x60UL)                  /*!< TRIMTRSWGATEV (Bitfield-Mask: 0x03)                   */
#define RAC_LNAMIXCTRL1_TRIMVCASLDO_Pos   (7UL)                     /*!< TRIMVCASLDO (Bit 7)                                   */
#define RAC_LNAMIXCTRL1_TRIMVCASLDO_Msk   (0x80UL)                  /*!< TRIMVCASLDO (Bitfield-Mask: 0x01)                     */
#define RAC_LNAMIXCTRL1_TRIMVREFLDO_Pos   (8UL)                     /*!< TRIMVREFLDO (Bit 8)                                   */
#define RAC_LNAMIXCTRL1_TRIMVREFLDO_Msk   (0x700UL)                 /*!< TRIMVREFLDO (Bitfield-Mask: 0x07)                     */
#define RAC_LNAMIXCTRL1_TRIMVREGMIN_Pos   (11UL)                    /*!< TRIMVREGMIN (Bit 11)                                  */
#define RAC_LNAMIXCTRL1_TRIMVREGMIN_Msk   (0x1800UL)                /*!< TRIMVREGMIN (Bitfield-Mask: 0x03)                     */
#define RAC_LNAMIXCTRL1_TRIMAUXBIAS_Pos   (13UL)                    /*!< TRIMAUXBIAS (Bit 13)                                  */
#define RAC_LNAMIXCTRL1_TRIMAUXBIAS_Msk   (0x6000UL)                /*!< TRIMAUXBIAS (Bitfield-Mask: 0x03)                     */
#define RAC_LNAMIXCTRL1_ENBIASCAL_Pos     (15UL)                    /*!< ENBIASCAL (Bit 15)                                    */
#define RAC_LNAMIXCTRL1_ENBIASCAL_Msk     (0x8000UL)                /*!< ENBIASCAL (Bitfield-Mask: 0x01)                       */
#define RAC_LNAMIXCTRL1_STATUSBIASCAL_Pos (16UL)                    /*!< STATUSBIASCAL (Bit 16)                                */
#define RAC_LNAMIXCTRL1_STATUSBIASCAL_Msk (0x10000UL)               /*!< STATUSBIASCAL (Bitfield-Mask: 0x01)                   */
#define RAC_LNAMIXCTRL1_TRIMAUXPLLGAIN_Pos (17UL)                   /*!< TRIMAUXPLLGAIN (Bit 17)                               */
#define RAC_LNAMIXCTRL1_TRIMAUXPLLGAIN_Msk (0x1e0000UL)             /*!< TRIMAUXPLLGAIN (Bitfield-Mask: 0x0f)                  */
#define RAC_LNAMIXCTRL1_TRIMLDOAMPBWRED_Pos (21UL)                  /*!< TRIMLDOAMPBWRED (Bit 21)                              */
#define RAC_LNAMIXCTRL1_TRIMLDOAMPBWRED_Msk (0x600000UL)            /*!< TRIMLDOAMPBWRED (Bitfield-Mask: 0x03)                 */
/* =======================================================  IFPGACTRL  ======================================================= */
#define RAC_IFPGACTRL_VLDO_Pos            (1UL)                     /*!< VLDO (Bit 1)                                          */
#define RAC_IFPGACTRL_VLDO_Msk            (0xeUL)                   /*!< VLDO (Bitfield-Mask: 0x07)                            */
#define RAC_IFPGACTRL_BANDSEL_Pos         (4UL)                     /*!< BANDSEL (Bit 4)                                       */
#define RAC_IFPGACTRL_BANDSEL_Msk         (0x10UL)                  /*!< BANDSEL (Bitfield-Mask: 0x01)                         */
#define RAC_IFPGACTRL_CASCBIAS_Pos        (5UL)                     /*!< CASCBIAS (Bit 5)                                      */
#define RAC_IFPGACTRL_CASCBIAS_Msk        (0xe0UL)                  /*!< CASCBIAS (Bitfield-Mask: 0x07)                        */
#define RAC_IFPGACTRL_TRIMVCASLDO_Pos     (8UL)                     /*!< TRIMVCASLDO (Bit 8)                                   */
#define RAC_IFPGACTRL_TRIMVCASLDO_Msk     (0x100UL)                 /*!< TRIMVCASLDO (Bitfield-Mask: 0x01)                     */
#define RAC_IFPGACTRL_TRIMVCM_Pos         (9UL)                     /*!< TRIMVCM (Bit 9)                                       */
#define RAC_IFPGACTRL_TRIMVCM_Msk         (0xe00UL)                 /*!< TRIMVCM (Bitfield-Mask: 0x07)                         */
#define RAC_IFPGACTRL_TRIMVREFLDO_Pos     (12UL)                    /*!< TRIMVREFLDO (Bit 12)                                  */
#define RAC_IFPGACTRL_TRIMVREFLDO_Msk     (0x7000UL)                /*!< TRIMVREFLDO (Bitfield-Mask: 0x07)                     */
#define RAC_IFPGACTRL_TRIMVREGMIN_Pos     (15UL)                    /*!< TRIMVREGMIN (Bit 15)                                  */
#define RAC_IFPGACTRL_TRIMVREGMIN_Msk     (0x18000UL)               /*!< TRIMVREGMIN (Bitfield-Mask: 0x03)                     */
#define RAC_IFPGACTRL_ENHYST_Pos          (17UL)                    /*!< ENHYST (Bit 17)                                       */
#define RAC_IFPGACTRL_ENHYST_Msk          (0x20000UL)               /*!< ENHYST (Bitfield-Mask: 0x01)                          */
#define RAC_IFPGACTRL_ENOFFD_Pos          (18UL)                    /*!< ENOFFD (Bit 18)                                       */
#define RAC_IFPGACTRL_ENOFFD_Msk          (0x40000UL)               /*!< ENOFFD (Bitfield-Mask: 0x01)                          */
/* =======================================================  IFPGACAL  ======================================================== */
#define RAC_IFPGACAL_IRAMP_Pos            (0UL)                     /*!< IRAMP (Bit 0)                                         */
#define RAC_IFPGACAL_IRAMP_Msk            (0x7fUL)                  /*!< IRAMP (Bitfield-Mask: 0x7f)                           */
#define RAC_IFPGACAL_IRPHASE_Pos          (8UL)                     /*!< IRPHASE (Bit 8)                                       */
#define RAC_IFPGACAL_IRPHASE_Msk          (0x7f00UL)                /*!< IRPHASE (Bitfield-Mask: 0x7f)                         */
#define RAC_IFPGACAL_OFFSETI_Pos          (16UL)                    /*!< OFFSETI (Bit 16)                                      */
#define RAC_IFPGACAL_OFFSETI_Msk          (0x7f0000UL)              /*!< OFFSETI (Bitfield-Mask: 0x7f)                         */
#define RAC_IFPGACAL_OFFSETQ_Pos          (24UL)                    /*!< OFFSETQ (Bit 24)                                      */
#define RAC_IFPGACAL_OFFSETQ_Msk          (0x7f000000UL)            /*!< OFFSETQ (Bitfield-Mask: 0x7f)                         */
/* ======================================================  IFFILTCTRL  ======================================================= */
#define RAC_IFFILTCTRL_BANDWIDTH_Pos      (0UL)                     /*!< BANDWIDTH (Bit 0)                                     */
#define RAC_IFFILTCTRL_BANDWIDTH_Msk      (0xfUL)                   /*!< BANDWIDTH (Bitfield-Mask: 0x0f)                       */
#define RAC_IFFILTCTRL_CENTFREQ_Pos       (5UL)                     /*!< CENTFREQ (Bit 5)                                      */
#define RAC_IFFILTCTRL_CENTFREQ_Msk       (0xe0UL)                  /*!< CENTFREQ (Bitfield-Mask: 0x07)                        */
#define RAC_IFFILTCTRL_VCM_Pos            (18UL)                    /*!< VCM (Bit 18)                                          */
#define RAC_IFFILTCTRL_VCM_Msk            (0xc0000UL)               /*!< VCM (Bitfield-Mask: 0x03)                             */
#define RAC_IFFILTCTRL_VREG_Pos           (21UL)                    /*!< VREG (Bit 21)                                         */
#define RAC_IFFILTCTRL_VREG_Msk           (0xe00000UL)              /*!< VREG (Bitfield-Mask: 0x07)                            */
#define RAC_IFFILTCTRL_DROOP_Pos          (25UL)                    /*!< DROOP (Bit 25)                                        */
#define RAC_IFFILTCTRL_DROOP_Msk          (0x6000000UL)             /*!< DROOP (Bitfield-Mask: 0x03)                           */
#define RAC_IFFILTCTRL_INPUTSHORT_Pos     (31UL)                    /*!< INPUTSHORT (Bit 31)                                   */
#define RAC_IFFILTCTRL_INPUTSHORT_Msk     (0x80000000UL)            /*!< INPUTSHORT (Bitfield-Mask: 0x01)                      */
/* =======================================================  IFADCCTRL  ======================================================= */
#define RAC_IFADCCTRL_REALMODE_Pos        (0UL)                     /*!< REALMODE (Bit 0)                                      */
#define RAC_IFADCCTRL_REALMODE_Msk        (0x1UL)                   /*!< REALMODE (Bitfield-Mask: 0x01)                        */
#define RAC_IFADCCTRL_INPUTSEL_Pos        (1UL)                     /*!< INPUTSEL (Bit 1)                                      */
#define RAC_IFADCCTRL_INPUTSEL_Msk        (0x2UL)                   /*!< INPUTSEL (Bitfield-Mask: 0x01)                        */
#define RAC_IFADCCTRL_INPUTSCALE_Pos      (2UL)                     /*!< INPUTSCALE (Bit 2)                                    */
#define RAC_IFADCCTRL_INPUTSCALE_Msk      (0xcUL)                   /*!< INPUTSCALE (Bitfield-Mask: 0x03)                      */
#define RAC_IFADCCTRL_SHORTI_Pos          (4UL)                     /*!< SHORTI (Bit 4)                                        */
#define RAC_IFADCCTRL_SHORTI_Msk          (0x10UL)                  /*!< SHORTI (Bitfield-Mask: 0x01)                          */
#define RAC_IFADCCTRL_SHORTQ_Pos          (5UL)                     /*!< SHORTQ (Bit 5)                                        */
#define RAC_IFADCCTRL_SHORTQ_Msk          (0x20UL)                  /*!< SHORTQ (Bitfield-Mask: 0x01)                          */
#define RAC_IFADCCTRL_VLDOSERIES_Pos      (6UL)                     /*!< VLDOSERIES (Bit 6)                                    */
#define RAC_IFADCCTRL_VLDOSERIES_Msk      (0x1c0UL)                 /*!< VLDOSERIES (Bitfield-Mask: 0x07)                      */
#define RAC_IFADCCTRL_VLDOSERIESCURR_Pos  (9UL)                     /*!< VLDOSERIESCURR (Bit 9)                                */
#define RAC_IFADCCTRL_VLDOSERIESCURR_Msk  (0xe00UL)                 /*!< VLDOSERIESCURR (Bitfield-Mask: 0x07)                  */
#define RAC_IFADCCTRL_VLDOSHUNT_Pos       (12UL)                    /*!< VLDOSHUNT (Bit 12)                                    */
#define RAC_IFADCCTRL_VLDOSHUNT_Msk       (0x3000UL)                /*!< VLDOSHUNT (Bitfield-Mask: 0x03)                       */
#define RAC_IFADCCTRL_VLDOCLKGEN_Pos      (14UL)                    /*!< VLDOCLKGEN (Bit 14)                                   */
#define RAC_IFADCCTRL_VLDOCLKGEN_Msk      (0xc000UL)                /*!< VLDOCLKGEN (Bitfield-Mask: 0x03)                      */
#define RAC_IFADCCTRL_VCM_Pos             (16UL)                    /*!< VCM (Bit 16)                                          */
#define RAC_IFADCCTRL_VCM_Msk             (0x70000UL)               /*!< VCM (Bitfield-Mask: 0x07)                             */
#define RAC_IFADCCTRL_OTA1CURRENT_Pos     (19UL)                    /*!< OTA1CURRENT (Bit 19)                                  */
#define RAC_IFADCCTRL_OTA1CURRENT_Msk     (0x180000UL)              /*!< OTA1CURRENT (Bitfield-Mask: 0x03)                     */
#define RAC_IFADCCTRL_OTA2CURRENT_Pos     (21UL)                    /*!< OTA2CURRENT (Bit 21)                                  */
#define RAC_IFADCCTRL_OTA2CURRENT_Msk     (0x600000UL)              /*!< OTA2CURRENT (Bitfield-Mask: 0x03)                     */
#define RAC_IFADCCTRL_OTA3CURRENT_Pos     (23UL)                    /*!< OTA3CURRENT (Bit 23)                                  */
#define RAC_IFADCCTRL_OTA3CURRENT_Msk     (0x1800000UL)             /*!< OTA3CURRENT (Bitfield-Mask: 0x03)                     */
#define RAC_IFADCCTRL_SATURATIONDETDIS_Pos (25UL)                   /*!< SATURATIONDETDIS (Bit 25)                             */
#define RAC_IFADCCTRL_SATURATIONDETDIS_Msk (0x2000000UL)            /*!< SATURATIONDETDIS (Bitfield-Mask: 0x01)                */
#define RAC_IFADCCTRL_REGENCLKDELAY_Pos   (26UL)                    /*!< REGENCLKDELAY (Bit 26)                                */
#define RAC_IFADCCTRL_REGENCLKDELAY_Msk   (0x1c000000UL)            /*!< REGENCLKDELAY (Bitfield-Mask: 0x07)                   */
#define RAC_IFADCCTRL_ENABLECLK_Pos       (29UL)                    /*!< ENABLECLK (Bit 29)                                    */
#define RAC_IFADCCTRL_ENABLECLK_Msk       (0x20000000UL)            /*!< ENABLECLK (Bitfield-Mask: 0x01)                       */
#define RAC_IFADCCTRL_INVERTCLK_Pos       (30UL)                    /*!< INVERTCLK (Bit 30)                                    */
#define RAC_IFADCCTRL_INVERTCLK_Msk       (0x40000000UL)            /*!< INVERTCLK (Bitfield-Mask: 0x01)                       */
/* =======================================================  IFADCCAL  ======================================================== */
#define RAC_IFADCCAL_CALEN_Pos            (4UL)                     /*!< CALEN (Bit 4)                                         */
#define RAC_IFADCCAL_CALEN_Msk            (0x10UL)                  /*!< CALEN (Bitfield-Mask: 0x01)                           */
#define RAC_IFADCCAL_RCCALOUT_Pos         (5UL)                     /*!< RCCALOUT (Bit 5)                                      */
#define RAC_IFADCCAL_RCCALOUT_Msk         (0x20UL)                  /*!< RCCALOUT (Bitfield-Mask: 0x01)                        */
/* =======================================================  PAENCTRL  ======================================================== */
#define RAC_PAENCTRL_PACTUNEN_Pos         (2UL)                     /*!< PACTUNEN (Bit 2)                                      */
#define RAC_PAENCTRL_PACTUNEN_Msk         (0x4UL)                   /*!< PACTUNEN (Bitfield-Mask: 0x01)                        */
#define RAC_PAENCTRL_PARAMP_Pos           (8UL)                     /*!< PARAMP (Bit 8)                                        */
#define RAC_PAENCTRL_PARAMP_Msk           (0x100UL)                 /*!< PARAMP (Bitfield-Mask: 0x01)                          */
/* ======================================================  PACTUNECTRL  ====================================================== */
#define RAC_PACTUNECTRL_PACTUNE_Pos       (0UL)                     /*!< PACTUNE (Bit 0)                                       */
#define RAC_PACTUNECTRL_PACTUNE_Msk       (0x7UL)                   /*!< PACTUNE (Bitfield-Mask: 0x07)                         */
#define RAC_PACTUNECTRL_SGPACTUNE_Pos     (4UL)                     /*!< SGPACTUNE (Bit 4)                                     */
#define RAC_PACTUNECTRL_SGPACTUNE_Msk     (0x1f0UL)                 /*!< SGPACTUNE (Bitfield-Mask: 0x1f)                       */
/* ========================================================  RCTUNE  ========================================================= */
#define RAC_RCTUNE_IFADCRCTUNE_Pos        (0UL)                     /*!< IFADCRCTUNE (Bit 0)                                   */
#define RAC_RCTUNE_IFADCRCTUNE_Msk        (0x3fUL)                  /*!< IFADCRCTUNE (Bitfield-Mask: 0x3f)                     */
#define RAC_RCTUNE_IFFILT_Pos             (16UL)                    /*!< IFFILT (Bit 16)                                       */
#define RAC_RCTUNE_IFFILT_Msk             (0x3f0000UL)              /*!< IFFILT (Bitfield-Mask: 0x3f)                          */
/* ==========================================================  APC  ========================================================== */
#define RAC_APC_ENPASTATUSVDDPA_Pos       (0UL)                     /*!< ENPASTATUSVDDPA (Bit 0)                               */
#define RAC_APC_ENPASTATUSVDDPA_Msk       (0x1UL)                   /*!< ENPASTATUSVDDPA (Bitfield-Mask: 0x01)                 */
#define RAC_APC_ENPASTATUSPKDVTH_Pos      (1UL)                     /*!< ENPASTATUSPKDVTH (Bit 1)                              */
#define RAC_APC_ENPASTATUSPKDVTH_Msk      (0x2UL)                   /*!< ENPASTATUSPKDVTH (Bitfield-Mask: 0x01)                */
#define RAC_APC_ENAPCSW_Pos               (2UL)                     /*!< ENAPCSW (Bit 2)                                       */
#define RAC_APC_ENAPCSW_Msk               (0x4UL)                   /*!< ENAPCSW (Bitfield-Mask: 0x01)                         */
#define RAC_APC_AMPCONTROLLIMITSW_Pos     (24UL)                    /*!< AMPCONTROLLIMITSW (Bit 24)                            */
#define RAC_APC_AMPCONTROLLIMITSW_Msk     (0xff000000UL)            /*!< AMPCONTROLLIMITSW (Bitfield-Mask: 0xff)               */
/* =========================================================  SPARE  ========================================================= */
#define RAC_SPARE_SYNTHSPARE_Pos          (0UL)                     /*!< SYNTHSPARE (Bit 0)                                    */
#define RAC_SPARE_SYNTHSPARE_Msk          (0xffUL)                  /*!< SYNTHSPARE (Bitfield-Mask: 0xff)                      */
#define RAC_SPARE_LNAMIXERSPARE_Pos       (8UL)                     /*!< LNAMIXERSPARE (Bit 8)                                 */
#define RAC_SPARE_LNAMIXERSPARE_Msk       (0x300UL)                 /*!< LNAMIXERSPARE (Bitfield-Mask: 0x03)                   */
#define RAC_SPARE_IFFILTSPARE_Pos         (10UL)                    /*!< IFFILTSPARE (Bit 10)                                  */
#define RAC_SPARE_IFFILTSPARE_Msk         (0x1c00UL)                /*!< IFFILTSPARE (Bitfield-Mask: 0x07)                     */
#define RAC_SPARE_IFPGASPARE_Pos          (13UL)                    /*!< IFPGASPARE (Bit 13)                                   */
#define RAC_SPARE_IFPGASPARE_Msk          (0x6000UL)                /*!< IFPGASPARE (Bitfield-Mask: 0x03)                      */
#define RAC_SPARE_IFFILTSPARE0_Pos        (15UL)                    /*!< IFFILTSPARE0 (Bit 15)                                 */
#define RAC_SPARE_IFFILTSPARE0_Msk        (0x18000UL)               /*!< IFFILTSPARE0 (Bitfield-Mask: 0x03)                    */
#define RAC_SPARE_IFFILTSPARE1_Pos        (17UL)                    /*!< IFFILTSPARE1 (Bit 17)                                 */
#define RAC_SPARE_IFFILTSPARE1_Msk        (0x60000UL)               /*!< IFFILTSPARE1 (Bitfield-Mask: 0x03)                    */
#define RAC_SPARE_IFFILTSPARE2_Pos        (19UL)                    /*!< IFFILTSPARE2 (Bit 19)                                 */
#define RAC_SPARE_IFFILTSPARE2_Msk        (0x180000UL)              /*!< IFFILTSPARE2 (Bitfield-Mask: 0x03)                    */
#define RAC_SPARE_IFADCSPARE_Pos          (21UL)                    /*!< IFADCSPARE (Bit 21)                                   */
#define RAC_SPARE_IFADCSPARE_Msk          (0xe00000UL)              /*!< IFADCSPARE (Bitfield-Mask: 0x07)                      */
#define RAC_SPARE_PASPARE_Pos             (24UL)                    /*!< PASPARE (Bit 24)                                      */
#define RAC_SPARE_PASPARE_Msk             (0x7000000UL)             /*!< PASPARE (Bitfield-Mask: 0x07)                         */
#define RAC_SPARE_SGPASPARE_Pos           (27UL)                    /*!< SGPASPARE (Bit 27)                                    */
#define RAC_SPARE_SGPASPARE_Msk           (0x38000000UL)            /*!< SGPASPARE (Bitfield-Mask: 0x07)                       */
#define RAC_SPARE_SGLNAMIXSPARE_Pos       (30UL)                    /*!< SGLNAMIXSPARE (Bit 30)                                */
#define RAC_SPARE_SGLNAMIXSPARE_Msk       (0xc0000000UL)            /*!< SGLNAMIXSPARE (Bitfield-Mask: 0x03)                   */


/** @} */
/** @} End of group EFR32FG1V_RAC */
/** @} End of group Parts */
