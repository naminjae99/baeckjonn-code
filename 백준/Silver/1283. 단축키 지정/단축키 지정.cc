#include <bits/stdc++.h>
using namespace std;

int vis[26]; // 단축키 사용 여부
int n;

int toIndex(char c) {
    if ('A' <= c && c <= 'Z') return c - 'A';
    if ('a' <= c && c <= 'z') return c - 'a';
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cin.ignore(); // 개행 제거
    string s;

    while (n--) {
        getline(cin, s);
        stringstream ss(s);
        vector<string> words;
        string word;
        while (ss >> word) words.push_back(word);

        bool flag = false;
        int keyWordIdx = -1;

        // 1단계: 각 단어 첫 글자로 단축키 지정
        for (int i = 0; i < (int)words.size(); i++) {
            int idx = toIndex(words[i][0]);
            if (idx != -1 && !vis[idx]) {
                vis[idx] = 1;
                keyWordIdx = i;
                flag = true;
                break;
            }
        }

        // 출력
        string tmp;
        if (flag) {
            for (int i = 0; i < (int)words.size(); i++) {
                if (i == keyWordIdx) {
                    tmp += "[" + string(1, words[i][0]) + "]";
                    if (words[i].size() > 1)
                        tmp += words[i].substr(1);
                } else {
                    tmp += words[i];
                }
                if (i + 1 < (int)words.size()) tmp += " ";
            }
        } else {
            // 2단계: 단어 내부에서 단축키 지정
            flag = false;
            for (int i = 0; i < (int)s.size(); i++) {
                int idx = toIndex(s[i]);
                if (!flag && idx != -1 && !vis[idx]) {
                    tmp += "["; tmp += s[i]; tmp += "]";
                    vis[idx] = 1;
                    flag = true;
                } else {
                    tmp += s[i];
                }
            }
        }

        cout << tmp << "\n";
    }
}
