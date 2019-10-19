#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N,K;
	cin >> N >> K;
	vector<int> a(N),m(N);
	vector<vector<int> > dp(N+1, vector<int>(K+5, -1));
	for(int i=0;i<N;i++)
		cin >> a[i];
	for(int i=0;i<N;i++)
		cin >> m[i];

	//初期化
	dp[0][0] = 0;
	//dp[i][j] = s (sはa[i-1]を残り何回使えるか)
	for(int i=1;i<=N;i++) {
		for(int j=0;j<=K;j++) {
			if(dp[i-1][j]>=0) dp[i][j] = m[i-1];
			else if(j-a[i-1] >= 0 and dp[i][j-a[i-1]]>=1) dp[i][j] = dp[i][j-a[i-1]] - 1;
			else dp[i][j] = -1;
		}
	}

	for(int i=0;i<=N;i++) {
		for(int j=0;j<=K;j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
	if(dp[N][K]>=0) cout << "Yes" << endl;
	else cout << "No" << endl;
}
