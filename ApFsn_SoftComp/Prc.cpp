#include "typeDifference.h"

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

	return;
}

void vdg_Prc_GridUpdate(void)
{
	return;
}