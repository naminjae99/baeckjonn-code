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


int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };

int n, m, ret, t, k;
char arr[55][55];
int d[255][255];
struct f {
	int x, y, z;
	bool operator<(const f& o)const {
		return z > o.z;
	}
};
priority_queue<f>q;
void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j];
			d[i][j] = 1e9;
			if (s[j] == 'S') {
				q.push({ i,j,0 });
				d[i][j] = 0;
			}
		}
	}
	
	int cnt = 0;

	while (!q.empty()) {
		int x = q.top().x;
		int y = q.top().y;
		int z = q.top().z;
		q.pop();
		if (d[x][y] != z)
			continue;

		if (arr[x][y] == 'K') {
			cnt++;
			ret += z;
			z = 0;
			d[x][y] = 0;
		}

		if(cnt==m)
			break;
		for (int j = 0; j < 4; j++) {
			int nx = x + dx[j];
			int ny = y + dy[j];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (arr[nx][ny] == '1')
				continue;
			if (d[nx][ny] > z + 1) {
				d[nx][ny] = z + 1;
				q.push({ nx,ny,z+1 });
			}
		}
	}
	if (cnt != m)
		ret = -1;
	cout << ret;
}



int main() {
	fastio
		input();
	
}