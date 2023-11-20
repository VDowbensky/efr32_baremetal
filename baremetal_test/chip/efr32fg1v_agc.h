/***************************************************************************//**
 * @file
 * @brief EFR32FG1V_AGC register and bit field definitions
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
/* =========================================================================================================================== */
/* ================                                            AGC                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Auto gain controller (AGC)
  */

typedef struct {                                /*!< (@ 0x40087000) AGC Structure                                              */
  __IM  uint32_t  STATUS0;                      /*!< (@ 0x00000000) STATUS0                                                    */
  __IM  uint32_t  STATUS1;                      /*!< (@ 0x00000004) STATUS1                                                    */
  __IM  uint32_t  RSSI;                         /*!< (@ 0x00000008) RSSI                                                       */
  __IM  uint32_t  FRAMERSSI;                    /*!< (@ 0x0000000C) FRAMERSSI                                                  */
  __IM  uint32_t  RESERVED;
  __IOM uint32_t  CTRL0;                        /*!< (@ 0x00000014) CTRL0                                                      */
  __IOM uint32_t  CTRL1;                        /*!< (@ 0x00000018) CTRL1                                                      */
  __IOM uint32_t  CTRL2;                        /*!< (@ 0x0000001C) CTRL2                                                      */
  __IOM uint32_t  RSSISTEPTHR;                  /*!< (@ 0x00000020) RSSISTEPTHR                                                */
  __IOM uint32_t  IFPEAKDET;                    /*!< (@ 0x00000024) IFPEAKDET                                                  */
  __IOM uint32_t  MANGAIN;                      /*!< (@ 0x00000028) MANGAIN                                                    */
  __IM  uint32_t  RESERVED1;
  __IM  uint32_t  IF;                           /*!< (@ 0x00000030) IF                                                         */
  __OM  uint32_t  IFS;                          /*!< (@ 0x00000034) IFS                                                        */
  __OM  uint32_t  IFC;                          /*!< (@ 0x00000038) IFC                                                        */
  __IOM uint32_t  IEN;                          /*!< (@ 0x0000003C) IEN                                                        */
  __OM  uint32_t  CMD;                          /*!< (@ 0x00000040) CMD                                                        */
  __IM  uint32_t  RESERVED2;
  __IOM uint32_t  GAINRANGE;                    /*!< (@ 0x00000048) GAINRANGE                                                  */
  __IOM uint32_t  GAININDEX;                    /*!< (@ 0x0000004C) GAININDEX                                                  */
  __IOM uint32_t  SLICECODE;                    /*!< (@ 0x00000050) SLICECODE                                                  */
  __IOM uint32_t  ATTENCODE1;                   /*!< (@ 0x00000054) ATTENCODE1                                                 */
  __IOM uint32_t  ATTENCODE2;                   /*!< (@ 0x00000058) ATTENCODE2                                                 */
  __IOM uint32_t  ATTENCODE3;                   /*!< (@ 0x0000005C) ATTENCODE3                                                 */
  __IOM uint32_t  GAINERROR1;                   /*!< (@ 0x00000060) GAINERROR1                                                 */
  __IOM uint32_t  GAINERROR2;                   /*!< (@ 0x00000064) GAINERROR2                                                 */
  __IOM uint32_t  GAINERROR3;                   /*!< (@ 0x00000068) GAINERROR3                                                 */
  __IOM uint32_t  MANUALCTRL;                   /*!< (@ 0x0000006C) MANUALCTRL                                                 */
  __IOM uint32_t  GAINSTEPLIM;                  /*!< (@ 0x00000070) GAINSTEPLIM                                                */
  __IOM uint32_t  LOOPDEL;                      /*!< (@ 0x00000074) LOOPDEL                                                    */
  __IOM uint32_t  MININDEX;                     /*!< (@ 0x00000078) MININDEX                                                   */
} AGC_Typedef;                                     /*!< Size = 124 (0x7c)                                                         */

                 /** @} */

/***************************************************************************//**
 * @addtogroup EFR32FG1V_AGC
 * @{
 * @defgroup EFR32FG1V_ADC_BitFields  AGC Bit Fields
 * @{
 ******************************************************************************/

/* =========================================================================================================================== */
/* ================                                            AGC                                            ================ */
/* =========================================================================================================================== */

/* ========================================================  STATUS0  ======================================================== */
#define AGC_STATUS0_GAININDEX_Pos         (0UL)                     /*!< GAININDEX (Bit 0)                                     */
#define AGC_STATUS0_GAININDEX_Msk         (0x3fUL)                  /*!< GAININDEX (Bitfield-Mask: 0x3f)                       */
#define AGC_STATUS0_CCA_Pos               (10UL)                    /*!< CCA (Bit 10)                                          */
#define AGC_STATUS0_CCA_Msk               (0x400UL)                 /*!< CCA (Bitfield-Mask: 0x01)                             */
#define AGC_STATUS0_GAINOK_Pos            (12UL)                    /*!< GAINOK (Bit 12)                                       */
#define AGC_STATUS0_GAINOK_Msk            (0x1000UL)                /*!< GAINOK (Bitfield-Mask: 0x01)                          */
#define AGC_STATUS0_GAINIFPGA_Pos         (13UL)                    /*!< GAINIFPGA (Bit 13)                                    */
#define AGC_STATUS0_GAINIFPGA_Msk         (0x1e000UL)               /*!< GAINIFPGA (Bitfield-Mask: 0x0f)                       */
#define AGC_STATUS0_GAINLNADEGEN_Pos      (17UL)                    /*!< GAINLNADEGEN (Bit 17)                                 */
#define AGC_STATUS0_GAINLNADEGEN_Msk      (0xe0000UL)               /*!< GAINLNADEGEN (Bitfield-Mask: 0x07)                    */
#define AGC_STATUS0_GAINLNASLICE_Pos      (20UL)                    /*!< GAINLNASLICE (Bit 20)                                 */
#define AGC_STATUS0_GAINLNASLICE_Msk      (0xf00000UL)              /*!< GAINLNASLICE (Bitfield-Mask: 0x0f)                    */
#define AGC_STATUS0_GAINLNAATTEN_Pos      (25UL)                    /*!< GAINLNAATTEN (Bit 25)                                 */
#define AGC_STATUS0_GAINLNAATTEN_Msk      (0x3e000000UL)            /*!< GAINLNAATTEN (Bitfield-Mask: 0x1f)                    */
/* ========================================================  STATUS1  ======================================================== */
#define AGC_STATUS1_CHPWR_Pos             (0UL)                     /*!< CHPWR (Bit 0)                                         */
#define AGC_STATUS1_CHPWR_Msk             (0xffUL)                  /*!< CHPWR (Bitfield-Mask: 0xff)                           */
#define AGC_STATUS1_ADCSTABILITYDET_Pos   (9UL)                     /*!< ADCSTABILITYDET (Bit 9)                               */
#define AGC_STATUS1_ADCSTABILITYDET_Msk   (0x200UL)                 /*!< ADCSTABILITYDET (Bitfield-Mask: 0x01)                 */
#define AGC_STATUS1_PGAPEAKDET2_Pos       (10UL)                    /*!< PGAPEAKDET2 (Bit 10)                                  */
#define AGC_STATUS1_PGAPEAKDET2_Msk       (0x400UL)                 /*!< PGAPEAKDET2 (Bitfield-Mask: 0x01)                     */
#define AGC_STATUS1_PGAPEAKDET1_Pos       (11UL)                    /*!< PGAPEAKDET1 (Bit 11)                                  */
#define AGC_STATUS1_PGAPEAKDET1_Msk       (0x800UL)                 /*!< PGAPEAKDET1 (Bitfield-Mask: 0x01)                     */
#define AGC_STATUS1_CFLOOPSTATE_Pos       (12UL)                    /*!< CFLOOPSTATE (Bit 12)                                  */
#define AGC_STATUS1_CFLOOPSTATE_Msk       (0x3000UL)                /*!< CFLOOPSTATE (Bitfield-Mask: 0x03)                     */
#define AGC_STATUS1_FASTLOOPSTATE_Pos     (14UL)                    /*!< FASTLOOPSTATE (Bit 14)                                */
#define AGC_STATUS1_FASTLOOPSTATE_Msk     (0x1c000UL)               /*!< FASTLOOPSTATE (Bitfield-Mask: 0x07)                   */
/* =========================================================  RSSI  ========================================================== */
#define AGC_RSSI_RSSIFRAC_Pos             (6UL)                     /*!< RSSIFRAC (Bit 6)                                      */
#define AGC_RSSI_RSSIFRAC_Msk             (0xc0UL)                  /*!< RSSIFRAC (Bitfield-Mask: 0x03)                        */
#define AGC_RSSI_RSSIINT_Pos              (8UL)                     /*!< RSSIINT (Bit 8)                                       */
#define AGC_RSSI_RSSIINT_Msk              (0xff00UL)                /*!< RSSIINT (Bitfield-Mask: 0xff)                         */
/* =======================================================  FRAMERSSI  ======================================================= */
#define AGC_FRAMERSSI_FRAMERSSIFRAC_Pos   (6UL)                     /*!< FRAMERSSIFRAC (Bit 6)                                 */
#define AGC_FRAMERSSI_FRAMERSSIFRAC_Msk   (0xc0UL)                  /*!< FRAMERSSIFRAC (Bitfield-Mask: 0x03)                   */
#define AGC_FRAMERSSI_FRAMERSSIINT_Pos    (8UL)                     /*!< FRAMERSSIINT (Bit 8)                                  */
#define AGC_FRAMERSSI_FRAMERSSIINT_Msk    (0xff00UL)                /*!< FRAMERSSIINT (Bitfield-Mask: 0xff)                    */
/* =========================================================  CTRL0  ========================================================= */
#define AGC_CTRL0_PWRTARGET_Pos           (0UL)                     /*!< PWRTARGET (Bit 0)                                     */
#define AGC_CTRL0_PWRTARGET_Msk           (0xffUL)                  /*!< PWRTARGET (Bitfield-Mask: 0xff)                       */
#define AGC_CTRL0_MODE_Pos                (8UL)                     /*!< MODE (Bit 8)                                          */
#define AGC_CTRL0_MODE_Msk                (0x700UL)                 /*!< MODE (Bitfield-Mask: 0x07)                            */
#define AGC_CTRL0_RSSISHIFT_Pos           (11UL)                    /*!< RSSISHIFT (Bit 11)                                    */
#define AGC_CTRL0_RSSISHIFT_Msk           (0x7f800UL)               /*!< RSSISHIFT (Bitfield-Mask: 0xff)                       */
#define AGC_CTRL0_DISCFLOOPADJ_Pos        (19UL)                    /*!< DISCFLOOPADJ (Bit 19)                                 */
#define AGC_CTRL0_DISCFLOOPADJ_Msk        (0x80000UL)               /*!< DISCFLOOPADJ (Bitfield-Mask: 0x01)                    */
#define AGC_CTRL0_USEADCSATDET_Pos        (20UL)                    /*!< USEADCSATDET (Bit 20)                                 */
#define AGC_CTRL0_USEADCSATDET_Msk        (0x100000UL)              /*!< USEADCSATDET (Bitfield-Mask: 0x01)                    */
#define AGC_CTRL0_AGCCLKUNDIVREQ_Pos      (21UL)                    /*!< AGCCLKUNDIVREQ (Bit 21)                               */
#define AGC_CTRL0_AGCCLKUNDIVREQ_Msk      (0x200000UL)              /*!< AGCCLKUNDIVREQ (Bitfield-Mask: 0x01)                  */
#define AGC_CTRL0_DISRESETCHPWR_Pos       (22UL)                    /*!< DISRESETCHPWR (Bit 22)                                */
#define AGC_CTRL0_DISRESETCHPWR_Msk       (0x400000UL)              /*!< DISRESETCHPWR (Bitfield-Mask: 0x01)                   */
#define AGC_CTRL0_ADCRESETDURATION_Pos    (23UL)                    /*!< ADCRESETDURATION (Bit 23)                             */
#define AGC_CTRL0_ADCRESETDURATION_Msk    (0x1800000UL)             /*!< ADCRESETDURATION (Bitfield-Mask: 0x03)                */
/* =========================================================  CTRL1  ========================================================= */
#define AGC_CTRL1_CCATHRSH_Pos            (0UL)                     /*!< CCATHRSH (Bit 0)                                      */
#define AGC_CTRL1_CCATHRSH_Msk            (0xffUL)                  /*!< CCATHRSH (Bitfield-Mask: 0xff)                        */
#define AGC_CTRL1_RSSIPERIOD_Pos          (8UL)                     /*!< RSSIPERIOD (Bit 8)                                    */
#define AGC_CTRL1_RSSIPERIOD_Msk          (0xf00UL)                 /*!< RSSIPERIOD (Bitfield-Mask: 0x0f)                      */
#define AGC_CTRL1_AGCPERIOD_Pos           (12UL)                    /*!< AGCPERIOD (Bit 12)                                    */
#define AGC_CTRL1_AGCPERIOD_Msk           (0x7000UL)                /*!< AGCPERIOD (Bitfield-Mask: 0x07)                       */
#define AGC_CTRL1_SUBPERIOD_Pos           (15UL)                    /*!< SUBPERIOD (Bit 15)                                    */
#define AGC_CTRL1_SUBPERIOD_Msk           (0x8000UL)                /*!< SUBPERIOD (Bitfield-Mask: 0x01)                       */
#define AGC_CTRL1_SUBNUM_Pos              (16UL)                    /*!< SUBNUM (Bit 16)                                       */
#define AGC_CTRL1_SUBNUM_Msk              (0x1f0000UL)              /*!< SUBNUM (Bitfield-Mask: 0x1f)                          */
#define AGC_CTRL1_SUBDEN_Pos              (21UL)                    /*!< SUBDEN (Bit 21)                                       */
#define AGC_CTRL1_SUBDEN_Msk              (0x3e00000UL)             /*!< SUBDEN (Bitfield-Mask: 0x1f)                          */
#define AGC_CTRL1_SUBINT_Pos              (26UL)                    /*!< SUBINT (Bit 26)                                       */
#define AGC_CTRL1_SUBINT_Msk              (0xfc000000UL)            /*!< SUBINT (Bitfield-Mask: 0x3f)                          */
/* =========================================================  CTRL2  ========================================================= */
#define AGC_CTRL2_FASTSTEP_Pos            (0UL)                     /*!< FASTSTEP (Bit 0)                                      */
#define AGC_CTRL2_FASTSTEP_Msk            (0x1fUL)                  /*!< FASTSTEP (Bitfield-Mask: 0x1f)                        */
#define AGC_CTRL2_HYST_Pos                (5UL)                     /*!< HYST (Bit 5)                                          */
#define AGC_CTRL2_HYST_Msk                (0x1e0UL)                 /*!< HYST (Bitfield-Mask: 0x0f)                            */
#define AGC_CTRL2_DMASEL_Pos              (9UL)                     /*!< DMASEL (Bit 9)                                        */
#define AGC_CTRL2_DMASEL_Msk              (0x200UL)                 /*!< DMASEL (Bitfield-Mask: 0x01)                          */
#define AGC_CTRL2_MAXPWRVAR_Pos           (10UL)                    /*!< MAXPWRVAR (Bit 10)                                    */
#define AGC_CTRL2_MAXPWRVAR_Msk           (0xfc00UL)                /*!< MAXPWRVAR (Bitfield-Mask: 0x3f)                       */
#define AGC_CTRL2_FASTLOOPDEL_Pos         (16UL)                    /*!< FASTLOOPDEL (Bit 16)                                  */
#define AGC_CTRL2_FASTLOOPDEL_Msk         (0xf0000UL)               /*!< FASTLOOPDEL (Bitfield-Mask: 0x0f)                     */
#define AGC_CTRL2_CFLOOPDEL_Pos           (20UL)                    /*!< CFLOOPDEL (Bit 20)                                    */
#define AGC_CTRL2_CFLOOPDEL_Msk           (0x3f00000UL)             /*!< CFLOOPDEL (Bitfield-Mask: 0x3f)                       */
#define AGC_CTRL2_RSSIFAST_Pos            (26UL)                    /*!< RSSIFAST (Bit 26)                                     */
#define AGC_CTRL2_RSSIFAST_Msk            (0x4000000UL)             /*!< RSSIFAST (Bitfield-Mask: 0x01)                        */
#define AGC_CTRL2_SLOWGAINADJ_Pos         (27UL)                    /*!< SLOWGAINADJ (Bit 27)                                  */
#define AGC_CTRL2_SLOWGAINADJ_Msk         (0x8000000UL)             /*!< SLOWGAINADJ (Bitfield-Mask: 0x01)                     */
#define AGC_CTRL2_ADCRSTFASTLOOP_Pos      (29UL)                    /*!< ADCRSTFASTLOOP (Bit 29)                               */
#define AGC_CTRL2_ADCRSTFASTLOOP_Msk      (0x60000000UL)            /*!< ADCRSTFASTLOOP (Bitfield-Mask: 0x03)                  */
#define AGC_CTRL2_ADCRSTSTARTUP_Pos       (31UL)                    /*!< ADCRSTSTARTUP (Bit 31)                                */
#define AGC_CTRL2_ADCRSTSTARTUP_Msk       (0x80000000UL)            /*!< ADCRSTSTARTUP (Bitfield-Mask: 0x01)                   */
/* ======================================================  RSSISTEPTHR  ====================================================== */
#define AGC_RSSISTEPTHR_POSSTEPTHR_Pos    (0UL)                     /*!< POSSTEPTHR (Bit 0)                                    */
#define AGC_RSSISTEPTHR_POSSTEPTHR_Msk    (0xffUL)                  /*!< POSSTEPTHR (Bitfield-Mask: 0xff)                      */
#define AGC_RSSISTEPTHR_NEGSTEPTHR_Pos    (8UL)                     /*!< NEGSTEPTHR (Bit 8)                                    */
#define AGC_RSSISTEPTHR_NEGSTEPTHR_Msk    (0xff00UL)                /*!< NEGSTEPTHR (Bitfield-Mask: 0xff)                      */
/* =======================================================  IFPEAKDET  ======================================================= */
#define AGC_IFPEAKDET_PKDTHRESH1_Pos      (0UL)                     /*!< PKDTHRESH1 (Bit 0)                                    */
#define AGC_IFPEAKDET_PKDTHRESH1_Msk      (0xfUL)                   /*!< PKDTHRESH1 (Bitfield-Mask: 0x0f)                      */
#define AGC_IFPEAKDET_PKDTHRESH2_Pos      (4UL)                     /*!< PKDTHRESH2 (Bit 4)                                    */
#define AGC_IFPEAKDET_PKDTHRESH2_Msk      (0xf0UL)                  /*!< PKDTHRESH2 (Bitfield-Mask: 0x0f)                      */
#define AGC_IFPEAKDET_MODEPKD_Pos         (8UL)                     /*!< MODEPKD (Bit 8)                                       */
#define AGC_IFPEAKDET_MODEPKD_Msk         (0x300UL)                 /*!< MODEPKD (Bitfield-Mask: 0x03)                         */
/* ========================================================  MANGAIN  ======================================================== */
#define AGC_MANGAIN_MANGAININDEX_Pos      (0UL)                     /*!< MANGAININDEX (Bit 0)                                  */
#define AGC_MANGAIN_MANGAININDEX_Msk      (0x3fUL)                  /*!< MANGAININDEX (Bitfield-Mask: 0x3f)                    */
#define AGC_MANGAIN_MANGAININDEXEN_Pos    (7UL)                     /*!< MANGAININDEXEN (Bit 7)                                */
#define AGC_MANGAIN_MANGAININDEXEN_Msk    (0x80UL)                  /*!< MANGAININDEXEN (Bitfield-Mask: 0x01)                  */
#define AGC_MANGAIN_MANGAINIFPGA_Pos      (9UL)                     /*!< MANGAINIFPGA (Bit 9)                                  */
#define AGC_MANGAIN_MANGAINIFPGA_Msk      (0x1e00UL)                /*!< MANGAINIFPGA (Bitfield-Mask: 0x0f)                    */
#define AGC_MANGAIN_MANGAINLNADEGEN_Pos   (13UL)                    /*!< MANGAINLNADEGEN (Bit 13)                              */
#define AGC_MANGAIN_MANGAINLNADEGEN_Msk   (0xe000UL)                /*!< MANGAINLNADEGEN (Bitfield-Mask: 0x07)                 */
#define AGC_MANGAIN_MANGAINLNASLICES_Pos  (16UL)                    /*!< MANGAINLNASLICES (Bit 16)                             */
#define AGC_MANGAIN_MANGAINLNASLICES_Msk  (0xf0000UL)               /*!< MANGAINLNASLICES (Bitfield-Mask: 0x0f)                */
#define AGC_MANGAIN_MANGAINLNAATTEN_Pos   (21UL)                    /*!< MANGAINLNAATTEN (Bit 21)                              */
#define AGC_MANGAIN_MANGAINLNAATTEN_Msk   (0x3e00000UL)             /*!< MANGAINLNAATTEN (Bitfield-Mask: 0x1f)                 */
#define AGC_MANGAIN_MANGAINLNASLICESREG_Pos (26UL)                  /*!< MANGAINLNASLICESREG (Bit 26)                          */
#define AGC_MANGAIN_MANGAINLNASLICESREG_Msk (0x3c000000UL)          /*!< MANGAINLNASLICESREG (Bitfield-Mask: 0x0f)             */
#define AGC_MANGAIN_MANGAINEN_Pos         (30UL)                    /*!< MANGAINEN (Bit 30)                                    */
#define AGC_MANGAIN_MANGAINEN_Msk         (0x40000000UL)            /*!< MANGAINEN (Bitfield-Mask: 0x01)                       */
/* ==========================================================  IF  =========================================================== */
#define AGC_IF_RSSIVALID_Pos              (0UL)                     /*!< RSSIVALID (Bit 0)                                     */
#define AGC_IF_RSSIVALID_Msk              (0x1UL)                   /*!< RSSIVALID (Bitfield-Mask: 0x01)                       */
#define AGC_IF_CCA_Pos                    (2UL)                     /*!< CCA (Bit 2)                                           */
#define AGC_IF_CCA_Msk                    (0x4UL)                   /*!< CCA (Bitfield-Mask: 0x01)                             */
#define AGC_IF_RSSIPOSSTEP_Pos            (3UL)                     /*!< RSSIPOSSTEP (Bit 3)                                   */
#define AGC_IF_RSSIPOSSTEP_Msk            (0x8UL)                   /*!< RSSIPOSSTEP (Bitfield-Mask: 0x01)                     */
#define AGC_IF_RSSINEGSTEP_Pos            (4UL)                     /*!< RSSINEGSTEP (Bit 4)                                   */
#define AGC_IF_RSSINEGSTEP_Msk            (0x10UL)                  /*!< RSSINEGSTEP (Bitfield-Mask: 0x01)                     */
#define AGC_IF_RSSIDONE_Pos               (5UL)                     /*!< RSSIDONE (Bit 5)                                      */
#define AGC_IF_RSSIDONE_Msk               (0x20UL)                  /*!< RSSIDONE (Bitfield-Mask: 0x01)                        */
/* ==========================================================  IFS  ========================================================== */
#define AGC_IFS_RSSIVALID_Pos             (0UL)                     /*!< RSSIVALID (Bit 0)                                     */
#define AGC_IFS_RSSIVALID_Msk             (0x1UL)                   /*!< RSSIVALID (Bitfield-Mask: 0x01)                       */
#define AGC_IFS_CCA_Pos                   (2UL)                     /*!< CCA (Bit 2)                                           */
#define AGC_IFS_CCA_Msk                   (0x4UL)                   /*!< CCA (Bitfield-Mask: 0x01)                             */
#define AGC_IFS_RSSIPOSSTEP_Pos           (3UL)                     /*!< RSSIPOSSTEP (Bit 3)                                   */
#define AGC_IFS_RSSIPOSSTEP_Msk           (0x8UL)                   /*!< RSSIPOSSTEP (Bitfield-Mask: 0x01)                     */
#define AGC_IFS_RSSINEGSTEP_Pos           (4UL)                     /*!< RSSINEGSTEP (Bit 4)                                   */
#define AGC_IFS_RSSINEGSTEP_Msk           (0x10UL)                  /*!< RSSINEGSTEP (Bitfield-Mask: 0x01)                     */
#define AGC_IFS_RSSIDONE_Pos              (5UL)                     /*!< RSSIDONE (Bit 5)                                      */
#define AGC_IFS_RSSIDONE_Msk              (0x20UL)                  /*!< RSSIDONE (Bitfield-Mask: 0x01)                        */
/* ==========================================================  IFC  ========================================================== */
#define AGC_IFC_RSSIVALID_Pos             (0UL)                     /*!< RSSIVALID (Bit 0)                                     */
#define AGC_IFC_RSSIVALID_Msk             (0x1UL)                   /*!< RSSIVALID (Bitfield-Mask: 0x01)                       */
#define AGC_IFC_CCA_Pos                   (2UL)                     /*!< CCA (Bit 2)                                           */
#define AGC_IFC_CCA_Msk                   (0x4UL)                   /*!< CCA (Bitfield-Mask: 0x01)                             */
#define AGC_IFC_RSSIPOSSTEP_Pos           (3UL)                     /*!< RSSIPOSSTEP (Bit 3)                                   */
#define AGC_IFC_RSSIPOSSTEP_Msk           (0x8UL)                   /*!< RSSIPOSSTEP (Bitfield-Mask: 0x01)                     */
#define AGC_IFC_RSSINEGSTEP_Pos           (4UL)                     /*!< RSSINEGSTEP (Bit 4)                                   */
#define AGC_IFC_RSSINEGSTEP_Msk           (0x10UL)                  /*!< RSSINEGSTEP (Bitfield-Mask: 0x01)                     */
#define AGC_IFC_RSSIDONE_Pos              (5UL)                     /*!< RSSIDONE (Bit 5)                                      */
#define AGC_IFC_RSSIDONE_Msk              (0x20UL)                  /*!< RSSIDONE (Bitfield-Mask: 0x01)                        */
/* ==========================================================  IEN  ========================================================== */
#define AGC_IEN_RSSIVALID_Pos             (0UL)                     /*!< RSSIVALID (Bit 0)                                     */
#define AGC_IEN_RSSIVALID_Msk             (0x1UL)                   /*!< RSSIVALID (Bitfield-Mask: 0x01)                       */
#define AGC_IEN_CCA_Pos                   (2UL)                     /*!< CCA (Bit 2)                                           */
#define AGC_IEN_CCA_Msk                   (0x4UL)                   /*!< CCA (Bitfield-Mask: 0x01)                             */
#define AGC_IEN_RSSIPOSSTEP_Pos           (3UL)                     /*!< RSSIPOSSTEP (Bit 3)                                   */
#define AGC_IEN_RSSIPOSSTEP_Msk           (0x8UL)                   /*!< RSSIPOSSTEP (Bitfield-Mask: 0x01)                     */
#define AGC_IEN_RSSINEGSTEP_Pos           (4UL)                     /*!< RSSINEGSTEP (Bit 4)                                   */
#define AGC_IEN_RSSINEGSTEP_Msk           (0x10UL)                  /*!< RSSINEGSTEP (Bitfield-Mask: 0x01)                     */
#define AGC_IEN_RSSIDONE_Pos              (5UL)                     /*!< RSSIDONE (Bit 5)                                      */
#define AGC_IEN_RSSIDONE_Msk              (0x20UL)                  /*!< RSSIDONE (Bitfield-Mask: 0x01)                        */
/* ==========================================================  CMD  ========================================================== */
#define AGC_CMD_RSSISTART_Pos             (0UL)                     /*!< RSSISTART (Bit 0)                                     */
#define AGC_CMD_RSSISTART_Msk             (0x1UL)                   /*!< RSSISTART (Bitfield-Mask: 0x01)                       */
/* =======================================================  GAINRANGE  ======================================================= */
#define AGC_GAINRANGE_MAXGAIN_Pos         (0UL)                     /*!< MAXGAIN (Bit 0)                                       */
#define AGC_GAINRANGE_MAXGAIN_Msk         (0x7fUL)                  /*!< MAXGAIN (Bitfield-Mask: 0x7f)                         */
#define AGC_GAINRANGE_MINGAIN_Pos         (7UL)                     /*!< MINGAIN (Bit 7)                                       */
#define AGC_GAINRANGE_MINGAIN_Msk         (0x3f80UL)                /*!< MINGAIN (Bitfield-Mask: 0x7f)                         */
/* =======================================================  GAININDEX  ======================================================= */
#define AGC_GAININDEX_NUMINDEXPGA_Pos     (0UL)                     /*!< NUMINDEXPGA (Bit 0)                                   */
#define AGC_GAININDEX_NUMINDEXPGA_Msk     (0xfUL)                   /*!< NUMINDEXPGA (Bitfield-Mask: 0x0f)                     */
#define AGC_GAININDEX_NUMINDEXDEGEN_Pos   (4UL)                     /*!< NUMINDEXDEGEN (Bit 4)                                 */
#define AGC_GAININDEX_NUMINDEXDEGEN_Msk   (0x30UL)                  /*!< NUMINDEXDEGEN (Bitfield-Mask: 0x03)                   */
#define AGC_GAININDEX_NUMINDEXSLICES_Pos  (6UL)                     /*!< NUMINDEXSLICES (Bit 6)                                */
#define AGC_GAININDEX_NUMINDEXSLICES_Msk  (0x1c0UL)                 /*!< NUMINDEXSLICES (Bitfield-Mask: 0x07)                  */
#define AGC_GAININDEX_NUMINDEXATTEN_Pos   (9UL)                     /*!< NUMINDEXATTEN (Bit 9)                                 */
#define AGC_GAININDEX_NUMINDEXATTEN_Msk   (0x3e00UL)                /*!< NUMINDEXATTEN (Bitfield-Mask: 0x1f)                   */
#define AGC_GAININDEX_MININDEXPGA_Pos     (14UL)                    /*!< MININDEXPGA (Bit 14)                                  */
#define AGC_GAININDEX_MININDEXPGA_Msk     (0x3c000UL)               /*!< MININDEXPGA (Bitfield-Mask: 0x0f)                     */
#define AGC_GAININDEX_MININDEXDEGEN_Pos   (18UL)                    /*!< MININDEXDEGEN (Bit 18)                                */
#define AGC_GAININDEX_MININDEXDEGEN_Msk   (0xc0000UL)               /*!< MININDEXDEGEN (Bitfield-Mask: 0x03)                   */
/* =======================================================  SLICECODE  ======================================================= */
#define AGC_SLICECODE_SLICECODEINDEX0_Pos (0UL)                     /*!< SLICECODEINDEX0 (Bit 0)                               */
#define AGC_SLICECODE_SLICECODEINDEX0_Msk (0xfUL)                   /*!< SLICECODEINDEX0 (Bitfield-Mask: 0x0f)                 */
#define AGC_SLICECODE_SLICECODEINDEX1_Pos (4UL)                     /*!< SLICECODEINDEX1 (Bit 4)                               */
#define AGC_SLICECODE_SLICECODEINDEX1_Msk (0xf0UL)                  /*!< SLICECODEINDEX1 (Bitfield-Mask: 0x0f)                 */
#define AGC_SLICECODE_SLICECODEINDEX2_Pos (8UL)                     /*!< SLICECODEINDEX2 (Bit 8)                               */
#define AGC_SLICECODE_SLICECODEINDEX2_Msk (0xf00UL)                 /*!< SLICECODEINDEX2 (Bitfield-Mask: 0x0f)                 */
#define AGC_SLICECODE_SLICECODEINDEX3_Pos (12UL)                    /*!< SLICECODEINDEX3 (Bit 12)                              */
#define AGC_SLICECODE_SLICECODEINDEX3_Msk (0xf000UL)                /*!< SLICECODEINDEX3 (Bitfield-Mask: 0x0f)                 */
#define AGC_SLICECODE_SLICECODEINDEX4_Pos (16UL)                    /*!< SLICECODEINDEX4 (Bit 16)                              */
#define AGC_SLICECODE_SLICECODEINDEX4_Msk (0xf0000UL)               /*!< SLICECODEINDEX4 (Bitfield-Mask: 0x0f)                 */
#define AGC_SLICECODE_SLICECODEINDEX5_Pos (20UL)                    /*!< SLICECODEINDEX5 (Bit 20)                              */
#define AGC_SLICECODE_SLICECODEINDEX5_Msk (0xf00000UL)              /*!< SLICECODEINDEX5 (Bitfield-Mask: 0x0f)                 */
#define AGC_SLICECODE_SLICECODEINDEX6_Pos (24UL)                    /*!< SLICECODEINDEX6 (Bit 24)                              */
#define AGC_SLICECODE_SLICECODEINDEX6_Msk (0xf000000UL)             /*!< SLICECODEINDEX6 (Bitfield-Mask: 0x0f)                 */
/* ======================================================  ATTENCODE1  ======================================================= */
#define AGC_ATTENCODE1_ATTENCODEINDEX0_Pos (0UL)                    /*!< ATTENCODEINDEX0 (Bit 0)                               */
#define AGC_ATTENCODE1_ATTENCODEINDEX0_Msk (0xfUL)                  /*!< ATTENCODEINDEX0 (Bitfield-Mask: 0x0f)                 */
#define AGC_ATTENCODE1_ATTENCODEINDEX1_Pos (4UL)                    /*!< ATTENCODEINDEX1 (Bit 4)                               */
#define AGC_ATTENCODE1_ATTENCODEINDEX1_Msk (0xf0UL)                 /*!< ATTENCODEINDEX1 (Bitfield-Mask: 0x0f)                 */
#define AGC_ATTENCODE1_ATTENCODEINDEX2_Pos (8UL)                    /*!< ATTENCODEINDEX2 (Bit 8)                               */
#define AGC_ATTENCODE1_ATTENCODEINDEX2_Msk (0xf00UL)                /*!< ATTENCODEINDEX2 (Bitfield-Mask: 0x0f)                 */
#define AGC_ATTENCODE1_ATTENCODEINDEX3_Pos (12UL)                   /*!< ATTENCODEINDEX3 (Bit 12)                              */
#define AGC_ATTENCODE1_ATTENCODEINDEX3_Msk (0xf000UL)               /*!< ATTENCODEINDEX3 (Bitfield-Mask: 0x0f)                 */
#define AGC_ATTENCODE1_ATTENCODEINDEX4_Pos (16UL)                   /*!< ATTENCODEINDEX4 (Bit 16)                              */
#define AGC_ATTENCODE1_ATTENCODEINDEX4_Msk (0xf0000UL)              /*!< ATTENCODEINDEX4 (Bitfield-Mask: 0x0f)                 */
#define AGC_ATTENCODE1_ATTENCODEINDEX5_Pos (20UL)                   /*!< ATTENCODEINDEX5 (Bit 20)                              */
#define AGC_ATTENCODE1_ATTENCODEINDEX5_Msk (0xf00000UL)             /*!< ATTENCODEINDEX5 (Bitfield-Mask: 0x0f)                 */
#define AGC_ATTENCODE1_ATTENCODEINDEX6_Pos (24UL)                   /*!< ATTENCODEINDEX6 (Bit 24)                              */
#define AGC_ATTENCODE1_ATTENCODEINDEX6_Msk (0xf000000UL)            /*!< ATTENCODEINDEX6 (Bitfield-Mask: 0x0f)                 */
/* ======================================================  ATTENCODE2  ======================================================= */
#define AGC_ATTENCODE2_ATTENCODEINDEX7_Pos (0UL)                    /*!< ATTENCODEINDEX7 (Bit 0)                               */
#define AGC_ATTENCODE2_ATTENCODEINDEX7_Msk (0x1fUL)                 /*!< ATTENCODEINDEX7 (Bitfield-Mask: 0x1f)                 */
#define AGC_ATTENCODE2_ATTENCODEINDEX8_Pos (5UL)                    /*!< ATTENCODEINDEX8 (Bit 5)                               */
#define AGC_ATTENCODE2_ATTENCODEINDEX8_Msk (0x3e0UL)                /*!< ATTENCODEINDEX8 (Bitfield-Mask: 0x1f)                 */
#define AGC_ATTENCODE2_ATTENCODEINDEX9_Pos (10UL)                   /*!< ATTENCODEINDEX9 (Bit 10)                              */
#define AGC_ATTENCODE2_ATTENCODEINDEX9_Msk (0x7c00UL)               /*!< ATTENCODEINDEX9 (Bitfield-Mask: 0x1f)                 */
#define AGC_ATTENCODE2_ATTENCODEINDEX10_Pos (15UL)                  /*!< ATTENCODEINDEX10 (Bit 15)                             */
#define AGC_ATTENCODE2_ATTENCODEINDEX10_Msk (0xf8000UL)             /*!< ATTENCODEINDEX10 (Bitfield-Mask: 0x1f)                */
#define AGC_ATTENCODE2_ATTENCODEINDEX11_Pos (20UL)                  /*!< ATTENCODEINDEX11 (Bit 20)                             */
#define AGC_ATTENCODE2_ATTENCODEINDEX11_Msk (0x1f00000UL)           /*!< ATTENCODEINDEX11 (Bitfield-Mask: 0x1f)                */
#define AGC_ATTENCODE2_ATTENCODEINDEX12_Pos (25UL)                  /*!< ATTENCODEINDEX12 (Bit 25)                             */
#define AGC_ATTENCODE2_ATTENCODEINDEX12_Msk (0x3e000000UL)          /*!< ATTENCODEINDEX12 (Bitfield-Mask: 0x1f)                */
/* ======================================================  ATTENCODE3  ======================================================= */
#define AGC_ATTENCODE3_ATTENCODEINDEX13_Pos (0UL)                   /*!< ATTENCODEINDEX13 (Bit 0)                              */
#define AGC_ATTENCODE3_ATTENCODEINDEX13_Msk (0x1fUL)                /*!< ATTENCODEINDEX13 (Bitfield-Mask: 0x1f)                */
#define AGC_ATTENCODE3_ATTENCODEINDEX14_Pos (5UL)                   /*!< ATTENCODEINDEX14 (Bit 5)                              */
#define AGC_ATTENCODE3_ATTENCODEINDEX14_Msk (0x3e0UL)               /*!< ATTENCODEINDEX14 (Bitfield-Mask: 0x1f)                */
#define AGC_ATTENCODE3_ATTENCODEINDEX15_Pos (10UL)                  /*!< ATTENCODEINDEX15 (Bit 10)                             */
#define AGC_ATTENCODE3_ATTENCODEINDEX15_Msk (0x7c00UL)              /*!< ATTENCODEINDEX15 (Bitfield-Mask: 0x1f)                */
#define AGC_ATTENCODE3_ATTENCODEINDEX16_Pos (15UL)                  /*!< ATTENCODEINDEX16 (Bit 15)                             */
#define AGC_ATTENCODE3_ATTENCODEINDEX16_Msk (0xf8000UL)             /*!< ATTENCODEINDEX16 (Bitfield-Mask: 0x1f)                */
#define AGC_ATTENCODE3_ATTENCODEINDEX17_Pos (20UL)                  /*!< ATTENCODEINDEX17 (Bit 20)                             */
#define AGC_ATTENCODE3_ATTENCODEINDEX17_Msk (0x1f00000UL)           /*!< ATTENCODEINDEX17 (Bitfield-Mask: 0x1f)                */
#define AGC_ATTENCODE3_ATTENCODEINDEX18_Pos (25UL)                  /*!< ATTENCODEINDEX18 (Bit 25)                             */
#define AGC_ATTENCODE3_ATTENCODEINDEX18_Msk (0x3e000000UL)          /*!< ATTENCODEINDEX18 (Bitfield-Mask: 0x1f)                */
/* ======================================================  GAINERROR1  ======================================================= */
#define AGC_GAINERROR1_DEGENERRINDEX0_Pos (0UL)                     /*!< DEGENERRINDEX0 (Bit 0)                                */
#define AGC_GAINERROR1_DEGENERRINDEX0_Msk (0x7UL)                   /*!< DEGENERRINDEX0 (Bitfield-Mask: 0x07)                  */
#define AGC_GAINERROR1_DEGENERRINDEX1_Pos (3UL)                     /*!< DEGENERRINDEX1 (Bit 3)                                */
#define AGC_GAINERROR1_DEGENERRINDEX1_Msk (0x38UL)                  /*!< DEGENERRINDEX1 (Bitfield-Mask: 0x07)                  */
#define AGC_GAINERROR1_DEGENERRINDEX2_Pos (6UL)                     /*!< DEGENERRINDEX2 (Bit 6)                                */
#define AGC_GAINERROR1_DEGENERRINDEX2_Msk (0x1c0UL)                 /*!< DEGENERRINDEX2 (Bitfield-Mask: 0x07)                  */
#define AGC_GAINERROR1_SLICEERRINDEX0_Pos (9UL)                     /*!< SLICEERRINDEX0 (Bit 9)                                */
#define AGC_GAINERROR1_SLICEERRINDEX0_Msk (0xe00UL)                 /*!< SLICEERRINDEX0 (Bitfield-Mask: 0x07)                  */
#define AGC_GAINERROR1_SLICEERRINDEX1_Pos (12UL)                    /*!< SLICEERRINDEX1 (Bit 12)                               */
#define AGC_GAINERROR1_SLICEERRINDEX1_Msk (0x7000UL)                /*!< SLICEERRINDEX1 (Bitfield-Mask: 0x07)                  */
#define AGC_GAINERROR1_SLICEERRINDEX2_Pos (15UL)                    /*!< SLICEERRINDEX2 (Bit 15)                               */
#define AGC_GAINERROR1_SLICEERRINDEX2_Msk (0x38000UL)               /*!< SLICEERRINDEX2 (Bitfield-Mask: 0x07)                  */
#define AGC_GAINERROR1_SLICEERRINDEX3_Pos (18UL)                    /*!< SLICEERRINDEX3 (Bit 18)                               */
#define AGC_GAINERROR1_SLICEERRINDEX3_Msk (0x1c0000UL)              /*!< SLICEERRINDEX3 (Bitfield-Mask: 0x07)                  */
#define AGC_GAINERROR1_SLICEERRINDEX4_Pos (21UL)                    /*!< SLICEERRINDEX4 (Bit 21)                               */
#define AGC_GAINERROR1_SLICEERRINDEX4_Msk (0xe00000UL)              /*!< SLICEERRINDEX4 (Bitfield-Mask: 0x07)                  */
#define AGC_GAINERROR1_SLICEERRINDEX5_Pos (24UL)                    /*!< SLICEERRINDEX5 (Bit 24)                               */
#define AGC_GAINERROR1_SLICEERRINDEX5_Msk (0x7000000UL)             /*!< SLICEERRINDEX5 (Bitfield-Mask: 0x07)                  */
/* ======================================================  GAINERROR2  ======================================================= */
#define AGC_GAINERROR2_ATTENERRINDEX0_Pos (0UL)                     /*!< ATTENERRINDEX0 (Bit 0)                                */
#define AGC_GAINERROR2_ATTENERRINDEX0_Msk (0x7UL)                   /*!< ATTENERRINDEX0 (Bitfield-Mask: 0x07)                  */
#define AGC_GAINERROR2_ATTENERRINDEX1_Pos (3UL)                     /*!< ATTENERRINDEX1 (Bit 3)                                */
#define AGC_GAINERROR2_ATTENERRINDEX1_Msk (0x38UL)                  /*!< ATTENERRINDEX1 (Bitfield-Mask: 0x07)                  */
#define AGC_GAINERROR2_ATTENERRINDEX2_Pos (6UL)                     /*!< ATTENERRINDEX2 (Bit 6)                                */
#define AGC_GAINERROR2_ATTENERRINDEX2_Msk (0x1c0UL)                 /*!< ATTENERRINDEX2 (Bitfield-Mask: 0x07)                  */
#define AGC_GAINERROR2_ATTENERRINDEX3_Pos (9UL)                     /*!< ATTENERRINDEX3 (Bit 9)                                */
#define AGC_GAINERROR2_ATTENERRINDEX3_Msk (0xe00UL)                 /*!< ATTENERRINDEX3 (Bitfield-Mask: 0x07)                  */
#define AGC_GAINERROR2_ATTENERRINDEX4_Pos (12UL)                    /*!< ATTENERRINDEX4 (Bit 12)                               */
#define AGC_GAINERROR2_ATTENERRINDEX4_Msk (0x7000UL)                /*!< ATTENERRINDEX4 (Bitfield-Mask: 0x07)                  */
#define AGC_GAINERROR2_ATTENERRINDEX5_Pos (15UL)                    /*!< ATTENERRINDEX5 (Bit 15)                               */
#define AGC_GAINERROR2_ATTENERRINDEX5_Msk (0x38000UL)               /*!< ATTENERRINDEX5 (Bitfield-Mask: 0x07)                  */
#define AGC_GAINERROR2_ATTENERRINDEX6_Pos (18UL)                    /*!< ATTENERRINDEX6 (Bit 18)                               */
#define AGC_GAINERROR2_ATTENERRINDEX6_Msk (0x1c0000UL)              /*!< ATTENERRINDEX6 (Bitfield-Mask: 0x07)                  */
#define AGC_GAINERROR2_ATTENERRINDEX7_Pos (21UL)                    /*!< ATTENERRINDEX7 (Bit 21)                               */
#define AGC_GAINERROR2_ATTENERRINDEX7_Msk (0xe00000UL)              /*!< ATTENERRINDEX7 (Bitfield-Mask: 0x07)                  */
#define AGC_GAINERROR2_ATTENERRINDEX8_Pos (24UL)                    /*!< ATTENERRINDEX8 (Bit 24)                               */
#define AGC_GAINERROR2_ATTENERRINDEX8_Msk (0x7000000UL)             /*!< ATTENERRINDEX8 (Bitfield-Mask: 0x07)                  */
#define AGC_GAINERROR2_ATTENERRINDEX9_Pos (27UL)                    /*!< ATTENERRINDEX9 (Bit 27)                               */
#define AGC_GAINERROR2_ATTENERRINDEX9_Msk (0x38000000UL)            /*!< ATTENERRINDEX9 (Bitfield-Mask: 0x07)                  */
/* ======================================================  GAINERROR3  ======================================================= */
#define AGC_GAINERROR3_ATTENERRINDEX10_Pos (0UL)                    /*!< ATTENERRINDEX10 (Bit 0)                               */
#define AGC_GAINERROR3_ATTENERRINDEX10_Msk (0x7UL)                  /*!< ATTENERRINDEX10 (Bitfield-Mask: 0x07)                 */
#define AGC_GAINERROR3_ATTENERRINDEX11_Pos (3UL)                    /*!< ATTENERRINDEX11 (Bit 3)                               */
#define AGC_GAINERROR3_ATTENERRINDEX11_Msk (0x38UL)                 /*!< ATTENERRINDEX11 (Bitfield-Mask: 0x07)                 */
#define AGC_GAINERROR3_ATTENERRINDEX12_Pos (6UL)                    /*!< ATTENERRINDEX12 (Bit 6)                               */
#define AGC_GAINERROR3_ATTENERRINDEX12_Msk (0x1c0UL)                /*!< ATTENERRINDEX12 (Bitfield-Mask: 0x07)                 */
#define AGC_GAINERROR3_ATTENERRINDEX13_Pos (9UL)                    /*!< ATTENERRINDEX13 (Bit 9)                               */
#define AGC_GAINERROR3_ATTENERRINDEX13_Msk (0xe00UL)                /*!< ATTENERRINDEX13 (Bitfield-Mask: 0x07)                 */
#define AGC_GAINERROR3_ATTENERRINDEX14_Pos (12UL)                   /*!< ATTENERRINDEX14 (Bit 12)                              */
#define AGC_GAINERROR3_ATTENERRINDEX14_Msk (0x7000UL)               /*!< ATTENERRINDEX14 (Bitfield-Mask: 0x07)                 */
#define AGC_GAINERROR3_ATTENERRINDEX15_Pos (15UL)                   /*!< ATTENERRINDEX15 (Bit 15)                              */
#define AGC_GAINERROR3_ATTENERRINDEX15_Msk (0x38000UL)              /*!< ATTENERRINDEX15 (Bitfield-Mask: 0x07)                 */
#define AGC_GAINERROR3_ATTENERRINDEX16_Pos (18UL)                   /*!< ATTENERRINDEX16 (Bit 18)                              */
#define AGC_GAINERROR3_ATTENERRINDEX16_Msk (0x1c0000UL)             /*!< ATTENERRINDEX16 (Bitfield-Mask: 0x07)                 */
#define AGC_GAINERROR3_ATTENERRINDEX17_Pos (21UL)                   /*!< ATTENERRINDEX17 (Bit 21)                              */
#define AGC_GAINERROR3_ATTENERRINDEX17_Msk (0xe00000UL)             /*!< ATTENERRINDEX17 (Bitfield-Mask: 0x07)                 */
/* ======================================================  MANUALCTRL  ======================================================= */
#define AGC_MANUALCTRL_ENMANUALRSTPKD_Pos (0UL)                     /*!< ENMANUALRSTPKD (Bit 0)                                */
#define AGC_MANUALCTRL_ENMANUALRSTPKD_Msk (0x1UL)                   /*!< ENMANUALRSTPKD (Bitfield-Mask: 0x01)                  */
#define AGC_MANUALCTRL_MANUALRSTPKD_Pos   (1UL)                     /*!< MANUALRSTPKD (Bit 1)                                  */
#define AGC_MANUALCTRL_MANUALRSTPKD_Msk   (0x2UL)                   /*!< MANUALRSTPKD (Bitfield-Mask: 0x01)                    */
#define AGC_MANUALCTRL_ENMANUALSLICESSEL_Pos (2UL)                  /*!< ENMANUALSLICESSEL (Bit 2)                             */
#define AGC_MANUALCTRL_ENMANUALSLICESSEL_Msk (0x4UL)                /*!< ENMANUALSLICESSEL (Bitfield-Mask: 0x01)               */
#define AGC_MANUALCTRL_MANUALSLICESSEL_Pos (3UL)                    /*!< MANUALSLICESSEL (Bit 3)                               */
#define AGC_MANUALCTRL_MANUALSLICESSEL_Msk (0x8UL)                  /*!< MANUALSLICESSEL (Bitfield-Mask: 0x01)                 */
#define AGC_MANUALCTRL_ENMANUALSLICESDUMP_Pos (4UL)                 /*!< ENMANUALSLICESDUMP (Bit 4)                            */
#define AGC_MANUALCTRL_ENMANUALSLICESDUMP_Msk (0x10UL)              /*!< ENMANUALSLICESDUMP (Bitfield-Mask: 0x01)              */
#define AGC_MANUALCTRL_MANUALSLICESDUMP_Pos (5UL)                   /*!< MANUALSLICESDUMP (Bit 5)                              */
#define AGC_MANUALCTRL_MANUALSLICESDUMP_Msk (0x20UL)                /*!< MANUALSLICESDUMP (Bitfield-Mask: 0x01)                */
/* ======================================================  GAINSTEPLIM  ====================================================== */
#define AGC_GAINSTEPLIM_FASTSTEPDOWN_Pos  (0UL)                     /*!< FASTSTEPDOWN (Bit 0)                                  */
#define AGC_GAINSTEPLIM_FASTSTEPDOWN_Msk  (0x3fUL)                  /*!< FASTSTEPDOWN (Bitfield-Mask: 0x3f)                    */
#define AGC_GAINSTEPLIM_EN2XFASTSTEPDOWN_Pos (6UL)                  /*!< EN2XFASTSTEPDOWN (Bit 6)                              */
#define AGC_GAINSTEPLIM_EN2XFASTSTEPDOWN_Msk (0x40UL)               /*!< EN2XFASTSTEPDOWN (Bitfield-Mask: 0x01)                */
#define AGC_GAINSTEPLIM_FASTSTEPUP_Pos    (7UL)                     /*!< FASTSTEPUP (Bit 7)                                    */
#define AGC_GAINSTEPLIM_FASTSTEPUP_Msk    (0x1f80UL)                /*!< FASTSTEPUP (Bitfield-Mask: 0x3f)                      */
#define AGC_GAINSTEPLIM_EN2XFASTSTEPUP_Pos (13UL)                   /*!< EN2XFASTSTEPUP (Bit 13)                               */
#define AGC_GAINSTEPLIM_EN2XFASTSTEPUP_Msk (0x2000UL)               /*!< EN2XFASTSTEPUP (Bitfield-Mask: 0x01)                  */
#define AGC_GAINSTEPLIM_CFLOOPSTEPMAX_Pos (14UL)                    /*!< CFLOOPSTEPMAX (Bit 14)                                */
#define AGC_GAINSTEPLIM_CFLOOPSTEPMAX_Msk (0xfc000UL)               /*!< CFLOOPSTEPMAX (Bitfield-Mask: 0x3f)                   */
/* ========================================================  LOOPDEL  ======================================================== */
#define AGC_LOOPDEL_PKDWAIT_Pos           (0UL)                     /*!< PKDWAIT (Bit 0)                                       */
#define AGC_LOOPDEL_PKDWAIT_Msk           (0xfUL)                   /*!< PKDWAIT (Bitfield-Mask: 0x0f)                         */
#define AGC_LOOPDEL_IFPGADEL_Pos          (4UL)                     /*!< IFPGADEL (Bit 4)                                      */
#define AGC_LOOPDEL_IFPGADEL_Msk          (0xf0UL)                  /*!< IFPGADEL (Bitfield-Mask: 0x0f)                        */
#define AGC_LOOPDEL_LNASLICESDEL_Pos      (8UL)                     /*!< LNASLICESDEL (Bit 8)                                  */
#define AGC_LOOPDEL_LNASLICESDEL_Msk      (0xf00UL)                 /*!< LNASLICESDEL (Bitfield-Mask: 0x0f)                    */
/* =======================================================  MININDEX  ======================================================== */
#define AGC_MININDEX_INDEXMINATTEN_Pos    (0UL)                     /*!< INDEXMINATTEN (Bit 0)                                 */
#define AGC_MININDEX_INDEXMINATTEN_Msk    (0x3fUL)                  /*!< INDEXMINATTEN (Bitfield-Mask: 0x3f)                   */
#define AGC_MININDEX_INDEXMINSLICES_Pos   (6UL)                     /*!< INDEXMINSLICES (Bit 6)                                */
#define AGC_MININDEX_INDEXMINSLICES_Msk   (0xfc0UL)                 /*!< INDEXMINSLICES (Bitfield-Mask: 0x3f)                  */
#define AGC_MININDEX_INDEXMINDEGEN_Pos    (12UL)                    /*!< INDEXMINDEGEN (Bit 12)                                */
#define AGC_MININDEX_INDEXMINDEGEN_Msk    (0x3f000UL)               /*!< INDEXMINDEGEN (Bitfield-Mask: 0x3f)                   */
#define AGC_MININDEX_INDEXMINPGA_Pos      (18UL)                    /*!< INDEXMINPGA (Bit 18)                                  */
#define AGC_MININDEX_INDEXMINPGA_Msk      (0xfc0000UL)              /*!< INDEXMINPGA (Bitfield-Mask: 0x3f)                     */



/** @} */
/** @} End of group EFR32FG1V_AGC */
/** @} End of group Parts */
