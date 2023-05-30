#include <bits/stdc++.h>

using namespace std;

int s[4],a[30],maxdeep,nowtime,maxtime,sum;

void dfs(int x){
    if(x>maxdeep){
        maxtime=max(maxtime,nowtime);
        return;
    }
    if(nowtime+a[x]<=sum/2){
        nowtime+=a[x];
        dfs(x+1);
        nowtime-=a[x];
    }
    dfs(x+1);
}

int main(){
    int ans=0;
    for(int i=0;i<4;i++)cin>>s[i];
    for(int i=0;i<4;i++){
        sum=0,maxtime=0,nowtime=0,maxdeep=s[i];
        for(int j=1;j<=s[i];j++){cin>>a[j];sum+=a[j];}
        dfs(1);
        ans+=sum-maxtime;
    }
    cout<<ans;
    return 0;
}