//数组+二分
#include <bits/stdc++.h>
#define maxn 10010
using namespace std;

int q,op,x,a[maxn],n=0;

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d %d",&op,&x);
        switch(op){
            case 1:cout<<lower_bound(a,a+n,x)-a+1<<endl;break;
            case 2:cout<<a[x-1]<<endl;break;
            case 3:{int pos=lower_bound(a,a+n,x)-a-1;
            if(pos>=0)cout<<a[pos]<<endl;
            else cout<<-2147483647<<endl;
            break;}
            case 4:{int _pos=upper_bound(a,a+n,x)-a;
            if(_pos<n)cout<<a[_pos]<<endl;
            else cout<<2147483647<<endl;
            break;}
            case 5:{a[n++]=x;sort(a,a+n);break;}
            default:break;
        }
    }
    return 0;
}