#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <memory.h>
#include <iomanip> 
#include <set>    
using namespace std;

int n,k;
long long total;
multiset <int> b;
pair<int, int> j[300003];

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int m, v;
        cin >> m >> v;
        j[i] = { m,v };
    }
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        b.insert(x);
    }
    
    sort(j, j + n,compare);

  
    int now = 0;

    while (1) {
        if (b.size() == 0)
            break;
        if (now == n)
            break;

        if (j[now].first > *prev(b.end())) {
            now++;
            continue;
        }
        if ((j[now].first <= *prev(b.end())) && (j[now].first >= *b.begin())) {
            total += j[now].second;
            auto it = b.lower_bound(j[now].first);
            b.erase(it);
            now++;
            continue;
        }
        if (j[now].first < *b.begin()) {
            total += j[now].second;
            b.erase(b.begin());
            now++;
        }
    }
    cout << total;
}