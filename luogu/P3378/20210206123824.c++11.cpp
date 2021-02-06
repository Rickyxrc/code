#include<bits/stdc++.h>
using namespace std;
unsigned int heap[1000006];
int n=0;
inline void siftup(int k);
inline void siftdown(int k){
	if(k>(n/2)||k==0)
		return;
	int minn=heap[k],minn_index=k;
	if(minn>heap[2*k])
		minn=heap[2*k],
		minn_index=2*k;
	if(2*k+1<=n)
		if(minn>heap[2*k+1])
			minn=heap[2*k+1],
			minn_index=2*k+1;
	if(minn_index!=k)
		swap(heap[k],heap[minn_index]),
		siftdown(minn_index);
	siftup(minn_index);
	return;
}
inline void siftup(int k){
	if(k==0)
		return;
	siftdown(k>>1);
	return;
}
inline void init(int n){
	for(int i=1;i<=n;i++){
		heap[i]=2147483648;
	}
	return;
}
//inline void oput(){
//	if(n)
//		for(int i=1;i<=n;i++){
//			cout<<heap[i]<<" ";
//		}
//	cout<<endl;
//}
int main(){
	int tp,type,num;
	cin>>num;
	init(num);
	for(int i=1;i<=num&&cin>>type;i++)
		if(type==1)
			cin>>tp,
			heap[++n]=tp,
			siftup(n);
		else if(type==2)
//			oput(),
			cout<<heap[1]<<endl;
		else if(type==3)
			n--,
			swap(heap[1],heap[n+1]),
			heap[n+1]=2147483648,
			siftdown(1);
	return 0;
}