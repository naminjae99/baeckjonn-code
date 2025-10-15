#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

string s;
int k;
unordered_set<string> vis[11];
int mx = -1;

void input() {
    cin >> s >> k;
    if (s.size() == 1) {  // 한 자리 수는 교환 불가
        cout << -1;
        return;
    }

    queue<pair<string, int>> q;
    q.push({s, 0});
    vis[0].insert(s);

    int sz = s.size();
    while (!q.empty()) {
        auto [x, dep] = q.front();
        q.pop();

        if (dep == k) {
            if (x[0] != '0') mx = max(mx, stoi(x));
            continue;
        }

        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                string nx = x;
                swap(nx[i], nx[j]);
                if (nx[0] == '0') continue;
                if (vis[dep + 1].count(nx)) continue;
                vis[dep + 1].insert(nx);
                q.push({nx, dep + 1});
            }
        }
    }
    cout << mx;
}

int main() {
    fastio;
    input();
}
