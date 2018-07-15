#ifndef __DISPLAY__H
#define __DISPLAY__H
#include <reg52.h>
#include <intrins.h>
#include "delay.h"

#define uchar unsigned char
#define uint unsigned int

#define seg8_bit  P0  //ฮปัก P0  
#define seg_num   P3  //ถฮัก P3 P3.2 P3.3 P3.4 P3.5

void seg_1display(uint arg_segnum,uint arg_segbit);

#endif