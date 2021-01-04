#include <stdio.h>

int main(int argc, char * argv[])
{
 int sum = 0,i = 1,count = 0;
 if(argc == 1)
 {
 printf("Enter the number \n");
 exit(1);
 }
 count = argc - 1;
 while (i <= count )
 {
 sum += atoi (argv[i]) ;
 i++;
 }
 printf("Avg of the numbers.%d\n", sum/count);
}
