#pragma once

// 公開関数
extern void vdg_Prc_init(void);
extern void vdg_Prc_GridUpdate(void);
extern void vds_Prc_SetObj(st_GridMap* (psts_PrcSO_GridMapInfo)[1000][4000]);

// 外部公開変数
extern st_GridMap stg_Prc_ArGridInfo[1000][4000]; // グリッドマップ情報