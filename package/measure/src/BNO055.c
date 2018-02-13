/***************************************************************************
  This is a library for the BNO055 orientation sensor
  Designed specifically to work with the Adafruit BNO055 Breakout.
  Pick one up today in the adafruit shop!

  ------> http://www.adafruit.com/products

  These sensors use I2C to communicate, 2 pins are required to interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by KTOWN for Adafruit Industries.
  Modified for operation on a linux platform by William Gerhard

  MIT license, all text above must be included in any redistribution
 ***************************************************************************/

#include <sys/stat.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <stdio.h>      /* Standard I/O functions */
#include <stdlib.h>      /* malloc functions */
#include <fcntl.h>
#include <syslog.h>		/* Syslog functionallity */
#include <inttypes.h>
#include <errno.h>
#include <math.h>

#include "BNO055.h"

/*!
 \param bus the bus to use in /dev/i2c-%d.
 \param address the device address on bus
 */
int BNO055_init(BNO055 *D, int32_t sensorID, int address, int bus)
{
void * mi2c;
  if ((mi2c = malloc(sizeof(I2C))) == NULL) return 1; 
  D->i2c = (I2C*)mi2c;
  D->_sensorID = sensorID;
  D->_address = address;
  return I2C_init(D->i2c, bus, address);
}

void BNO055_close(BNO055 * D)
{
  free ((void*)D->i2c);
}

int BNO055_begin(BNO055 * D, int8_t mode)
{
uint8_t id;
  /* Make sure we have the right device */
  id = I2C_read_byte(D->i2c, BNO055_CHIP_ID_ADDR);
  if (id != BNO055_ID) {
    id = I2C_read_byte(D->i2c, BNO055_CHIP_ID_ADDR);
    if(id != BNO055_ID) return 0;  // still not? ok bail
  }

  /* Switch to config mode (just in case since this is the default) */
  BNO055_setMode(D, OPERATION_MODE_CONFIG);

  /* Reset */
  I2C_write_byte(D->i2c, BNO055_SYS_TRIGGER_ADDR, 0x20);
  while(I2C_read_byte(D->i2c,BNO055_CHIP_ID_ADDR)!=BNO055_ID) usleep(10000);
  usleep(50000);

  /* Set to normal power mode */
  I2C_write_byte(D->i2c, BNO055_PWR_MODE_ADDR, POWER_MODE_NORMAL);
  I2C_write_byte(D->i2c, BNO055_PAGE_ID_ADDR, 0);
  I2C_write_byte(D->i2c, BNO055_SYS_TRIGGER_ADDR, 0x0);
  
  /* Set the requested operating mode (see section 3.3) */
  BNO055_setMode(D, mode);
  return 1;
}

void BNO055_setMode(BNO055 *D, int8_t mode)
{
  D->_mode = mode;
  I2C_write_byte(D->i2c, BNO055_OPR_MODE_ADDR, mode);
  usleep(30000);
}

int8_t BNO055_getTemp(BNO055 * D)
{
  return (int8_t)I2C_read_byte(D->i2c,BNO055_TEMP_ADDR);
}

