#include<bits/stdc++.h>
using namespace std;
char s[15][100001];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>s[i][j];
	for(int j=0;j<m;j++){
		for(int i=0;i<n;i++){
                if(s[i][j]=='#')//it is a num
				    if(s[i][j+1]!='#'&&s[i][j-1]!='#'&&s[i+2][j-1]!='#'&&s[i][j]=='#'&&s[i+1][j]=='#'&&s[i+2][j]=='#'&&s[i+3][j]=='#'&&s[i+4][j]=='#'){
						j++;
						cout<<"1";
					}   
                    else{//it is not 1
                        if(s[i][j+1]=='#'&&s[i][j+2]=='#')//it is 02356789
                            if(s[i+1][j]=='#'&&s[i+2][j]=='#'&&s[i+3][j]=='#'&&s[i+4][j]=='#')//it is 068
                                if(s[i+2][j+1]=='#')//it is 689
                                	if(s[i+1][j+2]!='#')//it is 8
                                    	cout<<"6";
                                    else//it is 8
                                    	cout<<"8";
                                else
                                    cout<<"0";
                            else//it is 23579
                            	if(s[i][j+2]=='#'&&s[i+1][j+2]=='#'&&s[i+2][j+2]=='#'&&s[i+3][j+2]=='#'&&s[i+4][j+2]=='#')//it is 379
                            		if(s[i+2][j]=='#')//is 39
                            			if(s[i+1][j]=='#')//it is 9
											cout<<"9";
										else
											cout<<"3";
									else
										cout<<"7";
                                else//it is 25
                                	if(s[i+1][j]=='#')
                                		cout<<"5";
                                	else
                                		cout<<"2";
                        else//it is 4
                            cout<<"4";
                        j+=3;
                    }
		}
	}	
	return 0;
} 