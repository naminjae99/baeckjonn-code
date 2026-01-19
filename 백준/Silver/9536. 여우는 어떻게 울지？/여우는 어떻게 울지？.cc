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


int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m, ret, k;

void input() {
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		vector<string> mp;
		unordered_set<string> vis;

		string s;
		getline(cin,s);

		stringstream ss(s);
		string word;
		
		while (ss>>word) {
			mp.push_back(word);
		}

		

		while (1) {
			getline(cin, s);
			if (s == "what does the fox say?") {
				for (auto c : mp) {
					if(vis.find(c)==vis.end())
						cout << c << " ";
				}
				cout << "\n";
				break;
			}
			else {
				stringstream os(s);
				string a, b, c;
				os >> a >> b >> c;
				vis.insert(c);
			}
		}
	}
}
int main() {
	fastio
	input();
}
