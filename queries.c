//Dan Dominic Staicu 311CA
#include "queries.h"
#include "matirx_mem_op.h"

#define MOD 10007

//check if current index corresponds to any matrix
int check_error(int index, int c_ind) {
	if (c_ind > index) {
		printf("No matrix with the given index\n");
		return 1;
	}
	return 0;
}

//print dimensions of requested matrix
void interrogate_dim(charact *db, int index) {
	int c_ind = 0;
	scanf("%d", &c_ind);
	if (check_error(index, c_ind)) {
		return;
	}
	printf("%d %d\n", db[c_ind].n, db[c_ind].m);
}

//print requested matrix
void query_print(charact *db, int index) {
	int c_ind = 0; //current read index of requested matrix
	scanf("%d", &c_ind);
	if (check_error(index, c_ind)) {
		return;
	}
	display_matrix(db[c_ind].mat, db[c_ind].n, db[c_ind].m);
}

//allocate to curent mat the new mat
void query_resize(charact *db, int index) {
	int ind = 0;
	scanf("%d", &ind);
	if (check_error(index, ind)) {
		return;
	}
	db[ind].mat = resize_mat(db, ind);
}

//read indexes and allocate new space for the new mat
void query_multiply(charact **db, int *index, int *mat_cnt) {
	//matrix 1 and matrix 2 index and
	int m1_ind = 0, m2_ind = 0;
	scanf("%d%d", &m1_ind, &m2_ind);
	if (check_error(*index, m1_ind))
		return;
	if (check_error(*index, m2_ind))
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
	//alloc mat's mem
	(*db)[*index].mat = alloc_matrix((*db)[*index].n, (*db)[*index].m);

	//create the product mat
	for (int i = 0; i < (*db)[*index].n; ++i) {
		for (int j = 0; j < (*db)[*index].m; ++j) {
			int sum = 0;
			for (int k = 0; k < (*db)[m1_ind].m; ++k)
				sum = (sum + (*db)[m1_ind].mat[i][k] * (*db)[m2_ind].mat[k][j])
				% MOD;
			(*db)[*index].mat[i][j] = sum; 
		}
	}
}
