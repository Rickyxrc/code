#include<stdio.h>
#include<map>
std::map<std::pair<int,int>,int> m;
int i,j,n,q,tp,k;
int main(){
	scanf("%d%d",&q,&q);
	for(int ii=1;ii<=q;ii++){
		scanf("%d",&tp);
		if(tp==1)
			scanf("%d%d%d",&i,&j,&k),
			m[{i,j}] = k;
		else
			scanf("%d%d",&i,&j),
			printf("%d\n",m[{i,j}]);
	}
	return 0;
}