#include <bits/stdc++.h>
//朴素算法，能得48分，其余超时
using namespace std;

const int MAXN=1e5+2;

vector<int> p[MAXN];
int n,m;
char name[MAXN];
int fa[MAXN],dep[MAXN];

void add(int u,int v){
    p[u].push_back(v);
    p[v].push_back(u);
}

void dfs(int x,int fno){
    if(x==0)return;
    fa[x]=fno;
    dep[x]=dep[fa[x]]+1;
    for(int i=0;i<p[x].size();i++){
        if(p[x][i]!=fno)
        dfs(p[x][i],x);
    }
}

bool lca(int u,int v,char ch){
    while(dep[u]>dep[v]){
        if(name[u]==ch)return true;
        u=fa[u];
    }
    while(dep[u]<dep[v]){
        if(name[v]==ch)return true;
        v=fa[v];
    }
    while(u!=v){
        if(name[u]==ch||name[v]==ch){
            return true;
        }
        u=fa[u];
        v=fa[v];
    }
    if(name[u]==ch){
        return true;
    }
    return false;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>name[i];
    }
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        add(x,y);
    }
    dfs(1,0);
    for(int i=1;i<=m;i++){
        int x,y;
        char ch;
        cin>>x>>y>>ch;
        cout<<lca(x,y,ch);
    }
    return 0;
}