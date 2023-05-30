#include <bits/stdc++.h>

using namespace std;

int Writefile1(char *fname){
    FILE *fp=NULL;
    char ch;
    fp=fopen(fname,"w+");
    if(fp!=NULL){
        cout<<"从键盘中输入内容,在空行处以Ctrl—z结束"<<endl;
        ch=getchar();
        while(ch!=EOF){
            fputc(ch,fp);
            ch=getchar();
        }
        fclose(fp);
        return 1;
    }else{
        return -1;
    }
}

int Readfile1(char *fname){
    FILE *fp=NULL;
    char ch;
    fp=fopen(fname,"r");
    if(fp!=NULL){
        ch=fgetc(fp);
        while(ch!=EOF){
            putchar(ch);
            ch=fgetc(fp);
        }
        fclose(fp);
        return 1;
    }else{
        return -1;
    }
}

int Readfile2(char *fname){
    FILE *fp=NULL;
    char buffer[1024],*p;
    fp=fopen(fname,"r");
    if(fp!=NULL){
        p=fgets(buffer,1024,fp);
        while(p!=NULL){
            cout<<buffer;
            p=fgets(buffer,1024,fp);
        }
        fclose(fp);
    }else{
        return -1;
    }
}



int main(){
    char a[100] = "D:\\NOTE\\luogu\\20221213\\test.txt";
    // Writefile1(a);
    // Readfile1(a);
    // Readfile2(a);
    
    return 0;
}