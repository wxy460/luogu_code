#include <bits/stdc++.h>

using namespace std;

#define M 410

int ans[M][M];

int d[8][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};

struct stt{
    int x,y;
};

queue<stt> q;

int main(){
    memset(ans,-1,sizeof(ans));
    int n,m,_x,_y;cin>>n>>m>>_x>>_y;
    stt tmp{_x,_y};q.push(tmp);
    ans[_x][_y]=0;
    while(!q.empty()){
        stt s=q.front();
        q.pop();
        int step=ans[s.x][s.y];
        for(int i=0;i<8;i++){
            int x=s.x+d[i][0];
            int y=s.y+d[i][1];
            if(x<1||x>n||y<1||y>m||ans[x][y]!=-1)continue;
            ans[x][y]=step+1;
            stt tmp={x,y};
            q.push(tmp);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%-5d",ans[i][j]);
        }
        cout<<endl;
    }
    return 0;
}