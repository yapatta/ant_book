#include <bits/stdc++.h>
using namespace std;

int par[MAX_N];		// 親
int rank[MAX_N];	// 木の深さ

// n要素初期化
void init(int n) {
	for(int i=0;i<n;i++) {
		par[i] = i;
		rank[i] = 0;
	}
}

// 木の根を求める
int find(int x) {
	if(par[x] == x) {
		return x;
	}else {
		return par[x] = find(par[x]);
	}
}

// xとyの属する集合を併合
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x == y) return;

	if(rank[x] < rank[y]) {
		par[x] = y;
	}else {
		par[y] = x;
		if(rank[x] == rank[y]) rank[x]++;
	}
}

// xとyが同じ集合に属するか
bool same(int x, int y) {
	return find(x) == find(y);
}
