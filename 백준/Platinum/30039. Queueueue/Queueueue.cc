#include <iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;

deque<int>h;
deque<int>v;
int h_s;
int v_s;
int h_n=-1;
int v_n=-1;

int n;
string s;
int x;


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	while (n--) {
	
		cin >> s;
		
		if (s == "hpush") {
			cin >> x;
			h.push_back(x);
			h_s++;
			h_n = (h_s+1) / 2 -1;

			//가로 크기가 홀수면 공유원소 바뀜
			if (h_s % 2 == 1) {
				if (v_s == 0) {
					v.push_back(x);
					v_s++; 
					v_n =(v_s+1)/2 -1;
				}
				else 
					v[v_n] = h[h_n];
			}
		}
		else if (s == "hpop") {
			if (h_s != 0) {
				cout << h[0] << "\n";

				//원소하나남은거 삭제시 
				if (h_s == 1) {
					if(v_s==1){
						h.pop_back();
						v.pop_back();
						h_s--;
						v_s--;
					}
					else {
						v.erase(v.begin() + v_n);
						v_s--;
						v_n = (v_s + 1) / 2 - 1;
						h[0] = v[v_n];
					}
				}
				else {
					h.pop_front();
					h_s--;
					if (h_s % 2 == 1) {
						h_n = (h_s + 1) / 2 - 1;
						v[v_n] = h[h_n];
					}
					else
						h_n = (h_s + 1) / 2 - 1;
				}
			}
			else
				cout << -1 << "\n";
		}
		else if (s == "hfront") {
			if (h_s != 0)
				cout << h[0] << "\n";
			else
				cout << -1<<"\n";
		}
		else if (s == "hback") {
			if (h_s != 0)
				cout << h[h_s-1] << "\n";
			else
				cout << -1 << "\n";
		}
		else if (s == "hsize") {
			cout << h_s << "\n";
		}
		else if (s == "vpush") {
			cin >> x;

			v.push_back(x);
			v_s++;
			v_n = (v_s + 1) / 2 - 1;

			if (v_s % 2 == 1) {
				if (h_s == 0) {
					h.push_back(x);
					h_s++;
					h_n = (h_s + 1) / 2 - 1;
				}
				else
					h[h_n] = v[v_n];
			}
		}
		else if (s == "vpop") {
			if (v_s != 0) {
				cout << v[0] << "\n";
				
				//원소하나남은거 삭제시 
				if (v_s == 1) {
					if (h_s == 1) {
						h.pop_back();
						v.pop_back();
						h_s--;
						v_s--;
					}
					else {
						h.erase(h.begin() + h_n);
						h_s--;
						h_n = (h_s + 1) / 2 - 1;
						v[0] = h[h_n];
					}
				}
				else {
					v.pop_front();
					v_s--;

					if (v_s % 2 == 1) {
						v_n = (v_s + 1) / 2 - 1;
						h[h_n] = v[v_n];
					}
					else
						v_n = (v_s + 1) / 2 - 1;
				}
			}
			else
				cout << -1 << "\n";
		}
		else if (s == "vfront") {
			if (v_s != 0)
				cout << v[0] << "\n";
			else
				cout << -1 << "\n";
		}
		else if (s == "vback") {
			if (v_s != 0)
				cout << v[v_s-1] << "\n";
			else
				cout << -1 << "\n";
		}
		else if (s == "vsize") {
			cout << v_s<< "\n";
		}
		else if (s == "size") {	
			if (h_s == 0 && v_s == 0)
				cout << 0<<"\n";
			else
				cout << v_s + h_s - 1 << "\n";

		}
		else if (s == "empty") {
			if (h_s == 0 && v_s == 0)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (s == "middle") {
			if (h_s==0)
				cout << -1 << "\n";
			else
				cout << h[h_n]<<"\n";
		}

		
		
		
		
	}
}