#include <bits/stdc++.h>

using namespace std;

#define eps 1e-4

double A,B,C,D;

double F(double x){
    return A*x*x*x+B*x*x+C*x+D;
}

int main(){
    cin>>A>>B>>C>>D;
    for(int i=-100;i<100;i++){
        double l=i,r=i+1,mid;
        if(fabs(F(l))<eps)cout<<fixed<<setprecision(2)<<l<<" ";
        else if(fabs(F(r))<eps)continue;
        else if(F(l)*F(r)<0){
            while(r-l>eps){
                mid=(r+l)/2;
                if(F(mid)*F(l)>0)l=mid;
                else r=mid;
            }
            cout<<fixed<<setprecision(2)<<mid<<" ";
        }
    }
    return 0;
}