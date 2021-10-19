#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Int{
	private:
		int s[10000],len=0;
		void fix(){
			for(int i=0;i<=len-2;i++){
				s[i+1] += (s[i]/10);
				s[i]%=10;
				if(s[i]<0)
					s[i]+=10,s[i+1]--;
			}
			while(s[len-1]>=10){
				s[len-1]-=10;
				s[len++]++;
			}
			return;
		}
	public:
		Int(){
			memset(s,0,sizeof(s));
			len = 0;
		}
		Int(const string& st){
			memset(s,0,sizeof(s));
			len = st.length();
			for(int i=len-1;i>=0;i--){
				s[i] = st[len-i-1]-'0';
			}
		}
		friend ostream& operator<<(ostream& os,const Int& ii);
		Int operator+(const Int& oth)const{
			Int rslt;
			rslt.len=(len > oth.len)?len:oth.len;
			for(int i=rslt.len-1;i>=0;i--){
				rslt.s[i] = s[i] + oth.s[i];
			}
			rslt.fix();
			return rslt;
		}
};
istream& operator>>(istream& is,Int& i){
	string str;
	is>>str;
	i = Int(str);
	return is;
}
ostream& operator<<(ostream& os,const Int& ii){
	for(int i=ii.len-1;i>=0;i--){
		os<<char(ii.s[i]+'0');
	}
	return os;
}
int main(){
	Int a,b;
	cin>>a>>b;
//	cout<<a<<"|"<<endl;
//	cout<<b<<"|"<<endl;
	cout<<a+b<<endl;
	return 0;
}