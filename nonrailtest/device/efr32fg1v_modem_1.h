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
 * @defgroup EFR32FG1V_MODEM
 * @{
 * @brief EFR32FG1V_MODEM Register Declaration
 ******************************************************************************/
/* =========================================================================================================================== */
/* ================                                           MODEM                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief Modem controller (MODEM)
  */

typedef struct {                                /*!< (@ 0x40086000) MODEM Structure                                            */
  __IM  uint32_t  STATUS;                       /*!< (@ 0x00000000) STATUS                                                     */
  __IM  uint32_t  TIMDETSTATUS;                 /*!< (@ 0x00000004) TIMDETSTATUS                                               */
  __IM  uint32_t  FREQOFFEST;                   /*!< (@ 0x00000008) FREQOFFEST                                                 */
  __IM  uint32_t  AFCADJRX;                     /*!< (@ 0x0000000C) AFCADJRX                                                   */
  __IM  uint32_t  AFCADJTX;                     /*!< (@ 0x00000010) AFCADJTX                                                   */
  __IOM uint32_t  MIXCTRL;                      /*!< (@ 0x00000014) MIXCTRL                                                    */
  __IOM uint32_t  CTRL0;                        /*!< (@ 0x00000018) CTRL0                                                      */
  __IOM uint32_t  CTRL1;                        /*!< (@ 0x0000001C) CTRL1                                                      */
  __IOM uint32_t  CTRL2;                        /*!< (@ 0x00000020) CTRL2                                                      */
  __IOM uint32_t  CTRL3;                        /*!< (@ 0x00000024) CTRL3                                                      */
  __IOM uint32_t  CTRL4;                        /*!< (@ 0x00000028) CTRL4                                                      */
  __IOM uint32_t  CTRL5;                        /*!< (@ 0x0000002C) CTRL5                                                      */
  __IOM uint32_t  TXBR;                         /*!< (@ 0x00000030) TXBR                                                       */
  __IOM uint32_t  RXBR;                         /*!< (@ 0x00000034) RXBR                                                       */
  __IOM uint32_t  CF;                           /*!< (@ 0x00000038) CF                                                         */
  __IOM uint32_t  PRE;                          /*!< (@ 0x0000003C) PRE                                                        */
  __IOM uint32_t  SYNC0;                        /*!< (@ 0x00000040) SYNC0                                                      */
  __IOM uint32_t  SYNC1;                        /*!< (@ 0x00000044) SYNC1                                                      */
  __IOM uint32_t  TIMING;                       /*!< (@ 0x00000048) TIMING                                                     */
  __IOM uint32_t  DSSS0;                        /*!< (@ 0x0000004C) DSSS0                                                      */
  __IOM uint32_t  MODINDEX;                     /*!< (@ 0x00000050) MODINDEX                                                   */
  __IOM uint32_t  AFC;                          /*!< (@ 0x00000054) AFC                                                        */
  __IOM uint32_t  AFCADJLIM;                    /*!< (@ 0x00000058) AFCADJLIM                                                  */
  __IOM uint32_t  SHAPING0;                     /*!< (@ 0x0000005C) SHAPING0                                                   */
  __IOM uint32_t  SHAPING1;                     /*!< (@ 0x00000060) SHAPING1                                                   */
  __IOM uint32_t  SHAPING2;                     /*!< (@ 0x00000064) SHAPING2                                                   */
  __IOM uint32_t  RAMPCTRL;                     /*!< (@ 0x00000068) RAMPCTRL                                                   */
  __IOM uint32_t  RAMPLEV;                      /*!< (@ 0x0000006C) RAMPLEV                                                    */
  __IOM uint32_t  ROUTEPEN;                     /*!< (@ 0x00000070) ROUTEPEN                                                   */
  __IOM uint32_t  ROUTELOC0;                    /*!< (@ 0x00000074) ROUTELOC0                                                  */
  __IOM uint32_t  ROUTELOC1;                    /*!< (@ 0x00000078) ROUTELOC1                                                  */
  __IM  uint32_t  RESERVED;
  __IM  uint32_t  IF;                           /*!< (@ 0x00000080) IF                                                         */
  __OM  uint32_t  IFS;                          /*!< (@ 0x00000084) IFS                                                        */
  __OM  uint32_t  IFC;                          /*!< (@ 0x00000088) IFC                                                        */
  __IOM uint32_t  IEN;                          /*!< (@ 0x0000008C) IEN                                                        */
  __OM  uint32_t  CMD;                          /*!< (@ 0x00000090) CMD                                                        */
  __IM  uint32_t  RESERVED1;
  __IOM uint32_t  DCCOMP;                       /*!< (@ 0x00000098) DCCOMP                                                     */
  __IOM uint32_t  DCCOMPFILTINIT;               /*!< (@ 0x0000009C) DCCOMPFILTINIT                                             */
  __IM  uint32_t  RESERVED2[24];
  __IM  uint32_t  DCESTI;                       /*!< (@ 0x00000100) DCESTI                                                     */
  __IM  uint32_t  RESERVED3[191];
  __IOM uint32_t  RAM0_RAMDATA;                 /*!< (@ 0x00000400) RAM0_RAMDATA                                               */
  __IOM uint32_t  RAM1_RAMDATA;                 /*!< (@ 0x00000404) RAM1_RAMDATA                                               */
  __IOM uint32_t  RAM2_RAMDATA;                 /*!< (@ 0x00000408) RAM2_RAMDATA                                               */
  __IOM uint32_t  RAM3_RAMDATA;                 /*!< (@ 0x0000040C) RAM3_RAMDATA                                               */
  __IOM uint32_t  RAM4_RAMDATA;                 /*!< (@ 0x00000410) RAM4_RAMDATA                                               */
  __IOM uint32_t  RAM5_RAMDATA;                 /*!< (@ 0x00000414) RAM5_RAMDATA                                               */
  __IOM uint32_t  RAM6_RAMDATA;                 /*!< (@ 0x00000418) RAM6_RAMDATA                                               */
  __IOM uint32_t  RAM7_RAMDATA;                 /*!< (@ 0x0000041C) RAM7_RAMDATA                                               */
  __IOM uint32_t  RAM8_RAMDATA;                 /*!< (@ 0x00000420) RAM8_RAMDATA                                               */
  __IOM uint32_t  RAM9_RAMDATA;                 /*!< (@ 0x00000424) RAM9_RAMDATA                                               */
  __IOM uint32_t  RAM10_RAMDATA;                /*!< (@ 0x00000428) RAM10_RAMDATA                                              */
  __IOM uint32_t  RAM11_RAMDATA;                /*!< (@ 0x0000042C) RAM11_RAMDATA                                              */
  __IOM uint32_t  RAM12_RAMDATA;                /*!< (@ 0x00000430) RAM12_RAMDATA                                              */
  __IOM uint32_t  RAM13_RAMDATA;                /*!< (@ 0x00000434) RAM13_RAMDATA                                              */
  __IOM uint32_t  RAM14_RAMDATA;                /*!< (@ 0x00000438) RAM14_RAMDATA                                              */
  __IOM uint32_t  RAM15_RAMDATA;                /*!< (@ 0x0000043C) RAM15_RAMDATA                                              */
  __IOM uint32_t  RAM16_RAMDATA;                /*!< (@ 0x00000440) RAM16_RAMDATA                                              */
  __IOM uint32_t  RAM17_RAMDATA;                /*!< (@ 0x00000444) RAM17_RAMDATA                                              */
  __IOM uint32_t  RAM18_RAMDATA;                /*!< (@ 0x00000448) RAM18_RAMDATA                                              */
  __IOM uint32_t  RAM19_RAMDATA;                /*!< (@ 0x0000044C) RAM19_RAMDATA                                              */
  __IOM uint32_t  RAM20_RAMDATA;                /*!< (@ 0x00000450) RAM20_RAMDATA                                              */
  __IOM uint32_t  RAM21_RAMDATA;                /*!< (@ 0x00000454) RAM21_RAMDATA                                              */
  __IOM uint32_t  RAM22_RAMDATA;                /*!< (@ 0x00000458) RAM22_RAMDATA                                              */
  __IOM uint32_t  RAM23_RAMDATA;                /*!< (@ 0x0000045C) RAM23_RAMDATA                                              */
  __IOM uint32_t  RAM24_RAMDATA;                /*!< (@ 0x00000460) RAM24_RAMDATA                                              */
  __IOM uint32_t  RAM25_RAMDATA;                /*!< (@ 0x00000464) RAM25_RAMDATA                                              */
  __IOM uint32_t  RAM26_RAMDATA;                /*!< (@ 0x00000468) RAM26_RAMDATA                                              */
  __IOM uint32_t  RAM27_RAMDATA;                /*!< (@ 0x0000046C) RAM27_RAMDATA                                              */
  __IOM uint32_t  RAM28_RAMDATA;                /*!< (@ 0x00000470) RAM28_RAMDATA                                              */
  __IOM uint32_t  RAM29_RAMDATA;                /*!< (@ 0x00000474) RAM29_RAMDATA                                              */
  __IOM uint32_t  RAM30_RAMDATA;                /*!< (@ 0x00000478) RAM30_RAMDATA                                              */
  __IOM uint32_t  RAM31_RAMDATA;                /*!< (@ 0x0000047C) RAM31_RAMDATA                                              */
  __IOM uint32_t  RAM32_RAMDATA;                /*!< (@ 0x00000480) RAM32_RAMDATA                                              */
  __IOM uint32_t  RAM33_RAMDATA;                /*!< (@ 0x00000484) RAM33_RAMDATA                                              */
  __IOM uint32_t  RAM34_RAMDATA;                /*!< (@ 0x00000488) RAM34_RAMDATA                                              */
  __IOM uint32_t  RAM35_RAMDATA;                /*!< (@ 0x0000048C) RAM35_RAMDATA                                              */
  __IOM uint32_t  RAM36_RAMDATA;                /*!< (@ 0x00000490) RAM36_RAMDATA                                              */
  __IOM uint32_t  RAM37_RAMDATA;                /*!< (@ 0x00000494) RAM37_RAMDATA                                              */
  __IOM uint32_t  RAM38_RAMDATA;                /*!< (@ 0x00000498) RAM38_RAMDATA                                              */
  __IOM uint32_t  RAM39_RAMDATA;                /*!< (@ 0x0000049C) RAM39_RAMDATA                                              */
  __IOM uint32_t  RAM40_RAMDATA;                /*!< (@ 0x000004A0) RAM40_RAMDATA                                              */
  __IOM uint32_t  RAM41_RAMDATA;                /*!< (@ 0x000004A4) RAM41_RAMDATA                                              */
  __IOM uint32_t  RAM42_RAMDATA;                /*!< (@ 0x000004A8) RAM42_RAMDATA                                              */
  __IOM uint32_t  RAM43_RAMDATA;                /*!< (@ 0x000004AC) RAM43_RAMDATA                                              */
  __IOM uint32_t  RAM44_RAMDATA;                /*!< (@ 0x000004B0) RAM44_RAMDATA                                              */
  __IOM uint32_t  RAM45_RAMDATA;                /*!< (@ 0x000004B4) RAM45_RAMDATA                                              */
  __IOM uint32_t  RAM46_RAMDATA;                /*!< (@ 0x000004B8) RAM46_RAMDATA                                              */
  __IOM uint32_t  RAM47_RAMDATA;                /*!< (@ 0x000004BC) RAM47_RAMDATA                                              */
  __IOM uint32_t  RAM48_RAMDATA;                /*!< (@ 0x000004C0) RAM48_RAMDATA                                              */
  __IOM uint32_t  RAM49_RAMDATA;                /*!< (@ 0x000004C4) RAM49_RAMDATA                                              */
  __IOM uint32_t  RAM50_RAMDATA;                /*!< (@ 0x000004C8) RAM50_RAMDATA                                              */
  __IOM uint32_t  RAM51_RAMDATA;                /*!< (@ 0x000004CC) RAM51_RAMDATA                                              */
  __IOM uint32_t  RAM52_RAMDATA;                /*!< (@ 0x000004D0) RAM52_RAMDATA                                              */
  __IOM uint32_t  RAM53_RAMDATA;                /*!< (@ 0x000004D4) RAM53_RAMDATA                                              */
  __IOM uint32_t  RAM54_RAMDATA;                /*!< (@ 0x000004D8) RAM54_RAMDATA                                              */
  __IOM uint32_t  RAM55_RAMDATA;                /*!< (@ 0x000004DC) RAM55_RAMDATA                                              */
  __IOM uint32_t  RAM56_RAMDATA;                /*!< (@ 0x000004E0) RAM56_RAMDATA                                              */
  __IOM uint32_t  RAM57_RAMDATA;                /*!< (@ 0x000004E4) RAM57_RAMDATA                                              */
  __IOM uint32_t  RAM58_RAMDATA;                /*!< (@ 0x000004E8) RAM58_RAMDATA                                              */
  __IOM uint32_t  RAM59_RAMDATA;                /*!< (@ 0x000004EC) RAM59_RAMDATA                                              */
  __IOM uint32_t  RAM60_RAMDATA;                /*!< (@ 0x000004F0) RAM60_RAMDATA                                              */
  __IOM uint32_t  RAM61_RAMDATA;                /*!< (@ 0x000004F4) RAM61_RAMDATA                                              */
  __IOM uint32_t  RAM62_RAMDATA;                /*!< (@ 0x000004F8) RAM62_RAMDATA                                              */
  __IOM uint32_t  RAM63_RAMDATA;                /*!< (@ 0x000004FC) RAM63_RAMDATA                                              */
  __IOM uint32_t  RAM64_RAMDATA;                /*!< (@ 0x00000500) RAM64_RAMDATA                                              */
  __IOM uint32_t  RAM65_RAMDATA;                /*!< (@ 0x00000504) RAM65_RAMDATA                                              */
  __IOM uint32_t  RAM66_RAMDATA;                /*!< (@ 0x00000508) RAM66_RAMDATA                                              */
  __IOM uint32_t  RAM67_RAMDATA;                /*!< (@ 0x0000050C) RAM67_RAMDATA                                              */
  __IOM uint32_t  RAM68_RAMDATA;                /*!< (@ 0x00000510) RAM68_RAMDATA                                              */
  __IOM uint32_t  RAM69_RAMDATA;                /*!< (@ 0x00000514) RAM69_RAMDATA                                              */
  __IOM uint32_t  RAM70_RAMDATA;                /*!< (@ 0x00000518) RAM70_RAMDATA                                              */
  __IOM uint32_t  RAM71_RAMDATA;                /*!< (@ 0x0000051C) RAM71_RAMDATA                                              */
  __IOM uint32_t  RAM72_RAMDATA;                /*!< (@ 0x00000520) RAM72_RAMDATA                                              */
  __IOM uint32_t  RAM73_RAMDATA;                /*!< (@ 0x00000524) RAM73_RAMDATA                                              */
  __IOM uint32_t  RAM74_RAMDATA;                /*!< (@ 0x00000528) RAM74_RAMDATA                                              */
  __IOM uint32_t  RAM75_RAMDATA;                /*!< (@ 0x0000052C) RAM75_RAMDATA                                              */
  __IOM uint32_t  RAM76_RAMDATA;                /*!< (@ 0x00000530) RAM76_RAMDATA                                              */
  __IOM uint32_t  RAM77_RAMDATA;                /*!< (@ 0x00000534) RAM77_RAMDATA                                              */
  __IOM uint32_t  RAM78_RAMDATA;                /*!< (@ 0x00000538) RAM78_RAMDATA                                              */
  __IOM uint32_t  RAM79_RAMDATA;                /*!< (@ 0x0000053C) RAM79_RAMDATA                                              */
  __IOM uint32_t  RAM80_RAMDATA;                /*!< (@ 0x00000540) RAM80_RAMDATA                                              */
  __IOM uint32_t  RAM81_RAMDATA;                /*!< (@ 0x00000544) RAM81_RAMDATA                                              */
  __IOM uint32_t  RAM82_RAMDATA;                /*!< (@ 0x00000548) RAM82_RAMDATA                                              */
  __IOM uint32_t  RAM83_RAMDATA;                /*!< (@ 0x0000054C) RAM83_RAMDATA                                              */
  __IOM uint32_t  RAM84_RAMDATA;                /*!< (@ 0x00000550) RAM84_RAMDATA                                              */
  __IOM uint32_t  RAM85_RAMDATA;                /*!< (@ 0x00000554) RAM85_RAMDATA                                              */
  __IOM uint32_t  RAM86_RAMDATA;                /*!< (@ 0x00000558) RAM86_RAMDATA                                              */
  __IOM uint32_t  RAM87_RAMDATA;                /*!< (@ 0x0000055C) RAM87_RAMDATA                                              */
  __IOM uint32_t  RAM88_RAMDATA;                /*!< (@ 0x00000560) RAM88_RAMDATA                                              */
  __IOM uint32_t  RAM89_RAMDATA;                /*!< (@ 0x00000564) RAM89_RAMDATA                                              */
  __IOM uint32_t  RAM90_RAMDATA;                /*!< (@ 0x00000568) RAM90_RAMDATA                                              */
  __IOM uint32_t  RAM91_RAMDATA;                /*!< (@ 0x0000056C) RAM91_RAMDATA                                              */
  __IOM uint32_t  RAM92_RAMDATA;                /*!< (@ 0x00000570) RAM92_RAMDATA                                              */
  __IOM uint32_t  RAM93_RAMDATA;                /*!< (@ 0x00000574) RAM93_RAMDATA                                              */
  __IOM uint32_t  RAM94_RAMDATA;                /*!< (@ 0x00000578) RAM94_RAMDATA                                              */
  __IOM uint32_t  RAM95_RAMDATA;                /*!< (@ 0x0000057C) RAM95_RAMDATA                                              */
  __IOM uint32_t  RAM96_RAMDATA;                /*!< (@ 0x00000580) RAM96_RAMDATA                                              */
  __IOM uint32_t  RAM97_RAMDATA;                /*!< (@ 0x00000584) RAM97_RAMDATA                                              */
  __IOM uint32_t  RAM98_RAMDATA;                /*!< (@ 0x00000588) RAM98_RAMDATA                                              */
  __IOM uint32_t  RAM99_RAMDATA;                /*!< (@ 0x0000058C) RAM99_RAMDATA                                              */
  __IOM uint32_t  RAM100_RAMDATA;               /*!< (@ 0x00000590) RAM100_RAMDATA                                             */
  __IOM uint32_t  RAM101_RAMDATA;               /*!< (@ 0x00000594) RAM101_RAMDATA                                             */
  __IOM uint32_t  RAM102_RAMDATA;               /*!< (@ 0x00000598) RAM102_RAMDATA                                             */
  __IOM uint32_t  RAM103_RAMDATA;               /*!< (@ 0x0000059C) RAM103_RAMDATA                                             */
  __IOM uint32_t  RAM104_RAMDATA;               /*!< (@ 0x000005A0) RAM104_RAMDATA                                             */
  __IOM uint32_t  RAM105_RAMDATA;               /*!< (@ 0x000005A4) RAM105_RAMDATA                                             */
  __IOM uint32_t  RAM106_RAMDATA;               /*!< (@ 0x000005A8) RAM106_RAMDATA                                             */
  __IOM uint32_t  RAM107_RAMDATA;               /*!< (@ 0x000005AC) RAM107_RAMDATA                                             */
  __IOM uint32_t  RAM108_RAMDATA;               /*!< (@ 0x000005B0) RAM108_RAMDATA                                             */
  __IOM uint32_t  RAM109_RAMDATA;               /*!< (@ 0x000005B4) RAM109_RAMDATA                                             */
  __IOM uint32_t  RAM110_RAMDATA;               /*!< (@ 0x000005B8) RAM110_RAMDATA                                             */
  __IOM uint32_t  RAM111_RAMDATA;               /*!< (@ 0x000005BC) RAM111_RAMDATA                                             */
  __IOM uint32_t  RAM112_RAMDATA;               /*!< (@ 0x000005C0) RAM112_RAMDATA                                             */
  __IOM uint32_t  RAM113_RAMDATA;               /*!< (@ 0x000005C4) RAM113_RAMDATA                                             */
  __IOM uint32_t  RAM114_RAMDATA;               /*!< (@ 0x000005C8) RAM114_RAMDATA                                             */
  __IOM uint32_t  RAM115_RAMDATA;               /*!< (@ 0x000005CC) RAM115_RAMDATA                                             */
  __IOM uint32_t  RAM116_RAMDATA;               /*!< (@ 0x000005D0) RAM116_RAMDATA                                             */
  __IOM uint32_t  RAM117_RAMDATA;               /*!< (@ 0x000005D4) RAM117_RAMDATA                                             */
  __IOM uint32_t  RAM118_RAMDATA;               /*!< (@ 0x000005D8) RAM118_RAMDATA                                             */
  __IOM uint32_t  RAM119_RAMDATA;               /*!< (@ 0x000005DC) RAM119_RAMDATA                                             */
  __IOM uint32_t  RAM120_RAMDATA;               /*!< (@ 0x000005E0) RAM120_RAMDATA                                             */
  __IOM uint32_t  RAM121_RAMDATA;               /*!< (@ 0x000005E4) RAM121_RAMDATA                                             */
  __IOM uint32_t  RAM122_RAMDATA;               /*!< (@ 0x000005E8) RAM122_RAMDATA                                             */
  __IOM uint32_t  RAM123_RAMDATA;               /*!< (@ 0x000005EC) RAM123_RAMDATA                                             */
  __IOM uint32_t  RAM124_RAMDATA;               /*!< (@ 0x000005F0) RAM124_RAMDATA                                             */
  __IOM uint32_t  RAM125_RAMDATA;               /*!< (@ 0x000005F4) RAM125_RAMDATA                                             */
  __IOM uint32_t  RAM126_RAMDATA;               /*!< (@ 0x000005F8) RAM126_RAMDATA                                             */
  __IOM uint32_t  RAM127_RAMDATA;               /*!< (@ 0x000005FC) RAM127_RAMDATA                                             */
  __IOM uint32_t  RAM128_RAMDATA;               /*!< (@ 0x00000600) RAM128_RAMDATA                                             */
  __IOM uint32_t  RAM129_RAMDATA;               /*!< (@ 0x00000604) RAM129_RAMDATA                                             */
  __IOM uint32_t  RAM130_RAMDATA;               /*!< (@ 0x00000608) RAM130_RAMDATA                                             */
  __IOM uint32_t  RAM131_RAMDATA;               /*!< (@ 0x0000060C) RAM131_RAMDATA                                             */
  __IOM uint32_t  RAM132_RAMDATA;               /*!< (@ 0x00000610) RAM132_RAMDATA                                             */
  __IOM uint32_t  RAM133_RAMDATA;               /*!< (@ 0x00000614) RAM133_RAMDATA                                             */
  __IOM uint32_t  RAM134_RAMDATA;               /*!< (@ 0x00000618) RAM134_RAMDATA                                             */
  __IOM uint32_t  RAM135_RAMDATA;               /*!< (@ 0x0000061C) RAM135_RAMDATA                                             */
  __IOM uint32_t  RAM136_RAMDATA;               /*!< (@ 0x00000620) RAM136_RAMDATA                                             */
  __IOM uint32_t  RAM137_RAMDATA;               /*!< (@ 0x00000624) RAM137_RAMDATA                                             */
  __IOM uint32_t  RAM138_RAMDATA;               /*!< (@ 0x00000628) RAM138_RAMDATA                                             */
  __IOM uint32_t  RAM139_RAMDATA;               /*!< (@ 0x0000062C) RAM139_RAMDATA                                             */
  __IOM uint32_t  RAM140_RAMDATA;               /*!< (@ 0x00000630) RAM140_RAMDATA                                             */
  __IOM uint32_t  RAM141_RAMDATA;               /*!< (@ 0x00000634) RAM141_RAMDATA                                             */
  __IOM uint32_t  RAM142_RAMDATA;               /*!< (@ 0x00000638) RAM142_RAMDATA                                             */
  __IOM uint32_t  RAM143_RAMDATA;               /*!< (@ 0x0000063C) RAM143_RAMDATA                                             */
  __IOM uint32_t  RAM144_RAMDATA;               /*!< (@ 0x00000640) RAM144_RAMDATA                                             */
  __IOM uint32_t  RAM145_RAMDATA;               /*!< (@ 0x00000644) RAM145_RAMDATA                                             */
  __IOM uint32_t  RAM146_RAMDATA;               /*!< (@ 0x00000648) RAM146_RAMDATA                                             */
  __IOM uint32_t  RAM147_RAMDATA;               /*!< (@ 0x0000064C) RAM147_RAMDATA                                             */
  __IOM uint32_t  RAM148_RAMDATA;               /*!< (@ 0x00000650) RAM148_RAMDATA                                             */
  __IOM uint32_t  RAM149_RAMDATA;               /*!< (@ 0x00000654) RAM149_RAMDATA                                             */
  __IOM uint32_t  RAM150_RAMDATA;               /*!< (@ 0x00000658) RAM150_RAMDATA                                             */
  __IOM uint32_t  RAM151_RAMDATA;               /*!< (@ 0x0000065C) RAM151_RAMDATA                                             */
  __IOM uint32_t  RAM152_RAMDATA;               /*!< (@ 0x00000660) RAM152_RAMDATA                                             */
  __IOM uint32_t  RAM153_RAMDATA;               /*!< (@ 0x00000664) RAM153_RAMDATA                                             */
  __IOM uint32_t  RAM154_RAMDATA;               /*!< (@ 0x00000668) RAM154_RAMDATA                                             */
  __IOM uint32_t  RAM155_RAMDATA;               /*!< (@ 0x0000066C) RAM155_RAMDATA                                             */
  __IOM uint32_t  RAM156_RAMDATA;               /*!< (@ 0x00000670) RAM156_RAMDATA                                             */
  __IOM uint32_t  RAM157_RAMDATA;               /*!< (@ 0x00000674) RAM157_RAMDATA                                             */
  __IOM uint32_t  RAM158_RAMDATA;               /*!< (@ 0x00000678) RAM158_RAMDATA                                             */
  __IOM uint32_t  RAM159_RAMDATA;               /*!< (@ 0x0000067C) RAM159_RAMDATA                                             */
  __IOM uint32_t  RAM160_RAMDATA;               /*!< (@ 0x00000680) RAM160_RAMDATA                                             */
  __IOM uint32_t  RAM161_RAMDATA;               /*!< (@ 0x00000684) RAM161_RAMDATA                                             */
  __IOM uint32_t  RAM162_RAMDATA;               /*!< (@ 0x00000688) RAM162_RAMDATA                                             */
  __IOM uint32_t  RAM163_RAMDATA;               /*!< (@ 0x0000068C) RAM163_RAMDATA                                             */
  __IOM uint32_t  RAM164_RAMDATA;               /*!< (@ 0x00000690) RAM164_RAMDATA                                             */
  __IOM uint32_t  RAM165_RAMDATA;               /*!< (@ 0x00000694) RAM165_RAMDATA                                             */
  __IOM uint32_t  RAM166_RAMDATA;               /*!< (@ 0x00000698) RAM166_RAMDATA                                             */
  __IOM uint32_t  RAM167_RAMDATA;               /*!< (@ 0x0000069C) RAM167_RAMDATA                                             */
  __IOM uint32_t  RAM168_RAMDATA;               /*!< (@ 0x000006A0) RAM168_RAMDATA                                             */
  __IOM uint32_t  RAM169_RAMDATA;               /*!< (@ 0x000006A4) RAM169_RAMDATA                                             */
  __IOM uint32_t  RAM170_RAMDATA;               /*!< (@ 0x000006A8) RAM170_RAMDATA                                             */
  __IOM uint32_t  RAM171_RAMDATA;               /*!< (@ 0x000006AC) RAM171_RAMDATA                                             */
  __IOM uint32_t  RAM172_RAMDATA;               /*!< (@ 0x000006B0) RAM172_RAMDATA                                             */
  __IOM uint32_t  RAM173_RAMDATA;               /*!< (@ 0x000006B4) RAM173_RAMDATA                                             */
  __IOM uint32_t  RAM174_RAMDATA;               /*!< (@ 0x000006B8) RAM174_RAMDATA                                             */
  __IOM uint32_t  RAM175_RAMDATA;               /*!< (@ 0x000006BC) RAM175_RAMDATA                                             */
  __IOM uint32_t  RAM176_RAMDATA;               /*!< (@ 0x000006C0) RAM176_RAMDATA                                             */
  __IOM uint32_t  RAM177_RAMDATA;               /*!< (@ 0x000006C4) RAM177_RAMDATA                                             */
  __IOM uint32_t  RAM178_RAMDATA;               /*!< (@ 0x000006C8) RAM178_RAMDATA                                             */
  __IOM uint32_t  RAM179_RAMDATA;               /*!< (@ 0x000006CC) RAM179_RAMDATA                                             */
  __IOM uint32_t  RAM180_RAMDATA;               /*!< (@ 0x000006D0) RAM180_RAMDATA                                             */
  __IOM uint32_t  RAM181_RAMDATA;               /*!< (@ 0x000006D4) RAM181_RAMDATA                                             */
  __IOM uint32_t  RAM182_RAMDATA;               /*!< (@ 0x000006D8) RAM182_RAMDATA                                             */
  __IOM uint32_t  RAM183_RAMDATA;               /*!< (@ 0x000006DC) RAM183_RAMDATA                                             */
  __IOM uint32_t  RAM184_RAMDATA;               /*!< (@ 0x000006E0) RAM184_RAMDATA                                             */
  __IOM uint32_t  RAM185_RAMDATA;               /*!< (@ 0x000006E4) RAM185_RAMDATA                                             */
  __IOM uint32_t  RAM186_RAMDATA;               /*!< (@ 0x000006E8) RAM186_RAMDATA                                             */
  __IOM uint32_t  RAM187_RAMDATA;               /*!< (@ 0x000006EC) RAM187_RAMDATA                                             */
  __IOM uint32_t  RAM188_RAMDATA;               /*!< (@ 0x000006F0) RAM188_RAMDATA                                             */
  __IOM uint32_t  RAM189_RAMDATA;               /*!< (@ 0x000006F4) RAM189_RAMDATA                                             */
  __IOM uint32_t  RAM190_RAMDATA;               /*!< (@ 0x000006F8) RAM190_RAMDATA                                             */
  __IOM uint32_t  RAM191_RAMDATA;               /*!< (@ 0x000006FC) RAM191_RAMDATA                                             */
  __IOM uint32_t  RAM192_RAMDATA;               /*!< (@ 0x00000700) RAM192_RAMDATA                                             */
  __IOM uint32_t  RAM193_RAMDATA;               /*!< (@ 0x00000704) RAM193_RAMDATA                                             */
  __IOM uint32_t  RAM194_RAMDATA;               /*!< (@ 0x00000708) RAM194_RAMDATA                                             */
  __IOM uint32_t  RAM195_RAMDATA;               /*!< (@ 0x0000070C) RAM195_RAMDATA                                             */
  __IOM uint32_t  RAM196_RAMDATA;               /*!< (@ 0x00000710) RAM196_RAMDATA                                             */
  __IOM uint32_t  RAM197_RAMDATA;               /*!< (@ 0x00000714) RAM197_RAMDATA                                             */
  __IOM uint32_t  RAM198_RAMDATA;               /*!< (@ 0x00000718) RAM198_RAMDATA                                             */
  __IOM uint32_t  RAM199_RAMDATA;               /*!< (@ 0x0000071C) RAM199_RAMDATA                                             */
  __IOM uint32_t  RAM200_RAMDATA;               /*!< (@ 0x00000720) RAM200_RAMDATA                                             */
  __IOM uint32_t  RAM201_RAMDATA;               /*!< (@ 0x00000724) RAM201_RAMDATA                                             */
  __IOM uint32_t  RAM202_RAMDATA;               /*!< (@ 0x00000728) RAM202_RAMDATA                                             */
  __IOM uint32_t  RAM203_RAMDATA;               /*!< (@ 0x0000072C) RAM203_RAMDATA                                             */
  __IOM uint32_t  RAM204_RAMDATA;               /*!< (@ 0x00000730) RAM204_RAMDATA                                             */
  __IOM uint32_t  RAM205_RAMDATA;               /*!< (@ 0x00000734) RAM205_RAMDATA                                             */
  __IOM uint32_t  RAM206_RAMDATA;               /*!< (@ 0x00000738) RAM206_RAMDATA                                             */
  __IOM uint32_t  RAM207_RAMDATA;               /*!< (@ 0x0000073C) RAM207_RAMDATA                                             */
  __IOM uint32_t  RAM208_RAMDATA;               /*!< (@ 0x00000740) RAM208_RAMDATA                                             */
  __IOM uint32_t  RAM209_RAMDATA;               /*!< (@ 0x00000744) RAM209_RAMDATA                                             */
  __IOM uint32_t  RAM210_RAMDATA;               /*!< (@ 0x00000748) RAM210_RAMDATA                                             */
  __IOM uint32_t  RAM211_RAMDATA;               /*!< (@ 0x0000074C) RAM211_RAMDATA                                             */
  __IOM uint32_t  RAM212_RAMDATA;               /*!< (@ 0x00000750) RAM212_RAMDATA                                             */
  __IOM uint32_t  RAM213_RAMDATA;               /*!< (@ 0x00000754) RAM213_RAMDATA                                             */
  __IOM uint32_t  RAM214_RAMDATA;               /*!< (@ 0x00000758) RAM214_RAMDATA                                             */
  __IOM uint32_t  RAM215_RAMDATA;               /*!< (@ 0x0000075C) RAM215_RAMDATA                                             */
  __IOM uint32_t  RAM216_RAMDATA;               /*!< (@ 0x00000760) RAM216_RAMDATA                                             */
  __IOM uint32_t  RAM217_RAMDATA;               /*!< (@ 0x00000764) RAM217_RAMDATA                                             */
  __IOM uint32_t  RAM218_RAMDATA;               /*!< (@ 0x00000768) RAM218_RAMDATA                                             */
  __IOM uint32_t  RAM219_RAMDATA;               /*!< (@ 0x0000076C) RAM219_RAMDATA                                             */
  __IOM uint32_t  RAM220_RAMDATA;               /*!< (@ 0x00000770) RAM220_RAMDATA                                             */
  __IOM uint32_t  RAM221_RAMDATA;               /*!< (@ 0x00000774) RAM221_RAMDATA                                             */
  __IOM uint32_t  RAM222_RAMDATA;               /*!< (@ 0x00000778) RAM222_RAMDATA                                             */
  __IOM uint32_t  RAM223_RAMDATA;               /*!< (@ 0x0000077C) RAM223_RAMDATA                                             */
  __IOM uint32_t  RAM224_RAMDATA;               /*!< (@ 0x00000780) RAM224_RAMDATA                                             */
  __IOM uint32_t  RAM225_RAMDATA;               /*!< (@ 0x00000784) RAM225_RAMDATA                                             */
  __IOM uint32_t  RAM226_RAMDATA;               /*!< (@ 0x00000788) RAM226_RAMDATA                                             */
  __IOM uint32_t  RAM227_RAMDATA;               /*!< (@ 0x0000078C) RAM227_RAMDATA                                             */
  __IOM uint32_t  RAM228_RAMDATA;               /*!< (@ 0x00000790) RAM228_RAMDATA                                             */
  __IOM uint32_t  RAM229_RAMDATA;               /*!< (@ 0x00000794) RAM229_RAMDATA                                             */
  __IOM uint32_t  RAM230_RAMDATA;               /*!< (@ 0x00000798) RAM230_RAMDATA                                             */
  __IOM uint32_t  RAM231_RAMDATA;               /*!< (@ 0x0000079C) RAM231_RAMDATA                                             */
  __IOM uint32_t  RAM232_RAMDATA;               /*!< (@ 0x000007A0) RAM232_RAMDATA                                             */
  __IOM uint32_t  RAM233_RAMDATA;               /*!< (@ 0x000007A4) RAM233_RAMDATA                                             */
  __IOM uint32_t  RAM234_RAMDATA;               /*!< (@ 0x000007A8) RAM234_RAMDATA                                             */
  __IOM uint32_t  RAM235_RAMDATA;               /*!< (@ 0x000007AC) RAM235_RAMDATA                                             */
  __IOM uint32_t  RAM236_RAMDATA;               /*!< (@ 0x000007B0) RAM236_RAMDATA                                             */
  __IOM uint32_t  RAM237_RAMDATA;               /*!< (@ 0x000007B4) RAM237_RAMDATA                                             */
  __IOM uint32_t  RAM238_RAMDATA;               /*!< (@ 0x000007B8) RAM238_RAMDATA                                             */
  __IOM uint32_t  RAM239_RAMDATA;               /*!< (@ 0x000007BC) RAM239_RAMDATA                                             */
  __IOM uint32_t  RAM240_RAMDATA;               /*!< (@ 0x000007C0) RAM240_RAMDATA                                             */
  __IOM uint32_t  RAM241_RAMDATA;               /*!< (@ 0x000007C4) RAM241_RAMDATA                                             */
  __IOM uint32_t  RAM242_RAMDATA;               /*!< (@ 0x000007C8) RAM242_RAMDATA                                             */
  __IOM uint32_t  RAM243_RAMDATA;               /*!< (@ 0x000007CC) RAM243_RAMDATA                                             */
  __IOM uint32_t  RAM244_RAMDATA;               /*!< (@ 0x000007D0) RAM244_RAMDATA                                             */
  __IOM uint32_t  RAM245_RAMDATA;               /*!< (@ 0x000007D4) RAM245_RAMDATA                                             */
  __IOM uint32_t  RAM246_RAMDATA;               /*!< (@ 0x000007D8) RAM246_RAMDATA                                             */
  __IOM uint32_t  RAM247_RAMDATA;               /*!< (@ 0x000007DC) RAM247_RAMDATA                                             */
  __IOM uint32_t  RAM248_RAMDATA;               /*!< (@ 0x000007E0) RAM248_RAMDATA                                             */
  __IOM uint32_t  RAM249_RAMDATA;               /*!< (@ 0x000007E4) RAM249_RAMDATA                                             */
  __IOM uint32_t  RAM250_RAMDATA;               /*!< (@ 0x000007E8) RAM250_RAMDATA                                             */
  __IOM uint32_t  RAM251_RAMDATA;               /*!< (@ 0x000007EC) RAM251_RAMDATA                                             */
  __IOM uint32_t  RAM252_RAMDATA;               /*!< (@ 0x000007F0) RAM252_RAMDATA                                             */
  __IOM uint32_t  RAM253_RAMDATA;               /*!< (@ 0x000007F4) RAM253_RAMDATA                                             */
  __IOM uint32_t  RAM254_RAMDATA;               /*!< (@ 0x000007F8) RAM254_RAMDATA                                             */
  __IOM uint32_t  RAM255_RAMDATA;               /*!< (@ 0x000007FC) RAM255_RAMDATA                                             */
} MODEM_Typedef;                                   /*!< Size = 2048 (0x800)                                                       */


/***************************************************************************//**
 * @addtogroup EFR32FG1V_MODEM
 * @{
 * @defgroup EFR32FG1V_MODEM BitFields  MODEM Bit Fields
 * @{
 ******************************************************************************/
/* =========================================================================================================================== */
/* ================                                           MODEM                                           ================ */
/* =========================================================================================================================== */

/* ========================================================  STATUS  ========================================================= */
#define MODEM_STATUS_DEMODSTATE_Pos       (0UL)                     /*!< DEMODSTATE (Bit 0)                                    */
#define MODEM_STATUS_DEMODSTATE_Msk       (0x7UL)                   /*!< DEMODSTATE (Bitfield-Mask: 0x07)                      */
#define MODEM_STATUS_FRAMEDETID_Pos       (4UL)                     /*!< FRAMEDETID (Bit 4)                                    */
#define MODEM_STATUS_FRAMEDETID_Msk       (0x10UL)                  /*!< FRAMEDETID (Bitfield-Mask: 0x01)                      */
#define MODEM_STATUS_ANTSEL_Pos           (5UL)                     /*!< ANTSEL (Bit 5)                                        */
#define MODEM_STATUS_ANTSEL_Msk           (0x20UL)                  /*!< ANTSEL (Bitfield-Mask: 0x01)                          */
#define MODEM_STATUS_TIMSEQINV_Pos        (6UL)                     /*!< TIMSEQINV (Bit 6)                                     */
#define MODEM_STATUS_TIMSEQINV_Msk        (0x40UL)                  /*!< TIMSEQINV (Bitfield-Mask: 0x01)                       */
#define MODEM_STATUS_TIMLOSTCAUSE_Pos     (7UL)                     /*!< TIMLOSTCAUSE (Bit 7)                                  */
#define MODEM_STATUS_TIMLOSTCAUSE_Msk     (0x80UL)                  /*!< TIMLOSTCAUSE (Bitfield-Mask: 0x01)                    */
#define MODEM_STATUS_CORR_Pos             (16UL)                    /*!< CORR (Bit 16)                                         */
#define MODEM_STATUS_CORR_Msk             (0xff0000UL)              /*!< CORR (Bitfield-Mask: 0xff)                            */
#define MODEM_STATUS_WEAKSYMBOLS_Pos      (24UL)                    /*!< WEAKSYMBOLS (Bit 24)                                  */
#define MODEM_STATUS_WEAKSYMBOLS_Msk      (0xff000000UL)            /*!< WEAKSYMBOLS (Bitfield-Mask: 0xff)                     */
/* =====================================================  TIMDETSTATUS  ====================================================== */
#define MODEM_TIMDETSTATUS_TIMDETCORR_Pos (0UL)                     /*!< TIMDETCORR (Bit 0)                                    */
#define MODEM_TIMDETSTATUS_TIMDETCORR_Msk (0xffUL)                  /*!< TIMDETCORR (Bitfield-Mask: 0xff)                      */
#define MODEM_TIMDETSTATUS_TIMDETFREQOFFEST_Pos (8UL)               /*!< TIMDETFREQOFFEST (Bit 8)                              */
#define MODEM_TIMDETSTATUS_TIMDETFREQOFFEST_Msk (0xff00UL)          /*!< TIMDETFREQOFFEST (Bitfield-Mask: 0xff)                */
#define MODEM_TIMDETSTATUS_TIMDETPREERRORS_Pos (16UL)               /*!< TIMDETPREERRORS (Bit 16)                              */
#define MODEM_TIMDETSTATUS_TIMDETPREERRORS_Msk (0xf0000UL)          /*!< TIMDETPREERRORS (Bitfield-Mask: 0x0f)                 */
#define MODEM_TIMDETSTATUS_TIMDETPASS_Pos (24UL)                    /*!< TIMDETPASS (Bit 24)                                   */
#define MODEM_TIMDETSTATUS_TIMDETPASS_Msk (0x1000000UL)             /*!< TIMDETPASS (Bitfield-Mask: 0x01)                      */
#define MODEM_TIMDETSTATUS_TIMDETINDEX_Pos (25UL)                   /*!< TIMDETINDEX (Bit 25)                                  */
#define MODEM_TIMDETSTATUS_TIMDETINDEX_Msk (0x1e000000UL)           /*!< TIMDETINDEX (Bitfield-Mask: 0x0f)                     */
/* ======================================================  FREQOFFEST  ======================================================= */
#define MODEM_FREQOFFEST_FREQOFFEST_Pos   (0UL)                     /*!< FREQOFFEST (Bit 0)                                    */
#define MODEM_FREQOFFEST_FREQOFFEST_Msk   (0xffUL)                  /*!< FREQOFFEST (Bitfield-Mask: 0xff)                      */
#define MODEM_FREQOFFEST_POE_Pos          (8UL)                     /*!< POE (Bit 8)                                           */
#define MODEM_FREQOFFEST_POE_Msk          (0xff00UL)                /*!< POE (Bitfield-Mask: 0xff)                             */
#define MODEM_FREQOFFEST_CORRVAL_Pos      (16UL)                    /*!< CORRVAL (Bit 16)                                      */
#define MODEM_FREQOFFEST_CORRVAL_Msk      (0xff0000UL)              /*!< CORRVAL (Bitfield-Mask: 0xff)                         */
#define MODEM_FREQOFFEST_SOFTVAL_Pos      (24UL)                    /*!< SOFTVAL (Bit 24)                                      */
#define MODEM_FREQOFFEST_SOFTVAL_Msk      (0xff000000UL)            /*!< SOFTVAL (Bitfield-Mask: 0xff)                         */
/* =======================================================  AFCADJRX  ======================================================== */
#define MODEM_AFCADJRX_AFCADJRX_Pos       (0UL)                     /*!< AFCADJRX (Bit 0)                                      */
#define MODEM_AFCADJRX_AFCADJRX_Msk       (0x7ffffUL)               /*!< AFCADJRX (Bitfield-Mask: 0x7ffff)                     */
/* =======================================================  AFCADJTX  ======================================================== */
#define MODEM_AFCADJTX_AFCADJTX_Pos       (0UL)                     /*!< AFCADJTX (Bit 0)                                      */
#define MODEM_AFCADJTX_AFCADJTX_Msk       (0x7ffffUL)               /*!< AFCADJTX (Bitfield-Mask: 0x7ffff)                     */
/* ========================================================  MIXCTRL  ======================================================== */
#define MODEM_MIXCTRL_MODE_Pos            (0UL)                     /*!< MODE (Bit 0)                                          */
#define MODEM_MIXCTRL_MODE_Msk            (0xfUL)                   /*!< MODE (Bitfield-Mask: 0x0f)                            */
#define MODEM_MIXCTRL_DIGIQSWAPEN_Pos     (4UL)                     /*!< DIGIQSWAPEN (Bit 4)                                   */
#define MODEM_MIXCTRL_DIGIQSWAPEN_Msk     (0x10UL)                  /*!< DIGIQSWAPEN (Bitfield-Mask: 0x01)                     */
/* =========================================================  CTRL0  ========================================================= */
#define MODEM_CTRL0_FDM0DIFFDIS_Pos       (0UL)                     /*!< FDM0DIFFDIS (Bit 0)                                   */
#define MODEM_CTRL0_FDM0DIFFDIS_Msk       (0x1UL)                   /*!< FDM0DIFFDIS (Bitfield-Mask: 0x01)                     */
#define MODEM_CTRL0_MAPFSK_Pos            (1UL)                     /*!< MAPFSK (Bit 1)                                        */
#define MODEM_CTRL0_MAPFSK_Msk            (0xeUL)                   /*!< MAPFSK (Bitfield-Mask: 0x07)                          */
#define MODEM_CTRL0_CODING_Pos            (4UL)                     /*!< CODING (Bit 4)                                        */
#define MODEM_CTRL0_CODING_Msk            (0x30UL)                  /*!< CODING (Bitfield-Mask: 0x03)                          */
#define MODEM_CTRL0_MODFORMAT_Pos         (6UL)                     /*!< MODFORMAT (Bit 6)                                     */
#define MODEM_CTRL0_MODFORMAT_Msk         (0x1c0UL)                 /*!< MODFORMAT (Bitfield-Mask: 0x07)                       */
#define MODEM_CTRL0_DUALCORROPTDIS_Pos    (9UL)                     /*!< DUALCORROPTDIS (Bit 9)                                */
#define MODEM_CTRL0_DUALCORROPTDIS_Msk    (0x200UL)                 /*!< DUALCORROPTDIS (Bitfield-Mask: 0x01)                  */
#define MODEM_CTRL0_DSSSLEN_Pos           (11UL)                    /*!< DSSSLEN (Bit 11)                                      */
#define MODEM_CTRL0_DSSSLEN_Msk           (0xf800UL)                /*!< DSSSLEN (Bitfield-Mask: 0x1f)                         */
#define MODEM_CTRL0_DSSSSHIFTS_Pos        (16UL)                    /*!< DSSSSHIFTS (Bit 16)                                   */
#define MODEM_CTRL0_DSSSSHIFTS_Msk        (0x70000UL)               /*!< DSSSSHIFTS (Bitfield-Mask: 0x07)                      */
#define MODEM_CTRL0_DSSSDOUBLE_Pos        (19UL)                    /*!< DSSSDOUBLE (Bit 19)                                   */
#define MODEM_CTRL0_DSSSDOUBLE_Msk        (0x180000UL)              /*!< DSSSDOUBLE (Bitfield-Mask: 0x03)                      */
#define MODEM_CTRL0_DETDIS_Pos            (21UL)                    /*!< DETDIS (Bit 21)                                       */
#define MODEM_CTRL0_DETDIS_Msk            (0x200000UL)              /*!< DETDIS (Bitfield-Mask: 0x01)                          */
#define MODEM_CTRL0_DIFFENCMODE_Pos       (22UL)                    /*!< DIFFENCMODE (Bit 22)                                  */
#define MODEM_CTRL0_DIFFENCMODE_Msk       (0x1c00000UL)             /*!< DIFFENCMODE (Bitfield-Mask: 0x07)                     */
#define MODEM_CTRL0_SHAPING_Pos           (25UL)                    /*!< SHAPING (Bit 25)                                      */
#define MODEM_CTRL0_SHAPING_Msk           (0x6000000UL)             /*!< SHAPING (Bitfield-Mask: 0x03)                         */
#define MODEM_CTRL0_DEMODRAWDATASEL_Pos   (27UL)                    /*!< DEMODRAWDATASEL (Bit 27)                              */
#define MODEM_CTRL0_DEMODRAWDATASEL_Msk   (0x38000000UL)            /*!< DEMODRAWDATASEL (Bitfield-Mask: 0x07)                 */
#define MODEM_CTRL0_FRAMEDETDEL_Pos       (30UL)                    /*!< FRAMEDETDEL (Bit 30)                                  */
#define MODEM_CTRL0_FRAMEDETDEL_Msk       (0xc0000000UL)            /*!< FRAMEDETDEL (Bitfield-Mask: 0x03)                     */
/* =========================================================  CTRL1  ========================================================= */
#define MODEM_CTRL1_SYNCBITS_Pos          (0UL)                     /*!< SYNCBITS (Bit 0)                                      */
#define MODEM_CTRL1_SYNCBITS_Msk          (0x1fUL)                  /*!< SYNCBITS (Bitfield-Mask: 0x1f)                        */
#define MODEM_CTRL1_SYNCERRORS_Pos        (5UL)                     /*!< SYNCERRORS (Bit 5)                                    */
#define MODEM_CTRL1_SYNCERRORS_Msk        (0x1e0UL)                 /*!< SYNCERRORS (Bitfield-Mask: 0x0f)                      */
#define MODEM_CTRL1_DUALSYNC_Pos          (9UL)                     /*!< DUALSYNC (Bit 9)                                      */
#define MODEM_CTRL1_DUALSYNC_Msk          (0x200UL)                 /*!< DUALSYNC (Bitfield-Mask: 0x01)                        */
#define MODEM_CTRL1_TXSYNC_Pos            (10UL)                    /*!< TXSYNC (Bit 10)                                       */
#define MODEM_CTRL1_TXSYNC_Msk            (0x400UL)                 /*!< TXSYNC (Bitfield-Mask: 0x01)                          */
#define MODEM_CTRL1_SYNCDATA_Pos          (11UL)                    /*!< SYNCDATA (Bit 11)                                     */
#define MODEM_CTRL1_SYNCDATA_Msk          (0x800UL)                 /*!< SYNCDATA (Bitfield-Mask: 0x01)                        */
#define MODEM_CTRL1_SYNC1INV_Pos          (12UL)                    /*!< SYNC1INV (Bit 12)                                     */
#define MODEM_CTRL1_SYNC1INV_Msk          (0x1000UL)                /*!< SYNC1INV (Bitfield-Mask: 0x01)                        */
#define MODEM_CTRL1_COMPMODE_Pos          (14UL)                    /*!< COMPMODE (Bit 14)                                     */
#define MODEM_CTRL1_COMPMODE_Msk          (0xc000UL)                /*!< COMPMODE (Bitfield-Mask: 0x03)                        */
#define MODEM_CTRL1_RESYNCPER_Pos         (16UL)                    /*!< RESYNCPER (Bit 16)                                    */
#define MODEM_CTRL1_RESYNCPER_Msk         (0xf0000UL)               /*!< RESYNCPER (Bitfield-Mask: 0x0f)                       */
#define MODEM_CTRL1_PHASEDEMOD_Pos        (20UL)                    /*!< PHASEDEMOD (Bit 20)                                   */
#define MODEM_CTRL1_PHASEDEMOD_Msk        (0x300000UL)              /*!< PHASEDEMOD (Bitfield-Mask: 0x03)                      */
#define MODEM_CTRL1_FREQOFFESTPER_Pos     (22UL)                    /*!< FREQOFFESTPER (Bit 22)                                */
#define MODEM_CTRL1_FREQOFFESTPER_Msk     (0x1c00000UL)             /*!< FREQOFFESTPER (Bitfield-Mask: 0x07)                   */
#define MODEM_CTRL1_FREQOFFESTLIM_Pos     (25UL)                    /*!< FREQOFFESTLIM (Bit 25)                                */
#define MODEM_CTRL1_FREQOFFESTLIM_Msk     (0xfe000000UL)            /*!< FREQOFFESTLIM (Bitfield-Mask: 0x7f)                   */
/* =========================================================  CTRL2  ========================================================= */
#define MODEM_CTRL2_SQITHRESH_Pos         (0UL)                     /*!< SQITHRESH (Bit 0)                                     */
#define MODEM_CTRL2_SQITHRESH_Msk         (0xffUL)                  /*!< SQITHRESH (Bitfield-Mask: 0xff)                       */
#define MODEM_CTRL2_RXFRCDIS_Pos          (8UL)                     /*!< RXFRCDIS (Bit 8)                                      */
#define MODEM_CTRL2_RXFRCDIS_Msk          (0x100UL)                 /*!< RXFRCDIS (Bitfield-Mask: 0x01)                        */
#define MODEM_CTRL2_RXPINMODE_Pos         (9UL)                     /*!< RXPINMODE (Bit 9)                                     */
#define MODEM_CTRL2_RXPINMODE_Msk         (0x200UL)                 /*!< RXPINMODE (Bitfield-Mask: 0x01)                       */
#define MODEM_CTRL2_TXPINMODE_Pos         (10UL)                    /*!< TXPINMODE (Bit 10)                                    */
#define MODEM_CTRL2_TXPINMODE_Msk         (0xc00UL)                 /*!< TXPINMODE (Bitfield-Mask: 0x03)                       */
#define MODEM_CTRL2_DATAFILTER_Pos        (12UL)                    /*!< DATAFILTER (Bit 12)                                   */
#define MODEM_CTRL2_DATAFILTER_Msk        (0x3000UL)                /*!< DATAFILTER (Bitfield-Mask: 0x03)                      */
#define MODEM_CTRL2_BRDIVA_Pos            (14UL)                    /*!< BRDIVA (Bit 14)                                       */
#define MODEM_CTRL2_BRDIVA_Msk            (0x3c000UL)               /*!< BRDIVA (Bitfield-Mask: 0x0f)                          */
#define MODEM_CTRL2_BRDIVB_Pos            (18UL)                    /*!< BRDIVB (Bit 18)                                       */
#define MODEM_CTRL2_BRDIVB_Msk            (0x3c0000UL)              /*!< BRDIVB (Bitfield-Mask: 0x0f)                          */
#define MODEM_CTRL2_DEVMULA_Pos           (22UL)                    /*!< DEVMULA (Bit 22)                                      */
#define MODEM_CTRL2_DEVMULA_Msk           (0xc00000UL)              /*!< DEVMULA (Bitfield-Mask: 0x03)                         */
#define MODEM_CTRL2_DEVMULB_Pos           (24UL)                    /*!< DEVMULB (Bit 24)                                      */
#define MODEM_CTRL2_DEVMULB_Msk           (0x3000000UL)             /*!< DEVMULB (Bitfield-Mask: 0x03)                         */
#define MODEM_CTRL2_RATESELMODE_Pos       (26UL)                    /*!< RATESELMODE (Bit 26)                                  */
#define MODEM_CTRL2_RATESELMODE_Msk       (0xc000000UL)             /*!< RATESELMODE (Bitfield-Mask: 0x03)                     */
#define MODEM_CTRL2_PRSDEBUG_Pos          (28UL)                    /*!< PRSDEBUG (Bit 28)                                     */
#define MODEM_CTRL2_PRSDEBUG_Msk          (0x10000000UL)            /*!< PRSDEBUG (Bitfield-Mask: 0x01)                        */
#define MODEM_CTRL2_DEVWEIGHTDIS_Pos      (29UL)                    /*!< DEVWEIGHTDIS (Bit 29)                                 */
#define MODEM_CTRL2_DEVWEIGHTDIS_Msk      (0x20000000UL)            /*!< DEVWEIGHTDIS (Bitfield-Mask: 0x01)                    */
#define MODEM_CTRL2_DMASEL_Pos            (30UL)                    /*!< DMASEL (Bit 30)                                       */
#define MODEM_CTRL2_DMASEL_Msk            (0xc0000000UL)            /*!< DMASEL (Bitfield-Mask: 0x03)                          */
/* =========================================================  CTRL3  ========================================================= */
#define MODEM_CTRL3_PRSDINEN_Pos          (0UL)                     /*!< PRSDINEN (Bit 0)                                      */
#define MODEM_CTRL3_PRSDINEN_Msk          (0x1UL)                   /*!< PRSDINEN (Bitfield-Mask: 0x01)                        */
#define MODEM_CTRL3_PRSDINSEL_Pos         (1UL)                     /*!< PRSDINSEL (Bit 1)                                     */
#define MODEM_CTRL3_PRSDINSEL_Msk         (0x1eUL)                  /*!< PRSDINSEL (Bitfield-Mask: 0x0f)                       */
#define MODEM_CTRL3_RAMTESTEN_Pos         (7UL)                     /*!< RAMTESTEN (Bit 7)                                     */
#define MODEM_CTRL3_RAMTESTEN_Msk         (0x80UL)                  /*!< RAMTESTEN (Bitfield-Mask: 0x01)                       */
#define MODEM_CTRL3_ANTDIVMODE_Pos        (8UL)                     /*!< ANTDIVMODE (Bit 8)                                    */
#define MODEM_CTRL3_ANTDIVMODE_Msk        (0x700UL)                 /*!< ANTDIVMODE (Bitfield-Mask: 0x07)                      */
#define MODEM_CTRL3_ANTDIVREPEATDIS_Pos   (11UL)                    /*!< ANTDIVREPEATDIS (Bit 11)                              */
#define MODEM_CTRL3_ANTDIVREPEATDIS_Msk   (0x800UL)                 /*!< ANTDIVREPEATDIS (Bitfield-Mask: 0x01)                 */
#define MODEM_CTRL3_TSAMPMODE_Pos         (12UL)                    /*!< TSAMPMODE (Bit 12)                                    */
#define MODEM_CTRL3_TSAMPMODE_Msk         (0x3000UL)                /*!< TSAMPMODE (Bitfield-Mask: 0x03)                       */
#define MODEM_CTRL3_TSAMPDEL_Pos          (14UL)                    /*!< TSAMPDEL (Bit 14)                                     */
#define MODEM_CTRL3_TSAMPDEL_Msk          (0xc000UL)                /*!< TSAMPDEL (Bitfield-Mask: 0x03)                        */
#define MODEM_CTRL3_TSAMPLIM_Pos          (16UL)                    /*!< TSAMPLIM (Bit 16)                                     */
#define MODEM_CTRL3_TSAMPLIM_Msk          (0xffff0000UL)            /*!< TSAMPLIM (Bitfield-Mask: 0xffff)                      */
/* =========================================================  CTRL4  ========================================================= */
#define MODEM_CTRL4_ISICOMP_Pos           (0UL)                     /*!< ISICOMP (Bit 0)                                       */
#define MODEM_CTRL4_ISICOMP_Msk           (0xfUL)                   /*!< ISICOMP (Bitfield-Mask: 0x0f)                         */
#define MODEM_CTRL4_DEVOFFCOMP_Pos        (4UL)                     /*!< DEVOFFCOMP (Bit 4)                                    */
#define MODEM_CTRL4_DEVOFFCOMP_Msk        (0x10UL)                  /*!< DEVOFFCOMP (Bitfield-Mask: 0x01)                      */
#define MODEM_CTRL4_PREDISTGAIN_Pos       (5UL)                     /*!< PREDISTGAIN (Bit 5)                                   */
#define MODEM_CTRL4_PREDISTGAIN_Msk       (0x3e0UL)                 /*!< PREDISTGAIN (Bitfield-Mask: 0x1f)                     */
#define MODEM_CTRL4_PREDISTDEB_Pos        (10UL)                    /*!< PREDISTDEB (Bit 10)                                   */
#define MODEM_CTRL4_PREDISTDEB_Msk        (0x1c00UL)                /*!< PREDISTDEB (Bitfield-Mask: 0x07)                      */
#define MODEM_CTRL4_PREDISTAVG_Pos        (13UL)                    /*!< PREDISTAVG (Bit 13)                                   */
#define MODEM_CTRL4_PREDISTAVG_Msk        (0x2000UL)                /*!< PREDISTAVG (Bitfield-Mask: 0x01)                      */
#define MODEM_CTRL4_PREDISTRST_Pos        (14UL)                    /*!< PREDISTRST (Bit 14)                                   */
#define MODEM_CTRL4_PREDISTRST_Msk        (0x4000UL)                /*!< PREDISTRST (Bitfield-Mask: 0x01)                      */
#define MODEM_CTRL4_PHASECLICKFILT_Pos    (15UL)                    /*!< PHASECLICKFILT (Bit 15)                               */
#define MODEM_CTRL4_PHASECLICKFILT_Msk    (0x3f8000UL)              /*!< PHASECLICKFILT (Bitfield-Mask: 0x7f)                  */
#define MODEM_CTRL4_SOFTDSSSMODE_Pos      (22UL)                    /*!< SOFTDSSSMODE (Bit 22)                                 */
#define MODEM_CTRL4_SOFTDSSSMODE_Msk      (0x400000UL)              /*!< SOFTDSSSMODE (Bitfield-Mask: 0x01)                    */
#define MODEM_CTRL4_ADCSATLEVEL_Pos       (23UL)                    /*!< ADCSATLEVEL (Bit 23)                                  */
#define MODEM_CTRL4_ADCSATLEVEL_Msk       (0x3800000UL)             /*!< ADCSATLEVEL (Bitfield-Mask: 0x07)                     */
#define MODEM_CTRL4_ADCSATDENS_Pos        (26UL)                    /*!< ADCSATDENS (Bit 26)                                   */
#define MODEM_CTRL4_ADCSATDENS_Msk        (0xc000000UL)             /*!< ADCSATDENS (Bitfield-Mask: 0x03)                      */
#define MODEM_CTRL4_OFFSETPHASEMASKING_Pos (28UL)                   /*!< OFFSETPHASEMASKING (Bit 28)                           */
#define MODEM_CTRL4_OFFSETPHASEMASKING_Msk (0x10000000UL)           /*!< OFFSETPHASEMASKING (Bitfield-Mask: 0x01)              */
#define MODEM_CTRL4_OFFSETPHASESCALING_Pos (29UL)                   /*!< OFFSETPHASESCALING (Bit 29)                           */
#define MODEM_CTRL4_OFFSETPHASESCALING_Msk (0x20000000UL)           /*!< OFFSETPHASESCALING (Bitfield-Mask: 0x01)              */
#define MODEM_CTRL4_CLKUNDIVREQ_Pos       (31UL)                    /*!< CLKUNDIVREQ (Bit 31)                                  */
#define MODEM_CTRL4_CLKUNDIVREQ_Msk       (0x80000000UL)            /*!< CLKUNDIVREQ (Bitfield-Mask: 0x01)                     */
/* =========================================================  CTRL5  ========================================================= */
#define MODEM_CTRL5_BRCALEN_Pos           (1UL)                     /*!< BRCALEN (Bit 1)                                       */
#define MODEM_CTRL5_BRCALEN_Msk           (0x2UL)                   /*!< BRCALEN (Bitfield-Mask: 0x01)                         */
#define MODEM_CTRL5_BRCALMODE_Pos         (2UL)                     /*!< BRCALMODE (Bit 2)                                     */
#define MODEM_CTRL5_BRCALMODE_Msk         (0xcUL)                   /*!< BRCALMODE (Bitfield-Mask: 0x03)                       */
#define MODEM_CTRL5_BRCALAVG_Pos          (4UL)                     /*!< BRCALAVG (Bit 4)                                      */
#define MODEM_CTRL5_BRCALAVG_Msk          (0x30UL)                  /*!< BRCALAVG (Bitfield-Mask: 0x03)                        */
#define MODEM_CTRL5_DETDEL_Pos            (6UL)                     /*!< DETDEL (Bit 6)                                        */
#define MODEM_CTRL5_DETDEL_Msk            (0x1c0UL)                 /*!< DETDEL (Bitfield-Mask: 0x07)                          */
#define MODEM_CTRL5_TDEDGE_Pos            (9UL)                     /*!< TDEDGE (Bit 9)                                        */
#define MODEM_CTRL5_TDEDGE_Msk            (0x200UL)                 /*!< TDEDGE (Bitfield-Mask: 0x01)                          */
#define MODEM_CTRL5_TREDGE_Pos            (10UL)                    /*!< TREDGE (Bit 10)                                       */
#define MODEM_CTRL5_TREDGE_Msk            (0x400UL)                 /*!< TREDGE (Bitfield-Mask: 0x01)                          */
/* =========================================================  TXBR  ========================================================== */
#define MODEM_TXBR_TXBRNUM_Pos            (0UL)                     /*!< TXBRNUM (Bit 0)                                       */
#define MODEM_TXBR_TXBRNUM_Msk            (0xffffUL)                /*!< TXBRNUM (Bitfield-Mask: 0xffff)                       */
#define MODEM_TXBR_TXBRDEN_Pos            (16UL)                    /*!< TXBRDEN (Bit 16)                                      */
#define MODEM_TXBR_TXBRDEN_Msk            (0xff0000UL)              /*!< TXBRDEN (Bitfield-Mask: 0xff)                         */
/* =========================================================  RXBR  ========================================================== */
#define MODEM_RXBR_RXBRNUM_Pos            (0UL)                     /*!< RXBRNUM (Bit 0)                                       */
#define MODEM_RXBR_RXBRNUM_Msk            (0x1fUL)                  /*!< RXBRNUM (Bitfield-Mask: 0x1f)                         */
#define MODEM_RXBR_RXBRDEN_Pos            (5UL)                     /*!< RXBRDEN (Bit 5)                                       */
#define MODEM_RXBR_RXBRDEN_Msk            (0x3e0UL)                 /*!< RXBRDEN (Bitfield-Mask: 0x1f)                         */
#define MODEM_RXBR_RXBRINT_Pos            (10UL)                    /*!< RXBRINT (Bit 10)                                      */
#define MODEM_RXBR_RXBRINT_Msk            (0x1c00UL)                /*!< RXBRINT (Bitfield-Mask: 0x07)                         */
/* ==========================================================  CF  =========================================================== */
#define MODEM_CF_DEC0_Pos                 (0UL)                     /*!< DEC0 (Bit 0)                                          */
#define MODEM_CF_DEC0_Msk                 (0x7UL)                   /*!< DEC0 (Bitfield-Mask: 0x07)                            */
#define MODEM_CF_DEC1_Pos                 (3UL)                     /*!< DEC1 (Bit 3)                                          */
#define MODEM_CF_DEC1_Msk                 (0x1fff8UL)               /*!< DEC1 (Bitfield-Mask: 0x3fff)                          */
#define MODEM_CF_DEC2_Pos                 (17UL)                    /*!< DEC2 (Bit 17)                                         */
#define MODEM_CF_DEC2_Msk                 (0x7e0000UL)              /*!< DEC2 (Bitfield-Mask: 0x3f)                            */
#define MODEM_CF_CFOSR_Pos                (23UL)                    /*!< CFOSR (Bit 23)                                        */
#define MODEM_CF_CFOSR_Msk                (0x3800000UL)             /*!< CFOSR (Bitfield-Mask: 0x07)                           */
#define MODEM_CF_DEC1GAIN_Pos             (26UL)                    /*!< DEC1GAIN (Bit 26)                                     */
#define MODEM_CF_DEC1GAIN_Msk             (0xc000000UL)             /*!< DEC1GAIN (Bitfield-Mask: 0x03)                        */
#define MODEM_CF_RESYNCRESETTIMING_Pos    (28UL)                    /*!< RESYNCRESETTIMING (Bit 28)                            */
#define MODEM_CF_RESYNCRESETTIMING_Msk    (0x10000000UL)            /*!< RESYNCRESETTIMING (Bitfield-Mask: 0x01)               */
#define MODEM_CF_RESYNCBYPASS_Pos         (29UL)                    /*!< RESYNCBYPASS (Bit 29)                                 */
#define MODEM_CF_RESYNCBYPASS_Msk         (0x20000000UL)            /*!< RESYNCBYPASS (Bitfield-Mask: 0x01)                    */
/* ==========================================================  PRE  ========================================================== */
#define MODEM_PRE_BASE_Pos                (0UL)                     /*!< BASE (Bit 0)                                          */
#define MODEM_PRE_BASE_Msk                (0xfUL)                   /*!< BASE (Bitfield-Mask: 0x0f)                            */
#define MODEM_PRE_BASEBITS_Pos            (4UL)                     /*!< BASEBITS (Bit 4)                                      */
#define MODEM_PRE_BASEBITS_Msk            (0x30UL)                  /*!< BASEBITS (Bitfield-Mask: 0x03)                        */
#define MODEM_PRE_PRESYMB4FSK_Pos         (6UL)                     /*!< PRESYMB4FSK (Bit 6)                                   */
#define MODEM_PRE_PRESYMB4FSK_Msk         (0x40UL)                  /*!< PRESYMB4FSK (Bitfield-Mask: 0x01)                     */
#define MODEM_PRE_PREERRORS_Pos           (7UL)                     /*!< PREERRORS (Bit 7)                                     */
#define MODEM_PRE_PREERRORS_Msk           (0x780UL)                 /*!< PREERRORS (Bitfield-Mask: 0x0f)                       */
#define MODEM_PRE_DSSSPRE_Pos             (11UL)                    /*!< DSSSPRE (Bit 11)                                      */
#define MODEM_PRE_DSSSPRE_Msk             (0x800UL)                 /*!< DSSSPRE (Bitfield-Mask: 0x01)                         */
#define MODEM_PRE_SYNCSYMB4FSK_Pos        (12UL)                    /*!< SYNCSYMB4FSK (Bit 12)                                 */
#define MODEM_PRE_SYNCSYMB4FSK_Msk        (0x1000UL)                /*!< SYNCSYMB4FSK (Bitfield-Mask: 0x01)                    */
#define MODEM_PRE_TXBASES_Pos             (16UL)                    /*!< TXBASES (Bit 16)                                      */
#define MODEM_PRE_TXBASES_Msk             (0xffff0000UL)            /*!< TXBASES (Bitfield-Mask: 0xffff)                       */
/* =========================================================  SYNC0  ========================================================= */
#define MODEM_SYNC0_SYNC0_Pos             (0UL)                     /*!< SYNC0 (Bit 0)                                         */
#define MODEM_SYNC0_SYNC0_Msk             (0xffffffffUL)            /*!< SYNC0 (Bitfield-Mask: 0xffffffff)                     */
/* =========================================================  SYNC1  ========================================================= */
#define MODEM_SYNC1_SYNC1_Pos             (0UL)                     /*!< SYNC1 (Bit 0)                                         */
#define MODEM_SYNC1_SYNC1_Msk             (0xffffffffUL)            /*!< SYNC1 (Bitfield-Mask: 0xffffffff)                     */
/* ========================================================  TIMING  ========================================================= */
#define MODEM_TIMING_TIMTHRESH_Pos        (0UL)                     /*!< TIMTHRESH (Bit 0)                                     */
#define MODEM_TIMING_TIMTHRESH_Msk        (0xffUL)                  /*!< TIMTHRESH (Bitfield-Mask: 0xff)                       */
#define MODEM_TIMING_TIMINGBASES_Pos      (8UL)                     /*!< TIMINGBASES (Bit 8)                                   */
#define MODEM_TIMING_TIMINGBASES_Msk      (0xf00UL)                 /*!< TIMINGBASES (Bitfield-Mask: 0x0f)                     */
#define MODEM_TIMING_ADDTIMSEQ_Pos        (12UL)                    /*!< ADDTIMSEQ (Bit 12)                                    */
#define MODEM_TIMING_ADDTIMSEQ_Msk        (0xf000UL)                /*!< ADDTIMSEQ (Bitfield-Mask: 0x0f)                       */
#define MODEM_TIMING_TIMSEQINVEN_Pos      (16UL)                    /*!< TIMSEQINVEN (Bit 16)                                  */
#define MODEM_TIMING_TIMSEQINVEN_Msk      (0x10000UL)               /*!< TIMSEQINVEN (Bitfield-Mask: 0x01)                     */
#define MODEM_TIMING_TIMSEQSYNC_Pos       (17UL)                    /*!< TIMSEQSYNC (Bit 17)                                   */
#define MODEM_TIMING_TIMSEQSYNC_Msk       (0x20000UL)               /*!< TIMSEQSYNC (Bitfield-Mask: 0x01)                      */
#define MODEM_TIMING_FDM0THRESH_Pos       (18UL)                    /*!< FDM0THRESH (Bit 18)                                   */
#define MODEM_TIMING_FDM0THRESH_Msk       (0x1c0000UL)              /*!< FDM0THRESH (Bitfield-Mask: 0x07)                      */
#define MODEM_TIMING_OFFSUBNUM_Pos        (21UL)                    /*!< OFFSUBNUM (Bit 21)                                    */
#define MODEM_TIMING_OFFSUBNUM_Msk        (0x1e00000UL)             /*!< OFFSUBNUM (Bitfield-Mask: 0x0f)                       */
#define MODEM_TIMING_OFFSUBDEN_Pos        (25UL)                    /*!< OFFSUBDEN (Bit 25)                                    */
#define MODEM_TIMING_OFFSUBDEN_Msk        (0x1e000000UL)            /*!< OFFSUBDEN (Bitfield-Mask: 0x0f)                       */
#define MODEM_TIMING_TSAGCDEL_Pos         (29UL)                    /*!< TSAGCDEL (Bit 29)                                     */
#define MODEM_TIMING_TSAGCDEL_Msk         (0x20000000UL)            /*!< TSAGCDEL (Bitfield-Mask: 0x01)                        */
#define MODEM_TIMING_FASTRESYNC_Pos       (30UL)                    /*!< FASTRESYNC (Bit 30)                                   */
#define MODEM_TIMING_FASTRESYNC_Msk       (0xc0000000UL)            /*!< FASTRESYNC (Bitfield-Mask: 0x03)                      */
/* =========================================================  DSSS0  ========================================================= */
#define MODEM_DSSS0_DSSS0_Pos             (0UL)                     /*!< DSSS0 (Bit 0)                                         */
#define MODEM_DSSS0_DSSS0_Msk             (0xffffffffUL)            /*!< DSSS0 (Bitfield-Mask: 0xffffffff)                     */
/* =======================================================  MODINDEX  ======================================================== */
#define MODEM_MODINDEX_MODINDEXM_Pos      (0UL)                     /*!< MODINDEXM (Bit 0)                                     */
#define MODEM_MODINDEX_MODINDEXM_Msk      (0x1fUL)                  /*!< MODINDEXM (Bitfield-Mask: 0x1f)                       */
#define MODEM_MODINDEX_MODINDEXE_Pos      (5UL)                     /*!< MODINDEXE (Bit 5)                                     */
#define MODEM_MODINDEX_MODINDEXE_Msk      (0x3e0UL)                 /*!< MODINDEXE (Bitfield-Mask: 0x1f)                       */
#define MODEM_MODINDEX_FREQGAINE_Pos      (16UL)                    /*!< FREQGAINE (Bit 16)                                    */
#define MODEM_MODINDEX_FREQGAINE_Msk      (0x70000UL)               /*!< FREQGAINE (Bitfield-Mask: 0x07)                       */
#define MODEM_MODINDEX_FREQGAINM_Pos      (19UL)                    /*!< FREQGAINM (Bit 19)                                    */
#define MODEM_MODINDEX_FREQGAINM_Msk      (0x380000UL)              /*!< FREQGAINM (Bitfield-Mask: 0x07)                       */
/* ==========================================================  AFC  ========================================================== */
#define MODEM_AFC_AFCSCALEM_Pos           (0UL)                     /*!< AFCSCALEM (Bit 0)                                     */
#define MODEM_AFC_AFCSCALEM_Msk           (0x1fUL)                  /*!< AFCSCALEM (Bitfield-Mask: 0x1f)                       */
#define MODEM_AFC_AFCSCALEE_Pos           (5UL)                     /*!< AFCSCALEE (Bit 5)                                     */
#define MODEM_AFC_AFCSCALEE_Msk           (0xe0UL)                  /*!< AFCSCALEE (Bitfield-Mask: 0x07)                       */
#define MODEM_AFC_AFCRXMODE_Pos           (10UL)                    /*!< AFCRXMODE (Bit 10)                                    */
#define MODEM_AFC_AFCRXMODE_Msk           (0x1c00UL)                /*!< AFCRXMODE (Bitfield-Mask: 0x07)                       */
#define MODEM_AFC_AFCTXMODE_Pos           (13UL)                    /*!< AFCTXMODE (Bit 13)                                    */
#define MODEM_AFC_AFCTXMODE_Msk           (0x6000UL)                /*!< AFCTXMODE (Bitfield-Mask: 0x03)                       */
#define MODEM_AFC_AFCRXCLR_Pos            (15UL)                    /*!< AFCRXCLR (Bit 15)                                     */
#define MODEM_AFC_AFCRXCLR_Msk            (0x8000UL)                /*!< AFCRXCLR (Bitfield-Mask: 0x01)                        */
#define MODEM_AFC_AFCDEL_Pos              (16UL)                    /*!< AFCDEL (Bit 16)                                       */
#define MODEM_AFC_AFCDEL_Msk              (0x1f0000UL)              /*!< AFCDEL (Bitfield-Mask: 0x1f)                          */
#define MODEM_AFC_AFCAVGPER_Pos           (21UL)                    /*!< AFCAVGPER (Bit 21)                                    */
#define MODEM_AFC_AFCAVGPER_Msk           (0xe00000UL)              /*!< AFCAVGPER (Bitfield-Mask: 0x07)                       */
/* =======================================================  AFCADJLIM  ======================================================= */
#define MODEM_AFCADJLIM_AFCADJLIM_Pos     (0UL)                     /*!< AFCADJLIM (Bit 0)                                     */
#define MODEM_AFCADJLIM_AFCADJLIM_Msk     (0x3ffffUL)               /*!< AFCADJLIM (Bitfield-Mask: 0x3ffff)                    */
/* =======================================================  SHAPING0  ======================================================== */
#define MODEM_SHAPING0_COEFF0_Pos         (0UL)                     /*!< COEFF0 (Bit 0)                                        */
#define MODEM_SHAPING0_COEFF0_Msk         (0xffUL)                  /*!< COEFF0 (Bitfield-Mask: 0xff)                          */
#define MODEM_SHAPING0_COEFF1_Pos         (8UL)                     /*!< COEFF1 (Bit 8)                                        */
#define MODEM_SHAPING0_COEFF1_Msk         (0xff00UL)                /*!< COEFF1 (Bitfield-Mask: 0xff)                          */
#define MODEM_SHAPING0_COEFF2_Pos         (16UL)                    /*!< COEFF2 (Bit 16)                                       */
#define MODEM_SHAPING0_COEFF2_Msk         (0xff0000UL)              /*!< COEFF2 (Bitfield-Mask: 0xff)                          */
#define MODEM_SHAPING0_COEFF3_Pos         (24UL)                    /*!< COEFF3 (Bit 24)                                       */
#define MODEM_SHAPING0_COEFF3_Msk         (0xff000000UL)            /*!< COEFF3 (Bitfield-Mask: 0xff)                          */
/* =======================================================  SHAPING1  ======================================================== */
#define MODEM_SHAPING1_COEFF4_Pos         (0UL)                     /*!< COEFF4 (Bit 0)                                        */
#define MODEM_SHAPING1_COEFF4_Msk         (0xffUL)                  /*!< COEFF4 (Bitfield-Mask: 0xff)                          */
#define MODEM_SHAPING1_COEFF5_Pos         (8UL)                     /*!< COEFF5 (Bit 8)                                        */
#define MODEM_SHAPING1_COEFF5_Msk         (0xff00UL)                /*!< COEFF5 (Bitfield-Mask: 0xff)                          */
#define MODEM_SHAPING1_COEFF6_Pos         (16UL)                    /*!< COEFF6 (Bit 16)                                       */
#define MODEM_SHAPING1_COEFF6_Msk         (0xff0000UL)              /*!< COEFF6 (Bitfield-Mask: 0xff)                          */
#define MODEM_SHAPING1_COEFF7_Pos         (24UL)                    /*!< COEFF7 (Bit 24)                                       */
#define MODEM_SHAPING1_COEFF7_Msk         (0xff000000UL)            /*!< COEFF7 (Bitfield-Mask: 0xff)                          */
/* =======================================================  SHAPING2  ======================================================== */
#define MODEM_SHAPING2_COEFF8_Pos         (0UL)                     /*!< COEFF8 (Bit 0)                                        */
#define MODEM_SHAPING2_COEFF8_Msk         (0xffUL)                  /*!< COEFF8 (Bitfield-Mask: 0xff)                          */
/* =======================================================  RAMPCTRL  ======================================================== */
#define MODEM_RAMPCTRL_RAMPRATE0_Pos      (0UL)                     /*!< RAMPRATE0 (Bit 0)                                     */
#define MODEM_RAMPCTRL_RAMPRATE0_Msk      (0xfUL)                   /*!< RAMPRATE0 (Bitfield-Mask: 0x0f)                       */
#define MODEM_RAMPCTRL_RAMPRATE0					(MODEM->RAMPCTRL & MODEM_RAMPCTRL_RAMPRATE0_Msk) >> MODEM_RAMPCTRL_RAMPRATE0_Pos
#define MODEM_RAMPCTRL_RAMPRATE1_Pos      (4UL)                     /*!< RAMPRATE1 (Bit 4)                                     */
#define MODEM_RAMPCTRL_RAMPRATE1_Msk      (0xf0UL)                  /*!< RAMPRATE1 (Bitfield-Mask: 0x0f)                       */
#define MODEM_RAMPCTRL_RAMPRATE1					(MODEM->RAMPCTRL & MODEM_RAMPCTRL_RAMPRATE1_Msk) >> MODEM_RAMPCTRL_RAMPRATE1_Pos
#define MODEM_RAMPCTRL_RAMPRATE2_Pos      (8UL)                     /*!< RAMPRATE2 (Bit 8)                                     */
#define MODEM_RAMPCTRL_RAMPRATE2_Msk      (0xf00UL)                 /*!< RAMPRATE2 (Bitfield-Mask: 0x0f)                       */
#define MODEM_RAMPCTRL_RAMPRATE2					(MODEM->RAMPCTRL & MODEM_RAMPCTRL_RAMPRATE2_Msk) >> MODEM_RAMPCTRL_RAMPRATE2_Pos
#define MODEM_RAMPCTRL_RAMPDIS_Pos        (23UL)                    /*!< RAMPDIS (Bit 23)                                      */
#define MODEM_RAMPCTRL_RAMPDIS_Msk        (0x800000UL)              /*!< RAMPDIS (Bitfield-Mask: 0x01)                         */
#define MODEM_RAMPCTRL_RAMPVAL_Pos        (24UL)                    /*!< RAMPVAL (Bit 24)                                      */
#define MODEM_RAMPCTRL_RAMPVAL_Msk        (0xff000000UL)            /*!< RAMPVAL (Bitfield-Mask: 0xff)                         */
/* ========================================================  RAMPLEV  ======================================================== */
#define MODEM_RAMPLEV_RAMPLEV0_Pos        (0UL)                     /*!< RAMPLEV0 (Bit 0)                                      */
#define MODEM_RAMPLEV_RAMPLEV0_Msk        (0xffUL)                  /*!< RAMPLEV0 (Bitfield-Mask: 0xff)                        */
#define MODEM_RAMPLEV_RAMPLEV0						(MODEM->RAMPLEV & MODEM_RAMPLEV_RAMPLEV0_Msk) >> MODEM_RAMPLEV_RAMPLEV0_Pos
#define MODEM_RAMPLEV_RAMPLEV1_Pos        (8UL)                     /*!< RAMPLEV1 (Bit 8)                                      */
#define MODEM_RAMPLEV_RAMPLEV1_Msk        (0xff00UL)                /*!< RAMPLEV1 (Bitfield-Mask: 0xff)                        */
#define MODEM_RAMPLEV_RAMPLEV1						(MODEM->RAMPLEV & MODEM_RAMPLEV_RAMPLEV1_Msk) >> MODEM_RAMPLEV_RAMPLEV1_Pos
#define MODEM_RAMPLEV_RAMPLEV2_Pos        (16UL)                    /*!< RAMPLEV2 (Bit 16)                                     */
#define MODEM_RAMPLEV_RAMPLEV2_Msk        (0xff0000UL)              /*!< RAMPLEV2 (Bitfield-Mask: 0xff)                        */
#define MODEM_RAMPLEV_RAMPLEV2						(MODEM->RAMPLEV & MODEM_RAMPLEV_RAMPLEV2_Msk) >> MODEM_RAMPLEV_RAMPLEV2_Pos
/* =======================================================  ROUTEPEN  ======================================================== */
#define MODEM_ROUTEPEN_DINPEN_Pos         (0UL)                     /*!< DINPEN (Bit 0)                                        */
#define MODEM_ROUTEPEN_DINPEN_Msk         (0x1UL)                   /*!< DINPEN (Bitfield-Mask: 0x01)                          */
#define MODEM_ROUTEPEN_DOUTPEN_Pos        (1UL)                     /*!< DOUTPEN (Bit 1)                                       */
#define MODEM_ROUTEPEN_DOUTPEN_Msk        (0x2UL)                   /*!< DOUTPEN (Bitfield-Mask: 0x01)                         */
#define MODEM_ROUTEPEN_DCLKPEN_Pos        (2UL)                     /*!< DCLKPEN (Bit 2)                                       */
#define MODEM_ROUTEPEN_DCLKPEN_Msk        (0x4UL)                   /*!< DCLKPEN (Bitfield-Mask: 0x01)                         */
#define MODEM_ROUTEPEN_ANT0PEN_Pos        (3UL)                     /*!< ANT0PEN (Bit 3)                                       */
#define MODEM_ROUTEPEN_ANT0PEN_Msk        (0x8UL)                   /*!< ANT0PEN (Bitfield-Mask: 0x01)                         */
#define MODEM_ROUTEPEN_ANT1PEN_Pos        (4UL)                     /*!< ANT1PEN (Bit 4)                                       */
#define MODEM_ROUTEPEN_ANT1PEN_Msk        (0x10UL)                  /*!< ANT1PEN (Bitfield-Mask: 0x01)                         */
/* =======================================================  ROUTELOC0  ======================================================= */
#define MODEM_ROUTELOC0_DINLOC_Pos        (0UL)                     /*!< DINLOC (Bit 0)                                        */
#define MODEM_ROUTELOC0_DINLOC_Msk        (0x3fUL)                  /*!< DINLOC (Bitfield-Mask: 0x3f)                          */
#define MODEM_ROUTELOC0_DOUTLOC_Pos       (8UL)                     /*!< DOUTLOC (Bit 8)                                       */
#define MODEM_ROUTELOC0_DOUTLOC_Msk       (0x3f00UL)                /*!< DOUTLOC (Bitfield-Mask: 0x3f)                         */
#define MODEM_ROUTELOC0_DCLKLOC_Pos       (16UL)                    /*!< DCLKLOC (Bit 16)                                      */
#define MODEM_ROUTELOC0_DCLKLOC_Msk       (0x3f0000UL)              /*!< DCLKLOC (Bitfield-Mask: 0x3f)                         */
/* =======================================================  ROUTELOC1  ======================================================= */
#define MODEM_ROUTELOC1_ANT0LOC_Pos       (0UL)                     /*!< ANT0LOC (Bit 0)                                       */
#define MODEM_ROUTELOC1_ANT0LOC_Msk       (0x3fUL)                  /*!< ANT0LOC (Bitfield-Mask: 0x3f)                         */
#define MODEM_ROUTELOC1_ANT1LOC_Pos       (8UL)                     /*!< ANT1LOC (Bit 8)                                       */
#define MODEM_ROUTELOC1_ANT1LOC_Msk       (0x3f00UL)                /*!< ANT1LOC (Bitfield-Mask: 0x3f)                         */
/* ==========================================================  IF  =========================================================== */
#define MODEM_IF_TXFRAMESENT_Pos          (0UL)                     /*!< TXFRAMESENT (Bit 0)                                   */
#define MODEM_IF_TXFRAMESENT_Msk          (0x1UL)                   /*!< TXFRAMESENT (Bitfield-Mask: 0x01)                     */
#define MODEM_IF_TXSYNCSENT_Pos           (1UL)                     /*!< TXSYNCSENT (Bit 1)                                    */
#define MODEM_IF_TXSYNCSENT_Msk           (0x2UL)                   /*!< TXSYNCSENT (Bitfield-Mask: 0x01)                      */
#define MODEM_IF_TXPRESENT_Pos            (2UL)                     /*!< TXPRESENT (Bit 2)                                     */
#define MODEM_IF_TXPRESENT_Msk            (0x4UL)                   /*!< TXPRESENT (Bitfield-Mask: 0x01)                       */
#define MODEM_IF_RXTIMDET_Pos             (8UL)                     /*!< RXTIMDET (Bit 8)                                      */
#define MODEM_IF_RXTIMDET_Msk             (0x100UL)                 /*!< RXTIMDET (Bitfield-Mask: 0x01)                        */
#define MODEM_IF_RXPREDET_Pos             (9UL)                     /*!< RXPREDET (Bit 9)                                      */
#define MODEM_IF_RXPREDET_Msk             (0x200UL)                 /*!< RXPREDET (Bitfield-Mask: 0x01)                        */
#define MODEM_IF_RXFRAMEDET0_Pos          (10UL)                    /*!< RXFRAMEDET0 (Bit 10)                                  */
#define MODEM_IF_RXFRAMEDET0_Msk          (0x400UL)                 /*!< RXFRAMEDET0 (Bitfield-Mask: 0x01)                     */
#define MODEM_IF_RXFRAMEDET1_Pos          (11UL)                    /*!< RXFRAMEDET1 (Bit 11)                                  */
#define MODEM_IF_RXFRAMEDET1_Msk          (0x800UL)                 /*!< RXFRAMEDET1 (Bitfield-Mask: 0x01)                     */
#define MODEM_IF_RXTIMLOST_Pos            (12UL)                    /*!< RXTIMLOST (Bit 12)                                    */
#define MODEM_IF_RXTIMLOST_Msk            (0x1000UL)                /*!< RXTIMLOST (Bitfield-Mask: 0x01)                       */
#define MODEM_IF_RXPRELOST_Pos            (13UL)                    /*!< RXPRELOST (Bit 13)                                    */
#define MODEM_IF_RXPRELOST_Msk            (0x2000UL)                /*!< RXPRELOST (Bitfield-Mask: 0x01)                       */
#define MODEM_IF_RXFRAMEDETOF_Pos         (14UL)                    /*!< RXFRAMEDETOF (Bit 14)                                 */
#define MODEM_IF_RXFRAMEDETOF_Msk         (0x4000UL)                /*!< RXFRAMEDETOF (Bitfield-Mask: 0x01)                    */
#define MODEM_IF_RXTIMNF_Pos              (15UL)                    /*!< RXTIMNF (Bit 15)                                      */
#define MODEM_IF_RXTIMNF_Msk              (0x8000UL)                /*!< RXTIMNF (Bitfield-Mask: 0x01)                         */
/* ==========================================================  IFS  ========================================================== */
#define MODEM_IFS_TXFRAMESENT_Pos         (0UL)                     /*!< TXFRAMESENT (Bit 0)                                   */
#define MODEM_IFS_TXFRAMESENT_Msk         (0x1UL)                   /*!< TXFRAMESENT (Bitfield-Mask: 0x01)                     */
#define MODEM_IFS_TXSYNCSENT_Pos          (1UL)                     /*!< TXSYNCSENT (Bit 1)                                    */
#define MODEM_IFS_TXSYNCSENT_Msk          (0x2UL)                   /*!< TXSYNCSENT (Bitfield-Mask: 0x01)                      */
#define MODEM_IFS_TXPRESENT_Pos           (2UL)                     /*!< TXPRESENT (Bit 2)                                     */
#define MODEM_IFS_TXPRESENT_Msk           (0x4UL)                   /*!< TXPRESENT (Bitfield-Mask: 0x01)                       */
#define MODEM_IFS_RXTIMDET_Pos            (8UL)                     /*!< RXTIMDET (Bit 8)                                      */
#define MODEM_IFS_RXTIMDET_Msk            (0x100UL)                 /*!< RXTIMDET (Bitfield-Mask: 0x01)                        */
#define MODEM_IFS_RXPREDET_Pos            (9UL)                     /*!< RXPREDET (Bit 9)                                      */
#define MODEM_IFS_RXPREDET_Msk            (0x200UL)                 /*!< RXPREDET (Bitfield-Mask: 0x01)                        */
#define MODEM_IFS_RXFRAMEDET0_Pos         (10UL)                    /*!< RXFRAMEDET0 (Bit 10)                                  */
#define MODEM_IFS_RXFRAMEDET0_Msk         (0x400UL)                 /*!< RXFRAMEDET0 (Bitfield-Mask: 0x01)                     */
#define MODEM_IFS_RXFRAMEDET1_Pos         (11UL)                    /*!< RXFRAMEDET1 (Bit 11)                                  */
#define MODEM_IFS_RXFRAMEDET1_Msk         (0x800UL)                 /*!< RXFRAMEDET1 (Bitfield-Mask: 0x01)                     */
#define MODEM_IFS_RXTIMLOST_Pos           (12UL)                    /*!< RXTIMLOST (Bit 12)                                    */
#define MODEM_IFS_RXTIMLOST_Msk           (0x1000UL)                /*!< RXTIMLOST (Bitfield-Mask: 0x01)                       */
#define MODEM_IFS_RXPRELOST_Pos           (13UL)                    /*!< RXPRELOST (Bit 13)                                    */
#define MODEM_IFS_RXPRELOST_Msk           (0x2000UL)                /*!< RXPRELOST (Bitfield-Mask: 0x01)                       */
#define MODEM_IFS_RXFRAMEDETOF_Pos        (14UL)                    /*!< RXFRAMEDETOF (Bit 14)                                 */
#define MODEM_IFS_RXFRAMEDETOF_Msk        (0x4000UL)                /*!< RXFRAMEDETOF (Bitfield-Mask: 0x01)                    */
#define MODEM_IFS_RXTIMNF_Pos             (15UL)                    /*!< RXTIMNF (Bit 15)                                      */
#define MODEM_IFS_RXTIMNF_Msk             (0x8000UL)                /*!< RXTIMNF (Bitfield-Mask: 0x01)                         */
/* ==========================================================  IFC  ========================================================== */
#define MODEM_IFC_TXFRAMESENT_Pos         (0UL)                     /*!< TXFRAMESENT (Bit 0)                                   */
#define MODEM_IFC_TXFRAMESENT_Msk         (0x1UL)                   /*!< TXFRAMESENT (Bitfield-Mask: 0x01)                     */
#define MODEM_IFC_TXSYNCSENT_Pos          (1UL)                     /*!< TXSYNCSENT (Bit 1)                                    */
#define MODEM_IFC_TXSYNCSENT_Msk          (0x2UL)                   /*!< TXSYNCSENT (Bitfield-Mask: 0x01)                      */
#define MODEM_IFC_TXPRESENT_Pos           (2UL)                     /*!< TXPRESENT (Bit 2)                                     */
#define MODEM_IFC_TXPRESENT_Msk           (0x4UL)                   /*!< TXPRESENT (Bitfield-Mask: 0x01)                       */
#define MODEM_IFC_RXTIMDET_Pos            (8UL)                     /*!< RXTIMDET (Bit 8)                                      */
#define MODEM_IFC_RXTIMDET_Msk            (0x100UL)                 /*!< RXTIMDET (Bitfield-Mask: 0x01)                        */
#define MODEM_IFC_RXPREDET_Pos            (9UL)                     /*!< RXPREDET (Bit 9)                                      */
#define MODEM_IFC_RXPREDET_Msk            (0x200UL)                 /*!< RXPREDET (Bitfield-Mask: 0x01)                        */
#define MODEM_IFC_RXFRAMEDET0_Pos         (10UL)                    /*!< RXFRAMEDET0 (Bit 10)                                  */
#define MODEM_IFC_RXFRAMEDET0_Msk         (0x400UL)                 /*!< RXFRAMEDET0 (Bitfield-Mask: 0x01)                     */
#define MODEM_IFC_RXFRAMEDET1_Pos         (11UL)                    /*!< RXFRAMEDET1 (Bit 11)                                  */
#define MODEM_IFC_RXFRAMEDET1_Msk         (0x800UL)                 /*!< RXFRAMEDET1 (Bitfield-Mask: 0x01)                     */
#define MODEM_IFC_RXTIMLOST_Pos           (12UL)                    /*!< RXTIMLOST (Bit 12)                                    */
#define MODEM_IFC_RXTIMLOST_Msk           (0x1000UL)                /*!< RXTIMLOST (Bitfield-Mask: 0x01)                       */
#define MODEM_IFC_RXPRELOST_Pos           (13UL)                    /*!< RXPRELOST (Bit 13)                                    */
#define MODEM_IFC_RXPRELOST_Msk           (0x2000UL)                /*!< RXPRELOST (Bitfield-Mask: 0x01)                       */
#define MODEM_IFC_RXFRAMEDETOF_Pos        (14UL)                    /*!< RXFRAMEDETOF (Bit 14)                                 */
#define MODEM_IFC_RXFRAMEDETOF_Msk        (0x4000UL)                /*!< RXFRAMEDETOF (Bitfield-Mask: 0x01)                    */
#define MODEM_IFC_RXTIMNF_Pos             (15UL)                    /*!< RXTIMNF (Bit 15)                                      */
#define MODEM_IFC_RXTIMNF_Msk             (0x8000UL)                /*!< RXTIMNF (Bitfield-Mask: 0x01)                         */
/* ==========================================================  IEN  ========================================================== */
#define MODEM_IEN_TXFRAMESENT_Pos         (0UL)                     /*!< TXFRAMESENT (Bit 0)                                   */
#define MODEM_IEN_TXFRAMESENT_Msk         (0x1UL)                   /*!< TXFRAMESENT (Bitfield-Mask: 0x01)                     */
#define MODEM_IEN_TXSYNCSENT_Pos          (1UL)                     /*!< TXSYNCSENT (Bit 1)                                    */
#define MODEM_IEN_TXSYNCSENT_Msk          (0x2UL)                   /*!< TXSYNCSENT (Bitfield-Mask: 0x01)                      */
#define MODEM_IEN_TXPRESENT_Pos           (2UL)                     /*!< TXPRESENT (Bit 2)                                     */
#define MODEM_IEN_TXPRESENT_Msk           (0x4UL)                   /*!< TXPRESENT (Bitfield-Mask: 0x01)                       */
#define MODEM_IEN_RXTIMDET_Pos            (8UL)                     /*!< RXTIMDET (Bit 8)                                      */
#define MODEM_IEN_RXTIMDET_Msk            (0x100UL)                 /*!< RXTIMDET (Bitfield-Mask: 0x01)                        */
#define MODEM_IEN_RXPREDET_Pos            (9UL)                     /*!< RXPREDET (Bit 9)                                      */
#define MODEM_IEN_RXPREDET_Msk            (0x200UL)                 /*!< RXPREDET (Bitfield-Mask: 0x01)                        */
#define MODEM_IEN_RXFRAMEDET0_Pos         (10UL)                    /*!< RXFRAMEDET0 (Bit 10)                                  */
#define MODEM_IEN_RXFRAMEDET0_Msk         (0x400UL)                 /*!< RXFRAMEDET0 (Bitfield-Mask: 0x01)                     */
#define MODEM_IEN_RXFRAMEDET1_Pos         (11UL)                    /*!< RXFRAMEDET1 (Bit 11)                                  */
#define MODEM_IEN_RXFRAMEDET1_Msk         (0x800UL)                 /*!< RXFRAMEDET1 (Bitfield-Mask: 0x01)                     */
#define MODEM_IEN_RXTIMLOST_Pos           (12UL)                    /*!< RXTIMLOST (Bit 12)                                    */
#define MODEM_IEN_RXTIMLOST_Msk           (0x1000UL)                /*!< RXTIMLOST (Bitfield-Mask: 0x01)                       */
#define MODEM_IEN_RXPRELOST_Pos           (13UL)                    /*!< RXPRELOST (Bit 13)                                    */
#define MODEM_IEN_RXPRELOST_Msk           (0x2000UL)                /*!< RXPRELOST (Bitfield-Mask: 0x01)                       */
#define MODEM_IEN_RXFRAMEDETOF_Pos        (14UL)                    /*!< RXFRAMEDETOF (Bit 14)                                 */
#define MODEM_IEN_RXFRAMEDETOF_Msk        (0x4000UL)                /*!< RXFRAMEDETOF (Bitfield-Mask: 0x01)                    */
#define MODEM_IEN_RXTIMNF_Pos             (15UL)                    /*!< RXTIMNF (Bit 15)                                      */
#define MODEM_IEN_RXTIMNF_Msk             (0x8000UL)                /*!< RXTIMNF (Bitfield-Mask: 0x01)                         */
/* ==========================================================  CMD  ========================================================== */
#define MODEM_CMD_PRESTOP_Pos             (0UL)                     /*!< PRESTOP (Bit 0)                                       */
#define MODEM_CMD_PRESTOP_Msk             (0x1UL)                   /*!< PRESTOP (Bitfield-Mask: 0x01)                         */
#define MODEM_CMD_AFCTXLOCK_Pos           (3UL)                     /*!< AFCTXLOCK (Bit 3)                                     */
#define MODEM_CMD_AFCTXLOCK_Msk           (0x8UL)                   /*!< AFCTXLOCK (Bitfield-Mask: 0x01)                       */
#define MODEM_CMD_AFCTXCLEAR_Pos          (5UL)                     /*!< AFCTXCLEAR (Bit 5)                                    */
#define MODEM_CMD_AFCTXCLEAR_Msk          (0x20UL)                  /*!< AFCTXCLEAR (Bitfield-Mask: 0x01)                      */
#define MODEM_CMD_AFCRXCLEAR_Pos          (4UL)                     /*!< AFCRXCLEAR (Bit 4)                                    */
#define MODEM_CMD_AFCRXCLEAR_Msk          (0x10UL)                  /*!< AFCRXCLEAR (Bitfield-Mask: 0x01)                      */
/* ========================================================  DCCOMP  ========================================================= */
#define MODEM_DCCOMP_DCESTIEN_Pos         (0UL)                     /*!< DCESTIEN (Bit 0)                                      */
#define MODEM_DCCOMP_DCESTIEN_Msk         (0x1UL)                   /*!< DCESTIEN (Bitfield-Mask: 0x01)                        */
#define MODEM_DCCOMP_DCCOMPEN_Pos         (1UL)                     /*!< DCCOMPEN (Bit 1)                                      */
#define MODEM_DCCOMP_DCCOMPEN_Msk         (0x2UL)                   /*!< DCCOMPEN (Bitfield-Mask: 0x01)                        */
#define MODEM_DCCOMP_DCRSTEN_Pos          (2UL)                     /*!< DCRSTEN (Bit 2)                                       */
#define MODEM_DCCOMP_DCRSTEN_Msk          (0x4UL)                   /*!< DCRSTEN (Bitfield-Mask: 0x01)                         */
#define MODEM_DCCOMP_DCCOMPFREEZE_Pos     (3UL)                     /*!< DCCOMPFREEZE (Bit 3)                                  */
#define MODEM_DCCOMP_DCCOMPFREEZE_Msk     (0x8UL)                   /*!< DCCOMPFREEZE (Bitfield-Mask: 0x01)                    */
#define MODEM_DCCOMP_DCCOMPGEAR_Pos       (4UL)                     /*!< DCCOMPGEAR (Bit 4)                                    */
#define MODEM_DCCOMP_DCCOMPGEAR_Msk       (0x70UL)                  /*!< DCCOMPGEAR (Bitfield-Mask: 0x07)                      */
#define MODEM_DCCOMP_DCLIMIT_Pos          (7UL)                     /*!< DCLIMIT (Bit 7)                                       */
#define MODEM_DCCOMP_DCLIMIT_Msk          (0x180UL)                 /*!< DCLIMIT (Bitfield-Mask: 0x03)                         */
/* ====================================================  DCCOMPFILTINIT  ===================================================== */
#define MODEM_DCCOMPFILTINIT_DCCOMPINITVALI_Pos (0UL)               /*!< DCCOMPINITVALI (Bit 0)                                */
#define MODEM_DCCOMPFILTINIT_DCCOMPINITVALI_Msk (0x7fffUL)          /*!< DCCOMPINITVALI (Bitfield-Mask: 0x7fff)                */
#define MODEM_DCCOMPFILTINIT_DCCOMPINITVALQ_Pos (15UL)              /*!< DCCOMPINITVALQ (Bit 15)                               */
#define MODEM_DCCOMPFILTINIT_DCCOMPINITVALQ_Msk (0x3fff8000UL)      /*!< DCCOMPINITVALQ (Bitfield-Mask: 0x7fff)                */
#define MODEM_DCCOMPFILTINIT_DCCOMPINIT_Pos (30UL)                  /*!< DCCOMPINIT (Bit 30)                                   */
#define MODEM_DCCOMPFILTINIT_DCCOMPINIT_Msk (0x40000000UL)          /*!< DCCOMPINIT (Bitfield-Mask: 0x01)                      */
/* ========================================================  DCESTI  ========================================================= */
#define MODEM_DCESTI_DCCOMPESTIVALI_Pos   (0UL)                     /*!< DCCOMPESTIVALI (Bit 0)                                */
#define MODEM_DCESTI_DCCOMPESTIVALI_Msk   (0x7fffUL)                /*!< DCCOMPESTIVALI (Bitfield-Mask: 0x7fff)                */
#define MODEM_DCESTI_DCCOMPESTIVALQ_Pos   (15UL)                    /*!< DCCOMPESTIVALQ (Bit 15)                               */
#define MODEM_DCESTI_DCCOMPESTIVALQ_Msk   (0x3fff8000UL)            /*!< DCCOMPESTIVALQ (Bitfield-Mask: 0x7fff)                */
/* =====================================================  RAM0_RAMDATA  ====================================================== */
#define MODEM_RAM0_RAMDATA_DATA_Pos       (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM0_RAMDATA_DATA_Msk       (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM1_RAMDATA  ====================================================== */
#define MODEM_RAM1_RAMDATA_DATA_Pos       (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM1_RAMDATA_DATA_Msk       (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM2_RAMDATA  ====================================================== */
#define MODEM_RAM2_RAMDATA_DATA_Pos       (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM2_RAMDATA_DATA_Msk       (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM3_RAMDATA  ====================================================== */
#define MODEM_RAM3_RAMDATA_DATA_Pos       (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM3_RAMDATA_DATA_Msk       (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM4_RAMDATA  ====================================================== */
#define MODEM_RAM4_RAMDATA_DATA_Pos       (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM4_RAMDATA_DATA_Msk       (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM5_RAMDATA  ====================================================== */
#define MODEM_RAM5_RAMDATA_DATA_Pos       (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM5_RAMDATA_DATA_Msk       (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM6_RAMDATA  ====================================================== */
#define MODEM_RAM6_RAMDATA_DATA_Pos       (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM6_RAMDATA_DATA_Msk       (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM7_RAMDATA  ====================================================== */
#define MODEM_RAM7_RAMDATA_DATA_Pos       (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM7_RAMDATA_DATA_Msk       (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM8_RAMDATA  ====================================================== */
#define MODEM_RAM8_RAMDATA_DATA_Pos       (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM8_RAMDATA_DATA_Msk       (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM9_RAMDATA  ====================================================== */
#define MODEM_RAM9_RAMDATA_DATA_Pos       (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM9_RAMDATA_DATA_Msk       (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM10_RAMDATA  ===================================================== */
#define MODEM_RAM10_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM10_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM11_RAMDATA  ===================================================== */
#define MODEM_RAM11_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM11_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM12_RAMDATA  ===================================================== */
#define MODEM_RAM12_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM12_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM13_RAMDATA  ===================================================== */
#define MODEM_RAM13_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM13_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM14_RAMDATA  ===================================================== */
#define MODEM_RAM14_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM14_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM15_RAMDATA  ===================================================== */
#define MODEM_RAM15_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM15_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM16_RAMDATA  ===================================================== */
#define MODEM_RAM16_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM16_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM17_RAMDATA  ===================================================== */
#define MODEM_RAM17_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM17_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM18_RAMDATA  ===================================================== */
#define MODEM_RAM18_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM18_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM19_RAMDATA  ===================================================== */
#define MODEM_RAM19_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM19_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM20_RAMDATA  ===================================================== */
#define MODEM_RAM20_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM20_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM21_RAMDATA  ===================================================== */
#define MODEM_RAM21_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM21_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM22_RAMDATA  ===================================================== */
#define MODEM_RAM22_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM22_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM23_RAMDATA  ===================================================== */
#define MODEM_RAM23_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM23_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM24_RAMDATA  ===================================================== */
#define MODEM_RAM24_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM24_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM25_RAMDATA  ===================================================== */
#define MODEM_RAM25_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM25_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM26_RAMDATA  ===================================================== */
#define MODEM_RAM26_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM26_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM27_RAMDATA  ===================================================== */
#define MODEM_RAM27_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM27_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM28_RAMDATA  ===================================================== */
#define MODEM_RAM28_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM28_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM29_RAMDATA  ===================================================== */
#define MODEM_RAM29_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM29_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM30_RAMDATA  ===================================================== */
#define MODEM_RAM30_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM30_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM31_RAMDATA  ===================================================== */
#define MODEM_RAM31_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM31_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM32_RAMDATA  ===================================================== */
#define MODEM_RAM32_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM32_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM33_RAMDATA  ===================================================== */
#define MODEM_RAM33_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM33_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM34_RAMDATA  ===================================================== */
#define MODEM_RAM34_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM34_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM35_RAMDATA  ===================================================== */
#define MODEM_RAM35_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM35_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM36_RAMDATA  ===================================================== */
#define MODEM_RAM36_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM36_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM37_RAMDATA  ===================================================== */
#define MODEM_RAM37_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM37_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM38_RAMDATA  ===================================================== */
#define MODEM_RAM38_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM38_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM39_RAMDATA  ===================================================== */
#define MODEM_RAM39_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM39_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM40_RAMDATA  ===================================================== */
#define MODEM_RAM40_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM40_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM41_RAMDATA  ===================================================== */
#define MODEM_RAM41_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM41_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM42_RAMDATA  ===================================================== */
#define MODEM_RAM42_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM42_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM43_RAMDATA  ===================================================== */
#define MODEM_RAM43_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM43_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM44_RAMDATA  ===================================================== */
#define MODEM_RAM44_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM44_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM45_RAMDATA  ===================================================== */
#define MODEM_RAM45_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM45_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM46_RAMDATA  ===================================================== */
#define MODEM_RAM46_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM46_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM47_RAMDATA  ===================================================== */
#define MODEM_RAM47_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM47_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM48_RAMDATA  ===================================================== */
#define MODEM_RAM48_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM48_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM49_RAMDATA  ===================================================== */
#define MODEM_RAM49_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM49_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM50_RAMDATA  ===================================================== */
#define MODEM_RAM50_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM50_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM51_RAMDATA  ===================================================== */
#define MODEM_RAM51_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM51_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM52_RAMDATA  ===================================================== */
#define MODEM_RAM52_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM52_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM53_RAMDATA  ===================================================== */
#define MODEM_RAM53_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM53_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM54_RAMDATA  ===================================================== */
#define MODEM_RAM54_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM54_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM55_RAMDATA  ===================================================== */
#define MODEM_RAM55_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM55_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM56_RAMDATA  ===================================================== */
#define MODEM_RAM56_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM56_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM57_RAMDATA  ===================================================== */
#define MODEM_RAM57_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM57_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM58_RAMDATA  ===================================================== */
#define MODEM_RAM58_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM58_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM59_RAMDATA  ===================================================== */
#define MODEM_RAM59_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM59_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM60_RAMDATA  ===================================================== */
#define MODEM_RAM60_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM60_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM61_RAMDATA  ===================================================== */
#define MODEM_RAM61_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM61_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM62_RAMDATA  ===================================================== */
#define MODEM_RAM62_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM62_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM63_RAMDATA  ===================================================== */
#define MODEM_RAM63_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM63_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM64_RAMDATA  ===================================================== */
#define MODEM_RAM64_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM64_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM65_RAMDATA  ===================================================== */
#define MODEM_RAM65_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM65_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM66_RAMDATA  ===================================================== */
#define MODEM_RAM66_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM66_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM67_RAMDATA  ===================================================== */
#define MODEM_RAM67_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM67_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM68_RAMDATA  ===================================================== */
#define MODEM_RAM68_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM68_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM69_RAMDATA  ===================================================== */
#define MODEM_RAM69_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM69_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM70_RAMDATA  ===================================================== */
#define MODEM_RAM70_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM70_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM71_RAMDATA  ===================================================== */
#define MODEM_RAM71_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM71_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM72_RAMDATA  ===================================================== */
#define MODEM_RAM72_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM72_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM73_RAMDATA  ===================================================== */
#define MODEM_RAM73_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM73_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM74_RAMDATA  ===================================================== */
#define MODEM_RAM74_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM74_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM75_RAMDATA  ===================================================== */
#define MODEM_RAM75_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM75_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM76_RAMDATA  ===================================================== */
#define MODEM_RAM76_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM76_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM77_RAMDATA  ===================================================== */
#define MODEM_RAM77_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM77_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM78_RAMDATA  ===================================================== */
#define MODEM_RAM78_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM78_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM79_RAMDATA  ===================================================== */
#define MODEM_RAM79_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM79_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM80_RAMDATA  ===================================================== */
#define MODEM_RAM80_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM80_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM81_RAMDATA  ===================================================== */
#define MODEM_RAM81_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM81_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM82_RAMDATA  ===================================================== */
#define MODEM_RAM82_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM82_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM83_RAMDATA  ===================================================== */
#define MODEM_RAM83_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM83_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM84_RAMDATA  ===================================================== */
#define MODEM_RAM84_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM84_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM85_RAMDATA  ===================================================== */
#define MODEM_RAM85_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM85_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM86_RAMDATA  ===================================================== */
#define MODEM_RAM86_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM86_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM87_RAMDATA  ===================================================== */
#define MODEM_RAM87_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM87_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM88_RAMDATA  ===================================================== */
#define MODEM_RAM88_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM88_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM89_RAMDATA  ===================================================== */
#define MODEM_RAM89_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM89_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM90_RAMDATA  ===================================================== */
#define MODEM_RAM90_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM90_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM91_RAMDATA  ===================================================== */
#define MODEM_RAM91_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM91_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM92_RAMDATA  ===================================================== */
#define MODEM_RAM92_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM92_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM93_RAMDATA  ===================================================== */
#define MODEM_RAM93_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM93_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM94_RAMDATA  ===================================================== */
#define MODEM_RAM94_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM94_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM95_RAMDATA  ===================================================== */
#define MODEM_RAM95_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM95_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM96_RAMDATA  ===================================================== */
#define MODEM_RAM96_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM96_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM97_RAMDATA  ===================================================== */
#define MODEM_RAM97_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM97_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM98_RAMDATA  ===================================================== */
#define MODEM_RAM98_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM98_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* =====================================================  RAM99_RAMDATA  ===================================================== */
#define MODEM_RAM99_RAMDATA_DATA_Pos      (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM99_RAMDATA_DATA_Msk      (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM100_RAMDATA  ===================================================== */
#define MODEM_RAM100_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM100_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM101_RAMDATA  ===================================================== */
#define MODEM_RAM101_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM101_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM102_RAMDATA  ===================================================== */
#define MODEM_RAM102_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM102_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM103_RAMDATA  ===================================================== */
#define MODEM_RAM103_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM103_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM104_RAMDATA  ===================================================== */
#define MODEM_RAM104_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM104_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM105_RAMDATA  ===================================================== */
#define MODEM_RAM105_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM105_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM106_RAMDATA  ===================================================== */
#define MODEM_RAM106_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM106_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM107_RAMDATA  ===================================================== */
#define MODEM_RAM107_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM107_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM108_RAMDATA  ===================================================== */
#define MODEM_RAM108_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM108_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM109_RAMDATA  ===================================================== */
#define MODEM_RAM109_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM109_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM110_RAMDATA  ===================================================== */
#define MODEM_RAM110_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM110_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM111_RAMDATA  ===================================================== */
#define MODEM_RAM111_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM111_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM112_RAMDATA  ===================================================== */
#define MODEM_RAM112_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM112_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM113_RAMDATA  ===================================================== */
#define MODEM_RAM113_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM113_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM114_RAMDATA  ===================================================== */
#define MODEM_RAM114_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM114_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM115_RAMDATA  ===================================================== */
#define MODEM_RAM115_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM115_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM116_RAMDATA  ===================================================== */
#define MODEM_RAM116_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM116_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM117_RAMDATA  ===================================================== */
#define MODEM_RAM117_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM117_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM118_RAMDATA  ===================================================== */
#define MODEM_RAM118_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM118_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM119_RAMDATA  ===================================================== */
#define MODEM_RAM119_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM119_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM120_RAMDATA  ===================================================== */
#define MODEM_RAM120_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM120_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM121_RAMDATA  ===================================================== */
#define MODEM_RAM121_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM121_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM122_RAMDATA  ===================================================== */
#define MODEM_RAM122_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM122_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM123_RAMDATA  ===================================================== */
#define MODEM_RAM123_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM123_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM124_RAMDATA  ===================================================== */
#define MODEM_RAM124_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM124_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM125_RAMDATA  ===================================================== */
#define MODEM_RAM125_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM125_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM126_RAMDATA  ===================================================== */
#define MODEM_RAM126_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM126_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM127_RAMDATA  ===================================================== */
#define MODEM_RAM127_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM127_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM128_RAMDATA  ===================================================== */
#define MODEM_RAM128_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM128_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM129_RAMDATA  ===================================================== */
#define MODEM_RAM129_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM129_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM130_RAMDATA  ===================================================== */
#define MODEM_RAM130_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM130_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM131_RAMDATA  ===================================================== */
#define MODEM_RAM131_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM131_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM132_RAMDATA  ===================================================== */
#define MODEM_RAM132_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM132_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM133_RAMDATA  ===================================================== */
#define MODEM_RAM133_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM133_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM134_RAMDATA  ===================================================== */
#define MODEM_RAM134_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM134_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM135_RAMDATA  ===================================================== */
#define MODEM_RAM135_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM135_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM136_RAMDATA  ===================================================== */
#define MODEM_RAM136_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM136_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM137_RAMDATA  ===================================================== */
#define MODEM_RAM137_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM137_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM138_RAMDATA  ===================================================== */
#define MODEM_RAM138_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM138_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM139_RAMDATA  ===================================================== */
#define MODEM_RAM139_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM139_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM140_RAMDATA  ===================================================== */
#define MODEM_RAM140_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM140_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM141_RAMDATA  ===================================================== */
#define MODEM_RAM141_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM141_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM142_RAMDATA  ===================================================== */
#define MODEM_RAM142_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM142_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM143_RAMDATA  ===================================================== */
#define MODEM_RAM143_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM143_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM144_RAMDATA  ===================================================== */
#define MODEM_RAM144_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM144_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM145_RAMDATA  ===================================================== */
#define MODEM_RAM145_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM145_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM146_RAMDATA  ===================================================== */
#define MODEM_RAM146_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM146_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM147_RAMDATA  ===================================================== */
#define MODEM_RAM147_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM147_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM148_RAMDATA  ===================================================== */
#define MODEM_RAM148_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM148_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM149_RAMDATA  ===================================================== */
#define MODEM_RAM149_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM149_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM150_RAMDATA  ===================================================== */
#define MODEM_RAM150_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM150_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM151_RAMDATA  ===================================================== */
#define MODEM_RAM151_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM151_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM152_RAMDATA  ===================================================== */
#define MODEM_RAM152_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM152_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM153_RAMDATA  ===================================================== */
#define MODEM_RAM153_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM153_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM154_RAMDATA  ===================================================== */
#define MODEM_RAM154_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM154_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM155_RAMDATA  ===================================================== */
#define MODEM_RAM155_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM155_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM156_RAMDATA  ===================================================== */
#define MODEM_RAM156_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM156_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM157_RAMDATA  ===================================================== */
#define MODEM_RAM157_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM157_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM158_RAMDATA  ===================================================== */
#define MODEM_RAM158_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM158_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM159_RAMDATA  ===================================================== */
#define MODEM_RAM159_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM159_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM160_RAMDATA  ===================================================== */
#define MODEM_RAM160_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM160_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM161_RAMDATA  ===================================================== */
#define MODEM_RAM161_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM161_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM162_RAMDATA  ===================================================== */
#define MODEM_RAM162_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM162_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM163_RAMDATA  ===================================================== */
#define MODEM_RAM163_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM163_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM164_RAMDATA  ===================================================== */
#define MODEM_RAM164_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM164_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM165_RAMDATA  ===================================================== */
#define MODEM_RAM165_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM165_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM166_RAMDATA  ===================================================== */
#define MODEM_RAM166_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM166_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM167_RAMDATA  ===================================================== */
#define MODEM_RAM167_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM167_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM168_RAMDATA  ===================================================== */
#define MODEM_RAM168_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM168_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM169_RAMDATA  ===================================================== */
#define MODEM_RAM169_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM169_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM170_RAMDATA  ===================================================== */
#define MODEM_RAM170_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM170_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM171_RAMDATA  ===================================================== */
#define MODEM_RAM171_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM171_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM172_RAMDATA  ===================================================== */
#define MODEM_RAM172_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM172_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM173_RAMDATA  ===================================================== */
#define MODEM_RAM173_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM173_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM174_RAMDATA  ===================================================== */
#define MODEM_RAM174_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM174_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM175_RAMDATA  ===================================================== */
#define MODEM_RAM175_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM175_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM176_RAMDATA  ===================================================== */
#define MODEM_RAM176_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM176_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM177_RAMDATA  ===================================================== */
#define MODEM_RAM177_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM177_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM178_RAMDATA  ===================================================== */
#define MODEM_RAM178_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM178_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM179_RAMDATA  ===================================================== */
#define MODEM_RAM179_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM179_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM180_RAMDATA  ===================================================== */
#define MODEM_RAM180_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM180_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM181_RAMDATA  ===================================================== */
#define MODEM_RAM181_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM181_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM182_RAMDATA  ===================================================== */
#define MODEM_RAM182_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM182_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM183_RAMDATA  ===================================================== */
#define MODEM_RAM183_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM183_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM184_RAMDATA  ===================================================== */
#define MODEM_RAM184_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM184_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM185_RAMDATA  ===================================================== */
#define MODEM_RAM185_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM185_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM186_RAMDATA  ===================================================== */
#define MODEM_RAM186_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM186_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM187_RAMDATA  ===================================================== */
#define MODEM_RAM187_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM187_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM188_RAMDATA  ===================================================== */
#define MODEM_RAM188_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM188_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM189_RAMDATA  ===================================================== */
#define MODEM_RAM189_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM189_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM190_RAMDATA  ===================================================== */
#define MODEM_RAM190_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM190_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM191_RAMDATA  ===================================================== */
#define MODEM_RAM191_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM191_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM192_RAMDATA  ===================================================== */
#define MODEM_RAM192_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM192_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM193_RAMDATA  ===================================================== */
#define MODEM_RAM193_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM193_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM194_RAMDATA  ===================================================== */
#define MODEM_RAM194_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM194_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM195_RAMDATA  ===================================================== */
#define MODEM_RAM195_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM195_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM196_RAMDATA  ===================================================== */
#define MODEM_RAM196_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM196_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM197_RAMDATA  ===================================================== */
#define MODEM_RAM197_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM197_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM198_RAMDATA  ===================================================== */
#define MODEM_RAM198_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM198_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM199_RAMDATA  ===================================================== */
#define MODEM_RAM199_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM199_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM200_RAMDATA  ===================================================== */
#define MODEM_RAM200_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM200_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM201_RAMDATA  ===================================================== */
#define MODEM_RAM201_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM201_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM202_RAMDATA  ===================================================== */
#define MODEM_RAM202_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM202_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM203_RAMDATA  ===================================================== */
#define MODEM_RAM203_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM203_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM204_RAMDATA  ===================================================== */
#define MODEM_RAM204_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM204_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM205_RAMDATA  ===================================================== */
#define MODEM_RAM205_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM205_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM206_RAMDATA  ===================================================== */
#define MODEM_RAM206_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM206_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM207_RAMDATA  ===================================================== */
#define MODEM_RAM207_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM207_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM208_RAMDATA  ===================================================== */
#define MODEM_RAM208_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM208_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM209_RAMDATA  ===================================================== */
#define MODEM_RAM209_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM209_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM210_RAMDATA  ===================================================== */
#define MODEM_RAM210_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM210_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM211_RAMDATA  ===================================================== */
#define MODEM_RAM211_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM211_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM212_RAMDATA  ===================================================== */
#define MODEM_RAM212_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM212_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM213_RAMDATA  ===================================================== */
#define MODEM_RAM213_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM213_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM214_RAMDATA  ===================================================== */
#define MODEM_RAM214_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM214_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM215_RAMDATA  ===================================================== */
#define MODEM_RAM215_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM215_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM216_RAMDATA  ===================================================== */
#define MODEM_RAM216_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM216_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM217_RAMDATA  ===================================================== */
#define MODEM_RAM217_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM217_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM218_RAMDATA  ===================================================== */
#define MODEM_RAM218_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM218_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM219_RAMDATA  ===================================================== */
#define MODEM_RAM219_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM219_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM220_RAMDATA  ===================================================== */
#define MODEM_RAM220_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM220_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM221_RAMDATA  ===================================================== */
#define MODEM_RAM221_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM221_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM222_RAMDATA  ===================================================== */
#define MODEM_RAM222_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM222_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM223_RAMDATA  ===================================================== */
#define MODEM_RAM223_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM223_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM224_RAMDATA  ===================================================== */
#define MODEM_RAM224_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM224_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM225_RAMDATA  ===================================================== */
#define MODEM_RAM225_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM225_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM226_RAMDATA  ===================================================== */
#define MODEM_RAM226_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM226_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM227_RAMDATA  ===================================================== */
#define MODEM_RAM227_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM227_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM228_RAMDATA  ===================================================== */
#define MODEM_RAM228_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM228_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM229_RAMDATA  ===================================================== */
#define MODEM_RAM229_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM229_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM230_RAMDATA  ===================================================== */
#define MODEM_RAM230_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM230_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM231_RAMDATA  ===================================================== */
#define MODEM_RAM231_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM231_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM232_RAMDATA  ===================================================== */
#define MODEM_RAM232_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM232_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM233_RAMDATA  ===================================================== */
#define MODEM_RAM233_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM233_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM234_RAMDATA  ===================================================== */
#define MODEM_RAM234_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM234_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM235_RAMDATA  ===================================================== */
#define MODEM_RAM235_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM235_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM236_RAMDATA  ===================================================== */
#define MODEM_RAM236_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM236_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM237_RAMDATA  ===================================================== */
#define MODEM_RAM237_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM237_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM238_RAMDATA  ===================================================== */
#define MODEM_RAM238_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM238_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM239_RAMDATA  ===================================================== */
#define MODEM_RAM239_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM239_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM240_RAMDATA  ===================================================== */
#define MODEM_RAM240_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM240_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM241_RAMDATA  ===================================================== */
#define MODEM_RAM241_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM241_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM242_RAMDATA  ===================================================== */
#define MODEM_RAM242_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM242_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM243_RAMDATA  ===================================================== */
#define MODEM_RAM243_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM243_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM244_RAMDATA  ===================================================== */
#define MODEM_RAM244_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM244_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM245_RAMDATA  ===================================================== */
#define MODEM_RAM245_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM245_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM246_RAMDATA  ===================================================== */
#define MODEM_RAM246_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM246_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM247_RAMDATA  ===================================================== */
#define MODEM_RAM247_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM247_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM248_RAMDATA  ===================================================== */
#define MODEM_RAM248_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM248_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM249_RAMDATA  ===================================================== */
#define MODEM_RAM249_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM249_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM250_RAMDATA  ===================================================== */
#define MODEM_RAM250_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM250_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM251_RAMDATA  ===================================================== */
#define MODEM_RAM251_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM251_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM252_RAMDATA  ===================================================== */
#define MODEM_RAM252_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM252_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM253_RAMDATA  ===================================================== */
#define MODEM_RAM253_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM253_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM254_RAMDATA  ===================================================== */
#define MODEM_RAM254_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM254_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */
/* ====================================================  RAM255_RAMDATA  ===================================================== */
#define MODEM_RAM255_RAMDATA_DATA_Pos     (0UL)                     /*!< DATA (Bit 0)                                          */
#define MODEM_RAM255_RAMDATA_DATA_Msk     (0xffUL)                  /*!< DATA (Bitfield-Mask: 0xff)                            */


/** @} */
/** @} End of group EFR32FG1V_MODEM*/
/** @} End of group Parts */
