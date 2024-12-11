#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <memory.h>
#include <iomanip> 
#include <set>    
#include <tuple>

using namespace std;

int n;
vector <tuple<int, int, int>> e;
int re;
int p[1002];

int find(int x) {
    //루트노드이면
    if (p[x]<0)
        return x;
    return p[x] = find(p[x]);
}
bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return 0;
    if (p[x] == p[y]) {
        p[x]--;
    }
    if (p[x] < p[y])
        p[y] = x;
    else
        p[x] = y;
    return 1;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    fill(p, p + n, -1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (i == j)
                continue;
            e.push_back({ x, i, j });
        }
    }
   
    sort(e.begin(), e.end());
    long long ans=0;
    int cnt = 0;
    for(auto edge:e){
        int c, x, y;
        tie(c, x, y) = edge;

        if (!merge(x, y))
            continue;
        cnt++;
        ans += c;
        if (cnt == n - 1)
            break;
    }
    cout << ans;
}