#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    char a[114][114]={0},b[114][114]={0};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='*'){
                b[i][j]=a[i][j];
            }else if(a[i][j]=='?'){
                char t='0';
                if(a[i-1][j]=='*'){
                    t++;
                }
                if(a[i+1][j]=='*'){
                    t++;
                }
                if(a[i][j-1]=='*'){
                    t++;
                }
                if(a[i][j+1]=='*'){
                    t++;
                }
                if(a[i+1][j+1]=='*'){
                    t++;
                }
                if(a[i-1][j+1]=='*'){
                    t++;
                }
                if(a[i+1][j-1]=='*'){
                    t++;
                }
                if(a[i-1][j-1]=='*'){
                    t++;
                }
                b[i][j]=t;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<b[i][j];
        }
        cout<<endl;
    }
    return 0;
}