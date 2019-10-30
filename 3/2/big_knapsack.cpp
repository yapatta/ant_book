#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e14;
const int MAX_N = 45;

int n;
ll w[MAX_N], v[MAX_N];
ll W;
pair<ll,ll> ps[1 << (MAX_N / 2)]; // 重さ, 価格

void input() {
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> w[i] >> v[i];
	}
	cin >> W;
}

void solve() {
	int n2 = n / 2;
	for(int i=0;i< 1<<n2;i++) {
		ll sw = 0, sv = 0;
		for(int j=0;j<n2;j++) {
			if(i >> j & 1) {
				sw += w[j];
				sv += v[j];
			}
		}
		ps[i] = make_pair(sw, sv);
	}

	sort(ps, ps + (1 << n2));
	int m = 1;
	// valueが上がっているときは、要素追加
	for(int i=1;i < 1<<n2;i++) {
		if(ps[m-1].second < ps[i].second) {
			ps[m++] = ps[i];
		}
	}
	for(int i=0;i<m;i++) {
		cout << ps[i].first << " " << ps[i].second << endl;
	}
	ll res = 0;
	for(int i=0;i < 1<<(n - n2);i++) {
		ll sw = 0, sv = 0;
		for(int j=0;j<n-n2;j++) {
			if(i>>j & 1) {
				sw += w[n2+j];
				sv += v[n2+j];
			}
		}
		if(sw <= W) {
			ll tv = (lower_bound(ps, ps+m, make_pair(W-sw, INF)) - 1)->second;
			cout << "sw = " << sw << endl;
			cout << "sv = " << sv << ", tv = " << tv << endl;
			res = max(res, sv + tv);
			cout << res << endl;
		}
	}
}

int main() {
	input();
	solve();
}
