#include <stdio.h>
#define INF 10000000

int min(int a, int b){

	return (a < b)? a:b;

}

int solver(double target, double capacity, int iteration, int upper_iteration){

	if (target < capacity || target < 0.0){
		return INF;
	} else if (target == capacity){
		return iteration+1;
	} else if (iteration == upper_iteration){
		return INF;
	} else if(3*capacity/4 < 1){
			int current_solution = solver(target-capacity, 1, iteration+1, upper_iteration);
			if (current_solution < INF) {
				return current_solution;
			}
			
			return  solver(target, 2*capacity, iteration+1, upper_iteration);
	} else{
			int current_solution = solver(target-capacity, 3*capacity/4, iteration+1, upper_iteration);
			if(current_solution < INF){
				return current_solution;
			}
			return solver(target, 2*capacity, iteration+1, upper_iteration);
	}
	

}

int main(void){

	float x, y;
	scanf("%f %f", &x, &y);	
	int i = 1, solution = INF;
	while(i < 100){
		
		solution = solver(x,y,0, i);
		if(solution < INF){
			break;
		}
		 
		i++;
		
	}
	
	if(solution != INF){
	printf("The solution is %d\n", solution);
	} else{
		printf("No solution exists\n");
	}
	return 0;
}
