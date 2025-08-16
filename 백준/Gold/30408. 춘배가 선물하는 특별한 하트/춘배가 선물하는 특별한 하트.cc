#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
#include <string>
#include <memory.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <string.h>
#include <set>
#include <iomanip>
#include <unordered_set>
#include <map>
#include<cfloat>
#include<sstream>
#include<numeric>
#include <limits>
using namespace std;
using ll = long long;




unordered_set<ll> vis;

int fr, ba;
ll q[500];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll nn, mm;
	cin >> nn>>mm;
	
	q[ba++] = nn;
	vis.insert(nn);

	while (fr < ba) {
		ll now = q[fr++];

		if (now == mm) {
			cout << "YES";
			return 0;
		}
		if (now == 1)
			continue;

		if (now % 2 == 1) {
			if (vis.find(now / 2) == vis.end()) {
				q[ba++] = now / 2;
				vis.insert(now / 2);
			}
			if (vis.find(now / 2 + 1) == vis.end()) {
				q[ba++] = now / 2 + 1;
				vis.insert(now / 2+1);
			}
		}
		else {
			if (vis.find(now / 2) == vis.end()) {
				q[ba++] = now / 2;
				vis.insert(now / 2);
			}
		}
	}
	cout << "NO";
}


