#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int mod=233333;
const int k=261;
vector<string> h[mod+2];
int n,ans=0;

int to_code(string x){
    int hash=1;
    for(int i=0;i<x.size();i++){
        hash=(hash*1ll*k+x[i])%mod;
    }
    return hash;
}

inline void insert(string x){
    for(int i=0;i<h[to_code(x)].size();i++){
        if(h[to_code(x)][i]==x)return;
    }    
    h[to_code(x)].push_back(x);
    ans++;
}

int main(){
    cin>>n;
    string x;
    for(int i=0;i<n;i++){
        cin>>x;
        insert(x);
    }
    cout<<ans;
    return 0;
}