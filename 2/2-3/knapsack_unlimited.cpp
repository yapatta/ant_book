#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N,W;
	cin >> N >> W;
	vector<int> w(N),v(N);
	for(int i=0;i<N;i++)
		cin >> w[i] >> v[i];

	vector<vector<int> > dp(N+1, vector<int>(W+5, 0));
	for(int i=0;i<W+5;i++) {
		dp[0][i] = 0;
	}

	for(int i=1;i<=N;i++) {
		for(int j=0;j<W+5;j++) {
			//何も加えなかったとき
			dp[i][j] = dp[i-1][j];
			if(j >= w[i-1])
				dp[i][j] = max(dp[i][j], dp[i][j-w[i-1]] + v[i-1]);
		}
	}
	for(int i=0;i<=N;i++) {
		for(int j=0;j<=W;j++) {
			cout << "dp[" << i << "][" << j << "]=" << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << dp[N][W] << endl;
}
