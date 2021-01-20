#include "reg52.h"
typedef unsigned int u16;
typedef unsigned char u8;

/*关键字定义*//*flag说明：0\1用于毫秒计时，2,3用于闹钟设定，4用于时钟设定，5用于毫秒计时设定*/
int Display[8],Display4ms[8],DisplayAlarm[8],DisplayMT[8],flag[7]={0},
		notice_on[8]={0x3f,0x37,0x00,0x00,0x00,0x00,0x00,0x00},
		notice_off[8]={0x3f,0x71,0x71,0x00,0x00,0x00,0x00,0x00};
short key=0;

/*I/O定义*/
sbit BT2 = P3^0;
sbit BT1 = P3^1;
sbit BT3 = P3^2;
sbit BT4 = P3^3;
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
sbit beep=P1^5;

/*计时时间定义*/
u16 clock[4]={0};
/*u16 hours=0,minutes=0,seconds=0,ms=0;/*

/*毫秒计时时间定义*/
u16 min=0,sec=0,ms2=0;
u16 msAlarm[4]={0};

/*闹钟时间定义*/
u16 alarm[4]={0};
/*u16 hrs=0,mins=0,secs=0;*/

/*数码管段码数组定义,0~F*/
u16 code smgduan[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
											0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};