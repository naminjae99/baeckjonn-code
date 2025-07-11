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
using namespace std;
using ll = long long;


int n, m, k;



//남은 시작지점,크기
set<pair<int, int>> other;

//변수 -> 시작지점,크기
unordered_map<string, pair<int,int>>mp;

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	cin >> n;

	other.insert({ 1,100000 });
	while (n--) {
		string s;
		cin >> s;

		if (s[5] == 'm') {
			string val= s.substr(0,4);
			string x= s.substr(12, s.size() - 13);
			int xx = stoi(x);
			
			bool flag = 0;
			for (auto it = other.begin(); it != other.end();it++) {
				if (it->second >=  xx) {
					mp[val] = { it->first,xx };

					if(it->second-xx>0)
						other.insert({ it->first + xx,it->second - xx });
					other.erase(it);
					flag = 1;
					break;
				}
			}
			if (flag == 0)
				mp[val] = { 0,0 };

		}
		else if (s[0] == 'f') {
			s = s.substr(5, 4);
			if (mp[s].first == 0)
				continue;

			int sidx = mp[s].first;
			int cnt = mp[s].second;

			auto nxt = other.lower_bound({sidx,0});

			if (nxt != other.begin()) {
				auto pre = prev(nxt);
				if (pre->first + pre->second == sidx) {
					sidx = pre->first;
					cnt += pre->second;
					other.erase(pre);
				}
			}

			if (nxt != other.end()) {
				if (sidx + cnt == nxt->first) {
					cnt+= nxt->second;
					other.erase(nxt);
				}
			}
			other.insert({ sidx,cnt });
			mp[s] = {0,0};
			
			
		}
		else {
			s = s.substr(6, 4);
			cout << mp[s].first<<"\n";
		}
	}
} 