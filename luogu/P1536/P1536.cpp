#include <iostream>
#include <set>
using namespace std;
const int maxn=1e5+2;
int fa[maxn],n=1,m,x,y;
set<int> fat;
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}

void join(int x,int y){
    int f1=find(x);
    int f2=find(y);
    if(f1!=f2)fa[f1]=f2;
}

void start(){
    fat.clear();
    for(int i=1;i<=n;i++)fa[i]=i;
}

int main(){
    do{
        cin>>n;
        if(n==0)break;
        cin>>m;
        start();
        for(int i=0;i<m;i++){
            cin>>x>>y;
            join(x,y);
        }
        for(int i=1;i<=n;i++){
            fat.insert(find(i));
        }
        cout<<fat.size()-1<<endl;
    }while(n!=0);
    return 0;
}