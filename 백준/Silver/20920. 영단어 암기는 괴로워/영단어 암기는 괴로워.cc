#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <math.h>
#include <queue>
#include <unordered_set>
#include <string>
#include <string.h>
#include<iomanip>
#include<limits>
#include<cfloat>
using namespace std;
using ll = long long;
using ld = long double;
int t, Q, n, p, m;

int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };


unordered_map<string, int>mp;
int cnt[100005];
string rmp[100005];
int idx;
vector<int> v;
struct cmp{	
	bool operator()(const int& a, int& b)const {
		if (cnt[a] != cnt[b])
			return cnt[a] > cnt[b];
		if (rmp[a].length() != rmp[b].length())
			return rmp[a].length() > rmp[b].length();
		return rmp[a] < rmp[b];
	}
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n>>m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s.size() < m)
			continue;
		if (mp.find(s) == mp.end()) {
			mp[s] = idx;
			rmp[idx] = s;
			v.push_back(idx++);
		}
		cnt[mp[s]]++;
	}
	sort(v.begin(), v.end(), cmp());
	for (auto c : v) {
		cout << rmp[c] << "\n";
	}
}