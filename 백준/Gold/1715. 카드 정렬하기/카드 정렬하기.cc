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

int n;

int arr[100001];
int s;
int re;
void push(int x) {
    s++;
    arr[s] = x;
   
    int tmp = s;
    while (tmp != 1) {
        int par = tmp / 2;
        if (arr[par] <= arr[tmp])
            break;
        swap(arr[par] , arr[tmp]);
        tmp = par;
    }
}
int top() {
        return arr[1];
}
void pop() {

    swap(arr[1], arr[s]);
    s--;
    int tmp = 1;

    while (tmp*2<=s) {
        int lc = 2 * tmp;
        int rc = 2 * tmp + 1;

        int min_c = lc;
        if (rc <= s && arr[rc] < arr[lc]) {
            min_c = rc;
        }
       
        if (arr[min_c] < arr[tmp]) {
            swap(arr[min_c], arr[tmp]);
        }
        else {
            break;
        }
        tmp = min_c;
    }
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        push(x);
    }
  

    while (s >= 2) {
        int tmp1 = top();
        pop();
        int tmp2 = top();
        pop();
        re += tmp1 + tmp2;
        push(tmp1 + tmp2);
    }
    if (n == 1) {
        cout << 0;
      
    }
    else
    cout << re;
}
