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
string s;
void input() {
	cin >> n;
	cin >> m;
	cin >> s;
}

void solve() {
	
	for (int i = 0; i < m; i++) {
		int cnt = 0;
		int last = i+1;

		if (s[i] == 'I') {
		//	cout << i << "번쨰 부터 검사\n";
			for (int j = i+1; j <m; j+=2) {
				last = j;
				if (s[j] == 'O'&&s[j + 1] == 'I') {
					//cout << j << "는 0=="<<s[j]<<"," << j + 1 << "="<<s[j+1]<<"라 가능\n";
					cnt++;
				}
				else 
					break;
			}
			//cout << cnt << ", " << last << "\n";

			i = last - 1;
			if (cnt >= n) {
				ret += cnt - (n-1);
			}
		

		}
	}
	cout << ret;

}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	input();
	solve();


}
