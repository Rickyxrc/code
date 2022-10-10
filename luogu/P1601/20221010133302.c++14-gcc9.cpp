#include<stdio.h>
#include<string>
#include<memory.h>
#define maxn 1007
int cache[maxn],top=0;
class Number{
	private:
		int s[maxn],len=0;
		void fix(){
			for(int i=0;i<this->len;i++)
				if(s[i]>=10)
					this->s[i]-=10,this->s[i+1]++;
			while(this->s[this->len]>0)len++;
		}
	public:
		Number(){
			memset(s,0,sizeof(s));
		}
		void input(){
			len=0;
			char ch;
			ch=getchar();
			while(!isdigit(ch))ch=getchar();
			while(isdigit(ch))cache[top++]=ch^48,ch=getchar();
			while(top)s[len++]=cache[--top];
		}
		void output(){
			for(int i=len-1;i>=0;i--)
				putchar(s[i]+48);
		}
		Number operator+(Number oth){
			Number ans;
			int mx = this->len > oth.len ? this->len : oth.len; 
			for(int i=0;i<=mx;i++)
				ans.s[i] = this->s[i] + oth.s[i];
			ans.len = mx;
			ans.fix();
			return ans;
		}
};
int main(){
	Number a,b;
	a.input();
	b.input();
	(a+b).output();
	return 0;
}