#include <bits/stdc++.h>
using namespace std;

// sz: ノードのサイズ
int heap[MAX_N], sz = 0;

void push(int x) {
	// 自分のノード番号
	int i = sz++;
	
	while(i > 0) {
		// 親のノード番号
		int p = (i - 1) / 2;
		// もう逆転していないなら抜ける
		if(heap[p] < x) break;
		// 親のノードの数字をおろして自分は上に
		heap[i] = heap[p];
		i = p;
	}
	heap[i] = x;
}

int pop() {
	// 最小値
	int ret = heap[0];

	// 板に持ってくる値
	int x = heap[--sz];

	// 根からおろしていく
	int i = 0;
	while(i*2+1 < sz) {
		// 子同士を比較
		int a = i*2+1, b = i*2+2;
		if(b < sz && heap[b] < heap[a]) a = b;

		// もう逆転していないなら終わり
		if(heap[a] >= x) break;

		// 子の数字を持ち上げる
		heap[i] = x;
		i = a;
	}

	heap[i] = x;
	return ret;
}
