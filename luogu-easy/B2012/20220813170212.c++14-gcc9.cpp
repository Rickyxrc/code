#include<stdio.h>
int main(){
    int a,l;
    scanf("%d%d",&a,&l);
    printf("%.3lf%%",double(l*100.0)/a);
    return 0;
}