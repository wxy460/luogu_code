#include <bits/stdc++.h>

using namespace std;

int a[15]={0},n,ans=0;

//循环判断效率慢，不如存储是否被占领
bool issafe(int x,int y){
    for(int i=1;i<x;i++){
        if(y==a[i])return false;
        if(abs(y-a[i])==abs(x-i))return false;
    }
    return true;
}

void dfs(int x){
    if(x>n){
        ans++;
        if(ans<=3){
            for(int i=1;i<=n;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(issafe(x,i)){
            a[x]=i;
            dfs(x+1);
        }
    }
}

int main(){
    cin>>n;
    dfs(1);
    cout<<ans;
    return 0;
}