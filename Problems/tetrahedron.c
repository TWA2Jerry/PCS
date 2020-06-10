#include<stdio.h>

int main(void){
	//OFFICIALLY ACCEPTED
	//Initialisation
	int n;
	scanf("%d", &n);
	unsigned long long vertex[4][n];

	//Now, what we do is build upwards. 
	//Note that corner D is index 3, A 0, B 1, and C 2
	//We firstly note that it is impossible to go from any point other than D to D itself in 0 moves. Therefore:
	vertex[0][0] = 0;
	vertex[1][0] = 0;
	vertex[2][0] = 0;
	vertex[3][0] = 1;
	unsigned long long modder = 1000000000+7;	
	//Now we actually do the iterating. The outermost loop iterates the steps, while inner loop iterates the corners
	for(int i = 1; i<n; i++){
		for(int j = 0; j<4; j++){
			vertex[j][i] = 0;
			for(int k = 0; k<4; k++){
				if(j == k) continue;
				vertex[j][i] += vertex[k][i-1];
				vertex[j][i] = (vertex[j][i])%modder;
			}
		}

	}
	unsigned long long answer = (vertex[0][n-1]+vertex[1][n-1]+vertex[2][n-1])%(modder);
	printf("%lli\n", answer);
	return 0;
	
}
