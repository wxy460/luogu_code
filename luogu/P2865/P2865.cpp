#include <bits/stdc++.h>
//有向图的k短路问题
using namespace std;

const int MAXN=5e3+12;
const int INF=0x3f3f3f3f;

int n,m;
int dis_1[MAXN],dis_2[MAXN],vis[MAXN],cnt[MAXN];

struct node{
    int u,dis;
    node()=default;
    node(int _u,int _dis):u(_u),dis(_dis){}
    bool operator>(const node& other)const{return dis>other.dis;}
};

struct node_A{
    int u,dis;
    node_A()=default;
    node_A(int _u,int _dis):u(_u),dis(_dis){}
    bool operator>(const node_A& other)const{return dis+dis_2[u]>other.dis+dis_2[other.u];}
};

struct edge{
    int v,w;
};

vector<edge> p[MAXN],_p[MAXN];
priority_queue<node,vector<node>,greater<node>> pq_1;
priority_queue<node_A,vector<node_A>,greater<node_A>> pq_2;

void add(int u,int v,int w){
    p[u].push_back({v,w});
    _p[v].push_back({u,w});
}

void dijkstra_1(int n,int s){
    fill_n(dis_2+1,n,INF);
    dis_2[s]=0;
    pq_1.push({s,0});
    while(!pq_1.empty()){
        int u=pq_1.top().u;pq_1.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto& [v,w]:_p[u]){
            if(dis_2[v]>dis_2[u]+w){
                dis_2[v]=dis_2[u]+w;
                pq_1.push({v,dis_2[v]});
            }
        }
    }
}

void dijkstra_2(int n,int s,int t,int k){
    fill_n(dis_1+1,n,INF);
    dis_1[s]=0;pq_2.push({s,0});
    while(!pq_2.empty()){
        int u=pq_2.top().u;pq_2.pop();
        ++cnt[u];
        if(u==t&&cnt[t]==k){
            cout<<dis_1[t]<<endl;
            return;
        }
        if(cnt[u]>k)continue;
        for(auto& [v,w]:p[u]){
            dis_1[v]=dis_1[u]+w;
           pq_2.push({v,dis_1[v]});
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int u,v,w;cin>>u>>v>>w;
        add(u,v,w);
    }
    dijkstra_1(n,n);
    dijkstra_2(n,1,n,2);
    return 0;
}