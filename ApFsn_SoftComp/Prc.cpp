#include "typeDifference.h"
#include "structureDeclaration.h"
#include "InLyr.h"

// �v���g�^�C�v�錾
void vdg_Prc_init(void);
void vdg_Prc_GridUpdate(void);
void vds_Prc_SetObj(st_GridMap *psts_PrcSO_GridMapInfo[1000][4000]);

st_GridMap stg_Prc_ArGridInfo[1000][4000]; // �O���b�h�}�b�v���

st_GridMap *psts_PrcSO_ArGridInfo[1000][4000]; // �O���b�h�}�b�v���̃|�C���^

// ������
void vdg_Prc_init(void)
{
	U2 u2t_PrcI_LoopRow;
	U2 u2t_PrcI_LoopColumn;

	for (u2t_PrcI_LoopRow = (U2)0; u2t_PrcI_LoopRow < (U2)1000; u2t_PrcI_LoopRow++)
	{
		for (u2t_PrcI_LoopColumn = (U2)0; u2t_PrcI_LoopColumn < (U2)4000; u2t_PrcI_LoopColumn++)
		{
			stg_Prc_ArGridInfo[u2t_PrcI_LoopRow][u2t_PrcI_LoopColumn].CnSnrDtct = (U1)0;
			stg_Prc_ArGridInfo[u2t_PrcI_LoopRow][u2t_PrcI_LoopColumn].CnSodDtct = (U1)0;
			stg_Prc_ArGridInfo[u2t_PrcI_LoopRow][u2t_PrcI_LoopColumn].InOcpy = (U1)0;
			stg_Prc_ArGridInfo[u2t_PrcI_LoopRow][u2t_PrcI_LoopColumn].CnObjSet = (U1)0;

			psts_PrcSO_ArGridInfo[u2t_PrcI_LoopRow][u2t_PrcI_LoopColumn] = &stg_Prc_ArGridInfo[u2t_PrcI_LoopRow][u2t_PrcI_LoopColumn];
		}
	}

	return;
}

void vdg_Prc_GridUpdate(void)
{
	S1 s1t_PrcGU_SnrClusterCount;
	S1 s1t_PrcGU_SnrCrdCount;
	S1 s1t_PrcGU_SodClusterCount;
	S1 s1t_PrcGU_SodCrdCount;
	S2 s2t_PrcGU_X = (S2)0;
	S2 s2t_PrcGU_Y = (S2)0;

	// �\�i�[
	for (s1t_PrcGU_SnrClusterCount = (S1)0; s1t_PrcGU_SnrClusterCount < (S1)3; s1t_PrcGU_SnrClusterCount++)
	{
		for (s1t_PrcGU_SnrCrdCount = (S1)0; s1t_PrcGU_SnrCrdCount < stg_InLyr_SnrDtctClstr[s1t_PrcGU_SnrClusterCount].InCrdNum; s1t_PrcGU_SnrCrdCount++)
		{
			if (stg_InLyr_SnrDtctClstr[s1t_PrcGU_SnrClusterCount].EmClstrState == (U1)1)
			{
				s2t_PrcGU_X = stg_InLyr_SnrDtctClstr[s1t_PrcGU_SnrClusterCount].st_crd[s1t_PrcGU_SnrCrdCount].In_X + (S2)1000;
				s2t_PrcGU_Y = stg_InLyr_SnrDtctClstr[s1t_PrcGU_SnrClusterCount].st_crd[s1t_PrcGU_SnrCrdCount].In_Y + (S2)500;
				//�z��O�A�N�Z�X�K�[�h
				if (s2t_PrcGU_X >= 0)
				{
					if (s2t_PrcGU_Y >= 0)
					{
						stg_Prc_ArGridInfo[(U2)s2t_PrcGU_Y][(U2)s2t_PrcGU_X].CnSnrDtct = (U1)1;
						stg_Prc_ArGridInfo[(U2)s2t_PrcGU_Y][(U2)s2t_PrcGU_X].InOcpy = stg_Prc_ArGridInfo[(U2)s2t_PrcGU_Y][(U2)s2t_PrcGU_X].InOcpy + (U1)5;
						// �O�a�K�[�h
						if (stg_Prc_ArGridInfo[(U2)s2t_PrcGU_Y][(U2)s2t_PrcGU_X].InOcpy > (U1)250)
						{
							stg_Prc_ArGridInfo[(U2)s2t_PrcGU_Y][(U2)s2t_PrcGU_X].InOcpy = (U1)250;
						}
					}
				}
			}
		}
	}

	// PVM
	for (s1t_PrcGU_SodClusterCount = (S1)0; s1t_PrcGU_SodClusterCount < (S1)4; s1t_PrcGU_SodClusterCount++)
	{
		for (s1t_PrcGU_SodCrdCount = (S1)0; s1t_PrcGU_SodCrdCount < stg_InLyr_SodDtctClstr[s1t_PrcGU_SodClusterCount].InCrdNum; s1t_PrcGU_SodCrdCount++)
		{
			if (stg_InLyr_SodDtctClstr[s1t_PrcGU_SodClusterCount].EmClstrState == (U1)1)
			{
				s2t_PrcGU_X = stg_InLyr_SodDtctClstr[s1t_PrcGU_SodClusterCount].st_crd[s1t_PrcGU_SodCrdCount].In_X + (S2)1000;
				s2t_PrcGU_Y = stg_InLyr_SodDtctClstr[s1t_PrcGU_SodClusterCount].st_crd[s1t_PrcGU_SodCrdCount].In_Y + (S2)500;
				//�z��O�A�N�Z�X�K�[�h
				if (s2t_PrcGU_X >= 0)
				{
					if (s2t_PrcGU_Y >= 0)
					{
						stg_Prc_ArGridInfo[(U2)s2t_PrcGU_Y][(U2)s2t_PrcGU_X].CnSodDtct = (U1)1;
						stg_Prc_ArGridInfo[(U2)s2t_PrcGU_Y][(U2)s2t_PrcGU_X].InOcpy = stg_Prc_ArGridInfo[(U2)s2t_PrcGU_Y][(U2)s2t_PrcGU_X].InOcpy + (U1)5;
						// �O�a�K�[�h
						if (stg_Prc_ArGridInfo[(U2)s2t_PrcGU_Y][(U2)s2t_PrcGU_X].InOcpy > (U1)250)
						{
							stg_Prc_ArGridInfo[(U2)s2t_PrcGU_Y][(U2)s2t_PrcGU_X].InOcpy = (U1)250;
						}
					}
				}
			}
		}
	}

	// ���̊m��
	vds_Prc_SetObj(psts_PrcSO_ArGridInfo);

	return;
}

void vds_Prc_SetObj(st_GridMap *psts_PrcSO_GridMapInfo[1000][4000])
{
	U2 u2t_PrcGU_LoopRow;
	U2 u2t_PrcGU_LoopColumn;

	for (u2t_PrcGU_LoopRow = (U2)0; u2t_PrcGU_LoopRow < (U2)1000; u2t_PrcGU_LoopRow++)
	{
		for (u2t_PrcGU_LoopColumn = (U2)0; u2t_PrcGU_LoopColumn < (U2)4000; u2t_PrcGU_LoopColumn++)
		{
			if (psts_PrcSO_GridMapInfo[u2t_PrcGU_LoopRow][u2t_PrcGU_LoopColumn]->InOcpy >= (U1)16)
			{
				psts_PrcSO_GridMapInfo[u2t_PrcGU_LoopRow][u2t_PrcGU_LoopColumn]->CnObjSet = (U1)1;
			}
		}
	}
	
	return;
}