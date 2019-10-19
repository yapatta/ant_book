#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX_N = 1e5+5;

int N,M;
ll X[MAX_N];

// 最も近い牛たちの距離をx, 他の距離をx以上としたとき、条件を満たす場合true, 満たさない場合falseを返す
bool C(int x) {
	int key = X[0]+x;
	for(int i=0;i<M-1;i++) {
		// key以上の値の中の最小値を求める
		int left = -1, right = N;
		while(right - left > 1) {
			int mid = (left+right) >> 1;
			if(key <= X[mid]) {
				right = mid;
			}else {
				left = mid;
			}
		}
		if(right==N) return false;
		key = X[right]+x;
	}
	return true;
}

int main() {
	cin >> N >> M;
	for(int i=0;i<N;i++)
		cin >> X[i];

	sort(X, X+N);
	int left = -1, right = X[N-1] - X[0]+1;
	while(right - left > 1) {
		//cout << left << " " << right << endl;
		int mid = (left+right) >> 1;
		if(C(mid)) left = mid;
		else right = mid;
	}
	cout << left << endl;
}
