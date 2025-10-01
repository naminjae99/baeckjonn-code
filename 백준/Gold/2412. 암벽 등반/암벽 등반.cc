#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;

int n, T;

// 좌표를 저장할 map<y, vector<x>>
unordered_map<int, vector<int>> rocks;
// 방문 체크
unordered_set<ll> vis;

inline ll encode(int x, int y) {
    return ((ll)x << 20) | y;
}

int bfs() {
    queue<pair<int,int>> q;
    q.push({0,0});
    vis.insert(encode(0,0));

    int step = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            auto [x,y] = q.front(); q.pop();
            if (y == T) return step;

            // y-2 ~ y+2 범위만 탐색
            for (int ny = y-2; ny <= y+2; ny++) {
                if (rocks.find(ny) == rocks.end()) continue;
                auto &vec = rocks[ny];
                // x-2 ~ x+2 범위만 확인
                for (int nx : vec) {
                    if (abs(nx-x) <= 2) {
                        ll code = encode(nx,ny);
                        if (!vis.count(code)) {
                            vis.insert(code);
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
        step++;
    }
    return -1;
}

int main() {
    fastio;
    cin >> n >> T;
    for (int i=0;i<n;i++) {
        int x,y; cin >> x >> y;
        rocks[y].push_back(x);
    }

    // 각 y별로 정렬 (이진 탐색 최적화 가능)
    for (auto &p : rocks) sort(p.second.begin(), p.second.end());

    cout << bfs();
    return 0;
}
