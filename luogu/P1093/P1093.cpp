#include <bits/stdc++.h>

using namespace std;

struct stu{
    int num;
    int C;
    int M;
    int E;
    int sum;
    stu(int n=0,int c=0,int m=0,int e=0,int s=0):num(n),C(c),M(m),E(m),sum(s){}
};

stu a[302];
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i].C>>a[i].M>>a[i].E;a[i].num=i;a[i].sum=a[i].C+a[i].M+a[i].E;}
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i].sum<a[j].sum)swap(a[i],a[j]);
            else if(a[i].sum==a[j].sum&&a[i].C<a[j].C)swap(a[i],a[j]);
            else if(a[i].sum==a[j].sum&&a[i].C==a[j].C&&a[i].num>a[j].num)swap(a[i],a[j]);
        }
    }
    for(int i=1;i<=5;i++){
        cout<<a[i].num<<" "<<a[i].sum<<endl;
    }
    return 0;
}