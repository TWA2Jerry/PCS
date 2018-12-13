#include <stdio.h>
#include <stdlib.h>

int num_cols,num_rows;
int * row, *col;

int max(int a, int b){

	if(a > b){
		return a;
	}

	else if(a == b){
		return a;

	}

	else{
		return b;
	}

}

int solve(int x,  int ** s){

	int best = 0;
	
		
		if(x<num_rows-1){
			
			for(int j = 0; j<num_cols; j++){			
				if(col[j] == 0 && row[x] == 0 && s[x][j]==0){
					col[j] = 1;
					row[x] = 1;
					s[x][j] = 1;
					best = max(best,solve(x+1,s)+1);
					col[j] = 0;
					row[x] = 0;
					s[x][j] = 0;
				}

				else{
					best = max(best,solve(x+1,s));

				}

			}

			return best;

		}

		else{

			int solved = 0;

			for (int j = 0; j<num_cols; j++){




				if(col[j] == 0 && row[x] == 0 && s[x][j]==0){
				solved = 1;
				}

			}	
			return solved; 		
			
		}		
		


}

int main(void){

	int num_test;
	scanf("%d",&num_test);
	int * solutions = malloc(num_test*sizeof(int));

	for(int i = 0; i<num_test;i++){
		scanf("%d %d",&num_rows, &num_cols);
		
		int ** s = malloc(num_rows*sizeof(int*));


		row = malloc(num_rows*sizeof(int));
		col = malloc(num_cols*sizeof(int));
		
		for(int n = 0; n<num_rows;n++){
			row[n] = 0;
		}

		for(int o = 0; o<num_cols; o++){
			col[o] = 0;
		}

		for(int j = 0; j<num_rows;j++){
			

			*(s+j) = malloc(num_cols*sizeof(int));
			
			for(int k = 0; k<num_cols; k++){
				scanf("%d",(*(s+j)+k));
			} 	


			
		}

	int max_num = solve(0,s);
	solutions[i] = max_num;		

	}

	for(int l = 0; l<num_test;l++){

		printf("%d\n",solutions[l]);
	}

	return 0;

}
