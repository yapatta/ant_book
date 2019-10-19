#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5+5;
const int INF = 1e5+5;

int N,S;
int A[MAX_N];
int main() {
	cin >> N >> S;
	for(int i=0;i<N;i++)
		cin >> A[i];

	int left = 0, right = 1;
	int sum = A[0];
	bool flag = false;
	int ans = INF;
	while(right <= N) {
		// cout << left << " " << right << endl;
		if(sum < S) {
			sum += A[right];
			right++;
		}else {
			ans = min(ans, right-left);
			sum -= A[left];
			left++;
		} 
	}
	cout << ((ans==INF)? 0 : ans) << endl;
}
