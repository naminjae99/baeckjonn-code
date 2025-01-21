#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<memory.h>
#include<iomanip>
using namespace std;


int arr[10][10];
int n, i, j, x, y, t, flag;
int tmp_point, re;
int point;
queue <int> q;
int si;
int cnt = 1;

void pri() {
	for (int a = 0; a < 10; a++) {
		for (int b = 0; b < 10; b++) {
			cout << setw(3) << arr[a][b];
		}
		cout << "\n";
	}
	cout << "\n";

}
void drop_bl() {
	for (j = 8; j >= 4; j--) {
		for (i = 0; i < 4; i++) {
			if (arr[i][j]) {
				if (i < 3 && arr[i + 1][j] == arr[i][j]) {
					int st = j;

					while (1) {
						st++;
						if (st >= 10) {
							st--;
							break;
						}
						if (arr[i][st] == 0 && arr[i + 1][st] == 0)
							continue;
						else {
							st--;
							break;
						}

					}
					if (j == st) {
						i++;
						continue;
					}
					if (st == j) {
						continue;
					}
					int tt = arr[i][j];
					arr[i][j] = arr[i + 1][j] = 0;
					arr[i][st] = arr[i + 1][st] =tt;
					

				}
				else if (i > 1 && arr[i][j] == arr[i - 1][j])
					continue;
				else if (j < 9 && arr[i][j] == arr[i][j + 1])
					continue;
				else if (j > 4 && arr[i][j] == arr[i][j - 1]) {
					int st = j;

					while (1) {
						st++;
						if (st >= 10) {
							st--;
							break;
						}
						if (arr[i][st] == 0)
							continue;
						else {
							st--;
							break;
						}

					}
					if (st == j) {
						continue;
					}
					int tt = arr[i][j];
					arr[i][j] = arr[i][j - 1] = 0;
					arr[i][st] = arr[i][st - 1] = tt;


				}
				else {
					int st = j;

					while (1) {
						st++;
						if (st >= 10) {
							st--;
							break;
						}
						if (arr[i][st] == 0)
							continue;
						else {
							st--;
							break;
						}

					}
					if (st == j)
						continue;
					int tt = arr[i][j];
					arr[i][j] = 0;
					arr[i][st] = tt;
				

				}
			}


		}
	}
}
int point_bl() {
	tmp_point = 0;
	for (j = 4; j < 10; j++) {
		flag = 0;
		for (i = 0; i < 4; i++) {
			if (arr[i][j] == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			for (i = 0; i < 4; i++) {
				if (j > 4) {
					if (arr[i][j] == arr[i][j - 1]) {
						arr[i][j - 1] = cnt++;
						arr[i][j] = 0;
					}
				}
				if (j < 9) {
					if (arr[i][j] == arr[i][j + 1]) {
						arr[i][j + 1] = cnt++;
						arr[i][j] = 0;
					}
				}
				arr[i][j] = 0;
			}
			tmp_point++;
		}
	}

	if (tmp_point > 0)
		drop_bl();

	return tmp_point;
}
//
int check_bl() {
	x = 0;
	for (j = 4; j < 6; j++) {
		for (i = 0; i < 4; i++) {
			if (arr[i][j]) {
				if (j == 4)
					x = -1;
				if (j == 5) {
					if (x == -1)
						x = 2;
					else
						x = 1;
				}
				break;
			}
		}
	}
	return x;
}
void spe_bl() {
	for (i = 0; i < 4; i++) {
		if (arr[i][8] != 0 && arr[i][9] == arr[i][8]) {
			arr[i][8] = cnt++;
		}
	}
	for (j = 9; j >= 6; j--) {
		for (i = 0; i < 4; i++) {
			arr[i][j] = arr[i][j - 1];
		}
	}
	for (i = 0; i < 4; i++) {
		arr[i][5] = 0;
	}
}
void spe_bl2() {
	for (i = 0; i < 4; i++) {

		if (arr[i][7] != 0 && arr[i][7] == arr[i][8]) {
			arr[i][7] = cnt++;
		}
	}
	for (j = 9; j >= 6; j--) {
		for (i = 0; i < 4; i++) {
			arr[i][j] = arr[i][j - 2];
		}
	}
	for (i = 0; i < 4; i++) {
		arr[i][4] = arr[i][5] = 0;
	}
}

int check_gr() {
	x = 0;
	for (j = 4; j < 6; j++) {
		for (i = 0; i < 4; i++) {
			if (arr[j][i]) {
				if (j == 4)
					x = -1;
				if (j == 5) {
					if (x == -1)
						x = 2;
					else
						x = 1;
				}
				break;
			}
		}
	}
	return x;
}
void spe_gr() {
	for (i = 0; i < 4; i++) {
		if (arr[9][i] != 0 && arr[9][i] == arr[8][i]) {
			arr[8][i] = cnt++;
		}
	}
	for (j = 9; j >= 6; j--) {
		for (i = 0; i < 4; i++) {
			arr[j][i] = arr[j - 1][i];
		}
	}
	for (i = 0; i < 4; i++) {
		arr[5][i] = 0;
	}
}
void spe_gr2() {
	for (i = 0; i < 4; i++) {
		if (arr[8][i] != 0 && arr[7][i] == arr[8][i]) {
			arr[7][i] = cnt++;
		}
	}
	for (j = 9; j >= 6; j--) {
		for (i = 0; i < 4; i++) {
			arr[j][i] = arr[j - 2][i];
		}
	}
	for (i = 0; i < 4; i++)
		arr[4][i] = arr[5][i] = 0;
}
void drop_gr() {

	for (j = 8; j >= 4; j--) {
		for (i = 0; i < 4; i++) {
			if (arr[j][i] > 0) {
				if (arr[j - 1][i] == arr[j][i]) {
					int st = j;
					while (1) {
						st++;
						if (st >= 10) {
							st--;
							break;
						}
						if (arr[st][i] == 0)
							continue;
						else {
							st--;
							break;
						}

					}
					if (st == j) {
						continue;
					}
					int tt = arr[j][i];
					arr[j][i] = arr[j - 1][i] = 0;
					arr[st][i] = arr[st - 1][i] = tt;
					

				}
				else if (j<9&& arr[j][i] == arr[j + 1][i])
					continue;
				else if (i < 3 && arr[j][i] == arr[j][i + 1]) {
					int st = j;

					while (1) {
						st++;
						if (st >= 10) {
							st--;
							break;
						}
						if (arr[st][i] == 0 && arr[st][i + 1] == 0)
							continue;
						else {
							st--;
							break;
						}

					}
					if (st == j) {
						i++;
						continue;
					}
					int tt = arr[j][i];
					arr[j][i] = 0;
					arr[j][i + 1] = 0;
					arr[st][i] =tt;
					arr[st][i + 1] = tt;
					

				}
				else if (i > 0 && arr[j][i] == arr[j][i - 1])
					continue;
				else {
					int st = j;
					while (1) {
						st++;
						if (st >= 10) {
							st--;
							break;
						}
						if (arr[st][i] == 0)
							continue;
						else {
							st--;
							break;
						}

					}
					int tt = arr[j][i];
					arr[j][i] = 0;
					arr[st][i] =tt;


				}
			}
		}
	}
}

int point_gr() {
	tmp_point = 0;
	for (j = 4; j < 10; j++) {
		flag = 0;
		for (i = 0; i < 4; i++) {
			if (arr[j][i] == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			for (i = 0; i < 4; i++) {
				if (j > 4) {
					if (arr[j][i] == arr[j - 1][i]) {
						arr[j - 1][i] = cnt++;
						arr[j][i] = 0;
					}
				}
				if (j < 9) {
					if (arr[j][i] == arr[j + 1][i]) {
						arr[j + 1][i] = cnt++;
						arr[j][i] = 0;
					}
				}
				arr[j][i] = 0;
			}
			tmp_point++;
		}
	}

	if (tmp_point > 0)
		drop_gr();

	return tmp_point;
}
///////////////
void blue(int h) {
	flag = 0;
	for (j = 4; j < 10; j++) {
		if (arr[h][j]) {
			arr[h][j - 1] = cnt++;
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		arr[h][9] = cnt++;
	}
}
void green(int w) {
	flag = 0;
	for (j = 4; j < 10; j++) {
		if (arr[j][w]) {
			arr[j - 1][w] = cnt++;
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		arr[9][w] = cnt++;
	}
}
////////////////////////////////
void blue2(int h) {
	flag = 0;
	for (j = 4; j < 10; j++) {
		if (arr[h][j]) {
			arr[h][j - 1] = arr[h][j - 2] = cnt++;
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		arr[h][9] = arr[h][8] = cnt++;
	}
}
void green2(int w) {
	flag = 0;
	for (j = 4; j < 10; j++) {
		if (arr[j][w] || arr[j][w + 1]) {
			arr[j - 1][w] = arr[j - 1][w + 1] = cnt++;
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		arr[9][w] = arr[9][w + 1] = cnt++;
	}
}
////////////////////////////////
void blue3(int h) {
	flag = 0;
	for (j = 4; j < 10; j++) {
		if (arr[h][j] || arr[h + 1][j]) {
			arr[h][j - 1] = arr[h + 1][j - 1] = cnt++;
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		arr[h][9] = arr[h + 1][9] = cnt++;
	}


}
void green3(int w) {
	flag = 0;
	for (j = 4; j < 10; j++) {
		if (arr[j][w]) {
			arr[j - 1][w] = arr[j - 2][w] = cnt++;
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		arr[9][w] = arr[8][w] = cnt++;
	}
}

int main() {
	cin >> n;
	while (n--) {
		cin >> t >> x >> y;
		if (t == 1) {
			blue(x);
			green(y);
		}
		else if (t == 2) {
			blue2(x);
			green2(y);
		}
		else {
			blue3(x);
			green3(y);
		}

		while (1) {
			point = point_bl();
			if (point > 0) {
				re += point;
				continue;
			}
			else {
				if (check_bl() == 1)
					spe_bl();
				else if (check_bl() == 2 || check_bl() == -1) {
					spe_bl2();
				}
				break;
			}
		}
		while (1) {
			point = point_gr();
			if (point > 0) {
				re += point;
				continue;
			}
			else {
				if (check_gr() == 1)
					spe_gr();
				else if (check_gr() == 2 || check_gr() == -1) {
					spe_gr2();
				}
				break;
			}
		}

	}
	x = 0;
	for (i = 0; i < 4; i++) {
		for (j = 6; j < 10; j++) {
			if (arr[i][j]) {
				x++;

			}
			if (arr[j][i]) {
				x++;

			}
		}
	}
	cout << re << "\n" << x;
}


