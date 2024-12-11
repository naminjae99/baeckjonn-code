#include <stdio.h>
#include<iostream>
#include <string>
#include<queue>
#include <memory.h>
#include<vector>
#include<set>
#include <iomanip> 
using namespace std;


int r,c,k,n;
int arr[26];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int re;

vector <string> v;
void f(int dep,int mok,int ind) {
	if (dep == mok) {
		int tmp = 0;
		for (int i = 0; i < v.size(); i++) {
			int flag = 0;
			for (int j = 0; j < v[i].size(); j++) {
				if (arr[v[i][j] - 'a'] == 0) {
					flag = 1;
					break;
				}
			}
			if (flag == 0)
				tmp++;
		}
		re = max(re, tmp);
		return;
	}
	for (int i = ind; i < 26; i++) {
		if (arr[i])
			continue;
		arr[i] = 1;
		f(dep + 1, mok,i+1);
		arr[i] = 0;
	}
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	if (k < 5) {
		cout << 0;
		return 0;
	}
	arr['a' - 'a'] = arr['c' - 'a'] = arr['i' - 'a'] = arr['t' - 'a'] = arr['n' - 'a'] = 1;

	f(0,k - 5,0);
	cout << re;
}
