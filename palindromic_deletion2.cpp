#include <bits/stdc++.h>

using namespace std;

int main(void){
	
	int N;
	cin >> N;
	string a;
	cin >> a;
	
	int least_cuts;
	
	for(int i = 0; i<N; i++){
		bool solution_found = false;		

		for(int j = 1; j<N-i+1; j++){
			string c(a);
			c.erase(i, j);
			string d(c);
			reverse(d.begin(), d.end());
			
			if(c.compare(d) == 0){
				solution_found = true;
				least_cuts = j;
				break;
			}

		}
		
		if(solution_found){
			break;
		}
	}

	printf("%d\n", N-least_cuts);
		
	return 0;

}
