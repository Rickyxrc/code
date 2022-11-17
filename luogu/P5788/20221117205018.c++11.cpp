#include<stdio.h>
#include<stack>
#define maxn 3000007
std::stack<int> st,id;
int flg[maxn],n,tmp;
int main(){
	scanf("%d",&n);
//	rev = new int[n];
	
	for(int i=1;i<=n;i++){
		scanf("%d",&tmp);
		while(!st.empty() && tmp > st.top()){
			flg[id.top()] = i;
			st.pop();
			id.pop();
		}
		id.push(i);
		st.push(tmp);
	}
	flg[id.top()] = 0;
	
	for(int i=1;i<=n;i++)
		printf("%d ",flg[i]);
	
	return 0;
}