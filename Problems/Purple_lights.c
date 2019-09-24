#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int minimum(int a, int b){
	
	if(a < b){
		return a;
	}

	else{
		return b;
	}

}

int min = 100000000;
int num_purple;
void solver(int sum, int iteration, int * light_array){

	
	if(iteration == num_purple){
		min = minimum(min,abs(sum));		
	}

	else{
		solver(sum+light_array[2*iteration], iteration+1, light_array);
		solver(sum-light_array[2*iteration+1], iteration+1, light_array);

	}
	

	return;
}

int main(void) {

	int num_test;
	int * results_array;

	scanf("%d", &num_test);
	results_array = (int*)malloc(num_test*sizeof(int));	

	for(int i = 0; i<num_test; i++){
		
		scanf("%d", &num_purple);
		min = 100000000;
		int * lights = (int*)malloc((num_purple*2)*sizeof(int));
		for(int lamp_iterator = 0; lamp_iterator<num_purple; lamp_iterator++){

		int blue_light, red_light;
		scanf("%d %d", &blue_light, &red_light);
		lights[2*lamp_iterator] = blue_light;
		lights[2*lamp_iterator+1] = red_light;
				
	}	
        solver(0,0, lights);
		results_array[i] = min;
	}

	for(int j = 0; j<num_test; j++){
		printf("%d\n", results_array[j]);
	}	
	return 0;
}
