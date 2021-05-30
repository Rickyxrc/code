#include<stdio.h>
int main(){
    unsigned long long k;
    scanf("%lld",&k),printf("%lld",(k&0xFFFF0000)>>16|(k&0x0000FFFF)<<16);
    return 0;
}