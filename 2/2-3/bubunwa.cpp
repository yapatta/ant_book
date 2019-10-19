#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N,K;
	cin >> N >> K;
	vector<int> a(N),m(N);
	vector<vector<bool> > dp(N+1, vector<bool>(K+5));
	for(int i=0;i<N;i++)
		cin >> a[i];
	for(int i=0;i<N;i++)
		cin >> m[i];

	for(int i=0;i<=N;i++)
		dp[i][0] = true;

	for(int i=1;i<=N;i++) {
		for(int j=0;j<=K;j++) {
			for(int k=0;k*a[i-1]<=j and k<=m[i-1];k++) {
				if(dp[i-1][j-k*a[i-1]])
					dp[i][j] = true;
			}
		}
	}
	for(int i=0;i<=N;i++) {
		for(int j=0;j<=K;j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
	if(dp[N][K]) cout << "Yes" << endl;
	else cout << "No" << endl;
}
