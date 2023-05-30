#include <bits/stdc++.h>

using namespace std;

//标答也是很有意思的,我自己的解答也很有意思

int main(){
    int A,B,C;cin>>A>>B>>C;
    if(A==0||B==0||C==0){cout<<"No!!!";return 0;}
    bool isfd=false;
    for(int a=1;a<=9;a++){
        for(int b=1;b<=9;b++){
            for(int c=1;c<=9;c++){
                if(a==b||b==c||c==a)continue;
                int tmp1=a*100+b*10+c;
                if(tmp1%A!=0)continue;
                int tmp2=tmp1*B/A;
                int tmp3=tmp1*C/A;
                if(tmp2>999||tmp2<100||tmp3>999||tmp3<100)continue;
                int d=tmp2/100%10;if(d==0)continue;
                int e=tmp2/10%10;if(e==0)continue;
                int f=tmp2%10;if(f==0)continue;
                int g=tmp3/100%10;if(g==0)continue;
                int h=tmp3/10%10;if(h==0)continue;
                int i=tmp3%10;if(i==0)continue;
                int arr[9];
                arr[0]=a;
                arr[1]=b;
                arr[2]=c;
                arr[3]=d;
                arr[4]=e;
                arr[5]=f;
                arr[6]=g;
                arr[7]=h;
                arr[8]=i;
                sort(arr,arr+9);
                int len=unique(arr,arr+9)-arr;
                if(len==9){cout<<tmp1<<" "<<tmp2<<" "<<tmp3<<endl;isfd=true;}
            }
        }
    }
    if(!isfd){
        cout<<"No!!!"<<endl;
    }
    return 0;
}