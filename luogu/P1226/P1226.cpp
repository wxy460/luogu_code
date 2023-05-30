#include <bits/stdc++.h>

using namespace std;

int x,y,mod;

long long binpow(long long a,long long b,long long mod){
    long long ret=1;
    while(b>0){
        if(b&1){
            ret=(ret*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return ret;
}

int main(){
    cin>>x>>y>>mod;
    cout<<x<<'^'<<y<<" mod "<<mod<<"="<<binpow(x,y,mod)<<endl;
    return 0;
}