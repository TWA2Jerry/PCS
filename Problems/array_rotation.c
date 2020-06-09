#include <stdio.h>
#include <stdlib.h>
int main(void){
	//OFFICIALLY ACCEPTED
	//Initialisation
	int n, k;
	scanf("%d %d", &n, &k);
	int array[n];
	for(int i = 0; i<n; i++){
		scanf("%d", &array[i]);
	}

	for(int i = 0; i<n; i++){
		if(i-k < 0){
			printf("%d ", array[(i-k+n)%n]);
		} else{
			printf("%d ", array[(i-k)%n]);
		}
		
	}
	
	return 0;
}
