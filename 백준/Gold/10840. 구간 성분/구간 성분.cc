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
#include<map>
#include<iomanip>
#include<cfloat>
#include<array>
using namespace std;
using ll = unsigned long long;


int n, m, k, t;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


string s1, s2;
int arr1[1505];

int arr2[1505];
unordered_set<string>mp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s1 >> s2;

	if (s1.size() > s2.size()) 
		swap(s1, s2);
	

	
	
	for (int si = s1.size(); si >= 1; si--) {
		string s;
	//	cout << "s2: \n";

		for (int i = 0; i <=s2.size()-si; i++) {
			s=s2.substr(i, si);
			sort(s.begin(), s.end());
			//cout << s << "\n";
			mp.insert(s);
		}
	//	cout << "s1: \n";
		for (int i = 0; i <= s1.size()-si; i++) {
			s = s1.substr(i, si);
			sort(s.begin(), s.end());
		//	cout << s << "\n";
			if (mp.find(s) != mp.end()) {
				cout << si;
				return 0;
			}
		}
	}
	
	cout << 0;

}
