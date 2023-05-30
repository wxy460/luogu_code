#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,r;cin>>n>>r;
    int U=1<<n;
    for(int S=U-1;S>=0;S--){
        if(__builtin_popcount(S)==r){
            for(int i=n-1;i>=0;i--){
                if(S&1<<i)cout<<setw(3)<<n-i;
            }
            cout<<endl;
        }
    }
    return 0;
}