#include<stdio.h>
#include<vector>
#include<memory.h>
#include<string.h>

#define maxn 3000010
#define maxnum 3000010

int li[maxn][65],vals[maxnum],cnt;

char s[maxn];

inline int mapping(char c){
	if(c>='a' && c<='z')
		return c-'a';
	if(c>='A' && c<='Z')
		return c-'A'+26;
	if(c>='0' && c<='9')
		return c-'0'+52;
}

void add(char* s){
	int index = 0;
	for(int i=0;i<strlen(s);i++){
		if(!li[index][mapping(s[i])]){
			li[index][mapping(s[i])] = ++cnt;
		}
		index = li[index][mapping(s[i])];
		vals[index]++;
	}
}

int query(char* s){
	int index = 0;
	for(int i=0;i<strlen(s);i++){
		if(!li[index][mapping(s[i])])
			return 0;
		index = li[index][mapping(s[i])];
	}
	return vals[index];
}

int T,n,m;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%s",s);
			add(s);
		}
		for(int i=1;i<=m;i++){
			scanf("%s",s);
			printf("%d\n",query(s));
		}
		
		for(int i=0;i<=cnt;i++){
			for(int j=0;j<=64;j++)
				li[i][j]=0;
			vals[i]=0;
		}
		cnt=1;
	}
}