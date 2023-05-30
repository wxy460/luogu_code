#include <bits/stdc++.h>
#define int long long
using namespace std;
//跑不过p3371
const int MAXN=1e4+2;
const int INF=0x7fffffff;
int n,m,s;

struct edge{
    int to,w;
};

vector<edge> p[MAXN];

int f[MAXN][MAXN];

void add(int u,int v,int w){
    p[u].push_back({v,w});
}

void start(){
    for(int i=1;i<=n;++i){
        f[i][i]=0;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i==j)continue;
            f[i][j]=INF;
        }
    }
    for(int i=1;i<=n;++i){
        for(auto edge:p[i]){
            if(i!=edge.to)
            if(f[i][edge.to])
            f[i][edge.to]=min(f[i][edge.to],edge.w);
            else{
                f[i][edge.to]=edge.w;
            }
        }
    }
}

void floid(){
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(f[i][j]>f[i][k]+f[k][j])f[i][j]=f[i][k]+f[k][j];
            }
        }
    }
}

signed main(){
    cin>>n>>m>>s;
    for(int i=1;i<=m;++i){
        int u,v,w;cin>>u>>v>>w;
        add(u,v,w);
    }
    start();
    floid();
    for(int i=1;i<=n;++i){
        cout<<f[s][i]<<" ";
    }cout<<endl;
}