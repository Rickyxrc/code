#include<stdio.h>
#include<iostream>
#include<map>
#define maxn 100005
#define len (cr-cl)
#define debug for(int i=1;i<=n;i++)cout<<s[i]<<" ";cout<<endl;for(int i=1;i<=n;i++)cout<<cnt[s[i]]<<" ";cout<<endl
using namespace std;
map<string,int> mp;
string tmp;
int n,s[maxn],cl=1,cr=1;
int mxlen,wd,mxwd;
int cnt[maxn];
void fetchmax(){
	if(wd>mxwd)
		mxwd=wd,mxlen=len;
	else if(wd == mxwd)
		if(mxlen>len)
			mxlen = len;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>tmp;
		mp[tmp]=i;
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>tmp;
		s[i]=mp[tmp];
	}
	cl=cr=1;
	while(cr<=n){
//		debug;
//		cout<<"wd="<<wd<<" len="<<len<<" minlen="<<mxlen<<endl;
		if((s[cr]!=0)&&(cnt[s[cr]]==0)){
//			cout<<"dbg 36:s[cr="<<s[cr]<<" cnt[s[cr="<<cnt[s[cr]]<<endl;
//			cout<<"dbg 37:wd++ cl="<<cl<<" cr="<<cr<<endl;
			wd++;
		}
			
//		cout<<"wd="<<wd<<" len="<<len<<" minlen="<<mxlen<<endl;
		cnt[s[cr]]++;
		cr++;
//		cout<<"cr move to "<<cr<<endl;
		while((cl<cr)&&(cnt[s[cl]]>1||s[cl]==0)){
			cnt[s[cl]]--;
			cl++;
//			cout<<"cl move to "<<cl<<endl;
	
		}
		fetchmax();
	}
	printf("%d\n%d",mxwd,mxlen);
}