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
#include<array>
using namespace std;
using ll = unsigned long long;


int n, m, k, t;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

unordered_map < string, int>mp;
int idx;
vector<pair<int, int>>ed[205];
int st, en;
int d[205];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	for(int tc=1;;tc++){
		cin >> n >> m;
		if (!n && !m)
			break;
	
		for (int i = 0; i < n; i++)
			ed[i].clear();
		mp.clear();
		idx = 0;

		while (m--) {
			string a, b;
			int c;
			cin >> a >> b >> c;
			if (mp.find(a) == mp.end())
				mp[a] = idx++;
			if (mp.find(b) == mp.end())
				mp[b] = idx++;
			int aa = mp[a];
			int bb = mp[b];
			ed[aa].push_back({ bb,c });
			ed[bb].push_back({ aa,c });
		}
		string start, end;
		cin >> start >> end;
		st = mp[start];
		en = mp[end];

		memset(d, -1, sizeof(d));
		d[st] = 1e9;
		priority_queue < pair<int, int>>q;
		q.push({ 1e9,st });
		while (!q.empty()) {
			int now = q.top().second;
			int mn = q.top().first;
			q.pop();
			if (d[now] > mn)
				continue;
			if (now == en)
				break;
			for (auto c : ed[now]) {
				int nmn = min(mn, c.second);
				if (d[c.first] < nmn) {
					d[c.first] = nmn;
					q.push({d[c.first],c.first });
				}
			}
		}

		cout << "Scenario #" << tc << "\n";
		cout << d[en] << " tons\n\n";

	}
}
