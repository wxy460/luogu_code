#include <bits/stdc++.h>

using namespace std;

const int MAXN=1e5+2;

typedef long long LL;

LL a[MAXN],d[MAXN<<2],b[MAXN<<2],_b[MAXN<<2],n,m,mod;

inline LL read(){
    LL sign=1,ret=0;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-')sign=-1;
        ch=getchar();    
    }
    while(isdigit(ch)){
        ret=(ret<<3)+(ret<<1)+ch-'0';
        ch=getchar();
    }
    return ret*sign;
}

void pd(LL s,LL t,LL p){
    LL m=s+((t-s)>>1);
    if(_b[p]!=1&&t!=s){
        d[p*2]*=_b[p],d[p*2+1]*=_b[p];
        _b[p*2]*=_b[p],_b[p*2+1]*=_b[p];
        b[p*2]*=_b[p],b[p*2+1]*=_b[p];
        d[p*2]%=mod;
        d[p*2+1]%=mod;
        b[p*2]%=mod;
        b[p*2+1]%=mod;
        _b[p*2]%=mod;
        _b[p*2+1]%=mod;
        _b[p]=1;
    }
    if(b[p]&&t!=s){
        d[p*2]+=(m-s+1)*b[p],d[p*2+1]+=(t-m)*b[p];
        b[p*2]+=b[p],b[p*2+1]+=b[p];
        d[p*2]%=mod;
        d[p*2+1]%=mod;
        b[p*2]%=mod;
        b[p*2+1]%=mod;
        b[p]=0;
    }
}

void build(LL s,LL t,LL p){
    _b[p]=1;
    if(s==t){
        d[p]=a[s];
        return;
    }
    LL m=s+((t-s)>>1);
    build(s,m,p*2);
    build(m+1,t,p*2+1);
    d[p]=(d[p*2]+d[p*2+1])%mod;
}

void update_add(LL l,LL r,LL c,LL s,LL t,LL p){
    if(l<=s&&t<=r){
        d[p]+=(t-s+1)*c,b[p]+=c;
        d[p]%=mod,b[p]%=mod;
        return;
    }
    LL m=s+((t-s)>>1);
    pd(s,t,p);
    if(l<=m)update_add(l,r,c,s,m,p*2);
    if(r>m)update_add(l,r,c,m+1,t,p*2+1);
    d[p]=(d[p*2]+d[p*2+1])%mod;
}

void update_mul(LL l,LL r,LL c,LL s,LL t,LL p){
    if(l<=s&&t<=r){
        d[p]*=c,b[p]*=c,_b[p]*=c;
        d[p]%=mod;
        b[p]%=mod;
        _b[p]%=mod;
        return;
    }
    LL m=s+((t-s)>>1);
    pd(s,t,p);
    if(l<=m)update_mul(l,r,c,s,m,p*2);
    if(r>m)update_mul(l,r,c,m+1,t,p*2+1);
    d[p]=(d[p*2]+d[p*2+1])%mod;
}

LL getsum(LL l,LL r,LL s,LL t,LL p){
    if(l<=s&&t<=r){
        return d[p];
    }
    LL m=s+((t-s)>>1);
    pd(s,t,p);
    LL sum=0;
    if(l<=m) sum+=getsum(l,r,s,m,p*2),sum%=mod;
    if(r>m) sum+=getsum(l,r,m+1,t,p*2+1),sum%=mod;
    return sum;
}

int main(){
    n=read();
    m=read();
    mod=read();
    for(int i=1;i<=n;i++)a[i]=read();
    build(1,n,1);
    for(int i=0;i<m;i++){
        int op;op=read();
        if(op==1){
            LL x,y,k;
            x=read();
            y=read();
            k=read();
            update_mul(x,y,k,1,n,1);
        }else if(op==2){
            LL x,y,k;
            x=read();
            y=read();
            k=read();
            update_add(x,y,k,1,n,1);
        }else if(op==3){
            LL x,y;
            x=read();
            y=read();
            cout<<getsum(x,y,1,n,1)<<endl;
        }
    }
    return 0;
}