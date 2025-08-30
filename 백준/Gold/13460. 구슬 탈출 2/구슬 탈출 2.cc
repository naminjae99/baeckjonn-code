#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
#include <iomanip>

using namespace std;

int n, m;
char arr[11][11];
int order[11];
char tmp[11][11];
int re = 12;

int tl() {
	for (int i = 1; i < n - 1; i++) {
		int rd = -1;
		int bd = -1;

		//첫번째 벽과 b r 위치찾아주기
		for (int j = 1; j < m - 1; j++) {
			if (tmp[i][j] == 'R')
				rd = j;
			if (tmp[i][j] == 'B')
				bd = j;
		}

		//r b없는경우
		if (rd == -1 && bd == -1)
			continue;

		//b만있는경우 b의 인덱스-1 부터 왼쪽으로밀기 
		if (rd == -1 && bd != -1){
			int st = bd;
			for (int j = st - 1; j > 0; j--) {
				if (tmp[i][j] == '.') {
					tmp[i][bd] = '.';
					tmp[i][j] = 'B';
					bd = j;
				}
				if (tmp[i][j] == '#')
					break;
				if (tmp[i][j] == 'O')
					return -1;
			}
		}

		if (rd != -1 && bd == -1) {
			int st = rd;
			for (int j = st - 1; j > 0; j--) {
				if (tmp[i][j] == '.') {
					tmp[i][rd] = '.';
					tmp[i][j] = 'R';
					rd = j;
				}
				if (tmp[i][j] == '#')
					break;
				if (tmp[i][j] == 'O')
					return 1;
			}
		}

		//둘다있는경우
		if (rd != -1 && bd != -1) {
			if (rd < bd) {
				int flag = 0;
				int st = rd;
				for (int j = st - 1; j > 0; j--) {
					if (tmp[i][j] == '.') {
						tmp[i][rd] = '.';
						tmp[i][j] = 'R';
						rd = j;
					}
					if (tmp[i][j] == '#')
						break;
					if (tmp[i][j] == 'O') {
						tmp[i][rd] = '.';
						flag = 1;
						break;
					}
				}
				st = bd;
				for (int j = st - 1; j > 0; j--) {
					if (tmp[i][j] == '.') {
						tmp[i][bd] = '.';
						tmp[i][j] = 'B';
						bd = j;
					}
					if (tmp[i][j] == '#')
						break;
					if (tmp[i][j] == 'O')
						return -1;
				}
				if (flag == 1)
					return 1;
			}
			else {
				int st = bd;
				for (int j = st - 1; j > 0; j--) {
					if (tmp[i][j] == '.') {
						tmp[i][bd] = '.';
						tmp[i][j] = 'B';
						bd = j;
					}
					if (tmp[i][j] == '#')
						break;
					if (tmp[i][j] == 'O')
						return -1;
				}
				st = rd;
				for (int j = st - 1; j > 0; j--) {
					if (tmp[i][j] == '.') {
						tmp[i][rd] = '.';
						tmp[i][j] = 'R';
						rd = j;
					}
					if (tmp[i][j] == '#')
						break;
					if (tmp[i][j] == 'O')
						return 1;
				}
			}
		}
	}
	return 0;
}

int td() {
	for (int i = 1; i < m - 1; i++) {
		int rd = -1;
		int bd = -1;

		//첫번째 벽과 b r 위치찾아주기
		for (int j = 1; j < n - 1; j++) {
			if (tmp[j][i] == 'R')
				rd = j;
			if (tmp[j][i] == 'B')
				bd = j;
		}

		//r b없는경우
		if (rd == -1 && bd == -1)
			continue;

		//b만있는경우 b의 인덱스+1부터 내리기
		if (rd == -1 && bd != -1) {
			int st = bd;
			for (int j = st+1; j <n-1; j++) {
				if (tmp[j][i] == '.') {
					tmp[bd][i] = '.';
					tmp[j][i] = 'B';
					bd = j;
				}
				if (tmp[j][i] == '#')
					break;
				if (tmp[j][i] == 'O')
					return -1;
			}
		}

		if (rd != -1 && bd == -1) {
			int st = rd;
			for (int j = st + 1; j < n - 1; j++) {
				if (tmp[j][i] == '.') {
					tmp[rd][i] = '.';
					tmp[j][i] = 'R';
					rd = j;
				}
				if (tmp[j][i] == '#')
					break;
				if (tmp[j][i] == 'O')
					return 1;
			}
		}

		//둘다있는경우
		if (rd != -1 && bd != -1) {
			if (rd > bd) {
				int flag = 0;
				int st = rd;
				for (int j = st + 1; j < n - 1; j++) {
					if (tmp[j][i] == '.') {
						tmp[rd][i] = '.';
						tmp[j][i] = 'R';
						rd = j;
					}
					if (tmp[j][i] == '#')
						break;
					if (tmp[j][i] == 'O') {
						flag = 1;
						tmp[rd][i] = '.';
						break;
					}
				}

				st = bd;
				for (int j = st + 1; j < n - 1; j++) {
					if (tmp[j][i] == '.') {
						tmp[bd][i] = '.';
						tmp[j][i] = 'B';
						bd = j;
					}
					if (tmp[j][i] == '#')
						break;
					if (tmp[j][i] == 'O')
						return -1;
				}
				if (flag == 1)
					return 1;
			}

			else {
				int st = bd;
				for (int j = st + 1; j < n - 1; j++) {
					if (tmp[j][i] == '.') {
						tmp[bd][i] = '.';
						tmp[j][i] = 'B';
						bd = j;
					}
					if (tmp[j][i] == '#')
						break;
					if (tmp[j][i] == 'O')
						return -1;
				}
				st = rd;
				for (int j = st + 1; j < n - 1; j++) {
					if (tmp[j][i] == '.') {
						tmp[rd][i] = '.';
						tmp[j][i] = 'R';
						rd = j;
					}
					if (tmp[j][i] == '#')
						break;
					if (tmp[j][i] == 'O')
						return 1;
				}
			}
		}
	}
	return 0;
}

int tr(){
	for (int i = 1; i < n - 1; i++) {
		int rd = -1;
		int bd = -1;

		//첫번째 벽과 b r 위치찾아주기
		for (int j = 1; j < m - 1; j++) {
			if (tmp[i][j] == 'R')
				rd = j;
			if (tmp[i][j] == 'B')
				bd = j;
		}

		//r b없는경우
		if (rd == -1 && bd == -1)
			continue;

		//b만있는경우 b의 인덱스-1 부터 왼쪽으로밀기 
		if (rd == -1 && bd != -1) {
			int st = bd;
			for (int j = st +1; j <m-1; j++) {
				if (tmp[i][j] == '.') {
					tmp[i][bd] = '.';
					tmp[i][j] = 'B';
					bd = j;
				}
				if (tmp[i][j] == '#')
					break;
				if (tmp[i][j] == 'O')
					return -1;
			}
		}

		if (rd != -1 && bd == -1) {
			int st = rd;
			for (int j = st + 1; j < m - 1; j++) {
				if (tmp[i][j] == '.') {
					tmp[i][rd] = '.';
					tmp[i][j] = 'R';
					rd = j;
				}
				if (tmp[i][j] == '#')
					break;
				if (tmp[i][j] == 'O')
					return 1;
			}
		}

		//둘다있는경우
		if (rd != -1 && bd != -1) {
			if (rd < bd) {
				int st = bd;
				for (int j = st + 1; j < m - 1; j++) {
					if (tmp[i][j] == '.') {
						tmp[i][bd] = '.';
						tmp[i][j] = 'B';
						bd = j;
					}
					if (tmp[i][j] == '#')
						break;
					if (tmp[i][j] == 'O')
						return -1;
				}
				st = rd;
				for (int j = st + 1; j < m - 1; j++) {
					if (tmp[i][j] == '.') {
						tmp[i][rd] = '.';
						tmp[i][j] = 'R';
						rd = j;
					}
					if (tmp[i][j] == '#')
						break;
					if (tmp[i][j] == 'O')
						return 1;
				}

			}
			else {
				int st = rd;
				int flag = 0;
				for (int j = st + 1; j < m - 1; j++) {
					if (tmp[i][j] == '.') {
						tmp[i][rd] = '.';
						tmp[i][j] = 'R';
						rd = j;
					}
					if (tmp[i][j] == '#')
						break;
					if (tmp[i][j] == 'O') {
						tmp[i][rd] = '.';
						flag=1;
						break;
					}
				}
				st = bd;
				for (int j = st + 1; j < m - 1; j++) {
					if (tmp[i][j] == '.') {
						tmp[i][bd] = '.';
						tmp[i][j] = 'B';
						bd = j;
					}
					if (tmp[i][j] == '#')
						break;
					if (tmp[i][j] == 'O')
						return -1;
				}
				if (flag == 1)
					return 1;
			}
		}
	}
	return 0;
}
int tu() {
	for (int i = 1; i < m - 1; i++) {
		int rd = -1;
		int bd = -1;

		//첫번째 벽과 b r 위치찾아주기
		for (int j = 1; j < n - 1; j++) {
			if (tmp[j][i] == 'R')
				rd = j;
			if (tmp[j][i] == 'B')
				bd = j;
		}

		//r b없는경우
		if (rd == -1 && bd == -1)
			continue;

		//b만있는경우 b의 인덱스+1부터 내리기
		if (rd == -1 && bd != -1) {
			int st = bd;
			for (int j = st - 1; j >0; j--) {
				if (tmp[j][i] == '.') {
					tmp[bd][i] = '.';
					tmp[j][i] = 'B';
					bd = j;
				}
				if (tmp[j][i] == '#')
					break;
				if (tmp[j][i] == 'O')
					return -1;
			}
		}

		if (rd != -1 && bd == -1) {
			int st = rd;
			for (int j = st - 1; j > 0; j--) {
				if (tmp[j][i] == '.') {
					tmp[rd][i] = '.';
					tmp[j][i] = 'R';
					rd = j;
				}
				if (tmp[j][i] == '#')
					break;
				if (tmp[j][i] == 'O')
					return 1;
			}
		}

		//둘다있는경우
		if (rd != -1 && bd != -1) {
			if (rd > bd) {
				int st = bd;
				for (int j = st - 1; j > 0; j--) {
					if (tmp[j][i] == '.') {
						tmp[bd][i] = '.';
						tmp[j][i] = 'B';
						bd = j;
					}
					if (tmp[j][i] == '#')
						break;
					if (tmp[j][i] == 'O')
						return -1;
				}
				st = rd;
				for (int j = st - 1; j > 0; j--) {
					if (tmp[j][i] == '.') {
						tmp[rd][i] = '.';
						tmp[j][i] = 'R';
						rd = j;
					}
					if (tmp[j][i] == '#')
						break;
					if (tmp[j][i] == 'O')
						return 1;
				}

			}
			else {
				int flag = 0;
				int st = rd;
				for (int j = st - 1; j > 0; j--) {
					if (tmp[j][i] == '.') {
						tmp[rd][i] = '.';
						tmp[j][i] = 'R';
						rd = j;
					}
					if (tmp[j][i] == '#')
						break;
					if (tmp[j][i] == 'O') {
						flag = 1;
						tmp[rd][i] = '.';
						break;
					}
						
				}
				st = bd;
				for (int j = st - 1; j > 0; j--) {
					if (tmp[j][i] == '.') {
						tmp[bd][i] = '.';
						tmp[j][i] = 'B';
						bd = j;
					}
					if (tmp[j][i] == '#')
						break;
					if (tmp[j][i] == 'O')
						return -1;
				}
				if (flag == 1)
					return 1;
			}
		}
	}
	return 0;
}
void f(int dep) {
	if (dep > 10)
		return;

	if (dep > 0) {
		//dep=돌려야할 횟수
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tmp[i][j] = arr[i][j];
			}
		}
		int tmpr=-1;

		for (int i = 0; i < dep; i++) {
			if (order[i] == 0) {
				int a = tl();
				if (a== -1)
					return;
				tmpr = max(tmpr,a);
			}
			if (order[i] == 1) {
				int a = td();
				if (a == -1)
					return;
				tmpr = max(tmpr, a);
			}
			if (order[i] == 2) {
				int a = tr();
				if (a == -1)
					return;
				tmpr = max(tmpr, a);
			}
			if (order[i] == 3) {
				int a = tu();
				if (a == -1)
					return;
				tmpr = max(tmpr, a);
			}
		}
		/*
		cout << "조합\n";
		for (int i = 0; i < dep; i++) {
			cout << order[i]<<" ";
		}
		cout << "\n";
		cout << "상태\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << tmp[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
		cout << "\n";
		*/

		if (tmpr == 1) {
			re = min(re, dep);
		}
	}

	for (int i = 0; i < 4; i++) {
		order[dep] = i;
		f(dep + 1);
	}
		

}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j];
		}
	}
	f(0);
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = arr[i][j];
		}
	}
	tl();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << tmp[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	if (re == 12)
		cout << -1;
	else
		cout << re;

}