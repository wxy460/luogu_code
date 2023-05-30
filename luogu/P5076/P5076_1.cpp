#include <bits/stdc++.h>

using namespace std;

multiset<int> Q;

int q;

int main(){
    cin>>q;
    Q.insert(-0x7fffffff);
    Q.insert(0x7fffffff);
    while(q--){
        int op,x;cin>>op>>x;
        switch(op){
            case 1:{
                int k=0;
                for(multiset<int>::iterator it=Q.begin();it!=Q.lower_bound(x);it++,k++);
                cout<<k<<endl;
                break;
            }
            case 2:{
                multiset<int>::iterator it=Q.begin();
                for(int i=0;i<x;i++,it++);
                cout<<*it<<endl;
                break;
            }
            case 3:{
                multiset<int>::iterator it=Q.lower_bound(x);
                cout<<*--it<<endl;
                break;
            }
            case 4:{
                multiset<int>::iterator it=Q.upper_bound(x);
                cout<<*it<<endl;
                break;
            }
            case 5:{
                Q.insert(x);
                break;
            }
            default:break;
        }
    }
    return 0;
}