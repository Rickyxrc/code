#include<stdio.h>

int cup[1<<9],val[1<<9],n,cnt=1,num;
int main(){
	scanf("%d",&n);
	n=1<<n;
	for(register int i=1;i<=n;i++)
		scanf("%d",val+i);
	num=(n<<1)-1;
	for(register int i=(num>>1)+1;i<=num;i++)
		cup[i]=cnt++;
	for(register int i=num>>1;i>=1;i--)
		if(val[cup[(i<<1)]] > val[cup[(i<<1)|1]])
			cup[i]=cup[(i<<1)];
		else
			cup[i]=cup[(i<<1)|1];
	if(cup[2] == cup[1])
		printf("%d",cup[3]);
	else
		printf("%d",cup[2]);
	return 0;
}