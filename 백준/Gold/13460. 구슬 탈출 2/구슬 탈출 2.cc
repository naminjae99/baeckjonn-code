#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
#include <string>
#include <memory.h>
#include <vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
#include<string.h>
#include<set>
#include<iomanip>
#include<unordered_set>

using namespace std;
int n, t, m, k;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };



int arr[10][10];
pair<int, int> r, b;

void input() {
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '#')
				arr[i][j] = -1;
			else if (s[j] == 'R') {
				r = { i,j };
				arr[i][j] = 1;
			}
			else if (s[j] == 'B') {
				b = { i,j };
				arr[i][j] = 2;
			}
			else if (s[j] == 'O')
				arr[i][j] = 3;
		}
	}
}

int ord[10];
int ret = -1;


void cal(int dep) {

	int copy[10][10];
	memcpy(copy, arr, sizeof(arr));

	pair<int, int> cr, cb;
	cr = r;
	cb = b;

	int fx, fy;

	

	for (int mv = 0; mv < dep; mv++) {

		

		if (ord[mv] == 0) {
			//cb가 먼저
			if (cr.first < cb.first) {
				fx = cb.first;
				for (int i = cb.first+1; i < n; i++) {
					if (copy[i][cb.second] == -1) {
						fx = i - 1;
						break;
					}
					if (copy[i][cb.second] == 3)
						return;
				}
			

				copy[cb.first][cb.second] = 0;
				copy[fx][cb.second] = 2;
				cb.first = fx;


				fx = cr.first;
				for (int i = cr.first; i < n; i++) {
					if (copy[i][cr.second] == -1 || copy[i][cr.second] == 2) {
						fx = i - 1;
						break;
					}
					if (copy[i][cr.second] == 3) {
						ret = mv + 1;
						return;
					}
				}
				copy[cr.first][cr.second] = 0;
				copy[fx][cr.second] = 1;
				cr.first = fx;
			}

			else {
				bool flag = 0;

				fx = cr.first;
				for (int i = cr.first; i < n; i++) {
					if (copy[i][cr.second] == -1) {
						fx = i - 1;
						break;
					}
					if (copy[i][cr.second] == 3) {
						flag = 1;
						break;
					}
				}
				copy[cr.first][cr.second] = 0;
				cr.first = fx;
				if (flag == 0) 
					copy[fx][cr.second] = 1;
				
			
				fx = cb.first;
				for (int i = cb.first; i < n; i++) {
					if (copy[i][cb.second] == -1 || copy[i][cb.second] == 1) {
						fx = i - 1;
						break;
					}
					if (copy[i][cb.second] == 3)
						return;
				}
				copy[cb.first][cb.second] = 0;
				copy[fx][cb.second] = 2;
				cb.first = fx;
				if (flag) {
					ret = mv + 1;
					return;
				}
			}

		
		}

		else if (ord[mv] == 1) {
			//cb가 먼저
			if (cr.first > cb.first) {
				fx = cb.first;
				for (int i = cb.first; i >= 0; i--) {
					if (copy[i][cb.second] == -1) {
						fx = i + 1;
						break;
					}
					if (copy[i][cb.second] == 3)
						return;
				}
				copy[cb.first][cb.second] = 0;
				copy[fx][cb.second] = 2;
				cb.first = fx;
				fx = cr.first;
				for (int i = cr.first; i >= 0; i--) {
					if (copy[i][cr.second] == -1 || copy[i][cr.second] == 2) {
						fx = i + 1;
						break;
					}
					if (copy[i][cr.second] == 3) {
						ret = mv + 1;
						return;
					}
				}
				copy[cr.first][cr.second] = 0;
				copy[fx][cr.second] = 1;
				cr.first = fx;
			}

			else {
				bool flag = 0;

				fx = cr.first;
				for (int i = cr.first; i >= 0; i--) {
					if (copy[i][cr.second] == -1) {
						fx = i + 1;
						break;
					}
					if (copy[i][cr.second] == 3) {
						flag = 1;
						break;
					}
				}
				copy[cr.first][cr.second] = 0;
				if (flag == 0)
					copy[fx][cr.second] = 1;
				cr.first = fx;


				fx = cb.first;
				for (int i = cb.first; i >= 0; i--) {
					if (copy[i][cb.second] == -1 || copy[i][cb.second] == 1) {
						fx = i + 1;
						break;
					}
					if (copy[i][cb.second] == 3)
						return;
				}
				copy[cb.first][cb.second] = 0;
				copy[fx][cb.second] = 2;
				cb.first = fx;
				if (flag) {
					ret = mv + 1;
					return;
				}
			}
		}

		else if (ord[mv] == 2) {
			//cb가 먼저
			if (cr.second > cb.second) {
				fy = cb.second;
				for (int i = cb.second; i >= 0; i--) {
					if (copy[cb.first][i] == -1) {
						fy = i + 1;
						break;
					}
					if (copy[cb.first][i] == 3)
						return;
				}
				copy[cb.first][cb.second] = 0;
				copy[cb.first][fy] = 2;
				cb.second = fy;

				fy = cr.second;
				for (int i = cr.second; i >= 0; i--) {
					if (copy[cr.first][i] == -1 || copy[cr.first][i] == 2) {
						fy = i + 1;
						break;
					}
					if (copy[cr.first][i] == 3) {
						ret = mv + 1;
						return;
					}
				}
				copy[cr.first][cr.second] = 0;
				copy[cr.first][fy] = 1;
				cr.second = fy;

			}

			else {
				bool flag = 0;

				fy = cr.second;
				for (int i = cr.second; i >= 0; i--) {
					if (copy[cr.first][i] == -1) {
						fy = i + 1;
						break;
					}
					if (copy[cr.first][i] == 3) {
						flag = 1;
						break;
					}
				}
				copy[cr.first][cr.second] = 0;
				if (flag == 0)
					copy[cr.first][fy] = 1;
				cr.second = fy;

				fy = cb.second;
				for (int i = cb.second; i >= 0; i--) {
					if (copy[cb.first][i] == -1 || copy[cb.first][i] == 1) {
						fy = i + 1;
						break;
					}
					if (copy[cb.first][i] == 3)
						return;
				}
				copy[cb.first][cb.second] = 0;
				copy[cb.first][fy] = 2;
				cb.second = fy;

				if (flag) {
					ret = mv + 1;
					return;
				}
			}
		}
		else if (ord[mv] == 3) {
			//cb가 먼저
			if (cr.second < cb.second) {
				fy = cb.second;
				for (int i = cb.second; i < m; i++) {
					if (copy[cb.first][i] == -1) {
						fy = i - 1;
						break;
					}
					if (copy[cb.first][i] == 3)
						return;
				}
				copy[cb.first][cb.second] = 0;
				copy[cb.first][fy] = 2;
				cb.second = fy;

				fy = cr.second;
				for (int i = cr.second; i < m; i++) {
					if (copy[cr.first][i] == -1 || copy[cr.first][i] == 2) {
						fy = i - 1;
						break;
					}
					if (copy[cr.first][i] == 3) {
						ret = mv + 1;
						return;
					}
				}
				copy[cr.first][cr.second] = 0;
				copy[cr.first][fy] = 1;
				cr.second = fy;

			}

			else {
				bool flag = 0;

				fy = cr.second;
				for (int i = cr.second; i < m; i++) {
					if (copy[cr.first][i] == -1) {
						fy = i - 1;
						break;
					}
					if (copy[cr.first][i] == 3) {
						flag = 1;
						break;
					}
				}
				copy[cr.first][cr.second] = 0;
				if (flag == 0)
					copy[cr.first][fy] = 1;
				cr.second = fy;

				fy = cb.second;
				for (int i = cb.second; i < m; i++) {
					if (copy[cb.first][i] == -1 || copy[cb.first][i] == 1) {
						fy = i - 1;
						break;
					}
					if (copy[cb.first][i] == 3)
						return;
				}
				copy[cb.first][cb.second] = 0;
				copy[cb.first][fy] = 2;
				cb.second = fy;

				if (flag) {
					ret = mv + 1;
					return;
				}
			}
		}

		
	}
}
void dfs(int dep,int mok) {
	if (ret != -1)
		return;

	if (dep == mok) {
		cal(dep);
		return;
	}

	for (int i = 0; i < 4; i++) {
		ord[dep] = i;
		dfs(dep + 1,mok);
	}
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	for(int i=1;i<11;i++)
		dfs(0,i);


	cout << ret;
}