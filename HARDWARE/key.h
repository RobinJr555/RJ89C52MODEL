#ifndef __KEY__H
#define __KEY__H
#include <reg52.h>
#include <intrins.h>
#include "delay.h"
#include "MYHEAD.h"

#define KEY_PORT P1 //设置点阵按键引脚

sbit KEY_READ 	= P1^0; //设置单个按键

uchar Keys_Scan();//点阵按键
uchar Key_Scan(uchar mode);//单个按键

#endif