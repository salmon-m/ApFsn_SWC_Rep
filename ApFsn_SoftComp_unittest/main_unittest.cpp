#include "pch.h"
#include "ApFsn_mainComp.h"
#include "main.cpp"

//main_schedule()のユニットテスト
TEST(TestCaseMain, TestMain) {
	main_schedule();
	EXPECT_EQ(0, u1s_main_CnInitial);
	EXPECT_TRUE(true);
}

TEST(TestCaseMain, TestMain2) {
	main_schedule();
	EXPECT_EQ(1, u1s_main_InCnt);
	EXPECT_TRUE(true);
}

TEST(TestCaseMain, TestMain3) {
	u1s_main_InCnt = 3;
	main_schedule();
	EXPECT_EQ(1, u1s_main_Cn4Cycle);
	EXPECT_TRUE(true);
}