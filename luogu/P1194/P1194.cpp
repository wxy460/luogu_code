#include <bits/stdc++.h>

using namespace std;

const int MAXN=5e2+22;
const int INF=0x3f3f3f3f;

struct edge{
    int u,v,w;
    bool operator<(const edge& other)const{return w<other.w;}
};

vector<edge> e;
int n,val,fa[MAXN],ans;

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void unite(int x,int y){
    int xf=find(x),yf=find(y);
    if(xf!=yf)fa[xf]=yf;
}

int main(){
    cin>>val>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            int w;cin>>w;
            if(i>=j)continue;
            e.push_back({i,j,w!=0?w:INF});
        }
    }

    for(int i=1;i<=n;++i){
        e.push_back({0,i,val});
    }

    sort(e.begin(),e.end());

    for(int i=1;i<=n;++i)fa[i]=i;

    for(auto& ed:e){
        int u=ed.u,v=ed.v,w=ed.w;
        if(find(u)!=find(v))unite(u,v),ans+=w;
    }

    cout<<ans<<endl;
    return 0;
}