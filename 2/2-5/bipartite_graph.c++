#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1005
int V, N;
int color[MAX_N];
vector<int> G[MAX_N];

bool dfs(int v, int c) {
	color[v] = c;
	for(int i=0;i<G[v].size();i++) {
		if(color[G[v][i]] == c) return false;
		if(color[G[v][i]] == 0 and !dfs(G[v][i], -c)) return false;
	}
	return true;
}
int main() {
	scanf("%d %d", &V, &N);
	for(int i=0;i<N;i++) {
		int a,b;
		scanf("%d %d", &a, &b);
		a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=0;i<V;i++) {
		if(color[i] == 0) {
			if(!dfs(i,1)) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
}
