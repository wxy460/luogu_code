#include <bits/stdc++.h>

using namespace std;

const int MAXN=2e4+22;

int n,m,dfn[MAXN],bel[MAXN],low[MAXN],c[MAXN],cnt,idx,s,rt;
int ind[MAXN];
stack<int> st;
vector<int> p[MAXN];
vector<int> points;

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
            if(x==rt)++s;
            low[x]=min(low[x],low[v]);
            if(low[v]>=dfn[x])c[x]=1;
        }else{
            low[x]=min(low[x],dfn[v]);
        }
    }
    if(low[x]==dfn[x]){
        int v;++idx;
        do{
            v=st.top();
            bel[v]=idx;
            st.pop();
        }while(v!=x);
    }
}

int main(){
    // freopen("C:\\Users\\ASUS\\Downloads\\P3388_4.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int u,v;cin>>u>>v;
        add(u,v);
    }
    for(int i=1;i<=n;++i){
        if(!dfn[i]){
            s=0;rt=i;
            dfs(i,0);
            ind[i]=s;
        }
    }
    for(int i=1;i<=n;++i){
        if(ind[i]>1)points.push_back(i);
    }
    for(int i=1;i<=n;++i){
        if(ind[i]) continue;
        if(c[i]==1)points.push_back(i);
    }
    sort(points.begin(),points.end());
    cout<<points.size()<<endl;
    for(auto i:points){
        cout<<i<<" ";
    }cout<<endl;
    return 0;
}