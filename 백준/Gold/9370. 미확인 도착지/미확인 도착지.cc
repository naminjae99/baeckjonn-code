#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include<iomanip>
#include<string>
#include<memory.h>
#include<array>
#include<unordered_map>
#include<algorithm>
#include<set>
#include<sstream>
using namespace std;
using ll = long long;


int n, m, t,T;
vector<pair<int, int>> e[2001];
int d[3][2001];
int s, g, h;

void dik(int st,int idx) {
	priority_queue<pair<int, int>>q;
	d[idx][st] = 0;
	q.push({ 0,st });

	while (!q.empty()) {
		int now = q.top().second;
		int cost = -q.top().first;
		q.pop();
		if (d[idx][now] != cost)
			continue;
		for (auto c : e[now]) {
			if (d[idx][c.second] > c.first+cost) {
				d[idx][c.second] = cost + c.first;
				q.push({ -d[idx][c.second],c.second });
			}
		}
	}
}
int gh;
int main() {
	cin >> T;
	while (T--) {
		cin >> n >> m >>t;
		cin >> s >> g >> h;
		vector< int> re;

		for (int i = 1; i <= n; i++) {
			e[i].clear();
			for (int j = 0; j < 3; j++)
				d[j][i] = 1e9;
		}
		int a, b, c;
		
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			if ((a == g && b == h) || (a == h && b == g))
				gh = c;
			e[a].push_back({ c,b });
			e[b].push_back({ c,a });
		}

		dik(s,0);
		dik(g, 1);
		dik(h, 2);

		for (int i = 0; i < t; i++) {
			cin >> a;
			int dir = d[0][a];
			int do1 = d[0][g] + gh + d[2][a];
			int do2 = d[0][h] + gh + d[1][a];
			if (dir >= do1 || dir >= do2)
				re.push_back(a);
		}
		sort(re.begin(), re.end());
		for (auto c : re) {
			cout <<c<<" ";
		}
		
		cout << "\n";
	}
	


}