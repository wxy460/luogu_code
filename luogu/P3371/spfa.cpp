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

int dis[MAXN],isv[MAXN],cnt[MAXN];
queue<int> q;

void add(int u,int v,int w){
    p[u].push_back({v,w});
}

bool spfa(int n,int s){
    fill_n(dis+1,n,INF);
    dis[s]=0,isv[s]=1;
    q.push(s);
    while(!q.empty()){
        int u=q.front();q.pop();
        isv[u]=0;
        for(auto& [v,w]:p[u]){
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                cnt[v]=cnt[u]+1;
                if(cnt[v]>=n)return false;
                if(!isv[v])q.push(v),isv[v]=1;
            }
        }
    }
    return true;
}

signed main(){
    cin>>n>>m>>s;
    for(int i=1;i<=m;++i){
        int u,v,w;cin>>u>>v>>w;
        add(u,v,w);
    }
    auto boolean=spfa(n,s);
    for(int i=1;i<=n;++i){
        cout<<dis[i]<<" ";
    }cout<<endl;
}