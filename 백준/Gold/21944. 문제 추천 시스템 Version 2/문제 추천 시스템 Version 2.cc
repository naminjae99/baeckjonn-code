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
using namespace std;
using ll = long long;


int n,m,k;


//dif , num
set<pair<int, int>> s[105];
int dif[100005];
int alg[100005];

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	
	cin >> n ;
	while (n--) {
		//a 번호/ b 난이도/ c 종류
		int a, b, c;
		cin >> a >> b >> c;
		
		s[c].insert({ b,a });
		s[0].insert({ b,a });
		dif[a] = b;
		alg[a] = c;
	}
	cin >> m;
	string cmd;

	int a, b,c;
	while (m--) {
		cin >> cmd;
		if (cmd[0] == 'r'&&cmd.back() == 'd') {
			cin >> a >> b;
			if (b == 1) 
				cout<<s[a].rbegin()->second<<"\n";
			else
				cout << s[a].begin()->second << "\n";
		}
		else if (cmd[0] == 'r'&&cmd.back() == '2') {
			cin >> a;
			if (a == 1)
				cout << s[0].rbegin()->second << "\n";
			else
				cout << s[0].begin()->second << "\n";
		}
		else if (cmd[0] == 'r'&&cmd.back() == '3') {
			cin >> a >> b;
			if (a == 1) {
				auto id=s[0].lower_bound({ b,0 });
				if (id == s[0].end())
					cout << -1 << "\n";
				else
					cout << id->second << "\n";
			}
			else {
				auto id = s[0].lower_bound({ b,0 });
				while (id->first >= b) {
					if (id != s[0].begin())
						id = prev(id);
					else
						break;
				}
				if (id->first < b)
					cout << id->second << "\n";
				else
					cout << -1 << "\n";

			}
		}
		else if (cmd[0] == 'a') {
			cin >> a >> b >> c;
			s[c].insert({ b,a });
			s[0].insert({ b,a });
			dif[a] = b;
			alg[a] = c;
		}
		else {
			cin >> a;
			int d = dif[a];
			int al = alg[a];

			s[al].erase({ d,a });
			s[0].erase({ d,a });
		}
	}

}
