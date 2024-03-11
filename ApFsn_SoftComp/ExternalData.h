#include "typeDifference.h"

typedef struct
{
	S2 In_X;
	S2 In_Y;
}st_csr_crd, st_pvm_crd;

typedef struct
{
	st_csr_crd st_dtct_crd[5];
	U1 InCrdNum;
	U1 EmClstrState;
	U1 Dummy[2];
}st_csr_clstr;

typedef struct
{
	st_pvm_crd st_dtct_crd[6];
	U1 InCrdNum;
	U1 EmClstrState;
	U1 Dummy[2];
}st_pvm_clstr;


st_csr_clstr stg_csr_dtct_clstr[3];
st_pvm_clstr stg_pvm_dtct_clstr[4];

