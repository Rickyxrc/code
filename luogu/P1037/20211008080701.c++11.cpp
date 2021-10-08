#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
#define N 1000
using namespace std;
class Int{
	int s[N];
	int len=0;
	bool flag=0;
	public:
		Int(int x){
			memset(s,0,sizeof(s));
			while(x){
				s[len++] = x%10;
				x/=10;
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
		Int operator*(const Int& oth) const{
			Int rslt("0");
			rslt.len = this->len * oth.len + 1;
			for(int i=0;i<this->len;i++)
				for(int j=0;j<oth.len;j++){
					rslt.s[i+j] += oth.s[j] * this->s[i] ;
				}
			rslt.fix();
			return rslt;
		}
		friend std::ostream& operator<<(std::ostream&,const Int&);
	private:
		void debug(){
			for(int i=0;i<this->len;i++){
				cout<<s[i]<<"|";
			}
			cout<<endl;
		}
		void fix(){
			for(int i=0;i<len;i++){
				s[i+1] += s[i]/10;
				s[i] %= 10;
				if(s[i]<0)
					s[i]+=10,s[i+1]--;
			}
			while(s[len-1]>=10){
				s[len] += s[len-1] / 10 ;
				s[len-1] %= 10 ;
				len++;
			}
			while(s[len-1]==0&&len>1)len--;
		}
};
std::ostream& operator<<(std::ostream& os,const Int& intt){
	if(intt.flag)
		os.put('-');
	if(intt.s[intt.len] > 0 &&intt.s[intt.len] < 9)
		os.put(char(intt.s[intt.len]+'0'));
	for(int i=intt.len-1;i>=0;i--)
		os.put(char(intt.s[i]+'0'));
	return os;
}
int a[17],b[17],rules,n;
Int ans=1;
char s[31];
int mays[31],book[15];
int dfs(int n){
	book[n] = 1;
	int rt = 1;
	for(int i=1;i<=rules;i++){
		if(a[i] == n && book[b[i]] == 0 )
			book[b[i]] = 1,rt+=dfs(b[i]);
	}
		
	return rt;
}
void getchars(char* s){
	int i=0;char c=getchar();
	while(c>='0' && c<='9') s[i++]=c , c=getchar() ;
}
int main(){
	getchars(s);
	scanf("%d",&rules);
	for(int i=1;i<=rules;i++)
		scanf("%d %d",&a[i],&b[i]);
	for(int i=0;i<=9;i++){
		memset(book,0,sizeof(book));
		mays[i] = dfs(i);
	}
		
	for(int i=0;i<strlen(s);i++){
		ans = ans * mays[(s[i]-'0')] ;
	}
	cout<<ans;
	return 0;
}
/*
12345 4
1 3
2 4
3 5
5 2

120
*/