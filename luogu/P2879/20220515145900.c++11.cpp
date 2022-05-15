#include<stdio.h>
#include<map>
#define maxn 10007
int n,r,i,h,diff[maxn],t1,t2,t3,tn;
std::map<std::pair<int,int>,int>mp;
int main(){
	scanf("%d%d%d%d",&n,&i,&h,&r);
	for(int i=1;i<=r;i++){
		scanf("%d%d",&t1,&t2);
		if(t1>t2){
			t3=t1;
			t1=t2;
			t2=t3;
		}
		//printf("- %d %d\n",t1,t2);
		if(mp.find({t1,t2}) == mp.end()){
			mp[{t1,t2}] = 1;
			diff[t1+1]--;
			diff[t2]++;
		}
	}
	tn = h;
	for(int i=1;i<=n;i++){
		tn+=diff[i];
		printf("%d\n",tn);
	}
	return 0;
}