#include <bits/stdc++.h>

using namespace std;

extern int errno;

int main(){
    FILE *fp=NULL;
    fp=fopen("luogu\\20221208\\abcde.txt","w+");
    char a[100]={0};
    scanf("%s",a);
    if(fp!=NULL){
        fprintf(fp,a);
        fclose(fp);
    }else{
        printf("open file error for %s\n",strerror(errno));
    }
    getchar();
    return 0;
}