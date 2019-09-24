#include <bits/stdc++.h>

using namespace std;

int main(void){
	
	int N;
	cin >> N;
	string a;
	cin >> a;
	
	int least_cuts = 1000000;
	
	string b(a);
	reverse(b.begin(), b.end());
	if(b.compare(a) == 0){
		printf("%d\n", N);
		return 0;
	}
	
	for(int i = 0; i<N; i++){
		bool solution_found = false;		
		int temp_least_cuts;
		for(int j = i; j<N; j++){
			string c(a);
			c.erase(i, j-i+1);
			string d(c);
			reverse(d.begin(), d.end());
			
			if(c.compare(d) == 0){
				temp_least_cuts = j-i+1;
				solution_found = true;
				break;
			}

		}
		
		if(solution_found){
			least_cuts = min(least_cuts, temp_least_cuts);
		}
	}

	printf("%d\n", N-least_cuts);
	return 0;

}
