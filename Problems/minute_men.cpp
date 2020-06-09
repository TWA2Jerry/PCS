#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main(void){
	//OFFICIALLY ACCEPTED
	//Initialisation
	string minutes;
	int n, longest_word_length = 0;
	getline(cin, minutes);
	vector <string> strings; 	
	scanf("%d", &n);

	//Scanning each clever word, then checking if it exists in the minutes
	for(int i = 0; i<n; i++){
		char clever_word[1001];	
		int found = 0;
		scanf("%s", clever_word);
		int word_length = strlen(clever_word);
		if(word_length < longest_word_length) continue;	
		for(int j = 0; j<(int)(strlen(minutes.c_str())-1-word_length+2); j++){
			for (int k = 0; k<word_length; k++){
				if(minutes[k+j] != clever_word[k] && minutes[k+j] != clever_word[k]-32){
					break;
				}

				if(k == word_length-1){
					found = 1;
					break;
				}
			}
			if(found){
				//Compare the length of the clever word to previously longest clever word, and add it to the words to be printed if it is of greater or equal length. Then break the whole for loop 
				if(word_length > longest_word_length){
					//Clear everything out, add only this, update longest_word_length
					strings.clear();
					strings.push_back(clever_word);
					longest_word_length = word_length;
					
					
				} else if(word_length == longest_word_length){
					//Just add the word, but don't delete the others
					strings.push_back(clever_word);
				}
			
				break;
			}
		}
	}
	
	for (auto x: strings){
		printf("%s\n", x.c_str());
	}
	return 0;

}
