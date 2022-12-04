//Dan Dominic Staicu 311CA
#include "matrix_io.h"
#include "queries2.h"
#include "matirx_mem_op.h"

#define FALSE 0
#define TRUE 1

int main(void)
{
	char c = 0;
	int mat_cnt = 0; //of how many matrixes were read
	int index = 0; //of last matrix

	//db is short from data base (of all matrixes)
	charact *db = malloc(sizeof(charact));
	if (!db) {
		printf("db calloc failed\n");
		return -1;
	}

	//check which command was read from STDIN
	while (scanf("%c", &c) != EOF) {
		switch (c) {
		case 'L':
			input(&db, &index, &mat_cnt);
			break;
		case 'D':
			interrogate_dim(db, index, mat_cnt);
			break;
		case 'P':
			query_print(db, index, mat_cnt);
			break;
		case 'C':
			query_resize(db, index, mat_cnt);
			break;
		case 'M':
			query_multiply(&db, &index, &mat_cnt, FALSE);
			break;
		case 'O':
			sort_db(&db, index, mat_cnt);
			break;
		case 'T':
			query_transposed(db, index, mat_cnt);
			break;
		case 'R':
			query_pow(db, index, mat_cnt);
			break;
		case 'F':
			query_del(&db, &index, &mat_cnt);
			break;
		case 'Q':
			free_all(db, index);
			return 0;
		case 'S':
			query_multiply(&db, &index, &mat_cnt, TRUE);
			break;
		default:
			//if none of the above commands was recognised
			printf("Unrecognized command\n");
			break;
		}
		//to step over the endline
		getchar();
	}
	//in case switch failed, freeing all the memory is still necesary
	free_all(db, index);
	return 0;
}
