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


int t, n, m;

int used = 1;
struct Node {
	int nxt[63];
	bool chk, vis;
};
Node node[40005];

int getnode() {
	memset(node[used].nxt, -1, sizeof(node[used].nxt));
	node[used].chk = node[used].vis = 0;
	return used++;
}
int ctoi(char x) {
	if ('0' <= x && x <= '9')
		return x - '0';
	if ('A' <= x && x <= 'Z')
		return x - 'A' + 10;
	if ('a' <= x && x <= 'z')
		return x - 'a' + 36;
	return 62;
}
void insert(string s, int mode) {
	int cur = 1;
	for (auto c : s) {
		int ch = ctoi(c);
		if (node[cur].nxt[ch] == -1)
			node[cur].nxt[ch] = getnode();
		cur = node[cur].nxt[ch];
		if (mode == -1)
			node[cur].vis = 1;
	}

	if (mode == 1) {
		node[cur].chk = 1;
		//	cout << cur << "삭제해야할단어\n";
	}

}
int cal(int cur) {
	//cout << cur << ", vis: " << vis[cur]<<", chk: "<<chk[cur]<< "\n";
	int tmp = 0;


	//자기 자신은 접두사
	if (node[cur].vis == 1) {
		if (node[cur].chk == 1) {
			tmp++;
			//	cout << cur << "에서 단어끝이자 not del 접두사\n";
		}
		for (int i = 0; i < 63; i++) {
			if (node[cur].nxt[i] == -1)
				continue;
			//	cout << trie[cur][i] << "실행\n";
			tmp += cal(node[cur].nxt[i]);
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
	
		used = 1;
		getnode();

		node[1].vis = 1;
		cin >> n;
		string s;
		for (int i = 0; i < n; i++) {
			cin >> s;
			insert(s, 1);
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> s;
			insert(s, -1);
		}

		bool flag = 0;
		for (int i = 0; i < 63; i++) {
			if (node[1].nxt[i] == -1)
				continue;
			if (node[node[1].nxt[i]].vis == 1) {
				flag = 1;
			}
		}
		if (flag == 0)
			cout << 1 << "\n";
		else
			cout << cal(1) << "\n";
	}

	return 0;
}
