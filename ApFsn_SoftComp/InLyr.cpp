#include "typeDifference.h"

//プロトタイプ宣言
void vdg_InLyr_init(void); 
void vdg_InLyr_GlobalCapture(void);

//構造体宣言
typedef struct
{
	S2 In_X;
	S2 In_Y;
}st_snr_crd;

typedef struct
{
	st_snr_crd st_crd[5];
	U1 InCrdNum;
	U1 EmClstrState;
}st_snr_clstr;

typedef struct
{
	S2 In_X;
	S2 In_Y;
}st_sod_crd;

typedef struct
{
	st_sod_crd st_crd[6];
	U1 InCrdNum;
	U1 EmClstrState;
}st_sod_clstr;


st_snr_clstr stg_InLyr_SnrDtctClstr[3];
st_sod_clstr stg_InLyr_SodDtctClstr[4];


void vdg_InLyr_init(void) 
{
	S1 S1_InLyr_LoopI = (S1)0;
	S1 S1_InLyr_LoopJ = (S1)0;

	for (S1_InLyr_LoopI = 0; S1_InLyr_LoopI < 3; S1_InLyr_LoopI++) 
	{
		for (S1_InLyr_LoopJ = 0; S1_InLyr_LoopJ < 5; S1_InLyr_LoopJ++) {
			stg_InLyr_SnrDtctClstr[S1_InLyr_LoopI].st_crd[S1_InLyr_LoopJ].In_X = 0;
			stg_InLyr_SnrDtctClstr[S1_InLyr_LoopI].st_crd[S1_InLyr_LoopJ].In_Y = 0;
		}
		stg_InLyr_SnrDtctClstr[S1_InLyr_LoopI].InCrdNum = 0;
		stg_InLyr_SnrDtctClstr[S1_InLyr_LoopI].EmClstrState = 0;
	}

	for (S1_InLyr_LoopI = 0; S1_InLyr_LoopI < 4; S1_InLyr_LoopI++)
	{
		for (S1_InLyr_LoopJ = 0; S1_InLyr_LoopJ < 6; S1_InLyr_LoopJ++) {
			stg_InLyr_SodDtctClstr[S1_InLyr_LoopI].st_crd[S1_InLyr_LoopJ].In_X = 0;
			stg_InLyr_SodDtctClstr[S1_InLyr_LoopI].st_crd[S1_InLyr_LoopJ].In_Y = 0;
		}
		stg_InLyr_SodDtctClstr[S1_InLyr_LoopI].InCrdNum = 0;
		stg_InLyr_SodDtctClstr[S1_InLyr_LoopI].EmClstrState = 0;
	}

	return;
}

void vdg_InLyr_GlobalCapture(void) 
{
	return;
}