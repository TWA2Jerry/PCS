#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159265359
int main(void){


	int num_test;
	scanf("%d",&num_test);
	double * solutions = malloc(num_test*sizeof(double));
	for(int i = 0; i<num_test; i++){
		int radius, chord_length;
		scanf("%d %d",&radius,&chord_length);

		double area = PI*pow(sqrt((double)((pow(radius,2)-pow(0.5*chord_length,2)))),2);
		solutions[i] = area; 

	}	

	for(int j = 0; j<num_test; j++){

		printf("%.10lf\n",solutions[j]);

	}
		
	
	return 0;

}
