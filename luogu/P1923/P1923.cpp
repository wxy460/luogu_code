#include <bits/stdc++.h>

using namespace std;

int ans=0,k,a[5000001]={0};

//nth_element(a,a+k,a+n);可以让第k小的数被排在k的位置。再cout<<a[k];就可以了
//当然从大到小可以加一个cmp函数或者greater<int>()的参数。

void findkth(int a[],int l,int r){
    if(l==r){
        ans=a[l];
        return;
    }
    int i=l,j=r,flag=a[(l+r)/2];
    do{
        while(a[i]<flag)i++;
        while(a[j]>flag)j--;
        if(i<=j){
            swap(a[i++],a[j--]);
            // int tmp=a[i];
            // a[i]=a[j];
            // a[j]=tmp;
            // i++;j--;
        }
    }while(i<=j);
    if(k<=j)findkth(a,l,j);
    else if(k>=i)findkth(a,i,r);
    else findkth(a,j+1,i-1);
}

int main(){
    //解除同步,使cin读入变快
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    findkth(a,0,n-1);
    cout<<ans;
    return 0;
}