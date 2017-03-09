/******************************************************************************
 * Copyright (C) 2016-2017 A. C. Open Hardware Ideas Lab
 *
 * Authors:
 *  Matteo Civale
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
 * @file libohiboard/source/ethernet-utility.c
 * @author Matteo Civale
 * @brief network utility implementation.
 */

#ifdef LIBOHIBOARD_ETHERNET

#include "ethernet-utility.h"

void Ethernet_networkConfig (struct netif *netif, Ethernet_NetworkConfig *config)
{
#ifdef LIBOHIBOARD_ETHERNET_LWIP_1_4_1

    // Disable MPU
    MPU_CESR &=~ MPU_CESR_VLD_MASK;

    lwip_init();

    LWIPPorting_setMacAddress(config->mac);
    // Set PHY initialization callback
    LWIPPorting_setPhyCallback(config->phyCallback);

    // Set timer callback
    LWIPPorting_setTimerCallback(config->timerCallback);

    // Initialize network interface
    netif_add(netif, &config->ip, &config->mask, &config->gateway, 0, LWIPPorting_init, ethernet_input);
    netif_set_default(netif);
    netif_set_up(netif);
#endif
}

#endif /* LIBOHIBOARD_ETHERNET */
