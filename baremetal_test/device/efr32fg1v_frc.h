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
 * @defgroup EFR32FG1V_FRC
 * @{
 * @brief EFR32FG1V_FRC Register Declaration
 ******************************************************************************/
/* =========================================================================================================================== */
/* ================                                            FRC                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Frame controller (FRC)
  */

typedef struct {                                /*!< (@ 0x40080000) FRC Structure                                              */
  __IM  uint32_t  STATUS;                       /*!< (@ 0x00000000) STATUS                                                     */
  __IOM uint32_t  DFLCTRL;                      /*!< (@ 0x00000004) DFLCTRL                                                    */
  __IOM uint32_t  MAXLENGTH;                    /*!< (@ 0x00000008) MAXLENGTH                                                  */
  __IOM uint32_t  ADDRFILTCTRL;                 /*!< (@ 0x0000000C) ADDRFILTCTRL                                               */
  __IOM uint32_t  DATABUFFER;                   /*!< (@ 0x00000010) DATABUFFER                                                 */
  __IOM uint32_t  WCNT;                         /*!< (@ 0x00000014) WCNT                                                       */
  __IOM uint32_t  WCNTCMP0;                     /*!< (@ 0x00000018) WCNTCMP0                                                   */
  __IOM uint32_t  WCNTCMP1;                     /*!< (@ 0x0000001C) WCNTCMP1                                                   */
  __IOM uint32_t  WCNTCMP2;                     /*!< (@ 0x00000020) WCNTCMP2                                                   */
  __OM  uint32_t  CMD;                          /*!< (@ 0x00000024) CMD                                                        */
  __IOM uint32_t  WHITECTRL;                    /*!< (@ 0x00000028) WHITECTRL                                                  */
  __IOM uint32_t  WHITEPOLY;                    /*!< (@ 0x0000002C) WHITEPOLY                                                  */
  __IOM uint32_t  WHITEINIT;                    /*!< (@ 0x00000030) WHITEINIT                                                  */
  __IOM uint32_t  FECCTRL;                      /*!< (@ 0x00000034) FECCTRL                                                    */
  __IOM uint32_t  BLOCKRAMADDR;                 /*!< (@ 0x00000038) BLOCKRAMADDR                                               */
  __IOM uint32_t  CONVRAMADDR;                  /*!< (@ 0x0000003C) CONVRAMADDR                                                */
  __IOM uint32_t  CTRL;                         /*!< (@ 0x00000040) CTRL                                                       */
  __IOM uint32_t  RXCTRL;                       /*!< (@ 0x00000044) RXCTRL                                                     */
  __IOM uint32_t  TRAILTXDATACTRL;              /*!< (@ 0x00000048) TRAILTXDATACTRL                                            */
  __IOM uint32_t  TRAILRXDATA;                  /*!< (@ 0x0000004C) TRAILRXDATA                                                */
  __IM  uint32_t  SCNT;                         /*!< (@ 0x00000050) SCNT                                                       */
  __IOM uint32_t  CONVGENERATOR;                /*!< (@ 0x00000054) CONVGENERATOR                                              */
  __IOM uint32_t  PUNCTCTRL;                    /*!< (@ 0x00000058) PUNCTCTRL                                                  */
  __IOM uint32_t  PAUSECTRL;                    /*!< (@ 0x0000005C) PAUSECTRL                                                  */
  __IM  uint32_t  IF;                           /*!< (@ 0x00000060) IF                                                         */
  __OM  uint32_t  IFS;                          /*!< (@ 0x00000064) IFS                                                        */
  __OM  uint32_t  IFC;                          /*!< (@ 0x00000068) IFC                                                        */
  __IOM uint32_t  IEN;                          /*!< (@ 0x0000006C) IEN                                                        */
  __IOM uint32_t  BUFFERMODE;                   /*!< (@ 0x00000070) BUFFERMODE                                                 */
  __IOM uint32_t  ROUTEPEN;                     /*!< (@ 0x00000074) ROUTEPEN                                                   */
  __IOM uint32_t  ROUTELOC0;                    /*!< (@ 0x00000078) ROUTELOC0                                                  */
  __IOM uint32_t  SNIFFCTRL;                    /*!< (@ 0x0000007C) SNIFFCTRL                                                  */
  __IOM uint32_t  AUXDATA;                      /*!< (@ 0x00000080) AUXDATA                                                    */
  __IOM uint32_t  RAWCTRL;                      /*!< (@ 0x00000084) RAWCTRL                                                    */
  __IM  uint32_t  RXRAWDATA;                    /*!< (@ 0x00000088) RXRAWDATA                                                  */
  __IM  uint32_t  PAUSEDATA;                    /*!< (@ 0x0000008C) PAUSEDATA                                                  */
  __IM  uint32_t  LIKELYCONVSTATE;              /*!< (@ 0x00000090) LIKELYCONVSTATE                                            */
  __IM  uint32_t  INTELEMENTNEXT;               /*!< (@ 0x00000094) INTELEMENTNEXT                                             */
  __IOM uint32_t  INTWRITEPOINT;                /*!< (@ 0x00000098) INTWRITEPOINT                                              */
  __IOM uint32_t  INTREADPOINT;                 /*!< (@ 0x0000009C) INTREADPOINT                                               */
  __IOM uint32_t  FCD0;                         /*!< (@ 0x000000A0) FCD0                                                       */
  __IOM uint32_t  FCD1;                         /*!< (@ 0x000000A4) FCD1                                                       */
  __IOM uint32_t  FCD2;                         /*!< (@ 0x000000A8) FCD2                                                       */
  __IOM uint32_t  FCD3;                         /*!< (@ 0x000000AC) FCD3                                                       */
  __IM  uint32_t  RESERVED[4];
  __IM  uint32_t  INTELEMENT0;                  /*!< (@ 0x000000C0) INTELEMENT0                                                */
  __IM  uint32_t  INTELEMENT1;                  /*!< (@ 0x000000C4) INTELEMENT1                                                */
  __IM  uint32_t  INTELEMENT2;                  /*!< (@ 0x000000C8) INTELEMENT2                                                */
  __IM  uint32_t  INTELEMENT3;                  /*!< (@ 0x000000CC) INTELEMENT3                                                */
  __IM  uint32_t  INTELEMENT4;                  /*!< (@ 0x000000D0) INTELEMENT4                                                */
  __IM  uint32_t  INTELEMENT5;                  /*!< (@ 0x000000D4) INTELEMENT5                                                */
  __IM  uint32_t  INTELEMENT6;                  /*!< (@ 0x000000D8) INTELEMENT6                                                */
  __IM  uint32_t  INTELEMENT7;                  /*!< (@ 0x000000DC) INTELEMENT7                                                */
  __IM  uint32_t  INTELEMENT8;                  /*!< (@ 0x000000E0) INTELEMENT8                                                */
  __IM  uint32_t  INTELEMENT9;                  /*!< (@ 0x000000E4) INTELEMENT9                                                */
  __IM  uint32_t  INTELEMENT10;                 /*!< (@ 0x000000E8) INTELEMENT10                                               */
  __IM  uint32_t  INTELEMENT11;                 /*!< (@ 0x000000EC) INTELEMENT11                                               */
  __IM  uint32_t  INTELEMENT12;                 /*!< (@ 0x000000F0) INTELEMENT12                                               */
  __IM  uint32_t  INTELEMENT13;                 /*!< (@ 0x000000F4) INTELEMENT13                                               */
  __IM  uint32_t  INTELEMENT14;                 /*!< (@ 0x000000F8) INTELEMENT14                                               */
  __IM  uint32_t  INTELEMENT15;                 /*!< (@ 0x000000FC) INTELEMENT15                                               */
} FRC_Typedef;                                     /*!< Size = 256 (0x100)                                                        */

/* =========================================================================================================================== */
/* ================                                            FRC                                            ================ */
/* =========================================================================================================================== */

/* ========================================================  STATUS  ========================================================= */
#define FRC_STATUS_ACTIVETXFCD_Pos        (0UL)                     /*!< ACTIVETXFCD (Bit 0)                                   */
#define FRC_STATUS_ACTIVETXFCD_Msk        (0x1UL)                   /*!< ACTIVETXFCD (Bitfield-Mask: 0x01)                     */
#define FRC_STATUS_ACTIVERXFCD_Pos        (1UL)                     /*!< ACTIVERXFCD (Bit 1)                                   */
#define FRC_STATUS_ACTIVERXFCD_Msk        (0x2UL)                   /*!< ACTIVERXFCD (Bitfield-Mask: 0x01)                     */
#define FRC_STATUS_RXABORTINPROGRESS_Pos  (2UL)                     /*!< RXABORTINPROGRESS (Bit 2)                             */
#define FRC_STATUS_RXABORTINPROGRESS_Msk  (0x4UL)                   /*!< RXABORTINPROGRESS (Bitfield-Mask: 0x01)               */
#define FRC_STATUS_SNIFFDFRAME_Pos        (3UL)                     /*!< SNIFFDFRAME (Bit 3)                                   */
#define FRC_STATUS_SNIFFDFRAME_Msk        (0x8UL)                   /*!< SNIFFDFRAME (Bitfield-Mask: 0x01)                     */
#define FRC_STATUS_SNIFFDCOUNT_Pos        (4UL)                     /*!< SNIFFDCOUNT (Bit 4)                                   */
#define FRC_STATUS_SNIFFDCOUNT_Msk        (0xf0UL)                  /*!< SNIFFDCOUNT (Bitfield-Mask: 0x0f)                     */
#define FRC_STATUS_RXRAWBLOCKED_Pos       (8UL)                     /*!< RXRAWBLOCKED (Bit 8)                                  */
#define FRC_STATUS_RXRAWBLOCKED_Msk       (0x100UL)                 /*!< RXRAWBLOCKED (Bitfield-Mask: 0x01)                    */
/* ========================================================  DFLCTRL  ======================================================== */
#define FRC_DFLCTRL_DFLMODE_Pos           (0UL)                     /*!< DFLMODE (Bit 0)                                       */
#define FRC_DFLCTRL_DFLMODE_Msk           (0x7UL)                   /*!< DFLMODE (Bitfield-Mask: 0x07)                         */
#define FRC_DFLCTRL_DFLBITORDER_Pos       (3UL)                     /*!< DFLBITORDER (Bit 3)                                   */
#define FRC_DFLCTRL_DFLBITORDER_Msk       (0x8UL)                   /*!< DFLBITORDER (Bitfield-Mask: 0x01)                     */
#define FRC_DFLCTRL_DFLSHIFT_Pos          (4UL)                     /*!< DFLSHIFT (Bit 4)                                      */
#define FRC_DFLCTRL_DFLSHIFT_Msk          (0x70UL)                  /*!< DFLSHIFT (Bitfield-Mask: 0x07)                        */
#define FRC_DFLCTRL_DFLOFFSET_Pos         (8UL)                     /*!< DFLOFFSET (Bit 8)                                     */
#define FRC_DFLCTRL_DFLOFFSET_Msk         (0xf00UL)                 /*!< DFLOFFSET (Bitfield-Mask: 0x0f)                       */
#define FRC_DFLCTRL_DFLBITS_Pos           (12UL)                    /*!< DFLBITS (Bit 12)                                      */
#define FRC_DFLCTRL_DFLBITS_Msk           (0xf000UL)                /*!< DFLBITS (Bitfield-Mask: 0x0f)                         */
#define FRC_DFLCTRL_MINLENGTH_Pos         (16UL)                    /*!< MINLENGTH (Bit 16)                                    */
#define FRC_DFLCTRL_MINLENGTH_Msk         (0xf0000UL)               /*!< MINLENGTH (Bitfield-Mask: 0x0f)                       */
#define FRC_DFLCTRL_DFLINCLUDECRC_Pos     (20UL)                    /*!< DFLINCLUDECRC (Bit 20)                                */
#define FRC_DFLCTRL_DFLINCLUDECRC_Msk     (0x100000UL)              /*!< DFLINCLUDECRC (Bitfield-Mask: 0x01)                   */
/* =======================================================  MAXLENGTH  ======================================================= */
#define FRC_MAXLENGTH_MAXLENGTH_Pos       (0UL)                     /*!< MAXLENGTH (Bit 0)                                     */
#define FRC_MAXLENGTH_MAXLENGTH_Msk       (0xfffUL)                 /*!< MAXLENGTH (Bitfield-Mask: 0xfff)                      */
/* =====================================================  ADDRFILTCTRL  ====================================================== */
#define FRC_ADDRFILTCTRL_EN_Pos           (0UL)                     /*!< EN (Bit 0)                                            */
#define FRC_ADDRFILTCTRL_EN_Msk           (0x1UL)                   /*!< EN (Bitfield-Mask: 0x01)                              */
#define FRC_ADDRFILTCTRL_BRDCST00EN_Pos   (1UL)                     /*!< BRDCST00EN (Bit 1)                                    */
#define FRC_ADDRFILTCTRL_BRDCST00EN_Msk   (0x2UL)                   /*!< BRDCST00EN (Bitfield-Mask: 0x01)                      */
#define FRC_ADDRFILTCTRL_BRDCSTFFEN_Pos   (2UL)                     /*!< BRDCSTFFEN (Bit 2)                                    */
#define FRC_ADDRFILTCTRL_BRDCSTFFEN_Msk   (0x4UL)                   /*!< BRDCSTFFEN (Bitfield-Mask: 0x01)                      */
#define FRC_ADDRFILTCTRL_ADDRESS_Pos      (8UL)                     /*!< ADDRESS (Bit 8)                                       */
#define FRC_ADDRFILTCTRL_ADDRESS_Msk      (0xff00UL)                /*!< ADDRESS (Bitfield-Mask: 0xff)                         */
/* ======================================================  DATABUFFER  ======================================================= */
#define FRC_DATABUFFER_DATABUFFER_Pos     (0UL)                     /*!< DATABUFFER (Bit 0)                                    */
#define FRC_DATABUFFER_DATABUFFER_Msk     (0xffUL)                  /*!< DATABUFFER (Bitfield-Mask: 0xff)                      */
/* =========================================================  WCNT  ========================================================== */
#define FRC_WCNT_WCNT_Pos                 (0UL)                     /*!< WCNT (Bit 0)                                          */
#define FRC_WCNT_WCNT_Msk                 (0xfffUL)                 /*!< WCNT (Bitfield-Mask: 0xfff)                           */
/* =======================================================  WCNTCMP0  ======================================================== */
#define FRC_WCNTCMP0_FRAMELENGTH_Pos      (0UL)                     /*!< FRAMELENGTH (Bit 0)                                   */
#define FRC_WCNTCMP0_FRAMELENGTH_Msk      (0xfffUL)                 /*!< FRAMELENGTH (Bitfield-Mask: 0xfff)                    */
/* =======================================================  WCNTCMP1  ======================================================== */
#define FRC_WCNTCMP1_LENGTHFIELDLOC_Pos   (0UL)                     /*!< LENGTHFIELDLOC (Bit 0)                                */
#define FRC_WCNTCMP1_LENGTHFIELDLOC_Msk   (0xfffUL)                 /*!< LENGTHFIELDLOC (Bitfield-Mask: 0xfff)                 */
/* =======================================================  WCNTCMP2  ======================================================== */
#define FRC_WCNTCMP2_ADDRFIELDLOC_Pos     (0UL)                     /*!< ADDRFIELDLOC (Bit 0)                                  */
#define FRC_WCNTCMP2_ADDRFIELDLOC_Msk     (0xfffUL)                 /*!< ADDRFIELDLOC (Bitfield-Mask: 0xfff)                   */
/* ==========================================================  CMD  ========================================================== */
#define FRC_CMD_RXABORT_Pos               (0UL)                     /*!< RXABORT (Bit 0)                                       */
#define FRC_CMD_RXABORT_Msk               (0x1UL)                   /*!< RXABORT (Bitfield-Mask: 0x01)                         */
#define FRC_CMD_FRAMEDETRESUME_Pos        (1UL)                     /*!< FRAMEDETRESUME (Bit 1)                                */
#define FRC_CMD_FRAMEDETRESUME_Msk        (0x2UL)                   /*!< FRAMEDETRESUME (Bitfield-Mask: 0x01)                  */
#define FRC_CMD_INTERLEAVEWRITERESUME_Pos (2UL)                     /*!< INTERLEAVEWRITERESUME (Bit 2)                         */
#define FRC_CMD_INTERLEAVEWRITERESUME_Msk (0x4UL)                   /*!< INTERLEAVEWRITERESUME (Bitfield-Mask: 0x01)           */
#define FRC_CMD_INTERLEAVEREADRESUME_Pos  (3UL)                     /*!< INTERLEAVEREADRESUME (Bit 3)                          */
#define FRC_CMD_INTERLEAVEREADRESUME_Msk  (0x8UL)                   /*!< INTERLEAVEREADRESUME (Bitfield-Mask: 0x01)            */
#define FRC_CMD_CONVRESUME_Pos            (4UL)                     /*!< CONVRESUME (Bit 4)                                    */
#define FRC_CMD_CONVRESUME_Msk            (0x10UL)                  /*!< CONVRESUME (Bitfield-Mask: 0x01)                      */
#define FRC_CMD_CONVTERMINATE_Pos         (5UL)                     /*!< CONVTERMINATE (Bit 5)                                 */
#define FRC_CMD_CONVTERMINATE_Msk         (0x20UL)                  /*!< CONVTERMINATE (Bitfield-Mask: 0x01)                   */
#define FRC_CMD_TXSUBFRAMERESUME_Pos      (6UL)                     /*!< TXSUBFRAMERESUME (Bit 6)                              */
#define FRC_CMD_TXSUBFRAMERESUME_Msk      (0x40UL)                  /*!< TXSUBFRAMERESUME (Bitfield-Mask: 0x01)                */
#define FRC_CMD_INTERLEAVEINIT_Pos        (7UL)                     /*!< INTERLEAVEINIT (Bit 7)                                */
#define FRC_CMD_INTERLEAVEINIT_Msk        (0x80UL)                  /*!< INTERLEAVEINIT (Bitfield-Mask: 0x01)                  */
#define FRC_CMD_INTERLEAVECNTCLEAR_Pos    (8UL)                     /*!< INTERLEAVECNTCLEAR (Bit 8)                            */
#define FRC_CMD_INTERLEAVECNTCLEAR_Msk    (0x100UL)                 /*!< INTERLEAVECNTCLEAR (Bitfield-Mask: 0x01)              */
#define FRC_CMD_CONVINIT_Pos              (9UL)                     /*!< CONVINIT (Bit 9)                                      */
#define FRC_CMD_CONVINIT_Msk              (0x200UL)                 /*!< CONVINIT (Bitfield-Mask: 0x01)                        */
#define FRC_CMD_BLOCKINIT_Pos             (10UL)                    /*!< BLOCKINIT (Bit 10)                                    */
#define FRC_CMD_BLOCKINIT_Msk             (0x400UL)                 /*!< BLOCKINIT (Bitfield-Mask: 0x01)                       */
#define FRC_CMD_STATEINIT_Pos             (11UL)                    /*!< STATEINIT (Bit 11)                                    */
#define FRC_CMD_STATEINIT_Msk             (0x800UL)                 /*!< STATEINIT (Bitfield-Mask: 0x01)                       */
#define FRC_CMD_RXRAWUNBLOCK_Pos          (12UL)                    /*!< RXRAWUNBLOCK (Bit 12)                                 */
#define FRC_CMD_RXRAWUNBLOCK_Msk          (0x1000UL)                /*!< RXRAWUNBLOCK (Bitfield-Mask: 0x01)                    */
/* =======================================================  WHITECTRL  ======================================================= */
#define FRC_WHITECTRL_FEEDBACKSEL_Pos     (0UL)                     /*!< FEEDBACKSEL (Bit 0)                                   */
#define FRC_WHITECTRL_FEEDBACKSEL_Msk     (0x1fUL)                  /*!< FEEDBACKSEL (Bitfield-Mask: 0x1f)                     */
#define FRC_WHITECTRL_XORFEEDBACK_Pos     (5UL)                     /*!< XORFEEDBACK (Bit 5)                                   */
#define FRC_WHITECTRL_XORFEEDBACK_Msk     (0x60UL)                  /*!< XORFEEDBACK (Bitfield-Mask: 0x03)                     */
#define FRC_WHITECTRL_SHROUTPUTSEL_Pos    (8UL)                     /*!< SHROUTPUTSEL (Bit 8)                                  */
#define FRC_WHITECTRL_SHROUTPUTSEL_Msk    (0xf00UL)                 /*!< SHROUTPUTSEL (Bitfield-Mask: 0x0f)                    */
#define FRC_WHITECTRL_BLOCKERRORCORRECT_Pos (12UL)                  /*!< BLOCKERRORCORRECT (Bit 12)                            */
#define FRC_WHITECTRL_BLOCKERRORCORRECT_Msk (0x1000UL)              /*!< BLOCKERRORCORRECT (Bitfield-Mask: 0x01)               */
/* =======================================================  WHITEPOLY  ======================================================= */
#define FRC_WHITEPOLY_POLY_Pos            (0UL)                     /*!< POLY (Bit 0)                                          */
#define FRC_WHITEPOLY_POLY_Msk            (0xffffUL)                /*!< POLY (Bitfield-Mask: 0xffff)                          */
/* =======================================================  WHITEINIT  ======================================================= */
#define FRC_WHITEINIT_WHITEINIT_Pos       (0UL)                     /*!< WHITEINIT (Bit 0)                                     */
#define FRC_WHITEINIT_WHITEINIT_Msk       (0xffffUL)                /*!< WHITEINIT (Bitfield-Mask: 0xffff)                     */
/* ========================================================  FECCTRL  ======================================================== */
#define FRC_FECCTRL_BLOCKWHITEMODE_Pos    (0UL)                     /*!< BLOCKWHITEMODE (Bit 0)                                */
#define FRC_FECCTRL_BLOCKWHITEMODE_Msk    (0x7UL)                   /*!< BLOCKWHITEMODE (Bitfield-Mask: 0x07)                  */
#define FRC_FECCTRL_CONVMODE_Pos          (4UL)                     /*!< CONVMODE (Bit 4)                                      */
#define FRC_FECCTRL_CONVMODE_Msk          (0x30UL)                  /*!< CONVMODE (Bitfield-Mask: 0x03)                        */
#define FRC_FECCTRL_CONVDECODEMODE_Pos    (6UL)                     /*!< CONVDECODEMODE (Bit 6)                                */
#define FRC_FECCTRL_CONVDECODEMODE_Msk    (0x40UL)                  /*!< CONVDECODEMODE (Bitfield-Mask: 0x01)                  */
#define FRC_FECCTRL_CONVTRACEBACKDISABLE_Pos (7UL)                  /*!< CONVTRACEBACKDISABLE (Bit 7)                          */
#define FRC_FECCTRL_CONVTRACEBACKDISABLE_Msk (0x80UL)               /*!< CONVTRACEBACKDISABLE (Bitfield-Mask: 0x01)            */
#define FRC_FECCTRL_CONVINV_Pos           (8UL)                     /*!< CONVINV (Bit 8)                                       */
#define FRC_FECCTRL_CONVINV_Msk           (0x300UL)                 /*!< CONVINV (Bitfield-Mask: 0x03)                         */
#define FRC_FECCTRL_INTERLEAVEMODE_Pos    (10UL)                    /*!< INTERLEAVEMODE (Bit 10)                               */
#define FRC_FECCTRL_INTERLEAVEMODE_Msk    (0xc00UL)                 /*!< INTERLEAVEMODE (Bitfield-Mask: 0x03)                  */
#define FRC_FECCTRL_INTERLEAVEFIRSTINDEX_Pos (12UL)                 /*!< INTERLEAVEFIRSTINDEX (Bit 12)                         */
#define FRC_FECCTRL_INTERLEAVEFIRSTINDEX_Msk (0xf000UL)             /*!< INTERLEAVEFIRSTINDEX (Bitfield-Mask: 0x0f)            */
#define FRC_FECCTRL_INTERLEAVEWIDTH_Pos   (16UL)                    /*!< INTERLEAVEWIDTH (Bit 16)                              */
#define FRC_FECCTRL_INTERLEAVEWIDTH_Msk   (0x10000UL)               /*!< INTERLEAVEWIDTH (Bitfield-Mask: 0x01)                 */
#define FRC_FECCTRL_CONVBUSLOCK_Pos       (17UL)                    /*!< CONVBUSLOCK (Bit 17)                                  */
#define FRC_FECCTRL_CONVBUSLOCK_Msk       (0x20000UL)               /*!< CONVBUSLOCK (Bitfield-Mask: 0x01)                     */
#define FRC_FECCTRL_CONVSUBFRAMETERMINATE_Pos (18UL)                /*!< CONVSUBFRAMETERMINATE (Bit 18)                        */
#define FRC_FECCTRL_CONVSUBFRAMETERMINATE_Msk (0x40000UL)           /*!< CONVSUBFRAMETERMINATE (Bitfield-Mask: 0x01)           */
#define FRC_FECCTRL_SINGLEBLOCK_Pos       (19UL)                    /*!< SINGLEBLOCK (Bit 19)                                  */
#define FRC_FECCTRL_SINGLEBLOCK_Msk       (0x80000UL)               /*!< SINGLEBLOCK (Bitfield-Mask: 0x01)                     */
#define FRC_FECCTRL_FORCE2FSK_Pos         (20UL)                    /*!< FORCE2FSK (Bit 20)                                    */
#define FRC_FECCTRL_FORCE2FSK_Msk         (0x100000UL)              /*!< FORCE2FSK (Bitfield-Mask: 0x01)                       */
#define FRC_FECCTRL_CONVHARDERROR_Pos     (21UL)                    /*!< CONVHARDERROR (Bit 21)                                */
#define FRC_FECCTRL_CONVHARDERROR_Msk     (0x200000UL)              /*!< CONVHARDERROR (Bitfield-Mask: 0x01)                   */
/* =====================================================  BLOCKRAMADDR  ====================================================== */
#define FRC_BLOCKRAMADDR_BLOCKRAMADDR_Pos (2UL)                     /*!< BLOCKRAMADDR (Bit 2)                                  */
#define FRC_BLOCKRAMADDR_BLOCKRAMADDR_Msk (0x7ffcUL)                /*!< BLOCKRAMADDR (Bitfield-Mask: 0x1fff)                  */
/* ======================================================  CONVRAMADDR  ====================================================== */
#define FRC_CONVRAMADDR_CONVRAMADDR_Pos   (2UL)                     /*!< CONVRAMADDR (Bit 2)                                   */
#define FRC_CONVRAMADDR_CONVRAMADDR_Msk   (0x7ffcUL)                /*!< CONVRAMADDR (Bitfield-Mask: 0x1fff)                   */
/* =========================================================  CTRL  ========================================================== */
#define FRC_CTRL_RANDOMTX_Pos             (0UL)                     /*!< RANDOMTX (Bit 0)                                      */
#define FRC_CTRL_RANDOMTX_Msk             (0x1UL)                   /*!< RANDOMTX (Bitfield-Mask: 0x01)                        */
#define FRC_CTRL_UARTMODE_Pos             (1UL)                     /*!< UARTMODE (Bit 1)                                      */
#define FRC_CTRL_UARTMODE_Msk             (0x2UL)                   /*!< UARTMODE (Bitfield-Mask: 0x01)                        */
#define FRC_CTRL_BITORDER_Pos             (2UL)                     /*!< BITORDER (Bit 2)                                      */
#define FRC_CTRL_BITORDER_Msk             (0x4UL)                   /*!< BITORDER (Bitfield-Mask: 0x01)                        */
#define FRC_CTRL_TXFCDMODE_Pos            (4UL)                     /*!< TXFCDMODE (Bit 4)                                     */
#define FRC_CTRL_TXFCDMODE_Msk            (0x30UL)                  /*!< TXFCDMODE (Bitfield-Mask: 0x03)                       */
#define FRC_CTRL_RXFCDMODE_Pos            (6UL)                     /*!< RXFCDMODE (Bit 6)                                     */
#define FRC_CTRL_RXFCDMODE_Msk            (0xc0UL)                  /*!< RXFCDMODE (Bitfield-Mask: 0x03)                       */
#define FRC_CTRL_BITSPERWORD_Pos          (8UL)                     /*!< BITSPERWORD (Bit 8)                                   */
#define FRC_CTRL_BITSPERWORD_Msk          (0x700UL)                 /*!< BITSPERWORD (Bitfield-Mask: 0x07)                     */
#define FRC_CTRL_RATESELECT_Pos           (11UL)                    /*!< RATESELECT (Bit 11)                                   */
#define FRC_CTRL_RATESELECT_Msk           (0x1800UL)                /*!< RATESELECT (Bitfield-Mask: 0x03)                      */
#define FRC_CTRL_TXPREFETCH_Pos           (13UL)                    /*!< TXPREFETCH (Bit 13)                                   */
#define FRC_CTRL_TXPREFETCH_Msk           (0x2000UL)                /*!< TXPREFETCH (Bitfield-Mask: 0x01)                      */
#define FRC_CTRL_SEQHANDSHAKE_Pos         (16UL)                    /*!< SEQHANDSHAKE (Bit 16)                                 */
#define FRC_CTRL_SEQHANDSHAKE_Msk         (0x10000UL)               /*!< SEQHANDSHAKE (Bitfield-Mask: 0x01)                    */
#define FRC_CTRL_PRBSTEST_Pos             (17UL)                    /*!< PRBSTEST (Bit 17)                                     */
#define FRC_CTRL_PRBSTEST_Msk             (0x20000UL)               /*!< PRBSTEST (Bitfield-Mask: 0x01)                        */
/* ========================================================  RXCTRL  ========================================================= */
#define FRC_RXCTRL_STORECRC_Pos           (0UL)                     /*!< STORECRC (Bit 0)                                      */
#define FRC_RXCTRL_STORECRC_Msk           (0x1UL)                   /*!< STORECRC (Bitfield-Mask: 0x01)                        */
#define FRC_RXCTRL_ACCEPTCRCERRORS_Pos    (1UL)                     /*!< ACCEPTCRCERRORS (Bit 1)                               */
#define FRC_RXCTRL_ACCEPTCRCERRORS_Msk    (0x2UL)                   /*!< ACCEPTCRCERRORS (Bitfield-Mask: 0x01)                 */
#define FRC_RXCTRL_ACCEPTBLOCKERRORS_Pos  (2UL)                     /*!< ACCEPTBLOCKERRORS (Bit 2)                             */
#define FRC_RXCTRL_ACCEPTBLOCKERRORS_Msk  (0x4UL)                   /*!< ACCEPTBLOCKERRORS (Bitfield-Mask: 0x01)               */
#define FRC_RXCTRL_TRACKABFRAME_Pos       (3UL)                     /*!< TRACKABFRAME (Bit 3)                                  */
#define FRC_RXCTRL_TRACKABFRAME_Msk       (0x8UL)                   /*!< TRACKABFRAME (Bitfield-Mask: 0x01)                    */
#define FRC_RXCTRL_BUFCLEAR_Pos           (4UL)                     /*!< BUFCLEAR (Bit 4)                                      */
#define FRC_RXCTRL_BUFCLEAR_Msk           (0x10UL)                  /*!< BUFCLEAR (Bitfield-Mask: 0x01)                        */
#define FRC_RXCTRL_BUFRESTOREFRAMEERROR_Pos (5UL)                   /*!< BUFRESTOREFRAMEERROR (Bit 5)                          */
#define FRC_RXCTRL_BUFRESTOREFRAMEERROR_Msk (0x20UL)                /*!< BUFRESTOREFRAMEERROR (Bitfield-Mask: 0x01)            */
#define FRC_RXCTRL_BUFRESTORERXABORTED_Pos (6UL)                    /*!< BUFRESTORERXABORTED (Bit 6)                           */
#define FRC_RXCTRL_BUFRESTORERXABORTED_Msk (0x40UL)                 /*!< BUFRESTORERXABORTED (Bitfield-Mask: 0x01)             */
/* ====================================================  TRAILTXDATACTRL  ==================================================== */
#define FRC_TRAILTXDATACTRL_TRAILTXDATA_Pos (0UL)                   /*!< TRAILTXDATA (Bit 0)                                   */
#define FRC_TRAILTXDATACTRL_TRAILTXDATA_Msk (0xffUL)                /*!< TRAILTXDATA (Bitfield-Mask: 0xff)                     */
#define FRC_TRAILTXDATACTRL_TRAILTXDATACNT_Pos (8UL)                /*!< TRAILTXDATACNT (Bit 8)                                */
#define FRC_TRAILTXDATACTRL_TRAILTXDATACNT_Msk (0x700UL)            /*!< TRAILTXDATACNT (Bitfield-Mask: 0x07)                  */
#define FRC_TRAILTXDATACTRL_TRAILTXDATAFORCE_Pos (11UL)             /*!< TRAILTXDATAFORCE (Bit 11)                             */
#define FRC_TRAILTXDATACTRL_TRAILTXDATAFORCE_Msk (0x800UL)          /*!< TRAILTXDATAFORCE (Bitfield-Mask: 0x01)                */
/* ======================================================  TRAILRXDATA  ====================================================== */
#define FRC_TRAILRXDATA_RSSI_Pos          (0UL)                     /*!< RSSI (Bit 0)                                          */
#define FRC_TRAILRXDATA_RSSI_Msk          (0x1UL)                   /*!< RSSI (Bitfield-Mask: 0x01)                            */
#define FRC_TRAILRXDATA_CRCOK_Pos         (1UL)                     /*!< CRCOK (Bit 1)                                         */
#define FRC_TRAILRXDATA_CRCOK_Msk         (0x2UL)                   /*!< CRCOK (Bitfield-Mask: 0x01)                           */
#define FRC_TRAILRXDATA_PROTIMERCC0BASE_Pos (2UL)                   /*!< PROTIMERCC0BASE (Bit 2)                               */
#define FRC_TRAILRXDATA_PROTIMERCC0BASE_Msk (0x4UL)                 /*!< PROTIMERCC0BASE (Bitfield-Mask: 0x01)                 */
#define FRC_TRAILRXDATA_PROTIMERCC0WRAPL_Pos (3UL)                  /*!< PROTIMERCC0WRAPL (Bit 3)                              */
#define FRC_TRAILRXDATA_PROTIMERCC0WRAPL_Msk (0x8UL)                /*!< PROTIMERCC0WRAPL (Bitfield-Mask: 0x01)                */
#define FRC_TRAILRXDATA_PROTIMERCC0WRAPH_Pos (4UL)                  /*!< PROTIMERCC0WRAPH (Bit 4)                              */
#define FRC_TRAILRXDATA_PROTIMERCC0WRAPH_Msk (0x10UL)               /*!< PROTIMERCC0WRAPH (Bitfield-Mask: 0x01)                */
#define FRC_TRAILRXDATA_RTCSTAMP_Pos      (5UL)                     /*!< RTCSTAMP (Bit 5)                                      */
#define FRC_TRAILRXDATA_RTCSTAMP_Msk      (0x20UL)                  /*!< RTCSTAMP (Bitfield-Mask: 0x01)                        */
/* =========================================================  SCNT  ========================================================== */
#define FRC_SCNT_SCNT_Pos                 (0UL)                     /*!< SCNT (Bit 0)                                          */
#define FRC_SCNT_SCNT_Msk                 (0xffUL)                  /*!< SCNT (Bitfield-Mask: 0xff)                            */
/* =====================================================  CONVGENERATOR  ===================================================== */
#define FRC_CONVGENERATOR_GENERATOR0_Pos  (0UL)                     /*!< GENERATOR0 (Bit 0)                                    */
#define FRC_CONVGENERATOR_GENERATOR0_Msk  (0x7fUL)                  /*!< GENERATOR0 (Bitfield-Mask: 0x7f)                      */
#define FRC_CONVGENERATOR_GENERATOR1_Pos  (8UL)                     /*!< GENERATOR1 (Bit 8)                                    */
#define FRC_CONVGENERATOR_GENERATOR1_Msk  (0x7f00UL)                /*!< GENERATOR1 (Bitfield-Mask: 0x7f)                      */
#define FRC_CONVGENERATOR_RECURSIVE_Pos   (16UL)                    /*!< RECURSIVE (Bit 16)                                    */
#define FRC_CONVGENERATOR_RECURSIVE_Msk   (0x10000UL)               /*!< RECURSIVE (Bitfield-Mask: 0x01)                       */
#define FRC_CONVGENERATOR_NONSYSTEMATIC_Pos (17UL)                  /*!< NONSYSTEMATIC (Bit 17)                                */
#define FRC_CONVGENERATOR_NONSYSTEMATIC_Msk (0x20000UL)             /*!< NONSYSTEMATIC (Bitfield-Mask: 0x01)                   */
/* =======================================================  PUNCTCTRL  ======================================================= */
#define FRC_PUNCTCTRL_PUNCT0_Pos          (0UL)                     /*!< PUNCT0 (Bit 0)                                        */
#define FRC_PUNCTCTRL_PUNCT0_Msk          (0x7fUL)                  /*!< PUNCT0 (Bitfield-Mask: 0x7f)                          */
#define FRC_PUNCTCTRL_PUNCT1_Pos          (8UL)                     /*!< PUNCT1 (Bit 8)                                        */
#define FRC_PUNCTCTRL_PUNCT1_Msk          (0x7f00UL)                /*!< PUNCT1 (Bitfield-Mask: 0x7f)                          */
/* =======================================================  PAUSECTRL  ======================================================= */
#define FRC_PAUSECTRL_FRAMEDETPAUSEEN_Pos (0UL)                     /*!< FRAMEDETPAUSEEN (Bit 0)                               */
#define FRC_PAUSECTRL_FRAMEDETPAUSEEN_Msk (0x1UL)                   /*!< FRAMEDETPAUSEEN (Bitfield-Mask: 0x01)                 */
#define FRC_PAUSECTRL_TXINTERLEAVEWRITEPAUSEEN_Pos (1UL)            /*!< TXINTERLEAVEWRITEPAUSEEN (Bit 1)                      */
#define FRC_PAUSECTRL_TXINTERLEAVEWRITEPAUSEEN_Msk (0x2UL)          /*!< TXINTERLEAVEWRITEPAUSEEN (Bitfield-Mask: 0x01)        */
#define FRC_PAUSECTRL_RXINTERLEAVEWRITEPAUSEEN_Pos (2UL)            /*!< RXINTERLEAVEWRITEPAUSEEN (Bit 2)                      */
#define FRC_PAUSECTRL_RXINTERLEAVEWRITEPAUSEEN_Msk (0x4UL)          /*!< RXINTERLEAVEWRITEPAUSEEN (Bitfield-Mask: 0x01)        */
#define FRC_PAUSECTRL_INTERLEAVEREADPAUSEEN_Pos (3UL)               /*!< INTERLEAVEREADPAUSEEN (Bit 3)                         */
#define FRC_PAUSECTRL_INTERLEAVEREADPAUSEEN_Msk (0x8UL)             /*!< INTERLEAVEREADPAUSEEN (Bitfield-Mask: 0x01)           */
#define FRC_PAUSECTRL_TXSUBFRAMEPAUSEEN_Pos (4UL)                   /*!< TXSUBFRAMEPAUSEEN (Bit 4)                             */
#define FRC_PAUSECTRL_TXSUBFRAMEPAUSEEN_Msk (0x10UL)                /*!< TXSUBFRAMEPAUSEEN (Bitfield-Mask: 0x01)               */
#define FRC_PAUSECTRL_CONVPAUSECNT_Pos    (5UL)                     /*!< CONVPAUSECNT (Bit 5)                                  */
#define FRC_PAUSECTRL_CONVPAUSECNT_Msk    (0x7e0UL)                 /*!< CONVPAUSECNT (Bitfield-Mask: 0x3f)                    */
#define FRC_PAUSECTRL_INTERLEAVEWRITEPAUSECNT_Pos (11UL)            /*!< INTERLEAVEWRITEPAUSECNT (Bit 11)                      */
#define FRC_PAUSECTRL_INTERLEAVEWRITEPAUSECNT_Msk (0xf800UL)        /*!< INTERLEAVEWRITEPAUSECNT (Bitfield-Mask: 0x1f)         */
#define FRC_PAUSECTRL_INTERLEAVEREADPAUSECNT_Pos (16UL)             /*!< INTERLEAVEREADPAUSECNT (Bit 16)                       */
#define FRC_PAUSECTRL_INTERLEAVEREADPAUSECNT_Msk (0x1f0000UL)       /*!< INTERLEAVEREADPAUSECNT (Bitfield-Mask: 0x1f)          */
/* ==========================================================  IF  =========================================================== */
#define FRC_IF_TXDONE_Pos                 (0UL)                     /*!< TXDONE (Bit 0)                                        */
#define FRC_IF_TXDONE_Msk                 (0x1UL)                   /*!< TXDONE (Bitfield-Mask: 0x01)                          */
#define FRC_IF_TXAFTERFRAMEDONE_Pos       (1UL)                     /*!< TXAFTERFRAMEDONE (Bit 1)                              */
#define FRC_IF_TXAFTERFRAMEDONE_Msk       (0x2UL)                   /*!< TXAFTERFRAMEDONE (Bitfield-Mask: 0x01)                */
#define FRC_IF_TXABORTED_Pos              (2UL)                     /*!< TXABORTED (Bit 2)                                     */
#define FRC_IF_TXABORTED_Msk              (0x4UL)                   /*!< TXABORTED (Bitfield-Mask: 0x01)                       */
#define FRC_IF_TXUF_Pos                   (3UL)                     /*!< TXUF (Bit 3)                                          */
#define FRC_IF_TXUF_Msk                   (0x8UL)                   /*!< TXUF (Bitfield-Mask: 0x01)                            */
#define FRC_IF_RXDONE_Pos                 (4UL)                     /*!< RXDONE (Bit 4)                                        */
#define FRC_IF_RXDONE_Msk                 (0x10UL)                  /*!< RXDONE (Bitfield-Mask: 0x01)                          */
#define FRC_IF_RXABORTED_Pos              (5UL)                     /*!< RXABORTED (Bit 5)                                     */
#define FRC_IF_RXABORTED_Msk              (0x20UL)                  /*!< RXABORTED (Bitfield-Mask: 0x01)                       */
#define FRC_IF_FRAMEERROR_Pos             (6UL)                     /*!< FRAMEERROR (Bit 6)                                    */
#define FRC_IF_FRAMEERROR_Msk             (0x40UL)                  /*!< FRAMEERROR (Bitfield-Mask: 0x01)                      */
#define FRC_IF_BLOCKERROR_Pos             (7UL)                     /*!< BLOCKERROR (Bit 7)                                    */
#define FRC_IF_BLOCKERROR_Msk             (0x80UL)                  /*!< BLOCKERROR (Bitfield-Mask: 0x01)                      */
#define FRC_IF_RXOF_Pos                   (8UL)                     /*!< RXOF (Bit 8)                                          */
#define FRC_IF_RXOF_Msk                   (0x100UL)                 /*!< RXOF (Bitfield-Mask: 0x01)                            */
#define FRC_IF_WCNTCMP0_Pos               (9UL)                     /*!< WCNTCMP0 (Bit 9)                                      */
#define FRC_IF_WCNTCMP0_Msk               (0x200UL)                 /*!< WCNTCMP0 (Bitfield-Mask: 0x01)                        */
#define FRC_IF_WCNTCMP1_Pos               (10UL)                    /*!< WCNTCMP1 (Bit 10)                                     */
#define FRC_IF_WCNTCMP1_Msk               (0x400UL)                 /*!< WCNTCMP1 (Bitfield-Mask: 0x01)                        */
#define FRC_IF_WCNTCMP2_Pos               (11UL)                    /*!< WCNTCMP2 (Bit 11)                                     */
#define FRC_IF_WCNTCMP2_Msk               (0x800UL)                 /*!< WCNTCMP2 (Bitfield-Mask: 0x01)                        */
#define FRC_IF_ADDRERROR_Pos              (12UL)                    /*!< ADDRERROR (Bit 12)                                    */
#define FRC_IF_ADDRERROR_Msk              (0x1000UL)                /*!< ADDRERROR (Bitfield-Mask: 0x01)                       */
#define FRC_IF_BUSERROR_Pos               (13UL)                    /*!< BUSERROR (Bit 13)                                     */
#define FRC_IF_BUSERROR_Msk               (0x2000UL)                /*!< BUSERROR (Bitfield-Mask: 0x01)                        */
#define FRC_IF_RXRAWEVENT_Pos             (14UL)                    /*!< RXRAWEVENT (Bit 14)                                   */
#define FRC_IF_RXRAWEVENT_Msk             (0x4000UL)                /*!< RXRAWEVENT (Bitfield-Mask: 0x01)                      */
#define FRC_IF_TXRAWEVENT_Pos             (15UL)                    /*!< TXRAWEVENT (Bit 15)                                   */
#define FRC_IF_TXRAWEVENT_Msk             (0x8000UL)                /*!< TXRAWEVENT (Bitfield-Mask: 0x01)                      */
#define FRC_IF_SNIFFOF_Pos                (16UL)                    /*!< SNIFFOF (Bit 16)                                      */
#define FRC_IF_SNIFFOF_Msk                (0x10000UL)               /*!< SNIFFOF (Bitfield-Mask: 0x01)                         */
#define FRC_IF_LVDSWILLERROR_Pos          (17UL)                    /*!< LVDSWILLERROR (Bit 17)                                */
#define FRC_IF_LVDSWILLERROR_Msk          (0x20000UL)               /*!< LVDSWILLERROR (Bitfield-Mask: 0x01)                   */
#define FRC_IF_LVDSERROR_Pos              (18UL)                    /*!< LVDSERROR (Bit 18)                                    */
#define FRC_IF_LVDSERROR_Msk              (0x40000UL)               /*!< LVDSERROR (Bitfield-Mask: 0x01)                       */
#define FRC_IF_FRAMEDETPAUSED_Pos         (24UL)                    /*!< FRAMEDETPAUSED (Bit 24)                               */
#define FRC_IF_FRAMEDETPAUSED_Msk         (0x1000000UL)             /*!< FRAMEDETPAUSED (Bitfield-Mask: 0x01)                  */
#define FRC_IF_INTERLEAVEWRITEPAUSED_Pos  (25UL)                    /*!< INTERLEAVEWRITEPAUSED (Bit 25)                        */
#define FRC_IF_INTERLEAVEWRITEPAUSED_Msk  (0x2000000UL)             /*!< INTERLEAVEWRITEPAUSED (Bitfield-Mask: 0x01)           */
#define FRC_IF_INTERLEAVEREADPAUSED_Pos   (26UL)                    /*!< INTERLEAVEREADPAUSED (Bit 26)                         */
#define FRC_IF_INTERLEAVEREADPAUSED_Msk   (0x4000000UL)             /*!< INTERLEAVEREADPAUSED (Bitfield-Mask: 0x01)            */
#define FRC_IF_TXSUBFRAMEPAUSED_Pos       (27UL)                    /*!< TXSUBFRAMEPAUSED (Bit 27)                             */
#define FRC_IF_TXSUBFRAMEPAUSED_Msk       (0x8000000UL)             /*!< TXSUBFRAMEPAUSED (Bitfield-Mask: 0x01)                */
#define FRC_IF_CONVPAUSED_Pos             (28UL)                    /*!< CONVPAUSED (Bit 28)                                   */
#define FRC_IF_CONVPAUSED_Msk             (0x10000000UL)            /*!< CONVPAUSED (Bitfield-Mask: 0x01)                      */
#define FRC_IF_RXWORD_Pos                 (29UL)                    /*!< RXWORD (Bit 29)                                       */
#define FRC_IF_RXWORD_Msk                 (0x20000000UL)            /*!< RXWORD (Bitfield-Mask: 0x01)                          */
#define FRC_IF_TXWORD_Pos                 (30UL)                    /*!< TXWORD (Bit 30)                                       */
#define FRC_IF_TXWORD_Msk                 (0x40000000UL)            /*!< TXWORD (Bitfield-Mask: 0x01)                          */
/* ==========================================================  IFS  ========================================================== */
#define FRC_IFS_TXDONE_Pos                (0UL)                     /*!< TXDONE (Bit 0)                                        */
#define FRC_IFS_TXDONE_Msk                (0x1UL)                   /*!< TXDONE (Bitfield-Mask: 0x01)                          */
#define FRC_IFS_TXAFTERFRAMEDONE_Pos      (1UL)                     /*!< TXAFTERFRAMEDONE (Bit 1)                              */
#define FRC_IFS_TXAFTERFRAMEDONE_Msk      (0x2UL)                   /*!< TXAFTERFRAMEDONE (Bitfield-Mask: 0x01)                */
#define FRC_IFS_TXABORTED_Pos             (2UL)                     /*!< TXABORTED (Bit 2)                                     */
#define FRC_IFS_TXABORTED_Msk             (0x4UL)                   /*!< TXABORTED (Bitfield-Mask: 0x01)                       */
#define FRC_IFS_TXUF_Pos                  (3UL)                     /*!< TXUF (Bit 3)                                          */
#define FRC_IFS_TXUF_Msk                  (0x8UL)                   /*!< TXUF (Bitfield-Mask: 0x01)                            */
#define FRC_IFS_RXDONE_Pos                (4UL)                     /*!< RXDONE (Bit 4)                                        */
#define FRC_IFS_RXDONE_Msk                (0x10UL)                  /*!< RXDONE (Bitfield-Mask: 0x01)                          */
#define FRC_IFS_RXABORTED_Pos             (5UL)                     /*!< RXABORTED (Bit 5)                                     */
#define FRC_IFS_RXABORTED_Msk             (0x20UL)                  /*!< RXABORTED (Bitfield-Mask: 0x01)                       */
#define FRC_IFS_FRAMEERROR_Pos            (6UL)                     /*!< FRAMEERROR (Bit 6)                                    */
#define FRC_IFS_FRAMEERROR_Msk            (0x40UL)                  /*!< FRAMEERROR (Bitfield-Mask: 0x01)                      */
#define FRC_IFS_BLOCKERROR_Pos            (7UL)                     /*!< BLOCKERROR (Bit 7)                                    */
#define FRC_IFS_BLOCKERROR_Msk            (0x80UL)                  /*!< BLOCKERROR (Bitfield-Mask: 0x01)                      */
#define FRC_IFS_RXOF_Pos                  (8UL)                     /*!< RXOF (Bit 8)                                          */
#define FRC_IFS_RXOF_Msk                  (0x100UL)                 /*!< RXOF (Bitfield-Mask: 0x01)                            */
#define FRC_IFS_WCNTCMP0_Pos              (9UL)                     /*!< WCNTCMP0 (Bit 9)                                      */
#define FRC_IFS_WCNTCMP0_Msk              (0x200UL)                 /*!< WCNTCMP0 (Bitfield-Mask: 0x01)                        */
#define FRC_IFS_WCNTCMP1_Pos              (10UL)                    /*!< WCNTCMP1 (Bit 10)                                     */
#define FRC_IFS_WCNTCMP1_Msk              (0x400UL)                 /*!< WCNTCMP1 (Bitfield-Mask: 0x01)                        */
#define FRC_IFS_WCNTCMP2_Pos              (11UL)                    /*!< WCNTCMP2 (Bit 11)                                     */
#define FRC_IFS_WCNTCMP2_Msk              (0x800UL)                 /*!< WCNTCMP2 (Bitfield-Mask: 0x01)                        */
#define FRC_IFS_ADDRERROR_Pos             (12UL)                    /*!< ADDRERROR (Bit 12)                                    */
#define FRC_IFS_ADDRERROR_Msk             (0x1000UL)                /*!< ADDRERROR (Bitfield-Mask: 0x01)                       */
#define FRC_IFS_BUSERROR_Pos              (13UL)                    /*!< BUSERROR (Bit 13)                                     */
#define FRC_IFS_BUSERROR_Msk              (0x2000UL)                /*!< BUSERROR (Bitfield-Mask: 0x01)                        */
#define FRC_IFS_RXRAWEVENT_Pos            (14UL)                    /*!< RXRAWEVENT (Bit 14)                                   */
#define FRC_IFS_RXRAWEVENT_Msk            (0x4000UL)                /*!< RXRAWEVENT (Bitfield-Mask: 0x01)                      */
#define FRC_IFS_TXRAWEVENT_Pos            (15UL)                    /*!< TXRAWEVENT (Bit 15)                                   */
#define FRC_IFS_TXRAWEVENT_Msk            (0x8000UL)                /*!< TXRAWEVENT (Bitfield-Mask: 0x01)                      */
#define FRC_IFS_SNIFFOF_Pos               (16UL)                    /*!< SNIFFOF (Bit 16)                                      */
#define FRC_IFS_SNIFFOF_Msk               (0x10000UL)               /*!< SNIFFOF (Bitfield-Mask: 0x01)                         */
#define FRC_IFS_LVDSWILLERROR_Pos         (17UL)                    /*!< LVDSWILLERROR (Bit 17)                                */
#define FRC_IFS_LVDSWILLERROR_Msk         (0x20000UL)               /*!< LVDSWILLERROR (Bitfield-Mask: 0x01)                   */
#define FRC_IFS_LVDSERROR_Pos             (18UL)                    /*!< LVDSERROR (Bit 18)                                    */
#define FRC_IFS_LVDSERROR_Msk             (0x40000UL)               /*!< LVDSERROR (Bitfield-Mask: 0x01)                       */
/* ==========================================================  IFC  ========================================================== */
#define FRC_IFC_TXDONE_Pos                (0UL)                     /*!< TXDONE (Bit 0)                                        */
#define FRC_IFC_TXDONE_Msk                (0x1UL)                   /*!< TXDONE (Bitfield-Mask: 0x01)                          */
#define FRC_IFC_TXAFTERFRAMEDONE_Pos      (1UL)                     /*!< TXAFTERFRAMEDONE (Bit 1)                              */
#define FRC_IFC_TXAFTERFRAMEDONE_Msk      (0x2UL)                   /*!< TXAFTERFRAMEDONE (Bitfield-Mask: 0x01)                */
#define FRC_IFC_TXABORTED_Pos             (2UL)                     /*!< TXABORTED (Bit 2)                                     */
#define FRC_IFC_TXABORTED_Msk             (0x4UL)                   /*!< TXABORTED (Bitfield-Mask: 0x01)                       */
#define FRC_IFC_TXUF_Pos                  (3UL)                     /*!< TXUF (Bit 3)                                          */
#define FRC_IFC_TXUF_Msk                  (0x8UL)                   /*!< TXUF (Bitfield-Mask: 0x01)                            */
#define FRC_IFC_RXDONE_Pos                (4UL)                     /*!< RXDONE (Bit 4)                                        */
#define FRC_IFC_RXDONE_Msk                (0x10UL)                  /*!< RXDONE (Bitfield-Mask: 0x01)                          */
#define FRC_IFC_RXABORTED_Pos             (5UL)                     /*!< RXABORTED (Bit 5)                                     */
#define FRC_IFC_RXABORTED_Msk             (0x20UL)                  /*!< RXABORTED (Bitfield-Mask: 0x01)                       */
#define FRC_IFC_FRAMEERROR_Pos            (6UL)                     /*!< FRAMEERROR (Bit 6)                                    */
#define FRC_IFC_FRAMEERROR_Msk            (0x40UL)                  /*!< FRAMEERROR (Bitfield-Mask: 0x01)                      */
#define FRC_IFC_BLOCKERROR_Pos            (7UL)                     /*!< BLOCKERROR (Bit 7)                                    */
#define FRC_IFC_BLOCKERROR_Msk            (0x80UL)                  /*!< BLOCKERROR (Bitfield-Mask: 0x01)                      */
#define FRC_IFC_RXOF_Pos                  (8UL)                     /*!< RXOF (Bit 8)                                          */
#define FRC_IFC_RXOF_Msk                  (0x100UL)                 /*!< RXOF (Bitfield-Mask: 0x01)                            */
#define FRC_IFC_WCNTCMP0_Pos              (9UL)                     /*!< WCNTCMP0 (Bit 9)                                      */
#define FRC_IFC_WCNTCMP0_Msk              (0x200UL)                 /*!< WCNTCMP0 (Bitfield-Mask: 0x01)                        */
#define FRC_IFC_WCNTCMP1_Pos              (10UL)                    /*!< WCNTCMP1 (Bit 10)                                     */
#define FRC_IFC_WCNTCMP1_Msk              (0x400UL)                 /*!< WCNTCMP1 (Bitfield-Mask: 0x01)                        */
#define FRC_IFC_WCNTCMP2_Pos              (11UL)                    /*!< WCNTCMP2 (Bit 11)                                     */
#define FRC_IFC_WCNTCMP2_Msk              (0x800UL)                 /*!< WCNTCMP2 (Bitfield-Mask: 0x01)                        */
#define FRC_IFC_ADDRERROR_Pos             (12UL)                    /*!< ADDRERROR (Bit 12)                                    */
#define FRC_IFC_ADDRERROR_Msk             (0x1000UL)                /*!< ADDRERROR (Bitfield-Mask: 0x01)                       */
#define FRC_IFC_BUSERROR_Pos              (13UL)                    /*!< BUSERROR (Bit 13)                                     */
#define FRC_IFC_BUSERROR_Msk              (0x2000UL)                /*!< BUSERROR (Bitfield-Mask: 0x01)                        */
#define FRC_IFC_RXRAWEVENT_Pos            (14UL)                    /*!< RXRAWEVENT (Bit 14)                                   */
#define FRC_IFC_RXRAWEVENT_Msk            (0x4000UL)                /*!< RXRAWEVENT (Bitfield-Mask: 0x01)                      */
#define FRC_IFC_TXRAWEVENT_Pos            (15UL)                    /*!< TXRAWEVENT (Bit 15)                                   */
#define FRC_IFC_TXRAWEVENT_Msk            (0x8000UL)                /*!< TXRAWEVENT (Bitfield-Mask: 0x01)                      */
#define FRC_IFC_SNIFFOF_Pos               (16UL)                    /*!< SNIFFOF (Bit 16)                                      */
#define FRC_IFC_SNIFFOF_Msk               (0x10000UL)               /*!< SNIFFOF (Bitfield-Mask: 0x01)                         */
#define FRC_IFC_LVDSWILLERROR_Pos         (17UL)                    /*!< LVDSWILLERROR (Bit 17)                                */
#define FRC_IFC_LVDSWILLERROR_Msk         (0x20000UL)               /*!< LVDSWILLERROR (Bitfield-Mask: 0x01)                   */
#define FRC_IFC_LVDSERROR_Pos             (18UL)                    /*!< LVDSERROR (Bit 18)                                    */
#define FRC_IFC_LVDSERROR_Msk             (0x40000UL)               /*!< LVDSERROR (Bitfield-Mask: 0x01)                       */
/* ==========================================================  IEN  ========================================================== */
#define FRC_IEN_TXDONE_Pos                (0UL)                     /*!< TXDONE (Bit 0)                                        */
#define FRC_IEN_TXDONE_Msk                (0x1UL)                   /*!< TXDONE (Bitfield-Mask: 0x01)                          */
#define FRC_IEN_TXAFTERFRAMEDONE_Pos      (1UL)                     /*!< TXAFTERFRAMEDONE (Bit 1)                              */
#define FRC_IEN_TXAFTERFRAMEDONE_Msk      (0x2UL)                   /*!< TXAFTERFRAMEDONE (Bitfield-Mask: 0x01)                */
#define FRC_IEN_TXABORTED_Pos             (2UL)                     /*!< TXABORTED (Bit 2)                                     */
#define FRC_IEN_TXABORTED_Msk             (0x4UL)                   /*!< TXABORTED (Bitfield-Mask: 0x01)                       */
#define FRC_IEN_TXUF_Pos                  (3UL)                     /*!< TXUF (Bit 3)                                          */
#define FRC_IEN_TXUF_Msk                  (0x8UL)                   /*!< TXUF (Bitfield-Mask: 0x01)                            */
#define FRC_IEN_RXDONE_Pos                (4UL)                     /*!< RXDONE (Bit 4)                                        */
#define FRC_IEN_RXDONE_Msk                (0x10UL)                  /*!< RXDONE (Bitfield-Mask: 0x01)                          */
#define FRC_IEN_RXABORTED_Pos             (5UL)                     /*!< RXABORTED (Bit 5)                                     */
#define FRC_IEN_RXABORTED_Msk             (0x20UL)                  /*!< RXABORTED (Bitfield-Mask: 0x01)                       */
#define FRC_IEN_FRAMEERROR_Pos            (6UL)                     /*!< FRAMEERROR (Bit 6)                                    */
#define FRC_IEN_FRAMEERROR_Msk            (0x40UL)                  /*!< FRAMEERROR (Bitfield-Mask: 0x01)                      */
#define FRC_IEN_BLOCKERROR_Pos            (7UL)                     /*!< BLOCKERROR (Bit 7)                                    */
#define FRC_IEN_BLOCKERROR_Msk            (0x80UL)                  /*!< BLOCKERROR (Bitfield-Mask: 0x01)                      */
#define FRC_IEN_RXOF_Pos                  (8UL)                     /*!< RXOF (Bit 8)                                          */
#define FRC_IEN_RXOF_Msk                  (0x100UL)                 /*!< RXOF (Bitfield-Mask: 0x01)                            */
#define FRC_IEN_WCNTCMP0_Pos              (9UL)                     /*!< WCNTCMP0 (Bit 9)                                      */
#define FRC_IEN_WCNTCMP0_Msk              (0x200UL)                 /*!< WCNTCMP0 (Bitfield-Mask: 0x01)                        */
#define FRC_IEN_WCNTCMP1_Pos              (10UL)                    /*!< WCNTCMP1 (Bit 10)                                     */
#define FRC_IEN_WCNTCMP1_Msk              (0x400UL)                 /*!< WCNTCMP1 (Bitfield-Mask: 0x01)                        */
#define FRC_IEN_WCNTCMP2_Pos              (11UL)                    /*!< WCNTCMP2 (Bit 11)                                     */
#define FRC_IEN_WCNTCMP2_Msk              (0x800UL)                 /*!< WCNTCMP2 (Bitfield-Mask: 0x01)                        */
#define FRC_IEN_ADDRERROR_Pos             (12UL)                    /*!< ADDRERROR (Bit 12)                                    */
#define FRC_IEN_ADDRERROR_Msk             (0x1000UL)                /*!< ADDRERROR (Bitfield-Mask: 0x01)                       */
#define FRC_IEN_BUSERROR_Pos              (13UL)                    /*!< BUSERROR (Bit 13)                                     */
#define FRC_IEN_BUSERROR_Msk              (0x2000UL)                /*!< BUSERROR (Bitfield-Mask: 0x01)                        */
#define FRC_IEN_RXRAWEVENT_Pos            (14UL)                    /*!< RXRAWEVENT (Bit 14)                                   */
#define FRC_IEN_RXRAWEVENT_Msk            (0x4000UL)                /*!< RXRAWEVENT (Bitfield-Mask: 0x01)                      */
#define FRC_IEN_TXRAWEVENT_Pos            (15UL)                    /*!< TXRAWEVENT (Bit 15)                                   */
#define FRC_IEN_TXRAWEVENT_Msk            (0x8000UL)                /*!< TXRAWEVENT (Bitfield-Mask: 0x01)                      */
#define FRC_IEN_SNIFFOF_Pos               (16UL)                    /*!< SNIFFOF (Bit 16)                                      */
#define FRC_IEN_SNIFFOF_Msk               (0x10000UL)               /*!< SNIFFOF (Bitfield-Mask: 0x01)                         */
#define FRC_IEN_LVDSWILLERROR_Pos         (17UL)                    /*!< LVDSWILLERROR (Bit 17)                                */
#define FRC_IEN_LVDSWILLERROR_Msk         (0x20000UL)               /*!< LVDSWILLERROR (Bitfield-Mask: 0x01)                   */
#define FRC_IEN_LVDSERROR_Pos             (18UL)                    /*!< LVDSERROR (Bit 18)                                    */
#define FRC_IEN_LVDSERROR_Msk             (0x40000UL)               /*!< LVDSERROR (Bitfield-Mask: 0x01)                       */
#define FRC_IEN_FRAMEDETPAUSED_Pos        (24UL)                    /*!< FRAMEDETPAUSED (Bit 24)                               */
#define FRC_IEN_FRAMEDETPAUSED_Msk        (0x1000000UL)             /*!< FRAMEDETPAUSED (Bitfield-Mask: 0x01)                  */
#define FRC_IEN_INTERLEAVEWRITEPAUSED_Pos (25UL)                    /*!< INTERLEAVEWRITEPAUSED (Bit 25)                        */
#define FRC_IEN_INTERLEAVEWRITEPAUSED_Msk (0x2000000UL)             /*!< INTERLEAVEWRITEPAUSED (Bitfield-Mask: 0x01)           */
#define FRC_IEN_INTERLEAVEREADPAUSED_Pos  (26UL)                    /*!< INTERLEAVEREADPAUSED (Bit 26)                         */
#define FRC_IEN_INTERLEAVEREADPAUSED_Msk  (0x4000000UL)             /*!< INTERLEAVEREADPAUSED (Bitfield-Mask: 0x01)            */
#define FRC_IEN_TXSUBFRAMEPAUSED_Pos      (27UL)                    /*!< TXSUBFRAMEPAUSED (Bit 27)                             */
#define FRC_IEN_TXSUBFRAMEPAUSED_Msk      (0x8000000UL)             /*!< TXSUBFRAMEPAUSED (Bitfield-Mask: 0x01)                */
#define FRC_IEN_CONVPAUSED_Pos            (28UL)                    /*!< CONVPAUSED (Bit 28)                                   */
#define FRC_IEN_CONVPAUSED_Msk            (0x10000000UL)            /*!< CONVPAUSED (Bitfield-Mask: 0x01)                      */
#define FRC_IEN_RXWORD_Pos                (29UL)                    /*!< RXWORD (Bit 29)                                       */
#define FRC_IEN_RXWORD_Msk                (0x20000000UL)            /*!< RXWORD (Bitfield-Mask: 0x01)                          */
#define FRC_IEN_TXWORD_Pos                (30UL)                    /*!< TXWORD (Bit 30)                                       */
#define FRC_IEN_TXWORD_Msk                (0x40000000UL)            /*!< TXWORD (Bitfield-Mask: 0x01)                          */
/* ======================================================  BUFFERMODE  ======================================================= */
#define FRC_BUFFERMODE_TXBUFFERMODE_Pos   (0UL)                     /*!< TXBUFFERMODE (Bit 0)                                  */
#define FRC_BUFFERMODE_TXBUFFERMODE_Msk   (0x1UL)                   /*!< TXBUFFERMODE (Bitfield-Mask: 0x01)                    */
#define FRC_BUFFERMODE_RXBUFFERMODE_Pos   (1UL)                     /*!< RXBUFFERMODE (Bit 1)                                  */
#define FRC_BUFFERMODE_RXBUFFERMODE_Msk   (0x6UL)                   /*!< RXBUFFERMODE (Bitfield-Mask: 0x03)                    */
/* =======================================================  ROUTEPEN  ======================================================== */
#define FRC_ROUTEPEN_DOUTPEN_Pos          (0UL)                     /*!< DOUTPEN (Bit 0)                                       */
#define FRC_ROUTEPEN_DOUTPEN_Msk          (0x1UL)                   /*!< DOUTPEN (Bitfield-Mask: 0x01)                         */
#define FRC_ROUTEPEN_DCLKPEN_Pos          (1UL)                     /*!< DCLKPEN (Bit 1)                                       */
#define FRC_ROUTEPEN_DCLKPEN_Msk          (0x2UL)                   /*!< DCLKPEN (Bitfield-Mask: 0x01)                         */
#define FRC_ROUTEPEN_DFRAMEPEN_Pos        (2UL)                     /*!< DFRAMEPEN (Bit 2)                                     */
#define FRC_ROUTEPEN_DFRAMEPEN_Msk        (0x4UL)                   /*!< DFRAMEPEN (Bitfield-Mask: 0x01)                       */
/* =======================================================  ROUTELOC0  ======================================================= */
#define FRC_ROUTELOC0_DOUTLOC_Pos         (0UL)                     /*!< DOUTLOC (Bit 0)                                       */
#define FRC_ROUTELOC0_DOUTLOC_Msk         (0x3fUL)                  /*!< DOUTLOC (Bitfield-Mask: 0x3f)                         */
#define FRC_ROUTELOC0_DCLKLOC_Pos         (8UL)                     /*!< DCLKLOC (Bit 8)                                       */
#define FRC_ROUTELOC0_DCLKLOC_Msk         (0x3f00UL)                /*!< DCLKLOC (Bitfield-Mask: 0x3f)                         */
#define FRC_ROUTELOC0_DFRAMELOC_Pos       (16UL)                    /*!< DFRAMELOC (Bit 16)                                    */
#define FRC_ROUTELOC0_DFRAMELOC_Msk       (0x3f0000UL)              /*!< DFRAMELOC (Bitfield-Mask: 0x3f)                       */
/* =======================================================  SNIFFCTRL  ======================================================= */
#define FRC_SNIFFCTRL_SNIFFMODE_Pos       (0UL)                     /*!< SNIFFMODE (Bit 0)                                     */
#define FRC_SNIFFCTRL_SNIFFMODE_Msk       (0x3UL)                   /*!< SNIFFMODE (Bitfield-Mask: 0x03)                       */
#define FRC_SNIFFCTRL_SNIFFBITS_Pos       (2UL)                     /*!< SNIFFBITS (Bit 2)                                     */
#define FRC_SNIFFCTRL_SNIFFBITS_Msk       (0x4UL)                   /*!< SNIFFBITS (Bitfield-Mask: 0x01)                       */
#define FRC_SNIFFCTRL_SNIFFRXDATA_Pos     (3UL)                     /*!< SNIFFRXDATA (Bit 3)                                   */
#define FRC_SNIFFCTRL_SNIFFRXDATA_Msk     (0x8UL)                   /*!< SNIFFRXDATA (Bitfield-Mask: 0x01)                     */
#define FRC_SNIFFCTRL_SNIFFTXDATA_Pos     (4UL)                     /*!< SNIFFTXDATA (Bit 4)                                   */
#define FRC_SNIFFCTRL_SNIFFTXDATA_Msk     (0x10UL)                  /*!< SNIFFTXDATA (Bitfield-Mask: 0x01)                     */
#define FRC_SNIFFCTRL_SNIFFRSSI_Pos       (5UL)                     /*!< SNIFFRSSI (Bit 5)                                     */
#define FRC_SNIFFCTRL_SNIFFRSSI_Msk       (0x20UL)                  /*!< SNIFFRSSI (Bitfield-Mask: 0x01)                       */
#define FRC_SNIFFCTRL_SNIFFSTATE_Pos      (6UL)                     /*!< SNIFFSTATE (Bit 6)                                    */
#define FRC_SNIFFCTRL_SNIFFSTATE_Msk      (0x40UL)                  /*!< SNIFFSTATE (Bitfield-Mask: 0x01)                      */
#define FRC_SNIFFCTRL_SNIFFAUXDATA_Pos    (7UL)                     /*!< SNIFFAUXDATA (Bit 7)                                  */
#define FRC_SNIFFCTRL_SNIFFAUXDATA_Msk    (0x80UL)                  /*!< SNIFFAUXDATA (Bitfield-Mask: 0x01)                    */
#define FRC_SNIFFCTRL_SNIFFBR_Pos         (8UL)                     /*!< SNIFFBR (Bit 8)                                       */
#define FRC_SNIFFCTRL_SNIFFBR_Msk         (0xff00UL)                /*!< SNIFFBR (Bitfield-Mask: 0xff)                         */
#define FRC_SNIFFCTRL_SNIFFSLEEPCTRL_Pos  (16UL)                    /*!< SNIFFSLEEPCTRL (Bit 16)                               */
#define FRC_SNIFFCTRL_SNIFFSLEEPCTRL_Msk  (0x10000UL)               /*!< SNIFFSLEEPCTRL (Bitfield-Mask: 0x01)                  */
/* ========================================================  AUXDATA  ======================================================== */
#define FRC_AUXDATA_AUXDATA_Pos           (0UL)                     /*!< AUXDATA (Bit 0)                                       */
#define FRC_AUXDATA_AUXDATA_Msk           (0x1ffUL)                 /*!< AUXDATA (Bitfield-Mask: 0x1ff)                        */
/* ========================================================  RAWCTRL  ======================================================== */
#define FRC_RAWCTRL_TXRAWMODE_Pos         (0UL)                     /*!< TXRAWMODE (Bit 0)                                     */
#define FRC_RAWCTRL_TXRAWMODE_Msk         (0x3UL)                   /*!< TXRAWMODE (Bitfield-Mask: 0x03)                       */
#define FRC_RAWCTRL_RXRAWMODE_Pos         (2UL)                     /*!< RXRAWMODE (Bit 2)                                     */
#define FRC_RAWCTRL_RXRAWMODE_Msk         (0x1cUL)                  /*!< RXRAWMODE (Bitfield-Mask: 0x07)                       */
#define FRC_RAWCTRL_RXRAWRANDOM_Pos       (5UL)                     /*!< RXRAWRANDOM (Bit 5)                                   */
#define FRC_RAWCTRL_RXRAWRANDOM_Msk       (0x20UL)                  /*!< RXRAWRANDOM (Bitfield-Mask: 0x01)                     */
#define FRC_RAWCTRL_RXRAWTRIGGER_Pos      (7UL)                     /*!< RXRAWTRIGGER (Bit 7)                                  */
#define FRC_RAWCTRL_RXRAWTRIGGER_Msk      (0x80UL)                  /*!< RXRAWTRIGGER (Bitfield-Mask: 0x01)                    */
#define FRC_RAWCTRL_RXRAWPRSSEL_Pos       (8UL)                     /*!< RXRAWPRSSEL (Bit 8)                                   */
#define FRC_RAWCTRL_RXRAWPRSSEL_Msk       (0xf00UL)                 /*!< RXRAWPRSSEL (Bitfield-Mask: 0x0f)                     */
/* =======================================================  RXRAWDATA  ======================================================= */
#define FRC_RXRAWDATA_RXRAWDATA_Pos       (0UL)                     /*!< RXRAWDATA (Bit 0)                                     */
#define FRC_RXRAWDATA_RXRAWDATA_Msk       (0xffffffffUL)            /*!< RXRAWDATA (Bitfield-Mask: 0xffffffff)                 */
/* =======================================================  PAUSEDATA  ======================================================= */
#define FRC_PAUSEDATA_PAUSEDATA_Pos       (0UL)                     /*!< PAUSEDATA (Bit 0)                                     */
#define FRC_PAUSEDATA_PAUSEDATA_Msk       (0x3fUL)                  /*!< PAUSEDATA (Bitfield-Mask: 0x3f)                       */
/* ====================================================  LIKELYCONVSTATE  ==================================================== */
#define FRC_LIKELYCONVSTATE_LIKELYCONVSTATE_Pos (0UL)               /*!< LIKELYCONVSTATE (Bit 0)                               */
#define FRC_LIKELYCONVSTATE_LIKELYCONVSTATE_Msk (0x3fUL)            /*!< LIKELYCONVSTATE (Bitfield-Mask: 0x3f)                 */
/* ====================================================  INTELEMENTNEXT  ===================================================== */
#define FRC_INTELEMENTNEXT_INTELEMENTNEXT_Pos (0UL)                 /*!< INTELEMENTNEXT (Bit 0)                                */
#define FRC_INTELEMENTNEXT_INTELEMENTNEXT_Msk (0xffUL)              /*!< INTELEMENTNEXT (Bitfield-Mask: 0xff)                  */
/* =====================================================  INTWRITEPOINT  ===================================================== */
#define FRC_INTWRITEPOINT_INTWRITEPOINT_Pos (0UL)                   /*!< INTWRITEPOINT (Bit 0)                                 */
#define FRC_INTWRITEPOINT_INTWRITEPOINT_Msk (0x1fUL)                /*!< INTWRITEPOINT (Bitfield-Mask: 0x1f)                   */
/* =====================================================  INTREADPOINT  ====================================================== */
#define FRC_INTREADPOINT_INTREADPOINT_Pos (0UL)                     /*!< INTREADPOINT (Bit 0)                                  */
#define FRC_INTREADPOINT_INTREADPOINT_Msk (0x1fUL)                  /*!< INTREADPOINT (Bitfield-Mask: 0x1f)                    */
/* =========================================================  FCD0  ========================================================== */
#define FRC_FCD0_WORDS_Pos                (0UL)                     /*!< WORDS (Bit 0)                                         */
#define FRC_FCD0_WORDS_Msk                (0xffUL)                  /*!< WORDS (Bitfield-Mask: 0xff)                           */
#define FRC_FCD0_BUFFER_Pos               (8UL)                     /*!< BUFFER (Bit 8)                                        */
#define FRC_FCD0_BUFFER_Msk               (0x300UL)                 /*!< BUFFER (Bitfield-Mask: 0x03)                          */
#define FRC_FCD0_INCLUDECRC_Pos           (10UL)                    /*!< INCLUDECRC (Bit 10)                                   */
#define FRC_FCD0_INCLUDECRC_Msk           (0x400UL)                 /*!< INCLUDECRC (Bitfield-Mask: 0x01)                      */
#define FRC_FCD0_CALCCRC_Pos              (11UL)                    /*!< CALCCRC (Bit 11)                                      */
#define FRC_FCD0_CALCCRC_Msk              (0x800UL)                 /*!< CALCCRC (Bitfield-Mask: 0x01)                         */
#define FRC_FCD0_SKIPCRC_Pos              (12UL)                    /*!< SKIPCRC (Bit 12)                                      */
#define FRC_FCD0_SKIPCRC_Msk              (0x3000UL)                /*!< SKIPCRC (Bitfield-Mask: 0x03)                         */
#define FRC_FCD0_SKIPWHITE_Pos            (14UL)                    /*!< SKIPWHITE (Bit 14)                                    */
#define FRC_FCD0_SKIPWHITE_Msk            (0x4000UL)                /*!< SKIPWHITE (Bitfield-Mask: 0x01)                       */
/* =========================================================  FCD1  ========================================================== */
#define FRC_FCD1_WORDS_Pos                (0UL)                     /*!< WORDS (Bit 0)                                         */
#define FRC_FCD1_WORDS_Msk                (0xffUL)                  /*!< WORDS (Bitfield-Mask: 0xff)                           */
#define FRC_FCD1_BUFFER_Pos               (8UL)                     /*!< BUFFER (Bit 8)                                        */
#define FRC_FCD1_BUFFER_Msk               (0x300UL)                 /*!< BUFFER (Bitfield-Mask: 0x03)                          */
#define FRC_FCD1_INCLUDECRC_Pos           (10UL)                    /*!< INCLUDECRC (Bit 10)                                   */
#define FRC_FCD1_INCLUDECRC_Msk           (0x400UL)                 /*!< INCLUDECRC (Bitfield-Mask: 0x01)                      */
#define FRC_FCD1_CALCCRC_Pos              (11UL)                    /*!< CALCCRC (Bit 11)                                      */
#define FRC_FCD1_CALCCRC_Msk              (0x800UL)                 /*!< CALCCRC (Bitfield-Mask: 0x01)                         */
#define FRC_FCD1_SKIPCRC_Pos              (12UL)                    /*!< SKIPCRC (Bit 12)                                      */
#define FRC_FCD1_SKIPCRC_Msk              (0x3000UL)                /*!< SKIPCRC (Bitfield-Mask: 0x03)                         */
#define FRC_FCD1_SKIPWHITE_Pos            (14UL)                    /*!< SKIPWHITE (Bit 14)                                    */
#define FRC_FCD1_SKIPWHITE_Msk            (0x4000UL)                /*!< SKIPWHITE (Bitfield-Mask: 0x01)                       */
/* =========================================================  FCD2  ========================================================== */
#define FRC_FCD2_WORDS_Pos                (0UL)                     /*!< WORDS (Bit 0)                                         */
#define FRC_FCD2_WORDS_Msk                (0xffUL)                  /*!< WORDS (Bitfield-Mask: 0xff)                           */
#define FRC_FCD2_BUFFER_Pos               (8UL)                     /*!< BUFFER (Bit 8)                                        */
#define FRC_FCD2_BUFFER_Msk               (0x300UL)                 /*!< BUFFER (Bitfield-Mask: 0x03)                          */
#define FRC_FCD2_INCLUDECRC_Pos           (10UL)                    /*!< INCLUDECRC (Bit 10)                                   */
#define FRC_FCD2_INCLUDECRC_Msk           (0x400UL)                 /*!< INCLUDECRC (Bitfield-Mask: 0x01)                      */
#define FRC_FCD2_CALCCRC_Pos              (11UL)                    /*!< CALCCRC (Bit 11)                                      */
#define FRC_FCD2_CALCCRC_Msk              (0x800UL)                 /*!< CALCCRC (Bitfield-Mask: 0x01)                         */
#define FRC_FCD2_SKIPCRC_Pos              (12UL)                    /*!< SKIPCRC (Bit 12)                                      */
#define FRC_FCD2_SKIPCRC_Msk              (0x3000UL)                /*!< SKIPCRC (Bitfield-Mask: 0x03)                         */
#define FRC_FCD2_SKIPWHITE_Pos            (14UL)                    /*!< SKIPWHITE (Bit 14)                                    */
#define FRC_FCD2_SKIPWHITE_Msk            (0x4000UL)                /*!< SKIPWHITE (Bitfield-Mask: 0x01)                       */
/* =========================================================  FCD3  ========================================================== */
#define FRC_FCD3_WORDS_Pos                (0UL)                     /*!< WORDS (Bit 0)                                         */
#define FRC_FCD3_WORDS_Msk                (0xffUL)                  /*!< WORDS (Bitfield-Mask: 0xff)                           */
#define FRC_FCD3_BUFFER_Pos               (8UL)                     /*!< BUFFER (Bit 8)                                        */
#define FRC_FCD3_BUFFER_Msk               (0x300UL)                 /*!< BUFFER (Bitfield-Mask: 0x03)                          */
#define FRC_FCD3_INCLUDECRC_Pos           (10UL)                    /*!< INCLUDECRC (Bit 10)                                   */
#define FRC_FCD3_INCLUDECRC_Msk           (0x400UL)                 /*!< INCLUDECRC (Bitfield-Mask: 0x01)                      */
#define FRC_FCD3_CALCCRC_Pos              (11UL)                    /*!< CALCCRC (Bit 11)                                      */
#define FRC_FCD3_CALCCRC_Msk              (0x800UL)                 /*!< CALCCRC (Bitfield-Mask: 0x01)                         */
#define FRC_FCD3_SKIPCRC_Pos              (12UL)                    /*!< SKIPCRC (Bit 12)                                      */
#define FRC_FCD3_SKIPCRC_Msk              (0x3000UL)                /*!< SKIPCRC (Bitfield-Mask: 0x03)                         */
#define FRC_FCD3_SKIPWHITE_Pos            (14UL)                    /*!< SKIPWHITE (Bit 14)                                    */
#define FRC_FCD3_SKIPWHITE_Msk            (0x4000UL)                /*!< SKIPWHITE (Bitfield-Mask: 0x01)                       */
/* ======================================================  INTELEMENT0  ====================================================== */
#define FRC_INTELEMENT0_INTELEMENT_Pos    (0UL)                     /*!< INTELEMENT (Bit 0)                                    */
#define FRC_INTELEMENT0_INTELEMENT_Msk    (0xffUL)                  /*!< INTELEMENT (Bitfield-Mask: 0xff)                      */
/* ======================================================  INTELEMENT1  ====================================================== */
#define FRC_INTELEMENT1_INDEXMINATTEN_Pos (0UL)                     /*!< INDEXMINATTEN (Bit 0)                                 */
#define FRC_INTELEMENT1_INDEXMINATTEN_Msk (0xffUL)                  /*!< INDEXMINATTEN (Bitfield-Mask: 0xff)                   */
/* ======================================================  INTELEMENT2  ====================================================== */
#define FRC_INTELEMENT2_INDEXMINATTEN_Pos (0UL)                     /*!< INDEXMINATTEN (Bit 0)                                 */
#define FRC_INTELEMENT2_INDEXMINATTEN_Msk (0xffUL)                  /*!< INDEXMINATTEN (Bitfield-Mask: 0xff)                   */
/* ======================================================  INTELEMENT3  ====================================================== */
#define FRC_INTELEMENT3_INDEXMINATTEN_Pos (0UL)                     /*!< INDEXMINATTEN (Bit 0)                                 */
#define FRC_INTELEMENT3_INDEXMINATTEN_Msk (0xffUL)                  /*!< INDEXMINATTEN (Bitfield-Mask: 0xff)                   */
/* ======================================================  INTELEMENT4  ====================================================== */
#define FRC_INTELEMENT4_INDEXMINATTEN_Pos (0UL)                     /*!< INDEXMINATTEN (Bit 0)                                 */
#define FRC_INTELEMENT4_INDEXMINATTEN_Msk (0xffUL)                  /*!< INDEXMINATTEN (Bitfield-Mask: 0xff)                   */
/* ======================================================  INTELEMENT5  ====================================================== */
#define FRC_INTELEMENT5_INDEXMINATTEN_Pos (0UL)                     /*!< INDEXMINATTEN (Bit 0)                                 */
#define FRC_INTELEMENT5_INDEXMINATTEN_Msk (0xffUL)                  /*!< INDEXMINATTEN (Bitfield-Mask: 0xff)                   */
/* ======================================================  INTELEMENT6  ====================================================== */
#define FRC_INTELEMENT6_INDEXMINATTEN_Pos (0UL)                     /*!< INDEXMINATTEN (Bit 0)                                 */
#define FRC_INTELEMENT6_INDEXMINATTEN_Msk (0xffUL)                  /*!< INDEXMINATTEN (Bitfield-Mask: 0xff)                   */
/* ======================================================  INTELEMENT7  ====================================================== */
#define FRC_INTELEMENT7_INDEXMINATTEN_Pos (0UL)                     /*!< INDEXMINATTEN (Bit 0)                                 */
#define FRC_INTELEMENT7_INDEXMINATTEN_Msk (0xffUL)                  /*!< INDEXMINATTEN (Bitfield-Mask: 0xff)                   */
/* ======================================================  INTELEMENT8  ====================================================== */
#define FRC_INTELEMENT8_INDEXMINATTEN_Pos (0UL)                     /*!< INDEXMINATTEN (Bit 0)                                 */
#define FRC_INTELEMENT8_INDEXMINATTEN_Msk (0xffUL)                  /*!< INDEXMINATTEN (Bitfield-Mask: 0xff)                   */
/* ======================================================  INTELEMENT9  ====================================================== */
#define FRC_INTELEMENT9_INDEXMINATTEN_Pos (0UL)                     /*!< INDEXMINATTEN (Bit 0)                                 */
#define FRC_INTELEMENT9_INDEXMINATTEN_Msk (0xffUL)                  /*!< INDEXMINATTEN (Bitfield-Mask: 0xff)                   */
/* =====================================================  INTELEMENT10  ====================================================== */
#define FRC_INTELEMENT10_INDEXMINATTEN_Pos (0UL)                    /*!< INDEXMINATTEN (Bit 0)                                 */
#define FRC_INTELEMENT10_INDEXMINATTEN_Msk (0xffUL)                 /*!< INDEXMINATTEN (Bitfield-Mask: 0xff)                   */
/* =====================================================  INTELEMENT11  ====================================================== */
#define FRC_INTELEMENT11_INDEXMINATTEN_Pos (0UL)                    /*!< INDEXMINATTEN (Bit 0)                                 */
#define FRC_INTELEMENT11_INDEXMINATTEN_Msk (0xffUL)                 /*!< INDEXMINATTEN (Bitfield-Mask: 0xff)                   */
/* =====================================================  INTELEMENT12  ====================================================== */
#define FRC_INTELEMENT12_INDEXMINATTEN_Pos (0UL)                    /*!< INDEXMINATTEN (Bit 0)                                 */
#define FRC_INTELEMENT12_INDEXMINATTEN_Msk (0xffUL)                 /*!< INDEXMINATTEN (Bitfield-Mask: 0xff)                   */
/* =====================================================  INTELEMENT13  ====================================================== */
#define FRC_INTELEMENT13_INDEXMINATTEN_Pos (0UL)                    /*!< INDEXMINATTEN (Bit 0)                                 */
#define FRC_INTELEMENT13_INDEXMINATTEN_Msk (0xffUL)                 /*!< INDEXMINATTEN (Bitfield-Mask: 0xff)                   */
/* =====================================================  INTELEMENT14  ====================================================== */
#define FRC_INTELEMENT14_INDEXMINATTEN_Pos (0UL)                    /*!< INDEXMINATTEN (Bit 0)                                 */
#define FRC_INTELEMENT14_INDEXMINATTEN_Msk (0xffUL)                 /*!< INDEXMINATTEN (Bitfield-Mask: 0xff)                   */
/* =====================================================  INTELEMENT15  ====================================================== */
#define FRC_INTELEMENT15_INDEXMINATTEN_Pos (0UL)                    /*!< INDEXMINATTEN (Bit 0)                                 */
#define FRC_INTELEMENT15_INDEXMINATTEN_Msk (0xffUL)                 /*!< INDEXMINATTEN (Bitfield-Mask: 0xff)                   */

/** @} */
/** @} End of group EFR32FG1V_FRC */
/** @} End of group Parts */
