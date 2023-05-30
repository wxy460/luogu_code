#include <bits/stdc++.h>

using namespace std;

#define maxn 310

struct pos{
    int x,y;
};

queue<pos> q;

int ans[maxn][maxn],death[maxn][maxn],M,Ans=1010;
int walk[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int main(){
    memset(ans,-1,sizeof(ans));
    memset(death,127,sizeof(death));
    cin>>M;
    for(int i=0;i<M;i++){
        int x,y,t;cin>>x>>y>>t;
        #define MIN(x,y,t) if(x>=0&&y>=0) death[x][y]=min(death[x][y],t)
        MIN(x,y,t);
        for(int k=0;k<4;k++)
            MIN(x+walk[k][0],y+walk[k][1],t);
    }
    ans[0][0]=0;
    q.push({0,0});
    while(!q.empty()){
        pos now=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x=now.x+walk[i][0];
            int y=now.y+walk[i][1];
            if(x<0||y<0||ans[x][y]!=-1||ans[now.x][now.y]+1>=death[x][y])continue;
            ans[x][y]=ans[now.x][now.y]+1;
            q.push({x,y});
        }
    }
    for(int i=0;i<310;i++)
        for(int j=0;j<310;j++)
            if(ans[i][j]!=-1&&death[i][j]>1000)
                Ans=min(Ans,ans[i][j]);
    if(Ans==1010){
        cout<<-1;
    }else{
        cout<<Ans;
    }
    return 0;
}