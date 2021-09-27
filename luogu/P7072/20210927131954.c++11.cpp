#include<stdio.h>
#include<vector>
#include<algorithm>
int n,Tp,cnt,pct,nowpeo;
std::vector<int> zb(16384);
std::vector<int>::iterator it;
void insert(int x){
	it = zb.begin(); 
	while(it<zb.end()){
		if(x>(*it)){
			zb.insert(it,x);
			return;
		}
		it++;
	}
}
int main(){
	scanf("%d%d",&n,&pct);
	for(int i=1;i<=n;i++){
		scanf("%d",&Tp);
		insert(Tp);
		cnt++;
		nowpeo = cnt * pct / 100 ;
		if(nowpeo == 0)
			nowpeo = 1 ;
		printf("%d ",zb[nowpeo-1]);
	}
	return 0;
} 