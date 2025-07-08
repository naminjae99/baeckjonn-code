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


int t, n, m;
int k;


vector< pair<ll, int>> ed[100005];

ll d[100005];

ll mx = -1;
int mnode = -1;

void dik(int x) {
	fill(d, d + x+1, 1e18);
	priority_queue<pair<ll, int>>q;
	q.push({ 0,x });
	d[x] = 0;
	while (!q.empty()) {
		int now = q.top().second;
		ll cost = -q.top().first;
		q.pop();
		if (d[now] != cost)
			continue;
		
		//cout << now << ", " << cost << "확인 \n";

		

		for (auto c : ed[now]) {
			if (d[c.second] > c.first + cost) {
				d[c.second] = c.first + cost;
				q.push({ -d[c.second],c.second });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL),  cout.tie(0);

	cin >> n>>m>>k;

	//a-> b
	while (m--) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		ed[b].push_back({ c,a });
	}
	while (k--) {
		int x;
		cin >> x;
		ed[n + 1].push_back({ 0,x });
	}


	//n+1에서 면접장들로까지 거리는 0/
	//n+1에서 각 도시로 가는거 dik중에 가장 큰값

	
	dik(n+1);
	
	for (int i = 1; i <= n; i++) {
		if (d[i] == 1e18)
			continue;
		if (d[i] == 0)
			continue;
		if (mx < d[i]) {
			mx = d[i];
			mnode = i;
		}
	}
	cout << mnode << "\n" << mx;
}
