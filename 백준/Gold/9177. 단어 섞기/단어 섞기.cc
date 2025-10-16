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

bool can;
string s1, s2, s3;
int sz1, sz2, sz3;

struct f {
	int x, y, z;
	bool operator<(const f& o)const {
		return z < o.z;
	}
};

void input() {
	cin >> t;

	for (int tr = 1; tr <= t; tr++) {
		cin >> s1 >> s2 >> s3;
		string t1, t2;
		t1 = s1 + s2;
		t2 = s3;

		sort(t1.begin(), t1.end());
		sort(t2.begin(), t2.end());
		if (t1 != t2) {
			cout << "Data set " << tr << ": " << "no\n";
			continue;
		}

		sz1 = s1.size();
		sz2 = s2.size();
		sz3 = s3.size();
		can = 0;

		priority_queue<f>q;
		q.push({0, 0, 0});
		while (!q.empty()){
			int x = q.top().x;
			int y = q.top().y;
			int z = q.top().z;
			q.pop();

			if (x == sz1 && y == sz2 && z == sz3) {
				can = 1;
				break;
			}

			if (x < sz1&&s1[x] == s3[z])
				q.push({ x + 1, y, z + 1 });
			if (y < sz2&&s2[y] == s3[z])
				q.push({ x, y + 1, z + 1 });
		}
		

		if(can)
			cout << "Data set " << tr << ": " << "yes\n";
		else
			cout << "Data set " << tr << ": " << "no\n";
	}
}
void solve() {
	
}
int main() {
	fastio;
	input();
	solve();

}




