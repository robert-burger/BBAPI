/**
    Character Driver for Beckhoff BIOS API
    Author: 	Patrick Brünn <p.bruenn@beckhoff.com>
    Copyright (C) 2013 - 2014  Beckhoff Automation GmbH

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

#ifndef __API_H_
#define __API_H_

#define DRV_VERSION      "1.1"
#define DRV_DESCRIPTION  "Beckhoff CCAT Ethernet/EtherCAT Network Driver"

#undef pr_fmt
#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

#include <linux/mutex.h>
#include "bbapi.h"
#include "simple_cdev.h"

/**
 * struct bbapi_object - manage access to Beckhoff BIOS functions
 * @memory: pointer to a BIOS copy in RAM
 * @entry: function pointer to the BIOS API function in RAM
 * @in: buffer to exchange data between user space and BIOS
 * @out: buffer to exchange data between BIOS and user space
 * @dev: meta data for the character device interface
 *
 * The size of the output buffer should be large enough to satisfy the
 * largest BIOS command. Right now this is: BIOSIOFFS_UEEPROM_READ.
 */
struct bbapi_object {
	void *memory;
	void *entry;
	char in[BBAPI_BUFFER_SIZE];
	char out[BBAPI_BUFFER_SIZE];
	struct simple_cdev dev;
	struct mutex mutex;
};
#endif /* #ifndef __API_H_ */
