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
int arr[27][2];
vector <int> re[3];
void f0(int x) {
    re[0].push_back(x);
    if (arr[x][0] != 0)
        f0(arr[x][0]);
    if (arr[x][1] != 0)
        f0(arr[x][1]);
}
void f1(int x) {
    
    if (arr[x][0] != 0)
        f1(arr[x][0]);
    re[1].push_back(x);
    if (arr[x][1] != 0)
        f1(arr[x][1]);
}
void f2(int x) {

    if (arr[x][0] != 0)
        f2(arr[x][0]);
    if (arr[x][1] != 0)
        f2(arr[x][1]);
    re[2].push_back(x);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        if(b!='.')
            arr[a - 'A'][0] = b - 'A';
        if (c != '.')
            arr[a - 'A'][1] = c - 'A';
    }
    f0(0);
    f1(0);
    f2(0);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < re[i].size(); j++) {
            cout << char(re[i][j] + 'A');
        }
        cout << "\n";
    }

}