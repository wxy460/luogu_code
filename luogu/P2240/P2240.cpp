#include <bits/stdc++.h>

using namespace std;

#define M 114

struct good{
    int m,v;
    double val;
}a[M];

bool cmp(good a,good b){
    return a.val>b.val;
}

int main(){
    int N,T;cin>>N>>T;
    int _T=T,cnt=0;
    double ans=0;
    for(int i=0;i<N;i++){
        cin>>a[i].m>>a[i].v;
        a[i].val=1.0*a[i].v/a[i].m;
    }
    sort(a,a+N,cmp);
    while(_T-a[cnt].m>=0&&cnt<N){
        _T-=a[cnt].m;
        ans+=a[cnt].v;
        cnt++;
    }
    if(_T>0&&cnt<N){
        ans+=a[cnt].val*(_T);
    }
    cout<<fixed<<setprecision(2)<<ans<<endl;
    return 0;
}