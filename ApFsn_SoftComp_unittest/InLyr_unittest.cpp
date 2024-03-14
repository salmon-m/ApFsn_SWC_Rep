#include "pch.h"
#include "main.h"
#include "InLyr.h"
#include "InLyr.cpp"

//vdg_InLyr_init()�̃��j�b�g�e�X�g
TEST(TestCaseInLyrInit, TestMainInLyrInit1) {
	//�\�i�[�Z���T�p
	stg_InLyr_SnrDtctClstr[0].st_crd[0].In_X = (S2)1;
	stg_InLyr_SnrDtctClstr[0].st_crd[0].In_Y = (S2)2;
	stg_InLyr_SnrDtctClstr[0].InCrdNum = (U1)1;
	stg_InLyr_SnrDtctClstr[0].EmClstrState = (U1)2;
	//PVW�p
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

//vdg_InLyr_GlobalCapture()�̃��j�b�g�e�X�g
TEST(TestCaseInLyrGC, TestMainInLyrGC1) {
	//�\�i�[�Z���T
	stg_csr_dtct_clstr[0].st_dtct_crd[2].In_X = -100;
	stg_csr_dtct_clstr[0].st_dtct_crd[2].In_Y = 200;
	stg_csr_dtct_clstr[0].InCrdNum = 3;
	//PVW
	stg_pvm_dtct_clstr[0].st_dtct_crd[3].In_X = -200;
	stg_pvm_dtct_clstr[0].st_dtct_crd[3].In_Y = -300;
	stg_pvm_dtct_clstr[0].InCrdNum = 4;

	vdg_InLyr_GlobalCapture();

	EXPECT_EQ(-100, stg_InLyr_SnrDtctClstr[0].st_crd[2].In_X);
	EXPECT_EQ(200, stg_InLyr_SnrDtctClstr[0].st_crd[2].In_Y);
	EXPECT_EQ(3, stg_InLyr_SnrDtctClstr[0].InCrdNum);
	EXPECT_EQ(-200, stg_InLyr_SodDtctClstr[0].st_crd[3].In_X);
	EXPECT_EQ(-300, stg_InLyr_SodDtctClstr[0].st_crd[3].In_Y);
	EXPECT_EQ(4, stg_InLyr_SodDtctClstr[0].InCrdNum);
}