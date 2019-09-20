#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void) {

	int num_test;
	scanf("%d",&num_test);
	int * solution = malloc(num_test*sizeof(int));
	for(int i = 0; i<num_test; i++){
		char string[101];
		scanf("%s",string);
		int b = strlen(string)-1;
		int problem = 0;
		if(b<1){
			solution[i] = 1;
		}

		else{
			int front_itr = 0, back_itr = 0;

			while(front_itr <= b-back_itr){

				while(isalpha(string[front_itr]) == 0){

					front_itr++;

				}

				while(isalpha(string[b-back_itr]==0)){
					back_itr++; 

				}

				if(string[front_itr] != string[b-back_itr] && string[front_itr]-32 != string[b-back_itr] && string[front_itr] && string[b-back_itr] - 32){

					problem = 1;

				}


			}



        }




			if(problem != 0){

				solution[i] = 1;
			}

			

		}
	

	for(int i = 0; i<num_test; i++){
		if(solution[i] != 1){

			printf("TRUE\n");
		}

		else{

			printf("FALSE\n");
		}

	}
	return 0;
}
