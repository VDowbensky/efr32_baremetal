#include "phy.h"
#include <stdbool.h>
#include <string.h>
#include "em_bus.h"
#include "em_assert.h"
#include "rail_rf.h"
#include "radio.h"
#include "rail.h"
#include "synth.h"
#include "generic_phy.h"
#include "rf_test.h"
#include "protimer.h"
#include "ir_cal.h"
#include "pa.h"
#include "em_cmu.h"
#include "rf_rand.h"
#include "rail_calibration.h"

bool forceIrCal = false;

uint16_t validateSetTiming(uint16_t *timing)

{
  uint16_t t;
  
  if (*timing < 60) t = 60;
  else
  {
    t = 13000;
    if (*timing < 13001) return *timing; //keep old value
  }
  *timing = t;
  return *timing;
}


/**
 * Load a static radio configuration
 *
 * @param[in] radioConfig Pointer to a radio configuration array
 * @return A non-zero value on failure and zero on success
 *
 * The radioConfig passed into this function should be generated for you, and
 * not created or edited by hand.
 */
uint8_t RAIL_RadioConfig(void *radioConfig) //currently not used

{
  RADIO_Config(&radioConfig); //!!!
  forceIrCal = true;
  return 0;
}

/**
 * Configure the channels supported by this device
 *
 * @param[in] config A pointer to the channel configuration for your device.
 *   This pointer will be cached in the library so it must be something that
 *   will exist for the runtime of the application. Typically this should be
 *   what is stored in Flash by the configuration tool.
 * @return Returns first available channel in config.
 *
 * When configuring channels on the EFR32, the Synth will be reconfigured based
 * on the frequency and channel spacing in config.
*/

//typedef struct RAIL_ChannelConfig {
//  RAIL_ChannelConfigEntry_t *configs; /**< Pointer to an array of RAIL_ChannelConfigEntry_t entries.*/
//  uint32_t length; /**< Number of RAIL_ChannelConfigEntry_t entries. */
//} RAIL_ChannelConfig_t;

uint8_t RAIL_ChannelConfig(const RAIL_ChannelConfig_t * config)

{
    
	//RAILInt_TrackChannelConfig();
  //SYNTH_Config(*(undefined4 *)(*config + 8),*(undefined4 *)(*config + 4));
	
	if (SYNTH_Is2p4GHz() == 0) SYNTH_DCDCRetimeClkSet(3500000);
  else SYNTH_DCDCRetimeClkSet(7000000);
  if (forceIrCal != 0)
  {
    forceIrCal = 0;
    RAIL_RfHalCalibrationPend(0x10000);
  }
//  return *(uint8_t *)*config;
  return 0; //!!!!!!!!!!!!!!!!
}



/**
 * Enable or disable direct mode for RAIL.
 *
 * @param[in] enable Whether to turn direct mode on or off. At some point this
 *  will include a configuration structure.
 * @warning This API configures fixed pins for tx data in, rx data out, rx clock
 *  out. There should be more control over these pins in the future but they are
 *  currently fixed.
 *
 * In this mode packets will be output and input directly to the radio via GPIO
 * and RAIL packet handling will be ignored. On the EFR32, the DIN pin in TX is
 * EFR32_PC10, which corresponds to EXP_HEADER15/WSTKP12, and the DOUT pin in
 * RX is EFR32_PC11, which corresponds to EXP_HEADER16/WSTKP13.
 */
void RAIL_DirectModeConfig(bool enable)

{
//  uint8_t *p;
  
//  if (enable == false)  p = directModeDisableConfig; //!!!!!!!!!!!!!!!!
//  else  p = directModeEnableConfig; //!!!!!!!!!!!!!!!!
//  GENERIC_PHY_DirectModeConfig(p); //!!!!!!!!!!!!!!!!
}



/**
 * Starts transmitting a tone on a certain channel
 *
 * @param[in] channel Define the channel to emit a tone
 * @return Returns 0 on success and 1 on error
 *
 * Transmits a continuous wave, or tone, at the given channel, as defined by
 * the channel configuration passed to RAIL_ChannelConfig().
 */
uint8_t RAIL_TxToneStart(uint8_t channel)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = (char *)RAILInt_SetChannelConfig(channel); //!!!
  if (pcVar1 != NULL)
  {
    iVar2 = RAIL_DebugModeGet();
    if (iVar2 != 1) GENERIC_PHY_ChannelSet(channel - *pcVar1);
    RFTEST_SaveRadioConfiguration();
    RFTEST_StartCwTx();
    return 0;
  }
  return 1;
}



/**
 * Stop tone transmission
 *
 * @return Returns 0 on success and 1 on error
 *
 * Halt the transmission started by RAIL_TxToneStart().
 */
uint8_t RAIL_TxToneStop(void)

{
  RFTEST_StopTx();
  RFTEST_RestoreRadioConfiguration();
  return 0;
}



/**
 * Start transmitting a stream on a certain channel
 *
 * @param[in] channel Channel on which to emit a stream
 * @param[in] mode Choose the stream mode (PN9, etc)
 * @return Returns 0 on success and 1 on error
 *
 * Emits an encoded stream of bits on the given channel, from either a PN9 or
 * pseudo-random source.
 */
uint8_t RAIL_TxStreamStart(uint8_t channel, RAIL_StreamMode_t mode)
{
  char *pcVar1;
 // if ((mode == 1) && ((char *)RAILInt_SetChannelConfig() != NULL)) //!!!!!!!!!!!!!!!!
  {
    RFTEST_SaveRadioConfiguration();
    RFTEST_StartStreamTx();
    if (RAIL_DebugModeGet() != 1) GENERIC_PHY_ChannelSet(channel - *pcVar1);
    return 0;
  }
  return 1;
}


/**
 * Stop stream transmission
 *
 * @return Returns 0 on success and 1 on error
 *
 * Halt the transmission started by RAIL_TxStreamStart().
 */
uint8_t RAIL_TxStreamStop(void)

{
  RFTEST_StopTx();
  RFTEST_RestoreRadioConfiguration();
  return 0;
}


/**
 * Set the radio transmit power level
 *
 * @param[in] powerLevel TX Power Level defined in deci dBm (10 * dBm)
 * @return TX Power Level in deci dBm (10 * dBm)
 *
 * Not all values of powerLevel are achievable, but this function will set the
 * power output to be close to the given powerLevel, and return the value that
 * was set as the power.
 */
int32_t RAIL_TxPowerSet(int32_t powerLevel) // in 0.1 dBm

{
  return PA_OutputPowerSet(powerLevel);
}


/**
 * Get the radio transmit power level
 *
 * @return TX Power Level defined in deci dBm (10 * dBm)
 *
 * This will return what the power output was actually set to, not just the
 * value passed into RAIL_TxPowerSet.
 */
int32_t RAIL_TxPowerGet(void)

{
  return PA_OutputPowerGet();
}


/**
 * Override the radio base frequency
 *
 * @param[in] freq Desired frequency in Hz
 *
 * Sets the radio to transmit at the frequency given. This function can only
 * be used while in RAIL_DEBUG_MODE_FREQ_OVERRIDE. The given frequency needs
 * to be close to the base frequency of the current PHY.
 */
RAIL_Status_t RAIL_DebugFrequencyOverride(uint32_t freq)

{
  SYNTH_Config(freq,0); //
  return RAIL_STATUS_NO_ERROR;
}


/**
 * Configure the length to use for received packets to be variable based on an
 * implicit length field in payload bytes
 *
 * @param[in] frameType Frame type configuration structure.
 *
 * Currently the frame type passed in only handles packet length decoding. If
 * NULL is passed into this function, it will clear any currently configured
 * frame type settings.
 */
void RAIL_PacketLengthConfigFrameType(const RAIL_FrameType_t *frameType)

{
  GENERIC_PHY_ConfigureFrameType(frameType);
}


/**
 * Return the current raw RSSI
 *
 * @return Return \ref RAIL_RSSI_INVALID if the receiver is disabled and we are
 * unable to get an RSSI value, otherwise, return the RSSI in quarter dBm,
 * dbm*4.
 *
 * Get the current RSSI value. This value represents the current energy of the
 * channel, so it can change rapidly, and will be low if there is no RF energy
 * in your current channel. The function from the value reported to dBm is an
 * offset dependent on the PHY and the PCB layout. Users should characterize the
 * RSSI received on their hardware and apply an offset in the application to
 * account for board and PHY parameters.
 */
int16_t RAIL_RxGetRSSI(void)

{
  return RADIO_GetRSSI();
}


/**
 * Set the crystal tuning
 *
 * @param[in] tune Chip dependent crystal capacitor bank tuning parameter
 *
 * Tune the crystal that the radio depends on, to change the location of the
 * center frequency for transmitting and receiving.
 */
void RAIL_SetTune(uint32_t tune)

{
  CMU_ClockSelectSet(0x11,5);
  CMU_OscillatorEnable(2,0,0);
  //CMU->HFXOSTEADYSTATECTRL &= 0xfff007ff;
	BUS_RegMaskedClear(&CMU->HFXOSTEADYSTATECTRL, _CMU_HFXOSTEADYSTATECTRL_CTUNE_MASK);
	CMU->HFXOSTEADYSTATECTRL |= (tune & 0x1ff) << _CMU_HFXOSTEADYSTATECTRL_CTUNE_SHIFT;
  CMU_OscillatorEnable(2,1,1);
  CMU_ClockSelectSet(0x11,4);
}


/**
 * Get the crystal tuning
 *
 * @return Chip dependent crystal capacitor bank tuning parameter
 *
 * Retrieve the current tuning value used by the crystal that the radio
 * depends on.
 */
uint32_t RAIL_GetTune(void)

{
	return (CMU->HFXOSTEADYSTATECTRL & _CMU_HFXOSTEADYSTATECTRL_CTUNE_MASK) >> _CMU_HFXOSTEADYSTATECTRL_CTUNE_SHIFT;
}


/**
 * Get the current RAIL time
 *
 * @return Returns the RAIL timebase in microseconds. Note that this wraps after
 * around 1.19 hours since it's stored in a 32bit value.
 *
 * Return the current time in the RAIL timebase (microseconds). This can be
 * used to compare with packet timestamps or to schedule transmits.
 */
uint32_t RAIL_GetTime(void)

{
  uint32_t cnt;
  cnt = PROTIMER_GetTime();
  return PROTIMER_PrecntOverflowToUs(cnt);
}


/**
 * Set the current RAIL time
 *
 * @param[in] time Set the RAIL timebase to this value in microseconds.
 * @return Returns RAIL_STATUS_NO_ERROR on success and
 * RAIL_STATUS_INVALID_STATE if the time could not be set.
 *
 * Set the current time in the RAIL timebase in microseconds.
 */
RAIL_Status_t RAIL_SetTime(uint32_t time)

{
  if (PROTIMER_SetTime(time) == 0) return RAIL_STATUS_INVALID_STATE;
  else return RAIL_STATUS_NO_ERROR;
}


/**
 * Configure RAIL automatic state transition timing
 *
 * @param[in] timings The timings used to configure the RAIL state machine. This
 * structure will be overwritten with the actual times that were set, in the
 * case of an input timing that is invalid.
 * @return Returns zero on success and an error code on error.
 *
 * The timings given will be close to the actual transition time, but there is
 * some software overhead that is not yet characterized. Also, timings are not
 * always adhered to when using an automatic transition after an error, due to
 * the cleanup required to recover from the error.
 */
RAIL_Status_t RAIL_SetStateTiming(RAIL_StateTiming_t *timings)

{
  RADIO_RxWarmTimeSet(timings->idleToRx);
  RADIO_TxToRxTimeSet(timings->txToRx); //it's not full correct
  RADIO_TxWarmTimeSet(timings->idleToTx);
  RADIO_RxFrameToTxTimeSet(timings->rxToTx);
  return RAIL_STATUS_NO_ERROR;
}

//uint16_t idleToRx; /**<Transition time from IDLE to RX */
//uint16_t txToRx; /**<Transition time from TX to RX */
//uint16_t idleToTx; /**<Transition time from IDLE to RX */
//uint16_t rxToTx; /**<Transition time from RX to TX */


/**
 * Configure address filtering.
 *
 * @param addrConfig The configuration structure which defines how addresses
 * are setup in your packets.
 * @return True if we were able to configure address filtering and false
 * otherwise.
 *
 * This function must be called to setup address filtering. You may call this
 * multiple times, but all previous information is wiped out each time you call
 * it so any configured addresses must be reset.
 */
bool RAIL_AddressFilterConfig(RAIL_AddrConfig_t *addrConfig)

{
  uint8_t bVar1;
  uint32_t uVar2;
  int32_t iVar3;
  uint8_t * local_1c;
  uint32_t local_18;
  uint32_t local_14;
  
//  bVar1 = *param_1;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  if (bVar1 < 3) 
	{
//    local_1c = param_2;
//    local_18 = param_3;
//    local_14 = param_4;
    memset((void*)local_1c,0,0xc);
    iVar3 = 0;
  //  while (iVar3 < (int)(uint32_t)bVar1) 
//	{
  //    *(uint8_t *)((int)&local_1c + iVar3) = *(uint8_t *)(*(int *)(param_1 + 4) + iVar3);
  //    *(uint8_t *)((int)&local_1c + iVar3 + 2) = *(uint8_t *)(*(int *)(param_1 + 8) + iVar3);
  //    iVar3 = iVar3 + 1;
  //  }
  //  local_18 = *(uint32_t *)(param_1 + 0xc);
//    local_14 = CONCAT31(local_14._1_3_,0xff);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    return  GENERIC_PHY_ConfigureAddressFiltering(local_1c);
  }
  else return false;
}


/**
 * Configure address filtering based on frame type
 *
 * @param validFrames The frames on which to enable address filtering. Each bit
 * corresponds to a frame, where a 1 means to enable address filtering during
 * that frame, and a 0 means to ignore addresses during that frame. The least
 * significant bit corresponds to frame 0, and the most significant bit to
 * frame 7.
 * @return True if configuration was set properly, false otherwise
 *
 * This function only takes effect if frame type length decoding and address
 * filtering are both being used. In that case, this function gives the ability
 * to only enable address filtering on certain types of frames.
 *
 * @note This function must be called after RAIL_AddressFilterConfig for it to
 * take effect.
 */
bool RAIL_AddressFilterByFrameType(uint8_t validFrames)

{
  //DAT_21000f52 = validFrames;
  *(uint8_t*)(SEQ->REG050 + 0x2)  = validFrames;
  return true;
}


/**
 * Enable address filtering.
 *
 * @return True if address filtering was enabled to start with and false
 * otherwise
 *
 * Only allow packets through that pass the current address filtering
 * configuration. This will not reset or change the configuration so you can
 * set that up before turning this feature on.
 */
bool RAIL_AddressFilterEnable(void)

{
  return GENERIC_PHY_EnableAddressFiltering();
}


/**
 * Disable address filtering.
 *
 * @return True if address filtering was enabled to start with and false
 * otherwise
 *
 * Allow all packets through regardless of addressing information. This will not
 * reset or change the current configuration.
 */
bool RAIL_AddressFilterDisable(void)

{
  return GENERIC_PHY_DisableAddressFiltering();
}


/**
 * Return whether address filtering is currently enabled.
 *
 * @return True if address filtering is enabled and false otherwise
 */
bool RAIL_AddressFilterIsEnabled(void)

{
  return GENERIC_PHY_IsEnabledAddressFiltering();
}


/**
 * Reset the address filtering configuration.
 *
 * Reset all structures related to address filtering. This will not disable
 * address fitlering. It will leave the radio in a state where no packets will
 * pass filtering.
 */
void RAIL_AddressFilterReset(void)

{
  GENERIC_PHY_ResetAddressFiltering();
}


/**
 * Set an address for filtering in hardware.
 *
 * @param field Which address field you want to use for this address
 * @param index Which match entry you want to place this address in for the
 * given field.
 * @param value A pointer to the address data. This must be at least as long
 * as the size specified in RAIL_AddressFilterConfig().
 * @param enable A boolean to indicate whether this address should be enabled
 * immediately.
 * @return True if we were able to set this address and false otherwise.
 *
 * This function will load the given address into hardware for filtering and
 * start filtering on it if you set the enable parameter to true. Otherwise,
 * you must call RAIL_AddressFilterEnableAddress() to turn it on later.
 */
bool RAIL_AddressFilterSetAddress(uint8_t field,uint8_t index,uint8_t *value,bool enable)

{
  //GENERIC_PHY_SetAddress(); //!!!!!!!!!!!!!!!!!!!!!!!!!!
	return true;
}


/**
 * Enable address filtering for the specified address
 *
 * @param field Which address field you want to enable the address within
 * @param index Which match entry in the given field you want to enable
 * @return True if we were able to enable filtering for this address and false
 * otherwise.
 */
bool RAIL_AddressFilterEnableAddress(uint8_t field, uint8_t index)

{
  // GENERIC_PHY_EnableAddress(); //!!!!!!!!!!!!!!!!!!!!!!!!!!
	return true;
}


/**
 * Disable address filtering for the specified address
 *
 * @param field Which address field you want to disable the address within
 * @param index Which match entry in the given field you want to disable
 * @return True if this address disabled successfully and false otherwise.
 *
 * This will clear the matchMask set in the RAIL_AddressFilterEnableAddress()
 * function and make sure that this address is marked as valid. To use it in
 * filtering again you must enable this address again.
 */
bool RAIL_AddressFilterDisableAddress(uint8_t field, uint8_t index)

{
  //GENERIC_PHY_DisableAddress(); //!!!!!!!!!!!!!!!!!!!!!!!!!!
	return true;
}


/***************************************************************************//**
 * Collect entropy from the radio if available.
 *
 * @param buffer The buffer to write the collected entropy to.
 * @param bytes The number of bytes to fill in in the input buffer
 * @return Returns the number of bytes of entropy we were able to collect. For
 * chips that don't support entropy collection this will return 0. Values less
 * than the requested amount may also be returned on platforms that use entropy
 * pools to collect random data periodically.
 *
 * Attempts to fill up the provided buffer with the requested number of bytes of
 * entropy. If we cannot provide as many bytes as requested then we will fill in
 * whatever we can and return the number of bytes we were able to get. For chips
 * that do not support this function we will always return 0 bytes. For
 * information about the specific mechanism for gathering entropy consult the
 * documentation for the chip family you're using.
 ******************************************************************************/
uint16_t RAIL_GetRadioEntropy(uint8_t *buffer, uint16_t bytes)

{
  return RFRAND_GetRadioEntropy();
}


