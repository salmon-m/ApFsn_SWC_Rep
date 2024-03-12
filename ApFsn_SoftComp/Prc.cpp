#include "typeDifference.h"
#include "structureDeclaration.h"

//プロトタイプ宣言
void vdg_Prc_init(void);
void vdg_Prc_GridUpdate(void);

//構造体の宣言
typedef struct
{
	U1 CnSnrDtct;   //ソナー検知の有無
	U1 CnSodDtct;   //PVM検知の有無
	U1 InOcpy;      //投票数
	U1 CnObjSet;    //物体確定フラグ
}st_GridMap;

st_GridMap stg_Prc_ArGridInfo[1000][4000];   //グリッドマップ情報

//初期化
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
	U2 U2_PrcGU_LoopI = (U2)0;
	U2 U2_PrcGU_LoopJ = (U2)0;
	S2 S2_PrcGU_X = (S2)0;
	S2 S2_PrcGU_Y = (S2)0;

	//ソナー
	for (U2_PrcGU_LoopI = 0; U2_PrcGU_LoopI < stg_InLyr_SnrDtctClstr[U2_PrcGU_LoopI].InCrdNum; U2_PrcGU_LoopI++)
	{
		for (U2_PrcGU_LoopJ = 0; U2_PrcGU_LoopJ < stg_InLyr_SnrDtctClstr[U2_PrcGU_LoopI].InCrdNum; U2_PrcGU_LoopJ++) 
		{
			S2_PrcGU_X = stg_InLyr_SnrDtctClstr[U2_PrcGU_LoopI].st_crd[U2_PrcGU_LoopJ].In_X + 1000;
			S2_PrcGU_Y = stg_InLyr_SnrDtctClstr[U2_PrcGU_LoopI].st_crd[U2_PrcGU_LoopJ].In_Y + 500;
			stg_Prc_ArGridInfo[S2_PrcGU_Y][S2_PrcGU_X].CnSnrDtct = 1;
			stg_Prc_ArGridInfo[S2_PrcGU_Y][S2_PrcGU_X].InOcpy += 5;
		}
	}

	//PVM
	for (U2_PrcGU_LoopI = 0; U2_PrcGU_LoopI < stg_InLyr_SodDtctClstr[U2_PrcGU_LoopI].InCrdNum; U2_PrcGU_LoopI++)
	{
		for (U2_PrcGU_LoopJ = 0; U2_PrcGU_LoopJ < stg_InLyr_SodDtctClstr[U2_PrcGU_LoopI].InCrdNum; U2_PrcGU_LoopJ++)
		{
			S2_PrcGU_X = stg_InLyr_SodDtctClstr[U2_PrcGU_LoopI].st_crd[U2_PrcGU_LoopJ].In_X + 1000;
			S2_PrcGU_Y = stg_InLyr_SodDtctClstr[U2_PrcGU_LoopI].st_crd[U2_PrcGU_LoopJ].In_Y + 500;
			stg_Prc_ArGridInfo[S2_PrcGU_Y][S2_PrcGU_X].CnSodDtct = 1;
			stg_Prc_ArGridInfo[S2_PrcGU_Y][S2_PrcGU_X].InOcpy += 5;
		}
	}

	//物体確定
	for (U2_PrcGU_LoopI = 0; U2_PrcGU_LoopI < 1000; U2_PrcGU_LoopI++)
	{
		for (U2_PrcGU_LoopJ = 0; U2_PrcGU_LoopJ < 4000; U2_PrcGU_LoopJ++)
		{
			if (stg_Prc_ArGridInfo[U2_PrcGU_LoopI][U2_PrcGU_LoopJ].InOcpy >= 16) {
				stg_Prc_ArGridInfo[U2_PrcGU_LoopI][U2_PrcGU_LoopJ].CnObjSet = 1;
			}
		}
	}
	
	return;
}