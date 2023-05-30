#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,vk=0,vv=0;
    string a;
    cin>>n>>a;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }else if(n==2){
        if(a=="KK"){
            cout<<1<<endl;
            return 0;
        }else if(a=="VK"){
            cout<<1<<endl;
            return 0;
        }else if(a=="KV"){
            cout<<0<<endl;
            return 0;
        }else if(a=="VV"){
            cout<<1<<endl;
            return 0;
        }
    }
    int fpos=a.find("VK");
    int npos=a.find("VK");
    int posv=a.find("VV");
    int posk=a.find("KKK");
    if(~posv){
        while(a[posv+2]=='K'&&~posv){
            posv=a.find("VV",posv+1);
        }
    }
    if(!~fpos){
        vk=0;
    }else if(~fpos){
        while(~npos){
            npos=a.find("VK",npos+1);
            vk++;
        }
    }
    if(!~posv){
        vv=0;
    }else if(~posv){
        vv=1;
    }
    if(~posk){
        vv=1;
    }
    if(a[0]=='K'&&a[1]=='K'){
        vv=1;
    }
    cout<<vk+vv<<endl;
    return 0;
}