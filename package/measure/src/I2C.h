/*
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 * Name        : I2C.h
 * Author      : Georgi Todorov
 * Version     :
 * Created on  : Dec 30, 2012
 *
 * Copyright © 2012 Georgi Todorov  <terahz@geodar.com>
 */

#ifndef I2C_H_
#define I2C_H_
#include <inttypes.h>

#define BUFFER_SIZE 0x01  //1 byte buffer

struct devi2c {
    int _i2caddr;
    int _i2cbus;
    int fd;
    uint8_t dataBuffer[BUFFER_SIZE];
    char busfile[64];
};
typedef struct devi2c I2C;

int I2C_init(I2C * dev,int bus, int address);
void I2C_close(I2C * dev);
uint8_t I2C_read_byte(I2C * dev,uint8_t address);
uint8_t I2C_read_length(I2C * dev,uint8_t, uint8_t, uint8_t*);
uint8_t I2C_write_byte(I2C * dev,uint8_t, uint8_t);

#endif /* I2C_H_ */
