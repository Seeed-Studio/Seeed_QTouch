/*
  QTouch Library
  2014 Copyright (c) Seeed Technology Inc.  All right reserved.

  Author: ZhangKun & Loovee
  2013-3-20
  
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <Wire.h>
#include <Arduino.h>
#include "Seeed_QTouch.h"


SeeedQTouch::SeeedQTouch()
{
    Wire.begin();
}


// Check chip ID
int SeeedQTouch::chipPresent()
{
    if (readReg(QTOUCH_REG_CHIPID) == 0x2e)
    {
        return 1;
    }
    return 0;
}

// if certain key touched, return 1 - touched, 0 untouched
unsigned char SeeedQTouch::isTouch(int key)
{
    if(key>7)return 0;                  // err input
    unsigned char st = getState();
    return ((0x01<<key)&st);            // if touched return 1, else return 0
}

// return all key state, bit0 for key0, bit1 for key1....
unsigned char SeeedQTouch::getState()
{
    return readReg(0x03);
}

int SeeedQTouch::touchNum()
{
    unsigned char state = getState();
    if(0 == state)return -1;
    
    for(int i=0; i<7; i++)
    {
        if((state>>i) & 0x01)
        {
            return i;
        }
    }
    
    return -1;
}

// Set group (0-3) for a key or disable the key (255)
int SeeedQTouch::setGroup(uint8_t key, uint8_t group) {
  uint8_t value;
  if (key > 6) {
		return -1;
	}
  if (group < 4) {
    value = readReg(QTOUCH_REG_AVEASK0 + key) & 0xfc;
		if (value == 0) {
			value = 8 << 2; //AVE default
		}
  }
  else if (group == 0xff) {
    value = 0; //Key disabled
    group = 1; //AKS default
  }
  else {
    return -1;
  }
  writeReg(QTOUCH_REG_AVEASK0 + key, value | group);
	return 0;
}


// read register
unsigned char SeeedQTouch::readReg(unsigned char addr_reg)
{

    Wire.beginTransmission(ADDR_QTOUCH);
    Wire.write(addr_reg); // register to read
    Wire.endTransmission();

    Wire.requestFrom(ADDR_QTOUCH, 1); // read a byte

    while(Wire.available()) 
    {
        return Wire.read();
    }
}

// write data to register 
unsigned char SeeedQTouch::writeReg(unsigned char addr_reg, unsigned char dta)      // write register
{
    Wire.beginTransmission(ADDR_QTOUCH);
    Wire.write(addr_reg); // register to read
    Wire.write(dta);
    Wire.endTransmission();
}

SeeedQTouch QTouch;