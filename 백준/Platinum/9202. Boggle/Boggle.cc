#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int n, m;
int trie[3000000][26];
int chk[3000000];             // 단어 길이 저장 (단어의 끝 표시)
string chk_str[3000000];      // 단어 저장
bool vis_trie[3000000];       // 단어 중복 방지
bool visited[4][4];           // 같은 칸 재방문 방지

int grid[4][4];
int dx[8] = { -1,-1,-1,0,1,1,1,0 };
int dy[8] = { -1,0,1,1,1,0,-1,-1 };

int used = 2;
int point, cnt, len, finded;

int score[9] = { 0, 0, 0, 1, 1, 2, 3, 5, 11 };  // 길이에 따른 점수

void insert(string s) {
	int cur = 1;
	for (auto c : s) {
		int ch = c - 'A';
		if (trie[cur][ch] == 0) trie[cur][ch] = used++;
		cur = trie[cur][ch];
	}
	chk[cur] = s.length();
	chk_str[cur] = s;
}

void find(int x, int y, int cur) {
	visited[x][y] = true;

	if (chk[cur] > 0 && !vis_trie[cur]) {
		vis_trie[cur] = true;
		cnt++;
		point += score[chk[cur]];

		if (chk[cur] > len) {
			len = chk[cur];
			finded = cur;
		}
		else if (chk[cur] == len && chk_str[cur] < chk_str[finded]) {
			finded = cur;
		}
	}

	for (int d = 0; d < 8; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;
		if (visited[nx][ny]) continue;
		int next = trie[cur][grid[nx][ny]];
		if (next) {
			find(nx, ny, next);
		}
	}

	visited[x][y] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		insert(s);
	}

	cin >> m;
	while (m--) {
		point = cnt = len = finded = 0;
		memset(vis_trie, 0, sizeof(vis_trie));

		for (int i = 0; i < 4; i++) {
			cin >> s;
			for (int j = 0; j < 4; j++) {
				grid[i][j] = s[j] - 'A';
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int next = trie[1][grid[i][j]];
				if (next) {
					memset(visited, 0, sizeof(visited));
					find(i, j, next);
				}
			}
		}

		if (cnt == 0) cout << "0 " << "" << " 0\n";
		else cout << point << " " << chk_str[finded] << " " << cnt << "\n";
	}
}
