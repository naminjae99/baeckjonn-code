#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, h;
int arr[32][12];

//hXn
int cnt = 4;

int check() {



	for (int i = 1; i <= n; i++) {
		int tmp = i;

		for (int j = 1; j <=h; j++) {
			if (arr[j][tmp] == 1)
				tmp++;
			else if (tmp>1&&arr[j][tmp - 1] == 1)
				tmp--;
		}
		if (tmp != i)
			return 0;
	}
	return 1;
}

void f(int x,int dep) {
	if (dep >= cnt) {
		return;
	}

	if (check() == 1) {
		cnt = dep;
	}

	for (int i = x; i <= h; i++) {
		for (int j = 1; j <n; j++) {
			if (arr[i][j] || arr[i][j - 1] || arr[i][j + 1])
				continue;
		
			arr[i][j] = 1;
			f(i, dep + 1);
			arr[i][j] = 0;

		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> h;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}

	f(1, 0);
	
	if (cnt > 3)
		cout << -1;
	else
		cout << cnt;
	return 0;

	

	
}