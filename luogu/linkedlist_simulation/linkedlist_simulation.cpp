#include <bits/stdc++.h>

using namespace std;

struct node{
    int pre,nxt;
    int key;
    node(int _key=0,int _pre=0,int _nxt=0){
        key=_key;
        pre=_pre;
        nxt=_nxt;
    }
};

node s[1005];

int tot=0;

int find(int x){
    int now=0;
    while(s[now].key!=x)now=s[now].nxt;
    return now;
}

void ins_back(int x,int y){
    int now=find(x);
    s[++tot]=node(y,now,s[now].nxt);
    s[s[now].nxt].pre=tot;
    s[now].nxt=tot;
}

void ins_front(int x,int y){
    int now=find(x);
    s[++tot]=node(y,s[now].pre,now);
    s[s[now].pre].nxt=tot;
    s[now].pre=tot;
}

int aks_back(int x){
    int now=find(x);
    return s[s[now].nxt].key;
}

int ask_front(int x){
    int now=find(x);
    return s[s[now].pre].key;
}

void del(int x){
    int now=find(x);
    int le=s[now].pre,rt=s[now].nxt;
    s[le].nxt=rt;
    s[rt].pre=le;
}

int main(){
    ins_back(0,114);
    ins_back(114,1919);
    ins_front(1919,514);
    for(int now=1;now!=0;now=s[now].nxt){
        cout<<s[now].key<<endl;
    }
    return 0;
}