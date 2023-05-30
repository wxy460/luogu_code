#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+2;
const int mod=233333;
int N,ans=0;
char a[12],b[12];
vector<pair<int,int>> lk[mod+2]; 

int gethash(char a[],char b[]){
    return a[0]-'A'+(a[1]-'A')*26+(b[0]-'A')*26*26+(b[1]-'A')*26*26*26;
}

void insert(int x){
    for(int i=0;i<lk[x%mod].size();i++){
        if(lk[x%mod][i].first==x){
            lk[x%mod][i].second++;
            return;
        }
    }
    lk[x%mod].push_back(pair<int,int> (x,1));
}

int find(int x){
    for(int i=0;i<lk[x%mod].size();i++){
        if(lk[x%mod][i].first==x)return lk[x%mod][i].second;
    }
    return 0;
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        a[2]=0;
        if(a[0]!=b[0]||a[1]!=b[1])//排除在同一个州的情况
            ans+=find(gethash(b,a));
        insert(gethash(a,b));
    }
    cout<<ans<<endl;
    return 0;
}