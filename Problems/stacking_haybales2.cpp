#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//As per meet in the middle strategems, we have two ordered lists consisting of the possible sums for each half of the given haybales, and we update these as wego
set <long long> sa;
set<long long> sb;

int main(void){
	//OFFICIALLY ACCEPTED
	//Initialisation
	int t;
	scanf("%d", &t);
	int results[t];
	for(int i = 0; i<t; i++){
		results[i] = 0;
	}
	//Iterating through the test-cases
	for(int i = 0; i<t; i++){
		//Initialisation for each test case
		sa.clear();
		sb.clear();
		int n; 
		long long h;
		scanf("%d %lld", &n, &h);
		long long heights[n];
		for(int j = 0; j<n; j++){
			scanf("%lld", &heights[j]);
		}
		//For each group, list all possible sums
		//The method we're going to use is that we keep inserting the sums of elements added to previous sums. I'm fairly confident that this will generate all possible sums for a given array of values.
		sa.insert(0);
		vector <long long> tempsa;
		for(int j = 0; j<n/2; j++) {
			for(auto x: sa){
				tempsa.push_back(x+heights[j]);
			}

			for(auto x: tempsa){
				sa.insert(x);
			}
		}

		sb.insert(0);
		vector <long long> tempsb;
		for(int j = n/2; j<n; j++){
			for(auto x: sb){
				tempsb.push_back(x+heights[j]);
			}
			
			for(auto x:tempsb){
				sb.insert(x);
			}
		}

	
		//Process all possible pairs of sums between the two groups as per meet in the middle strategy. Really, this can be done by taking the target, then subtracting a sum from one list, then checking if this is present in the other list. 
		int found = 0;
		for(auto x: sa){
			if(sb.count(h-x) >= 1){
				found = 1;
				break;
			}
		}
		if(found) results[i] = 1;
	
	}

	for(int i = 0; i<t; i++){
		if(results[i]){
			printf("YAY\n");
		} else{
			printf("NAY\n");
		}
	}

	return 0;
}
