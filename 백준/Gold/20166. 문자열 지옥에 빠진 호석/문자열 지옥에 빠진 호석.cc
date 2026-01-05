#include<iostream>
#include <unordered_set>
#include <unordered_map>
#include<queue>
#include<string>
using namespace std;

int n, m,k;
char arr[11][11];
int dx[8] = { -1,-1,-1,0,1,1,1,0 };
int dy[8] = { -1,0,1,1,1,0,-1,-1 };



unordered_map<string, int> v;

void bfs(int x, int y, int dep, string s) {
	if (dep == 5)
		return;
	v[s]++;
	for (int dir = 0; dir < 8; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx == n + 1)
			nx = 1;
		if (nx == 0)
			nx = n;
		if (ny == m + 1)
			ny = 1;
		if (ny == 0)
			ny = m;
		bfs(nx, ny, dep + 1, s + arr[nx][ny]);
	}
}
int main() {
	ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	cin >> n >> m>>k;
	for (int i = 1; i <= n; i++) {
		string x;
		cin >>x;
		for (int j = 0; j < m; j++) {
			arr[i][j+1] = x[j];
		}
	}
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= m; b++) {
			bfs(a, b, 0, string(1,arr[a][b]));
		}
	}


	for (int i = 0; i < k; i++) {
		string x;
		cin >> x;
		cout << v[x] << "\n";
	}



	
	
}