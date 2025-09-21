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

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


int n, m, t,k;
int ret;
string s;


void input() {
	while (1) {
		cin >> s;
		if (s == "end")
			break;
		bool flag = 0;

		bool cate = 0;
		int cnt = 0;
		
		bool ismo = 0;
		for (int i = 0; i < s.size(); i++) {
			if (i < s.size() - 1) {
				if (s[i] == s[i + 1] && s[i] != 'e'&&s[i] != 'o') {
					flag = 1;
					break;
				}
			}
			if(ismo==0)
				if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
					ismo = 1;
			
			if (cate == 0) {
				if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
					cnt++;
				else {
					cate = 1;
					cnt = 1;
				}
			}
			else {
				if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
					cate = 0;
					cnt = 1;
				}
				else {
					cnt++;
				}
			}
			if (cnt >= 3) {
				flag = 1;
				break;
			}
		}
		if (flag || ismo == 0)
			cout << "<" << s << "> is not acceptable.\n";
		else
			cout << "<" << s << "> is acceptable.\n";

	}
}
void solve() {

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	input();
	solve();
	//cout << ret;
	return 0;
}