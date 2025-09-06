#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        string s;
        getline(cin, s);

        if (s == "#")
            break;

        stack<string> st;
        for (int i = 0; i < (int)s.length(); i++) {
            // 태그를 찾기 시작
            if (s[i] == '<') {
                int temp_start = i + 1;
                int temp_end = 0;

                while (s[i] != '>') {
                    i++;
                    temp_end++;
                }

                // 태그 내용 파싱
                string tag = s.substr(temp_start, temp_end - 1);

                // 공백 기준으로 단어 분리 (예: <br />, <a href=""> 등 처리)
                vector<string> temp_words = split(tag, ' ');

                if (temp_words.back() == "/") { // 단일 태그 (self-closing) 처리
                    continue;
                }
                else if (temp_words[0][0] == '/') { // 닫는 태그 처리
                    if (!st.empty() && st.top() == temp_words[0].substr(1, temp_words[0].length())) {
                        st.pop();
                    }
                    else if (st.empty()) {
                        st.push(temp_words[0]);
                    }
                }
                else { // 여는 태그 처리
                    st.push(temp_words[0]);
                }
            }
        }

        if (!st.empty()) {
            cout << "illegal\n";
        }
        else {
            cout << "legal\n";
        }
    }

    return 0;
}
