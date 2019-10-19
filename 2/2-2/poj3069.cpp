#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main() {
	int n,r;
	while(cin >> r >> n) {
		if(r==-1 and n==-1) break;
		vector<int> x(n);
		for(int i=0;i<n;i++)
			cin >> x[i];
		sort(x.begin(),x.end());
		int i = 0,ans = 0;
		while(i < n) {
			int s = x[i++];
			while(i < n and x[i]-s <= r) i++;
			int p = x[i-1];
			while(i < n and x[i]-p <= r) i++;
			ans++;
		}
		cout << ans << endl;
	}
}
