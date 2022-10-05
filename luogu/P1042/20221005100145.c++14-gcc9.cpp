#include<stdio.h>
#include<string>
int a,b,A,B,t,ed;
std::string s;
int gameend(int a,int b,int n){
	if(std::max(a,b)>=n&(std::max(a,b)-std::min(a,b))>=2)
		return true;
	return false;
}
int main(){
	while(true){
		t = ' ';
		while(t!='W'&&t!='L'&&t!='E')
			t=getchar();
		if(t=='E')
			break;
		s+=t;
	}
	a=b=0;
	for(auto t : s){
		if(t=='W')
			a++;
		if(t=='L')
			b++;
		if(ed=gameend(a,b,11)){
			printf("%d:%d\n",a,b);
			a=b=0;
		}
	}
//	if(a!=0 && b!=0)
		printf("%d:%d\n\n",a,b);
	
	a=b=0;
	for(auto t : s){
		if(t=='W')
			a++;
		if(t=='L')
			b++;
		if(ed=gameend(a,b,21)){
			printf("%d:%d\n",a,b);
			a=b=0;
		}
	}
//	if(a!=0 && b!=0)
		printf("%d:%d",a,b);
	return 0;
}