#include <iostream>
#define MAXN 5010
using namespace std;

int n,m,p,fa[MAXN];

int fid(int x){
    if(x==fa[x])return x;
    return fa[x]=fid(fa[x]);//将每个人和族长直接相连接
}

void join(int c1,int c2){
    int f1=fid(c1),f2=fid(c2);
    if(f1!=f2)fa[f1]=f2;
}

int main(){
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        join(x,y);
    }
    for(int i=0;i<p;i++){
        int x,y;cin>>x>>y;
        if(fid(x)==fid(y))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}