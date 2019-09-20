#include <stdio.h>
#include <stdlib.h>

int num_cols,num_rows;


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

int solve(int x,  int ** s,int * row,int *col){

	int best = 0;
	
		
		if(x<num_rows-1){
			
			for(int j = 0; j<num_cols; j++){			
				if(!col[j] && !row[x] && !s[x][j]){
					col[j] = 1;
					row[x] = 1;
					s[x][j] = 1;
					best = max(best,solve(x+1,s,row,col)+1);

				}

				else{
					best = max(best,solve(x+1,s,row,col));

				}

			}

			return best;

		}

		else{

			int solved = 0;

			for (int j = 0; j<num_cols; j++){




				if(!col[j] && !row[x] && !s[x][j]){
				solved = 1;
				}

			}	
			return solved; 		
			
		}		
		


}

int main(void){

	int num_test;
	scanf("%d",&num_test);
	int ** s;
	for(int i = 0; i<num_test;i++){

		scanf("%d %d",&num_rows, &num_cols);
		s = malloc(num_rows*sizeof(int*));


		int * row = realloc(row,num_rows*sizeof(int));
		int * col = realloc(col,num_cols*sizeof(int));
		
		for(int l = 0; l<num_rows;l++){

			row[l] = 0;
		}

		for(int m = 0; m<num_cols;m++){
			col[m] = 0;

		}

		for(int j = 0; j<num_rows;j++){
			

			*(s+j) = malloc(num_cols*sizeof(int));
			
			for(int k = 0; k<num_cols; k++){
				scanf("%d",(*(s+i)+j));
			} 	


			
		}

	int max_num = solve(0,s,row,col);
	printf("%d\n",max_num);		
		

	}

	return 0;

}
