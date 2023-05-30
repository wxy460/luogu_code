//未用二分超时
#include <bits/stdc++.h>

using namespace std;

int n,c,x[100010],ans=0,cnt=1;

int main(){
    cin>>n>>c;
    for(int i=0;i<n;i++)cin>>x[i];
    sort(x,x+n);
    do{
        int tmp=x[0];
        cnt=1;
        ans++;
        for(int i=1;i<n;i++){
            if(x[i]-tmp>=ans){
                cnt++;
                tmp=x[i];
            }
        }
    }while(cnt>=c);
    cout<<ans-1;
    return 0;
}