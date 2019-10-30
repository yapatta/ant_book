#include <bits/stdc++.h>
using namespace std;
using ll= long long;
const int MAX_N = 505;

int dx[] = {-1, 0, 0, 1};
int dy[] = { 0, 1,-1, 0};

int W, H, N;
int X1[MAX_N],X2[MAX_N], Y1[MAX_N], Y2[MAX_N];
int fld[6*MAX_N][6*MAX_N];

void input() {
	cin >> W >> H >> N;
	for(int i=0;i<N;i++) cin >> X1[i];
	for(int i=0;i<N;i++) cin >> X2[i];
	for(int i=0;i<N;i++) cin >> Y1[i];
	for(int i=0;i<N;i++) cin >> Y2[i];
}

// 配列とWorHを与えたら、圧縮した状態を返す
int compress(int *x1, int *x2, int w) {
	vector<int> xs;
	for(int i=0;i<N;i++) {
		for(int d=-1;d<=1;d++) {
			int tx1 = x1[i] + d, tx2 = x2[i] + d;
			if(1<= tx1 && tx1 <= W) xs.push_back(tx1);
			if(1<= tx2 && tx2 <= W) xs.push_back(tx2);
		}
	}
	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());

	for(int i=0;i<N;i++) {
		x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
		x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
	}
	return xs.size();
}

void solve() {
	memset(fld, 0, sizeof(fld));

	H = compress(Y1, Y2, H);
	W = compress(X1, X2, W);

	for(int i=0;i<N;i++) {
		for(int y=Y1[i];y<=Y2[i];y++) {
			for(int x=X1[i];x<=X2[i];x++) {
				fld[y][x] = true;
			}
		}
	}

	int ans = 0;
	for(int y=0;y<H;y++) {
		for(int x=0;x<W;x++) {
			if(fld[y][x]) continue;
			ans++;
			fld[y][x] = true;
			queue<pair<int,int> > que;
			que.push(make_pair(y,x));
			while(!que.empty()) {
				int sy = que.front().first, sx = que.front().second;
				que.pop();
				for(int i=0;i<4;i++) {
					int ty = sy + dy[i], tx = sx + dx[i];
					if(fld[ty][tx] || (ty<0 || H<=ty || tx<0 || W<=tx)) continue;
					fld[ty][tx] = true;
					que.push(make_pair(ty, tx));
				}
			}

		}
	}
	cout << ans << endl;
}

int main() {
	input();
	solve();
}
