#include <bits/stdc++.h>

using namespace std;

const int MAXN=1e4+2;

int n,m,val[MAXN];
int dfn[MAXN],low[MAXN],cnt;
int bel[MAXN],ins[MAXN],idx;
int dp[MAXN],ans;

vector<int> p[MAXN];
int st[MAXN],top;

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
        int v,sum=0;++idx;
        do{
            ins[v=st[top--]]=0;
            bel[v]=idx;
            sum+=val[v];

            for(auto vv:p[v]){
                dp[idx]=max(dp[idx],dp[bel[vv]]);
            }

        }while(v!=x);
        dp[idx]+=sum;
        ans=max(ans,dp[idx]);
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>val[i];
    for(int i=1,u,v;i<=m;++i){
        cin>>u>>v;
        add(u,v);
    }
    for(int i=1;i<=n;++i){
        if(!dfn[i])tarjan(i);
    }
    cout<<ans<<endl;
    return 0;
}