#include <bits/stdc++.h>

using namespace std;

string expand(){
    string ans="",X;
    char ch;int D;
    while(cin>>ch){
        if(ch=='['){
            cin>>D;
            X=expand();
            while(D--)ans+=X;
        }else if(ch==']'){
            return ans;
        }else{
            ans+=ch;
        }
        
    }
    return ans;
}

int main(){
    cout<<expand();
    return 0;
}