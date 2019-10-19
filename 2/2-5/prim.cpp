#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX_V 1005
#define INF 1e9+7

int cost[MAX_V][MAX_V];
int mincost[MAX_V];
bool used[MAX_V];
int V, N;

void init() {
	for(int i=0;i<V;i++) {
		mincost[i] = INF;
		used[i] = false;
	}
}

int prim() {
	init();
	mincost[0] = 0;
	int res = 0;

	while(true) {
		int v = -1;
		for(int u=0;u<V;u++) {
			if(!used[u] && (v == -1 || mincost[u] < mincost[v]))
				v = u;
		}
		if(v == -1) break;
		used[v] = true;
		res += mincost[v];

		for(int u=0;u<V;u++) {
			mincost[u] = min(mincost[u], cost[v][u]);
		}
	}
	return res;
}

int main() {
	cin >> V >> N;
	for(int i=0;i<V;i++) {
		for(int j=0;j<V;j++) {
			cost[i][j] = INF;
		}
	}
	for(int i=0;i<N;i++) {
		int a, b, len;
		cin >> a >> b >> len;
		cost[a][b] = len;
		cost[b][a] = len;
	}
	cout << prim() << endl;
}
