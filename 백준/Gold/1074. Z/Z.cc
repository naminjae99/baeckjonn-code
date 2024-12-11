#include <iostream>

using namespace std;

int n,r,c;

int z(int n ,int x, int y) {
	if (n == 0)
		return 0;
	int half = 1 << (n - 1);

	if (x < half && y < half) {
		return z(n - 1, x, y);
	}
	if (x < half && y >= half) {
		return half*half+z(n - 1, x, y-half);
	}
	if (x >= half && y < half) {
		return half * half*2 + z(n - 1, x-half, y);
	}
	if (x >= half && y >= half) {
		return half * half*3 + z(n - 1, x-half, y-half);
	}
}
int main() {
	cin >> n >> r >> c;
	cout << z(n, r, c);




}