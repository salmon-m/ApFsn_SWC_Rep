#pragma once
#include "typeDifference.h"

//�\���̐錾
typedef struct
{
	S2 In_X;   //X���W
	S2 In_Y;   //Y���W
}st_crd;

typedef struct
{
	st_crd st_crd[5];   //�ő���W�� 5
	U1 InCrdNum;            //���m���W��
	U1 EmClstrState;        //�N���X�^���
}st_snr_clstr;

typedef struct
{
	st_crd st_crd[6];   //�ő���W�� 6
	U1 InCrdNum;            //���m���W��
	U1 EmClstrState;        //�N���X�^���
}st_sod_clstr;


extern st_snr_clstr stg_InLyr_SnrDtctClstr[3];   //�\�i�[�Z���T���m�N���X�^
extern st_sod_clstr stg_InLyr_SodDtctClstr[4];   //PVM���m�N���X�^

