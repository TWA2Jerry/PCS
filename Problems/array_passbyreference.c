#include <stdio.h>

void change_value(int* array){
	array[1] = 5;
}

int main(void){

	int array[4] = {1,2,3,4};
	change_value(array);
	printf("%d\n", array[1]);
	return 0;
}
