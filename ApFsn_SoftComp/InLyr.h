#pragma once
#include "structureDeclaration.h"

// ���J�֐�
extern void vdg_InLyr_init(void);
extern void vdg_InLyr_GlobalCapture(void);
extern void vds_InLyr_CapSodClstr(st_pvm_clstr* psts_InLyrCSC_InClstr, st_sod_clstr* psts_InLyrCSC_OutClstr);

// �O�����J�ϐ�
extern st_snr_clstr stg_InLyr_SnrDtctClstr[3]; // �\�i�[�Z���T���m�N���X�^
extern st_sod_clstr stg_InLyr_SodDtctClstr[4]; // PVM���m�N���X�^