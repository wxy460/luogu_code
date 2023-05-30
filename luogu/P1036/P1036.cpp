#include <bits/stdc++.h>

using namespace std;

bool isprime(int x){
    if(x==0||x==1)return false;
    if(x==2||x==3)return true;
    if(x%2==0||x%6==0||x%6==3)return false;
    for(int i=3;i<x/i;i++)
        if(x%i==0)
            return false;
    return true;
}

int k_binary(int x){
    int k=0;
    while(x){
        if(x%2==1)k++;
        x>>=1;
    }
    return k;
}//计算2进制数的1的个数

int a[23]={0};

int main(){
    int n,k,ans=0;cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    int U=1<<n;
    for(int S=0;S<U;S++){
        if(__builtin_popcount(S)==k){
            int sum=0;
            for(int i=0;i<n;i++)
                if(S&1<<i)sum+=a[i];
            if(isprime(sum))ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}