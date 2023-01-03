#include<stdio.h>
#include<ctype.h>

int jz;

void swap(int& a,int& b){
	int t=a;
	a=b;
	b=t;
}

bool digit(char ch){
	if('0'<=ch && ch<='9')
		return true;
	if('A'<=ch && ch<='F')
		return true;
	return false;
}

#define maxl 10000
struct Int{
	int s[maxl],len=0;
	void fix(){
		for(int i=0;i<len-1;i++)
			if(s[i] >= jz)
				s[i]-=jz,s[i+1]++;
		if(s[len-1] >= jz)
			s[len-1]-=jz,s[len]++,len++;
	}
	Int add(){
		Int res;
		for(int i=0;i<len;i++)
			res.s[i] = s[i]+s[len-i-1];
		res.len = len;
		res.fix();
		return res;
	}
	void read(){
		char ch;
		while(!digit(ch))ch=getchar();
		while(digit(ch)){
			if('0'<=ch && ch<='9')
				s[len++]=ch^48;
			else
				s[len++]=(ch-'A')+10;
			ch=getchar();
		}
		for(int i=0;i<(len>>1);i++)
			swap(s[i],s[len-i-1]);
	}
	void print(){
		for(int i=len-1;i>=0;i--)
			if(0<=s[i] && s[i]<=9)
				putchar(s[i]+48);
			else
				putchar(s[i]+64);
	}
	bool hw(){
		for(int i=0;i<len;i++)
			if(s[i] != s[len-i-1])
				return false;
		return true;
	}
};

int main(){
	scanf("%d",&jz);
	int step=0;
	Int s;
	s.read();
	while(step<30){
		s = s.add();
//		s.print();putchar('\n');
		step++;
		if(s.hw())
			return printf("STEP=%d\n",step)&0;
	}
	return printf("Impossible!")&0;
}