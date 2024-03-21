#include "typeDifference.h"
#include "structureDeclaration.h"
#include "Prc.h"

// プロトタイプ宣言
void vdg_OutLyr_init(void);
void vdg_OutLyr_GlobalUpdate(void);

st_GridMap_Out stg_OutLyr_ArGridInfo[1000][4000];

// コンポの初期化
void vdg_OutLyr_init(void)
{
	U2 u2t_OutLyrI_LoopRow;
	U2 u2t_OutLyrI_LoopColumn;

	for (u2t_OutLyrI_LoopRow = (U2)0; u2t_OutLyrI_LoopRow < (U2)1000; u2t_OutLyrI_LoopRow++)
	{
		for (u2t_OutLyrI_LoopColumn = (U2)0; u2t_OutLyrI_LoopColumn < (U2)4000; u2t_OutLyrI_LoopColumn++)
		{
			stg_OutLyr_ArGridInfo[u2t_OutLyrI_LoopRow][u2t_OutLyrI_LoopColumn].CnObjSet = (U1)0;
		}
	}

	return;
}

// 外部出力データの更新
void vdg_OutLyr_GlobalUpdate(void)
{
	U2 u2t_OutLyrGU_LoopRow;
	U2 u2t_OutLyrGU_LoopColumn;

	for (u2t_OutLyrGU_LoopRow = (U2)0; u2t_OutLyrGU_LoopRow < (U2)1000; u2t_OutLyrGU_LoopRow++)
	{
		for (u2t_OutLyrGU_LoopColumn = (U2)0; u2t_OutLyrGU_LoopColumn < (U2)4000; u2t_OutLyrGU_LoopColumn++)
		{
			stg_OutLyr_ArGridInfo[u2t_OutLyrGU_LoopRow][u2t_OutLyrGU_LoopColumn].CnObjSet = stg_Prc_ArGridInfo[u2t_OutLyrGU_LoopRow][u2t_OutLyrGU_LoopColumn].CnObjSet;
		}
	}

	return;
}