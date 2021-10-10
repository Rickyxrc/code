#include<iostream>
class Int{
	private:
		int s[10000],flag,len;
		void fix(){
			for(int i=0;i<len-1;i++){
				s[i+1] += s[i]/10;
				s[i] %= 10;
				if(s[i]<0)
					s[i+1]--,s[i]+=10;
			}
			while(s[len-1] >= 10){
				s[len] += s[len-1]/10;
				s[len-1]%=10;
				len++; 
			}
		}
	public:
		Int(){len=1;s[0]=0;flag=0;}
		Int(std::string st){
			if(st[0] == '-')
				st.erase(0,1),flag=1;
			else
				flag=0;
			len = st.length();
			for(int i=len-1;i>=0;i--)
				s[i] = st[len-i-1]-'0';
		}
		Int operator+(const Int& it){
			int lens = std::max(this->len,it.len);
			Int rslt;
			rslt.len = lens;
			for(int i=0;i<lens;i++)
				rslt.s[i] = this->s[i] + it.s[i];
			rslt.fix();
			return rslt;
		}
		friend std::ostream& operator<<(std::ostream& os,const Int& it);
		friend std::istream& operator>>(std::istream& os,const Int& it);
};
std::ostream& operator<<(std::ostream& os,const Int& it){
	if(it.flag)
		os.put('-');
	for(int i=it.len-1;i>=0;i--)
		os.put(it.s[i]+'0');
	return os;
}
std::istream& operator>>(std::istream& is,Int& it){
	std::string s;
	is>>s;
	Int rslt(s);
	it = rslt;
	return is;
}
int main(){
	Int x,y;
	std::cin>>x>>y;
	std::cout<<x+y;
	return 0;
}