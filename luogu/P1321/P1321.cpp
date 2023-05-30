#include <bits/stdc++.h>

using namespace std;

int f(string s,string t){
    int pos=s.find(t),cnt=0;
    while(~pos){
        pos=s.find(t,pos+t.size());
        cnt++;
    }
    return cnt;
}

int main(){
    string a;
    cin>>a;
    int cntb=0,cnto=0,cnty=0,cntbo=0,cntoy=0,cntboy=0;
    cntb=f(a,"b");
    cnto=f(a,"o");
    cnty=f(a,"y");
    cntbo=f(a,"bo");
    cntoy=f(a,"oy");
    // cntboy=f(a,"boy");
    int cnt1=cntb+cnto+cnty-cntbo-cntoy;
    int g=0,r=0,i=0,l=0,gi=0,gir=0,girl=0,ir=0,irl=0,rl=0;
    g=f(a,"g");
    r=f(a,"r");
    i=f(a,"i");
    l=f(a,"l");
    gi=f(a,"gi");
    // gir=f(a,"gir");
    // girl=f(a,"girl");
    ir=f(a,"ir");
    // irl=f(a,"irl");
    rl=f(a,"rl");
    int cnt2=g+r+i+l-gi-ir-rl;
    cout<<cnt1<<endl;
    cout<<cnt2<<endl;
    return 0;
}