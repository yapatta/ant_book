#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e4+5;
const int MAX_C = 1e4+5;
const int ST_SIZE = (1 << 15) -1;

int N, C;
int L[MAX_N], S[MAX_C], A[MAX_C];

// セグ木のデータ
double vx[ST_SIZE], vy[ST_SIZE]; // 各節点のベクトル
double abg[ST_SIZE]; // 各節点の角度

// 角度の変化を調べるため、現在の角度を保存する
double prv[MAX_N];

// セグ木を初期化
// k: 節点の番号, l, rはその節点が[l,r)に対応づいていることを表す
void init(int k, int l, int r) {
	ang[k] = vx[k] = 0.0;
	if(r-l == 1) {
		vy[k] = L[l];
	} else {
		int chl = k*2+1, chr = k*2+2;
		init(chl, l, (l+r)/2);
		init(chr, (l+r)/2, r);
		vy[k] = vy[chl] + vy[chr];
	}
}

void input() {
	cin >> N >> C;
	for(int i=0;i<N;i++) cin >> L[i];
	for(int i=0;i<C;i++) cin >> S[i];
	for(int i=0;i<C;i++) cin >> A[i];
}

int main() {

}
