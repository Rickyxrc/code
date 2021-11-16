#include<stdio.h>
#include<iostream>
#include<map>
#define maxn 100005
#define len (cr-cl)
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
		if((s[cr]!=0)&&(cnt[s[cr]]==0)){
			wd++;
		}
		cnt[s[cr]]++;
		cr++;
		while((cl<cr)&&(cnt[s[cl]]>1||s[cl]==0)){
			cnt[s[cl]]--;
			cl++;
		}
		fetchmax();
	}
	printf("%d\n%d",mxwd,mxlen);
}