#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int num_test;
	scanf("%d", &num_test);
	int * results_array = (int*)malloc(num_test*sizeof(int));

	for(int i = 0; i<num_test; i++){

		int rooms_array[2001];
		int room1, room2;
		int num_rooms, num_halls;
		int num1s = 0;
		

		scanf("%d %d", &num_rooms, &num_halls);

		for(int l = 0; l<=2000; l++){

			rooms_array[l] = 0;

		}		
		
		for(int j = 0; j<num_halls; j++){
			scanf("%d %d", &room1, &room2);
			rooms_array[room1] += 1;
			rooms_array[room2] += 1;

		}

		for(int k = 1; k<=num_rooms; k++){
			if(rooms_array[k] != 0 && rooms_array[k]%2 != 0){
				num1s += rooms_array[k]%2;

			}

			else if(rooms_array[k] == 0){
				num1s += 2;
			} 	

		}


		if(num_rooms == 1){
			results_array[i] = 0;

		}
		
		else if(num1s%2 == 0){
			results_array[i] = num1s/2;
		}

		else{

			results_array[i] = num1s/2 + 1;

		}

		


	}

	for(int i = 0; i<num_test; i++){
		printf("%d\n", results_array[i]);

	}	
	return 0;

}
