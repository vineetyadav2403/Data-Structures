// using command line

#include
 
int main(int argc, char *argv[])
 
{
 
int n, first = 0, second = 1, next, c;
 
n = atoi(argv[1]);
 
printf("These are %d values in Fibonacci series are by MyGeekMonkey:-\n",n);
 
for ( c = 0 ; c < n ; c++ )
 
{
 
if ( c <= 1 )
 
next = c;
 
else
 
{
 
next = first + second;
 
first = second;
 
second = next;
 
}
 
printf("%d\n",next);
 
}
 
return 0;
 
}
