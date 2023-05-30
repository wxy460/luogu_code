#include <bits/stdc++.h>

using namespace std;

long long f[22][22][22];

long long w(long long a,long long b,long long c){
    if(a<=0||b<=0||c<=0)return 1;
    if(a>20||b>20||c>20)return w(20,20,20);
    if(f[a][b][c]!=-1)return f[a][b][c];
    if(a<b&&b<c)return f[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    return f[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}

int main(){
    long long a,b,c;
    memset(f,-1,sizeof(f));
    while(cin>>a>>b>>c){
        if(a==-1&&b==-1&&c==-1)break;
        printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,w(a,b,c));
    }
    return 0;
}