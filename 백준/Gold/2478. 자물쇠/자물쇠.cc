#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include<iostream>
#include <string>
#include<deque>
#include <memory.h>
#include<vector>
#include<set>
#include<queue>
#include <cassert>
#include<algorithm>

using namespace std;
int n;
deque<int> arr;
int k1, p, q, k2;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		arr.push_back(x);
	}
	
	int flag = 0;
	while (flag == 0) {
		p = 0;
		q = 0;
		k1 = 0;
		k2++;
		arr.push_front(arr.back());
		arr.pop_back();

		for (int i = 0; i < n - 1; i++) {
			if (arr[i] == n)
				continue;
			if (arr[i + 1] == arr[i] + 1)
				continue;
			else {
				p = i + 2;
				for (int j = i + 2; j < n; j++) {
					if (arr[i] + 1 == arr[j]) {
						q = j + 1;
						break;
					}
				}
				break;
			}
		}
		if (p == 0 || q == 0) {
			for (int i = 0; i < n - 1; i++) {
				
				if (arr[i + 1] != arr[i] - 1)
					continue;
				else {
					p = i + 1;
					for (int j = i + 1; j < n; j++) {
						if (arr[i] - (j - i) != arr[j]) {
							q = j;
							break;
						}
						else
							q = j + 1;
					}
					break;
				}
			}
		}

		if (q == n)
			k1 = arr[p - 1];
		else
			k1 = arr.back();
		if (k1 == n || q == 0 || p == 0 || !(q > p)) {
			continue;
		}

		else {
			
			int tmp[505] = { 0, };
			for (int i = 0; i < n; i++)
				tmp[i] = arr[i];
			for (int i = 0; i <= q - p; i++)
				tmp[i + p-1] = arr[q-1 - i];

			int ff = 0;

			for (int i = 0; i < n; i++) {
				int x = (n - k1 + i)%n;
				if (tmp[x] != i + 1) {
					ff = 1;
					break;
				}
			}
			if (ff)

				continue;
			cout << k1 << "\n" << p << " " << q << "\n" << k2;
			break;
		}
	}
	

	

}