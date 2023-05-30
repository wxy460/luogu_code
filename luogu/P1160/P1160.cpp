#include <bits/stdc++.h>

using namespace std;

struct node{
    int pre,nxt,key;
    node(int _key=0,int _pre=0,int _nxt=0){
        key=_key;
        pre=_pre;
        nxt=_nxt;
    }
};

node s[100010];

int n,m,tot=0,idx[100010]={0};

void ins_back(int x,int y){
    int now=idx[x];
    s[++tot]=node(y,now,s[now].nxt);
    s[s[now].nxt].pre=tot;
    s[now].nxt=tot;
    idx[y]=tot;
}

void ins_front(int x,int y){
    int now=idx[x];
    s[++tot]=node(y,s[now].pre,now);
    s[s[now].pre].nxt=tot;
    s[now].pre=tot;
    idx[y]=tot;
}

void del(int x){
    int now=idx[x];
    int le=s[now].pre;
    int rt=s[now].nxt;
    s[le].nxt=rt;
    s[rt].pre=le;
    idx[x]=0;
}

int main(){
    int x,k,p;
    cin>>n;
    s[0]=node();
    ins_back(0,1);
    for(int i=2;i<=n;i++){
        cin>>k>>p;
        p?ins_back(k,i):ins_front(k,i);
    }
    cin>>m;
    while(m--){
        cin>>x;
        if(idx[x])del(x);
    }
    for(int now=s[0].nxt;now;now=s[now].nxt)cout<<s[now].key<<" ";
    return 0;
}