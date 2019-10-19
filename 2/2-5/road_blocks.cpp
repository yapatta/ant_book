#include <iostream>
#include <algorithm>
#include <queue>
#define MAX_N 5005
#define INF 1e9+7
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

typedef struct {
	int to, cost;
} edge;

int N, R;
vector<edge> G[MAX_N];
// first: 距離 ,second: 点
int dist[MAX_N], dist2[MAX_N];

int dijkstra() {
	priority_queue<P, vector<P>, greater<P> > pq;
	fill(dist, dist + N, INF);
	fill(dist2, dist2 + N, INF);
	dist[0] = 0, dist2[0] = 0;
	pq.push(make_pair(0,0));
	while(!pq.empty()) {
		P p = pq.top();
		pq.pop();
		int v = p.second;
		if(dist2[v] < p.first) continue;
		for(int i=0;i<G[v].size();i++) {
			edge e = G[v][i];
			int nxd = dist[v] + e.cost;
			if(dist[e.to] > nxd) {
				// nxdにe.toに行くための、現時点で二番目に近い距離を入れておく
				swap(dist[e.to], nxd);
				pq.push(make_pair(dist[e.to],e.to));
			}
			if(dist2[e.to] > nxd && dist[e.to] < nxd) {
				dist2[e.to] = nxd;
				pq.push(make_pair(dist2[e.to], e.to));
			}
		}
	}
	return dist2[N-1];
}


int main() {
	cin >> N >> R;
	for(int i=0;i<R;i++) {
		int a,b,d;
		cin >> a >> b >> d;
		a--, b--;

		edge tmp;
		tmp.to = b;
		tmp.cost = d;
		G[a].push_back(tmp);
		tmp.to = a;
		G[b].push_back(tmp);
	}
	cout << dijkstra() << endl;
}
