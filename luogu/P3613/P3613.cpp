#include <bits/stdc++.h>

using namespace std;

int n,q,opt,i,j,k;

int main(){
    cin>>n>>q;
    vector<vector<int>> blocker(n+1);
    while(q--){
        cin>>opt;
        if(opt==1){
            cin>>i>>j>>k;
            if(blocker[i].size()<j+1)
                blocker[i].resize(j+1);
            blocker[i][j]=k;
        }else{
            cin>>i>>j;
            cout<<blocker[i][j]<<endl;
        }
    }
    return 0;
}