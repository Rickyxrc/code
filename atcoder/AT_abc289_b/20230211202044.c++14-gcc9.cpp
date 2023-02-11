#include<stdio.h>
#include<stack>

#define maxn 107

std::stack<int> s;
int arrayy[maxn],n,m,t;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&t),
		arrayy[t]=1;
	
	for(int i=1;i<=n;i++){
		if(arrayy[i])
			s.push(i);
		else{	
			printf("%d ",i);
			while(!s.empty())
				printf("%d ",s.top()),
				s.pop();
		}
	}
	return 0;
} 