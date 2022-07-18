#include<stdio.h>
#include<algorithm>
#include<cctype>
#define maxn 102 
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
namespace xrc{
	class Item{
	public:
		int weight,value;
		double advValue;
		Item(int tempValue,int tempWeight){
			this->weight = tempWeight;
			this->value  = tempValue;
			this->advValue = (double)tempValue/tempWeight;
		}
		Item(){
		}
		inline bool operator<(const Item o){
			return this->advValue > o.advValue;
		}
	};
	Item list[maxn];
}
int n,m,tw,tv;
double val;
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++)
		xrc::list[i] = xrc::Item(read(),read());
	std::sort(xrc::list+1,xrc::list+n+1);
	for(int i=1;i<=n;i++){
		if(m<=0)break;
		if(m > xrc::list[i].weight)
			m-=xrc::list[i].weight,
			val+=xrc::list[i].value;
		else
			val+=m*xrc::list[i].advValue,
			m=0;
	}
	printf("%.2f",val);
	return 0;
}
