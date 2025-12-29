#include <iostream>
#include <deque>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, l;

// 사과여부
int arr[101][101];
int flag;

//꼬리저장 벡터
deque <pair<int, int>> tail;

int dir;

//시간 방향
deque <pair<int, char>> v;

//시간
int t;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };




int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	cin >> k;

	//사과놓기
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		arr[x - 1][y - 1] = 1;
	}

	cin >> l;

	for (int i = 0; i < l; i++) {
		int a;
		char b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	//시작지점은 머리이자 꼬리

	tail.push_back({ 0,0 });

	while (1) {


		t++;


		int x = tail.back().first;
		int y = tail.back().second;

		int nx = x + dx[dir];
		int ny = y + dy[dir];

		//벽만날떄
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
			flag = 1;
			break;
		}

		//자기 몸만날떄
		for (int i = 0; i < tail.size(); i++) {
			int tmpx = tail[i].first;
			int tmpy = tail[i].second;

			if (nx == tmpx && ny == tmpy) {
				flag = 1;
				break;
			}
		}

		if (flag == 1)
			break;

		//사과있으면
		if (arr[nx][ny] == 1) {
			//새 머리
			tail.push_back({ nx,ny });
			arr[nx][ny] = 0;
		}
		else {
			//맨끝 꼬리삭제
			tail.pop_front();
			tail.push_back({ nx,ny });
		}



		//시간마다 방향변환
		if (v.size() >= 1) {
			if (t == v[0].first) {

				if (v[0].second == 'D') {
					dir = (dir + 1) % 4;
				}

				else {
					dir = (dir + 3) % 4;
				}

				v.pop_front();
			}
		}



	}

	//끝난경우
	if (flag == 1) {
		cout << t;
		return 0;
	}

}