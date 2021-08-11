## efr32_baremetal

# Attention! For testing and research purposes only. Do NOT use in commercial projects!

* Based on reverse engineering Silicon Labs RAIL library version 1.2 using Ghidra SRE.
* SoC: EFR32FG1V131.
* Frequency band: 868 MHz. Maybe easily changed to any sub-GHz band.
* Now working: synthesizer control and TX control (CW and PN9 transmitting only).
* Controlled through UART0 by simple CLI command set (UART_TX: PA0, UART_RX: PA1).
* Schematics and CLI commands description coming soon.
