#include <iostream>
#include <string>
using namespace std;

string A,B;
int ans=0,_ans;

int main(){
    cin>>A>>B;
    for(int i=0;i<A.size()-1;i++){
        for(int j=1;j<B.size();j++){
            if(A[i]==B[j]&&A[i+1]==B[j-1]){
                ans++;
            }
        }
    }
    _ans=1<<ans;
    cout<<_ans<<endl;
    return 0;
}