#include<bits/stdc++.h>

using namespace std;

map<string,int> stu;
int N,op;
string x;

inline void insert(string nam,int score){
    stu[nam]=score;
    cout<<"OK"<<endl;
}

inline void find(string nam){
    if(stu.find(nam)!=stu.end()) cout<<stu[nam]<<endl;
    else cout<<"Not found"<<endl;
}

inline void delet(string nam){
    if(stu.find(nam)!=stu.end()){stu.erase(nam);cout<<"Deleted successfully"<<endl;}
    else cout<<"Not found"<<endl;
}

inline void all(){
    cout<<stu.size()<<endl;
}

int main(){
    cin>>N;
    while(N--){
        cin>>op;
        if(op==1){
            cin>>x;
            int score;cin>>score;
            insert(x,score);
        }else if(op==2){
            cin>>x;
            find(x);
        }else if(op==3){
            cin>>x;
            delet(x);
        }else if(op==4){
            all();
        }
    }
    return 0;
}