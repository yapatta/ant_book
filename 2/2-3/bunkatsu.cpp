#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n,m,M;
	cin >> n >> m >> M;	
	vector<vector<int> > dp(m+5, vector<int>(n+5, 0));
	dp[0][0] = 1;
	
	for(int i=1;i<=m;i++) {
		for(int j=0;j<=n;j++) {
			if(j-i>=0)
				dp[i][j] = dp[i][j-i] + dp[i-1][j];
			else
				dp[i][j] = dp[i-1][j];
			dp[i][j] %= M;
		}
	}
	for(int i=0;i<=m;i++) {
		for(int j=0;j<=n;j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << dp[m][n] << endl;
}
