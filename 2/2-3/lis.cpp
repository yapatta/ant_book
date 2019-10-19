#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i];
	//dp[i]: 長さi+1の増加部分列の最後の数(小さければ小さいほどいい)
	vector<int> dp(n+1,INF);
	for(int i=0;i<n;i++) {
		*lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
		/*
		for(int j=0;j<=i;j++) {
			if(a[i]<=dp[j]) {
				dp[j] = a[i];
				break;
			}
		}
		*/
	}

	int ans = 0;
	for(int i=0;i<=n;i++) {
		if(dp[i] == INF) {
			ans = i;
			break;
		}
	}
	cout << ans << endl;
}
