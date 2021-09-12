#include<stdio.h>

//-Heap---------------

//-Heap---------------

//-Huffman-tree-------
struct TreeNode{                       
	unsigned int leav;          
	unsigned int data;
	unsigned int fath;
	unsigned int lson;
	unsigned int rson;
};
#define maxn 100000
TreeNode treePool[maxn];

unsigned int table[maxn],poolcnt=0,tablecnt=0,n,Tp,ans;
unsigned int min1,min1ind,min2,min2ind;

unsigned int newTreeNode(unsigned int lsonn,unsigned int rsonn,unsigned int fathh,unsigned int dataa,unsigned int leavv){
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
	for(unsigned int i=0;i<tablecnt;i++){
		if(min1 > treePool[table[i]].data )
			min1 = treePool[table[i]].data,
			min1ind = i; 
	}
	for(unsigned int i=0;i<tablecnt;i++){
		if(i == min1ind)
			continue;
		if(min2 > treePool[table[i]].data )
			min2 = treePool[table[i]].data,
			min2ind = i;
	}
}

void merge(unsigned int indi,unsigned int indj){
	unsigned int Tp1,Tp2,news;
	ans+=treePool[indi].data + treePool[indj].data;
	news = newTreeNode(indi,indj,-1,
		treePool[indi].data + treePool[indj].data
			,-1);
	return;
}

void del(unsigned int deln){
	for(unsigned int i = deln ; i< tablecnt-1 ; i++)
		table[i] = table[i+1] ;

	table[tablecnt--] = 0;
	return;
}
//--------------------


int main(){
	scanf("%d",&n);
	for(unsigned int i=1;i<=n;i++){
		scanf("%d",&Tp);
		newTreeNode(-1,-1,-1,Tp,1);
	}
	while(tablecnt>1){
		find2min();
		merge(table[min1ind],table[min2ind]);
		del(min1ind);
		if(min1ind<min2ind)
			min2ind--;
		del(min2ind);
	}
	printf("%d",ans);
	return 0;
}