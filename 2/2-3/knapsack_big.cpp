#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 1e11;

int main() {
	ll N,W;
	cin >> N >> W;
	vector<ll> w(N),v(N);
	ll vmax = 0;
	for(ll i=0;i<N;i++) {
		cin >> w[i] >> v[i];
		vmax += v[i];
	}

	vector<vector<ll> > dp(N+1, vector<ll>(vmax+1, INF));
	dp[0][0] = 0;

	for(ll i=1;i<=N;i++) {
		for(ll j=0;j<=vmax;j++) {
			dp[i][j] = dp[i-1][j];
			if(j >= v[i-1]) {
				dp[i][j] = min(dp[i][j], dp[i-1][j-v[i-1]] + w[i-1]);
			}
		}
	}
	ll ans = 0;
	for(ll j=0;j<=vmax;j++) {
		if(dp[N][j] <= W)
			ans = j;
	}
	cout << ans << endl;
}
