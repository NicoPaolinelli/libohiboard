/******************************************************************************
 * Copyright (C) 2014 A. C. Open Hardware Ideas Lab
 * 
 * Authors:
 *  Francesco Piunti <francesco.piunti89@gmail.com>
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
 * @file libohiboard/include/dac.h
 * @author Francesco Piunti <francesco.piunti89@gmail.com>
 * @author Marco Giammarini <m.giammarini@warcomeb.it>
 * @brief DAC definitions and prototypes.
 */

#ifdef LIBOHIBOARD_DAC

#ifndef __DAC_H
#define __DAC_H

#include "platforms.h"
#include "errors.h"
#include "types.h"

typedef enum {
    DAC_VOLTAGEREF_VDDA,
    DAC_VOLTAGEREF_VOUT
} Dac_VoltageRef;

typedef enum 
{
    DAC_TRIGGER_HARDWARE = 0x00,
    DAC_TRIGGER_SOFTWARE = 0x01,

} Dac_TriggerSelect;

//typedef enum
//{
//
//}Dac_TriggerSource;



typedef enum 
{
    DAC_POWERMODE_LOW,
    DAC_POWERMODE_HIGH
} Dac_PowerMode;

typedef enum 
{
    DAC_BUFFERMODE_OFF,
    DAC_BUFFERMODE_NORMAL,
    DAC_BUFFERMODE_SWING,
    DAC_BUFFERMODE_ONETIME
} Dac_BufferMode;


typedef enum
{
	DAC_POINTER_NO_EVENT,
	DAC_POINTER_TOP,
	DAC_POINTER_BOTTOM,
	DAC_POINTER_BOOTH

}Dac_InterruptEvent;

typedef enum
{
    DAC_BUFFER_MODE_NORMAL  = 0x0,
	DAC_BUFFER_MODE_OT_SCAN = 0x1,

}Dac_bufferMode;


typedef struct Dac_Device* Dac_DeviceHandle;

#if defined (LIBOHIBOARD_K10D10)

extern Dac_DeviceHandle DAC0;
extern Dac_DeviceHandle DAC1;

#elif defined (LIBOHIBOARD_K12D5)

extern Dac_DeviceHandle OB_DAC0;

#elif defined (LIBOHIBOARD_K60DZ10) || \
      defined (LIBOHIBOARD_OHIBOARD_R1)

#elif defined (LIBOHIBOARD_KL25Z4)  || \
      defined (LIBOHIBOARD_FRDMKL25Z)

extern Dac_DeviceHandle OB_DAC0;

#elif defined (LIBOHIBOARD_K64F12)     || \
      defined (LIBOHIBOARD_FRDMK64F)

extern Dac_DeviceHandle DAC0;
extern Dac_DeviceHandle DAC1;

#endif

typedef struct _Dac_Config
{
    Dac_VoltageRef ref;
    
    Dac_PowerMode powerMode;
    
    Dac_TriggerSelect trigger;
    Dac_BufferMode buffer;

    bool dmaEnable;
    Dac_InterruptEvent interruptEvent;
    Dac_bufferMode bufferMode;


} Dac_Config;



System_Errors Dac_init (Dac_DeviceHandle dev, void *callback, Dac_Config *config);

System_Errors Dac_writeValue (Dac_DeviceHandle dev, uint16_t value);

System_Errors enableDmaTrigger(Dac_DeviceHandle dev, Dac_InterruptEvent event);

#endif /* __DAC_H */

#endif /* LIBOHIBOARD_DAC */
