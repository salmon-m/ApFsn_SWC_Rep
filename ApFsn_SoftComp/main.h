#include "typeDifference.h"
#include "structureDeclaration.h"

//公開関数
extern void vdg_main_init(void);
extern void vdg_main_4cycle(void);
extern void main_schedule(void);


//Dummy：ApFsn_SoftCompの外部入力になるが、mainで定義して動かす
extern U1 u1g_ApFsn_IG;
extern st_csr_clstr stg_csr_dtct_clstr[3];
extern st_pvm_clstr stg_pvm_dtct_clstr[4];