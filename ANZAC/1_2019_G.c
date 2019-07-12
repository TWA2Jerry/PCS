#include <stdio.h>

int main(void){

	int lawn[10][10];
	for(int row_itr = 0; row_itr<10; row_itr++){
		for(int col_itr = 0; col_itr<10; col_itr++){
			lawn[row_itr][col_itr] = 1;
		}

	}

	int num_weeks;
	scanf("%d", &num_weeks);
	
	int columns[3];
	int rows[3];

	for(int week = 0; week<=num_weeks-1; week++){

		for(int i = 0; i<10; i++){
                	for(int j = 0; j<10; j++){
                                    lawn[i][j]++;
                           }
                        }


		scanf("%d %d %d", &rows[0], &rows[1], &rows[2]);
		scanf("%d %d %d", &columns[0], &columns[1], &columns[2]);

		for(int i = 0; i<3; i++){

			for(int j = 0; j<10; j++){
				lawn[rows[i]-1][j] = 1;
			}

		}

		for(int i = 0; i<3; i++){

                        for(int j = 0; j<10; j++){
                        	lawn[j][columns[i]-1] = 1;
			}

                }

		

	}

	for(int i = 0; i<10; i++){
		for(int j = 0; j<10; j++){
			printf("%d ", lawn[i][j]);

		}

		printf("\n");
	
	}

}
