#include <iostream>
#include <string>
using namespace std;

string A,B;

void pre(int l1,int r1,int l2,int r2){
    if(l1>r1||l2>r2)return;
    cout<<B[r2];
    for(int i=0;i<=r1;i++){
        if(A[i]==B[r2]){
            pre(l1,i-1,l2,l2-l1+i-1);
            pre(i+1,r1,l2-l1+i,r2-1);
            return;
        }
    }
}

int main(){
    cin>>A>>B;
    pre(0,A.size()-1,0,B.size()-1);
    return 0;
}