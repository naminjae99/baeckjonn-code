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
using namespace std;
using ll = long long;


int n, m, k,t;
//trie[20005][26]꼴에서 26이 string으로 변
int trie[1000005][26];
int chk[1000005];

unordered_map<string,bool> prf;
int used = 2;
string ret;


pair<bool, int> insert(string s) {
	bool flag = 0;
	string tmp="";
	ret = "";

	int cur = 1;
	for (auto c : s) {
		tmp += c;
		if(flag==0)
			ret += c;
		
		if (trie[cur][c - 'a'] == 0) {
			trie[cur][c - 'a'] = used++;
		}
		if (prf[ret] == 0)
			flag = 1;
		prf[tmp] = 1;
		cur = trie[cur][c - 'a'];
	}
	return { flag,++chk[cur] };

}
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	cin >> n;
	while (n--) {
		string s;
		cin >> s;

		pair<int,int> re=insert(s);
		//한번도 안사용한 접두사 찾은경우
		if (re.first == 1)
			cout << ret << "\n";
		else {
			//자기닉네임으로
			if (re.second == 1) {
				cout << s << "\n";
				prf[s] = 1;
			}
			else {
					s += to_string(re.second);
				cout << s << "\n";
				prf[s] = 1;
			}
		}
	}

}
