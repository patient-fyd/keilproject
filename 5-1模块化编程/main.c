#include <REGX52.H>
#include "Delay.h"
#include "Nixie.h"
void main()
{
	while(1)
	{
		Nixie(6,5);
		Nixie(7,2);
		Nixie(8,0);
	}
}