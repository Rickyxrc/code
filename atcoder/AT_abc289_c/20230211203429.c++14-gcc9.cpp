#include<stdio.h>

#define maxn 17
int qus[maxn],book[maxn],target;

int n,m,lenn,tm,ans;

bool valid(){
	int res=0;
	for(int i=1;i<=m;i++)
		res |= book[i] * qus[i];
	return res==target;
}

void dfs(int step){
	if(step==m+1){
//		for(int i=1;i<step;i++)
//			printf("%d ",book[i]);
//		if(valid())
//			printf("OK!");
//		puts("");
		ans+=valid();
		return;
	}
	
	for(int i=0;i<=1;i++){
		book[step] = i;
		dfs(step+1);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&lenn);
		for(int j=1;j<=lenn;j++)
			scanf("%d",&tm),
			qus[i] |= (1<<tm);
	}
	
	for(int i=1;i<=n;i++)
		target |= (1<<i);
		
//	for(int i=1;i<=m;i++)
//		printf("<%d>\n",qus[i]);
	
	dfs(1);
	printf("%d",ans);
	return 0;
}