#include <iostream>
#include <vector>
const int MAXN=1e4+5;
using namespace std;

int n,m;

struct edge{
    int to,cost;
};

vector<edge> p[MAXN];

int v[MAXN][MAXN];

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,l;
        cin>>u>>v>>l;
        p[u].push_back({v,l});
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<p[i].size();j++){
            v[i][p[i][j].to]=p[i][j].cost;
        }
    }
    for(int i=1;i<=n;i++,puts(""))
    for(int j=1;j<=n;j++)
    cout<<v[i][j]<<" ";
    return 0;
}