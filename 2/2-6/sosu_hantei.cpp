#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool sosu(ll n) {
	if(n == 2) return true;
	for(ll i=3;i*i<=n;i++) {
		if(n%i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	ll n;
	cin >> n;
	if(sosu(n)) cout << "Yes" << endl;
	else cout << "No" << endl;
}
