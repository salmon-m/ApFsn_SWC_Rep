#include "pch.h"
#include "main.h"
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
	vdg_main_init();
	EXPECT_EQ(1, u1s_main_InLyrResult);
	EXPECT_EQ(1, u1s_main_PrcResult);
	EXPECT_EQ(1, u1s_main_OutLyrResult);
}

//vdg_main_4cycle()のユニットテスト
TEST(TestCaseMain4cycle, TestMain4cycle1) {
	vdg_main_4cycle();
	EXPECT_EQ(2, u1s_main_InLyrResult);
	EXPECT_EQ(2, u1s_main_PrcResult);
	EXPECT_EQ(2, u1s_main_OutLyrResult);
}
