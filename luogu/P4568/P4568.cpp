#include <bits/stdc++.h>

using namespace std;

const int MAXN=1e4+1;
const int INF=0x3f3f3f3f;

struct node{
    int u,dis,cnt;
    node(int _u,int _dis,int _cnt):u(_u),dis(_dis),cnt(_cnt){}
    bool operator>(const node& other)const{
        return dis>other.dis;
    }
};

struct edge{
    int to,w;
};

int n,m,k;
int s,t;
vector<edge> p[MAXN];
priority_queue<node,vector<node>,greater<node>> pq;
int dis[MAXN][12],vis[MAXN][12];

void add(int u,int v,int w){
    p[u].push_back({v,w});
    p[v].push_back({u,w});
}

void dijkstra(int n,int s){
    memset(dis,0x3f,sizeof(dis));
    dis[s][0]=0;
    pq.push({s,0,0});
    while(!pq.empty()){
        int u=pq.top().u,cnt=pq.top().cnt;
        pq.pop();
        if(vis[u][cnt])continue;
        vis[u][cnt]=1;
        for(auto& [v,w]:p[u]){
            if(cnt<k&&dis[v][cnt+1]>dis[u][cnt]){
                dis[v][cnt+1]=dis[u][cnt];
                pq.push({v,dis[v][cnt+1],cnt+1});
            }
            if(dis[v][cnt]>dis[u][cnt]+w){
                dis[v][cnt]=dis[u][cnt]+w;
                pq.push({v,dis[v][cnt],cnt});
            }
        }
    }
}

int main(){
    cin>>n>>m>>k;
    cin>>s>>t;
    for(int i=1;i<=m;++i){
        int u,v,w;cin>>u>>v>>w;
        add(u,v,w);
    }
    dijkstra(n,s);
    int ans=0x7fffffff;
    for(int i=0;i<=k;++i){
        ans=min(ans,dis[t][i]);
    }
    cout<<ans<<endl;
    return 0;
}