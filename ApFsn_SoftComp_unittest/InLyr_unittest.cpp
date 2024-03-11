#include "pch.h"
#include "ApFsn_InLyrComp.h"
#include "InLyr.cpp"

//vdg_InLyr_init()のユニットテスト
TEST(TestCaseInLyrInit, TestMainInLyrInit1) {
	//
	stg_InLyr_SnrDtctClstr[0].st_crd[0].In_X = (S2)1;
	stg_InLyr_SnrDtctClstr[0].st_crd[0].In_Y = (S2)2;
	stg_InLyr_SnrDtctClstr[0].InCrdNum = (U1)1;
	stg_InLyr_SnrDtctClstr[0].EmClstrState = (U1)2;
	stg_InLyr_SodDtctClstr[0].st_crd[0].In_X = (U1)3;
	stg_InLyr_SodDtctClstr[0].st_crd[0].In_Y = (U1)4;
	stg_InLyr_SodDtctClstr[0].InCrdNum = (U1)3;
	stg_InLyr_SodDtctClstr[0].EmClstrState = (U1)4;
	
	vdg_InLyr_init();
	
	EXPECT_EQ(0, stg_InLyr_SnrDtctClstr[0].st_crd[0].In_X);
	EXPECT_EQ(0, stg_InLyr_SnrDtctClstr[0].st_crd[0].In_Y);
	EXPECT_EQ(0, stg_InLyr_SnrDtctClstr[0].InCrdNum);
	EXPECT_EQ(0, stg_InLyr_SnrDtctClstr[0].EmClstrState);
	EXPECT_EQ(0, stg_InLyr_SodDtctClstr[0].st_crd[0].In_X);
	EXPECT_EQ(0, stg_InLyr_SodDtctClstr[0].st_crd[0].In_Y);
	EXPECT_EQ(0, stg_InLyr_SodDtctClstr[0].InCrdNum);
	EXPECT_EQ(0, stg_InLyr_SodDtctClstr[0].EmClstrState);
}