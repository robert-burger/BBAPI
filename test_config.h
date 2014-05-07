/**
    Beckhoff BIOS API driver to access hwmon sensors for Beckhoff IPCs
    Copyright (C) 2014  Beckhoff Automation GmbH
    Author: Patrick Bruenn <p.bruenn@beckhoff.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/
#ifndef _TEST_CONFIG_H_
#define _TEST_CONFIG_H_

/** select test device */
#define DEVICE_CX2030_CX2100_0004 0x21000004
#define DEVICE_CX2030_CX2100_0904 0x21000904
#define DEVICE_CX5000 0x5000

//#define TEST_DEVICE DEVICE_CX5000
#define TEST_DEVICE DEVICE_CX2030_CX2100_0904

/** reused ranges */
#define BOOTCOUNTER_RANGE 1, 1500
#define OPERATION_TIME_RANGE  1, 200000
#define _24VOLT_RANGE 23600, 28000
#define CONFIG_CXPWRSUPP_TEMP_RANGE -35, 85


/** general configuration */
#if (TEST_DEVICE == DEVICE_CX5000)
#define CONFIG_GENERAL_BOARDINFO {"CX553\0", 1, 0, 128}
#define CONFIG_GENERAL_BOARDNAME "CBxx53\0\0\0\0\0\0\0\0\0"
#define CONFIG_GENERAL_VERSION {1, 21, 1}
#elif (TEST_DEVICE == DEVICE_CX2030_CX2100_0904)
#define CONFIG_GENERAL_BOARDINFO {"CX20x0\0", 2, 1, 52}
#define CONFIG_GENERAL_BOARDNAME "CX20x0\0\0\0\0\0\0\0\0\0"
#define CONFIG_GENERAL_VERSION {2, 9, 1}
#else
#define CONFIG_GENERAL_BOARDINFO {"CX20x0\0", 1, 1, 52}
#define CONFIG_GENERAL_BOARDNAME "CX20x0\0\0\0\0\0\0\0\0\0"
#define CONFIG_GENERAL_VERSION {2, 9, 1}
#endif
#if defined(__i386__)
#define CONFIG_GENERAL_PLATFORM 0x00
#elif defined(__x86_64__)
#define CONFIG_GENERAL_PLATFORM 0x01
#endif

/** PWRCTRL configuration */
#define CONFIG_PWRCTRL_BL_REVISION {0, 14, 0}
#if (TEST_DEVICE == DEVICE_CX5000)
#define CONFIG_PWRCTRL_FW_REVISION {0, 17, 50}
#else
#define CONFIG_PWRCTRL_FW_REVISION {0, 17, 36}
#endif
#define CONFIG_PWRCTRL_DEVICE_ID 0xD
#define CONFIG_PWRCTRL_OPERATION_TIME_RANGE OPERATION_TIME_RANGE
#define CONFIG_PWRCTRL_MIN_TEMP_RANGE 10, 20
#define CONFIG_PWRCTRL_MAX_TEMP_RANGE 70, 112
#define CONFIG_PWRCTRL_MIN_VOLT_RANGE 49, 50
#define CONFIG_PWRCTRL_MAX_VOLT_RANGE 49, 50
#if (TEST_DEVICE == DEVICE_CX2030_CX2100_0904)
#define CONFIG_PWRCTRL_SERIAL "09922514060066"
#define CONFIG_PWRCTRL_PRODUCTION_DATE {16, 14}
#define CONFIG_PWRCTRL_TEST_COUNT 1
#define CONFIG_PWRCTRL_TEST_NUMBER "120200"
#else
#define CONFIG_PWRCTRL_SERIAL "0000000000000000"
#define CONFIG_PWRCTRL_PRODUCTION_DATE {0, 0}
#define CONFIG_PWRCTRL_TEST_COUNT 0
#define CONFIG_PWRCTRL_TEST_NUMBER "000000"
#endif
#define CONFIG_PWRCTRL_BOOT_COUNTER_RANGE BOOTCOUNTER_RANGE
#define CONFIG_PWRCTRL_POSITION 0x00
#define CONFIG_PWRCTRL_LAST_SHUTDOWN {0, 0, 0}

/** S-UPS configuration */
#if (TEST_DEVICE == DEVICE_CX5000)
#define CONFIG_SUPS_DISABLED 0
#else
#define CONFIG_SUPS_DISABLED 1
#endif
#define CONFIG_SUPS_STATUS_OFF 0xAF
#define CONFIG_SUPS_STATUS_100 0xCA
#define CONFIG_SUPS_REVISION {1, 9}
#define CONFIG_SUPS_POWERFAILCOUNT 21
#define CONFIG_SUPS_PWRFAIL_TIMES {393, 1533, 1620}
#define CONFIG_SUPS_SHUTDOWN_TYPE 0xFF
#define CONFIG_SUPS_ACTIVE_COUNT 0
#define CONFIG_SUPS_INTERNAL_PWRF_STATUS 0
#define CONFIG_SUPS_TEST_RESULT 0
#define CONFIG_SUPS_GPIO_PIN {0x480, 0x28, 0x1}

/** CX Power Supply configuration */
#if (TEST_DEVICE == DEVICE_CX5000)
#define CONFIG_CXPWRSUPP_DISABLED 1
#define CONFIG_CXPWRSUPP_TYPE 0
#define CONFIG_CXPWRSUPP_SERIALNO 0
#elif (TEST_DEVICE == DEVICE_CX2030_CX2100_0004)
#define CONFIG_CXPWRSUPP_DISABLED 0
#define CONFIG_CXPWRSUPP_TYPE 4        //CX2100-0004
#define CONFIG_CXPWRSUPP_SERIALNO 1467 //CX2100-0004
#else
#define CONFIG_CXPWRSUPP_DISABLED 0
#define CONFIG_CXPWRSUPP_TYPE 904      //CX2100-0904
#define CONFIG_CXPWRSUPP_SERIALNO 834  //CX2100-0904
#endif
#define CONFIG_CXPWRSUPP_FWVERSION {5, 0}
#define CONFIG_CXPWRSUPP_BOOTCOUNTER_RANGE BOOTCOUNTER_RANGE
#define CONFIG_CXPWRSUPP_OPERATIONTIME_RANGE OPERATION_TIME_RANGE
#define CONFIG_CXPWRSUPP_5VOLT_RANGE 5000, 5100
#define CONFIG_CXPWRSUPP_12VOLT_RANGE 12000, 12350
#define CONFIG_CXPWRSUPP_24VOLT_RANGE _24VOLT_RANGE
#define CONFIG_CXPWRSUPP_TEMP_RANGE -35, 85
#define CONFIG_CXPWRSUPP_CURRENT_RANGE 640, 4550
#define CONFIG_CXPWRSUPP_POWER_RANGE 10000, 101000
#define CONFIG_CXPWRSUPP_BUTTON_STATE 0x00

/** CX UPS configuration */
#if (TEST_DEVICE == DEVICE_CX5000)
#define CONFIG_CXUPS_DISABLED 1
#else
#define CONFIG_CXUPS_DISABLED 0
#endif
#define CONFIG_CXUPS_ENABLED !CONFIG_CXUPS_DISABLED

#define CONFIG_CXUPS_FIRMWAREVER {1, 0}
#define CONFIG_CXUPS_POWERSTATUS 1 // (BYTE) (0 := Unknown, 1 := Online, 2 := OnBatteries)
#define CONFIG_CXUPS_BATTERYSTATUS 1 // (BYTE) (0 := Unknown, 1 := Ok, 2 := Change batteries)
#define CONFIG_CXUPS_BATTERYCAPACITY 100
#define CONFIG_CXUPS_BATTERYRUNTIME_RANGE 1, 180
#define CONFIG_CXUPS_BOOTCOUNTER_RANGE 0, 0 //TODO obsolete?
#define CONFIG_CXUPS_OPERATIONTIME_RANGE OPERATION_TIME_RANGE
#define CONFIG_CXUPS_POWERFAILCOUNT	0
#define CONFIG_CXUPS_BATTERYCRITICAL 0
#define CONFIG_CXUPS_BATTERYPRESENT	1
#define CONFIG_CXUPS_OUTPUTVOLT_RANGE 9000, 12000
#define CONFIG_CXUPS_INPUTVOLT_RANGE _24VOLT_RANGE
#define CONFIG_CXUPS_CURRENT 0
#define CONFIG_CXUPS_CURRENT_RANGE 8000, 10000
#define CONFIG_CXUPS_POWER 0
#define CONFIG_CXUPS_POWER_RANGE 20000, 100000
#define CONFIG_CXUPS_TEMP_RANGE 0, 85

#endif /* #ifndef _TEST_CONFIG_H_ */
