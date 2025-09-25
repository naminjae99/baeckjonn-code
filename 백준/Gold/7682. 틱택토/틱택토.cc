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

int dx[8] = { -1,1,0,0,-1,-1,1,1 };
int dy[8] = { 0,0,-1,1,-1,1,-1,1 };
string s;
bool isWin(char board[3][3], char player) {
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
		if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
	}
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
	if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
	return false;
}

bool solve(string &s) {
	char board[3][3];
	int cntX = 0, cntO = 0;
	for (int i = 0; i < 9; i++) {
		board[i / 3][i % 3] = s[i];
		if (s[i] == 'X') cntX++;
		else if (s[i] == 'O') cntO++;
	}

	bool xWin = isWin(board, 'X');
	bool oWin = isWin(board, 'O');

	if (cntO > cntX || cntX - cntO > 1) return false;
	if (xWin && oWin) return false;
	if (xWin && cntX != cntO + 1) return false;
	if (oWin && cntX != cntO) return false;
	if (!xWin && !oWin && cntX + cntO != 9) return false;

	return true;
}

int main() {

	while (1) {
		cin >> s;
		if (s == "end")
			break;
		bool flag=solve(s);
		if (flag)
			cout << "valid\n";
		else
			cout << "invalid\n";

	}
	return 0;
}
