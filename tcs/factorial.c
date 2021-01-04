//**************************
#include <stdio.h>
int main(int argc, char *argv[])

{

int n,i;

unsigned long long factorial = 1;

n = atol(argv[1]);

for(i=1; i<=n; ++i)

{

factorial *= i;

}

printf(“Factorial of %d = %llu”, n, factorial);

}
//***********************
#include <stdio.h> // for printf
#include <stdlib.h> // for function atoi() for converting string into int
// Function to return fact value of n
int fact(int n)
{
 if (n == 0)
 return 1;
 else {
 int ans = 1;
 int i;
 for (i = 1; i <= n; i++) {
 ans = ans * i;
 }
 return ans;
 }
}
// argc tells the number of arguments
// provided+1 +1 for file.exe
// char *argv[] is used to store the
// command line arguments in the string format
int main(int argc, char* argv[])
{
 // means only one argument exist that is file.exe
 if (argc == 1) {
 printf("No command line argument exist Please provide them first \n");
 return 0;
 } else {
 int i, n, ans;
 // actual arguments starts from index 1 to (argc-1)
 for (i = 1; i < argc; i++) {
 // function of stdlib.h to convert string
 // into int using atoi() function
 n = atoi(argv[i]);
 
 // since we got the value of n as usual of
 // input now perform operations
 // on number which you have required
 
 // get ans from function
 ans = fact(n);
 
 // print answer using stdio.h library's printf() function
 printf("%d\n", ans);
 }
 return 0;
 }
}

//*************************************
