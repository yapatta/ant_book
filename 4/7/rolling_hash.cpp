#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

// ハッシュの基数
const ull KEY = 1e8+7;


// aがbに含まれているか?(a⊂b)
bool contain(string a, string b) {
	int al = a.size(), bl = b.size();
	if(al > bl) return false;

	// Bのal乗
	ull t = 1;
	for(int i=0;i<al;i++)
		t *= KEY;

	// aとbの最初のal文字に関するハッシュ値を計算
	ull ah = 0, bh = 0;
	for(int i=0;i<al;i++) {
		ah = ah * KEY + (a[i]-'a');
		bh = bh * KEY + (b[i]-'a');
	}

	// bの場所を1つずつ薦めながらハッシュ値をチェック
	for(int i=0;i+al<=bl;i++) {
		if(ah == bh) return true;
		if(i + al < bl) bh = bh * KEY - (b[i]-'a')*t + b[i+al];
	}
	return false;
}
