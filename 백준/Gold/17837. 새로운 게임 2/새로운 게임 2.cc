#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <memory.h>
#include <iomanip> 

using namespace std;

struct h {
    int x;
    int y;
    int d;
};

int dx[5] = { 0,0,0,-1,1};
int dy[5] = { 0,1,-1,0,0 };
int n, k;
int arr[13][13];
//맵위에있는 말의 번호들 
vector <int> horse[13][13];
//말의 정보
vector <h> hor;
int t;
int fflag;

int endgame() {
    int flag = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (horse[i][j].size() > 3) {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 1)
        return 1;
    else
        return 0;
}

void changed(int num, int dir) {
    if (dir == 1)
        hor[num].d = 2;
    else if (dir == 2)
        hor[num].d = 1;
    else if (dir == 3)
        hor[num].d = 4;
    else if (dir == 4)
        hor[num].d = 3;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];
    for (int i = 0; i < k; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        hor.push_back({ x,y,d });
        horse[x][y].push_back(i);
    }

    while (1){
    
        t++;
        if (t > 1000) {
            t = -1;
            break;
        }
        //cout << "현재시간: " << t << "--------------------\n";

        //말이동
        for (int i = 0; i < k; i++) {
            int x = hor[i].x;
            int y = hor[i].y;
            int d = hor[i].d;
            int nx = x + dx[d];
            int ny = y + dy[d];

            //범위밖
            if (nx<1 || nx>n || ny<1 || ny>n) {
                changed(i, d);
                d = hor[i].d;
                nx = x + dx[d];
                ny = y + dy[d];
                if (arr[nx][ny] == 2) {
                    continue;
                }
                
                else {
                    i--;
                    continue;
                }
            }
            //파랑
            else if (arr[nx][ny] == 2) {
                changed(i, d);
                d = hor[i].d;
                nx = x + dx[d];
                ny = y + dy[d];
                if (nx<1 || nx>n || ny<1 || ny>n) {
                    continue;
                }
                if (arr[nx][ny] == 2)
                    continue;

                i--;
                continue;
            }

            //하얀
            if (arr[nx][ny] == 0) {           
                int st = -1;
                for (int j = 0; j < horse[x][y].size(); j++) {
                    if (horse[x][y][j] == i) {
                        st = j;
                        break;
                    }
                }
                //x,y 에있던 모든말이 nx,ny로 이동
                for (int j = st; j < horse[x][y].size(); j++) {
                    hor[horse[x][y][j]].x = nx;
                    hor[horse[x][y][j]].y = ny;
                    horse[nx][ny].push_back(horse[x][y][j]);
                }
                horse[x][y].erase(horse[x][y].begin() + st, horse[x][y].end());
            }

            //빨강
            if (arr[nx][ny] == 1) {
                int st = -1;
                for (int j = 0; j < horse[x][y].size(); j++) {
                    if (horse[x][y][j] == i) {
                        st = j;
                        break;
                    }
                }
                //x,y 에있던 모든말이 nx,ny로 거꾸로 이동
                for (int j = horse[x][y].size()-1; j >=st; j--) {
                    hor[horse[x][y][j]].x = nx;
                    hor[horse[x][y][j]].y = ny;
                    horse[nx][ny].push_back(horse[x][y][j]);
                }
                horse[x][y].erase(horse[x][y].begin() + st, horse[x][y].end());
            }
           
           
            /*
            cout << i << "번째 말이동후 말갯수\n";
            for (int a = 1; a <= n; a++) {
                for (int b = 1; b <= n; b++) {
                    cout<<horse[a][b].size() << " ";
                }
                cout << "\n";
            }
            cout << i << "번째 말이동후 말이 올라타있는순서\n";
            for (int a = 1; a <= n; a++) {
                for (int b = 1; b <= n; b++) {
                    if (horse[a][b].size() == 0)
                        continue;
                    cout << a<<" , " << b << "에 있는 말의 순서";
                    for (int c = 0; c < horse[a][b].size(); c++) {
                        cout << horse[a][b][c] << " ";
                    }
                }
                cout << "\n";
            }
            cout << "말 상태\n";
            for (int a = 0; a < k; a++) {
                cout << a << "번째말( " << hor[a].x << " , " << hor[a].y << " , " << hor[a].d << " )\n";
            }*/
            if (endgame()) {
                fflag = 1;
                break;
            }
        }
        if (fflag==1)
            break;
    }

    cout << t;
}