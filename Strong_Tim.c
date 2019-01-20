#include <stdio.h>

int iterator;
int target; 
int array[20000];
int tests[100];
int n;
int max(int a, int b){

	if(a > b){

		return a;
	}

	else{
		return b;
	}

}

int max_weight(int current_total, int index, int num_weights);

int main(void) {

	int num_test;
	scanf("%d", &num_test);
	
	for(int i = 0; i<num_test; i++){
		int max_num;
		scanf("%d %d", &n, &target);
		for(int j = 0; j<n; j++){

			scanf("%d", &array[j]);
			
		}
		max_num = max_weight(0,0,0);		
		tests[i] = max_num;		

	}

	for(int i = 0; i<num_test; i++){

		printf("%d\n",tests[i]);

	}


	return 0;
}

int max_weight(int current_total, int index, int num_weights) {
    if(index == n){
        
        if(current_total == target){
            return num_weights;
            
        }
        
        
        else{
            return 0;
        }
    }
    
    
    else{
        
        return(max(max_weight(current_total,index+1,num_weights), max_weight(current_total+array[index], index+1,num_weights+1)));
        
    }
    
    
    
    
    
}
