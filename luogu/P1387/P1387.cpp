#include <bits/stdc++.h>

using namespace std;

const int MAXN=110;

int sum[MAXN][MAXN],num[MAXN][MAXN],n,m;

int solve(){
    int ret=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            sum[i][j]=-sum[i-1][j-1]+sum[i][j-1]+sum[i-1][j]+num[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int len=1;
            int _sum;
            while(i-len>=0&&j-len>=0){
                _sum=sum[i][j]+sum[i-len][j-len]-sum[i-len][j]-sum[i][j-len];
                if(_sum/len==len&&_sum%len==0){
                    if(ret<len){
                        ret=len;
                    }
                }
                len++;
            }
        }
    }
    return ret;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>num[i][j];
        }
    }
    cout<<solve()<<endl;
    return 0;
}