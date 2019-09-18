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

int main(void) {

	int num_hours, num_pricing_options;
	scanf("%d %d", &num_hours, &num_pricing_options);
	
	int * hours_array = (int*)malloc(num_pricing_options*sizeof(int));
	int * prices_array = (int*)malloc(num_pricing_options*sizeof(int));
	int * possible_array = (int*)malloc((num_hours+10)*sizeof(int));	

	for(int i = 0; i<num_pricing_options; i++){
		scanf("%d %d", &hours_array[i], &prices_array[i]);

	}

	possible_array[0] = 0;
	for(int j = 1; j<(num_hours+10); j++){
		possible_array[j] = 10000000;
		
		for(int hour = 0; hour<num_pricing_options; hour++){
			if(j-hours_array[hour] >= 0 && possible_array[j-hours_array[hour]]+prices_array[hour] < possible_array[j]){
				possible_array[j] = possible_array[j-hours_array[hour]]+prices_array[hour];
				
			}

			else if(j-hours_array[hour] < 0 && prices_array[hour] < possible_array[j]){
				possible_array[j] = prices_array[hour];
			}

		}

	}
	
	printf("%d\n", possible_array[num_hours]);
	return 0;
}
