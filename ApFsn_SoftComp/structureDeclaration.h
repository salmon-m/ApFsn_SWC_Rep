#pragma once
#include "typeDifference.h"

//ApFsn_SoftComp���̍\���̒�`
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

typedef struct
{
	U1 CnSnrDtct;   //�\�i�[���m�̗L��
	U1 CnSodDtct;   //PVM���m�̗L��
	U1 InOcpy;      //���[��
	U1 CnObjSet;    //���̊m��t���O
}st_GridMap;


//ApFsn_SoftComp�̊O��IF�̍\���̒�`�i�_�~�[��`�����A�{�t�@�C���ɐݒ�j
typedef struct
{
	st_crd st_dtct_crd[5];   //�ő���W��
	U1 InCrdNum;             //���m���W��
	U1 EmClstrState;         //�N���X�^���
	U1 Dummy[2];             //�_�~�[��`�i�A���C�����g�p�j
}st_csr_clstr;

typedef struct
{
	st_crd st_dtct_crd[6];  //�ő���W��
	U1 InCrdNum;            //���m���W��
	U1 EmClstrState;        //�N���X�^���
	U1 Dummy[2];            //�_�~�[��`�i�A���C�����g�p�j
}st_pvm_clstr;