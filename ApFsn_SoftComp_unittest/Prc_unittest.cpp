#include "pch.h"
#include "InLyr.h"
#include "Prc.h"
#include "Prc.cpp"

//vdg_Prc_init()�̃��j�b�g�e�X�g
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


//vdg_Prc_GridUpdate()�̃��j�b�g�e�X�g
// 
// �Ԃ̌���ɂ���
// 2�̌��m���d�Ȃ��Ă���A���̂̊m��t���O����
TEST(TestCasePrcGU, MultiSnrPvm_ConfObj) {

	stg_InLyr_SnrDtctClstr[0].st_crd[0].In_X = (S2)-1000;
	stg_InLyr_SnrDtctClstr[0].st_crd[0].In_Y = (S2)-500;
	stg_InLyr_SnrDtctClstr[0].InCrdNum = (U1)1;
	stg_InLyr_SnrDtctClstr[0].EmClstrState = (U1)1;
	stg_InLyr_SnrDtctClstr[1].st_crd[0].In_X = (S2)-1000;
	stg_InLyr_SnrDtctClstr[1].st_crd[0].In_Y = (S2)-500;
	stg_InLyr_SnrDtctClstr[1].InCrdNum = (U1)1;
	stg_InLyr_SnrDtctClstr[1].EmClstrState = (U1)1;

	//PVM�p
	stg_InLyr_SodDtctClstr[0].st_crd[0].In_X = (U1)-1000;
	stg_InLyr_SodDtctClstr[0].st_crd[0].In_Y = (U1)-500;
	stg_InLyr_SodDtctClstr[0].InCrdNum = (U1)1;
	stg_InLyr_SodDtctClstr[0].EmClstrState = (U1)1;
	stg_InLyr_SodDtctClstr[1].st_crd[0].In_X = (U1)-1000;
	stg_InLyr_SodDtctClstr[1].st_crd[0].In_Y = (U1)-500;
	stg_InLyr_SodDtctClstr[1].InCrdNum = (U1)1;
	stg_InLyr_SodDtctClstr[1].EmClstrState = (U1)1;

	vdg_Prc_GridUpdate();
	EXPECT_EQ(1, stg_Prc_ArGridInfo[0][0].CnSnrDtct);
	EXPECT_EQ(1, stg_Prc_ArGridInfo[0][0].CnSodDtct);
	EXPECT_EQ(20, stg_Prc_ArGridInfo[0][0].InOcpy);
	EXPECT_EQ(1, stg_Prc_ArGridInfo[0][0].CnObjSet);
}
// 2�̌��m���d�Ȃ��Ă���A���̂̊m��t���O�Ȃ�
TEST(TestCasePrcGU, MultiSnrPvm_NoConfObj) {

	stg_InLyr_SnrDtctClstr[0].st_crd[0].In_X = (S2)-200;
	stg_InLyr_SnrDtctClstr[0].st_crd[0].In_Y = (S2)-100;
	stg_InLyr_SnrDtctClstr[0].InCrdNum = (U1)1;
	stg_InLyr_SnrDtctClstr[0].EmClstrState = (U1)1;
	//PVM�p
	stg_InLyr_SodDtctClstr[0].st_crd[0].In_X = (U1)-200;
	stg_InLyr_SodDtctClstr[0].st_crd[0].In_Y = (U1)-100;
	stg_InLyr_SodDtctClstr[0].InCrdNum = (U1)1;
	stg_InLyr_SodDtctClstr[0].EmClstrState = (U1)1;

	vdg_Prc_GridUpdate();
	EXPECT_EQ(1, stg_Prc_ArGridInfo[400][800].CnSnrDtct);
	EXPECT_EQ(1, stg_Prc_ArGridInfo[400][800].CnSodDtct);
	EXPECT_EQ(10, stg_Prc_ArGridInfo[400][800].InOcpy);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[400][800].CnObjSet);
}

// �\�i�[�݂̂̌��m������A���̂̊m��t���O����
TEST(TestCasePrcGU, SingleSnr_ConfObj) {

	stg_InLyr_SnrDtctClstr[0].st_crd[0].In_X = (S2)-900;
	stg_InLyr_SnrDtctClstr[0].st_crd[0].In_Y = (S2)-400;
	stg_InLyr_SnrDtctClstr[0].st_crd[1].In_X = (S2)-900;
	stg_InLyr_SnrDtctClstr[0].st_crd[1].In_Y = (S2)-400;
	stg_InLyr_SnrDtctClstr[0].InCrdNum = (U1)2;
	stg_InLyr_SnrDtctClstr[0].EmClstrState = (U1)1;
	stg_InLyr_SnrDtctClstr[1].st_crd[0].In_X = (S2)-900;
	stg_InLyr_SnrDtctClstr[1].st_crd[0].In_Y = (S2)-400;
	stg_InLyr_SnrDtctClstr[1].InCrdNum = (U1)1;
	stg_InLyr_SnrDtctClstr[1].EmClstrState = (U1)1;
	stg_InLyr_SnrDtctClstr[2].st_crd[0].In_X = (S2)-900;
	stg_InLyr_SnrDtctClstr[2].st_crd[0].In_Y = (S2)-400;
	stg_InLyr_SnrDtctClstr[2].InCrdNum = (U1)1;
	stg_InLyr_SnrDtctClstr[2].EmClstrState = (U1)1;

	vdg_Prc_GridUpdate();
	EXPECT_EQ(1, stg_Prc_ArGridInfo[100][100].CnSnrDtct);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[100][100].CnSodDtct);
	EXPECT_EQ(20, stg_Prc_ArGridInfo[100][100].InOcpy);
	EXPECT_EQ(1, stg_Prc_ArGridInfo[100][100].CnObjSet);
}
// �\�i�[�݂̂̌��m������A���̂̊m��t���O�Ȃ�
TEST(TestCasePrcGU, SingleSnr_NoConfObj) {

	stg_InLyr_SnrDtctClstr[0].st_crd[0].In_X = (S2)-1000;
	stg_InLyr_SnrDtctClstr[0].st_crd[0].In_Y = (S2)500;	
	stg_InLyr_SnrDtctClstr[0].InCrdNum = (U1)1;
	stg_InLyr_SnrDtctClstr[0].EmClstrState = (U1)1;
	stg_InLyr_SnrDtctClstr[1].st_crd[0].In_X = (S2)-1000;
	stg_InLyr_SnrDtctClstr[1].st_crd[0].In_Y = (S2)500;
	stg_InLyr_SnrDtctClstr[1].InCrdNum = (U1)1;
	stg_InLyr_SnrDtctClstr[1].EmClstrState = (U1)0;
	stg_InLyr_SnrDtctClstr[2].st_crd[0].In_X = (S2)-1000;
	stg_InLyr_SnrDtctClstr[2].st_crd[0].In_Y = (S2)500;
	stg_InLyr_SnrDtctClstr[2].InCrdNum = (U1)1;
	stg_InLyr_SnrDtctClstr[2].EmClstrState = (U1)0;

	vdg_Prc_GridUpdate();
	EXPECT_EQ(1, stg_Prc_ArGridInfo[1000][0].CnSnrDtct);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[1000][0].CnSodDtct);
	EXPECT_EQ(5, stg_Prc_ArGridInfo[1000][0].InOcpy);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[1000][0].CnObjSet);
}

// PVM�݂̂̌��m������A���̂̊m��t���O����
TEST(TestCasePrcGU, SinglePvm_ConfObj) {

	stg_InLyr_SodDtctClstr[0].st_crd[0].In_X = (S2)-200;
	stg_InLyr_SodDtctClstr[0].st_crd[0].In_Y = (S2)200;
	stg_InLyr_SodDtctClstr[0].st_crd[1].In_X = (S2)-200;
	stg_InLyr_SodDtctClstr[0].st_crd[1].In_Y = (S2)200;
	stg_InLyr_SodDtctClstr[0].InCrdNum = (U1)2;
	stg_InLyr_SodDtctClstr[0].EmClstrState = (U1)1;
	stg_InLyr_SodDtctClstr[1].st_crd[0].In_X = (S2)-200;
	stg_InLyr_SodDtctClstr[1].st_crd[0].In_Y = (S2)200;
	stg_InLyr_SodDtctClstr[1].InCrdNum = (U1)1;
	stg_InLyr_SodDtctClstr[1].EmClstrState = (U1)1;
	stg_InLyr_SodDtctClstr[2].st_crd[0].In_X = (S2)-200;
	stg_InLyr_SodDtctClstr[2].st_crd[0].In_Y = (S2)200;
	stg_InLyr_SodDtctClstr[2].InCrdNum = (U1)1;
	stg_InLyr_SodDtctClstr[2].EmClstrState = (U1)1;

	vdg_Prc_GridUpdate();
	EXPECT_EQ(0, stg_Prc_ArGridInfo[700][800].CnSnrDtct);
	EXPECT_EQ(1, stg_Prc_ArGridInfo[700][800].CnSodDtct);
	EXPECT_EQ(20, stg_Prc_ArGridInfo[700][800].InOcpy);
	EXPECT_EQ(1, stg_Prc_ArGridInfo[700][800].CnObjSet);
}
// PVM�݂̂̌��m������A���̂̊m��t���O�Ȃ�
TEST(TestCasePrcGU, SinglePvm_NoConfObj) {

	stg_InLyr_SodDtctClstr[0].st_crd[0].In_X = (S2)-900;
	stg_InLyr_SodDtctClstr[0].st_crd[0].In_Y = (S2)500;
	stg_InLyr_SodDtctClstr[0].InCrdNum = (U1)1;
	stg_InLyr_SodDtctClstr[0].EmClstrState = (U1)1;
	stg_InLyr_SodDtctClstr[1].st_crd[0].In_X = (S2)-900;
	stg_InLyr_SodDtctClstr[1].st_crd[0].In_Y = (S2)500;
	stg_InLyr_SodDtctClstr[1].InCrdNum = (U1)0;
	stg_InLyr_SodDtctClstr[1].EmClstrState = (U1)1;
	stg_InLyr_SodDtctClstr[2].st_crd[0].In_X = (S2)-900;
	stg_InLyr_SodDtctClstr[2].st_crd[0].In_Y = (S2)500;
	stg_InLyr_SodDtctClstr[2].InCrdNum = (U1)1;
	stg_InLyr_SodDtctClstr[2].EmClstrState = (U1)0;

	vdg_Prc_GridUpdate();
	EXPECT_EQ(0, stg_Prc_ArGridInfo[1000][100].CnSnrDtct);
	EXPECT_EQ(1, stg_Prc_ArGridInfo[1000][100].CnSodDtct);
	EXPECT_EQ(5, stg_Prc_ArGridInfo[1000][100].InOcpy);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[1000][100].CnObjSet);
}

// ���m�Ȃ��A���̂̊m��t���O�Ȃ�
TEST(TestCasePrcGU, NoDetection_NoConfObj) {

	stg_InLyr_SnrDtctClstr[0].st_crd[0].In_X = (S2)-500;
	stg_InLyr_SnrDtctClstr[0].st_crd[0].In_Y = (S2)0;
	stg_InLyr_SnrDtctClstr[0].InCrdNum = (U1)1;
	stg_InLyr_SnrDtctClstr[0].EmClstrState = (U1)0;
	//PVM�p
	stg_InLyr_SodDtctClstr[0].st_crd[0].In_X = (U1)-500;
	stg_InLyr_SodDtctClstr[0].st_crd[0].In_Y = (U1)0;
	stg_InLyr_SodDtctClstr[0].InCrdNum = (U1)1;
	stg_InLyr_SodDtctClstr[0].EmClstrState = (U1)0;

	vdg_Prc_GridUpdate();
	EXPECT_EQ(0, stg_Prc_ArGridInfo[500][500].CnSnrDtct);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[500][500].CnSodDtct);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[500][500].InOcpy);
	EXPECT_EQ(0, stg_Prc_ArGridInfo[500][500].CnObjSet);
}

//�Ԃ̑O��