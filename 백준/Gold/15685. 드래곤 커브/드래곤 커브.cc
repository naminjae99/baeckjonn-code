#include <iostream>
#include <deque>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int arr[102][102];
int n, x, y, d, g;




int dy[4]={0,-1,0,1};
int dx[4] = { 1,0,-1,0 };

int ex;
int ey;
int result;





int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	

	while (n--) {
		cin >> x >> y >> d >> g;

		arr[y][x] = 1;

	
		vector <int> q;

		q.push_back({ d });
		y += dy[d];
		x += dx[d];
		arr[y][x] = 1;

		while (g--) {
			int s = q.size();
			for (int j = s-1; j >=0; j--) {
				int nd = (q[j] + 1) % 4;
				q.push_back(nd);
				
				y += dy[nd];
				x += dx[nd];
				arr[y][x] = 1;

			}

		}


	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (arr[i][j] == 1) {
				if (arr[i][j + 1] == 1 && arr[i + 1][j + 1] == 1 && arr[i + 1][j] == 1)
					result++;
			}
		}
	}

	
	

	cout << result;
}