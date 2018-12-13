#include <stdio.h>
#include <stdlib.h>
int max(int a, int b){

	if(a > b){
		return a;

	}

	else{
		return b;

	}

}

int main(void) {


	int num_test;
	scanf("%d",&num_test);
	int * solution = malloc(num_test*sizeof(int));

	int itr = 0;
	for(; itr<num_test; itr++){
		int num_house;
		int sub_sum = 0;
		int best = 0;
		int profit;


		scanf("%d",&num_house);
		for(int i = 0; i<num_house; i++){

			scanf("%d", &profit);
			sub_sum += profit;
			
			if(sub_sum <= 0){
				sub_sum = 0;

			}

			else{

				best = max(best, sub_sum);
			}

		}
		
		solution[itr] = best;

	}
	
	for(int j = 0; j<num_test;j++){

		printf("%d\n",solution[j]);
	}
	return 0;


}
