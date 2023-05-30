#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int x;
    int y;
}pos;

double dis(pos a,pos b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main(){
    pos a,b,c;
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
    double cir;
    cir=dis(a,b)+dis(b,c)+dis(c,a);
    cout<<fixed<<setprecision(2)<<cir<<endl;
    // printf("%.2lf",cir);
    return 0;
}