// LED.c
// Runs on TM4C123
// Provide functions that initialize a GPIO as an input pin and
// allow reading of two negative logic switches on PF0 and PF4
// Output to LEDs
// Use bit-banded I/O.
// Daniel and Jonathan Valvano
// Feb 23, 2015
#include <stdint.h>
#include "inc/tm4c123gh6pm.h"

/* This example accompanies the book
   "Embedded Systems: Introduction to ARM Cortex M Microcontrollers",
   ISBN: 978-1469998749, Jonathan Valvano, copyright (c) 2014
   Section 4.2    Program 4.2

  "Embedded Systems: Real Time Interfacing to ARM Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2014
   Example 2.3, Program 2.9, Figure 2.36

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

#define SWITCHES (*((volatile uint32_t *)0x40025044))
#define SW1 0x10  // on the left side of the Launchpad board
#define SW2 0x01  // on the right side of the Launchpad board
#define PF1 (*((volatile uint32_t *)0x40025008))
#define PF2 (*((volatile uint32_t *)0x40025010))
#define PF3 (*((volatile uint32_t *)0x40025020))

//------------LED_Init------------
// LEDs on PF3,2,1 are enabled
// Input: none
// Output: none
void LED_Init(void) {
  SYSCTL_RCGCGPIO_R |= 0x20;  // 1) activate Port F
  while ((SYSCTL_PRGPIO_R & 0x20) != 0x20) {
  };                                  // wait to finish activating
  GPIO_PORTF_CR_R = 0x0E;             // 2b) enable commit for PF3-PF1
  GPIO_PORTF_AMSEL_R &= ~0x0E;     // 3) disable analog functionality on PF3-PF1
  GPIO_PORTF_PCTL_R = 0x00000000;  // 4) configure PF1-PF3 as GPIO
  GPIO_PORTF_DIR_R = 0x0E;         // 5) make PF3-1 output
  GPIO_PORTF_AFSEL_R = 0;          // 6) disable alt funct on PF0 and PF4
  GPIO_PORTF_DEN_R = 0x0E;         // 7) enable digital I/O on PF1-PF3
}


//------------LED_RedOn------------
// Turn on red LED
// Input: none
// Output: none
void LED_RedOn(void) { PF1 = 0x02; }
//------------LED_RedOff------------
// Turn off red LED
// Input: none
// Output: none
void LED_RedOff(void) { PF1 = 0x00; }
//------------LED_RedToggle------------
// Toggle redv LED
// Input: none
// Output: none
void LED_RedToggle(void) { PF1 ^= 0x02; }
//------------LED_BlueOn------------
// Turn on blue LED
// Input: none
// Output: none
void LED_BlueOn(void) { PF2 = 0x04; }
//------------LED_BlueOff------------
// Turn off blue LED
// Input: none
// Output: none
void LED_BlueOff(void) { PF2 = 0x00; }
//------------LED_BlueToggle------------
// Toggle blue LED
// Input: none
// Output: none
void LED_BlueToggle(void) { PF2 ^= 0x04; }
//------------LED_GreenToggle------------
//------------LED_GreenOn------------
// Turn on green LED
// Input: none
// Output: none
void LED_GreenOn(void) { PF3 = 0x08; }
//------------LED_GreenOff------------
// Turn off green LED
// Input: none
// Output: none
void LED_GreenOff(void) { PF3 = 0x00; }
// Toggle green LED
// Input: none
// Output: none
void LED_GreenToggle(void) { PF3 ^= 0x08; }
