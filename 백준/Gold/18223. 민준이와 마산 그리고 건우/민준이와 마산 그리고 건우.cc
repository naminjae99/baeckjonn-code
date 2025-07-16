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

using namespace std;
using ll = long long;


int n, m, k, t;
int st, en;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
struct f {
	int now, cnt;
	bool operator<(const f& o)const {
		return cnt > o.cnt;
	}
};
int d[5005];
vector<pair<int, int>> ed[5005];
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	cin >> n >> m>>en;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		ed[a].push_back({ c,b });
		ed[b].push_back({ c,a });
	}
	fill(d, d + n + 1, 1e9);
	d[1] = 0;
	priority_queue<f>q;
	q.push({ 1,0 });
	while (!q.empty()) {
		int now = q.top().now;
		int cnt = q.top().cnt;
		q.pop();
		if (d[now] < cnt)
			continue;
		
		for (auto c: ed[now]) {
			
			if (d[c.second] > cnt + c.first) {
				d[c.second] = cnt + c.first;
				q.push({ c.second,d[c.second] });
			}
		}
	}
	int d1 = d[en];
	int d2 = d[n];

	fill(d, d + n + 1, 1e9);
	d[n] = 0;
	q.push({ n,0 });
	while (!q.empty()) {
		int now = q.top().now;
		int cnt = q.top().cnt;
		q.pop();
		if (d[now] < cnt)
			continue;
		if (now == en)
			break;
		for (auto c : ed[now]) {
			if (d[c.second] > cnt + c.first) {
				d[c.second] = cnt + c.first;
				q.push({ c.second,d[c.second] });
			}
		}
	}
	if(d1+d[en]==d2)
		cout << "SAVE HIM";
	else
		cout << "GOOD BYE";
}
