#include <bits/stdc++.h>

using namespace std;

int main(void){

	int vertices;
	cin >> vertices;
	vector <pair<int, int>> adj[vertices];
	
	for(int i = 0; i<vertices-1; i++){
		int u,v,w;
		cin >> u >> v >> w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}

	
	
}
