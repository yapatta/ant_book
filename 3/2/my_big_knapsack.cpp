#include <bits/stdc++.h>
#define MAX_N 42
using namespace std;
using ll = long long;
const ll INF = 1e15;

int N;
ll W;
ll w[MAX_N], v[MAX_N];
pair<ll,ll> db[1 << (MAX_N/2)];

void input() {
	cin >> N;
	for(int i=0;i<N;i++) {
		cin >> w[i] >> v[i];
	}
	cin >> W;
}

void solve() {
	int n2 = N / 2;
	for(ll i=0;i<(1<<n2);i++) {
		ll sw = 0, sv = 0;
		for(int j=0;j<n2;j++) {
			if(i >> j & 1) {
				sw += w[j];
				sv += v[j];
			}
		}
		db[i] = make_pair(sw, sv);
	}

	sort(db, db+(1<<n2));

	ll m = 1;
	for(ll i=1;i<(1<<n2);i++) {
		if(db[m-1].second < db[i].second) {
			db[m] = db[i];
			m++;
		}
	}

	ll res = 0;

	for(ll i=0;i<(1<<(N-n2));i++) {
		ll sw = 0, sv = 0;
		for(int j=0;j<N-n2;j++) {
			if(i >> j & 1) {
				sw += w[n2+j];
				sv += v[n2+j];
			}
		}
		if(sw <= W) {
			ll tv = (lower_bound(db, db+m, make_pair(W-sw, INF))-1)->second;
			res = max(res, tv+sv);
		}
	}
	cout << res << endl;
}

int main() {
	input();
	solve();
}
