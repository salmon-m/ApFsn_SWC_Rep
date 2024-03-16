#include "pch.h"
#include "InLyr.h"
#include "Prc.h"
#include "Prc.cpp"

//vdg_Prc_init()のユニットテスト
TEST(TestCasePrcInit, TestPrcInit1) {

	stg_Prc_ArGridInfo[0][0].CnSnrDtct = 1;
	stg_Prc_ArGridInfo[0][0].CnSodDtct = 1;
	stg_Prc_ArGridInfo[0][0].InOcpy = 20;
	stg_Prc_ArGridInfo[0][0].CnObjSet = 1;

	vdg_Prc_init();
	EXPECT_EQ(0, stg_Prc_ArGridInfo[0][0].CnSnrDtct);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[0][0].CnSodDtct);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[0][0].InOcpy);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[0][0].CnObjSet);
}


//vdg_Prc_GridUpdate()のユニットテスト
// 
// 車の後方について
// 2つの検知が重なっている、物体の確定フラグあり
TEST(TestCasePrcGU,MultiSnrPvm_ConfObj) {

	st_snr_clstr* pst_workSnr[3];
	for (int i = 0; i < 3; i++)
	{
		pst_workSnr[i] = &(stg_InLyr_SnrDtctClstr[i]);
	}
	st_sod_clstr* pst_workSod[4];
	for (int i = 0; i < 4; i++)
	{
		pst_workSod[i] = &(stg_InLyr_SodDtctClstr[i]);
	}
	//ソナー用
	pst_workSnr[0]->st_crd[0].In_X = -700;
	pst_workSnr[0]->st_crd[0].In_Y = -500;
	pst_workSnr[0]->InCrdNum = 1;
	pst_workSnr[0]->EmClstrState = 1;
	pst_workSnr[1]->st_crd[0].In_X = -700;
	pst_workSnr[1]->st_crd[0].In_Y = -500;
	pst_workSnr[1]->InCrdNum = 1;
	pst_workSnr[1]->EmClstrState = 1;

	//PVM用
	pst_workSod[0]->st_crd[0].In_X = -700;
	pst_workSod[0]->st_crd[0].In_Y = -500;
	pst_workSod[0]->InCrdNum = 1;
	pst_workSod[0]->EmClstrState = 1;
	pst_workSod[1]->st_crd[0].In_X = -700;
	pst_workSod[1]->st_crd[0].In_Y = -500;
	pst_workSod[1]->InCrdNum = 1;
	pst_workSod[1]->EmClstrState = 1;

	vdg_Prc_GridUpdate();
	EXPECT_EQ(1, stg_Prc_ArGridInfo[0][300].CnSnrDtct);
	EXPECT_EQ(1, stg_Prc_ArGridInfo[0][300].CnSodDtct);
	EXPECT_EQ(20, stg_Prc_ArGridInfo[0][300].InOcpy);
	EXPECT_EQ(1, stg_Prc_ArGridInfo[0][300].CnObjSet);
}
// 2つの検知が重なっている、物体の確定フラグなし
TEST(TestCasePrcGU,MultiSnrPvm_NoConfObj) {
	st_snr_clstr* pst_workSnr[3];
	for (int i = 0; i < 3; i++)
	{
		pst_workSnr[i] = &(stg_InLyr_SnrDtctClstr[i]);
	}
	st_sod_clstr* pst_workSod[4];
	for (int i = 0; i < 4; i++)
	{
		pst_workSod[i] = &(stg_InLyr_SodDtctClstr[i]);
	}

	pst_workSnr[0]->st_crd[0].In_X = -200;
	pst_workSnr[0]->st_crd[0].In_Y = -100;
	pst_workSnr[0]->InCrdNum = 1;
	pst_workSnr[0]->EmClstrState = 1;
	//PVM用
	pst_workSod[0]->st_crd[0].In_X = -200;
	pst_workSod[0]->st_crd[0].In_Y = -100;
	pst_workSod[0]->InCrdNum = 1;
	pst_workSod[0]->EmClstrState = 1;

	vdg_Prc_GridUpdate();
	EXPECT_EQ(1, stg_Prc_ArGridInfo[400][800].CnSnrDtct);
	EXPECT_EQ(1, stg_Prc_ArGridInfo[400][800].CnSodDtct);
	EXPECT_EQ(10, stg_Prc_ArGridInfo[400][800].InOcpy);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[400][800].CnObjSet);
}

// ソナーのみの検知がある、物体の確定フラグあり
TEST(TestCasePrcGU,SingleSnr_ConfObj) {
	st_snr_clstr* pst_workSnr[3];
	for (int i = 0; i < 3; i++)
	{
		pst_workSnr[i] = &(stg_InLyr_SnrDtctClstr[i]);
	}

	pst_workSnr[0]->st_crd[0].In_X = -900;
	pst_workSnr[0]->st_crd[0].In_Y = -400;
	pst_workSnr[0]->st_crd[1].In_X = -900;
	pst_workSnr[0]->st_crd[1].In_Y = -400;
	pst_workSnr[0]->InCrdNum = 2;
	pst_workSnr[0]->EmClstrState = 1;
	pst_workSnr[1]->st_crd[0].In_X = -900;
	pst_workSnr[1]->st_crd[0].In_Y = -400;
	pst_workSnr[1]->InCrdNum = 1;
	pst_workSnr[1]->EmClstrState = 1;
	pst_workSnr[2]->st_crd[0].In_X = -900;
	pst_workSnr[2]->st_crd[0].In_Y = -400;
	pst_workSnr[2]->InCrdNum = 1;
	pst_workSnr[2]->EmClstrState = 1;

	vdg_Prc_GridUpdate();
	EXPECT_EQ(1, stg_Prc_ArGridInfo[100][100].CnSnrDtct);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[100][100].CnSodDtct);
	EXPECT_EQ(20, stg_Prc_ArGridInfo[100][100].InOcpy);
	EXPECT_EQ(1, stg_Prc_ArGridInfo[100][100].CnObjSet);
}
// ソナーのみの検知がある、物体の確定フラグなし
TEST(TestCasePrcGU,SingleSnr_NoConfObj) {
	st_snr_clstr* pst_workSnr[3];
	for (int i = 0; i < 3; i++)
	{
		pst_workSnr[i] = &(stg_InLyr_SnrDtctClstr[i]);
	}

	pst_workSnr[0]->st_crd[0].In_X = -1000;
	pst_workSnr[0]->st_crd[0].In_Y = 400;
	pst_workSnr[0]->InCrdNum = 1;
	pst_workSnr[0]->EmClstrState = 1;
	pst_workSnr[1]->st_crd[0].In_X = -1000;
	pst_workSnr[1]->st_crd[0].In_Y = 400;
	pst_workSnr[1]->InCrdNum = 1;
	pst_workSnr[1]->EmClstrState = (U1)0;
	pst_workSnr[2]->st_crd[0].In_X = -1000;
	pst_workSnr[2]->st_crd[0].In_Y = 400;
	pst_workSnr[2]->InCrdNum = 1;
	pst_workSnr[2]->EmClstrState = (U1)0;

	vdg_Prc_GridUpdate();
	EXPECT_EQ(1, stg_Prc_ArGridInfo[900][0].CnSnrDtct);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[900][0].CnSodDtct);
	EXPECT_EQ(5, stg_Prc_ArGridInfo[900][0].InOcpy);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[900][0].CnObjSet);
}

// PVMのみの検知がある、物体の確定フラグあり
TEST(TestCasePrcGU,SinglePvm_ConfObj) {
	st_sod_clstr* pst_workSod[4];
	for (int i = 0; i < 4; i++)
	{
		pst_workSod[i] = &(stg_InLyr_SodDtctClstr[i]);
	}

	pst_workSod[0]->st_crd[0].In_X = -200;
	pst_workSod[0]->st_crd[0].In_Y = 200;
	pst_workSod[0]->st_crd[1].In_X = -200;
	pst_workSod[0]->st_crd[1].In_Y = 200;
	pst_workSod[0]->InCrdNum = 2;
	pst_workSod[0]->EmClstrState = 1;
	pst_workSod[1]->st_crd[0].In_X = -200;
	pst_workSod[1]->st_crd[0].In_Y = 200;
	pst_workSod[1]->InCrdNum = 1;
	pst_workSod[1]->EmClstrState = 1;
	pst_workSod[2]->st_crd[0].In_X = -200;
	pst_workSod[2]->st_crd[0].In_Y = 200;
	pst_workSod[2]->InCrdNum = 1;
	pst_workSod[2]->EmClstrState = 1;

	vdg_Prc_GridUpdate();
	EXPECT_EQ(0, stg_Prc_ArGridInfo[700][800].CnSnrDtct);
	EXPECT_EQ(1, stg_Prc_ArGridInfo[700][800].CnSodDtct);
	EXPECT_EQ(20, stg_Prc_ArGridInfo[700][800].InOcpy);
	EXPECT_EQ(1, stg_Prc_ArGridInfo[700][800].CnObjSet);
}
// PVMのみの検知がある、物体の確定フラグなし
TEST(TestCasePrcGU,SinglePvm_NoConfObj) {
	st_sod_clstr* pst_workSod[4];
	for (int i = 0; i < 4; i++)
	{
		pst_workSod[i] = &(stg_InLyr_SodDtctClstr[i]);
	}

	pst_workSod[0]->st_crd[0].In_X = -900;
	pst_workSod[0]->st_crd[0].In_Y = 400;
	pst_workSod[0]->InCrdNum = 1;
	pst_workSod[0]->EmClstrState = 1;
	pst_workSod[1]->st_crd[0].In_X = -900;
	pst_workSod[1]->st_crd[0].In_Y = 400;
	pst_workSod[1]->InCrdNum = 0;
	pst_workSod[1]->EmClstrState = 1;
	pst_workSod[2]->st_crd[0].In_X = -900;
	pst_workSod[2]->st_crd[0].In_Y = 400;
	pst_workSod[2]->InCrdNum = 1;
	pst_workSod[2]->EmClstrState = (U1)0;

	vdg_Prc_GridUpdate();
	EXPECT_EQ(0, stg_Prc_ArGridInfo[900][100].CnSnrDtct);
	EXPECT_EQ(1, stg_Prc_ArGridInfo[900][100].CnSodDtct);
	EXPECT_EQ(5, stg_Prc_ArGridInfo[900][100].InOcpy);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[900][100].CnObjSet);
}

// 検知なし、物体の確定フラグなし
TEST(TestCasePrcGU,NoDetection_NoConfObj) {
	st_snr_clstr* pst_workSnr[3];
	for (int i = 0; i < 3; i++)
	{
		pst_workSnr[i] = &(stg_InLyr_SnrDtctClstr[i]);
	}
	st_sod_clstr* pst_workSod[4];
	for (int i = 0; i < 4; i++)
	{
		pst_workSod[i] = &(stg_InLyr_SodDtctClstr[i]);
	}

	pst_workSnr[0]->st_crd[0].In_X = -500;
	pst_workSnr[0]->st_crd[0].In_Y = (S2)0;
	pst_workSnr[0]->InCrdNum = 1;
	pst_workSnr[0]->EmClstrState = (U1)0;
	//PVM用
	pst_workSod[0]->st_crd[0].In_X = -500;
	pst_workSod[0]->st_crd[0].In_Y = (S2)0;
	pst_workSod[0]->InCrdNum = 1;
	pst_workSod[0]->EmClstrState = (U1)0;

	vdg_Prc_GridUpdate();
	EXPECT_EQ(0, stg_Prc_ArGridInfo[500][500].CnSnrDtct);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[500][500].CnSodDtct);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[500][500].InOcpy);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[500][500].CnObjSet);
}

//車の前方について
//2つの検知が重なる
TEST(TestCasePrcGU, FrontOfTheCar_MultSnrPvm_NoConfObj) {

	st_snr_clstr* pst_workSnr[3];
	for (int i = 0; i < 3; i++)
	{
		pst_workSnr[i] = &(stg_InLyr_SnrDtctClstr[i]);
	}
	st_sod_clstr* pst_workSod[4];
	for (int i = 0; i < 4; i++)
	{
		pst_workSod[i] = &(stg_InLyr_SodDtctClstr[i]);
	}
	//ソナー用
	pst_workSnr[0]->st_crd[0].In_X = 2000;
	pst_workSnr[0]->st_crd[0].In_Y = (S2)0;
	pst_workSnr[0]->InCrdNum = 2;
	pst_workSnr[0]->EmClstrState = 1;

	//PVM用
	pst_workSod[0]->st_crd[0].In_X = 2000;
	pst_workSod[0]->st_crd[0].In_Y = (S2)0;
	pst_workSod[0]->InCrdNum = 1;
	pst_workSod[0]->EmClstrState = 1;

	vdg_Prc_GridUpdate();
	EXPECT_EQ(1, stg_Prc_ArGridInfo[500][3000].CnSnrDtct);
	EXPECT_EQ(1, stg_Prc_ArGridInfo[500][3000].CnSodDtct);
	EXPECT_EQ(10, stg_Prc_ArGridInfo[500][3000].InOcpy);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[500][3000].CnObjSet);
}

// ソナーのみの検知がある
TEST(TestCasePrcGU, FrontOfTheCar_SingleSnr_NoConfObj) {
	st_snr_clstr* pst_workSnr[3];
	for (int i = 0; i < 3; i++)
	{
		pst_workSnr[i] = &(stg_InLyr_SnrDtctClstr[i]);
	}

	pst_workSnr[0]->st_crd[0].In_X = 2000;
	pst_workSnr[0]->st_crd[0].In_Y = 100;
	pst_workSnr[0]->InCrdNum = 1;
	pst_workSnr[0]->EmClstrState = 1;

	vdg_Prc_GridUpdate();
	EXPECT_EQ(1, stg_Prc_ArGridInfo[600][3000].CnSnrDtct);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[600][3000].CnSodDtct);
	EXPECT_EQ(5, stg_Prc_ArGridInfo[600][3000].InOcpy);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[600][3000].CnObjSet);
}

// PVMのみの検知がある
TEST(TestCasePrcGU, FrontOfTheCar_SingleSod_NoConfObj) {
	st_sod_clstr* pst_workSod[4];
	for (int i = 0; i < 4; i++)
	{
		pst_workSod[i] = &(stg_InLyr_SodDtctClstr[i]);
	}

	pst_workSod[0]->st_crd[0].In_X = 2000;
	pst_workSod[0]->st_crd[0].In_Y = 200;
	pst_workSod[0]->InCrdNum = 1;
	pst_workSod[0]->EmClstrState = 1;

	vdg_Prc_GridUpdate();
	EXPECT_EQ(0, stg_Prc_ArGridInfo[700][3000].CnSnrDtct);
	EXPECT_EQ(1, stg_Prc_ArGridInfo[700][3000].CnSodDtct);
	EXPECT_EQ(5, stg_Prc_ArGridInfo[700][3000].InOcpy);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[700][3000].CnObjSet);
}

// 検知なし
TEST(TestCasePrcGU, FrontOfTheCar_NoDetection_NoConfObj) {
	st_snr_clstr* pst_workSnr[3];
	for (int i = 0; i < 3; i++)
	{
		pst_workSnr[i] = &(stg_InLyr_SnrDtctClstr[i]);
	}
	st_sod_clstr* pst_workSod[4];
	for (int i = 0; i < 4; i++)
	{
		pst_workSod[i] = &(stg_InLyr_SodDtctClstr[i]);
	}

	pst_workSnr[0]->st_crd[0].In_X = 2000;
	pst_workSnr[0]->st_crd[0].In_Y = -100;
	pst_workSnr[0]->InCrdNum = 1;
	pst_workSnr[0]->EmClstrState = (U1)0;
	//PVM用
	pst_workSod[0]->st_crd[0].In_X = 2000;
	pst_workSod[0]->st_crd[0].In_Y = -100;
	pst_workSod[0]->InCrdNum = 1;
	pst_workSod[0]->EmClstrState = (U1)0;

	vdg_Prc_GridUpdate();
	EXPECT_EQ(0, stg_Prc_ArGridInfo[400][3000].CnSnrDtct);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[400][3000].CnSodDtct);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[400][3000].InOcpy);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[400][3000].CnObjSet);
}