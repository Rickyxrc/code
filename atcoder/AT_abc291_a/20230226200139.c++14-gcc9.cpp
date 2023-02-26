#include<stdio.h>
char c;
int num=1;
int main(){
  while(true){
    c = getchar();
    if('A' <= c && c <= 'Z')
      return printf("%d",num)&0;
    num++;
  }
}