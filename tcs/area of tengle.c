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
