#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
 int n1,n2,x,y;
 if (argc == 1 || argc > 3)
 {
 printf("Enter Two Number\r\n");
 exit(0);
 }
 x=atoi(argv[1]);
 y=atoi(argv[2]);
 n1 = x; n2 = y;
 while(n1!=n2){
 if(n1>n2)
 n1=n1-n2;
 else
 n2=n2-n1;
 }
 printf("L.C.M of %d & %d = %d \r\n",x,y,x*y/n1);
 return 0;
}
