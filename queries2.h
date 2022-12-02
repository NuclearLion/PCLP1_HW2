//Dan Dominic Staicu 311CA
#ifndef _QUERIES2_H_
#define _QUERIES2_H_

#include "queries.h"
#include "matirx_mem_op.h"
#include "utils.h"
#include "matrix_io.h"

void query_transposed(charact *db, int index);

void query_pow(charact *db, int index);

void query_del(charact *db, int *index, int *cnt_mat);

void free_all(charact *db, int index);

#endif