#include "pch.h"
#include "InLyr.h"
#include "Prc.h"
#include "Prc.cpp"

//vdg_Prc_init()のユニットテスト
TEST(TestCasePrcInit, TestPrcInit1) {

	stg_Prc_ArGridInfo[0][0].CnSnrDtct = 1;
	stg_Prc_ArGridInfo[0][0].CnSodDtct = 2;
	stg_Prc_ArGridInfo[0][0].InOcpy = 3;
	stg_Prc_ArGridInfo[0][0].CnObjSet = 4;

	vdg_Prc_init();
	EXPECT_EQ(0, stg_Prc_ArGridInfo[0][0].CnSnrDtct);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[0][0].CnSodDtct);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[0][0].InOcpy);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[0][0].CnObjSet);
}


//vdg_Prc_GridUpdate()のユニットテスト
// 
// 2つの検知が重なっている、物体の確定フラグあり
TEST(TestCasePrcGU, MultiSnrPvm_ConfObj) {

	stg_InLyr_SnrDtctClstr[0].st_crd[0].In_X = (S2)0;
	stg_InLyr_SnrDtctClstr[0].st_crd[0].In_Y = (S2)0;
	stg_InLyr_SnrDtctClstr[0].InCrdNum = (U1)1;
	stg_InLyr_SnrDtctClstr[0].EmClstrState = (U1)1;
	stg_InLyr_SnrDtctClstr[1].st_crd[0].In_X = (S2)0;
	stg_InLyr_SnrDtctClstr[1].st_crd[0].In_Y = (S2)0;
	stg_InLyr_SnrDtctClstr[1].InCrdNum = (U1)1;
	stg_InLyr_SnrDtctClstr[1].EmClstrState = (U1)1;

	//PVM用
	stg_InLyr_SodDtctClstr[0].st_crd[0].In_X = (U1)0;
	stg_InLyr_SodDtctClstr[0].st_crd[0].In_Y = (U1)0;
	stg_InLyr_SodDtctClstr[0].InCrdNum = (U1)1;
	stg_InLyr_SodDtctClstr[0].EmClstrState = (U1)1;
	stg_InLyr_SodDtctClstr[1].st_crd[0].In_X = (U1)0;
	stg_InLyr_SodDtctClstr[1].st_crd[0].In_Y = (U1)0;
	stg_InLyr_SodDtctClstr[1].InCrdNum = (U1)1;
	stg_InLyr_SodDtctClstr[1].EmClstrState = (U1)1;

	vdg_Prc_GridUpdate();
	EXPECT_EQ(1, stg_Prc_ArGridInfo[500][1000].CnSnrDtct);
	EXPECT_EQ(1, stg_Prc_ArGridInfo[500][1000].CnSodDtct);
	EXPECT_EQ(20, stg_Prc_ArGridInfo[500][1000].InOcpy);
	EXPECT_EQ(1, stg_Prc_ArGridInfo[500][1000].CnObjSet);
}
// 2つの検知が重なっている、物体の確定フラグなし
TEST(TestCasePrcGU, MultiSnrPvm_NoConfObj) {

	stg_InLyr_SnrDtctClstr[0].st_crd[0].In_X = (S2)10;
	stg_InLyr_SnrDtctClstr[0].st_crd[0].In_Y = (S2)10;
	stg_InLyr_SnrDtctClstr[0].InCrdNum = (U1)1;
	stg_InLyr_SnrDtctClstr[0].EmClstrState = (U1)1;
	//PVM用
	stg_InLyr_SodDtctClstr[0].st_crd[0].In_X = (U1)10;
	stg_InLyr_SodDtctClstr[0].st_crd[0].In_Y = (U1)10;
	stg_InLyr_SodDtctClstr[0].InCrdNum = (U1)1;
	stg_InLyr_SodDtctClstr[0].EmClstrState = (U1)1;

	vdg_Prc_GridUpdate();
	EXPECT_EQ(1, stg_Prc_ArGridInfo[510][1010].CnSnrDtct);
	EXPECT_EQ(1, stg_Prc_ArGridInfo[510][1010].CnSodDtct);
	EXPECT_EQ(10, stg_Prc_ArGridInfo[510][1010].InOcpy);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[510][1010].CnObjSet);
}

// ソナーのみの検知がある、物体の確定フラグあり
TEST(TestCasePrcGU, SingleSnr_ConfObj) {

	stg_InLyr_SnrDtctClstr[0].st_crd[0].In_X = (S2)20;
	stg_InLyr_SnrDtctClstr[0].st_crd[0].In_Y = (S2)20;
	stg_InLyr_SnrDtctClstr[0].st_crd[1].In_X = (S2)20;
	stg_InLyr_SnrDtctClstr[0].st_crd[1].In_Y = (S2)20;
	stg_InLyr_SnrDtctClstr[0].InCrdNum = (U1)2;
	stg_InLyr_SnrDtctClstr[0].EmClstrState = (U1)1;
	stg_InLyr_SnrDtctClstr[1].st_crd[0].In_X = (S2)20;
	stg_InLyr_SnrDtctClstr[1].st_crd[0].In_Y = (S2)20;
	stg_InLyr_SnrDtctClstr[1].InCrdNum = (U1)1;
	stg_InLyr_SnrDtctClstr[1].EmClstrState = (U1)1;
	stg_InLyr_SnrDtctClstr[2].st_crd[0].In_X = (S2)20;
	stg_InLyr_SnrDtctClstr[2].st_crd[0].In_Y = (S2)20;
	stg_InLyr_SnrDtctClstr[2].InCrdNum = (U1)1;
	stg_InLyr_SnrDtctClstr[2].EmClstrState = (U1)1;

	vdg_Prc_GridUpdate();
	EXPECT_EQ(1, stg_Prc_ArGridInfo[520][1020].CnSnrDtct);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[520][1020].CnSodDtct);
	EXPECT_EQ(20, stg_Prc_ArGridInfo[520][1020].InOcpy);
	EXPECT_EQ(1, stg_Prc_ArGridInfo[520][1020].CnObjSet);
}
// ソナーのみの検知がある、物体の確定フラグなし
TEST(TestCasePrcGU, SingleSnr_NoConfObj) {

	stg_InLyr_SnrDtctClstr[0].st_crd[0].In_X = (S2)30;
	stg_InLyr_SnrDtctClstr[0].st_crd[0].In_Y = (S2)30;
	stg_InLyr_SnrDtctClstr[0].InCrdNum = (U1)1;
	stg_InLyr_SnrDtctClstr[0].EmClstrState = (U1)1;
	stg_InLyr_SnrDtctClstr[1].st_crd[0].In_X = (S2)30;
	stg_InLyr_SnrDtctClstr[1].st_crd[0].In_Y = (S2)30;
	stg_InLyr_SnrDtctClstr[1].InCrdNum = (U1)1;
	stg_InLyr_SnrDtctClstr[1].EmClstrState = (U1)0;
	stg_InLyr_SnrDtctClstr[2].st_crd[0].In_X = (S2)30;
	stg_InLyr_SnrDtctClstr[2].st_crd[0].In_Y = (S2)30;
	stg_InLyr_SnrDtctClstr[2].InCrdNum = (U1)1;
	stg_InLyr_SnrDtctClstr[2].EmClstrState = (U1)0;

	vdg_Prc_GridUpdate();
	EXPECT_EQ(1, stg_Prc_ArGridInfo[530][1030].CnSnrDtct);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[530][1030].CnSodDtct);
	EXPECT_EQ(5, stg_Prc_ArGridInfo[530][1030].InOcpy);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[530][1030].CnObjSet);
}

// PVMのみの検知がある、物体の確定フラグあり
TEST(TestCasePrcGU, SinglePvm_ConfObj) {

	stg_InLyr_SodDtctClstr[0].st_crd[0].In_X = (S2)40;
	stg_InLyr_SodDtctClstr[0].st_crd[0].In_Y = (S2)40;
	stg_InLyr_SodDtctClstr[0].st_crd[1].In_X = (S2)40;
	stg_InLyr_SodDtctClstr[0].st_crd[1].In_Y = (S2)40;
	stg_InLyr_SodDtctClstr[0].InCrdNum = (U1)2;
	stg_InLyr_SodDtctClstr[0].EmClstrState = (U1)1;
	stg_InLyr_SodDtctClstr[1].st_crd[0].In_X = (S2)40;
	stg_InLyr_SodDtctClstr[1].st_crd[0].In_Y = (S2)40;
	stg_InLyr_SodDtctClstr[1].InCrdNum = (U1)1;
	stg_InLyr_SodDtctClstr[1].EmClstrState = (U1)1;
	stg_InLyr_SodDtctClstr[2].st_crd[0].In_X = (S2)40;
	stg_InLyr_SodDtctClstr[2].st_crd[0].In_Y = (S2)40;
	stg_InLyr_SodDtctClstr[2].InCrdNum = (U1)1;
	stg_InLyr_SodDtctClstr[2].EmClstrState = (U1)1;

	vdg_Prc_GridUpdate();
	EXPECT_EQ(0, stg_Prc_ArGridInfo[540][1040].CnSnrDtct);
	EXPECT_EQ(1, stg_Prc_ArGridInfo[540][1040].CnSodDtct);
	EXPECT_EQ(20, stg_Prc_ArGridInfo[540][1040].InOcpy);
	EXPECT_EQ(1, stg_Prc_ArGridInfo[540][1040].CnObjSet);
}
// PVMのみの検知がある、物体の確定フラグなし
TEST(TestCasePrcGU, SinglePvm_NoConfObj) {

	stg_InLyr_SodDtctClstr[0].st_crd[0].In_X = (S2)50;
	stg_InLyr_SodDtctClstr[0].st_crd[0].In_Y = (S2)50;
	stg_InLyr_SodDtctClstr[0].InCrdNum = (U1)1;
	stg_InLyr_SodDtctClstr[0].EmClstrState = (U1)1;
	stg_InLyr_SodDtctClstr[1].st_crd[0].In_X = (S2)50;
	stg_InLyr_SodDtctClstr[1].st_crd[0].In_Y = (S2)50;
	stg_InLyr_SodDtctClstr[1].InCrdNum = (U1)0;
	stg_InLyr_SodDtctClstr[1].EmClstrState = (U1)1;
	stg_InLyr_SodDtctClstr[2].st_crd[0].In_X = (S2)50;
	stg_InLyr_SodDtctClstr[2].st_crd[0].In_Y = (S2)50;
	stg_InLyr_SodDtctClstr[2].InCrdNum = (U1)1;
	stg_InLyr_SodDtctClstr[2].EmClstrState = (U1)0;

	vdg_Prc_GridUpdate();
	EXPECT_EQ(0, stg_Prc_ArGridInfo[550][1050].CnSnrDtct);
	EXPECT_EQ(1, stg_Prc_ArGridInfo[550][1050].CnSodDtct);
	EXPECT_EQ(5, stg_Prc_ArGridInfo[550][1050].InOcpy);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[550][1050].CnObjSet);
}

// 検知なし、物体の確定フラグなし
TEST(TestCasePrcGU, NoDetection_NoConfObj) {

	stg_InLyr_SnrDtctClstr[0].st_crd[0].In_X = (S2)60;
	stg_InLyr_SnrDtctClstr[0].st_crd[0].In_Y = (S2)60;
	stg_InLyr_SnrDtctClstr[0].InCrdNum = (U1)1;
	stg_InLyr_SnrDtctClstr[0].EmClstrState = (U1)0;
	//PVM用
	stg_InLyr_SodDtctClstr[0].st_crd[0].In_X = (U1)60;
	stg_InLyr_SodDtctClstr[0].st_crd[0].In_Y = (U1)60;
	stg_InLyr_SodDtctClstr[0].InCrdNum = (U1)1;
	stg_InLyr_SodDtctClstr[0].EmClstrState = (U1)0;

	vdg_Prc_GridUpdate();
	EXPECT_EQ(0, stg_Prc_ArGridInfo[560][1060].CnSnrDtct);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[560][1060].CnSodDtct);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[560][1060].InOcpy);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[560][1060].CnObjSet);
}

//車の前側