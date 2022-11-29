#include<stdio.h>
#define maxn 500007
int data[maxn],n,m,t,mode,x,y;

int lowbit(int x){
	return x&(-x);
}

void add(int index,int val){
	while(index<=n)
		data[index]+=val,
		index+=lowbit(index);
}

int query(int index){
	int ans=0;
	while(index)
		ans+=data[index],
		index-=lowbit(index);
	return ans;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		add(i,t);
	}
	
	for(int i=1;i<=m;i++){
		scanf("%d",&mode);
		if(mode==1){
			scanf("%d%d",&x,&y);
			add(x,y);
		}
		if(mode==2){
			scanf("%d%d",&x,&y);
			printf("%d\n",query(y)-query(x-1));
		}
	}
	
	return 0;
}