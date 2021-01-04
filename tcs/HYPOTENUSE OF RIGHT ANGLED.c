CALCULATE LENGTH OF THE HYPOTENUSE OF RIGHT ANGLED TRIANGLE

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
 
if(argc<2)
{
printf("please use \"prg_name value1 value2 ... \"\n");
return -1;
}
 
int a,b,side1,side2,side3;
a=atoi(argv[1]);
b=atoi(argv[2]);
side1=pow(a,2);
side2=pow(b,2);
side3=sqrt((side1+side2));
printf("the hypotenuse is %d",side3);
return 0;
 
}
