#include<stdio.h>
//scanf,prinft的头文件 
#include<memory.h>
//memset的头文件 

const int Maxx = 100005; 
int head[Maxx],next[Maxx],to[Maxx],cnt=0;
//邻接表结构 

//插入一条f->t的边(头插法)
void insert(int f,int t){
	
	next[cnt]=head[f];
	//第一步:新建结点，指向表头
	 
	to[cnt]=t;
	//向结点存入信息(要到达的边) 
	
	head[f]=cnt;
	//第二步:头结点指向新结点
	
	cnt++; 
	return;
}

int ans[Maxx]; 
//source表示从哪个点开始搜索
//now表示现在搜索到了那个点 
void dfs(int source,int now){
	if(ans[now])
		return;
	//搜索过就返回
	
	ans[now]=source;
	
	//遍历 now 的所有边 
	int indt=head[now];
	while(indt!=-1){
		dfs(source,to[indt]);
		
		indt=next[indt];
		//下一条边 
	}
	return;
}

int n,m,from,tto;
int main(){
	memset(head,-1,sizeof(head));
	//初始化head数组,这一步非常重要 
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&from,&tto);
		
		if(from == tto)
			continue;
		//自环就跳过 
		
		insert(tto,from);
	}

	//从n到1深搜
	//为什么?题目要求最大的点，所以最大点优先 
	for(int i=n;i;i--)
		dfs(i,i);
		
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}