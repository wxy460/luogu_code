#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
int n,root,cnt=0,opt,x;

struct Node{
    int left,right,size,value,num;
    Node(int l,int r,int s,int v)
        :left(l),right(r),size(s),value(v),num(1){}
    Node(){}
}t[MAXN];

inline void update(int root){
    t[root].size=t[t[root].left].size+t[t[root].right].size+t[root].num;
}

int rk(int x,int root){
    if(root){
        if(x<t[root].value){
            return rk(x,t[root].left);
        }
        if(x>t[root].value){
            return rk(x,t[root].right)+t[t[root].left].size+t[root].num;
        }
        else{
            return t[t[root].left].size+t[root].num;
        }
    }
    return 1;
}

int kth(int x,int root){
    if(x<=t[t[root].left].size){
        return kth(x,t[root].left);
    }
    if(x<=t[t[root].left].size+t[root].num){
        return t[root].value;
    }
    return kth(x-t[t[root].left].size-t[root].num,t[root].right);
}

void insert(int x,int root){
    if(x<t[root].value){
        if(!t[root].left)
            t[t[root].left=++cnt]=Node{0,0,1,x};
        else
            insert(x,t[root].left);
    }
    if(x>t[root].value){
        if(!t[root].right)
            t[t[root].right=++cnt]=Node{0,0,1,x};
        else
            insert(x,t[root].right);
    }
    else
        t[root].num++;
    update(root);
}

int main(){
    cin>>n;
    int num=0;
    t[root=++cnt]=Node{0,0,1,0x7fffffff};
    while(n--){
        cin>>opt>>x;
        if(opt==1)cout<<rk(x,root)<<endl;
        else if(opt==2)cout<<kth(x,root)<<endl;
        else if(opt==3){
            if(rk(x,root)==1){cout<<-0x7fffffff<<endl;}
            else cout<<kth(rk(x,root)-1,root)<<endl;
        }
        else if(opt==4)cout<<kth(rk(x+1,root),root)<<endl;
        else insert(x,root);
    }
    return 0;
}