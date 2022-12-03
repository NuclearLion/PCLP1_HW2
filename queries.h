//Dan Dominic Staicu 311CA
#ifndef _QUERIES_H_
#define _QUERIES_H_

#include "matrix_caracteristics.h"
#include "matrix_io.h"
#include "matirx_mem_op.h"
#include "strassen.h"

//the CS checker forced me to declare "charact * *db"... not my fault:(
void query_multiply(charact * *db, int *index, int *mat_cnt, int stras);

void interrogate_dim(charact *db, int index, int mat_cnt);

void query_print(charact *db, int index, int mat_cnt);

void query_resize(charact *db, int index, int mat_cnt);

#endif
