/*
 * This file is part of the libohiboard project.
 *
 * Copyright (C) 2018 A. C. Open Hardware Ideas Lab
 *
 * Authors:
 *   Marco Giammarini <m.giammarini@warcomeb.it>
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
 */

/**
 * @file libohiboard/include/hardware/adc_STM32L4.h
 * @author Marco Giammarini <m.giammarini@warcomeb.it>
 * @brief ADC pins and device definitions for STM32L4 series
 */

#ifndef __ADC_STM32L4_H
#define __ADC_STM32L4_H

#ifdef __cplusplus
extern "C" {
#endif

#include "platforms.h"

#if defined(LIBOHIBOARD_ADC) & defined(LIBOHIBOARD_STM32L4)

#define ADC_CHANNEL_MASK                 (0x00FF0000u)
#define ADC_CHANNEL_POS                  (16u)

#define ADC_CHANNEL_INTERNAL_ADC1        (0x00000100u)
#define ADC_CHANNEL_INTERNAL_ADC2        (0x00000200u)
#define ADC_CHANNEL_INTERNAL_ADC3        (0x00000300u)

#define ADC_SMPR_REGOFFSET_1             (0x00000000u)
#define ADC_SMPR_REGOFFSET_2             (0x00001000u)
#define ADC_SMPR_REGOFFSET_MASK          (0x0000F000u)
#define ADC_SMPR_REGOFFSET_POS           (12u)

#define ADC_SMPR_SMPX_MASK               (0x000000FFu)

typedef enum _Adc_Pins
{
    ADC_PINS_PA0,
    ADC_PINS_PA1,
    ADC_PINS_PA2,
    ADC_PINS_PA3,
    ADC_PINS_PA4,
    ADC_PINS_PA5,
    ADC_PINS_PA6,
    ADC_PINS_PA7,

    ADC_PINS_PB0,
    ADC_PINS_PB1,

    ADC_PINS_PC0,
    ADC_PINS_PC1,
    ADC_PINS_PC2,
    ADC_PINS_PC3,
    ADC_PINS_PC4,
    ADC_PINS_PC5,

    ADC_PINS_INTERNAL,
} Adc_Pins;

typedef enum _Adc_Channels
{
    ADC_CHANNELS_CH0         = (0x00000000u | ADC_SMPR_REGOFFSET_1 | ADC_SMPR1_SMP0_Pos),
    ADC_CHANNELS_CH1         = (0x00010000u | ADC_SMPR_REGOFFSET_1 | ADC_SMPR1_SMP1_Pos),
    ADC_CHANNELS_CH2         = (0x00020000u | ADC_SMPR_REGOFFSET_1 | ADC_SMPR1_SMP2_Pos),
    ADC_CHANNELS_CH3         = (0x00030000u | ADC_SMPR_REGOFFSET_1 | ADC_SMPR1_SMP3_Pos),
    ADC_CHANNELS_CH4         = (0x00040000u | ADC_SMPR_REGOFFSET_1 | ADC_SMPR1_SMP4_Pos),
    ADC_CHANNELS_CH5         = (0x00050000u | ADC_SMPR_REGOFFSET_1 | ADC_SMPR1_SMP5_Pos),
    ADC_CHANNELS_CH6         = (0x00060000u | ADC_SMPR_REGOFFSET_1 | ADC_SMPR1_SMP6_Pos),
    ADC_CHANNELS_CH7         = (0x00070000u | ADC_SMPR_REGOFFSET_1 | ADC_SMPR1_SMP7_Pos),
    ADC_CHANNELS_CH8         = (0x00080000u | ADC_SMPR_REGOFFSET_1 | ADC_SMPR1_SMP8_Pos),
    ADC_CHANNELS_CH9         = (0x00090000u | ADC_SMPR_REGOFFSET_1 | ADC_SMPR1_SMP9_Pos),
    ADC_CHANNELS_CH10        = (0x000A0000u | ADC_SMPR_REGOFFSET_2 | ADC_SMPR2_SMP10_Pos),
    ADC_CHANNELS_CH11        = (0x000B0000u | ADC_SMPR_REGOFFSET_2 | ADC_SMPR2_SMP11_Pos),
    ADC_CHANNELS_CH12        = (0x000C0000u | ADC_SMPR_REGOFFSET_2 | ADC_SMPR2_SMP12_Pos),
    ADC_CHANNELS_CH13        = (0x000D0000u | ADC_SMPR_REGOFFSET_2 | ADC_SMPR2_SMP13_Pos),
    ADC_CHANNELS_CH14        = (0x000E0000u | ADC_SMPR_REGOFFSET_2 | ADC_SMPR2_SMP14_Pos),
    ADC_CHANNELS_CH15        = (0x000F0000u | ADC_SMPR_REGOFFSET_2 | ADC_SMPR2_SMP15_Pos),
    ADC_CHANNELS_CH16        = (0x00100000u | ADC_SMPR_REGOFFSET_2 | ADC_SMPR2_SMP16_Pos),
    ADC_CHANNELS_CH17        = (0x00110000u | ADC_SMPR_REGOFFSET_2 | ADC_SMPR2_SMP17_Pos),
    ADC_CHANNELS_CH18        = (0x00120000u | ADC_SMPR_REGOFFSET_2 | ADC_SMPR2_SMP18_Pos),

    ADC_CHANNELS_VREFINT     = (0x00000000u | ADC_SMPR_REGOFFSET_1 | ADC_SMPR1_SMP0_Pos  | ADC_CHANNEL_INTERNAL_ADC1),
    ADC_CHANNELS_TEMPERATURE = (0x00110000u | ADC_SMPR_REGOFFSET_2 | ADC_SMPR2_SMP17_Pos | ADC_CHANNEL_INTERNAL_ADC1),
    ADC_CHANNELS_VBAT        = (0x00120000u | ADC_SMPR_REGOFFSET_2 | ADC_SMPR2_SMP18_Pos | ADC_CHANNEL_INTERNAL_ADC1),

    ADC_CHANNELS_DAC1_ADC2   = (0x00110000u | ADC_SMPR_REGOFFSET_2 | ADC_SMPR2_SMP17_Pos | ADC_CHANNEL_INTERNAL_ADC2),
    ADC_CHANNELS_DAC2_ADC2   = (0x00120000u | ADC_SMPR_REGOFFSET_2 | ADC_SMPR2_SMP18_Pos | ADC_CHANNEL_INTERNAL_ADC2),

    ADC_CHANNELS_DAC1_ADC3   = (0x000E0000u | ADC_SMPR_REGOFFSET_2 | ADC_SMPR2_SMP14_Pos | ADC_CHANNEL_INTERNAL_ADC3),
    ADC_CHANNELS_DAC2_ADC3   = (0x000F0000u | ADC_SMPR_REGOFFSET_2 | ADC_SMPR2_SMP15_Pos | ADC_CHANNEL_INTERNAL_ADC3),

} Adc_Channels;


#define ADC_SQR_REGOFFSET_1              (0x00000000u)
#define ADC_SQR_REGOFFSET_2              (0x00010000u)
#define ADC_SQR_REGOFFSET_3              (0x00020000u)
#define ADC_SQR_REGOFFSET_4              (0x00030000u)
#define ADC_SQR_REGOFFSET_MASK           (0x000F0000u)
#define ADC_SQR_REGOFFSET_POS            (16u)

#define ADC_SQR_SHIFT_MASK               (0x000000FFu)
#define ADC_SQR_SHIFT_POS                (0u)

/**
 *
 */
typedef enum _Adc_SequencePosition
{
    ADC_SEQUENCEPOSITION_1   = (ADC_SQR1_SQ1_Pos  | ADC_SQR_REGOFFSET_1),
    ADC_SEQUENCEPOSITION_2   = (ADC_SQR1_SQ2_Pos  | ADC_SQR_REGOFFSET_1),
    ADC_SEQUENCEPOSITION_3   = (ADC_SQR1_SQ3_Pos  | ADC_SQR_REGOFFSET_1),
    ADC_SEQUENCEPOSITION_4   = (ADC_SQR1_SQ4_Pos  | ADC_SQR_REGOFFSET_1),
    ADC_SEQUENCEPOSITION_5   = (ADC_SQR2_SQ5_Pos  | ADC_SQR_REGOFFSET_2),
    ADC_SEQUENCEPOSITION_6   = (ADC_SQR2_SQ6_Pos  | ADC_SQR_REGOFFSET_2),
    ADC_SEQUENCEPOSITION_7   = (ADC_SQR2_SQ7_Pos  | ADC_SQR_REGOFFSET_2),
    ADC_SEQUENCEPOSITION_8   = (ADC_SQR2_SQ8_Pos  | ADC_SQR_REGOFFSET_2),
    ADC_SEQUENCEPOSITION_9   = (ADC_SQR2_SQ9_Pos  | ADC_SQR_REGOFFSET_2),
    ADC_SEQUENCEPOSITION_10  = (ADC_SQR3_SQ10_Pos | ADC_SQR_REGOFFSET_3),
    ADC_SEQUENCEPOSITION_11  = (ADC_SQR3_SQ11_Pos | ADC_SQR_REGOFFSET_3),
    ADC_SEQUENCEPOSITION_12  = (ADC_SQR3_SQ12_Pos | ADC_SQR_REGOFFSET_3),
    ADC_SEQUENCEPOSITION_13  = (ADC_SQR3_SQ13_Pos | ADC_SQR_REGOFFSET_3),
    ADC_SEQUENCEPOSITION_14  = (ADC_SQR3_SQ14_Pos | ADC_SQR_REGOFFSET_3),
    ADC_SEQUENCEPOSITION_15  = (ADC_SQR4_SQ15_Pos | ADC_SQR_REGOFFSET_4),
    ADC_SEQUENCEPOSITION_16  = (ADC_SQR4_SQ16_Pos | ADC_SQR_REGOFFSET_4),

} Adc_SequencePosition;

/**
 * Channel sampling time.
 * This value must be set for each channel.
 */
typedef enum _Adc_SamplingTime
{
    ADC_SAMPLINGTIME_2_ADCCLK_5   = (0x00000000u),
    ADC_SAMPLINGTIME_6_ADCCLK_5   = (ADC_SMPR1_SMP0_0),
    ADC_SAMPLINGTIME_12_ADCCLK_5  = (ADC_SMPR1_SMP0_1),
    ADC_SAMPLINGTIME_24_ADCCLK_5  = (ADC_SMPR1_SMP0_1 | ADC_SMPR1_SMP0_0),
    ADC_SAMPLINGTIME_47_ADCCLK_5  = (ADC_SMPR1_SMP0_2),
    ADC_SAMPLINGTIME_92_ADCCLK_5  = (ADC_SMPR1_SMP0_2 | ADC_SMPR1_SMP0_0),
    ADC_SAMPLINGTIME_247_ADCCLK_5 = (ADC_SMPR1_SMP0_2 | ADC_SMPR1_SMP0_1),
    ADC_SAMPLINGTIME_640_ADCCLK_5 = (ADC_SMPR1_SMP0_2 | ADC_SMPR1_SMP0_1 | ADC_SMPR1_SMP0_0),

} Adc_SamplingTime;

#endif // LIBOHIBOARD_RTC & LIBOHIBOARD_STM32L4

#ifdef __cplusplus
}
#endif

#endif // __ADC_STM32L4_H