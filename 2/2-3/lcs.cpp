#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int S_MAX = 1005;
const int T_MAX = 1005;

int N,M;
string s,t;
int dp[S_MAX][T_MAX];

int main() {
	cin >> N >> M;
	cin >> s >> t;
	for(int j=0;j<=M;j++)
		dp[N][j] = 0;
	for(int i=0;i<=N;i++)
		dp[i][M] = 0;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			if(s[i-1]==t[j-1]) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
			}
		}
	}
	cout << dp[N][M] << endl;
}
