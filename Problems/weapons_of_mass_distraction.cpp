#include <bits/stdc++.h>

using namespace std;

typedef struct bomb_thingo{

	int x;
	int y;
	int r;

}bomb;

int main(void){

	int num_bombs;
	scanf("%d", &num_bombs);

	bool collision = false;
	bool collision_detected = false;
	
	bomb bombs[num_bombs];
		
	for(int i = 0; i<num_bombs; i++){
		int x,y,r;
		
		scanf("%d %d %d", &r, &x, &y);
		bombs[i].x = x;
		bombs[i].y = y;
		bombs[i].r = r;
	}
	
	for(int i = 0; i<num_bombs-1; i++){
		for(int j = 0; j<num_bombs-1; j++){
			if(j == i) continue;
				if(bombs[i].r+bombs[j].r >= sqrt(pow(bombs[i].x-bombs[j].x,2))+sqrt(pow(bombs[i].y-bombs[j].y,2))){
				collision_detected = true;
				break;
			} 
		}

		if(collision_detected){
			break;
		}


	}

	if(!collision_detected){
	
		for(int j = 0; j<num_bombs-1; j++){
                                if(bombs[num_bombs-1].r+bombs[j].r >= sqrt(pow(bombs[num_bombs-1].x-bombs[j].x,2))+sqrt(pow(bombs[num_bombs-1].y-bombs[j].y,2))){
                                collision = true;
                                break;
                        }
                }


	}
		

	if (collision_detected) {
		printf("safely stopped collision\n");
	}

	else if(!collision){
		printf("no collision\n");
	}	

	else{
		printf("collision\n");
	}

	return 0;

}
