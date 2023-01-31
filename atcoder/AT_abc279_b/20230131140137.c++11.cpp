#include<bits/stdc++.h>
int pfix[1000007],ch,findeddd=0;
std::string strMode,str;
void getpfix(){
	int i=0,j=-1;
	pfix[0]=-1;
	while(i<strMode.length()){
		if(j==-1 || strMode[i] == strMode[j])
			pfix[++i] = ++j;
		else
			j = pfix[j];
	}
}
void kmp(){
	int i=0,j=0;
	while(i<str.length()){
		if((j==-1 || str[i] == strMode[j]))
			i++,j++;
		else
			j = pfix[j];
		if(j==strMode.length()){
			findeddd = 1;
			j = pfix[j];
		}
	}
}
int main(){
	std::cin>>str>>strMode;
//    printf("%s\n%s\n",str.c_str(),strMode.c_str());
	
	getpfix();
	kmp();
		
	if(findeddd)
		printf("Yes");
	else
		printf("No");
}