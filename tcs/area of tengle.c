#include<stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  if (argc < 3)// as number of arguments needed are 2 and 1 is default arg.
  {
   printf(" Please provide values for both base and height \n");
   return 0;
  }
else
 {
  int base = atoi(argv[1]);
  int height = atoi(argv[2]);
  float area = 0.5*base*height;
  printf("%.2f",area);
  return 0;
 }
}


//********************
#include<stdio.h>
#include<math.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
if(argc==1)
{
printf(“No command line argument present, pls add them first”);
return 0;
}
else
{
int a, b, c;
float area,s;
a=atoi(argv[1]);
b=atoi(argv[2]);
c=atoi(argv[3]);
s=(a+b+c)/3;
area=sqrt(s*(s-a)*(s-b)*(s-c));
printf(“Area is %f”,area);
return 0;
}
}
