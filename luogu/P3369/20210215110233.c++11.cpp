#include<bits/stdc++.h>
using namespace std;
namespace stdd{
	#define ThisNum__ 100001
	class tree{
		private:
			int root;
			int total;
			int fa[ThisNum__];
			int child[ThisNum__][2];
			int val[ThisNum__];
			int count[ThisNum__];
			int sz[ThisNum__];
			void rotate(int x){
				int y=fa[x],z=fa[y],chk=get(x);
				child[y][chk]=child[x][chk^1];
				if (child[x][chk^1])
					fa[child[x][chk^1]]=y;
				child[x][chk^1]=y;
				fa[y]=x;
				fa[x]=z;
				if(z)
					child[z][bool(y==child[z][1])]=x;
				mfunc(x);
				mfunc(y);
				return;
			}
			void splay(int x){
				for(int f=fa[x];f=fa[x],f;rotate(x))
				    if(fa[f])
						rotate(get(x)==get(f)?f:x);
			    root=x;
			    return;
			}
			inline void mfunc(int x){
				sz[x]=sz[child[x][0]]+sz[child[x][1]]+count[x];
				return;
			} 
			inline bool get(int x){
				return bool(x==child[fa[x]][1]);
			}
			inline void clear(int x){
				child[x][0]=0;
				child[x][1]=0;
				fa[x]=0;
				val[x]=0;
				sz[x]=0;
				count[x]=0;
			}
			inline int func(bool mode){
				int cur=child[root][mode];
			    while(child[cur][!mode])
					cur=child[cur][!mode];
			    splay(cur);
			    return cur;
		    }
		    //0前驱,1后继
		public:
			tree(){root=0;}
			inline void ins(int k){
			    if (!root){
				    val[++total]=k;
				    count[total]++;
				    root=total;
				    mfunc(root); 
				    return;
			    }
			    int cur=root,f=0;
			    while(1){
				    if(val[cur]==k){
					    count[cur]++;
					    mfunc(cur);
					    mfunc(f);
					    splay(cur);
					    break;
				    }
				    f=cur;
				    cur=child[cur][val[cur]<k];
				    if(!cur){
					    val[++total]=k;
					    count[total]++;
					    fa[total]=f;
					    child[f][val[f]<k]=total;
					    mfunc(total);
					    mfunc(f);
					    splay(total);
					    break;
				    }
			    }
			}
			inline int rk(int k){
			    int res=0,cur=root;
			    while (1){
				    if (k<val[cur])
				    	cur=child[cur][0];
				    else{
					    res+=sz[child[cur][0]];
					    if(k==val[cur]){
						    splay(cur);
						    return res+1;
					    }
					    res+=count[cur];
					    cur=child[cur][1];
				    }
			    }
		    }
			inline int kth(int k) {
			    int cur=root;
			    while(1){
				 	if (child[cur][0]&&k<=sz[child[cur][0]])
				    	cur=child[cur][0];
				    else{
					    k-=count[cur]+sz[child[cur][0]];
					    if(k<=0){
					    splay(cur);
					    return val[cur];
					    }
					    cur=child[cur][1];
				    }
			    }
		    }
			inline void del(int k){
			    rk(k);
			    if(count[root]>1){
			    	count[root]--;
			    	mfunc(root);
			    	return;
			    }
			    if(!child[root][0]&&!child[root][1]){
			    	clear(root);
			    	root=0;
			    	return;
			    }
			    if (!child[root][0]){
			    	int cur=root;
			    	root=child[root][1];
			    	fa[root]=0;
			    	clear(cur);
			    	return;
			    }
			    if (!child[root][1]){
			    	int cur=root;
			    	root=child[root][0];
			    	fa[root]=0;
			    	clear(cur);
			    	return;
			    }
			    int cur=root;
			    int x=func(0);
			    fa[child[cur][1]]=x;
			    child[x][1]=child[cur][1];
			    clear(cur);
			    mfunc(root);
		  	}
		  	inline int fun(int x,bool mode){
		  		int tp;
				ins(x);
		  		tp=func(mode);
		  		del(x);
		  		return val[tp];
			}
	};
}
int main(){
	stdd::tree t;
	int n,tp,tp_;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>tp>>tp_;
		switch(tp){
			case 1:{
				t.ins(tp_);
				break;
			}
			case 2:{
				t.del(tp_);
				break;
			}
			case 3:{
				cout<<t.rk(tp_)<<endl;
				break;
			}
			case 4:{
				cout<<t.kth(tp_)<<endl;
				break;
			}
			case 5:{
				cout<<t.fun(tp_,0)<<endl;
				break;
			} 
			case 6:{
				cout<<t.fun(tp_,1)<<endl;
				break;
			} 
		}
	}
	return 0;
}