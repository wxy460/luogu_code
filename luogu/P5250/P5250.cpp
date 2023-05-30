#include <iostream>
#include <set>
using namespace std;
int N,op,len;
set<int> l;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>op>>len;
        if(op==1){
            if(l.find(len)!=l.end()){
                cout<<"Already Exist"<<endl;
            }else{
                l.insert(len);
            }
        }else if(op==2){
            if(!l.empty()){
                auto pos=l.lower_bound(len);
                if(len==*pos){
                    cout<<*pos<<endl;
                    l.erase(pos);
                }else{
                    auto _pos=pos;
                    if(_pos!=l.begin())pos--;
                    if(_pos==l.end()||len-*pos<=*_pos-len){
                        cout<<*pos<<endl;
                        l.erase(pos);
                    }else if(len-*pos>*_pos-len){
                        cout<<*_pos<<endl;
                        l.erase(_pos);
                    }
                }
            }else{
                cout<<"Empty"<<endl;
            }
        }
    }
    return 0;
}