#include <iostream>
#define MAX_M 16
#define MAX_N 16
using namespace std;
typedef long long ll;

const int dx[5] = {-1, 0, 0, 0, 1};
const int dy[5] = { 0,-1, 0, 1, 0};

int M,N;
int tile[MAX_M][MAX_N];
int opt[MAX_M][MAX_N];	// 最適解保存用
int flip[MAX_M][MAX_N]; // 作業用

int get(int x, int y) {
	int c = tile[x][y];
	for(int d=0;d<5;d++) {
		int x2 = x + dx[d], y2 = y + dy[d];
		if(0 <= x2 && x2 < M && 0 <= y2 && y2 < N) {
			c += flip[x2][y2];
		}
	}
	return c%2;
}

int calc() {
	for(int i=1;i<M;i++) {
		for(int j=0;j<N;j++) {
			if(get(i-1, j) == 1) {
				// (i-1, j)が黒色なら, このマスをひっくり返す
				flip[i][j] = 1;
			}
		}
	}
	
	cout << endl;
	for(int i=0;i<M;i++) {
		for(int j=0;j<N;j++) {
			printf("%d%c", flip[i][j], (j==N-1) ? '\n' : ' ');
		}
	}
	cout << endl;
	
	// 最後の行がすべて白でないとき, ヒックリ返し失敗
	for(int j=0;j<N;j++) {
		if(get(M-1, j) == 1) {
			return -1;
		}
	}
	
	// ヒックリ返しがうまくいっているとき, 何回ヒックリ返したか記録
	int res = 0;
	for(int i=0;i<M;i++) {
		for(int j=0;j<N;j++) {
			res += flip[i][j];
		}
	}

	return res;
}

void solve() {
	int res = -1;

	// 1行目を辞書順に全部試す
	for(int i=0;i<(1<<N);i++) {
		memset(flip, 0, sizeof(flip));
		for(int j=0;j<N;j++) {
			flip[0][N-1-j] = (i >> j) & 1;
		}
		// calcで-1をなぜか吐く
		int num = calc();
		if(num >= 0 && (res < 0 || res > num)) {
			res = num;
			memcpy(opt, flip, sizeof(flip));
			
			cout << endl;
			for(int i=0;i<M;i++) {
				for(int j=0;j<N;j++) {
					printf("%d%c", opt[i][j], (j+1==N) ? '\n' : ' ');
				}
			}
			cout << endl;
		}
	}

	if(res < 0) {
		printf("IMPOSSIBLE\n");
	} else {
		for(int i=0;i<M;i++) {
			for(int j=0;j<N;j++) {
				printf("%d%c", opt[i][j], j+1==N ? '\n' : ' ');
			}
		}
	}
}

void input() {
	cin >> M >> N;
	for(int i=0;i<M;i++) {
		for(int j=0;j<N;j++) {
			cin >> tile[i][j];
		}
	}
}

int main() {
	input();
	solve();
}
