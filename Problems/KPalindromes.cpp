#include <bits/stdc++.h>

using namespace std;

map <string, int> words;

int distance(string a){

	if(words.count(a)){
		return words[a];
	}

	if(a.length() == 1){
		words[a] = 0;
		return 0;
	}	

	string b = a;
	words[a] = 1000000;
	reverse(b.begin(), b.end());
	
	if(b == a){

		words[a] = 0;
		return 0;	

	}	else{
			int best = 1000000;
			for(int i = 0; i < (int)a.length(); i++){
				string c = a;
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
		words[a] = distance(a);
	}

	for(int i = 0; i<num_test; i++){
		printf("%d\n", words[strings[i]]);
	}
	
	return 0;

}
