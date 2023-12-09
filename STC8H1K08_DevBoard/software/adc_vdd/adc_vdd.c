// ===================================================================================
// Project:   Example for STC8H1K08
// Version:   v1.0
// Year:      2023
// Author:    Stefan Wagner
// Github:    https://github.com/wagiminator
// EasyEDA:   https://easyeda.com/wagiminator
// License:   http://creativecommons.org/licenses/by-sa/3.0/
// ===================================================================================
//
// Description:
// ------------
// Samples supply voltage (VDD) using analog to serial converter (ADC) and internal
// reference voltage (VREF). Sends it once a second via UART.
//
// Compilation Instructions:
// -------------------------
// - Make sure SDCC toolchain and Python3 with PySerial is installed.
// - Connect the MCU board via USB to your PC.
// - Run 'make flash'.
// - Perform a power cycle (press and release DOWNLOAD button) when prompted.

// ===================================================================================
// Libraries, Definitions and Macros
// ===================================================================================
#include "gpio.h"                       // GPIO functions
#include "delay.h"                      // delay functions
#include "debug_serial.h"               // serial debug functions

// ===================================================================================
// Main Function
// ===================================================================================
void main() {
  // Setup
  P_SW2 |= 0x80;                        // enable access to extended registers (MUST!)
  ADC_init();                           // init analog to digital converter (ADC)
  DEBUG_init();                         // init DEBUG (TX: P31, BAUD: 115200, 8N1)

  // Loop
  while (1) {
    DEBUG_printf("VDD: %dmV\n", ADC_read_VDD());  // read VDD in mV and send via UART
    DLY_ms(1000);                       // wait a bit
  }
}
