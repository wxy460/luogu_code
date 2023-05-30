#include <bits/stdc++.h>

using namespace std;

//快排
void qsort(int a[],int l,int r){
    int i=l,j=r,flag=a[(l+r)/2];
    do{
        while(a[i]<flag)i++;
        while(a[j]>flag)j--;
        if(i<=j)
            swap(a[i++],a[j--]);
    }while(i<=j);
    if(l<j)qsort(a,l,j);
    if(r>i)qsort(a,i,r);
}

int a[114514]={0};

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    qsort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}