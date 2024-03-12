#pragma once
#include "typeDifference.h"

//ApFsn_SoftComp内の構造体定義
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

typedef struct
{
	U1 CnSnrDtct;   //ソナー検知の有無
	U1 CnSodDtct;   //PVM検知の有無
	U1 InOcpy;      //投票数
	U1 CnObjSet;    //物体確定フラグ
}st_GridMap;


//ApFsn_SoftCompの外部IFの構造体定義（ダミー定義だが、本ファイルに設定）
typedef struct
{
	st_crd st_dtct_crd[5];   //最大座標数
	U1 InCrdNum;             //検知座標数
	U1 EmClstrState;         //クラスタ状態
	U1 Dummy[2];             //ダミー定義（アライメント用）
}st_csr_clstr;

typedef struct
{
	st_crd st_dtct_crd[6];  //最大座標数
	U1 InCrdNum;            //検知座標数
	U1 EmClstrState;        //クラスタ状態
	U1 Dummy[2];            //ダミー定義（アライメント用）
}st_pvm_clstr;