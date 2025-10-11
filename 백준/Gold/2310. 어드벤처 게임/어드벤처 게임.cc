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
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using ll = long long;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m, ret, k, t, Q;

struct f {
	char room;
	int cost;
	vector<int> cango;
}info[1005];

//n번방을 m 비용을 가진채 방문
int vis[1005][505];

int qx[100005];
int qy[100005];
int fr, ba;

void solve() {
	memset(vis, 0, sizeof(vis));
	fr = ba = 0;

	vis[1][0] = 1;
	qx[ba] = 1, qy[ba++] = 0;


	while (fr<ba) {
		int x = qx[fr];
		int cost = qy[fr++];
		


		if (info[x].room == 'L') {
			if (cost < info[x].cost) {
				cost = info[x].cost;
			}
		}
		else if (info[x].room == 'T') {
			if (info[x].cost <= cost) {
				cost -= info[x].cost;
			}
			else
				continue;
		}

		//	cout << x << ", " << cost << "\n\n";



		if (x == n) {
			cout << "Yes\n";
			return;
		}

		for (auto c : info[x].cango) {
			if (c == x)
				continue;
			if (vis[c][cost] == 0) {
				qx[ba] = c;
				qy[ba++] = cost;
				vis[c][cost] = 1;
			}
		}
	}
	cout << "No\n";
}

void input() {
	while (1) {
		cin >> n;
		if (n == 0)
			break;

		char room;
		int cost;
		for (int i = 1; i <= n; i++) {
			cin >> room >> cost;
			info[i].room = room;
			info[i].cost = cost;
			info[i].cango.clear();

			int x;
			while (1) {
				cin >> x;
				if (x == 0)
					break;
				info[i].cango.push_back(x);
			}
		}

		solve();
	}

}

int main() {
	fastio;
	input();


}