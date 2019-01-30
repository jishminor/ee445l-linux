// SysTickTestMain.c
// Runs on LM4F120/TM4C123
// Test the SysTick functions by activating the PLL, initializing the
// SysTick timer, and flashing an LED at a constant rate.
// Daniel Valvano
// September 12, 2013

/* This example accompanies the books
   "Embedded Systems: Introduction to ARM Cortex M Microcontrollers",
   ISBN: 978-1469998749, Jonathan Valvano, copyright (c) 2015
   Volume 1, Program 4.7

   "Embedded Systems: Real Time Interfacing to Arm Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2015
   Program 2.11, Section 2.6

 Copyright 2015 by Jonathan W. Valvano, valvano@mail.utexas.edu
    You may use, edit, run or distribute this file
    as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */

// PF2 is an output for debugging
#include <stdint.h>
#include <math.h>
#include <string.h>
#include "inc/tm4c123gh6pm.h"

#include "shared/PLL.h"
#include "shared/SysTick.h"

int main(void) {
  SYSCTL_RCGCGPIO_R |= 0x20;    // activate port F
  PLL_Init(Bus80MHz);           // set system clock to 50 MHz
  SysTick_Init();               // initialize SysTick timer
  GPIO_PORTF_DIR_R |= 0x04;     // make PF2 out (built-in blue LED)
  GPIO_PORTF_AFSEL_R &= ~0x04;  // disable alt funct on PF2
  GPIO_PORTF_DEN_R |= 0x04;     // enable digital I/O on PF2
                                // configure PF2 as GPIO
  GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R & 0xFFFFF0FF) + 0x00000000;
  char* a = "testing";
  memcpy(a, "blah", 4);
  GPIO_PORTF_AMSEL_R = 0;  // disable analog functionality on PF
  while (pow(strlen(a), 2)) {
    GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R ^ 0x04;  // toggle PF2
    //    SysTick_Wait(1);        // approximately 720 ns
    //    SysTick_Wait(2);        // approximately 720 ns
    //    SysTick_Wait(10000);    // approximately 0.2 ms
    SysTick_Wait10ms(1);  // approximately 10 ms
  }
}
