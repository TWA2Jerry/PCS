#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int num_test;
	scanf("%d", &num_test);
	int * results_array = (int*)malloc(num_test*sizeof(int));
	for(int i = 0; i<num_test; i++){

        int num_hay_bales;
        long long target_height,haybale_total = 0;
		scanf("%d %lli", &num_hay_bales, &target_height);
		long long * haybales = (long long*)malloc(num_hay_bales*sizeof(long long));
		for(int j = 0; j<num_hay_bales; j++){
			scanf("%lli", &haybales[j]);
			

		}
        
        for(int j = 0; j<num_hay_bales; j++){
            haybale_total += haybales[j];
            
        }
        
        if(target_height > haybale_total){
            
            results_array[i] = 0;
        }
        
        else if (target_height == haybale_total){
            results_array[i] = 1;
        }
        
        else{
            int * possible_array =  (int*)malloc(haybale_total*sizeof(int));
            for(long long k = 0; k<haybale_total; k++){
                possible_array[k] = 0;
            }

            possible_array[0] = 1;
            
            for(int j = 0; j<=num_hay_bales; j++){
                for(long long n = haybale_total; n>= 0; n--){
                    if(possible_array[n] == 1){

                        possible_array[(n+haybales[j])] = 1;
                    }
                }

            }

            if(possible_array[target_height] == 1){
                results_array[i] = 1;
            }
            
            else{
                results_array[i] = 0;
            }
            
        }
	
	}

	for(int l = 0; l<num_test; l++){
		if(results_array[l] == 1){
	
			printf("YAY\n");
		}		

		else{
			printf("NAY\n");
		}
	}
	return 0;

}
