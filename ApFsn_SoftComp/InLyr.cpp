#include "typeDifference.h"
#include "ExternalData.h" //�O������DummyIF�p
#include "main.h"		  //�O������DummyIF�p
#include "structureDeclaration.h"

// �v���g�^�C�v�錾
void vdg_InLyr_init(void);
void vdg_InLyr_GlobalCapture(void);

st_snr_clstr stg_InLyr_SnrDtctClstr[3]; // �\�i�[�Z���T���m�N���X�^
st_sod_clstr stg_InLyr_SodDtctClstr[4]; // PVM���m�N���X�^

// ������
void vdg_InLyr_init(void)
{
	S1 s1t_InLyrI_SnrClusterCount;
	S1 s1t_InLyrI_SnrCrdCount;
	S1 s1t_InLyrI_SodClusterCount;
	S1 s1t_InLyrI_SodCrdCount;

	// �\�i�[�Z���T���m�N���X�^�p�ϐ��̏�����
	for (s1t_InLyrI_SnrClusterCount = (S1)0; s1t_InLyrI_SnrClusterCount < (S1)3; s1t_InLyrI_SnrClusterCount++)
	{
		for (s1t_InLyrI_SnrCrdCount = (S1)0; s1t_InLyrI_SnrCrdCount < (S1)5; s1t_InLyrI_SnrCrdCount++)
		{
			stg_InLyr_SnrDtctClstr[s1t_InLyrI_SnrClusterCount].st_crd[s1t_InLyrI_SnrCrdCount].In_X = (S2)0;
			stg_InLyr_SnrDtctClstr[s1t_InLyrI_SnrClusterCount].st_crd[s1t_InLyrI_SnrCrdCount].In_Y = (S2)0;
		}
		stg_InLyr_SnrDtctClstr[s1t_InLyrI_SnrClusterCount].InCrdNum = (U1)0;
		stg_InLyr_SnrDtctClstr[s1t_InLyrI_SnrClusterCount].EmClstrState = (U1)0;
	}

	// PVM���m�N���X�^�p�ϐ��̏�����
	for (s1t_InLyrI_SodClusterCount = (S1)0; s1t_InLyrI_SodClusterCount < (S1)4; s1t_InLyrI_SodClusterCount++)
	{
		for (s1t_InLyrI_SodCrdCount = (S1)0; s1t_InLyrI_SodCrdCount < (S1)6; s1t_InLyrI_SodCrdCount++)
		{
			stg_InLyr_SodDtctClstr[s1t_InLyrI_SodClusterCount].st_crd[s1t_InLyrI_SodCrdCount].In_X = (S2)0;
			stg_InLyr_SodDtctClstr[s1t_InLyrI_SodClusterCount].st_crd[s1t_InLyrI_SodCrdCount].In_Y = (S2)0;
		}
		stg_InLyr_SodDtctClstr[s1t_InLyrI_SodClusterCount].InCrdNum = (U1)0;
		stg_InLyr_SodDtctClstr[s1t_InLyrI_SodClusterCount].EmClstrState = (U1)0;
	}

	return;
}

// �O���f�[�^�̎�荞��
void vdg_InLyr_GlobalCapture(void)
{
	S1 s1t_InLyrGC_SnrClusterCount;
	S1 s1t_InLyrGC_SnrCrdCount;
	S1 s1t_InLyrGC_SodClusterCount;
	S1 s1t_InLyrGC_SodCrdCount;

	// �\�i�[�Z���T���m�N���X�^��荞��
	for (s1t_InLyrGC_SnrClusterCount = (S1)0; s1t_InLyrGC_SnrClusterCount < (S1)3; s1t_InLyrGC_SnrClusterCount++)
	{
		for (s1t_InLyrGC_SnrCrdCount = (S1)0; s1t_InLyrGC_SnrCrdCount < (S1)5; s1t_InLyrGC_SnrCrdCount++)
		{
			stg_InLyr_SnrDtctClstr[s1t_InLyrGC_SnrClusterCount].st_crd[s1t_InLyrGC_SnrCrdCount].In_X = stg_csr_dtct_clstr[s1t_InLyrGC_SnrClusterCount].st_dtct_crd[s1t_InLyrGC_SnrCrdCount].In_X;
			stg_InLyr_SnrDtctClstr[s1t_InLyrGC_SnrClusterCount].st_crd[s1t_InLyrGC_SnrCrdCount].In_Y = stg_csr_dtct_clstr[s1t_InLyrGC_SnrClusterCount].st_dtct_crd[s1t_InLyrGC_SnrCrdCount].In_Y;
		}
		stg_InLyr_SnrDtctClstr[s1t_InLyrGC_SnrClusterCount].InCrdNum = stg_csr_dtct_clstr[s1t_InLyrGC_SnrClusterCount].InCrdNum;
		stg_InLyr_SnrDtctClstr[s1t_InLyrGC_SnrClusterCount].EmClstrState = stg_csr_dtct_clstr[s1t_InLyrGC_SnrClusterCount].EmClstrState;
	}

	// PVM���m�N���X�^��荞��
	for (s1t_InLyrGC_SodClusterCount = (S1)0; s1t_InLyrGC_SodClusterCount < (S1)4; s1t_InLyrGC_SodClusterCount++)
	{
		for (s1t_InLyrGC_SodCrdCount = (S1)0; s1t_InLyrGC_SodCrdCount < (S1)6; s1t_InLyrGC_SodCrdCount++)
		{
			stg_InLyr_SodDtctClstr[s1t_InLyrGC_SodClusterCount].st_crd[s1t_InLyrGC_SodCrdCount].In_X = stg_pvm_dtct_clstr[s1t_InLyrGC_SodClusterCount].st_dtct_crd[s1t_InLyrGC_SodCrdCount].In_X;
			stg_InLyr_SodDtctClstr[s1t_InLyrGC_SodClusterCount].st_crd[s1t_InLyrGC_SodCrdCount].In_Y = stg_pvm_dtct_clstr[s1t_InLyrGC_SodClusterCount].st_dtct_crd[s1t_InLyrGC_SodCrdCount].In_Y;
		}
		stg_InLyr_SodDtctClstr[s1t_InLyrGC_SodClusterCount].InCrdNum = stg_pvm_dtct_clstr[s1t_InLyrGC_SodClusterCount].InCrdNum;
		stg_InLyr_SodDtctClstr[s1t_InLyrGC_SodClusterCount].EmClstrState = stg_pvm_dtct_clstr[s1t_InLyrGC_SodClusterCount].EmClstrState;
	}

	return;
}