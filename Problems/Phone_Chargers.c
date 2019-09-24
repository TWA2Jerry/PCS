#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max(int a, int b){

	if(a > b){
		return a;
	}

	else{
		return b;
	}

}

int min(int a, int b){

	if(a<b){
		return a;
	}

	else{
		return b;
	}

}

int main(void) {

	int num_test;
	int phone1[3];
	int phone2[3];
	int phone3[3];
	int phone_ready[3];

	
	scanf("%d",&num_test);
	int * solutions = malloc(num_test*sizeof(int)); 
	for(int i = 0; i<num_test;i++){
		int cost = 1000000;
		for(int j = 0; j<3;j++){
			
			scanf("%d",&phone1[j]);	
			
		}

		for(int k = 0; k<3; k++){

			scanf("%d",&phone2[k]);			
		}

		for(int l = 0; l<3; l++){

		
			scanf("%d",&phone3[l]);
		}

		
		for(int m = 0; m<3; m++){
			phone_ready[0] = 0;
			phone_ready[1] = 0;
			phone_ready[2] = 0;
			int temp_cost = 0;
	
			phone_ready[m] = 1;
			temp_cost = phone1[m];
			for(int j = 0; j<3;j++){
                temp_cost = phone1[m];
				if(phone_ready[j] == 0){
					temp_cost = max(temp_cost,phone2[j]);
					phone_ready[j] = 1; 					
				}

				else{
					continue;

				}
				for(int k = 0; k<3; k++){

					if(phone_ready[k] == 0){
						temp_cost = max(temp_cost, phone3[k]);
						cost = min(cost,temp_cost);
						phone_ready[j] = 0;
						phone_ready[k] = 0;
					}

					else{
						continue;
					}	
				}
			}
		}
		
		solutions[i] = cost;

	}
	for(int i = 0; i<num_test; i++){

		printf("%d\n",solutions[i]);
	}

	return 0;
}
