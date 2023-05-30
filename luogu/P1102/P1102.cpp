//超时
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL a[200010],N,C;

LL find(LL x){
    int l=0,r=N;
    while(l<r){
        int mid=l+(r-l)/2;
        if(a[mid]>=x)r=mid;
        else l=mid+1;
    }
    if(a[l]==x){
        int ret=0;
        while(a[l+ret]==x){
            ret++;
        }
        return ret;
    }else{
        return 0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>C;
    for(int i=0;i<N;i++)cin>>a[i];
    sort(a,a+N);
    LL ans=0;
    for(int i=0;i<N;i++){
        ans+=find(a[i]+C);
    }
    cout<<ans;
    return 0;
}