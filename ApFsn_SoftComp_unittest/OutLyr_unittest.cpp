#include "pch.h"
#include "OutLyr.h"
#include "OutLyr.cpp"

//vdg_InLyr_init()のユニットテスト
TEST(TestCaseOutLyrInit, TestOutLyrInit) {

	stg_OutLyr_ArGridInfo[0][0].CnObjSet = 1;
	stg_OutLyr_ArGridInfo[900][3500] .CnObjSet= 1;

	vdg_OutLyr_init();

	EXPECT_EQ(0, stg_OutLyr_ArGridInfo[0][0].CnObjSet);
	EXPECT_EQ(0, stg_OutLyr_ArGridInfo[900][3500].CnObjSet);
}

