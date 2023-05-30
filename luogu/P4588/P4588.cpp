#include <bits/stdc++.h>

//以时间为轴建树
#define int long long
using namespace std;
const int MAXN=1e5+3;
int d[MAXN<<2],cha[MAXN<<2],isc[MAXN<<2],mod,op,t,Q,m;

// void push_down(int s,int t,int p){
//     int m=s+((t-s)>>1);
//     if(isc[p]&&s!=t){
//         cha[p*2]=cha[p*2+1]=cha[p];
//         isc[p*2]=isc[p*2+1]=isc[p];
//         isc[p]=0;
//     }
// }

void build(int s,int t,int p){
    if(s==t){
        d[p]=1;
        return;
    }
    int m=s+((t-s)>>1);
    // push_down(s,t,p);
    build(s,m,p*2);
    build(m+1,t,p*2+1);
    d[p]=(d[p*2]*d[p*2+1])%mod;
}

void update_cha(int l,int r,int c,int s,int t,int p){
    if(l<=s&&t<=r){
        d[p]=c;
        // cha[p]=c;
        // isc[p]=1;
        return;
    }
    int m=s+((t-s)>>1);
    // push_down(s,t,p);
    int pro=1;
    if(l<=m)update_cha(l,r,c,s,m,p*2);
    if(m<r)update_cha(l,r,c,m+1,t,p*2+1);
    d[p]=(d[p*2]*d[p*2+1])%mod;
}

int getpro(int l,int r,int s,int t,int p){
    if(l<=s&&t<=r){
        return d[p];
    }
    int m=s+((t-s)>>1);
    // push_down(s,t,p);
    int pro=1;
    if(l<=m)pro*=getpro(l,r,s,m,p*2);
    if(m<r)pro*=getpro(l,r,m+1,t,p*2+1);
    return pro;
}

signed main(){
    cin>>t;
    while(t--){
        cin>>Q>>mod;
        build(1,Q,1);
        for(int i=1;i<=Q;i++){
            cin>>op>>m;
            if(op==1){
                update_cha(i,i,m,1,Q,1);
            }else{
                update_cha(m,m,1,1,Q,1);
            }
            cout<<getpro(1,Q,1,Q,1)<<endl;
        }
    }
}