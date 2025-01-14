#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include<iostream>
#include <string>
#include<deque>
#include <memory.h>
#include<vector>
#include<set>
#include<queue>
#include <cassert>

#include<algorithm>

using namespace std;

int t,n;
vector <pair<int, int>> order;
char arr[6][3][3];

void init() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			arr[0][i][j] = 'w';
			arr[1][i][j] = 'y';
			arr[2][i][j] = 'r'; 
			arr[3][i][j] = 'o';
			arr[4][i][j] = 'g';
			arr[5][i][j] = 'b';
		}
	}
}
void one_turn(int x) {
	char tmp[6][3][3];
	memcpy(tmp, arr, sizeof(arr));
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			arr[x][j][2-i] = tmp[x][i][j];
		}
	}
	
	

}
void rev_one_turn(int x) {
	char tmp[6][3][3];
	memcpy(tmp, arr, sizeof(arr));


	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			arr[x][2-j][i] = tmp[x][i][j];
		}
	}
}
void two_turn(int a,int b,int c,int d,int r) {
	char tmp[6][3][3];
	memcpy(tmp, arr, sizeof(arr));
	for (int i = 0; i < 3; i++) {
		arr[b][r][i] = tmp[a][r][i];
		arr[c][r][i] = tmp[b][r][i];
		arr[d][r][i] = tmp[c][r][i];
		arr[a][r][i] = tmp[d][r][i];
	}

}


void two_turn2(int a, int b, int c, int d) {
	char tmp[6][3][3];
	memcpy(tmp, arr, sizeof(arr));
	for (int i = 0; i < 3; i++) {
			arr[b][i][0] = tmp[a][2][i];
			arr[c][0][2 - i] = tmp[b][i][0];
			arr[d][i][2] = tmp[c][0][i];
			arr[a][2][2 - i] = tmp[d][i][2];
	}
}
void rev_two_turn2(int a, int b, int c, int d) {
	char tmp[6][3][3];
	memcpy(tmp, arr, sizeof(arr));
	for (int i = 0; i < 3; i++) {
		arr[b][2-i][2] = tmp[a][2][i];
		arr[c][0][i] = tmp[b][i][2];
		arr[d][2-i][0] = tmp[c][0][i];
		arr[a][2][i] = tmp[d][i][0];
	}
}

void two_turn4(int a, int b, int c, int d) {
	char tmp[6][3][3];
	memcpy(tmp, arr, sizeof(arr));
	for (int i = 0; i < 3; i++) {
		arr[b][i][0] = tmp[a][i][0];
		arr[c][i][0] = tmp[b][i][0];
		arr[d][2-i][2] = tmp[c][i][0];
		arr[a][2-i][0] = tmp[d][i][2];
	}
}
void rev_two_turn4(int a, int b, int c, int d) {
	char tmp[6][3][3];
	memcpy(tmp, arr, sizeof(arr));
	for (int i = 0; i < 3; i++) {
		arr[b][2-i][2] = tmp[a][i][0];
		arr[c][2-i][0] = tmp[b][i][2];
		arr[d][i][0] = tmp[c][i][0];
		arr[a][i][0] = tmp[d][i][0];
	}
}
void two_turn3(int a, int b, int c, int d) {
	char tmp[6][3][3];
	memcpy(tmp, arr, sizeof(arr));

	for (int i = 0; i < 3; i++) {
		arr[b][2-i][0] = tmp[a][0][i];
		arr[c][2][i] = tmp[b][i][0];
		arr[d][2-i][2] = tmp[c][2][i];
		arr[a][0][i] = tmp[d][i][2];
	}
	
}
void rev_two_turn3(int a, int b, int c, int d) {
	char tmp[6][3][3];
	memcpy(tmp, arr, sizeof(arr));
	for (int i = 0; i < 3; i++) {
		arr[b][i][2] = tmp[a][0][i];
		arr[c][2][2 - i] = tmp[b][i][2];
		arr[d][i][0] = tmp[c][2][i];
		arr[a][0][2-i] = tmp[d][i][0];
	}
}

void two_turn5(int a, int b, int c, int d)	 {
	char tmp[6][3][3];
	memcpy(tmp, arr, sizeof(arr));
	for (int i = 0; i < 3; i++) {
		arr[b][2-i][0] = tmp[a][i][2];
		arr[c][2-i][2] = tmp[b][i][0];
		arr[d][i][2] = tmp[c][i][2];
		arr[a][i][2] = tmp[d][i][2];
	}
	
}
void rev_two_turn5(int a, int b, int c, int d) {
	char tmp[6][3][3];
	memcpy(tmp, arr, sizeof(arr));
	for (int i = 0; i < 3; i++) {
		arr[b][i][2] = tmp[a][i][2];
		arr[c][i][2] = tmp[b][i][2];
		arr[d][2-i][0] = tmp[c][i][2];
		arr[a][2-i][2] = tmp[d][i][0];
	}

}
void p() {
	cout << "큐브상태\n";
	for (int w = 0; w < 6; w++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << arr[w][i][j];
			}
			cout << "\n";
		}
		cout << "\n\n";
	}
}

void turn1(int x) {
	if (order[x].first == 0 && order[x].second == 1) {
		one_turn(0);
		two_turn(4, 3, 5, 2, 0);
	}
	else if (order[x].first == 0 && order[x].second == -1) {
		rev_one_turn(0);
		two_turn(4, 2, 5, 3, 0);
	}

	else if (order[x].first == 1 && order[x].second == 1) {
		one_turn(1);
		two_turn(2,5,3,4, 2);
	}
	else if (order[x].first == 1 && order[x].second == -1) {
		rev_one_turn(1);
		two_turn(2,4,3,5, 2);
	}

	else if (order[x].first == 2 && order[x].second == 1) {
		one_turn(2);
		two_turn2(0, 5, 1,4);
	}
	else if (order[x].first == 2 && order[x].second == -1) {
		rev_one_turn(2);
		rev_two_turn2(0,4,1,5);
	}

	else if (order[x].first == 3 && order[x].second == 1) {
		one_turn(3);
		two_turn3(0, 4, 1, 5);
	}
	else if (order[x].first == 3 && order[x].second == -1) {
		rev_one_turn(3);
		rev_two_turn3(0, 5, 1,4);
	}

	else if (order[x].first == 4 && order[x].second == 1) {
		one_turn(4);
		two_turn4(0, 2, 1,3);
	}
	else if (order[x].first == 4 && order[x].second == -1) {
		rev_one_turn(4);
		rev_two_turn4(0, 3, 1, 2);

	}

	else if (order[x].first == 5 && order[x].second == 1) {
		one_turn(5);
		two_turn5(0, 3, 1, 2);
	}
	else if (order[x].first == 5 && order[x].second == -1) {
		rev_one_turn(5);
		rev_two_turn5(0, 2, 1, 3);
	}

}

int main() {
	cin >> t;
	while (t--) {
		
		order.clear();
		init();
		cin >> n;
		for (int i = 0; i < n; i++) {

			string s = "";
			cin >> s;

			int a, b;
			char x, y;
			x = s[0];
			y = s[1];

			if (x == 'U')
				a = 0;
			if (x == 'D')
				a = 1;
			if (x == 'F')
				a = 2;
			if (x == 'B')
				a = 3;
			if (x == 'L')
				a = 4;
			if (x == 'R')
				a = 5;

			if (y == '+')
				b = 1;
			if (y == '-')
				b = -1;
			order.push_back({ a,b });

		}

		for (int i = 0; i < n; i++) {
			turn1(i);
			
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << arr[0][i][j];
			}
			cout << "\n";
		}
	}

}