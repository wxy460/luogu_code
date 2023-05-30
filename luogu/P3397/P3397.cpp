//暴力不可取
#include <bits/stdc++.h>

using namespace std;

int n,m,x_1,y_1,x_2,y_2,p[110][110];

void update(){
    for(int i=x_1;i<=x_2;i++){
        for(int j=y_1;j<=y_2;j++){
            p[i][j]++;
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x_1>>y_1>>x_2>>y_2;
        update();
    }
    for(int i=1;i<=n;i++,puts(""))
    for(int j=1;j<=n;j++)
    cout<<p[i][j]<<" ";
    return 0;
}