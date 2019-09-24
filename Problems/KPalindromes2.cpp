#include <bits/stdc++.h>
#define INF 1000000

using namespace std;

map <string, int> words;

int distance(string a){

	if(words.count(a)){
		return words[a];
	}

	if(((int)a.length()) == 1){
		words[a] = 0;
		return 0;
	}	

	string b(a);
	words[a] = INF;
	reverse(b.begin(), b.end());
	
	if(b.compare(a) == 0){

		words[a] = 0;
		return words[a];	

	}	else{
			int best = INF;
			for(int i = 0; i < (int)a.length(); i++){
				string c(a);
				c.erase(c.begin()+i);
						
				best = min(best, distance(c)+1);
				
			}
		
			words[a] = best;
			return words[a];

		}	

	
}

int main(void){

	int num_test;
	scanf("%d", &num_test);
	
	vector<string> strings;
	
	
	for(int i = 0; i<num_test; i++){
		string a;
		cin >> a;
		strings.push_back(a);
		int best = distance(a);
		words[a] = best;
	}

	for(int i = 0; i<num_test; i++){
		printf("%d\n", words[strings[i]]);
	}
	
	return 0;

}
