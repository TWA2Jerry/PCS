#include <bits/stdc++.h>

using namespace std;

int N, no_edges;

void dfs(int s, int e, vector<int> * adj, int * sizes){

	
	sizes[s] = 1;
	for(auto u : adj[s]){
		if (u != e) {
			dfs(u, s, adj, sizes);
			sizes[s] += sizes[u];
		}
	}
	
	return;

}

int find_centroid(int u, int n, vector<int> * adj, int * sizes, bool * seen){
	
	while(1){
		int maxtreesize = 0, direction;
		for(auto v: adj[u]){
			if(seen[v]) {
				continue;
			}
			if(sizes[v] > maxtreesize){
				maxtreesize = sizes[v];
				direction = v;
			}
		}
			
		if(maxtreesize <= n/2){
			break;
		} else{
			sizes[u] -= maxtreesize;
			sizes[direction] = n;
			u = direction;
		}
	}
	return u;	

}


int main(void){

	scanf("%d %d", &N, &no_edges);
		
	int subtree_sizes[N];
	vector <int> adj[N];
	vector<int> centroid_tree[N];
	bool seen[N];

	for(int i = 0; i<N; i++){
		seen[i] = false;
		subtree_sizes[i] = 0;
	}
	
	int a, b;
	for(int i = 0; i<N-1; i++){
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(N-1, -1, adj, subtree_sizes);	
	
	int centroid = find_centroid(N-1, N, adj, subtree_sizes, seen);
	seen[centroid] = true;
	queue<int> q;
	q.push(centroid);	

	while(!q.empty()){
		int u = q.front(); q.pop();
		for(auto s : adj[u]){
			if(!seen[s]){
				int subtree_centroid  = find_centroid(s, subtree_sizes[s], adj,subtree_sizes, seen);
				q.push(subtree_centroid);
				seen[subtree_centroid] = true;
				//And then we need to attach this centroid onto the centroid tree
				centroid_tree[u].push_back(subtree_centroid);
				centroid_tree[subtree_centroid].push_back(u);
			}
		}
	}
	

	printf("All done\n");
	return 0;

}
