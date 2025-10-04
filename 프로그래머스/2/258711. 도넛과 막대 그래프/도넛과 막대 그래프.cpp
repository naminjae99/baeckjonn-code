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

int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };

int n, m, ret, k, t, h, w;

vector<int> ed[1000005];
vector<int> red[1000005];
unordered_set<int> s;


bool donut, stick, eight;

int vis[1000005];
void check(int x) {
	vis[x] = 1;
	
	if (ed[x].empty()) {
		stick = 1;
		return;
	}
	if (ed[x].size() > 1) {
		eight = 1;
		return;
	}


	for (auto c : ed[x]) {
		//자기 자신으로 돌아올떄
		if (vis[c]) {
			donut = 1;
			return;
		}
		check(c);
	}
}
vector<int> solution(vector<vector<int>> edges) {
	vector<int> answer;
	for (auto c : edges) {
		ed[c[0]].push_back(c[1]);
		red[c[1]].push_back(c[0]);
		s.insert(c[0]);
	}

	for (auto c : s) {
		if (ed[c].size() < 2)
			continue;
		//들어오는 간선이있으면 안됨
		if (!red[c].empty())
			continue;
		
		memset(vis, 0, sizeof(vis));

		int x,y,z;
		x=y=z=0;
		//나가는 간선들 확인
		for (auto out : ed[c]) {
			donut = stick = eight = 0;
			//나가는 간선 1개,자기자신한테 올떄 도넛 

			//나가는 간선 없거나 하나, 자기자신한테 안옴 막대

			//나가는 간선 두개거나 나머지?

		
			check(out);
			if (eight)
				z++;
			else if (stick)
				y++;
			else
				x++;
		}
		answer.push_back(c);
		answer.push_back(x);
		answer.push_back(y);
		answer.push_back(z);
		break;
	}

	
	return answer;
}
