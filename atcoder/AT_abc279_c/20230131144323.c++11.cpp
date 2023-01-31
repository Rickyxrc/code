#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
 
#define maxn 400007
std::string s[maxn];
std::string sl[maxn];
 
int lim[maxn];
 
int w,h;
char ch,chh;
 
char gch(){
	while(true){
		ch=getchar();
		if(ch=='#'|| ch=='.')
			return ch;
	}
}
 
int hashh(int xx){
	int res=0;
	for(int y=0;y<=s[xx].size();y++)
		res = (res + 13 + s[xx][y]*s[xx][y])%maxn;
	return res%maxn;
}
 
int main(){
	scanf("%d%d",&h,&w);
	
	for(int x=1;x<=h;x++)
		for(int y=1;y<=w;y++)
			s[y] += gch();
	
	std::sort(s+1,s+w+1);
		
	for(int x=1;x<=h;x++)
		for(int y=1;y<=w;y++)
			sl[y] += gch();
	
	sort(sl+1,sl+w+1);
			
	for(int x=1;x<=w;x++){
		if(s[x] != sl[x])
			return puts("No")&0;
	}
	
	return puts("Yes")&0;
}