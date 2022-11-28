#include "queries.h"

//check if current index corresponds to any matrix
int check_error(int index, int c_ind) {
	if (c_ind > index) {
		printf("No matrix with the given index\n");
		return 1;
	}
	return 0;
}

//print dimensions of requested matrix
void interrogate_dim(caracteristics *db, int index) {
	int c_ind = 0;
	scanf("%d", &c_ind);
	if (check_error(index, c_ind)) {
		return;
	}
	printf("%d %d\n", db[c_ind].n, db[c_ind].m);
}

//print requested matrix
void query_print(caracteristics *db, int index) {
	int c_ind = 0; //current read index of requested matrix
	scanf("%d", &c_ind);
	if (check_error(index, c_ind)) {
		return;
	}
	display_matrix(db[c_ind].mat, db[c_ind].n, db[c_ind].m);
}
