#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int Password,Count=0;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	while(1)
	{
		LCD_ShowNum(2,1,Password,4);
		KeyNum=MatrixKey();
		if(KeyNum)
		{
			if(KeyNum<=10)  //如果S1到S10按键按下，输入密码
			{
				if(Count<4)
				{					
					Password*=10;
					Password+=KeyNum%10;
					Count++;
				}
				LCD_ShowNum(2,1,Password,4);
			}
			if(KeyNum==11)
			{
				if(Password==2425)
				{
					LCD_ShowString(1,14,"OK ");
					Password=0;
					Count=0;
					LCD_ShowNum(2,1,Password,4);
				}
				else
				{
					LCD_ShowString(1,14,"ERR");
					Password=0;
					Count=0;
					LCD_ShowNum(2,1,Password,4);
				}
			}
			if(KeyNum==12)
			{
				Password=0;
				Count=0;
				LCD_ShowString(1,14,"   ");
				LCD_ShowNum(2,1,Password,4);
			}
			
		}
		
		
	}
}