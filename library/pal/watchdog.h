/*
 *  Watchdog maintenance routines
 *
 *  Copyright (C) 2016, Michael Froehlich
 *  SPDX-License-Identifier: Apache-2.0
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may
 *  not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  This file is part of mbed TLS (https://tls.mbed.org)
 */
/*
 * The software watchdog on the ESP8266 likes to trip on long running bignum.c
 * calculations. This file adds a definition that is used in bignum.c to prevent
 * the watchdog from tripping.
 *
 */

#ifndef MBEDTLS_PAL_WATCHDOG_H
#define MBEDTLS_PAL_WATCHDOG_H


#if defined(ESP8266)

/* Do not pull in the full set of Expressif headers here.
 */
void system_soft_wdt_feed(void);

#define RESET_WATCHDOG()  system_soft_wdt_feed()

#else

#define RESET_WATCHDOG()

#endif 

#endif // #ifndef MBEDTLS_PAL_WATCHDOG_H
