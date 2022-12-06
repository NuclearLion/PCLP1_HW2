//Dan Dominic Staicu 311CA
#include "queries.h"

//alloc memory for a new mat in db, read it's dimensions, alloc mem
//of the new mat, and read it's values from STDIN
void input(charact_t **db, int *index, int *mat_cnt)
{
	alloc_new_in_db(db, mat_cnt, index);
	scanf("%d%d", &(*db)[*index].n, &(*db)[*index].m);
	(*db)[*index].mat = alloc_matrix((*db)[*index].n, (*db)[*index].m);
	read_matrix((*db)[*index].mat, (*db)[*index].n, (*db)[*index].m);
}

//print dimensions of requested matrix
void interrogate_dim(charact_t *db, int index, int mat_cnt)
{
	//read index of requested mat
	int c_ind = 0; //current read index of requested matrix
	scanf("%d", &c_ind);
	//check if mat index is inside the db
	if (check_error(index, c_ind, mat_cnt))
		return;
	printf("%d %d\n", db[c_ind].n, db[c_ind].m);
}

//print requested matrix
void query_print(charact_t *db, int index, int mat_cnt)
{
	int c_ind = 0; //current read index of requested matrix
	scanf("%d", &c_ind);

	//check if mat index is inside the db
	if (check_error(index, c_ind, mat_cnt))
		return;

	display_matrix(db[c_ind].mat, db[c_ind].n, db[c_ind].m);
}

//allocate to curent mat the new mat
void query_resize(charact_t *db, int index, int mat_cnt)
{
	int ind = 0; //current read index of requested matrix
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
}

//read indexes and allocate new space for the new mat
//the stras variable is a boolean that represets which algorithm to use
//for multipling (classic or Strassen)
void query_multiply(charact_t **db, int *index, int *mat_cnt, int stras)
{
	//matrix 1 index and matrix 2 index
	int m1_ind = 0, m2_ind = 0;
	scanf("%d%d", &m1_ind, &m2_ind);
	if (check_error(*index, m1_ind, *mat_cnt))
		return;
	if (check_error(*index, m2_ind, *mat_cnt))
		return;

	//Mat1 column and mat2 row amount need to be the same
	//if it's Strassen, it actually checks if both mats have the same dim
	//as they are square mats
	if ((*db)[m1_ind].m != (*db)[m2_ind].n) {
		printf("Cannot perform matrix multiplication\n");
		return;
	}

	//alloc new space for new mat in database
	alloc_new_in_db(db, mat_cnt, index);

	//the new mat has m1's nr of rows and m2's nr of cols
	(*db)[*index].n = (*db)[m1_ind].n;
	(*db)[*index].m = (*db)[m2_ind].m;

	//check if it's a Strassen multiplication
	if (!stras) {
		//alloc mat's mem and fill it with values
		(*db)[*index].mat = product_mat((*db)[m1_ind].mat, (*db)[m2_ind].mat,
		(*db)[*index].n, (*db)[m1_ind].m, (*db)[*index].m);
	} else {
		//if it's Strassen, alloc mem for new mat which is used as parameter
		(*db)[*index].mat = alloc_matrix((*db)[*index].n, (*db)[*index].n);
		strassen((*db)[m1_ind].mat, (*db)[m2_ind].mat, (*db)[m1_ind].n,
				 (*db)[*index].mat);
	}
}

//replace the mat with it's transposed
void query_transposed(charact_t *db, int index, int mat_cnt)
{
	int ind = 0;
	scanf("%d", &ind);
	//check if mat's index is inside the database
	if (check_error(index, ind, mat_cnt))
		return;

	//create the new mat
	int **aux = transp_mat(db[ind].mat, db[ind].n, db[ind].m);
	//free the old one
	free_mat(db[ind].mat, db[ind].n);
	//and assign the old one to the new one
	db[ind].mat = aux;
	//swap the number of lines with the number of cols
	swap_any(&db[ind].n, &db[ind].m, (size_t)sizeof(int));
}

//check if a mat can be rised to a power
void query_pow(charact_t *db, int index, int mat_cnt)
{
	int ind = 0, pow = 0;
	scanf("%d %d", &ind, &pow);
	//check if mat's index is inside the database
	if (check_error(index, ind, mat_cnt))
		return;
	if (pow < 0) {
		printf("Power should be positive\n");
		return;
	}
	if (db[ind].n != db[ind].m) {
		printf("Cannot perform matrix multiplication\n");
		return;
	}
	db[ind].mat = mat_pow(db[ind].mat, db[ind].n, pow);
}

//delete a mat from db
void query_del(charact_t **db, int *index, int *cnt_mat)
{
	int ind = 0;
	scanf("%d", &ind);
	//check if mat's index is inside the database
	if (check_error(*index, ind, *cnt_mat))
		return;

	//free the targeted mat's memory
	free_mat((*db)[ind].mat, (*db)[ind].n);
	//and overwrite all the others
	for (int i = ind; i < *index; ++i)
		overwrite(&(*db)[i], &(*db)[i + 1], (size_t)sizeof(charact_t));

	//substract 1 from all indexes
	--*cnt_mat;
	--*index;
	//and realloc the space, with 1 less
	*db = realloc(*db, *cnt_mat * sizeof(charact_t));
}

//free everything inside the db
void free_all(charact_t *db, int index)
{
	//free the memory of every single mat which was manually allocated
	for (int i = 0; i <= index; ++i)
		free_mat(db[i].mat, db[i].n);
	//and finally everything elese
	free(db);
}
