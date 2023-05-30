#include <bits/stdc++.h>

using namespace std;

int x[100010],n,c;

bool P(int d){
    int cnt=0,tmp=-1e9;
    for(int i=0;i<n;i++){
        if(x[i]-tmp>=d){
            cnt++;
            tmp=x[i];
        }
    }
    return cnt>=c;
}

int main(){
    cin>>n>>c;
    for(int i=0;i<n;i++)cin>>x[i];
    sort(x,x+n);
    int l=0,r=1e9,ans,mid;
    while(l<r){
        if(P(mid=l+r>>1))
            ans=mid,l=mid+1;
        else
            r=mid;
    }
    cout<<ans;
    return 0;
}