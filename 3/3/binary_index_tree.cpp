#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e9+7;

int bit[MAX_N+1], n;

int sum(int i) {
	int s = 0;
	while(i > 0) {
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add(int i, int x) {
	while(i <= n) {
		bit[i] += x;
		i += i & -i;
	}
}

int sumAtoB(int a, int b) {
	if(a==1) return sum(b);
	return sum(b) - sum(a-1);
}

void input() {
	cin >> n;
	for(int i=1;i<=n;i++) {
		int tmp;
		cin >> tmp;
		add(i,tmp);
	}
}

void solve() {
	int a, b;
	while(cin >> a >> b) {
		if(a == -1) break;
		cout << sumAtoB(a, b) << endl;
	}
}

int main() {
	input();
	solve();
}
