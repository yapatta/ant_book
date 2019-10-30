#include <iostream>
#include <algorithm>
#define MAX_N 4005
using namespace std;
typedef long long ll;
int A[4][MAX_N];
int B[2][MAX_N*MAX_N];
int N;

void input() {
	cin >> N;
	for(int j=0;j<N;j++) {
		for(int i=0;i<4;i++) {
			cin >> A[i][j];
		}
	}
}

ll lower_binary(int* a, int n, int key) {
	int left = -1, right = n;
	while(right-left > 1) {
		int mid = (left + right) / 2;
		if(a[mid] >= key) right = mid;
		else left = mid;
	}
	return right;
}

ll upper_binary(int* a, int n, int key) {
	int left = -1, right = n;
	while(right-left > 1) {
		int mid = (left + right) / 2;
		if(a[mid] > key) right = mid;
		else left = mid;
	}
	return right;
}

void solve() {
	ll ans = 0;
	int cntA = 0;
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			B[0][cntA++] = A[0][i] + A[1][j];
		}
	}
	int cntB = 0;
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			B[1][cntB++] = A[2][i] + A[3][j];
		}
	}
	sort(B[0], B[0]+cntA);
	sort(B[1], B[1]+cntB);
	for(int i=0;i<cntA;i++) {
		int tmp = 0 - B[0][i];
		int num = upper_binary(B[1], cntB, tmp) - lower_binary(B[1], cntB, tmp);
		if(num >= 0) {
			ans += num;
		}
	}
	cout << ans << endl;
}

int main() {
	input();
	solve();
}
