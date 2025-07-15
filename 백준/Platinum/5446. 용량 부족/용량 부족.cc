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
using namespace std;
using ll = long long;


int t, n,m;
int trie[40005][64];
int used = 2;

int chk[40005];
int vis[40005];
int ctoi(char x) {
	if('0'<=x&&x<='9')
		return x - '0';
	if ('A' <= x && x <= 'Z')
		return x - 'A'+10;
	if ('a' <= x && x <= 'z')
		return x - 'a'+36;
	return 62;
}
void insert(string s, int mode) {
	int cur = 1;
	for (auto c : s) {
		int ch = ctoi(c);
		if (trie[cur][ch] == -1)
			trie[cur][ch] = used++;
		cur = trie[cur][ch];
		if(mode==-1)
		vis[cur] = 1;
	}

	if (mode == 1) {
		chk[cur] = 1;
	//	cout << cur << "삭제해야할단어\n";
	}
	
}
int cal(int cur) {
	//cout << cur << ", vis: " << vis[cur]<<", chk: "<<chk[cur]<< "\n";
	int tmp = 0;

	
	//자기 자신은 접두사
	if (vis[cur] == 1) {
		if (chk[cur] == 1) {
			tmp++;
		//	cout << cur << "에서 단어끝이자 not del 접두사\n";
		}
		for (int i = 0; i < 63; i++) {
			if (trie[cur][i] == -1)
				continue;
		//	cout << trie[cur][i] << "실행\n";
			tmp += cal(trie[cur][i]);
		}
	}
	//접두사 풀림 그 자식들도 전부 접두사 아니므로 cur까지 삭제하면 다삭제가능
	else {
		//cout << cur << " 삭제하면 다삭제됨\n";
		tmp++;
	}

	

	return tmp;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--) {
		memset(chk, 0, sizeof(chk));
		memset(vis, 0, sizeof(vis));
		memset(trie, -1, sizeof(trie));
		used = 2;
		vis[1] = 1;
		cin >> n;
		string s;
		for (int i = 0; i < n; i++) {
			cin >> s;
			insert(s,1);
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> s;
			insert(s, -1);
		}

	bool flag = 0;
		for (int i = 0; i < 63; i++) {
			if (trie[1][i] == -1)
				continue;
			if (vis[trie[1][i]] == 1) {
				flag = 1;
			}
		}
		if (flag == 0)
			cout << 1 << "\n";
		else
			cout<< cal(1)<<"\n";
	}
	
	return 0;
}
