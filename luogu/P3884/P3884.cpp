#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e2+2;
vector<int> p[MAXN];
queue<int> q;

int n,u,v,x,y,w=1,fa[MAXN],de[MAXN];

void add(int u,int v){
    p[u].push_back(v);
}

int dep(int x){
    if(p[x].size()==0){
        return 1;
    }
    int m=0;
    for(int i=0;i<p[x].size();i++){
        m=max(m,dep(p[x][i]));
    }
    return m+1;
}

void wid(){
    q.push(1);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<p[x].size();i++){
            q.push(p[x][i]);
        }
        int _w=q.size();
        w=max(w,_w);
    }
}

void dfs(int x,int fath,int d){
    fa[x]=fath;
    de[x]=d;
    for(int i=0;i<p[x].size();i++){
        dfs(p[x][i],x,d+1);
    }
}

int getlca(int x,int y){
    while(x!=y){
        if(dep(1)-dep(x)>=dep(1)-dep(y)){
            x=fa[x];
        }else{
            y=fa[y];
        }
    }
    return x;
}

int dis(int x,int y){
    int lca=getlca(x,y);
    int d1=-de[lca]+de[x];
    int d2=-de[lca]+de[y];
    return d1*2+d2;
}

int main(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        add(u,v);
    }
    cin>>x>>y;
    dfs(1,0,1);
    cout<<dep(1)<<endl;
    wid();
    cout<<w<<endl;
    cout<<dis(x,y)<<endl;
    return 0;
}