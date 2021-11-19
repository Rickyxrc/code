#include<stdio.h>
#include<cstring>
#define maxn 1000001
char str[maxn],finds[maxn];
int lenstr,lenfinds,IndEx,i,j;
int prefix[maxn];
int main(){
	scanf("%s%s",str,finds);
	lenstr = strlen(str);
	lenfinds = strlen(finds);
	IndEx=0;
	prefix[0]=prefix[1]=0;
	for(int i=1;i<lenfinds;i++){
		while(IndEx!=0&&finds[i]!=finds[IndEx])
			IndEx=prefix[IndEx];
		if(finds[i]==finds[IndEx])
			prefix[i+1]=++IndEx;
		else
			prefix[i+1]=0;
	}	
	prefix[0]=-1;
	i=0;j=0;
	while(i<lenstr){
		if(j==-1||str[i] == finds[j])
			i++,j++;
		else
			j=prefix[j];
		if(j==lenfinds)
				printf("%d\n",i-lenfinds+1),
				j=prefix[j];
	}
	for(int i=1;i<=lenfinds;i++)
		printf("%d ",prefix[i]);
	return 0;
}