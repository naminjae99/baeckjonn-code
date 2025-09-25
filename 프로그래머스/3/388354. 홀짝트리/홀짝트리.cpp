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
//mode==1 홀짝트리

int vis[1000005];
vector<int> ed[1000005];
int mode;

int dfs(int x) {
	vis[x] = 1;
	int child = 0;

	for (auto c : ed[x]) {
		if (!vis[c]) {
			if (!dfs(c)) {
				vis[x] = 0;
				return 0;
			}
			child++;
		}
	}
	vis[x] = 0;

	// 이 노드에서 홀짝 조건 체크
	if (mode == ((x % 2) == (child % 2)))
		return 1;
	return 0;
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
	for (auto &c : edges) {
		ed[c[0]].push_back(c[1]);
		ed[c[1]].push_back(c[0]);
	}

	vector<int> answer(2, 0);

	for (auto c : nodes) {
		if ((c % 2) == (ed[c].size() % 2))
			mode = 1;
		else
			mode = 0;
	
		
		if (dfs(c)) {
			if (mode == 1) answer[0]++;
			else answer[1]++;
		}
	}
	return answer;
}



