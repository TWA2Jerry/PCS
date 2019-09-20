#include <bits/stdc++.h>

using namespace std;

int main(void){

	int N;
	cin >> N;
	string a;
	cin >> a;
	int least_cut = 1000000;
	for(int i = 0; i<N; i++){
		int temp_least_cut;
		for(int j = i; j <= N; j++){
			string c(a);
			c.erase(i, j-i);
			string d(c);
			reverse(d.begin(), d.end());
			if(d.compare(c) == 0){
				temp_least_cut = j-i;
				break;
			}
		}
			
		least_cut = min(least_cut, temp_least_cut);
	}

	printf("%d\n", N-least_cut);
	return 0;
}
