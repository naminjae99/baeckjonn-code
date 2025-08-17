#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
#include <string>
#include <memory.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <string.h>
#include <set>
#include <iomanip>
#include <unordered_set>
#include <map>
#include<cfloat>
#include<sstream>
#include<numeric>
#include <limits>
using namespace std;
using ll = long long;



int n, m, k;

string s;
int u, f;
struct info {
	string per;
	string owner;
	string owner_gr;
};
unordered_map<string, set<string>> gr;

unordered_map<string, info>file;

bool isAbleToRead, isAbleToWrite, isAbleToExecute;
void confirm_Permission(int Permission) {
	isAbleToRead = false;
	isAbleToWrite = false;
	isAbleToExecute = false;
	if (Permission == 1) {
		isAbleToExecute = true;
	}
	else if (Permission == 2) {
		isAbleToWrite = true;
	}
	else if (Permission == 3) {
		isAbleToExecute = true;
		isAbleToWrite = true;
	}
	else if (Permission == 4) {
		isAbleToRead = true;
	}
	else if (Permission == 5) {
		isAbleToRead = true;
		isAbleToExecute = true;
	}
	else if (Permission == 6) {
		isAbleToRead = true;
		isAbleToWrite = true;
	}
	else if (Permission == 7) {
		isAbleToRead = true;
		isAbleToWrite = true;
		isAbleToExecute = true;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> u >> f;
	cin.ignore();

	for (int i = 0; i < u; i++) {
		getline(cin, s);
		
		string s1,s2;
		vector<string> tmp;
		string sum = "";
		s1 = "";
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				s1 = sum;
				sum = "";
			}
			else
				sum += s[i];
		}
		s2 = sum;
		if (s1 == "") {
			gr[s2].insert(s2);
			continue;
		}
		else {
			gr[s1].insert(s1);
			sum = "";
			for (int i = 0; i < s2.size(); i++) {
				if (s2[i] == ',') {
					tmp.push_back(sum);
					sum = "";
				}
				else {
					sum += s2[i];
				}
			}
			tmp.push_back(sum);

			gr[s1].insert(s1);
			for (int i = 0; i < tmp.size(); i++) {
				gr[tmp[i]].insert(s1);
			}
		}
		
	}

	for (int i = 0; i < f; i++) {
		string a, b, c, d;
		cin >> a >> b >> c >> d;
		file[a] = { b,c,d };

	}
	int q;
	cin >> q;

	while (q--) {
		string  User_Name, File_Name, Operation;
		cin >> User_Name >> File_Name >> Operation;
		string Owner = file[File_Name].owner;
		string Owner_Group = file[File_Name].owner_gr;
		string Permission = file[File_Name].per;

		if (Owner == User_Name) {
			confirm_Permission(Permission[0] - '0');
		}
		else {
			bool isInGroup = false;
			if (gr.find(Owner_Group) != gr.end()) {
				if (gr[Owner_Group].find(User_Name) != gr[Owner_Group].end())
					isInGroup = 1;
			}

			if (isInGroup) {
				confirm_Permission(Permission[1] - '0');
			}
			else {
				confirm_Permission(Permission[2] - '0');
			}
		}
		if (((Operation == "R") && (isAbleToRead)) || ((Operation == "W") && (isAbleToWrite)) || ((Operation == "X") && (isAbleToExecute))) {
			cout << "1\n";
		}
		else {
			cout << "0\n";
		}
	}

}


