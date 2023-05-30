#include <bits/stdc++.h>

using namespace std;
const int MAXN=1e3+2;
typedef long long LL;
LL n,m,f[MAXN][MAXN],l[MAXN],r[MAXN],ans;
char ch;
stack<int> s1,s2;

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>ch;
            if(ch=='*'){
                f[i][j]=0;
            }else{
                f[i][j]=f[i-1][j]+1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        f[i][0]=f[i][m+1]=-1;
    }
    for(int i=1;i<=n;i++){
        while(!s1.empty())s1.pop();
        while(!s2.empty())s2.pop();
        s1.push(1);
        s2.push(m);
        for(int k=2,t=m-1;k<=m+1&&t>=0;k++,t--){
            while(!s1.empty()&&f[i][k]<f[i][s1.top()]){
                r[s1.top()]=k;
                s1.pop();
            }
            while(!s2.empty()&&f[i][t]<=f[i][s2.top()]){
                l[s2.top()]=t;
                s2.pop();
            }
            s1.push(k);
            s2.push(t);
        }
        for(int j=1;j<=m;j++){
            ans+=(r[j]-j)*(j-l[j])*f[i][j];
        }
    }
    cout<<ans<<endl;
    return 0;
}