#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <memory.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int m, k, n;
int arr[155][155];

// 큐에 cost를 같이 들고 다니도록 수정
struct f {
	int x, y, state, cost;
};
pair<int, int> st;

// [주의] 홀수/짝수 차원([2]) 추가!!
int vis[155][155][3][2];

bool out(int x, int y) {
	return x < 0 || x >= n || y < 0 || y >= m;
}

void input() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				st = { i, j };
			}
		}
	}
	set<pair<int, int>> s;
	memset(vis, -1, sizeof(vis));
	queue<f> q;
	
	// 시작점: 비용 0, 짝수(0) 방문 처리
	q.push({ st.first, st.second, 0, 0 });
	vis[st.first][st.second][0][0] = 0;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int state = q.front().state;
		int cost = q.front().cost;
		q.pop();

		// 정답 판별
		if (cost <= k) {
			if (state == 0 && (k - cost) % 2 == 0) {
				s.insert({ x, y });
			}
		}
		
		if (cost >= k) continue; // k번 움직였으면 더 뻗어나갈 필요 없음

		int ncost = cost + 1;
		int npar = ncost % 2; // 다음 방문의 홀짝성

		if (state == 0) {
			int nx = x - 1;
			int nnx = x - 2;
			if (!out(nnx, y) && arr[nx][y] != 0 && arr[nnx][y] != 0 && vis[nx][y][1][npar] == -1) {
				vis[nx][y][1][npar] = ncost;
				q.push({ nx, y, 1, ncost });
			}
			nx = x + 2;
			nnx = x + 1;
			if (!out(nnx, y) && arr[nx][y] != 0 && arr[nnx][y] != 0 && vis[nx][y][1][npar] == -1) {
				vis[nx][y][1][npar] = ncost;
				q.push({ nx, y, 1, ncost });
			}

			int ny = y + 1;
			int nny = y + 2;
			if (!out(x, nny) && arr[x][ny] != 0 && arr[x][nny] != 0 && vis[x][ny][2][npar] == -1) {
				vis[x][ny][2][npar] = ncost;
				q.push({ x, ny, 2, ncost });
			}
			ny = y - 2;
			nny = y - 1;
			if (!out(x, nny) && arr[x][ny] != 0 && arr[x][nny] != 0 && vis[x][ny][2][npar] == -1) {
				vis[x][ny][2][npar] = ncost;
				q.push({ x, ny, 2, ncost });
			}
		}
		else if (state == 1) {
			// 위로 굴릴 때 -> x - 2 에 세워짐
			int nx = x - 2;
			if (!out(nx, y) && arr[nx][y] != 0 && vis[nx][y][0][npar] == -1) {
				vis[nx][y][0][npar] = ncost;
				q.push({ nx, y, 0, ncost });
			}
			
			// 아래로 굴릴 때 -> x + 1 에 세워짐 (버그 수정됨!)
			nx = x + 1;
			if (!out(nx, y) && arr[nx][y] != 0 && vis[nx][y][0][npar] == -1) {
				vis[nx][y][0][npar] = ncost;
				q.push({ nx, y, 0, ncost });
			}

			// 우로 굴릴 때
			nx = x - 1;
			int ny = y + 1;
			if (!out(nx, ny) && arr[x][ny] != 0 && arr[nx][ny] != 0 && vis[x][ny][1][npar] == -1) {
				vis[x][ny][1][npar] = ncost;
				q.push({ x, ny, 1, ncost });
			}
			
			// 좌로 굴릴 때
			ny = y - 1;
			if (!out(nx, ny) && arr[x][ny] != 0 && arr[nx][ny] != 0 && vis[x][ny][1][npar] == -1) {
				vis[x][ny][1][npar] = ncost;
				q.push({ x, ny, 1, ncost });
			}
		}
		else {
			// 좌로 굴릴 때 -> y - 1 에 세워짐
			int ny = y - 1;
			if (!out(x, ny) && arr[x][ny] != 0 && vis[x][ny][0][npar] == -1) {
				vis[x][ny][0][npar] = ncost;
				q.push({ x, ny, 0, ncost });
			}
			
			// 우로 굴릴 때 -> y + 2 에 세워짐
			ny = y + 2;
			if (!out(x, ny) && arr[x][ny] != 0 && vis[x][ny][0][npar] == -1) {
				vis[x][ny][0][npar] = ncost;
				q.push({ x, ny, 0, ncost });
			}

			// 위로 굴릴 때
			int nx = x - 1;
			ny = y + 1;
			if (!out(nx, ny) && arr[nx][ny] != 0 && arr[nx][y] != 0 && vis[nx][y][2][npar] == -1) {
				vis[nx][y][2][npar] = ncost;
				q.push({ nx, y, 2, ncost });
			}
			
			// 아래로 굴릴 때
			nx = x + 1;
			if (!out(nx, ny) && arr[nx][ny] != 0 && arr[nx][y] != 0 && vis[nx][y][2][npar] == -1) {
				vis[nx][y][2][npar] = ncost;
				q.push({ nx, y, 2, ncost });
			}
		}
	}
	 s.erase(st); // 시작점도 가능한 위치 중 하나입니다!
	cout << s.size();
}

int main() {
	fastio;
	input();
}