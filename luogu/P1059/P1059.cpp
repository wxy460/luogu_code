#include <bits/stdc++.h>

#define M 114

using namespace std;

int a[M],b[M];

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>a[i];
    int cnt=1;b[0]=a[0];
    for(int i=1;i<N;i++){
        int isrp=0;
        for(int j=0;j<i;j++){
            if(a[j]==a[i])
                isrp=1;
        }
        if(!isrp)
            b[cnt++]=a[i];
    }
    sort(b,b+cnt);
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)
        cout<<b[i]<<" ";
    cout<<endl;
    return 0;
}