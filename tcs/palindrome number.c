#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
 int num=atoi(argv[1]);
 if(isPalindrome(num))
 printf("Palindrome");
 else
 printf("Not Palindrome");
 
 return 0;
}
int isPalindrome(int n)
{
 int m=n;
 int rev=0;
 while(m!=0)
 {
 rev=(rev*10) + (m%10);
 m=m/10;
 }
 if(rev==n)
 return 1;
 else
 return 0;
}
