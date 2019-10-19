#include <bits/stdc++.h>
using namespace std;
const int INF = 1e7;
const int MAX_N = 1e4+5;
const int MAX_K = 1e4+5;

// C(x) := 単位重さあたりの価値がx以上になるよう選ぶことができるか
int w[MAX_N], v[MAX_N];
double wv[MAX_N];
int N,K;

bool C(double x) {
	double sum = 0;
	for(int i=0;i<N;i++) {
		wv[i] = v[i] - x*w[i];
	}
	sort(wv, wv+N);
	// 大きい順からk個取る
	for(int i=0;i<K;i++) {
		sum += wv[N-1-i];
	}
	cout << sum << endl;
	return sum >= 0;
}

int main() {
	cin >> N >> K;
	for(int i=0;i<N;i++)
		cin >> w[i] >> v[i];

	double left = 0,right = INF;
	while(right-left > 0.001) {
		cout << left << " " << right << endl;
		double mid = (left+right) / 2;
		if(C(mid)) left = mid;
		else right = mid;
	}
	cout << fixed;
	cout << setprecision(2) << left << endl;
}
