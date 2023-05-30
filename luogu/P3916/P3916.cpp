#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+2;

int n,m,x,y,ans[maxn]={0};
vector<int> p[maxn];

void dfs(int x,int v){
    ans[x]=v;
    for(int i=0;i<p[x].size();i++){
        if(!ans[p[x][i]])
        dfs(p[x][i],v);
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        p[y].push_back(x);
    }
    for(int i=n;i>=1;i--){
        if(ans[i]==0)
            dfs(i,i);
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}