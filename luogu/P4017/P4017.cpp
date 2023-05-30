//对DAG的拓扑排序
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int mod=80112002;
const int maxn=5010;
const int maxm=5e5+10;
int n,m,f[maxn],ind[maxn],outd[maxn],ans=0;
vector<int> p[maxn];
queue<int> q;

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        ind[y]++;
        outd[x]++;
        p[x].push_back(y);
    }
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++){
        if(!ind[i]){
            q.push(i);
            f[i]=1;
        }
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<p[x].size();i++){
            int y=p[x][i];
            ind[y]--;
            f[y]=(f[x]+f[y])%mod;
            if(!ind[y]){
                q.push(y);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!outd[i]){
            ans=(ans+f[i])%mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}