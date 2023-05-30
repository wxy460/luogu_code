#include <bits/stdc++.h>

using namespace std;

#define M 1145

struct people{
    int id;
    int time;
}a[M];

bool cmp(people a,people b){
    return a.time<b.time;
}

int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i].time;a[i].id=i;}
    sort(a+1,a+n+1,cmp);
    double ans=0;
    for(int i=1;i<=n-1;i++){
        ans+=(n-i)*a[i].time;
    }
    ans/=n;
    for(int i=1;i<=n;i++)cout<<a[i].id<<" ";
    cout<<endl<<fixed<<setprecision(2)<<ans;
    return 0;
}