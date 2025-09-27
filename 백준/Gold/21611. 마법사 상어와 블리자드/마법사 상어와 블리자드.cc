#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;


int n, m;
int arr[55][55];
pair<int,int> mag[103];
int r;
int goo[2555];
int si;

void del(int d,int s) {


    int dx[4] = { -1,1,0,0 };
    int dy[4] = { 0,0,-1,1 };
    int x = (n+1) / 2;
    int y = (n+1) / 2;
    for (int i = 1; i <= s; i++) {
        int nx = x + i*dx[d-1];
        int ny = y + i*dy[d-1];
      
        arr[nx][ny] = 0;
    }
}

void pu() {
    int x = (n + 1) / 2;
    int y = (n + 1) / 2;
    int dir = 0;
    int ddx[4] = { 0,1,0,-1 };
    int ddy[4] = { -1,0,1,0 };

    si = 0;
    memset(goo,0, sizeof(goo));

    //빈칸아닌 구슬넣기
    for (int i = 1; i < 2 * n; i++) {
        int conner = (i + 1) / 2;

       
        for (int j = 1; j <= conner; j++) {
            int nx = x + ddx[dir];
            int ny = y + ddy[dir];
        
                if (arr[nx][ny] != 0) {
                    goo[si] = arr[nx][ny];
                    si++;
                }
                x = nx;
                y = ny;
            
        }
         dir=(dir+1)%4;
    }
}
void d4() {

    while (1) {
        //폭발안한 구슬 넣어두는 tmp
        vector <int> tmp;
        int end;

        for (int i = 0; i < si; i++) {
            end = i;

            while (end < si && goo[i] == goo[end])
                end++;

            if (end - i < 4) {
                for (int j = i; j < end; j++) {
                    tmp.push_back(goo[j]);
                }
            }
            else {
                r += goo[i] * (end - i);

            }
            i = end - 1;
        }


        int tmpsize = tmp.size();

        //원래있던 구슬은==폭발안한구슬벡터
        if (tmpsize == si)
            break;
        
            for (int i = 0; i < si; i++)
                goo[i] = 0;

            si = tmpsize;
            for (int i = 0; i < tmpsize; i++) {
                goo[i] = tmp[i];
            }

        
    }

    //2개로 쪼개서 넣을 임시 벡터
    vector <int> q;

    int en;
    //q의최대 크기


    for (int i = 0; i < si; i++) {
        if (q.size() >= n * n)
            break;
        en = i;
        while (en < si && goo[i] == goo[en])
            en++;
        int a = (en - i);
        int b = goo[i];
        q.push_back(a);
        q.push_back(b);
        i = en - 1;
    }
   

    for (int i = 0; i < q.size(); i++) {
        goo[i] = q[i];
    }
    si = 0;
    int x = (n + 1) / 2;
    int y = (n + 1) / 2;
    int dir = 0;
    int ddx[4] = { 0,1,0,-1 };
    int ddy[4] = { -1,0,1,0 };
    memset(arr, 0, sizeof(arr));

    for (int i = 1; i < 2 * n; i++) {
        int conner = (i + 1) / 2;

        if (i == 2 * n - 1)
            conner = n - 1;

     
        for (int j = 1; j <= conner; j++) {
           
          int nx = x + ddx[dir];
           int ny = y + ddy[dir];
           
                arr[nx][ny] = goo[si];
                si++;
                x = nx;
                y = ny;
            
        }
     
        dir=(dir+1)%4;
      
    }

   
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];

    for (int i = 1; i <= m; i++) {
        int d, s;
        cin >> d >> s;
        mag[i] = { d,s };
    }

  
    for (int i = 1; i <= m; i++) {
        //시전한 마법
        int d = mag[i].first;
        int s = mag[i].second;
        del(d, s);
        pu();
       
        d4();

    }
    cout << r;
}