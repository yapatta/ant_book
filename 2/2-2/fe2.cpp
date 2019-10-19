#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;
const int INF = 1e9;
int N;

int main() {
	ll ans = 0;
	priority_queue<int> pq;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		int tmp;
		cin >> tmp;
		pq.push(-tmp);
	}

	//板が一本になるまで適用
	while(!pq.empty() and N > 1) {
		int m1 = pq.top();
		pq.pop();
		int m2 = pq.top();
		pq.pop();
		//併合
		int t = -(m1 + m2);
		ans += t;
		pq.push(-t);
		N--;
	}
	cout << ans << endl;
}
