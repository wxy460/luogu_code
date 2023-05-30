#include <bits/stdc++.h>
using namespace std;

string A,B,C,D;
int num[30]={0},last[402]={0},alp[30],isprt[402][30]={0};

void update(string x){
    for(int i=0;x[i];i++){
        // for(int j=0;j<26;j++){
        //     if(x[i]=='A'+j){
        //         num[j]++;
        //     }
        // }
        if(isupper(x[i])){
            int pos=lower_bound(alp,alp+26,x[i])-alp;
            num[pos]++;
        }
    }
}

int main(){
    for(int i=0;i<26;i++)alp[i]=i+'A';
    getline(cin,A);update(A);
    getline(cin,B);update(B);
    getline(cin,C);update(C);
    getline(cin,D);update(D);
    int max=-1;
    for(int i=0;i<26;i++){
        if(num[i]>max){
            max=num[i];
        }
    }
    for(int i=0;i<max;i++){
        for(int j=0;j<26;j++){
            if(max-i<=num[j]){
                isprt[i][j]=1;
                last[i]=j;
            }
        }
    }
    for(int i=0;i<max;i++){
        for(int j=0;j<last[i];j++){
            if(isprt[i][j])cout<<'*'<<' ';
            else cout<<"  ";
        }
        cout<<'*'<<endl;
    }
    for(int i=0;i<25;i++)cout<<(char)alp[i]<<' ';
    cout<<(char)alp[25];
    return 0;
}