#include <iostream>

using namespace std;

const int maxn=120;
const int IFN=1e6;

int n,p[maxn][maxn],city_num[maxn],ans=0;

void floyed(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(p[i][k]!=IFN&&i!=k){
                for(int j=1;j<=n;j++){
                    if(i!=j&&k!=j&&p[i][k]+p[k][j]<p[i][j]){
                        p[i][j]=p[i][k]+p[k][j];
                    }
                }
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    if(i==j)p[i][i]=0;
    else p[i][j]=IFN;
    
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>city_num[i]>>u>>v;
        p[i][u]=p[u][i]=1;
        p[i][v]=p[v][i]=1;
    }
    floyed();
    int min=0x7fffffff;
    for(int i=1;i<=n;i++){
        ans=0;
        for(int j=1;j<=n;j++){
            if(i!=j&&p[j][i]!=IFN){
                ans+=p[j][i]*city_num[j];
            }
        }
        if(min>ans){
            min=ans;
        }
    }
    cout<<min<<endl;
    return 0;
}