#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = 1e5+5;
int N,S;
int A[MAX_N], sum[MAX_N];

int main() {
	int NN,ii=0;
	cin >> NN;
	while(ii < NN) {
		for(int i=0;i<=MAX_N;i++) {
			A[I] = 0; 
			sum[i] = 0;
		}
		cin >> N >> S;
		for(int i=0;i<N;i++) cin >> A[i];
		for(int i=0;i<N;i++)
			sum[i+1] = sum[i] + A[i];

		if(sum[N] < S) {
			cout << 0 << endl;
			return 0;
		}

		int ans = N;
		for(int left=0;S <= sum[N] - sum[left];left++) {
			int right = lower_bound(sum+left, sum+N, S+sum[left]) - sum;
			ans = min(ans, right-left);
		}
		cout << ans << endl;
		ii++;
	}
}
