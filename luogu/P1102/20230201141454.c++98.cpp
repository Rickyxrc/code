#include<stdio.h>
#include<string.h>

#define maxn 200007

struct Node{
	Node* nxt[10];
	int cnt;
	Node(){
		for(int i=0;i<10;i++)
			nxt[i] = NULL;
		cnt=0;
	}
};
Node* root;

void ins(long long s){
	Node* t = root;
	while(s){
		if(t->nxt[s%10] == NULL)
			t -> nxt[s%10] = new Node;
		t = t->nxt[s%10];
		s/=10;
	}
	t->cnt++;
}

int query(long long s){
	Node* t = root;
	while(s){
		if(t->nxt[s%10] == NULL)
			return 0;
		t = t->nxt[s%10];
		s/=10;
	}
	return t->cnt;
}

int n,c;
long long k[maxn],res;

int main(){
	root = new Node();
	scanf("%d%d",&n,&c);
	
	for(int i=1;i<=n;i++)
		scanf("%lld",k+i),
		ins(k[i]);
	
	for(int i=1;i<=n;i++)
		res += query(c+k[i]);
	
	printf("%lld",res);
	return 0;
}