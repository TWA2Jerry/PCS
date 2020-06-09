#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(void){
	//OFFICALLY ACCEPTED
	//Intialisation
	int q;
	//Set up an array which contains the factors, if any, of each integer 
	int sieve[1000000];
	for(int i = 0; i<1000000; i++){
		sieve[i] = 0;
	}
	
	//Sieve of Eratosthenes. What we're doing is setting the at least one prime factor for each composite integer
	for(int x = 2; x<=1000000; x++){
		if(sieve[x]) continue;
		for(int u = 2*x; u<=1000000; u+= x){
			sieve[u] = x;
		}
	}

	//Scan in the number of rows of chocolate and proceed with processing each. 
	scanf("%d", &q);
	int ans[q];
	for(int i = 0; i<q; i++){
		ans[i] = 1;	
	}
	
	//What we do now is scan through each row number Ni. For each, we first find the prediscovered factor from the sieve, and then just use that factor to divide Ni. What we do is basically do the factor tree method. Each time we find a prime factor, we upload it to X structure. At the end, we then find the number of instances of each prime, then use the "number of factors" formula to find the number of factors of Ni.  

	//If the factor is 0 from the sieve, then Ni is prime, and we can just throw in   
	for(int i = 0; i<q; i++){
		int ni;
		multiset <int> factors;
		set <int> s;
		scanf("%d", &ni);
		int factor = sieve[ni];
		if(factor == 0){
			if(ni == 1){ans[i] = 1;}
			else{
				ans[i] = 2;
			}
			continue;
		} 
		while(factor != 0){
			factors.insert(factor);
			s.insert(factor);
			ni /= factor;
			factor = sieve[ni];
		}
		factors.insert(ni); /*This is because if the factor based off the last ni is 0, then ni is now a prime, and is a factor */
		s.insert(ni);
		//For each unique factor, we then note the number of occurrences, and multiply
		for (auto x : s){
			ans[i] *= (factors.count(x)+1);
		}
	}
		
	for(int i = 0; i<q; i++){
		printf("%d\n", ans[i]);
	} 
		
	return 0;
}
