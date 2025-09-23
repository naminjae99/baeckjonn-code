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
using namespace std;
using ll = long long;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };


int n, m, t, k, ret;

int board_idx,block_idx;
int board_size[2500];
vector<pair<int, int>> block[2500][4];
int vis[51][51];
int board[51][51];
int tb[51][51];
int used[2500];
int board_used[2500];
void bfs1(int a, int b, int num) {
	board[a][b] = num;
	queue<pair<int, int>> q;
	q.push({ a,b });

	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (board[nx][ny]!=0)
				continue;
			board[nx][ny] = num;
			q.push({ nx,ny });
			cnt++;
		}
	}
	board_size[num] = cnt;
}

void bfs(int a, int b, int num) {
	vis[a][b] = 1;
	queue<pair<int, int>> q;
	q.push({ a,b });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		block[num][0].push_back({ x - a,y - b });

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (vis[nx][ny] || tb[nx][ny]==0)
				continue;
			vis[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
	for (int i = 1; i < 4; i++) 
		for (auto c : block[num][i - 1]) 
			block[num][i].push_back({ c.second,-c.first });
		
	
}
bool check(int x, int y,int cate,int dir) {
	int num = board[x][y];
	if (board_size[num] != block[cate][dir].size())
		return 0;
	for (auto c : block[cate][dir]) {
		if (board[x + c.first][y + c.second] == num)
			continue;
		else
			return 0;
	}

	board_used[num] = 1;
	ret += board_size[num];
	return 1;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
	board_idx = 2;
	n = game_board.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board[i][j] = game_board[i][j];
			tb[i][j] = table[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] || vis[i][j])
				continue;
			bfs1(i, j, board_idx++);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tb[i][j] == 0 || vis[i][j])
				continue;
			bfs(i, j, block_idx++);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 1 || board_used[board[i][j]])
				continue;
			bool flag = 0;
			for (int ct = 0; ct < block_idx; ct++) {
				if (used[ct])
					continue;
				for (int dir = 0; dir < 4; dir++) {
					flag = check(i, j, ct, dir);
					if (flag) {
						used[ct] = 1;
						break;
					}

				}
				if (flag)
					break;
			}

		}
	}
	return ret;
}