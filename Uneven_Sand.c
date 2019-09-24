#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

	unsigned long int number, lower = 1 , upper = 2000000000;
	char reply[10];
	int counter = 1;
	number = (lower+upper)/2;
		
	printf("%lu\n", number);
	scanf("%s", reply);

	while(reply[0] != 'O'){


		if(reply[0] == 'S'){
			lower = number;
			number = (lower+upper)/2;
			
			if(number == lower || counter == 31){
				printf("%lu\n", number+1);
				break;
			}

			counter++;
		} else{
			upper = number;
			number = (lower+upper)/2;

			if(counter == 31){
				printf("%lu\n", number-1);
				break;
			}
			counter++;
		}

		printf("%lu\n", number);
		scanf("%s",reply); 		
				
	}


	return 0;
}
