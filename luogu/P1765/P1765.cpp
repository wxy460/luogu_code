#include <bits/stdc++.h>

using namespace std;

string a1="adgjmptw";
string a2="behknqux";
string a3="cfilorvy";
string a4="sz";

int main(){
    string a;
    int count=0;
    getline(cin,a);
    for(int i=0;i<a.size();i++){
        if(~a1.find(a[i])){
            count++;
        }else if(~a2.find(a[i])){
            count+=2;
        }else if(~a3.find(a[i])){
            count+=3;
        }else if(~a4.find(a[i])){
            count+=4;
        }else if(a[i]==' '){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}