#include <bits/stdc++.h>

using namespace std;

#define M 1000010

struct tim{
    int op;
    int ed;
}a[M];

bool cmp(tim b,tim c){
    return b.ed<c.ed;
}

int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>a[i].op>>a[i].ed;
    sort(a,a+n,cmp);
    int ans=1,tmp=a[0].ed;
    for(int i=1;i<n;i++){
        if(tmp<=a[i].op){ans++;tmp=a[i].ed;}
        else{continue;}
    }
    cout<<ans;
    return 0;
}