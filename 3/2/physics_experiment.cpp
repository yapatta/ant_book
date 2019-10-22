#include <bits/stdc++.h>
#define MAX_N 105
using namespace std;
const double GRA = 10;

int N,H,R,T;
double ans[MAX_N];

void input() {
	cin >> N >> H >> R >> T;
}

double calc(int t) {
	if(t < 0) return H;
	// √2h/g
	double tau = sqrt(2*H/GRA);
	int k = (int)(t / tau);
	// 落ちるとき 頂上に行った時間をt = 0とおく
	if(k%2 == 0) {
		// v = -gt, y = H-1/2gt^2
		return H - 1/2 * GRA * (t-k*tau)*(t-k*tau);
	} else {	// 上がるとき 地面についた点をtと置く場合
		// v = v0 - gt, y = v0t - 1/2gt^2
		return H - GRA * (k * tau + tau - t) * (k * tau + tau - t) / 2;

	}
}
void solve() {
	for(int i=0;i<N;i++) {
		ans[i] = calc(T-i);
	}
	sort(ans, ans+N);
	for(int i=0;i<N;i++) {
		printf("%lf%c", ans[i] + 2 * R * i /100.0, (i==N-1) ? '\n' : ' ');
	}
}

int main() {
	input();
	solve();
}
