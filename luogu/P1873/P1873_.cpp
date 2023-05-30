#include <bits/stdc++.h>

using namespace std;

#define M 1000010

typedef long long LL;

LL a[M],n,m;

bool P(int h){
    LL tot=0;
    for(int i=0;i<n;i++){
        // tot+=h>=a[i]?0:a[i]-h;
        if(a[i]>h)
            tot+=a[i]-h;
    }
    return tot>=m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    int l=0,r=1e9,ans,mid;
    while(l<r){
        if(P(mid=l+(r-l)/2))
            ans=mid,l=mid+1;
        else
            r=mid;
    }
    cout<<ans;
    return 0;
}