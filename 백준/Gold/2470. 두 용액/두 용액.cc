#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include<set>
#include<unordered_map>
#include<string>
using namespace std;
const int INF = 2*1e9;

int n, m;

string s;
int arr[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    int st = 0;
    int en = n - 1;
    int min = 2*1e9+1;

    int l = 0;
    int r = n - 1;

    while (st < en) {

        int tmp = arr[st] + arr[en];
        int a_tmp = abs(arr[st] + arr[en]);
        if (min>a_tmp) {
            l = st; r = en;
            min = a_tmp;
        }
        
        if (tmp >= 0) {
            --en;
        }
        else {
            ++st;
        }
    }
    cout << arr[l] << " " << arr[r];
}
