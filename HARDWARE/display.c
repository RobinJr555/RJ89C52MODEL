#include "display.h"


//���������                  0     1    2    3    4    5    6    7    8    9   10    11   12  13   14 
//0100 0000                   0     1    2    3    4    5    6    7    8    9  ȫ��   -    A   B    C
uchar code seg_bit_table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0xff,0xbf,0x90,0x80,0xc6};//�������ʾ����
uchar code seg_num_scan[] ={0x04,0x08,0x10,0x20};//����ɨ��

//�����������ʾ
void seg_1display(uint arg_segnum,uint arg_segbit)
{
	uchar i_num = 0;
	seg_num  =  seg_num_scan[arg_segnum]|seg_num;//ѡ���ڼ��������
	seg8_bit =  seg_bit_table[arg_segbit];

}

//�趨�ĸ��������ʾ
void seg_alldisplay(uint arg_segbit1,uint arg_segbit2,uint arg_segbit3,uint arg_segbit4)
{
	
}