#include <bits/stdc++.h>
//无向图的次短路

using namespace std;

const int MAXN=3e5+12;
const int INF=0x3f3f3f3f;

int n,m;
int dis[MAXN],dis2[MAXN],vis[MAXN];

struct node{
    int u,dis;
    node(int _u,int _dis):u(_u),dis(_dis){}
    bool operator>(const node& other)const{return dis>other.dis;}
};

struct edge{
    int v,w;
};

vector<edge> p[MAXN];
priority_queue<node,vector<node>,greater<node>> pq;

void add(int u,int v,int w){
    p[u].push_back({v,w});
    p[v].push_back({u,w});
}

void dijkstra(int n,int s){
    fill_n(dis+1,n,INF);
    fill_n(dis2+1,n,INF);
    dis[s]=0;
    pq.push({s,0});
    while(!pq.empty()){
        int u=pq.top().u;pq.pop();
        // if(vis[u])continue;
        // vis[u]=1;
        for(auto& [v,w]:p[u]){
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                pq.push({v,dis[v]});
            }
            if(dis[v]<dis[u]+w&&dis2[v]>dis[u]+w){
                dis2[v]=dis[u]+w;
                pq.push({v,dis[v]});
            }
            if(dis2[v]>dis2[u]+w){
                dis2[v]=dis2[u]+w;
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int u,v,w;cin>>u>>v>>w;
        add(u,v,w);
    }
    dijkstra(n,1);
    cout<<dis2[n]<<endl;
    return 0;
}