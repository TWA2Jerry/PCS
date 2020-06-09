#include <stdio.h>
#include <stdlib.h>
int main(void){

	char * p1 = "Yello";
	char * p2 = "Yello";
	char *p3 = (char*)malloc(6*sizeof(char));
	for(int i = 0; i<5; i++){
		p3[i] = 65+i;
	}
	p3[1] = 'D';
	printf("%s\n", p3);
	printf("%c\n", p2[1]);
	char array[6] = "Yello";
	printf("%p %p %p", p1, p2, array);
	return 0;
}
