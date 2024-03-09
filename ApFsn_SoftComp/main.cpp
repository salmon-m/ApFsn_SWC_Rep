#include "typeDifference.h"

//Dummy定義
//本当は main.cppの外部入力になるが、
//ApFsn_SoftComp.cppではmain()定義しており、
//main()をリンカー入力するとUnittest.exeがmain()を呼んでしまうため
//やむえず main.cpp に外部入力を定義
U1 u1g_ApFsn_IG;
//Dummy定義


static U1 u1s_main_InCnt;
static U1 u1s_main_Cn4Cycle;
/* ここからUnitTest用の変数宣言 */
static U1 u1s_main_InLyrResult = (U1)0;
static U1 u1s_main_PrcResult = (U1)0;
static U1 u1s_main_OutLyrResult = (U1)0;
/* ここまでUnitTest用 */

//プロトタイプ宣言
void vdg_main_init(void);
void vdg_main_4cycle(void);
/* ここからUnitTest用のプロトタイプ宣言 */
void vdg_InLyr_init(void);
void vdg_Prc_init(void);
void vdg_OutLyr_init(void);
void vdg_InLyr_GlobalCapture(void);
void vdg_Prc_GridUpdate(void);
void vdg_OutLyr_GlobalUpdate(void);
/* ここまでUnitTest用 */


void main_schedule(void)
{
	//初回フラグ
	if (u1g_ApFsn_IG == ON)
		{
			vdg_main_init();
		}
	else
	{
		//カウント
		u1s_main_InCnt++;
		u1s_main_InCnt %= 4;
		//カウント数確認
		if ((u1s_main_InCnt % 4) == 0)
		{
			u1s_main_Cn4Cycle = ON;
		}
		else
		{
			u1s_main_Cn4Cycle = OFF;
		}
		//定周期フラグ
		if (u1s_main_Cn4Cycle == ON)
		{
			vdg_main_4cycle();
		}
		//elseは処理無し
		else {
		}

	}
	return;
}

// コンポの初期化
void vdg_main_init(void) {
	//自モジュールのRAM初期化
	u1s_main_InCnt = (U1)0;
	u1s_main_Cn4Cycle = OFF;

	//他モジュールの初期化関数コール
	vdg_InLyr_init();
	vdg_Prc_init();
	vdg_OutLyr_init();

	return;
}

//定周期で処理を実行
void vdg_main_4cycle(void) {
	vdg_InLyr_GlobalCapture();
	vdg_Prc_GridUpdate();
	vdg_OutLyr_GlobalUpdate();
	return;
}

/* ここからUnitTest用 */
//初期化処理
void vdg_InLyr_init(void) {
	u1s_main_InLyrResult = 1;
}
void vdg_Prc_init(void) {
	u1s_main_PrcResult = 1;
}
void vdg_OutLyr_init(void) {
	u1s_main_OutLyrResult = 1;
}

//定周期処理
void vdg_InLyr_GlobalCapture(void) {
	u1s_main_InLyrResult = 2;
}
void vdg_Prc_GridUpdate(void) {
	u1s_main_PrcResult = 2;
}
void vdg_OutLyr_GlobalUpdate(void) {
	u1s_main_OutLyrResult = 2;
}
/* ここまでUnitTest用 */

