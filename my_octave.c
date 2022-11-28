#include "matrix_io.h"

int main(void)
{
	char c = 0;
	int index = 0;
	typedef struct {
		int n, m;
		int **mat;
	}caracteristics;
	//db is short from data base (of all matrixes)
	caracteristics *db = calloc(1, sizeof(caracteristics));
	if (!db) {
		printf("prost\n");
		return -1;
	}

	while (scanf("%c", &c) != EOF) {
		switch (c) {
		case 'L':
			++index;
			db = realloc(db, index * sizeof(caracteristics));
			if (!db)
				return -1;
			scanf("%d%d", &db[index].n, &db[index].m);
			db[index].mat = alloc_matrix(db[index].n, db[index].m);
			read_matrix(db[index].mat, db[index].n, db[index].m);
			//display_matrix(db[index].mat, db[index].n, db[index].m);
			break;
		default:
			printf("Unrecognized command\n");
			break;
		}
		getchar();
	}
	return 0;
}
