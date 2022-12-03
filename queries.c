//Dan Dominic Staicu 311CA
#include "queries.h"

//print dimensions of requested matrix
void interrogate_dim(charact *db, int index, int mat_cnt)
{
	int c_ind = 0;
	scanf("%d", &c_ind);
	if (check_error(index, c_ind, mat_cnt))
		return;

	printf("%d %d\n", db[c_ind].n, db[c_ind].m);
}

//print requested matrix
void query_print(charact *db, int index, int mat_cnt)
{
	int c_ind = 0; //current read index of requested matrix
	scanf("%d", &c_ind);
	if (check_error(index, c_ind, mat_cnt))
		return;

	display_matrix(db[c_ind].mat, db[c_ind].n, db[c_ind].m);
}

//allocate to curent mat the new mat
void query_resize(charact *db, int index, int mat_cnt)
{
	int ind = 0;
	scanf("%d", &ind);
	if (check_error(index, ind, mat_cnt)) {
		//in case the index it's not inside, we still need to read and trash
		//the next values, in order to skip to the next input
		trash();
		return;
	}
	int loc_n = db[ind].n;
	int **aux = resize_mat(db, ind);
	free_mat(db[ind].mat, loc_n);
	db[ind].mat = aux;
	//db[ind].mat = resize_mat(db, ind);
}

//read indexes and allocate new space for the new mat
void query_multiply(charact **db, int *index, int *mat_cnt, int stras)
{
	//matrix 1 index and matrix 2 index
	int m1_ind = 0, m2_ind = 0;
	scanf("%d%d", &m1_ind, &m2_ind);
	if (check_error(*index, m1_ind, *mat_cnt))
		return;
	if (check_error(*index, m2_ind, *mat_cnt))
		return;

	//Mat1 column and mat2 row amount need to be the same
	if ((*db)[m1_ind].m != (*db)[m2_ind].n) {
		printf("Cannot perform matrix multiplication\n");
		return;
	}

	//alloc new space for new mat in database
	alloc_new_in_db(db, mat_cnt, index);

	//the new mat has m1's nr of rows and m2's nr of cols
	(*db)[*index].n = (*db)[m1_ind].n;
	(*db)[*index].m = (*db)[m2_ind].m;

	if (stras == 0) {
		//alloc mat's mem and fill it with values
		(*db)[*index].mat = product_mat((*db)[m1_ind].mat, (*db)[m2_ind].mat,
		(*db)[*index].n, (*db)[m1_ind].m, (*db)[*index].m);
	} else {
		(*db)[*index].mat = alloc_matrix((*db)[*index].n, (*db)[*index].n);
		strassen((*db)[m1_ind].mat, (*db)[m2_ind].mat,(*db)[m1_ind].n, (*db)[*index].mat);
	}
		// (*db)[*index].mat = strassen((*db)[m1_ind].mat, (*db)[m2_ind].mat,
		// (*db)[m1_ind].n);
}
