#include<stdio.h>
int main(int argc, char *argv[]){
int num,binary,decimal=0,rem,base=1;
num=atoi(argv[1]);
binary=num;
while(num>0){
rem=num%2;
decimal+=rem*base;
num=num/10;
base=base*2;
}
printf("%d",decimal);
return 0;
}
