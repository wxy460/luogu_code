#include <bits/stdc++.h>
//目前是暴力枚举
using namespace std;

const int MAXN=330;

struct node{
    int to,w;
};

vector<node> p[MAXN];
vector<int> dias;
node dia[MAXN];

int dis[MAXN],des,_des,dep[MAXN],ispath[MAXN];
int n,s,ans,_ans=0x7fffffff;

void add(int u,int v,int w){
    p[u].push_back({v,w});
    p[v].push_back({u,w});
}

void dfs(int x,int fno,int on){
    for(int i=0;i<p[x].size();++i){
        if(p[x][i].to==fno)continue;
        if(on)dia[p[x][i].to]={x,p[x][i].w};
        dep[p[x][i].to]=dep[x]+p[x][i].w;
        if(dep[des]<dep[p[x][i].to])des=p[x][i].to;
        dfs(p[x][i].to,x,on);
    }
}

void getdia(){
    dfs(1,0,0);
    _des=des;
    dep[des]=0;
    dfs(des,0,1);
    for(int x=des;x;x=dia[x].to){
        dias.push_back(x);
    }
}

void setdis(int x,int fno){
    if(ispath[x])dis[x]=0;
    for(int i=0;i<p[x].size();++i){
        if(p[x][i].to==fno)continue;
        if(!ispath[p[x][i].to])dis[p[x][i].to]=dis[x]+p[x][i].w;
        if(ans<dis[p[x][i].to])ans=dis[p[x][i].to];
        setdis(p[x][i].to,x);
    }
}

void solve(){
    for(int i=0;i<dias.size();++i){
        int length=0;
        fill_n(ispath,n,0);
        for(int j=i;j<dias.size();++j){
            ispath[dias[j]]=1;
            if(j-i>0)length+=dia[dias[j-1]].w;

            if(length>s)break;

            fill_n(dis,n,0),ans=0;
            setdis(dias[i],0);
            _ans=min(_ans,ans);
        }
    }
    cout<<_ans<<endl;
}

signed main(){
    cin>>n>>s;
    for(int i=1;i<n;++i){
        int u,v,w;cin>>u>>v>>w;
        add(u,v,w);
    }
    getdia();
    solve();
}