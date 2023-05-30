#include <bits/stdc++.h>

using namespace std;

#define M 501

int a[M][M]={0},tmp[M][M]={0},x[M]={0},y[M]={0},r[M]={0},z[M]={0};

void spin(int s[M][M],int x,int y,int r,int z){
    if(z==0){
        for(int i=0;i<M;i++){
            for(int j=0;j<M;j++){
                tmp[i][j]=s[i][j];
            }
        }
        for(int i=x-r;i<=x+r;i++){
            for(int j=y-r;j<=y+r;j++){
                tmp[x-y+j][y+x-i]=s[i][j];
            }
        }
        for(int i=0;i<M;i++){
            for(int j=0;j<M;j++){
                s[i][j]=tmp[i][j];
            }
        }
        memset(tmp,0,sizeof(tmp));
    }else if(z==1){
        for(int i=0;i<M;i++){
            for(int j=0;j<M;j++){
                tmp[i][j]=s[i][j];
            }
        }
        for(int i=x-r;i<=x+r;i++){
            for(int j=y-r;j<=y+r;j++){
                tmp[x+y-j][y-x+i]=s[i][j];
            }
        }
        for(int i=0;i<M;i++){
            for(int j=0;j<M;j++){
                s[i][j]=tmp[i][j];
            }
        }
        memset(tmp,0,sizeof(tmp));
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=++cnt;
        }
    }
    for(int i=0;i<m;i++){
        cin>>x[i]>>y[i]>>r[i]>>z[i];
    }
    for(int i=0;i<m;i++){
        spin(a,x[i],y[i],r[i],z[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}