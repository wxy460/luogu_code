#include <bits/stdc++.h>

using namespace std;

const int MAXN=5e4+44;

int n,m,d[MAXN<<2],yea[MAXN],val[MAXN];

void build(int s,int t,int p){
    if(s==t){
        d[p]=val[s];
        return;
    }
    int m=s+((t-s)>>1);

    build(s,m,p*2);
    build(m+1,t,p*2+1);
    d[p]=max(d[p*2],d[p*2+1]);
}

int askmax(int l,int r,int s,int t,int p){
    if(l<=s&&t<=r){
        return d[p];
    }
    int m=s+((t-s)>>1);
    int ret=-0x7fffffff;
    if(l<=m)ret=max(ret,askmax(l,r,s,m,p*2));
    if(m<r)ret=max(ret,askmax(l,r,m+1,t,p*2+1));
    return ret;
}

bool isknown(int year){
    int pos=lower_bound(yea+1,yea+n+1,year)-yea;
    if(pos!=n+1&&yea[pos]==year)return true;
    return false;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>yea[i]>>val[i];
    }
    build(1,n,1);
    cin>>m;
    for(int i=1;i<=m;i++){
        int Y,X;
        cin>>Y>>X;
        int u=lower_bound(yea+1,yea+n+1,Y)-yea;
        int v=lower_bound(yea+1,yea+n+1,X)-yea;
        if(isknown(Y)&&isknown(X)){
            if(val[u]<val[v]){
                cout<<"false"<<endl;
                continue;
            }else if(v==u+1){
                if(X==Y+1){
                    cout<<"true"<<endl;
                    continue;
                }else{
                    cout<<"maybe"<<endl;
                    continue;
                }
            }else if(askmax(u+1,v-1,1,n,1)>=val[v]){
                cout<<"false"<<endl;
                continue;
            }else if(X-Y==v-u){
                cout<<"true"<<endl;
                continue;
            }else{
                cout<<"maybe"<<endl;
                continue;
            }
        }else if(!isknown(Y)&&isknown(X)){
            if(u==v){
                cout<<"maybe"<<endl;
                continue;
            }else if(askmax(u,v-1,1,n,1)>=val[v]){
                cout<<"false"<<endl;
                continue;
            }else{
                cout<<"maybe"<<endl;
                continue;
            }
        }else if(isknown(Y)&&!isknown(X)){
            if(v==u+1){
                cout<<"maybe"<<endl;
                continue;
            }else if(askmax(u+1,v-1,1,n,1)>=val[u]){
                cout<<"false"<<endl;
                continue;
            }else{
                cout<<"maybe"<<endl;
                continue;
            }
        }else{
            cout<<"maybe"<<endl;
            continue;
        }
    }
    return 0;
}