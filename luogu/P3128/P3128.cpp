#include <bits/stdc++.h>
//暴力60分
using namespace std;

const int MAXN=5e4+22;

int fa[MAXN],dep[MAXN],cnt[MAXN];
int n,k,ans;

vector<int> p[MAXN];

void add(int u,int v){
    p[u].push_back(v);
    p[v].push_back(u);
}

void dfs(int x,int fno,int on){
    if(fno)dep[x]=dep[fno]+1;
    fa[x]=fno;
    if(on){
        ans=max(ans,cnt[x]);
    }
    for(auto to:p[x]){
        if(to==fno)continue;
        dfs(to,x,on);
    }
}

int lca(int x,int y){
    if(dep[x]>dep[y])swap(x,y);
    int s=dep[y]-dep[x];
    for(;s;--s,y=fa[y]){
        ++cnt[y];
    }
    if(x==y){
        ++cnt[x];
        return x;
    }
    for(;x!=y;x=fa[x],y=fa[y]){
        ++cnt[x];
        ++cnt[y];
    }
    ++cnt[x];
    return x;
}

int main(){
    cin>>n>>k;
    for(int i=1;i<n;++i){
        int u,v;cin>>u>>v;
        add(u,v);
    }
    dfs(1,0,0);
    for(int i=0;i<k;++i){
        int s,t;cin>>s>>t;
        lca(s,t);
    }
    dfs(1,0,1);
    cout<<ans<<endl;
    return 0;
}