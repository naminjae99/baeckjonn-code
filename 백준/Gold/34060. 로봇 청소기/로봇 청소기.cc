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
#include<map>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using ll = long long;


ll dx[4] = {-1, 1, 0, 0};
ll dy[4] = { 0,0,-1,1 };

int m, ret, t, k, Q, n;
ll yset[200005];
ll xset[200005];

unordered_set<ll> xy;
unordered_set<ll>vis;
ll mx = 1e9;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> yset[i];


	//x가 같을때  최소
	//x=0 
	xy.insert(yset[0]);
	xset[0] = 0;

	for (int i = 1; i < n; i++) {
		if (yset[i - 1] >= yset[i]) {
			xset[i] = xset[i - 1] + 1;
			xy.insert(xset[i] * mx + yset[i]);
		}
		else {
			xset[i] = xset[i - 1];
			xy.insert(xset[i] * mx + yset[i]);
		}
	}

	queue<ll>q;

	for (int i = 0; i < n; i++) {
		if (vis.find(xset[i] * mx + yset[i]) != vis.end())
			continue;
		ret++;
		q.push(xset[i] * mx + yset[i]);
		vis.insert(xset[i] * mx + yset[i]);

		while (!q.empty()) {
			ll cur = q.front();
			q.pop();
			ll x = cur / mx;
			ll y = cur % mx;

			for (int i = 0; i < 4; i++) {
				ll nx = x + dx[i];
				ll ny = y + dy[i];
				if (nx < 0 || nx >= 1e9 || ny<1 || ny>1e9)
					continue;
				if (xy.find(nx*mx + ny) == xy.end())
					continue;
				if (vis.find(nx*mx + ny) != vis.end())
					continue;
				vis.insert(nx*mx + ny);
				q.push(nx*mx + ny);
			}
		}
	}
	cout << ret << "\n";

	cout << n;


}



int main() {
	fastio
		input();

}