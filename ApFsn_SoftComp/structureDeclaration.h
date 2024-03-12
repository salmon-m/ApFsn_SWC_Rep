#pragma once
#include "typeDifference.h"

//構造体宣言
typedef struct
{
	S2 In_X;   //X座標
	S2 In_Y;   //Y座標
}st_crd;

typedef struct
{
	st_crd st_crd[5];   //最大座標数 5
	U1 InCrdNum;            //検知座標数
	U1 EmClstrState;        //クラスタ状態
}st_snr_clstr;

typedef struct
{
	st_crd st_crd[6];   //最大座標数 6
	U1 InCrdNum;            //検知座標数
	U1 EmClstrState;        //クラスタ状態
}st_sod_clstr;


extern st_snr_clstr stg_InLyr_SnrDtctClstr[3];   //ソナーセンサ検知クラスタ
extern st_sod_clstr stg_InLyr_SodDtctClstr[4];   //PVM検知クラスタ

