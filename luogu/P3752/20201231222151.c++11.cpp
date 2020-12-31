#include<bits/stdc++.h>
using namespace std;
map<string,int>v;
map<string,int>::iterator iter;  
string l[101];
int main(){
//	freopen("P3752_1.in","r",stdin);
//	freopen("P3752_1_.out","w",stdout);
	ios::sync_with_stdio(false);
	int n;
	char c;
	string m;
	cin>>n;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>l[i];
		m="";
		flag=1;
		cin.get(c);
		do{
			cin.get(c);
			if(c==' '){
				if(m=="")
					continue;	
				v[m]=i;
                //cout<<"["<<m<<"]="<<i<<endl;
				m="";
				continue;
			}
			else if(c=='\n'||c=='\r'){
				v[m]=i;
                //cout<<"["<<m<<"]="<<i<<endl;
				m="";
				break;
			}
			else if(c>='a'&&c<='z')
				m+=c;
			else if(c>='A'&&c<='Z')
				m+=(c-'A'+'a');
            else m+=c;
		}while(1);
	}
	string k="",r="";
	bool fst=1;
    while(getline(cin,k)){
        if(k=="")
            continue;
        if(k[k.length()-1]=='\r')    
            k.erase(k.length()-1);
        //cout<<k<<endl;
        //cout<<"T"<<endl;
		for(int i=0;i<k.length()&&k.length();i++){
			r="";
			while(k[i]!='!'&&k[i]!=' '&&k[i]!=','&&k[i]!='.'&&k[i]!='('&&k[i]!=')'&&k[i]!=';'&&i<k.length()){
				if(k[i]>='A'&&k[i]<='Z')
					r+=(k[i]-'A'+'a');
				else if(k[i]>='a'&&k[i]<='z')
					r+=(k[i]);
                else r+=k[i];
				i++;
			}
            if(r=="")
                continue;
            //cout<<"["<<r<<"]"<<endl;
			iter=v.find(r);
			if(iter!=v.end()){
                //cout<<"fnd-"<<r<<endl<<"-----";
				cout<<l[iter->second]<<endl;
				break;
			}
            else;
                //cout<<"nfnd-"<<r<<endl;
		}
	}
    //cout<<"return"<<endl;
	return 0;
}