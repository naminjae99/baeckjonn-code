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
using ll = long long;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };


int n, m, t, k, ret;

unordered_map<string, int>mp;

int solution(string begin, string target, vector<string> words) {
	for (auto c : words)
		mp[c] = -1;
	mp[begin] = 0;

	queue<string> q;
	q.push(begin);

	while (!q.empty()) {
		string s = q.front();
		q.pop();
		if (s == target)
			return mp[s];
		for (int i = 0; i < s.size(); i++) {
			string tmp = s;
			for (int j = 0; j < 26; j++) {
				tmp[i] = char(j + 'a');
				if (mp.find(tmp) == mp.end())
					continue;
				if (mp[tmp] == -1) {
					mp[tmp] = mp[s] + 1;
					q.push(tmp);
				}
			}
		}
	}


	return 0;
}