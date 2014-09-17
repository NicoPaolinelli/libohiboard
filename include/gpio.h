/******************************************************************************
 * Copyright (C) 2014 A. C. Open Hardware Ideas Lab
 * 
 * Authors:
 *  Marco Giammarini <m.giammarini@warcomeb.it>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ******************************************************************************/

/**
 * @file libohiboard/include/gpio.h
 * @author Marco Giammarini <m.giammarini@warcomeb.it>
 * @brief GPIO definitions and prototypes.
 */

#ifndef __GPIO_H
#define __GPIO_H

#include "platforms.h"
#include "errors.h"
#include "types.h"

#define GPIO_PINS_OUTPUT                    0x01
#define GPIO_PINS_INPUT                     0x02
#define GPIO_PINS_PULL                      0x04
#define GPIO_PINS_ENABLE_PULLUP             0x08
#define GPIO_PINS_ENABLE_PULLDOWN           0x10
#define GPIO_PINS_ENABLE_DRIVE_STRENGTH     0x20
#define GPIO_PINS_ENABLE_SLEW_RATE          0x40
#define GPIO_PINS_ENABLE_PASSIVE_FILTER     0x80

/* Useful define */
#define GPIO_PIN_MASK                       0x1Fu
#define GPIO_PIN(x)                         (((1)<<(x & GPIO_PIN_MASK)))

typedef enum 
{
    GPIO_LOW    = 0x00,
    GPIO_HIGH   = 0x01,
    GPIO_TOGGLE = 0xFF,
} Gpio_Level;


typedef enum
{
#if defined (MK60DZ10)

#elif defined (OHIBOARD_R1)

#elif defined (MKL15Z4)

    GPIO_PINS_PTA0 = 0,
    GPIO_PINS_PTA1,
    GPIO_PINS_PTA2,
    GPIO_PINS_PTA3,
    GPIO_PINS_PTA4,
    GPIO_PINS_PTA5,
    GPIO_PINS_PTA12,
    GPIO_PINS_PTA13,
    GPIO_PINS_PTA14,
    GPIO_PINS_PTA15,
    GPIO_PINS_PTA16,
    GPIO_PINS_PTA17,
    GPIO_PINS_PTA18,
    GPIO_PINS_PTA19,
    GPIO_PINS_PTA20,

    GPIO_PINS_PTB0,
    GPIO_PINS_PTB1,
    GPIO_PINS_PTB2,
    GPIO_PINS_PTB3,
    GPIO_PINS_PTB8,
    GPIO_PINS_PTB9,
    GPIO_PINS_PTB10,
    GPIO_PINS_PTB11,
    GPIO_PINS_PTB16,
    GPIO_PINS_PTB17,
    GPIO_PINS_PTB18,
    GPIO_PINS_PTB19,

    GPIO_PINS_PTC0,
    GPIO_PINS_PTC1,
    GPIO_PINS_PTC2,
    GPIO_PINS_PTC3,
    GPIO_PINS_PTC4,
    GPIO_PINS_PTC5,
    GPIO_PINS_PTC6,
    GPIO_PINS_PTC7,
    GPIO_PINS_PTC8,
    GPIO_PINS_PTC9,
    GPIO_PINS_PTC10,
    GPIO_PINS_PTC11,
    GPIO_PINS_PTC12,
    GPIO_PINS_PTC13,
    GPIO_PINS_PTC16,
    GPIO_PINS_PTC17,

    GPIO_PINS_PTD0,
    GPIO_PINS_PTD1,
    GPIO_PINS_PTD2,
    GPIO_PINS_PTD3,
    GPIO_PINS_PTD4,
    GPIO_PINS_PTD5,
    GPIO_PINS_PTD6,
    GPIO_PINS_PTD7,

    GPIO_PINS_PTE0,
    GPIO_PINS_PTE1,
    GPIO_PINS_PTE2,
    GPIO_PINS_PTE3,
    GPIO_PINS_PTE4,
    GPIO_PINS_PTE5,
    GPIO_PINS_PTE16,
    GPIO_PINS_PTE17,
    GPIO_PINS_PTE18,
    GPIO_PINS_PTE19,
    GPIO_PINS_PTE20,
    GPIO_PINS_PTE21,
    GPIO_PINS_PTE22,
    GPIO_PINS_PTE23,
    GPIO_PINS_PTE24,
    GPIO_PINS_PTE25,
    GPIO_PINS_PTE29,
    GPIO_PINS_PTE30,
    GPIO_PINS_PTE31,
    
#elif defined (FRDMKL25Z)

    GPIO_PINS_PTA0 = 0,
    GPIO_PINS_PTA1,
    GPIO_PINS_PTA2,
    GPIO_PINS_PTA3,
    GPIO_PINS_PTA4,
    GPIO_PINS_PTA5,
    GPIO_PINS_PTA12,
    GPIO_PINS_PTA13,
    GPIO_PINS_PTA14,
    GPIO_PINS_PTA15,
    GPIO_PINS_PTA16,
    GPIO_PINS_PTA17,
    GPIO_PINS_PTA18,
    GPIO_PINS_PTA19,
    GPIO_PINS_PTA20,

    GPIO_PINS_PTB0,
    GPIO_PINS_PTB1,
    GPIO_PINS_PTB2,
    GPIO_PINS_PTB3,
    GPIO_PINS_PTB8,
    GPIO_PINS_PTB9,
    GPIO_PINS_PTB10,
    GPIO_PINS_PTB11,
    GPIO_PINS_PTB16,
    GPIO_PINS_PTB17,
    GPIO_PINS_PTB18,
    GPIO_PINS_PTB19,

    GPIO_PINS_PTC0,
    GPIO_PINS_PTC1,
    GPIO_PINS_PTC2,
    GPIO_PINS_PTC3,
    GPIO_PINS_PTC4,
    GPIO_PINS_PTC5,
    GPIO_PINS_PTC6,
    GPIO_PINS_PTC7,
    GPIO_PINS_PTC8,
    GPIO_PINS_PTC9,
    GPIO_PINS_PTC10,
    GPIO_PINS_PTC11,
    GPIO_PINS_PTC12,
    GPIO_PINS_PTC13,
    GPIO_PINS_PTC16,
    GPIO_PINS_PTC17,

    GPIO_PINS_PTD0,
    GPIO_PINS_PTD1,
    GPIO_PINS_PTD2,
    GPIO_PINS_PTD3,
    GPIO_PINS_PTD4,
    GPIO_PINS_PTD5,
    GPIO_PINS_PTD6,
    GPIO_PINS_PTD7,

    GPIO_PINS_PTE0,
    GPIO_PINS_PTE1,
    GPIO_PINS_PTE2,
    GPIO_PINS_PTE3,
    GPIO_PINS_PTE4,
    GPIO_PINS_PTE5,
    GPIO_PINS_PTE20,
    GPIO_PINS_PTE21,
    GPIO_PINS_PTE22,
    GPIO_PINS_PTE23,
    GPIO_PINS_PTE24,
    GPIO_PINS_PTE25,
    GPIO_PINS_PTE29,
    GPIO_PINS_PTE30,
    GPIO_PINS_PTE31,

#elif defined (MK10DZ10)
    
    GPIO_PINS_NONE,
    
#elif defined (MK10D10)

    GPIO_PINS_PTA0 = 0,
    GPIO_PINS_PTA1,
    GPIO_PINS_PTA2,
    GPIO_PINS_PTA3,
    GPIO_PINS_PTA4,
    GPIO_PINS_PTA5,
    GPIO_PINS_PTA6,
    GPIO_PINS_PTA7,
    GPIO_PINS_PTA8,
    GPIO_PINS_PTA9,
    GPIO_PINS_PTA10,
    GPIO_PINS_PTA11,
    GPIO_PINS_PTA12,
    GPIO_PINS_PTA13,
    GPIO_PINS_PTA14,
    GPIO_PINS_PTA15,
    GPIO_PINS_PTA16,
    GPIO_PINS_PTA17,
    GPIO_PINS_PTA18,
    GPIO_PINS_PTA19,
    GPIO_PINS_PTA24,
    GPIO_PINS_PTA25,
    GPIO_PINS_PTA26,
    GPIO_PINS_PTA27,
    GPIO_PINS_PTA28,
    GPIO_PINS_PTA29,

    GPIO_PINS_PTB0,
    GPIO_PINS_PTB1,
    GPIO_PINS_PTB2,
    GPIO_PINS_PTB3,
    GPIO_PINS_PTB4,
    GPIO_PINS_PTB5,
    GPIO_PINS_PTB6,
    GPIO_PINS_PTB7,
    GPIO_PINS_PTB8,
    GPIO_PINS_PTB9,
    GPIO_PINS_PTB10,
    GPIO_PINS_PTB11,
    GPIO_PINS_PTB16,
    GPIO_PINS_PTB17,
    GPIO_PINS_PTB18,
    GPIO_PINS_PTB19,
    GPIO_PINS_PTB20,
    GPIO_PINS_PTB21,
    GPIO_PINS_PTB22,
    GPIO_PINS_PTB23,
    
    GPIO_PINS_PTC0,
    GPIO_PINS_PTC1,
    GPIO_PINS_PTC2,
    GPIO_PINS_PTC3,
    GPIO_PINS_PTC4,
    GPIO_PINS_PTC5,
    GPIO_PINS_PTC6,
    GPIO_PINS_PTC7,
    GPIO_PINS_PTC8,
    GPIO_PINS_PTC9,
    GPIO_PINS_PTC10,
    GPIO_PINS_PTC11,
    GPIO_PINS_PTC12,
    GPIO_PINS_PTC13,
    GPIO_PINS_PTC14,
    GPIO_PINS_PTC15,
    GPIO_PINS_PTC16,
    GPIO_PINS_PTC17,
    GPIO_PINS_PTC18,
    GPIO_PINS_PTC19,    
    
    GPIO_PINS_PTD0,
    GPIO_PINS_PTD1,
    GPIO_PINS_PTD2,
    GPIO_PINS_PTD3,
    GPIO_PINS_PTD4,
    GPIO_PINS_PTD5,
    GPIO_PINS_PTD6,
    GPIO_PINS_PTD7,
    GPIO_PINS_PTD8,
    GPIO_PINS_PTD9,
    GPIO_PINS_PTD10,
    GPIO_PINS_PTD11,
    GPIO_PINS_PTD12,
    GPIO_PINS_PTD13,
    GPIO_PINS_PTD14,
    GPIO_PINS_PTD15,
    
    GPIO_PINS_PTE0,
    GPIO_PINS_PTE1,
    GPIO_PINS_PTE2,
    GPIO_PINS_PTE3,
    GPIO_PINS_PTE4,
    GPIO_PINS_PTE5,
    GPIO_PINS_PTE6,
    GPIO_PINS_PTE7,
    GPIO_PINS_PTE8,
    GPIO_PINS_PTE9,
    GPIO_PINS_PTE10,
    GPIO_PINS_PTE11,
    GPIO_PINS_PTE12,
    GPIO_PINS_PTE16,
    GPIO_PINS_PTE17,
    GPIO_PINS_PTE18,
    GPIO_PINS_PTE19,
    GPIO_PINS_PTE24,
    GPIO_PINS_PTE25,
    GPIO_PINS_PTE26,
    GPIO_PINS_PTE27,
    GPIO_PINS_PTE28,
    
#endif
} Gpio_Pins;



System_Errors Gpio_config (Gpio_Pins pin, uint16_t options);

void Gpio_set (Gpio_Pins pin);
void Gpio_clear (Gpio_Pins pin);
void Gpio_toggle (Gpio_Pins pin);

Gpio_Level Gpio_get (Gpio_Pins pin);

#endif /* __GPIO_H */
