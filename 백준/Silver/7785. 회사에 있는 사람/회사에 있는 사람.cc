#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int M = 1000003; // 해시 테이블 크기
const int a = 1000;    // 해시 상수
const int MX = 1000005; // 최대 삽입 횟수

int head[M];
int pre[MX];
int nxt[MX];
string key[MX];
bool deleted[MX]; // 삭제된 키 추적 플래그
int unused = 0;

int my_hash(string& s) {
    int h = 0;
    for (auto x : s)
        h = (h * a + x) % M;
    return h;
}

int find(string k) {
    int h = my_hash(k);
    int idx = head[h];
    while (idx != -1) {
        if (key[idx] == k && !deleted[idx])
            return idx;
        idx = nxt[idx];
    }
    return -1;
}

void insert(string k) {
    if (find(k) != -1) // 이미 존재하는 경우
        return;

    int h = my_hash(k);
    if (head[h] != -1) {
        pre[head[h]] = unused;
        nxt[unused] = head[h];
    }
    key[unused] = k;
    deleted[unused] = false; // 초기화
    head[h] = unused;
    unused++;
}

void erase(string k) {
    int idx = find(k);
    if (idx != -1) {
        deleted[idx] = true;
        if (nxt[idx] != -1)
            pre[nxt[idx]] = pre[idx];
        if (pre[idx] != -1)
            nxt[pre[idx]] = nxt[idx];
        if (head[my_hash(k)] == idx)
            head[my_hash(k)] = nxt[idx];
    }
}

int main() {
    fill(head, head + M, -1);
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);
    fill(deleted, deleted + MX, false); // 삭제 플래그 초기화

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        if (b == "enter")
            insert(a);
        else
            erase(a);
    }

    vector<string> result;
    for (int i = 0; i < unused; i++) {
        if (!deleted[i]) // 삭제되지 않은 키만 추가
            result.push_back(key[i]);
    }

    sort(result.begin(), result.end(), greater<>());

    for (const auto& name : result)
        cout << name << "\n";

    return 0;
}
