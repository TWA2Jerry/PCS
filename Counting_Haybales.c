#include <stdio.h>
#include <stdlib.h>

int comparator(const void * a, const void * b){

	int c = *(const int*)a;
	int d = *(const int*)b;

	if(c > d){
		return 1;

	}

	else if(c == d){
		return 0;

	}

	else{
		return -1; 
	}

}

int binary_search(int target, int lower, int upper, int * array){

	int middle = (lower+upper)/2;
	
	if(target == array[middle] || middle == lower) {
		return middle; 

	}

	else if(target > array[middle]){
		return binary_search(target, middle, upper, array);

	}

	else{
		return binary_search(target, lower, middle, array);
	}

}

int main(void) {

	int num_haybales, num_queries;
	int * haybale_position, *results_array;
	scanf("%d %d", &num_haybales, &num_queries);
	haybale_position = (int*) malloc(num_haybales*sizeof(int));
	results_array = (int*)malloc(num_queries*sizeof(int));
	for(int i = 0; i<num_haybales; i++){
		scanf("%d", &haybale_position[i]);
	}

	mergesort(haybale_position,num_haybales, 4, comparator);
	for(int i = 0; i<num_queries; i++){
		int lower, upper;
		scanf("%d %d", &lower, &upper);
		int lower_index = binary_search(lower, 0, num_haybales-1, haybale_position);
		if(lower > haybale_position[lower_index]){
			lower_index += 1;

		}

		int upper_index = binary_search(upper, 0, num_haybales-1,haybale_position);

		if(upper < haybale_position[upper_index]){
			upper_index -= 1;
		}

		else if(upper > haybale_position[upper_index] && upper >= haybale_position[upper_index+1]){
			upper_index += 1;
		}		
		if(upper_index-lower_index != 0){		
			results_array[i] = upper_index-lower_index+1;
		}
		
		else if(upper_index-lower_index == 0 && upper != lower && lower <= haybale_position[num_haybales-1]){
			results_array[i] = 1;

		}

		else{
			results_array[i] = upper_index-lower_index; 
		}

	}



	for(int i = 0; i<num_queries; i++){

		printf("%d\n", results_array[i]);

	}		
	
	return 0;

}
