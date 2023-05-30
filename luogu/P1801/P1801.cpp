#include <bits/stdc++.h>

using namespace std;

priority_queue<int> p;
priority_queue<int,vector<int>,greater<int>> q;
int n,m;
vector<int> a,u;

int main(){
    cin>>n>>m;
    for(int i=0;i<n;++i){
        int tmp;cin>>tmp;
        a.push_back(tmp);
    }
    u.push_back(0);
    for(int i=1;i<=m;++i){
        int tmp;cin>>tmp;
        u.push_back(tmp);
    }
    for(int i=1;i<=m;++i){
        for(int j=u[i-1];j<u[i];++j){
            p.push(a[j]);
        }
        while(p.size()>=i){
            q.push(p.top()),p.pop();
        }
        cout<<q.top()<<endl;
        p.push(q.top()),q.pop();
    }
    return 0;
}