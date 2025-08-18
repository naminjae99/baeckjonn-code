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

struct node {
	int cnt[26];
	bool operator<(const node& o)const {
		for (int i = 0; i < 26; i++) {
			if (cnt[i] != o.cnt[i])
				return cnt[i] < o.cnt[i];
		}
		return 0;
	}
};
string s1, s2;
set<node>s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s1 >> s2;


	if (s1.size() > s2.size())
		swap(s1, s2);
	int sz1 = s1.size();
	int sz2 = s2.size();
	
	node c;

	for (int sz = sz1-1; sz >= 0; sz--) {
		s.clear();
		
		for (int i = 0; i < 26; i++)
			c.cnt[i] = 0;
		for (int i = 0; i <= sz; i++)
			c.cnt[s1[i] - 'a']++;
		s.insert(c);
		for (int i = sz + 1; i < sz1; i++) {
			c.cnt[s1[i] - 'a']++;
			c.cnt[s1[i - sz - 1] - 'a']--;
			s.insert(c);
		}

		for (int i = 0; i < 26; i++)
			c.cnt[i] = 0;
		for (int i = 0; i <= sz; i++)
			c.cnt[s2[i] - 'a']++;
		if (s.count(c)) {
			cout << sz + 1;
			return 0;
		}
		for (int i = sz + 1; i < sz2; i++) {
			c.cnt[s2[i] - 'a']++;
			c.cnt[s2[i - sz - 1] - 'a']--;
			if (s.count(c)) {
				cout << sz + 1;
				return 0;
			}
		}

	}
	

	cout << 0;

}
