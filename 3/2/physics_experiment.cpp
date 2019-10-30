#include <bits/stdc++.h>
#define MAX_N 105
using namespace std;
const double GRA = 10;

int N,H,R,T;
double ans[MAX_N];

void input() {
	cin >> N >> H >> R >> T;
}

double calc(double height,int t) {
	if(t < 0) return height;
	// √2h/g
	double tau = sqrt(2*height/GRA);
	cout << "tau: " << tau << endl;
	int k = (int)(t / tau);
	cout << "k: " << k << endl;
	// 落ちるとき 頂上に行った時間をt = 0とおく
	if(k%2 == 0) {
		double d = t-k*tau;
		return height - GRA * d * d / 2;
	} else {	// 上がるとき 地面についた点をtと置く場合
		double d = tau*(k+1) - t;
		return height - GRA * d * d / 2;
	}
}

void solve() {
	for(int i=0;i<N;i++) {
		double h = H + 2 * R * i / 100.0;
		ans[i] = calc(h,T-i);
		//cout << ans[i] << " ";
	}
	//cout << endl;
	sort(ans, ans+N);
	for(int i=0;i<N;i++) {
		printf("%lf%c", ans[i], (i==N-1) ? '\n' : ' ');
	}
}

int main() {
	input();
	solve();
}
