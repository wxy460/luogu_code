#include <bits/stdc++.h>

using namespace std;

#define M 114514

int n,m,dr[M],dr1[M],num[M];
string name[M];

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>dr[i]>>name[i];
    }
    for(int i=0;i<m;i++){
        cin>>dr1[i]>>num[i];
    }
    int t=0;
    for(int i=0;i<m;i++){
        if(dr1[i]^dr[t]){
            t+=num[i];
            t%=n;
        }else{
            t-=num[i];
            if(t<0) t+=n;
            t%=n;
        }
    }
    cout<<name[t]<<endl;
    return 0;
}