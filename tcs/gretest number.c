
#include <stdio.h>

int main(int argc, char *argv[])

{

int c[10];

int i,temp,j,greatest;

j = 0;

for(i=1; i<argc; i++)

{

temp = atoi(argv[i]);

c[j] = temp;

j++;

}

greatest = c[0];

for (i = 0; i < 10; i++) {

if (c[i] > greatest) {

greatest = c[i];

}

}

printf("Greatest of ten numbers is %d", greatest);

return 0;

}
