#include <iostream>
using namespace std;
const int maxn=1e5+2;
const long long IFN=0x7fffffff;
struct node{
    int next,to;
}e[maxn<<1];
int head[maxn],w[maxn],num,siz[maxn],n,x,y;
long long f[maxn],ans=IFN;

inline void add(int from,int to){
    e[++num].to=to;
    e[num].next=head[from];
    head[from]=num;
}

void dfs(int u,int fa,int dep){
    siz[u]=w[u];
    for(int i=head[u];i;i=e[i].next){
        if(e[i].to!=fa){
            dfs(e[i].to,u,dep+1),siz[u]+=siz[e[i].to];
        }
    }
    f[1]+=w[u]*dep;
}

void dp(int u,int fa){
    for(int i=head[u];i;i=e[i].next){
        if(e[i].to!=fa){
            f[e[i].to]=f[u]+siz[1]-2*siz[e[i].to],dp(e[i].to,u);
        }
    }
    ans=min(ans,f[u]);
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>x>>y;
        if(x)add(i,x),add(x,i);
        if(y)add(i,y),add(y,i);
    }
    dfs(1,0,0);
    dp(1,0);
    cout<<ans;
    return 0;
}