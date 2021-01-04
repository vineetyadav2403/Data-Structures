#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
bool isPrime(int n)
{
if(n<2)
return false;
int i;
for(i=2;i*i<=n;i++)
{
if(n%i==0)
return false;
}
return true;
}
int main(int argc, char *argv[])
{
if(argc==1)
{
printf("No arguments");
return 0;
}
else
{
int n;
n=atoi(argv[1]);
float sq=0;
if(isPrime(n))
{
sq=sqrt(n);
printf("%.2f",sq);
}
else
printf("%.2f",sq);
return 0;
}
}
