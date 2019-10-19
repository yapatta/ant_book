#include <bits/stdc++.h>
const int INF = 1e9+7;
const int MAX_E = 1000;
const int MAX_V = 2000;
using namespace std;

typedef struct {
	int from, to, cost;
} edge;

edge es[MAX_E];
int d[MAX_V];
int V, E;

void shortest_path(int s) {
	for(int i=0;i<V;i++) d[i] = INF;
	d[s] = 0;
	while(true) {
		bool update = false;
		for(int i=0;i<E;i++) {
			edge e = es[i];
			if(d[e.from] != INF and d[e.to] > d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
				update = true;
			}
		}
		if(!update) break;
	}
}

int main() {

}
