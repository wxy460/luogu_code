#include <bits/stdc++.h>

using namespace std;

const int MAXN=1e5+2;

typedef long long LL;

LL d[MAXN<<2],a[MAXN],b[MAXN<<2];

void build(LL s,LL t,LL p){
    if(s==t){
        d[p]=a[s];
        return;
    }
    LL m=s+((t-s)>>1);
    build(s,m,p*2);
    build(m+1,t,p*2+1);
    d[p]=d[p*2]+d[p*2+1];
}

void update(LL l,LL r,LL c,LL s,LL t,LL p){
    if(l<=s&&t<=r){
        d[p]+=(t-s+1)*c,b[p]+=c;
        return;
    }
    int m=s+((t-s)>>1);
    if(b[p]&&t!=s){
        d[p*2]+=(m-s+1)*b[p],d[p*2+1]+=(t-m)*b[p];
        b[p*2]+=b[p],b[p*2+1]+=b[p];
        b[p]=0;
    }
    if(l<=m)update(l,r,c,s,m,p*2);
    if(r>m)update(l,r,c,m+1,t,p*2+1);
    d[p]=d[p*2]+d[p*2+1];
}

LL getsum(LL l,LL r,LL s,LL t,LL p){
    if(l<=s&&t<=r){
        return d[p];
    }
    LL m=s+((t-s)>>1);
    if(b[p]&&t!=s){
        d[p*2]+=(m-s+1)*b[p],d[p*2+1]+=(t-m)*b[p];
        b[p*2]+=b[p],b[p*2+1]+=b[p];
        b[p]=0;
    }
    LL sum=0;
    if(l<=m)sum+=getsum(l,r,s,m,p*2);
    if(r>m)sum+=getsum(l,r,m+1,t,p*2+1);
    return sum;
}

int n,m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(d,0,sizeof(d));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,n,1);
    for(int i=0;i<m;i++){
        int op;cin>>op;
        if(op==1){
            LL x,y,k;cin>>x>>y>>k;
            update(x,y,k,1,n,1);
        }else if(op==2){
            LL x,y;cin>>x>>y;
            cout<<getsum(x,y,1,n,1)<<endl;
        }
    }
    return 0;
}