#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL a[200010],N,C;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>C;
    for(int i=0;i<N;i++)cin>>a[i];
    sort(a,a+N);
    LL ans=0;
    for(int i=0;i<N;i++){
        ans+=upper_bound(a,a+N,a[i]+C)-lower_bound(a,a+N,a[i]+C);
    }
    cout<<ans;
    return 0;
}