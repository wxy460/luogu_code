#include <bits/stdc++.h>

#define M 1000010

using namespace std;

int a[M],m,n;

int find(int x){
    int l=0,r=n;
    while(l<r){
        int mid=l+(r-l)/2;
        if(a[mid]>=x)r=mid;//相等移动右书签
        else l=mid+1;
    }
    if(a[l]==x){
        return l+1;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++){
        int tmp;cin>>tmp;
        cout<<find(tmp)<<" ";
    }
    return 0;
}