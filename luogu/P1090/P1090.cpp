#include <bits/stdc++.h>

using namespace std;

#define M 20010

int a[M],b[M],cnt=0,ans=0;

int main(){
    memset(a,127,sizeof(a));
    memset(b,127,sizeof(b));
    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int i=0,j=0,tmp;
    for(int k=1;k<n;k++){
        tmp=a[i]<b[j]?a[i++]:b[j++];
        tmp+=a[i]<b[j]?a[i++]:b[j++];
        b[cnt++]=tmp;
        ans+=tmp;
    }
    cout<<ans;
    return 0;
}