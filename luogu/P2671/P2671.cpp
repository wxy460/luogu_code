#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+2;
const int MOD=10007;

struct l{
    int num,col;
}a[MAXN];

int n,m,ans;

void solve(){
    for(int i=1;i<=n;i++){
        for(int j=i+2;j<=n;j+=2){
            if(a[i].col==a[j].col){
                ans=(ans+(i+j)*(a[i].num+a[j].num))%MOD;
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].num;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i].col;
    }
    solve();
    cout<<ans<<endl;
    return 0;
}