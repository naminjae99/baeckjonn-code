#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int n;
vector<int> a;
vector<int> tmp;

ll merge_sort(int left, int right) {
    if (left >= right) return 0;

    int mid = (left + right) / 2;
    ll cnt = 0;

    cnt += merge_sort(left, mid);
    cnt += merge_sort(mid + 1, right);

    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            tmp[k++] = a[i++];
        } else {
            // a[i] > a[j]이므로 역순 쌍 발생
            tmp[k++] = a[j++];
            cnt += (mid - i + 1); // i부터 mid까지는 모두 a[j]보다 크다
        }
    }

    while (i <= mid) tmp[k++] = a[i++];
    while (j <= right) tmp[k++] = a[j++];

    // 결과 복사
    for (int idx = left; idx <= right; idx++) {
        a[idx] = tmp[idx];
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    a.resize(n);
    tmp.resize(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    cout << merge_sort(0, n - 1) << "\n";

    return 0;
}
