#include <stdio.h>
#include <stdlib.h>

int num_haybales;

int solver(int * haybales, int lower, int upper){
	int num_haybales_between = 0;
	for(int i = 0; i<num_haybales; i++){
		if(haybales[i] >= lower && haybales[i] <= upper){

			num_haybales_between++;
		}

	}

	return num_haybales_between;


}


int main(void){

	int  num_queries;
	int * haybales, *results_array;
	scanf("%d %d", &num_haybales, &num_queries);
	haybales = (int*)malloc(num_haybales*sizeof(int));
	results_array = (int*)malloc(num_queries*sizeof(int));

	for(int i = 0; i<num_haybales; i++){
		scanf("%d",&haybales[i]);

	}

	for(int j = 0; j<num_queries; j++){
		int lower, upper;
		scanf("%d %d", &lower, &upper);
		results_array[j] = solver(haybales, lower, upper);
	}

	for(int k = 0; k<num_queries; k++){
		printf("%d\n", results_array[k]);

	}	

	return 0;
}
