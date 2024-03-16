#include "typeDifference.h"
#include "structureDeclaration.h"
#include "InLyr.h"
#include "Prc.h"
#include "OutLyr.h"

// Dummy��`
// �{���� main.cpp�̊O�����͂ɂȂ邪�A
// ApFsn_SoftComp.cpp�ł�main()��`���Ă���A
// main()�������J�[���͂����Unittest.exe��main()���Ă�ł��܂�����
// ��ނ��� main.cpp �ɊO�����͂��`
U1 u1g_ApFsn_IG;
st_csr_clstr stg_csr_dtct_clstr[3];
st_pvm_clstr stg_pvm_dtct_clstr[4];
// Dummy��`

static U1 u1s_main_InCnt;	 // �J�E���g��
static U1 u1s_main_Cn4Cycle; // ������t���O
/* ��������UnitTest�p�̕ϐ��錾
 *static U1 u1s_main_InLyrResult = (U1)0;
 *static U1 u1s_main_PrcResult = (U1)0;
 *static U1 u1s_main_OutLyrResult = (U1)0;
 * �����܂�UnitTest�p */

// �v���g�^�C�v�錾
void vdg_main_init(void);
void vdg_main_4cycle(void);
/* ��������UnitTest�p�̃v���g�^�C�v�錾
 *void vdg_InLyr_init(void);
 *void vdg_Prc_init(void);
 *void vdg_OutLyr_init(void);
 *void vdg_InLyr_GlobalCapture(void);
 *void vdg_Prc_GridUpdate(void);
 *void vdg_OutLyr_GlobalUpdate(void);
 * �����܂�UnitTest�p */

void main_schedule(void)
{
	// ����t���O
	if (u1g_ApFsn_IG == ON)
	{
		vdg_main_init();
	}
	else
	{
		// �J�E���g
		u1s_main_InCnt++;
		// �J�E���g���m�F
		if ((u1s_main_InCnt % 4) == 0)
		{
			u1s_main_Cn4Cycle = ON;
			u1s_main_InCnt = (U1)0;
		}
		else
		{
			u1s_main_Cn4Cycle = OFF;
		}
		// ������t���O
		if (u1s_main_Cn4Cycle == ON)
		{
			vdg_main_4cycle();
		}
		// else�͏�������
		else
		{
		}
	}
	return;
}

// �R���|�̏�����
void vdg_main_init(void)
{
	// �����W���[����RAM������
	u1s_main_InCnt = (U1)0;
	u1s_main_Cn4Cycle = OFF;

	// �����W���[���̏������֐��R�[��
	vdg_InLyr_init();
	vdg_Prc_init();
	vdg_OutLyr_init();

	return;
}

// ������ŏ��������s
void vdg_main_4cycle(void)
{
	vdg_InLyr_GlobalCapture();
	vdg_Prc_GridUpdate();
	vdg_OutLyr_GlobalUpdate();
	return;
}

/* ��������UnitTest�p */
// ����������
/*
 *void vdg_InLyr_init(void) {
 *	u1s_main_InLyrResult = 1;
 *}
 *
 *void vdg_Prc_init(void) {
 *	u1s_main_PrcResult = 1;
 *}
 *
 *void vdg_OutLyr_init(void) {
 *	u1s_main_OutLyrResult = 1;
 *}
 *
 *���������
 *
 *void vdg_InLyr_GlobalCapture(void) {
 *	u1s_main_InLyrResult = 2;
 *}
 *
 *void vdg_Prc_GridUpdate(void) {
 *	u1s_main_PrcResult = 2;
 *}
 *
 *void vdg_OutLyr_GlobalUpdate(void) {
 *	u1s_main_OutLyrResult = 2;
 *}
 * �����܂�UnitTest�p */
