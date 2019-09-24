#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int num_haybales, num_queries;
	scanf("%d %d", &num_haybales, &num_queries);
	int * results_array = (int*)malloc(num_queries*sizeof(int));

	int * haybales = (int*)malloc(100000*sizeof(int));
	int * haybales_cumulative = (int*)malloc(100000*sizeof(int));
	int haybale_temp;

	for(int  i = 0; i<100000; i++){
		haybales[i] = 0;
	}
	for(int i = 0; i<num_haybales; i++){
		scanf("%d",&haybale_temp);
		haybales[haybale_temp-1] = 1;
	}

	int haybale_sum = 0;
	for(int i = 0; i<100000; i++){
		if(haybales[i] == 1){
			haybale_sum++;
		}

		haybales_cumulative[i] = haybale_sum;

	}

	for(int j = 0; j<num_queries; j++){
		int lower, upper;
		scanf("%d %d", &lower, &upper);
		int num_haybales = haybales_cumulative[upper]-haybales_cumulative[lower];
		if(haybales[lower] == 1){
			num_haybales++;
		}

		results_array[j] = num_haybales; 
	}
	
	for(int j = 0; j<num_queries; j++){
		printf("%d\n", results_array[j]);

	}
	return 0;
}
