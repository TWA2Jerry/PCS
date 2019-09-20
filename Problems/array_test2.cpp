#include <bits/stdc++.h>

using namespace std;

void change_array(int * a){
	
	a[0] = 5;
	
}

int main(void){
	int sizes[5];
	for(int i = 0; i<5; i++){
		sizes[i] = i;
	}

	change_array(sizes);
	printf("%d\n", sizes[0]);
	
}
