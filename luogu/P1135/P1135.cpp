#include <bits/stdc++.h>

using namespace std;

#define M 210

queue<int> flr;

int N,A,B,k[M],step[M]={0};

int main(){
    cin>>N>>A>>B;if(A==B){cout<<"0";return 0;}
    for(int i=1;i<=N;i++)cin>>k[i];
    flr.push(A);step[A]=0;
    while(!flr.empty()){
        int now=flr.front();
        flr.pop();
        int ifup=now+k[now];
        int ifdown=now-k[now];
        if(ifup<=N&&step[ifup]==0){
            step[ifup]=step[now]+1;
            flr.push(ifup);
        }
        if(ifdown>=1&&step[ifdown]==0){
            step[ifdown]=step[now]+1;
            flr.push(ifdown);
        }
        if(step[B]!=0){
            cout<<step[B];return 0;
        }
    }
    cout<<"-1";
    return 0;
}