#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;
	string a;
	for(int i=0;i<N;i++)
		cin >> a[i];
	string ans = "";
	int l = 0, r = N-1;
	while(l <= r) {
		if(a[l] < a[r]) {
			ans += a[l];
			l++;
		}else if(a[l] > a[r]) {
			ans += a[r];
			r--;
		}else {
			if(l==r) {
				ans += a[l];
				break;
			}
			int tl = l, tr = r;
			while(1) {
				if(a[tl] < a[tr]) {
					ans += a[l];
					l++;
					break;
				}else if(a[tl] > a[tr]) {
					ans += a[r];
					r--;
					break;
				}else {
					if(tl+1==tr or tl==tr+1 or tl==tr) {
						if(a[tl]==a[tr]) {
							ans += a[l];
							l++;
							break;
						}
					}
					tl++;
					tr--;
				}
			}
		}
	}
	for(int i=0;i<ans.size();i++) {
		if(i%80==0) cout << endl;
		cout << ans[i];
	}
}
