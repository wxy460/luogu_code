#include <bits/stdc++.h>

using namespace std;

const int MAXN=1e2+2;

int f[MAXN][MAXN],n;

void floid(){
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                f[i][j]|=f[i][k]&f[k][j];
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>f[i][j];
        }
    }
    floid();
    for(int i=1;i<=n;++i,puts("")){
        for(int j=1;j<=n;++j){
            cout<<f[i][j]<<" ";
        }
    }
    return 0;
}