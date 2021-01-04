
/*Write a C program that will find the sum of all prime numbers in a given range.
The range will be specified as command line parameters. The first command line parameter, 
N1 which is a positive integer, will contain the lower bound of the range.
The second command line parameter N2, which is also a positive integer will the upper bound of the range.
The program should consider all the prime numbers within the range, excluding the upper and lower bound.
Print the output in integer format to stdout. Other than the integer number, no other extra information should be printed to stdout.
*/

#include<stdio.h>
int main(int argc,char *argv[])
{
int N1,N2,i,j,sum=0,count,lower,upper;
if(argc!=3)
 exit(0);
N1=atoi(argv[1]);
lower=N1+1;
N2=atoi(argv[2]);
upper=N2;
 for(i=lower;i<upper;i++)
 {
 count=1;
 for(j=2;j<=i/2;j++)
 {
 if(i%j==0)
 {
 count++;
 }
 }
 if(count==1)
 {
 sum=sum+i;
 }
 }
 printf("%d",sum);
return 0;
}
