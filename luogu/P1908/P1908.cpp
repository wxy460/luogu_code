#include <bits/stdc++.h>

using namespace std;

const int MAXN=5e5+55;

int n,a[MAXN],cnt[MAXN];
int c[MAXN],ls[MAXN];
long long ans;

inline int lowbit(int x){return x&-x;}

void start(){
    memcpy(c,a,sizeof(a));
    sort(c+1,c+n+1);
    int l=unique(c+1,c+n+1)-c-1;
    for(int i=1;i<=n;i++){
        ls[i]=lower_bound(c+1,c+l+1,a[i])-c;
    }
}

int getsum(int v){
    int ret=0;
    while(v>0){
        ret+=cnt[v];
        v-=lowbit(v);
    }
    return ret;
}

void add(int v,int num){
    while(v<=MAXN){
        cnt[v]+=num;
        v+=lowbit(v);
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    start();
    for(int i=n;i>=1;i--){
        int tmp=getsum(ls[i]-1);
        ans+=tmp;
        add(ls[i],1);
    }
    cout<<ans<<endl;
    return 0;
}