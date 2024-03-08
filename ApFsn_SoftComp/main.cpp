#include "typeDifference.h"

#define ON ((U1)1)
#define OFF ((U1)0)

static U1 u1s_main_CnInitial = ON;
static U1 u1s_main_InCnt;
static U1 u1s_main_Cn4Cycle;

/* ��������UnitTest�p */
static U1 u1s_main_InLyrResult = (U1)0;
static U1 u1s_main_PrcResult = (U1)0;
static U1 u1s_main_OutLyrResult = (U1)0;

//InLyr����
void vdg_InLyr_init() {
	u1s_main_InLyrResult = 1;
}
void vdg_InLyr_GlobalCapture() {
	u1s_main_InLyrResult = 2;
}

//Prc����
void vdg_Prc_init() {
	u1s_main_PrcResult = 1;
}
void vdg_Prc_GridUpdate() {
	u1s_main_PrcResult = 2;
}

//OutLyr����
void vdg_OutLyr_init() {
	u1s_main_OutLyrResult = 1;
}
void vdg_OutLyr_GlobalUpdate() {
	u1s_main_OutLyrResult = 2;
}

/* �����܂�UnitTest�p */


void vdg_main_init() {
	u1s_main_InCnt = (U1)0;
	u1s_main_Cn4Cycle = OFF;

	vdg_InLyr_init();
	vdg_Prc_init();
	vdg_OutLyr_init();

	return;
}

void vdg_main_4cycle() {
	vdg_InLyr_GlobalCapture();
	vdg_Prc_GridUpdate();
	vdg_OutLyr_GlobalUpdate();
	return;
}

void main_schedule(void)
{
	//����t���O
	if (u1s_main_CnInitial == ON)
		{
			vdg_main_init();
			u1s_main_CnInitial = OFF;
		}
	else
	{
		//�J�E���g
		u1s_main_InCnt++;
		u1s_main_InCnt %= 4;
		//�J�E���g���m�F
		if ((u1s_main_InCnt % 4) == 0)
		{
			u1s_main_Cn4Cycle = ON;
		}
		else
		{
			u1s_main_Cn4Cycle = OFF;
		}
		//������t���O
		if (u1s_main_Cn4Cycle == ON)
		{
			vdg_main_4cycle();
		}
		//else�͏�������
		else {
		}

	}
	return;
}