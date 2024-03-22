#include "pch.h"
#include "main.h"
#include "InLyr.h"
#include "InLyr.cpp"

//vdg_InLyr_init()�̃��j�b�g�e�X�g
TEST(TestCaseInLyrInit, InLyrInit) {
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
TEST(TestCaseInLyrGC, GlobalCapture) {
	//�\�i�[�Z���T
	stg_csr_dtct_clstr[0].st_dtct_crd[2].In_X = -100;
	stg_csr_dtct_clstr[0].st_dtct_crd[2].In_Y = 200;
	stg_csr_dtct_clstr[0].InCrdNum = 3;
	//PVW
	stg_pvm_dtct_clstr[0].st_dtct_crd[3].In_X = -200;
	stg_pvm_dtct_clstr[0].st_dtct_crd[3].In_Y = -300;
	stg_pvm_dtct_clstr[0].InCrdNum = 4;
	stg_pvm_dtct_clstr[1].st_dtct_crd[0].In_X = 100;
	stg_pvm_dtct_clstr[1].st_dtct_crd[0].In_Y = 100;
	stg_pvm_dtct_clstr[1].InCrdNum = 1;

	vdg_InLyr_GlobalCapture();

	EXPECT_EQ(-100, stg_InLyr_SnrDtctClstr[0].st_crd[2].In_X);
	EXPECT_EQ(200, stg_InLyr_SnrDtctClstr[0].st_crd[2].In_Y);
	EXPECT_EQ(3, stg_InLyr_SnrDtctClstr[0].InCrdNum);
	EXPECT_EQ(-200, stg_InLyr_SodDtctClstr[0].st_crd[3].In_X);
	EXPECT_EQ(-300, stg_InLyr_SodDtctClstr[0].st_crd[3].In_Y);
	EXPECT_EQ(4, stg_InLyr_SodDtctClstr[0].InCrdNum);
	EXPECT_EQ(100, stg_InLyr_SodDtctClstr[1].st_crd[0].In_X);
	EXPECT_EQ(100, stg_InLyr_SodDtctClstr[1].st_crd[0].In_Y);
	EXPECT_EQ(1, stg_InLyr_SodDtctClstr[1].InCrdNum);
}

//vds_InLyr_CapSodClstr()�̃��j�b�g�e�X�g
TEST(TestCaseInLyrCSC, CapSodClstr) {

	st_pvm_clstr* psts_PvmClstr; // �O���f�[�^��PVM���m�N���X�^�p�̃|�C���^
	st_sod_clstr* psts_SodClstr; // InLyr��PVM���m�N���X�^�p�̃|�C���^

	psts_PvmClstr = &stg_pvm_dtct_clstr[0];
	psts_SodClstr = &stg_InLyr_SodDtctClstr[0];
	
	//PVW
	psts_PvmClstr->st_dtct_crd[0].In_X = (S2)100;
	psts_PvmClstr->st_dtct_crd[0].In_Y = (S2)200;
	psts_PvmClstr->InCrdNum = (U1)1;
	psts_PvmClstr->EmClstrState = (U1)1;
	psts_SodClstr->st_crd[0].In_X = (S2)0;
	psts_SodClstr->st_crd[0].In_Y = (S2)0;
	psts_SodClstr->InCrdNum = (U1)0;
	psts_SodClstr->EmClstrState = (U1)0;

	vds_InLyr_CapSodClstr(psts_PvmClstr,psts_SodClstr);

	EXPECT_EQ(100, psts_SodClstr->st_crd[0].In_X);
	EXPECT_EQ(200, psts_SodClstr->st_crd[0].In_Y);
	EXPECT_EQ(1, psts_SodClstr->InCrdNum);
	EXPECT_EQ(1, psts_SodClstr->EmClstrState);
}
