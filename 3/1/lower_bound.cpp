#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i];
	
	// k以上の最小のindexを求める
	int left = -1, right = n;
	while(right-left>1) {
		int mid = (left+right) >> 1;
		if(a[mid] < k) {
			left = mid;
		}else {
			right = mid;
		}
	}

	cout << right << endl;
}
