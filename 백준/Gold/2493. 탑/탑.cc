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



int n, m,ret;

int arr[500005];
stack<pair<int, int>>s;
int re[500005];
void input() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	for (int i = 0; i < n; i++) {
		if (s.empty()) {
			s.push({ arr[i],i });
			continue;
		}

		
		while (!s.empty()) {
			if (s.top().first < arr[i])
				s.pop();
			else
				break;
		}
		if (!s.empty())
			re[i]=s.top().second+1;
		
		s.push({ arr[i],i });

	}
	for (int i = 0; i < n; i++)
		cout << re[i] << " ";
}
void solve() {

}
int main() {
	fastio
		input();
	solve();


	

}