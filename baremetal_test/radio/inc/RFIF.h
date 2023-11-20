#ifndef _RFIF_H_
#define _RFIF_H_

#include "em_device.h"
#include "em_bus.h"
#include <stdbool.h>
#include <math.h>
#include "RADIO_config.h"


#define EFR32_SERIES_1

        //#if model.part_family.lower() in ["dumbo", "jumbo", "nerio", "nixi", "unit_test_part"]:
 		//pll_bandwidth_rx
		#if defined EFR32_SERIES_1
        #define PLL_BW_RX_250KHz  	0  //'PLL loop filter bandwidth is approximately 250 KHz'],
        #define PLL_BW_RX_297KHz  	1  //'PLL loop filter bandwidth is approximately 297 KHz'],
        #define PLL_BW_RX_354KHz  	2  //'PLL loop filter bandwidth is approximately 354 KHz'],
        #define PLL_BW_RX_420KHz  	3  //'PLL loop filter bandwidth is approximately 420 KHz'],
        #define PLL_BW_RX_500KHz  	6  //'PLL loop filter bandwidth is approximately 500 KHz'],
        #define PLL_BW_RX_594KHz  	7  //'PLL loop filter bandwidth is approximately 594 KHz'],
        #define PLL_BW_RX_1260KHz  	8 //'PLL loop filter bandwidth is approximately 1260 KHz'],
        #define PLL_BW_RX_1500KHz  	9 //'PLL loop filter bandwidth is approximately 1500 KHz'],
        #define PLL_BW_RX_1780KHz  	10 //'PLL loop filter bandwidth is approximately 1780 KHz'],
        #define PLL_BW_RX_2120KHz  	11 //'PLL loop filter bandwidth is approximately 2120 KHz'],
        #define PLL_BW_RX_2520KHz  	14 //'PLL loop filter bandwidth is approximately 2520 KHz'],
        #define PLL_BW_RX_3000KHz  	15 //'PLL loop filter bandwidth is approximately 3000 KHz'],
        #else
        #define PLL_BW_RX_100KHz  	0// 'PLL loop filter bandwidth is approximately 100 KHz'],
        #define PLL_BW_RX_150KHz  	1// 'PLL loop filter bandwidth is approximately 150 KHz'],
        #define PLL_BW_RX_200KHz  	2// 'PLL loop filter bandwidth is approximately 200 KHz'],
        #define PLL_BW_RX_250KHz  	3// 'PLL loop filter bandwidth is approximately 250 KHz'],
        #define PLL_BW_RX_300KHz  	6// 'PLL loop filter bandwidth is approximately 300 KHz'],
		#endif

        //#if model.part_family.lower() in ["dumbo", "jumbo", "nerio", "nixi", "unit_test_part"]:
		//pll_bandwidth_tx
		#if defined EFR32_SERIES_1
        #define PLL_BW_TX_250KHz  	0  //'PLL loop filter bandwidth is approximately 250 KHz'],
        #define PLL_BW_TX_297KHz  	1  //'PLL loop filter bandwidth is approximately 297 KHz'],
        #define PLL_BW_TX_354KHz  	2  //'PLL loop filter bandwidth is approximately 354 KHz'],
        #define PLL_BW_TX_420KHz  	3  //'PLL loop filter bandwidth is approximately 420 KHz'],
        #define PLL_BW_TX_500KHz  	6  //'PLL loop filter bandwidth is approximately 500 KHz'],
        #define PLL_BW_TX_594KHz  	7  //'PLL loop filter bandwidth is approximately 594 KHz'],
        #define PLL_BW_TX_1260KHz  	8 //'PLL loop filter bandwidth is approximately 1260 KHz'],
        #define PLL_BW_TX_1500KHz  	9 //'PLL loop filter bandwidth is approximately 1500 KHz'],
        #define PLL_BW_TX_1780KHz  	10 //'PLL loop filter bandwidth is approximately 1780 KHz'],
        #define PLL_BW_TX_2120KHz  	11 //'PLL loop filter bandwidth is approximately 2120 KHz'],
        #define PLL_BW_TX_2520KHz  	14 //'PLL loop filter bandwidth is approximately 2520 KHz'],
        #define PLL_BW_TX_3000KHz  	15 //'PLL loop filter bandwidth is approximately 3000 KHz'],
        #else
        #define PLL_BW_TX_750KHz   	0 //'PLL loop filter bandwidth is approximately 750 KHz'],
        #define PLL_BW_TX_1000KHz  	1 //'PLL loop filter bandwidth is approximately 1000 KHz'],
        #define PLL_BW_TX_1200KHz  	2 //'PLL loop filter bandwidth is approximately 1200 KHz'],
        #define PLL_BW_TX_1500KHz  	3 //'PLL loop filter bandwidth is approximately 1500 KHz'],
        #define PLL_BW_TX_2000KHz  	6 //'PLL loop filter bandwidth is approximately 2000 KHz'],
        #define PLL_BW_TX_2500KHz  	7 //'PLL loop filter bandwidth is approximately 2500 KHz'],
        #define PLL_BW_TX_000KHz  	8 //'PLL loop filter bandwidth is approximately 3000 KHz'],
		#endif

        
        // Don't write this register directly any more.  Write the version in sequencer code instead.
		
		
    void RFIF_GetIffiltBw(void);
    void RFIF_CalcIffiltRatio(void);
	void RFIF_SetIffiltCtrlReg(void);
	void RFIF_SetIfadcCtrlReg(void); 
	void RFIF_CalcLpfBwTx(void);
	void RFIF_CalcLpfBwRx(void);
	void RFIF_SetLpfBw(void);
	void RFIF_SetIfpgaCtrlReg(void);
    void RFIF_SetRfEnReg(void);
    void RFIF_SetlnaMixCtrl1Reg(void);
    void RFIF_SetVcoCtrlReg(void);

#endif
