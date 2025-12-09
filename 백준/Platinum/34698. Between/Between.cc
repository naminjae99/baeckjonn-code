#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include<iostream>
#include<unordered_map>
#include<set>
#include<vector>
#include<memory.h>
#include<algorithm>
#include<math.h>
#include<queue>
#include<deque>
#include<unordered_set>
#include<string>
#include<string.h>
#include<stack>
#include<sstream>
#include<iomanip>
#include<deque>
#include<array>
#include<limits.h>
#include<cfloat>
#include<map>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using ll = long long;

int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int dy[8] = { 1,1,1,0,0,-1,-1,-1 };
int n, m, ret, k, Q, L;


vector<int> ed[2005];
int dis[2005][2005];
int chk[2005];

void bfs(int st) {

	fill(dis[st], dis[st] + n + 1, 1e9);
	queue<int> q;
	q.push(st);
	dis[st][st] = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (auto c : ed[x]) {
			if (dis[st][c]!=1e9)
				continue;
			dis[st][c] = dis[st][x]+1;
			q.push( c);
		}
	}
}
void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		ed[x].push_back(y);
	}


	for (int i = 1; i <= n; i++) {
		bfs(i);
	}
	


	cin >> m;


	while (m--) {
		int st, en;
		cin >> st >> en>>k;
		for (int i = 0; i < k; i++)
			cin >> chk[i];

		//시작점과 끝점이 연결안된경우
		if (dis[st][en] == 1e9) {
			cout << "NO\n";
			continue;
		}
		int ori = dis[st][en];


		vector<pair<int, int>> path;

		bool flag = 0;
		//chk에 있는게 최단거리가 아닌경우나 끊겨있는경우
		for (int i = 0; i < k; i++) {
			int x = chk[i];
			if (dis[st][x] == 1e9 || dis[x][en] == 1e9) {
				flag = 1; 
				break;
			}
			if (dis[st][x] + dis[x][en] != ori) {
				flag = 1; 
				break;
			}
			path.push_back({ dis[st][x],x });
		}
		if (flag) {
			cout << "NO\n";
			continue;
		}

		sort(path.begin(), path.end());


		//chk에 있는애들이 하나의 경로가 아닌경우
		for (int i = 1; i < path.size(); i++) {
			int nxt = path[i].second;
			int now = path[i-1	].second;

			if (dis[now][nxt] == 1e9 || dis[st][now] + dis[now][nxt] != dis[st][nxt]) {
				flag = 1;
				break;
			}
		}
	
	
		if (flag)
			cout << "NO\n";
		else
			cout << "YES\n";


	}

}

void solve() {



}

int main() {
	fastio;
	input();
	solve();
}




