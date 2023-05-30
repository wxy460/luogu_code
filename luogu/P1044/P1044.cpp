#include <bits/stdc++.h>

using namespace std;

int a[20]={0};

int main(){
    int n;cin>>n;
    a[0]=1;a[1]=1;
    for(int i=2;i<=n;i++){
        for(int k=1;k<=i;k++){
            a[i]+=a[k-1]*a[i-k];
        }
    }
    cout<<a[n];
    return 0;
}