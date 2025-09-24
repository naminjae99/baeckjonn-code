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

int dx[4] = {-1,0,1,0 };
int dy[4] = { 0,1,0,-1 };


int n, m, t, k, ret;

void input() {
	cout << 100 << "\n";
	for (int i = 1; i < 100; i++) {
		for (int j = 1; j < 100; j++) {
			if (i == j)
				cout << 0 << " ";
			else
				cout << 10000 << " ";
		}
		cout << 4999<<"\n";
	}
	for (int i = 1; i < 100; i++)
		cout << 4999 << " ";
	cout << 0;
}

void solve() {

}

void calculator() {


}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	input();
	solve();


	return 0;
}