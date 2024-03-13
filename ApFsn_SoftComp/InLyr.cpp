#include "typeDifference.h"
#include "main.h"                  //�O������DummyIF�p
#include "structureDeclaration.h"

//�v���g�^�C�v�錾
void vdg_InLyr_init(void); 
void vdg_InLyr_GlobalCapture(void);

st_snr_clstr stg_InLyr_SnrDtctClstr[3];   //�\�i�[�Z���T���m�N���X�^
st_sod_clstr stg_InLyr_SodDtctClstr[4];   //PVM���m�N���X�^

//������
void vdg_InLyr_init(void) 
{
	S1 S1_InLyrI_LoopI = (S1)0;
	S1 S1_InLyrI_LoopJ = (S1)0;

	//�\�i�[�Z���T���m�N���X�^�p�ϐ��̏�����
	for (S1_InLyrI_LoopI = 0; S1_InLyrI_LoopI < 3; S1_InLyrI_LoopI++) 
	{
		for (S1_InLyrI_LoopJ = 0; S1_InLyrI_LoopJ < 5; S1_InLyrI_LoopJ++) {
			stg_InLyr_SnrDtctClstr[S1_InLyrI_LoopI].st_crd[S1_InLyrI_LoopJ].In_X = (S2)0;
			stg_InLyr_SnrDtctClstr[S1_InLyrI_LoopI].st_crd[S1_InLyrI_LoopJ].In_Y = (S2)0;
		}
		stg_InLyr_SnrDtctClstr[S1_InLyrI_LoopI].InCrdNum = (U1)0;
		stg_InLyr_SnrDtctClstr[S1_InLyrI_LoopI].EmClstrState = (U1)0;
	}

	//PVM���m�N���X�^�p�ϐ��̏�����
	for (S1_InLyrI_LoopI = 0; S1_InLyrI_LoopI < 4; S1_InLyrI_LoopI++)
	{
		for (S1_InLyrI_LoopJ = 0; S1_InLyrI_LoopJ < 6; S1_InLyrI_LoopJ++) {
			stg_InLyr_SodDtctClstr[S1_InLyrI_LoopI].st_crd[S1_InLyrI_LoopJ].In_X = (S2)0;
			stg_InLyr_SodDtctClstr[S1_InLyrI_LoopI].st_crd[S1_InLyrI_LoopJ].In_Y = (S2)0;
		}
		stg_InLyr_SodDtctClstr[S1_InLyrI_LoopI].InCrdNum = (U1)0;
		stg_InLyr_SodDtctClstr[S1_InLyrI_LoopI].EmClstrState = (U1)0;
	}

	return;
}

//�O���f�[�^�̎�荞��
void vdg_InLyr_GlobalCapture(void) 
{
	S1 S1_InLyrGC_LoopI = (S1)0;
	S1 S1_InLyrGC_LoopJ = (S1)0;

	//�\�i�[�Z���T���m�N���X�^��荞��
	for (S1_InLyrGC_LoopI = 0; S1_InLyrGC_LoopI < 3; S1_InLyrGC_LoopI++)
	{
		for (S1_InLyrGC_LoopJ = 0; S1_InLyrGC_LoopJ < 5; S1_InLyrGC_LoopJ++) {
			stg_InLyr_SnrDtctClstr[S1_InLyrGC_LoopI].st_crd[S1_InLyrGC_LoopJ].In_X = stg_csr_dtct_clstr[S1_InLyrGC_LoopI].st_dtct_crd[S1_InLyrGC_LoopJ].In_X;
			stg_InLyr_SnrDtctClstr[S1_InLyrGC_LoopI].st_crd[S1_InLyrGC_LoopJ].In_Y = stg_csr_dtct_clstr[S1_InLyrGC_LoopI].st_dtct_crd[S1_InLyrGC_LoopJ].In_Y;
		}
		stg_InLyr_SnrDtctClstr[S1_InLyrGC_LoopI].InCrdNum = stg_csr_dtct_clstr[S1_InLyrGC_LoopI].InCrdNum;
		stg_InLyr_SnrDtctClstr[S1_InLyrGC_LoopI].EmClstrState = stg_csr_dtct_clstr[S1_InLyrGC_LoopI].EmClstrState;
	}

	//PVM���m�N���X�^��荞��
	for (S1_InLyrGC_LoopI = 0; S1_InLyrGC_LoopI < 4; S1_InLyrGC_LoopI++)
	{
		for (S1_InLyrGC_LoopJ = 0; S1_InLyrGC_LoopJ < 6; S1_InLyrGC_LoopJ++) {
			stg_InLyr_SodDtctClstr[S1_InLyrGC_LoopI].st_crd[S1_InLyrGC_LoopJ].In_X = stg_pvm_dtct_clstr[S1_InLyrGC_LoopI].st_dtct_crd[S1_InLyrGC_LoopJ].In_X;
			stg_InLyr_SodDtctClstr[S1_InLyrGC_LoopI].st_crd[S1_InLyrGC_LoopJ].In_Y = stg_pvm_dtct_clstr[S1_InLyrGC_LoopI].st_dtct_crd[S1_InLyrGC_LoopJ].In_Y;
		}
		stg_InLyr_SodDtctClstr[S1_InLyrGC_LoopI].InCrdNum = stg_pvm_dtct_clstr[S1_InLyrGC_LoopI].InCrdNum;
		stg_InLyr_SodDtctClstr[S1_InLyrGC_LoopI].EmClstrState = stg_pvm_dtct_clstr[S1_InLyrGC_LoopI].EmClstrState;
	}

	return;
}