#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char s[1048600],k[10];
int hashs[1007],ans,hashval[28];

int n;

int hash8(char* s){
	int res=0;
	for(int i=0;i<8;i++)
		res += hashval[s[i]-'a'];
	return res;
}

int main(){
	srand(37215892);
	for(int i=1;i<=27;i++)
		hashval[i] = rand()*(rand()%1145)*(rand()%10086);
	
	scanf("%s",s);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%s",k),
		hashs[i]=hash8(k);
	
	int strl = strlen(s);
	for(int i=0;i<strl-7;i++)
		for(int j=0;j<n;j++){
			if(hash8(s+i) == hashs[j])
//				printf("at %d , %d\n",i,j),
				ans++;
		}
	
	printf("%d",ans);
	return 0;
}