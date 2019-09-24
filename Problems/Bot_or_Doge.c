#include <stdio.h>

int main(void) {


	static char s[100];
	scanf("%s",s);
	static int a[26];
	int n = 0;
	int i = 0; 
	
	while(i<100 && s[i] != '\0'){
		
		int j = s[i] - 'a';
		if(a[j] == 0){
			a[j] = 1;
			n++;
		}

		i++;

	}
	
	if(n%2 != 0){
		
		printf("BOT");

	}

	else{
		printf("DOGE");
	}

	return 0;

}
