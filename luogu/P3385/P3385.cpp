#include <bits/stdc++.h>

using namespace std;

const int MAXN=2e3+3;
const int INF=0x3f3f3f3f;

int dis[MAXN],vis[MAXN],cnt[MAXN];

struct edge{
    int v,w;
};

vector<edge> p[MAXN];
queue<int> q;

void add(int u,int v,int w){
    if(w>=0){
        p[u].push_back({v,w});
        p[v].push_back({u,w});
    }else{
        p[u].push_back({v,w});
    }
}

bool spfa(int n,int s){
    while(!q.empty())q.pop();
    fill_n(cnt,MAXN,0);
    fill_n(vis,MAXN,0);
    fill_n(dis+1,n,INF);
    dis[s]=0,vis[s]=1;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(auto& [v,w]:p[u]){
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                cnt[v]=cnt[u]+1;
                if(cnt[v]>=n)return false;
                if(!vis[v])q.push(v),vis[v]=1;
            }
        }
    }
    return true;
}

int main(){
    // freopen("C:\\Users\\ASUS\\Downloads\\P3385_11.in","r",stdin);
    int echo;cin>>echo;
    for(int i=1;i<=echo;++i){
        int n,m;cin>>n>>m;
        for(int j=1;j<=m;++j){
            int u,v,w;cin>>u>>v>>w;
            add(u,v,w);
        }
        // for(int j=1;j<=n;++j){
        //     add(0,j,0);
        // }
        if(!spfa(n,1)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        for(int i=1;i<=n;++i){
            p[i].clear();
        }
    }
    return 0;
}