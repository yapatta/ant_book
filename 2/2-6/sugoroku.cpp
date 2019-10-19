#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll extGCD(ll a, ll b, ll &x, ll &y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll bx, by;
	ll d = extGCD(b, a%b, bx, by);
	x = by, y = bx - a/b * by;
	return d;
}

int main() {
	ll a, b, x, y;
	cin >> a >> b;	
	extGCD(a,b,x,y);
	int ans[4] = {0,0,0,0};
	if(x >= 0) {
		ans[0] = x;
	}else{
		ans[1] = -x;
	}
	if(y >= 0) {
		ans[2] = y;
	}else {
		ans[3] = -y;
	}
	cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;
}
