#include <bits/stdc++.h>
using namespace std;
using unko = long long;
const unko MAX_N = 1e6+7;

/*
 * b-a <= 1e6 に着目
 * [a, √a] におけるエラトステネスの篩を求める
 *
 */

vector<unko> prime;
bool isPrime[MAX_N];

void eratos(unko b) {
	for(unko i=2;i*i<b;i++) {
		if(isPrime[i]) {
			prime.push_back(i);
			for(unko j=2*i;j*j<b;j+=i) {
				isPrime[j] = false;
			}
		}
	}
}

int main() {
	unko a, b;
	cin >> a >> b;
	for(unko i=0;i*i<=b;i++) isPrime[i] = true;
	eratos(b);
	unko ans = 0;
	for(unko i=a;i<b;i++) {
		bool flag = true;
		for(unko j=2;j*j<=i;j++) {
			if(isPrime[j]) {
				if(i%j == 0) {
					flag = false;
				}
			}
		}
		if(flag) ans++;
	}
	cout << ans << endl;
}
