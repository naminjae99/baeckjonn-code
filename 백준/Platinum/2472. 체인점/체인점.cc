#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, t;
vector<pair<int, int>> ed[100005];
int apt[3];
int d[3][100005];

struct Node {
    int now;
    ll mx;
};

Node heap[1000005];
int hs;

void push(Node x) {
    int i = hs++;
    while (i > 0) {
        int par = (i - 1) / 2;
        if (heap[par].mx <= x.mx) break;
        heap[i] = heap[par];
        i = par;
    }
    heap[i] = x;
}

Node pop() {
    Node ret = heap[0];
    int i = 0;
    heap[i] = heap[--hs];
    while (1) {
        int le = i * 2 + 1, ri = i * 2 + 2, pr = i;
        if (le < hs && heap[le].mx < heap[pr].mx) pr = le;
        if (ri < hs && heap[ri].mx < heap[pr].mx) pr = ri;
        if (pr == i) break;
        swap(heap[pr], heap[i]);
        i = pr;
    }
    return ret;
}

void dijkstra() {
    for (int i = 0; i < 3; i++) {
        fill(d[i], d[i] + n + 1, 1e9);
        d[i][apt[i]] = 0;
        push({apt[i], 0});
        while (hs > 0) {
            auto cur = pop();
            int now = cur.now, cost = cur.mx;
            if (d[i][now] != cost) continue;
            for (auto& e : ed[now]) {
                if (d[i][e.second] > cost + e.first) {
                    d[i][e.second] = cost + e.first;
                    push({e.second, d[i][e.second]});
                }
            }
        }
    }
}

vector<int> cx, cy, cz;
bool re[100005];
int tree[400005];

int update(int no, int s, int e, int idx, int val) {
    if (idx < s || idx > e) return tree[no];
    if (s == e) return tree[no] = val;
    int mid = (s + e) / 2;
    return tree[no] = min(update(no * 2, s, mid, idx, val), update(no * 2 + 1, mid + 1, e, idx, val));
}

int query(int no, int s, int e, int l, int r) {
    if (r < s || e < l) return 1e9;
    if (l <= s && e <= r) return tree[no];
    int mid = (s + e) / 2;
    return min(query(no * 2, s, mid, l, r), query(no * 2 + 1, mid + 1, e, l, r));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < 3; i++) cin >> apt[i];
    cin >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        ed[a].emplace_back(c, b);
        ed[b].emplace_back(c, a);
    }

    dijkstra();

    for (int i = 1; i <= n; i++) {
        cx.push_back(d[0][i]);
        cy.push_back(d[1][i]);
        cz.push_back(d[2][i]);
    }
    sort(cx.begin(), cx.end());
    sort(cy.begin(), cy.end());
    sort(cz.begin(), cz.end());

    struct Point {
        int x, y, z, idx;
        bool operator<(const Point& o) const {
            if (x == o.x) return y == o.y ? z > o.z : y > o.y;
            return x < o.x;
        }
    };

    vector<Point> points(n + 1);
    for (int i = 1; i <= n; i++) {
        points[i] = {
            (int)(lower_bound(cx.begin(), cx.end(), d[0][i]) - cx.begin()) + 1,
            (int)(lower_bound(cy.begin(), cy.end(), d[1][i]) - cy.begin()) + 1,
            (int)(lower_bound(cz.begin(), cz.end(), d[2][i]) - cz.begin()) + 1,
            i
        };
    }
    sort(points.begin() + 1, points.end());
    fill(tree, tree + 4 * n, 1e9);

    for (int i = 1; i <= n; i++) {
        int minZ = query(1, 1, n, 1, points[i].y - 1);
        if (minZ >= points[i].z) re[points[i].idx] = 1;
        int currentMin = query(1, 1, n, points[i].y, points[i].y);
        update(1, 1, n, points[i].y, min(currentMin, points[i].z));
    }

    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        cout << (re[x] ? "YES" : "NO") << '\n';
    }

    return 0;
}
