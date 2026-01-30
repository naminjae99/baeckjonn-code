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


int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int vis[35][35];
char arr[35][35];



int solution(int m, int n, vector<string> board) {
	int answer = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = board[m - 1 - i][j];
		}
	}

	while (1) {
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				vis[i][j] = 0;
			
		bool flag = 0;
		for (int i = 0; i < m-1; i++) {
			for (int j = 0; j < n-1; j++) {
				if (arr[i][j] == '0')
					continue;
				if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i + 1][j + 1]
					&& arr[i][j] == arr[i + 1][j]) {
					vis[i][j] = vis[i][j + 1] = vis[i + 1][j] = vis[i + 1][j + 1] = 1;
					flag = 1;
				}
			}
		}
		if (flag) {
			for (int j = 0; j < n; j++) {
				queue<int>q;
				for (int i = 0; i < m; i++) {
					if (vis[i][j] == 0)
						q.push(arr[i][j]);
					else
						answer++;
					arr[i][j] = '0';
				}
				int x = 0;
				while (!q.empty()) {
					arr[x++][j] = q.front();
					q.pop();
				}
			}
			
		}
		else
			break;
	}

	return answer;

} 
