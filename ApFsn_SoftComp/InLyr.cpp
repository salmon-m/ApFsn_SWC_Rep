#include "typeDifference.h"
#include "ExternalData.h" //外部入力DummyIF用
#include "main.h"		  //外部入力DummyIF用
#include "structureDeclaration.h"

// プロトタイプ宣言
void vdg_InLyr_init(void);
void vdg_InLyr_GlobalCapture(void);

st_snr_clstr stg_InLyr_SnrDtctClstr[3]; // ソナーセンサ検知クラスタ
st_sod_clstr stg_InLyr_SodDtctClstr[4]; // PVM検知クラスタ

// 初期化
void vdg_InLyr_init(void)
{
	S1 S1_InLyrI_SnrClusterCount = (S1)0;
	S1 S1_InLyrI_SnrPointCount = (S1)0;
	S1 S1_InLyrI_SodClusterCount = (S1)0;
	S1 S1_InLyrI_SodPointCount = (S1)0;

	// ソナーセンサ検知クラスタ用変数の初期化
	for (S1_InLyrI_SnrClusterCount = 0; S1_InLyrI_SnrClusterCount < 3; S1_InLyrI_SnrClusterCount++)
	{
		for (S1_InLyrI_SnrPointCount = 0; S1_InLyrI_SnrPointCount < 5; S1_InLyrI_SnrPointCount++)
		{
			stg_InLyr_SnrDtctClstr[S1_InLyrI_SnrClusterCount].st_crd[S1_InLyrI_SnrPointCount].In_X = (S2)0;
			stg_InLyr_SnrDtctClstr[S1_InLyrI_SnrClusterCount].st_crd[S1_InLyrI_SnrPointCount].In_Y = (S2)0;
		}
		stg_InLyr_SnrDtctClstr[S1_InLyrI_SnrClusterCount].InCrdNum = (U1)0;
		stg_InLyr_SnrDtctClstr[S1_InLyrI_SnrClusterCount].EmClstrState = (U1)0;
	}

	// PVM検知クラスタ用変数の初期化
	for (S1_InLyrI_SodClusterCount = 0; S1_InLyrI_SodClusterCount < 4; S1_InLyrI_SodClusterCount++)
	{
		for (S1_InLyrI_SodPointCount = 0; S1_InLyrI_SodPointCount < 6; S1_InLyrI_SodPointCount++)
		{
			stg_InLyr_SodDtctClstr[S1_InLyrI_SodClusterCount].st_crd[S1_InLyrI_SodPointCount].In_X = (S2)0;
			stg_InLyr_SodDtctClstr[S1_InLyrI_SodClusterCount].st_crd[S1_InLyrI_SodPointCount].In_Y = (S2)0;
		}
		stg_InLyr_SodDtctClstr[S1_InLyrI_SodClusterCount].InCrdNum = (U1)0;
		stg_InLyr_SodDtctClstr[S1_InLyrI_SodClusterCount].EmClstrState = (U1)0;
	}

	return;
}

// 外部データの取り込み
void vdg_InLyr_GlobalCapture(void)
{
	S1 S1_InLyrGC_SnrClusterCount = (S1)0;
	S1 S1_InLyrGC_SnrPointCount = (S1)0;
	S1 S1_InLyrGC_SodClusterCount = (S1)0;
	S1 S1_InLyrGC_SodPointCount = (S1)0;

	// ソナーセンサ検知クラスタ取り込み
	for (S1_InLyrGC_SnrClusterCount = 0; S1_InLyrGC_SnrClusterCount < 3; S1_InLyrGC_SnrClusterCount++)
	{
		for (S1_InLyrGC_SnrPointCount = 0; S1_InLyrGC_SnrPointCount < 5; S1_InLyrGC_SnrPointCount++)
		{
			stg_InLyr_SnrDtctClstr[S1_InLyrGC_SnrClusterCount].st_crd[S1_InLyrGC_SnrPointCount].In_X = stg_csr_dtct_clstr[S1_InLyrGC_SnrClusterCount].st_dtct_crd[S1_InLyrGC_SnrPointCount].In_X;
			stg_InLyr_SnrDtctClstr[S1_InLyrGC_SnrClusterCount].st_crd[S1_InLyrGC_SnrPointCount].In_Y = stg_csr_dtct_clstr[S1_InLyrGC_SnrClusterCount].st_dtct_crd[S1_InLyrGC_SnrPointCount].In_Y;
		}
		stg_InLyr_SnrDtctClstr[S1_InLyrGC_SnrClusterCount].InCrdNum = stg_csr_dtct_clstr[S1_InLyrGC_SnrClusterCount].InCrdNum;
		stg_InLyr_SnrDtctClstr[S1_InLyrGC_SnrClusterCount].EmClstrState = stg_csr_dtct_clstr[S1_InLyrGC_SnrClusterCount].EmClstrState;
	}

	// PVM検知クラスタ取り込み
	for (S1_InLyrGC_SodClusterCount = 0; S1_InLyrGC_SodClusterCount < 4; S1_InLyrGC_SodClusterCount++)
	{
		for (S1_InLyrGC_SodPointCount = 0; S1_InLyrGC_SodPointCount < 6; S1_InLyrGC_SodPointCount++)
		{
			stg_InLyr_SodDtctClstr[S1_InLyrGC_SodClusterCount].st_crd[S1_InLyrGC_SodPointCount].In_X = stg_pvm_dtct_clstr[S1_InLyrGC_SodClusterCount].st_dtct_crd[S1_InLyrGC_SodPointCount].In_X;
			stg_InLyr_SodDtctClstr[S1_InLyrGC_SodClusterCount].st_crd[S1_InLyrGC_SodPointCount].In_Y = stg_pvm_dtct_clstr[S1_InLyrGC_SodClusterCount].st_dtct_crd[S1_InLyrGC_SodPointCount].In_Y;
		}
		stg_InLyr_SodDtctClstr[S1_InLyrGC_SodClusterCount].InCrdNum = stg_pvm_dtct_clstr[S1_InLyrGC_SodClusterCount].InCrdNum;
		stg_InLyr_SodDtctClstr[S1_InLyrGC_SodClusterCount].EmClstrState = stg_pvm_dtct_clstr[S1_InLyrGC_SodClusterCount].EmClstrState;
	}

	return;
}