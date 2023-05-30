#include <bits/stdc++.h>

using namespace std;

int a[11451]={0};

int main(){
    int N,add;cin>>N>>add;
    for(int i=0;i<N;i++)cin>>a[i];
    for(int i=0;i<add;i++)next_permutation(a,a+N);
    for(int i=0;i<N;i++)cout<<a[i]<<" ";
    return 0;
}