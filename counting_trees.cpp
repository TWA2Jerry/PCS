#include <bits/stdc++.h>

using namespace std;

int T, N, M;

typedef struct trees{
	int x;
	int y;
} tree;


int gcd (int a, int b){return a%b == 0? b: gcd(b, a%b);} 

int main(void){

	scanf("%d", &T);
	int results[T];

	for(int i = 0; i<T; i++){
		//Setting up the garden, we create an array of tree structures which have x and y coordinates		
		scanf("%d %d", &N, &M);
		tree garden[N];
		bool seen[N];
		int count = 0;

		for(int j = 0; j<N; j++){
			seen[j] = false;
		}

		int x, y;
		for(int j = 0; j<N; j++){
			scanf("%d %d", &x, &y);
			garden[j].x = x;
			garden[j].y = y; 
		}

		//Loop through each tree, n^2 algorithm, we just check to see if any other tree has the same gradient, if so, don't check it cause it can't be seen
		for(int j = 0; j<N; j++){
			if(seen[j]){
				continue;
			}

			count++;

			for(int k = 0; k<N; k++){
				if(seen[k] || k==j){
					continue;
				}

				int a,b,c,d;
				a = garden[j].x; b = garden[j].y; c = garden[k].x; d = garden[k].y;
				int gcdj;
				int gcdk;
				if(a > b){
					gcdj = gcd(a,b);
				} else{
					gcdj = gcd(b,a);
				}

				if(c > d){
					gcdk = gcd(c,d);
				} else{
					gcdk = gcd(d,c);
				}

				a = a/gcdj; b = b/gcdj;
				c = c/gcdk; d = d/gcdk;

				if(a == c && b==d){
					seen[k] = true;
				}	

			}			

		}

		results[i] = count;
	
	}
		
	for(int i = 0; i<T; i++){
		printf("%d\n", results[i]);
	}
	return 0;
}
