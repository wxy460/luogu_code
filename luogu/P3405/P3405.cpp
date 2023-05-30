//wrong solution
#include <bits/stdc++.h>
using namespace std;

int N,ans=0;const int maxn=2e5+2;
string cow,city,cow_name[maxn];

map<string,string> a;

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>cow>>city;
        cow_name[i]=cow.substr(0,2);
        a[cow_name[i]]=city;
    }
    // for(int i=1;i<N;i++){
    //     for(int j=0;j<i;j++){
    //         if(a[cow_name[j]]==cow_name[i].substr(0,2)&&a[cow_name[i]]==cow_name[j].substr(0,2))
    //             ans++;
    //     }
    // }
    sort(cow_name,cow_name+N);
    for(int i=0;i<N;i++){
        int pos_1=lower_bound(cow_name,cow_name+N,a[cow_name[i]])-cow_name;
        int pos_2=upper_bound(cow_name,cow_name+N,a[cow_name[i]])-cow_name;
        if(pos_1!=-1&&pos_2!=-1){
            for(int j=pos_1;j<pos_2;j++){
                if(cow_name[i]==a[cow_name[j]])ans++;
            }
        }
    }
    cout<<ans/2;
    return 0;
}