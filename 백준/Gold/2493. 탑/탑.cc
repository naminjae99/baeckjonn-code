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



int n, m, ret;

int arr[500005];



pair<int, int> s[1000005];
int fr,tp;


void input() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		if (fr==tp) {
			s[tp++] = { arr[i],i };
			cout << 0 << "\n";
			continue;
		}


		while (fr != tp) {
			if (s[tp - 1].first < arr[i])
				tp--;
			else
				break;
		}
		if (fr != tp)
			cout << s[tp - 1].second + 1 << "\n";
		else
			cout << 0 << "\n";

		s[tp++]={ arr[i],i };

	}

}
void solve() {

}
int main() {
	fastio
		input();
	solve();




}