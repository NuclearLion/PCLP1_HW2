#ifndef _QUERIES_H_
#define _QUERIES_H_

#include "matrix_caracteristics.h"
#include "matrix_io.h"

int check_error(int index, int c_ind);

void interrogate_dim(caracteristics *db, int index);

void query_print(caracteristics *db, int index);

void query_resize(caracteristics *db, int index);

#endif
