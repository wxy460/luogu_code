#include <bits/stdc++.h>

using namespace std;
#define LL long long
const int MAXN=1e5+4;
const int MOD=1e8-3;
LL n,a[MAXN],b[MAXN],_a[MAXN],_b[MAXN],q[MAXN],cnta[MAXN],cntb[MAXN],cntq[MAXN];
LL ans;
inline LL lowbit(int x){return x&-x;}

LL getsum(LL x){
    LL ret=0;
    for(;x>0;x-=lowbit(x)){
        ret+=cntq[x];
    }
    return ret;
}

void add(LL x,LL num){
    for(;x<=MAXN;x+=lowbit(x)){
        cntq[x]+=num;
    }
}

void start(){
    memcpy(_a,a,sizeof(a));
    memcpy(_b,b,sizeof(b));
    sort(_a+1,_a+n+1);
    sort(_b+1,_b+n+1);
    LL alen=unique(_a+1,_a+n+1)-_a-1;
    LL blen=unique(_b+1,_b+n+1)-_b-1;
    for(int i=1;i<=n;i++){
        //替换成排名
        // cnta[i]=lower_bound(_a+1,_a+alen+1,a[i])-_a;
        // cntb[i]=lower_bound(_b+1,_b+blen+1,b[i])-_b;
        //替换成排名为i的数的位置
        cnta[lower_bound(_a+1,_a+alen+1,a[i])-_a]=i;
        cntb[lower_bound(_b+1,_b+blen+1,b[i])-_b]=i;
    }
    for(int i=1;i<=n;i++){
        q[cnta[i]]=cntb[i];
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    start();
    for(int i=n;i>=1;i--){
        ans=(ans+getsum(q[i]-1))%MOD;
        add(q[i],1);
    }
    cout<<ans<<endl;
    return 0;
}