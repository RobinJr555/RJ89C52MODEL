#include "display.h"


//共阴数码管                  0     1    2    3    4    5    6    7    8    9   10    11   12  13   14 
//0100 0000                   0     1    2    3    4    5    6    7    8    9  全灭   -    A   B    C
uchar code seg_bit_table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0xff,0xbf,0x90,0x80,0xc6};//数码管显示编码
uchar code seg_num_scan[] ={0x04,0x08,0x10,0x20};//段码扫描

//单个数码管显示
void seg_1display(uint arg_segnum,uint arg_segbit)
{
	uchar i_num = 0;
	seg_num  =  seg_num_scan[arg_segnum]|seg_num;//选定第几个数码管
	seg8_bit =  seg_bit_table[arg_segbit];

}

//设定四个数码管显示
void seg_alldisplay(uint arg_segbit1,uint arg_segbit2,uint arg_segbit3,uint arg_segbit4)
{
	
}