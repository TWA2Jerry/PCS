#include <stdio.h>
#include <string.h>
int main(void) {

	int d;
	scanf("%d",&d);
	int a[d];
	for(int i = 0; i<d; i++){
		static char  s[100000];
		scanf("%s",s);
		int OK = 0;
		int O_found = 0;
		for(int j = 0; j<=strlen(s);j++){

			if(s[j] == 'K' && O_found != 0){

				OK = 1;

			}

			if(s[j] == 'O'){
				
				O_found  = 1;

			}

		}

		a[i] = OK;

	
	}

	for(int i = 0; i<d; i++){

		if(a[i] ==  1){
			printf("YES\n");

		}

		else{
			printf("NO\n");
		}

	}	



	return 0;

}
