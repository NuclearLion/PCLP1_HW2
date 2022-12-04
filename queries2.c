//Dan Dominic Staicu 311CA
#include "queries2.h"

//replace the mat with it's transposed
void query_transposed(charact *db, int index, int mat_cnt)
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
void query_pow(charact *db, int index, int mat_cnt)
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

//overwrite a value over another, regardless their data type
void overwrite(void *a, void *b, size_t s)
{
	memcpy(a, b, s);
}

//delete a mat from db
void query_del(charact **db, int *index, int *cnt_mat)
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
		overwrite(&(*db)[i], &(*db)[i + 1], (size_t)sizeof(charact));

	//substract 1 from all indexes
	--*cnt_mat;
	--*index;
	//and realloc the space, with 1 less
	*db = realloc(*db, *cnt_mat * sizeof(charact));
}

//free everything inside the db
void free_all(charact *db, int index)
{
	//free the memory of every single mat which was manually allocated
	for (int i = 0; i <= index; ++i)
		free_mat(db[i].mat, db[i].n);
	//and finally everything elese
	free(db);
}
