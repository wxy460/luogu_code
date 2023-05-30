//典型的深度优化搜索

#include <bits/stdc++.h>

using namespace std;

int a[100]={0},n,ans=0;
int b1[100]={0},b2[100]={0},b3[100]={0};

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
        if(b1[i]==0&&b2[x+i]==0&&b3[x-i+15]==0){
            a[x]=i;
            b1[i]=1,b2[x+i]=1,b3[x-i+15]=1;
            dfs(x+1);
            b1[i]=0,b2[x+i]=0,b3[x-i+15]=0;
        }
    }
}

int main(){
    cin>>n;
    dfs(1);
    cout<<ans;
    return 0;
}