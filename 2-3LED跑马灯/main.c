#include <REGX52.H>
#include <INTRINS.H>

void Delay1ms(unsigned int x)		//@12.000MHz
{
	unsigned char i, j;
  while(x)
	{		
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		
		x--;
	}
}


void main()
{
	while(1)
	{
		P2=0xFE;//11111110
		Delay1ms(500);
		P2=0xFD;//11111101
		Delay1ms(500);
		P2=0xFB;//1111 1011
		Delay1ms(500);
		P2=0xF7;//1111 0111
		Delay1ms(500);
		P2=0xEF;//1110 1111
		Delay1ms(500);
		P2=0xDF;//11011111
		Delay1ms(500);
		P2=0xBF;//10111111
		Delay1ms(500);
		P2=0x7F;//0111 1111
		Delay1ms(500);
	}
}
	