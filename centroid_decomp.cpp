#include <bits/stdc++.h>

using namespace std;

int N, no_edges;

int find_centroid(int u, int n, vector<int> * adj, int * sizes){

	int centroid = u, maxtree = 0, max_index = u;
	bool centroid_found = false;

	while(centroid_found == false){
		for(auto v: adj[centroid]){
			if(sizes[v] > maxtree){
				maxtree = sizes[v];
				max_index = v;
			}
		}
	
		if(maxtree <=  n/2) {
			centroid_found = true;
			continue;
		} 
		
		sizes[u] = sizes[u]-maxtree;
		sizes[max_index] = n;
		centroid = max_index;
		
	}

	return centroid;	

}

/*
int decompose(int u, vector<int> *adj, int * sizes){

	int n = sizes[u];
	int centroid = find_centroid(u, n, adj, sizes);
	seen[centroid] = true;
	return centroid;

}
*/

int main(void){

	scanf("%d %d", &N, &no_edges);
		
	int subtree_sizes[N];
	vector <int> adj[N];
	vector<int> centroid_tree[N];
	bool seen[N];
	
	int a, b;
	for(int i = 0; i<no_edges; i++){
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int centroid = find_centroid(N-1, N, adj, subtree_sizes);
	seen[centroid] = true;
	queue<int> q;
	q.push(centroid);	

	while(!q.empty()){
		int u = q.top(); q.pop();
		for(auto s : adj[u]){
			if(!seen[s]){
				subtree_centroid  = find_centroid(s, subtree_sizes[s], adj,subtree_sizes);
				q.push(subtree_centroid);
				seen[s] = true;
				//And then we need to attach this centroid onto the centroid tree
				centroid_tree[u].push_back(subtree_centroid);
				centroid_tree[subtree_centroid].push_back(u);
			}
		}	
	}

	return 0;

}
