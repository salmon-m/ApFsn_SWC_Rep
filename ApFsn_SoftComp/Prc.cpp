#include "typeDifference.h"
#include "structureDeclaration.h"
#include "InLyr.h"

// プロトタイプ宣言
void vdg_Prc_init(void);
void vdg_Prc_GridUpdate(void);

st_GridMap stg_Prc_ArGridInfo[1000][4000]; // グリッドマップ情報

// 初期化
void vdg_Prc_init(void)
{
	U2 U2_PrcI_LoopRow = (U2)0;
	U2 U2_PrcI_LoopColumn = (U2)0;

	for (U2_PrcI_LoopRow = 0; U2_PrcI_LoopRow < 1000; U2_PrcI_LoopRow++)
	{
		for (U2_PrcI_LoopColumn = 0; U2_PrcI_LoopColumn < 4000; U2_PrcI_LoopColumn++)
		{
			stg_Prc_ArGridInfo[U2_PrcI_LoopRow][U2_PrcI_LoopColumn].CnSnrDtct = (U1)0;
			stg_Prc_ArGridInfo[U2_PrcI_LoopRow][U2_PrcI_LoopColumn].CnSodDtct = (U1)0;
			stg_Prc_ArGridInfo[U2_PrcI_LoopRow][U2_PrcI_LoopColumn].InOcpy = (U1)0;
			stg_Prc_ArGridInfo[U2_PrcI_LoopRow][U2_PrcI_LoopColumn].CnObjSet = (U1)0;
		}
	}

	return;
}

void vdg_Prc_GridUpdate(void)
{
	S1 S1_PrcGU_SnrClusterCount = (S1)0;
	S1 S1_PrcGU_SnrPointCount = (S1)0;
	S1 S1_PrcGU_SodClusterCount = (S1)0;
	S1 S1_PrcGU_SodPointCount = (S1)0;
	U2 U2_PrcGU_LoopRow = (U2)0;
	U2 U2_PrcGU_LoopColumn = (U2)0;
	S2 S2_PrcGU_X = (S2)0;
	S2 S2_PrcGU_Y = (S2)0;

	// ソナー
	for (S1_PrcGU_SnrClusterCount = 0; (S1_PrcGU_SnrClusterCount < 3) && (stg_InLyr_SnrDtctClstr[S1_PrcGU_SnrClusterCount].InCrdNum != 0); S1_PrcGU_SnrClusterCount++)
	{
		for (S1_PrcGU_SnrPointCount = 0; S1_PrcGU_SnrPointCount < stg_InLyr_SnrDtctClstr[S1_PrcGU_SnrClusterCount].InCrdNum; S1_PrcGU_SnrPointCount++)
		{
			if (stg_InLyr_SnrDtctClstr[S1_PrcGU_SnrClusterCount].EmClstrState == 1)
			{
				S2_PrcGU_X = stg_InLyr_SnrDtctClstr[S1_PrcGU_SnrClusterCount].st_crd[S1_PrcGU_SnrPointCount].In_X + 1000;
				S2_PrcGU_Y = stg_InLyr_SnrDtctClstr[S1_PrcGU_SnrClusterCount].st_crd[S1_PrcGU_SnrPointCount].In_Y + 500;
				stg_Prc_ArGridInfo[S2_PrcGU_Y][S2_PrcGU_X].CnSnrDtct = 1;
				stg_Prc_ArGridInfo[S2_PrcGU_Y][S2_PrcGU_X].InOcpy += 5;
			}
		}
	}

	// PVM
	for (S1_PrcGU_SodClusterCount = 0; (S1_PrcGU_SodClusterCount < 4) && (stg_InLyr_SodDtctClstr[S1_PrcGU_SodClusterCount].InCrdNum != 0); S1_PrcGU_SodClusterCount++)
	{
		for (S1_PrcGU_SodPointCount = 0; S1_PrcGU_SodPointCount < stg_InLyr_SodDtctClstr[S1_PrcGU_SodClusterCount].InCrdNum; S1_PrcGU_SodPointCount++)
		{
			if (stg_InLyr_SodDtctClstr[S1_PrcGU_SodClusterCount].EmClstrState == 1)
			{
				S2_PrcGU_X = stg_InLyr_SodDtctClstr[S1_PrcGU_SodClusterCount].st_crd[S1_PrcGU_SodPointCount].In_X + 1000;
				S2_PrcGU_Y = stg_InLyr_SodDtctClstr[S1_PrcGU_SodClusterCount].st_crd[S1_PrcGU_SodPointCount].In_Y + 500;
				stg_Prc_ArGridInfo[S2_PrcGU_Y][S2_PrcGU_X].CnSodDtct = 1;
				stg_Prc_ArGridInfo[S2_PrcGU_Y][S2_PrcGU_X].InOcpy += 5;
			}
		}
	}

	// 物体確定
	for (U2_PrcGU_LoopRow = 0; U2_PrcGU_LoopRow < 1000; U2_PrcGU_LoopRow++)
	{
		for (U2_PrcGU_LoopColumn = 0; U2_PrcGU_LoopColumn < 4000; U2_PrcGU_LoopColumn++)
		{
			if (stg_Prc_ArGridInfo[U2_PrcGU_LoopRow][U2_PrcGU_LoopColumn].InOcpy >= 16)
			{
				stg_Prc_ArGridInfo[U2_PrcGU_LoopRow][U2_PrcGU_LoopColumn].CnObjSet = 1;
			}
		}
	}

	return;
}