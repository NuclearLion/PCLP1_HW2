//Dan Dominic Staicu 311CA
#ifndef _QUERIES_H_
#define _QUERIES_H_

#include "matrix_caracteristics.h"
#include "matrix_io.h"
#include "matirx_mem_op.h"
#include "strassen.h"
#include "utils.h"

void input(charact_t **db, int *index, int *mat_cnt);

void query_multiply(charact_t **db, int *index, int *mat_cnt, int stras);

void interrogate_dim(charact_t *db, int index, int mat_cnt);

void query_print(charact_t *db, int index, int mat_cnt);

void query_resize(charact_t *db, int index, int mat_cnt);

void query_transposed(charact_t *db, int index, int mat_cnt);

void query_pow(charact_t *db, int index, int mat_cnt);

void query_del(charact_t **db, int *index, int *cnt_mat);

void free_all(charact_t *db, int index);

#endif
