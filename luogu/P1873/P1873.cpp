//超时，所以二分答案需要判断书签而不是判断答案
#include <bits/stdc++.h>

using namespace std;

int a[1000010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    int l=0,r=1e9,tot=0,mid;
    while(tot!=m){
        mid=l+(r-l)/2;tot=0;
        for(int i=0;i<n;i++){
            tot+=mid>a[i]?0:a[i]-mid;
        }
        if(tot<m){
            r=mid;
        }else if(tot>m){
            l=mid;
        }
    }
    cout<<mid;
    return 0;
}