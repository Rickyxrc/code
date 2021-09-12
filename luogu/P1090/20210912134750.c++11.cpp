#include<stdio.h>
struct TreeNode{                       
	long long leav;          
	long long data;
	long long fath;
	long long lson;
	long long rson;
};
#define maxn 100000
TreeNode treePool[maxn];

long long table[maxn],poolcnt=0,tablecnt=0,n,Tp,ans;
long long min1,min1ind,min2,min2ind;

long long newTreeNode(long long lsonn,long long rsonn,long long fathh,long long dataa,long long leavv){
	treePool[poolcnt].lson=lsonn;
	treePool[poolcnt].rson=rsonn;
	treePool[poolcnt].fath=fathh;
	treePool[poolcnt].data=dataa;
	treePool[poolcnt].leav=leavv;
	table[tablecnt]=poolcnt++;
	return tablecnt++;
}

void find2min(){
	min1 = 2147483647 ;
	min1ind = -1 ;
	min2 = 2147483647 ;
	for(long long i=0;i<tablecnt;i++){
		if(min1 > treePool[table[i]].data )
			min1 = treePool[table[i]].data,
			min1ind = i; 
	}
	for(long long i=0;i<tablecnt;i++){
		if(i == min1ind)
			continue;
		if(min2 > treePool[table[i]].data )
			min2 = treePool[table[i]].data,
			min2ind = i;
	}
}

void merge(long long indi,long long indj){
	
//	printf("merge %d,%d -> %d\n",indi,indj,treePool[indi].data + treePool[indj].data);
	long long Tp1,Tp2,news;
	ans+=treePool[indi].data + treePool[indj].data;
	news = newTreeNode(indi,indj,-1,
		treePool[indi].data + treePool[indj].data
			,-1);
//	
//	treePool[table[i]].fath=poolcnt;
//	treePool[table[j]].fath=poolcnt;
//	
//	table[tablecnt++] = poolcnt++;
	return;
}

void del(long long deln){
	for(long long i = deln ; i< tablecnt-1 ; i++)
		table[i] = table[i+1] ;

	table[tablecnt--] = 0;
	return;
}

int main(){
	
//	freopen("F:/洛谷数据点收集/P1090_2.in","r",stdin);
	
	scanf("%d",&n);
	for(long long i=1;i<=n;i++){
		scanf("%d",&Tp);
		newTreeNode(-1,-1,-1,Tp,1);
	}
	
//	for(long long i=0;i<tablecnt;i++)
//		printf("%d ",treePool[table[i]].data);
//	printf("\n");
	
	while(tablecnt>1){
		find2min();
//		printf("%d\n",tablecnt);
//		printf("min1 is %d , at %d.\n",min1,min1ind);
//		printf("min2 is %d , at %d.\n",min2,min2ind);
		
//		printf("treePool index = %d , %d .\n",table[min1ind],table[min2ind]);
		merge(table[min1ind],table[min2ind]);
		
		del(min1ind);
		if(min1ind<min2ind)
			min2ind--;
		del(min2ind);
		
//		for(long long i=0;i<tablecnt;i++)
//			printf("%d ",treePool[table[i]].data);
//		printf("\n");
		
//		printf("merge two subtree (%d,%d).\n",min1,min2);
		
//		break;
	}
	printf("%d",ans);
	return 0;
}