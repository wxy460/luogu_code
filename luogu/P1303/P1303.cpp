#include <bits/stdc++.h>

using namespace std;

int c[11451]={0},d[11451]={0},s[11451]={0};

string mul(string a,string b){
    for(int i=a.size()-1;i>=0;i--)
        c[a.size()-1-i]=a[i]-'0';
    for(int i=b.size()-1;i>=0;i--)
        d[b.size()-1-i]=b[i]-'0';
    for(int i=0;i<a.size();i++)
        for(int j=0;j<b.size();j++)
            s[i+j]+=c[i]*d[j];
    int len=a.size()+b.size();
    for(int i=0;i<len;i++){
        s[i+1]+=s[i]/10;
        s[i]%=10;
    }
    while(!s[len-1]){
        len--;
    }
    string ret;
    for(int i=max(0,len-1);i>=0;i--)
        ret+=s[i]+'0';
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    return ret;
}

int main(){
    string a,b;
    cin>>a>>b;
    cout<<mul(a,b)<<endl;
    return 0;
}