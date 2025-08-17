#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
    vector<int> p; // negative size for root, parent index otherwise
    DSU(int n): p(n+1, -1) {} // 1-indexed
    int find(int x){ return p[x] < 0 ? x : p[x] = find(p[x]); }
    bool unite(int a, int b){
        a = find(a); b = find(b);
        if (a == b) return false;
        // union by size (keep a as bigger)
        if (-p[a] < -p[b]) swap(a, b);
        p[a] += p[b]; // sizes add (both negative)
        p[b] = a;
        return true;
    }
    ll size(int x){ return -p[find(x)]; }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<ll> val(n+1);
    for (int i = 1; i <= n; ++i) cin >> val[i];

    if (n == 1) { // 한 노드면 그 값이 정답
        cout << val[1] << '\n';
        return 0;
    }

    // 간선과 각 간선의 min 값
    vector<pair<ll, pair<int,int>>> edges;
    for (int i = 0; i < n-1; ++i){
        int a,b; cin >> a >> b;
        ll mn = min(val[a], val[b]);
        edges.push_back({mn, {a,b}});
    }

    // min 값 기준 내림차순으로 정렬
    sort(edges.begin(), edges.end(), [](auto &A, auto &B){
        return A.first > B.first;
    });

    DSU dsu(n);
    ll ans = *max_element(val.begin()+1, val.end()); // single node 선택도 고려

    for (auto &e : edges){
        ll mn = e.first;
        int a = e.second.first;
        int b = e.second.second;
        if (dsu.find(a) != dsu.find(b)) {
            dsu.unite(a,b);
            ll sz = dsu.size(a); // 합쳐진 컴포넌트 크기
            ans = max(ans, sz * mn);
        }
    }

    cout << ans << '\n';
    return 0;
}
