#include "pch.h"
#include "ApFsn_PrcComp.h"
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