#include <bits/stdc++.h>

using namespace std;

const int MAXN=5e5+2;
int rt,n,m,dep[MAXN],fa[MAXN][31];

vector<int> p[MAXN];

void add(int u,int v){
    p[u].push_back(v);
    p[v].push_back(u);
}

void dfs(int x,int fno){
    if(fno)dep[x]=dep[fno]+1;
    fa[x][0]=fno;
    for(int i=1;i<31;++i){
        fa[x][i]=fa[fa[x][i-1]][i-1];
    }
    for(auto to:p[x]){
        if(to==fno)continue;
        dfs(to,x);
    }
}

int lca(int x,int y){
    if(dep[x]>dep[y])swap(x,y);
    int s=dep[y]-dep[x];
    for(int i=0;s;s>>=1,++i){
        if(s&1)y=fa[y][i];
    }
    if(x==y)return x;
    for(int i=30;i>=0;--i){
        if(fa[x][i]!=fa[y][i]){
            x=fa[x][i];
            y=fa[y][i];
        }
    }
    return fa[x][0];
}

int main(){
    cin>>n>>m>>rt;
    for(int i=1;i<n;++i){
        int u,v;cin>>u>>v;
        add(u,v);
    }
    dfs(rt,0);
    for(int i=1;i<=m;++i){
        int x,y;cin>>x>>y;
        cout<<lca(x,y)<<endl;
    }
    return 0;
}