#include <bits/stdc++.h>

using namespace std;

const int MAXN=1e5+2;

vector<int> p[MAXN];

int n,d,cnt;

void add(int u,int v){
    p[u].push_back(v);
    p[v].push_back(u);
}

void dfs(int x,int fno,int dep){
    if(dep>d)return;
    if(fno)++cnt;
    for(auto to:p[x]){
        if(to==fno)continue;
        dfs(to,x,dep+1);
    }
}

auto main()->int{
    cin>>n>>d;
    for(int i=1;i<n;++i){
        int u,v;cin>>u>>v;
        add(u,v);
    }
    dfs(1,0,0);
    cout<<cnt<<endl;
    return 0;
}