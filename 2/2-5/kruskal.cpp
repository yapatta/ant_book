#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX_V 1005
#define MAX_E 1005

typedef struct {
	int u, v, cost;
} edge;

int par[MAX_V], depth[MAX_V];

edge es[MAX_E];
int V, E;

void init_union_find() {
	for(int i=0;i<V;i++) {
		par[i] = i;
		depth[i] = 0;
	}
}

int find(int x) {
	if(par[x] == x) {
		return x;
	} else {
		return par[x] = find(par[x]);
	}
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x == y) return;

	if(depth[x] < depth[y]) {
		par[x] = y;
	} else {
		par[y] = x;
		if(depth[x] == depth[y]) {
			depth[x]++;
		}
	}
}

bool same(int x, int y) {
	return find(x) == find(y);
}

bool comp(const edge& e1, edge& e2) {
	return e1.cost < e2.cost;
}

int kruskal() {
	sort(es, es + E, comp);
	init_union_find();
	int res = 0;
	for(int i=0;i<E;i++) {
		edge e = es[i];
		if(!same(e.u, e.v)) {
			unite(e.u, e.v);
			res += e.cost;
		}
	}
	return res;
}

int main() {

}
