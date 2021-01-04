[code language="cpp"]
// Program to print all value of
// command line argument
// once we get the value from command
// line we can use them to solve our problem
#include <stdio.h>

int main(int argc, char *argv[])
{
int a,b;
int i;
if(argc<2)
{
printf("please use \"prg_name value1 value2 ... \"\n");
return -1;
}
 
for(i=1; i<argc; i++)
{
printf("arg[%2d]: %d\n",i,atoi(argv[i]));
}


return 0;
}
[/code]
