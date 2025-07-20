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
#include<map>
#include<iomanip>
#include<cfloat>
using namespace std;
using ll = long long;


int n, m,k;
vector<pair<int, int>> ed[1005];

vector < pair<int, int>> used;
struct f {
	int now, cnt;
	bool operator<(const f& o)const {
			return cnt > o.cnt;
	}
};
int d[1005];
int par[1005];

int cal() {
	priority_queue<f> q;
	q.push({ 1, 0 });
	fill(d, d + n + 1, 1e9);
	d[1] = 0;
	par[1] = 1;

	while (!q.empty()) {
		int now = q.top().now;
		int cnt = q.top().cnt;
		
		q.pop();
		if (d[now] < cnt)
			continue;
		if (now == n)
			return cnt;

		for (auto& c : ed[now]) {
			if (d[c.second] > c.first + cnt) {
				d[c.second] = cnt + c.first;
				q.push({ c.second,d[c.second] });
				par[c.second] = now;
			}
		}
	}
	return -1;
}


int dik(int x) {
	priority_queue<f> q;
	q.push({ 1, 0 });
	fill(d, d + n + 1, 1e9);
	d[1] = 0;

	while (!q.empty()) {
		int now = q.top().now;
		int cnt = q.top().cnt;

		q.pop();
		if (d[now] < cnt)
			continue;
		if (now == n)
			return cnt;

		for (auto& c : ed[now]) {

			if (now == used[x].first&&c.second == used[x].second)
				continue;
			if (d[c.second] > c.first + cnt) {
				d[c.second] = cnt + c.first;
				q.push({ c.second,d[c.second] });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		ed[a].push_back({ c,b });
		ed[b].push_back({ c,a });
	}

	int ori_dis=cal();
	if (ori_dis == 1e9) {
		cout << 0;
		return 0;
	}
	int pre = par[n];
	int cur = n;
	
	while (cur!=1) {
		used.push_back({ pre,cur });
		//cout << pre << ", " << cur << "\n";
		cur = pre;
		pre = par[pre];
	}
	int re = 0;
	bool flag = 0;

	for (int i = 0; i < used.size(); i++) {
		int tmp = dik(i);
		//cout << used[i].first << "->" << used[i].second << "안썻을떄: " << tmp << "\n";
		if (tmp == ori_dis) {
			flag = 1;
		}
		else if (tmp == -1) {
			cout << -1;
			return 0;
		}
		else {
			re = max(tmp - ori_dis, re);
		}

	}
	if (flag == 1)
		cout << 0;
	else
	cout << re;
}
