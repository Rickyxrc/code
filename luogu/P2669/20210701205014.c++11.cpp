#include<stdio.h>
#include<cstdlib>
int n,days,cnt,ccnt=1;
int main(){
    scanf("%d",&days);
    for(int i=1;;i++){
    	for(int j=1;j<=ccnt;j++){
            cnt++;
            n+=i;
            if(cnt==days)
                goto flg;
        }
        ccnt++;
	}
    flg: 
    printf("%d",n);
    return 0;
}