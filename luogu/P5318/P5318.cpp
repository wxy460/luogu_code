#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+2;
vector<int> p[maxn];
bool isv[maxn]={0};
bool _isv[maxn]={0};
queue<int> stt;
int n,m,x,y;

void dfs(int x){
    cout<<x<<' ';
    for(int i=0;i<p[x].size();i++){
        if(!isv[p[x][i]]){
            isv[p[x][i]]=true;   
            dfs(p[x][i]);
        }
    }
}

void bfs(){
    stt.push(1);
    while(!stt.empty()){
        int x=stt.front();
        stt.pop();
        cout<<x<<' ';
        for(int i=0;i<p[x].size();i++){
            if(!_isv[p[x][i]]){
                _isv[p[x][i]]=true;
                stt.push(p[x][i]);
            }
        }
    }
}

int main(){
    isv[1]=1;
    _isv[1]=1;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        p[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        sort(p[i].begin(),p[i].end());
    }
    dfs(1);
    cout<<endl;
    bfs();
    cout<<endl;
    return 0;
}