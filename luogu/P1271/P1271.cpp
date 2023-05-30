#include <bits/stdc++.h>

using namespace std;

//wrong ans:数据量大超时了
// #define M 2000006

// int a[M]={0};

// int main(){
//     int n,m;
//     cin>>n>>m;
//     for(int i=0;i<m;i++){
//         cin>>a[i];
//     }
//     for(int i=0;i<m;i++){
//         int k=i;
//         for(int j=i+1;j<m;j++){
//             if(a[k]>a[j]){
//                 k=j;
//             }
//         }
//         if(k!=i)
//             swap(a[i],a[k]);
//     }
//     for(int i=0;i<m;i++){
//         cout<<a[i]<<" ";
//     }
//     return 0;
// }

//计数排序

int a[1006]={0};

int main(){
    int n,m,tmp;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>tmp;
        a[tmp]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<a[i];j++){
            cout<<i<<" ";
        }
    }
    return 0;
}