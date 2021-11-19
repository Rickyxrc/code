#include<stdio.h>
#include<cstring>
#define maxn 1000001
char str[maxn],finds[maxn];
int lenstr,lenfinds,IndEx,i,j;
int prefix[maxn];
int main(){
	scanf("%s%s",str,finds);
	
	lenstr = strlen(str);
	lenfinds = strlen(finds);
	
	IndEx=0;
	//打出最长公共前后缀
	//自己和自己配对 
	prefix[0]=prefix[1]=0;
	for(int i=1;i<lenfinds;i++){
		while(IndEx!=0&&finds[i]!=finds[IndEx])
			//失配，且不为第一个 
			//直接向后跳
			IndEx=prefix[IndEx];
		if(finds[i]==finds[IndEx])
			prefix[i+1]=++IndEx;
		else
			prefix[i+1]=0;
	}	

//	for(int i=lenfinds+1;i>=1;i--)
//		prefix[i]=prefix[i-1];
	prefix[0]=-1;
	//从0开始配对
	//prefix看作 [0,len-1) 的数组 
//	for(int i=0;i<lenfinds;i++)
//		printf("%d ",prefix[i]);
//	printf("\n");
	
	
	//和模式串配对 
//	IndEx = 0;
//	for(int i=0;i<lenstr;i++){
//		printf("IndEx = %d i = %d pos = %d\n",IndEx,i,i-lenfinds+2);
//		while(IndEx!=0&&finds[i]!=str[IndEx])
//			//失配，且不为第一个
//			//直接向后跳 
//			IndEx=prefix[IndEx];
//			if(str[i]==finds[IndEx])
//				//匹配,继续找 
//				IndEx++;
//			if(IndEx==lenfinds)
//				//找到了 
//				printf("%d\n",i-lenfinds+2);
//	}
	
	//模式串和字符串匹配 
	i=0;j=0;
	//i    :主串中的指针 
	//j    :模式串中的指针 
	while(i<lenstr){
//		printf("loop i=%d j=%d 1=[%c] 2=[%c]\n",i,j,str[i],finds[j]);
		if(j==-1||str[i] == finds[j])//匹配,直接向右移动 条件:(不能匹配到最后一个)
		{
			i++,j++;
		}		
				//没有匹配到最后一个 
				//(j-IndEx+1)已匹配串长度 匹配到最后一个,要假装失配,才能继续匹配 			
		else{
//			lost:
			//失配 ，将finds[prefix[j]]与 i对齐 => 移动 j-prefix[j] 位
			// j 位置不变 (相对与IndEx向左 j-prefix[j] )
//			printf("lost i=%d j=%d 1=[%c] 2=[%c]\n",i,j,str[i],finds[j]);
			j=prefix[j];

		}
		if(j==lenfinds){
				//匹配 
				//假装失配，才能继续找下去 
				//特判失配打印
//				printf("fake--------------------\n",i,j,str[i],finds[j]);
				printf("%d\n",i-lenfinds+1);
				j=prefix[j];
//				goto lost;
			}
	}

	
//	满足 t 既是 s 的前缀，又是 s 的后缀 (最长公共前后缀)
//	t 就是 prefix[] 全部左移一位
	for(int i=1;i<=lenfinds;i++)
		printf("%d ",prefix[i]);
	return 0;
}
/*
bababababaca
ababaca

*/