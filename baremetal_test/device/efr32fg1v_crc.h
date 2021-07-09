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
 * @defgroup EFR32FG1V_CRC
 * @{
 * @brief EFR32FG1V_CRC Register Declaration
 ******************************************************************************/
/* =========================================================================================================================== */
/* ================                                            CRC                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief RF CRC engine (CRC)
  */

typedef struct {                                /*!< (@ 0x40082000) CRC Structure                                              */
  __IOM uint32_t  CTRL;                         /*!< (@ 0x00000000) CTRL                                                       */
  __IM  uint32_t  STATUS;                       /*!< (@ 0x00000004) STATUS                                                     */
  __OM  uint32_t  CMD;                          /*!< (@ 0x00000008) CMD                                                        */
  __IOM uint32_t  INPUTDATA;                    /*!< (@ 0x0000000C) INPUTDATA                                                  */
  __IOM uint32_t  INIT;                         /*!< (@ 0x00000010) INIT                                                       */
  __IM  uint32_t  DATA;                         /*!< (@ 0x00000014) DATA                                                       */
  __IOM uint32_t  POLY;                         /*!< (@ 0x00000018) POLY                                                       */
} CRC_Typedef;   
/***************************************************************************//**
 * @addtogroup EFR32FG1V_CRC
 * @{
 * @defgroup EFR32FG1V_CRC BitFields  CRC Bit Fields
 * @{
 ******************************************************************************/
/* =========================================================================================================================== */
/* ================                                            CRC                                            ================ */
/* =========================================================================================================================== */

/* =========================================================  CTRL  ========================================================== */
#define CRC_CTRL_INPUTINV_Pos             (0UL)                     /*!< INPUTINV (Bit 0)                                      */
#define CRC_CTRL_INPUTINV_Msk             (0x1UL)                   /*!< INPUTINV (Bitfield-Mask: 0x01)                        */
#define CRC_CTRL_OUTPUTINV_Pos            (1UL)                     /*!< OUTPUTINV (Bit 1)                                     */
#define CRC_CTRL_OUTPUTINV_Msk            (0x2UL)                   /*!< OUTPUTINV (Bitfield-Mask: 0x01)                       */
#define CRC_CTRL_CRCWIDTH_Pos             (2UL)                     /*!< CRCWIDTH (Bit 2)                                      */
#define CRC_CTRL_CRCWIDTH_Msk             (0xcUL)                   /*!< CRCWIDTH (Bitfield-Mask: 0x03)                        */
#define CRC_CTRL_INPUTBITORDER_Pos        (5UL)                     /*!< INPUTBITORDER (Bit 5)                                 */
#define CRC_CTRL_INPUTBITORDER_Msk        (0x20UL)                  /*!< INPUTBITORDER (Bitfield-Mask: 0x01)                   */
#define CRC_CTRL_BYTEREVERSE_Pos          (6UL)                     /*!< BYTEREVERSE (Bit 6)                                   */
#define CRC_CTRL_BYTEREVERSE_Msk          (0x40UL)                  /*!< BYTEREVERSE (Bitfield-Mask: 0x01)                     */
#define CRC_CTRL_BITREVERSE_Pos           (7UL)                     /*!< BITREVERSE (Bit 7)                                    */
#define CRC_CTRL_BITREVERSE_Msk           (0x80UL)                  /*!< BITREVERSE (Bitfield-Mask: 0x01)                      */
#define CRC_CTRL_BITSPERWORD_Pos          (8UL)                     /*!< BITSPERWORD (Bit 8)                                   */
#define CRC_CTRL_BITSPERWORD_Msk          (0xf00UL)                 /*!< BITSPERWORD (Bitfield-Mask: 0x0f)                     */
#define CRC_CTRL_PADCRCINPUT_Pos          (12UL)                    /*!< PADCRCINPUT (Bit 12)                                  */
#define CRC_CTRL_PADCRCINPUT_Msk          (0x1000UL)                /*!< PADCRCINPUT (Bitfield-Mask: 0x01)                     */
/* ========================================================  STATUS  ========================================================= */
#define CRC_STATUS_BUSY_Pos               (0UL)                     /*!< BUSY (Bit 0)                                          */
#define CRC_STATUS_BUSY_Msk               (0x1UL)                   /*!< BUSY (Bitfield-Mask: 0x01)                            */
/* ==========================================================  CMD  ========================================================== */
#define CRC_CMD_INITIALIZE_Pos            (0UL)                     /*!< INITIALIZE (Bit 0)                                    */
#define CRC_CMD_INITIALIZE_Msk            (0x3fUL)                  /*!< INITIALIZE (Bitfield-Mask: 0x3f)                      */
/* =======================================================  INPUTDATA  ======================================================= */
#define CRC_INPUTDATA_INPUTDATA_Pos       (0UL)                     /*!< INPUTDATA (Bit 0)                                     */
#define CRC_INPUTDATA_INPUTDATA_Msk       (0xffffUL)                /*!< INPUTDATA (Bitfield-Mask: 0xffff)                     */
/* =========================================================  INIT  ========================================================== */
#define CRC_INIT_INIT_Pos                 (0UL)                     /*!< INIT (Bit 0)                                          */
#define CRC_INIT_INIT_Msk                 (0xffffffffUL)            /*!< INIT (Bitfield-Mask: 0xffffffff)                      */
/* =========================================================  DATA  ========================================================== */
#define CRC_DATA_DATA_Pos                 (0UL)                     /*!< DATA (Bit 0)                                          */
#define CRC_DATA_DATA_Msk                 (0xffffffffUL)            /*!< DATA (Bitfield-Mask: 0xffffffff)                      */
/* =========================================================  POLY  ========================================================== */
#define CRC_POLY_POLY_Pos                 (0UL)                     /*!< POLY (Bit 0)                                          */
#define CRC_POLY_POLY_Msk                 (0xffffffffUL)            /*!< POLY (Bitfield-Mask: 0xffffffff)                      */


/** @} */
/** @} End of group EFR32FG1V_CRC */
/** @} End of group Parts */
