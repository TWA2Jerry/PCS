#include <bits/stdc++.h>

using namespace std;

int main(void){

	int num_cows;
	scanf("%d", &num_cows);
	
	vector <tuple<int, int, int>> cows_vector;
	queue <int> q;
	bool visited[num_cows];
	for(int i = 0; i<num_cows; i++){
		int x,y,p;
		scanf("%d %d %d", &x, &y, &p);
		cows_vector.push_back({x,y,p}); 
		visited[i] = false;
	}


	int max_num = 0;
	
	for(int i = 0; i<num_cows; i++){
		
		q.push(i);
		visited[i] = true;
		int current_max = 1;
		while(!q.empty()){
			int a = q.front(); q.pop();
			int x1 = get<0>(cows_vector[a]);
			int y1 = get<1>(cows_vector[a]);
			int power = get<2>(cows_vector[a]);
	
			for(int j = 0; j<num_cows; j++){
				if(visited[j]) continue;
				int x2 = get<0>(cows_vector[j]);
				int y2 = get<1>(cows_vector[j]);
			
				if(pow(power, 2) >= pow(x2-x1, 2)+pow(y2-y1, 2)){
					current_max++;
					visited[j] = true;
					q.push(j);	
				}			
		
			}
			
		}

		if (current_max > max_num) max_num  = current_max;
		for(int j = 0; j<num_cows; j++){
			visited[j] = false;
		}
	}
	
	printf("%d\n", max_num);
	return 0;

}
