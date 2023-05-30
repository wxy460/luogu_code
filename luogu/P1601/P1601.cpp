#include <bits/stdc++.h>

using namespace std;

string add(string a,string b){
    string c,d;
    int len=max(a.size(),b.size());
    for(int i=a.size()-1;i>=0;i--){
        c+=a[i];
    }
    for(int i=b.size()-1;i>=0;i--){
        d+=b[i];
    }
    while(c.size()<len){
        c+="0";
    }
    while(d.size()<len){
        d+="0";
    }
    string s;
    char tmp='0';
    for(int i=0;i<len;i++){
        s+=(c[i]+d[i]+tmp-'0'-'0'-'0')%10+'0';
        tmp=(c[i]+d[i]+tmp-'0'-'0'-'0')/10+'0';
    }
    if(tmp=='1'){
        s+='1';
    }
    string ret;
    for(int i=s.size()-1;i>=0;i--){
        ret+=s[i];
    }
    return ret;
}

int main(){
    string a,b;
    cin>>a>>b;
    cout<<add(a,b)<<endl;
    return 0;
}