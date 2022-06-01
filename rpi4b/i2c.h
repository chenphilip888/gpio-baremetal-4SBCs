/*
 * Copyright 2017 Google, Inc
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#ifndef _I2C_H_
#define _I2C_H_

#include "registers.h"

#define BSC_C_I2CEN    (1 << 15)
#define BSC_C_INTR    (1 << 10)
#define BSC_C_INTT    (1 << 9)
#define BSC_C_INTD    (1 << 8)
#define BSC_C_ST    (1 << 7)
#define BSC_C_CLEAR    (1 << 4)
#define BSC_C_READ    1

#define START_READ    BSC_C_I2CEN|BSC_C_ST|BSC_C_CLEAR|BSC_C_READ
#define START_WRITE    BSC_C_I2CEN|BSC_C_ST

#define BSC_S_CLKT    (1 << 9)
#define BSC_S_ERR    (1 << 8)
#define BSC_S_RXF    (1 << 7)
#define BSC_S_TXE    (1 << 6)
#define BSC_S_RXD    (1 << 5)
#define BSC_S_TXD    (1 << 4)
#define BSC_S_RXR    (1 << 3)
#define BSC_S_TXW    (1 << 2)
#define BSC_S_DONE    (1 << 1)
#define BSC_S_TA    1

#define CLEAR_STATUS    BSC_S_CLKT|BSC_S_ERR|BSC_S_DONE

#define PAGESIZE 4096
#define BLOCK_SIZE 4096
 
/* i2c timerout */
#define I2C_TIMEOUT_MS		100
#define I2C_TIMEOUT_US		100000
#define I2C_RETRY_COUNT		3

/* i2c error return code */
#define I2C_OK			0
#define I2C_ERROR_TIMEOUT	-1
#define I2C_ERROR_NOACK		-2
#define I2C_ERROR_IO		-3

/* Clock dividor register */
#define I2C_CLKDIV_VAL(divl, divh) \
        (((divl) & 0xffff) | (((divh) << 16) & 0xffff0000))

/* rk i2c fifo max transfer bytes */
#define RK_I2C_FIFO_SIZE	32

#define I2C_MRXADDR_SET(vld, addr)	(((vld) << 24) | (addr))
#define I2C_MRXRADDR_SET(vld, raddr)	(((vld) << 24) | (raddr))

#define I2C_CON_EN		(1 << 0)
#define I2C_CON_MOD(mod)	((mod) << 1)
#define I2C_MODE_TX		0x00
#define I2C_MODE_TRX		0x01
#define I2C_MODE_RX		0x02
#define I2C_MODE_RRX		0x03
#define I2C_CON_MASK		(3 << 1)

#define I2C_CON_START		(1 << 3)
#define I2C_CON_STOP		(1 << 4)
#define I2C_CON_LASTACK		(1 << 5)
#define I2C_CON_ACTACK		(1 << 6)

#define I2C_BTFIEN		(1 << 0)
#define I2C_BRFIEN		(1 << 1)
#define I2C_MBTFIEN		(1 << 2)
#define I2C_MBRFIEN		(1 << 3)
#define I2C_STARTIEN		(1 << 4)
#define I2C_STOPIEN		(1 << 5)
#define I2C_NAKRCVIEN		(1 << 6)

#define I2C_BTFIPD              (1 << 0)
#define I2C_BRFIPD              (1 << 1)
#define I2C_MBTFIPD             (1 << 2)
#define I2C_MBRFIPD             (1 << 3)
#define I2C_STARTIPD            (1 << 4)
#define I2C_STOPIPD             (1 << 5)
#define I2C_NAKRCVIPD           (1 << 6)
#define I2C_IPD_ALL_CLEAN       0x7f

void wiringPiI2CWriteReg8( char chip, int reg, int bufi );
void set_backlight( int r, int g, int b );
void textCommand( int cmd );
void setText( char * text );
void i2c_lcd_test( void );

#endif
