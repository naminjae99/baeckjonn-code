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
int n,m, ret, t, k, Q, L;

int dx[9] = {-1,0,1,0};
int dy[9] = { 0,-1,0,1 };

char arr[51][51];
int vis[51][51];


void input() {
	cin >> n >> m ;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j]=s[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j])
				continue;
			ret++;
			vis[i][j] = 1;

			if (arr[i][j] == '-') {
				int ny = j + 1;
				while (1) {
					if (ny>=m)
						break;
					if (arr[i][ny] == '-') {
						vis[i][ny] = 1;
						ny++;
					}
					else
						break;
				}
			}
			else {
				int nx = i + 1;
				while (1) {
					if (nx >= n)
						break;
					if (arr[nx][j] == '|') {
						vis[nx][j] = 1;
						nx++;
					}
					else
						break;
				}
			}
		}
	}
	cout << ret;
}



void run() {


}


int main() {
	fastio
		input();
	run();

}
