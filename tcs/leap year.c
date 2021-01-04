#include<stdio.h>
void main(int argc,char *argv[])
{
 int n;
 n=atoi(argv[1]);
 if(n%4==0)
 {
 if(n%100==0)
 {
 if(n%400==0)
 
 printf("Leap Year");
 else
 printf("Not Leap Year");
 }
 else
 printf("Leap Year");
 }
 else
 printf("Not Leap Year");
 getch(); 
 
}
