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
using ll = long long;


int n, m, k, t;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


struct f {
	int x, y, cost;
	
};
struct ff {
	string s;
	int cost;
	bool operator<(const ff& o)const {
		if(cost!=o.cost)
			return cost > o.cost;
		return s > o.s;
	}
};
f ed[11];
vector<char> re;
unordered_map<string, int> mp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	
	string s;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		x--;
		char xx = char(x) - '0';
		s += xx;
		re.push_back(xx);
	}
	sort(re.begin(), re.end());
	string ret="";
	for (auto c : re)
		ret += c;

	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		ed[i] = { a-1,b-1,c };
	}


	
	priority_queue<ff>q;
	q.push({ s,0 });
	mp[s] = 0;

	while (!q.empty()) {
		string x = q.top().s;
		int cnt = q.top().cost;
		q.pop();
		
		if (mp[x] < cnt)
			continue;

		if (x == ret) {
			cout << cnt;
			return 0;
		}

		for (int i = 0; i < m; i++) {
			string nx = x;
			/*
			char a = x[ed[i].x];
			nx[ed[i].x] = nx[ed[i].y];
			nx[ed[i].y] = a;
			*/
			swap(nx[ed[i].x], nx[ed[i].y]);
			
			if (mp.find(nx) == mp.end()) {
				mp[nx] = cnt + ed[i].cost;
				q.push({ nx,mp[nx] });
			}
			else {
				if (mp[nx] > cnt + ed[i].cost) {
					mp[nx] = cnt + ed[i].cost;
					q.push({ nx,mp[nx] });
				}
			}
		
		}
	}
	cout << -1;
}
