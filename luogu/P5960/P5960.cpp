#include <bits/stdc++.h>

using namespace std;

const int MAXN=5e3+10;
const int INF=0x3f3f3f3f;

struct edge{
    int v,w;
};

int n,m;
int dis[MAXN],vis[MAXN],cnt[MAXN];
vector<edge> p[MAXN];
queue<int> q;

void add(int u,int v,int w){
    p[u].push_back({v,w});
}

bool spfa(int n){
    fill_n(dis+1,n,INF);
    dis[0]=0;
    q.push(0);
    vis[0]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(auto& [v,w]:p[u]){
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                cnt[v]=cnt[u]+1;
                if(cnt[v]>=n+1)return false;
                if(!vis[v])q.push(v),vis[v]=1;
            }
        }
    }
    return true;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int u,v,w;cin>>v>>u>>w;
        add(u,v,w);
    }
    for(int i=1;i<=n;++i){
        add(0,i,0);
    }
    if(spfa(n)){
        for(int i=1;i<=n;++i){
            cout<<dis[i]<<" ";
        }cout<<'\n';
    }else{
        cout<<"NO"<<'\n';
    }
    return 0;
}