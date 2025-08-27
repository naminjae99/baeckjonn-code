#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int arr[101][101];
int vis[101][101];
vector<pair<int,int>> sw[101][101];
int n, m;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int result=1;

void bfs(int stx,int sty){
	vis[stx][sty] = 1;
	queue <pair<int, int>> q;
	q.push({ stx,sty });

	while (!q.empty()) {
		int flag = 0;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (arr[x][y] != 2) {
			int si = sw[x][y].size();
			for (int i = 0; i < si; i++) {
				int a = sw[x][y][i].first;
				int b = sw[x][y][i].second;
				//불이 아직 안켜진경우만 키고 re++;
				if (arr[a][b] == 0) {
					arr[a][b] = 1;
					result++;
					flag = 1;
				}
			}
			//2이면 불이켜져있고 불켜기가 완료되있음
			arr[x][y] = 2;
		}
		//불을 켰을경우 그시점에서 다시시작
		//즉 그 좌표만 vis1주고 나머지초기화
		//큐도 초기화
		if (flag == 1) {
			memset(vis, 0, sizeof(vis));
			vis[x][y] = 1;
			while (!q.empty())
				q.pop();
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx <= 0 || nx > n || ny <= 0 || ny > n)
				continue;
			if (vis[nx][ny] == 1)
				continue;
			if (arr[nx][ny] == 0)
				continue;
			vis[nx][ny] = 1;
			q.push({ nx,ny });
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		sw[x][y].push_back({ a, b });
	}
	arr[1][1] = 1;
	
	bfs(1, 1);

	cout << result;

}