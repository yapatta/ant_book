#include <bits/stdc++.h>
using namespace std;
// a > b
int gcd(int a, int b) {
	if(b==0) return a;
	return gcd(b, a%b);
}

int main() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if( (x1==x2) and (y1==y2) ) cout << 0 << endl;
	else cout << gcd(abs(x1-x2), abs(y1-y2)) - 1 << endl;
}
