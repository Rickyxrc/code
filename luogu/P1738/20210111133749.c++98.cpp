#include<bits/stdc++.h>
using namespace std;
map<string,bool>flg=map<string,bool>();
map<string,bool>::iterator it;
int main(){
	ios::sync_with_stdio(false);
	int n,num=0;
	cin>>n;
	string m,r;
	char c;
	bool f=1;
	for(int i=1;i<=n;i++){
        
		cin>>m;
		c=m[0];
		for(int i=0;i<m.length();i++,c=m[i]){
			r+=c;
			if(i&&c=='/'||i+1==m.length()){
				if(r[r.length()-1]!='/')
                    r=r+'/';
					//r.erase(r.length()-1);
				it=flg.find(r);
				if(it==flg.end()){ 
					num++;
					flg[r]=1;
                    //cout<<r<<endl;
				}
			}
		}
		if(!f)
			cout<<endl;
		f=0;
		cout<<num;
		r=string("");
	}
}