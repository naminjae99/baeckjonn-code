#include <iostream>
#include <string>
using namespace std;

bool good[26];
int trie[1500005][26];
int chk[1500005];
int used = 2;
int total;
int k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, mask;
    cin >> s >> mask >> k;

    for (int i = 0; i < 26; i++)
        good[i] = (mask[i] == '1');

    int n = s.size();

    for (int i = 0; i < n; i++) {
        int bad = 0;
        int cur = 1;
        for (int j = i; j < n; j++) {
            int c = s[j] - 'a';
            if (trie[cur][c] == 0)
                trie[cur][c] = used++;
            cur = trie[cur][c];
            if (!good[c]) bad++;
            if (bad > k) break;
            if (chk[cur] == 0) {
                chk[cur] = 1;
                total++;
            }
        }
    }

    cout << total;
}
