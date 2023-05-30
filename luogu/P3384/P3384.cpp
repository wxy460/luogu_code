#include <bits/stdc++.h>

using namespace std;

const int MAXN=1e5+114;

int n,m,rt,mod;
vector<int> p[MAXN];
int dat[MAXN];
int dep[MAXN],fa[MAXN],son[MAXN],siz[MAXN];
int dfn[MAXN],rnk[MAXN],ufa[MAXN],tot;

void add(int u,int v){
    p[u].push_back(v);
    p[v].push_back(u);
}

void dfs1(int x,int fno){
    siz[x]=1;
    son[x]=-1;
    if(fno){
        dep[x]=dep[fno]+1;
        fa[x]=fno;
    }
    for(auto to:p[x]){
        if(to==fno)continue;
        dfs1(to,x);
        siz[x]+=siz[to];
        if(son[x]==-1||siz[to]>siz[son[x]])son[x]=to;
    }
}

void dfs2(int x,int ufno){
    ++tot;
    dfn[x]=tot;
    rnk[tot]=x;
    ufa[x]=ufno;
    if(son[x]==-1)return;
    dfs2(son[x],ufno);
    for(auto to:p[x]){
        if(to==fa[x]||to==son[x])continue;
        dfs2(to,to);
    }
}

namespace tree{

#define MID int m=(s+((t-s)>>1))
#define pushup() d[p]=(d[p*2]+d[p*2+1])%mod
int a[MAXN],d[MAXN<<2],add[MAXN<<2];

void build(int s,int t,int p){
    if(s==t){
        d[p]=a[s],d[p]%=mod;
        return;
    }
    MID;
    build(s,m,p*2);
    build(m+1,t,p*2+1);
    pushup();
}

void pushdown(int s,int t,int p){
    MID;
    if(s!=t&&add[p]){
        d[p*2]+=add[p]*(m-s+1),d[p*2+1]+=add[p]*(t-m);
        d[p*2]%=mod,d[p*2+1]%=mod;
        add[p*2]+=add[p],add[p*2+1]+=add[p];
        add[p*2]%=mod,add[p*2+1]%=mod;
        add[p]=0;
    }
}

int getsum(int l,int r,int s,int t,int p){
    if(l<=s&&t<=r){
        return d[p];
    }
    MID;
    pushdown(s,t,p);
    int sum=0;
    if(l<=m)sum+=getsum(l,r,s,m,p*2),sum%=mod;
    if(r>m)sum+=getsum(l,r,m+1,t,p*2+1),sum%=mod;
    return sum;
}

void updateadd(int l,int r,int c,int s,int t,int p){
    if(l<=s&&t<=r){
        d[p]+=c*(t-s+1),d[p]%=mod;
        add[p]+=c,add[p]%=mod;
        return;
    }
    MID;
    pushdown(s,t,p);
    if(l<=m)updateadd(l,r,c,s,m,p*2);
    if(r>m)updateadd(l,r,c,m+1,t,p*2+1);
    pushup();
}


}

int get_path_sum(int u,int v){
    int sum=0;
    while(ufa[u]!=ufa[v]){
        if(dep[ufa[u]]<dep[ufa[v]])swap(u,v);
        sum+=tree::getsum(dfn[ufa[u]],dfn[u],1,n,1),sum%=mod;
        u=fa[ufa[u]];
    }
    if(dep[u]<dep[v])swap(u,v);
    sum+=tree::getsum(dfn[v],dfn[u],1,n,1),sum%=mod;
    return sum;
}

void modify_path_sum(int u,int v,int c){
    while(ufa[u]!=ufa[v]){
        if(dep[ufa[u]]<dep[ufa[v]])swap(u,v);
        tree::updateadd(dfn[ufa[u]],dfn[u],c,1,n,1);
        u=fa[ufa[u]];
    }
    if(dep[u]<dep[v])swap(u,v);
    tree::updateadd(dfn[v],dfn[u],c,1,n,1);
}

int get_rt_sum(int x){
    return tree::getsum(dfn[x],dfn[x]+siz[x]-1,1,n,1);
}

void modify_rt_sum(int x,int c){
    tree::updateadd(dfn[x],dfn[x]+siz[x]-1,c,1,n,1);
}

int main(){
    freopen("C:\\Users\\ASUS\\Downloads\\P3384_4.in","r",stdin);
    cin>>n>>m>>rt>>mod;
    for(int i=1;i<=n;++i){
        cin>>dat[i];
    }
    for(int i=1;i<n;++i){
        int u,v;cin>>u>>v;
        add(u,v);
    }
    dfs1(rt,0);
    dfs2(rt,rt);

    for(int i=1;i<=n;++i){
        tree::a[dfn[i]]=dat[i];
    }
    tree::build(1,n,1);
    
    for(int i=1;i<=m;++i){
        int op;cin>>op;
        if(op==1){
            int x,y,z;cin>>x>>y>>z;
            modify_path_sum(x,y,z);
        }else if(op==2){
            int x,y;cin>>x>>y;
            cout<<get_path_sum(x,y)<<endl;
        }else if(op==3){
            int x,z;cin>>x>>z;
            modify_rt_sum(x,z);
        }else if(op==4){
            int x;cin>>x;
            cout<<get_rt_sum(x)<<endl;
        }
        // cout<<"---------------"<<endl;
        // for(int i=1;i<=n;++i){
        //     cout<<get_path_sum(i,i)<<" ";
        // }cout<<endl;
        // cout<<"---------------"<<endl;
        // for(int i=1;i<=n;++i){
        //     get_path_sum(i,i);
        // }
    }
    return 0;
}