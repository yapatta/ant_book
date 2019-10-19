#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_N = 1e4+5;

int N,K;
double L[MAX_N];

bool C(double x) {
	int num = 0;
	for(int i=0;i<N;i++) {
		num += (int)(L[i]/x);
	}
	return num >= K;
}

int main() {
	cin >> N >> K;
	for(int i=0;i<N;i++)
		cin >> L[i];
	
	sort(L, L+N);
	// 解の存在範囲
	double lb = 0, rb = L[N-1];

	//for(int i=0;i<100;i++) {
	while(fabs(lb-rb) > 0.001) {
		cout << lb << " " << rb << endl;
		double mid = (lb+rb)/2;
		if(C(mid)) lb = mid;
		else rb = mid;
	}
	cout << fixed;
	cout << setprecision(1) << rb << endl;
}
