#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

	long number, lower = 1 , upper = 2000000000;
	char * reply  = (char*)malloc(10*sizeof(char));
	
	number = (lower+upper)/2;
	printf("%li\n", number);
	
	scanf("%*li%s\n", reply);
	while(reply[0] != 'O'){

		if(reply[0] == 'S'){
            lower = number;
			number = (lower+upper)/2;
            if(number == lower){
                printf("%li\n", number+1);
                break;
            }
		}

		else{
            upper = number;
			number = (lower+upper)/2;
        }

		printf("%li\n", number);
		scanf("%s\n", reply);

	}

	return 0;


}
