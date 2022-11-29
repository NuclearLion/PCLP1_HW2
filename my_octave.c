//Dan Dominic Staicu 311CA
#include "matrix_io.h"
#include "queries.h"
#include "matirx_mem_op.h"

int main(void)
{
	char c = 0;
	int mat_cnt = 0; //of how many matrixes were read
	int index = 0; //of last matrix
	//db is short from data base (of all matrixes)
	caracteristics *db = calloc(1, sizeof(caracteristics));
	if (!db) {
		printf("db calloc failed\n");
		return -1;
	}

	while (scanf("%c", &c) != EOF) {
		switch (c) {
		case 'L':
			++mat_cnt;
			index = mat_cnt - 1;
			db = realloc(db, mat_cnt * sizeof(caracteristics));
			if (!db)
				return -1;
			scanf("%d%d", &db[index].n, &db[index].m);
			db[index].mat = alloc_matrix(db[index].n, db[index].m);
			read_matrix(db[index].mat, db[index].n, db[index].m);
			//display_matrix(db[index].mat, db[index].n, db[index].m);
			break;
		case 'D':
			interrogate_dim(db, index);
			break;
		case 'P':
			query_print(db, index);
			break;
		case 'C':
			//resize_mat(db, index);
			query_resize(db, index);
			// printf("!!!HERE:\n");
			// query_print(db, index);
			break;
		default:
			printf("Unrecognized command\n");
			break;
		}
		getchar();
	}
	return 0;
}
