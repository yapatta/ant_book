#include <iostream>
#define MAX_M 16
#define MAX_N 16
using namespace std;

int dx[] = {-1, 0, 0, 0, 1};
int dy[] = {0, -1, 0, 1, 0};

int M,N;
int tile[MAX_M][MAX_N];
int flip[MAX_M][MAX_N]; // 現状の変化値
int opt[MAX_M][MAX_N]; // 決定版

void input() {
	cin >> M >> N;
	for(int i=0;i<M;i++) {
		for(int j=0;j<N;j++) {
			cin >> tile[i][j];
		}
	}
}

int get(int x, int y) {
	int c = tile[x][y];
	for(int i=0;i<5;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(0<=nx and nx<M and 0<=ny and ny<N)
			c += flip[nx][ny];
	}
	return c%2;
}

int calc() {
	for(int i=1;i<M;i++) {
		for(int j=0;j<N;j++) {
			// 一つ上が黒だった場合
			if(get(i-1, j) == 1) {
				flip[i][j] = 1;
			}
		}
	}
	int res = 0;
	for(int j=0;j<M;j++) {
		if(get(M-1, j) == 1) {
			return -1;
		}
	}
	for(int i=0;i<M;i++) {
		for(int j=0;j<N;j++) {
			res += flip[i][j];
		}
	}
	return res;
}

void solve() {
	// 一番上のNマスで, 取るか取らないかを決める
	// 次のマスを変えるか変えないかは, 上のマスを変化させられる唯一の要因であるから上のマスが黒であるなら, 次のマスを変化させる
	int res = -1;
	for(int i=0;i<(1<<N);i++) {
		memset(flip, 0, sizeof(flip));
		for(int j=0;j<N;j++) {
			flip[0][j] = (i >> j) & 1;
		}
		int num = calc();
		if(num >=0 and (num < res || res < 0)) {
			res = num;
			memcpy(opt, flip, sizeof(flip));
		}
	}
	if(res < 0) {
		cout << "IMPOSSIBLE" << endl;
	}else {
		for(int i=0;i<M;i++) {
			for(int j=0;j<N;j++) {
				printf("%d%c", opt[i][j], (j==N-1) ? '\n' : ' ');
			}
		}
	}
}


int main() {
	input();
	solve();
}
