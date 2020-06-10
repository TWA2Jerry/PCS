#include <stdio.h>
#include <stdlib.h>
int gcd(int a, int b){return a%b == 0? b:gcd(b, a%b);}

typedef struct z{
	int x;
	int y;
} zombie;

int main(void){

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
		int absa = abs(a);
		int absb = abs(b);
		for(int j = i+1; j<n; j++){
			if(seen[j]) continue;
			int c = zombies[j].x-x0;
			int d = zombies[j].y-y0;
			int absc = abs(c);
			int absd = abs(d);
			//This is to cover the edge case of if one of the differences is 0, if it is, then no matter what, then the corresponding coordinate has to also be zero
			if(a == 0 || c== 0){
				if(a==c) seen[j] = 1;
				continue;
			}
			if(b==0 || d==0){
				if(b==d) seen[j] = 1;
				continue;
			}
			int gcdj = absa > absb? gcd(absa,absb):gcd(absb,absa);
			int gcdk = absc > absd? gcd(absc,absd):gcd(absd,absc);
			if(absa/gcdj == absc/gcdk && absb/gcdj == absd/gcdk && a/b == c/d){
				seen[j] = 1;
			}
		}
	}
	printf("%d\n", number_of_shots);
	return 0;
}
