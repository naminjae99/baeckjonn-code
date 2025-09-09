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
#include<unordered_set>
#include<string>
#include<string.h>
#include<stack>
#include<sstream>
#include<iomanip>
#include<deque>
using namespace std;
using ll = long long;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };

int n, m, t, ret, h, k;

unordered_set<int> ed[11];
int vis[11];

void dfs(int x, int dep) {
	//	cout << x << "방문\n";
	for (auto c : ed[x]) {
		if (vis[c])
			continue;
		vis[c] = 1;
		dfs(c, dep + 1);
		vis[c] = 0;
	}
	ret = max(dep, ret);
}
void input() {
	ret = 0;

	for (int i = 1; i <= 10; i++)
		ed[i].clear();

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> k;
		int a = -1; int b = -1;
		while (k--) {
			a = b;
			cin >> b;
			if (a == -1)
				continue;
			ed[a].insert(b);
			//cout << a << "," << b << "연결 \n";
		}
	}
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		vis[i] = 1;
		dfs(i, 1);
		vis[i] = 0;
		//	cout << "\n\n";
	}

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	for (int i = 1; i <= t; i++) {

		input();
		cout << "#" << i << " ";

		for (int j = 1; j <= n; j++) {
			cout << ed[j].size() << " ";
		}
		cout << ret;
		cout << "\n";
	}


}
