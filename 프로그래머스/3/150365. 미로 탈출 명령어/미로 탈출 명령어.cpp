#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, -1, 1, 0 };
char dir[4] = { 'd', 'l', 'r', 'u' };

int N, M, R, C, K;
string answer = "";

bool valid(int x, int y) {
    return x >= 1 && x <= N && y >= 1 && y <= M;
}

void dfs(int x, int y, int cnt, string path) {
    if (!answer.empty()) return; // 이미 답 찾음
    int dist = abs(R - x) + abs(C - y);
    if (cnt + dist > K) return; // 더 못감
    if ((K - cnt - dist) % 2 == 1) return; // 짝수여야 가능

    if (cnt == K) {
        if (x == R && y == C) answer = path;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (valid(nx, ny))
            dfs(nx, ny, cnt + 1, path + dir[i]);
        if (!answer.empty()) return;
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    N = n; M = m; R = r; C = c; K = k;
    answer = "";

    int dist = abs(R - x) + abs(C - y);
    if (dist > K || (K - dist) % 2 == 1) return "impossible";

    dfs(x, y, 0, "");
    if (answer.empty()) return "impossible";
    return answer;
}

