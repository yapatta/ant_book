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
	//dp[i]: 最後がa[i]のときのLISの最大の長さ
	vector<int> dp(n);
	for(int i=0;i<n;i++) {
		dp[i] = 1;
		for(int j=0;j<i;j++) {
			if(a[j] < a[i])
				dp[i] = max(dp[i], dp[j]+1);
		}
		cout << "dp[" << i << "]=" << dp[i] << endl;
	}

	int ans = 0;
	for(int i=0;i<=n;i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}
