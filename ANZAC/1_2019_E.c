#include <stdio.h>
#include <math.h>

int min(int a, int b){

	if(a < b){
		return a;
	}

	else{
		return b;
	}
}

int num_messages(int n, int t){

	if(n <= 4){
		return -1;
	}

	int num_char_remaining = t;
	int decimal_iterator = 0;
	int num_messages = 1000000000;
	int max_char;
	
	if((n-2)%2 == 0){
		max_char = (n-2)/2;
	}

	else{
		max_char = (n-2)/2 + 1;
	}
		
	
	
	for(int current_max = 1; current_max <= max_char; current_max++){
		decimal_iterator = 0;
		int current_num_messages = 0;
		num_char_remaining = t;
		while(num_char_remaining != 0 && decimal_iterator+1 <= current_max){
			
			int num_char_possible = n-(3+current_max+decimal_iterator);
			if(num_char_possible <= 0){
				if(num_messages == 1000000000 || num_messages == -1){

					num_messages = -1;
					break;

				}
			}	

			int num_characters = 9*((int)pow(10,decimal_iterator))*(num_char_possible);
			if(num_characters >= num_char_remaining){
			
				if(num_char_remaining%(num_char_possible) != 0){
					current_num_messages += num_char_remaining/(num_char_possible) + 1;
					num_messages = min(current_num_messages, num_messages);
					break;
				}	

				else{
					current_num_messages += num_char_remaining/(num_char_possible);	
					num_messages = min(current_num_messages, num_messages);
					break;
				}

			}

			num_char_remaining -= num_characters;
			current_num_messages += 9*((int)pow(10, decimal_iterator));
			decimal_iterator++;

		}
	}

	return num_messages;

}

int main(void){

	int n, t;
	scanf("%d %d", &n, &t);
	printf("%d\n", num_messages(n,t));
	return 0;

}
