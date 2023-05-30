#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int num;
    string name;
    string sex;
    int age;
    int score;
} Studenttype;

Studenttype aStu[4]={
    {201601,"yaya","m",18,80},
    {201602,"wawa","m",24,89},
    {201603,"kiki","m",26,90},
    {201604,"momo","f",23,68}
},stu;

int main(){
    FILE *fp=NULL;
    if((fp=fopen("stu.dat","wb+"))!=NULL){
        fwrite(aStu,sizeof(Studenttype),4,fp);
        fclose(fp);
    }
    if((fp=fopen("stu.dat","rb+"))==NULL) return 0;
    cout<<"学号"<<"\t"<<"姓名"<<"\t"<<"性别"<<"\t"<<"年龄"<<"\t"<<"成绩"<<endl;
    fread(&stu,sizeof(Studenttype),1,fp);
    while(!feof(fp)){
        cout<<stu.num<<"\t"<<stu.name<<"\t"<<stu.sex<<"\t"<<stu.age<<"\t"<<stu.score<<"\t"<<endl;
        fread(&stu,sizeof(Studenttype),1,fp);
    }
    return 0;
}