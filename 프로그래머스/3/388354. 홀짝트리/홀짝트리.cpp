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
#include<array>
#include<limits.h>
#include<cfloat>
using namespace std;

int n, idx;
bool vis[400005];
int rmp[400005];
vector<int> ed[400005];
unordered_map<int, int> mp;
int q[400005];
int fr, ba;
vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
	for (auto c : nodes) {
		rmp[idx] = c;
		mp[c] = idx++;
		
	}

	for (auto &c : edges) {
		int s = mp[c[0]];
		int e = mp[c[1]];
		ed[s].push_back(e);
		ed[e].push_back(s);
	}

	vector<int> answer(2, 0);

	for (int i = 0; i < idx; i++) {
		if (vis[i])
			continue;
		int tree[2] = { 0,0 };
		fr = ba = 0;
		q[ba++] = i;
		vis[i] = 1;
		while (fr < ba) {
			int x = q[fr++];

			for (auto c : ed[x]) {
				if (vis[c])
					continue;
				q[ba++] = c;
				vis[c] = 1;
			}
			if ((rmp[x] % 2) == (ed[x].size() % 2))
				tree[0]++;
			else
				tree[1]++;
		}
		if (tree[0] == 1)
			answer[0]++;
		if (tree[1] == 1)
			answer[1]++;
	}
	return answer;
}

