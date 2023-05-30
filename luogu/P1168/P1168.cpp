#include <bits/stdc++.h>

using namespace std;

priority_queue<int> p;
priority_queue<int,vector<int>,greater<int>> q;
int n;
vector<int> a;

int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        int tmp;cin>>tmp;
        a.push_back(tmp);
    }
    q.push(a[0]);cout<<a[0]<<endl;
    for(int i=2;i<n;i+=2){
        int mid=q.top();
        if(a[i-1]<mid){
            p.push(a[i-1]);
        }else{
            q.push(a[i-1]);
        }
        mid=q.top();
        if(a[i]<mid){
            p.push(a[i]);
        }else{
            q.push(a[i]);
        }
        while(p.size()>i/2)q.push(p.top()),p.pop();
        while(q.size()>i/2+1)p.push(q.top()),q.pop();
        cout<<q.top()<<endl;
    }
    return 0;
}