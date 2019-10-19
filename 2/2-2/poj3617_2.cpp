#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	string a,ans="";
	for(int i=0;i<n;i++)
		cin >> a[i];

	int l = 0, r = n-1;
	while(l <= r) {
		bool left = false;
		for(int i=0;l+i<=r-i;i++) {
			if(a[l+i] < a[r-i]) {
				left = true;
				break;
			}else if(a[l+i] > a[r-i]) {
				left = false;
				break;
			}
		}
		if(left) ans += a[l++];
		else ans += a[r--];
	}
	for(int i=0;i<n;i++) {
		if(i%80==0 and i!=0) cout << endl;
		cout << ans[i];
	}
}
