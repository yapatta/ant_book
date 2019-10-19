#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 1e9;
int N;
vector<int> l;

void solve() {
	ll ans = 0;
	
	//板が一本になるまで適用
	while(N > 1) {
		//一番短い板: m1, 次に短い板: m2
		int m1 = 0, m2 = 1;
		if(l[m1] > l[m2]) swap(m1,m2);

		for(int i=2;i<N;i++) {
			if(l[i] < l[m1]) {
				m2 = m1;
				m1 = i;
			}else if(l[i] < l[m2]) {
				m2 = i;
			}
		}

		//併合
		int t = l[m1] + l[m2];
		ans += t;

		if(m1 == N-1) swap(m1,m2);
		l[m1] = t;
		l[m2] = l[N-1];
		N--;
	}
	cout << ans << endl;
}

int main() {
	cin >> N;
	l = vector<int>(N);
	for(int i=0;i<N;i++)
		cin >> l[i];
	solve();
}
