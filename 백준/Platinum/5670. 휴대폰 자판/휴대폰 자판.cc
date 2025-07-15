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

int n;
int used = 2;
int trie[1000008][26];
//해당글자에서 다음글자 가는종류
int cnt[1000008];

bool chk[1000008];
string arr[100005];
void insert(string s) {
	int cur = 1;
	for (auto c : s) {
		if (trie[cur][c - 'a'] == -1) {
			trie[cur][c - 'a'] = used++;
			cnt[cur]++;
		}
		//cout << cur << "에서";
		cur = trie[cur][c - 'a'];
		
		//cout << cur << "가는데 vis증가 \n";
	}
	chk[cur] = 1;
}
int main(){

	while (cin>>n) {

	

		memset(cnt, 0, sizeof(cnt));
		memset(chk, 0, sizeof(chk));
		used = 2;
		memset(trie, -1, sizeof(trie));
		for (int i = 0; i < n;i++) {
			string s;
			cin >> s;
			arr[i] = s;
			insert(s);
		}

		int sum=0;
		for (int i = 0; i < n; i++) {
			int cur = trie[1][arr[i][0]-'a'];
			int tmp = 1;

		//	cout << cur << "에서 시작\n";
			for (int j = 1; j < arr[i].size();j++) {
				char cc = arr[i][j];

				if (cnt[cur] == 1) {
					//마지막글자 확인할떄
				
						//마지막글자전에 단어가 있으면 직접입력해줘야함
					if (chk[cur] == 1) {
					//	cout << "11: " << cc << "확인하는데 1개\n";
						tmp++;
					}
					

					cur = trie[cur][cc - 'a'];
					
				}
				else {
					//cout <<"22: "<< cc << "확인하는데 1개\n";
					tmp++;
					cur = trie[cur][cc - 'a'];
				}

			}
			//cout << arr[i] << "를 만드는데 " << tmp << "개 필요\n";
			sum += tmp;
		}
		cout <<fixed<<setprecision(2) <<(float)sum / (float)n<<"\n";
		
	}


}