/*
PID:1219
TITLE:八皇后 Checker Challenge - 洛谷
*/
#include<stdio.h>
#include<stdlib.h>
int n,s,num_s,sta[14],lcr[30],rcr[30],st[30],li[30];
inline void print(){
    s++;
    if(s>3)
        return;
    //do something to print
    for(int i=1;i<=n;i++)
        printf("%d ",st[i]);
    printf("\n");
    return;
}
void getsolution(int step=1){
    if(step==n+1){
        print();
        num_s++;
        return;
    }
        for(int j=1;j<=n;j++){
            if(!(lcr[j+n-step]||rcr[j+step-1]||st[step]||li[j])){
                lcr[j+n-step]=1;
                rcr[j+step-1]=1;
                st[step]=j;
                li[j]=1;

                getsolution(step+1);

                lcr[j+n-step]=0;
                rcr[j+step-1]=0;
                st[step]=0;
                li[j]=0;
            }
        }
    return;
}
int main(){
    scanf("%d",&n);
    getsolution();
    printf("%d",num_s);
    return 0;
}
/*
(i,j)
(1,1) (1,2) (1,3) (1,4) (1,5) (1,6)
(2,1) (2,2) (2,3) (2,4) (2,5) (2,6) 
(3,1) (3,2) (3,3) (3,4) (3,5) (3,6)
(4,1) (4,2) (4,3) (4,4) (4,5) (4,6)
(5,1) (5,2) (5,3) (5,4) (5,5) (5,6)
(6,1) (6,2) (6,3) (6,4) (6,5) (6,6) 

j+(n-i) 左斜
j+(i-1) 右斜

i       横线

j       竖线


-*----
---*--
-----*
*-----
----*-
--*---

*/