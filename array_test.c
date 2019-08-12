#include <stdio.h>

void array_changer(int * array){

	array[1] = 5;

}

int main(void){

	int array[5];
	for (int i = 0; i<5; i++){
		array[i] = i;
	}

	array_changer(array);
	for (int i = 0; i<5; i++){
		printf("%d\n", array[i]);
	}

}
