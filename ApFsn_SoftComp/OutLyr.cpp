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
	U2 U2_OutLyrI_LoopRow = (U2)0;
	U2 U2_OutLyrI_LoopColumn = (U2)0;

	for (U2_OutLyrI_LoopRow = 0; U2_OutLyrI_LoopRow < 1000; U2_OutLyrI_LoopRow++)
	{
		for (U2_OutLyrI_LoopColumn = 0; U2_OutLyrI_LoopColumn < 4000; U2_OutLyrI_LoopColumn++)
		{
			stg_OutLyr_ArGridInfo[U2_OutLyrI_LoopRow][U2_OutLyrI_LoopColumn].CnObjSet = 0;
		}
	}

	return;
}

// 外部出力データの更新
void vdg_OutLyr_GlobalUpdate(void)
{
	U2 U2_OutLyrGU_LoopRow = (U2)0;
	U2 U2_OutLyrGU_LoopColumn = (U2)0;

	for (U2_OutLyrGU_LoopRow = 0; U2_OutLyrGU_LoopRow < 1000; U2_OutLyrGU_LoopRow++)
	{
		for (U2_OutLyrGU_LoopColumn = 0; U2_OutLyrGU_LoopColumn < 4000; U2_OutLyrGU_LoopColumn++)
		{
			stg_OutLyr_ArGridInfo[U2_OutLyrGU_LoopRow][U2_OutLyrGU_LoopColumn].CnObjSet = stg_Prc_ArGridInfo[U2_OutLyrGU_LoopRow][U2_OutLyrGU_LoopColumn].CnObjSet;
		}
	}

	return;
}