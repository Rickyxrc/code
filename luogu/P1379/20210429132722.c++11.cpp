#include<bits/stdc++.h>
#define tardp 46686
#define ft q.front()
#define getdigit() getchar()^48
using namespace std;
int mp[1000000]={0};
int jc[10]={1,1,2,6,24,120,720,5040,40320,362880};
int flag[10];
struct un{int k[10];int ct;};
inline int rk(int k[],int n=9){
	for(int i=1;i<=9;i++)
		flag[i]=0;
	int solution=0,Tp,cnt=0;
	for(int i=1;i<=n;i++){
		Tp=k[i]+1;
		flag[Tp]=1;
		cnt=0;
		for(int i=1;i<Tp;i++)
			cnt+=!flag[i];
		solution+=cnt*jc[n-i];
	}
	return solution+1;
} 
queue<un>q;
inline void pushh(int A,int B){
	un tmp=ft;
	swap(tmp.k[A],tmp.k[B]);/*printf("rk=%d ",rk(ft.k));*/
//	for(int i=1;i<=9;i++)putchar(tmp.k[i]+48);cout<<" "<<tmp.ct<<" "<<rk(tmp.k)<<" "<<mp[rk(tmp.k)];putchar('\n');
	if(mp[rk(tmp.k)]==0){
		mp[rk(tmp.k)]=1;
		q.push(tmp);
//		for(int i=1;i<=9;i++)putchar(ft.k[i]+48);cout<<" "<<ft.ct<<" "<<rk(ft.k)<<"pushed";putchar('\n');
	}
}
int main(){
	un a={{0,getdigit(),getdigit(),getdigit(),getdigit(),getdigit(),getdigit(),getdigit(),getdigit(),getdigit()},0};
	int tp=0;
	q.push(a);
	while(q.size()){
//		for(int i=1;i<=9;i++)putchar(ft.k[i]+48);cout<<" "<<ft.ct<<" "<<rk(ft.k);putchar('\n');
		mp[rk(ft.k)]=1;
		if(rk(ft.k)==tardp){
			break;
		}
		for(int i=1;i<=9;i++)
			if(!ft.k[i]){
				tp=i;
				break;
			}
//		cout<<" tp="<<tp<<endl; 
		ft.ct++;
		if(tp>3)   	{pushh(tp,tp-3);}
//		cout<<"1tp="<<tp<<endl; 
		if(tp<7)    {pushh(tp,tp+3);}
//		cout<<"2tp="<<tp<<endl; 
		if(tp%3)    {pushh(tp,tp+1);}
//		cout<<"3tp="<<tp<<endl;
		if((tp+2)%3){pushh(tp,tp-1);}
//		cout<<"4tp="<<tp<<endl;
		q.pop();
	}
	printf("%d",ft.ct);
	return 0;
}