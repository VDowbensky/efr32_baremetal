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
 * @defgroup EFR32FG1V_SYNTH
 * @{
 * @brief EFR32FG1V_SYNTHRegister Declaration
 ******************************************************************************/
/* =========================================================================================================================== */
/* ================                                           SYNTH                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief Frequency synthezicer (SYNTH)
  */

typedef struct {                                /*!< (@ 0x40083000) SYNTH Structure                                            */
  __IM  uint32_t  STATUS;                       /*!< (@ 0x00000000) STATUS                                                     */
  __OM  uint32_t  CMD;                          /*!< (@ 0x00000004) CMD                                                        */
  __IOM uint32_t  CTRL;                         /*!< (@ 0x00000008) CTRL                                                       */
  __IOM uint32_t  CALCTRL;                      /*!< (@ 0x0000000C) CALCTRL                                                    */
  __IM  uint32_t  RESERVED[5];
  __IOM uint32_t  VCDACCTRL;                    /*!< (@ 0x00000024) VCDACCTRL                                                  */
  __IM  uint32_t  RESERVED1;
  __IOM uint32_t  FREQ;                         /*!< (@ 0x0000002C) FREQ                                                       */
  __IOM uint32_t  IFFREQ;                       /*!< (@ 0x00000030) IFFREQ                                                     */
  __IOM uint32_t  DIVCTRL;                      /*!< (@ 0x00000034) DIVCTRL                                                    */
  __IOM uint32_t  CHCTRL;                       /*!< (@ 0x00000038) CHCTRL                                                     */
  __IOM uint32_t  CHSP;                         /*!< (@ 0x0000003C) CHSP                                                       */
  __IOM uint32_t  CALOFFSET;                    /*!< (@ 0x00000040) CALOFFSET                                                  */
  __IOM uint32_t  VCOTUNING;                    /*!< (@ 0x00000044) VCOTUNING                                                  */
  __IM  uint32_t  RESERVED2;
  __IOM uint32_t  VCORANGE;                     /*!< (@ 0x0000004C) VCORANGE                                                   */
  __IOM uint32_t  VCOGAIN;                      /*!< (@ 0x00000050) VCOGAIN                                                    */
  __IOM uint32_t  AUXVCOTUNING;                 /*!< (@ 0x00000054) AUXVCOTUNING                                               */
  __IOM uint32_t  AUXFREQ;                      /*!< (@ 0x00000058) AUXFREQ                                                    */
  __IOM uint32_t  AUXVCDACCTRL;                 /*!< (@ 0x0000005C) AUXVCDACCTRL                                               */
  __IOM uint32_t  CHPDACCTRL;                   /*!< (@ 0x00000060) CHPDACCTRL                                                 */
  __IOM uint32_t  CAPCALCYCLECNT;               /*!< (@ 0x00000064) CAPCALCYCLECNT                                             */
  __IM  uint32_t  RESERVED3[2];
  __IM  uint32_t  IF;                           /*!< (@ 0x00000070) IF                                                         */
  __OM  uint32_t  IFS;                          /*!< (@ 0x00000074) IFS                                                        */
  __OM  uint32_t  IFC;                          /*!< (@ 0x00000078) IFC                                                        */
  __IOM uint32_t  IEN;                          /*!< (@ 0x0000007C) IEN                                                        */
} SYNTH_Typedef;                                   /*!< Size = 128 (0x80)                                                         */

/***************************************************************************//**
 * @addtogroup EFR32FG1V_SYNTH
 * @{
 * @defgroup EFR32FG1V_SYNTH BitFields  SYNTH Bit Fields
 * @{
 ******************************************************************************/
/* =========================================================================================================================== */
/* ================                                           SYNTH                                           ================ */
/* =========================================================================================================================== */

/* ========================================================  STATUS  ========================================================= */
#define SYNTH_STATUS_INLOCK_Pos           (0UL)                     /*!< INLOCK (Bit 0)                                        */
#define SYNTH_STATUS_INLOCK_Msk           (0x1UL)                   /*!< INLOCK (Bitfield-Mask: 0x01)                          */
#define SYNTH_STATUS_IFFREQEN_Pos         (1UL)                     /*!< IFFREQEN (Bit 1)                                      */
#define SYNTH_STATUS_IFFREQEN_Msk         (0x2UL)                   /*!< IFFREQEN (Bitfield-Mask: 0x01)                        */
#define SYNTH_STATUS_SYNTHREADY_Pos       (2UL)                     /*!< SYNTHREADY (Bit 2)                                    */
#define SYNTH_STATUS_SYNTHREADY_Msk       (0x4UL)                   /*!< SYNTHREADY (Bitfield-Mask: 0x01)                      */
#define SYNTH_STATUS_AUXINLOCK_Pos        (4UL)                     /*!< AUXINLOCK (Bit 4)                                     */
#define SYNTH_STATUS_AUXINLOCK_Msk        (0x10UL)                  /*!< AUXINLOCK (Bitfield-Mask: 0x01)                       */
#define SYNTH_STATUS_AUXRUNNING_Pos       (5UL)                     /*!< AUXRUNNING (Bit 5)                                    */
#define SYNTH_STATUS_AUXRUNNING_Msk       (0x20UL)                  /*!< AUXRUNNING (Bitfield-Mask: 0x01)                      */
#define SYNTH_STATUS_CAPCALRUNNING_Pos    (8UL)                     /*!< CAPCALRUNNING (Bit 8)                                 */
#define SYNTH_STATUS_CAPCALRUNNING_Msk    (0x100UL)                 /*!< CAPCALRUNNING (Bitfield-Mask: 0x01)                   */
#define SYNTH_STATUS_CAPCALBITRESULT_Pos  (9UL)                     /*!< CAPCALBITRESULT (Bit 9)                               */
#define SYNTH_STATUS_CAPCALBITRESULT_Msk  (0x200UL)                 /*!< CAPCALBITRESULT (Bitfield-Mask: 0x01)                 */
#define SYNTH_STATUS_CAPCALFULLWAIT_Pos   (10UL)                    /*!< CAPCALFULLWAIT (Bit 10)                               */
#define SYNTH_STATUS_CAPCALFULLWAIT_Msk   (0x400UL)                 /*!< CAPCALFULLWAIT (Bitfield-Mask: 0x01)                  */
#define SYNTH_STATUS_AUXCAPCALRUNNING_Pos (11UL)                    /*!< AUXCAPCALRUNNING (Bit 11)                             */
#define SYNTH_STATUS_AUXCAPCALRUNNING_Msk (0x800UL)                 /*!< AUXCAPCALRUNNING (Bitfield-Mask: 0x01)                */
#define SYNTH_STATUS_AUXCALBITRESULT_Pos  (12UL)                    /*!< AUXCALBITRESULT (Bit 12)                              */
#define SYNTH_STATUS_AUXCALBITRESULT_Msk  (0x1000UL)                /*!< AUXCALBITRESULT (Bitfield-Mask: 0x01)                 */
#define SYNTH_STATUS_AUXCALFULLWAIT_Pos   (13UL)                    /*!< AUXCALFULLWAIT (Bit 13)                               */
#define SYNTH_STATUS_AUXCALFULLWAIT_Msk   (0x2000UL)                /*!< AUXCALFULLWAIT (Bitfield-Mask: 0x01)                  */
#define SYNTH_STATUS_CAPCALERROR_Pos      (14UL)                    /*!< CAPCALERROR (Bit 14)                                  */
#define SYNTH_STATUS_CAPCALERROR_Msk      (0x4000UL)                /*!< CAPCALERROR (Bitfield-Mask: 0x01)                     */
#define SYNTH_STATUS_AUXCALERROR_Pos      (15UL)                    /*!< AUXCALERROR (Bit 15)                                  */
#define SYNTH_STATUS_AUXCALERROR_Msk      (0x8000UL)                /*!< AUXCALERROR (Bitfield-Mask: 0x01)                     */
#define SYNTH_STATUS_VCOFREQACTIVE_Pos    (16UL)                    /*!< VCOFREQACTIVE (Bit 16)                                */
#define SYNTH_STATUS_VCOFREQACTIVE_Msk    (0x10000UL)               /*!< VCOFREQACTIVE (Bitfield-Mask: 0x01)                   */
#define SYNTH_STATUS_VCOVARBANK_Pos       (17UL)                    /*!< VCOVARBANK (Bit 17)                                   */
#define SYNTH_STATUS_VCOVARBANK_Msk       (0x7e0000UL)              /*!< VCOVARBANK (Bitfield-Mask: 0x3f)                      */
#define SYNTH_STATUS_VCOAMPOK_Pos         (24UL)                    /*!< VCOAMPOK (Bit 24)                                     */
#define SYNTH_STATUS_VCOAMPOK_Msk         (0x1000000UL)             /*!< VCOAMPOK (Bitfield-Mask: 0x01)                        */
#define SYNTH_STATUS_CHPALLOWTRISTATE_Pos (26UL)                    /*!< CHPALLOWTRISTATE (Bit 26)                             */
#define SYNTH_STATUS_CHPALLOWTRISTATE_Msk (0x4000000UL)             /*!< CHPALLOWTRISTATE (Bitfield-Mask: 0x01)                */
/* ==========================================================  CMD  ========================================================== */
#define SYNTH_CMD_SYNTHSTART_Pos          (0UL)                     /*!< SYNTHSTART (Bit 0)                                    */
#define SYNTH_CMD_SYNTHSTART_Msk          (0x1UL)                   /*!< SYNTHSTART (Bitfield-Mask: 0x01)                      */
#define SYNTH_CMD_SYNTHSTOP_Pos           (1UL)                     /*!< SYNTHSTOP (Bit 1)                                     */
#define SYNTH_CMD_SYNTHSTOP_Msk           (0x2UL)                   /*!< SYNTHSTOP (Bitfield-Mask: 0x01)                       */
#define SYNTH_CMD_ENABLEIF_Pos            (2UL)                     /*!< ENABLEIF (Bit 2)                                      */
#define SYNTH_CMD_ENABLEIF_Msk            (0x4UL)                   /*!< ENABLEIF (Bitfield-Mask: 0x01)                        */
#define SYNTH_CMD_DISABLEIF_Pos           (3UL)                     /*!< DISABLEIF (Bit 3)                                     */
#define SYNTH_CMD_DISABLEIF_Msk           (0x8UL)                   /*!< DISABLEIF (Bitfield-Mask: 0x01)                       */
#define SYNTH_CMD_CAPCALSTART_Pos         (4UL)                     /*!< CAPCALSTART (Bit 4)                                   */
#define SYNTH_CMD_CAPCALSTART_Msk         (0x10UL)                  /*!< CAPCALSTART (Bitfield-Mask: 0x01)                     */
#define SYNTH_CMD_AUXSTART_Pos            (6UL)                     /*!< AUXSTART (Bit 6)                                      */
#define SYNTH_CMD_AUXSTART_Msk            (0x40UL)                  /*!< AUXSTART (Bitfield-Mask: 0x01)                        */
#define SYNTH_CMD_AUXSTOP_Pos             (7UL)                     /*!< AUXSTOP (Bit 7)                                       */
#define SYNTH_CMD_AUXSTOP_Msk             (0x80UL)                  /*!< AUXSTOP (Bitfield-Mask: 0x01)                         */
#define SYNTH_CMD_AUXCAPCALSTART_Pos      (8UL)                     /*!< AUXCAPCALSTART (Bit 8)                                */
#define SYNTH_CMD_AUXCAPCALSTART_Msk      (0x100UL)                 /*!< AUXCAPCALSTART (Bitfield-Mask: 0x01)                  */
#define SYNTH_CMD_VCOUP_Pos               (9UL)                     /*!< VCOUP (Bit 9)                                         */
#define SYNTH_CMD_VCOUP_Msk               (0x200UL)                 /*!< VCOUP (Bitfield-Mask: 0x01)                           */
#define SYNTH_CMD_VCODOWN_Pos             (10UL)                    /*!< VCODOWN (Bit 10)                                      */
#define SYNTH_CMD_VCODOWN_Msk             (0x400UL)                 /*!< VCODOWN (Bitfield-Mask: 0x01)                         */
/* =========================================================  CTRL  ========================================================== */
#define SYNTH_CTRL_DITHERDSMINPUT_Pos     (0UL)                     /*!< DITHERDSMINPUT (Bit 0)                                */
#define SYNTH_CTRL_DITHERDSMINPUT_Msk     (0x1UL)                   /*!< DITHERDSMINPUT (Bitfield-Mask: 0x01)                  */
#define SYNTH_CTRL_DITHERDSMOUTPUT_Pos    (1UL)                     /*!< DITHERDSMOUTPUT (Bit 1)                               */
#define SYNTH_CTRL_DITHERDSMOUTPUT_Msk    (0xeUL)                   /*!< DITHERDSMOUTPUT (Bitfield-Mask: 0x07)                 */
#define SYNTH_CTRL_DITHERDAC_Pos          (4UL)                     /*!< DITHERDAC (Bit 4)                                     */
#define SYNTH_CTRL_DITHERDAC_Msk          (0xf0UL)                  /*!< DITHERDAC (Bitfield-Mask: 0x0f)                       */
#define SYNTH_CTRL_DSMMODE_Pos            (8UL)                     /*!< DSMMODE (Bit 8)                                       */
#define SYNTH_CTRL_DSMMODE_Msk            (0x100UL)                 /*!< DSMMODE (Bitfield-Mask: 0x01)                         */
#define SYNTH_CTRL_LSBFORCE_Pos           (9UL)                     /*!< LSBFORCE (Bit 9)                                      */
#define SYNTH_CTRL_LSBFORCE_Msk           (0x200UL)                 /*!< LSBFORCE (Bitfield-Mask: 0x01)                        */
#define SYNTH_CTRL_LOCKTHRESHOLD_Pos      (10UL)                    /*!< LOCKTHRESHOLD (Bit 10)                                */
#define SYNTH_CTRL_LOCKTHRESHOLD_Msk      (0x1c00UL)                /*!< LOCKTHRESHOLD (Bitfield-Mask: 0x07)                   */
#define SYNTH_CTRL_AUXLOCKTHRESHOLD_Pos   (13UL)                    /*!< AUXLOCKTHRESHOLD (Bit 13)                             */
#define SYNTH_CTRL_AUXLOCKTHRESHOLD_Msk   (0xe000UL)                /*!< AUXLOCKTHRESHOLD (Bitfield-Mask: 0x07)                */
#define SYNTH_CTRL_PRSMUX0_Pos            (16UL)                    /*!< PRSMUX0 (Bit 16)                                      */
#define SYNTH_CTRL_PRSMUX0_Msk            (0x70000UL)               /*!< PRSMUX0 (Bitfield-Mask: 0x07)                         */
#define SYNTH_CTRL_PRSMUX1_Pos            (20UL)                    /*!< PRSMUX1 (Bit 20)                                      */
#define SYNTH_CTRL_PRSMUX1_Msk            (0x700000UL)              /*!< PRSMUX1 (Bitfield-Mask: 0x07)                         */
#define SYNTH_CTRL_TRISTATEPOSTPONE_Pos   (29UL)                    /*!< TRISTATEPOSTPONE (Bit 29)                             */
#define SYNTH_CTRL_TRISTATEPOSTPONE_Msk   (0x20000000UL)            /*!< TRISTATEPOSTPONE (Bitfield-Mask: 0x01)                */
#define SYNTH_CTRL_INTEGERMODE_Pos        (30UL)                    /*!< INTEGERMODE (Bit 30)                                  */
#define SYNTH_CTRL_INTEGERMODE_Msk        (0x40000000UL)            /*!< INTEGERMODE (Bitfield-Mask: 0x01)                     */
#define SYNTH_CTRL_MMDSCANTESTEN_Pos      (31UL)                    /*!< MMDSCANTESTEN (Bit 31)                                */
#define SYNTH_CTRL_MMDSCANTESTEN_Msk      (0x80000000UL)            /*!< MMDSCANTESTEN (Bitfield-Mask: 0x01)                   */
/* ========================================================  CALCTRL  ======================================================== */
#define SYNTH_CALCTRL_NUMCYCLES_Pos       (0UL)                     /*!< NUMCYCLES (Bit 0)                                     */
#define SYNTH_CALCTRL_NUMCYCLES_Msk       (0xfUL)                   /*!< NUMCYCLES (Bitfield-Mask: 0x0f)                       */
#define SYNTH_CALCTRL_CAPCALSIDE_Pos      (4UL)                     /*!< CAPCALSIDE (Bit 4)                                    */
#define SYNTH_CALCTRL_CAPCALSIDE_Msk      (0x10UL)                  /*!< CAPCALSIDE (Bitfield-Mask: 0x01)                      */
#define SYNTH_CALCTRL_CAPCALENDMODE_Pos   (5UL)                     /*!< CAPCALENDMODE (Bit 5)                                 */
#define SYNTH_CALCTRL_CAPCALENDMODE_Msk   (0x20UL)                  /*!< CAPCALENDMODE (Bitfield-Mask: 0x01)                   */
#define SYNTH_CALCTRL_CAPCALCYCLEWAIT_Pos (6UL)                     /*!< CAPCALCYCLEWAIT (Bit 6)                               */
#define SYNTH_CALCTRL_CAPCALCYCLEWAIT_Msk (0xc0UL)                  /*!< CAPCALCYCLEWAIT (Bitfield-Mask: 0x03)                 */
#define SYNTH_CALCTRL_CAPCALWAITMODE_Pos  (8UL)                     /*!< CAPCALWAITMODE (Bit 8)                                */
#define SYNTH_CALCTRL_CAPCALWAITMODE_Msk  (0x100UL)                 /*!< CAPCALWAITMODE (Bitfield-Mask: 0x01)                  */
#define SYNTH_CALCTRL_CAPCALSINGLESTEP_Pos (9UL)                    /*!< CAPCALSINGLESTEP (Bit 9)                              */
#define SYNTH_CALCTRL_CAPCALSINGLESTEP_Msk (0x200UL)                /*!< CAPCALSINGLESTEP (Bitfield-Mask: 0x01)                */
#define SYNTH_CALCTRL_STARTUPTIMING_Pos   (10UL)                    /*!< STARTUPTIMING (Bit 10)                                */
#define SYNTH_CALCTRL_STARTUPTIMING_Msk   (0x7c00UL)                /*!< STARTUPTIMING (Bitfield-Mask: 0x1f)                   */
#define SYNTH_CALCTRL_AUXCALCYCLES_Pos    (16UL)                    /*!< AUXCALCYCLES (Bit 16)                                 */
#define SYNTH_CALCTRL_AUXCALCYCLES_Msk    (0x70000UL)               /*!< AUXCALCYCLES (Bitfield-Mask: 0x07)                    */
#define SYNTH_CALCTRL_AUXCALACCURACY_Pos  (19UL)                    /*!< AUXCALACCURACY (Bit 19)                               */
#define SYNTH_CALCTRL_AUXCALACCURACY_Msk  (0x80000UL)               /*!< AUXCALACCURACY (Bitfield-Mask: 0x01)                  */
#define SYNTH_CALCTRL_AUXCALCYCLEWAIT_Pos (20UL)                    /*!< AUXCALCYCLEWAIT (Bit 20)                              */
#define SYNTH_CALCTRL_AUXCALCYCLEWAIT_Msk (0x300000UL)              /*!< AUXCALCYCLEWAIT (Bitfield-Mask: 0x03)                 */
#define SYNTH_CALCTRL_AUXCALSINGLESTEP_Pos (22UL)                   /*!< AUXCALSINGLESTEP (Bit 22)                             */
#define SYNTH_CALCTRL_AUXCALSINGLESTEP_Msk (0x400000UL)             /*!< AUXCALSINGLESTEP (Bitfield-Mask: 0x01)                */
#define SYNTH_CALCTRL_SYNTHOVERRIDEEN_Pos (24UL)                    /*!< SYNTHOVERRIDEEN (Bit 24)                              */
#define SYNTH_CALCTRL_SYNTHOVERRIDEEN_Msk (0x1000000UL)             /*!< SYNTHOVERRIDEEN (Bitfield-Mask: 0x01)                 */
#define SYNTH_CALCTRL_CLKLOADDENOMVAL_Pos (25UL)                    /*!< CLKLOADDENOMVAL (Bit 25)                              */
#define SYNTH_CALCTRL_CLKLOADDENOMVAL_Msk (0x2000000UL)             /*!< CLKLOADDENOMVAL (Bitfield-Mask: 0x01)                 */
#define SYNTH_CALCTRL_PRESCALERRESETVAL_Pos (26UL)                  /*!< PRESCALERRESETVAL (Bit 26)                            */
#define SYNTH_CALCTRL_PRESCALERRESETVAL_Msk (0x4000000UL)           /*!< PRESCALERRESETVAL (Bitfield-Mask: 0x01)               */
#define SYNTH_CALCTRL_COUNTERRESETVAL_Pos (27UL)                    /*!< COUNTERRESETVAL (Bit 27)                              */
#define SYNTH_CALCTRL_COUNTERRESETVAL_Msk (0x8000000UL)             /*!< COUNTERRESETVAL (Bitfield-Mask: 0x01)                 */
#define SYNTH_CALCTRL_AUXPLLOVERRIDEEN_Pos (28UL)                   /*!< AUXPLLOVERRIDEEN (Bit 28)                             */
#define SYNTH_CALCTRL_AUXPLLOVERRIDEEN_Msk (0x10000000UL)           /*!< AUXPLLOVERRIDEEN (Bitfield-Mask: 0x01)                */
#define SYNTH_CALCTRL_AUXPLLMMDRESETVAL_Pos (29UL)                  /*!< AUXPLLMMDRESETVAL (Bit 29)                            */
#define SYNTH_CALCTRL_AUXPLLMMDRESETVAL_Msk (0x20000000UL)          /*!< AUXPLLMMDRESETVAL (Bitfield-Mask: 0x01)               */
/* =======================================================  VCDACCTRL  ======================================================= */
#define SYNTH_VCDACCTRL_VCDACVAL_Pos      (0UL)                     /*!< VCDACVAL (Bit 0)                                      */
#define SYNTH_VCDACCTRL_VCDACVAL_Msk      (0x3fUL)                  /*!< VCDACVAL (Bitfield-Mask: 0x3f)                        */
#define SYNTH_VCDACCTRL_EN_Pos            (6UL)                     /*!< EN (Bit 6)                                            */
#define SYNTH_VCDACCTRL_EN_Msk            (0x40UL)                  /*!< EN (Bitfield-Mask: 0x01)                              */
/* =========================================================  FREQ  ========================================================== */
#define SYNTH_FREQ_FREQ_Pos               (0UL)                     /*!< FREQ (Bit 0)                                          */
#define SYNTH_FREQ_FREQ_Msk               (0xfffffffUL)             /*!< FREQ (Bitfield-Mask: 0xfffffff)                       */
/* ========================================================  IFFREQ  ========================================================= */
#define SYNTH_IFFREQ_IFFREQ_Pos           (0UL)                     /*!< IFFREQ (Bit 0)                                        */
#define SYNTH_IFFREQ_IFFREQ_Msk           (0xfffffUL)               /*!< IFFREQ (Bitfield-Mask: 0xfffff)                       */
#define SYNTH_IFFREQ_LOSIDE_Pos           (20UL)                    /*!< LOSIDE (Bit 20)                                       */
#define SYNTH_IFFREQ_LOSIDE_Msk           (0x100000UL)              /*!< LOSIDE (Bitfield-Mask: 0x01)                          */
/* ========================================================  DIVCTRL  ======================================================== */
#define SYNTH_DIVCTRL_LODIVFREQCTRL_Pos   (0UL)                     /*!< LODIVFREQCTRL (Bit 0)                                 */
#define SYNTH_DIVCTRL_LODIVFREQCTRL_Msk   (0x1ffUL)                 /*!< LODIVFREQCTRL (Bitfield-Mask: 0x1ff)                  */
#define SYNTH_DIVCTRL_AUXLODIVFREQCTRL_Pos (16UL)                   /*!< AUXLODIVFREQCTRL (Bit 16)                             */
#define SYNTH_DIVCTRL_AUXLODIVFREQCTRL_Msk (0x3f0000UL)             /*!< AUXLODIVFREQCTRL (Bitfield-Mask: 0x3f)                */
/* ========================================================  CHCTRL  ========================================================= */
#define SYNTH_CHCTRL_CHNO_Pos             (0UL)                     /*!< CHNO (Bit 0)                                          */
#define SYNTH_CHCTRL_CHNO_Msk             (0x3fUL)                  /*!< CHNO (Bitfield-Mask: 0x3f)                            */
/* =========================================================  CHSP  ========================================================== */
#define SYNTH_CHSP_CHSP_Pos               (0UL)                     /*!< CHSP (Bit 0)                                          */
#define SYNTH_CHSP_CHSP_Msk               (0x3ffffUL)               /*!< CHSP (Bitfield-Mask: 0x3ffff)                         */
/* =======================================================  CALOFFSET  ======================================================= */
#define SYNTH_CALOFFSET_CALOFFSET_Pos     (0UL)                     /*!< CALOFFSET (Bit 0)                                     */
#define SYNTH_CALOFFSET_CALOFFSET_Msk     (0x7fffUL)                /*!< CALOFFSET (Bitfield-Mask: 0x7fff)                     */
/* =======================================================  VCOTUNING  ======================================================= */
#define SYNTH_VCOTUNING_VCOTUNING_Pos     (0UL)                     /*!< VCOTUNING (Bit 0)                                     */
#define SYNTH_VCOTUNING_VCOTUNING_Msk     (0xffUL)                  /*!< VCOTUNING (Bitfield-Mask: 0xff)                       */
/* =======================================================  VCORANGE  ======================================================== */
#define SYNTH_VCORANGE_MODE_Pos           (0UL)                     /*!< MODE (Bit 0)                                          */
#define SYNTH_VCORANGE_MODE_Msk           (0x3UL)                   /*!< MODE (Bitfield-Mask: 0x03)                            */
#define SYNTH_VCORANGE_SWITCHMODE_Pos     (2UL)                     /*!< SWITCHMODE (Bit 2)                                    */
#define SYNTH_VCORANGE_SWITCHMODE_Msk     (0x4UL)                   /*!< SWITCHMODE (Bitfield-Mask: 0x01)                      */
#define SYNTH_VCORANGE_HIGHTHRESH_Pos     (3UL)                     /*!< HIGHTHRESH (Bit 3)                                    */
#define SYNTH_VCORANGE_HIGHTHRESH_Msk     (0x18UL)                  /*!< HIGHTHRESH (Bitfield-Mask: 0x03)                      */
#define SYNTH_VCORANGE_LOWTHRESH_Pos      (5UL)                     /*!< LOWTHRESH (Bit 5)                                     */
#define SYNTH_VCORANGE_LOWTHRESH_Msk      (0x60UL)                  /*!< LOWTHRESH (Bitfield-Mask: 0x03)                       */
/* ========================================================  VCOGAIN  ======================================================== */
#define SYNTH_VCOGAIN_VCOGAIN_Pos         (0UL)                     /*!< VCOGAIN (Bit 0)                                       */
#define SYNTH_VCOGAIN_VCOGAIN_Msk         (0x3fUL)                  /*!< VCOGAIN (Bitfield-Mask: 0x3f)                         */
/* =====================================================  AUXVCOTUNING  ====================================================== */
#define SYNTH_AUXVCOTUNING_AUXVCOTUNING_Pos (0UL)                   /*!< AUXVCOTUNING (Bit 0)                                  */
#define SYNTH_AUXVCOTUNING_AUXVCOTUNING_Msk (0x7fUL)                /*!< AUXVCOTUNING (Bitfield-Mask: 0x7f)                    */
/* ========================================================  AUXFREQ  ======================================================== */
#define SYNTH_AUXFREQ_MMDDENOM_Pos        (0UL)                     /*!< MMDDENOM (Bit 0)                                      */
#define SYNTH_AUXFREQ_MMDDENOM_Msk        (0x7fUL)                  /*!< MMDDENOM (Bitfield-Mask: 0x7f)                        */
/* =====================================================  AUXVCDACCTRL  ====================================================== */
#define SYNTH_AUXVCDACCTRL_VALUE_Pos      (0UL)                     /*!< VALUE (Bit 0)                                         */
#define SYNTH_AUXVCDACCTRL_VALUE_Msk      (0xfUL)                   /*!< VALUE (Bitfield-Mask: 0x0f)                           */
#define SYNTH_AUXVCDACCTRL_EN_Pos         (4UL)                     /*!< EN (Bit 4)                                            */
#define SYNTH_AUXVCDACCTRL_EN_Msk         (0x10UL)                  /*!< EN (Bitfield-Mask: 0x01)                              */
/* ======================================================  CHPDACCTRL  ======================================================= */
#define SYNTH_CHPDACCTRL_CHPDACVAL_Pos    (0UL)                     /*!< CHPDACVAL (Bit 0)                                     */
#define SYNTH_CHPDACCTRL_CHPDACVAL_Msk    (0xffUL)                  /*!< CHPDACVAL (Bitfield-Mask: 0xff)                       */
#define SYNTH_CHPDACCTRL_OVERRIDE_Pos     (8UL)                     /*!< OVERRIDE (Bit 8)                                      */
#define SYNTH_CHPDACCTRL_OVERRIDE_Msk     (0x100UL)                 /*!< OVERRIDE (Bitfield-Mask: 0x01)                        */
/* ====================================================  CAPCALCYCLECNT  ===================================================== */
#define SYNTH_CAPCALCYCLECNT_CAPCALCYCLECNT_Pos (0UL)               /*!< CAPCALCYCLECNT (Bit 0)                                */
#define SYNTH_CAPCALCYCLECNT_CAPCALCYCLECNT_Msk (0x3ffUL)           /*!< CAPCALCYCLECNT (Bitfield-Mask: 0x3ff)                 */
/* ==========================================================  IF  =========================================================== */
#define SYNTH_IF_LOCKED_Pos               (0UL)                     /*!< LOCKED (Bit 0)                                        */
#define SYNTH_IF_LOCKED_Msk               (0x1UL)                   /*!< LOCKED (Bitfield-Mask: 0x01)                          */
#define SYNTH_IF_UNLOCKED_Pos             (1UL)                     /*!< UNLOCKED (Bit 1)                                      */
#define SYNTH_IF_UNLOCKED_Msk             (0x2UL)                   /*!< UNLOCKED (Bitfield-Mask: 0x01)                        */
#define SYNTH_IF_CAPCALDONE_Pos           (2UL)                     /*!< CAPCALDONE (Bit 2)                                    */
#define SYNTH_IF_CAPCALDONE_Msk           (0x4UL)                   /*!< CAPCALDONE (Bitfield-Mask: 0x01)                      */
#define SYNTH_IF_VCOHIGH_Pos              (4UL)                     /*!< VCOHIGH (Bit 4)                                       */
#define SYNTH_IF_VCOHIGH_Msk              (0x10UL)                  /*!< VCOHIGH (Bitfield-Mask: 0x01)                         */
#define SYNTH_IF_VCOLOW_Pos               (5UL)                     /*!< VCOLOW (Bit 5)                                        */
#define SYNTH_IF_VCOLOW_Msk               (0x20UL)                  /*!< VCOLOW (Bitfield-Mask: 0x01)                          */
#define SYNTH_IF_AUXCAPCALDONE_Pos        (6UL)                     /*!< AUXCAPCALDONE (Bit 6)                                 */
#define SYNTH_IF_AUXCAPCALDONE_Msk        (0x40UL)                  /*!< AUXCAPCALDONE (Bitfield-Mask: 0x01)                   */
#define SYNTH_IF_AUXLOCKED_Pos            (7UL)                     /*!< AUXLOCKED (Bit 7)                                     */
#define SYNTH_IF_AUXLOCKED_Msk            (0x80UL)                  /*!< AUXLOCKED (Bitfield-Mask: 0x01)                       */
#define SYNTH_IF_AUXUNLOCKED_Pos          (8UL)                     /*!< AUXUNLOCKED (Bit 8)                                   */
#define SYNTH_IF_AUXUNLOCKED_Msk          (0x100UL)                 /*!< AUXUNLOCKED (Bitfield-Mask: 0x01)                     */
/* ==========================================================  IFS  ========================================================== */
#define SYNTH_IFS_LOCKED_Pos              (0UL)                     /*!< LOCKED (Bit 0)                                        */
#define SYNTH_IFS_LOCKED_Msk              (0x1UL)                   /*!< LOCKED (Bitfield-Mask: 0x01)                          */
#define SYNTH_IFS_UNLOCKED_Pos            (1UL)                     /*!< UNLOCKED (Bit 1)                                      */
#define SYNTH_IFS_UNLOCKED_Msk            (0x2UL)                   /*!< UNLOCKED (Bitfield-Mask: 0x01)                        */
#define SYNTH_IFS_CAPCALDONE_Pos          (2UL)                     /*!< CAPCALDONE (Bit 2)                                    */
#define SYNTH_IFS_CAPCALDONE_Msk          (0x4UL)                   /*!< CAPCALDONE (Bitfield-Mask: 0x01)                      */
#define SYNTH_IFS_VCOHIGH_Pos             (4UL)                     /*!< VCOHIGH (Bit 4)                                       */
#define SYNTH_IFS_VCOHIGH_Msk             (0x10UL)                  /*!< VCOHIGH (Bitfield-Mask: 0x01)                         */
#define SYNTH_IFS_VCOLOW_Pos              (5UL)                     /*!< VCOLOW (Bit 5)                                        */
#define SYNTH_IFS_VCOLOW_Msk              (0x20UL)                  /*!< VCOLOW (Bitfield-Mask: 0x01)                          */
#define SYNTH_IFS_AUXCAPCALDONE_Pos       (6UL)                     /*!< AUXCAPCALDONE (Bit 6)                                 */
#define SYNTH_IFS_AUXCAPCALDONE_Msk       (0x40UL)                  /*!< AUXCAPCALDONE (Bitfield-Mask: 0x01)                   */
#define SYNTH_IFS_AUXLOCKED_Pos           (7UL)                     /*!< AUXLOCKED (Bit 7)                                     */
#define SYNTH_IFS_AUXLOCKED_Msk           (0x80UL)                  /*!< AUXLOCKED (Bitfield-Mask: 0x01)                       */
#define SYNTH_IFS_AUXUNLOCKED_Pos         (8UL)                     /*!< AUXUNLOCKED (Bit 8)                                   */
#define SYNTH_IFS_AUXUNLOCKED_Msk         (0x100UL)                 /*!< AUXUNLOCKED (Bitfield-Mask: 0x01)                     */
/* ==========================================================  IFC  ========================================================== */
#define SYNTH_IFC_LOCKED_Pos              (0UL)                     /*!< LOCKED (Bit 0)                                        */
#define SYNTH_IFC_LOCKED_Msk              (0x1UL)                   /*!< LOCKED (Bitfield-Mask: 0x01)                          */
#define SYNTH_IFC_UNLOCKED_Pos            (1UL)                     /*!< UNLOCKED (Bit 1)                                      */
#define SYNTH_IFC_UNLOCKED_Msk            (0x2UL)                   /*!< UNLOCKED (Bitfield-Mask: 0x01)                        */
#define SYNTH_IFC_CAPCALDONE_Pos          (2UL)                     /*!< CAPCALDONE (Bit 2)                                    */
#define SYNTH_IFC_CAPCALDONE_Msk          (0x4UL)                   /*!< CAPCALDONE (Bitfield-Mask: 0x01)                      */
#define SYNTH_IFC_VCOHIGH_Pos             (4UL)                     /*!< VCOHIGH (Bit 4)                                       */
#define SYNTH_IFC_VCOHIGH_Msk             (0x10UL)                  /*!< VCOHIGH (Bitfield-Mask: 0x01)                         */
#define SYNTH_IFC_VCOLOW_Pos              (5UL)                     /*!< VCOLOW (Bit 5)                                        */
#define SYNTH_IFC_VCOLOW_Msk              (0x20UL)                  /*!< VCOLOW (Bitfield-Mask: 0x01)                          */
#define SYNTH_IFC_AUXCAPCALDONE_Pos       (6UL)                     /*!< AUXCAPCALDONE (Bit 6)                                 */
#define SYNTH_IFC_AUXCAPCALDONE_Msk       (0x40UL)                  /*!< AUXCAPCALDONE (Bitfield-Mask: 0x01)                   */
#define SYNTH_IFC_AUXLOCKED_Pos           (7UL)                     /*!< AUXLOCKED (Bit 7)                                     */
#define SYNTH_IFC_AUXLOCKED_Msk           (0x80UL)                  /*!< AUXLOCKED (Bitfield-Mask: 0x01)                       */
#define SYNTH_IFC_AUXUNLOCKED_Pos         (8UL)                     /*!< AUXUNLOCKED (Bit 8)                                   */
#define SYNTH_IFC_AUXUNLOCKED_Msk         (0x100UL)                 /*!< AUXUNLOCKED (Bitfield-Mask: 0x01)                     */
/* ==========================================================  IEN  ========================================================== */
#define SYNTH_IEN_LOCKED_Pos              (0UL)                     /*!< LOCKED (Bit 0)                                        */
#define SYNTH_IEN_LOCKED_Msk              (0x1UL)                   /*!< LOCKED (Bitfield-Mask: 0x01)                          */
#define SYNTH_IEN_UNLOCKED_Pos            (1UL)                     /*!< UNLOCKED (Bit 1)                                      */
#define SYNTH_IEN_UNLOCKED_Msk            (0x2UL)                   /*!< UNLOCKED (Bitfield-Mask: 0x01)                        */
#define SYNTH_IEN_CAPCALDONE_Pos          (2UL)                     /*!< CAPCALDONE (Bit 2)                                    */
#define SYNTH_IEN_CAPCALDONE_Msk          (0x4UL)                   /*!< CAPCALDONE (Bitfield-Mask: 0x01)                      */
#define SYNTH_IEN_VCOHIGH_Pos             (4UL)                     /*!< VCOHIGH (Bit 4)                                       */
#define SYNTH_IEN_VCOHIGH_Msk             (0x10UL)                  /*!< VCOHIGH (Bitfield-Mask: 0x01)                         */
#define SYNTH_IEN_VCOLOW_Pos              (5UL)                     /*!< VCOLOW (Bit 5)                                        */
#define SYNTH_IEN_VCOLOW_Msk              (0x20UL)                  /*!< VCOLOW (Bitfield-Mask: 0x01)                          */
#define SYNTH_IEN_AUXCAPCALDONE_Pos       (6UL)                     /*!< AUXCAPCALDONE (Bit 6)                                 */
#define SYNTH_IEN_AUXCAPCALDONE_Msk       (0x40UL)                  /*!< AUXCAPCALDONE (Bitfield-Mask: 0x01)                   */
#define SYNTH_IEN_AUXLOCKED_Pos           (7UL)                     /*!< AUXLOCKED (Bit 7)                                     */
#define SYNTH_IEN_AUXLOCKED_Msk           (0x80UL)                  /*!< AUXLOCKED (Bitfield-Mask: 0x01)                       */
#define SYNTH_IEN_AUXUNLOCKED_Pos         (8UL)                     /*!< AUXUNLOCKED (Bit 8)                                   */
#define SYNTH_IEN_AUXUNLOCKED_Msk         (0x100UL)                 /*!< AUXUNLOCKED (Bitfield-Mask: 0x01)                     */


/** @} */
/** @} End of group EFR32FG1V_SYNTH */
/** @} End of group Parts */
