#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll arr[123457];
vector<int> ch[123457];

ll dfs(int now) {
    ll res = 0;
    for (int next : ch[now]) {
        res += dfs(next);
    }

    if (arr[now] >= 0) {
        res += arr[now];
    } else {
        res += arr[now]; // arr[now]는 음수
        if (res < 0) res = 0; // 양이 늑대에게 전부 먹히면 0
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    char type;
    ll a;
    int p;

    for (int i = 2; i <= n; i++) {
        cin >> type >> a >> p;
        arr[i] = (type == 'S') ? a : -a;
        ch[p].push_back(i); // 부모 -> 자식 방향
    }

    cout << dfs(1) << '\n';
}
