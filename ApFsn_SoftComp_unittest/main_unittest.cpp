#include "pch.h"
#include "main.h"
#include "InLyr.h"
#include "Prc.h"
#include "main.cpp"
#include "InLyr.cpp"
#include "Prc.cpp"

//main_schedule()のユニットテスト
TEST(TestCaseMainSchedule, TestMainSchedule1) {
	main_schedule();
	EXPECT_EQ(0, u1s_main_CnInitial);
}

TEST(TestCaseMainSchedule, TestMainSchedule2) {
	u1s_main_CnInitial = OFF;
	u1s_main_InCnt = 0;
	main_schedule();
	EXPECT_EQ(1, u1s_main_InCnt);
}

TEST(TestCaseMainSchedule, TestMainSchedule3) {
	u1s_main_CnInitial = OFF;
	u1s_main_InCnt = 3;
	main_schedule();
	EXPECT_EQ(1, u1s_main_Cn4Cycle);
}

//main_init()のユニットテスト
TEST(TestCaseMainInit, TestMainInit) {
	stg_InLyr_SnrDtctClstr[0].st_crd[0].In_X = 1;
	stg_InLyr_SodDtctClstr[0].st_crd[0].In_Y = 1;
	stg_Prc_ArGridInfo[0][0].CnSnrDtct = 1;
	stg_Prc_ArGridInfo[0][0].CnSodDtct = 2;

	vdg_main_init();

	EXPECT_EQ(0, stg_InLyr_SnrDtctClstr[0].st_crd[0].In_X);
	EXPECT_EQ(0, stg_InLyr_SodDtctClstr[0].st_crd[0].In_Y);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[0][0].CnSnrDtct);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[0][0].CnSodDtct);
}

//vdg_main_4cycle()のユニットテスト
TEST(TestCaseMain4cycle, TestMain4cycle1) {
	stg_csr_dtct_clstr[0].st_dtct_crd[0].In_X = -100;
	stg_csr_dtct_clstr[0].st_dtct_crd[0].In_Y = 200;
	stg_csr_dtct_clstr[0].InCrdNum = 1;

	vdg_main_4cycle();

	EXPECT_EQ(-100, stg_InLyr_SnrDtctClstr[0].st_crd[0].In_X);
	EXPECT_EQ(200, stg_InLyr_SnrDtctClstr[0].st_crd[0].In_Y);
	EXPECT_EQ(1, stg_InLyr_SnrDtctClstr[0].InCrdNum);
	EXPECT_EQ(1, stg_Prc_ArGridInfo[700][900].CnSnrDtct);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[700][900].CnSodDtct);
	EXPECT_EQ(5, stg_Prc_ArGridInfo[700][900].InOcpy);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[700][900].CnObjSet);
}