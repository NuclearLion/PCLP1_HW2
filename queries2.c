//Dan Dominic Staicu 311CA
#include "queries2.h"

//replace the mat with it's transposed
void query_transposed(charact *db, int index)
{
	int ind = 0;
	scanf("%d", &ind);
	if (check_error(index, ind)) {
		return;
	}
	//maybe a leak here?
	db[ind].mat = transp_mat(db[ind].mat, db[ind].n, db[ind].m);
	swap_any(&db[ind].n, &db[ind].m, (size_t)sizeof(int));
}

void query_pow(charact *db, int index)
{
	int ind = 0, pow = 0;
	scanf("%d %d", &ind, &pow);
	if (check_error(index, ind)) {
		return;
	}
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