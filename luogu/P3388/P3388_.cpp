#include <bits/stdc++.h>

using namespace std;

const int MAXN=2e4+2;

int n,m,dfn[MAXN],low[MAXN],cnt,deg[MAXN];

vector<int> p[MAXN];

vector<int> dots[MAXN];
stack<int> st;
int idx;

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
            if(low[v]>=dfn[x]){
                dots[++idx].push_back(x);
                ++deg[x];
                int vv;
                do{
                    vv=st.top();
                    dots[idx].push_back(vv);
                    ++deg[vv];
                    st.pop();
                }while(vv!=v);
            }
        }else{
            low[x]=min(low[x],dfn[v]);
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1,u,v;i<=m;++i){
        cin>>u>>v;
        add(u,v);
    }
    for(int i=1;i<=n;++i){
        if(!dfn[i]){
            dfs(i,0);
            while(!st.empty())st.pop();
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        ans+=deg[i]>1;
    }cout<<ans<<'\n';
    for(int i=1;i<=n;++i){
        if(deg[i]>1){
            cout<<i<<" ";
        }
    }

    // //点双连通分量
    // for(int i=1;i<=idx;++i){
    //     for(auto t:dots[i]){
    //         cout<<t<<" ";
    //     }cout<<'\n';
    // }
    return 0;
}