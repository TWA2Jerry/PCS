#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(void) {

	int num_test;
	scanf("%d",&num_test);
	int * solution = malloc(num_test*sizeof(int));


	for(int i = 0; i<num_test; i++){

		int num, power;
		scanf("%d %d", &num, &power);
		int target = pow(10,power)-1;
		int closest;
		float float_multiple = (float)target/num;
        int multiple = target/num;
        
        if((num/10) >= 1 && power == 1){
            
            closest = 0;
            
        }
        
        else if(power <= 0){
            closest = -1;
        }
        
        else if(num == 0 && power == 1){
            
            closest = 0;
            
        }
        
        else if(num == 0 && power != 1){
            closest = -1;
        }
        
        else{
        
            if(float_multiple < 1){

                closest = -1;

            }

            else{
                closest = num*(multiple);
            }


            

        }
        
        solution[i] = closest;
        
    }

	for(int j = 0; j<num_test; j++){
		printf("%d\n",solution[j]);

	}

	return 0;

}
