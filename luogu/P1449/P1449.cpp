#include <bits/stdc++.h>

using namespace std;

stack<int> num;

int main(){
    string p,tmp;
    getline(cin,p);
    for(int i=0;p[i]!='@';i++){
        if(p[i]=='.'){
            int t=stoi(tmp);
            num.push(t);
            tmp="";
        }else if(isdigit(p[i])){
            tmp+=p[i];
        }else if(p[i]=='+'){
            int x=num.top();
            num.pop();
            int y=num.top();
            num.pop();
            int z=y+x;
            num.push(z);
        }else if(p[i]=='-'){
            int x=num.top();
            num.pop();
            int y=num.top();
            num.pop();
            int z=y-x;
            num.push(z);
        }else if(p[i]=='*'){
            int x=num.top();
            num.pop();
            int y=num.top();
            num.pop();
            int z=y*x;
            num.push(z);
        }else if(p[i]=='/'){
            int x=num.top();
            num.pop();
            int y=num.top();
            num.pop();
            int z=y/x;
            num.push(z);
        }
    }
    cout<<num.top()<<endl;
    return 0;
}