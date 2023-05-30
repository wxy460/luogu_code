#include <cstdio>
#include <cmath>
double s(double x1,double y1,double x2,double y2){
	double s0;
	s0=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	return s0;
}


int main(){
	double a,b,c,d,e,f;
	scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f);
	double sum=0,s1,s2,s3;
	s1=s(a,b,c,d);
	s2=s(c,d,e,f);
	s3=s(e,f,a,b);
	sum=s1+s2+s3;
	printf("%.2lf",sum);
}
