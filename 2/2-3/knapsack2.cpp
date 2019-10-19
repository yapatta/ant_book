#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 105;
const int MAX_W = 10005;

int dp[MAX_N][MAX_W];
int w[MAX_N];
int v[MAX_N];
int N,W;

// i番目以降探索済み, 重さjまで可能のときの価値の最大値
int rec(int i, int j) {
	if(dp[i][j] >= 0) {
		return dp[i][j];
	}
	int retval;
	if(i == N) {
		retval = 0;
	}else if(j < w[i]) {
		retval = rec(i+1, j);
	}else {
		retval = max(rec(i+1,j), rec(i+1, j-w[i]) + v[i]);
	}
	return dp[i][j] = retval;
}
int main() {
	cin >> N >> W;
	for(int i=0;i<N;i++)
		cin >> w[i] >> v[i];
	memset(dp, -1, sizeof(dp));
	cout << rec(0,W) << endl;
}
