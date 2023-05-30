#include<bits/stdc++.h>

using namespace std;

#define M 22

long long f[M][M]={0};
int ctrl[M][M]={0};
int d[9][2]={{0,0},{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};

int main(){
    int n,m,hx,hy;
    cin>>n>>m>>hx>>hy;
    for(int i=0;i<9;i++){
        int tmpx=hx+d[i][0],tmpy=hy+d[i][1];
        //想想控制点为啥要限制在地图内
        //因为数组中参数为负数会出问题,越界改变了一些数据
        if(tmpx>=0&&tmpx<=n&&tmpy>=0&&tmpy<=m)
            ctrl[tmpx][tmpy]=1;
    }
    f[0][0]=1-ctrl[0][0];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(ctrl[i][j])continue;
            if(i!=0)f[i][j]+=f[i-1][j];
            if(j!=0)f[i][j]+=f[i][j-1];
        }
    }
    cout<<f[n][m];
    return 0;
}