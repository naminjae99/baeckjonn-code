#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
#include <string>
#include <memory.h>
#include <vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
#include<string.h>
#include<set>
#include<iomanip>
#include<unordered_set>
#include<map>
using namespace std;



int n, m;
struct info {
	string name;
	info* par;
	map<string,info*>al;
	set<string>ph;
}node[100005];
int idx;

unordered_map<string, info*>mp;

info* root;
info* cur;

pair<int, int> delf(info* st) {
	
	pair<int, int> re = { 1,st->ph.size() };
	for (auto c : st->al) {
		pair<int,int> tmp= delf(c.second);
		re.first += tmp.first;
		re.second += tmp.second;
	}
	return re;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	string cmd, s;

	cur=root=mp["album"] = &node[idx++];
	root->name = "album";
	

	

	while (n--) {
		cin >> cmd >> s;
		if (cmd[0] == 'm') {
			if (cur->al.find(s)!=cur->al.end())
				cout << "duplicated album name\n";
			else {
				info* add = &node[idx++];
				add->name = s;
				add->par = cur;

				cur->al[s] = add;
			}
		}

		else if (cmd[0] == 'r') {
			
			if (s == "-1") {
				if (cur->al.size()==0) {
					cout << 0 << " " << 0 << "\n";
				}
				else {
					auto del = cur->al.begin();
					
					pair<int,int> re=delf(del->second);
					cout << re.first << " " << re.second << "\n";
					cur->al.erase(del->first);
				}
			}
			else if (s == "0") {
			
				pair<int, int> re = delf(cur);

				cout << re.first-1 << " " << re.second-cur->ph.size() << "\n";
				cur->al.clear();

			}
			else if (s == "1") {
				if (cur->al.begin() == cur->al.end()) {
					cout << 0 << " " << 0 << "\n";
				}
				else {
					auto del = cur->al.rbegin();
					pair<int, int> re = delf(del->second);
					cout << re.first << " " << re.second << "\n";
					cur->al.erase(del->first);
				}
			}
			else {
				if (cur->al.find(s) == cur->al.end())
					cout << 0 << " " << 0 << "\n";
				else {
					auto del = cur->al[s];
					
					pair<int, int> re = delf(del);
					cout << re.first << " " << re.second << "\n";
					cur->al.erase(s);

			
				}
			}
		}
		else if (cmd[0] == 'i') {
			if (cur->ph.find(s) == cur->ph.end())
				cur->ph.insert(s);
			else
				cout << "duplicated photo name\n";
		}
		else if(cmd[0]=='d') {
		
			if (s == "-1") {
				if (cur->ph.begin() != cur->ph.end()) {
					cur->ph.erase(cur->ph.begin());
					cout << 1 << "\n";
				}
				else
					cout << 0 << "\n";
			}
			else if (s == "0") {
				cout << cur->ph.size()<<"\n";
				cur->ph.clear();
			}
			else if (s == "1") {
				if (cur->ph.size()>0) {
					cur->ph.erase(*cur->ph.rbegin());
					cout << 1 << "\n";
				}
				else
					cout << 0 << "\n";
			}
			else {
				if (cur->ph.find(s) == cur->ph.end())
					cout << 0 << "\n";
				else {
					cout << 1 << "\n";
					cur->ph.erase(s);
				}
			}
		}
		else {
			if (s == "/")
				cur = root;
			else if (s == "..") {
				if (cur->par != nullptr)
					cur = cur->par;
			}
			else {
				if (cur->al.find(s) != cur->al.end())
					cur = cur->al[s];
			}
			cout << cur->name << "\n";
		}
	}
}