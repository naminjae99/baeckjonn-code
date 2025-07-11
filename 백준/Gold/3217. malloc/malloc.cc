#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
using namespace std;

int n;
set<pair<int, int>> other;
unordered_map<string, pair<int, int>> mp;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;

    other.insert({1, 100000}); // 전체 메모리 초기화

    while (n--) {
        string s;
        cin >> s;

        if (s[5] == 'm') { // malloc
            string val = s.substr(0, 4);
            string x = s.substr(12, s.size() - 13);
            int xx = stoi(x);

            bool flag = false;
            for (auto it = other.begin(); it != other.end(); ++it) {
                if (it->second >= xx) {
                    int start = it->first;
                    mp[val] = {start, xx};

                    other.erase(it);
                    if (it->second > xx) // ✅ size가 0이면 넣지 마라
                        other.insert({start + xx, it->second - xx});

                    flag = true;
                    break;
                }
            }
            if (!flag)
                mp[val] = {0, 0};

        } else if (s[0] == 'f') { // free
            s = s.substr(5, 4);
            if (mp[s].first == 0) continue;

            int sidx = mp[s].first;
            int cnt = mp[s].second;

            auto nxt = other.lower_bound({sidx, 0});

            if (nxt != other.begin()) {
                auto pre = prev(nxt);
                if (pre->first + pre->second == sidx) {
                    sidx = pre->first;
                    cnt += pre->second;
                    other.erase(pre);
                }
            }

            if (nxt != other.end() && sidx + cnt == nxt->first) {
                cnt += nxt->second;
                other.erase(nxt);
            }

            other.insert({sidx, cnt});
            mp[s] = {0, 0};

        } else { // print
            s = s.substr(6, 4);
            cout << mp[s].first << "\n";
        }
    }
}
