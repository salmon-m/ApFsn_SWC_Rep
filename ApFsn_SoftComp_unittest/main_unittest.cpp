#include "pch.h"
#include "ApFsn_mainComp.h"
#include "main.cpp"

//main_schedule()�̃��j�b�g�e�X�g
TEST(TestCaseMainSchedule, TestMainSchedule1) {
	main_schedule();
	EXPECT_EQ(0, u1s_main_CnInitial);
}

TEST(TestCaseMainSchedule, TestMainSchedule2) {
	u1s_main_CnInitial = OFF;
	u1s_main_InCnt = 0;
	main_schedule();
	EXPECT_EQ(1, u1s_main_InCnt);
}

TEST(TestCaseMainSchedule, TestMainSchedule3) {
	u1s_main_CnInitial = OFF;
	u1s_main_InCnt = 3;
	main_schedule();
	EXPECT_EQ(1, u1s_main_Cn4Cycle);
}

//main_init()�̃��j�b�g�e�X�g
TEST(TestCaseMainInit, TestMainInit) {
	vdg_main_init();
	EXPECT_EQ(1, u1s_main_InLyrResult);
	EXPECT_EQ(1, u1s_main_PrcResult);
	EXPECT_EQ(1, u1s_main_OutLyrResult);
}

//vdg_main_4cycle()�̃��j�b�g�e�X�g
TEST(TestCaseMain4cycle, TestMain4cycle1) {
	vdg_main_4cycle();
	EXPECT_EQ(2, u1s_main_InLyrResult);
	EXPECT_EQ(2, u1s_main_PrcResult);
	EXPECT_EQ(2, u1s_main_OutLyrResult);
}
