#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

bool reverse_comp(const ll &a, const ll &b) {
	return a > b;
}
int main() {
	ll n;
	cin >> n;
	vector<ll> x(n), y(n);
	for(ll i=0;i<n;i++) cin >> x[i];
	for(ll i=0;i<n;i++) cin >> y[i];
	ll ans = 0;
	sort(x.begin(), x.end(), reverse_comp);
	sort(y.begin(), y.end());
	// reverse(x.begin(), x.end());
	for(ll i=0;i<n;i++) {
		ans += x[i]*y[i];
	}
	cout << ans << endl;
}
