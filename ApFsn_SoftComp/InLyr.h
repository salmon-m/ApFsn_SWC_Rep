#pragma once
#include "structureDeclaration.h"

// 公開関数
extern void vdg_InLyr_init(void);
extern void vdg_InLyr_GlobalCapture(void);

// 外部公開変数
extern st_snr_clstr stg_InLyr_SnrDtctClstr[3]; // ソナーセンサ検知クラスタ
extern st_sod_clstr stg_InLyr_SodDtctClstr[4]; // PVM検知クラスタ