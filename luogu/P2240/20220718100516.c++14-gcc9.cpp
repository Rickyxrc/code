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
}class Item{
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
		bool operator<(const Item o){
			return this->advValue > o.advValue;
		}
}list[maxn];
int n,m,tw,tv;
double val;
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++)
		list[i] = Item(read(),read());
	std::sort(list+1,list+n+1);
//	for(int i=1;i<=n;i++){
//		printf("%d %d %lf\n",list[i].weight,list[i].value,list[i].advValue);
//	}
	for(int i=1;i<=n;i++){
		if(m<=0)break;
		if(m > list[i].weight)
			m-=list[i].weight,
			val+=list[i].value;
		else
			val+=m*list[i].advValue,
			m=0;
	}
	printf("%.2f",val);
	return 0;
}
