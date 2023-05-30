#include <bits/stdc++.h>
using namespace std;
//#define ONLINE_JUDGE
int main(){
    #ifndef ONLINE_JUDGE
        freopen("20221207test.in","r",stdin);
        freopen("20221207test.out","w",stdout);
    #endif
    string s;
    int ans=0;
    while(cin>>s){
        ans+=s.size();
    }
    cout<<ans<<endl;
    return 0;
}