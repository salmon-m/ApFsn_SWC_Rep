#include "typeDifference.h"
#include "structureDeclaration.h"

//�v���g�^�C�v�錾
void vdg_OutLyr_init(void);
void vdg_OutLyr_GlobalUpdate(void);

st_GridMap_Out stg_OutLyr_ArGridInfo[1000][4000];

//�R���|�̏�����
void vdg_OutLyr_init(void)
{
	U2 U2_OutLyrI_LoopI = (U2)0;
	U2 U2_OutLyrI_LoopJ = (U2)0;

	for (U2_OutLyrI_LoopI = 0; U2_OutLyrI_LoopI < 1000; U2_OutLyrI_LoopI++)
	{
		for (U2_OutLyrI_LoopJ = 0;  U2_OutLyrI_LoopJ < 4000; U2_OutLyrI_LoopJ++)
		{
			stg_OutLyr_ArGridInfo[U2_OutLyrI_LoopI][U2_OutLyrI_LoopJ].CnObjSet = 0;
		}
	}

	return;
}

//�O���o�̓f�[�^�̍X�V
void vdg_OutLyr_GlobalUpdate(void){}