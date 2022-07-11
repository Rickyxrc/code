#include<stdio.h>
#include<algorithm>
struct __tmpStruct {
	char s[22];
	int y,m,d,index;
}t[101];
bool cmp(__tmpStruct i,__tmpStruct j){
	if(i.y!=j.y)
		return i.y<j.y;
	else{
		if(i.m!=j.m)return i.m<j.m;
		else if(i.d==j.d&&i.m==j.m)return i.index>j.index;
		else if(i.d!=j.d&&i.m==j.m)return i.d<j.d;
	}
}
int y,m,d,n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		t[i].index = i,
		scanf("%s%d%d%d",t[i].s,&t[i].y,&t[i].m,&t[i].d);
	std::stable_sort(t+1,t+n+1,cmp);
	for(int i=1;i<=n;i++)
		printf("%s\n",t[i].s);
	return 0;
}