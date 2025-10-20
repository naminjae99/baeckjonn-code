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

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m, ret, k, t, Q;

multiset<int> v;
vector<int> solution(vector<string> operations) {
	for (auto c : operations) {
		char cmd = c[0];
		int x;
		if (cmd == 'I') {
			x = stoi(c.substr(2));
			v.insert(x);
	
		}
		else {
			x = stoi(c.substr(2));
			if (x == 1) {
				if (v.empty())
					continue;
				auto it = v.end();
				it--;
		
				v.erase(it);
				
			}
			else {
				if (v.empty())
					continue;
				auto it = v.begin();
			
				v.erase(it);
			}
		}
	}
	vector<int> answer;
	if (v.empty()) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else {
		auto it = v.end();
		it--;
		answer.push_back(*it);
		answer.push_back(*v.begin());
	}
	return answer;
}
