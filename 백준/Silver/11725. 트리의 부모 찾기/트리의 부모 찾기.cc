#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <memory.h>
#include <iomanip> 
using namespace std;

int n;
vector<int> e[100005];
int p[100005];
void f(int x) {
    for (int i = 0; i < e[x].size(); i++) {
        if (p[e[x][i]] != 0)
            continue;
        p[e[x][i]] = x;
        f(e[x][i]);
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
 
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    p[1] = 1;
    f(1);
    for (int i = 2; i <= n; i++) {
        cout << p[i] << "\n";
    }

}