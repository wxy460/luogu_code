//错解，递归效率不高，并且还有隐藏错误
#include <bits/stdc++.h>

using namespace std;

int a[1000010],tmp,n,m,ans=-1;

void find(int x,int p,int q){
    int flag=a[(p+q)/2];
    if(a[p]==x){
        while(a[p]==a[p-1]){
            p--;
        }
        ans=p+1;
        return;
    }else if(p==q||q==p+1){
        ans=-1;
        return;
    }

    if(x<flag){
        q=(p+q)/2;
        find(x,p,q);
    }else if(x>=flag){
        p=(p+q)/2;
        find(x,p,q);
    }
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cin>>n>>m;
    scanf("%d%d",&n,&m);
    // for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<m;i++){
        // cin>>tmp;
        scanf("%d",&tmp);
        find(tmp,0,n-1);
        cout<<ans<<" ";
    }
    return 0;
}