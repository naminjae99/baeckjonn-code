#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
#include <string>
#include <memory.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <string.h>
#include <set>
#include <iomanip>
#include <unordered_set>
#include <map>
#include<cfloat>
#include<sstream>
#include<numeric>
#include <limits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; 
        cin >> n;
        vector<int> parent(n + 1, 0);
        vector<char> visited(n + 1, 0);

        // a가 부모, b가 자식
        for (int i = 0; i < n - 1; ++i) {
            int a, b; 
            cin >> a >> b;
            parent[b] = a;
        }

        int s, e; 
        cin >> s >> e;

        // s의 모든 조상 표시
        int x = s;
        while (x) {
            visited[x] = 1;
            x = parent[x];
        }

        // e를 위로 올리며 처음 만나는 visited가 LCA
        int y = e;
        while (y && !visited[y]) {
            y = parent[y];
        }

        cout << y << '\n';
    }
    return 0;
}
