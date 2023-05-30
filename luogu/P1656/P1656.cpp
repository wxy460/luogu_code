#include <bits/stdc++.h>

using namespace std;

const int MAXN=200;

struct edge{
    int u,v;
    bool operator<(const edge& other)const{
        if(u==other.u)return v<other.v;
        return u<other.u;
    }
};

vector<int> p[MAXN];
vector<edge> e;
stack<int> st;
int n,m,dfn[MAXN],low[MAXN],bel[MAXN],cnt,idx;

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
            if(low[v]>dfn[x])e.push_back({min(x,v),max(x,v)});
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
    sort(e.begin(),e.end());
    for(const auto& ed:e){
        cout<<ed.u<<" "<<ed.v<<endl;
    }
    return 0;
}