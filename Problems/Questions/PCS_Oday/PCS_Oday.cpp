#include <bits/stdc++.h>

using namespace std;

int main(void){

	int n,c, m;
	scanf("%d %d %d", &n, &c, &m);

	vector <pair<int, int>> adj[n];
	priority_queue<pair<int,int>> q;
	bool processed[n];
	int distance[n];
	int required[m];
	
	for(int i = 0; i<n; i++){
		distance[i] = 1000000000;
		processed[i] = false;
	}

	int a, b, w;
	for(int i = 0; i<c; i++){
		scanf("%d %d %d",&a, &b, &w);
		adj[a].push_back({b, w});
		adj[b].push_back({a, w}); 
	}

	for(int i = 0; i<m; i++){
		scanf("%d", &required[i]);
	}


	int current_node = required[0];
	int iteration = 0;
	int total_distance = 0;	


	while(iteration != m-1){

		distance[current_node] = 0;
		q.push({current_node, 0});

		while(!q.empty()){

			int a = q.top().first; q.pop();
			if(processed[a]){
				continue;
			}

			processed[a] = true;

			for(auto u : adj[a]){
				
				int end_node = u.first, w = u.second;
				if(distance[a]+w < distance[end_node]){
					distance[end_node] = distance[a]+w;
					q.push({end_node, -w});
				}

			}


		}



		
		iteration++;
		current_node = required[iteration];
		total_distance += distance[required[iteration]];
		
		for(int i = 0; i<n; i++){
			distance[i] = 1000000000;
			processed[i] = false;
		}

	}

	printf("%d\n", total_distance);
			
	return 0;
}
