#include <bits/stdc++.h>

using namespace std;

#define M 114

struct Bigint{
    int len,a[M];
    Bigint(int x=0){
        memset(a,0,sizeof(a));
        for(len=0;x;len++){
            a[len]=x%10;
            x/=10;
        }
    }
    int& operator[](int i){
        return a[i];
    }
    void f(int _len){
        len=_len;
        for(int i=0;i<len;i++){
            a[i+1]+=a[i]/10;
            a[i]%=10;
        }
        for(;!a[len-1];){
            len--;
        }
    }
    void print(){
        for(int i=len-1;i>=0;i--){
            cout<<a[i];
        }
        cout<<endl;
    }
};

Bigint operator+(Bigint a,Bigint b){
    Bigint c;
    int len=max(a.len,b.len);
    for(int i=0;i<len;i++){
        c[i]+=a[i]+b[i];
    }
    c.f(len+1);
    return c;
}

Bigint operator*(Bigint a,int b){
    Bigint c;
    int len=a.len;
    for(int i=0;i<len;i++){
        c[i]=a[i]*b;
    }
    c.f(len+11);
    return c;
}

int main(){
    Bigint ans,tmp(1);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        tmp=tmp*i;
        ans=ans+tmp;
    }
    ans.print();
    return 0;
}