#include <bits/stdc++.h>
using namespace std;
int main(){
    int score1=0,score2=0,cnt=0;
    char a[114514]={0};
    char ch=getchar();a[cnt++]=ch;
    while(ch!='E'){
        if(ch=='\n'){
            ch=getchar();a[cnt++]=ch;
            continue;
        }else if(ch=='W'){
            score1++;
        }else if(ch=='L'){
            score2++;
        }
        if(score1==11&&score2<=9){
            cout<<score1<<':'<<score2<<endl;
            score1=score2=0;
        }else if(score1<=9&&score2==11){
            cout<<score1<<':'<<score2<<endl;
            score1=score2=0;
        }else if(score1>=10&&score2>=10&&abs(score1-score2)>=2){
            cout<<score1<<':'<<score2<<endl;
            score1=score2=0;
        }
        ch=getchar();a[cnt++]=ch;
    }
    cout<<score1<<':'<<score2<<endl;
    score1=score2=0;

    cout<<endl;
    //--------------------------------------------------------------

    cnt=0;
    ch=a[cnt++];
    while(ch!='E'){
        if(ch=='\n'){
            ch=a[cnt++];
            continue;
        }else if(ch=='W'){
            score1++;
        }else if(ch=='L'){
            score2++;
        }
        if(score1==21&&score2<=19){
            cout<<score1<<':'<<score2<<endl;
            score1=score2=0;
        }else if(score1<=19&&score2==21){
            cout<<score1<<':'<<score2<<endl;
            score1=score2=0;
        }else if(score1>=20&&score2>=20&&abs(score1-score2)>=2){
            cout<<score1<<':'<<score2<<endl;
            score1=score2=0;
        }
        ch=a[cnt++];
    }
    cout<<score1<<':'<<score2<<endl;
    score1=score2=0;
    return 0;
}