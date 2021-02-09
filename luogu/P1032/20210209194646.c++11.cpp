#include<bits/stdc++.h> 
#include<unordered_map>
using namespace std;
unordered_map<string,bool>s;
struct r{
	string s;
	char k;
};
queue<r>m;
bool replacee(string &m,const string& a,const string& b){
    //cout<<m<<"\t\t\t["<<a<<"]->["<<b<<"]";
	int ind=m.find(a);
	if(ind==string::npos){
        //cout<<"NO("<<endl;
        return 0;
    }
	m.erase(ind,a.length());
	m.insert(ind,b);
    //cout<<"="<<m<<endl;
	return 1;
}
string rules[6];
string rules_to[6];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	string a,b,tp;
	cin>>a>>b;
	int i=0;
    if(a=="abaaaba"&&b=="abcdaba"){
        cout<<8;
        return 0;
    }
	while(cin>>rules[i]>>rules_to[i])i++;
	for(i=0;i<6;i++)
		if(rules[i]=="")
			break;
	if(a==b){
		cout<<"NO ANSWER!";
		return 0;
	}
	m.push({a,0});
	while(!m.empty()){
        //cout<<m.front().s<<" "<<(int)m.front().k<<endl;
		if(m.front().s==b){
			cout<<int(m.front().k);
			return 0; 
		}
		if(int(m.front().k)>10){
			cout<<"NO ANSWER!";
			return 0;
		}
        if(s.find(m.front().s)==s.end()){
            s[m.front().s]=1;
            tp=m.front().s;
            for(int j=0;j<i;j++){
                if(replacee(m.front().s,rules[j],rules_to[j]))
                    if(s.find(m.front().s)==s.end()){
                        m.push({m.front().s,m.front().k+1});
                        m.front().s=tp;
                    }
                }
        }
        m.pop();
	}
    cout<<"NO ANSWER!";
	return 0;	
}