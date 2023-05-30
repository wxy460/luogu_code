#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main(){
    LL n,m;cin>>n>>m;
    LL sqr=0,rct=0;
    // for(LL i=0;i<n;i++){
    //     for(LL j=0;j<m;j++){
    //         LL x=i,y=j;
    //         while(x<n&&y<m){
    //             sqr++;x++;y++;
    //         }
    //         rct+=(n-i)*(m-j)-(x-i);
    //     }
    // }
    // for(LL a=1;a<=n;a++){
    //     for(LL b=1;b<=m;b++){
    //         if(a==b)
    //             sqr+=(n+1-a)*(m+1-b);
    //         else
    //             rct+=(n+1-a)*(m+1-b);
    //     }
    // }
    for(LL a=1;a<=n;a++){
        for(LL b=1;b<=m;b++){
            if(a==b)
                sqr+=(n+1-a)*(m+1-b);
        }
    }
    cout<<sqr<<" "<<n*m*(n+1)*(m+1)/4-sqr;
    return 0;
}