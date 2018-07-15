#ifndef __DS18B20__H
#define __DS18B20__H
#include <reg52.h>
#include <intrins.h>
#include "MYHEAD.h"
#include "delay.h"

sbit DQ = P3^3; //DS18B20ÊäÈë¿Ú
bit  DS18B20_IS_OK = 1;

uchar Init_DS18B20();
uchar ReadOneByte();
void WriteOneByte(uchar dat);
void Read_Temperature(uchar* Temp_Value);

#endif