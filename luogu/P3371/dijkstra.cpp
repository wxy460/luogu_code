#include <bits/stdc++.h>

using namespace std;

const int MAXN=1e4+3;
const int INF=0x7fffffff;

struct node{
    int u,dis;
    bool operator>(const node& _node)const{
        return dis>_node.dis;
    }
};

struct edge{
    int to,w;
};

int n,m,s;
vector<edge> p[MAXN];
priority_queue<node,vector<node>,greater<node>> q;
int dis[MAXN],vis[MAXN];

void add(int u,int v,int w){
    p[u].push_back({v,w});
}

void dijkstra(int n,int s){
    fill_n(dis+1,n,INF);
    dis[s]=0;
    q.push({s,0});
    while(!q.empty()){
        int u=q.top().u;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto& [v,w]:p[u]){
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({v,dis[v]});
            }
        }
    }
}

int main(){
    cin>>n>>m>>s;
    for(int i=1;i<=m;++i){
        int u,v,w;cin>>u>>v>>w;
        add(u,v,w);
    }
    dijkstra(n,s);
    for(int i=1;i<=n;++i){
        cout<<dis[i]<<" ";
    }cout<<"\n";
    return 0;
}