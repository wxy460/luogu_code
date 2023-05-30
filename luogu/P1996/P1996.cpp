#include <bits/stdc++.h>

using namespace std;

queue<int> p;
vector<int> ans;

int n,m,cnt=0;

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        p.push(i);
    }
    while(p.size()!=0){
        if(++cnt%m==0){
            ans.push_back(p.front());
            p.pop();
        }else{
            int tmp=p.front();
            p.pop();
            p.push(tmp);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}