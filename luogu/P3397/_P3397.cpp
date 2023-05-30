#include <bits/stdc++.h>

using namespace std;

int n,m,x_1,y_1,x_2,y_2,p[1100][1100],add[1100][1100],sum;

void f(){
    for(int i=x_1;i<=x_2;i++){
        add[i][y_1]+=1;
        add[i][y_2+1]+=-1;
    }
}//差分标记

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x_1>>y_1>>x_2>>y_2;
        f();
    }
    for(int i=1;i<=n+1;i++){
        for(int j=1;j<=n+1;j++){
            sum+=add[i][j],p[i][j]=sum;
        }
    }
    for(int i=1;i<=n;i++,puts(""))
    for(int j=1;j<=n;j++)
    cout<<p[i][j]<<" ";
    return 0;
}