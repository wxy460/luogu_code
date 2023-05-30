#include <bits/stdc++.h>

using namespace std;

const int MAXN=1e5+2;

vector<int> p[MAXN];
int n,m;
char name[MAXN];
int fa[MAXN][33],dep[MAXN],ishv[MAXN][33][2];

void add(int u,int v){
    p[u].push_back(v);
    p[v].push_back(u);
}

void dfs(int x,int fno){
    if(x==0)return;
    fa[x][0]=fno;
    dep[x]=dep[fno]+1;
    ishv[x][0][0]=(name[x]=='G'?1:0)|(name[fno]=='G'?1:0);
    ishv[x][0][1]=(name[x]=='H'?1:0)|(name[fno]=='H'?1:0);
    for(int i=1;i<31;i++){
        fa[x][i]=fa[fa[x][i-1]][i-1];
        ishv[x][i][0]=ishv[x][i-1][0]|ishv[fa[x][i-1]][i-1][0];
        ishv[x][i][1]=ishv[x][i-1][1]|ishv[fa[x][i-1]][i-1][1];
    }
    for(int i=0;i<p[x].size();i++){
        if(p[x][i]==fno)continue;
        dfs(p[x][i],x);
    }
}

bool lca(int u,int v,char ch){
    int op=0;
    if(ch=='G')op=0;
    else if(ch=='H')op=1;
    if(dep[u]>dep[v])swap(u,v);
    int tmp=dep[v]-dep[u];
    for(int i=0;tmp;i++,tmp>>=1){
        if(tmp&1){
            if(ishv[v][i][op])return true;
            v=fa[v][i];
        }
    }
    if(u==v){
        if(name[u]==ch)return true;
        return false;
    }
    for(int i=30;i>=0&&v!=u;i--){
        if(fa[u][i]!=fa[v][i]){
            if(ishv[u][i][op]||ishv[v][i][op]){
                return true;
            }
            u=fa[u][i];
            v=fa[v][i];
        }
    }
    if(ishv[u][0][op]||ishv[v][0][op]){
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