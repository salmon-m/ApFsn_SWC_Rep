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
TEST(TestCasePrcGU, TestPrcGU1) {

	stg_InLyr_SnrDtctClstr[0].st_crd[0].In_X = (S2)0;
	stg_InLyr_SnrDtctClstr[0].st_crd[0].In_Y = (S2)0;
	stg_InLyr_SnrDtctClstr[0].InCrdNum = (U1)1;
	stg_InLyr_SnrDtctClstr[0].EmClstrState = (U1)1;
	//PVW用
	stg_InLyr_SodDtctClstr[0].st_crd[0].In_X = (U1)0;
	stg_InLyr_SodDtctClstr[0].st_crd[0].In_Y = (U1)0;
	stg_InLyr_SodDtctClstr[0].InCrdNum = (U1)1;
	stg_InLyr_SodDtctClstr[0].EmClstrState = (U1)1;

	vdg_Prc_GridUpdate();
	EXPECT_EQ(1, stg_Prc_ArGridInfo[500][1000].CnSnrDtct);
	EXPECT_EQ(1, stg_Prc_ArGridInfo[500][1000].CnSodDtct);
	EXPECT_EQ(10, stg_Prc_ArGridInfo[500][1000].InOcpy);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[500][1000].CnObjSet);
}