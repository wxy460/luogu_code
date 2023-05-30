#include <bits/stdc++.h>

using namespace std;

int a[114]={0};

int main(){
    int N,cnt;cin>>N;
    for(int i=0;i<N;i++)cin>>a[i];
    sort(a,a+N);
    cnt=unique(a,a+N)-a;//unique返回末元素指针,且只能对有序数组使用
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)cout<<a[i]<<" ";
    return 0;
}