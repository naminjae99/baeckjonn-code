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
using ll = long long;


int q,n, m, k, t;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

bool good[26];

int trie[1150005][26];
int chk[1150005];
int used = 2;
int total;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	string tmp;
	cin >> tmp;
	//0이 나쁜 문자
	for (int i = 0; i < 26; i++) {
		good[i] = tmp[i] - '0';
	}
	cin >> k;

	int si = s.size();

	for (int i = 0; i < si; i++) {
		int cnt = 0;
		int cur = 1;

		for (int j = i; j < si; j++) {
			int ch = s[j] - 'a';
			if (trie[cur][ch] == 0)
				trie[cur][ch] = used++;
			cur = trie[cur][ch];
			
			//뒤에꺼 안봐도 나쁜단어
			if (chk[cur] < 0)
				break;
			if (good[ch] == 0)
				cnt++;
			//나쁜단어인경우 종료
			if (cnt > k) {
				chk[cur] = -1;
				break;
			}

			if (chk[cur] == 0) {
				//cout << s.substr(i, j+1) << "\n";
				total++;
				chk[cur] = 1;
			}
		}
		
	}
	cout << total;
}
