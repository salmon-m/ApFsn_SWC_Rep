#include "typeDifference.h"

//�v���g�^�C�v�錾
void vdg_Prc_init(void);
void vdg_Prc_GridUpdate(void);

//�\���̂̐錾
typedef struct
{
	U1 CnSnrDtct;   //�\�i�[���m�̗L��
	U1 CnSodDtct;   //PVM���m�̗L��
	U1 InOcpy;      //���[��
	U1 CnObjSet;    //���̊m��t���O
}st_GridMap;

st_GridMap stg_Prc_ArGridInfo[1000][4000];   //�O���b�h�}�b�v���

//������
void vdg_Prc_init(void) 
{
	U2 U2_PrcI_LoopI = (U2)0;
	U2 U2_PrcI_LoopJ = (U2)0;

	for (U2_PrcI_LoopI = 0; U2_PrcI_LoopI < 1000; U2_PrcI_LoopI++) 
	{
		for (U2_PrcI_LoopJ = 0; U2_PrcI_LoopJ < 4000; U2_PrcI_LoopJ++) 
		{
			stg_Prc_ArGridInfo[U2_PrcI_LoopI][U2_PrcI_LoopJ].CnSnrDtct = (U1)0;
			stg_Prc_ArGridInfo[U2_PrcI_LoopI][U2_PrcI_LoopJ].CnSodDtct = (U1)0;
			stg_Prc_ArGridInfo[U2_PrcI_LoopI][U2_PrcI_LoopJ].InOcpy = (U1)0;
			stg_Prc_ArGridInfo[U2_PrcI_LoopI][U2_PrcI_LoopJ].CnObjSet = (U1)0;
		}
	}

	return;
}

void vdg_Prc_GridUpdate(void)
{
	return;
}