#include <bits/stdc++.h>

using namespace std;

int a[1010];

int f(int n){
    int ans=1;
    if(a[n]!=-1)return a[n];
    for(int i=1;i<=n/2;i++){
        ans+=f(i);
    }
    return a[n]=ans;
}

int main(){
    int n;cin>>n;
    memset(a,-1,sizeof(a));
    a[1]=1;
    cout<<f(n);
    return 0;
}