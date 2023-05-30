#include <bits/stdc++.h>

using namespace std;

const int MAXN=5e4+40;

vector<int> p[MAXN];
int fa[MAXN],dep[MAXN],siz[MAXN],son[MAXN],dfn[MAXN],rnk[MAXN],top[MAXN],cnt;

int n,k;

void add(int u,int v){
    p[u].push_back(v);
    p[v].push_back(u);
}

//update dep,fa,siz,son
void dfs1(int x,int fno){
    son[x]=-1;
    siz[x]=1;
    if(fno){
        fa[x]=fno;
        dep[x]=dep[fno]+1;
    }
    for(auto to:p[x]){
        if(to==fno)continue;
        dfs1(to,x);
        siz[x]+=siz[to];
        if(son[x]==-1||siz[son[x]]<siz[to])son[x]=to;
    }
}

//tree chain partitioning
void dfs2(int x,int ulti_fno){
    top[x]=ulti_fno;
    ++cnt;
    dfn[x]=cnt;
    rnk[cnt]=x;
    if(son[x]==-1)return;
    dfs2(son[x],ulti_fno);
    for(auto to:p[x]){
        if(to==fa[x]||to==son[x])continue;
        dfs2(to,to);
    }
}

//using segment tree to maintain the sum of paths
namespace SegTree{

int d[MAXN<<2],M[MAXN<<2],sum[MAXN<<2];

void build(int s,int t,int p){
    if(s==t){
        d[p]=0,M[p]=0;
        return;
    }
    int m=s+((t-s)>>1);
    build(s,m,p*2);
    build(m+1,t,p*2+1);
    d[p]=d[p*2]+d[p*2+1];
    M[p]=max(M[p*2],M[p*2+1]);
}

void pushdown(int s,int t,int p){
    int m=s+((t-s)>>1);
    if(s!=t&&sum[p]){
        d[p*2]+=(m-s+1)*sum[p],d[p*2+1]+=(t-m)*sum[p];
        M[p*2]+=sum[p],M[p*2+1]+=sum[p];
        sum[p*2]+=sum[p],sum[p*2+1]+=sum[p];
        sum[p]=0;
    }
}

int getsum(int l,int r,int s,int t,int p){
    if(l<=s&&t<=r){
        return d[p];
    }
    int m=s+((t-s)>>1);
    pushdown(s,t,p);
    int sum=0;
    if(l<=m)sum+=getsum(l,r,s,m,p*2);
    if(r>m)sum+=getsum(l,r,m+1,t,p*2+1);
    return sum;
}

int getmax(int l,int r,int s,int t,int p){
    if(l<=s&&t<=r){
        return M[p];
    }
    int m=s+((t-s)>>1);
    pushdown(s,t,p);
    int _max=-0x7fffffff;
    if(l<=m)_max=max(_max,getmax(l,r,s,m,p*2));
    if(r>m)_max=max(_max,getsum(l,r,m+1,t,p*2+1));
    return _max;
}

void update_add(int l,int r,int c,int s,int t,int p){
    if(l<=s&&t<=r){
        d[p]+=(t-s+1)*c,M[p]+=c;
        sum[p]+=c;
        return;
    }
    int m=s+((t-s)>>1);
    pushdown(s,t,p);
    if(l<=m)update_add(l,r,c,s,m,p*2);
    if(r>m)update_add(l,r,c,m+1,t,p*2+1);
    d[p]=d[p*2]+d[p*2+1];
    M[p]=max(M[p*2],M[p*2+1]);
}

}

int get_tree_path_sum(int u,int v){
    int ret=0;
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]){
            swap(u,v);
        }
        int l=min(dfn[u],dfn[top[u]]);
        int r=max(dfn[u],dfn[top[u]]);
        ret+=SegTree::getsum(l,r,1,n,1);
        u=fa[top[u]];
    }
    int l=min(dfn[u],dfn[v]);
    int r=max(dfn[u],dfn[v]);
    ret+=SegTree::getsum(l,r,1,n,1);
    return ret;
}

void update_tree_path_sum(int u,int v){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]){
            swap(u,v);
        }
        int l=min(dfn[u],dfn[top[u]]);
        int r=max(dfn[u],dfn[top[u]]);
        SegTree::update_add(l,r,1,1,n,1);
        u=fa[top[u]];
    }
    int l=min(dfn[u],dfn[v]);
    int r=max(dfn[u],dfn[v]);
    SegTree::update_add(l,r,1,1,n,1);
}

int main(){
    cin>>n>>k;
    for(int i=1;i<n;++i){
        int u,v;cin>>u>>v;
        add(u,v);
    }
    dfs1(1,0);
    dfs2(1,0);
    SegTree::build(1,n,1);
    for(int i=0;i<k;++i){
        int u,v;cin>>u>>v;
        update_tree_path_sum(u,v);
    }
    cout<<SegTree::getmax(1,n,1,n,1)<<endl;
    return 0;
}