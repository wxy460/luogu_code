#include <bits/stdc++.h>

using namespace std;

struct cdt{
    string vote;
    int id;
}a[28];

bool cmp(cdt a,cdt b){
    if(a.vote.size()==b.vote.size())return a.vote>b.vote;
    return a.vote.size()>b.vote.size();
}

int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){cin>>a[i].vote;a[i].id=i+1;}
    sort(a,a+n,cmp);
    cout<<a[0].id<<endl<<a[0].vote;
    return 0;
}