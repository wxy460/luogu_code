#include <bits/stdc++.h>
using namespace std;
const int maxn=200;
int p[maxn],num=0,n;
struct node{
    char l,r;
}e[maxn];

void add(char u,char l,char r){
    e[++num].l=l;
    e[num].r=r;
    p[u]=num;
}

void dfs(char u){
    int i=p[u];
    cout<<u;
    if(i&&e[i].l!='*')dfs(e[i].l);
    if(i&&e[i].r!='*')dfs(e[i].r);
}

int main(){
    cin>>n;
    char u,l,r;cin>>u>>l>>r;
    add(u,l,r);
    for(int i=2;i<=n;i++){
        char u1,l1,r1;cin>>u1>>l1>>r1;
        add(u1,l1,r1);
    }
    dfs(u);
    return 0;
}