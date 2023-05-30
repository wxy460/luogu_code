#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=5e4+50;

int n,siz[MAXN],w[MAXN],centroid[2],dep[MAXN],root;
vector<int> p[MAXN];

void add(int u,int v){
    p[u].push_back(v);
    p[v].push_back(u);
}

void getcentroid(int x,int fno){
    siz[x]=1;
    w[x]=0;
    for(int i=0;i<p[x].size();++i){
        if(p[x][i]==fno)continue;
        getcentroid(p[x][i],x);
        siz[x]+=siz[p[x][i]];
        w[x]=max(w[x],siz[p[x][i]]);
    }
    w[x]=max(w[x],n-siz[x]);
    if(w[x]<=n/2){
        centroid[centroid[0]!=0]=x;
    }
}

int getsum(int x,int fno){
    int sum=0;
    if(fno)
    dep[x]=dep[fno]+1;
    for(int i=0;i<p[x].size();++i){
        if(p[x][i]==fno)continue;
        sum+=getsum(p[x][i],x);
    }
    sum+=dep[x];
    return sum;
}

signed main(){
    cin>>n;
    for(int i=1;i<=n-1;++i){
        int x,y;cin>>x>>y;
        if(i==1)root=x;
        add(x,y);
    }
    getcentroid(root,0);
    int c=centroid[1]!=0?min(centroid[0],centroid[1]):centroid[0];
    cout<<c<<" ";
    // cout<<min(getsum(centroid[0],0),getsum(centroid[1],0))<<endl;
    cout<<getsum(centroid[0],0)<<endl;
}