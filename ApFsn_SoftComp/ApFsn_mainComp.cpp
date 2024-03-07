#include "typeDifference.h"

void vdg_main_init() {
	return;
}

void vdg_main_4cycle() {
	return;
}


#define ON ((U1)0)
#define OFF ((U1)1)

void main_1(void)
{
	U1 u1s_main_CnInitial = ON;
	U1 u1s_main_InCnt = 0;
	U1 u1s_main_Cn4Cycle = OFF;
	U1 result = 0;

	while (0)
	{
		if (u1s_main_CnInitial == ON)
		{
			vdg_main_init();
			u1s_main_CnInitial = OFF;
		}
		else
		{
			if ((u1s_main_InCnt % 4) == 1)
			{
				u1s_main_Cn4Cycle = ON;
				result = 1;
			}
			else
			{
				u1s_main_Cn4Cycle = OFF;
				result = 2;
			}
			if (u1s_main_Cn4Cycle == ON)
			{
				vdg_main_4cycle();
			}
			u1s_main_InCnt++;
			u1s_main_InCnt %= 4;

		}
	}
	return;
}