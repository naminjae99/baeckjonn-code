#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int trie[10005][2], nodeCnt = 1;
bool isEnd[10005];  // 단어의 끝 여부
int n;
vector<pair<int, int>> words; // {길이, 입력순서}
string result[1001];

bool insert(int len, int idx, int node, string s) {
    if (isEnd[node]) return false; // 지나가는 곳이 단어의 끝이면 안 됨

    if ((int)s.size() == len) {
        isEnd[node] = true;
        result[idx] = s;
        return true;
    }

    for (int d = 0; d <= 1; ++d) {
        int &next = trie[node][d];
        if (next == 0) next = ++nodeCnt;
        if (insert(len, idx, next, s + char('0' + d))) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    words.resize(n);
    int totalLen = 0;
    for (int i = 0; i < n; ++i) {
        cin >> words[i].first;
        words[i].second = i;
        totalLen += words[i].first;
    }

    if (totalLen > 1000) {
        cout << -1 << "\n"; // 총 길이 초과
        return 0;
    }

    // 짧은 것부터 만들어야 접두어 안 겹침
    sort(words.begin(), words.end());

    for (auto [len, idx] : words) {
        if (!insert(len, idx, 1, "")) {
            cout << -1 << "\n";
            return 0;
        }
    }

    cout << 1 << "\n";
    for (int i = 0; i < n; ++i) {
        cout << result[i] << "\n";
    }
}
