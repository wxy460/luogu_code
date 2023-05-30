#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int MAXN=5e5+2;

int n,m,dfn[MAXN],low[MAXN],cnt,idx,w[MAXN],sz[MAXN],sz_cur;

int st[MAXN],top;

LL ans;

struct G{
    vector<int> p[MAXN];
    void add(int u,int v){
        p[u].push_back(v);
        p[v].push_back(u);
    }
    vector<int>& operator[](int i){
        return p[i];
    }
}graph,crt;

void tarjan(int x,int fno){
    w[x]=-1;++sz_cur;
    dfn[x]=low[x]=++cnt;
    st[++top]=x;
    for(auto v:graph[x]){
        if(v==fno)continue;
        if(!dfn[v]){
            tarjan(v,x);
            low[x]=min(low[x],low[v]);
            if(low[v]>=dfn[x]){
                int vv;++idx;
                do{
                    vv=st[top--];
                    crt.add(idx,vv);
                    ++w[idx];
                }while(vv!=v);
                crt.add(idx,x);
                ++w[idx];
            }
        }else{
            low[x]=min(low[x],dfn[v]);
        }
    }
}

void dfs(int x,int fno){
    sz[x]=x<=n;
    LL cnt=0;
    for(auto v:crt[x]){
        if(v==fno)continue;
        dfs(v,x);
        cnt+=1ll*sz[x]*sz[v];
        sz[x]+=sz[v];
    }
    cnt+=1ll*sz[x]*(sz_cur-sz[x]);
    cnt<<=1;
    ans+=1ll*cnt*w[x];
}

int main(){
    cin>>n>>m;
    for(int i=1,u,v;i<=m;++i){
        cin>>u>>v;
        graph.add(u,v);
    }
    idx=n;
    for(int i=1;i<=n;++i){
        if(!dfn[i]){
            tarjan(i,0);
            dfs(i,0);
            top=sz_cur=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}