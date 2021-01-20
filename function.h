#include "define.h"
/*时间进制换算函数*/
/*0为时间设置换算模式，1为正常计时换算模式*/
void TimeCalc(int n,u16 * clock)
{
	if(clock[2]==60)
	{
		if(n!=0)
		clock[1]++;
		clock[2]=0;
	}
	if(clock[1]==60)
	{
		if(n!=0)
		clock[0]++;
		clock[1]=0;
	}
	if(clock[0]==24)
	{
		clock[0]=0;
	}
	if(clock[2]>60)
	{
		clock[2]=59;
		}
	if(clock[1]>60)
	{
		clock[1]=59;
		}
	if(clock[0]>24)
	{
		clock[0]=23;
		}
}
/*延时函数*/
void delay(u16 i)
{
	while(i--);
}

/*计时特征函数*/
void datapros()
{
	Display[0]=smgduan[clock[0]/10];
	Display[1]=smgduan[clock[0]%10];
	Display[2]=0x40;	
	Display[3]=smgduan[clock[1]/10];
	Display[4]=smgduan[clock[1]%10];
	Display[5]=0x40;
	Display[6]=smgduan[clock[2]/10];
	Display[7]=smgduan[clock[2]%10];
}

/*毫秒计时特征函数*/
void datapros4ms()
{
	Display4ms[0]=smgduan[min/10];
	Display4ms[1]=smgduan[min%10];
	Display4ms[2]=0x40;	
	Display4ms[3]=smgduan[sec/10];
	Display4ms[4]=smgduan[sec%10];
	Display4ms[5]=0x40;
	Display4ms[6]=smgduan[ms2/10];
	Display4ms[7]=smgduan[ms2%10];
}
/*毫秒闹钟特征函数*/
void dataprosMT()
{
	DisplayMT[0]=smgduan[msAlarm[0]/10];
	DisplayMT[1]=smgduan[msAlarm[0]%10];
	DisplayMT[2]=0x40;	
	DisplayMT[3]=smgduan[msAlarm[1]/10];
	DisplayMT[4]=smgduan[msAlarm[1]%10];
	DisplayMT[5]=0x40;
	DisplayMT[6]=smgduan[msAlarm[2]/10];
	DisplayMT[7]=smgduan[msAlarm[2]%10];
}
/*闹钟特征函数*/
void dataprosA()
{
	DisplayAlarm[0]=smgduan[alarm[0]/10];
	DisplayAlarm[1]=smgduan[alarm[0]%10];
	DisplayAlarm[2]=0x40;	
	DisplayAlarm[3]=smgduan[alarm[1]/10];
	DisplayAlarm[4]=smgduan[alarm[1]%10];
	DisplayAlarm[5]=0x40;
	DisplayAlarm[6]=smgduan[alarm[2]/10];
	DisplayAlarm[7]=smgduan[alarm[2]%10];
}
/*段码发送函数*/
void smgsend(int * prop)
{
	u8 i;
	for(i=0;i<8;i++)
	{
	switch(i)
	{
		  case(0):
				LSA=1;LSB=1;LSC=1; break;
			case(1):
				LSA=0;LSB=1;LSC=1; break;
			case(2):
				LSA=1;LSB=0;LSC=1; break;
			case(3):	
				LSA=0;LSB=0;LSC=1; break;
			case(4):
				LSA=1;LSB=1;LSC=0; break;
			case(5):
				LSA=0;LSB=1;LSC=0; break;
			case(6):
				LSA=1;LSB=0;LSC=0; break;
			case(7):
				LSA=0;LSB=0;LSC=0; break;	
		}
	P0=prop[i];
	delay(100);
	P0=0x00;
	}
}

/*按键检测函数*/
int KeyScan()
{
	if(BT1==0)
	{
		delay(100);
		if(BT1==0)
			return 1;
	}
	if(BT2==0)
	{
		delay(100);
		if(BT2==0)
			return 2;
	}
	if(BT3==0)
	{
		delay(100);
		if(BT3==0)
			return 3;
	}
	if(BT4==0)
	{
		delay(100);
		if(BT4==0)
			return 4;
	}
	else return 0;
}
/*毫秒计数器换算函数*/
void msCalc()
{
		if(sec>=60)
		{
			sec=0;
			min++;
			if(min>=60)
			{
				min=0;
			}
		}	
}
