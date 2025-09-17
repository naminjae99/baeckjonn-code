#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

struct fish {
	int num;
	int dir;
};

struct state {
	int x;
	int y;
	int dir;
};
fish arr[4][4];


state shark;


int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
int result=-1;


void fishmove(fish carr[4][4],state sh) {
	for (int i = 1; i <= 16; i++) {
		int x = -1;
		int y = -1;
		int dir = -1;

		for (int a = 0; a < 4; a++) {
			for (int b = 0; b < 4; b++) {
				if (carr[a][b].num == i) {
					x = a;
					y = b;
					dir = carr[a][b].dir;
					break;
				}
			}
			if (x != -1)
				break;
		}

		// 해당 숫자에 물고기가 없는 경우
		if (x == -1)
			continue;

		for (int j = 0; j < 8; j++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			// 범위 밖이거나 상어가 있는 경우 각도 45도 회전
			if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4 || (nx == sh.x && ny == sh.y)) {
				dir = (dir + 1) % 8;
				continue;
			}

			carr[x][y].dir = dir;
			// Swap the fish correctly
			swap(carr[x][y], carr[nx][ny]);

			
			break;
		}
	}
}


void dfs(state sh,int sum) {
	result = max(result, sum);

	fish tmp[4][4];
	memcpy(tmp, arr, sizeof(arr));
	//tmp=물고기이동전

	fishmove(arr, sh);

	//arr배열이 섞인상태

	for (int i = 1; i < 4; i++) {
		int x = sh.x;
		int y = sh.y;
		int d = sh.dir;

		int nx = x + dx[d] * i;
		int ny = y + dy[d] * i;

		//범위밖이면 집가기
		if (nx < 0 || nx>3 || ny < 0 || ny>3)
			break;

		else {
			if (arr[nx][ny].num == 0)
				continue;

			int dd = arr[nx][ny].dir;
			int size = arr[nx][ny].num;

			arr[nx][ny].num = 0;
			state newsh = { nx,ny,dd };

			dfs(newsh, sum + size);

			arr[nx][ny].num = size;
		
		}
	}
	memcpy(arr, tmp, sizeof(tmp));

}

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;
			arr[i][j].num = a;
			arr[i][j].dir =b-1;
		}
	}
	shark = { 0,0,arr[0][0].dir };

	int startsum = arr[0][0].num;
	arr[0][0].num = 0;

	
	dfs(shark, startsum);

	cout << result;
}
