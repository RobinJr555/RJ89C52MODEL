#ifndef __ADC8032__H
#define __ADC8032__H
#include <reg52.h>
#include <intrins.h>
#include "MYHEAD.h"

sbit CS  = P1^0;
sbit CLK = P1^1;
sbit DIO = P1^2;

uchar Get_AD_Result(unsigned char CH);

#endif