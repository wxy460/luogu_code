#include <bits/stdc++.h>

using namespace std;

bool isprm(int x){
    if(x==1){
        return false;
    }else if(x==3||x==2){
        return true;
    }else if(x%2==0){
        return false;
    }else if(x%6==1||x%6==5){
        for(int i=3;i<x/2;i+=2){
            if(x%i==0){
                return false;
            }
        }
        return true;
    }else{
        return false;
    }
}

int main(){
    int n;
    cin>>n;
    int a[114]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int b[114],cnt=0;
    for(int i=0;i<n;i++){
        if(isprm(a[i])){
            b[cnt++]=a[i];
        }
    }
    for(int i=0;i<cnt;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;
}