#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_N = 1 << 17;

int n, dat[2 * MAX_N -1];

void init(int n_) {
	// 要素数の2のべき乗
	n = 1;
	while(n < n_) n *= 2;

	// すべての値をINT_MAXに
	for(int i=0;i<2*n-1;i++) dat[i] = INT_MAX;
}

// k番目の値を(0-index)をaに変更
void update(int k, int a) {
	k += n-1;
	dat[k] = a;

	// 登りながら更新
	while(k > 0) {
		k = (k-1) / 2;
		dat[k] = min(dat[k*2+1], dat[k*2+2]);
	}
}

// [a,b)の最小値を求める
// k: 節点の番号, l,rはその節点が[l,r)に対応づいていることを表す
int query(int a, int b, int k, int l, int r) {
	// [a,b) と[l,r)が交差していなければ, INT_MAX
	if(r <= a || b <= l) return INT_MAX;

	// [a,b)が[l,r)を完全に含んでいたらこの節点の値を返す
	if(a <= l && r <= b) return dat[k];
	else {
		// そうでなければ２つの個の最小値
		int vl = query(a, b, k*2+1, l, (l+r)/2);
		int vr = query(a, b, k*2+2, (l+r)/2, r);
		return min(vl, vr);
	}
}

void input() {
	int n_;
	cin >> n_;
	init(n_);
	for(int i=0;i<n_;i++) {
		int tmp;
		cin >> tmp;
		update(i, tmp);
	}
}

void solve() {
	int a,b;
	while(cin >> a >> b) {
		if(a == -1) break;
		cout << query(a, b, 0, 0, n) << endl;
	}
}

int main() {
	input();
	solve();
}
