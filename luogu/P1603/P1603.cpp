#include <bits/stdc++.h>

using namespace std;

string a[30]={"","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"};

string tr(string x){
    for(int i=1;i<=20;i++){
        if(x==a[i]){
            int tmp=i*i%100;
            string ret=to_string(tmp);
            while(ret.size()<2){
                ret=ret.insert(0,"0");
            }
            return ret;
        }
    }
    if(x=="a"||x=="anothor"||x=="first"){
        return "01";
    }else if(x=="both"||x=="second"){
        return "04";
    }else if(x=="third"){
        return "09";
    }else{
        return "";
    }
}

int main(){
    string w[10],t[10],ans="0";
    for(int i=0;i<6;i++){
        cin>>w[i];
        ans+=tr(w[i]);
    }
    while(ans[0]=='0'&&ans.size()>1){
        ans=ans.substr(1,ans.size()-1);
    }
    cout<<ans;
    return 0;
}