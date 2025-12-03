#include <bits/stdc++.h>
using namespace std;
using ll = long long;

typedef array<int,2> pr;
typedef array<int,4> ip4;
typedef array<long long,4> lp4;

const int MAX = 501;
const ll LINF = (ll)4e18;

int A[MAX][MAX];
int B[MAX][MAX];
ll D[MAX][MAX][2];
ip4 par[MAX][MAX][2];
pr go[4] = {{1,0},{0,1},{-1,0},{0,-1}};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int R[2], C[2];
    cin >> N >> R[0] >> C[0] >> R[1] >> C[1];

    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin >> A[i][j];
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin >> B[i][j];

    // init
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++){
            D[i][j][0] = D[i][j][1] = LINF;
        }

    // pq element: {cost, x, y, dir}
    priority_queue<lp4, vector<lp4>, greater<lp4>> pq;

    // start from destination (R1,C1) — 역다익스트라
    D[R[1]][C[1]][0] = D[R[1]][C[1]][1] = (ll)A[R[1]][C[1]];
    pq.push({ D[R[1]][C[1]][0], R[1], C[1], 0 });
    pq.push({ D[R[1]][C[1]][1], R[1], C[1], 1 });
    par[R[1]][C[1]][0] = {-1,-1,-1,-1};
    par[R[1]][C[1]][1] = {-1,-1,-1,-1};

    while(!pq.empty()){
        lp4 cur = pq.top(); pq.pop();
        ll cost = cur[0];
        int x = (int)cur[1];
        int y = (int)cur[2];
        int dir = (int)cur[3];
        if (D[x][y][dir] < cost) continue;

        for(auto mv : go){
            int nx = x + mv[0];
            int ny = y + mv[1];
            int z = (mv[0] == 0 ? 1 : 0); // 1: horizontal, 0: vertical
            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;

            // 안전하게 중간연산은 __int128로
            __int128 prev_without_A = ( (__int128)cost - (__int128)A[x][y] );
            __int128 mult = (z == dir ? 1 : (ll)B[x][y]);
            __int128 tmp = prev_without_A * mult + (__int128)A[nx][ny] + (__int128)A[x][y];
            ll CS;
            if (tmp > (__int128)LLONG_MAX) CS = LLONG_MAX;
            else if (tmp < (__int128)LLONG_MIN) CS = LLONG_MIN;
            else CS = (long long)tmp;

            if (D[nx][ny][z] > CS){
                D[nx][ny][z] = CS;
                par[nx][ny][z] = {x, y, dir, 0};
                pq.push({ (long long)CS, nx, ny, z });
            }
        }
    }

    // 복원: 출발(R0,C0)에서 두 dir 중 작은거 고름
    int DR = (D[R[0]][C[0]][0] < D[R[0]][C[0]][1]) ? 0 : 1;
    string ans = "";
    while(R[0] != R[1] || C[0] != C[1]){
        int X = par[R[0]][C[0]][DR][0];
        int Y = par[R[0]][C[0]][DR][1];
        int PD = par[R[0]][C[0]][DR][2];

        // R0,C0 -> (X,Y) 이므로 방향 문자 결정
        if (X == R[0]) {
            // 좌우
            if (Y == C[0] + 1) ans += 'R';
            else ans += 'L';
        } else {
            // 상하
            if (X == R[0] + 1) ans += 'D';
            else ans += 'U';
        }

        DR = PD;
        R[0] = X; C[0] = Y;
    }

    // 현재 ans 는 출발->도착 방향으로 구성된 것(정답 코드와 동일 방식)
    cout << ans.size() << '\n';
    cout << ans << '\n';
    return 0;
}
