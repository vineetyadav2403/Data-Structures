#include<stdio.h>
int main(int argc,char *argv[])
{
 int n,s=0,b=1,r;
 n=atoi(argv[1]);
 int c=n;
 while(c>0)
 {
 r=c%8;
 s=s+r*b;
 c=c/8;
 b=b*10;
 }
 printf("%d",s);
 getch();
}
