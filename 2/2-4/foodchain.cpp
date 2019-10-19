#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 50005;

int par[MAX_N];		// 親
int ranker[MAX_N];	// 木の深さ

// n要素初期化
void init(int n) {
	for(int i=0;i<n;i++) {
		par[i] = i;
		ranker[i] = 0;
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

	if(ranker[x] < ranker[y]) {
		par[x] = y;
	}else {
		par[y] = x;
		if(ranker[x] == ranker[y]) ranker[x]++;
	}
}

// xとyが同じ集合に属するか
bool same(int x, int y) {
	return find(x) == find(y);
}

int main() {
	int n,k;
	cin >> n >> k;
	init(n*3);
	vector<int> T(n+5),X(n+5),Y(n+5);
	for(int i=0;i<k;i++) {
		cin >> T[i] >> X[i] >> Y[i];
	}
	int ans = 0;
	for(int i=0;i<k;i++) {
		int t = T[i];
		int x = X[i]-1, y = Y[i]-1;

		if(x<0 || n<=x || y<0 || n<=y) {
			ans++;
			continue;
		}

		if(t == 1) {
			if(same(x, y+n) || same(x, y+2*n)) {
				ans++;
			}else {
				unite(x,y);
				unite(x+n, y+n);
				unite(x+n*2, y+n*2);
			}
		}else {
			if(same(x,y) || same(x, y+2*n)) {
				ans++;
			}else {
				unite(x, y+n);
				unite(x+n, y+2*n);
				unite(x+2*n, y);
			}
		}
	}
	cout << ans << endl;
}
