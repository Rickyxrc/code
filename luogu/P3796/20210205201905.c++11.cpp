#include<bits/stdc++.h>
#define maxn 1000001
using namespace std;
char s[151][maxn],T[maxn];
int n,cnt,vis[maxn],ans;
struct {
	int son[26];int fail;int flag;
	void init(){memset(son,0,sizeof(son));fail=flag=0;}
}trie[maxn];	
queue<int>q;
void init(){
	for(int i=0;i<=cnt;i++)trie[i].init();
	for(int i=1;i<=n;i++)vis[i]=0;
	cnt=1;ans=0;
}
void insert(char* s,int num){
	int u=1,len=strlen(s);
	for(int i=0;i<len;i++){
		int v=s[i]-'a';
		if(!trie[u].son[v])trie[u].son[v]=++cnt;
		u=trie[u].son[v];
	}
	trie[u].flag=num;
	return;
}
void getfail(void){	
	for(int i=0;i<26;i++)
		trie[0].son[i]=1;
	q.push(1);
	trie[1].fail=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
        int Fail=trie[u].fail;
		for(int i=0;i<26;i++){
			int v=trie[u].son[i];
			if(!v){
				trie[u].son[i]=trie[Fail].son[i];
				continue;
			}
			trie[v].fail=trie[Fail].son[i];
			q.push(v);
		}
	}
}
int query(char* s){
	int u=1,len=strlen(s);
	for(int i=0;i<len;i++){
		int v=s[i]-'a';
		int k=trie[u].son[v];
		while(k>1){
            if(trie[k].flag)
                vis[trie[k].flag]++;
            k=trie[k].fail;
        }
		u=trie[u].son[v];
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	while(1){
		cin>>n;
		if(n==0)
			return 0;
		init();
		for(int i=1;i<=n;i++){
			cin>>s[i];
			insert(s[i],i);
		}
		cin>>T;
		getfail();
		query(T);
		for(int i=1;i<=n;i++)
			ans=max(vis[i],ans);
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)
			if(vis[i]==ans)
				cout<<s[i]<<endl;
	}
} 