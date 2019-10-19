#include <bits/stdc++.h>
using namespace std;

// ax + by = gcd(a, b)
// gcd(3, 0, x, y) = 3 : x = 1, y = 0
// gcd(9, 3, x, y) = 3 : d = gcd(3, 0, y, x) => x = 0, y = 1
// gcd(21, 9, x, y) = 3: d = gcd(9, 3, y, x) => x = 1, y = -2
int extGCD(int a, int b, int &x, int &y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int bx, by;
	int d = extGCD(b, a%b, bx, by);
	x = by, y = bx - (a/b)*by;
	return d;
}
/*
 * gcd(111, 30, x, y)
 * gcd(30, 21, y, x)
 * gcd(21, 9, x ,1) =>
 * gcd(9, 3, 1, 0) => 3
 * gcd(3, 0, x, y)
 */

int main() {
	int x, y;
	extGCD(111, 30, x, y);
	cout << x << " " << y << endl;
}

/*
int extgcd(int a, int b, int x, int y) {
	// bs + rt = d
	// a = bq + r
	// x = t, y = s - qt
	// とおくと、ax + by = d になる。ここで, a > b > r
	
	// 初期状態: (gcd(a,b),0,1, 1)
	int nx = y, ny = x - a/b * y;
	extgcd( , a, nx, ny);
}
*/
