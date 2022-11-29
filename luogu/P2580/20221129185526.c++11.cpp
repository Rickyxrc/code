#include<stdio.h>
#include<vector>
#include<memory.h>
#include<string.h>

#define maxn 1000007
#define maxnum 1000007

int li[maxn][55],vals[maxnum],cnt,wordcnt;

char s[maxn];

inline int mapping(char c){
	return c-'a';
}

void add(char* s){
	int index = 1;
	for(int i=0;i<strlen(s);i++){
		if(!li[index][mapping(s[i])]){
//			printf("add node %d [%c] %d %d\n",index,s[i],mapping(s[i]),cnt+1);
			li[index][mapping(s[i])] = ++cnt;
		}
		index = li[index][mapping(s[i])];
	}
	vals[index] = 1919810;
}

int query(char* s){
	int index = 1,rv=0;
	for(int i=0;i<strlen(s);i++){
		if(!li[index][mapping(s[i])])
			return 0;
		index = li[index][mapping(s[i])];
	}
	rv = vals[index];
	if(vals[index] == 1919810)
		vals[index] = 114514;
	return rv;
}

int T,n,m;

int main(){
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		add(s);
	}
	
	scanf("%d",&m);
	
	for(int i=1;i<=m;i++){
		scanf("%s",s);
		int t = query(s);
		if(t == 1919810)
			puts("OK");
		else if(t == 114514)
			puts("REPEAT");
		else
			puts("WRONG");
	}
}
/*

3
he
him
her

2
ababab
abababc

*/
/*
10
wuzuofan
luozhezheng
wangleping
chengjunyang
xudemin
liuyunzhe
wuyaoxuan
gaoqiuyang
huangyeqi
dinghaipeng
10
wangleping
wangleping
wuyaoxuan
chenyande
wuyaoxuan
gaoqiuyang
huangyeqi
dinghaipeng
wuyaoxuan
chengjunyang

*/