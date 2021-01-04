#include<stdio.h>
int main(int argc, char * argv[])
{
int num,temp,arms=0,rem;
if (argc!= 2)
{
 printf("Enter the number:\n");
 scanf("%d",&num);
}
else
{
 num = atoi(argv[1]);
}
 temp=num;
while(num>0)
{
 rem=num%10;
 arms=arms+rem*rem*rem;
 num=num/10;
}
if(temp==arms)
{
 printf(" \n%d is an Armstrong number",temp);
}
else
{
 printf("\n%d is not an Armstrong number",temp);
}
return 0;
}
