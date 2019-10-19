#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int n,l,p;
	cin >> n;
	vector<pair<int,int> > ab(n);
	for(int i=0;i<n;i++) {
		int a,b;
		cin >> a >> b;
		ab[i] = make_pair(a,b);
	}
	cin >> l >> p;
	for(int i=0;i<n;i++) {
		ab[i].first = l-ab[i].first;
	}

	sort(ab.begin(),ab.end());
	priority_queue<int> pq;
	int ans = 0, gas = p, len = 0, i = 0;
	while(len < l) {
		gas--;
		len++;
		if(len == ab[i].first and i < n) {
			pq.push(ab[i].second);
			i++;
		}
		if(gas==0 and len != l) {
			if(!pq.empty()) {
				ans++;
				gas += pq.top();
				pq.pop();
			}else {
				ans = -1;
				break;
			}
		}
		//cout << len << " " << gas << endl;
	}
	cout << ans << endl;
}
