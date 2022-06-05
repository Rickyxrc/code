#include<stdio.h>
#include<cctype>
#include<deque>
std::deque<int> q;
int n,dk,m=1;
char ch,ch2;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		ch=' ',ch2=' ';
		while(!isalpha(ch))ch=getchar();
		while(!isalpha(ch2))ch2=getchar();
		dk=-1;
		if(ch=='D')
			scanf("%d",&dk);
		
		if(ch=='A'){
			if(ch2=='L')
//				printf("L in %d \n",m),
				q.push_front(m);
			else if(ch2=='R')
//				printf("R in %d \n",m),
				q.push_back(m);
			m++;
		}
		else if(ch=='D'){
			if(ch2=='L')
				for(int i=1;i<=dk;i++)q.pop_front();
			else if(ch2=='R')
				for(int i=1;i<=dk;i++)q.pop_back();
		}
		
//		for(int i=0;i<q.size();i++){
//			int t = q.front();
//			printf("%d",t);
//			q.pop_front();
//			q.push_back(t);
//		}	
//		printf("\n");
	}
	for(int i=0;i<q.size();i++){
		int t = q.front();
		printf("%d\n",t);
		q.pop_front();
		q.push_back(t);
	}
	return 0;
}