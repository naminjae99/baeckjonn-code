#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
#include <iomanip>

using namespace std;

int arr[6][6][6];
int order[6];
int m = 987654321;
int tmp[6][6][6];
int oritmp[6][6][6];
int dx[6] = { 0,0,-1,1,0,0 };
int dy[6] = { 0,0,0,0,-1,1 };
int dz[6] = { -1,1,0,0,0,0 };

void copy(int a, int b) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            tmp[a][i][j] = oritmp[b][i][j];
        }
    }
}
void turn(int num,int cnt) {
    if (cnt == 0)
        return;

    if (cnt == 1) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                tmp[num][j][4-i] = arr[num][i][j];
            }
        }
    }
    if (cnt == 2) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                tmp[num][4-i][4 - j] = arr[num][i][j];
            }
        }
    }
    if (cnt == 3) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                tmp[num][4-j][i] = arr[num][i][j];
            }
        }
    }
}

void cal() {
    if (tmp[0][0][0] == 0 || tmp[4][4][4] == 0)
        return;

    queue <pair<pair<int, int>, pair<int,int>>> q;
    q.push({ {0,0},{0,0} });
    int vis[6][6][6]={0,};

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int w = 0; w < 5; w++) {
                vis[i][j][w]=0;
            }
        }
    }

    vis[0][0][0] = 1;

    while (!q.empty()) {
        int z = q.front().first.first;
        int x = q.front().first.second;
        int y = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();

        if (x == 4 && y == 4 && z == 4) {
            m = min(m, cnt);
            return;
        }

        for (int i = 0; i < 6; i++) {
            int nz = z + dz[i];
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx>4 || ny < 0 || ny>4 || nz < 0 || nz>4)
                continue;
            if (vis[nz][nx][ny] == 1 || tmp[nz][nx][ny] == 0)
                continue;
            vis[nz][nx][ny] = 1;
            q.push({ {nz,nx},{ny,cnt + 1} });
        }
    }
}
void dfs(int dep) {
    if (dep == 5){
     
        

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int w = 0; w < 5; w++) {
                    tmp[i][j][w]=arr[i][j][w];
                }
            }
        }

        for (int i = 0; i < 5; i++) {
            turn(i,order[i]);
        }
     
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int w = 0; w < 5; w++) {
                    oritmp[i][j][w] = tmp[i][j][w];
                }
            }
        }
        
      
        for (int a = 0; a < 5; a++) {
            copy(0, a);
            for (int b = 0; b < 5; b++) {
                if (a == b)
                    continue;
                copy(1,b);
                for (int c = 0; c < 5; c++) {
                    if (a == c||b==c)
                        continue;
                    copy(2,c);
                    for (int d = 0; d < 5; d++) {
                        if (a == d || b == d||c==d)
                            continue;
                        copy(3,d);;
                        for (int e = 0; e < 5; e++) {
                            if (a == e || b == e||c==e||d==e)
                                continue;
                            copy(4,e);
                           
                            cal();
                        }
                    }
                }
            }
        }
     /*
        for (int i = 0; i < 5; i++) {
            cout << "z축: " << i << "\n";

            for (int j = 0; j < 5; j++) {
                for (int w = 0; w < 5; w++) {
                    cout<<tmp[i][j][w]<<" ";
                }
                cout << "\n";
            }
            cout << "\n";
        }

        */


       

        return;
    }

    for (int i = 0; i < 4; i++) {
        order[dep] = i;
        dfs(dep + 1);
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int w = 0; w < 5; w++) {
                cin >> arr[i][j][w];
            }
        }
    }
    dfs(0);

    if (m == 987654321)
        cout << -1;
    else 
        cout << m;
   
}