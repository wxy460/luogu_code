#include <bits/stdc++.h>

using namespace std;

const int MAXN=5e3+2;

struct edge{
    int u,v;
};

int n,m,dfn[MAXN],low[MAXN],bel[MAXN],deg[MAXN],cnt,idx;

vector<int> p[MAXN];
vector<edge> brige;
stack<int> st;

void add(int u,int v){
    p[u].push_back(v);
    p[v].push_back(u);
}

void dfs(int x,int fno){
    dfn[x]=low[x]=++cnt;
    st.push(x);
    for(auto v:p[x]){
        if(v==fno)continue;
        if(!dfn[v]){
            dfs(v,x);
            low[x]=min(low[x],low[v]);
            if(low[v]>dfn[x])brige.push_back({x,v});
        }else{
            low[x]=min(low[x],dfn[v]);
        } 
    }
    if(low[x]==dfn[x]){
        ++idx;
        for(int v=st.top();v!=x;st.pop(),v=st.top()){
            bel[v]=idx;
        }bel[x]=idx,st.pop();
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int u,v;cin>>u>>v;
        add(u,v);
    }
    dfs(1,0);
    for(auto ed:brige){
        int u=ed.u,v=ed.v;
        if(bel[u]!=bel[v]){
            ++deg[bel[u]],++deg[bel[v]];
        }
    }
    int leaves=0;
    for(int i=1;i<=idx;++i){
        leaves+=deg[i]==1;
    }
    cout<<((leaves+1)>>1)<<endl;
    return 0;
}