#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int possible(int l, int r, int n, int c){

	if(n < 3 && l+r >= n){
		return 1;
	}
	
	if(c > n-1){
		return -1;
	}

	if(n > l+r){
		return -1;
	}


	bool seen[n];
	int num_different_nodes = 0;
	int a, b;
	for(int i = 0; i<n; i++){
		seen[i] = false;
	}

	for(int i = 0; i<c; i++){
		scanf("%d %d", &a, &b);
		if(!seen[a]){
			seen[a] = true;
			num_different_nodes++;
		}

		if(!seen[b]){
			seen[b] = true;
			num_different_nodes++;
		} 		
	}

	if(c > num_different_nodes-1){
		return -1;
	}
	
	if((c+1)%2 == 0){
		if(l >= (c+1)/2 && r >= (c+1)/2 && (l+r)>=n){
			return 1;
		}

		else{
			return -1;
		}	
	}

	else{
		if((l >= (c+1)/2+1 && r >= (c+1)/2 && (l+r) >= n) || (r >= (c+1)/2+1 && l >= (c+1)/2 && (l+r) >= n)){
			return 1;
		}

		else{
			return -1;
		}
	}

	

}

int main(void){

	int l, r, n,c;
	scanf("%d %d %d %d", &l, &r, &n, &c);	
	int possibility = possible(l, r, n, c);
	if(possibility != -1){
		printf("Yes\n");
	}
	
	else{
		printf("No\n");
	}

	return 0;

}
