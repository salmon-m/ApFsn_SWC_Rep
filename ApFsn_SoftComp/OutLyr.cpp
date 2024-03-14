#include "typeDifference.h"

//プロトタイプ宣言
void vdg_OutLyr_init(void);
void vdg_OutLyr_GlobalUpdate(void);

//構造体の宣言
struct st_GridMap_Out {
	U1 CnObjSet;
	U1 Dummy[3];
};

st_GridMap_Out stg_OutLyr_ArGridInfo[1000][4000];

void vdg_OutLyr_init(void){}
void vdg_OutLyr_GlobalUpdate(void){}