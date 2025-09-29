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
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using ll = long long;

int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };

string find(ll x) {
	ll tmp = 26;
	while (1) {
		if (x - tmp >= 0) {
			x -= tmp;
			tmp *= 26;
		}
		else
			break;
	}



	ll block = tmp / 26;

	string s = "";
	while (block) {
		s += (x / block + 'a');
		x = x % block;
		block /= 26;
	}

	return s;

}
ll refind(string s) {
	ll re = 0;
	ll tmp = 1;
	for (int i = s.size() - 1; i >= 0; i--) {
		re += (s[i] - 'a' + 1)*tmp;
		tmp *= 26;
	}
	return re - 1;
}
string solution(long long n, vector<string> bans) {
	n--;
	string s = find(n);
	vector<ll>tmp;
	
	for (auto c : bans) {
		tmp.push_back(refind(c));
	}
	sort(tmp.begin(), tmp.end());
	for (auto c : tmp) {
		if (c <= n)
			n++;
		else
			break;
	}
	return find(n);
}