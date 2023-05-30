#include <bits/stdc++.h>

using namespace std;

const int MAXN=2e5+2;

int n,a[MAXN],sum[MAXN],_max=-0x7fffffff;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=max(sum[i-1]+a[i],a[i]);
        _max=max(_max,sum[i]);
    }
    cout<<_max<<endl;
    return 0;
}