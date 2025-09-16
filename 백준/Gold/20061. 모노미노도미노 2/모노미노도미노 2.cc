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
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int n, t, ret, m;
int point;
int arr[11][11];

void push(int ty, int a, int b) {
	//a,b
	int x, y;
	if (ty == 1) {
		y = 5;
		for (int j = 6; j < 10; j++) {
			if (arr[a][j])
				break;
			y = j;
		}
		arr[a][y] = 1;

		x = 5;
		for (int j = 6; j < 10; j++) {
			if (arr[j][b])
				break;
			x = j;
		}
		arr[x][b] = 1;
	}
	else if (ty == 2) {
		y = 5;
		for (int j = 6; j < 10; j++) {
			if (arr[a][j])
				break;
			y = j;
		}
		arr[a][y] =arr[a][y-1]= 1;

		x = 5;
		for (int j = 6; j < 10; j++) {
			if (arr[j][b]||arr[j][b+1])
				break;
			x = j;
		}
		arr[x][b] = arr[x][b + 1] = 1;
	}
	else {
		y = 5;
		for (int j = 6; j < 10; j++) {
			if (arr[a][j]||arr[a+1][j])
				break;
			y = j;
		}
		arr[a][y] = arr[a+1][y] = 1;

		x = 5;
		for (int j = 6; j < 10; j++) {
			if (arr[j][b])
				break;
			x = j;
		}
		arr[x][b] = arr[x-1][b] = 1;
	}
}
void del() {
	for (int j = 9; j >= 4; j--) {
		int flag = 0;
		for (int i = 0; i < 4; i++) {
			if (arr[i][j])
				flag++;
		}
		if (flag != 4)
			continue;
		point++;
		for (int i = 0; i < 4; i++) {
			for (int k = j; k >= 4; k--) {
				arr[i][k] = arr[i][k - 1];
			}
		}
		j++;
	}

	for (int i = 9; i >= 4; i--) {
		int flag = 0;
		for (int j = 0; j < 4; j++) {
			if (arr[i][j])
				flag++;
		}
		if (flag != 4)
			continue;
		point++;
		for (int j = 0; j < 4; j++) {
			for (int k = i; k >= 4; k--) {
				arr[k][j] = arr[k-1][j];
			}
		}
		i++;
	}

}
void blank() {
	bool flag = 0;
	bool fflag = 0;

	
	for (int i = 0; i < 4; i++) {
		if (arr[i][4]) {
			flag = 1;
			break;
		}
		if (arr[i][5])
			fflag = 1;
	}
	//2칸밀고
	if (flag) {
		for (int j = 9; j >= 4; j--) {
			for (int i = 0; i < 4; i++) {
					arr[i][j] = arr[i][j - 2];
			}
		}
	}
	//한칸밀고
	else if (fflag) {
		for (int j = 9; j >= 4; j--) {
			for (int i = 0; i < 4; i++) {
				arr[i][j] = arr[i][j - 1];
			}
		}
	}

	flag = fflag = 0;
	for (int i = 0; i < 4; i++) {
		if (arr[4][i]) {
			flag = 1;
			break;
		}
		if (arr[5][i])
			fflag = 1;
	}
	//2칸밀고
	if (flag) {
		for (int i = 9; i >= 4; i--) {
			for (int j = 0; j < 4; j++) {
				arr[i][j] = arr[i-2][j];
			}
		}
	}
	//한칸밀고
	else if (fflag) {
		for (int i = 9; i >= 4; i--) {
			for (int j = 0; j < 4; j++) {
				arr[i][j] = arr[i - 1][j];
			}
		}
	}
	
}
void print() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}
void input() {
	cin >> n;
	while (n--) {
		int ty, x, y;
		cin >> ty >> x >> y;

		push(ty,x, y);
	
		del();
	

		blank();
	
	}
}
void solve() {


}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	input();
	solve();
	for (int i = 0; i < 4; i++) {
		for (int j = 6; j < 10; j++) {
			if (arr[i][j])
				ret++;
			if (arr[j][i])
				ret++;
		}
	}

	cout <<point<<"\n"<< ret;

}
