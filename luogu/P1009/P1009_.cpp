#include <bits/stdc++.h>

using namespace std;

#define M 114

int sum[M]={0},tmp[M]={0};//倒过来存数的每一位

int main(){
    int n;
    cin>>n;
    sum[0]=tmp[0]=1;
    //阶乘
    for(int i=2;i<=n;i++){
        for(int j=0;j<M;j++){
            tmp[j]*=i;
        }
        for(int j=0;j<M;j++){
            tmp[j+1]+=tmp[j]/10;
            tmp[j]%=10;
        }
        for(int j=0;j<M;j++){
            sum[j]+=tmp[j];
        }
        for(int j=0;j<M;j++){
            sum[j+1]+=sum[j]/10;
            sum[j]%=10;
        }//上两步可合并，可判断是否进位减少判断时间
    }
    int len=M;
    for(int i=M-1;i>=0&&sum[i]==0;i--,len--);
    for(int i=len-1;i>=0;i--){
        cout<<sum[i];
    }
    return 0;
}