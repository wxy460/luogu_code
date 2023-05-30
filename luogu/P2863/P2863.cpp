#include <bits/stdc++.h>

using namespace std;

const int MAXN=1e4+2;

int n,m;
int dfn[MAXN],low[MAXN],cnt;
int bel[MAXN],ins[MAXN],siz[MAXN],idx;
int st[MAXN],top;

vector<int> p[MAXN];

void add(int u,int v){
    p[u].push_back(v);
}

void tarjan(int x){
    dfn[x]=low[x]=++cnt;
    ins[st[++top]=x]=1;
    for(auto v:p[x]){
        if(!dfn[v]){
            tarjan(v);
            low[x]=min(low[x],low[v]);
        }else if(ins[v]){
            low[x]=min(low[x],dfn[v]);
        }
    }
    if(low[x]==dfn[x]){
        int v;++idx;
        do{
            ins[v=st[top--]]=0;
            bel[v]=idx;
            ++siz[idx];
        }while(v!=x);
    }
}

int main(){
    cin>>n>>m;
    for(int i=1,u,v;i<=m;++i){
        cin>>u>>v;
        add(u,v);
    }
    for(int i=1;i<=n;++i){
        if(!dfn[i])tarjan(i);
    }
    int ans=0;
    for(int i=1;i<=idx;++i){
        ans+=siz[i]>1;
    }cout<<ans<<'\n';
    return 0;
}