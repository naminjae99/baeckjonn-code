#include <bits/stdc++.h>
using namespace std;

struct info {
    int month, day, hour, min;
};

int month2day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

unordered_map<string, int> per_map; // 사람 → 인덱스
unordered_map<string, info> mp[80000]; // [사람 인덱스][물건] = 빌린 시간
map<string, long long> cost; // 사람 → 연체 시간(분)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= 12; i++)
        month2day[i] += month2day[i - 1];

    int n, F;
    string L;
    cin >> n >> L >> F;

    // 마감 시간 제한을 분으로 변환
    info lim;
    lim.day = stoi(L.substr(0, 3));
    lim.hour = stoi(L.substr(4, 2));
    lim.min = stoi(L.substr(7, 2));
    int limi = lim.day * 24 * 60 + lim.hour * 60 + lim.min;

    int per_idx = 0;
    for (int i = 0; i < n; i++) {
        string date, ti, ob, per;
        cin >> date >> ti >> ob >> per;

        if (per_map.find(per) == per_map.end())
            per_map[per] = per_idx++;
        int pidx = per_map[per];

        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        int hour = stoi(ti.substr(0, 2));
        int mi = stoi(ti.substr(3, 2));

        // 첫 대여라면 기록
        if (mp[pidx].find(ob) == mp[pidx].end()) {
            mp[pidx][ob] = { month, day, hour, mi };
        }
        // 반납이면 시간 계산
        else {
            info pre = mp[pidx][ob];
            long long dif = pre.min + pre.hour * 60 + (pre.day - 1) * 24 * 60 +
                             month2day[pre.month - 1] * 24 * 60;
            long long now = mi + hour * 60 + (day - 1) * 24 * 60 +
                             month2day[month - 1] * 24 * 60;

            if (dif + limi < now) {
                cost[per] += (now - dif - limi);
            }
            mp[pidx].erase(ob);
        }
    }

    if (cost.empty()) {
        cout << -1;
        return 0;
    }
    for (auto &c : cost) {
        cout << c.first << " " << c.second * F << "\n";
    }
}
