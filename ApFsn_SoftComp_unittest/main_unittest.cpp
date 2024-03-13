#include "pch.h"
#include "main.h"
#include "InLyr.h"
#include "Prc.h"
#include "main.cpp"

//main_schedule()のユニットテスト
TEST(TestCaseMainSchedule, Test_init) {
	u1g_ApFsn_IG = ON;
	main_schedule();
	EXPECT_EQ(0, u1s_main_InCnt);
	EXPECT_EQ(OFF, u1s_main_Cn4Cycle);
}

TEST(TestCaseMainSchedule, Test_1cycle) {
	u1g_ApFsn_IG = OFF;
	u1s_main_InCnt = 0;
	u1s_main_Cn4Cycle = ON; //期待値とは異なる値を入れる
	main_schedule();
	EXPECT_EQ(1, u1s_main_InCnt);
	EXPECT_EQ(OFF, u1s_main_Cn4Cycle);
}

TEST(TestCaseMainSchedule, Test_4cycle) {
	u1g_ApFsn_IG = OFF;
	u1s_main_InCnt = 3;
	u1s_main_Cn4Cycle = OFF; //期待値とは異なる値を入れる
	main_schedule();
	EXPECT_EQ(0, u1s_main_InCnt);
	EXPECT_EQ(ON, u1s_main_Cn4Cycle);
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
	stg_csr_dtct_clstr[0].EmClstrState = 1;

	vdg_main_4cycle();

	EXPECT_EQ(-100, stg_InLyr_SnrDtctClstr[0].st_crd[0].In_X);
	EXPECT_EQ(200, stg_InLyr_SnrDtctClstr[0].st_crd[0].In_Y);
	EXPECT_EQ(1, stg_InLyr_SnrDtctClstr[0].InCrdNum);
	EXPECT_EQ(1, stg_Prc_ArGridInfo[700][900].CnSnrDtct);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[700][900].CnSodDtct);
	EXPECT_EQ(5, stg_Prc_ArGridInfo[700][900].InOcpy);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[700][900].CnObjSet);
}