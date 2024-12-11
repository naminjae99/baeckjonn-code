#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORIter(v, vec) for(auto &v: vec)
#define pb push_back
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

int prv[500'001], nxt[500'001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    FOR(i, 0, N+1) { prv[i] = i-1; nxt[i] = i+1; }
    
    while(M--) {
        char c; int X, Y; cin >> c >> X >> Y;
        if(c == 'A') {
            nxt[prv[X]] = nxt[X];
            prv[nxt[X]] = prv[X];
            prv[X] = prv[Y];
            nxt[X] = Y;
            nxt[prv[X]] = X;
            prv[nxt[X]] = X;
        }
        else {
            nxt[prv[X]] = nxt[X];
            prv[nxt[X]] = prv[X];
            prv[X] = Y;
            nxt[X] = nxt[Y];
            nxt[prv[X]] = X;
            prv[nxt[X]] = X;
        }
    }
    
    vector<int> seq;
    int cur = 0;
    while(true) {
        cur = nxt[cur];
        if(cur > N) break;
        seq.pb(cur);
    }
    
    vector<int> d;
    int dp[N];
    
    FOR(i, 0, N) {
        int t = lower_bound(all(d), seq[i]) - d.begin();
        if(t < d.size()) {
            d[t] = seq[i];
            dp[i] = t+1;
        }
        else {
            d.pb(seq[i]);
            dp[i] = d.size();
        }
    }
    
    vector<int> lis(d.size());
    int idx = N-1;
    for(int i = d.size(); i >= 1; i--) {
        while(dp[idx] != i) idx--;
        lis[i-1] = seq[idx];
        idx--;
    }
    
    cout << N-d.size() << '\n';
    FOR(i, 0, lis.size()) {
        int l = (i == 0 ? 1 : lis[i-1]+1), r = lis[i]-1;
        FOR(j, l, r+1) {
            cout << "A " << j << ' ' << lis[i] << '\n';
        }
    }
    
    for(int j = N; j > lis.back(); j--) {
        cout << "B " << j << ' ' << lis.back() << '\n';
    }
    
    return 0;
}
