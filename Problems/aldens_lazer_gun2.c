#include <stdio.h>
#include <stdlib.h>

typedef struct z{
	int x;
	int y;
} zombie;

int main(void){
	//OFFICIALLY ACCEPTED
	//Intialisation
	int n, x0, y0;
	int number_of_shots = 0;
	scanf("%d %d %d", &n, &x0, &y0);
	zombie zombies[n];
	int seen[n];
	for(int i = 0; i<n; i++){
		seen[i] = 0;
	}	

	//Simply scanning in the zombies
	for(int i = 0; i<n; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		zombies[i].x = x; zombies[i].y = y;
	}	

	//Here's the main part, what we do is we go through the array of zombies, then, for each zombie, if it's been shot before, we ignore, if it hasn't, we add it as a shot needed, then see if any other zombies lie on the same line, and count them as being shot as well, and then update their "seen" status
	for(int i = 0; i<n; i++){
		if(seen[i]) continue;
		number_of_shots++;
		seen[i] = 1;
		int a = zombies[i].x-x0;
		int b = zombies[i].y-y0;
		for(int j = i+1; j<n; j++){
			if(seen[j]) continue;
			int c = zombies[j].x-x0;
			int d = zombies[j].y-y0;
			
			if(a*d == c*b){
				seen[j] = 1;
			}
		}
	}
	printf("%d\n", number_of_shots);
	return 0;
}
