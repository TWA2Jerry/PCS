#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int array[4] = {1,2,3,4};
	*(array+5) = 5;
	array[5] = 15;
	printf("%d\n", array[5]);
	return 0;

}
