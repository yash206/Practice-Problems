#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define pb push_back

vector<pair<int, int>> graph[100000];
// Adjacency list of (neighbour, edge weight)
ll dist[100000];
int N;

void dijkstra(int src) { // Source and destination
	for (int i = 0; i < N; ++i) dist[i] = LLONG_MAX;
	// Set all distances to infinity

	using T = pair<ll,int>; priority_queue<T,vector<T>,greater<T>> pq;
	dist[src] = 0; // The shortest path from a node to itself is 0
	pq.push({0, src});

	while (pq.size()) {
		ll cdist; int node; tie(cdist, node) = pq.top(); pq.pop();
		if (cdist != dist[node]) continue;
		for (pair<int, int> i : graph[node]) {
			// If we can reach a neighbouring node faster,
			// we update its minimum distance
			if (cdist+i.second < dist[i.first]) {
				pq.push({dist[i.first] = cdist+i.second, i.first});
			}
		}
	}
}

int main() {
  int s,t;
	int M; cin >> N >> M;
  cin>>s>>t;
	for (int i = 0; i < M; ++i) {
		int a,b,c; cin >> a >> b >> c;
		graph[a-1].pb({b-1,c});
	}
	dijkstra(s-1);
  cout<<dist[t-1];
	//for (int i = 0; i < N; ++i) cout << dist[i] << " ";
}



// Shortest path between two vertices of the graph given edge weighs are positive

/*

Input:
3 4 1 2
1 2 6
1 3 2
3 2 3
1 3 4

Output:
0 5 2

*/
