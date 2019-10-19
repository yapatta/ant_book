#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e4+9;
const char *AGCT = "AGCT";
const int MAX_K = 105;
const int MAX_N = 10005;

int N, K;
string S;
int nx[MAX_K][4];
int dp[MAX_N][MAX_K];

int main() {
	cin >> N >> K >> S;

	// 初期化らしい
	for(int i=0;i<K;i++)
	{
		for(int j=0;j<4;j++)
		{
			string s = S.substr(0,i) + AGCT[j];
			while(S.substr(0, s.size()) != s)
				s = s.substr(1);
			nx[i][j] = s.size();
		}
	}

	dp[0][0] = 1;
	for(int i=1;i<K;i++) dp[0][i] = 0;

	for(int t=0;t<N;t++)
	{
		// 初期化
		for(int i=0;i<K;i++)
			dp[t+1][i] = 0;

		for(int i=0;i<K;i++)
		{
			for(int j=0;j<4;j++)
			{
				int ti = nx[i][j];
				if(ti==K) continue;
				dp[t+1][ti] = (dp[t+1][ti] + dp[t][i])%MOD;
			}
		}
	}
	int ans = 0;
	for(int i=0;i<K;i++) ans = (ans + dp[N][i])%MOD;
	cout << ans << endl;
}
