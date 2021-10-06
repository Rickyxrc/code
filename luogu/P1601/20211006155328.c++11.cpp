#include<stdio.h>
#include<string>
#include<cstring>
#include<iostream>
#include<string.h>
#define N 1000
using namespace std;
class Int{
	int s[N];
	int len;
//	bool positive;
	public:
		Int(int x){
			memset(s,0,sizeof(s));
			char stack[10];
			int top=0,tp;
			while(x){
				stack[top++] = x % 10;
			}
			tp = top;
			while(top){
				s[len++] = stack[--top] ; 
			}
		}
		Int(std::string x){
			memset(s,0,sizeof(s));
			len = x.length();
			for(int i=0;i<len;i++)s[i] = x[len-i-1] - 48 ;
		}
		Int(char* x){
			memset(s,0,sizeof(s));
			len = strlen(x);
			for(int i=0;i<len;i++)s[i] = x[len-i-1] - 48 ;
		}
		Int(){memset(s,0,sizeof(s));len = 1;s[0] = '0';}
		
		Int operator=(Int& oth){
			this->len = oth.len;
			for(int i=this -> len -1 ; i >= 0 ; i --){
				this->s[i]=oth.s[i];
			}
			return *this;
		}	
		
		Int operator+(const Int& oth) const{
			Int rslt;
			int i;
			for(i=0;i<this->len || i<oth.len;i++)
				rslt.s[i] = this->s[i] + oth.s[i];
			rslt.len = i;
			rslt.fix();
			return rslt;
		}
		friend std::ostream& operator<<(std::ostream&,const Int&);
		friend std::istream& operator>>(std::istream&,Int&);
	private:
		void fix(){
			for(int i=0;i<this->len;i++){
				s[i+1] += s[i] / 10 ;
				s[i] %= 10;
			}
			while(s[len-1]>=10){
				s[len] += s[len-1] / 10 ;
				s[len-1] %= 10 ;
				len++;
			}
		}
};
std::ostream& operator<<(std::ostream& os,const Int& intt){
	if(intt.s[intt.len] > 0 &&intt.s[intt.len] < 9)
		os<<char(intt.s[intt.len]+'0');
	for(int i=intt.len-1;i>=0;i--)
		os<<char(intt.s[i]+'0');
	return os;
}
std::istream& operator>>(std::istream& is,Int& intt){
	std::string s;
	is>>s;
	intt =*new Int(s);
	return is;
}
int main(){
	Int a,b;
	std::cin>>a>>b;
	std::cout<<a+b;
	return 0;
}