#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <string>
#include <ctype.h>
#include <stdio.h>
#define max_n 1025
typedef long long ll;
using namespace std;
int a[max_n][max_n];
int b[max_n][max_n];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));

	for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &a[i][j]);
            b[i][j] = b[i][j - 1] + a[i][j];
        }
	}

	for(int i = 1; i <= m; i++){
        int type;
        scanf("%d", &type);
        if(type){
            int y1, x1, y2, x2;
            scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
            int ret = 0;
            for(int j = y1; j <= y2; j++){
                ret += (b[j][x2] - b[j][x1 - 1]);
            }
            printf("%d\n", ret);
        }else{
            int y, x, value;
            scanf("%d%d%d", &y,&x,&value);
            int update_value = value - (b[y][x] - b[y][x - 1]);
            for(int j = x; j <= n; j++){
                b[y][j] += update_value;
            }
        }
	}
	return 0;
}

