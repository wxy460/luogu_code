#include <bits/stdc++.h>

using namespace std;
const int MAXN=2e6+4;
int n,m;
struct node{
    int val,id;
}a[MAXN];

deque<node> q;

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<0<<'\n';
    for(int i=1;i<n;i++){
        while(!q.empty()&&(q.back().val>=a[i].val)){
            q.pop_back();
        }
        q.push_back(a[i]);
        if(i-m==q.front().id)q.pop_front();
        cout<<q.front().val<<'\n';
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].val;
        a[i].id=i;
    }
    solve();
    return 0;
}