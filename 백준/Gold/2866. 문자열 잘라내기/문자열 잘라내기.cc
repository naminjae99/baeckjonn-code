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

using namespace std;
using ll = long long;

int n, m;
string arr[1001];
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[j]+=s[j];
		}
	}

	int cur = 1;
	unordered_set<string> uset;
	
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {
			if (uset.find(arr[i].substr(j)) == uset.end())
				uset.insert(arr[i].substr(j));
			else {
				cout << max(0,j-1);
				return 0;
			}
		}
		uset.clear();
	}

	cout << n-1;
}