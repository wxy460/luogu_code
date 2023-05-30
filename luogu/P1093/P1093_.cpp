#include <bits/stdc++.h>

using namespace std;

struct stu{
    int num,chinese,sum;
}a[306];

bool cmp(stu a,stu b){
    if(a.sum!=b.sum)return a.sum>b.sum;   
    if(a.chinese!=b.chinese)return a.chinese>b.chinese;   
    return a.num<b.num;   
}

int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int c,m,e;
        cin>>c>>m>>e;
        a[i].num=i+1;
        a[i].chinese=c;
        a[i].sum=c+m+e;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<5;i++)cout<<a[i].num<<" "<<a[i].sum<<endl;
    return 0;
}