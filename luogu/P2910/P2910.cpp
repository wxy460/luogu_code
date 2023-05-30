#include <bits/stdc++.h>

using namespace std;

const int MAXN=1e2+2;
const int INF=0x3f3f3f3f;

int n,m;
int p[MAXN][MAXN];
int dis[MAXN][MAXN];
int path[MAXN*MAXN];

void floid(int n){
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;++i){
        dis[i][i]=0;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i==j)continue;
            dis[i][j]=p[i][j];
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        cin>>path[i];
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>p[i][j];
        }
    }
    floid(n);
    int ans=0;
    for(int i=1;i<m;++i){
        ans+=dis[path[i]][path[i+1]];
    }
    cout<<ans<<endl;
    return 0;
}