#include<stdio.h>
#include<algorithm>
#define maxn 102 
class Item{
	public:
		int weight,value;
		double advValue;
		Item(int tempWeight,int tempValue){
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
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&tw,&tv);
		list[i] = Item(tw,tv);
	}
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
