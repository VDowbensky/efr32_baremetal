// Copyright 2021 Silicon Laboratories, Inc.
//
//

/***************************************************************************//**
 * @brief RAIL Configuration
 * @details
 *   WARNING: Auto-Generated Radio Config  -  DO NOT EDIT
 *   Radio Configurator Version: 5.6.0
 *   RAIL Adapter Version: 2.4.13
 *   RAIL Compatibility: 1.x
 *******************************************************************************
 * # License
 * <b>Copyright 2019 Silicon Laboratories Inc. www.silabs.com</b>
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
#include "em_device.h"
#include "rail_config.h"

const uint32_t generated_phyInfo[] = {
  0UL,
  0x00100000UL, // 16.0
};

const uint32_t generated[] = {
  0x01010FF0UL, (uint32_t) &generated_phyInfo,
  0x01010FF4UL, 0x00000000UL,
  0x01010FF8UL, 0x0003C002UL, //seq
  0x01010FFCUL, 0x0003C002UL,
  0x00010004UL, 0x00000000UL, //FRC->DFLCTRL
  0x00010008UL, 0x00000000UL, //FRC->MAXLENGTH
  0x00010018UL, 0x0000001FUL, //FRC->WCNTCMP0
  0x0001001CUL, 0x00000000UL, //FRC->WCNTCMP1
  0x00010028UL, 0x00000000UL, //FRC->WHITECTRL
  0x0001002CUL, 0x00000108UL, //FRC->WHITEPOLY
  0x00010030UL, 0x0000FFFFUL, //FRC->WHITEINIT
  0x00010034UL, 0x00000001UL, //FRC->FECCTRL
  0x00010038UL, 0x00000000UL, //FRC->BLOCKRAMADDR
  0x0001003CUL, 0x00000000UL, //FRC->CONVRAMADDR
  0x00010040UL, 0x00000700UL, //FRC->CTRL
  0x00010048UL, 0x00000000UL, //FRC->TRAILTXDATACTRL
  0x00010054UL, 0x00000000UL, //FRC->CONVGENERATOR
  0x00010058UL, 0x00000000UL, //FRC->PUNCTCTRL
  0x000100A0UL, 0x00000CFFUL, //FRC->FCD0
  0x000100A4UL, 0x00000000UL, //FRC->FCD1
  0x000100A8UL, 0x00000DFFUL, //FRC->FCD2
  0x000100ACUL, 0x00000000UL, //FRC->FCD3
  0x00012000UL, 0x00000744UL, //CRC->CTRL
  0x00012010UL, 0x00000000UL, //CRC->INIT
  0x00012018UL, 0x0000A001UL, //CRC->POLY
  0x00013008UL, 0x0000AC3FUL, //SYNTH->CTRL
  0x00013030UL, 0x00104000UL, //SYNTH->IFFREQ
  0x00013034UL, 0x00000003UL, //SYNTH->DIVCTRL
  0x00013040UL, 0x00000000UL, //SYNTH->CALOFFSET
  0x000140A0UL, 0x0F00277AUL, //RAC->VCOCTRL
  0x000140F4UL, 0x00001020UL, //RAC->RFENCTRL
  0x00014134UL, 0x00000880UL, //RAC->LNAMIXCTRL1
  0x00014138UL, 0x000087F6UL, //RAC->IFPGACTRL
  0x00014140UL, 0x008800E0UL, //RAC->IFFILTCTRL
  0x00014144UL, 0x1153E6C1UL, //RAC->IFADCCTRL
  0x00016014UL, 0x00000010UL, //MODEM->MIXCTRL
  0x00016018UL, 0x04000000UL, //MODEM->CTRL0
  0x0001601CUL, 0x0001400FUL, //MODEM->CTRL1
  0x00016020UL, 0x00002000UL, //MODEM->CTRL2
  0x00016024UL, 0x00000000UL, //MODEM->CTRL3
  0x00016028UL, 0x03000000UL, //MODEM->CTRL4
  0x0001602CUL, 0x00000000UL, //MODEM->CTRL5
  0x00016030UL, 0x00FF5FA0UL, //MODEM->TXBR
  0x00016034UL, 0x00000820UL, //MODEM->RXBR
  0x00016038UL, 0x020200F8UL, //MODEM->CF
  0x0001603CUL, 0x00140012UL, //MODEM->PRE
  0x00016040UL, 0x00002BB4UL, //MODEM->SYNC0
  0x00016044UL, 0x00000000UL, //MODEM->SYNC1
  0x00016048UL, 0x0220081FUL, //MODEM->TIMING
  0x0001604CUL, 0x00000000UL, //MODEM->DSSS0
  0x00016050UL, 0x00230390UL, //MODEM->MODINDEX
  0x00016054UL, 0x00000000UL, //MODEM->AFC
  0x00016058UL, 0x00000000UL, //MODEM->AFCADJLIM
  0x0001605CUL, 0x22140A04UL, //MODEM->SHAPING0
  0x00016060UL, 0x504B4133UL, //MODEM->SHAPING1
  0x00016064UL, 0x00000000UL, //MODEM->SHAPING2
  0x00017014UL, 0x000270FEUL, //AGC->CTRL0
  0x00017018UL, 0x00001300UL, //AGC->CTRL1
  0x0001701CUL, 0x81D10060UL, //AGC->CTRL2
  0x00017028UL, 0x00000000UL, //AGC->MANGAIN
  0x00017048UL, 0x0000383EUL, //AGC->GAINRANGE
  0x0001704CUL, 0x000025BCUL, //AGC->GAININDEX
  0x00017070UL, 0x00020105UL, //AGC->GAINSTEPLIM
  0x00017074UL, 0x00000113UL, //AGC->LOOPDEL
  0x00017078UL, 0x006D8480UL, //AGC->MININDEX

  0xFFFFFFFFUL,
};

const uint32_t *configList[] = {
  generated,
};

const char *configNames[] = {
  "generated",
};

RAIL_ChannelConfigEntry_t generated_channels[] = {
  { 0, 20, 100000, 868000000 },
};

const RAIL_ChannelConfig_t generated_channelConfig = {
  generated_channels,
  1,
};

const RAIL_ChannelConfig_t *channelConfigs[] = {
  &generated_channelConfig,
};

RAIL_FrameType_t *frameTypeConfigList[] = {
  NULL
};

const uint8_t irCalConfig[] = {
  25, 69, 3, 6, 4, 16, 1, 1, 1, 3, 1, 6, 0, 16, 39, 0, 0, 5, 0, 1, 1, 0, 0, 0, 0, 0
};


//        _  _                          
//       | )/ )         Wireless        
//    \\ |//,' __       Application     
//    (")(_)-"()))=-    Software        
//       (\\            Platform        
