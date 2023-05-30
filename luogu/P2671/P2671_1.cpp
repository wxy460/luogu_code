#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN=1e5+22;
const int MOD=10007;

struct node{
    LL num,col;
}a[MAXN];

LL n,m,_sum;
vector<pair<LL,LL>> nu[2][MAXN];
vector<LL> sum_1[2][MAXN],sum_2[2][MAXN],sum_3[2][MAXN];


int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].num;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i].col;
    }
    for(int i=1;i<=n;i++){
        nu[i%2][a[i].col].push_back(make_pair(i,a[i].num));
    }
    for(int k=0;k<=1;k++){
        for(int i=1;i<=m;i++){
            LL s=0;
            if(nu[k][i].size()<2)continue;
            for(int j=0;j<nu[k][i].size();j++){
                if(j==0){
                    sum_1[k][i].push_back(nu[k][i][0].first%MOD);
                    sum_2[k][i].push_back(nu[k][i][0].second%MOD);
                    sum_3[k][i].push_back((nu[k][i][0].first*nu[k][i][0].second)%MOD);
                }else{
                    sum_1[k][i].push_back((sum_1[k][i][j-1]+nu[k][i][j].first)%MOD);
                    sum_2[k][i].push_back((sum_2[k][i][j-1]+nu[k][i][j].second)%MOD);
                    sum_3[k][i].push_back((sum_3[k][i][j-1]+nu[k][i][j].first*nu[k][i][j].second)%MOD);
                }
            }
            for(int j=0;j<nu[k][i].size();j++){
                if(j==0)s=(s+(nu[k][i][0].first+nu[k][i][1].first)*(nu[k][i][0].second+nu[k][i][1].second))%MOD;
                if(j>=2)s=(s+sum_1[k][i][j-1]*nu[k][i][j].second+sum_2[k][i][j-1]*nu[k][i][j].first+sum_3[k][i][j-1]+j*nu[k][i][j].first*nu[k][i][j].second)%MOD;
            }
            _sum=(_sum+s)%MOD;
        }
    }
    cout<<_sum<<endl;
    return 0;
}