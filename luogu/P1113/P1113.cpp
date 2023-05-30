#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+2;
int n,len[maxn],ans[maxn]={0},_ans=0;
vector<int> p[maxn];

int dfs(int x){
    if(ans[x])return ans[x];
    for(int i=0;i<p[x].size();i++){
        ans[x]=max(ans[x],dfs(p[x][i]));
    }
    ans[x]+=len[x];
    return ans[x];
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,t,y;
        cin>>x>>len[i];
        while(cin>>y,y){
            p[x].push_back(y);//反向建立图，指向需要准备的任务
        }
    }
    for(int i=1;i<=n;i++){
        _ans=max(_ans,dfs(i));
    }
    cout<<_ans<<endl;
    return 0;
}