#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e4+2;
const int INF=0x7fffffff;
int n,m,s;

struct edge{
    int to,w;
};

vector<edge> p[MAXN];

int dis[MAXN];

void add(int u,int v,int w){
    p[u].push_back({v,w});
}

bool bellman_ford(int n,int s){
    fill_n(dis+1,n,INF);
    dis[s]=0;
    bool flag;
    for(int i=1;i<=n;++i){
        flag=false;
        for(int u=1;u<=n;++u){
            if(dis[u]==INF)continue;
            for(auto edge:p[u]){
                int v=edge.to,w=edge.w;
                if(dis[v]>dis[u]+w){
                    dis[v]=dis[u]+w;
                    flag=true;
                }
            }
        }
        if(!flag)break;
    }
    return flag;
}

signed main(){
    cin>>n>>m>>s;
    for(int i=1;i<=m;++i){
        int u,v,w;cin>>u>>v>>w;
        add(u,v,w);
    }
    auto boolean=bellman_ford(n,s);
    for(int i=1;i<=n;++i){
        cout<<dis[i]<<" ";
    }cout<<endl;
}