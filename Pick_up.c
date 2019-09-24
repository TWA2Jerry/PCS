#include <stdio.h>
#include <math.h>

int main(void){

	int distance;
	scanf("%d", &distance);
	int distance_remaining = distance;
	
	int current_speed_index = 0;
	int num_moves = 0;

	while(distance_remaining != 0){

		int temp_distance = distance_remaining;
	
		while((int)pow(2, (int)log2(temp_distance)) != temp_distance){
			temp_distance -= (int)pow(2,(int)log2(temp_distance));
		}

		distance_remaining -= (int)pow(2, (int)log2(temp_distance));
		num_moves  = (int)log2(temp_distance) - current_speed_index;
		for(int i = 0; i<num_moves; i++){
			printf("Add rockets\n"); 
		}
		
		printf("Go\n");

		current_speed_index = (int)log2(temp_distance);

	}

	return 0;

}
