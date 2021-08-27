#include<stdio.h>
int cup[1<<9],val[1<<9],n,cnt=1,num;
int main(){
	scanf("%d",&n);
	n=1<<n;
	for(int i=1;i<=n;i++)
		scanf("%d",val+i);
	num=(n<<1)-1;
//	printf(":%d:",num);
	for(int i=(num>>1)+1;i<=num;i++)
//		printf("%d ",cnt),
		cup[i]=cnt++;
	
	for(int i=num>>1;i>=1;i--)
		if(val[cup[i*2]] > val[cup[i*2+1]])
			cup[i]=cup[i*2];
		else
			cup[i]=cup[i*2+1];
	
//	printf("%d",cup[1]);

	if(cup[2] == cup[1])
		printf("%d",cup[3]);
	else
		printf("%d",cup[2]);
	return 0;
}