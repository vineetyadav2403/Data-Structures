#include <stdio.h>

#include <string.h>

void isPalindrome(char str[])

{

int l = 0;

int h = strlen(str) - 1;

while (h > l)

{

if (str[l++] != str[h--])

{

printf("%s is Not Palindromen", str);

return;

}

}

printf("%s is palindromen", str);

}

int main(int argc, char *argv[])

{

int i,k;

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

isPalindrome(cmdstring);

}
