#include <iostream>
using namespace std;
const int MAX_N = 5005;

int N;
string S;
int dir[MAX_N];
int f[MAX_N];

int calc(int K) {
	for(int i=0;i<S.size();i++) {
		if(S[i]=='F') dir[i] = 1;
		else dir[i] = 0;
	}

	memset(f, 0, sizeof(f));
	int res = 0, sum = 0;
	for(int i=0;i+K<=N;i++) {
		// 区間[i, i+K-1]に着目
		if()
	}

}

int main() {
	cin >> N >> S;
}
