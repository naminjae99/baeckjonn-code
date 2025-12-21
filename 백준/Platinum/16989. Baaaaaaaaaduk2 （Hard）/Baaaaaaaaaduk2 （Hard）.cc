#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int n, m;
int arr[1005][1005];
bool vis[1005][1005];

bool outbound(int x, int y) {
	return (x < 0 || x >= n || y < 0 || y >= m);
}

/*
 mp1 : 자유도 1개짜리 그룹
 mp2 : 자유도 2개짜리 그룹
*/
map<pair<int, int>, int> mp1;
map<pair<pair<int, int>, pair<int, int>>, int> mp2;

void bfs(int sx, int sy) {
	queue<pair<int, int>> q;
	q.push({ sx, sy });
	vis[sx][sy] = true;

	vector<pair<int, int>> libs;
	int cnt = 0;

	while (!q.empty()) {
		auto[x, y] = q.front(); q.pop();
		cnt++;

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (outbound(nx, ny)) continue;
			if (vis[nx][ny])continue;
			if (arr[nx][ny] == 2) {
				vis[nx][ny] = true;
				q.push({ nx, ny });
			}
			else if (arr[nx][ny] == 0) {
				vis[nx][ny] = true;
				libs.push_back({ nx, ny });
			}
		}
	}

	// 자유도 중복 제거
	sort(libs.begin(), libs.end());
	libs.erase(unique(libs.begin(), libs.end()), libs.end());
	for (auto c : libs) {
		vis[c.first][c.second] = 0;
	}
	if (libs.size() == 1) {
		mp1[libs[0]] += cnt;
	}
	else if (libs.size() == 2) {
		pair<int, int> p1 = libs[0];
		pair<int, int> p2 = libs[1];
		if (p2 < p1) swap(p1, p2);
		mp2[{p1, p2}] += cnt;
	}
}

int main() {
	fastio

		cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	// 상대 돌(2) 그룹 BFS
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j] && arr[i][j] == 2) {
				bfs(i, j);
			}
		}
	}

	int ret = 0;

	// 자유도 2개 그룹 + 자유도 1개 그룹 조합
	for (auto &c : mp2) {
		auto p1 = c.first.first;
		auto p2 = c.first.second;
		int sum = c.second;
		sum += mp1[p1];
		sum += mp1[p2];
		ret = max(ret, sum);
	}

	// 자유도 1개 그룹 중 2개 선택
	vector<int> v;
	for (auto &c : mp1) v.push_back(c.second);
	sort(v.begin(), v.end());

	int s = 0;
	for (int i = (int)v.size() - 1; i >= max(0, (int)v.size() - 2); i--) {
		s += v[i];
	}
	ret = max(ret, s);

	cout << ret;
	return 0;
}
