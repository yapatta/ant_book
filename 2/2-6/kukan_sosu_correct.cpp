#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAX_L = 1e6+7;
const ll MAX_SQRT_B = 1e6+7;

bool is_prime[MAX_L];
bool is_prime_small[MAX_SQRT_B];

ll segment_sieve(ll a, ll b) {
	for(ll i=0;i*i<b;i++) is_prime_small[i] = true;
	for(ll i=0;i<b-a;i++) is_prime[i] = true;

	for(ll i=2;i*i<b;i++) {
		if(is_prime_small[i]) {
			for(ll j=2*i;j*j<b;j+=i) is_prime_small[j] = false;
			ll fi = (a%i==0)? a/i : a/i+1;
			for(ll j=max(i * 2LL, i * fi);j<b;j+=i) is_prime[j-a] = false;
		}
	}
	ll ans = 0;
	for(ll i=0;i<b-a;i++)
		if(is_prime[i]) {
			cout << i+a << endl;
			ans++;
		}
	return ans;
}

int main() {
	ll a, b;
	cin >> a >> b;
	cout << segment_sieve(a, b) << endl;
}
