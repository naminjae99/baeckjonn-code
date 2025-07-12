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
using namespace std;
using ll = long long;

int n, m, k, t;

int en,st;
vector<pair<int,int>> ed[10005];
int d[10005];

struct f {
	int now, mx;
	bool operator<(const f& o)const {
		return mx < o.mx;
	}
};
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	cin >> n>>m;
	while (m--) {
		int a, b,c;
		cin >> a >> b>>c;
		ed[a].push_back({b,c});
		ed[b].push_back({ a,c });
	}

	cin >> st >> en;

	fill(d, d + n + 1, 0);
	priority_queue<f> q;
	q.push({ st,(int)1e9});
	d[st] = 1e9;
	//st는 제한이 무한

	while (!q.empty()) {
		int now = q.top().now;
		int bod = q.top().mx;
		q.pop();

		//cout << now << "를 " << bod << "제한으로 이동\n";
		if (d[now] >bod)
			continue;
		if (now == en) {
			cout << bod;
			break;
		}
		for (auto c : ed[now]) {
			if (d[c.first]<min(bod,c.second)) {
				d[c.first] = min(bod,c.second);
				q.push({c.first,d[c.first] });
				//cout << c.first << ", " << d[c.first] << "추가\n";
			}
		}
	}
	
}
