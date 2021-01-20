#include "function.h"
/*时间设置*/
void TimeSet()
{
		while(1)
		{
			TimeCalc(0,clock);
			datapros();
			smgsend(Display);
			key=KeyScan();
			if(key==1)
			{delay(20000);clock[flag[4]]++;}
			else if(key==2)
			{delay(20000);clock[flag[4]]--;}
			else if(key==3)
			{delay(20000);flag[4]=2;break;}
			else if(key==4)
			{
				delay(20000);
				if(flag[4]==0)
					flag[4]=2;
				else
					flag[4]--;
			}
		}
}
/*毫秒计时器*/
void msTimer()
{
	msAlarm[0]=msAlarm[1]=msAlarm[2]=0;/*初始化*/
	EX0=0;
	while(1)
	{
start:
		ms2=0;
		sec=0;
		datapros4ms();
		smgsend(Display4ms);
		key = KeyScan();
		if(key==1)/*开始计时*/
		{
			delay(10000);
			flag[1] = 1;			
			while(1)
			{
pause:
				msCalc();
				datapros4ms();
				smgsend(Display4ms);
				if(msAlarm[0]==min && msAlarm[1]==sec && flag[5]==1)/*闹钟触发条件*/
				{
					flag[1]=0;
					while(1)
					{
						int i=100;
						smgsend(DisplayMT);
						while(i)
						{
							i--;
							beep=~beep;
							delay(100);
						}
						key = KeyScan();
						if(key==1)
						{delay(20000);goto start;}
					}
				}
				key = KeyScan();/*暂停*/
				if(key==1)
				{
					delay(10000);
					flag[1] = 0;
					while(1)
					{
						msCalc();
						datapros4ms();
						smgsend(Display4ms);
						key = KeyScan();
						if(key==1)/*继续*/
						{
							delay(10000);
							flag[1] = 1;
							goto pause;
						}
						if(key==3)/*退出*/
						{delay(20000);goto end;}
						if(key==2)/*清零*/
						{
							delay(20000);
							ms2=min=sec=0;
							goto start;
						}
						if(key==4)/*闹钟设置*/
						{
							delay(20000);
setting:			flag[0]=2;
							while(1)
							{
								TimeCalc(0,msAlarm);
								dataprosMT();
								smgsend(DisplayMT);
								key=KeyScan();
								if(key==1)
								{delay(20000);msAlarm[flag[0]]++;}
								else if(key==2)
								{delay(20000);msAlarm[flag[0]]--;}
								else if(key==3)
								{delay(20000);flag[0]=2;;break;}
								else if(key==4)
								{
									delay(20000);
								if(flag[0]==0)
								{
									while(1)/*闹钟开关*/
									{
										if(flag[5]==0)
										{
											smgsend(notice_off);/*闹钟关闭状态表示*/
											key = KeyScan();
											if(key==1)
											{delay(20000);flag[5]=1;}
											if(key==4)
											{delay(20000);break;}
										}
										else if(flag[5]==1)
										{
											smgsend(notice_on);/*闹钟启用状态表示*/
											key = KeyScan();
											if(key==1)
											{delay(20000);flag[5]=0;}
											if(key==4)
											{delay(20000);break;}
										}
									}
								flag[0]=2;
								}
							else
								flag[0]--;
								}
							}
						}
					}
				}
			}
		}
		else if(key==3)
		{delay(20000);goto end;}
		else if(key==4)
		{delay(20000);goto setting;}
	}
	end: EX0=1;flag[5]=0;
}
/*闹钟设置*/
void AlarmSet()
{
	while(1)
	{
			TimeCalc(0,alarm);
			dataprosA();
			smgsend(DisplayAlarm);
			key=KeyScan();
			if(key==1)
			{delay(20000);alarm[flag[2]]++;}
			else if(key==2)
			{delay(20000);alarm[flag[2]]--;}
			else if(key==3)
			{delay(20000);EX0=1;break;}
			else if(key==4)
			{
				delay(20000);
				if(flag[2]==0)
				{
					while(1)/*闹钟开关*/
				{
					if(flag[3]==0)
					{
						smgsend(notice_off);/*闹钟关闭状态表示*/
						key = KeyScan();
						if(key==1)
						{delay(20000);flag[3]=1;}
						if(key==4)
						{delay(20000);break;}
					}
					else if(flag[3]==1)
					{
						smgsend(notice_on);/*闹钟启用状态表示*/
						key = KeyScan();
						if(key==1)
						{delay(20000);flag[3]=0;}
						if(key==4)
						{delay(20000);break;}
					}
				}
					flag[2]=2;
				}
				else
					flag[2]--;
			}
		}
}