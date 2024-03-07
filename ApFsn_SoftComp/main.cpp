#include "typeDifference.h"

#define ON ((U1)0)
#define OFF ((U1)1)

static U1 u1s_main_CnInitial = ON;
static U1 u1s_main_InCnt = 0;
static U1 u1s_main_Cn4Cycle = OFF;

void vdg_main_init() {
	return;
}

void vdg_main_4cycle() {
	return;
}

void main_schedule(void)
{
	//初回フラグ
	if (u1s_main_CnInitial == ON)
		{
			vdg_main_init();
			u1s_main_CnInitial = OFF;
		}
	else
	{
		//カウント
		u1s_main_InCnt++;
		u1s_main_InCnt %= 4;
		//カウント数確認
		if ((u1s_main_InCnt % 4) == 0)
		{
			u1s_main_Cn4Cycle = ON;
		}
		else
		{
			u1s_main_Cn4Cycle = OFF;
		}
		//定周期フラグ
		if (u1s_main_Cn4Cycle == ON)
		{
			vdg_main_4cycle();
		}
		//elseは処理無し
		else {
		}

	}
	return;
}