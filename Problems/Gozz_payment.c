#include <stdio.h>
#include <stdlib.h>

int solver(int target, int a, int b){
	int solved = 0;
	for(int i = 0; i<b; i++){
		int num_remaining = target-((i+1)*7);
		if(num_remaining%5 == 0){
			if((num_remaining/5) <= a){
				solved = 1;

			}

		}	
		
	}

	return solved; 
	
}

int main(void) {

	int num_test, *results_array;
	scanf("%d", &num_test);
	results_array = (int*)malloc(num_test*sizeof(int));
	for(int i = 0; i<num_test; i++){

		int target, a, b;
		scanf("%d %d %d", &target, &a, &b);
		
		results_array[i] = solver(target, a,b);
		 
		

	}

	for(int i = 0; i<num_test; i++){

		if(results_array[i] == 1){
			printf("YES\n");

		}

		else{
			printf("NO\n");	
		}
	}

	return 0;

}

	
