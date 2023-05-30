#include <bits/stdc++.h>

using namespace std;

#define M 1145

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

Bigint f[5050];

int main(){
    int n;cin>>n;
    f[0]=Bigint(1);
    f[1]=Bigint(1);
    for(int i=2;i<=n;i++){
        f[i]=f[i-1]+f[i-2];
    }
    f[n].print();
    return 0;
}