#include<iostream>
#include<cstring>
using namespace std;
#define maxn 600
int max(int a,int b){
	return a>b?a:b;
}
class Int{
	private:
		int s[maxn],len;
		void fix(){
			for(int i=0;i<len-1;i++){
				s[i+1] += s[i]/10;
				s[i] %= 10;
			}
			while(s[len-1]>=10){
				s[len] += s[len-1]/10;
				s[len-1] %= 10;
				len++;
			}
		}
	public:
		Int(){memset(s,0,sizeof(s));s[0]=0;len=1;}
		Int(const string& st){
			memset(s,0,sizeof(s));
			len=st.length();
			for(int i=st.length()-1;i>=0;i--)
				s[len-i-1] = (st[i]^48);
		}
		friend ostream& operator<<(ostream& os,const Int& it);
		const Int operator+(const Int& obj){
			Int rslt;
			rslt.len=std::max(len,obj.len);
			for(int i=0;i<rslt.len;i++)
				rslt.s[i]=s[i]+obj.s[i];
			rslt.fix();
			return rslt;
		}
		
};
istream& operator>>(istream& is,Int& it){
	string s;
	is>>s;
	it=Int(s);
	return is;
}
ostream& operator<<(ostream& os,const Int& it){
	for(int i=it.len-1;i>=0;i--)
		os.put(it.s[i]+48);
	return os;
}
Int a,b;
int main(){
	cin>>a>>b;
	cout<<a+b;
}