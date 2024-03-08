#include "pch.h"
#include "ApFsn_mainComp.h"
#include "main.cpp"

//main_schedule()のユニットテスト
TEST(TestCaseMainSchedule, TestMainSchedule1) {
	main_schedule();
	EXPECT_EQ(0, u1s_main_CnInitial);
	EXPECT_TRUE(true);
}

TEST(TestCaseMainSchedule, TestMainSchedule2) {
	u1s_main_CnInitial = OFF;
	u1s_main_InCnt = 0;
	main_schedule();
	EXPECT_EQ(1, u1s_main_InCnt);
	EXPECT_TRUE(true);
}

TEST(TestCaseMainSchedule, TestMainSchedule3) {
	u1s_main_CnInitial = OFF;
	u1s_main_InCnt = 3;
	main_schedule();
	EXPECT_EQ(1, u1s_main_Cn4Cycle);
	EXPECT_TRUE(true);
}

//main_init()のユニットテスト
TEST(TestCaseMainInit, TestMainInit1) {
	vdg_main_init();
	EXPECT_EQ(1, u1s_main_InLyrResult);
	EXPECT_TRUE(true);
}

TEST(TestCaseMainInit, TestMainInit2) {
	vdg_main_init();
	EXPECT_EQ(1, u1s_main_PrcResult);
	EXPECT_TRUE(true);
}

TEST(TestCaseMainInit, TestMainInit3) {
	vdg_main_init();
	EXPECT_EQ(1, u1s_main_OutLyrResult);
	EXPECT_TRUE(true);
}