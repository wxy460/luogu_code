#include <bits/stdc++.h>

using namespace std;

int a[10];

int main(){
    long long A,B,C;
    int cnt=0;
    cin>>A>>B>>C;
    for(int i=1;i<=9;i++)a[i]=i;
    do{
        int x=a[1]*100+a[2]*10+a[3];
        int y=a[4]*100+a[5]*10+a[6];
        int z=a[7]*100+a[8]*10+a[9];
        if(x*B==y*A&&x*C==z*A){cout<<x<<" "<<y<<" "<<z<<endl;cnt++;}
    }while(next_permutation(a+1,a+10));
    if(!cnt)cout<<"No!!!"<<endl;
    return 0;
}