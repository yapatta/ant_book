#include <iostream>
using namespace std;
const int INF = 5005;
const int MAX_N = 5005;

int N;
int cows[MAX_N], f[MAX_N];

// あるk(1<=k<=N)のとき, 最小の操作回数を返す(操作できなかった場合-1を返す)
/* 配列f: f[i] : [i:i+k-1]を反転させたか
 * 
 */
int calc(int k) {
	for(int i=0;i<=N;i++) f[i] = 0;
	int plus = 0, res = 0;
	for(int i=0;i<N-k+1;i++) {
		// 後ろを向いているとき
		if((cows[i]+plus)%2 == 0) {
			res++;
			plus++;
			f[i] = 1;
		}
		if(i-k+1 >= 0) {
			plus -= f[i-k+1];
		}
	}
	// 次に, N-k+2~N-1までについて
	for(int i=N-k+1;i<N;i++) {
		if((cows[i]+plus)%2 == 0) {
			return -1;
		}
		if(i-k+1 >= 0) {
			plus -= f[i-k+1];
		}
	}
	return res;
}

int main() {
	cin >> N;
	// 前処理
	for(int i=0;i<N;i++) {
		char c;
		cin >> c;
		if(c == 'F') cows[i] = 1;
		else cows[i] = 0;
	}
	
	int ans_k, cnt = INF;
	for(int k=1;k<=N;k++) {
		int tmpcnt = calc(k);
		if(tmpcnt != -1) {
			if(cnt > tmpcnt) {
				cnt = tmpcnt;
				ans_k = k;
			}
		}
	}
	cout << ans_k << " " << cnt << endl;
}
