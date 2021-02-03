#include<bits/stdc++.h>
extern"C"int Seniorious(int x);
extern"C"int Chtholly(int n,int c){
	int l=1,r=n;
	int mid=(l+r)>>1;
	while(1){
		int s=Seniorious(mid);
		if(s==0)
			return mid;
		else if(s==1)
			r=mid-1;
		else if(s==-1)
			l=mid+1;
		mid=(l+r)>>1;
	}
}