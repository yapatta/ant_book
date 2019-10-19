#include <bits/stdc++.h>
#define MAX_N 1000005
using namespace std;
using ll = long long;

bool isPrime[MAX_N];

int eratos(int n) {
	int ans = 0;
	for(int i=1;i<=n;i++) isPrime[i] = true;
	for(int i=2;i<=n;i++) {
		if(isPrime[i]) {
			ans++;
			for(int j=2*i;j<=n;j+=i) {
				isPrime[j] = false;
			}
		}
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	cout << eratos(n) << endl;
}
