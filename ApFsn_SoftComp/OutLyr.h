#pragma once
#include "structureDeclaration.h"

// 公開関数
extern void vdg_OutLyr_init(void);
extern void vdg_OutLyr_GlobalUpdate(void);

// 外部公開変数
extern st_GridMap_Out stg_OutLyr_ArGridInfo[1000][4000]; // グリッドマップ情報