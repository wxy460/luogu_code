#include <bits/stdc++.h>

using namespace std;
const int MAXN=2e6+5;

struct node{
    int val,id;
}a[MAXN];

deque<node> q;
int n,k;

void solve(){
    for(int i=1;i<=n;i++){
        while(!q.empty()&&(q.back().val<=a[i].val)){
            q.pop_back();
        }
        q.push_back(a[i]);
        if(q.front().id==i-k)q.pop_front();
        if(i>=k)cout<<q.front().val<<endl;
    }
}

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i].val;
        a[i].id=i;
    }
    solve();
    return 0;
}