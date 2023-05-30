#include <bits/stdc++.h>

using namespace std;

bool iseq(int n,char a[14][14],char b[14][14]){
    int t=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]!=b[i][j]){
                t=0;
            }
        }
    }
    return t;
}

void spin(int n,char a[14][14]){
    int t[14][14]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            t[j][n-1-i]=a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=t[i][j];
        }
    }
}

void mir(int n,char a[14][14]){
    int t[14][14]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            t[i][n-1-j]=a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=t[i][j];
        }
    }
}

int main(){
    int n;
    char a[14][14]={0},b[14][14]={0};
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>b[i][j];
        }
    }
    char t1[14][14],t2[14][14],t3[14][14];
    char r[14][14];
    char r1[14][14],r2[14][14],r3[14][14];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            t1[i][j]=a[i][j];
            t2[i][j]=a[i][j];
            t3[i][j]=a[i][j];
            r[i][j]=a[i][j];
            r1[i][j]=a[i][j];
            r2[i][j]=a[i][j];
            r3[i][j]=a[i][j];
        }
    }
    spin(n,t1);
    spin(n,t2);spin(n,t2);
    spin(n,t3);spin(n,t3);spin(n,t3);
    mir(n,r);
    mir(n,r1);spin(n,r1);
    mir(n,r2);spin(n,r2);spin(n,r2);
    mir(n,r3);spin(n,r3);spin(n,r3);spin(n,r3);
    if(iseq(n,b,t1)){
        cout<<"1"<<endl;
    }else if(iseq(n,b,t2)){
        cout<<"2"<<endl;
    }else if(iseq(n,b,t3)){
        cout<<"3"<<endl;
    }else if(iseq(n,b,r)){
        cout<<"4"<<endl;
    }else if(iseq(n,b,r1)||iseq(n,b,r2)||iseq(n,b,r3)){
        cout<<"5"<<endl;
    }else if(iseq(n,b,a)){
        cout<<"6"<<endl;
    }else{
        cout<<"7"<<endl;
    }
    return 0;
}