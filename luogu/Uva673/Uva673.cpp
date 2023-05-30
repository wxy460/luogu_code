#include <bits/stdc++.h>

using namespace std;

stack<char> s;
int num;

char trans(char a){
    if(a==')')return '(';
    if(a==']')return '[';
    if(a=='}')return '{';
    return '\0';
}

int main(){
    cin>>num;
    string p;
    getline(cin,p);
    while(num--){
        while(!s.empty())s.pop();
        getline(cin,p);
        for(int i=0;i<p.size();i++){
            if(s.empty()){
                s.push(p[i]);
                continue;
            }
            if(s.top()==trans(p[i]))s.pop();
            else s.push(p[i]);
        }
        if(s.empty()){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}