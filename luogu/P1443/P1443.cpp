//废案，因为没学队列
// #include <bits/stdc++.h>

// using namespace std;

// int maze[410][410],n,m,x,y;
// int d[8][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};

// bool isin(int x,int y){
//     return 1<=x&&x<=n&&1<=y&&y<=m;
// }

// void bfs(int deep){
//     for(int i=0;i<8;i++)
//     if(isin(x+d[i][0],y+d[i][1])&&maze[x+d[i][0]][y+d[i][1]]==-1){
//         x+=d[i][0];y+=d[i][1];maze[x][y]=deep;
//         bfs(deep+1);
//         x-=d[i][0];y-=d[i][1];
//     }
//     return;
// }

// int main(){
//     memset(maze,-1,sizeof(maze));
//     cin>>n>>m>>x>>y;
//     maze[x][y]=0;
//     bfs(1);
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             cout<<maze[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }