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
    memset(s,0,sizeof(s));
    return ret;
}

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

string jc(int n){
    if(n==0){
        return "1";
    }else if(n==1){
        return "1";
    }else{
        return mul(jc(n-1),to_string(n));
    }
}

string jch(int n){
    string ret="0";
    for(int i=1;i<=n;i++){
        string tmp="0";
        tmp=add(ret,jc(i));
        ret=tmp;
    }
    return ret;
}

int main(){
    int n;
    cin>>n;
    cout<<jch(n)<<endl;
    return 0;
}