#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN=2e5+2;
int a[MAXN],d[MAXN<<2],isxor[MAXN<<2];

void pushdown(int s,int t,int p){
    int m=s+((t-s)>>1);
    if(isxor[p]&&s!=t){
        d[p*2]=(m-s+1)-d[p*2],d[p*2+1]=(t-m)-d[p*2+1];
        isxor[p*2]^=1,isxor[p*2+1]^=1;
        isxor[p]=0;
    }
}

void build(int s,int t,int p){
    if(s==t){
        d[p]=a[s];
        return;
    }
    int m=s+((t-s)>>1);
    build(s,m,p*2);
    build(m+1,t,p*2+1);
    d[p]=d[p*2]+d[p*2+1];
}

int getsum(int l,int r,int s,int t,int p){
    if(l<=s&&t<=r){
        return d[p];
    }
    int m=s+((t-s)>>1);
    pushdown(s,t,p);
    int sum=0;
    if(l<=m)sum+=getsum(l,r,s,m,p*2);
    if(m<r)sum+=getsum(l,r,m+1,t,p*2+1);
    d[p]=d[p*2]+d[p*2+1];
    return sum;
}

void _xor_(int l,int r,int s,int t,int p){
    if(l<=s&&t<=r){
        d[p]=t-s+1-d[p],isxor[p]^=1;
        return;
    }
    int m=s+((t-s)>>1);
    pushdown(s,t,p);
    if(l<=m)_xor_(l,r,s,m,p*2);
    if(m<r)_xor_(l,r,m+1,t,p*2+1);
    d[p]=d[p*2]+d[p*2+1];
}

int n,m;
string atk;

signed main(){
    cin>>n>>m>>atk;
    for(int i=0;i<n;++i){
        a[i+1]=atk[i]-'0';
    }
    build(1,n,1);
    for(int i=1;i<=m;++i){
        int op;cin>>op;
        if(op==0){
            int l,r;cin>>l>>r;
            _xor_(l,r,1,n,1);
        }else if(op==1){
            int l,r;cin>>l>>r;
            cout<<getsum(l,r,1,n,1)<<endl;
        }
    }
}