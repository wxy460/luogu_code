#include <cmath>
#include <complex>
#include <iostream>
// #pragma GCC optimize(2)
using namespace std;

typedef complex<double> COMP;

const COMP I(0,1);
const int MAX_N=5e6+4;
const double PI=acos(-1);

COMP rot[MAX_N];
COMP rot2[MAX_N];

COMP a[MAX_N];
COMP b[MAX_N];
COMP ans[MAX_N];
COMP tmp[MAX_N];
int _ans[MAX_N];
int n=1;

void flatten(int *x,int len){
    for(int i=0;i<len;++i){
        x[i+1]+=x[i]/10;
        x[i]%=10;
    }
}

void DFT(COMP* f,int n,int rev,int d){
    if(n==1)return;
    for(int i=0;i<n;++i){
        tmp[i]=f[i];
    }
    for(int i=0;i<n;++i){
        if(i&1){
            f[i/2+n/2]=tmp[i];
        }else{
            f[i/2]=tmp[i];
        }
    }
    COMP *g=f,*h=f+n/2;
    DFT(g,n/2,rev,d+1),DFT(h,n/2,rev,d+1);
    // COMP cur(1,0),step(cos(2*PI/n),sin(2*rev*PI/n));
    for(int k=0;k<n/2;++k){
        COMP tt;
        if(rev==1)
        tt = rot[(1<<d)*k] * h[k];
        else if(rev==-1)
        tt = rot2[(1<<d)*k] * h[k];
        tmp[k]=g[k]+tt;
        tmp[k+n/2]=g[k]-tt;
    }
    for(int i=0;i<n;++i){
        f[i]=tmp[i];
    }
}



int main(){
    // freopen("out","w",stdout);
    string aa,bb;
    char ch;
    // cin>>aa>>bb;
    while(ch=getchar()){
        if(ch==' '||ch=='\n')break;
        aa+=ch;
    }
    while(ch=getchar()){
        if(ch==' '||ch=='\n')break;
        bb+=ch;
    }
    // for( int i = 0 ; i < 1000000 ; ++ i ) aa.push_back( '1' ) , bb.push_back( '2' );
    int lena=aa.size(),lenb=bb.size();
    for(int i=0;i<aa.size();i++){
        a[i]=aa[aa.size()-1-i]-'0';
    }
    for(int i=0;i<bb.size();i++){
        b[i]=bb[bb.size()-1-i]-'0';
    }
    int t=lena+lenb+1;
    for(;t;t>>=1,n<<=1);
    COMP tt(1,0),_tt(1,0),s(cos(2*PI/n),sin(2*PI/n)),_s(cos(2*PI/n),-sin(2*PI/n));
    for(int i=0;i<n;i++){
        rot[i]=tt;
        rot2[i]=_tt;
        tt=tt*s;
        _tt=_tt*_s;
    }

    DFT(a,n,-1,0);
    DFT(b,n,-1,0);
    for(int i=0;i<n;++i){
        ans[i]=a[i]*b[i];
    }
    DFT(ans,n,1,0);
    for(int i=0;i<n;++i){
        _ans[i]=floor(ans[i].real()+0.5)/n;
    }
    flatten(_ans,n);
    int len=n;
    while(!_ans[len-1]&&len>=1)len--;
    for(int i=len-1;i>=0;--i)putchar( _ans[i] + '0' );
    return 0;
}