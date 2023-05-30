#include<bits/stdc++.h>

using namespace std;

list<int> a;

list<int>::iterator it,now;

int n,m,cnt=0;

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)a.push_back(i);
    it=a.begin();
    while(!a.empty()){
        cnt++;
        now=it;
        if(++it==a.end())it=a.begin();
        if(cnt==m){
            cout<<*now<<" ";
            a.erase(now);
            cnt=0;
        }
    }
    return 0;
}