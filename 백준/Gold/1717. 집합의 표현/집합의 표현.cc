#include <iostream>
#include<queue>
#include <vector>
#include <memory.h>
using namespace std;

int n,m;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int par[1000001];



int find(int x){
  if(par[x]<0)
    return x;
  return par[x]=find(par[x]);
}

void uni(int a,int b){
  a=find(a);
  b=find(b);
  if(a==b)
   return;
  if(par[a]>par[b])
    swap(a,b);
   if(par[a]==par[b])
    par[a]--;
  par[b]=a;  
  
}
bool chk(int a,int b){
  a=find(a);
  b=find(b);
  if(a==b)
   return 1;
  return 0; 
}

int main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  memset(par,-1,sizeof(par));

  cin>>n>>m;
  int cmd,x,y;

  while (m--){
    cin>>cmd>>x>>y;

     if(cmd){
      if(chk(x,y))
         cout<<"yes\n";
       else
         cout<<"no\n";
     }
    else
      uni(x,y);
  }

 }
 
