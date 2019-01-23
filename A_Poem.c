#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {

	int num_encrypt, num_lines;
	char encrypt_array[26], decrypt_array[26];
	scanf("%d \n %d",&num_encrypt,&num_lines);
	char *  lines[num_lines];
	
	for(int i = 0; i<26;i++){

		encrypt_array[i] = i+65;
		decrypt_array[i] = i+65;

	}

	for(int i = 0; i<num_encrypt; i++){
		char old, new;
		while(isalpha(old = getc(stdin)) == 0);
		while(isalpha(new = getc(stdin)) == 0);
		encrypt_array[old-65] = new;
		decrypt_array[new-65] = old;

	}

	for (int j = 0; j<num_lines; j++){

		char type;
		while(isalpha(type = getc(stdin)) == 0);
		char holder[1001];
		if(type == 'D'){
			
			scanf("%s",holder);
			lines[j] = (char*)malloc((strlen(holder)+1)*sizeof(char));
			for(int l = 0; l<strlen(holder); l++){
				if(holder[l] != '_'){
					holder[l] = decrypt_array[holder[l]-65];
				}
			}

			strcpy(lines[j],holder);

		}

		else{

			scanf("%s",holder);
			lines[j] = (char*)malloc((strlen(holder)+1)*sizeof(char));
			for(int l = 0;l<strlen(holder);l++){

				if(holder[l] != '_'){
					holder[l] = encrypt_array[holder[l]-65];
					

				}


			} 

			strcpy(lines[j], holder);

		}



	


	}

	for(int k = 0; k<num_lines; k++){

		printf("%s\n",lines[k]);

	}

	return 0;

}
