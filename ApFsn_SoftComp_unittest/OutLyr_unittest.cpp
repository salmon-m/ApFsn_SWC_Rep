#include "pch.h"
#include "OutLyr.h"
#include "InLyr.h"
#include "OutLyr.cpp"

//vdg_InLyr_init()�̃��j�b�g�e�X�g
TEST(TestCaseOutLyrInit, Test_OutLyrInit) {

	stg_OutLyr_ArGridInfo[0][0].CnObjSet = 1;
	stg_OutLyr_ArGridInfo[900][3500] .CnObjSet= 1;

	vdg_OutLyr_init();

	EXPECT_EQ(0, stg_OutLyr_ArGridInfo[0][0].CnObjSet);
	EXPECT_EQ(0, stg_OutLyr_ArGridInfo[900][3500].CnObjSet);
}

//�Ԃ̌���A���̌��m����
TEST(TestCaseOutLyrGU, BehindTheCar_ConfObj) {

	stg_Prc_ArGridInfo[0][0].CnSnrDtct = 1;
	stg_Prc_ArGridInfo[0][0].CnSodDtct = 1;
	stg_Prc_ArGridInfo[0][0].InOcpy = 20;
	stg_Prc_ArGridInfo[0][0].CnObjSet = 1;

	vdg_OutLyr_GlobalUpdate();

	EXPECT_EQ(1, stg_OutLyr_ArGridInfo[0][0].CnObjSet);
}

//�Ԃ̌���A���̌��m�Ȃ�
TEST(TestCaseOutLyrGU, BehindTheCar_NoConfObj) {

	stg_Prc_ArGridInfo[0][0].CnSnrDtct = 0;
	stg_Prc_ArGridInfo[0][0].CnSodDtct = 0;
	stg_Prc_ArGridInfo[0][0].InOcpy = 0;
	stg_Prc_ArGridInfo[0][0].CnObjSet = 0;

	vdg_OutLyr_GlobalUpdate();

	EXPECT_EQ(0, stg_OutLyr_ArGridInfo[0][0].CnObjSet);
}

//�Ԃ̑O���A���̌��m����
TEST(TestCaseOutLyrGU, FrontOfTheCar_ConfObj) {
	stg_Prc_ArGridInfo[900][3500].CnSnrDtct = 1;
	stg_Prc_ArGridInfo[900][3500].CnSodDtct = 1;
	stg_Prc_ArGridInfo[900][3500].InOcpy = 20;
	stg_Prc_ArGridInfo[900][3500].CnObjSet = 1;

	vdg_OutLyr_GlobalUpdate();

	EXPECT_EQ(1, stg_OutLyr_ArGridInfo[900][3500].CnObjSet);
}

//�Ԃ̑O���A���̌��m�Ȃ�
TEST(TestCaseOutLyrGU, FrontOfTheCar_NoConfObj) {
	stg_Prc_ArGridInfo[900][3500].CnSnrDtct = 0;
	stg_Prc_ArGridInfo[900][3500].CnSodDtct = 0;
	stg_Prc_ArGridInfo[900][3500].InOcpy = 0;
	stg_Prc_ArGridInfo[900][3500].CnObjSet = 0;

	vdg_OutLyr_GlobalUpdate();

	EXPECT_EQ(0, stg_OutLyr_ArGridInfo[900][3500].CnObjSet);
}