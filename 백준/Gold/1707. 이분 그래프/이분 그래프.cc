    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include <deque>
    #include <queue>
    #include <stack>
    #include <memory.h>
    #include <iomanip> 
    using namespace std;

    int k,v,e;
    vector <int> arr[20002];
   

    int main() {
        ios::sync_with_stdio(0); cin.tie(0);
        cin >> k;

        for (int t = 0; t < k; t++) {
            cin >> v >> e;

            for (int i = 1; i <= v; i++) {
                arr[i].clear();
            }

         
            for (int i = 0; i < e; i++) {
                int x, y;
                cin >> x >> y;
                arr[x].push_back(y);
                arr[y].push_back(x);
            }


            int flag = 0;
            int vis[20001]={0,};

            for (int j = 1; j <= v; j++) {
                queue <int> q;
                q.push(j);
                if (vis[j] != 0)
                    continue;
                vis[j] = 1;
               

                while (!q.empty()) {
                    int x = q.front();
                    q.pop();

                    for (int i = 0; i < arr[x].size(); i++) {
                        if (vis[arr[x][i]] == vis[x]) {
                            flag = 1;
                            break;
                        }
                     
                        if (vis[arr[x][i]] == 0) {
                            q.push(arr[x][i]);
                            vis[arr[x][i]] = -vis[x];
                        }
                     
                    }
                }
                
            }
            if (flag == 0)
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";

        }
        
       
       

    }