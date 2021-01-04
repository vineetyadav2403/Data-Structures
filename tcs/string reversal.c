// using command line
#include <stdio.h>
 

#include <string.h>
 
#include <stdlib.h>
 
int main(int argc, char *argv[])
{
 int k;
 char temp;
 int i,j=0;
 int strsize = 0;
 for (i=1; i<argc; i++) {
 strsize += strlen(argv[i]);
 if (argc > i+1)
 strsize++;
 }
 char *cmdstring;
 cmdstring = malloc(strsize);
 cmdstring[0] = '\0';
 for (k=1; k<argc; k++) {
 strcat(cmdstring, argv[k]);
 if (argc > k+1)
 strcat(cmdstring, " ");
 }
 i = 0;
 j = strlen(cmdstring) - 1;
 while (i < j) {
 temp = cmdstring[i];
 cmdstring[i] = cmdstring[j];
 cmdstring[j] = temp;
 i++;
 j--;
 }
 printf("\nReverse string is :%s", cmdstring);
 return(0);
 
}
