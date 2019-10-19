#include <bits/stdc++.h>
#define MAX_N 65005
using namespace std;
using ll = long long;

bool isprime(ll n) {
	bool flag = true;
	for(ll i=2;i*i<=n;i++) {
		if(n%i==0)
			flag = false;
	}
	return flag;
}

map<tuple<ll,ll,ll>, ll> mp;

ll powmod(ll x, ll n, ll mod) {
	if(mp.count(make_tuple(x,n,mod))) {
		return mp[make_tuple(x,n,mod)];
	} 
	if(n==1) return  mp[make_tuple(x,n,mod)] = x;
	else if(n==0) return mp[make_tuple(x,n,mod)] = 1;
	
	if(n%2==0) return mp[make_tuple(x,n,mod)] = powmod(x, n/2, mod) * powmod(x, n/2, mod) % mod;
	else return mp[make_tuple(x,n,mod)] = x * powmod(x, n-1, mod) % mod;
}

int main(void) {
	ll n;
	cin >> n;
	if(isprime(n)) {
		cout << "No" << endl;
		return 0;
	}
	for(ll x=2;x<n;x++) {
		if(x == powmod(x, n, n)) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
